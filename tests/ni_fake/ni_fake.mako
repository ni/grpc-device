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
   
   
mytemplate = Template(filename='template_niFake_metadata.mako')
metadata = getMetaData()


FileName = "ni_fake.proto"
f=open(FileName, "w+")
f.write(mytemplate.render(data=metadata));
f.close()

