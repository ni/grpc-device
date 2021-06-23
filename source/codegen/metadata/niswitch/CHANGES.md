# Changes in metadata from the nimi-python metadata

## config.py

The following metadata was added : 
- 'service_class_prefix': 'NiSwitch',
- 'java_package': 'com.ni.niswitch.grpc',
- 'csharp_namespace': 'NationalInstruments.NISwitch.Grpc',
- 'namespace_component': 'niswitch',

Removed the 'repeated-capabilities' as it is python specific.

## attributes.py

The following attributes were added : 
- CLASS_SPEC_MAJOR_VERSION
- CLASS_SPEC_MINOR_VERSION
- RANGE_CHECK
- QUERY_INSTRUMENT_STATUS
- CACHE 
- RECORD_COERCIONS
- INTERCHANGE_CHECK 
- GROUP_CAPABILITIES
- SPECIFIC_DRIVER_PREFIX

## enums.py

Added an enum for the defined values of wire mode attribute.

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
- `'default-value'`

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

The following functions names were made Pascal and moved to their alphabetic position:
 - `close`
 - `error_message`
 - `reset`
 - `self_test`
 - `error_query`
 - `revision_query`
 
The following functions were tagged with `'init_method': True,` to ensure their generated service handlers register the new session with the session_repository.
- `init`
- `InitWithOptions`
- `InitWithTopology`

The following functions were given a field `grpc_field_number` and `grpc_raw_field_number` on `attribute_value` parameter to customize field number assigned to them in proto file.
- `CheckAttributeViInt32`
- `SetAttributeViInt32`