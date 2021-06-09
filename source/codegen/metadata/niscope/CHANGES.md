# Changes in metadata from the nimi-python metadata

## attributes.py

The following attributes were added : 
- RANGE_CHECK
- QUERY_INSTRUMENT_STATUS
- CACHE
- RECORD_COERCIONS
- DRIVER_SETUP
- INTERCHANGE_CHECK
- SPECIFIC_DRIVER_PREFIX
- GROUP_CAPABILITIES
- SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION
- SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION
- CLOCK_SYNC_PULSE_SOURCE
- FETCH_INTERLEAVED_DATA
- DEVICE_NUMBER
- EXPORTED_SAMPLE_CLOCK_OUTPUT_TERMINAL
- OSCILLATOR_PHASE_DAC_VALUE
- 5V_OUT_OUTPUT_TERMINAL
- DDC_ENABLED
- DDC_FREQUENCY_TRANSLATION_ENABLED
- DDC_CENTER_FREQUENCY
- DDC_DATA_PROCESSING_MODE
- DDC_FREQUENCY_TRANSLATION_PHASE_I
- DDC_FREQUENCY_TRANSLATION_PHASE_Q
- DIGITAL_GAIN
- DIGITAL_OFFSET
- OVERFLOW_ERROR_REPORTING
- DDC_Q_SOURCE
- FETCH_INTERLEAVED_IQ_DATA
- DITHER_ENABLED
- FRACTIONAL_RESAMPLE_ENABLED
- P2P_SAMPLES_AVAIL_IN_ENDPOINT
- P2P_DATA_TRANS_PERMISSION_ADDR
- P2P_DATA_TRANS_PERMISSION_ADDR_TYPE
- P2P_DESTINATION_WINDOW_ADDR
- P2P_DESTINATION_WINDOW_ADDR_TYPE
- P2P_DESTINATION_WINDOW_SIZE
- P2P_NOTIFY_PUSH_MESSAGE_ON
- P2P_NOTIFY_MESSAGE_PUSH_ADDR
- P2P_NOTIFY_MESSAGE_PUSH_ADDR_TYPE
- P2P_NOTIFY_MESSAGE_PUSH_VALUE
- P2P_ENABLED
- P2P_CHANNELS_TO_STREAM
- P2P_SAMPLES_TRANSFERRED
- P2P_MOST_SAMPLES_AVAIL_IN_ENDPOINT
- P2P_ENDPOINT_SIZE
- P2P_MANUAL_CONFIGURATION_ENABLED
- P2P_ENDPOINT_OVERFLOW
- P2P_FIFO_ENDPOINT_COUNT
- P2P_ONBOARD_MEMORY_ENABLED
- P2P_STREAM_RELATIVE_TO
- P2P_SAMPLES_TRANSFERRED_PER_RECORD

The following attributes were removed :
- RECORD_ARM_SOURCE

## config.py

The following metadata was added:
- `'service_class_prefix': 'NiScope'`
- `'java_package': 'com.ni.grpc.scope'`
- `'csharp_namespace': 'NationalInstruments.Grpc.Scope'`
- `'namespace_component': 'niscope'`

The fields of the custom waveform-info struct were added to `'custom_types'` in place of the `'ctypes_type'`, `'file_name'`, and `'python_name'`. A  `'grpc_name'` field was also added which was the snake case version of the name field.

Two structs were added
- `'NIComplexNumber_struct'`
- `'NIComplexI16_struct'`

## functions.py

The occurrences of `'default_value'` were not removed but should be removed once enum support is complete.

All occurrences of the following keys were removed along with their values:
- `'python_api_converter_name'`
- `'documentation'`
- `'method_name_for_documentation'`
- `'method_templates'`
- `'python_name'`
- `'type_in_documentation'`

The following `python-only` functions were removed:
- `FancyFetch`
- `FancyGetEqualizationFilterCoefficients`
- `FancyGetExtCalLastDateAndTime`
- `FancyGetExtCalLastTemp`
- `FancyGetSelfCalLastDateAndTime`
- `FancyGetSelfCalLastTemp`
- `FancyRead`
- `FetchDispatcher`
- `fancy_self_test`
- `FancyFetchArrayMeasurement`
- `FancyFetchMeasurementStats`

