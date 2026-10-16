# security: SMSS calls wcslen on unvalidated registry REG_SZ data

Status: **not published — repository Issues disabled**. Local finding A04.

## Summary

A successful Branding query can supply REG_SZ bytes without a NUL terminator. SMSS scans beyond the returned heap allocation while calculating the OS value length.

## Evidence and reproduction

`base/subsys/sm/server/sminit.c:1544–1559`:

```c
        if (BrandingStatus == STATUS_BUFFER_TOO_SMALL || BrandingStatus == STATUS_BUFFER_OVERFLOW) {
            BrandingInfo = (KEY_VALUE_PARTIAL_INFORMATION *)RtlAllocateHeap( RtlProcessHeap(), 0, BrandingResultSize );
            if (BrandingInfo != NULL) {
                BrandingStatus = NtQueryValueKey( Key,
                                                 &BrandingValueName,
                                                 KeyValuePartialInformation,
                                                 BrandingInfo,
                                                 BrandingResultSize,
                                                 &BrandingResultSize );
                if (NT_SUCCESS( BrandingStatus ) && BrandingInfo->Type == REG_SZ &&
                    BrandingInfo->DataLength >= sizeof( WCHAR )) {
                    ValueData = (PWSTR)BrandingInfo->Data;
                } else {
                    ValueData = NULL;
                }
            }
```

`base/subsys/sm/server/sminit.c:1570–1581`:

```c
        RtlInitUnicodeString( &ValueName, L"OS" );
        Status = NtSetValueKey( Key,
                                &ValueName,
                                0,
                                REG_SZ,
                                ValueData,
                                (wcslen( ValueData ) + 1) * sizeof( WCHAR )
                              );

        if (BrandingInfo != NULL) {
            RtlFreeHeap( RtlProcessHeap(), 0, BrandingInfo );
        }
```

Run `python3 agents/audit_reproduce.py` from the checkout. The extracted block receives one nonzero WCHAR with REG_SZ type, DataLength equal to sizeof(WCHAR), and no terminator. AddressSanitizer reports `heap-buffer-overflow` in `__interceptor_wcslen`, exit 1. Expected: reject malformed strings or create a bounded, terminated copy before any string operation.

## Root cause

Type and minimum length checks do not establish alignment, a terminator, or a bounded string length. Registry value bytes must not be assumed NUL-terminated.

## Impact and severity

**High** — Session Manager registry boundary.

## Recommended fix

Validate even WCHAR byte length and available data bounds; use a bounded length and ensure a terminator in separately sized storage. Reject malformed values and fall back safely. Keep this separate from initializing ValueData: either fix alone leaves the other bug.

## Acceptance criteria

- [ ] Nonterminated, zero-length, odd-byte and invalid-type values cannot trigger out-of-bounds reads.
- [ ] Terminated valid values still work.
- [ ] Regression test is clean under a memory checker.

## Verification limitations

No Windows build, installed OS, or original Microsoft compiler/resource compiler is available. Extracted-code results do not establish a complete product build or boot result. Linux probe uses host wchar_t width (4 bytes), whereas Windows WCHAR is 2; the missing terminator/bound-check defect is width-independent. API and heap functions are stubbed. Writing this HKLM key normally requires administrative access; no remote or unprivileged exploit was established.

## Deduplication

Checked all available open/closed issue records, PRs #1/#2, their issue comments, review comments and reviews on 2026-10-16. No matching defect report found. PR #2 describes branding as a feature, not these failures. Discussions are disabled.
