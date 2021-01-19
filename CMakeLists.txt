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

#----------------------------------------------------------------------
# Include generated *.pb.h files
#----------------------------------------------------------------------
include_directories(
  "${CMAKE_CURRENT_BINARY_DIR}" 
  "./source"
)

#----------------------------------------------------------------------
# Proto file
#----------------------------------------------------------------------
get_filename_component(core_proto "core.proto" ABSOLUTE)
get_filename_component(core_proto_path "${core_proto}" PATH)

#----------------------------------------------------------------------
# Generated sources
#----------------------------------------------------------------------
set(core_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/core.pb.cc")
set(core_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/core.pb.h")
set(core_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/core.grpc.pb.cc")
set(core_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/core.grpc.pb.h")
add_custom_command(
  OUTPUT "${core_proto_srcs}" "${core_proto_hdrs}" "${core_grpc_srcs}" "${core_grpc_hdrs}"
  COMMAND ${_PROTOBUF_PROTOC}
  ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
    --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
    -I "${core_proto_path}"
    --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
    "${core_proto}"
  DEPENDS "${core_proto}")
  
add_executable(core_server 
   "source/hardware/grpc/core_server.cpp"
   "source/hardware/grpc/core_service.cpp"
   "source/hardware/grpc/core_service.h"
   ${core_proto_srcs}
   ${core_grpc_srcs})

target_link_libraries(core_server
   ${_REFLECTION}
   ${_GRPC_GRPCPP}
   ${_PROTOBUF_LIBPROTOBUF}
   )

# Add googletest tests
enable_testing()
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(third_party/gtest ${CMAKE_CURRENT_BINARY_DIR}/gtest} EXCLUDE_FROM_ALL)

add_executable(UnitTestRunner 
    "tests/run_all_tests.cpp"
    "tests/sample_google_tests.cpp")
target_link_libraries(UnitTestRunner gtest)

add_executable(InProcessServerClientTestRunner 
    "tests/run_all_tests.cpp"
    "tests/in-process-server-client-tests.cpp"
    "source/core_service.cpp"
    ${core_proto_srcs}
    ${core_grpc_srcs})
target_link_libraries(InProcessServerClientTestRunner 
    gtest
    ${_GRPC_GRPCPP})

# Hook up different google test runners to CTest
add_test( NAME UnitTests COMMAND UnitTestRunner )
add_test( NAME InProcessServerClientTests COMMAND InProcessServerClientTestRunner )