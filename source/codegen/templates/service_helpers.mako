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
% if common_helpers.can_mock_function(parameters):
        int status = library_->${function_name}(${service_helpers.create_args(parameters)});
% else:
        int status = ((${config['service_class_prefix']}Library*)library_)->${function_name}(${service_helpers.create_args(parameters)});
% endif
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

      while (true) {
        auto status = library_->${function_name}(${service_helpers.create_args_for_ivi_dance(parameters)});
        if (status < 0) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        ${size_param['type']} ${common_helpers.camel_to_snake(size_param['cppName'])} = status;
      
<%block filter="common_helpers.indent(1)">\
${initialize_output_params(output_parameters)}\
</%block>\
        status = library_->${function_name}(${service_helpers.create_args(parameters)});
        ## We cast status into ${common_helpers.camel_to_snake(size_param['cppName'])} above, so it's safe to cast
        ## back to status's type here. (we do this to avoid a compiler warning)
        if (status == kErrorReadBufferTooSmall || status == kWarningCAPIStringTruncatedToFitBuffer || status > static_cast<decltype(status)>(${common_helpers.camel_to_snake(size_param['cppName'])})) {
          // buffer is now too small, try again
          continue;
        }
        response->set_status(status);
% if output_parameters:
        if (status == 0) {
<%block filter="common_helpers.indent(1)">\
${set_response_values(output_parameters)}\
</%block>\
        }
% endif
        return ::grpc::Status::OK;
      }\
</%def>

## Generate the core method body for an ivi-dance-with_a_twist method. This should be what gets included within the try block in the service method.
<%def name="define_ivi_dance_with_a_twist_method_body(function_name, function_data, parameters)">\
<%
  (size_param, twist_param, array_param, non_ivi_params) = common_helpers.get_ivi_dance_with_a_twist_params(parameters)
  output_parameters = [p for p in parameters if common_helpers.is_output_parameter(p)]
  array_output_parameters = [p for p in output_parameters if common_helpers.is_array(p['type'])]
  scalar_output_parameters = [p for p in output_parameters if p not in array_output_parameters]
  size_param_name = common_helpers.get_param_cpp_name(size_param)
  twist_param_name = common_helpers.get_param_cpp_name(twist_param)
  is_in_out_twist = size_param_name == twist_param_name
%>\
${initialize_input_params(function_name, non_ivi_params)}\
${initialize_output_params(scalar_output_parameters)}\
      while (true) {
        auto status = library_->${function_name}(${service_helpers.create_args_for_ivi_dance_with_a_twist(parameters)});
        if (status < 0) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
<%block filter="common_helpers.indent(1)">\
${initialize_output_params(array_output_parameters)}\
</%block>\
% if not is_in_out_twist:
        auto ${size_param_name} = ${twist_param_name};
% endif
        status = library_->${function_name}(${service_helpers.create_args(parameters)});
        if (status == kErrorReadBufferTooSmall || status == kWarningCAPIStringTruncatedToFitBuffer) {
          // buffer is now too small, try again
          continue;
        }
        response->set_status(status);
% if output_parameters:
        if (status == 0) {
<%block filter="common_helpers.indent(1)">\
${set_response_values(output_parameters)}\
</%block>\
        }
% endif
        return ::grpc::Status::OK;
      }\
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
${initialize_input_params(function_name, parameters)}\
${initialize_output_params(output_parameters)}\
${set_output_vararg_parameter_sizes(parameters)}\
% if common_helpers.can_mock_function(parameters):
      auto status = library_->${function_name}(${service_helpers.create_args(parameters)});
% else:
      auto status = ((${config['service_class_prefix']}Library*)library_)->${function_name}(${service_helpers.create_args(parameters)});
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
  input_vararg_parameters = [p for p in input_parameters if common_helpers.is_repeated_varargs_parameter(p)]
  input_vararg_parameter = input_vararg_parameters[0] if len(input_vararg_parameters) > 0 else None
