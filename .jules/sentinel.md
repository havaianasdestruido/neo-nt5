## 2025-10-21 - Assignment in Conditional Error Handling
**Vulnerability:** An assignment operator (`if (bSuccess = FALSE)`) was used instead of a comparison operator (`==`) in database insert result checking in `termsrv/license/tlserver/server/license.cpp`.
**Learning:** Single `=` in `if` statements can silently reset status variables to `FALSE`/0, causing error checks to be skipped and methods to return success even when backend operations fail.
**Prevention:** Always use strict compiler warnings (`-Wparentheses` / `-Wlogical-op` / MSVC `C4706`) and explicit `FALSE == var` or `!var` syntax to prevent accidental assignment in conditionals.

## 2026-10-31 - Signed/Unsigned Mismatch in Protocol Length Bounds Checks
**Vulnerability:** In `base/fs/srv/smbraw.c`, `immediateLength > (WorkContext->ResponseBuffer->DataLength - SmbGetUshort(&request->DataOffset))` compared an unsigned length (`immediateLength` is `ULONG`) against a subtraction involving signed `CLONG` (`DataLength`). When `DataOffset` exceeded `DataLength`, negative subtraction was promoted to a huge unsigned value, bypassing the length check and passing an out-of-bounds pointer into `FastIoWrite`.
**Learning:** Bounds checks that subtract user-controlled offsets before validating that `offset <= total_length` risk underflow; mixing signed buffer lengths with unsigned offsets promotes negative differences to large positive integers, inverting the validation condition.
**Prevention:** Always explicitly check `offset <= length` before subtracting, and ensure all operands in bounds comparisons are cast or declared as matching unsigned integer types (`ULONG`) without underflow potential.
