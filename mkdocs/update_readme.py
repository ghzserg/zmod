#!/usr/bin/env python3
"""Sync README.md and README_ru.md from docs/en/index.md and docs/ru/index.md.

Transformations applied:
1. Remove YAML front matter (--- block)
2. Replace the zmod.link/link/ reference after the logo with two standard links
3. Convert MkDocs !!! danger admonitions to GitHub > [!CAUTION] format
4. Convert all relative Markdown links (starting with /) to absolute wiki.zmod.link URLs
"""

import os
import re

BASE_URL = "https://wiki.zmod.link"
README_LINKS = (
    "[https://zmod.link/](https://zmod.link/) "
    "[@zmod_help_bot](http://t.me/zmod_help_bot)"
)


def remove_front_matter(text: str) -> str:
    """Remove YAML front matter block delimited by ---."""
    if text.startswith("---"):
        end = text.find("\n---", 3)
        if end != -1:
            return text[end + 4 :].lstrip("\n")
    return text


def replace_logo_link(text: str, lang_link: str = "") -> str:
    """After the logo <img>, replace the [zMod LINK...](zmod.link/link/) line
    with the language switch link (if any) and the two standard README links."""
    replacement = (f"{lang_link}\n\n" if lang_link else "") + README_LINKS
    return re.sub(
        r"\[.*?\]\(https://zmod\.link/link/\)",
        replacement,
        text,
    )


def convert_admonitions(text: str) -> str:
    """Convert MkDocs !!! danger blocks to GitHub Markdown > [!CAUTION] format.

    MkDocs format:
        !!! danger
            First paragraph text.

            Second paragraph text.

    GitHub format:
        > [!CAUTION]
        > First paragraph text.
        >
        > Second paragraph text.
    """
    lines = text.split("\n")
    result = []
    i = 0
    while i < len(lines):
        line = lines[i]
        if re.match(r"^!!! danger", line):
            result.append("> [!CAUTION]")
            i += 1
            in_block = True
            while i < len(lines) and in_block:
                curr = lines[i]
                if curr.startswith("    "):
                    # Indented content line — strip 4 spaces, prefix with >
                    result.append("> " + curr[4:])
                    i += 1
                elif curr == "":
                    # Empty line — check if block continues after it
                    j = i + 1
                    while j < len(lines) and lines[j] == "":
                        j += 1
                    if j < len(lines) and lines[j].startswith("    "):
                        # Block continues — emit bare >
                        result.append(">")
                        i += 1
                    else:
                        # Block ends — emit blank line and stop
                        result.append("")
                        i += 1
                        in_block = False
                else:
                    # Non-indented, non-empty line — block ended
                    in_block = False
        else:
            result.append(line)
            i += 1
    return "\n".join(result)


def fix_relative_links(text: str, base: str = BASE_URL) -> str:
    """Convert relative Markdown links (URL starts with /) to absolute URLs."""
    return re.sub(
        r"\[([^\]]*)\]\((/[^)]*)\)",
        lambda m: f"[{m.group(1)}]({base}{m.group(2)})",
        text,
    )


def process(source: str, target: str, lang_link: str = "") -> None:
    with open(source, encoding="utf-8") as f:
        content = f.read()

    content = remove_front_matter(content)
    content = replace_logo_link(content, lang_link)
    content = convert_admonitions(content)
    content = fix_relative_links(content)

    with open(target, "w", encoding="utf-8") as f:
        f.write(content)

    print(f"  {os.path.relpath(source)} → {os.path.relpath(target)}")


if __name__ == "__main__":
    root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    docs = os.path.join(root, "docs")

    print("Syncing README files from docs index pages...")
    process(
        os.path.join(docs, "en", "index.md"),
        os.path.join(root, "README.md"),
        lang_link="[На русском](https://wiki.zmod.link/ru/)",
    )
    process(
        os.path.join(docs, "ru", "index.md"),
        os.path.join(root, "README_ru.md"),
        lang_link="[In English](https://wiki.zmod.link/)",
    )
    print("Done.")
