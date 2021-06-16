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
- `'CONFIG_PRODUCT_NUMBER'`
- `'RECORD_COERCIONS'`

`'enum'` tags added to following attributes:
- `'BUFFER_SIZE'`
- `'LATENCY'`
- `'SETTLE_TIME'`
- `'APERTURE_TIME'`
- `'OFFSET_COMP_OHMS'`
- `'DC_BIAS'`
- `'POWERLINE_FREQ'`
- `'RANGE'`
- `'TRIGGER_DELAY'`
- `'FREQ_VOLTAGE_RANGE'`
- `'SAMPLE_INTERVAL'`
- `'TRIGGER_COUNT'`
- `'SAMPLE_COUNT'`

`'FREQ_VOLTAGE_AUTO_RANGE'` (from nimi-python) changed to `'FREQ_VOLTAGE_AUTO_RANGE_VALUE'` to match the nidmm.h


## enums.py

All occurrences of the following keys were removed along with their values:
- `'documentation'`

Enums with more than 2 consecutive uppercase letters in their name (as abbreviations) have been changed to the letters other than first letter in the abbreviation to lowercase. eg. DCBias to DcBias, ADCCalibration to AdcCalibration, etc. 

Metadata for following enums added:
- `'BufferSize'`
- `'CalibrationType'`
- `'CompensatedOhms'`
- `'ControlCommit'`
- `'ApertureTime'`
- `'Configuration4022'`
- `'DcBias'`
- `'Latency'`
- `'PowerLineFrequencies'`
- `'Range'`
- `'SettleTime'`
- `'TriggerDelays'`
- `'FrequencyVoltageRange'`
- `'SampleInterval'`
- `'TriggerCount'`
- `'SampleCount'`
- `'TimeLimit'`

`'NIDMM_VAL_FIXED'` (from nimi-python) changed to `'NIDMM_VAL_TEMP_REF_JUNC_FIXED'` in the `'ThermocoupleReferenceJunctionType'` to match the documentation and the header file

Following calibration enums removed:
- `'CalibrationCloseAction'`
- `'LcCalibration'`
- `'MiscCalibration'`

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
- `'apertureTime'` parameter of function `'GetApertureTimeInfo'`
- `'calType'` parameter of function `'CalibrationType'`
- `'offsetCompOhms'` parameter of function `'ConfigureOffsetCompOhms'`
- `'configuration'` parameter of function `'Control4022'`
- `'powerLineFrequencyHz'` parameter of function `'ConfigurePowerLineFrequency'`
- `'triggerDelay'` parameter of function `'ConfigureTrigger'`
- `'controlAction'` parameter of function `'Control'`
- `'voltageRange'` parameter of function `'ConfigureFrequencyVoltageRange'`
- `'sampleInterval'` parameter of function `'ConfigureMultiPoint'`
- `'triggerCount'` parameter of function `'ConfigureMultiPoint'`
- `'sampleCount'` parameter of function `'ConfigureMultiPoint'`
- `'maximumTime'` parameter of function `'Fetch'`
- `'maximumTime'` parameter of function `'FetchMultiPoint'`
- `'maximumTime'` parameter of function `'FetchWaveform'`
- `'maximumTime'` parameter of function `'Read'`
- `'maximumTime'` parameter of function `'ReadMultiPoint'`
- `'maximumTime'` parameter of function `'ReadWaveform'`

Following calibration functions removed:
- `'CalAdjustGain'`
- `'CalAdjustACFilter'`
- `'CalAdjustLC'`
- `'CalAdjustLinearization'`
- `'CalAdjustMisc'`
- `'CalAdjustOffset'`
- `'CloseExtCal'`
- `'GetCalCount'`
- `'GetCalUserDefinedInfo'`
- `'GetCalUserDefinedInfoMaxSize'`
- `'InitExtCal'`
- `'RestoreLastExtCalConstants'`
- `'SetCalPassword'`
- `'SetCalUserDefinedInfo'`
