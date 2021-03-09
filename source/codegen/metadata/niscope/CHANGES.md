# Changes in metadata from the nimi-python metadata

## config.py

The following metadata was added:
- `'service_class_prefix': 'NiScope'`
- `'java_package': 'com.ni.scope.grpc'`
- `'csharp_namespace': 'NationalInstruments.Scope.Grpc'`
- `'namespace_component': 'scope'`

The fields of the custom waveform-info struct were added to `'custom_types'` in place of the `'ctypes_type'`,
`'file_name'`, and `'python_name'`. A  `'grpc_name'` field was also added which was the snake case version of the name field.

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

The following functions were changed from `public` to `CustomCode` to indicate their service handlers won't be generated and instead
should be implemented by hand in niscope_service.custom.cpp.
- `Fetch`
- `FetchArrayMeasurement`
- `FetchBinary16`
- `FetchBinary8`
- `FetchMeasurementStats`
- `Read`

Instances of `python-code` used for the `size` mechanism were updated to `custom-code` to reflect their implementations will be handled
in the custom service handler implementations.

The following functions were tagged with `'init_method': True,` to ensure their generated service handlers register the new session
with the session_repository.
- `Init`
- `InitWithOptions`
