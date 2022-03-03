"""Shared service file generation."""

from argparse import ArgumentParser
from pathlib import Path

from template_helpers import instantiate_mako_template, write_if_changed, load_metadata


def _generate_register_all_services(metadata_dir: Path, output_dir: Path) -> None:
    driver_modules = [
        load_metadata(p)
        for p in sorted(metadata_dir.iterdir())
        if p.is_dir() and "fake" not in p.name
    ]

    template = instantiate_mako_template("register_all_services.h.mako")

    write_if_changed(
        output_dir / "register_all_services.h", template.render(drivers=driver_modules)
    )

    template = instantiate_mako_template("register_all_services.cpp.mako")

    write_if_changed(
        output_dir / "register_all_services.cpp", template.render(drivers=driver_modules)
    )


if __name__ == "__main__":
    parser = ArgumentParser(description="Generate shared service files for grpc-device.")
    parser.add_argument(
        "metadata", help="The path to the root directory containing all API metadata."
    )
    parser.add_argument(
        "--output", "-o", help="The path to the top-level directory to save the generated files.."
    )

    args = parser.parse_args()
    output_path = "." if args.output is None else args.output
    _generate_register_all_services(Path(args.metadata), Path(output_path))
