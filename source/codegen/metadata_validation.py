"""Metadata validation."""
from typing import Any, Dict, List, Set

import common_helpers
import service_helpers
from schema import And, Optional, Or, Schema, Use  # type: ignore


# grpc device metadata mutations have been applied to MI drivers in
# source to minimize transformations that happen outside of hapigen
_ALREADY_MUTATED = (
    "NI-DCPower",
    "NI-Digital Pattern Driver",
    "NI-DMM",
    "NI-FAKE",
    "NI-FGEN",
    "NI-SCOPE",
    "NI-SWITCH",
    "NI-TClk",
)


class RULES:
    """Rules that can be suppressed."""

    # In general, arrays should have sizes passed in to the underlying C API.
    ARRAY_PARAMETER_NEEDS_SIZE = "ARRAY_PARAMETER_NEEDS_SIZE"
    # The gRPC layer can determine the size of input arrays, so we should not require callers to
    # pass in the size. We should not add any new suppressions of this type.
    INPUT_ARRAY_SHOULD_NOT_HAVE_PASSED_IN_SIZE = "INPUT_ARRAY_SHOULD_NOT_HAVE_PASSED_IN_SIZE"
    # In general, enums shouldn't have duplicate values. This is helpful for catching typos although
    # there are a few enums that have legitimate duplicates.
    ENUMS_SHOULD_NOT_HAVE_DUPLICATE_VALUES = "ENUMS_SHOULD_NOT_HAVE_DUPLICATE_VALUES"
    # The ENUMS_SHOULD_BE_USED validation rule is intended to catch enums that are not mapped
    # to functions or attributes because of incomplete or mishandled metadata. Note that any
    # unreferenced enums will not be included in the proto file. These enums should be reviewed
    # and if they are correctly included-but-not-referenced and are not required to be
    # in the proto file,the rule can be suppressed.
    ENUMS_SHOULD_BE_USED = "ENUMS_SHOULD_BE_USED"


DOCUMENTATION_SCHEMA = Schema(
    {
        "description": str,
        Optional("python_description"): str,
        Optional("note"): str,
        Optional("table_body"): list,
        Optional("caution"): str,
    }
)

SIZE_SCHEMA = Schema(
    {
        "mechanism": And(str, lambda s: not common_helpers.is_unsupported_size_mechanism_type(s)),
        "value": Or(str, int),
        Optional("value_twist"): str,
        Optional("tags"): [str],
    },
)

PARAM_SCHEMA = Schema(
    {
        "direction": And(str, lambda s: s in ("in", "out")),
        "name": str,
        Optional("type"): str,
        Optional("grpc_type"): str,
        Optional("documentation"): DOCUMENTATION_SCHEMA,
        Optional("bitfield_as_enum_array"): str,
        Optional("enum"): str,
        Optional("size"): SIZE_SCHEMA,
        Optional("default_value"): Or(str, bool, int, float, None),
        Optional("is_repeated_capability"): bool,
        Optional("repeated_capability_type"): str,
        Optional("use_array"): bool,
        Optional("numpy"): bool,
        # integer in string form, make sure int(x) doesn't raise
        Optional("grpc_field_number"): And(str, Use(int)),
        # integer in string form, make sure int(x) doesn't raise
        Optional("grpc_raw_field_number"): And(str, Use(int)),
        # integer in string form, make sure int(x) doesn't raise
        Optional("grpc_mapped_field_number"): And(str, Use(int)),
        Optional("type_in_documentation"): str,
        Optional("include_in_proto"): bool,
        Optional("proto_only"): bool,
        Optional("is_session_handle"): bool,
        Optional("is_session_name"): bool,
        Optional("repeating_argument"): bool,
        Optional("python_api_converter_name"): str,
        Optional("attribute"): str,
        Optional("hardcoded_value"): str,
        Optional("is_compound_type"): bool,
        Optional("max_length"): int,
        Optional("repeated_var_args"): bool,
        Optional("pointer"): bool,
        Optional("coerced"): bool,
        Optional("callback_params"): [dict],
        Optional("callback_token"): bool,
        Optional("use_in_python_api"): bool,
        Optional("cross_driver_session"): str,
        Optional("cpp_local_name"): str,
        Optional("grpc_name"): str,
        Optional("return_value"): bool,
        Optional("supports_standard_copy_convert"): bool,
        Optional("supports_standard_output_allocation"): bool,
        Optional("get_last_error"): str,
        Optional("additional_arguments_to_copy_convert"): [str],
        Optional("additional_arguments_to_output_allocation"): [str],
        Optional("proto_only"): bool,
        Optional("input_passed_by_ptr"): bool,
        Optional("cppName"): str,
        Optional("determine_size_from"): [str],
        Optional("is_size_param"): bool,
        Optional("linked_params_are_optional"): bool,
        Optional("mapped-enum"): str,
        Optional("is_optional"): bool,
        Optional("is_optional_in_python"): bool,
        Optional("ctypes_data_type"): Or(str, None),
        Optional("has_explicit_buffer_size"): bool,
        Optional("is_list"): bool,
        Optional("python_data_type"): str,
        Optional("python_type_annotation"): str,
        Optional("python_description"): str,
        Optional("python_default_value"): Or(str, bool, int, float, None),
    }
)

