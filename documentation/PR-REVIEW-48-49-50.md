# Review of the three documentation PRs (#48, #49, #50)

All three PRs branched from the same commit (`b5251b6`) and all three tried to do the same job: turn
the 11-page Docusaurus site in `documentation/site/docs/` into a real Windows source-code reference.
They were mutually exclusive — #49 and #50 rewrite the same 11 guide files and both add a
`native-api.md`, so they could not both apply.

**Outcome:** #49 merged (`43c0c43`). #48 and #50 closed with their unique contributions called out.

Everything below was measured, not taken from the PR descriptions. Where a PR's own claim and my
measurement disagree, the measurement is what is written here.

---

## 1. Headline numbers

| | baseline `main` | #48 | #49 (merged) | #50 |
| --- | --- | --- | --- | --- |
| Guide pages touched | — | 0 of 11 | **11 of 11** | 11 of 11 |
| New reference pages | — | 8 | **19** | 2 |
| Total hand-written pages | 11 | 19 | **30** | 13 |
| Hand-written lines | 2,692 | 7,888 | **12,125** | 4,381 |
| Words | 15,454 | 42,764 | **72,805** | 25,851 |
| `learn.microsoft.com` links | 0 | 262 | **558** | 271 |
| `path:line` tree citations | 18 | 104 | **597** | 152 |
| Code fences | 102 | 129 | **319** | 146 |
| FAQ sections | 11/11 | 8/8 | **30/30** | 13/13 |
| FAQ questions | — | 32 | **334** | 94 |
| Compile-checked examples | 0 | **8 C files** | 0 | 0 |
| `npm run build` | passes | **FAILS** | **passes** | passes |

Line and word counts are the files the PR actually adds or rewrites, not the whole tree. #48's row counts
its 8 new `win32-api/` pages plus the 11 unchanged baseline guides (2,692 + 5,196 = 7,888 lines); its
"code fences" figure is the 8 new pages only, since it adds no fences to the guides.

---

## 2. Coverage — what surface each PR actually reaches

This is the axis with the widest spread, and the one that decided the merge.

**#49 covers the most, and covers it twice over.** It does not just add reference pages; it rewrites
the eleven existing guide pages (+1,350 lines) and then adds 19 reference pages organised by export
DLL: `windows-api`, `kernel32-{file,process,memory,library}-api`, `user32`, `gdi32`, `advapi32`,
`ntdll`, `native-api`, plus the cross-cutting `structures`, `status-codes`, `driver-model`,
`pe-loader`, `registry`, `com-rpc`, `winsock-api`, `kernel-objects` and a `glossary`. That is both
entry points to the same material — "I want to know where `CreateFileW` lives" (DLL page) and "I want
to know how the object manager works" (topic page) — which is what a source map needs.

By contrast, **#50** expands the eleven guides but adds only two pages. Its per-page additions are
also much thinner almost everywhere:

| Guide page | #49 adds | #50 adds |
| --- | --- | --- |
| `interfaces.md` | +333 | +82 |
| `testing-debugging.md` | +204 | +58 |
| `security-directory.md` | +193 | +134 |
| `io-storage.md` | +190 | +178 |
| `networking.md` | +186 | +105 |
| `win32-shell.md` | +258 | +180 |
| `function-index.md` | +143 | +35 |
| `build.md` | +131 | +81 |
| `overview.md` | +107 | +2 |
| `architecture.md` | +87 | +82 |
| `kernel.md` | +125 | **+333** |

`kernel.md` is the one page where #50 is clearly deeper, and that work is genuinely good — it is the
main thing I would want ported back.

**#48 covers a different axis entirely, and it is the axis nothing else covers.** Its eight
`win32-api/` pages document 107 functions (counted: 107 per-function `##` sections, and each page's
own "This page covers **N** functions" header sums to the same 107) with a per-function block: official signature, header and
library table, minimum-client/server, character-set variants, the prototype quoted from the
mingw-w64 SDK headers, documented return-value semantics, and a tested example. That is
`learn.microsoft.com`'s structure, reproduced correctly, with a "In this tree" row added. It is the
only PR where every function on the page has working sample code. But it explicitly does **not**
expand the eleven guides ("This PR does not yet expand the 11 guide pages"), so on its own it leaves
the site half-rewritten: 19 pages where 11 are baseline prose and 8 are API reference, with no
bridge between them.

