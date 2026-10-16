# bug: branding changes firmware-visible ACPI _OS identity

Status: **not published — repository Issues disabled**. Local finding A06.

## Summary

The branding switch changes the ACPI _OS string consumed by firmware AML, not merely a user-visible label, violating the previous firmware identity contract.

## Evidence and reproduction

`base/busdrv/acpi/driver/nt/amlisupp.c:24–35`:

```c
#include "pch.h"

#ifndef NEONT_BRANDING
#define NEONT_BRANDING 1
#endif



#if NEONT_BRANDING
PSZ gpszOSName = "NEONT";
#else
PSZ gpszOSName = "Microsoft Windows NT";
```

`base/busdrv/acpi/driver/amlinew/amliapi.c:166–184`:

```c
            if ((rc == STATUS_SUCCESS) &&
                ((rc = CreateNameSpaceObject(gpheapGlobal, "_OS", NULL, NULL,
                                             &pns, 0)) == STATUS_SUCCESS))
            {
                pns->ObjData.dwDataType = OBJTYPE_STRDATA;
                pns->ObjData.dwDataLen = STRLEN(gpszOSName) + 1;
                if ((pns->ObjData.pbDataBuff = NEWSDOBJ(gpheapGlobal,
                                                        pns->ObjData.dwDataLen))
                    == NULL)
                {
                    rc = AMLI_LOGERR(AMLIERR_OUT_OF_MEM,
                                     ("AMLIInitialize: failed to allocate \\_OS name object"));
                }
                else
                {
                    MEMCPY(pns->ObjData.pbDataBuff, gpszOSName,
                           pns->ObjData.dwDataLen);
                }
            }
```

Static dataflow: default branding sets gpszOSName to NEONT; AMLIInitialize creates namespace object `_OS` and copies gpszOSName into its data. Any AML comparison of `_OS` to the previously exposed Microsoft Windows NT string necessarily changes outcome. Expected: retain the established firmware identity while changing display branding.

## Root cause

The same display-branding switch controls a firmware-facing OS compatibility interface.

## Impact and severity

**Medium** — ACPI firmware compatibility.

## Recommended fix

Always expose the established Microsoft Windows NT ACPI _OS string for this kernel; keep display branding separate.

## Acceptance criteria

- [ ] ACPI _OS remains Microsoft Windows NT in both branding modes.
- [ ] An AML fixture comparing _OS to the compatibility string takes the same branch in both modes.
- [ ] Document that firmware identities are excluded from cosmetic rebranding.

## Verification limitations

No Windows build, installed OS, or original Microsoft compiler/resource compiler is available. Extracted-code results do not establish a complete product build or boot result. The changed firmware-visible value is confirmed by source dataflow. No real DSDT, AML interpreter, or affected hardware was available, so actual device/power failures are not claimed.

## Deduplication

Checked all available open/closed issue records, PRs #1/#2, their issue comments, review comments and reviews on 2026-10-16. No matching defect report found. PR #2 describes branding as a feature, not these failures. Discussions are disabled.
