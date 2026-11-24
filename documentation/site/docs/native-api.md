---
title: The native API (Nt/Zw)
sidebar_position: 12
description: The NT system services — how services.tab and gensrv build the syscall tables, Nt versus Zw semantics, where every major Nt* service is implemented in this tree, and the official documentation for each.
---

The **native API** is the interface `ntdll` exposes to user mode and kernel drivers use through the
`Zw` aliases: the `Nt*` system services. In this tree the service list is not a spreadsheet or a
wiki — it is a checked-in text file that the build compiles into both ends of every system call. This
page documents that mechanism and maps the major services to their implementations and official
documentation. The related guides are
[Kernel and executive](/kernel#how-an-nt-call-reaches-the-manager) (dispatch internals) and
[Windows API to source map](/api-source-map) (the Win32 layer above).

## The service list is source

[`base/ntos/ke/services.tab`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/services.tab)
is 284 lines of `Name,argbytes` — the name without its `Nt` prefix, and the size in bytes of the
*in-memory* arguments:

```text
AllocateVirtualMemory,6        Close,1                 CreateFile,11
CreateKey,7                    CreateProcess,8         CreateSection,7
CreateThread,8                 DelayExecution,2        DuplicateObject,7
LoadDriver,1                   OpenFile,6              OpenProcess,4
QueryInformationProcess,5      QuerySystemInformation,4
ReadFile,9                     SetInformationThread,4  SetValueKey,6
SystemDebugControl,6           WaitForSingleObject,3   WriteFile,9
YieldExecution,0
```

(`YieldExecution,0` — zero bytes of arguments — is the clean proof that the number is argument
bytes, not parameter count: `NtYieldExecution` takes no arguments at all.)

The build rule is in [`base/ntos/ke/up/makefile.inc`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/up/makefile.inc):

```bat
$(O)\sysstubs.$(ASM_SUFFIX) $(O)\systable.$(ASM_SUFFIX): $(SERVICES_TAB) ..\$(TARGET_DIRECTORY)\table.stb ..\$(TARGET_DIRECTORY)\services.stb
    gensrv -d $(O) -e $(ASM_SUFFIX) -g $(SERVICES_DIR) $(TARGET_BRACES) -s ..\$(TARGET_DIRECTORY)
```

`gensrv` ([`sdktools/gensrv/gensrv.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/sdktools/gensrv/gensrv.c))
preprocesses `services.tab`, merges it with the macro files `table.stb` and `services.stb` for the
target architecture, and emits two assembly files:

| Output | Contents | Consumed by |
| --- | --- | --- |
| `sysstubs.asm` | One `Nt*` stub per service (the `STUBS_*` macros in `services.stb`) | `ntdll` — the user-mode entry points |
| `systable.asm` | `KiServiceTable`, `KiArgumentTable`, `KiServiceLimit` | the kernel — the dispatch table |

The `TABLE_ENTRY` macro in
[`base/ntos/ke/i386/table.stb`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/i386/table.stb)
is what each table row becomes:

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

The comment at the top of that file is the whole authoring guide:

```text
; To add a system service simply add the name of the service to the below
; table. If the system service has arguments, then immediately
; follow the name of the serice with a comma and following that the number
; of bytes of in memory arguments, e.g. CreateObject,40.
```

## Dispatch: from stub to manager

On x86 the user-mode stub enters through `int 2Eh` or `SYSENTER`:

```asm
; base/ntos/ke/i386/trap.asm
        extrn   _KeServiceDescriptorTable:dword          ; line 52
        extrn   _KeServiceDescriptorTableShadow:dword    ; line 105
IDTEntry        _KiSystemService, D_INT332          ;2E: system service calls   ; line 416
```

`KiSystemService` (and `KiFastCallEntry`, line 1049) takes the service number from `EAX`, looks the
address up in `KeServiceDescriptorTable` (or `KeServiceDescriptorTableShadow` for win32k services —
line 1013), probes and copies the arguments using `KiArgumentTable`, and calls the manager's
`Nt*` implementation. Consequences worth knowing:

1. **A service number is not a constant.** It is the position of the name in `services.tab` at the
   build that produced the kernel. Any published syscall-number table describes some other build.
2. **The `Nt`/`Zw` pair share one implementation.** `services.tab` names one routine per line; the
   two exported names are two stubs into it.
3. **Argument probing depends on the entry mode**, which is the real `Nt` versus `Zw` difference.

## `Nt` versus `Zw`

The official documentation states the rule directly:

> If the call to this function occurs in user mode, you should use the name "**NtCreateFile**"
> instead of "**ZwCreateFile**".
> — [NtCreateFile function (ntifs.h), Microsoft Learn](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)

| Caller | `NtXxx` | `ZwXxx` |
| --- | --- | --- |
| User mode | Normal stub; arguments probed | Identical entry (alias) |
| Kernel mode | Probes arguments as user-mode (previous mode is inherited) | Sets `PreviousMode = KernelMode` — no probing |

So kernel code that passes kernel pointers to a service must call the `Zw` form; code that
deliberately wants user-mode probing semantics calls the `Nt` form. The WDK documents the kernel
routines under their `Zw` names — for example
[ZwCreateFile](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntddk/nf-ntddk-zwcreatefile)
— and the SDK documents the subset Microsoft exposes to user mode under `winternl.h` — for example
[NtCreateFile](https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ntcreatefile).
Everything not in those headers is still exported from `ntdll` in this tree's builds, but is not a
supported application contract.

## Where the major services are implemented

Every row verified in this checkout; `Arg bytes` is the `services.tab` value:

| Service | `Arg bytes` | Implementation | Official documentation |
| --- | --- | --- | --- |
| `NtCreateFile` | 11 | [`base/ntos/io/iomgr/create.c:37`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/io/iomgr/create.c) | [ntifs](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile) / [winternl](https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ntcreatefile) / [Zw](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntddk/nf-ntddk-zwcreatefile) |
| `NtOpenFile` | 6 | [`base/ntos/io/iomgr/open.c:34`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/io/iomgr/open.c) | [ZwOpenFile](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwopenfile) |
| `NtReadFile` | 9 | [`base/ntos/io/iomgr/read.c:39`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/io/iomgr/read.c) | [ZwReadFile](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwreadfile) |
| `NtWriteFile` | 9 | [`base/ntos/io/iomgr/write.c:35`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/io/iomgr/write.c) | [ZwWriteFile](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwwritefile) |
| `NtCreateSection` | 7 | [`base/ntos/mm/creasect.c:136`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/mm/creasect.c) | [ZwCreateSection](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwcreatesection) |
| `NtAllocateVirtualMemory` | 6 | [`base/ntos/mm/allocvm.c:83`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/mm/allocvm.c) | [ZwAllocateVirtualMemory](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwallocatevirtualmemory) |
| `NtCreateThread` | 8 | [`base/ntos/ps/create.c:86`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ps/create.c) | — (kernel-side only in the WDK set) |
| `NtCreateProcess` | 8 | [`base/ntos/ps/create.c:847`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ps/create.c) | — |
| `NtOpenProcess` | 4 | [`base/ntos/ps/psopen.c:30`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ps/psopen.c) | [winternl](https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ntopenprocess) |
| `NtQueryInformationProcess` | 5 | [`base/ntos/ps/psquery.c:563`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ps/psquery.c) | [winternl](https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ntqueryinformationprocess) |
| `NtSetInformationThread` | 4 | [`base/ntos/ps/psquery.c:3200`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ps/psquery.c) | [winternl](https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ntsetinformationthread) |
| `NtDuplicateObject` | 7 | [`base/ntos/ob/obhandle.c:774`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ob/obhandle.c) | [winternl](https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ntduplicateobject) |
| `NtWaitForSingleObject` | 3 | [`base/ntos/ob/obwait.c:286`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ob/obwait.c) | [winternl](https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ntwaitforsingleobject) |
| `NtClose` | 1 | [`base/ntos/ob/obclose.c:410`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ob/obclose.c) | [ZwClose](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-zwclose) |
| `NtQuerySystemInformation` | 4 | [`base/ntos/ex/sysinfo.c:1342`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ex/sysinfo.c) | — (undocumented class set) |
| `NtDelayExecution` | 2 | [`base/ntos/ex/delay.c:33`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ex/delay.c) | [ZwDelayExecution](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwdelayexecution) |
| `NtCreateKey` | 7 | `base/ntos/config/cmapi.c` (`Nt*Key` family) | [ZwCreateKey](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey) |
| `NtSetValueKey` | 6 | `base/ntos/config/cmapi.c` | [ZwSetValueKey](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-zwsetvaluekey) |
| `NtLoadDriver` | 1 | [`base/ntos/io/iomgr/loadunld.c:35`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/io/iomgr/loadunld.c) | [ZwLoadDriver](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-zwloaddriver) |
| `NtYieldExecution` | 0 | [`base/ntos/ke/yield.c:29`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/yield.c) | [ZwYieldExecution](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-zwyieldexecution) |
| `NtSystemDebugControl` | 6 | `base/ntos/kd64` (the kernel-debugger family) | — (undocumented) |

The dash entries are real exports of the tree with no public Microsoft reference page — the honest
documentation for them is the source linked in the row and the `services.tab` line.

## The win32k shadow table

The windowing and graphics services ride the same mechanism with a second table. Its source list is
[`windows/core/kmode/services.tab`](https://github.com/havaianasdestruido/neo-nt5/blob/main/windows/core/kmode/services.tab)
— 750 entries in `Stub,NumParams[,ErrRetVal]` format, with `Gdi*` and `NtUser*` names. The header of
that file documents the extra error-return column (`0`, `-1`, or `1` for a status code). Details,
and the `NtUserCreateWindowEx` walk-through, are in
[Win32, windowing and the shell](/win32-shell#the-win32k-service-table).

The kernel table and the shadow table are looked up through `KeServiceDescriptorTable` and
`KeServiceDescriptorTableShadow` respectively — the two `extrn`s at the top of `trap.asm`.

## 32-bit on 64-bit

`base/ntdll/wow6432/i386/table.stb` is a checked-in copy of the service-table generator macros for
the WOW64 thunk, and `windows/core/wow6432/{daytona}/i386/table.stb` covers the win32k side. The
32-bit service number is translated to the 64-bit one during the transition — which is another
reason syscall numbers are per-build and per-architecture, not universal constants.

## References

Official Microsoft documentation:

| Topic | Official documentation |
| --- | --- |
| `NtCreateFile` (user-mode) | [https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ntcreatefile](https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ntcreatefile) |
| `ZwCreateFile` (kernel) | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntddk/nf-ntddk-zwcreatefile](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntddk/nf-ntddk-zwcreatefile) |
| `winternl.h` routines | [https://learn.microsoft.com/en-us/windows/win32/api/winternl/](https://learn.microsoft.com/en-us/windows/win32/api/winternl/) |
| `ntddk.h`/`ntifs.h` Zw routines | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/_kernel/](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/_kernel/) |
| System services and system calls | [https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/system-threads-and-worker-threads](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/system-threads-and-worker-threads) |
| Process/thread native handles | [https://learn.microsoft.com/en-us/windows/win32/procthread/scheduling-priorities](https://learn.microsoft.com/en-us/windows/win32/procthread/scheduling-priorities) |

In-tree anchors:

| File | Why |
| --- | --- |
| [`base/ntos/ke/services.tab`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/services.tab) | The service list — the ABI of this build |
| [`base/ntos/ke/i386/table.stb`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/i386/table.stb) | The table/stub generator macros |
| [`base/ntos/ke/i386/services.stb`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/i386/services.stb) | The user-stub generator macros |
| [`base/ntos/ke/i386/trap.asm`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/i386/trap.asm) | `KiSystemService`, `KiFastCallEntry` |
| [`sdktools/gensrv/gensrv.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/sdktools/gensrv/gensrv.c) | The generator implementation |
| [`windows/core/kmode/services.tab`](https://github.com/havaianasdestruido/neo-nt5/blob/main/windows/core/kmode/services.tab) | The win32k service list |

## Frequently asked questions

### Q: What is the syscall number of `NtCreateFile` in this build?

Whatever position `CreateFile` occupies in the generated `systable.asm` — determined by the order of
`base/ntos/ke/services.tab` in the build you made. Do not publish it as "the" number. If you need it
for a tool built against this tree, generate the table with the `gensrv` pipeline and read the
index, or derive it at runtime through `KeServiceDescriptorTable` the way the debugger extensions
do.

### Q: Why do some `Nt*` functions have no Microsoft documentation?

Because Microsoft documents the supported surface (`winternl.h` for applications, `ntddk.h` /
`ntifs.h` for drivers), not every export. `NtQuerySystemInformation`'s information classes and
routines like `NtCreateProcess` are implementation details that leaked into the public eye; their
documentation is the source in the table above. Calling undocumented services from an application
is a compatibility bet, not a contract.

### Q: Where is `ZwCreateFile` defined in this tree?

Nowhere as a separate body. `services.tab` has one `CreateFile` entry; the `Zw` name is an alias on
the stub side. The implementation is `NtCreateFile` in `base/ntos/io/iomgr/create.c:37`, and the
behavioural difference is only `PreviousMode` handling on entry. If you are debugging "Zw behaviour",
you are debugging the calling convention, not a second function.

### Q: How do I add a new system service?

Four coordinated edits, then a full kernel + ntdll build:

1. Add `Name,argbytes` to `base/ntos/ke/services.tab` (order = service number).
2. Implement `NtName` in the owning manager, with the right `alloc_text` and IRQL discipline.
3. Declare it in the internal headers the manager publishes (see
   [Interfaces and cross-project contracts](/interfaces)).
4. If user mode needs it, add the export to the ntdll definition lists and consider the wow64
   thunk.

The `table.stb` header comment says the list edit alone generates the stubs and table — the
implementation and the header are the parts you must write. Adding a service is an ABI event: old
`ntdll` against a new kernel (or vice versa) misnumbers everything after the insertion point.

### Q: Is the POSIX subsystem using these services?

Indirectly. `base/subsys/posix` runs as a subsystem and its server calls the Win32/native API like
any other process; it does not get its own syscall table. `LpcRequestPort`-style LPC traffic to the
subsystem server is the transport, not a second kernel ABI.
