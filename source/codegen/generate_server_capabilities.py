"""Service information generation."""

import argparse
import json
from pathlib import Path

from common_helpers import get_driver_readiness
from template_helpers import load_metadata


def _generate_file(metadata_dir: Path, output_dir: Path) -> None:
    service_instance_names = []
    driver_modules = [
        load_metadata(p)
        for p in sorted(metadata_dir.iterdir())
        if p.is_dir() and "fake" not in p.name
    ]
    for data in driver_modules:
        config = data["config"]
        if get_driver_readiness(config) == "Release":
            service_name = f'{config["module_name"]}_grpc.{config["service_class_prefix"]}'
            service_instance_names.append(service_name)
    service_information_dict = {}
    service_information_dict["provided_service_interfaces"] = service_instance_names
    output_file_path = Path(output_dir).joinpath("server_capabilities.json")
    with open(output_file_path, "w") as outfile:
        json.dump(service_information_dict, outfile, indent=4)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Generate NI gRPC-device server implementation information."
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
    args = parser.parse_args()
    output_path = "." if args.output is None else args.output
    _generate_file(Path(args.metadata), Path(output_path))
