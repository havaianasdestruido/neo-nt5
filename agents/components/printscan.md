# `printscan/` — printing, imaging, fax and scanning

This project contains print drivers and spooler, scan/WIA, fax client/server and related UI/tools. It crosses user/kernel and local/network boundaries; printer UI is not the spooler, and a spooler fix is not a driver fix. [`printscan/dirs`](../../printscan/dirs) is the build traversal; [every nested folder](../catalog/printscan.md) is cataloged.

| Path (relative to `printscan/`) | Responsibility |
| --- | --- |
| [`print`](../../printscan/print) | Printer drivers and the spooler/service stack; see below. |
| [`scan`](../../printscan/scan) | Scanning support and device-facing functionality. |
| [`wia`](../../printscan/wia) | Windows Image Acquisition core, drivers, kernel parts, setup and tests. |
| [`fax`](../../printscan/fax) · [`faxsrv`](../../printscan/faxsrv) | Fax clients/components and fax service implementation. |
| [`ui`](../../printscan/ui) | User-interface integration for print/scan devices and settings. |
| [`lib`](../../printscan/lib) · [`inc`](../../printscan/inc) | Shared print/scan libraries and headers. |
| [`dload`](../../printscan/dload) | Delay-load/build integration. |
| [`publish`](../../printscan/publish) · [`ddk`](../../printscan/ddk) | Interface publishing and driver-development material. Note the singular `publish/` here. |

## Inside `print/`

* [`print/drivers/kernelmode`](../../printscan/print/drivers/kernelmode) and [`usermode`](../../printscan/print/drivers/usermode) contain rendering/printer drivers, samples and parsers. Coordinate their data format with the spooler, not with the disk-driver stack in `drivers/storage`.
* [`print/spooler/spoolss`](../../printscan/print/spooler/spoolss) implements the spooler API/server and client/IDL surfaces. [`localspl`](../../printscan/print/spooler/localspl) handles local spooling; [`monitors`](../../printscan/print/spooler/monitors) and [`prtprocs`](../../printscan/print/spooler/prtprocs) handle output transports and print processing; `inetpp2`/`inetsrv` add Internet-facing pieces. [`print/spooler/idl`](../../printscan/print/spooler/idl) and [`inc`](../../printscan/print/spooler/inc) define contracts.
* [`print/embedded`](../../printscan/print/embedded) contains component descriptions, scripts and tests for embedded configurations; it is not the main Win32 spooler.

## Change impact

Trace caller → spooler service/IDL → processor/monitor → driver → device/network transport, and check authorization, driver install/INF, architecture, resource/locale and service start behavior. The [print flow](../system-flows.md#6-a-web-request-or-print-job) and [interface checklist](../interfaces.md#review-checklist-for-interface-changes) show adjacent areas.
