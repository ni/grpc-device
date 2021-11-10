from argparse import ArgumentParser
from pathlib import Path
import subprocess
import sys
import venv


def _ensure_pip(python: Path):
    # Workaround for https://bugs.python.org/issue43749, which hopefully is fixed in cpython 3.11.
    # The default venv.create will use the exe name, which is python3.exe in some environments
    # (i.e., GH runners, see https://github.com/actions/virtual-environments/issues/2690).
    # The new venv just has python.exe, so this won't work.
    cmd = [
        str(python), 
        "-Im", 
        "ensurepip", 
        "--upgrade",
        "--default-pip"
    ]
    subprocess.check_output(cmd, stderr=subprocess.STDOUT)


def bootstrap_venv(venv_dir: Path, requirements: Path):
    venv.create(venv_dir, with_pip=False)

    if sys.platform == "win32":
        python_path = venv_dir / "Scripts" / "python.exe"
    else:
        python_path = venv_dir / "bin" / "python"

    _ensure_pip(python_path)

    cmd = [str(python_path), "-m", "pip", "install", "-r", str(requirements)]
    subprocess.check_output(cmd, stderr=subprocess.STDOUT)


def main():
    parser = ArgumentParser(description="Bootstrap a venv at the given path and requirements.")
    parser.add_argument(
        "venv",
        help="The path to the venv to bootstrap.",
    )

    parser.add_argument(
        "requirements",
        help="The requirements file.",
    )

    args = parser.parse_args()

    return bootstrap_venv(Path(args.venv), Path(args.requirements))


if __name__ == "__main__":
    main()
