<%!
  import common_helpers
  import service_helpers
%>

## Generate the core method body for an Init method. This should be what gets included within the try block in the service method.
<%def name="define_init_method_body(function_name, function_data, parameters)">\
<%
  config = data['config']
  output_parameters = [p for p in parameters if common_helpers.is_output_parameter(p)]
  input_parameters = [p for p in parameters if common_helpers.is_input_parameter(p)]
  session_output_param = next((p for p in output_parameters if p['grpc_type'] == 'nidevice_grpc.Session'), None)
  session_behavior_param = next((p for p in input_parameters if p['grpc_type'] == 'nidevice_grpc.SessionInitializationBehavior'), None)
  session_initialized_param = next((p for p in output_parameters if common_helpers.is_proto_only_parameter(p) and p['type'] == 'bool'), None)
  output_parameters_to_initialize = [p for p in output_parameters if p['grpc_type'] != 'nidevice_grpc.Session']
  resource_handle_type = session_output_param['type']
  session_output_var_name = common_helpers.get_cpp_local_name(session_output_param)
  close_function_call = function_data['custom_close'] if 'custom_close' in function_data else f"{config['close_function']}(id)"

  explicit_session_params = (common_helpers.get_cpp_local_name(param) for param in parameters if param.get('is_session_name', False))
  session_field_name = next(explicit_session_params, 'session_name')
  add_session_snippet = 'add_session(grpc_device_session_name, init_lambda, cleanup_lambda)'
  if session_behavior_param and session_initialized_param:
      session_behavior_param_name = common_helpers.get_cpp_local_name(session_behavior_param)
      session_initialized_param_name = common_helpers.get_cpp_local_name(session_initialized_param)
      add_session_snippet = f'add_session(grpc_device_session_name, init_lambda, cleanup_lambda, {session_behavior_param_name}, &{session_initialized_param_name})'
%>\
${initialize_input_params(function_name, parameters)}
${initialize_output_params(output_parameters_to_initialize)}\
      auto init_lambda = [&] () {
## If the session is not returned, it's an output param and need to be declared before calling.
% if not service_helpers.is_session_returned_from_function(parameters):
        ${resource_handle_type} ${session_output_var_name};
% endif
${call_library_method(
  function_name=function_name,
  function_data=function_data,
  arg_string=service_helpers.create_args(parameters),
  indent_level=1,
  library_ptr=service_helpers.get_library_ptr_for_potentially_unmockable_function(config, parameters))
}\
        return std::make_tuple(status, ${session_output_var_name});
      };
      std::string grpc_device_session_name = request->${session_field_name}();
      auto cleanup_lambda = [&] (${resource_handle_type} id) { library_->${close_function_call}; };
      int status = ${service_helpers.session_repository_field_name(session_output_param, config)}->${add_session_snippet};
${populate_response(function_data=function_data, parameters=parameters, init_method=True)}\
      return ::grpc::Status::OK;\
</%def>

<%def name="define_cross_driver_init_method_body(function_name, function_data, parameters)">\
<%
  config = data['config']
  initiating_driver_input_param = next(p for p in parameters if common_helpers.is_input_parameter(p) and p['grpc_type'] == 'nidevice_grpc.Session')
  output_parameters = [p for p in parameters if common_helpers.is_output_parameter(p)]
  session_output_param = next(p for p in output_parameters if p['grpc_type'] == 'nidevice_grpc.Session')
  output_parameters_to_initialize = [p for p in output_parameters if p['grpc_type'] != 'nidevice_grpc.Session']
  cross_driver_dep = service_helpers.get_cross_driver_session_dependency(session_output_param)
  session_output_var_name = common_helpers.get_cpp_local_name(session_output_param)
  session_output_field_name = common_helpers.get_grpc_field_name(session_output_param)
  initiating_driver_input_var_name = common_helpers.get_cpp_local_name(initiating_driver_input_param)
  initiating_driver_c_name = f'{initiating_driver_input_var_name}_grpc_session'
