---
title: Kernel and executive
sidebar_position: 4
description: The base/ntos managers, system-service dispatch from ntdll to the owning manager, object and handle lifetimes, pool, waits, DPCs, the memory-manager surface, and the official documentation for each kernel routine.
---

`base/ntos/` is the NT executive: the kernel proper plus the managers that run in kernel mode. It is
**not** the Win32 kernel — that is `windows/core`, covered in
[Win32, windowing and the shell](/win32-shell). This page maps every manager, shows where a system
service is implemented and how an `Nt*` call reaches it, and pairs the in-tree routines with their
official WDK documentation.

## Manager map

| Directory | Manager | Representative files in this checkout |
| --- | --- | --- |
| `ke` | Kernel / scheduler | `kiinit.c`, `dpcobj.c`, `dpcsup.c`, `eventobj.c`, `mutntobj.c`, `bugcheck.c`, `balmgr.c`, `channel.c` |
| `ps` | Processes and threads | `create.c`, `pscid.c`, `psenum.c`, `psjob.c`, `psimpers.c`, `psquota.c`, `security.c` |
| `mm` | Virtual memory | `mmfault.c`, `allocvm.c`, `mapview.c`, `freevm.c`, `modwrite.c`, `crashdmp.c`, `mi.h`, `miglobal.c` |
| `io` | I/O manager and PnP | `iomgr/iosubs.c`, `iomgr/create.c`, `iomgr/complete.c`, `pnpmgr/` |
| `ob` | Object manager | `obcreate.c`, `obhandle.c`, `obref.c`, `obinsert.c`, `obtype.c`, `ob.txt` |
| `ex` | Executive support, pool, time | `pool.c` |
| `se` | Security reference monitor | `accessck.c`, `token.c`, `adtlog.c` — see [Security](/security-directory) |
| `config` | Registry | `cmboot.c`, `cmapi.c`, `cmapi2.c`, `cmdelay.c`, `chkreg/` |
| `cache` | Cache manager | see `base/ntos/cache` |
| `lpc` | Local procedure calls | `lpccreat.c`, `lpcsend.c`, `lpcrecv.c`, `lpcreply.c`, `lpclistn.c` |
| `po` | Power manager | see `base/ntos/po` |
| `dbgk` | User-mode debugging | see `base/ntos/dbgk` |
| `kd64` | Kernel debugger | `kdinit.c`, `kdbreak.c`, `kdapi.c`, `kddbgio.c`, `print.c` |
| `verifier` | Driver Verifier hooks | `vfirp.c`, `vfdeadlock.c`, `vfddi.c`, `vfstack.c`, `vfpnp.c`, `vfpower.c` |
| `fsrtl`, `fstub`, `raw` | Filesystem runtime and stubs | shared by every filesystem driver |
| `rtl` | Kernel runtime library | string, unicode, security descriptor helpers |
| `arb` | Resource arbiters | bus-resource allocation for PnP |
| `wmi`, `perf` | Instrumentation | WMI provider support, performance counters |
| `init` | Kernel start-up and link configuration | `init.c`, `up/`, `mp/`, `pae/`, `paemp/` |

Each manager directory holds architecture subdirectories (`i386`, `amd64`, `ia64`, `alpha`,
`axp64`) and `up` / `mp` / `pae` / `paemp` variants, plus a `sources.inc` that the variant nodes
include.

## Where a system service lives

System services are implemented by the manager that owns the resource, not in `ntdll` and not in a
single dispatcher file. `NtCreateFile` is in the I/O manager:

```c
// base/ntos/io/iomgr/create.c:37
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

and it is explicitly paged:

```c
#ifdef ALLOC_PRAGMA
#pragma alloc_text(PAGE, NtCreateFile)
#pragma alloc_text(PAGE, NtCreateNamedPipeFile)
#pragma alloc_text(PAGE, NtCreateMailslotFile)
#endif
```

`#pragma alloc_text(PAGE, ...)` moves a routine into the pageable `PAGE` section. Routines that can
run at raised IRQL, in a DPC or during a crash must **not** be paged — that is why `IofCallDriver`
and `IofCompleteRequest` are `FASTCALL` and unpaged while `NtCreateFile` is pageable.

## How an `Nt*` call reaches the manager

