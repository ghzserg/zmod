"""Prepare MkDocs docs from wiki sources.

Steps:
1. Copy top-level files from wiki/ into docs/{ru,en} based on filename suffix.
2. Strip navigation artifacts and normalize markdown for Python-Markdown.
"""

from __future__ import annotations

import argparse
import re
import shutil
from pathlib import Path

# ---------- fenced code block detection ----------
# A real fenced code block delimiter: 3+ backticks (or tildes), possibly preceded
# by indentation, optionally followed by an info string (no more backticks).
# Lines like  ```START_PRINT ... ``` text  are NOT fences — they contain
# a closing run of backticks on the same line, so they are inline code.
_FENCE_RE = re.compile(r'^\s*(`{3,})[^`]*$|^\s*(~{3,})[^~]*$')


def _is_fence_delimiter(stripped: str) -> bool:
    """Return True if *stripped* is a fenced code-block delimiter."""
    return _FENCE_RE.match(stripped) is not None


# ---------- GitHub alerts → MkDocs admonitions ----------
# GitHub: > [!NOTE]  / > [!TIP]  / > [!IMPORTANT]  / > [!WARNING]  / > [!CAUTION]
# MkDocs: !!! note   / !!! tip   / !!! warning      / !!! warning   / !!! danger
_GH_ALERT_TYPE = re.compile(
    r'^(?P<indent>\s*)>\s*\[!(?P<type>[A-Za-z]+)\]\s*$',
)
_GH_ALERT_MAP: dict[str, str] = {
    'NOTE': 'note',
    'TIP': 'tip',
    'IMPORTANT': 'warning',
    'WARNING': 'warning',
    'CAUTION': 'danger',
}

# ---------- list fix ----------
# Python-Markdown requires a blank line before the first list item.
# GitHub Wiki / GFM does not. This regex matches a list-item line.
_LIST_ITEM = re.compile(r'^[ \t]*(?:[-*+]|\d+[.)]) ', re.MULTILINE)
_ORDERED_ITEM = re.compile(r'^[ \t]*\d+[.)] ')
_INDENTED_LIST = re.compile(r'^(?P<indent>[ \t]+)(?:[-*+]|\d+[.)]) ')
_TOP_LEVEL_LIST = re.compile(r'^(?:[-*+]|\d+[.)]) ')


def _indent_width(indent: str) -> int:
    return sum(4 if ch == '\t' else 1 for ch in indent)

# Button names to strip: Top, Back, Forward
_BUTTON_NAMES = r'Top|Back|Forward'

# Language switch links (redundant — MkDocs has a built-in language switcher)
_LANG_SWITCH = re.compile(
    r'\n*\*\[(?:Прочитать на русском языке|Read in English)\]\([^)]*\)\*\n*',
)

# Standalone @zmod_help_bot link lines (redundant — icon is in the site footer).
# Matches lines where the bot link is the entire content (possibly as a list item),
# but NOT when it's part of a sentence (e.g. "Connect to the bot @zmod_help_bot").
_BOT_LINK = re.compile(
    r'^[ \t]*(?:[-*+] )?\[@zmod_help_bot\]\(https?://t\.me/zmod_help_bot\)\s*$',
    re.MULTILINE,
)

# ---------- navigation tables ----------
# HTML tables (all have table-layout:fixed — they are navigation index blocks).
_HTML_TABLE = re.compile(
    r'\n*<table[^>]*>.*?</table>\n*',
    re.DOTALL | re.IGNORECASE,
)

# Markdown pipe-tables whose header row is empty:  | | |\n|---|---|\n...
# These are TOC / navigation tables (FAQ, Setup, Recomendations).
# Content tables always have a filled header row, so they are not matched.
_MD_NAV_TABLE = re.compile(
    r'\n*'
    r'^\|\s*\|\s*\|\s*$\n'       # empty header row:  | | |
    r'^\|[-|: ]+\|\s*$\n'            # separator row:     |---|---|
    r'(?:^\|.*\|\s*$\n)*',           # data rows
    re.MULTILINE,
)

# <div align="center"> wrapper with a nav button inside
_DIV_WRAPPED = re.compile(
    r'\n*<div[^>]*>\s*\n'
    r'\s*\[!\[(?:' + _BUTTON_NAMES + r')\]\(https://github\.com/ghzserg/zmod/wiki/images/(?:Top|Back|Forward)\.svg\s*\)\]\([^)]*\)\s*\n'
    r'\s*</div>\n*',
    re.IGNORECASE,
)