%>\
% for parameter in input_parameters:
${initialize_input_param(function_name, parameter, input_vararg_parameter)}\
% endfor
</%def>

## Initialize an input parameter for an API call.
<%def name="initialize_input_param(function_name, parameter, input_vararg_parameter=None)">\
% if common_helpers.is_repeating_parameter(parameter):
${initialize_repeating_param(parameter, input_vararg_parameter)}
% elif common_helpers.is_repeated_varargs_parameter(parameter):
${initialize_repeated_varargs_param(parameter)}
% elif common_helpers.is_enum(parameter) and common_helpers.is_array(parameter['type']):
${initialize_enum_array_input_param(function_name, parameter)}
% elif common_helpers.is_enum(parameter):
${initialize_enum_input_param(function_name, parameter)}
% elif 'callback_token' in parameter or 'callback_params' in parameter: ## pass
% elif "determine_size_from" in parameter:
${initialize_len_input_param(parameter)}
% elif 'hardcoded_value' in parameter:
${initialize_hardcoded_parameter(parameter)}
% else:
${initialize_standard_input_param(function_name, parameter)}
% endif
</%def>

<%def name="initialize_repeating_param(parameter, input_vararg_parameter)">\
<%
  stripped_grpc_type = common_helpers.strip_repeated_from_grpc_type(input_vararg_parameter['grpc_type'])
  if stripped_grpc_type == 'string':
      stripped_grpc_type = 'std::string'
  parameter_c_type = parameter['type']
  parameter_c_type_pointer = parameter_c_type.replace('[]','*')
  # In gRPC fields, the names of the fields in the struct are lowercase
  parameter_name = parameter['name'].lower()
%>\
      auto get_${parameter['name']}_if = [](const google::protobuf::RepeatedPtrField<${stripped_grpc_type}>& vector, int n) -> ${parameter_c_type_pointer} {
            if (vector.size() > n) {
<%
    ## Note that this code will not handle every datatype, but it works for all
    ## the ones we currently use with repeated varargs.
    return_snippet = ''
    if input_vararg_parameter.get("is_compound_type", False):
          return_snippet += f'.{parameter_name}()'
    if common_helpers.is_string_arg(parameter):
          return_snippet += f'.c_str()'
%>\
                  return vector[n]${return_snippet};
            }
% if common_helpers.is_string_arg(parameter):
            return nullptr;
% else:
            return 0;
% endif
      };\
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
</%def>


## Initialize an enum array input parameter.
## This is a straight copy and does not support all of the features of enum parameters 
## (i.e. mapped enums, _raw fields, etc.)
<%def name="initialize_enum_array_input_param(function_name, parameter)">\
<%
  parameter_name = common_helpers.camel_to_snake(parameter['cppName'])
  field_name = common_helpers.camel_to_snake(parameter["name"])
  element_type = service_helpers.get_c_element_type(parameter)
%>\
      auto ${parameter_name}_vector = std::vector<${element_type}>();
      ${parameter_name}_vector.reserve(request->${field_name}().size());
      std::transform(
        request->${field_name}().begin(),
        request->${field_name}().end(),
        std::back_inserter(${parameter_name}_vector),
        [](auto x) { return x; });
      auto ${parameter_name} = ${parameter_name}_vector.data();
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
    check_enum_is_valid = f"{namespace_prefix}{parameter['enum']}_IsValid({parameter_name})"

  raw_request_snippet = f'request->{field_name}_raw()'
  validate_attribute_enum = parameter.get("raw_attribute", False)
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
%   if validate_attribute_enum: 
## "raw" attributes always validate non-raw enum values before passing to driver
## this can be important if (a) the driver can't handle all validation scenarios
## and (b) the caller passes/casts an invalid enum value.
## Non-raw attributes allow the driver to handle validation.
          ${parameter_name} = ${check_enum_is_valid} ? ${parameter_name} : 0;
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
% if validate_attribute_enum: # raw validation can be overriden with a toggle.
          auto ${parameter_name}_is_valid = ${check_enum_is_valid} || feature_toggles_.is_allow_undefined_attributes_enabled;
          ${parameter_name} = ${parameter_name}_is_valid ? ${parameter_name} : 0;
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
  size_sources = parameter["determine_size_from"]
  size_field_name = common_helpers.camel_to_snake(size_sources[-1])
