---
content_title: Clmtp
---

## Introduction

`clmtp` is a command line tool that interfaces with the REST API exposed by `nodmtp`. Developers can also use `clmtp` to deploy and test MTPIO smart contracts.

## Installation

`clmtp` is distributed as part of the [MTPIO software suite](https://github.com/MTPIO/mtp/blob/master/README.md). To install `clmtp` just visit the [MTPIO Software Installation](../00_install/index.md) section.

## Using Clmtp

To use `clmtp`, you need the end point (IP address and port number) of a running `nodmtp` instance. Also, the `nodmtp` instance must be configured to load the `mtpio::chain_api_plugin` when launched. This allows `nodmtp` to respond to the RPC requests coming from `clmtp`.

### Clmtp Commands

For a list of all `clmtp` commands, run:

```sh
clmtp --help
```

```console
Command Line Interface to MTPIO Client
Usage: clmtp [OPTIONS] SUBCOMMAND

Options:
  -h,--help                   Print this help message and exit
  -u,--url TEXT=http://127.0.0.1:8888/
                              the http/https URL where nodmtp is running
  --wallet-url TEXT=unix:///Users/username/mtpio-wallet/kmtpd.sock
                              the http/https URL where kmtpd is running
  -r,--header                 pass specific HTTP header; repeat this option to pass multiple headers
  -n,--no-verify              don't verify peer certificate when using HTTPS
  --no-auto-kmtpd             don't automatically launch a kmtpd if one is not currently running
  -v,--verbose                output verbose errors and action console output
  --print-request             print HTTP request to STDERR
  --print-response            print HTTP response to STDERR

Subcommands:
  version                     Retrieve version information
  create                      Create various items, on and off the blockchain
  convert                     Pack and unpack transactions
  get                         Retrieve various items and information from the blockchain
  set                         Set or update blockchain state
  transfer                    Transfer tokens from account to account
  net                         Interact with local p2p network connections
  wallet                      Interact with local wallet
  sign                        Sign a transaction
  push                        Push arbitrary transactions to the blockchain
  multisig                    Multisig contract commands
  wrap                        Wrap contract commands
  system                      Send mtpio.system contract action to the blockchain.
```

### Clmtp Subcommands

To get help with any particular subcommand, run `clmtp SUBCOMMAND --help`. For instance:

```sh
clmtp create --help
```

```console
Create various items, on and off the blockchain
Usage: clmtp create SUBCOMMAND

Subcommands:
  key                         Create a new keypair and print the public and private keys
  account                     Create a new account on the blockchain
                              (assumes system contract does not restrict RAM usage)
```

`clmtp` can also provide usage help for subcommands within subcommands. For instance:

```sh
clmtp create account --help
```

```console
Create a new account on the blockchain (assumes system contract does not restrict RAM usage)
Usage: clmtp create account [OPTIONS] creator name OwnerKey [ActiveKey]

Positionals:
  creator TEXT                The name of the account creating the new account (required)
  name TEXT                   The name of the new account (required)
  OwnerKey TEXT               The owner public key or permission level for the new account (required)
  ActiveKey TEXT              The active public key or permission level for the new account

Options:
  -h,--help                   Print this help message and exit
  -x,--expiration             set the time in seconds before a transaction expires, defaults to 30s
  -f,--force-unique           force the transaction to be unique. this will consume extra bandwidth and remove any protections against accidently issuing the same transaction multiple times
  -s,--skip-sign              Specify if unlocked wallet keys should be used to sign transaction
  -j,--json                   print result as json
  --json-file TEXT            save result in json format into a file
  -d,--dont-broadcast         don't broadcast transaction to the network (just print to stdout)
  --return-packed             used in conjunction with --dont-broadcast to get the packed transaction
  -r,--ref-block TEXT         set the reference block num or block id used for TAPOS (Transaction as Proof-of-Stake)
  --use-old-rpc               use old RPC push_transaction, rather than new RPC send_transaction
  -p,--permission TEXT ...    An account and permission level to authorize, as in 'account@permission' (defaults to 'creator@active')
  --max-cpu-usage-ms UINT     set an upper limit on the milliseconds of cpu usage budget, for the execution of the transaction (defaults to 0 which means no limit)
  --max-net-usage UINT        set an upper limit on the net usage budget, in bytes, for the transaction (defaults to 0 which means no limit)
  --delay-sec UINT            set the delay_sec seconds, defaults to 0s
```

## Clmtp Example

The following `clmtp` command creates a local wallet named `mywallet` and displays the password to the screen:

```sh
clmtp wallet create -n mywallet --to-console
```

```console
Creating wallet: mywallet
Save password to use in the future to unlock this wallet.
Without password imported keys will not be retrievable.
"PW5JbF34UdA193Eps1bjrWVJRaNMt1VKddLn4Dx6SPVTfMDRnMBWN"
```
