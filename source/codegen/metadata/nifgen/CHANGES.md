# Changes in metadata from the nimi-python metadata

## config.py

The following metadata was added:
- 'c_function_prefix': 'niFgen_'
- 'service_class_prefix': 'NiFgen'
- 'java_package': 'com.ni.grpc.fgen'
- 'csharp_namespace': 'NationalInstruments.Grpc.Fgen'

## attributes.py

The documentation and lv_property values were removed from all the attributes.

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

The following functions removed as they are obsolete:
- ConfigureGain
- ConfigureRefClockFrequency
- ConfigureRefClockSource
- ConfigureTriggerSource
- ConfigureUpdateClockSource
- SendSoftwareTrigger