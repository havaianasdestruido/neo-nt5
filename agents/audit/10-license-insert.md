# bug: TLSDBLicenseAddEntry reports success after database insert fails

Status: **not published — repository Issues disabled**. Local finding A10.

## Summary

License insertion failures are silently returned as ERROR_SUCCESS, leaving callers believing an unpersisted license record was stored.

## Evidence and reproduction

`termsrv/license/tlserver/server/license.cpp:405–420`:

```cpp
    }

    dwStatus = ERROR_SUCCESS;    

    pLicense->dbLowerBound = dump.dbLowerBound;
    GetSystemTimeAsFileTime(&(pLicense->ftLastModifyTime));
    bSuccess = licenseTable.InsertRecord(*pLicense);

    if(bSuccess = FALSE)
    {
        if(licenseTable.GetLastJetError() == JET_errKeyDuplicate)
        {
            SetLastError(dwStatus=TLS_E_DUPLICATE_RECORD);
        }
        else
        {
```

`termsrv/license/tlserver/server/license.cpp:438–446`:

```cpp

            SetLastError(dwStatus = SET_JB_ERROR(licenseTable.GetLastJetError()));
            TLSASSERT(FALSE);
        }
    };

cleanup:
    return dwStatus;
}
```

Run `python3 agents/audit_reproduce.py` from the checkout. The decision probe forces InsertRecord failure (bSuccess=FALSE) and executes the exact condition. GCC warns about assignment in a truth value; result is `failed_insert_return_status=0`. Expected: duplicate-key or mapped ESE error, never success after failed persistence.

## Root cause

`if(bSuccess = FALSE)` overwrites the insert result and always evaluates false. All error mapping, logging and status updates are skipped.

## Impact and severity

**Medium** — Terminal Services licensing database.

## Recommended fix

Use `if (!bSuccess)` and test failure propagation using a LicensedTable fault-injection seam. Verify callers do not commit/report success for failed inserts.

## Acceptance criteria

- [ ] Successful inserts return success.
- [ ] Duplicate-key insert failure maps to TLS_E_DUPLICATE_RECORD.
- [ ] Other ESE failures are logged and returned as the appropriate nonzero status.
- [ ] No failure path reports a record as persisted.

## Verification limitations

No Windows build, installed OS, or original Microsoft compiler/resource compiler is available. Extracted-code results do not establish a complete product build or boot result. Only the exact decision was compiled with a forced result; no live ESE database, transaction or licensing server was modified.

## Deduplication

Checked all available open/closed issue records, PRs #1/#2, their issue comments, review comments and reviews on 2026-10-16. No matching defect report found. PR #2 describes branding as a feature, not these failures. Discussions are disabled.
