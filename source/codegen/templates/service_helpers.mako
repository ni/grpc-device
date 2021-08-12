<%!
  import common_helpers
  import service_helpers
%>

## Generate the core method body for an Init method. This should be what gets included within the try block in the service method.
<%def name="define_init_method_body(function_name, function_data, parameters)">\
<%
  config = data['config']
  output_parameters = [p for p in parameters if common_helpers.is_output_parameter(p)]
  session_output_param = next((parameter for parameter in output_parameters if parameter['grpc_type'] == 'nidevice_grpc.Session'), None)
  resource_handle_type = session_output_param['type']
  session_output_var_name = session_output_param['cppName']
  close_function_call = function_data['custom_close'] if 'custom_close' in function_data else f"{config['close_function']}(id)"

  explicit_session_params = (common_helpers.camel_to_snake(param['cppName']) for param in parameters if param.get('is_session_name', False))
  session_field_name = next(explicit_session_params, 'session_name')
%>\
${initialize_input_params(function_name, parameters)}
      auto init_lambda = [&] () {
        ${resource_handle_type} ${session_output_var_name};
        int status = library_->${function_name}(${service_helpers.create_args(parameters)});
        return std::make_tuple(status, ${session_output_var_name});
      };
      uint32_t session_id = 0;
      const std::string& grpc_device_session_name = request->${session_field_name}();
      auto cleanup_lambda = [&] (${resource_handle_type} id) { library_->${close_function_call}; };
      int status = session_repository_->add_session(grpc_device_session_name, init_lambda, cleanup_lambda, session_id);
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

## Generate the core method body for an ivi-dance-with_a_twist method. This should be what gets included within the try block in the service method.
<%def name="define_ivi_dance_with_a_twist_method_body(function_name, function_data, parameters)">\
<%
  (size_param, array_param, non_ivi_params) = common_helpers.get_ivi_dance_with_a_twist_params(parameters)
  output_parameters = [p for p in parameters if common_helpers.is_output_parameter(p)]
  array_output_parameters = [p for p in output_parameters if common_helpers.is_array(p['type'])]
  scalar_output_parameters = [p for p in output_parameters if p not in array_output_parameters]
%>\
${initialize_input_params(function_name, non_ivi_params)}\
${initialize_output_params(scalar_output_parameters)}\
      auto status = library_->${function_name}(${service_helpers.create_args_for_ivi_dance_with_a_twist(parameters)});
      if (status < 0) {
        response->set_status(status);
        return ::grpc::Status::OK;
      }
${initialize_output_params(array_output_parameters)}\
      status = library_->${function_name}(${service_helpers.create_args(parameters)});
      response->set_status(status);
% if output_parameters:
      if (status == 0) {
${set_response_values(output_parameters)}\
      }
% endif
      return ::grpc::Status::OK;\
</%def>


<%def name="define_async_callback_method_body(function_name, function_data, parameters, config)">\
<%
  (input_parameters, callback_parameters) = service_helpers.get_callback_method_parameters(function_data)
  response_parameters = common_helpers.filter_parameters_for_grpc_fields(callback_parameters)
  request_type = service_helpers.get_request_type(function_name)
  response_type = service_helpers.get_response_type(function_name)
  driver_library_interface = common_helpers.get_library_interface_type_name(config)
