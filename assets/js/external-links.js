function applyExternalLinks(root = document) {
  const links = root.querySelectorAll('a[href^="http"]');
  for (const link of links) {
    try {
      const url = new URL(link.href, window.location.href);
      if (url.host && url.host !== window.location.host) {
        link.target = '_blank';
        link.rel = 'noopener noreferrer';
      }
    } catch {
      // Ignore invalid URLs
    }
  }
}

document.addEventListener('DOMContentLoaded', () => {
  applyExternalLinks();
});

// Support MkDocs Material instant navigation
if (window.document$ && typeof window.document$.subscribe === 'function') {
  window.document$.subscribe(() => {
    applyExternalLinks();
  });
}
