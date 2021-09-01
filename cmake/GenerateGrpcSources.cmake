#----------------------------------------------------------------------
# Use the grpc targets directly from this build, only when not cross-compiling.
#----------------------------------------------------------------------
if(CMAKE_CROSSCOMPILING)
  find_program(_PROTOBUF_PROTOC protoc)
  find_program(_GRPC_CPP_PLUGIN_EXECUTABLE grpc_cpp_plugin)

  if(NOT _GRPC_DEVICE_NILRT_LEGACY_TOOLCHAIN)
    find_package(gRPC REQUIRED)
    find_library(_REFLECTION grpc++_reflection)
    find_library(_GRPC_GRPCPP grpc++)
    find_library(_PROTOBUF_LIBPROTOBUF protobuf)
  else()
    set(_REFLECTION grpc++_reflection)
    set(_GRPC_GRPCPP grpc++)
    set(_PROTOBUF_LIBPROTOBUF libprotobuf)
  endif()

else()
  set(_PROTOBUF_PROTOC $<TARGET_FILE:protobuf::protoc>)
  set(_REFLECTION grpc++_reflection)
  set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:grpc_cpp_plugin>)
  set(_GRPC_GRPCPP grpc++)
  set(_PROTOBUF_LIBPROTOBUF libprotobuf)
endif()

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
    DEPENDS "${proto_file}" "${session_proto}")
endfunction()

