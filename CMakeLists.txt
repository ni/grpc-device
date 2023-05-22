cmake_minimum_required(VERSION 3.12.0)

project(ni_grpc_device_server
  LANGUAGES C CXX
  VERSION 2.2.0)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(CreateVirtualEnvironment)

# Workaround for: https://bugs.chromium.org/p/boringssl/issues/detail?id=423
if (CMAKE_SYSTEM_PROCESSOR STREQUAL "AMD64")
  set(CMAKE_SYSTEM_PROCESSOR "amd64")
endif()

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
    add_subdirectory(third_party/grpc ${CMAKE_CURRENT_BINARY_DIR}/grpc EXCLUDE_FROM_ALL)
    set(_REFLECTION grpc++_reflection)
    set(_GRPC_GRPCPP grpc++)
    set(_PROTOBUF_LIBPROTOBUF libprotobuf)
  endif()

else()
  add_subdirectory(third_party/grpc ${CMAKE_CURRENT_BINARY_DIR}/grpc EXCLUDE_FROM_ALL)
  set(_PROTOBUF_PROTOC $<TARGET_FILE:protobuf::protoc>)
  set(_REFLECTION grpc++_reflection)
  set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:grpc_cpp_plugin>)
  set(_GRPC_GRPCPP grpc++)
  set(_PROTOBUF_LIBPROTOBUF libprotobuf)
endif()

#----------------------------------------------------------------------
CreateVirtualEnvironment(virtual_environment
  REQUIREMENTS_TXT
    ${CMAKE_SOURCE_DIR}/python_build_requirements.txt
  ENV_NAME
    venv
  OUT_PYTHON_EXE
    PYTHON_EXE
)

#----------------------------------------------------------------------
# Use the utfcpp targets directly from this build, only when not cross-compiling.
#----------------------------------------------------------------------
if(CMAKE_CROSSCOMPILING AND NOT _GRPC_DEVICE_NILRT_LEGACY_TOOLCHAIN)
  find_package(utf8cpp REQUIRED)
else()
  add_subdirectory(third_party/utfcpp ${CMAKE_CURRENT_BINARY_DIR}/utfcpp EXCLUDE_FROM_ALL)
endif()
include_directories(
  "./third_party/utfcpp/source"
)

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
  "./imports/include"
  "./source"
)
if(WIN32)
  link_directories("./imports/lib/win64")
endif()

#----------------------------------------------------------------------
# Get list of NI Driver APIs and directories to generate from
#----------------------------------------------------------------------
set(metadata_dir ${CMAKE_SOURCE_DIR}/source/codegen/metadata)
set(service_output_dir ${CMAKE_SOURCE_DIR}/generated)
set(codegen_dir ${CMAKE_SOURCE_DIR}/source/codegen)
set(custom_dir ${CMAKE_SOURCE_DIR}/source/custom)
set(nidrivers "nidaqmx" "nidcpower" "nidigitalpattern" "nidmm" "nifake" "nifake_extension" "nifake_non_ivi" "nifgen" "nimxlcterminaladaptor_restricted" "nirfmxbluetooth" "nirfmxcdma2k" "nirfmxgsm" "nirfmxinstr" "nirfmxinstr_restricted" "nirfmxlte" "nirfmxnr" "nirfmxspecan" "nirfmxspecan_restricted" "nirfmxtdscdma" "nirfmxwcdma" "nirfmxdemod" "nirfmxwlan" "nirfmxwlan_restricted" "nirfsa" "nirfsg" "niscope" "niscope_restricted" "niswitch" "nisync" "nitclk" "nixnet" "nixnetsocket")

#----------------------------------------------------------------------
# Create NI Driver APIs proto and server files
#----------------------------------------------------------------------
set(codegen_scripts
  "${codegen_dir}/client_helpers.py"
  "${codegen_dir}/common_helpers.py"
  "${codegen_dir}/generate_service.py"
  "${codegen_dir}/generate_shared_service_files.py"
  "${codegen_dir}/service_helpers.py"
  "${codegen_dir}/proto_helpers.py"
  "${codegen_dir}/metadata_mutation.py"
  "${codegen_dir}/metadata_validation.py"
  "${codegen_dir}/template_helpers.py"
  "${codegen_dir}/templates/client.cpp.mako"
  "${codegen_dir}/templates/client.h.mako"
  "${codegen_dir}/templates/client_helpers.mako"
  "${codegen_dir}/templates/library_interface.h.mako"
  "${codegen_dir}/templates/library.cpp.mako"
  "${codegen_dir}/templates/library.h.mako"
  "${codegen_dir}/templates/mock_library.h.mako"
  "${codegen_dir}/templates/proto.mako"
  "${codegen_dir}/templates/proto_helpers.mako"
  "${codegen_dir}/templates/register_all_services.h.mako"
  "${codegen_dir}/templates/register_all_services.cpp.mako"
  "${codegen_dir}/templates/service.cpp.mako"
  "${codegen_dir}/templates/service_helpers.mako"
  "${codegen_dir}/templates/service.h.mako"
  "${codegen_dir}/templates/service_registrar.h.mako"
  "${codegen_dir}/templates/service_registrar.cpp.mako"
  )

