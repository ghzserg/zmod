# Installing and Running MkDocs for zMod Wiki

## 1. Install dependencies

```bash
# Install Python 3.8+
pip install -r requirements.txt
```

## 2. Local preview

Start the development server:

```bash
mkdocs serve
```

Open in your browser: **http://localhost:8000**

The site will auto-refresh when files change.

## 3. Build static site

Generate the site for publishing:

```bash
mkdocs build
```

The output will be in the `site/` folder.

## 4. Publish to GitHub Pages

```bash
mkdocs gh-deploy
```

This automatically creates the `gh-pages` branch and publishes the site.

## Project structure

```
zmod/
├── mkdocs/
│   ├── mkdocs.yml          # MkDocs configuration
│   ├── prepare_docs.py     # Wiki → docs preprocessing
│   ├── requirements.txt    # Python dependencies
│   └── overrides/
│       ├── main.html       # Theme overrides
│       └── css/            # Custom styles
├── docs/                   # Generated MkDocs sources (en/ru)
├── wiki/                   # Source wiki files
│   ├── *.md
│   └── images/
└── site/                   # (generated) Static site output
```

## Configuration

All settings are in `mkdocs.yml`:
- **Navigation menu** - `nav` section
- **Theme and extensions** - `theme` and `markdown_extensions`
- **Language** - `language: en`

## Commands

| Command | Description |
|---------|-------------|
| `mkdocs serve` | Start local server |
| `mkdocs build` | Build static site |
| `mkdocs gh-deploy` | Publish to GitHub Pages |
| `mkdocs --help` | Command help |
