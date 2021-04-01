import sys
import os
import argparse
import importlib
import importlib.util
import mako.template
import pathlib
import metadata_mutation
from mako.lookup import TemplateLookup

def generate_service_file(metadata, template_file_name, generated_file_suffix, gen_dir):
  current_dir = os.path.dirname(__file__)
  template_file_path = os.path.join(current_dir, "templates", template_file_name)
  template_directory = os.path.dirname(template_file_path)
  module_name = metadata["config"]["module_name"]
  output_dir = os.path.join(gen_dir, module_name)
  file_name = module_name + generated_file_suffix
  output_file_path = os.path.join(output_dir, file_name)

  os.makedirs(output_dir, exist_ok=True)
  template_lookup = TemplateLookup(directories = template_directory + "/")
  template = mako.template.Template(filename=template_file_path, lookup=template_lookup)
  f=open(output_file_path, "w+", newline="")
  f.write(template.render(data=metadata))
  f.close()

def fix_up_metadata(metadata):
  for function in metadata["functions"]:
    parameters = metadata["functions"][function]["parameters"]
    metadata_mutation.sanitize_names(parameters)
    metadata_mutation.mark_size_params(parameters)
    metadata_mutation.mark_non_grpc_params(parameters)

def generate_all(metadata_dir, gen_dir):
  sys.path.append(metadata_dir)
  init_file = os.path.join(metadata_dir, "__init__.py")
  spec = importlib.util.spec_from_file_location("metadata", init_file)
  module = importlib.util.module_from_spec(spec)
  spec.loader.exec_module(module)

  metadata = module.metadata
  lookup = TemplateLookup(directories = metadata_dir)
  metadata["lookup"] = lookup
  fix_up_metadata(metadata)
  generate_service_file(metadata, "proto.mako", ".proto", gen_dir)
  generate_service_file(metadata, "service.h.mako", "_service.h", gen_dir)
  generate_service_file(metadata, "service.cpp.mako", "_service.cpp", gen_dir)
  generate_service_file(metadata, "library_interface.h.mako", "_library_interface.h", gen_dir)
  generate_service_file(metadata, "library.cpp.mako", "_library.cpp", gen_dir)
  generate_service_file(metadata, "library.h.mako", "_library.h", gen_dir)
  generate_service_file(metadata, "mock_library.h.mako", "_mock_library.h", gen_dir)

if __name__ == "__main__":
  parser = argparse.ArgumentParser(description = "Generate files for specified NI driver API gRPC service.")
  parser.add_argument("metadata", help = "The path to the directory containing the metadata for the API being generated.")
  parser.add_argument("--output", "-o", help = "The path to the top-level directory to save the generated files. The API-specific sub-directories will be automatically created.")
  args = parser.parse_args()
  generate_all(args.metadata, "." if args.output is None else args.output)
