---
title: USER — windows, messages and input
sidebar_position: 17
description: Window classes, window creation, the message loop, dialogs, timers, hooks and the clipboard — how user32 forwards to NtUser* and where win32k implements each call.
---

USER is the windowing half of Win32. It lives in two halves that share a header set:

```text
application
   |  user32.dll  (windows/core/ntuser/client)
   |  CreateWindowExW -> _CreateWindowEx -> NtUserCreateWindowEx
   v
win32k.sys     (windows/core/ntuser/kernel)   + windows/core/ntgdi/kernel
   |  window manager, input, desktop, hooks, clipboard
   v
kernel (base/ntos) -- imports fixed by base/ntos/init/w32kexps.txt
```

The client side is `windows/core/ntuser/client`, built as `user32.dll` (`TARGETNAME=user32` in
`sources.inc`). The server side is `windows/core/ntuser/kernel`, linked into `win32k.sys`. The
`NtUser*` names are the syscall surface; the plain Win32 names are the published API.

`user32.def` is the export list, and it shows that a number of exports are **direct forwarders**:

```text
    LockWindowStation = NtUserLockWindowStation         PRIVATE
    UnlockWindowStation = NtUserUnlockWindowStation     PRIVATE
    QuerySendMessage = NtUserQuerySendMessage           PRIVATE
    SetTimer = NtUserSetTimer
```

So `SetTimer` is not a separate implementation: the export points straight at the syscall stub.
That is a useful clue when tracing — if the `.def` says `= NtUserXxx`, the client-side function does
not exist.

## Window classes

A window cannot be created until its class is registered. `RegisterClassExW` takes a
`WNDCLASSEXW`:

```c
typedef struct tagWNDCLASSEXW {
    UINT       cbSize;
    UINT       style;
    WNDPROC    lpfnWndProc;
    int        cbClsExtra;
    int        cbWndExtra;
    HINSTANCE  hInstance;
    HICON      hIcon;
    HCURSOR    hCursor;
    HBRUSH     hbrBackground;
    LPCWSTR    lpszMenuName;
    LPCWSTR    lpszClassName;
    HICON      hIconSm;
} WNDCLASSEXW;
```

Class styles that matter:

| Style | Effect |
| --- | --- |
| `CS_HREDRAW` / `CS_VREDRAW` | Redraw the whole window on horizontal/vertical resize |
| `CS_OWNDC` | Give each window its own device context |
| `CS_CLASSDC` | Share one DC across all windows of the class |
| `CS_PARENTDC` | Use the parent's DC |
| `CS_DBLCLKS` | Deliver `WM_LBUTTONDBLCLK` instead of two clicks |
| `CS_GLOBALCLASS` | Register the class globally (not per-instance) |

A class is owned by the module that registers it. Creating a window of a class registered by
another module is possible only for system classes (`BUTTON`, `EDIT`, `LISTBOX`, `STATIC`,
`COMBOBOX`, `SCROLLBAR`, `MDICLIENT`) or with explicit care; this is why "class not found" errors
often mean "wrong `hInstance`".

The client-side registration path is in `windows/core/ntuser/client/classc.c` and the kernel side
in `windows/core/ntuser/kernel/class.c`.

## Window creation

