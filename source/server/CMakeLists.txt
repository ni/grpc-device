add_library(ni_grpc_device_server_core
  "device_enumerator.cpp"
  "feature_toggles.cpp"
  "logging.cpp"
  "semaphore.cpp"
  "server_configuration_parser.cpp"
  "server_security_configuration.cpp"
  "session_repository.cpp"
  "session_utilities_service.cpp"
  "shared_library.cpp"
  "syscfg_library.cpp")

target_include_directories(ni_grpc_device_server_core
  PUBLIC ${CMAKE_SOURCE_DIR}/imports/include
  PUBLIC "../" # HACK should be able to sanitize this, but include statements expect it to be server/<whatever>.h
)

target_link_libraries(ni_grpc_device_server_core
  ni_grpc_device_server_core_proto
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF}
  ${CMAKE_DL_LIBS}
  nlohmann_json::nlohmann_json
  )