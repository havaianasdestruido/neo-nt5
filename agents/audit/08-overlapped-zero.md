# bug: UL Win9x samples initialize OVERLAPPED with a zero-length memset

Status: **not published — repository Issues disabled**. Local finding A08.

## Summary

Seven OVERLAPPED initializations in four sample programs write zero bytes and then pass indeterminate fields to asynchronous I/O.

## Evidence and reproduction

`inetsrv/iis/iisrearc/ul/win9x/src/test/cmd/snd/snd.c:50–51`:

```c
	memset( &Overlapped, sizeof( Overlapped ), 0 );
	Overlapped.hEvent = CreateEvent( NULL, FALSE, FALSE, NULL );
```

`inetsrv/iis/iisrearc/ul/win9x/src/test/cmd/rcv/rcv.c:60–61`:

```c
	memset( &Overlapped, sizeof( Overlapped ), 0 );
	Overlapped.hEvent = CreateEvent( NULL, FALSE, FALSE, NULL );
```

`inetsrv/iis/iisrearc/ul/win9x/src/test/chat/client/client.c:64–68`:

```c
	ulSize = sizeof( WCHAR ) * ( ulCount + 1 );

	memset( &Overlapped, sizeof( Overlapped ), 0 );
	Overlapped.hEvent = CreateEvent( NULL, FALSE, FALSE, NULL );

```

Run `python3 agents/audit_reproduce.py` from the checkout. A portable OVERLAPPED-layout probe prefills its storage with 0xA5, executes the identical memset statement, and prints `first byte after supposed zeroing: a5`. GCC warns `-Wmemset-transposed-args`. Other occurrences: chat/client/client.c:115,177 and chat/server/server.c:104,219. Expected: clear the whole structure before setting hEvent.

## Root cause

memset arguments are in the order pointer, count, value instead of pointer, value, count.

## Impact and severity

**Low** — IIS UL Win9x test clients.

## Recommended fix

Use `memset(&Overlapped, 0, sizeof Overlapped)` or zero initialization at each affected site; test all reserved/offset fields before asynchronous calls.

## Acceptance criteria

- [ ] All seven calls clear sizeof(OVERLAPPED) bytes.
- [ ] No transposed-memset warning in these samples.
- [ ] A prefilled-structure regression test verifies zero initialization before setting hEvent.

## Verification limitations

No Windows build, installed OS, or original Microsoft compiler/resource compiler is available. Extracted-code results do not establish a complete product build or boot result. This affects legacy sample/test programs; no production HTTP-service exposure is asserted. The probe uses a portable stand-in structure, not Windows I/O.

## Deduplication

Checked all available open/closed issue records, PRs #1/#2, their issue comments, review comments and reviews on 2026-10-16. No matching defect report found. PR #2 describes branding as a feature, not these failures. Discussions are disabled.
