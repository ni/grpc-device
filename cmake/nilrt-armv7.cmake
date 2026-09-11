#----------------------------------------------------------------------
# CMake toolchain file for cross-compiling for NI Linux Real-Time ARMv7
#----------------------------------------------------------------------
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR armv7-a)

#----------------------------------------------------------------------
# Path variables for toolchains
#----------------------------------------------------------------------
if(NOT NILRT_TOOLCHAIN_ROOT)
  message(FATAL_ERROR "NILRT_TOOLCHAIN_ROOT must point to the extracted NI Linux RT toolchain")
endif()
set(toolchain_path ${NILRT_TOOLCHAIN_ROOT}/sysroots)
set(include_path cortexa9-vfpv3-nilrt-linux-gnueabi/usr/include/c++/6.3.0)

#----------------------------------------------------------------------
# Compilers
#----------------------------------------------------------------------
set(CMAKE_C_COMPILER arm-linux-gnueabi-gcc)
set(CMAKE_CXX_COMPILER arm-linux-gnueabi-g++)
find_program(CMAKE_OBJCOPY arm-linux-gnueabi-objcopy REQUIRED)

#----------------------------------------------------------------------
# Default compiler flags
#----------------------------------------------------------------------
set(CMAKE_SYSROOT ${toolchain_path}/cortexa9-vfpv3-nilrt-linux-gnueabi)
set(CMAKE_C_STANDARD_INCLUDE_DIRECTORIES ${CMAKE_SYSROOT}/usr/include)
set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES
  ${toolchain_path}/${include_path}
  ${toolchain_path}/${include_path}/arm-nilrt-linux-gnueabi
  ${CMAKE_SYSROOT}/usr/include)
set(CMAKE_C_FLAGS_INIT "-Wall -fmessage-length=0 -march=armv7-a -mfpu=vfpv3 -mfloat-abi=softfp")
set(CMAKE_CXX_FLAGS_INIT "-Wall -fmessage-length=0 -march=armv7-a -mfpu=vfpv3 -mfloat-abi=softfp")
set(CMAKE_C_FLAGS_DEBUG_INIT "-O0 -g3")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-O0 -g3")
set(CMAKE_C_FLAGS_RELEASE_INIT "-O3")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-O3")

#----------------------------------------------------------------------
# Define proper search behavior for cross compilation
#----------------------------------------------------------------------
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)