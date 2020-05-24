---
content_title: Build MTPIO Binaries
---

[[info | Shell Scripts]]
| The build script is one of various automated shell scripts provided in the MTPIO repository for building, installing, and optionally uninstalling the MTPIO software and its dependencies. They are available in the `mtp/scripts` folder.

The build script first installs all dependencies and then builds MTPIO. The script supports these [Operating Systems](../../index.md#supported-operating-systems). To run it, first change to the `~/mtpio/mtp` folder, then launch the script:

```sh
cd ~/mtpio/mtp
./scripts/mtpio_build.sh
```

The build process writes temporary content to the `mtp/build` folder. After building, the program binaries can be found at `mtp/build/programs`.

[[info | What's Next?]]
| [Installing MTPIO](03_install-mtpio-binaries.md) is strongly recommended after building from source as it makes local development significantly more friendly.
