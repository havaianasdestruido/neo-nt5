---
title: "Registry"
sidebar_position: 17
description: "RegCreateKeyExW, RegOpenKeyExW, value queries and deletion: official signatures, the base/screg implementation and compiled examples that clean up after themselves."
---

# Registry

The registry API is a client of the configuration manager in `base/screg` (the Win32 client wrappers) and `base/ntos/config` (the kernel hive code). Every `Reg*` function in this table has a `W` (UTF-16) form; `A` forms convert and call the `W` form.

The examples write only under `HKEY_CURRENT_USER\Software\NEONT5Docs` and delete it again, so they run without administrator rights.

This page covers **8 functions**: [`RegCreateKeyExW`](#regcreatekeyexw), [`RegOpenKeyExW`](#regopenkeyexw), [`RegQueryValueExW`](#regqueryvalueexw), [`RegSetValueExW`](#regsetvalueexw), [`RegEnumKeyExW`](#regenumkeyexw), [`RegDeleteValueW`](#regdeletevaluew), [`RegDeleteKeyW`](#regdeletekeyw), [`RegCloseKey`](#regclosekey).

## Shared setup

Paste this block at the top of your source file, then one or more example functions below, then call them from `main`. The complete, compiled file is [registry.c](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/registry.c).

```c
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
```

## Functions

## RegCreateKeyExW

Creates the specified registry key. If the key already exists, the function opens it. Note that key names are not case sensitive. To perform transacted registry operations on a key, call the [RegCreateKeyTransacted](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regcreatekeytransacteda) function.

| Attribute | Value |
| --- | --- |
| Header | `winreg.h` (include `Windows.h`) |
| Library | Advapi32.lib (DLL `Advapi32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps only] |
| Minimum server | Windows 2000 Server [desktop apps only] |
| Character set | RegCreateKeyExW (Unicode) and RegCreateKeyExA (ANSI) |
| Official reference | [RegCreateKeyExW function (winreg.h)](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regcreatekeyexw) |
| In this tree | [`base/screg/winreg/client/regkey.c:488`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/screg/winreg/client/regkey.c#L488) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
LONG WINAPI RegCreateKeyExW(
    HKEY hKey,
    LPCWSTR lpSubKey,
    DWORD Reserved,
    LPWSTR lpClass,
    DWORD dwOptions,
    REGSAM samDesired,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    PHKEY phkResult,
    LPDWORD lpdwDisposition
);
```

**Return value.** If the function succeeds, the return value is ERROR_SUCCESS. If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

**Tested example** — `example_RegCreateKeyExW` in [`registry.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/registry.c):

```c
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
```

## RegOpenKeyExW

Opens the specified registry key. Note that key names are not case sensitive. To perform transacted registry operations on a key, call the [RegOpenKeyTransacted](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regopenkeytransacteda) function.

| Attribute | Value |
| --- | --- |
| Header | `winreg.h` (include `Windows.h`) |
| Library | Advapi32.lib (DLL `Advapi32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps only] |
| Minimum server | Windows 2000 Server [desktop apps only] |
| Character set | RegOpenKeyExW (Unicode) and RegOpenKeyExA (ANSI) |
| Official reference | [RegOpenKeyExW function (winreg.h)](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regopenkeyexw) |
| In this tree | [`base/screg/winreg/client/regkey.c:1092`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/screg/winreg/client/regkey.c#L1092) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
LONG WINAPI RegOpenKeyExW(
    HKEY hKey,
    LPCWSTR lpSubKey,
    DWORD ulOptions,
    REGSAM samDesired,
    PHKEY phkResult
);
```

**Return value.** If the function succeeds, the return value is ERROR_SUCCESS. If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

**Tested example** — `example_RegOpenKeyExW` in [`registry.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/registry.c):

```c
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
```

## RegQueryValueExW

Retrieves the type and data for the specified value name associated with an open registry key. > [!WARNING] > If the value being queried is a string (REG_SZ, REG_MULTI_SZ, and REG_EXPAND_SZ) the value returned is NOT guaranteed to be null-terminated. Use the [RegGetValue](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-reggetvaluea) function if you want to ensure returned string values are null-terminated. More information is in the remarks below.

| Attribute | Value |
| --- | --- |
| Header | `winreg.h` (include `Windows.h`) |
| Library | Advapi32.lib (DLL `Advapi32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps only] |
| Minimum server | Windows 2000 Server [desktop apps only] |
| Character set | RegQueryValueExW (Unicode) and RegQueryValueExA (ANSI) |
| Official reference | [RegQueryValueExW function (winreg.h)](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regqueryvalueexw) |
| In this tree | [`base/screg/winreg/client/regqval.c:687`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/screg/winreg/client/regqval.c#L687) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
LONG WINAPI RegQueryValueExW(
    HKEY hKey,
    LPCWSTR lpValueName,
    LPDWORD lpReserved,
    LPDWORD lpType,
    LPBYTE lpData,
    LPDWORD lpcbData
);
```

**Return value.** If the function succeeds, the return value is ERROR_SUCCESS. If the function fails, the return value is a [system error code](https://learn.microsoft.com/en-us/windows/win32/Debug/system-error-codes).

**Tested example** — `example_RegQueryValueExW` in [`registry.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/registry.c):

```c
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
```

## RegSetValueExW

Sets the data and type of a specified value under a registry key.

| Attribute | Value |
| --- | --- |
| Header | `winreg.h` (include `Windows.h`) |
| Library | Advapi32.lib (DLL `Advapi32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps only] |
| Minimum server | Windows 2000 Server [desktop apps only] |
| Character set | RegSetValueExW (Unicode) and RegSetValueExA (ANSI) |
| Official reference | [RegSetValueExW function (winreg.h)](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regsetvalueexw) |
| In this tree | [`base/screg/winreg/client/regsval.c:496`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/screg/winreg/client/regsval.c#L496) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
LONG WINAPI RegSetValueExW(
    HKEY hKey,
    LPCWSTR lpValueName,
    DWORD Reserved,
    DWORD dwType,
    CONST BYTE *lpData,
    DWORD cbData
);
```

**Return value.** If the function succeeds, the return value is ERROR_SUCCESS. If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

**Tested example** — `example_RegSetValueExW` in [`registry.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/registry.c):

```c
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
```

## RegEnumKeyExW

Enumerates the subkeys of the specified open registry key. The function retrieves information about one subkey each time it is called.

| Attribute | Value |
| --- | --- |
| Header | `winreg.h` (include `Windows.h`) |
| Library | Advapi32.lib (DLL `Advapi32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps only] |
| Minimum server | Windows 2000 Server [desktop apps only] |
| Character set | RegEnumKeyExW (Unicode) and RegEnumKeyExA (ANSI) |
| Official reference | [RegEnumKeyExW function (winreg.h)](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regenumkeyexw) |
| In this tree | [`base/screg/winreg/client/regekey.c:338`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/screg/winreg/client/regekey.c#L338) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
LONG WINAPI RegEnumKeyExW(
    HKEY hKey,
    DWORD dwIndex,
    LPWSTR lpName,
    LPDWORD lpcchName,
    LPDWORD lpReserved,
    LPWSTR lpClass,
    LPDWORD lpcchClass,
    PFILETIME lpftLastWriteTime
);
```

**Return value.** If the function succeeds, the return value is ERROR_SUCCESS. If the function fails, the return value is a [system error code](https://learn.microsoft.com/en-us/windows/win32/Debug/system-error-codes). If there are no more subkeys available, the function returns ERROR_NO_MORE_ITEMS.

**Tested example** — `example_RegEnumKeyExW` in [`registry.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/registry.c):

```c
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
```

## RegDeleteValueW

Removes a named value from the specified registry key. Note that value names are not case sensitive.

| Attribute | Value |
| --- | --- |
| Header | `winreg.h` (include `Windows.h`) |
| Library | Advapi32.lib (DLL `Advapi32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps only] |
| Minimum server | Windows 2000 Server [desktop apps only] |
| Character set | RegDeleteValueW (Unicode) and RegDeleteValueA (ANSI) |
| Official reference | [RegDeleteValueW function (winreg.h)](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regdeletevaluew) |
| In this tree | [`base/screg/winreg/client/regdval.c:132`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/screg/winreg/client/regdval.c#L132) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
LONG WINAPI RegDeleteValueW(
    HKEY hKey,
    LPCWSTR lpValueName
);
```

**Return value.** If the function succeeds, the return value is ERROR_SUCCESS. If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

**Tested example** — `example_RegDeleteValueW` in [`registry.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/registry.c):

```c
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
```

## RegDeleteKeyW

Deletes a subkey and its values. Note that key names are not case sensitive. **64-bit Windows:  **On WOW64, 32-bit applications view a registry tree that is separate from the registry tree that 64-bit applications view. To enable an application to delete an entry in the alternate registry view, use the [RegDeleteKeyEx](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regdeletekeyexa) function.

| Attribute | Value |
| --- | --- |
| Header | `winreg.h` (include `Windows.h`) |
| Library | Advapi32.lib (DLL `Advapi32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps only] |
| Minimum server | Windows 2000 Server [desktop apps only] |
| Character set | RegDeleteKeyW (Unicode) and RegDeleteKeyA (ANSI) |
| Official reference | [RegDeleteKeyW function (winreg.h)](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regdeletekeyw) |
| In this tree | [`base/screg/winreg/client/regdkey.c:122`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/screg/winreg/client/regdkey.c#L122) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
LONG WINAPI RegDeleteKeyW(
    HKEY hKey,
    LPCWSTR lpSubKey
);
```

**Return value.** If the function succeeds, the return value is ERROR_SUCCESS. If the function fails, the return value is a nonzero error code defined in Winerror.h. To get a generic description of the error, you can use the [FormatMessage](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag.

**Tested example** — `example_RegDeleteKeyW` in [`registry.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/registry.c):

```c
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
```

## RegCloseKey

Closes a handle to the specified registry key.

| Attribute | Value |
| --- | --- |
| Header | `winreg.h` (include `Windows.h`) |
| Library | Advapi32.lib (DLL `Advapi32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps only] |
| Minimum server | Windows 2000 Server [desktop apps only] |
| Character set | - |
| Official reference | [RegCloseKey function (winreg.h)](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regclosekey) |
| In this tree | [`base/screg/winreg/client/regkey.c:51`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/screg/winreg/client/regkey.c#L51) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
NTDDI_WIN10_19H1 LONG WINAPI RegCloseKey(
    HKEY hKey
);
```

**Return value.** If the function succeeds, the return value is ERROR_SUCCESS. If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

**Tested example** — `example_RegCloseKey` in [`registry.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/registry.c):

```c
static void example_RegCloseKey(void)
{
    HKEY key = NULL;
    /* Every successful Reg*Open/Create call needs exactly one RegCloseKey. */
    if (RegOpenKeyExW(HKEY_CURRENT_USER, L"Software", 0, KEY_READ, &key) == ERROR_SUCCESS)
        RegCloseKey(key);
}
```

## Build and test

Compile for an x86_64 Windows target with warnings treated as errors (run it on Windows; the examples are compiled here, not executed):

```sh
zig cc -target x86_64-windows-gnu -std=c11 -Wall -Wextra -Werror registry.c -o registry.exe -lkernel32 -ladvapi32 -lws2_32 -luser32 -lgdi32 -lshell32
```

With MSVC from a Developer Command Prompt: `cl /nologo /W4 /WX registry.c`. MSVC is not run in this checkout; the file is verified only with the zig/clang Windows targets.

## Frequently asked questions

### Q: Why does RegQueryValueExW return ERROR_MORE_DATA?

The buffer was too small for the value. Query with a NULL data pointer to learn the size first, or allocate the size reported in `cbData`.

### Q: Is RegDeleteKeyW recursive?

No. It deletes only a key without subkeys. Enumerate and delete children first, as `example_RegEnumKeyExW` does.

### Q: How big can a registry value be?

The official page [Registry Element Size Limits](https://learn.microsoft.com/en-us/windows/win32/sysinfo/registry-element-size-limits) lists the limits for key names, value names and value data. Store large data in a file and keep a path in the registry.

### Q: Where is the client implementation?

`base/screg/winreg/client/regkey.c` (for example `RegOpenKeyExW` at line 1092 in this revision). The kernel side is under `base/ntos/config`.
