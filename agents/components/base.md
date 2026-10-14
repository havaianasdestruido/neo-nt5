# `base/` — boot, executive, native and foundational services

`base/` holds much of the OS foundation: boot/HAL/kernel, native and Win32 base APIs, filesystems, PnP, session startup, setup and foundational services. It is **not** the whole kernel or all Windows APIs; graphics and UI kernel code also lives in [`windows/`](windows.md), other drivers in [`drivers/`](drivers.md), and security services in [`ds/`](ds.md). Build order is specified by [`base/dirs`](../../base/dirs). [Every nested base directory and build definition](../catalog/base.md) is indexed separately.

## Immediate subtrees

| Path (relative to `base/`) | Responsibility / where to look |
| --- | --- |
| [`boot`](../../base/boot) | Boot sectors, loader, detection, boot video/fonts, EFI/network/setup variants. |
| [`hals`](../../base/hals) | Platform/processor-specific HALs and interrupt/platform support. |
| [`ntos`](../../base/ntos) | Kernel/executive managers; see [detail](#kernel-and-boot-detail). |
| [`ntdll`](../../base/ntdll) · [`ntdllsym`](../../base/ntdllsym) | Native user-mode API/runtime and symbol-related build support. |
| [`subsys`](../../base/subsys) | Session Manager (`sm`), CSRSS (`csr`), and historical POSIX subsystem. |
| [`win32`](../../base/win32) | Win32 base client/server, NLS and side-by-side (`fusion`) functionality. |
| [`wow64`](../../base/wow64) · [`mvdm`](../../base/mvdm) | 32-on-64 compatibility and historical DOS/virtual-machine support; not universal build targets. |
| [`fs`](../../base/fs) · [`fsrec`](../../base/fsrec) | Filesystems/redirectors and filesystem recognizers. |
| [`pnp`](../../base/pnp) · [`busdrv`](../../base/busdrv) · [`basedrv`](../../base/basedrv) | PnP/setup API and bus/foundation drivers. |
| [`wdmdrv`](../../base/wdmdrv) · [`wdmlib`](../../base/wdmlib) | WDM driver helpers and libraries. |
| [`cluster`](../../base/cluster) | Cluster service, management, storage/network resources and setup. |
| [`screg`](../../base/screg) · [`eventlog`](../../base/eventlog) | Service control/registry-facing code and Event Log client/server. |
| [`ntsetup`](../../base/ntsetup) · [`remoteboot`](../../base/remoteboot) | OS setup, hives/INFs/migration and remote-boot provisioning. |
| [`headless`](../../base/headless) · [`firmware`](../../base/firmware) · [`efiutil`](../../base/efiutil) · [`xip`](../../base/xip) | Headless/EMS, firmware/EFI utilities, and execute-in-place support. |
| [`wmi`](../../base/wmi) | Base WMI plumbing and supporting libraries; WMI service/providers also live in `admin/`. |
| [`crts`](../../base/crts) · [`urtl`](../../base/urtl) · [`strsafe`](../../base/strsafe) · [`zlib`](../../base/zlib) | C runtime, runtime/string and compression support. |
| [`dload`](../../base/dload) · [`dloadhandler`](../../base/dloadhandler) · [`stublibs`](../../base/stublibs) | Delay-loading and stub/helper libraries. |
| [`seaudit`](../../base/seaudit) · [`qfe`](../../base/qfe) · [`mspatch`](../../base/mspatch) | Security audit helpers, hotfix-related resources and patch support. Root `QFE/` is **absent** even though root `dirs` names it. |
| [`cmd`](../../base/cmd) · [`tools`](../../base/tools) · [`testlockout`](../../base/testlockout) | Command interpreters/utilities, debugging tools and lockout test material. |
| [`inc`](../../base/inc) · [`ddk`](../../base/ddk) · [`published`](../../base/published) | Internal headers, DDK material and publication support. Do not assume a published file is its source owner. |

## Kernel and boot detail

[`base/boot/dirs`](../../base/boot/dirs) traverses [`bootcode`](../../base/boot/bootcode), [`bootfont`](../../base/boot/bootfont), [`bootvid`](../../base/boot/bootvid), [`kdcom`](../../base/boot/kdcom), [`kd1394`](../../base/boot/kd1394), [`tftplib`](../../base/boot/tftplib), [`lib`](../../base/boot/lib), [`bd`](../../base/boot/bd), [`efi`](../../base/boot/efi), [`bootssp`](../../base/boot/bootssp), [`bldr`](../../base/boot/bldr), [`setup`](../../base/boot/setup), [`detect`](../../base/boot/detect), [`startup`](../../base/boot/startup), [`startrom`](../../base/boot/startrom) and [`oschoice`](../../base/boot/oschoice), with architecture qualifiers. Read boot format/loader paths together with architecture-specific kernel/HAL selection; not all branches apply to each boot medium.

[`base/ntos/dirs`](../../base/ntos/dirs) names these kernel areas (additional `inc` is a header tree):

| Area | Main concern | Area | Main concern |
| --- | --- | --- | --- |
| [`init`](../../base/ntos/init) | Kernel entry/initialization and build variants | [`ke`](../../base/ntos/ke) | Scheduler, exceptions and low-level kernel |
| [`ps`](../../base/ntos/ps) | Processes/threads | [`mm`](../../base/ntos/mm) | Virtual memory |
| [`ob`](../../base/ntos/ob) | Object namespace/handles | [`se`](../../base/ntos/se) | Security reference monitor |
| [`io`](../../base/ntos/io) | I/O manager and kernel PnP | [`po`](../../base/ntos/po) | Power management |
| [`config`](../../base/ntos/config) | Registry/configuration manager | [`cache`](../../base/ntos/cache) | Cache manager |
| [`lpc`](../../base/ntos/lpc) | Local procedure calls | [`ex`](../../base/ntos/ex) | Executive primitives |
| [`arb`](../../base/ntos/arb) | Resource arbitration | [`dbgk`](../../base/ntos/dbgk) | Kernel debugger/process hooks |
| [`kd64`](../../base/ntos/kd64) | Kernel debugging transport/core | [`verifier`](../../base/ntos/verifier) | Driver verifier |
| [`fsrtl`](../../base/ntos/fsrtl) | Filesystem runtime helpers | [`fstub`](../../base/ntos/fstub) | Filesystem stubs |
| [`raw`](../../base/ntos/raw) | Raw volume filesystem | [`rtl`](../../base/ntos/rtl) | Runtime support |
| [`nls`](../../base/ntos/nls) | Kernel NLS data/support | [`vdm`](../../base/ntos/vdm) | Virtual DOS machine hooks |
| [`wmi`](../../base/ntos/wmi) | Kernel instrumentation | [`perf`](../../base/ntos/perf) | Performance support |
| [`ntsym`](../../base/ntos/ntsym) | Kernel symbol build/exports | [`inc`](../../base/ntos/inc) | Private kernel headers |

Source fragments in `up`, `mp`, `pae`, `i386`, `amd64`, `ia64`, and language folders are variants. A `sources` in one of these may omit `TARGETNAME` and feed a parent target; the [catalog](../catalog/base.md) shows declarations, not final kernel linkage.

## Other boundaries worth tracing

* **Process/UI:** [`base/subsys/sm/server`](../../base/subsys/sm/server) builds SMSS; [`base/subsys/csr/csrss`](../../base/subsys/csr/csrss) builds CSRSS. [`base/win32/client`](../../base/win32/client), [`windows/core`](windows.md), [`ds/security/gina`](../../ds/security/gina) and [`shell/explorer`](../../shell/explorer) implement the rest of an interactive session. See [boot/Win32 flows](../system-flows.md).
* **File and device:** [`base/fs/ntfs`](../../base/fs/ntfs), `fastfat`, `cdfs`, `udfs`, `efs`, `npfs`, `mup`, `rdr2`, `srv` and `dfs` play different local/remote roles. Their I/O contract reaches `ntos/io`, [`drivers/storage`](../../drivers/storage), and PnP. `base/pnp/setupapi` handles user-mode installation, not the kernel PnP manager itself.
* **Setup and delivery:** [`base/ntsetup/inf`](../../base/ntsetup/inf), [`hives`](../../base/ntsetup/hives), [`migdlls`](../../base/ntsetup/migdlls) and other setup folders determine what is installed. Check [postbuild](../build-and-release.md) and per-component setup before claiming a compiled binary ships.
