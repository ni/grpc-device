<%!
  import common_helpers
  import proto_helpers
%>

## Define a proto enum capturing attributes from the metadata.
<%def name="define_attribute_enum(group_name, data_type, attributes)">\
<%
  attribute_value_prefix = group_name.upper() + "_ATTRIBUTE"

  # When attributes are split-by-datatype, the actual attributes don't need a type-name disambiguator because
  # the original unsplit list didn't have duplicates. However, they each need a unique-ified UNSPECIFIED param.
  unspecified_disambiguator = "_" + common_helpers.pascal_to_snake(data_type).upper() if data_type else ""
  unspecified_attribute_value_prefix = group_name.upper() + unspecified_disambiguator + "_ATTRIBUTE"
%>\
enum ${common_helpers.get_attribute_enum_name(group_name, data_type)} {
  ${unspecified_attribute_value_prefix}_UNSPECIFIED = 0;
% for attribute in attributes:
<%
   attribute_name = attributes[attribute]["name"]
%>\
  ${attribute_value_prefix}_${attribute_name} = ${attribute};
% endfor
}
</%def>

## Define enums in the proto for each metadata enum referenced in a proto message.
<%def name="define_function_enums(function_enums)">\
<%
  enums = data["enums"]
  enum_definitions = proto_helpers.get_enum_definitions(function_enums, enums)
%>\
% for enum_name in enum_definitions:
enum ${enum_name} {
%   if enum_definitions[enum_name]["allow_alias"]:
  option allow_alias = true;
%   endif
%   for value in enum_definitions[enum_name]["values"]:
  ${value["name"]} = ${value["value"]};
%   endfor
}

% endfor
</%def>

## If there is a custom proto mako template in the metadata, insert it.
<%def name="insert_custom_template_if_found()">\
<%
  config = data["config"]
  lookup = data["lookup"]
  has_custom_template = False
  if config["custom_types"]:
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
  request_parameters = proto_helpers.get_message_parameter_definitions(input_parameters)
%>\
message ${common_helpers.snake_to_pascal(function)}Request {
% for parameter in request_parameters:
%   if parameter.get("use_oneof", False):
  oneof ${parameter["name"]} {
%     for oneof_parameter in parameter["parameters"]:
    ${oneof_parameter["type"]} ${oneof_parameter["name"]} = ${oneof_parameter["grpc_field_number"]};
%     endfor
  }
%   else:
  ${parameter["type"]} ${parameter["name"]} = ${parameter["grpc_field_number"]};
%   endif
% endfor
}
</%def>

## Define a proto response message for a given API function.
<%def name="define_response_message(function, output_parameters)">\
<%
  config = data["config"]
  service_class_prefix = config["service_class_prefix"]
  response_parameters = proto_helpers.get_message_parameter_definitions(output_parameters)
%>\
message ${common_helpers.snake_to_pascal(function)}Response {
% for parameter in response_parameters:
  ${parameter["type"]} ${parameter["name"]} = ${parameter["grpc_field_number"]};
% endfor
}
</%def>