**Judgement:** coverage is not close. #49 adds more pages, more lines, more citations, and — the part
that is hard to fake — more *kinds* of page. #48's 107 functions are excellent but sit inside an
otherwise unchanged site; #50's scope is a subset of #49's.

---

## 3. Completeness — does each PR finish what it starts, and is it honest about the edges?

**#49 finishes, and documents its holes.** The self-reported gap handling is unusually specific for a
docs PR: three components with no usable source in the tree are written up as gaps rather than
silently omitted — `lsass.exe` (only `ds/published/lsa/*.idl` survives), `volmgr` (headers only, no
driver source), and `mswsock`/`EtwRegister`. A docs PR that says "this does not exist here" is worth
more than one that quietly skips it, because the omission is what a reader cannot detect.

**#48 is honest about being unfinished, and that honesty is correct.** Its body states plainly that
the guide pages are not expanded and that the build was not verified. That is exactly the right thing
to write — but it also means the PR cannot be merged as the site's documentation; it is one half of
a documentation update.

**#50 has the weakest verification-to-claim ratio.** Its body claims the full pipeline works end to
end (121,045 files → 1,097,134 definitions → 3,665 pages, 0 failures) and that `npm run build`
succeeds, but the build success came from a reduced-reference dev-mode build, and the full-generation
claim is about the generator, not about the site rendering. Its two new pages are also the least
integrated: `native-api.md` duplicates #49's, and `win32-api-map.md` is a curated lookup table whose
rows are asserted `rg`-verified but which overlaps #49's `windows-api.md` and `kernel32-*` tables
without superseding them.

---

## 4. Clarity — is a page usable by someone who is not the author?

**#48 is the clearest per page, and it is not especially close.** The fixed per-function skeleton
(purpose prose → attribute table → prototype → return value → tested example, all with identical
heading levels) means a reader can jump to any function and know where to look. Its use of
`## CreateFileW` as the section heading rather than `###` also makes each function its own sidebar
entry, which is good navigation. The weakness is depth of tree analysis: "In this tree" is one table
row, where #49 gives the hop-by-hop chain.

**#49 is clear but dense, and it is consistently dense.** Every reference page carries a function
table whose columns are name / header / implementation (`path:line`) / Learn link, then worked
examples, then the internal `Nt*`/`Zw*` path, then a FAQ. The uniformity is the clarity feature: once
you have read one page you can navigate all nineteen. 334 FAQ questions across 30 pages (average
11 per page, minimum 6) is a real readability investment — the FAQs answer the "yes but where does it
*actually* happen" questions inline instead of pushing them to a footnote.

**#50 is clear in places and padded in others.** Its `## References` sections are useful and cheap.
But its guide additions sometimes restate the baseline instead of extending it — `overview.md` gains
2 lines, and several sections are new-pipeline notes (`makefile.def` header quote, the `build.exe`
in-tree manual) that read like research notes rather than explanation.

---

## 5. What I actually verified myself

I did not take the PR bodies at face value. Run in this sandbox, on each PR's own tree, with
reduced-prefix generation (42 reference pages — the documented dev mode, because the full 3,629-page
set OOM-kills a 4 GB box for all three PRs including baseline):

| Check | #48 | #49 | #50 |
| --- | --- | --- | --- |
| `npm run build` (cold, cache cleared) | **fails** | **passes** | **passes** |
| `python3 -m unittest discover -s documentation/tests` | passes | passes | passes |
| `path:line` citations resolving to a real file | 104/104 | 395/399 | 140/148 |
| Cited lines near the cited symbol | — | 248 ok / 7 drift | 27 ok / 2 drift |
| Internal links resolving to a real page | — | 105/105 | 71/71 |
| Anchor fragments resolving | — | 105/105 | 71/71 |
| Relative `.md` links (Docusaurus treats these as doc refs) | **3 broken** | 0 | 0 |

