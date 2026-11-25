---
title: Status and error codes
sidebar_position: 23
description: NTSTATUS severity and facility, the common STATUS_* values, Win32 error codes, HRESULT, and the functions that translate between them.
---

Windows has three error namespaces. Confusing them produces misleading logs, wrong retry logic, and
"the call failed with error 0" reports. This page is the decoder ring.

| Namespace | Type | Produced by | Consumed by | Translation |
| --- | --- | --- | --- | --- |
| NT status | `NTSTATUS` | Kernel and native services | `Nt*` return values, `IO_STATUS_BLOCK.Status` | `RtlNtStatusToDosError` |
| Win32 error | `DWORD` (`ERROR_*`) | Win32 APIs | `GetLastError` | `BaseSetLastNTError` |
| COM `HRESULT` | 32-bit | COM methods | Return value | `HRESULT_FROM_WIN32` |

## `NTSTATUS` layout

Defined in `public/sdk/inc/ntdef.h`:

```text
 3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0
 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
+---------------+---------------+-------------------------------+---------------+
| Severity (2)  | Customer (1)  | Reserved/Facility (12)        | Code (16)     |
+---------------+---------------+-------------------------------+---------------+
```

| Bits | Field | Meaning |
| --- | --- | --- |
| 31–30 | Severity | `00` success, `01` informational, `10` warning, `11` error |
| 29 | Customer | `1` if the code is customer-defined |
| 28–16 | Facility | `FACILITY_*` value |
| 15–0 | Code | Facility-specific code |

The severity macros:

```c
#define NT_SUCCESS(Status)      ((NTSTATUS)(Status) >= 0)
#define NT_INFORMATION(Status)  (((ULONG)(Status)) >> 30 == 1)
#define NT_WARNING(Status)      (((ULONG)(Status)) >> 30 == 2)
#define NT_ERROR(Status)        (((ULONG)(Status)) >> 30 == 3)
```

`NT_SUCCESS` is **true for informational and warning statuses**, not just success. A status like
`STATUS_BUFFER_OVERFLOW` (`0x80000005`) is a warning: the call partially succeeded. Checking only
`NT_SUCCESS` and then reading the buffer as if it were complete is a real bug.

## Common `STATUS_*` values

