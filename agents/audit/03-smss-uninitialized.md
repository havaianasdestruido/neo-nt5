# bug: SMSS reads uninitialized ValueData when Branding is absent

Status: **not published — repository Issues disabled**. Local finding A03.

## Summary

Normal startup without the optional Branding registry value reads an indeterminate pointer before applying the default; this can cause invalid memory access in SMSS.

## Evidence and reproduction

`base/subsys/sm/server/sminit.c:1470–1476`:

```c
    OBJECT_ATTRIBUTES ObjectAttributes;
    UNICODE_STRING KeyName;
    UNICODE_STRING ValueName;
    PWSTR ValueData;
    WCHAR ValueBuffer[ 256 ];
    WCHAR ValueBuffer1[ 256 ];
    PKEY_VALUE_PARTIAL_INFORMATION KeyValueInfo;
```

`base/subsys/sm/server/sminit.c:1537–1567`:

```c
        RtlInitUnicodeString( &BrandingValueName, L"Branding" );
        BrandingStatus = NtQueryValueKey( Key,
                                         &BrandingValueName,
                                         KeyValuePartialInformation,
                                         NULL,
                                         0,
                                         &BrandingResultSize );
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
        }

        if (ValueData == NULL) {
#if NEONT_BRANDING
            ValueData = L"NEONT";
#else
            ValueData = L"Windows_NT";
#endif
```

`base/subsys/sm/server/sminit.c:1570–1577`:

```c
        RtlInitUnicodeString( &ValueName, L"OS" );
        Status = NtSetValueKey( Key,
                                &ValueName,
                                0,
                                REG_SZ,
                                ValueData,
                                (wcslen( ValueData ) + 1) * sizeof( WCHAR )
                              );
```

Run `python3 agents/audit_reproduce.py` from the checkout. The exact branding block is compiled with NT API stubs returning a missing-value status. GCC `-fanalyzer` reports `use of uninitialized value ValueData [CWE-457]` at the NULL check and subsequent use. The same unassigned path exists on first-query failure and allocation failure. Expected: a deterministic default string, never a read of uninitialized state.

## Root cause

ValueData is declared without initialization. Only the successful allocation/second-query branch assigns it before the NULL test.

## Impact and severity

**High** — Session Manager initialization.

## Recommended fix

Initialize ValueData to NULL (or the intended compatible default) before querying. Preserve that defined fallback for every error and allocation-failure path. Remove the unused BrandingInfoSize declaration.

## Acceptance criteria

- [ ] Missing Branding, access/query failure, allocation failure and invalid type all use a defined fallback.
- [ ] Path analysis reports no uninitialized pointer read.
- [ ] A Windows boot smoke test without Branding succeeds.

## Verification limitations

No Windows build, installed OS, or original Microsoft compiler/resource compiler is available. Extracted-code results do not establish a complete product build or boot result. The finding is static path analysis, not a demonstrated VM boot crash. No privilege-escalation claim is made.

## Deduplication

Checked all available open/closed issue records, PRs #1/#2, their issue comments, review comments and reviews on 2026-10-16. No matching defect report found. PR #2 describes branding as a feature, not these failures. Discussions are disabled.
