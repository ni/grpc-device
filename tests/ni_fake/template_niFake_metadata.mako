//---------------------------------------------------------------------
//---------------------------------------------------------------------
License header (if applicable)
//---------------------------------------------------------------------
//---------------------------------------------------------------------
Proto file for the NIFake Metadata
//---------------------------------------------------------------------
//---------------------------------------------------------------------
Syntax = "proto3";
//---------------------------------------------------------------------
//---------------------------------------------------------------------
Package
//---------------------------------------------------------------------
//---------------------------------------------------------------------
Imports (sorted)

//---------------------------------------------------------------------
//---------------------------------------------------------------------
<%
def is_output_parameter(parameter):
    if "out" in parameter["direction"]:
      return True
    return False

def is_input_parameter(parameter):
    if "in" in parameter["direction"]:
        return True
    return False

def camel_to_snake(camelString):
  camelString = list(camelString)
  index = 0
  snake_string = camelString
  for x in camelString :
      if x.isupper():
          camelString[index] = camelString[index].lower();
          camelString.insert(index, "_")
          
      index = index + 1
  return ("".join(camelString)) 
%>

//---------------------------------------------------------------------
// The niFakeService definition.
//---------------------------------------------------------------------
service NiFakeService {
% for function in data["functions"]:
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
% for attribute in data["attributes"]:
<%
   attribute_name = data["attributes"][attribute]["name"]
%>
${attribute_name} = ${attribute};
% endfor
}

//---------------------------------------------------------------------
// The niFakeEnums definition.
//---------------------------------------------------------------------
enum FakeValues {
NoValue = 0;
% for enum_list in data["enums"]:
<%
   enums = data["enums"][enum_list]
%>
   % for values in enums :
   <%
   value_array = enums[values]
   %>
      % for value in value_array :
${value["name"]} = ${value["value"]};
      % endfor   
   % endfor    
% endfor
}


//---------------------------------------------------------------------
// Parameters & Results
//---------------------------------------------------------------------
% for function in data["functions"]:
<% 
   parameter_array = data["functions"][function]["parameters"] 
   index = 0
%>\
message ${function}Parameters {
   % for parameter in parameter_array:
   <%
      if is_input_parameter(parameter) == False:
         continue;     
      index  = index +1
   %>
${parameter["type"]} ${camel_to_snake(parameter["name"])} = ${index}  
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

${parameter["type"]} ${camel_to_snake(parameter["name"])} = ${index}  
   %endfor
   
}


% endfor