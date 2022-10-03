# -*- coding: utf-8 -*-
# This file is generated from NI-DCPower API metadata version 23.0.0d9999
config = {
    'additional_headers': {
        'custom/ivi_errors.h': [
            'service.cpp'
        ]
    },
    'api_version': '23.0.0',
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
            'name': 'NILCRLoadCompensationSpot'
        },
        {
            'fields': [
                {
                    'grpc_type': 'double',
                    'name': 'vdc',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'idc',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'stimulusFrequency',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'nidevice_grpc.NIComplexNumber',
                    'name': 'acVoltage',
                    'type': 'NIComplexNumber_struct'
                },
                {
                    'grpc_type': 'nidevice_grpc.NIComplexNumber',
                    'name': 'acCurrent',
                    'type': 'NIComplexNumber_struct'
                },
                {
                    'grpc_type': 'nidevice_grpc.NIComplexNumber',
                    'name': 'z',
                    'type': 'NIComplexNumber_struct'
                },
                {
                    'grpc_type': 'double',
                    'name': 'zMagnitude',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'zPhase',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'nidevice_grpc.NIComplexNumber',
                    'name': 'y',
                    'type': 'NIComplexNumber_struct'
                },
                {
                    'grpc_type': 'double',
                    'name': 'yMagnitude',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'yPhase',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'ls',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'cs',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'rs',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'lp',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'cp',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'rp',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'd',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'q',
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
                },
                {
                    'grpc_type': 'double',
                    'name': 'reserved1',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'reserved2',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'reserved3',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'reserved4',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'reserved5',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'reserved6',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'reserved7',
                    'type': 'ViReal64'
                }
            ],
            'grpc_name': 'NILCRMeasurement',
            'name': 'NILCRMeasurement'
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