The following functions were changed from `private` to `public`:
- `ActualMeasWfmSize`
- `ActualNumWfms`
- `Fetch`
- `FetchArrayMeasurement`
- `FetchBinary16`
- `FetchBinary32`
- `FetchBinary8`
- `FetchMeasurementStats`
- `GetAttributeViBoolean`
- `GetAttributeViInt32`
- `GetAttributeViInt64`
- `GetAttributeViReal64`
- `GetAttributeViString`
- `GetEqualizationFilterCoefficients`
- `error_message`
- `InitWithOptions`
- `InitiateAcquisition`
- `Read`
- `SetAttributeViBoolean`
- `SetAttributeViInt32`
- `SetAttributeViInt64`
- `SetAttributeViReal64`
- `SetAttributeViString`
- `close`
- `self_test`

The following functions were changed from 'private' to 'no' because they did not exist in niScope.h:
- `CalFetchDate` - not found in niScope.h
- `CalFetchTemperature` - not found in niScope.h
- `ConfigureRefLevels` - obsolete

The following functions, not originally in the nimi-python metadata were added:
 - `ActualRecordLength`
 - `AdjustSampleClockRelativeDelay`
 - `CableSenseSignalStart`
 - `CableSenseSignalStop`
 - `CheckAttributeViBoolean`
 - `CheckAttributeViInt32`
 - `CheckAttributeViInt64`
 - `CheckAttributeViReal64`
 - `CheckAttributeViSession`
 - `CheckAttributeViString`
 - `ConfigureAcquisition`
 - `ConfigureClock`
 - `ConfigureTriggerGlitch`
 - `ConfigureTriggerRunt`
 - `ConfigureTriggerWidth`
 - `ErrorHandler`
 - `ExportSignal`
 - `FetchComplex`
 - `FetchComplexBinary16`
 - `FetchMeasurement`
 - `GetAttributeViSession`
 - `GetChannelName`
 - `GetChannelNameFromString`
 - `GetErrorMessage`
 - `GetFrequencyResponse`
 - `GetNormalizationCoefficients`
 - `GetScalingCoefficients`
 - `GetStreamEndpointHandle`
 - `Init`
 - `ReadMeasurement`
 - `RevisionQuery`
 - `SampleMode`
 - `SampleRate`
 - `SetAttributeViSession`

The following functions names were made Pascal and moved to their alphabetic position:
 - `close`
 - `error_message`
 - `reset`
 - `self_test`

The following functions were given a field `grpc_type`:
- `Fetch`
- `FetchArrayMeasurement`
- `FetchBinary16`
- `FetchBinary32`
- `FetchBinary8`
- `Read`

The following functions were given a field `grpc_field_number` and `grpc_raw_field_number` on `value` parameter to customize field number assigned to them in proto file.
- `CheckAttributeViInt32`
- `CheckAttributeViInt64`
- `CheckAttributeViReal64`
- `SetAttributeViInt32`
- `SetAttributeViInt64`
- `SetAttributeViReal64`

The following functions were changed from `public` to `CustomCode` to indicate their service handlers won't be generated and instead should be implemented by hand in niscope_service.custom.cpp.
- `Fetch`
- `FetchArrayMeasurement`
- `FetchBinary16`
- `FetchBinary8`
- `FetchMeasurementStats`
- `Read`
- `FetchComplex`
- `FetchComplexBinary16`
- `FetchMeasurement`
- `GetScalingCoefficients`
- `ReadMeasurement`

Instances of `python-code` used for the `size` mechanism were updated to `custom-code` to reflect their implementations will be handled in the custom service handler implementations.

The following functions were tagged with `'init_method': True` to ensure their generated service handlers register the new session with the session_repository.
- `Init`
- `InitWithOptions`

The following parameters were marked as `'include_in_proto': False` because they are calculated in the service handler and shouldn't be passed in.
- `bufferSize` in `GetNormalizationCoefficients`
- `bufferSize` in `GetScalingCoefficients`
- `measurementWaveformSize` in `FetchArrayMeasurement`