<%!
  import common_helpers
  import service_helpers
%>

## Generate the core method body for an Init method. This should be what gets included within the try block in the service method.
<%def name="define_init_method_body(function_name, function_data, parameters)">\
<%
  config = data['config']
  output_parameters = [p for p in parameters if common_helpers.is_output_parameter(p)]
  session_output_param = next((parameter for parameter in output_parameters if parameter['type'] == 'ViSession'), None)
  session_output_var_name = session_output_param['cppName']
%>\
${initialize_input_params(function_name, parameters)}
      auto init_lambda = [&] () -> std::tuple<int, uint32_t> {
        ViSession ${session_output_var_name};
        int status = library_->${function_name}(${service_helpers.create_args(parameters)});
        return std::make_tuple(status, vi);
      };
      uint32_t session_id = 0;
      const std::string& session_name = request->session_name();
<%
 close_function_call = function_data['custom_close'] if 'custom_close' in function_data else f"{config['close_function']}(id)"
%>\
      auto cleanup_lambda = [&] (uint32_t id) { library_->${close_function_call}; };
      int status = session_repository_->add_session(session_name, init_lambda, cleanup_lambda, session_id);
      response->set_status(status);
      if (status == 0) {
        response->mutable_${session_output_var_name}()->set_id(session_id);
      }
      return ::grpc::Status::OK;\
</%def>

## Generate the core method body for an ivi-dance method. This should be what gets included within the try block in the service method.
<%def name="define_ivi_dance_method_body(function_name, function_data, parameters)">\
<%
  (size_param, array_param, non_ivi_params) = common_helpers.get_ivi_dance_params(parameters)
  output_parameters = [p for p in parameters if common_helpers.is_output_parameter(p)]
%>\
${initialize_input_params(function_name, non_ivi_params)}\

      auto status = library_->${function_name}(${service_helpers.create_args_for_ivi_dance(parameters)});
      if (status < 0) {
        response->set_status(status);
        return ::grpc::Status::OK;
      }
      ${size_param['type']} ${common_helpers.camel_to_snake(size_param['cppName'])} = status;

${initialize_output_params(output_parameters)}\
      status = library_->${function_name}(${service_helpers.create_args(parameters)});
      response->set_status(status);
% if output_parameters:
      if (status == 0) {
${set_response_values(output_parameters)}\
      }
% endif
      return ::grpc::Status::OK;\
</%def>

## Generate the core method body for an ivi-dance method. This should be what gets included within the try block in the service method.
<%def name="define_simple_method_body(function_name, function_data, parameters)">\
<%
  config = data['config']
  output_parameters = [p for p in parameters if common_helpers.is_output_parameter(p)]
%>\
${initialize_input_params(function_name, parameters)}\
${initialize_output_params(output_parameters)}\
% if function_name == config['close_function']:
      session_repository_->remove_session(${service_helpers.create_args(parameters)});
% else:
      auto status = library_->${function_name}(${service_helpers.create_args(parameters)});
      response->set_status(status);
% endif
% if output_parameters:
      if (status == 0) {
${set_response_values(output_parameters=output_parameters)}\
      }
% endif
      return ::grpc::Status::OK;\
</%def>

## Initialize the input parameters to the API call.
<%def name="initialize_input_params(function_name, parameters)">\
<%
  input_parameters = [p for p in parameters if common_helpers.is_input_parameter(p)]
%>\
% for parameter in input_parameters:
${initialize_input_param(function_name, parameter)}
% endfor
</%def>

## Initialize an input parameter for an API call.
<%def name="initialize_input_param(function_name, parameter)">\
<%
  enums = data['enums']
%>\
% if common_helpers.is_enum(parameter) and enums[parameter["enum"]].get("generate-mappings", False):
${initialize_enum_input_param(function_name, parameter)}\
% elif "determine_size_from" in parameter:
${initialize_len_input_param(parameter)}\
% else:
${initialize_standard_input_param(function_name, parameter)}\
% endif
</%def>

## Initialize an enum input parameter for an API call.
<%def name="initialize_enum_input_param(function_name, parameter)">\
<%
  parameter_name = common_helpers.camel_to_snake(parameter['cppName'])
  pascal_parameter_name = common_helpers.snake_to_pascal(parameter_name)
  map_name = parameter["enum"].lower() + "_input_map_"
  iterator_name = parameter_name + "_imap_it"
  enum_type_prefix = function_name + "Request::" + pascal_parameter_name + "EnumCase::"
  param_all_caps_snake = parameter_name.upper()
%>\
      ${parameter['type']} ${parameter_name};
      switch (request->${parameter_name}_enum_case()) {
        case ${enum_type_prefix}k${pascal_parameter_name}: {
          auto ${iterator_name} = ${map_name}.find(request->${parameter_name}());
          if (${iterator_name} == ${map_name}.end()) {
            return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for ${parameter_name} was not specified or out of range.");
          }
% if parameter['type'] == "ViConstString":
          ${parameter_name} = static_cast<${parameter['type']}>((${iterator_name}->second).c_str());
% else:
          ${parameter_name} = static_cast<${parameter['type']}>(${iterator_name}->second);
% endif
          break;
        }
        case ${enum_type_prefix}k${pascal_parameter_name}Raw: {
% if parameter['type'] == "ViConstString":
          ${parameter_name} = static_cast<${parameter['type']}>((request->${parameter_name}_raw()).c_str());
% else:
          ${parameter_name} = static_cast<${parameter['type']}>(request->${parameter_name}_raw());
% endif
          break;
        } 
        case ${enum_type_prefix}${param_all_caps_snake}_ENUM_NOT_SET: {
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for ${parameter_name} was not specified or out of range");
          break;
        }
      }
