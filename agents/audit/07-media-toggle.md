# bug: multimedia product resources ignore NEONT_BRANDING=0

Status: **not published — repository Issues disabled**. Local finding A07.

## Summary

Three multimedia headers define a branding toggle but unconditionally emit NEONT product names for WIN32, contradicting the advertised official-branding opt-out.

## Evidence and reproduction

`public/sdk/inc/ntverp.h:26–29`:

```c
/* NEONT branding toggle: default enabled (NEONT). Define NEONT_BRANDING=0 for official branding. */
#ifndef NEONT_BRANDING
#define NEONT_BRANDING 1
#endif
```

`multimedia/media/mmcaps2k/mmcaps.h:64–79`:

```c
#ifdef WIN32
#if (defined(_X86_)) || (defined(i386))
#define APP_VERSION_PRODUCTNAME_RC  "NEONT (i386)\0"
#endif
#if (defined(_MIPS_)) || (defined(MIPS))
#define APP_VERSION_PRODUCTNAME_RC  "NEONT (MIPS)\0"
#endif
#if (defined(_ALPHA_)) || (defined(ALPHA))
#define APP_VERSION_PRODUCTNAME_RC  "NEONT (Alpha)\0"
#endif
#ifndef APP_VERSION_PRODUCTNAME_RC
#define APP_VERSION_PRODUCTNAME_RC  "NEONT\0"
#endif
#else
#define APP_VERSION_PRODUCTNAME_RC  "Microsoft Windows\0"
#endif
```

`multimedia/media/samples/acmapp/acmapp.h:77–95`:

```c
#ifdef WIN32
#if (defined(_X86_)) || (defined(i386))
#define APP_VERSION_PRODUCTNAME_RC  "NEONT Sample Application (i386)\0"
#endif
#if (defined(_MIPS_)) || (defined(MIPS))
#define APP_VERSION_PRODUCTNAME_RC  "NEONT Sample Application (MIPS)\0"
#endif
#if (defined(_ALPHA_)) || (defined(ALPHA))
#define APP_VERSION_PRODUCTNAME_RC  "NEONT Sample Application (Alpha)\0"
#endif
#if (defined(_PPC_)) || (defined(PPC))
#define APP_VERSION_PRODUCTNAME_RC  "NEONT Sample Application (PowerPC)\0"
#endif
#ifndef APP_VERSION_PRODUCTNAME_RC
#define APP_VERSION_PRODUCTNAME_RC  "NEONT Sample Application\0"
#endif
#else
#define APP_VERSION_PRODUCTNAME_RC  "Microsoft Windows Sample Application\0"
#endif
```

Run `python3 agents/audit_reproduce.py` from the checkout. Preprocessing the exact product-name conditional from mmcaps2k with WIN32, _X86_, and NEONT_BRANDING=0 emits `"NEONT (i386)\0"`. The same pattern is present in `multimedia/media/samples/mmcapsex/mmcaps.h:64–79`. Expected: the original Microsoft Windows NT product string when branding is disabled.

## Root cause

NEONT replacements were made without guarding product-name declarations with #if NEONT_BRANDING.

## Impact and severity

**Low** — Multimedia version resources.

## Recommended fix

Condition the product-name macros in all three headers and retain the existing architecture suffixes in both branches.

## Acceptance criteria

- [ ] All three resource headers emit original product names with branding=0.
- [ ] Default/branding=1 still emits NEONT names.
- [ ] Preprocessor tests cover each architecture-specific and fallback product name.

## Verification limitations

No Windows build, installed OS, or original Microsoft compiler/resource compiler is available. Extracted-code results do not establish a complete product build or boot result. Only the product-name conditional was extracted to avoid unrelated missing Windows SDK includes; no linked PE resources were inspected.

## Deduplication

Checked all available open/closed issue records, PRs #1/#2, their issue comments, review comments and reviews on 2026-10-16. No matching defect report found. PR #2 describes branding as a feature, not these failures. Discussions are disabled.
