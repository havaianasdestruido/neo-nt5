---
title: GDI — device contexts, drawing and bitmaps
sidebar_position: 18
description: Device contexts, pens and brushes, bitmaps and DIBs, fonts and text output, palettes and regions — the gdi32 API mapped to windows/core/ntgdi.
---

GDI is the graphics half of Win32. Its client side is `windows/core/ntgdi/client`, built as
`gdi32.dll` (`TARGETNAME=gdi32` in `sources.inc`); its kernel side is `windows/core/ntgdi/gre`
and the rest of `windows/core/ntgdi`, linked into `win32k.sys`.

The model is **handle-based**: you obtain a device context (`HDC`), select objects into it, draw,
then restore and release. Every `HDC` has a current pen, brush, font, bitmap and palette; selecting
a new one returns the previous one so you can restore it.

```text
HDC  --select-->  HPEN / HBRUSH / HFONT / HBITMAP / HPALETTE / HRGN
  |
  +-- drawing: LineTo, Rectangle, Ellipse, Polygon, BitBlt, TextOut
  |
  +-- query:   GetPixel, GetTextExtentPoint32, GetDeviceCaps
```

## Device contexts

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `GetDC` | DC for a window's client area | forwarder to `NtUserGetDC` (`user32.def`) | [GetDC](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getdc) |
| `GetWindowDC` | DC for the whole window including non-client area | `user32.def` forwarder | [GetWindowDC](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getwindowdc) |
| `ReleaseDC` | Release a `GetDC`/`GetWindowDC` DC | `windows/core/ntuser/client/client.c:1072` | [ReleaseDC](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-releasedc) |
| `BeginPaint` | DC plus a `PAINTSTRUCT` during `WM_PAINT` | `user32.def` forwarder | [BeginPaint](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-beginpaint) |
| `EndPaint` | Release the paint DC | `user32.def` forwarder | [EndPaint](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-endpaint) |
| `CreateDCA` / `CreateDCW` | DC for a printer or display device | `windows/core/ntgdi/client/object.c` (`bCreateDCA` at `:743`, `bCreateDCW` at `:637`) | [CreateDCA](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createdca) |
| `CreateCompatibleDC` | Memory DC compatible with a given DC | `windows/core/ntgdi/client/object.c:1128` | [CreateCompatibleDC](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createcompatibledc) |
| `CreateICW` | Information context (query, no drawing) | `object.c` | [CreateICW](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createicw) |
| `DeleteDC` | Destroy a created DC | `windows/core/ntgdi/client/object.c:1171` | [DeleteDC](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-deletedc) |
| `SaveDC` / `RestoreDC` | Push/pop DC state | `object.c:1372`, `:1436` | [SaveDC](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-savedc) |

Rules:

- `GetDC`/`GetWindowDC` return a **shared** DC: you must `ReleaseDC` it, and you must not delete it.
- `CreateDC`/`CreateCompatibleDC` return an **owned** DC: you must `DeleteDC` it.
- `BeginPaint`/`EndPaint` are only valid during `WM_PAINT`, and they validate the update region.
- Selecting a bitmap into a DC and then deleting the bitmap is invalid; restore the old bitmap first.

## Drawing primitives

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `Rectangle` | Filled rectangle with the current pen/brush | `windows/core/ntgdi/client/output.c:414` | [Rectangle](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-rectangle) |
| `Ellipse` | Filled ellipse | `output.c:312` | [Ellipse](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-ellipse) |
| `Polygon` | Filled polygon | `windows/core/ntgdi/client/poly.c:112` | [Polygon](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-polygon) |
| `Polyline` | Unfilled polyline | `poly.c` | [Polyline](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-polyline) |
| `MoveToEx` / `LineTo` | Move the current position / draw a line | `output.c` | [LineTo](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-lineto) |
| `SetPixel` / `GetPixel` | Single pixel | `output.c:2626`, `dcquery.c:276` | [SetPixel](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-setpixel) |
| `BitBlt` | Block copy | `output.c:729` | [BitBlt](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-bitblt) |
| `StretchBlt` | Scaled block copy | `output.c:836` | [StretchBlt](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-stretchblt) |
| `PatBlt` | Pattern block copy | `output.c` | [PatBlt](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-patblt) |
| `FillRect` | Fill with a brush | `user32` | [FillRect](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-fillrect) |
| `InvalidateRect` | Add a rectangle to the update region | `user32` | [InvalidateRect](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-invalidaterect) |

### `BitBlt` raster operations

