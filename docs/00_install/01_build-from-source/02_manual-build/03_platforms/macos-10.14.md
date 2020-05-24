---
content_title: MacOS 10.14
---

This section contains shell commands to manually download, build, install, test, and uninstall MTPIO and dependencies on MacOS 10.14.

[[info | Building MTPIO is for Advanced Developers]]
| If you are new to MTPIO, it is recommended that you install the [MTPIO Prebuilt Binaries](../../../00_install-prebuilt-binaries.md) instead of building from source.

Select a task below, then copy/paste the shell commands to a Unix terminal to execute:

* [Download MTPIO Repository](#download-mtpio-repository)
* [Install MTPIO Dependencies](#install-mtpio-dependencies)
* [Build MTPIO](#build-mtpio)
* [Install MTPIO](#install-mtpio)
* [Test MTPIO](#test-mtpio)
* [Uninstall MTPIO](#uninstall-mtpio)

[[info | Building MTPIO on another OS?]]
| Visit the [Build MTPIO from Source](../../index.md) section.

## Download MTPIO Repository
These commands set the MTPIO directories, install git, and clone the MTPIO repository.
```sh
# set MTPIO directories
export MTPIO_LOCATION=~/mtpio/mtp
export MTPIO_INSTALL_LOCATION=$MTPIO_LOCATION/../install
mkdir -p $MTPIO_INSTALL_LOCATION
# install git
brew update && brew install git
# clone MTPIO repository
git clone https://github.com/MTPIO/mtp.git $MTPIO_LOCATION
cd $MTPIO_LOCATION && git submodule update --init --recursive
```

## Install Dependencies
These commands install the MTPIO software dependencies. Make sure to [Download the MTPIO Repository](#download-mtpio-repository) first and set the MTPIO directories.
```sh
# install dependencies
brew install cmake python libtool libusb graphviz automake wget gmp pkgconfig doxygen openssl@1.1 jq boost || :
export PATH=$MTPIO_INSTALL_LOCATION/bin:$PATH
# install mongodb
mkdir -p $MTPIO_INSTALL_LOCATION/bin
cd $MTPIO_INSTALL_LOCATION && curl -OL https://fastdl.mongodb.org/osx/mongodb-osx-ssl-x86_64-3.6.3.tgz
    tar -xzf mongodb-osx-ssl-x86_64-3.6.3.tgz && rm -f mongodb-osx-ssl-x86_64-3.6.3.tgz && \
    mv $MTPIO_INSTALL_LOCATION/mongodb-osx-x86_64-3.6.3/bin/* $MTPIO_INSTALL_LOCATION/bin/ && \
    rm -rf $MTPIO_INSTALL_LOCATION/mongodb-osx-x86_64-3.6.3 && rm -rf $MTPIO_INSTALL_LOCATION/mongodb-osx-ssl-x86_64-3.6.3.tgz
# install mongo-c-driver from source
cd $MTPIO_INSTALL_LOCATION && curl -LO https://github.com/mongodb/mongo-c-driver/releases/download/1.13.0/mongo-c-driver-1.13.0.tar.gz && \
    tar -xzf mongo-c-driver-1.13.0.tar.gz && cd mongo-c-driver-1.13.0 && \
    mkdir -p cmake-build && cd cmake-build && \
    cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$MTPIO_INSTALL_LOCATION -DENABLE_BSON=ON -DENABLE_SSL=DARWIN -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF -DENABLE_STATIC=ON -DENABLE_ICU=OFF -DENABLE_SASL=OFF -DENABLE_SNAPPY=OFF .. && \
    make -j $(getconf _NPROCESSORS_ONLN) && \
    make install && \
    rm -rf $MTPIO_INSTALL_LOCATION/mongo-c-driver-1.13.0.tar.gz $MTPIO_INSTALL_LOCATION/mongo-c-driver-1.13.0
# install mongo-cxx-driver from source
cd $MTPIO_INSTALL_LOCATION && curl -L https://github.com/mongodb/mongo-cxx-driver/archive/r3.4.0.tar.gz -o mongo-cxx-driver-r3.4.0.tar.gz && \
    tar -xzf mongo-cxx-driver-r3.4.0.tar.gz && cd mongo-cxx-driver-r3.4.0/build && \
    cmake -DBUILD_SHARED_LIBS=OFF -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$MTPIO_INSTALL_LOCATION .. && \
    make -j $(getconf _NPROCESSORS_ONLN) VERBOSE=1 && \
    make install && \
    rm -rf $MTPIO_INSTALL_LOCATION/mongo-cxx-driver-r3.4.0.tar.gz $MTPIO_INSTALL_LOCATION/mongo-cxx-driver-r3.4.0
```

## Build MTPIO
These commands build the MTPIO software on the specified OS. Make sure to [Install MTPIO Dependencies](#install-mtpio-dependencies) first.

[[caution | `MTPIO_BUILD_LOCATION` environment variable]]
| Do NOT change this variable. It is set for convenience only. It should always be set to the `build` folder within the cloned repository.

```sh
export MTPIO_BUILD_LOCATION=$MTPIO_LOCATION/build
mkdir -p $MTPIO_BUILD_LOCATION
cd $MTPIO_BUILD_LOCATION && cmake -DCMAKE_BUILD_TYPE='Release' -DCMAKE_INSTALL_PREFIX=$MTPIO_INSTALL_LOCATION -DBUILD_MONGO_DB_PLUGIN=true $MTPIO_LOCATION
cd $MTPIO_BUILD_LOCATION && make -j$(getconf _NPROCESSORS_ONLN)
```

## Install MTPIO
This command installs the MTPIO software on the specified OS. Make sure to [Build MTPIO](#build-mtpio) first.
```sh
cd $MTPIO_BUILD_LOCATION && make install
```

## Test MTPIO
These commands validate the MTPIO software installation on the specified OS. This task is optional but recommended. Make sure to [Install MTPIO](#install-mtpio) first.
```sh
$MTPIO_INSTALL_LOCATION/bin/mongod --fork --logpath $(pwd)/mongod.log --dbpath $(pwd)/mongodata
cd $MTPIO_BUILD_LOCATION && make test
```

## Uninstall MTPIO
These commands uninstall the MTPIO software from the specified OS.
```sh
xargs rm < $MTPIO_BUILD_LOCATION/install_manifest.txt
rm -rf $MTPIO_BUILD_LOCATION
```
