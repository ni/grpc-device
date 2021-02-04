cmake_minimum_required(VERSION 3.12)

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
# Use C++17 (needed for shared_mutex support on Linux)
#----------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#----------------------------------------------------------------------
# Include generated *.pb.h files
#----------------------------------------------------------------------
include_directories(
  "${CMAKE_CURRENT_BINARY_DIR}"
  "./source"
  "./source/core_server"
)

#----------------------------------------------------------------------
# Proto file
#----------------------------------------------------------------------
get_filename_component(server_utilities_proto "source/server_utilities.proto" ABSOLUTE)
get_filename_component(server_utilities_proto_path "${server_utilities_proto}" PATH)

#----------------------------------------------------------------------
# Generated sources
#----------------------------------------------------------------------
set(server_utilities_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/server_utilities.pb.cc")
set(server_utilities_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/server_utilities.pb.h")
set(server_utilities_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/server_utilities.grpc.pb.cc")
set(server_utilities_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/server_utilities.grpc.pb.h")
add_custom_command(
  OUTPUT "${server_utilities_proto_srcs}" "${server_utilities_proto_hdrs}" "${server_utilities_grpc_srcs}" "${server_utilities_grpc_hdrs}"
  COMMAND ${_PROTOBUF_PROTOC}
  ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
    --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
    -I "${server_utilities_proto_path}"
    --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
    "${server_utilities_proto}"
  DEPENDS "${server_utilities_proto}")

add_executable(core_server
   "source/core_server/core_server.cpp"
   "source/core_server/hardware/grpc/core_service.cpp"
   "source/core_server/hardware/grpc/internal/semaphore.cpp"
   "source/core_server/hardware/grpc/internal/session_repository.cpp"
   "source/core_server/hardware/grpc/internal/shared_library.cpp"
   ${server_utilities_proto_srcs}
   ${server_utilities_grpc_srcs})

target_link_libraries(core_server
   ${_REFLECTION}
   ${_GRPC_GRPCPP}
   ${_PROTOBUF_LIBPROTOBUF}
   ${CMAKE_DL_LIBS}
   )

# Add googletest tests
enable_testing()
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(third_party/gtest ${CMAKE_CURRENT_BINARY_DIR}/gtest} EXCLUDE_FROM_ALL)

# Link test executable against gtest
add_executable(CoreServiceTestsRunner
    "source/tests/run_all_tests.cpp"
    "source/tests/integration/hardware/grpc/core_service_tests.cpp"
    "source/core_server/hardware/grpc/core_service.cpp"
    "source/core_server/hardware/grpc/internal/semaphore.cpp"
    "source/core_server/hardware/grpc/internal/session_repository.cpp"
    ${server_utilities_proto_srcs}
    ${server_utilities_grpc_srcs})

target_link_libraries(CoreServiceTestsRunner
    gtest
    ${_GRPC_GRPCPP}
    ${CMAKE_DL_LIBS})

add_library(TestApi SHARED
    "source/tests/test_api/test_api.cpp")
add_compile_definitions(TestApi TEST_API_BUILDING)

add_executable(UnitTestsRunner
    "source/tests/run_all_tests.cpp"
    "source/tests/unit/hardware/grpc/core_service_tests.cpp"
    "source/tests/unit/shared_library_tests.cpp"
    "source/core_server/hardware/grpc/core_service.cpp"
    "source/core_server/hardware/grpc/internal/semaphore.cpp"
    "source/core_server/hardware/grpc/internal/session_repository.cpp"
    "source/core_server/hardware/grpc/internal/shared_library.cpp"
    ${server_utilities_proto_srcs}
    ${server_utilities_grpc_srcs})

target_link_libraries(UnitTestsRunner
    gtest
    ${_GRPC_GRPCPP}
    ${CMAKE_DL_LIBS})

# Hook up different google test runners to CTest
# add_test( NAME UnitTests COMMAND UnitTestsRunner )
add_test( NAME CoreServiceTests COMMAND CoreServiceTestsRunner )
add_test( NAME UnitTests COMMAND UnitTestsRunner )
