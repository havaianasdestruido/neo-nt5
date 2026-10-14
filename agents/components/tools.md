# `tools/` — build-environment scripts and postbuild orchestration

`tools/` is the checked-in build/tooling **environment**, not the same thing as [`sdktools/`](sdktools.md), which contains many tool *sources*. Its root contains Razzle, NMAKE rules, publication/version helpers, signing/international build utilities and postbuild entry points. Many files assume historical Windows build-lab tools and paths. [All nested tools directories](../catalog/tools.md) are indexed (most have no `sources`).

| Path (relative to `tools/`) | Contents |
| --- | --- |
| [`postbuildscripts`](../../tools/postbuildscripts) | Data-driven staging, layout, catalogs/signing, compression, symbols, checks and image-generation scripts; [`pbuild.dat`](../../tools/postbuildscripts/pbuild.dat) controls scheduling. |
| [`x86`](../../tools/x86) · [`win64`](../../tools/win64) · [`ia64`](../../tools/ia64) | Architecture/host tool payloads and language/tool runtime directories. Existence of a folder is not proof every compiler/tool is available. |
| [`tools16`](../../tools/tools16) | Legacy 16-bit tools/assets. |
| [`wppconfig`](../../tools/wppconfig) | WPP software tracing configuration. |
| [`sp`](../../tools/sp) · [`qfelists`](../../tools/qfelists) | Service-pack/hotfix-related data and scripts. |

## Entry points and responsibilities

* [`razzle.cmd`](../../tools/razzle.cmd) chooses architecture/flavor/paths and prepares a clean Windows command environment. [`ntenv.cmd`](../../tools/ntenv.cmd) and architecture `*mk.inc` files contribute tool settings.
* [`makefile.def`](../../tools/makefile.def), [`makefile.plt`](../../tools/makefile.plt), [`projects.inc`](../../tools/projects.inc) and project `project.mk`/`makefile.inc` implement the shared NMAKE conventions used by leaf `sources`. Tool *source* for `build.exe` is at [`sdktools/build`](../../sdktools/build).
* [`postbuild.cmd`](../../tools/postbuild.cmd) drives the scheduler and [`postbuildscripts/pbuild.dat`](../../tools/postbuildscripts/pbuild.dat) lists ordered jobs/barriers. `cdimage.cmd` is one job, not the absent `tools\oscdimg.cmd` mentioned in the repository README.
* Version/publication helpers (e.g. [`updtnum.pl`](../../tools/updtnum.pl), [`genbldno.pl`](../../tools/genbldno.pl), [`publish.pl`](../../tools/publish.pl)) tie into [`makefil0`](../../makefil0), headers and staged binaries. Do not run cleanup/scorch/revert/postbuild scripts on a valuable workspace without understanding their side effects.

Some legacy files here are certificates, signing or build-lab material. Do not copy their contents into `agents/`, logs or chat. The [build guide](../build-and-release.md#checkout-limitations) lists concrete missing helpers and explains why this folder does not guarantee a reproducible product build.
