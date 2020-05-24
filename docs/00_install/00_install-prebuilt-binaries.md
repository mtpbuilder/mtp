---
content_title: Install Prebuilt Binaries
---

[[info | Previous Builds]]
| If you have previously installed MTPIO from source using shell scripts, you must first run the [Uninstall Script](01_build-from-source/01_shell-scripts/05_uninstall-mtpio.md) before installing any prebuilt binaries on the same OS.

## Prebuilt Binaries

Prebuilt MTPIO software packages are available for the operating systems below. Find and follow the instructions for your OS:

### Mac OS X:

#### Mac OS X Brew Install
```sh
brew tap mtpio/mtpio
brew install mtpio
```
#### Mac OS X Brew Uninstall
```sh
brew remove mtpio
```

### Ubuntu Linux:

#### Ubuntu 18.04 Package Install
```sh
wget https://github.com/mtpio/mtp/releases/download/v2.0.5/mtpio_2.0.5-1-ubuntu-18.04_amd64.deb
sudo apt install ./mtpio_2.0.5-1-ubuntu-18.04_amd64.deb
```
#### Ubuntu 16.04 Package Install
```sh
wget https://github.com/mtpio/mtp/releases/download/v2.0.5/mtpio_2.0.5-1-ubuntu-16.04_amd64.deb
sudo apt install ./mtpio_2.0.5-1-ubuntu-16.04_amd64.deb
```
#### Ubuntu Package Uninstall
```sh
sudo apt remove mtpio
```

### RPM-based (CentOS, Amazon Linux, etc.):

#### RPM Package Install
```sh
wget https://github.com/mtpio/mtp/releases/download/v2.0.5/mtpio-2.0.5-1.el7.x86_64.rpm
sudo yum install ./mtpio-2.0.5-1.el7.x86_64.rpm
```
#### RPM Package Uninstall
```sh
sudo yum remove mtpio
```

## Location of MTPIO binaries

After installing the prebuilt packages, the actual MTPIO binaries will be located under:
* `/usr/opt/mtpio/<version-string>/bin` (Linux-based); or
* `/usr/local/Cellar/mtpio/<version-string>/bin` (MacOS)

where `version-string` is the MTPIO version that was installed.

Also, soft links for each MTPIO program (`nodmtp`, `clmtp`, `kmtpd`, etc.) will be created under `usr/bin` or `usr/local/bin` to allow them to be executed from any directory.

## Previous Versions

To install previous versions of the MTPIO prebuilt binaries:

1. Browse to https://github.com/MTPIO/mtp/tags and select the actual version of the MTPIO software you need to install.

2. Scroll down past the `Release Notes` and download the package or archive that you need for your OS.

3. Follow the instructions on the first paragraph above to install the selected prebuilt binaries on the given OS.
