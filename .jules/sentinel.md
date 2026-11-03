## 2025-10-21 - Assignment in Conditional Error Handling
**Vulnerability:** An assignment operator (`if (bSuccess = FALSE)`) was used instead of a comparison operator (`==`) in database insert result checking in `termsrv/license/tlserver/server/license.cpp`.
**Learning:** Single `=` in `if` statements can silently reset status variables to `FALSE`/0, causing error checks to be skipped and methods to return success even when backend operations fail.
**Prevention:** Always use strict compiler warnings (`-Wparentheses` / `-Wlogical-op` / MSVC `C4706`) and explicit `FALSE == var` or `!var` syntax to prevent accidental assignment in conditionals.

## 2026-10-31 - Signed/Unsigned Mismatch in Protocol Length Bounds Checks
**Vulnerability:** In `base/fs/srv/smbraw.c`, `immediateLength > (WorkContext->ResponseBuffer->DataLength - SmbGetUshort(&request->DataOffset))` compared an unsigned length (`immediateLength` is `ULONG`) against a subtraction involving signed `CLONG` (`DataLength`). When `DataOffset` exceeded `DataLength`, negative subtraction was promoted to a huge unsigned value, bypassing the length check and passing an out-of-bounds pointer into `FastIoWrite`.
**Learning:** Bounds checks that subtract user-controlled offsets before validating that `offset <= total_length` risk underflow; mixing signed buffer lengths with unsigned offsets promotes negative differences to large positive integers, inverting the validation condition.
**Prevention:** Always explicitly check `offset <= length` before subtracting, and ensure all operands in bounds comparisons are cast or declared as matching unsigned integer types (`ULONG`) without underflow potential.

## 2026-11-02 - Unbounded Backwards Pointer Search in Path Canonicalization
**Vulnerability:** In `ds/netapi/netlib/canon.c`, `ConvertPathMacros` passed `ptr - 1` into `BackUpPath(Path, ptr - 1)` after collapsing a `..` component to the start of the buffer (`ptr == Path`). `BackUpPath` tested `Path != Stopper` only after dereferencing. Because `Path < Stopper`, the equality stop condition never matched, causing the loop to scan backwards out-of-bounds into stack memory until encountering an arbitrary `\` (CVE-2008-4250).
**Learning:** Backwards pointer scans that rely on strict pointer equality `ptr != stopper` fail catastrophically if called with `ptr < stopper`, leading to stack underflows and subsequent out-of-bounds writes if the scan result is used as a copy destination.
**Prevention:** Always ensure search routines enforce directional relational bounds (`Path > Stopper`) and validate `Path >= Stopper` prior to search loops. In callers, guard against decrementing pointers at buffer boundaries (`(ptr > Path) ? BackUpPath(Path, ptr - 1) : NULL`).
