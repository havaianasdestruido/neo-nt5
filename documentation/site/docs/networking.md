---
title: Networking stack
sidebar_position: 6
description: NDIS miniports, the TCP/IP driver, TDI, Winsock and AFD, plus the network services and the in-tree locking documentation.
---

Networking in this tree spans four projects, and the boundaries between them are contractual:
`drivers/net` (hardware), `net/ndis` (the driver interface), `net/tcpip` and friends (protocol
drivers), and `net/sockets` plus `net/tdi` (the user-facing transport interface). A socket API change
is not a packet-driver change, and vice versa.

## Layer map

```text
application / server role  (inetsrv/iis, inetcore/wininet, an app)
        |
   ws2_32.dll / wsock32.dll        net/sockets/winsock2/ws2_32, wsock32
        |  Winsock SPI
   afd.sys                          net/sockets/winsock2/wsp/afdsys
        |  TDI
   tcpip.sys / other transports    net/tcpip/driver, net/netbt, net/nwlink, net/atm, net/irda, net/dlc
        |  NDIS
   ndis.sys                         net/ndis/sys
        |
   miniport driver                  drivers/net, net/rndis, net/1394
```

`net/` also holds the services and configuration around that stack: `dhcp`, `wins`, `ipsec`, `rras`,
`config`, `qos`, `mcast`, `upnp`, `snmp`, `tapi`, `unimodem`, `ias`, `sfm`, `wlbs`, `homenet`,
`layer2svc`, `diagnostics`, plus the naming services `netbt` and `netbios`. Legacy transports coexist
in this historical tree — their presence does not mean every one is on the default path.

## NDIS: registering a miniport

