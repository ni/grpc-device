import sys, importlib, importlib.util, os, argparse

parser = argparse.ArgumentParser(description = "Generate files for NI Driver API gRPC support.")
parser.add_argument("metadataPath", type=str, help="Path to metadata files for the driver.")
parser.add_argument("outputPath", type=str, help="Path where generated files should be created.")
parser.add_argument("--fakes", "-f", action='store_true', help="Enables generation of fakes for the driver shared library.")
args = parser.parse_args()

sys.path.append("..")

spec = importlib.util.spec_from_file_location("metadata", args.metadataPath + "/__init__.py")
metadata = importlib.util.module_from_spec(spec)
spec.loader.exec_module(metadata)


from mako.template import Template
from mako.lookup import TemplateLookup

def generate_service_file(template_file_name, generated_file_suffix):
  mytemplate = Template(filename=template_file_name)
  fileName = metadata.metadata["config"]["module_name"] + generated_file_suffix
  os.makedirs(args.outputPath, exist_ok=True)

  protoFilePath = args.outputPath + fileName

  f=open(protoFilePath, "w+")
  f.write(mytemplate.render(data=metadata.metadata))
  f.close()

generate_service_file("proto.mako", ".proto")
generate_service_file("service.h.mako", "_service.h")
generate_service_file("service.cpp.mako", "_service.cpp")
if args.fakes :
    generate_service_file("fake_library.h.mako", "_fake_library.h")
    generate_service_file("fake_library.cpp.mako", "_fake_library.cpp")
