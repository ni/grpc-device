"""Script validating that any imported proto file matches its corresponding generated one.

Expects import path as source/codegen/protos and generated folder path.

Background: 
All MI driver metadata is being sourced from hapigen. We're also creating .proto files
based on the metadata in that component. So when an MI driver is updated, the export will have
a metadata folder with [attributes.py, config.py, enums.py, functions.py, <driver-name>.proto]. Someone
will copy these files to grpc-device: metadata files (.py) to source/codegen/metadata folder and the .proto file to source/codegen/protos.

Purpose: 
Since, at the moment, we have both grpc-device and hapigen generating the driver .proto files we want a way to validate
that they're creating equivalent ones. This script will check imported .proto files (copied out of hapigen-based driver exports)
against their corresponding .proto file that gets generated in grpc-device to make sure they match.

On Mismatch:
1. Make sure .proto from driver export is copied over to grpc-device
2. Make sure you built grpc-device locally to get any generated folder changes (specifically .proto files there)
3. The proto generators (mako and helper python files) likely changed between grpc-device and hapigen and need to be synced up.
"""

import argparse
import filecmp
import glob
import os
import sys


def _check_mismatched_protos(imported_dir: str, generated_dir: str) -> bool:
    any_mismatches = False
    file_paths = glob.glob(f"{imported_dir}/**/*.proto", recursive=True)
    for file_path in file_paths:
        driver_dir_name = os.path.split(os.path.split(file_path)[0])[1]
        file_name = os.path.basename(file_path)
        driver_and_file_path = f"{driver_dir_name}/{file_name}"
        generated_file_path = f"{generated_dir}/{driver_and_file_path}"
        compare_result = filecmp.cmp(file_path, generated_file_path)
        if compare_result:
            print(
                f"✔️ {f'{imported_dir}/{driver_and_file_path}'} matched {f'{generated_dir}/{driver_and_file_path}.'}"
            )
        else:
            any_mismatches = True
            print(
                f"❌ {f'{imported_dir}/{driver_and_file_path}'} did not match {f'{generated_dir}/{driver_and_file_path}'}."
            )
    return any_mismatches


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Check if any file has changed that affects the Linux RT Feed."
    )
    parser.add_argument(
        "-i",
        "--imported",
        help="The path to the directory containing all of the imported proto files.",
    )
    parser.add_argument(
        "-g",
        "--generated",
        help="The path to the directory containing all the generated files.",
    )
    args = parser.parse_args()
    any_mismatches = _check_mismatched_protos(args.imported, args.generated)
    if any_mismatches:
        print("\nFail: Some imported proto files didn't match the generated ones.")
        sys.exit(1)
    else:
        print("\nSuccess: All the imported proto files matched the generated ones.")
