---
title: Registry — structure, API and implementation
sidebar_position: 26
description: Hives, keys, values and cells; the Reg* API and its native services; where base/ntos/config and base/screg/winreg implement each layer; examples and debugging.
---

The registry is a hierarchical database of **keys** and **values**, stored in **hives** and exposed
through three layers: the kernel configuration manager (`base/ntos/config`), the user-mode client
(`base/screg/winreg/client`), and the `Reg*` exports of advapi32.

```text
RegOpenKeyExW / RegQueryValueExW          (advapi32)
        |
        v
base/screg/winreg/client/regkey.c         (path building, error mapping)
        |
        v
NtOpenKey / NtQueryValueKey               (base/ntos/config/ntapi.c)
        |
        v
configuration manager: hives, cells, indexes, notify
        |
        v
hive files: SOFTWARE, SYSTEM, SAM, SECURITY, NTUSER.DAT, UsrClass.dat
```

## The object model

| Object | What it is | Lifetime |
| --- | --- | --- |
| **Key** | A node in a hierarchy; has a name, a class, a security descriptor, a last-write time | Until deleted or hive unloaded |
| **Value** | A named piece of data under a key; has a type and a byte blob | Until deleted |
| **Hive** | A file-backed or memory-backed container of keys | Loaded at boot or by `RegLoadKey` |
| **Cell** | The allocation unit inside a hive; a key, a value, or data | Managed by the hive allocator |
| **Symbolic link** | A key that resolves to another key (`\Registry\Machine\...`) | Permanent |

A key can have subkeys and values. A value cannot have children. Key names are case-insensitive and
may contain backslashes as separators only; a key name itself cannot contain a backslash.

## Hives

| Hive | File | Root | Contents |
| --- | --- | --- | --- |
| `HKLM\SOFTWARE` | `SOFTWARE` | `\Registry\Machine\Software` | Application settings, classes |
| `HKLM\SYSTEM` | `SYSTEM` | `\Registry\Machine\System` | Services, drivers, control sets |
| `HKLM\SAM` | `SAM` | `\Registry\Machine\SAM` | Local account database |
| `HKLM\SECURITY` | `SECURITY` | `\Registry\Machine\Security` | Policy, secrets |
| `HKLM\HARDWARE` | (volatile) | `\Registry\Machine\Hardware` | Detected hardware |
| `HKCU` | `NTUSER.DAT` | `\Registry\User\<SID>` | Per-user settings |
| `HKU` | `NTUSER.DAT` + `UsrClass.dat` | `\Registry\User` | Loaded user hives |
| `HKCC` | (volatile) | `\Registry\Machine\System\CurrentControlSet\Hardware Profiles\Current` | Hardware profile |

The kernel loads `SYSTEM`, `SOFTWARE`, `SAM` and `SECURITY` at boot from `%SystemRoot%\System32\config`
and the `HKLM\SYSTEM\CurrentControlSet\Control\hivelist` values. `cmboot.c` performs the boot load;
`cmsavres.c` handles save/restore; `cmhvlist.c` manages the hive list.

## The native services

`base/ntos/config/ntapi.c` is the syscall surface:

| Service | Implementation | Purpose |
| --- | --- | --- |
| `NtCreateKey` | `ntapi.c:221` | Create or open a key |
| `NtOpenKey` | `ntapi.c:2080` | Open a key |
| `NtQueryKey` | `ntapi.c:2239` | Query key metadata |
| `NtEnumerateKey` | `ntapi.c:718` | Enumerate subkeys by index |
| `NtQueryValueKey` | `ntapi.c:2422` | Read a value |
| `NtSetValueKey` | `ntapi.c:3039` | Write a value |
| `NtDeleteKey` | `ntapi.c:487` | Delete a key |
| `NtDeleteValueKey` | `ntapi.c` | Delete a value |
| `NtNotifyChangeKey` | `ntapi.c` | Watch a key |
| `NtQueryMultipleValueKey` | `ntapi.c` | Read several values at once |
| `NtFlushKey` | `ntapi.c` | Flush a hive |
| `NtCompactKeys` | `ntapi.c` | Compact a hive |
| `NtLoadKey` / `NtUnloadKey` | `ntapi.c` | Load/unload a hive |

`NtCreateKey`'s signature:

```c
NtCreateKey(
    OUT PHANDLE KeyHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes,
    IN ULONG TitleIndex OPTIONAL,
    IN PUNICODE_STRING Class OPTIONAL,
    IN ULONG CreateOptions,
    OUT PULONG Disposition OPTIONAL
    )
```

`CreateOptions` includes `REG_OPTION_VOLATILE` (do not persist the key to disk),
`REG_OPTION_NON_VOLATILE`, and `REG_OPTION_BACKUP_RESTORE` (open for backup/restore, bypassing
access checks). `Disposition` returns `REG_CREATED_NEW_KEY` or `REG_OPENED_EXISTING_KEY`.

### Information classes for `NtQueryValueKey`

