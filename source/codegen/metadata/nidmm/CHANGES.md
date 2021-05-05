# Changes in metadata from the nimi-python metadata

## config.py

The following metadata was added : 
- 'service_class_prefix': 'NiDmm'
- 'java_package': 'com.ni.grpc.dmm'
- 'csharp_namespace': 'NationalInstruments.Grpc.Dmm'
- 'namespace_component': 'nidmm'


## attributes.py

All occurrences of the following keys were removed along with their values:
- `'documentation'`
- `'lv_property'`

Metadata for following attributes added:
- `'RANGE_CHECK'`
- `'QUERY_INSTRUMENT_STATUS'`
- `'CACHE'`
- `'INTERCHANGE_CHECK'`
- `'SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION'`
- `'SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION'`
- `'CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION'`
- `'CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION'`
- `'GROUP_CAPABILITIES'`
- `'IO_SESSION'`
- `'TRIGGER_SLOPE'`
- `'SAMPLE_TRIGGER_SLOPE'`
- `'MEAS_DEST_SLOPE'`
- `'LATENCY'`
- `'SHUNT_VALUE'`

`'enum'` tag adding to the following attributes:
- `'APERTURE_TIME'`
- `'OFFSET_COMP_OHMS'`
- `'DC_BIAS'`
- `'POWERLINE_FREQ'`
- `'RANGE'`
- `'TRIGGER_DELAY'`

## enums.py

All occurrences of the following keys were removed along with their values:
- `'documentation'`

Enums with more than 2 consecutive uppercase letters in their name (as abbreviations) have been changed to the letters other than first letter in the abbreviation to lowercase. eg. DCBias to DcBias, ADCCalibration to AdcCalibration, etc. 

Metadata for following enums added:
- `'ApertureTime'`
- `'CalibrationCloseAction'`
- `'CalibrationType'`
- `'CompensatedOhms'`
- `'Configuration4022'`
- `'DcBias'`
- `'MiscCalibration'`
- `'PowerLineFrequencies'`
- `'Range'`
- `'TriggerDelays'`


# Changes in metadata from the base metadata

## functions.py

All occurrences of the following keys were removed along with their values:
- `'documentation'`
- `'python_name'`
- `'type_in_documentation'`
- `'use_session_lock'`
- `'default-value'`

The following functions names were made Pascal and moved to their alphabetic position:
 - `close`
 - `error_message`
 - `reset`
 - `self_test`
 - `error_query`
 - `revision_query`
 - `init`
 
The following functions were tagged with `'init_method': True,` to ensure their generated service handlers register the new session
with the session_repository.
- `Init`
- `InitWithOptions`
- `InitExtCal` : Added a 'custom_close' tag to this function, since this API has a corresponding close function called 'CloseExtCal'

`'enum'` tag added to the following functions:
- `'apertureTime`' parameter of function `'GetApertureTimeInfo'`
- `'action`' parameter of function `'CloseExtCal'`
- `'calType`' parameter of function `'CalibrationType'`
- `'offsetCompOhms`' parameter of function `'ConfigureOffsetCompOhms'`
- `'configuration`' parameter of function `'Control4022'`
- `'type`' parameter of function `'CalAdjustMisc'`
- `'powerLineFrequencyHz`' parameter of function `'ConfigurePowerLineFrequency'`
- `'triggerDelay`' parameter of function `'ConfigureTrigger'`

