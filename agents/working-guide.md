# Working guide for a coding agent

This repository is a historical Windows source tree with many unrelated targets. Keep changes **narrow and verifiable**. The [component guides](README.md#component-guides) identify an area; the [catalog](catalog/README.md) finds nested build definitions; [interfaces](interfaces.md) explains cross-project impact; [build/release](build-and-release.md) describes what can and cannot be asserted about this checkout.

## Locate the real owner

1. Name the symptom or API and choose an [end-to-end trace](system-flows.md). Do not assume the visible executable owns the underlying behavior (e.g. MMC vs LSA, Explorer vs filesystem, IIS UI vs HTTP service).
2. Search **a likely subtree**, not 8 GB of source by default: `rg -n 'SymbolName' base/ntos`, `rg -n 'TARGETNAME\s*=\s*foo' --glob sources net`, or `rg --files ds/security | rg '/(dirs|sources|.*\.idl)$'`. The generated [catalog](catalog/README.md) is faster for path/target lookup.
3. Open the closest leaf `sources`, then trace ancestor `dirs` back toward root. Read `makefile.inc`, `project.mk`, `componentdef`, `idl`, INF/registration and `*/published` as appropriate. Check platform/locale/SKU guards. Remember a leaf can exist but not be selected.
4. Inspect direct callers and consumers (including remote, kernel/user or 32/64-bit sides) and identify a test in the same area. For cross-project interfaces, follow [the checklist](interfaces.md#review-checklist-for-interface-changes).

## Make the smallest coherent change

* Match the style, calling conventions, resource ownership and error handling in the surrounding subsystem. Existing `makefile` files often just include the shared rule; add sources in `sources` and dependencies in the appropriate build definitions, **not** in an indirection-only makefile.
* Treat public/IDL/driver structures, registry/INF/MOF and on-disk formats as compatibility surfaces. Do not fix a client by silently changing only the server contract, or change an interface without tracing consumers.
* Preserve variants (`i386`, `amd64`, `ia64`, `wow6432`, `up`, `mp`, languages), while limiting changes to the architectures actually supported by the affected component. State explicitly which variants were **not** tested.
* Do not reproduce product keys, signing material, certificates or other secrets from the repository in documentation/logs; never submit binaries or artifacts from a local build unless specifically required and authorized. Observe proprietary-source rights and provenance concerns.
* Do not rewrite or normalize tens of thousands of unrelated files. Root `dirs` and postbuild scripts can affect huge portions of the tree; review such edits carefully. Scripts that clean/scorch/revert or package files may be destructive.

## Validate honestly

| Environment | Appropriate evidence |
| --- | --- |
| Any platform | `git diff --check`; review changed paths; compare build target/consumer declarations; run applicable text/static tests. For this documentation: `python3 agents/generate_catalog.py --check` and `python3 agents/verify.py`. |
| Windows with compatible NT build toolchain | Enter a fresh Razzle session, select explicit architecture/flavor, build the smallest reachable affected target and its dependents, inspect logs/symbols; run local unit/DRT tools if present. See [build/release](build-and-release.md). |
| Installed test system / VM | Exercise actual behavior, setup/service registration, negative/security paths, resource cleanup, locales and 32/64-bit variants; test image/media only if all prerequisites are available and permitted. |

There is **no** supported repo-wide `npm test` or Linux compile target. A grep result, successful catalog regeneration, or existence of a `sources` file is not a runtime test. Report tests run, environment, relevant failures and untested targets. Do not imply that this checkout produces installable images just because postbuild scripts exist.

## Maintain these docs

* When adding/removing tracked source directories or changing `sources` target names/types: `python3 agents/generate_catalog.py --write`, then `--check`.
* When changing a top-level area, update its [`components/*.md`](components/base.md) guide and relevant architecture/build/flow pages. Write exact paths; distinguish checked-in source from a historical dependency that is absent here.
* Run `python3 agents/verify.py` to check local Markdown links and that every tracked root has a component guide/catalog entry. `git diff --check` catches whitespace defects.
* Catalog entries are deliberately literal. Do not hand-edit generated pages; document semantic explanations in the component guides. If a declaration looks implausible, inspect conditional `sources` and NMAKE includes instead of inventing an output.
