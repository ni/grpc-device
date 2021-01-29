//---------------------------------------------------------------------
//---------------------------------------------------------------------
syntax = "proto3";

//---------------------------------------------------------------------
//---------------------------------------------------------------------
no imports

//---------------------------------------------------------------------
//---------------------------------------------------------------------
options

//---------------------------------------------------------------------
//---------------------------------------------------------------------

packages 
//---------------------------------------------------------------------
//---------------------------------------------------------------------

<%
def is_output_parameter(parameter):
    if 'out' in parameter['direction']:
      return True
    return False

def is_input_parameter(parameter):
    if 'in' in parameter['direction']:
        return True
    return False 
%>


//---------------------------------------------------------------------
// The niFakeService definition.
//---------------------------------------------------------------------
service niFakeService {
% for function in data['functions']:
<% 
   method_name = function
%>
rpc ${method_name}(${method_name}Parameters) returns (${method_name}Result) {};
% endfor
}

//---------------------------------------------------------------------
// The niFakeAttributes definition.
//---------------------------------------------------------------------
enum FakeAttributes {
NoValue = 0;
% for attribute in data['attributes']:
<%
   attribute_name = data['attributes'][attribute]['name']
%>
${attribute_name} = ${attribute};
% endfor
}

//---------------------------------------------------------------------
// The niFakeEnums definition.
//---------------------------------------------------------------------
enum FakeValues {
NoValue = 0;
% for enum_list in data['enums']:
<%
   enums = data['enums'][enum_list]
%>
   % for values in enums :
   <%
   value_array = enums[values]
   %>
      % for value in value_array :
${value['name']} = ${value['value']};
      % endfor   
   % endfor    
% endfor
}


//---------------------------------------------------------------------
// Parameters & Results
//---------------------------------------------------------------------
% for function in data['functions']:
<% 
   parameter_array = data['functions'][function]['parameters'] 
   index = 0
%>\
message ${function}Parameters {
   % for parameter in parameter_array:
   <%
      if is_input_parameter(parameter) == False:
         continue;     
      index  = index +1
   %>
${parameter['type']} ${parameter['name']} = ${index}  
   % endfor

}


message ${function}Result {

int32 status = 1;
<%
index = 1
%>\
   %for parameter in parameter_array:
   <%
    if is_output_parameter(parameter) == False:
        continue;  
    index = index + 1
   %>

${parameter['type']} ${parameter['name']} = ${index}  
   %endfor
   
}


% endfor