%>\
${initialize_input_params(function_name, parameters)}
${initialize_output_params(output_parameters_to_initialize)}\
      auto initiating_session_name = ${initiating_driver_c_name}.name();
      auto init_lambda = [&] () {
        ${cross_driver_dep.resource_handle_type} ${session_output_var_name};
        int status = library_->${function_name}(${service_helpers.create_args(parameters)});
        return std::make_tuple(status, ${session_output_var_name});
      };
      std::string session_name = request->session_name();
      int status = ${cross_driver_dep.field_name}->add_dependent_session(session_name, init_lambda, initiating_session_name);
      response->set_status(status);
      if (status == 0) {
        response->mutable_${session_output_field_name}()->set_name(session_name);
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
${call_library_method(
  function_name=function_name,
  function_data=function_data,
  arg_string=service_helpers.create_args_for_ivi_dance(parameters),
  indent_level=1)
}\
${populate_error_check(function_data, parameters, indent_level=1)}\
        ${size_param['type']} ${common_helpers.get_cpp_local_name(size_param)} = status;

<%block filter="common_helpers.indent(1)">\
${initialize_output_params(output_parameters)}\
</%block>\
${call_library_method(
  function_name=function_name,
  function_data=function_data,
  arg_string=service_helpers.create_args(parameters),
  indent_level=1,
  declare_outputs=False)
}\
        ## We cast status into ${common_helpers.get_cpp_local_name(size_param)} above, so it's safe to cast
        ## back to status's type here. (we do this to avoid a compiler warning)
        if (status == kErrorReadBufferTooSmall || status == kWarningCAPIStringTruncatedToFitBuffer || status > static_cast<decltype(status)>(${common_helpers.get_cpp_local_name(size_param)})) {
          // buffer is now too small, try again
          continue;
        }
${populate_response(function_data=function_data, parameters=parameters, indent_level=1)}\
        return ::grpc::Status::OK;
      }\
</%def>

## Generate the core method body for an ivi-dance-with_a_twist method. This should be what gets included within the try block in the service method.
<%def name="define_ivi_dance_with_a_twist_method_body(function_name, function_data, parameters)">\
<%
  ivi_param_sets = common_helpers.get_ivi_dance_with_a_twist_params(parameters)
  non_ivi_params = common_helpers.get_params_not_in_ivi_twist(parameters, ivi_param_sets)
  output_parameters = [p for p in parameters if common_helpers.is_output_parameter(p)]
  array_output_parameters = [p for p in output_parameters if common_helpers.is_array(p['type'])]
  scalar_output_parameters = [p for p in output_parameters if p not in array_output_parameters]
%>\
${initialize_input_params(function_name, non_ivi_params)}\
${initialize_output_params(scalar_output_parameters)}\
      while (true) {
${call_library_method(
  function_name=function_name,
  function_data=function_data,
  arg_string=service_helpers.create_args_for_ivi_dance_with_a_twist(parameters),
  indent_level=1)
}\
${populate_error_check(function_data, parameters, indent_level=1)}\
<%block filter="common_helpers.indent(1)">\
${initialize_output_params(array_output_parameters)}\
</%block>\
% for ivi_param_set in ivi_param_sets:
%   if not ivi_param_set.is_in_out_twist:
        auto ${ivi_param_set.size_param_name} = ${ivi_param_set.twist_param_name};
%   endif
% endfor
${call_library_method(
  function_name=function_name,
  function_data=function_data,
  arg_string=service_helpers.create_args(parameters),
  indent_level=1,
  declare_outputs=False)
}\
        if (status == kErrorReadBufferTooSmall || status == kWarningCAPIStringTruncatedToFitBuffer) {
          // buffer is now too small, try again
          continue;
        }
${populate_response(function_data=function_data, parameters=parameters, indent_level=1)}\
        return ::grpc::Status::OK;
      }\
</%def>


<%def name="define_async_callback_method_body(function_name, function_data, parameters, config)">\
<%
  callback_parameters = service_helpers.get_callback_method_parameters(function_data)
  response_parameters = common_helpers.filter_parameters_for_grpc_fields(callback_parameters)
  request_type = service_helpers.get_request_type(function_name)
  response_type = service_helpers.get_response_type(function_name)
  driver_library_interface = common_helpers.get_library_interface_type_name(config)
  service_class = config["service_class_prefix"] + "Service"
