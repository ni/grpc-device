import sys
import os
import argparse
import importlib
import importlib.util
import mako.template
import pathlib
import metadata_mutation
import common_helpers
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


class AttributeValueExpander:
  '''Wraps an _attribute_type_map of:
  
  group -> type -> attributes

  and implements the metadata_mutations to add_attribute_values_enums and expand_attribute_function_value_param.
  '''
  def __init__(self, metadata):
    self._metadata = metadata
    self._attribute_type_map = {}

    for group_name, attributes in common_helpers.get_attribute_groups(metadata).items():
      attribute_enums_by_type = common_helpers.get_attribute_enums_by_type(attributes)
      metadata_mutation.add_attribute_values_enums(metadata["enums"], attribute_enums_by_type, group_name)
      self._attribute_type_map[group_name] = attribute_enums_by_type

  def get_used_attribute(self, parameters):
    param_types = (param["grpc_type"] for param in parameters)
    param_types = (common_helpers.strip_suffix(p, "Attributes") for p in param_types)
    attribute_params = (p for p in param_types if p in self._attribute_type_map)
    return next(attribute_params, None)

  def expand_attribute_value_params(self, func):
    parameters = func["parameters"]
    used_attribute = self.get_used_attribute(parameters)
    if used_attribute:
      metadata_mutation.expand_attribute_function_value_param(
        func,
        self._metadata["enums"], 
        self._attribute_type_map[used_attribute], 
        used_attribute)


def mutate_metadata(metadata):
  config = metadata["config"]
  
  attribute_expander = AttributeValueExpander(metadata)
  for function_name in metadata["functions"]:
    function = metadata["functions"][function_name]
    parameters = function["parameters"]
    metadata_mutation.sanitize_names(parameters)
    metadata_mutation.set_var_args_types(parameters, config)
    metadata_mutation.mark_size_params(parameters)
    metadata_mutation.mark_non_proto_params(parameters)
    metadata_mutation.mark_mapped_enum_params(parameters, metadata["enums"])
    metadata_mutation.populate_grpc_types(parameters, config)
    attribute_expander.expand_attribute_value_params(function)


def generate_all(metadata_dir, gen_dir):
  sys.path.append(metadata_dir)
  init_file = os.path.join(metadata_dir, "__init__.py")
  spec = importlib.util.spec_from_file_location("metadata", init_file)
  module = importlib.util.module_from_spec(spec)
  spec.loader.exec_module(module)

  metadata = module.metadata
  lookup = TemplateLookup(directories = metadata_dir)
  metadata["lookup"] = lookup
  mutate_metadata(metadata)
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
