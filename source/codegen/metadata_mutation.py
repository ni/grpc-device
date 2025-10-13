"""Metadata mutation."""

import copy
from collections import namedtuple
from typing import Any, Dict, Optional

import common_helpers

RESERVED_WORDS = [
    "abstract",
    "as",
    "base",
    "bool",
    "break",
    "byte",
    "case",
    "catch",
    "char",
    "checked",
    "class",
    "const",
    "continue",
    "decimal",
    "default",
    "delegate",
    "do",
    "double",
    "else",
    "enum",
    "event",
    "explicit",
    "extern",
    "false",
    "finally",
    "fixed",
    "float",
    "for",
    "foreach",
    "goto",
    "if",
    "implicit",
    "in",
    "int",
    "interface",
    "internal",
    "is",
    "lock",
    "long",
    "namespace",
    "new",
    "null",
    "object",
    "operator",
    "out",
    "override",
    "params",
    "private",
    "protected",
    "public",
    "readonly",
    "ref",
    "return",
    "sbyte",
    "sealed",
    "short",
    "sizeof",
    "stackalloc",
    "static",
    "string",
    "struct",
    "switch",
    "this",
    "throw",
    "true",
    "try",
    "typeof",
    "uint",
    "ulong",
    "unchecked",
    "unsafe",
    "ushort",
    "using",
    "virtual",
    "void",
    "volatile",
    "while",
]

# These are all of the coerced narrow numerics used in RFmx and DAQmx.
# This will not account for other aliases of narrow numerics.
# Note that params can also be marked coerced instead of updating this list.
# uint8 is not included because it can be represented as a byte.
KNOWN_COERCED_NARROW_NUMERIC_TYPES = [
    "int8",
    "int8_t",
    "uint8_t",
    "int16",
    "int16_t",
    "uInt16",
    "uint16_t",
]

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


def mutate(metadata: dict):
    """Mutate the given metadata."""
    config = metadata["config"]
    if config["driver_name"] in _ALREADY_MUTATED:
        return

    # Generate new streaming APIs for functions that support it.
    all_functions = {}

    for function_name, function in metadata["functions"].items():
        all_functions[function_name] = function

        if function.get("supports_streaming") is True:
            new_function_name = f"Begin{function_name}"
            all_functions[new_function_name] = generate_streaming_metadata(function)

    metadata["functions"] = all_functions

    move_zero_enums_to_front(metadata["enums"])

    for custom_type in config["custom_types"]:
        fields = custom_type["fields"]
        set_grpc_type_for_custom_type_fields(fields, config)

    attribute_expander = AttributeAccessorExpander(metadata)
    for function_name, function in metadata["functions"].items():
        parameters = function["parameters"]
        add_get_last_error_params_if_needed(function, config)
        sanitize_names(parameters)
        set_var_args_types(parameters, config)
        mark_size_params(parameters)
        mark_non_proto_params(parameters)
        mark_mapped_enum_params(parameters, metadata["enums"])
        populate_grpc_types(parameters, config)
        mark_coerced_narrow_numeric_parameters(parameters)
        attribute_expander.expand_attribute_value_params(function)
        attribute_expander.patch_attribute_enum_type(function_name, function)


def generate_streaming_metadata(function: dict) -> dict:
    """Generate the streaming API metadata for a given function."""
    streaming_parameters = []

    for param in function["parameters"]:
        new_param = copy.deepcopy(param)
        if new_param.get("is_streaming_type", False) is True:
            new_param["include_in_proto"] = False
        streaming_parameters.append(new_param)

    # Add the additional out parameter at the end
    streaming_parameters.append(
        {
            "direction": "out",
            "grpc_type": "ni.datamonikers.v1.Moniker",
            "name": "moniker",
            "type": "ni::data_monikers::Moniker",
        }
    )

    # Construct the streaming API metadata
    streaming_metadata = {
        "is_streaming_api": True,
        "parameters": streaming_parameters,
        "returns": function["returns"],
    }

    return streaming_metadata


def sanitize_names(parameters):
    """Sanitize name fields on a list of parameter objects.

    Also, populate the cppname field with the sanitized value.
    """
    for parameter in parameters:
        if "callback_params" in parameter:
            sanitize_names(parameter["callback_params"])
        parameter["cppName"] = parameter["name"]
        if parameter["cppName"] in RESERVED_WORDS:
            parameter["cppName"] += "Parameter"


