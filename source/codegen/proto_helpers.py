def get_grpc_type_from_ivi(type, driver_name_pascal):
    if 'ViSession' in type:
        return 'fixed64'
    if 'ViBoolean' in type:
        return 'bool'
    if 'ViReal64' in type:
        return 'double'
    if 'ViInt32' in type:
        return 'sint32'
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
        return driver_name_pascal + "Attributes"
    if 'ViInt8' in type:
        return 'uint32'
    if 'void*' in type:
        return 'fixed64'
    if 'ViInt16' in type:
        return 'uint32'
    if 'ViInt64' in type:
        return 'int64'
    if 'ViUInt32' in type:
        return 'uint32'
    if 'ViUInt64' in type:
        return 'uint64'
    if 'ViStatus' in type:
        return 'sint32'
    if 'ViAddr' in type:
        return 'fixed64'
    if 'hightime.datetime' in type:
        return 'google.protobuf.Timestamp'
    if 'CustomStruct' in type:
        return 'fixed64'
    if 'int' == type:
        return 'sint32'
    return type
    
def is_custom_struct(type):
    if 'CustomStruct' in type:
        return True
    else:
        return False