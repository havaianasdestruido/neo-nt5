---
title: Kernel driver model — WDM, IRPs and DDI
sidebar_position: 24
description: DriverEntry, dispatch tables, the IRP stack, PnP and power, completion semantics, DPC/ISR/DMA, filesystem drivers and NDIS miniports — the driver-facing contracts in this tree.
---

A Windows kernel driver is a DLL with a `DriverEntry` that fills a dispatch table and a device
stack that receives **IRPs** (I/O request packets). The contract is the DDI in `public/ddk/inc`
(`wdm.h`, `ntifs.h`, `ndis.h`, `scsi.h`), not the Win32 API. This page is the model; the tree
implements it across `drivers/`, `base/fs`, `net/ndis` and `base/ntos/io`.

```text
I/O manager (base/ntos/io)
   |  IoCallDriver -> IofCallDriver -> IopfCallDriver
   v
+--------------------------------------------------+
| Device object stack                              |
|   top filter -> function driver -> bus driver    |
|   each has a DRIVER_OBJECT and a dispatch table  |
+--------------------------------------------------+
   |  IRP with a stack of IO_STACK_LOCATION, one per driver
   v
hardware (port/miniport) or filesystem (base/fs)
```

## The three kinds of driver in this tree

| Kind | `TARGETTYPE` | Examples | Contract |
| --- | --- | --- | --- |
| Kernel-mode driver | `DRIVER` | `drivers/storage/disk`, `base/fs/ntfs`, `net/tcpip` | `wdm.h` / `ntifs.h` |
| NDIS miniport | `MINIPORT` | `drivers/net/*`, `net/ndis/samples` | `ndis.h` |
| Class/port library | `LIBRARY` | `drivers/storage/classpnp`, `net/ndis/sys` | shared header sets |

`drivers/storage/disk/sources` is a one-screen example:

```bat
TARGETNAME=disk
TARGETPATH=obj
TARGETTYPE=DRIVER

TARGETLIBS=$(DDK_LIB_PATH)\classpnp.lib
```

The `TARGETLIBS` line is the dependency: `disk.sys` links against the class library, and
`DriverEntry` is mostly a `CLASS_INIT_DATA` initialisation.

## `DriverEntry`

```c
NTSTATUS
DriverEntry(
    IN PDRIVER_OBJECT DriverObject,
    IN PUNICODE_STRING RegistryPath
    );
```

