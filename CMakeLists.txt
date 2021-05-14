cmake_minimum_required(VERSION 3.12.0)

project(ni_grpc_device_server C CXX)

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
# Use C++17 (needed for shared_mutex support on Linux)
#----------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#----------------------------------------------------------------------
# Find python3 for the build system
#----------------------------------------------------------------------
find_package(Python3 COMPONENTS Interpreter)
if(NOT ${Python3_FOUND})
  message(WARNING "Python3 not found. Python3 is required for code generation.")
endif()

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
set(nidrivers "nidcpower" "nidigital" "nidmm" "nifake" "niscope" "niswitch" "nisync")

#----------------------------------------------------------------------
# Create NI Driver APIs proto and server files
#----------------------------------------------------------------------
set(codegen_scripts
  "${codegen_dir}/common_helpers.py"
  "${codegen_dir}/generate_service.py"
  "${codegen_dir}/service_helpers.py"
  "${codegen_dir}/proto_helpers.py"
  "${codegen_dir}/metadata_mutation.py"
  "${codegen_dir}/templates/library_interface.h.mako"
  "${codegen_dir}/templates/library.cpp.mako"
  "${codegen_dir}/templates/library.h.mako"
  "${codegen_dir}/templates/mock_library.h.mako"
  "${codegen_dir}/templates/proto.mako"
  "${codegen_dir}/templates/proto_helpers.mako"
  "${codegen_dir}/templates/service.cpp.mako"
  "${codegen_dir}/templates/service_helpers.mako"
  "${codegen_dir}/templates/service.h.mako")

# Populated in the api loop below.
set(nidriver_service_srcs "")

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
  set(output_files
    ${service_output_dir}/${api}/${api}_library_interface.h
    ${service_output_dir}/${api}/${api}_library.cpp
    ${service_output_dir}/${api}/${api}_library.h
    ${service_output_dir}/${api}/${api}_mock_library.h
    ${service_output_dir}/${api}/${api}.proto
    ${service_output_dir}/${api}/${api}_service.cpp
    ${service_output_dir}/${api}/${api}_service.h)
  set(gen_command COMMAND ${Python3_EXECUTABLE} ${codegen_dir}/generate_service.py ${metadata_dir}/${api}/ -o ${service_output_dir}/)
  if (NOT api STREQUAL "nifake")
    set(nidriver_service_srcs
      ${nidriver_service_srcs}
      "${service_output_dir}/${api}/${api}_service.cpp"
      "${service_output_dir}/${api}/${api}_library.cpp"
      "${custom_dir}/${api}_service.custom.cpp")
  endif()
  add_custom_command(OUTPUT ${output_files}
    ${gen_command}
    COMMENT "Generating proto file and service for ${api}"
    DEPENDS ${codegen_dependencies} ${codegen_scripts})
endforeach()

#----------------------------------------------------------------------
# Proto file
#----------------------------------------------------------------------
get_filename_component(session_proto "source/protobuf/session.proto" ABSOLUTE)
get_filename_component(session_proto_path "${session_proto}" PATH)

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

foreach(api ${nidrivers})
  GenerateGrpcSources(
    ${service_output_dir}/${api}/${api}.proto
    ${service_output_dir}/${api}/
    "${proto_srcs_dir}/${api}.pb.cc"
    "${proto_srcs_dir}/${api}.pb.h"
    "${proto_srcs_dir}/${api}.grpc.pb.cc"
    "${proto_srcs_dir}/${api}.grpc.pb.h")
  if(NOT api STREQUAL "nifake")
    set(nidriver_service_srcs
      ${nidriver_service_srcs}
      "${proto_srcs_dir}/${api}.pb.cc"
      "${proto_srcs_dir}/${api}.grpc.pb.cc")
  endif()
endforeach()