The published entry point is `CreateWindowExW`. Its implementation is the shared `_CreateWindowEx`
at [`windows/core/ntuser/client/ntstubs.c:1520`](https://github.com/havaianasdestruido/neo-nt5/blob/main/windows/core/ntuser/client/ntstubs.c#L1520),
which builds `LARGE_STRING` structures for the class and title, validates extended styles, and calls
the syscall:

```c
HWND _CreateWindowEx(
    DWORD dwExStyle,
    LPCTSTR pClassName,
    LPCTSTR pWindowName,
    DWORD dwStyle,
    int x,
    int y,
    int nWidth,
    int nHeight,
    HWND hwndParent,
    HMENU hmenu,
    HANDLE hModule,
    LPVOID pParam,
    DWORD dwFlags)
```

The kernel side is `NtUserCreateWindowEx` at
[`windows/core/ntuser/kernel/ntstubs.c:8005`](https://github.com/havaianasdestruido/neo-nt5/blob/main/windows/core/ntuser/kernel/ntstubs.c#L8005),
and the real work is in `createw.c`. Three parameters are worth understanding:

- `pstrNVClassName` is the **non-volatile** class name; the two name parameters exist because a
  class can be identified either by a full name or by an atom.
- `PLARGE_STRING`, not `UNICODE_STRING`: the window manager needs strings longer than
  `UNICODE_STRING` allows.
- `PACTIVATION_CONTEXT` ties window creation to side-by-side assembly resolution
  (`base/win32/fusion`, `base/ntdll/sxsactctx.c`).

### Styles and extended styles

`dwStyle` comes from `winuser.h`: `WS_OVERLAPPED`, `WS_POPUP`, `WS_CHILD`, `WS_VISIBLE`,
`WS_DISABLED`, `WS_CAPTION`, `WS_SYSMENU`, `WS_THICKFRAME`, `WS_MINIMIZEBOX`, `WS_MAXIMIZEBOX`,
`WS_CLIPCHILDREN`, `WS_CLIPSIBLINGS`. `dwExStyle` includes `WS_EX_TOPMOST`, `WS_EX_TOOLWINDOW`,
`WS_EX_TRANSPARENT`, `WS_EX_ACCEPTFILES`, `WS_EX_APPWINDOW`, `WS_EX_LAYERED`,
`WS_EX_NOACTIVATE`, `WS_EX_COMPOSITED`.

Two rules that catch people:

- `WS_CHILD` and `WS_POPUP` are mutually exclusive. `WS_POPUP` is implied when `WS_CHILD` is absent
  and no parent is supplied.
- `WS_VISIBLE` causes the window to be shown on creation; without it you must call `ShowWindow`.
  `CreateWindowExW` returns a valid hidden window either way.

## The message loop

A Win32 GUI thread runs this loop:

```c
MSG msg;
while (GetMessageW(&msg, NULL, 0, 0) > 0) {
    TranslateMessage(&msg);
    DispatchMessageW(&msg);
}
```

`GetMessageW` has three return states:

| Return | Meaning |
| --- | --- |
| `> 0` | A message other than `WM_QUIT` was retrieved |
| `0` | `WM_QUIT` was retrieved; exit the loop |
| `-1` | An error occurred; `GetLastError` |

Testing only `while (GetMessageW(...))` is a bug: `-1` is truthy, so an error would keep the loop
spinning.

The kernel side is `NtUserGetMessage` at
`windows/core/ntuser/kernel/ntstubs.c:1975` and `NtUserPeekMessage` at `:5567`.
`DispatchMessageW` calls the window procedure; for a thread with no window, messages are still
delivered to thread message targets (`PostThreadMessage`).

### The `MSG` structure

```c
typedef struct tagMSG {
    HWND   hwnd;
    UINT   message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD  time;
    POINT  pt;
} MSG;
```

`hwnd == NULL` means a thread message. `pt` is in screen coordinates at the time the message was
generated; `GetMessagePos` returns the same information for the last retrieved message.

## Window procedures

```c
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) {
    case WM_CREATE:
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProcW(hwnd, msg, wParam, lParam);
    }
}
```

`DefWindowProcW` must be called for every message you do not handle. It implements default
behaviour for `WM_CLOSE`, `WM_PAINT`, `WM_SETCURSOR`, `WM_NCHITTEST`, non-client area painting and
dozens of system messages. Omitting it produces a window that cannot be moved, closed or painted.

`CallWindowProcW` (`windows/core/ntuser/client/clmsg.c:2217`) calls a window procedure that may be
a Unicode or ANSI procedure; it is how subclassing works. `SetWindowLongPtrW(hwnd, GWLP_WNDPROC, ...)`
returns the previous procedure, which you must pass to `CallWindowProcW` to keep the default
behaviour.

### Messages you will handle most

| Message | Sent when | Typical handling |
| --- | --- | --- |
| `WM_CREATE` | Window is being created | Initialise, return 0 |
| `WM_PAINT` | Part of the client area is invalid | `BeginPaint`/`EndPaint` and draw |
| `WM_SIZE` | Window size changed | Recompute layout |
| `WM_COMMAND` | Menu, control or accelerator | Inspect `LOWORD(wParam)` |
| `WM_NOTIFY` | Common control notification | Inspect `NMHDR` |
| `WM_CLOSE` | User asks to close | Destroy or ask for confirmation |
| `WM_DESTROY` | Window is being destroyed | Free resources, `PostQuitMessage` for the main window |
| `WM_TIMER` | A timer expired | Do periodic work |
| `WM_KEYDOWN` / `WM_CHAR` | Keyboard input | Translate or handle |
| `WM_MOUSEMOVE`, `WM_LBUTTONDOWN` | Mouse input | Hit-test and act |
| `WM_SETCURSOR` | Mouse moved and input is idle | Set a cursor |
| `WM_NCHITTEST` | Hit-testing the non-client area | Return `HTCLIENT`/`HTCAPTION`/... |

### A complete window

```c
#include <windows.h>

static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) {
    case WM_CREATE:
        return 0;

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        TextOutW(hdc, 10, 10, L"hello, USER", 11);
        EndPaint(hwnd, &ps);
        return 0;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

int APIENTRY wWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPWSTR cmd, int show)
{
    WNDCLASSEXW wc = { sizeof(wc) };
    wc.style         = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc   = WndProc;
    wc.hInstance     = hInst;
    wc.hCursor       = LoadCursorW(NULL, (LPCWSTR)IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = L"NeoWikiWindow";
    if (!RegisterClassExW(&wc)) {
        return 0;
    }

    HWND hwnd = CreateWindowExW(
        0, L"NeoWikiWindow", L"NEONT wiki demo",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 640, 480,
        NULL, NULL, hInst, NULL);
    if (!hwnd) {
        return 0;
    }

    ShowWindow(hwnd, show);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessageW(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return (int)msg.wParam;
}
```

## Dialogs

`CreateDialogParamW` (`windows/core/ntuser/client/clres.c:1008`) creates a modeless dialog from a
resource template; `DialogBoxParamW` is the modal wrapper that runs its own message loop. The
dialog procedure returns `TRUE` if it handled a message and `FALSE` to let the default procedure
run — the opposite convention from a window procedure, and a frequent source of bugs.

```c
static INT_PTR CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) {
    case WM_INITDIALOG:
        return TRUE;                     // handled; do not let the default set focus
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
            EndDialog(hDlg, LOWORD(wParam));
            return TRUE;
        }
        break;
    }
    return FALSE;                        // let the default dialog procedure run
}
```

## Timers

`SetTimer` is a direct forwarder to `NtUserSetTimer` (`user32.def`), whose kernel implementation is
at `windows/core/ntuser/kernel/ntstubs.c:6029`.

```c
UINT_PTR id = SetTimer(hwnd, 1, 1000, NULL);   // WM_TIMER every second
// ...
KillTimer(hwnd, 1);
```

Timer messages are **low priority** and coalesced: if the thread is busy, multiple expirations may
be delivered as one `WM_TIMER`. Never use a UI timer for precise timing; use
`QueryPerformanceCounter` or a waitable timer.

## Hooks

`SetWindowsHookExW` (`windows/core/ntuser/client/clhook.c:114`) installs a hook procedure in the
hook chain. The `idHook` values include `WH_KEYBOARD`, `WH_MOUSE`, `WH_CBT`, `WH_SHELL`,
`WH_GETMESSAGE`, `WH_CALLWNDPROC`. A global hook (`dwThreadId == 0`) requires a DLL because the
procedure must be injected into every process with a matching desktop.

```c
HHOOK hHook = SetWindowsHookExW(WH_KEYBOARD_LL, LowLevelKeyboardProc, hInst, 0);
// ...
UnhookWindowsHookEx(hHook);
```

Low-level hooks (`WH_KEYBOARD_LL`, `WH_MOUSE_LL`) run on the installing thread, which must have a
message loop — without one, the hook never fires. The kernel-side hook machinery is in
`windows/core/ntuser/kernel/hooks.c`.

## Clipboard

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `OpenClipboard` | Acquire the clipboard lock | `windows/core/ntuser/client/ntstubs.c:836` | [OpenClipboard](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-openclipboard) |
| `CloseClipboard` | Release it | client side | [CloseClipboard](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-closeclipboard) |
| `EmptyClipboard` | Clear ownership and contents | client side | [EmptyClipboard](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-emptyclipboard) |
| `SetClipboardData` | Publish a format | client side | [SetClipboardData](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setclipboarddata) |
| `GetClipboardData` | Read a format | `windows/core/ntuser/client/client.c:406` | [GetClipboardData](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getclipboarddata) |
| `RegisterClipboardFormatW` | Register a private format | client side | [RegisterClipboardFormatW](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) |

```c
if (OpenClipboard(hwnd)) {
    EmptyClipboard();
    HGLOBAL h = GlobalAlloc(GMEM_MOVEABLE, (wcslen(text) + 1) * sizeof(wchar_t));
    if (h) {
        wcscpy((wchar_t *)GlobalLock(h), text);
        GlobalUnlock(h);
        SetClipboardData(CF_UNICODETEXT, h);   // system owns h after a successful call
    }
    CloseClipboard();
}
```

After a successful `SetClipboardData` the system owns the memory; do not free it.

## Function reference table

| Function | Header | Implementation | Documentation |
| --- | --- | --- | --- |
| `CreateWindowExW` | `winuser.h` | `windows/core/ntuser/client/ntstubs.c:1520` | [CreateWindowExW](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createwindowexw) |
| `RegisterClassExW` | `winuser.h` | `windows/core/ntuser/client/classc.c` | [RegisterClassExW](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-registerclassexw) |
| `DefWindowProcW` | `winuser.h` | `windows/core/ntuser/client/clmsg.c` | [DefWindowProcW](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-defwindowprocw) |
| `CallWindowProcW` | `winuser.h` | `windows/core/ntuser/client/clmsg.c:2217` | [CallWindowProcW](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-callwindowprocw) |
| `GetMessageW` | `winuser.h` | `windows/core/ntuser/client/ntstubs.c` | [GetMessageW](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getmessagew) |
| `PeekMessageW` | `winuser.h` | client side | [PeekMessageW](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-peekmessagew) |
| `DispatchMessageW` | `winuser.h` | client side | [DispatchMessageW](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-dispatchmessagew) |
| `PostMessageW` | `winuser.h` | client side | [PostMessageW](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-postmessagew) |
| `SendMessageW` | `winuser.h` | `windows/core/ntuser/client/clmsg.c` | [SendMessageW](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-sendmessagew) |
| `PostQuitMessage` | `winuser.h` | client side | [PostQuitMessage](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-postquitmessage) |
| `SetTimer` | `winuser.h` | forwarder to `NtUserSetTimer` (`kernel/ntstubs.c:6029`) | [SetTimer](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-settimer) |
| `KillTimer` | `winuser.h` | client side | [KillTimer](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-killtimer) |
| `ShowWindow` | `winuser.h` | client side | [ShowWindow](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-showwindow) |
| `UpdateWindow` | `winuser.h` | `windows/core/ntuser/client/client.c:3809` | [UpdateWindow](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-updatewindow) |
| `DestroyWindow` | `winuser.h` | client side | [DestroyWindow](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-destroywindow) |
| `IsWindow` | `winuser.h` | `windows/core/ntuser/client/wow.c:289` | [IsWindow](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-iswindow) |
| `GetParent` | `winuser.h` | `windows/core/ntuser/client/wow.c:335` | [GetParent](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getparent) |
| `GetClientRect` | `winuser.h` | `windows/core/ntuser/client/wow.c:664` | [GetClientRect](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getclientrect) |
| `GetWindowRect` | `winuser.h` | `windows/core/ntuser/client/wow.c:690` | [GetWindowRect](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getwindowrect) |
| `GetSystemMetrics` | `winuser.h` | `windows/core/ntuser/client/wow.c:423` | [GetSystemMetrics](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getsystemmetrics) |
| `EnableWindow` | `winuser.h` | `windows/core/ntuser/client/client.c:3138` | [EnableWindow](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-enablewindow) |
| `LoadCursorW` | `winuser.h` | `windows/core/ntuser/client/clres.c:2419` | [LoadCursorW](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-loadcursorw) |
| `LoadIconW` | `winuser.h` | `windows/core/ntuser/client/clres.c:2467` | [LoadIconW](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-loadiconw) |
| `MessageBoxW` | `winuser.h` | `windows/core/ntuser/client/msgbox.c:315` | [MessageBoxW](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-messageboxw) |
| `CreateDialogParamW` | `winuser.h` | `windows/core/ntuser/client/clres.c:1008` | [CreateDialogParamW](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createdialogparamw) |
| `SetWindowsHookExW` | `winuser.h` | `windows/core/ntuser/client/clhook.c:114` | [SetWindowsHookExW](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setwindowshookexw) |
| `OpenClipboard` | `winuser.h` | `windows/core/ntuser/client/ntstubs.c:836` | [OpenClipboard](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-openclipboard) |
| `GetClipboardData` | `winuser.h` | `windows/core/ntuser/client/client.c:406` | [GetClipboardData](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getclipboarddata) |

## Frequently asked questions

### Q: Why is `SetTimer` listed as a forwarder in `user32.def`?

Because the export table points directly at `NtUserSetTimer`. There is no client-side
`SetTimer` function in `user32`; the loader resolves the export to the syscall stub. The kernel
implementation is at `windows/core/ntuser/kernel/ntstubs.c:6029`. The same is true of
`LockWindowStation`, `UnlockWindowStation` and `QuerySendMessage`.

### Q: Why does `CreateWindowExW` take 12 parameters when the syscall takes 14?

Because the client wrapper (`_CreateWindowEx` at `ntstubs.c:1520`) computes the extra parameters:
the non-volatile class name and the activation context. The syscall is
`NtUserCreateWindowEx` (`kernel/ntstubs.c:8005`). Adding a parameter means changing both sides plus
the generated stub, which is why the tree keeps them in lockstep.

### Q: Why is my `WM_PAINT` handler never called?

Because `WM_PAINT` is generated only when the window has an invalid region and the message queue is
empty. If you never call `BeginPaint`/`EndPaint`, or you validate the region elsewhere, the message
is not generated. `UpdateWindow` forces a synchronous `WM_PAINT` if the region is invalid.

### Q: What is the difference between `SendMessage` and `PostMessage`?

`SendMessage` calls the target window procedure directly and **waits** for the result; if the target
belongs to another thread, the sending thread blocks until the target processes the message (unless
`SMTO_NOTIMEOUT`/`SendMessageTimeout` is used). `PostMessage` queues the message and returns
immediately. Sending to a thread that is blocked on you is the classic deadlock.

### Q: How do I handle a message for a window I do not own?

Subclass it: `SetWindowLongPtrW(hwnd, GWLP_WNDPROC, (LONG_PTR)NewProc)`, then call
`CallWindowProcW(oldProc, ...)` for the messages you pass through. For cross-process subclassing,
the procedure must be in a DLL injected into the target process; otherwise the address is invalid.

### Q: Why does `GetMessageW` return `-1`?

On an error such as an invalid window handle or a failed syscall. Because `-1` is nonzero, a
`while (GetMessageW(...))` loop treats it as success and keeps running. Always compare `> 0`.

### Q: Where is the kernel-mode window manager?

`windows/core/ntuser/kernel`, with the syscall entry points collected in
[`ntstubs.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/windows/core/ntuser/kernel/ntstubs.c)
and the real implementation split across `createw.c`, `class.c`, `clmsg.c`, `hooks.c`, `input.c`,
`desktop.c`, `clipbrd.c` and others. `win32k.sys` is the kernel binary that contains it.

### Q: Is the clipboard a kernel object?

The clipboard is a per-desktop structure owned by the window manager. `OpenClipboard` acquires it
and records the owner window; `SetClipboardData` publishes a format. The data itself lives in
global memory objects owned by the process. Delayed rendering (`SetClipboardData(fmt, NULL)`) lets
the owner supply the data on demand through `WM_RENDERFORMAT`.

### Q: How do I find the implementation of a user32 function?

```bash
# 1. is it a direct forwarder?
grep -n 'SomeFunction' windows/core/ntuser/client/user32.def

# 2. is it implemented client-side?
rg -n 'SomeFunction' windows/core/ntuser/client

# 3. which syscall does it call?
rg -n 'NtUserSomeFunction' windows/core/ntuser/kernel
```

If step 1 shows `= NtUserXxx`, step 2 will find nothing — the export is the syscall.
