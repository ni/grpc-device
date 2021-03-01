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

The server's startup configuration is set by specifying port and security settings in a JSON configuration file. A default configuration file named `server_config.json` with an insecure configuration (no SSL/TLS) is located in the same directory as the server executable. For more information on SSL/TLS related security settings refer to the [SSL/TLS Support](## SSL/TLS Support) section below.

There are two ways to start the server:

1. Launch the server application without specifying a path to a configuration file (use the default configuration file):

### Windows
`.\core_server.exe`

### Linux
`./core_server`

2. Launch the server application by specifying a path (relative or absolute) to the configuration file:

### Windows
`.\core_server.exe C:\path\to\config\file\server_config.json`

### Linux
`./core_server \path\to\config\file\server_config.json`


If the server starts successfully and registers on the port specified in the configuration file then it will print a message indicating that to the terminal output:

```
Server listening on port 50051. Security is configured with insecure credentials.
```

**Note:** If port `0 `is specified then the server will automatically select a port from the dynamic range. The port used will be reflected in the message above.

If the server fails to start (i.e. a port is not specified in the configuration file) then an error message is printed in the terminal and the application will exit.

### Common Server Startup Errors

1. The datatypes of the values in the configuration file don't match the expected datatypes. For example, the port must be an integer type and not a string. The error message will provide specific details on the type requirements.
2. The configuration file can't be found at the provided location. This error can also occur if the user lacks read permissions for the file.
3. The server configuration file is malformed and is not in proper JSON format. Refer to JSON configuration files in this readme for example of the expected format.
4. The specified port is out of the allowed port range. The solution is to select a port in the allowable range (0-65535).
5. The specified port is already in use. The solution is to select another port or terminate the other application using the port.
6. Security configuration errors. See [SSL/TLS Support](## SSL/TLS Support) section below.

### Default Configuration File (insecure):

```
{
   "port": 50051,
   "security" : {
      "server_cert": "",
      "server_key": "",
      "root_cert": ""
   }
}
```

## Creating a gRPC Client

Coming Soon

## SSL/TLS Support

The server supports both server-side TLS and mutual TLS. Security configuration is accomplished by setting the `server_cert`, `server_key` and `root_cert` values in the server's configuration file. The server expects the certificate files specified in the configuration file to exist in a `certs` folder that is located in the same directory as the configuration file being used by the server.

In the default case the server expects the `certs` folder to be located in the same folder as the server executable itself:

```
<installation directory>
|
--> core_server
--> server_config.json
--> certs/
   |
   --> certfile1.pem
   --> certfile2.pem
   --> certfile3.pem
```

If a path to the configuration file is specified when starting the server then the `certs` folder must be located in the same location as the specified configuration file:

```
<installation directory>
|
--> core_server

<path specified to config file>
|
--> server_config.json
--> certs/
   |
   --> certfile1.pem
   --> certfile2.pem
   --> certfile3.pem
```
   
1. When none of the security-related configuration values are set then the server defaults to an insecure (no SSL/TLS) configuration. Additionally, if one of the `server_cert` or `server_key` values is set but not the other then the server will also default to an insecure configuration. Specifying one of the two is considered an incomplete configuration.
2. To configure the server for server-side TLS then set both the `server_cert` and `server_key` values. In this configuration only the identity of the server is verified:

```
{
   "port": 50051,
   "security" : {
      "server_cert": "server_self_signed_crt.pem",
      "server_key": "server_privatekey.pem",
      "root_cert": ""
   }
}
```
3. To configure the server for mutual TLS then set the `server_cert`, `server_key` and `root_cert` values. This configuration verifies the identity of the client in addition to the identity of the server. When the `root_cert` is specified the server always requests a client certificate:

```
{
   "port": 50051,
   "security" : {
      "server_cert": "server_self_signed_crt.pem",
      "server_key": "server_privatekey.pem",
      "root_cert": "client_self_signed_crt.pem"
   }
}
```

**Note: ** The server's configuration (insecure, server-side TLS or mutual TLS) will always be printed to the terminal when the server starts.

### Creating Certificates

A detailed explanation of security considerations is outside of the scope of this document. To read more about SSL/TLS in gRPC refer to [this document](https://grpc.io/docs/guides/auth/).

There are many tools available to produce certificate files for SSL/TLS. One such tool is `openssl` and below is a simple example that creates self-signed server and client certificates:

```
openssl genrsa -passout pass:1111 -des3 -out ca.key 2048

openssl req -passin pass:1111 -new -x509 -days 3650 -key ca.key -out ca.crt -subj "/C=US/ST=Texas/L=Austin/O=NI/OU=R&D/CN=MachineName"
 
openssl genrsa -passout pass:1111 -des3 -out server_privatekey.pem 2048
 
openssl req -passin pass:1111 -new -key server_privatekey.pem -out server_csr.pem -subj "/C=US/ST=Texas/L=Austin/O=NI/OU=R&D/CN=MachineName"
 
openssl x509 -req -passin pass:1111 -days 3650 -in server_csr.pem -CA ca.crt -CAkey ca.key -CAcreateserial -out server_self_signed_crt.pem
 
openssl rsa -passin pass:1111 -in server_privatekey.pem -out server_privatekey.pem
 
openssl genrsa -passout pass:1111 -des3 -out client_privatekey.pem 2048
 
openssl req -passin pass:1111 -new -key client_privatekey.pem -out client_csr.pem -subj "/C=US/ST=Texas/L=Austin/O=NI/OU=R&D/CN=MachineName"
 
openssl x509 -passin pass:1111 -req -days 3650 -in client_csr.pem -CA ca.crt -CAkey ca.key -CAcreateserial -out client_self_signed_crt.pem
 
openssl rsa -passin pass:1111 -in client_privatekey.pem -out client_privatekey.pem
```

### Configuring the Client (Python Example)

The examples below make use of the certificates generated in the section above. Your specific configuration (i.e. the certificate files you use) will be dependent on how you generate the certificate files.

1. To establish a connection to an insecure server then call the `insecure_channel(..)` method:

```
channel = grpc.insecure_channel(serverAddress)
```

2. To establish a connection to a server configured for server-side TLS then call the `secure_channel(..)` method and set `root_certificates` to point to the server's self-signed certificate:

```
ca_cert = open('server_self_signed_crt.pem', 'rb').read()
creds = grpc.ssl_channel_credentials(root_certificates=ca_cert)
channel = grpc.secure_channel(serverAddress, creds)
```

3. To establish a connection to a server configured for mutual TLS then call the `secure_channel(..)` method and set:
   a. `root_certificates` to point to the server's self-signed certificate
   b. `certificate_chain` to point to the client's self-signed certificate
   c. `private_key` to point to the client's private key
   
```
ca_cert = open('server_self_signed_crt.pem', 'rb').read()
client_cert = open('client_self_signed_crt.pem', 'rb').read()
client_key = open('client_privatekey.pem', 'rb').read()
creds = grpc.ssl_channel_credentials(root_certificates=ca_cert, private_key=client_key, certificate_chain=client_cert)
channel = grpc.secure_channel(serverAddress, creds)
```

### Troubleshooting Security Configuration

1. If the server can't find the certificate file at the expected location then the server will fail to start and an error message will be printed to the terminal. In this case verify that the certificate file exists at the correct location and that the user has read permissions for the file.
2. If a client fails to connect to the server the cause can be one of many reasons. To determine if the failure is related to the security configuration review the server's terminal output. SSL/TLS error messages will be printed to the terminal where the server is running. Below is an example error message on the server side when the server expects a client certificate but does not receive it:

```
E0301 12:10:55.011000000  1136 ssl_transport_security.cc:1455] Handshake failed with fatal error SSL_ERROR_SSL: error:100000c0:SSL routines:OPENSSL_internal:PEER_DID_NOT_RETURN_A_CERTIFICATE.
```

3. One common error state occurs when a client creates a channel for a configuration different from the server. For example, the server might be configured for mutual TLS and the client configures an insecure channel (no security) or server-side TLS (no client certificate specified). In this case the client will typically see an `UNAVAILABLE` error status on the first RPC call. The gRPC conneciton utilizes lazy intialization and therefore the connection isn't established until the first RPC called is made. Below is an example call stack from a Python client:

```
<class 'grpc._channel._InactiveRpcError'>
Traceback (most recent call last):
  File "C:\Users\ksulliva\Desktop\Demo\client.py", line 22, in <module>
    response = server.IsReservedByClient(serverTypes.IsReservedByClientRequest(reservation_id=reservation_id, client_id=client_id))
  File "C:\Users\ksulliva\AppData\Local\Packages\PythonSoftwareFoundation.Python.3.9_qbz5n2kfra8p0\LocalCache\local-packages\Python39\site-packages\grpc\_channel.py", line 923, in __call__
    return _end_unary_response_blocking(state, call, False, None)
  File "C:\Users\ksulliva\AppData\Local\Packages\PythonSoftwareFoundation.Python.3.9_qbz5n2kfra8p0\LocalCache\local-packages\Python39\site-packages\grpc\_channel.py", line 826, in _end_unary_response_blocking
    raise _InactiveRpcError(state)
grpc._channel._InactiveRpcError: <_InactiveRpcError of RPC that terminated with:
        status = StatusCode.UNAVAILABLE
        details = "failed to connect to all addresses"
        debug_error_string = "{"created":"@1614621623.440000000","description":"Failed to pick subchannel","file":"src/core/ext/filters/client_channel/client_channel.cc","file_line":5391,"referenced_errors":[{"created":"@1614621623.440000000","description":"failed to connect to all addresses","file":"src/core/ext/filters/client_channel/lb_policy/pick_first/pick_first.cc","file_line":398,"grpc_status":14}]}"
```
