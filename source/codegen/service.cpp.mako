// This file was generated
<%
import re
import codegen_helpers
import handler_helpers
attributes = data['attributes']
config = data['config']
enums = data['enums']
functions = data['functions']

## TODO: Pull niFake from config metadata.
driver_prefix = "niFake" ## config['driver_name']
driver_file_name_prefix= "ni_fake"
driver_namespace = "fake"
library_name = "NiFake"
service_name = "NiFakeService"
c_function_prefix = config['c_function_prefix']
linux_library_name = config['library_info']['Linux']['64bit']['name']
linux_library_name = "./" + linux_library_name + '.so'
windows_libary_name = config['library_info']['Windows']['64bit']['name']
%>\
//---------------------------------------------------------------------
//---------------------------------------------------------------------
#include <thread>
#include <sstream>
#include <fstream>
#include <iostream>
#include <${driver_file_name_prefix}_service.h>
#include <${driver_file_name_prefix}.grpc.h>
#include <atomic>

namespace ni
{
namespace ${driver_namespace}
{
namespace grpc
{
  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  using internal = ni::hardware::grpc::internal;

## Function pointers to driver library
% for method_name in functions:
<%
    f = functions[method_name]
    if not handler_helpers.should_gen_function_pointer(f):
      continue
    parameters = f['parameters']
    handler_helpers.sanitize_names(parameters)
%>\
% if not codegen_helpers.has_array_parameter(f):
  using ${c_function_prefix}${method_name}Ptr = int (*)(${handler_helpers.create_params(parameters)});
% endif
%endfor

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  using namespace std;

## Constructors
  #if defined(_MSC_VER)
    static const char* driver_api_library_name = "${windows_libary_name}";
  #else
    static const char* driver_api_library_name = "${linux_library_name}";
  #endif

  ${service_name}::${service_name}(internal::SharedLibrary* shared_library, internal::SessionRepository* session_repository)
      : shared_library_(shared_library), session_repository_(session_repository) 
  {
    shared_library_ -> set_library_name(driver_api_library_name);
  }

% for method_name in functions:
<%
    f = functions[method_name]
    if not codegen_helpers.should_gen_service_handler(f):
      continue
    parameters = f['parameters']
    handler_helpers.sanitize_names(parameters)
    input_parameters = [p for p in parameters if codegen_helpers.is_input_parameter(p)]
    output_parameters = [p for p in parameters if codegen_helpers.is_output_parameter(p)]
%>\
  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status ${service_name}::${method_name}(grpc::ServerContext* context, const ${driver_prefix}::${method_name}Request* request, ${driver_prefix}::${method_name}Response* response)
  {
% if codegen_helpers.has_array_parameter(f):
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

<% continue %>
% endif
    shared_library_ -> load();
    if (!shared_library_ -> is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto ${method_name}FunctionPointer = reinterpret_cast<${c_function_prefix}${method_name}Ptr>(shared_library_ -> get_function_pointer("${c_function_prefix}${method_name}"));
    if (${method_name}FunctionPointer == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: ${c_function_prefix}${method_name}");
    }

%for parameter in input_parameters:
    ${handler_helpers.get_c_type(parameter)} ${codegen_helpers.camel_to_snake_name(parameter)} = ${handler_helpers.get_request_value(parameter)}
%endfor
%for parameter in output_parameters:
    ${handler_helpers.get_c_type(parameter)} ${codegen_helpers.camel_to_snake_name(parameter)};
%endfor
    auto status = ${method_name}FunctionPointer(${handler_helpers.create_args(parameters)});
    response->set_status(status);
%if output_parameters:
    if (status == 0) {
%for parameter in output_parameters:
## TODO: Figure out how to format ViSession responses. Look at Cifra's example for an idea.
      response->set_${codegen_helpers.camel_to_snake_name(parameter)}(${codegen_helpers.camel_to_snake_name(parameter)});
%endfor
    }
%endif
    return grpc::Status::OK;
  }

% endfor
} // namespace grpc
} // namespace ${driver_namespace}
} // namespace ni