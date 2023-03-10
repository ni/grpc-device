from .functions import functions
from .functions_addon import functions_validation_suppressions
from .attributes import attributes
from .enums import enums
from .enums_addon import enums_validation_suppressions
from .config import config

metadata = {
    "functions" : functions,
    "functions_validation_suppressions": functions_validation_suppressions,
    "attributes" : attributes,
    "enums" : enums,
    "enums_validation_suppressions": enums_validation_suppressions,
    "config" : config
}
