---
content_title: Uninstall MTPIO
---

If you have previously built MTPIO from source and now wish to install the prebuilt binaries, or to build from source again, it is recommended to run the `mtpio_uninstall.sh` script within the `mtp/scripts` folder:

```sh
cd ~/mtpio/mtp
sudo ./scripts/mtpio_uninstall.sh
```

[[info | Uninstall Dependencies]]
| The uninstall script will also prompt the user to uninstall MTPIO dependencies. This is recommended if installing prebuilt MTPIO binaries or building MTPIO for the first time.
