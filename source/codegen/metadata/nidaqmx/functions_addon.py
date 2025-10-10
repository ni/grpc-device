functions_override_metadata = {
    'ReadAnalogWaveforms': {
        'returns': 'int32',
        'codegen_method': 'CustomCodeNoLibrary',
        'parameters': [
            {
                'ctypes_data_type': 'ctypes.TaskHandle',
                'direction': 'in',
                'is_optional_in_python': False,
                'name': 'task',
                'python_data_type': 'TaskHandle',
                'python_description': '',
                'python_type_annotation': 'TaskHandle',
                'type': 'TaskHandle'
            },
            {
                'ctypes_data_type': 'ctypes.c_int',
                'direction': 'in',
                'is_optional_in_python': False,
                'name': 'numberOfSamplesPerChannel',
                'python_data_type': 'int',
                'python_description': '',
                'python_type_annotation': 'int',
                'type': 'int32'
            },
            {
                'ctypes_data_type': 'ctypes.c_double',
                'direction': 'in',
                'is_optional_in_python': True,
                'name': 'timeout',
                'python_data_type': 'float',
                'python_default_value': '10.0',
                'python_description': 'Specifies the time in seconds to wait for the device to respond before timing out.',
                'python_type_annotation': 'Optional[float]',
                'type': 'float64'
            },
            {
                # TODO: change this to the WaveformAttributeMode enum
                'name': 'waveformAttributeMode',
                'type': 'int32',
                'direction': 'in'
            },
            # We need to import waveforms.proto from ni-apis for this
            # {
            #     'name': 'waveforms',
            #     'type': 'repeated ni.protobuf.types.AnalogWaveformDouble',
            #     'direction': 'out'
            # }
        ]
    }
}

functions_validation_suppressions = {
    'WriteCtrFreq': {
        'parameters': {
            # size is determined by numSampsPerChan and how many channels are in the task
            'frequency': ['ARRAY_PARAMETER_NEEDS_SIZE'],
            'dutyCycle': ['ARRAY_PARAMETER_NEEDS_SIZE'],
        }
    },
    'WriteCtrTicks': {
        'parameters': {
            # size is determined by numSampsPerChan and how many channels are in the task
            'highTicks': ['ARRAY_PARAMETER_NEEDS_SIZE'],
            'lowTicks': ['ARRAY_PARAMETER_NEEDS_SIZE'],
        }
    },
    'WriteCtrTime': {
        'parameters': {
            # size is determined by numSampsPerChan and how many channels are in the task
            'highTime': ['ARRAY_PARAMETER_NEEDS_SIZE'],
            'lowTime': ['ARRAY_PARAMETER_NEEDS_SIZE'],
        }
    },
    'InternalWriteDigitalWaveform': {
        'parameters': {
            # size is determined by numSampsPerChan and how many channels are in the task
            'writeArray': ['ARRAY_PARAMETER_NEEDS_SIZE'],
        }
    },
    'ReadAnalogWaveforms': {
        'parameters': {
            # size is determined by the number of channels in the task
            'waveforms': ['ARRAY_PARAMETER_NEEDS_SIZE']
        }
    }
}

# size is determined by numSampsPerChan and how many channels are in the task
for function in ['WriteAnalogF64', 'WriteBinaryI16', 'WriteBinaryI32', 'WriteBinaryU16',
 'WriteBinaryU32', 'WriteDigitalLines', 'WriteDigitalU16', 'WriteDigitalU32', 'WriteDigitalU8',
 'WriteRaw']:
    functions_validation_suppressions[function] = {
        'parameters': {
            'writeArray': ['ARRAY_PARAMETER_NEEDS_SIZE']
        }
    }
