functions_override_metadata = {
    'ReadAnalogF64': {
        'python_codegen_method': 'CustomCode_Read',
    },
    'ReadAnalogScalarF64': {
        'python_codegen_method': 'CustomCode_Read_Scalar',
    },
    'ReadBinaryI16': {
        'python_codegen_method': 'CustomCode_Read',
    },
    'ReadBinaryI32': {
        'python_codegen_method': 'CustomCode_Read',
    },
    'ReadBinaryU16': {
        'python_codegen_method': 'CustomCode_Read',
    },
    'ReadBinaryU32': {
        'python_codegen_method': 'CustomCode_Read',
    },
    'ReadCounterF64': {
        'python_codegen_method': 'CustomCode_Read',
    },
    'ReadCounterF64Ex': {
        'python_codegen_method': 'CustomCode_Read',
    },
    'ReadCounterScalarF64': {
        'python_codegen_method': 'CustomCode_Read_Scalar',
    },
    'ReadCounterScalarU32': {
        'python_codegen_method': 'CustomCode_Read_Scalar',
    },
    'ReadCounterU32': {
        'python_codegen_method': 'CustomCode_Read',
    },
    'ReadCounterU32Ex': {
        'python_codegen_method': 'CustomCode_Read',
    },
    'ReadCtrFreq': {
        'python_codegen_method': 'CustomCode_Read',
    },
    'ReadCtrFreqScalar': {
        'python_codegen_method': 'CustomCode_Read_Scalar',
    },
    'ReadCtrTicks': {
        'python_codegen_method': 'CustomCode_Read',
    },
    'ReadCtrTicksScalar': {
        'python_codegen_method': 'CustomCode_Read_Scalar',
    },
    'ReadCtrTime': {
        'python_codegen_method': 'CustomCode_Read',
    },
    'ReadCtrTimeScalar': {
        'python_codegen_method': 'CustomCode_Read_Scalar',
    },
    'ReadDigitalLines': {
        'python_codegen_method': 'CustomCode_Read',
    },
    'ReadDigitalScalarU32': {
        'python_codegen_method': 'CustomCode_Read_Scalar',
    },
    'ReadDigitalU16': {
        'python_codegen_method': 'CustomCode_Read',
    },
    'ReadDigitalU32': {
        'python_codegen_method': 'CustomCode_Read',
    },
    'ReadDigitalU8': {
        'python_codegen_method': 'CustomCode_Read',
    },
    'ReadPowerScalarF64': {
        'python_codegen_method': 'CustomCode_Read_Scalar',
    },
    'WriteAnalogF64': {
        'python_codegen_method': 'CustomCode_Write',
    },
    'WriteAnalogScalarF64': {
        'python_codegen_method': 'CustomCode_Write_Scalar',
    },
    'WriteBinaryI16': {
        'python_codegen_method': 'CustomCode_Write',
    },
    'WriteBinaryI32': {
        'python_codegen_method': 'CustomCode_Write',
    },
    'WriteBinaryU16': {
        'python_codegen_method': 'CustomCode_Write',
    },
    'WriteBinaryU32': {
        'python_codegen_method': 'CustomCode_Write',
    },
    'WriteCtrFreq': {
        'python_codegen_method': 'CustomCode_Write',
    },
    'WriteCtrFreqScalar': {
        'python_codegen_method': 'CustomCode_Write_Scalar',
    },
    'WriteCtrTicks': {
        'python_codegen_method': 'CustomCode_Write',
    },
    'WriteCtrTicksScalar': {
        'python_codegen_method': 'CustomCode_Write_Scalar',
    },
    'WriteCtrTime': {
        'python_codegen_method': 'CustomCode_Write',
    },
    'WriteCtrTimeScalar': {
        'python_codegen_method': 'CustomCode_Write_Scalar',
    },
    'WriteDigitalLines': {
        'python_codegen_method': 'CustomCode_Write',
    },
    'WriteDigitalScalarU32': {
        'python_codegen_method': 'CustomCode_Write_Scalar',
    },
    'WriteDigitalU16': {
        'python_codegen_method': 'CustomCode_Write',
    },
    'WriteDigitalU32': {
        'python_codegen_method': 'CustomCode_Write',
    },
    'WriteDigitalU8': {
        'python_codegen_method': 'CustomCode_Write',
    },
    'ReadPowerBinaryI16':{
        'python_codegen_method': 'CustomCode_Read',
    },
    'ReadPowerF64':{
        'python_codegen_method': 'CustomCode_Read',
    },
    'ReadRaw':{
        'python_codegen_method': 'CustomCode_Read',
    },
    'WriteRaw':{
        'python_codegen_method': 'CustomCode_Write',
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
