"""Script for validating if a set of changed files warrants updating the Linux RT Feed.

Expects output of git diff --name-only <last-release-commit> <current-commit> 
to be piped in so it can be read from sys.stdin
"""

import argparse
import fnmatch
import os
import sys
from typing import List

from template_helpers import load_metadata


def _check_core_files_affecting_rt(changed_files: List[str]) -> bool:
    files_affecting_linux_rt = [
        "source/config/*",
        "source/custom/ivi_errors.h",
        "source/protobuf/*",
        "source/server/*",
    ]

    for pattern in files_affecting_linux_rt:
        if fnmatch.filter(changed_files, pattern):
            return True
    return False


def _check_driver_files_affecting_rt(driver_name: str, changed_files: List[str]) -> bool:
    files_affecting_linux_rt = [
        f"generated/{driver_name}/*",
        f"examples/{driver_name}/*",
        f"source/custom/{driver_name}*",
    ]

    for pattern in files_affecting_linux_rt:
        if fnmatch.filter(changed_files, pattern):
            return True
    return False


def _check_all(metadata_dir: str, changed_files: List[str]) -> bool:
    if _check_core_files_affecting_rt(changed_files):
        return True
    rt_supported_drivers = [
        driver
        for driver in os.listdir(metadata_dir)
        if load_metadata(f"{metadata_dir}/{driver}/")["config"]["linux_rt_support"]
    ]
    for driver in rt_supported_drivers:
        if _check_driver_files_affecting_rt(driver, changed_files):
            return True
    return False


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Check if any file has changed that affects the Linux RT Feed."
    )
    parser.add_argument(
        "metadata",
        help="The path to the directory containing all of the metadata.",
    )
    args = parser.parse_args()
    changed_files = list()
    for line in sys.stdin:
        changed_files.append(line.strip())
    if _check_all(args.metadata, changed_files):
        print("Linux RT Feed needs updating.")
    else:
        print("Linux RT Feed does not need updating.")
