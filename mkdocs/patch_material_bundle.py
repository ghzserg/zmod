#!/usr/bin/env python3
"""Patch MkDocs Material bundle to disable lazy search chunks.

This script finds current `bundle.*.min.js` files from installed Material theme,
applies the search render patch, and writes patched copies to:

    mkdocs/overrides/assets/javascripts/

Run it after updating mkdocs-material.
"""

from __future__ import annotations

import re
import sys
import shutil
from pathlib import Path


LAZY_PATTERN = re.compile(
    r"b\(\(\{items:l\}\)=>L\(\$\(\.\.\.l\.slice\(0,10\)\),"
    r"\$\(\.\.\.l\.slice\(10\)\)\.pipe\(ot\(4\),Xr\(n\),"
    r"b\(\s*\(\[f\]\)=>f\)\)\)\)",
    re.S,
)

PATCH_REPLACEMENT = "b(({items:l})=>$(...l))"
_LAST_MIRROR_KEY: tuple[str, int] | None = None


def find_material_bundle_dir() -> Path:
    try:
        import material  # type: ignore
    except Exception as exc:  # pragma: no cover
        raise RuntimeError(
            "Cannot import `material` package. Install mkdocs-material first."
        ) from exc

    material_root = Path(material.__file__).resolve().parent
    bundle_dir = material_root / "templates" / "assets" / "javascripts"
    if not bundle_dir.exists():
        raise RuntimeError(f"Material assets directory not found: {bundle_dir}")

    return bundle_dir


def patch_bundle_content(content: str) -> tuple[str, bool]:
    if PATCH_REPLACEMENT in content and "slice(0,10)" not in content:
        return content, True

    patched, count = LAZY_PATTERN.subn(PATCH_REPLACEMENT, content, count=1)
    return patched, count == 1


def run_patch() -> int:
    script_dir = Path(__file__).resolve().parent
    overrides_dir = script_dir / "overrides" / "assets" / "javascripts"
    overrides_dir.mkdir(parents=True, exist_ok=True)

    src_dir = find_material_bundle_dir()
    src_bundles = sorted(src_dir.glob("bundle.*.min.js"))
    if not src_bundles:
        print(f"No bundle.*.min.js files found in {src_dir}")
        return 1

    patched_names: set[str] = set()
    for src_bundle in src_bundles:
        content = src_bundle.read_text(encoding="utf-8")
        patched, ok = patch_bundle_content(content)
        if not ok:
            print(f"[WARN] Pattern not found in {src_bundle.name}. Skipped.")
            continue

        out_path = overrides_dir / src_bundle.name
        out_path.write_text(patched, encoding="utf-8")
        patched_names.add(src_bundle.name)
        print(f"[OK] Patched {src_bundle.name} -> {out_path}")

    # Remove stale overridden bundles that no longer exist in current theme.
    for stale in overrides_dir.glob("bundle.*.min.js"):
        if stale.name not in patched_names:
            stale.unlink()
            print(f"[CLEAN] Removed stale override {stale.name}")

    if not patched_names:
        print("No bundles patched. Check theme version/pattern.")
        return 2

    print("Done.")
    return 0


def on_startup(command: str, dirty: bool) -> None:  # MkDocs hook
    if command not in {"serve", "build", "gh-deploy"}:
        return

    code = run_patch()
    if code != 0:
        print(f"[WARN] patch_material_bundle failed with code {code}")


def _extract_locales(config: dict) -> set[str]:
    locales: set[str] = set()

    try:
        plugins = config.get("plugins")
        i18n_plugin = plugins.get("i18n") if plugins is not None else None
        i18n_cfg = getattr(i18n_plugin, "config", {}) if i18n_plugin is not None else {}
        languages = i18n_cfg.get("languages", []) if isinstance(i18n_cfg, dict) else []

        default_locale = None
        for item in languages:
            locale = None
            is_default = False

            if isinstance(item, dict):
                locale = item.get("locale")
                is_default = bool(item.get("default", False))
            else:
                locale = getattr(item, "locale", None)
                is_default = bool(getattr(item, "default", False))

            if locale:
                locales.add(str(locale))
            if is_default and locale:
                default_locale = str(locale)

        if default_locale:
            locales.discard(default_locale)
    except Exception:
        pass

    # Fallback for this repository structure if plugin internals differ.
    if not locales:
        locales = {"ru", "de", "pt", "cs"}

    return locales


def _mirror_sitemap_for_locales(config: dict) -> None:
    global _LAST_MIRROR_KEY

    site_dir = Path(config.get("site_dir", "site")).resolve()
    root_sitemap = site_dir / "sitemap.xml"
    root_sitemap_gz = site_dir / "sitemap.xml.gz"

    if not root_sitemap.exists():
        return

    mirror_key = (str(site_dir), root_sitemap.stat().st_mtime_ns)
    if _LAST_MIRROR_KEY == mirror_key:
        return
    _LAST_MIRROR_KEY = mirror_key

    locales = _extract_locales(config)
    for locale in sorted(locales):
        locale_dir = site_dir / locale
        if not locale_dir.exists() or not locale_dir.is_dir():
            continue

        out_xml = locale_dir / "sitemap.xml"
        shutil.copy2(root_sitemap, out_xml)

        if root_sitemap_gz.exists():
            out_gz = locale_dir / "sitemap.xml.gz"
            shutil.copy2(root_sitemap_gz, out_gz)

        print(f"[OK] Mirrored sitemap for /{locale}/")


def on_post_build(config: dict) -> None:  # MkDocs hook
    _mirror_sitemap_for_locales(config)


if __name__ == "__main__":
    sys.exit(run_patch())
