# gRPC Support for NI Hardware Driver APIs

This repo contains necessary C++ code and .proto files needed to build a gRPC server for NI hardware driver APIs.

## Build Status
![Linux Build](https://github.com/ni/ni-driver-apis-grpc/workflows/Build%20Matrix/badge.svg)
![NI Linux Real-Time Build](https://github.com/ni/ni-driver-apis-grpc/workflows/NI%20Linux%20Real-Time%20Build/badge.svg)

## Note: This project is not yet complete
* The gRPC server is not yet complete.
* Testing on Linux not yet implemented.
* SSL/TLS support not yet implemented.
* Support for specific NI driver APIs not yet added.

## Building on Windows 64-bit

### Prerequisites
To prepare for cmake + Microsoft Visual C++ compiler build
- Install Visual Studio 2015, 2017, or 2019 (Visual C++ compiler will be used).
- Install [Git](https://git-scm.com/).
- Install [CMake](https://cmake.org/download/).

Launch "x64 Native Tools Command Prompt for Visual Studio"

### Clone Repo

Clone the repo and update submodules, this will pull the gRPC components and all dependencies

```
> git clone https://github.com/ni/ni-driver-apis-grpc.git
> cd ni-driver-apis-grpc
> git submodule update --init --recursive
```

### Build Debug
```
> mkdir build
> cd build
> cmake ..
> cmake --build .
```

### Build Release
```
> mkdir build
> cd build
> cmake ..
> cmake --build . --config Release
```

## Building on Linux

### Prerequisites

For Debian/Ubuntu, install git and cmake:
```
> sudo apt-get update
> sudo apt-get install git
> sudo apt-get install cmake
```

For NI Linux RT, install git, git-perltools, and cmake:
```
> opkg update
> opkg install git
> opkg install git-perltools
> opkg install cmake
```

### Clone Repo

Clone the repo and update submodules, this will pull the gRPC components and all dependencies

```
> git clone https://github.com/ni/ni-driver-apis-grpc.git ni-driver-apis-grpc
> cd ni-driver-apis-grpc
> git submodule update --init --recursive
```

### Build Debug

```
> mkdir -p cmake/build
> cd cmake/build
> cmake ../..
> make
```

### Build Release

```
> mkdir -p cmake/build
> cd cmake/build
> cmake -DCMAKE_BUILD_TYPE=Release ../..
> make
```

## Running the gRPC Server

Coming Soon

## Creating a gRPC Client

Coming Soon

## SSL/TLS Support

Coming Soon
