# NI Device gRPC Server and Client APIs

This repo contains the source code needed to build and run the NI gRPC Device Server for supported NI hardware driver APIs. Also contained in this repo are instructions and examples that demonstrate how to create client code that interacts with devices connected to an instance of the NI gRPC Device Server.

The server and the client APIs allow NI's instrumentation to be accessed and controlled through a remote interface via pre-defined APIs using a client/server architecture. The API is not a driver but instead a layer on top of the existing driver C APIs that provides remote capabilities.

For more detailed information on the server and API design refer to the [wiki](https://github.com/ni/grpc-device/wiki).

## Build Status
![Linux Build](https://github.com/ni/grpc-device/workflows/Build%20Matrix/badge.svg)
![NI Linux Real-Time Build](https://github.com/ni/grpc-device/workflows/NI%20Linux%20Real-Time%20Build/badge.svg)

## Downloading a Release

### Download the Server
1. (Windows Only) Download and install the latest [Microsoft Visual C++ Redistributable for Visual Studio 2015, 2017 and 2019](https://support.microsoft.com/en-us/topic/the-latest-supported-visual-c-downloads-2647da03-1eea-4433-9aff-95f26a218cc0).
2. Navigate to the [Releases](https://github.com/ni/grpc-device/releases) page.
3. Download the latest Server Release `.tar.gz` or `.zip` for the desired platform.
4. Extract the contents of the `.tar.gz` or `.zip` to a directory with read and write permissions.
5. [Run the server](#running-the-grpc-server)
* **List of supported OS:**
  - Windows 64-bit
  - Linux 64-bit
  - NI Linux RT

### Download the Client Files
1. Navigate to the [Releases](https://github.com/ni/grpc-device/releases) page.
2. Download the latest Client Release's `ni-grpc-device-client.tar.gz` or `ni-grpc-device-client.zip` depending on the client platform.
3. Extract the contents of `ni-grpc-device-client.tar.gz` or `ni-grpc-device-client.zip` to a directory with read and write permissions.
4. [Create a gRPC client](#creating-a-grpc-client).

## Building on Windows 64-bit

### Prerequisites
To prepare for cmake + Microsoft Visual C++ compiler build
- Install Visual Studio 2015, 2017, or 2019 (Visual C++ compiler will be used).
- Install [Git](https://git-scm.com/).
- Install [CMake](https://cmake.org/download/) 3.12.0 or newer and add it to the PATH.
- Install [Python](https://www.python.org/downloads/) and add it to the PATH.
- Install [mako](https://www.makotemplates.org/download.html)

Launch "x64 Native Tools Command Prompt for Visual Studio" and change to a directory where you have write permissions. Alternatively, use Windows PowerShell in a directory where you have write permissions.

### Clone Repo

Clone the repo and update submodules, this will pull the gRPC components and all dependencies

```
> git clone https://github.com/ni/grpc-device.git
> cd grpc-device
> git submodule update --init --recursive
```

### Build Debug

Build a debug build if debugging symbols are required during development:

```
> mkdir build
> cd build
> cmake .. -A x64
> cmake --build .
```

### Build Release

Build a release build for use in a production environment:

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
> git clone https://github.com/ni/grpc-device.git grpc-device
> cd grpc-device
> git submodule update --init --recursive
```

### Build Debug

Build a debug build if debugging symbols are required during development:

```
> mkdir -p cmake/build
> cd cmake/build
> cmake ../..
> make
```

### Build Release

Build a release build for use in a production environment:

```
> mkdir -p cmake/build
> cd cmake/build
> cmake -DCMAKE_BUILD_TYPE=Release ../..
> make
```
## Running the gRPC Server

The server's startup configuration is set by specifying port and security settings in a JSON configuration file. A default configuration file named `server_config.json` with an insecure configuration (no SSL/TLS) is located in the same directory as the server executable. For more information on SSL/TLS related security settings refer to the [SSL/TLS Support section](#ssltls-support). The location of the server binary is not important as long as the user has proper permissions in the chosen directory.

There are two ways to start the server:

1. Launch the server application without specifying a path to a configuration file (use the default configuration file):

    **Windows**
    
    `.\ni_grpc_device_server.exe`
    
   **Note:** It is also possible to start the server by double-clicking the executable. Starting the server through a command prompt, however, allows for observation of [startup errors](#common-server-startup-errors).
   
    **Linux and Linux RT**
    
    `./ni_grpc_device_server`

2. Launch the server application by specifying a path (relative or absolute) to the configuration file:

    **Windows**
    
    `.\ni_grpc_device_server.exe C:\path\to\config\file\server_config.json`

    **Linux and Linux RT**
    
    `./ni_grpc_device_server /path/to/config/file/server_config.json`


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
6. Security configuration errors. See [Server Security Support wiki page](https://github.com/ni/grpc-device/wiki/Server-Security-Support).

### Default Configuration File (insecure):

Below are the contents of a default configuration file using port `31763` and configured without SSL/TLS.  A configuration file with these contents also exists in the same directory as the `ni_grpc_device_server` binary.

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

The server supports both server-side TLS and mutual TLS. Security configuration is accomplished by setting the `server_cert`, `server_key` and `root_cert` values in the server's configuration file. The server expects the certificate files specified in the configuration file to exist in a `certs` folder that is located in the same directory as the configuration file being used by the server. For more detailed information on SSL/TLS support refer to the [Server Security Support wiki page](https://github.com/ni/grpc-device/wiki/Server-Security-Support).
