# cmake build file for C++ MonikerStreamingClient example.
# Assumes protobuf and gRPC have been installed using cmake.

cmake_minimum_required(VERSION 3.16)

project(MonikerStreamingClient C CXX)

find_package(Protobuf CONFIG REQUIRED)
message(STATUS "Using protobuf ${Protobuf_VERSION}")

set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)
find_program(_PROTOBUF_PROTOC protoc)
find_package(gRPC CONFIG REQUIRED)
message(STATUS "Using gRPC ${gRPC_VERSION}")
set(_GRPC_GRPCPP gRPC::grpc++)
find_program(_GRPC_CPP_PLUGIN_EXECUTABLE grpc_cpp_plugin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")

# Proto files
get_filename_component(daqmx_proto "${CMAKE_SOURCE_DIR}/../../../generated/nidaqmx/nidaqmx.proto" ABSOLUTE)
get_filename_component(daqmx_proto_path "${daqmx_proto}" PATH)
get_filename_component(session_proto "${CMAKE_SOURCE_DIR}/../../../third_party/ni-apis/ni/grpcdevice/v1/session.proto" ABSOLUTE)
get_filename_component(session_proto_path "${session_proto}" PATH)
get_filename_component(data_moniker_proto "${CMAKE_SOURCE_DIR}/../../../imports/protobuf/data_moniker.proto" ABSOLUTE)
get_filename_component(data_moniker_proto_path "${data_moniker_proto}" PATH)

message(STATUS "daqmx_proto_path: ${daqmx_proto_path}")
#----------------------------------------------------------------------
# Generate sources from proto files
# Usage: GenerateGrpcSources(<proto-file-name> <proto-file-path>)
#----------------------------------------------------------------------
function(GenerateGrpcSources)
set(proto_name ${ARGV0})
set(proto_absolute_path ${ARGV1})

set(proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/${proto_name}.pb.cc")
set(proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/${proto_name}.pb.h")
set(grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/${proto_name}.grpc.pb.cc")
set(grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/${proto_name}.grpc.pb.h")

add_custom_command(
      OUTPUT "${proto_srcs}" "${proto_hdrs}" "${grpc_srcs}" "${grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${daqmx_proto_path}"
        -I "${session_proto_path}"
        -I "${data_moniker_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        ${proto_absolute_path}
      DEPENDS ${proto_absolute_path})
endfunction()

# Generated sources
GenerateGrpcSources(nidaqmx ${daqmx_proto})
GenerateGrpcSources(session ${session_proto})
GenerateGrpcSources(data_moniker ${data_moniker_proto})

# Include generated *.pb.h files
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

add_executable(MonikerStreamingClient
    "stream-read-analog-input-using-moniker-streaming.cpp"
    "${CMAKE_CURRENT_BINARY_DIR}/nidaqmx.pb.cc"
    "${CMAKE_CURRENT_BINARY_DIR}/nidaqmx.pb.h"
    "${CMAKE_CURRENT_BINARY_DIR}/nidaqmx.grpc.pb.cc"
    "${CMAKE_CURRENT_BINARY_DIR}/nidaqmx.grpc.pb.h"
    "${CMAKE_CURRENT_BINARY_DIR}/session.pb.cc"
    "${CMAKE_CURRENT_BINARY_DIR}/session.pb.h"
    "${CMAKE_CURRENT_BINARY_DIR}/session.grpc.pb.cc"
    "${CMAKE_CURRENT_BINARY_DIR}/session.grpc.pb.h"
    "${CMAKE_CURRENT_BINARY_DIR}/data_moniker.pb.cc"
    "${CMAKE_CURRENT_BINARY_DIR}/data_moniker.pb.h"
    "${CMAKE_CURRENT_BINARY_DIR}/data_moniker.grpc.pb.cc"
    "${CMAKE_CURRENT_BINARY_DIR}/data_moniker.grpc.pb.h"
    )
target_link_libraries(MonikerStreamingClient
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF})
