# These dictionaries are applied to the generated enums dictionary at build time
# Any changes to the API should be made here. enums.py is code generated

enums_override_metadata = {}

enums_validation_suppressions = {
    "CouplingTypes": [
        "ENUMS_SHOULD_BE_USED"
    ],  # Bitfield version of Coupling1 and Coupling2, used by nidaqmx-python
    "DAQmxErrors": ["ENUMS_SHOULD_BE_USED"],  # Used by nidaqmx-python
    "DAQmxWarnings": ["ENUMS_SHOULD_BE_USED"],  # Used by nidaqmx-python
    "FillMode": ["ENUMS_SHOULD_BE_USED"],  # Same as GroupBy
    "Impedance1": [
        "ENUMS_SHOULD_BE_USED"
    ],  # Should be a mapped enum, but grpc-device did not support those when this was added and adding it now would break compatibility
    "Save": ["ENUMS_SHOULD_BE_USED"],  # Same as SaveOptions
    "SignalModifiers": ["ENUMS_SHOULD_BE_USED"],  # Same as InvertPolarity
    "TaskMode": ["ENUMS_SHOULD_BE_USED"],  # Same as TaskControlAction
    "TermCfg": [
        "ENUMS_SHOULD_BE_USED"
    ],  # Bitfield version of InputTermCfg, InputTermCfg2, etc., used by nidaqmx-python
    "TriggerUsageTypes": [
        "ENUMS_SHOULD_BE_USED"
    ],  # Bitfield version of TriggerType4, etc., used by nidaqmx-python
    "WDTTaskAction": ["ENUMS_SHOULD_BE_USED"],  # Same as WatchdogControlAction
}
