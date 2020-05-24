---
content_title: MTPIO Software Dependencies
---

The MTPIO software requires specific software dependencies to build the MTPIO binaries. These dependencies can be built from source or installed from binaries directly. Dependencies can be pinned to a specific version release or unpinned to the current version, usually the latest one. The main MTPIO dependencies hosted outside the MTPIO repos are:

* Clang - the C++17 compliant compiler used by MTPIO
* CMake - the build system used by MTPIO
* Boost - the C++ Boost library used by MTPIO
* OpenSSL - the secure communications (and crypto) library
* LLVM - the LLVM compiler/toolchain infrastructure

Other dependencies are either inside the MTPIO repo, such as the `secp256k1` elliptic curve DSA library, or they are otherwise used for testing or housekeeping purposes, such as:

* automake, autoconf, autotools
* doxygen, graphviz
* python2, python3
* bzip2, zlib
* etc.

## Pinned Dependencies

To guarantee interoperability across different MTPIO software releases, developers may opt to reproduce the exact "pinned" dependency binaries used in-house. Block producers may want to install and run the MTPIO software built with these pinned dependencies for portability and stability reasons. Pinned dependencies are usually built from source.

## Unpinned Dependencies

Regular users or application developers may prefer installing unpinned versions of the MTPIO dependencies. These correspond to the latest or otherwise stable versions of the dependencies. The main advantage of unpinned dependencies is reduced installation times and perhaps better performance. Pinned dependencies are typically installed from binaries.

## Automatic Installation of Dependencies

MTPIO dependencies can be built or installed automatically from the [Build Script](../01_shell-scripts/02_build-mtpio-binaries.md) when building MTPIO from source. To build the pinned dependencies, the optional `-P` parameter can be specified when invoking the script. Otherwise, the unpinned dependencies will be installed instead, with the exception of `boost` and `cmake` which are always pinned:

```sh
cd ~/mtpio/mtp
./scripts/mtpio_build.sh [-P]
```

### Unupported Platforms

MTPIO dependencies can also be built and installed manually by reproducing the same commands invoked by the [Build Script](../01_shell-scripts/02_build-mtpio-binaries.md). The actual commands can be generated from the script directly by exporting specific environment variables and CLI parameters to the script when invoked:

```sh
cd ~/mtpio/mtp
export VERBOSE=true && export DRYRUN=true && ./scripts/mtpio_build.sh -y [-P]
```
