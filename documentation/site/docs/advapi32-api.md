---
title: ADVAPI32 — registry, services, event log, security and crypto
sidebar_position: 19
description: The registry API, the service control manager, the event log, token and privilege APIs and CryptoAPI — with the implementation points in base/screg, base/eventlog, mergedcomponents/advapi32 and ds/security.
---

`advapi32.dll` is not one subsystem. It is a **merged component** that pulls five independent
implementations into one DLL. `mergedcomponents/advapi32/sources` shows the shape:

```bat
TARGETNAME=advapi32
TARGETTYPE=DYNLINK

LINKLIBS=  \
    $(BASE_LIB_PATH)\winreg.lib \        # registry client
    $(BASE_LIB_PATH)\svcctrl.lib \       # service control manager client
    $(SDK_LIB_PATH)\elfapi.lib \         # event log client
    $(DS_LIB_PATH)\rsa32.lib \           # RSA/crypto
    ...
```

So the export is advapi32's, but the code lives elsewhere:

| API family | Implementation | Reference |
| --- | --- | --- |
| Registry (`Reg*`) | `base/screg/winreg/client` | [Registry](/registry) |
| Services (`*Service*`, SCM) | `base/screg/sc/client/scwrap.cxx` | [Services](#services) |
| Event log (`*EventLog*`, `RegisterEventSource`) | `base/eventlog` + `mergedcomponents/advapi32/eventapi.c` | [Event log](#event-log) |
| Security descriptors, tokens, privileges | `mergedcomponents/advapi32/security.c`, `sddl.c`, `logon32.c` | [Security and directory](/security-directory) |
| CryptoAPI (`Crypt*`) | `mergedcomponents/advapi32/cryptapi.c` + `ds/security/cryptoapi` | [CryptoAPI](#cryptoapi) |

## Registry

### Roots and predefined keys

| Handle | Meaning | Backing hive |
| --- | --- | --- |
| `HKEY_CLASSES_ROOT` | File associations, COM classes | Merge of `HKLM\Software\Classes` and `HKCU\Software\Classes` |
| `HKEY_CURRENT_USER` | Current user's profile | `NTUSER.DAT` |
| `HKEY_LOCAL_MACHINE` | Machine-wide settings | `SOFTWARE`, `SYSTEM`, `SAM`, `SECURITY`, `HARDWARE` |
| `HKEY_USERS` | Loaded user profiles | `DEFAULT` plus SIDs |
| `HKEY_CURRENT_CONFIG` | Current hardware profile | `SYSTEM\CurrentControlSet\Hardware Profiles` |

`base/screg/winreg/client/predefh.c` maps the predefined handles to real paths. `HKEY_CURRENT_USER`
is a per-process cached handle to the current user's hive, which is why it changes after
`ImpersonateLoggedOnUser` only if `RegOpenCurrentUser` is used.

### Core functions

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `RegOpenKeyExW` | Open a key | `base/screg/winreg/client/regkey.c:1094` | [RegOpenKeyExW](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regopenkeyexw) |
| `RegCreateKeyExW` | Open or create | `regkey.c:490` | [RegCreateKeyExW](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regcreatekeyexw) |
| `RegCloseKey` | Close a key handle | `regkey.c:53` | [RegCloseKey](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regclosekey) |
| `RegQueryValueExW` | Read a value | `base/screg/winreg/client/regqval.c:689` | [RegQueryValueExW](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regqueryvalueexw) |
| `RegSetValueExW` | Write a value | `base/screg/winreg/client/regsval.c:498` | [RegSetValueExW](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regsetvalueexw) |
| `RegEnumKeyExW` | Enumerate subkeys | `base/screg/winreg/client/regekey.c:340` | [RegEnumKeyExW](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regenumkeyexw) |
| `RegEnumValueW` | Enumerate values | `base/screg/winreg/client/regeval.c` | [RegEnumValueW](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regenumvaluew) |
| `RegQueryInfoKeyW` | Key metadata | `base/screg/winreg/client/regqkey.c:304` | [RegQueryInfoKeyW](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regqueryinfokeyw) |
| `RegDeleteKeyW` | Delete an empty key | `base/screg/winreg/client/regdkey.c:124` | [RegDeleteKeyW](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regdeletekeyw) |
| `RegDeleteValueW` | Delete a value | `regdval.c` | [RegDeleteValueW](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regdeletevaluew) |
| `RegFlushKey` | Flush a hive | `regkey.c:711` | [RegFlushKey](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regflushkey) |
| `RegConnectRegistryW` | Connect to a remote registry | `regcnreg.c:272` | [RegConnectRegistryW](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regconnectregistryw) |
| `RegLoadKeyW` / `RegUnLoadKeyW` | Load/unload a hive file | `reglukey.c:168`, `:399` | [RegLoadKeyW](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regloadkeyw) |
| `RegSaveKeyW` / `RegRestoreKeyW` | Save/restore a hive | `regsrkey.c:426`, `:159` | [RegSaveKeyW](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regsavekeyw) |
| `RegNotifyChangeKeyValue` | Watch a key | `regnckey.c:439` | [RegNotifyChangeKeyValue](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regnotifychangekeyvalue) |

### Access rights

| Right | Allows |
| --- | --- |
| `KEY_READ` | `KEY_QUERY_VALUE \| KEY_ENUMERATE_SUB_KEYS \| KEY_NOTIFY \| READ_CONTROL` |
| `KEY_WRITE` | `KEY_SET_VALUE \| KEY_CREATE_SUB_KEY` |
| `KEY_EXECUTE` | Same as `KEY_READ` |
| `KEY_ALL_ACCESS` | Everything |
| `KEY_QUERY_VALUE` | Read values |
| `KEY_SET_VALUE` | Write values |
| `KEY_CREATE_SUB_KEY` | Create subkeys |

`RegOpenKeyExW` fails with `ERROR_ACCESS_DENIED` if the key's security descriptor does not grant the
requested access. Opening with more access than you need is both a failure risk and an unnecessary
privilege.

### Value types

| Type | Data |
| --- | --- |
| `REG_SZ` | Null-terminated UTF-16 string |
| `REG_EXPAND_SZ` | String with `%VAR%` placeholders |
| `REG_MULTI_SZ` | Double-null-terminated list of strings |
| `REG_DWORD` | 32-bit little-endian |
| `REG_QWORD` | 64-bit little-endian |
| `REG_BINARY` | Arbitrary bytes |
| `REG_NONE` | No type |

`REG_SZ` and `REG_EXPAND_SZ` are the same on disk; the type tells the consumer whether to call
`ExpandEnvironmentStringsW`. `REG_MULTI_SZ` is `A\0B\0C\0\0` — the final extra null is required.

### Example: read and write a value

```c
#include <windows.h>
#include <stdio.h>

int wmain(void)
{
    HKEY hKey = NULL;
    LONG rc = RegOpenKeyExW(HKEY_LOCAL_MACHINE,
                            L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion",
                            0, KEY_READ | KEY_SET_VALUE, &hKey);
    if (rc != ERROR_SUCCESS) { wprintf(L"open failed %ld\n", rc); return 1; }

    // Read a string. The size query is required because RegQueryValueExW
    // needs a buffer size and may return ERROR_MORE_DATA.
    DWORD type = 0, size = 0;
    rc = RegQueryValueExW(hKey, L"ProductName", NULL, &type, NULL, &size);
    if (rc == ERROR_SUCCESS && type == REG_SZ && size <= 1024) {
        wchar_t buf[512];
        rc = RegQueryValueExW(hKey, L"ProductName", NULL, &type, (LPBYTE)buf, &size);
        if (rc == ERROR_SUCCESS) { wprintf(L"ProductName = %ls\n", buf); }
    }

    // Write a DWORD.
    DWORD value = 12345;
    rc = RegSetValueExW(hKey, L"NeoWikiValue", 0, REG_DWORD, (const BYTE *)&value, sizeof(value));

    RegCloseKey(hKey);
    return rc == ERROR_SUCCESS ? 0 : 1;
}
```

Registry functions return `ERROR_SUCCESS` (`0`) directly, not `BOOL`. `LSTATUS` is a `LONG`; check
`== ERROR_SUCCESS`, not `if (!rc)` with an implicit conversion that hides warnings.

## Services

The Service Control Manager (SCM) owns services. `base/screg/sc` has a client half and a server
half; the client wrappers are `base/screg/sc/client/scwrap.cxx`.

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `OpenSCManagerW` | Connect to the SCM | `scwrap.cxx:778` | [OpenSCManagerW](https://learn.microsoft.com/en-us/windows/win32/api/winsvc/nf-winsvc-openscmanagerw) |
| `CreateServiceW` | Install a service | `scwrap.cxx:3238` | [CreateServiceW](https://learn.microsoft.com/en-us/windows/win32/api/winsvc/nf-winsvc-createservicew) |
| `OpenServiceW` | Open an existing service | `scwrap.cxx:684` | [OpenServiceW](https://learn.microsoft.com/en-us/windows/win32/api/winsvc/nf-winsvc-openservicew) |
| `StartServiceW` | Start a service | `scwrap.cxx:957` | [StartServiceW](https://learn.microsoft.com/en-us/windows/win32/api/winsvc/nf-winsvc-startservicew) |
| `ControlService` | Send a control code | `scwrap.cxx:265` | [ControlService](https://learn.microsoft.com/en-us/windows/win32/api/winsvc/nf-winsvc-controlservice) |
| `QueryServiceStatusEx` | Query state | `scwrap.cxx:883` | [QueryServiceStatusEx](https://learn.microsoft.com/en-us/windows/win32/api/winsvc/nf-winsvc-queryservicestatusex) |
| `QueryServiceConfigW` | Query configuration | `scwrap.cxx:4193` | [QueryServiceConfigW](https://learn.microsoft.com/en-us/windows/win32/api/winsvc/nf-winsvc-queryserviceconfigw) |
| `EnumServicesStatusW` | Enumerate services | `scwrap.cxx:312` | [EnumServicesStatusW](https://learn.microsoft.com/en-us/windows/win32/api/winsvc/nf-winsvc-enumservicesstatusw) |
| `DeleteService` | Mark for deletion | `scwrap.cxx:3340` | [DeleteService](https://learn.microsoft.com/en-us/windows/win32/api/winsvc/nf-winsvc-deleteservice) |
| `CloseServiceHandle` | Close an SCM/service handle | `scwrap.cxx:734` | [CloseServiceHandle](https://learn.microsoft.com/en-us/windows/win32/api/winsvc/nf-winsvc-closeservicehandle) |

### Service states

```text
SERVICE_STOPPED
   | StartService
   v
SERVICE_START_PENDING -> SERVICE_RUNNING
   | ControlService(SERVICE_CONTROL_STOP)
   v
SERVICE_STOP_PENDING -> SERVICE_STOPPED

SERVICE_PAUSE_PENDING <-> SERVICE_PAUSED
SERVICE_CONTINUE_PENDING -> SERVICE_RUNNING
```

`QueryServiceStatusEx` returns `SERVICE_STATUS_PROCESS`, which includes the process ID and the
service flags. `StartService` returns before the service is running; poll
`QueryServiceStatusEx` or wait on the service's status handle.

```c
SC_HANDLE hScm = OpenSCManagerW(NULL, NULL, SC_MANAGER_CONNECT);
SC_HANDLE hSvc = OpenServiceW(hScm, L"Spooler", SERVICE_START | SERVICE_QUERY_STATUS);
if (hSvc) {
    if (StartServiceW(hSvc, 0, NULL)) {
        SERVICE_STATUS_PROCESS ssp = {0};
        DWORD needed = 0;
        // Poll until the state leaves the pending set.
        for (;;) {
            QueryServiceStatusEx(hSvc, SC_STATUS_PROCESS_INFO, (LPBYTE)&ssp, sizeof(ssp), &needed);
            if (ssp.dwCurrentState == SERVICE_RUNNING) break;
            Sleep(200);
        }
    }
    CloseServiceHandle(hSvc);
}
if (hScm) CloseServiceHandle(hScm);
```

## Event log

The event log client is `base/eventlog` (the ELF API) and the advapi32 wrappers are in
`mergedcomponents/advapi32/eventapi.c`.

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `RegisterEventSourceW` | Get a handle to write | `eventapi.c:704` | [RegisterEventSourceW](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-registereventsourcew) |
| `ReportEventW` | Write a record | `eventapi.c:937` | [ReportEventW](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-reporteventw) |
| `OpenEventLogW` | Get a handle to read | `eventapi.c` | [OpenEventLogW](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-openeventlogw) |
| `ReadEventLogW` | Read records | `eventapi.c` | [ReadEventLogW](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-readeventlogw) |
| `ClearEventLogW` | Clear a log | `eventapi.c` | [ClearEventLogW](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-cleareventlogw) |
| `BackupEventLogW` | Save a log to a file | `eventapi.c` | [BackupEventLogW](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-backupeventlogw) |
| `CloseEventLog` | Close the handle | `eventapi.c` | [CloseEventLog](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-closeeventlog) |
| `GetNumberOfEventLogRecords` | Count records | `eventapi.c` | [GetNumberOfEventLogRecords](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getnumberefeventlogrecords) |

```c
HANDLE hLog = RegisterEventSourceW(NULL, L"NeoWiki");
if (hLog) {
    const wchar_t *strings[] = { L"the wiki service started" };
    ReportEventW(hLog, EVENTLOG_INFORMATION_TYPE, 0, 1, NULL, 1, 0, strings, NULL);
    CloseEventLog(hLog);
}
```

`ReportEventW`'s `dwEventID` must be defined in a message DLL registered under the source name, or
the event viewer shows a placeholder. The tree's `base/eventlog/server` is the service that writes
records to the log files.

## Security API

The user-mode security wrappers live in `mergedcomponents/advapi32/security.c`, with SDDL helpers
in `sddl.c` and logon helpers in `logon32.c`.

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `InitializeSecurityDescriptor` | Initialise a self-relative SD | `security.c:4521` | [InitializeSecurityDescriptor](https://learn.microsoft.com/en-us/windows/win32/api/securitybaseapi/nf-securitybaseapi-initializesecuritydescriptor) |
| `SetSecurityDescriptorDacl` | Set the DACL | `security.c:4766` | [SetSecurityDescriptorDacl](https://learn.microsoft.com/en-us/windows/win32/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptordacl) |
| `GetSecurityDescriptorDacl` | Read the DACL | `security.c:4832` | [GetSecurityDescriptorDacl](https://learn.microsoft.com/en-us/windows/win32/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptordacl) |
| `OpenProcessToken` | Open a process token | `security.c:556` | [OpenProcessToken](https://learn.microsoft.com/en-us/windows/win32/api/securitybaseapi/nf-securitybaseapi-openprocesstoken) |
| `OpenThreadToken` | Open a thread token | `security.c:608` | [OpenThreadToken](https://learn.microsoft.com/en-us/windows/win32/api/securitybaseapi/nf-securitybaseapi-openthreadtoken) |
| `GetTokenInformation` | Query token contents | `security.c:674` | [GetTokenInformation](https://learn.microsoft.com/en-us/windows/win32/api/securitybaseapi/nf-securitybaseapi-gettokeninformation) |
| `AdjustTokenPrivileges` | Enable/disable privileges | `security.c:880` | [AdjustTokenPrivileges](https://learn.microsoft.com/en-us/windows/win32/api/securitybaseapi/nf-securitybaseapi-adjusttokenprivileges) |
| `DuplicateTokenEx` | Create an impersonation token | `security.c:101` | [DuplicateTokenEx](https://learn.microsoft.com/en-us/windows/win32/api/securitybaseapi/nf-securitybaseapi-duplicatetokenex) |
| `ImpersonateLoggedOnUser` | Adopt a token | `logon32.c:1507` | [ImpersonateLoggedOnUser](https://learn.microsoft.com/en-us/windows/win32/api/securitybaseapi/nf-securitybaseapi-impersonateloggedonuser) |
| `RevertToSelf` | End impersonation | `security.c:6927` | [RevertToSelf](https://learn.microsoft.com/en-us/windows/win32/api/securitybaseapi/nf-securitybaseapi-reverttoself) |
| `CheckTokenMembership` | Is a SID enabled in a token | `security.c:9107` | [CheckTokenMembership](https://learn.microsoft.com/en-us/windows/win32/api/securitybaseapi/nf-securitybaseapi-checktokenmembership) |
| `AccessCheck` | Perform an access check | `security.c:240` | [AccessCheck](https://learn.microsoft.com/en-us/windows/win32/api/securitybaseapi/nf-securitybaseapi-accesscheck) |
| `GetUserNameW` | Current user name | `username.c:38` | [GetUserNameW](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getusernamew) |
| `LookupAccountNameW` | Name to SID | `security.c:7530` | [LookupAccountNameW](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-lookupaccountnamew) |

### Example: enable a privilege

```c
#include <windows.h>
#include <stdio.h>

int wmain(void)
{
    HANDLE hToken = NULL;
    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) {
        wprintf(L"OpenProcessToken failed %lu\n", GetLastError());
        return 1;
    }

    TOKEN_PRIVILEGES tp = {0};
    tp.PrivilegeCount = 1;
    tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    if (!LookupPrivilegeValueW(NULL, SE_SHUTDOWN_NAME, &tp.Privileges[0].Luid)) {
        wprintf(L"LookupPrivilegeValueW failed %lu\n", GetLastError());
        CloseHandle(hToken);
        return 1;
    }

    if (!AdjustTokenPrivileges(hToken, FALSE, &tp, 0, NULL, NULL)) {
        wprintf(L"AdjustTokenPrivileges failed %lu\n", GetLastError());
    }

    CloseHandle(hToken);
    return 0;
}
```

`AdjustTokenPrivileges` returns success even when the privilege is not held; check
`GetLastError() == ERROR_NOT_ALL_ASSIGNED` if you need to know.

### Example: build a security descriptor with SDDL

```c
PSECURITY_DESCRIPTOR pSD = NULL;
if (ConvertStringSecurityDescriptorToSecurityDescriptorW(
        L"D:(A;;GA;;;WD)(A;;GA;;;BA)", SDDL_REVISION_1, &pSD, NULL)) {
    // pSD is self-relative and must be freed with LocalFree
    // Use it in SetSecurityInfo / SetNamedSecurityInfo / CreateFile SECURITY_ATTRIBUTES
    LocalFree(pSD);
}
```

## CryptoAPI

The CryptoAPI entry points are `mergedcomponents/advapi32/cryptapi.c`; the providers are under
`ds/security/cryptoapi` (CSPs) and `ds/security/cryptoapi/pki`.

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `CryptAcquireContextW` | Acquire a CSP handle | `cryptapi.c:691` | [CryptAcquireContextW](https://learn.microsoft.com/en-us/windows/win32/api/wincrypt/nf-wincrypt-cryptacquirecontextw) |
| `CryptReleaseContext` | Release it | `cryptapi.c:1248` | [CryptReleaseContext](https://learn.microsoft.com/en-us/windows/win32/api/wincrypt/nf-wincrypt-cryptreleasecontext) |
| `CryptCreateHash` | Create a hash object | `cryptapi.c:2360` | [CryptCreateHash](https://learn.microsoft.com/en-us/windows/win32/api/wincrypt/nf-wincrypt-cryptcreatehash) |
| `CryptHashData` | Feed data to the hash | `cryptapi.c:2564` | [CryptHashData](https://learn.microsoft.com/en-us/windows/win32/api/wincrypt/nf-wincrypt-crypthashdata) |
| `CryptGetHashParam` | Read the digest | `cryptapi.c` | [CryptGetHashParam](https://learn.microsoft.com/en-us/windows/win32/api/wincrypt/nf-wincrypt-cryptgethashparam) |
| `CryptDeriveKey` | Derive a key from a hash | `cryptapi.c:1508` | [CryptDeriveKey](https://learn.microsoft.com/en-us/windows/win32/api/wincrypt/nf-wincrypt-cryptderivekey) |
| `CryptEncrypt` | Encrypt a buffer | `cryptapi.c:2181` | [CryptEncrypt](https://learn.microsoft.com/en-us/windows/win32/api/wincrypt/nf-wincrypt-cryptencrypt) |
| `CryptDecrypt` | Decrypt a buffer | `cryptapi.c:2273` | [CryptDecrypt](https://learn.microsoft.com/en-us/windows/win32/api/wincrypt/nf-wincrypt-cryptdecrypt) |
| `CryptGenRandom` | Fill a buffer with random bytes | `cryptapi.c:1840` | [CryptGenRandom](https://learn.microsoft.com/en-us/windows/win32/api/wincrypt/nf-wincrypt-cryptgenrandom) |

```c
HCRYPTPROV hProv = 0;
HCRYPTHASH hHash = 0;
BYTE digest[20];       // SHA-1 is 20 bytes
DWORD len = sizeof(digest);

if (CryptAcquireContextW(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT) &&
    CryptCreateHash(hProv, CALG_SHA1, 0, 0, &hHash) &&
    CryptHashData(hHash, (const BYTE *)"hello", 5, 0) &&
    CryptGetHashParam(hHash, HP_HASHVAL, digest, &len, 0)) {
    // digest[0..len-1] is the SHA-1 of "hello"
}

if (hHash) CryptDestroyHash(hHash);
if (hProv) CryptReleaseContext(hProv, 0);
```

`CRYPT_VERIFYCONTEXT` acquires a transient context with no key container — the right choice for
hashing and random-number generation. For persistent keys, pass a container name and omit the flag.

## Frequently asked questions

### Q: Why is advapi32 a "merged component"?

Because the Windows team consolidated several DLLs' exports into one binary without moving the code.
`mergedcomponents/advapi32/sources` links `winreg.lib`, `svcctrl.lib`, `elfapi.lib`, `rsa32.lib`
and others, and `advapi32.def` lists the exports. That is why the registry implementation is in
`base/screg/winreg`, the SCM client in `base/screg/sc`, and the event log in `base/eventlog`.

### Q: Why does `RegOpenKeyExW` return a `LONG`, not a `BOOL`?

Because the registry API predates the `BOOL` convention and returns `ERROR_SUCCESS` directly. A
`LONG` of zero is success. Checking `if (!rc)` happens to work but hides the error code; use
`if (rc == ERROR_SUCCESS)`.

### Q: Why does `RegQueryValueExW` need to be called twice?

Because the value size is not known in advance and the API does not return it unless you pass a
buffer. The first call with a `NULL` buffer returns `ERROR_SUCCESS` and sets `*pcbData`; the second
call retrieves the data. If the value can change between calls, be prepared for
`ERROR_MORE_DATA`.

### Q: What is the difference between `HKEY_CURRENT_USER` and `RegOpenCurrentUser`?

`HKEY_CURRENT_USER` is a per-process handle that the loader caches for the process token at startup.
`RegOpenCurrentUser` opens the hive for the **current impersonation token**, which is the correct
call in a service that impersonates users. Using the predefined handle while impersonating gives the
service account's hive, not the user's.

### Q: Why does `StartService` return before the service is running?

Because the SCM only queues the start request. The service's `ServiceMain` runs in its own process
and reports `SERVICE_RUNNING` through `SetServiceStatus`. Poll `QueryServiceStatusEx` or wait for
the service's status change notification.

### Q: Why does `ReportEventW` need a message DLL?

Because the event record stores an event identifier and insertion strings, not a formatted message.
The event viewer resolves the identifier against the message file registered under
`HKLM\SYSTEM\CurrentControlSet\Services\EventLog\<Log>\<Source>` and formats the text. Without a
message file, the record still exists but displays as a placeholder.

### Q: Is `AdjustTokenPrivileges` all I need to shut down the system?

No. You need the `SeShutdownPrivilege` in the token, and you must enable it. `AdjustTokenPrivileges`
enables a privilege the token already holds; it cannot add one the token does not have. Also,
`InitiateSystemShutdown` requires the privilege on the target machine.

### Q: Where is the kernel side of the security API?

`base/ntos/se`: `accessck.c` (`SepAccessCheck` at line 1660), `token.c`, `seassign.c`,
`privileg.c`, `seaudit.c`. The user-mode wrappers build the structures and call
`Nt*` services such as `NtOpenProcessToken`, `NtSetInformationToken`, `NtAdjustPrivilegesToken`.
See [Security and directory services](/security-directory).

### Q: Why is CryptoAPI in advapi32 and also in `ds/security/cryptoapi`?

The advapi32 side is the public entry point and the CSP dispatch; the actual providers (RSA base,
strong, enhanced, and the PKI layer) are separate projects under `ds/security/cryptoapi`. A new
algorithm is a provider change, not an advapi32 change — unless it needs a new export.

### Q: How do I enumerate a registry key's values correctly?

```c
DWORD index = 0, nameLen = 16384, valueLen = 0, type = 0;
wchar_t name[8192];
for (;;) {
    nameLen = 8192; valueLen = 0;
    LONG rc = RegEnumValueW(hKey, index, name, &nameLen, NULL, &type, NULL, &valueLen);
    if (rc == ERROR_NO_MORE_ITEMS) break;
    if (rc != ERROR_SUCCESS) break;
    // name[0..nameLen-1] is the value name; type is the value type
    index++;
}
```

Reset `nameLen` every iteration: `RegEnumValueW` overwrites it with the actual length, and leaving it
at the previous value causes `ERROR_MORE_DATA` on the next call.
