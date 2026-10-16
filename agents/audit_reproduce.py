#!/usr/bin/env python3
"""Non-destructive audit probes. Generated files live in a temporary directory.
These are extracted-code probes, NOT a Windows build or integration test.
Run from any directory with Python 3, GCC and Perl installed.
"""
from pathlib import Path
import os
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parent.parent

def run(args, **kw):
    p = subprocess.run(args, text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, **kw)
    print('$', ' '.join(map(str, args)))
    print(p.stdout)
    print('exit:', p.returncode)
    return p

with tempfile.TemporaryDirectory(prefix='neo-audit-') as tmp:
    tmp = Path(tmp)
    print('=== Build-number parser: unchanged script, Windows-path fixture on Linux ===')
    # Linux permits backslashes in names; no script/path rewrites are required.
    (tmp / 'fixture\\published\\sdk\\inc\\ntverp.h').write_bytes((ROOT / 'published/sdk/inc/ntverp.h').read_bytes())
    run(['perl', str(ROOT / 'tools/genbldno.pl')], cwd=tmp, env={**os.environ, 'SDXROOT':'fixture'})
    print('=== Disk Administrator preprocessor: both branding modes ===')
    for mode in ('0', '1'):
        p = run(['gcc', '-E', '-P', '-x', 'c', '-DNEONT_BRANDING='+mode, str(ROOT / 'base/fs/utils/fdisk/fdisk.dlg')])
        first = next(line.strip() for line in p.stdout.splitlines() if 'CONTROL' in line)
        print('First CONTROL has required ID/class fields:', ',' in first)

    source = (ROOT / 'base/subsys/sm/server/sminit.c').read_text()
    block = source[source.index('    {\n        UNICODE_STRING BrandingValueName;'):source.index('    if (!NT_SUCCESS( Status )) {', source.index('UNICODE_STRING BrandingValueName;'))]
    prefix = r'''
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <wchar.h>
#include <string.h>
typedef wchar_t WCHAR, *PWSTR;
typedef int NTSTATUS;
typedef unsigned long ULONG;
typedef int UNICODE_STRING;
typedef struct { ULONG TitleIndex, Type, DataLength; unsigned char Data[1]; } KEY_VALUE_PARTIAL_INFORMATION;
#define STATUS_BUFFER_TOO_SMALL (-1)
#define STATUS_BUFFER_OVERFLOW (-2)
#define KeyValuePartialInformation 2
#define REG_SZ 1
#define NT_SUCCESS(x) ((x)>=0)
#define NEONT_BRANDING 1
#define RtlProcessHeap() NULL
#define RtlAllocateHeap(h,f,n) malloc(n)
#define RtlFreeHeap(h,f,p) free(p)
#define RtlInitUnicodeString(a,b) ((void)0)
static int NtQueryValueKey(int k, void *v, int c, void *out, ULONG n, ULONG *size) {
    *size = __builtin_offsetof(KEY_VALUE_PARTIAL_INFORMATION, Data) + sizeof(WCHAR);
#ifdef MISSING
    return -3;
#else
    if (!out) return STATUS_BUFFER_TOO_SMALL;
    KEY_VALUE_PARTIAL_INFORMATION *p = out;
    p->Type=REG_SZ; p->DataLength=sizeof(WCHAR);
    WCHAR x=L'X'; memcpy(p->Data, &x, sizeof(x));
    return 0;
#endif
}
static int NtSetValueKey(int k, void *v, int a, int t, void *p, size_t n) {
    printf("write size=%zu\n", n); return 0;
}
int main(void) {
    PWSTR ValueData;
    UNICODE_STRING ValueName;
    NTSTATUS Status;
    int Key=0;
'''
    c = tmp / 'smss.c'
    c.write_text(prefix + block + '\nreturn Status;\n}\n')
    print('=== SMSS absent Branding: GCC path analysis of exact extracted block ===')
    run(['gcc', '-DMISSING', '-O0', '-fanalyzer', '-c', str(c), '-o', str(tmp/'smss.o')])
    print('=== SMSS non-NUL REG_SZ: ASan exact extracted block with NT/heap stubs ===')
    run(['gcc', '-g', '-O0', '-fsanitize=address', str(c), '-o', str(tmp/'smss')])
    run([str(tmp/'smss')], env={**os.environ, 'ASAN_OPTIONS':'detect_leaks=0'})

    print('=== Sample OVERLAPPED initialization: exact statement, portable structure ===')
    c.write_text('''#include <stdio.h>\n#include <string.h>\ntypedef struct {unsigned long Internal, InternalHigh, Offset, OffsetHigh; void *hEvent;} OVERLAPPED;\nint main(void) { OVERLAPPED Overlapped; memset(&Overlapped,0xA5,sizeof(Overlapped));\nmemset( &Overlapped, sizeof( Overlapped ), 0 );\nprintf("first byte after supposed zeroing: %02x\\n", *(unsigned char*)&Overlapped); }\n''')
    run(['gcc', '-Wall', str(c), '-o', str(tmp/'overlapped')])
    run([str(tmp/'overlapped')])

    print('=== snd message length boundary: source-extracted buffer-writing loop ===')
    snd = (ROOT / 'inetsrv/iis/iisrearc/ul/win9x/src/test/cmd/snd/snd.c').read_text()
    start = snd.index("\t\tfor ( ulCount = 0; ulCount<ulSize;")
    loop = snd[start:snd.index('\n\t\tprintf', start)]
    c.write_text('#include <stdlib.h>\ntypedef char CHAR;\nint main(void) { unsigned long ulCount, ulSize=2048; char pBuffer[2048];\n' + loop + '\nreturn pBuffer[0]; }\n')
    run(['gcc', '-g', '-O0', '-fsanitize=address', str(c), '-o', str(tmp/'snd')])
    run([str(tmp/'snd')], env={**os.environ, 'ASAN_OPTIONS':'detect_leaks=0'})

    print('=== Media branding disabled: preprocess macros without Windows headers ===')
    header = (ROOT/'multimedia/media/mmcaps2k/mmcaps.h').read_text()
    # Extract the complete product-name conditional; unrelated includes need Windows SDK.
    section = header[header.index('#ifdef WIN32', header.index('APP_VERSION_COMPANYNAME_RC')):header.index('#ifdef DEBUG')]
    macro = tmp/'media.h'
    macro.write_text(section + '\nAPP_VERSION_PRODUCTNAME_RC\n')
    run(['gcc', '-E', '-P', '-x', 'c', '-DWIN32', '-D_X86_', '-DNEONT_BRANDING=0', str(macro)])

    print('=== WMI HTTP header failure: exact method body, failing WinINet stub ===')
    http = (ROOT/'admin/wmi/wbem/xmltransport/client/helpersources/httpconnectionagent.cpp').read_text()
    start = http.index('HRESULT CHTTPConnectionAgent::GetResultHeader(WCHAR **ppszBuffer, DWORD *pdwHeaderLen)')
    body = http[start:http.index('\n/*', start)].replace('CHTTPConnectionAgent::', '')
    stub = r'''
#include <cstdio>
#include <cstddef>
typedef int HRESULT;
typedef int BOOL;
typedef wchar_t WCHAR;
typedef unsigned long DWORD;
#define S_OK 0
#define E_FAIL (-1)
#define E_INVALIDARG (-2)
#define E_OUTOFMEMORY (-3)
#define FALSE 0
#define HTTP_QUERY_RAW_HEADERS_CRLF 0
int m_pCriticalSection=0, m_hOpenRequest=0;
void EnterCriticalSection(int) {}
void LeaveCriticalSection(int) {}
BOOL HttpQueryInfo(int,int,void *,DWORD *n,DWORD *) { *n=8; return FALSE; }
'''
    cpp=tmp/'http.cpp'
    cpp.write_text(stub + body + '\nint main(){ WCHAR *p=NULL; DWORD n=0; int hr=GetResultHeader(&p,&n); printf("hr=%d buffer_returned=%d\\n",hr,p!=NULL); delete[] p; }\n')
    run(['g++', '-Wall', str(cpp), '-o', str(tmp/'http')])
    run([str(tmp/'http')])

    print('=== License insertion failure: extracted decision with forced failed insert ===')
    license = (ROOT/'termsrv/license/tlserver/server/license.cpp').read_text()
    start = license.index('    bSuccess = licenseTable.InsertRecord(*pLicense);')
    end = license.index('\ncleanup:', start)
    decision = license[start:end]
    c.write_text('''#include <stdio.h>\n#define FALSE 0\nint main(void) { int bSuccess=0; unsigned long dwStatus=0;\n'''+decision[decision.index('    if(bSuccess = FALSE)'):decision.index('\n    {', decision.index('    if(bSuccess = FALSE)'))]+''' {dwStatus=123;}\nprintf("failed_insert_return_status=%lu\\n",dwStatus); return 0; }\n''')
    run(['gcc', '-Wall', str(c), '-o', str(tmp/'license')])
    run([str(tmp/'license')])
