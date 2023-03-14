# These dictionaries are applied to the generated enums dictionary at build time
# Any changes to the API should be made here. enums.py is code generated

enums_override_metadata = {}

enums_validation_suppressions = {
    "DAQmxErrors": ["ENUMS_SHOULD_BE_USED"],  # Used by nidaqmx-python
    "DAQmxWarnings": ["ENUMS_SHOULD_BE_USED"],  # Used by nidaqmx-python
}
