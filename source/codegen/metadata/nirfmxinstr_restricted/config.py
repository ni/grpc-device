# -*- coding: utf-8 -*-
config = {
    'api_version': '21.0.0',
    "internal_service": True,
    'c_header': 'RfmxInstr.h',
    'c_function_prefix': 'RfmxInstr_',
    'service_class_prefix': 'NiRFmxInstrRestricted',
    'java_package': 'com.ni.grpc.nirfmxinstrrestricted',
    'csharp_namespace': 'NationalInstruments.Grpc.NiRFmxInstrRestricted',
    'namespace_component': 'nirfmxinstr_restricted',
    'close_function': 'Close',
    'driver_name': 'NI-RFMXINSTR',
    'custom_types': [],
    'status_ok': 'status >= 0',
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nirfmxinstr',
                'type': 'cdll',
                'abi_version': '1'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'niRFmxInstr.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'niRFmxInstr.dll',
                'type': 'cdll'
            }
        }
    },
    'linux_rt_support': False,
    'metadata_version': '0.1',
    'module_name': 'nirfmxinstr_restricted',
    'session_class_description': 'An NI-RFmxInstr instrument handle.',
    'session_handle_parameter_name': 'instrument',
}