# Populated in the api loop below.
set(nidriver_service_library_hdrs "")
set(nidriver_service_srcs "")
set(nidriver_client_srcs "")

# We'll codegen all drivers, but some are not included in the server build.
set(nidrivers_to_build ${nidrivers})
# Fake drivers are not in the server and are added manually to the UnitTestRunner build.
list(FILTER nidrivers_to_build EXCLUDE REGEX "^nifake.*")
if (NOT WIN32)
  # None of the RFmx drivers support Linux and building against the headers fails.
  # Exclude them on Linux.
  list(FILTER nidrivers_to_build EXCLUDE REGEX "^nirfmx.*")
endif()

set(all_codegen_dependencies "")

foreach(api ${nidrivers})
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
  if (EXISTS "${metadata_dir}/${api}/custom_proto.mako")
    set(codegen_dependencies ${codegen_dependencies} "${metadata_dir}/${api}/custom_proto.mako")
  endif()
  set(all_codegen_dependencies
    ${all_codegen_dependencies}
    ${codegen_dependencies}
  )

  set(output_files
    ${service_output_dir}/${api}/${api}_client.cpp
    ${service_output_dir}/${api}/${api}_client.h
    ${service_output_dir}/${api}/${api}_compilation_test.cpp
    ${service_output_dir}/${api}/${api}_library_interface.h
    ${service_output_dir}/${api}/${api}_library.cpp
    ${service_output_dir}/${api}/${api}_library.h
    ${service_output_dir}/${api}/${api}_mock_library.h
    ${service_output_dir}/${api}/${api}.proto
    ${service_output_dir}/${api}/${api}_service.cpp
    ${service_output_dir}/${api}/${api}_service.h
    ${service_output_dir}/${api}/${api}_service_registrar.cpp
    ${service_output_dir}/${api}/${api}_service_registrar.h
  )
  set(nidriver_service_library_hdrs
    ${nidriver_service_library_hdrs}
    "${service_output_dir}/${api}/${api}_library.h"
    "${service_output_dir}/${api}/${api}_library_interface.h"
    "${service_output_dir}/${api}/${api}_mock_library.h")
  set(gen_command COMMAND ${PYTHON_EXE} ${codegen_dir}/generate_service.py ${metadata_dir}/${api}/ -o ${service_output_dir}/)
  if (api IN_LIST nidrivers_to_build)
    set(nidriver_service_srcs
      ${nidriver_service_srcs}
      "${service_output_dir}/${api}/${api}_service.cpp"
      "${service_output_dir}/${api}/${api}_service_registrar.cpp"
      "${service_output_dir}/${api}/${api}_library.cpp"
      "${custom_dir}/${api}_service.custom.cpp")
    set(nidriver_client_srcs
      ${nidriver_client_srcs}
      "${service_output_dir}/${api}/${api}_client.cpp")
  endif()
  set(proto_dependencies ${codegen_dependencies} ${codegen_scripts} virtual_environment)
  add_custom_command(OUTPUT ${output_files}
    ${gen_command}
    COMMENT "Generating proto file and service for ${api}"
    DEPENDS ${proto_dependencies})
  add_custom_target(generate_proto_and_service_target_for_${api}
    DEPENDS ${output_files})
endforeach()

add_custom_command(
  OUTPUT
    ${service_output_dir}/register_all_services.cpp
    ${service_output_dir}/register_all_services.h
  COMMAND
    ${PYTHON_EXE} ${codegen_dir}/generate_shared_service_files.py ${metadata_dir}/ -o ${service_output_dir}/
  COMMENT
    "Generating shared service files"
  DEPENDS
    ${all_codegen_dependencies}
    ${codegen_scripts}
    virtual_environment
)