def set_var_args_types(parameters, config):
    """Set information about varargs parameters in the metadata."""
    for parameter in parameters:
        if common_helpers.is_repeated_varargs_parameter(parameter):
            parameter["type"] = "..."


def mark_size_params(parameters):
    """Mark the size parameters in the metadata."""
    for param in parameters:
        mechanism = common_helpers.get_size_mechanism(param)
        if mechanism in {
            "len",
            "ivi-dance",
            "passed-in",
            "passed-in-by-ptr",
            "ivi-dance-with-a-twist",
        }:
            size_param = _get_size_param(param, parameters)
            size_param["is_size_param"] = True
            if mechanism == "passed-in-by-ptr":
                size_param["pointer"] = True


def mark_coerced_narrow_numeric_parameters(parameters: dict) -> None:
    """Mark parameters with narrow numeric types as coerced."""
    for param in parameters:
        param_type = common_helpers.get_underlying_type(param)
        if param_type in KNOWN_COERCED_NARROW_NUMERIC_TYPES:
            param["coerced"] = True


def mark_non_proto_params(parameters):
    """Mark the parameters that shouldn't be included in the proto request message.

    Their values should be derived from other sources in the service handlers.
    """
    for param in parameters:
        mechanism = common_helpers.get_size_mechanism(param)
        if mechanism in {"len", "len-in-bytes", "ivi-dance", "ivi-dance-with-a-twist"}:
            size_param = _get_size_param(param, parameters)
            if size_param["direction"] == "in":
                # Output size_params can still be included in the proto
                # as information.
                size_param["include_in_proto"] = False
            if mechanism in ["len", "len-in-bytes"]:
                if "determine_size_from" not in size_param:
                    size_param["determine_size_from"] = []
                size_param["determine_size_from"].append(param["name"])
                is_optional = common_helpers.has_optional_size_tag(param)
                if is_optional != size_param.get("linked_params_are_optional", is_optional):
                    raise Exception(
                        "Code generator does not support linked params that are a mix of optional and required",
                        size_param,
                    )
                size_param["linked_params_are_optional"] = is_optional


def _get_size_param(param, parameters):
    named_params = {p["name"]: p for p in parameters}
    return named_params.get(param["size"]["value"], None)


def mark_mapped_enum_params(parameters, enums):
    """Mark enum paramaters as mapped-enum if the enum has mappings."""
    for param in (p for p in parameters if "enum" in p):
        enum_name = param["enum"]
        enum = enums[enum_name]
        if "generate-mappings" in enum:
            del param["enum"]
            param["mapped-enum"] = enum_name


def populate_grpc_types(parameters, config):
    """Set the grpc_type of each parameter that doesn't already have it set."""
    for parameter in parameters:
        if "callback_params" in parameter:
            populate_grpc_types(parameter["callback_params"], config)
        if "grpc_type" in parameter:
            continue
        parameter["grpc_type"] = common_helpers.get_grpc_type(parameter["type"], config)


def set_grpc_type_for_custom_type_fields(fields, config):
    """Set the grpc_type for each field of a custom type."""
    for field in fields:
        if "grpc_type" in field:
            continue
        elif "enum" in field:
            field["grpc_type"] = field["enum"]
        else:
            field["grpc_type"] = common_helpers.get_grpc_type(field["type"], config)


def _get_short_enum_type_name(typename: str) -> str:
    if typename in ["char[]", "const char[]", "char"]:
        return "String"
    stripped_name = common_helpers.strip_prefix(typename, "Vi")
    return common_helpers.ensure_pascal_case(stripped_name)


def _remove_leading_group_name(enum_value_name, group_name):
    return common_helpers.strip_prefix(enum_value_name, f"{group_name.upper()}_")


def _add_leading_enum_name(enum_value_name, enum_name, enum):
    enum_value_prefix = enum.get(
        "enum-value-prefix", common_helpers.pascal_to_snake(enum_name).upper()
    )
    return f"{enum_value_prefix}_{enum_value_name}"


