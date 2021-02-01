"""
from metadata.nifake.config import config
from metadata.nifake.functions import functions
from metadata.nifake.attributes import attributes
from metadata.nifake.enums import enums
import metadata.nifake.functions_addon
import metadata.nifake.attributes_addon
import metadata.nifake.enums_addon
import metadata.nifake.config_addon

import build.helper as helper
import sys

# Update generated functions data with hand maintained data
config['modules'] = sys.modules
helpeadd_all_metadata(functions, attributes, enums, config)

__version__ = config['module_version']

"""
