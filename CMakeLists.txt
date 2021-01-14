cmake_minimum_required(VERSION 3.5.1)

project(core_server C CXX)

#----------------------------------------------------------------------
# Include the gRPC's cmake build
#----------------------------------------------------------------------
add_subdirectory(third_party/grpc ${CMAKE_CURRENT_BINARY_DIR}/grpc EXCLUDE_FROM_ALL)

#----------------------------------------------------------------------
# Use the grpc targets directly from this build.
#----------------------------------------------------------------------
set(_PROTOBUF_LIBPROTOBUF libprotobuf)
set(_REFLECTION grpc++_reflection)
if(CMAKE_CROSSCOMPILING)
  find_program(_PROTOBUF_PROTOC protoc)
else()
  set(_PROTOBUF_PROTOC $<TARGET_FILE:protobuf::protoc>)
endif()
set(_GRPC_GRPCPP grpc++)
if(CMAKE_CROSSCOMPILING)
  find_program(_GRPC_CPP_PLUGIN_EXECUTABLE grpc_cpp_plugin)
else()
  set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:grpc_cpp_plugin>)
endif()

add_executable(core_server "source/core_server.cpp")

target_link_libraries(core_server
   ${_REFLECTION}
   ${_GRPC_GRPCPP}
   ${_PROTOBUF_LIBPROTOBUF}
   )

# Add googletest unit tests
enable_testing()
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(third_party/gtest ${CMAKE_CURRENT_BINARY_DIR}/gtest} EXCLUDE_FROM_ALL)
add_executable(UnitTests Tests/RunAllGoogleTests.cpp Tests/SampleGoogleTestCase.cpp)

# Link test executable against gtest
target_link_libraries(UnitTests gtest)

# Add test so the google test runner hooks up to CTest
add_test( NAME UnitTests COMMAND UnitTests )