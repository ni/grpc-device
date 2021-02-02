import sys
sys.path.append("..")
from metadata.niFake import metadata
from mako.template import Template
from mako.lookup import TemplateLookup

   
mytemplate = Template(filename="template_niFake_metadata.mako")

FileName = "ni_fake.proto"
f=open(FileName, "w+")
f.write(mytemplate.render(data=metadata));
f.close()

