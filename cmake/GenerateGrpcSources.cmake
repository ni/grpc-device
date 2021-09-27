set(proto_srcs_dir "${PROJECT_BINARY_DIR}/proto")

include(ImportGrpc)

#----------------------------------------------------------------------
# Generate sources from proto files
#----------------------------------------------------------------------
function(GenerateGrpcSources proto_file proto_path proto_srcs proto_hdrs grpc_srcs grpc_hdrs)
  get_filename_component(proto_out_path "${proto_srcs}" PATH)
  add_custom_command(
    OUTPUT "${proto_srcs}" "${proto_hdrs}" "${grpc_srcs}" "${grpc_hdrs}"
    COMMAND ${_PROTOBUF_PROTOC}
    ARGS --grpc_out "${proto_out_path}"
      --cpp_out "${proto_out_path}"
      -I "${proto_path}"
      -I ${CMAKE_SOURCE_DIR}/third_party/grpc/third_party/protobuf/src/
      -I ${CMAKE_SOURCE_DIR}/source/protobuf
      --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
      "${proto_file}"
    DEPENDS "${proto_file}")
endfunction()
