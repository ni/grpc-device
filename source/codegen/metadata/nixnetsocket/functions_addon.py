functions_override_metadata = {}

# Client requests the amount of data to read.
functions_validation_suppressions = {
    name: {"parameters": {"mem": ["ARRAY_PARAMETER_NEEDS_SIZE"]}} for name in ["Recv", "RecvFrom"]
}
