---
title: The Windows API surface
sidebar_position: 12
description: How the Win32 API, the NT native API and the kernel driver interfaces fit together, where each DLL is implemented in this tree, and how to trace a call from header to source.
---

This page is the entry point for the **API reference** half of the wiki. The guide pages
([Architecture](/architecture), [Kernel](/kernel), [I/O](/io-storage), and the rest) explain how the
tree is organised; the pages linked here explain the **callable surface** — what the functions are,
which header declares them, which binary exports them, where this checkout implements them, and
what the official Microsoft documentation says.

Three API layers matter in this tree, and confusing them is the most common source of wrong edits:

```text
+---------------------------------------------------------------+
| Win32 API          kernel32.dll user32.dll gdi32.dll advapi32 |
|                    shell32.dll ole32.dll ws2_32.dll ...       |
+------------------------------+--------------------------------+
                               |  thin wrappers, ANSI/Unicode shims
+------------------------------v--------------------------------+
| NT native API      ntdll.dll  Nt*/Zw*  +  Rtl*  +  Ldr*        |
+------------------------------+--------------------------------+
                               |  syscall (int 2Eh / sysenter / syscall)
+------------------------------v--------------------------------+
| Executive          ntoskrnl.exe  base/ntos  (Nt* implemented)  |
| Kernel drivers     wdm.h / ntifs.h / ndis.h  DDI contracts    |
+---------------------------------------------------------------+
```

## The DLLs and where this tree builds them

| Binary | Declared by | Implemented in this checkout | Export list | Reference page |
| --- | --- | --- | --- | --- |
| `kernel32.dll` | `public/sdk/inc/winbase.h`, `fileapi.h`, `processthreadsapi.h`, `memoryapi.h`, `synchapi.h`, `libloaderapi.h` | `base/win32/client` (`TARGETNAME=kernel32`, `TARGETTYPE=DYNLINK` in `sources.inc`) | `base/win32/client/kernel32.prf`, `kernel32.src` | [Files](/kernel32-file-api), [Processes and threads](/kernel32-process-api), [Memory](/kernel32-memory-api), [Libraries](/kernel32-library-api) |
| `user32.dll` | `public/sdk/inc/winuser.h` | `windows/core/ntuser/client` (`TARGETNAME=user32`) | `windows/core/ntuser/client/user32.def`, `user32.prf` | [USER](/user32-api) |
| `gdi32.dll` | `public/sdk/inc/wingdi.h` | `windows/core/ntgdi/client` (`TARGETNAME=gdi32`) | `windows/core/ntgdi/client/gdi32.def`, `gdi32.prf` | [GDI](/gdi32-api) |
| `advapi32.dll` | `public/sdk/inc/winreg.h`, `winsvc.h`, `winbase.h` (event log), `wincrypt.h` | `mergedcomponents/advapi32` (`TARGETNAME=advapi32`) plus `ds/win32/advapi` and `base/eventlog` | `mergedcomponents/advapi32/advapi32.def` | [ADVAPI32](/advapi32-api) |
| `ntdll.dll` | `public/sdk/inc/winternl.h`, `ntdef.h` | `base/ntdll` | `base/ntdll/ntdll.prf`, generated stubs from `base/ntos/ke/services.tab` | [NTDLL runtime](/ntdll-api), [Native API](/native-api) |
| `shell32.dll` | `public/sdk/inc/shlobj.h`, `shellapi.h` | `shell/shell32` | `shell/shell32/*.def` | [Win32, windowing and the shell](/win32-shell) |
| `ws2_32.dll` | `public/sdk/inc/winsock2.h` | `net/sockets/winsock2/ws2_32` | `ws2_32.def` in that directory | [Networking stack](/networking) |
| `ole32.dll`, `oleaut32.dll`, `comdlg32.dll`, `comctl32.dll` | `public/sdk/inc/objbase.h`, `oaidl.h`, `commdlg.h`, `commctrl.h` | `com/ole32`, `com/oleaut32`, `shell/comdlg32`, `shell/comctl32` | per-project `.def` files | [Interfaces](/interfaces) |

The export lists are the ABI. `kernel32.prf` is a **pre-link directive file**: each line names a
symbol and its decorated stack size, for example:

