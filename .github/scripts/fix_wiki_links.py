"""Fix percent-encoded Cyrillic in wiki markdown links.

Rewrites URL fragments like:
  https://.../FAQ#%D1%8F-... -> https://.../FAQ#я-...

Only decodes the fragment part after '#'.
"""
from __future__ import annotations

from pathlib import Path
import re
from urllib.parse import urlsplit, urlunsplit, unquote

WIKI_DIR = Path(__file__).resolve().parent.parent.parent / "wiki"

# Markdown link: [text](url)
MD_LINK = re.compile(r"\[([^\]]+)\]\(([^)]+)\)")


def decode_anchor(url: str) -> str:
    if "#" not in url or "%" not in url:
        return url
    parts = urlsplit(url)
    if not parts.fragment or "%" not in parts.fragment:
        return url
    decoded_fragment = unquote(parts.fragment)
    return urlunsplit((parts.scheme, parts.netloc, parts.path, parts.query, decoded_fragment))


def fix_links(text: str) -> str:
    def repl(match: re.Match[str]) -> str:
        label, url = match.group(1), match.group(2)
        return f"[{label}]({decode_anchor(url)})"

    return MD_LINK.sub(repl, text)


def main() -> int:
    if not WIKI_DIR.exists():
        raise SystemExit(f"Wiki directory not found: {WIKI_DIR}")

    changed = 0
    for md_file in sorted(WIKI_DIR.glob("*.md")):
        original = md_file.read_text(encoding="utf-8")
        updated = fix_links(original)
        if updated != original:
            md_file.write_text(updated, encoding="utf-8")
            changed += 1

    print(f"Updated files: {changed}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
