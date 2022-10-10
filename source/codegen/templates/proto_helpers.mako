<%!
  from mako.exceptions import TopLevelLookupException

  import common_helpers
  import proto_helpers
%>

## Define a proto enum capturing attributes from the metadata.
<%def name="define_attribute_enum(group_name, sub_group, attributes, config)">\
<%
  attribute_value_prefix = group_name.upper() + "_ATTRIBUTE"

  # When attributes are split-by-datatype, the actual attributes don't need a type-name disambiguator because
  # the original unsplit list didn't have duplicates. 
  # But there are 2 cases that need to be disambiguated:
  # * Each attribute has an UNSPECIFIED placeholder.
  # * Reset attributes overlap the data-type-specific attributes.
  attribute_disambiguator = "_" + common_helpers.pascal_to_snake(sub_group).upper() if sub_group else ""
  disambiguated_attribute_value_prefix = group_name.upper() + attribute_disambiguator + "_ATTRIBUTE"
  unspecified_attribute_value_prefix = disambiguated_attribute_value_prefix
  attribute_value_prefix = disambiguated_attribute_value_prefix if sub_group == "Reset" else attribute_value_prefix
%>\
% if attributes:
enum ${common_helpers.get_attribute_enum_name(group_name, sub_group, config)} {
  ${unspecified_attribute_value_prefix}_UNSPECIFIED = 0;
%   for attribute in attributes:
<%
   attribute_name = attributes[attribute]["name"]
%>\
  ${attribute_value_prefix}_${attribute_name} = ${attribute};
%   endfor
}

% endif
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
  custom_template = None
  try:
    custom_template = lookup.get_template("custom_proto.mako").render()
  except TopLevelLookupException:
    pass # no template
%>\
% if custom_template:
${custom_template}
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
% if (parameter.get("is_get_last_error_output", False)):
  ${parameter["type"]} ${parameter["name"]} = ${parameter["grpc_field_number"]} [deprecated = true];
% else:
  ${parameter["type"]} ${parameter["name"]} = ${parameter["grpc_field_number"]};
% endif
% endfor
}
</%def>

## Define a proto message for a given custom type.
<%def name="define_custom_type(custom_type)">\
<%
  config = data["config"]
  used_indexes = []
%>\
message ${custom_type["grpc_name"]} {
% for field in common_helpers.filter_parameters_for_grpc_fields(custom_type["fields"]):
<%
  field_type = field["grpc_type"]
  field_name = common_helpers.get_grpc_field_name(field)
  field_number = proto_helpers.generate_parameter_field_number(field, used_indexes)
%>\
  ${field_type} ${field_name} = ${field_number};
% endfor
}
</%def>
