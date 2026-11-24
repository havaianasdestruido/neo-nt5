---
title: Architecture and runtime boundaries
sidebar_position: 2
description: Boot chain, kernel and user mode, the executive managers, Win32k, one call through all layers, and how engineering trees map onto runtime layers.
---

The tree is partitioned mainly by **engineering project**, not by a strict layered package manager.
Kernel code lives in `base/ntos` and `windows/core`; networking lives in `net/`, `drivers/` and the
file-system redirectors; end-user interfaces depend on many of those projects at once. Use this page
to find the boundary a change crosses, then read the linked source.

## Runtime layers

```text
firmware / boot sector
  -> base/boot/bootcode + base/boot/bldr (+ detect, efi, startrom, setup)
  -> base/ntos + base/hals
       |-- ke  scheduler / low-level kernel     |-- ob  object namespace
       |-- ps  processes and threads            |-- mm  virtual memory
       |-- io  I/O manager + pnpmgr             |-- se  security reference monitor
       |-- config registry                      |-- cache / lpc / po / ex / rtl
  -> base/subsys/sm (SMSS) -> base/subsys/csr (CSRSS), services
  -> base/ntdll (native API) + base/win32 + windows/core (Win32)
  -> shell/explorer, ds/security logon, admin, inetsrv, printscan, termsrv
```

This is a **navigation model**, not the precise boot order and not a dependency graph. The source is
organised by project as well as by layer: Win32 crosses `base/`, `windows/`, `shell/` and `ds/`;
networking crosses `net/`, `drivers/` and `base/fs/`.

## One call through every layer

The fastest way to internalise the architecture is to follow a single documented API from the
application to the hardware. `CreateFileW`'s public contract:

```cpp
HANDLE CreateFileW(
  [in]           LPCWSTR               lpFileName,
  [in]           DWORD                 dwDesiredAccess,
  [in]           DWORD                 dwShareMode,
  [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  [in]           DWORD                 dwCreationDisposition,
  [in]           DWORD                 dwFlagsAndAttributes,
  [in, optional] HANDLE                hTemplateFile
);
```

— [CreateFileW function (fileapi.h), Microsoft Learn](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilew)

and the route it takes through this source tree:

```text
application
  -> kernel32   CreateFileW                 base/win32/client/fileopcr.c:5371
  -> ntdll      NtCreateFile stub           generated from base/ntos/ke/services.tab
  -> kernel     NtCreateFile                base/ntos/io/iomgr/create.c:37
  -> IRP_MJ_CREATE down the stack           base/ntos/io/iomgr/iosubs.c (IofCallDriver)
  -> filesystem NtfsFsdCreate               base/fs/ntfs/create.c:633
  -> volume     class/port drivers          drivers/storage/{classpnp,disk,scsiport,...}
  -> hardware   miniport / port driver
```

Each arrow is a project boundary with its own `dirs`/`sources` build node. The layers where the
open can *fail* are the bottom three; the layer that can make the call *wrong* (path translation,
disposition mapping, ANSI/Unicode) is the top one. Details and the `NtCreateFile` parameter tables
are in [I/O, file systems and storage](/io-storage); the system-call mechanics are in
[The native API](/native-api).

## Boot and kernel start-up

`base/boot/` contains `bootcode`, `bldr`, `detect`, `efi`, `startrom`, `tftplib`, `oschoice`,
`setup`, `kdcom` and `kd1394` — boot sectors, the loader, hardware detection, the EFI path, network
boot and the boot-time transports for the kernel debugger. Architecture-specific and language
folders underneath are variants, not separate operating systems. The loader sources themselves are
in `base/boot/bldr` (`advboot.c`, `bootstat.c`, `bldrint.h`, plus per-language build nodes such as
`daytona/`, `br/`, `chs/` that each produce an `osloader`).

The kernel is assembled from `base/ntos/`, whose own `dirs` fixes the traversal order of the
executive:

