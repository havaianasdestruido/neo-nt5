# security: README publishes product keys

Status: **not published — repository Issues disabled**. Local finding A15.

## Summary

The root README exposes product keys in plain text, violating the project guide instruction not to publish embedded product keys and complicating safe redistribution/forking.

## Evidence and reproduction

`README.md:75–79`:

```markdown
## Product Keys

- **Standard Edition**: `M6RJ9-TBJH3-9DDXM-4VX9Q-K8M8M`
- **Enterprise Edition**: `QW32K-48T2T-3D2PJ-DXBWY-C6WRJ`
- **Enterprise x64**: `KK2WD-BFYJ6-77X87-8TRBF-9B343`
```

`agents/README.md:68–72`:

```markdown

## Scope and provenance

Paths and claims in these guides refer to the files in this repository, not to every released NEONT 5.x SKU. This checkout mixes XP/Server-related trees and contains version- and architecture-specific branches. For example, [`public/sdk/inc/ntverp.h`](../../public/sdk/inc/ntverp.h) declares a 5.1/2600 version in this snapshot; the repository README's broader product description does not make every directory a Server 2003 component. The [repository README](../../README.md) includes historic build instructions, but some named helpers are absent here. Do not publish embedded product keys, private certificates, or binaries as part of an agent's report. Respect the rights and licenses applicable to this proprietary source tree.
```

Static grep confirms these keys appear in README.md. The agent guide explicitly says not to publish embedded product keys as part of a report or guide. Expected: no product keys in repository documentation.

## Root cause

Product keys were added to the public README without redaction.

## Impact and severity

**Medium** — Repository documentation.

## Recommended fix

Remove or replace the literal keys with instructions for obtaining install media/keys from a legitimate Microsoft source; scrub repository history if required by policy.

## Acceptance criteria

- [ ] Literal product-key strings no longer appear in tracked source/docs.
- [ ] README still explains SKU/installation steps without disclosing license keys.
- [ ] A contribution guideline/document review note warns against future key publication.

## Verification limitations

Whether these keys are valid or revocable for a specific edition was not validated, and no additional copies are reproduced in this report.

## Deduplication

Checked all available open/closed issue records, PRs #1/#2, their issue comments, review comments and reviews on 2026-10-16. No matching defect report found. PR #2 describes branding as a feature, not these failures. Discussions are disabled.
