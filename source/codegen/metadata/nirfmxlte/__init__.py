from .functions import functions
from .functions_addon import functions_override_metadata
from .attributes import attributes
from .enums import enums
from .config import config

metadata = {
    "functions": functions,
    "attributes": attributes,
    "enums": enums,
    "config": config
}

metadata['functions'].update(functions_override_metadata)
