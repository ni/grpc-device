# Changes in metadata from the nimi-python metadata

## functions.py

The following functions were tagged with `'init_method': True,` to ensure their generated service handlers register the new session
with the session_repository.
- `init`

The following function parameters were changes to camel case so the generated name would be snake case.
- `idQuery` parameter in `init`
