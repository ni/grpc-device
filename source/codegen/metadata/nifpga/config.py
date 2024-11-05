# -*- coding: utf-8 -*-
config = {
    'api_version': '24.3.0',
    'c_header': 'NiFpga.h',
    'c_function_prefix': 'NiFpga_',
    'c_dll_function_prefix': 'NiFpgaDll_',
    'service_class_prefix': 'NiFpga',
    'java_package': 'com.ni.grpc.nifpga',
    'csharp_namespace': 'NationalInstruments.Grpc.NiFpga',
    'namespace_component': 'nifpga',
    'init_function': 'Open',
    'close_function': 'Close',
    'code_readiness': 'Release',
    'driver_name': 'NI-FPGA',
    'status_ok': 'status >= 0',
    'additional_protos': ['data_moniker.proto'],
    'resource_handle_type': ['NiFpga_Session'],
    'type_to_grpc_type': {
        'NiFpga_Session': 'nidevice_grpc.Session',
        'char[]': 'string',
        'NiFpga_Status': 'int32',
        'size_t': 'uint32',
        'int8_t': 'int32',
        'int16_t': 'int32',
        'int32_t': 'int32',
        'int64_t': 'int64',       
        'uint8_t':'uint32',
        'uint16_t': 'uint32',
        'uint32_t': 'uint32',
        'uint64_t': 'uint64',  
        'NiFpga_Bool': 'bool',
        'NiFpga_FifoProperty': 'uint32',
    },
    'has_streaming_api': True,
    'use_dynload_msvc': True,
    'use_protobuf_arenas': True,
    'custom_types': [],
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'NiFpga',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'NiFpga.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'NiFpga.dll',
                'type': 'cdll'
            }
        }
    },
    'linux_rt_support': True,
    'metadata_version': '0.1',
    'module_name': 'nifpga',
    'session_class_description': 'An NI-FPGA session.',
    'session_handle_parameter_name': 'session'
}