set(nidriver_service_srcs
    ${nidriver_service_srcs}
    ${service_output_dir}/register_all_services.cpp
)

#----------------------------------------------------------------------
# Proto file
#----------------------------------------------------------------------
get_filename_component(session_proto "imports/protobuf/session.proto" ABSOLUTE)
get_filename_component(session_utilities_proto "source/protobuf/session_utilities.proto" ABSOLUTE)
get_filename_component(nidevice_proto "imports/protobuf/nidevice.proto" ABSOLUTE)
get_filename_component(deviceid_restricted_proto "source/protobuf_restricted/deviceid_restricted.proto" ABSOLUTE)
get_filename_component(debugsessionproperties_restricted_proto "source/protobuf_restricted/debugsessionproperties_restricted.proto" ABSOLUTE)
get_filename_component(calibrationoperations_restricted_proto "source/protobuf_restricted/calibrationoperations_restricted.proto" ABSOLUTE)
get_filename_component(session_proto_path "${session_proto}" PATH)

#----------------------------------------------------------------------
# Generate sources from proto files
# Usage: GenerateGrpcSources(PROTO <path> OUTPUT <path>...)
#----------------------------------------------------------------------
function(GenerateGrpcSources)
  set(oneValueArgs PROTO)
  set(multiValueArgs OUTPUT)
  cmake_parse_arguments(GENERATE_ARGS "" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})
  set(output_files "${GENERATE_ARGS_OUTPUT}")
  set(proto_file "${GENERATE_ARGS_PROTO}")
  get_filename_component(proto_path "${proto_file}" PATH)
  # Asssumption: all outputs are in the same directory: use the zero-th.
  list(GET output_files 0 proto_srcs)
  get_filename_component(proto_out_path "${proto_srcs}" PATH)
  add_custom_command(
    OUTPUT ${output_files}
    COMMAND ${_PROTOBUF_PROTOC}
    ARGS --grpc_out "${proto_out_path}"
      --cpp_out "${proto_out_path}"
      -I "${proto_path}"
      -I ${CMAKE_SOURCE_DIR}/third_party/grpc/third_party/protobuf/src/
      -I ${CMAKE_SOURCE_DIR}/imports/protobuf
      --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
      "${proto_file}"
    DEPENDS "${proto_file}" "${session_proto}")
endfunction()

set(session_proto_srcs "${proto_srcs_dir}/session.pb.cc")
set(session_proto_hdrs "${proto_srcs_dir}/session.pb.h")
set(session_grpc_srcs "${proto_srcs_dir}/session.grpc.pb.cc")
set(session_grpc_hdrs "${proto_srcs_dir}/session.grpc.pb.h")
set(session_utilities_proto_srcs "${proto_srcs_dir}/session_utilities.pb.cc")
set(session_utilities_proto_hdrs "${proto_srcs_dir}/session_utilities.pb.h")
set(session_utilities_grpc_srcs "${proto_srcs_dir}/session_utilities.grpc.pb.cc")
set(session_utilities_grpc_hdrs "${proto_srcs_dir}/session_utilities.grpc.pb.h")
set(nidevice_proto_srcs "${proto_srcs_dir}/nidevice.pb.cc")
set(nidevice_proto_hdrs "${proto_srcs_dir}/nidevice.pb.h")
set(deviceid_restricted_proto_srcs "${proto_srcs_dir}/deviceid_restricted.pb.cc")
set(deviceid_restricted_proto_hdrs "${proto_srcs_dir}/deviceid_restricted.pb.h")
set(deviceid_restricted_grpc_srcs "${proto_srcs_dir}/deviceid_restricted.grpc.pb.cc")
set(deviceid_restricted_grpc_hdrs "${proto_srcs_dir}/deviceid_restricted.grpc.pb.h")
set(debugsessionproperties_restricted_proto_srcs "${proto_srcs_dir}/debugsessionproperties_restricted.pb.cc")
set(debugsessionproperties_restricted_proto_hdrs "${proto_srcs_dir}/debugsessionproperties_restricted.pb.h")
set(debugsessionproperties_restricted_grpc_srcs "${proto_srcs_dir}/debugsessionproperties_restricted.grpc.pb.cc")
set(debugsessionproperties_restricted_grpc_hdrs "${proto_srcs_dir}/debugsessionproperties_restricted.grpc.pb.h")
set(calibrationoperations_restricted_proto_srcs "${proto_srcs_dir}/calibrationoperations_restricted.pb.cc")
set(calibrationoperations_restricted_proto_hdrs "${proto_srcs_dir}/calibrationoperations_restricted.pb.h")
set(calibrationoperations_restricted_grpc_srcs "${proto_srcs_dir}/calibrationoperations_restricted.grpc.pb.cc")
set(calibrationoperations_restricted_grpc_hdrs "${proto_srcs_dir}/calibrationoperations_restricted.grpc.pb.h")

