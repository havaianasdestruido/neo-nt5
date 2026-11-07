---
title: Project overview
slug: /
sidebar_position: 1
---

NEONT 5 is a large Windows NT-family source tree. Start with the [project README](https://github.com/havaianasdestruido/neo-nt5/blob/main/README.md) for Razzle, build and packaging commands. The [architecture guide](https://github.com/havaianasdestruido/neo-nt5/blob/main/agents/architecture.md) explains the major runtime boundaries; the [component guides and directory catalog](https://github.com/havaianasdestruido/neo-nt5/blob/main/agents/README.md) map the tree, including build and checkout limitations.

## Find a function

Browse the [generated function index](reference/). Each entry links to the definition at the indexed revision, shows its signature, compares same-name body hashes, and links syntactic calls in test-named files. Follow the source link to read the implementation; follow the test links to inspect assertions and setup. The [coverage report](reference/coverage) explains what could not be analyzed.

## Keeping this site current

The Pages workflow regenerates the index from the checked-out repository on each push to the default branch and on manual dispatch. For local generation and validation see [the documentation maintainer guide](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/README.md). The generated index is evidence for investigation, not a substitute for semantic review or running tests.
