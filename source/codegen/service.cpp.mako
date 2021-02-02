// This file was generated
<%
import re
import codegen_helpers
attributes = data['attributes']
config = data['config']
enums = data['enums']
functions = data['functions']

## TODO: Pull niFake from config metadata.
driver_prefix = "niFake" ## config['driver_name']
driver_file_name_prefix= "ni_fake"
library_name = "NiFake"
service_name = "NiFakeService"
array_brackets_expression = re.compile(r'\[.*\]')
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

//---------------------------------------------------------------------
//---------------------------------------------------------------------
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::StatusCode
using grpc::ServerWriter;
using ni::hardware::grpc::internal::ViSession;

% for method_name in functions:
<%
    f = functions[method_name]
    parameters = f['parameters']
%>\
% if not codegen_helpers.has_array_parameter(f):
using ${method_name}Ptr = int (*)(${codegen_helpers.create_params(parameters)});
% endif
%endfor

static bool s_HasSession;
static std::atomic<unsigned int> s_IdleCount;

//---------------------------------------------------------------------
//---------------------------------------------------------------------
using namespace std;

## Constructors
#if defined(_MSC_VER)
   static const char* driver_api_library_name = "${windows_libary_name}";
#else
   static const char* driver_api_library_name = "${linux_library_name}";
#endif

${service_name}::${service_name}(internal::SessionRepository* session_repository)
    : shared_library_(driver_api_library_name), session_repository_(session_repository)
{
}

% for method_name in functions:
<%
    f = functions[method_name]
    parameters = f['parameters']
    input_parameters = [p for p in parameters if codegen_helpers.is_input_parameter(p)]
    output_parameters = [p for p in parameters if codegen_helpers.is_output_parameter(p)]
%>\
//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status ${service_name}::${method_name}(ServerContext* context, const ${driver_prefix}::${method_name}Request* request, ${driver_prefix}::${method_name}Response* response)
{
% if codegen_helpers.has_array_parameter(f):
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

<% continue %>
% endif
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto ${method_name}FunctionPointer = reinterpret_cast<${method_name}Ptr>(shared_library_.get_function_pointer("${c_function_prefix}${method_name}"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

%for parameter in input_parameters:
  ${parameter['type']} ${codegen_helpers.camel_to_snake_name(parameter)} = ${codegen_helpers.get_request_value(parameter)}
%endfor
%for parameter in output_parameters:
  ${parameter['type']} ${codegen_helpers.camel_to_snake_name(parameter)};
%endfor

  auto status = ${method_name}FunctionPointer(${codegen_helpers.create_args(parameters)});
  response->set_status(status);
  if (status == 0) {
%for parameter in output_parameters:
## TODO: Figure out how to format ViSession responses. Look at Cifra's example for an idea.
    response->set_${codegen_helpers.get_proto_type(codegen_helpers.camel_to_snake_name(parameter).lower())}(${codegen_helpers.get_proto_type(codegen_helpers.camel_to_snake_name(parameter))});
%endfor
  }

  return Status::OK;
}

% endfor