The #48 failure is not cosmetic and it is not the OOM the author reported:

```
Error: MDX compilation failed for file "win32-api/files.md"
Cause: Docs markdown link couldn't be resolved: (nf-fileapi-writefileex.md)
     ... win32-api/memory.md    → nf-memoryapi-virtualqueryex.md
     ... win32-api/runtime.md   → ../errhandlingapi/nf-errhandlingapi-getlasterror.md
[ERROR] Client bundle compiled with errors therefore further build is impossible.
```

Docusaurus resolves any link ending in `.md` as a document reference, so these three have to be
absolute `https://learn.microsoft.com/...` URLs or plain code spans. It is a three-character-per-link
fix — but it means the PR as pushed could not ship the site, and the PR body's "MDX compiles" claim
does not hold for the tree as committed. I confirmed this twice, including in a fresh sparse clone
with the webpack cache deleted, so it is not stale-cache noise.

The citation "misses" above are mostly shorthand rather than errors — e.g. #49 writes
`kernel/ntstubs.c:6029` in a context where the full path `windows/core/ntuser/kernel/ntstubs.c` is
established a few lines earlier. The genuine drift is small and I would treat it as normal rot risk,
not a defect: `CreateFileW` cited at `base/ntos/io/iomgr/create.c:37` lands on the `#pragma
alloc_text(PAGE, NtCreateFile)` block rather than the function header, i.e. off by a few lines within
the right function.

**One thing that separates #48 from the other two, in the opposite direction:** #48 pins its
"in this tree" links to the full base commit SHA (`blob/b5251b626.../path#L5369`, 105 of them), so
the links keep pointing at the exact lines that were verified even as `main` moves. #49 uses
`blob/main/` (23 of its links carry a line number) and #50 uses `blob/main/` throughout (none carry a
line number). All three rot eventually; #48's rot the slowest, #50's the least severely, because a
link without a line number can never point at the wrong line.

---

## 6. Why #49

Ranked on the three axes:

| | Coverage | Completeness | Clarity | Build |
| --- | --- | --- | --- | --- |
| **#49** | 1st | 1st | 2nd | passes |
| #48 | 3rd (narrow, but unique) | 3rd (declared incomplete) | **1st** | fails |
| #50 | 2nd | 2nd | 3rd | passes |

#49 wins on two of three axes and passes the build, and its weakest axis is a difference of style
(#48's per-function skeleton is better than #49's function table) rather than a difference of
substance. It also removes the largest future maintenance burden: it adds no example code, so there
is nothing that has to keep compiling against an SDK.

The cost of the decision is real and worth stating plainly: **#49 has no tested code.** Every example
in its 19 reference pages is illustrative, never compiled. #48 is the only PR that proves its
examples build (`zig cc` for x86_64 and aarch64 under `-Wall -Wextra -Werror`), and that property is
lost by closing it. It is worth re-landing.

---

## 7. Follow-ups this review recommends

1. **Re-land #48's examples** as their own PR: `documentation/examples/win32/` (8 C files) plus the
   eight `win32-api/` pages, with the three `.md` links rewritten as absolute Learn URLs. This is the
   highest-value open item — it turns illustrative snippets into verified ones.
2. **Port #50's `kernel.md`** section (+333 lines, the deepest kernel page of the three) onto the
   merged tree.
3. **Fix `documentation/README.md`** — done in #51. After #49 the site shipped 30 pages while the
   README still said "Eleven hand-written pages … positions 1–11".
4. **Pin citations consistently.** #49's `blob/main/...#L` links will drift; consider #48's
   commit-SHA convention for line-level citations, or drop the line number where the path alone
   identifies the routine.
5. **Decide the FAQ convention.** At 334 questions the FAQ is now a load-bearing part of the site,
   but the README still describes it as a per-page footnote rule. Worth a paragraph on how many
   questions is enough.