%>\
    using CallbackRouter = nidevice_grpc::CallbackRouter<int32, ${service_helpers.create_param_type_list(callback_parameters)}>;
    class ${function_name}Reactor : public nidevice_grpc::ServerWriterReactor<${response_type}, nidevice_grpc::CallbackRegistration> {
    public:
    ${function_name}Reactor(::grpc::CallbackServerContext* context, const ${request_type}* request, LibrarySharedPtr library, ${service_class}* service)
    {
      auto status = start(context, request, library, service);
      if (!status.ok()) {
        this->try_finish(std::move(status));
      }
    }

    ::grpc::Status start(::grpc::CallbackServerContext* context, const ${request_type}* request, LibrarySharedPtr library, ${service_class}* service)
    {
      try {
        auto handler = CallbackRouter::register_handler(
          [this](${service_helpers.create_args_for_callback(callback_parameters)}) {
            ${response_type} callback_response;
            auto response = &callback_response;
<%block filter="common_helpers.indent(2)">\
${set_response_values(output_parameters=response_parameters, init_method=False)}\
</%block>\
            queue_write(callback_response);
            return 0;
        });

        const auto& session_repository_ = service->session_repository_;
<%block filter="common_helpers.indent(1)">\
${initialize_input_params(function_name, parameters)}\
</%block>\

${call_library_method(
  function_name=function_name,
  function_data=function_data,
  arg_string=service_helpers.create_args(parameters),
  library_ptr="library",
  indent_level=1)
}\
${populate_error_check(function_data, parameters, indent_level=1, service_deref="service->")}\

        // SendInitialMetadata after the driver call so that WaitForInitialMetadata can be used to ensure that calls are serialized.
        StartSendInitialMetadata();

        this->set_producer(std::move(handler));
      }
      catch (nidevice_grpc::NonDriverException& ex) {
         return ex.GetStatus();
      }

      return ::grpc::Status::OK;
    }
    };

    return new ${function_name}Reactor(context, request, library_, this);
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
${call_library_method(
  function_name=function_name,
  function_data=function_data,
  arg_string=service_helpers.create_args(parameters),
  library_ptr=service_helpers.get_library_ptr_for_potentially_unmockable_function(config, parameters))
}\
${populate_response(function_data=function_data, parameters=parameters)}\
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
<%
  session_param = common_helpers.get_first_session_param(parameters)
  session_param_name = f'{common_helpers.get_cpp_local_name(session_param)}_grpc_session'
%>\
      ${service_helpers.session_repository_field_name(session_param, config)}->remove_session(${session_param_name}.name());
% endif
${call_library_method(
  function_name=function_name,
  function_data=function_data,
  arg_string=service_helpers.create_args(parameters))
}\
${populate_response(function_data=function_data, parameters=parameters)}\
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
${initialize_input_param(function_name, parameter, parameters, input_vararg_parameter)}\
% endfor
</%def>

## Initialize an input parameter for an API call.
<%def name="initialize_input_param(function_name, parameter, parameters, input_vararg_parameter=None)">\
% if common_helpers.is_repeating_parameter(parameter):
${initialize_repeating_param(parameter, input_vararg_parameter)}
% elif common_helpers.is_repeated_varargs_parameter(parameter):
${initialize_repeated_varargs_param(parameter)}
% elif common_helpers.is_bitfield_as_enum_array(parameter):
${initialize_bitfield_as_enum_array_param(function_name, parameter)}
% elif common_helpers.is_enum(parameter) and common_helpers.is_array(parameter['type']) and not common_helpers.is_string_arg(parameter):
${initialize_enum_array_input_param(function_name, parameter)}
% elif common_helpers.is_enum(parameter):
${initialize_enum_input_param(function_name, parameter)}
% elif 'hardcoded_value' in parameter:
${initialize_hardcoded_parameter(parameter)}
% elif 'callback_token' in parameter or 'callback_params' in parameter: ## pass
% elif "determine_size_from" in parameter:
${initialize_len_input_param(parameter, parameters)}
% elif common_helpers.is_two_dimension_array_param(parameter):
${initialize_two_dimension_input_param(function_name, parameter, parameters)}
% elif service_helpers.is_size_param_passed_by_ptr(parameter):
${initialize_pointer_input_parameter(parameter)}
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
  parameter_name = common_helpers.get_grpc_field_name(parameter)