%>\
    using CallbackRouter = nidevice_grpc::CallbackRouter<int32, ${service_helpers.create_param_type_list(callback_parameters)}>;
    class ${function_name}Reactor : public nidevice_grpc::ServerWriterReactor<${response_type}, nidevice_grpc::CallbackRegistration> {
    public:
    ${function_name}Reactor(const ${request_type}& request, ${driver_library_interface}* library, const ResourceRepositorySharedPtr& session_repository)
    {
      auto status = start(&request, library, session_repository);
      if (!status.ok()) {
        this->Finish(status);
      }
    }

    ::grpc::Status start(const ${request_type}* request, ${driver_library_interface}* library, const ResourceRepositorySharedPtr& session_repository_)
    {
      try {
        auto handler = CallbackRouter::register_handler(
          [this](${service_helpers.create_args_for_callback(callback_parameters)}) {
            ${response_type} callback_response;
            auto response = &callback_response;
<%block filter="common_helpers.indent(2)">\
${set_response_values(output_parameters=response_parameters)}\
</%block>\
            queue_write(callback_response);
            return 0;
        });

<%block filter="common_helpers.indent(1)">\
${initialize_input_params(function_name, parameters)}\
</%block>\

        auto status = library->${function_name}(${service_helpers.create_args(parameters)});

        // SendInitialMetadata after the driver call so that WaitForInitialMetadata can be used to ensure that calls are serialized.
        StartSendInitialMetadata();

        if (status) {
          ${response_type} failed_to_register_response;
          failed_to_register_response.set_status(status);
          queue_write(failed_to_register_response);
        }

        this->set_producer(std::move(handler));
      }
      catch (nidevice_grpc::LibraryLoadException& ex) {
         return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
      }

      return ::grpc::Status::OK;
    }
    };

    return new ${function_name}Reactor(*request, library_, session_repository_);
</%def>

## Generate the core method body for a method with repeated varargs.
## This should be what gets included within the try block in the service method.
<%def name="define_repeated_varargs_method_body(function_name, function_data, parameters)">\
<%
  config = data['config']
  output_parameters = [p for p in parameters if common_helpers.is_output_parameter(p)]
%>\
${initialize_input_params(function_name, [p for p in parameters if p.get('include_in_proto', True)] )}\
${initialize_output_params(output_parameters)}\
% if common_helpers.can_mock_function(parameters):
      auto status = library_->${function_name}(${service_helpers.create_args_for_varargs(parameters)});
% else:
      auto status = ((${config['service_class_prefix']}Library*)library_)->${function_name}(${service_helpers.create_args_for_varargs(parameters)});
% endif
      response->set_status(status);
