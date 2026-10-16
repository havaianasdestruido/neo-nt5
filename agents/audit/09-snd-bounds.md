# bug: UL snd accepts message lengths beyond its stack buffer

Status: **not published — repository Issues disabled**. Local finding A09.

## Summary

Entering 2048 as the send length writes a terminator one byte past the 2048-byte stack buffer; larger lengths also overflow the fill loop.

## Evidence and reproduction

`inetsrv/iis/iisrearc/ul/win9x/src/test/cmd/snd/snd.c:32–35`:

```c
	ULONG result, ulSize, ulCount;
	DWORD dwWhich, dwTimeout;
	CHAR pBuffer[CMD_BUFFER_SIZE];
	OVERLAPPED Overlapped;
```

`inetsrv/iis/iisrearc/ul/win9x/src/test/cmd/snd/snd.c:65–70`:

```c
		gets( pBuffer );
		ulSize = atoi( pBuffer );
		if ( ulSize == 0 ) goto myexit;

		for ( ulCount = 0; ulCount<ulSize; ulCount++ ) pBuffer[ulCount] = '0'+((CHAR)(ulCount%10));
		pBuffer[ulSize] = '\0';
```

`inetsrv/iis/iisrearc/ul/win9x/src/test/cmd/cmd.h:30–33`:

```c

#define CMD_BUFFER_SIZE 2048
```

Run `python3 agents/audit_reproduce.py` from the checkout. The exact source fill-loop and terminator statement are compiled with a 2048-byte buffer and ulSize=2048. ASan reports `stack-buffer-overflow`, exit 1. On a provisioned legacy system, start snd with a valid URI/timeout and enter `2048` when prompted. Expected: reject lengths above 2047. `gets` also accepts unbounded console input and the argv URI copy at lines 43–44 has no length check; address these input bounds in the same client fix.

## Root cause

Untrusted console/argument lengths are used without validating buffer capacity, including required terminator space; atoi also fails to provide robust parse/range validation.

## Impact and severity

**Low** — IIS UL Win9x snd test client.

## Recommended fix

Use bounded line input and checked integer parsing. Require a nonnegative size strictly below sizeof pBuffer; validate URI capacity before copying. Keep zero-length exit behavior explicit.

## Acceptance criteria

- [ ] 2048, larger values, negative values, overflow and malformed numeric input are rejected safely.
- [ ] 2047 and normal small lengths remain within bounds.
- [ ] Overlong console lines and URI arguments cannot overflow buffers.
- [ ] Boundary probes run clean under ASan.

## Verification limitations

No Windows build, installed OS, or original Microsoft compiler/resource compiler is available. Extracted-code results do not establish a complete product build or boot result. The actual UL driver and executable were not run. Local developer/test-tool impact only; this is not claimed to be remotely reachable in IIS.

## Deduplication

Checked all available open/closed issue records, PRs #1/#2, their issue comments, review comments and reviews on 2026-10-16. No matching defect report found. PR #2 describes branding as a feature, not these failures. Discussions are disabled.