GenerateGrpcSources(
  PROTO
    ${session_proto}
  OUTPUT
    "${session_proto_srcs}"
    "${session_proto_hdrs}"
    "${session_grpc_srcs}"
    "${session_grpc_hdrs}"
)

GenerateGrpcSources(
  PROTO
    ${session_utilities_proto}
  OUTPUT
    "${session_utilities_proto_srcs}"
    "${session_utilities_proto_hdrs}"
    "${session_utilities_grpc_srcs}"
    "${session_utilities_grpc_hdrs}"
)

GenerateGrpcSources(
  PROTO
    ${nidevice_proto}
  OUTPUT
    "${nidevice_proto_srcs}"
    "${nidevice_proto_hdrs}"
)

GenerateGrpcSources(
  PROTO
    ${deviceid_restricted_proto}
  OUTPUT
    "${deviceid_restricted_proto_srcs}"
    "${deviceid_restricted_proto_hdrs}"
    "${deviceid_restricted_grpc_srcs}"
    "${deviceid_restricted_grpc_hdrs}"
)

GenerateGrpcSources(
  PROTO
    ${debugsessionproperties_restricted_proto}
  OUTPUT
    "${debugsessionproperties_restricted_proto_srcs}"
    "${debugsessionproperties_restricted_proto_hdrs}"
    "${debugsessionproperties_restricted_grpc_srcs}"
    "${debugsessionproperties_restricted_grpc_hdrs}"
)

GenerateGrpcSources(
  PROTO
    ${calibrationoperations_restricted_proto}
  OUTPUT
    "${calibrationoperations_restricted_proto_srcs}"
    "${calibrationoperations_restricted_proto_hdrs}"
    "${calibrationoperations_restricted_grpc_srcs}"
    "${calibrationoperations_restricted_grpc_hdrs}"
)

set(nidriver_service_library_hdrs
  ${nidriver_service_library_hdrs}
  "${session_proto_hdrs}"
  "${session_grpc_hdrs}"
  "${session_utilities_proto_hdrs}"
  "${session_utilities_grpc_hdrs}"
  "${nidevice_proto_hdrs}"
  "${deviceid_restricted_proto_hdrs}"
  "${deviceid_restricted_grpc_hdrs}"
  "${debugsessionproperties_restricted_proto_hdrs}"
  "${debugsessionproperties_restricted_grpc_hdrs}"
  "${calibrationoperations_restricted_proto_hdrs}"
  "${calibrationoperations_restricted_grpc_hdrs}"
)

foreach(api ${nidrivers})
  GenerateGrpcSources(
    PROTO
      ${service_output_dir}/${api}/${api}.proto
    OUTPUT
      "${proto_srcs_dir}/${api}.pb.cc"
      "${proto_srcs_dir}/${api}.pb.h"
      "${proto_srcs_dir}/${api}.grpc.pb.cc"
      "${proto_srcs_dir}/${api}.grpc.pb.h"
  )
  set(nidriver_service_library_hdrs
    ${nidriver_service_library_hdrs}
    "${proto_srcs_dir}/${api}.pb.h"
    "${proto_srcs_dir}/${api}.grpc.pb.h")
  if(api IN_LIST nidrivers_to_build)
    set(nidriver_service_srcs
      ${nidriver_service_srcs}
      "${proto_srcs_dir}/${api}.pb.cc"
      "${proto_srcs_dir}/${api}.grpc.pb.cc")
  endif()
endforeach()

