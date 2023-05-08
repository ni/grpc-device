from .functions import functions
from .functions_addon import functions_validation_suppressions, functions_override_metadata
from .attributes import attributes
from .enums import enums
from .enums_addon import enums_validation_suppressions
from .config import config

copy_functions = functions.copy()
def update_functions():
    for function_name, function_data in functions_override_metadata.items():
        copy_functions[function_name] = {**copy_functions[function_name], **functions_override_metadata[function_name]}
    return copy_functions

all_functions = update_functions() 

metadata = {
    "functions" : all_functions,
    "functions_validation_suppressions": functions_validation_suppressions,
    "attributes" : attributes,
    "enums" : enums,
    "enums_validation_suppressions": enums_validation_suppressions,
    "config" : config
}