% if output_parameters:
      if (status == 0) {
${set_response_values(output_parameters=output_parameters)}\
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
% if function_name == config['close_function'] or service_helpers.is_custom_close_method(function_data):
      session_repository_->remove_session(${service_helpers.create_args(parameters[:1])});
% endif
      auto status = library_->${function_name}(${service_helpers.create_args(parameters)});
      response->set_status(status);
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
${initialize_input_param(function_name, parameter)}\
% endfor
</%def>

## Initialize an input parameter for an API call.
<%def name="initialize_input_param(function_name, parameter)">\
% if common_helpers.is_enum(parameter):
${initialize_enum_input_param(function_name, parameter)}
% elif 'callback_token' in parameter or 'callback_params' in parameter: ## pass
% elif "determine_size_from" in parameter:
${initialize_len_input_param(parameter)}
% elif common_helpers.is_repeated_varargs_parameter(parameter):
${initialize_repeated_varargs_param(parameter)}
% elif 'hardcoded_value' in parameter:
${initialize_hardcoded_parameter(parameter)}
% else:
${initialize_standard_input_param(function_name, parameter)}
% endif
</%def>

<%def name="initialize_repeated_varargs_param(parameter)">\
<%
  config = data['config']
  parameter_name = common_helpers.camel_to_snake(parameter['cppName'])
  field_name = common_helpers.camel_to_snake(parameter["name"])
  stripped_grpc_type = common_helpers.strip_repeated_from_grpc_type(parameter['grpc_type'])
  request_snippet = f'request->{field_name}()'
  c_type = parameter['type']
  c_type_pointer = c_type.replace('[]','*')
  max_vector_size = parameter['max_length']
%>\
      auto ${parameter_name} = request->${field_name}();
      if (${parameter_name}.size() == 0) {
            return ::grpc::Status(::grpc::INVALID_ARGUMENT, "No values for ${parameter["name"]} were specified");
      }
      if (${parameter_name}.size() > ${max_vector_size}) {
            return ::grpc::Status(::grpc::INVALID_ARGUMENT, "More than ${max_vector_size} values for ${parameter["name"]} were specified");
      }
% for member in parameter['varargs_type']['fields']:
<%
  member_c_type = member['type']
  member_c_type_pointer = member_c_type.replace('[]','*')
  # In gRPC fields, the names of the fields in the struct are lowercase
  member_name = member['name'].lower()
%>\
      auto get_${member['name']}_if = [](const google::protobuf::RepeatedPtrField<${stripped_grpc_type}>& vector, int n) -> ${member_c_type_pointer} {
            if (vector.size() > n) {
% if common_helpers.is_string_arg(member):
                  return vector[n].${member_name}().c_str();
% else:
## Note that this code will not handle every datatype, but it works for all
## the ones we currently use with repeated varargs.
                  return vector[n].${member_name}();
% endif            
            }
% if common_helpers.is_string_arg(member):
            return nullptr;
% else:
            return 0;
% endif
      };
% endfor
</%def>

## Initialize an enum input parameter for an API call.
<%def name="initialize_enum_input_param(function_name, parameter)">\
<%
  config = data['config']
  enums = data['enums']
  namespace_prefix = config["namespace_component"] + "_grpc::"
  parameter_name = common_helpers.camel_to_snake(parameter['cppName'])
  field_name = common_helpers.camel_to_snake(parameter["name"])
  pascal_field_name = common_helpers.snake_to_pascal(field_name)
  one_of_case_prefix = f'{namespace_prefix}{function_name}Request::{pascal_field_name}EnumCase'
  has_mapped_enum = 'mapped-enum' in parameter
  has_unmapped_enum = 'enum' in parameter
  if has_mapped_enum:
    map_name = parameter["mapped-enum"].lower() + "_input_map_"
    mapped_enum_iterator_name = field_name + "_imap_it"
    mapped_request_snippet = f'request->{field_name}_mapped()'
  if has_unmapped_enum:
    enum_request_snippet = f'request->{field_name}()'
  raw_request_snippet = f'request->{field_name}_raw()'
%>\
      ${parameter['type']} ${parameter_name};
      switch (request->${field_name}_enum_case()) {
% if has_unmapped_enum:
        case ${one_of_case_prefix}::k${pascal_field_name}: {
%   if parameter['type'] in ["ViConstString", "ViString"]:
          ${parameter_name} = const_cast<${parameter['type']}>((${enum_request_snippet}).c_str());
%   else:
          ${parameter_name} = static_cast<${parameter['type']}>(${enum_request_snippet});
%   endif
          break;
        }
% endif
% if has_mapped_enum:
        case ${one_of_case_prefix}::k${pascal_field_name}Mapped: {
          auto ${mapped_enum_iterator_name} = ${map_name}.find(${mapped_request_snippet});
          if (${mapped_enum_iterator_name} == ${map_name}.end()) {
            return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for ${parameter_name}_mapped was not specified or out of range.");
          }
%   if parameter['type'] in ["ViConstString", "ViString"]:
          ${parameter_name} = const_cast<${parameter['type']}>((${f'{mapped_enum_iterator_name}->second'}).c_str());
%   else:
          ${parameter_name} = static_cast<${parameter['type']}>(${f'{mapped_enum_iterator_name}->second'});
%   endif
          break;
        }
% endif
        case ${one_of_case_prefix}::k${pascal_field_name}Raw: {
% if parameter['type'] in ["ViConstString", "ViString"]:
          ${parameter_name} = const_cast<${parameter['type']}>(${raw_request_snippet}.c_str());
% else:
          ${parameter_name} = static_cast<${parameter['type']}>(${raw_request_snippet});
% endif
          break;
        }
        case ${one_of_case_prefix}::${field_name.upper()}_ENUM_NOT_SET: {
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


## Initialize a 'hardcoded' param.
<%def name="initialize_hardcoded_parameter(parameter)">\
      auto ${common_helpers.camel_to_snake(parameter['cppName'])} = ${parameter['hardcoded_value']};\
</%def>


## Initialize an input parameter for an API call.
<%def name="initialize_standard_input_param(function_name, parameter)">\
<%
  parameter_name = common_helpers.camel_to_snake(parameter['cppName'])
  field_name = common_helpers.camel_to_snake(parameter["name"])
  request_snippet = f'request->{field_name}()'
  c_type = parameter['type']
  grpc_type = parameter.get('grpc_type', None)
  c_type_pointer = c_type.replace('[]','*')
  c_type_underlying_type = common_helpers.get_underlying_type_name(c_type)
  c_element_type_that_needs_coercion = service_helpers.get_c_element_type_for_array_that_needs_coercion(parameter)
%>\
% if c_type in ['ViConstString', 'const char[]']:
      auto ${parameter_name} = ${request_snippet}.c_str();\
% elif common_helpers.is_string_arg(parameter):
      ${c_type_pointer} ${parameter_name} = (${c_type_pointer})${request_snippet}.c_str();\
% elif c_type == 'ViSession[]':
      auto ${parameter_name}_request = ${request_snippet};
      std::vector<${c_type_underlying_type}> ${parameter_name};
      std::transform(
        ${parameter_name}_request.begin(),
        ${parameter_name}_request.end(),
        std::back_inserter(${parameter_name}),
        [&](auto session) { return session_repository_->access_session(session.id(), session.name()); }); \
% elif c_type == 'ViBoolean[]':
      auto ${parameter_name}_request = ${request_snippet};
      std::vector<${c_type_underlying_type}> ${parameter_name};
      std::transform(
        ${parameter_name}_request.begin(),
        ${parameter_name}_request.end(),
        std::back_inserter(${parameter_name}),
        [](auto x) { return x ? VI_TRUE : VI_FALSE; });
% elif c_type == 'ViInt16[]':
      auto ${parameter_name}_request = ${request_snippet};
      std::vector<${c_type_underlying_type}> ${parameter_name};
      std::transform(
        ${parameter_name}_request.begin(),
        ${parameter_name}_request.end(),
        std::back_inserter(${parameter_name}),
        [](auto x) { return (${c_type_underlying_type})x; }); \
 % elif common_helpers.is_struct(parameter) and common_helpers.is_array(c_type):
      auto ${parameter_name}_request = ${request_snippet};
      std::vector<${c_type_underlying_type}> ${parameter_name};
      Copy(${parameter_name}_request, &${parameter_name});\
% elif c_type in ['ViChar', 'ViInt8', 'ViInt16']:
      ${c_type} ${parameter_name} = (${c_type})${request_snippet};\
% elif grpc_type == 'nidevice_grpc.Session':
      auto ${parameter_name}_grpc_session = ${request_snippet};
      ${c_type} ${parameter_name} = session_repository_->access_session(${parameter_name}_grpc_session.id(), ${parameter_name}_grpc_session.name());\
% elif c_type in ['ViAddr[]', 'ViInt32[]', 'ViUInt32[]', 'int32[]', 'uInt32[]']:
      auto ${parameter_name} = const_cast<${c_type_pointer}>(reinterpret_cast<const ${c_type_pointer}>(${request_snippet}.data()));\
%elif c_type in ['const int32[]', 'const uInt32[]']:
      auto ${parameter_name} = reinterpret_cast<${c_type_pointer}>(${request_snippet}.data());\
%elif grpc_type == 'bytes':
      auto ${parameter_name} = reinterpret_cast<const unsigned char*>(${request_snippet}.data());\
%elif service_helpers.is_input_array_that_needs_coercion(parameter):
      auto ${parameter_name}_raw = ${request_snippet};
      auto ${parameter_name} = std::vector<${c_element_type_that_needs_coercion}>();
      ${parameter_name}.reserve(${parameter_name}_raw.size());
      std::transform(
        ${parameter_name}_raw.begin(),
        ${parameter_name}_raw.end(),
        std::back_inserter(${parameter_name}),
        [](auto x) { 
              if (x < std::numeric_limits<${c_element_type_that_needs_coercion}>::min() || x > std::numeric_limits<${c_element_type_that_needs_coercion}>::max()) {
                  std::string message("value ");
                  message.append(std::to_string(x));
                  message.append(" doesn't fit in datatype ");
                  message.append("${c_element_type_that_needs_coercion}");
                  throw nidevice_grpc::ValueOutOfRangeException(message);
              }
              return static_cast<${c_element_type_that_needs_coercion}>(x);
        });
% elif common_helpers.is_array(c_type):
      auto ${parameter_name} = const_cast<${c_type_pointer}>(${request_snippet}.data());\
% elif c_type == 'CVIAbsoluteTime':
      ${c_type} ${parameter_name} = convert_from_grpc<${c_type}>(${request_snippet});\
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
  size = common_helpers.get_size_expression(parameter)
%>\
%     if common_helpers.is_struct(parameter) or underlying_param_type == 'ViBoolean':
      std::vector<${underlying_param_type}> ${parameter_name}(${size}, ${underlying_param_type}());
## Byte arrays are leveraging a string as a buffer, so we don't need to take special consideration of the null terminator.
%     elif parameter['grpc_type'] == 'bytes':
      std::string ${parameter_name}(${size}, '\0');
## Driver string APIs require room in the buffer for the null terminator. We need to account for that when sizing the string.
%     elif common_helpers.is_string_arg(parameter) and common_helpers.get_size_mechanism(parameter) == 'fixed':
      std::string ${parameter_name}(${size} - 1, '\0');
%     elif common_helpers.is_string_arg(parameter):
      std::string ${parameter_name};
      if (${size} > 0) {
          ${parameter_name}.resize(${size}-1);
      }
%     elif service_helpers.is_output_array_that_needs_coercion(parameter):
      std::vector<${underlying_param_type}> ${parameter_name}(${size});
## uInt32 requires cast because of int vs long in that typedef vs uint32_t
%     elif underlying_param_type in ['ViAddr', 'ViInt32', 'ViUInt32', 'ViUInt16', 'uInt32', 'int32']:
      response->mutable_${parameter_name}()->Resize(${size}, 0);
      ${underlying_param_type}* ${parameter_name} = reinterpret_cast<${underlying_param_type}*>(response->mutable_${parameter_name}()->mutable_data());
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
<%
  has_mapped_enum = 'mapped-enum' in parameter
  has_unmapped_enum = 'enum' in parameter
  if has_mapped_enum:
    mapped_enum_name = parameter["mapped-enum"]
    map_name = mapped_enum_name.lower() + "_output_map_"
    mapped_enum_iterator_name = parameter_name + "_omap_it"
%>\
%     if has_mapped_enum:
        auto ${mapped_enum_iterator_name} = ${map_name}.find(${parameter_name});
        if(${mapped_enum_iterator_name} != ${map_name}.end()) {
          response->set_${parameter_name}_mapped(static_cast<${namespace_prefix}${mapped_enum_name}>(${mapped_enum_iterator_name}->second));
        }
%     endif
%     if has_unmapped_enum:
%       if common_helpers.is_array(parameter['type']) and common_helpers.is_string_arg(parameter):
        CopyBytesToEnums(${parameter_name}, response->mutable_${parameter_name}());
%       elif parameter['type'] == 'ViReal64':
        if(${parameter_name} == (int)${parameter_name}) {
          response->set_${parameter_name}(static_cast<${namespace_prefix}${parameter["enum"]}>(static_cast<int>(${parameter_name})));
        }
%       else:
        response->set_${parameter_name}(static_cast<${namespace_prefix}${parameter["enum"]}>(${parameter_name}));
%       endif
%     endif
        response->set_${parameter_name}_raw(${parameter_name});
%   elif service_helpers.is_output_array_that_needs_coercion(parameter):
        response->mutable_${parameter_name}()->Clear();
        response->mutable_${parameter_name}()->Reserve(${common_helpers.get_size_expression(parameter)});
        std::transform(
          ${parameter_name}.begin(),
          ${parameter_name}.end(),
          google::protobuf::RepeatedFieldBackInserter(response->mutable_${parameter_name}()),
          [](auto x) { 
              return x;
          });
%   elif common_helpers.is_array(parameter['type']):
%     if common_helpers.is_string_arg(parameter):
        response->set_${parameter_name}(${parameter_name});
%     elif common_helpers.is_struct(parameter) or parameter['type'] == 'ViBoolean[]':
        Copy(${parameter_name}, response->mutable_${parameter_name}());
%     endif
%   elif parameter['type'] == 'ViSession':
        auto session_id = session_repository_->resolve_session_id(${parameter_name});
        response->mutable_${parameter_name}()->set_id(session_id);
%   elif parameter['type'] == 'CVIAbsoluteTime':
        convert_to_grpc(${parameter_name}, response->mutable_${parameter_name}());
%   else:
        response->set_${parameter_name}(${parameter_name});
%   endif
% endfor
</%def>
