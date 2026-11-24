/*
 * Win32 registry examples for the NEONT 5 documentation site.
 *
 * All examples write only under HKEY_CURRENT_USER\Software\NEONT5Docs and remove
 * that key again, so they need no administrator rights and leave nothing behind.
 *
 * Build with MinGW-w64 or zig cc (any Windows target):
 *     zig cc -target x86_64-windows-gnu -std=c11 -Wall -Wextra -Werror registry.c -o registry.exe -ladvapi32
 * Build with MSVC:
 *     cl /nologo /W4 /WX registry.c advapi32.lib
 */
#define UNICODE
#define _UNICODE
#include <windows.h>
#include <stdio.h>
#include <wchar.h>

#define DEMO_KEY L"Software\\NEONT5Docs"

/* Shared helper: remove the demo key tree if it exists (ignores "not found"). */
static void cleanup_demo_key(void)
{
    HKEY parent = NULL;
    if (RegOpenKeyExW(HKEY_CURRENT_USER, L"Software", 0, KEY_WRITE, &parent) == ERROR_SUCCESS) {
        RegDeleteKeyW(parent, L"NEONT5Docs");   /* fails if subkeys exist; the demo creates none */
        RegCloseKey(parent);
    }
}

/* @fn RegCreateKeyExW */
static void example_RegCreateKeyExW(void)
{
    HKEY key = NULL;
    DWORD disposition = 0;
    LSTATUS rc = RegCreateKeyExW(HKEY_CURRENT_USER, DEMO_KEY, 0, NULL, REG_OPTION_NON_VOLATILE,
                                 KEY_READ | KEY_WRITE, NULL, &key, &disposition);
    if (rc != ERROR_SUCCESS) {
        wprintf(L"RegCreateKeyExW failed: %ld\n", rc);
        return;
    }
    /* REG_CREATED_NEW_KEY or REG_OPENED_EXISTING_KEY */
    wprintf(L"Key %ls\n", disposition == REG_CREATED_NEW_KEY ? L"created" : L"already existed");
    RegCloseKey(key);
}

/* @fn RegOpenKeyExW */
static void example_RegOpenKeyExW(void)
{
    HKEY key = NULL;
    /* Open for reading only; the key must already exist. */
    LSTATUS rc = RegOpenKeyExW(HKEY_CURRENT_USER, L"Software", 0, KEY_READ, &key);
    if (rc == ERROR_SUCCESS) {
        wprintf(L"Opened HKCU\\Software\n");
        RegCloseKey(key);
    }
}

/* @fn RegQueryValueExW */
static void example_RegQueryValueExW(void)
{
    HKEY key = NULL;
    DWORD type = 0, size = 0;
    wchar_t value[64] = L"";
    DWORD dwordValue = 0;

    if (RegCreateKeyExW(HKEY_CURRENT_USER, DEMO_KEY, 0, NULL, 0, KEY_READ | KEY_WRITE, NULL, &key, NULL) != ERROR_SUCCESS)
        return;
    DWORD seed = 42;
    RegSetValueExW(key, L"Greeting", 0, REG_SZ, (const BYTE *)L"hello", 6 * sizeof(wchar_t));
    RegSetValueExW(key, L"Count", 0, REG_DWORD, (const BYTE *)&seed, sizeof(DWORD));

    /* First call with NULL data to learn the size, then read. */
    size = sizeof(value);
    if (RegQueryValueExW(key, L"Greeting", NULL, &type, (LPBYTE)value, &size) == ERROR_SUCCESS && type == REG_SZ)
        wprintf(L"Greeting = %ls\n", value);

    size = sizeof(dwordValue);
    if (RegQueryValueExW(key, L"Count", NULL, &type, (LPBYTE)&dwordValue, &size) == ERROR_SUCCESS)
        wprintf(L"Count = %lu\n", dwordValue);

    RegCloseKey(key);
    cleanup_demo_key();
}

