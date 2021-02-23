cmake_minimum_required(VERSION 3.12.0)

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
set(proto_srcs_dir "${CMAKE_CURRENT_BINARY_DIR}/proto")
file(MAKE_DIRECTORY ${proto_srcs_dir})
include_directories(
  "${proto_srcs_dir}"
  "./generated"
  "./imports/includes"
  "./source"
  "./source/core_server"
)
link_directories("./imports/lib/win64")

#----------------------------------------------------------------------
# Get list of NI Driver APIs and directories to generate from
#----------------------------------------------------------------------
set(metadata_dir ${CMAKE_SOURCE_DIR}/source/metadata)
set(service_output_dir ${CMAKE_SOURCE_DIR}/generated)
set(codegen_dir ${CMAKE_SOURCE_DIR}/source/codegen)
set(ni_apis "nifake" "niscope")

#----------------------------------------------------------------------
# Create NI Driver APIs proto and server files
#----------------------------------------------------------------------
set(codegen_scripts
  "${codegen_dir}/common_helpers.py"
  "${codegen_dir}/generate_service.py"
  "${codegen_dir}/handler_helpers.py"
  "${codegen_dir}/library_interface.h.mako"
  "${codegen_dir}/library.cpp.mako"
  "${codegen_dir}/library.h.mako"
  "${codegen_dir}/mock_library.h.mako"
  "${codegen_dir}/proto.mako"
  "${codegen_dir}/proto_helpers.py"
  "${codegen_dir}/service.cpp.mako"
  "${codegen_dir}/service.h.mako")

# Populated in the api loop below.
set(api_service_srcs "")

foreach(api ${ni_apis})
  set(codegen_dependencies
    "${metadata_dir}/${api}/attributes.py"
    "${metadata_dir}/${api}/attributes_addon.py"
    "${metadata_dir}/${api}/config.py"
    "${metadata_dir}/${api}/config_addon.py"
    "${metadata_dir}/${api}/enums.py"
    "${metadata_dir}/${api}/enums_addon.py"
    "${metadata_dir}/${api}/functions.py"
    "${metadata_dir}/${api}/functions_addon.py"
    "${metadata_dir}/${api}/__init__.py")
  set(output_files
    ${service_output_dir}/${api}/${api}_library_interface.h
    ${service_output_dir}/${api}/${api}_library.cpp
    ${service_output_dir}/${api}/${api}_library.h
    ${service_output_dir}/${api}/${api}_mock_library.h
    ${service_output_dir}/${api}/${api}.proto
    ${service_output_dir}/${api}/${api}_service.cpp
    ${service_output_dir}/${api}/${api}_service.h)
  set(gen_command COMMAND python ${codegen_dir}/generate_service.py ${metadata_dir}/${api}/ -o ${service_output_dir}/)
  if (NOT api STREQUAL "nifake")
    set(api_service_srcs
      ${api_service_srcs}
      "${service_output_dir}/${api}/${api}_service.cpp"
      "${service_output_dir}/${api}/${api}_library.cpp")
  endif()
  add_custom_command(OUTPUT ${output_files}
    ${gen_command}
    COMMENT "Generating proto file and service for ${api}"
    DEPENDS ${codegen_dependencies} ${codegen_scripts})
endforeach()

#----------------------------------------------------------------------
# Proto file
#----------------------------------------------------------------------
get_filename_component(server_utilities_proto "source/server_utilities.proto" ABSOLUTE)
get_filename_component(server_utilities_proto_path "${server_utilities_proto}" PATH)

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
      -I ${CMAKE_SOURCE_DIR}/source
      --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
      "${proto_file}"
    DEPENDS "${proto_file}" "${server_utilities_proto}")
endfunction()

set(server_utilities_proto_srcs "${proto_srcs_dir}/server_utilities.pb.cc")
set(server_utilities_proto_hdrs "${proto_srcs_dir}/server_utilities.pb.h")
set(server_utilities_grpc_srcs "${proto_srcs_dir}/server_utilities.grpc.pb.cc")
set(server_utilities_grpc_hdrs "${proto_srcs_dir}/server_utilities.grpc.pb.h")
GenerateGrpcSources(
  ${server_utilities_proto}
  ${server_utilities_proto_path}
  ${server_utilities_proto_srcs}
  ${server_utilities_proto_hdrs}
  ${server_utilities_grpc_srcs}
  ${server_utilities_grpc_hdrs})

foreach(api ${ni_apis})
  GenerateGrpcSources(
    ${service_output_dir}/${api}/${api}.proto
    ${service_output_dir}/${api}/
    "${proto_srcs_dir}/${api}.pb.cc"
    "${proto_srcs_dir}/${api}.pb.h"
    "${proto_srcs_dir}/${api}.grpc.pb.cc"
    "${proto_srcs_dir}/${api}.grpc.pb.h")
  if(NOT api STREQUAL "nifake")
    set(api_service_srcs
      ${api_service_srcs}
      "${proto_srcs_dir}/${api}.pb.cc"
      "${proto_srcs_dir}/${api}.grpc.pb.cc")
  endif()
endforeach()

