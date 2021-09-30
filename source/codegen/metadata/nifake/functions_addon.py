# These dictionaries are merged with the extracted function metadata at build time.
# Changes to the metadata should be made here, because functions.py is generated thus any changes get overwritten.

functions_override_metadata = {
}

functions_validation_suppressions = {
    "AcceptViSessionArray": {
        "parameters": {
            "sessionArray": ["INPUT_ARRAY_SHOULD_NOT_HAVE_PASSED_IN_SIZE"]
        }
    },
    "BoolArrayInputFunction": {
        "parameters": {
            "anArray": ["INPUT_ARRAY_SHOULD_NOT_HAVE_PASSED_IN_SIZE"]
        }
    },
    "ViUInt8ArrayInputFunction": {
        "parameters": {
            "anArray": ["INPUT_ARRAY_SHOULD_NOT_HAVE_PASSED_IN_SIZE"]
        }
    },
}
