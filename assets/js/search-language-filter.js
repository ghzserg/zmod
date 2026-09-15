(() => {
  const DEFAULT_LOCALE = "en";
  const LOCALES = ["en", "ru", "de", "pt", "cs"];
  const NON_DEFAULT_LOCALES = LOCALES.filter((locale) => locale !== DEFAULT_LOCALE);
  const localeSet = new Set(LOCALES);
  let isFiltering = false;
  let isScheduled = false;

  function detectLocaleFromPathname(pathname) {
    const segments = String(pathname || "")
      .split("/")
      .filter(Boolean);

    const localeSegment = segments.find((segment) => localeSet.has(segment));
    return localeSegment || null;
  }

  function getCurrentLocale() {
    return detectLocaleFromPathname(window.location.pathname) || DEFAULT_LOCALE;
  }

  function toPathname(href) {
    try {
      return new URL(href, window.location.origin).pathname;
    } catch {
      return href || "";
    }
  }

  function hasLocaleSegment(value, locale) {
    const normalized = String(value || "").split("#")[0].split("?")[0];
    const localeRegex = new RegExp(`(?:^|/)${locale}(?:/|$)`);
    return localeRegex.test(normalized);
  }

  function isAllowedPath(pathname, currentLocale, href) {
    const pathLocale = detectLocaleFromPathname(pathname);
    const hasLocale = (locale) => pathLocale === locale || hasLocaleSegment(pathname, locale) || hasLocaleSegment(href, locale);

    if (currentLocale === DEFAULT_LOCALE) {
      return !NON_DEFAULT_LOCALES.some((locale) => hasLocale(locale));
    }

    return hasLocale(currentLocale);
  }

  function isBrokenSearchLink(pathname, href, link) {
    const normalizedPath = String(pathname || "").toLowerCase();
    const normalizedHref = String(href || "").toLowerCase();

    if (normalizedPath === "/undefined" || normalizedPath.startsWith("/undefined/")) {
      return true;
    }

    if (normalizedHref.includes("/undefined") || normalizedHref.endsWith("undefined") || normalizedHref.endsWith("undefined?h=")) {
      return true;
    }

    const text = (link.textContent || "").replace(/\s+/g, "").trim();
    return text.length === 0;
  }

  function isVisible(element) {
    return !!element && window.getComputedStyle(element).display !== "none";
  }

  function updateSearchMetaCount() {
    const meta = document.querySelector(".md-search-result__meta");
    if (!meta) {
      return;
    }

    const totalItems = document.querySelectorAll(".md-search-result__item").length;
    if (totalItems === 0) {
      return;
    }

    const visibleItems = Array.from(document.querySelectorAll(".md-search-result__item")).filter(isVisible).length;
    const currentText = (meta.textContent || "").trim();
    let nextText = null;

    if (/\d+/.test(currentText)) {
      nextText = currentText.replace(/\d+/, String(visibleItems));
    } else if (currentText.includes("#")) {
      nextText = currentText.replace("#", String(visibleItems));
    }

    if (nextText !== null && nextText !== currentText) {
      meta.textContent = nextText;
    }
  }

  function filterSearchResults() {
    if (isFiltering) {
      return;
    }

    isFiltering = true;

    try {
      const currentLocale = getCurrentLocale();
      const links = document.querySelectorAll(".md-search-result__link[href]");

      links.forEach((link) => {
        const href = link.getAttribute("href") || "";
        const pathname = toPathname(href);
        const isAllowed = isAllowedPath(pathname, currentLocale, href);
        const isBroken = isBrokenSearchLink(pathname, href, link);
        link.style.display = isAllowed && !isBroken ? "" : "none";
      });

      const moreBlocks = document.querySelectorAll("details.md-search-result__more");
      moreBlocks.forEach((block) => {
        const blockLinks = Array.from(block.querySelectorAll(".md-search-result__link"));
        const hasVisibleLink = blockLinks.some(isVisible);
        block.style.display = blockLinks.length > 0 && !hasVisibleLink ? "none" : "";
      });

      const items = document.querySelectorAll(".md-search-result__item");
      items.forEach((item) => {
        const itemLinks = Array.from(item.querySelectorAll(".md-search-result__link"));
        const hasVisibleLink = itemLinks.some(isVisible);
        item.style.display = hasVisibleLink ? "" : "none";
      });

      updateSearchMetaCount();
    } finally {
      isFiltering = false;
    }
  }

  function scheduleFilterSearchResults() {
    if (isScheduled) {
      return;
    }

    isScheduled = true;
    requestAnimationFrame(() => {
      isScheduled = false;
      filterSearchResults();
    });
  }

  function startObserver() {
    const searchRoot = document.querySelector('[data-md-component="search-result"]') || document.body;
    const observer = new MutationObserver(() => {
      if (isFiltering) {
        return;
      }

      scheduleFilterSearchResults();
    });

    observer.observe(searchRoot, {
      childList: true,
      subtree: true,
    });

    scheduleFilterSearchResults();
  }

  if (document.readyState === "loading") {
    document.addEventListener("DOMContentLoaded", startObserver, { once: true });
  } else {
    startObserver();
  }
})();
