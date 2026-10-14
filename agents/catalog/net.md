# `net/` — directory and build-definition inventory

**1364 tracked directories; 890 directories with `sources`.**
Read the [explanation of `net/`](../components/net.md),
the [catalog key](README.md), or the [agent guide](../README.md).
This is a literal inventory, not a resolved build graph or a claim that every
directory is shipped. Paths and metadata reflect tracked files at generation time.

## `net/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net](../../net) | 5 | [net/dirs](../../net/dirs) | — | — |

## `net/1394/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/1394](../../net/1394) | 1 | [net/1394/dirs](../../net/1394/dirs) | — | — |
| [net/1394/arp](../../net/1394/arp) | 1 | [net/1394/arp/dirs](../../net/1394/arp/dirs) | — | — |
| [net/1394/arp/kdext](../../net/1394/arp/kdext) | 17 | [net/1394/arp/kdext/sources](../../net/1394/arp/kdext/sources), [net/1394/arp/kdext/makefile](../../net/1394/arp/kdext/makefile) | `tkd` | `PROGRAM` |
| [net/1394/arp/sys](../../net/1394/arp/sys) | 28 | [net/1394/arp/sys/dirs](../../net/1394/arp/sys/dirs) | — | — |
| [net/1394/arp/sys/nt](../../net/1394/arp/sys/nt) | 2 | [net/1394/arp/sys/nt/sources](../../net/1394/arp/sys/nt/sources), [net/1394/arp/sys/nt/makefile](../../net/1394/arp/sys/nt/makefile) | `arp1394` | `DRIVER` |
| [net/1394/componentdef](../../net/1394/componentdef) | 6 | [net/1394/componentdef/sources](../../net/1394/componentdef/sources), [net/1394/componentdef/makefile](../../net/1394/componentdef/makefile) | `None` | `notarget` |
| [net/1394/enum](../../net/1394/enum) | 1 | [net/1394/enum/dirs](../../net/1394/enum/dirs) | — | — |
| [net/1394/enum/sys](../../net/1394/enum/sys) | 7 | [net/1394/enum/sys/sources](../../net/1394/enum/sys/sources), [net/1394/enum/sys/makefile](../../net/1394/enum/sys/makefile) | `Enum1394` | `DRIVER` |
| [net/1394/inc](../../net/1394/inc) | 4 | — | — | — |
| [net/1394/inf](../../net/1394/inf) | 5 | [net/1394/inf/sources](../../net/1394/inf/sources), [net/1394/inf/makefile](../../net/1394/inf/makefile) | `inf` | `notarget` |
| [net/1394/nic](../../net/1394/nic) | 1 | [net/1394/nic/dirs](../../net/1394/nic/dirs) | — | — |
| [net/1394/nic/sys](../../net/1394/nic/sys) | 35 | [net/1394/nic/sys/sources](../../net/1394/nic/sys/sources), [net/1394/nic/sys/makefile](../../net/1394/nic/sys/makefile) | `nic1394` | `DRIVER` |
| [net/1394/tools](../../net/1394/tools) | 1 | [net/1394/tools/dirs](../../net/1394/tools/dirs) | — | — |
| [net/1394/tools/ipfwadm](../../net/1394/tools/ipfwadm) | 9 | [net/1394/tools/ipfwadm/sources](../../net/1394/tools/ipfwadm/sources), [net/1394/tools/ipfwadm/makefile](../../net/1394/tools/ipfwadm/makefile) | `ipfwadm` | `PROGRAM` |

## `net/atm/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/atm](../../net/atm) | 1 | [net/atm/dirs](../../net/atm/dirs) | — | — |
| [net/atm/arp](../../net/atm/arp) | 1 | [net/atm/arp/dirs](../../net/atm/arp/dirs) | — | — |
| [net/atm/arp/atmarp](../../net/atm/arp/atmarp) | 10 | [net/atm/arp/atmarp/sources](../../net/atm/arp/atmarp/sources), [net/atm/arp/atmarp/makefile](../../net/atm/arp/atmarp/makefile) | `atmarp` | `PROGRAM` |
| [net/atm/arp/atmarpc](../../net/atm/arp/atmarpc) | 36 | [net/atm/arp/atmarpc/sources](../../net/atm/arp/atmarpc/sources), [net/atm/arp/atmarpc/makefile](../../net/atm/arp/atmarpc/makefile) | `atmarpc` | `DRIVER` |
| [net/atm/arp/atmarps](../../net/atm/arp/atmarps) | 23 | [net/atm/arp/atmarps/sources](../../net/atm/arp/atmarps/sources), [net/atm/arp/atmarps/makefile](../../net/atm/arp/atmarps/makefile) | `atmarps` | `DRIVER` |
| [net/atm/arp/kdext](../../net/atm/arp/kdext) | 15 | [net/atm/arp/kdext/sources](../../net/atm/arp/kdext/sources), [net/atm/arp/kdext/makefile](../../net/atm/arp/kdext/makefile) | `atmarpkd` | `DYNLINK` |
| [net/atm/componentdef](../../net/atm/componentdef) | 6 | [net/atm/componentdef/sources](../../net/atm/componentdef/sources), [net/atm/componentdef/makefile](../../net/atm/componentdef/makefile) | `None` | `notarget` |
| [net/atm/epvc](../../net/atm/epvc) | 1 | [net/atm/epvc/dirs](../../net/atm/epvc/dirs) | — | — |
| [net/atm/epvc/inf](../../net/atm/epvc/inf) | 6 | [net/atm/epvc/inf/sources](../../net/atm/epvc/inf/sources), [net/atm/epvc/inf/makefile](../../net/atm/epvc/inf/makefile) | `inf` | `notarget` |
| [net/atm/epvc/notify](../../net/atm/epvc/notify) | 20 | [net/atm/epvc/notify/sources](../../net/atm/epvc/notify/sources), [net/atm/epvc/notify/makefile](../../net/atm/epvc/notify/makefile) | `atmpvcno` | `DYNLINK` |
| [net/atm/epvc/sys](../../net/atm/epvc/sys) | 23 | [net/atm/epvc/sys/sources](../../net/atm/epvc/sys/sources), [net/atm/epvc/sys/makefile](../../net/atm/epvc/sys/makefile) | `atmepvc` | `DRIVER` |
| [net/atm/inc](../../net/atm/inc) | 3 | — | — | — |
| [net/atm/lane](../../net/atm/lane) | 1 | [net/atm/lane/dirs](../../net/atm/lane/dirs) | — | — |
| [net/atm/lane/exe](../../net/atm/lane/exe) | 5 | [net/atm/lane/exe/sources](../../net/atm/lane/exe/sources), [net/atm/lane/exe/makefile](../../net/atm/lane/exe/makefile) | `atmlane` | `PROGRAM` |
| [net/atm/lane/kdext](../../net/atm/lane/kdext) | 5 | [net/atm/lane/kdext/sources](../../net/atm/lane/kdext/sources), [net/atm/lane/kdext/makefile](../../net/atm/lane/kdext/makefile) | `kdlane` | `DYNLINK` |
| [net/atm/lane/sys](../../net/atm/lane/sys) | 25 | [net/atm/lane/sys/sources](../../net/atm/lane/sys/sources), [net/atm/lane/sys/makefile](../../net/atm/lane/sys/makefile) | `atmlane` | `DRIVER` |
| [net/atm/rawwan](../../net/atm/rawwan) | 1 | [net/atm/rawwan/dirs](../../net/atm/rawwan/dirs) | — | — |
| [net/atm/rawwan/sys](../../net/atm/rawwan/sys) | 25 | [net/atm/rawwan/sys/sources](../../net/atm/rawwan/sys/sources), [net/atm/rawwan/sys/makefile](../../net/atm/rawwan/sys/makefile) | `rawwan` | `DRIVER` |
| [net/atm/rawwan/tdi](../../net/atm/rawwan/tdi) | 8 | [net/atm/rawwan/tdi/sources](../../net/atm/rawwan/tdi/sources), [net/atm/rawwan/tdi/makefile](../../net/atm/rawwan/tdi/makefile) | `atmsp` | `LIBRARY` |
| [net/atm/samples](../../net/atm/samples) | 0 | — | — | — |
| [net/atm/samples/atmsmpl](../../net/atm/samples/atmsmpl) | 2 | [net/atm/samples/atmsmpl/dirs](../../net/atm/samples/atmsmpl/dirs) | — | — |
| [net/atm/samples/atmsmpl/app](../../net/atm/samples/atmsmpl/app) | 7 | [net/atm/samples/atmsmpl/app/sources](../../net/atm/samples/atmsmpl/app/sources), [net/atm/samples/atmsmpl/app/makefile](../../net/atm/samples/atmsmpl/app/makefile) | `atmsmapp` | `PROGRAM` |
| [net/atm/samples/atmsmpl/driver](../../net/atm/samples/atmsmpl/driver) | 17 | [net/atm/samples/atmsmpl/driver/sources](../../net/atm/samples/atmsmpl/driver/sources), [net/atm/samples/atmsmpl/driver/makefile](../../net/atm/samples/atmsmpl/driver/makefile) | `atmsmdrv` | `DRIVER` |
| [net/atm/samples/atmsmpl/inc](../../net/atm/samples/atmsmpl/inc) | 1 | — | — | — |
| [net/atm/winsock](../../net/atm/winsock) | 5 | [net/atm/winsock/sources](../../net/atm/winsock/sources), [net/atm/winsock/makefile](../../net/atm/winsock/makefile) | `wshatm` | `DYNLINK` |

## `net/config/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/config](../../net/config) | 3 | [net/config/dirs](../../net/config/dirs) | — | — |
| [net/config/common](../../net/config/common) | 1 | [net/config/common/dirs](../../net/config/common/dirs) | — | — |
| [net/config/common/ncbase](../../net/config/common/ncbase) | 29 | [net/config/common/ncbase/sources](../../net/config/common/ncbase/sources), [net/config/common/ncbase/makefile](../../net/config/common/ncbase/makefile) | `ncbase` | `LIBRARY` |
| [net/config/common/ncdebug](../../net/config/common/ncdebug) | 10 | [net/config/common/ncdebug/sources](../../net/config/common/ncdebug/sources), [net/config/common/ncdebug/makefile](../../net/config/common/ncdebug/makefile) | `ncdebug` | `LIBRARY` |
| [net/config/common/ncdebug/unit](../../net/config/common/ncdebug/unit) | 3 | [net/config/common/ncdebug/unit/sources](../../net/config/common/ncdebug/unit/sources), [net/config/common/ncdebug/unit/makefile](../../net/config/common/ncdebug/unit/makefile) | `unit_dbg` | `PROGRAM` |
| [net/config/common/nclan](../../net/config/common/nclan) | 4 | [net/config/common/nclan/sources](../../net/config/common/nclan/sources), [net/config/common/nclan/makefile](../../net/config/common/nclan/makefile) | `lancmn` | `LIBRARY` |
| [net/config/common/ncnetcfg](../../net/config/common/ncnetcfg) | 13 | [net/config/common/ncnetcfg/sources](../../net/config/common/ncnetcfg/sources), [net/config/common/ncnetcfg/makefile](../../net/config/common/ncnetcfg/makefile) | `ncnetcfg` | `LIBRARY` |
| [net/config/common/ncnetcon](../../net/config/common/ncnetcon) | 6 | [net/config/common/ncnetcon/sources](../../net/config/common/ncnetcon/sources), [net/config/common/ncnetcon/makefile](../../net/config/common/ncnetcon/makefile) | `ncnetcon` | `LIBRARY` |
| [net/config/common/ncoc](../../net/config/common/ncoc) | 6 | [net/config/common/ncoc/sources](../../net/config/common/ncoc/sources), [net/config/common/ncoc/makefile](../../net/config/common/ncoc/makefile) | `ncoc` | `LIBRARY` |
| [net/config/common/ncras](../../net/config/common/ncras) | 4 | [net/config/common/ncras/sources](../../net/config/common/ncras/sources), [net/config/common/ncras/makefile](../../net/config/common/ncras/makefile) | `ncras` | `LIBRARY` |
| [net/config/common/nctraceui](../../net/config/common/nctraceui) | 10 | [net/config/common/nctraceui/sources](../../net/config/common/nctraceui/sources), [net/config/common/nctraceui/makefile](../../net/config/common/nctraceui/makefile) | `nctraceui` | `LIBRARY` |
| [net/config/dbgext](../../net/config/dbgext) | 9 | [net/config/dbgext/sources](../../net/config/dbgext/sources), [net/config/dbgext/makefile](../../net/config/dbgext/makefile) | `ncext` | `DYNLINK` |
| [net/config/embedded](../../net/config/embedded) | 5 | — | — | — |
| [net/config/idl](../../net/config/idl) | 1 | — | — | — |
| [net/config/inc](../../net/config/inc) | 81 | — | — | — |
| [net/config/netcfg](../../net/config/netcfg) | 1 | [net/config/netcfg/dirs](../../net/config/netcfg/dirs) | — | — |
| [net/config/netcfg/alanecfg](../../net/config/netcfg/alanecfg) | 10 | [net/config/netcfg/alanecfg/sources](../../net/config/netcfg/alanecfg/sources), [net/config/netcfg/alanecfg/makefile](../../net/config/netcfg/alanecfg/makefile) | `alanecfg` | `LIBRARY` |
| [net/config/netcfg/atlkcfg](../../net/config/netcfg/atlkcfg) | 9 | [net/config/netcfg/atlkcfg/sources](../../net/config/netcfg/atlkcfg/sources), [net/config/netcfg/atlkcfg/makefile](../../net/config/netcfg/atlkcfg/makefile) | `atlkcfg` | `LIBRARY` |
| [net/config/netcfg/atmcfg](../../net/config/netcfg/atmcfg) | 24 | [net/config/netcfg/atmcfg/sources](../../net/config/netcfg/atmcfg/sources), [net/config/netcfg/atmcfg/makefile](../../net/config/netcfg/atmcfg/makefile) | `atmcfg` | `LIBRARY` |
| [net/config/netcfg/brdgcfg](../../net/config/netcfg/brdgcfg) | 6 | [net/config/netcfg/brdgcfg/sources](../../net/config/netcfg/brdgcfg/sources), [net/config/netcfg/brdgcfg/makefile](../../net/config/netcfg/brdgcfg/makefile) | `brdgcfg` | `LIBRARY` |
| [net/config/netcfg/dhcpscfg](../../net/config/netcfg/dhcpscfg) | 9 | [net/config/netcfg/dhcpscfg/sources](../../net/config/netcfg/dhcpscfg/sources), [net/config/netcfg/dhcpscfg/makefile](../../net/config/netcfg/dhcpscfg/makefile) | `dhcpscfg` | `LIBRARY` |
| [net/config/netcfg/dll](../../net/config/netcfg/dll) | 9 | [net/config/netcfg/dll/sources](../../net/config/netcfg/dll/sources), [net/config/netcfg/dll/makefile](../../net/config/netcfg/dll/makefile) | `netcfgx` | `DYNLINK` |
| [net/config/netcfg/engine](../../net/config/netcfg/engine) | 80 | [net/config/netcfg/engine/sources](../../net/config/netcfg/engine/sources), [net/config/netcfg/engine/makefile](../../net/config/netcfg/engine/makefile) | `be` | `LIBRARY` |
| [net/config/netcfg/inc](../../net/config/netcfg/inc) | 9 | — | — | — |
| [net/config/netcfg/inf](../../net/config/netcfg/inf) | 53 | [net/config/netcfg/inf/dirs](../../net/config/netcfg/inf/dirs) | — | — |
| [net/config/netcfg/inf/ent](../../net/config/netcfg/inf/ent) | 3 | [net/config/netcfg/inf/ent/sources](../../net/config/netcfg/inf/ent/sources), [net/config/netcfg/inf/ent/makefile](../../net/config/netcfg/inf/ent/makefile) | — | — |
| [net/config/netcfg/inf/per](../../net/config/netcfg/inf/per) | 3 | [net/config/netcfg/inf/per/sources](../../net/config/netcfg/inf/per/sources), [net/config/netcfg/inf/per/makefile](../../net/config/netcfg/inf/per/makefile) | — | — |
| [net/config/netcfg/inf/sld](../../net/config/netcfg/inf/sld) | 26 | — | — | — |
| [net/config/netcfg/inf/srv](../../net/config/netcfg/inf/srv) | 3 | [net/config/netcfg/inf/srv/sources](../../net/config/netcfg/inf/srv/sources), [net/config/netcfg/inf/srv/makefile](../../net/config/netcfg/inf/srv/makefile) | — | — |
| [net/config/netcfg/inf/usa](../../net/config/netcfg/inf/usa) | 51 | — | — | — |
| [net/config/netcfg/inf/wks](../../net/config/netcfg/inf/wks) | 3 | [net/config/netcfg/inf/wks/sources](../../net/config/netcfg/inf/wks/sources), [net/config/netcfg/inf/wks/makefile](../../net/config/netcfg/inf/wks/makefile) | — | — |
| [net/config/netcfg/isdncfg](../../net/config/netcfg/isdncfg) | 13 | [net/config/netcfg/isdncfg/sources](../../net/config/netcfg/isdncfg/sources), [net/config/netcfg/isdncfg/makefile](../../net/config/netcfg/isdncfg/makefile) | `isdncfg` | `LIBRARY` |
| [net/config/netcfg/msclicfg](../../net/config/netcfg/msclicfg) | 14 | [net/config/netcfg/msclicfg/sources](../../net/config/netcfg/msclicfg/sources), [net/config/netcfg/msclicfg/makefile](../../net/config/netcfg/msclicfg/makefile) | `msclicfg` | `LIBRARY` |
| [net/config/netcfg/nbfcfg](../../net/config/netcfg/nbfcfg) | 7 | [net/config/netcfg/nbfcfg/sources](../../net/config/netcfg/nbfcfg/sources), [net/config/netcfg/nbfcfg/makefile](../../net/config/netcfg/nbfcfg/makefile) | `nbfcfg` | `LIBRARY` |
| [net/config/netcfg/netcomm](../../net/config/netcfg/netcomm) | 22 | [net/config/netcfg/netcomm/sources](../../net/config/netcfg/netcomm/sources), [net/config/netcfg/netcomm/makefile](../../net/config/netcfg/netcomm/makefile) | `netcomm` | `LIBRARY` |
| [net/config/netcfg/nwclicfg](../../net/config/netcfg/nwclicfg) | 11 | [net/config/netcfg/nwclicfg/sources](../../net/config/netcfg/nwclicfg/sources), [net/config/netcfg/nwclicfg/makefile](../../net/config/netcfg/nwclicfg/makefile) | `nwclicfg` | `LIBRARY` |
| [net/config/netcfg/nwlnkcfg](../../net/config/netcfg/nwlnkcfg) | 14 | [net/config/netcfg/nwlnkcfg/sources](../../net/config/netcfg/nwlnkcfg/sources), [net/config/netcfg/nwlnkcfg/makefile](../../net/config/netcfg/nwlnkcfg/makefile) | `nwlnkcfg` | `LIBRARY` |
| [net/config/netcfg/rascfg](../../net/config/netcfg/rascfg) | 34 | [net/config/netcfg/rascfg/sources](../../net/config/netcfg/rascfg/sources), [net/config/netcfg/rascfg/makefile](../../net/config/netcfg/rascfg/makefile) | `rascfg` | `LIBRARY` |
| [net/config/netcfg/sapcfg](../../net/config/netcfg/sapcfg) | 7 | [net/config/netcfg/sapcfg/sources](../../net/config/netcfg/sapcfg/sources), [net/config/netcfg/sapcfg/makefile](../../net/config/netcfg/sapcfg/makefile) | `sapcfg` | `LIBRARY` |
| [net/config/netcfg/sfncfg](../../net/config/netcfg/sfncfg) | 16 | [net/config/netcfg/sfncfg/sources](../../net/config/netcfg/sfncfg/sources), [net/config/netcfg/sfncfg/makefile](../../net/config/netcfg/sfncfg/makefile) | `sfncfg` | `DYNLINK` |
| [net/config/netcfg/srvrcfg](../../net/config/netcfg/srvrcfg) | 12 | [net/config/netcfg/srvrcfg/sources](../../net/config/netcfg/srvrcfg/sources), [net/config/netcfg/srvrcfg/makefile](../../net/config/netcfg/srvrcfg/makefile) | `srvrcfg` | `LIBRARY` |
| [net/config/netcfg/tcpipcfg](../../net/config/netcfg/tcpipcfg) | 42 | [net/config/netcfg/tcpipcfg/sources](../../net/config/netcfg/tcpipcfg/sources), [net/config/netcfg/tcpipcfg/makefile](../../net/config/netcfg/tcpipcfg/makefile) | `tcpipcfg` | `LIBRARY` |
| [net/config/netcfg/wlbscfg](../../net/config/netcfg/wlbscfg) | 28 | [net/config/netcfg/wlbscfg/sources](../../net/config/netcfg/wlbscfg/sources), [net/config/netcfg/wlbscfg/makefile](../../net/config/netcfg/wlbscfg/makefile) | `wlbs` | `LIBRARY` |
| [net/config/netman](../../net/config/netman) | 1 | [net/config/netman/dirs](../../net/config/netman/dirs) | — | — |
| [net/config/netman/conman](../../net/config/netman/conman) | 50 | [net/config/netman/conman/sources](../../net/config/netman/conman/sources), [net/config/netman/conman/makefile](../../net/config/netman/conman/makefile) | `conman` | `LIBRARY` |
| [net/config/netman/conobs](../../net/config/netman/conobs) | 12 | [net/config/netman/conobs/sources](../../net/config/netman/conobs/sources), [net/config/netman/conobs/makefile](../../net/config/netman/conobs/makefile) | `conobs` | `LIBRARY` |
| [net/config/netman/dll](../../net/config/netman/dll) | 15 | [net/config/netman/dll/sources](../../net/config/netman/dll/sources), [net/config/netman/dll/makefile](../../net/config/netman/dll/makefile) | `netman` | `DYNLINK` |
| [net/config/netman/eapol](../../net/config/netman/eapol) | 1 | [net/config/netman/eapol/dirs](../../net/config/netman/eapol/dirs) | — | — |
| [net/config/netman/eapol/inf](../../net/config/netman/eapol/inf) | 4 | [net/config/netman/eapol/inf/sources](../../net/config/netman/eapol/inf/sources), [net/config/netman/eapol/inf/makefile](../../net/config/netman/eapol/inf/makefile) | `inf` | `notarget` |
| [net/config/netman/eapol/parser](../../net/config/netman/eapol/parser) | 8 | [net/config/netman/eapol/parser/sources](../../net/config/netman/eapol/parser/sources), [net/config/netman/eapol/parser/makefile](../../net/config/netman/eapol/parser/makefile) | `nmeapol` | `DYNLINK` |
| [net/config/netman/eapol/service](../../net/config/netman/eapol/service) | 25 | [net/config/netman/eapol/service/sources](../../net/config/netman/eapol/service/sources), [net/config/netman/eapol/service/makefile](../../net/config/netman/eapol/service/makefile) | `eapol` | `LIBRARY` |
| [net/config/netman/inc](../../net/config/netman/inc) | 19 | — | — | — |
| [net/config/netman/ncqueue](../../net/config/netman/ncqueue) | 4 | [net/config/netman/ncqueue/sources](../../net/config/netman/ncqueue/sources), [net/config/netman/ncqueue/makefile](../../net/config/netman/ncqueue/makefile) | `ncqueue` | `LIBRARY` |
| [net/config/netman/test](../../net/config/netman/test) | 5 | [net/config/netman/test/sources](../../net/config/netman/test/sources), [net/config/netman/test/makefile](../../net/config/netman/test/makefile) | `tnetman` | `PROGRAM` |
| [net/config/netoc](../../net/config/netoc) | 37 | [net/config/netoc/sources](../../net/config/netoc/sources), [net/config/netoc/makefile](../../net/config/netoc/makefile) | `netoc` | `DYNLINK` |
| [net/config/samples](../../net/config/samples) | 1 | [net/config/samples/dirs](../../net/config/samples/dirs) | — | — |
| [net/config/samples/answerfiles](../../net/config/samples/answerfiles) | 5 | — | — | — |
| [net/config/samples/bindview](../../net/config/samples/bindview) | 12 | [net/config/samples/bindview/sources](../../net/config/samples/bindview/sources), [net/config/samples/bindview/makefile](../../net/config/samples/bindview/makefile) | `bindview` | `PROGRAM` |
| [net/config/samples/filter](../../net/config/samples/filter) | 15 | [net/config/samples/filter/sources](../../net/config/samples/filter/sources), [net/config/samples/filter/makefile](../../net/config/samples/filter/makefile) | `passthru` | `DYNLINK` |
| [net/config/samples/muxim](../../net/config/samples/muxim) | 21 | [net/config/samples/muxim/sources](../../net/config/samples/muxim/sources), [net/config/samples/muxim/makefile](../../net/config/samples/muxim/makefile) | `mux` | `DYNLINK` |
| [net/config/samples/netcfg](../../net/config/samples/netcfg) | 10 | [net/config/samples/netcfg/sources](../../net/config/samples/netcfg/sources), [net/config/samples/netcfg/makefile](../../net/config/samples/netcfg/makefile) | `snetcfg` | `PROGRAM` |
| [net/config/samples/oemupg](../../net/config/samples/oemupg) | 8 | [net/config/samples/oemupg/sources](../../net/config/samples/oemupg/sources), [net/config/samples/oemupg/makefile](../../net/config/samples/oemupg/makefile) | `oemupg` | `DYNLINK` |
| [net/config/shell](../../net/config/shell) | 1 | [net/config/shell/dirs](../../net/config/shell/dirs) | — | — |
| [net/config/shell/advcfg](../../net/config/shell/advcfg) | 13 | [net/config/shell/advcfg/sources](../../net/config/shell/advcfg/sources), [net/config/shell/advcfg/makefile](../../net/config/shell/advcfg/makefile) | `advcfg` | `LIBRARY` |
| [net/config/shell/commconn](../../net/config/shell/commconn) | 9 | [net/config/shell/commconn/sources](../../net/config/shell/commconn/sources), [net/config/shell/commconn/makefile](../../net/config/shell/commconn/makefile) | `commconn` | `LIBRARY` |
| [net/config/shell/common](../../net/config/shell/common) | 4 | [net/config/shell/common/sources](../../net/config/shell/common/sources), [net/config/shell/common/makefile](../../net/config/shell/common/makefile) | `shcommon` | `LIBRARY` |
| [net/config/shell/cpl](../../net/config/shell/cpl) | 9 | [net/config/shell/cpl/sources](../../net/config/shell/cpl/sources), [net/config/shell/cpl/makefile](../../net/config/shell/cpl/makefile) | `ncpa` | `DYNLINK` |
| [net/config/shell/dll](../../net/config/shell/dll) | 11 | [net/config/shell/dll/sources](../../net/config/shell/dll/sources), [net/config/shell/dll/makefile](../../net/config/shell/dll/makefile) | `netshell` | `DYNLINK` |
| [net/config/shell/dun](../../net/config/shell/dun) | 4 | [net/config/shell/dun/sources](../../net/config/shell/dun/sources), [net/config/shell/dun/makefile](../../net/config/shell/dun/makefile) | `dun` | `LIBRARY` |
| [net/config/shell/folder](../../net/config/shell/folder) | 73 | [net/config/shell/folder/sources](../../net/config/shell/folder/sources), [net/config/shell/folder/makefile](../../net/config/shell/folder/makefile) | `confold` | `LIBRARY` |
| [net/config/shell/ico](../../net/config/shell/ico) | 17 | — | — | — |
| [net/config/shell/ico/confolder](../../net/config/shell/ico/confolder) | 29 | — | — | — |
| [net/config/shell/ico/mediatypes](../../net/config/shell/ico/mediatypes) | 7 | — | — | — |
| [net/config/shell/ico/overlays](../../net/config/shell/ico/overlays) | 10 | — | — | — |
| [net/config/shell/ico/statmon](../../net/config/shell/ico/statmon) | 8 | — | — | — |
| [net/config/shell/ico/tray](../../net/config/shell/ico/tray) | 6 | — | — | — |
| [net/config/shell/icons](../../net/config/shell/icons) | 35 | — | — | — |
| [net/config/shell/idl](../../net/config/shell/idl) | 4 | [net/config/shell/idl/sources](../../net/config/shell/idl/sources), [net/config/shell/idl/makefile](../../net/config/shell/idl/makefile) | `idl` | `LIBRARY` |
| [net/config/shell/inc](../../net/config/shell/inc) | 22 | — | — | — |
| [net/config/shell/lanui](../../net/config/shell/lanui) | 37 | [net/config/shell/lanui/sources](../../net/config/shell/lanui/sources), [net/config/shell/lanui/makefile](../../net/config/shell/lanui/makefile) | `lanui` | `LIBRARY` |
| [net/config/shell/netsetup](../../net/config/shell/netsetup) | 54 | [net/config/shell/netsetup/sources](../../net/config/shell/netsetup/sources), [net/config/shell/netsetup/makefile](../../net/config/shell/netsetup/makefile) | `netsetup` | `LIBRARY` |
| [net/config/shell/res](../../net/config/shell/res) | 122 | — | — | — |
| [net/config/shell/statmon](../../net/config/shell/statmon) | 18 | [net/config/shell/statmon/sources](../../net/config/shell/statmon/sources), [net/config/shell/statmon/makefile](../../net/config/shell/statmon/makefile) | `statmon` | `LIBRARY` |
| [net/config/shell/wanui](../../net/config/shell/wanui) | 15 | [net/config/shell/wanui/sources](../../net/config/shell/wanui/sources), [net/config/shell/wanui/makefile](../../net/config/shell/wanui/makefile) | `wanui` | `LIBRARY` |
| [net/config/tools](../../net/config/tools) | 1 | [net/config/tools/dirs](../../net/config/tools/dirs) | — | — |
| [net/config/tools/chkaf](../../net/config/tools/chkaf) | 1 | — | — | — |
| [net/config/tools/dllquery](../../net/config/tools/dllquery) | 18 | [net/config/tools/dllquery/sources](../../net/config/tools/dllquery/sources), [net/config/tools/dllquery/makefile](../../net/config/tools/dllquery/makefile) | `dllquery` | `PROGRAM` |
| [net/config/tools/enumdevs](../../net/config/tools/enumdevs) | 5 | [net/config/tools/enumdevs/sources](../../net/config/tools/enumdevs/sources), [net/config/tools/enumdevs/makefile](../../net/config/tools/enumdevs/makefile) | `enumdevs` | `PROGRAM` |
| [net/config/tools/icomerge](../../net/config/tools/icomerge) | 8 | [net/config/tools/icomerge/sources](../../net/config/tools/icomerge/sources), [net/config/tools/icomerge/makefile](../../net/config/tools/icomerge/makefile) | `icomerge` | `PROGRAM` |
| [net/config/tools/lanacfg](../../net/config/tools/lanacfg) | 5 | [net/config/tools/lanacfg/sources](../../net/config/tools/lanacfg/sources), [net/config/tools/lanacfg/makefile](../../net/config/tools/lanacfg/makefile) | `lanacfg` | `PROGRAM` |
| [net/config/tools/ncbrowse](../../net/config/tools/ncbrowse) | 29 | [net/config/tools/ncbrowse/sources](../../net/config/tools/ncbrowse/sources), [net/config/tools/ncbrowse/makefile](../../net/config/tools/ncbrowse/makefile) | `ncbrowse` | `PROGRAM` |
| [net/config/tools/ncbrowse/res](../../net/config/tools/ncbrowse/res) | 14 | — | — | — |
| [net/config/tools/ncdiag](../../net/config/tools/ncdiag) | 5 | [net/config/tools/ncdiag/sources](../../net/config/tools/ncdiag/sources), [net/config/tools/ncdiag/makefile](../../net/config/tools/ncdiag/makefile) | `ncdiag` | `PROGRAM` |
| [net/config/tools/netafx](../../net/config/tools/netafx) | 8 | [net/config/tools/netafx/sources](../../net/config/tools/netafx/sources), [net/config/tools/netafx/makefile](../../net/config/tools/netafx/makefile) | `netafx` | `PROGRAM` |
| [net/config/tools/netwiz](../../net/config/tools/netwiz) | 1 | — | — | — |
| [net/config/tools/rasbindc](../../net/config/tools/rasbindc) | 5 | [net/config/tools/rasbindc/sources](../../net/config/tools/rasbindc/sources), [net/config/tools/rasbindc/makefile](../../net/config/tools/rasbindc/makefile) | `rasbindc` | `PROGRAM` |
| [net/config/tools/svchostc](../../net/config/tools/svchostc) | 5 | [net/config/tools/svchostc/sources](../../net/config/tools/svchostc/sources), [net/config/tools/svchostc/makefile](../../net/config/tools/svchostc/makefile) | `svchostc` | `PROGRAM` |
| [net/config/tools/winipcfg](../../net/config/tools/winipcfg) | 5 | [net/config/tools/winipcfg/sources](../../net/config/tools/winipcfg/sources), [net/config/tools/winipcfg/makefile](../../net/config/tools/winipcfg/makefile) | `winipcfg` | `PROGRAM` |
| [net/config/upgrade](../../net/config/upgrade) | 1 | [net/config/upgrade/dirs](../../net/config/upgrade/dirs) | — | — |
| [net/config/upgrade/digiupg](../../net/config/upgrade/digiupg) | 8 | [net/config/upgrade/digiupg/sources](../../net/config/upgrade/digiupg/sources), [net/config/upgrade/digiupg/makefile](../../net/config/upgrade/digiupg/makefile) | `digiupg` | `DYNLINK` |
| [net/config/upgrade/modemshr](../../net/config/upgrade/modemshr) | 1 | [net/config/upgrade/modemshr/dirs](../../net/config/upgrade/modemshr/dirs) | — | — |
| [net/config/upgrade/modemshr/dll](../../net/config/upgrade/modemshr/dll) | 7 | [net/config/upgrade/modemshr/dll/sources](../../net/config/upgrade/modemshr/dll/sources), [net/config/upgrade/modemshr/dll/makefile](../../net/config/upgrade/modemshr/dll/makefile) | `mdmshrup` | `DYNLINK` |
| [net/config/upgrade/modemshr/netmap](../../net/config/upgrade/modemshr/netmap) | 4 | [net/config/upgrade/modemshr/netmap/sources](../../net/config/upgrade/modemshr/netmap/sources), [net/config/upgrade/modemshr/netmap/makefile](../../net/config/upgrade/modemshr/netmap/makefile) | — | `NOTARGET` |
| [net/config/upgrade/netupgrd](../../net/config/upgrade/netupgrd) | 27 | [net/config/upgrade/netupgrd/sources](../../net/config/upgrade/netupgrd/sources), [net/config/upgrade/netupgrd/makefile](../../net/config/upgrade/netupgrd/makefile) | `netupgrd` | `DYNLINK` |
| [net/config/upgrade/nunt4dll](../../net/config/upgrade/nunt4dll) | 3 | [net/config/upgrade/nunt4dll/sources](../../net/config/upgrade/nunt4dll/sources), [net/config/upgrade/nunt4dll/makefile](../../net/config/upgrade/nunt4dll/makefile) | — | `NOTARGET` |
| [net/config/upgrade/nunt4dll/alpha](../../net/config/upgrade/nunt4dll/alpha) | 2 | — | — | — |
| [net/config/upgrade/nunt4dll/i386](../../net/config/upgrade/nunt4dll/i386) | 2 | — | — | — |

## `net/ddk/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/ddk](../../net/ddk) | 4 | [net/ddk/sources](../../net/ddk/sources), [net/ddk/makefile](../../net/ddk/makefile) | — | `NOTARGET` |

## `net/dhcp/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/dhcp](../../net/dhcp) | 1 | [net/dhcp/dirs](../../net/dhcp/dirs) | — | — |
| [net/dhcp/client](../../net/dhcp/client) | 2 | [net/dhcp/client/dirs](../../net/dhcp/client/dirs) | — | — |
| [net/dhcp/client/dhcp](../../net/dhcp/client/dhcp) | 16 | [net/dhcp/client/dhcp/sources](../../net/dhcp/client/dhcp/sources), [net/dhcp/client/dhcp/makefile](../../net/dhcp/client/dhcp/makefile) | `dhcpcli2` | `LIBRARY` |
| [net/dhcp/client/inc](../../net/dhcp/client/inc) | 19 | — | — | — |
| [net/dhcp/client/nt](../../net/dhcp/client/nt) | 35 | [net/dhcp/client/nt/sources](../../net/dhcp/client/nt/sources), [net/dhcp/client/nt/makefile](../../net/dhcp/client/nt/makefile) | `dhcpcsvc` | `DYNLINK` |
| [net/dhcp/client/rogue](../../net/dhcp/client/rogue) | 6 | [net/dhcp/client/rogue/sources](../../net/dhcp/client/rogue/sources), [net/dhcp/client/rogue/makefile](../../net/dhcp/client/rogue/makefile) | `dhcploc` | `PROGRAM` |
| [net/dhcp/dhcpmib](../../net/dhcp/dhcpmib) | 10 | [net/dhcp/dhcpmib/sources](../../net/dhcp/dhcpmib/sources), [net/dhcp/dhcpmib/makefile](../../net/dhcp/dhcpmib/makefile) | `dhcpmib` | `DYNLINK` |
| [net/dhcp/dhcpprov](../../net/dhcp/dhcpprov) | 1 | [net/dhcp/dhcpprov/dirs](../../net/dhcp/dhcpprov/dirs) | — | — |
| [net/dhcp/dhcpprov/dll](../../net/dhcp/dhcpprov/dll) | 23 | [net/dhcp/dhcpprov/dll/sources](../../net/dhcp/dhcpprov/dll/sources), [net/dhcp/dhcpprov/dll/makefile](../../net/dhcp/dhcpprov/dll/makefile) | `dhcpprov` | `DYNLINK` |
| [net/dhcp/dhcpprov/inc](../../net/dhcp/dhcpprov/inc) | 17 | — | — | — |
| [net/dhcp/dhcpprov/mof](../../net/dhcp/dhcpprov/mof) | 2 | — | — | — |
| [net/dhcp/dhcpprov/scripts](../../net/dhcp/dhcpprov/scripts) | 0 | — | — | — |
| [net/dhcp/dhcpprov/scripts/vbscript](../../net/dhcp/dhcpprov/scripts/vbscript) | 1 | — | — | — |
| [net/dhcp/inc](../../net/dhcp/inc) | 7 | — | — | — |
| [net/dhcp/lib](../../net/dhcp/lib) | 8 | [net/dhcp/lib/sources](../../net/dhcp/lib/sources), [net/dhcp/lib/makefile](../../net/dhcp/lib/makefile) | `dhcplib` | `LIBRARY` |
| [net/dhcp/netsh](../../net/dhcp/netsh) | 1 | [net/dhcp/netsh/dirs](../../net/dhcp/netsh/dirs) | — | — |
| [net/dhcp/netsh/common](../../net/dhcp/netsh/common) | 4 | [net/dhcp/netsh/common/sources](../../net/dhcp/netsh/common/sources), [net/dhcp/netsh/common/makefile](../../net/dhcp/netsh/common/makefile) | `common` | `LIBRARY` |
| [net/dhcp/netsh/dhcp](../../net/dhcp/netsh/dhcp) | 18 | [net/dhcp/netsh/dhcp/sources](../../net/dhcp/netsh/dhcp/sources), [net/dhcp/netsh/dhcp/makefile](../../net/dhcp/netsh/dhcp/makefile) | `dhcpmon` | `DYNLINK` |
| [net/dhcp/netsh/inc](../../net/dhcp/netsh/inc) | 11 | — | — | — |
| [net/dhcp/server](../../net/dhcp/server) | 3 | [net/dhcp/server/dirs](../../net/dhcp/server/dirs) | — | — |
| [net/dhcp/server/binl](../../net/dhcp/server/binl) | 29 | [net/dhcp/server/binl/sources](../../net/dhcp/server/binl/sources), [net/dhcp/server/binl/makefile](../../net/dhcp/server/binl/makefile) | `binlsvc` | `DYNLINK` |
| [net/dhcp/server/client](../../net/dhcp/server/client) | 19 | [net/dhcp/server/client/sources](../../net/dhcp/server/client/sources), [net/dhcp/server/client/makefile](../../net/dhcp/server/client/makefile) | `dhcpsapi` | `DYNLINK` |
| [net/dhcp/server/dhcpds](../../net/dhcp/server/dhcpds) | 38 | [net/dhcp/server/dhcpds/sources](../../net/dhcp/server/dhcpds/sources), [net/dhcp/server/dhcpds/makefile](../../net/dhcp/server/dhcpds/makefile) | `dsauth` | `DYNLINK` |
| [net/dhcp/server/dhcpds/test](../../net/dhcp/server/dhcpds/test) | 10 | [net/dhcp/server/dhcpds/test/sources](../../net/dhcp/server/dhcpds/test/sources), [net/dhcp/server/dhcpds/test/makefile](../../net/dhcp/server/dhcpds/test/makefile) | `engine` | `PROGRAM` |
| [net/dhcp/server/dhcpexim](../../net/dhcp/server/dhcpexim) | 23 | [net/dhcp/server/dhcpexim/sources](../../net/dhcp/server/dhcpexim/sources), [net/dhcp/server/dhcpexim/makefile](../../net/dhcp/server/dhcpexim/makefile) | `dhcpexim` | `PROGRAM` |
| [net/dhcp/server/dhcpexim/res](../../net/dhcp/server/dhcpexim/res) | 2 | — | — | — |
| [net/dhcp/server/exim](../../net/dhcp/server/exim) | 15 | [net/dhcp/server/exim/sources](../../net/dhcp/server/exim/sources), [net/dhcp/server/exim/makefile](../../net/dhcp/server/exim/makefile) | `exim` | `LIBRARY` |
| [net/dhcp/server/idl](../../net/dhcp/server/idl) | 4 | — | — | — |
| [net/dhcp/server/mm](../../net/dhcp/server/mm) | 50 | [net/dhcp/server/mm/sources](../../net/dhcp/server/mm/sources), [net/dhcp/server/mm/makefile](../../net/dhcp/server/mm/makefile) | `dhcpmm` | `LIBRARY` |
| [net/dhcp/server/mmreg](../../net/dhcp/server/mmreg) | 17 | [net/dhcp/server/mmreg/sources](../../net/dhcp/server/mmreg/sources), [net/dhcp/server/mmreg/makefile](../../net/dhcp/server/mmreg/makefile) | `dhcpmmreg` | `LIBRARY` |
| [net/dhcp/server/msgs](../../net/dhcp/server/msgs) | 3 | [net/dhcp/server/msgs/sources](../../net/dhcp/server/msgs/sources), [net/dhcp/server/msgs/makefile](../../net/dhcp/server/msgs/makefile) | — | `NOTARGET` |
| [net/dhcp/server/server](../../net/dhcp/server/server) | 80 | [net/dhcp/server/server/sources](../../net/dhcp/server/server/sources), [net/dhcp/server/server/makefile](../../net/dhcp/server/server/makefile) | `dhcpssvc` | `DYNLINK` |
| [net/dhcp/server/server/auditlog](../../net/dhcp/server/server/auditlog) | 8 | [net/dhcp/server/server/auditlog/sources](../../net/dhcp/server/server/auditlog/sources), [net/dhcp/server/server/auditlog/makefile](../../net/dhcp/server/server/auditlog/makefile) | `dhcpslog` | `DYNLINK` |
| [net/dhcp/server/upgrade](../../net/dhcp/server/upgrade) | 9 | [net/dhcp/server/upgrade/sources](../../net/dhcp/server/upgrade/sources), [net/dhcp/server/upgrade/makefile](../../net/dhcp/server/upgrade/makefile) | `dhcpupg` | `LIBRARY` |

## `net/diagnostics/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/diagnostics](../../net/diagnostics) | 2 | [net/diagnostics/dirs](../../net/diagnostics/dirs) | — | — |
| [net/diagnostics/netdiag](../../net/diagnostics/netdiag) | 77 | [net/diagnostics/netdiag/sources](../../net/diagnostics/netdiag/sources), [net/diagnostics/netdiag/makefile](../../net/diagnostics/netdiag/makefile) | `netdiag` | `PROGRAM` |
| [net/diagnostics/netwatch](../../net/diagnostics/netwatch) | 22 | [net/diagnostics/netwatch/sources](../../net/diagnostics/netwatch/sources), [net/diagnostics/netwatch/makefile](../../net/diagnostics/netwatch/makefile) | `netwatch` | `PROGRAM` |
| [net/diagnostics/wmi](../../net/diagnostics/wmi) | 1 | [net/diagnostics/wmi/dirs](../../net/diagnostics/wmi/dirs) | — | — |
| [net/diagnostics/wmi/dglogs](../../net/diagnostics/wmi/dglogs) | 24 | [net/diagnostics/wmi/dglogs/sources](../../net/diagnostics/wmi/dglogs/sources), [net/diagnostics/wmi/dglogs/makefile](../../net/diagnostics/wmi/dglogs/makefile) | `dglogs` | `LIBRARY` |
| [net/diagnostics/wmi/dgnet](../../net/diagnostics/wmi/dgnet) | 34 | [net/diagnostics/wmi/dgnet/sources](../../net/diagnostics/wmi/dgnet/sources), [net/diagnostics/wmi/dgnet/makefile](../../net/diagnostics/wmi/dgnet/makefile) | `dgnet` | `LIBRARY` |
| [net/diagnostics/wmi/dll](../../net/diagnostics/wmi/dll) | 10 | [net/diagnostics/wmi/dll/sources](../../net/diagnostics/wmi/dll/sources), [net/diagnostics/wmi/dll/makefile](../../net/diagnostics/wmi/dll/makefile) | `dgnet` | `DYNLINK` |
| [net/diagnostics/wmi/idl](../../net/diagnostics/wmi/idl) | 3 | [net/diagnostics/wmi/idl/sources](../../net/diagnostics/wmi/idl/sources), [net/diagnostics/wmi/idl/makefile](../../net/diagnostics/wmi/idl/makefile) | — | `NOTARGET` |
| [net/diagnostics/wmi/inc](../../net/diagnostics/wmi/inc) | 2 | — | — | — |

## `net/dlc/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/dlc](../../net/dlc) | 1 | [net/dlc/dirs](../../net/dlc/dirs) | — | — |
| [net/dlc/api](../../net/dlc/api) | 9 | [net/dlc/api/sources](../../net/dlc/api/sources), [net/dlc/api/makefile](../../net/dlc/api/makefile) | `dlcapi` | `DYNLINK` |
| [net/dlc/driver](../../net/dlc/driver) | 48 | [net/dlc/driver/sources](../../net/dlc/driver/sources), [net/dlc/driver/makefile](../../net/dlc/driver/makefile) | `dlc` | `DRIVER` |
| [net/dlc/driver/ia64](../../net/dlc/driver/ia64) | 1 | [net/dlc/driver/ia64/sources](../../net/dlc/driver/ia64/sources) | — | — |

## `net/homenet/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/homenet](../../net/homenet) | 1 | [net/homenet/dirs](../../net/homenet/dirs) | — | — |
| [net/homenet/alg](../../net/homenet/alg) | 5 | [net/homenet/alg/dirs](../../net/homenet/alg/dirs) | — | — |
| [net/homenet/alg/alg_ftp](../../net/homenet/alg/alg_ftp) | 22 | [net/homenet/alg/alg_ftp/sources](../../net/homenet/alg/alg_ftp/sources), [net/homenet/alg/alg_ftp/makefile](../../net/homenet/alg/alg_ftp/makefile) | `ALG_FTP` | `LIBRARY` |
| [net/homenet/alg/alg_icq](../../net/homenet/alg/alg_icq) | 40 | [net/homenet/alg/alg_icq/sources](../../net/homenet/alg/alg_icq/sources), [net/homenet/alg/alg_icq/makefile](../../net/homenet/alg/alg_icq/makefile) | `ALG_ICQ` | `LIBRARY` |
| [net/homenet/alg/alg_test](../../net/homenet/alg/alg_test) | 13 | [net/homenet/alg/alg_test/sources](../../net/homenet/alg/alg_test/sources), [net/homenet/alg/alg_test/makefile](../../net/homenet/alg/alg_test/makefile) | `ALG_TEST` | `DYNLINK` |
| [net/homenet/alg/exe](../../net/homenet/alg/exe) | 49 | [net/homenet/alg/exe/sources](../../net/homenet/alg/exe/sources), [net/homenet/alg/exe/makefile](../../net/homenet/alg/exe/makefile) | `ALG` | `PROGRAM` |
| [net/homenet/alg/idl_private](../../net/homenet/alg/idl_private) | 3 | [net/homenet/alg/idl_private/sources](../../net/homenet/alg/idl_private/sources), [net/homenet/alg/idl_private/makefile](../../net/homenet/alg/idl_private/makefile) | `ALG_Private` | `LIBRARY` |
| [net/homenet/alg/idl_public](../../net/homenet/alg/idl_public) | 3 | [net/homenet/alg/idl_public/sources](../../net/homenet/alg/idl_public/sources), [net/homenet/alg/idl_public/makefile](../../net/homenet/alg/idl_public/makefile) | `ALG_Public` | `LIBRARY` |
| [net/homenet/alg/inc](../../net/homenet/alg/inc) | 1 | — | — | — |
| [net/homenet/beacon](../../net/homenet/beacon) | 1 | [net/homenet/beacon/dirs](../../net/homenet/beacon/dirs) | — | — |
| [net/homenet/beacon/client](../../net/homenet/beacon/client) | 33 | [net/homenet/beacon/client/sources](../../net/homenet/beacon/client/sources), [net/homenet/beacon/client/makefile](../../net/homenet/beacon/client/makefile) | `icsdclt` | `DYNLINK` |
| [net/homenet/beacon/idl](../../net/homenet/beacon/idl) | 16 | [net/homenet/beacon/idl/sources](../../net/homenet/beacon/idl/sources), [net/homenet/beacon/idl/makefile](../../net/homenet/beacon/idl/makefile) | `idl` | `LIBRARY` |
| [net/homenet/beacon/server](../../net/homenet/beacon/server) | 37 | [net/homenet/beacon/server/sources](../../net/homenet/beacon/server/sources), [net/homenet/beacon/server/makefile](../../net/homenet/beacon/server/makefile) | `beacon` | `LIBRARY` |
| [net/homenet/bridge](../../net/homenet/bridge) | 1 | [net/homenet/bridge/dirs](../../net/homenet/bridge/dirs) | — | — |
| [net/homenet/bridge/exe](../../net/homenet/bridge/exe) | 3 | [net/homenet/bridge/exe/sources](../../net/homenet/bridge/exe/sources), [net/homenet/bridge/exe/makefile](../../net/homenet/bridge/exe/makefile) | `bridge` | `PROGRAM` |
| [net/homenet/bridge/inc](../../net/homenet/bridge/inc) | 1 | — | — | — |
| [net/homenet/bridge/inf](../../net/homenet/bridge/inf) | 5 | [net/homenet/bridge/inf/sources](../../net/homenet/bridge/inf/sources), [net/homenet/bridge/inf/makefile](../../net/homenet/bridge/inf/makefile) | `inf` | `NOTARGET` |
| [net/homenet/bridge/sld](../../net/homenet/bridge/sld) | 4 | — | — | — |
| [net/homenet/bridge/sys](../../net/homenet/bridge/sys) | 35 | [net/homenet/bridge/sys/sources](../../net/homenet/bridge/sys/sources), [net/homenet/bridge/sys/makefile](../../net/homenet/bridge/sys/makefile) | `bridge` | `DRIVER` |
| [net/homenet/config](../../net/homenet/config) | 2 | [net/homenet/config/dirs](../../net/homenet/config/dirs) | — | — |
| [net/homenet/config/cfgmgr](../../net/homenet/config/cfgmgr) | 13 | [net/homenet/config/cfgmgr/sources](../../net/homenet/config/cfgmgr/sources), [net/homenet/config/cfgmgr/makefile](../../net/homenet/config/cfgmgr/makefile) | `CfgMgr` | `LIBRARY` |
| [net/homenet/config/dll](../../net/homenet/config/dll) | 44 | [net/homenet/config/dll/sources](../../net/homenet/config/dll/sources), [net/homenet/config/dll/makefile](../../net/homenet/config/dll/makefile) | `HNetCfg` | `DYNLINK` |
| [net/homenet/config/idl](../../net/homenet/config/idl) | 5 | [net/homenet/config/idl/sources](../../net/homenet/config/idl/sources), [net/homenet/config/idl/makefile](../../net/homenet/config/idl/makefile) | `saupdate` | `LIBRARY` |
| [net/homenet/config/inc](../../net/homenet/config/inc) | 26 | — | — | — |
| [net/homenet/config/mof](../../net/homenet/config/mof) | 4 | [net/homenet/config/mof/sources](../../net/homenet/config/mof/sources), [net/homenet/config/mof/makefile](../../net/homenet/config/mof/makefile) | — | `NOTARGET` |
| [net/homenet/config/natupnp](../../net/homenet/config/natupnp) | 14 | [net/homenet/config/natupnp/sources](../../net/homenet/config/natupnp/sources), [net/homenet/config/natupnp/makefile](../../net/homenet/config/natupnp/makefile) | `NATUPnP` | `LIBRARY` |
| [net/homenet/config/sld](../../net/homenet/config/sld) | 2 | — | — | — |
| [net/homenet/fwlogger](../../net/homenet/fwlogger) | 4 | [net/homenet/fwlogger/sources](../../net/homenet/fwlogger/sources), [net/homenet/fwlogger/makefile](../../net/homenet/fwlogger/makefile) | `FwLogger` | `PROGRAM` |
| [net/homenet/netsh](../../net/homenet/netsh) | 16 | [net/homenet/netsh/sources](../../net/homenet/netsh/sources), [net/homenet/netsh/makefile](../../net/homenet/netsh/makefile) | `hnetmon` | `DYNLINK` |

## `net/ias/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/ias](../../net/ias) | 2 | [net/ias/dirs](../../net/ias/dirs) | — | — |
| [net/ias/iasjet](../../net/ias/iasjet) | 1 | [net/ias/iasjet/dirs](../../net/ias/iasjet/dirs) | — | — |
| [net/ias/iasjet/dll](../../net/ias/iasjet/dll) | 8 | [net/ias/iasjet/dll/sources](../../net/ias/iasjet/dll/sources), [net/ias/iasjet/dll/makefile](../../net/ias/iasjet/dll/makefile) | `iasrecst` | `DYNLINK` |
| [net/ias/iasjet/dnary](../../net/ias/iasjet/dnary) | 8 | [net/ias/iasjet/dnary/sources](../../net/ias/iasjet/dnary/sources), [net/ias/iasjet/dnary/makefile](../../net/ias/iasjet/dnary/makefile) | `dnary` | `LIBRARY` |
| [net/ias/iasjet/dstore](../../net/ias/iasjet/dstore) | 23 | [net/ias/iasjet/dstore/sources](../../net/ias/iasjet/dstore/sources), [net/ias/iasjet/dstore/makefile](../../net/ias/iasjet/dstore/makefile) | `dstore` | `LIBRARY` |
| [net/ias/iasjet/inc](../../net/ias/iasjet/inc) | 2 | — | — | — |
| [net/ias/iasjet/netsh](../../net/ias/iasjet/netsh) | 4 | [net/ias/iasjet/netsh/sources](../../net/ias/iasjet/netsh/sources), [net/ias/iasjet/netsh/makefile](../../net/ias/iasjet/netsh/makefile) | `netsh` | `LIBRARY` |
| [net/ias/iasjet/setup](../../net/ias/iasjet/setup) | 41 | [net/ias/iasjet/setup/sources](../../net/ias/iasjet/setup/sources), [net/ias/iasjet/setup/makefile](../../net/ias/iasjet/setup/makefile) | `setup` | `LIBRARY` |
| [net/ias/iasjet/setup/dbhelper](../../net/ias/iasjet/setup/dbhelper) | 16 | — | — | — |
| [net/ias/idl](../../net/ias/idl) | 14 | [net/ias/idl/sources](../../net/ias/idl/sources), [net/ias/idl/makefile](../../net/ias/idl/makefile) | — | `NOTARGET` |
| [net/ias/inc](../../net/ias/inc) | 17 | — | — | — |
| [net/ias/misc](../../net/ias/misc) | 12 | [net/ias/misc/dirs](../../net/ias/misc/dirs) | — | — |
| [net/ias/misc/ara](../../net/ias/misc/ara) | 4 | [net/ias/misc/ara/sources](../../net/ias/misc/ara/sources), [net/ias/misc/ara/makefile](../../net/ias/misc/ara/makefile) | — | — |
| [net/ias/misc/br](../../net/ias/misc/br) | 4 | [net/ias/misc/br/sources](../../net/ias/misc/br/sources), [net/ias/misc/br/makefile](../../net/ias/misc/br/makefile) | — | — |
| [net/ias/misc/chs](../../net/ias/misc/chs) | 4 | [net/ias/misc/chs/sources](../../net/ias/misc/chs/sources), [net/ias/misc/chs/makefile](../../net/ias/misc/chs/makefile) | — | — |
| [net/ias/misc/cht](../../net/ias/misc/cht) | 4 | [net/ias/misc/cht/sources](../../net/ias/misc/cht/sources), [net/ias/misc/cht/makefile](../../net/ias/misc/cht/makefile) | — | — |
| [net/ias/misc/cs](../../net/ias/misc/cs) | 4 | [net/ias/misc/cs/sources](../../net/ias/misc/cs/sources), [net/ias/misc/cs/makefile](../../net/ias/misc/cs/makefile) | — | — |
| [net/ias/misc/da](../../net/ias/misc/da) | 4 | [net/ias/misc/da/sources](../../net/ias/misc/da/sources), [net/ias/misc/da/makefile](../../net/ias/misc/da/makefile) | — | — |
| [net/ias/misc/el](../../net/ias/misc/el) | 4 | [net/ias/misc/el/sources](../../net/ias/misc/el/sources), [net/ias/misc/el/makefile](../../net/ias/misc/el/makefile) | — | — |
| [net/ias/misc/en](../../net/ias/misc/en) | 3 | [net/ias/misc/en/sources](../../net/ias/misc/en/sources), [net/ias/misc/en/makefile](../../net/ias/misc/en/makefile) | — | — |
| [net/ias/misc/es](../../net/ias/misc/es) | 4 | [net/ias/misc/es/sources](../../net/ias/misc/es/sources), [net/ias/misc/es/makefile](../../net/ias/misc/es/makefile) | — | — |
| [net/ias/misc/fi](../../net/ias/misc/fi) | 4 | [net/ias/misc/fi/sources](../../net/ias/misc/fi/sources), [net/ias/misc/fi/makefile](../../net/ias/misc/fi/makefile) | — | — |
| [net/ias/misc/fr](../../net/ias/misc/fr) | 4 | [net/ias/misc/fr/sources](../../net/ias/misc/fr/sources), [net/ias/misc/fr/makefile](../../net/ias/misc/fr/makefile) | — | — |
| [net/ias/misc/ger](../../net/ias/misc/ger) | 4 | [net/ias/misc/ger/sources](../../net/ias/misc/ger/sources), [net/ias/misc/ger/makefile](../../net/ias/misc/ger/makefile) | — | — |
| [net/ias/misc/heb](../../net/ias/misc/heb) | 4 | [net/ias/misc/heb/sources](../../net/ias/misc/heb/sources), [net/ias/misc/heb/makefile](../../net/ias/misc/heb/makefile) | — | — |
| [net/ias/misc/hu](../../net/ias/misc/hu) | 4 | [net/ias/misc/hu/sources](../../net/ias/misc/hu/sources), [net/ias/misc/hu/makefile](../../net/ias/misc/hu/makefile) | — | — |
| [net/ias/misc/it](../../net/ias/misc/it) | 4 | [net/ias/misc/it/sources](../../net/ias/misc/it/sources), [net/ias/misc/it/makefile](../../net/ias/misc/it/makefile) | — | — |
| [net/ias/misc/jpn](../../net/ias/misc/jpn) | 4 | [net/ias/misc/jpn/sources](../../net/ias/misc/jpn/sources), [net/ias/misc/jpn/makefile](../../net/ias/misc/jpn/makefile) | — | — |
| [net/ias/misc/kor](../../net/ias/misc/kor) | 4 | [net/ias/misc/kor/sources](../../net/ias/misc/kor/sources), [net/ias/misc/kor/makefile](../../net/ias/misc/kor/makefile) | — | — |
| [net/ias/misc/nl](../../net/ias/misc/nl) | 4 | [net/ias/misc/nl/sources](../../net/ias/misc/nl/sources), [net/ias/misc/nl/makefile](../../net/ias/misc/nl/makefile) | — | — |
| [net/ias/misc/no](../../net/ias/misc/no) | 4 | [net/ias/misc/no/sources](../../net/ias/misc/no/sources), [net/ias/misc/no/makefile](../../net/ias/misc/no/makefile) | — | — |
| [net/ias/misc/pl](../../net/ias/misc/pl) | 4 | [net/ias/misc/pl/sources](../../net/ias/misc/pl/sources), [net/ias/misc/pl/makefile](../../net/ias/misc/pl/makefile) | — | — |
| [net/ias/misc/psu](../../net/ias/misc/psu) | 3 | [net/ias/misc/psu/sources](../../net/ias/misc/psu/sources), [net/ias/misc/psu/makefile](../../net/ias/misc/psu/makefile) | — | — |
| [net/ias/misc/pt](../../net/ias/misc/pt) | 4 | [net/ias/misc/pt/sources](../../net/ias/misc/pt/sources), [net/ias/misc/pt/makefile](../../net/ias/misc/pt/makefile) | — | — |
| [net/ias/misc/ru](../../net/ias/misc/ru) | 4 | [net/ias/misc/ru/sources](../../net/ias/misc/ru/sources), [net/ias/misc/ru/makefile](../../net/ias/misc/ru/makefile) | — | — |
| [net/ias/misc/sld](../../net/ias/misc/sld) | 15 | [net/ias/misc/sld/sources](../../net/ias/misc/sld/sources), [net/ias/misc/sld/makefile](../../net/ias/misc/sld/makefile) | — | `NOTARGET` |
| [net/ias/misc/sv](../../net/ias/misc/sv) | 4 | [net/ias/misc/sv/sources](../../net/ias/misc/sv/sources), [net/ias/misc/sv/makefile](../../net/ias/misc/sv/makefile) | — | — |
| [net/ias/misc/tr](../../net/ias/misc/tr) | 4 | [net/ias/misc/tr/sources](../../net/ias/misc/tr/sources), [net/ias/misc/tr/makefile](../../net/ias/misc/tr/makefile) | — | — |
| [net/ias/misc/usa](../../net/ias/misc/usa) | 5 | [net/ias/misc/usa/sources](../../net/ias/misc/usa/sources), [net/ias/misc/usa/makefile](../../net/ias/misc/usa/makefile) | — | — |
| [net/ias/mmc](../../net/ias/mmc) | 1 | [net/ias/mmc/dirs](../../net/ias/mmc/dirs) | — | — |
| [net/ias/mmc/atl25](../../net/ias/mmc/atl25) | 1 | — | — | — |
| [net/ias/mmc/common](../../net/ias/mmc/common) | 26 | — | — | — |
| [net/ias/mmc/ias](../../net/ias/mmc/ias) | 107 | [net/ias/mmc/ias/sources](../../net/ias/mmc/ias/sources), [net/ias/mmc/ias/makefile](../../net/ias/mmc/ias/makefile) | `iasmmc` | `DYNLINK` |
| [net/ias/mmc/iasnt4](../../net/ias/mmc/iasnt4) | 5 | [net/ias/mmc/iasnt4/sources](../../net/ias/mmc/iasnt4/sources), [net/ias/mmc/iasnt4/makefile](../../net/ias/mmc/iasnt4/makefile) | `iasnt4` | `NOTARGET` |
| [net/ias/mmc/nap](../../net/ias/mmc/nap) | 171 | [net/ias/mmc/nap/sources](../../net/ias/mmc/nap/sources), [net/ias/mmc/nap/makefile](../../net/ias/mmc/nap/makefile) | `napmmc` | `DYNLINK` |
| [net/ias/mmc/proxy](../../net/ias/mmc/proxy) | 42 | [net/ias/mmc/proxy/sources](../../net/ias/mmc/proxy/sources), [net/ias/mmc/proxy/makefile](../../net/ias/mmc/proxy/makefile) | `iasproxy` | `LIBRARY` |
| [net/ias/policy](../../net/ias/policy) | 1 | [net/ias/policy/dirs](../../net/ias/policy/dirs) | — | — |
| [net/ias/policy/dll_bld](../../net/ias/policy/dll_bld) | 17 | [net/ias/policy/dll_bld/sources](../../net/ias/policy/dll_bld/sources), [net/ias/policy/dll_bld/makefile](../../net/ias/policy/dll_bld/makefile) | `iaspolcy` | `DYNLINK` |
| [net/ias/policy/inc](../../net/ias/policy/inc) | 4 | — | — | — |
| [net/ias/policy/src](../../net/ias/policy/src) | 5 | [net/ias/policy/src/sources](../../net/ias/policy/src/sources), [net/ias/policy/src/makefile](../../net/ias/policy/src/makefile) | `policy` | `LIBRARY` |
| [net/ias/protocol](../../net/ias/protocol) | 1 | [net/ias/protocol/dirs](../../net/ias/protocol/dirs) | — | — |
| [net/ias/protocol/proxy](../../net/ias/protocol/proxy) | 31 | [net/ias/protocol/proxy/sources](../../net/ias/protocol/proxy/sources), [net/ias/protocol/proxy/makefile](../../net/ias/protocol/proxy/makefile) | `proxy` | `LIBRARY` |
| [net/ias/protocol/radius](../../net/ias/protocol/radius) | 87 | [net/ias/protocol/radius/sources](../../net/ias/protocol/radius/sources), [net/ias/protocol/radius/makefile](../../net/ias/protocol/radius/makefile) | `iasrad` | `DYNLINK` |
| [net/ias/providers](../../net/ias/providers) | 1 | [net/ias/providers/dirs](../../net/ias/providers/dirs) | — | — |
| [net/ias/providers/accounting](../../net/ias/providers/accounting) | 18 | [net/ias/providers/accounting/sources](../../net/ias/providers/accounting/sources), [net/ias/providers/accounting/makefile](../../net/ias/providers/accounting/makefile) | `iasacct` | `DYNLINK` |
| [net/ias/providers/nap](../../net/ias/providers/nap) | 1 | [net/ias/providers/nap/dirs](../../net/ias/providers/nap/dirs) | — | — |
| [net/ias/providers/nap/cond](../../net/ias/providers/nap/cond) | 14 | [net/ias/providers/nap/cond/sources](../../net/ias/providers/nap/cond/sources), [net/ias/providers/nap/cond/makefile](../../net/ias/providers/nap/cond/makefile) | `cond` | `LIBRARY` |
| [net/ias/providers/nap/dll](../../net/ias/providers/nap/dll) | 17 | [net/ias/providers/nap/dll/sources](../../net/ias/providers/nap/dll/sources), [net/ias/providers/nap/dll/makefile](../../net/ias/providers/nap/dll/makefile) | `iasnap` | `DYNLINK` |
| [net/ias/providers/nap/flex](../../net/ias/providers/nap/flex) | 5 | [net/ias/providers/nap/flex/sources](../../net/ias/providers/nap/flex/sources), [net/ias/providers/nap/flex/makefile](../../net/ias/providers/nap/flex/makefile) | `flex` | `LIBRARY` |
| [net/ias/providers/nap/inc](../../net/ias/providers/nap/inc) | 2 | — | — | — |
| [net/ias/providers/nap/regex](../../net/ias/providers/nap/regex) | 12 | [net/ias/providers/nap/regex/sources](../../net/ias/providers/nap/regex/sources), [net/ias/providers/nap/regex/makefile](../../net/ias/providers/nap/regex/makefile) | `regex` | `LIBRARY` |
| [net/ias/providers/nap/tree](../../net/ias/providers/nap/tree) | 5 | [net/ias/providers/nap/tree/sources](../../net/ias/providers/nap/tree/sources), [net/ias/providers/nap/tree/makefile](../../net/ias/providers/nap/tree/makefile) | `tree` | `LIBRARY` |
| [net/ias/providers/ntuser](../../net/ias/providers/ntuser) | 1 | [net/ias/providers/ntuser/dirs](../../net/ias/providers/ntuser/dirs) | — | — |
| [net/ias/providers/ntuser/auth](../../net/ias/providers/ntuser/auth) | 19 | [net/ias/providers/ntuser/auth/sources](../../net/ias/providers/ntuser/auth/sources), [net/ias/providers/ntuser/auth/makefile](../../net/ias/providers/ntuser/auth/makefile) | `auth` | `LIBRARY` |
| [net/ias/providers/ntuser/basecamp](../../net/ias/providers/ntuser/basecamp) | 7 | [net/ias/providers/ntuser/basecamp/sources](../../net/ias/providers/ntuser/basecamp/sources), [net/ias/providers/ntuser/basecamp/makefile](../../net/ias/providers/ntuser/basecamp/makefile) | `basecamp` | `LIBRARY` |
| [net/ias/providers/ntuser/dll](../../net/ias/providers/ntuser/dll) | 6 | [net/ias/providers/ntuser/dll/sources](../../net/ias/providers/ntuser/dll/sources), [net/ias/providers/ntuser/dll/makefile](../../net/ias/providers/ntuser/dll/makefile) | `iassam` | `DYNLINK` |
| [net/ias/providers/ntuser/eap](../../net/ias/providers/ntuser/eap) | 18 | [net/ias/providers/ntuser/eap/sources](../../net/ias/providers/ntuser/eap/sources), [net/ias/providers/ntuser/eap/makefile](../../net/ias/providers/ntuser/eap/makefile) | `eap` | `LIBRARY` |
| [net/ias/providers/ntuser/inc](../../net/ias/providers/ntuser/inc) | 5 | — | — | — |
| [net/ias/providers/ntuser/ldap](../../net/ias/providers/ntuser/ldap) | 15 | [net/ias/providers/ntuser/ldap/sources](../../net/ias/providers/ntuser/ldap/sources), [net/ias/providers/ntuser/ldap/makefile](../../net/ias/providers/ntuser/ldap/makefile) | `ldap` | `LIBRARY` |
| [net/ias/providers/ntuser/lsa](../../net/ias/providers/ntuser/lsa) | 12 | [net/ias/providers/ntuser/lsa/sources](../../net/ias/providers/ntuser/lsa/sources), [net/ias/providers/ntuser/lsa/makefile](../../net/ias/providers/ntuser/lsa/makefile) | `lsa` | `LIBRARY` |
| [net/ias/providers/ntuser/names](../../net/ias/providers/ntuser/names) | 6 | [net/ias/providers/ntuser/names/sources](../../net/ias/providers/ntuser/names/sources), [net/ias/providers/ntuser/names/makefile](../../net/ias/providers/ntuser/names/makefile) | `names` | `LIBRARY` |
| [net/ias/providers/ntuser/peruser](../../net/ias/providers/ntuser/peruser) | 14 | [net/ias/providers/ntuser/peruser/sources](../../net/ias/providers/ntuser/peruser/sources), [net/ias/providers/ntuser/peruser/makefile](../../net/ias/providers/ntuser/peruser/makefile) | `peruser` | `LIBRARY` |
| [net/ias/rasserver](../../net/ias/rasserver) | 11 | [net/ias/rasserver/sources](../../net/ias/rasserver/sources), [net/ias/rasserver/makefile](../../net/ias/rasserver/makefile) | `iashlpr` | `DYNLINK` |
| [net/ias/sdo](../../net/ias/sdo) | 1 | [net/ias/sdo/dirs](../../net/ias/sdo/dirs) | — | — |
| [net/ias/sdo/datastore2](../../net/ias/sdo/datastore2) | 1 | [net/ias/sdo/datastore2/dirs](../../net/ias/sdo/datastore2/dirs) | — | — |
| [net/ias/sdo/datastore2/adsi](../../net/ias/sdo/datastore2/adsi) | 11 | [net/ias/sdo/datastore2/adsi/sources](../../net/ias/sdo/datastore2/adsi/sources), [net/ias/sdo/datastore2/adsi/makefile](../../net/ias/sdo/datastore2/adsi/makefile) | `iasads` | `DYNLINK` |
| [net/ias/sdo/datastore2/inc](../../net/ias/sdo/datastore2/inc) | 4 | — | — | — |
| [net/ias/sdo/datastore2/net](../../net/ias/sdo/datastore2/net) | 17 | [net/ias/sdo/datastore2/net/sources](../../net/ias/sdo/datastore2/net/sources), [net/ias/sdo/datastore2/net/makefile](../../net/ias/sdo/datastore2/net/makefile) | `net` | `LIBRARY` |
| [net/ias/sdo/datastore2/oledb](../../net/ias/sdo/datastore2/oledb) | 27 | [net/ias/sdo/datastore2/oledb/sources](../../net/ias/sdo/datastore2/oledb/sources), [net/ias/sdo/datastore2/oledb/makefile](../../net/ias/sdo/datastore2/oledb/makefile) | `oledb` | `LIBRARY` |
| [net/ias/sdo/sdoias](../../net/ias/sdo/sdoias) | 69 | [net/ias/sdo/sdoias/sources](../../net/ias/sdo/sdoias/sources), [net/ias/sdo/sdoias/makefile](../../net/ias/sdo/sdoias/makefile) | `iassdo` | `DYNLINK` |
| [net/ias/services](../../net/ias/services) | 1 | [net/ias/services/dirs](../../net/ias/services/dirs) | — | — |
| [net/ias/services/auditor](../../net/ias/services/auditor) | 14 | [net/ias/services/auditor/sources](../../net/ias/services/auditor/sources), [net/ias/services/auditor/makefile](../../net/ias/services/auditor/makefile) | `auditor` | `LIBRARY` |
| [net/ias/services/dictionary](../../net/ias/services/dictionary) | 6 | [net/ias/services/dictionary/sources](../../net/ias/services/dictionary/sources), [net/ias/services/dictionary/makefile](../../net/ias/services/dictionary/makefile) | `dictionary` | `LIBRARY` |
| [net/ias/services/dll_bld](../../net/ias/services/dll_bld) | 7 | [net/ias/services/dll_bld/sources](../../net/ias/services/dll_bld/sources), [net/ias/services/dll_bld/makefile](../../net/ias/services/dll_bld/makefile) | `iassvcs` | `DYNLINK` |
| [net/ias/services/inc](../../net/ias/services/inc) | 21 | — | — | — |
| [net/ias/services/msgtbl](../../net/ias/services/msgtbl) | 3 | [net/ias/services/msgtbl/sources](../../net/ias/services/msgtbl/sources), [net/ias/services/msgtbl/makefile](../../net/ias/services/msgtbl/makefile) | `msgtbl` | `NOTARGET` |
| [net/ias/services/thrdpool](../../net/ias/services/thrdpool) | 5 | [net/ias/services/thrdpool/sources](../../net/ias/services/thrdpool/sources), [net/ias/services/thrdpool/makefile](../../net/ias/services/thrdpool/makefile) | `thrdpool` | `LIBRARY` |
| [net/ias/services/util](../../net/ias/services/util) | 15 | [net/ias/services/util/sources](../../net/ias/services/util/sources), [net/ias/services/util/makefile](../../net/ias/services/util/makefile) | `iasutil` | `LIBRARY` |
| [net/ias/system](../../net/ias/system) | 1 | [net/ias/system/dirs](../../net/ias/system/dirs) | — | — |
| [net/ias/system/ias](../../net/ias/system/ias) | 9 | [net/ias/system/ias/sources](../../net/ias/system/ias/sources), [net/ias/system/ias/makefile](../../net/ias/system/ias/makefile) | `ias` | `DYNLINK` |
| [net/ias/system/perfmon](../../net/ias/system/perfmon) | 22 | [net/ias/system/perfmon/sources](../../net/ias/system/perfmon/sources), [net/ias/system/perfmon/makefile](../../net/ias/system/perfmon/makefile) | `iasperf` | `DYNLINK` |
| [net/ias/uuid](../../net/ias/uuid) | 3 | [net/ias/uuid/sources](../../net/ias/uuid/sources), [net/ias/uuid/makefile](../../net/ias/uuid/makefile) | `iasuuid` | `LIBRARY` |

## `net/inc/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/inc](../../net/inc) | 68 | — | — | — |

## `net/ipsec/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/ipsec](../../net/ipsec) | 1 | [net/ipsec/dirs](../../net/ipsec/dirs) | — | — |
| [net/ipsec/componentdef](../../net/ipsec/componentdef) | 6 | [net/ipsec/componentdef/sources](../../net/ipsec/componentdef/sources), [net/ipsec/componentdef/makefile](../../net/ipsec/componentdef/makefile) | — | `NOTARGET` |
| [net/ipsec/inc](../../net/ipsec/inc) | 4 | — | — | — |
| [net/ipsec/ipseccmd](../../net/ipsec/ipseccmd) | 26 | [net/ipsec/ipseccmd/sources](../../net/ipsec/ipseccmd/sources), [net/ipsec/ipseccmd/makefile](../../net/ipsec/ipseccmd/makefile) | `ipseccmd` | `PROGRAM` |
| [net/ipsec/ipsecshr](../../net/ipsec/ipsecshr) | 6 | [net/ipsec/ipsecshr/sources](../../net/ipsec/ipsecshr/sources), [net/ipsec/ipsecshr/makefile](../../net/ipsec/ipsecshr/makefile) | `ipsecshr` | `LIBRARY` |
| [net/ipsec/pastore](../../net/ipsec/pastore) | 19 | [net/ipsec/pastore/sources](../../net/ipsec/pastore/sources), [net/ipsec/pastore/makefile](../../net/ipsec/pastore/makefile) | `pastore` | `LIBRARY` |
| [net/ipsec/polstore](../../net/ipsec/polstore) | 62 | [net/ipsec/polstore/sources](../../net/ipsec/polstore/sources), [net/ipsec/polstore/makefile](../../net/ipsec/polstore/makefile) | `polstore` | `DYNLINK` |
| [net/ipsec/spd](../../net/ipsec/spd) | 1 | [net/ipsec/spd/dirs](../../net/ipsec/spd/dirs) | — | — |
| [net/ipsec/spd/client](../../net/ipsec/spd/client) | 16 | [net/ipsec/spd/client/sources](../../net/ipsec/spd/client/sources), [net/ipsec/spd/client/makefile](../../net/ipsec/spd/client/makefile) | `winipsec` | `DYNLINK` |
| [net/ipsec/spd/idl](../../net/ipsec/spd/idl) | 8 | [net/ipsec/spd/idl/sources](../../net/ipsec/spd/idl/sources), [net/ipsec/spd/idl/makefile](../../net/ipsec/spd/idl/makefile) | — | `NOTARGET` |
| [net/ipsec/spd/server](../../net/ipsec/spd/server) | 99 | [net/ipsec/spd/server/sources](../../net/ipsec/spd/server/sources), [net/ipsec/spd/server/makefile](../../net/ipsec/spd/server/makefile) | `ipsecsvc` | `DYNLINK` |

## `net/irda/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/irda](../../net/irda) | 1 | [net/irda/dirs](../../net/irda/dirs) | — | — |
| [net/irda/comm](../../net/irda/comm) | 1 | [net/irda/comm/dirs](../../net/irda/comm/dirs) | — | — |
| [net/irda/comm/inc](../../net/irda/comm/inc) | 8 | — | — | — |
| [net/irda/comm/inf](../../net/irda/comm/inf) | 4 | [net/irda/comm/inf/sources](../../net/irda/comm/inf/sources), [net/irda/comm/inf/makefile](../../net/irda/comm/inf/makefile) | `inf` | `notarget` |
| [net/irda/comm/ircomm](../../net/irda/comm/ircomm) | 16 | [net/irda/comm/ircomm/sources](../../net/irda/comm/ircomm/sources), [net/irda/comm/ircomm/makefile](../../net/irda/comm/ircomm/makefile) | `msircomm` | `DRIVER` |
| [net/irda/comm/irenum](../../net/irda/comm/irenum) | 10 | [net/irda/comm/irenum/sources](../../net/irda/comm/irenum/sources), [net/irda/comm/irenum/makefile](../../net/irda/comm/irenum/makefile) | `irenum` | `DRIVER` |
| [net/irda/comm/link](../../net/irda/comm/link) | 4 | [net/irda/comm/link/sources](../../net/irda/comm/link/sources), [net/irda/comm/link/makefile](../../net/irda/comm/link/makefile) | `irlink` | `DRIVER_LIBRARY` |
| [net/irda/comm/util](../../net/irda/comm/util) | 5 | [net/irda/comm/util/sources](../../net/irda/comm/util/sources), [net/irda/comm/util/makefile](../../net/irda/comm/util/makefile) | `irutils` | `DRIVER_LIBRARY` |
| [net/irda/comm/vuart](../../net/irda/comm/vuart) | 6 | [net/irda/comm/vuart/sources](../../net/irda/comm/vuart/sources), [net/irda/comm/vuart/makefile](../../net/irda/comm/vuart/makefile) | `vuart` | `DRIVER_LIBRARY` |
| [net/irda/dbgcon](../../net/irda/dbgcon) | 3 | [net/irda/dbgcon/sources](../../net/irda/dbgcon/sources), [net/irda/dbgcon/makefile](../../net/irda/dbgcon/makefile) | `dbgcon` | `PROGRAM` |
| [net/irda/eventlog](../../net/irda/eventlog) | 6 | [net/irda/eventlog/sources](../../net/irda/eventlog/sources), [net/irda/eventlog/makefile](../../net/irda/eventlog/makefile) | `eventlog` | `LIBRARY` |
| [net/irda/hint](../../net/irda/hint) | 4 | [net/irda/hint/sources](../../net/irda/hint/sources), [net/irda/hint/makefile](../../net/irda/hint/makefile) | `hint` | `PROGRAM` |
| [net/irda/idl](../../net/irda/idl) | 9 | [net/irda/idl/sources](../../net/irda/idl/sources), [net/irda/idl/makefile](../../net/irda/idl/makefile) | `irstubs` | `LIBRARY` |
| [net/irda/inc](../../net/irda/inc) | 15 | — | — | — |
| [net/irda/irclass](../../net/irda/irclass) | 10 | [net/irda/irclass/sources](../../net/irda/irclass/sources), [net/irda/irclass/makefile](../../net/irda/irclass/makefile) | `irclass` | `DYNLINK` |
| [net/irda/irenum](../../net/irda/irenum) | 2 | [net/irda/irenum/sources](../../net/irda/irenum/sources) | `irenum` | `DRIVER` |
| [net/irda/irftp](../../net/irda/irftp) | 32 | [net/irda/irftp/sources](../../net/irda/irftp/sources), [net/irda/irftp/makefile](../../net/irda/irftp/makefile) | `irftp` | `PROGRAM` |
| [net/irda/irftp/res](../../net/irda/irftp/res) | 4 | — | — | — |
| [net/irda/irlap](../../net/irda/irlap) | 8 | [net/irda/irlap/sources](../../net/irda/irlap/sources), [net/irda/irlap/makefile](../../net/irda/irlap/makefile) | `irlap` | `LIBRARY` |
| [net/irda/irlmp](../../net/irda/irlmp) | 4 | [net/irda/irlmp/sources](../../net/irda/irlmp/sources), [net/irda/irlmp/makefile](../../net/irda/irlmp/makefile) | `irlmp` | `LIBRARY` |
| [net/irda/irmon](../../net/irda/irmon) | 21 | [net/irda/irmon/sources](../../net/irda/irmon/sources), [net/irda/irmon/makefile](../../net/irda/irmon/makefile) | `irmon` | `DYNLINK` |
| [net/irda/irprops](../../net/irda/irprops) | 28 | [net/irda/irprops/sources](../../net/irda/irprops/sources), [net/irda/irprops/makefile](../../net/irda/irprops/makefile) | `irprops` | `DYNLINK` |
| [net/irda/irprops/res](../../net/irda/irprops/res) | 2 | — | — | — |
| [net/irda/irsir](../../net/irda/irsir) | 36 | [net/irda/irsir/sources](../../net/irda/irsir/sources), [net/irda/irsir/makefile](../../net/irda/irsir/makefile) | `irsir` | `DRIVER` |
| [net/irda/irtdicl](../../net/irda/irtdicl) | 5 | [net/irda/irtdicl/sources](../../net/irda/irtdicl/sources), [net/irda/irtdicl/makefile](../../net/irda/irtdicl/makefile) | `irtdicl` | `DRIVER_LIBRARY` |
| [net/irda/irtranp](../../net/irda/irtranp) | 18 | [net/irda/irtranp/sources](../../net/irda/irtranp/sources), [net/irda/irtranp/makefile](../../net/irda/irtranp/makefile) | `irtranp` | `LIBRARY` |
| [net/irda/irutil](../../net/irda/irutil) | 7 | [net/irda/irutil/sources](../../net/irda/irutil/sources), [net/irda/irutil/makefile](../../net/irda/irutil/makefile) | `irutil` | `LIBRARY` |
| [net/irda/irxfer](../../net/irda/irxfer) | 32 | [net/irda/irxfer/sources](../../net/irda/irxfer/sources), [net/irda/irxfer/makefile](../../net/irda/irxfer/makefile) | `irxfer` | `LIBRARY` |
| [net/irda/kdext](../../net/irda/kdext) | 5 | [net/irda/kdext/sources](../../net/irda/kdext/sources), [net/irda/kdext/makefile](../../net/irda/kdext/makefile) | `irdakdx` | `DYNLINK` |
| [net/irda/rasirda](../../net/irda/rasirda) | 6 | [net/irda/rasirda/sources](../../net/irda/rasirda/sources), [net/irda/rasirda/makefile](../../net/irda/rasirda/makefile) | `rasirda` | `DRIVER` |
| [net/irda/samples](../../net/irda/samples) | 1 | [net/irda/samples/dirs](../../net/irda/samples/dirs) | — | — |
| [net/irda/samples/blaster](../../net/irda/samples/blaster) | 7 | [net/irda/samples/blaster/sources](../../net/irda/samples/blaster/sources), [net/irda/samples/blaster/makefile](../../net/irda/samples/blaster/makefile) | `blaster` | `PROGRAM` |
| [net/irda/samples/nscirda](../../net/irda/samples/nscirda) | 34 | [net/irda/samples/nscirda/sources](../../net/irda/samples/nscirda/sources), [net/irda/samples/nscirda/makefile](../../net/irda/samples/nscirda/makefile) | `nscirda` | `DRIVER` |
| [net/irda/sys](../../net/irda/sys) | 7 | [net/irda/sys/sources](../../net/irda/sys/sources), [net/irda/sys/makefile](../../net/irda/sys/makefile) | `irda` | `DRIVER` |
| [net/irda/winsock](../../net/irda/winsock) | 5 | [net/irda/winsock/sources](../../net/irda/winsock/sources), [net/irda/winsock/makefile](../../net/irda/winsock/makefile) | `wshirda` | `DYNLINK` |

## `net/jet500/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/jet500](../../net/jet500) | 1 | [net/jet500/dirs](../../net/jet500/dirs) | — | — |
| [net/jet500/inc](../../net/jet500/inc) | 2 | — | — | — |
| [net/jet500/jet](../../net/jet500/jet) | 2 | [net/jet500/jet/dirs](../../net/jet500/jet/dirs) | — | — |
| [net/jet500/jet/dae](../../net/jet500/jet/dae) | 1 | [net/jet500/jet/dae/dirs](../../net/jet500/jet/dae/dirs) | — | — |
| [net/jet500/jet/dae/inc](../../net/jet500/jet/dae/inc) | 38 | — | — | — |
| [net/jet500/jet/dae/src](../../net/jet500/jet/dae/src) | 48 | [net/jet500/jet/dae/src/sources](../../net/jet500/jet/dae/src/sources), [net/jet500/jet/dae/src/makefile](../../net/jet500/jet/dae/src/makefile) | `DAE` | `LIBRARY` |
| [net/jet500/jet/jet](../../net/jet500/jet/jet) | 1 | [net/jet500/jet/jet/dirs](../../net/jet500/jet/jet/dirs) | — | — |
| [net/jet500/jet/jet/compact](../../net/jet500/jet/jet/compact) | 8 | [net/jet500/jet/jet/compact/sources](../../net/jet500/jet/jet/compact/sources), [net/jet500/jet/jet/compact/makefile](../../net/jet500/jet/jet/compact/makefile) | `jetpack` | `PROGRAM` |
| [net/jet500/jet/jet/inc](../../net/jet500/jet/jet/inc) | 27 | — | — | — |
| [net/jet500/jet/jet/src](../../net/jet500/jet/jet/src) | 22 | [net/jet500/jet/jet/src/sources](../../net/jet500/jet/jet/src/sources), [net/jet500/jet/jet/src/makefile](../../net/jet500/jet/jet/src/makefile) | `jet` | `DYNLINK` |
| [net/jet500/jetconv](../../net/jet500/jetconv) | 9 | [net/jet500/jetconv/sources](../../net/jet500/jetconv/sources), [net/jet500/jetconv/makefile](../../net/jet500/jetconv/makefile) | `jetconv` | `PROGRAM` |
| [net/jet500/xjet](../../net/jet500/xjet) | 1 | [net/jet500/xjet/dirs](../../net/jet500/xjet/dirs) | — | — |
| [net/jet500/xjet/inc](../../net/jet500/xjet/inc) | 59 | — | — | — |
| [net/jet500/xjet/src](../../net/jet500/xjet/src) | 66 | [net/jet500/xjet/src/dirs](../../net/jet500/xjet/src/dirs) | — | — |
| [net/jet500/xjet/src/convert](../../net/jet500/xjet/src/convert) | 5 | [net/jet500/xjet/src/convert/sources](../../net/jet500/xjet/src/convert/sources), [net/jet500/xjet/src/convert/makefile](../../net/jet500/xjet/src/convert/makefile) | `upg351db` | `PROGRAM` |
| [net/jet500/xjet/src/jet500](../../net/jet500/xjet/src/jet500) | 4 | [net/jet500/xjet/src/jet500/sources](../../net/jet500/xjet/src/jet500/sources), [net/jet500/xjet/src/jet500/makefile](../../net/jet500/xjet/src/jet500/makefile) | `jet500` | `DYNLINK` |
| [net/jet500/xjet/src/lang](../../net/jet500/xjet/src/lang) | 0 | — | — | — |
| [net/jet500/xjet/src/lang/usa](../../net/jet500/xjet/src/lang/usa) | 1 | — | — | — |
| [net/jet500/xjet/src/msg1](../../net/jet500/xjet/src/msg1) | 5 | [net/jet500/xjet/src/msg1/sources](../../net/jet500/xjet/src/msg1/sources), [net/jet500/xjet/src/msg1/makefile](../../net/jet500/xjet/src/msg1/makefile) | `convmsg` | `DYNLINK` |

## `net/layer2svc/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/layer2svc](../../net/layer2svc) | 1 | [net/layer2svc/dirs](../../net/layer2svc/dirs) | — | — |
| [net/layer2svc/componentdef](../../net/layer2svc/componentdef) | 4 | [net/layer2svc/componentdef/sources](../../net/layer2svc/componentdef/sources), [net/layer2svc/componentdef/makefile](../../net/layer2svc/componentdef/makefile) | — | `NOTARGET` |
| [net/layer2svc/crypt](../../net/layer2svc/crypt) | 1 | [net/layer2svc/crypt/dirs](../../net/layer2svc/crypt/dirs) | — | — |
| [net/layer2svc/crypt/src](../../net/layer2svc/crypt/src) | 8 | [net/layer2svc/crypt/src/sources](../../net/layer2svc/crypt/src/sources), [net/layer2svc/crypt/src/makefile](../../net/layer2svc/crypt/src/makefile) | `wzccrypt` | `LIBRARY` |
| [net/layer2svc/dialog](../../net/layer2svc/dialog) | 27 | [net/layer2svc/dialog/sources](../../net/layer2svc/dialog/sources), [net/layer2svc/dialog/makefile](../../net/layer2svc/dialog/makefile) | `wzcdlg` | `DYNLINK` |
| [net/layer2svc/dialog/res](../../net/layer2svc/dialog/res) | 1 | — | — | — |
| [net/layer2svc/eapol](../../net/layer2svc/eapol) | 1 | [net/layer2svc/eapol/dirs](../../net/layer2svc/eapol/dirs) | — | — |
| [net/layer2svc/eapol/inf](../../net/layer2svc/eapol/inf) | 4 | [net/layer2svc/eapol/inf/sources](../../net/layer2svc/eapol/inf/sources), [net/layer2svc/eapol/inf/makefile](../../net/layer2svc/eapol/inf/makefile) | `inf` | `notarget` |
| [net/layer2svc/eapol/parser](../../net/layer2svc/eapol/parser) | 8 | [net/layer2svc/eapol/parser/sources](../../net/layer2svc/eapol/parser/sources), [net/layer2svc/eapol/parser/makefile](../../net/layer2svc/eapol/parser/makefile) | `nmeapol` | `DYNLINK` |
| [net/layer2svc/eapol/service](../../net/layer2svc/eapol/service) | 42 | [net/layer2svc/eapol/service/sources](../../net/layer2svc/eapol/service/sources), [net/layer2svc/eapol/service/makefile](../../net/layer2svc/eapol/service/makefile) | `eapol` | `LIBRARY` |
| [net/layer2svc/inc](../../net/layer2svc/inc) | 9 | — | — | — |
| [net/layer2svc/monitor](../../net/layer2svc/monitor) | 1 | [net/layer2svc/monitor/dirs](../../net/layer2svc/monitor/dirs) | — | — |
| [net/layer2svc/monitor/database](../../net/layer2svc/monitor/database) | 9 | [net/layer2svc/monitor/database/sources](../../net/layer2svc/monitor/database/sources), [net/layer2svc/monitor/database/makefile](../../net/layer2svc/monitor/database/makefile) | `appmon` | `LIBRARY` |
| [net/layer2svc/monitor/inc](../../net/layer2svc/monitor/inc) | 1 | — | — | — |
| [net/layer2svc/wastore](../../net/layer2svc/wastore) | 23 | [net/layer2svc/wastore/sources](../../net/layer2svc/wastore/sources), [net/layer2svc/wastore/makefile](../../net/layer2svc/wastore/makefile) | `wastore` | `LIBRARY` |
| [net/layer2svc/wlpolicy](../../net/layer2svc/wlpolicy) | 28 | [net/layer2svc/wlpolicy/sources](../../net/layer2svc/wlpolicy/sources), [net/layer2svc/wlpolicy/makefile](../../net/layer2svc/wlpolicy/makefile) | `wlpolicy` | `LIBRARY` |
| [net/layer2svc/wlsnp](../../net/layer2svc/wlsnp) | 60 | [net/layer2svc/wlsnp/sources](../../net/layer2svc/wlsnp/sources), [net/layer2svc/wlsnp/makefile](../../net/layer2svc/wlsnp/makefile) | `wlsnp` | `DYNLINK` |
| [net/layer2svc/wlsnp/bmp](../../net/layer2svc/wlsnp/bmp) | 18 | — | — | — |
| [net/layer2svc/wlsnp/ico](../../net/layer2svc/wlsnp/ico) | 19 | — | — | — |
| [net/layer2svc/wlstore](../../net/layer2svc/wlstore) | 23 | [net/layer2svc/wlstore/sources](../../net/layer2svc/wlstore/sources), [net/layer2svc/wlstore/makefile](../../net/layer2svc/wlstore/makefile) | `wlstore` | `LIBRARY` |
| [net/layer2svc/zeroconf](../../net/layer2svc/zeroconf) | 1 | [net/layer2svc/zeroconf/dirs](../../net/layer2svc/zeroconf/dirs) | — | — |
| [net/layer2svc/zeroconf/client](../../net/layer2svc/zeroconf/client) | 12 | [net/layer2svc/zeroconf/client/sources](../../net/layer2svc/zeroconf/client/sources), [net/layer2svc/zeroconf/client/makefile](../../net/layer2svc/zeroconf/client/makefile) | `wzcsapi` | `DYNLINK` |
| [net/layer2svc/zeroconf/cmdtool](../../net/layer2svc/zeroconf/cmdtool) | 17 | [net/layer2svc/zeroconf/cmdtool/sources](../../net/layer2svc/zeroconf/cmdtool/sources), [net/layer2svc/zeroconf/cmdtool/makefile](../../net/layer2svc/zeroconf/cmdtool/makefile) | `wzctool` | `PROGRAM` |
| [net/layer2svc/zeroconf/idl](../../net/layer2svc/zeroconf/idl) | 5 | — | — | — |
| [net/layer2svc/zeroconf/server](../../net/layer2svc/zeroconf/server) | 27 | [net/layer2svc/zeroconf/server/sources](../../net/layer2svc/zeroconf/server/sources), [net/layer2svc/zeroconf/server/makefile](../../net/layer2svc/zeroconf/server/makefile) | `wzcsvc` | `DYNLINK` |
| [net/layer2svc/zeroconf/server/resources](../../net/layer2svc/zeroconf/server/resources) | 4 | — | — | — |
| [net/layer2svc/zeroconf/service](../../net/layer2svc/zeroconf/service) | 6 | [net/layer2svc/zeroconf/service/sources](../../net/layer2svc/zeroconf/service/sources), [net/layer2svc/zeroconf/service/makefile](../../net/layer2svc/zeroconf/service/makefile) | `wzerocnf` | `PROGRAM` |

## `net/lib/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/lib](../../net/lib) | 1 | — | — | — |

## `net/mcast/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/mcast](../../net/mcast) | 1 | [net/mcast/dirs](../../net/mcast/dirs) | — | — |
| [net/mcast/pgm](../../net/mcast/pgm) | 1 | [net/mcast/pgm/dirs](../../net/mcast/pgm/dirs) | — | — |
| [net/mcast/pgm/dll](../../net/mcast/pgm/dll) | 5 | [net/mcast/pgm/dll/sources](../../net/mcast/pgm/dll/sources), [net/mcast/pgm/dll/makefile](../../net/mcast/pgm/dll/makefile) | `wshrm` | `DYNLINK` |
| [net/mcast/pgm/inc](../../net/mcast/pgm/inc) | 3 | — | — | — |
| [net/mcast/pgm/sys](../../net/mcast/pgm/sys) | 17 | [net/mcast/pgm/sys/sources](../../net/mcast/pgm/sys/sources), [net/mcast/pgm/sys/makefile](../../net/mcast/pgm/sys/makefile) | `rmcast` | `DRIVER` |
| [net/mcast/pgm/sys/amd64](../../net/mcast/pgm/sys/amd64) | 1 | — | — | — |
| [net/mcast/pgm/sys/i386](../../net/mcast/pgm/sys/i386) | 1 | — | — | — |
| [net/mcast/pgm/sys/ia64](../../net/mcast/pgm/sys/ia64) | 1 | — | — | — |
| [net/mcast/pgm/test](../../net/mcast/pgm/test) | 3 | [net/mcast/pgm/test/sources](../../net/mcast/pgm/test/sources), [net/mcast/pgm/test/makefile](../../net/mcast/pgm/test/makefile) | `RMTest` | `PROGRAM` |

## `net/mmc/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/mmc](../../net/mmc) | 1 | [net/mmc/dirs](../../net/mmc/dirs) | — | — |
| [net/mmc/acssnap](../../net/mmc/acssnap) | 56 | [net/mmc/acssnap/sources](../../net/mmc/acssnap/sources), [net/mmc/acssnap/makefile](../../net/mmc/acssnap/makefile) | `acssnap` | `DYNLINK` |
| [net/mmc/acssnap/res](../../net/mmc/acssnap/res) | 8 | — | — | — |
| [net/mmc/common](../../net/mmc/common) | 67 | [net/mmc/common/sources](../../net/mmc/common/sources), [net/mmc/common/makefile](../../net/mmc/common/makefile) | `snapcomn` | `LIBRARY` |
| [net/mmc/common/res](../../net/mmc/common/res) | 2 | — | — | — |
| [net/mmc/dhcp](../../net/mmc/dhcp) | 104 | [net/mmc/dhcp/sources](../../net/mmc/dhcp/sources), [net/mmc/dhcp/makefile](../../net/mmc/dhcp/makefile) | `dhcpsnap` | `DYNLINK` |
| [net/mmc/dhcp/res](../../net/mmc/dhcp/res) | 120 | — | — | — |
| [net/mmc/dialinusr](../../net/mmc/dialinusr) | 59 | [net/mmc/dialinusr/sources](../../net/mmc/dialinusr/sources), [net/mmc/dialinusr/makefile](../../net/mmc/dialinusr/makefile) | `rasuser` | `DYNLINK` |
| [net/mmc/dialinusr/res](../../net/mmc/dialinusr/res) | 3 | — | — | — |
| [net/mmc/idl](../../net/mmc/idl) | 7 | [net/mmc/idl/sources](../../net/mmc/idl/sources), [net/mmc/idl/makefile](../../net/mmc/idl/makefile) | — | `NOTARGET` |
| [net/mmc/ipsecmon](../../net/mmc/ipsecmon) | 74 | [net/mmc/ipsecmon/sources](../../net/mmc/ipsecmon/sources), [net/mmc/ipsecmon/makefile](../../net/mmc/ipsecmon/makefile) | `IpsmSnap` | `DYNLINK` |
| [net/mmc/ipsecmon/res](../../net/mmc/ipsecmon/res) | 19 | — | — | — |
| [net/mmc/ipxsnap](../../net/mmc/ipxsnap) | 83 | [net/mmc/ipxsnap/sources](../../net/mmc/ipxsnap/sources), [net/mmc/ipxsnap/makefile](../../net/mmc/ipxsnap/makefile) | `ipxsnap` | `DYNLINK` |
| [net/mmc/ipxsnap/res](../../net/mmc/ipxsnap/res) | 6 | — | — | — |
| [net/mmc/mprinc](../../net/mmc/mprinc) | 8 | — | — | — |
| [net/mmc/mprsnap](../../net/mmc/mprsnap) | 114 | [net/mmc/mprsnap/sources](../../net/mmc/mprsnap/sources), [net/mmc/mprsnap/makefile](../../net/mmc/mprsnap/makefile) | `mprsnap` | `DYNLINK` |
| [net/mmc/mprsnap/res](../../net/mmc/mprsnap/res) | 35 | — | — | — |
| [net/mmc/pubidls](../../net/mmc/pubidls) | 3 | [net/mmc/pubidls/sources](../../net/mmc/pubidls/sources), [net/mmc/pubidls/makefile](../../net/mmc/pubidls/makefile) | `idl` | `NOTARGET` |
| [net/mmc/remrras](../../net/mmc/remrras) | 1 | [net/mmc/remrras/dirs](../../net/mmc/remrras/dirs) | — | — |
| [net/mmc/remrras/idl](../../net/mmc/remrras/idl) | 3 | [net/mmc/remrras/idl/sources](../../net/mmc/remrras/idl/sources), [net/mmc/remrras/idl/makefile](../../net/mmc/remrras/idl/makefile) | `idl` | `NOTARGET` |
| [net/mmc/remrras/inc](../../net/mmc/remrras/inc) | 1 | — | — | — |
| [net/mmc/remrras/prxydll](../../net/mmc/remrras/prxydll) | 12 | [net/mmc/remrras/prxydll/sources](../../net/mmc/remrras/prxydll/sources), [net/mmc/remrras/prxydll/makefile](../../net/mmc/remrras/prxydll/makefile) | `rrasprxy` | `DYNLINK` |
| [net/mmc/remrras/rrasuid](../../net/mmc/remrras/rrasuid) | 3 | [net/mmc/remrras/rrasuid/sources](../../net/mmc/remrras/rrasuid/sources), [net/mmc/remrras/rrasuid/makefile](../../net/mmc/remrras/rrasuid/makefile) | `rrasuid` | `LIBRARY` |
| [net/mmc/remrras/server](../../net/mmc/remrras/server) | 26 | [net/mmc/remrras/server/sources](../../net/mmc/remrras/server/sources), [net/mmc/remrras/server/makefile](../../net/mmc/remrras/server/makefile) | `remrras` | `PROGRAM` |
| [net/mmc/rtrfiltr](../../net/mmc/rtrfiltr) | 24 | [net/mmc/rtrfiltr/sources](../../net/mmc/rtrfiltr/sources), [net/mmc/rtrfiltr/makefile](../../net/mmc/rtrfiltr/makefile) | `rtrfiltr` | `DYNLINK` |
| [net/mmc/rtrfiltr/res](../../net/mmc/rtrfiltr/res) | 1 | — | — | — |
| [net/mmc/rtrlib](../../net/mmc/rtrlib) | 37 | [net/mmc/rtrlib/sources](../../net/mmc/rtrlib/sources), [net/mmc/rtrlib/makefile](../../net/mmc/rtrlib/makefile) | `rtrlib` | `LIBRARY` |
| [net/mmc/rtrlib/res](../../net/mmc/rtrlib/res) | 4 | — | — | — |
| [net/mmc/snmp](../../net/mmc/snmp) | 24 | [net/mmc/snmp/sources](../../net/mmc/snmp/sources), [net/mmc/snmp/makefile](../../net/mmc/snmp/makefile) | `snmpsnap` | `DYNLINK` |
| [net/mmc/snmp/res](../../net/mmc/snmp/res) | 2 | — | — | — |
| [net/mmc/tapi](../../net/mmc/tapi) | 40 | [net/mmc/tapi/sources](../../net/mmc/tapi/sources), [net/mmc/tapi/makefile](../../net/mmc/tapi/makefile) | `tapisnap` | `DYNLINK` |
| [net/mmc/tapi/res](../../net/mmc/tapi/res) | 20 | — | — | — |
| [net/mmc/tfscore](../../net/mmc/tfscore) | 47 | [net/mmc/tfscore/sources](../../net/mmc/tfscore/sources), [net/mmc/tfscore/makefile](../../net/mmc/tfscore/makefile) | `tfscore` | `LIBRARY` |
| [net/mmc/tfscore/res](../../net/mmc/tfscore/res) | 12 | — | — | — |
| [net/mmc/wins](../../net/mmc/wins) | 93 | [net/mmc/wins/sources](../../net/mmc/wins/sources), [net/mmc/wins/makefile](../../net/mmc/wins/makefile) | `winssnap` | `DYNLINK` |
| [net/mmc/wins/res](../../net/mmc/wins/res) | 46 | — | — | — |

## `net/ndis/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/ndis](../../net/ndis) | 1 | [net/ndis/dirs](../../net/ndis/dirs) | — | — |
| [net/ndis/lib](../../net/ndis/lib) | 4 | [net/ndis/lib/sources](../../net/ndis/lib/sources), [net/ndis/lib/makefile](../../net/ndis/lib/makefile) | `ndispnp` | `LIBRARY` |
| [net/ndis/loopback](../../net/ndis/loopback) | 7 | [net/ndis/loopback/sources](../../net/ndis/loopback/sources), [net/ndis/loopback/makefile](../../net/ndis/loopback/makefile) | `LOOP` | `DRIVER` |
| [net/ndis/pnptst](../../net/ndis/pnptst) | 5 | [net/ndis/pnptst/sources](../../net/ndis/pnptst/sources), [net/ndis/pnptst/makefile](../../net/ndis/pnptst/makefile) | `netpnp` | `PROGRAM` |
| [net/ndis/samples](../../net/ndis/samples) | 1 | [net/ndis/samples/dirs](../../net/ndis/samples/dirs) | — | — |
| [net/ndis/samples/coisdn](../../net/ndis/samples/coisdn) | 38 | [net/ndis/samples/coisdn/sources](../../net/ndis/samples/coisdn/sources), [net/ndis/samples/coisdn/makefile](../../net/ndis/samples/coisdn/makefile) | `CoIsdn` | `DRIVER` |
| [net/ndis/samples/im](../../net/ndis/samples/im) | 11 | [net/ndis/samples/im/sources](../../net/ndis/samples/im/sources), [net/ndis/samples/im/makefile](../../net/ndis/samples/im/makefile) | `passthru` | `DRIVER` |
| [net/ndis/samples/im/memphis](../../net/ndis/samples/im/memphis) | 2 | — | — | — |
| [net/ndis/samples/isdnwan](../../net/ndis/samples/isdnwan) | 44 | [net/ndis/samples/isdnwan/sources](../../net/ndis/samples/isdnwan/sources), [net/ndis/samples/isdnwan/makefile](../../net/ndis/samples/isdnwan/makefile) | `IsdnWan` | `DRIVER` |
| [net/ndis/samples/muxim](../../net/ndis/samples/muxim) | 12 | [net/ndis/samples/muxim/sources](../../net/ndis/samples/muxim/sources), [net/ndis/samples/muxim/makefile](../../net/ndis/samples/muxim/makefile) | `mux` | `DRIVER` |
| [net/ndis/sys](../../net/ndis/sys) | 53 | [net/ndis/sys/dirs](../../net/ndis/sys/dirs) | — | — |
| [net/ndis/sys/mp](../../net/ndis/sys/mp) | 5 | [net/ndis/sys/mp/sources](../../net/ndis/sys/mp/sources), [net/ndis/sys/mp/makefile](../../net/ndis/sys/mp/makefile) | `ndis` | `EXPORT_DRIVER` |
| [net/ndis/sys/ndiskd](../../net/ndis/sys/ndiskd) | 6 | [net/ndis/sys/ndiskd/sources](../../net/ndis/sys/ndiskd/sources), [net/ndis/sys/ndiskd/makefile](../../net/ndis/sys/ndiskd/makefile) | `ndiskd` | `DYNLINK` |
| [net/ndis/sys/ndissym](../../net/ndis/sys/ndissym) | 4 | [net/ndis/sys/ndissym/sources](../../net/ndis/sys/ndissym/sources), [net/ndis/sys/ndissym/makefile](../../net/ndis/sys/ndissym/makefile) | — | `NOTARGET` |
| [net/ndis/tunmp](../../net/ndis/tunmp) | 1 | [net/ndis/tunmp/dirs](../../net/ndis/tunmp/dirs) | — | — |
| [net/ndis/tunmp/sys](../../net/ndis/tunmp/sys) | 16 | [net/ndis/tunmp/sys/sources](../../net/ndis/tunmp/sys/sources), [net/ndis/tunmp/sys/makefile](../../net/ndis/tunmp/sys/makefile) | `tunmp` | `DRIVER` |
| [net/ndis/tunmp/test](../../net/ndis/tunmp/test) | 3 | [net/ndis/tunmp/test/sources](../../net/ndis/tunmp/test/sources), [net/ndis/tunmp/test/makefile](../../net/ndis/tunmp/test/makefile) | `tuntest` | `PROGRAM` |
| [net/ndis/uio](../../net/ndis/uio) | 2 | [net/ndis/uio/dirs](../../net/ndis/uio/dirs) | — | — |
| [net/ndis/uio/inf](../../net/ndis/uio/inf) | 5 | [net/ndis/uio/inf/sources](../../net/ndis/uio/inf/sources), [net/ndis/uio/inf/makefile](../../net/ndis/uio/inf/makefile) | `inf` | `notarget` |
| [net/ndis/uio/sys](../../net/ndis/uio/sys) | 13 | [net/ndis/uio/sys/sources](../../net/ndis/uio/sys/sources), [net/ndis/uio/sys/makefile](../../net/ndis/uio/sys/makefile) | `ndisuio` | `DRIVER` |
| [net/ndis/uio/test](../../net/ndis/uio/test) | 3 | [net/ndis/uio/test/sources](../../net/ndis/uio/test/sources), [net/ndis/uio/test/makefile](../../net/ndis/uio/test/makefile) | `uiotest` | `PROGRAM` |

## `net/netbeui/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/netbeui](../../net/netbeui) | 1 | [net/netbeui/dirs](../../net/netbeui/dirs) | — | — |
| [net/netbeui/kdext](../../net/netbeui/kdext) | 30 | [net/netbeui/kdext/sources](../../net/netbeui/kdext/sources), [net/netbeui/kdext/makefile](../../net/netbeui/kdext/makefile) | `nbfext` | `DYNLINK` |
| [net/netbeui/sys](../../net/netbeui/sys) | 42 | [net/netbeui/sys/sources](../../net/netbeui/sys/sources), [net/netbeui/sys/makefile](../../net/netbeui/sys/makefile) | `nbf` | `DRIVER` |

## `net/netbios/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/netbios](../../net/netbios) | 1 | [net/netbios/dirs](../../net/netbios/dirs) | — | — |
| [net/netbios/componentdef](../../net/netbios/componentdef) | 5 | [net/netbios/componentdef/sources](../../net/netbios/componentdef/sources), [net/netbios/componentdef/makefile](../../net/netbios/componentdef/makefile) | `None` | `notarget` |
| [net/netbios/lib](../../net/netbios/lib) | 9 | [net/netbios/lib/sources](../../net/netbios/lib/sources), [net/netbios/lib/makefile](../../net/netbios/lib/makefile) | `netbios` | `LIBRARY` |
| [net/netbios/sys](../../net/netbios/sys) | 20 | [net/netbios/sys/sources](../../net/netbios/sys/sources), [net/netbios/sys/makefile](../../net/netbios/sys/makefile) | `netbios` | `DRIVER` |
| [net/netbios/winsock](../../net/netbios/winsock) | 6 | [net/netbios/winsock/sources](../../net/netbios/winsock/sources), [net/netbios/winsock/makefile](../../net/netbios/winsock/makefile) | `wshnetbs` | `DYNLINK` |

## `net/netbt/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/netbt](../../net/netbt) | 1 | [net/netbt/dirs](../../net/netbt/dirs) | — | — |
| [net/netbt/inc](../../net/netbt/inc) | 12 | — | — | — |
| [net/netbt/kdext](../../net/netbt/kdext) | 7 | [net/netbt/kdext/sources](../../net/netbt/kdext/sources), [net/netbt/kdext/makefile](../../net/netbt/kdext/makefile) | `netbtkd` | `DYNLINK` |
| [net/netbt/lmhosts](../../net/netbt/lmhosts) | 5 | [net/netbt/lmhosts/sources](../../net/netbt/lmhosts/sources), [net/netbt/lmhosts/makefile](../../net/netbt/lmhosts/makefile) | `lmhsvc` | `DYNLINK` |
| [net/netbt/nbtstat](../../net/netbt/nbtstat) | 9 | [net/netbt/nbtstat/sources](../../net/netbt/nbtstat/sources), [net/netbt/nbtstat/makefile](../../net/netbt/nbtstat/makefile) | `nbtstat` | `PROGRAM` |
| [net/netbt/sys](../../net/netbt/sys) | 12 | [net/netbt/sys/dirs](../../net/netbt/sys/dirs) | — | — |
| [net/netbt/sys/nt](../../net/netbt/sys/nt) | 22 | [net/netbt/sys/nt/sources](../../net/netbt/sys/nt/sources), [net/netbt/sys/nt/makefile](../../net/netbt/sys/nt/makefile) | `netbt` | `DRIVER` |

## `net/netevent/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/netevent](../../net/netevent) | 5 | [net/netevent/sources](../../net/netevent/sources), [net/netevent/makefile](../../net/netevent/makefile) | `netevent` | `DYNLINK` |

## `net/nwlink/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/nwlink](../../net/nwlink) | 1 | [net/nwlink/dirs](../../net/nwlink/dirs) | — | — |
| [net/nwlink/flt](../../net/nwlink/flt) | 11 | [net/nwlink/flt/sources](../../net/nwlink/flt/sources), [net/nwlink/flt/makefile](../../net/nwlink/flt/makefile) | `nwlnkflt` | `DRIVER` |
| [net/nwlink/fwd](../../net/nwlink/fwd) | 29 | [net/nwlink/fwd/sources](../../net/nwlink/fwd/sources), [net/nwlink/fwd/makefile](../../net/nwlink/fwd/makefile) | `nwlnkfwd` | `DRIVER` |
| [net/nwlink/inc](../../net/nwlink/inc) | 5 | — | — | — |
| [net/nwlink/ipx](../../net/nwlink/ipx) | 32 | [net/nwlink/ipx/sources](../../net/nwlink/ipx/sources), [net/nwlink/ipx/makefile](../../net/nwlink/ipx/makefile) | `nwlnkipx` | `DRIVER` |
| [net/nwlink/ipxroute](../../net/nwlink/ipxroute) | 8 | [net/nwlink/ipxroute/sources](../../net/nwlink/ipxroute/sources), [net/nwlink/ipxroute/makefile](../../net/nwlink/ipxroute/makefile) | `ipxroute` | `PROGRAM` |
| [net/nwlink/kdext](../../net/nwlink/kdext) | 16 | [net/nwlink/kdext/sources](../../net/nwlink/kdext/sources), [net/nwlink/kdext/makefile](../../net/nwlink/kdext/makefile) | `isnext` | `DYNLINK` |
| [net/nwlink/nb](../../net/nwlink/nb) | 26 | [net/nwlink/nb/sources](../../net/nwlink/nb/sources), [net/nwlink/nb/makefile](../../net/nwlink/nb/makefile) | `nwlnknb` | `DRIVER` |
| [net/nwlink/spx](../../net/nwlink/spx) | 38 | [net/nwlink/spx/sources](../../net/nwlink/spx/sources), [net/nwlink/spx/makefile](../../net/nwlink/spx/makefile) | `nwlnkspx` | `DRIVER` |
| [net/nwlink/winsock](../../net/nwlink/winsock) | 7 | [net/nwlink/winsock/sources](../../net/nwlink/winsock/sources), [net/nwlink/winsock/makefile](../../net/nwlink/winsock/makefile) | `wshisn` | `DYNLINK` |

## `net/published/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/published](../../net/published) | 1 | [net/published/dirs](../../net/published/dirs) | — | — |
| [net/published/idlole](../../net/published/idlole) | 36 | [net/published/idlole/sources](../../net/published/idlole/sources), [net/published/idlole/makefile](../../net/published/idlole/makefile) | — | `NOTARGET` |
| [net/published/idlrpc](../../net/published/idlrpc) | 2 | [net/published/idlrpc/sources](../../net/published/idlrpc/sources), [net/published/idlrpc/makefile](../../net/published/idlrpc/makefile) | — | `NOTARGET` |
| [net/published/inc](../../net/published/inc) | 132 | [net/published/inc/sources](../../net/published/inc/sources), [net/published/inc/makefile](../../net/published/inc/makefile) | — | `NOTARGET` |
| [net/published/lib](../../net/published/lib) | 2 | [net/published/lib/dirs](../../net/published/lib/dirs) | — | — |
| [net/published/lib/dload](../../net/published/lib/dload) | 17 | [net/published/lib/dload/sources](../../net/published/lib/dload/sources), [net/published/lib/dload/makefile](../../net/published/lib/dload/makefile) | `dloadnet` | `LIBRARY` |
| [net/published/lib/nls](../../net/published/lib/nls) | 3 | [net/published/lib/nls/sources](../../net/published/lib/nls/sources), [net/published/lib/nls/makefile](../../net/published/lib/nls/makefile) | `nls` | `LIBRARY` |
| [net/published/lib/unixapis](../../net/published/lib/unixapis) | 7 | [net/published/lib/unixapis/sources](../../net/published/lib/unixapis/sources), [net/published/lib/unixapis/makefile](../../net/published/lib/unixapis/makefile) | `unixapis` | `LIBRARY` |
| [net/published/uuid](../../net/published/uuid) | 6 | [net/published/uuid/sources](../../net/published/uuid/sources), [net/published/uuid/makefile](../../net/published/uuid/makefile) | `uuidnet` | `LIBRARY` |

## `net/qos/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/qos](../../net/qos) | 1 | [net/qos/dirs](../../net/qos/dirs) | — | — |
| [net/qos/inc](../../net/qos/inc) | 2 | — | — | — |
| [net/qos/pclass](../../net/qos/pclass) | 1 | [net/qos/pclass/dirs](../../net/qos/pclass/dirs) | — | — |
| [net/qos/pclass/gpc](../../net/qos/pclass/gpc) | 24 | [net/qos/pclass/gpc/sources](../../net/qos/pclass/gpc/sources), [net/qos/pclass/gpc/makefile](../../net/qos/pclass/gpc/makefile) | `msgpc` | `DRIVER` |
| [net/qos/pclass/kdext](../../net/qos/pclass/kdext) | 11 | [net/qos/pclass/kdext/sources](../../net/qos/pclass/kdext/sources), [net/qos/pclass/kdext/makefile](../../net/qos/pclass/kdext/makefile) | `kdgpc` | `DYNLINK` |
| [net/qos/pclass/proxy](../../net/qos/pclass/proxy) | 3 | [net/qos/pclass/proxy/sources](../../net/qos/pclass/proxy/sources), [net/qos/pclass/proxy/makefile](../../net/qos/pclass/proxy/makefile) | `gpcprx` | `DRIVER_LIBRARY` |
| [net/qos/psched](../../net/qos/psched) | 1 | [net/qos/psched/dirs](../../net/qos/psched/dirs) | — | — |
| [net/qos/psched/kdext](../../net/qos/psched/kdext) | 13 | [net/qos/psched/kdext/sources](../../net/qos/psched/kdext/sources), [net/qos/psched/kdext/makefile](../../net/qos/psched/kdext/makefile) | `kdps` | `DYNLINK` |
| [net/qos/psched/netshell](../../net/qos/psched/netshell) | 0 | — | — | — |
| [net/qos/psched/netshell/diffserv](../../net/qos/psched/netshell/diffserv) | 4 | — | — | — |
| [net/qos/psched/netshell/diffserv/qos-netsh](../../net/qos/psched/netshell/diffserv/qos-netsh) | 12 | [net/qos/psched/netshell/diffserv/qos-netsh/sources](../../net/qos/psched/netshell/diffserv/qos-netsh/sources) | `ippromon` | `DYNLINK` |
| [net/qos/psched/netshell/diffserv/qos-protocol](../../net/qos/psched/netshell/diffserv/qos-protocol) | 23 | [net/qos/psched/netshell/diffserv/qos-protocol/sources](../../net/qos/psched/netshell/diffserv/qos-protocol/sources), [net/qos/psched/netshell/diffserv/qos-protocol/makefile](../../net/qos/psched/netshell/diffserv/qos-protocol/makefile) | `qosmgr` | `DYNLINK` |
| [net/qos/psched/pschdprf](../../net/qos/psched/pschdprf) | 13 | [net/qos/psched/pschdprf/sources](../../net/qos/psched/pschdprf/sources), [net/qos/psched/pschdprf/makefile](../../net/qos/psched/pschdprf/makefile) | `pschdprf` | `DYNLINK` |
| [net/qos/psched/pslog](../../net/qos/psched/pslog) | 6 | [net/qos/psched/pslog/sources](../../net/qos/psched/pslog/sources), [net/qos/psched/pslog/makefile](../../net/qos/psched/pslog/makefile) | `pslog` | `PROGRAM` |
| [net/qos/psched/sys](../../net/qos/psched/sys) | 55 | [net/qos/psched/sys/dirs](../../net/qos/psched/sys/dirs) | — | — |
| [net/qos/psched/sys/mp](../../net/qos/psched/sys/mp) | 2 | [net/qos/psched/sys/mp/sources](../../net/qos/psched/sys/mp/sources), [net/qos/psched/sys/mp/makefile](../../net/qos/psched/sys/mp/makefile) | — | — |
| [net/qos/psched/zaw](../../net/qos/psched/zaw) | 3 | [net/qos/psched/zaw/sources](../../net/qos/psched/zaw/sources), [net/qos/psched/zaw/makefile](../../net/qos/psched/zaw/makefile) | `qtcp` | `PROGRAM` |
| [net/qos/tc](../../net/qos/tc) | 1 | [net/qos/tc/dirs](../../net/qos/tc/dirs) | — | — |
| [net/qos/tc/dll](../../net/qos/tc/dll) | 27 | [net/qos/tc/dll/sources](../../net/qos/tc/dll/sources), [net/qos/tc/dll/makefile](../../net/qos/tc/dll/makefile) | `traffic` | `DYNLINK` |
| [net/qos/tools](../../net/qos/tools) | 1 | [net/qos/tools/dirs](../../net/qos/tools/dirs) | — | — |
| [net/qos/tools/qtcp](../../net/qos/tools/qtcp) | 7 | [net/qos/tools/qtcp/sources](../../net/qos/tools/qtcp/sources), [net/qos/tools/qtcp/makefile](../../net/qos/tools/qtcp/makefile) | `qtcp` | `PROGRAM` |
| [net/qos/tools/timestmp](../../net/qos/tools/timestmp) | 8 | [net/qos/tools/timestmp/sources](../../net/qos/tools/timestmp/sources), [net/qos/tools/timestmp/makefile](../../net/qos/tools/timestmp/makefile) | `timestmp` | `DRIVER` |
| [net/qos/tools/tsinstl](../../net/qos/tools/tsinstl) | 4 | [net/qos/tools/tsinstl/sources](../../net/qos/tools/tsinstl/sources), [net/qos/tools/tsinstl/makefile](../../net/qos/tools/tsinstl/makefile) | `tsinstl` | `PROGRAM` |

## `net/rndis/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/rndis](../../net/rndis) | 2 | [net/rndis/dirs](../../net/rndis/dirs) | — | — |
| [net/rndis/inc](../../net/rndis/inc) | 3 | — | — | — |
| [net/rndis/inf](../../net/rndis/inf) | 6 | [net/rndis/inf/sources](../../net/rndis/inf/sources), [net/rndis/inf/makefile](../../net/rndis/inf/makefile) | `inf` | `notarget` |
| [net/rndis/inf/usa](../../net/rndis/inf/usa) | 1 | — | — | — |
| [net/rndis/inftemplate](../../net/rndis/inftemplate) | 2 | — | — | — |
| [net/rndis/rndismp](../../net/rndis/rndismp) | 15 | [net/rndis/rndismp/dirs](../../net/rndis/rndismp/dirs) | — | — |
| [net/rndis/rndismp/sys](../../net/rndis/rndismp/sys) | 4 | [net/rndis/rndismp/sys/sources](../../net/rndis/rndismp/sys/sources), [net/rndis/rndismp/sys/makefile](../../net/rndis/rndismp/sys/makefile) | `RNDISMP` | `EXPORT_DRIVER` |
| [net/rndis/rndismp/win2k](../../net/rndis/rndismp/win2k) | 4 | [net/rndis/rndismp/win2k/sources](../../net/rndis/rndismp/win2k/sources), [net/rndis/rndismp/win2k/makefile](../../net/rndis/rndismp/win2k/makefile) | `RNDISMP` | `EXPORT_DRIVER` |
| [net/rndis/rndismp/win9x](../../net/rndis/rndismp/win9x) | 4 | [net/rndis/rndismp/win9x/sources](../../net/rndis/rndismp/win9x/sources), [net/rndis/rndismp/win9x/makefile](../../net/rndis/rndismp/win9x/makefile) | `RNDISMP` | `EXPORT_DRIVER` |
| [net/rndis/usb8023](../../net/rndis/usb8023) | 15 | [net/rndis/usb8023/dirs](../../net/rndis/usb8023/dirs) | — | — |
| [net/rndis/usb8023/sys](../../net/rndis/usb8023/sys) | 2 | [net/rndis/usb8023/sys/sources](../../net/rndis/usb8023/sys/sources), [net/rndis/usb8023/sys/makefile](../../net/rndis/usb8023/sys/makefile) | `usb8023` | `DRIVER` |
| [net/rndis/usb8023/win9x](../../net/rndis/usb8023/win9x) | 2 | [net/rndis/usb8023/win9x/sources](../../net/rndis/usb8023/win9x/sources), [net/rndis/usb8023/win9x/makefile](../../net/rndis/usb8023/win9x/makefile) | `usb8023` | `DRIVER` |

## `net/rras/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/rras](../../net/rras) | 1 | [net/rras/dirs](../../net/rras/dirs) | — | — |
| [net/rras/cm](../../net/rras/cm) | 2 | [net/rras/cm/dirs](../../net/rras/cm/dirs) | — | — |
| [net/rras/cm/ccfg9x](../../net/rras/cm/ccfg9x) | 27 | [net/rras/cm/ccfg9x/sources](../../net/rras/cm/ccfg9x/sources), [net/rras/cm/ccfg9x/makefile](../../net/rras/cm/ccfg9x/makefile) | `ccfg95` | `DYNLINK` |
| [net/rras/cm/ccfg9x/i386](../../net/rras/cm/ccfg9x/i386) | 1 | — | — | — |
| [net/rras/cm/ccfgnt](../../net/rras/cm/ccfgnt) | 11 | [net/rras/cm/ccfgnt/sources](../../net/rras/cm/ccfgnt/sources), [net/rras/cm/ccfgnt/makefile](../../net/rras/cm/ccfgnt/makefile) | `ccfgnt` | `DYNLINK` |
| [net/rras/cm/cmcfg](../../net/rras/cm/cmcfg) | 11 | [net/rras/cm/cmcfg/sources](../../net/rras/cm/cmcfg/sources), [net/rras/cm/cmcfg/makefile](../../net/rras/cm/cmcfg/makefile) | `cmcfg32` | `DYNLINK` |
| [net/rras/cm/cmcontbl](../../net/rras/cm/cmcontbl) | 5 | [net/rras/cm/cmcontbl/sources](../../net/rras/cm/cmcontbl/sources), [net/rras/cm/cmcontbl/makefile](../../net/rras/cm/cmcontbl/makefile) | `cmcontbl` | `LIBRARY` |
| [net/rras/cm/cmdebug](../../net/rras/cm/cmdebug) | 3 | [net/rras/cm/cmdebug/sources](../../net/rras/cm/cmdebug/sources), [net/rras/cm/cmdebug/makefile](../../net/rras/cm/cmdebug/makefile) | `cmdebug` | `LIBRARY` |
| [net/rras/cm/cmdial](../../net/rras/cm/cmdial) | 54 | [net/rras/cm/cmdial/sources](../../net/rras/cm/cmdial/sources), [net/rras/cm/cmdial/makefile](../../net/rras/cm/cmdial/makefile) | `cmdial32` | `DYNLINK` |
| [net/rras/cm/cmdial/help](../../net/rras/cm/cmdial/help) | 6 | — | — | — |
| [net/rras/cm/cmdl](../../net/rras/cm/cmdl) | 14 | [net/rras/cm/cmdl/sources](../../net/rras/cm/cmdl/sources), [net/rras/cm/cmdl/makefile](../../net/rras/cm/cmdl/makefile) | `cmdl32` | `PROGRAM` |
| [net/rras/cm/cmmgr](../../net/rras/cm/cmmgr) | 9 | [net/rras/cm/cmmgr/sources](../../net/rras/cm/cmmgr/sources), [net/rras/cm/cmmgr/makefile](../../net/rras/cm/cmmgr/makefile) | `cmmgr32` | `PROGRAM` |
| [net/rras/cm/cmmon](../../net/rras/cm/cmmon) | 32 | [net/rras/cm/cmmon/sources](../../net/rras/cm/cmmon/sources), [net/rras/cm/cmmon/makefile](../../net/rras/cm/cmmon/makefile) | `cmmon32` | `PROGRAM` |
| [net/rras/cm/cmpbk](../../net/rras/cm/cmpbk) | 19 | [net/rras/cm/cmpbk/sources](../../net/rras/cm/cmpbk/sources), [net/rras/cm/cmpbk/makefile](../../net/rras/cm/cmpbk/makefile) | `cmpbk32` | `DYNLINK` |
| [net/rras/cm/cmsecure](../../net/rras/cm/cmsecure) | 5 | [net/rras/cm/cmsecure/dirs](../../net/rras/cm/cmsecure/dirs) | — | — |
| [net/rras/cm/cmsecure/win32](../../net/rras/cm/cmsecure/win32) | 2 | [net/rras/cm/cmsecure/win32/sources](../../net/rras/cm/cmsecure/win32/sources), [net/rras/cm/cmsecure/win32/makefile](../../net/rras/cm/cmsecure/win32/makefile) | `cmsecure` | `LIBRARY` |
| [net/rras/cm/cmsetup](../../net/rras/cm/cmsetup) | 14 | [net/rras/cm/cmsetup/dirs](../../net/rras/cm/cmsetup/dirs) | — | — |
| [net/rras/cm/cmsetup/ansi](../../net/rras/cm/cmsetup/ansi) | 2 | [net/rras/cm/cmsetup/ansi/sources](../../net/rras/cm/cmsetup/ansi/sources), [net/rras/cm/cmsetup/ansi/makefile](../../net/rras/cm/cmsetup/ansi/makefile) | `cmsetup` | `LIBRARY` |
| [net/rras/cm/cmsetup/unicode](../../net/rras/cm/cmsetup/unicode) | 2 | [net/rras/cm/cmsetup/unicode/sources](../../net/rras/cm/cmsetup/unicode/sources), [net/rras/cm/cmsetup/unicode/makefile](../../net/rras/cm/cmsetup/unicode/makefile) | `cmsetupW` | `LIBRARY` |
| [net/rras/cm/cmstp](../../net/rras/cm/cmstp) | 18 | [net/rras/cm/cmstp/sources](../../net/rras/cm/cmstp/sources), [net/rras/cm/cmstp/makefile](../../net/rras/cm/cmstp/makefile) | `cmstp` | `PROGRAM` |
| [net/rras/cm/cmutil](../../net/rras/cm/cmutil) | 20 | [net/rras/cm/cmutil/sources](../../net/rras/cm/cmutil/sources), [net/rras/cm/cmutil/makefile](../../net/rras/cm/cmutil/makefile) | `cmutil` | `DYNLINK` |
| [net/rras/cm/cnetcfg](../../net/rras/cm/cnetcfg) | 19 | [net/rras/cm/cnetcfg/sources](../../net/rras/cm/cnetcfg/sources), [net/rras/cm/cnetcfg/makefile](../../net/rras/cm/cnetcfg/makefile) | `cnetcfg` | `DYNLINK` |
| [net/rras/cm/common](../../net/rras/cm/common) | 0 | — | — | — |
| [net/rras/cm/common/inc](../../net/rras/cm/common/inc) | 48 | — | — | — |
| [net/rras/cm/common/rc](../../net/rras/cm/common/rc) | 1 | — | — | — |
| [net/rras/cm/common/source](../../net/rras/cm/common/source) | 17 | — | — | — |
| [net/rras/cm/common/strings](../../net/rras/cm/common/strings) | 20 | — | — | — |
| [net/rras/cm/customactions](../../net/rras/cm/customactions) | 1 | [net/rras/cm/customactions/dirs](../../net/rras/cm/customactions/dirs) | — | — |
| [net/rras/cm/customactions/cmproxy](../../net/rras/cm/customactions/cmproxy) | 8 | [net/rras/cm/customactions/cmproxy/sources](../../net/rras/cm/customactions/cmproxy/sources), [net/rras/cm/customactions/cmproxy/makefile](../../net/rras/cm/customactions/cmproxy/makefile) | `cmproxy` | `DYNLINK` |
| [net/rras/cm/customactions/cmroute](../../net/rras/cm/customactions/cmroute) | 7 | [net/rras/cm/customactions/cmroute/sources](../../net/rras/cm/customactions/cmroute/sources), [net/rras/cm/customactions/cmroute/makefile](../../net/rras/cm/customactions/cmroute/makefile) | `cmroute` | `DYNLINK` |
| [net/rras/cm/customactions/cmsample](../../net/rras/cm/customactions/cmsample) | 7 | [net/rras/cm/customactions/cmsample/sources](../../net/rras/cm/customactions/cmsample/sources), [net/rras/cm/customactions/cmsample/makefile](../../net/rras/cm/customactions/cmsample/makefile) | `cmsample` | `DYNLINK` |
| [net/rras/cm/customactions/cmsample/testfiles](../../net/rras/cm/customactions/cmsample/testfiles) | 2 | — | — | — |
| [net/rras/cm/migrate](../../net/rras/cm/migrate) | 9 | [net/rras/cm/migrate/sources](../../net/rras/cm/migrate/sources), [net/rras/cm/migrate/makefile](../../net/rras/cm/migrate/makefile) | `migrate` | `DYNLINK` |
| [net/rras/cm/profwiz](../../net/rras/cm/profwiz) | 27 | [net/rras/cm/profwiz/sources](../../net/rras/cm/profwiz/sources), [net/rras/cm/profwiz/makefile](../../net/rras/cm/profwiz/makefile) | `cmak` | `PROGRAM` |
| [net/rras/cm/profwiz/docs](../../net/rras/cm/profwiz/docs) | 3 | — | — | — |
| [net/rras/cm/profwiz/setup](../../net/rras/cm/profwiz/setup) | 7 | — | — | — |
| [net/rras/cm/profwiz/support](../../net/rras/cm/profwiz/support) | 0 | — | — | — |
| [net/rras/cm/profwiz/support/alpha](../../net/rras/cm/profwiz/support/alpha) | 3 | — | — | — |
| [net/rras/cm/profwiz/support/x86](../../net/rras/cm/profwiz/support/x86) | 10 | — | — | — |
| [net/rras/cm/uapi](../../net/rras/cm/uapi) | 2 | [net/rras/cm/uapi/dirs](../../net/rras/cm/uapi/dirs) | — | — |
| [net/rras/cm/uapi/cmutoa](../../net/rras/cm/uapi/cmutoa) | 5 | [net/rras/cm/uapi/cmutoa/sources](../../net/rras/cm/uapi/cmutoa/sources), [net/rras/cm/uapi/cmutoa/makefile](../../net/rras/cm/uapi/cmutoa/makefile) | `cmutoa` | `DYNLINK` |
| [net/rras/cm/uapi/uapiinit](../../net/rras/cm/uapi/uapiinit) | 3 | [net/rras/cm/uapi/uapiinit/sources](../../net/rras/cm/uapi/uapiinit/sources), [net/rras/cm/uapi/uapiinit/makefile](../../net/rras/cm/uapi/uapiinit/makefile) | `uapiinit` | `LIBRARY` |
| [net/rras/common](../../net/rras/common) | 1 | [net/rras/common/dirs](../../net/rras/common/dirs) | — | — |
| [net/rras/common/mprcommn](../../net/rras/common/mprcommn) | 4 | [net/rras/common/mprcommn/sources](../../net/rras/common/mprcommn/sources), [net/rras/common/mprcommn/makefile](../../net/rras/common/mprcommn/makefile) | `mprcommn` | `LIBRARY` |
| [net/rras/common/rtutils](../../net/rras/common/rtutils) | 29 | [net/rras/common/rtutils/sources](../../net/rras/common/rtutils/sources), [net/rras/common/rtutils/makefile](../../net/rras/common/rtutils/makefile) | `rtutils` | `DYNLINK` |
| [net/rras/cps](../../net/rras/cps) | 2 | [net/rras/cps/dirs](../../net/rras/cps/dirs) | — | — |
| [net/rras/cps/hhwrap](../../net/rras/cps/hhwrap) | 6 | [net/rras/cps/hhwrap/sources](../../net/rras/cps/hhwrap/sources), [net/rras/cps/hhwrap/makefile](../../net/rras/cps/hhwrap/makefile) | `hhwrap` | `DYNLINK` |
| [net/rras/cps/inc](../../net/rras/cps/inc) | 1 | — | — | — |
| [net/rras/cps/pba](../../net/rras/cps/pba) | 3 | [net/rras/cps/pba/dirs](../../net/rras/cps/pba/dirs) | — | — |
| [net/rras/cps/pba/buildit](../../net/rras/cps/pba/buildit) | 5 | [net/rras/cps/pba/buildit/sources](../../net/rras/cps/pba/buildit/sources), [net/rras/cps/pba/buildit/makefile](../../net/rras/cps/pba/buildit/makefile) | `pbainst` | `PROGRAM` |
| [net/rras/cps/pba/buildit/sources0](../../net/rras/cps/pba/buildit/sources0) | 7 | — | — | — |
| [net/rras/cps/pba/buildit/sources1](../../net/rras/cps/pba/buildit/sources1) | 11 | — | — | — |
| [net/rras/cps/pba/source](../../net/rras/cps/pba/source) | 44 | — | — | — |
| [net/rras/cps/pbserver](../../net/rras/cps/pbserver) | 15 | [net/rras/cps/pbserver/sources](../../net/rras/cps/pbserver/sources), [net/rras/cps/pbserver/makefile](../../net/rras/cps/pbserver/makefile) | `pbserver` | `DYNLINK` |
| [net/rras/cps/pbsmon](../../net/rras/cps/pbsmon) | 10 | [net/rras/cps/pbsmon/sources](../../net/rras/cps/pbsmon/sources), [net/rras/cps/pbsmon/makefile](../../net/rras/cps/pbsmon/makefile) | `pbsmon` | `DYNLINK` |
| [net/rras/cps/pbsvrmsg](../../net/rras/cps/pbsvrmsg) | 4 | [net/rras/cps/pbsvrmsg/sources](../../net/rras/cps/pbsvrmsg/sources), [net/rras/cps/pbsvrmsg/makefile](../../net/rras/cps/pbsvrmsg/makefile) | `pbsvrmsg` | `DYNLINK` |
| [net/rras/dim](../../net/rras/dim) | 1 | [net/rras/dim/dirs](../../net/rras/dim/dirs) | — | — |
| [net/rras/dim/admindll](../../net/rras/dim/admindll) | 29 | [net/rras/dim/admindll/sources](../../net/rras/dim/admindll/sources), [net/rras/dim/admindll/makefile](../../net/rras/dim/admindll/makefile) | `mprapi` | `DYNLINK` |
| [net/rras/dim/idl](../../net/rras/dim/idl) | 6 | [net/rras/dim/idl/sources](../../net/rras/dim/idl/sources), [net/rras/dim/idl/makefile](../../net/rras/dim/idl/makefile) | — | `NOTARGET` |
| [net/rras/dim/server](../../net/rras/dim/server) | 18 | [net/rras/dim/server/sources](../../net/rras/dim/server/sources), [net/rras/dim/server/makefile](../../net/rras/dim/server/makefile) | `mprdim` | `DYNLINK` |
| [net/rras/inc](../../net/rras/inc) | 34 | — | — | — |
| [net/rras/ip](../../net/rras/ip) | 1 | [net/rras/ip/dirs](../../net/rras/ip/dirs) | — | — |
| [net/rras/ip/bootp](../../net/rras/ip/bootp) | 19 | [net/rras/ip/bootp/sources](../../net/rras/ip/bootp/sources), [net/rras/ip/bootp/makefile](../../net/rras/ip/bootp/makefile) | `ipbootp` | `DYNLINK` |
| [net/rras/ip/btpagnt](../../net/rras/ip/btpagnt) | 11 | [net/rras/ip/btpagnt/sources](../../net/rras/ip/btpagnt/sources), [net/rras/ip/btpagnt/makefile](../../net/rras/ip/btpagnt/makefile) | `btpagnt` | `DYNLINK` |
| [net/rras/ip/dvmrp](../../net/rras/ip/dvmrp) | 32 | [net/rras/ip/dvmrp/sources](../../net/rras/ip/dvmrp/sources), [net/rras/ip/dvmrp/makefile](../../net/rras/ip/dvmrp/makefile) | `dvmrp` | `DYNLINK` |
| [net/rras/ip/fltrdrvr](../../net/rras/ip/fltrdrvr) | 16 | [net/rras/ip/fltrdrvr/dirs](../../net/rras/ip/fltrdrvr/dirs) | — | — |
| [net/rras/ip/fltrdrvr/kdext](../../net/rras/ip/fltrdrvr/kdext) | 5 | [net/rras/ip/fltrdrvr/kdext/sources](../../net/rras/ip/fltrdrvr/kdext/sources), [net/rras/ip/fltrdrvr/kdext/makefile](../../net/rras/ip/fltrdrvr/kdext/makefile) | `ipfext` | `DYNLINK` |
| [net/rras/ip/fltrdrvr/mp](../../net/rras/ip/fltrdrvr/mp) | 2 | [net/rras/ip/fltrdrvr/mp/sources](../../net/rras/ip/fltrdrvr/mp/sources), [net/rras/ip/fltrdrvr/mp/makefile](../../net/rras/ip/fltrdrvr/mp/makefile) | `ipfltdrv` | — |
| [net/rras/ip/fltrdrvr/perf](../../net/rras/ip/fltrdrvr/perf) | 2 | [net/rras/ip/fltrdrvr/perf/sources](../../net/rras/ip/fltrdrvr/perf/sources), [net/rras/ip/fltrdrvr/perf/makefile](../../net/rras/ip/fltrdrvr/perf/makefile) | `ipfltprf` | — |
| [net/rras/ip/igmp](../../net/rras/ip/igmp) | 33 | [net/rras/ip/igmp/sources](../../net/rras/ip/igmp/sources), [net/rras/ip/igmp/makefile](../../net/rras/ip/igmp/makefile) | `igmpv2` | `DYNLINK` |
| [net/rras/ip/igmpagnt](../../net/rras/ip/igmpagnt) | 11 | [net/rras/ip/igmpagnt/sources](../../net/rras/ip/igmpagnt/sources), [net/rras/ip/igmpagnt/makefile](../../net/rras/ip/igmpagnt/makefile) | `igmpagnt` | `DYNLINK` |
| [net/rras/ip/inc](../../net/rras/ip/inc) | 1 | — | — | — |
| [net/rras/ip/ipinip](../../net/rras/ip/ipinip) | 26 | [net/rras/ip/ipinip/sources](../../net/rras/ip/ipinip/sources), [net/rras/ip/ipinip/makefile](../../net/rras/ip/ipinip/makefile) | `ipinip` | `DRIVER` |
| [net/rras/ip/mcastmib](../../net/rras/ip/mcastmib) | 11 | [net/rras/ip/mcastmib/sources](../../net/rras/ip/mcastmib/sources), [net/rras/ip/mcastmib/makefile](../../net/rras/ip/mcastmib/makefile) | `mcastmib` | `DYNLINK` |
| [net/rras/ip/nat](../../net/rras/ip/nat) | 53 | [net/rras/ip/nat/sources](../../net/rras/ip/nat/sources), [net/rras/ip/nat/makefile](../../net/rras/ip/nat/makefile) | `ipnat` | `DRIVER` |
| [net/rras/ip/nat/direct](../../net/rras/ip/nat/direct) | 4 | [net/rras/ip/nat/direct/sources](../../net/rras/ip/nat/direct/sources), [net/rras/ip/nat/direct/makefile](../../net/rras/ip/nat/direct/makefile) | `ipnatdir` | `DRIVER` |
| [net/rras/ip/nat/kdext](../../net/rras/ip/nat/kdext) | 5 | [net/rras/ip/nat/kdext/sources](../../net/rras/ip/nat/kdext/sources), [net/rras/ip/nat/kdext/makefile](../../net/rras/ip/nat/kdext/makefile) | `natext` | `DYNLINK` |
| [net/rras/ip/nath323](../../net/rras/ip/nath323) | 69 | [net/rras/ip/nath323/sources](../../net/rras/ip/nath323/sources), [net/rras/ip/nath323/makefile](../../net/rras/ip/nath323/makefile) | `nath323` | `LIBRARY` |
| [net/rras/ip/nathlp](../../net/rras/ip/nathlp) | 1 | [net/rras/ip/nathlp/dirs](../../net/rras/ip/nathlp/dirs) | — | — |
| [net/rras/ip/nathlp/alg](../../net/rras/ip/nathlp/alg) | 17 | [net/rras/ip/nathlp/alg/sources](../../net/rras/ip/nathlp/alg/sources), [net/rras/ip/nathlp/alg/makefile](../../net/rras/ip/nathlp/alg/makefile) | `natALG` | `LIBRARY` |
| [net/rras/ip/nathlp/dhcp](../../net/rras/ip/nathlp/dhcp) | 13 | [net/rras/ip/nathlp/dhcp/sources](../../net/rras/ip/nathlp/dhcp/sources), [net/rras/ip/nathlp/dhcp/makefile](../../net/rras/ip/nathlp/dhcp/makefile) | `natdhcp` | `LIBRARY` |
| [net/rras/ip/nathlp/dll](../../net/rras/ip/nathlp/dll) | 17 | [net/rras/ip/nathlp/dll/sources](../../net/rras/ip/nathlp/dll/sources), [net/rras/ip/nathlp/dll/makefile](../../net/rras/ip/nathlp/dll/makefile) | `ipnathlp` | `DYNLINK` |
| [net/rras/ip/nathlp/dns](../../net/rras/ip/nathlp/dns) | 17 | [net/rras/ip/nathlp/dns/sources](../../net/rras/ip/nathlp/dns/sources), [net/rras/ip/nathlp/dns/makefile](../../net/rras/ip/nathlp/dns/makefile) | `natdns` | `LIBRARY` |
| [net/rras/ip/nathlp/ftp](../../net/rras/ip/nathlp/ftp) | 13 | [net/rras/ip/nathlp/ftp/sources](../../net/rras/ip/nathlp/ftp/sources), [net/rras/ip/nathlp/ftp/makefile](../../net/rras/ip/nathlp/ftp/makefile) | `natftp` | `LIBRARY` |
| [net/rras/ip/nathlp/h323](../../net/rras/ip/nathlp/h323) | 7 | [net/rras/ip/nathlp/h323/sources](../../net/rras/ip/nathlp/h323/sources), [net/rras/ip/nathlp/h323/makefile](../../net/rras/ip/nathlp/h323/makefile) | `nath323p` | `LIBRARY` |
| [net/rras/ip/nathlp/idl](../../net/rras/ip/nathlp/idl) | 3 | [net/rras/ip/nathlp/idl/sources](../../net/rras/ip/nathlp/idl/sources), [net/rras/ip/nathlp/idl/makefile](../../net/rras/ip/nathlp/idl/makefile) | `idl` | `LIBRARY` |
| [net/rras/ip/nathlp/inc](../../net/rras/ip/nathlp/inc) | 19 | — | — | — |
| [net/rras/ip/nathlp/natapi](../../net/rras/ip/nathlp/natapi) | 5 | [net/rras/ip/nathlp/natapi/sources](../../net/rras/ip/nathlp/natapi/sources), [net/rras/ip/nathlp/natapi/makefile](../../net/rras/ip/nathlp/natapi/makefile) | `ipnatapi` | `LIBRARY` |
| [net/rras/ip/nathlp/natsvc](../../net/rras/ip/nathlp/natsvc) | 16 | [net/rras/ip/nathlp/natsvc/sources](../../net/rras/ip/nathlp/natsvc/sources), [net/rras/ip/nathlp/natsvc/makefile](../../net/rras/ip/nathlp/natsvc/makefile) | `natsvc` | `LIBRARY` |
| [net/rras/ip/nathlp/test](../../net/rras/ip/nathlp/test) | 1 | — | — | — |
| [net/rras/ip/priority](../../net/rras/ip/priority) | 6 | [net/rras/ip/priority/sources](../../net/rras/ip/priority/sources), [net/rras/ip/priority/makefile](../../net/rras/ip/priority/makefile) | `iprtprio` | `DYNLINK` |
| [net/rras/ip/rip](../../net/rras/ip/rip) | 24 | [net/rras/ip/rip/sources](../../net/rras/ip/rip/sources), [net/rras/ip/rip/makefile](../../net/rras/ip/rip/makefile) | `iprip2` | `DYNLINK` |
| [net/rras/ip/ripagnt](../../net/rras/ip/ripagnt) | 11 | [net/rras/ip/ripagnt/sources](../../net/rras/ip/ripagnt/sources), [net/rras/ip/ripagnt/makefile](../../net/rras/ip/ripagnt/makefile) | `ripagnt` | `DYNLINK` |
| [net/rras/ip/rtrmgr](../../net/rras/ip/rtrmgr) | 60 | [net/rras/ip/rtrmgr/sources](../../net/rras/ip/rtrmgr/sources), [net/rras/ip/rtrmgr/makefile](../../net/rras/ip/rtrmgr/makefile) | `iprtrmgr` | `DYNLINK` |
| [net/rras/ip/sample](../../net/rras/ip/sample) | 45 | [net/rras/ip/sample/sources](../../net/rras/ip/sample/sources), [net/rras/ip/sample/makefile](../../net/rras/ip/sample/makefile) | `ipsample` | `DYNLINK` |
| [net/rras/ip/utility](../../net/rras/ip/utility) | 1 | [net/rras/ip/utility/dirs](../../net/rras/ip/utility/dirs) | — | — |
| [net/rras/ip/utility/ipkern](../../net/rras/ip/utility/ipkern) | 15 | [net/rras/ip/utility/ipkern/sources](../../net/rras/ip/utility/ipkern/sources), [net/rras/ip/utility/ipkern/makefile](../../net/rras/ip/utility/ipkern/makefile) | `ipkern` | `PROGRAM` |
| [net/rras/ip/wanarp2](../../net/rras/ip/wanarp2) | 27 | [net/rras/ip/wanarp2/sources](../../net/rras/ip/wanarp2/sources), [net/rras/ip/wanarp2/makefile](../../net/rras/ip/wanarp2/makefile) | `wanarp` | `DRIVER` |
| [net/rras/ip/wanarp2/kdext](../../net/rras/ip/wanarp2/kdext) | 5 | [net/rras/ip/wanarp2/kdext/sources](../../net/rras/ip/wanarp2/kdext/sources), [net/rras/ip/wanarp2/kdext/makefile](../../net/rras/ip/wanarp2/kdext/makefile) | `wrp` | `DYNLINK` |
| [net/rras/ipx](../../net/rras/ipx) | 1 | [net/rras/ipx/dirs](../../net/rras/ipx/dirs) | — | — |
| [net/rras/ipx/adptif](../../net/rras/ipx/adptif) | 24 | [net/rras/ipx/adptif/sources](../../net/rras/ipx/adptif/sources), [net/rras/ipx/adptif/makefile](../../net/rras/ipx/adptif/makefile) | `adptif` | `DYNLINK` |
| [net/rras/ipx/autonet](../../net/rras/ipx/autonet) | 4 | [net/rras/ipx/autonet/sources](../../net/rras/ipx/autonet/sources), [net/rras/ipx/autonet/makefile](../../net/rras/ipx/autonet/makefile) | `autonet` | `LIBRARY` |
| [net/rras/ipx/inc](../../net/rras/ipx/inc) | 6 | — | — | — |
| [net/rras/ipx/ipxwan](../../net/rras/ipx/ipxwan) | 16 | [net/rras/ipx/ipxwan/sources](../../net/rras/ipx/ipxwan/sources), [net/rras/ipx/ipxwan/makefile](../../net/rras/ipx/ipxwan/makefile) | `ipxwan` | `DYNLINK` |
| [net/rras/ipx/rip](../../net/rras/ipx/rip) | 26 | [net/rras/ipx/rip/sources](../../net/rras/ipx/rip/sources), [net/rras/ipx/rip/makefile](../../net/rras/ipx/rip/makefile) | `ipxrip` | `DYNLINK` |
| [net/rras/ipx/rtrmgr](../../net/rras/ipx/rtrmgr) | 28 | [net/rras/ipx/rtrmgr/sources](../../net/rras/ipx/rtrmgr/sources), [net/rras/ipx/rtrmgr/makefile](../../net/rras/ipx/rtrmgr/makefile) | `ipxrtmgr` | `DYNLINK` |
| [net/rras/ipx/rtrmgr/test](../../net/rras/ipx/rtrmgr/test) | 6 | [net/rras/ipx/rtrmgr/test/sources](../../net/rras/ipx/rtrmgr/test/sources) | `router` | `PROGRAM` |
| [net/rras/ipx/sap](../../net/rras/ipx/sap) | 33 | [net/rras/ipx/sap/sources](../../net/rras/ipx/sap/sources), [net/rras/ipx/sap/makefile](../../net/rras/ipx/sap/makefile) | `ipxsap` | `DYNLINK` |
| [net/rras/ipx/sap/client](../../net/rras/ipx/sap/client) | 6 | [net/rras/ipx/sap/client/sources](../../net/rras/ipx/sap/client/sources), [net/rras/ipx/sap/client/makefile](../../net/rras/ipx/sap/client/makefile) | `nwsaplib` | `LIBRARY` |
| [net/rras/ipx/sap/test](../../net/rras/ipx/sap/test) | 6 | [net/rras/ipx/sap/test/sources](../../net/rras/ipx/sap/test/sources), [net/rras/ipx/sap/test/makefile](../../net/rras/ipx/sap/test/makefile) | `router` | `PROGRAM` |
| [net/rras/ipx/snmp](../../net/rras/ipx/snmp) | 19 | [net/rras/ipx/snmp/sources](../../net/rras/ipx/snmp/sources), [net/rras/ipx/snmp/makefile](../../net/rras/ipx/snmp/makefile) | `rtipxmib` | `DYNLINK` |
| [net/rras/mgm](../../net/rras/mgm) | 28 | [net/rras/mgm/sources](../../net/rras/mgm/sources), [net/rras/mgm/makefile](../../net/rras/mgm/makefile) | `mgm` | `LIBRARY` |
| [net/rras/mprmsg](../../net/rras/mprmsg) | 7 | [net/rras/mprmsg/sources](../../net/rras/mprmsg/sources), [net/rras/mprmsg/makefile](../../net/rras/mprmsg/makefile) | `mprmsg` | `DYNLINK` |
| [net/rras/ndis](../../net/rras/ndis) | 1 | [net/rras/ndis/dirs](../../net/rras/ndis/dirs) | — | — |
| [net/rras/ndis/asyncmac](../../net/rras/ndis/asyncmac) | 34 | [net/rras/ndis/asyncmac/sources](../../net/rras/ndis/asyncmac/sources), [net/rras/ndis/asyncmac/makefile](../../net/rras/ndis/asyncmac/makefile) | `asyncmac` | `DRIVER` |
| [net/rras/ndis/ndistapi](../../net/rras/ndis/ndistapi) | 6 | [net/rras/ndis/ndistapi/sources](../../net/rras/ndis/ndistapi/sources), [net/rras/ndis/ndistapi/makefile](../../net/rras/ndis/ndistapi/makefile) | `ndistapi` | `EXPORT_DRIVER` |
| [net/rras/ndis/ndiswan](../../net/rras/ndis/ndiswan) | 37 | [net/rras/ndis/ndiswan/dirs](../../net/rras/ndis/ndiswan/dirs) | — | — |
| [net/rras/ndis/ndiswan/export](../../net/rras/ndis/ndiswan/export) | 2 | [net/rras/ndis/ndiswan/export/sources](../../net/rras/ndis/ndiswan/export/sources), [net/rras/ndis/ndiswan/export/makefile](../../net/rras/ndis/ndiswan/export/makefile) | `ndiswan` | — |
| [net/rras/ndis/ndiswan/kdext](../../net/rras/ndis/ndiswan/kdext) | 9 | [net/rras/ndis/ndiswan/kdext/sources](../../net/rras/ndis/ndiswan/kdext/sources), [net/rras/ndis/ndiswan/kdext/makefile](../../net/rras/ndis/ndiswan/kdext/makefile) | `wanhelp` | `DYNLINK` |
| [net/rras/ndis/ndproxy](../../net/rras/ndis/ndproxy) | 16 | [net/rras/ndis/ndproxy/sources](../../net/rras/ndis/ndproxy/sources), [net/rras/ndis/ndproxy/makefile](../../net/rras/ndis/ndproxy/makefile) | `ndproxy` | `DRIVER` |
| [net/rras/ndis/ndproxy/kdext](../../net/rras/ndis/ndproxy/kdext) | 13 | [net/rras/ndis/ndproxy/kdext/sources](../../net/rras/ndis/ndproxy/kdext/sources), [net/rras/ndis/ndproxy/kdext/makefile](../../net/rras/ndis/ndproxy/kdext/makefile) | `pxkd` | `DYNLINK` |
| [net/rras/ndis/rasl2tp](../../net/rras/ndis/rasl2tp) | 25 | [net/rras/ndis/rasl2tp/sources](../../net/rras/ndis/rasl2tp/sources), [net/rras/ndis/rasl2tp/makefile](../../net/rras/ndis/rasl2tp/makefile) | `rasl2tp` | `DRIVER` |
| [net/rras/ndis/rasl2tp/kdext](../../net/rras/ndis/rasl2tp/kdext) | 13 | [net/rras/ndis/rasl2tp/kdext/sources](../../net/rras/ndis/rasl2tp/kdext/sources), [net/rras/ndis/rasl2tp/kdext/makefile](../../net/rras/ndis/rasl2tp/kdext/makefile) | `l2tp` | `DYNLINK` |
| [net/rras/ndis/raspppoe](../../net/rras/ndis/raspppoe) | 24 | [net/rras/ndis/raspppoe/sources](../../net/rras/ndis/raspppoe/sources), [net/rras/ndis/raspppoe/makefile](../../net/rras/ndis/raspppoe/makefile) | `raspppoe` | `DRIVER` |
| [net/rras/ndis/raspptp](../../net/rras/ndis/raspptp) | 2 | [net/rras/ndis/raspptp/dirs](../../net/rras/ndis/raspptp/dirs) | — | — |
| [net/rras/ndis/raspptp/common](../../net/rras/ndis/raspptp/common) | 15 | [net/rras/ndis/raspptp/common/sources](../../net/rras/ndis/raspptp/common/sources), [net/rras/ndis/raspptp/common/makefile](../../net/rras/ndis/raspptp/common/makefile) | `raspptp` | `DRIVER` |
| [net/rras/ndis/raspptp/nt](../../net/rras/ndis/raspptp/nt) | 8 | [net/rras/ndis/raspptp/nt/sources](../../net/rras/ndis/raspptp/nt/sources), [net/rras/ndis/raspptp/nt/makefile](../../net/rras/ndis/raspptp/nt/makefile) | `pptpnt` | `LIBRARY` |
| [net/rras/ndis/raspptp/pptpkdx](../../net/rras/ndis/raspptp/pptpkdx) | 5 | [net/rras/ndis/raspptp/pptpkdx/sources](../../net/rras/ndis/raspptp/pptpkdx/sources), [net/rras/ndis/raspptp/pptpkdx/makefile](../../net/rras/ndis/raspptp/pptpkdx/makefile) | `pptpkdx` | `DYNLINK` |
| [net/rras/ndis/raspti](../../net/rras/ndis/raspti) | 15 | [net/rras/ndis/raspti/sources](../../net/rras/ndis/raspti/sources), [net/rras/ndis/raspti/makefile](../../net/rras/ndis/raspti/makefile) | `raspti` | `DRIVER` |
| [net/rras/netsh](../../net/rras/netsh) | 1 | [net/rras/netsh/dirs](../../net/rras/netsh/dirs) | — | — |
| [net/rras/netsh/aaaa](../../net/rras/netsh/aaaa) | 25 | [net/rras/netsh/aaaa/sources](../../net/rras/netsh/aaaa/sources), [net/rras/netsh/aaaa/makefile](../../net/rras/netsh/aaaa/makefile) | `aaaamon` | `DYNLINK` |
| [net/rras/netsh/embedded](../../net/rras/netsh/embedded) | 9 | — | — | — |
| [net/rras/netsh/if](../../net/rras/netsh/if) | 26 | [net/rras/netsh/if/sources](../../net/rras/netsh/if/sources), [net/rras/netsh/if/makefile](../../net/rras/netsh/if/makefile) | `ifmon` | `DYNLINK` |
| [net/rras/netsh/inc](../../net/rras/netsh/inc) | 3 | — | — | — |
| [net/rras/netsh/ip](../../net/rras/netsh/ip) | 1 | [net/rras/netsh/ip/dirs](../../net/rras/netsh/ip/dirs) | — | — |
| [net/rras/netsh/ip/ipmon](../../net/rras/netsh/ip/ipmon) | 34 | [net/rras/netsh/ip/ipmon/sources](../../net/rras/netsh/ip/ipmon/sources), [net/rras/netsh/ip/ipmon/makefile](../../net/rras/netsh/ip/ipmon/makefile) | `ipmontr` | `DYNLINK` |
| [net/rras/netsh/ip/preview](../../net/rras/netsh/ip/preview) | 28 | [net/rras/netsh/ip/preview/sources](../../net/rras/netsh/ip/preview/sources), [net/rras/netsh/ip/preview/makefile](../../net/rras/netsh/ip/preview/makefile) | `ipprvwmon` | `DYNLINK` |
| [net/rras/netsh/ip/sample](../../net/rras/netsh/ip/sample) | 23 | [net/rras/netsh/ip/sample/sources](../../net/rras/netsh/ip/sample/sources), [net/rras/netsh/ip/sample/makefile](../../net/rras/netsh/ip/sample/makefile) | `ipsamplemn` | `DYNLINK` |
| [net/rras/netsh/ipx](../../net/rras/netsh/ipx) | 1 | [net/rras/netsh/ipx/dirs](../../net/rras/netsh/ipx/dirs) | — | — |
| [net/rras/netsh/ipx/ipxmon](../../net/rras/netsh/ipx/ipxmon) | 30 | [net/rras/netsh/ipx/ipxmon/sources](../../net/rras/netsh/ipx/ipxmon/sources), [net/rras/netsh/ipx/ipxmon/makefile](../../net/rras/netsh/ipx/ipxmon/makefile) | `ipxmontr` | `DYNLINK` |
| [net/rras/netsh/ipx/protocols](../../net/rras/netsh/ipx/protocols) | 33 | [net/rras/netsh/ipx/protocols/sources](../../net/rras/netsh/ipx/protocols/sources), [net/rras/netsh/ipx/protocols/makefile](../../net/rras/netsh/ipx/protocols/makefile) | `ipxpromn` | `DYNLINK` |
| [net/rras/netsh/ras](../../net/rras/netsh/ras) | 40 | [net/rras/netsh/ras/sources](../../net/rras/netsh/ras/sources), [net/rras/netsh/ras/makefile](../../net/rras/netsh/ras/makefile) | `rasmontr` | `DYNLINK` |
| [net/rras/netsh/shell](../../net/rras/netsh/shell) | 21 | [net/rras/netsh/shell/sources](../../net/rras/netsh/shell/sources), [net/rras/netsh/shell/makefile](../../net/rras/netsh/shell/makefile) | `netsh` | `PROGLIB` |
| [net/rras/ras](../../net/rras/ras) | 1 | [net/rras/ras/dirs](../../net/rras/ras/dirs) | — | — |
| [net/rras/ras/autodial](../../net/rras/ras/autodial) | 1 | [net/rras/ras/autodial/dirs](../../net/rras/ras/autodial/dirs) | — | — |
| [net/rras/ras/autodial/rasacd](../../net/rras/ras/autodial/rasacd) | 15 | [net/rras/ras/autodial/rasacd/sources](../../net/rras/ras/autodial/rasacd/sources), [net/rras/ras/autodial/rasacd/makefile](../../net/rras/ras/autodial/rasacd/makefile) | `rasacd` | `DRIVER` |
| [net/rras/ras/autodial/rasadhlp](../../net/rras/ras/autodial/rasadhlp) | 8 | [net/rras/ras/autodial/rasadhlp/sources](../../net/rras/ras/autodial/rasadhlp/sources), [net/rras/ras/autodial/rasadhlp/makefile](../../net/rras/ras/autodial/rasadhlp/makefile) | `rasadhlp` | `DYNLINK` |
| [net/rras/ras/autodial/rasauto](../../net/rras/ras/autodial/rasauto) | 30 | [net/rras/ras/autodial/rasauto/sources](../../net/rras/ras/autodial/rasauto/sources), [net/rras/ras/autodial/rasauto/makefile](../../net/rras/ras/autodial/rasauto/makefile) | `rasauto` | `DYNLINK` |
| [net/rras/ras/autodial/rasautou](../../net/rras/ras/autodial/rasautou) | 5 | [net/rras/ras/autodial/rasautou/sources](../../net/rras/ras/autodial/rasautou/sources), [net/rras/ras/autodial/rasautou/makefile](../../net/rras/ras/autodial/rasautou/makefile) | `rasautou` | `PROGRAM` |
| [net/rras/ras/ddm](../../net/rras/ras/ddm) | 33 | [net/rras/ras/ddm/sources](../../net/rras/ras/ddm/sources), [net/rras/ras/ddm/makefile](../../net/rras/ras/ddm/makefile) | `mprddm` | `DYNLINK` |
| [net/rras/ras/hlp](../../net/rras/ras/hlp) | 12 | [net/rras/ras/hlp/sources](../../net/rras/ras/hlp/sources), [net/rras/ras/hlp/makefile](../../net/rras/ras/hlp/makefile) | — | `NOTARGET` |
| [net/rras/ras/idl](../../net/rras/ras/idl) | 5 | [net/rras/ras/idl/sources](../../net/rras/ras/idl/sources), [net/rras/ras/idl/makefile](../../net/rras/ras/idl/makefile) | — | `NOTARGET` |
| [net/rras/ras/inc](../../net/rras/ras/inc) | 25 | — | — | — |
| [net/rras/ras/inf](../../net/rras/ras/inf) | 5 | [net/rras/ras/inf/sources](../../net/rras/ras/inf/sources), [net/rras/ras/inf/makefile](../../net/rras/ras/inf/makefile) | — | `NOTARGET` |
| [net/rras/ras/ini](../../net/rras/ras/ini) | 3 | [net/rras/ras/ini/sources](../../net/rras/ras/ini/sources), [net/rras/ras/ini/makefile](../../net/rras/ras/ini/makefile) | — | `NOTARGET` |
| [net/rras/ras/ppp](../../net/rras/ras/ppp) | 1 | [net/rras/ras/ppp/dirs](../../net/rras/ras/ppp/dirs) | — | — |
| [net/rras/ras/ppp/auth](../../net/rras/ras/ppp/auth) | 1 | [net/rras/ras/ppp/auth/dirs](../../net/rras/ras/ppp/auth/dirs) | — | — |
| [net/rras/ras/ppp/auth/nt](../../net/rras/ras/ppp/auth/nt) | 7 | [net/rras/ras/ppp/auth/nt/sources](../../net/rras/ras/ppp/auth/nt/sources), [net/rras/ras/ppp/auth/nt/makefile](../../net/rras/ras/ppp/auth/nt/makefile) | `rasauth` | `LIBRARY` |
| [net/rras/ras/ppp/auth/radius](../../net/rras/ras/ppp/auth/radius) | 17 | [net/rras/ras/ppp/auth/radius/sources](../../net/rras/ras/ppp/auth/radius/sources), [net/rras/ras/ppp/auth/radius/makefile](../../net/rras/ras/ppp/auth/radius/makefile) | `rasrad` | `DYNLINK` |
| [net/rras/ras/ppp/auth/radius/test](../../net/rras/ras/ppp/auth/radius/test) | 1 | — | — | — |
| [net/rras/ras/ppp/common](../../net/rras/ras/ppp/common) | 12 | [net/rras/ras/ppp/common/sources](../../net/rras/ras/ppp/common/sources), [net/rras/ras/ppp/common/makefile](../../net/rras/ras/ppp/common/makefile) | `ppputil` | `LIBRARY` |
| [net/rras/ras/ppp/eaptls](../../net/rras/ras/ppp/eaptls) | 14 | [net/rras/ras/ppp/eaptls/sources](../../net/rras/ras/ppp/eaptls/sources), [net/rras/ras/ppp/eaptls/makefile](../../net/rras/ras/ppp/eaptls/makefile) | `rastls` | `DYNLINK` |
| [net/rras/ras/ppp/engine](../../net/rras/ras/ppp/engine) | 30 | [net/rras/ras/ppp/engine/sources](../../net/rras/ras/ppp/engine/sources), [net/rras/ras/ppp/engine/makefile](../../net/rras/ras/ppp/engine/makefile) | `rasppp` | `DYNLINK` |
| [net/rras/ras/ppp/rasatcp](../../net/rras/ras/ppp/rasatcp) | 6 | [net/rras/ras/ppp/rasatcp/sources](../../net/rras/ras/ppp/rasatcp/sources), [net/rras/ras/ppp/rasatcp/makefile](../../net/rras/ras/ppp/rasatcp/makefile) | `rasatcp` | `LIBRARY` |
| [net/rras/ras/ppp/rasbacp](../../net/rras/ras/ppp/rasbacp) | 5 | [net/rras/ras/ppp/rasbacp/sources](../../net/rras/ras/ppp/rasbacp/sources), [net/rras/ras/ppp/rasbacp/makefile](../../net/rras/ras/ppp/rasbacp/makefile) | `rasbacp` | `LIBRARY` |
| [net/rras/ras/ppp/rascbcp](../../net/rras/ras/ppp/rascbcp) | 5 | [net/rras/ras/ppp/rascbcp/sources](../../net/rras/ras/ppp/rascbcp/sources), [net/rras/ras/ppp/rascbcp/makefile](../../net/rras/ras/ppp/rascbcp/makefile) | `rascbcp` | `LIBRARY` |
| [net/rras/ras/ppp/rasccp](../../net/rras/ras/ppp/rasccp) | 5 | [net/rras/ras/ppp/rasccp/sources](../../net/rras/ras/ppp/rasccp/sources), [net/rras/ras/ppp/rasccp/makefile](../../net/rras/ras/ppp/rasccp/makefile) | `rasccp` | `LIBRARY` |
| [net/rras/ras/ppp/raschap](../../net/rras/ras/ppp/raschap) | 18 | [net/rras/ras/ppp/raschap/sources](../../net/rras/ras/ppp/raschap/sources), [net/rras/ras/ppp/raschap/makefile](../../net/rras/ras/ppp/raschap/makefile) | `raschap` | `DYNLINK` |
| [net/rras/ras/ppp/raseap](../../net/rras/ras/ppp/raseap) | 5 | [net/rras/ras/ppp/raseap/sources](../../net/rras/ras/ppp/raseap/sources), [net/rras/ras/ppp/raseap/makefile](../../net/rras/ras/ppp/raseap/makefile) | `raseap` | `LIBRARY` |
| [net/rras/ras/ppp/raseap/test](../../net/rras/ras/ppp/raseap/test) | 13 | [net/rras/ras/ppp/raseap/test/sources](../../net/rras/ras/ppp/raseap/test/sources), [net/rras/ras/ppp/raseap/test/makefile](../../net/rras/ras/ppp/raseap/test/makefile) | `eap` | `DYNLINK` |
| [net/rras/ras/ppp/rasipcp](../../net/rras/ras/ppp/rasipcp) | 5 | [net/rras/ras/ppp/rasipcp/sources](../../net/rras/ras/ppp/rasipcp/sources), [net/rras/ras/ppp/rasipcp/makefile](../../net/rras/ras/ppp/rasipcp/makefile) | `rasipcp` | `LIBRARY` |
| [net/rras/ras/ppp/rasiphlp](../../net/rras/ras/ppp/rasiphlp) | 26 | [net/rras/ras/ppp/rasiphlp/sources](../../net/rras/ras/ppp/rasiphlp/sources), [net/rras/ras/ppp/rasiphlp/makefile](../../net/rras/ras/ppp/rasiphlp/makefile) | `rasiphlp` | `LIBRARY` |
| [net/rras/ras/ppp/rasipxcp](../../net/rras/ras/ppp/rasipxcp) | 21 | [net/rras/ras/ppp/rasipxcp/sources](../../net/rras/ras/ppp/rasipxcp/sources), [net/rras/ras/ppp/rasipxcp/makefile](../../net/rras/ras/ppp/rasipxcp/makefile) | `rasipxcp` | `LIBRARY` |
| [net/rras/ras/ppp/raspap](../../net/rras/ras/ppp/raspap) | 5 | [net/rras/ras/ppp/raspap/sources](../../net/rras/ras/ppp/raspap/sources), [net/rras/ras/ppp/raspap/makefile](../../net/rras/ras/ppp/raspap/makefile) | `raspap` | `LIBRARY` |
| [net/rras/ras/rasman](../../net/rras/ras/rasman) | 1 | [net/rras/ras/rasman/dirs](../../net/rras/ras/rasman/dirs) | — | — |
| [net/rras/ras/rasman/common](../../net/rras/ras/rasman/common) | 1 | [net/rras/ras/rasman/common/dirs](../../net/rras/ras/rasman/common/dirs) | — | — |
| [net/rras/ras/rasman/common/inc](../../net/rras/ras/rasman/common/inc) | 4 | — | — | — |
| [net/rras/ras/rasman/common/reghelp](../../net/rras/ras/rasman/common/reghelp) | 3 | [net/rras/ras/rasman/common/reghelp/sources](../../net/rras/ras/rasman/common/reghelp/sources), [net/rras/ras/rasman/common/reghelp/makefile](../../net/rras/ras/rasman/common/reghelp/makefile) | `reghelp` | `LIBRARY` |
| [net/rras/ras/rasman/dll](../../net/rras/ras/rasman/dll) | 14 | [net/rras/ras/rasman/dll/sources](../../net/rras/ras/rasman/dll/sources), [net/rras/ras/rasman/dll/makefile](../../net/rras/ras/rasman/dll/makefile) | `rasman` | `DYNLINK` |
| [net/rras/ras/rasman/mxs32](../../net/rras/ras/rasman/mxs32) | 8 | [net/rras/ras/rasman/mxs32/sources](../../net/rras/ras/rasman/mxs32/sources), [net/rras/ras/rasman/mxs32/makefile](../../net/rras/ras/rasman/mxs32/makefile) | `rasmxs` | `DYNLINK` |
| [net/rras/ras/rasman/mxswrap](../../net/rras/ras/rasman/mxswrap) | 5 | [net/rras/ras/rasman/mxswrap/sources](../../net/rras/ras/rasman/mxswrap/sources), [net/rras/ras/rasman/mxswrap/makefile](../../net/rras/ras/rasman/mxswrap/makefile) | `mxswrap` | `LIBRARY` |
| [net/rras/ras/rasman/rasman](../../net/rras/ras/rasman/rasman) | 34 | [net/rras/ras/rasman/rasman/sources](../../net/rras/ras/rasman/rasman/sources), [net/rras/ras/rasman/rasman/makefile](../../net/rras/ras/rasman/rasman/makefile) | `rasmans` | `DYNLINK` |
| [net/rras/ras/rasman/serial32](../../net/rras/ras/rasman/serial32) | 7 | [net/rras/ras/rasman/serial32/sources](../../net/rras/ras/rasman/serial32/sources), [net/rras/ras/rasman/serial32/makefile](../../net/rras/ras/rasman/serial32/makefile) | `rasser` | `DYNLINK` |
| [net/rras/ras/rasman/tapi32](../../net/rras/ras/rasman/tapi32) | 12 | [net/rras/ras/rasman/tapi32/sources](../../net/rras/ras/rasman/tapi32/sources), [net/rras/ras/rasman/tapi32/makefile](../../net/rras/ras/rasman/tapi32/makefile) | `rastapi` | `DYNLINK` |
| [net/rras/ras/rassfm](../../net/rras/ras/rassfm) | 15 | [net/rras/ras/rassfm/sources](../../net/rras/ras/rassfm/sources), [net/rras/ras/rassfm/makefile](../../net/rras/ras/rassfm/makefile) | `rassfm` | `DYNLINK` |
| [net/rras/ras/rassld](../../net/rras/ras/rassld) | 9 | [net/rras/ras/rassld/sources](../../net/rras/ras/rassld/sources), [net/rras/ras/rassld/makefile](../../net/rras/ras/rassld/makefile) | — | `NOTARGET` |
| [net/rras/ras/scp](../../net/rras/ras/scp) | 6 | [net/rras/ras/scp/sources](../../net/rras/ras/scp/sources), [net/rras/ras/scp/makefile](../../net/rras/ras/scp/makefile) | — | `NOTARGET` |
| [net/rras/ras/ui](../../net/rras/ras/ui) | 1 | [net/rras/ras/ui/dirs](../../net/rras/ras/ui/dirs) | — | — |
| [net/rras/ras/ui/common](../../net/rras/ras/ui/common) | 1 | [net/rras/ras/ui/common/dirs](../../net/rras/ras/ui/common/dirs) | — | — |
| [net/rras/ras/ui/common/debug](../../net/rras/ras/ui/common/debug) | 3 | [net/rras/ras/ui/common/debug/sources](../../net/rras/ras/ui/common/debug/sources), [net/rras/ras/ui/common/debug/makefile](../../net/rras/ras/ui/common/debug/makefile) | `debug` | `LIBRARY` |
| [net/rras/ras/ui/common/inc](../../net/rras/ras/ui/common/inc) | 1 | [net/rras/ras/ui/common/inc/makefile](../../net/rras/ras/ui/common/inc/makefile) | — | — |
| [net/rras/ras/ui/common/nouiutil](../../net/rras/ras/ui/common/nouiutil) | 20 | [net/rras/ras/ui/common/nouiutil/sources](../../net/rras/ras/ui/common/nouiutil/sources), [net/rras/ras/ui/common/nouiutil/makefile](../../net/rras/ras/ui/common/nouiutil/makefile) | `nouiutil` | `LIBRARY` |
| [net/rras/ras/ui/common/pbk](../../net/rras/ras/ui/common/pbk) | 8 | [net/rras/ras/ui/common/pbk/sources](../../net/rras/ras/ui/common/pbk/sources), [net/rras/ras/ui/common/pbk/makefile](../../net/rras/ras/ui/common/pbk/makefile) | `pbk` | `LIBRARY` |
| [net/rras/ras/ui/common/phonenum](../../net/rras/ras/ui/common/phonenum) | 3 | [net/rras/ras/ui/common/phonenum/sources](../../net/rras/ras/ui/common/phonenum/sources), [net/rras/ras/ui/common/phonenum/makefile](../../net/rras/ras/ui/common/phonenum/makefile) | `phonenum` | `LIBRARY` |
| [net/rras/ras/ui/common/rnk](../../net/rras/ras/ui/common/rnk) | 3 | [net/rras/ras/ui/common/rnk/sources](../../net/rras/ras/ui/common/rnk/sources), [net/rras/ras/ui/common/rnk/makefile](../../net/rras/ras/ui/common/rnk/makefile) | `rnk` | `LIBRARY` |
| [net/rras/ras/ui/common/sharing](../../net/rras/ras/ui/common/sharing) | 8 | [net/rras/ras/ui/common/sharing/sources](../../net/rras/ras/ui/common/sharing/sources), [net/rras/ras/ui/common/sharing/makefile](../../net/rras/ras/ui/common/sharing/makefile) | `rasshare` | `LIBRARY` |
| [net/rras/ras/ui/common/tapiutil](../../net/rras/ras/ui/common/tapiutil) | 3 | [net/rras/ras/ui/common/tapiutil/sources](../../net/rras/ras/ui/common/tapiutil/sources), [net/rras/ras/ui/common/tapiutil/makefile](../../net/rras/ras/ui/common/tapiutil/makefile) | `tapiutil` | `LIBRARY` |
| [net/rras/ras/ui/common/uiutil](../../net/rras/ras/ui/common/uiutil) | 11 | [net/rras/ras/ui/common/uiutil/sources](../../net/rras/ras/ui/common/uiutil/sources), [net/rras/ras/ui/common/uiutil/makefile](../../net/rras/ras/ui/common/uiutil/makefile) | `uiutil` | `LIBRARY` |
| [net/rras/ras/ui/extapi](../../net/rras/ras/ui/extapi) | 1 | [net/rras/ras/ui/extapi/dirs](../../net/rras/ras/ui/extapi/dirs) | — | — |
| [net/rras/ras/ui/extapi/src](../../net/rras/ras/ui/extapi/src) | 20 | [net/rras/ras/ui/extapi/src/sources](../../net/rras/ras/ui/extapi/src/sources), [net/rras/ras/ui/extapi/src/makefile](../../net/rras/ras/ui/extapi/src/makefile) | `rasapi32` | `DYNLINK` |
| [net/rras/ras/ui/extapi/xlate](../../net/rras/ras/ui/extapi/xlate) | 4 | [net/rras/ras/ui/extapi/xlate/sources](../../net/rras/ras/ui/extapi/xlate/sources), [net/rras/ras/ui/extapi/xlate/makefile](../../net/rras/ras/ui/extapi/xlate/makefile) | `dummy` | `LIBRARY` |
| [net/rras/ras/ui/inc](../../net/rras/ras/ui/inc) | 61 | — | — | — |
| [net/rras/ras/ui/nt4](../../net/rras/ras/ui/nt4) | 1 | [net/rras/ras/ui/nt4/dirs](../../net/rras/ras/ui/nt4/dirs) | — | — |
| [net/rras/ras/ui/nt4/common](../../net/rras/ras/ui/nt4/common) | 1 | [net/rras/ras/ui/nt4/common/dirs](../../net/rras/ras/ui/nt4/common/dirs) | — | — |
| [net/rras/ras/ui/nt4/common/debug](../../net/rras/ras/ui/nt4/common/debug) | 3 | [net/rras/ras/ui/nt4/common/debug/sources](../../net/rras/ras/ui/nt4/common/debug/sources), [net/rras/ras/ui/nt4/common/debug/makefile](../../net/rras/ras/ui/nt4/common/debug/makefile) | `debug` | `LIBRARY` |
| [net/rras/ras/ui/nt4/common/nouiutil](../../net/rras/ras/ui/nt4/common/nouiutil) | 11 | [net/rras/ras/ui/nt4/common/nouiutil/sources](../../net/rras/ras/ui/nt4/common/nouiutil/sources), [net/rras/ras/ui/nt4/common/nouiutil/makefile](../../net/rras/ras/ui/nt4/common/nouiutil/makefile) | `nouiutil` | `LIBRARY` |
| [net/rras/ras/ui/nt4/common/pbk](../../net/rras/ras/ui/nt4/common/pbk) | 6 | [net/rras/ras/ui/nt4/common/pbk/sources](../../net/rras/ras/ui/nt4/common/pbk/sources), [net/rras/ras/ui/nt4/common/pbk/makefile](../../net/rras/ras/ui/nt4/common/pbk/makefile) | `pbk` | `LIBRARY` |
| [net/rras/ras/ui/nt4/common/phonenum](../../net/rras/ras/ui/nt4/common/phonenum) | 3 | [net/rras/ras/ui/nt4/common/phonenum/sources](../../net/rras/ras/ui/nt4/common/phonenum/sources), [net/rras/ras/ui/nt4/common/phonenum/makefile](../../net/rras/ras/ui/nt4/common/phonenum/makefile) | `phonenum` | `LIBRARY` |
| [net/rras/ras/ui/nt4/common/rnk](../../net/rras/ras/ui/nt4/common/rnk) | 3 | [net/rras/ras/ui/nt4/common/rnk/sources](../../net/rras/ras/ui/nt4/common/rnk/sources), [net/rras/ras/ui/nt4/common/rnk/makefile](../../net/rras/ras/ui/nt4/common/rnk/makefile) | `rnk` | `LIBRARY` |
| [net/rras/ras/ui/nt4/common/tapiutil](../../net/rras/ras/ui/nt4/common/tapiutil) | 3 | [net/rras/ras/ui/nt4/common/tapiutil/sources](../../net/rras/ras/ui/nt4/common/tapiutil/sources), [net/rras/ras/ui/nt4/common/tapiutil/makefile](../../net/rras/ras/ui/nt4/common/tapiutil/makefile) | `tapiutil` | `LIBRARY` |
| [net/rras/ras/ui/nt4/common/uiutil](../../net/rras/ras/ui/nt4/common/uiutil) | 11 | [net/rras/ras/ui/nt4/common/uiutil/sources](../../net/rras/ras/ui/nt4/common/uiutil/sources), [net/rras/ras/ui/nt4/common/uiutil/makefile](../../net/rras/ras/ui/nt4/common/uiutil/makefile) | `uiutil` | `LIBRARY` |
| [net/rras/ras/ui/nt4/inc](../../net/rras/ras/ui/nt4/inc) | 40 | — | — | — |
| [net/rras/ras/ui/nt4/rasdlg](../../net/rras/ras/ui/nt4/rasdlg) | 30 | [net/rras/ras/ui/nt4/rasdlg/sources](../../net/rras/ras/ui/nt4/rasdlg/sources), [net/rras/ras/ui/nt4/rasdlg/makefile](../../net/rras/ras/ui/nt4/rasdlg/makefile) | `rasdlg4` | `DYNLINK` |
| [net/rras/ras/ui/perf](../../net/rras/ras/ui/perf) | 18 | [net/rras/ras/ui/perf/sources](../../net/rras/ras/ui/perf/sources), [net/rras/ras/ui/perf/makefile](../../net/rras/ras/ui/perf/makefile) | `rasctrs` | `DYNLINK` |
| [net/rras/ras/ui/rasadmin](../../net/rras/ras/ui/rasadmin) | 1 | [net/rras/ras/ui/rasadmin/dirs](../../net/rras/ras/ui/rasadmin/dirs) | — | — |
| [net/rras/ras/ui/rasadmin/api](../../net/rras/ras/ui/rasadmin/api) | 15 | [net/rras/ras/ui/rasadmin/api/sources](../../net/rras/ras/ui/rasadmin/api/sources), [net/rras/ras/ui/rasadmin/api/makefile](../../net/rras/ras/ui/rasadmin/api/makefile) | `rassapi` | `DYNLINK` |
| [net/rras/ras/ui/rasdial](../../net/rras/ras/ui/rasdial) | 1 | [net/rras/ras/ui/rasdial/dirs](../../net/rras/ras/ui/rasdial/dirs) | — | — |
| [net/rras/ras/ui/rasdial/src](../../net/rras/ras/ui/rasdial/src) | 4 | [net/rras/ras/ui/rasdial/src/sources](../../net/rras/ras/ui/rasdial/src/sources), [net/rras/ras/ui/rasdial/src/makefile](../../net/rras/ras/ui/rasdial/src/makefile) | `rasdial` | `PROGRAM` |
| [net/rras/ras/ui/rasdial/xlate](../../net/rras/ras/ui/rasdial/xlate) | 4 | [net/rras/ras/ui/rasdial/xlate/sources](../../net/rras/ras/ui/rasdial/xlate/sources), [net/rras/ras/ui/rasdial/xlate/makefile](../../net/rras/ras/ui/rasdial/xlate/makefile) | `dummy` | `LIBRARY` |
| [net/rras/ras/ui/rasdlg](../../net/rras/ras/ui/rasdlg) | 39 | [net/rras/ras/ui/rasdlg/sources](../../net/rras/ras/ui/rasdlg/sources), [net/rras/ras/ui/rasdlg/makefile](../../net/rras/ras/ui/rasdlg/makefile) | `rasdlg` | `DYNLINK` |
| [net/rras/ras/ui/rasphone](../../net/rras/ras/ui/rasphone) | 10 | [net/rras/ras/ui/rasphone/sources](../../net/rras/ras/ui/rasphone/sources), [net/rras/ras/ui/rasphone/makefile](../../net/rras/ras/ui/rasphone/makefile) | `rasphone` | `PROGRAM` |
| [net/rras/ras/ui/rasscrpt](../../net/rras/ras/ui/rasscrpt) | 27 | [net/rras/ras/ui/rasscrpt/sources](../../net/rras/ras/ui/rasscrpt/sources), [net/rras/ras/ui/rasscrpt/makefile](../../net/rras/ras/ui/rasscrpt/makefile) | `rasscrpt` | `LIBRARY` |
| [net/rras/ras/ui/rassrvui](../../net/rras/ras/ui/rassrvui) | 39 | [net/rras/ras/ui/rassrvui/sources](../../net/rras/ras/ui/rassrvui/sources), [net/rras/ras/ui/rassrvui/makefile](../../net/rras/ras/ui/rassrvui/makefile) | `rassrvui` | `LIBRARY` |
| [net/rras/ras/ui/rassrvui/test](../../net/rras/ras/ui/rassrvui/test) | 5 | [net/rras/ras/ui/rassrvui/test/sources](../../net/rras/ras/ui/rassrvui/test/sources), [net/rras/ras/ui/rassrvui/test/makefile](../../net/rras/ras/ui/rassrvui/test/makefile) | `test` | `PROGRAM` |
| [net/rras/routemon](../../net/rras/routemon) | 15 | [net/rras/routemon/sources](../../net/rras/routemon/sources), [net/rras/routemon/makefile](../../net/rras/routemon/makefile) | `routemon` | `PROGRAM` |
| [net/rras/rtm](../../net/rras/rtm) | 19 | [net/rras/rtm/sources](../../net/rras/rtm/sources), [net/rras/rtm/makefile](../../net/rras/rtm/makefile) | `rtmv1` | `LIBRARY` |
| [net/rras/rtmv2](../../net/rras/rtmv2) | 55 | [net/rras/rtmv2/sources](../../net/rras/rtmv2/sources), [net/rras/rtmv2/makefile](../../net/rras/rtmv2/makefile) | `rtm` | `DYNLINK` |
| [net/rras/upgrade](../../net/rras/upgrade) | 1 | [net/rras/upgrade/dirs](../../net/rras/upgrade/dirs) | — | — |
| [net/rras/upgrade/steelhead2nt5](../../net/rras/upgrade/steelhead2nt5) | 13 | [net/rras/upgrade/steelhead2nt5/sources](../../net/rras/upgrade/steelhead2nt5/sources), [net/rras/upgrade/steelhead2nt5/makefile](../../net/rras/upgrade/steelhead2nt5/makefile) | `rtrupg` | `DYNLINK` |
| [net/rras/upgrade/tools](../../net/rras/upgrade/tools) | 1 | [net/rras/upgrade/tools/dirs](../../net/rras/upgrade/tools/dirs) | — | — |
| [net/rras/upgrade/tools/b3rasace](../../net/rras/upgrade/tools/b3rasace) | 5 | [net/rras/upgrade/tools/b3rasace/sources](../../net/rras/upgrade/tools/b3rasace/sources), [net/rras/upgrade/tools/b3rasace/makefile](../../net/rras/upgrade/tools/b3rasace/makefile) | `b3rasace` | `PROGRAM` |

## `net/sfm/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/sfm](../../net/sfm) | 1 | [net/sfm/dirs](../../net/sfm/dirs) | — | — |
| [net/sfm/afp](../../net/sfm/afp) | 2 | [net/sfm/afp/dirs](../../net/sfm/afp/dirs) | — | — |
| [net/sfm/afp/componentdef](../../net/sfm/afp/componentdef) | 5 | [net/sfm/afp/componentdef/sources](../../net/sfm/afp/componentdef/sources), [net/sfm/afp/componentdef/makefile](../../net/sfm/afp/componentdef/makefile) | — | `NOTARGET` |
| [net/sfm/afp/inc](../../net/sfm/afp/inc) | 4 | — | — | — |
| [net/sfm/afp/messages](../../net/sfm/afp/messages) | 7 | [net/sfm/afp/messages/sources](../../net/sfm/afp/messages/sources), [net/sfm/afp/messages/makefile](../../net/sfm/afp/messages/makefile) | `sfmmsg` | `DYNLINK` |
| [net/sfm/afp/server](../../net/sfm/afp/server) | 79 | [net/sfm/afp/server/sources](../../net/sfm/afp/server/sources), [net/sfm/afp/server/makefile](../../net/sfm/afp/server/makefile) | `sfmsrv` | `DRIVER` |
| [net/sfm/afp/service](../../net/sfm/afp/service) | 1 | [net/sfm/afp/service/dirs](../../net/sfm/afp/service/dirs) | — | — |
| [net/sfm/afp/service/client](../../net/sfm/afp/service/client) | 9 | [net/sfm/afp/service/client/sources](../../net/sfm/afp/service/client/sources), [net/sfm/afp/service/client/makefile](../../net/sfm/afp/service/client/makefile) | `sfmapi` | `DYNLINK` |
| [net/sfm/afp/service/idl](../../net/sfm/afp/service/idl) | 7 | [net/sfm/afp/service/idl/sources](../../net/sfm/afp/service/idl/sources), [net/sfm/afp/service/idl/makefile](../../net/sfm/afp/service/idl/makefile) | — | `NOTARGET` |
| [net/sfm/afp/service/server](../../net/sfm/afp/service/server) | 28 | [net/sfm/afp/service/server/sources](../../net/sfm/afp/service/server/sources), [net/sfm/afp/service/server/makefile](../../net/sfm/afp/service/server/makefile) | `sfmsvc` | `PROGRAM` |
| [net/sfm/afp/sfmctrs](../../net/sfm/afp/sfmctrs) | 15 | [net/sfm/afp/sfmctrs/sources](../../net/sfm/afp/sfmctrs/sources), [net/sfm/afp/sfmctrs/makefile](../../net/sfm/afp/sfmctrs/makefile) | `sfmctrs` | `DYNLINK` |
| [net/sfm/afp/ui](../../net/sfm/afp/ui) | 1 | [net/sfm/afp/ui/dirs](../../net/sfm/afp/ui/dirs) | — | — |
| [net/sfm/afp/ui/afpmgr](../../net/sfm/afp/ui/afpmgr) | 48 | [net/sfm/afp/ui/afpmgr/sources](../../net/sfm/afp/ui/afpmgr/sources), [net/sfm/afp/ui/afpmgr/makefile](../../net/sfm/afp/ui/afpmgr/makefile) | `sfmmgr` | `DYNLINK` |
| [net/sfm/afp/ui/cmdline](../../net/sfm/afp/ui/cmdline) | 7 | [net/sfm/afp/ui/cmdline/sources](../../net/sfm/afp/ui/cmdline/sources), [net/sfm/afp/ui/cmdline/makefile](../../net/sfm/afp/ui/cmdline/makefile) | `macfile` | `PROGRAM` |
| [net/sfm/afp/ui/xlate](../../net/sfm/afp/ui/xlate) | 17 | [net/sfm/afp/ui/xlate/sources](../../net/sfm/afp/ui/xlate/sources), [net/sfm/afp/ui/xlate/makefile](../../net/sfm/afp/ui/xlate/makefile) | `afpmgr` | `LIBRARY` |
| [net/sfm/atalk](../../net/sfm/atalk) | 1 | [net/sfm/atalk/dirs](../../net/sfm/atalk/dirs) | — | — |
| [net/sfm/atalk/componentdef](../../net/sfm/atalk/componentdef) | 4 | [net/sfm/atalk/componentdef/sources](../../net/sfm/atalk/componentdef/sources), [net/sfm/atalk/componentdef/makefile](../../net/sfm/atalk/componentdef/makefile) | — | `NOTARGET` |
| [net/sfm/atalk/messages](../../net/sfm/atalk/messages) | 7 | [net/sfm/atalk/messages/sources](../../net/sfm/atalk/messages/sources), [net/sfm/atalk/messages/makefile](../../net/sfm/atalk/messages/makefile) | `sfmatmsg` | `DYNLINK` |
| [net/sfm/atalk/perfctrs](../../net/sfm/atalk/perfctrs) | 14 | [net/sfm/atalk/perfctrs/sources](../../net/sfm/atalk/perfctrs/sources), [net/sfm/atalk/perfctrs/makefile](../../net/sfm/atalk/perfctrs/makefile) | `atkctrs` | `DYNLINK` |
| [net/sfm/atalk/sys](../../net/sfm/atalk/sys) | 70 | [net/sfm/atalk/sys/sources](../../net/sfm/atalk/sys/sources), [net/sfm/atalk/sys/makefile](../../net/sfm/atalk/sys/makefile) | `sfmatalk` | `DRIVER` |
| [net/sfm/atalk/winsock](../../net/sfm/atalk/winsock) | 9 | [net/sfm/atalk/winsock/sources](../../net/sfm/atalk/winsock/sources), [net/sfm/atalk/winsock/makefile](../../net/sfm/atalk/winsock/makefile) | `sfmwshat` | `DYNLINK` |
| [net/sfm/inc](../../net/sfm/inc) | 1 | — | — | — |
| [net/sfm/setup](../../net/sfm/setup) | 1 | [net/sfm/setup/dirs](../../net/sfm/setup/dirs) | — | — |
| [net/sfm/setup/infs](../../net/sfm/setup/infs) | 3 | — | — | — |
| [net/sfm/setup/resource](../../net/sfm/setup/resource) | 7 | [net/sfm/setup/resource/sources](../../net/sfm/setup/resource/sources), [net/sfm/setup/resource/makefile](../../net/sfm/setup/resource/makefile) | `sfmres` | `DYNLINK` |
| [net/sfm/setup/sfmreg](../../net/sfm/setup/sfmreg) | 4 | [net/sfm/setup/sfmreg/sources](../../net/sfm/setup/sfmreg/sources), [net/sfm/setup/sfmreg/makefile](../../net/sfm/setup/sfmreg/makefile) | `sfmreg` | `PROGRAM` |
| [net/sfm/setup/util](../../net/sfm/setup/util) | 7 | [net/sfm/setup/util/sources](../../net/sfm/setup/util/sources), [net/sfm/setup/util/makefile](../../net/sfm/setup/util/makefile) | `sfmutil` | `DYNLINK` |
| [net/sfm/uam](../../net/sfm/uam) | 12 | [net/sfm/uam/sources](../../net/sfm/uam/sources), [net/sfm/uam/makefile](../../net/sfm/uam/makefile) | `uam` | `LIBRARY` |
| [net/sfm/uam/uam5src](../../net/sfm/uam/uam5src) | 1 | — | — | — |
| [net/sfm/uam/uam5src/rsalibs](../../net/sfm/uam/uam5src/rsalibs) | 4 | — | — | — |
| [net/sfm/uam/uam5src/uamrsrc](../../net/sfm/uam/uam5src/uamrsrc) | 4 | — | — | — |
| [net/sfm/uam/uam5src/uamsrc](../../net/sfm/uam/uam5src/uamsrc) | 30 | — | — | — |

## `net/snmp/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/snmp](../../net/snmp) | 1 | [net/snmp/dirs](../../net/snmp/dirs) | — | — |
| [net/snmp/common](../../net/snmp/common) | 1 | [net/snmp/common/dirs](../../net/snmp/common/dirs) | — | — |
| [net/snmp/common/dll](../../net/snmp/common/dll) | 20 | [net/snmp/common/dll/sources](../../net/snmp/common/dll/sources), [net/snmp/common/dll/makefile](../../net/snmp/common/dll/makefile) | `snmpapi` | `DYNLINK` |
| [net/snmp/common/lib](../../net/snmp/common/lib) | 3 | [net/snmp/common/lib/sources](../../net/snmp/common/lib/sources), [net/snmp/common/lib/makefile](../../net/snmp/common/lib/makefile) | `snmp` | `LIBRARY` |
| [net/snmp/compiler](../../net/snmp/compiler) | 1 | [net/snmp/compiler/dirs](../../net/snmp/compiler/dirs) | — | — |
| [net/snmp/compiler/mibccv2](../../net/snmp/compiler/mibccv2) | 14 | [net/snmp/compiler/mibccv2/sources](../../net/snmp/compiler/mibccv2/sources), [net/snmp/compiler/mibccv2/makefile](../../net/snmp/compiler/mibccv2/makefile) | `mibcc` | `PROGRAM` |
| [net/snmp/docs](../../net/snmp/docs) | 1 | — | — | — |
| [net/snmp/manager](../../net/snmp/manager) | 1 | [net/snmp/manager/dirs](../../net/snmp/manager/dirs) | — | — |
| [net/snmp/manager/mgmtapi](../../net/snmp/manager/mgmtapi) | 1 | [net/snmp/manager/mgmtapi/dirs](../../net/snmp/manager/mgmtapi/dirs) | — | — |
| [net/snmp/manager/mgmtapi/dll](../../net/snmp/manager/mgmtapi/dll) | 9 | [net/snmp/manager/mgmtapi/dll/sources](../../net/snmp/manager/mgmtapi/dll/sources), [net/snmp/manager/mgmtapi/dll/makefile](../../net/snmp/manager/mgmtapi/dll/makefile) | `mgmtapi` | `DYNLINK` |
| [net/snmp/manager/mgmtapi/samples](../../net/snmp/manager/mgmtapi/samples) | 1 | [net/snmp/manager/mgmtapi/samples/dirs](../../net/snmp/manager/mgmtapi/samples/dirs) | — | — |
| [net/snmp/manager/mgmtapi/samples/snmputil](../../net/snmp/manager/mgmtapi/samples/snmputil) | 5 | [net/snmp/manager/mgmtapi/samples/snmputil/sources](../../net/snmp/manager/mgmtapi/samples/snmputil/sources), [net/snmp/manager/mgmtapi/samples/snmputil/makefile](../../net/snmp/manager/mgmtapi/samples/snmputil/makefile) | `snmputil` | `PROGRAM` |
| [net/snmp/manager/winsnmp](../../net/snmp/manager/winsnmp) | 1 | [net/snmp/manager/winsnmp/dirs](../../net/snmp/manager/winsnmp/dirs) | — | — |
| [net/snmp/manager/winsnmp/dll](../../net/snmp/manager/winsnmp/dll) | 15 | [net/snmp/manager/winsnmp/dll/sources](../../net/snmp/manager/winsnmp/dll/sources), [net/snmp/manager/winsnmp/dll/makefile](../../net/snmp/manager/winsnmp/dll/makefile) | `wsnmp32` | `DYNLINK` |
| [net/snmp/manager/winsnmp/docs](../../net/snmp/manager/winsnmp/docs) | 3 | — | — | — |
| [net/snmp/manager/winsnmp/exe](../../net/snmp/manager/winsnmp/exe) | 4 | [net/snmp/manager/winsnmp/exe/sources](../../net/snmp/manager/winsnmp/exe/sources), [net/snmp/manager/winsnmp/exe/makefile](../../net/snmp/manager/winsnmp/exe/makefile) | `snmptrap` | `PROGRAM` |
| [net/snmp/manager/winsnmp/inc](../../net/snmp/manager/winsnmp/inc) | 3 | — | — | — |
| [net/snmp/mibs](../../net/snmp/mibs) | 32 | [net/snmp/mibs/sources](../../net/snmp/mibs/sources), [net/snmp/mibs/makefile](../../net/snmp/mibs/makefile) | `mibs` | `NOTARGET` |
| [net/snmp/newagent](../../net/snmp/newagent) | 1 | [net/snmp/newagent/dirs](../../net/snmp/newagent/dirs) | — | — |
| [net/snmp/newagent/exe](../../net/snmp/newagent/exe) | 25 | [net/snmp/newagent/exe/sources](../../net/snmp/newagent/exe/sources), [net/snmp/newagent/exe/makefile](../../net/snmp/newagent/exe/makefile) | `snmp` | `PROGRAM` |
| [net/snmp/newagent/inc](../../net/snmp/newagent/inc) | 19 | — | — | — |
| [net/snmp/sld](../../net/snmp/sld) | 8 | [net/snmp/sld/sources](../../net/snmp/sld/sources), [net/snmp/sld/makefile](../../net/snmp/sld/makefile) | — | `NOTARGET` |
| [net/snmp/subagent](../../net/snmp/subagent) | 1 | [net/snmp/subagent/dirs](../../net/snmp/subagent/dirs) | — | — |
| [net/snmp/subagent/hostmib](../../net/snmp/subagent/hostmib) | 39 | [net/snmp/subagent/hostmib/sources](../../net/snmp/subagent/hostmib/sources), [net/snmp/subagent/hostmib/makefile](../../net/snmp/subagent/hostmib/makefile) | `hostmib` | `DYNLINK` |
| [net/snmp/subagent/lmmib2](../../net/snmp/subagent/lmmib2) | 44 | [net/snmp/subagent/lmmib2/sources](../../net/snmp/subagent/lmmib2/sources), [net/snmp/subagent/lmmib2/makefile](../../net/snmp/subagent/lmmib2/makefile) | `lmmib2` | `DYNLINK` |
| [net/snmp/subagent/snmpevnt](../../net/snmp/subagent/snmpevnt) | 1 | [net/snmp/subagent/snmpevnt/dirs](../../net/snmp/subagent/snmpevnt/dirs) | — | — |
| [net/snmp/subagent/snmpevnt/evntagnt](../../net/snmp/subagent/snmpevnt/evntagnt) | 15 | [net/snmp/subagent/snmpevnt/evntagnt/sources](../../net/snmp/subagent/snmpevnt/evntagnt/sources), [net/snmp/subagent/snmpevnt/evntagnt/makefile](../../net/snmp/subagent/snmpevnt/evntagnt/makefile) | `evntagnt` | `DYNLINK` |
| [net/snmp/subagent/snmpevnt/evntcmd](../../net/snmp/subagent/snmpevnt/evntcmd) | 17 | [net/snmp/subagent/snmpevnt/evntcmd/sources](../../net/snmp/subagent/snmpevnt/evntcmd/sources), [net/snmp/subagent/snmpevnt/evntcmd/makefile](../../net/snmp/subagent/snmpevnt/evntcmd/makefile) | `evntcmd` | `PROGRAM` |
| [net/snmp/subagent/snmpevnt/evntwin](../../net/snmp/subagent/snmpevnt/evntwin) | 43 | [net/snmp/subagent/snmpevnt/evntwin/sources](../../net/snmp/subagent/snmpevnt/evntwin/sources), [net/snmp/subagent/snmpevnt/evntwin/makefile](../../net/snmp/subagent/snmpevnt/evntwin/makefile) | `evntwin` | `PROGRAM` |
| [net/snmp/subagent/snmpevnt/evntwin/res](../../net/snmp/subagent/snmpevnt/evntwin/res) | 6 | — | — | — |
| [net/snmp/subagent/snmpmib](../../net/snmp/subagent/snmpmib) | 9 | [net/snmp/subagent/snmpmib/sources](../../net/snmp/subagent/snmpmib/sources), [net/snmp/subagent/snmpmib/makefile](../../net/snmp/subagent/snmpmib/makefile) | `snmpmib` | `DYNLINK` |

## `net/sockets/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/sockets](../../net/sockets) | 1 | [net/sockets/dirs](../../net/sockets/dirs) | — | — |
| [net/sockets/compdef](../../net/sockets/compdef) | 7 | [net/sockets/compdef/sources](../../net/sockets/compdef/sources), [net/sockets/compdef/makefile](../../net/sockets/compdef/makefile) | — | `NOTARGET` |
| [net/sockets/inetdb](../../net/sockets/inetdb) | 12 | [net/sockets/inetdb/sources](../../net/sockets/inetdb/sources), [net/sockets/inetdb/makefile](../../net/sockets/inetdb/makefile) | — | `NOTARGET` |
| [net/sockets/samples](../../net/sockets/samples) | 0 | — | — | — |
| [net/sockets/samples/wshsmple](../../net/sockets/samples/wshsmple) | 8 | [net/sockets/samples/wshsmple/sources](../../net/sockets/samples/wshsmple/sources), [net/sockets/samples/wshsmple/makefile](../../net/sockets/samples/wshsmple/makefile) | `wshsmple` | `DYNLINK` |
| [net/sockets/sockreg](../../net/sockets/sockreg) | 4 | [net/sockets/sockreg/sources](../../net/sockets/sockreg/sources), [net/sockets/sockreg/makefile](../../net/sockets/sockreg/makefile) | `sockreg` | `LIBRARY` |
| [net/sockets/winsock2](../../net/sockets/winsock2) | 1 | [net/sockets/winsock2/dirs](../../net/sockets/winsock2/dirs) | — | — |
| [net/sockets/winsock2/inc](../../net/sockets/winsock2/inc) | 4 | — | — | — |
| [net/sockets/winsock2/util](../../net/sockets/winsock2/util) | 1 | [net/sockets/winsock2/util/dirs](../../net/sockets/winsock2/util/dirs) | — | — |
| [net/sockets/winsock2/util/sockeye](../../net/sockets/winsock2/util/sockeye) | 9 | [net/sockets/winsock2/util/sockeye/sources](../../net/sockets/winsock2/util/sockeye/sources), [net/sockets/winsock2/util/sockeye/makefile](../../net/sockets/winsock2/util/sockeye/makefile) | `sockeye` | `PROGRAM` |
| [net/sockets/winsock2/util/sporder](../../net/sockets/winsock2/util/sporder) | 1 | [net/sockets/winsock2/util/sporder/dirs](../../net/sockets/winsock2/util/sporder/dirs) | — | — |
| [net/sockets/winsock2/util/sporder/dll](../../net/sockets/winsock2/util/sporder/dll) | 5 | [net/sockets/winsock2/util/sporder/dll/sources](../../net/sockets/winsock2/util/sporder/dll/sources), [net/sockets/winsock2/util/sporder/dll/makefile](../../net/sockets/winsock2/util/sporder/dll/makefile) | `sporder` | `DYNLINK` |
| [net/sockets/winsock2/util/sporder/exe](../../net/sockets/winsock2/util/sporder/exe) | 9 | [net/sockets/winsock2/util/sporder/exe/sources](../../net/sockets/winsock2/util/sporder/exe/sources), [net/sockets/winsock2/util/sporder/exe/makefile](../../net/sockets/winsock2/util/sporder/exe/makefile) | `sporder` | `PROGRAM` |
| [net/sockets/winsock2/util/ws2inst](../../net/sockets/winsock2/util/ws2inst) | 7 | [net/sockets/winsock2/util/ws2inst/sources](../../net/sockets/winsock2/util/ws2inst/sources), [net/sockets/winsock2/util/ws2inst/makefile](../../net/sockets/winsock2/util/ws2inst/makefile) | `ws2inst` | `PROGRAM` |
| [net/sockets/winsock2/ws2_32](../../net/sockets/winsock2/ws2_32) | 1 | [net/sockets/winsock2/ws2_32/dirs](../../net/sockets/winsock2/ws2_32/dirs) | — | — |
| [net/sockets/winsock2/ws2_32/common](../../net/sockets/winsock2/ws2_32/common) | 11 | [net/sockets/winsock2/ws2_32/common/sources](../../net/sockets/winsock2/ws2_32/common/sources), [net/sockets/winsock2/ws2_32/common/makefile](../../net/sockets/winsock2/ws2_32/common/makefile) | `common` | `LIBRARY` |
| [net/sockets/winsock2/ws2_32/inc](../../net/sockets/winsock2/ws2_32/inc) | 26 | — | — | — |
| [net/sockets/winsock2/ws2_32/src](../../net/sockets/winsock2/ws2_32/src) | 47 | [net/sockets/winsock2/ws2_32/src/sources](../../net/sockets/winsock2/ws2_32/src/sources), [net/sockets/winsock2/ws2_32/src/makefile](../../net/sockets/winsock2/ws2_32/src/makefile) | `ws2_32` | `DYNLINK` |
| [net/sockets/winsock2/ws2help](../../net/sockets/winsock2/ws2help) | 1 | [net/sockets/winsock2/ws2help/dirs](../../net/sockets/winsock2/ws2help/dirs) | — | — |
| [net/sockets/winsock2/ws2help/inc](../../net/sockets/winsock2/ws2help/inc) | 1 | — | — | — |
| [net/sockets/winsock2/ws2help/ws2help](../../net/sockets/winsock2/ws2help/ws2help) | 7 | [net/sockets/winsock2/ws2help/ws2help/dirs](../../net/sockets/winsock2/ws2help/ws2help/dirs) | — | — |
| [net/sockets/winsock2/ws2help/ws2help/nt](../../net/sockets/winsock2/ws2help/ws2help/nt) | 10 | [net/sockets/winsock2/ws2help/ws2help/nt/sources](../../net/sockets/winsock2/ws2help/ws2help/nt/sources), [net/sockets/winsock2/ws2help/ws2help/nt/makefile](../../net/sockets/winsock2/ws2help/ws2help/nt/makefile) | — | — |
| [net/sockets/winsock2/ws2help/ws2ifsl](../../net/sockets/winsock2/ws2help/ws2ifsl) | 20 | [net/sockets/winsock2/ws2help/ws2ifsl/sources](../../net/sockets/winsock2/ws2help/ws2ifsl/sources), [net/sockets/winsock2/ws2help/ws2ifsl/makefile](../../net/sockets/winsock2/ws2help/ws2ifsl/makefile) | `ws2ifsl` | `DRIVER` |
| [net/sockets/winsock2/wsock32](../../net/sockets/winsock2/wsock32) | 8 | [net/sockets/winsock2/wsock32/sources](../../net/sockets/winsock2/wsock32/sources), [net/sockets/winsock2/wsock32/makefile](../../net/sockets/winsock2/wsock32/makefile) | `wsock32` | `DYNLINK` |
| [net/sockets/winsock2/wsp](../../net/sockets/winsock2/wsp) | 2 | [net/sockets/winsock2/wsp/dirs](../../net/sockets/winsock2/wsp/dirs) | — | — |
| [net/sockets/winsock2/wsp/afdsys](../../net/sockets/winsock2/wsp/afdsys) | 34 | [net/sockets/winsock2/wsp/afdsys/dirs](../../net/sockets/winsock2/wsp/afdsys/dirs) | — | — |
| [net/sockets/winsock2/wsp/afdsys/kdext](../../net/sockets/winsock2/wsp/afdsys/kdext) | 23 | [net/sockets/winsock2/wsp/afdsys/kdext/sources](../../net/sockets/winsock2/wsp/afdsys/kdext/sources), [net/sockets/winsock2/wsp/afdsys/kdext/makefile](../../net/sockets/winsock2/wsp/afdsys/kdext/makefile) | `afdkd` | `DYNLINK` |
| [net/sockets/winsock2/wsp/afdsys/mp](../../net/sockets/winsock2/wsp/afdsys/mp) | 3 | [net/sockets/winsock2/wsp/afdsys/mp/sources](../../net/sockets/winsock2/wsp/afdsys/mp/sources), [net/sockets/winsock2/wsp/afdsys/mp/makefile](../../net/sockets/winsock2/wsp/afdsys/mp/makefile) | — | — |

## `net/streams/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/streams](../../net/streams) | 1 | [net/streams/dirs](../../net/streams/dirs) | — | — |
| [net/streams/inc](../../net/streams/inc) | 1 | — | — | — |
| [net/streams/sys](../../net/streams/sys) | 7 | [net/streams/sys/sources](../../net/streams/sys/sources) | `streams` | `EXPORT_DRIVER` |
| [net/streams/winstrm](../../net/streams/winstrm) | 16 | [net/streams/winstrm/sources](../../net/streams/winstrm/sources), [net/streams/winstrm/makefile](../../net/streams/winstrm/makefile) | `winstrm` | `DYNLINK` |

## `net/tapi/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/tapi](../../net/tapi) | 1 | [net/tapi/dirs](../../net/tapi/dirs) | — | — |
| [net/tapi/admin](../../net/tapi/admin) | 1 | [net/tapi/admin/dirs](../../net/tapi/admin/dirs) | — | — |
| [net/tapi/admin/dll](../../net/tapi/admin/dll) | 6 | [net/tapi/admin/dll/sources](../../net/tapi/admin/dll/sources), [net/tapi/admin/dll/makefile](../../net/tapi/admin/dll/makefile) | `tsec` | `DYNLINK` |
| [net/tapi/admin/setup](../../net/tapi/admin/setup) | 5 | [net/tapi/admin/setup/sources](../../net/tapi/admin/setup/sources), [net/tapi/admin/setup/makefile](../../net/tapi/admin/setup/makefile) | `tcmsetup` | `PROGRAM` |
| [net/tapi/apps](../../net/tapi/apps) | 1 | [net/tapi/apps/dirs](../../net/tapi/apps/dirs) | — | — |
| [net/tapi/apps/tapitna](../../net/tapi/apps/tapitna) | 13 | [net/tapi/apps/tapitna/sources](../../net/tapi/apps/tapitna/sources), [net/tapi/apps/tapitna/makefile](../../net/tapi/apps/tapitna/makefile) | `tlocmgr` | `PROGRAM` |
| [net/tapi/apps/tapiupr](../../net/tapi/apps/tapiupr) | 9 | [net/tapi/apps/tapiupr/sources](../../net/tapi/apps/tapiupr/sources), [net/tapi/apps/tapiupr/makefile](../../net/tapi/apps/tapiupr/makefile) | `tapiupr` | `PROGRAM` |
| [net/tapi/apps/tb](../../net/tapi/apps/tb) | 13 | [net/tapi/apps/tb/sources](../../net/tapi/apps/tb/sources), [net/tapi/apps/tb/makefile](../../net/tapi/apps/tb/makefile) | `tb20` | `PROGRAM` |
| [net/tapi/apps/tsecimp](../../net/tapi/apps/tsecimp) | 14 | [net/tapi/apps/tsecimp/sources](../../net/tapi/apps/tsecimp/sources), [net/tapi/apps/tsecimp/makefile](../../net/tapi/apps/tsecimp/makefile) | `tsecimp` | `PROGRAM` |
| [net/tapi/apps/watchit](../../net/tapi/apps/watchit) | 15 | [net/tapi/apps/watchit/sources](../../net/tapi/apps/watchit/sources), [net/tapi/apps/watchit/makefile](../../net/tapi/apps/watchit/makefile) | `tapihart` | `PROGRAM` |
| [net/tapi/client](../../net/tapi/client) | 51 | [net/tapi/client/sources](../../net/tapi/client/sources), [net/tapi/client/makefile](../../net/tapi/client/makefile) | `tapi32` | `DYNLINK` |
| [net/tapi/cpl](../../net/tapi/cpl) | 9 | [net/tapi/cpl/sources](../../net/tapi/cpl/sources), [net/tapi/cpl/makefile](../../net/tapi/cpl/makefile) | `telephon` | `DYNLINK` |
| [net/tapi/explib](../../net/tapi/explib) | 4 | [net/tapi/explib/sources](../../net/tapi/explib/sources), [net/tapi/explib/makefile](../../net/tapi/explib/makefile) | `tapi32l` | `LIBRARY` |
| [net/tapi/idl](../../net/tapi/idl) | 6 | [net/tapi/idl/sources](../../net/tapi/idl/sources), [net/tapi/idl/makefile](../../net/tapi/idl/makefile) | — | `NOTARGET` |
| [net/tapi/inc](../../net/tapi/inc) | 21 | — | — | — |
| [net/tapi/litesabr](../../net/tapi/litesabr) | 1 | [net/tapi/litesabr/dirs](../../net/tapi/litesabr/dirs) | — | — |
| [net/tapi/litesabr/filters](../../net/tapi/litesabr/filters) | 4 | [net/tapi/litesabr/filters/dirs](../../net/tapi/litesabr/filters/dirs) | — | — |
| [net/tapi/litesabr/filters/amrtpdmx](../../net/tapi/litesabr/filters/amrtpdmx) | 24 | [net/tapi/litesabr/filters/amrtpdmx/sources](../../net/tapi/litesabr/filters/amrtpdmx/sources), [net/tapi/litesabr/filters/amrtpdmx/makefile](../../net/tapi/litesabr/filters/amrtpdmx/makefile) | `amrtpdmx` | `LIBRARY` |
| [net/tapi/litesabr/filters/amrtpnet](../../net/tapi/litesabr/filters/amrtpnet) | 26 | [net/tapi/litesabr/filters/amrtpnet/sources](../../net/tapi/litesabr/filters/amrtpnet/sources), [net/tapi/litesabr/filters/amrtpnet/makefile](../../net/tapi/litesabr/filters/amrtpnet/makefile) | `amrtpnet` | `LIBRARY` |
| [net/tapi/litesabr/filters/amrtpss](../../net/tapi/litesabr/filters/amrtpss) | 11 | [net/tapi/litesabr/filters/amrtpss/sources](../../net/tapi/litesabr/filters/amrtpss/sources), [net/tapi/litesabr/filters/amrtpss/makefile](../../net/tapi/litesabr/filters/amrtpss/makefile) | `amrtpss` | `LIBRARY` |
| [net/tapi/litesabr/filters/codecs](../../net/tapi/litesabr/filters/codecs) | 1 | [net/tapi/litesabr/filters/codecs/dirs](../../net/tapi/litesabr/filters/codecs/dirs) | — | — |
| [net/tapi/litesabr/filters/codecs/g711](../../net/tapi/litesabr/filters/codecs/g711) | 19 | [net/tapi/litesabr/filters/codecs/g711/sources](../../net/tapi/litesabr/filters/codecs/g711/sources), [net/tapi/litesabr/filters/codecs/g711/makefile](../../net/tapi/litesabr/filters/codecs/g711/makefile) | `g711codc` | `DYNLINK` |
| [net/tapi/litesabr/filters/dxmrtp](../../net/tapi/litesabr/filters/dxmrtp) | 6 | [net/tapi/litesabr/filters/dxmrtp/sources](../../net/tapi/litesabr/filters/dxmrtp/sources), [net/tapi/litesabr/filters/dxmrtp/makefile](../../net/tapi/litesabr/filters/dxmrtp/makefile) | `dxmrtp` | `DYNLINK` |
| [net/tapi/litesabr/filters/inc](../../net/tapi/litesabr/filters/inc) | 10 | — | — | — |
| [net/tapi/litesabr/filters/inc/ph](../../net/tapi/litesabr/filters/inc/ph) | 8 | — | — | — |
| [net/tapi/litesabr/filters/inc/stl](../../net/tapi/litesabr/filters/inc/stl) | 54 | — | — | — |
| [net/tapi/litesabr/filters/intldbg](../../net/tapi/litesabr/filters/intldbg) | 7 | [net/tapi/litesabr/filters/intldbg/sources](../../net/tapi/litesabr/filters/intldbg/sources), [net/tapi/litesabr/filters/intldbg/makefile](../../net/tapi/litesabr/filters/intldbg/makefile) | `intldbg` | `LIBRARY` |
| [net/tapi/litesabr/filters/lib](../../net/tapi/litesabr/filters/lib) | 1 | — | — | — |
| [net/tapi/litesabr/filters/mixer](../../net/tapi/litesabr/filters/mixer) | 16 | [net/tapi/litesabr/filters/mixer/sources](../../net/tapi/litesabr/filters/mixer/sources), [net/tapi/litesabr/filters/mixer/makefile](../../net/tapi/litesabr/filters/mixer/makefile) | `mxfilter` | `LIBRARY` |
| [net/tapi/litesabr/filters/ppm](../../net/tapi/litesabr/filters/ppm) | 79 | [net/tapi/litesabr/filters/ppm/sources](../../net/tapi/litesabr/filters/ppm/sources), [net/tapi/litesabr/filters/ppm/makefile](../../net/tapi/litesabr/filters/ppm/makefile) | `ppm` | `LIBRARY` |
| [net/tapi/litesabr/filters/rph](../../net/tapi/litesabr/filters/rph) | 1 | [net/tapi/litesabr/filters/rph/dirs](../../net/tapi/litesabr/filters/rph/dirs) | — | — |
| [net/tapi/litesabr/filters/rph/common](../../net/tapi/litesabr/filters/rph/common) | 15 | [net/tapi/litesabr/filters/rph/common/sources](../../net/tapi/litesabr/filters/rph/common/sources), [net/tapi/litesabr/filters/rph/common/makefile](../../net/tapi/litesabr/filters/rph/common/makefile) | `rphcom` | `LIBRARY` |
| [net/tapi/litesabr/filters/rph/rphaud](../../net/tapi/litesabr/filters/rph/rphaud) | 9 | [net/tapi/litesabr/filters/rph/rphaud/sources](../../net/tapi/litesabr/filters/rph/rphaud/sources), [net/tapi/litesabr/filters/rph/rphaud/makefile](../../net/tapi/litesabr/filters/rph/rphaud/makefile) | `rphaud` | `LIBRARY` |
| [net/tapi/litesabr/filters/rph/rphgena](../../net/tapi/litesabr/filters/rph/rphgena) | 11 | [net/tapi/litesabr/filters/rph/rphgena/sources](../../net/tapi/litesabr/filters/rph/rphgena/sources), [net/tapi/litesabr/filters/rph/rphgena/makefile](../../net/tapi/litesabr/filters/rph/rphgena/makefile) | `rphgena` | `LIBRARY` |
| [net/tapi/litesabr/filters/rph/rphgenv](../../net/tapi/litesabr/filters/rph/rphgenv) | 11 | [net/tapi/litesabr/filters/rph/rphgenv/sources](../../net/tapi/litesabr/filters/rph/rphgenv/sources), [net/tapi/litesabr/filters/rph/rphgenv/makefile](../../net/tapi/litesabr/filters/rph/rphgenv/makefile) | `rphgenv` | `LIBRARY` |
| [net/tapi/litesabr/filters/rph/rphh26x](../../net/tapi/litesabr/filters/rph/rphh26x) | 11 | [net/tapi/litesabr/filters/rph/rphh26x/sources](../../net/tapi/litesabr/filters/rph/rphh26x/sources), [net/tapi/litesabr/filters/rph/rphh26x/makefile](../../net/tapi/litesabr/filters/rph/rphh26x/makefile) | `rphh26x` | `LIBRARY` |
| [net/tapi/litesabr/filters/rrcm](../../net/tapi/litesabr/filters/rrcm) | 2 | [net/tapi/litesabr/filters/rrcm/dirs](../../net/tapi/litesabr/filters/rrcm/dirs) | — | — |
| [net/tapi/litesabr/filters/rrcm/md5](../../net/tapi/litesabr/filters/rrcm/md5) | 7 | [net/tapi/litesabr/filters/rrcm/md5/sources](../../net/tapi/litesabr/filters/rrcm/md5/sources), [net/tapi/litesabr/filters/rrcm/md5/makefile](../../net/tapi/litesabr/filters/rrcm/md5/makefile) | `md5` | `LIBRARY` |
| [net/tapi/litesabr/filters/rrcm/rtcp](../../net/tapi/litesabr/filters/rrcm/rtcp) | 12 | [net/tapi/litesabr/filters/rrcm/rtcp/sources](../../net/tapi/litesabr/filters/rrcm/rtcp/sources), [net/tapi/litesabr/filters/rrcm/rtcp/makefile](../../net/tapi/litesabr/filters/rrcm/rtcp/makefile) | `rtcp` | `LIBRARY` |
| [net/tapi/litesabr/filters/rrcm/rtp](../../net/tapi/litesabr/filters/rrcm/rtp) | 17 | [net/tapi/litesabr/filters/rrcm/rtp/sources](../../net/tapi/litesabr/filters/rrcm/rtp/sources), [net/tapi/litesabr/filters/rrcm/rtp/makefile](../../net/tapi/litesabr/filters/rrcm/rtp/makefile) | `rtp` | `LIBRARY` |
| [net/tapi/litesabr/filters/setup](../../net/tapi/litesabr/filters/setup) | 5 | [net/tapi/litesabr/filters/setup/sources](../../net/tapi/litesabr/filters/setup/sources), [net/tapi/litesabr/filters/setup/makefile](../../net/tapi/litesabr/filters/setup/makefile) | — | `NOTARGET` |
| [net/tapi/litesabr/filters/sph](../../net/tapi/litesabr/filters/sph) | 1 | [net/tapi/litesabr/filters/sph/dirs](../../net/tapi/litesabr/filters/sph/dirs) | — | — |
| [net/tapi/litesabr/filters/sph/common](../../net/tapi/litesabr/filters/sph/common) | 11 | [net/tapi/litesabr/filters/sph/common/sources](../../net/tapi/litesabr/filters/sph/common/sources), [net/tapi/litesabr/filters/sph/common/makefile](../../net/tapi/litesabr/filters/sph/common/makefile) | `sphcom` | `LIBRARY` |
| [net/tapi/litesabr/filters/sph/sphaud](../../net/tapi/litesabr/filters/sph/sphaud) | 9 | [net/tapi/litesabr/filters/sph/sphaud/sources](../../net/tapi/litesabr/filters/sph/sphaud/sources), [net/tapi/litesabr/filters/sph/sphaud/makefile](../../net/tapi/litesabr/filters/sph/sphaud/makefile) | `sphaud` | `LIBRARY` |
| [net/tapi/litesabr/filters/sph/sphgena](../../net/tapi/litesabr/filters/sph/sphgena) | 11 | [net/tapi/litesabr/filters/sph/sphgena/sources](../../net/tapi/litesabr/filters/sph/sphgena/sources), [net/tapi/litesabr/filters/sph/sphgena/makefile](../../net/tapi/litesabr/filters/sph/sphgena/makefile) | `sphgena` | `LIBRARY` |
| [net/tapi/litesabr/filters/sph/sphgenv](../../net/tapi/litesabr/filters/sph/sphgenv) | 11 | [net/tapi/litesabr/filters/sph/sphgenv/sources](../../net/tapi/litesabr/filters/sph/sphgenv/sources), [net/tapi/litesabr/filters/sph/sphgenv/makefile](../../net/tapi/litesabr/filters/sph/sphgenv/makefile) | `sphgenv` | `LIBRARY` |
| [net/tapi/litesabr/filters/sph/sphh26x](../../net/tapi/litesabr/filters/sph/sphh26x) | 9 | [net/tapi/litesabr/filters/sph/sphh26x/sources](../../net/tapi/litesabr/filters/sph/sphh26x/sources), [net/tapi/litesabr/filters/sph/sphh26x/makefile](../../net/tapi/litesabr/filters/sph/sphh26x/makefile) | `sphh26x` | `LIBRARY` |
| [net/tapi/nte](../../net/tapi/nte) | 47 | [net/tapi/nte/sources](../../net/tapi/nte/sources), [net/tapi/nte/makefile](../../net/tapi/nte/makefile) | — | `NOTARGET` |
| [net/tapi/perfdll](../../net/tapi/perfdll) | 7 | [net/tapi/perfdll/sources](../../net/tapi/perfdll/sources), [net/tapi/perfdll/makefile](../../net/tapi/perfdll/makefile) | `tapiperf` | `DYNLINK` |
| [net/tapi/rca](../../net/tapi/rca) | 17 | [net/tapi/rca/sources](../../net/tapi/rca/sources), [net/tapi/rca/makefile](../../net/tapi/rca/makefile) | `rca` | `DRIVER` |
| [net/tapi/rtc](../../net/tapi/rtc) | 2 | [net/tapi/rtc/dirs](../../net/tapi/rtc/dirs) | — | — |
| [net/tapi/rtc/phoenix](../../net/tapi/rtc/phoenix) | 1 | [net/tapi/rtc/phoenix/dirs](../../net/tapi/rtc/phoenix/dirs) | — | — |
| [net/tapi/rtc/phoenix/src](../../net/tapi/rtc/phoenix/src) | 2 | [net/tapi/rtc/phoenix/src/dirs](../../net/tapi/rtc/phoenix/src/dirs) | — | — |
| [net/tapi/rtc/phoenix/src/axctl](../../net/tapi/rtc/phoenix/src/axctl) | 28 | [net/tapi/rtc/phoenix/src/axctl/sources](../../net/tapi/rtc/phoenix/src/axctl/sources), [net/tapi/rtc/phoenix/src/axctl/makefile](../../net/tapi/rtc/phoenix/src/axctl/makefile) | `RTCCTL` | `DYNLINK` |
| [net/tapi/rtc/phoenix/src/axctl/res](../../net/tapi/rtc/phoenix/src/axctl/res) | 34 | — | — | — |
| [net/tapi/rtc/phoenix/src/core](../../net/tapi/rtc/phoenix/src/core) | 23 | [net/tapi/rtc/phoenix/src/core/sources](../../net/tapi/rtc/phoenix/src/core/sources), [net/tapi/rtc/phoenix/src/core/makefile](../../net/tapi/rtc/phoenix/src/core/makefile) | `RTCCore` | `LIBRARY` |
| [net/tapi/rtc/phoenix/src/core/genkey](../../net/tapi/rtc/phoenix/src/core/genkey) | 6 | [net/tapi/rtc/phoenix/src/core/genkey/sources](../../net/tapi/rtc/phoenix/src/core/genkey/sources), [net/tapi/rtc/phoenix/src/core/genkey/makefile](../../net/tapi/rtc/phoenix/src/core/genkey/makefile) | `genkey` | `PROGRAM` |
| [net/tapi/rtc/phoenix/src/core/stress](../../net/tapi/rtc/phoenix/src/core/stress) | 4 | [net/tapi/rtc/phoenix/src/core/stress/sources](../../net/tapi/rtc/phoenix/src/core/stress/sources), [net/tapi/rtc/phoenix/src/core/stress/makefile](../../net/tapi/rtc/phoenix/src/core/stress/makefile) | `RTCStress` | `PROGRAM` |
| [net/tapi/rtc/phoenix/src/core/test](../../net/tapi/rtc/phoenix/src/core/test) | 4 | [net/tapi/rtc/phoenix/src/core/test/sources](../../net/tapi/rtc/phoenix/src/core/test/sources), [net/tapi/rtc/phoenix/src/core/test/makefile](../../net/tapi/rtc/phoenix/src/core/test/makefile) | `RTCTest` | `PROGRAM` |
| [net/tapi/rtc/phoenix/src/core/test2](../../net/tapi/rtc/phoenix/src/core/test2) | 4 | [net/tapi/rtc/phoenix/src/core/test2/sources](../../net/tapi/rtc/phoenix/src/core/test2/sources), [net/tapi/rtc/phoenix/src/core/test2/makefile](../../net/tapi/rtc/phoenix/src/core/test2/makefile) | `RTCTest` | `PROGRAM` |
| [net/tapi/rtc/phoenix/src/core/test3](../../net/tapi/rtc/phoenix/src/core/test3) | 4 | [net/tapi/rtc/phoenix/src/core/test3/sources](../../net/tapi/rtc/phoenix/src/core/test3/sources), [net/tapi/rtc/phoenix/src/core/test3/makefile](../../net/tapi/rtc/phoenix/src/core/test3/makefile) | `RTCTest` | `PROGRAM` |
| [net/tapi/rtc/phoenix/src/core/test4](../../net/tapi/rtc/phoenix/src/core/test4) | 5 | [net/tapi/rtc/phoenix/src/core/test4/sources](../../net/tapi/rtc/phoenix/src/core/test4/sources), [net/tapi/rtc/phoenix/src/core/test4/makefile](../../net/tapi/rtc/phoenix/src/core/test4/makefile) | `RTCTest` | `PROGRAM` |
| [net/tapi/rtc/phoenix/src/core/test5](../../net/tapi/rtc/phoenix/src/core/test5) | 3 | [net/tapi/rtc/phoenix/src/core/test5/sources](../../net/tapi/rtc/phoenix/src/core/test5/sources), [net/tapi/rtc/phoenix/src/core/test5/makefile](../../net/tapi/rtc/phoenix/src/core/test5/makefile) | `RTCTest` | `PROGRAM` |
| [net/tapi/rtc/phoenix/src/dll](../../net/tapi/rtc/phoenix/src/dll) | 12 | [net/tapi/rtc/phoenix/src/dll/sources](../../net/tapi/rtc/phoenix/src/dll/sources), [net/tapi/rtc/phoenix/src/dll/makefile](../../net/tapi/rtc/phoenix/src/dll/makefile) | `RTCDLL` | `DYNLINK` |
| [net/tapi/rtc/phoenix/src/dll/res](../../net/tapi/rtc/phoenix/src/dll/res) | 3 | — | — | — |
| [net/tapi/rtc/phoenix/src/dll/waves](../../net/tapi/rtc/phoenix/src/dll/waves) | 4 | — | — | — |
| [net/tapi/rtc/phoenix/src/dpnathlp](../../net/tapi/rtc/phoenix/src/dpnathlp) | 3 | [net/tapi/rtc/phoenix/src/dpnathlp/sources](../../net/tapi/rtc/phoenix/src/dpnathlp/sources), [net/tapi/rtc/phoenix/src/dpnathlp/makefile](../../net/tapi/rtc/phoenix/src/dpnathlp/makefile) | `dpnhguid` | `LIBRARY` |
| [net/tapi/rtc/phoenix/src/exe](../../net/tapi/rtc/phoenix/src/exe) | 37 | [net/tapi/rtc/phoenix/src/exe/sources](../../net/tapi/rtc/phoenix/src/exe/sources), [net/tapi/rtc/phoenix/src/exe/makefile](../../net/tapi/rtc/phoenix/src/exe/makefile) | `rtcclnt` | `PROGRAM` |
| [net/tapi/rtc/phoenix/src/exe/res](../../net/tapi/rtc/phoenix/src/exe/res) | 82 | — | — | — |
| [net/tapi/rtc/phoenix/src/idl](../../net/tapi/rtc/phoenix/src/idl) | 16 | [net/tapi/rtc/phoenix/src/idl/sources](../../net/tapi/rtc/phoenix/src/idl/sources), [net/tapi/rtc/phoenix/src/idl/makefile](../../net/tapi/rtc/phoenix/src/idl/makefile) | — | `NOTARGET` |
| [net/tapi/rtc/phoenix/src/inc](../../net/tapi/rtc/phoenix/src/inc) | 15 | — | — | — |
| [net/tapi/rtc/phoenix/src/media](../../net/tapi/rtc/phoenix/src/media) | 66 | [net/tapi/rtc/phoenix/src/media/sources](../../net/tapi/rtc/phoenix/src/media/sources), [net/tapi/rtc/phoenix/src/media/makefile](../../net/tapi/rtc/phoenix/src/media/makefile) | `rtcmedia` | `DYNLINK` |
| [net/tapi/rtc/phoenix/src/media/test](../../net/tapi/rtc/phoenix/src/media/test) | 7 | [net/tapi/rtc/phoenix/src/media/test/sources](../../net/tapi/rtc/phoenix/src/media/test/sources), [net/tapi/rtc/phoenix/src/media/test/makefile](../../net/tapi/rtc/phoenix/src/media/test/makefile) | `join` | `PROGRAM` |
| [net/tapi/rtc/phoenix/src/media/testmix](../../net/tapi/rtc/phoenix/src/media/testmix) | 4 | [net/tapi/rtc/phoenix/src/media/testmix/sources](../../net/tapi/rtc/phoenix/src/media/testmix/sources), [net/tapi/rtc/phoenix/src/media/testmix/makefile](../../net/tapi/rtc/phoenix/src/media/testmix/makefile) | `walkmix` | `PROGRAM` |
| [net/tapi/rtc/phoenix/src/share](../../net/tapi/rtc/phoenix/src/share) | 21 | [net/tapi/rtc/phoenix/src/share/sources](../../net/tapi/rtc/phoenix/src/share/sources), [net/tapi/rtc/phoenix/src/share/makefile](../../net/tapi/rtc/phoenix/src/share/makefile) | `rtcshare` | `PROGRAM` |
| [net/tapi/rtc/phoenix/src/share/res](../../net/tapi/rtc/phoenix/src/share/res) | 5 | — | — | — |
| [net/tapi/rtc/phoenix/src/sip](../../net/tapi/rtc/phoenix/src/sip) | 51 | [net/tapi/rtc/phoenix/src/sip/sources](../../net/tapi/rtc/phoenix/src/sip/sources), [net/tapi/rtc/phoenix/src/sip/makefile](../../net/tapi/rtc/phoenix/src/sip/makefile) | `sipcli` | `LIBRARY` |
| [net/tapi/rtc/phoenix/src/sip/msgtest](../../net/tapi/rtc/phoenix/src/sip/msgtest) | 3 | [net/tapi/rtc/phoenix/src/sip/msgtest/sources](../../net/tapi/rtc/phoenix/src/sip/msgtest/sources), [net/tapi/rtc/phoenix/src/sip/msgtest/makefile](../../net/tapi/rtc/phoenix/src/sip/msgtest/makefile) | `msgtest` | `PROGRAM` |
| [net/tapi/rtc/phoenix/src/sip/siptest](../../net/tapi/rtc/phoenix/src/sip/siptest) | 5 | [net/tapi/rtc/phoenix/src/sip/siptest/sources](../../net/tapi/rtc/phoenix/src/sip/siptest/sources), [net/tapi/rtc/phoenix/src/sip/siptest/makefile](../../net/tapi/rtc/phoenix/src/sip/siptest/makefile) | `siptest` | `PROGRAM` |
| [net/tapi/rtc/phoenix/src/sip/ssltest](../../net/tapi/rtc/phoenix/src/sip/ssltest) | 17 | [net/tapi/rtc/phoenix/src/sip/ssltest/sources](../../net/tapi/rtc/phoenix/src/sip/ssltest/sources), [net/tapi/rtc/phoenix/src/sip/ssltest/makefile](../../net/tapi/rtc/phoenix/src/sip/ssltest/makefile) | `ssltest` | `PROGRAM` |
| [net/tapi/rtc/phoenix/src/twizard](../../net/tapi/rtc/phoenix/src/twizard) | 8 | [net/tapi/rtc/phoenix/src/twizard/sources](../../net/tapi/rtc/phoenix/src/twizard/sources), [net/tapi/rtc/phoenix/src/twizard/makefile](../../net/tapi/rtc/phoenix/src/twizard/makefile) | `RTCTWiz` | `LIBRARY` |
| [net/tapi/rtc/phoenix/src/util](../../net/tapi/rtc/phoenix/src/util) | 14 | [net/tapi/rtc/phoenix/src/util/sources](../../net/tapi/rtc/phoenix/src/util/sources), [net/tapi/rtc/phoenix/src/util/makefile](../../net/tapi/rtc/phoenix/src/util/makefile) | `RTCUtil` | `LIBRARY` |
| [net/tapi/server](../../net/tapi/server) | 24 | [net/tapi/server/sources](../../net/tapi/server/sources), [net/tapi/server/makefile](../../net/tapi/server/makefile) | `tapisrv` | `DYNLINK` |
| [net/tapi/skywalker](../../net/tapi/skywalker) | 1 | [net/tapi/skywalker/dirs](../../net/tapi/skywalker/dirs) | — | — |
| [net/tapi/skywalker/apps](../../net/tapi/skywalker/apps) | 1 | [net/tapi/skywalker/apps/dirs](../../net/tapi/skywalker/apps/dirs) | — | — |
| [net/tapi/skywalker/apps/avdialer](../../net/tapi/skywalker/apps/avdialer) | 1 | [net/tapi/skywalker/apps/avdialer/dirs](../../net/tapi/skywalker/apps/avdialer/dirs) | — | — |
| [net/tapi/skywalker/apps/avdialer/avdialer](../../net/tapi/skywalker/apps/avdialer/avdialer) | 130 | [net/tapi/skywalker/apps/avdialer/avdialer/sources](../../net/tapi/skywalker/apps/avdialer/avdialer/sources), [net/tapi/skywalker/apps/avdialer/avdialer/makefile](../../net/tapi/skywalker/apps/avdialer/avdialer/makefile) | `dialer` | `PROGRAM` |
| [net/tapi/skywalker/apps/avdialer/avdialer/res](../../net/tapi/skywalker/apps/avdialer/avdialer/res) | 49 | — | — | — |
| [net/tapi/skywalker/apps/avdialer/avlib](../../net/tapi/skywalker/apps/avdialer/avlib) | 67 | [net/tapi/skywalker/apps/avdialer/avlib/sources](../../net/tapi/skywalker/apps/avdialer/avlib/sources), [net/tapi/skywalker/apps/avdialer/avlib/makefile](../../net/tapi/skywalker/apps/avdialer/avlib/makefile) | `avlib` | `LIBRARY` |
| [net/tapi/skywalker/apps/avdialer/avmeter](../../net/tapi/skywalker/apps/avdialer/avmeter) | 8 | [net/tapi/skywalker/apps/avdialer/avmeter/sources](../../net/tapi/skywalker/apps/avdialer/avmeter/sources), [net/tapi/skywalker/apps/avdialer/avmeter/makefile](../../net/tapi/skywalker/apps/avdialer/avmeter/makefile) | `avmeter` | `DYNLINK` |
| [net/tapi/skywalker/apps/avdialer/avtapi](../../net/tapi/skywalker/apps/avdialer/avtapi) | 108 | [net/tapi/skywalker/apps/avdialer/avtapi/sources](../../net/tapi/skywalker/apps/avdialer/avtapi/sources), [net/tapi/skywalker/apps/avdialer/avtapi/makefile](../../net/tapi/skywalker/apps/avdialer/avtapi/makefile) | `avtapi` | `DYNLINK` |
| [net/tapi/skywalker/apps/avdialer/avtapi/res](../../net/tapi/skywalker/apps/avdialer/avtapi/res) | 20 | — | — | — |
| [net/tapi/skywalker/apps/avdialer/avwav](../../net/tapi/skywalker/apps/avdialer/avwav) | 41 | [net/tapi/skywalker/apps/avdialer/avwav/sources](../../net/tapi/skywalker/apps/avdialer/avwav/sources), [net/tapi/skywalker/apps/avdialer/avwav/makefile](../../net/tapi/skywalker/apps/avdialer/avwav/makefile) | `avwav` | `DYNLINK` |
| [net/tapi/skywalker/apps/avdialer/confprop](../../net/tapi/skywalker/apps/avdialer/confprop) | 17 | [net/tapi/skywalker/apps/avdialer/confprop/sources](../../net/tapi/skywalker/apps/avdialer/confprop/sources), [net/tapi/skywalker/apps/avdialer/confprop/makefile](../../net/tapi/skywalker/apps/avdialer/confprop/makefile) | `confprop` | `LIBRARY` |
| [net/tapi/skywalker/apps/avdialer/synchros](../../net/tapi/skywalker/apps/avdialer/synchros) | 4 | [net/tapi/skywalker/apps/avdialer/synchros/sources](../../net/tapi/skywalker/apps/avdialer/synchros/sources), [net/tapi/skywalker/apps/avdialer/synchros/makefile](../../net/tapi/skywalker/apps/avdialer/synchros/makefile) | `synchros` | `LIBRARY` |
| [net/tapi/skywalker/apps/avdialer/transbmp](../../net/tapi/skywalker/apps/avdialer/transbmp) | 4 | [net/tapi/skywalker/apps/avdialer/transbmp/sources](../../net/tapi/skywalker/apps/avdialer/transbmp/sources), [net/tapi/skywalker/apps/avdialer/transbmp/makefile](../../net/tapi/skywalker/apps/avdialer/transbmp/makefile) | `transbmp` | `LIBRARY` |
| [net/tapi/skywalker/apps/samples](../../net/tapi/skywalker/apps/samples) | 1 | [net/tapi/skywalker/apps/samples/dirs](../../net/tapi/skywalker/apps/samples/dirs) | — | — |
| [net/tapi/skywalker/apps/samples/ansmach](../../net/tapi/skywalker/apps/samples/ansmach) | 12 | [net/tapi/skywalker/apps/samples/ansmach/sources](../../net/tapi/skywalker/apps/samples/ansmach/sources), [net/tapi/skywalker/apps/samples/ansmach/makefile](../../net/tapi/skywalker/apps/samples/ansmach/makefile) | `ansmach` | `PROGRAM` |
| [net/tapi/skywalker/apps/samples/incoming](../../net/tapi/skywalker/apps/samples/incoming) | 9 | [net/tapi/skywalker/apps/samples/incoming/sources](../../net/tapi/skywalker/apps/samples/incoming/sources), [net/tapi/skywalker/apps/samples/incoming/makefile](../../net/tapi/skywalker/apps/samples/incoming/makefile) | `t3in` | `PROGRAM` |
| [net/tapi/skywalker/apps/samples/mstsample](../../net/tapi/skywalker/apps/samples/mstsample) | 1 | [net/tapi/skywalker/apps/samples/mstsample/dirs](../../net/tapi/skywalker/apps/samples/mstsample/dirs) | — | — |
| [net/tapi/skywalker/apps/samples/mstsample/tapirecv](../../net/tapi/skywalker/apps/samples/mstsample/tapirecv) | 12 | [net/tapi/skywalker/apps/samples/mstsample/tapirecv/sources](../../net/tapi/skywalker/apps/samples/mstsample/tapirecv/sources), [net/tapi/skywalker/apps/samples/mstsample/tapirecv/makefile](../../net/tapi/skywalker/apps/samples/mstsample/tapirecv/makefile) | `TAPIRecv` | `PROGRAM` |
| [net/tapi/skywalker/apps/samples/mstsample/tapisend](../../net/tapi/skywalker/apps/samples/mstsample/tapisend) | 8 | [net/tapi/skywalker/apps/samples/mstsample/tapisend/sources](../../net/tapi/skywalker/apps/samples/mstsample/tapisend/sources), [net/tapi/skywalker/apps/samples/mstsample/tapisend/makefile](../../net/tapi/skywalker/apps/samples/mstsample/tapisend/makefile) | `TAPISend` | `PROGRAM` |
| [net/tapi/skywalker/apps/samples/outgoing](../../net/tapi/skywalker/apps/samples/outgoing) | 7 | [net/tapi/skywalker/apps/samples/outgoing/sources](../../net/tapi/skywalker/apps/samples/outgoing/sources), [net/tapi/skywalker/apps/samples/outgoing/makefile](../../net/tapi/skywalker/apps/samples/outgoing/makefile) | `t3out` | `PROGRAM` |
| [net/tapi/skywalker/apps/t3test](../../net/tapi/skywalker/apps/t3test) | 32 | [net/tapi/skywalker/apps/t3test/sources](../../net/tapi/skywalker/apps/t3test/sources), [net/tapi/skywalker/apps/t3test/makefile](../../net/tapi/skywalker/apps/t3test/makefile) | `t3test` | `PROGRAM` |
| [net/tapi/skywalker/apps/t3test/res](../../net/tapi/skywalker/apps/t3test/res) | 2 | — | — | — |
| [net/tapi/skywalker/apps/t3testph](../../net/tapi/skywalker/apps/t3testph) | 32 | [net/tapi/skywalker/apps/t3testph/sources](../../net/tapi/skywalker/apps/t3testph/sources), [net/tapi/skywalker/apps/t3testph/makefile](../../net/tapi/skywalker/apps/t3testph/makefile) | `t3test` | `PROGRAM` |
| [net/tapi/skywalker/apps/t3testph/res](../../net/tapi/skywalker/apps/t3testph/res) | 2 | — | — | — |
| [net/tapi/skywalker/cc](../../net/tapi/skywalker/cc) | 2 | [net/tapi/skywalker/cc/dirs](../../net/tapi/skywalker/cc/dirs) | — | — |
| [net/tapi/skywalker/cc/callcont](../../net/tapi/skywalker/cc/callcont) | 30 | [net/tapi/skywalker/cc/callcont/sources](../../net/tapi/skywalker/cc/callcont/sources), [net/tapi/skywalker/cc/callcont/makefile](../../net/tapi/skywalker/cc/callcont/makefile) | `callcont` | `LIBRARY` |
| [net/tapi/skywalker/cc/h245](../../net/tapi/skywalker/cc/h245) | 1 | [net/tapi/skywalker/cc/h245/dirs](../../net/tapi/skywalker/cc/h245/dirs) | — | — |
| [net/tapi/skywalker/cc/h245/inc](../../net/tapi/skywalker/cc/h245/inc) | 28 | — | — | — |
| [net/tapi/skywalker/cc/h245/src](../../net/tapi/skywalker/cc/h245/src) | 32 | [net/tapi/skywalker/cc/h245/src/sources](../../net/tapi/skywalker/cc/h245/src/sources), [net/tapi/skywalker/cc/h245/src/makefile](../../net/tapi/skywalker/cc/h245/src/makefile) | `h245` | `LIBRARY` |
| [net/tapi/skywalker/cc/h245ws](../../net/tapi/skywalker/cc/h245ws) | 13 | [net/tapi/skywalker/cc/h245ws/sources](../../net/tapi/skywalker/cc/h245ws/sources), [net/tapi/skywalker/cc/h245ws/makefile](../../net/tapi/skywalker/cc/h245ws/makefile) | `h245ws` | `LIBRARY` |
| [net/tapi/skywalker/cc/inc](../../net/tapi/skywalker/cc/inc) | 52 | — | — | — |
| [net/tapi/skywalker/cc/q931](../../net/tapi/skywalker/cc/q931) | 16 | [net/tapi/skywalker/cc/q931/sources](../../net/tapi/skywalker/cc/q931/sources), [net/tapi/skywalker/cc/q931/makefile](../../net/tapi/skywalker/cc/q931/makefile) | `q931` | `LIBRARY` |
| [net/tapi/skywalker/confmsp](../../net/tapi/skywalker/confmsp) | 24 | [net/tapi/skywalker/confmsp/sources](../../net/tapi/skywalker/confmsp/sources), [net/tapi/skywalker/confmsp/makefile](../../net/tapi/skywalker/confmsp/makefile) | `confmsp` | `DYNLINK` |
| [net/tapi/skywalker/conftsp](../../net/tapi/skywalker/conftsp) | 10 | [net/tapi/skywalker/conftsp/sources](../../net/tapi/skywalker/conftsp/sources), [net/tapi/skywalker/conftsp/makefile](../../net/tapi/skywalker/conftsp/makefile) | `ipconf` | `DYNLINK` |
| [net/tapi/skywalker/csamsp](../../net/tapi/skywalker/csamsp) | 17 | [net/tapi/skywalker/csamsp/sources](../../net/tapi/skywalker/csamsp/sources), [net/tapi/skywalker/csamsp/makefile](../../net/tapi/skywalker/csamsp/makefile) | `csamsp` | `DYNLINK` |
| [net/tapi/skywalker/filters](../../net/tapi/skywalker/filters) | 2 | [net/tapi/skywalker/filters/dirs](../../net/tapi/skywalker/filters/dirs) | — | — |
| [net/tapi/skywalker/filters/doc](../../net/tapi/skywalker/filters/doc) | 6 | — | — | — |
| [net/tapi/skywalker/filters/dxmrtp](../../net/tapi/skywalker/filters/dxmrtp) | 5 | [net/tapi/skywalker/filters/dxmrtp/sources](../../net/tapi/skywalker/filters/dxmrtp/sources), [net/tapi/skywalker/filters/dxmrtp/makefile](../../net/tapi/skywalker/filters/dxmrtp/makefile) | `$(MINORCOMP)` | `DYNLINK` |
| [net/tapi/skywalker/filters/inc](../../net/tapi/skywalker/filters/inc) | 9 | — | — | — |
| [net/tapi/skywalker/filters/rtp](../../net/tapi/skywalker/filters/rtp) | 5 | [net/tapi/skywalker/filters/rtp/dirs](../../net/tapi/skywalker/filters/rtp/dirs) | — | — |
| [net/tapi/skywalker/filters/rtp/dsrtp](../../net/tapi/skywalker/filters/rtp/dsrtp) | 1 | [net/tapi/skywalker/filters/rtp/dsrtp/dirs](../../net/tapi/skywalker/filters/rtp/dsrtp/dirs) | — | — |
| [net/tapi/skywalker/filters/rtp/dsrtp/inc](../../net/tapi/skywalker/filters/rtp/dsrtp/inc) | 3 | — | — | — |
| [net/tapi/skywalker/filters/rtp/dsrtp/src](../../net/tapi/skywalker/filters/rtp/dsrtp/src) | 9 | [net/tapi/skywalker/filters/rtp/dsrtp/src/sources](../../net/tapi/skywalker/filters/rtp/dsrtp/src/sources), [net/tapi/skywalker/filters/rtp/dsrtp/src/makefile](../../net/tapi/skywalker/filters/rtp/dsrtp/src/makefile) | `$(MINORCOMP)` | `LIBRARY` |
| [net/tapi/skywalker/filters/rtp/inc](../../net/tapi/skywalker/filters/rtp/inc) | 45 | — | — | — |
| [net/tapi/skywalker/filters/rtp/msrtp](../../net/tapi/skywalker/filters/rtp/msrtp) | 1 | [net/tapi/skywalker/filters/rtp/msrtp/dirs](../../net/tapi/skywalker/filters/rtp/msrtp/dirs) | — | — |
| [net/tapi/skywalker/filters/rtp/msrtp/dsapi](../../net/tapi/skywalker/filters/rtp/msrtp/dsapi) | 3 | [net/tapi/skywalker/filters/rtp/msrtp/dsapi/sources](../../net/tapi/skywalker/filters/rtp/msrtp/dsapi/sources), [net/tapi/skywalker/filters/rtp/msrtp/dsapi/makefile](../../net/tapi/skywalker/filters/rtp/msrtp/dsapi/makefile) | `dsrtpapi` | `LIBRARY` |
| [net/tapi/skywalker/filters/rtp/msrtp/funcs](../../net/tapi/skywalker/filters/rtp/msrtp/funcs) | 16 | [net/tapi/skywalker/filters/rtp/msrtp/funcs/sources](../../net/tapi/skywalker/filters/rtp/msrtp/funcs/sources), [net/tapi/skywalker/filters/rtp/msrtp/funcs/makefile](../../net/tapi/skywalker/filters/rtp/msrtp/funcs/makefile) | `funcs` | `LIBRARY` |
| [net/tapi/skywalker/filters/rtp/msrtp/glob](../../net/tapi/skywalker/filters/rtp/msrtp/glob) | 5 | [net/tapi/skywalker/filters/rtp/msrtp/glob/sources](../../net/tapi/skywalker/filters/rtp/msrtp/glob/sources), [net/tapi/skywalker/filters/rtp/msrtp/glob/makefile](../../net/tapi/skywalker/filters/rtp/msrtp/glob/makefile) | `glob` | `LIBRARY` |
| [net/tapi/skywalker/filters/rtp/msrtp/misc](../../net/tapi/skywalker/filters/rtp/msrtp/misc) | 14 | [net/tapi/skywalker/filters/rtp/msrtp/misc/sources](../../net/tapi/skywalker/filters/rtp/msrtp/misc/sources), [net/tapi/skywalker/filters/rtp/msrtp/misc/makefile](../../net/tapi/skywalker/filters/rtp/msrtp/misc/makefile) | `misc` | `LIBRARY` |
| [net/tapi/skywalker/filters/rtp/msrtp/msrtp](../../net/tapi/skywalker/filters/rtp/msrtp/msrtp) | 6 | [net/tapi/skywalker/filters/rtp/msrtp/msrtp/sources](../../net/tapi/skywalker/filters/rtp/msrtp/msrtp/sources), [net/tapi/skywalker/filters/rtp/msrtp/msrtp/makefile](../../net/tapi/skywalker/filters/rtp/msrtp/msrtp/makefile) | `msrtp` | `DYNLINK` |
| [net/tapi/skywalker/filters/rtp/msrtp/rtcp](../../net/tapi/skywalker/filters/rtp/msrtp/rtcp) | 8 | [net/tapi/skywalker/filters/rtp/msrtp/rtcp/sources](../../net/tapi/skywalker/filters/rtp/msrtp/rtcp/sources), [net/tapi/skywalker/filters/rtp/msrtp/rtcp/makefile](../../net/tapi/skywalker/filters/rtp/msrtp/rtcp/makefile) | `rtcp` | `LIBRARY` |
| [net/tapi/skywalker/filters/rtp/msrtp/rtp](../../net/tapi/skywalker/filters/rtp/msrtp/rtp) | 8 | [net/tapi/skywalker/filters/rtp/msrtp/rtp/sources](../../net/tapi/skywalker/filters/rtp/msrtp/rtp/sources), [net/tapi/skywalker/filters/rtp/msrtp/rtp/makefile](../../net/tapi/skywalker/filters/rtp/msrtp/rtp/makefile) | `rtp` | `LIBRARY` |
| [net/tapi/skywalker/filters/rtp/tools](../../net/tapi/skywalker/filters/rtp/tools) | 2 | [net/tapi/skywalker/filters/rtp/tools/dirs](../../net/tapi/skywalker/filters/rtp/tools/dirs) | — | — |
| [net/tapi/skywalker/filters/rtp/tools/common](../../net/tapi/skywalker/filters/rtp/tools/common) | 3 | [net/tapi/skywalker/filters/rtp/tools/common/sources](../../net/tapi/skywalker/filters/rtp/tools/common/sources), [net/tapi/skywalker/filters/rtp/tools/common/makefile](../../net/tapi/skywalker/filters/rtp/tools/common/makefile) | `$(MINORCOMP)` | `LIBRARY` |
| [net/tapi/skywalker/filters/rtp/tools/inc](../../net/tapi/skywalker/filters/rtp/tools/inc) | 3 | — | — | — |
| [net/tapi/skywalker/filters/rtp/tools/udpecho](../../net/tapi/skywalker/filters/rtp/tools/udpecho) | 3 | [net/tapi/skywalker/filters/rtp/tools/udpecho/sources](../../net/tapi/skywalker/filters/rtp/tools/udpecho/sources), [net/tapi/skywalker/filters/rtp/tools/udpecho/makefile](../../net/tapi/skywalker/filters/rtp/tools/udpecho/makefile) | `$(MINORCOMP)` | `PROGRAM` |
| [net/tapi/skywalker/filters/rtp/tools/udprecv](../../net/tapi/skywalker/filters/rtp/tools/udprecv) | 3 | [net/tapi/skywalker/filters/rtp/tools/udprecv/sources](../../net/tapi/skywalker/filters/rtp/tools/udprecv/sources), [net/tapi/skywalker/filters/rtp/tools/udprecv/makefile](../../net/tapi/skywalker/filters/rtp/tools/udprecv/makefile) | `$(MINORCOMP)` | `PROGRAM` |
| [net/tapi/skywalker/filters/rtp/tools/udpsend](../../net/tapi/skywalker/filters/rtp/tools/udpsend) | 3 | [net/tapi/skywalker/filters/rtp/tools/udpsend/sources](../../net/tapi/skywalker/filters/rtp/tools/udpsend/sources), [net/tapi/skywalker/filters/rtp/tools/udpsend/makefile](../../net/tapi/skywalker/filters/rtp/tools/udpsend/makefile) | `$(MINORCOMP)` | `PROGRAM` |
| [net/tapi/skywalker/filters/utils](../../net/tapi/skywalker/filters/utils) | 4 | [net/tapi/skywalker/filters/utils/sources](../../net/tapi/skywalker/filters/utils/sources), [net/tapi/skywalker/filters/utils/makefile](../../net/tapi/skywalker/filters/utils/makefile) | `tptrace` | `LIBRARY` |
| [net/tapi/skywalker/filters/video](../../net/tapi/skywalker/filters/video) | 3 | [net/tapi/skywalker/filters/video/dirs](../../net/tapi/skywalker/filters/video/dirs) | — | — |
| [net/tapi/skywalker/filters/video/inc](../../net/tapi/skywalker/filters/video/inc) | 1 | — | — | — |
| [net/tapi/skywalker/filters/video/tapivcap](../../net/tapi/skywalker/filters/video/tapivcap) | 79 | [net/tapi/skywalker/filters/video/tapivcap/sources](../../net/tapi/skywalker/filters/video/tapivcap/sources), [net/tapi/skywalker/filters/video/tapivcap/makefile](../../net/tapi/skywalker/filters/video/tapivcap/makefile) | `$(MINORCOMP)` | `LIBRARY` |
| [net/tapi/skywalker/filters/video/tapivcap/i386](../../net/tapi/skywalker/filters/video/tapivcap/i386) | 2 | — | — | — |
| [net/tapi/skywalker/filters/video/tapivcap/vc50](../../net/tapi/skywalker/filters/video/tapivcap/vc50) | 1 | — | — | — |
| [net/tapi/skywalker/filters/video/tapivdec](../../net/tapi/skywalker/filters/video/tapivdec) | 34 | [net/tapi/skywalker/filters/video/tapivdec/sources](../../net/tapi/skywalker/filters/video/tapivdec/sources), [net/tapi/skywalker/filters/video/tapivdec/makefile](../../net/tapi/skywalker/filters/video/tapivdec/makefile) | `$(MINORCOMP)` | `LIBRARY` |
| [net/tapi/skywalker/filters/video/tapivdec/i386](../../net/tapi/skywalker/filters/video/tapivdec/i386) | 2 | — | — | — |
| [net/tapi/skywalker/h323](../../net/tapi/skywalker/h323) | 2 | [net/tapi/skywalker/h323/dirs](../../net/tapi/skywalker/h323/dirs) | — | — |
| [net/tapi/skywalker/h323/asn](../../net/tapi/skywalker/h323/asn) | 11 | [net/tapi/skywalker/h323/asn/sources](../../net/tapi/skywalker/h323/asn/sources), [net/tapi/skywalker/h323/asn/makefile](../../net/tapi/skywalker/h323/asn/makefile) | `h323asn` | `LIBRARY` |
| [net/tapi/skywalker/h323/inc](../../net/tapi/skywalker/h323/inc) | 16 | — | — | — |
| [net/tapi/skywalker/h323/test](../../net/tapi/skywalker/h323/test) | 1 | — | — | — |
| [net/tapi/skywalker/h323/tsp](../../net/tapi/skywalker/h323/tsp) | 35 | [net/tapi/skywalker/h323/tsp/sources](../../net/tapi/skywalker/h323/tsp/sources), [net/tapi/skywalker/h323/tsp/makefile](../../net/tapi/skywalker/h323/tsp/makefile) | `H323` | `DYNLINK` |
| [net/tapi/skywalker/h323msp](../../net/tapi/skywalker/h323msp) | 22 | [net/tapi/skywalker/h323msp/sources](../../net/tapi/skywalker/h323msp/sources), [net/tapi/skywalker/h323msp/makefile](../../net/tapi/skywalker/h323msp/makefile) | `H323msp` | `DYNLINK` |
| [net/tapi/skywalker/h323tsp](../../net/tapi/skywalker/h323tsp) | 34 | [net/tapi/skywalker/h323tsp/sources](../../net/tapi/skywalker/h323tsp/sources), [net/tapi/skywalker/h323tsp/makefile](../../net/tapi/skywalker/h323tsp/makefile) | `h323` | `DYNLINK` |
| [net/tapi/skywalker/hidtsp](../../net/tapi/skywalker/hidtsp) | 17 | [net/tapi/skywalker/hidtsp/sources](../../net/tapi/skywalker/hidtsp/sources), [net/tapi/skywalker/hidtsp/makefile](../../net/tapi/skywalker/hidtsp/makefile) | `hidphone` | `DYNLINK` |
| [net/tapi/skywalker/hidtsp/phonemgr](../../net/tapi/skywalker/hidtsp/phonemgr) | 28 | [net/tapi/skywalker/hidtsp/phonemgr/sources](../../net/tapi/skywalker/hidtsp/phonemgr/sources), [net/tapi/skywalker/hidtsp/phonemgr/makefile](../../net/tapi/skywalker/hidtsp/phonemgr/makefile) | `phonemgr` | `PROGRAM` |
| [net/tapi/skywalker/inc](../../net/tapi/skywalker/inc) | 54 | — | — | — |
| [net/tapi/skywalker/ipconf](../../net/tapi/skywalker/ipconf) | 2 | [net/tapi/skywalker/ipconf/dirs](../../net/tapi/skywalker/ipconf/dirs) | — | — |
| [net/tapi/skywalker/ipconf/bridge](../../net/tapi/skywalker/ipconf/bridge) | 0 | — | — | — |
| [net/tapi/skywalker/ipconf/bridge/bridgetm](../../net/tapi/skywalker/ipconf/bridge/bridgetm) | 22 | [net/tapi/skywalker/ipconf/bridge/bridgetm/sources](../../net/tapi/skywalker/ipconf/bridge/bridgetm/sources), [net/tapi/skywalker/ipconf/bridge/bridgetm/makefile](../../net/tapi/skywalker/ipconf/bridge/bridgetm/makefile) | `bridge` | `DYNLINK` |
| [net/tapi/skywalker/ipconf/bridge/inc](../../net/tapi/skywalker/ipconf/bridge/inc) | 1 | — | — | — |
| [net/tapi/skywalker/ipconf/bridge/test](../../net/tapi/skywalker/ipconf/bridge/test) | 10 | [net/tapi/skywalker/ipconf/bridge/test/sources](../../net/tapi/skywalker/ipconf/bridge/test/sources), [net/tapi/skywalker/ipconf/bridge/test/makefile](../../net/tapi/skywalker/ipconf/bridge/test/makefile) | `work` | `PROGRAM` |
| [net/tapi/skywalker/ipconf/bridge/test2](../../net/tapi/skywalker/ipconf/bridge/test2) | 16 | [net/tapi/skywalker/ipconf/bridge/test2/sources](../../net/tapi/skywalker/ipconf/bridge/test2/sources), [net/tapi/skywalker/ipconf/bridge/test2/makefile](../../net/tapi/skywalker/ipconf/bridge/test2/makefile) | `work` | `PROGRAM` |
| [net/tapi/skywalker/ipconf/inc](../../net/tapi/skywalker/ipconf/inc) | 1 | — | — | — |
| [net/tapi/skywalker/ipconf/msp](../../net/tapi/skywalker/ipconf/msp) | 34 | [net/tapi/skywalker/ipconf/msp/sources](../../net/tapi/skywalker/ipconf/msp/sources), [net/tapi/skywalker/ipconf/msp/makefile](../../net/tapi/skywalker/ipconf/msp/makefile) | `confmsp` | `DYNLINK` |
| [net/tapi/skywalker/ipconf/test](../../net/tapi/skywalker/ipconf/test) | 0 | — | — | — |
| [net/tapi/skywalker/ipconf/test/t3out](../../net/tapi/skywalker/ipconf/test/t3out) | 23 | [net/tapi/skywalker/ipconf/test/t3out/sources](../../net/tapi/skywalker/ipconf/test/t3out/sources), [net/tapi/skywalker/ipconf/test/t3out/makefile](../../net/tapi/skywalker/ipconf/test/t3out/makefile) | `t3out` | `PROGRAM` |
| [net/tapi/skywalker/ipconf/tsp](../../net/tapi/skywalker/ipconf/tsp) | 10 | [net/tapi/skywalker/ipconf/tsp/sources](../../net/tapi/skywalker/ipconf/tsp/sources), [net/tapi/skywalker/ipconf/tsp/makefile](../../net/tapi/skywalker/ipconf/tsp/makefile) | `ipconf` | `DYNLINK` |
| [net/tapi/skywalker/mdhcp](../../net/tapi/skywalker/mdhcp) | 21 | [net/tapi/skywalker/mdhcp/sources](../../net/tapi/skywalker/mdhcp/sources), [net/tapi/skywalker/mdhcp/makefile](../../net/tapi/skywalker/mdhcp/makefile) | `mdhcp` | `DYNLINK` |
| [net/tapi/skywalker/mspbase](../../net/tapi/skywalker/mspbase) | 14 | [net/tapi/skywalker/mspbase/sources](../../net/tapi/skywalker/mspbase/sources), [net/tapi/skywalker/mspbase/makefile](../../net/tapi/skywalker/mspbase/makefile) | `mspbase` | `LIBRARY` |
| [net/tapi/skywalker/parser](../../net/tapi/skywalker/parser) | 30 | [net/tapi/skywalker/parser/sources](../../net/tapi/skywalker/parser/sources), [net/tapi/skywalker/parser/makefile](../../net/tapi/skywalker/parser/makefile) | `sdpparse` | `LIBRARY` |
| [net/tapi/skywalker/rcamsp](../../net/tapi/skywalker/rcamsp) | 17 | [net/tapi/skywalker/rcamsp/sources](../../net/tapi/skywalker/rcamsp/sources), [net/tapi/skywalker/rcamsp/makefile](../../net/tapi/skywalker/rcamsp/makefile) | `rcamsp` | `DYNLINK` |
| [net/tapi/skywalker/rend](../../net/tapi/skywalker/rend) | 40 | [net/tapi/skywalker/rend/sources](../../net/tapi/skywalker/rend/sources), [net/tapi/skywalker/rend/makefile](../../net/tapi/skywalker/rend/makefile) | `rend` | `DYNLINK` |
| [net/tapi/skywalker/sdpblb](../../net/tapi/skywalker/sdpblb) | 35 | [net/tapi/skywalker/sdpblb/sources](../../net/tapi/skywalker/sdpblb/sources), [net/tapi/skywalker/sdpblb/makefile](../../net/tapi/skywalker/sdpblb/makefile) | `sdpblb` | `DYNLINK` |
| [net/tapi/skywalker/tapi3](../../net/tapi/skywalker/tapi3) | 72 | [net/tapi/skywalker/tapi3/sources](../../net/tapi/skywalker/tapi3/sources), [net/tapi/skywalker/tapi3/makefile](../../net/tapi/skywalker/tapi3/makefile) | `tapi3` | `DYNLINK` |
| [net/tapi/skywalker/tapi3/sounds](../../net/tapi/skywalker/tapi3/sounds) | 22 | — | — | — |
| [net/tapi/skywalker/terminals](../../net/tapi/skywalker/terminals) | 1 | [net/tapi/skywalker/terminals/dirs](../../net/tapi/skywalker/terminals/dirs) | — | — |
| [net/tapi/skywalker/terminals/fplayback](../../net/tapi/skywalker/terminals/fplayback) | 13 | [net/tapi/skywalker/terminals/fplayback/sources](../../net/tapi/skywalker/terminals/fplayback/sources), [net/tapi/skywalker/terminals/fplayback/makefile](../../net/tapi/skywalker/terminals/fplayback/makefile) | `FPTerm` | `LIBRARY` |
| [net/tapi/skywalker/terminals/frecord](../../net/tapi/skywalker/terminals/frecord) | 9 | [net/tapi/skywalker/terminals/frecord/sources](../../net/tapi/skywalker/terminals/frecord/sources), [net/tapi/skywalker/terminals/frecord/makefile](../../net/tapi/skywalker/terminals/frecord/makefile) | `FileRecordingTerminal` | `LIBRARY` |
| [net/tapi/skywalker/terminals/multitrack](../../net/tapi/skywalker/terminals/multitrack) | 5 | [net/tapi/skywalker/terminals/multitrack/sources](../../net/tapi/skywalker/terminals/multitrack/sources), [net/tapi/skywalker/terminals/multitrack/makefile](../../net/tapi/skywalker/terminals/multitrack/makefile) | `MultiTrackTerminal` | `LIBRARY` |
| [net/tapi/skywalker/terminals/storage](../../net/tapi/skywalker/terminals/storage) | 17 | [net/tapi/skywalker/terminals/storage/sources](../../net/tapi/skywalker/terminals/storage/sources), [net/tapi/skywalker/terminals/storage/makefile](../../net/tapi/skywalker/terminals/storage/makefile) | `StorageUnits` | `LIBRARY` |
| [net/tapi/skywalker/termmgr](../../net/tapi/skywalker/termmgr) | 41 | [net/tapi/skywalker/termmgr/sources](../../net/tapi/skywalker/termmgr/sources), [net/tapi/skywalker/termmgr/makefile](../../net/tapi/skywalker/termmgr/makefile) | `termmgr` | `DYNLINK` |
| [net/tapi/skywalker/wavemsp](../../net/tapi/skywalker/wavemsp) | 17 | [net/tapi/skywalker/wavemsp/sources](../../net/tapi/skywalker/wavemsp/sources), [net/tapi/skywalker/wavemsp/makefile](../../net/tapi/skywalker/wavemsp/makefile) | `wavemsp` | `DYNLINK` |
| [net/tapi/sp](../../net/tapi/sp) | 2 | [net/tapi/sp/dirs](../../net/tapi/sp/dirs), [net/tapi/sp/makefile](../../net/tapi/sp/makefile) | — | — |
| [net/tapi/sp/atsp32](../../net/tapi/sp/atsp32) | 8 | [net/tapi/sp/atsp32/sources](../../net/tapi/sp/atsp32/sources), [net/tapi/sp/atsp32/makefile](../../net/tapi/sp/atsp32/makefile) | `atsp32` | `DYNLINK` |
| [net/tapi/sp/esp](../../net/tapi/sp/esp) | 1 | [net/tapi/sp/esp/dirs](../../net/tapi/sp/esp/dirs) | — | — |
| [net/tapi/sp/esp/exe](../../net/tapi/sp/esp/exe) | 9 | [net/tapi/sp/esp/exe/sources](../../net/tapi/sp/esp/exe/sources), [net/tapi/sp/esp/exe/makefile](../../net/tapi/sp/esp/exe/makefile) | `espexe` | `PROGRAM` |
| [net/tapi/sp/esp/idl](../../net/tapi/sp/esp/idl) | 5 | [net/tapi/sp/esp/idl/sources](../../net/tapi/sp/esp/idl/sources), [net/tapi/sp/esp/idl/makefile](../../net/tapi/sp/esp/idl/makefile) | — | `NOTARGET` |
| [net/tapi/sp/esp/tsp](../../net/tapi/sp/esp/tsp) | 13 | [net/tapi/sp/esp/tsp/sources](../../net/tapi/sp/esp/tsp/sources), [net/tapi/sp/esp/tsp/makefile](../../net/tapi/sp/esp/tsp/makefile) | `esp32` | `DYNLINK` |
| [net/tapi/sp/esp/ui](../../net/tapi/sp/esp/ui) | 5 | [net/tapi/sp/esp/ui/sources](../../net/tapi/sp/esp/ui/sources), [net/tapi/sp/esp/ui/makefile](../../net/tapi/sp/esp/ui/makefile) | `espui` | `DYNLINK` |
| [net/tapi/sp/kmddsp](../../net/tapi/sp/kmddsp) | 9 | [net/tapi/sp/kmddsp/sources](../../net/tapi/sp/kmddsp/sources), [net/tapi/sp/kmddsp/makefile](../../net/tapi/sp/kmddsp/makefile) | `kmddsp` | `DYNLINK` |
| [net/tapi/sp/ndptsp](../../net/tapi/sp/ndptsp) | 1 | [net/tapi/sp/ndptsp/dirs](../../net/tapi/sp/ndptsp/dirs) | — | — |
| [net/tapi/sp/ndptsp/tsp](../../net/tapi/sp/ndptsp/tsp) | 10 | [net/tapi/sp/ndptsp/tsp/sources](../../net/tapi/sp/ndptsp/tsp/sources), [net/tapi/sp/ndptsp/tsp/makefile](../../net/tapi/sp/ndptsp/tsp/makefile) | `ndptsp` | `DYNLINK` |
| [net/tapi/sp/remotesp](../../net/tapi/sp/remotesp) | 18 | [net/tapi/sp/remotesp/sources](../../net/tapi/sp/remotesp/sources), [net/tapi/sp/remotesp/makefile](../../net/tapi/sp/remotesp/makefile) | `remotesp` | `DYNLINK` |
| [net/tapi/tapihndl](../../net/tapi/tapihndl) | 3 | [net/tapi/tapihndl/sources](../../net/tapi/tapihndl/sources), [net/tapi/tapihndl/makefile](../../net/tapi/tapihndl/makefile) | `tapihndl` | `LIBRARY` |
| [net/tapi/tapiui](../../net/tapi/tapiui) | 19 | [net/tapi/tapiui/sources](../../net/tapi/tapiui/sources), [net/tapi/tapiui/makefile](../../net/tapi/tapiui/makefile) | `tapiui` | `DYNLINK` |
| [net/tapi/thunk](../../net/tapi/thunk) | 12 | [net/tapi/thunk/sources](../../net/tapi/thunk/sources), [net/tapi/thunk/makefile](../../net/tapi/thunk/makefile) | `tapi` | `LIBRARY` |
| [net/tapi/tregupr2](../../net/tapi/tregupr2) | 6 | [net/tapi/tregupr2/sources](../../net/tapi/tregupr2/sources), [net/tapi/tregupr2/makefile](../../net/tapi/tregupr2/makefile) | `tregupr2` | `LIBRARY` |

## `net/tcpip/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/tcpip](../../net/tcpip) | 1 | [net/tcpip/dirs](../../net/tcpip/dirs) | — | — |
| [net/tcpip/apis](../../net/tcpip/apis) | 1 | [net/tcpip/apis/dirs](../../net/tcpip/apis/dirs) | — | — |
| [net/tcpip/apis/icmp](../../net/tcpip/apis/icmp) | 4 | [net/tcpip/apis/icmp/sources](../../net/tcpip/apis/icmp/sources), [net/tcpip/apis/icmp/makefile](../../net/tcpip/apis/icmp/makefile) | `icmp` | `DYNLINK` |
| [net/tcpip/apis/iphlpapi](../../net/tcpip/apis/iphlpapi) | 1 | [net/tcpip/apis/iphlpapi/dirs](../../net/tcpip/apis/iphlpapi/dirs) | — | — |
| [net/tcpip/apis/iphlpapi/dll](../../net/tcpip/apis/iphlpapi/dll) | 46 | [net/tcpip/apis/iphlpapi/dll/sources](../../net/tcpip/apis/iphlpapi/dll/sources), [net/tcpip/apis/iphlpapi/dll/makefile](../../net/tcpip/apis/iphlpapi/dll/makefile) | `iphlpapi` | `DYNLINK` |
| [net/tcpip/apis/iphlpapi/icmptest](../../net/tcpip/apis/iphlpapi/icmptest) | 4 | [net/tcpip/apis/iphlpapi/icmptest/sources](../../net/tcpip/apis/iphlpapi/icmptest/sources), [net/tcpip/apis/iphlpapi/icmptest/makefile](../../net/tcpip/apis/iphlpapi/icmptest/makefile) | `icmptest` | `PROGRAM` |
| [net/tcpip/apis/iphlpapi/lib](../../net/tcpip/apis/iphlpapi/lib) | 15 | [net/tcpip/apis/iphlpapi/lib/sources](../../net/tcpip/apis/iphlpapi/lib/sources), [net/tcpip/apis/iphlpapi/lib/makefile](../../net/tcpip/apis/iphlpapi/lib/makefile) | `ipcfgdll` | `LIBRARY` |
| [net/tcpip/apis/routetab](../../net/tcpip/apis/routetab) | 12 | [net/tcpip/apis/routetab/dirs](../../net/tcpip/apis/routetab/dirs) | — | — |
| [net/tcpip/apis/routetab/9x](../../net/tcpip/apis/routetab/9x) | 2 | [net/tcpip/apis/routetab/9x/sources](../../net/tcpip/apis/routetab/9x/sources), [net/tcpip/apis/routetab/9x/makefile](../../net/tcpip/apis/routetab/9x/makefile) | `routetb1` | `DYNLINK` |
| [net/tcpip/apis/routetab/nt](../../net/tcpip/apis/routetab/nt) | 2 | [net/tcpip/apis/routetab/nt/sources](../../net/tcpip/apis/routetab/nt/sources), [net/tcpip/apis/routetab/nt/makefile](../../net/tcpip/apis/routetab/nt/makefile) | `routetab` | `DYNLINK` |
| [net/tcpip/commands](../../net/tcpip/commands) | 1 | [net/tcpip/commands/dirs](../../net/tcpip/commands/dirs) | — | — |
| [net/tcpip/commands/common](../../net/tcpip/commands/common) | 2 | — | — | — |
| [net/tcpip/commands/common2](../../net/tcpip/commands/common2) | 7 | [net/tcpip/commands/common2/sources](../../net/tcpip/commands/common2/sources), [net/tcpip/commands/common2/makefile](../../net/tcpip/commands/common2/makefile) | `common2` | `LIBRARY` |
| [net/tcpip/commands/ipconfig](../../net/tcpip/commands/ipconfig) | 9 | [net/tcpip/commands/ipconfig/sources](../../net/tcpip/commands/ipconfig/sources), [net/tcpip/commands/ipconfig/makefile](../../net/tcpip/commands/ipconfig/makefile) | `ipconfig` | `PROGRAM` |
| [net/tcpip/commands/netstat](../../net/tcpip/commands/netstat) | 7 | [net/tcpip/commands/netstat/sources](../../net/tcpip/commands/netstat/sources), [net/tcpip/commands/netstat/makefile](../../net/tcpip/commands/netstat/makefile) | `netstat` | `PROGRAM` |
| [net/tcpip/commands/pathping](../../net/tcpip/commands/pathping) | 9 | [net/tcpip/commands/pathping/sources](../../net/tcpip/commands/pathping/sources), [net/tcpip/commands/pathping/makefile](../../net/tcpip/commands/pathping/makefile) | `pathping` | `PROGRAM` |
| [net/tcpip/commands/ping](../../net/tcpip/commands/ping) | 6 | [net/tcpip/commands/ping/sources](../../net/tcpip/commands/ping/sources), [net/tcpip/commands/ping/makefile](../../net/tcpip/commands/ping/makefile) | `ping` | `PROGRAM` |
| [net/tcpip/commands/tracert](../../net/tcpip/commands/tracert) | 6 | [net/tcpip/commands/tracert/sources](../../net/tcpip/commands/tracert/sources), [net/tcpip/commands/tracert/makefile](../../net/tcpip/commands/tracert/makefile) | `tracert` | `PROGRAM` |
| [net/tcpip/driver](../../net/tcpip/driver) | 1 | [net/tcpip/driver/dirs](../../net/tcpip/driver/dirs) | — | — |
| [net/tcpip/driver/common](../../net/tcpip/driver/common) | 5 | [net/tcpip/driver/common/dirs](../../net/tcpip/driver/common/dirs) | — | — |
| [net/tcpip/driver/common/9x](../../net/tcpip/driver/common/9x) | 8 | [net/tcpip/driver/common/9x/sources](../../net/tcpip/driver/common/9x/sources), [net/tcpip/driver/common/9x/makefile](../../net/tcpip/driver/common/9x/makefile) | — | — |
| [net/tcpip/driver/common/nt](../../net/tcpip/driver/common/nt) | 3 | [net/tcpip/driver/common/nt/sources](../../net/tcpip/driver/common/nt/sources), [net/tcpip/driver/common/nt/makefile](../../net/tcpip/driver/common/nt/makefile) | — | — |
| [net/tcpip/driver/inc](../../net/tcpip/driver/inc) | 14 | — | — | — |
| [net/tcpip/driver/ipsec](../../net/tcpip/driver/ipsec) | 1 | [net/tcpip/driver/ipsec/dirs](../../net/tcpip/driver/ipsec/dirs) | — | — |
| [net/tcpip/driver/ipsec/kdext](../../net/tcpip/driver/ipsec/kdext) | 12 | [net/tcpip/driver/ipsec/kdext/sources](../../net/tcpip/driver/ipsec/kdext/sources), [net/tcpip/driver/ipsec/kdext/makefile](../../net/tcpip/driver/ipsec/kdext/makefile) | `ipseckd` | `DYNLINK` |
| [net/tcpip/driver/ipsec/sys](../../net/tcpip/driver/ipsec/sys) | 37 | [net/tcpip/driver/ipsec/sys/sources](../../net/tcpip/driver/ipsec/sys/sources), [net/tcpip/driver/ipsec/sys/makefile](../../net/tcpip/driver/ipsec/sys/makefile) | `ipsec` | `DRIVER` |
| [net/tcpip/driver/ipv4](../../net/tcpip/driver/ipv4) | 50 | [net/tcpip/driver/ipv4/dirs](../../net/tcpip/driver/ipv4/dirs) | — | — |
| [net/tcpip/driver/ipv4/9x](../../net/tcpip/driver/ipv4/9x) | 2 | [net/tcpip/driver/ipv4/9x/sources](../../net/tcpip/driver/ipv4/9x/sources), [net/tcpip/driver/ipv4/9x/makefile](../../net/tcpip/driver/ipv4/9x/makefile) | — | — |
| [net/tcpip/driver/ipv4/nt](../../net/tcpip/driver/ipv4/nt) | 2 | [net/tcpip/driver/ipv4/nt/sources](../../net/tcpip/driver/ipv4/nt/sources), [net/tcpip/driver/ipv4/nt/makefile](../../net/tcpip/driver/ipv4/nt/makefile) | — | — |
| [net/tcpip/driver/kdext](../../net/tcpip/driver/kdext) | 16 | [net/tcpip/driver/kdext/sources](../../net/tcpip/driver/kdext/sources), [net/tcpip/driver/kdext/makefile](../../net/tcpip/driver/kdext/makefile) | `tcpipext` | `DYNLINK` |
| [net/tcpip/driver/kdext2](../../net/tcpip/driver/kdext2) | 1 | [net/tcpip/driver/kdext2/dirs](../../net/tcpip/driver/kdext2/dirs) | — | — |
| [net/tcpip/driver/kdext2/9xkd](../../net/tcpip/driver/kdext2/9xkd) | 8 | [net/tcpip/driver/kdext2/9xkd/sources](../../net/tcpip/driver/kdext2/9xkd/sources), [net/tcpip/driver/kdext2/9xkd/makefile](../../net/tcpip/driver/kdext2/9xkd/makefile) | `w9xtcpkd` | `DRIVER_LIBRARY` |
| [net/tcpip/driver/kdext2/inc](../../net/tcpip/driver/kdext2/inc) | 3 | — | — | — |
| [net/tcpip/driver/kdext2/lib](../../net/tcpip/driver/kdext2/lib) | 5 | [net/tcpip/driver/kdext2/lib/dirs](../../net/tcpip/driver/kdext2/lib/dirs) | — | — |
| [net/tcpip/driver/kdext2/lib/9x](../../net/tcpip/driver/kdext2/lib/9x) | 2 | [net/tcpip/driver/kdext2/lib/9x/sources](../../net/tcpip/driver/kdext2/lib/9x/sources), [net/tcpip/driver/kdext2/lib/9x/makefile](../../net/tcpip/driver/kdext2/lib/9x/makefile) | — | `DRIVER_LIBRARY` |
| [net/tcpip/driver/kdext2/lib/nt](../../net/tcpip/driver/kdext2/lib/nt) | 2 | [net/tcpip/driver/kdext2/lib/nt/sources](../../net/tcpip/driver/kdext2/lib/nt/sources), [net/tcpip/driver/kdext2/lib/nt/makefile](../../net/tcpip/driver/kdext2/lib/nt/makefile) | — | `LIBRARY` |
| [net/tcpip/driver/kdext2/ntkd](../../net/tcpip/driver/kdext2/ntkd) | 11 | [net/tcpip/driver/kdext2/ntkd/sources](../../net/tcpip/driver/kdext2/ntkd/sources), [net/tcpip/driver/kdext2/ntkd/makefile](../../net/tcpip/driver/kdext2/ntkd/makefile) | `tcpipkd` | `DYNLINK` |
| [net/tcpip/driver/kdext3](../../net/tcpip/driver/kdext3) | 4 | [net/tcpip/driver/kdext3/sources](../../net/tcpip/driver/kdext3/sources), [net/tcpip/driver/kdext3/makefile](../../net/tcpip/driver/kdext3/makefile) | `dtext` | `DYNLINK` |
| [net/tcpip/driver/sys](../../net/tcpip/driver/sys) | 3 | [net/tcpip/driver/sys/dirs](../../net/tcpip/driver/sys/dirs) | — | — |
| [net/tcpip/driver/sys/9x](../../net/tcpip/driver/sys/9x) | 4 | [net/tcpip/driver/sys/9x/sources](../../net/tcpip/driver/sys/9x/sources), [net/tcpip/driver/sys/9x/makefile](../../net/tcpip/driver/sys/9x/makefile) | — | — |
| [net/tcpip/driver/sys/9xkd](../../net/tcpip/driver/sys/9xkd) | 2 | [net/tcpip/driver/sys/9xkd/sources](../../net/tcpip/driver/sys/9xkd/sources), [net/tcpip/driver/sys/9xkd/makefile](../../net/tcpip/driver/sys/9xkd/makefile) | — | — |
| [net/tcpip/driver/sys/nt](../../net/tcpip/driver/sys/nt) | 9 | [net/tcpip/driver/sys/nt/sources](../../net/tcpip/driver/sys/nt/sources), [net/tcpip/driver/sys/nt/makefile](../../net/tcpip/driver/sys/nt/makefile) | — | — |
| [net/tcpip/driver/tcp](../../net/tcpip/driver/tcp) | 33 | [net/tcpip/driver/tcp/dirs](../../net/tcpip/driver/tcp/dirs) | — | — |
| [net/tcpip/driver/tcp/9x](../../net/tcpip/driver/tcp/9x) | 3 | [net/tcpip/driver/tcp/9x/sources](../../net/tcpip/driver/tcp/9x/sources), [net/tcpip/driver/tcp/9x/makefile](../../net/tcpip/driver/tcp/9x/makefile) | — | — |
| [net/tcpip/driver/tcp/9x/i386](../../net/tcpip/driver/tcp/9x/i386) | 1 | — | — | — |
| [net/tcpip/driver/tcp/nt](../../net/tcpip/driver/tcp/nt) | 2 | [net/tcpip/driver/tcp/nt/sources](../../net/tcpip/driver/tcp/nt/sources), [net/tcpip/driver/tcp/nt/makefile](../../net/tcpip/driver/tcp/nt/makefile) | — | — |
| [net/tcpip/driver/tcp/nt/alpha](../../net/tcpip/driver/tcp/nt/alpha) | 1 | — | — | — |
| [net/tcpip/driver/tcp/nt/amd64](../../net/tcpip/driver/tcp/nt/amd64) | 1 | — | — | — |
| [net/tcpip/driver/tcp/nt/i386](../../net/tcpip/driver/tcp/nt/i386) | 1 | — | — | — |
| [net/tcpip/driver/tcp/nt/ia64](../../net/tcpip/driver/tcp/nt/ia64) | 1 | — | — | — |
| [net/tcpip/samples](../../net/tcpip/samples) | 1 | [net/tcpip/samples/dirs](../../net/tcpip/samples/dirs) | — | — |
| [net/tcpip/samples/connopt](../../net/tcpip/samples/connopt) | 4 | [net/tcpip/samples/connopt/sources](../../net/tcpip/samples/connopt/sources), [net/tcpip/samples/connopt/makefile](../../net/tcpip/samples/connopt/makefile) | `connopt` | `PROGRAM` |
| [net/tcpip/samples/kmcancel](../../net/tcpip/samples/kmcancel) | 5 | [net/tcpip/samples/kmcancel/sources](../../net/tcpip/samples/kmcancel/sources), [net/tcpip/samples/kmcancel/makefile](../../net/tcpip/samples/kmcancel/makefile) | `kmcancel` | `DRIVER` |
| [net/tcpip/samples/limitbcast](../../net/tcpip/samples/limitbcast) | 4 | [net/tcpip/samples/limitbcast/sources](../../net/tcpip/samples/limitbcast/sources), [net/tcpip/samples/limitbcast/makefile](../../net/tcpip/samples/limitbcast/makefile) | `limitbcast` | `PROGRAM` |
| [net/tcpip/samples/mcastloop](../../net/tcpip/samples/mcastloop) | 4 | [net/tcpip/samples/mcastloop/sources](../../net/tcpip/samples/mcastloop/sources), [net/tcpip/samples/mcastloop/makefile](../../net/tcpip/samples/mcastloop/makefile) | `mcastloop` | `PROGRAM` |
| [net/tcpip/samples/rcvall](../../net/tcpip/samples/rcvall) | 4 | [net/tcpip/samples/rcvall/sources](../../net/tcpip/samples/rcvall/sources), [net/tcpip/samples/rcvall/makefile](../../net/tcpip/samples/rcvall/makefile) | `rcvall` | `PROGRAM` |
| [net/tcpip/samples/rtchange](../../net/tcpip/samples/rtchange) | 4 | [net/tcpip/samples/rtchange/sources](../../net/tcpip/samples/rtchange/sources), [net/tcpip/samples/rtchange/makefile](../../net/tcpip/samples/rtchange/makefile) | `rtchange` | `PROGRAM` |
| [net/tcpip/services](../../net/tcpip/services) | 1 | [net/tcpip/services/dirs](../../net/tcpip/services/dirs) | — | — |
| [net/tcpip/services/exe](../../net/tcpip/services/exe) | 4 | [net/tcpip/services/exe/sources](../../net/tcpip/services/exe/sources), [net/tcpip/services/exe/makefile](../../net/tcpip/services/exe/makefile) | `tcpsvcs` | `PROGRAM` |
| [net/tcpip/services/lpd](../../net/tcpip/services/lpd) | 25 | [net/tcpip/services/lpd/sources](../../net/tcpip/services/lpd/sources), [net/tcpip/services/lpd/makefile](../../net/tcpip/services/lpd/makefile) | `lpdsvc` | `DYNLINK` |
| [net/tcpip/services/rip](../../net/tcpip/services/rip) | 16 | [net/tcpip/services/rip/dirs](../../net/tcpip/services/rip/dirs) | — | — |
| [net/tcpip/services/rip/nt](../../net/tcpip/services/rip/nt) | 3 | [net/tcpip/services/rip/nt/sources](../../net/tcpip/services/rip/nt/sources), [net/tcpip/services/rip/nt/makefile](../../net/tcpip/services/rip/nt/makefile) | `iprip` | `DYNLINK` |
| [net/tcpip/services/simple](../../net/tcpip/services/simple) | 12 | [net/tcpip/services/simple/sources](../../net/tcpip/services/simple/sources), [net/tcpip/services/simple/makefile](../../net/tcpip/services/simple/makefile) | `simptcp` | `DYNLINK` |
| [net/tcpip/services/telnet](../../net/tcpip/services/telnet) | 1 | [net/tcpip/services/telnet/dirs](../../net/tcpip/services/telnet/dirs) | — | — |
| [net/tcpip/services/telnet/admin](../../net/tcpip/services/telnet/admin) | 19 | [net/tcpip/services/telnet/admin/sources](../../net/tcpip/services/telnet/admin/sources), [net/tcpip/services/telnet/admin/makefile](../../net/tcpip/services/telnet/admin/makefile) | `TlntAdmn` | `PROGRAM` |
| [net/tcpip/services/telnet/client](../../net/tcpip/services/telnet/client) | 24 | [net/tcpip/services/telnet/client/dirs](../../net/tcpip/services/telnet/client/dirs) | — | — |
| [net/tcpip/services/telnet/client/resdll](../../net/tcpip/services/telnet/client/resdll) | 3 | [net/tcpip/services/telnet/client/resdll/sources](../../net/tcpip/services/telnet/client/resdll/sources), [net/tcpip/services/telnet/client/resdll/makefile](../../net/tcpip/services/telnet/client/resdll/makefile) | `telnetcr` | `DYNLINK` |
| [net/tcpip/services/telnet/client/usa](../../net/tcpip/services/telnet/client/usa) | 2 | [net/tcpip/services/telnet/client/usa/sources](../../net/tcpip/services/telnet/client/usa/sources), [net/tcpip/services/telnet/client/usa/makefile](../../net/tcpip/services/telnet/client/usa/makefile) | — | — |
| [net/tcpip/services/telnet/common](../../net/tcpip/services/telnet/common) | 1 | [net/tcpip/services/telnet/common/dirs](../../net/tcpip/services/telnet/common/dirs) | — | — |
| [net/tcpip/services/telnet/common/activex](../../net/tcpip/services/telnet/common/activex) | 12 | [net/tcpip/services/telnet/common/activex/sources](../../net/tcpip/services/telnet/common/activex/sources), [net/tcpip/services/telnet/common/activex/makefile](../../net/tcpip/services/telnet/common/activex/makefile) | `sfucom` | `LIBRARY` |
| [net/tcpip/services/telnet/common/inc](../../net/tcpip/services/telnet/common/inc) | 2 | — | — | — |
| [net/tcpip/services/telnet/common/locresman](../../net/tcpip/services/telnet/common/locresman) | 3 | [net/tcpip/services/telnet/common/locresman/dirs](../../net/tcpip/services/telnet/common/locresman/dirs) | — | — |
| [net/tcpip/services/telnet/common/locresman/tgt_dll](../../net/tcpip/services/telnet/common/locresman/tgt_dll) | 4 | [net/tcpip/services/telnet/common/locresman/tgt_dll/sources](../../net/tcpip/services/telnet/common/locresman/tgt_dll/sources), [net/tcpip/services/telnet/common/locresman/tgt_dll/makefile](../../net/tcpip/services/telnet/common/locresman/tgt_dll/makefile) | `SolarLRM` | `DYNLINK` |
| [net/tcpip/services/telnet/common/locresman/tgt_lib](../../net/tcpip/services/telnet/common/locresman/tgt_lib) | 2 | [net/tcpip/services/telnet/common/locresman/tgt_lib/sources](../../net/tcpip/services/telnet/common/locresman/tgt_lib/sources), [net/tcpip/services/telnet/common/locresman/tgt_lib/makefile](../../net/tcpip/services/telnet/common/locresman/tgt_lib/makefile) | `locresman` | `LIBRARY` |
| [net/tcpip/services/telnet/server](../../net/tcpip/services/telnet/server) | 1 | [net/tcpip/services/telnet/server/dirs](../../net/tcpip/services/telnet/server/dirs) | — | — |
| [net/tcpip/services/telnet/server/common](../../net/tcpip/services/telnet/server/common) | 21 | [net/tcpip/services/telnet/server/common/sources](../../net/tcpip/services/telnet/server/common/sources), [net/tcpip/services/telnet/server/common/makefile](../../net/tcpip/services/telnet/server/common/makefile) | `tlntutils` | `LIBRARY` |
| [net/tcpip/services/telnet/server/proxystub](../../net/tcpip/services/telnet/server/proxystub) | 6 | [net/tcpip/services/telnet/server/proxystub/sources](../../net/tcpip/services/telnet/server/proxystub/sources), [net/tcpip/services/telnet/server/proxystub/makefile](../../net/tcpip/services/telnet/server/proxystub/makefile) | `TlntSvrp` | `DYNLINK` |
| [net/tcpip/services/telnet/server/tlntsess](../../net/tcpip/services/telnet/server/tlntsess) | 22 | [net/tcpip/services/telnet/server/tlntsess/sources](../../net/tcpip/services/telnet/server/tlntsess/sources), [net/tcpip/services/telnet/server/tlntsess/makefile](../../net/tcpip/services/telnet/server/tlntsess/makefile) | `tlntSess` | `PROGRAM` |
| [net/tcpip/services/telnet/server/tlntsvr](../../net/tcpip/services/telnet/server/tlntsvr) | 22 | [net/tcpip/services/telnet/server/tlntsvr/sources](../../net/tcpip/services/telnet/server/tlntsvr/sources), [net/tcpip/services/telnet/server/tlntsvr/makefile](../../net/tcpip/services/telnet/server/tlntsvr/makefile) | `TlntSvr` | `PROGRAM` |
| [net/tcpip/services/tftp](../../net/tcpip/services/tftp) | 15 | [net/tcpip/services/tftp/sources](../../net/tcpip/services/tftp/sources), [net/tcpip/services/tftp/makefile](../../net/tcpip/services/tftp/makefile) | `tftpd` | `PROGRAM` |
| [net/tcpip/snmp](../../net/tcpip/snmp) | 17 | [net/tcpip/snmp/sources](../../net/tcpip/snmp/sources), [net/tcpip/snmp/makefile](../../net/tcpip/snmp/makefile) | `inetmib1` | `DYNLINK` |
| [net/tcpip/tools](../../net/tcpip/tools) | 1 | [net/tcpip/tools/dirs](../../net/tcpip/tools/dirs) | — | — |
| [net/tcpip/tools/checkv4](../../net/tcpip/tools/checkv4) | 8 | [net/tcpip/tools/checkv4/sources](../../net/tcpip/tools/checkv4/sources), [net/tcpip/tools/checkv4/makefile](../../net/tcpip/tools/checkv4/makefile) | `checkv4` | `PROGRAM` |
| [net/tcpip/tools/enablerouter](../../net/tcpip/tools/enablerouter) | 4 | [net/tcpip/tools/enablerouter/sources](../../net/tcpip/tools/enablerouter/sources), [net/tcpip/tools/enablerouter/makefile](../../net/tcpip/tools/enablerouter/makefile) | `enablerouter` | `PROGRAM` |
| [net/tcpip/tools/ipfw](../../net/tcpip/tools/ipfw) | 6 | [net/tcpip/tools/ipfw/sources](../../net/tcpip/tools/ipfw/sources), [net/tcpip/tools/ipfw/makefile](../../net/tcpip/tools/ipfw/makefile) | `ipfw` | `DRIVER` |
| [net/tcpip/tools/irdp](../../net/tcpip/tools/irdp) | 4 | [net/tcpip/tools/irdp/sources](../../net/tcpip/tools/irdp/sources), [net/tcpip/tools/irdp/makefile](../../net/tcpip/tools/irdp/makefile) | `irdp` | `PROGRAM` |
| [net/tcpip/tools/pfd](../../net/tcpip/tools/pfd) | 5 | [net/tcpip/tools/pfd/sources](../../net/tcpip/tools/pfd/sources), [net/tcpip/tools/pfd/makefile](../../net/tcpip/tools/pfd/makefile) | `pfd` | `DRIVER` |
| [net/tcpip/tools/sendarp](../../net/tcpip/tools/sendarp) | 4 | [net/tcpip/tools/sendarp/sources](../../net/tcpip/tools/sendarp/sources), [net/tcpip/tools/sendarp/makefile](../../net/tcpip/tools/sendarp/makefile) | `sendarp` | `PROGRAM` |
| [net/tcpip/tools/tcbmon](../../net/tcpip/tools/tcbmon) | 4 | [net/tcpip/tools/tcbmon/sources](../../net/tcpip/tools/tcbmon/sources), [net/tcpip/tools/tcbmon/makefile](../../net/tcpip/tools/tcbmon/makefile) | `tcbmon` | `PROGRAM` |
| [net/tcpip/tools/tcbview](../../net/tcpip/tools/tcbview) | 4 | [net/tcpip/tools/tcbview/sources](../../net/tcpip/tools/tcbview/sources), [net/tcpip/tools/tcbview/makefile](../../net/tcpip/tools/tcbview/makefile) | `tcbview` | `PROGRAM` |
| [net/tcpip/tpipv6](../../net/tcpip/tpipv6) | 1 | [net/tcpip/tpipv6/dirs](../../net/tcpip/tpipv6/dirs) | — | — |
| [net/tcpip/tpipv6/6to4svc](../../net/tcpip/tpipv6/6to4svc) | 23 | [net/tcpip/tpipv6/6to4svc/sources](../../net/tcpip/tpipv6/6to4svc/sources), [net/tcpip/tpipv6/6to4svc/makefile](../../net/tcpip/tpipv6/6to4svc/makefile) | `6to4svc` | `DYNLINK` |
| [net/tcpip/tpipv6/dplayip6](../../net/tcpip/tpipv6/dplayip6) | 32 | [net/tcpip/tpipv6/dplayip6/sources](../../net/tcpip/tpipv6/dplayip6/sources), [net/tcpip/tpipv6/dplayip6/makefile](../../net/tcpip/tpipv6/dplayip6/makefile) | `dplayip6` | `DYNLINK` |
| [net/tcpip/tpipv6/dplsvr6](../../net/tcpip/tpipv6/dplsvr6) | 15 | [net/tcpip/tpipv6/dplsvr6/sources](../../net/tcpip/tpipv6/dplsvr6/sources), [net/tcpip/tpipv6/dplsvr6/makefile](../../net/tcpip/tpipv6/dplsvr6/makefile) | `dplsvr6` | `PROGRAM` |
| [net/tcpip/tpipv6/embedded](../../net/tcpip/tpipv6/embedded) | 7 | — | — | — |
| [net/tcpip/tpipv6/inc](../../net/tcpip/tpipv6/inc) | 3 | — | — | — |
| [net/tcpip/tpipv6/ipsec](../../net/tcpip/tpipv6/ipsec) | 6 | [net/tcpip/tpipv6/ipsec/sources](../../net/tcpip/tpipv6/ipsec/sources), [net/tcpip/tpipv6/ipsec/makefile](../../net/tcpip/tpipv6/ipsec/makefile) | `ipsec6` | `PROGRAM` |
| [net/tcpip/tpipv6/ipv6](../../net/tcpip/tpipv6/ipv6) | 7 | [net/tcpip/tpipv6/ipv6/sources](../../net/tcpip/tpipv6/ipv6/sources), [net/tcpip/tpipv6/ipv6/makefile](../../net/tcpip/tpipv6/ipv6/makefile) | `ipv6` | `PROGRAM` |
| [net/tcpip/tpipv6/ipv6mon](../../net/tcpip/tpipv6/ipv6mon) | 25 | [net/tcpip/tpipv6/ipv6mon/sources](../../net/tcpip/tpipv6/ipv6mon/sources), [net/tcpip/tpipv6/ipv6mon/makefile](../../net/tcpip/tpipv6/ipv6mon/makefile) | `ipv6mon` | `DYNLINK` |
| [net/tcpip/tpipv6/ping6](../../net/tcpip/tpipv6/ping6) | 6 | [net/tcpip/tpipv6/ping6/sources](../../net/tcpip/tpipv6/ping6/sources), [net/tcpip/tpipv6/ping6/makefile](../../net/tcpip/tpipv6/ping6/makefile) | `ping6` | `PROGRAM` |
| [net/tcpip/tpipv6/samples](../../net/tcpip/tpipv6/samples) | 0 | — | — | — |
| [net/tcpip/tpipv6/samples/genproxy](../../net/tcpip/tpipv6/samples/genproxy) | 3 | [net/tcpip/tpipv6/samples/genproxy/sources](../../net/tcpip/tpipv6/samples/genproxy/sources), [net/tcpip/tpipv6/samples/genproxy/makefile](../../net/tcpip/tpipv6/samples/genproxy/makefile) | `genproxy` | `PROGRAM` |
| [net/tcpip/tpipv6/samples/rawsock](../../net/tcpip/tpipv6/samples/rawsock) | 3 | [net/tcpip/tpipv6/samples/rawsock/makefile](../../net/tcpip/tpipv6/samples/rawsock/makefile) | — | — |
| [net/tcpip/tpipv6/samples/simple](../../net/tcpip/tpipv6/samples/simple) | 4 | [net/tcpip/tpipv6/samples/simple/makefile](../../net/tcpip/tpipv6/samples/simple/makefile) | — | — |
| [net/tcpip/tpipv6/samples/testai](../../net/tcpip/tpipv6/samples/testai) | 3 | [net/tcpip/tpipv6/samples/testai/sources](../../net/tcpip/tpipv6/samples/testai/sources), [net/tcpip/tpipv6/samples/testai/makefile](../../net/tcpip/tpipv6/samples/testai/makefile) | `testai` | `PROGRAM` |
| [net/tcpip/tpipv6/tcpip6](../../net/tcpip/tpipv6/tcpip6) | 1 | [net/tcpip/tpipv6/tcpip6/dirs](../../net/tcpip/tpipv6/tcpip6/dirs) | — | — |
| [net/tcpip/tpipv6/tcpip6/algrthms](../../net/tcpip/tpipv6/tcpip6/algrthms) | 9 | [net/tcpip/tpipv6/tcpip6/algrthms/sources](../../net/tcpip/tpipv6/tcpip6/algrthms/sources), [net/tcpip/tpipv6/tcpip6/algrthms/makefile](../../net/tcpip/tpipv6/tcpip6/algrthms/makefile) | `algrthms` | `LIBRARY` |
| [net/tcpip/tpipv6/tcpip6/inc](../../net/tcpip/tpipv6/tcpip6/inc) | 24 | — | — | — |
| [net/tcpip/tpipv6/tcpip6/ip6](../../net/tcpip/tpipv6/tcpip6/ip6) | 28 | [net/tcpip/tpipv6/tcpip6/ip6/sources](../../net/tcpip/tpipv6/tcpip6/ip6/sources), [net/tcpip/tpipv6/tcpip6/ip6/makefile](../../net/tcpip/tpipv6/tcpip6/ip6/makefile) | `ip6` | `LIBRARY` |
| [net/tcpip/tpipv6/tcpip6/sys](../../net/tcpip/tpipv6/tcpip6/sys) | 12 | [net/tcpip/tpipv6/tcpip6/sys/sources](../../net/tcpip/tpipv6/tcpip6/sys/sources), [net/tcpip/tpipv6/tcpip6/sys/makefile](../../net/tcpip/tpipv6/tcpip6/sys/makefile) | `tcpip6` | `EXPORT_DRIVER` |
| [net/tcpip/tpipv6/tcpip6/sys/amd64](../../net/tcpip/tpipv6/tcpip6/sys/amd64) | 1 | — | — | — |
| [net/tcpip/tpipv6/tcpip6/sys/i386](../../net/tcpip/tpipv6/tcpip6/sys/i386) | 3 | [net/tcpip/tpipv6/tcpip6/sys/i386/sources](../../net/tcpip/tpipv6/tcpip6/sys/i386/sources) | — | — |
| [net/tcpip/tpipv6/tcpip6/sys/ia64](../../net/tcpip/tpipv6/tcpip6/sys/ia64) | 1 | — | — | — |
| [net/tcpip/tpipv6/tcpip6/tcp](../../net/tcpip/tpipv6/tcpip6/tcp) | 11 | [net/tcpip/tpipv6/tcpip6/tcp/sources](../../net/tcpip/tpipv6/tcpip6/tcp/sources), [net/tcpip/tpipv6/tcpip6/tcp/makefile](../../net/tcpip/tpipv6/tcpip6/tcp/makefile) | `tcp` | `LIBRARY` |
| [net/tcpip/tpipv6/tcpip6/udp](../../net/tcpip/tpipv6/tcpip6/udp) | 6 | [net/tcpip/tpipv6/tcpip6/udp/sources](../../net/tcpip/tpipv6/tcpip6/udp/sources), [net/tcpip/tpipv6/tcpip6/udp/makefile](../../net/tcpip/tpipv6/tcpip6/udp/makefile) | `udp` | `LIBRARY` |
| [net/tcpip/tpipv6/test](../../net/tcpip/tpipv6/test) | 0 | — | — | — |
| [net/tcpip/tpipv6/test/testai](../../net/tcpip/tpipv6/test/testai) | 1 | [net/tcpip/tpipv6/test/testai/makefile](../../net/tcpip/tpipv6/test/testai/makefile) | — | — |
| [net/tcpip/tpipv6/tracert6](../../net/tcpip/tpipv6/tracert6) | 6 | [net/tcpip/tpipv6/tracert6/sources](../../net/tcpip/tpipv6/tracert6/sources), [net/tcpip/tpipv6/tracert6/makefile](../../net/tcpip/tpipv6/tracert6/makefile) | `tracert6` | `PROGRAM` |
| [net/tcpip/tpipv6/ttcp](../../net/tcpip/tpipv6/ttcp) | 6 | [net/tcpip/tpipv6/ttcp/sources](../../net/tcpip/tpipv6/ttcp/sources), [net/tcpip/tpipv6/ttcp/makefile](../../net/tcpip/tpipv6/ttcp/makefile) | `ttcp` | `PROGRAM` |
| [net/tcpip/tpipv6/wship6](../../net/tcpip/tpipv6/wship6) | 6 | [net/tcpip/tpipv6/wship6/sources](../../net/tcpip/tpipv6/wship6/sources), [net/tcpip/tpipv6/wship6/makefile](../../net/tcpip/tpipv6/wship6/makefile) | `wship6` | `DYNLINK` |
| [net/tcpip/winsock](../../net/tcpip/winsock) | 5 | [net/tcpip/winsock/sources](../../net/tcpip/winsock/sources), [net/tcpip/winsock/makefile](../../net/tcpip/winsock/makefile) | `wshtcpip` | `DYNLINK` |

## `net/tdi/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/tdi](../../net/tdi) | 1 | [net/tdi/dirs](../../net/tdi/dirs) | — | — |
| [net/tdi/sample](../../net/tdi/sample) | 3 | [net/tdi/sample/dirs](../../net/tdi/sample/dirs) | — | — |
| [net/tdi/sample/inc](../../net/tdi/sample/inc) | 4 | — | — | — |
| [net/tdi/sample/lib](../../net/tdi/sample/lib) | 14 | [net/tdi/sample/lib/sources](../../net/tdi/sample/lib/sources), [net/tdi/sample/lib/makefile](../../net/tdi/sample/lib/makefile) | `TDILIB` | `LIBRARY` |
| [net/tdi/sample/sys](../../net/tdi/sample/sys) | 18 | [net/tdi/sample/sys/sources](../../net/tdi/sample/sys/sources), [net/tdi/sample/sys/makefile](../../net/tdi/sample/sys/makefile) | `tdisample` | `DRIVER` |
| [net/tdi/sample/tdisamp](../../net/tdi/sample/tdisamp) | 3 | [net/tdi/sample/tdisamp/sources](../../net/tdi/sample/tdisamp/sources), [net/tdi/sample/tdisamp/makefile](../../net/tdi/sample/tdisamp/makefile) | `tdisamp` | `PROGRAM` |
| [net/tdi/sys](../../net/tdi/sys) | 12 | [net/tdi/sys/sources](../../net/tdi/sys/sources), [net/tdi/sys/makefile](../../net/tdi/sys/makefile) | `tdi` | `EXPORT_DRIVER` |
| [net/tdi/sys/tdikd](../../net/tdi/sys/tdikd) | 5 | [net/tdi/sys/tdikd/sources](../../net/tdi/sys/tdikd/sources), [net/tdi/sys/tdikd/makefile](../../net/tdi/sys/tdikd/makefile) | `tdikd` | `DYNLINK` |

## `net/unimodem/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/unimodem](../../net/unimodem) | 4 | [net/unimodem/dirs](../../net/unimodem/dirs) | — | — |
| [net/unimodem/common](../../net/unimodem/common) | 9 | [net/unimodem/common/sources](../../net/unimodem/common/sources), [net/unimodem/common/makefile](../../net/unimodem/common/makefile) | `rovcomm` | `LIBRARY` |
| [net/unimodem/componentdef](../../net/unimodem/componentdef) | 5 | [net/unimodem/componentdef/sources](../../net/unimodem/componentdef/sources), [net/unimodem/componentdef/makefile](../../net/unimodem/componentdef/makefile) | `None` | `notarget` |
| [net/unimodem/inc](../../net/unimodem/inc) | 7 | — | — | — |
| [net/unimodem/inf](../../net/unimodem/inf) | 3 | [net/unimodem/inf/dirs](../../net/unimodem/inf/dirs) | — | — |
| [net/unimodem/inf/usa](../../net/unimodem/inf/usa) | 1 | [net/unimodem/inf/usa/dirs](../../net/unimodem/inf/usa/dirs) | — | — |
| [net/unimodem/inf/usa/drivers](../../net/unimodem/inf/usa/drivers) | 1 | [net/unimodem/inf/usa/drivers/dirs](../../net/unimodem/inf/usa/drivers/dirs) | — | — |
| [net/unimodem/inf/usa/drivers/3com](../../net/unimodem/inf/usa/drivers/3com) | 5 | [net/unimodem/inf/usa/drivers/3com/sources](../../net/unimodem/inf/usa/drivers/3com/sources), [net/unimodem/inf/usa/drivers/3com/makefile](../../net/unimodem/inf/usa/drivers/3com/makefile) | `inf` | `notarget` |
| [net/unimodem/inf/usa/drivers/3com/i386](../../net/unimodem/inf/usa/drivers/3com/i386) | 8 | — | — | — |
| [net/unimodem/inf/usa/drivers/gsm](../../net/unimodem/inf/usa/drivers/gsm) | 5 | [net/unimodem/inf/usa/drivers/gsm/sources](../../net/unimodem/inf/usa/drivers/gsm/sources), [net/unimodem/inf/usa/drivers/gsm/makefile](../../net/unimodem/inf/usa/drivers/gsm/makefile) | `inf` | `notarget` |
| [net/unimodem/inf/usa/drivers/gsm/i386](../../net/unimodem/inf/usa/drivers/gsm/i386) | 2 | — | — | — |
| [net/unimodem/inf/usa/drivers/ibm](../../net/unimodem/inf/usa/drivers/ibm) | 1 | [net/unimodem/inf/usa/drivers/ibm/dirs](../../net/unimodem/inf/usa/drivers/ibm/dirs) | — | — |
| [net/unimodem/inf/usa/drivers/lucent](../../net/unimodem/inf/usa/drivers/lucent) | 6 | [net/unimodem/inf/usa/drivers/lucent/sources](../../net/unimodem/inf/usa/drivers/lucent/sources), [net/unimodem/inf/usa/drivers/lucent/makefile](../../net/unimodem/inf/usa/drivers/lucent/makefile) | `inf` | `notarget` |
| [net/unimodem/inf/usa/drivers/lucent/i386](../../net/unimodem/inf/usa/drivers/lucent/i386) | 10 | — | — | — |
| [net/unimodem/inf/usa/drivers/ositech](../../net/unimodem/inf/usa/drivers/ositech) | 4 | [net/unimodem/inf/usa/drivers/ositech/sources](../../net/unimodem/inf/usa/drivers/ositech/sources), [net/unimodem/inf/usa/drivers/ositech/makefile](../../net/unimodem/inf/usa/drivers/ositech/makefile) | `inf` | `notarget` |
| [net/unimodem/inf/usa/drivers/ositech/i386](../../net/unimodem/inf/usa/drivers/ositech/i386) | 2 | — | — | — |
| [net/unimodem/inf/usa/inf](../../net/unimodem/inf/usa/inf) | 190 | [net/unimodem/inf/usa/inf/sources](../../net/unimodem/inf/usa/inf/sources), [net/unimodem/inf/usa/inf/makefile](../../net/unimodem/inf/usa/inf/makefile) | `inf` | `NOTARGET` |
| [net/unimodem/inf/usa/inf/samples](../../net/unimodem/inf/usa/inf/samples) | 7 | — | — | — |
| [net/unimodem/lights](../../net/unimodem/lights) | 19 | [net/unimodem/lights/sources](../../net/unimodem/lights/sources), [net/unimodem/lights/makefile](../../net/unimodem/lights/makefile) | `lights` | `PROGRAM` |
| [net/unimodem/resource](../../net/unimodem/resource) | 7 | — | — | — |
| [net/unimodem/sample](../../net/unimodem/sample) | 2 | [net/unimodem/sample/dirs](../../net/unimodem/sample/dirs) | — | — |
| [net/unimodem/sample/inf](../../net/unimodem/sample/inf) | 4 | [net/unimodem/sample/inf/sources](../../net/unimodem/sample/inf/sources), [net/unimodem/sample/inf/makefile](../../net/unimodem/sample/inf/makefile) | `inf` | `notarget` |
| [net/unimodem/sample/sys](../../net/unimodem/sample/sys) | 10 | [net/unimodem/sample/sys/sources](../../net/unimodem/sample/sys/sources), [net/unimodem/sample/sys/makefile](../../net/unimodem/sample/sys/makefile) | `fakemodem` | `DRIVER` |
| [net/unimodem/serialui](../../net/unimodem/serialui) | 18 | [net/unimodem/serialui/sources](../../net/unimodem/serialui/sources), [net/unimodem/serialui/makefile](../../net/unimodem/serialui/makefile) | `serialui` | `DYNLINK` |
| [net/unimodem/src](../../net/unimodem/src) | 1 | [net/unimodem/src/dirs](../../net/unimodem/src/dirs) | — | — |
| [net/unimodem/src/atmini](../../net/unimodem/src/atmini) | 38 | [net/unimodem/src/atmini/sources](../../net/unimodem/src/atmini/sources), [net/unimodem/src/atmini/makefile](../../net/unimodem/src/atmini/makefile) | `unimdmat` | `DYNLINK` |
| [net/unimodem/src/cpl](../../net/unimodem/src/cpl) | 1 | [net/unimodem/src/cpl/sources](../../net/unimodem/src/cpl/sources) | `modem` | `DYNLINK` |
| [net/unimodem/src/debugmem](../../net/unimodem/src/debugmem) | 4 | [net/unimodem/src/debugmem/sources](../../net/unimodem/src/debugmem/sources), [net/unimodem/src/debugmem/makefile](../../net/unimodem/src/debugmem/makefile) | `debugmem` | `LIBRARY` |
| [net/unimodem/src/inc](../../net/unimodem/src/inc) | 9 | — | — | — |
| [net/unimodem/src/mdmdbgex](../../net/unimodem/src/mdmdbgex) | 8 | [net/unimodem/src/mdmdbgex/sources](../../net/unimodem/src/mdmdbgex/sources), [net/unimodem/src/mdmdbgex/makefile](../../net/unimodem/src/mdmdbgex/makefile) | `mdmdbgex` | `DYNLINK` |
| [net/unimodem/src/mdminst](../../net/unimodem/src/mdminst) | 18 | [net/unimodem/src/mdminst/sources](../../net/unimodem/src/mdminst/sources), [net/unimodem/src/mdminst/makefile](../../net/unimodem/src/mdminst/makefile) | `mdminst` | `DYNLINK` |
| [net/unimodem/src/modemui](../../net/unimodem/src/modemui) | 38 | [net/unimodem/src/modemui/sources](../../net/unimodem/src/modemui/sources), [net/unimodem/src/modemui/makefile](../../net/unimodem/src/modemui/makefile) | `modemui` | `DYNLINK` |
| [net/unimodem/src/serwvdrv](../../net/unimodem/src/serwvdrv) | 14 | [net/unimodem/src/serwvdrv/sources](../../net/unimodem/src/serwvdrv/sources), [net/unimodem/src/serwvdrv/makefile](../../net/unimodem/src/serwvdrv/makefile) | `serwvdrv` | `DYNLINK` |
| [net/unimodem/src/sys](../../net/unimodem/src/sys) | 1 | [net/unimodem/src/sys/dirs](../../net/unimodem/src/sys/dirs) | — | — |
| [net/unimodem/src/sys/inc](../../net/unimodem/src/sys/inc) | 1 | — | — | — |
| [net/unimodem/src/sys/modem](../../net/unimodem/src/sys/modem) | 18 | [net/unimodem/src/sys/modem/sources](../../net/unimodem/src/sys/modem/sources), [net/unimodem/src/sys/modem/makefile](../../net/unimodem/src/sys/modem/makefile) | `modem` | `DRIVER` |
| [net/unimodem/src/sys/modemcsa](../../net/unimodem/src/sys/modemcsa) | 15 | [net/unimodem/src/sys/modemcsa/sources](../../net/unimodem/src/sys/modemcsa/sources), [net/unimodem/src/sys/modemcsa/makefile](../../net/unimodem/src/sys/modemcsa/makefile) | `modemcsa` | `DRIVER` |
| [net/unimodem/src/sys/rootmdm](../../net/unimodem/src/sys/rootmdm) | 9 | [net/unimodem/src/sys/rootmdm/sources](../../net/unimodem/src/sys/rootmdm/sources), [net/unimodem/src/sys/rootmdm/makefile](../../net/unimodem/src/sys/rootmdm/makefile) | `rootmdm` | `DRIVER` |
| [net/unimodem/src/tsp](../../net/unimodem/src/tsp) | 65 | [net/unimodem/src/tsp/sources](../../net/unimodem/src/tsp/sources), [net/unimodem/src/tsp/makefile](../../net/unimodem/src/tsp/makefile) | `unimdm` | `DYNLINK` |
| [net/unimodem/src/umcfg](../../net/unimodem/src/umcfg) | 13 | [net/unimodem/src/umcfg/sources](../../net/unimodem/src/umcfg/sources), [net/unimodem/src/umcfg/makefile](../../net/unimodem/src/umcfg/makefile) | `umcfg` | `PROGRAM` |
| [net/unimodem/src/umdmxfrm](../../net/unimodem/src/umdmxfrm) | 18 | [net/unimodem/src/umdmxfrm/sources](../../net/unimodem/src/umdmxfrm/sources), [net/unimodem/src/umdmxfrm/makefile](../../net/unimodem/src/umdmxfrm/makefile) | `umdmxfrm` | `DYNLINK` |
| [net/unimodem/src/uniplat](../../net/unimodem/src/uniplat) | 13 | [net/unimodem/src/uniplat/sources](../../net/unimodem/src/uniplat/sources), [net/unimodem/src/uniplat/makefile](../../net/unimodem/src/uniplat/makefile) | `uniplat` | `DYNLINK` |
| [net/unimodem/src/w95migr](../../net/unimodem/src/w95migr) | 15 | [net/unimodem/src/w95migr/sources](../../net/unimodem/src/w95migr/sources), [net/unimodem/src/w95migr/makefile](../../net/unimodem/src/w95migr/makefile) | `migrate` | `DYNLINK` |
| [net/unimodem/tools](../../net/unimodem/tools) | 1 | [net/unimodem/tools/dirs](../../net/unimodem/tools/dirs) | — | — |
| [net/unimodem/tools/procalc](../../net/unimodem/tools/procalc) | 3 | — | — | — |
| [net/unimodem/tools/src](../../net/unimodem/tools/src) | 66 | — | — | — |

## `net/upnp/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/upnp](../../net/upnp) | 2 | [net/upnp/dirs](../../net/upnp/dirs) | — | — |
| [net/upnp/common](../../net/upnp/common) | 1 | [net/upnp/common/dirs](../../net/upnp/common/dirs) | — | — |
| [net/upnp/common/upbase](../../net/upnp/common/upbase) | 23 | [net/upnp/common/upbase/sources](../../net/upnp/common/upbase/sources), [net/upnp/common/upbase/makefile](../../net/upnp/common/upbase/makefile) | `upbase` | `LIBRARY` |
| [net/upnp/common/upcom](../../net/upnp/common/upcom) | 3 | [net/upnp/common/upcom/sources](../../net/upnp/common/upcom/sources), [net/upnp/common/upcom/makefile](../../net/upnp/common/upcom/makefile) | `upcom` | `LIBRARY` |
| [net/upnp/common/updebug](../../net/upnp/common/updebug) | 6 | [net/upnp/common/updebug/sources](../../net/upnp/common/updebug/sources), [net/upnp/common/updebug/makefile](../../net/upnp/common/updebug/makefile) | `updebug` | `LIBRARY` |
| [net/upnp/common/upnetwork](../../net/upnp/common/upnetwork) | 5 | [net/upnp/common/upnetwork/sources](../../net/upnp/common/upnetwork/sources), [net/upnp/common/upnetwork/makefile](../../net/upnp/common/upnetwork/makefile) | `upnetwork` | `LIBRARY` |
| [net/upnp/common/upthread](../../net/upnp/common/upthread) | 3 | [net/upnp/common/upthread/sources](../../net/upnp/common/upthread/sources), [net/upnp/common/upthread/makefile](../../net/upnp/common/upthread/makefile) | `upthread` | `LIBRARY` |
| [net/upnp/host](../../net/upnp/host) | 3 | [net/upnp/host/dirs](../../net/upnp/host/dirs) | — | — |
| [net/upnp/host/common](../../net/upnp/host/common) | 5 | [net/upnp/host/common/sources](../../net/upnp/host/common/sources), [net/upnp/host/common/makefile](../../net/upnp/host/common/makefile) | `uhcommon` | `LIBRARY` |
| [net/upnp/host/idl](../../net/upnp/host/idl) | 4 | [net/upnp/host/idl/sources](../../net/upnp/host/idl/sources), [net/upnp/host/idl/makefile](../../net/upnp/host/idl/makefile) | `idl` | `LIBRARY` |
| [net/upnp/host/inc](../../net/upnp/host/inc) | 6 | — | — | — |
| [net/upnp/host/sample](../../net/upnp/host/sample) | 1 | [net/upnp/host/sample/dirs](../../net/upnp/host/sample/dirs) | — | — |
| [net/upnp/host/sample/idl](../../net/upnp/host/sample/idl) | 3 | [net/upnp/host/sample/idl/sources](../../net/upnp/host/sample/idl/sources), [net/upnp/host/sample/idl/makefile](../../net/upnp/host/sample/idl/makefile) | `idl` | `LIBRARY` |
| [net/upnp/host/sample/inst](../../net/upnp/host/sample/inst) | 8 | [net/upnp/host/sample/inst/sources](../../net/upnp/host/sample/inst/sources), [net/upnp/host/sample/inst/makefile](../../net/upnp/host/sample/inst/makefile) | `hosttest` | `PROGRAM` |
| [net/upnp/host/sample/src](../../net/upnp/host/sample/src) | 15 | [net/upnp/host/sample/src/sources](../../net/upnp/host/sample/src/sources), [net/upnp/host/sample/src/makefile](../../net/upnp/host/sample/src/makefile) | `sdev` | `DYNLINK` |
| [net/upnp/host/udhdiag](../../net/upnp/host/udhdiag) | 5 | [net/upnp/host/udhdiag/sources](../../net/upnp/host/udhdiag/sources), [net/upnp/host/udhdiag/makefile](../../net/upnp/host/udhdiag/makefile) | `udhdiag` | `PROGRAM` |
| [net/upnp/host/udhisapi](../../net/upnp/host/udhisapi) | 18 | [net/upnp/host/udhisapi/sources](../../net/upnp/host/udhisapi/sources), [net/upnp/host/udhisapi/makefile](../../net/upnp/host/udhisapi/makefile) | `udhisapi` | `DYNLINK` |
| [net/upnp/host/upnpcont](../../net/upnp/host/upnpcont) | 1 | [net/upnp/host/upnpcont/dirs](../../net/upnp/host/upnpcont/dirs) | — | — |
| [net/upnp/host/upnpcont/cont](../../net/upnp/host/upnpcont/cont) | 5 | [net/upnp/host/upnpcont/cont/sources](../../net/upnp/host/upnpcont/cont/sources), [net/upnp/host/upnpcont/cont/makefile](../../net/upnp/host/upnpcont/cont/makefile) | `cont` | `LIBRARY` |
| [net/upnp/host/upnpcont/dll](../../net/upnp/host/upnpcont/dll) | 9 | [net/upnp/host/upnpcont/dll/sources](../../net/upnp/host/upnpcont/dll/sources), [net/upnp/host/upnpcont/dll/makefile](../../net/upnp/host/upnpcont/dll/makefile) | `upnpcont` | `DYNLINK` |
| [net/upnp/host/upnpcont/exe](../../net/upnp/host/upnpcont/exe) | 6 | [net/upnp/host/upnpcont/exe/sources](../../net/upnp/host/upnpcont/exe/sources), [net/upnp/host/upnpcont/exe/makefile](../../net/upnp/host/upnpcont/exe/makefile) | `upnpcont` | `PROGRAM` |
| [net/upnp/host/upnpcont/inc](../../net/upnp/host/upnpcont/inc) | 3 | — | — | — |
| [net/upnp/host/upnphost](../../net/upnp/host/upnphost) | 2 | [net/upnp/host/upnphost/dirs](../../net/upnp/host/upnphost/dirs) | — | — |
| [net/upnp/host/upnphost/automationproxy](../../net/upnp/host/upnphost/automationproxy) | 4 | [net/upnp/host/upnphost/automationproxy/sources](../../net/upnp/host/upnphost/automationproxy/sources), [net/upnp/host/upnphost/automationproxy/makefile](../../net/upnp/host/upnphost/automationproxy/makefile) | `AutomationProxy` | `LIBRARY` |
| [net/upnp/host/upnphost/dll](../../net/upnp/host/upnphost/dll) | 16 | [net/upnp/host/upnphost/dll/sources](../../net/upnp/host/upnphost/dll/sources), [net/upnp/host/upnphost/dll/makefile](../../net/upnp/host/upnphost/dll/makefile) | `upnphost` | `DYNLINK` |
| [net/upnp/host/upnphost/evtapi](../../net/upnp/host/upnphost/evtapi) | 5 | [net/upnp/host/upnphost/evtapi/sources](../../net/upnp/host/upnphost/evtapi/sources), [net/upnp/host/upnphost/evtapi/makefile](../../net/upnp/host/upnphost/evtapi/makefile) | `hostevt` | `LIBRARY` |
| [net/upnp/host/upnphost/inc](../../net/upnp/host/upnphost/inc) | 29 | — | — | — |
| [net/upnp/host/upnphost/registrar](../../net/upnp/host/upnphost/registrar) | 36 | [net/upnp/host/upnphost/registrar/sources](../../net/upnp/host/upnphost/registrar/sources), [net/upnp/host/upnphost/registrar/makefile](../../net/upnp/host/upnphost/registrar/makefile) | `registrar` | `LIBRARY` |
| [net/upnp/host/upnphost/udhhttp](../../net/upnp/host/upnphost/udhhttp) | 21 | [net/upnp/host/upnphost/udhhttp/sources](../../net/upnp/host/upnphost/udhhttp/sources), [net/upnp/host/upnphost/udhhttp/makefile](../../net/upnp/host/upnphost/udhhttp/makefile) | `udhhttp` | `LIBRARY` |
| [net/upnp/host/upnpreg](../../net/upnp/host/upnpreg) | 5 | [net/upnp/host/upnpreg/sources](../../net/upnp/host/upnpreg/sources), [net/upnp/host/upnpreg/makefile](../../net/upnp/host/upnpreg/makefile) | `upnpreg` | `PROGRAM` |
| [net/upnp/host/utl2idl](../../net/upnp/host/utl2idl) | 5 | [net/upnp/host/utl2idl/sources](../../net/upnp/host/utl2idl/sources), [net/upnp/host/utl2idl/makefile](../../net/upnp/host/utl2idl/makefile) | `utl2idl` | `PROGRAM` |
| [net/upnp/inc](../../net/upnp/inc) | 46 | [net/upnp/inc/sources](../../net/upnp/inc/sources), [net/upnp/inc/makefile](../../net/upnp/inc/makefile) | — | `NOTARGET` |
| [net/upnp/proto](../../net/upnp/proto) | 0 | — | — | — |
| [net/upnp/proto/ssdp](../../net/upnp/proto/ssdp) | 0 | — | — | — |
| [net/upnp/proto/ssdp/network](../../net/upnp/proto/ssdp/network) | 2 | — | — | — |
| [net/upnp/setup](../../net/upnp/setup) | 2 | — | — | — |
| [net/upnp/ssdp](../../net/upnp/ssdp) | 1 | [net/upnp/ssdp/dirs](../../net/upnp/ssdp/dirs) | — | — |
| [net/upnp/ssdp/common](../../net/upnp/ssdp/common) | 1 | [net/upnp/ssdp/common/dirs](../../net/upnp/ssdp/common/dirs) | — | — |
| [net/upnp/ssdp/common/eventsrv](../../net/upnp/ssdp/common/eventsrv) | 3 | [net/upnp/ssdp/common/eventsrv/sources](../../net/upnp/ssdp/common/eventsrv/sources), [net/upnp/ssdp/common/eventsrv/makefile](../../net/upnp/ssdp/common/eventsrv/makefile) | `eventsrv` | `LIBRARY` |
| [net/upnp/ssdp/common/ssdpnetwork](../../net/upnp/ssdp/common/ssdpnetwork) | 4 | [net/upnp/ssdp/common/ssdpnetwork/sources](../../net/upnp/ssdp/common/ssdpnetwork/sources), [net/upnp/ssdp/common/ssdpnetwork/makefile](../../net/upnp/ssdp/common/ssdpnetwork/makefile) | `ssdpnetwork` | `LIBRARY` |
| [net/upnp/ssdp/common/ssdpparser](../../net/upnp/ssdp/common/ssdpparser) | 4 | [net/upnp/ssdp/common/ssdpparser/sources](../../net/upnp/ssdp/common/ssdpparser/sources), [net/upnp/ssdp/common/ssdpparser/makefile](../../net/upnp/ssdp/common/ssdpparser/makefile) | `ssdpparser` | `LIBRARY` |
| [net/upnp/ssdp/common/ssdpsrv](../../net/upnp/ssdp/common/ssdpsrv) | 19 | [net/upnp/ssdp/common/ssdpsrv/sources](../../net/upnp/ssdp/common/ssdpsrv/sources), [net/upnp/ssdp/common/ssdpsrv/makefile](../../net/upnp/ssdp/common/ssdpsrv/makefile) | `ssdpsrv` | `LIBRARY` |
| [net/upnp/ssdp/common/ssdptimer](../../net/upnp/ssdp/common/ssdptimer) | 4 | [net/upnp/ssdp/common/ssdptimer/sources](../../net/upnp/ssdp/common/ssdptimer/sources), [net/upnp/ssdp/common/ssdptimer/makefile](../../net/upnp/ssdp/common/ssdptimer/makefile) | `ssdptimer` | `LIBRARY` |
| [net/upnp/ssdp/common/ssdptimer/test](../../net/upnp/ssdp/common/ssdptimer/test) | 7 | [net/upnp/ssdp/common/ssdptimer/test/sources](../../net/upnp/ssdp/common/ssdptimer/test/sources), [net/upnp/ssdp/common/ssdptimer/test/makefile](../../net/upnp/ssdp/common/ssdptimer/test/makefile) | `testtimer` | `PROGRAM` |
| [net/upnp/ssdp/inc](../../net/upnp/ssdp/inc) | 11 | — | — | — |
| [net/upnp/ssdp/ssdpapi](../../net/upnp/ssdp/ssdpapi) | 18 | [net/upnp/ssdp/ssdpapi/sources](../../net/upnp/ssdp/ssdpapi/sources), [net/upnp/ssdp/ssdpapi/makefile](../../net/upnp/ssdp/ssdpapi/makefile) | `ssdpapi` | `DYNLINK` |
| [net/upnp/ssdp/ssdpsrv](../../net/upnp/ssdp/ssdpsrv) | 1 | [net/upnp/ssdp/ssdpsrv/dirs](../../net/upnp/ssdp/ssdpsrv/dirs) | — | — |
| [net/upnp/ssdp/ssdpsrv/nt](../../net/upnp/ssdp/ssdpsrv/nt) | 8 | [net/upnp/ssdp/ssdpsrv/nt/sources](../../net/upnp/ssdp/ssdpsrv/nt/sources), [net/upnp/ssdp/ssdpsrv/nt/makefile](../../net/upnp/ssdp/ssdpsrv/nt/makefile) | `ssdpsrv` | `DYNLINK` |
| [net/upnp/ssdp/ssdpsrv/nt/objd](../../net/upnp/ssdp/ssdpsrv/nt/objd) | 0 | — | — | — |
| [net/upnp/ssdp/ssdpsrv/nt/objd/i386](../../net/upnp/ssdp/ssdpsrv/nt/objd/i386) | 1 | — | — | — |
| [net/upnp/tools](../../net/upnp/tools) | 1 | [net/upnp/tools/dirs](../../net/upnp/tools/dirs) | — | — |
| [net/upnp/tools/esmon](../../net/upnp/tools/esmon) | 6 | [net/upnp/tools/esmon/sources](../../net/upnp/tools/esmon/sources), [net/upnp/tools/esmon/makefile](../../net/upnp/tools/esmon/makefile) | `esmon` | `PROGRAM` |
| [net/upnp/tools/inc](../../net/upnp/tools/inc) | 2 | — | — | — |
| [net/upnp/tools/isapictl](../../net/upnp/tools/isapictl) | 6 | [net/upnp/tools/isapictl/sources](../../net/upnp/tools/isapictl/sources), [net/upnp/tools/isapictl/makefile](../../net/upnp/tools/isapictl/makefile) | `isapictl` | `DYNLINK` |
| [net/upnp/tools/scpdgen](../../net/upnp/tools/scpdgen) | 5 | [net/upnp/tools/scpdgen/sources](../../net/upnp/tools/scpdgen/sources), [net/upnp/tools/scpdgen/makefile](../../net/upnp/tools/scpdgen/makefile) | `scpdgen` | `PROGRAM` |
| [net/upnp/tools/updiag](../../net/upnp/tools/updiag) | 18 | [net/upnp/tools/updiag/sources](../../net/upnp/tools/updiag/sources), [net/upnp/tools/updiag/makefile](../../net/upnp/tools/updiag/makefile) | `updiag` | `PROGRAM` |
| [net/upnp/tools/util](../../net/upnp/tools/util) | 3 | [net/upnp/tools/util/sources](../../net/upnp/tools/util/sources), [net/upnp/tools/util/makefile](../../net/upnp/tools/util/makefile) | `util` | `LIBRARY` |
| [net/upnp/tools/validatesd](../../net/upnp/tools/validatesd) | 3 | [net/upnp/tools/validatesd/sources](../../net/upnp/tools/validatesd/sources), [net/upnp/tools/validatesd/makefile](../../net/upnp/tools/validatesd/makefile) | `validateSD` | `PROGRAM` |
| [net/upnp/upnp](../../net/upnp/upnp) | 1 | [net/upnp/upnp/dirs](../../net/upnp/upnp/dirs) | — | — |
| [net/upnp/upnp/api](../../net/upnp/upnp/api) | 21 | [net/upnp/upnp/api/sources](../../net/upnp/upnp/api/sources), [net/upnp/upnp/api/makefile](../../net/upnp/upnp/api/makefile) | `upnpapi` | `LIBRARY` |
| [net/upnp/upnp/dll](../../net/upnp/upnp/dll) | 18 | [net/upnp/upnp/dll/sources](../../net/upnp/upnp/dll/sources), [net/upnp/upnp/dll/makefile](../../net/upnp/upnp/dll/makefile) | `upnp` | `DYNLINK` |
| [net/upnp/upnp/host](../../net/upnp/upnp/host) | 8 | [net/upnp/upnp/host/sources](../../net/upnp/upnp/host/sources), [net/upnp/upnp/host/makefile](../../net/upnp/upnp/host/makefile) | `host` | `LIBRARY` |
| [net/upnp/upnp/inc](../../net/upnp/upnp/inc) | 27 | — | — | — |
| [net/upnp/upnp/rehy](../../net/upnp/upnp/rehy) | 8 | [net/upnp/upnp/rehy/sources](../../net/upnp/upnp/rehy/sources), [net/upnp/upnp/rehy/makefile](../../net/upnp/upnp/rehy/makefile) | `upnprehy` | `LIBRARY` |
| [net/upnp/upnp/test-clients](../../net/upnp/upnp/test-clients) | 1 | [net/upnp/upnp/test-clients/dirs](../../net/upnp/upnp/test-clients/dirs) | — | — |
| [net/upnp/upnp/test-clients/downloadctest](../../net/upnp/upnp/test-clients/downloadctest) | 13 | — | — | — |
| [net/upnp/upnp/test-clients/downloadctest/res](../../net/upnp/upnp/test-clients/downloadctest/res) | 5 | — | — | — |
| [net/upnp/upnp/test-clients/samplecppclient](../../net/upnp/upnp/test-clients/samplecppclient) | 1 | — | — | — |
| [net/upnp/upnp/test-clients/scripts](../../net/upnp/upnp/test-clients/scripts) | 6 | — | — | — |
| [net/upnp/upnpui](../../net/upnp/upnpui) | 1 | [net/upnp/upnpui/dirs](../../net/upnp/upnpui/dirs) | — | — |
| [net/upnp/upnpui/common](../../net/upnp/upnpui/common) | 4 | [net/upnp/upnpui/common/sources](../../net/upnp/upnpui/common/sources), [net/upnp/upnpui/common/makefile](../../net/upnp/upnpui/common/makefile) | `upscmn` | `LIBRARY` |
| [net/upnp/upnpui/dll](../../net/upnp/upnpui/dll) | 48 | [net/upnp/upnpui/dll/sources](../../net/upnp/upnpui/dll/sources), [net/upnp/upnpui/dll/makefile](../../net/upnp/upnpui/dll/makefile) | `upnpui` | `DYNLINK` |
| [net/upnp/upnpui/idl](../../net/upnp/upnpui/idl) | 5 | [net/upnp/upnpui/idl/sources](../../net/upnp/upnpui/idl/sources), [net/upnp/upnpui/idl/makefile](../../net/upnp/upnpui/idl/makefile) | — | `NOTARGET` |
| [net/upnp/upnpui/inc](../../net/upnp/upnpui/inc) | 22 | — | — | — |
| [net/upnp/upnpui/res](../../net/upnp/upnpui/res) | 10 | — | — | — |

## `net/winnet/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/winnet](../../net/winnet) | 36 | [net/winnet/sources](../../net/winnet/sources), [net/winnet/makefile](../../net/winnet/makefile) | `mpr` | `DYNLINK` |

## `net/wins/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/wins](../../net/wins) | 1 | [net/wins/dirs](../../net/wins/dirs) | — | — |
| [net/wins/componentdef](../../net/wins/componentdef) | 6 | [net/wins/componentdef/sources](../../net/wins/componentdef/sources), [net/wins/componentdef/makefile](../../net/wins/componentdef/makefile) | — | `NOTARGET` |
| [net/wins/idl](../../net/wins/idl) | 4 | — | — | — |
| [net/wins/mib](../../net/wins/mib) | 9 | [net/wins/mib/sources](../../net/wins/mib/sources), [net/wins/mib/makefile](../../net/wins/mib/makefile) | `winsmib` | `DYNLINK` |
| [net/wins/msgs](../../net/wins/msgs) | 4 | [net/wins/msgs/sources](../../net/wins/msgs/sources), [net/wins/msgs/makefile](../../net/wins/msgs/makefile) | `winsevnt` | `DYNLINK` |
| [net/wins/netsh](../../net/wins/netsh) | 20 | [net/wins/netsh/sources](../../net/wins/netsh/sources), [net/wins/netsh/makefile](../../net/wins/netsh/makefile) | `winsmon` | `DYNLINK` |
| [net/wins/perfctrs](../../net/wins/perfctrs) | 20 | [net/wins/perfctrs/sources](../../net/wins/perfctrs/sources), [net/wins/perfctrs/makefile](../../net/wins/perfctrs/makefile) | `winsctrs` | `DYNLINK` |
| [net/wins/rpc](../../net/wins/rpc) | 15 | [net/wins/rpc/sources](../../net/wins/rpc/sources), [net/wins/rpc/makefile](../../net/wins/rpc/makefile) | `winsrpc` | `DYNLINK` |
| [net/wins/server](../../net/wins/server) | 1 | [net/wins/server/dirs](../../net/wins/server/dirs) | — | — |
| [net/wins/server/com](../../net/wins/server/com) | 5 | [net/wins/server/com/sources](../../net/wins/server/com/sources), [net/wins/server/com/makefile](../../net/wins/server/com/makefile) | `com` | `LIBRARY` |
| [net/wins/server/inc](../../net/wins/server/inc) | 22 | — | — | — |
| [net/wins/server/msc](../../net/wins/server/msc) | 13 | [net/wins/server/msc/sources](../../net/wins/server/msc/sources), [net/wins/server/msc/makefile](../../net/wins/server/msc/makefile) | `msc` | `LIBRARY` |
| [net/wins/server/nms](../../net/wins/server/nms) | 12 | [net/wins/server/nms/sources](../../net/wins/server/nms/sources), [net/wins/server/nms/makefile](../../net/wins/server/nms/makefile) | `nms` | `PROGRAM` |
| [net/wins/server/rpl](../../net/wins/server/rpl) | 6 | [net/wins/server/rpl/sources](../../net/wins/server/rpl/sources), [net/wins/server/rpl/makefile](../../net/wins/server/rpl/makefile) | `rpl` | `LIBRARY` |

## `net/wlbs/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [net/wlbs](../../net/wlbs) | 2 | [net/wlbs/dirs](../../net/wlbs/dirs) | — | — |
| [net/wlbs/api](../../net/wlbs/api) | 22 | [net/wlbs/api/sources](../../net/wlbs/api/sources), [net/wlbs/api/makefile](../../net/wlbs/api/makefile) | `wlbsctrl` | `DYNLINK` |
| [net/wlbs/componentdef](../../net/wlbs/componentdef) | 4 | [net/wlbs/componentdef/sources](../../net/wlbs/componentdef/sources), [net/wlbs/componentdef/makefile](../../net/wlbs/componentdef/makefile) | `None` | `notarget` |
| [net/wlbs/control](../../net/wlbs/control) | 5 | [net/wlbs/control/dirs](../../net/wlbs/control/dirs) | — | — |
| [net/wlbs/control/nlb](../../net/wlbs/control/nlb) | 4 | [net/wlbs/control/nlb/sources](../../net/wlbs/control/nlb/sources), [net/wlbs/control/nlb/makefile](../../net/wlbs/control/nlb/makefile) | `nlb` | `PROGRAM` |
| [net/wlbs/control/wlbs](../../net/wlbs/control/wlbs) | 2 | [net/wlbs/control/wlbs/sources](../../net/wlbs/control/wlbs/sources), [net/wlbs/control/wlbs/makefile](../../net/wlbs/control/wlbs/makefile) | `wlbs` | `PROGRAM` |
| [net/wlbs/driver](../../net/wlbs/driver) | 26 | [net/wlbs/driver/sources](../../net/wlbs/driver/sources), [net/wlbs/driver/makefile](../../net/wlbs/driver/makefile) | `wlbs` | `DRIVER` |
| [net/wlbs/inc](../../net/wlbs/inc) | 5 | — | — | — |
| [net/wlbs/installpack](../../net/wlbs/installpack) | 15 | [net/wlbs/installpack/dirs](../../net/wlbs/installpack/dirs) | — | — |
| [net/wlbs/installpack/inf](../../net/wlbs/installpack/inf) | 4 | — | — | — |
| [net/wlbs/installpack/install](../../net/wlbs/installpack/install) | 2 | [net/wlbs/installpack/install/sources](../../net/wlbs/installpack/install/sources), [net/wlbs/installpack/install/makefile](../../net/wlbs/installpack/install/makefile) | `NLBWizard` | `PROGRAM` |
| [net/wlbs/installpack/uninstall](../../net/wlbs/installpack/uninstall) | 2 | [net/wlbs/installpack/uninstall/sources](../../net/wlbs/installpack/uninstall/sources), [net/wlbs/installpack/uninstall/makefile](../../net/wlbs/installpack/uninstall/makefile) | `NLBUninst` | `PROGRAM` |
| [net/wlbs/nlbkd](../../net/wlbs/nlbkd) | 10 | [net/wlbs/nlbkd/sources](../../net/wlbs/nlbkd/sources), [net/wlbs/nlbkd/makefile](../../net/wlbs/nlbkd/makefile) | `nlbkd` | `DYNLINK` |
| [net/wlbs/nlbmgr](../../net/wlbs/nlbmgr) | 2 | [net/wlbs/nlbmgr/dirs](../../net/wlbs/nlbmgr/dirs) | — | — |
| [net/wlbs/nlbmgr/exe](../../net/wlbs/nlbmgr/exe) | 64 | [net/wlbs/nlbmgr/exe/sources](../../net/wlbs/nlbmgr/exe/sources), [net/wlbs/nlbmgr/exe/makefile](../../net/wlbs/nlbmgr/exe/makefile) | `nlbmgr` | `PROGRAM` |
| [net/wlbs/nlbmgr/inetcfg](../../net/wlbs/nlbmgr/inetcfg) | 6 | [net/wlbs/nlbmgr/inetcfg/sources](../../net/wlbs/nlbmgr/inetcfg/sources), [net/wlbs/nlbmgr/inetcfg/makefile](../../net/wlbs/nlbmgr/inetcfg/makefile) | `nicbind` | `LIBRARY` |
| [net/wlbs/nlbmgr/nlbsprov](../../net/wlbs/nlbmgr/nlbsprov) | 26 | [net/wlbs/nlbmgr/nlbsprov/sources](../../net/wlbs/nlbmgr/nlbsprov/sources), [net/wlbs/nlbmgr/nlbsprov/makefile](../../net/wlbs/nlbmgr/nlbsprov/makefile) | `nlbsprov` | `LIBRARY` |
| [net/wlbs/nlbmgr/provider](../../net/wlbs/nlbmgr/provider) | 21 | [net/wlbs/nlbmgr/provider/sources](../../net/wlbs/nlbmgr/provider/sources), [net/wlbs/nlbmgr/provider/makefile](../../net/wlbs/nlbmgr/provider/makefile) | `nlbmprov` | `DYNLINK` |
| [net/wlbs/nlbmgr/provider/tests](../../net/wlbs/nlbmgr/provider/tests) | 15 | [net/wlbs/nlbmgr/provider/tests/sources](../../net/wlbs/nlbmgr/provider/tests/sources), [net/wlbs/nlbmgr/provider/tests/makefile](../../net/wlbs/nlbmgr/provider/tests/makefile) | `tprov` | `PROGRAM` |
| [net/wlbs/nlbmgr/tmgr](../../net/wlbs/nlbmgr/tmgr) | 20 | [net/wlbs/nlbmgr/tmgr/sources](../../net/wlbs/nlbmgr/tmgr/sources), [net/wlbs/nlbmgr/tmgr/makefile](../../net/wlbs/nlbmgr/tmgr/makefile) | `tmgr` | `PROGRAM` |
| [net/wlbs/nlbmgr/wmibase](../../net/wlbs/nlbmgr/wmibase) | 25 | [net/wlbs/nlbmgr/wmibase/sources](../../net/wlbs/nlbmgr/wmibase/sources), [net/wlbs/nlbmgr/wmibase/makefile](../../net/wlbs/nlbmgr/wmibase/makefile) | `wmibase` | `LIBRARY` |
| [net/wlbs/util](../../net/wlbs/util) | 6 | [net/wlbs/util/sources](../../net/wlbs/util/sources), [net/wlbs/util/makefile](../../net/wlbs/util/makefile) | `wlbsutil` | `LIBRARY` |
| [net/wlbs/utilities](../../net/wlbs/utilities) | 0 | — | — | — |
| [net/wlbs/utilities/tracing](../../net/wlbs/utilities/tracing) | 4 | — | — | — |
| [net/wlbs/wmi](../../net/wlbs/wmi) | 49 | [net/wlbs/wmi/sources](../../net/wlbs/wmi/sources), [net/wlbs/wmi/makefile](../../net/wlbs/wmi/makefile) | `wlbsprov` | `DYNLINK` |
| [net/wlbs/wmi2](../../net/wlbs/wmi2) | 7 | — | — | — |
| [net/wlbs/xml](../../net/wlbs/xml) | 15 | [net/wlbs/xml/sources](../../net/wlbs/xml/sources), [net/wlbs/xml/makefile](../../net/wlbs/xml/makefile) | `xml` | `PROGRAM` |
