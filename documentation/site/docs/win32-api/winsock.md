---
title: "Winsock 2 sockets"
sidebar_position: 19
description: "WSAStartup, socket, bind, listen, accept, connect, send, recv and name resolution: official signatures, the net/sockets implementation and compiled examples using loopback only."
---

# Winsock 2 sockets

Winsock 2 is the socket API. The client DLL `ws2_32` and its service provider sit in `net/sockets/winsock2`, and below it the kernel socket path runs through AFD (`net/sockets/winsock2/wsp/afdsys` in the networking tree, see [Networking stack](/networking)). Every example here uses loopback only, so it can be compiled and reasoned about without network access.

Remember that a successful `WSAStartup` must be paired with `WSACleanup`, and that socket errors are reported by `WSAGetLastError`, not `GetLastError`.

This page covers **13 functions**: [`WSAStartup`](#wsastartup), [`WSACleanup`](#wsacleanup), [`socket`](#socket), [`bind`](#bind), [`listen`](#listen), [`accept`](#accept), [`connect`](#connect), [`send`](#send), [`recv`](#recv), [`closesocket`](#closesocket), [`getaddrinfo`](#getaddrinfo), [`freeaddrinfo`](#freeaddrinfo), [`ioctlsocket`](#ioctlsocket).

## Shared setup

Paste this block at the top of your source file, then one or more example functions below, then call them from `main`. The complete, compiled file is [winsock.c](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/winsock.c).

```c
/*
 * Winsock 2 examples for the NEONT 5 documentation site.
 *
 * Build with MinGW-w64 or zig cc (any Windows target):
 *     zig cc -target x86_64-windows-gnu -std=c11 -Wall -Wextra -Werror winsock.c -o winsock.exe -lws2_32
 * Build with MSVC:
 *     cl /nologo /W4 /WX winsock.c ws2_32.lib
 *
 * Every example uses the loopback address (127.0.0.1) and an ephemeral port
 * (port 0 lets the system choose), so nothing leaves the machine. The accept
 * example uses a non-blocking socket, so it returns instead of waiting.
 */
#define UNICODE
#define _UNICODE
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>

#ifdef _MSC_VER
#pragma comment(lib, "ws2_32.lib")   /* MSVC links the library from the source file */
#endif

/* Shared helper: a TCP socket bound to 127.0.0.1 on a port chosen by the system and listening. */
static SOCKET listen_on_loopback(unsigned short *port_out)
{
    struct sockaddr_in addr;
    int len = sizeof(addr);
    SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (s == INVALID_SOCKET) return INVALID_SOCKET;

    ZeroMemory(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
    if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) == SOCKET_ERROR ||
        listen(s, SOMAXCONN) == SOCKET_ERROR) {
        closesocket(s);
        return INVALID_SOCKET;
    }
    getsockname(s, (struct sockaddr *)&addr, &len);
    *port_out = ntohs(addr.sin_port);
    return s;
}
```

## Functions

## WSAStartup

The **WSAStartup** function initiates use of the Winsock DLL by a process.

| Attribute | Value |
| --- | --- |
| Header | `winsock.h` (include `Winsock2.h`) |
| Library | Ws2_32.lib (DLL `Ws2_32.dll`) |
| Minimum client | Windows 8.1, Windows Vista [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [WSAStartup function (winsock.h)](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsastartup) |
| In this tree | [`net/sockets/winsock2/ws2_32/src/startup.cpp:111`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/net/sockets/winsock2/ws2_32/src/startup.cpp#L111) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
int WSAAPI WSAStartup(
    WORD wVersionRequested,
    LPWSADATA lpWSAData
);
```

**Return value.** If successful, the **WSAStartup** function returns zero. Otherwise, it returns one of the error codes listed below. The **WSAStartup** function directly returns the extended error code in the return value for this function. A call to the [WSAGetLastError](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsagetlasterror) function is not needed and should  not be used.

**Tested example** — `example_WSAStartup` in [`winsock.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/winsock.c):

```c
static void example_WSAStartup(void)
{
    WSADATA data;
    /* Request Winsock 2.2. The call must succeed before any other socket function. */
    int rc = WSAStartup(MAKEWORD(2, 2), &data);
    if (rc == 0)
        wprintf(L"Winsock %d.%d ready\n", LOBYTE(data.wVersion), HIBYTE(data.wVersion));
    else
        wprintf(L"WSAStartup failed: %d\n", rc);   /* returns the error code directly; GetLastError is not set */
    WSACleanup();
}
```

## WSACleanup

The **WSACleanup** function terminates use of the Winsock 2 DLL (*Ws2_32.dll*).

| Attribute | Value |
| --- | --- |
| Header | `winsock.h` (include `Winsock2.h`) |
| Library | Ws2_32.lib (DLL `Ws2_32.dll`) |
| Minimum client | Windows 8.1, Windows Vista [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [WSACleanup function (winsock.h)](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsacleanup) |
| In this tree | [`net/sockets/winsock2/ws2_32/src/startup.cpp:417`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/net/sockets/winsock2/ws2_32/src/startup.cpp#L417) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
int WSAAPI WSACleanup(
    void
);
```

**Return value.** The return value is zero if the operation was successful. Otherwise, the value SOCKET_ERROR is returned, and a specific error number can be retrieved by calling [WSAGetLastError](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsagetlasterror). In a multithreaded environment, **WSACleanup** terminates Windows Sockets operations for all threads.

**Tested example** — `example_WSACleanup` in [`winsock.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/winsock.c):

```c
static void example_WSACleanup(void)
{
    WSADATA data;
    WSAStartup(MAKEWORD(2, 2), &data);
    /* Each successful WSAStartup needs one WSACleanup. */
    if (WSACleanup() == 0)
        wprintf(L"Winsock released\n");
}
```

## socket

The **socket** function creates a socket that is bound to a specific transport service provider.

| Attribute | Value |
| --- | --- |
| Header | `winsock2.h` |
| Library | Ws2_32.lib (DLL `Ws2_32.dll`) |
| Minimum client | Windows 8.1, Windows Vista [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [socket function (winsock2.h)](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-socket) |
| In this tree | [`net/sockets/winsock2/ws2_32/src/socklife.cpp:53`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/net/sockets/winsock2/ws2_32/src/socklife.cpp#L53) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
SOCKET WSAAPI socket(
    int af,
    int type,
    int protocol
);
```

**Return value.** If no error occurs, **socket** returns a descriptor referencing the new socket. Otherwise, a value of INVALID_SOCKET is returned, and a specific error code can be retrieved by calling [WSAGetLastError](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsagetlasterror). Error code Meaning **[WSANOTINITIALISED](https://learn.microsoft.com/en-us/windows/win32/WinSock/windows-sockets-error-codes-2)** A successful [WSAStartup](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsastartup) call must occur before using this function.

**Tested example** — `example_socket` in [`winsock.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/winsock.c):

```c
static void example_socket(void)
{
    WSADATA data;
    WSAStartup(MAKEWORD(2, 2), &data);
    SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (s == INVALID_SOCKET)
        wprintf(L"socket failed: %d\n", WSAGetLastError());
    else {
        wprintf(L"TCP socket created\n");
        closesocket(s);
    }
    WSACleanup();
}
```

## bind

The **bind** function associates a local address with a socket.

| Attribute | Value |
| --- | --- |
| Header | `winsock.h` (include `Winsock2.h`) |
| Library | Ws2_32.lib (DLL `Ws2_32.dll`) |
| Minimum client | Windows 8.1, Windows Vista [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [bind function (winsock.h)](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-bind) |
| In this tree | [`net/sockets/winsock2/ws2_32/src/sockctrl.cpp:50`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/net/sockets/winsock2/ws2_32/src/sockctrl.cpp#L50) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
int WSAAPI bind(
    SOCKET s,
    const struct sockaddr *name,
    int namelen
);
```

**Return value.** If no error occurs, **bind** returns zero. Otherwise, it returns SOCKET_ERROR, and a specific error code can be retrieved by calling [WSAGetLastError](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsagetlasterror). Error code Meaning **[WSANOTINITIALISED](https://learn.microsoft.com/en-us/windows/win32/WinSock/windows-sockets-error-codes-2)** **Note**  A successful [WSAStartup](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsastartup) call must occur before using this function. **[WSAENETDOWN](https://learn.microsoft.com/en-us/windows/win32/WinSock/windows-sockets-error-codes-2)** The network subsystem has failed.

**Tested example** — `example_bind` in [`winsock.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/winsock.c):

```c
static void example_bind(void)
{
    WSADATA data;
    struct sockaddr_in addr;
    WSAStartup(MAKEWORD(2, 2), &data);
    SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (s != INVALID_SOCKET) {
        ZeroMemory(&addr, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(0);                       /* 0 = pick any free port */
        inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
        if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) == 0)
            wprintf(L"Bound to 127.0.0.1 (ephemeral port)\n");
        closesocket(s);
    }
    WSACleanup();
}
```

## listen

The **listen** function places a socket in a state in which it is listening for an incoming connection.

| Attribute | Value |
| --- | --- |
| Header | `winsock2.h` |
| Library | Ws2_32.lib (DLL `Ws2_32.dll`) |
| Minimum client | Windows 8.1, Windows Vista [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [listen function (winsock2.h)](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-listen) |
| In this tree | [`net/sockets/winsock2/ws2_32/src/sockctrl.cpp:486`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/net/sockets/winsock2/ws2_32/src/sockctrl.cpp#L486) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
int WSAAPI listen(
    SOCKET s,
    int backlog
);
```

**Return value.** If no error occurs, **listen** returns zero. Otherwise, a value of **SOCKET_ERROR** is returned, and a specific error code can be retrieved by calling [WSAGetLastError](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsagetlasterror). Error code Meaning **[WSANOTINITIALISED](https://learn.microsoft.com/en-us/windows/win32/WinSock/windows-sockets-error-codes-2)** A successful [WSAStartup](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsastartup) call must occur before using this function.

**Tested example** — `example_listen` in [`winsock.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/winsock.c):

```c
static void example_listen(void)
{
    WSADATA data;
    unsigned short port = 0;
    WSAStartup(MAKEWORD(2, 2), &data);
    SOCKET s = listen_on_loopback(&port);
    if (s != INVALID_SOCKET) {
        wprintf(L"Listening on 127.0.0.1:%u\n", port);
        closesocket(s);
    }
    WSACleanup();
}
```

## accept

The **accept** function permits an incoming connection attempt on a socket.

| Attribute | Value |
| --- | --- |
| Header | `winsock2.h` |
| Library | Ws2_32.lib (DLL `Ws2_32.dll`) |
| Minimum client | Windows 8.1, Windows Vista [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [accept function (winsock2.h)](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-accept) |
| In this tree | [`net/sockets/winsock2/ws2_32/src/socklife.cpp:383`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/net/sockets/winsock2/ws2_32/src/socklife.cpp#L383) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
ifndef __WINSOCK_WS1_SHARED SOCKET WSAAPI accept(
    SOCKET s,
    struct sockaddr *addr,
    int *addrlen
);
```

**Return value.** If no error occurs, **accept** returns a value of type **SOCKET** that is a descriptor for the new socket. This returned value is a handle for the socket on which the actual connection is made. Otherwise, a value of **INVALID_SOCKET** is returned, and a specific error code can be retrieved by calling [WSAGetLastError](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsagetlasterror).

**Tested example** — `example_accept` in [`winsock.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/winsock.c):

```c
static void example_accept(void)
{
    WSADATA data;
    unsigned short port = 0;
    u_long nonBlocking = 1;
    WSAStartup(MAKEWORD(2, 2), &data);
    SOCKET server = listen_on_loopback(&port);
    if (server != INVALID_SOCKET) {
        /* Non-blocking mode: accept returns at once with WSAEWOULDBLOCK when no client is waiting. */
        ioctlsocket(server, FIONBIO, &nonBlocking);
        SOCKET client = accept(server, NULL, NULL);
        if (client == INVALID_SOCKET && WSAGetLastError() == WSAEWOULDBLOCK)
            wprintf(L"No pending connection (non-blocking accept)\n");
        else if (client != INVALID_SOCKET)
            closesocket(client);
        closesocket(server);
    }
    WSACleanup();
}
```

## connect

The **connect** function establishes a connection to a specified socket.

| Attribute | Value |
| --- | --- |
| Header | `winsock2.h` |
| Library | Ws2_32.lib (DLL `Ws2_32.dll`) |
| Minimum client | Windows Vista [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [connect function (winsock2.h)](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-connect) |
| In this tree | [`net/sockets/winsock2/ws2_32/src/sockctrl.cpp:109`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/net/sockets/winsock2/ws2_32/src/sockctrl.cpp#L109) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
int WSAAPI connect(
    SOCKET s,
    const struct sockaddr *name,
    int namelen
);
```

**Return value.** If no error occurs, **connect** returns zero. Otherwise, it returns SOCKET_ERROR, and a specific error code can be retrieved by calling [WSAGetLastError](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsagetlasterror). On a blocking socket, the return value indicates success or failure of the connection attempt.

**Tested example** — `example_connect` in [`winsock.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/winsock.c):

```c
static void example_connect(void)
{
    WSADATA data;
    unsigned short port = 0;
    struct sockaddr_in target;
    WSAStartup(MAKEWORD(2, 2), &data);
    SOCKET server = listen_on_loopback(&port);
    SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server != INVALID_SOCKET && client != INVALID_SOCKET) {
        ZeroMemory(&target, sizeof(target));
        target.sin_family = AF_INET;
        target.sin_port = htons(port);
        inet_pton(AF_INET, "127.0.0.1", &target.sin_addr);
        /* On loopback the handshake completes against the listen backlog, so this returns promptly. */
        if (connect(client, (struct sockaddr *)&target, sizeof(target)) == 0)
            wprintf(L"Connected to port %u\n", port);
        closesocket(client);
    }
    if (server != INVALID_SOCKET) closesocket(server);
    WSACleanup();
}
```

## send

The **send** function sends data on a connected socket.

| Attribute | Value |
| --- | --- |
| Header | `winsock2.h` |
| Library | Ws2_32.lib (DLL `Ws2_32.dll`) |
| Minimum client | Windows 8.1, Windows Vista [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [send function (winsock2.h)](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-send) |
| In this tree | [`net/sockets/winsock2/ws2_32/src/send.cpp:40`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/net/sockets/winsock2/ws2_32/src/send.cpp#L40) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
endif int WSAAPI send(
    SOCKET s,
    const char *buf,
    int len,
    int flags
);
```

**Return value.** If no error occurs, **send** returns the total number of bytes sent, which can be less than the number requested to be sent in the *len* parameter. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code can be retrieved by calling [WSAGetLastError](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsagetlasterror). Error code Meaning **[WSANOTINITIALISED](https://learn.microsoft.com/en-us/windows/win32/WinSock/windows-sockets-error-codes-2)** A successful [WSAStartup](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsastartup) call must occur before using this function.

**Tested example** — `example_send` in [`winsock.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/winsock.c):

```c
static void example_send(void)
{
    WSADATA data;
    unsigned short port = 0;
    struct sockaddr_in target;
    const char message[] = "ping";
    WSAStartup(MAKEWORD(2, 2), &data);
    SOCKET server = listen_on_loopback(&port);
    SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server != INVALID_SOCKET && client != INVALID_SOCKET) {
        ZeroMemory(&target, sizeof(target));
        target.sin_family = AF_INET;
        target.sin_port = htons(port);
        inet_pton(AF_INET, "127.0.0.1", &target.sin_addr);
        if (connect(client, (struct sockaddr *)&target, sizeof(target)) == 0) {
            /* send returns the number of bytes accepted by the stack, which can be less than requested. */
            int sent = send(client, message, (int)sizeof(message) - 1, 0);
            wprintf(L"Sent %d bytes\n", sent);
        }
    }
    if (client != INVALID_SOCKET) closesocket(client);
    if (server != INVALID_SOCKET) closesocket(server);
    WSACleanup();
}
```

## recv

The **recv** function receives data from a connected socket or a bound connectionless socket.

| Attribute | Value |
| --- | --- |
| Header | `winsock.h` (include `Winsock2.h`) |
| Library | Ws2_32.lib (DLL `Ws2_32.dll`) |
| Minimum client | Windows 8.1, Windows Vista [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [recv function (winsock.h)](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-recv) |
| In this tree | [`net/sockets/winsock2/ws2_32/src/recv.cpp:43`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/net/sockets/winsock2/ws2_32/src/recv.cpp#L43), [`net/sockets/winsock2/wsock32/sockopt.c:459`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/net/sockets/winsock2/wsock32/sockopt.c#L459) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
endif int WSAAPI recv(
    SOCKET s,
    char *buf,
    int len,
    int flags
);
```

**Return value.** If no error occurs, **recv** returns the number of bytes received and the buffer pointed to by the *buf* parameter will contain this data received. If the connection has been gracefully closed, the return value is zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code can be retrieved by calling [WSAGetLastError](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsagetlasterror).

**Tested example** — `example_recv` in [`winsock.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/winsock.c):

```c
static void example_recv(void)
{
    WSADATA data;
    unsigned short port = 0;
    struct sockaddr_in target;
    char buffer[32];
    int received = 0;
    WSAStartup(MAKEWORD(2, 2), &data);
    SOCKET server = listen_on_loopback(&port);
    SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server != INVALID_SOCKET && client != INVALID_SOCKET) {
        ZeroMemory(&target, sizeof(target));
        target.sin_family = AF_INET;
        target.sin_port = htons(port);
        inet_pton(AF_INET, "127.0.0.1", &target.sin_addr);
        if (connect(client, (struct sockaddr *)&target, sizeof(target)) == 0) {
            SOCKET peer = accept(server, NULL, NULL);     /* the connection is already queued */
            if (peer != INVALID_SOCKET) {
                send(client, "ping", 4, 0);
                received = recv(peer, buffer, sizeof(buffer) - 1, 0);   /* 0 = orderly close, < 0 = error */
                if (received > 0) {
                    buffer[received] = '\0';
                    wprintf(L"Received %d bytes: %S\n", received, buffer);
                }
                closesocket(peer);
            }
        }
    }
    if (client != INVALID_SOCKET) closesocket(client);
    if (server != INVALID_SOCKET) closesocket(server);
    WSACleanup();
}
```

## closesocket

The **closesocket** function closes an existing socket.

| Attribute | Value |
| --- | --- |
| Header | `winsock.h` (include `Winsock2.h`) |
| Library | Ws2_32.lib (DLL `Ws2_32.dll`) |
| Minimum client | Windows 8.1, Windows Vista [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [closesocket function (winsock.h)](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-closesocket) |
| In this tree | [`net/sockets/winsock2/ws2_32/src/socklife.cpp:1012`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/net/sockets/winsock2/ws2_32/src/socklife.cpp#L1012) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
int WSAAPI closesocket(
    SOCKET s
);
```

**Return value.** If no error occurs, **closesocket** returns zero. Otherwise, a value of **SOCKET_ERROR** is returned, and a specific error code can be retrieved by calling [WSAGetLastError](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsagetlasterror). Error code Meaning **[WSANOTINITIALISED](https://learn.microsoft.com/en-us/windows/win32/WinSock/windows-sockets-error-codes-2)** A successful [WSAStartup](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsastartup) call must occur before using this function.

**Tested example** — `example_closesocket` in [`winsock.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/winsock.c):

```c
static void example_closesocket(void)
{
    WSADATA data;
    WSAStartup(MAKEWORD(2, 2), &data);
    SOCKET s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (s != INVALID_SOCKET && closesocket(s) == 0)
        wprintf(L"UDP socket closed\n");     /* use closesocket, not CloseHandle, for SOCKET values */
    WSACleanup();
}
```

## getaddrinfo

The **getaddrinfo** function provides protocol-independent translation from an ANSI host name to an address.

| Attribute | Value |
| --- | --- |
| Header | `ws2tcpip.h` |
| Library | Ws2_32.lib (DLL `Ws2_32.dll`) |
| Minimum client | Windows XP, Windows 8.1 [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [getaddrinfo function (ws2tcpip.h)](https://learn.microsoft.com/en-us/windows/win32/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) |
| In this tree | [`net/sockets/winsock2/ws2_32/src/addrinfo.cpp:1062`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/net/sockets/winsock2/ws2_32/src/addrinfo.cpp#L1062) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
int WSAAPI getaddrinfo(
    const char *nodename,
    const char *servname,
    const struct addrinfo *hints,
    struct addrinfo **res
);
```

**Return value.** Success returns zero. Failure returns a nonzero Windows Sockets error code, as found in the [Windows Sockets Error Codes](https://learn.microsoft.com/en-us/windows/win32/WinSock/windows-sockets-error-codes-2). Most nonzero error codes returned by the **getaddrinfo** function map to the set of errors outlined by Internet Engineering Task Force (IETF) recommendations. The following table lists these error codes and their WSA equivalents. It is recommended that the WSA error codes be used, as they offer familiar and comprehensive error information for Winsock programmers.

**Tested example** — `example_getaddrinfo` in [`winsock.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/winsock.c):

```c
static void example_getaddrinfo(void)
{
    WSADATA data;
    struct addrinfo hints, *result = NULL;
    WSAStartup(MAKEWORD(2, 2), &data);
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;          /* IPv4 or IPv6 */
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    /* Resolve the loopback name; the result is a linked list you must free. */
    int rc = getaddrinfo("localhost", "80", &hints, &result);
    if (rc == 0) {
        int count = 0;
        for (struct addrinfo *p = result; p != NULL; p = p->ai_next) count++;
        wprintf(L"localhost resolved to %d address(es)\n", count);
        freeaddrinfo(result);
    } else {
        wprintf(L"getaddrinfo failed: %d\n", rc);
    }
    WSACleanup();
}
```

## freeaddrinfo

The **freeaddrinfo** function frees address information that the [getaddrinfo](https://learn.microsoft.com/en-us/windows/win32/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) function dynamically allocates in [addrinfo](https://learn.microsoft.com/en-us/windows/win32/api/ws2def/ns-ws2def-addrinfoa) structures.

| Attribute | Value |
| --- | --- |
| Header | `ws2tcpip.h` |
| Library | - |
| Minimum client | Windows 8.1, Windows Vista [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [freeaddrinfo function (ws2tcpip.h)](https://learn.microsoft.com/en-us/windows/win32/api/ws2tcpip/nf-ws2tcpip-freeaddrinfo) |
| In this tree | [`net/sockets/winsock2/ws2_32/src/addrinfo.cpp:556`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/net/sockets/winsock2/ws2_32/src/addrinfo.cpp#L556) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
void WSAAPI freeaddrinfo(
    LPADDRINFO pAddrInfo
);
```

**Return value.** This function does not return a value.

**Tested example** — `example_freeaddrinfo` in [`winsock.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/winsock.c):

```c
static void example_freeaddrinfo(void)
{
    WSADATA data;
    struct addrinfo hints, *result = NULL;
    WSAStartup(MAKEWORD(2, 2), &data);
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo("127.0.0.1", "0", &hints, &result) == 0)
        freeaddrinfo(result);             /* the list came from getaddrinfo: free it with freeaddrinfo only */
    WSACleanup();
}
```

## ioctlsocket

The **ioctlsocket** function controls the I/O mode of a socket.

| Attribute | Value |
| --- | --- |
| Header | `winsock.h` (include `Winsock2.h`) |
| Library | Ws2_32.lib (DLL `Ws2_32.dll`) |
| Minimum client | Windows 8.1, Windows Vista [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [ioctlsocket function (winsock.h)](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-ioctlsocket) |
| In this tree | [`net/sockets/winsock2/ws2_32/src/ioctl.cpp:39`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/net/sockets/winsock2/ws2_32/src/ioctl.cpp#L39) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
int WSAAPI ioctlsocket(
    SOCKET s,
    __LONG32 cmd,
    u_long *argp
);
```

**Return value.** Upon successful completion, the **ioctlsocket** returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code can be retrieved by calling [WSAGetLastError](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsagetlasterror). Error code Meaning **[WSANOTINITIALISED](https://learn.microsoft.com/en-us/windows/win32/WinSock/windows-sockets-error-codes-2)** A successful [WSAStartup](https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsastartup) call must occur before using this function.

**Tested example** — `example_ioctlsocket` in [`winsock.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/winsock.c):

```c
static void example_ioctlsocket(void)
{
    WSADATA data;
    u_long mode = 1;                      /* 1 = non-blocking, 0 = blocking */
    WSAStartup(MAKEWORD(2, 2), &data);
    SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (s != INVALID_SOCKET) {
        if (ioctlsocket(s, FIONBIO, &mode) == 0)
            wprintf(L"Socket is non-blocking\n");
        closesocket(s);
    }
    WSACleanup();
}
```

## Build and test

Compile for an x86_64 Windows target with warnings treated as errors (run it on Windows; the examples are compiled here, not executed):

```sh
zig cc -target x86_64-windows-gnu -std=c11 -Wall -Wextra -Werror winsock.c -o winsock.exe -lkernel32 -ladvapi32 -lws2_32 -luser32 -lgdi32 -lshell32
```

With MSVC from a Developer Command Prompt: `cl /nologo /W4 /WX winsock.c`. MSVC is not run in this checkout; the file is verified only with the zig/clang Windows targets.

## Frequently asked questions

### Q: Why does socket() return INVALID_SOCKET and not -1?

`SOCKET` is an unsigned pointer-sized type, so the documented failure value is `INVALID_SOCKET` (`(SOCKET)(~0)`). Compare with the constant, not with -1.

### Q: How do I read the error from a socket call?

Call `WSAGetLastError()`. `GetLastError()` is not set by Winsock functions.

### Q: Does send() send everything I pass it?

Not necessarily. It returns how many bytes were accepted, and you must loop when that is less than the length.

### Q: Where is the server side of HTTP or the kernel socket path?

The kernel socket path is AFD under `net/sockets/winsock2/wsp/afdsys` (see [Networking stack](/networking)). The HTTP server is in `inetsrv`, not in Winsock.