| Status | Value | Meaning | Win32 mapping |
| --- | --- | --- | --- |
| `STATUS_SUCCESS` | `0x00000000` | Success | `ERROR_SUCCESS` |
| `STATUS_PENDING` | `0x00000103` | Operation pending | `ERROR_IO_PENDING` |
| `STATUS_BUFFER_OVERFLOW` | `0x80000005` | Buffer too small, data truncated | `ERROR_MORE_DATA` |
| `STATUS_BUFFER_TOO_SMALL` | `0xC0000023` | Buffer too small, nothing written | `ERROR_INSUFFICIENT_BUFFER` |
| `STATUS_INVALID_PARAMETER` | `0xC000000D` | Bad parameter | `ERROR_INVALID_PARAMETER` |
| `STATUS_INVALID_HANDLE` | `0xC0000008` | Bad handle | `ERROR_INVALID_HANDLE` |
| `STATUS_ACCESS_DENIED` | `0xC0000022` | Access denied | `ERROR_ACCESS_DENIED` |
| `STATUS_OBJECT_NAME_NOT_FOUND` | `0xC0000034` | Path does not exist | `ERROR_FILE_NOT_FOUND` |
| `STATUS_OBJECT_NAME_COLLISION` | `0xC0000035` | Name already exists | `ERROR_FILE_EXISTS` |
| `STATUS_OBJECT_PATH_NOT_FOUND` | `0xC000003A` | Parent path does not exist | `ERROR_PATH_NOT_FOUND` |
| `STATUS_FILE_IS_A_DIRECTORY` | `0xC00000BA` | Operation invalid on a directory | `ERROR_ACCESS_DENIED` |
| `STATUS_NOT_IMPLEMENTED` | `0xC0000002` | Not implemented | `ERROR_INVALID_FUNCTION` |
| `STATUS_NO_MEMORY` | `0xC0000017` | Allocation failed | `ERROR_NOT_ENOUGH_MEMORY` |
| `STATUS_CONFLICTING_ADDRESSES` | `0xC0000018` | Address range already mapped | `ERROR_INVALID_ADDRESS` |
| `STATUS_UNABLE_TO_FREE_VM` | `0xC000001A` | Cannot free the range | `ERROR_INVALID_ADDRESS` |
| `STATUS_ACCESS_VIOLATION` | `0xC0000005` | Invalid memory access | Exception |
| `STATUS_PRIVILEGE_NOT_HELD` | `0xC0000061` | Privilege missing | `ERROR_PRIVILEGE_NOT_HELD` |
| `STATUS_NO_SUCH_PRIVILEGE` | `0xC0000060` | Privilege does not exist | `ERROR_NO_SUCH_PRIVILEGE` |
| `STATUS_NOT_ALL_ASSIGNED` | `0xC0000064` | Some privileges not held | `ERROR_NOT_ALL_ASSIGNED` |
| `STATUS_INVALID_IMAGE_FORMAT` | `0xC000007B` | Bad PE / wrong architecture | `ERROR_BAD_EXE_FORMAT` |
| `STATUS_ENTRYPOINT_NOT_FOUND` | `0xC0000139` | Import not found | `ERROR_PROC_NOT_FOUND` |
| `STATUS_DLL_NOT_FOUND` | `0xC0000135` | DLL not found | `ERROR_MOD_NOT_FOUND` |
| `STATUS_CANCELLED` | `0xC0000120` | Operation cancelled | `ERROR_OPERATION_ABORTED` |
| `STATUS_TIMEOUT` | `0x00000102` | Wait timed out | `WAIT_TIMEOUT` |
| `STATUS_USER_APC` | `0x000000C0` | APC delivered | `WAIT_IO_COMPLETION` |
| `STATUS_ABANDONED` | `0x00000080` | Abandoned mutex | `WAIT_ABANDONED` |

## Common Win32 error codes

| Error | Value | Meaning |
| --- | --- | --- |
| `ERROR_SUCCESS` | 0 | Success |
| `ERROR_INVALID_FUNCTION` | 1 | Not supported |
| `ERROR_FILE_NOT_FOUND` | 2 | File missing |
| `ERROR_PATH_NOT_FOUND` | 3 | Path missing |
| `ERROR_ACCESS_DENIED` | 5 | Access denied |
| `ERROR_INVALID_HANDLE` | 6 | Bad handle |
| `ERROR_NOT_ENOUGH_MEMORY` | 8 | Allocation failed |
| `ERROR_NO_MORE_FILES` | 18 | End of enumeration |
| `ERROR_SHARING_VIOLATION` | 32 | File in use |
| `ERROR_LOCK_VIOLATION` | 33 | Locked region |
| `ERROR_HANDLE_EOF` | 38 | End of file |
| `ERROR_BAD_FORMAT` | 11 | Bad EXE format |
| `ERROR_INVALID_ACCESS` | 12 | Invalid access |
| `ERROR_INVALID_DATA` | 13 | Invalid data |
| `ERROR_OUTOFMEMORY` | 14 | Out of memory |
| `ERROR_CURRENT_DIRECTORY` | 16 | Cannot remove the current directory |
| `ERROR_NOT_SAME_DEVICE` | 17 | Cross-device rename |
| `ERROR_NO_MORE_ITEMS` | 259 | End of enumeration |
| `ERROR_GEN_FAILURE` | 31 | Device failure |
| `ERROR_FILE_EXISTS` | 80 | File exists |
| `ERROR_INVALID_PARAMETER` | 87 | Bad parameter |
| `ERROR_IO_PENDING` | 997 | Overlapped I/O pending |
| `ERROR_IO_INCOMPLETE` | 996 | Overlapped I/O incomplete |
| `ERROR_NOT_ALL_ASSIGNED` | 1300 | Some privileges not held |
| `ERROR_PRIVILEGE_NOT_HELD` | 1314 | Privilege not held |
| `ERROR_ALREADY_EXISTS` | 183 | Object already existed |
| `ERROR_MOD_NOT_FOUND` | 126 | DLL not found |
| `ERROR_PROC_NOT_FOUND` | 127 | Export not found |
| `ERROR_BAD_EXE_FORMAT` | 193 | Bad EXE format |

