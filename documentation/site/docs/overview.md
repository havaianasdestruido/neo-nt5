---
title: Project overview
slug: /
sidebar_position: 1
description: What this source checkout contains, how the documentation site is assembled, and which page to read first.
---

NEONT 5 is a large Windows NT-family source tree. This site is its documentation: a set of
hand-written guides that explain how the tree is organised and built, plus a **generated function
index** that inventories every C, C++ and Python definition the generator can parse.

Nothing on this site certifies that the checkout builds, installs or boots. It documents what is
checked in and where the boundaries are.

## What is in the checkout

The numbers below come from the tracked files in this repository, not from a released product:

| Measurement | Value | How it was measured |
| --- | --- | --- |
| Tracked files | 277,956 | `git ls-files \| wc -l` |
| Tracked directories | 24,666 across 21 root trees | [`agents/catalog/README.md`](https://github.com/havaianasdestruido/neo-nt5/blob/main/agents/catalog/README.md) |
| Files the index generator can parse (`.c .h .cpp .cxx .cc .hpp .hxx .py`) | 120,323 | `git ls-files` filtered by extension |
| `.idl` interface definitions | 1,658 | `git ls-files \| grep -c '\.idl$'` |
| `.mof` management schemas | 540 | `git ls-files \| grep -c '\.mof$'` |
| `.inf` installation files | 1,318 | `git ls-files \| grep -c '\.inf$'` |
| Root build trees named by the root `dirs` | 18 of 21 | see [Build, package and release](/build) |

The declared product version in this snapshot is **5.1.2600.1106**, from
[`public/sdk/inc/ntverp.h`](https://github.com/havaianasdestruido/neo-nt5/blob/main/public/sdk/inc/ntverp.h):

```c
#define VER_PRODUCTBUILD            /* NEONT */   2600
#define VER_PRODUCTBUILD_QFE        1106
...
#define VER_PRODUCTMAJORVERSION     5
#define VER_PRODUCTMINORVERSION     1
#define VER_PRODUCTVERSION_W        (0x0501)
```

That is a *declaration in a header*. It does not make every directory in the tree a Windows XP
component, and the repository README's broader "Windows 2000 through Windows Server 2003" framing
does not either — several trees carry both XP-era and Server-era branches side by side.

## How this site is assembled

Two different kinds of page live here, and they are produced by different mechanisms:

| Kind | Where it comes from | Edited by hand? |
| --- | --- | --- |
| **Guide pages** (this page and the ones linked below) | Markdown checked into `documentation/site/docs/` | Yes |
| **Function index pages** under `reference/` | `documentation/scripts/generate.py`, run by the Pages workflow | No — they are regenerated on every publish and old generated files are deleted first |

The generated pages are *not committed*. `.gitignore` excludes `site/static/reference/`, so a local
`git status` stays clean after you run the generator. See
[Using the generated function index](/function-index) for exactly what those pages do and do not
tell you.

## Which page to read first

| You want to… | Read |
| --- | --- |
| Understand boot, kernel/user mode and how the trees relate | [Architecture and runtime boundaries](/architecture) |
| Rebuild, stage or package the tree | [Build, package and release](/build) |
| Change kernel, executive or system-service code | [Kernel and executive](/kernel) |
| Change file systems, storage drivers or Plug and Play | [I/O, file systems and storage](/io-storage) |
| Change NDIS, TCP/IP, Winsock or a network service | [Networking stack](/networking) |
| Change Win32, windowing, graphics or the shell | [Win32, windowing and the shell](/win32-shell) |
| Change access checks, authentication or Active Directory | [Security and directory services](/security-directory) |
| Change a header, IDL, import library or published contract | [Interfaces and cross-project contracts](/interfaces) |
| Find or run a test, use the verifier or the debugger extensions | [Tests, diagnostics and debugging](/testing-debugging) |
| Read the auto-generated inventory | [Using the generated function index](/function-index) |

The repository also keeps a parallel set of Markdown guides in
[`agents/`](https://github.com/havaianasdestruido/neo-nt5/tree/main/agents) — an architecture map, a
generated directory catalog, per-component guides and a task plan. Those files are the working notes
for people and coding agents changing source; this site is the published reference.

## The source-only change policy

[`AGENTS.md`](https://github.com/havaianasdestruido/neo-nt5/blob/main/AGENTS.md) at the repository
root is mandatory for anyone changing this tree, and it constrains what this documentation may claim:

> **Never edit `.htm` / `.html` files (any letter case) to make a visual change.**

Behaviour, layout and text live in compiled source — C, C++, headers, assembly and batch files.
HTML in this tree is shipped content, generated output or legacy documentation. The in-scope file
types for a change are `*.c`, `*.cpp`, `*.cxx`, `*.h`, `*.hpp`, `*.hxx`, `*.inc`, `*.asm` and
`*.bat` / `*.cmd`, with `*.rc`, `*.idl` and build definitions (`sources`, `dirs`, `makefile*`,
`*.mk`) allowed only where a source change genuinely needs them.

Two consequences worth repeating here:

1. A problem that "only reproduces in the HTML" is still fixed in the code that produces or consumes
   that page.
2. This site documents source behaviour. When it describes a function, it links to the definition
   rather than restating an inferred meaning.

## The full wiki map

The site now has two halves: **guides** that explain the tree, and **API reference** pages that
document the callable surface with signatures, implementation points and official documentation
links. Use this table to jump directly to a topic.

### Guides

| Page | Subject |
| --- | --- |
| [Project overview](/) | This page: what the checkout contains and how the site is assembled |
| [Architecture and runtime boundaries](/architecture) | Boot chain, kernel/user boundary, Win32k, build variants |
| [Build, package and release](/build) | Razzle, `dirs`/`sources`/`makefile`, postbuild, SKUs, checkout gaps |
| [Kernel and executive](/kernel) | The `base/ntos` managers, system services, object and handle lifetimes |
| [I/O, file systems and storage](/io-storage) | IRP lifecycle, file systems, class/port drivers, Plug and Play |
| [Networking stack](/networking) | NDIS, TCP/IP, TDI, Winsock and AFD |
| [Win32, windowing and the shell](/win32-shell) | Where Win32 is implemented, the window server, the shell |
| [Security and directory services](/security-directory) | Access checks, tokens, auditing, LSA, Active Directory layers |
| [Interfaces and cross-project contracts](/interfaces) | Public/published/private headers, IDL/RPC, MOF, INFs |
| [Tests, diagnostics and debugging](/testing-debugging) | Test conventions, Driver Verifier, `gflags`, `kdext` extensions |
| [Using the generated function index](/function-index) | How the generated index works and how to read it |
| [Glossary](/glossary) | Every term and abbreviation used on the wiki |

### Windows API reference

| Page | API surface |
| --- | --- |
| [The Windows API surface](/windows-api) | DLL/header map, calling conventions, ANSI/Unicode, error model, tracing a call |
| [File, directory, pipe and mailslot API](/kernel32-file-api) | `CreateFile`, `ReadFile`, `WriteFile`, enumeration, mappings, pipes, mailslots |
| [Process, thread and synchronization API](/kernel32-process-api) | `CreateProcess`, `CreateThread`, TLS, waits, critical sections, events, mutexes, jobs |
| [Memory management API](/kernel32-memory-api) | `VirtualAlloc`, heaps, page protection, cross-process memory |
| [Library, loader, resource and diagnostics API](/kernel32-library-api) | `LoadLibrary`, `GetProcAddress`, resources, ToolHelp, `FormatMessage`, console gap |
| [USER — windows, messages and input](/user32-api) | Window classes, message loop, dialogs, timers, hooks, clipboard |
| [GDI — device contexts, drawing and bitmaps](/gdi32-api) | DCs, pens/brushes, bitmaps/DIBs, fonts/text, palettes, regions |
| [ADVAPI32 — registry, services, event log, security and crypto](/advapi32-api) | `Reg*`, SCM, event log, tokens/privileges, CryptoAPI |
| [NTDLL — the NT runtime library](/ntdll-api) | `Rtl*`, `Ldr*`, `Csr*`, activation contexts, VEH, error translation |
| [NT native API — Nt*/Zw* system services](/native-api) | Syscall path, `services.tab`, core services by category, `Nt` vs `Zw` |
| [Core structures and constants](/structures) | `UNICODE_STRING`, `OBJECT_ATTRIBUTES`, `IO_STATUS_BLOCK`, `OVERLAPPED`, constants |
| [Status and error codes](/status-codes) | `NTSTATUS`, Win32 errors, `HRESULT`, conversion functions, bugcheck codes |
| [Kernel driver model — WDM, IRPs and DDI](/driver-model) | `DriverEntry`, dispatch tables, IRP stack, PnP/power, DPC/ISR/DMA, NDIS |
| [PE format and the loader](/pe-loader) | Headers, sections, imports/exports, relocations, TLS, `Ldr*` |
| [Registry — structure, API and implementation](/registry) | Hives, cells, native services, `Reg*`, symbolic links, redirection |
| [COM, RPC and OLE](/com-rpc) | `IUnknown`, class factories, marshalling, MIDL/IDL, NDR, structured storage |
| [Winsock API — sockets, providers and AFD](/winsock-api) | The Winsock 2 API, SPI, AFD, `select`/overlapped models |
| [Kernel objects and handles](/kernel-objects) | Object types, handle tables, reference counting, the object directory |

### Reference generated from the tree

| Page | Subject |
| --- | --- |
| <a href="reference/">Generated function index</a> | Every C/C++/Python definition, its signature and its test links |
| <a href="reference/coverage.html">Extraction coverage</a> | Files that could not be parsed and why |

## How to use the API reference

Each API page follows the same shape:

1. **A model** — the layering, so you know which DLL owns which call.
2. **Function tables** — function, header, implementation file and line in this checkout, and a
   link to the official Microsoft documentation.
3. **Worked examples** — compilable C against the Windows SDK.
4. **Internal path** — which `Nt*` service the call reaches, and where that service lives.
5. **FAQ** — the mistakes that are actually made.

Two conventions are used throughout:

- **"Implementation"** means the file and line in *this checkout*, verified with `rg` against the
  tree. It is a pointer, not a claim about every Windows release.
- **"Documentation"** links to Microsoft Learn, which is the authority on parameter semantics,
  minimum supported Windows version, header and import library.

When the two disagree, the tree wins for *this checkout* and the documentation wins for the
*published contract*. Say which one you are reasoning about.

## Frequently asked questions

### Q: Is this a working operating system I can build and install?

Not as verified here. The root `dirs` names trees that are absent and omits trees that are present,
and two helper scripts named by the README are not checked in:

```bat
rem README.md asks for both of these:
C:\NT\tools\missing.cmd      REM ABSENT from this checkout
C:\NT\tools\oscdimg.cmd      REM ABSENT from this checkout

rem what IS present:
C:\NT\tools\razzle.cmd       PRESENT
C:\NT\tools\postbuild.cmd    PRESENT
```

No full build, installation or boot test has been run for this documentation, and the workspace is
Linux — this tree targets a Windows `cmd`/NMAKE/`build.exe` toolchain. See
[Checkout limitations](/build#checkout-limitations) for the full list.

### Q: The root `dirs` and the repository contents disagree. Which one is right?

Each answers a different question. The root
[`dirs`](https://github.com/havaianasdestruido/neo-nt5/blob/main/dirs) is the *build traversal*
`build.exe` would follow:

```bat
DIRS=           \
    Published   \
    QFE         \
    Base        \
    Windows     \
    Admin       \
    DS          \
    Shell       \
    InetCore    \
    COM         \
    Drivers     \
    Net         \
    SdkTools    \
        \
    MultiMedia  \
    InetSrv     \
    PrintScan   \
    EndUser     \
    loc         \
    MergedComponents
```

It names `QFE` (no root `QFE/` directory exists; there *is* a `base/qfe`) and it does **not** name
the present `termsrv/`, `public/`, `tools/`, `developer/` or `documentation/` trees. Treat it as the
authority for its own traversal, not as an inventory of the checkout.

### Q: How do I find the source behind a symptom I can see in the product?

Do not assume the visible executable owns the behaviour — MMC snap-ins manage LSA, Explorer is not
the file system, the IIS UI is not the HTTP service. Pick a layer instead:

```text
symptom in the UI      -> /win32-shell        (windows/core, shell/, base/win32)
symptom in a file op   -> /io-storage         (base/ntos/io, base/fs, drivers/storage)
symptom on the network -> /networking         (net/ndis, net/tcpip, net/sockets)
access denied / token  -> /security-directory (base/ntos/se, ds/security)
hang, bugcheck, boot   -> /kernel             (base/ntos, base/hals, base/boot)
```

Then search a *likely subtree* rather than the whole tree:

```bash
rg -n 'NtfsFsdCreate' base/fs/ntfs
rg -n 'TARGETNAME\s*=\s*disk' --glob sources drivers
```

### Q: Why does this site link to `github.com` for source files instead of showing them inline?

So a claim stays checkable at a pinned revision. The generated index links each definition to
`https://github.com/havaianasdestruido/neo-nt5/blob/<revision>/<path>#L<line>`, where `<revision>` is
the commit the site was built from (`GITHUB_SHA` in the Actions workflow). Hand-written pages link
to `main`. Snippets on the guide pages are short quotations meant for orientation; the linked file
is always the authority.

### Q: How fresh is this site?

The Pages workflow
[`.github/workflows/documentation.yml`](https://github.com/havaianasdestruido/neo-nt5/blob/main/.github/workflows/documentation.yml)
runs on pushes to `main` and on manual dispatch. It installs the Python requirements, runs
`python -m unittest discover -s documentation/tests`, regenerates the index with
`python documentation/scripts/generate.py`, then `npm ci && npm run build` and publishes
`documentation/site/build` as a Pages artifact. A push to a feature branch does not update the live
site.

### Q: Can I run the site locally?

Yes, with Python 3.11+ and Node 20+:

```sh
python3 -m pip install -r documentation/requirements.txt
python3 -m unittest discover -s documentation/tests
python3 documentation/scripts/generate.py
cd documentation/site && npm ci && npm run build
```

The generated pages are static HTML copied verbatim into the build, so the Docusaurus build does
not process them and does not fail if they are missing — the navbar and guide links to them are
plain URLs. Run the generator before `npm run build` anyway, so the published site actually
contains the index; a build without it ships a site whose **Function index** link leads nowhere.

### Q: Which API page should I read for a specific function?

Start from the header that declares it. `fileapi.h` functions are on
[File, directory, pipe and mailslot API](/kernel32-file-api); `processthreadsapi.h` and `synchapi.h`
on [Process, thread and synchronization API](/kernel32-process-api); `memoryapi.h` on
[Memory management API](/kernel32-memory-api); `libloaderapi.h` on
[Library, loader, resource and diagnostics API](/kernel32-library-api); `winuser.h` on
[USER](/user32-api); `wingdi.h` on [GDI](/gdi32-api); `winreg.h`, `winsvc.h`, `winbase.h` (event
log) and `wincrypt.h` on [ADVAPI32](/advapi32-api); `winternl.h` on
[NTDLL](/ntdll-api) and [Native API](/native-api).

### Q: Do the API pages cover every function in the tree?

No. They cover the documented Windows API surface that this checkout implements, grouped by header
family. The **generated function index** covers every C/C++/Python definition the parser can find,
including internal helpers that have no public documentation. The two are complementary: the API
pages explain the contract, the index locates the code.

### Q: Why do the API pages link to Microsoft Learn instead of copying the documentation?

Because the official pages are the authority on parameter semantics, supported versions and
header/import-library requirements, and they are updated when the contract changes. This wiki
adds what the official docs do not have: the implementation path in this checkout, the internal
`Nt*` service, and the specific mistakes the source makes visible. Quoting short signatures is
fair; duplicating whole articles would go stale and misattribute the text.

### Q: Is the console API documented here?

Partly. The exports are listed in `base/win32/client/kernel32.src`, but the implementations are not
present in `base/win32/client` in this checkout. The
[Library, loader, resource and diagnostics API](/kernel32-library-api#console) page states that
explicitly rather than inventing an implementation path.