| Class | Structure | Use |
| --- | --- | --- |
| `KeyValueBasicInformation` | `KEY_VALUE_BASIC_INFORMATION` | Type only |
| `KeyValueFullInformation` | `KEY_VALUE_FULL_INFORMATION` | Type plus data inline |
| `KeyValuePartialInformation` | `KEY_VALUE_PARTIAL_INFORMATION` | Type plus data, with a separate name buffer |
| `KeyValueFullInformationAlign64` | aligned variant | 64-bit alignment |
| `KeyValuePartialInformationAlign64` | aligned variant | 64-bit alignment |

The Win32 wrapper uses `KeyValuePartialInformation` and builds the `REG_*` type and byte count from
it. `RegQueryValueExW` is at `base/screg/winreg/client/regqval.c:689`.

## The user-mode API

`base/screg/winreg/client` is the client implementation, linked into advapi32 as `winreg.lib`. The
files map to the API families:

| File | Family |
| --- | --- |
| `regkey.c` | `RegOpenKeyEx`, `RegCreateKeyEx`, `RegCloseKey`, `RegFlushKey` |
| `regqval.c` | `RegQueryValueEx` |
| `regsval.c` | `RegSetValueEx` |
| `regekey.c` | `RegEnumKeyEx` |
| `regeval.c` | `RegEnumValue` |
| `regqkey.c` | `RegQueryInfoKey` |
| `regdkey.c` | `RegDeleteKey` |
| `regdval.c` | `RegDeleteValue` |
| `regcnreg.c` | `RegConnectRegistry` |
| `reglukey.c` | `RegLoadKey`, `RegUnLoadKey` |
| `regsrkey.c` | `RegSaveKey`, `RegRestoreKey` |
| `regnckey.c` | `RegNotifyChangeKeyValue` |
| `predefh.c` | Predefined key mapping |

