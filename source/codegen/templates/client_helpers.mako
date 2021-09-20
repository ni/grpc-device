<%!
import common_helpers
import client_helpers
import service_helpers
from client_helpers import ParamMechanism
%>

## Copy data from the client method params to the request.
<%def name="build_request(client_params)">\
%   for param in client_params:
<%
  field_name = common_helpers.camel_to_snake(param.name)
%>\
%     if param.mechanism == ParamMechanism.ARRAY:
  copy_array(${field_name}, request.mutable_${field_name}());
%     elif param.mechanism in [ParamMechanism.ENUM, ParamMechanism.MAPPED_ENUM]:
<%
  enum_type = client_helpers.get_enum_value_type(param)
  raw_type = client_helpers.get_enum_raw_type(param)
  is_mapped = param.mechanism == ParamMechanism.MAPPED_ENUM
  maybe_mapped_suffix = "_mapped" if is_mapped else ""
%>\
  const auto ${field_name}_ptr = ${field_name}.get_if<${enum_type}>();
  const auto ${field_name}_raw_ptr = ${field_name}.get_if<${raw_type}>();
  if (${field_name}_ptr) {
    request.set_${field_name}${maybe_mapped_suffix}(*${field_name}_ptr);
  }
  else if (${field_name}_raw_ptr) {
    request.set_${field_name}_raw(*${field_name}_raw_ptr);
  }
%     elif param.mechanism == ParamMechanism.COPY:
  request.mutable_${field_name}()->CopyFrom(${field_name});
%     else:
  request.set_${field_name}(${field_name});
%     endif
%   endfor
</%def>
