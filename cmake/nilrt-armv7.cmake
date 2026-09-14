#----------------------------------------------------------------------
# CMake toolchain file for cross-compiling for NI Linux Real-Time ARMv7
#----------------------------------------------------------------------
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR armv7-a)

#----------------------------------------------------------------------
# Path variables for toolchains
#----------------------------------------------------------------------
list(APPEND CMAKE_TRY_COMPILE_PLATFORM_VARIABLES NILRT_TOOLCHAIN_ROOT)
if(NOT NILRT_TOOLCHAIN_ROOT)
  message(FATAL_ERROR "NILRT_TOOLCHAIN_ROOT must point to the extracted NI Linux RT toolchain")
endif()
set(toolchain_path ${NILRT_TOOLCHAIN_ROOT}/sysroots)

#----------------------------------------------------------------------
# Compilers
#----------------------------------------------------------------------
set(CMAKE_C_COMPILER arm-linux-gnueabi-gcc-12)
set(CMAKE_CXX_COMPILER arm-linux-gnueabi-g++-12)
find_program(CMAKE_OBJCOPY arm-linux-gnueabi-objcopy REQUIRED)

#----------------------------------------------------------------------
# Default compiler flags
#----------------------------------------------------------------------
set(CMAKE_SYSROOT ${toolchain_path}/cortexa9-vfpv3-nilrt-linux-gnueabi)
set(nilrt_cxx_include_path ${CMAKE_SYSROOT}/usr/include/c++/6.3.0)

# Use GCC 12 with the headers and runtime from the 2018 NILRT sysroot. GCC 13
# reserves identifiers such as __remove_cv that are used by the GCC 6 headers.
# GCC 6 reported 201500L in C++1z mode; preserve that library feature profile so
# its headers do not expose final C++17 facilities that they do not provide.
set(CMAKE_C_STANDARD_INCLUDE_DIRECTORIES ${CMAKE_SYSROOT}/usr/include)
set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES
  ${nilrt_cxx_include_path}
  ${nilrt_cxx_include_path}/arm-nilrt-linux-gnueabi
  ${nilrt_cxx_include_path}/backward
  ${CMAKE_SYSROOT}/usr/include
)
set(CMAKE_C_FLAGS_INIT "-Wall -fmessage-length=0 -march=armv7-a -mfpu=vfpv3 -mfloat-abi=softfp")
set(CMAKE_CXX_FLAGS_INIT "-Wall -fmessage-length=0 -march=armv7-a -mfpu=vfpv3 -mfloat-abi=softfp -nostdinc++ -U__cplusplus -D__cplusplus=201500L")
set(CMAKE_ASM_FLAGS_INIT "-march=armv7-a -mfpu=vfpv3 -mfloat-abi=softfp")
set(CMAKE_EXE_LINKER_FLAGS_INIT "-L${CMAKE_SYSROOT}/usr/lib -L${CMAKE_SYSROOT}/lib")
set(CMAKE_C_FLAGS_DEBUG_INIT "-O0 -g3")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-O0 -g3")
set(CMAKE_C_FLAGS_RELEASE_INIT "-O3")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-O3")

# c-ares fails to detect fcntl when probing the 2018 sysroot with the host cross-compiler.
set(HAVE_FCNTL 1 CACHE INTERNAL "fcntl is available on NI Linux RT")

#----------------------------------------------------------------------
# Define proper search behavior for cross compilation
#----------------------------------------------------------------------
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)