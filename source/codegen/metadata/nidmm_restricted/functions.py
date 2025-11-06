# -*- coding: utf-8 -*-
# This file is generated from NI-DMM API metadata version 26.0.0d90
functions = {
    'AttributeWasSetByUser': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'repCapName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'repCapName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'int32',
                'name': 'attributeId',
                'type': 'ViAttr'
            }
        ],
        'returns': 'ViBoolean'
    },
    'CachedReadStatus': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'acqBacklog',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'acqBacklog',
                'type': 'ViInt32'
            },
            {
                'cppName': 'acqStatus',
                'direction': 'out',
                'enum': 'AcquisitionStatus',
                'grpc_type': 'sint32',
                'name': 'acqStatus',
                'type': 'ViInt16'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchMultiPointWithCaching': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'maxTime',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'maxTime',
                'type': 'ViInt32'
            },
            {
                'cppName': 'arraySize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'arraySize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'readingArray',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'readingArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySize'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'actualPts',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'actualPts',
                'type': 'ViInt32'
            },
            {
                'cppName': 'isMonitoring',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'isMonitoring',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetError': {
        'codegen_method': 'private',
        'is_error_handling': True,
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'errorCode',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'errorCode',
                'type': 'ViStatus'
            },
            {
                'cppName': 'bufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'description',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'description',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetErrorMessage': {
        'codegen_method': 'private',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'errorCode',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'errorCode',
                'type': 'ViStatus'
            },
            {
                'cppName': 'bufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'errorMessage',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'errorMessage',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetOpenSessionsInformation': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'cppName': 'resourceName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'resourceName',
                'type': 'ViRsrc'
            },
            {
                'cppName': 'infoJson',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'infoJson',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'bufferSizeNeededInBytes'
                },
                'type': 'ViChar[]'
            },
            {
                'cppName': 'bufferSize',
                'direction': 'in',
                'grpc_type': 'uint64',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViUInt64'
            },
            {
                'cppName': 'bufferSizeNeededInBytes',
                'direction': 'out',
                'grpc_type': 'uint64',
                'name': 'bufferSizeNeededInBytes',
                'type': 'ViUInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'RequestPrivilege': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'privilegeLevel',
                'direction': 'in',
                'enum': 'PrivilegeLevel',
                'grpc_type': 'sint32',
                'name': 'privilegeLevel',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    }
}
