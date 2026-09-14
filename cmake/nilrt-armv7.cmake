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
set(compiler_path ${toolchain_path}/x86_64-nilrtsdk-linux/usr/bin/arm-nilrt-linux-gnueabi)
set(CMAKE_C_COMPILER ${compiler_path}/arm-nilrt-linux-gnueabi-gcc)
set(CMAKE_CXX_COMPILER ${compiler_path}/arm-nilrt-linux-gnueabi-g++)
set(CMAKE_OBJCOPY ${compiler_path}/arm-nilrt-linux-gnueabi-objcopy)

#----------------------------------------------------------------------
# Default compiler flags
#----------------------------------------------------------------------
set(CMAKE_SYSROOT ${toolchain_path}/cortexa9-vfpv3-nilrt-linux-gnueabi)
set(CMAKE_C_FLAGS_INIT "-Wall -fmessage-length=0 -march=armv7-a -mfpu=vfpv3 -mfloat-abi=softfp")
set(CMAKE_CXX_FLAGS_INIT "-Wall -fmessage-length=0 -march=armv7-a -mfpu=vfpv3 -mfloat-abi=softfp")
set(CMAKE_ASM_FLAGS_INIT "-march=armv7-a -mfpu=vfpv3 -mfloat-abi=softfp")
set(CMAKE_EXE_LINKER_FLAGS_INIT "-L${CMAKE_SYSROOT}/usr/lib")
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