---
content_title: Nodmtp
---

## Introduction

`nodmtp` is the core service daemon that runs on every MTPIO node. It can be configured to process smart contracts, validate transactions, produce blocks containing valid transactions, and confirm blocks to record them on the blockchain.

## Installation

`nodmtp` is distributed as part of the [MTPIO software suite](https://github.com/MTPIO/mtp/blob/master/README.md). To install `nodmtp`, visit the [MTPIO Software Installation](../00_install/index.md) section.

## Explore

Navigate the sections below to configure and use `nodmtp`.

* [Usage](02_usage/index.md) - Configuring and using `nodmtp`, node setups/environments.
* [Plugins](03_plugins/index.md) - Using plugins, plugin options, mandatory vs. optional.
* [Replays](04_replays/index.md) - Replaying the chain from a snapshot or a blocks.log file.
* [Logging](06_logging/index.md) - Logging config/usage, loggers, appenders, logging levels.
* [Upgrade Guides](07_upgrade-guides/index.md) - MTPIO version/consensus upgrade guides.
* [Troubleshooting](08_troubleshooting/index.md) - Common `nodmtp` troubleshooting questions.

[[info | Access Node]]
| A local or remote MTPIO access node running `nodmtp` is required for a client application or smart contract to interact with the blockchain.