```text
CloseHandle@4
GetLastError@0
SetLastError@4
SetStdHandle@8
```

The `@4` suffix is the x86 `__stdcall` decoration: the callee pops 4 bytes of arguments. Change a
signature and the decoration changes, which is why an export list edit is a compatibility event and
not a refactor. `user32.def` and `gdi32.def` are module-definition files with explicit `EXPORTS`
sections and therefore the authoritative list of what the DLL promises to the outside world.

### Headers are split by API set, not by DLL

The Windows SDK of this era splits one DLL's surface across many headers. `kernel32.dll` alone is
declared by `winbase.h`, `fileapi.h`, `processthreadsapi.h`, `memoryapi.h`, `synchapi.h`,
`libloaderapi.h`, `errhandlingapi.h`, `handleapi.h`, `heapapi.h`, `sysinfoapi.h`, `consoleapi.h`,
`stringapiset.h`, `tlhelp32.h`, `winnls.h` and `winperf.h`. `windows.h` includes most of them through
`winbase.h`. `public/sdk/inc` contains 1,173 `.h` files; the full list is:

```bash
ls public/sdk/inc | wc -l          # 1173 headers
ls public/sdk/inc | grep -E '^(winbase|winuser|wingdi|winreg|winnt|winerror|ntdef|winternl)\.h$'
```

For drivers the equivalent split is `public/ddk/inc/wdm/wdm.h`, `ntifs.h`, `ndis.h`, `ntddk.h`, and
the bus/class headers (`scsi.h`, `usb.h`, `hidclass.h`, `1394.h`). `public/ddk/inc` holds 100+ of
them.

## Calling conventions in this tree

Windows x86 uses `__stdcall` for the Win32 API and `__cdecl` for the C runtime. NT uses `NTAPI`
(`__stdcall`) for native services and `FASTCALL` for hot kernel paths. The tree makes all of them
visible:

| Convention | Macro you will see | Callee cleans arguments? | Where it appears |
| --- | --- | --- | --- |
| `__stdcall` | `WINAPI`, `APIENTRY`, `CALLBACK`, `NTAPI` | Yes (`@n` decoration) | Win32 exports, `Nt*` services, window procedures |
| `__cdecl` | `CRTAPI`, none | No | C runtime, variadic functions such as `wsprintf` |
| `__fastcall` | `FASTCALL` | First two args in `ECX`/`EDX` | `IofCallDriver`, `IofCompleteRequest`, `AfdSend` |
| `__thiscall` | none (implicit) | Yes, `this` in `ECX` | C++ member functions in `com/`, `shell/`, `ds/` |

A mismatch is not a compile error when a function pointer is cast, and it corrupts the stack at run
time. The tree's own kernel exports state the convention explicitly, for example
`base/ntos/io/iomgr/iosubs.c`:

```c
NTSTATUS
FASTCALL
IofCallDriver(
    IN PDEVICE_OBJECT DeviceObject,
    IN OUT PIRP Irp
    )
```

and the AFD send path in `net/sockets/winsock2/wsp/afdsys/send.c`:

```c
NTSTATUS
FASTCALL
AfdSend (
    IN PIRP Irp,
    IN PIO_STACK_LOCATION IrpSp
    )
```

## ANSI and Unicode

Almost every Win32 function that takes or returns a string exists in two forms: `XxxA` (ANSI code
page) and `XxxW` (UTF-16). `windows.h` maps the undecorated name to one of them based on the
`UNICODE` macro:

```c
#ifdef UNICODE
#define CreateFile  CreateFileW
#else
#define CreateFile  CreateFileA
#endif
```