# Empty centered div wrappers (no content)
_EMPTY_CENTER_DIV = re.compile(
    r'\n*<div\s+align="center">\s*\n\s*</div>\n*',
    re.IGNORECASE,
)

# Standalone nav button (no div wrapper)
_STANDALONE = re.compile(
    r'\[!\[(?:' + _BUTTON_NAMES + r')\]\(https://github\.com/ghzserg/zmod/wiki/images/(?:Top|Back|Forward)\.svg\s*\)\]\([^)]*\)',
    re.IGNORECASE,
)

# ---------- Macros index cleanup ----------
# Remove heading links like: <h1 align="center"><a href="...">...</a></h1>
# and <h2 align="center"><a href="...">...</a></h2>
_HTML_ALIGN_HEADING_LINK = re.compile(
    r'^\s*<h[12]\s+align="center">\s*<a\s+href="[^"]*">.*?</a>\s*</h[12]>\s*$',
    re.IGNORECASE | re.MULTILINE,
)

# Remove centered strong heading line: <p align="center"><strong>...</strong></p>
_HTML_ALIGN_STRONG = re.compile(
    r'^\s*<p\s+align="center">\s*<strong>.*?</strong>\s*</p>\s*$',
    re.IGNORECASE | re.MULTILINE,
)

# Remove standalone separators: *** or --- (with optional surrounding spaces)
_STANDALONE_SEP = re.compile(
    r'^\s*(?:\*\*\*|---)\s*$',
    re.MULTILINE,
)

# Collapse consecutive separators (*** / ---) with no text between them.
_MULTI_SEP_BLOCK = re.compile(
    r'(?:^\s*(?:\*\*\*|---)\s*$\n(?:^\s*$\n)*){2,}',
    re.MULTILINE,
)

# ---------- wiki image syntax ----------
# Convert [[/images/foo.jpg]] -> ![](../images/foo.jpg)
_WIKI_IMAGE = re.compile(
    r'\[\[\s*(?P<path>/images/[^\]]+?)\s*\]\]'
)

# ---------- wiki page links ----------
# Convert absolute GitHub wiki links to relative MkDocs links.
# Examples:
#   https://github.com/ghzserg/zmod/wiki/Setup#внимание-ad5x  -> ru/Setup/#внимание-ad5x
#   https://github.com/ghzserg/zmod/wiki/Setup_en#ad5x-warning -> /Setup/#ad5x-warning
_WIKI_LINK = re.compile(
    r'https://github\.com/ghzserg/zmod/wiki/(?P<page>[A-Za-z0-9_.\-/%]+)(?P<anchor>#[^\s)]+)?'
)


def _convert_wiki_links(markdown: str) -> str:
    """Convert GitHub wiki links to relative MkDocs links."""

    def _replace(match: re.Match[str]) -> str:
        page = match.group('page')
        anchor = match.group('anchor') or ''

        # Skip wiki image assets (buttons, etc.)
        if page.startswith('images/') or page.lower().endswith(('.png', '.jpg', '.jpeg', '.gif', '.svg', '.webp')):
            return match.group(0)

        if page.endswith('_en'):
            base = page[:-3]
            return f'/{base}/{anchor}'
        if page.endswith('_ru'):
            base = page[:-3]
            return f'/ru/{base}/{anchor}'
        return f'/ru/{page}/{anchor}'

    return _WIKI_LINK.sub(_replace, markdown)


def _fix_lists(markdown: str) -> str:
    """Insert a blank line before a list that directly follows a non-list line.

    Python-Markdown treats ``text\n- item`` as a single paragraph.
    This function adds the required blank line so lists render correctly,
    while keeping the source files compatible with GitHub Wiki.
    """
    lines = markdown.split('\n')
    result: list[str] = []
    in_fence = False

    for i, line in enumerate(lines):
        stripped = line.strip()
        # track fenced code blocks (``` or ~~~)
        if _is_fence_delimiter(stripped):
            in_fence = not in_fence

        if not in_fence and i > 0 and _LIST_ITEM.match(line) and lines[i - 1].strip():
            # Case 1: list starts right after a paragraph line
            if not _LIST_ITEM.match(lines[i - 1]):
                result.append('')
            else:
                # Case 2: nested list follows a parent list item without a blank line
                # Example:
                # 6. Parent item
                #    - child
                m = _INDENTED_LIST.match(line)
                if m and _ORDERED_ITEM.match(lines[i - 1]):
                    result.append('')

        # Normalize indentation for nested list items
        if not in_fence:
            m = _INDENTED_LIST.match(line)
            if m:
                # Find previous non-empty line to determine parent indent
                j = i - 1
                while j >= 0 and not lines[j].strip():
                    j -= 1
                if j >= 0 and _LIST_ITEM.match(lines[j]):
                    parent_indent = _INDENTED_LIST.match(lines[j])
                    parent_width = _indent_width(parent_indent.group('indent')) if parent_indent else 0
                    current_width = _indent_width(m.group('indent'))
                    desired_width = parent_width + 4
                    if current_width < desired_width:
                        line = (' ' * desired_width) + line.lstrip()

        # Case 3: ensure a blank line AFTER a nested list block
        if (
            not in_fence
            and i > 0
            and lines[i - 1].strip()
            and not _LIST_ITEM.match(line)
        ):
            prev = lines[i - 1]
            if _INDENTED_LIST.match(prev):
                result.append('')

        # Case 4: nested list ends right before the next top-level list item
        if (
            not in_fence
            and i > 0
            and _TOP_LEVEL_LIST.match(line)
            and _INDENTED_LIST.match(lines[i - 1])
        ):
            result.append('')

        result.append(line)

    return '\n'.join(result)