The `dwRop` parameter selects a ternary raster operation. The common ones:

| Code | Meaning |
| --- | --- |
| `SRCCOPY` | Copy source to destination |
| `SRCPAINT` | OR source and destination |
| `SRCAND` | AND source and destination |
| `SRCINVERT` | XOR source and destination |
| `SRCCOPY \| CAPTUREBLT` | Copy including layered windows |
| `BLACKNESS` / `WHITENESS` | Fill |

`BitBlt` is the fastest way to move pixels between compatible DCs. For per-pixel work, use a DIB
section and write to its bits directly; `SetPixel` in a loop is orders of magnitude slower.

## Objects: pens, brushes, fonts

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `CreatePen` | Logical pen | `windows/core/ntgdi/client/object.c:2123` | [CreatePen](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createpen) |
| `CreatePenIndirect` | Pen from a `LOGPEN` | `object.c` | [CreatePenIndirect](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createpenindirect) |
| `CreateSolidBrush` | Solid colour brush | `object.c:1972` | [CreateSolidBrush](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createsolidbrush) |
| `CreateBrushIndirect` | Brush from a `LOGBRUSH` | `object.c:1987` | [CreateBrushIndirect](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createbrushindirect) |
| `CreatePatternBrush` | Brush from a bitmap | `object.c` | [CreatePatternBrush](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createpatternbrush) |
| `CreateHatchBrush` | Hatched brush | `object.c` | [CreateHatchBrush](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createhatchbrush) |
| `SelectObject` | Select an object into a DC | `object.c:2998` | [SelectObject](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-selectobject) |
| `DeleteObject` | Destroy a GDI object | `object.c:2836` | [DeleteObject](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-deleteobject) |
| `GetObjectW` | Query an object's logical attributes | `object.c` | [GetObjectW](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-getobjectw) |
| `GetStockObject` | Built-in pen/brush/font | `object.c:3280` | [GetStockObject](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-getstockobject) |

Stock objects (`WHITE_BRUSH`, `LTGRAY_BRUSH`, `NULL_PEN`, `SYSTEM_FONT`, `DEFAULT_GUI_FONT`, ...)
are **not** owned by the caller: never `DeleteObject` them.

### The select/restore idiom

```c
HPEN oldPen = (HPEN)SelectObject(hdc, CreatePen(PS_SOLID, 2, RGB(255, 0, 0)));
// ... draw ...
HPEN created = (HPEN)SelectObject(hdc, oldPen);   // restore, and get the created pen back
DeleteObject(created);
```

The double-select idiom is the only reliable way to delete an object after restoring the DC: the
first `SelectObject` returns the previous object, the second returns the one you created.

## Bitmaps and DIBs

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `CreateBitmap` | Device-dependent bitmap | `windows/core/ntgdi/client/bitmap.c:2530` | [CreateBitmap](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createbitmap) |
| `CreateCompatibleBitmap` | Bitmap compatible with a DC | `bitmap.c` | [CreateCompatibleBitmap](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createcompatiblebitmap) |
| `CreateDIBSection` | DIB with direct access to its bits | `bitmap.c` | [CreateDIBSection](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createdibsection) |
| `CreateDIBitmap` | DIB from a `BITMAPINFOHEADER` and bits | `bitmap.c` | [CreateDIBitmap](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createdibitmap) |
| `GetDIBits` | Copy bitmap bits into a DIB | `bitmap.c:1155` | [GetDIBits](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-getdibits) |
| `SetDIBits` | Set bitmap bits from a DIB | `bitmap.c:1656` | [SetDIBits](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-setdibits) |
| `SetDIBitsToDevice` | Draw DIB bits directly to a DC | `bitmap.c:608` | [SetDIBitsToDevice](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-setdibitstodevice) |
| `StretchDIBits` | Scaled DIB draw | `bitmap.c` | [StretchDIBits](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-stretchdibits) |

### A 32-bit DIB section

