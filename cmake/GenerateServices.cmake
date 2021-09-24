#----------------------------------------------------------------------
# Find python3 for the build system
#----------------------------------------------------------------------
find_package(Python3 REQUIRED COMPONENTS Interpreter)

set(metadata_dir ${CMAKE_SOURCE_DIR}/source/codegen/metadata)
set(service_output_dir ${CMAKE_SOURCE_DIR}/generated)
set(codegen_dir ${CMAKE_SOURCE_DIR}/source/codegen)
set(custom_dir ${CMAKE_SOURCE_DIR}/source/custom)

#----------------------------------------------------------------------
# Create NI Driver APIs proto and server files
#----------------------------------------------------------------------
set(codegen_scripts
  "${codegen_dir}/client_helpers.py"
  "${codegen_dir}/cmake_helpers.py"
  "${codegen_dir}/common_helpers.py"
  "${codegen_dir}/generate_service.py"
  "${codegen_dir}/service_helpers.py"
  "${codegen_dir}/proto_helpers.py"
  "${codegen_dir}/metadata_mutation.py"
  "${codegen_dir}/templates/client.cpp.mako"
  "${codegen_dir}/templates/client.h.mako"
  "${codegen_dir}/templates/client_helpers.mako"
  "${codegen_dir}/templates/cmake_lists.mako"
  "${codegen_dir}/templates/library_interface.h.mako"
  "${codegen_dir}/templates/library.cpp.mako"
  "${codegen_dir}/templates/library.h.mako"
  "${codegen_dir}/templates/mock_library.h.mako"
  "${codegen_dir}/templates/proto.mako"
  "${codegen_dir}/templates/proto_helpers.mako"
  "${codegen_dir}/templates/service.cpp.mako"
  "${codegen_dir}/templates/service_helpers.mako"
  "${codegen_dir}/templates/service.h.mako")


function (GenerateServices module_name metadata_files output_files)
  set(gen_command COMMAND ${Python3_EXECUTABLE} ${codegen_dir}/generate_service.py ${metadata_dir}/${module_name}/ -o ${service_output_dir}/)
  add_custom_command(OUTPUT ${output_files}
    ${gen_command}
    COMMENT "Generating proto file and service for ${module_name}"
    DEPENDS ${metadata_files} ${codegen_scripts})
endfunction()


function(GenerateServiceCMakeLists)
  execute_process(
    COMMAND ${Python3_EXECUTABLE} ${codegen_dir}/generate_cmake_lists.py ${metadata_dir}/ -o ${service_output_dir}/)
endfunction()