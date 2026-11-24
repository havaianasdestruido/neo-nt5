---
title: I/O, file systems and storage
sidebar_position: 5
description: The IRP lifecycle with the exact stack macros, the CreateFileW-to-IRP walk-through, the layered split between the I/O manager, file systems, class and port drivers, Plug and Play, and the official WDK documentation for each routine.
---

A file operation in this tree crosses at least four separate projects. Knowing which layer owns a
symptom is most of the work: the I/O manager (`base/ntos/io`), the file system (`base/fs`), the class
and port drivers (`drivers/storage`), and Plug and Play / setup (`base/pnp`). This page walks one
`CreateFile` call end to end, then maps each layer's routines to their official documentation.

## From `CreateFileW` to an IRP

One call, five layers, each in a different directory of this tree:

```text
app: CreateFileW(L"C:\\temp\\f.txt", ...)
  -> kernel32 thunk   base/win32/client/fileopcr.c:5371  (CreateFileW)
  -> ntdll stub       generated from base/ntos/ke/services.tab (CreateFile,11)
  -> I/O manager      base/ntos/io/iomgr/create.c:37     (NtCreateFile)
  -> filesystem       base/fs/ntfs/create.c:633          (NtfsFsdCreate)
  -> storage stack    drivers/storage/...                (class/port drivers)
```

The public signature, as compiled against `winternl.h`:

```cpp
__kernel_entry NTSTATUS NtCreateFile(
  [out]          PHANDLE            FileHandle,
  [in]           ACCESS_MASK        DesiredAccess,
  [in]           POBJECT_ATTRIBUTES ObjectAttributes,
  [out]          PIO_STATUS_BLOCK   IoStatusBlock,
  [in, optional] PLARGE_INTEGER     AllocationSize,
  [in]           ULONG              FileAttributes,
  [in]           ULONG              ShareAccess,
  [in]           ULONG              CreateDisposition,
  [in]           ULONG              CreateOptions,
  [in, optional] PVOID              EaBuffer,
  [in]           ULONG              EaLength
);
```

— [NtCreateFile function (winternl.h), Microsoft Learn](https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ntcreatefile)

Two parameter groups decide behaviour that is invisible in the `CreateFileW` API, and both are
documented on that page:

| `CreateDisposition` | Meaning (quoted from the official documentation) |
| --- | --- |
| `FILE_SUPERSEDE` | If the file already exists, replace it with the given file. If it does not, create the given file. |
| `FILE_CREATE` | If the file already exists, fail the request and do not create or open the given file. |
| `FILE_OPEN` | If the file already exists, open it instead of creating a new file. If it does not, fail the request. |
| `FILE_OPEN_IF` | If the file already exists, open it. If it does not, create the given file. |
| `FILE_OVERWRITE` | If the file already exists, open it and overwrite it. If it does not, fail the request. |
| `FILE_OVERWRITE_IF` | If the file already exists, open it and overwrite it. If it does not, create the given file. |

`ObjectAttributes` is initialized with `InitializeObjectAttributes` and carries the name — either a
fully qualified path such as `\??\C:\temp\f.txt`, or a path relative to a `RootDirectory` handle —
plus `OBJ_CASE_INSENSITIVE` and an optional security descriptor and quality-of-service blob. The
official page also records two rules that show up as bugs constantly: `NtCreateFile` **never returns
`STATUS_REPARSE`**, and for directories you must not pass `FILE_READ_DATA`, `FILE_WRITE_DATA`,
`FILE_APPEND_DATA` or `FILE_EXECUTE` (use `FILE_LIST_DIRECTORY` / `FILE_TRAVERSE`).

The kernel-side implementation in this tree is exactly the service from
[`base/ntos/io/iomgr/create.c:37`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/io/iomgr/create.c):

```c
NTSTATUS
NtCreateFile(
    OUT PHANDLE FileHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes,
    OUT PIO_STATUS_BLOCK IoStatusBlock,
    IN PLARGE_INTEGER AllocationSize OPTIONAL,
    IN ULONG FileAttributes,
    IN ULONG ShareAccess,
    IN ULONG CreateDisposition,
    IN ULONG CreateOptions,
    IN PVOID EaBuffer OPTIONAL,
    IN ULONG EaLength
    )
```

