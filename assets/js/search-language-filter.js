(() => {
  const DEFAULT_LOCALE = "en";
  const LOCALES = ["en", "ru", "de", "pt", "cs"];
  const NON_DEFAULT_LOCALES = LOCALES.filter((locale) => locale !== DEFAULT_LOCALE);

  const localePrefixRegex = new RegExp(`^/(${NON_DEFAULT_LOCALES.join("|")})(/|$)`);

  function getCurrentLocale() {
    const match = window.location.pathname.match(localePrefixRegex);
    return match ? match[1] : DEFAULT_LOCALE;
  }

  function toPathname(href) {
    try {
      return new URL(href, window.location.origin).pathname;
    } catch {
      return href || "";
    }
  }

  function isAllowedPath(pathname, currentLocale) {
    if (currentLocale === DEFAULT_LOCALE) {
      return !NON_DEFAULT_LOCALES.some(
        (locale) => pathname === `/${locale}` || pathname.startsWith(`/${locale}/`)
      );
    }

    return pathname === `/${currentLocale}` || pathname.startsWith(`/${currentLocale}/`);
  }

  function filterSearchResults() {
    const currentLocale = getCurrentLocale();
    const items = document.querySelectorAll(".md-search-result__item");

    items.forEach((item) => {
      const link = item.querySelector("a[href]");
      if (!link) {
        return;
      }

      const pathname = toPathname(link.getAttribute("href"));
      item.style.display = isAllowedPath(pathname, currentLocale) ? "" : "none";
    });
  }

  function startObserver() {
    const searchRoot = document.querySelector('[data-md-component="search-result"]') || document.body;
    const observer = new MutationObserver(() => {
      filterSearchResults();
    });

    observer.observe(searchRoot, {
      childList: true,
      subtree: true,
    });

    filterSearchResults();
  }

  if (document.readyState === "loading") {
    document.addEventListener("DOMContentLoaded", startObserver, { once: true });
  } else {
    startObserver();
  }
})();
