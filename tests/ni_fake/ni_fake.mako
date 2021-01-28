import ast
from metadata.functions import functions
from metadata.attributes import attributes
from metadata.enums import enums
from metadata.config import config
from mako.template import Template


def getMetaData():
   metadata = {
      "functions" : functions, 
      "attributes" : attributes, 
      "enums" : enums,
      "config" : config
   }
   return metadata
   
   
mytemplate = Template(filename='C:/Users/adarrow/Documents/GitHub/ni-driver-apis-grpc/tests/ni_fake/template_niFake_metadata.mako')
metadata = getMetaData()


FileName = "HelloProto.proto"
f=open(FileName, "w+")
f.write(mytemplate.render_unicode(data=metadata));
f.close()

