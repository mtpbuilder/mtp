## Description
Retrieve accounts which are servants of a given account 

## Info

**Command**

```sh
clmtp get servants
```
**Output**

```console
Usage: clmtp get servants account

Positionals:
  account TEXT                The name of the controlling account
```

## Command

```sh
clmtp get servants inita
```

## Output

```json
{
  "controlled_accounts": [
    "tester"
  ]
}
```
