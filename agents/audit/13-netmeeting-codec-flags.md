# bug: NetMeeting codec begin functions never set DecompressStarted/CompressStarted

Status: **not published — repository Issues disabled**. Local finding A13.

## Summary

Several codec begin functions are supposed to initialize one-shot state but assign FALSE in a conditional, so the body never executes and the Started flag remains false.

## Evidence and reproduction

`enduser/netmeeting/av/codecs/dec/dech263/sa_api.c:560–582`:

```c
     case SA_PCM_DECODE:
        break;
#ifdef MPEG_SUPPORT
     case SA_MPEG_DECODE:
        if (Info->MDInfo->DecompressStarted = FALSE)
           Info->MDInfo->DecompressStarted = TRUE;
        break;
#endif /* MPEG_SUPPORT */
#ifdef AC3_SUPPORT
     case SA_AC3_DECODE:
        if (Info->AC3Info->DecompressStarted = FALSE)
           Info->AC3Info->DecompressStarted = TRUE;
        break;
#endif /* AC3_SUPPORT */

#ifdef G723_SUPPORT
     /*
     case SA_G723_DECODE:
        if (Info->pSaG723Info->DecompressStarted = FALSE)
           Info->pSaG723Info->DecompressStarted = TRUE;
        break;
      */
#endif /* G723_SUPPORT */
```

`enduser/netmeeting/av/codecs/dec/dech263/sa_api.c:848–858`:

```c
#ifdef MPEG_SUPPORT
     case SA_MPEG_ENCODE:
        SaSetParamInt(Sah, SA_PARAM_SAMPLESPERSEC, wfIn->nSamplesPerSec);
        SaSetParamInt(Sah, SA_PARAM_CHANNELS, wfIn->nChannels);
        sa_MpegVerifyEncoderSettings(Sah);
        if (Info->MCInfo->CompressStarted = FALSE)
           Info->MCInfo->CompressStarted = TRUE;
        break;
#endif /* MPEG_SUPPORT */
#ifdef GSM_SUPPORT
     case SA_GSM_ENCODE:
```

`enduser/netmeeting/av/codecs/dec/dech263/sources:12–31`:

```makefile

TARGETNAME=dech263
TARGETEXT=drv
TARGETPATH=$(_OBJ_DIR)
TARGETTYPE=DYNLINK

DLLDEF=dech263.def

TARGETLIBS=$(SDK_LIB_PATH)\kernel32.lib    \
           $(SDK_LIB_PATH)\advapi32.lib    \
           $(SDK_LIB_PATH)\user32.lib      \
           $(SDK_LIB_PATH)\gdi32.lib      \
           $(SDK_LIB_PATH)\ole32.lib

# Use DEC defines (no need for _WINDOWS though)
USER_C_FLAGS=/DSTATIC_BUILD /DH263_SUPPORT $(USER_C_FLAGS)

C_DEFINES=$(C_DEFINES) -DWIN32			

#
```

Run `python3 agents/audit_reproduce.py` from the checkout. An extracted decision: assign FALSE then check it. Output: `codec_exit=0`; the flag stays 0 even when it should be set to TRUE. GCC warns `-Wparentheses`. The identical bug appears in `enduser/netmeeting/av/codecs/dec/dech261/sa_api.c`, which is a duplicate file (cmp exit 0).

## Root cause

`if (Info->MDInfo->DecompressStarted = FALSE)` sets the flag to false and never enters the initialization branch. The intended test was `== FALSE`.

## Impact and severity

**Medium** — NetMeeting audio/video codecs.

## Recommended fix

Change every affected assignment to an equality test (`== FALSE`), cover both dech261 and dech263, and test one-shot initialization for MPEG/AC3/PCM encode/decode paths.

## Acceptance criteria

- [ ] Repeated Begin calls do not reinitialize already-started codec state.
- [ ] All `= FALSE` guarded initializers in sa_api.c are corrected.
- [ ] A compiler settings or local lint pass flags these assignments as warnings/errors.
- [ ] Duplicate dech261/dech263 copies are fixed together.

## Verification limitations

No Windows build, installed OS, or original Microsoft compiler/resource compiler is available. Extracted-code results do not establish a complete product build or boot result. NetMeeting codec driver is not built or executed here. Impact is inferred from the one-shot state flag and downstream !Started checks; no media stream regression was run.

## Deduplication

Checked all available open/closed issue records, PRs #1/#2, their issue comments, review comments and reviews on 2026-10-16. No matching defect report found. PR #2 describes branding as a feature, not these failures. Discussions are disabled.
