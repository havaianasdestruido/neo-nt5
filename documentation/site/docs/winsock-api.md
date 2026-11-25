---
title: Winsock API — sockets, providers and AFD
sidebar_position: 29
description: The Winsock 2 API, the service-provider interface, how ws2_32.dll talks to afd.sys, and the functions with their implementation points in net/sockets/winsock2.
---

Winsock is a **layered API**: the application calls `ws2_32.dll`, which dispatches to a transport
service provider, which talks to `afd.sys` in the kernel. Understanding which layer owns a failure is
the whole skill.

```text
+-----------------------------------------------------------+
| Application  ->  ws2_32.dll        net/sockets/winsock2/ws2_32
+-----------------------------------------------------------+
| Service providers (SPI)           net/sockets/winsock2/wsp
+-----------------------------------------------------------+
| afd.sys                           net/sockets/winsock2/wsp/afdsys
+-----------------------------------------------------------+
| TDI transports  \Device\Tcp ...  net/tcpip, net/tdi
+-----------------------------------------------------------+
```

## Startup and cleanup

| Function | Implementation | Documentation |
| --- | --- | --- |
| `WSAStartup` | `net/sockets/winsock2/ws2_32/src/startup.cpp:112` | [WSAStartup](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsastartup) |
| `WSACleanup` | `startup.cpp:418` | [WSACleanup](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsacleanup) |
| `WSAGetLastError` | `perthrd.cpp:42` | [WSAGetLastError](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsagetlasterror) |
| `WSASetLastError` | `perthrd.cpp:67` | [WSASetLastError](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsasetlasterror) |

`WSAStartup` must be called before any other Winsock function, and its return value must be checked:

```c
WSADATA wsaData;
int rc = WSAStartup(MAKEWORD(2, 2), &wsaData);
if (rc != 0) {
    // rc IS the error code; WSAGetLastError is not set here.
    return rc;
}
if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
    WSACleanup();
    return WSANOTINITIALISED;   // requested version not available
}
```

`WSAStartup` is **reference counted per thread**: each successful call must be balanced by a
`WSACleanup`. A thread that calls `WSAStartup` and exits without `WSACleanup` leaves the count
elevated, which keeps the provider loaded and the socket handles valid in other threads — a leak
that shows up as "WSACleanup never returns".

## Socket lifecycle

| Function | Implementation | Documentation |
| --- | --- | --- |
| `socket` | `socklife.cpp:54` | [socket](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-socket) |
| `WSASocketW` | `socklife.cpp:117` | [WSASocketW](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsasocketw) |
| `WSASocketA` | `socklife.cpp:299` | [WSASocketA](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsasocketa) |
| `accept` | `socklife.cpp:384` | [accept](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-accept) |
| `WSAAccept` | `socklife.cpp:425` | [WSAAccept](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsaaccept) |
| `closesocket` | `socklife.cpp:1013` | [closesocket](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-closesocket) |

`socket()` is a thin wrapper over `WSASocketW` with `dwFlags = 0` and no protocol info. `closesocket`
is not like `CloseHandle`: a socket handle is a real kernel handle **only** in the AFD sense; you
must not pass it to `CloseHandle`, and a duplicated socket handle (`WSADuplicateSocketW` at `dupsock.cpp:44`) refers to a
**new** socket descriptor in the target process, not the same handle value.

A complete TCP server, with the error checks that matter:

```c
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

#pragma comment(lib, "ws2_32.lib")

int wmain(void)
{
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) return 1;

    SOCKET listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listener == INVALID_SOCKET) { WSACleanup(); return 1; }

    struct sockaddr_in addr = {0};
    addr.sin_family      = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    addr.sin_port        = htons(8642);

    if (bind(listener, (struct sockaddr *)&addr, sizeof(addr)) == SOCKET_ERROR) {
        printf("bind failed: %d\n", WSAGetLastError());
        closesocket(listener); WSACleanup(); return 1;
    }
    if (listen(listener, SOMAXCONN) == SOCKET_ERROR) {
        printf("listen failed: %d\n", WSAGetLastError());
        closesocket(listener); WSACleanup(); return 1;
    }

    for (;;) {
        struct sockaddr_in peer = {0};
        int peerLen = sizeof(peer);
        SOCKET s = accept(listener, (struct sockaddr *)&peer, &peerLen);
        if (s == INVALID_SOCKET) {
            if (WSAGetLastError() == WSAEINTR) continue;
            break;
        }
        char buf[512];
        int n = recv(s, buf, sizeof(buf), 0);
        if (n > 0) send(s, buf, (size_t)n, 0);
        closesocket(s);
    }

    closesocket(listener);
    WSACleanup();
    return 0;
}
```

## Name resolution

