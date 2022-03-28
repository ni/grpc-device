"""Service generation."""

import argparse
import os

import metadata_mutation
import metadata_validation
from mako.lookup import TemplateLookup  # type: ignore
from template_helpers import instantiate_mako_template, load_metadata, write_if_changed


def _generate_service_file(metadata, template_file_name, generated_file_suffix, gen_dir):
    module_name = metadata["config"]["module_name"]
    output_dir = os.path.join(gen_dir, module_name)
    file_name = module_name + generated_file_suffix
    output_file_path = os.path.join(output_dir, file_name)

    os.makedirs(output_dir, exist_ok=True)
    template = instantiate_mako_template(template_file_name)
    write_if_changed(output_file_path, template.render(data=metadata))


def _mutate_metadata(metadata: dict):
    config = metadata["config"]

    metadata_mutation.move_zero_enums_to_front(metadata["enums"])

    attribute_expander = metadata_mutation.AttributeAccessorExpander(metadata)
    for function_name in metadata["functions"]:
        function = metadata["functions"][function_name]
        parameters = function["parameters"]
        metadata_mutation.add_get_last_error_params_if_needed(function, config)
        metadata_mutation.sanitize_names(parameters)
        metadata_mutation.set_var_args_types(parameters, config)
        metadata_mutation.mark_size_params(parameters)
        metadata_mutation.mark_non_proto_params(parameters)
        metadata_mutation.mark_mapped_enum_params(parameters, metadata["enums"])
        metadata_mutation.populate_grpc_types(parameters, config)
        metadata_mutation.mark_coerced_narrow_numeric_parameters(parameters)
        attribute_expander.expand_attribute_value_params(function)
        attribute_expander.patch_attribute_enum_type(function_name, function)


def _generate_all(metadata_dir: str, gen_dir: str, validate_only: bool):
    metadata = load_metadata(metadata_dir)
    metadata_validation.validate_metadata(metadata)
    if validate_only:
        return

    lookup = TemplateLookup(directories=metadata_dir)
    metadata["lookup"] = lookup
    _mutate_metadata(metadata)
    _generate_service_file(metadata, "proto.mako", ".proto", gen_dir)
    _generate_service_file(metadata, "service.h.mako", "_service.h", gen_dir)
    _generate_service_file(metadata, "service.cpp.mako", "_service.cpp", gen_dir)
    _generate_service_file(metadata, "service_registrar.h.mako", "_service_registrar.h", gen_dir)
    _generate_service_file(
        metadata, "service_registrar.cpp.mako", "_service_registrar.cpp", gen_dir
    )
    _generate_service_file(metadata, "library_interface.h.mako", "_library_interface.h", gen_dir)
    _generate_service_file(metadata, "library.cpp.mako", "_library.cpp", gen_dir)
    _generate_service_file(metadata, "library.h.mako", "_library.h", gen_dir)
    _generate_service_file(metadata, "mock_library.h.mako", "_mock_library.h", gen_dir)
    _generate_service_file(metadata, "client.h.mako", "_client.h", gen_dir)
    _generate_service_file(metadata, "client.cpp.mako", "_client.cpp", gen_dir)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Generate files for specified NI driver API gRPC service."
    )
    parser.add_argument(
        "metadata",
        help="The path to the directory containing the metadata for the API being generated.",
    )
    parser.add_argument(
        "--output",
        "-o",
        help="The path to the top-level directory to save the generated files. The API-specific sub-directories will be automatically created.",
    )
    parser.add_argument(
        "--validate",
        "-v",
        dest="validate",
        action="store_true",
        help="Just validate the metadata and don't generate any files",
    )
    args = parser.parse_args()
    _generate_all(args.metadata, "." if args.output is None else args.output, args.validate)