The real one, from
[`drivers/storage/disk/disk.c:181`](https://github.com/havaianasdestruido/neo-nt5/blob/main/drivers/storage/disk/disk.c#L181):

```c
DriverEntry(
    IN PDRIVER_OBJECT DriverObject,
    IN PUNICODE_STRING RegistryPath
    )
{
    CLASS_INIT_DATA InitializationData;
    ...
    NTSTATUS status;

    status = DiskSaveDetectInfo(DriverObject);
    ...
    RtlZeroMemory (&InitializationData, sizeof(CLASS_INIT_DATA));
    InitializationData.InitializationDataSize = sizeof(CLASS_INIT_DATA);
    InitializationData.FdoData.DeviceExtensionSize = FUNCTIONAL_EXTENSION_SIZE;
    InitializationData.FdoData.DeviceType = FILE_DEVICE_DISK;
    InitializationData.FdoData.DeviceCharacteristics = FILE_DEVICE_SECURE_OPEN;
```

`DriverEntry` runs in the context of the system process, at `PASSIVE_LEVEL`, with the driver
section still pageable. It must:

1. Fill `DriverObject->DriverUnload` if the driver can be unloaded.
2. Fill `DriverObject->MajorFunction[]` for every `IRP_MJ_*` it handles.
3. Create at least one device object (`IoCreateDevice`) if it is not a pure library.
4. Return `STATUS_SUCCESS`, or a failure status that unloads the driver.

`DriverEntry` is placed in the discardable `INIT` section in the tree:

```c
#pragma alloc_text(INIT, DriverEntry)
```

## The dispatch table

```c
PDRIVER_DISPATCH MajorFunction[IRP_MJ_MAXIMUM_FUNCTION + 1];
```

Declared at `public/ddk/inc/wdm/wdm.h:11029`. A dispatch routine has this shape:

```c
NTSTATUS
DispatchPnp(
    IN PDEVICE_OBJECT DeviceObject,
    IN OUT PIRP Irp
    );
```

It reads the current stack location, decides whether to handle or pass down, and eventually calls
`IoCompleteRequest` or `IoCallDriver`. The IRP major codes, from `wdm.h:10189`:

| Code | Value | Meaning |
| --- | --- | --- |
| `IRP_MJ_CREATE` | `0x00` | `CreateFile` |
| `IRP_MJ_CREATE_NAMED_PIPE` | `0x01` | Named pipe create |
| `IRP_MJ_CLOSE` | `0x02` | Last handle closed |
| `IRP_MJ_READ` | `0x03` | `ReadFile` |
| `IRP_MJ_WRITE` | `0x04` | `WriteFile` |
| `IRP_MJ_QUERY_INFORMATION` | `0x05` | `GetFileInformationByHandle` |
| `IRP_MJ_SET_INFORMATION` | `0x06` | `SetFileInformationByHandle` |
| `IRP_MJ_QUERY_EA` | `0x07` | Extended attributes |
| `IRP_MJ_SET_EA` | `0x08` | Extended attributes |
| `IRP_MJ_FLUSH_BUFFERS` | `0x09` | `FlushFileBuffers` |
| `IRP_MJ_QUERY_VOLUME_INFORMATION` | `0x0A` | Volume query |
| `IRP_MJ_SET_VOLUME_INFORMATION` | `0x0B` | Volume set |
| `IRP_MJ_DIRECTORY_CONTROL` | `0x0C` | `FindFirstFile`/`FindNextFile` |
| `IRP_MJ_FILE_SYSTEM_CONTROL` | `0x0D` | FSCTL |
| `IRP_MJ_DEVICE_CONTROL` | `0x0E` | `DeviceIoControl` |
| `IRP_MJ_INTERNAL_DEVICE_CONTROL` | `0x0F` | Kernel-originated IOCTL |
| `IRP_MJ_SHUTDOWN` | `0x10` | Shutdown |
| `IRP_MJ_LOCK_CONTROL` | `0x11` | `LockFile`/`UnlockFile` |
| `IRP_MJ_CLEANUP` | `0x12` | Handle cleanup |
| `IRP_MJ_CREATE_MAILSLOT` | `0x13` | Mailslot create |
| `IRP_MJ_QUERY_SECURITY` | `0x14` | Security query |
| `IRP_MJ_SET_SECURITY` | `0x15` | Security set |
| `IRP_MJ_POWER` | `0x16` | Power IRP |
| `IRP_MJ_SYSTEM_CONTROL` | `0x17` | WMI |
| `IRP_MJ_DEVICE_CHANGE` | `0x18` | Device change |
| `IRP_MJ_QUERY_QUOTA` | `0x19` | Quota query |
| `IRP_MJ_SET_QUOTA` | `0x1A` | Quota set |
| `IRP_MJ_PNP` | `0x1B` | Plug and Play |

A driver that does not fill a slot gets the default `IopInvalidDeviceRequest`, which completes the
IRP with `STATUS_INVALID_DEVICE_REQUEST`. Fill every slot you do not handle with a pass-down or a
failure routine; leaving it at the default is a silent bug.

## The IRP

`IRP` is declared at `public/ddk/inc/wdm/wdm.h:11148`:

```c
typedef struct _IRP {
    CSHORT Type;
    USHORT Size;
    PMDL MdlAddress;
    ULONG Flags;
    union {
        struct _IRP *MasterIrp;
        LONG IrpCount;
        PVOID SystemBuffer;
    } AssociatedIrp;
    LIST_ENTRY ThreadListEntry;
    IO_STATUS_BLOCK IoStatus;
    ...
} IRP;
```

The fields you use:

| Field | Meaning |
| --- | --- |
| `MdlAddress` | MDL for direct I/O (device I/O, not buffered) |
| `AssociatedIrp.SystemBuffer` | System buffer for buffered I/O |
| `IoStatus` | Completion status and information |
| `Flags` | `IRP_PAGING_IO`, `IRP_SYNCHRONOUS_API`, ... |
| `Cancel` | Cancellation routine |
| `Tail.Overlay.CurrentStackLocation` | Current `IO_STACK_LOCATION` |
| `Tail.Overlay.DeviceQueueEntry` | Queue entry while pending |
| `UserBuffer` | Caller's output buffer for direct I/O |

`IO_STACK_LOCATION` (`wdm.h:11604`) holds the per-driver parameters: `MajorFunction`,
`MinorFunction`, `Parameters` (a union of `Create`, `Read`, `Write`, `DeviceIoControl`, `Pnp`,
`Power`, ...), `DeviceObject`, `FileObject`, `CompletionRoutine`, `Context`.

### The IRP lifecycle

```c
// 1. The I/O manager allocates and fills the IRP.
PIRP Irp = IoAllocateIrp(StackSize, FALSE);

// 2. The driver sets up its stack location.
PIO_STACK_LOCATION IrpSp = IoGetNextIrpStackLocation(Irp);
IrpSp->MajorFunction = IRP_MJ_READ;

// 3. The driver passes it down.
NTSTATUS status = IoCallDriver(LowerDeviceObject, Irp);

// 4. The lower driver completes it.
IoCompleteRequest(Irp, IO_NO_INCREMENT);
```

`IoCallDriver` is a macro that calls `IofCallDriver`, which is an indirection:

```c
// base/ntos/io/iomgr/iosubs.c:2273
NTSTATUS
FASTCALL
IofCallDriver(
    IN PDEVICE_OBJECT DeviceObject,
    IN OUT PIRP Irp
    )
{
    return pIofCallDriver(DeviceObject, Irp);
}
```

The real work is `IopfCallDriver`, and the verified variant is `IovCallDriver` in
`base/ntos/verifier`. The same pattern applies to `IofCompleteRequest` (line 3316).

### Completion

`IoCompleteRequest` walks the completion routines from the current stack location upward. A
completion routine can return:

| Return | Effect |
| --- | --- |
| `STATUS_SUCCESS` | Continue completion to the next routine |
| `STATUS_MORE_PROCESSING_REQUIRED` | Stop completion; the completion routine owns the IRP |
| `STATUS_CONTINUE_COMPLETION` | Same as `STATUS_SUCCESS` |

`STATUS_MORE_PROCESSING_REQUIRED` is the mechanism for a driver that needs to keep the IRP (for
example, to reuse it for a lower-level transfer). It must eventually call `IoCompleteRequest`
itself. Returning it and never completing the IRP is the classic "hung I/O with no visible owner".

`IopfCompleteRequest`'s header comment in `base/ntos/io/iomgr/complete.c` describes the walk, and
it is worth reading before writing a completion routine.

## Buffered, direct and neither

The I/O manager decides how user buffers reach the driver, based on the device object's `DO_BUFFERED_IO`
or `DO_DIRECT_IO` flag and the IOCTL's transfer type.

| Method | Buffer | Used by |
| --- | --- | --- |
| Buffered I/O | `Irp->AssociatedIrp.SystemBuffer` | `DO_BUFFERED_IO`, METHOD_BUFFERED |
| Direct I/O | `Irp->MdlAddress` mapped pages | `DO_DIRECT_IO`, METHOD_IN_DIRECT/METHOD_OUT_DIRECT |
| Neither | `Irp->UserBuffer` raw user pointer | METHOD_NEITHER; driver must probe |

For `IRP_MJ_READ`/`WRITE`, the device object's flags decide. For IOCTLs, the `DeviceIoControl`
method bits in the IOCTL code decide (`METHOD_BUFFERED`, `METHOD_IN_DIRECT`,
`METHOD_OUT_DIRECT`, `METHOD_NEITHER`). A driver that uses `METHOD_NEITHER` must probe the user
pointers with `ProbeForRead`/`ProbeForWrite` in a `try`/`except`.

## Plug and Play

A PnP driver receives `IRP_MJ_PNP` with a `MinorFunction`:

| Minor function | Meaning |
| --- | --- |
| `IRP_MN_START_DEVICE` | Resources assigned; start the device |
| `IRP_MN_QUERY_REMOVE_DEVICE` | Can the device be removed? |
| `IRP_MN_REMOVE_DEVICE` | Remove the device |
| `IRP_MN_CANCEL_REMOVE_DEVICE` | Cancel a pending removal |
| `IRP_MN_SURPRISE_REMOVAL` | Device disappeared without warning |
| `IRP_MN_QUERY_STOP_DEVICE` | Can the device be stopped? |
| `IRP_MN_STOP_DEVICE` | Stop the device |
| `IRP_MN_QUERY_PNP_DEVICE_STATE` | Query the PnP state |
| `IRP_MN_QUERY_DEVICE_RELATIONS` | Query parent/child relations |
| `IRP_MN_QUERY_ID` | Query hardware/instance IDs |
| `IRP_MN_QUERY_RESOURCES` | Query boot resources |
| `IRP_MN_QUERY_RESOURCE_REQUIREMENTS` | Query required resources |
| `IRP_MN_FILTER_RESOURCE_REQUIREMENTS` | Filter resource requirements |
| `IRP_MN_QUERY_CAPABILITIES` | Query device capabilities |

The rule for PnP IRPs: **pass unhandled ones down with `IoSkipCurrentIrpStackLocation` and
`IoCallDriver`**, and do not complete them yourself unless you own the request. The PnP manager
expects the whole stack to see them.

## Power

`IRP_MJ_POWER` carries `IRP_MN_WAIT_WAKE`, `IRP_MN_POWER_SEQUENCE`, `IRP_MN_SET_POWER`,
`IRP_MN_QUERY_POWER`. Power IRPs arrive at `PASSIVE_LEVEL` for system power and at
`DISPATCH_LEVEL` for device power. `PoCallDriver` is the required call for power IRPs because it
acquires the power lock; using `IoCallDriver` for a power IRP is a bug.

## DPCs, ISRs, timers and DMA

| Primitive | Purpose | Key routines |
| --- | --- | --- |
| DPC | Run work at `DISPATCH_LEVEL` after an ISR | `KeInitializeDpc`, `KeInsertQueueDpc` |
| ISR | Handle a device interrupt | `KeRegisterIsr`/`IoConnectInterrupt`, returns `TRUE` if handled |
| Timer | Periodic or one-shot kernel timer | `KeInitializeTimer`, `KeSetTimer` |
| Spin lock | Protect data at raised IRQL | `KeAcquireSpinLock`, `KeReleaseSpinLock` |
| DMA | Bus-master or slave transfers | `IoAllocateAdapterChannel`, `KeFlushIoBuffers`, `PutScatterGatherList` |
| Work item | Run work at `PASSIVE_LEVEL` | `IoAllocateWorkItem`, `IoQueueWorkItem` |
| Cancel-safe queue | Queue IRPs safely | `IoCsqInitialize`, `IoCsqInsertIrp` |

Rules that prevent the most common driver bugs:

- A DPC runs at `DISPATCH_LEVEL`; it must not touch pageable memory or block.
- An ISR runs at the device's SynchronIRQL; it must be short and must not allocate.
- A spin lock raises IRQL to `DISPATCH_LEVEL`; do not hold it across a pageable call.
- `KeAcquireSpinLock` and `KeReleaseSpinLock` must be paired in the same thread.

## Filesystem drivers

A filesystem registers with `IoRegisterFileSystem` and fills the same dispatch table. The tree's
NTFS example is in
[`base/fs/ntfs/ntfsinit.c:245`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/fs/ntfs/ntfsinit.c#L245):

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
```

The `Fsd` prefix means the routine may run in the requesting thread's context; `Fsp` routines run
in the filesystem's worker context. That distinction determines what you may do about blocking,
APCs and exception handling.

## NDIS miniports

`net/ndis/sys/configm.c:36` registers a miniport:

```c
NDIS_STATUS
NdisMRegisterMiniport(
    IN  NDIS_HANDLE             NdisWrapperHandle,
    IN  PNDIS_MINIPORT_CHARACTERISTICS MiniportCharacteristics,
    IN  UINT                    CharacteristicsLength
    )
```

`CharacteristicsLength` lets a newer NDIS wrapper accept an older, smaller characteristics block —
a versioning convention. A miniport fills the `NDIS_MINIPORT_CHARACTERISTICS` with
`InitializeHandler`, `ResetHandler`, `HaltHandler`, `SendHandler`, `SendPacketsHandler`,
`QueryInformationHandler`, `SetInformationHandler`, `ReturnPacketHandler` and the PnP handlers.

## A minimal driver skeleton

```c
#include <wdm.h>

VOID DriverUnload(IN PDRIVER_OBJECT DriverObject);
NTSTATUS DispatchCreateClose(IN PDEVICE_OBJECT DeviceObject, IN OUT PIRP Irp);
NTSTATUS DispatchDefault(IN PDEVICE_OBJECT DeviceObject, IN OUT PIRP Irp);

NTSTATUS
DriverEntry(
    IN PDRIVER_OBJECT DriverObject,
    IN PUNICODE_STRING RegistryPath
    )
{
    UNICODE_STRING name;
    RtlInitUnicodeString(&name, L"\\Device\\NeoWiki");

    PDEVICE_OBJECT deviceObject = NULL;
    NTSTATUS status = IoCreateDevice(DriverObject, 0, &name, FILE_DEVICE_UNKNOWN,
                                     FILE_DEVICE_SECURE_OPEN, FALSE, &deviceObject);
    if (!NT_SUCCESS(status)) {
        return status;
    }

    for (ULONG i = 0; i <= IRP_MJ_MAXIMUM_FUNCTION; i++) {
        DriverObject->MajorFunction[i] = DispatchDefault;
    }
    DriverObject->MajorFunction[IRP_MJ_CREATE]  = DispatchCreateClose;
    DriverObject->MajorFunction[IRP_MJ_CLOSE]   = DispatchCreateClose;
    DriverObject->DriverUnload = DriverUnload;

    return STATUS_SUCCESS;
}

VOID
DriverUnload(IN PDRIVER_OBJECT DriverObject)
{
    UNICODE_STRING link;
    RtlInitUnicodeString(&link, L"\\DosDevices\\NeoWiki");
    IoDeleteSymbolicLink(&link);
    if (DriverObject->DeviceObject) {
        IoDeleteDevice(DriverObject->DeviceObject);
    }
}

NTSTATUS
DispatchCreateClose(IN PDEVICE_OBJECT DeviceObject, IN OUT PIRP Irp)
{
    Irp->IoStatus.Status = STATUS_SUCCESS;
    Irp->IoStatus.Information = 0;
    IoCompleteRequest(Irp, IO_NO_INCREMENT);
    return STATUS_SUCCESS;
}

NTSTATUS
DispatchDefault(IN PDEVICE_OBJECT DeviceObject, IN OUT PIRP Irp)
{
    Irp->IoStatus.Status = STATUS_INVALID_DEVICE_REQUEST;
    Irp->IoStatus.Information = 0;
    IoCompleteRequest(Irp, IO_NO_INCREMENT);
    return STATUS_INVALID_DEVICE_REQUEST;
}
```

The skeleton is deliberately minimal, but it has the three properties every driver needs: a
complete dispatch table, a `DriverUnload`, and a device object with a symbolic link so user mode
can open it.

## DDI reference

| Function | Purpose | Documentation |
| --- | --- | --- |
| `IoCreateDevice` | Create a device object | [IoCreateDevice](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice) |
| `IoDeleteDevice` | Delete a device object | [IoDeleteDevice](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-iodeletedevice) |
| `IoCreateSymbolicLink` | Create a `\DosDevices` link | [IoCreateSymbolicLink](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatesymboliclink) |
| `IoDeleteSymbolicLink` | Remove the link | [IoDeleteSymbolicLink](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-iodeletesymboliclink) |
| `IoAllocateIrp` | Allocate an IRP | [IoAllocateIrp](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp) |
| `IoFreeIrp` | Free an IRP | [IoFreeIrp](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-iofreeirp) |
| `IoCallDriver` | Send an IRP down the stack | [IoCallDriver](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver) |
| `IoCompleteRequest` | Complete an IRP | [IoCompleteRequest](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest) |
| `IoGetNextIrpStackLocation` | Current stack location | [IoGetNextIrpStackLocation](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetnextirpstacklocation) |
| `IoSkipCurrentIrpStackLocation` | Skip a stack location | [IoSkipCurrentIrpStackLocation](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-ioskipcurrentirpstacklocation) |
| `IoSetCompletionRoutine` | Set a completion routine | [IoSetCompletionRoutine](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutine) |
| `IoStartPacket` / `IoStartNextPacket` | Serialize device queues | [IoStartPacket](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-iostartpacket) |
| `IoMarkIrpPending` | Mark an IRP pending | [IoMarkIrpPending](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-iomarkirppending) |
| `IoAcquireCancelSpinLock` | Cancel-routine lock | [IoAcquireCancelSpinLock](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-ioacquirecancelSpinLock) |
| `KeInitializeDpc` / `KeInsertQueueDpc` | DPC | [KeInitializeDpc](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc) |
| `KeSetTimer` | Timer | [KeSetTimer](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimer) |
| `KeAcquireSpinLock` | Spin lock | [KeAcquireSpinLock](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock) |
| `ExAllocatePoolWithTag` | Pool allocation | [ExAllocatePoolWithTag](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag) |
| `ProbeForRead` / `ProbeForWrite` | Probe user buffers | [ProbeForRead](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-probeforread) |
| `IoRegisterDriverReinitialization` | Re-initialise a driver | [IoRegisterDriverReinitialization](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdriverreinitialization) |

## Frequently asked questions

### Q: Why is `IofCallDriver` a one-line function?

Because it is an indirection so the I/O verifier can splice in its own `IovCallDriver`. The real
work is in `IopfCallDriver` (`base/ntos/io/iomgr/iosubs.c`). If you are debugging "IoCallDriver"
behaviour, the code you need is in `IopfCallDriver`, not the wrapper.

### Q: What happens if I do not fill a `MajorFunction` slot?

The I/O manager uses `IopInvalidDeviceRequest`, which completes the IRP with
`STATUS_INVALID_DEVICE_REQUEST`. That is a silent failure: the caller sees an error, and the driver
author never sees the request. Fill every slot.

### Q: Why must a PnP IRP be passed down?

Because the PnP manager sends it to the whole stack and expects each driver to participate. A
filter that completes `IRP_MN_QUERY_REMOVE_DEVICE` itself can make the device un-removable or crash
the stack. Pass unhandled PnP IRPs down with `IoSkipCurrentIrpStackLocation` + `IoCallDriver`.

### Q: What is `STATUS_MORE_PROCESSING_REQUIRED` for?

It stops the completion walk. A completion routine returns it when it needs to keep the IRP — for
example, to send it to a lower device or to reuse it. The completion routine then owns the IRP and
must complete it later. Returning it and forgetting is the classic I/O hang.

### Q: Can I call `IoCompleteRequest` at `DISPATCH_LEVEL`?

Yes, but the IRQL affects what `IoCompleteRequest` may do. At `DISPATCH_LEVEL` it cannot wait or
touch pageable memory. The `PriorityBoost` argument is still required.

### Q: Why is `DO_BUFFERED_IO` versus `DO_DIRECT_IO` a device-object flag?

Because the I/O manager needs to know how to build the IRP before the driver sees it. The flag is
set in `IoCreateDevice` (or by the class library). Changing it after the device is created has no
effect on already-queued IRPs.

### Q: Where is the filesystem driver contract documented?

`public/ifskit/inc/ntifs.h` is the IFS kit header, and `public/ifskit` holds the IFS samples and
documentation. `base/fs/ntfs` is a complete, real filesystem; `base/fs/fltsamples` holds the legacy
filter samples.

### Q: How do I add a driver to the build?

Add its directory to the parent `dirs`, give it a `sources` with `TARGETTYPE=DRIVER` (or
`MINIPORT`), and make sure its `TARGETLIBS` are already built and published. The build traversal
follows `dirs`, not the filesystem: a directory that is not in a `dirs` is never compiled. See
[Build, package and release](/build).

### Q: What IRQL does `DriverEntry` run at?

`PASSIVE_LEVEL`, in the context of the system process, with the driver's code and data pageable
until `DriverEntry` returns. That is why `DriverEntry` can call APIs that page-fault and why the
`INIT` section is discardable afterwards.

### Q: Where is the WDK DDI reference?

[https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/). The tree's headers are under
`public/ddk/inc`, and `wdm.h` is at `public/ddk/inc/wdm/wdm.h` — note the extra `wdm` directory,
not `public/ddk/inc/wdm.h`.
