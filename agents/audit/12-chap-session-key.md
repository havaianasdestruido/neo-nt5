# security: PPP CHAP user-session key zeroing clears only a pointer width

Status: **not published — repository Issues disabled**. Local finding A12.

## Summary

CGetSessionKeys only clears the first pointer-sized bytes of the user session-key buffer before key derivation, leaving stale bytes and producing an incorrect session key under failure paths.

## Evidence and reproduction

`net/rras/ras/ppp/common/clsa.c:685–708`:

```c
        WCHAR           szPw[ PWLEN + 1 ];
        NT_PASSWORD     ntpw;
        NT_OWF_PASSWORD ntowf;
        ANSI_STRING     ansi;

        memset( pUserKey, '\0', sizeof(pUserKey) );

        /* NT_PASSWORD is really a UNICODE_STRING, so we need to convert our
        ** ANSI password.
        */
        ntpw.Length = 0;
        ntpw.MaximumLength = sizeof(szPw);
        ntpw.Buffer = szPw;
        RtlInitAnsiString( &ansi, pszPw );
        RtlAnsiStringToUnicodeString( &ntpw, &ansi, FALSE );

        RtlCalculateNtOwfPassword( &ntpw, &ntowf );

        /* The first argument to RtlCalculateUserSessionKeyNt is the NT
        ** response, but it is not used internally.
        */
        RtlCalculateUserSessionKeyNt( NULL, &ntowf, pUserKey );

        memset( szPw, '\0', sizeof(szPw) );
```

`public/internal/ds/inc/crypt.h:252–257`:

```c
// The user session key is similar to the LM and NT session key except it
// is different for each user on the system. This allows it to be used
// for secure user communication with a server.
//
// begin_ntsubauth
#define USER_SESSION_KEY_LENGTH     (CYPHER_BLOCK_LENGTH * 2)
```

`net/rras/ras/ppp/raschap/sources:28–34`:

```makefile
    $(SDK_LIB_PATH)\ole32.lib \
	$(SDK_LIB_PATH)\uuid.lib \
	$(SDK_LIB_PATH)\oleaut32.lib \
    ..\common\$(O)\ppputil.lib 

INCLUDES=..\..\inc;..\..\..\inc;..\..\..\..\..\inc;\
    ..\..\..\..\..\inc\crypto;..\common;$(DS_INC_PATH);$(DS_INC_PATH)\crypto;$(QFE_INC_PATH);
```

Run `python3 agents/audit_reproduce.py` from the checkout. A minimal probe mirrors `sizeof(pUserKey)` and `sizeof(*pUserKey)` against the public USER_SESSION_KEY layout: output is `bytes zeroed: 8/16 non-zero remaining=8`, exit 2. Expected: zero the full `USER_SESSION_KEY` structure (16 bytes), not `pUserKey` (a pointer).

## Root cause

The memset argument order is correct, but the size is `sizeof(pUserKey)` instead of `sizeof(*pUserKey)`. Since pUserKey is a pointer, this clears 4 or 8 bytes instead of the full key.

## Impact and severity

**High** — RRAS PPP CHAP session-key derivation.

## Recommended fix

Use `memset(pUserKey, 0, sizeof(*pUserKey))` and similarly review LM key error-zeroing. Add regression tests for buffer zeroing and successful/failed key derivation.

## Acceptance criteria

- [ ] All 16 bytes of USER_SESSION_KEY are zeroed before derivation and on failure.
- [ ] Pointer-size regression test catches this pattern on 32-bit and 64-bit builds.
- [ ] MS-CHAP session-key consumers see deterministic zeroing rather than stale stack/heap bytes.

## Verification limitations

No Windows build, installed OS, or original Microsoft compiler/resource compiler is available. Extracted-code results do not establish a complete product build or boot result. Struct layout and sizes are from the published headers; RtlCalculateUserSessionKeyNt implementation in crypto DLL is not built/linked here, so a live CHAP exchange was not reproduced.

## Deduplication

Checked all available open/closed issue records, PRs #1/#2, their issue comments, review comments and reviews on 2026-10-16. No matching defect report found. PR #2 describes branding as a feature, not these failures. Discussions are disabled.
