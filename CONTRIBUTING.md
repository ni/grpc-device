# Contributing to grpc-device

Contributions to grpc-device are welcome from all!

grpc-device is managed via [git](https://git-scm.com), with the canonical upstream
repository hosted on [GitHub](https://github.com/ni/grpc-device/).

grpc-device follows a pull-request model for development.  If you wish to
contribute, you will need to create a GitHub account, fork this project, push a
branch with your changes to your project, and then submit a pull request.

Please remember to sign off your commits (e.g., by using `git commit -s` if you
are using the command line client). This amends your git commit message with a line
of the form `Signed-off-by: Name Lastname <name.lastmail@emailaddress.com>`. Please
include all authors of any given commit into the commit message with a
`Signed-off-by` line. This indicates that you have read and signed the Developer
Certificate of Origin (see below) and are able to legally submit your code to
this repository.

See [GitHub's official documentation](https://help.github.com/articles/using-pull-requests/) for more details.

# Getting Started

## Building on Windows 64-bit

### Prerequisites
To prepare for cmake + Microsoft Visual C++ compiler build
- Install Visual Studio 2022 or newer (Visual C++ compiler will be used).
- Install [Git](https://git-scm.com/).
- Install [CMake](https://cmake.org/download/) 3.18.0 or newer and add it to the PATH.
  - Our github actions use 3.18.0 to build currently. 
  - [CMake Build Failure in grpc-device: Compatibility Update Required](https://github.com/ni/grpc-device/issues/1172) documents a known issue when using newer versions of CMake where you will see `Compatibility with CMake < 3.5 has been removed from CMake` with a workaround of using the flag `-DCMAKE_POLICY_VERSION_MINIMUM=3.5`.
- Install [Python](https://www.python.org/downloads/) and add it to the PATH.
- Install [NASM](https://nasm.us/) and add it to the PATH.
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

### Build with Ninja

Build faster by using Ninja:

```
> "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvars64.bat"
> mkdir build
> cd build
> cmake .. -G "Ninja Multi-Config"
> cmake --build .
```

## Building on Linux

### Prerequisites

For Debian/Ubuntu, install git, cmake (3.18.0 or newer), and mako:
```
> sudo apt-get update
> sudo apt-get install git
> sudo apt-get install cmake
> sudo apt-get install g++
> sudo apt-get install python3-venv  # for ensurepip
> sudo apt-get install ninja-build   # optional
```

For NI Linux RT, install packagegroup-core-buildessential, git, git-perltools, cmake (3.18.0 or newer), python3-utils, and mako:
```
> opkg update
> opkg install packagegroup-core-buildessential
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

**Note**: When building on Linux RT if the compiler toolchain segfaults at any point
you might need to increase the default stack size before building again.
```
> ulimit -s 8192
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

# Testing

## C++ Code under Source
Changes made to the C++ code under the `source` directory should be accompanied with auto tests in one of the
following three test suites, all written using [Google Test/Mock](https://github.com/google/googletest):

### Unit
Unit tests should use mocks or fakes of any dependencies of the subject under test (SUT). These tests get run automatically
for Windows and Linux when a pull request is created that merges to `main`.

The test name should match the class being tested.

> Example:<br>
> A unit test for class `MyFoo` should be named `MyFooTests` and go in `/source/tests/unit/my_foo.cpp`

### Integration
Integration tests should be used when testing multiple components together, such as the client & server. Any dependencies
not being tested should be mocked or faked. These tests get run automatically for Windows and Linux when a pull request
is created that merges to `main`.

The test name should match the class being tested.

> Example:<br>
> An integration test for class `MyFoo` should be named `MyFooTests` and go in `/source/tests/integration/my_foo.cpp`

### System
A system test tests the server and client on a system with the supported NI device drivers installed. These tests are not
run automatically and should be run manually by executing the `SystemTestRunner` class in the build directory.

The test name should match the driver and the features being tested.

## Code generation scripts
The code generation scripts generate files into the `generated` directory which gets checked into source control. Before
pushing a change to the templates or helpers, first perform a local build and add the resulting generated files to your
commit. This will allow reviewers to see the effects of the change.

# Developer Certificate of Origin (DCO)

   Developer's Certificate of Origin 1.1

   By making a contribution to this project, I certify that:

   (a) The contribution was created in whole or in part by me and I
       have the right to submit it under the open source license
       indicated in the file; or

   (b) The contribution is based upon previous work that, to the best
       of my knowledge, is covered under an appropriate open source
       license and I have the right under that license to submit that
       work with modifications, whether created in whole or in part
       by me, under the same open source license (unless I am
       permitted to submit under a different license), as indicated
       in the file; or

   (c) The contribution was provided directly to me by some other
       person who certified (a), (b) or (c) and I have not modified
       it.

   (d) I understand and agree that this project and the contribution
       are public and that a record of the contribution (including all
       personal information I submit with it, including my sign-off) is
       maintained indefinitely and may be redistributed consistent with
       this project or the open source license(s) involved.

(taken from [developercertificate.org](https://developercertificate.org/))

See [LICENSE](https://github.com/ni/grpc-device/blob/master/LICENSE)
for details about how grpc-device is licensed.

# Additional Info

If you're looking for additional info while working in the grpc-device repo, you can check out the [Internal Development](https://github.com/ni/grpc-device/wiki/internal-development) page of our Wiki. It hosts a collection of overviews and tips and tricks that might prove useful.