| Function | Implementation | Documentation |
| --- | --- | --- |
| `getaddrinfo` | `addrinfo.cpp:1064` | [getaddrinfo](https://learn.microsoft.com/en-us/windows/win32/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) |
| `freeaddrinfo` | `addrinfo.cpp:558` | [freeaddrinfo](https://learn.microsoft.com/en-us/windows/win32/api/ws2tcpip/nf-ws2tcpip-freeaddrinfo) |
| `getnameinfo` | `addrinfo.cpp:1571` | [getnameinfo](https://learn.microsoft.com/en-us/windows/win32/api/ws2tcpip/nf-ws2tcpip-getnameinfo) |
| `gethostbyname` | `getxbyy.cpp:288` | [gethostbyname](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-gethostbyname) |
| `gethostbyaddr` | `getxbyy.cpp` | [gethostbyaddr](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-gethostbyaddr) |
| `getservbyname` / `getservbyport` | `getxbyy.cpp` | [getservbyname](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-getservbyname) |
| `getprotobyname` | `getxbyy.cpp` | [getprotobyname](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-getprotobyname) |
| `WSAAddressToStringW` | `rnr.cpp:2544` | [WSAAddressToStringW](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsaaddresstostringw) |

`getaddrinfo` is the modern, protocol-independent API; `gethostbyname` is IPv4-only and deprecated.
Both are **blocking** and may take seconds, which is why real servers use a worker thread or
`GetAddrInfoExW` with an overlapped completion.

## Data transfer

| Function | Implementation | Documentation |
| --- | --- | --- |
| `send` | `send.cpp:41` | [send](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-send) |
| `sendto` | `send.cpp:116` | [sendto](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-sendto) |
| `WSASend` | `send.cpp:198` | [WSASend](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsasend) |
| `recv` | `recv.cpp:44` | [recv](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-recv) |
| `recvfrom` | `recv.cpp:128` | [recvfrom](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-recvfrom) |
| `WSARecv` | `recv.cpp:219` | [WSARecv](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsarecv) |
| `WSAGetOverlappedResult` | `sockctrl.cpp:830` | [WSAGetOverlappedResult](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsagetoverlappedresult) |

The **overlapped** transfer is the one that scales:

```c
WSAOVERLAPPED ov = {0};
ov.hEvent = WSACreateEvent();
WSABUF buf = { len, data };
DWORD sent = 0;

int rc = WSASend(s, &buf, 1, &sent, 0, &ov, NULL);
if (rc == SOCKET_ERROR && WSAGetLastError() != WSA_IO_PENDING) {
    // real failure
}
// completion arrives via the event, a completion port, or the completion routine
```

`WSASend` returning `SOCKET_ERROR` with `WSAGetLastError() == WSA_IO_PENDING` means **success in
progress**, not failure. Treating it as an error is the single most common overlapped-socket bug.

## Multiplexing

| Function | Implementation | Documentation |
| --- | --- | --- |
| `select` | `select.cpp:45` | [select](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-select) |
| `WSAEventSelect` | `select.cpp:158` | [WSAEventSelect](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsaeventselect) |
| `WSAAsyncSelect` | `select.cpp:220` | [WSAAsyncSelect](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsaasyncselect) |
| `WSAWaitForMultipleEvents` | `select.cpp` | [WSAWaitForMultipleEvents](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsawaitformultipleevents) |
| `WSAEnumNetworkEvents` | `select.cpp` | [WSAEnumNetworkEvents](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsaenumnetworkevents) |

Three models, with different scaling properties:

| Model | Scales to | Cost |
| --- | --- | --- |
| `select` | ~64 sockets per call (FD_SETSIZE), O(n) per call | A full scan of every set, every call |
| `WSAEventSelect` | One event per socket, up to `MAXIMUM_WAIT_OBJECTS` per wait | One kernel event object per socket |
| `WSAAsyncSelect` | Limited by the message loop | Requires a window, uses `PostMessage` |
| I/O completion ports | Tens of thousands of sockets | One port, a thread pool, overlapped I/O |

`select` is the API everyone knows and the one that stops working first. Its `FD_SET` is a fixed
array of `FD_SETSIZE` (64) sockets, and it is **modified in place** — you must rebuild the sets
before every call. A loop that passes the same `fd_set` twice reports spurious readiness.

## Options and control

| Function | Implementation | Documentation |
| --- | --- | --- |
| `setsockopt` | `sockctrl.cpp:546` | [setsockopt](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-setsockopt) |
| `getsockopt` | `sockctrl.cpp:334` | [getsockopt](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-getsockopt) |
| `ioctlsocket` | `ioctl.cpp:40` | [ioctlsocket](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-ioctlsocket) |
| `WSAIoctl` | `ioctl.cpp:84` | [WSAIoctl](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsaioctl) |
| `bind` | `sockctrl.cpp:51` | [bind](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-bind) |
| `listen` | `sockctrl.cpp:487` | [listen](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-listen) |
| `connect` | `sockctrl.cpp:110` | [connect](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-connect) |
| `getsockname` | `sockctrl.cpp:275` | [getsockname](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-getsockname) |
| `getpeername` | `sockctrl.cpp:218` | [getpeername](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-getpeername) |
| `shutdown` | `sockctrl.cpp:639` | [shutdown](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-shutdown) |

The options that matter in practice:

| Option | Level | Effect |
| --- | --- | --- |
| `SO_REUSEADDR` | `SOL_SOCKET` | Allow bind to an address in `TIME_WAIT` |
| `SO_EXCLUSIVEADDRUSE` | `SOL_SOCKET` | Prevent anyone else binding the same address |
| `SO_KEEPALIVE` | `SOL_SOCKET` | Enable TCP keepalive probes |
| `SO_LINGER` | `SOL_SOCKET` | Control `closesocket` behaviour with unsent data |
| `SO_SNDBUF` / `SO_RCVBUF` | `SOL_SOCKET` | Set the socket buffer size |
| `SO_RCVTIMEO` / `SO_SNDTIMEO` | `SOL_SOCKET` | Set a receive/send timeout |
| `TCP_NODELAY` | `IPPROTO_TCP` | Disable Nagle's algorithm |
| `SO_BROADCAST` | `SOL_SOCKET` | Allow sending to the broadcast address |

`SO_LINGER` is the one that causes data loss:

```c
LINGER lg = { 1, 0 };              // l_onoff = 1, l_linger = 0 -> hard close
setsockopt(s, SOL_SOCKET, SO_LINGER, (char *)&lg, sizeof(lg));
closesocket(s);                    // discards unsent data, sends RST
```

`l_onoff = 1` with `l_linger = 0` aborts the connection. `l_onoff = 0` (the default) performs a
graceful close in the background. `l_onoff = 1` with a positive `l_linger` blocks `closesocket` for
up to that many seconds.

## The service provider interface

`ws2_32.dll` does not implement TCP. It routes each call through a **service provider** — a DLL that
exports the `WSAPROC_TABLE`. `net/sockets/winsock2/wsp` is the provider side; the registry records
which provider handles which address family, and `WSAEnumProtocolsW` enumerates them.

```text
HKLM\SYSTEM\CurrentControlSet\Services\WinSock2\Parameters\Protocol_Catalog9\Catalog_Entries\<n>
    PackedCatalogItem     = binary WSAPROTOCOL_INFOW
    LibraryPath           = %SystemRoot%\system32\mswsock.dll
    ProtocolName          = TCP/IP
```

| SPI function | Purpose |
| --- | --- |
| `WSPStartup` | Initialise the provider, return the procedure table |
| `WSPSocket` | Create a socket |
| `WSPBind`, `WSPListen`, `WSPAccept`, `WSPConnect` | The lifecycle |
| `WSPSend`, `WSPRecv`, `WSPSendTo`, `WSPRecvFrom` | Data transfer |
| `WSPSelect` | Multiplexing |
| `WSPCloseSocket` | Close |
| `WSPGetSockOpt`, `WSPSetSockOpt` | Options |
| `WSPAddressToString`, `WSPStringToAddress` | Address formatting |
| `WSPCleanup` | Provider shutdown |

The layered-provider model (`MSAfd` → `mswsock.dll` → `afd.sys`) is why a socket call can fail with
`WSAEPROVIDERFAILEDINIT` even when the network is fine: the **catalog** entry is broken, not the
transport.

## Error codes

| Code | Value | Meaning |
| --- | --- | --- |
| `WSAEWOULDBLOCK` | 10035 | Non-blocking operation would block |
| `WSAEINPROGRESS` | 10036 | A blocking call is in progress |
| `WSAECONNRESET` | 10054 | The peer sent an RST |
| `WSAECONNABORTED` | 10053 | The connection was aborted (timeout) |
| `WSAETIMEDOUT` | 10060 | The connection timed out |
| `WSAECONNREFUSED` | 10061 | The peer refused the connection |
| `WSAENOTCONN` | 10057 | The socket is not connected |
| `WSAEINVAL` | 10022 | An argument is invalid, or the socket is already bound |
| `WSAEADDRINUSE` | 10048 | The address is in use |
| `WSAEAFNOSUPPORT` | 10047 | The address family is not supported |
| `WSAEMFILE` | 10024 | No more socket descriptors available |
| `WSAENOBUFS` | 10055 | No buffer space available |
| `WSAENOTSOCK` | 10038 | The handle is not a socket |
| `WSAEINTR` | 10004 | The call was cancelled (`WSACancelBlockingCall`) |
| `WSA_IO_PENDING` | 997 | The overlapped operation will complete later |

`WSAEWOULDBLOCK` on a non-blocking socket is not an error: it means "no data yet, try again". The
loop that treats it as fatal exits on the first idle poll.

## Frequently asked questions

### Q: Why do I have to call `WSAStartup` at all?

Because Winsock is a **dynamically loaded** subsystem: `WSAStartup` loads the provider catalog, maps
the service-provider DLLs, and initialises the per-thread state that `WSAGetLastError` uses. It also
negotiates the version. A call into `ws2_32.dll` before `WSAStartup` returns `WSANOTINITIALISED`.

### Q: Is a `SOCKET` a kernel handle?

It is a handle-like value, but it is not a `HANDLE` for `CloseHandle`. `ws2_32.dll` keeps a table
mapping socket values to AFD file handles. Use `closesocket`. Passing a `SOCKET` to `CloseHandle`
closes the wrong thing or fails.

### Q: Why does `recv` return 0?

Because the peer performed an orderly shutdown. `recv` returning 0 means "no more data, connection
closed". Returning `SOCKET_ERROR` with `WSAEWOULDBLOCK` means "no data yet". These are different
conditions, and confusing them produces the "server ignores disconnects" bug.

### Q: What is the difference between `shutdown(s, SD_SEND)` and `closesocket(s)`?

`shutdown(SD_SEND)` sends a FIN and stops **sending**; the socket can still receive. `closesocket`
releases the socket and, if there is unsent data, may send an RST (hard close) or linger. The
graceful pattern is `shutdown(s, SD_SEND)`, drain `recv` until it returns 0, then `closesocket`.

### Q: How do I make a socket non-blocking?

`ioctlsocket(s, FIONBIO, &mode)` with `mode = 1`, or create it with `WSASocketW(..., WSA_FLAG_OVERLAPPED, ...)`
and use overlapped I/O. Non-blocking sockets return `WSAEWOULDBLOCK` instead of waiting.

### Q: Why does `select` only handle 64 sockets?

Because `FD_SETSIZE` is 64 in the published headers and `fd_set` is a fixed array. `select` is a
Unix-compatibility API; Windows provides it for portability. For more sockets use `WSAEventSelect`,
`WSAAsyncSelect`, or — the scalable answer — I/O completion ports with overlapped I/O.

### Q: Why does `connect` fail with `WSAEADDRINUSE` when I restart my server?

Because the old socket is in `TIME_WAIT` for up to four minutes. Set `SO_REUSEADDR` **before**
`bind` to allow the bind to succeed. Do not use `SO_EXCLUSIVEADDRUSE` for a restartable server; it
does the opposite.

### Q: Where is `TransmitFile` implemented?

`TransmitFile` is an **extension** exported by `mswsock.dll`, not by `ws2_32.dll`. In this checkout
the `mswsock` sources are not present as a standalone directory; the kernel side is the AFD path in
`net/sockets/winsock2/wsp/afdsys`. Do not cite a user-mode implementation path for it.

### Q: What is `WSA_FLAG_OVERLAPPED` for?

It marks the socket as usable with overlapped I/O (`WSAOVERLAPPED`). A socket created with plain
`socket()` already has the flag set on Windows NT and later, but `WSASocketW` lets you request it
explicitly along with `WSA_FLAG_NO_HANDLE_INHERIT` to prevent handle inheritance into child
processes.

### Q: Why does my server stop accepting after 8192 connections?

Because the listen backlog is capped by `SOMAXCONN` (and by the transport's own limit). `listen`
with `SOMAXCONN` sets the maximum the transport allows; a slow accept loop still fills it. Also
check nonpaged pool: each connection consumes kernel memory, and a large backlog with slow
consumers exhausts it before the socket limit is reached.

### Q: What does `WSAStartup` version `MAKEWORD(2,2)` actually check?

It asks for Winsock 2.2 and requires the DLL to support **at least** 2.2. The DLL returns the highest
version it supports that is ≤ the request. If it cannot support 2.2, `WSAStartup` returns
`WSAVERNOTSUPPORTED` and `WSADATA.wVersion` is not valid.

### Q: Is there a way to get a socket's local address without `getsockname`?

`getsockname` is the API. On Windows the alternative is `WSADuplicateSocket` plus inspection of the
`WSAPROTOCOL_INFO`, but that is for duplicating into another process, not for querying the address.
Use `getsockname`.

### Q: How do I detect a broken connection?

`SO_KEEPALIVE` plus a reasonable interval, or application-level heartbeats. TCP keepalive only
detects a dead peer after the interval plus the probes, which is minutes by default. A server that
must notice disconnects promptly implements its own timeout.

### Q: Where is the Winsock error string table?

In `ws2_32.dll` as a message resource. `FormatMessageW` with `FORMAT_MESSAGE_FROM_HMODULE` and the
module handle of `ws2_32.dll` formats a Winsock error. Do not use `FORMAT_MESSAGE_FROM_SYSTEM`
alone — that only covers `winerror.h` ranges, and the Winsock codes (10000–11999) need the module.
