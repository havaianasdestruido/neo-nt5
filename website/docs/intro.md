---
sidebar_position: 1
---
# NEONT 5 source guide

This repository contains a large historical Windows NT 5-era source tree. The [function reference](../reference) is generated from tracked code; select a top-level component and a file range to explore definitions, internal syntax, potential test calls and same-name definitions in other files.

## Navigating the tree

- `base`, `drivers`, `ds`, `net`, `shell`, `windows`: operating-system components and services.
- `admin`, `com`, `inetcore`, `inetsrv`, `multimedia`, `printscan`, `termsrv`: administration, platform services, networking, media, printing and terminal services.
- `public`, `published`, `sdktools`, `tools`: interfaces, SDK and build tooling.
- `agents/README.md` in the repository contains the more detailed component map and build boundaries.

The root README describes the Razzle environment, build commands, and image creation. These historical instructions require their original Windows build environment and dependencies; the documentation build does not build the operating system.

## Reading the reference

Each entry links to its definition and shows the textual signature, syntactic control constructs, and called names. Same-name definitions show whether their raw body text hashes match; differing text does **not** establish a behavioral difference, and identical text may behave differently with different macros or context. Potential test uses are calls matched by name in paths containing test, tests, testing, unittest, unittests, spec or specs as a filename or directory token. They are not proof that a test runs or calls that specific overload. At most 20 matches of each kind are displayed. Follow the links to understand the actual implementation and assertions.

## Coverage and limitations

The Python generator parses tracked C, C++, Python, JavaScript, Java and C# files, including inline definitions in common headers. It records definitions with bodies, not declarations, macros, function pointers, lambdas, assembly, batch files, or other unsupported languages. Legacy compiler extensions, conditional compilation, encodings, malformed code and parser errors can hide or misidentify definitions and calls. It does not preprocess, resolve symbols, interpret tests, or infer runtime behavior. Parse-error counts are reported in the reference. Search filters the selected range only, not the entire repository. Generated links point at `main` and can differ from an unmerged branch.

## Regeneration and deployment

From the repository root, with Python 3 and Node 20:

```sh
python3 -m venv .venv
. .venv/bin/activate
pip install -r scripts/requirements-docs.txt
python scripts/generate_docs.py
cd website
npm ci
npm run build
```

For local development use `npm start`; for another Pages repository set `DOCS_BASE_URL` to its path, including leading and trailing slashes. The generator uses `git ls-files`, so add new files to Git before generating. Generated inventory is disposable and not checked in. The Pages workflow rebuilds it on every push to `main` and can also be run manually. In repository Settings → Pages, set the source to **GitHub Actions**. Deployment requires Pages permissions and an environment named `github-pages`; repository settings may require approval. This publishes the generated source signatures and links publicly, so confirm the repository and contents are appropriate for public hosting first.