`ndis.sys` is built from `net/ndis/sys`, whose files are split by role: `miniport.c`, `protocol.c`,
`mac.c`, `sendm.c`, `requestm.c`, `timerm.c`, `dma.c`, `ndispnp.c`, `ndispwr.c`, `ndiswmi.c`,
`ndissd.c`. Registration of a miniport goes through
[`net/ndis/sys/configm.c:36`](https://github.com/havaianasdestruido/neo-nt5/blob/main/net/ndis/sys/configm.c):

```c
NDIS_STATUS
NdisMRegisterMiniport(
    IN  NDIS_HANDLE             NdisWrapperHandle,
    IN  PNDIS_MINIPORT_CHARACTERISTICS MiniportCharacteristics,
    IN  UINT                    CharacteristicsLength
    )
```

The `CharacteristicsLength` parameter exists so a newer wrapper can accept an older, smaller
characteristics block — a versioning convention you must preserve when adding a field. NDIS also
ships a WMI schema, `net/ndis/sys/ndis.mof`, so management queries over NDIS objects are a contract
too.

`net/ndis/` additionally contains `samples/`, `loopback/`, `tunmp/`, `uio/` and `pnptst/` — reference
and test miniports.

## TCP/IP driver

`net/tcpip/driver/tcp/` is the TCP implementation, organised by function rather than by layer:

| File | Responsibility |
| --- | --- |
| `tcpconn.c` | Connection state machine, TCB management |
| `tcpsend.c` | Segment transmission |
| `tcprcv.c` | Segment reception and reassembly |
| `tcpdeliv.c` | Delivery of received data to the TDI client |
| `tcb.c` | Transmission control block lifecycle |
| `addr.c`, `dgram.c`, `raw.c`, `udp.c` | Addressing, datagrams, raw and UDP endpoints |
| `pnp.c`, `ntinit.c`, `ntdisp.c`, `ntautodl.c` | PnP, initialisation, dispatch, auto-load |
| `secfltr.c` | Security filter hook (IPsec) |

Real entry points from
[`net/tcpip/driver/tcp/tcpsend.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/net/tcpip/driver/tcp/tcpsend.c):

```c
TCPSendComplete(void *Context, PNDIS_BUFFER BufferChain, IP_STATUS SendStatus)   // line 262
RcvWin(TCB * WinTCB)                                                             // line 397
SendSYN(TCB * SYNTcb, CTELockHandle TCBHandle)                                   // line 680
SendACK(TCB * ACKTcb)                                                            // line 1044
SendRSTFromHeader(TCPHeader UNALIGNED * TCPH, uint Length, IPAddr Dest, ...)     // line 1435
```

and from `tcpdeliv.c`:

```c
PendData(TCB * RcvTCB, uint RcvFlags, IPRcvBuf * InBuffer, uint Size)   // line 267
BufferData(TCB * RcvTCB, uint RcvFlags, IPRcvBuf * InBuffer, uint Size) // line 329
IndicateData(TCB * RcvTCB, uint RcvFlags, IPRcvBuf * InBuffer, uint Size) // line 573
```

Two conventions matter when editing here. The `CTELockHandle` parameter is the lock acquired by the
caller and released by the callee — a calling-convention detail that is easy to break silently. And
`TCPHeader UNALIGNED *` is not decoration: headers arrive at arbitrary offsets inside NDIS buffers,
so an unaligned-safe access is required on architectures that fault otherwise.

There is also `net/tcpip/tpipv6/` (the separate IPv6 stack of this era) and `net/tcpip/winsock/` —
`wshtcpip.c` is the Winsock name-space helper for TCP/IP.

## AFD: the socket-to-TDI bridge

`afd.sys` is not in a directory called `afd`; it is a Winsock service provider at
`net/sockets/winsock2/wsp/afdsys/`. Its files map to socket verbs: `create.c`, `bind.c`,
`connect.c`, `listen.c`, `accept.c`, `send.c`, `receive.c`, `recvdg.c`, `recvvc.c`, `select.c`,
`poll.c`, `eventsel.c`, `group.c`, `close.c`, `fastio.c`, `pnp.c`.

```c
// net/sockets/winsock2/wsp/afdsys/send.c:91
NTSTATUS
FASTCALL
AfdSend (
    IN PIRP Irp,
    IN PIO_STACK_LOCATION IrpSp
    )
```

`AfdSendDatagram` is at line 1701 in the same file. The user-mode half is
`net/sockets/winsock2/ws2_32/` (with `wsock32/` for the Winsock 1.1 shim and `ws2help/` for the
helper/name-space layer).

### Read the in-tree locking document first

`net/sockets/winsock2/wsp/afdsys/` contains a 440-line
[`spinlock.txt`](https://github.com/havaianasdestruido/neo-nt5/blob/main/net/sockets/winsock2/wsp/afdsys/spinlock.txt)
that documents every use of the global AFD spin lock, per function, with the strategy that justifies
it:

```text
AfdSpinLock Usage
~~~~~~~~~~~~~~~~~

    ACCEPT.C

        Function:   AfdDeferAccept
        Protects:   Endpoint->Common.VcListening.UnacceptedConnectionListHead
        Synopsis:   Used when deferring an accept (putting a connection back
                    on the endpoint's unaccepted connection queue).
        Strategy:   None. Deferring accepted connections is a very low
                    frequency operation (and is impossible in WinSock 1.1).

    BIND.C

        Function:   AfdRestartGetAddress
        Protects:   Endpoint->LocalAddress[Length]
        Synopsis:   Used when allocating an endpoint's local address buffer
                    to prevent multiple processors from allocating the buffer.
```

Any change that takes or releases `AfdSpinLock` should be reflected in this file, because the
document *is* the record of which orderings are safe. A sibling
[`registry.txt`](https://github.com/havaianasdestruido/neo-nt5/blob/main/net/sockets/winsock2/wsp/afdsys/registry.txt)
(202 lines) documents AFD's registry parameters the same way.

## NDIS in detail

NDIS is the boundary between the hardware-specific miniport and the protocol stack. `net/ndis/sys`
is the NDIS wrapper; the miniport's contract is a set of function pointers it exports and a set of
NDIS services it calls.

| Miniport exports | Purpose |
| --- | --- |
| `DriverEntry` | Registers the miniport with `NdisMRegisterMiniport` or `NdisMRegisterMiniportDriver` |
| `MiniportInitialize` | Bring the adapter to a known state |
| `MiniportReset` | Reset the adapter |
| `MiniportHalt` | Tear it down |
| `MiniportSend` / `MiniportSendPackets` | Transmit a packet or a batch |
| `MiniportReturnPacket` | Reclaim a packet after a send completes |
| `MiniportQueryInformation` / `MiniportSetInformation` | OID requests |
| `MiniportISR` / `MiniportHandleInterrupt` | Interrupt handling (split by design) |
| `MiniportCheckForHang` | Detect a stalled adapter |
| `MiniportShutdown` | Power-down path |

A miniport never allocates or frees packets. It describes the transfer and calls
`NdisMIndicateReceivePacket` for receives, and returns `NDIS_STATUS_PENDING` from
`MiniportSend` unless the send completed synchronously. `MiniportReturnPacket` is where the protocol
reclaims the packet — a miniport that forgets to call it leaks the pool.

| NDIS service | Purpose |
| --- | --- |
| `NdisMRegisterMiniport` | Register a legacy miniport (`net/ndis/sys/configm.c:36`) |
| `NdisMRegisterMiniportDriver` | Register an NDIS 5+ miniport driver |
| `NdisMSetAttributesEx` | Declare the adapter's media, properties and callback table |
| `NdisMAllocateMapRegisters` | Bus-master DMA map registers |
| `NdisMStartBufferPhysicalMapping` | Map a buffer for DMA |
| `NdisMQueryAdapterResources` | Get the assigned resources |
| `NdisReadConfiguration` | Read a registry parameter (`net/ndis/sys/configm.c`) |
| `NdisWriteConfiguration` | Write one |
| `NdisMIndicateReceivePacket` | Deliver received data upward |
| `NdisMSetTimer` / `NdisMCancelTimer` | Miniport timers |
| `NdisMRegisterDevice` | Create a device object for a control channel |
| `NdisMGetDeviceProperty` | Query PnP device properties |

### OID requests

An OID (Object ID) is a hardware/protocol parameter. The protocol sends an OID request
(`NdisOidRequest` in NDIS 5, `NdisRequest` in NDIS 4) and the miniport answers it. Some are
mandatory, some are optional, some are settable, some are read-only.

| OID | Meaning |
| --- | --- |
| `OID_GEN_SUPPORTED_LIST` | The OIDs the miniport supports |
| `OID_GEN_HARDWARE_STATUS` | `NdisHardwareStatusReady`, `Initializing`, `Reset`, `Closing`, `NotReady` |
| `OID_GEN_MEDIA_SUPPORTED` / `OID_GEN_MEDIA_IN_USE` | `NdisMedium802_3`, `NdisMedium802_5`, `NdisMediumFddi`, `NdisMediumAtm`, ... |
| `OID_GEN_MAXIMUM_FRAME_SIZE` | The largest frame the adapter can carry |
| `OID_GEN_LINK_SPEED` | Link speed in 100 bps units |
| `OID_GEN_TRANSMIT_BUFFER_SPACE` | Transmit buffer space |
| `OID_GEN_VENDOR_ID` | Vendor ID |
| `OID_GEN_VENDOR_DESCRIPTION` | Vendor string |
| `OID_GEN_CURRENT_PACKET_FILTER` | The packet filter (promiscuous, broadcast, multicast, ...) |
| `OID_GEN_CURRENT_LOOKAHEAD` | Lookahead size |
| `OID_802_3_PERMANENT_ADDRESS` | The burnt-in MAC address |
| `OID_802_3_CURRENT_ADDRESS` | The currently programmed address |
| `OID_802_3_MULTICAST_LIST` | The multicast address list |
| `OID_802_3_MAXIMUM_LIST_SIZE` | Maximum multicast addresses |

The headers are `public/ddk/inc/ndis.h` (for `NdisMedium*`) and `public/sdk/inc/ntddndis.h` for
the OID definitions; the NDIS library's own copy is under `net/ndis/sys`.

## TDI and the transport boundary

TDI (Transport Driver Interface) is the kernel-mode transport interface that AFD (the Winsock
kernel-mode helper) uses. `net/tdi` holds the TDI client library; the transports implement
`TdiBuildDeviceIoControlSetEvent`-style handlers.

| TDI request | Purpose |
| --- | --- |
| `TDI_ASSOCIATE_ADDRESS` | Associate a transport address with a connection |
| `TDI_CONNECT` | Connect |
| `TDI_DISCONNECT` | Disconnect |
| `TDI_LISTEN` | Listen |
| `TDI_ACCEPT` | Accept |
| `TDI_SEND` / `TDI_RECEIVE` | Datagram and stream data |
| `TDI_SEND_DATAGRAM` / `TDI_RECEIVE_DATAGRAM` | Connectionless data |
| `TDI_SET_EVENT_HANDLER` | Register an event handler |
| `TDI_QUERY_INFORMATION` / `TDI_SET_INFORMATION` | Query/set transport state |

The transport's device object is `\Device\Tcp`, `\Device\Udp`, `\Device\RawIp`, `\Device\Ip`, or
`\Device\IPMulticast` in this tree. An AFD socket opens one of these and turns Winsock calls into
TDI requests.

## AFD: from Winsock to TDI

`net/sockets/winsock2/wsp/afdsys` is the **Ancillary Function Driver**, the kernel-mode part of Winsock. `ws2_32.dll` talks
to it with IOCTLs:

| AFD IOCTL | Purpose |
| --- | --- |
| `IOCTL_AFD_BIND` | Bind a socket to an address |
| `IOCTL_AFD_CONNECT` | Connect |
| `IOCTL_AFD_LISTEN` | Listen |
| `IOCTL_AFD_ACCEPT` | Accept a connection |
| `IOCTL_AFD_SEND` / `IOCTL_AFD_RECEIVE` | Data transfer |
| `IOCTL_AFD_SELECT` | `select()` |
| `IOCTL_AFD_WSP_RECV_DATAGRAM` | Datagram receive |
| `IOCTL_AFD_GET_SOCK_NAME` / `IOCTL_AFD_GET_PEER_NAME` | `getsockname` / `getpeername` |
| `IOCTL_AFD_SET_CONTEXT` / `IOCTL_AFD_GET_CONTEXT` | Per-socket context |
| `IOCTL_AFD_TRANSMIT_FILE` | `TransmitFile` |
| `IOCTL_AFD_TRANSMIT_PACKETS` | `TransmitPackets` |
| `IOCTL_AFD_WSP_EVENT_SELECT` | `WSAEventSelect` |
| `IOCTL_AFD_WSP_ENUM_NETWORK_EVENTS` | `WSAEnumNetworkEvents` |

`IOCTL_AFD_*` codes are defined in the private headers inside
`net/sockets/winsock2/wsp/afdsys` (`afdp.h`, `afdstr.h`, `afddata.h`); `net/published/inc/afd.w` is
the published AFD interface description. The `IOCTL_AFD_SELECT` request is how `select()` blocks: AFD
queues the request and completes it when any of the socket events in the mask fires.

## Winsock in the tree

`net/sockets/winsock2` is the user-mode Winsock stack: `ws2_32/` builds `ws2_32.dll`, `wsock32/`
builds `wsock32.dll`, and `wsp/` holds the service-provider side including `afdsys`. The **catalog** of providers is the registry key
`HKLM\SYSTEM\CurrentControlSet\Services\WinSock2\Parameters\Protocol_Catalog9` (and
`Namespace_Catalog5`). Each entry is a `WSAPROTOCOL_INFOW`-shaped record with a `ProtocolName` and
a `CatalogEntryId`; the namespace providers are enumerated by `WSAEnumNameSpaceProvidersW`.

| Library | Role |
| --- | --- |
| `ws2_32.dll` | The Winsock 2 API; talks to AFD |
| `wsock32.dll` | The Winsock 1.1 compatibility layer |
| `mswsock.dll` | The Microsoft extensions (`TransmitFile`, `AcceptEx`, `ConnectEx`, `WSARecvEx`) |
| `wshtcpip.dll` | The TCP/IP helper for `ws2_32` |
| `wshqos.dll` | Quality of Service helper |

## Frequently asked questions

### Q: A `send()` hangs. Which layer do I instrument first?

Work down the stack and stop at the first layer that still has the data:

```text
ws2_32 send()  -> afd!AfdSend (afdsys/send.c:91)
              -> TDI send IRP into tcpip
              -> tcp!SendSYN / retransmit logic (tcpsend.c)
              -> NdisMSend -> miniport
```

`afd` keeps per-endpoint state and a send-possible event handler
(`AfdSendPossibleEventHandler`, `send.c:2055`); `tcp` keeps the send window in `RcvWin`/TCB state.
A hang with data queued in `afd` is a transport problem; a hang with an empty `afd` queue and a
stalled TCB is a TCP or driver problem.

### Q: What is TDI, and is it still used here?

TDI (Transport Driver Interface) is the kernel-mode contract between transports and their clients,
implemented in `net/tdi/` (`sys`, `sample`). AFD is a TDI client of TCP/IP; `netbt` and other
transports expose TDI too. It is present and load-bearing in this snapshot — a change to TCP/IP's TDI
handling affects every TDI client, not just Winsock.

### Q: How do I add a parameter that a protocol driver reads from the registry?

Three places have to agree, and the tree keeps a written record for at least one of them:

```bash
# 1. the reader in the driver
rg -n 'RTL_QUERY_REGISTRY_TABLE|Parameters' net/tcpip/driver/tcp/ntinit.c | head

# 2. the setup default in an INF or hive
rg -rn --glob '*.inf' 'TcpWindowSize|TcpMaxDataRetransmissions' base/ntsetup net | head

# 3. the documentation of record, where the component keeps one
cat net/sockets/winsock2/wsp/afdsys/registry.txt | head -20
```

A driver that reads a value with no setup default will silently behave differently on a clean install.

### Q: Is IPsec part of TCP/IP or separate?

Separate, with a hook. `net/ipsec/` holds the IPsec implementation, and TCP/IP calls into it through
`net/tcpip/driver/tcp/secfltr.c` (and the matching `ipsec/` directory under `net/tcpip/driver`).
A filter that drops or transforms packets can therefore look like a TCP bug. Check `secfltr.c`
before concluding the transport misbehaved.

### Q: Which stack handles a UNC file share over the network?

Not the socket layer. `base/fs/rdr2` speaks SMB over TDI directly, so a redirector problem lives in
`base/fs/rdr2` and `base/fs/mup`, not in `ws2_32` or `afd`. See
[I/O, file systems and storage](/io-storage#network-path-resolution).

### Q: Where is the server side of HTTP?

`inetsrv/iis/` — with `iisrearc` (the request-processing architecture) and `svcs/w3` (the WWW
service), plus `admin`, `config`, `exe`, `inc` and the in-tree `iisntw.chm`. Client-side HTTP is a
different project entirely: `inetcore/wininet`, `inetcore/urlmon`, `inetcore/mshtml`. Changing one
does not change the other.

### Q: How do I tell a real protocol path from a legacy one?

Check reachability, not presence. `net/dirs` and each subtree's `dirs` decide what the build
traverses; `OPTIONAL_DIRS` and architecture qualifiers can exclude a folder:

```bash
cat net/dirs
cat net/tcpip/dirs
grep -rn "OPTIONAL_DIRS" net/*/dirs | head
```

`net/branch-reasons-and-info.txt` and `net/owners.txt` are checked in and record ownership and
branch history for this project — useful when a directory's status is unclear.

### Q: Why does my miniport's `MiniportSend` get a packet it cannot use?

Because the packet's buffer chain may not be contiguous or may not match the adapter's alignment.
Use `NdisQueryPacket` to get the buffer count, `NdisGetFirstBufferFromPacket` to get the first
buffer, and `NdisMStartBufferPhysicalMapping` to map it for DMA. A miniport that assumes
`FirstBuffer` holds the whole frame works only for small frames and crashes on jumbo or coalesced
packets.

### Q: What is the difference between `NdisMRegisterMiniport` and `NdisMRegisterMiniportDriver`?

`NdisMRegisterMiniport` registers a **legacy** miniport that NDIS calls back into for each adapter;
`NdisMRegisterMiniportDriver` registers an NDIS 5 miniport **driver** that returns an
`NDIS_MINIPORT_CHARACTERISTICS` table and is initialised per adapter. The 5.x model separates the
driver from the adapter, which is what PnP requires. The legacy entry point at
`net/ndis/sys/configm.c:36` is the shim that adapts the old contract.

### Q: How does `select()` actually block?

`ws2_32.dll` calls `IOCTL_AFD_SELECT` with a mask of events. AFD queues the request and completes it
when any of the sockets in the set signals one of the events, or when the timeout expires. That is
why `select()` on a socket that is not in the mask returns immediately, and why closing a socket
with a pending `select()` completes the request with `STATUS_CANCELLED`.

### Q: What is `TransmitFile` doing that `send()` cannot?

`TransmitFile` (`IOCTL_AFD_TRANSMIT_FILE`) sends a file's data directly from the cache without
copying it into user buffers, and can prepend/append a small user buffer and a trailer. The
kernel-side path is `net/sockets/winsock2/wsp/afdsys` plus the TDI fast path. It is
only meaningful for a **connected** socket, and only when the file is cached.

### Q: Where does `netstat` get its information?

`net/tdi`'s `TDI_QUERY_INFORMATION` with `TDI_QUERY_ADDRESS_INFO`/`TDI_QUERY_CONNECTION_INFO` is
the kernel path; the user-mode consumer is `net/sockets/winsock2` and the `iphlpapi`/`netstat` tools. The
TCP/IP driver's device objects (`\Device\Tcp`, `\Device\Udp`) expose the same information through
IOCTLs that `GetTcpTable`/`GetUdpTable` use.

### Q: Why is my NDIS miniport's interrupt handler running at the wrong IRQL?

`MiniportISR` runs at the adapter's `SynchronIRQL` and must only acknowledge the interrupt and
defer work. `MiniportHandleInterrupt` runs at `DISPATCH_LEVEL` via a DPC and does the real work. If
you call NDIS functions from `MiniportISR` that may only be called at `DISPATCH_LEVEL`, you lower
the IRQL illegally. Keep `MiniportISR` to `NdisMSynchronizeWithInterrupt`-safe operations.

### Q: What is `NdisMedium` and why does it matter?

`NdisMedium` is the media type the adapter claims (`NdisMedium802_3`, `NdisMedium802_5`,
`NdisMediumFddi`, `NdisMediumAtm`, `NdisMediumWan`, `NdisMediumLocalTalk`, ...). The protocol above
uses it to decide how to parse the frame. Reporting the wrong medium is a classic 802.11 miniport
bug: the adapter claims 802.3 but delivers 802.11 frames, so the protocol mis-parses every packet.

### Q: Is there a loopback adapter in this tree?

Yes. `net/ndis/loopback` implements the loopback miniport (MSLOOP), and `net/ndis/config` has the
`netcfg` components for installing it. It is a real NDIS miniport that short-circuits sends back to
receives, which makes it useful for testing protocol stacks without hardware.
