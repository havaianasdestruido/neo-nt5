---
title: Architecture and runtime boundaries
sidebar_position: 2
description: Boot chain, kernel and user mode, the executive managers, Win32k, and how engineering trees map onto runtime layers.
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

## Boot and kernel start-up

`base/boot/` contains `bootcode`, `bldr`, `detect`, `efi`, `startrom`, `tftplib`, `oschoice`,
`setup`, `kdcom` and `kd1394` — boot sectors, the loader, hardware detection, the EFI path, network
boot and the boot-time transports for the kernel debugger. Architecture-specific and language
folders underneath are variants, not separate operating systems.

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

The first user-mode processes come from `base/subsys/sm` (the session manager) and
`base/subsys/csr` (the client/server runtime subsystem); `base/subsys/posix` holds the POSIX
subsystem. Service control infrastructure is in `base/screg/sc`.

## Win32k is not ntos

A common source of confusion: **`base/ntos` is the executive kernel; `windows/core` is the
kernel-mode half of Win32.** They are different projects with different build definitions.

| Directory | What it is |
| --- | --- |
| `windows/core/ntuser` | Kernel-mode USER: windowing, input, the desktop |
| `windows/core/ntgdi` | Kernel-mode GDI |
| `windows/core/kmode` | Kernel-mode support for the above |
| `windows/core/umode` | User-mode side (user32/gdi32 and friends) |
| `windows/core/winsrv` | The CSRSS server DLL for the Windows subsystem |
| `windows/core/dxkernel` | DirectX kernel support |
| `base/ntos/*` | Executive: memory, process, I/O, object, security managers |

A window-manager change belongs in `windows/core/ntuser`; a handle-table change belongs in
`base/ntos/ob`. The user-mode Win32 implementations are split between
`base/win32/client` (kernel32-style APIs) and `windows/core/umode`.

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

## Address space layout

The split between user and kernel address space is a property of the build configuration, not of
the hardware alone. The default 32-bit layout is a 2 GiB / 2 GiB split; the `/3GB` boot switch moves
it to 3 GiB / 1 GiB for programs linked with `LARGEADDRESSAWARE`; PAE changes physical addressing,
not the virtual split.

```text
32-bit default                    32-bit /3GB                      x64
0x00000000 +----------+           0x00000000 +----------+          0x0000000000000000
           | user    |                      | user    |                          | user
0x7FFFFFFF +----------+           0xBFFFFFFF +----------+          0x000007FFFFFFFFFF
0x80000000 | kernel  |           0xC0000000 | kernel  |          0xFFFF800000000000
           |         |                      |         |                          | kernel
0xFFFFFFFF +----------+           0xFFFFFFFF +----------+          0xFFFFFFFFFFFFFFFF
```

`base/ntos/mm` enforces the split: `MmUserProbeAddress` is the boundary above which a user-mode
pointer is invalid, and `ProbeForRead`/`ProbeForWrite` check it. A driver that captures a user
pointer without probing can be handed a kernel address and read or write kernel memory — the
classic "user-mode pointer capture" vulnerability.

The tree carries the PAE variants in `base/ntos/init/pae` and `base/ntos/init/paemp`, with
`C_DEFINES=$(C_DEFINES) /D_X86PAE_` in `base/ntos/init/paemp/sources`.

## System service dispatch

The full path from a Win32 call to the executive, with the tree's file for each hop:

| Hop | Location |
| --- | --- |
| Win32 export | `base/win32/client/<family>.c`, export list in `kernel32.prf` |
| Argument conversion | `base/win32/client` (ANSI/Unicode, path translation) |
| Native stub | generated from `base/ntos/ke/services.tab` by `gensrv` |
| Syscall instruction | `int 2Eh` / `sysenter`; entry at `base/ntos/ke/i386/trap.asm` |
| Dispatcher | `KiSystemService`; table at `base/ntos/ke/kiinit.c:314` |
| Service implementation | `base/ntos/<manager>/...`, e.g. `io/iomgr/create.c:37` |

The table is built from `services.tab` (284 lines, `Name,ArgumentCount`). `KeServiceDescriptorTable`
is the user-mode table; `KeServiceDescriptorTableShadow` is the copy that `win32k.sys` fills with
`NtUser*`/`NtGdi*` at index 1. The dispatcher selects the table from the caller's `PreviousMode`, which
is why a Win32k call from a user thread works while the same call from a kernel thread without a
Win32k context does not.

## Process and thread objects

The executive represents a process with an `EPROCESS` and a thread with an `ETHREAD`. The important
fields, for orientation:

| Object | Field | Meaning |
| --- | --- | --- |
| `EPROCESS` | `Pcb` | The kernel process block (`KPROCESS`) |
| | `UniqueProcessId` | The PID |
| | `ActiveThreads` | Thread count |
| | `ObjectTable` | The handle table |
| | `SectionObject` | The executable image |
| | `DirectoryObject` | The object directory |
| | `Token` | The primary token (`EX_FAST_REF`) |
| `ETHREAD` | `Tcb` | The kernel thread block (`KTHREAD`) |
| | `Cid` | `CLIENT_ID` (process and thread IDs) |
| | `ThreadsProcess` | Owning `EPROCESS` |
| | `StartAddress` | The `LPTHREAD_START_ROUTINE` |
| | `Win32StartAddress` | The Win32 start address |
| | `Teb` | The thread's TEB |

`PsCreateSystemThread` (`base/ntos/ps/create.c:184`) creates a thread in the initial system process
when `ProcessHandle == NULL`. `PsLookupProcessByProcessId` and `PsLookupThreadByThreadId` are the
lookups behind `NtOpenProcess`/`NtOpenThread`.

## Executive manager reference

| Manager | Key routines | Responsibility |
| --- | --- | --- |
| `ke` | `KeWaitForSingleObject`, `KeAcquireSpinLock`, `KeInsertQueueDpc`, `KeBugcheckEx` | Scheduling, synchronization, DPC/ISR, bugcheck |
| `mm` | `MmAllocatePagesForMdl`, `MmProbeAndLockPages`, `MmBuildMdlForNonPagedPool` | Virtual memory, MDLs, paging |
| `ps` | `PsCreateSystemThread`, `PsLookupProcessByProcessId`, `PsTerminateProcess` | Process/thread lifecycle |
| `io` | `IoCreateDevice`, `IoCallDriver`, `IoCompleteRequest`, `IoAllocateIrp` | I/O manager and PnP |
| `ob` | `ObReferenceObjectByHandle`, `ObOpenObjectByName`, `ObInsertObject` | Object namespace and handles |
| `se` | `SeAccessCheck`, `SeAssignSecurity`, `SeTokenIsAdmin` | Access checks and tokens |
| `ex` | `ExAllocatePoolWithTag`, `ExInitializeResourceLite`, `ExInterlockedInsertTailList` | Pool, resources, interlocked lists |
| `config` | `NtCreateKey`, `NtQueryValueKey`, `CmRegisterCallback` | Registry |
| `cache` | `CcInitializeCacheMap`, `CcPinRead`, `CcFlushCache` | Cache manager |
| `lpc` | `NtCreatePort`, `NtConnectPort`, `NtRequestWaitReplyPort` | LPC ports |
| `po` | `PoCallDriver`, `PoRegisterDevice`, `PoSetPowerState` | Power manager |
| `dbgk` | `DbgkInitialize`, `DbgkCreateThread` | User-mode debugging |
| `rtl` | `RtlInitUnicodeString`, `RtlAllocateHeap`, `RtlNtStatusToDosError` | Runtime library |

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
