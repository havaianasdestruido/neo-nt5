# `net/` — transport, network services and configuration

`net/` spans packet/driver-facing layers, transports, client APIs, setup, management and network services. NIC drivers also live in [`drivers/net`](../../drivers/net), SMB redirector/server in [`base/fs`](../../base/fs), and applications in `inetsrv/`/`inetcore/`. The build order is in [`net/dirs`](../../net/dirs); [all nested folders](../catalog/net.md) are cataloged.

| Path (relative to `net/`) | Responsibility / boundary |
| --- | --- |
| [`ndis`](../../net/ndis) | NDIS driver/protocol infrastructure, samples, test and user I/O components. |
| [`tcpip`](../../net/tcpip) | IP/TCP driver, APIs, services, tools and Winsock integration; see below. |
| [`sockets`](../../net/sockets) · [`tdi`](../../net/tdi) | Winsock-facing socket code and Transport Driver Interface. |
| [`ipsec`](../../net/ipsec) · [`qos`](../../net/qos) | IP security policy/keying and Quality of Service scheduling/classification. |
| [`config`](../../net/config) · [`layer2svc`](../../net/layer2svc) | Network component binding, connection UI/setup and layer-2/wireless policy/802.1X services. |
| [`dhcp`](../../net/dhcp) · [`wins`](../../net/wins) · [`snmp`](../../net/snmp) | DHCP client/server, WINS name service and SNMP management. |
| [`rras`](../../net/rras) · [`ias`](../../net/ias) | Routing/Remote Access and authentication/accounting policy service. |
| [`netbios`](../../net/netbios) · [`netbt`](../../net/netbt) · [`netbeui`](../../net/netbeui) | NetBIOS APIs/transport, NetBIOS-over-TCP/IP, and legacy NetBEUI. |
| [`nwlink`](../../net/nwlink) · [`dlc`](../../net/dlc) · [`streams`](../../net/streams) | Legacy IPX/SPX, DLC and STREAMS networking. |
| [`1394`](../../net/1394) · [`atm`](../../net/atm) · [`irda`](../../net/irda) · [`rndis`](../../net/rndis) | IEEE 1394, ATM, infrared and RNDIS media/adapters. |
| [`mcast`](../../net/mcast) · [`wlbs`](../../net/wlbs) | Multicast/PGM and Network Load Balancing. |
| [`homenet`](../../net/homenet) · [`upnp`](../../net/upnp) | Home networking (bridge/NAT-related pieces) and UPnP discovery/hosting. |
| [`tapi`](../../net/tapi) · [`unimodem`](../../net/unimodem) | Telephony API, modem stack and associated UI/provider code. |
| [`sfm`](../../net/sfm) | Services for Macintosh (AFP/AppleTalk) networking. |
| [`mmc`](../../net/mmc) · [`diagnostics`](../../net/diagnostics) | Management consoles and network diagnostics/monitoring. |
| [`jet500`](../../net/jet500) · [`winnet`](../../net/winnet) · [`netevent`](../../net/netevent) | Network-related data/storage, Windows network integration and event support; inspect leaf targets for exact behavior. |
| [`inc`](../../net/inc) · [`lib`](../../net/lib) · [`ddk`](../../net/ddk) · [`published`](../../net/published) | Internal headers/libs, DDK and published cross-project contracts. |

## Inside `tcpip/`

[`driver`](../../net/tcpip/driver) contains `common`, `ipv4`, `tcp`, `ipsec`, `sys` and debugger-extension folders. [`apis`](../../net/tcpip/apis), [`winsock`](../../net/tcpip/winsock), [`services`](../../net/tcpip/services), [`commands`](../../net/tcpip/commands), [`snmp`](../../net/tcpip/snmp), [`tpipv6`](../../net/tcpip/tpipv6), [`tools`](../../net/tcpip/tools) and [`samples`](../../net/tcpip/samples) cover the other build/API/service/test surfaces. The directory `tpipv6` is separate: do not assume IPv4 changes automatically cover IPv6. `driver/*/nt` and `driver/*/9x` are historical target variants, not extra layers on every NT packet path.

## Trace a network change

NIC/miniport in `drivers/net` → NDIS → transport (`net/tcpip`, `ipsec`, etc.) → socket/TDI APIs → consumer (SMB, IIS, client application). Also check `net/config` binding/INF, routing/address policies, shared headers/IDL and setup/management. A change to a packet structure needs both producer and consumer review; a service feature may not touch the driver at all. See [packet flow](../system-flows.md#4-a-network-packet--socket-operation) and [interface boundaries](../interfaces.md#binary-and-process-boundaries).
