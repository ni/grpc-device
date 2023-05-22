"""Script for validating the examples."""

import re
from argparse import ArgumentParser
from contextlib import contextmanager
from os import chdir, getcwd, system as _system_core
from pathlib import Path
from shutil import copytree, rmtree
from sys import exit
from typing import List, NamedTuple, Optional

from stage_client_files import stage_client_files


class _CommandRecord(NamedTuple):
    exit_code: int
    command: str


_FAILED_COMMANDS: List[_CommandRecord] = []


def _system(command):
    """Capture the result of any failed system calls in _FAILED_COMMANDS."""
    exit_code = _system_core(command)
    if exit_code:
        _FAILED_COMMANDS.append(_CommandRecord(exit_code, command))


@contextmanager
def _create_stage_dir(staging_dir):
    initial_dir = getcwd()
    try:
        rmtree(staging_dir, ignore_errors=True)
        staging_dir.mkdir(parents=True)
        chdir(staging_dir)
        yield
    finally:
        chdir(initial_dir)


def _stage_client_files(artifact_location: Optional[str], staging_dir: Path) -> None:
    if artifact_location:
        copytree(artifact_location, staging_dir, dirs_exist_ok=True)
    else:
        stage_client_files(staging_dir, True)


def _validate_examples(
    driver_glob_expression: str,
    exclude: str,
    ip_address: str,
    device_name: str,
    artifact_location: Optional[str],
) -> None:
    staging_dir = Path(__file__).parent.parent.parent / "build" / "validate_examples"
    staging_dir = staging_dir.resolve()

    print(f"Validating examples using staging_dir: {staging_dir}")

    with _create_stage_dir(staging_dir):
        _system("poetry new .")
        _system("poetry add grpcio")
        _system("poetry add --dev grpcio-tools mypy mypy-protobuf types-protobuf grpc-stubs")
        # black requires python >=3.6.2, so only ask it to be installed for python >=3.6.2, or else
        # poetry can give a SolverProblemError and fail the "install" step
        _system('poetry add --dev --python ">=3.6.2" black')
        _system("poetry install")

        _stage_client_files(artifact_location, staging_dir)
        examples_dir = staging_dir / "examples"
        proto_dir = staging_dir / "proto"

        proto_files_str = str.join(" ", [file.name for file in proto_dir.glob("*.proto")])

        _system(
            rf"poetry run python -m grpc_tools.protoc -I{proto_dir} --python_out=. --grpc_python_out=. --mypy_out=. --mypy_grpc_out=. {proto_files_str}"
        )
        for dir in examples_dir.glob(driver_glob_expression):
            if exclude and re.search(exclude, dir.as_posix()):
                print(f"-- Skipping: {dir.name}")
                continue
            print()
            print(f"-- Validating: {dir.name}")

            # Use '=' to allow a leading dash, e.g. "-aio\.py$".
            extend_exclude_option = f' --extend-exclude="{exclude}"' if exclude else ""
            exclude_option = f' --exclude="{exclude}"' if exclude else ""

            print(f" -> Running black line-length 100")
            _system(f"poetry run black --check --line-length 100 {dir}{extend_exclude_option}")

            print(f" -> Running mypy")
            _system(
                f"poetry run mypy {dir} --check-untyped-defs --ignore-missing-imports{exclude_option}"
            )

            if ip_address:
                for file in dir.glob("*.py"):
                    if exclude and re.search(exclude, file.as_posix()):
                        print(f" -> Skipping example: {file.name}")
                        continue
                    print(f" -> Running example: {file.name}")
                    port = 31763
                    _system(rf"poetry run python {file} {ip_address} {port} {device_name}")


if __name__ == "__main__":
    parser = ArgumentParser(description="Validate grpc-device examples.")
    parser.add_argument(
        "-p",
        "--pattern",
        help='Glob expression for scrapigen driver names to validate (e.g., "*rfmx*").',
        default="*",
    )

    parser.add_argument(
        "-e",
        "--exclude",
        help="Regular expression matching files and directories to exclude from validation "
        '(e.g. --exclude="-aio\.py$"). Use forward slash as a directory separator.',
        default="",
    )
    parser.add_argument(
        "-s",
        "--server",
        help="grpc-device server IP address. If not specified, skip running examples.",
    )

    parser.add_argument(
        "-d",
        "--device",
        help="Device alias to run examples. Default: no device passed to example (uses session-level simulation).",
        default="",
    )

    parser.add_argument(
        "-a",
        "--artifacts",
        help="Pre-existing client artifact directory. If set, these files will be used. Otherwise, artifacts will be staged from source.",
        default=None,
    )

    args = parser.parse_args()

    _validate_examples(args.pattern, args.exclude, args.server, args.device, args.artifacts)

    if any(_FAILED_COMMANDS):
        for code, command in _FAILED_COMMANDS:
            print(f"FAILED STEP ({code}): [{command}]")

        exit(1)
