import sys, importlib, importlib.util, os 
sys.path.append("..")
metadataPath = sys.argv[1] + "/__init__.py"
outputPath = sys.argv[2]

spec = importlib.util.spec_from_file_location("metadata", metadataPath)
metadata = importlib.util.module_from_spec(spec)
spec.loader.exec_module(metadata)


from mako.template import Template
from mako.lookup import TemplateLookup

def generate_service_file(template_file_name, generated_file_suffix):
  mytemplate = Template(filename=template_file_name)
  fileName = metadata.metadata["config"]["module_name"] + generated_file_suffix
  os.makedirs(outputPath, exist_ok=True)

  protoFilePath = outputPath + fileName

  f=open(protoFilePath, "w+")
  f.write(mytemplate.render(data=metadata.metadata))
  f.close()

generate_service_file("proto.mako", ".proto")
generate_service_file("service.h.mako", "_service.h")
generate_service_file("service.cpp.mako", "_service.cpp")
