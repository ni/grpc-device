# Changes in metadata from the nimi-python metadata

## functions.py

The following functions, not originally in nimi-python metadata, were newly added:
- `'InitExtCal'`
- `'CloseExtCal'`
- `'BoolArrayInputFunction'`
	- This function allows testing of ViBoolean[] input parameter
- `'GetViUInt8'`
	- This function allows testing of ViUInt8 parameter
- `'ViUInt8ArrayInputFunction'`
	- This function allows testing of ViUInt8[] input parameter
- `'ViUInt8ArrayOutputFunction'`
	- This function allows testing of ViUInt8[] output parameter
- `'AcceptViUInt32Array'`
	- This function allows testing of ViUInt32[] input parameter
- `'GetViInt32Array'`
	- This function allows testing of ViInt32[] output parameter
- `'GetViUInt32Array'`
	- This function allows testing of ViUInt32[] output parameter
- `'AcceptViSessionArray'`
	- This function allows testing of ViSession[] input parameter
- `'GetArrayViUInt8WithEnum'`
  - This function allows testing of ViUInt8[] output parameters that use enum
- Changed `'GetAnIviDanceWithATwistString'` to `'GetAnIviDanceWithATwistArray'` and updated the parameters
    -  This function allows testing of ivi-dance-with-a-twist mechanism
- `'GetAttributeViSession'`
    - This function allows testing `ViSession` out parameters from non-open methods.
The following functions were tagged with `'init_method': True,` to ensure their generated service handlers register the new session
with the session_repository.
- `InitWithOptions`
- `InitExtCal` : Added a 'custom_close' tag to this function, since this API has a corresponding close function called `'CloseExtCal'`

The following function was tagged with `'custom_close_method': True,` to ensure that the generated service handler of this function removes
the registered session from session_repository.
- `CloseExtCal`

Added `'grpc_type'` to `'SetCustomTypeArray'` since the API uses CustomStruct.
