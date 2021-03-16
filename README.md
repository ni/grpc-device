# NI Device gRPC Server and Client APIs

This repo contains the C++ code and `.proto` files needed to build and run the NI gRPC Device Server for supported NI hardware driver APIs. Also contained in this repo are instructions and examples wirtten in Python that demonstrate how to create client code that interacts with devices connected to an instance of the NI gRPC Device Server.

The server and the corresponding client API allows NI's instrumentation to be accessed and controlled through a remote interface via pre-defined APIs in a holistic and OS agnostic way using a client/server architecture. The API is not a driver but instead a layer on top of the existing driver C APIs that provides remote capabilities.

For more detailed information on the server and API design refer to the [wiki](https://github.com/ni/grpc-device/wiki).

## Build Status
![Linux Build](https://github.com/ni/ni-driver-apis-grpc/workflows/Build%20Matrix/badge.svg)
![NI Linux Real-Time Build](https://github.com/ni/ni-driver-apis-grpc/workflows/NI%20Linux%20Real-Time%20Build/badge.svg)

## Building on Windows 64-bit

### Prerequisites
To prepare for cmake + Microsoft Visual C++ compiler build
- Install Visual Studio 2015, 2017, or 2019 (Visual C++ compiler will be used).
- Install [Git](https://git-scm.com/).
- Install [CMake](https://cmake.org/download/) 3.12.0 or newer.
- Install [Python](https://www.python.org/downloads/).
- Install [mako](https://www.makotemplates.org/download.html)

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
> cmake .. -A x64
> cmake --build .
```

### Build Release
```
> mkdir build
> cd build
> cmake .. -A x64
> cmake --build . --config Release
```

## Building on Linux

### Prerequisites

For Debian/Ubuntu, install git, cmake (3.12.0 or newer), and mako:
```
> sudo apt-get update
> sudo apt-get install git
> sudo apt-get install cmake
> python -m pip install mako
```

For NI Linux RT, install git, git-perltools, cmake (3.12.0 or newer), python3-utils, and mako:
```
> opkg update
> opkg install git
> opkg install git-perltools
> opkg install cmake
> opkg install python3-misc
# follow the latest instructions to install pip:
# https://pip.pypa.io/en/stable/installing/
> python -m pip install mako
```

**Note**: Depending on the version of NI Linux RT, installing a newer version of CMake
may be required. Follow the instructions to [install CMake](https://cmake.org/install/).
If this is required, make sure to install openssl-dev as well.
```
> opkg install openssl-dev
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

The server's startup configuration is set by specifying port and security settings in a JSON configuration file. A default configuration file named `server_config.json` with an insecure configuration (no SSL/TLS) is located in the same directory as the server executable. For more information on SSL/TLS related security settings refer to the [SSL/TLS Support section](#ssltls-support).

There are two ways to start the server:

1. Launch the server application without specifying a path to a configuration file (use the default configuration file):

    **Windows**
    
    `.\core_server.exe`

    **Linux**
    
    `./core_server`

2. Launch the server application by specifying a path (relative or absolute) to the configuration file:

    **Windows**
    
    `.\core_server.exe C:\path\to\config\file\server_config.json`

    **Linux**
    
    `./core_server /path/to/config/file/server_config.json`


If the server starts successfully on the port specified in the configuration file, then it will print a message to the terminal output:

```
Server listening on port 12345. Security is configured with insecure credentials.
```

**Note:** If port `0` is specified then the server will automatically select a port from the dynamic range. The port used will be reflected in the startup message.

If the server fails to start (i.e. a port is not specified in the configuration file) then an error message is printed in the terminal and the application will exit.

### Common Server Startup Errors

1. The datatypes of the values in the configuration file don't match the expected datatypes. For example, the port must be an integer type and not a string. The error message will provide specific details on the type requirements.
2. The configuration file can't be found at the provided location. This error can also occur if the user lacks read permissions for the file.
3. The server configuration file is malformed and is not in proper JSON format. Refer to the JSON configuration file in this readme for an example of the expected format.
4. The specified port is out of the allowed port range. The solution is to select a port in the allowable range (0-65535).
5. The specified port is already in use. The solution is to select another port or terminate the other application using the port.
6. Security configuration errors. See [Server SSL TLS Support wiki page](https://github.com/ni/ni-driver-apis-grpc/wiki/Server-SSL-TLS-Support).

### Default Configuration File (insecure):

```json
{
   "port": 31763,
   "security" : {
      "server_cert": "",
      "server_key": "",
      "root_cert": ""
   }
}
```

## Creating a gRPC Client

Each supported driver API has a corresponding `.proto` file that defines the interface used by clients to interact with the NI devices connected to the server. Creating a client requires compiling the `.proto` into supporting files in the client's language of choice using the protocol buffer compiler `protoc`. For more detailed information refer to the [Creating a gRPC Client wiki page](https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client).

## SSL/TLS Support

The server supports both server-side TLS and mutual TLS. Security configuration is accomplished by setting the `server_cert`, `server_key` and `root_cert` values in the server's configuration file. The server expects the certificate files specified in the configuration file to exist in a `certs` folder that is located in the same directory as the configuration file being used by the server. For more detailed information on SSL/TLS support refer to the [Server SSL TLS Support wiki page](https://github.com/ni/ni-driver-apis-grpc/wiki/Server-SSL-TLS-Support).