```c
#include <windows.h>

HBITMAP MakeDibSection(HDC hdc, int width, int height, void **bits)
{
    BITMAPINFO bi = {0};
    bi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
    bi.bmiHeader.biWidth       = width;
    bi.bmiHeader.biHeight      = -height;      // top-down
    bi.bmiHeader.biPlanes      = 1;
    bi.bmiHeader.biBitCount    = 32;
    bi.bmiHeader.biCompression = BI_RGB;

    return CreateDIBSection(hdc, &bi, DIB_RGB_COLORS, bits, NULL, 0);
}

// Draw a 256x256 gradient into a memory DC and blit it to the screen.
void DrawGradient(HWND hwnd, HDC hdcDest)
{
    HDC hdcMem = CreateCompatibleDC(hdcDest);
    void *bits = NULL;
    HBITMAP hbm = MakeDibSection(hdcDest, 256, 256, &bits);
    if (!hbm || !bits) { DeleteDC(hdcMem); return; }

    HBITMAP old = (HBITMAP)SelectObject(hdcMem, hbm);

    DWORD *p = (DWORD *)bits;
    for (int y = 0; y < 256; y++) {
        for (int x = 0; x < 256; x++) {
            p[y * 256 + x] = RGB(x, y, 0x80);   // 0x00BBGGRR
        }
    }

    BitBlt(hdcDest, 0, 0, 256, 256, hdcMem, 0, 0, SRCCOPY);

    SelectObject(hdcMem, old);
    DeleteObject(hbm);
    DeleteDC(hdcMem);
}
```

Notes:

- A negative `biHeight` makes the DIB top-down, which matches how people write image loops.
- `CreateDIBSection` gives you a pointer to the bits, so you can write pixels without `SetPixel`.
- The DIB is selected into a memory DC; you cannot select a bitmap into the screen DC directly.
- `RGB(r, g, b)` produces `0x00BBGGRR`, not `0x00RRGGBB`.

## Text and fonts

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `CreateFontW` | Font from a description | `object.c` | [CreateFontW](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createfontw) |
| `CreateFontIndirectW` | Font from a `LOGFONTW` | `object.c:2688` | [CreateFontIndirectW](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createfontindirectw) |
| `TextOutW` | Draw a string | `output.c:1925` | [TextOutW](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-textoutw) |
| `ExtTextOutW` | Draw with spacing, clipping and opaque rectangle | `output.c:1337` | [ExtTextOutW](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-exttextoutw) |
| `GetTextExtentPoint32W` | Measure a string | `dcquery.c:1958` | [GetTextExtentPoint32W](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-gettextextentpoint32w) |
| `SetTextColor` / `SetBkColor` | Foreground/background colour | `windows/core/ntgdi/client/ldc.c:439`, `:515` | [SetTextColor](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-settextcolor) |
| `SetBkMode` | `TRANSPARENT` or `OPAQUE` | `ldc.c` | [SetBkMode](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-setbkmode) |
| `GetTextMetricsW` | Font metrics | `dcquery.c` | [GetTextMetricsW](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-gettextmetricsw) |

```c
LOGFONTW lf = {0};
lf.lfHeight         = -MulDiv(12, GetDeviceCaps(hdc, LOGPIXELSY), 72);  // 12 pt
lf.lfWeight         = FW_NORMAL;
lf.lfCharSet        = DEFAULT_CHARSET;
lf.lfQuality        = CLEARTYPE_QUALITY;
wcscpy(lf.lfFaceName, L"Segoe UI");

HFONT hFont = CreateFontIndirectW(&lf);
HFONT old   = (HFONT)SelectObject(hdc, hFont);

SetTextColor(hdc, RGB(0, 0, 0));
SetBkMode(hdc, TRANSPARENT);
TextOutW(hdc, 10, 10, L"Hello, GDI", 10);

SelectObject(hdc, old);
DeleteObject(hFont);
```

`lfHeight` is negative for "character height" and positive for "cell height"; the `MulDiv`
conversion is the standard way to turn points into device units at the current DPI.

## Palettes and colour

| Function | Purpose | Documentation |
| --- | --- | --- |
| `CreatePalette` | Logical palette from `LOGPALETTE` | [CreatePalette](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createpalette) |
| `SelectPalette` / `RealizePalette` | Install and map a palette | [RealizePalette](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-realizepalette) |
| `GetSystemPaletteEntries` | Query the system palette | [GetSystemPaletteEntries](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-getsystempaletteentries) |
| `GetNearestColor` | Closest realisable colour | [GetNearestColor](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-getnearestcolor) |

Palettes matter on 8-bpp devices and on remote desktops with reduced colour depth. On a
32-bpp display, `SetTextColor`/`SetBkColor` are effectively direct.

## Regions and paths

| Function | Purpose | Documentation |
| --- | --- | --- |
| `CreateRectRgn` / `CreateEllipticRgn` / `CreatePolygonRgn` | Create a region | [CreateRectRgn](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createrectrgn) |
| `SelectClipRgn` | Intersect with the DC clip region | [SelectClipRgn](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-selectcliprgn) |
| `BeginPath` / `EndPath` / `StrokeAndFillPath` | Vector paths | [BeginPath](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-beginpath) |
| `SetWindowRgn` | Window-shaped region | [SetWindowRgn](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setwindowrgn) |

