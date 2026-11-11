---
title: Win32, windowing and the shell
sidebar_position: 7
description: Where the Win32 API is implemented, the kernel-mode window server, GDI, and how the shell is organised across shell/ and windows/core.
---

"Win32" is not one directory. The API surface is split across at least four projects, and the split
is historical rather than logical. Getting the owner wrong is the most common mistake in this area.

## Where the pieces live

| Concern | Location | Notes |
| --- | --- | --- |
| Win32 API declarations | `public/sdk/inc` | The ABI applications compile against |
| kernel32-style implementations | `base/win32/client` | Plus `base/win32/server`, `winnls`, `lz32`, `fusion`, `verifier` |
| user32/gdi32 user-mode side | `windows/core/umode` | Architecture subdirs `i386`, `amd64`, `ia64`, `wow6432` |
| Kernel-mode window manager | `windows/core/ntuser` | `kernel/`, `client/`, `server/`, `imm/`, `kbd/`, `kdexts/` |
| Kernel-mode GDI | `windows/core/ntgdi` | `gre/`, `fonts/`, `halftone/`, `icm/`, `image/`, `mf3216/`, `mstypeo/` |
| CSRSS server DLL | `windows/core/winsrv` | Subsystem services for the Windows subsystem |
| Shell | `shell/` | `shell32`, `comctl32`, `comdlg32`, `shlwapi`, `shdocvw`, `browseui`, `themes`, `cpls`, `explorer` |

`base/win32/client` is enormous and flat — `fileopcr.c`, `filemap.c`, `filefind.c`, `comm.c`,
`beep.c`, `backup.c`, `count.c` and hundreds more, each implementing a family of exports. The kernel
side is much more structured.

## The window manager

`windows/core/ntuser/kernel/` holds the implementation, with one file per concept: `atom.c`,
`caption.c`, `capture.c`, `caret.c`, `class.c`, `clipbrd.c`, `createw.c`, `cursor.c`, `dc.c`,
`ddemlsvr.c`, `ddetrack.c`, `desktop.c`, `dragdrop.c`, `dwp.c`, `enumwin.c`, `event.c`, `exitwin.c`,
`fekbd.c`, `focusact.c`, `fullscr.c`, `ghost.c`, `handtabl.c`.