add_executable(ni_grpc_device_server
   "imports/include/nierr_Status.cpp"
   "source/server/calibration_operations_restricted_service_registrar.cpp"
   "source/server/calibration_operations_restricted_service.cpp"
   "source/server/core_server.cpp"
   "source/server/core_services_registrar.cpp"
   "source/server/debug_session_properties_restricted_service_registrar.cpp"
   "source/server/debug_session_properties_restricted_service.cpp"
   "source/server/device_enumerator.cpp"
   "source/server/feature_toggles.cpp"
   "source/server/logging.cpp"
   "source/server/semaphore.cpp"
   "source/server/server_configuration_parser.cpp"
   "source/server/server_security_configuration.cpp"
   "source/server/session_repository.cpp"
   "source/server/session_utilities_service.cpp"
   "source/server/session_utilities_service_registrar.cpp"
   "source/server/shared_library.cpp"
   "source/server/software_enumerator.cpp"
   "source/server/syscfg_library.cpp"
   "source/server/syscfg_resource_accessor.cpp"
   "source/server/syscfg_session_handler.cpp"
   ${nidevice_proto_srcs}
   ${session_proto_srcs}
   ${session_grpc_srcs}
   ${session_utilities_proto_srcs}
   ${session_utilities_grpc_srcs}
   ${deviceid_restricted_proto_srcs}
   ${deviceid_restricted_grpc_srcs}
   ${debugsessionproperties_restricted_proto_srcs}
   ${debugsessionproperties_restricted_grpc_srcs}
   ${calibrationoperations_restricted_proto_srcs}
   ${calibrationoperations_restricted_grpc_srcs}
   ${nidriver_service_srcs})

if(WIN32)
  set(version_generated_dir "${CMAKE_CURRENT_BINARY_DIR}/version")
  file(MAKE_DIRECTORY ${version_generated_dir})

  # Generate version resource file for Windows
  configure_file(
    source/server/version.rc.in
    ${version_generated_dir}/version.rc
    @ONLY)

  target_sources(ni_grpc_device_server
    PRIVATE "${version_generated_dir}/version.rc"
  )
endif()

if(CMAKE_SYSTEM_NAME STREQUAL Linux)
  target_sources(ni_grpc_device_server
    PRIVATE "source/server/linux/syslog_logging.cpp"
    PRIVATE "source/server/linux/daemonize.cpp")
endif()

target_link_libraries(ni_grpc_device_server
   ${_REFLECTION}
   ${_GRPC_GRPCPP}
   ${_PROTOBUF_LIBPROTOBUF}
   ${CMAKE_DL_LIBS}
   nlohmann_json::nlohmann_json
   utf8cpp
   )

set_target_properties(ni_grpc_device_server PROPERTIES BUILD_WITH_INSTALL_RPATH TRUE)

#----------------------------------------------------------------------
# Copy server_config.json to binary output directory
#----------------------------------------------------------------------
add_custom_command(
   TARGET ni_grpc_device_server POST_BUILD
   COMMAND  ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_SOURCE_DIR}/source/config/localhost_config.json
            $<TARGET_FILE_DIR:ni_grpc_device_server>/server_config.json)

#----------------------------------------------------------------------
# Generate server_capabilities.json to binary output directory
#----------------------------------------------------------------------
add_custom_command(
   TARGET ni_grpc_device_server POST_BUILD
   COMMAND  ${PYTHON_EXE} ${codegen_dir}/generate_server_capabilities.py ${metadata_dir}/
            -o $<TARGET_FILE_DIR:ni_grpc_device_server>/)


#----------------------------------------------------------------------
# Add JSON parser and configure google tests
#----------------------------------------------------------------------
if(CMAKE_CROSSCOMPILING AND NOT _GRPC_DEVICE_NILRT_LEGACY_TOOLCHAIN)
  find_package(nlohmann_json REQUIRED)
  find_package(GTest REQUIRED)
else()
  add_subdirectory(third_party/json ${CMAKE_CURRENT_BINARY_DIR}/json EXCLUDE_FROM_ALL)
  enable_testing()
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  add_subdirectory(third_party/gtest ${CMAKE_CURRENT_BINARY_DIR}/gtest EXCLUDE_FROM_ALL)
endif()

