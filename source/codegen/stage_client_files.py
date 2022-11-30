"""Stage client files."""

from argparse import ArgumentParser
from pathlib import Path
from shutil import copy2, copytree
from tempfile import TemporaryDirectory
from typing import Dict, Iterable, List

from common_helpers import get_driver_readiness
from template_helpers import load_metadata


class _ArtifactReadiness:
    """Class to determine whether a Path with a module-named artifact directory is release-ready."""

    _module_to_readiness = {}  # type: Dict[str, str]

    def __init__(self, metadata_dir: Path, ignore_release_readiness: bool):
        modules = [
            load_metadata(p) for p in metadata_dir.iterdir() if p.is_dir() and "fake" not in p.name
        ]

        self._module_to_readiness = {
            d["config"]["module_name"]: get_driver_readiness(d["config"]) for d in modules
        }

        self.ignore_release_readiness = ignore_release_readiness

    def is_release_ready(self, module_path: Path) -> bool:
        """Determine release-readiness.

        Do so by checking the name of the module_path directory against code_readiness for the
        module_name in config.py.
        """
        module_name = module_path.name
        if "fake" in module_name:
            return False

        if "session" == module_name:
            return True

        if module_name not in self._module_to_readiness:
            raise KeyError(f"No module config.py metadata for module_name: {module_path}")

        return self._module_to_readiness[module_name] == "Release"

    def get_release_ready_subdirs(self, directory: Path) -> Iterable[Path]:
        """Return all subdirectories of directory for which is_release_ready is True."""
        return (
            d
            for d in directory.iterdir()
            if d.is_dir() and (self.is_release_ready(d) or self.ignore_release_readiness)
        )


class _ArtifactLocations:
    repo_root: Path

    def __init__(self, repo_root: Path):
        self.repo_root = repo_root

    @property
    def examples(self) -> Path:
        return self.repo_root / "examples"

    @property
    def generated_files(self) -> Path:
        return self.repo_root / "generated"

    @property
    def shared_protos(self) -> Path:
        return self.repo_root / "source" / "protobuf"

    @property
    def restricted_protos(self) -> Path:
        return self.repo_root / "source" / "protobuf_restricted"

    @property
    def metadata_dir(self) -> Path:
        return self.repo_root / "source" / "codegen" / "metadata"


def _get_release_proto_files(
    artifact_locations: _ArtifactLocations, readiness: _ArtifactReadiness
) -> List[Path]:

    release_driver_dirs = readiness.get_release_ready_subdirs(artifact_locations.generated_files)
    return [proto for d in release_driver_dirs for proto in d.glob("*.proto")]


def _get_release_example_directories(
    artifact_locations: _ArtifactLocations, readiness: _ArtifactReadiness
) -> Iterable[Path]:
    return readiness.get_release_ready_subdirs(artifact_locations.examples)


def stage_client_files(output_path: Path, ignore_release_readiness: bool):
    """Stage the client files into the given output path."""
    repo_root = Path(__file__).parent.parent.parent
    artifact_locations = _ArtifactLocations(repo_root)
    readiness = _ArtifactReadiness(artifact_locations.metadata_dir, ignore_release_readiness)

    proto_path = output_path / "proto"
    proto_path.mkdir(parents=True)

    for file in artifact_locations.shared_protos.iterdir():
        copy2(file, proto_path)

    for file in _get_release_proto_files(artifact_locations, readiness):
        copy2(file, proto_path)

    if readiness.ignore_release_readiness:
        for file in artifact_locations.restricted_protos.iterdir():
            copy2(file, proto_path)

    examples_path = output_path / "examples"
    examples_path.mkdir(parents=True)

    for dir in _get_release_example_directories(artifact_locations, readiness):
        copytree(dir, examples_path / dir.name)

    copy2(artifact_locations.repo_root / "LICENSE", output_path)
    copy2(artifact_locations.repo_root / "ThirdPartyNotices.txt", output_path)


if __name__ == "__main__":
    parser = ArgumentParser(description="Stage client files for NI driver API gRPC services.")
    parser.add_argument(
        "--output",
        "-o",
        help="The path to the top-level directory to stage the client files. Must be empty or non-existent.",
    )

    parser.add_argument(
        "--ignore-release-readiness", action="store_true", help="Force-include all artifacts."
    )

    args = parser.parse_args()

    if args.output:
        stage_client_files(Path(args.output), args.ignore_release_readiness)
    else:
        print(
            """
***No --output directory specified.***
Performing Dry Run.
        """
        )
        with TemporaryDirectory() as tempdir:
            tempdirpath = Path(tempdir)
            stage_client_files(tempdirpath, args.ignore_release_readiness)
            created_files = (f for f in tempdirpath.glob("**/*") if not f.is_dir())
            for out_file in created_files:
                print(out_file.relative_to(tempdirpath))
