# Changes in metadata from the nimi-python metadata

## config.py

The following metadata was added : 
- 'service_class_prefix': 'NiSwitch',
- 'java_package': 'com.ni.niswitch.grpc',
- 'csharp_namespace': 'NationalInstruments.NISwitch.Grpc',
- 'namespace_component': 'niswitch',

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
- `fancy_self_test`

The following functions were changed from `private` to `public`:
- `GetAttributeViBoolean`
- `GetAttributeViInt32`
- `GetAttributeViReal64`
- `GetAttributeViString`
- `GetError`
- `ErrorMessage`
- `InitWithTopology`
- `InitiateScan`
- `SetAttributeViBoolean`
- `SetAttributeViInt32`
- `SetAttributeViReal64`
- `SetAttributeViString`
- `close`
- `self_test`

The following APIs are missing (compared to the C API documentation)
- Init
- InitWithOptions
- IsDebounced
- Scan
- IsScanning
- ConfigureScanList
- ConfigureScanTrigger
- SetContinuousScan
- ErrorQuery
- ClearError
- GetNextInterchangeWarning
- ResetInterchangeCheck
- ClearInterchangeWarnings
- GetNextCoercionRecord
- InvalidateAllAttributes
- RevisionQuery
- GetAttributeViSession
- SetAttributeViSession
- All the CheckAttribute APIs