```bat
DIRS= \
    nls        \
    rtl        \
    config     \
    kd64       \
    ex         \
    ob         \
    se         \
    mm         \
    ke         \
    po         \
    ps         \
    arb        \
    io         \
    cache      \
    lpc        \
    dbgk       \
    raw        \
    fstub      \
    fsrtl      \
    vdm        \
    verifier   \
    wmi        \
    perf       \
    init       \
    ntsym
```

Entry points for kernel start-up are in
[`base/ntos/init/init.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/init/init.c),
and both are explicitly placed in the discardable `INIT` section:

```c
#pragma alloc_text(INIT,ExpInitializeExecutive)
#pragma alloc_text(INIT,Phase1Initialization)

VOID
ExpInitializeExecutive(
    IN ULONG Number,
    IN PLOADER_PARAMETER_BLOCK LoaderBlock
    );

VOID
Phase1Initialization(
    IN PVOID Context
    )
```

`ExpInitializeExecutive` is declared at line 48 and defined at line 611; `Phase1Initialization` is
at line 1394. The `Number` parameter is the processor number, and the `Number == 0` branch is where
the boot processor reads the loader block's setup flags — including whether this is a text-mode
setup or a remote-boot client.

### Four kernel binaries from one source set

`base/ntos/init` has `up/`, `mp/`, `pae/` and `paemp/` subdirectories. They are not four kernels;
they are four *link configurations* over the same source, distinguished by the target name and a
handful of macros. From
[`base/ntos/init/paemp/sources`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/init/paemp/sources):

```bat
NT_UP=0
!include $(PROJECT_ROOT)\ntos\ntoskrnl.inc
!undef NTTEST
NTTEST=ntkrpamp
TARGET1=paemp
TARGET2=mp

!include ..\up\sources.cmn

C_DEFINES=$(C_DEFINES) /D_X86PAE_
LINKER_FLAGS=/LARGEADDRESSAWARE
```

The same directory holds the checked-in linker response files `ntoskrnl.x86`, `ntkrnlmp.x86` and
their `.alp` / `.mip` counterparts. `up/sources` is a three-line file whose only real work is
`!include sources.cmn`. When you change shared kernel code, all four configurations compile it;
when you change an `mp/` or `pae/` fragment, only some do.

## The user/kernel boundary

`base/ntdll` exposes the native user-mode API and contains the architecture-specific syscall stubs
(`i386/`, `amd64/`, `ia64/`, `alpha/`, `axp64/`, plus `wow6432/`). System services themselves are
implemented in the managers — for example `NtCreateFile` lives in the I/O manager, not in ntdll:

```c
// base/ntos/io/iomgr/create.c:37
#pragma alloc_text(PAGE, NtCreateFile)

NTSTATUS
NtCreateFile(
    OUT PHANDLE FileHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes,
    OUT PIO_STATUS_BLOCK IoStatusBlock,
    ...
    )
```

The stubs are **generated at build time**: `base/ntos/ke/services.tab` lists every service with its
argument-byte count, `gensrv` turns it into the `ntdll` stubs and the kernel's `KiServiceTable`, and
`int 2Eh` / `SYSENTER` land in `KiSystemService` in `base/ntos/ke/i386/trap.asm`. The full mechanism,
with the generator's macro files, is documented in
[The native API](/native-api) and in
[Kernel and executive](/kernel#how-an-nt-call-reaches-the-manager).

The first user-mode processes come from `base/subsys/sm` (the session manager) and
`base/subsys/csr` (the client/server runtime subsystem); `base/subsys/posix` holds the POSIX
subsystem. Service control infrastructure is in `base/screg/sc` — and the registry client DLL
(`advapi32`'s `Reg*` functions) is `base/screg/winreg/client`.

## Win32k is not ntos

A common source of confusion: **`base/ntos` is the executive kernel; `windows/core` is the
kernel-mode half of Win32.** They are different projects with different build definitions.

| Directory | What it is |
| --- | --- |
| `windows/core/ntuser` | Kernel-mode USER: windowing, input, the desktop |
| `windows/core/ntgdi` | Kernel-mode GDI |
| `windows/core/kmode` | The win32k service table and shared kmode pieces |
| `windows/core/umode` | User-mode side (user32/gdi32 and friends) |
| `windows/core/winsrv` | The CSRSS server DLL for the Windows subsystem |
| `windows/core/dxkernel` | DirectX kernel support |
| `base/ntos/*` | Executive: memory, process, I/O, object, security managers |

A window-manager change belongs in `windows/core/ntuser`; a handle-table change belongs in
`base/ntos/ob`. The user-mode Win32 implementations are split between
`base/win32/client` (kernel32-style APIs) and `windows/core/umode`. The two kernels share one ABI —
the export list in `base/ntos/init/w32kexps.txt` and the second service table described in
[Win32, windowing and the shell](/win32-shell#the-win32k-service-table).

## Cross-cutting planes

| Plane | Producer and consumer locations | Why it matters |
| --- | --- | --- |
| Native / Win32 API | `base/ntdll`, `base/win32`, `windows/core`, `public/sdk/inc` | User/kernel ABI, process and UI contracts |
| Devices and files | `base/ntos/io`, `drivers`, `base/fs`, `base/pnp` | IRPs, cache, filesystem and redirector behaviour must agree |
| Transport | `net/ndis`, `net/tcpip`, `net/tdi`, `net/sockets`, `drivers/net` | NIC drivers, protocol stacks and socket libraries are separate |
| Identity and directory | `base/ntos/se`, `ds/security`, `ds/ds`, `ds/netapi`, `admin` | Enforcement, authentication, storage, APIs and UI are separate |
| IPC and objects | `com/rpc`, `com/ole32`, `admin/wmi`, `base/wmi`, `base/ntos/lpc` | RPC/COM contracts bridge processes and trees |
| Session / presentation | `windows/core`, `shell`, `termsrv`, `printscan` | Interactive, remote and printed output take different paths |

## Build variants that change what compiles

`dirs` entries can carry architecture qualifiers and `sources` files branch on build macros. The
variants that matter most in this tree:

| Variant | Meaning |
| --- | --- |
| `up` / `mp` | Uniprocessor / multiprocessor |
| `pae` / `paemp` | Physical Address Extension, alone or with `mp` |
| `i386`, `amd64`, `ia64`, `alpha`, `axp64` | Processor architectures with their own stubs and HALs |
| `wow6432`, `wow64win` | 32-bit compatibility on 64-bit — an interface path, not a second OS |
| `free` / `checked` | Release versus debug/verification build |

A directory name alone does not prove the variant is supported in this snapshot. Read the `sources`
file and the `!IF` guards before asserting a target exists.

## References

Official Microsoft documentation for the concepts on this page:

| Topic | Official documentation |
| --- | --- |
| `CreateFileW` | [https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilew](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilew) |
| `NtCreateFile` (user-mode view) | [https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ntcreatefile](https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ntcreatefile) |
| System boot and the loader | [https://learn.microsoft.com/en-us/windows-hardware/drivers/bringup/boot-process](https://learn.microsoft.com/en-us/windows-hardware/drivers/bringup/boot-process) |
| Windows kernel-mode drivers | [https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/) |
| Windows drivers reference (wdm.h) | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/) |
| Processes and threads (user-mode) | [https://learn.microsoft.com/en-us/windows/win32/procthread/processes-and-threads](https://learn.microsoft.com/en-us/windows/win32/procthread/processes-and-threads) |
| Wow64 | [https://learn.microsoft.com/en-us/windows/win32/winprog64/running-32-bit-applications](https://learn.microsoft.com/en-us/windows/win32/winprog64/running-32-bit-applications) |
| Windows architecture (presentation + docs) | [https://learn.microsoft.com/en-us/windows/win32/learnwin32/learn-to-program-for-windows](https://learn.microsoft.com/en-us/windows/win32/learnwin32/learn-to-program-for-windows) |

In-tree anchors for this page:

| File | Why |
| --- | --- |
| [`base/ntos/init/init.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/init/init.c) | `ExpInitializeExecutive` (611), `Phase1Initialization` (1394) |
| [`base/ntos/ke/services.tab`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/services.tab) | The native service list |
| [`windows/core/kmode/services.tab`](https://github.com/havaianasdestruido/neo-nt5/blob/main/windows/core/kmode/services.tab) | The win32k service list |
| [`base/ntos/init/w32kexps.txt`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/init/w32kexps.txt) | The kernel→win32k ABI |
| [`base/ntos/dirs`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/dirs) | The executive build traversal |

## Frequently asked questions

### Q: Where does a system call actually start and end?

On the way in: an application calls a Win32 export such as `CreateFileW`, implemented in user mode at
[`base/win32/client/fileopcr.c:5371`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/win32/client/fileopcr.c):

```c
HANDLE
WINAPI
CreateFileW(
    LPCWSTR lpFileName,
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile
    )
```

That translates arguments and calls the native service `NtCreateFile` through `ntdll`, which crosses
into `base/ntos/io/iomgr/create.c`. From there the I/O manager builds an IRP and hands it to a
filesystem driver. A system call is therefore *not* a library call into a driver — see
[I/O, file systems and storage](/io-storage) for the full path.

### Q: Which `dirs` file decides whether my kernel change is even compiled?

Every ancestor `dirs`, from the root down. For kernel code the chain is
`dirs` → `base/dirs` → `base/ntos/dirs` → `base/ntos/io/dirs`, and then the leaf `sources`.
`OPTIONAL_DIRS` entries and `!IF` guards can silently exclude a folder:

```bash
# print the traversal chain for one component
for d in . base base/ntos base/ntos/io; do echo "== $d/dirs"; cat $d/dirs; done
```

`base/ntos/dirs` ends with `OPTIONAL_DIRS=` (empty), so nothing in `ntos` is optional at that level —
but that is a property of this file, not of the build system.

### Q: Is the HAL a directory or a product?

`base/hals/` contains several HAL implementations: `halacpi`, `halmps`, `halx86`, `halia64`,
`halsp`, `halssc`, plus shared `inc/`, `processor/`, `intfilter/` and `mcasample/`. The HAL is the
platform-specific layer between firmware and the kernel, declared with `TARGETTYPE=HAL`. Changing
`base/ntos` does not require a HAL change, and changing a HAL does not change kernel semantics — but
the kernel/HAL interface is an ABI, so review both sides.

### Q: Why are there directories for Alpha and MIPS in a 5.1 tree?

This is a historical source tree that retained architecture branches. `base/ntdll/alpha`,
`base/ntos/init/up/ntoskrnl.alp`, `base/hals/halsp` and similar are checked in. Whether a given
architecture still builds here is a separate question from whether its source is present — the root
build traversal and the available toolchain decide that, and no build was run for this
documentation.

### Q: How do I tell a kernel-mode GUI change from a shell change?

Follow the direction of the call. Code in `shell/explorer` (for example
`tray.cpp`, `taskbar.cpp`, `bandsite.cpp`) runs in the Explorer process and talks to the window
manager through Win32. Code in `windows/core/ntuser` *is* the window manager. If a symptom can be
reproduced with a plain Win32 program and no Explorer, the owner is usually `windows/core`; if it
needs the shell to appear, start in `shell/`.

### Q: Does this architecture page describe the boot order exactly?

No, and it deliberately does not claim to. It names the trees involved at each stage so you can find
the owner of a change. The authoritative order lives in the loader (`base/boot/bldr`), in
`ExpInitializeExecutive` and `Phase1Initialization` in `base/ntos/init/init.c`, and in the service
start order recorded in the registry hives and INFs under `base/ntsetup`. Read those before
asserting an ordering.

### Q: How many system services and windowing services does this build define?

284 native services in `base/ntos/ke/services.tab` and 750 win32k entries in
`windows/core/kmode/services.tab`, both counted as the checked-in files stand. Those lists *are* the
ABI for this source; anything published elsewhere describes a different build. See
[The native API](/native-api).
