# -*- coding: utf-8 -*-
# This file is generated from NI-DCPower API metadata version 23.0.0d288
config = {
    'additional_headers': {
        'custom/ivi_errors.h': [
            'service.cpp'
        ]
    },
    'api_version': '23.0.0d288',
    'c_function_prefix': 'niDCPower_',
    'c_header': 'nidcpower.h',
    'close_function': 'Close',
    'csharp_namespace': 'NationalInstruments.Grpc.DCPower',
    'custom_types': [
        {
            'fields': [
                {
                    'grpc_type': 'double',
                    'name': 'frequency',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'sint32',
                    'name': 'referenceValueType',
                    'type': 'ViInt32'
                },
                {
                    'grpc_type': 'double',
                    'name': 'referenceValueA',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'referenceValueB',
                    'type': 'ViReal64'
                }
            ],
            'grpc_name': 'NILCRLoadCompensationSpot',
            'name': 'NILCRLoadCompensationSpot_struct'
        },
        {
            'fields': [
                {
                    'grpc_type': 'double',
                    'name': 'Vdc',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'Idc',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'stimulusFrequency',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'nidevice_grpc.NIComplexNumber',
                    'name': 'ACVoltage',
                    'type': 'struct NIComplexNumber_struct'
                },
                {
                    'grpc_type': 'nidevice_grpc.NIComplexNumber',
                    'name': 'ACCurrent',
                    'type': 'struct NIComplexNumber_struct'
                },
                {
                    'grpc_type': 'nidevice_grpc.NIComplexNumber',
                    'name': 'Z',
                    'type': 'struct NIComplexNumber_struct'
                },
                {
                    'grpc_type': 'double',
                    'name': 'ZMagnitude',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'ZPhase',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'nidevice_grpc.NIComplexNumber',
                    'name': 'Y',
                    'type': 'struct NIComplexNumber_struct'
                },
                {
                    'grpc_type': 'double',
                    'name': 'YMagnitude',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'YPhase',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'Ls',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'Cs',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'Rs',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'Lp',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'Cp',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'Rp',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'D',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'Q',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'uint32',
                    'name': 'measurementMode',
                    'type': 'ViUInt16'
                },
                {
                    'grpc_type': 'bool',
                    'name': 'dcInCompliance',
                    'type': 'ViBoolean'
                },
                {
                    'grpc_type': 'bool',
                    'name': 'acInCompliance',
                    'type': 'ViBoolean'
                },
                {
                    'grpc_type': 'bool',
                    'name': 'unbalanced',
                    'type': 'ViBoolean'
                }
            ],
            'grpc_name': 'NILCRMeasurement',
            'name': 'NILCRMeasurement_struct'
        }
    ],
    'driver_name': 'NI-DCPower',
    'java_package': 'com.ni.grpc.dcpower',
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nidcpower',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'nidcpower_32.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'nidcpower_64.dll',
                'type': 'cdll'
            }
        }
    },
    'linux_rt_support': True,
    'module_name': 'nidcpower',
    'namespace_component': 'nidcpower',
    'service_class_prefix': 'NiDCPower',
    'session_handle_parameter_name': 'vi',
    'status_ok': 'status >= 0'
}
