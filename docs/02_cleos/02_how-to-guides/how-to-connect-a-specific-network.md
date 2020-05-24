## Goal

Connect to a specific `nodmtp` or `kmtpd` host to send COMMAND

`clmtp` and `kmtpd` can connect to a specific node by using the `--url` or `--wallet-url` optional arguments, respectively, followed by the http address and port number these services are listening to.

[[info | Default address:port]]
| If no optional arguments are used (i.e. `--url` or `--wallet-url`), `clmtp` attempts to connect to a local `nodmtp` or `kmtpd` running at localhost `127.0.0.1` and default port `8888`.

## Before you begin

* Install the currently supported version of `clmtp`

## Steps
### Connecting to Nodmtp

```sh
clmtp -url http://nodmtp-host:8888 COMMAND
```

### Connecting to Kmtpd

```sh
clmtp --wallet-url http://kmtpd-host:8888 COMMAND
```