The full list is `public/sdk/inc/winerror.h`, which is 2,000+ lines of `#define ERROR_*`.

## `HRESULT` layout

```text
 3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0
 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
+---------------+---------------+-------------------------------+---------------+
| Severity (1)  | R (1) | N (1)| Facility (11)                | Code (16)     |
+---------------+---------------+-------------------------------+---------------+
```

| Bit | Meaning |
| --- | --- |
| 31 | Severity: `1` failure, `0` success |
| 30 | Reserved (`R`) |
| 29 | `N`: `1` if the error is from a non-Microsoft facility |
| 28–16 | Facility (`FACILITY_WINDOWS`, `FACILITY_ITF`, ...) |
| 15–0 | Code |

The `SUCCEEDED` and `FAILED` macros test bit 31:

```c
#define SUCCEEDED(hr) (((HRESULT)(hr)) >= 0)
#define FAILED(hr)    (((HRESULT)(hr)) < 0)
```

`SUCCEEDED(hr)` is true for `S_FALSE` as well as `S_OK`. If you need "the object was actually
created", test `hr == S_OK`, not `SUCCEEDED(hr)`.

## Conversion functions

| Function | Direction | Implementation | Documentation |
| --- | --- | --- | --- |
| `RtlNtStatusToDosError` | `NTSTATUS` to `ERROR_*` | `base/ntos/rtl/error.c:45` | [RtlNtStatusToDosError](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlntstatustodoserror) |
| `RtlDosErrorToNtStatus` | `ERROR_*` to `NTSTATUS` | `base/ntos/rtl/error.c` | [RtlDosErrorToNtStatus](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtldoserrortontstatus) |
| `BaseSetLastNTError` | `NTSTATUS` to `GetLastError` | `base/win32/client/error.c:177` | internal |
| `FormatMessageW` | Error code to text | `base/win32/client/message.c:156` | [FormatMessageW](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-formatmessagew) |
| `HRESULT_FROM_WIN32` | `ERROR_*` to `HRESULT` | macro | [HRESULT_FROM_WIN32](https://learn.microsoft.com/en-us/windows/win32/api/winerror/nf-winerror-hresult_from_win32) |
| `GetLastError` | Read the last Win32 error | `base/win32/client/error.c:92` | [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) |

`BaseSetLastNTError` is the one every Win32 wrapper calls after a failed native service:

```c
// base/win32/client/error.c
BaseSetLastNTError(
    IN NTSTATUS Status
    )
{
    ...
    SetLastError( dwErrorCode );
}
```

It calls `RtlNtStatusToDosError` and then `SetLastError`, which stores the value in the TEB.

## Decoding a status at a glance

```c
static const wchar_t *Severity(NTSTATUS st)
{
    switch (((ULONG)st) >> 30) {
    case 0: return L"success";
    case 1: return L"informational";
    case 2: return L"warning";
    default: return L"error";
    }
}

static const wchar_t *Facility(NTSTATUS st)
{
    switch ((((ULONG)st) >> 16) & 0xFFF) {
    case 0x000: return L"FACILITY_NULL";
    case 0x003: return L"FACILITY_DISPATCH";
    case 0x004: return L"FACILITY_STORAGE";
    case 0x007: return L"FACILITY_WIN32";
    case 0x009: return L"FACILITY_SECURITY";
    case 0x00A: return L"FACILITY_RPC";
    case 0x00B: return L"FACILITY_SSPI";
    case 0x00C: return L"FACILITY_TERMINAL_SERVER";
    default:   return L"FACILITY_OTHER";
    }
}
```

`FACILITY_WIN32` (`0x7`) means the low 16 bits are a Win32 error code, which is the mapping
`HRESULT_FROM_WIN32` produces. `FACILITY_RPC` (`0xA`) is an RPC status. `FACILITY_SECURITY`
(`0x9`) is an SSPI/security status.

## Reading a bugcheck

A kernel bugcheck stop code is a `NTSTATUS`-like value, but the four parameters are documented per
stop code. The tree's `base/ntos/ke/bugcheck.c` contains the `KeBugcheckEx` implementation and the
string table:

```text
0x0000001E  KMODE_EXCEPTION_NOT_HANDLED
0x00000050  PAGE_FAULT_IN_NONPAGED_AREA
0x0000007F  UNEXPECTED_KERNEL_MODE_TRAP
0x000000A   IRQL_NOT_LESS_OR_EQUAL
0x000000C2  BAD_POOL_CALLER
0x000000D1  DRIVER_IRQL_NOT_LESS_OR_EQUAL
0x000000EA  THREAD_STUCK_IN_DEVICE_DRIVER
0x00000133  DPC_WATCHDOG_VIOLATION
```

The parameters are in `KeBugcheckEx`'s argument list and in the dump; `!analyze -v` in the debugger
maps them to the source line. See [Tests, diagnostics and debugging](/testing-debugging).

## Frequently asked questions

### Q: Why does `NT_SUCCESS` return true for warnings?

Because `NT_SUCCESS` is defined as `>= 0`, and warnings have severity `10` (negative in two's
complement only if the top bits are `10` — actually `0x80000005` is negative, so `>= 0` is false).
The subtlety is that `STATUS_PENDING` (`0x00000103`) is informational and `NT_SUCCESS` is true for
it. Always check for `STATUS_PENDING` explicitly when you care about completion.

### Q: Why does `GetLastError` return stale values?

Because it is a per-thread variable in the TEB that is only written when an API fails. A successful
call may not clear it. The documented pattern is to call `SetLastError(0)` before a call whose
success/failure you will test through `GetLastError`, or to test the return value and only then
read the error.

### Q: Why does `CreateFileW` set `ERROR_ALREADY_EXISTS` and still return a handle?

Because the creation disposition allows success-with-history. `CREATE_ALWAYS` on an existing file
truncates it and reports `FILE_OVERWRITTEN`; `OPEN_ALWAYS` reports `FILE_OPENED`. The Win32 layer
maps both to `ERROR_ALREADY_EXISTS` while returning a valid handle. Only `INVALID_HANDLE_VALUE`
means failure.

### Q: How do I get the message text for an `NTSTATUS`?

`FormatMessageW` with `FORMAT_MESSAGE_FROM_SYSTEM` handles many `ERROR_*` codes but not all
`NTSTATUS` values. For a native status, `ntdll!RtlNtStatusToDosError` first, then
`FormatMessageW`. The tree's `base/ntos/rtl/error.c` contains the mapping table.

### Q: What is the difference between `STATUS_BUFFER_OVERFLOW` and `STATUS_BUFFER_TOO_SMALL`?

`STATUS_BUFFER_OVERFLOW` means the call wrote as much as fitted and the buffer was too small — the
data is partially valid. `STATUS_BUFFER_TOO_SMALL` means the buffer was too small and nothing was
written; `Information` holds the required size. Both are warnings, not errors.

### Q: Why is `HRESULT` signed but `NTSTATUS` compared with `>= 0`?

Both are 32-bit values with severity in the top bits, so a signed comparison is the natural test for
success. `SUCCEEDED`/`FAILED` and `NT_SUCCESS` all rely on the same bit-31 convention. Do not
compare with `== 0`; `S_FALSE` and `STATUS_PENDING` are success values.

### Q: Where is `winerror.h`?

`public/sdk/inc/winerror.h`. It defines `ERROR_*`, `SEVERITY_*`, `FACILITY_*`, `S_OK`, `E_*`,
`HRESULT_FROM_WIN32` and the `FORMAT_MESSAGE_*` flags. The file is large; search it with
`rg -n 'ERROR_' public/sdk/inc/winerror.h`.

### Q: How do I turn a Win32 error into an `HRESULT`?

`HRESULT_FROM_WIN32(error)` — a macro that sets `FACILITY_WIN32` and the severity bit. The inverse
is `HRESULT_CODE(hr)`, which extracts the low 16 bits.
