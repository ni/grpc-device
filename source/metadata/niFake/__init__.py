import sys
sys.path.append("niFake")
from metadata.nifake.functions import functions
from metadata.nifake.attributes import attributes
from metadata.nifake.enums import enums
from metadata.nifake.config import config

metadata = {
    "functions" : functions, 
    "attributes" : attributes, 
    "enums" : enums,
    "config" : config
}