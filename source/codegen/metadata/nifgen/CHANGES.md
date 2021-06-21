# Changes in metadata from the nimi-python metadata

## config.py

The following metadata was added:
- 'c_function_prefix': 'niFgen_'
- 'service_class_prefix': 'NiFgen'
- 'java_package': 'com.ni.grpc.fgen'
- 'csharp_namespace': 'NationalInstruments.Grpc.Fgen'

# Changes in metadata from the base metadata

## functions.py

The following functions were tagged with their corresponding CNAME tag
- Close
- ErrorMessage
- Reset
- SelfTest
- ErrorQuery
- Init
- RevisionQuery

Added value_twist attribute to the coefficientsArray parameter of GetFirFilterCoefficients function.

Added 'grpc_type' tag to these APIs since they use custom types : 
- CreateWaveformComplexF64
- WriteComplexBinary16Waveform

The following function was tagged as 'codegen_method':'CustomCode':
- CreateAdvancedArbSequence

For the `coercedMarkersArray` parameter of `CreateAdvancedArbSequence` function:
  - 'mechanism' for `size` was changed to 'custom-code'
  - 'value' for `size` was changed to 'sequenceLength'

For the `errorMessage` parameter of `ErrorHandler` function:
  - 'type' was changed to 'ViChar[]'
  - 'mechanism' for `size` was changed to 'fixed'
  - 'value' for `size` was changed to '256'

`enum` tag was added to parameters on following functions:
- `outputMode` parameter in `ConfigureOutputMode` function

The following functions removed as they are obsolete:
- ConfigureGain
- ConfigureRefClockFrequency
- ConfigureRefClockSource
- ConfigureTriggerSource
- ConfigureUpdateClockSource
- SendSoftwareTrigger

The following Calibration functions were removed as we are not supporting them in gRPC :
- `'InitExtCal'`
- `'CloseExtCal'`
- `'InitializeAnalogOutputCalibration'`
- `'WriteBinary16AnalogStaticValue'`
- `'CalAdjustMainPathPreAmpOffset'`
- `'CalAdjustMainPathPreAmpGain'`
- `'CalAdjustMainPathPostAmpGainAndOffset'`
- `'CalAdjustDirectPathGain'`
- `'CalAdjustMainPathOutputImpedance'`
- `'CalAdjustDirectPathOutputImpedance'`
- `'InitializeOscillatorFrequencyCalibration'`
- `'CalAdjustOscillatorFrequency'`
- `'InitializeCalADCCalibration'`
- `'CalAdjustAdc'`
- `'ReadCalADC'`
- `'InitializeFlatnessCalibration'`
- `'CalAdjustFlatness'`
- `'ChangeExtCalPassword'`
- `'GetCalUserDefinedInfo'`
- `'GetCalUserDefinedInfoMaxSize'`
- `'RestoreLastExtCalConstants'`
- `'SetCalUserDefinedInfo'`

## attributes.py

Following attributes missing in attributes.hapigen, taken from constants.hapigen:
- `BURST_COUNT`
- `CHANNEL_COUNT`

Following enum values removed because the enums of string type are not supported in grpc:
- `SampleClockSource` from `SAMPLE_CLOCK_SOURCE`
- `ReferenceClockSource` from `REFERENCE_CLOCK_SOURCE`
- `SampleClockTimebaseSource` from `SAMPLE_CLOCK_TIMEBASE_SOURCE`

Following attributes removed as Calibrations is no longer supported for gRPC:
- `CAL_ADC_INPUT`
- `GAIN_DAC_VALUE`
- `OFFSET_DAC_VALUE`
- `OSCILLATOR_FREQ_DAC_VALUE`
- `POST_AMPLIFIER_ATTENUATION`
- `PRE_AMPLIFIER_ATTENUATION`

## enums.py

All occurrences of the following keys were removed along with their values:
- `'documentation'`

Metadata for following enums missing in enums.hapigen, taken from constants.hapigen:
- `'FrequencyListOptions'`
- `'SequenceHandle'`
- `'WaveformHandle'`
- `'ArbitraryWaveformHandle'`
- `'ArbitrarySequenceHandle'`
- `'BurstCount'`
- `'FrequencyListHandle'`
- `'LoadImpedance'`
- `'OspOverflowStatus'`
- `'OutputImpedance'`
- `'SampleRate'`
- `'AddressType'`
- `'Signal'`
- `'RouteSignalFrom'`
- `'RouteSignalTo'`