# Link test executable against gtest
add_executable(IntegrationTestsRunner
    "source/tests/utilities/run_all_tests.cpp"
    "source/tests/integration/ni_fake_service_tests_endtoend.cpp"
    "source/tests/integration/ni_fake_non_ivi_service_tests_endtoend.cpp"
    "source/tests/integration/session_utilities_service_tests.cpp"
    "source/tests/integration/session_utilities_service_tests_endtoend.cpp"
    "source/server/device_enumerator.cpp"
    "source/server/feature_toggles.cpp"
    "source/server/semaphore.cpp"
    "source/server/session_repository.cpp"
    "source/server/session_utilities_service.cpp"
    "source/server/shared_library.cpp"
    "source/server/software_enumerator.cpp"
    "source/server/syscfg_session_handler.cpp"
    ${nidevice_proto_srcs}
    ${session_proto_srcs}
    ${session_grpc_srcs}
    ${session_utilities_proto_srcs}
    ${session_utilities_grpc_srcs}
    ${deviceid_restricted_proto_srcs}
    ${deviceid_restricted_grpc_srcs}
    ${debugsessionproperties_restricted_proto_srcs}
    ${debugsessionproperties_restricted_grpc_srcs}
    ${calibrationoperations_restricted_proto_srcs}
    ${calibrationoperations_restricted_grpc_srcs}
    "${proto_srcs_dir}/nifake.pb.cc"
    "${proto_srcs_dir}/nifake.grpc.pb.cc"
    "${proto_srcs_dir}/nifake_non_ivi.pb.cc"
    "${proto_srcs_dir}/nifake_non_ivi.grpc.pb.cc"
    "${service_output_dir}/nifake/nifake_client.cpp"
    "${service_output_dir}/nifake/nifake_service.cpp"
    "${service_output_dir}/nifake_non_ivi/nifake_non_ivi_client.cpp"
    "${service_output_dir}/nifake_non_ivi/nifake_non_ivi_service.cpp"
    "${custom_dir}/nifake_non_ivi_service.custom.cpp"
    "${custom_dir}/nifake_service.custom.cpp"
)

    set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
    set(THREADS_PREFER_PTHREAD_FLAG TRUE)
    find_package(Threads REQUIRED)

target_link_libraries(IntegrationTestsRunner
    gtest
    gmock
    ${_GRPC_GRPCPP}
    ${CMAKE_DL_LIBS}
    Threads::Threads
    nlohmann_json::nlohmann_json)

add_library(TestApi SHARED
    "source/tests/utilities/test_api.cpp")
add_compile_definitions(TestApi TEST_API_BUILDING)

add_executable(UnitTestsRunner
    "imports/include/nierr_Status.cpp"
    "source/tests/utilities/run_all_tests.cpp"
    "source/tests/unit/callback_router_tests.cpp"
    "source/tests/unit/converters_tests.cpp"
    "source/tests/unit/session_resource_repository_tests.cpp"
    "source/tests/unit/session_repository_tests.cpp"
    "source/tests/unit/calibration_operations_tests.cpp"
    "source/tests/unit/debug_session_properties_tests.cpp"
    "source/tests/unit/device_enumerator_tests.cpp"
    "source/tests/unit/software_enumerator_tests.cpp"
    "source/tests/unit/server_configuration_parser_tests.cpp"
    "source/tests/unit/server_security_configuration_tests.cpp"
    "source/tests/unit/ni_fake_non_ivi_service_tests.cpp"
    "source/tests/unit/ni_fake_service_tests.cpp"
    "source/tests/unit/nimxlc_terminal_adaptor_converters_tests.cpp"
    "source/tests/unit/shared_library_tests.cpp"
    "source/tests/unit/syscfg_library_tests.cpp"
    "source/tests/unit/syscfg_resource_accessor_tests.cpp"
    "source/tests/unit/xnet_converters_tests.cpp"
    "source/tests/unit/xnet_socket_converters_tests.cpp"
    "source/server/calibration_operations_restricted_service.cpp"
    "source/server/debug_session_properties_restricted_service.cpp"
    "source/server/device_enumerator.cpp"
    "source/server/feature_toggles.cpp"
    "source/server/semaphore.cpp"
    "source/server/server_configuration_parser.cpp"
    "source/server/server_security_configuration.cpp"
    "source/server/session_repository.cpp"
    "source/server/shared_library.cpp"
    "source/server/software_enumerator.cpp"
    "source/server/syscfg_library.cpp"
    "source/server/syscfg_resource_accessor.cpp"
    "source/server/syscfg_session_handler.cpp"
    ${nidevice_proto_srcs}
    ${session_proto_srcs}
    ${session_grpc_srcs}
    ${session_utilities_proto_srcs}
    ${session_utilities_grpc_srcs}
    ${deviceid_restricted_proto_srcs}
    ${deviceid_restricted_grpc_srcs}
    ${debugsessionproperties_restricted_proto_srcs}
    ${debugsessionproperties_restricted_grpc_srcs}
    ${calibrationoperations_restricted_proto_srcs}
    ${calibrationoperations_restricted_grpc_srcs}
    "${proto_srcs_dir}/nifake.pb.cc"
    "${proto_srcs_dir}/nifake.grpc.pb.cc"
    "${proto_srcs_dir}/nifake_extension.pb.cc"
    "${proto_srcs_dir}/nifake_extension.grpc.pb.cc"
    "${proto_srcs_dir}/nifake_non_ivi.pb.cc"
    "${proto_srcs_dir}/nifake_non_ivi.grpc.pb.cc"
    "${proto_srcs_dir}/nimxlcterminaladaptor_restricted.pb.cc"
    "${proto_srcs_dir}/nixnet.grpc.pb.cc"
    "${proto_srcs_dir}/nixnet.pb.cc"
    "${proto_srcs_dir}/nixnetsocket.pb.cc"
    "${service_output_dir}/nifake/nifake_service.cpp"
    "${service_output_dir}/nifake_extension/nifake_extension_service.cpp"
    "${service_output_dir}/nifake_non_ivi/nifake_non_ivi_service.cpp"
    "${service_output_dir}/nixnet/nixnet_service.cpp"
    "${custom_dir}/nifake_service.custom.cpp"
    "${custom_dir}/nifake_extension_service.custom.cpp"
    "${custom_dir}/nifake_non_ivi_service.custom.cpp"
    "${custom_dir}/nimxlcterminaladaptor_restricted_service.custom.cpp"
    "${custom_dir}/nixnet_service.custom.cpp"
)

