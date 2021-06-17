# Changes in metadata from the nimi-python metadata

## config.py

The following metadata was added:
- 'c_function_prefix': 'niDCPower_'
- 'service_class_prefix': 'NiDCPower'
- 'java_package': 'com.ni.grpc.dcpower'
- 'csharp_namespace': 'NationalInstruments.Grpc.DCPower'

The following function name was capitalised:
- 'close_function': 'Close'

## attributes.py

The documentation and lv_property values were removed from all the attributes.

The following attributes were added : 
- NIDCPOWER_ATTRIBUTE_RANGE_CHECK
- NIDCPOWER_ATTRIBUTE_CACHE
- NIDCPOWER_ATTRIBUTE_RECORD_COERCIONS
- NIDCPOWER_ATTRIBUTE_INTERCHANGE_CHECK
- NIDCPOWER_ATTRIBUTE_GROUP_CAPABILITIES
- NIDCPOWER_ATTRIBUTE_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION
- NIDCPOWER_ATTRIBUTE_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION
- NIDCPOWER_ATTRIBUTE_DIGITAL_EDGE_START_TRIGGER_EDGE
- NIDCPOWER_ATTRIBUTE_DIGITAL_EDGE_SEQUENCE_ADVANCE_TRIGGER_EDGE
- NIDCPOWER_ATTRIBUTE_DIGITAL_EDGE_SOURCE_TRIGGER_EDGE
- NIDCPOWER_ATTRIBUTE_DIGITAL_EDGE_MEASURE_TRIGGER_EDGE
- NIDCPOWER_ATTRIBUTE_DIGITAL_EDGE_PULSE_TRIGGER_EDGE
- NIDCPOWER_ATTRIBUTE_DIGITAL_EDGE_SHUTDOWN_TRIGGER_EDGE

`enum` tag was added to following attributes:
- NIDCPOWER_ATTRIBUTE_VOLTAGE_LEVEL_AUTORANGE
- NIDCPOWER_ATTRIBUTE_POWER_LINE_FREQUENCY
- NIDCPOWER_ATTR_CURRENT_LIMIT_BEHAVIOR
- NIDCPOWER_ATTR_CURRENT_LIMIT_AUTORANGE
- NIDCPOWER_ATTR_CURRENT_LEVEL_AUTORANGE
- NIDCPOWER_ATTR_VOLTAGE_LIMIT_AUTORANGE
- NIDCPOWER_ATTR_AUTORANGE

## enums.py

Following enums were defined :
- PowerLineFrequencies
- In 'OutputStates' : Following were added
    - NIDCPOWER_VAL_OUTPUT_OVER_VOLTAGE
    - NIDCPOWER_VAL_OUTPUT_OVER_CURRENT
    - NIDCPOWER_VAL_OUTPUT_UNREGULATED
- In 'PowerAllocationMode' : Following were renamed
    - NIDCPOWER_VAL_POWER_ALLOCATION_MODE_DISABLED to NIDCPOWER_VAL_DISABLED
    - NIDCPOWER_VAL_POWER_ALLOCATION_MODE_AUTOMATIC to NIDCPOWER_VAL_AUTOMATIC
    - NIDCPOWER_VAL_POWER_ALLOCATION_MODE_MANUAL to NIDCPOWER_VAL_MANUAL

# Changes in metadata from the base metadata

## functions.py

The Following calibration functions were removed from the metadata :
- ChangeExtCalPassword
- GetCalUserDefinedInfoMaxSize
- SetCalUserDefinedInfo
- GetCalUserDefinedInfo
- InitExtCal
- CloseExtCal
- CalAdjustVoltageLevel
- CalAdjustVoltageMeasurement
- CalAdjustCurrentLimit
- CalAdjustCurrentMeasurement
- CalAdjustOutputResistance
- CalAdjustResidualVoltageOffset
- CalAdjustResidualCurrentOffset
- ConnectInternalReference
- CalAdjustInternalReference

The following functions were tagged as 'codegen_method':'CustomCode':
- MeasureMultiple

For MeasureMultiple function, the value field 'size':'number_of_channels' was added inside parameters 'voltageMeasurements' and 'currentMeasurements'. Also the mechanism was changed to 'mechanism':'custom-code'. Doing this would allow custom implementation of MeasureMultiple API.

The following functions were tagged with 'init_method': True, to ensure their generated service handler registers the new session with the session_repository:
- InitializeWithIndependentChannels
- InitializeWithChannels

The following functions were tagged with their corresponding c_names:
- reset
- self_test
- revision_query
- ConfigureOVP
- error_message
- error_query

The following function, not originally in the base metadata, was newly added from nimi-python metadata:
- `ParseChannelCount`

The following function was tagged with `'codegen_method': 'private'`, because this API is not exposed in `nidcpower.h`.
- `ParseChannelCount`

`enum` tag was added to parameters on following functions.
- `edge` parameter in `ConfigureDigitalEdgeMeasureTriggerWithChannels`
- `edge` parameter in `ConfigureDigitalEdgePulseTriggerWithChannels`
- `edge` parameter in `ConfigureDigitalEdgeSequenceAdvanceTriggerWithChannels`
- `edge` parameter in `ConfigureDigitalEdgeShutdownTriggerWithChannels`
- `edge` parameter in `ConfigureDigitalEdgeSourceTriggerWithChannels`
- `edge` parameter in `ConfigureDigitalEdgeStartTriggerWithChannels`
- `sourceMode` parameter in `ConfigureSourceModeWithChannels`
- `signal` parameter in `ExportSignalWithChannels`
- `trigger` parameter in `SendSoftwareEdgeTriggerWithChannels`
- `eventId` parameter in `WaitForEventWithChannels`
- `behavior` parameter in `ConfigureCurrentLimit`
- `edge` parameter in `ConfigureDigitalEdgeMeasureTrigger`
- `edge` parameter in `ConfigureDigitalEdgePulseTrigger`
- `edge` parameter in `ConfigureDigitalEdgeSequenceAdvanceTrigger`
- `edge` parameter in `ConfigureDigitalEdgeSourceTrigger`
- `edge` parameter in `ConfigureDigitalEdgeStartTrigger`
- `function` parameter in `ConfigureOutputFunction`
- `sense` parameter in `ConfigureSense`
- `sourceMode` parameter in `ConfigureSourceMode`
- `trigger` parameter in `SendSoftwareEdgeTrigger`
- `eventId` parameter in `WaitForEvent`
- `powerlineFrequency` parameter in `ConfigurePowerLineFrequency`