The system-service entry points are collected in one very large file,
[`windows/core/ntuser/kernel/ntstubs.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/windows/core/ntuser/kernel/ntstubs.c)
— 14,238 lines. A representative entry point at line 8005:

```c
HWND NtUserCreateWindowEx(
    IN DWORD dwExStyle,
    IN PLARGE_STRING pstrNVClassName,
    IN PLARGE_STRING pstrClassName,
    IN PLARGE_STRING pstrWindowName OPTIONAL,
    IN DWORD dwStyle,
    IN int x,
    IN int y,
    IN int nWidth,
    IN int nHeight,
    IN HWND hwndParent,
    IN HMENU hmenu,
    IN HANDLE hModule,
    IN LPVOID pParam,
    IN DWORD dwFlags,
    IN PACTIVATION_CONTEXT pActCtx)
```

Three details worth noticing:

- `PLARGE_STRING`, not `PUNICODE_STRING` — the window manager needs strings longer than
  `UNICODE_STRING` allows for class and window names.
- `pstrNVClassName` is the *non-volatile* class name; the two parameters exist because class names
  have both an atom-lookup form and a full form.
- `PACTIVATION_CONTEXT` ties window creation to side-by-side assembly resolution, which lives in
  `base/win32/fusion` and `base/ntdll` (`sxsactctx.c`, `sxsctxsrch.c`).

The matching **client-side** stub is in `windows/core/ntuser/client/ntstubs.c` (a different file with
the same name), which marshals arguments and traps into the kernel. Both sides are generated and
maintained together; changing a signature means changing both plus `user32.prf`.

### The win32k import contract

`win32k.sys` is not statically linked against the kernel; it imports a fixed list of kernel exports.
That list is checked in as
[`base/ntos/init/w32kexps.txt`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/init/w32kexps.txt)
(71 lines):

```text
ExDesktopObjectType CONSTANT        // Data - use pointer for access
ExEventObjectType CONSTANT          // Data - use pointer for access
ExWindowStationObjectType CONSTANT  // Data - use pointer for access
KeServiceDescriptorTable CONSTANT   // Data - use pointer for access
KeUserModeCallback
LpcRequestPort
LpcRequestWaitReplyPort
MmCreateSection
MmGrowKernelStack
MmMapViewOfSection
ObAssignSecurity
```

This is the ABI between `base/ntos` and `windows/core`. Adding or removing an entry changes both
projects and the link of every kernel binary — it is not a local edit.

## The shell

`shell/` is a project tree in its own right, with its own `project.mk`, `common.mk`, `common.inc`,
`published/`, `sld/` and `lcinf/`:

| Directory | Contents |
| --- | --- |
| `shell32` | The core shell DLL — 768 entries in this directory alone |
| `explorer` | The shell process: `tray.cpp`, `taskbar.cpp`, `bandsite.cpp`, `classfac.cpp`, `desktop2/`, `win95/`, `winnt/` |
| `comctl32`, `comdlg32` | Common controls and common dialogs |
| `shlwapi` | Shell light-weight utility library |
| `shdocvw`, `browseui`, `browseinfo` | Web view, browser UI, browsing history |
| `themes` | Visual styles |
| `cpls` | Control-panel applets |
| `applets`, `services`, `ext`, `iecontrols`, `osshell` | Applets, shell services, extensions |
| `drts`, `shelldrt` | Design/regression tests — see [Tests](/testing-debugging) |
| `docs` | In-tree developer notes |

### The shell's own developer notes

`shell/docs/` contains `shelldev.doc`, `scnotify.doc`, `instid.txt`, `uassist.txt`, `style.htm` and
`other.htm`. `shelldev.doc` is a Word document titled *"IE4 Shell Development Tips & Tricks,
Version 0.8"* and it records several behaviours that still surprise people:

```text
KnownDLL Issues
  ... windows does one additional LoadLibrary of the Known DLLs at bootup time
      and never frees them.

  Under winnt it is stored in
  HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\KnownDLLs
  (note the space)

AlwaysUnloadDll
  ... the Explorer will not unload DLLs right away when their reference count
      goes to zero, but instead it keeps them loaded for an additional 5 minutes
      ... You can disable this feature by creating the key
  HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\AlwaysUnloadDll
  and setting its default value to "1".
```

It is a historical document and its Win9x advice does not apply here, but the KnownDLL and
`AlwaysUnloadDll` mechanics are real and explain why a rebuilt `shell32.dll` does not appear to take
effect. Treat it as a lead to verify in source, not as current guidance.

## Frequently asked questions

### Q: A `CreateFile` call misbehaves. Which of the four Win32 layers do I edit?

Follow the direction of the call:

```text
app -> kernel32!CreateFileW        base/win32/client/fileopcr.c:5371
    -> ntdll!NtCreateFile          base/ntdll
    -> ntos!NtCreateFile           base/ntos/io/iomgr/create.c:37
    -> filesystem driver           base/fs/ntfs/...
```

Argument translation, ANSI/Unicode conversion and error mapping belong in `base/win32/client`.
Semantics of the open itself belong in the I/O manager or the filesystem. Nothing about a file open
belongs in `windows/core`.

### Q: Why is `NtUserCreateWindowEx` in a file called `ntstubs.c`?

Because it *is* a stub: it validates and captures user-mode arguments, then calls into the real
implementation in `createw.c`. The `TRACE("NtUserCreateWindowEx")` line at
`windows/core/ntuser/kernel/ntstubs.c:8170` is the tracing hook. If you are fixing window-creation
logic, the stub is the wrong place — unless the bug is in argument capture, which is exactly the kind
of bug that produces an exploitable one.

### Q: Is `shell32` a UI component I can restyle freely?

No, and per the repository's
[source-only policy](/#the-source-only-change-policy) you would not restyle it by editing
HTML anyway. `shell32` exposes COM interfaces (`IShellFolder`, `IShellView`, context-menu handlers)
consumed by third-party code, and its resource IDs and behaviour are a compatibility surface. Look at
`shell/shell32/_security.h`, `apithk.c` and the `.def` files before changing exports.

### Q: How do Explorer, the taskbar and the tray relate?

Explorer is the process; the taskbar and tray are its top-level windows. In `shell/explorer`:
`taskbar.cpp` / `taskband.cpp` implement the taskbar and its bands, `bandsite.cpp` is the band-site
COM object, `tray.cpp` / `trayitem.cpp` / `traynot.cpp` / `trayclok.cpp` implement the notification
area, its items, notifications and clock, and `trayreg.cpp` reads the tray's registry settings. The
window manager that hosts them is `windows/core/ntuser`.

```bash
ls shell/explorer | grep -E '^tray|^task'
```

### Q: Where does localization of shell strings happen?

In resource scripts and the locale trees, not in C string literals. `shell/lcinf/`, `shell/sld/`,
`shell/types/` and `shell/typebin/` carry locale and component-description data, and each component
has `.rc` files (for example `shell/explorer/explorer.rc`, with `explorer.rcv` alongside). A string
change means editing the string table in the owning `.rc` and checking the locale copies — see
[Interfaces and cross-project contracts](/interfaces).

### Q: What is `wow6432` doing in `windows/core`?

`windows/core/wow6432` and `windows/core/wow64win` implement the 32-bit-on-64-bit compatibility
path for Win32 calls — thunking and structure translation, not a second window manager. Any change to
a structure shared across the boundary has to be reviewed in both the native and the wow64 path.
`base/ntdll/wow6432` and `base/wow64` are the corresponding pieces on the other side.

### Q: How do I find the export list of a shell DLL?

From its module-definition file, which is the authoritative export list:

```bash
cat shell/explorer/cabinet.def
ls shell/shell32/*.def
grep -rn "EXPORTS" -A 20 shell/shlwapi/*.def | head -30
```

`windows/core/ntuser/client/user32.prf` plays the same role for the user-mode USER exports. Changing
an export list is a compatibility event, not a refactor.