%>\
      auto get_${parameter['name']}_if = [](const google::protobuf::RepeatedPtrField<${stripped_grpc_type}>& vector, int n) -> ${parameter_c_type_pointer} {
            if (vector.size() > n) {
<%
    # Note that this code will not handle every datatype, but it works for all
    # the ones we currently use with repeated varargs.
    return_snippet = ''
    if input_vararg_parameter.get("is_compound_type", False):
      return_snippet += f'.{parameter_name}()'
    if common_helpers.is_string_arg(parameter):
      # Warning: We don't convert_from_grpc here (converting from utf-8) because we would need to
      # store the converted string in a buffer until the extracted c_str() is no longer needed. For
      # now this is fine, though, because the only driver that uses this is NI-DAQmx, for strings
      # that are ASCII-only. (For physical channels and lines.)
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
  parameter_name = common_helpers.get_cpp_local_name(parameter)
  field_name = common_helpers.get_grpc_field_name(parameter)
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
  parameter_name = common_helpers.get_cpp_local_name(parameter)
  field_name = common_helpers.get_grpc_field_name(parameter)
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

## Initialize a bitfield as enum array input parameter for an API call.
<%def name="initialize_bitfield_as_enum_array_param(function_name, parameter)">\
<%
  parameter_name = common_helpers.get_cpp_local_name(parameter)
  field_name = common_helpers.get_grpc_field_name(parameter)
  enum_type = common_helpers.get_bitfield_enum_type(parameter)
  bitfield_type = parameter["type"]
%>\
      const auto ${parameter_name} = nidevice_grpc::converters::convert_bitfield_as_enum_array_input(
        request->${field_name}_array(),
        request->${field_name}_raw());
</%def>

## Initialize an enum input parameter for an API call.
<%def name="initialize_enum_input_param(function_name, parameter)">\
<%
  config = data['config']
  enums = data['enums']
  namespace_prefix = config["namespace_component"] + "_grpc::"
  parameter_name = common_helpers.get_cpp_local_name(parameter)
  parameter_type_pointer = parameter['type'].replace('[]','*')
  field_name = common_helpers.get_grpc_field_name(parameter)
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
      ${parameter_type_pointer} ${parameter_name};
% if parameter['grpc_type'] == "string":
      std::string ${parameter_name}_buffer;
% endif
      switch (request->${field_name}_enum_case()) {
% if has_unmapped_enum:
        case ${one_of_case_prefix}::k${pascal_field_name}: {
%   if parameter['grpc_type'] == "string":
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
%   if parameter['grpc_type'] == "string":
          ${parameter_name} = const_cast<${parameter_type_pointer}>((${f'{mapped_enum_iterator_name}->second'}).c_str());
%   else:
          ${parameter_name} = static_cast<${parameter['type']}>(${f'{mapped_enum_iterator_name}->second'});
%   endif
          break;
        }
% endif
        case ${one_of_case_prefix}::k${pascal_field_name}Raw: {
% if parameter['grpc_type'] == "string":
          ${parameter_name}_buffer = convert_from_grpc<std::string>(${raw_request_snippet});
          ${parameter_name} = const_cast<${parameter_type_pointer}>(${parameter_name}_buffer.c_str());
% else:
          ${parameter_name} = static_cast<${parameter['type']}>(${raw_request_snippet});
% endif
% if validate_attribute_enum: # raw validation can be overridden with a toggle.
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
<%def name="initialize_len_input_param(parameter, parameters)">\
<%
  parameter_name = common_helpers.get_cpp_local_name(parameter)
  size_sources = common_helpers.get_grpc_field_names_for_param_names(
    parameters,
    parameter["determine_size_from"]
  )
  size_field_name = common_helpers.get_grpc_field_name_from_str(size_sources[-1])
  allow_optional = parameter["linked_params_are_optional"]
  allow_optional_as_cpp_constant = "true" if allow_optional else "false"
%>\
% if len(size_sources) > 1:
      auto ${parameter_name}_determine_from_sizes = std::array<int, ${len(size_sources)}>
      {
<%block filter="common_helpers.trim_trailing_comma()">\
% for size_source in size_sources:
        request->${size_source}_size(),
% endfor
</%block>\
      };
      const auto ${parameter_name}_size_calculation = calculate_linked_array_size(${parameter_name}_determine_from_sizes, ${allow_optional_as_cpp_constant});

      if (${parameter_name}_size_calculation.match_state == MatchState::MISMATCH) {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The sizes of linked repeated fields [${str.join(', ', size_sources)}] do not match");
      }
% if allow_optional:
      // NULL out optional params with zero sizes.
      if (${parameter_name}_size_calculation.match_state == MatchState::MATCH_OR_ZERO) {
% for size_source in size_sources:
        ${size_source} = request->${size_source}_size() ? std::move(${size_source}) : nullptr;
% endfor
      }
% endif
      auto ${parameter_name} = ${parameter_name}_size_calculation.size;
% else:
<%
  size_field_name = size_sources[-1]
  linked_array_param_name = parameter["determine_size_from"]
  linked_array_param = common_helpers.get_param_with_name(parameters, linked_array_param_name[-1])
  calculate_len_in_bytes = common_helpers.get_size_mechanism(linked_array_param) == "len-in-bytes"
  linked_array_param_underlying_type = common_helpers.get_underlying_type(linked_array_param)
  if len(linked_array_param_name) > 1 and calculate_len_in_bytes:
    raise f"{parameter['name']} has 'len-in-bytes' set but has more than one 'determine-size-from' values!"
%>\
  %if calculate_len_in_bytes:
      ${parameter['type']} ${parameter_name} = static_cast<${parameter['type']}>(request->${size_field_name}().size() * sizeof(${linked_array_param_underlying_type}));\
  %elif linked_array_param['type'] in ['ViConstString', 'const char[]']:
      ${parameter['type']} ${parameter_name} = static_cast<${parameter['type']}>(convert_from_grpc<std::string>(request->${size_field_name}()).size());\
  %else:
      ${parameter['type']} ${parameter_name} = static_cast<${parameter['type']}>(request->${size_field_name}().size());\
  %endif
% endif
</%def>

## Initialize an input parameter with the 'two-dimension' size mechanism.
<%def name="initialize_two_dimension_input_param(function_name, parameter, parameters)">\
<%
  parameter_name = common_helpers.get_cpp_local_name(parameter)
  size_param_name = common_helpers.get_size_param(parameter)
  size_param = common_helpers.get_param_with_name(parameters, size_param_name)
  size_field_name = common_helpers.get_grpc_field_name(size_param)
%>\
${initialize_standard_input_param(function_name, parameter)}
      auto total_length = std::accumulate(request->${size_field_name}().cbegin(), request->${size_field_name}().cend(), 0);

      if (total_length != request->${parameter_name}_size()) {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The total size of the two-dimensional array ${parameter_name} does not match the expected size from the sum of ${size_field_name}");
      }
</%def>


## Initialize a 'hardcoded' param.
<%def name="initialize_hardcoded_parameter(parameter)">\
      auto ${common_helpers.get_cpp_local_name(parameter)} = ${parameter['hardcoded_value']};\
</%def>

## Initialize an input parameter that's passed by pointer.
<%def name="initialize_pointer_input_parameter(parameter)">\
      ${parameter['type']} ${common_helpers.get_cpp_local_name(parameter)}_copy = request->${common_helpers.get_cpp_local_name(parameter)}();\
</%def>


## Initialize an input parameter for an API call.
<%def name="initialize_standard_input_param(function_name, parameter)">\
<%
  config = data['config']
  parameter_name = common_helpers.get_cpp_local_name(parameter)
  field_name = common_helpers.get_grpc_field_name(parameter)
  request_snippet = f'request->{field_name}()'
  c_type = parameter['type']
  grpc_type = parameter.get('grpc_type', None)
  c_type_pointer = c_type.replace('[]','*')
  is_array = common_helpers.is_array(c_type)
  c_type_underlying_type = common_helpers.get_underlying_type_name(c_type)
  c_element_type_that_needs_coercion = service_helpers.get_c_element_type_for_array_that_needs_coercion(parameter)
%>\
% if c_type in ['ViConstString', 'const char[]']:
      auto ${parameter_name}_mbcs = convert_from_grpc<std::string>(${request_snippet});
      auto ${parameter_name} = ${parameter_name}_mbcs.c_str();\
% elif grpc_type == 'string':
      auto ${parameter_name}_mbcs = convert_from_grpc<std::string>(${request_snippet});
      ${c_type_pointer} ${parameter_name} = (${c_type_pointer})${parameter_name}_mbcs.c_str();\
% elif common_helpers.is_string_arg(parameter):
      ${c_type_pointer} ${parameter_name} = (${c_type_pointer})${request_snippet}.c_str();\
% elif common_helpers.supports_standard_copy_conversion_routines(parameter):
      auto ${parameter_name} = convert_from_grpc<${c_type_underlying_type}>(${str.join(", ", [request_snippet] + parameter.get("additional_arguments_to_copy_convert", []))});\
% elif grpc_type == 'repeated nidevice_grpc.Session':
      auto ${parameter_name}_request = ${request_snippet};
      std::vector<${c_type_underlying_type}> ${parameter_name};
      std::transform(
        ${parameter_name}_request.begin(),
        ${parameter_name}_request.end(),
        std::back_inserter(${parameter_name}),
        [&](auto session) { return ${service_helpers.session_repository_field_name(parameter, config)}->access_session(session.name()); }); \
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
% elif c_type in ['ViChar', 'ViInt8', 'ViInt16']:
      ${c_type} ${parameter_name} = (${c_type})${request_snippet};\
% elif grpc_type == 'nidevice_grpc.Session':
      auto ${parameter_name}_grpc_session = ${request_snippet};
      ${c_type} ${parameter_name} = ${service_helpers.session_repository_field_name(parameter, config)}->access_session(${parameter_name}_grpc_session.name());\
% elif is_array and common_helpers.is_driver_typedef_with_same_size_but_different_qualifiers(c_type_underlying_type):
      auto ${parameter_name} = const_cast<${c_type_pointer}>(reinterpret_cast<const ${c_type_pointer}>(${request_snippet}.data()));\
%elif c_type in ['const int32[]', 'const uInt32[]']:
      auto ${parameter_name} = reinterpret_cast<${c_type_pointer}>(${request_snippet}.data());\
%elif grpc_type == 'bytes':
      auto ${parameter_name} = reinterpret_cast<const unsigned char*>(${request_snippet}.data());\
%elif service_helpers.is_scalar_input_that_needs_coercion(parameter):
      auto ${parameter_name}_raw = ${request_snippet};
      if (${parameter_name}_raw < std::numeric_limits<${c_type}>::min() || ${parameter_name}_raw > std::numeric_limits<${c_type}>::max()) {
          std::string message("value ");
          message.append(std::to_string(${parameter_name}_raw));
          message.append(" doesn't fit in datatype ");
          message.append("${c_type}");
          throw nidevice_grpc::ValueOutOfRangeException(message);
      }
      auto ${parameter_name} = static_cast<${c_type}>(${parameter_name}_raw);
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
% elif common_helpers.is_nidevice_enum_parameter(grpc_type):
      auto ${parameter_name} = ${request_snippet};\
% else:
      ${c_type} ${parameter_name} = ${request_snippet};\
% endif
</%def>

<%def name="set_output_vararg_parameter_sizes(parameters)">\
<%
  input_vararg_parameter = [p for p in parameters if common_helpers.is_repeated_varargs_parameter(p) and common_helpers.is_input_parameter(p)][0]
  input_parameter_name = common_helpers.get_cpp_local_name(input_vararg_parameter)
  output_vararg_parameters = [p for p in parameters if common_helpers.is_repeating_parameter(p) and not common_helpers.is_input_parameter(p)]
%>\
% for parameter in output_vararg_parameters:
<%
  parameter_name = common_helpers.get_cpp_local_name(parameter)
%>\
      ${parameter_name}Vector.resize(${input_parameter_name}.size());
% endfor
</%def>

## Initialize the output parameters for an API call.
<%def name="initialize_output_params(output_parameters)">\
<%
  output_parameters = common_helpers.get_params_needing_initialization(output_parameters)
%>\
% for parameter in output_parameters:
<%
  parameter_name = common_helpers.get_cpp_local_name(parameter)
  underlying_param_type = common_helpers.get_underlying_type_name(parameter["type"])
  grpc_type = parameter["grpc_type"]
  grpc_cpp_lib_type = service_helpers.get_protobuf_cpplib_type(grpc_type)
%>\
%   if 'hardcoded_value' in parameter:
${initialize_hardcoded_parameter(parameter)}
%   elif common_helpers.supports_standard_output_allocation_routines(parameter):
      auto ${parameter_name} = allocate_output_storage<${underlying_param_type}, ${grpc_cpp_lib_type}>(${str.join(", ", parameter.get("additional_arguments_to_output_allocation", []))});
%   elif common_helpers.is_repeating_parameter(parameter):
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
  buffer_size = common_helpers.get_buffer_size_expression(parameter)
  size = common_helpers.get_size_expression(parameter)
%>\
%     if common_helpers.supports_standard_copy_conversion_routines(parameter):
      std::vector<${underlying_param_type}> ${parameter_name}(${size}, ${underlying_param_type}());
## Byte arrays are leveraging a string as a buffer, so we don't need to take special consideration of the null terminator.
%     elif grpc_type == 'bytes':
      std::string ${parameter_name}(${size}, '\0');
## Driver string APIs require room in the buffer for the null terminator. We need to account for that when sizing the string.
%     elif common_helpers.is_string_arg(parameter) and common_helpers.get_size_mechanism(parameter) == 'fixed':
      std::string ${parameter_name}(${size}, '\0');
%     elif common_helpers.is_string_arg(parameter):
      std::string ${parameter_name};
      if (${buffer_size} > 0) {
          ${parameter_name}.resize(${size});
      }
%     elif service_helpers.is_output_array_that_needs_coercion(parameter):
      std::vector<${underlying_param_type}> ${parameter_name}(${size});
%     elif common_helpers.is_enum(parameter):
      response->mutable_${parameter_name}_raw()->Resize(${size}, 0);
      ${underlying_param_type}* ${parameter_name} = reinterpret_cast<${underlying_param_type}*>(response->mutable_${parameter_name}_raw()->mutable_data());
%     elif common_helpers.is_driver_typedef_with_same_size_but_different_qualifiers(underlying_param_type):
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


## Handles populating the response message after calling the driver API.
<%def name="populate_response(function_data, parameters, indent_level=0, init_method=False)">\
<%
  output_parameters = [p for p in parameters if common_helpers.is_output_parameter(p)]
  get_last_error_outputs = service_helpers.get_last_error_output_params(output_parameters)
  normal_outputs = [p for p in output_parameters if not p in get_last_error_outputs]
%>\
<%block filter="common_helpers.indent(indent_level)">\
${populate_error_check(function_data, parameters)}\
      response->set_status(status);
%if output_parameters:
${set_response_values(normal_outputs, init_method)}\
%endif
</%block>\
</%def>

## Handles populating the response message after calling the driver API.
<%def name="populate_error_check(function_data, parameters, indent_level=0, service_deref='')">\
<%
  config = data['config']
  input_parameters = [p for p in parameters if common_helpers.is_input_parameter(p)]
  resource_handle_types = service_helpers.get_resource_handle_types(config)
  error_parameters = [p for p in parameters if common_helpers.is_output_parameter(p) and "return_on_error_key" in p]
%>\
<%block filter="common_helpers.indent(indent_level)">\
<%
  session = 0
  handle_type = resource_handle_types[0]
  for parameter in input_parameters:
    if parameter['type'] in resource_handle_types:
      session = common_helpers.get_cpp_local_name(parameter)
      handle_type = parameter['type']
      break
  cpp_handle_type = handle_type[0].upper() + handle_type[1:]
  method_call = ""
  if function_data.get('exclude_from_get_last_error', False):
    method_call = f'return nidevice_grpc::ApiErrorToStatus(context, status);'
  else:
    method_call = f'return {service_deref}ConvertApiErrorStatusFor{cpp_handle_type}(context, status, {session});'
%>\
      %for error_parameter in error_parameters:
      context->AddTrailingMetadata("${error_parameter["return_on_error_key"]}", std::to_string(${common_helpers.pascal_to_snake(error_parameter["name"])}));
      %endfor
      if (!status_ok(status)) {
        ${method_call}
      }
</%block>\
</%def>


## Set output parameters updated through API call on the gRPC response message.
<%def name="set_response_values(output_parameters, init_method)">\
<%
  output_parameters = [p for p in output_parameters if service_helpers.should_copy_to_response(p)]
  config = data['config']
  enums = data['enums']
  namespace_prefix = config["namespace_component"] + "_grpc::"
%>\
% for parameter in output_parameters:
<%
  parameter_name = common_helpers.get_cpp_local_name(parameter)
  field_name = common_helpers.get_grpc_field_name(parameter)
%>\
%   if common_helpers.is_repeating_parameter(parameter):
<%
    varargs_parameter = [p for p in output_parameters if common_helpers.is_repeated_varargs_parameter(p)][0]
    varargs_parameter_name = common_helpers.get_cpp_local_name(varargs_parameter)
%>\
## Note that this currently only supports one repeated output parameter.
      for (int i = 0; i < ${parameter_name}Vector.size(); ++i) {
%     if 'enum' in parameter:
        response->add_${varargs_parameter_name}(static_cast<${parameter['enum']}>(${parameter_name}Vector[i]));
%     else:
        response->add_${varargs_parameter_name}(${parameter_name}Vector[i]);
%     endif
      }
%   elif common_helpers.is_repeated_varargs_parameter(parameter): #pass
%   elif common_helpers.is_enum(parameter) == True:
<%
  has_mapped_enum = 'mapped-enum' in parameter
  has_unmapped_enum = 'enum' in parameter
  is_bitfield_as_enum_array = 'bitfield_as_enum_array' in parameter
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
        response->set_${field_name}_mapped(static_cast<${namespace_prefix}${mapped_enum_name}>(${mapped_enum_iterator_name}->second));
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
      CopyBytesToEnums(${parameter_name}, response->mutable_${field_name}());
%       elif uses_raw_output_as_read_buffer:
<%
      raw_response_field = f"response->{field_name}_raw()"
      cast_x_to_enum = f"static_cast<{namespace_prefix}{parameter['enum']}>(x)"
      checked_convert_x_to_enum = f"checked_convert_{parameter_name}(x)"
      convert_x_to_enum = checked_convert_x_to_enum if use_checked_enum_conversion else cast_x_to_enum
%>\
${initialize_response_buffer(parameter_name=parameter_name, parameter=parameter)}\
${copy_to_response_with_transform(source_buffer=raw_response_field, parameter_name=parameter_name, transform_x=convert_x_to_enum, size=common_helpers.get_size_expression(parameter))}\
%       elif parameter['type'] == 'ViReal64':
      if(${parameter_name} == (int)${parameter_name}) {
        response->set_${field_name}(static_cast<${namespace_prefix}${parameter["enum"]}>(static_cast<int>(${parameter_name})));
      }
%       elif parameter.get("use_checked_enum_conversion", False):
      response->set_${field_name}(checked_convert_${parameter_name}(${parameter_name}));
%       else:
      response->set_${field_name}(static_cast<${namespace_prefix}${parameter["enum"]}>(${parameter_name}));
%       endif
%     endif
%     if is_bitfield_as_enum_array:
%       for flag_value, flag_enum_name in service_helpers.get_bitfield_value_to_name_mapping(parameter, enums).items():
      if (${parameter_name} & ${hex(flag_value)})
        response->add_${field_name}_array(${flag_enum_name});
%       endfor
%     endif
%     if not uses_raw_output_as_read_buffer: # Set data to raw, unless we *got* the data from raw.
      response->set_${field_name}_raw(${parameter_name});
%     endif
%   elif service_helpers.is_output_array_that_needs_coercion(parameter):
${initialize_response_buffer(parameter_name=parameter_name, parameter=parameter)}\
${copy_to_response_with_transform(source_buffer=parameter_name, parameter_name=parameter_name, transform_x="x", size=common_helpers.get_size_expression(parameter))}\
%   elif common_helpers.supports_standard_copy_conversion_routines(parameter):
      convert_to_grpc(${str.join(", ", [f'{parameter_name}', f'response->mutable_{field_name}()'] + parameter.get("additional_arguments_to_copy_convert", []))});
%   elif parameter['grpc_type'] == 'string':
      std::string ${parameter_name}_utf8;
      convert_to_grpc(${parameter_name}, &${parameter_name}_utf8);
      response->set_${field_name}(${parameter_name}_utf8);
%   elif common_helpers.is_string_arg(parameter):
      response->set_${field_name}(${parameter_name});
%   elif parameter['grpc_type'] == 'nidevice_grpc.Session':
%      if not init_method: # Non-init methods need to resolve the session ID from the out param.
      auto grpc_device_session_name = ${service_helpers.session_repository_field_name(parameter, config)}->resolve_session_name(${parameter_name});
%      endif
      response->mutable_${field_name}()->set_name(grpc_device_session_name);
%   elif common_helpers.is_array(parameter['type']):
%     if common_helpers.get_size_mechanism(parameter) == 'passed-in-by-ptr':
### size may have changed
      response->mutable_${field_name}()->Resize(${common_helpers.get_size_expression(parameter)}, 0);
%     endif
### pass: other array types don't need to copy.
%   else:
      response->set_${field_name}(${parameter_name});
%   endif
%   if common_helpers.is_regular_string_arg(parameter):
      nidevice_grpc::converters::trim_trailing_nulls(*(response->mutable_${field_name}()));
%   endif
### Handle ivi-dance-with-a-twist resizing.
%   if common_helpers.is_ivi_dance_array_with_a_twist_param(parameter):
<%
  size = common_helpers.get_size_expression(parameter)
%>\
%     if common_helpers.is_regular_byte_array_arg(parameter):
      response->mutable_${field_name}()->resize(${size});
%     elif common_helpers.is_regular_string_arg(parameter):
### pass: handled above with trim_trailing_nulls for all string outputs.
%     elif common_helpers.is_struct(parameter):
##        RepeatedPtrField doesn't support Resize(), so use DeleteSubrange()
##        to delete any extra elements.
      {
        auto shrunk_size = ${size};
        auto current_size = response->mutable_${field_name}()->size();
        if (shrunk_size != current_size) {
          response->mutable_${field_name}()->DeleteSubrange(shrunk_size, current_size - shrunk_size);
        }
      }
%     else:
## This code doesn't handle all parameter types (i.e., enums), see what initialize_output_params() does for that.
      response->mutable_${field_name}()->Resize(${size}, 0);
%     endif
%   endif
% endfor
</%def>

## Allocate the response buffer using get_size_expression.
<%def name="initialize_response_buffer(parameter_name, parameter)">\
        response->mutable_${parameter_name}()->Clear();
        response->mutable_${parameter_name}()->Reserve(${common_helpers.get_size_expression(parameter)});
</%def>

## Copy source_buffer to response->mutable_[parameter_name]() applying transform_x.
<%def name="copy_to_response_with_transform(source_buffer, parameter_name, transform_x, size)">\
        std::transform(
          ${source_buffer}.begin(),
          ${source_buffer}.begin() + ${size},
          google::protobuf::RepeatedFieldBackInserter(response->mutable_${parameter_name}()),
          [&](auto x) {
              return ${transform_x};
          });
</%def>

## Call the driver library method function_name.
## function_name: name of the function.
## function_data: function metadata.
## arg_string: comma separated argument list to pass to the function (see service_helpers.create_args),
## indent_level: (Optional) levels of additional indentation for the call snippet.
## library_ptr: (Optional) variable or expression for the library pointer (default: this->library_).
## declare_outputs: (Optional) If this is true, variables will be declared as "auto". If false, variables will just be assigned (default: False).
<%def name="call_library_method(
  function_name,
  function_data,
  arg_string,
  indent_level=0,
  library_ptr='library_',
  declare_outputs=True)">\
<%
  return_type = service_helpers.get_function_return_type(function_data)
  return_value_name = service_helpers.get_return_value_name(function_data)
  auto_decl = "auto " if declare_outputs else ""
%>\
<%block filter="common_helpers.indent(indent_level)">\
% if return_type != "void":
      ${auto_decl}${return_value_name} = ${library_ptr}->${function_name}(${arg_string});
% else:
      ${library_ptr}->${function_name}(${arg_string});
% endif
% if service_helpers.has_status_expression(function_data):
      ${auto_decl}status = ${service_helpers.get_status_expression(function_data)};
% endif
</%block>\
</%def>
