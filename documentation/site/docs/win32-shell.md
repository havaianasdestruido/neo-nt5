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

## The message path

A message travels from the hardware to a window procedure through a fixed sequence. Each hop is
identifiable in the tree.

```text
keyboard / mouse
  -> win32k input thread (windows/core/ntuser/kernel/ntinput.c, input.c)
     -> raw input queue
        -> system message queue (per-desktop)
           -> per-thread message queue (QMESSAGE / tagMSG)
              -> GetMessage / PeekMessage  (user-mode)
                 -> DispatchMessage -> window procedure
```

| Step | Location |
| --- | --- |
| Raw input delivery | `windows/core/ntuser/kernel/ntinput.c`, `input.c`, `kbd.c`, `newmouse.c` |
| System queue and routing | `windows/core/ntuser/kernel/queue.c`, `srvmsg.c` |
| Thread queue creation | `windows/core/ntuser/kernel/desktop.c`, `createw.c` |
| `NtUserGetMessage` / `NtUserPeekMessage` | `windows/core/ntuser/kernel/ntstubs.c` |
| `NtUserDispatchMessage` | `ntstubs.c` |
| Sent-message marshalling | `windows/core/ntuser/kernel/sendmsg.c` |
| Cross-thread calls | `windows/core/ntuser/client/clmsg.c:485` (`SendMessageWorker`) |

There are three message classes, and they behave differently:

| Class | Posted by | Delivered by | Can be filtered |
| --- | --- | --- | --- |
| **Posted** | `PostMessage` | `GetMessage`/`PeekMessage` | Yes — via a message filter or hook |
| **Sent** | `SendMessage` | Direct call into the target WndProc | Yes — via a `WH_CALLWNDPROC` hook |
| **Input** | Hardware | `GetMessage` after `TranslateMessage` | Yes — via `WH_GETMESSAGE` |

A **sent** message crosses threads: `SendMessage` to a window owned by another thread blocks the
caller until the target thread calls `GetMessage`/`PeekMessage` and processes the sent message. That
is why a thread that never pumps messages deadlocks every `SendMessage` aimed at it — the classic
"my window is frozen" bug. `SendMessageTimeout` and `SendMessageCallback` exist for exactly this.

### The window structure

```text
WND (kernel window object; declared in windows/core/ntuser/inc, created in createw.c)
 +-- spwndParent      parent window
 +-- spwndChild       first child
 +-- spwndOwner       owner (for owned top-level windows)
 +-- pcls             window class (CLS)
 +-- lpfnWndProc      window procedure
 +-- hTask            owning thread's queue
 +-- strName          window text
 +-- dwStyle / dwExStyle
 +-- rcWindow / rcClient
 +-- hrgnUpdate       update region
 +-- pSBInfo          scroll bar info
```

`GetParent` returns the **owner** for a top-level window and the **parent** for a child. That
surprises people: for an overlapped window with `WS_POPUP` set, `GetParent` returns the owner, not
`NULL`. Use `GetAncestor(hwnd, GA_PARENT)` for the unambiguous answer.

### Window classes

A class is registered per **process** (not per thread) with `RegisterClassExW`:

```c
WNDCLASSEXW wc = { sizeof(wc) };
wc.lpfnWndProc   = WndProc;
wc.hInstance     = hInst;
wc.hCursor       = LoadCursorW(NULL, (LPCWSTR)IDC_ARROW);
wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
wc.lpszClassName = L"MyWindowClass";
ATOM atom = RegisterClassExW(&wc);
```

Classes have a **style** that controls system behaviour:

| Style | Effect |
| --- | --- |
| `CS_HREDRAW` / `CS_VREDRAW` | Redraw the whole window on a horizontal/vertical resize |
| `CS_OWNDC` | Give every window its own DC (never released) |
| `CS_CLASSDC` | Share one DC among all windows of the class |
| `CS_PARENTDC` | Inherit the parent's DC |
| `CS_DBLCLKS` | Generate double-click messages |
| `CS_NOCLOSE` | Disable the close box |
| `CS_SAVEBITS` | Save the bits under the window (popups) |
| `CS_BYTEALIGNCLIENT` / `CS_BYTEALIGNWINDOW` | Align the client/window area |
| `CS_GLOBALCLASS` | Make the class process-global |

A window class exists until `UnregisterClass` or the process exits. `CS_OWNDC` windows each consume a
DC from the (limited) system pool; creating thousands of them exhausts GDI handles.

## The shell

`shell/` is the shell source. The important DLLs:

