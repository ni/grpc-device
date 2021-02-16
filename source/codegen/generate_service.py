import sys
import os
import argparse
import importlib
import importlib.util
import mako.template
import pathlib

def generate_service_file(metadata, template_file_name, generated_file_suffix, gen_dir):
  current_dir = os.path.dirname(__file__)
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

def generate_all(metadata_dir, gen_dir, gen_mock):
  sys.path.append(metadata_dir)
  init_file = os.path.join(metadata_dir, "__init__.py")
  spec = importlib.util.spec_from_file_location("metadata", init_file)
  module = importlib.util.module_from_spec(spec)
  spec.loader.exec_module(module)

  metadata = module.metadata;
  generate_service_file(metadata, "proto.mako", ".proto", gen_dir)
  generate_service_file(metadata, "service.h.mako", "_service.h", gen_dir)
  generate_service_file(metadata, "service.cpp.mako", "_service.cpp", gen_dir)
  generate_service_file(metadata, "library_wrapper.h.mako", "_library_wrapper.h", gen_dir)
  if gen_mock:
      generate_service_file(metadata, 'mock_library_wrapper.h.mako', "_mock_library_wrapper.h", gen_dir)

if __name__ == "__main__":
  parser = argparse.ArgumentParser(description = "Generate files for specified NI driver API gRPC service.")
  parser.add_argument("metadata", help = "The path to the directory containing the metadata for the API being generated.")
  parser.add_argument("--output", "-o", help = "The path to the top-level directory to save the generated files. The API-specific sub-directories will be automatically created.")
  parser.add_argument("--generate-mock", "-m",  action = 'store_true', help = "Generate a mock of the LibraryWrapper for the API being generated.")
  args = parser.parse_args()
  generate_all(args.metadata, "." if args.output is None else args.output, args.generate_mock)