The route from `ntdll` to `NtCreateFile` is generated at build time from a text list. The list is
[`base/ntos/ke/services.tab`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/services.tab)
— 284 lines of `Name,argbytes`, one per system service:

```text
AcceptConnectPort,6
AccessCheck,8
...
Close,1
...
CreateFile,11
...
CreateProcess,8
...
DuplicateObject,7
...
OpenProcess,4
...
QuerySystemInformation,4
```

`CreateFile,11` means the service is called `NtCreateFile` and takes 11 arguments. The build step is
in [`base/ntos/ke/up/makefile.inc`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/up/makefile.inc):

```bat
$(O)\sysstubs.$(ASM_SUFFIX) $(O)\systable.$(ASM_SUFFIX): $(SERVICES_TAB) ..\$(TARGET_DIRECTORY)\table.stb ..\$(TARGET_DIRECTORY)\services.stb
    gensrv -d $(O) -e $(ASM_SUFFIX) -g $(SERVICES_DIR) $(TARGET_BRACES) -s ..\$(TARGET_DIRECTORY)
```

`gensrv` is checked in at
[`sdktools/gensrv/gensrv.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/sdktools/gensrv/gensrv.c).
It reads `services.tab` and two macro files — `base/ntos/ke/<arch>/table.stb` and
`base/ntos/ke/<arch>/services.stb` — and emits `sysstubs.asm` (the user-mode stubs that become
`ntdll`) and `systable.asm` (the kernel's dispatch table). The `TABLE_ENTRY` macro in
[`base/ntos/ke/i386/table.stb`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/i386/table.stb)
shows exactly what is emitted per service:

```asm
TABLE_ENTRY macro l,bias,numargs
        Local   Bytes

        Bytes = numargs*4

        EXTRNP  _Nt&l,&numargs
IFDEF STD_CALL
        ComposeInst <dd offset FLAT:>,_Nt,l,<@>,%(Bytes)
ELSE
        dd offset FLAT:_Nt&l
ENDIF
endm
```

That single `dd offset FLAT:_Nt&l` line is the service table entry: the address of the manager's
implementation. The same file closes the table with `_KiServiceLimit` and opens `_KiArgumentTable`.

Dispatch is assembly. In
[`base/ntos/ke/i386/trap.asm`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/i386/trap.asm):

```asm
        extrn   _KeServiceDescriptorTable:dword          ; line 52
        extrn   _KeServiceDescriptorTableShadow:dword    ; line 105
...
IDTEntry        _KiSystemService, D_INT332          ;2E: system service calls   ; line 416
```

`int 2Eh` lands in `KiSystemService`; the fast path is `KiFastCallEntry` (line 1049, via
`SYSENTER`). Line 1013 shows the win32k twist:

```asm
        lea     edx, _KeServiceDescriptorTableShadow + SERVICE_TABLE_TEST ;
```

`KeServiceDescriptorTableShadow` carries the second service table — the one `win32k.sys` registers —
so an `NtUser*` call dispatches through the same mechanism but a different table. That table is
built the same way from
[`windows/core/kmode/services.tab`](https://github.com/havaianasdestruido/neo-nt5/blob/main/windows/core/kmode/services.tab)
(750 entries, `Gdi*` and `NtUser*` stubs, each line `Stub,NumParams[,ErrRetVal]`).

### `Nt` versus `Zw`

They are the same routine in kernel mode and different entry paths from user mode. The official
documentation for `NtCreateFile` states it plainly:

> If the call to this function occurs in user mode, you should use the name "**NtCreateFile**"
> instead of "**ZwCreateFile**".
> — [NtCreateFile function (ntifs.h), Microsoft Learn](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)

From user mode, `NtCreateFile` and `ZwCreateFile` are two ntdll stubs that enter the kernel
identically. From kernel mode, `ZwCreateFile` sets `PreviousMode = KernelMode` on the way in, which
skips user-mode argument probing — while `NtCreateFile` called from kernel mode keeps whatever
previous mode the caller had. **Consequence for driver code:** use the `Zw` form when calling from
kernel mode if you want kernel-mode semantics; the access check and probing behaviour differ.

## Object and handle lifetimes

Handles are references counted in two places: a handle-table entry (per process) and a
pointer count (per object). `ObReferenceObjectByHandle`, at
[`base/ntos/ob/obref.c:1044`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ob/obref.c),
is the canonical bridge between them:

```c
NTSTATUS
ObReferenceObjectByHandle (
    IN HANDLE Handle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_TYPE ObjectType OPTIONAL,
    IN KPROCESSOR_MODE AccessMode,
    OUT PVOID *Object,
    OUT POBJECT_HANDLE_INFORMATION HandleInformation OPTIONAL
    )
```

It performs the access check against `DesiredAccess`, validates the object type when one is given,
increments the pointer count, and returns the object body. Every successful call must be balanced
with `ObDereferenceObject` (`base/ntos/ob/obref.c:2665`); leaking the pointer count is a
handle-independent leak that no handle audit will find.

The manager's other pillars in this checkout:

| Routine | Location | Role |
| --- | --- | --- |
| `ObOpenObjectByName` | `base/ntos/ob/obref.c:591` | Name lookup → handle, the path behind every `NtOpen*` |
| `ObInsertObject` | `base/ntos/ob/obinsert.c:29` | Insert a new object into the namespace, optionally make a handle |
| `ObAssignSecurity` | `base/ntos/ob/obse.c:1487` | Assign a security descriptor at creation, delegating to `SeAssignSecurity` (`base/ntos/se/seassign.c:90`) |
| `ObFindHandleForObject` | `base/ntos/ob/obinit.c` | The routine behind handle audits — find the handle that references an object |

The object manager keeps its own in-tree documentation.
[`base/ntos/ob/ob.txt`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ob/ob.txt)
is a 1,896-line breakdown of what each module exports:

```text
    obinit.c    KMUTANT ObpInitKillMutant;
                UNICODE_STRING ObpDosDevicesShortName;
                PDEVICE_MAP ObSystemDeviceMap

                ObInitSystem (
                ObInitProcess (
                ObKillProcess (
                ObFindHandleForObject (

    obhandle.c  NtDuplicateObject (
                ObpIncrPointerCount (
                ObpDecrPointerCountWithResult (
                ObpCreateHandle (
                ObpTranslateGrantedAccessIndex (

    obref.c     ObOpenObjectByName (
                ObOpenObjectByPointer (
```

Read it before changing object-manager internals — it names the private (`Obp`) routines that carry
the invariants.

## Threads and processes

Kernel worker threads are created through the process manager, at
[`base/ntos/ps/create.c:184`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ps/create.c):

```c
NTSTATUS
PsCreateSystemThread(
    OUT PHANDLE ThreadHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
    IN HANDLE ProcessHandle OPTIONAL,
    OUT PCLIENT_ID ClientId OPTIONAL,
    IN PKSTART_ROUTINE StartRoutine,
    IN PVOID StartContext
    )
```

Passing `NULL` for `ProcessHandle` puts the thread in the initial system process. The returned
handle is a real handle and must be closed with `ZwClose`, or the thread object leaks even after the
thread exits. The official documentation adds the operational contract the signature cannot show:
the thread runs at `PASSIVE_LEVEL` in the system process context, and the `StartRoutine` must
terminate with `PsTerminateSystemThread` — see
[PsCreateSystemThread function (wdm.h), Microsoft Learn](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-pscreatesystemthread).

The same file owns the user-visible creation services:

| Service | Location | Notes |
| --- | --- | --- |
| `NtCreateThread` | `base/ntos/ps/create.c:86` | The thread-creation service |
| `NtCreateProcess` | `base/ntos/ps/create.c:847` | The process-creation service |
| `PspCreateProcess` | `base/ntos/ps/create.c:1008` | The private worker both go through |

`CreateProcessW` in `kernel32` does much more than `NtCreateProcess`: it creates the section,
initial thread, and startup context before entering the kernel — see
[Win32, windowing and the shell](/win32-shell) for that half.

## Pool allocation: types, tags and quotas

Pool is tagged and typed. The canonical allocator is `ExAllocatePoolWithTag`, at
[`base/ntos/ex/pool.c:1080`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ex/pool.c):

```c
PVOID
ExAllocatePoolWithTag (
    IN POOL_TYPE PoolType,
    IN SIZE_T NumberOfBytes,
    IN ULONG Tag
    )
```

The same file defines `ExAllocatePoolWithTagPriority` (line 2111), `ExAllocatePoolWithQuotaTag`
(line 2273), `ExFreePoolWithTag` (line 3033) and the untagged `ExFreePool` (line 3708).

The official WDK documentation states the contract precisely:

> **ExAllocatePoolWithTag** routine allocates pool memory of the specified type and returns a pointer
> to the allocated block.
>
> ```cpp
> PVOID ExAllocatePoolWithTag(
>   [in] __drv_strictTypeMatch(__drv_typeExpr)POOL_TYPE PoolType,
>   [in] SIZE_T                                         NumberOfBytes,
>   [in] ULONG                                          Tag
> );
> ```
>
> Specify the pool tag as a non-zero character literal of one to four characters delimited by single
> quotation marks (for example, 'Tag1'). The string is usually specified in reverse order (for
> example, '1gaT'). Each allocation code path should use a unique pool tag to help debuggers and
> verifiers identify the code path.
>
> Callers of **ExAllocatePoolWithTag** must be executing at IRQL \<= DISPATCH\_LEVEL. A caller
> executing at DISPATCH\_LEVEL must specify a **NonPaged** *Xxx* value for *PoolType*.
>
> — [ExAllocatePoolWithTag function (wdm.h), Microsoft Learn](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

Facts from that page that matter for code in *this* tree:

| Rule | Why it matters here |
| --- | --- |
| Allocations `\< PAGE_SIZE` stay inside one page and are 8-byte (x86) / 16-byte (x64) aligned | Structure packing assumptions in `base/ntos/ex/pool.c` callers |
| Zero-length allocations are flagged by Driver Verifier | `vfirp.c` and friends will complain before you will |
| Allocated memory is **uninitialized** | A buffer later copied to user mode must be zeroed first |
| The tag is stored little-endian — `'Fred'` shows as `derF` in pool dumps | What you type is not what `poolmon` displays |
| `NULL` return means out of pool | This era's code returns `NULL`; it does not raise (unless `POOL_RAISE_IF_ALLOCATION_FAILURE` is OR-ed in) |

The four-character tag is what pool-mon and the crash dump show, so a new allocation site should use
a tag that identifies its component rather than reusing a generic one. In this checkout the tree's
own allocations model the convention — search a component for existing tags before inventing one:

```bash
rg -n "ExAllocatePoolWithTag\(" base/ntos/io | head
rg -o "ExAllocatePoolWithTag\([^,]+,[^,]+, '[^']{4}'" base/ntos -g '*.c' | head
```

`ExAllocatePoolWithQuotaTag` charges the allocation against the process quota
(`base/ntos/ps/psquota.c` maintains the counters), which is why user-triggered allocations in the
I/O path use the quota variant: a runaway application hits its quota instead of exhausting system
pool.

## Dispatcher objects and waits

Events, mutants (mutexes), semaphores, threads and timers are all dispatcher objects, and the wait
machinery is shared. The three anchors in `base/ntos/ke`:

| Routine | Location |
| --- | --- |
| `KeInitializeEvent` | [`base/ntos/ke/eventobj.c:56`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/eventobj.c) |
| `KeSetEvent` | [`base/ntos/ke/eventobj.c:346`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/eventobj.c) |
| `KeInitializeMutex` | [`base/ntos/ke/mutntobj.c:99`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/mutntobj.c) |
| `KeWaitForSingleObject` | [`base/ntos/ke/wait.c:914`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/wait.c) |

The official WDK page for the wait is the contract every caller must satisfy:

> **KeWaitForSingleObject** routine puts the current thread into a wait state until the given
> dispatcher object is set to a signaled state or (optionally) until the wait times out.
>
> ```cpp
> NTSTATUS KeWaitForSingleObject (
>     PVOID Object,
>     KWAIT_REASON WaitReason,
>     KPROCESSOR_MODE WaitMode,
>     BOOLEAN Alertable,
>     PLARGE_INTEGER Timeout
>     );
> ```
>
> *Timeout* — A positive value specifies an absolute time, relative to January 1, 1601. A negative
> value specifies an interval relative to the current time. […] If \**Timeout* = 0, the routine
> returns without waiting. If the caller supplies a **NULL** pointer, the routine waits indefinitely.
>
> Callers of **KeWaitForSingleObject** must be running at IRQL \<= DISPATCH\_LEVEL. However, if
> *Timeout* = **NULL** or \**Timeout* != 0, the caller must be running at IRQL \<= APC\_LEVEL and in
> a nonarbitrary thread context.
>
> — [KeWaitForSingleObject function (wdm.h), Microsoft Learn](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)

Return values are `STATUS_SUCCESS`, `STATUS_ALERTED`, `STATUS_USER_APC` and `STATUS_TIMEOUT` — and
the documentation is explicit that all four count as "success" for `NT_SUCCESS`, so code that waits
alertable or in user mode **must** check which one came back. A mutex wait has the extra rule that
once the mutex is held, only special kernel APCs are delivered until it is released.

The rest of the primitive set, all in `base/ntos/ke`:

```bash
rg -n '^Ke[A-Za-z]*(Event|Mutex|Semaphore|SpinLock|Timer|Dpc)' base/ntos/ke -g '*.c'
```

## DPCs and raised IRQL

Deferred procedure calls run at `DISPATCH_LEVEL`, on the processor that queued them. The lifecycle
is three routines in [`base/ntos/ke/dpcobj.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/dpcobj.c):

```c
VOID KeInitializeDpc (          // line 44
    IN PRKDPC Dpc,
    IN PKDEFERRED_ROUTINE DeferredRoutine,
    IN PVOID DeferredContext
    );

BOOLEAN KeInsertQueueDpc (      // line 94
    IN PRKDPC Dpc,
    IN PVOID SystemArgument1,
    IN PVOID SystemArgument2
    );
```

Rules that follow from the IRQL, and that the tree's own code follows:

1. A DPC routine must not block, must not touch pageable memory, and must not call anything whose
   documented maximum IRQL is below `DISPATCH_LEVEL`.
2. `KeAcquireSpinLock` raises to `DISPATCH_LEVEL`; anything under that lock is in DPC rules
   whether or not it is a DPC routine.
3. Per-processor work goes through `KeSetTargetProcessorDpc`; time-based work through `KTIMER`
   (`KeInitializeTimerEx` in `base/ntos/ke/dpcobj.c`'s sibling timer object code) which expires by
   queueing a DPC.

This is the second half of the paging rule from earlier: `#pragma alloc_text(PAGE, ...)` code can
never be on a DPC or spin-lock path.

## The memory-manager surface

The `mm` manager's exported surface, with this checkout's locations:

| Routine | Location | Typical caller |
| --- | --- | --- |
| `MmProbeAndLockPages` | [`base/ntos/mm/iosup.c:231`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/mm/iosup.c) | Drivers pinning user buffers before DMA |
| `MmMapLockedPagesSpecifyCache` | `base/ntos/mm/iosup.c:2980` | Mapping an MDL into another process or kernel space |
| `MmMapLockedPages` | `base/ntos/mm/iosup.c:3486` | The older sibling of the above |
| `MmMapIoSpace` | `base/ntos/mm/iosup.c:6032` | Mapping device registers into the kernel |
| `MmCreateSection` | [`base/ntos/mm/creasect.c:389`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/mm/creasect.c) | Section objects — the backing of `NtCreateSection`, images and paging files |
| `MmMapViewOfSection` | [`base/ntos/mm/mapview.c:746`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/mm/mapview.c) | Mapping a section into a process — also on the `win32k` import list |

The fault path itself is `base/ntos/mm/mmfault.c`; pagefile and modified-page writing is
`modwrite.c`; crash-dump support is `crashdmp.c`. The official IRQL rules for these are
per-routine — `MmMapIoSpace` is `IRQL <= DISPATCH_LEVEL` with nonpaged arguments,
`MmProbeAndLockPages` requires `IRQL <= APC_LEVEL` — so each call site must be checked against the
WDK page, not against a general rule. Start at
[wdm.h routines by IRQL, Microsoft Learn](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/introduction-to-wdm-routines-by-irql)
when in doubt.

## The registry inside the kernel

`base/ntos/config` is the configuration manager — the registry implementation. `cmboot.c` loads the
boot hives, `cmapi.c` / `cmapi2.c` implement the `Nt*Key` services (`CreateKey`, `OpenKey`,
`SetValueKey`, … all in `services.tab`), `cmdelay.c` handles delayed writes, and `chkreg/` holds
registry checking tools. A registry *policy* read by a service is not a kernel change; a change to
hive layout, quota or notification semantics is. `base/ntos/config/boot` holds the boot-hive pieces
that must agree with `base/ntsetup`.

## References

Official Microsoft documentation for the routines on this page (external links; content is
Microsoft's):

| Routine / topic | Official documentation |
| --- | --- |
| `ZwCreateFile` / `NtCreateFile` | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntddk/nf-ntddk-zwcreatefile](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntddk/nf-ntddk-zwcreatefile), [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile) |
| `ExAllocatePoolWithTag` | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag) |
| `ExFreePoolWithTag` | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreepoolwithtag](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreepoolwithtag) |
| `KeWaitForSingleObject` | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject) |
| `KeInitializeEvent` / `KeSetEvent` | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializeevent](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializeevent), [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetevent](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetevent) |
| `KeInitializeDpc` / `KeInsertQueueDpc` | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc), [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertqueuedpc](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertqueuedpc) |
| `PsCreateSystemThread` | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-pscreatesystemthread](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-pscreatesystemthread) |
| `ObReferenceObjectByHandle` | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-obreferenceobjectbyhandle](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-obreferenceobjectbyhandle) |
| `MmMapIoSpace` / `MmProbeAndLockPages` | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-mmapiospace](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-mmapiospace), [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages) |
| Routines by IRQL | [https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/introduction-to-wdm-routines-by-irql](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/introduction-to-wdm-routines-by-irql) |
| Pool tags and `poolmon` | [https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/poolmon](https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/poolmon) |
| Waits and APCs | [https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/waits-and-apcs](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/waits-and-apcs) |

In-tree documents worth reading before touching a manager:

| Document | What it covers |
| --- | --- |
| [`base/ntos/ob/ob.txt`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ob/ob.txt) | Object-manager module exports and private invariants |
| [`base/ntos/ke/i386/table.stb`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/i386/table.stb) | How `KiServiceTable` is generated |
| [`base/ntos/ke/services.tab`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/services.tab) | The system-service list itself |
| [`sdktools/gensrv/gensrv.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/sdktools/gensrv/gensrv.c) | The generator's parsing rules |
| `base/ntos/init/w32kexps.txt` | The kernel→win32k export contract (see [Win32](/win32-shell#the-win32k-import-contract)) |

## Frequently asked questions

### Q: How do I find every implementation of a system service?

Search for the `Nt`-prefixed definition, and remember the `Zw` alias is the same routine from kernel
mode:

```bash
rg -n '^NtCreateFile' base/ntos
rg -n '^Ob[A-Za-z]+\s*\(' base/ntos/ob
rg -n '#pragma alloc_text\(PAGE' base/ntos/io
```

`rg -n '^IofCallDriver' base/ntos/io` returns exactly one hit — `base/ntos/io/iomgr/iosubs.c:2273` —
which is a good sanity check that your search pattern is anchored to definitions rather than calls.
To see whether a name is a *service* at all, check `base/ntos/ke/services.tab`; to see its argument
size, read the number after the comma.

### Q: `IofCallDriver` is one line. Is that the real implementation? {#iofcalldriver-indirection}

No. It is a dispatcher indirection so the I/O verifier can be spliced in at run time:

```c
// base/ntos/io/iomgr/iosubs.c:2273
NTSTATUS
FASTCALL
IofCallDriver(
    IN PDEVICE_OBJECT DeviceObject,
    IN OUT PIRP Irp
    )
{
    //
    // This routine will either jump immediately to IopfCallDriver, or rather
    // IovCallDriver.
    //
    return pIofCallDriver(DeviceObject, Irp);
}
```

The real work is in `IopfCallDriver`, and the verified variant is `IovCallDriver` in
`base/ntos/verifier`. The same pattern applies to `IofCompleteRequest` (line 3316) and
`IopfCompleteRequest`. If you are fixing a bug "in `IoCallDriver`", you almost certainly mean one of
those two. The official documentation confirms the indirection is deliberate — `IoCallDriver` is a
macro that wraps `IofCallDriver` and callers are told "Do not call **IofCallDriver**. Call
**IoCallDriver** instead" ([IoCallDriver macro (wdm.h), Microsoft Learn](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)).

### Q: What runs at page-fault time, and what must not be paged?

Anything reachable from the fault path or from raised IRQL. Concretely, in this tree:
`base/ntos/mm/mmfault.c` handles the fault, and code paged with `#pragma alloc_text(PAGE, ...)` is
excluded from it. Rules of thumb drawn from the code:

```c
// pageable: system-service entry points that touch no pageable memory afterwards
#pragma alloc_text(PAGE, NtCreateFile)

// NOT pageable: dispatch and completion paths, DPC routines, cancel routines
NTSTATUS FASTCALL IofCallDriver(IN PDEVICE_OBJECT, IN OUT PIRP);
```

If you add a routine that a DPC, a completion routine or a spin-lock region calls, do not add it to
an `alloc_text(PAGE, ...)` list.

### Q: A handle audit shows no leak, but memory grows. Where do I look?

Pointer counts and quota, not the handle table. Three places to instrument:

```bash
# object pointer accounting
rg -n 'ObpIncrPointerCount|ObpDecrPointerCountWithResult' base/ntos/ob/obhandle.c
# per-process quota
rg -n 'PsChargeProcess|PspReturnQuota' base/ntos/ps/psquota.c
# pool by tag
rg -n 'ExAllocatePoolWithTag' base/ntos/ex/pool.c
```

A missing `ObDereferenceObject` after a successful `ObReferenceObjectByHandle` produces exactly this
symptom: handles look clean, the object never goes away. For pool, the WDK's advice is the tool
chain: turn on special pool for the tag with `gflags`, then track it with `poolmon` — both are in
this tree (`sdktools/gflags`, and the WDK's poolmon is the consumer of the same tag data).

### Q: Why does the tag I passed appear backwards in the dump?

Because the documentation says so: the tag is stored little-endian, so a caller passing `'Fred'`
sees `derF` in pool dumps and `0x64657246` in registry and tool displays
([ExAllocatePoolWithTag](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag),
*Remarks*). Write tags in reverse when that makes the dump readable, and keep the four characters in
the `0x20`–`0x7E` range.

### Q: How does the registry fit into the kernel?

`base/ntos/config` is the configuration manager — the registry implementation. `cmboot.c` loads the
boot hives, `cmapi.c` / `cmapi2.c` implement the `Nt*Key` services, `cmdelay.c` handles delayed
writes, and `chkreg/` holds registry checking tools. A registry *policy* read by a service is not a
kernel change; a change to hive layout, quota or notification semantics is. `base/ntos/config/boot`
holds the boot-hive pieces that must agree with `base/ntsetup`.

### Q: Is the debugger in the kernel?

`base/ntos/kd64` is the kernel debugger stub compiled into the kernel; the debugger *client* is
external. The boot-time transports live elsewhere: `base/boot/kdcom` (serial) and `base/boot/kd1394`
(1394). Kernel-mode support for the `!` extensions of individual components is in per-component
`kdext`/`kdexts` folders — for example `net/tcpip/driver/kdext`, `drivers/storage/kdext` and
`windows/core/ntuser/kdexts`. See [Tests, diagnostics and debugging](/testing-debugging).

### Q: Why does `base/ntos` have its own `makefil0` and `project.mk`?

Because `ntos` is a project with project-wide macros, not just a directory. `base/ntos/ntoskrnl.inc`
is included by the link-configuration nodes (`up`, `mp`, `pae`, `paemp`) and carries the kernel-wide
settings, while `project.mk` sets project-level paths. Changing one of those files changes every
kernel binary at once — which is exactly why such an edit needs a stated reason and a build of all
four configurations.

### Q: Where do I look to understand a raw system-call number?

Nowhere in this tree as a fixed constant. The service number of `NtCreateFile` is its position in
the generated table, which comes from the order of
[`base/ntos/ke/services.tab`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/services.tab).
Any table of hard-coded numbers you find elsewhere describes some *other* build. The honest way to
get a number for this source is to run `gensrv`'s pipeline and read `systable.asm`'s order — see
[The native API](/native-api) for the full walk-through.
