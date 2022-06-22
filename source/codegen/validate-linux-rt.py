"""Script for validating if a set of changed files warrants updating the Linux RT Feed.

Expects output of git diff --name-only <last-release-commit> <current-commit> 
to be piped in so it can be read from sys.stdin
"""

import argparse
import fnmatch
import os
import sys
from typing import Set

from template_helpers import load_metadata


def _get_codegen_changes(changed_files: Set[str]) -> Set[str]:
    return set(fnmatch.filter(changed_files, "source/codegen/*"))


def _get_test_changes(changed_files: Set[str]) -> Set[str]:
    return set(fnmatch.filter(changed_files, "source/tests/*"))


def _get_non_rt_driver_changes(driver_name: str, changed_files: Set[str]) -> Set[str]:
    files_affecting_linux_rt = [
        f"generated/{driver_name}/*",
        f"examples/{driver_name}/*",
        f"source/custom/{driver_name}*",
    ]
    non_rt_driver_changes = set()

    for pattern in files_affecting_linux_rt:
        non_rt_driver_changes |= set(fnmatch.filter(changed_files, pattern))
    return non_rt_driver_changes


def _need_linux_rt_feed_update(metadata_dir: str, changed_files: Set[str]) -> bool:
    codegen_changes = _get_codegen_changes(changed_files)
    remaining_changes = changed_files - codegen_changes
    test_changes = _get_test_changes(changed_files)
    remaining_changes -= test_changes
    non_rt_drivers = [
        driver
        for driver in os.listdir(metadata_dir)
        if not load_metadata(f"{metadata_dir}/{driver}/")["config"]["linux_rt_support"]
    ]
    non_rt_driver_changes = set()
    for non_rt_driver in non_rt_drivers:
        non_rt_driver_changes |= _get_non_rt_driver_changes(non_rt_driver, remaining_changes)
    remaining_changes = remaining_changes - non_rt_driver_changes
    if non_rt_driver_changes:
        if len(remaining_changes) == 1 and next(iter(remaining_changes)) == "source/CMakeLists.txt":
            return False
    return len(remaining_changes) > 0


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Check if any file has changed that affects the Linux RT Feed."
    )
    parser.add_argument(
        "metadata",
        help="The path to the directory containing all of the metadata.",
    )
    args = parser.parse_args()
    changed_files = set()
    for line in sys.stdin:
        changed_files.add(line.strip())
    if _need_linux_rt_feed_update(args.metadata, changed_files):
        print("\nLinux RT Feed likely needs updating.")
    else:
        print("\nLinux RT Feed should not need updating.")