/* @fn RegSetValueExW */
static void example_RegSetValueExW(void)
{
    HKEY key = NULL;
    const wchar_t path[] = L"C:\\NEONT5\\Logs";
    if (RegCreateKeyExW(HKEY_CURRENT_USER, DEMO_KEY, 0, NULL, 0, KEY_WRITE, NULL, &key, NULL) != ERROR_SUCCESS)
        return;
    /* REG_SZ data must include the terminating NUL in cbData (bytes, not characters). */
    LSTATUS rc = RegSetValueExW(key, L"LogPath", 0, REG_SZ, (const BYTE *)path, (DWORD)((wcslen(path) + 1) * sizeof(wchar_t)));
    wprintf(L"RegSetValueExW: %ls\n", rc == ERROR_SUCCESS ? L"ok" : L"failed");
    RegCloseKey(key);
    cleanup_demo_key();
}

/* @fn RegEnumKeyExW */
static void example_RegEnumKeyExW(void)
{
    HKEY parent = NULL;
    wchar_t name[256];
    DWORD index = 0;

    if (RegCreateKeyExW(HKEY_CURRENT_USER, DEMO_KEY L"\\Child1", 0, NULL, 0, KEY_WRITE, NULL, &parent, NULL) == ERROR_SUCCESS)
        RegCloseKey(parent);
    if (RegOpenKeyExW(HKEY_CURRENT_USER, DEMO_KEY, 0, KEY_READ, &parent) != ERROR_SUCCESS)
        return;

    /* Enumerate until ERROR_NO_MORE_ITEMS. nameLen is in characters and is reset on every call. */
    for (;;) {
        DWORD nameLen = (DWORD)(sizeof(name) / sizeof(name[0]));
        LSTATUS rc = RegEnumKeyExW(parent, index, name, &nameLen, NULL, NULL, NULL, NULL);
        if (rc == ERROR_NO_MORE_ITEMS) break;
        if (rc == ERROR_SUCCESS) wprintf(L"Subkey: %ls\n", name);
        index++;
    }
    RegCloseKey(parent);

    /* RegDeleteKeyW removes only leaf keys, so remove the child first. */
    if (RegOpenKeyExW(HKEY_CURRENT_USER, DEMO_KEY, 0, KEY_WRITE, &parent) == ERROR_SUCCESS) {
        RegDeleteKeyW(parent, L"Child1");
        RegCloseKey(parent);
    }
    cleanup_demo_key();
}

/* @fn RegDeleteValueW */
static void example_RegDeleteValueW(void)
{
    HKEY key = NULL;
    if (RegCreateKeyExW(HKEY_CURRENT_USER, DEMO_KEY, 0, NULL, 0, KEY_READ | KEY_WRITE, NULL, &key, NULL) != ERROR_SUCCESS)
        return;
    DWORD one = 1;
    RegSetValueExW(key, L"Temporary", 0, REG_DWORD, (const BYTE *)&one, sizeof(DWORD));
    if (RegDeleteValueW(key, L"Temporary") == ERROR_SUCCESS)
        wprintf(L"Value deleted\n");
    RegCloseKey(key);
    cleanup_demo_key();
}

/* @fn RegDeleteKeyW */
static void example_RegDeleteKeyW(void)
{
    HKEY key = NULL;
    /* Create a leaf key, then delete it from its parent. */
    if (RegCreateKeyExW(HKEY_CURRENT_USER, DEMO_KEY L"\\Leaf", 0, NULL, 0, KEY_WRITE, NULL, &key, NULL) == ERROR_SUCCESS)
        RegCloseKey(key);
    if (RegOpenKeyExW(HKEY_CURRENT_USER, DEMO_KEY, 0, KEY_WRITE, &key) == ERROR_SUCCESS) {
        if (RegDeleteKeyW(key, L"Leaf") == ERROR_SUCCESS)
            wprintf(L"Leaf key deleted\n");
        RegCloseKey(key);
    }
    cleanup_demo_key();
}

/* @fn RegCloseKey */
static void example_RegCloseKey(void)
{
    HKEY key = NULL;
    /* Every successful Reg*Open/Create call needs exactly one RegCloseKey. */
    if (RegOpenKeyExW(HKEY_CURRENT_USER, L"Software", 0, KEY_READ, &key) == ERROR_SUCCESS)
        RegCloseKey(key);
}

int main(void)
{
    example_RegCreateKeyExW();
    example_RegOpenKeyExW();
    example_RegQueryValueExW();
    example_RegSetValueExW();
    example_RegEnumKeyExW();
    example_RegDeleteValueW();
    example_RegDeleteKeyW();
    example_RegCloseKey();
    return 0;
}