add_executable(core_server
   "source/core_server/core_server.cpp"
   "source/core_server/hardware/grpc/core_service.cpp"
   "source/core_server/hardware/grpc/internal/device_enumerator.cpp"
   "source/core_server/hardware/grpc/internal/semaphore.cpp"
   "source/core_server/hardware/grpc/internal/server_configuration_parser.cpp"
   "source/core_server/hardware/grpc/internal/server_security_configuration.cpp"
   "source/core_server/hardware/grpc/internal/session_repository.cpp"
   "source/core_server/hardware/grpc/internal/shared_library.cpp"
   ${server_utilities_proto_srcs}
   ${server_utilities_grpc_srcs}
   ${api_service_srcs})

target_link_libraries(core_server
   ${_REFLECTION}
   ${_GRPC_GRPCPP}
   ${_PROTOBUF_LIBPROTOBUF}
   ${CMAKE_DL_LIBS}
   nlohmann_json::nlohmann_json
   )

if(WIN32)
  target_link_libraries(core_server Delayimp niScope)
  set_target_properties(core_server PROPERTIES LINK_FLAGS "/DELAYLOAD:niScope.dll" )
  set(core_server CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}  /DELAYLOAD:niScope.dll")
endif()

#----------------------------------------------------------------------
# Copy server_config.json to binary output directory
#----------------------------------------------------------------------
add_custom_command(
   TARGET core_server POST_BUILD
   COMMAND  ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_SOURCE_DIR}/source/config/insecure_config.json
            $<TARGET_FILE_DIR:core_server>/server_config.json)

#----------------------------------------------------------------------
# Add JSON parser
#----------------------------------------------------------------------
add_subdirectory(third_party/json ${CMAKE_CURRENT_BINARY_DIR}/json EXCLUDE_FROM_ALL)

# Add googletest tests
enable_testing()
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(third_party/gtest ${CMAKE_CURRENT_BINARY_DIR}/gtest EXCLUDE_FROM_ALL)

# Link test executable against gtest
add_executable(IntegrationTestsRunner
    "source/tests/run_all_tests.cpp"
    "source/tests/integration/core_service_tests.cpp"
    "source/core_server/hardware/grpc/core_service.cpp"
    "source/core_server/hardware/grpc/internal/device_enumerator.cpp"
    "source/core_server/hardware/grpc/internal/semaphore.cpp"
    "source/core_server/hardware/grpc/internal/session_repository.cpp"
    "source/core_server/hardware/grpc/internal/shared_library.cpp"
    ${server_utilities_proto_srcs}
    ${server_utilities_grpc_srcs})

    set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
    set(THREADS_PREFER_PTHREAD_FLAG TRUE)
    find_package(Threads REQUIRED)

target_link_libraries(IntegrationTestsRunner
    gtest
    ${_GRPC_GRPCPP}
    ${CMAKE_DL_LIBS}
    Threads::Threads)

add_library(TestApi SHARED
    "source/tests/utilities/test_api.cpp")
add_compile_definitions(TestApi TEST_API_BUILDING)

# Hardcode ni-fake sources in right now to get it building the unit tests.
add_executable(UnitTestsRunner
    "source/tests/run_all_tests.cpp"
    "source/tests/unit/core_service_tests.cpp"
    "source/tests/unit/device_enumerator_tests.cpp"
    "source/tests/unit/session_repository_tests.cpp"
    "source/tests/unit/server_configuration_parser_tests.cpp"
    "source/tests/unit/server_security_configuration_tests.cpp"
    "source/tests/unit/ni_fake_service_tests.cpp"
    "source/tests/unit/shared_library_tests.cpp"
    "source/core_server/hardware/grpc/core_service.cpp"
    "source/core_server/hardware/grpc/internal/device_enumerator.cpp"
    "source/core_server/hardware/grpc/internal/semaphore.cpp"
    "source/core_server/hardware/grpc/internal/server_configuration_parser.cpp"
    "source/core_server/hardware/grpc/internal/server_security_configuration.cpp"
    "source/core_server/hardware/grpc/internal/session_repository.cpp"
    "source/core_server/hardware/grpc/internal/shared_library.cpp"
    ${server_utilities_proto_srcs}
    ${server_utilities_grpc_srcs}
    "${service_output_dir}/nifake/nifake_service.cpp"
    "${proto_srcs_dir}/nifake.pb.cc"
    "${proto_srcs_dir}/nifake.grpc.pb.cc")

target_include_directories(UnitTestsRunner
    PRIVATE "${service_output_dir}/nifake")

target_link_libraries(UnitTestsRunner
    gtest
    gmock
    ${_GRPC_GRPCPP}
    ${CMAKE_DL_LIBS}
    Threads::Threads
    nlohmann_json::nlohmann_json)

#----------------------------------------------------------------------
# Copy test asset certificates to binary output certs sub-directory
#----------------------------------------------------------------------
add_custom_command(
  TARGET UnitTestsRunner POST_BUILD
  COMMAND  ${CMAKE_COMMAND} -E copy_directory 
           ${CMAKE_SOURCE_DIR}/source/tests/assets/
           $<TARGET_FILE_DIR:core_server>/certs/)
           
add_executable(SystemTestsRunner
    "source/tests/run_all_tests.cpp"
    "source/tests/system/stub_test.cpp")

target_link_libraries(SystemTestsRunner
    gtest
    ${_GRPC_GRPCPP}
    ${CMAKE_DL_LIBS})


# Hook up different google test runners to CTest
# add_test( NAME UnitTests COMMAND UnitTestsRunner )
add_test( NAME UnitTests COMMAND UnitTestsRunner )
add_test( NAME IntegrationTests COMMAND IntegrationTestsRunner )
add_test( NAME SystemTests COMMAND SystemTestsRunner )