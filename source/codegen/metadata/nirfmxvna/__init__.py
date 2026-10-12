from .functions import functions
from .attributes import attributes
from .enums import enums
from .enums_addon import enums_override_metadata
from .attributes_addon import attributes_override_metadata
from .config import config

metadata = {
    "functions": functions,
    "attributes": attributes,
    "enums": enums,
    "enums_override_metadata": enums_override_metadata,
    "attributes_override_metadata": attributes_override_metadata,
    "config": config
}

metadata['enums'].update(enums_override_metadata)
metadata['attributes'].update(attributes_override_metadata)