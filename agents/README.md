# Agent's guide to this NEONT source tree

This folder is a **map of the checked-in NEONT 5.x codebase** for people and coding agents. It is not an implementation of autonomous agents, a replacement for the original build tools, or a claim that this checkout is a complete, buildable Windows distribution. Start with the [architecture](architecture.md), then the [build/release path](build-and-release.md); use the [component guides](#component-guides) to find an owner, and the [complete directory catalog](catalog/README.md) to locate a particular nested component.

## What “complete” means here

* Every **tracked directory outside `agents/`** is listed in the generated [catalog](catalog/README.md), with direct file count, links to any local `dirs`/`sources`/`makefile`, and literal target declarations where available. It includes data, tests, architecture/locale variants, and directories the root build does **not** visit. Regenerate it after source changes with `python3 agents/generate_catalog.py --write`.
* Each top-level tree has a [guide](#component-guides) describing its immediate subtrees and important deeper boundaries. Cross-cutting guides explain how pieces cooperate. This is a **directory/build-target inventory and architectural explanation**, not a 277,000-file, line-by-line commentary; names and `sources` declarations alone cannot establish runtime behavior.
* A `dirs` entry is not proof a folder exists, nor a `sources` entry proof its target ships. Some references and scripts are missing from this checkout. See [known limits](build-and-release.md#checkout-limitations) before trying to build.

## System in one view

```text
firmware / boot sector -> base/boot -> base/ntos + base/hals
                                      |          |
                              drivers, file systems, NDIS/TCP/IP
                                      |
                            ntdll -> SMSS/CSRSS, Win32, services
                                      |
               Windows UI / shell / admin / COM / directory services
                                      |
                   IIS, IE, media, print/scan, terminal services

source + public interfaces -> dirs/sources + Razzle/build -> binaries
                                    -> postbuild staging -> SKU/media
```

This is a **navigation model**, not the precise boot order or a dependency graph. The source is organized by product/project as well as by runtime layer: for example Win32 crosses `base/`, `windows/`, `shell/`, and `ds/`; networking crosses `net/`, `drivers/`, and `base/fs/`.

## Read by task

| If you are changing… | Start here | Then inspect… |
| --- | --- | --- |
| Boot, kernel, processes, memory, I/O | [architecture](architecture.md#execution-and-boot) · [base](components/base.md) | `base/boot`, `base/ntos`, `base/hals`, `base/subsys` |
| Hardware, file systems, installation | [drivers](components/drivers.md) · [base](components/base.md) | `drivers/storage`, `base/fs`, `base/pnp`, `base/ntsetup` |
| Win32 API, UI, Explorer | [windows](components/windows.md) · [shell](components/shell.md) | `base/win32`, `windows/core`, `shell/explorer` |
| Network protocol or Internet service | [net](components/net.md) · [inetsrv](components/inetsrv.md) | `net/ndis`, `net/tcpip`, `inetsrv/iis` |
| Authentication, AD, registry/security policy | [ds](components/ds.md) · [admin](components/admin.md) | `ds/security`, `ds/ds`, `base/ntos/se` |
| RPC/COM and shared ABI | [com](components/com.md) · [interfaces](interfaces.md) | `com/rpc`, `com/ole32`, `public/`, `published/` |
| Print, fax, media, remote sessions | [printscan](components/printscan.md) · [multimedia](components/multimedia.md) · [termsrv](components/termsrv.md) | `printscan/print`, `multimedia/dshow`, `termsrv/drivers` |
| Rebuild, package, or debug | [build/release](build-and-release.md) · [working guide](working-guide.md) | `tools/razzle.cmd`, `dirs`, `tools/postbuildscripts/pbuild.dat` |

## Guides

* [Architecture and runtime boundaries](architecture.md) — boot, kernel/user mode, system services, sessions and presentation.
* [End-to-end traces](system-flows.md) — boot, Win32 call, file access, packet, authentication, web request, print job.
* [Build, postbuild, and checkout limits](build-and-release.md) — exact build files, architectures, conditional directories, packaging, missing pieces.
* [Interfaces and shared contracts](interfaces.md) — headers, IDL/RPC, driver APIs, publication, installation/resource contracts.
* [Working and validation guide](working-guide.md) — where to edit, how to trace dependencies, safe checks, test strategy.
* [Agent specializations and handoffs](roles.md) — suggested review roles spanning multiple project trees.
* [Glossary](glossary.md) — abbreviations used throughout the tree.
* [Tracked-directory catalog](catalog/README.md) — all nested directories, generated from tracked paths; **inventory, not an interpreted build graph**.

## Component guides

| Core / platform | Services / applications | Build / interfaces |
| --- | --- | --- |
| [base](components/base.md) | [admin](components/admin.md) | [developer](components/developer.md) |
| [drivers](components/drivers.md) | [ds](components/ds.md) | [loc](components/loc.md) |
| [windows](components/windows.md) | [enduser](components/enduser.md) | [public](components/public.md) |
| [net](components/net.md) | [inetcore](components/inetcore.md) | [published](components/published.md) |
| [com](components/com.md) | [inetsrv](components/inetsrv.md) | [sdktools](components/sdktools.md) |
| [mergedcomponents](components/mergedcomponents.md) | [multimedia](components/multimedia.md) | [tools](components/tools.md) |
| [printscan](components/printscan.md) | [shell](components/shell.md) | |
| [termsrv](components/termsrv.md) | | |

The guide names correspond to **all 21 top-level tracked trees**. Some areas (notably `termsrv/`, `public/`, and `tools/`) are present but are not named in the root `dirs`; treat the root build file as the authority for *its* traversal, not as an inventory of the checkout. The remaining root files are the historical [README](../README.md), build traversal [`dirs`](../dirs), NMAKE targets [`makefil0`](../makefil0), and [`empty`](../empty) (a small placeholder file, not an OS component).

## Scope and provenance

Paths and claims in these guides refer to the files in this repository, not to every released NEONT 5.x SKU. This checkout mixes XP/Server-related trees and contains version- and architecture-specific branches. For example, [`public/sdk/inc/ntverp.h`](../public/sdk/inc/ntverp.h) declares a 5.1/2600 version in this snapshot; the repository README's broader product description does not make every directory a Server 2003 component. The [repository README](../README.md) includes historic build instructions, but some named helpers are absent here. Do not publish embedded product keys, private certificates, or binaries as part of an agent's report. Respect the rights and licenses applicable to this proprietary source tree.
