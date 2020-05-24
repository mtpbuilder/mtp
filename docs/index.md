---
content_title: MTPIO Overview
---

MTPIO is the next-generation blockchain platform for creating and deploying smart contracts and distributed applications. MTPIO comes with a number of programs. The primary ones included in MTPIO are the following:

* [Nodmtp](01_nodmtp/index.md) (node + mtp = nodmtp)  - core service daemon that runs a node for block production, API endpoints, or local development.
* [Clmtp](02_clmtp/index.md) (cli + mtp = clmtp) - command line interface to interact with the blockchain (via `nodmtp`) and manage wallets (via `kmtpd`).
* [Kmtpd](03_kmtpd/index.md) (key + mtp = kmtpd) - component that manages MTPIO keys in wallets and provides a secure enclave for digital signing.

The basic relationship between these components is illustrated in the diagram below.

![MTPIO components](mtpio_components.png)

[[info | What's Next?]]
| [Install the MTPIO Software](00_install/index.md) before exploring the sections above.
