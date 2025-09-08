from .functions import functions
from .functions_addon import functions_override_metadata
from .attributes import attributes
from .attributes_addon import attributes_override_metadata
from .enums import enums
from .enums_addon import enums_override_metadata
from .config import config

metadata = {
    "functions" : functions,
    "attributes" : attributes,
    "enums" : enums,
    "config" : config
}

metadata['functions'].update(functions_override_metadata)
metadata['attributes'].update(attributes_override_metadata)
metadata['enums'].update(enums_override_metadata)