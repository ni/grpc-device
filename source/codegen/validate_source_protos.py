"""Script for validating the source proto files against generated ones.

Expects input source path to source/codegen/protos and generated folder path.
"""

import argparse
import filecmp
import glob
import os
import sys


def _check_mismatched_protos(source: str, generated: str) -> bool:
    any_mismatches = False
    file_paths = glob.glob(f"{source}/**/*.proto", recursive=True)
    for file_path in file_paths:
        driver_dir_name = os.path.split(os.path.split(file_path)[0])[1]
        file_name = os.path.basename(file_path)
        driver_and_file_path = f"{driver_dir_name}/{file_name}"
        generated_file_path = f"{generated}/{driver_and_file_path}"
        compare_result = filecmp.cmp(file_path, generated_file_path)
        if not compare_result:
            any_mismatches = True
            print(
                f"❌ {f'source/codegen/proto/{driver_and_file_path}'} did not match {f'generated/{driver_and_file_path}.'}"
            )
        else:
            print(
                f"✔️ {f'source/codegen/proto/{driver_and_file_path}'} matched {f'generated/{driver_and_file_path}.'}"
            )
    return any_mismatches


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Check if any file has changed that affects the Linux RT Feed."
    )
    parser.add_argument(
        "-s",
        "--source",
        help="The path to the directory containing all of the source proto files.",
    )
    parser.add_argument(
        "-g",
        "--generated",
        help="The path to the directory containing all the generated files.",
    )
    args = parser.parse_args()
    any_mismatches = _check_mismatched_protos(args.source, args.generated)
    if any_mismatches:
        print("\nFail: Some source proto files didn't match the generated ones.")
        sys.exit(1)
    else:
        print("\nSuccess: All the source proto files matched the generated ones.")
