# gRPC Support for NI Hardware Driver APIs

This repo contains necessary C++ code and support VIs to implement a gRPC server in LabVIEW.

eexample/ExampleQueryServer.vi with query_server.proto defines a simple query service example that can be used for a variety of purposes.  

You can either use the service as defined to implement a generic server via gPRC or use the implementation
as a pattern to implement a gRPC service of your design.

the project supports Windows, Linux, and Linux RT.

## Build Status
TBD

## Note: This project is not yet complete
* The gRPC server is not yet complete.
* Testing on Linux not yet implemented.
* SSL/TLS support not yet implemented.
* Support for specific NI driver APIs not yet added.

## Building on Windows

### Prerequisites
To prepare for cmake + Microsoft Visual C++ compiler build
- Install Visual Studio 2015, 2017, or 2019 (Visual C++ compiler will be used).
- Install [Git](https://git-scm.com/).
- Install [CMake](https://cmake.org/download/).


### Building 64-bit

**Launch "x64 Native Tools Command Prompt for Visual Studio"**

Download the repo and update submodules, this will pull the gRPC components and all dependencies

```
> git clone https://github.com/ni/ni-driver-apis-grpc.git
> cd ni-driver-apis-grpc
> git submodule update --init --recursive
```

Build Debug
```
> mkdir build
> cd build
> cmake ..
> cmake --build .
```

Build Release
```
> mkdir build
> cd build
> cmake ..
> cmake --build . --config Release
```

## Building on Linux

Download the repo and update submodules, this will pull the gRPC components and all dependencies

```
> git clone https://github.com/ni/ni-driver-apis-grpc.git ni-driver-apis-grpc
> cd ni-driver-apis-grpc
> git submodule update --init --recursive
```

Build Debug

```
> mkdir -p cmake/build
> cd cmake/build
> cmake ../..
> make
```

Build Release

```
> mkdir -p cmake/build
> cd cmake/build
> cmake -DCMAKE_BUILD_TYPE=Release ../..
> make
```

## Building on Linux RT

Install required packages not installed by default

```
> opkg update
> opkg install git
> opkg install git-perltools
> opkg install cmake
```

Download the repo and update submodules, this will pull the gRPC components and all dependencies

```
> git clone https://github.com/ni/ni-driver-apis-grpc.git ni-driver-apis-grpc
> cd ni-driver-apis-grpc
> git submodule update --init --recursive
```

Build Debug

```
> mkdir -p cmake/build
> cd cmake/build
> cmake ../..
> make
```

Build Release

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

You can enable SSL/TLS support on the server by specifying the path to a certificate and private key in the configuration file.
More information about the config file TBD

You can generate the certificate with openssl using the following script.

```
mypass="password123"

echo Generate server key:
openssl genrsa -passout pass:$mypass -des3 -out server.key 4096

echo Generate server signing request:
openssl req -passin pass:$mypass -new -key server.key -out server.csr -subj  "/C=US/ST=TX/L=Austin/O=NI/OU=labview/CN=localhost"

echo Self-sign server certificate:
openssl x509 -req -passin pass:$mypass -days 365 -in server.csr -signkey server.key -set_serial 01 -out server.crt

echo Remove passphrase from server key:
openssl rsa -passin pass:$mypass -in server.key -out server.key

rm server.csr
```

Clients then must connect using the server certificate that was generated (server.cer) otherwise the connection will fail.

If you do not passing in a certificate then the server will use insecure gRPC.
