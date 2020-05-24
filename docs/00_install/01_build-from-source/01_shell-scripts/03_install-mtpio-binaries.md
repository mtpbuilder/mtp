---
content_title: Install MTPIO Binaries
---

## MTPIO install script

For ease of contract development, content can be installed at the `/usr/local` folder using the `mtpio_install.sh` script within the `mtp/scripts` folder. Adequate permission is required to install on system folders:

```sh
cd ~/mtpio/mtp
sudo ./scripts/mtpio_install.sh
```

## MTPIO manual install

In lieu of the `mtpio_install.sh` script, you can install the MTPIO binaries directly by invoking `make install` within the `mtp/build` folder. Again, adequate permission is required to install on system folders:

```sh
cd ~/mtpio/mtp/build
sudo make install
```

[[info | What's Next?]]
| Configure and use [Nodmtp](../../../01_nodmtp/index.md), or optionally [Test the MTPIO binaries](04_test-mtpio-binaries.md).
