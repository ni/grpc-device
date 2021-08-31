list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(GenerateGrpcSources)

#----------------------------------------------------------------------
# Proto file
#----------------------------------------------------------------------

set(proto_srcs_dir "${CMAKE_CURRENT_BINARY_DIR}/core/proto")
file(MAKE_DIRECTORY ${proto_srcs_dir})

get_filename_component(session_proto "session.proto" ABSOLUTE)
get_filename_component(session_proto_path "${session_proto}" PATH)

set(session_proto_srcs "${proto_srcs_dir}/session.pb.cc")
set(session_proto_hdrs "${proto_srcs_dir}/session.pb.h")
set(session_grpc_srcs "${proto_srcs_dir}/session.grpc.pb.cc")
set(session_grpc_hdrs "${proto_srcs_dir}/session.grpc.pb.h")
GenerateGrpcSources(
  ${session_proto}
  ${session_proto_path}
  ${session_proto_srcs}
  ${session_proto_hdrs}
  ${session_grpc_srcs}
  ${session_grpc_hdrs})


add_library(ni_grpc_device_server_core_proto
  ${session_proto_srcs}
  ${session_grpc_srcs})

target_include_directories(ni_grpc_device_server_core_proto
  PUBLIC ${proto_srcs_dir}
  )

target_link_libraries(ni_grpc_device_server_core_proto
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})