| Binary | Source | Role |
| --- | --- | --- |
| `shell32.dll` | `shell/shell32` | The shell object model, `IShellFolder`, `IShellLink`, `SHGetFolderPath`, `SHFileOperation` |
| `shlwapi.dll` | `shell/shlwapi` | Path and string helpers (`PathAppend`, `StrChr`, `SHCreateStreamOnFile`) |
| `comctl32.dll` | `shell/comctl32` | Common controls v5 and v6, including the theme-aware controls |
| `comdlg32.dll` | `shell/comdlg32` | Open/Save, Print, ChooseFont, ChooseColor |
| `shdocvw.dll` | `shell/shdocvw` | The Web View / shell namespace extension host |
| `browseui.dll` | `shell/browseui` | Explorer's browser UI |
| `explorer.exe` | `shell/explorer` | The desktop process |
| `shsvc.dll`, `shgina.dll` | `shell/` | Shell services and the GINA |

### The shell namespace

The shell is a **namespace**: a tree of `IShellFolder` items addressed by `ITEMIDLIST` (PIDL). The
desktop is the root; `My Computer`, `Recycle Bin`, `Control Panel` and the filesystem are children.

| Interface | Purpose |
| --- | --- |
| `IShellFolder` | Enumerate children, bind to a child, compare PIDLs |
| `IShellFolder2` | Extended details (`GetDetailsOf`, `GetDefaultColumn`) |
| `IPersistFolder` | Initialize a folder with a PIDL |
| `IPersistFolder2` | Plus `GetCurFolder` |
| `IShellLink` / `IShellLinkW` | Shortcut resolution and saving |
| `IContextMenu` | Verbs for a right-click |
| `IDataObject` | Clipboard and drag-drop data |
| `IDropTarget` | Drop handling |
| `IExtractIcon` | Icon extraction |
| `IShellExtInit` | Initialize an extension with a PIDL and a data object |
| `IColumnProvider` | Extra columns in Explorer |

A PIDL is a self-relative `ITEMIDLIST`: an array of `SHITEMID`, each with `cb` and `abID`. The
filesystem part is a `SHITEMID` whose `abID` is a file-attributes-plus-name blob. **Never** assume
the layout of a PIDL — only the shell implementation knows it. Use `ILFindLastID`, `ILRemoveLastID`,
`ILClone`, `ILGetSize`, `ILFree`.

### Name-space extension registration

A namespace extension is a COM object registered under a shell key:

```text
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\explorer\MyComputer\NameSpace\{clsid}
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\explorer\NetworkNeighborhood\NameSpace\{clsid}
HKCR\Directory\Background\shellex\ContextMenuHandlers\{name}
HKCR\Folder\shellex\ContextMenuHandlers\{name}
HKCR\*\shellex\ContextMenuHandlers\{name}
```

The shell enumerates those keys, `CoCreateInstance`s the CLSID, and calls `IShellExtInit::Initialize`
then `IContextMenu::QueryContextMenu` / `InvokeCommand`. A slow extension delays every right-click in
Explorer; a crash takes Explorer down because extensions load **in-process**.

### `SHFileOperation` and the file operation contract

`SHFileOperation` is the shell's copy/move/delete/rename API. It is used by Explorer's drag-drop and
by installers. Its behaviour differs from `CopyFile` in ways that matter:

- It honours the shell's confirmation dialogs (`FOF_NOCONFIRMATION` suppresses them).
- It can undo (`FOF_ALLOWUNDO` sends deletes to the Recycle Bin).
- It resolves shell links (`FOF_NOLINKINFO` suppresses that).
- It reports progress (`FOF_SIMPLEPROGRESS`, `IFileOperationProgressSink`).
- It does **not** preserve NTFS ACLs on a copy, and it may coalesce operations.

For a faithful copy that preserves everything, use `CopyFileExW` or `BackupRead`/`BackupWrite`, not
`SHFileOperation`.

## GDI drawing model

| Concept | What it is |
| --- | --- |
| **DC** | A device context: a bundle of a device, a graphics mode, and the currently selected objects |
| **Bitmap** | A pixel buffer; a DIB has a documented header, a DDB is device-dependent |
| **Brush** | A fill pattern: solid, hatched, or a bitmap |
| **Pen** | A line style: cosmetic (1 px) or geometric (width, join, cap) |
| **Font** | A `LOGFONT` selection; the font mapper picks the closest installed face |
| **Region** | A set of rectangles/curves used for clipping |
| **Palette** | A logical-to-physical colour table for 8-bpp devices |
| **Path** | A sequence of lines and curves that can be stroked, filled, or clipped |

The draw sequence is always:

```c
HDC hdc = BeginPaint(hwnd, &ps);          // 1. get a DC, validate the update region
HBRUSH brush = CreateSolidBrush(RGB(255,0,0));
HGDIOBJ old = SelectObject(hdc, brush);    // 2. select the object
FillRect(hdc, &ps.rcPaint, brush);         // 3. draw
SelectObject(hdc, old);                    // 4. restore the old object
DeleteObject(brush);                       // 5. delete your object
EndPaint(hwnd, &ps);                       // 6. release the DC
```

