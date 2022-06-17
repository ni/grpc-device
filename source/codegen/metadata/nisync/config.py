# -*- coding: utf-8 -*-
config = {
    "api_version": "20.1.0",
    "c_header": "nisync.h",
    "c_function_prefix": "niSync_",
    "service_class_prefix": "NiSync",
    "java_package": "com.ni.grpc.sync",
    "csharp_namespace": "NationalInstruments.Grpc.Sync",
    "namespace_component": "nisync",
    "close_function": "Close",
    "context_manager_name": {
        "abort_function": "Abort",
        "initiate_function": "InitiateAcquisition",
        "task": "acquisition",
    },
    "custom_types": [],
    "driver_name": "NI-SYNC",
    "init_function": "init",
    "status_ok": "status >= 0",
    "library_info": {
        "Linux": {"64bit": {"name": "nisync", "type": "cdll"}},
        "Windows": {
            "32bit": {"name": "nisync.dll", "type": "windll"},
            "64bit": {"name": "nisync.dll", "type": "cdll"},
        },
    },
    'linux_rt_support': True,
    "metadata_version": "2.0",
    "module_name": "nisync",
    "repeated_capabilities": [{"prefix": "", "python_name": "channels"}],
    "session_class_description": "An NI-SYNC session to a National Instruments timing and synchronization device.",
    "session_handle_parameter_name": "vi",
    "uses_nitclk": True,
}