The full function table with documentation links is on
[ADVAPI32](/advapi32-api#registry).

## Example: enumerate a key recursively

```c
#include <windows.h>
#include <stdio.h>

static void WalkKey(HKEY hRoot, const wchar_t *path, int depth)
{
    HKEY hKey = NULL;
    LONG rc = RegOpenKeyExW(hRoot, path, 0, KEY_READ, &hKey);
    if (rc != ERROR_SUCCESS) return;

    DWORD subKeys = 0, maxSubKeyLen = 0, values = 0, maxValueName = 0;
    RegQueryInfoKeyW(hKey, NULL, NULL, NULL, &subKeys, &maxSubKeyLen, NULL,
                     &values, &maxValueName, NULL, NULL, NULL);

    wchar_t *name = (wchar_t *)malloc((maxSubKeyLen + 1) * sizeof(wchar_t));
    for (DWORD i = 0; i < subKeys; i++) {
        DWORD len = maxSubKeyLen + 1;
        if (RegEnumKeyExW(hKey, i, name, &len, NULL, NULL, NULL, NULL) == ERROR_SUCCESS) {
            wprintf(L"%*ls%ls\n", depth * 2, L"", name);
            // recurse: build the full path and call WalkKey again
        }
    }
    free(name);
    RegCloseKey(hKey);
}

int wmain(void)
{
    WalkKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion", 0);
    return 0;
}
```

The size-query-then-allocate pattern is required: `RegQueryInfoKeyW` returns the maximum lengths,
and `RegEnumKeyExW` needs a buffer that large.

## Example: watch a key

```c
HANDLE hEvent = CreateEventW(NULL, FALSE, FALSE, NULL);
HKEY hKey = NULL;
RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
              0, KEY_NOTIFY, &hKey);

RegNotifyChangeKeyValue(hKey, TRUE, REG_NOTIFY_CHANGE_LAST_SET, hEvent, TRUE);

if (WaitForSingleObject(hEvent, INFINITE) == WAIT_OBJECT_0) {
    // Something under the key changed.
}
RegCloseKey(hKey);
CloseHandle(hEvent);
```

`bWatchSubtree = TRUE` watches the whole subtree. The notification is **one-shot**: after it fires,
you must call `RegNotifyChangeKeyValue` again to watch for the next change.

## Hive internals

A hive is a sequence of **bins** (`HBIN`), each 4 KiB aligned, containing **cells** (`HCELL`). A cell
is a typed allocation: a key node (`CM_KEY_NODE`), a value (`CM_KEY_VALUE`), a security descriptor,
or index data. The hive header (`HHIVE` / `_HIVE`) records the root cell, the free cell list, the
sequence number and the dirty vector.

The tree's implementation is in `base/ntos/config`:

| File | Responsibility |
| --- | --- |
| `cminit.c` | Hive initialisation, hive allocator |
| `cmalloc.c` | Cell allocation and coalescing |
| `cmindex.c` | Key and value indexes |
| `cmname.c` | Name comparison and hashing |
| `cmparse.c`, `cmparse2.c` | Path parsing |
| `cmquery.c` | Query information classes |
| `cmdelete.c` | Key/value deletion |
| `cmdelay.c` | Delayed close and lazy write |
| `cmnotify.c` | Change notification |
| `cmsavres.c` | Save/restore |
| `cmse.c` | Security descriptors |
| `cmboot.c` | Boot-time hive loading |
| `cmhvlist.c` | Hive list management |
| `cmkd` | Kernel debugger extensions |

`base/ntos/config/chkreg` is a separate checker that walks a hive file and validates its structure —
the source of the `chkreg` tool, useful for diagnosing a corrupt hive.

## Symbolic links and `HKCR`

`HKEY_CLASSES_ROOT` is a merged view of `HKLM\Software\Classes` and `HKCU\Software\Classes`. The
merge is implemented in the client (`regclass.c`), not in the kernel: the kernel sees two separate
hives, and the client combines them. A write under `HKCR` goes to `HKCU\Software\Classes` if the
user is not an administrator, and to `HKLM\Software\Classes` otherwise.

Registry symbolic links are `REG_LINK` values that the configuration manager resolves during name
lookup. `\Registry\Machine\System\CurrentControlSet` is a symbolic link to one of `ControlSet001`,
`ControlSet002`, ... chosen at boot.

## Debugging

| Tool | Purpose |
| --- | --- |
| `regedit`, `regedt32` | Interactive editing (`base/fs/utils/regedit`, `regedt32`) |
| `reg.exe` | Command-line queries (`base/fs/utils/reg`) |
| `regdmp`, `regbin` | Hive dump (`base/ntos/config/chkreg`) |
| `!reg` debugger extension | Kernel registry state |
| `regmon` / `diskmon` | Registry/file activity (historical tools) |
| `RegNotifyChangeKeyValue` | Programmatic watch |

A common diagnostic: if a value is "not there" for a 32-bit application on 64-bit Windows, check
registry redirection. `WOW6432Node` is the redirected view for 32-bit processes; `KEY_WOW64_64KEY`
opens the 64-bit view and `KEY_WOW64_32KEY` opens the 32-bit view. The redirection is implemented in
`base/screg/winreg` and `wow64reg.lib`.

## Frequently asked questions

### Q: Why is `RegOpenKeyExW` not in `base/win32/client`?

Because the registry client is its own project, `base/screg/winreg/client`, linked into advapi32 as
`winreg.lib`. `mergedcomponents/advapi32/sources` lists `$(BASE_LIB_PATH)\winreg.lib` in
`LINKLIBS`. That is also why `RegOpenKeyExW` is not a kernel32 export.

### Q: What is the difference between `HKEY_CURRENT_USER` and `HKEY_USERS\<SID>`?

`HKEY_CURRENT_USER` is a predefined handle that maps to `HKEY_USERS\<current user SID>`. It is a
convenience alias, implemented in `predefh.c`. The underlying key is the same.

### Q: Why does `RegQueryValueExW` need two calls?

Because the value size is not known in advance and the API does not return it without a buffer.
Call once with `NULL` to get the size, then again with a buffer. Handle
`ERROR_MORE_DATA` if the value can grow between calls.

### Q: Why does `RegEnumKeyExW` fail with `ERROR_MORE_DATA` after I allocated the buffer?

Because `RegQueryInfoKeyW` returns the **maximum** subkey length, but `RegEnumKeyExW` also writes a
class string. Reset the length before every call — the API overwrites it with the actual length, so
leaving it at the previous value causes the next call to fail.

### Q: What is `REG_OPTION_VOLATILE`?

A key created with `REG_OPTION_VOLATILE` is kept only in memory and is not written to the hive
file. It disappears when the hive is unloaded or the system reboots. `HKLM\HARDWARE` is the
canonical volatile hive.

### Q: How do I read a `REG_MULTI_SZ`?

```c
// buffer is REG_MULTI_SZ: A\0B\0C\0\0
for (const wchar_t *p = (const wchar_t *)buffer; *p; p += wcslen(p) + 1) {
    // p is one string
}
```

The list is terminated by an extra null after the last string. If the buffer is not
double-null-terminated, the loop runs off the end.

### Q: Why does a 32-bit application see different registry keys?

Because of registry redirection. 32-bit processes see `WOW6432Node` for `HKLM\SOFTWARE` and a
different `HKCU\Software\Classes` view. Use `KEY_WOW64_64KEY` or `KEY_WOW64_32KEY` to open the other
view explicitly. The redirection lives in `base/screg/winreg` and `wow64reg.lib`.

### Q: Where is the registry security check performed?

In the configuration manager, `cmse.c` and the object manager. A key has a security descriptor;
`NtOpenKey` calls `SeAccessCheck` against the caller's token and the requested access. The user-mode
`RegOpenKeyExW` just passes the access mask through.

### Q: How large can a registry value be?

`REG_VALUE` data is limited by the cell size, which is limited by the hive; the practical limit is
a few megabytes, and the documented limit is 1 MB for `REG_SZ`/`REG_BINARY` in some contexts. Storing
large blobs in the registry is an anti-pattern: it slows hive loading and makes the hive
unfragmentable.

### Q: Can I load a hive file and edit it offline?

Yes: `RegLoadKeyW` with `REG_OPTION_BACKUP_RESTORE`, or `reg load` from `reg.exe`. The hive must be
unloaded when done (`RegUnLoadKeyW`). `base/ntos/config/chkreg` can validate the file before you
load it.