Skipping step 4 leaks the default object into your DC; skipping step 5 leaks the brush. A GDI object
is not freed by `SelectObject` — only `DeleteObject` frees it, and only when it is **not selected
into any DC**.

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

### Q: Why does `GetParent` return a non-NULL value for a top-level window?

Because for an overlapped or popup window it returns the **owner**, not the parent. A top-level
window has no parent in the child-window sense; it has an owner (set by passing `hwndParent` to
`CreateWindowEx`, or by `SetWindowLongPtr(GWLP_HWNDPARENT)`). To get the unambiguous answer, call
`GetAncestor(hwnd, GA_PARENT)` and check `GetWindowLongPtr(hwnd, GWL_STYLE) & WS_CHILD`.

### Q: Why does `SendMessage` hang?

Because a sent message is a **cross-thread call**. The calling thread blocks until the target thread
retrieves the message, which only happens when the target calls `GetMessage`/`PeekMessage`. If the
target thread is busy or does not pump messages, the sender waits forever. Use `SendMessageTimeout`
with `SMTO_ABORTIFHUNG` or `SMTO_NOTIMEOUTIFNOTHUNG`, or post the message instead.

### Q: What is the difference between a `WM_PAINT` and a `WM_NCPAINT`?

`WM_PAINT` paints the client area; `WM_NCPAINT` paints the non-client area (frame, title bar, menu
bar). `BeginPaint`/`EndPaint` handle `WM_PAINT`'s validation. `WM_NCPAINT` is sent when the frame
needs redrawing; `DefWindowProc` does the default painting, so a custom frame must handle it and
call `DefWindowProc` for anything it does not draw.

### Q: Why does my window flicker when it resizes?

Because `WM_ERASEBKGND` erases the whole client area and then `WM_PAINT` redraws it. Register the
class with `CS_HREDRAW|CS_VREDRAW` off (or handle `WM_ERASEBKGND` by returning 1 without erasing),
and paint the whole client area in one pass. For complex windows, use a memory DC and `BitBlt` the
finished image once, or enable `WS_EX_COMPOSITED`.

### Q: How do I make a window topmost?

`SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE)`. A topmost
window stays above all non-topmost windows. To demote it, use `HWND_NOTOPMOST`. Only one window can be
foreground at a time; `SetForegroundWindow` has restrictions to prevent focus stealing.

### Q: Where is the desktop window and can I get its handle?

`GetDesktopWindow()` returns it. It is created by the window manager at desktop initialization
(`windows/core/ntuser/kernel/desktop.c`). It is a real `HWND`, but you should not subclass it or
draw on it directly: the shell owns the desktop background, and doing so breaks wallpaper and
icon layout. Use `SHGetDesktopFolder` if you want the shell namespace root.

### Q: What is the difference between `LoadMenu` and `LoadMenuIndirect`?

`LoadMenuW` loads a menu **resource** by name or ID from a module. `LoadMenuIndirectW` loads a menu
from an in-memory `MENUTEMPLATE` — the same template the resource compiler emits. `LoadMenuIndirect`
is what you use when the template comes from somewhere other than a resource, for example a
custom menu builder.

### Q: Why does my icon disappear at 16 colours?

Because a `.ico` file can contain multiple images, and the shell picks the best match for the current
display depth. If the file only has a 256-colour image, a 16-colour display gets a dithered mess.
Ship 16x16, 32x32 and 48x48 images at 4, 8, 32 bpp. `LoadIconW` and `LoadImageW` select from the
group icon; `SHDefExtractIcon` does the same with shell fallbacks.

### Q: How do I host a shell namespace extension out of process?

You do not, for `IContextMenu` and `IShellFolder` — the shell loads them in-process by design. The
supported out-of-process options are a `ShellExecute`-launched helper, a `BackgroundCopyHandler`, or
a COM local server used for a specific verb. A crashing in-process extension takes Explorer with it,
which is why extension authors are told to test under `Application Verifier` with low resources.

### Q: What is `SHGetFolderPath` doing that `GetWindowsDirectory` does not?

It resolves a **CSIDL** to a per-user or per-machine path through the shell's folder database, so
it works for `CSIDL_PERSONAL` (My Documents), `CSIDL_APPDATA`, `CSIDL_LOCAL_APPDATA`, `CSIDL_PROGRAM_FILES`,
and so on. `GetWindowsDirectory` only returns `%SystemRoot%`. `SHGetFolderPath` is deprecated in
favour of `SHGetKnownFolderPath`, which takes a `KNOWNFOLDERID` GUID and is the only API that
supports per-user redirection and virtual folders.