</%def>

## Initialize an input parameter that is determined by the 'len' size mechanism.
<%def name="initialize_len_input_param(parameter)">\
<%
  parameter_name = common_helpers.camel_to_snake(parameter['cppName'])
  field_name = common_helpers.camel_to_snake(parameter["determine_size_from"])
%>\
      ${parameter['type']} ${parameter_name} = request->${field_name}().size();\
</%def>

## Initialize an input parameter for an API call.
<%def name="initialize_standard_input_param(function_name, parameter)">\
<%
  config = data['config']
  parameter_name = common_helpers.camel_to_snake(parameter['cppName'])
  field_name = common_helpers.camel_to_snake(parameter["name"])
  namespace_prefix = config["namespace_component"] + "_grpc::"
  request_snippet = f'request->{field_name}()'
  c_type = parameter['type']
  c_type_pointer = c_type.replace('[]','*')
%>\
% if c_type == 'ViConstString':
      ${c_type} ${parameter_name} = ${request_snippet}.c_str();\
% elif c_type == 'ViString' or c_type == 'ViRsrc':
      ${c_type} ${parameter_name} = (${c_type})${request_snippet}.c_str();\
% elif c_type == 'ViInt8[]' or c_type == 'ViChar[]':
      ${c_type_pointer} ${parameter_name} = (${c_type[:-2]}*)${request_snippet}.c_str();\
% elif 'enum' in parameter:
<%
PascalFieldName = common_helpers.snake_to_pascal(field_name)
one_of_case_prefix = f'{namespace_prefix}{function_name}Request::{PascalFieldName}EnumCase'
%>\
      ${c_type} ${parameter_name};
      switch (request->${field_name}_enum_case()) {
        case ${one_of_case_prefix}::k${PascalFieldName}:
          ${parameter_name} = (${c_type})${request_snippet};
          break;
        case ${one_of_case_prefix}::k${PascalFieldName}Raw:
          ${parameter_name} = (${c_type})request->${field_name}_raw();
          break;
        case ${one_of_case_prefix}::${field_name.upper()}_ENUM_NOT_SET:
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for ${field_name} was not specified or out of range");
          break;
      }
% elif c_type == 'ViChar' or c_type == 'ViInt16' or c_type == 'ViInt8':
      ${c_type} ${parameter_name} = (${c_type})${request_snippet};\
% elif c_type == 'ViSession':
      auto ${parameter_name}_grpc_session = ${request_snippet};
      ${c_type} ${parameter_name} = session_repository_->access_session(${parameter_name}_grpc_session.id(), ${parameter_name}_grpc_session.name());\
% elif common_helpers.is_array(c_type):
      auto ${parameter_name} = const_cast<${c_type_pointer}>(${request_snippet}.data());\
% else:
      ${c_type} ${parameter_name} = ${request_snippet};\
% endif
</%def>

## Initialize the output parameters for an API call.
<%def name="initialize_output_params(output_parameters)">\
% for parameter in output_parameters:
<%
  parameter_name = common_helpers.camel_to_snake(parameter['cppName'])
  underlying_param_type = common_helpers.get_underlying_type_name(parameter["type"])
%>\
%   if common_helpers.is_array(parameter['type']):
<%
  size = ''
  if common_helpers.get_size_mechanism(parameter) == 'fixed':
    size = parameter['size']['value']
  else:
    size = common_helpers.camel_to_snake(parameter['size']['value'])
%>\
%     if common_helpers.is_struct(parameter):
      std::vector<${underlying_param_type}> ${parameter_name}(${size}, ${underlying_param_type}());
%     elif service_helpers.is_string_arg(parameter):
      std::string ${parameter_name}(${size}, '\0');
%     else:
      response->mutable_${parameter_name}()->Resize(${size}, 0);
      ${underlying_param_type}* ${parameter_name} = response->mutable_${parameter_name}()->mutable_data();
%     endif
%   else:
      ${underlying_param_type} ${parameter_name} {};
%   endif
% endfor
</%def>

## Set output parameters updated through API call on the gRPC response message.
<%def name="set_response_values(output_parameters)">\
<%
  config = data['config']
  enums = data['enums']
  namespace_prefix = config["namespace_component"] + "_grpc::"
%>\
% for parameter in output_parameters:
<%
  parameter_name = common_helpers.camel_to_snake(parameter['cppName'])
%>\
%   if common_helpers.is_enum(parameter) == True:
%     if enums[parameter["enum"]].get("generate-mappings", False):
<%
  map_name = parameter["enum"].lower() + "_output_map_"
  iterator_name = parameter_name + "_omap_it"
%>\
        auto ${iterator_name} = ${map_name}.find(${parameter_name});
        if(${iterator_name} != ${map_name}.end()) {
          response->set_${parameter_name}(static_cast<${namespace_prefix}${parameter["enum"]}>(${iterator_name}->second));
        }
%     else:
        response->set_${parameter_name}(static_cast<${namespace_prefix}${parameter["enum"]}>(${parameter_name}));
%     endif
        response->set_${parameter_name}_raw(${parameter_name});
%   elif common_helpers.is_array(parameter['type']):
%     if service_helpers.is_string_arg(parameter):
        response->set_${parameter_name}(${parameter_name});
%     elif common_helpers.is_struct(parameter):
        Copy(${parameter_name}, response->mutable_${parameter_name}());
%     endif
%   elif parameter['type'] == 'ViSession':
        response->mutable_${parameter_name}()->set_id(${parameter_name});
%   else:
        response->set_${parameter_name}(${parameter_name});
%   endif
% endfor
</%def>