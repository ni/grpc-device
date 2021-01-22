# CMake toolchain file for cross-compiling for NI Linux Real-Time
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

# root path for toolchains
find_program(COMPILER_PATH x86_64-nilrt-linux-gcc)
get_filename_component(toolchain_path ${COMPILER_PATH}/../../../../.. REALPATH DIRECTORY)

# compilers
set(CMAKE_C_COMPILER x86_64-nilrt-linux-gcc)
set(CMAKE_CXX_COMPILER x86_64-nilrt-linux-g++)

# compiler flags
set(CMAKE_SYSROOT ${toolchain_path}/core2-64-nilrt-linux)
set(CMAKE_<LANG>_STANDARD_INCLUDE_DIRECTORIES ${toolchain_path}/core2-64-nilrt-linux/usr/include/c++/6.3.0 ${toolchain_path}/core2-64-nilrt-linux/usr/include/c++/6.3.0/x86_64-nilrt-linux)
set(CMAKE_<LANG>_FLAGS "-Wall -fmessage-length=0")
set(CMAKE_<LANG>_FLAGS_DEBUG "-O0 -g3")
set(CMAKE_<LANG>_FLAGS_RELEASE "-O3")

# define search behavior
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
