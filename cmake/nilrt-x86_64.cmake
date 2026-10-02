#----------------------------------------------------------------------
# CMake toolchain file for cross-compiling for NI Linux Real-Time
#----------------------------------------------------------------------
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

#----------------------------------------------------------------------
# Path variables for toolchains
#----------------------------------------------------------------------
if(NILRT_TOOLCHAIN_ROOT)
	set(toolchain_path ${NILRT_TOOLCHAIN_ROOT}/sysroots)
else()
	find_program(COMPILER_PATH x86_64-nilrt-linux-gcc REQUIRED)
	get_filename_component(toolchain_path ${COMPILER_PATH}/../../../../.. REALPATH DIRECTORY)
endif()

#----------------------------------------------------------------------
# Compilers
#----------------------------------------------------------------------
set(CMAKE_C_COMPILER x86_64-nilrt-linux-gcc)
set(CMAKE_CXX_COMPILER x86_64-nilrt-linux-g++)
find_program(CMAKE_OBJCOPY x86_64-nilrt-linux-objcopy REQUIRED)

#----------------------------------------------------------------------
# Default compiler flags
#----------------------------------------------------------------------
set(CMAKE_SYSROOT ${toolchain_path}/core2-64-nilrt-linux)
set(CMAKE_C_FLAGS_INIT "-Wall -fmessage-length=0")
set(CMAKE_CXX_FLAGS_INIT "-Wall -fmessage-length=0")
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