add_executable(ni_grpc_device_server
   "source/server/core_server.cpp"
   "source/server/device_enumerator.cpp"
   "source/server/logging.cpp"
   "source/server/semaphore.cpp"
   "source/server/server_configuration_parser.cpp"
   "source/server/server_security_configuration.cpp"
   "source/server/session_repository.cpp"
   "source/server/session_utilities_service.cpp"
   "source/server/shared_library.cpp"
   "source/server/syscfg_library.cpp"
   ${session_proto_srcs}
   ${session_grpc_srcs}
   ${nidriver_service_srcs})

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
   )

set_target_properties(ni_grpc_device_server PROPERTIES BUILD_WITH_INSTALL_RPATH TRUE)

if(WIN32)
  target_link_libraries(ni_grpc_device_server Delayimp nidcpower niDigital nidmm niScope niswitch nisync)
  set_target_properties(ni_grpc_device_server PROPERTIES LINK_FLAGS "/DELAYLOAD:nidcpower.dll /DELAYLOAD:niDigital_64.dll /DELAYLOAD:nidmm_64.dll /DELAYLOAD:niScope.dll /DELAYLOAD:niswitch.dll /DELAYLOAD:nisync.dll")
  set(ni_grpc_device_server CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /DELAYLOAD:nidcpower.dll /DELAYLOAD:niDigital_64.dll /DELAYLOAD:nidmm_64.dll /DELAYLOAD:niScope.dll /DELAYLOAD:niswitch.dll /DELAYLOAD:nisync.dll")
endif()

#----------------------------------------------------------------------
# Copy server_config.json to binary output directory
#----------------------------------------------------------------------
add_custom_command(
   TARGET ni_grpc_device_server POST_BUILD
   COMMAND  ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_SOURCE_DIR}/source/config/insecure_config.json
            $<TARGET_FILE_DIR:ni_grpc_device_server>/server_config.json)

#----------------------------------------------------------------------
# Add JSON parser and configure google tests
#----------------------------------------------------------------------
if(CMAKE_CROSSCOMPILING AND NOT _GRPC_DEVICE_NILRT_LEGACY_TOOLCHAIN)
  find_package(nlohmann_json REQUIRED)
  find_library(gtest REQUIRED)
else()
  add_subdirectory(third_party/json ${CMAKE_CURRENT_BINARY_DIR}/json EXCLUDE_FROM_ALL)
  enable_testing()
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  add_subdirectory(third_party/gtest ${CMAKE_CURRENT_BINARY_DIR}/gtest EXCLUDE_FROM_ALL)
endif()

# Link test executable against gtest
add_executable(IntegrationTestsRunner
    "source/tests/utilities/run_all_tests.cpp"
    "source/tests/integration/session_utilities_service_tests.cpp"
    "source/tests/integration/session_utilities_service_tests_endtoend.cpp"
    "source/server/device_enumerator.cpp"
    "source/server/semaphore.cpp"
    "source/server/session_repository.cpp"
    "source/server/session_utilities_service.cpp"
    "source/server/shared_library.cpp"
    ${session_proto_srcs}
    ${session_grpc_srcs})

    set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
    set(THREADS_PREFER_PTHREAD_FLAG TRUE)
    find_package(Threads REQUIRED)

target_link_libraries(IntegrationTestsRunner
    gtest
    gmock
    ${_GRPC_GRPCPP}
    ${CMAKE_DL_LIBS}
    Threads::Threads)

add_library(TestApi SHARED
    "source/tests/utilities/test_api.cpp")
add_compile_definitions(TestApi TEST_API_BUILDING)

