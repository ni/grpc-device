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
- Install [Python](https://www.python.org/downloads/).

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

## C++ Coding Conventions

This project follows the Google style guidelines for all C++ and protobuf files with the exceptions documented below.

The C++ style is encoded in the `clang-format` file at the root of the repository.<br>
See https://clang.llvm.org/docs/ClangFormatStyleOptions.html

Setting | Google | Ours | Justification
--|--|--|--
`ColumnLimit` | `80` | `0` | Some times a long line is appropriate. We should police that in PRs, not with our tooling.
`AlignAfterOpenBracket` | `Align` | `AlwaysBreak` | Either all parameters should be on one line or all of them on separate lines. Without this the formatter would allow you to leave parameters on the first line and would align the other lines with the first parameter. This adds a lot of whitespace.
`BreakBeforeBraces` | `Attach` | `Stroustrup` | This puts function curly braces on the next line and puts `else` blocks on the next line. This helps with control flow readability.
`DerivePointerAlignment` | `true` | `false` | We should be consistent with our pointer alignment. Left alignment (`void* foo`) is more standard than right (`void *foo`) and is the default Google style.
`IndentPPDirectives` | `None` | `BeforeHash` | Indented `#include` directives inside `#defined` blocks improves readability.

## Running the gRPC Server

Coming Soon

## Creating a gRPC Client

Coming Soon

## SSL/TLS Support

Coming Soon
