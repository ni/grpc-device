from .functions import functions
from .functions_addon import functions_validation_suppressions
from .attributes import attributes
from .attributes_addon import additional_attributes_used_in_proto
from .enums import enums
from .enums_addon import enums_validation_suppressions
from .config import config

metadata = {
    "functions" : functions,
    "functions_validation_suppressions": functions_validation_suppressions,
    "attributes" : attributes,
    "additional_attributes": additional_attributes_used_in_proto,
    "enums" : enums,
    "enums_validation_suppressions": enums_validation_suppressions,
    "config" : config
}