add_executable(UnitTestsRunner
    "source/tests/utilities/run_all_tests.cpp"
    "source/tests/unit/session_repository_tests.cpp"
    "source/tests/unit/device_enumerator_tests.cpp"
    "source/tests/unit/server_configuration_parser_tests.cpp"
    "source/tests/unit/server_security_configuration_tests.cpp"
    "source/tests/unit/ni_fake_service_tests.cpp"
    "source/tests/unit/shared_library_tests.cpp"
    "source/tests/unit/syscfg_library_tests.cpp"
    "source/server/device_enumerator.cpp"
    "source/server/semaphore.cpp"
    "source/server/server_configuration_parser.cpp"
    "source/server/server_security_configuration.cpp"
    "source/server/session_repository.cpp"
    "source/server/shared_library.cpp"
    "source/server/syscfg_library.cpp"
    ${session_proto_srcs}
    ${session_grpc_srcs}
    "${service_output_dir}/nifake/nifake_service.cpp"
    "${custom_dir}/nifake_service.custom.cpp"
    "${proto_srcs_dir}/nifake.pb.cc"
    "${proto_srcs_dir}/nifake.grpc.pb.cc")

# ni_fake_service_tests.cpp exceeds the MSVC limit for the number of sections in an obj file defined by PE-COFF.
# This disables that requirement for just the ni_fake_service_tests.cpp file.
if(MSVC)
  set_source_files_properties("source/tests/unit/ni_fake_service_tests.cpp" PROPERTIES COMPILE_FLAGS /bigobj)
endif()

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
           $<TARGET_FILE_DIR:UnitTestsRunner>/)

add_executable(SystemTestsRunner
    "source/tests/utilities/run_all_tests.cpp"
    "source/tests/system/device_server.cpp"
    "source/tests/system/enumerate_devices.cpp"
    "source/tests/system/session_utilities_service_tests.cpp"
    "source/tests/system/nidcpower_driver_api_tests.cpp"
    "source/tests/system/nidcpower_session_tests.cpp"
    "source/tests/system/nidigital_driver_api_tests.cpp"
    "source/tests/system/nidigital_session_tests.cpp"
    "source/tests/system/nidmm_driver_api_tests.cpp"
    "source/tests/system/nidmm_session_tests.cpp"
    "source/tests/system/niscope_driver_api_tests.cpp"
    "source/tests/system/niscope_session_tests.cpp"
    "source/tests/system/niswitch_driver_api_tests.cpp"
    "source/tests/system/niswitch_session_tests.cpp"
    "source/tests/system/nisync_driver_api_tests.cpp"
    "source/tests/system/nisync_session_tests.cpp"
    "source/server/device_enumerator.cpp"
    "source/server/session_repository.cpp"
    "source/server/semaphore.cpp"
    "source/server/session_utilities_service.cpp"
    "source/server/shared_library.cpp"
    "source/server/syscfg_library.cpp"
    ${session_proto_srcs}
    ${session_grpc_srcs}
    ${nidriver_service_srcs})

target_link_libraries(SystemTestsRunner
    gtest
    gmock
    ${_GRPC_GRPCPP}
    ${CMAKE_DL_LIBS})

if(WIN32)
    target_link_libraries(SystemTestsRunner Delayimp nidcpower niDigital nidmm niScope niswitch nisync)
    set_target_properties(SystemTestsRunner PROPERTIES LINK_FLAGS "/DELAYLOAD:nidcpower.dll /DELAYLOAD:niDigital_64.dll /DELAYLOAD:nidmm_64.dll /DELAYLOAD:niScope.dll /DELAYLOAD:niswitch.dll /DELAYLOAD:nisync.dll")
    set(SystemTestsRunner CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}  /DELAYLOAD:nidcpower.dll /DELAYLOAD:niDigital_64.dll /DELAYLOAD:nidmm_64.dll /DELAYLOAD:niScope.dll /DELAYLOAD:niswitch.dll /DELAYLOAD:nisync.dll")
endif()

# Hook up different google test runners to CTest
# add_test( NAME UnitTests COMMAND UnitTestsRunner )
add_test( NAME UnitTests COMMAND UnitTestsRunner )
add_test( NAME IntegrationTests COMMAND IntegrationTestsRunner )
add_test( NAME SystemTests COMMAND SystemTestsRunner )