## A complete paint handler

```c
case WM_PAINT: {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);

    // Background
    RECT rc;
    GetClientRect(hwnd, &rc);
    FillRect(hdc, &rc, (HBRUSH)(COLOR_WINDOW + 1));

    // Border
    HPEN pen = CreatePen(PS_SOLID, 2, RGB(0x70, 0x70, 0x70));
    HPEN oldPen = (HPEN)SelectObject(hdc, pen);
    HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));
    Rectangle(hdc, 10, 10, rc.right - 10, rc.bottom - 10);

    // Text
    SetBkMode(hdc, TRANSPARENT);
    SetTextColor(hdc, RGB(0, 0, 0));
    TextOutW(hdc, 20, 20, L"Painted with GDI", 16);

    SelectObject(hdc, oldBrush);
    HPEN created = (HPEN)SelectObject(hdc, oldPen);
    DeleteObject(created);
    DeleteObject(pen);

    EndPaint(hwnd, &ps);
    return 0;
}
```

## Function reference table

| Function | Header | Implementation | Documentation |
| --- | --- | --- | --- |
| `GetDC` | `winuser.h` | forwarder to `NtUserGetDC` | [GetDC](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getdc) |
| `ReleaseDC` | `winuser.h` | `windows/core/ntuser/client/client.c:1072` | [ReleaseDC](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-releasedc) |
| `CreateDCA` | `wingdi.h` | `windows/core/ntgdi/client/object.c:743` | [CreateDCA](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createdca) |
| `CreateCompatibleDC` | `wingdi.h` | `windows/core/ntgdi/client/object.c:1128` | [CreateCompatibleDC](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createcompatibledc) |
| `DeleteDC` | `wingdi.h` | `windows/core/ntgdi/client/object.c:1171` | [DeleteDC](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-deletedc) |
| `SaveDC` | `wingdi.h` | `windows/core/ntgdi/client/object.c:1372` | [SaveDC](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-savedc) |
| `RestoreDC` | `wingdi.h` | `windows/core/ntgdi/client/object.c:1436` | [RestoreDC](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-restoredc) |
| `Rectangle` | `wingdi.h` | `windows/core/ntgdi/client/output.c:414` | [Rectangle](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-rectangle) |
| `Ellipse` | `wingdi.h` | `windows/core/ntgdi/client/output.c:312` | [Ellipse](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-ellipse) |
| `Polygon` | `wingdi.h` | `windows/core/ntgdi/client/poly.c:112` | [Polygon](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-polygon) |
| `BitBlt` | `wingdi.h` | `windows/core/ntgdi/client/output.c:729` | [BitBlt](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-bitblt) |
| `StretchBlt` | `wingdi.h` | `windows/core/ntgdi/client/output.c:836` | [StretchBlt](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-stretchblt) |
| `SetPixel` | `wingdi.h` | `windows/core/ntgdi/client/output.c:2626` | [SetPixel](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-setpixel) |
| `GetPixel` | `wingdi.h` | `windows/core/ntgdi/client/dcquery.c:276` | [GetPixel](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-getpixel) |
| `CreatePen` | `wingdi.h` | `windows/core/ntgdi/client/object.c:2123` | [CreatePen](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createpen) |
| `CreateSolidBrush` | `wingdi.h` | `windows/core/ntgdi/client/object.c:1972` | [CreateSolidBrush](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createsolidbrush) |
| `CreateBrushIndirect` | `wingdi.h` | `windows/core/ntgdi/client/object.c:1987` | [CreateBrushIndirect](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createbrushindirect) |
| `SelectObject` | `wingdi.h` | `windows/core/ntgdi/client/object.c:2998` | [SelectObject](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-selectobject) |
| `DeleteObject` | `wingdi.h` | `windows/core/ntgdi/client/object.c:2836` | [DeleteObject](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-deleteobject) |
| `GetStockObject` | `wingdi.h` | `windows/core/ntgdi/client/object.c:3280` | [GetStockObject](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-getstockobject) |
| `CreateBitmap` | `wingdi.h` | `windows/core/ntgdi/client/bitmap.c:2530` | [CreateBitmap](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createbitmap) |
| `GetDIBits` | `wingdi.h` | `windows/core/ntgdi/client/bitmap.c:1155` | [GetDIBits](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-getdibits) |
| `SetDIBits` | `wingdi.h` | `windows/core/ntgdi/client/bitmap.c:1656` | [SetDIBits](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-setdibits) |
| `SetDIBitsToDevice` | `wingdi.h` | `windows/core/ntgdi/client/bitmap.c:608` | [SetDIBitsToDevice](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-setdibitstodevice) |
| `CreateFontIndirectW` | `wingdi.h` | `windows/core/ntgdi/client/object.c:2688` | [CreateFontIndirectW](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createfontindirectw) |
| `TextOutW` | `wingdi.h` | `windows/core/ntgdi/client/output.c:1925` | [TextOutW](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-textoutw) |
| `ExtTextOutW` | `wingdi.h` | `windows/core/ntgdi/client/output.c:1337` | [ExtTextOutW](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-exttextoutw) |
| `GetTextExtentPoint32W` | `wingdi.h` | `windows/core/ntgdi/client/dcquery.c:1958` | [GetTextExtentPoint32W](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-gettextextentpoint32w) |
| `SetTextColor` | `wingdi.h` | `windows/core/ntgdi/client/ldc.c:439` | [SetTextColor](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-settextcolor) |
| `SetBkColor` | `wingdi.h` | `windows/core/ntgdi/client/ldc.c:515` | [SetBkColor](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-setbkcolor) |

