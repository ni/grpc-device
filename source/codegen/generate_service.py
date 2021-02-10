"""
Usage: python generate_service.py <metadata_dir> <generated_dir>

  metadata_dir:  The absolute or relative path to the directory containing the metadata
                 for the API being generated.

  generated_dir: The absolute or relative path to the top-level directory to save the
                 generated files. The API-specific sub-directories will be automatically
                 created.

Example:
  From the root directory:
    python generate_service.py ./source/apis/metadata/nifake ./generated
  Generates the following files:
    ./generated/nifake/nifake.proto
    ./generated/nifake/nifake_service.cpp
    ./generated/nifake/nifake_service.h
"""

import sys
import os
import importlib
import importlib.util
import mako.template

def generate_service_file(metadata, template_file_name, generated_file_suffix, gen_dir):
  current_dir = dirname = os.path.dirname(__file__)
  template_file_path = os.path.join(current_dir, template_file_name)
  module_name = metadata["config"]["module_name"]
  output_dir = os.path.join(gen_dir, module_name)
  file_name = module_name + generated_file_suffix
  output_file_path = os.path.join(output_dir, file_name)

  os.makedirs(output_dir, exist_ok=True)
  template = mako.template.Template(filename=template_file_path)
  f=open(output_file_path, "w+", newline="")
  f.write(template.render(data=metadata))
  f.close()

def generate_all(metadata_dir, gen_dir):
  sys.path.append(metadata_dir)
  init_file = os.path.join(metadata_dir, "__init__.py")
  spec = importlib.util.spec_from_file_location("metadata", init_file)
  module = importlib.util.module_from_spec(spec)
  spec.loader.exec_module(module)

  metadata = module.metadata;
  generate_service_file(metadata, "proto.mako", ".proto", gen_dir)
  generate_service_file(metadata, "service.h.mako", "_service.h", gen_dir)
  generate_service_file(metadata, "service.cpp.mako", "_service.cpp", gen_dir)

if __name__ == "__main__":
  metadata_dir = os.path.abspath(sys.argv[1])
  gen_dir = os.path.abspath(sys.argv[2])
  generate_all(metadata_dir, gen_dir)