# These dictionaries are merged with the extracted function metadata at build time.
# Changes to the metadata should be made here, because functions.py is generated thus any changes get overwritten.

functions_override_metadata = {
}

functions_validation_suppressions = {
    "InputArraysWithNarrowIntegerTypes": {
        "parameters": {
            "u16Array": ["ARRAY_PARAMETER_NEEDS_SIZE"],
            "i16Array": ["ARRAY_PARAMETER_NEEDS_SIZE"],
            "i8Array": ["ARRAY_PARAMETER_NEEDS_SIZE"],
        }
    },
    "InputArrayOfBytes": {
        "parameters": {
            "u8Array": ["ARRAY_PARAMETER_NEEDS_SIZE"],
        }
    },
}