FUNCTION_SCHEMA = Schema(
    {
        "parameters": [PARAM_SCHEMA],
        "returns": str,
        Optional("cname"): str,
        Optional("codegen_method"): And(
            str,
            lambda s: s
            in (
                "public",
                "private",
                "CustomCode",
                "no",
                "python-only",
                "grpc-only",
                "CustomCodeCustomProtoMessage",
            ),
        ),
        Optional("init_method"): bool,
        Optional("stream_response"): bool,
        Optional("is_error_handling"): bool,
        Optional("render_in_session_base"): bool,
        Optional("method_name_for_documentation"): str,
        Optional("use_session_lock"): bool,
        Optional("documentation"): DOCUMENTATION_SCHEMA,
        Optional("method_templates"): list,
        Optional("custom_close"): str,
        Optional("custom_close_method"): bool,
        Optional("python_name"): str,
        Optional("status_expression"): str,
        Optional("include_in_client"): bool,
        Optional("exclude_from_get_last_error"): bool,
        Optional("calling_convention"): str,
        Optional("python_class_name"): str,
        Optional("handle_parameter"): dict,
        Optional("adaptor_parameter"): dict,
        Optional("is_python_factory"): bool,
        Optional("python_description"): str,
    }
)

ATTRIBUTE_SCHEMA = Schema(
    {
        "name": str,
        Optional("access"): And(
            str, lambda s: s in ["read", "read only", "write", "write only", "read-write"]
        ),
        "type": str,
        Optional("resettable"): bool,
        Optional("enum"): str,
        Optional("python_enum"): str,
        Optional("channel_based"): bool,
        Optional("attribute_class"): str,
        Optional("type_in_documentation"): str,
        Optional("documentation"): DOCUMENTATION_SCHEMA,
        Optional("lv_property"): str,
        Optional("repeated_capability_type"): str,
        Optional("python_type"): str,
        Optional("python_name"): str,
        Optional("codegen_method"): str,
        Optional("grpc_type"): str,
        Optional("c_function_name"): str,
        Optional("calling_convention"): str,
        Optional("bitfield_enum"): str,
        Optional("ctypes_data_type"): str,
        Optional("handle_parameters"): dict,
        Optional("python_object_constructor_params"): dict,
        Optional("has_explicit_read_buffer_size"): bool,
        Optional("python_object_has_factory"): bool,
        Optional("python_object_module_location"): str,
        Optional("python_object_type"): str,
        Optional("has_explicit_write_buffer_size"): bool,
        Optional("is_list"): bool,
        Optional("is_python_object"): bool,
        Optional("python_class_name"): str,
        Optional("python_data_type"): str,
        Optional("python_description"): str,
    }
)

