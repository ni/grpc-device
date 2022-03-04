"""Helpers for mako templates."""

from importlib import import_module
from pathlib import Path
from typing import Union

from mako.lookup import TemplateLookup  # type: ignore
from mako.template import Template  # type: ignore


def instantiate_mako_template(template_file_name: str) -> Template:
    """Instantiate the mako template in the given file."""
    current_dir = Path(__file__).parent
    template_directory = current_dir / "templates"
    template_file_path = template_directory / template_file_name
    template_lookup = TemplateLookup(directories=str(template_directory))
    return Template(filename=str(template_file_path), lookup=template_lookup)


def write_if_changed(output_file_path: Union[Path, str], new_contents: str) -> None:
    """Write new_contents to output_file_path if new_contents != the contents of output_file_path.

    This prevents downstream recompiles when codegen runs but does not change a given file.
    """
    old_contents = _read_file_contents(output_file_path)
    if old_contents != new_contents:
        with open(output_file_path, "w+", newline="") as f:
            f.write(new_contents)


def load_metadata(metadata_dir: Union[Path, str]) -> dict:
    """Load the metadata from the given directory."""
    metadata_path = Path(metadata_dir)
    module = import_module("metadata." + metadata_path.name)

    return module.metadata


def _read_file_contents(output_file_path: Union[Path, str]) -> str:
    try:
        with Path(output_file_path).open("r", newline="") as f:
            return f.read()
    except FileNotFoundError:
        return ""