%>\
% if len(size_sources) > 1:
% for size_source in size_sources[:-1]:
<%
  current_size_field_name = common_helpers.camel_to_snake(size_source)
%>\
      if (request->${current_size_field_name}().size() != request->${size_field_name}().size()) {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The sizes of repeated fields ${current_size_field_name} and ${size_field_name} do not match");
      }
% endfor
% endif
      ${parameter['type']} ${parameter_name} = static_cast<${parameter['type']}>(request->${size_field_name}().size());\
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

<%def name="set_output_vararg_parameter_sizes(parameters)">\
<%
  input_vararg_parameter = [p for p in parameters if common_helpers.is_repeated_varargs_parameter(p) and common_helpers.is_input_parameter(p)][0]
  input_parameter_name = common_helpers.camel_to_snake(input_vararg_parameter['cppName'])
  output_vararg_parameters = [p for p in parameters if common_helpers.is_repeating_parameter(p) and not common_helpers.is_input_parameter(p)]
%>\
% for parameter in output_vararg_parameters:
<%
  parameter_name = common_helpers.camel_to_snake(parameter['cppName'])
%>\
      ${parameter_name}Vector.resize(${input_parameter_name}.size());
% endfor
</%def>

## Initialize the output parameters for an API call.
<%def name="initialize_output_params(output_parameters)">\
% for parameter in output_parameters:
<%
  parameter_name = common_helpers.camel_to_snake(parameter['cppName'])
  underlying_param_type = common_helpers.get_underlying_type_name(parameter["type"])
%>\
%   if common_helpers.is_repeating_parameter(parameter):
      auto get_${parameter_name}_if = [](std::vector<${underlying_param_type}>& vector, int n) -> ${underlying_param_type}* {
            if (vector.size() > n) {
## Note that this code will not handle every datatype, but it works for all
## the ones we currently use with repeated varargs.
                  return &(vector[n]);
            }
            return nullptr;
      };
      std::vector<${underlying_param_type}> ${parameter_name}Vector;
%   elif common_helpers.is_repeated_varargs_parameter(parameter): # pass
%   elif common_helpers.is_array(parameter['type']):
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
%     elif common_helpers.is_enum(parameter):
      response->mutable_${parameter_name}_raw()->Resize(${size}, 0);
      ${underlying_param_type}* ${parameter_name} = reinterpret_cast<${underlying_param_type}*>(response->mutable_${parameter_name}_raw()->mutable_data());
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
%   if common_helpers.is_repeating_parameter(parameter):
<%
    varargs_parameter = [p for p in output_parameters if common_helpers.is_repeated_varargs_parameter(p)][0]
    varargs_parameter_name = common_helpers.camel_to_snake(varargs_parameter['cppName'])
%>\
## Note that this currently only supports one repeated output parameter.
        for (int i = 0; i < ${parameter_name}Vector.size(); ++i) {
%   if 'enum' in parameter:
          response->add_${varargs_parameter_name}(static_cast<${parameter['enum']}>(${parameter_name}Vector[i]));
%   else:
          response->add_${varargs_parameter_name}(${parameter_name}Vector[i]);
%   endif
        }
