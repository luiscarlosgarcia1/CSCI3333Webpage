# CSCI 3333 Course Website

This project is a static course website for CSCI 3333. It brings together the course outline, weekly recap pages, and supporting learning materials such as practice problems, examples, and review documents.

## Folder structure

```text
.
├── index.html          # Main course website page
├── components/         # Reusable page sections and styles
│   └── weeks/          # Weekly page-content components
└── assets/             # Course resources
    └── weeks/          # Week-specific recaps and materials
```

## Run locally

From this folder, run:

```bash
python3 -m http.server 8000
```

Then open <http://localhost:8000> in your browser.
