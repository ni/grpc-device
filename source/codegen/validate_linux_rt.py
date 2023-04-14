"""Script for validating if a set of changed files warrants updating the Linux RT Feed.

Expects output of git diff --name-only <last-release-commit> <current-commit> 
to be piped in so it can be read from sys.stdin
"""

import argparse
import fnmatch
import os
import sys
from pprint import pprint
from typing import Set

from template_helpers import load_metadata


def _get_codegen_changes(changed_files: Set[str]) -> Set[str]:
    return set(fnmatch.filter(changed_files, "source/codegen/*"))


def _get_test_changes(changed_files: Set[str]) -> Set[str]:
    return set(fnmatch.filter(changed_files, "source/tests/*"))


def _get_import_changes(changed_files: Set[str]) -> Set[str]:
    return set(fnmatch.filter(changed_files, "imports/*"))


def _get_markdown_changes(changed_files: Set[str]) -> Set[str]:
    return set(fnmatch.filter(changed_files, "*.md"))


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
    _print_changed_files("Codegen changes not affecting RT:", codegen_changes)
    remaining_changes = changed_files - codegen_changes
    test_changes = _get_test_changes(remaining_changes)
    _print_changed_files("Test related changes not affecting RT:", test_changes)
    remaining_changes -= test_changes
    import_changes = _get_import_changes(remaining_changes)
    _print_changed_files("Import related changes not affecting RT:", import_changes)
    remaining_changes -= import_changes
    markdown_changes = _get_markdown_changes(remaining_changes)
    _print_changed_files("Markdown changes not affecting RT:", markdown_changes)
    remaining_changes -= markdown_changes

    non_rt_drivers = [
        driver
        for driver in os.listdir(metadata_dir)
        if os.path.isdir(os.path.join(metadata_dir, driver))
        and not load_metadata(f"{metadata_dir}/{driver}/")["config"].get("linux_rt_support", False)
    ]
    non_rt_driver_changes = set()
    for non_rt_driver in non_rt_drivers:
        non_rt_driver_changes |= _get_non_rt_driver_changes(non_rt_driver, remaining_changes)
    _print_changed_files("Changes related to drivers not supported on RT:", non_rt_driver_changes)
    remaining_changes = remaining_changes - non_rt_driver_changes
    if non_rt_driver_changes and remaining_changes == {"source/CMakeLists.txt"}:
        return False
    if len(remaining_changes) > 0:
        _print_changed_files("Remaining changes likely affecting RT:", remaining_changes)
        return True
    return False


def _print_changed_files(title: str, changed_files: Set[str]):
    print(f"\n{title}\n")
    pprint(changed_files)


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
    env_file = os.getenv("GITHUB_ENV")
    update_linux_rt = False
    if _need_linux_rt_feed_update(args.metadata, changed_files):
        print("\nLinux RT's grpc-device dependency needs updating.")
        update_linux_rt = True
    else:
        print("\nLinux RT's grpc-device dependency doesn't need updating.")
    if env_file:
        with open(env_file, "a") as myfile:
            myfile.write(f"SHOULD_UPDATE_LINUX_RT={update_linux_rt}")
