## 2025-10-21 - Assignment in Conditional Error Handling
**Vulnerability:** An assignment operator (`if (bSuccess = FALSE)`) was used instead of a comparison operator (`==`) in database insert result checking in `termsrv/license/tlserver/server/license.cpp`.
**Learning:** Single `=` in `if` statements can silently reset status variables to `FALSE`/0, causing error checks to be skipped and methods to return success even when backend operations fail.
**Prevention:** Always use strict compiler warnings (`-Wparentheses` / `-Wlogical-op` / MSVC `C4706`) and explicit `FALSE == var` or `!var` syntax to prevent accidental assignment in conditionals.
