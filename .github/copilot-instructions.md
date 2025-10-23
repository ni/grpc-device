# Copilot Instructions for grpc-device Repository

## Building the Project

This repository requires specific environment setup before building. **Always** follow these guidelines when running build commands.

### Prerequisites

1. **Visual Studio Build Tools**: Ensure Visual Studio Build Tools are installed with C++ development components
2. **CMake**: Make sure CMake is available in the system PATH

### Critical Build Requirements

#### Environment Variables
Before running any CMake or build commands, you **MUST** set up the Visual Studio environment variables by running `vcvars64.bat`. This script sets up the necessary compiler and linker paths.

#### Working Directory
All build commands should be executed from the `build` directory within the repository root.

### Correct Build Command Pattern

**Always use this pattern for build commands in PowerShell:**

From the repository root:
```powershell
cmd.exe /c "call `"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvars64.bat`" && cd /d build && cmake --build . --config Debug"
```

From the build directory (if already there):
```powershell
cmd.exe /c "call `"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvars64.bat`" && cmake --build . --config Debug"
```

Or for different configurations:

```powershell
# Release build
cmd.exe /c "call `"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvars64.bat`" && cd /d build && cmake --build . --config Release"

# RelWithDebInfo build
cmd.exe /c "call `"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvars64.bat`" && cd /d build && cmake --build . --config RelWithDebInfo"
```

**Note**: The first command assumes you're in the repository root. If you're already in the build directory, use the second form.

### CMake Configuration

For initial project configuration, refer to the `CONTRIBUTING.md` file and follow the "Build with Ninja" instructions.

### Common Mistakes to Avoid

1. **Never run CMake commands without first calling `vcvars64.bat`**
2. **Never run build commands from the repository root** - always change to the `build` directory first
3. **Don't use PowerShell semicolons (`;`) with vcvars64.bat** - use `cmd.exe /c` with `&&` to preserve environment variables

### Alternative vcvars64.bat Locations

If the standard path doesn't work, try these common locations:
- `"C:\Program Files (x86)\Microsoft Visual Studio\2022\Professional\VC\Auxiliary\Build\vcvars64.bat"`
- `"C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"`
- `"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"`

### Testing

To run tests after building:

```powershell
.\build\Debug\SystemTestsRunner.exe
```

### Clean Build

**WARNING: Never perform a clean build without asking the user first.** Full builds take a very long time and are almost never needed. Most issues can be resolved with a regular incremental build.

If a clean build is specifically requested:

```powershell
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

Remember: **Always start with vcvars64.bat and navigate to the build directory** before running any build-related commands.