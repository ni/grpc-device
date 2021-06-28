# Changes in metadata from the nimi-python metadata

## functions.py

The following functions, not originally in nimi-python metadata, were newly added:
- `'InitExtCal'`
- `'CloseExtCal'`
- `'BoolArrayInputFunction'`
	- This function allows testing of ViBoolean[] input parameter
- `'AcceptViUInt32Array'`
	- This function allows testing of ViUInt32[] input parameter
- `'GetViInt32Array'`
	- This function allows testing of ViInt32[] output parameter
- `'GetViUInt32Array'`
	- This function allows testing of ViUInt32[] output parameter
 
The following functions were tagged with `'init_method': True,` to ensure their generated service handlers register the new session
with the session_repository.
- `InitWithOptions`
- `InitExtCal` : Added a 'custom_close' tag to this function, since this API has a corresponding close function called `'CloseExtCal'`

The following function was tagged with `'custom_close_method': True,` to ensure that the generated service handler of this function removes
the registered session from session_repository.
- `CloseExtCal`