SIMPLE_ATTRIBUTE_SCHEMA = Schema(
    {
        "name": str,
    },
)

ENUM_SCHEMA = Schema(
    {
        Optional("python_name"): str,
        "values": [
            {
                "name": str,
                "value": Or(str, int, float),
                Optional("python_name"): str,
                Optional("documentation"): DOCUMENTATION_SCHEMA,
                Optional("type"): str,
            }
        ],
        Optional("generate-mappings"): bool,
        Optional("enum-value-prefix"): str,
        Optional("generate-mapping-type"): bool,
        Optional("force-include"): bool,
        Optional("codegen_method"): str,
    }
)


def validate_metadata(metadata: dict):
    """Validate the given metadata."""
    try:
        for function_name in metadata["functions"]:
            _validate_function(function_name, metadata)
        for attribute_group in common_helpers.get_attribute_groups(metadata):
            for attribute_id in attribute_group.attributes:
                _validate_attribute(attribute_group.attributes[attribute_id], metadata)
        function_enums = set(
            common_helpers.get_function_enums(metadata["functions"], metadata["enums"])
        )
        attribute_enums = _get_attribute_enums(metadata)
        used_enums = function_enums.union(attribute_enums)
        for enum_name in metadata["enums"]:
            if not _rule_is_suppressed(metadata, RULES.ENUMS_SHOULD_BE_USED, ["enums", enum_name]):
                _validate_enum(enum_name, used_enums, metadata)
    except Exception as e:
        raise Exception(f"Failed to validate {metadata['config']['namespace_component']}") from e


def _rule_is_suppressed(metadata: dict, rule: str, path: List[str]) -> bool:
    suppression_dict_name = path[0] + "_validation_suppressions"
    suppression_dict = metadata.get(suppression_dict_name, {})
    for entry in path[1:-1]:
        suppression_dict = suppression_dict.get(entry, {})
    last_entry = path[-1]
    if last_entry not in suppression_dict:
        return False
    return rule in suppression_dict[last_entry]


def _parameter_name_exists(function: dict, name: str) -> bool:
    return any([param for param in function["parameters"] if param["name"] == name])


