"""Script validating that any imported proto file matches its corresponding generated one.

Expects import path as source/codegen/metadata and generated folder path.

Background: 
All MI driver metadata is being imported from hapigen. We're also creating .proto files
based on the metadata in that component. So when an MI driver is updated, the export will have
a metadata folder with [attributes.py, config.py, enums.py, functions.py, <driver-name>.proto]. Someone
will import those five files to grpc-device's source/codegen/metadata folder.

Purpose: 
Since, at the moment, we have both grpc-device and hapigen generating the driver .proto files we want a way to validate
that they're creating equivalent ones. This script will check imported .proto files (copied out of hapigen-based driver exports)
against their corresponding .proto file that gets generated in grpc-device to make sure they match.

On Mismatch:
1. Make sure .proto from driver export is copied over to grpc-device
2. Make sure you built grpc-device locally to get any generated folder changes (specifically .proto files there)
3. The proto generators (mako and helper python files) likely changed between grpc-device and hapigen and need to be synced up.
"""

import click
import filecmp
import glob
import os
import sys

@click.command()
@click.option('--imported', '-i', help="Directory where imported .proto files reside")
@click.option('--generated', '-g', help='Directory where generated .proto files reside')
def _check_mismatched_protos(imported: str, generated: str):
    any_mismatches = False
    file_paths = glob.glob(f"{imported}/**/*.proto", recursive=True)
    for file_path in file_paths:
        driver_dir_name = os.path.split(os.path.split(file_path)[0])[1]
        file_name = os.path.basename(file_path)
        driver_and_file_path = f"{driver_dir_name}/{file_name}"
        generated_file_path = f"{generated}/{driver_and_file_path}"
        compare_result = filecmp.cmp(file_path, generated_file_path)
        if compare_result:
            print(
                f"✔️ {f'{imported}/{driver_and_file_path}'} matched {f'{generated}/{driver_and_file_path}.'}"
            )
        else:
            any_mismatches = True
            print(
                f"❌ {f'{imported}/{driver_and_file_path}'} did not match {f'{generated}/{driver_and_file_path}'}."
            )
    if any_mismatches:
        print("\nFail: Some imported proto files didn't match the generated ones.")
        sys.exit(1)
    else:
        print("\nSuccess: All the imported proto files matched the generated ones.")


if __name__ == "__main__":
    _check_mismatched_protos()
