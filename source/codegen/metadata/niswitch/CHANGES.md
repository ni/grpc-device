# Changes in metadata from the nimi-python metadata

## config.py

The following metadata was added : 
- 'service_class_prefix': 'NiSwitch',
- 'java_package': 'com.ni.niswitch.grpc',
- 'csharp_namespace': 'NationalInstruments.NISwitch.Grpc',
- 'namespace_component': 'niswitch',

Removed the 'repeated-capabilities' as it is python specific.

## functions.py

All occurrences of the following keys were removed along with their values:
- `'python_api_converter_name'`
- `'documentation'`
- `'method_name_for_documentation'`
- `'method_templates'`
- `'python_name'`
- `'type_in_documentation'`
- `'codegen_method'`
- `'is_error_handling'`
- `'use_session_lock'`

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

The following APIs were newly added :
- init
- InitWithOptions
- IsDebounced
- Scan
- IsScanning
- ConfigureScanList
- ConfigureScanTrigger
- SetContinuousScan
- ClearError
- GetNextInterchangeWarning
- ResetInterchangeCheck
- ClearInterchangeWarnings
- GetNextCoercionRecord
- InvalidateAllAttributes
- GetAttributeViSession
- SetAttributeViSession
- All the CheckAttribute APIs(5)
- ErrorQuery
- RevisionQuery
