# Changes in metadata from the nimi-python metadata

## config.py

The following metadata was added : 
- 'service_class_prefix': 'NiDigital'
- 'java_package': 'com.ni.grpc.nidigital'
- 'csharp_namespace': 'NationalInstruments.Grpc.Digital'
- 'namespace_component': 'nidigitalpattern'
- 'module_name' is changed to 'nidigitalpattern'

## attributes.py

`'enum'` tags added to following attributes:
- `'HISTORY_RAM_MAX_SAMPLES_TO_ACQUIRE_PER_SITE'`

All occurrences of the following keys were removed along with their values:
- `'documentation'`
- `'attribute_class'`
- `'type_in_documentation'`

## enums.py

Metadata for following enums added:
- `'HistoryRamMaxSamplesToAcquirePerSite'`

Enums with more than 2 consecutive uppercase letters in their name (as abbreviations) have been changed to the letters other than first letter in the abbreviation to lowercase.

All occurrences of the following keys were removed along with their values:
- `'documentation'`


# Changes in metadata from the base metadata

## functions.py

All occurrences of the following keys were removed along with their values:
- `'documentation'`
- `'python_name'`
- `'type_in_documentation'`
- `'use_session_lock'`
- `'default-value'`
- `'is_repeated_capability'`
- `'repeated_capability_type'`
- `'python_api_converter_name'`

The following functions names were made Pascal and moved to their alphabetic position:
 - `close`
 - `error_message`
 - `reset`
 - `self_test`
 - `init`

 The following functions were tagged with `'init_method': True,` to ensure their generated service handlers register the new session
with the session_repository.
- `Init`
- `InitWithOptions`

`'cname'` tag added to following functions:
- `'ClockGeneratorAbort'`
- `'ClockGeneratorGenerateClock'`
- `'ClockGeneratorInitiate'`
- `'Close'`
- `'ErrorMessage'`
- `'FrequencyCounterConfigureMeasurementMode'`
- `'FrequencyCounterConfigureMeasurementTime'`
- `'Init'`
- `'PPMUConfigureApertureTime'`
- `'PPMUConfigureCurrentLevel'`
- `'PPMUConfigureCurrentLevelRange'`
- `'PPMUConfigureCurrentLimit'`
- `'PPMUConfigureCurrentLimitRange'`
- `'PPMUConfigureOutputFunction'`
- `'PPMUConfigureVoltageLevel'`
- `'PPMUConfigureVoltageLimits'`
- `'PPMUSource'`
- `'Reset'`
- `'SelfTest'`
- `'FrequencyCounterMeasureFrequency'`
- `'PPMUMeasure'`
