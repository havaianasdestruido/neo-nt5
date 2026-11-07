# Documentation maintenance

The Docusaurus site combines a hand-written overview with an automatically generated function index. From the repository root, use Python 3.11+ and Node 20+:

```sh
python3 -m pip install -r documentation/requirements.txt
python3 -m unittest discover -s documentation/tests
python3 documentation/scripts/generate.py
cd documentation/site
npm ci
npm run build
npm start
```

Generation uses tracked and unignored untracked files, and removes old Markdown files **only** in the output directory. Generated pages are not committed. `--prefix base/ntos/` limits a local run; repeat it for multiple prefixes. Do not deploy a prefix-limited run as the full reference. `--output` chooses a dedicated generated directory; `--revision` changes source links. By default links use the current commit (or `GITHUB_SHA` in Actions), so uncommitted changes may not appear at their links.

The GitHub Actions workflow regenerates and builds on pushes to `main` and manual dispatch, then publishes the artifact with GitHub Pages. In repository Settings → Pages, set the source to **GitHub Actions**; ensure Pages is enabled and Actions are permitted. The configured repository name determines the Pages base path. A successful workflow and repository Pages settings are required before a live site exists.

## Interpretation and scope

The generator uses tree-sitter for C/C++ and Python's AST for Python. It does not preprocess C/C++, resolve symbols, execute tests, or analyze other languages. Headers use the C++ grammar; malformed/legacy code may be only partly parsed. A report lists parsing failures. Test candidates are call expressions in paths containing a test-related segment, matched by leaf name; overloads, macros, indirect calls and similarly named unrelated functions make these references incomplete or false positives. Hashes identify textual body differences only; they cannot establish behavioral equivalence or difference. No automated inventory can honestly explain every function's internal semantics or guarantee every test association in this tree. Inspect the linked files and build configurations, and run the relevant tests when those answers matter.