This tree implements both. `CreateFileA` is at
[`base/win32/client/fileopcr.c:5331`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/win32/client/fileopcr.c#L5331)
and `CreateFileW` 40 lines later at line 5371; the A version converts the name and calls the W
version, so the semantics live in exactly one place. The pattern repeats for `CreateProcessA/W`
(`base/win32/client/process.c:1001` and `:4328`) and `LoadLibraryA/W` (`base/win32/client/module.c:52`
and `:94`).

Two consequences:

1. **Never fix a string bug in the A wrapper alone** unless the bug is the conversion itself. The
   W version is the one that reaches the kernel.
2. **The kernel is Unicode.** `NtCreateFile` takes a `PUNICODE_STRING` built from the wide name. An
   ANSI application pays a conversion on every call; a Unicode application does not.

`base/win32/client` also holds the conversion helpers (`Basep8BitStringToDynamicUnicodeString`,
`BasepAnsiStringToDynamicUnicodeString`) and the `winnls` code-page tables.

## The error model

Three error namespaces coexist, and the tree translates between them in both directions:

| Namespace | Type | Set by | Retrieved by | Translation |
| --- | --- | --- | --- | --- |
| Win32 last error | `DWORD` (`ERROR_*`) | `SetLastError` | `GetLastError` | `BaseSetLastNTError` |
| NT status | `NTSTATUS` (`STATUS_*`) | Kernel returns | `IoStatusBlock.Status`, return value | `RtlNtStatusToDosError` |
| COM `HRESULT` | 32-bit `HRESULT` (`S_OK`, `E_*`) | COM methods | return value | `HRESULT_FROM_WIN32` |

`GetLastError` is at
[`base/win32/client/error.c:92`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/win32/client/error.c#L92).
It reads the calling thread's last-error value from the TEB, which is why it is thread-local and why
"the error code was clobbered by a later call" is a real failure mode: any intervening Win32 call can
overwrite it. The kernel's `RtlNtStatusToDosError` (`base/ntos/rtl`) is the table that turns a
`STATUS_*` into the `ERROR_*` that `GetLastError` reports.

`NT_SUCCESS`, `NT_INFORMATION`, `NT_WARNING`, `NT_ERROR` classify a status by its top bits. The
layout is fixed by `public/sdk/inc/ntdef.h`:

```text
 3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0
 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
+---------------+---------------+-------------------------------+---------------+
| Severity | Customer | Reserved | Facility | Code |
```

See [Status and error codes](/status-codes) for the full tables.

## Handles and objects

A `HANDLE` is an index into the calling process's handle table, not a pointer. The object manager
(`base/ntos/ob`) owns the table; `ObReferenceObjectByHandle` at
[`base/ntos/ob/obref.c:1044`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ob/obref.c#L1044)
turns an index into an object pointer and performs the access check at the same time.

Four handle conventions you will meet constantly:

| Convention | Meaning | Example |
| --- | --- | --- |
| `INVALID_HANDLE_VALUE` | `CreateFile` failure sentinel (`-1`), **not** `NULL` | File, pipe, mailslot handles |
| `NULL` | Failure for most other APIs | `CreateEvent`, `LoadLibrary` |
| Pseudo-handle | Constant that refers to the calling process/thread | `GetCurrentProcess()` returns `-1` |
| Kernel handle | Bit 31 set; valid in any process context | `OBJ_KERNEL_HANDLE` in `OBJECT_ATTRIBUTES` |

The pseudo-handle is why `GetCurrentProcess()` is free: it returns `(HANDLE)-1` and the kernel
recognises the value. `DuplicateHandle` with `DUPLICATE_CLOSE_SOURCE` is the only way to turn a
pseudo-handle into a real one.

## Tracing an API call from header to source

A repeatable five-step method. Worked example: `ReadFile`.

```bash
# 1. Which header declares it, and which export does UNICODE select?
rg -n 'ReadFile' public/sdk/inc/fileapi.h public/sdk/inc/winbase.h | head

# 2. Which DLL exports it?
rg -n 'ReadFile' base/win32/client/kernel32.prf base/win32/client/kernel32.src

# 3. Where is the W version implemented?
rg -n '^ReadFile' base/win32/client/*.c

# 4. Which native service does it call?
rg -n 'NtReadFile' base/win32/client/*.c

# 5. Where is that native service implemented?
rg -n '^NtReadFile' base/ntos
```

Step 3 lands on `base/win32/client/fileopcr.c`; step 5 lands on `base/ntos/io/iomgr/read.c`. Every
layer in between is visible in the tree — there is no hidden DLL boundary except the syscall
instruction itself.

The syscall table that defines step 5 is checked in as
[`base/ntos/ke/services.tab`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/services.tab).
It is 284 lines of `Name,ArgumentCount` pairs, and `gensrv` (source at `sdktools/gensrv`) turns it
into the `Nt*`/`Zw*` stubs and the kernel service table:

```text
CreateFile,11
CreateProcess,8
CreateProcessEx,9
CreateThread,8
MapViewOfSection,10
OpenFile,6
OpenKey,3
QueryValueKey,6
```

`base/ntdll/makefile.nap` records the generation rule:

```bat
i386\usrstubs.asm: \\nt\private\ntos\ke\services.tab
    gensrv -d i386 -e asm \\nt\private\ntos\ke
```

That is why adding a system service touches `services.tab` first: it is the single source of truth
for the syscall number, the stub, and the argument count.

## The native API versus the Win32 API

`Nt*` and `Zw*` are the same routine with different semantics for kernel-mode callers: `Nt*` uses the
caller's previous mode for pointer capture, `Zw*` forces kernel mode. In user mode both are the same.
The Win32 API is a **wrapper** over the native API plus policy: `CreateFileW` builds an
`OBJECT_ATTRIBUTES` and an `IO_STATUS_BLOCK`, converts the path, and calls `NtCreateFile`.

| Win32 call | Native service | Implemented at |
| --- | --- | --- |
| `CreateFileW` | `NtCreateFile` | `base/ntos/io/iomgr/create.c:37` |
| `ReadFile` | `NtReadFile` | `base/ntos/io/iomgr/read.c` |
| `WriteFile` | `NtWriteFile` | `base/ntos/io/iomgr/write.c` |
| `CreateProcessW` | `NtCreateProcessEx` | `base/ntos/ps/create.c:884` |
| `CreateThread` | `NtCreateThread` / `NtCreateThreadEx` | `base/ntos/ps/create.c:86` |
| `VirtualAlloc` | `NtAllocateVirtualMemory` | `base/ntos/mm/allocvm.c:83` |
| `MapViewOfFile` | `NtMapViewOfSection` | `base/ntos/mm/mapview.c:199` |
| `RegOpenKeyExW` | `NtOpenKey` | `base/ntos/config/ntapi.c:2080` |
| `WaitForSingleObject` | `NtWaitForSingleObject` | `base/ntos/ob/obwait.c:286` |
| `CloseHandle` | `NtClose` | `base/ntos/ob/obclose.c:410` |

The full native API page, with signatures and the syscall path, is
[NT native API](/native-api).

## Official documentation

Microsoft publishes the API reference on Microsoft Learn. The stable URL shape is
`https://learn.microsoft.com/en-us/windows/win32/api/<header>/nf-<header>-<function>`, for example:

| Document | URL |
| --- | --- |
| Win32 API index | [https://learn.microsoft.com/en-us/windows/win32/api/](https://learn.microsoft.com/en-us/windows/win32/api/) |
| `fileapi.h` (file functions) | [https://learn.microsoft.com/en-us/windows/win32/api/fileapi/](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/) |
| `processthreadsapi.h` | [https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/) |
| `memoryapi.h` | [https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/) |
| `synchapi.h` | [https://learn.microsoft.com/en-us/windows/win32/api/synchapi/](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/) |
| `libloaderapi.h` | [https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/) |
| `winuser.h` (USER) | [https://learn.microsoft.com/en-us/windows/win32/api/winuser/](https://learn.microsoft.com/en-us/windows/win32/api/winuser/) |
| `wingdi.h` (GDI) | [https://learn.microsoft.com/en-us/windows/win32/api/wingdi/](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/) |
| `winreg.h` (registry) | [https://learn.microsoft.com/en-us/windows/win32/api/winreg/](https://learn.microsoft.com/en-us/windows/win32/api/winreg/) |
| `winsvc.h` (services) | [https://learn.microsoft.com/en-us/windows/win32/api/winsvc/](https://learn.microsoft.com/en-us/windows/win32/api/winsvc/) |
| `wincrypt.h` (CryptoAPI) | [https://learn.microsoft.com/en-us/windows/win32/api/wincrypt/](https://learn.microsoft.com/en-us/windows/win32/api/wincrypt/) |
| `winternl.h` (native API) | [https://learn.microsoft.com/en-us/windows/win32/api/winternl/](https://learn.microsoft.com/en-us/windows/win32/api/winternl/) |
| Windows Driver Kit reference | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/) |
| `wdm.h` kernel DDI | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/) |

Every function table in this section links the individual function page as well, so a claim about a
signature can be checked against the official source in one click.

## Frequently asked questions

### Q: Is `kernel32.dll` one project in this tree?

One project, many files. `base/win32/client` has 121 entries in its directory and a flat layout:
`fileopcr.c`, `filemap.c`, `filefind.c`, `process.c`, `thread.c`, `synch.c`, `gmem.c`, `lmem.c`,
`module.c`, `toolhelp.c`, `dir.c`, `comm.c`, `pipe.c`, `namepipe.c`, `mailslot.c` and so on. There is
no per-API subdirectory, which is why `rg -n '^ReadFile' base/win32/client` is the fastest way in.

### Q: Why does the same function appear in `kernel32.prf` and `kernel32.src`?

They serve different build steps. `kernel32.src` is the source list for the DLL; `kernel32.prf` is
the pre-link directive file that feeds the export and decoration step. The `.def` equivalent for
user32 and gdi32 is `user32.def` / `gdi32.def`. All three are generated-adjacent files that must be
edited together with a signature change.

### Q: What is the difference between `WINAPI` and `NTAPI`?

Both expand to `__stdcall` on x86, but they belong to different contracts. `WINAPI` is the Win32
calling convention and is subject to the `UNICODE`/ANSI export split. `NTAPI` is the native
convention used by `Nt*`/`Zw*` and by kernel callbacks. A function declared `NTAPI` must not be
assigned to a `WINAPI` function pointer without an explicit cast, even though the code compiles.

### Q: Why does `CreateFileA` exist at all if the kernel is Unicode?

Because the ANSI entry point is part of the published ABI and millions of programs call it. The A
version converts with the thread's code page (`CP_ACP` unless `SetFileApisToOEM` changed it), which
means file names outside the current code page are unreachable from an ANSI application. That is a
documented limitation, not a bug in this tree.

### Q: How do I know which header a function belongs to?

Read the `#include` line in the implementation. `base/win32/client/fileopcr.c` includes `winbase.h`
and `fileapi.h`; `base/win32/client/synch.c` includes `synchapi.h` through `windows.h`. Microsoft
Learn's per-function page also names the header in its Requirements table, which is the quickest
check when the local header set is ambiguous.

### Q: Can I call the native API directly from a user-mode application?

Yes, but it is unsupported. `winternl.h` declares a subset (`NtCreateFile`, `NtOpenFile`,
`NtClose`, `NtQueryInformationProcess`, ...), and `base/ntdll/ntdll.prf` lists the exported symbols.
The unsupported part is the contract: the syscall numbers and structure layouts are internal to the
OS version. That is exactly why this wiki separates the documented Win32 layer from the native layer.

### Q: Where do I read about a driver-facing API rather than a user-mode one?

Start at [Kernel driver model](/driver-model), then the WDK header index at
[https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/). The tree's DDI headers are under
`public/ddk/inc/`, and the driver-side contracts are `wdm.h`, `ntifs.h`, `ndis.h`, `scsi.h` and the
class-specific headers.

### Q: Why are some APIs in `base/win32/client` and others in `windows/core/umode`?

History and layering. `base/win32/client` is the kernel32-style API set: files, processes, memory,
synchronization, loading. `windows/core/umode` is the user-mode half of the windowing and graphics
subsystem (user32/gdi32), which lives in the `windows/core` project because it shares headers and
build definitions with the kernel-mode window manager. The boundary is `windows/core`, not "user
mode" in the abstract.

### Q: What is the `win32k` ABI mentioned elsewhere on this wiki?

`win32k.sys` (built from `windows/core/ntuser` and `windows/core/ntgdi` kernel halves) imports a
fixed list of kernel exports listed in
[`base/ntos/init/w32kexps.txt`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/init/w32kexps.txt).
It is the ABI between the executive and the window manager. Adding an import there changes both
projects and every kernel binary's link.