def _convert_gh_alerts(markdown: str) -> str:
    """Convert GitHub-style alerts to MkDocs admonitions.

    GitHub:                          MkDocs (admonition extension):
      > [!NOTE]                        !!! note
      > First line                         First line
      > Second line                        Second line
    """
    lines = markdown.split('\n')
    result: list[str] = []
    in_fence = False
    i = 0

    while i < len(lines):
        line = lines[i]
        stripped = line.strip()

        # track fenced code blocks
        if _is_fence_delimiter(stripped):
            in_fence = not in_fence

        if not in_fence:
            m = _GH_ALERT_TYPE.match(line)
            if m:
                indent = m.group('indent')
                gh_type = m.group('type').upper()
                adm_type = _GH_ALERT_MAP.get(gh_type, 'note')

                result.append(f'{indent}!!! {adm_type}')

                # Consume continuation lines (start with `>`)
                i += 1
                body_lines: list[str] = []
                while i < len(lines):
                    cline = lines[i]
                    # line continues the blockquote
                    if re.match(r'^\s*>', cline):
                        # strip leading `> ` or `>`
                        content = re.sub(r'^\s*>\s?', '', cline)
                        body_lines.append(f'{indent}    {content}')
                        i += 1
                    else:
                        break

                # Ensure there is at least one content line (even if empty)
                if not body_lines:
                    body_lines.append(f'{indent}    ')

                result.extend(body_lines)
                continue                               # i already advanced

        result.append(line)
        i += 1

    return '\n'.join(result)


def _collapse_separators(markdown: str) -> str:
    """Collapse runs of separator lines into a single separator line."""

    def _replace(match: re.Match[str]) -> str:
        block = match.group(0)
        first = re.search(r'^\s*(\*\*\*|---)\s*$', block, re.MULTILINE)
        sep = first.group(1) if first else '---'
        # Keep a blank line before and after the separator
        return f'\n{sep}\n\n'

    return _MULTI_SEP_BLOCK.sub(_replace, markdown)


def _remove_trailing_separator(markdown: str) -> str:
    """Remove a trailing separator at end of file."""
    return re.sub(r'\n*\s*(?:\*\*\*|---)\s*\n*\Z', '\n', markdown)


def _clean_markdown(markdown: str, *, base_stem: str | None = None) -> str:
    """Pre-process markdown before rendering."""
    # 1. Strip navigation artefacts
    #    Use '\n\n' replacement to preserve blank lines around removed blocks,
    #    preventing '---' from being misinterpreted as setext <h2> headings.
    markdown = _LANG_SWITCH.sub('\n\n', markdown)
    markdown = _BOT_LINK.sub('', markdown)
    markdown = _DIV_WRAPPED.sub('\n\n', markdown)
    markdown = _STANDALONE.sub('', markdown)
    markdown = _EMPTY_CENTER_DIV.sub('\n\n', markdown)
    # 2. Strip navigation tables (HTML and markdown TOC tables)
    markdown = _HTML_TABLE.sub('\n\n', markdown)
    markdown = _MD_NAV_TABLE.sub('\n\n', markdown)
    # 2.1 Strip leftover headings/separators from removed tables (Macros pages only)
    if base_stem == 'Macros':
        markdown = _HTML_ALIGN_HEADING_LINK.sub('', markdown)
        markdown = _HTML_ALIGN_STRONG.sub('', markdown)
    # 3. Convert wiki image syntax to Markdown
    markdown = _WIKI_IMAGE.sub(r'![](..\g<path>)', markdown)
    # 4. Convert absolute GitHub wiki links → relative MkDocs links
    markdown = _convert_wiki_links(markdown)
    # 5. Convert GitHub alerts → MkDocs admonitions
    markdown = _convert_gh_alerts(markdown)
    # 6. Fix lists (blank line before first item)
    markdown = _fix_lists(markdown)
    # 7. Clean up leftover blank lines (3+ in a row → 2)
    markdown = re.sub(r'\n{3,}', '\n\n', markdown)
    # 8. Remove consecutive separators with no text between them
    markdown = _collapse_separators(markdown)
    # 9. Remove trailing separator at EOF
    markdown = _remove_trailing_separator(markdown)
    return markdown


