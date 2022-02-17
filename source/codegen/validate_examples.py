from argparse import ArgumentParser
from contextlib import contextmanager
from sys import exit
from os import getcwd, chdir, system as _system_core
from pathlib import Path
from shutil import rmtree
from typing import NamedTuple

from stage_client_files import stage_client_files


class _CommandRecord(NamedTuple):
    exit_code: int
    command: str


_FAILED_COMMANDS: list[_CommandRecord] = []


def _system(command):
    """
    Capture the result of any failed system calls in _FAILED_COMMANDS.
    """
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


def validate_examples(driver_glob_expression: str, ip_address: str, device_name: str) -> None:
    staging_dir = Path(__file__).parent.parent.parent / "build" / "validate_examples"

    print(f"Validating examples using staging_dir: {staging_dir}")

    with _create_stage_dir(staging_dir):
        _system("poetry new .")
        _system("poetry add grpcio")
        _system("poetry add --dev grpcio-tools black mypy mypy-protobuf types-protobuf grpc-stubs")
        _system("poetry install")

        stage_client_files(staging_dir, True)
        examples_dir = staging_dir / "examples"
        proto_dir = staging_dir / "proto"
        proto_files_str = str.join(" ", [file.name for file in proto_dir.glob("*.proto")])

        _system(
            rf"poetry run python -m grpc_tools.protoc -I{proto_dir} --python_out=. --grpc_python_out=. --mypy_out=. --mypy_grpc_out=. {proto_files_str}"
        )
        for dir in examples_dir.glob(driver_glob_expression):
            print()
            print(f"-- Validating: {dir.name}")

            print(f" -> Running black line-length 100")
            _system(f"poetry run black --check --line-length 100 {dir}")

            print(f" -> Running mypy")
            _system(f"poetry run mypy {dir} --check-untyped-defs")

            if ip_address:
                for file in dir.glob("*.py"):
                    print(f" -> Running example: {file.name}")
                    PORT = 31763
                    _system(rf"poetry run python {file} {ip_address} {PORT} {device_name}")


if __name__ == "__main__":
    parser = ArgumentParser(description="Validate grpc-device examples.")
    parser.add_argument(
        "-p",
        "--pattern",
        help="Glob expression for scrapigen driver names to validate (i.e., *rfmx*).",
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

    args = parser.parse_args()

    validate_examples(args.pattern, args.server, args.device)

    if any(_FAILED_COMMANDS):
        for code, command in _FAILED_COMMANDS:
            print(f"FAILED STEP ({code}): [{command}]")

        exit(_FAILED_COMMANDS[-1].exit_code)
