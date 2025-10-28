# Copilot Instructions for grpc-device Repository

## Building the Project

This repository requires specific environment setup before building. **Always** follow these guidelines when running build commands.

### Prerequisites

1. **Visual Studio Build Tools**: Ensure Visual Studio Build Tools are installed with C++ development components
2. **CMake**: Make sure CMake is available in the system PATH

### Critical: Preferred Build Method

**Always use the copilot-build.ps1 script for all builds:**

```powershell
# Default Debug build
.\utils\copilot-build.ps1

# Release build
.\utils\copilot-build.ps1 --config Release

# RelWithDebInfo build
.\utils\copilot-build.ps1 --config RelWithDebInfo

# Other cmake arguments
.\utils\copilot-build.ps1 --target clean --config Debug
.\utils\copilot-build.ps1 --parallel 4 --config Release
```

This script automatically handles the Visual Studio environment setup and is much more Copilot-friendly since it avoids complex command chaining that often requires manual approval.
Any parameters you pass into this script will be passed along into the cmake command. However, you should prefer to do simple full builds instead of targeted builds. Ninja is good
at doing incremental builds quickly.

### Testing

To run tests after building:

```powershell
# Run unit tests
.\build\Debug\UnitTestsRunner.exe

# Run system tests
.\build\Debug\SystemTestsRunner.exe
```

Or use the build script to build first, then run tests:

```powershell
.\utils\copilot-build.ps1 --config Debug
.\build\Debug\UnitTestsRunner.exe
.\build\Debug\SystemTestsRunner.exe
```

### Clean Build

**WARNING: Never perform a clean build without asking the user first.** Full builds take a very long time and are almost never needed. Most issues can be resolved with a regular incremental build.

If a clean build is specifically requested:

```powershell
# Using the build script (preferred)
.\utils\copilot-build.ps1 --target clean --config Debug

# Or manually
cmd.exe /c "call `"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvars64.bat`" && cd /d `"%cd%\build`" && cmake --build . --target clean && cmake --build . --config Debug"
```

## Repository Structure Notes

- Source code is in the `source/` directory
- Examples are in the `examples/` directory  
- Generated code is in the `generated/` directory
- Build artifacts go in the `build/` directory
- The project uses gRPC and Protocol Buffers for communication

## Python Components

This repository also contains Python components. When working with Python:

1. Use the virtual environment created by the build system
2. Install dependencies from `python_build_requirements.txt`
3. Python examples are located in the `examples/` directory