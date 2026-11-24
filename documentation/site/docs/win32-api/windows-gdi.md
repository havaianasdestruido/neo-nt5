---
title: "Windows, messages and GDI"
sidebar_position: 18
description: "RegisterClassExW, CreateWindowExW, the message loop and WM_PAINT: official signatures, the tree locations of the window manager and compiled examples."
---

# Windows, messages and GDI

Window creation and message dispatch are split between the user-mode client and the kernel-mode window manager. The user-mode USER32 client is in `windows/core/ntuser/client`: `user32.def` exports the functions, and `cltxt.h` and `ntcftxt.h` wrap each one in logging macros before it calls the kernel service (for example `NtUserCreateWindowEx`, declared in `windows/core/ntuser/inc/ntuser.h`). `TextOutW` is in the user-mode GDI client, `windows/core/ntgdi/client`. The message loop calls `GetMessageW`, which blocks on the thread's message queue; `DispatchMessageW` then calls the window procedure registered with `RegisterClassExW`.

Drawing is performed in `WM_PAINT`, between `BeginPaint` and `EndPaint`. Calling GDI outside that pair is valid for a device context you obtained yourself, but it is not the same contract.

This page covers **13 functions**: [`RegisterClassExW`](#registerclassexw), [`CreateWindowExW`](#createwindowexw), [`ShowWindow`](#showwindow), [`GetMessageW`](#getmessagew), [`TranslateMessage`](#translatemessage), [`DispatchMessageW`](#dispatchmessagew), [`DefWindowProcW`](#defwindowprocw), [`PostQuitMessage`](#postquitmessage), [`MessageBoxW`](#messageboxw), [`DestroyWindow`](#destroywindow), [`BeginPaint`](#beginpaint), [`EndPaint`](#endpaint), [`TextOutW`](#textoutw).

## Shared setup

Paste this block at the top of your source file, then one or more example functions below, then call them from `main`. The complete, compiled file is [window.c](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/window.c).

```c
/*
 * Win32 window, message-loop and GDI examples for the NEONT 5 documentation site.
 *
 * Build with MinGW-w64 or zig cc (any Windows target):
 *     zig cc -target x86_64-windows-gnu -std=c11 -Wall -Wextra -Werror window.c -o window.exe -luser32 -lgdi32 -lkernel32
 * Build with MSVC:
 *     cl /nologo /W4 /WX window.c user32.lib gdi32.lib
 *
 * The default main() runs only examples that return by themselves. MessageBoxW
 * blocks until someone clicks OK, so it runs only when built with -DDEMO_INTERACTIVE.
 */
#define UNICODE
#define _UNICODE
#include <windows.h>
#include <stdio.h>
#include <wchar.h>

#define DEMO_CLASS L"NEONT5DocsWindowClass"
#define WM_DEMO_PING (WM_APP + 1)

static volatile LONG g_pings = 0;

/* Window procedure shared by every example. The system calls it for each message. */
static LRESULT CALLBACK demo_wnd_proc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) {
    case WM_DEMO_PING:
        InterlockedIncrement(&g_pings);
        return 0;
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);          /* must pair with EndPaint, only inside WM_PAINT */
        TextOutW(hdc, 10, 10, L"Hello from NEONT 5", 18);
        EndPaint(hwnd, &ps);
        return 0;
    }
    default:
        return DefWindowProcW(hwnd, msg, wParam, lParam);
    }
}

/* Shared helper: register the window class once per example and return its atom. */
static ATOM register_demo_class(void)
{
    WNDCLASSEXW wc;
    ZeroMemory(&wc, sizeof(wc));
    wc.cbSize = sizeof(wc);
    wc.lpfnWndProc = demo_wnd_proc;
    wc.hInstance = GetModuleHandleW(NULL);
    wc.hCursor = LoadCursorW(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = DEMO_CLASS;
    return RegisterClassExW(&wc);
}

/* Shared helper: create a hidden-by-default top-level window of the demo class. */
static HWND create_demo_window(void)
{
    return CreateWindowExW(0, DEMO_CLASS, L"NEONT 5 documentation", WS_OVERLAPPEDWINDOW,
                           CW_USEDEFAULT, CW_USEDEFAULT, 320, 200,
                           NULL, NULL, GetModuleHandleW(NULL), NULL);
}
```

## Functions

## RegisterClassExW

Registers a window class for subsequent use in calls to the [CreateWindow](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createwindowa) or [CreateWindowEx](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createwindowexa) function.

| Attribute | Value |
| --- | --- |
| Header | `winuser.h` (include `Windows.h`) |
| Library | User32.lib (DLL `User32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps only] |
| Minimum server | Windows 2000 Server [desktop apps only] |
| Character set | RegisterClassExW (Unicode) and RegisterClassExA (ANSI) |
| API set | `ext-ms-win-ntuser-windowclass-l1-1-0 (introduced in Windows 8)` |
| Official reference | [RegisterClassExW function (winuser.h)](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-registerclassexw) |
| In this tree | [`windows/core/ntuser/client/user32.def:967`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/windows/core/ntuser/client/user32.def#L967) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
ATOM WINAPI RegisterClassExW(
    CONST WNDCLASSEXW *
);
```

**Return value.** Type: **ATOM** If the function succeeds, the return value is a class atom that uniquely identifies the class being registered. This atom can only be used by the [CreateWindow](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createwindowa), [CreateWindowEx](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createwindowexa), [GetClassInfo](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getclassinfoa), [GetClassInfoEx](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getclassinfoexa), [FindWindow](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-findwindowa), [FindWindowEx](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-findwindowexa), and [UnregisterClass](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-unregisterclassa) functions and the **IActiveIMMap::FilterClientWindows** method.

**Tested example** — `example_RegisterClassExW` in [`window.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/window.c):

```c
static void example_RegisterClassExW(void)
{
    ATOM atom = register_demo_class();
    if (atom == 0) {
        wprintf(L"RegisterClassExW failed: %lu\n", GetLastError());
        return;
    }
    wprintf(L"Window class registered (atom %u)\n", (unsigned)atom);
    UnregisterClassW(DEMO_CLASS, GetModuleHandleW(NULL));
}
```

## CreateWindowExW

Creates an overlapped, pop-up, or child window with an extended window style; otherwise, this function is identical to the [CreateWindow](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createwindoww) function. For more information about creating a window and for full descriptions of the other parameters of **CreateWindowEx**, see **CreateWindow**.

| Attribute | Value |
| --- | --- |
| Header | `winuser.h` (include `Windows.h`) |
| Library | User32.lib (DLL `User32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps only] |
| Minimum server | Windows 2000 Server [desktop apps only] |
| Character set | CreateWindowExW (Unicode) and CreateWindowExA (ANSI) |
| API set | `ext-ms-win-ntuser-window-l1-1-0 (introduced in Windows 8)` |
| Official reference | [CreateWindowExW function (winuser.h)](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createwindowexw) |
| In this tree | [`windows/core/ntuser/client/cltxt.h:39`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/windows/core/ntuser/client/cltxt.h#L39) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
HWND WINAPI CreateWindowExW(
    DWORD dwExStyle,
    LPCWSTR lpClassName,
    LPCWSTR lpWindowName,
    DWORD dwStyle,
    int X,
    int Y,
    int nWidth,
    int nHeight,
    HWND hWndParent,
    HMENU hMenu,
    HINSTANCE hInstance,
    LPVOID lpParam
);
```

**Return value.** Type: **HWND** If the function succeeds, the return value is a handle to the new window.

**Tested example** — `example_CreateWindowExW` in [`window.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/window.c):

```c
static void example_CreateWindowExW(void)
{
    if (register_demo_class() == 0) return;
    HWND hwnd = create_demo_window();
    if (hwnd == NULL) {
        wprintf(L"CreateWindowExW failed: %lu\n", GetLastError());
    } else {
        wprintf(L"Window handle %p created\n", (void *)hwnd);
        DestroyWindow(hwnd);
    }
    UnregisterClassW(DEMO_CLASS, GetModuleHandleW(NULL));
}
```

## ShowWindow

Sets the specified window's show state.

| Attribute | Value |
| --- | --- |
| Header | `winuser.h` (include `Windows.h`) |
| Library | User32.lib (DLL `User32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps only] |
| Minimum server | Windows 2000 Server [desktop apps only] |
| Character set | - |
| API set | `ext-ms-win-ntuser-window-l1-1-0 (introduced in Windows 8)` |
| Official reference | [ShowWindow function (winuser.h)](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-showwindow) |
| In this tree | [`windows/core/ntuser/client/user32.def:185`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/windows/core/ntuser/client/user32.def#L185) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI ShowWindow(
    HWND hWnd,
    int nCmdShow
);
```

**Return value.** Type: **BOOL** If the window was previously visible, the return value is nonzero.

**Tested example** — `example_ShowWindow` in [`window.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/window.c):

```c
static void example_ShowWindow(void)
{
    if (register_demo_class() == 0) return;
    HWND hwnd = create_demo_window();
    if (hwnd != NULL) {
        ShowWindow(hwnd, SW_SHOWNOACTIVATE);   /* SW_HIDE would make it invisible again */
        ShowWindow(hwnd, SW_HIDE);
        DestroyWindow(hwnd);
    }
    UnregisterClassW(DEMO_CLASS, GetModuleHandleW(NULL));
}
```

## GetMessageW

Retrieves a message from the calling thread's message queue. The function dispatches incoming sent messages until a posted message is available for retrieval. Unlike **GetMessage**, the [PeekMessage](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-peekmessagea) function does not wait for a message to be posted before returning.

| Attribute | Value |
| --- | --- |
| Header | `winuser.h` (include `Windows.h`) |
| Library | User32.lib (DLL `User32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps only] |
| Minimum server | Windows 2000 Server [desktop apps only] |
| Character set | GetMessageW (Unicode) and GetMessageA (ANSI) |
| API set | `ext-ms-win-ntuser-message-l1-1-0 (introduced in Windows 8)` |
| Official reference | [GetMessageW function (winuser.h)](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getmessagew) |
| In this tree | [`windows/core/ntuser/client/ntcftxt.h:271`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/windows/core/ntuser/client/ntcftxt.h#L271) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI GetMessageW(
    LPMSG lpMsg,
    HWND hWnd,
    UINT wMsgFilterMin,
    UINT wMsgFilterMax
);
```

**Return value.** Type: **BOOL** If the function retrieves a message other than [WM_QUIT](https://learn.microsoft.com/en-us/windows/win32/winmsg/wm-quit), the return value is nonzero.

**Tested example** — `example_GetMessageW` in [`window.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/window.c):

```c
static void example_GetMessageW(void)
{
    MSG msg;
    /* Post WM_QUIT first so the loop ends immediately; a real program loops until GetMessageW returns 0. */
    PostQuitMessage(0);
    BOOL r;
    while ((r = GetMessageW(&msg, NULL, 0, 0)) > 0) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    /* r == 0 means WM_QUIT was retrieved; r == -1 means GetMessageW failed. */
    wprintf(L"Message loop ended with %d\n", (int)r);
}
```

## TranslateMessage

Translates virtual-key messages into character messages. The character messages are posted to the calling thread's message queue, to be read the next time the thread calls the [GetMessage](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getmessage) or [PeekMessage](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-peekmessagea) function.

| Attribute | Value |
| --- | --- |
| Header | `winuser.h` (include `Windows.h`) |
| Library | User32.lib (DLL `User32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps only] |
| Minimum server | Windows 2000 Server [desktop apps only] |
| Character set | - |
| API set | `ext-ms-win-ntuser-message-l1-1-0 (introduced in Windows 8)` |
| Official reference | [TranslateMessage function (winuser.h)](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-translatemessage) |
| In this tree | [`windows/core/ntuser/client/user32.def:130`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/windows/core/ntuser/client/user32.def#L130) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI TranslateMessage(
    CONST MSG *lpMsg
);
```

**Return value.** Type: **BOOL** If the message is translated (that is, a character message is posted to the thread's message queue), the return value is nonzero.

**Tested example** — `example_TranslateMessage` in [`window.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/window.c):

```c
static void example_TranslateMessage(void)
{
    /* TranslateMessage turns WM_KEYDOWN into WM_CHAR; here a custom ping message stands in for input. */
    MSG msg;
    if (register_demo_class() == 0) return;
    HWND hwnd = create_demo_window();
    if (hwnd == NULL) return;
    PostMessageW(hwnd, WM_DEMO_PING, 0, 0);
    if (GetMessageW(&msg, hwnd, 0, 0) > 0) {
        TranslateMessage(&msg);            /* no effect on WM_DEMO_PING, but it belongs in every loop */
        DispatchMessageW(&msg);
    }
    wprintf(L"Pings received: %ld\n", (long)g_pings);
    DestroyWindow(hwnd);
    UnregisterClassW(DEMO_CLASS, GetModuleHandleW(NULL));
}
```

## DispatchMessageW

Dispatches a message to a window procedure. It is typically used to dispatch a message retrieved by the [GetMessage](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getmessage) function.

| Attribute | Value |
| --- | --- |
| Header | `winuser.h` (include `Windows.h`) |
| Library | User32.lib (DLL `User32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps only] |
| Minimum server | Windows 2000 Server [desktop apps only] |
| Character set | DispatchMessageW (Unicode) and DispatchMessageA (ANSI) |
| API set | `ext-ms-win-ntuser-message-l1-1-0 (introduced in Windows 8)` |
| Official reference | [DispatchMessageW function (winuser.h)](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-dispatchmessagew) |
| In this tree | [`windows/core/ntuser/client/user32.def:132`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/windows/core/ntuser/client/user32.def#L132) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
LRESULT WINAPI DispatchMessageW(
    CONST MSG *lpMsg
);
```

**Return value.** Type: **LRESULT** The return value specifies the value returned by the window procedure. Although its meaning depends on the message being dispatched, the return value generally is ignored.

**Tested example** — `example_DispatchMessageW` in [`window.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/window.c):

```c
static void example_DispatchMessageW(void)
{
    /* DispatchMessageW calls the window procedure of msg.hwnd; here that is demo_wnd_proc. */
    MSG msg;
    if (register_demo_class() == 0) return;
    HWND hwnd = create_demo_window();
    if (hwnd == NULL) return;
    PostMessageW(hwnd, WM_DEMO_PING, 0, 0);
    if (GetMessageW(&msg, hwnd, 0, 0) > 0)
        DispatchMessageW(&msg);
    DestroyWindow(hwnd);
    UnregisterClassW(DEMO_CLASS, GetModuleHandleW(NULL));
}
```

## DefWindowProcW

Calls the default window procedure to provide default processing for any window messages that an application does not process. This function ensures that every message is processed. **DefWindowProc** is called with the same parameters received by the window procedure.

| Attribute | Value |
| --- | --- |
| Header | `winuser.h` (include `Windows.h`) |
| Library | User32.lib (DLL `User32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps only] |
| Minimum server | Windows 2000 Server [desktop apps only] |
| Character set | DefWindowProcW (Unicode) and DefWindowProcA (ANSI) |
| API set | `ext-ms-win-ntuser-window-l1-1-0 (introduced in Windows 8)` |
| Official reference | [DefWindowProcW function (winuser.h)](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-defwindowprocw) |
| In this tree | [`windows/core/ntuser/client/cltxt.h:673`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/windows/core/ntuser/client/cltxt.h#L673) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
LRESULT WINAPI DefWindowProcW(
    HWND hWnd,
    UINT Msg,
    WPARAM wParam,
    LPARAM lParam
);
```

**Return value.** Type: **LRESULT** The return value is the result of the message processing and depends on the message.

**Tested example** — `example_DefWindowProcW` in [`window.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/window.c):

```c
static void example_DefWindowProcW(void)
{
    /* Any message the application does not handle goes to DefWindowProcW (for example WM_CLOSE, which destroys the window). */
    if (register_demo_class() == 0) return;
    HWND hwnd = create_demo_window();
    if (hwnd == NULL) return;
    LRESULT r = DefWindowProcW(hwnd, WM_NULL, 0, 0);
    wprintf(L"DefWindowProcW(WM_NULL) returned %ld\n", (long)r);
    DestroyWindow(hwnd);
    UnregisterClassW(DEMO_CLASS, GetModuleHandleW(NULL));
}
```

## PostQuitMessage

Indicates to the system that a thread has made a request to terminate (quit). It is typically used in response to a [WM_DESTROY](https://learn.microsoft.com/en-us/windows/win32/winmsg/wm-destroy) message.

| Attribute | Value |
| --- | --- |
| Header | `winuser.h` (include `Windows.h`) |
| Library | User32.lib (DLL `User32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps only] |
| Minimum server | Windows 2000 Server [desktop apps only] |
| Character set | - |
| API set | `ext-ms-win-ntuser-message-l1-1-0 (introduced in Windows 8)` |
| Official reference | [PostQuitMessage function (winuser.h)](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-postquitmessage) |
| In this tree | [`windows/core/ntuser/client/client.c:3556`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/windows/core/ntuser/client/client.c#L3556) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
VOID WINAPI PostQuitMessage(
    int nExitCode
);
```

**Return value.** See the official reference.

**Tested example** — `example_PostQuitMessage` in [`window.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/window.c):

```c
static void example_PostQuitMessage(void)
{
    MSG msg;
    /* Puts WM_QUIT in the queue of the calling thread; the exit code is returned by the loop's wParam. */
    PostQuitMessage(7);
    if (GetMessageW(&msg, NULL, 0, 0) == 0)
        wprintf(L"WM_QUIT received, exit code %Iu\n", msg.wParam);
}
```

## MessageBoxW

Displays a modal dialog box that contains a system icon, a set of buttons, and a brief application-specific message, such as status or error information. The message box returns an integer value that indicates which button the user clicked.

| Attribute | Value |
| --- | --- |
| Header | `winuser.h` (include `Windows.h`) |
| Library | User32.lib (DLL `User32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps only] |
| Minimum server | Windows 2000 Server [desktop apps only] |
| Character set | MessageBoxW (Unicode) and MessageBoxA (ANSI) |
| API set | `ext-ms-win-ntuser-dialogbox-l1-1-0 (introduced in Windows 8)` |
| Official reference | [MessageBoxW function (winuser.h)](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-messageboxw) |
| In this tree | [`windows/core/ntuser/client/msgbox.c:315`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/windows/core/ntuser/client/msgbox.c#L315) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
int WINAPI MessageBoxW(
    HWND hWnd,
    LPCWSTR lpText,
    LPCWSTR lpCaption,
    UINT uType
);
```

**Return value.** Type: **int** If a message box has a **Cancel** button, the function returns the **IDCANCEL** value if either the ESC key is pressed or the **Cancel** button is selected. If the message box has no **Cancel** button, pressing ESC will no effect - unless an MB_OK button is present. If an MB_OK button is displayed and the user presses ESC, the return value will be **IDOK**.

**Tested example** — `example_MessageBoxW` in [`window.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/window.c):

```c
#ifdef DEMO_INTERACTIVE
static void example_MessageBoxW(void)
{
    /* MessageBoxW is modal and blocks until the user responds. Built with -DDEMO_INTERACTIVE only. */
    int choice = MessageBoxW(NULL, L"Continue with the NEONT 5 example?", L"NEONT 5 docs",
                             MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON1);
    wprintf(L"User chose %ls\n", choice == IDOK ? L"OK" : L"Cancel");
}
#endif
```

## DestroyWindow

Destroys the specified window. The function sends [WM_DESTROY](https://learn.microsoft.com/en-us/windows/win32/winmsg/wm-destroy) and [WM_NCDESTROY](https://learn.microsoft.com/en-us/windows/win32/winmsg/wm-ncdestroy) messages to the window to deactivate it and remove the keyboard focus from it. The function also destroys the window's menu, destroys timers, removes clipboard ownership, and breaks the clipboard viewer chain (if the window is at the top of the viewer chain). If the specified window is a parent or owner window, **DestroyWindow** automatically destroys the associated child or owned windows when it destroys the parent or owner window. The function first destroys child or owned windows, and then it destroys the parent or owner window.

| Attribute | Value |
| --- | --- |
| Header | `winuser.h` (include `Windows.h`) |
| Library | User32.lib (DLL `User32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps only] |
| Minimum server | Windows 2000 Server [desktop apps only] |
| Character set | - |
| API set | `ext-ms-win-ntuser-window-l1-1-0 (introduced in Windows 8)` |
| Official reference | [DestroyWindow function (winuser.h)](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-destroywindow) |
| In this tree | [`windows/core/ntuser/client/user32.def:195`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/windows/core/ntuser/client/user32.def#L195) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI DestroyWindow(
    HWND hWnd
);
```

**Return value.** Type: **BOOL** If the function succeeds, the return value is nonzero.

**Tested example** — `example_DestroyWindow` in [`window.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/window.c):

```c
static void example_DestroyWindow(void)
{
    if (register_demo_class() == 0) return;
    HWND hwnd = create_demo_window();
    /* DestroyWindow sends WM_DESTROY and then WM_NCDESTROY; the handle is invalid afterwards. */
    if (hwnd != NULL && DestroyWindow(hwnd))
        wprintf(L"Window destroyed\n");
    UnregisterClassW(DEMO_CLASS, GetModuleHandleW(NULL));
}
```

## BeginPaint

The **BeginPaint** function prepares the specified window for painting and fills a [PAINTSTRUCT](https://learn.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-paintstruct) structure with information about the painting.

| Attribute | Value |
| --- | --- |
| Header | `winuser.h` (include `Windows.h`) |
| Library | User32.lib (DLL `User32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps only] |
| Minimum server | Windows 2000 Server [desktop apps only] |
| Character set | - |
| API set | `ext-ms-win-ntuser-draw-l1-1-0 (introduced in Windows 8)` |
| Official reference | [BeginPaint function (winuser.h)](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-beginpaint) |
| In this tree | [`windows/core/ntuser/client/user32.def:342`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/windows/core/ntuser/client/user32.def#L342) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
HDC WINAPI BeginPaint(
    HWND hWnd,
    LPPAINTSTRUCT lpPaint
);
```

**Return value.** If the function succeeds, the return value is the handle to a display device context for the specified window. If the function fails, the return value is **NULL**, indicating that no display device context is available.

**Tested example** — `example_BeginPaint` in [`window.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/window.c):

```c
static void example_BeginPaint(void)
{
    /* The painting itself lives in demo_wnd_proc (WM_PAINT). Here UpdateWindow forces one synchronous paint. */
    if (register_demo_class() == 0) return;
    HWND hwnd = create_demo_window();
    if (hwnd == NULL) return;
    ShowWindow(hwnd, SW_SHOWNOACTIVATE);
    UpdateWindow(hwnd);                  /* sends WM_PAINT -> BeginPaint/TextOutW/EndPaint */
    DestroyWindow(hwnd);
    UnregisterClassW(DEMO_CLASS, GetModuleHandleW(NULL));
}
```

## EndPaint

The **EndPaint** function marks the end of painting in the specified window. This function is required for each call to the [BeginPaint](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-beginpaint) function, but only after painting is complete.

| Attribute | Value |
| --- | --- |
| Header | `winuser.h` (include `Windows.h`) |
| Library | User32.lib (DLL `User32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps only] |
| Minimum server | Windows 2000 Server [desktop apps only] |
| Character set | - |
| API set | `ext-ms-win-ntuser-draw-l1-1-0 (introduced in Windows 8)` |
| Official reference | [EndPaint function (winuser.h)](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-endpaint) |
| In this tree | [`windows/core/ntuser/client/user32.def:343`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/windows/core/ntuser/client/user32.def#L343) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI EndPaint(
    HWND hWnd,
    CONST PAINTSTRUCT *lpPaint
);
```

**Return value.** The return value is always nonzero.

**Tested example** — `example_EndPaint` in [`window.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/window.c):

```c
static void example_EndPaint(void)
{
    /* EndPaint releases the device context returned by BeginPaint; see demo_wnd_proc for the paired call. */
    PAINTSTRUCT ps;
    ZeroMemory(&ps, sizeof(ps));
    wprintf(L"PAINTSTRUCT is %u bytes; always pair BeginPaint with EndPaint\n", (unsigned)sizeof(ps));
}
```

## TextOutW

The **TextOut** function writes a character string at the specified location, using the currently selected font, background color, and text color.

| Attribute | Value |
| --- | --- |
| Header | `wingdi.h` (include `Windows.h`) |
| Library | Gdi32.lib (DLL `Gdi32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps only] |
| Minimum server | Windows 2000 Server [desktop apps only] |
| Character set | TextOutW (Unicode) and TextOutA (ANSI) |
| Official reference | [TextOutW function (wingdi.h)](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-textoutw) |
| In this tree | [`windows/core/ntgdi/client/output.c:1925`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/windows/core/ntgdi/client/output.c#L1925) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI TextOutW(
    HDC hdc,
    int x,
    int y,
    LPCWSTR lpString,
    int c
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero.

**Tested example** — `example_TextOutW` in [`window.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/window.c):

```c
static void example_TextOutW(void)
{
    /* TextOutW draws the string at (x, y) in logical coordinates of the device context. */
    HDC screen = GetDC(NULL);
    if (screen == NULL) return;
    /* Drawing on the screen DC here is for illustration; a real program draws in WM_PAINT. */
    BOOL ok = TextOutW(screen, 0, 0, L"NEONT 5", 7);
    wprintf(L"TextOutW returned %ls\n", ok ? L"TRUE" : L"FALSE");
    ReleaseDC(NULL, screen);
}
```

## Build and test

Compile for an x86_64 Windows target with warnings treated as errors (run it on Windows; the examples are compiled here, not executed):

```sh
zig cc -target x86_64-windows-gnu -std=c11 -Wall -Wextra -Werror window.c -o window.exe -lkernel32 -ladvapi32 -lws2_32 -luser32 -lgdi32 -lshell32
```

With MSVC from a Developer Command Prompt: `cl /nologo /W4 /WX window.c`. MSVC is not run in this checkout; the file is verified only with the zig/clang Windows targets.

## Frequently asked questions

### Q: Why does the message loop need TranslateMessage?

`TranslateMessage` turns virtual-key messages into character messages (`WM_CHAR`). Skipping it is legal, but keyboard text input then never arrives.

### Q: What does a 0 return from GetMessageW mean?

The thread received `WM_QUIT`, usually posted by `PostQuitMessage`. `-1` means the call failed; check `GetLastError`.

### Q: Where is the window manager in this tree?

Kernel-mode windowing is `windows/core/ntuser`; the user-mode client is `windows/core/umode`. See [Win32, windowing and the shell](/win32-shell) for the split.

### Q: Why is MessageBoxW not run by default?

It blocks until someone responds. The example is compiled only with `-DDEMO_INTERACTIVE`.