# ni_fake_service_tests.cpp and several DAQ cpp files exceed the MSVC limit for the number of sections
# in an obj file defined by PE-COFF. This line disables the limit.
if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj /D_SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING")
endif(MSVC)

target_include_directories(UnitTestsRunner
    PRIVATE "${service_output_dir}/nifake"
    PRIVATE "${service_output_dir}/nifake_extension"
    PRIVATE "${service_output_dir}/nifake_non_ivi")

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
           $<TARGET_FILE_DIR:UnitTestsRunner>/)

foreach(api ${nidrivers_to_build})
  set(compilation_test_sources
    ${compilation_test_sources}
    "${service_output_dir}/${api}/${api}_compilation_test.cpp")
endforeach()
add_library(CompilationTests STATIC ${compilation_test_sources})
target_link_libraries(CompilationTests
    ${_GRPC_GRPCPP}
)
add_custom_target(generated_nidriver_service_library_hdrs DEPENDS ${nidriver_service_library_hdrs})
add_dependencies(CompilationTests generated_nidriver_service_library_hdrs)

set(system_test_runner_sources
  "imports/include/nierr_Status.cpp"
  "source/tests/utilities/run_all_tests.cpp"
  "source/server/core_services_registrar.cpp"
  "source/tests/system/device_server.cpp"
  "source/tests/system/enumerate_devices.cpp"
  "source/tests/system/enumerate_software.cpp"
  "source/tests/system/session_utilities_service_tests.cpp"
  "source/tests/system/nidaqmx_driver_api_tests.cpp"
  "source/tests/system/nidaqmx_session_tests.cpp"
  "source/tests/system/nidcpower_driver_api_tests.cpp"
  "source/tests/system/nidcpower_session_tests.cpp"
  "source/tests/system/nidigital_driver_api_tests.cpp"
  "source/tests/system/nidigital_session_tests.cpp"
  "source/tests/system/nidmm_driver_api_tests.cpp"
  "source/tests/system/nidmm_session_tests.cpp"
  "source/tests/system/nifgen_driver_api_tests.cpp"
  "source/tests/system/nifgen_session_tests.cpp"
  "source/tests/system/nirfsa_driver_api_tests.cpp"
  "source/tests/system/nirfsg_driver_api_tests.cpp"
  "source/tests/system/nirfsg_session_tests.cpp"
  "source/tests/system/niscope_driver_api_tests.cpp"
  "source/tests/system/niscope_restricted_driver_api_tests.cpp"
  "source/tests/system/niscope_session_tests.cpp"
  "source/tests/system/niswitch_driver_api_tests.cpp"
  "source/tests/system/niswitch_session_tests.cpp"
  "source/tests/system/nisync_driver_api_tests.cpp"
  "source/tests/system/nisync_session_tests.cpp"
  "source/tests/system/nitclk_driver_api_tests.cpp"
  "source/tests/system/nixnet_lin_driver_api_tests.cpp"
  "source/tests/system/nixnet_can_driver_api_tests.cpp"
  "source/tests/system/nixnet_ethernet_driver_api_tests.cpp"
  "source/tests/system/nixnetsocket_driver_api_tests.cpp"
  "source/server/calibration_operations_restricted_service_registrar.cpp"
  "source/server/calibration_operations_restricted_service.cpp"
  "source/server/debug_session_properties_restricted_service_registrar.cpp"
  "source/server/debug_session_properties_restricted_service.cpp"
  "source/server/device_enumerator.cpp"
  "source/server/feature_toggles.cpp"
  "source/server/semaphore.cpp"
  "source/server/session_repository.cpp"
  "source/server/session_utilities_service.cpp"
  "source/server/session_utilities_service_registrar.cpp"
  "source/server/shared_library.cpp"
  "source/server/software_enumerator.cpp"
  "source/server/syscfg_library.cpp"
  "source/server/syscfg_resource_accessor.cpp"
  "source/server/syscfg_session_handler.cpp"
  ${nidevice_proto_srcs}
  ${session_proto_srcs}
  ${session_grpc_srcs}
  ${session_utilities_proto_srcs}
  ${session_utilities_grpc_srcs}
  ${deviceid_restricted_proto_srcs}
  ${deviceid_restricted_grpc_srcs}
  ${debugsessionproperties_restricted_proto_srcs}
  ${debugsessionproperties_restricted_grpc_srcs}
  ${calibrationoperations_restricted_proto_srcs}
  ${calibrationoperations_restricted_grpc_srcs}
  ${nidriver_service_srcs}
  ${nidriver_client_srcs}
)

