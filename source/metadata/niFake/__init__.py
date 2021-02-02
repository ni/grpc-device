import sys
sys.path.append("niFake")
from metadata.niFake.functions import functions
from metadata.niFake.attributes import attributes
from metadata.niFake.enums import enums
from metadata.niFake.config import config

metadata = {
    "functions" : functions, 
    "attributes" : attributes, 
    "enums" : enums,
    "config" : config
}