def _base_stem(file_path: Path) -> str:
    stem = file_path.stem
    if stem.endswith('_ru'):
        return stem[:-3]
    if stem.endswith('_en'):
        return stem[:-3]
    return stem


def _file_lang(file_path: Path) -> str | None:
    stem = file_path.stem
    if stem.endswith('_ru'):
        return 'ru'
    if stem.endswith('_en'):
        return 'en'
    return None


def _copy_and_clean_file(src: Path, dest_dir: Path, dest_stem: str) -> None:
    text = src.read_text(encoding='utf-8')
    cleaned = _clean_markdown(text, base_stem=dest_stem)
    dest_dir.mkdir(parents=True, exist_ok=True)
    dest_path = dest_dir / f'{dest_stem}{src.suffix}'
    dest_path.write_text(cleaned, encoding='utf-8')


def _copy_images(wiki_dir: Path, docs_dir: Path) -> None:
    images_src = wiki_dir / 'images'
    if not images_src.exists() or not images_src.is_dir():
        return

    images_dest = docs_dir / 'images'
    images_dest.mkdir(parents=True, exist_ok=True)

    for item in images_src.iterdir():
        if not item.is_file():
            continue
        if item.suffix.lower() == '.svg':
            continue
        shutil.copy2(item, images_dest / item.name)


def main() -> int:
    parser = argparse.ArgumentParser(description='Prepare MkDocs docs from wiki sources.')
    parser.add_argument('--wiki-dir', type=Path, default=None, help='Path to wiki directory')
    parser.add_argument('--docs-dir', type=Path, default=None, help='Path to docs directory')
    args = parser.parse_args()

    root_dir = Path(__file__).resolve().parent.parent
    wiki_dir = args.wiki_dir or (root_dir / 'wiki')
    docs_dir = args.docs_dir or (root_dir / 'docs')

    if not wiki_dir.exists() or not wiki_dir.is_dir():
        raise SystemExit(f'Wiki directory not found: {wiki_dir}')

    _copy_images(wiki_dir, docs_dir)

    files = [p for p in wiki_dir.iterdir() if p.is_file() and not p.name.startswith('_') and not p.name.startswith('Home') and not p.name.startswith('R.')]
    groups: dict[str, list[Path]] = {}
    for src in files:
        groups.setdefault(_base_stem(src), []).append(src)

    for base, group in groups.items():
        by_lang: dict[str, Path] = {}
        base_file: Path | None = None
        for src in group:
            lang = _file_lang(src)
            if lang is None:
                base_file = src
            else:
                by_lang[lang] = src

        if len(group) == 1:
            src = group[0]
            _copy_and_clean_file(src, docs_dir / 'ru', base)
            _copy_and_clean_file(src, docs_dir / 'en', base)
            continue

        if base_file is not None and 'en' in by_lang and 'ru' not in by_lang:
            _copy_and_clean_file(base_file, docs_dir / 'ru', base)
            _copy_and_clean_file(by_lang['en'], docs_dir / 'en', base)
            continue

        if base_file is not None and 'ru' in by_lang and 'en' not in by_lang:
            _copy_and_clean_file(base_file, docs_dir / 'en', base)
            _copy_and_clean_file(by_lang['ru'], docs_dir / 'ru', base)
            continue

        if 'en' in by_lang and 'ru' in by_lang:
            _copy_and_clean_file(by_lang['en'], docs_dir / 'en', base)
            _copy_and_clean_file(by_lang['ru'], docs_dir / 'ru', base)
            continue

        for src in group:
            _copy_and_clean_file(src, docs_dir / 'ru', base)
            _copy_and_clean_file(src, docs_dir / 'en', base)

    return 0


if __name__ == '__main__':
    raise SystemExit(main())