if(WIN32)
  list(
    APPEND
      system_test_runner_sources
        "source/tests/system/nimxlcterminaladaptor_restricted_driver_api_tests.cpp"
        "source/tests/system/nirfmxbluetooth_driver_api_tests.cpp"
        "source/tests/system/nirfmxbluetooth_session_tests.cpp"
        "source/tests/system/nirfmxcdma2k_driver_api_tests.cpp"
        "source/tests/system/nirfmxcdma2k_session_tests.cpp"
        "source/tests/system/nirfmxgsm_driver_api_tests.cpp"
        "source/tests/system/nirfmxgsm_session_tests.cpp"
        "source/tests/system/nirfmxinstr_driver_api_tests.cpp"
        "source/tests/system/nirfmxinstr_restricted_driver_api_tests.cpp"
        "source/tests/system/nirfmxlte_driver_api_tests.cpp"
        "source/tests/system/nirfmxlte_session_tests.cpp"
        "source/tests/system/nirfmxnr_driver_api_tests.cpp"
        "source/tests/system/nirfmxnr_session_tests.cpp"
        "source/tests/system/nirfmxspecan_driver_api_tests.cpp"
        "source/tests/system/nirfmxspecan_restricted_driver_api_tests.cpp"
        "source/tests/system/nirfmxspecan_session_tests.cpp"
        "source/tests/system/nirfmxtdscdma_driver_api_tests.cpp"
        "source/tests/system/nirfmxtdscdma_session_tests.cpp"
        "source/tests/system/nirfmxwcdma_driver_api_tests.cpp"
        "source/tests/system/nirfmxwcdma_session_tests.cpp"
        "source/tests/system/nirfmxdemod_driver_api_tests.cpp"
        "source/tests/system/nirfmxdemod_session_tests.cpp"
        "source/tests/system/nirfmxwlan_driver_api_tests.cpp"
        "source/tests/system/nirfmxwlan_restricted_driver_api_tests.cpp"
        "source/tests/system/nirfmxwlan_session_tests.cpp"
  )
endif()

add_executable(SystemTestsRunner ${system_test_runner_sources})

target_link_libraries(SystemTestsRunner
    gtest
    gmock
    ${_GRPC_GRPCPP}
    ${CMAKE_DL_LIBS}
    nlohmann_json::nlohmann_json
)

add_custom_command(
  TARGET SystemTestsRunner POST_BUILD
  COMMAND  ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/source/tests/assets/data/
            $<TARGET_FILE_DIR:SystemTestsRunner>/)

if(_GRPC_DEVICE_NILRT_LEGACY_TOOLCHAIN)
    target_link_libraries(SystemTestsRunner stdc++fs)
    target_compile_definitions(SystemTestsRunner PRIVATE FS_EXPERIMENTAL)
endif()


# Hook up different google test runners to CTest
# add_test( NAME UnitTests COMMAND UnitTestsRunner )
add_test( NAME UnitTests COMMAND UnitTestsRunner )
add_test( NAME IntegrationTests COMMAND IntegrationTestsRunner )
add_test( NAME SystemTests COMMAND SystemTestsRunner )
