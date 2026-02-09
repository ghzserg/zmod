function upsertDownloadButton() {
  const headerInner = document.querySelector('.md-header__inner');
  if (!headerInner) {
    return;
  }

  let btn = headerInner.querySelector('#header-download-button');
  if (!btn) {
    btn = document.createElement('a');
    btn.id = 'header-download-button';
    btn.className = 'md-header__button md-button header-download-button';
    const iconTemplate = document.getElementById('download-icon-template');
    const iconHtml = iconTemplate ? iconTemplate.innerHTML.trim() : '';
    btn.innerHTML = `
      <span class="md-icon" aria-hidden="true">${iconHtml}</span>
    `;
    const options = headerInner.querySelectorAll('.md-header__option');
    if (options.length > 0) {
      headerInner.insertBefore(btn, options[0]);
    } else {
      headerInner.appendChild(btn);
    }
  }

  btn.href = 'https://github.com/ghzserg/zmod/releases/latest';
  btn.target = '_blank';
  btn.rel = 'noopener noreferrer';

  const lang = (document.documentElement.lang || 'en').toLowerCase();
  const tooltip = lang.startsWith('ru') ? 'Скачать последний релиз' : 'Download latest release';
  btn.title = tooltip;
  btn.setAttribute('aria-label', tooltip);

}

document.addEventListener('DOMContentLoaded', () => {
  upsertDownloadButton();
});

// Support MkDocs Material instant navigation
if (window.document$ && typeof window.document$.subscribe === 'function') {
  window.document$.subscribe(() => {
    upsertDownloadButton();
  });
}
