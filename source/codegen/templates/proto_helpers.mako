<%!
  import common_helpers
  import proto_helpers
%>

## Define a proto enum capturing all attributes from the metadata.
<%def name="define_attribute_enum(attributes)">\
<%
  config = data["config"]
  service_class_prefix = config["service_class_prefix"]
  attribute_value_prefix = service_class_prefix.upper() + "_ATTRIBUTE"
%>\
enum ${service_class_prefix}Attributes {
  ${attribute_value_prefix}_UNSPECIFIED = 0;
% for attribute in attributes:
<%
   attribute_name = attributes[attribute]["name"]
%>\
  ${attribute_value_prefix}_${attribute_name} = ${attribute};
% endfor
}
</%def>

## Define enums in the proto for each metadata enum referenced in a proto message.
<%def name="define_enums(used_enums)">\
<%
  enums = data["enums"]
%>\
% for enum_name in (e for e in enums if e in used_enums):
<%
  enum_value_prefix = common_helpers.pascal_to_snake(enum_name).upper()
  enum = enums[enum_name]
  allow_alias = proto_helpers.should_allow_alias(enum)
  nonint_index = 1
%>\
enum ${enum_name} {
% if allow_alias == True:
  option allow_alias = true;
% endif
  ${enum_value_prefix}_UNSPECIFIED = 0;
% for value in enum["values"]:
% if enum.get("generate-mappings", False):
  ${enum_value_prefix}_${value["name"]} = ${nonint_index};
<%
  nonint_index = nonint_index + 1
%>\
% else:
  ${enum_value_prefix}_${value["name"]} = ${value["value"]};
% endif
% endfor
}

% endfor
</%def>

## If there is a custom proto mako template in the metadata, insert it.
<%def name="insert_custom_template_if_found()">\
<%
  config = data["config"]
  lookup = data["lookup"]
  has_custom_template = False
  if len(config["custom_types"]) > 0:
    custom_template = "custom_proto.mako"
    has_custom_template = True
%>\
% if has_custom_template:
${lookup.get_template(custom_template).render()}
% endif
</%def>

## Define a proto request message for a given API function.
<%def name="define_request_message(function, input_parameters)">\
<%
  config = data["config"]
  service_class_prefix = config["service_class_prefix"]
  index = 0
%>\
message ${common_helpers.snake_to_pascal(function)}Request {
% for parameter in input_parameters:
<%
  index  = index + 1
  if 'grpc_type' in parameter:
    parameter_type = parameter['grpc_type']
  else:
    parameter_type = proto_helpers.determine_function_parameter_type(parameter, service_class_prefix)
%>\
% if common_helpers.is_enum(parameter):
<%
  index = index + 1
  is_array = common_helpers.is_array(parameter["type"])
  non_enum_type = proto_helpers.get_grpc_type_from_ivi(parameter["type"], is_array, service_class_prefix)
  parameter_name = common_helpers.camel_to_snake(parameter["name"])
%>\
  oneof ${parameter_name}_enum {
    ${parameter_type} ${parameter_name} = ${index-1};
    ${non_enum_type} ${parameter_name}_raw = ${index};
  }
% else:
  ${parameter_type} ${common_helpers.camel_to_snake(parameter["name"])} = ${index};
% endif
% endfor
}
</%def>

## Define a proto response message for a given API function.
<%def name="define_response_message(function, output_parameters)">\
<%
  config = data["config"]
  service_class_prefix = config["service_class_prefix"]
  index = 1
%>\
message ${common_helpers.snake_to_pascal(function)}Response {
  int32 status = 1;
% for parameter in output_parameters:
<%
  index = index + 1
  if "grpc_type" in parameter:
    parameter_type = parameter["grpc_type"]
  else:
    parameter_type = proto_helpers.determine_function_parameter_type(parameter, service_class_prefix)
%>\
% if common_helpers.is_enum(parameter):
<%
  index = index + 1
  is_array = common_helpers.is_array(parameter["type"])
  non_enum_type = proto_helpers.get_grpc_type_from_ivi(parameter["type"], is_array, service_class_prefix)
%>\
  ${parameter_type} ${common_helpers.camel_to_snake(parameter["name"])} = ${index-1};
  ${non_enum_type} ${common_helpers.camel_to_snake(parameter["name"])}_raw = ${index};
% else:
  ${parameter_type} ${common_helpers.camel_to_snake(parameter["name"])} = ${index};
% endif
% endfor
}
</%def>