def _validate_function(function_name: str, metadata: dict):
    try:
        function: Dict[str, Any] = metadata["functions"][function_name]
        ivi_dance_with_a_twist_params = []
        ivi_dance_with_a_twist_sizes = set()
        ivi_dance_with_a_twist_twists = set()
        if function.get("codegen_method", "public") != "no":
            FUNCTION_SCHEMA.validate(function)
            if "documentation" in function:
                DOCUMENTATION_SCHEMA.validate(function["documentation"])
            duplicate_resource_handles_allowed = metadata["config"].get(
                "duplicate_resource_handles_allowed", False
            )
            is_init_method = function.get("init_method", False)
            for parameter in function["parameters"]:
                _validate_parameter_size(parameter, function_name, metadata)
                if "type" not in parameter:
                    if "grpc_type" not in parameter:
                        raise Exception(f"parameter {parameter['name']} has no type or grpc_type!")
                    if not parameter.get("repeated_var_args", False) and not parameter.get(
                        "proto_only", False
                    ):
                        raise Exception(
                            f"parameter {parameter['name']} has no type and repeated_var_args or proto_only is not set!"
                        )
                if "enum" in parameter:
                    if parameter["enum"] not in metadata["enums"]:
                        raise Exception(
                            f"parameter {parameter['name']} has enum {parameter['enum']} that was not found!"
                        )
                if "max_length" in parameter:
                    if "repeated_var_args" not in parameter:
                        raise Exception(
                            f"parameter {parameter['name']} has max_length but no repeated_var_args!"
                        )
                if "callback_params" in parameter:
                    for callback_param in parameter["callback_params"]:
                        try:
                            PARAM_SCHEMA.validate(callback_param)
                        except Exception:
                            raise Exception(
                                f"Failed to validate callback_param with name {callback_param['name']}"
                            )
                if "hardcoded_value" in parameter:
                    if parameter.get("include_in_proto", True):
                        raise Exception(
                            f"parameter {parameter['name']} has hardcoded_value but is include_in_proto!"
                        )
                if "cross_driver_session" in parameter:
                    # Assumption: there's no code that automatically sets the grpc_type for
                    # cross_driver_sessions and nidevice_grpc.Session is the only type that works.
                    if parameter.get("grpc_type", None) not in [
                        "nidevice_grpc.Session",
                        "repeated nidevice_grpc.Session",
                    ]:
                        raise Exception(
                            f"parameter {parameter['name']} is a cross_driver_session but does not have a grpc_type of nidevice_grpc.Session!"
                        )
                    # Assumption: a method that creates a session (via accessing a cross-driver
                    # session) must be an init_method to ensure that the session is tracked in the
                    # session repository.
                    if parameter["direction"] == "out" and not function.get("init_method"):
                        raise Exception(
                            f"parameter {parameter['name']} is a cross_driver_session output but {function_name} is not an init_method!"
                        )
                if parameter.get("size", {}).get("mechanism", None) == "ivi-dance-with-a-twist":
                    size = parameter["size"]
                    ivi_dance_with_a_twist_params.append(parameter["name"])
                    ivi_dance_with_a_twist_sizes.add(size["value"])
                    ivi_dance_with_a_twist_twists.add(size["value_twist"])
                if duplicate_resource_handles_allowed:
                    if not is_init_method:
                        if parameter["direction"] == "out" and parameter[
                            "type"
                        ] in service_helpers.get_resource_handle_types(metadata["config"]):
                            raise Exception(
                                f"{metadata['config']['namespace_component']} allows duplicate resource handles in the session repository. Therefore, the handle we'd get for \"{parameter['name']}\" can't be mapped back to a Session to provide to the client!"
                            )
                if common_helpers.is_optional_param(parameter):
                    if common_helpers.is_enum(parameter):
                        raise Exception(
                            f"\"{parameter['name']}\" is marked optional and an enum which doesn't make sense!"
                        )
                    if function.get("codegen_method", "public") != "CustomCode":
                        raise Exception(
                            f"\"{parameter['name']}\" is marked optional but the function is not marked CustomCode!"
                        )
    except Exception as e:
        raise Exception(f"Failed to validate function {function_name}") from e


def _validate_attribute(attribute: dict, metadata: dict):
    try:
        if metadata["config"]["module_name"] == "nisync":
            # The attributes for nisync only have a name
            SIMPLE_ATTRIBUTE_SCHEMA.validate(attribute)
        else:
            ATTRIBUTE_SCHEMA.validate(attribute)
        if "enum" in attribute:
            if attribute["enum"] not in metadata["enums"]:
                raise Exception(
                    f"attribute {attribute['name']} has enum {attribute['enum']} that was not found!"
                )

    except Exception as e:
        raise Exception(
            f"Failed to validate attribute with name {attribute.get('name', '(none)')}"
        ) from e


def _validate_enum(enum_name: str, used_enums: Set[str], metadata: dict):
    try:
        enum: Dict[str, Any] = metadata["enums"][enum_name]
        ENUM_SCHEMA.validate(enum)
        if enum_name in used_enums:
            generate_mappings = enum.get("generate-mappings", False)
            value_types = set([type(value["value"]) for value in enum["values"]])
            if not generate_mappings:
                value_types.remove(type(1))
                if any(value_types):
                    raise Exception(
                        f"generate-mappings is False, but values have non-int types: {value_types}"
                    )
            # This is to avoid the duplicate enum value rule running on Attribute enums
            # that will be present in the pre-mutated drivers.
            if metadata["config"]["driver_name"] in _ALREADY_MUTATED:
                return
            values = [value["value"] for value in enum["values"]]
            values_set = set(values)
            if len(values) != len(values_set):
                if not _rule_is_suppressed(
                    metadata, RULES.ENUMS_SHOULD_NOT_HAVE_DUPLICATE_VALUES, ["enums", enum_name]
                ):
                    raise Exception(f"Duplicate values in enum!")
        else:
            raise Exception(
                f"Enum is in metadata but is not referenced by a function/attribute or force-included."
            )
    except Exception as e:
        raise Exception(f"Failed to validate enum with name {enum_name}") from e


