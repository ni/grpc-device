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
get_filename_component(daqmx_proto "../../../generated/nidaqmx/nidaqmx.proto" ABSOLUTE)
get_filename_component(daqmx_proto_path "${daqmx_proto}" PATH)
get_filename_component(session_proto "../../../imports/protobuf/session.proto" ABSOLUTE)
get_filename_component(session_proto_path "${session_proto}" PATH)
get_filename_component(data_moniker_proto "../../../imports/protobuf/data_moniker.proto" ABSOLUTE)
get_filename_component(data_moniker_proto_path "${data_moniker_proto}" PATH)

# Generated sources
set(daqmx_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/nidaqmx.pb.cc")
set(daqmx_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/nidaqmx.pb.h")
set(daq_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/nidaqmx.grpc.pb.cc")
set(daq_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/nidaqmx.grpc.pb.h")
add_custom_command(
      OUTPUT "${daqmx_proto_srcs}" "${daqmx_proto_hdrs}" "${daq_grpc_srcs}" "${daq_grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${daqmx_proto_path}"
        -I "${session_proto_path}"
        -I "${data_moniker_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${daqmx_proto}"
      DEPENDS "${daqmx_proto}")

# Generated sources
set(session_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/session.pb.cc")
set(session_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/session.pb.h")
set(session_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/session.grpc.pb.cc")
set(session_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/session.grpc.pb.h")
add_custom_command(
    OUTPUT "${session_proto_srcs}" "${session_proto_hdrs}" "${session_grpc_srcs}" "${session_grpc_hdrs}"
    COMMAND ${_PROTOBUF_PROTOC}
    ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${session_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${session_proto}"
    DEPENDS "${session_proto}")

# Generated sources
set(data_moniker_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/data_moniker.pb.cc")
set(data_moniker_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/data_moniker.pb.h")
set(data_moniker_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/data_moniker.grpc.pb.cc")
set(data_moniker_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/data_moniker.grpc.pb.h")
add_custom_command(
        OUTPUT "${data_moniker_proto_srcs}" "${data_moniker_proto_hdrs}" "${data_moniker_grpc_srcs}" "${data_moniker_grpc_hdrs}"
        COMMAND ${_PROTOBUF_PROTOC}
        ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${data_moniker_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${data_moniker_proto}"
        DEPENDS "${data_moniker_proto}")

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
