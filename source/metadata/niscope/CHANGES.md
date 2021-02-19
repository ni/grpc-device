# Changes in metadata from the nimi-python metadata

## functions.py

The occurrences of `'default_value'` were not removed but should be removed once enum support is complete.

The occurrences of `'mechanism': 'python-code'` were not removed but should be removed once custom struct support is complete.

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

The following functions were changed from `private` to `public`:
- `ConfigureRefLevels`
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
