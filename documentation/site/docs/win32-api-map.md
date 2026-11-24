---
title: Windows API to source map
slug: /api-source-map
sidebar_position: 13
description: A curated map from well-known Win32 and NT APIs to their exact implementation files in this tree, with the official Microsoft Learn documentation for every entry.
---

The generated [function index](/function-index) lists everything; this page answers the question it
cannot: **"I know the API — where is it *here*?"** Every row is a definition verified in this
checkout, paired with the official documentation for the API. Three subsystems get their own deep
pages — the system services in [The native API](/native-api), the windowing stack in
[Win32, windowing and the shell](/win32-shell), and the socket layer in
[Networking stack](/networking); their rows are summarised here with links.

How to re-verify a row:

```bash
rg -n '^CreateFileW' base/win32 -g '*.c'      # definition search, anchored
rg -n '^RegOpenKeyExW' base/screg -g '*.c'
```

## kernel32 — `base/win32/client`

File and I/O:

| API | Definition | Official documentation |
| --- | --- | --- |
| `CreateFileW` | [`base/win32/client/fileopcr.c:5371`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/win32/client/fileopcr.c) | [CreateFileW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilew) |
| `CreateFileA` | `base/win32/client/fileopcr.c:5331` | [CreateFileA](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilea) |
| `ReadFile` | [`base/win32/client/filehops.c:213`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/win32/client/filehops.c) | [ReadFile](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-readfile) |
| `WriteFile` | `base/win32/client/filehops.c:424` | [WriteFile](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-writefile) |
| `CreateFileMappingW` | [`base/win32/client/filemap.c:76`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/win32/client/filemap.c) | [CreateFileMappingW](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-createfilemappingw) |
| `MapViewOfFile` | `base/win32/client/filemap.c:377` | [MapViewOfFile](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffile) |

Memory, modules and processes:

| API | Definition | Official documentation |
| --- | --- | --- |
| `VirtualAlloc` | [`base/win32/client/gmem.c:888`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/win32/client/gmem.c) | [VirtualAlloc](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualalloc) |
| `LoadLibraryW` | [`base/win32/client/module.c:94`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/win32/client/module.c) | [LoadLibraryW](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryw) |
| `GetProcAddress` | `base/win32/client/module.c:1430` | [GetProcAddress](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) |
| `GetModuleHandleW` | `base/win32/client/module.c:1153` | [GetModuleHandleW](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandlew) |
| `CreateProcessW` | [`base/win32/client/process.c:4328`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/win32/client/process.c) | [CreateProcessW](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessw) |
| `GetVersion` | `base/win32/client/module.c:1526` | [GetVersion](https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getversion) |

Synchronization and handles:

| API | Definition | Official documentation |
| --- | --- | --- |
| `CreateEventW` | [`base/win32/client/synch.c:170`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/win32/client/synch.c) | [CreateEventW](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-createeventw) |
| `WaitForSingleObject` | `base/win32/client/synch.c:1170` | [WaitForSingleObject](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject) |
| `WaitForSingleObjectEx` | `base/win32/client/synch.c:1221` | [WaitForSingleObjectEx](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-waitforsingleobjectex) |
| `CloseHandle` | [`base/win32/client/handle.c:24`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/win32/client/handle.c) | [CloseHandle](https://learn.microsoft.com/en-us/windows/win32/api/handleapi/nf-handleapi-closehandle) |

Strings and messages:

| API | Definition | Official documentation |
| --- | --- | --- |
| `FormatMessageW` | [`base/win32/client/message.c:156`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/win32/client/message.c) | [FormatMessageW](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-formatmessagew) |
| `lstrlenW` | `base/win32/client/lcompat.c:674` | [lstrlenW](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-lstrlenw) |

Every `kernel32` routine in this table ultimately calls an `Nt*` service — the mapping from service
to manager is [The native API](/native-api).

## advapi32 — registry and security

Registry (implementation: `base/screg/winreg/client`):

| API | Definition | Official documentation |
| --- | --- | --- |
| `RegCloseKey` | [`base/screg/winreg/client/regkey.c:53`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/screg/winreg/client/regkey.c) | [RegCloseKey](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regclosekey) |
| `RegCreateKeyExW` | `base/screg/winreg/client/regkey.c:490` | [RegCreateKeyExW](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regcreatekeyexw) |
| `RegOpenKeyExW` | `base/screg/winreg/client/regkey.c:1094` | [RegOpenKeyExW](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regopenkeyexw) |
| `RegSetValueExW` | [`base/screg/winreg/client/regsval.c:498`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/screg/winreg/client/regsval.c) | [RegSetValueExW](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regsetvalueexw) |
| `RegQueryValueExW` | [`base/screg/winreg/client/regqval.c:689`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/screg/winreg/client/regqval.c) | [RegQueryValueExW](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regqueryvalueexw) |

Security (implementation: `mergedcomponents/advapi32/security.c`):

| API | Definition | Official documentation |
| --- | --- | --- |
| `OpenProcessToken` | [`mergedcomponents/advapi32/security.c:556`](https://github.com/havaianasdestruido/neo-nt5/blob/main/mergedcomponents/advapi32/security.c) | [OpenProcessToken](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-openprocesstoken) |
| `AdjustTokenPrivileges` | `mergedcomponents/advapi32/security.c:880` | [AdjustTokenPrivileges](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-adjusttokenprivileges) |
| `LookupPrivilegeValueW` | `mergedcomponents/advapi32/security.c:8238` | [LookupPrivilegeValueW](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-lookupprivilegevaluew) |
| `LsaLogonUser` (secur32/LSA client) | [`ds/security/base/lsa/client/austub.c:483`](https://github.com/havaianasdestruido/neo-nt5/blob/main/ds/security/base/lsa/client/austub.c) | [LsaLogonUser](https://learn.microsoft.com/en-us/windows/win32/api/ntsecapi/nf-ntsecapi-lsalogonuser) |

## user32 — `windows/core/ntuser`

| API | Path through this tree | Official documentation |
| --- | --- | --- |
| `CreateWindowExW` | wrapper `windows/core/ntuser/client/cltxt.h:39` → `_CreateWindowEx` `client/ntstubs.c:1520` → `NtUserCreateWindowEx` `kernel/ntstubs.c:8005` | [CreateWindowExW](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createwindowexw) |
| `GetMessageW` | `NtUserGetMessage` [`windows/core/ntuser/kernel/ntstubs.c:1975`](https://github.com/havaianasdestruido/neo-nt5/blob/main/windows/core/ntuser/kernel/ntstubs.c) | [GetMessageW](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getmessagew) |
| `RegisterClassW` / `RegisterClassExW` | `RegisterClassWOWA` `windows/core/ntuser/client/client.c:2698` → `NtUserRegisterClassExWOW` `kernel/ntstubs.c:9098` | [RegisterClassW](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-registerclassw) |

The message loop and windowing internals are documented in
[Win32, windowing and the shell](/win32-shell#createwindowexw-layer-by-layer); the export table is
`windows/core/ntuser/client/user32.def`.

## ws2_32 — Winsock

| API | Definition | Official documentation |
| --- | --- | --- |
| `WSAStartup` | [`net/sockets/winsock2/ws2_32/src/startup.cpp:112`](https://github.com/havaianasdestruido/neo-nt5/blob/main/net/sockets/winsock2/ws2_32/src/startup.cpp) | [WSAStartup](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsastartup) |
| `WSASocketW` | [`net/sockets/winsock2/ws2_32/src/socklife.cpp:117`](https://github.com/havaianasdestruido/neo-nt5/blob/main/net/sockets/winsock2/ws2_32/src/socklife.cpp) | [WSASocketW](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsasocketw) |
| `WSAConnect` | `net/sockets/winsock2/ws2_32/src/sockctrl.cpp:693` | [WSAConnect](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsaconnect) |
| `send` / `sendto` / `WSASend` | `net/sockets/winsock2/ws2_32/src/send.cpp:41` / `:116` / `:198` | [send](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-send) |
| `recv` / `WSARecv` | `net/sockets/winsock2/ws2_32/src/recv.cpp:44` / `:219` | [recv](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-recv) |

The AFD and TCP layers underneath are in [Networking stack](/networking).

## ole32 — COM

| API | Definition | Official documentation |
| --- | --- | --- |
| `CoCreateInstance` | [`com/ole32/com/objact/actapi.cxx:89`](https://github.com/havaianasdestruido/neo-nt5/blob/main/com/ole32/com/objact/actapi.cxx) | [CoCreateInstance](https://learn.microsoft.com/en-us/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance) |

## setupapi — device installation

| API | Definition | Official documentation |
| --- | --- | --- |
| `SetupDiCreateDeviceInfoList` | [`base/pnp/setupapi/devinfo.c:124`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/pnp/setupapi/devinfo.c) | [SetupDiCreateDeviceInfoList](https://learn.microsoft.com/en-us/windows/win32/api/setupapi/nf-setupapi-setupdicreatedeviceinfolist) |
| `SetupDiCallClassInstaller` | [`base/pnp/setupapi/devinst.c:944`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/pnp/setupapi/devinst.c) | [SetupDiCallClassInstaller](https://learn.microsoft.com/en-us/windows/win32/api/setupapi/nf-setupapi-setupdicallclassinstaller) |

## ntdll and the kernel

The `Nt*`/`Zw*` services are not listed here — they have their own page with dispatch mechanics,
argument-byte counts and per-manager locations: [The native API](/native-api). Driver-facing kernel
routines (`Io*`, `Ke*`, `Ex*`, `Mm*`, `Ob*`, `Se*`) are covered under
[Kernel and executive](/kernel) and [I/O, file systems and storage](/io-storage).

## How to read this map

* **A definition is not the whole story.** `CreateWindowExW`'s real work is in kernel mode; `send`'s
  real work is in `afd.sys` and `tcpip.sys`. The map gives the entry point; the linked deep page
  gives the layers.
* **A/W pairs** are separate exports; the A form converts and calls the W form (or vice versa where
  historical quirks apply). Search both when tracing.
* **Line numbers move.** They are exact for this checkout; re-run the `rg` command above after
  pulling. The URLs link to `main`, which is where merged work lands.
* **Missing rows are not missing APIs.** This is a curated subset of the best-documented entry
  points. For everything else, use the generated [function index](/function-index) or search
  directly:

```bash
rg -n '^CreateWindowExW|^GetMessageW' windows/core -g '*.c'
```

## Frequently asked questions

### Q: Why is there no `kernel32!CreateFile` row?

Because `CreateFile` is an A/W alias pair — the real exports are `CreateFileA` and `CreateFileW`,
both listed. Several Win32 "functions" are macros or aliases in `windows.h`; search for the A/W
forms in the source.

### Q: A row's line number is stale. Is the map wrong?

The map is exact for this checkout, and every row carries the search command to re-find the
definition. Sources above line numbers; the map says where to look first.

### Q: Where do I find APIs that are not in this table?

Three escalating tools, in order:

```bash
# 1. definition search in the likely tree
rg -n '^SHGetFileInfo' shell -g '*.c*'
# 2. export lists, which name everything the DLL exposes
grep -n 'SHGetFileInfo' shell/shell32/*.def
# 3. the generated index, which covers all parsed C/C++/Python
python3 documentation/scripts/generate.py --prefix shell/shell32 --output /tmp/gen
```

### Q: Can I use this map to call undocumented internals safely?

No. The map is a *navigation* aid for reading and changing this source tree, not a support statement
about any API. The tree is proprietary source and this documentation makes no claim about what is
safe or supported to call from an application — the "Official documentation" column exists exactly
to separate the supported contracts from the rest.
