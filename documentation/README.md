# Documentation maintenance

The Docusaurus site combines hand-written guide pages with an automatically generated function
index. From the repository root, use Python 3.11+ and Node 20+:

```sh
python3 -m pip install -r documentation/requirements.txt
python3 -m unittest discover -s documentation/tests
python3 documentation/scripts/generate.py
cd documentation/site
npm ci
npm run build
npm start
```

## Guide pages

Thirty hand-written pages live in `site/docs/` and are ordered by `sidebar_position` 1–30. They fall
into three groups: the eleven guide pages (1–11) that explain the source tree, the API reference
(12–30) that maps the Windows API onto it, and `glossary.md` (28) as the term index.

| Position | File | Subject |
| --- | --- | --- |
| 1 | `overview.md` (slug `/`) | What the checkout contains, how the site is assembled |
| 2 | `architecture.md` | Boot chain, kernel/user boundary, Win32k vs `ntos`, build variants |
| 3 | `build.md` | Razzle, `dirs`/`sources`/`makefile`, postbuild, SKUs, checkout gaps |
| 4 | `kernel.md` | The `base/ntos` managers, system services, object and handle lifetimes |
| 5 | `io-storage.md` | IRP lifecycle, file systems, class/port drivers, Plug and Play |
| 6 | `networking.md` | NDIS, TCP/IP, TDI, Winsock and AFD |
| 7 | `win32-shell.md` | Where Win32 is implemented, the window server, the shell |
| 8 | `security-directory.md` | Access checks, tokens, auditing, LSA, Active Directory layers |
| 9 | `interfaces.md` | Public/published/private headers, IDL/RPC, MOF, INFs |
| 10 | `testing-debugging.md` | Test conventions, Driver Verifier, `gflags`, `kdext` extensions |
| 11 | `function-index.md` | How the generated index works and how to read it |
| 12 | `windows-api.md` | How Win32, the native API and the driver interfaces fit together |
| 13 | `kernel32-file-api.md` | Files, directories, pipes, mailslots, file mapping |
| 14 | `kernel32-process-api.md` | Processes, threads, TLS, waits, synchronization primitives |
| 15 | `kernel32-memory-api.md` | `VirtualAlloc`, heaps, protection, mapped views, kernel pools |
| 16 | `kernel32-library-api.md` | `LoadLibrary`, the DLL search order, resources, ToolHelp |
| 17 | `user32-api.md` | Window classes, the message loop, dialogs, hooks, the clipboard |
| 18 | `gdi32-api.md` | Device contexts, pens, bitmaps and DIBs, fonts, palettes |
| 19 | `advapi32-api.md` | Registry, the SCM, the event log, tokens, CryptoAPI |
| 20 | `ntdll-api.md` | The `Rtl`, `Ldr`, `Csr` and `SxS` families |
| 21 | `native-api.md` | The `Nt*`/`Zw*` syscall path and the core native services |
| 22 | `structures.md` | `UNICODE_STRING`, `OBJECT_ATTRIBUTES`, the structures behind the API |
| 23 | `status-codes.md` | `NTSTATUS`, Win32 errors, `HRESULT` and how to decode them |
| 24 | `driver-model.md` | `DriverEntry`, dispatch tables, IRPs, PnP and power, IRQL |
| 25 | `pe-loader.md` | PE/COFF layout, imports, exports, relocations, `Ldr` mapping |
| 26 | `registry.md` | Hives, keys, values and cells, `Reg*` and its native services |
| 27 | `com-rpc.md` | COM, class factories, the RPC runtime, NDR, MIDL |
| 28 | `glossary.md` | Every abbreviation and term used across the site |
| 29 | `winsock-api.md` | Winsock 2, the SPI, how `ws2_32.dll` reaches `afd.sys` |
| 30 | `kernel-objects.md` | The object manager, handle tables, references, the object directory |

Generated pages are plain static HTML under `site/static/reference/` (`index.html`,
bucket pages like `base-0001.html`, and `coverage.html`). They are copied verbatim into the
published site and are *not* Docusaurus documents, so they do not appear in the sidebar and do
not go through webpack — the full index would otherwise exhaust Node's heap during
`docusaurus build` (over a million definitions across ~3600 pages).

Rules that keep the guide pages honest:

* **Every claim cites a path**, and paths link to `github.com/.../blob/main/...` rather than to a
  relative file link, because relative links resolve against the site base URL and would break.
* **Snippets are short quotations** of real source, not paraphrases. Verify them with `sed -n` or
  `rg -n` before editing a page that quotes them; the tree moves.
* **Never assert a build, install or boot.** State what was and was not run.
* MDX is strict: wrap anything containing `{`, `}` or `<` in a code span or fence, or the build fails.

## Frequently asked questions on every page

Every page on the site carries a `## Frequently asked questions` section that answers questions about
**that page's own content**:

* On the guide pages, the FAQ is hand-written alongside the prose.
* On generated pages, it is emitted by `generate.py` from that page's own extracted data — the entry
  count, how many entries share a name, how many lack test evidence, and the first entry's real
  captured signature — via `page_faq()`, `index_faq()` and `coverage_faq()`.

When you add a guide page, add its FAQ. When you change what a generated page shows, update the
matching `*_faq()` function, because a FAQ that no longer matches the page is worse than none.
`documentation/tests/test_generate.py` asserts that every written page contains the section and that
the per-page counts and quoted signature come from that page's data.

Generation uses tracked and unignored untracked files, and removes old HTML files **only** in the output directory (plus any stale Markdown left under the old `site/docs/reference/` location). Generated pages are not committed (`documentation/.gitignore` excludes `site/static/reference/`). `--prefix base/ntos/` limits a local run; repeat it for multiple prefixes. Do not deploy a prefix-limited run as the full reference. `--output` chooses a dedicated generated directory (default `site/static/reference/`); `--revision` changes source links. By default links use the current commit (or `GITHUB_SHA` in Actions), so uncommitted changes may not appear at their links.

The GitHub Actions workflow regenerates and builds on pushes to `main` and manual dispatch, then publishes the artifact with GitHub Pages. In repository Settings → Pages, set the source to **GitHub Actions**; ensure Pages is enabled and Actions are permitted. The configured repository name determines the Pages base path. A successful workflow and repository Pages settings are required before a live site exists. The generated pages are static files copied verbatim, so the Docusaurus build does not validate them — the guide pages and navbar link to them with ordinary URLs. Run the generator before `npm run build` so the published site actually contains the index.

## Interpretation and scope

The generator uses tree-sitter for C/C++ and Python's AST for Python. It does not preprocess C/C++, resolve symbols, execute tests, or analyze other languages. Headers use the C++ grammar; malformed/legacy code may be only partly parsed. A report lists parsing failures. Test candidates are call expressions in paths containing a test-related segment, matched by leaf name; overloads, macros, indirect calls and similarly named unrelated functions make these references incomplete or false positives. Hashes identify textual body differences only; they cannot establish behavioral equivalence or difference. No automated inventory can honestly explain every function's internal semantics or guarantee every test association in this tree. Inspect the linked files and build configurations, and run the relevant tests when those answers matter.
