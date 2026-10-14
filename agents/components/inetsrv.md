# `inetsrv/` — Internet server and indexing roles

This tree contains IIS, Message Queuing, indexing/query and language word-breakers. It consumes networking, security, COM and setup infrastructure from other projects. It is distinct from the browser/client code in [`inetcore/`](inetcore.md). [`inetsrv/dirs`](../../inetsrv/dirs) defines this project's build traversal; [the complete catalog](../catalog/inetsrv.md) lists its nested targets and data.

| Path (relative to `inetsrv/`) | Responsibility |
| --- | --- |
| [`iis`](../../inetsrv/iis) | IIS service/HTTP/FTP, metabase, administration, setup and web content; see below. |
| [`msmq`](../../inetsrv/msmq) | Microsoft Message Queuing services, clients and management. |
| [`query`](../../inetsrv/query) | Indexing Service / content indexing, query, filters and administrative tools. |
| [`intlwb`](../../inetsrv/intlwb) | Language-specific word breakers and search/indexing support. |
| [`published`](../../inetsrv/published) | Shared/publication interfaces for server consumers. |

## IIS substructure

[`inetsrv/iis/iisrearc`](../../inetsrv/iis/iisrearc) contains core/IIS rearchitecture and HTTP-oriented pieces; [`svcs/w3`](../../inetsrv/iis/svcs/w3) contains web-service subtrees, while [`svcs/ftp`](../../inetsrv/iis/svcs/ftp), `smtp` and `nntp` cover other protocols. [`admin`](../../inetsrv/iis/admin) contains ADSI/management/UI/provider paths; [`setup`](../../inetsrv/iis/setup) and [`img`](../../inetsrv/iis/img) cover installation/web content. `svcs`, `lkrhash`, `staxinc` and other supporting directories have their own build definitions. Do not equate a configuration snap-in with request processing or assume every protocol is installed for every SKU.

## Boundaries to test

A web request traverses NIC/NDIS/TCP/IP, IIS service/request code, authentication/authorization, application or static content and optionally management/configuration; see [web flow](../system-flows.md#6-a-web-request-or-print-job). Indexing also crosses filesystem notifications, filters and query APIs. Check RPC/COM/metabase/registry contracts, service registration, INF/postbuild and security credentials. [`inetsrv/dirs`](../../inetsrv/dirs) names `infosoft`, which is absent here; full service/media builds are not established by this guide.
