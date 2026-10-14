# `drivers/` — device and class drivers

`drivers/` holds many hardware, class, filter and WDM components. Kernel driver infrastructure also lives in [`base/ntos/io`](../../base/ntos/io), installation in [`base/pnp`](../../base/pnp), and network protocol code in [`net/`](net.md). Follow [`drivers/dirs`](../../drivers/dirs) for build order/architecture qualifiers; see [every nested driver folder and target](../catalog/drivers.md).

| Path (relative to `drivers/`) | Role / boundary |
| --- | --- |
| [`apm`](../../drivers/apm) | Advanced Power Management battery/power drivers. |
| [`dot4`](../../drivers/dot4) | IEEE 1284.4/DOT4 USB printer-related driver. |
| [`drivers`](../../drivers/drivers) | Legacy WDM/DDK driver material; inspect its own subdirectories rather than treating it as all drivers. |
| [`filters`](../../drivers/filters) | Example/basic filters and pseudo devices, including `mountmgr`, `beep`, `null` and a dummy FDO. |
| [`ftapi`](../../drivers/ftapi) | Fault-tolerant volume/partition management utilities and library; coordinate with storage/volume stack. |
| [`input`](../../drivers/input) | Keyboard, mouse, HID/joystick and input port/class drivers. |
| [`ksfilter`](../../drivers/ksfilter) | Kernel Streaming filters/support, software enumerator and audio/media stream components. |
| [`net`](../../drivers/net) | NIC/vendor and network-related hardware drivers; protocols live mainly in `net/`. |
| [`parallel`](../../drivers/parallel) · [`serial`](../../drivers/serial) | Port and serial communications drivers. |
| [`sac`](../../drivers/sac) | Special Administration Console driver/terminal support, relevant to headless operation. |
| [`smartcrd`](../../drivers/smartcrd) | Smart-card readers and common support. Authentication/user-mode services are in `ds/security`. |
| [`sound`](../../drivers/sound) · [`video`](../../drivers/video) | Sound/display driver-related trees, including vendor/monitor material. |
| [`storage`](../../drivers/storage) | Disk/CD/changer, class, port, IDE, partition, volume/filter and related drivers. |
| [`tpg`](../../drivers/tpg) | Tablet PC/pen hardware (`hwx`, `wisp`) with architecture-specific traversal. |
| [`watchdog`](../../drivers/watchdog) | Watchdog-related display support. |
| [`wdm`](../../drivers/wdm) | WDM audio, BDA/capture, USB, DVD, input and related device families. |
| [`wmilib`](../../drivers/wmilib) | WMI support library for drivers. |
| [`nlsmsg`](../../drivers/nlsmsg) | I/O error log message resources. |
| [`inc`](../../drivers/inc) · [`ddk`](../../drivers/ddk) · [`published`](../../drivers/published) | Local interface/DDK material and publication to shared header/library locations. |
| [`kmpi`](../../drivers/kmpi) | Small legacy support area (only a readme in this checkout); do not infer an active build target. |

## Device and storage path

User-mode SetupAPI in [`base/pnp/setupapi`](../../base/pnp/setupapi) and component INFs register devices; the kernel PnP and I/O managers in [`base/ntos/io`](../../base/ntos/io) coordinate drivers. For disk/file I/O, distinguish [`storage/port`](../../drivers/storage/port), [`storage/class`](../../drivers/storage/class), [`storage/classpnp`](../../drivers/storage/classpnp), [`storage/partmgr`](../../drivers/storage/partmgr) and filesystem sources in [`base/fs`](../../base/fs). For network I/O, distinguish NIC miniports here from [`net/ndis`](../../net/ndis), [`net/tcpip`](../../net/tcpip) and Winsock. For capture/audio, connect `drivers/wdm` and `ksfilter` to [`multimedia/`](multimedia.md).

## Driver change checklist

Trace the IRP/stream/request contract, power/PnP paths, synchronization/IRQL, cancel/remove/unload paths, matching INF and any DDK/public header. Check `dirs` and `sources` for processor/OS variants before promising a target is included; [`drivers/dirs`](../../drivers/dirs) names some absent optional/historical directories (`oem`, for example). The [interfaces guide](../interfaces.md#binary-and-process-boundaries) and [build limitations](../build-and-release.md#checkout-limitations) apply.
