functions_override_metadata = {
    'ReadAnalogWaveforms': {
        'returns': 'int32',
        'codegen_method': 'CustomCodeNoLibrary',
        'parameters': [
            {
                'name': 'taskHandle',
                'type': 'TaskHandle',
                'direction': 'in'
            },
            {
                'name': 'numberOfSamplesPerChannel',
                'type': 'int32',
                'direction': 'in'
            },
            {
                'name': 'timeout',
                'type': 'float64',
                'direction': 'in'
            },
            # We need to import waveforms.proto or something for this to work
            # {
            #     'name': 'waveforms',
            #     'type': 'AnalogWaveform[]',
            #     'direction': 'out'
            # },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'name': 'waveformAttributeMode',
                'type': 'int32',
                'direction': 'in'
            }
        ],
        'documentation': {
            'description': 'Reads analog waveforms from the specified task'
        }
    }
}

functions_validation_suppressions = {
    'ReadAnalogWaveforms': {
        'parameters': {
            # size is determined by the number of channels in the task
            'waveforms': ['ARRAY_PARAMETER_NEEDS_SIZE']
        }
    },
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
