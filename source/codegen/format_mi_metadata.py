"""Script for formatting mi-driver metadata in same style as hapigen output."""
import argparse
import io
import os
from enum import Enum

import metadata_mutation
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
        metadata_mutation.mutate(metadata)
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
            with io.open(
                f"{path}{metadata_name}.py", "w", encoding="utf-8", newline="\n"
            ) as temp:
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
