---
content_title: Kmtpd
---

## Introduction

`kmtpd` is a key manager service daemon for storing private keys and signing digital messages. It provides a secure key storage medium for keys to be encrypted at rest in the associated wallet file. `kmtpd` also defines a secure enclave for signing transaction created by `clmtp` or a third part library.

## Installation

`kmtpd` is distributed as part of the [MTPIO software suite](https://github.com/MTPIO/mtp/blob/master/README.md). To install `kmtpd` just visit the [MTPIO Software Installation](../00_install/index.md) section.

## Operation

When a wallet is unlocked with the corresponding password, `clmtp` can request `kmtpd` to sign a transaction with the appropriate private keys. Also, `kmtpd` provides support for hardware-based wallets such as Secure Encalve and YubiHSM.

[[info | Audience]]
| `kmtpd` is intended to be used by MTPIO developers only.
