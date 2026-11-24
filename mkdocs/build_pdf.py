#!/usr/bin/env python3
"""Create one PDF book per MkDocs language from the built HTML site."""

import argparse
import html
import posixpath
import re
from datetime import datetime, timezone
from pathlib import Path
from urllib.parse import unquote, urljoin, urlsplit

import yaml
from bs4 import BeautifulSoup
from pygments.formatters import HtmlFormatter
from weasyprint import HTML, CSS, default_url_fetcher

HERE = Path(__file__).resolve().parent
LABELS = {
    "en": ("User guide", "Contents", "Supported printers", "Edition"),
    "ru": ("Руководство пользователя", "Оглавление", "Поддерживаемые принтеры", "Версия"),
    "de": ("Benutzerhandbuch", "Inhaltsverzeichnis", "Unterstützte Drucker", "Version"),
    "cs": ("Uživatelská příručka", "Obsah", "Podporované tiskárny", "Verze"),
}


def nav_pages(items, translations):
    for item in items:
        if isinstance(item, dict):
            for title, value in item.items():
                if isinstance(value, list):
                    yield from nav_pages(value, translations)
                elif value.endswith(".md"):
                    yield value, translations.get(title, title)
        elif isinstance(item, str) and item.endswith(".md"):
            yield item, Path(item).stem


def route(path):
    """Normalize both directory URLs and index.html to the same key."""
    path = posixpath.normpath(unquote(path))
    if path.endswith("/index.html"):
        path = path[:-len("/index.html")]
    return path.rstrip("/") or "/"


def page_path(site, prefix, source):
    rel = Path(source)
    if rel.name == "index.md":
        return site / prefix / rel.parent / "index.html"
    return site / prefix / rel.with_suffix("") / "index.html"


def local_asset(site, origin, url):
    parsed = urlsplit(url)
    if parsed.netloc != origin.netloc or parsed.scheme not in ("http", "https"):
        return url
    path = (site / unquote(parsed.path).lstrip("/")).resolve()
    if path.is_relative_to(site) and path.is_file():
        return path.as_uri()
    return url


