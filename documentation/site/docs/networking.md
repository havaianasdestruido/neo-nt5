---
title: Networking stack
sidebar_position: 6
description: NDIS miniports, the TCP/IP driver, TDI, Winsock and AFD with verified ws2_32 entry points, the network services, the in-tree locking documentation, and the official Winsock/NDIS references.
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

## Winsock: the user-mode surface in this tree

`ws2_32` is built from `net/sockets/winsock2/ws2_32/src/`, and each socket verb has its file. Verified
definition locations in this checkout:

| API | Definition | Official documentation |
| --- | --- | --- |
| `WSAStartup` | [`net/sockets/winsock2/ws2_32/src/startup.cpp:112`](https://github.com/havaianasdestruido/neo-nt5/blob/main/net/sockets/winsock2/ws2_32/src/startup.cpp) | [nf-winsock2-wsastartup](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsastartup) |
| `WSASocketW` | [`net/sockets/winsock2/ws2_32/src/socklife.cpp:117`](https://github.com/havaianasdestruido/neo-nt5/blob/main/net/sockets/winsock2/ws2_32/src/socklife.cpp) | [nf-winsock2-wsasocketw](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsasocketw) |
| `WSAConnect` | [`net/sockets/winsock2/ws2_32/src/sockctrl.cpp:693`](https://github.com/havaianasdestruido/neo-nt5/blob/main/net/sockets/winsock2/ws2_32/src/sockctrl.cpp) | [nf-winsock2-wsaconnect](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsaconnect) |
| `send` | [`net/sockets/winsock2/ws2_32/src/send.cpp:41`](https://github.com/havaianasdestruido/neo-nt5/blob/main/net/sockets/winsock2/ws2_32/src/send.cpp) | [nf-winsock2-send](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-send) |
| `sendto` | `net/sockets/winsock2/ws2_32/src/send.cpp:116` | [nf-winsock2-sendto](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-sendto) |
| `WSASend` | `net/sockets/winsock2/ws2_32/src/send.cpp:198` | [nf-winsock2-wsasend](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsasend) |
| `recv` | `net/sockets/winsock2/ws2_32/src/recv.cpp:44` | [nf-winsock2-recv](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-recv) |
| `WSARecv` | `net/sockets/winsock2/ws2_32/src/recv.cpp:219` | [nf-winsock2-wsarecv](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsarecv) |

The `WSASocketW` definition shows the in-tree style — a thin wrapper whose routine comment *is* the
contract:

```c
// net/sockets/winsock2/ws2_32/src/socklife.cpp:117
WSASocketW (
    IN int af,
    IN int type,
    IN int protocol,
    IN LPWSAPROTOCOL_INFOW lpProtocolInfo,
    IN GROUP g,
    IN DWORD dwFlags)
/*++
Routine Description:

    Create  a  socket  which is bound to a specific transport service provider,
    optionally create and/or join a socket group.
```

The official page for `WSASocketW` documents what the wrapper must preserve: `lpProtocolInfo` lets a
caller duplicate or redirect a socket across processes, `g` is the socket-group semantics of the
era, and `dwFlags` carries `WSA_FLAG_OVERLAPPED` and the in-tree `WSA_FLAG_NO_HANDLE_INHERIT`
handling. `net/sockets/winsock2/wsock32/` is the Winsock 1.1 shim over the same providers and
`ws2help/` is the helper/name-space layer.

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
characteristics block — a versioning convention you must preserve when adding a field. The official
documentation is at
[NdisMRegisterMiniport function (ndis.h), Microsoft Learn](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiport),
and the miniport entry-point set it describes (`MiniportInitialize`, `MiniportSend`,
`MiniportTransferData`, `MiniportReset`, …) is the structure `MiniportCharacteristics` fills in.

Other anchors in the same file and its siblings:

| Routine | Location | Role |
| --- | --- | --- |
| `NdisMRegisterMiniport` | `net/ndis/sys/configm.c:36` | Register the driver with NDIS |
| `NdisMRegisterDevice` | `net/ndis/sys/configm.c:418` | Create a control device object for a miniport |
| `NdisMSendComplete` | [`net/ndis/sys/sendm.c:489`](https://github.com/havaianasdestruido/neo-nt5/blob/main/net/ndis/sys/sendm.c) | Report an async send finished — the top of the send-completion path |

NDIS also ships a WMI schema, `net/ndis/sys/ndis.mof`, so management queries over NDIS objects are a
contract too.

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

The receive side is the mirror, at
[`net/sockets/winsock2/wsp/afdsys/receive.c:44`](https://github.com/havaianasdestruido/neo-nt5/blob/main/net/sockets/winsock2/wsp/afdsys/receive.c):

```c
AfdReceive (
    IN PIRP Irp,
    IN PIO_STACK_LOCATION IrpSp
    )
{
    NTSTATUS status;
    AFD_LOCK_QUEUE_HANDLE lockHandle;
    PAFD_ENDPOINT endpoint;
    PAFD_CONNECTION connection;
```

`AfdCreate` is at `create.c:40` and `AfdSendDatagram` at `send.c:1701`. Every `Afd*` dispatch routine
takes exactly the `(Irp, IrpSp)` pair — AFD is a kernel driver and its "API surface" is IRP codes,
which is why a Winsock bug that reproduces at the `ws2_32` layer can still be an AFD IRP-handling
bug. The user-mode half is `net/sockets/winsock2/ws2_32/` (with `wsock32/` for the Winsock 1.1 shim
and `ws2help/` for the helper/name-space layer).

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

## References

Official Microsoft documentation for the layers on this page:

| Routine / topic | Official documentation |
| --- | --- |
| `WSAStartup` | [https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsastartup](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsastartup) |
| `WSASocketW` | [https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsasocketw](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsasocketw) |
| `send` / `recv` | [https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-send](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-send), [https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-recv](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-recv) |
| `WSASend` / `WSARecv` | [https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsasend](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsasend), [https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsarecv](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsarecv) |
| Winsock version negotiation | [https://learn.microsoft.com/en-us/windows/win32/winsock/initializing-winsock](https://learn.microsoft.com/en-us/windows/win32/winsock/initializing-winsock) |
| `NdisMRegisterMiniport` | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiport](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiport) |
| NDIS miniport drivers | [https://learn.microsoft.com/en-us/windows-hardware/drivers/network/ndis-miniport-drivers](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/ndis-miniport-drivers) |
| TDI transport drivers | [https://learn.microsoft.com/en-us/windows-hardware/drivers/network/tdi-transport-drivers](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/tdi-transport-drivers) |
| Winsock SPI | [https://learn.microsoft.com/en-us/windows/win32/winsock/winsock-service-provider-interface-2-2](https://learn.microsoft.com/en-us/windows/win32/winsock/winsock-service-provider-interface-2-2) |

In-tree anchors:

| Document / file | Why |
| --- | --- |
| [`net/sockets/winsock2/wsp/afdsys/spinlock.txt`](https://github.com/havaianasdestruido/neo-nt5/blob/main/net/sockets/winsock2/wsp/afdsys/spinlock.txt) | The locking contract, per function |
| [`net/sockets/winsock2/wsp/afdsys/registry.txt`](https://github.com/havaianasdestruido/neo-nt5/blob/main/net/sockets/winsock2/wsp/afdsys/registry.txt) | AFD's registry parameters |
| [`net/ndis/sys/configm.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/net/ndis/sys/configm.c) | Miniport registration |
| [`net/branch-reasons-and-info.txt`](https://github.com/havaianasdestruido/neo-nt5/blob/main/net/branch-reasons-and-info.txt) | Branch history for `net/` |
| [`net/owners.txt`](https://github.com/havaianasdestruido/neo-nt5/blob/main/net/owners.txt) | Ownership per subtree |

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

### Q: `WSASocketW` and `socket` behave differently in my test. Where would that come from?

From `net/sockets/winsock2/ws2_32/src/socklife.cpp` — the two are separate exports with separate
setup paths, and `WSASocketW` additionally handles `lpProtocolInfo` duplication and socket groups.
Check which export the test actually binds (`wsock32`'s `socket` is a Winsock 1.1 shim with different
error and inheritance behaviour), then read the corresponding definition on this page's table before
suspecting `afd`.
