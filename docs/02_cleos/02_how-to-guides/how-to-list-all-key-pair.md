## Goal

List all key pairs

## Before you begin

* Install the currently supported version of `clmtp`

* Understand the following:
  * What is a public and private key pair

## Steps

Unlock your wallet

```sh
clmtp wallet unlock
```

List all public keys:

```sh
clmtp wallet keys
```

List all private keys:

```sh
clmtp wallet private_keys

```

[[warning]]
| Be careful never real your private keys in a production enviroment