## Frequently asked questions

### Q: Why does `GetDC` appear in `user32.def` as `GetDC = NtUserGetDC`?

Because `GetDC` is a forwarder to the USER syscall, even though the function is documented under
`winuser.h` and feels like GDI. GDI's own DC creation (`CreateDCA`, `CreateCompatibleDC`) lives in
`gdi32.dll`. The split is historical: window DCs are managed by USER, drawing DCs by GDI.

### Q: Why do I have to call `ReleaseDC` on a `GetDC` handle but `DeleteDC` on a created one?

Because they are different kinds of DC. `GetDC` returns a DC from a per-thread cache that USER
owns; `ReleaseDC` returns it. `CreateDC`/`CreateCompatibleDC` allocate a new DC that you own;
`DeleteDC` destroys it. Calling `DeleteDC` on a `GetDC` handle corrupts the cache, and calling
`ReleaseDC` on a created DC leaks it.

### Q: Why is `SetPixel` slow?

Because each call is a syscall into the graphics engine. For per-pixel work, create a DIB section
with `CreateDIBSection`, write the bits directly, then `BitBlt` the result. That turns thousands of
syscalls into one.

### Q: What is the difference between a bitmap and a DIB?

A bitmap (`HBITMAP` from `CreateBitmap`) is device-dependent and its bits are opaque to you. A DIB
(`CreateDIBSection`, `CreateDIBitmap`) has a documented header and bits you can read and write.
Use a DIB when you need to manipulate pixels or save them to a file.

### Q: Why is `RGB(255, 0, 0)` red but stored as `0x000000FF`?

Because `COLORREF` is `0x00BBGGRR`. `RGB(r, g, b)` does the shift for you. When writing a 32-bit
DIB directly, the memory layout is `B, G, R, X` on little-endian x86, so a `DWORD` write is
`0x00RRGGBB` as a number — the reverse of `COLORREF`.

### Q: How do I draw text with a transparent background?

`SetBkMode(hdc, TRANSPARENT)` before `TextOutW`. With `OPAQUE` (the default), the background is
filled with the current background colour, which is why text appears in a coloured box.

### Q: Where is the kernel-side GDI?

`windows/core/ntgdi/gre` is the graphics engine; `fonts/`, `halftone/`, `icm/`, `image/`,
`mf3216/` and `mstypeo/` are the sub-engines. The syscall stubs are generated from the same
`services.tab` pattern as USER (`base/ntos/ke/services.tab`), and `gdi32.def` lists the client
exports.

### Q: Can I use GDI from a service with no desktop?

Only with a printer or memory DC. `GetDC(NULL)` returns the screen DC, which fails if the session
has no desktop (session 0 isolation). `CreateDCA(L"DISPLAY", ...)` has the same restriction. Use a
memory DC (`CreateCompatibleDC(NULL)`) for off-screen work.

### Q: How do I know whether a GDI object was selected into a DC?

`GetObjectW` gives the logical attributes, but not the selection state. Track it yourself: the
`SelectObject` return value is the only reliable record. Deleting a selected object fails silently
in release builds and asserts in checked builds.
