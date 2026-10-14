# `windows/` — Win32 windowing, graphics and compatibility

This project contains Win32 client/kernel GUI plumbing, GDI/USER, console support, text/input and application compatibility. It is **not** a synonym for the entire OS; native executive code is in [`base/ntos`](../../base/ntos) and desktop applications in [`shell/`](shell.md). [`windows/dirs`](../../windows/dirs) gives its build traversal; the [catalog](../catalog/windows.md) covers all nested folders.

| Path (relative to `windows/`) | Responsibility |
| --- | --- |
| [`core`](../../windows/core) | Win32 kernel/user-side windowing and graphics, console, runtime and session server; see below. |
| [`advcore`](../../windows/advcore) | Text Services Framework (`ctf`), DirectUI/DUser, GDI+ and associated controls/resources. |
| [`appcompat`](../../windows/appcompat) | Application compatibility database, shims, apphelp, verifier/UI and servicing tools. |
| [`feime`](../../windows/feime) | Far East input method/language-specific input support. |
| [`netdde`](../../windows/netdde) | Network Dynamic Data Exchange components. |
| [`oleacc`](../../windows/oleacc) | Accessibility / OLE accessibility implementation and resources. |
| [`richedit`](../../windows/richedit) | RichEdit versions, text services and language support. |
| [`winstate`](../../windows/winstate) | User state/migration tools and components (including `scanstate`/`loadstate` trees). |
| [`ddk`](../../windows/ddk) · [`published`](../../windows/published) | Driver-facing/publication material. |
| [`dload`](../../windows/dload) | Delay-load integration/support. |

## Inside `core/`

| Subtree | Responsibility / neighbor |
| --- | --- |
| [`kmode`](../../windows/core/kmode) · [`umode`](../../windows/core/umode) | Kernel/user Win32 build variants. Inspect their `dirs`/`sources` and architecture subfolders for the selected target. |
| [`ntuser`](../../windows/core/ntuser) | Window manager, input and USER API paths (client, server, kernel, keyboard/IME). |
| [`ntgdi`](../../windows/core/ntgdi) | GDI rendering, fonts, graphics drivers and image/color support. |
| [`dxkernel`](../../windows/core/dxkernel) | DirectX-related kernel interfaces and driver glue; coordinate with [`multimedia/directx`](../../multimedia/directx). |
| [`ntcon`](../../windows/core/ntcon) | Console client/server and IME-related console support. |
| [`winsrv`](../../windows/core/winsrv) · [`termspl`](../../windows/core/termspl) | Win32 session/server components; trace with CSRSS and terminal sessions. |
| [`rtl`](../../windows/core/rtl) · [`w32inc`](../../windows/core/w32inc) | Shared client/kernel runtime and Win32 internal headers. |
| [`cslpk`](../../windows/core/cslpk) | Language-pack/character support. |
| [`wow6432`](../../windows/core/wow6432) · [`wow64win`](../../windows/core/wow64win) | 32-bit compatibility / Win32 translations on 64-bit systems. |
| [`syminfo`](../../windows/core/syminfo) | Symbol/build support. |

## Before changing an API or visual behavior

Follow [`public/sdk/inc`](../../public/sdk/inc) → [`base/win32`](../../base/win32) or `windows/core` client → Win32 server or kernel side → input/video drivers → [`shell`](shell.md) and [`termsrv`](termsrv.md) where applicable. Preserve user/kernel and 32/64-bit layout, access checks, resource/locale variants and compatibility database effects. See [the Win32 flow](../system-flows.md#2-a-win32ui-operation) and [interfaces](../interfaces.md).