def _validate_parameter_size(parameter: dict, function_name: str, metadata: dict):
    function: Dict[str, Any] = metadata["functions"][function_name]
    size = parameter.get("size", None)
    if size is None:
        if common_helpers.is_array(parameter.get("type", "")) and not _is_string_type(
            parameter, metadata
        ):
            if not _rule_is_suppressed(
                metadata,
                RULES.ARRAY_PARAMETER_NEEDS_SIZE,
                ["functions", function_name, "parameters", parameter["name"]],
            ):
                raise Exception(f"parameter {parameter['name']} is an array but has no size!")
    if size is not None:
        SIZE_SCHEMA.validate(size)
        mechanism = size["mechanism"]
        if mechanism in [
            "len",
            "len-in-bytes",
            "ivi-dance",
            "ivi-dance-with-a-twist",
            "passed-in",
            "passed-in-by-ptr",
            "two-dimension",
        ]:
            if not _parameter_name_exists(function, size["value"]):
                raise Exception(
                    f"parameter {parameter['name']} refers to nonexistant parameter {size['value']} in its size value!"
                )
        if mechanism == "two-dimension":
            size_param = common_helpers.get_param_with_name(function["parameters"], size["value"])
            if common_helpers.has_size_mechanism_tag(size_param, "optional"):
                # There may be a case where this is valid, but it's more likely as a mistake.
                raise Exception(
                    f"parameter {size_param['name']} is optional but used by {parameter['name']} as a two-dimension size param!"
                )

        if mechanism == "ivi-dance-with-a-twist":
            if "value_twist" not in size:
                raise Exception(
                    f"parameter {parameter['name']} doesn't have value_twist in its size parameter!"
                )
            if not _parameter_name_exists(function, size["value_twist"]):
                raise Exception(
                    f"parameter {parameter['name']} refers to nonexistant parameter {size['value_twist']} in its size value_twist!"
                )
        else:
            if "value_twist" in size:
                raise Exception(
                    f"parameter {parameter['name']} has value_twist in its size parameter but is not ivi-dance-with-a-twist!"
                )
        if parameter["direction"] == "in":
            if mechanism == "passed-in" or mechanism == "passed-in-by-ptr":
                if not _rule_is_suppressed(
                    metadata,
                    RULES.INPUT_ARRAY_SHOULD_NOT_HAVE_PASSED_IN_SIZE,
                    ["functions", function_name, "parameters", parameter["name"]],
                ):
                    raise Exception(
                        f"parameter {parameter['name']} is an input but has mechanism {mechanism}! Use mechanism len instead so the user doesn't have to explicitly pass in the size."
                    )
            if mechanism in ["ivi-dance", "ivi-dance-with-a-twist"]:
                raise Exception(
                    f"parameter {parameter['name']} is an input but has mechanism {mechanism}!"
                )
        else:
            if mechanism in ["len", "len-in-bytes"]:
                raise Exception(
                    f"parameter {parameter['name']} is an output but has mechanism {mechanism}!"
                )


def _get_attribute_enums(metadata: dict) -> Set[str]:
    attribute_enums = set()
    for attribute_group in common_helpers.get_attribute_groups(metadata):
        for attribute_id in attribute_group.attributes:
            attribute = attribute_group.attributes[attribute_id]
            if "enum" in attribute:
                attribute_enums.add(attribute["enum"])
    return attribute_enums


def _is_string_type(parameter: dict, metadata: dict) -> bool:
    if parameter.get("is_compound_type", False):
        return False
    grpc_type = parameter.get("grpc_type", None)
    if grpc_type is None:
        grpc_type = common_helpers.get_grpc_type(parameter["type"], metadata["config"])
    return grpc_type == "string"
