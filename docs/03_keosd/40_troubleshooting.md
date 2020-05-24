---
content_title: Kmtpd Troubleshooting
---

## How to solve the error "Failed to lock access to wallet directory; is another `kmtpd` running"?

Since `clmtp` may auto-launch an instance of `kmtpd`, it is possible to end up with multiple instances of `kmtpd` running. That can cause unexpected behavior or the error message above.

To fix this issue, you can terminate all running `kmtpd` instances and restart `kmtpd`. The following command will find and terminate all instances of `kmtpd` running on the system:

```sh
pkill kmtpd
```
