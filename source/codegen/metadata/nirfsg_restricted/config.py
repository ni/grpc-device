# -*- coding: utf-8 -*-
config = {
    'api_version': '23.0.0',
    'c_header': 'niRFSGPrivate.h',
    'c_function_prefix': 'niRFSG_',
    'service_class_prefix': 'NiRFSGRestricted',
    'java_package': 'com.ni.grpc.rfsgrestricted',
    'csharp_namespace': 'NationalInstruments.Grpc.NiRFSGRestricted',
    'namespace_component': 'nirfsg_restricted',
    'close_function': None,
    'custom_types': [],
    'additional_headers': {'custom/ivi_errors.h': ['service.cpp']},
    'code_readiness': 'Release',
    'driver_name': 'NI-RFSG-RESTRICTED',
    'is_restricted': True,
    'status_ok': 'status >= 0',
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nirfsg',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'niRFSG_32.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'niRFSG_64.dll',
                'type': 'cdll'
            }
        }
    },
    'linux_rt_support': False,
    'module_name': 'nirfsg_restricted',
    'session_handle_parameter_name': 'vi',
    'duplicate_resource_handles_allowed': True,
}
