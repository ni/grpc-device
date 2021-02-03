import common_helpers
def get_grpc_type_from_ivi(type, driver_name_camel):
    if 'ViSession' in type:
        return 'uint32'
    if 'ViBoolean' in type:
        return 'bool'
    if 'ViReal64' in type:
        return 'double'
    if 'ViInt32' in type:
        return 'int32'
    if 'ViConstString' in type:
        return 'string'
    if 'ViString' in type:
        return 'string'
    if 'ViRsrc' in type:
        return 'string'
    if 'ViChar' in type:
        return 'string'
    if 'ViReal32' in type:
        return 'float'
    if 'ViAttr' in type:
        return common_helpers.driver_name_to_pascal(driver_name_camel.replace("ni", "")) + "Attributes"
    if 'ViInt8' in type:
        return 'bytes'
    if 'void' in type:
        return 'bytes'
    if 'ViInt16' in type:
        return 'bytes'
    if 'ViInt64' in type:
        return 'int64'
    if 'ViUInt32' in type:
        return 'uint32'
    if 'ViUInt64' in type:
        return 'uint64'
    if 'ViStatus' in type:
        return 'int32'
    if 'ViAddr' in type:
        return 'bytes'
    if 'int' == type:
        return 'int32'
    return type