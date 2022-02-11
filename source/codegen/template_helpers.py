from importlib import import_module
from pathlib import Path

from mako.lookup import TemplateLookup
from mako.template import Template, Template


def instantiate_mako_template(template_file_name: str) -> Template:
    current_dir = Path(__file__).parent
    template_directory = current_dir / "templates"
    template_file_path = template_directory / template_file_name
    template_lookup = TemplateLookup(directories=str(template_directory))
    return Template(filename=str(template_file_path), lookup=template_lookup)


def write_if_changed(output_file_path: str, new_contents: str) -> None:
    """Write new_contents to output_file_path if new_contents != the contents
    of output_file_path.

    This prevents downstream recompiles when codegen runs but does not change
    a given file.
    """
    old_contents = _read_file_contents(output_file_path)
    if old_contents != new_contents:
        with open(output_file_path, "w+", newline="") as f:
            f.write(new_contents)


def load_metadata(metadata_dir: str) -> dict:
    metadata_path = Path(metadata_dir)
    module = import_module("metadata." + metadata_path.name)

    return module.metadata


def _read_file_contents(output_file_path: str) -> str:
    try:
        with open(output_file_path, "r", newline="") as f:
            return f.read()
    except FileNotFoundError:
        return ""