It builds the `IRP_MJ_CREATE` IRP and sends it down the stack; the filesystem's `NtfsFsdCreate`
(`base/fs/ntfs/create.c:633`) is what ultimately decides whether the open succeeds. Everything
after `NtCreateFile` on this page describes how that IRP travels.

## The IRP lifecycle

An I/O request is a packet with a stack of locations, one per driver it passes through. The I/O
manager builds it, `IofCallDriver` sends it down, `IofCompleteRequest` walks the completion routines
back up. The stack cursor is a macro in the DDK header,
[`public/ddk/inc/wdm/wdm.h:12424`](https://github.com/havaianasdestruido/neo-nt5/blob/main/public/ddk/inc/wdm/wdm.h):

```c
#define IoGetNextIrpStackLocation( Irp ) (\
    (Irp)->Tail.Overlay.CurrentStackLocation - 1 )
```

The whole family lives in the same header, and every driver in the tree is written against these
exact macros:

| Macro | Line in `public/ddk/inc/wdm/wdm.h` | What it does |
| --- | --- | --- |
| `IoGetCurrentIrpStackLocation` | 12293 | Returns `Tail.Overlay.CurrentStackLocation` — the caller's own slot |
| `IoGetNextIrpStackLocation` | 12424 | The slot one level down (the next driver's) |
| `IoSetNextIrpStackLocation` | 12711 | Advances the cursor before building the next slot |
| `IoSkipCurrentIrpStackLocation` | 12778 | Passes the IRP down *without* a completion routine |
| `IoSetCompletionRoutine` | 12665 | Registers the routine run when the lower driver completes |
| `IoMarkIrpPending` | 12548 | Marks the IRP pending — required when a dispatch routine returns `STATUS_PENDING` |

`IoSetCompletionRoutine` expands to a store of three booleans — `Success`, `Error`, `Cancel` — which
is why a completion routine can be asked to run only on one outcome:

```c
#define IoSetCompletionRoutine( Irp, Routine, CompletionContext, Success, Error, Cancel ) { \
```

Allocation and completion are indirections in
[`base/ntos/io/iomgr/iosubs.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/io/iomgr/iosubs.c),
so the verifier can substitute its own:

```c
PIRP
IoAllocateIrp(
    IN CCHAR StackSize,
    IN BOOLEAN ChargeQuota
    )
{
    return (pIoAllocateIrp(StackSize, ChargeQuota));
}
```

Anchors in the same file, with their exact lines in this checkout:

| Routine | Line | Role |
| --- | --- | --- |
| `IoAllocateIrp` | 713 | Build an IRP for a lower driver |
| `IoBuildSynchronousFsdRequest` | 2102 | The workhorse behind synchronous `ReadFile`/`WriteFile` |
| `IofCallDriver` | 2273 | Send the IRP down (verifier indirection) |
| `IofCompleteRequest` | 3316 | Run the completion chain back up |
| `IoCreateDevice` | 4236 | Create a device object — every driver's `DriverEntry` call |
| `IoCompleteRequest` | 13025 | The thin public wrapper over `IofCompleteRequest` |

The completion path is documented at length in the source itself, in the header comment of
`IopfCompleteRequest`:

```text
1.  A check is made to determine whether the packet's stack locations
    have been exhausted.  If not, then the stack location pointer is set
    to the next location and if there is a routine to be invoked, then
    it will be invoked. ...

    If a routine is invoked to complete the packet for a specific driver
    which needs to perform work a lot of work or the work needs to be
    performed in the context of another process, then the routine will
    return an alternate success code of STATUS_MORE_PROCESSING_REQUIRED.
```

`STATUS_MORE_PROCESSING_REQUIRED` is the mechanism that lets a driver defer completion. Misusing it —
returning it without ever completing the IRP later — is the classic "hung I/O with no visible owner"
bug.

### The dispatch rules that trip everyone

Drawn from the code on this page and the official `IoCallDriver` documentation
([IoCallDriver macro (wdm.h), Microsoft Learn](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)):

1. If a dispatch routine queues the IRP and returns, it must call `IoMarkIrpPending` first and
   return `STATUS_PENDING` — even if the work completes instantly afterwards.
2. If a dispatch routine calls `IoSkipCurrentIrpStackLocation`, it may **not** also register a
   completion routine; the skip leaves no slot for it.
3. `IoCallDriver`'s return is the lower driver's status; it is not necessarily the IRP's final
   status. A driver that returns a status other than the one it puts in `Irp->IoStatus.Status`
   creates the inconsistency the verifier check `CompleteRequestStatusCheck` exists to catch.
4. The official requirement for `IoCallDriver` is `IRQL <= DISPATCH_LEVEL`, and the DDI compliance
   rules it lists (`ForwardedAtBadIrql`, `MarkIrpPending`, `LowerDriverReturn`, …) are precisely
   the failure shapes above.

## File system drivers

`base/fs/` holds one directory per format or role:

| Directory | Role |
| --- | --- |
| `ntfs`, `fastfat`, `cdfs`, `udfs` | On-disk file systems |
| `efs` | Encrypting file system filter layer |
| `mup` | Multiple UNC provider — routes a UNC path to a redirector |
| `rdr2` | The SMB client redirector |
| `srv` | The SMB server service |
| `npfs`, `mailslot` | Named pipes and mailslots |
| `clfs`, `lfs` | Common log file system and the older log file service |
| `dfs`, `hsm`, `sis`, `remotefs`, `smbtrsup` | DFS, hierarchical storage, single-instance store, remote/transport support |
| `fltsamples` | Legacy filter samples: `filespy`, `sfilter`, `latency`, `iotest` |

A file system registers itself by filling in the driver object's dispatch table. From
[`base/fs/ntfs/ntfsinit.c:245`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/fs/ntfs/ntfsinit.c):

```c
DriverObject->MajorFunction[IRP_MJ_CREATE]                   = (PDRIVER_DISPATCH)NtfsFsdCreate;
DriverObject->MajorFunction[IRP_MJ_CLOSE]                    = (PDRIVER_DISPATCH)NtfsFsdClose;
DriverObject->MajorFunction[IRP_MJ_READ]                     = (PDRIVER_DISPATCH)NtfsFsdRead;
DriverObject->MajorFunction[IRP_MJ_WRITE]                    = (PDRIVER_DISPATCH)NtfsFsdWrite;
DriverObject->MajorFunction[IRP_MJ_FLUSH_BUFFERS]            = (PDRIVER_DISPATCH)NtfsFsdFlushBuffers;
DriverObject->MajorFunction[IRP_MJ_FILE_SYSTEM_CONTROL]      = (PDRIVER_DISPATCH)NtfsFsdFileSystemControl;
DriverObject->MajorFunction[IRP_MJ_CLEANUP]                  = (PDRIVER_DISPATCH)NtfsFsdCleanup;
DriverObject->MajorFunction[IRP_MJ_SHUTDOWN]                 = (PDRIVER_DISPATCH)NtfsFsdShutdown;
DriverObject->MajorFunction[IRP_MJ_PNP]                      = (PDRIVER_DISPATCH)NtfsFsdPnp;

DriverObject->FastIoDispatch = &NtfsFastIoDispatch;

NtfsFastIoDispatch.SizeOfFastIoDispatch =    sizeof(FAST_IO_DISPATCH);
NtfsFastIoDispatch.FastIoCheckIfPossible =   NtfsFastIoCheckIfPossible;
NtfsFastIoDispatch.FastIoRead =              NtfsCopyReadA;
NtfsFastIoDispatch.FastIoWrite =             NtfsCopyWriteA;
```

Two things to notice. Several major functions share one dispatcher (`NtfsFsdDispatch`) because they
all take the same path, and the `FastIoDispatch` table is a *separate* fast path that bypasses IRPs
entirely — a change to cached-read semantics has to be made in both places or the two paths diverge.

The `Fsd` prefix means "file system driver": the routine may be called in the context of the
requesting thread. `Fsp`-prefixed routines run in the file system's own worker context. That
distinction determines what you may do about blocking, APCs and exception handling.

NTFS's create path, the deepest common path in the tree:

| Routine | Location | Context |
| --- | --- | --- |
| `NtfsFsdCreate` | [`base/fs/ntfs/create.c:633`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/fs/ntfs/create.c) | The `IRP_MJ_CREATE` dispatch entry |
| `NtfsCommonCreate` | `base/fs/ntfs/create.c:1261` | The shared worker (FSD and FSP paths converge here) |
| `NtfsFsdRead` | [`base/fs/ntfs/read.c:134`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/fs/ntfs/read.c) | The `IRP_MJ_READ` entry |

When tracing an open failure, start at `NtfsFsdCreate` and follow the `NtfsCompleteRequest` /
exception style of the surrounding code rather than assuming the status came from the I/O manager.

## Storage class and port drivers

`drivers/storage/` is layered, and the layers have distinct owners:

| Layer | Directory | Example |
| --- | --- | --- |
| Class (device-type logic) | `class`, `classpnp`, `cdrom`, `disk`, `tape`, `changer` | `disk.sys` |
| Port / miniport | `port` (`scsi`, `raid`, `diskdump`), `scsiport`, `ide`, `iscsiprt`, `sbp2port` | `scsiport.sys` |
| Volume and filtering | `partmgr`, `volsnap`, `newft`, `drivearb`, `fpfilter`, `addfilter` | partitioning, snapshots, fault tolerance |
| Removable / legacy | `fdc`, `sfloppy`, `mcd`, `redbook`, `cdaudio`, `rsm2`, `tffsport` | |
| Instrumentation | `diskperf`, `scsiwmi`, `kdext` | performance and WMI |

The class driver `disk.sys` does not talk to hardware directly; it hands a `CLASS_INIT_DATA`
structure to `classpnp`. From
[`drivers/storage/disk/disk.c:181`](https://github.com/havaianasdestruido/neo-nt5/blob/main/drivers/storage/disk/disk.c):

```c
DriverEntry(
    IN PDRIVER_OBJECT DriverObject,
    IN PUNICODE_STRING RegistryPath
    )
{
    CLASS_INIT_DATA InitializationData;
    CLASS_QUERY_WMI_REGINFO_EX_LIST classQueryWmiRegInfoExList;
    GUID guidQueryRegInfoEx = GUID_CLASSPNP_QUERY_REGINFOEX;

    NTSTATUS status;

#if defined(_X86_)
    //
    // Read the information NtDetect squirreled away about the disks in this
    // system.
    //
    status = DiskSaveDetectInfo(DriverObject);
    ...
#endif
```

and its build definition, `drivers/storage/disk/sources`, links against the class library:

```bat
TARGETNAME=disk
TARGETPATH=obj
TARGETTYPE=DRIVER

TARGETLIBS=$(DDK_LIB_PATH)\classpnp.lib
```

`drivers/storage/classpnp` also ships an in-tree document,
[`classpnp.htm`](https://github.com/havaianasdestruido/neo-nt5/blob/main/drivers/storage/classpnp/classpnp.htm),
describing the class-driver contract. Read it as reference; per the repository's
[source-only policy](/#the-source-only-change-policy), behaviour changes belong in the C
source, not in that page.

## Plug and Play and setup

`base/pnp/` contains the user-mode half: `umpnpmgr` (the PnP manager service), `cfgmgr32` and
`setupapi` (the installation APIs), `newdev`, `hdwwiz` (add-hardware wizard), `hotplug`, plus `idl`
and a `test` directory. The kernel half is `base/ntos/io/pnpmgr`, and resource arbitration is
`base/ntos/arb`.

The SetupAPI entry points live in `base/pnp/setupapi` — `SetupDiCreateDeviceInfoList` at
[`base/pnp/setupapi/devinfo.c:124`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/pnp/setupapi/devinfo.c)
and `SetupDiCallClassInstaller` at
[`base/pnp/setupapi/devinst.c:944`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/pnp/setupapi/devinst.c)
are the two a driver-installation change touches most. Their official documentation:
[SetupDiCreateDeviceInfoList](https://learn.microsoft.com/en-us/windows/win32/api/setupapi/nf-setupapi-setupdicreatedeviceinfolist)
and
[SetupDiCallClassInstaller](https://learn.microsoft.com/en-us/windows/win32/api/setupapi/nf-setupapi-setupdicallclassinstaller).

An INF is part of the contract, not decoration — a driver that builds but is not described by an INF
never loads on a clean install. A minimal real example,
[`admin/dcpromo/dcpdns.inf`](https://github.com/havaianasdestruido/neo-nt5/blob/main/admin/dcpromo/dcpdns.inf):

```inf
[Version]
Signature = "$Windows NT$"

[Components]
NetOC=netoc.dll,NetOcSetupProc,netoc.inf

[Global]
WindowTitle=Windows NT Server Setup -- Installing DNS Server
```

That one delegates to a network optional-component DLL. Driver INFs are larger and carry
`[Manufacturer]`, `[SourceDisksFiles]` and `[DestinationDirs]` sections.

## References

Official Microsoft documentation for the routines on this page:

| Routine / topic | Official documentation |
| --- | --- |
| `NtCreateFile` (user mode) | [https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ntcreatefile](https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ntcreatefile) |
| `ZwCreateFile` (kernel mode) | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntddk/nf-ntddk-zwcreatefile](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntddk/nf-ntddk-zwcreatefile) |
| `CreateFileW` (Win32) | [https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilew](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilew) |
| `IoCallDriver` / `IofCallDriver` | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver), [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-iofcalldriver](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-iofcalldriver) |
| `IoCompleteRequest` | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest) |
| `IoAllocateIrp` | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp) |
| `IoBuildSynchronousFsdRequest` | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildsynchronousfsdrequest](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildsynchronousfsdrequest) |
| `IoCreateDevice` | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice) |
| IRPs and IRP stack locations | [https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/irps](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/irps) |
| File names, paths and namespaces | [https://learn.microsoft.com/en-us/windows/win32/fileio/naming-a-file](https://learn.microsoft.com/en-us/windows/win32/fileio/naming-a-file) |
| Using files in a driver | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ifs/using-files-in-a-driver](https://learn.microsoft.com/en-us/windows-hardware/drivers/ifs/using-files-in-a-driver) |
| `SetupDiCreateDeviceInfoList` | [https://learn.microsoft.com/en-us/windows/win32/api/setupapi/nf-setupapi-setupdicreatedeviceinfolist](https://learn.microsoft.com/en-us/windows/win32/api/setupapi/nf-setupapi-setupdicreatedeviceinfolist) |

In-tree anchors:

| Document / file | Why |
| --- | --- |
| [`public/ddk/inc/wdm/wdm.h`](https://github.com/havaianasdestruido/neo-nt5/blob/main/public/ddk/inc/wdm/wdm.h) | Every IRP macro quoted on this page, at the cited lines |
| [`base/ntos/io/iomgr/iosubs.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/io/iomgr/iosubs.c) | Allocation, send, complete, `IoCreateDevice` |
| [`base/fs/ntfs/ntfsinit.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/fs/ntfs/ntfsinit.c) | A complete filesystem dispatch table |
| [`drivers/storage/classpnp/classpnp.htm`](https://github.com/havaianasdestruido/neo-nt5/blob/main/drivers/storage/classpnp/classpnp.htm) | The class-driver contract (reference only) |
| [`base/pnp/setupapi`](https://github.com/havaianasdestruido/neo-nt5/tree/main/base/pnp/setupapi) | The SetupAPI implementation |

## Frequently asked questions

### Q: Which layer produced this error status?

Walk the stack, not the status code. A `STATUS_*` value travels up through every completion routine
and any of them can rewrite it. Practical triage:

```bash
# is the status generated by the I/O manager itself?
rg -n 'STATUS_INVALID_PARAMETER' base/ntos/io/iomgr/*.c | head

# is it a filesystem-specific status?
rg -n 'return STATUS_' base/fs/ntfs/create.c | head

# or does the port driver translate a SCSI sense code?
rg -n 'ScsiPortNotification|MapScsiStatus' drivers/storage/port/scsi/*.c | head
```

If the same status appears in several layers, the *deepest* one that can produce it for this request
is the one to change.

### Q: What does `CreateFileW` do that `NtCreateFile` does not?

Argument translation and compatibility: the Win32 layer converts DOS paths and device names,
expands `lpSecurityAttributes`, maps `dwCreationDisposition` onto `CreateDisposition`, folds
`FILE_FLAG_*` into `CreateOptions`, and maps the resulting `NTSTATUS` back to `GetLastError` codes.
The implementation is `CreateFileW` at `base/win32/client/fileopcr.c:5371` (with the ANSI
`CreateFileA` at line 5331 doing conversion first). Semantics of the open itself are identical —
they are decided below `NtCreateFile`. See
[Win32, windowing and the shell](/win32-shell).

### Q: Is `fltmgr` in this tree?

There is no `base/fs/fltmgr` directory in this checkout. What exists is the legacy filter sample set
under `base/fs/fltsamples/` — `filespy`, `sfilter`, `latency` and `iotest` — which attach to a device
object and intercept IRPs the older way. If you are looking for a filter framework, that is the
mechanism present here; do not assume the modern filter manager API is available.

```bash
ls base/fs/fltsamples        # dirs  filespy  iotest  latency  sfilter
ls base/fs | grep -i flt     # fltsamples only
```

### Q: Where does a network path (`\\server\share`) get resolved? {#network-path-resolution}

In `mup`, then in the redirector. `base/fs/mup` decides which redirector provider claims the prefix;
`base/fs/rdr2` implements the SMB client; `base/fs/srv` is the server side. A network-file bug
therefore has three candidate owners before the network stack is even involved:

```text
CreateFile("\\server\share\f") -> mup prefix lookup -> rdr2 redirector
                               -> net/tdi + net/tcpip transport
```

See [Networking stack](/networking) for the transport half.

### Q: What is the difference between `class` and `classpnp`?

`class` is the historical class driver; `classpnp` is the PnP/power-aware shared library that modern
class drivers (`disk`, `cdrom`) link against and delegate to. That is why `disk/sources` has
`TARGETLIBS=$(DDK_LIB_PATH)\classpnp.lib` and why `disk.sys`'s `DriverEntry` is mostly a
`CLASS_INIT_DATA` initialisation. A change to retry, autorun or power behaviour usually belongs in
`classpnp` — check `retry.c`, `autorun.c` and `power.c` there before touching `disk`.

### Q: How do I add a source file to a filesystem driver?

To the leaf `sources`, never to the local `makefile`. NTFS's own leaf file lists them explicitly, so
the edit is a one-line addition to a `SOURCES=` continuation:

```bash
grep -n "^SOURCES=" -A 30 base/fs/ntfs/sources | head -35
```

Then confirm the directory is reached: `base/dirs` must list `fs`, and `base/fs/dirs` must list the
format directory.

### Q: Does a change here need a registry or INF update too?

Often. Storage drivers read configuration from
`HKLM\SYSTEM\CurrentControlSet\Services\<name>` — the `RegistryPath` argument to `DriverEntry` is
exactly that services node. If you add a tunable, it needs a default in the INF or in the hive under
`base/ntsetup`, otherwise a clean install behaves differently from a machine that has the value set
by hand.

### Q: Can I test any of this without booting Windows?

Only statically. The tree does contain kernel test scaffolding and samples — for example
`base/pnp/test`, `base/fs/fltsamples/iotest`, and the `drt` directories described in
[Tests, diagnostics and debugging](/testing-debugging) — but running them needs a target system. On
this checkout the honest evidence is a source read, the build-definition chain, and
`git diff --check`. Say which of those you did.
