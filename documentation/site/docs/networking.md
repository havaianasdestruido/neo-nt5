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
