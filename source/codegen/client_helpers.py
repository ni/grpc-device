import common_helpers
import re
from collections import namedtuple
from copy import deepcopy
from enum import Enum

class ParamMechanism(Enum):
  BASIC = 0
  ARRAY = 1
  ENUM = 2
  COPY = 3

ClientParam = namedtuple(
  "ClientParam", 
  [
    "name", 
    "type", 
    "mechanism"
  ])


def create_params(func: dict) -> list[str]:
  client_params = get_client_parameters(func)

  param_list = [
    f"{p.type} {p.name}"
    for p in client_params
  ]

  return param_list


def stub_param() -> str:
  return f"const {stub_ptr_alias()}& stub"


def create_streaming_params(func: dict) -> str:
  params = create_params(func)
  client_context_param = "::grpc::ClientContext& context"
  params = [stub_param()] + [client_context_param] + params
  return str.join(", ", params)


def create_unary_params(func: dict) -> str:
  params = create_params(func)
  params = [stub_param()] + params
  return str.join(", ", params)

PROTOBUF_PRIM_TYPES = ["bool", "double", "float"]

PROTOBUF_TYPE_TO_CPP_TYPE = {
"double": "double",
"float": "float",
"int32": "int32",
"int64": "int64",
"uint32": "uint32",
"uint64": "uint64",
"sint32": "int32",
"sint64": "int64",
"fixed32": "uint32",
"fixed64": "uint64",
"sfixed32": "int32",
"sfixed64": "int64",
"bool": "bool",
"string": "string",
"bytes": "string"
}

def is_basic_type(grpc_type: str) -> bool:
  return (
    grpc_type in PROTOBUF_PRIM_TYPES
    or grpc_type in PROTOBUF_TYPE_TO_CPP_TYPE
    or grpc_type.endswith("Attributes")
  )


def protobuf_namespace_alias() -> str:
  return "pb"


def get_cpp_client_param_type(param: dict) -> str:
  grpc_type = param["grpc_type"]

  if is_grpc_array(param):
    underlying_type = common_helpers.strip_prefix(grpc_type, "repeated ")
    underlying_type = get_cpp_type_for_protobuf_type(underlying_type)
    return f"std::vector<{underlying_type}>"


  if "enum" in param:
    enum_less_param = deepcopy(param)
    enum_less_param.pop("enum")
    base_type = get_cpp_type_for_protobuf_type(grpc_type)
    if base_type:
      return f"simple_variant<{param['enum']}, {base_type}>"
    return param["enum"]

  return get_cpp_type_for_protobuf_type(grpc_type)


def get_cpp_type_for_protobuf_type(protobuf_type: str) -> str:
  if protobuf_type in PROTOBUF_PRIM_TYPES:
    return protobuf_type

  if protobuf_type in PROTOBUF_TYPE_TO_CPP_TYPE:
    cpp_type = PROTOBUF_TYPE_TO_CPP_TYPE[protobuf_type]
    return f"{protobuf_namespace_alias()}::{cpp_type}"

  return protobuf_type.replace(".", "::")


def const_ref_t(t: str) -> str:
  return f"const {t}&"


def get_param_mechanism(param: dict) -> ParamMechanism:
  if is_grpc_array(param):
    return ParamMechanism.ARRAY
  if "enum" in param:
    return ParamMechanism.ENUM
  if is_basic_type(param["grpc_type"]):
    return ParamMechanism.BASIC
  return ParamMechanism.COPY


def create_client_param(param: dict) -> ClientParam:
  name = common_helpers.camel_to_snake(param["name"])
  param_type = get_cpp_client_param_type(param)
  param_type = const_ref_t(param_type)
  param_mechanism = get_param_mechanism(param)

  return ClientParam(name, param_type, param_mechanism)


def is_grpc_array(param: dict) -> bool:
  return param["grpc_type"].startswith("repeated ")


def stub_ptr_alias():
  return "StubPtr"


def get_client_parameters(func: dict) -> list[ClientParam]:
  inputs = [
    p
    for p in func["parameters"]
    if common_helpers.is_input_parameter(p)
  ]

  inputs = common_helpers.filter_parameters_for_grpc_fields(inputs)

  return [
    create_client_param(p)
    for p in inputs
  ]


def split_types_from_variant(variant_type: str) -> tuple[str, str]:
  match = re.match(r".*simple_variant<([^,]+), ([^>]+)>", variant_type)
  return (match[1], match[2])


def get_enum_value_type(param: ClientParam) -> str:
  enum, _ = split_types_from_variant(param.type)
  return enum


def get_enum_raw_type(param: ClientParam) -> str:
  _, raw = split_types_from_variant(param.type)
  return raw


def streaming_response_type(response_type: str) -> str:
  return f"std::unique_ptr<grpc::ClientReader<{response_type}>>"
