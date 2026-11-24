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

/* @fn RegisterClassExW */
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

/* @fn CreateWindowExW */
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

/* @fn ShowWindow */
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

/* @fn GetMessageW */
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

/* @fn TranslateMessage */
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

/* @fn DispatchMessageW */
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

/* @fn DefWindowProcW */
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

/* @fn PostQuitMessage */
static void example_PostQuitMessage(void)
{
    MSG msg;
    /* Puts WM_QUIT in the queue of the calling thread; the exit code is returned by the loop's wParam. */
    PostQuitMessage(7);
    if (GetMessageW(&msg, NULL, 0, 0) == 0)
        wprintf(L"WM_QUIT received, exit code %Iu\n", msg.wParam);
}

/* @fn MessageBoxW */
#ifdef DEMO_INTERACTIVE
static void example_MessageBoxW(void)
{
    /* MessageBoxW is modal and blocks until the user responds. Built with -DDEMO_INTERACTIVE only. */
    int choice = MessageBoxW(NULL, L"Continue with the NEONT 5 example?", L"NEONT 5 docs",
                             MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON1);
    wprintf(L"User chose %ls\n", choice == IDOK ? L"OK" : L"Cancel");
}
#endif

/* @fn DestroyWindow */
static void example_DestroyWindow(void)
{
    if (register_demo_class() == 0) return;
    HWND hwnd = create_demo_window();
    /* DestroyWindow sends WM_DESTROY and then WM_NCDESTROY; the handle is invalid afterwards. */
    if (hwnd != NULL && DestroyWindow(hwnd))
        wprintf(L"Window destroyed\n");
    UnregisterClassW(DEMO_CLASS, GetModuleHandleW(NULL));
}

/* @fn BeginPaint */
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

/* @fn EndPaint */
static void example_EndPaint(void)
{
    /* EndPaint releases the device context returned by BeginPaint; see demo_wnd_proc for the paired call. */
    PAINTSTRUCT ps;
    ZeroMemory(&ps, sizeof(ps));
    wprintf(L"PAINTSTRUCT is %u bytes; always pair BeginPaint with EndPaint\n", (unsigned)sizeof(ps));
}

/* @fn TextOutW */
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

int main(void)
{
    example_RegisterClassExW();
    example_CreateWindowExW();
    example_ShowWindow();
    example_GetMessageW();
    example_TranslateMessage();
    example_DispatchMessageW();
    example_DefWindowProcW();
    example_PostQuitMessage();
#ifdef DEMO_INTERACTIVE
    example_MessageBoxW();
#endif
    example_DestroyWindow();
    example_BeginPaint();
    example_EndPaint();
    example_TextOutW();
    return 0;
}
