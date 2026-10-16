# bug: WMI HTTP header query returns success and uninitialized data on failure

Status: **not published — repository Issues disabled**. Local finding A11.

## Summary

GetResultHeader returns S_OK and transfers an unwritten heap buffer to the caller when the second HttpQueryInfo call fails.

## Evidence and reproduction

`admin/wmi/wbem/xmltransport/client/helpersources/httpconnectionagent.cpp:598–613`:

```cpp
		bResult = HttpQueryInfo(m_hOpenRequest,HTTP_QUERY_RAW_HEADERS_CRLF,
			szResult,&dwBufLen,&dwNextHeader);

		if(bResult = FALSE)
			hr = E_FAIL;
		else
			*ppszBuffer = szResult;

	}

	if(NULL != pdwHeaderLen)
		*pdwHeaderLen = dwBufLen; //fill out param header length.

	LeaveCriticalSection(m_pCriticalSection);

	return hr;
```

`admin/wmi/wbem/xmltransport/client/mainsources/xmlwbemclienttransport.cpp:95–102`:

```cpp
					WCHAR *pwszResponse = NULL;

					// No need to check the return value here since, if the call
					// fails and pszResponse is NULL, the call to Initialize() below
					// will automatically assume a non-WMI server
					ConnectionAgent.GetResultHeader(&pwszResponse,&dwResponseSize);

					// Create the IWbemServices object and initialize it with not only the
```

Run `python3 agents/audit_reproduce.py` from the checkout. The exact method body is compiled with no-op lock stubs and a HttpQueryInfo stub that returns FALSE for both the sizing query and data query. Actual output: `hr=0 buffer_returned=1`; GCC warns about the assignment condition. Expected: failure HRESULT and NULL buffer. The production caller explicitly relies on NULL on failure to distinguish a non-WMI server.

## Root cause

`if(bResult = FALSE)` assigns false, always takes the else branch, and returns the newly allocated but uninitialized buffer while hr remains S_OK.

## Impact and severity

**Medium** — WMI XML HTTP transport.

## Recommended fix

Use `if (!bResult)`, initialize output pointer and length, free the temporary buffer on failure, check sizing-query error semantics, and only transfer ownership after a successful data query.

## Acceptance criteria

- [ ] Failed data query returns failure, NULL buffer and defined length without leaking.
- [ ] Sizing-query failures other than insufficient buffer are handled explicitly.
- [ ] Successful header queries still transfer valid terminated data.
- [ ] A mocked WinINet regression exercises sizing success/failure and second-query failure.

## Verification limitations

No Windows build, installed OS, or original Microsoft compiler/resource compiler is available. Extracted-code results do not establish a complete product build or boot result. Exact method tested with WinINet/lock stubs, not against a live server. No outbound disclosure or remote exploit was demonstrated.

## Deduplication

Checked all available open/closed issue records, PRs #1/#2, their issue comments, review comments and reviews on 2026-10-16. No matching defect report found. PR #2 describes branding as a feature, not these failures. Discussions are disabled.