%   elif common_helpers.is_repeated_varargs_parameter(parameter): #pass
%   elif common_helpers.is_enum(parameter) == True:
<%
  has_mapped_enum = 'mapped-enum' in parameter
  has_unmapped_enum = 'enum' in parameter
  if has_mapped_enum:
    mapped_enum_name = parameter["mapped-enum"]
    map_name = mapped_enum_name.lower() + "_output_map_"
    mapped_enum_iterator_name = parameter_name + "_omap_it"
  is_array = common_helpers.is_array(parameter["type"])
  is_string = common_helpers.is_string_arg(parameter)
  uses_raw_output_as_read_buffer = is_array and not is_string
  use_checked_enum_conversion = parameter.get("use_checked_enum_conversion", False)
%>\
%     if has_mapped_enum:
        auto ${mapped_enum_iterator_name} = ${map_name}.find(${parameter_name});
        if(${mapped_enum_iterator_name} != ${map_name}.end()) {
          response->set_${parameter_name}_mapped(static_cast<${namespace_prefix}${mapped_enum_name}>(${mapped_enum_iterator_name}->second));
        }
%     endif
%     if has_unmapped_enum:
%       if use_checked_enum_conversion:
        auto checked_convert_${parameter_name} = [](auto raw_value) {
          bool raw_value_is_valid = ${namespace_prefix}${parameter["enum"]}_IsValid(raw_value);
          auto valid_enum_value = raw_value_is_valid ? raw_value : 0;
          return static_cast<${namespace_prefix}${parameter["enum"]}>(valid_enum_value);
        };
%       endif
%       if is_string:
        CopyBytesToEnums(${parameter_name}, response->mutable_${parameter_name}());
%       elif uses_raw_output_as_read_buffer:
<%
      raw_response_field = f"response->{parameter_name}_raw()"
      cast_x_to_enum = f"static_cast<{namespace_prefix}{parameter['enum']}>(x)"
      checked_convert_x_to_enum = f"checked_convert_{parameter_name}(x)"
      convert_x_to_enum = checked_convert_x_to_enum if use_checked_enum_conversion else cast_x_to_enum
%>\
${initialize_response_buffer(parameter_name=parameter_name, parameter=parameter)}\
${copy_to_response_with_transform(source_buffer=raw_response_field, parameter_name=parameter_name, transform_x=convert_x_to_enum)}\
%       elif parameter['type'] == 'ViReal64':
        if(${parameter_name} == (int)${parameter_name}) {
          response->set_${parameter_name}(static_cast<${namespace_prefix}${parameter["enum"]}>(static_cast<int>(${parameter_name})));
        }
%       elif parameter.get("use_checked_enum_conversion", False):
        response->set_${parameter_name}(checked_convert_${parameter_name}(${parameter_name}));
%       else:
        response->set_${parameter_name}(static_cast<${namespace_prefix}${parameter["enum"]}>(${parameter_name}));
%       endif
%     endif
%     if not uses_raw_output_as_read_buffer: # Set data to raw, unless we *got* the data from raw.
        response->set_${parameter_name}_raw(${parameter_name});
%     endif
%   elif service_helpers.is_output_array_that_needs_coercion(parameter):
${initialize_response_buffer(parameter_name=parameter_name, parameter=parameter)}\
${copy_to_response_with_transform(source_buffer=parameter_name, parameter_name=parameter_name, transform_x="x")}\
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

## Allocate the response buffer using get_size_expression.
<%def name="initialize_response_buffer(parameter_name, parameter)">\
        response->mutable_${parameter_name}()->Clear();
        response->mutable_${parameter_name}()->Reserve(${common_helpers.get_size_expression(parameter)});
</%def>

## Copy source_buffer to response->mutable_[parameter_name]() applying transform_x.
<%def name="copy_to_response_with_transform(source_buffer, parameter_name, transform_x)">\
        std::transform(
          ${source_buffer}.begin(),
          ${source_buffer}.end(),
          google::protobuf::RepeatedFieldBackInserter(response->mutable_${parameter_name}()),
          [&](auto x) { 
              return ${transform_x};
          });
</%def>
