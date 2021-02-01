import ast
import os
from metadata.nifake.functions import functions
from metadata.nifake.attributes import attributes
from metadata.nifake.enums import enums
from metadata.nifake.config import config
from mako.template import Template


def getMetaData():
   metadata = {
      "functions" : functions, 
      "attributes" : attributes, 
      "enums" : enums,
      "config" : config
   }
   return metadata
   

mytemplate = Template(filename='service.h.mako')
metadata = getMetaData()
if not os.path.exists('../../generated'):
    os.makedirs('../../generated')
FileName = "../../generated/service.h"
f=open(FileName, "w+")
f.write(mytemplate.render_unicode(data=metadata))
f.close()
