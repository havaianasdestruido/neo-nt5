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

/* @fn WSAStartup */
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

/* @fn WSACleanup */
static void example_WSACleanup(void)
{
    WSADATA data;
    WSAStartup(MAKEWORD(2, 2), &data);
    /* Each successful WSAStartup needs one WSACleanup. */
    if (WSACleanup() == 0)
        wprintf(L"Winsock released\n");
}

/* @fn socket */
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

/* @fn bind */
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

/* @fn listen */
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

/* @fn accept */
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

/* @fn connect */
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

/* @fn send */
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

/* @fn recv */
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

/* @fn closesocket */
static void example_closesocket(void)
{
    WSADATA data;
    WSAStartup(MAKEWORD(2, 2), &data);
    SOCKET s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (s != INVALID_SOCKET && closesocket(s) == 0)
        wprintf(L"UDP socket closed\n");     /* use closesocket, not CloseHandle, for SOCKET values */
    WSACleanup();
}

/* @fn getaddrinfo */
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

/* @fn freeaddrinfo */
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

/* @fn ioctlsocket */
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

int main(void)
{
    example_WSAStartup();
    example_WSACleanup();
    example_socket();
    example_bind();
    example_listen();
    example_accept();
    example_connect();
    example_send();
    example_recv();
    example_closesocket();
    example_getaddrinfo();
    example_freeaddrinfo();
    example_ioctlsocket();
    return 0;
}
