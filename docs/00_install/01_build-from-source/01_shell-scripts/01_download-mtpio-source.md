---
content_title: Download MTPIO Source
---

To download the MTPIO source code, clone the `mtp` repo and its submodules. It is adviced to create a home `mtpio` folder first and download all the MTPIO related software there:

```sh
mkdir -p ~/mtpio && cd ~/mtpio
git clone --recursive https://github.com/MTPIO/mtp
```

## Update Submodules

If a repository is cloned without the `--recursive` flag, the submodules *must* be updated before starting the build process:

```sh
cd ~/mtpio/mtp
git submodule update --init --recursive
```

## Pull Changes

When pulling changes, especially after switching branches, the submodules *must* also be updated. This can be achieved with the `git submodule` command as above, or using `git pull` directly:

```sh
[git checkout <branch>]  (optional)
git pull --recurse-submodules
```

[[info | What's Next?]]
| [Build MTPIO binaries](02_build-mtpio-binaries.md)