def _add_attribute_values_enums(enums, attribute_enums_by_type, group_name):
    """Add new enums to enums metadata, for use as the value parameter of SetAttribute APIs."""
    for type_name in attribute_enums_by_type:
        unmapped_values = {}
        # For mapped enums, we want legacy (no 'order') entries first (in encounter order),
        # then append all ordered entries sorted by their 'order' field. We collect them
        # separately and merge after processing all contributing enums of this type.
        mapped_legacy_values = {}
        mapped_ordered_values = []  # list of tuples (order, value_name, value_value)

        for enum_name in sorted(attribute_enums_by_type[type_name]):
            enum = enums[enum_name]
            is_mapped_enum = enum.get("generate-mappings", False)
            for value in enum["values"]:
                # Remove the leading group name (if any) because it will be redundant in the
                # aggregate enum.
                value_name = _remove_leading_group_name(value["name"], group_name)
                # Add a leading enum to differentiate sub-enums within the aggregate values enum.
                value_name = _add_leading_enum_name(value_name, enum_name, enum)
                if is_mapped_enum:
                    if "order" in value:
                        mapped_ordered_values.append((value["order"], value_name, value["value"]))
                    else:
                        mapped_legacy_values[value_name] = value["value"]
                else:
                    unmapped_values[value_name] = value["value"]

        # Now append ordered mapped entries sorted by their 'order'.
        if mapped_ordered_values:
            # stable sort to maintain original order in case of same order fields
            mapped_ordered_values.sort(key=lambda t: t[0])
            for _, value_name, value_val in mapped_ordered_values:
                mapped_legacy_values[value_name] = value_val

        shortened_type_name = _get_short_enum_type_name(type_name)
        enum_value_prefix = (f"{group_name}_{shortened_type_name}").upper()
        unmapped_enum_name = _get_attribute_values_enum_name(group_name, type_name)
        mapped_enum_name = _get_attribute_values_enum_name(group_name, type_name, is_mapped=True)
        _add_enum(unmapped_enum_name, unmapped_values, enums, enum_value_prefix)
        _add_enum(mapped_enum_name, mapped_legacy_values, enums, enum_value_prefix, is_mapped=True)


AttributeReferencingParameter = namedtuple(
    "AttributeReferencingParameter", ["attribute_group", "parameter"]
)


class AttributeAccessorExpander:
    """Wraps an _attribute_type_map of: group -> type -> attributes.

    Also implements the metadata_mutations to _add_attribute_values_enums,
    _expand_attribute_function_value_param, and patch_attribute_enum_type.
    """

    def __init__(self, metadata):  # noqa: D107
        self._config = metadata["config"]
        self._enums = metadata["enums"]
        self._attribute_type_map = {}

        for group in common_helpers.get_attribute_groups(metadata):
            attribute_enums_by_type = common_helpers.get_attribute_enums_by_type(group.attributes)
            _add_attribute_values_enums(self._enums, attribute_enums_by_type, group.name)
            self._attribute_type_map[group.name] = attribute_enums_by_type

    def _get_attribute_reference_parameter(
        self, parameters
    ) -> Optional[AttributeReferencingParameter]:
        """Get the parameter that references an attribute, if there is one."""

        def try_resolve_attribute_reference(parameter) -> Optional[AttributeReferencingParameter]:
            param_type = parameter["grpc_type"]
            # All attribute parameters must have a grpc_type of {group_name}Attributes.
            # In MI, this is added during metadata mutation of ViAttr types.
            attr_suffix = common_helpers.get_attribute_enum_suffix(self._config)
            potential_attribute_name = common_helpers.strip_suffix(param_type, attr_suffix)
            if potential_attribute_name in self._attribute_type_map:
                return AttributeReferencingParameter(potential_attribute_name, parameter)
            return None

        # Assumption: there are 0 or 1 parameters that reference an attribute per function.
        attribute_resolve_results = (try_resolve_attribute_reference(p) for p in parameters)
        valid_references = (ref for ref in attribute_resolve_results if ref)
        return next(valid_references, None)

    def patch_attribute_enum_type(self, function_name, func):
        """Update the attribute parameter to point to the proper enum name.

        Only applies for drivers that splits attribute enums by type.

        For example, DAQmx has a Get/Set/ResetBufferAttributeUInt32 functions. The parameter that
        selects _which_ attribute needs to use the proper attribute enum. The input says that the
        grpc_type is BufferAttribute, but the generated code splits the enums by type, with a
        special group for Reset functions. So in this example, the Get and Set functions' attribute
        enum would be BufferUInt32Attribute, and the Reset function's attribute enum would be
        BufferResetAttribute.
        """
        if not common_helpers.get_split_attributes_by_type(self._config):
            return
        parameters = func["parameters"]
        attribute_reference = self._get_attribute_reference_parameter(parameters)
        if attribute_reference:
            group = attribute_reference.attribute_group
            attribute_param = attribute_reference.parameter
            if function_name.startswith("Reset"):
                sub_group = "Reset"
            else:
                value_param = _get_attribute_function_value_param(func)
                sub_group = common_helpers.get_grpc_type_name_for_identifier(
                    value_param["type"], self._config
                )
            if common_helpers.supports_raw_attributes(self._config):
                attribute_param["enum"] = common_helpers.get_attribute_enum_name(
                    group, sub_group, self._config
                )
                attribute_param["grpc_type"] = "int32"
                attribute_param["raw_attribute"] = True
            else:
                attribute_param["grpc_type"] = common_helpers.get_attribute_enum_name(
                    group, sub_group, self._config
                )

    def expand_attribute_value_params(self, func):
        """Update the attrVal parameter to use the proper enum, if available."""
        parameters = func["parameters"]
        attribute_reference = self._get_attribute_reference_parameter(parameters)
        if attribute_reference:
            _expand_attribute_function_value_param(
                func,
                self._enums,
                self._attribute_type_map[attribute_reference.attribute_group],
                attribute_reference.attribute_group,
            )


