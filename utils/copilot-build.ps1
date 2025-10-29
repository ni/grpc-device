#!/usr/bin/env pwsh
# Build script for grpc-device project
# This script sets up the Visual Studio environment and builds the project
#
# This script is particularly useful for GitHub Copilot since the complex
# cmd.exe command with vcvars64.bat setup often requires manual approval.
# Using this script allows for easier auto-approval of build commands.

param(
    [Parameter(ValueFromRemainingArguments = $true)]
    [string[]]$BuildArgs
)

# Convert BuildArgs array to a single string for passing to cmake
$cmakeArgs = if ($BuildArgs) { $BuildArgs -join " " } else { "--config Debug" }

# Run the build command with Visual Studio environment setup
$command = "call `"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvars64.bat`" && cd /d `"$PWD\build`" && cmake --build . $cmakeArgs"

Write-Host "Running build command: cmake --build . $cmakeArgs"
Write-Host "Setting up Visual Studio environment and building..."

cmd.exe /c $command