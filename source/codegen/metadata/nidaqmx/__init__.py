from .functions import functions
from .functions_addon import functions_validation_suppressions, functions_override_metadata
from .attributes import attributes
from .enums import enums
from .enums_addon import enums_validation_suppressions, enums_override_metadata
from .config import config

metadata = {
    "functions" : functions,
    "functions_validation_suppressions": functions_validation_suppressions,
    "attributes" : attributes,
    "enums" : enums,
    "enums_validation_suppressions": enums_validation_suppressions,
    "config" : config
}
metadata['functions'].update(functions_override_metadata)
metadata['enums'].update(enums_override_metadata)

# Add new Read attribute manually
metadata['attributes']['Read'][12776] = {
    'access': 'read',
    'c_function_name': 'ReadDefaultNumberOfSamplesToRead',
    'calling_convention': 'StdCall',
    'ctypes_data_type': 'ctypes.c_uint',
    'handle_parameters': {
        'taskHandle': {
            'accessor': 'self._handle',
            'ctypes_data_type': 'lib_importer.task_handle',
            'cvi_name': 'taskHandle'
        }
    },
    'has_explicit_read_buffer_size': False,
    'has_explicit_write_buffer_size': False,
    'is_list': False,
    'is_python_object': False,
    'lv_filter': [
        'Read'
    ],
    'name': 'DEFAULT_NUMBER_OF_SAMPLES_TO_READ',
    'python_class_name': 'InStream',
    'python_data_type': 'int',
    'python_description': 'Indicates the default number of samples to read per channel.',
    'resettable': False,
    'type': 'uInt32'
}
