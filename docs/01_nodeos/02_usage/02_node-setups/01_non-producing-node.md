---
content_title: Non-producing Node Setup
---

## Goal

This section describes how to set up a non-producing node within the MTPIO network. A non-producing node is a node that is not configured to produce blocks, instead it is connected and synchronized with other peers from an `MTPIO` based blockchain, exposing one or more services publicly or privately by enabling one or more [Nodmtp Plugins](../../03_plugins/index.md), except the `producer_plugin`.

## Before you begin

* [Install the MTPIO software](../../../00_install/index.md) before starting this section.
* It is assumed that `nodmtp`, `clmtp`, and `kmtpd` are accessible through the path. If you built MTPIO using shell scripts, make sure to run the [Install Script](../../../00_install/01_build-from-source/01_shell-scripts/03_install-mtpio-binaries.md).
* Know how to pass [Nodmtp options](../../02_usage/00_nodmtp-options.md) to enable or disable functionality.

## Steps

To setup a non-producing node is simple. 

1. [Set Peers](#1-set-peers)
2. [Enable one or more available plugins](#2-enable-one-or-more-available-plugins)

### 1. Set Peers

You need to set some peers in your config ini, for example:

```console
# config.ini:

p2p-peer-address = 106.10.42.238:9876
```

Or you can include the peer in as a boot flag when running `nodmtp`, as follows:

```sh
nodmtp ... --p2p-peer-address=106.10.42.238:9876
```

### 2. Enable one or more available plugins

Each available plugin is listed and detailed in the [Nodmtp Plugins](../../03_plugins/index.md) section. When `nodmtp` starts, it will expose the functionality provided by the enabled plugins it was started with. For example, if you start `nodmtp` with [`state_history_plugin`](../../03_plugins/state_history_plugin/index.md) enabled, you will have a non-producing node that offers full blockchain history. If you start `nodmtp` with [`http_plugin`](../../03_plugins/http_plugin/index.md) enabled, you will have a non-producing node which exposes the MTPIO RPC API. Therefore, you can extend the basic functionality provided by a non-producing node by enabling any number of existing plugins on top of it. Another aspect to consider is that some plugins have dependencies to other plugins. Therefore, you need to satisfy all dependencies for a plugin in order to enable it.