def build_book(config, site, docs, lang, output):
    locale = lang["locale"]
    prefix = "" if lang.get("default") == "true" else locale
    title, contents, printers, edition = LABELS.get(locale, LABELS["en"])
    origin = urlsplit(config["site_url"])
    pages = dict(nav_pages(config["nav"], lang.get("nav_translations", {})))
    # Include documentation pages reachable by links but absent from navigation.
    for source in sorted((docs / locale).rglob("*.md")):
        pages.setdefault(source.relative_to(docs / locale).as_posix(), None)

    chapters = []
    targets = {}
    for source, nav_title in pages.items():
        path = page_path(site, prefix, source)
        if not path.is_file():
            raise FileNotFoundError(f"{locale}: missing built page {path}")
        soup = BeautifulSoup(path.read_text(encoding="utf-8"), "html.parser")
        article = soup.select_one("article.md-content__inner")
        if article is None:
            raise ValueError(f"{path}: Material article not found")
        for element in article.select(
            ".md-content__button, .headerlink, .edit-page-footer, "
            "#download-icon-template, .pdf-download, script, style, input"
        ):
            element.decompose()
        for element in article.select("details"):
            element.name = "div"
            element["class"] = ["print-details"]
            element.attrs.pop("open", None)
        for element in article.select("summary"):
            element.name = "p"
            element["class"] = ["print-summary"]
        chapter_id = f"chapter-{len(chapters) + 1}"
        url = urljoin(config["site_url"], path.relative_to(site).parent.as_posix() + "/")
        if path.parent == site:
            url = config["site_url"]
        key = route(urlsplit(url).path)
        heading = article.find("h1", recursive=False)
        chapter_title = nav_title or (heading.get_text(" ", strip=True) if heading else path.parent.name)
        if heading:
            # Retain the original anchor, but avoid duplicate chapter headings.
            heading.name = "span"
            heading.clear()
            heading.attrs.pop("align", None)
        anchors = {}
        for element in article.select("[id]"):
            original = element["id"]
            if original not in anchors:
                anchors[original] = f"{chapter_id}-a{len(anchors) + 1}"
                element["id"] = anchors[original]
            else:
                del element["id"]
        for element in article.select("h1"):
            element.name = "h2"
        targets[key] = (chapter_id, anchors)
        chapters.append((chapter_id, chapter_title, url, article))

    sections = []
    toc = []
    for chapter_id, chapter_title, url, article in chapters:
        for link in article.select("a[href]"):
            href = link["href"]
            absolute = urljoin(url, href)
            parsed = urlsplit(absolute)
            target = targets.get(route(parsed.path)) if parsed.netloc == origin.netloc else None
            if target and (not parsed.fragment or unquote(parsed.fragment) in target[1]):
                link["href"] = "#" + (target[1][unquote(parsed.fragment)] if parsed.fragment else target[0])
            else:
                link["href"] = absolute
        for img in article.select("img"):
            src = img.get("data-src") or img.get("src")
            if src:
                img["src"] = local_asset(site, origin, urljoin(url, src))
            for attr in ("srcset", "sizes", "loading", "height", "style"):
                img.attrs.pop(attr, None)
        for frame in article.select("iframe, video"):
            src = frame.get("src")
            # Media cannot be played in a printed book; retain a usable link.
            if src:
                replacement = BeautifulSoup("", "html.parser").new_tag("a", href=urljoin(url, src))
                replacement.string = src
                frame.replace_with(replacement)
            else:
                frame.decompose()
        escaped = html.escape(chapter_title)
        toc.append(f'<li><a href="#{chapter_id}">{escaped}</a></li>')
        sections.append(
            f'<section class="chapter" id="{chapter_id}"><h1>{escaped}</h1>'
            + article.decode_contents() + "</section>"
        )

    logo = (site / "images/logo.png").as_uri()
    author = html.escape(config.get("site_author", "ghzserg"))
    year = datetime.now(timezone.utc).year
    changelog = (docs / "en" / "Changelog.md").read_text(encoding="utf-8")
    latest = re.search(r"^### Version (\d+(?:\.\d+)+[-\w.]*)\s*$", changelog, re.MULTILINE)
    version = latest.group(1) if latest else ""
    edition_text = f"{edition} {version} · " if version else ""
    copyright_text = f"© 2024–{year} {author}"
    document = (
        f'<!doctype html><html lang="{html.escape(locale)}"><head><meta charset="utf-8">'
        f'<meta name="author" content="{author}">'
        f'<title>Z-Mod — {html.escape(title)}</title></head><body>'
        '<section class="cover">'
        f'<div class="cover-top"><span>Z-MOD</span><span>{html.escape(locale.upper())}</span></div>'
        f'<div class="cover-brand"><img src="{logo}" alt="Z-Mod"><h1>Z-Mod</h1>'
        f'<p class="cover-title">{html.escape(title)}</p>'
        f'<p class="cover-edition">{html.escape(edition_text + lang["name"])}</p></div>'
        f'<div class="cover-models"><p>{html.escape(printers)}</p>'
        '<div>AD5M &nbsp; / &nbsp; AD5M Pro &nbsp; / &nbsp; AD5X</div>'
        '<div>Creator 5 &nbsp; / &nbsp; Creator 5 Pro</div></div>'
        '<div class="cover-footer">'
        f'<p class="cover-copyright">{copyright_text}</p>'
        f'<p><a href="{html.escape(config["repo_url"])}">github.com/ghzserg/zmod</a>'
        f' &nbsp; · &nbsp; <a href="{html.escape(config["site_url"])}">wiki.zmod.link</a></p>'
        '</div></section>'
        f'<section class="contents"><h1>{html.escape(contents)}</h1><ol>'
        + "".join(toc) + "</ol></section>" + "".join(sections) + "</body></html>"
    )

    def fetch(url):
        # Use the generated site for wiki assets instead of the previous deployment.
        return default_url_fetcher(local_asset(site, origin, url), timeout=15)

    destination = output / f"Z-Mod-{locale.upper()}.pdf"
    HTML(string=document, base_url=site.as_uri() + "/", url_fetcher=fetch).write_pdf(
        destination,
        stylesheets=[
            CSS(filename=HERE / "pdf.css"),
            CSS(string=HtmlFormatter().get_style_defs([".highlight", ".codehilite"])),
        ],
        optimize_images=True, jpeg_quality=85, dpi=150,
    )
    print(f"{destination}: {len(chapters)} chapters, {destination.stat().st_size:,} bytes", flush=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--config", type=Path, default=HERE / "mkdocs.yml")
    args = parser.parse_args()
    config = yaml.load(args.config.read_text(encoding="utf-8"), Loader=yaml.BaseLoader)
    site = (args.config.parent / config["site_dir"]).resolve()
    docs = (args.config.parent / config["docs_dir"]).resolve()
    output = site / "pdf"
    output.mkdir(exist_ok=True)
    i18n = next(plugin["i18n"] for plugin in config["plugins"] if isinstance(plugin, dict) and "i18n" in plugin)
    for lang in i18n["languages"]:
        if lang.get("build", "true") == "true":
            build_book(config, site, docs, lang, output)


if __name__ == "__main__":
    main()
