"""Helpers for creating client .h/.cpp files."""

import re
from collections import namedtuple
from enum import Enum
from typing import List, Tuple

import common_helpers


class ParamMechanism(Enum):
    """Enumeration of parameter mechanisms supported by client codegen."""

    BASIC = 0
    ARRAY = 1
    ENUM = 2
    MAPPED_ENUM = 3
    COPY = 4
    BITFIELD_AS_ENUM_ARRAY = 5


ClientParam = namedtuple("ClientParam", ["name", "cppName", "type", "mechanism"])


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
    "bytes": "string",
}


def _to_parameter_list(client_params: List[ClientParam]) -> List[str]:
    param_list = [f"{p.type} {p.cppName}" for p in client_params]

    return param_list


def stub_param() -> str:
    """Get the C++ stub parameter."""
    return f"const {stub_ptr_alias()}& stub"


def create_streaming_params(client_params: List[ClientParam]) -> str:
    """Build the C++ parameter list for streaming functions."""
    params = _to_parameter_list(client_params)
    client_context_param = "::grpc::ClientContext& context"
    params = [stub_param()] + [client_context_param] + params
    return str.join(", ", params)


def create_unary_params(client_params: List[ClientParam]) -> str:
    """Build the C++ parameter list for normal functions."""
    params = _to_parameter_list(client_params)
    params = [stub_param()] + params
    return str.join(", ", params)


def _is_basic_type(grpc_type: str) -> bool:
    return (
        grpc_type in PROTOBUF_PRIM_TYPES
        or grpc_type in PROTOBUF_TYPE_TO_CPP_TYPE
        or grpc_type.endswith("Attributes")
        or grpc_type.endswith("Attribute")
    )


def protobuf_namespace_alias() -> str:
    """Get the protobuf namespace alias."""
    return "pb"


def _get_cpp_client_param_type(param: dict, enums: dict) -> str:
    grpc_type = param["grpc_type"]

    if _is_grpc_array(param):
        underlying_type = common_helpers.strip_prefix(grpc_type, "repeated ")
        underlying_type = _get_cpp_type_for_protobuf_type(underlying_type)
        return f"std::vector<{underlying_type}>"

    if "enum" in param:
        base_type = _get_cpp_type_for_protobuf_type(grpc_type)
        if base_type:
            return f"simple_variant<{param['enum']}, {base_type}>"
        return param["enum"]

    if "mapped-enum" in param:
        enum = param["mapped-enum"]
        base_type = common_helpers.get_enum_value_cpp_type(enums[enum])
        return f"simple_variant<{enum}, {base_type}>"

    if common_helpers.is_bitfield_as_enum_array(param):
        enum = common_helpers.get_bitfield_enum_type(param)
        base_type = common_helpers.get_enum_value_cpp_type(enums[enum])
        return f"simple_variant<std::vector<{enum}>, {base_type}>"

    return _get_cpp_type_for_protobuf_type(grpc_type)


def _get_cpp_type_for_protobuf_type(protobuf_type: str) -> str:
    if protobuf_type in PROTOBUF_PRIM_TYPES:
        return protobuf_type

    if protobuf_type in PROTOBUF_TYPE_TO_CPP_TYPE:
        cpp_type = PROTOBUF_TYPE_TO_CPP_TYPE[protobuf_type]
        return f"{protobuf_namespace_alias()}::{cpp_type}"

    return protobuf_type.replace(".", "::")


def _const_ref_t(t: str) -> str:
    return f"const {t}&"


def _get_param_mechanism(param: dict) -> ParamMechanism:
    if _is_grpc_array(param):
        return ParamMechanism.ARRAY
    if common_helpers.is_bitfield_as_enum_array(param):
        return ParamMechanism.BITFIELD_AS_ENUM_ARRAY
    if "enum" in param:
        return ParamMechanism.ENUM
    if "mapped-enum" in param:
        return ParamMechanism.MAPPED_ENUM
    if _is_basic_type(param["grpc_type"]):
        return ParamMechanism.BASIC
    return ParamMechanism.COPY


def _create_client_param(param: dict, enums: dict) -> ClientParam:
    name = common_helpers.get_grpc_field_name(param)
    cppname = common_helpers.get_grpc_client_field_name(param)
    param_type = _get_cpp_client_param_type(param, enums)
    param_type = _const_ref_t(param_type)
    param_mechanism = _get_param_mechanism(param)

    return ClientParam(name, cppname, param_type, param_mechanism)


def _is_grpc_array(param: dict) -> bool:
    return param["grpc_type"].startswith("repeated ")


def stub_ptr_alias():
    """Get the stub pointer alias."""
    return "StubPtr"


def get_client_parameters(func: dict, enums: dict) -> List[ClientParam]:
    """Create a list of ClientParam objects for the given function."""
    inputs = [p for p in func["parameters"] if common_helpers.is_input_parameter(p)]

    inputs = common_helpers.filter_parameters_for_grpc_fields(inputs)

    return [_create_client_param(p, enums) for p in inputs]


def _split_types_from_variant(variant_type: str) -> Tuple[str, str]:
    match = re.match(r".*simple_variant<([^,]+), ([^>]+)>", variant_type)
    assert match
    return (match[1], match[2])


def get_enum_value_type(param: ClientParam) -> str:
    """Get the enum name of the given enum ClientParam."""
    enum, _ = _split_types_from_variant(param.type)
    return enum


def get_enum_raw_type(param: ClientParam) -> str:
    """Get the raw C++ value_type of the given enum ClientParam."""
    _, raw = _split_types_from_variant(param.type)
    return raw


def streaming_response_type(response_type: str) -> str:
    """Wrap the given response type with a reader for streaming functions."""
    return f"std::unique_ptr<grpc::ClientReader<{response_type}>>"


def filter_functions_to_include_in_client(functions: dict) -> dict:
    """Include only those functions which dont have 'include_in_client' tag in metadata."""
    filtered_functions = {}
    for func_name in functions.keys():
        if functions[func_name].get("include_in_client", True) is True:
            filtered_functions[func_name] = functions[func_name]
    return filtered_functions
