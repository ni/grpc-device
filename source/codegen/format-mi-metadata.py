"""Script for formatting mi-driver metadata in same style as hapigen output."""
import argparse
import codecs
import metadata_mutation
import os
from enum import Enum

from template_helpers import load_metadata


class _Formatter(object):
    # From https://stackoverflow.com/questions/3229419/how-to-pretty-print-nested-dictionaries
    # Changes
    #  - sort keys in tuple and dictionary for reproducability
    #  - Use 4 spaces rather than tab (\t) per indent level
    def __init__(self):
        self.types = {}
        self.htchar = "    "
        self.lfchar = "\n"
        self.indent = 0
        self._set_formatter(object, self.__class__._format_object)
        self._set_formatter(dict, self.__class__._format_dict)
        self._set_formatter(list, self.__class__._format_list)
        self._set_formatter(tuple, self.__class__._format_tuple)
        self._set_formatter(Enum, self.__class__._format_enum)

    def _set_formatter(self, obj, callback):
        self.types[obj] = callback

    def _get_formatter(self, value):
        formater = self.types[type(value) if type(value) in self.types else object]
        if isinstance(value, Enum):
            formater = self.types[Enum]

        return formater

    def __call__(self, value, **args):
        for key in args:
            setattr(self, key, args[key])
        formater = self._get_formatter(value)
        return formater(self, value, self.indent)

    def _format_object(self, value, indent):
        return repr(value)

    def _format_enum(self, value, indent):
        return repr(value.value)

    def _format_dict(self, value, indent):
        items = [
            self.lfchar
            + self.htchar * (indent + 1)
            + (self._get_formatter(key))(self, key, indent)
            + ": "
            + (self._get_formatter(value[key]))(self, value[key], indent + 1)
            for key in sorted(value)
        ]
        return "{%s}" % (",".join(items) + self.lfchar + self.htchar * indent)

    def _format_list(self, value, indent):
        items = [
            self.lfchar
            + self.htchar * (indent + 1)
            + (self._get_formatter(item))(self, item, indent + 1)
            for item in value
        ]
        return "[%s]" % (",".join(items) + self.lfchar + self.htchar * indent)

    def _format_tuple(self, value, indent):
        items = [
            self.lfchar
            + self.htchar * (indent + 1)
            + (self._get_formatter(item))(self, item, indent + 1)
            for item in sorted(value)
        ]
        return "(%s)" % (",".join(items) + self.lfchar + self.htchar * indent)


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


def _format_mi_metadata(metadata_dir: str):
    mi_drivers_to_update = [
        "nidcpower",
        "nidigitalpattern",
        "nidmm",
        "nifake",
        "nifgen",
        "niscope",
        "niswitch",
        "nitclk",
    ]
    mi_drivers = [driver for driver in os.listdir(metadata_dir) if driver in mi_drivers_to_update]
    pretty = _Formatter()
    for mi_driver in mi_drivers:
        metadata_names = ["attributes", "config", "enums", "functions"]
        path = f"{metadata_dir}/{mi_driver}/"
        metadata = load_metadata(path)
        _mutate_metadata(metadata)
        api_name = metadata["config"]["driver_name"]
        api_version = metadata["config"]["api_version"]
        for metadata_name in metadata_names:
            actual_metadata = metadata[metadata_name]
            pretty_metadata = "# -*- coding: utf-8 -*-"
            pretty_metadata += "\r\n"
            pretty_metadata += (
                f"# This file is generated from {api_name} API metadata version {api_version}"
            )
            pretty_metadata += "\r\n"
            pretty_metadata += f"{metadata_name} = {pretty(actual_metadata)}"
            with codecs.open(f"{path}{metadata_name}.py", "w", "utf-8-sig") as temp:
                temp.write(pretty_metadata)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Check if any file has changed that affects the Linux RT Feed."
    )
    parser.add_argument(
        "metadata",
        help="The path to the directory containing all of the metadata.",
    )
    args = parser.parse_args()
    _format_mi_metadata(args.metadata)
