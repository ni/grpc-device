from argparse import ArgumentParser
from contextlib import contextmanager
from os import system, getcwd, chdir
from pathlib import Path
from shutil import rmtree

from stage_client_files import stage_client_files

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

def validate_examples(driver_glob_expression: str, ip_address: str) -> None:
  staging_dir = Path(__file__).parent.parent.parent / "build" / "validate_examples"

  print(f"Validating examples using staging_dir: {staging_dir}")

  with _create_stage_dir(staging_dir):
    system("poetry new .")
    system("poetry add grpcio")
    system("poetry add --dev grpcio-tools black mypy mypy-protobuf types-protobuf grpc-stubs")
    system("poetry install")

    stage_client_files(staging_dir, True)
    examples_dir = staging_dir / "examples"
    proto_dir = staging_dir / "proto"
    proto_files_str = str.join(" ", [file.name for file in proto_dir.glob("*.proto")])

    system(
      rf"poetry run python -m grpc_tools.protoc -I{proto_dir} --python_out=. --grpc_python_out=. --mypy_out=. --mypy_grpc_out=. {proto_files_str}"
    )
    for dir in examples_dir.glob(driver_glob_expression):
      print()
      print(f"-- Validating: {dir.name} --")
      
      print(f" -> Running black line-length 100")
      system(f"poetry run black --check --line-length 100 {dir}")
      
      print(f" -> Running mypy")
      system(f"poetry run mypy {dir}")

      for file in dir.glob("*.py"):
        print(f" -> Running example: {file.name}")
        system(rf"poetry run python {file} {ip_address}")


if __name__ == "__main__":
  parser = ArgumentParser(description="Validate grpc-device examples.")
  parser.add_argument(
      "-p", 
      "--pattern", 
      help="Glob expression for scrapigen driver names to validate (i.e., *rfmx*).")

  parser.add_argument(
      "-s",
      "--server", 
      help="grpc-device server IP address.")

  args = parser.parse_args()

  validate_examples(args.pattern, args.server)