def _expand_attribute_function_value_param(
    function, enums, attribute_enums_by_type, service_class_prefix
):
    """For SetAttribute and CheckAttribute, update function metadata to mark value param as enum."""
    value_param = _get_attribute_function_value_param(function)
    if not value_param:
        return
    if value_param["direction"] == "out":
        if common_helpers.is_static_castable_enum_type(value_param):
            value_param["use_checked_enum_conversion"] = True
        else:
            return

    if value_param["type"] == "ViConstString":
        param_type = "ViString"
    else:
        param_type = common_helpers.get_underlying_type(value_param)
    if param_type in attribute_enums_by_type:
        enum_name = _get_attribute_values_enum_name(service_class_prefix, param_type)
        mapped_enum_name = _get_attribute_values_enum_name(
            service_class_prefix, param_type, is_mapped=True
        )
        enum_exists = enum_name in enums
        mapped_enum_exists = mapped_enum_name in enums
        if enum_exists:
            value_param["enum"] = enum_name
        if mapped_enum_exists:
            value_param["mapped-enum"] = mapped_enum_name
        if not enum_exists and not mapped_enum_exists:
            # Ideally there must be an enum associated with this parameter for SetAttribute* API.
            # Since the enum is empty, users will be passing in raw values. Make it clear via
            # naming.
            value_param["name"] += "_raw"


def _get_attribute_function_value_param(function):
    return next(
        (
            param
            for param in function["parameters"]
            if param["name"] in {"value", "attributeValue", "attrVal"}
        ),
        None,
    )


def _get_attribute_values_enum_name(group_name, type, is_mapped=False):
    enum_name_suffix = "Mapped" if is_mapped else ""
    shortened_type_name = _get_short_enum_type_name(type)
    return group_name + shortened_type_name + "AttributeValues" + enum_name_suffix


def _add_enum(enum_name, enum_values, enums, enum_value_prefix, is_mapped=False):
    if not enum_values:
        return
    values = [{"name": name, "value": enum_values[name]} for name in enum_values]
    new_enum = {
        "enum-value-prefix": enum_value_prefix,
        "generate-mappings": is_mapped,
        "values": values,
    }
    enums.update({enum_name: new_enum})


def move_zero_enums_to_front(enums: dict) -> None:
    """Put the enum value with value 0 _first_ if there is one, or else add UNSPECIFIED enum value.

    protobuf requires that the first enum value be zero. For enums missing a zero value,
    we will add an UNSPECIFIED enum value to the front (this is the best practice). But if
    there already is a zero enum, make sure that pre-existing zero value is at the front.
    """
    for enum in enums.values():
        values = enum["values"]
        try:
            i, _ = next((i, v) for i, v in enumerate(values) if v["value"] == 0)
            values.insert(0, values.pop(i))
        except StopIteration:
            pass


def add_get_last_error_params_if_needed(function_data: Dict[str, Any], config: dict) -> None:
    """Add get_last_error parameters to the list if any are specified in config."""
    if function_data.get("exclude_from_get_last_error"):
        return

    parameters = function_data["parameters"]
    for get_last_error_field in config.get("get_last_error", []):
        parameters.append(
            {
                "direction": "out",
                "get_last_error": "deprecated",
                "name": get_last_error_field["name"],
                "type": get_last_error_field["type"],
            }
        )
