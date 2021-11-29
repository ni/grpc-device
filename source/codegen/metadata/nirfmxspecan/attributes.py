attributes = {
    1048577: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the expected carrier frequency of the RF signal that needs to be acquired. This value is expressed in Hz. The signal analyzer tunes to this frequency.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default of this attribute is hardware dependent.\n \nGet Function: RFmxSpecAn_GetCenterFrequency\n Set Function: RFmxSpecAn_SetCenterFrequency\n'
        },
        'name': 'CENTER_FREQUENCY',
        'type': 'float64'
    },
    1048578: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the reference level which represents the maximum expected power of the RF input signal. This value is configured in dBm for RF devices and as Vpk-pk for baseband devices.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.        \n\nThe default of this attribute is hardware dependent.\n \nGet Function: RFmxSpecAn_GetReferenceLevel\n Set Function: RFmxSpecAn_SetReferenceLevel\n'
        },
        'name': 'REFERENCE_LEVEL',
        'type': 'float64'
    },
    1048579: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the attenuation of a switch (or cable) connected to the RF IN connector of the signal analyzer. This value is expressed in dB. For more information about attenuation, refer to the Attenuation and Signal Levels topic for your device in the NI RF Vector Signal Analyzers Help.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.        \n\nThe default value is 0.\n \nGet Function: RFmxSpecAn_GetExternalAttenuation\n Set Function: RFmxSpecAn_SetExternalAttenuation\n'
        },
        'name': 'EXTERNAL_ATTENUATION',
        'type': 'float64'
    },
    1048580: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the trigger type.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.        \n\nThe default value is None.\n \nGet Function: RFmxSpecAn_GetTriggerType\n Set Function: RFmxSpecAn_SetTriggerType\n'
        },
        'enum': 'TriggerType',
        'name': 'TRIGGER_TYPE',
        'type': 'int32'
    },
    1048581: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the source terminal for the digital edge trigger. This attribute is used only when you set the RFMXSPECAN_ATTR_TRIGGER_TYPE attribute to RFMXSPECAN_VAL_TRIGGER_TYPE_DIGITAL_EDGE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.        \n\nThe default of this attribute is hardware dependent.\n \nGet Function: RFmxSpecAn_GetDigitalEdgeTriggerSource\n Set Function: RFmxSpecAn_SetDigitalEdgeTriggerSource\n'
        },
        'enum': 'DigitalEdgeTriggerSource',
        'name': 'DIGITAL_EDGE_TRIGGER_SOURCE',
        'type': 'char[]'
    },
    1048582: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the active edge for the trigger. This attribute is used only when you set the RFMXSPECAN_ATTR_TRIGGER_TYPE attribute to RFMXSPECAN_VAL_TRIGGER_TYPE_DIGITAL_EDGE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.        \n\nThe default value is Rising Edge.\n \nGet Function: RFmxSpecAn_GetDigitalEdgeTriggerEdge\n Set Function: RFmxSpecAn_SetDigitalEdgeTriggerEdge\n'
        },
        'enum': 'DigitalEdgeTriggerEdge',
        'name': 'DIGITAL_EDGE_TRIGGER_EDGE',
        'type': 'int32'
    },
    1048583: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the channel from which the device monitors the trigger. This attribute is used only when you set the RFMXSPECAN_ATTR_TRIGGER_TYPE attribute to RFMXSPECAN_VAL_TRIGGER_TYPE_IQ_POWER_EDGE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default of this attribute is hardware dependent.\n \nGet Function: RFmxSpecAn_GetIQPowerEdgeTriggerSource\n Set Function: RFmxSpecAn_SetIQPowerEdgeTriggerSource\n'
        },
        'name': 'IQ_POWER_EDGE_TRIGGER_SOURCE',
        'type': 'char[]'
    },
    1048584: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the power level at which the device triggers. This value is expressed in dB when you set the RFMXSPECAN_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE attribute to RFMXSPECAN_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE and is expressed in dBm when you set the RFMXSPECAN_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE attribute to RFMXSPECAN_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_ABSOLUTE. The device asserts the trigger when the signal exceeds the level specified by  the value of this attribute, taking into consideration the specified slope. This attribute is used only when you set the RFMXSPECAN_ATTR_TRIGGER_TYPE attribute to RFMXSPECAN_VAL_TRIGGER_TYPE_IQ_POWER_EDGE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector String topic for information about the string syntax for named signals.\n \nThe default of this attribute is hardware dependent.\n \nGet Function: RFmxSpecAn_GetIQPowerEdgeTriggerLevel\n Set Function: RFmxSpecAn_SetIQPowerEdgeTriggerLevel\n'
        },
        'name': 'IQ_POWER_EDGE_TRIGGER_LEVEL',
        'type': 'float64'
    },
    1048585: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the device asserts the trigger when the signal power is rising or when it is falling. The device asserts the trigger when the signal power exceeds the specified level with the slope you specify. This attribute is used only when you set the RFMXSPECAN_ATTR_TRIGGER_TYPE  attribute to RFMXSPECAN_VAL_TRIGGER_TYPE_IQ_POWER_EDGE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.        \n\nThe default value is Rising Slope.\n \nGet Function: RFmxSpecAn_GetIQPowerEdgeTriggerSlope\n Set Function: RFmxSpecAn_SetIQPowerEdgeTriggerSlope\n'
        },
        'enum': 'IQPowerEdgeTriggerSlope',
        'name': 'IQ_POWER_EDGE_TRIGGER_SLOPE',
        'type': 'int32'
    },
    1048586: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the trigger delay time. This value is expressed in seconds.\n \nIf the delay is negative, the measurement acquires pre-trigger samples. If the delay is positive, the measurement acquires post-trigger samples.         \n\nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.        \n\nThe default value is 0.\n \nGet Function: RFmxSpecAn_GetTriggerDelay\n Set Function: RFmxSpecAn_SetTriggerDelay\n'
        },
        'name': 'TRIGGER_DELAY',
        'type': 'float64'
    },
    1048587: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the measurement computes the minimum quiet time used for triggering.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_MANUAL.\n \nGet Function: RFmxSpecAn_GetTriggerMinimumQuietTimeMode\n Set Function: RFmxSpecAn_SetTriggerMinimumQuietTimeMode\n'
        },
        'enum': 'TriggerMinimumQuietTimeMode',
        'name': 'TRIGGER_MINIMUM_QUIET_TIME_MODE',
        'type': 'int32'
    },
    1048588: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the time duration for which the signal must be quiet before the signal analyzer arms the I/Q power edge trigger. This value is expressed in seconds. If you set the RFMXSPECAN_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE attribute to RFMXSPECAN_VAL_IQ_POWER_EDGE_RISING_SLOPE, the signal is quiet below the trigger level.  If you set the RFMXSPECAN_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE attribute to RFMXSPECAN_VAL_IQ_POWER_EDGE_FALLING_SLOPE, the signal is quiet above the trigger level.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.        \n\nThe default of this attribute is hardware dependent.\n \nGet Function: RFmxSpecAn_GetTriggerMinimumQuietTimeDuration\n Set Function: RFmxSpecAn_SetTriggerMinimumQuietTimeDuration\n'
        },
        'name': 'TRIGGER_MINIMUM_QUIET_TIME_DURATION',
        'type': 'float64'
    },
    1048589: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the initial reference level, in dBm, which the RFmxSpecAn_AutoLevel function uses to estimate the peak power of the input signal.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 30.\n \nGet Function: RFmxSpecAn_GetAutoLevelInitialReferenceLevel\n Set Function: RFmxSpecAn_SetAutoLevelInitialReferenceLevel\n'
        },
        'name': 'AUTO_LEVEL_INITIAL_REFERENCE_LEVEL',
        'type': 'float64'
    },
    1048590: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the set of attributes that are considered by RFmx in the locked signal configuration state.\n \nIf your test system performs the same measurement at different selected ports, multiple frequencies and/or power levels repeatedly, enabling this attribute will help achieve faster measurements. When you set this attribute to a value other than Disabled, the RFmx driver will use an optimized code path and skip some checks. Because RFmx skips some checks when you use this attribute, you need to be aware of the limitations of this feature, which are listed in the Limitations of the RFMXSPECAN_ATTR_LIMITED_CONFIGURATION_CHANGE Attribute topic.         \n\nYou can also use this attribute to lock a specific instrument configuration for a signal so that every time that you initiate the signal, RFmx applies the RFmxInstr attributes from a locked configuration.        \n\nNI recommends you use this attribute in conjunction with named signal configurations. Create named signal configurations for each measurement configuration in your test program and set this attribute to a value other than Disabled for one or more of the named signal configurations. This allows RFmx to precompute the acquisition settings for your measurement configurations and re-use the precomputed settings each time you initiate the measurement. You do not need to use this attribute if you create named signals for all the measurement configurations in your test program during test sequence initialization and do not change any RFInstr or personality attributes while testing each device under test. RFmx automatically optimizes that use case.        \n\nSpecify the named signal configuration you are setting this attribute in the selector string input.  You do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector String topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_LIMITED_CONFIGURATION_CHANGE_DISABLED.\n \nGet Function: RFmxSpecAn_GetLimitedConfigurationChange\n Set Function: RFmxSpecAn_SetLimitedConfigurationChange\n'
        },
        'enum': 'LimitedConfigurationChange',
        'name': 'LIMITED_CONFIGURATION_CHANGE',
        'type': 'int32'
    },
    1052663: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the time offset from the start of the step for which the measurements are computed. This value is expressed in seconds. This attribute is valid only when you set the RFMXSPECAN_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE attribute to RFMXSPECAN_VAL_TIMER_EVENT_STR.\n \nYou need to use a selector string to configure or read this attribute for the list step instance.\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_GetListStepTimerOffset\n Set Function: RFmxSpecAn_SetListStepTimerOffset\n'
        },
        'name': 'LIST_STEP_TIMER_OFFSET',
        'type': 'float64'
    },
    1052664: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of active steps in a list.\n \nYou need to use a selector string to configure or read this attribute for the list instance.\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_GetNumberOfSteps\n Set Function: RFmxSpecAn_SetNumberOfSteps\n'
        },
        'name': 'NUMBER_OF_STEPS',
        'type': 'int32'
    },
    1052665: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the duration of a given list step. This value is expressed in seconds.\n \nYou need to use a selector string to configure or read this attribute for the list step instance.\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_GetListStepTimerDuration\n Set Function: RFmxSpecAn_SetListStepTimerDuration\n'
        },
        'name': 'LIST_STEP_TIMER_DURATION',
        'type': 'float64'
    },
    1052668: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the margin RFmx adds to the RFMXSPECAN_ATTR_REFERENCE_LEVEL attribute. The margin avoids clipping and overflow warnings if the input signal exceeds the configured reference level.\n \nRFmx configures the input gain to avoid clipping and associated overflow warnings provided the instantaneous power of the input signal remains within the RFMXSPECAN_ATTR_REFERENCE_LEVEL plus the RFMXSPECAN_ATTR_REFERENCE_LEVEL_HEADROOM. If you know the input power of the signal precisely or previously included the margin in the RFMXSPECAN_ATTR_REFERENCE_LEVEL, you could improve the signal-to-noise  ratio by reducing the RFMXSPECAN_ATTR_REFERENCE_LEVEL_HEADROOM.       \n\nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.      \n\n   Supported devices: PXIe-5668, PXIe-5830/5831/5832/5840/5841.\n \nDefault values\n\nPXIe-5668\t    6 dB\t    \n\nPXIe-5830/5831/5832/5841\t    1 dB\t    \n\nPXIe-5840\t    0 dB\t    \n\n \nGet Function: RFmxSpecAn_GetReferenceLevelHeadroom\n Set Function: RFmxSpecAn_SetReferenceLevelHeadroom\n'
        },
        'name': 'REFERENCE_LEVEL_HEADROOM',
        'type': 'float64'
    },
    1052669: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the instrument port to be configured to acquire a signal. Use RFmxInstr_GetAvailablePorts function to get the valid port names.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n\n Valid values\n\nPXIe-5830\t    if0, if1\t    \n\nPXIe-5831/5832\t    if0, if1, rf(0-1)/port(x), where 0-1 indicates one (0) or two (1) mmRH-5582 connections and x is the port number on the mmRH-5582 front panel\t    \n\nOther devices\t    '' (empty string)\t    \n\n \nDefault values\n\nPXIe-5830/5831/5832\t    if1\t    \n\nOther devices\t    '' (empty string)\t    \n\n \nGet Function: RFmxSpecAn_GetSelectedPorts\n Set Function: RFmxSpecAn_SetSelectedPorts\n"
        },
        'name': 'SELECTED_PORTS',
        'type': 'char[]'
    },
    1052671: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the reference for the RFMXSPECAN_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL attribute. The RFMXSPECAN_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE attribute is used only when you set the RFMXSPECAN_ATTR_TRIGGER_TYPE attribute to RFMXSPECAN_VAL_TRIGGER_TYPE_IQ_POWER_EDGE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector String topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_ABSOLUTE.\n \nGet Function: RFmxSpecAn_GetIQPowerEdgeTriggerLevelType\n Set Function: RFmxSpecAn_SetIQPowerEdgeTriggerLevelType\n'
        },
        'enum': 'IQPowerEdgeTriggerLevelType',
        'name': 'IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE',
        'type': 'int32'
    },
    1052672: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the ACP measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_ACPGetMeasurementEnabled\n Set Function: RFmxSpecAn_ACPSetMeasurementEnabled\n'
        },
        'name': 'ACP_MEASUREMENT_ENABLED',
        'type': 'int32'
    },
    1052674: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of carriers.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_ACPGetNumberOfCarriers\n Set Function: RFmxSpecAn_ACPSetNumberOfCarriers\n'
        },
        'name': 'ACP_NUMBER_OF_CARRIERS',
        'type': 'int32'
    },
    1052675: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies whether to consider the carrier power as part of the total carrier power measurement.\n \n\n \nUse 'carrier(n)' as the selector string to configure or read this attribute.        \n\nThe default value is RFMXSPECAN_VAL_ACP_CARRIER_MODE_ACTIVE.\n \nGet Function: RFmxSpecAn_ACPGetCarrierMode\n Set Function: RFmxSpecAn_ACPSetCarrierMode\n"
        },
        'enum': 'AcpCarrierMode',
        'name': 'ACP_CARRIER_MODE',
        'type': 'int32'
    },
    1052676: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the center frequency of the carrier, relative to the RF center frequency. This value is expressed in Hz.        \n\nUse 'carrier(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_ACPGetCarrierFrequency\n Set Function: RFmxSpecAn_ACPSetCarrierFrequency\n"
        },
        'name': 'ACP_CARRIER_FREQUENCY',
        'type': 'float64'
    },
    1052677: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the frequency range over which the measurement integrates the carrier power. This value is expressed in Hz.        \n\nUse 'carrier(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 1 MHz.\n \nGet Function: RFmxSpecAn_ACPGetCarrierIntegrationBandwidth\n Set Function: RFmxSpecAn_ACPSetCarrierIntegrationBandwidth\n"
        },
        'name': 'ACP_CARRIER_INTEGRATION_BANDWIDTH',
        'type': 'float64'
    },
    1052678: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies whether to apply the root-raised-cosine (RRC) filter on the acquired carrier channel before measuring the carrier channel power.        \n\nUse 'carrier(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_ACP_CARRIER_RRC_FILTER_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_ACPGetCarrierRRCFilterEnabled\n Set Function: RFmxSpecAn_ACPSetCarrierRRCFilterEnabled\n"
        },
        'enum': 'AcpCarrierRrcFilterEnabled',
        'name': 'ACP_CARRIER_RRC_FILTER_ENABLED',
        'type': 'int32'
    },
    1052679: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the roll-off factor for the root-raised-cosine (RRC) filter.        \n\nUse 'carrier(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 0.1.\n \nGet Function: RFmxSpecAn_ACPGetCarrierRRCFilterAlpha\n Set Function: RFmxSpecAn_ACPSetCarrierRRCFilterAlpha\n"
        },
        'name': 'ACP_CARRIER_RRC_FILTER_ALPHA',
        'type': 'float64'
    },
    1052680: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of offset channels.        \n\nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \n\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_ACPGetNumberOfOffsets\n Set Function: RFmxSpecAn_ACPSetNumberOfOffsets\n'
        },
        'name': 'ACP_NUMBER_OF_OFFSETS',
        'type': 'int32'
    },
    1052681: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies whether to enable the offset channel for ACP measurement.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_ACP_OFFSET_FREQUENCY_ENABLED_TRUE.\n \nGet Function: RFmxSpecAn_ACPGetOffsetEnabled\n Set Function: RFmxSpecAn_ACPSetOffsetEnabled\n"
        },
        'enum': 'AcpOffsetEnabled',
        'name': 'ACP_OFFSET_ENABLED',
        'type': 'int32'
    },
    1052682: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the center or edge frequency of the offset channel, relative to the center frequency of the closest carrier as determined by the RFMXSPECAN_ATTR_ACP_OFFSET_FREQUENCY_DEFINITION attribute. This value is expressed in Hz. The sign of offset frequency is ignored and the RFMXSPECAN_ATTR_ACP_OFFSET_SIDEBAND attribute determines whether the upper, lower, or both offsets are measured.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 1 MHz.\n \nGet Function: RFmxSpecAn_ACPGetOffsetFrequency\n Set Function: RFmxSpecAn_ACPSetOffsetFrequency\n"
        },
        'name': 'ACP_OFFSET_FREQUENCY',
        'type': 'float64'
    },
    1052683: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies whether the offset channel is present on one side, or on both sides of the carrier.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_ACP_OFFSET_SIDEBAND_BOTH.\n \nGet Function: RFmxSpecAn_ACPGetOffsetSideband\n Set Function: RFmxSpecAn_ACPSetOffsetSideband\n"
        },
        'enum': 'AcpOffsetSideband',
        'name': 'ACP_OFFSET_SIDEBAND',
        'type': 'int32'
    },
    1052684: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the carrier to be used as power reference to measure the offset channel relative power. The offset channel power is measured only if you set the RFMXSPECAN_ATTR_ACP_CARRIER_MODE attribute of the reference carrier to RFMXSPECAN_VAL_ACP_CARRIER_MODE_ACTIVE.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_ACP_OFFSET_POWER_REFERENCE_CARRIER_CLOSEST.\n \nGet Function: RFmxSpecAn_ACPGetOffsetPowerReferenceCarrier\n Set Function: RFmxSpecAn_ACPSetOffsetPowerReferenceCarrier\n"
        },
        'enum': 'AcpOffsetPowerReferenceCarrier',
        'name': 'ACP_OFFSET_POWER_REFERENCE_CARRIER',
        'type': 'int32'
    },
    1052685: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the index of the carrier to be used as the reference carrier. The power measured in this carrier is used as the power reference for measuring the offset channel relative power, when you set the RFMXSPECAN_ATTR_ACP_OFFSET_POWER_REFERENCE_CARRIER attribute to RFMXSPECAN_VAL_ACP_OFFSET_POWER_REFERENCE_CARRIER_SPECIFIC.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_ACPGetOffsetPowerReferenceSpecific\n Set Function: RFmxSpecAn_ACPSetOffsetPowerReferenceSpecific\n"
        },
        'name': 'ACP_OFFSET_POWER_REFERENCE_SPECIFIC',
        'type': 'int32'
    },
    1052686: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the frequency range, over which the measurement integrates the offset channel power. This value is expressed in Hz.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 1 MHz.\n \nGet Function: RFmxSpecAn_ACPGetOffsetIntegrationBandwidth\n Set Function: RFmxSpecAn_ACPSetOffsetIntegrationBandwidth\n"
        },
        'name': 'ACP_OFFSET_INTEGRATION_BANDWIDTH',
        'type': 'float64'
    },
    1052687: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the attenuation relative to the external attenuation specified by the RFMXSPECAN_ATTR_EXTERNAL_ATTENUATION attribute. This value is expressed in dB. Use the ACP Offset Rel Attn attribute to compensate for variations in external attenuation when the offset channels are spread wide in frequency.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_ACPGetOffsetRelativeAttenuation\n Set Function: RFmxSpecAn_ACPSetOffsetRelativeAttenuation\n"
        },
        'name': 'ACP_OFFSET_RELATIVE_ATTENUATION',
        'type': 'float64'
    },
    1052688: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies whether to apply the root-raised-cosine (RRC) filter on the acquired offset channel before measuring the offset channel power.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_ACP_OFFSET_RRC_FILTER_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_ACPGetOffsetRRCFilterEnabled\n Set Function: RFmxSpecAn_ACPSetOffsetRRCFilterEnabled\n"
        },
        'enum': 'AcpOffsetRrcFilterEnabled',
        'name': 'ACP_OFFSET_RRC_FILTER_ENABLED',
        'type': 'int32'
    },
    1052689: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the roll-off factor for the root-raised-cosine (RRC) filter.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 0.1.\n \nGet Function: RFmxSpecAn_ACPGetOffsetRRCFilterAlpha\n Set Function: RFmxSpecAn_ACPSetOffsetRRCFilterAlpha\n"
        },
        'name': 'ACP_OFFSET_RRC_FILTER_ALPHA',
        'type': 'float64'
    },
    1052690: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the method for performing the ACP measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_ACP_MEASUREMENT_METHOD_NORMAL.\n \nGet Function: RFmxSpecAn_ACPGetMeasurementMethod\n Set Function: RFmxSpecAn_ACPSetMeasurementMethod\n'
        },
        'enum': 'AcpMeasurementMethod',
        'name': 'ACP_MEASUREMENT_METHOD',
        'type': 'int32'
    },
    1052691: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the units for the absolute power.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_ACP_POWER_UNITS_DBM_PER_HZ.\n \nGet Function: RFmxSpecAn_ACPGetPowerUnits\n Set Function: RFmxSpecAn_ACPSetPowerUnits\n'
        },
        'enum': 'AcpPowerUnits',
        'name': 'ACP_POWER_UNITS',
        'type': 'int32'
    },
    1052692: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum number of threads used for parallelism for adjacent channel power  (ACP) measurement.\n \nThe number of threads can range from 1 to the number of physical cores. The number of threads you set may not be used in calculations. The actual number of threads used depends on the problem size, system resources, data availability, and other considerations.         \n\nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_ACPGetNumberOfAnalysisThreads\n Set Function: RFmxSpecAn_ACPSetNumberOfAnalysisThreads\n'
        },
        'name': 'ACP_NUMBER_OF_ANALYSIS_THREADS',
        'type': 'int32'
    },
    1052693: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of acquisitions used for averaging when you set the RFMXSPECAN_ATTR_ACP_AVERAGING_ENABLED attribute to RFMXSPECAN_VAL_ACP_AVERAGING_ENABLED_TRUE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10.\n \nGet Function: RFmxSpecAn_ACPGetAveragingCount\n Set Function: RFmxSpecAn_ACPSetAveragingCount\n'
        },
        'name': 'ACP_AVERAGING_COUNT',
        'type': 'int32'
    },
    1052694: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable averaging for the ACP measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_ACP_AVERAGING_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_ACPGetAveragingEnabled\n Set Function: RFmxSpecAn_ACPSetAveragingEnabled\n'
        },
        'enum': 'AcpAveragingEnabled',
        'name': 'ACP_AVERAGING_ENABLED',
        'type': 'int32'
    },
    1052696: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the averaging type for averaging multiple spectrum acquisitions. The averaged spectrum is used for ACP measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_ACP_AVERAGING_TYPE_RMS.\n \nGet Function: RFmxSpecAn_ACPGetAveragingType\n Set Function: RFmxSpecAn_ACPSetAveragingType\n'
        },
        'enum': 'AcpAveragingType',
        'name': 'ACP_AVERAGING_TYPE',
        'type': 'int32'
    },
    1052697: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the FFT window type to use to reduce spectral leakage.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_ACP_FFT_WINDOW_FLAT_TOP.\n \nGet Function: RFmxSpecAn_ACPGetFFTWindow\n Set Function: RFmxSpecAn_ACPSetFFTWindow\n'
        },
        'enum': 'AcpFftWindow',
        'name': 'ACP_FFT_WINDOW',
        'type': 'int32'
    },
    1052698: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the factor by which the time-domain waveform is zero-padded before fast Fourier transform (FFT). The FFT size is given by the following formula:        \n\nwaveform size * padding        \n\nThis attribute is used only when the acquisition span is less than the device instantaneous bandwidth of the device.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is -1.\n \nGet Function: RFmxSpecAn_ACPGetFFTPadding\n Set Function: RFmxSpecAn_ACPSetFFTPadding\n'
        },
        'name': 'ACP_FFT_PADDING',
        'type': 'float64'
    },
    1052699: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the measurement computes the resolution bandwidth (RBW).\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_ACP_RBW_AUTO_TRUE.\n \nGet Function: RFmxSpecAn_ACPGetRBWFilterAutoBandwidth\n Set Function: RFmxSpecAn_ACPSetRBWFilterAutoBandwidth\n'
        },
        'enum': 'AcpRbwAutoBandwidth',
        'name': 'ACP_RBW_FILTER_AUTO_BANDWIDTH',
        'type': 'int32'
    },
    1052700: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the bandwidth of the resolution bandwidth (RBW) filter used to sweep the acquired signal, when you set the RFMXSPECAN_ATTR_ACP_RBW_FILTER_AUTO_BANDWIDTH attribute to RFMXSPECAN_VAL_ACP_RBW_AUTO_FALSE. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10 kHz.\n \nGet Function: RFmxSpecAn_ACPGetRBWFilterBandwidth\n Set Function: RFmxSpecAn_ACPSetRBWFilterBandwidth\n'
        },
        'name': 'ACP_RBW_FILTER_BANDWIDTH',
        'type': 'float64'
    },
    1052701: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the shape of the digital resolution bandwidth (RBW) filter.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_ACP_RBW_FILTER_TYPE_GAUSSIAN.\n \nGet Function: RFmxSpecAn_ACPGetRBWFilterType\n Set Function: RFmxSpecAn_ACPSetRBWFilterType\n'
        },
        'enum': 'AcpRbwFilterType',
        'name': 'ACP_RBW_FILTER_TYPE',
        'type': 'int32'
    },
    1052702: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the measurement computes the sweep time.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_ACP_SWEEP_TIME_AUTO_TRUE.\n \nGet Function: RFmxSpecAn_ACPGetSweepTimeAuto\n Set Function: RFmxSpecAn_ACPSetSweepTimeAuto\n'
        },
        'enum': 'AcpSweepTimeAuto',
        'name': 'ACP_SWEEP_TIME_AUTO',
        'type': 'int32'
    },
    1052703: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the sweep time when you set the RFMXSPECAN_ATTR_ACP_SWEEP_TIME_AUTO attribute to RFMXSPECAN_VAL_ACP_SWEEP_TIME_AUTO_FALSE. This value is expressed in seconds.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.001.\n \nGet Function: RFmxSpecAn_ACPGetSweepTimeInterval\n Set Function: RFmxSpecAn_ACPSetSweepTimeInterval\n'
        },
        'name': 'ACP_SWEEP_TIME_INTERVAL',
        'type': 'float64'
    },
    1052704: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether RFmx compensates for the instrument noise while performing the measurement when you set the RFMXSPECAN_ATTR_ACP_NOISE_CALIBRATION_MODE attribute to RFMXSPECAN_VAL_ACP_NOISE_CALIBRATION_MODE_AUTO, or when you set the RFMXSPECAN_ATTR_ACP_NOISE_CALIBRATION_MODE attribute to RFMXSPECAN_VAL_ACP_NOISE_CALIBRATION_MODE_MANUAL and RFMXSPECAN_ATTR_ACP_MEASUREMENT_MODE to RFMXSPECAN_VAL_ACP_MEASUREMENT_MODE_MEASURE. Refer to the Noise Compensation Algorithm topic for more information.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_ACP_NOISE_COMPENSATION_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_ACPGetNoiseCompensationEnabled\n Set Function: RFmxSpecAn_ACPSetNoiseCompensationEnabled\n'
        },
        'enum': 'AcpNoiseCompensationEnabled',
        'name': 'ACP_NOISE_COMPENSATION_ENABLED',
        'type': 'int32'
    },
    1052705: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the traces to be stored and retrieved after performing the ACP measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_ACPGetAllTracesEnabled\n Set Function: RFmxSpecAn_ACPSetAllTracesEnabled\n'
        },
        'name': 'ACP_ALL_TRACES_ENABLED',
        'type': 'int32'
    },
    1052706: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the total integrated power, in dBm, of all the active carriers measured when you set the RFMXSPECAN_ATTR_ACP_POWER_UNITS attribute to RFMXSPECAN_VAL_ACP_POWER_UNITS_DBM.         \n\nReturns the power spectral density, in dBm/Hz, based on the power in all the active carriers measured when you set the RFMXSPECAN_ATTR_ACP_POWER_UNITS attribute to RFMXSPECAN_VAL_ACP_POWER_UNITS_DBM_PER_HZ.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_ACPGetResultsTotalCarrierPower\n'
        },
        'name': 'ACP_RESULTS_TOTAL_CARRIER_POWER',
        'type': 'float64'
    },
    1052707: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the frequency bin spacing of the spectrum acquired by the measurement. This value is expressed in Hz.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_ACPGetResultsFrequencyResolution\n'
        },
        'name': 'ACP_RESULTS_FREQUENCY_RESOLUTION',
        'type': 'float64'
    },
    1052708: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the center frequency of the carrier relative to the Center Frequency attribute. This value is expressed in Hz.        \n\nUse 'carrier(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_ACPGetResultsCarrierFrequency\n"
        },
        'name': 'ACP_RESULTS_CARRIER_FREQUENCY',
        'type': 'float64'
    },
    1052709: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the frequency range, over which the measurement integrates the carrier power. This value is expressed in Hz.        \n\nUse 'carrier(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_ACPGetResultsCarrierIntegrationBandwidth\n"
        },
        'name': 'ACP_RESULTS_CARRIER_INTEGRATION_BANDWIDTH',
        'type': 'float64'
    },
    1052710: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the measured carrier power.        \n\nUse 'carrier(n)' as the selector string to read this result.\n \nThe carrier power is reported in dBm when you set the RFMXSPECAN_ATTR_ACP_POWER_UNITS attribute to RFMXSPECAN_VAL_ACP_POWER_UNITS_DBM, and in dBm/Hz when you set the RFMXSPECAN_ATTR_ACP_POWER_UNITS attribute to RFMXSPECAN_VAL_ACP_POWER_UNITS_DBM_PER_HZ.\n \nGet Function: RFmxSpecAn_ACPGetResultsCarrierAbsolutePower\n"
        },
        'name': 'ACP_RESULTS_CARRIER_ABSOLUTE_POWER',
        'type': 'float64'
    },
    1052711: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the carrier power measured relative to the total carrier power of all active carriers. This value is expressed in dB.        \n\nUse 'carrier(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_ACPGetResultsCarrierTotalRelativePower\n"
        },
        'name': 'ACP_RESULTS_CARRIER_TOTAL_RELATIVE_POWER',
        'type': 'float64'
    },
    1052712: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the index of the carrier used as a reference to define the center frequency of the lower (negative) offset channel. Lower offset channels are channels that are to the left of the carrier.        \n\nUse 'offset(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_ACPGetResultsLowerOffsetFrequencyReferenceCarrier\n"
        },
        'name': 'ACP_RESULTS_LOWER_OFFSET_FREQUENCY_REFERENCE_CARRIER',
        'type': 'int32'
    },
    1052713: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the center frequency of the lower offset channel relative to the center frequency of the closest carrier. The offset frequency has a negative value.        \n\nUse 'offset(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_ACPGetResultsLowerOffsetFrequency\n"
        },
        'name': 'ACP_RESULTS_LOWER_OFFSET_FREQUENCY',
        'type': 'float64'
    },
    1052714: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the integration bandwidth used to measure the power in the lower offset channel.        \n\nUse 'offset(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_ACPGetResultsLowerOffsetIntegrationBandwidth\n"
        },
        'name': 'ACP_RESULTS_LOWER_OFFSET_INTEGRATION_BANDWIDTH',
        'type': 'float64'
    },
    1052715: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the index of the carrier used as the power reference to measure the lower (negative) offset channel relative power.\n \nA value of -1 indicates that the total power of all active carriers is used as the reference power. The measurement uses the RFMXSPECAN_ATTR_ACP_OFFSET_POWER_REFERENCE_CARRIER attribute to set the power reference.        \n\nUse 'offset(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_ACPGetResultsLowerOffsetPowerReferenceCarrier\n"
        },
        'name': 'ACP_RESULTS_LOWER_OFFSET_POWER_REFERENCE_CARRIER',
        'type': 'int32'
    },
    1052716: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the lower offset channel power.\n \nThe offset channel power is reported in dBm when you set the RFMXSPECAN_ATTR_ACP_POWER_UNITS attribute to RFMXSPECAN_VAL_ACP_POWER_UNITS_DBM, and in dBm/Hz when you set the RFMXSPECAN_ATTR_ACP_POWER_UNITS attribute to RFMXSPECAN_VAL_ACP_POWER_UNITS_DBM_PER_HZ.        \n\nUse 'offset(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_ACPGetResultsLowerOffsetAbsolutePower\n"
        },
        'name': 'ACP_RESULTS_LOWER_OFFSET_ABSOLUTE_POWER',
        'type': 'float64'
    },
    1052717: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the lower offset channel power measured relative to the integrated power of the power reference carrier. This value is expressed in dB.        \n\nUse 'offset(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_ACPGetResultsLowerOffsetRelativePower\n"
        },
        'name': 'ACP_RESULTS_LOWER_OFFSET_RELATIVE_POWER',
        'type': 'float64'
    },
    1052718: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the index of the carrier used as a reference to define the center frequency of the upper (positive) offset channel. Upper offset channels are channels that are to the right of the carrier.         \n\nUse 'offset(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_ACPGetResultsUpperOffsetFrequencyReferenceCarrier\n"
        },
        'name': 'ACP_RESULTS_UPPER_OFFSET_FREQUENCY_REFERENCE_CARRIER',
        'type': 'int32'
    },
    1052719: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the center frequency of the upper offset channel relative to the center frequency of the closest carrier. The offset frequency has a positive value.        \n\nUse 'offset(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_ACPGetResultsUpperOffsetFrequency\n"
        },
        'name': 'ACP_RESULTS_UPPER_OFFSET_FREQUENCY',
        'type': 'float64'
    },
    1052720: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the integration bandwidth used to measure the power in the upper offset channel.        \n\nUse 'offset(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_ACPGetResultsUpperOffsetIntegrationBandwidth\n"
        },
        'name': 'ACP_RESULTS_UPPER_OFFSET_INTEGRATION_BANDWIDTH',
        'type': 'float64'
    },
    1052721: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the index of the carrier used as the power reference to measure the upper (positive) offset channel relative power.\n \nA value of -1 indicates that the total power of all active carriers is used as the reference power. The measurement uses the RFMXSPECAN_ATTR_ACP_OFFSET_POWER_REFERENCE_CARRIER attribute to set the power reference.        \n\nUse 'offset(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_ACPGetResultsUpperOffsetPowerReferenceCarrier\n"
        },
        'name': 'ACP_RESULTS_UPPER_OFFSET_POWER_REFERENCE_CARRIER',
        'type': 'int32'
    },
    1052722: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the upper offset channel power.\n \nThe offset channel power is reported in dBm when you set the RFMXSPECAN_ATTR_ACP_POWER_UNITS attribute to RFMXSPECAN_VAL_ACP_POWER_UNITS_DBM, and in dBm/Hz when you set the RFMXSPECAN_ATTR_ACP_POWER_UNITS attribute to RFMXSPECAN_VAL_ACP_POWER_UNITS_DBM_PER_HZ.        \n\nUse 'offset(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_ACPGetResultsUpperOffsetAbsolutePower\n"
        },
        'name': 'ACP_RESULTS_UPPER_OFFSET_ABSOLUTE_POWER',
        'type': 'float64'
    },
    1052723: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the upper offset channel power measured relative to the integrated power of the power reference carrier. This value is expressed in dB.        \n\nUse 'offset(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_ACPGetResultsUpperOffsetRelativePower\n"
        },
        'name': 'ACP_RESULTS_UPPER_OFFSET_RELATIVE_POWER',
        'type': 'float64'
    },
    1052724: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the measurement computes an IF output power level offset for the offset channels to improve the dynamic range of the ACP measurement. This attribute is used only if you set the RFMXSPECAN_ATTR_ACP_MEASUREMENT_METHOD attribute to RFMXSPECAN_VAL_ACP_MEASUREMENT_METHOD_DYNAMIC_RANGE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_ACP_IF_OUTPUT_POWER_OFFSET_AUTO_TRUE.\n \nGet Function: RFmxSpecAn_ACPGetIFOutputPowerOffsetAuto\n Set Function: RFmxSpecAn_ACPSetIFOutputPowerOffsetAuto\n'
        },
        'enum': 'AcpIFOutputPowerOffsetAuto',
        'name': 'ACP_IF_OUTPUT_POWER_OFFSET_AUTO',
        'type': 'int32'
    },
    1052725: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the offset by which to adjust the IF output power level for offset channels that are near to the carrier channel to improve the dynamic range. This value is expressed in dB. This attribute is used only if you set the RFMXSPECAN_ATTR_ACP_MEASUREMENT_METHOD attribute to RFMXSPECAN_VAL_ACP_MEASUREMENT_METHOD_DYNAMIC_RANGE and set the RFMXSPECAN_ATTR_ACP_IF_OUTPUT_POWER_OFFSET_AUTO attribute to RFMXSPECAN_VAL_ACP_IF_OUTPUT_POWER_OFFSET_AUTO_FALSE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10 dB.\n \nGet Function: RFmxSpecAn_ACPGetNearIFOutputPowerOffset\n Set Function: RFmxSpecAn_ACPSetNearIFOutputPowerOffset\n'
        },
        'name': 'ACP_NEAR_IF_OUTPUT_POWER_OFFSET',
        'type': 'float64'
    },
    1052726: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the offset by which to adjust the IF output power level for offset channels that are far from the carrier channel to improve the dynamic range. This value is expressed in dB. This attribute is used only if you set the RFMXSPECAN_ATTR_ACP_MEASUREMENT_METHOD attribute to RFMXSPECAN_VAL_ACP_MEASUREMENT_METHOD_DYNAMIC_RANGE and set the RFMXSPECAN_ATTR_ACP_IF_OUTPUT_POWER_OFFSET_AUTO attribute to RFMXSPECAN_VAL_ACP_IF_OUTPUT_POWER_OFFSET_AUTO_FALSE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 20 dB.\n \nGet Function: RFmxSpecAn_ACPGetFarIFOutputPowerOffset\n Set Function: RFmxSpecAn_ACPSetFarIFOutputPowerOffset\n'
        },
        'name': 'ACP_FAR_IF_OUTPUT_POWER_OFFSET',
        'type': 'float64'
    },
    1052727: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the offset frequency definition used to specify the RFMXSPECAN_ATTR_ACP_OFFSET_FREQUENCY attribute.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_ACP_CARRIER_CENTER_TO_OFFSET_CENTER.\n \nGet Function: RFmxSpecAn_ACPGetOffsetFrequencyDefinition\n Set Function: RFmxSpecAn_ACPSetOffsetFrequencyDefinition\n"
        },
        'enum': 'AcpOffsetFrequencyDefinition',
        'name': 'ACP_OFFSET_FREQUENCY_DEFINITION',
        'type': 'int32'
    },
    1052728: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the bandwidth definition which you use to specify the value of the RFMXSPECAN_ATTR_ACP_RBW_FILTER_BANDWIDTH attribute.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_ACP_RBW_FILTER_BANDWIDTH_DEFINITION_3DB.\n \nGet Function: RFmxSpecAn_ACPGetRBWFilterBandwidthDefinition\n Set Function: RFmxSpecAn_ACPSetRBWFilterBandwidthDefinition\n'
        },
        'enum': 'AcpRbwFilterBandwidthDefinition',
        'name': 'ACP_RBW_FILTER_BANDWIDTH_DEFINITION',
        'type': 'int32'
    },
    1052729: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the amplitude of the frequency bins, used in the measurement, is corrected for external attenuation at the RF center frequency, or at the individual frequency bins. Use the RFmxInstr_CfgExternalAttenuationTable function to configure the external attenuation table.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_ACP_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY.\n \nGet Function: RFmxSpecAn_ACPGetAmplitudeCorrectionType\n Set Function: RFmxSpecAn_ACPSetAmplitudeCorrectionType\n'
        },
        'enum': 'AcpAmplitudeCorrectionType',
        'name': 'ACP_AMPLITUDE_CORRECTION_TYPE',
        'type': 'int32'
    },
    1052730: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the FFT size when you set the         RFMXSPECAN_ATTR_ACP_MEASUREMENT_METHOD attribute to RFMXSPECAN_VAL_ACP_MEASUREMENT_METHOD_SEQUENTIAL_FFT.\n \n\n \nThe default value is 512.\n \nGet Function: RFmxSpecAn_ACPGetSequentialFFTSize\n Set Function: RFmxSpecAn_ACPSetSequentialFFTSize\n'
        },
        'name': 'ACP_SEQUENTIAL_FFT_SIZE',
        'type': 'int32'
    },
    1052731: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the overlap mode when you set the RFMXSPECAN_ATTR_ACP_MEASUREMENT_METHOD attribute to RFMXSPECAN_VAL_ACP_MEASUREMENT_METHOD_SEQUENTIAL_FFT.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_ACP_FFT_OVERLAP_MODE_DISABLED.\n \nGet Function: RFmxSpecAn_ACPGetFFTOverlapMode\n Set Function: RFmxSpecAn_ACPSetFFTOverlapMode\n'
        },
        'enum': 'AcpFftOverlapMode',
        'name': 'ACP_FFT_OVERLAP_MODE',
        'type': 'int32'
    },
    1052732: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the samples to overlap between the consecutive chunks as a percentage of the RFMXSPECAN_ATTR_ACP_SEQUENTIAL_FFT_SIZE attribute when you set the RFMXSPECAN_ATTR_ACP_MEASUREMENT_METHOD attribute to RFMXSPECAN_VAL_ACP_MEASUREMENT_METHOD_SEQUENTIAL_FFT and the RFMXSPECAN_ATTR_ACP_FFT_OVERLAP_MODE attribute to RFMXSPECAN_VAL_ACP_FFT_OVERLAP_MODE_USER_DEFINED. This value is expressed as a percentage.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_ACPGetFFTOverlap\n Set Function: RFmxSpecAn_ACPSetFFTOverlap\n'
        },
        'name': 'ACP_FFT_OVERLAP',
        'type': 'float64'
    },
    1052733: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the measurement calibrates the noise floor of analyzer or performs the ACP measurement. Refer to the measurement guidelines section in the Noise Compensation Algorithm topic for more information.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_ACP_MEASUREMENT_MODE_MEASURE.\n \nGet Function: RFmxSpecAn_ACPGetMeasurementMode\n Set Function: RFmxSpecAn_ACPSetMeasurementMode\n'
        },
        'enum': 'AcpMeasurementMode',
        'name': 'ACP_MEASUREMENT_MODE',
        'type': 'int32'
    },
    1052734: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the noise compensation type. Refer to the Noise Compensation Algorithm topic for more information.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_ACP_NOISE_COMPENSATION_TYPE_ANALYZER_AND_TERMINATION.\n \nGet Function: RFmxSpecAn_ACPGetNoiseCompensationType\n Set Function: RFmxSpecAn_ACPSetNoiseCompensationType\n'
        },
        'enum': 'AcpNoiseCompensationType',
        'name': 'ACP_NOISE_COMPENSATION_TYPE',
        'type': 'int32'
    },
    1052735: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the averaging count used for noise calibration when you set the RFMXSPECAN_ATTR_ACP_NOISE_CALIBRATION_AVERAGING_AUTO attribute to RFMXSPECAN_VAL_ACP_NOISE_CALIBRATION_AVERAGING_AUTO_FALSE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 32.\n \nGet Function: RFmxSpecAn_ACPGetNoiseCalibrationAveragingCount\n Set Function: RFmxSpecAn_ACPSetNoiseCalibrationAveragingCount\n'
        },
        'name': 'ACP_NOISE_CALIBRATION_AVERAGING_COUNT',
        'type': 'int32'
    },
    1052736: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether RFmx automatically computes the averaging count used for instrument noise calibration.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_ACP_NOISE_CALIBRATION_AVERAGING_AUTO_TRUE.\n \nGet Function: RFmxSpecAn_ACPGetNoiseCalibrationAveragingAuto\n Set Function: RFmxSpecAn_ACPSetNoiseCalibrationAveragingAuto\n'
        },
        'enum': 'AcpNoiseCalibrationAveragingAuto',
        'name': 'ACP_NOISE_CALIBRATION_AVERAGING_AUTO',
        'type': 'int32'
    },
    1052737: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the noise calibration and measurement is performed manually by the user or automatically by RFmx. Refer to the measurement guidelines section in the Noise Compensation Algorithm topic for more information.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_ACP_NOISE_CALIBRATION_MODE_AUTO.\n \nGet Function: RFmxSpecAn_ACPGetNoiseCalibrationMode\n Set Function: RFmxSpecAn_ACPSetNoiseCalibrationMode\n'
        },
        'enum': 'AcpNoiseCalibrationMode',
        'name': 'ACP_NOISE_CALIBRATION_MODE',
        'type': 'int32'
    },
    1056768: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the CCDF measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_CCDFGetMeasurementEnabled\n Set Function: RFmxSpecAn_CCDFSetMeasurementEnabled\n'
        },
        'name': 'CCDF_MEASUREMENT_ENABLED',
        'type': 'int32'
    },
    1056770: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the acquisition time for the CCDF measurement. This value is expressed in seconds.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.001.\n \nGet Function: RFmxSpecAn_CCDFGetMeasurementInterval\n Set Function: RFmxSpecAn_CCDFSetMeasurementInterval\n'
        },
        'name': 'CCDF_MEASUREMENT_INTERVAL',
        'type': 'float64'
    },
    1056771: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum number of threads used for parallelism for CCDF measurement.\n \nThe number of threads can range from 1 to the number of physical cores. The number of threads you set may not be used in calculations. The actual number of threads used depends on the problem size, system resources, data availability, and other considerations.         \n\nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_CCDFGetNumberOfAnalysisThreads\n Set Function: RFmxSpecAn_CCDFSetNumberOfAnalysisThreads\n'
        },
        'name': 'CCDF_NUMBER_OF_ANALYSIS_THREADS',
        'type': 'int32'
    },
    1056772: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of acquisitions used for the CCDF measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_CCDFGetNumberOfRecords\n Set Function: RFmxSpecAn_CCDFSetNumberOfRecords\n'
        },
        'name': 'CCDF_NUMBER_OF_RECORDS',
        'type': 'int32'
    },
    1056774: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the roll-off factor for the root-raised-cosine (RRC) filter.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.1.\n \nGet Function: RFmxSpecAn_CCDFGetRBWFilterRRCAlpha\n Set Function: RFmxSpecAn_CCDFSetRBWFilterRRCAlpha\n'
        },
        'name': 'CCDF_RBW_FILTER_RRC_ALPHA',
        'type': 'float64'
    },
    1056775: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the bandwidth of the resolution bandwidth (RBW) filter used to measure the signal. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 100 kHz.\n \nGet Function: RFmxSpecAn_CCDFGetRBWFilterBandwidth\n Set Function: RFmxSpecAn_CCDFSetRBWFilterBandwidth\n'
        },
        'name': 'CCDF_RBW_FILTER_BANDWIDTH',
        'type': 'float64'
    },
    1056776: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the shape of the digital resolution bandwidth (RBW) filter.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_CCDF_RBW_FILTER_TYPE_NONE.\n \nGet Function: RFmxSpecAn_CCDFGetRBWFilterType\n Set Function: RFmxSpecAn_CCDFSetRBWFilterType\n'
        },
        'enum': 'CcdfRbwFilterType',
        'name': 'CCDF_RBW_FILTER_TYPE',
        'type': 'int32'
    },
    1056777: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable thresholding of the acquired samples to be used for the CCDF measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_CCDF_THRESHOLD_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_CCDFGetThresholdEnabled\n Set Function: RFmxSpecAn_CCDFSetThresholdEnabled\n'
        },
        'enum': 'CcdfThresholdEnabled',
        'name': 'CCDF_THRESHOLD_ENABLED',
        'type': 'int32'
    },
    1056778: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies either the relative or absolute threshold power level based on the value of the RFMXSPECAN_ATTR_CCDF_THRESHOLD_TYPE attribute.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is -20.\n \nGet Function: RFmxSpecAn_CCDFGetThresholdLevel\n Set Function: RFmxSpecAn_CCDFSetThresholdLevel\n'
        },
        'name': 'CCDF_THRESHOLD_LEVEL',
        'type': 'float64'
    },
    1056779: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the reference for the power level used for thresholding.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_CCDF_THRESHOLD_TYPE_RELATIVE.\n \nGet Function: RFmxSpecAn_CCDFGetThresholdType\n Set Function: RFmxSpecAn_CCDFSetThresholdType\n'
        },
        'enum': 'CcdfThresholdType',
        'name': 'CCDF_THRESHOLD_TYPE',
        'type': 'int32'
    },
    1056781: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the traces to be stored and retrieved after performing the CCDF measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_CCDFGetAllTracesEnabled\n Set Function: RFmxSpecAn_CCDFSetAllTracesEnabled\n'
        },
        'name': 'CCDF_ALL_TRACES_ENABLED',
        'type': 'int32'
    },
    1056782: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the average power of all the samples. This value is expressed in dBm. If you set the RFMXSPECAN_ATTR_CCDF_THRESHOLD_ENABLED attribute to RFMXSPECAN_VAL_CCDF_THRESHOLD_ENABLED_TRUE, samples above the threshold are measured.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_CCDFGetResultsMeanPower\n'
        },
        'name': 'CCDF_RESULTS_MEAN_POWER',
        'type': 'float64'
    },
    1056783: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the percentage of samples that have more power than the mean power.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_CCDFGetResultsMeanPowerPercentile\n'
        },
        'name': 'CCDF_RESULTS_MEAN_POWER_PERCENTILE',
        'type': 'float64'
    },
    1056784: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the power above the mean power, over which 10% of the total samples in the signal are present. This value is expressed in dB.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_CCDFGetResultsTenPercentPower\n'
        },
        'name': 'CCDF_RESULTS_TEN_PERCENT_POWER',
        'type': 'float64'
    },
    1056785: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the power above the mean power, over which 1% of the total samples in the signal are present. This value is expressed in dB.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_CCDFGetResultsOnePercentPower\n'
        },
        'name': 'CCDF_RESULTS_ONE_PERCENT_POWER',
        'type': 'float64'
    },
    1056786: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the power above the mean power, over which 0.1% of the total samples in the signal are present. This value is expressed in dB.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_CCDFGetResultsOneTenthPercentPower\n'
        },
        'name': 'CCDF_RESULTS_ONE_TENTH_PERCENT_POWER',
        'type': 'float64'
    },
    1056787: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the power above the mean power, over which 0.01% of the total samples in the signal are present. This value is expressed in dB.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_CCDFGetResultsOneHundredthPercentPower\n'
        },
        'name': 'CCDF_RESULTS_ONE_HUNDREDTH_PERCENT_POWER',
        'type': 'float64'
    },
    1056788: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the power above the mean power, over which 0.001% of the total samples in the signal are present. This value is expressed in dB.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_CCDFGetResultsOneThousandthPercentPower\n'
        },
        'name': 'CCDF_RESULTS_ONE_THOUSANDTH_PERCENT_POWER',
        'type': 'float64'
    },
    1056789: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the power above the mean power, over which 0.0001% of the total samples in the signal are present. This value is expressed in dB.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_CCDFGetResultsOneTenThousandthPercentPower\n'
        },
        'name': 'CCDF_RESULTS_ONE_TEN_THOUSANDTH_PERCENT_POWER',
        'type': 'float64'
    },
    1056790: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the peak power of the acquired signal, relative to the mean power.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nGet Function: RFmxSpecAn_CCDFGetResultsPeakPower\n'
        },
        'name': 'CCDF_RESULTS_PEAK_POWER',
        'type': 'float64'
    },
    1056791: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the total number of samples measured. The total number of samples includes only the samples above the threshold, when you set the RFMXSPECAN_ATTR_CCDF_THRESHOLD_ENABLED attribute to RFMXSPECAN_VAL_CCDF_THRESHOLD_ENABLED_TRUE.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_CCDFGetResultsMeasuredSampleCount\n'
        },
        'name': 'CCDF_RESULTS_MEASURED_SAMPLES_COUNT',
        'type': 'int32'
    },
    1060864: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the CHP measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_CHPGetMeasurementEnabled\n Set Function: RFmxSpecAn_CHPSetMeasurementEnabled\n'
        },
        'name': 'CHP_MEASUREMENT_ENABLED',
        'type': 'int32'
    },
    1060866: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the frequency range, over which the measurement integrates the power. This value is expressed in Hz.\n \nUse 'carrier(n)' as the selector string to configure or read this attribute.\n \nThe default value is 1 MHz.\n \nGet Function: RFmxSpecAn_CHPGetCarrierIntegrationBandwidth\n Set Function: RFmxSpecAn_CHPSetCarrierIntegrationBandwidth\n"
        },
        'name': 'CHP_CARRIER_INTEGRATION_BANDWIDTH',
        'type': 'float64'
    },
    1060867: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum number of threads used for parallelism for CHP measurement.\n \nThe number of threads can range from 1 to the number of physical cores. The number of threads you set may not be used in calculations. The actual number of threads used depends on the problem size, system resources, data availability, and other considerations.         \n\nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_CHPGetNumberOfAnalysisThreads\n Set Function: RFmxSpecAn_CHPSetNumberOfAnalysisThreads\n'
        },
        'name': 'CHP_NUMBER_OF_ANALYSIS_THREADS',
        'type': 'int32'
    },
    1060868: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the frequency range around the center frequency, to acquire for the measurement. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1 MHz.\n \nGet Function: RFmxSpecAn_CHPGetSpan\n Set Function: RFmxSpecAn_CHPSetSpan\n'
        },
        'name': 'CHP_SPAN',
        'type': 'float64'
    },
    1060870: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of acquisitions used for averaging when you set the RFMXSPECAN_ATTR_CHP_AVERAGING_ENABLED attribute to RFMXSPECAN_VAL_CHP_AVERAGING_ENABLED_TRUE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10.\n \nGet Function: RFmxSpecAn_CHPGetAveragingCount\n Set Function: RFmxSpecAn_CHPSetAveragingCount\n'
        },
        'name': 'CHP_AVERAGING_COUNT',
        'type': 'int32'
    },
    1060871: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable averaging for the CHP measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_CHP_AVERAGING_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_CHPGetAveragingEnabled\n Set Function: RFmxSpecAn_CHPSetAveragingEnabled\n'
        },
        'enum': 'ChpAveragingEnabled',
        'name': 'CHP_AVERAGING_ENABLED',
        'type': 'int32'
    },
    1060873: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the averaging type for averaging multiple spectrum acquisitions. The averaged spectrum is used for CHP measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_CHP_AVERAGING_TYPE_RMS.\n \nGet Function: RFmxSpecAn_CHPGetAveragingType\n Set Function: RFmxSpecAn_CHPSetAveragingType\n'
        },
        'enum': 'ChpAveragingType',
        'name': 'CHP_AVERAGING_TYPE',
        'type': 'int32'
    },
    1060874: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the FFT window type to use to reduce spectral leakage.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_CHP_FFT_WINDOW_FLAT_TOP.\n \nGet Function: RFmxSpecAn_CHPGetFFTWindow\n Set Function: RFmxSpecAn_CHPSetFFTWindow\n'
        },
        'enum': 'ChpFftWindow',
        'name': 'CHP_FFT_WINDOW',
        'type': 'int32'
    },
    1060875: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the factor by which the time-domain waveform is zero-padded before fast Fourier transform (FFT). The FFT size is given by the following formula:        \n\nwaveform size * padding        \n\nThis attribute is used only when the acquisition span is less than the device instantaneous bandwidth of the device.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is -1.\n \nGet Function: RFmxSpecAn_CHPGetFFTPadding\n Set Function: RFmxSpecAn_CHPSetFFTPadding\n'
        },
        'name': 'CHP_FFT_PADDING',
        'type': 'float64'
    },
    1060876: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the measurement computes the resolution bandwidth (RBW).\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_CHP_RBW_AUTO_TRUE.\n \nGet Function: RFmxSpecAn_CHPGetRBWFilterAutoBandwidth\n Set Function: RFmxSpecAn_CHPSetRBWFilterAutoBandwidth\n'
        },
        'enum': 'ChpRbwAutoBandwidth',
        'name': 'CHP_RBW_FILTER_AUTO_BANDWIDTH',
        'type': 'int32'
    },
    1060877: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the bandwidth of the resolution bandwidth (RBW) filter used to sweep the acquired signal, when you set the RFMXSPECAN_ATTR_CHP_RBW_FILTER_AUTO_BANDWIDTH attribute to RFMXSPECAN_VAL_CHP_RBW_AUTO_FALSE. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10 kHz.\n \nGet Function: RFmxSpecAn_CHPGetRBWFilterBandwidth\n Set Function: RFmxSpecAn_CHPSetRBWFilterBandwidth\n'
        },
        'name': 'CHP_RBW_FILTER_BANDWIDTH',
        'type': 'float64'
    },
    1060878: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the shape of the digital resolution bandwidth (RBW) filter.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_CHP_RBW_FILTER_TYPE_GAUSSIAN.\n \nGet Function: RFmxSpecAn_CHPGetRBWFilterType\n Set Function: RFmxSpecAn_CHPSetRBWFilterType\n'
        },
        'enum': 'ChpRbwFilterType',
        'name': 'CHP_RBW_FILTER_TYPE',
        'type': 'int32'
    },
    1060879: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies whether to apply the root-raised-cosine (RRC) filter on the acquired channel before measuring the channel power.\n \nUse 'carrier(n)' as the selector string to configure or read this attribute.\n \nThe default value is RFMXSPECAN_VAL_CHP_CARRIER_RRC_FILTER_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_CHPGetCarrierRRCFilterEnabled\n Set Function: RFmxSpecAn_CHPSetCarrierRRCFilterEnabled\n"
        },
        'enum': 'ChpCarrierRrcFilterEnabled',
        'name': 'CHP_CARRIER_RRC_FILTER_ENABLED',
        'type': 'int32'
    },
    1060880: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the roll-off factor of the root-raised-cosine (RRC) filter.\n \nUse 'carrier(n)' as the selector string to configure or read this attribute.\n \nThe default value is 0.1.\n \nGet Function: RFmxSpecAn_CHPGetCarrierRRCFilterAlpha\n Set Function: RFmxSpecAn_CHPSetCarrierRRCFilterAlpha\n"
        },
        'name': 'CHP_CARRIER_RRC_FILTER_ALPHA',
        'type': 'float64'
    },
    1060881: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the measurement computes the sweep time.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_CHP_SWEEP_TIME_AUTO_TRUE.\n \nGet Function: RFmxSpecAn_CHPGetSweepTimeAuto\n Set Function: RFmxSpecAn_CHPSetSweepTimeAuto\n'
        },
        'enum': 'ChpSweepTimeAuto',
        'name': 'CHP_SWEEP_TIME_AUTO',
        'type': 'int32'
    },
    1060882: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the sweep time when you set the RFMXSPECAN_ATTR_CHP_SWEEP_TIME_AUTO attribute to RFMXSPECAN_VAL_CHP_SWEEP_TIME_AUTO_FALSE. This value is expressed in seconds.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.001.\n \nGet Function: RFmxSpecAn_CHPGetSweepTimeInterval\n Set Function: RFmxSpecAn_CHPSetSweepTimeInterval\n'
        },
        'name': 'CHP_SWEEP_TIME_INTERVAL',
        'type': 'float64'
    },
    1060884: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the traces to be stored and retrieved after performing the CHP measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_CHPGetAllTracesEnabled\n Set Function: RFmxSpecAn_CHPSetAllTracesEnabled\n'
        },
        'name': 'CHP_ALL_TRACES_ENABLED',
        'type': 'int32'
    },
    1060885: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the carrier power measured in the integration bandwidth that you specify in the RFMXSPECAN_ATTR_CHP_CARRIER_INTEGRATION_BANDWIDTH attribute. This value is expressed in dBm.\n \nUse 'carrier(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_CHPGetResultsCarrierAbsolutePower\n"
        },
        'name': 'CHP_RESULTS_CARRIER_ABSOLUTE_POWER',
        'type': 'float64'
    },
    1060886: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the power spectral density of the channel. This value is expressed in dBm/Hz.\n \nUse 'carrier(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_CHPGetResultsCarrierPSD\n"
        },
        'name': 'CHP_RESULTS_CARRIER_PSD',
        'type': 'float64'
    },
    1060887: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the frequency bin spacing of the spectrum acquired by the measurement. This value is expressed in Hz.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_CHPGetResultsFrequencyResolution\n'
        },
        'name': 'CHP_RESULTS_FREQUENCY_RESOLUTION',
        'type': 'float64'
    },
    1060888: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of carriers.        \n\nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \n\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_CHPGetNumberOfCarriers\n Set Function: RFmxSpecAn_CHPSetNumberOfCarriers\n'
        },
        'name': 'CHP_NUMBER_OF_CARRIERS',
        'type': 'int32'
    },
    1060889: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the center frequency of the carrier, relative to the RF center frequency. This value is expressed in Hz.        \n\nUse 'carrier(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_CHPGetCarrierFrequency\n Set Function: RFmxSpecAn_CHPSetCarrierFrequency\n"
        },
        'name': 'CHP_CARRIER_FREQUENCY',
        'type': 'float64'
    },
    1060890: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the total integrated carrier power of all carriers, in dBm.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_CHPGetResultsTotalCarrierPower\n'
        },
        'name': 'CHP_RESULTS_TOTAL_CARRIER_POWER',
        'type': 'float64'
    },
    1060891: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the center frequency of the carrier relative to the Center Frequency attribute. This value is expressed in Hz.\n \nUse 'carrier(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_CHPGetResultsCarrierFrequency\n"
        },
        'name': 'CHP_RESULTS_CARRIER_FREQUENCY',
        'type': 'float64'
    },
    1060892: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the frequency range over which the measurement integrates the carrier power. This value is expressed in Hz.\n \nUse 'carrier(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_CHPGetResultsCarrierIntegrationBandwidth\n"
        },
        'name': 'CHP_RESULTS_CARRIER_INTEGRATION_BANDWIDTH',
        'type': 'float64'
    },
    1060893: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the carrier power measured relative to the total carrier power of all carriers. This value is expressed in dB.\n \nUse 'carrier(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_CHPGetResultsCarrierRelativePower\n"
        },
        'name': 'CHP_RESULTS_CARRIER_RELATIVE_POWER',
        'type': 'float64'
    },
    1060894: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the bandwidth definition that you use to specify the value of the RFMXSPECAN_ATTR_CHP_RBW_FILTER_BANDWIDTH attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_CHP_RBW_FILTER_BANDWIDTH_DEFINITION_3DB.\n \nGet Function: RFmxSpecAn_CHPGetRBWFilterBandwidthDefinition\n Set Function: RFmxSpecAn_CHPSetRBWFilterBandwidthDefinition\n'
        },
        'enum': 'ChpRbwFilterBandwidthDefinition',
        'name': 'CHP_RBW_FILTER_BANDWIDTH_DEFINITION',
        'type': 'int32'
    },
    1060895: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the amplitude of the frequency bins, used in the measurement, is corrected for external attenuation at the RF center frequency, or at the individual frequency bins. Use the RFmxInstr_CfgExternalAttenuationTable function to configure the external attenuation table.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_CHP_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY.\n \nGet Function: RFmxSpecAn_CHPGetAmplitudeCorrectionType\n Set Function: RFmxSpecAn_CHPSetAmplitudeCorrectionType\n'
        },
        'enum': 'ChpAmplitudeCorrectionType',
        'name': 'CHP_AMPLITUDE_CORRECTION_TYPE',
        'type': 'int32'
    },
    1060896: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the measurement calibrates the noise floor of analyzer or performs the CHP measurement. Refer to the measurement guidelines section in the Noise Compensation Algorithm topic for more information.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_CHP_MEASUREMENT_MODE_MEASURE.\n \nGet Function: RFmxSpecAn_CHPGetMeasurementMode\n Set Function: RFmxSpecAn_CHPSetMeasurementMode\n'
        },
        'enum': 'ChpMeasurementMode',
        'name': 'CHP_MEASUREMENT_MODE',
        'type': 'int32'
    },
    1060897: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether RFmx compensates for the instrument noise when performing the measurement. To compensate for instrument noise when performing a CHP measurement, set the RFMXSPECAN_ATTR_CHP_NOISE_CALIBRATION_MODE attribute to RFMXSPECAN_VAL_CHP_NOISE_CALIBRATION_MODE_AUTO, or set the RFMXSPECAN_ATTR_CHP_NOISE_CALIBRATION_MODE attribute to RFMXSPECAN_VAL_CHP_NOISE_CALIBRATION_MODE_MANUAL and RFMXSPECAN_ATTR_CHP_MEASUREMENT_MODE attribute to RFMXSPECAN_VAL_CHP_MEASUREMENT_MODE_MEASURE.  Refer to the measurement guidelines section in the Noise Compensation Algorithm topic for more information.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_CHP_NOISE_COMPENSATION_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_CHPGetNoiseCompensationEnabled\n Set Function: RFmxSpecAn_CHPSetNoiseCompensationEnabled\n'
        },
        'enum': 'ChpNoiseCompensationEnabled',
        'name': 'CHP_NOISE_COMPENSATION_ENABLED',
        'type': 'int32'
    },
    1060898: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the noise compensation type. Refer to the Noise Compensation Algorithm topic for more information.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_CHP_NOISE_COMPENSATION_TYPE_ANALYZER_AND_TERMINATION.\n \nGet Function: RFmxSpecAn_CHPGetNoiseCompensationType\n Set Function: RFmxSpecAn_CHPSetNoiseCompensationType\n'
        },
        'enum': 'ChpNoiseCompensationType',
        'name': 'CHP_NOISE_COMPENSATION_TYPE',
        'type': 'int32'
    },
    1060899: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the averaging count used for noise calibration when you set the RFMXSPECAN_ATTR_CHP_NOISE_CALIBRATION_AVERAGING_AUTO attribute to RFMXSPECAN_VAL_CHP_NOISE_CALIBRATION_AVERAGING_AUTO_FALSE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 32.\n \nGet Function: RFmxSpecAn_CHPGetNoiseCalibrationAveragingCount\n Set Function: RFmxSpecAn_CHPSetNoiseCalibrationAveragingCount\n'
        },
        'name': 'CHP_NOISE_CALIBRATION_AVERAGING_COUNT',
        'type': 'int32'
    },
    1060900: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether RFmx automatically computes the averaging count used for instrument noise calibration.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_CHP_NOISE_CALIBRATION_AVERAGING_AUTO_TRUE.\n \nGet Function: RFmxSpecAn_CHPGetNoiseCalibrationAveragingAuto\n Set Function: RFmxSpecAn_CHPSetNoiseCalibrationAveragingAuto\n'
        },
        'enum': 'ChpNoiseCalibrationAveragingAuto',
        'name': 'CHP_NOISE_CALIBRATION_AVERAGING_AUTO',
        'type': 'int32'
    },
    1060901: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the noise calibration and measurement is performed manually by the user or automatically by RFmx. Refer to the measurement guidelines section in the Noise Compensation Algorithm topic for more information.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_CHP_NOISE_CALIBRATION_MODE_AUTO.\n \nGet Function: RFmxSpecAn_CHPGetNoiseCalibrationMode\n Set Function: RFmxSpecAn_CHPSetNoiseCalibrationMode\n'
        },
        'enum': 'ChpNoiseCalibrationMode',
        'name': 'CHP_NOISE_CALIBRATION_MODE',
        'type': 'int32'
    },
    1064960: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the FCnt measurement.\n \nYou do not need to use a selector string to read this result for default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_FCntGetMeasurementEnabled\n Set Function: RFmxSpecAn_FCntSetMeasurementEnabled\n'
        },
        'name': 'FCNT_MEASUREMENT_ENABLED',
        'type': 'int32'
    },
    1064962: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the acquisition time for the FCnt measurement. This value is expressed in seconds.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.001.\n \nGet Function: RFmxSpecAn_FCntGetMeasurementInterval\n Set Function: RFmxSpecAn_FCntSetMeasurementInterval\n'
        },
        'name': 'FCNT_MEASUREMENT_INTERVAL',
        'type': 'float64'
    },
    1064963: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum number of threads used for parallelism for FCnt measurement.\n \nThe number of threads can range from 1 to the number of physical cores. The number of threads you set may not be used in calculations. The actual number of threads used depends on the problem size, system resources, data availability, and other considerations.         \n\nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_FCntGetNumberOfAnalysisThreads\n Set Function: RFmxSpecAn_FCntSetNumberOfAnalysisThreads\n'
        },
        'name': 'FCNT_NUMBER_OF_ANALYSIS_THREADS',
        'type': 'int32'
    },
    1064965: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of acquisitions used for averaging when you set the RFMXSPECAN_ATTR_FCNT_AVERAGING_ENABLED attribute to RFMXSPECAN_VAL_FCNT_AVERAGING_ENABLED_TRUE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10.\n \nGet Function: RFmxSpecAn_FCntGetAveragingCount\n Set Function: RFmxSpecAn_FCntSetAveragingCount\n'
        },
        'name': 'FCNT_AVERAGING_COUNT',
        'type': 'int32'
    },
    1064966: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable averaging for the FCnt measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FCNT_AVERAGING_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_FCntGetAveragingEnabled\n Set Function: RFmxSpecAn_FCntSetAveragingEnabled\n'
        },
        'enum': 'FcntAveragingEnabled',
        'name': 'FCNT_AVERAGING_ENABLED',
        'type': 'int32'
    },
    1064968: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the averaging type for the FCnt measurement. The averaged instantaneous signal phase difference is used for the measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FCNT_AVERAGING_TYPE_MEAN.\n \nGet Function: RFmxSpecAn_FCntGetAveragingType\n Set Function: RFmxSpecAn_FCntSetAveragingType\n'
        },
        'enum': 'FcntAveragingType',
        'name': 'FCNT_AVERAGING_TYPE',
        'type': 'int32'
    },
    1064969: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the roll-off factor for the root-raised-cosine (RRC) filter.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.1.\n \nGet Function: RFmxSpecAn_FCntGetRBWFilterRRCAlpha\n Set Function: RFmxSpecAn_FCntSetRBWFilterRRCAlpha\n'
        },
        'name': 'FCNT_RBW_FILTER_RRC_ALPHA',
        'type': 'float64'
    },
    1064970: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the bandwidth of the resolution bandwidth (RBW) filter used to measure the signal. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 100 kHz.\n \nGet Function: RFmxSpecAn_FCntGetRBWFilterBandwidth\n Set Function: RFmxSpecAn_FCntSetRBWFilterBandwidth\n'
        },
        'name': 'FCNT_RBW_FILTER_BANDWIDTH',
        'type': 'float64'
    },
    1064971: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the shape of the digital resolution bandwidth (RBW) filter.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FCNT_RBW_FILTER_TYPE_NONE.\n \nGet Function: RFmxSpecAn_FCntGetRBWFilterType\n Set Function: RFmxSpecAn_FCntSetRBWFilterType\n'
        },
        'enum': 'FcntRbwFilterType',
        'name': 'FCNT_RBW_FILTER_TYPE',
        'type': 'int32'
    },
    1064972: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable thresholding of the acquired samples to be used for the FCnt measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FCNT_THRESHOLD_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_FCntGetThresholdEnabled\n Set Function: RFmxSpecAn_FCntSetThresholdEnabled\n'
        },
        'enum': 'FcntThresholdEnabled',
        'name': 'FCNT_THRESHOLD_ENABLED',
        'type': 'int32'
    },
    1064973: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies either the relative or absolute threshold power level based on the value of the RFMXSPECAN_ATTR_FCNT_THRESHOLD_TYPE attribute.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is -20.\n \nGet Function: RFmxSpecAn_FCntGetThresholdLevel\n Set Function: RFmxSpecAn_FCntSetThresholdLevel\n'
        },
        'name': 'FCNT_THRESHOLD_LEVEL',
        'type': 'float64'
    },
    1064974: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the reference for the power level used for thresholding.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FCNT_THRESHOLD_TYPE_RELATIVE.\n \nGet Function: RFmxSpecAn_FCntGetThresholdType\n Set Function: RFmxSpecAn_FCntSetThresholdType\n'
        },
        'enum': 'FcntThresholdType',
        'name': 'FCNT_THRESHOLD_TYPE',
        'type': 'int32'
    },
    1064976: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the traces to be stored and retrieved after performing the FCnt measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_FCntGetAllTracesEnabled\n Set Function: RFmxSpecAn_FCntSetAllTracesEnabled\n'
        },
        'name': 'FCNT_ALL_TRACES_ENABLED',
        'type': 'int32'
    },
    1064977: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the signal frequency relative to the RF center frequency. Only samples above the threshold are used when you set the RFMXSPECAN_ATTR_FCNT_THRESHOLD_ENABLED attribute to RFMXSPECAN_VAL_FCNT_THRESHOLD_ENABLED_TRUE.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_FCntGetResultsAverageRelativeFrequency\n'
        },
        'name': 'FCNT_RESULTS_AVERAGE_RELATIVE_FREQUENCY',
        'type': 'float64'
    },
    1064978: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the net phase of the vector sum of the I/Q samples used for frequency measurement.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_FCntGetResultsMeanPhase\n'
        },
        'name': 'FCNT_RESULTS_MEAN_PHASE',
        'type': 'float64'
    },
    1064979: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the RF signal frequency. Only samples above the threshold are used when you set the RFMXSPECAN_ATTR_FCNT_THRESHOLD_ENABLED attribute to RFMXSPECAN_VAL_FCNT_THRESHOLD_ENABLED_TRUE.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_FCntGetResultsAverageAbsoluteFrequency\n'
        },
        'name': 'FCNT_RESULTS_AVERAGE_ABSOLUTE_FREQUENCY',
        'type': 'float64'
    },
    1064980: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the two-sample deviation of the measured frequency.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_FCntGetResultsAllanDeviation\n'
        },
        'name': 'FCNT_RESULTS_ALLAN_DEVIATION',
        'type': 'float64'
    },
    1069056: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the Harmonics measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_HarmGetMeasurementEnabled\n Set Function: RFmxSpecAn_HarmSetMeasurementEnabled\n'
        },
        'name': 'HARM_MEASUREMENT_ENABLED',
        'type': 'int32'
    },
    1069058: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum number of threads used for parallelism for Harmonics measurement.\n \nThe number of threads can range from 1 to the number of physical cores. The number of threads you set may not be used in calculations. The actual number of threads used depends on the problem size, system resources, data availability, and other considerations.         \n\nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_HarmGetNumberOfAnalysisThreads\n Set Function: RFmxSpecAn_HarmSetNumberOfAnalysisThreads\n'
        },
        'name': 'HARM_NUMBER_OF_ANALYSIS_THREADS',
        'type': 'int32'
    },
    1069059: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the roll-off factor for the root-raised-cosine (RRC) filter.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.1.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_HarmGetFundamentalRBWFilterAlpha\n Set Function: RFmxSpecAn_HarmSetFundamentalRBWFilterAlpha\n'
        },
        'name': 'HARM_FUNDAMENTAL_RBW_FILTER_ALPHA',
        'type': 'float64'
    },
    1069060: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the bandwidth of the resolution bandwidth (RBW) filter used to measure the fundamental signal. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 100 kHz.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_HarmGetFundamentalRBWFilterBandwidth\n Set Function: RFmxSpecAn_HarmSetFundamentalRBWFilterBandwidth\n'
        },
        'name': 'HARM_FUNDAMENTAL_RBW_FILTER_BANDWIDTH',
        'type': 'float64'
    },
    1069061: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the shape of the digital resolution bandwidth (RBW) filter.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_HARM_RBW_FILTER_TYPE_GAUSSIAN.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_HarmGetFundamentalRBWFilterType\n Set Function: RFmxSpecAn_HarmSetFundamentalRBWFilterType\n'
        },
        'enum': 'HarmRbwFilterType',
        'name': 'HARM_FUNDAMENTAL_RBW_FILTER_TYPE',
        'type': 'int32'
    },
    1069062: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the acquisition time for the Harmonics measurement of the fundamental signal. This value is expressed in seconds.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.001.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_HarmGetFundamentalMeasurementInterval\n Set Function: RFmxSpecAn_HarmSetFundamentalMeasurementInterval\n'
        },
        'name': 'HARM_FUNDAMENTAL_MEASUREMENT_INTERVAL',
        'type': 'float64'
    },
    1069063: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of harmonics, including fundamental, to measure.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 3.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_HarmGetNumberOfHarmonics\n Set Function: RFmxSpecAn_HarmSetNumberOfHarmonics\n'
        },
        'name': 'HARM_NUMBER_OF_HARMONICS',
        'type': 'int32'
    },
    1069064: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable auto configuration of successive harmonics.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_HARM_AUTO_HARMONICS_SETUP_ENABLED_TRUE.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_HarmGetAutoSetupEnabled\n Set Function: RFmxSpecAn_HarmSetAutoSetupEnabled\n'
        },
        'enum': 'HarmAutoHarmonicsSetupEnabled',
        'name': 'HARM_AUTO_SETUP_ENABLED',
        'type': 'int32'
    },
    1069065: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies whether to enable a particular harmonic for measurement. Only the enabled harmonics are used to measure the total harmonic distortion (THD). This attribute is not used if you set the RFMXSPECAN_ATTR_HARM_AUTO_SETUP_ENABLED to RFMXSPECAN_VAL_HARM_AUTO_HARMONICS_SETUP_ENABLED_TRUE.        \n\nUse 'harmonic(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_HARM_HARMONIC_ENABLED_TRUE.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_HarmGetHarmonicEnabled\n Set Function: RFmxSpecAn_HarmSetHarmonicEnabled\n"
        },
        'enum': 'HarmHarmonicEnabled',
        'name': 'HARM_HARMONIC_ENABLED',
        'type': 'int32'
    },
    1069066: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the order of the harmonic. This attribute is not used if you set the RFMXSPECAN_ATTR_HARM_AUTO_SETUP_ENABLED to RFMXSPECAN_VAL_HARM_AUTO_HARMONICS_SETUP_ENABLED_TRUE.        \n\nFrequency of Nth order harmonic = N * (Frequency of fundamental)        \n\nUse 'harmonic(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 1.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_HarmGetHarmonicOrder\n Set Function: RFmxSpecAn_HarmSetHarmonicOrder\n"
        },
        'name': 'HARM_HARMONIC_ORDER',
        'type': 'int32'
    },
    1069067: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the acquisition time for the harmonic. This value is expressed in seconds. This attribute is not used if you set the RFMXSPECAN_ATTR_HARM_AUTO_SETUP_ENABLED to RFMXSPECAN_VAL_HARM_AUTO_HARMONICS_SETUP_ENABLED_TRUE.        \n\nUse 'harmonic(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 1 ms.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_HarmGetHarmonicMeasurementInterval\n Set Function: RFmxSpecAn_HarmSetHarmonicMeasurementInterval\n"
        },
        'name': 'HARM_HARMONIC_MEASUREMENT_INTERVAL',
        'type': 'float64'
    },
    1069068: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of acquisitions used for averaging when you set the RFMXSPECAN_ATTR_HARM_AVERAGING_ENABLED attribute to RFMXSPECAN_VAL_HARM_AVERAGING_ENABLED_TRUE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10.        \n\n   Supported devices: PXIe-5644/5645/5646, PXIe-5663/5663E/5665/5668\n \nGet Function: RFmxSpecAn_HarmGetAveragingCount\n Set Function: RFmxSpecAn_HarmSetAveragingCount\n'
        },
        'name': 'HARM_AVERAGING_COUNT',
        'type': 'int32'
    },
    1069069: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable averaging for the Harmonics measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_HARM_AVERAGING_ENABLED_FALSE.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_HarmGetAveragingEnabled\n Set Function: RFmxSpecAn_HarmSetAveragingEnabled\n'
        },
        'enum': 'HarmAveragingEnabled',
        'name': 'HARM_AVERAGING_ENABLED',
        'type': 'int32'
    },
    1069071: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the averaging type for the Harmonics measurement. The averaged power trace is used for the measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_HARM_AVERAGING_TYPE_RMS.        \n\n   Supported devices: PXIe-5644/5645/5646, PXIe-5663/5663E/5665/5668\n \nGet Function: RFmxSpecAn_HarmGetAveragingType\n Set Function: RFmxSpecAn_HarmSetAveragingType\n'
        },
        'enum': 'HarmAveragingType',
        'name': 'HARM_AVERAGING_TYPE',
        'type': 'int32'
    },
    1069072: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the traces to be stored and retrieved after performing the Harmonics measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_HarmGetAllTracesEnabled\n Set Function: RFmxSpecAn_HarmSetAllTracesEnabled\n'
        },
        'name': 'HARM_ALL_TRACES_ENABLED',
        'type': 'int32'
    },
    1069073: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the frequency used as the fundamental frequency. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nGet Function: RFmxSpecAn_HarmGetResultsFundamentalFrequency\n'
        },
        'name': 'HARM_RESULTS_FUNDAMENTAL_FREQUENCY',
        'type': 'float64'
    },
    1069074: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the average power measured at the fundamental frequency. This value is expressed in dBm.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_HarmGetResultsAverageFundamentalPower\n'
        },
        'name': 'HARM_RESULTS_AVERAGE_FUNDAMENTAL_POWER',
        'type': 'float64'
    },
    1069075: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the total harmonics distortion (THD), measured as a percentage of the power in the fundamental signal.\n \nTHD (%) = SQRT (Total power of all enabled harmonics - Power in fundamental) * 100 / Power in fundamental        \n\nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_HarmGetResultsTotalHarmonicDistortion\n'
        },
        'name': 'HARM_RESULTS_TOTAL_HARMONIC_DISTORTION',
        'type': 'float64'
    },
    1069076: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the RF frequency of the harmonic. This value is expressed in Hz.        \n\nUse 'harmonic(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_HarmGetResultsHarmonicFrequency\n"
        },
        'name': 'HARM_RESULTS_HARMONIC_FREQUENCY',
        'type': 'float64'
    },
    1069077: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the resolution bandwidth (RBW) which is used by the harmonic measurement, for the harmonic specified by the selector string. This value is expressed in Hz.        \n\nUse 'harmonic(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_HarmGetResultsHarmonicRBW\n"
        },
        'name': 'HARM_RESULTS_HARMONIC_RBW',
        'type': 'float64'
    },
    1069078: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the average absolute power measured at the harmonic specified by the selector string. This value is expressed in dBm.        \n\nUse 'harmonic(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_HarmGetResultsHarmonicAverageAbsolutePower\n"
        },
        'name': 'HARM_RESULTS_HARMONIC_AVERAGE_ABSOLUTE_POWER',
        'type': 'float64'
    },
    1069079: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the average power relative to the fundamental power measured at the harmonic specified by the selector string. This value is expressed in dB.         \n\nUse 'harmonic(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_HarmGetResultsHarmonicAverageRelativePower\n"
        },
        'name': 'HARM_RESULTS_HARMONIC_AVERAGE_RELATIVE_POWER',
        'type': 'float64'
    },
    1069080: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the resolution bandwidth for the harmonic. This attribute is not used if you set the RFMXSPECAN_ATTR_HARM_AUTO_SETUP_ENABLED to RFMXSPECAN_VAL_HARM_AUTO_HARMONICS_SETUP_ENABLED_TRUE. This value is expressed in Hz.        \n\nUse 'harmonic(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 100 kHz.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_HarmGetHarmonicBandwidth\n Set Function: RFmxSpecAn_HarmSetHarmonicBandwidth\n"
        },
        'name': 'HARM_HARMONIC_BANDWIDTH',
        'type': 'float64'
    },
    1069082: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the method used to perform the harmonics measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_HARM_MEASUREMENT_METHOD_TIME_DOMAIN.\n \nGet Function: RFmxSpecAn_HarmGetMeasurementMethod\n Set Function: RFmxSpecAn_HarmSetMeasurementMethod\n'
        },
        'enum': 'HarmMeasurementMethod',
        'name': 'HARM_MEASUREMENT_METHOD',
        'type': 'int32'
    },
    1069083: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable compensation of the average harmonic powers for inherent noise floor of the signal analyzer.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_HARM_NOISE_COMPENSATION_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_HarmGetNoiseCompensationEnabled\n Set Function: RFmxSpecAn_HarmSetNoiseCompensationEnabled\n'
        },
        'enum': 'HarmNoiseCompensationEnabled',
        'name': 'HARM_NOISE_COMPENSATION_ENABLED',
        'type': 'int32'
    },
    1073152: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable OBW measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_OBWGetMeasurementEnabled\n Set Function: RFmxSpecAn_OBWSetMeasurementEnabled\n'
        },
        'name': 'OBW_MEASUREMENT_ENABLED',
        'type': 'int32'
    },
    1073154: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the percentage of the total power that is contained in the OBW.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 99%.\n \nGet Function: RFmxSpecAn_OBWGetBandwidthPercentage\n Set Function: RFmxSpecAn_OBWSetBandwidthPercentage\n'
        },
        'name': 'OBW_BANDWIDTH_PERCENTAGE',
        'type': 'float64'
    },
    1073155: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum number of threads used for parallelism for the OBW measurement.\n \nThe number of threads can range from 1 to the number of physical cores. The number of threads you set may not be used in calculations. The actual number of threads used depends on the problem size, system resources, data availability, and other considerations.         \n\nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_OBWGetNumberOfAnalysisThreads\n Set Function: RFmxSpecAn_OBWSetNumberOfAnalysisThreads\n'
        },
        'name': 'OBW_NUMBER_OF_ANALYSIS_THREADS',
        'type': 'int32'
    },
    1073156: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the frequency range around the center frequency, to acquire for the measurement. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1 MHz.\n \nGet Function: RFmxSpecAn_OBWGetSpan\n Set Function: RFmxSpecAn_OBWSetSpan\n'
        },
        'name': 'OBW_SPAN',
        'type': 'float64'
    },
    1073158: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of acquisitions used for averaging when you set the RFMXSPECAN_ATTR_OBW_AVERAGING_ENABLED attribute to RFMXSPECAN_VAL_OBW_AVERAGING_ENABLED_TRUE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10.\n \nGet Function: RFmxSpecAn_OBWGetAveragingCount\n Set Function: RFmxSpecAn_OBWSetAveragingCount\n'
        },
        'name': 'OBW_AVERAGING_COUNT',
        'type': 'int32'
    },
    1073159: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable averaging for the OBW measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_OBW_AVERAGING_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_OBWGetAveragingEnabled\n Set Function: RFmxSpecAn_OBWSetAveragingEnabled\n'
        },
        'enum': 'ObwAveragingEnabled',
        'name': 'OBW_AVERAGING_ENABLED',
        'type': 'int32'
    },
    1073161: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the averaging type for averaging multiple spectrum acquisitions. The averaged spectrum is used for OBW measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_OBW_AVERAGING_TYPE_RMS.\n \nGet Function: RFmxSpecAn_OBWGetAveragingType\n Set Function: RFmxSpecAn_OBWSetAveragingType\n'
        },
        'enum': 'ObwAveragingType',
        'name': 'OBW_AVERAGING_TYPE',
        'type': 'int32'
    },
    1073162: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the FFT window type to use to reduce spectral leakage.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_OBW_FFT_WINDOW_FLAT_TOP.\n \nGet Function: RFmxSpecAn_OBWGetFFTWindow\n Set Function: RFmxSpecAn_OBWSetFFTWindow\n'
        },
        'enum': 'ObwFftWindow',
        'name': 'OBW_FFT_WINDOW',
        'type': 'int32'
    },
    1073163: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the factor by which the time-domain waveform is zero-padded before fast Fourier transform (FFT). The FFT size is given by the following formula:        \n\nwaveform size * padding        \n\nThis attribute is used only when the acquisition span is less than the device instantaneous bandwidth of the device.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is -1.\n \nGet Function: RFmxSpecAn_OBWGetFFTPadding\n Set Function: RFmxSpecAn_OBWSetFFTPadding\n'
        },
        'name': 'OBW_FFT_PADDING',
        'type': 'float64'
    },
    1073164: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the measurement computes the resolution bandwidth (RBW).\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_OBW_RBW_AUTO_TRUE.\n \nGet Function: RFmxSpecAn_OBWGetRBWFilterAutoBandwidth\n Set Function: RFmxSpecAn_OBWSetRBWFilterAutoBandwidth\n'
        },
        'enum': 'ObwRbwAutoBandwidth',
        'name': 'OBW_RBW_FILTER_AUTO_BANDWIDTH',
        'type': 'int32'
    },
    1073165: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the bandwidth of the resolution bandwidth (RBW) filter used to sweep the acquired signal, when you set the RFMXSPECAN_ATTR_OBW_RBW_FILTER_AUTO_BANDWIDTH attribute to RFMXSPECAN_VAL_OBW_RBW_AUTO_FALSE. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10 kHz.\n \nGet Function: RFmxSpecAn_OBWGetRBWFilterBandwidth\n Set Function: RFmxSpecAn_OBWSetRBWFilterBandwidth\n'
        },
        'name': 'OBW_RBW_FILTER_BANDWIDTH',
        'type': 'float64'
    },
    1073166: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the shape of the digital resolution bandwidth (RBW) filter.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_OBW_RBW_FILTER_TYPE_GAUSSIAN.\n \nGet Function: RFmxSpecAn_OBWGetRBWFilterType\n Set Function: RFmxSpecAn_OBWSetRBWFilterType\n'
        },
        'enum': 'ObwRbwFilterType',
        'name': 'OBW_RBW_FILTER_TYPE',
        'type': 'int32'
    },
    1073167: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the measurement computes the sweep time.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_OBW_SWEEP_TIME_AUTO_TRUE.\n \nGet Function: RFmxSpecAn_OBWGetSweepTimeAuto\n Set Function: RFmxSpecAn_OBWSetSweepTimeAuto\n'
        },
        'enum': 'ObwSweepTimeAuto',
        'name': 'OBW_SWEEP_TIME_AUTO',
        'type': 'int32'
    },
    1073168: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the sweep time when you set the RFMXSPECAN_ATTR_OBW_SWEEP_TIME_AUTO attribute to RFMXSPECAN_VAL_OBW_SWEEP_TIME_AUTO_FALSE. This value is expressed in seconds.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.001.\n \nGet Function: RFmxSpecAn_OBWGetSweepTimeInterval\n Set Function: RFmxSpecAn_OBWSetSweepTimeInterval\n'
        },
        'name': 'OBW_SWEEP_TIME_INTERVAL',
        'type': 'float64'
    },
    1073170: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the traces to be stored and retrieved after performing the OBW.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_OBWGetAllTracesEnabled\n Set Function: RFmxSpecAn_OBWSetAllTracesEnabled\n'
        },
        'name': 'OBW_ALL_TRACES_ENABLED',
        'type': 'int32'
    },
    1073171: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the bandwidth that occupies the percentage of the total power of the signal that you specify in the RFMXSPECAN_ATTR_OBW_BANDWIDTH_PERCENTAGE attribute. This value is expressed in Hz.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_OBWGetResultsOccupiedBandwidth\n'
        },
        'name': 'OBW_RESULTS_OCCUPIED_BANDWIDTH',
        'type': 'float64'
    },
    1073172: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the total integrated power, in dBm, of the averaged spectrum acquired by the OBW measurement when you set the RFMXSPECAN_ATTR_OBW_POWER_UNITS attribute to RFMXSPECAN_VAL_OBW_POWER_UNITS_DBM. The RFMXSPECAN_ATTR_OBW_RESULTS_AVERAGE_POWER attribute returns the power spectral density, in dBm/Hz,  when you set the RFMXSPECAN_ATTR_OBW_POWER_UNITS attribute to RFMXSPECAN_VAL_OBW_POWER_UNITS_DBM_PER_HZ.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_OBWGetResultsAveragePower\n'
        },
        'name': 'OBW_RESULTS_AVERAGE_POWER',
        'type': 'float64'
    },
    1073173: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the start frequency of the OBW. This value is expressed in Hz.\n \nThe OBW is calculated using the following formula: OBW = stop frequency - start frequency        \n\nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_OBWGetResultsStartFrequency\n'
        },
        'name': 'OBW_RESULTS_START_FREQUENCY',
        'type': 'float64'
    },
    1073174: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the stop frequency of the OBW. This value is expressed in Hz.\n \nThe OBW is calculated using the following formula: OBW = stop frequency - start frequency        \n\nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_OBWGetResultsStopFrequency\n'
        },
        'name': 'OBW_RESULTS_STOP_FREQUENCY',
        'type': 'float64'
    },
    1073175: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the frequency bin spacing of the spectrum acquired by the OBW measurement. This value is expressed in Hz.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_OBWGetResultsFrequencyResolution\n'
        },
        'name': 'OBW_RESULTS_FREQUENCY_RESOLUTION',
        'type': 'float64'
    },
    1073176: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the units for the absolute power.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_OBW_POWER_UNITS_DBM_PER_HZ.\n \nGet Function: RFmxSpecAn_OBWGetPowerUnits\n Set Function: RFmxSpecAn_OBWSetPowerUnits\n'
        },
        'enum': 'ObwPowerUnits',
        'name': 'OBW_POWER_UNITS',
        'type': 'int32'
    },
    1073177: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the bandwidth definition that you use to specify the value of the RFMXSPECAN_ATTR_OBW_RBW_FILTER_BANDWIDTH attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_OBW_RBW_FILTER_BANDWIDTH_DEFINITION_3DB.\n \nGet Function: RFmxSpecAn_OBWGetRBWFilterBandwidthDefinition\n Set Function: RFmxSpecAn_OBWSetRBWFilterBandwidthDefinition\n'
        },
        'enum': 'ObwRbwFilterBandwidthDefinition',
        'name': 'OBW_RBW_FILTER_BANDWIDTH_DEFINITION',
        'type': 'int32'
    },
    1073178: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the amplitude of the frequency bins, used in the measurement, is corrected for external attenuation at the RF center frequency, or at the individual frequency bins. Use the RFmxInstr_CfgExternalAttenuationTable function to configure the external attenuation table.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_OBW_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY.\n \nGet Function: RFmxSpecAn_OBWGetAmplitudeCorrectionType\n Set Function: RFmxSpecAn_OBWSetAmplitudeCorrectionType\n'
        },
        'enum': 'ObwAmplitudeCorrectionType',
        'name': 'OBW_AMPLITUDE_CORRECTION_TYPE',
        'type': 'int32'
    },
    1077248: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the Phase Amplitude Versus Time (PAVT) measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_PAVTGetMeasurementEnabled\n Set Function: RFmxSpecAn_PAVTSetMeasurementEnabled\n'
        },
        'name': 'PAVT_MEASUREMENT_ENABLED',
        'type': 'int32'
    },
    1077250: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the location at which the segment is measured is indicated by time or trigger.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_PAVT_MEASUREMENT_LOCATION_TYPE_TIME.\n \nGet Function: RFmxSpecAn_PAVTGetMeasurementLocationType\n Set Function: RFmxSpecAn_PAVTSetMeasurementLocationType\n'
        },
        'enum': 'PavtMeasurementLocationType',
        'name': 'PAVT_MEASUREMENT_LOCATION_TYPE',
        'type': 'int32'
    },
    1077251: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of segments to be measured.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_PAVTGetNumberOfSegments\n Set Function: RFmxSpecAn_PAVTSetNumberOfSegments\n'
        },
        'name': 'PAVT_NUMBER_OF_SEGMENTS',
        'type': 'int32'
    },
    1077252: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the start time of measurement of the segments. This value is expressed in seconds. You can use this attribute only when you set the RFMXSPECAN_ATTR_PAVT_MEASUREMENT_LOCATION_TYPE attribute to RFMXSPECAN_VAL_PAVT_MEASUREMENT_LOCATION_TYPE_TIME.\n \nUse 'segment(n)' as the selector string to configure or read this attribute.\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_PAVTGetSegmentStartTime\n Set Function: RFmxSpecAn_PAVTSetSegmentStartTime\n"
        },
        'name': 'PAVT_SEGMENT_START_TIME',
        'type': 'float64'
    },
    1077253: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the time offset from the start of the segment for which the phase and amplitude, amplitude, or frequency error values are computed. This value is expressed in seconds. This attribute is valid only when you set the RFMXSPECAN_ATTR_PAVT_MEASUREMENT_INTERVAL_MODE attribute to RFMXSPECAN_VAL_PAVT_MEASUREMENT_INTERVAL_MODE_UNIFORM.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_PAVTGetMeasurementOffset\n Set Function: RFmxSpecAn_PAVTSetMeasurementOffset\n'
        },
        'name': 'PAVT_MEASUREMENT_OFFSET',
        'type': 'float64'
    },
    1077254: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the duration within the segment over which the phase and amplitude, amplitude, or frequency error values are computed. This value is expressed in seconds. This attribute is valid only when you set the RFMXSPECAN_ATTR_PAVT_MEASUREMENT_INTERVAL_MODE attribute to RFMXSPECAN_VAL_PAVT_MEASUREMENT_INTERVAL_MODE_UNIFORM.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1 millisecond.\n \nGet Function: RFmxSpecAn_PAVTGetMeasurementLength\n Set Function: RFmxSpecAn_PAVTSetMeasurementLength\n'
        },
        'name': 'PAVT_MEASUREMENT_LENGTH',
        'type': 'float64'
    },
    1077255: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the traces to be stored and retrieved after performing the PAVT measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_PAVTGetAllTracesEnabled\n Set Function: RFmxSpecAn_PAVTSetAllTracesEnabled\n'
        },
        'name': 'PAVT_ALL_TRACES_ENABLED',
        'type': 'int32'
    },
    1077258: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the mean phase of the segment, relative to the phase of the reference segment. This value is expressed in degrees.       \n\n\n \nUse 'segment(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_PAVTGetResultsMeanRelativePhase\n"
        },
        'name': 'PAVT_RESULTS_MEAN_RELATIVE_PHASE',
        'type': 'float64'
    },
    1077259: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the mean amplitude of the segment, relative to the amplitude of the reference segment. This value is expressed in dB.      \n\nMean Relative Amplitude = ai - ar      \n\nai is the absolute amplitude of the segment i, expressed in dBm      \n\nar is the absolute amplitude of the reference segment r, expressed in dBm     \n\nwhere,\n\nr = 1, if Segment0 is configured as Frequency Error Measurement segment\n\nr = 0, otherwise\n \nUse 'segment(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_PAVTGetResultsMeanRelativeAmplitude\n"
        },
        'name': 'PAVT_RESULTS_MEAN_RELATIVE_AMPLITUDE',
        'type': 'float64'
    },
    1077260: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable frequency offset correction for the measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_PAVT_FREQUENCY_OFFSET_CORRECTION_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_PAVTGetFrequencyOffsetCorrectionEnabled\n Set Function: RFmxSpecAn_PAVTSetFrequencyOffsetCorrectionEnabled\n'
        },
        'enum': 'PavtFrequencyOffsetCorrectionEnabled',
        'name': 'PAVT_FREQUENCY_OFFSET_CORRECTION_ENABLED',
        'type': 'int32'
    },
    1077261: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the bandwidth over which the signal is measured. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10 MHz.\n \nGet Function: RFmxSpecAn_PAVTGetMeasurementBandwidth\n Set Function: RFmxSpecAn_PAVTSetMeasurementBandwidth\n'
        },
        'name': 'PAVT_MEASUREMENT_BANDWIDTH',
        'type': 'float64'
    },
    1077262: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the mean absolute amplitude of the segment. This value is expressed in dBm.\n \nUse 'segment(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_PAVTGetResultsMeanAbsoluteAmplitude\n"
        },
        'name': 'PAVT_RESULTS_MEAN_ABSOLUTE_AMPLITUDE',
        'type': 'float64'
    },
    1077263: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the mean absolute phase of the segment. This value is expressed in degrees.\n \nUse 'segment(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_PAVTGetResultsMeanAbsolutePhase\n"
        },
        'name': 'PAVT_RESULTS_MEAN_ABSOLUTE_PHASE',
        'type': 'float64'
    },
    1077264: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the type of segment.\n \nUse 'segment(n)' as the selector string to configure or read this attribute.\n \nThe default value is RFMXSPECAN_VAL_PAVT_SEGMENT_TYPE_PHASE_AND_AMPLITUDE.\n \nGet Function: RFmxSpecAn_PAVTGetSegmentType\n Set Function: RFmxSpecAn_PAVTSetSegmentType\n"
        },
        'enum': 'PavtSegmentType',
        'name': 'PAVT_SEGMENT_TYPE',
        'type': 'int32'
    },
    1077265: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the time offset from the start of the segment for which the phase and amplitude, amplitude, or frequency error values are computed. This value is expressed in seconds. This attribute is valid only when you set the RFMXSPECAN_ATTR_PAVT_MEASUREMENT_INTERVAL_MODE attribute to RFMXSPECAN_VAL_PAVT_MEASUREMENT_INTERVAL_MODE_VARIABLE.\n \nUse 'segment(n)' as the selector string to configure or read this attribute.\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_PAVTGetSegmentMeasurementOffset\n Set Function: RFmxSpecAn_PAVTSetSegmentMeasurementOffset\n"
        },
        'name': 'PAVT_SEGMENT_MEASUREMENT_OFFSET',
        'type': 'float64'
    },
    1077266: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the duration within each segment over which the phase and amplitude, amplitude, or frequency error values are computed. This value is expressed in seconds. This attribute is valid when you set the RFMXSPECAN_ATTR_PAVT_MEASUREMENT_INTERVAL_MODE attribute to RFMXSPECAN_VAL_PAVT_MEASUREMENT_INTERVAL_MODE_VARIABLE.\n \nUse 'segment(n)' as the selector string to configure or read this attribute.\n \nThe default value is 1 millisecond.\n \nGet Function: RFmxSpecAn_PAVTGetSegmentMeasurementLength\n Set Function: RFmxSpecAn_PAVTSetSegmentMeasurementLength\n"
        },
        'name': 'PAVT_SEGMENT_MEASUREMENT_LENGTH',
        'type': 'float64'
    },
    1077267: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the phase measurement results are unwrapped or wrapped.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_PAVT_PHASE_UNWRAP_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_PAVTGetPhaseUnwrapEnabled\n Set Function: RFmxSpecAn_PAVTSetPhaseUnwrapEnabled\n'
        },
        'enum': 'PavtPhaseUnwrapEnabled',
        'name': 'PAVT_PHASE_UNWRAP_ENABLED',
        'type': 'int32'
    },
    1077268: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the mean frequency error of the segment. This value is expressed in Hz\n \nUse 'segment(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_PAVTGetResultsFrequencyErrorMean\n"
        },
        'name': 'PAVT_RESULTS_FREQUENCY_ERROR_MEAN',
        'type': 'float64'
    },
    1077269: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the mode of configuring the measurement interval.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_PAVT_MEASUREMENT_INTERVAL_MODE_UNIFORM.\n \nGet Function: RFmxSpecAn_PAVTGetMeasurementIntervalMode\n Set Function: RFmxSpecAn_PAVTSetMeasurementIntervalMode\n'
        },
        'enum': 'PavtMeasurementIntervalMode',
        'name': 'PAVT_MEASUREMENT_INTERVAL_MODE',
        'type': 'int32'
    },
    1077270: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable frequency offset correction per segment for the measurement. While you set this attribute to RFMXSPECAN_VAL_PAVT_FREQUENCY_TRACKING_ENABLED_TRUE, ensure that the RFMXSPECAN_ATTR_PAVT_FREQUENCY_OFFSET_CORRECTION_ENABLED attribute is set to RFMXSPECAN_VAL_PAVT_FREQUENCY_OFFSET_CORRECTION_ENABLED_TRUE and the RFMXSPECAN_ATTR_PAVT_SEGMENT_TYPE attribute is set to RFMXSPECAN_VAL_PAVT_SEGMENT_TYPE_PHASE_AND_AMPLITUDE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_PAVT_FREQUENCY_TRACKING_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_PAVTGetFrequencyTrackingEnabled\n Set Function: RFmxSpecAn_PAVTSetFrequencyTrackingEnabled\n'
        },
        'enum': 'PavtFrequencyTrackingEnabled',
        'name': 'PAVT_FREQUENCY_TRACKING_ENABLED',
        'type': 'int32'
    },
    1081344: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the SEM measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_SEMGetMeasurementEnabled\n Set Function: RFmxSpecAn_SEMSetMeasurementEnabled\n'
        },
        'name': 'SEM_MEASUREMENT_ENABLED',
        'type': 'int32'
    },
    1081346: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of carriers.        \n\nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \n\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_SEMGetNumberOfCarriers\n Set Function: RFmxSpecAn_SEMSetNumberOfCarriers\n'
        },
        'name': 'SEM_NUMBER_OF_CARRIERS',
        'type': 'int32'
    },
    1081347: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies whether to consider the carrier power as part of the total carrier power measurement.         \n\nUse 'carrier(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_SEM_ENABLED_TRUE.\n \nGet Function: RFmxSpecAn_SEMGetCarrierEnabled\n Set Function: RFmxSpecAn_SEMSetCarrierEnabled\n"
        },
        'enum': 'SemCarrierEnabled',
        'name': 'SEM_CARRIER_ENABLED',
        'type': 'int32'
    },
    1081348: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the center frequency of the carrier, relative to the RF center frequency. This value is expressed in Hz.        \n\nUse 'carrier(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_SEMGetCarrierFrequency\n Set Function: RFmxSpecAn_SEMSetCarrierFrequency\n"
        },
        'name': 'SEM_CARRIER_FREQUENCY',
        'type': 'float64'
    },
    1081349: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the frequency range over which the measurement integrates the carrier power. This value is expressed in Hz.        \n\nUse 'carrier(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 2 MHz.\n \nGet Function: RFmxSpecAn_SEMGetCarrierIntegrationBandwidth\n Set Function: RFmxSpecAn_SEMSetCarrierIntegrationBandwidth\n"
        },
        'name': 'SEM_CARRIER_INTEGRATION_BANDWIDTH',
        'type': 'float64'
    },
    1081350: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies whether the measurement computes the resolution bandwidth (RBW) of the carrier.         \n\nUse 'carrier(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_SEM_CARRIER_RBW_AUTO_TRUE.\n \nGet Function: RFmxSpecAn_SEMGetCarrierRBWFilterAutoBandwidth\n Set Function: RFmxSpecAn_SEMSetCarrierRBWFilterAutoBandwidth\n"
        },
        'enum': 'SemCarrierRbwAutoBandwidth',
        'name': 'SEM_CARRIER_RBW_FILTER_AUTO_BANDWIDTH',
        'type': 'int32'
    },
    1081351: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the bandwidth of the resolution bandwidth (RBW) filter used to sweep the acquired carrier signal, when you set the RFMXSPECAN_ATTR_SEM_CARRIER_RBW_FILTER_AUTO_BANDWIDTH attribute to RFMXSPECAN_VAL_SEM_CARRIER_RBW_AUTO_FALSE. This value is expressed in Hz.        \n\nUse 'carrier(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 10 kHz.\n \nGet Function: RFmxSpecAn_SEMGetCarrierRBWFilterBandwidth\n Set Function: RFmxSpecAn_SEMSetCarrierRBWFilterBandwidth\n"
        },
        'name': 'SEM_CARRIER_RBW_FILTER_BANDWIDTH',
        'type': 'float64'
    },
    1081352: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the shape of the digital resolution bandwidth (RBW) filter.        \n\nUse 'carrier(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_SEM_CARRIER_RBW_FILTER_TYPE_GAUSSIAN.\n \nGet Function: RFmxSpecAn_SEMGetCarrierRBWFilterType\n Set Function: RFmxSpecAn_SEMSetCarrierRBWFilterType\n"
        },
        'enum': 'SemCarrierRbwFilterType',
        'name': 'SEM_CARRIER_RBW_FILTER_TYPE',
        'type': 'int32'
    },
    1081353: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies whether to apply the root-raised-cosine (RRC) filter on the acquired carrier channel before measuring the carrier channel power.        \n\nUse 'carrier(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_SEM_RRC_FILTER_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_SEMGetCarrierRRCFilterEnabled\n Set Function: RFmxSpecAn_SEMSetCarrierRRCFilterEnabled\n"
        },
        'enum': 'SemCarrierRrcFilterEnabled',
        'name': 'SEM_CARRIER_RRC_FILTER_ENABLED',
        'type': 'int32'
    },
    1081354: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the roll-off factor for the root-raised-cosine (RRC) filter to apply on the acquired carrier channel before measuring the carrier channel power.        \n\nUse 'carrier(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 0.1.\n \nGet Function: RFmxSpecAn_SEMGetCarrierRRCFilterAlpha\n Set Function: RFmxSpecAn_SEMSetCarrierRRCFilterAlpha\n"
        },
        'name': 'SEM_CARRIER_RRC_FILTER_ALPHA',
        'type': 'float64'
    },
    1081355: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of offset segments.        \n\nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \n\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_SEMGetNumberOfOffsets\n Set Function: RFmxSpecAn_SEMSetNumberOfOffsets\n'
        },
        'name': 'SEM_NUMBER_OF_OFFSETS',
        'type': 'int32'
    },
    1081356: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the resolution of the spectrum to compare with spectral mask limits as an integer multiple of the resolution bandwidth (RBW).\n \nIf you set this attribute to a value greater than 1, the measurement acquires the spectrum with a narrow resolution and then processes it digitally to get a wider resolution that is equal to the product of the bandwidth integral and the RBW.\n \nUse 'offset(n)' as the selector string to configure or read this attribute.        \n\nThe default value is 1.\n \nGet Function: RFmxSpecAn_SEMGetOffsetBandwidthIntegral\n Set Function: RFmxSpecAn_SEMSetOffsetBandwidthIntegral\n"
        },
        'name': 'SEM_OFFSET_BANDWIDTH_INTEGRAL',
        'type': 'int32'
    },
    1081357: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the criteria to determine the measurement fail status.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_ABSOLUTE_AND_RELATIVE.\n \nGet Function: RFmxSpecAn_SEMGetOffsetLimitFailMask\n Set Function: RFmxSpecAn_SEMSetOffsetLimitFailMask\n"
        },
        'enum': 'SemOffsetLimitFailMask',
        'name': 'SEM_OFFSET_LIMIT_FAIL_MASK',
        'type': 'int32'
    },
    1081358: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the attenuation relative to the external attenuation specified by the RFMXSPECAN_ATTR_EXTERNAL_ATTENUATION attribute. This value is expressed in dB. Use the SEM Offset Rel Attn attribute to compensate for the variations in external attenuation when offset segments are spread wide in frequency.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_SEMGetOffsetRelativeAttenuation\n Set Function: RFmxSpecAn_SEMSetOffsetRelativeAttenuation\n"
        },
        'name': 'SEM_OFFSET_RELATIVE_ATTENUATION',
        'type': 'float64'
    },
    1081359: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies whether the absolute limit mask is a flat line or a line with a slope.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_SEM_OFFSET_ABSOLUTE_LIMIT_MODE_COUPLE.\n \nGet Function: RFmxSpecAn_SEMGetOffsetAbsoluteLimitMode\n Set Function: RFmxSpecAn_SEMSetOffsetAbsoluteLimitMode\n"
        },
        'enum': 'SemOffsetAbsoluteLimitMode',
        'name': 'SEM_OFFSET_ABSOLUTE_LIMIT_MODE',
        'type': 'int32'
    },
    1081360: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the absolute power limit corresponding to the beginning of the offset segment. This value is expressed in dBm. This power limit is also set as the stop limit for the offset segment when you set the RFMXSPECAN_ATTR_SEM_OFFSET_ABSOLUTE_LIMIT_MODE attribute to RFMXSPECAN_VAL_SEM_OFFSET_ABSOLUTE_LIMIT_MODE_COUPLE.\n \nUse 'offset(n)' as the selector string to configure or read this attribute.\n \nThe default value is -10.\n \nGet Function: RFmxSpecAn_SEMGetOffsetAbsoluteLimitStart\n Set Function: RFmxSpecAn_SEMSetOffsetAbsoluteLimitStart\n"
        },
        'name': 'SEM_OFFSET_ABSOLUTE_LIMIT_START',
        'type': 'float64'
    },
    1081361: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the absolute power limit corresponding to the end of the offset segment. This value is expressed in dBm. The measurement ignores this attribute when you set the RFMXSPECAN_ATTR_SEM_OFFSET_ABSOLUTE_LIMIT_MODE attribute to RFMXSPECAN_VAL_SEM_OFFSET_ABSOLUTE_LIMIT_MODE_COUPLE.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is -10.\n \nGet Function: RFmxSpecAn_SEMGetOffsetAbsoluteLimitStop\n Set Function: RFmxSpecAn_SEMSetOffsetAbsoluteLimitStop\n"
        },
        'name': 'SEM_OFFSET_ABSOLUTE_LIMIT_STOP',
        'type': 'float64'
    },
    1081362: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies whether to enable the offset segment for SEM measurement.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_SEM_OFFSET_ENABLED_TRUE.\n \nGet Function: RFmxSpecAn_SEMGetOffsetEnabled\n Set Function: RFmxSpecAn_SEMSetOffsetEnabled\n"
        },
        'enum': 'SemOffsetEnabled',
        'name': 'SEM_OFFSET_ENABLED',
        'type': 'int32'
    },
    1081363: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies whether the offset segment is present on one side, or on both sides of the carrier.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_SEM_OFFSET_SIDEBAND_BOTH.\n \nGet Function: RFmxSpecAn_SEMGetOffsetSideband\n Set Function: RFmxSpecAn_SEMSetOffsetSideband\n"
        },
        'enum': 'SemOffsetSideband',
        'name': 'SEM_OFFSET_SIDEBAND',
        'type': 'int32'
    },
    1081364: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the start frequency of the offset segment relative to the closest configured carrier channel bandwidth center or carrier channel bandwidth edge based on the value of the RFMXSPECAN_ATTR_SEM_OFFSET_FREQUENCY_DEFINITION attribute. This value is expressed in Hz.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 1 MHz.\n \nGet Function: RFmxSpecAn_SEMGetOffsetStartFrequency\n Set Function: RFmxSpecAn_SEMSetOffsetStartFrequency\n"
        },
        'name': 'SEM_OFFSET_START_FREQUENCY',
        'type': 'float64'
    },
    1081365: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the stop frequency of the offset segment relative to the closest configured carrier  channel bandwidth center or carrier channel bandwidth edge based on the value of the RFMXSPECAN_ATTR_SEM_OFFSET_FREQUENCY_DEFINITION attribute. This value is expressed in Hz.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 2 MHz.\n \nGet Function: RFmxSpecAn_SEMGetOffsetStopFrequency\n Set Function: RFmxSpecAn_SEMSetOffsetStopFrequency\n"
        },
        'name': 'SEM_OFFSET_STOP_FREQUENCY',
        'type': 'float64'
    },
    1081366: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies whether the measurement computes the resolution bandwidth (RBW).         \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_SEM_RBW_AUTO_TRUE.\n \nGet Function: RFmxSpecAn_SEMGetOffsetRBWFilterAutoBandwidth\n Set Function: RFmxSpecAn_SEMSetOffsetRBWFilterAutoBandwidth\n"
        },
        'enum': 'SemOffsetRbwAutoBandwidth',
        'name': 'SEM_OFFSET_RBW_FILTER_AUTO_BANDWIDTH',
        'type': 'int32'
    },
    1081367: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the bandwidth of the resolution bandwidth (RBW) filter used to sweep the acquired offset segment, when you set the RFMXSPECAN_ATTR_SEM_OFFSET_RBW_FILTER_AUTO_BANDWIDTH attribute to RFMXSPECAN_VAL_SEM_RBW_AUTO_FALSE. This value is expressed in Hz.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 10 kHz.\n \nGet Function: RFmxSpecAn_SEMGetOffsetRBWFilterBandwidth\n Set Function: RFmxSpecAn_SEMSetOffsetRBWFilterBandwidth\n"
        },
        'name': 'SEM_OFFSET_RBW_FILTER_BANDWIDTH',
        'type': 'float64'
    },
    1081368: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the shape of the digital resolution bandwidth (RBW) filter.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_SEM_RBW_FILTER_TYPE_GAUSSIAN.\n \nGet Function: RFmxSpecAn_SEMGetOffsetRBWFilterType\n Set Function: RFmxSpecAn_SEMSetOffsetRBWFilterType\n"
        },
        'enum': 'SemOffsetRbwFilterType',
        'name': 'SEM_OFFSET_RBW_FILTER_TYPE',
        'type': 'int32'
    },
    1081369: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies whether the relative limit mask is a flat line or a line with a slope.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_SEM_OFFSET_RELATIVE_LIMIT_MODE_MANUAL.\n \nGet Function: RFmxSpecAn_SEMGetOffsetRelativeLimitMode\n Set Function: RFmxSpecAn_SEMSetOffsetRelativeLimitMode\n"
        },
        'enum': 'SemOffsetRelativeLimitMode',
        'name': 'SEM_OFFSET_RELATIVE_LIMIT_MODE',
        'type': 'int32'
    },
    1081370: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the relative power limit corresponding to the beginning of the offset segment. This value is expressed in dB. This power limit is also set as the stop limit for the offset segment when you set the RFMXSPECAN_ATTR_SEM_OFFSET_RELATIVE_LIMIT_MODE attribute to RFMXSPECAN_VAL_SEM_OFFSET_RELATIVE_LIMIT_MODE_COUPLE.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is -20.\n \nGet Function: RFmxSpecAn_SEMGetOffsetRelativeLimitStart\n Set Function: RFmxSpecAn_SEMSetOffsetRelativeLimitStart\n"
        },
        'name': 'SEM_OFFSET_RELATIVE_LIMIT_START',
        'type': 'float64'
    },
    1081371: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the relative power limit corresponding to the end of the offset segment. This value is expressed in dB. The measurement ignores this attribute when you set the RFMXSPECAN_ATTR_SEM_OFFSET_RELATIVE_LIMIT_MODE attribute to RFMXSPECAN_VAL_SEM_OFFSET_RELATIVE_LIMIT_MODE_COUPLE.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is -30.\n \nGet Function: RFmxSpecAn_SEMGetOffsetRelativeLimitStop\n Set Function: RFmxSpecAn_SEMSetOffsetRelativeLimitStop\n"
        },
        'name': 'SEM_OFFSET_RELATIVE_LIMIT_STOP',
        'type': 'float64'
    },
    1081372: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the units for the absolute power.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SEM_POWER_UNITS_DBM_PER_HZ.\n \nGet Function: RFmxSpecAn_SEMGetPowerUnits\n Set Function: RFmxSpecAn_SEMSetPowerUnits\n'
        },
        'enum': 'SemPowerUnits',
        'name': 'SEM_POWER_UNITS',
        'type': 'int32'
    },
    1081373: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum number of threads used for parallelism for SEM measurement.\n \nThe number of threads can range from 1 to the number of physical cores. The number of threads you set may not be used in calculations. The actual number of threads used depends on the problem size, system resources, data availability, and other considerations.         \n\nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_SEMGetNumberOfAnalysisThreads\n Set Function: RFmxSpecAn_SEMSetNumberOfAnalysisThreads\n'
        },
        'name': 'SEM_NUMBER_OF_ANALYSIS_THREADS',
        'type': 'int32'
    },
    1081374: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of acquisitions used for averaging when you set the RFMXSPECAN_ATTR_SEM_AVERAGING_ENABLED attribute to RFMXSPECAN_VAL_SEM_AVERAGING_ENABLED_TRUE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10.\n \nGet Function: RFmxSpecAn_SEMGetAveragingCount\n Set Function: RFmxSpecAn_SEMSetAveragingCount\n'
        },
        'name': 'SEM_AVERAGING_COUNT',
        'type': 'int32'
    },
    1081375: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable averaging for the SEM measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SEM_AVERAGING_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_SEMGetAveragingEnabled\n Set Function: RFmxSpecAn_SEMSetAveragingEnabled\n'
        },
        'enum': 'SemAveragingEnabled',
        'name': 'SEM_AVERAGING_ENABLED',
        'type': 'int32'
    },
    1081377: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the averaging type for averaging multiple spectrum acquisitions. The averaged spectrum is used for SEM measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SEM_AVERAGING_TYPE_RMS.\n \nGet Function: RFmxSpecAn_SEMGetAveragingType\n Set Function: RFmxSpecAn_SEMSetAveragingType\n'
        },
        'enum': 'SemAveragingType',
        'name': 'SEM_AVERAGING_TYPE',
        'type': 'int32'
    },
    1081378: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the FFT window type to use to reduce spectral leakage.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SEM_FFT_WINDOW_FLAT_TOP.\n \nGet Function: RFmxSpecAn_SEMGetFFTWindow\n Set Function: RFmxSpecAn_SEMSetFFTWindow\n'
        },
        'enum': 'SemFftWindow',
        'name': 'SEM_FFT_WINDOW',
        'type': 'int32'
    },
    1081379: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the factor by which the time-domain waveform is zero-padded before FFT. The FFT size is given by the following formula:        \n\nwaveform size * padding        \n\nThis attribute is used only when the acquisition span is less than the device instantaneous bandwidth of the device.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is -1.\n \nGet Function: RFmxSpecAn_SEMGetFFTPadding\n Set Function: RFmxSpecAn_SEMSetFFTPadding\n'
        },
        'name': 'SEM_FFT_PADDING',
        'type': 'float64'
    },
    1081380: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the power reference is the integrated power or the peak power in the closest carrier channel. The leftmost carrier is the carrier closest to all the lower (negative) offset segments. The rightmost carrier is the carrier closest to all the upper (positive) offset segments.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SEM_REFERENCE_TYPE_INTEGRATION.\n \nGet Function: RFmxSpecAn_SEMGetReferenceType\n Set Function: RFmxSpecAn_SEMSetReferenceType\n'
        },
        'enum': 'SemReferenceType',
        'name': 'SEM_REFERENCE_TYPE',
        'type': 'int32'
    },
    1081381: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the measurement computes the sweep time.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SEM_SWEEP_TIME_AUTO_TRUE.\n \nGet Function: RFmxSpecAn_SEMGetSweepTimeAuto\n Set Function: RFmxSpecAn_SEMSetSweepTimeAuto\n'
        },
        'enum': 'SemSweepTimeAuto',
        'name': 'SEM_SWEEP_TIME_AUTO',
        'type': 'int32'
    },
    1081382: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the sweep time when you set the RFMXSPECAN_ATTR_SEM_SWEEP_TIME_AUTO attribute to RFMXSPECAN_VAL_SEM_SWEEP_TIME_AUTO_FALSE. This value is expressed in seconds.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.001.\n \nGet Function: RFmxSpecAn_SEMGetSweepTimeInterval\n Set Function: RFmxSpecAn_SEMSetSweepTimeInterval\n'
        },
        'name': 'SEM_SWEEP_TIME_INTERVAL',
        'type': 'float64'
    },
    1081383: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the traces to be stored and retrieved after performing the SEM measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_SEMGetAllTracesEnabled\n Set Function: RFmxSpecAn_SEMSetAllTracesEnabled\n'
        },
        'name': 'SEM_ALL_TRACES_ENABLED',
        'type': 'int32'
    },
    1081384: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the total integrated power, in dBm, of all the enabled carriers measured when you set the RFMXSPECAN_ATTR_SEM_POWER_UNITS attribute to RFMXSPECAN_VAL_SEM_POWER_UNITS_DBM. Returns the power spectral density, in dBm/Hz, when you set the RFMXSPECAN_ATTR_SEM_POWER_UNITS attribute to RFMXSPECAN_VAL_SEM_POWER_UNITS_DBM_PER_HZ.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_SEMGetResultsTotalCarrierPower\n'
        },
        'name': 'SEM_RESULTS_TOTAL_CARRIER_POWER',
        'type': 'float64'
    },
    1081385: {
        'access': 'read-write',
        'documentation': {
            'description': ' Indicates the overall measurement status based on the measurement limits and the fail criteria that you set in the RFMXSPECAN_ATTR_SEM_OFFSET_LIMIT_FAIL_MASK attribute for each offset segment.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_SEMGetResultsCompositeMeasurementStatus\n'
        },
        'enum': 'SemCompositeMeasurementStatus',
        'name': 'SEM_RESULTS_COMPOSITE_MEASUREMENT_STATUS',
        'type': 'int32'
    },
    1081386: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the frequency bin spacing of the spectrum acquired by the measurement. This value is expressed in Hz.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_SEMGetResultsFrequencyResolution\n'
        },
        'name': 'SEM_RESULTS_FREQUENCY_RESOLUTION',
        'type': 'float64'
    },
    1081387: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the center frequency of the carrier relative to the Center Frequency attribute. This value is expressed in Hz.        \n\nUse 'carrier(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_SEMGetResultsCarrierFrequency\n"
        },
        'name': 'SEM_RESULTS_CARRIER_FREQUENCY',
        'type': 'float64'
    },
    1081388: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the frequency range, over which the measurement integrates the carrier power. This value is expressed in Hz.        \n\nUse 'carrier(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_SEMGetResultsCarrierIntegrationBandwidth\n"
        },
        'name': 'SEM_RESULTS_CARRIER_INTEGRATION_BANDWIDTH',
        'type': 'float64'
    },
    1081389: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the carrier power.\n \nThe carrier power is reported in dBm when you set the RFMXSPECAN_ATTR_SEM_POWER_UNITS attribute to RFMXSPECAN_VAL_SEM_POWER_UNITS_DBM, and in dBm/Hz when you set the RFMXSPECAN_ATTR_SEM_POWER_UNITS attribute to RFMXSPECAN_VAL_SEM_POWER_UNITS_DBM_PER_HZ.        \n\nUse 'carrier(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_SEMGetResultsCarrierAbsolutePower\n"
        },
        'name': 'SEM_RESULTS_CARRIER_ABSOLUTE_POWER',
        'type': 'float64'
    },
    1081390: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the carrier power relative to the total carrier power of all enabled carriers. This value is expressed in dB.        \n\nUse 'carrier(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_SEMGetResultsCarrierTotalRelativePower\n"
        },
        'name': 'SEM_RESULTS_CARRIER_TOTAL_RELATIVE_POWER',
        'type': 'float64'
    },
    1081391: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the peak power in the carrier channel.\n \nThe power is reported in dBm when you set the RFMXSPECAN_ATTR_SEM_POWER_UNITS attribute to RFMXSPECAN_VAL_SEM_POWER_UNITS_DBM, and in dBm/Hz when you set the RFMXSPECAN_ATTR_SEM_POWER_UNITS attribute to RFMXSPECAN_VAL_SEM_POWER_UNITS_DBM_PER_HZ.        \n\nUse 'carrier(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_SEMGetResultsCarrierPeakAbsolutePower\n"
        },
        'name': 'SEM_RESULTS_CARRIER_PEAK_ABSOLUTE_POWER',
        'type': 'float64'
    },
    1081392: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the frequency at which the peak power occurs in the carrier channel. This value is expressed in Hz.        \n\nUse 'carrier(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_SEMGetResultsCarrierPeakFrequency\n"
        },
        'name': 'SEM_RESULTS_CARRIER_PEAK_FREQUENCY',
        'type': 'float64'
    },
    1081393: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the start frequency of the lower (negative) offset segment. This value is expressed in Hz.        \n\nUse 'offset(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_SEMGetResultsLowerOffsetStartFrequency\n"
        },
        'name': 'SEM_RESULTS_LOWER_OFFSET_START_FREQUENCY',
        'type': 'float64'
    },
    1081394: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the stop frequency of the lower (negative) offset segment. This value is expressed in Hz.        \n\nUse 'offset(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_SEMGetResultsLowerOffsetStopFrequency\n"
        },
        'name': 'SEM_RESULTS_LOWER_OFFSET_STOP_FREQUENCY',
        'type': 'float64'
    },
    1081395: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the index of the carrier that was used as the power reference to define the lower (negative) offset segment relative power. The reference carrier is the carrier that has an offset closest to the offset segment.        \n\nUse 'offset(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_SEMGetResultsLowerOffsetPowerReferenceCarrier\n"
        },
        'name': 'SEM_RESULTS_LOWER_OFFSET_POWER_REFERENCE_CARRIER',
        'type': 'int32'
    },
    1081396: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the power measured in the lower (negative) offset segment.\n \nThe power is reported in dBm when you set the RFMXSPECAN_ATTR_SEM_POWER_UNITS attribute to RFMXSPECAN_VAL_SEM_POWER_UNITS_DBM, and in dBm/Hz when you set the RFMXSPECAN_ATTR_SEM_POWER_UNITS attribute to RFMXSPECAN_VAL_SEM_POWER_UNITS_DBM_PER_HZ.        \n\nUse 'offset(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_SEMGetResultsLowerOffsetTotalAbsolutePower\n"
        },
        'name': 'SEM_RESULTS_LOWER_OFFSET_TOTAL_ABSOLUTE_POWER',
        'type': 'float64'
    },
    1081397: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the power measured in the lower (negative) offset segment relative to either the integrated or peak power of the reference carrier.\n \nWhen you set the RFMXSPECAN_ATTR_SEM_REFERENCE_TYPE attribute to RFMXSPECAN_VAL_SEM_REFERENCE_TYPE_INTEGRATION, the reference carrier power is the total power in the reference carrier. When you set the RFMXSPECAN_ATTR_SEM_REFERENCE_TYPE attribute to RFMXSPECAN_VAL_SEM_REFERENCE_TYPE_PEAK, the reference carrier power is the peak power in the reference carrier.        \n\nUse 'offset(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_SEMGetResultsLowerOffsetTotalRelativePower\n"
        },
        'name': 'SEM_RESULTS_LOWER_OFFSET_TOTAL_RELATIVE_POWER',
        'type': 'float64'
    },
    1081398: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the peak power measured in the lower (negative) offset segment.\n \nThe power is reported in dBm when you set the RFMXSPECAN_ATTR_SEM_POWER_UNITS attribute to RFMXSPECAN_VAL_SEM_POWER_UNITS_DBM, and in dBm/Hz when you set the RFMXSPECAN_ATTR_SEM_POWER_UNITS attribute to RFMXSPECAN_VAL_SEM_POWER_UNITS_DBM_PER_HZ.        \n\nUse 'offset(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_SEMGetResultsLowerOffsetPeakAbsolutePower\n"
        },
        'name': 'SEM_RESULTS_LOWER_OFFSET_PEAK_ABSOLUTE_POWER',
        'type': 'float64'
    },
    1081399: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the peak power measured in the lower (negative) offset segment relative to the integrated or peak power of the reference carrier.\n \nWhen you set the RFMXSPECAN_ATTR_SEM_REFERENCE_TYPE attribute to RFMXSPECAN_VAL_SEM_REFERENCE_TYPE_INTEGRATION, the reference carrier power is the total power in the reference carrier. When you set the RFMXSPECAN_ATTR_SEM_REFERENCE_TYPE attribute to RFMXSPECAN_VAL_SEM_REFERENCE_TYPE_PEAK, the reference carrier power is the peak power in the reference carrier.        \n\nUse 'offset(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_SEMGetResultsLowerOffsetPeakRelativePower\n"
        },
        'name': 'SEM_RESULTS_LOWER_OFFSET_PEAK_RELATIVE_POWER',
        'type': 'float64'
    },
    1081400: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the frequency at which the peak power occurred in the lower offset segment. This value is expressed in Hz.        \n\nUse 'offset(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_SEMGetResultsLowerOffsetPeakFrequency\n"
        },
        'name': 'SEM_RESULTS_LOWER_OFFSET_PEAK_FREQUENCY',
        'type': 'float64'
    },
    1081401: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the margin from the limit mask value that you set in the RFMXSPECAN_ATTR_SEM_OFFSET_LIMIT_FAIL_MASK attribute. This value is expressed in dB. Margin is defined as the maximum difference between the spectrum and the limit mask.\n \nWhen you set the RFMXSPECAN_ATTR_SEM_OFFSET_LIMIT_FAIL_MASK attribute to Absolute, the margin is with reference to the absolute limit mask.        \n\nWhen you set the RFMXSPECAN_ATTR_SEM_OFFSET_LIMIT_FAIL_MASK attribute to Relative, the margin is with reference to the relative limit mask.        \n\nWhen you set the RFMXSPECAN_ATTR_SEM_OFFSET_LIMIT_FAIL_MASK attribute to Abs AND Rel, the margin is the maximum of the margins referenced to the absolute and relative limit masks.        \n\nWhen you set the RFMXSPECAN_ATTR_SEM_OFFSET_LIMIT_FAIL_MASK attribute to Abs OR Rel, the margin is the minimum of the margins referenced to the absolute and relative limit masks.        \n\nUse 'offset(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_SEMGetResultsLowerOffsetMargin\n"
        },
        'name': 'SEM_RESULTS_LOWER_OFFSET_MARGIN',
        'type': 'float64'
    },
    1081402: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the power, at which the margin occurred in the lower (negative) offset segment.\n \nThe power is reported in dBm when you set the RFMXSPECAN_ATTR_SEM_POWER_UNITS attribute to RFMXSPECAN_VAL_SEM_POWER_UNITS_DBM, and in dBm/Hz when you set the RFMXSPECAN_ATTR_SEM_POWER_UNITS attribute to RFMXSPECAN_VAL_SEM_POWER_UNITS_DBM_PER_HZ.        \n\nUse 'offset(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_SEMGetResultsLowerOffsetMarginAbsolutePower\n"
        },
        'name': 'SEM_RESULTS_LOWER_OFFSET_MARGIN_ABSOLUTE_POWER',
        'type': 'float64'
    },
    1081403: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the power at which the margin occurred in the lower (negative) offset segment relative to the integrated or peak power of the reference carrier. This value is expressed in dB.        \n\nUse 'offset(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_SEMGetResultsLowerOffsetMarginRelativePower\n"
        },
        'name': 'SEM_RESULTS_LOWER_OFFSET_MARGIN_RELATIVE_POWER',
        'type': 'float64'
    },
    1081404: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the frequency at which the margin occurred in the lower (negative) offset segment. This value is expressed in Hz.        \n\nUse 'offset(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_SEMGetResultsLowerOffsetMarginFrequency\n"
        },
        'name': 'SEM_RESULTS_LOWER_OFFSET_MARGIN_FREQUENCY',
        'type': 'float64'
    },
    1081405: {
        'access': 'read-write',
        'documentation': {
            'description': " Indicates the lower offset segment measurement status based on measurement limits and the fail criteria that you specify in the RFMXSPECAN_ATTR_SEM_OFFSET_LIMIT_FAIL_MASK attribute.        \n\nUse 'offset(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_SEMGetResultsLowerOffsetMeasurementStatus\n"
        },
        'enum': 'SemLowerOffsetMeasurementStatus',
        'name': 'SEM_RESULTS_LOWER_OFFSET_MEASUREMENT_STATUS',
        'type': 'int32'
    },
    1081406: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the start frequency of the upper (positive) offset segment. This value is expressed in Hz.        \n\nUse 'offset(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_SEMGetResultsUpperOffsetStartFrequency\n"
        },
        'name': 'SEM_RESULTS_UPPER_OFFSET_START_FREQUENCY',
        'type': 'float64'
    },
    1081407: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the stop frequency of the upper (positive) offset segment. This value is expressed in Hz.        \n\nUse 'offset(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_SEMGetResultsUpperOffsetStopFrequency\n"
        },
        'name': 'SEM_RESULTS_UPPER_OFFSET_STOP_FREQUENCY',
        'type': 'float64'
    },
    1081408: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the index of the carrier that was used as the power reference to define the upper (positive) offset segment relative power. The reference carrier is the carrier that has an offset closest to the offset segment.        \n\nUse 'offset(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_SEMGetResultsUpperOffsetPowerReferenceCarrier\n"
        },
        'name': 'SEM_RESULTS_UPPER_OFFSET_POWER_REFERENCE_CARRIER',
        'type': 'int32'
    },
    1081409: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the offset segment power measured in the upper (positive) offset segment.\n \nThe power is reported in dBm when you set the RFMXSPECAN_ATTR_SEM_POWER_UNITS attribute to RFMXSPECAN_VAL_SEM_POWER_UNITS_DBM, and in dBm/Hz when you set the RFMXSPECAN_ATTR_SEM_POWER_UNITS attribute to RFMXSPECAN_VAL_SEM_POWER_UNITS_DBM_PER_HZ.        \n\nUse 'offset(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_SEMGetResultsUpperOffsetTotalAbsolutePower\n"
        },
        'name': 'SEM_RESULTS_UPPER_OFFSET_TOTAL_ABSOLUTE_POWER',
        'type': 'float64'
    },
    1081410: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the power measured in the upper (positive) offset segment relative to the integrated or peak power of the reference carrier.        \n\n When you set the RFMXSPECAN_ATTR_SEM_REFERENCE_TYPE attribute to RFMXSPECAN_VAL_SEM_REFERENCE_TYPE_INTEGRATION, the reference carrier power is the total power in the reference carrier. When you set the RFMXSPECAN_ATTR_SEM_REFERENCE_TYPE attribute to RFMXSPECAN_VAL_SEM_REFERENCE_TYPE_PEAK, the reference carrier power is the peak power in the reference.        \n\nUse 'offset(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_SEMGetResultsUpperOffsetTotalRelativePower\n"
        },
        'name': 'SEM_RESULTS_UPPER_OFFSET_TOTAL_RELATIVE_POWER',
        'type': 'float64'
    },
    1081411: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the peak power measured in the upper (positive) offset segment.\n \nThe power is reported in dBm when you set the RFMXSPECAN_ATTR_SEM_POWER_UNITS attribute to RFMXSPECAN_VAL_SEM_POWER_UNITS_DBM, and in dBm/Hz when you set the RFMXSPECAN_ATTR_SEM_POWER_UNITS attribute to RFMXSPECAN_VAL_SEM_POWER_UNITS_DBM_PER_HZ.        \n\nUse 'offset(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_SEMGetResultsUpperOffsetPeakAbsolutePower\n"
        },
        'name': 'SEM_RESULTS_UPPER_OFFSET_PEAK_ABSOLUTE_POWER',
        'type': 'float64'
    },
    1081412: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the peak power measured in the upper (positive) offset segment relative to the integrated or peak power of the reference carrier.         \n\nWhen you set the RFMXSPECAN_ATTR_SEM_REFERENCE_TYPE attribute to RFMXSPECAN_VAL_SEM_REFERENCE_TYPE_INTEGRATION, the reference carrier power is the total power in the reference carrier. When you set the RFMXSPECAN_ATTR_SEM_REFERENCE_TYPE attribute to RFMXSPECAN_VAL_SEM_REFERENCE_TYPE_PEAK, the reference carrier power is the peak power in the reference carrier.        \n\nUse 'offset(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_SEMGetResultsUpperOffsetPeakRelativePower\n"
        },
        'name': 'SEM_RESULTS_UPPER_OFFSET_PEAK_RELATIVE_POWER',
        'type': 'float64'
    },
    1081413: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the frequency at which the peak power occurred in the upper offset segment. This value is expressed in Hz.        \n\nUse 'offset(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_SEMGetResultsUpperOffsetPeakFrequency\n"
        },
        'name': 'SEM_RESULTS_UPPER_OFFSET_PEAK_FREQUENCY',
        'type': 'float64'
    },
    1081414: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the margin from the limit mask value that you set in the RFMXSPECAN_ATTR_SEM_OFFSET_LIMIT_FAIL_MASK attribute. This value is expressed in dB. Margin is defined as the maximum difference between the spectrum and the limit mask.\n \nWhen you set the RFMXSPECAN_ATTR_SEM_OFFSET_LIMIT_FAIL_MASK attribute to Absolute, the margin is with reference to the absolute limit mask.        \n\nWhen you set the RFMXSPECAN_ATTR_SEM_OFFSET_LIMIT_FAIL_MASK attribute to Relative, the margin is with reference to the relative limit mask.        \n\nWhen you set the RFMXSPECAN_ATTR_SEM_OFFSET_LIMIT_FAIL_MASK attribute to Abs AND Rel, the margin is the maximum of the margin referenced to the absolute and relative limit masks.        \n\nWhen you set the RFMXSPECAN_ATTR_SEM_OFFSET_LIMIT_FAIL_MASK attribute to Abs OR Rel, the margin is the minimum of the margin referenced to the absolute and relative limit masks.        \n\nUse 'offset(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_SEMGetResultsUpperOffsetMargin\n"
        },
        'name': 'SEM_RESULTS_UPPER_OFFSET_MARGIN',
        'type': 'float64'
    },
    1081415: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the power, at which the margin occurred in the upper (positive) offset segment.\n \nThe power is reported in dBm when you set the RFMXSPECAN_ATTR_SEM_POWER_UNITS attribute to RFMXSPECAN_VAL_SEM_POWER_UNITS_DBM, and in dBm/Hz when you set the RFMXSPECAN_ATTR_SEM_POWER_UNITS attribute to RFMXSPECAN_VAL_SEM_POWER_UNITS_DBM_PER_HZ.        \n\nUse 'offset(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_SEMGetResultsUpperOffsetMarginAbsolutePower\n"
        },
        'name': 'SEM_RESULTS_UPPER_OFFSET_MARGIN_ABSOLUTE_POWER',
        'type': 'float64'
    },
    1081416: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the power at which the margin occurred in the upper (positive) offset segment relative to the integrated or peak power of the reference carrier. This value is expressed in dB.        \n\nUse 'offset(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_SEMGetResultsUpperOffsetMarginRelativePower\n"
        },
        'name': 'SEM_RESULTS_UPPER_OFFSET_MARGIN_RELATIVE_POWER',
        'type': 'float64'
    },
    1081417: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the frequency at which the margin occurred in the upper (positive)  offset. This value is expressed in Hz.        \n\nUse 'offset(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_SEMGetResultsUpperOffsetMarginFrequency\n"
        },
        'name': 'SEM_RESULTS_UPPER_OFFSET_MARGIN_FREQUENCY',
        'type': 'float64'
    },
    1081418: {
        'access': 'read-write',
        'documentation': {
            'description': " Indicates the upper offset measurement status based on measurement limits and the fail criteria that you specify in the RFMXSPECAN_ATTR_SEM_OFFSET_LIMIT_FAIL_MASK attribute.        \n\nUse 'offset(n)' as the selector string to read this result.\n \n\n \nGet Function: RFmxSpecAn_SEMGetResultsUpperOffsetMeasurementStatus\n"
        },
        'enum': 'SemUpperOffsetMeasurementStatus',
        'name': 'SEM_RESULTS_UPPER_OFFSET_MEASUREMENT_STATUS',
        'type': 'int32'
    },
    1081419: {
        'access': 'read-write',
        'documentation': {
            'description': " specifies the channel bandwidth of the carrier. This parameter is used to calculate the values of the RFMXSPECAN_ATTR_SEM_OFFSET_START_FREQUENCY and RFMXSPECAN_ATTR_SEM_OFFSET_STOP_FREQUENCY attributes when you set the RFMXSPECAN_ATTR_SEM_OFFSET_FREQUENCY_DEFINITION attribute to RFMXSPECAN_VAL_SEM_CARRIER_EDGE_TO_MEASUREMENT_BANDWIDTH_CENTER or RFMXSPECAN_VAL_SEM_CARRIER_EDGE_TO_MEASUREMENT_BANDWIDTH_EDGE.         \n\nUse 'carrier(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 2 MHz.\n \nGet Function: RFmxSpecAn_SEMGetCarrierChannelBandwidth\n Set Function: RFmxSpecAn_SEMSetCarrierChannelBandwidth\n"
        },
        'name': 'SEM_CARRIER_CHANNEL_BANDWIDTH',
        'type': 'float64'
    },
    1081420: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the definition of  the start frequency and stop frequency of the offset segments from the nearest carrier channels.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is  Carrier Center to Meas BW Center.\n \nGet Function: RFmxSpecAn_SEMGetOffsetFrequencyDefinition\n Set Function: RFmxSpecAn_SEMSetOffsetFrequencyDefinition\n"
        },
        'enum': 'SemOffsetFrequencyDefinition',
        'name': 'SEM_OFFSET_FREQUENCY_DEFINITION',
        'type': 'int32'
    },
    1081421: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the bandwidth definition which you use to specify the value of the RFMXSPECAN_ATTR_SEM_OFFSET_RBW_FILTER_BANDWIDTH attribute.        \n\nUse 'offset(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_SEM_OFFSET_RBW_FILTER_BANDWIDTH_DEFINITION_3DB.\n \nGet Function: RFmxSpecAn_SEMGetOffsetRBWFilterBandwidthDefinition\n Set Function: RFmxSpecAn_SEMSetOffsetRBWFilterBandwidthDefinition\n"
        },
        'enum': 'SemOffsetRbwFilterBandwidthDefinition',
        'name': 'SEM_OFFSET_RBW_FILTER_BANDWIDTH_DEFINITION',
        'type': 'int32'
    },
    1081422: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the bandwidth definition that you use to specify the value of the RFMXSPECAN_ATTR_SEM_CARRIER_RBW_FILTER_BANDWIDTH attribute.        \n\nUse 'carrier(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_SEM_CARRIER_RBW_FILTER_BANDWIDTH_DEFINITION_3DB.\n \nGet Function: RFmxSpecAn_SEMGetCarrierRBWFilterBandwidthDefinition\n Set Function: RFmxSpecAn_SEMSetCarrierRBWFilterBandwidthDefinition\n"
        },
        'enum': 'SemCarrierRbwFilterBandwidthDefinition',
        'name': 'SEM_CARRIER_RBW_FILTER_BANDWIDTH_DEFINITION',
        'type': 'int32'
    },
    1081423: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the amplitude of the frequency bins, used in the measurement, is corrected for external attenuation at the RF center frequency, or at the individual frequency bins. Use the RFmxInstr_CfgExternalAttenuationTable function to configure the external attenuation table.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SEM_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY.\n \nGet Function: RFmxSpecAn_SEMGetAmplitudeCorrectionType\n Set Function: RFmxSpecAn_SEMSetAmplitudeCorrectionType\n'
        },
        'enum': 'SemAmplitudeCorrectionType',
        'name': 'SEM_AMPLITUDE_CORRECTION_TYPE',
        'type': 'int32'
    },
    1085440: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the spectrum measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_SpectrumGetMeasurementEnabled\n Set Function: RFmxSpecAn_SpectrumSetMeasurementEnabled\n'
        },
        'name': 'SPECTRUM_MEASUREMENT_ENABLED',
        'type': 'int32'
    },
    1085442: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum number of threads used for parallelism for spectrum measurement.\n \nThe number of threads can range from 1 to the number of physical cores. The number of threads you set may not be used in calculations. The actual number of threads used depends on the problem size, system resources, data availability, and other considerations.         \n\nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_SpectrumGetNumberOfAnalysisThreads\n Set Function: RFmxSpecAn_SpectrumSetNumberOfAnalysisThreads\n'
        },
        'name': 'SPECTRUM_NUMBER_OF_ANALYSIS_THREADS',
        'type': 'int32'
    },
    1085443: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the frequency range around the center frequency, to acquire for the measurement. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1 MHz.\n \nGet Function: RFmxSpecAn_SpectrumGetSpan\n Set Function: RFmxSpecAn_SpectrumSetSpan\n'
        },
        'name': 'SPECTRUM_SPAN',
        'type': 'float64'
    },
    1085445: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of acquisitions used for averaging when you set the RFMXSPECAN_ATTR_SPECTRUM_AVERAGING_ENABLED attribute to RFMXSPECAN_VAL_SPECTRUM_AVERAGING_ENABLED_TRUE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10.\n \nGet Function: RFmxSpecAn_SpectrumGetAveragingCount\n Set Function: RFmxSpecAn_SpectrumSetAveragingCount\n'
        },
        'name': 'SPECTRUM_AVERAGING_COUNT',
        'type': 'int32'
    },
    1085446: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable averaging for the spectrum measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SPECTRUM_AVERAGING_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_SpectrumGetAveragingEnabled\n Set Function: RFmxSpecAn_SpectrumSetAveragingEnabled\n'
        },
        'enum': 'SpectrumAveragingEnabled',
        'name': 'SPECTRUM_AVERAGING_ENABLED',
        'type': 'int32'
    },
    1085448: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the averaging type for averaging multiple spectrum acquisitions. The averaged spectrum is used for spectrum measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SPECTRUM_AVERAGING_TYPE_RMS.\n \nGet Function: RFmxSpecAn_SpectrumGetAveragingType\n Set Function: RFmxSpecAn_SpectrumSetAveragingType\n'
        },
        'enum': 'SpectrumAveragingType',
        'name': 'SPECTRUM_AVERAGING_TYPE',
        'type': 'int32'
    },
    1085449: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the FFT window type to use to reduce spectral leakage.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SPECTRUM_FFT_WINDOW_FLAT_TOP.\n \nGet Function: RFmxSpecAn_SpectrumGetFFTWindow\n Set Function: RFmxSpecAn_SpectrumSetFFTWindow\n'
        },
        'enum': 'SpectrumFftWindow',
        'name': 'SPECTRUM_FFT_WINDOW',
        'type': 'int32'
    },
    1085450: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the factor by which the time-domain waveform is zero-padded before FFT. The FFT size is given by the following formula:        \n\nwaveform size * padding        \n\nThis attribute is used only when the acquisition span is less than the device instantaneous bandwidth of the device.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is -1.\n \nGet Function: RFmxSpecAn_SpectrumGetFFTPadding\n Set Function: RFmxSpecAn_SpectrumSetFFTPadding\n'
        },
        'name': 'SPECTRUM_FFT_PADDING',
        'type': 'float64'
    },
    1085451: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the measurement computes the resolution bandwidth (RBW).\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SPECTRUM_RBW_AUTO_TRUE.\n \nGet Function: RFmxSpecAn_SpectrumGetRBWFilterAutoBandwidth\n Set Function: RFmxSpecAn_SpectrumSetRBWFilterAutoBandwidth\n'
        },
        'enum': 'SpectrumRbwAutoBandwidth',
        'name': 'SPECTRUM_RBW_FILTER_AUTO_BANDWIDTH',
        'type': 'int32'
    },
    1085452: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the bandwidth of the resolution bandwidth (RBW) filter used to sweep the acquired signal, when you set the RFMXSPECAN_ATTR_SPECTRUM_RBW_FILTER_AUTO_BANDWIDTH attribute to RFMXSPECAN_VAL_SPECTRUM_RBW_AUTO_FALSE. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10 kHz.\n \nGet Function: RFmxSpecAn_SpectrumGetRBWFilterBandwidth\n Set Function: RFmxSpecAn_SpectrumSetRBWFilterBandwidth\n'
        },
        'name': 'SPECTRUM_RBW_FILTER_BANDWIDTH',
        'type': 'float64'
    },
    1085453: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the shape of the digital resolution bandwidth (RBW) filter.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SPECTRUM_RBW_FILTER_TYPE_GAUSSIAN.\n \nGet Function: RFmxSpecAn_SpectrumGetRBWFilterType\n Set Function: RFmxSpecAn_SpectrumSetRBWFilterType\n'
        },
        'enum': 'SpectrumRbwFilterType',
        'name': 'SPECTRUM_RBW_FILTER_TYPE',
        'type': 'int32'
    },
    1085454: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the measurement computes the sweep time.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SPECTRUM_SWEEP_TIME_AUTO_TRUE.\n \nGet Function: RFmxSpecAn_SpectrumGetSweepTimeAuto\n Set Function: RFmxSpecAn_SpectrumSetSweepTimeAuto\n'
        },
        'enum': 'SpectrumSweepTimeAuto',
        'name': 'SPECTRUM_SWEEP_TIME_AUTO',
        'type': 'int32'
    },
    1085455: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the sweep time when you set the RFMXSPECAN_ATTR_SPECTRUM_SWEEP_TIME_AUTO attribute to RFMXSPECAN_VAL_SPECTRUM_SWEEP_TIME_AUTO_FALSE. This value is expressed in seconds.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.001.\n \nGet Function: RFmxSpecAn_SpectrumGetSweepTimeInterval\n Set Function: RFmxSpecAn_SpectrumSetSweepTimeInterval\n'
        },
        'name': 'SPECTRUM_SWEEP_TIME_INTERVAL',
        'type': 'float64'
    },
    1085456: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether RFmx compensates for the instrument noise while performing the measurement when you set the RFMXSPECAN_ATTR_SPECTRUM_NOISE_CALIBRATION_MODE attribute to RFMXSPECAN_VAL_SPECTRUM_NOISE_CALIBRATION_MODE_AUTO, or when you set the RFMXSPECAN_ATTR_SPECTRUM_NOISE_CALIBRATION_MODE attribute to RFMXSPECAN_VAL_SPECTRUM_NOISE_CALIBRATION_MODE_MANUAL and RFMXSPECAN_ATTR_SPECTRUM_MEASUREMENT_MODE to RFMXSPECAN_VAL_SPECTRUM_MEASUREMENT_MODE_MEASURE. Refer to the Noise Compensation Algorithm topic for more information.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SPECTRUM_NOISE_COMPENSATION_ENABLED_FALSE.        \n\n   Supported Devices: PXIe-5663/5665/5668, PXIe-5830/5831/5832\n \nGet Function: RFmxSpecAn_SpectrumGetNoiseCompensationEnabled\n Set Function: RFmxSpecAn_SpectrumSetNoiseCompensationEnabled\n'
        },
        'enum': 'SpectrumNoiseCompensationEnabled',
        'name': 'SPECTRUM_NOISE_COMPENSATION_ENABLED',
        'type': 'int32'
    },
    1085458: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the peak amplitude, of the averaged spectrum.\n \nWhen you set the RFMXSPECAN_ATTR_SPECTRUM_SPAN attribute to 0, the measurement returns the peak amplitude in the time domain power trace.        \n\nThe amplitude is reported in units specified by the value of the RFMXSPECAN_ATTR_SPECTRUM_POWER_UNITS attribute.         \n\nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_SpectrumGetResultsPeakAmplitude\n'
        },
        'name': 'SPECTRUM_RESULTS_PEAK_AMPLITUDE',
        'type': 'float64'
    },
    1085459: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the frequency at the peak amplitude of the averaged spectrum. This value is expressed in Hz. This attribute is not valid if you set the RFMXSPECAN_ATTR_SPECTRUM_SPAN attribute to 0.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_SpectrumGetResultsPeakFrequency\n'
        },
        'name': 'SPECTRUM_RESULTS_PEAK_FREQUENCY',
        'type': 'float64'
    },
    1085460: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the frequency bin spacing of the spectrum acquired by the measurement. This value is expressed in Hz. This attribute is not valid if you set the RFMXSPECAN_ATTR_SPECTRUM_SPAN attribute to 0.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_SpectrumGetResultsFrequencyResolution\n'
        },
        'name': 'SPECTRUM_RESULTS_FREQUENCY_RESOLUTION',
        'type': 'float64'
    },
    1085461: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the units for the absolute power.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SPECTRUM_POWER_UNITS_DBM_PER_HZ.\n \nGet Function: RFmxSpecAn_SpectrumGetPowerUnits\n Set Function: RFmxSpecAn_SpectrumSetPowerUnits\n'
        },
        'enum': 'SpectrumPowerUnits',
        'name': 'SPECTRUM_POWER_UNITS',
        'type': 'int32'
    },
    1085462: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the bandwidth definition which you use to specify the value of the RFMXSPECAN_ATTR_SPECTRUM_RBW_FILTER_BANDWIDTH attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_SPECTRUM_RBW_FILTER_BANDWIDTH_DEFINITION_3DB.\n \nGet Function: RFmxSpecAn_SpectrumGetRBWFilterBandwidthDefinition\n Set Function: RFmxSpecAn_SpectrumSetRBWFilterBandwidthDefinition\n'
        },
        'enum': 'SpectrumRbwFilterBandwidthDefinition',
        'name': 'SPECTRUM_RBW_FILTER_BANDWIDTH_DEFINITION',
        'type': 'int32'
    },
    1085463: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the amplitude of the frequency bins, used in the measurement, is corrected for external attenuation at the RF center frequency, or at the individual frequency bins. Use the RFmxInstr_CfgExternalAttenuationTable function to configure the external attenuation table.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SPECTRUM_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY.\n \nGet Function: RFmxSpecAn_SpectrumGetAmplitudeCorrectionType\n Set Function: RFmxSpecAn_SpectrumSetAmplitudeCorrectionType\n'
        },
        'enum': 'SpectrumAmplitudeCorrectionType',
        'name': 'SPECTRUM_AMPLITUDE_CORRECTION_TYPE',
        'type': 'int32'
    },
    1085464: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the type of detector to be used.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SPECTRUM_DETECTOR_TYPE_NONE.        \n\nRefer to Spectral Measurements topic for more information on detector types.\n \nGet Function: RFmxSpecAn_SpectrumGetDetectorType\n Set Function: RFmxSpecAn_SpectrumSetDetectorType\n'
        },
        'enum': 'SpectrumDetectorType',
        'name': 'SPECTRUM_DETECTOR_TYPE',
        'type': 'int32'
    },
    1085465: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of trace points after the detector is applied.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1001.\n \nGet Function: RFmxSpecAn_SpectrumGetDetectorPoints\n Set Function: RFmxSpecAn_SpectrumSetDetectorPoints\n'
        },
        'name': 'SPECTRUM_DETECTOR_POINTS',
        'type': 'int32'
    },
    1085466: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the video bandwidth (VBW) is expressed directly or computed based on the VBW to RBW ratio.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SPECTRUM_VBW_FILTER_AUTO_BANDWIDTH_True.\n \nGet Function: RFmxSpecAn_SpectrumGetVBWFilterAutoBandwidth\n Set Function: RFmxSpecAn_SpectrumSetVBWFilterAutoBandwidth\n'
        },
        'enum': 'SpectrumVbwFilterAutoBandwidth',
        'name': 'SPECTRUM_VBW_FILTER_AUTO_BANDWIDTH',
        'type': 'int32'
    },
    1085467: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the video bandwidth (VBW) in Hz when you set the RFMXSPECAN_ATTR_SPECTRUM_VBW_FILTER_AUTO_BANDWIDTH attribute to RFMXSPECAN_VAL_SPECTRUM_VBW_FILTER_AUTO_BANDWIDTH_False.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 30000.\n \nGet Function: RFmxSpecAn_SpectrumGetVBWFilterBandwidth\n Set Function: RFmxSpecAn_SpectrumSetVBWFilterBandwidth\n'
        },
        'name': 'SPECTRUM_VBW_FILTER_BANDWIDTH',
        'type': 'float64'
    },
    1085468: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the VBW to RBW Ratio when you set the RFMXSPECAN_ATTR_SPECTRUM_VBW_FILTER_AUTO_BANDWIDTH attribute to RFMXSPECAN_VAL_SPECTRUM_VBW_FILTER_AUTO_BANDWIDTH_True .\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 3.\n \nGet Function: RFmxSpecAn_SpectrumGetVBWFilterVBWToRBWRatio\n Set Function: RFmxSpecAn_SpectrumSetVBWFilterVBWToRBWRatio\n'
        },
        'name': 'SPECTRUM_VBW_FILTER_VBW_TO_RBW_RATIO',
        'type': 'float64'
    },
    1085470: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the measurement calibrates the noise floor of analyzer or performs the spectrum measurement. Refer to the measurement guidelines section in the Noise Compensation Algorithm topic for more information.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SPECTRUM_MEASUREMENT_MODE_MEASURE.\n \nGet Function: RFmxSpecAn_SpectrumGetMeasurementMode\n Set Function: RFmxSpecAn_SpectrumSetMeasurementMode\n'
        },
        'enum': 'SpectrumMeasurementMode',
        'name': 'SPECTRUM_MEASUREMENT_MODE',
        'type': 'int32'
    },
    1085471: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the noise compensation type. Refer to the Noise Compensation Algorithm topic for more information.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SPECTRUM_NOISE_COMPENSATION_TYPE_ANALYZER_AND_TERMINATION.\n \nGet Function: RFmxSpecAn_SpectrumGetNoiseCompensationType\n Set Function: RFmxSpecAn_SpectrumSetNoiseCompensationType\n'
        },
        'enum': 'SpectrumNoiseCompensationType',
        'name': 'SPECTRUM_NOISE_COMPENSATION_TYPE',
        'type': 'int32'
    },
    1085472: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the averaging count used for noise calibration when you set the RFMXSPECAN_ATTR_SPECTRUM_NOISE_CALIBRATION_AVERAGING_AUTO  attribute to RFMXSPECAN_VAL_SPECTRUM_NOISE_CALIBRATION_AVERAGING_AUTO_FALSE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 32.\n \nGet Function: RFmxSpecAn_SpectrumGetNoiseCalibrationAveragingCount\n Set Function: RFmxSpecAn_SpectrumSetNoiseCalibrationAveragingCount\n'
        },
        'name': 'SPECTRUM_NOISE_CALIBRATION_AVERAGING_COUNT',
        'type': 'int32'
    },
    1085473: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether RFmx automatically computes the averaging count used for instrument noise calibration.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SPECTRUM_NOISE_CALIBRATION_AVERAGING_AUTO_TRUE.\n \nGet Function: RFmxSpecAn_SpectrumGetNoiseCalibrationAveragingAuto\n Set Function: RFmxSpecAn_SpectrumSetNoiseCalibrationAveragingAuto\n'
        },
        'enum': 'SpectrumNoiseCalibrationAveragingAuto',
        'name': 'SPECTRUM_NOISE_CALIBRATION_AVERAGING_AUTO',
        'type': 'int32'
    },
    1085474: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the noise calibration and measurement is performed manually by the user or automatically by RFmx. Refer to the measurement guidelines section in the Noise Compensation Algorithm topic for more information.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SPECTRUM_NOISE_CALIBRATION_MODE_AUTO.\n \nGet Function: RFmxSpecAn_SpectrumGetNoiseCalibrationMode\n Set Function: RFmxSpecAn_SpectrumSetNoiseCalibrationMode\n'
        },
        'enum': 'SpectrumNoiseCalibrationMode',
        'name': 'SPECTRUM_NOISE_CALIBRATION_MODE',
        'type': 'int32'
    },
    1085475: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to analyze just the real I or Q component of the acquired IQ data, or analyze the complex IQ data.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SPECTRUM_ANALYSIS_INPUT_IQ.\n \nGet Function: RFmxSpecAn_SpectrumGetAnalysisInput\n Set Function: RFmxSpecAn_SpectrumSetAnalysisInput\n'
        },
        'enum': 'SpectrumAnalysisInput',
        'name': 'SPECTRUM_ANALYSIS_INPUT',
        'type': 'int32'
    },
    1089536: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the spurious emission (Spur) measurement.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nThe default value is RFMXSPECAN_VAL_FALSE.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetMeasurementEnabled\n Set Function: RFmxSpecAn_SpurSetMeasurementEnabled\n'
        },
        'name': 'SPUR_MEASUREMENT_ENABLED',
        'type': 'int32'
    },
    1089539: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum number of threads used for parallelism for spurious emission (Spur) measurement.\n \nThe number of threads can range from 1 to the number of physical cores. The number of threads you set may not be used in calculations. The actual number of threads used depends on the problem size, system resources, data availability, and other considerations.         \n\nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetNumberOfAnalysisThreads\n Set Function: RFmxSpecAn_SpurSetNumberOfAnalysisThreads\n'
        },
        'name': 'SPUR_NUMBER_OF_ANALYSIS_THREADS',
        'type': 'int32'
    },
    1089540: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of ranges.        \n\nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \n\n \nThe default value is 1.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetNumberOfRanges\n Set Function: RFmxSpecAn_SpurSetNumberOfRanges\n'
        },
        'name': 'SPUR_NUMBER_OF_RANGES',
        'type': 'int32'
    },
    1089541: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies whether to measure the spurious emissions (Spur) in the frequency range.        \n\nUse 'range(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_SPUR_RANGE_ENABLED_TRUE.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetRangeEnabled\n Set Function: RFmxSpecAn_SpurSetRangeEnabled\n"
        },
        'enum': 'SpurRangeEnabled',
        'name': 'SPUR_RANGE_ENABLED',
        'type': 'int32'
    },
    1089542: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the attenuation relative to the external attenuation specified by the RFMXSPECAN_ATTR_EXTERNAL_ATTENUATION attribute. This value is expressed in dB. Use the Spur Range Rel Attn attribute to compensate for the variations in external attenuation when offset segments are spread wide in frequency.        \n\nUse 'range(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 0.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetRangeRelativeAttenuation\n Set Function: RFmxSpecAn_SpurSetRangeRelativeAttenuation\n"
        },
        'name': 'SPUR_RANGE_RELATIVE_ATTENUATION',
        'type': 'float64'
    },
    1089543: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the number of spurious emissions (Spur) that the measurement should report in the frequency range.        \n\nUse 'range(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 10.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetRangeNumberOfSpursToReport\n Set Function: RFmxSpecAn_SpurSetRangeNumberOfSpursToReport\n"
        },
        'name': 'SPUR_RANGE_NUMBER_OF_SPURS_TO_REPORT',
        'type': 'int32'
    },
    1089544: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the start of the frequency range for the measurement. This value is expressed in Hz.        \n\nUse 'range(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 500 MHz.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetRangeStartFrequency\n Set Function: RFmxSpecAn_SpurSetRangeStartFrequency\n"
        },
        'name': 'SPUR_RANGE_START_FREQUENCY',
        'type': 'float64'
    },
    1089545: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the stop of the frequency range for the measurement. This value is expressed in Hz.        \n\nUse 'range(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 1.5 GHz.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetRangeStopFrequency\n Set Function: RFmxSpecAn_SpurSetRangeStopFrequency\n"
        },
        'name': 'SPUR_RANGE_STOP_FREQUENCY',
        'type': 'float64'
    },
    1089546: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of acquisitions used for averaging when you set the RFMXSPECAN_ATTR_SPUR_AVERAGING_ENABLED attribute to RFMXSPECAN_VAL_SPUR_AVERAGING_ENABLED_TRUE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetAveragingCount\n Set Function: RFmxSpecAn_SpurSetAveragingCount\n'
        },
        'name': 'SPUR_AVERAGING_COUNT',
        'type': 'int32'
    },
    1089547: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable averaging for the spurious emission (Spur) measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SPUR_AVERAGING_ENABLED_FALSE.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetAveragingEnabled\n Set Function: RFmxSpecAn_SpurSetAveragingEnabled\n'
        },
        'enum': 'SpurAveragingEnabled',
        'name': 'SPUR_AVERAGING_ENABLED',
        'type': 'int32'
    },
    1089549: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the averaging type for averaging multiple spectrum acquisitions. The averaged spectrum is used for spurious emission (Spur) measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SPUR_AVERAGING_TYPE_RMS.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetAveragingType\n Set Function: RFmxSpecAn_SpurSetAveragingType\n'
        },
        'enum': 'SpurAveragingType',
        'name': 'SPUR_AVERAGING_TYPE',
        'type': 'int32'
    },
    1089551: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the FFT window type to use to reduce spectral leakage.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SPUR_FFT_WINDOW_FLAT_TOP.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetFFTWindow\n Set Function: RFmxSpecAn_SpurSetFFTWindow\n'
        },
        'enum': 'SpurFftWindow',
        'name': 'SPUR_FFT_WINDOW',
        'type': 'int32'
    },
    1089552: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies whether the absolute limit threshold is a flat line or a line with a slope.        \n\nUse 'range(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_SPUR_ABSOLUTE_LIMIT_MODE_COUPLE.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetRangeAbsoluteLimitMode\n Set Function: RFmxSpecAn_SpurSetRangeAbsoluteLimitMode\n"
        },
        'enum': 'SpurAbsoluteLimitMode',
        'name': 'SPUR_RANGE_ABSOLUTE_LIMIT_MODE',
        'type': 'int32'
    },
    1089553: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the absolute power limit corresponding to the beginning of the frequency range. This value is expressed in dBm. This power limit is also set as the absolute power limit for the range when you set the RFMXSPECAN_ATTR_SPUR_RANGE_ABSOLUTE_LIMIT_MODE attribute to RFMXSPECAN_VAL_SPUR_ABSOLUTE_LIMIT_MODE_COUPLE.        \n\nUse 'range(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is -10.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetRangeAbsoluteLimitStart\n Set Function: RFmxSpecAn_SpurSetRangeAbsoluteLimitStart\n"
        },
        'name': 'SPUR_RANGE_ABSOLUTE_LIMIT_START',
        'type': 'float64'
    },
    1089554: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the absolute power limit corresponding to the end of the frequency range. This value is expressed in dBm. The measurement ignores this attribute when you set the RFMXSPECAN_ATTR_SPUR_RANGE_ABSOLUTE_LIMIT_MODE attribute to RFMXSPECAN_VAL_SPUR_ABSOLUTE_LIMIT_MODE_COUPLE.        \n\nUse 'range(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is -10.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetRangeAbsoluteLimitStop\n Set Function: RFmxSpecAn_SpurSetRangeAbsoluteLimitStop\n"
        },
        'name': 'SPUR_RANGE_ABSOLUTE_LIMIT_STOP',
        'type': 'float64'
    },
    1089555: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies whether the measurement computes the resolution bandwidth (RBW).         \n\nUse 'range(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_SPUR_RBW_AUTO_TRUE.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetRangeRBWFilterAutoBandwidth\n Set Function: RFmxSpecAn_SpurSetRangeRBWFilterAutoBandwidth\n"
        },
        'enum': 'SpurRbwAutoBandwidth',
        'name': 'SPUR_RANGE_RBW_FILTER_AUTO_BANDWIDTH',
        'type': 'int32'
    },
    1089556: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the bandwidth of the resolution bandwidth (RBW) filter used to sweep the acquired signal, when you set the RFMXSPECAN_ATTR_SPUR_RANGE_RBW_FILTER_AUTO_BANDWIDTH attribute to False.        \n\nUse 'range(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 10 kHz.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetRangeRBWFilterBandwidth\n Set Function: RFmxSpecAn_SpurSetRangeRBWFilterBandwidth\n"
        },
        'name': 'SPUR_RANGE_RBW_FILTER_BANDWIDTH',
        'type': 'float64'
    },
    1089557: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the shape of the digital resolution bandwidth (RBW) filter.        \n\nUse 'range(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_SPUR_RBW_FILTER_TYPE_GAUSSIAN.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetRangeRBWFilterType\n Set Function: RFmxSpecAn_SpurSetRangeRBWFilterType\n"
        },
        'enum': 'SpurRbwFilterType',
        'name': 'SPUR_RANGE_RBW_FILTER_TYPE',
        'type': 'int32'
    },
    1089558: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies whether the measurement computes the sweep time.        \n\nUse 'range(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_SPUR_SWEEP_TIME_AUTO_TRUE.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetRangeSweepTimeAuto\n Set Function: RFmxSpecAn_SpurSetRangeSweepTimeAuto\n"
        },
        'enum': 'SpurSweepTimeAuto',
        'name': 'SPUR_RANGE_SWEEP_TIME_AUTO',
        'type': 'int32'
    },
    1089559: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the sweep time when you set the RFMXSPECAN_ATTR_SPUR_RANGE_SWEEP_TIME_AUTO attribute to RFMXSPECAN_VAL_SPUR_SWEEP_TIME_AUTO_FALSE. This value is expressed in seconds.        \n\nUse 'range(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 0.001.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetRangeSweepTimeInterval\n Set Function: RFmxSpecAn_SpurSetRangeSweepTimeInterval\n"
        },
        'name': 'SPUR_RANGE_SWEEP_TIME_INTERVAL',
        'type': 'float64'
    },
    1089560: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the traces to be stored and retrieved after performing the spurious emissions (Spur) measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetAllTracesEnabled\n Set Function: RFmxSpecAn_SpurSetAllTracesEnabled\n'
        },
        'name': 'SPUR_ALL_TRACES_ENABLED',
        'type': 'int32'
    },
    1089561: {
        'access': 'read-write',
        'documentation': {
            'description': ' Indicates the overall measurement status.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nSupported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetResultsMeasurementStatus\n'
        },
        'enum': 'SpurMeasurementStatus',
        'name': 'SPUR_RESULTS_MEASUREMENT_STATUS',
        'type': 'int32'
    },
    1089562: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the frequency of the detected spurious emissions (Spur). This value is expressed in Hz.        \n\nUse 'range(n)/spur(k)' as the selector string to read this result.\n \n\n \nSupported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetResultsRangeFrequency\n"
        },
        'name': 'SPUR_RESULTS_RANGE_FREQUENCY',
        'type': 'float64'
    },
    1089563: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the amplitude of the detected spurious emissions (Spur). This value is expressed in dBm.        \n\nUse 'range(n)/spur(k)' as the selector string to read this result.\n \n\n \nSupported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetResultsRangeAmplitude\n"
        },
        'name': 'SPUR_RESULTS_RANGE_AMPLITUDE',
        'type': 'float64'
    },
    1089564: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the threshold used to calculate the margin of the detected spurious emissions (Spur). This value is expressed in dBm. The measurement calculates the threshold using the absolute limit line specified by the RFMXSPECAN_ATTR_SPUR_RANGE_ABSOLUTE_LIMIT_MODE attribute.        \n\nUse 'range(n)/spur(k)' as the selector string to read this result.\n \n\n \nSupported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetResultsRangeAbsoluteLimit\n"
        },
        'name': 'SPUR_RESULTS_RANGE_ABSOLUTE_LIMIT',
        'type': 'float64'
    },
    1089565: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the difference between the amplitude and the absolute limit of the detected spurious emissions (Spur) at the Spur frequency.        \n\nUse 'range(n)/spur(k)' as the selector string to read this result.\n \n\n \nSupported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetResultsRangeMargin\n"
        },
        'name': 'SPUR_RESULTS_RANGE_MARGIN',
        'type': 'float64'
    },
    1089566: {
        'access': 'read-write',
        'documentation': {
            'description': " Indicates the measurement status for the frequency range.        \n\nUse 'range(n)' as the selector string to read this result.\n \n\n \nSupported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetResultsRangeMeasurementStatus\n"
        },
        'enum': 'SpurRangeStatus',
        'name': 'SPUR_RESULTS_RANGE_MEASUREMENT_STATUS',
        'type': 'int32'
    },
    1089567: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the number of detected spurious emissions (Spur) in the specified frequency range.        \n\nUse 'range(n)' as the selector string to read this result.\n \n\n \nSupported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetResultsRangeNumberOfDetectedSpurs\n"
        },
        'name': 'SPUR_RESULTS_RANGE_NUMBER_OF_DETECTED_SPURS',
        'type': 'int32'
    },
    1089568: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the index of the range used to store and retrieve spurious emission (Spur) traces. This attribute is not used if you set the Spur All Traces Enabled Attribute to FALSE. When you set this attribute to -1, the measurement stores and retrieves traces for all enabled ranges.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is -1.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetTraceRangeIndex\n Set Function: RFmxSpecAn_SpurSetTraceRangeIndex\n'
        },
        'name': 'SPUR_TRACE_RANGE_INDEX',
        'type': 'int32'
    },
    1089569: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the threshold level above which the measurement detects spurs in the range that you specify using the  RFMXSPECAN_ATTR_SPUR_RANGE_START_FREQUENCY and  RFMXSPECAN_ATTR_SPUR_RANGE_STOP_FREQUENCY attributes. This value is expressed in dBm.        \n\nUse 'range(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is -200.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetRangePeakThreshold\n Set Function: RFmxSpecAn_SpurSetRangePeakThreshold\n"
        },
        'name': 'SPUR_RANGE_PEAK_THRESHOLD',
        'type': 'float64'
    },
    1089570: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the peak excursion value used to find the spurs in the spectrum. This value is expressed in dB. The signal should rise and fall by at least the peak excursion value, above the threshold, to be considered a spur.        \n\nUse 'range(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 0.        \n\n   Supported devices: PXIe-5665/5668\n \nGet Function: RFmxSpecAn_SpurGetRangePeakExcursion\n Set Function: RFmxSpecAn_SpurSetRangePeakExcursion\n"
        },
        'name': 'SPUR_RANGE_PEAK_EXCURSION',
        'type': 'float64'
    },
    1089571: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the bandwidth definition which you use to specify the value of the RFMXSPECAN_ATTR_SPUR_RANGE_RBW_FILTER_BANDWIDTH attribute.        \n\nUse 'range(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is RFMXSPECAN_VAL_SPUR_RANGE_RBW_FILTER_BANDWIDTH_DEFINITION_3DB.\n \nGet Function: RFmxSpecAn_SpurGetRangeRBWFilterBandwidthDefinition\n Set Function: RFmxSpecAn_SpurSetRangeRBWFilterBandwidthDefinition\n"
        },
        'enum': 'SpurRbwFilterBandwidthDefinition',
        'name': 'SPUR_RANGE_RBW_FILTER_BANDWIDTH_DEFINITION',
        'type': 'int32'
    },
    1089572: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the amplitude of the frequency bins, used in the measurement, is corrected for external attenuation at the RF center frequency, or at the individual frequency bins. Use the RFmxInstr_CfgExternalAttenuationTable function to configure the external attenuation table.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_SPUR_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY.\n \nGet Function: RFmxSpecAn_SpurGetAmplitudeCorrectionType\n Set Function: RFmxSpecAn_SpurSetAmplitudeCorrectionType\n'
        },
        'enum': 'SpurAmplitudeCorrectionType',
        'name': 'SPUR_AMPLITUDE_CORRECTION_TYPE',
        'type': 'int32'
    },
    1089573: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the type of detector to be used.        \n\nUse 'range(n)' as the selector string to configure or read this attribute.\n \nRefer to Spectral Measurements topic for more information on detector types.\n \nThe default value is RFMXSPECAN_VAL_SPUR_RANGE_DETECTOR_TYPE_NONE.\n \nGet Function: RFmxSpecAn_SpurGetRangeDetectorType\n Set Function: RFmxSpecAn_SpurSetRangeDetectorType\n"
        },
        'enum': 'SpurRangeDetectorType',
        'name': 'SPUR_RANGE_DETECTOR_TYPE',
        'type': 'int32'
    },
    1089574: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the number of range points after the detector is applied.        \n\nUse 'range(n)' as the selector string to configure or read this attribute.\n \n\n \nThe default value is 1001.\n \nGet Function: RFmxSpecAn_SpurGetRangeDetectorPoints\n Set Function: RFmxSpecAn_SpurSetRangeDetectorPoints\n"
        },
        'name': 'SPUR_RANGE_DETECTOR_POINTS',
        'type': 'int32'
    },
    1089575: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies whether the video bandwidth (VBW) is expressed directly or computed based on the VBW to RBW ratio.\n \nUse 'range(n)' as the selector string to configure or read this attribute.\n \nThe default value is RFMXSPECAN_VAL_SPUR_RANGE_VBW_FILTER_AUTO_BANDWIDTH_TRUE.\n \nGet Function: RFmxSpecAn_SpurGetRangeVBWFilterAutoBandwidth\n Set Function: RFmxSpecAn_SpurSetRangeVBWFilterAutoBandwidth\n"
        },
        'enum': 'SpurRangeVbwFilterAutoBandwidth',
        'name': 'SPUR_RANGE_VBW_FILTER_AUTO_BANDWIDTH',
        'type': 'int32'
    },
    1089576: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the video bandwidth (VBW) in Hz when you set the RFMXSPECAN_ATTR_SPUR_RANGE_VBW_FILTER_AUTO_BANDWIDTH attribute to RFMXSPECAN_VAL_SPUR_RANGE_VBW_FILTER_AUTO_BANDWIDTH_FALSE.\n \nUse 'range(n)' as the selector string to configure or read this attribute.\n \nThe default value is 30000.\n \nGet Function: RFmxSpecAn_SpurGetRangeVBWFilterBandwidth\n Set Function: RFmxSpecAn_SpurSetRangeVBWFilterBandwidth\n"
        },
        'name': 'SPUR_RANGE_VBW_FILTER_BANDWIDTH',
        'type': 'float64'
    },
    1089577: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the VBW to RBW Ratio when you set the RFMXSPECAN_ATTR_SPUR_RANGE_VBW_FILTER_AUTO_BANDWIDTH attribute to RFMXSPECAN_VAL_SPUR_RANGE_VBW_FILTER_AUTO_BANDWIDTH_TRUE.\n \nUse 'range(n)' as the selector string to configure or read this attribute.\n \nThe default value is 3.\n \nGet Function: RFmxSpecAn_SpurGetRangeVBWFilterVBWToRBWRatio\n Set Function: RFmxSpecAn_SpurSetRangeVBWFilterVBWToRBWRatio\n"
        },
        'name': 'SPUR_RANGE_VBW_FILTER_VBW_TO_RBW_RATIO',
        'type': 'float64'
    },
    1093632: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the TXP measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_TXPGetMeasurementEnabled\n Set Function: RFmxSpecAn_TXPSetMeasurementEnabled\n'
        },
        'name': 'TXP_MEASUREMENT_ENABLED',
        'type': 'int32'
    },
    1093634: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the acquisition time for the TXP measurement. This value is expressed in seconds.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.001.\n \nGet Function: RFmxSpecAn_TXPGetMeasurementInterval\n Set Function: RFmxSpecAn_TXPSetMeasurementInterval\n'
        },
        'name': 'TXP_MEASUREMENT_INTERVAL',
        'type': 'float64'
    },
    1093635: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum number of threads used for parallelism for TXP measurement.\n \nThe number of threads can range from 1 to the number of physical cores. The number of threads you set may not be used in calculations. The actual number of threads used depends on the problem size, system resources, data availability, and other considerations.         \n\nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_TXPGetNumberOfAnalysisThreads\n Set Function: RFmxSpecAn_TXPSetNumberOfAnalysisThreads\n'
        },
        'name': 'TXP_NUMBER_OF_ANALYSIS_THREADS',
        'type': 'int32'
    },
    1093637: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of acquisitions used for averaging when you set the RFMXSPECAN_ATTR_TXP_AVERAGING_ENABLED attribute to RFMXSPECAN_VAL_TXP_AVERAGING_ENABLED_TRUE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10.\n \nGet Function: RFmxSpecAn_TXPGetAveragingCount\n Set Function: RFmxSpecAn_TXPSetAveragingCount\n'
        },
        'name': 'TXP_AVERAGING_COUNT',
        'type': 'int32'
    },
    1093638: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable averaging for the TXP measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_TXP_AVERAGING_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_TXPGetAveragingEnabled\n Set Function: RFmxSpecAn_TXPSetAveragingEnabled\n'
        },
        'enum': 'TxpAveragingEnabled',
        'name': 'TXP_AVERAGING_ENABLED',
        'type': 'int32'
    },
    1093640: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the averaging type for the TXP measurement. The averaged power trace is used for the measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_TXP_AVERAGING_TYPE_RMS.\n \nGet Function: RFmxSpecAn_TXPGetAveragingType\n Set Function: RFmxSpecAn_TXPSetAveragingType\n'
        },
        'enum': 'TxpAveragingType',
        'name': 'TXP_AVERAGING_TYPE',
        'type': 'int32'
    },
    1093641: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the roll-off factor for the root-raised-cosine (RRC) filter.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.1.\n \nGet Function: RFmxSpecAn_TXPGetRBWFilterAlpha\n Set Function: RFmxSpecAn_TXPSetRBWFilterAlpha\n'
        },
        'name': 'TXP_RBW_FILTER_ALPHA',
        'type': 'float64'
    },
    1093642: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the bandwidth of the resolution bandwidth (RBW) filter used to measure the signal. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 100 kHz.\n \nGet Function: RFmxSpecAn_TXPGetRBWFilterBandwidth\n Set Function: RFmxSpecAn_TXPSetRBWFilterBandwidth\n'
        },
        'name': 'TXP_RBW_FILTER_BANDWIDTH',
        'type': 'float64'
    },
    1093643: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the shape of the digital resolution bandwidth (RBW) filter.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_TXP_RBW_FILTER_TYPE_GAUSSIAN.\n \nGet Function: RFmxSpecAn_TXPGetRBWFilterType\n Set Function: RFmxSpecAn_TXPSetRBWFilterType\n'
        },
        'enum': 'TxpRbwFilterType',
        'name': 'TXP_RBW_FILTER_TYPE',
        'type': 'int32'
    },
    1093644: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable thresholding of the acquired samples to be used for the TXP measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_TXP_THRESHOLD_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_TXPGetThresholdEnabled\n Set Function: RFmxSpecAn_TXPSetThresholdEnabled\n'
        },
        'enum': 'TxpThresholdEnabled',
        'name': 'TXP_THRESHOLD_ENABLED',
        'type': 'int32'
    },
    1093645: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies either the relative or absolute threshold power level based on the value of the RFMXSPECAN_ATTR_TXP_THRESHOLD_TYPE attribute.\n \n\n \nThe default value is -20.\n \nGet Function: RFmxSpecAn_TXPGetThresholdLevel\n Set Function: RFmxSpecAn_TXPSetThresholdLevel\n'
        },
        'name': 'TXP_THRESHOLD_LEVEL',
        'type': 'float64'
    },
    1093646: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the reference for the power level used for thresholding.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_TXP_THRESHOLD_TYPE_RELATIVE.\n \nGet Function: RFmxSpecAn_TXPGetThresholdType\n Set Function: RFmxSpecAn_TXPSetThresholdType\n'
        },
        'enum': 'TxpThresholdType',
        'name': 'TXP_THRESHOLD_TYPE',
        'type': 'int32'
    },
    1093648: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the traces to be stored and retrieved after performing the TXP measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_TXPGetAllTracesEnabled\n Set Function: RFmxSpecAn_TXPSetAllTracesEnabled\n'
        },
        'name': 'TXP_ALL_TRACES_ENABLED',
        'type': 'int32'
    },
    1093649: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the mean power of the signal. This value is expressed in dBm. Only the samples above the threshold are used by the measurement when you set the RFMXSPECAN_ATTR_TXP_THRESHOLD_ENABLED attribute to RFMXSPECAN_VAL_TXP_THRESHOLD_ENABLED_TRUE. When you set the RFMXSPECAN_ATTR_TXP_AVERAGING_ENABLED attribute to RFMXSPECAN_VAL_TXP_THRESHOLD_ENABLED_TRUE, the mean power is measured using the power trace averaged over multiple acquisitions.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_TXPGetResultsAverageMeanPower\n'
        },
        'name': 'TXP_RESULTS_AVERAGE_MEAN_POWER',
        'type': 'float64'
    },
    1093650: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the ratio of the peak power of the signal to the mean power. Only the samples above the threshold are used by the measurement when you set the RFMXSPECAN_ATTR_TXP_THRESHOLD_ENABLED attribute to RFMXSPECAN_VAL_TXP_THRESHOLD_ENABLED_TRUE. When you set the RFMXSPECAN_ATTR_TXP_AVERAGING_ENABLED attribute to RFMXSPECAN_VAL_TXP_THRESHOLD_ENABLED_TRUE, the peak and mean powers are measured using the power trace averaged over multiple acquisitions.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_TXPGetResultsPeaktoAverageRatio\n'
        },
        'name': 'TXP_RESULTS_PEAK_TO_AVERAGE_RATIO',
        'type': 'float64'
    },
    1093651: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the maximum power of the averaged power trace. This value is expressed in dBm.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_TXPGetResultsMaximumPower\n'
        },
        'name': 'TXP_RESULTS_MAXIMUM_POWER',
        'type': 'float64'
    },
    1093652: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the minimum power of the averaged power trace. This value is expressed in dBm.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_TXPGetResultsMinimumPower\n'
        },
        'name': 'TXP_RESULTS_MINIMUM_POWER',
        'type': 'float64'
    },
    1093655: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the video bandwidth (VBW) is expressed directly or computed based on the VBW to RBW ratio.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_TXP_VBW_FILTER_AUTO_BANDWIDTH_TRUE.\n \nGet Function: RFmxSpecAn_TXPGetVBWFilterAutoBandwidth\n Set Function: RFmxSpecAn_TXPSetVBWFilterAutoBandwidth\n'
        },
        'enum': 'TxpVbwFilterAutoBandwidth',
        'name': 'TXP_VBW_FILTER_AUTO_BANDWIDTH',
        'type': 'int32'
    },
    1093656: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the video bandwidth when you set the RFMXSPECAN_ATTR_TXP_VBW_FILTER_AUTO_BANDWIDTH attribute to RFMXSPECAN_VAL_TXP_VBW_FILTER_AUTO_BANDWIDTH_FALSE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 30000.\n \nGet Function: RFmxSpecAn_TXPGetVBWFilterBandwidth\n Set Function: RFmxSpecAn_TXPSetVBWFilterBandwidth\n'
        },
        'name': 'TXP_VBW_FILTER_BANDWIDTH',
        'type': 'float64'
    },
    1093657: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the VBW to RBW Ratio when you set the RFMXSPECAN_ATTR_TXP_VBW_FILTER_AUTO_BANDWIDTH attribute to RFMXSPECAN_VAL_TXP_VBW_FILTER_AUTO_BANDWIDTH_TRUE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 3.\n \nGet Function: RFmxSpecAn_TXPGetVBWFilterVBWToRBWRatio\n Set Function: RFmxSpecAn_TXPSetVBWFilterVBWToRBWRatio\n'
        },
        'name': 'TXP_VBW_FILTER_VBW_TO_RBW_RATIO',
        'type': 'float64'
    },
    1097728: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the time, in seconds, to wait before results are available in the RFmxSpecAn_AttributeNode. Set this value to a time longer than expected for fetching the measurement. A value of -1 specifies that the RFmxSpecAn Attribute Node waits until the measurement is complete.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10.\n \nGet Function: RFmxSpecAn_GetResultFetchTimeout\n Set Function: RFmxSpecAn_SetResultFetchTimeout\n'
        },
        'name': 'RESULT_FETCH_TIMEOUT',
        'type': 'float64'
    },
    1105920: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the AMPM measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_AMPMGetMeasurementEnabled\n Set Function: RFmxSpecAn_AMPMSetMeasurementEnabled\n'
        },
        'name': 'AMPM_MEASUREMENT_ENABLED',
        'type': 'int32'
    },
    1105922: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the degree of the polynomial used to approximate the AM-to-AM characteristic of the device under test (DUT).\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 7.\n \nGet Function: RFmxSpecAn_AMPMGetAMToAMCurveFitOrder\n Set Function: RFmxSpecAn_AMPMSetAMToAMCurveFitOrder\n'
        },
        'name': 'AMPM_AM_TO_AM_CURVE_FIT_ORDER',
        'type': 'int32'
    },
    1105923: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the polynomial approximation cost-function of the device under test AM-to-AM characteristic.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_AMPM_AM_TO_AM_CURVE_FIT_TYPE_LEAST_ABSOLUTE_RESIDUAL.\n \nGet Function: RFmxSpecAn_AMPMGetAMToAMCurveFitType\n Set Function: RFmxSpecAn_AMPMSetAMToAMCurveFitType\n'
        },
        'enum': 'AmpmAMToAMCurveFitType',
        'name': 'AMPM_AM_TO_AM_CURVE_FIT_TYPE',
        'type': 'int32'
    },
    1105924: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the degree of the polynomial used to approximate the AM-to-PM characteristic of the device under test.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 7.\n \nGet Function: RFmxSpecAn_AMPMGetAMToPMCurveFitOrder\n Set Function: RFmxSpecAn_AMPMSetAMToPMCurveFitOrder\n'
        },
        'name': 'AMPM_AM_TO_PM_CURVE_FIT_ORDER',
        'type': 'int32'
    },
    1105925: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the polynomial approximation cost-function of the device under test AM-to-PM characteristic.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_AMPM_AM_TO_PM_CURVE_FIT_TYPE_LEAST_ABSOLUTE_RESIDUAL.\n \nGet Function: RFmxSpecAn_AMPMGetAMToPMCurveFitType\n Set Function: RFmxSpecAn_AMPMSetAMToPMCurveFitType\n'
        },
        'enum': 'AmpmAMToPMCurveFitType',
        'name': 'AMPM_AM_TO_PM_CURVE_FIT_TYPE',
        'type': 'int32'
    },
    1105926: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable averaging for the AMPM measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_AMPM_AVERAGING_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_AMPMGetAveragingEnabled\n Set Function: RFmxSpecAn_AMPMSetAveragingEnabled\n'
        },
        'enum': 'AmpmAveragingEnabled',
        'name': 'AMPM_AVERAGING_ENABLED',
        'type': 'int32'
    },
    1105927: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of acquisitions used for averaging when you set the RFMXSPECAN_ATTR_AMPM_AVERAGING_ENABLED attribute to RFMXSPECAN_VAL_AMPM_AVERAGING_ENABLED_TRUE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10.\n \nGet Function: RFmxSpecAn_AMPMGetAveragingCount\n Set Function: RFmxSpecAn_AMPMSetAveragingCount\n'
        },
        'name': 'AMPM_AVERAGING_COUNT',
        'type': 'int32'
    },
    1105929: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the duration of the reference waveform considered for the AMPM measurement. When the reference waveform contains an idle duration, the AMPM measurement neglects the idle samples in the reference waveform leading up to the start of the first active portion of the reference waveform. This value is expressed in seconds.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 100E-6.\n \nGet Function: RFmxSpecAn_AMPMGetMeasurementInterval\n Set Function: RFmxSpecAn_AMPMSetMeasurementInterval\n'
        },
        'name': 'AMPM_MEASUREMENT_INTERVAL',
        'type': 'float64'
    },
    1105930: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the reference waveform is a modulated signal or a combination of one or more sinusoidal signals. To time-align the sinusoidal reference waveform to the acquired signal, set the RFMXSPECAN_ATTR_AMPM_SIGNAL_TYPE attribute to Tones, which switches the AMPM measurement alignment algorithm.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_AMPM_SIGNAL_TYPE_MODULATED.\n \nGet Function: RFmxSpecAn_AMPMGetSignalType\n Set Function: RFmxSpecAn_AMPMSetSignalType\n'
        },
        'enum': 'AmpmSignalType',
        'name': 'AMPM_SIGNAL_TYPE',
        'type': 'int32'
    },
    1105931: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the acquisition sample rate is based on the reference waveform.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_AMPM_MEASUREMENT_SAMPLE_RATE_MODE_REFERENCE_WAVEFORM.\n \nGet Function: RFmxSpecAn_AMPMGetMeasurementSampleRateMode\n Set Function: RFmxSpecAn_AMPMSetMeasurementSampleRateMode\n'
        },
        'enum': 'AmpmMeasurementSampleRateMode',
        'name': 'AMPM_MEASUREMENT_SAMPLE_RATE_MODE',
        'type': 'int32'
    },
    1105932: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the acquisition sample rate when you set the RFMXSPECAN_ATTR_AMPM_MEASUREMENT_SAMPLE_RATE_MODE attribute to RFMXSPECAN_VAL_AMPM_MEASUREMENT_SAMPLE_RATE_MODE_USER. This value is expressed in samples per second (S/s).\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 120,000,000.\n \nGet Function: RFmxSpecAn_AMPMGetMeasurementSampleRate\n Set Function: RFmxSpecAn_AMPMSetMeasurementSampleRate\n'
        },
        'name': 'AMPM_MEASUREMENT_SAMPLE_RATE',
        'type': 'float64'
    },
    1105933: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable thresholding of the acquired samples used for the AMPM measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_AMPM_THRESHOLD_ENABLED_TRUE.\n \nGet Function: RFmxSpecAn_AMPMGetThresholdEnabled\n Set Function: RFmxSpecAn_AMPMSetThresholdEnabled\n'
        },
        'enum': 'AmpmThresholdEnabled',
        'name': 'AMPM_THRESHOLD_ENABLED',
        'type': 'int32'
    },
    1105934: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the reference for the power level used for thresholding.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_AMPM_THRESHOLD_TYPE_RELATIVE.\n \nGet Function: RFmxSpecAn_AMPMGetThresholdType\n Set Function: RFmxSpecAn_AMPMSetThresholdType\n'
        },
        'enum': 'AmpmThresholdType',
        'name': 'AMPM_THRESHOLD_TYPE',
        'type': 'int32'
    },
    1105935: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies either the relative or absolute threshold power level, based on the value of the RFMXSPECAN_ATTR_AMPM_THRESHOLD_TYPE attribute.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is -20 dB.\n \nGet Function: RFmxSpecAn_AMPMGetThresholdLevel\n Set Function: RFmxSpecAn_AMPMSetThresholdLevel\n'
        },
        'name': 'AMPM_THRESHOLD_LEVEL',
        'type': 'float64'
    },
    1105936: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the average power of the signal at the input port of the device under test. This value is expressed in dBm.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is -20 dBm.\n \nGet Function: RFmxSpecAn_AMPMGetDUTAverageInputPower\n Set Function: RFmxSpecAn_AMPMSetDUTAverageInputPower\n'
        },
        'name': 'AMPM_DUT_AVERAGE_INPUT_POWER',
        'type': 'float64'
    },
    1105937: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the traces to be stored and retrieved after performing the AMPM measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_AMPMGetAllTracesEnabled\n Set Function: RFmxSpecAn_AMPMSetAllTracesEnabled\n'
        },
        'name': 'AMPM_ALL_TRACES_ENABLED',
        'type': 'int32'
    },
    1105938: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum number of threads used for parallelism for the AMPM measurement.         \n\nThe number of threads can range from 1 to the number of physical cores. However, the number of threads you set may not be used in calculations. The actual number of threads used depends on the problem size, system resources, data availability, and other considerations.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_AMPMGetNumberOfAnalysisThreads\n Set Function: RFmxSpecAn_AMPMSetNumberOfAnalysisThreads\n'
        },
        'name': 'AMPM_NUMBER_OF_ANALYSIS_THREADS',
        'type': 'int32'
    },
    1105940: {
        'access': 'read-write',
        'documentation': {
            'description': '\r\n  "Returns the coefficients of the polynomial that approximates the measured AM-to-AM characteristic of the device under test.\\n\\n"\r\r\n  "Pass the selector string as Empty to read this attribute for the default signal and result instance. Refer to the Selector String topic for information about the string syntax for named signals.\\n\\n"\r\r\n  "Get Function:RFmxSpecAn_AMPMGetResultsAMToAMCurveFitCoefficients"\r'
        },
        'name': 'AMPM_RESULTS_AM_TO_AM_CURVE_FIT_COEFFICIENTS',
        'type': 'float32[]'
    },
    1105941: {
        'access': 'read-write',
        'documentation': {
            'description': '\r\n  "Returns the coefficients of the polynomial that approximates the measured AM-to-PM characteristic of the device under test.\\n\\n"\r\r\n  "Pass the selector string as Empty to read this attribute for the default signal and result instance. Refer to the Selector String topic for information about the string syntax for named signals.\\n\\n"\r\r\n  "Get Function:RFmxSpecAn_AMPMGetResultsAMToPMCurveFitCoefficients"\r\r\n  ""\r'
        },
        'name': 'AMPM_RESULTS_AM_TO_PM_CURVE_FIT_COEFFICIENTS',
        'type': 'float32[]'
    },
    1105942: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the average linear gain of the device under test, computed by rejecting signal samples containing gain compression. This value is expressed in dB.\n \n\n \nGet Function: RFmxSpecAn_AMPMGetResultsMeanLinearGain\n'
        },
        'name': 'AMPM_RESULTS_MEAN_LINEAR_GAIN',
        'type': 'float64'
    },
    1105943: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the mean phase error of the acquired signal relative to the reference waveform caused by the device under test. This value is expressed in degrees.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_AMPMGetResultsMeanPhaseError\n'
        },
        'name': 'AMPM_RESULTS_MEAN_PHASE_ERROR',
        'type': 'float64'
    },
    1105944: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the ratio, as a percentage, of l2 norm of difference between the normalized reference and acquired waveforms, to the l2 norm of the normalized reference waveform.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_AMPMGetResultsMeanRMSEVM\n'
        },
        'name': 'AMPM_RESULTS_MEAN_RMS_EVM',
        'type': 'float64'
    },
    1105945: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the approximation error of the polynomial approximation of the measured device under test AM-to-AM characteristic. This value is expressed in dB.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_AMPMGetResultsAMToAMCurveFitResidual\n'
        },
        'name': 'AMPM_RESULTS_AM_TO_AM_CURVE_FIT_RESIDUAL',
        'type': 'float64'
    },
    1105946: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the approximation error of the polynomial approximation of the measured AM-to-PM characteristic of the device under test. This value is expressed in degrees.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_AMPMGetResultsAMToPMCurveFitResidual\n'
        },
        'name': 'AMPM_RESULTS_AM_TO_PM_CURVE_FIT_RESIDUAL',
        'type': 'float64'
    },
    1105947: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the peak-to-peak deviation of the device under test gain. This value is expressed in dB.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_AMPMGetResultsGainErrorRange\n'
        },
        'name': 'AMPM_RESULTS_GAIN_ERROR_RANGE',
        'type': 'float64'
    },
    1105948: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the peak-to-peak deviation of the phase distortion of the acquired signal relative to the reference waveform caused by the device under test. This value is expressed in degrees.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_AMPMGetResultsPhaseErrorRange\n'
        },
        'name': 'AMPM_RESULTS_PHASE_ERROR_RANGE',
        'type': 'float64'
    },
    1105949: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the theoretical output power at which the device under test gain drops by 1 dB from its mean linear gain. This value is expressed in dBm. This attribute returns NaN when the AM-to-AM characteristics of the device under test are flat.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_AMPMGetResults1dBCompressionPoint\n'
        },
        'name': 'AMPM_RESULTS_1_DB_COMPRESSION_POINT',
        'type': 'float64'
    },
    1105953: {
        'access': 'read-write',
        'documentation': {
            'description': ' Enables frequency offset correction for the measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_AMPM_FREQUENCY_OFFSET_CORRECTION_ENABLED_TRUE.\n \nGet Function: RFmxSpecAn_AMPMGetFrequencyOffsetCorrectionEnabled\n Set Function: RFmxSpecAn_AMPMSetFrequencyOffsetCorrectionEnabled\n'
        },
        'enum': 'AmpmFrequencyOffsetCorrectionEnabled',
        'name': 'AMPM_FREQUENCY_OFFSET_CORRECTION_ENABLED',
        'type': 'int32'
    },
    1105954: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum time alignment error expected between the acquired and the reference waveforms. This value is expressed in seconds.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.00002.\n \nGet Function: RFmxSpecAn_AMPMGetMaximumTimingError\n Set Function: RFmxSpecAn_AMPMSetMaximumTimingError\n'
        },
        'name': 'AMPM_MAXIMUM_TIMING_ERROR',
        'type': 'float64'
    },
    1105955: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the reference power used for AM to AM and AM to PM traces.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_AMPM_REFERENCE_POWER_TYPE_INPUT.\n \nGet Function: RFmxSpecAn_AMPMGetReferencePowerType\n Set Function: RFmxSpecAn_AMPMSetReferencePowerType\n'
        },
        'enum': 'AmpmReferencePowerType',
        'name': 'AMPM_REFERENCE_POWER_TYPE',
        'type': 'int32'
    },
    1105956: {
        'access': 'read-write',
        'documentation': {
            'description': ' Enables computation of compression points corresponding to the respective compression levels specified by the RFMXSPECAN_ATTR_AMPM_COMPRESSION_POINT_LEVEL attribute.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_AMPM_COMPRESSION_POINT_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_AMPMGetCompressionPointEnabled\n Set Function: RFmxSpecAn_AMPMSetCompressionPointEnabled\n'
        },
        'enum': 'AmpmCompressionPointEnabled',
        'name': 'AMPM_COMPRESSION_POINT_ENABLED',
        'type': 'int32'
    },
    1105957: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the compression levels for which the compression points are computed when you set the RFMXSPECAN_ATTR_AMPM_COMPRESSION_POINT_ENABLED attribute to RFMXSPECAN_VAL_AMPM_COMPRESSION_POINT_ENABLED_TRUE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nGet Function: RFmxSpecAn_AMPMGetCompressionPointLevel\n Set Function: RFmxSpecAn_AMPMSetCompressionPointLevel\n'
        },
        'name': 'AMPM_COMPRESSION_POINT_LEVEL',
        'type': 'float64[]'
    },
    1105958: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the theoretical input power at which the device gain drops by the compression level, specified through RFMXSPECAN_ATTR_AMPM_COMPRESSION_POINT_LEVEL attribute, from its mean linear gain. This value is expressed in dBm.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nGet Function: RFmxSpecAn_AMPMGetResultsInputCompressionPoint\n'
        },
        'name': 'AMPM_RESULTS_INPUT_COMPRESSION_POINT',
        'type': 'float64[]'
    },
    1105959: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the theoretical output power at which the device gain drops by the compression level, specified through RFMXSPECAN_ATTR_AMPM_COMPRESSION_POINT_LEVEL attribute, from its mean linear gain. This value is expressed in dBm.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nGet Function: RFmxSpecAn_AMPMGetResultsOutputCompressionPoint\n'
        },
        'name': 'AMPM_RESULTS_OUTPUT_COMPRESSION_POINT',
        'type': 'float64[]'
    },
    1105960: {
        'access': 'read-write',
        'documentation': {
            'description': '\r\n  "Specifies the input power array, in dBm, for the predistortion lookup table when you set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_USER_DPD_MODEL_LOOKUP_TABLE.\\n\\n"\r\r\n  "Pass the selector string as Empty to configure or read this attribute for the default signal instance. Refer to the Selector String topic for information about the string syntax for named signals. \\n\\n"\r\r\n  "Get Function: RFmxSpecAn_DPDGetApplyDPDUserLookupTableInputPower\\n"\r\r\n  "Set Function: RFmxSpecAn_DPDSetApplyDPDUserLookupTableInputPower\\n"\r'
        },
        'name': 'DPD_APPLY_DPD_USER_LOOKUP_TABLE_INPUT_POWER',
        'type': 'float32[]'
    },
    1105961: {
        'access': 'read-write',
        'documentation': {
            'description': ' Enables IQ origin offset correction for the measurement.\n \nWhen you set this attribute is set to True, the measurement computes and corrects any origin offset between the reference and the acquired waveforms. When you set this attribute to False, origin offset correction is not performed.\n \nThe default value is RFMXSPECAN_VAL_AMPM_IQ_ORIGIN_OFFSET_CORRECTION_ENABLED_TRUE.\n \nGet Function: RFmxSpecAn_AMPMGetIQOriginOffsetCorrectionEnabled\n Set Function: RFmxSpecAn_AMPMSetIQOriginOffsetCorrectionEnabled\n'
        },
        'enum': 'AmpmIQOriginOffsetCorrectionEnabled',
        'name': 'AMPM_IQ_ORIGIN_OFFSET_CORRECTION_ENABLED',
        'type': 'int32'
    },
    1105962: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the method used for synchronization of acquired waveform with reference waveform.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_AMPM_SYNCHRONIZATION_METHOD_DIRECT.\n \nGet Function: RFmxSpecAn_AMPMGetSynchronizationMethod\n Set Function: RFmxSpecAn_AMPMSetSynchronizationMethod\n'
        },
        'enum': 'AmpmSynchronizationMethod',
        'name': 'AMPM_SYNCHRONIZATION_METHOD',
        'type': 'int32'
    },
    1105963: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies if auto detection of carrier offset and carrier bandwidth is enabled.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_AMPM_AUTO_CARRIER_DETECTION_ENABLED_TRUE.\n \nGet Function: RFmxSpecAn_AMPMGetAutoCarrierDetectionEnabled\n Set Function: RFmxSpecAn_AMPMSetAutoCarrierDetectionEnabled\n'
        },
        'enum': 'AmpmAutoCarrierDetectionEnabled',
        'name': 'AMPM_AUTO_CARRIER_DETECTION_ENABLED',
        'type': 'int32'
    },
    1105964: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of carriers in the reference waveform when you set the RFMXSPECAN_ATTR_AMPM_AUTO_CARRIER_DETECTION_ENABLED attribute to RFMXSPECAN_VAL_AMPM_AUTO_CARRIER_DETECTION_ENABLED_FALSE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_AMPMGetNumberOfCarriers\n Set Function: RFmxSpecAn_AMPMSetNumberOfCarriers\n'
        },
        'name': 'AMPM_NUMBER_OF_CARRIERS',
        'type': 'int32'
    },
    1105965: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the carrier offset when you set the RFMXSPECAN_ATTR_AMPM_AUTO_CARRIER_DETECTION_ENABLED attribute to RFMXSPECAN_VAL_AMPM_AUTO_CARRIER_DETECTION_ENABLED_FALSE. This value is expressed in Hz.\n \nUse 'carrier(n)' as the selector string to configure or read this attribute.\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_AMPMGetCarrierOffset\n Set Function: RFmxSpecAn_AMPMSetCarrierOffset\n"
        },
        'name': 'AMPM_CARRIER_OFFSET',
        'type': 'float64'
    },
    1105966: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the carrier bandwidth when you set the RFMXSPECAN_ATTR_AMPM_AUTO_CARRIER_DETECTION_ENABLED attribute to RFMXSPECAN_VAL_AMPM_AUTO_CARRIER_DETECTION_ENABLED_FALSE. This value is expressed in Hz.\n \nUse 'carrier(n)' as the selector string to configure or read this attribute.\n \nThe default value is 20 MHz.\n \nGet Function: RFmxSpecAn_AMPMGetCarrierBandwidth\n Set Function: RFmxSpecAn_AMPMSetCarrierBandwidth\n"
        },
        'name': 'AMPM_CARRIER_BANDWIDTH',
        'type': 'float64'
    },
    1105967: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the measurement equalizes the channel.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_AMPM_EQUALIZER_MODE_OFF.\n \nGet Function: RFmxSpecAn_AMPMGetEqualizerMode\n Set Function: RFmxSpecAn_AMPMSetEqualizerMode\n'
        },
        'enum': 'AmpmEqualizerMode',
        'name': 'AMPM_EQUALIZER_MODE',
        'type': 'int32'
    },
    1105968: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the length of the equalizer filter. The measurement maintains the filter length as an odd number by incrementing any even numbered value by one.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 21.\n \nGet Function: RFmxSpecAn_AMPMGetEqualizerFilterLength\n Set Function: RFmxSpecAn_AMPMSetEqualizerFilterLength\n'
        },
        'name': 'AMPM_EQUALIZER_FILTER_LENGTH',
        'type': 'int32'
    },
    1105969: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the results that rely on the AM to AM characteristics.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_AMPM_AM_TO_AM_ENABLED_TRUE.\n \nGet Function: RFmxSpecAn_AMPMGetAMToAMEnabled\n Set Function: RFmxSpecAn_AMPMSetAMToAMEnabled\n'
        },
        'enum': 'AmpmAMToAMEnabled',
        'name': 'AMPM_AM_TO_AM_ENABLED',
        'type': 'int32'
    },
    1105970: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the results that rely on AM to PM characteristics.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_AMPM_AM_TO_PM_ENABLED_TRUE.\n \nGet Function: RFmxSpecAn_AMPMGetAMToPMEnabled\n Set Function: RFmxSpecAn_AMPMSetAMToPMEnabled\n'
        },
        'enum': 'AmpmAMToPMEnabled',
        'name': 'AMPM_AM_TO_PM_ENABLED',
        'type': 'int32'
    },
    1105971: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the RFMXSPECAN_ATTR_AMPM_RESULTS_MEAN_RMS_EVM attribute.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_AMPM_EVM_ENABLED_TRUE.\n \nGet Function: RFmxSpecAn_AMPMGetEVMEnabled\n Set Function: RFmxSpecAn_AMPMSetEVMEnabled\n'
        },
        'enum': 'AmpmEvmEnabled',
        'name': 'AMPM_EVM_ENABLED',
        'type': 'int32'
    },
    1105972: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the gain reference for compression point calculation.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_AMPM_COMPRESSION_POINT_GAIN_REFERENCE_AUTO.\n \nGet Function: RFmxSpecAn_AMPMGetCompressionPointGainReference\n Set Function: RFmxSpecAn_AMPMSetCompressionPointGainReference\n'
        },
        'enum': 'AmpmCompressionPointGainReference',
        'name': 'AMPM_COMPRESSION_POINT_GAIN_REFERENCE',
        'type': 'int32'
    },
    1105973: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the reference power corresponding to the gain reference to be used for compression point calculation when you set the RFMXSPECAN_ATTR_AMPM_COMPRESSION_POINT_GAIN_REFERENCE attribute to RFMXSPECAN_VAL_AMPM_COMPRESSION_POINT_GAIN_REFERENCE_REFERENCE_POWER. The reference power can be configured as either input or output power based on the value of the RFMXSPECAN_ATTR_AMPM_REFERENCE_POWER_TYPE attribute. This value is expressed in dBm.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is -20.\n \nGet Function: RFmxSpecAn_AMPMGetCompressionPointGainReferencePower\n Set Function: RFmxSpecAn_AMPMSetCompressionPointGainReferencePower\n'
        },
        'name': 'AMPM_COMPRESSION_POINT_GAIN_REFERENCE_POWER',
        'type': 'float64'
    },
    1110016: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable DPD measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_DPDGetMeasurementEnabled\n Set Function: RFmxSpecAn_DPDSetMeasurementEnabled\n'
        },
        'name': 'DPD_MEASUREMENT_ENABLED',
        'type': 'int32'
    },
    1110018: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the acquisition sample rate configuration mode.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD_MEASUREMENT_SAMPLE_RATE_MODE_REFERENCE_WAVEFORM.\n \nGet Function: RFmxSpecAn_DPDGetMeasurementSampleRateMode\n Set Function: RFmxSpecAn_DPDSetMeasurementSampleRateMode\n'
        },
        'enum': 'DpdMeasurementSampleRateMode',
        'name': 'DPD_MEASUREMENT_SAMPLE_RATE_MODE',
        'type': 'int32'
    },
    1110019: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the acquisition sample rate when you set the RFMXSPECAN_ATTR_DPD_MEASUREMENT_SAMPLE_RATE_MODE attribute to RFMXSPECAN_VAL_DPD_MEASUREMENT_SAMPLE_RATE_MODE_USER. This value is expressed in Samples per second (S/s).\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 120 MHz.\n \nGet Function: RFmxSpecAn_DPDGetMeasurementSampleRate\n Set Function: RFmxSpecAn_DPDSetMeasurementSampleRate\n'
        },
        'name': 'DPD_MEASUREMENT_SAMPLE_RATE',
        'type': 'float64'
    },
    1110020: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the duration of the reference waveform considered for the DPD measurement. When the reference waveform contains an idle duration, the DPD measurement neglects the idle samples in the reference waveform leading up to the start of the first active portion of the reference waveform. This value is expressed in seconds.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 100E-6.\n \nGet Function: RFmxSpecAn_DPDGetMeasurementInterval\n Set Function: RFmxSpecAn_DPDSetMeasurementInterval\n'
        },
        'name': 'DPD_MEASUREMENT_INTERVAL',
        'type': 'float64'
    },
    1110021: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the reference waveform is a modulated signal or a combination of one or more sinusoidal signals. To time-align the sinusoidal reference waveform to the acquired signal, set the RFMXSPECAN_ATTR_DPD_SIGNAL_TYPE attribute to Tones, which switches the DPD measurement alignment algorithm.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD_SIGNAL_TYPE_MODULATED.\n \nGet Function: RFmxSpecAn_DPDGetSignalType\n Set Function: RFmxSpecAn_DPDSetSignalType\n'
        },
        'enum': 'DpdSignalType',
        'name': 'DPD_SIGNAL_TYPE',
        'type': 'int32'
    },
    1110023: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the average power of the signal at the device under test input port. This value is expressed in dBm.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is -20 dBm.\n \nGet Function: RFmxSpecAn_DPDGetDUTAverageInputPower\n Set Function: RFmxSpecAn_DPDSetDUTAverageInputPower\n'
        },
        'name': 'DPD_DUT_AVERAGE_INPUT_POWER',
        'type': 'float64'
    },
    1110024: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the DPD model used by the DPD measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD_MODEL_LOOKUP_TABLE.\n \nGet Function: RFmxSpecAn_DPDGetModel\n Set Function: RFmxSpecAn_DPDSetModel\n'
        },
        'enum': 'DpdModel',
        'name': 'DPD_MODEL',
        'type': 'int32'
    },
    1110025: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the degree of the polynomial used to approximate the device under test AM-to-AM characteristic  when you set the RFMXSPECAN_ATTR_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_MODEL_LOOKUP_TABLE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 7.\n \nGet Function: RFmxSpecAn_DPDGetLookupTableAMToAMCurveFitOrder\n Set Function: RFmxSpecAn_DPDSetLookupTableAMToAMCurveFitOrder\n'
        },
        'name': 'DPD_LOOKUP_TABLE_AM_TO_AM_CURVE_FIT_ORDER',
        'type': 'int32'
    },
    1110026: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the polynomial approximation cost-function of the device under test AM-to-AM characteristic when you set the RFMXSPECAN_ATTR_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_MODEL_LOOKUP_TABLE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD_LOOKUP_TABLE_AM_TO_AM_CURVE_FIT_TYPE_LEAST_ABSOLUTE_RESIDUAL.\n \nGet Function: RFmxSpecAn_DPDGetLookupTableAMToAMCurveFitType\n Set Function: RFmxSpecAn_DPDSetLookupTableAMToAMCurveFitType\n'
        },
        'enum': 'DpdLookupTableAMToAMCurveFitType',
        'name': 'DPD_LOOKUP_TABLE_AM_TO_AM_CURVE_FIT_TYPE',
        'type': 'int32'
    },
    1110027: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the degree of the polynomial used to approximate the device under test AM-to-PM characteristic when you set the RFMXSPECAN_ATTR_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_MODEL_LOOKUP_TABLE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 7.\n \nGet Function: RFmxSpecAn_DPDGetLookupTableAMToPMCurveFitOrder\n Set Function: RFmxSpecAn_DPDSetLookupTableAMToPMCurveFitOrder\n'
        },
        'name': 'DPD_LOOKUP_TABLE_AM_TO_PM_CURVE_FIT_ORDER',
        'type': 'int32'
    },
    1110028: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the polynomial approximation cost-function of the device under test AM-to-PM characteristic when you set the RFMXSPECAN_ATTR_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_MODEL_LOOKUP_TABLE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD_LOOKUP_TABLE_AM_TO_PM_CURVE_FIT_TYPE_LEAST_ABSOLUTE_RESIDUAL.\n \nGet Function: RFmxSpecAn_DPDGetLookupTableAMToPMCurveFitType\n Set Function: RFmxSpecAn_DPDSetLookupTableAMToPMCurveFitType\n'
        },
        'enum': 'DpdLookupTableAMToPMCurveFitType',
        'name': 'DPD_LOOKUP_TABLE_AM_TO_PM_CURVE_FIT_TYPE',
        'type': 'int32'
    },
    1110029: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable thresholding of the acquired samples to be used for the DPD measurement when you set the RFMXSPECAN_ATTR_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_MODEL_LOOKUP_TABLE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD_LOOKUP_TABLE_THRESHOLD_ENABLED_TRUE.\n \nGet Function: RFmxSpecAn_DPDGetLookupTableThresholdEnabled\n Set Function: RFmxSpecAn_DPDSetLookupTableThresholdEnabled\n'
        },
        'enum': 'DpdLookupTableThresholdEnabled',
        'name': 'DPD_LOOKUP_TABLE_THRESHOLD_ENABLED',
        'type': 'int32'
    },
    1110030: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the reference for the power level used for thresholding.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD_LOOKUP_TABLE_THRESHOLD_TYPE_RELATIVE.\n \nGet Function: RFmxSpecAn_DPDGetLookupTableThresholdType\n Set Function: RFmxSpecAn_DPDSetLookupTableThresholdType\n'
        },
        'enum': 'DpdLookupTableThresholdType',
        'name': 'DPD_LOOKUP_TABLE_THRESHOLD_TYPE',
        'type': 'int32'
    },
    1110031: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies either the relative or absolute threshold power level based on the value of the RFMXSPECAN_ATTR_DPD_LOOKUP_TABLE_THRESHOLD_TYPE attribute. This value is expressed in dB or dBm.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is -20.\n \nGet Function: RFmxSpecAn_DPDGetLookupTableThresholdLevel\n Set Function: RFmxSpecAn_DPDSetLookupTableThresholdLevel\n'
        },
        'name': 'DPD_LOOKUP_TABLE_THRESHOLD_LEVEL',
        'type': 'float64'
    },
    1110032: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the step size of the input power levels in the predistortion lookup table when you set the RFMXSPECAN_ATTR_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_MODEL_LOOKUP_TABLE. This value is expressed in dB.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.1 dB.\n \nGet Function: RFmxSpecAn_DPDGetLookupTableStepSize\n Set Function: RFmxSpecAn_DPDSetLookupTableStepSize\n'
        },
        'name': 'DPD_LOOKUP_TABLE_STEP_SIZE',
        'type': 'float64'
    },
    1110033: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the order of the DPD polynomial when you set the RFMXSPECAN_ATTR_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_MODEL_MEMORY_POLYNOMIAL or RFMXSPECAN_VAL_DPD_MODEL_GENERALIZED_MEMORY_POLYNOMIAL. This order value corresponds to Ka in the equation for the generalized memory polynomial.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 3.\n \nGet Function: RFmxSpecAn_DPDGetMemoryPolynomialOrder\n Set Function: RFmxSpecAn_DPDSetMemoryPolynomialOrder\n'
        },
        'name': 'DPD_MEMORY_POLYNOMIAL_ORDER',
        'type': 'int32'
    },
    1110034: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the memory depth of the DPD polynomial when you set the RFMXSPECAN_ATTR_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_MODEL_MEMORY_POLYNOMIAL or RFMXSPECAN_VAL_DPD_MODEL_GENERALIZED_MEMORY_POLYNOMIAL. This depth value corresponds to Qa in the equation for the generalized memory polynomial.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_DPDGetMemoryPolynomialMemoryDepth\n Set Function: RFmxSpecAn_DPDSetMemoryPolynomialMemoryDepth\n'
        },
        'name': 'DPD_MEMORY_POLYNOMIAL_MEMORY_DEPTH',
        'type': 'int32'
    },
    1110035: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the lead order cross term of the DPD polynomial when you set the RFMXSPECAN_ATTR_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_MODEL_GENERALIZED_MEMORY_POLYNOMIAL. This term value corresponds to Kc in the equation for the generalized memory polynomial.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_DPDGetMemoryPolynomialLeadOrder\n Set Function: RFmxSpecAn_DPDSetMemoryPolynomialLeadOrder\n'
        },
        'name': 'DPD_MEMORY_POLYNOMIAL_LEAD_ORDER',
        'type': 'int32'
    },
    1110036: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the lag order cross term of the DPD polynomial when you set the RFMXSPECAN_ATTR_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_MODEL_GENERALIZED_MEMORY_POLYNOMIAL. This term value corresponds to Kb in the equation for the generalized memory polynomial.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_DPDGetMemoryPolynomialLagOrder\n Set Function: RFmxSpecAn_DPDSetMemoryPolynomialLagOrder\n'
        },
        'name': 'DPD_MEMORY_POLYNOMIAL_LAG_ORDER',
        'type': 'int32'
    },
    1110037: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the lead memory depth cross term of the DPD polynomial when you set the RFMXSPECAN_ATTR_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_MODEL_GENERALIZED_MEMORY_POLYNOMIAL. This term value corresponds to Qc in the equation for the generalized memory polynomial.  The value of the RFMXSPECAN_ATTR_DPD_MEMORY_POLYNOMIAL_LEAD_MEMORY_DEPTH attribute must be greater than or equal to the value of the RFMXSPECAN_ATTR_DPD_MEMORY_POLYNOMIAL_MAXIMUM_LEAD attribute.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_DPDGetMemoryPolynomialLeadMemoryDepth\n Set Function: RFmxSpecAn_DPDSetMemoryPolynomialLeadMemoryDepth\n'
        },
        'name': 'DPD_MEMORY_POLYNOMIAL_LEAD_MEMORY_DEPTH',
        'type': 'int32'
    },
    1110038: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the lag memory depth cross term of the DPD polynomial when you set the RFMXSPECAN_ATTR_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_MODEL_GENERALIZED_MEMORY_POLYNOMIAL. This term value corresponds to Qb in the equation for the generalized memory polynomial.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_DPDGetMemoryPolynomialLagMemoryDepth\n Set Function: RFmxSpecAn_DPDSetMemoryPolynomialLagMemoryDepth\n'
        },
        'name': 'DPD_MEMORY_POLYNOMIAL_LAG_MEMORY_DEPTH',
        'type': 'int32'
    },
    1110039: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum lead stagger cross term of the DPD polynomial when you set the RFMXSPECAN_ATTR_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_MODEL_GENERALIZED_MEMORY_POLYNOMIAL. This term value corresponds to Mc in the equation for the generalized memory polynomial.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_DPDGetMemoryPolynomialMaximumLead\n Set Function: RFmxSpecAn_DPDSetMemoryPolynomialMaximumLead\n'
        },
        'name': 'DPD_MEMORY_POLYNOMIAL_MAXIMUM_LEAD',
        'type': 'int32'
    },
    1110040: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum lag stagger cross term of the DPD polynomial when you set the RFMXSPECAN_ATTR_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_MODEL_GENERALIZED_MEMORY_POLYNOMIAL. This term value corresponds to Mb in the equation for the generalized memory polynomial.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_DPDGetMemoryPolynomialMaximumLag\n Set Function: RFmxSpecAn_DPDSetMemoryPolynomialMaximumLag\n'
        },
        'name': 'DPD_MEMORY_POLYNOMIAL_MAXIMUM_LAG',
        'type': 'int32'
    },
    1110042: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable iterative computation of the DPD Results DPD Polynomial using indirect-learning architecture.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD_ITERATIVE_DPD_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_DPDGetIterativeDPDEnabled\n Set Function: RFmxSpecAn_DPDSetIterativeDPDEnabled\n'
        },
        'enum': 'DpdIterativeDpdEnabled',
        'name': 'DPD_ITERATIVE_DPD_ENABLED',
        'type': 'int32'
    },
    1110044: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable averaging for the DPD measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD_AVERAGING_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_DPDGetAveragingEnabled\n Set Function: RFmxSpecAn_DPDSetAveragingEnabled\n'
        },
        'enum': 'DpdAveragingEnabled',
        'name': 'DPD_AVERAGING_ENABLED',
        'type': 'int32'
    },
    1110045: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of acquisitions used for averaging when you set the RFMXSPECAN_ATTR_DPD_AVERAGING_ENABLED attribute to RFMXSPECAN_VAL_DPD_AVERAGING_ENABLED_TRUE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10.\n \nGet Function: RFmxSpecAn_DPDGetAveragingCount\n Set Function: RFmxSpecAn_DPDSetAveragingCount\n'
        },
        'name': 'DPD_AVERAGING_COUNT',
        'type': 'int32'
    },
    1110047: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the traces to be stored and retrieved after performing the DPD measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_DPDGetAllTracesEnabled\n Set Function: RFmxSpecAn_DPDSetAllTracesEnabled\n'
        },
        'name': 'DPD_ALL_TRACES_ENABLED',
        'type': 'int32'
    },
    1110048: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum number of threads used for parallelism of the DPD measurement.\n \nThe number of threads can range from 1 to the number of physical cores. However, the number of threads you set may not all be used in calculations. The actual number of threads used depends on the problem size, system resources, data availability, and other considerations.         \n\nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_DPDGetNumberofAnalysisThreads\n Set Function: RFmxSpecAn_DPDSetNumberofAnalysisThreads\n'
        },
        'name': 'DPD_NUMBER_OF_ANALYSIS_THREADS',
        'type': 'int32'
    },
    1110049: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to use the configuration parameters used by the DPD measurement for applying DPD.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD_APPLY_DPD_CONFIGURATION_INPUT_MEASUREMENT.\n \nGet Function: RFmxSpecAn_DPDGetApplyDPDConfigurationInput\n Set Function: RFmxSpecAn_DPDSetApplyDPDConfigurationInput\n'
        },
        'enum': 'DpdApplyDpdConfigurationInput',
        'name': 'DPD_APPLY_DPD_CONFIGURATION_INPUT',
        'type': 'int32'
    },
    1110050: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the predistortion type when you set the RFMXSPECAN_ATTR_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_MODEL_LOOKUP_TABLE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD_APPLY_DPD_LOOKUP_TABLE_CORRECTION_TYPE_MAGNITUDE_AND_PHASE.\n \nGet Function: RFmxSpecAn_DPDGetApplyDPDLookupTableCorrectionType\n Set Function: RFmxSpecAn_DPDSetApplyDPDLookupTableCorrectionType\n'
        },
        'enum': 'DpdApplyDpdLookupTableCorrectionType',
        'name': 'DPD_APPLY_DPD_LOOKUP_TABLE_CORRECTION_TYPE',
        'type': 'int32'
    },
    1110053: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the average input power for the device under test that was used to compute the DPD Apply DPD User DPD Polynomial or the DPD Apply DPD User LUT Complex Gain when you set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CONFIGURATION_INPUT attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CONFIGURATION_INPUT_USER. This value is expressed in dBm.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is -20 dBm.\n \nGet Function: RFmxSpecAn_DPDGetApplyDPDUserDUTAverageInputPower\n Set Function: RFmxSpecAn_DPDSetApplyDPDUserDUTAverageInputPower\n'
        },
        'name': 'DPD_APPLY_DPD_USER_DUT_AVERAGE_INPUT_POWER',
        'type': 'float64'
    },
    1110054: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the DPD model for applying DPD when you set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CONFIGURATION_INPUT attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CONFIGURATION_INPUT_USER.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD_APPLY_DPD_USER_DPD_MODEL_LOOKUP_TABLE.\n \nGet Function: RFmxSpecAn_DPDGetApplyDPDUserDPDModel\n Set Function: RFmxSpecAn_DPDSetApplyDPDUserDPDModel\n'
        },
        'enum': 'DpdApplyDpdUserDpdModel',
        'name': 'DPD_APPLY_DPD_USER_DPD_MODEL',
        'type': 'int32'
    },
    1110055: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the acquisition sample rate used to compute the DPD Apply DPD User DPD Polynomial or DPD Apply DPD User LUT Complex Gain when you set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CONFIGURATION_INPUT attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CONFIGURATION_INPUT_USER. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 120 MHz.\n \nGet Function: RFmxSpecAn_DPDGetApplyDPDUserMeasurementSampleRate\n Set Function: RFmxSpecAn_DPDSetApplyDPDUserMeasurementSampleRate\n'
        },
        'name': 'DPD_APPLY_DPD_USER_MEASUREMENT_SAMPLE_RATE',
        'type': 'float64'
    },
    1110058: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the order of the DPD polynomial when you set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_USER_DPD_MODEL_MEMORY_POLYNOMIAL or RFMXSPECAN_VAL_DPD_APPLY_DPD_USER_DPD_MODEL_GENERALIZED_MEMORY_POLYNOMIAL and set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CONFIGURATION_INPUT attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CONFIGURATION_INPUT_USER. This value corresponds to Ka in the equation for generalized memory polynomial.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.        \n\nThe default value is 3.\n \nGet Function: RFmxSpecAn_DPDGetApplyDPDUserMemoryPolynomialOrder\n Set Function: RFmxSpecAn_DPDSetApplyDPDUserMemoryPolynomialOrder\n'
        },
        'name': 'DPD_APPLY_DPD_USER_MEMORY_POLYNOMIAL_ORDER',
        'type': 'int32'
    },
    1110059: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the memory depth of the DPD polynomial when you set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_USER_DPD_MODEL_MEMORY_POLYNOMIAL or RFMXSPECAN_VAL_DPD_APPLY_DPD_USER_DPD_MODEL_GENERALIZED_MEMORY_POLYNOMIAL and set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CONFIGURATION_INPUT attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CONFIGURATION_INPUT_USER. This value corresponds to Qa in the equation for generalized memory polynomial.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.        \n\nThe default value is 0.\n \nGet Function: RFmxSpecAn_DPDGetApplyDPDUserMemoryPolynomialMemoryDepth\n Set Function: RFmxSpecAn_DPDSetApplyDPDUserMemoryPolynomialMemoryDepth\n'
        },
        'name': 'DPD_APPLY_DPD_USER_MEMORY_POLYNOMIAL_MEMORY_DEPTH',
        'type': 'int32'
    },
    1110060: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the lead order cross term of the DPD polynomial when you set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_USER_DPD_MODEL_GENERALIZED_MEMORY_POLYNOMIAL and set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CONFIGURATION_INPUT attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CONFIGURATION_INPUT_USER. This value corresponds to Kc in the equation for the generalized memory polynomial.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.        \n\nThe default value is 0.\n \nGet Function: RFmxSpecAn_DPDGetApplyDPDUserMemoryPolynomialLeadOrder\n Set Function: RFmxSpecAn_DPDSetApplyDPDUserMemoryPolynomialLeadOrder\n'
        },
        'name': 'DPD_APPLY_DPD_USER_MEMORY_POLYNOMIAL_LEAD_ORDER',
        'type': 'int32'
    },
    1110061: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the lag order cross term of the DPD polynomial when you set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_USER_DPD_MODEL_GENERALIZED_MEMORY_POLYNOMIAL and set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CONFIGURATION_INPUT attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CONFIGURATION_INPUT_USER. This value corresponds to Kb in the equation for the generalized memory polynomial.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.        \n\nThe default value is 0.\n \nGet Function: RFmxSpecAn_DPDGetApplyDPDUserMemoryPolynomialLagOrder\n Set Function: RFmxSpecAn_DPDSetApplyDPDUserMemoryPolynomialLagOrder\n'
        },
        'name': 'DPD_APPLY_DPD_USER_MEMORY_POLYNOMIAL_LAG_ORDER',
        'type': 'int32'
    },
    1110062: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the lead memory depth cross term of the DPD polynomial when you set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_USER_DPD_MODEL_GENERALIZED_MEMORY_POLYNOMIAL and set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CONFIGURATION_INPUT attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CONFIGURATION_INPUT_USER. This value corresponds to Qc in the equation for the generalized memory polynomial.  The value of the RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_MEMORY_POLYNOMIAL_LEAD_MEMORY_DEPTH attribute must be greater than or equal to the value of the RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_MEMORY_POLYNOMIAL_MAXIMUM_LEAD attribute.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.        \n\nThe default value is 0.\n \nGet Function: RFmxSpecAn_DPDGetApplyDPDUserMemoryPolynomialLeadMemoryDepth\n Set Function: RFmxSpecAn_DPDSetApplyDPDUserMemoryPolynomialLeadMemoryDepth\n'
        },
        'name': 'DPD_APPLY_DPD_USER_MEMORY_POLYNOMIAL_LEAD_MEMORY_DEPTH',
        'type': 'int32'
    },
    1110063: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the lag memory depth cross term of the DPD polynomial when you set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_USER_DPD_MODEL_MEMORY_POLYNOMIAL or RFMXSPECAN_VAL_DPD_APPLY_DPD_USER_DPD_MODEL_GENERALIZED_MEMORY_POLYNOMIAL and set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CONFIGURATION_INPUT attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CONFIGURATION_INPUT_USER. This value corresponds to Qb in the equation for the generalized memory polynomial.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.        \n\nThe default value is 0.\n \nGet Function: RFmxSpecAn_DPDGetApplyDPDUserMemoryPolynomialLagMemoryDepth\n Set Function: RFmxSpecAn_DPDSetApplyDPDUserMemoryPolynomialLagMemoryDepth\n'
        },
        'name': 'DPD_APPLY_DPD_USER_MEMORY_POLYNOMIAL_LAG_MEMORY_DEPTH',
        'type': 'int32'
    },
    1110064: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum lead stagger cross term of the DPD polynomial when you set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_USER_DPD_MODEL_MEMORY_POLYNOMIAL or RFMXSPECAN_VAL_DPD_APPLY_DPD_USER_DPD_MODEL_GENERALIZED_MEMORY_POLYNOMIAL and set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CONFIGURATION_INPUT attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CONFIGURATION_INPUT_USER. This value corresponds to Mc in the equation for the generalized memory polynomial.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.        \n\nThe default value is 0.\n \nGet Function: RFmxSpecAn_DPDGetApplyDPDUserMemoryPolynomialMaximumLead\n Set Function: RFmxSpecAn_DPDSetApplyDPDUserMemoryPolynomialMaximumLead\n'
        },
        'name': 'DPD_APPLY_DPD_USER_MEMORY_POLYNOMIAL_MAXIMUM_LEAD',
        'type': 'int32'
    },
    1110065: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum lag stagger cross term of the DPD polynomial when you set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_USER_DPD_MODEL_MEMORY_POLYNOMIAL or RFMXSPECAN_VAL_DPD_APPLY_DPD_USER_DPD_MODEL_GENERALIZED_MEMORY_POLYNOMIAL and set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CONFIGURATION_INPUT attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CONFIGURATION_INPUT_USER. This value corresponds to Mb in the equation for the generalized memory polynomial.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.        \n\nThe default value is 0.\n \nGet Function: RFmxSpecAn_DPDGetApplyDPDUserMemoryPolynomialMaximumLag\n Set Function: RFmxSpecAn_DPDSetApplyDPDUserMemoryPolynomialMaximumLag\n'
        },
        'name': 'DPD_APPLY_DPD_USER_MEMORY_POLYNOMIAL_MAXIMUM_LAG',
        'type': 'int32'
    },
    1110067: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the average gain of the device under test. This value is expressed in dB.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_DPDGetResultsAverageGain\n'
        },
        'name': 'DPD_RESULTS_AVERAGE_GAIN',
        'type': 'float64'
    },
    1110070: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the predistortion type when you set the RFMXSPECAN_ATTR_DPD_MODEL attribute to RFMXSPECAN_VAL_DPD_MODEL_MEMORY_POLYNOMIAL or RFMXSPECAN_VAL_DPD_MODEL_GENERALIZED_MEMORY_POLYNOMIAL.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD_APPLY_DPD_MEMORY_MODEL_CORRECTION_TYPE_MAGNITUDE_AND_PHASE.\n \nGet Function: RFmxSpecAn_DPDGetApplyDPDMemoryModelCorrectionType\n Set Function: RFmxSpecAn_DPDSetApplyDPDMemoryModelCorrectionType\n'
        },
        'enum': 'DpdApplyDpdMemoryModelCorrectionType',
        'name': 'DPD_APPLY_DPD_MEMORY_MODEL_CORRECTION_TYPE',
        'type': 'int32'
    },
    1110071: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the gain expected from the DUT after applying DPD on the input waveform.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD_TARGET_GAIN_TYPE_AVERAGE_GAIN.\n \nGet Function: RFmxSpecAn_DPDGetTargetGainType\n Set Function: RFmxSpecAn_DPDSetTargetGainType\n'
        },
        'enum': 'DpdTargetGainType',
        'name': 'DPD_TARGET_GAIN_TYPE',
        'type': 'int32'
    },
    1110072: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the type of the DPD lookup table (LUT).\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD_LOOKUP_TABLE_TYPE_LOG.\n \nGet Function: RFmxSpecAn_DPDGetLookupTableType\n Set Function: RFmxSpecAn_DPDSetLookupTableType\n'
        },
        'enum': 'DpdLookupTableType',
        'name': 'DPD_LOOKUP_TABLE_TYPE',
        'type': 'int32'
    },
    1110073: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable frequency offset correction for the DPD measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD_FREQUENCY_OFFSET_CORRECTION_ENABLED_TRUE.\n \nGet Function: RFmxSpecAn_DPDGetFrequencyOffsetCorrectionEnabled\n Set Function: RFmxSpecAn_DPDSetFrequencyOffsetCorrectionEnabled\n'
        },
        'enum': 'DpdFrequencyOffsetCorrectionEnabled',
        'name': 'DPD_FREQUENCY_OFFSET_CORRECTION_ENABLED',
        'type': 'int32'
    },
    1110074: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum time alignment error expected between the acquired and the reference waveforms. This value is expressed in seconds.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.00002.\n \nGet Function: RFmxSpecAn_DPDGetMaximumTimingError\n Set Function: RFmxSpecAn_DPDSetMaximumTimingError\n'
        },
        'name': 'DPD_MAXIMUM_TIMING_ERROR',
        'type': 'float64'
    },
    1110075: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the normalized mean-squared error (NMSE) computation.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD_NMSE_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_DPDGetNMSEEnabled\n Set Function: RFmxSpecAn_DPDSetNMSEEnabled\n'
        },
        'enum': 'DpdNmseEnabled',
        'name': 'DPD_NMSE_ENABLED',
        'type': 'int32'
    },
    1110076: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the crest factor reduction (CFR) when applying pre-DPD signal conditioning.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_DPDGetPreDPDCFREnabled\n Set Function: RFmxSpecAn_DPDSetPreDPDCFREnabled\n'
        },
        'enum': 'DpdPreDpdCfrEnabled',
        'name': 'DPD_PRE_DPD_CFR_ENABLED',
        'type': 'int32'
    },
    1110077: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum number of iterations allowed to converge waveform PAPR to target PAPR, when you set the RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_ENABLED attribute to RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_ENABLED_TRUE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10.\n \nGet Function: RFmxSpecAn_DPDGetPreDPDCFRMaximumIterations\n Set Function: RFmxSpecAn_DPDSetPreDPDCFRMaximumIterations\n'
        },
        'name': 'DPD_PRE_DPD_CFR_MAXIMUM_ITERATIONS',
        'type': 'int32'
    },
    1110078: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the method used to perform crest factor reduction (CFR) when you set the RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_ENABLED attribute to RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_ENABLED_TRUE. Refer to DPD concept topic for more information about CFR methods.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_METHOD_CLIPPING.\n \nGet Function: RFmxSpecAn_DPDGetPreDPDCFRMethod\n Set Function: RFmxSpecAn_DPDSetPreDPDCFRMethod\n'
        },
        'enum': 'DpdPreDpdCfrMethod',
        'name': 'DPD_PRE_DPD_CFR_METHOD',
        'type': 'int32'
    },
    1110080: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the DPD Lookup Table (LUT) type when you set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CONFIGURATION_INPUT attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CONFIGURATION_INPUT_USER.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nGet Function: RFmxSpecAn_DPDGetApplyDPDUserLookupTableType\n Set Function: RFmxSpecAn_DPDSetApplyDPDUserLookupTableType\n'
        },
        'enum': 'DpdApplyDpdUserLookupTableType',
        'name': 'DPD_APPLY_DPD_USER_LOOKUP_TABLE_TYPE',
        'type': 'int32'
    },
    1110081: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the target peak-to-average power ratio when you set the RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_ENABLED attribute to RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_ENABLED_TRUE. This value is expressed in dB.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 8.\n \nGet Function: RFmxSpecAn_DPDGetPreDPDCFRTargetPAPR\n Set Function: RFmxSpecAn_DPDSetPreDPDCFRTargetPAPR\n'
        },
        'name': 'DPD_PRE_DPD_CFR_TARGET_PAPR',
        'type': 'float64'
    },
    1110082: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the window type to be used when you set the RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_ENABLED attribute to RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_ENABLED_TRUE and the RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_METHOD attribute to RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_METHOD_PEAK_WINDOWING.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is  Kaiser-Bessel.\n \nGet Function: RFmxSpecAn_DPDGetPreDPDCFRWindowType\n Set Function: RFmxSpecAn_DPDSetPreDPDCFRWindowType\n'
        },
        'enum': 'DpdPreDpdCfrWindowType',
        'name': 'DPD_PRE_DPD_CFR_WINDOW_TYPE',
        'type': 'int32'
    },
    1110083: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum window length to be used when you set the RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_ENABLED attribute to RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_ENABLED_TRUE and the RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_METHOD attribute to RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_METHOD_PEAK_WINDOWING.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10.\n \nGet Function: RFmxSpecAn_DPDGetPreDPDCFRWindowLength\n Set Function: RFmxSpecAn_DPDSetPreDPDCFRWindowLength\n'
        },
        'name': 'DPD_PRE_DPD_CFR_WINDOW_LENGTH',
        'type': 'int32'
    },
    1110084: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the shaping factor to be used when you set the RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_ENABLED attribute to RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_ENABLED_TRUE and the RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_METHOD attribute to RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_METHOD_SIGMOID. Refer to the DPD concept topic for more information about shaping factor.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 5.\n \nGet Function: RFmxSpecAn_DPDGetPreDPDCFRShapingFactor\n Set Function: RFmxSpecAn_DPDSetPreDPDCFRShapingFactor\n'
        },
        'name': 'DPD_PRE_DPD_CFR_SHAPING_FACTOR',
        'type': 'float64'
    },
    1110085: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the shaping threshold to be used when you set the RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_ENABLED attribute to RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_ENABLED_TRUE and the RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_METHOD attribute to RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_METHOD_SIGMOID. This value is expressed in dB. Refer to the DPD concept topic for more information about shaping threshold.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is -5.\n \nGet Function: RFmxSpecAn_DPDGetPreDPDCFRShapingThreshold\n Set Function: RFmxSpecAn_DPDSetPreDPDCFRShapingThreshold\n'
        },
        'name': 'DPD_PRE_DPD_CFR_SHAPING_THRESHOLD',
        'type': 'float64'
    },
    1110086: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the crest factor reduction (CFR) on the pre-distorted waveform.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_DPDGetApplyDPDCFREnabled\n Set Function: RFmxSpecAn_DPDSetApplyDPDCFREnabled\n'
        },
        'enum': 'DpdApplyDpdCfrEnabled',
        'name': 'DPD_APPLY_DPD_CFR_ENABLED',
        'type': 'int32'
    },
    1110087: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the method used to perform the crest factor reduction (CFR) when you set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_ENABLED attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_ENABLED_TRUE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_METHOD_CLIPPING.\n \nGet Function: RFmxSpecAn_DPDGetApplyDPDCFRMethod\n Set Function: RFmxSpecAn_DPDSetApplyDPDCFRMethod\n'
        },
        'enum': 'DpdApplyDpdCfrMethod',
        'name': 'DPD_APPLY_DPD_CFR_METHOD',
        'type': 'int32'
    },
    1110088: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum number of iterations allowed to converge waveform PAPR to target PAPR when you set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_ENABLED attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_ENABLED_TRUE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10.\n \nGet Function: RFmxSpecAn_DPDGetApplyDPDCFRMaximumIterations\n Set Function: RFmxSpecAn_DPDSetApplyDPDCFRMaximumIterations\n'
        },
        'name': 'DPD_APPLY_DPD_CFR_MAXIMUM_ITERATIONS',
        'type': 'int32'
    },
    1110089: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the target PAPR type when you set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_ENABLED attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_ENABLED_TRUE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_TARGET_PAPR_TYPE_INPUT_PAPR.\n \nGet Function: RFmxSpecAn_DPDGetApplyDPDCFRTargetPAPRType\n Set Function: RFmxSpecAn_DPDSetApplyDPDCFRTargetPAPRType\n'
        },
        'enum': 'DpdApplyDpdCfrTargetPaprType',
        'name': 'DPD_APPLY_DPD_CFR_TARGET_PAPR_TYPE',
        'type': 'int32'
    },
    1110090: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the method used for synchronization of the acquired waveform with the reference waveform.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD_SYNCHRONIZATION_METHOD_DIRECT.\n \nGet Function: RFmxSpecAn_DPDGetSynchronizationMethod\n Set Function: RFmxSpecAn_DPDSetSynchronizationMethod\n'
        },
        'enum': 'DpdSynchronizationMethod',
        'name': 'DPD_SYNCHRONIZATION_METHOD',
        'type': 'int32'
    },
    1110091: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies if auto detection of carrier offset and carrier bandwidth is enabled.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD_AUTO_CARRIER_DETECTION_ENABLED_TRUE.\n \nGet Function: RFmxSpecAn_DPDGetAutoCarrierDetectionEnabled\n Set Function: RFmxSpecAn_DPDSetAutoCarrierDetectionEnabled\n'
        },
        'enum': 'DpdAutoCarrierDetectionEnabled',
        'name': 'DPD_AUTO_CARRIER_DETECTION_ENABLED',
        'type': 'int32'
    },
    1110092: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of carriers in the reference waveform when you set the RFMXSPECAN_ATTR_DPD_AUTO_CARRIER_DETECTION_ENABLED attribute to RFMXSPECAN_VAL_DPD_AUTO_CARRIER_DETECTION_ENABLED_FALSE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_DPDGetNumberOfCarriers\n Set Function: RFmxSpecAn_DPDSetNumberOfCarriers\n'
        },
        'name': 'DPD_NUMBER_OF_CARRIERS',
        'type': 'int32'
    },
    1110093: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the carrier offset when you set the RFMXSPECAN_ATTR_DPD_AUTO_CARRIER_DETECTION_ENABLED attribute to RFMXSPECAN_VAL_DPD_AUTO_CARRIER_DETECTION_ENABLED_FALSE. This value is expressed in Hz.\n \nUse 'carrier(n)' as the selector string to configure or read this attribute.\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_DPDGetCarrierOffset\n Set Function: RFmxSpecAn_DPDSetCarrierOffset\n"
        },
        'name': 'DPD_CARRIER_OFFSET',
        'type': 'float64'
    },
    1110094: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the carrier bandwidth when you set the RFMXSPECAN_ATTR_DPD_AUTO_CARRIER_DETECTION_ENABLED attribute to RFMXSPECAN_VAL_DPD_AUTO_CARRIER_DETECTION_ENABLED_FALSE. This value is expressed in Hz.\n \nUse 'carrier(n)' as the selector string to configure or read this attribute.\n \nThe default value is 20 MHz.\n \nGet Function: RFmxSpecAn_DPDGetCarrierBandwidth\n Set Function: RFmxSpecAn_DPDSetCarrierBandwidth\n"
        },
        'name': 'DPD_CARRIER_BANDWIDTH',
        'type': 'float64'
    },
    1110106: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the target PAPR when you set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_ENABLED attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_ENABLED_TRUE and the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_TARGET_PAPR_TYPE attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_TARGET_PAPR_TYPE_CUSTOM. This value is expressed in dB.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 8.\n \nGet Function: RFmxSpecAn_DPDGetApplyDPDCFRTargetPAPR\n Set Function: RFmxSpecAn_DPDSetApplyDPDCFRTargetPAPR\n'
        },
        'name': 'DPD_APPLY_DPD_CFR_TARGET_PAPR',
        'type': 'float64'
    },
    1110107: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the window type to be used when you set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_ENABLED attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_ENABLED_TRUE and the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_METHOD attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_METHOD_PEAK_WINDOWING.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is  Kaiser-Bessel.\n \nGet Function: RFmxSpecAn_DPDGetApplyDPDCFRWindowType\n Set Function: RFmxSpecAn_DPDSetApplyDPDCFRWindowType\n'
        },
        'enum': 'DpdApplyDpdCfrWindowType',
        'name': 'DPD_APPLY_DPD_CFR_WINDOW_TYPE',
        'type': 'int32'
    },
    1110108: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum window length to be used when you set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_ENABLED attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_ENABLED_TRUE and the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_METHOD attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_METHOD_PEAK_WINDOWING.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10.\n \nGet Function: RFmxSpecAn_DPDGetApplyDPDCFRWindowLength\n Set Function: RFmxSpecAn_DPDSetApplyDPDCFRWindowLength\n'
        },
        'name': 'DPD_APPLY_DPD_CFR_WINDOW_LENGTH',
        'type': 'int32'
    },
    1110109: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the shaping factor to be used when you set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_ENABLED attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_ENABLED_TRUE and the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_METHOD attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_METHOD_SIGMOID. Refer to DPD concept topic for more information about shaping factor.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 5.\n \nGet Function: RFmxSpecAn_DPDGetApplyDPDCFRShapingFactor\n Set Function: RFmxSpecAn_DPDSetApplyDPDCFRShapingFactor\n'
        },
        'name': 'DPD_APPLY_DPD_CFR_SHAPING_FACTOR',
        'type': 'float64'
    },
    1110110: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the shaping threshold to be used when you set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_ENABLED  attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_ENABLED_TRUE and the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_METHOD attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_METHOD_SIGMOID. This value is expressed in dB. Refer to DPD concept topic for more information about shaping threshold.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance.  Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is -5.\n \nGet Function: RFmxSpecAn_DPDGetApplyDPDCFRShapingThreshold\n Set Function: RFmxSpecAn_DPDSetApplyDPDCFRShapingThreshold\n'
        },
        'name': 'DPD_APPLY_DPD_CFR_SHAPING_THRESHOLD',
        'type': 'float64'
    },
    1110111: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the normalized mean-squared DPD modeling error when you set the RFMXSPECAN_ATTR_DPD_NMSE_ENABLED attribute to RFMXSPECAN_VAL_DPD_NMSE_ENABLED_TRUE. This value is expressed in dB. NaN is returned when the RFMXSPECAN_ATTR_DPD_NMSE_ENABLED attribute is set to RFMXSPECAN_VAL_DPD_NMSE_ENABLED_FALSE.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_DPDGetResultsNMSE\n'
        },
        'name': 'DPD_RESULTS_NMSE',
        'type': 'float64'
    },
    1110112: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the filtering operation when you set the RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_ENABLED attribute to RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_ENABLED_TRUE. Refer to DPD concept topic for more information about filtering.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_DPD__PRE_DPD_CFR_FILTER_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_DPDGetPreDPDCFRFilterEnabled\n Set Function: RFmxSpecAn_DPDSetPreDPDCFRFilterEnabled\n'
        },
        'enum': 'DpdPreDpdCfrFilterEnabled',
        'name': 'DPD_PRE_DPD_CFR_FILTER_ENABLED',
        'type': 'int32'
    },
    1110114: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of carriers in the input waveform when you set the RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_ENABLED attribute and the RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_FILTER_ENABLED attribute to RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_ENABLED_TRUE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_DPDGetPreDPDCFRNumberOfCarriers\n Set Function: RFmxSpecAn_DPDSetPreDPDCFRNumberOfCarriers\n'
        },
        'name': 'DPD_PRE_DPD_CFR_NUMBER_OF_CARRIERS',
        'type': 'int32'
    },
    1110115: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the carrier offset relative to the center of the complex baseband equivalent of the RF signal when you set the RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_ENABLED attribute and the RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_FILTER_ENABLED attribute to RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_ENABLED_TRUE. This value is expressed in Hz.\n \nUse 'carrier(n)' as the selector string to configure or read this attribute.\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_DPDGetPreDPDCarrierOffset\n Set Function: RFmxSpecAn_DPDSetPreDPDCarrierOffset\n"
        },
        'name': 'DPD_PRE_DPD_CARRIER_OFFSET',
        'type': 'float64'
    },
    1110116: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the carrier bandwidth when you set the RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_ENABLED attribute and the RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_FILTER_ENABLED attribute to RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_ENABLED_TRUE. This value is expressed in Hz.\n \nUse 'carrier(n)' as the selector string to configure or read this attribute.\n \nThe default value is 20 MHz.\n \nGet Function: RFmxSpecAn_DPDGetPreDPDCarrierBandwidth\n Set Function: RFmxSpecAn_DPDSetPreDPDCarrierBandwidth\n"
        },
        'name': 'DPD_PRE_DPD_CARRIER_BANDWIDTH',
        'type': 'float64'
    },
    1110117: {
        'access': 'read-write',
        'documentation': {
            'description': ' Enables the IQ origin offset correction for the measurement.\n \nWhen you set this attribute to True, the measurement computes and corrects any origin offset between the reference and the acquired waveforms. When you set this attribute to False, origin offset correction is not performed.\n \nThe default value is RFMXSPECAN_VAL_DPD_IQ_ORIGIN_OFFSET_CORRECTION_ENABLED_TRUE.\n \nGet Function: RFmxSpecAn_DPDGetIQOriginOffsetCorrectionEnabled\n Set Function: RFmxSpecAn_DPDSetIQOriginOffsetCorrectionEnabled\n'
        },
        'enum': 'DpdIQOriginOffsetCorrectionEnabled',
        'name': 'DPD_IQ_ORIGIN_OFFSET_CORRECTION_ENABLED',
        'type': 'int32'
    },
    1110272: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the I/Q measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_IQGetMeasurementEnabled\n Set Function: RFmxSpecAn_IQSetMeasurementEnabled\n'
        },
        'name': 'IQ_MEASUREMENT_ENABLED',
        'type': 'int32'
    },
    1110274: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the acquisition sample rate. This value is expressed in samples per second (S/s).\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 50 MS/s.\n \nGet Function: RFmxSpecAn_IQGetSampleRate\n Set Function: RFmxSpecAn_IQSetSampleRate\n'
        },
        'name': 'IQ_SAMPLE_RATE',
        'type': 'float64'
    },
    1110275: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of records to acquire.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_IQGetNumberOfRecords\n Set Function: RFmxSpecAn_IQSetNumberOfRecords\n'
        },
        'name': 'IQ_NUMBER_OF_RECORDS',
        'type': 'int32'
    },
    1110276: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the acquisition time for the I/Q measurement. This value is expressed in seconds.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.001.\n \nGet Function: RFmxSpecAn_IQGetAcquisitionTime\n Set Function: RFmxSpecAn_IQSetAcquisitionTime\n'
        },
        'name': 'IQ_ACQUISITION_TIME',
        'type': 'float64'
    },
    1110277: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the pretrigger time for the I/Q measurement. This value is expressed in seconds.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_IQGetPretriggerTime\n Set Function: RFmxSpecAn_IQSetPretriggerTime\n'
        },
        'name': 'IQ_PRETRIGGER_TIME',
        'type': 'float64'
    },
    1110280: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the measurement computes the minimum acquisition bandwidth.\n \n\n \nThe default value is RFMXSPECAN_VAL_IQ_AUTO_BANDWIDTH_TRUE.\n \nGet Function: RFmxSpecAn_IQGetBandwidthAuto\n Set Function: RFmxSpecAn_IQSetBandwidthAuto\n'
        },
        'enum': 'IQBandwidthAuto',
        'name': 'IQ_BANDWIDTH_AUTO',
        'type': 'int32'
    },
    1110281: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the minimum acquisition bandwidth when you set the RFMXSPECAN_ATTR_IQ_BANDWIDTH_AUTO attribute to RFMXSPECAN_VAL_IQ_AUTO_BANDWIDTH_FALSE. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1 MHz.\n \nGet Function: RFmxSpecAn_IQGetBandwidth\n Set Function: RFmxSpecAn_IQSetBandwidth\n'
        },
        'name': 'IQ_BANDWIDTH',
        'type': 'float64'
    },
    1110282: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the measurement deletes the fetched record.\n \n\n \nThe default value is RFMXSPECAN_VAL_IQ_DELETE_RECORD_ON_FETCH_TRUE.\n \nGet Function: RFmxSpecAn_IQGetDeleteRecordOnFetch\n Set Function: RFmxSpecAn_IQSetDeleteRecordOnFetch\n'
        },
        'enum': 'IQDeleteRecordOnFetch',
        'name': 'IQ_DELETE_RECORD_ON_FETCH',
        'type': 'int32'
    },
    1114112: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the IM measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_IMGetMeasurementEnabled\n Set Function: RFmxSpecAn_IMSetMeasurementEnabled\n'
        },
        'name': 'IM_MEASUREMENT_ENABLED',
        'type': 'int32'
    },
    1114114: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the tones and intermod frequencies are relative to the RF center frequency, or are absolute frequencies.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_IM_FREQUENCY_DEFINITION_RELATIVE.\n \nGet Function: RFmxSpecAn_IMGetFrequencyDefinition\n Set Function: RFmxSpecAn_IMSetFrequencyDefinition\n'
        },
        'enum': 'IMFrequencyDefinition',
        'name': 'IM_FREQUENCY_DEFINITION',
        'type': 'int32'
    },
    1114115: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the frequency of the tone that has a lower frequency among the two tones in the input signal. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is -1 MHz.\n \nGet Function: RFmxSpecAn_IMGetFundamentalLowerToneFrequency\n Set Function: RFmxSpecAn_IMSetFundamentalLowerToneFrequency\n'
        },
        'name': 'IM_FUNDAMENTAL_LOWER_TONE_FREQUENCY',
        'type': 'float64'
    },
    1114116: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the frequency of the tone that has a higher frequency among the two tones in the input signal. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1 MHz.\n \nGet Function: RFmxSpecAn_IMGetFundamentalUpperToneFrequency\n Set Function: RFmxSpecAn_IMSetFundamentalUpperToneFrequency\n'
        },
        'name': 'IM_FUNDAMENTAL_UPPER_TONE_FREQUENCY',
        'type': 'float64'
    },
    1114117: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the measurement computes the intermod frequencies or uses user-specified frequencies.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_IM_AUTO_INTERMODS_SETUP_ENABLED_TRUE.\n \nGet Function: RFmxSpecAn_IMGetAutoIntermodsSetupEnabled\n Set Function: RFmxSpecAn_IMSetAutoIntermodsSetupEnabled\n'
        },
        'enum': 'IMAutoIntermodsSetupEnabled',
        'name': 'IM_AUTO_INTERMODS_SETUP_ENABLED',
        'type': 'int32'
    },
    1114118: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the order up to which the RFmx driver measures odd order intermodulation products when you set the Auto Intermods Setup Enabled attribute to True. The lower and upper intermodulation products are measured for each order.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 3.\n \nGet Function: RFmxSpecAn_IMGetMaximumIntermodOrder\n Set Function: RFmxSpecAn_IMSetMaximumIntermodOrder\n'
        },
        'name': 'IM_MAXIMUM_INTERMOD_ORDER',
        'type': 'int32'
    },
    1114119: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of intermods to measure when you set the RFMXSPECAN_ATTR_IM_AUTO_INTERMODS_SETUP_ENABLED attribute to RFMXSPECAN_VAL_IM_AUTO_INTERMODS_SETUP_ENABLED_FALSE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_IMGetNumberOfIntermods\n Set Function: RFmxSpecAn_IMSetNumberOfIntermods\n'
        },
        'name': 'IM_NUMBER_OF_INTERMODS',
        'type': 'int32'
    },
    1114120: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies whether to enable an intermod for the IM measurement. This attribute is not used when you set the RFMXSPECAN_ATTR_IM_AUTO_INTERMODS_SETUP_ENABLED attribute to RFMXSPECAN_VAL_IM_AUTO_INTERMODS_SETUP_ENABLED_TRUE.\n \nUse 'intermod(n)' as the selector string to configure or read this attribute.\n \nThe default value is RFMXSPECAN_VAL_IM_INTERMOD_ENABLED_TRUE.\n \nGet Function: RFmxSpecAn_IMGetIntermodEnabled\n Set Function: RFmxSpecAn_IMSetIntermodEnabled\n"
        },
        'enum': 'IMIntermodEnabled',
        'name': 'IM_INTERMOD_ENABLED',
        'type': 'int32'
    },
    1114121: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the order of the intermod. This attribute is not used when you set the RFMXSPECAN_ATTR_IM_AUTO_INTERMODS_SETUP_ENABLED attribute to RFMXSPECAN_VAL_IM_AUTO_INTERMODS_SETUP_ENABLED_TRUE.\n \nUse 'intermod(n)' as the selector string to configure or read this attribute.\n \nThe default value is 3.\n \nGet Function: RFmxSpecAn_IMGetIntermodOrder\n Set Function: RFmxSpecAn_IMSetIntermodOrder\n"
        },
        'name': 'IM_INTERMOD_ORDER',
        'type': 'int32'
    },
    1114122: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies whether to measure intermodulation products corresponding to both lower and upper intermod frequencies or either one of them. This attribute is not used when you set the RFMXSPECAN_ATTR_IM_AUTO_INTERMODS_SETUP_ENABLED attribute to RFMXSPECAN_VAL_IM_AUTO_INTERMODS_SETUP_ENABLED_TRUE.\n \nUse 'intermod(n)' as the selector string to configure or read this attribute.\n \nThe default value is RFMXSPECAN_VAL_IM_INTERMOD_SIDE_BOTH.\n \nGet Function: RFmxSpecAn_IMGetIntermodSide\n Set Function: RFmxSpecAn_IMSetIntermodSide\n"
        },
        'enum': 'IMIntermodSide',
        'name': 'IM_INTERMOD_SIDE',
        'type': 'int32'
    },
    1114123: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the frequency of the lower intermodulation product. This value is expressed in Hz. This attribute is not used when you set the RFMXSPECAN_ATTR_IM_AUTO_INTERMODS_SETUP_ENABLED attribute to RFMXSPECAN_VAL_IM_AUTO_INTERMODS_SETUP_ENABLED_TRUE.\n \nUse 'intermod(n)' as the selector string to configure or read this attribute.\n \nThe default value is -3 MHz.\n \nGet Function: RFmxSpecAn_IMGetLowerIntermodFrequency\n Set Function: RFmxSpecAn_IMSetLowerIntermodFrequency\n"
        },
        'name': 'IM_LOWER_INTERMOD_FREQUENCY',
        'type': 'float64'
    },
    1114124: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the frequency of the upper intermodulation product. This value is expressed in Hz. This attribute is not used when you set the RFMXSPECAN_ATTR_IM_AUTO_INTERMODS_SETUP_ENABLED attribute to RFMXSPECAN_VAL_IM_AUTO_INTERMODS_SETUP_ENABLED_TRUE.\n \nUse 'intermod(n)' as the selector string to configure or read this attribute.\n \nThe default value is 3 MHz.\n \nGet Function: RFmxSpecAn_IMGetUpperIntermodFrequency\n Set Function: RFmxSpecAn_IMSetUpperIntermodFrequency\n"
        },
        'name': 'IM_UPPER_INTERMOD_FREQUENCY',
        'type': 'float64'
    },
    1114125: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the method used to perform the IM measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_IM_MEASUREMENT_METHOD_NORMAL.\n \nGet Function: RFmxSpecAn_IMGetMeasurementMethod\n Set Function: RFmxSpecAn_IMSetMeasurementMethod\n'
        },
        'enum': 'IMMeasurementMethod',
        'name': 'IM_MEASUREMENT_METHOD',
        'type': 'int32'
    },
    1114126: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the measurement computes the RBW.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_IM_RBW_FILTER_AUTO_BANDWIDTH_TRUE.\n \nGet Function: RFmxSpecAn_IMGetRBWFilterAutoBandwidth\n Set Function: RFmxSpecAn_IMSetRBWFilterAutoBandwidth\n'
        },
        'enum': 'IMRbwFilterAutoBandwidth',
        'name': 'IM_RBW_FILTER_AUTO_BANDWIDTH',
        'type': 'int32'
    },
    1114127: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the bandwidth of the RBW filter used to sweep the acquired signal, when you set the RFMXSPECAN_ATTR_IM_RBW_FILTER_AUTO_BANDWIDTH attribute to RFMXSPECAN_VAL_IM_RBW_FILTER_AUTO_BANDWIDTH_FALSE. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10 kHz.\n \nGet Function: RFmxSpecAn_IMGetRBWFilterBandwidth\n Set Function: RFmxSpecAn_IMSetRBWFilterBandwidth\n'
        },
        'name': 'IM_RBW_FILTER_BANDWIDTH',
        'type': 'float64'
    },
    1114128: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the response of the digital RBW filter.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_IM_RBW_FILTER_TYPE_GAUSSIAN.\n \nGet Function: RFmxSpecAn_IMGetRBWFilterType\n Set Function: RFmxSpecAn_IMSetRBWFilterType\n'
        },
        'enum': 'IMRbwFilterType',
        'name': 'IM_RBW_FILTER_TYPE',
        'type': 'int32'
    },
    1114129: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the measurement computes the sweep time.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_IM_SWEEP_TIME_AUTO_TRUE.\n \nGet Function: RFmxSpecAn_IMGetSweepTimeAuto\n Set Function: RFmxSpecAn_IMSetSweepTimeAuto\n'
        },
        'enum': 'IMSweepTimeAuto',
        'name': 'IM_SWEEP_TIME_AUTO',
        'type': 'int32'
    },
    1114130: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the sweep time when you set the RFMXSPECAN_ATTR_IM_SWEEP_TIME_AUTO attribute to RFMXSPECAN_VAL_IM_SWEEP_TIME_AUTO_FALSE. This value is expressed in seconds.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.001.\n \nGet Function: RFmxSpecAn_IMGetSweepTimeInterval\n Set Function: RFmxSpecAn_IMSetSweepTimeInterval\n'
        },
        'name': 'IM_SWEEP_TIME_INTERVAL',
        'type': 'float64'
    },
    1114131: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable averaging for the IM measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_IM_AVERAGING_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_IMGetAveragingEnabled\n Set Function: RFmxSpecAn_IMSetAveragingEnabled\n'
        },
        'enum': 'IMAveragingEnabled',
        'name': 'IM_AVERAGING_ENABLED',
        'type': 'int32'
    },
    1114132: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of acquisitions used for averaging when you set the RFMXSPECAN_ATTR_IM_AVERAGING_ENABLED attribute to RFMXSPECAN_VAL_IM_AVERAGING_ENABLED_TRUE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10.\n \nGet Function: RFmxSpecAn_IMGetAveragingCount\n Set Function: RFmxSpecAn_IMSetAveragingCount\n'
        },
        'name': 'IM_AVERAGING_COUNT',
        'type': 'int32'
    },
    1114134: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the averaging type for averaging multiple spectrum acquisitions. The averaged spectrum is used for the IM measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_IM_AVERAGING_TYPE_RMS.\n \nGet Function: RFmxSpecAn_IMGetAveragingType\n Set Function: RFmxSpecAn_IMSetAveragingType\n'
        },
        'enum': 'IMAveragingType',
        'name': 'IM_AVERAGING_TYPE',
        'type': 'int32'
    },
    1114135: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the FFT window type to use to reduce spectral leakage.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_IM_FFT_WINDOW_FLAT_TOP.\n \nGet Function: RFmxSpecAn_IMGetFFTWindow\n Set Function: RFmxSpecAn_IMSetFFTWindow\n'
        },
        'enum': 'IMFftWindow',
        'name': 'IM_FFT_WINDOW',
        'type': 'int32'
    },
    1114136: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the factor by which the time-domain waveform is zero-padded before an FFT. The FFT size is given by the following formula:        \n\n   FFT size = waveform size * padding        \n\nThis attribute is used only when the acquisition span is less than the device instantaneous bandwidth.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is -1.\n \nGet Function: RFmxSpecAn_IMGetFFTPadding\n Set Function: RFmxSpecAn_IMSetFFTPadding\n'
        },
        'name': 'IM_FFT_PADDING',
        'type': 'float64'
    },
    1114137: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the measurement computes an IF output power level offset for the intermods to maximize the dynamic range of the signal analyzer. This attribute is used only if you set the RFMXSPECAN_ATTR_IM_MEASUREMENT_METHOD attribute to RFMXSPECAN_VAL_IM_MEASUREMENT_METHOD_DYNAMIC_RANGE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_IM_IF_OUTPUT_POWER_OFFSET_AUTO_TRUE.\n \nGet Function: RFmxSpecAn_IMGetIFOutputPowerOffsetAuto\n Set Function: RFmxSpecAn_IMSetIFOutputPowerOffsetAuto\n'
        },
        'enum': 'IMIFOutputPowerOffsetAuto',
        'name': 'IM_IF_OUTPUT_POWER_OFFSET_AUTO',
        'type': 'int32'
    },
    1114138: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the offset by which to adjust the IF output power level for the intermods near the carrier channel to improve the dynamic range of the signal analyzer. This value is expressed in dB. This attribute is used only if you set the RFMXSPECAN_ATTR_IM_MEASUREMENT_METHOD attribute to RFMXSPECAN_VAL_IM_MEASUREMENT_METHOD_DYNAMIC_RANGE and the RFMXSPECAN_ATTR_IM_IF_OUTPUT_POWER_OFFSET_AUTO attribute to RFMXSPECAN_VAL_IM_IF_OUTPUT_POWER_OFFSET_AUTO_FALSE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10 dB.\n \nGet Function: RFmxSpecAn_IMGetNearIFOutputPowerOffset\n Set Function: RFmxSpecAn_IMSetNearIFOutputPowerOffset\n'
        },
        'name': 'IM_NEAR_IF_OUTPUT_POWER_OFFSET',
        'type': 'float64'
    },
    1114139: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the offset by which to adjust the IF output power level for the intermods that are far from the carrier channel to improve the dynamic range of the signal analyzer. This value is expressed in dB. This attribute is used only if you set the RFMXSPECAN_ATTR_IM_MEASUREMENT_METHOD attribute to RFMXSPECAN_VAL_IM_MEASUREMENT_METHOD_DYNAMIC_RANGE and the RFMXSPECAN_ATTR_IM_IF_OUTPUT_POWER_OFFSET_AUTO attribute to RFMXSPECAN_VAL_IM_IF_OUTPUT_POWER_OFFSET_AUTO_FALSE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 20 dB.\n \nGet Function: RFmxSpecAn_IMGetFarIFOutputPowerOffset\n Set Function: RFmxSpecAn_IMSetFarIFOutputPowerOffset\n'
        },
        'name': 'IM_FAR_IF_OUTPUT_POWER_OFFSET',
        'type': 'float64'
    },
    1114140: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the traces to be stored and retrieved after performing the IM measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_IMGetAllTracesEnabled\n Set Function: RFmxSpecAn_IMSetAllTracesEnabled\n'
        },
        'name': 'IM_ALL_TRACES_ENABLED',
        'type': 'int32'
    },
    1114141: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum number of threads used for parallelism for the IM measurement.          \n\nThe number of threads can range from 1 to the number of physical cores. The number of threads you set may not be used in calculations. The actual number of threads used depends on the problem size, system resources, data availability, and other considerations.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_IMGetNumberOfAnalysisThreads\n Set Function: RFmxSpecAn_IMSetNumberOfAnalysisThreads\n'
        },
        'name': 'IM_NUMBER_OF_ANALYSIS_THREADS',
        'type': 'int32'
    },
    1114143: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the peak power measured around the lower tone frequency when you set the RFMXSPECAN_ATTR_IM_LOCAL_PEAK_SEARCH_ENABLED attribute to RFMXSPECAN_VAL_IM_LOCAL_PEAK_SEARCH_ENABLED_TRUE. This value is expressed in dBm. When you set the RFMXSPECAN_ATTR_IM_LOCAL_PEAK_SEARCH_ENABLED attribute to RFMXSPECAN_VAL_IM_LOCAL_PEAK_SEARCH_ENABLED_FALSE, the measurement returns the power at the lower tone frequency.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_IMGetResultsFundamentalLowerTonePower\n'
        },
        'name': 'IM_RESULTS_LOWER_TONE_POWER',
        'type': 'float64'
    },
    1114145: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the peak power measured around the upper tone frequency when you set the RFMXSPECAN_ATTR_IM_LOCAL_PEAK_SEARCH_ENABLED attribute to RFMXSPECAN_VAL_IM_LOCAL_PEAK_SEARCH_ENABLED_TRUE. This value is expressed in dBm. When you set the RFMXSPECAN_ATTR_IM_LOCAL_PEAK_SEARCH_ENABLED attribute to RFMXSPECAN_VAL_IM_LOCAL_PEAK_SEARCH_ENABLED_FALSE, the measurement returns the power at the upper tone frequency.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_IMGetResultsFundamentalUpperTonePower\n'
        },
        'name': 'IM_RESULTS_UPPER_TONE_POWER',
        'type': 'float64'
    },
    1114146: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the order of the intermod.\n \nUse 'intermod(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_IMGetResultsIntermodOrder\n"
        },
        'name': 'IM_RESULTS_INTERMOD_ORDER',
        'type': 'int32'
    },
    1114148: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the peak power measured around the lower intermod frequency when you set the RFMXSPECAN_ATTR_IM_LOCAL_PEAK_SEARCH_ENABLED attribute to RFMXSPECAN_VAL_IM_LOCAL_PEAK_SEARCH_ENABLED_TRUE. This value is expressed in dBm. When you set the RFMXSPECAN_ATTR_IM_LOCAL_PEAK_SEARCH_ENABLED attribute to RFMXSPECAN_VAL_IM_LOCAL_PEAK_SEARCH_ENABLED_FALSE, the measurement returns the power at the lower intermod frequency.\n \nUse 'intermod(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_IMGetResultsLowerIntermodPower\n"
        },
        'name': 'IM_RESULTS_LOWER_INTERMOD_POWER',
        'type': 'float64'
    },
    1114150: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the peak power measured around the upper intermod frequency when you set the RFMXSPECAN_ATTR_IM_LOCAL_PEAK_SEARCH_ENABLED attribute to RFMXSPECAN_VAL_IM_LOCAL_PEAK_SEARCH_ENABLED_TRUE. This value is expressed in dBm. When you set the RFMXSPECAN_ATTR_IM_LOCAL_PEAK_SEARCH_ENABLED attribute to RFMXSPECAN_VAL_IM_LOCAL_PEAK_SEARCH_ENABLED_FALSE, the measurement returns the power at the upper intermod frequency.\n \nUse 'intermod(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_IMGetResultsUpperIntermodPower\n"
        },
        'name': 'IM_RESULTS_UPPER_INTERMOD_POWER',
        'type': 'float64'
    },
    1114151: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the lower output intercept power. This value is expressed in dBm. Refer to the IM topic for more information about this result.\n \nUse 'intermod(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_IMGetResultsLowerOutputInterceptPower\n"
        },
        'name': 'IM_RESULTS_LOWER_OUTPUT_INTERCEPT_POWER',
        'type': 'float64'
    },
    1114152: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the upper output intercept power. This value is expressed in dBm. Refer to the IM topic for more information about this result.\n \nUse 'intermod(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_IMGetResultsUpperOutputInterceptPower\n"
        },
        'name': 'IM_RESULTS_UPPER_OUTPUT_INTERCEPT_POWER',
        'type': 'float64'
    },
    1114153: {
        'access': 'read-write',
        'documentation': {
            'description': " Returns the worst case output intercept power which is equal to the minimum of the values of the IM Results Upper Output Intercept Power and IM Results Lower Output Intercept Power results. This value is expressed in dBm.\n \nUse 'intermod(n)' as the selector string to read this result.\n \nGet Function: RFmxSpecAn_IMGetResultsWorstCaseOutputInterceptPower\n"
        },
        'name': 'IM_RESULTS_WORST_CASE_OUTPUT_INTERCEPT_POWER',
        'type': 'float64'
    },
    1114154: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable a local peak search around the tone or intermod frequencies to account for small frequency offsets.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_IM_LOCAL_PEAK_SEARCH_ENABLED_TRUE.\n \nGet Function: RFmxSpecAn_IMGetLocalPeakSearchEnabled\n Set Function: RFmxSpecAn_IMSetLocalPeakSearchEnabled\n'
        },
        'enum': 'IMLocalPeakSearchEnabled',
        'name': 'IM_LOCAL_PEAK_SEARCH_ENABLED',
        'type': 'int32'
    },
    1114155: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the amplitude of the frequency bins, used in the measurement, is corrected for external attenuation at the RF center frequency, or at the individual frequency bins. Use the RFmxInstr_CfgExternalAttenuationTable function to configure the external attenuation table.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_IM_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY.\n \nGet Function: RFmxSpecAn_IMGetAmplitudeCorrectionType\n Set Function: RFmxSpecAn_IMSetAmplitudeCorrectionType\n'
        },
        'enum': 'IMAmplitudeCorrectionType',
        'name': 'IM_AMPLITUDE_CORRECTION_TYPE',
        'type': 'int32'
    },
    1179649: {
        'access': 'read-write',
        'documentation': {
            'description': ' Enables the noise figure (NF) measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_NFGetMeasurementEnabled\n Set Function: RFmxSpecAn_NFSetMeasurementEnabled\n'
        },
        'name': 'NF_MEASUREMENT_ENABLED',
        'type': 'int32'
    },
    1179652: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the list of frequencies at which the noise figure (NF) of the DUT is computed. This value is expressed in Hz.\n \n\n \nThe default value is an empty array.\n \nGet Function: RFmxSpecAn_NFGetFrequencyList\n Set Function: RFmxSpecAn_NFSetFrequencyList\n'
        },
        'name': 'NF_FREQUENCY_LIST',
        'type': 'float64[]'
    },
    1179653: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the effective noise-bandwidth in which power measurements are performed for the noise figure (NF) measurement. This value is expressed in Hz.\n \n\n \nThe default value is 100 kHz.\n \nGet Function: RFmxSpecAn_NFGetMeasurementBandwidth\n Set Function: RFmxSpecAn_NFSetMeasurementBandwidth\n'
        },
        'name': 'NF_MEASUREMENT_BANDWIDTH',
        'type': 'float64'
    },
    1179654: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the duration for which the signals are acquired at each frequency which you specify in the RFMXSPECAN_ATTR_NF_FREQUENCY_LIST attribute. This value is expressed in seconds.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1 ms.\n \nGet Function: RFmxSpecAn_NFGetMeasurementInterval\n Set Function: RFmxSpecAn_NFSetMeasurementInterval\n'
        },
        'name': 'NF_MEASUREMENT_INTERVAL',
        'type': 'float64'
    },
    1179655: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable averaging for the noise figure (NF) measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_NF_AVERAGING_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_NFGetAveragingEnabled\n Set Function: RFmxSpecAn_NFSetAveragingEnabled\n'
        },
        'enum': 'NFAveragingEnabled',
        'name': 'NF_AVERAGING_ENABLED',
        'type': 'int32'
    },
    1179656: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of acquisitions used for averaging when you set the RFMXSPECAN_ATTR_NF_AVERAGING_ENABLED attribute to RFMXSPECAN_VAL_NF_AVERAGING_ENABLED_TRUE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10.\n \nGet Function: RFmxSpecAn_NFGetAveragingCount\n Set Function: RFmxSpecAn_NFSetAveragingCount\n'
        },
        'name': 'NF_AVERAGING_COUNT',
        'type': 'int32'
    },
    1179657: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the measurement method used to perform the noise figure (NF) measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is  Y-Factor.\n \nGet Function: RFmxSpecAn_NFGetMeasurementMethod\n Set Function: RFmxSpecAn_NFSetMeasurementMethod\n'
        },
        'enum': 'NFMeasurementMethod',
        'name': 'NF_MEASUREMENT_METHOD',
        'type': 'int32'
    },
    1179658: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the measurement should calibrate the noise characteristics of the analyzer or compute the noise characteristics of the DUT when you set the RFMXSPECAN_ATTR_NF_MEASUREMENT_METHOD attribute to RFMXSPECAN_VAL_NF_MEASUREMENT_METHOD_Y_FACTOR.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_NF_Y_FACTOR_MODE_MEASURE.\n \nGet Function: RFmxSpecAn_NFGetYFactorMode\n Set Function: RFmxSpecAn_NFSetYFactorMode\n'
        },
        'enum': 'NFYFactorMode',
        'name': 'NF_Y_FACTOR_MODE',
        'type': 'int32'
    },
    1179660: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the array of effective noise ratio (ENR) values of the noise source as a function of the frequency. This value is expressed in dB. The corresponding frequencies are specified by the RFMXSPECAN_ATTR_NF_Y_FACTOR_NOISE_SOURCE_ENR_FREQUENCY attribute. This attribute is used only when you set the RFMXSPECAN_ATTR_NF_MEASUREMENT_METHOD attribute to RFMXSPECAN_VAL_NF_MEASUREMENT_METHOD_Y_FACTOR.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is an empty array.\n \nGet Function: RFmxSpecAn_NFGetYFactorNoiseSourceENR\n Set Function: RFmxSpecAn_NFSetYFactorNoiseSourceENR\n'
        },
        'name': 'NF_Y_FACTOR_NOISE_SOURCE_ENR',
        'type': 'float64[]'
    },
    1179661: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies an array of frequencies corresponding to the effective noise ratio (ENR) values specified by the RFMXSPECAN_ATTR_NF_Y_FACTOR_NOISE_SOURCE_ENR attribute. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is an empty array.\n \nGet Function: RFmxSpecAn_NFGetYFactorNoiseSourceENRFrequency\n Set Function: RFmxSpecAn_NFSetYFactorNoiseSourceENRFrequency\n'
        },
        'name': 'NF_Y_FACTOR_NOISE_SOURCE_ENR_FREQUENCY',
        'type': 'float64[]'
    },
    1179662: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the calibrated cold noise temperature of the noise source used in the Y-Factor method. This value is expressed in kelvin.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 302.8.\n \nGet Function: RFmxSpecAn_NFGetYFactorNoiseSourceColdTemperature\n Set Function: RFmxSpecAn_NFSetYFactorNoiseSourceColdTemperature\n'
        },
        'name': 'NF_Y_FACTOR_NOISE_SOURCE_COLD_TEMPERATURE',
        'type': 'float64'
    },
    1179663: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the physical temperature of the noise source used in the Y-Factor method when the noise source is turned off. This value is expressed in kelvin.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 297.\n \nGet Function: RFmxSpecAn_NFGetYFactorNoiseSourceOffTemperature\n Set Function: RFmxSpecAn_NFSetYFactorNoiseSourceOffTemperature\n'
        },
        'name': 'NF_Y_FACTOR_NOISE_SOURCE_OFF_TEMPERATURE',
        'type': 'float64'
    },
    1179664: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the time to wait till the noise source used in the Y-Factor method settles to either hot or cold state when the noise source is turned on or off. This value is expressed in seconds.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.\n \nGet Function: RFmxSpecAn_NFGetYFactorNoiseSourceSettlingTime\n Set Function: RFmxSpecAn_NFSetYFactorNoiseSourceSettlingTime\n'
        },
        'name': 'NF_Y_FACTOR_NOISE_SOURCE_SETTLING_TIME',
        'type': 'float64'
    },
    1179665: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the noise figure (NF) measurement accounts for ohmic losses between the noise source and the input port of the DUT, excluding the losses that are common to calibration and the measurement steps for the Y-Factor method, which are specified by the RFMXSPECAN_ATTR_NF_Y_FACTOR_NOISE_SOURCE_LOSS attribute.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_NF_DUT_INPUT_LOSS_COMPENSATION_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_NFGetDUTInputLossCompensationEnabled\n Set Function: RFmxSpecAn_NFSetDUTInputLossCompensationEnabled\n'
        },
        'enum': 'NFDutInputLossCompensationEnabled',
        'name': 'NF_DUT_INPUT_LOSS_COMPENSATION_ENABLED',
        'type': 'int32'
    },
    1179666: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies an array of the ohmic losses between the noise source and the input port of the DUT, as a function of the frequency. This value is expressed in dB. This loss is accounted for by the NF measurement when you set the RFMXSPECAN_ATTR_NF_DUT_INPUT_LOSS_COMPENSATION_ENABLED attribute to RFMXSPECAN_VAL_NF_DUT_INPUT_LOSS_COMPENSATION_ENABLED_TRUE. You must exclude any loss which is inherent to the noise source and is common between the calibration and measurement steps, and configure the loss using the RFMXSPECAN_ATTR_NF_Y_FACTOR_NOISE_SOURCE_LOSS attribute.        \n\nSpecify the frequencies at which the losses were measured using the RFMXSPECAN_ATTR_NF_DUT_INPUT_LOSS_FREQUENCY attribute.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is an empty array.\n \nGet Function: RFmxSpecAn_NFGetDUTInputLoss\n Set Function: RFmxSpecAn_NFSetDUTInputLoss\n'
        },
        'name': 'NF_DUT_INPUT_LOSS',
        'type': 'float64[]'
    },
    1179667: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies an array of frequencies corresponding to the value of the RFMXSPECAN_ATTR_NF_DUT_INPUT_LOSS attribute. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is an empty array.\n \nGet Function: RFmxSpecAn_NFGetDUTInputLossFrequency\n Set Function: RFmxSpecAn_NFSetDUTInputLossFrequency\n'
        },
        'name': 'NF_DUT_INPUT_LOSS_FREQUENCY',
        'type': 'float64[]'
    },
    1179668: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the physical temperature of the ohmic loss elements considered in the RFMXSPECAN_ATTR_NF_DUT_INPUT_LOSS attribute. This value is expressed in kelvin.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 297.\n \nGet Function: RFmxSpecAn_NFGetDUTInputLossTemperature\n Set Function: RFmxSpecAn_NFSetDUTInputLossTemperature\n'
        },
        'name': 'NF_DUT_INPUT_LOSS_TEMPERATURE',
        'type': 'float64'
    },
    1179669: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the noise figure (NF) measurement accounts for ohmic losses between the output port of the DUT and the input port of the analyzer.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_NF_DUT_OUTPUT_LOSS_COMPENSATION_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_NFGetDUTOutputLossCompensationEnabled\n Set Function: RFmxSpecAn_NFSetDUTOutputLossCompensationEnabled\n'
        },
        'enum': 'NFDutOutputLossCompensationEnabled',
        'name': 'NF_DUT_OUTPUT_LOSS_COMPENSATION_ENABLED',
        'type': 'int32'
    },
    1179670: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the array of ohmic losses between the output port of the DUT and the input port of the analyzer, as a function of frequency. This value is expressed in dB. This loss is accounted for by the noise figure (NF) measurement when you set the RFMXSPECAN_ATTR_NF_DUT_OUTPUT_LOSS_COMPENSATION_ENABLED attribute to RFMXSPECAN_VAL_NF_DUT_OUTPUT_LOSS_COMPENSATION_ENABLED_TRUE.        \n\nSpecify the array of frequencies at which the losses were measured using the RFMXSPECAN_ATTR_NF_DUT_OUTPUT_LOSS_FREQUENCY attribute.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is an empty array.\n \nGet Function: RFmxSpecAn_NFGetDUTOutputLoss\n Set Function: RFmxSpecAn_NFSetDUTOutputLoss\n'
        },
        'name': 'NF_DUT_OUTPUT_LOSS',
        'type': 'float64[]'
    },
    1179671: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the array of frequencies corresponding to the value of the RFMXSPECAN_ATTR_NF_DUT_OUTPUT_LOSS  attribute. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is an empty array.\n \nGet Function: RFmxSpecAn_NFGetDUTOutputLossFrequency\n Set Function: RFmxSpecAn_NFSetDUTOutputLossFrequency\n'
        },
        'name': 'NF_DUT_OUTPUT_LOSS_FREQUENCY',
        'type': 'float64[]'
    },
    1179672: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the physical temperature of the ohmic loss elements specified by the RFMXSPECAN_ATTR_NF_DUT_OUTPUT_LOSS attribute. This value is expressed in kelvin.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 297.\n \nGet Function: RFmxSpecAn_NFGetDUTOutputLossTemperature\n Set Function: RFmxSpecAn_NFSetDUTOutputLossTemperature\n'
        },
        'name': 'NF_DUT_OUTPUT_LOSS_TEMPERATURE',
        'type': 'float64'
    },
    1179673: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the noise figure (NF) measurement should account for ohmic losses inherent to the noise source used in the Y-Factor method common to the calibration and measurement steps.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_NF_Y_FACTOR_NOISE_SOURCE_LOSS_COMPENSATION_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_NFGetYFactorNoiseSourceLossCompensationEnabled\n Set Function: RFmxSpecAn_NFSetYFactorNoiseSourceLossCompensationEnabled\n'
        },
        'enum': 'NFYFactorNoiseSourceLossCompensationEnabled',
        'name': 'NF_Y_FACTOR_NOISE_SOURCE_LOSS_COMPENSATION_ENABLED',
        'type': 'int32'
    },
    1179674: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies an array of the ohmic losses inherent to the noise source used in the Y-Factor method. This value is expressed in dB. This loss is accounted for by the NF measurement when you set the RFMXSPECAN_ATTR_NF_Y_FACTOR_NOISE_SOURCE_LOSS_COMPENSATION_ENABLED attribute to RFMXSPECAN_VAL_NF_Y_FACTOR_NOISE_SOURCE_LOSS_COMPENSATION_ENABLED_TRUE.\n \nYou must specify the frequencies at which the losses were measured using the RFMXSPECAN_ATTR_NF_Y_FACTOR_NOISE_SOURCE_LOSS_FREQUENCY attribute.         \n\nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is an empty array.\n \nGet Function: RFmxSpecAn_NFGetYFactorNoiseSourceLoss\n Set Function: RFmxSpecAn_NFSetYFactorNoiseSourceLoss\n'
        },
        'name': 'NF_Y_FACTOR_NOISE_SOURCE_LOSS',
        'type': 'float64[]'
    },
    1179675: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the frequencies corresponding to the ohmic loss inherent to the noise source used in the Y-Factor method specified by the RFMXSPECAN_ATTR_NF_Y_FACTOR_NOISE_SOURCE_LOSS attribute. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is an empty array.\n \nGet Function: RFmxSpecAn_NFGetYFactorNoiseSourceLossFrequency\n Set Function: RFmxSpecAn_NFSetYFactorNoiseSourceLossFrequency\n'
        },
        'name': 'NF_Y_FACTOR_NOISE_SOURCE_LOSS_FREQUENCY',
        'type': 'float64[]'
    },
    1179676: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the physical temperature of the ohmic loss elements specified in the RFMXSPECAN_ATTR_NF_Y_FACTOR_NOISE_SOURCE_LOSS attribute. This value is expressed in kelvin.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 297.\n \nGet Function: RFmxSpecAn_NFGetYFactorNoiseSourceLossTemperature\n Set Function: RFmxSpecAn_NFSetYFactorNoiseSourceLossTemperature\n'
        },
        'name': 'NF_Y_FACTOR_NOISE_SOURCE_LOSS_TEMPERATURE',
        'type': 'float64'
    },
    1179677: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the noise figure (NF) measurement accounts for the ohmic losses between the noise source and input port of the analyzer during the calibration step, excluding any losses which you have specified using the RFMXSPECAN_ATTR_NF_Y_FACTOR_NOISE_SOURCE_LOSS attribute.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_NF_CALIBRATION_LOSS_COMPENSATION_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_NFGetCalibrationLossCompensationEnabled\n Set Function: RFmxSpecAn_NFSetCalibrationLossCompensationEnabled\n'
        },
        'enum': 'NFCalibrationLossCompensationEnabled',
        'name': 'NF_CALIBRATION_LOSS_COMPENSATION_ENABLED',
        'type': 'int32'
    },
    1179678: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the array of ohmic losses between the noise source and input port of the analyzer during calibration, as a function of frequency. This value is expressed in dB. This loss is accounted for by the noise figure (NF) measurement when you set the RFMXSPECAN_ATTR_NF_CALIBRATION_LOSS_COMPENSATION_ENABLED attribute to RFMXSPECAN_VAL_NF_CALIBRATION_LOSS_COMPENSATION_ENABLED_TRUE. You must exclude any loss specified by the RFMXSPECAN_ATTR_NF_Y_FACTOR_NOISE_SOURCE_LOSS attribute.        \n\nThis attribute specifies the frequencies at which the RFMXSPECAN_ATTR_NF_CALIBRATION_LOSS_FREQUENCY attribute measures the losses.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is an empty array.\n \nGet Function: RFmxSpecAn_NFGetCalibrationLoss\n Set Function: RFmxSpecAn_NFSetCalibrationLoss\n'
        },
        'name': 'NF_CALIBRATION_LOSS',
        'type': 'float64[]'
    },
    1179679: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies an array of frequencies corresponding to the ohmic losses between the source and the input port of the analyzer. This value is expressed in Hz. This attribute is applicable only when you set the RFMXSPECAN_ATTR_NF_Y_FACTOR_MODE attribute to RFMXSPECAN_VAL_NF_Y_FACTOR_MODE_CALIBRATE and set the RFMXSPECAN_ATTR_NF_MEASUREMENT_METHOD attribute to RFMXSPECAN_VAL_NF_MEASUREMENT_METHOD_Y_FACTOR, or when you set the RFMXSPECAN_ATTR_NF_COLD_SOURCE_MODE attribute to RFMXSPECAN_VAL_NF_Y_FACTOR_MODE_CALIBRATE and set the RFMXSPECAN_ATTR_NF_MEASUREMENT_METHOD attribute to RFMXSPECAN_VAL_NF_MEASUREMENT_METHOD_COLD_SOURCE.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is an empty array.\n \nGet Function: RFmxSpecAn_NFGetCalibrationLossFrequency\n Set Function: RFmxSpecAn_NFSetCalibrationLossFrequency\n'
        },
        'name': 'NF_CALIBRATION_LOSS_FREQUENCY',
        'type': 'float64[]'
    },
    1179680: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the physical temperature of the ohmic loss elements specified by the RFMXSPECAN_ATTR_NF_CALIBRATION_LOSS attribute. This value is expressed in kelvin.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 297.\n \nGet Function: RFmxSpecAn_NFGetCalibrationLossTemperature\n Set Function: RFmxSpecAn_NFSetCalibrationLossTemperature\n'
        },
        'name': 'NF_CALIBRATION_LOSS_TEMPERATURE',
        'type': 'float64'
    },
    1179681: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum number of threads used for parallelism for the noise figure (NF) measurement.\n \nThe number of threads can range from 1 to the number of physical cores. The number of threads you set may not be used in calculations. The actual number of threads used depends on the problem size, system resources, data availability, and other considerations.\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_NFGetNumberOfAnalysisThreads\n Set Function: RFmxSpecAn_NFSetNumberOfAnalysisThreads\n'
        },
        'name': 'NF_NUMBER_OF_ANALYSIS_THREADS',
        'type': 'int32'
    },
    1179682: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns an array of the noise figures of the DUT measured at the frequencies specified by the RFMXSPECAN_ATTR_NF_FREQUENCY_LIST attribute. This value is expressed in dB.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_NFGetResultsDUTNoiseFigure\n'
        },
        'name': 'NF_RESULTS_DUT_NOISE_FIGURE',
        'type': 'float64[]'
    },
    1179683: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns an array of the equivalent thermal noise temperatures of the DUT measured at the frequencies specified by the RFMXSPECAN_ATTR_NF_FREQUENCY_LIST attribute. This value is expressed in kelvin.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_NFGetResultsDUTNoiseTemperature\n'
        },
        'name': 'NF_RESULTS_DUT_NOISE_TEMPERATURE',
        'type': 'float64[]'
    },
    1179684: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns an array of the available gains of the DUT measured at the frequencies specified by the RFMXSPECAN_ATTR_NF_FREQUENCY_LIST attribute. This value is expressed in dB.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_NFGetResultsDUTGain\n'
        },
        'name': 'NF_RESULTS_DUT_GAIN',
        'type': 'float64[]'
    },
    1179685: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns an array of the noise figures of the analyzer measured at the frequencies specified by the RFMXSPECAN_ATTR_NF_FREQUENCY_LIST attribute. This value is expressed in dB.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_NFGetResultsAnalyzerNoiseFigure\n'
        },
        'name': 'NF_RESULTS_ANALYZER_NOISE_FIGURE',
        'type': 'float64[]'
    },
    1179686: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns an array of the measurement Y-Factors measured at the frequencies specified by the RFMXSPECAN_ATTR_NF_FREQUENCY_LIST attribute. This value is expressed in dB. A valid result is returned only when you set the RFMXSPECAN_ATTR_NF_MEASUREMENT_METHOD attribute to RFMXSPECAN_VAL_NF_MEASUREMENT_METHOD_Y_FACTOR.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_NFGetResultsMeasurementYFactor\n'
        },
        'name': 'NF_RESULTS_MEASUREMENT_Y_FACTOR',
        'type': 'float64[]'
    },
    1179687: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns an array of the calibration Y-Factors measured at the frequencies specified by the RFMXSPECAN_ATTR_NF_FREQUENCY_LIST attribute. This value is expressed in dB. A valid result is returned only when you set the RFMXSPECAN_ATTR_NF_MEASUREMENT_METHOD attribute to RFMXSPECAN_VAL_NF_MEASUREMENT_METHOD_Y_FACTOR.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_NFGetResultsCalibrationYFactor\n'
        },
        'name': 'NF_RESULTS_CALIBRATION_Y_FACTOR',
        'type': 'float64[]'
    },
    1179688: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the array of powers measured at the frequencies specified by the RFMXSPECAN_ATTR_NF_FREQUENCY_LIST attribute, when the noise source is enabled. This value is expressed in dBm. A valid result is returned only when you set the RFMXSPECAN_ATTR_NF_MEASUREMENT_METHOD attribute to RFMXSPECAN_VAL_NF_MEASUREMENT_METHOD_Y_FACTOR.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_NFGetResultsYFactorHotPower\n'
        },
        'name': 'NF_RESULTS_Y_FACTOR_HOT_POWER',
        'type': 'float64[]'
    },
    1179689: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the array of powers measured at the frequencies specified by the RFMXSPECAN_ATTR_NF_FREQUENCY_LIST attribute, when the noise source is disabled. This value is expressed in dBm. A valid result is returned only when you set the RFMXSPECAN_ATTR_NF_MEASUREMENT_METHOD attribute to RFMXSPECAN_VAL_NF_MEASUREMENT_METHOD_Y_FACTOR.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_NFGetResultsYFactorColdPower\n'
        },
        'name': 'NF_RESULTS_Y_FACTOR_COLD_POWER',
        'type': 'float64[]'
    },
    1179690: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the power measured at the frequencies specified by the RFMXSPECAN_ATTR_NF_FREQUENCY_LIST attribute. This value is expressed in dBm. A valid result is returned only when you set the RFMXSPECAN_ATTR_NF_MEASUREMENT_METHOD attribute to Cold-source.\n \nYou do not need to use a selector string to read this result for default signal and result instance. Refer to the Selector Strings topic for information about the string syntax for named signals and results.\n \nGet Function: RFmxSpecAn_NFGetResultsColdSourcePower\n'
        },
        'name': 'NF_RESULTS_COLD_SOURCE_POWER',
        'type': 'float64[]'
    },
    1179691: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the measurement should calibrate the noise characteristics of the analyzer or compute the noise characteristics of the DUT for the cold source method.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_NF_COLD_SOURCE_MODE_MEASURE.\n \nGet Function: RFmxSpecAn_NFGetColdSourceMode\n Set Function: RFmxSpecAn_NFSetColdSourceMode\n'
        },
        'enum': 'NFColdSourceMode',
        'name': 'NF_COLD_SOURCE_MODE',
        'type': 'int32'
    },
    1179692: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies an array of voltage standing wave ratios (VSWR) as a function of frequency of the microwave termination used as the noise source in cold source method. The corresponding array of frequencies is specified by the RFMXSPECAN_ATTR_NF_COLD_SOURCE_INPUT_TERMINATION_VSWR_FREQUENCY attribute.\n \nIn most cases, the exact VSWR of the microwave termination may not be known. Hence, NI recommends that you set this attribute to an empty array, in which case the noise figure (NF) measurement assumes that the VSWR of the microwave termination is unity for all frequencies.          \n\nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is an empty array.\n \nGet Function: RFmxSpecAn_NFGetColdSourceInputTerminationVSWR\n Set Function: RFmxSpecAn_NFSetColdSourceInputTerminationVSWR\n'
        },
        'name': 'NF_COLD_SOURCE_INPUT_TERMINATION_VSWR',
        'type': 'float64[]'
    },
    1179693: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies an array of  frequencies corresponding to the voltage standing wave ratios (VSWR) of the microwave termination used in the cold source method as specified by the RFMXSPECAN_ATTR_NF_COLD_SOURCE_INPUT_TERMINATION_VSWR attribute. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is an empty array.\n \nGet Function: RFmxSpecAn_NFGetColdSourceInputTerminationVSWRFrequency\n Set Function: RFmxSpecAn_NFSetColdSourceInputTerminationVSWRFrequency\n'
        },
        'name': 'NF_COLD_SOURCE_INPUT_TERMINATION_VSWR_FREQUENCY',
        'type': 'float64[]'
    },
    1179694: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the physical temperature of the microwave termination used as the noise source in the cold source method. This value is expressed in kelvin.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 297.\n \nGet Function: RFmxSpecAn_NFGetColdSourceInputTerminationTemperature\n Set Function: RFmxSpecAn_NFSetColdSourceInputTerminationTemperature\n'
        },
        'name': 'NF_COLD_SOURCE_INPUT_TERMINATION_TEMPERATURE',
        'type': 'float64'
    },
    1179695: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies an array of the gains of the DUT as a function of frequency, when the output port of the DUT is terminated with an impedance equal to the characteristic impedance. This value is expressed in dB. The corresponding array of frequencies is specified by the RFMXSPECAN_ATTR_NF_COLD_SOURCE_DUT_S_PARAMETERS_FREQUENCY attribute.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is an empty array.\n \nGet Function: RFmxSpecAn_NFGetColdSourceDUTS21\n Set Function: RFmxSpecAn_NFSetColdSourceDUTS21\n'
        },
        'name': 'NF_COLD_SOURCE_DUT_S21',
        'type': 'float64[]'
    },
    1179696: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies an array of the input-isolations of the DUT as a function of frequency, when the input port of the DUT is terminated with an impedance equal to the characteristic impedance. This value is expressed in dB. The corresponding array of frequencies is specified by the RFMXSPECAN_ATTR_NF_COLD_SOURCE_DUT_S_PARAMETERS_FREQUENCY attribute.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is an empty array.\n \nGet Function: RFmxSpecAn_NFGetColdSourceDUTS12\n Set Function: RFmxSpecAn_NFSetColdSourceDUTS12\n'
        },
        'name': 'NF_COLD_SOURCE_DUT_S12',
        'type': 'float64[]'
    },
    1179697: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies an array of the input-reflections of the DUT as a function of frequency, when the output port of the DUT is terminated with an impedance equal to the characteristic impedance. This value is expressed in dB.\n \nThe corresponding array of frequencies is specified by the RFMXSPECAN_ATTR_NF_COLD_SOURCE_DUT_S_PARAMETERS_FREQUENCY attribute.         \n\nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is an empty array.\n \nGet Function: RFmxSpecAn_NFGetColdSourceDUTS11\n Set Function: RFmxSpecAn_NFSetColdSourceDUTS11\n'
        },
        'name': 'NF_COLD_SOURCE_DUT_S11',
        'type': 'float64[]'
    },
    1179698: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies an array of the output-reflections of the DUT as a function of frequency, when the input port of the DUT is terminated with an impedance equal to the characteristic impedance. This value is expressed in dB. The corresponding array of frequencies is specified by the RFMXSPECAN_ATTR_NF_COLD_SOURCE_DUT_S_PARAMETERS_FREQUENCY attribute.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is an empty array.\n \nGet Function: RFmxSpecAn_NFGetColdSourceDUTS22\n Set Function: RFmxSpecAn_NFSetColdSourceDUTS22\n'
        },
        'name': 'NF_COLD_SOURCE_DUT_S22',
        'type': 'float64[]'
    },
    1179699: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies an array of frequencies corresponding to the s-parameters of the DUT specified by the RFMXSPECAN_ATTR_NF_COLD_SOURCE_DUT_S21, RFMXSPECAN_ATTR_NF_COLD_SOURCE_DUT_S12, RFMXSPECAN_ATTR_NF_COLD_SOURCE_DUT_S11, and RFMXSPECAN_ATTR_NF_COLD_SOURCE_DUT_S22 attributes. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is an empty array.\n \nGet Function: RFmxSpecAn_NFGetColdSourceDUTSParametersFrequency\n Set Function: RFmxSpecAn_NFSetColdSourceDUTSParametersFrequency\n'
        },
        'name': 'NF_COLD_SOURCE_DUT_S_PARAMETERS_FREQUENCY',
        'type': 'float64[]'
    },
    1179700: {
        'access': 'read-write',
        'documentation': {
            'description': ' Associates a unique string identifier with the hardware setup used to perform calibration for the NF measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is an empty string.\n \nGet Function: RFmxSpecAn_NFGetCalibrationSetupId\n Set Function: RFmxSpecAn_NFSetCalibrationSetupId\n'
        },
        'name': 'NF_CALIBRATION_SETUP_ID',
        'type': 'char[]'
    },
    1179701: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies if an external preamplifier is present in the signal path.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_NF_EXTERNAL_PREAMP_PRESENT_FALSE.\n \nGet Function: RFmxSpecAn_NFGetExternalPreampPresent\n Set Function: RFmxSpecAn_NFSetExternalPreampPresent\n'
        },
        'enum': 'NFExternalPreampPresent',
        'name': 'NF_EXTERNAL_PREAMP_PRESENT',
        'type': 'int32'
    },
    1179702: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the array of frequencies corresponding to the value of the RFMXSPECAN_ATTR_NF_EXTERNAL_PREAMP_GAIN attribute.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nGet Function: RFmxSpecAn_NFGetExternalPreampFrequency\n Set Function: RFmxSpecAn_NFSetExternalPreampFrequency\n'
        },
        'name': 'NF_EXTERNAL_PREAMP_FREQUENCY',
        'type': 'float64[]'
    },
    1179703: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the gain of the external preamp as a function of frequency. The value is expressed in dB.\n \nSpecify the frequencies at which gain values were measured using the RFMXSPECAN_ATTR_NF_EXTERNAL_PREAMP_FREQUENCY attribute.\n \nGet Function: RFmxSpecAn_NFGetExternalPreampGain\n Set Function: RFmxSpecAn_NFSetExternalPreampGain\n'
        },
        'name': 'NF_EXTERNAL_PREAMP_GAIN',
        'type': 'float64[]'
    },
    1179705: {
        'access': 'read-write',
        'name': 'NF_DEVICE_TEMPERATURE_TOLERANCE',
        'type': 'float64'
    },
    1179706: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the type of DUT.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_NF_DUT_TYPE_AMPLIFIER.\n \nGet Function: RFmxSpecAn_NFGetDUTType\n Set Function: RFmxSpecAn_NFSetDUTType\n'
        },
        'enum': 'NFDutType',
        'name': 'NF_DUT_TYPE',
        'type': 'int32'
    },
    1179708: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the fixed LO frequency of the DUT when you set the RFMXSPECAN_ATTR_NF_DUT_TYPE attribute to either RFMXSPECAN_VAL_NF_DUT_TYPE_DOWNCONVERTER or RFMXSPECAN_VAL_NF_DUT_TYPE_UPCONVERTER. This value is expressed in Hz.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10 MHz.\n \nGet Function: RFmxSpecAn_NFGetFrequencyConverterLOFrequency\n Set Function: RFmxSpecAn_NFSetFrequencyConverterLOFrequency\n'
        },
        'name': 'NF_FREQUENCY_CONVERTER_LO_FREQUENCY',
        'type': 'float64'
    },
    1179710: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the context of the NF Frequency List attribute.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_NF_FREQUENCY_CONVERTER_FREQUENCY_CONTEXT_RF.\n \nGet Function: RFmxSpecAn_NFGetFrequencyConverterFrequencyContext\n Set Function: RFmxSpecAn_NFSetFrequencyConverterFrequencyContext\n'
        },
        'enum': 'NFFrequencyConverterFrequencyContext',
        'name': 'NF_FREQUENCY_CONVERTER_FREQUENCY_CONTEXT',
        'type': 'int32'
    },
    1179711: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the sideband when you set the RFMXSPECAN_ATTR_NF_DUT_TYPE attribute to either RFMXSPECAN_VAL_NF_DUT_TYPE_DOWNCONVERTER or RFMXSPECAN_VAL_NF_DUT_TYPE_UPCONVERTER, and the RFMXSPECAN_ATTR_NF_FREQUENCY_CONVERTER_FREQUENCY_CONTEXT attribute to RFMXSPECAN_VAL_NF_FREQUENCY_CONVERTER_FREQUENCY_CONTEXT_IF.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_NF_FREQUENCY_CONVERTER_SIDEBAND_LSB.\n \nGet Function: RFmxSpecAn_NFGetFrequencyConverterSideband\n Set Function: RFmxSpecAn_NFSetFrequencyConverterSideband\n'
        },
        'enum': 'NFFrequencyConverterSideband',
        'name': 'NF_FREQUENCY_CONVERTER_SIDEBAND',
        'type': 'int32'
    },
    1179712: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the gain ratio of the DUT at the image frequency to that at the RF frequency. This value is expressed in dB. Refer to NF concept help for more details.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 999.99 dB.\n \nGet Function: RFmxSpecAn_NFGetFrequencyConverterImageRejection\n Set Function: RFmxSpecAn_NFSetFrequencyConverterImageRejection\n'
        },
        'name': 'NF_FREQUENCY_CONVERTER_IMAGE_REJECTION',
        'type': 'float64'
    },
    1245184: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the phase noise measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance.  Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetMeasurementEnabled\n Set Function: RFmxSpecAn_PhaseNoiseSetMeasurementEnabled\n'
        },
        'name': 'PHASENOISE_MEASUREMENT_ENABLED',
        'type': 'int32'
    },
    1245186: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies how the measurement computes offset subranges.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_PHASENOISE_RANGE_DEFINITION_AUTO.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetRangeDefinition\n Set Function: RFmxSpecAn_PhaseNoiseSetRangeDefinition\n'
        },
        'enum': 'PhaseNoiseRangeDefinition',
        'name': 'PHASENOISE_RANGE_DEFINITION',
        'type': 'int32'
    },
    1245187: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the start frequency of the offset frequency range when you set the RFMXSPECAN_ATTR_PHASENOISE_RANGE_DEFINITION attribute to RFMXSPECAN_VAL_PHASENOISE_RANGE_DEFINITION_AUTO.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1000.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetStartFrequency\n Set Function: RFmxSpecAn_PhaseNoiseSetStartFrequency\n'
        },
        'name': 'PHASENOISE_START_FREQUENCY',
        'type': 'float64'
    },
    1245188: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the stop frequency of the offset frequency range when you set the RFMXSPECAN_ATTR_PHASENOISE_RANGE_DEFINITION attribute to RFMXSPECAN_VAL_PHASENOISE_RANGE_DEFINITION_AUTO.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1E+06.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetStopFrequency\n Set Function: RFmxSpecAn_PhaseNoiseSetStopFrequency\n'
        },
        'name': 'PHASENOISE_STOP_FREQUENCY',
        'type': 'float64'
    },
    1245189: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the RBW as a percentage of the start frequency of each subrange when you set the RFMXSPECAN_ATTR_PHASENOISE_RANGE_DEFINITION attribute to RFMXSPECAN_VAL_PHASENOISE_RANGE_DEFINITION_AUTO.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 10.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetRBWPercentage\n Set Function: RFmxSpecAn_PhaseNoiseSetRBWPercentage\n'
        },
        'name': 'PHASENOISE_RBW_PERCENTAGE',
        'type': 'float64'
    },
    1245190: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the factor by which you increase the averaging count for each range. This setting applies to both Auto and Manual range definitions.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetAveragingMultiplier\n Set Function: RFmxSpecAn_PhaseNoiseSetAveragingMultiplier\n'
        },
        'name': 'PHASENOISE_AVERAGING_MULTIPLIER',
        'type': 'int32'
    },
    1245191: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the FFT window to use.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_PHASENOISE_FFT_WINDOW_HAMMING.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetFFTWindow\n Set Function: RFmxSpecAn_PhaseNoiseSetFFTWindow\n'
        },
        'enum': 'PhaseNoiseFftWindow',
        'name': 'PHASENOISE_FFT_WINDOW',
        'type': 'int32'
    },
    1245192: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of manual ranges.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 1.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetNumberOfRanges\n Set Function: RFmxSpecAn_PhaseNoiseSetNumberOfRanges\n'
        },
        'name': 'PHASENOISE_NUMBER_OF_RANGES',
        'type': 'int32'
    },
    1245193: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the start frequency for the specified subrange when you set the RFMXSPECAN_ATTR_PHASENOISE_RANGE_DEFINITION attribute to RFMXSPECAN_VAL_PHASENOISE_RANGE_DEFINITION_MANUAL.\n \nUse 'range(n)' as the selector string to configure or read this attribute.\n \nThe default value is 1000.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetRangeStartFrequency\n Set Function: RFmxSpecAn_PhaseNoiseSetRangeStartFrequency\n"
        },
        'name': 'PHASENOISE_RANGE_START_FREQUENCY',
        'type': 'float64'
    },
    1245194: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the stop frequency for the specified subrange when you set the RFMXSPECAN_ATTR_PHASENOISE_RANGE_DEFINITION attribute to RFMXSPECAN_VAL_PHASENOISE_RANGE_DEFINITION_MANUAL.\n \nUse 'range(n)' as the selector string to configure or read this attribute.\n \nThe default value is 1E+06.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetRangeStopFrequency\n Set Function: RFmxSpecAn_PhaseNoiseSetRangeStopFrequency\n"
        },
        'name': 'PHASENOISE_RANGE_STOP_FREQUENCY',
        'type': 'float64'
    },
    1245195: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the RBW as a percentage of the RFMXSPECAN_ATTR_PHASENOISE_RANGE_START_FREQUENCY attribute of the specified subrange when you set the RFMXSPECAN_ATTR_PHASENOISE_RANGE_DEFINITION attribute to RFMXSPECAN_VAL_PHASENOISE_RANGE_DEFINITION_MANUAL.\n \nUse 'range(n)' as the selector string to configure or read this attribute.\n \nThe default value is 10.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetRangeRBWPercentage\n Set Function: RFmxSpecAn_PhaseNoiseSetRangeRBWPercentage\n"
        },
        'name': 'PHASENOISE_RANGE_RBW_PERCENTAGE',
        'type': 'float64'
    },
    1245196: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the averaging count for the specified subrange when you set the RFMXSPECAN_ATTR_PHASENOISE_RANGE_DEFINITION attribute to RFMXSPECAN_VAL_PHASENOISE_RANGE_DEFINITION_MANUAL.\n \nUse 'range(n)' as the selector string to configure or read this attribute.\n \nThe default value is 10.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetRangeAveragingCount\n Set Function: RFmxSpecAn_PhaseNoiseSetRangeAveragingCount\n"
        },
        'name': 'PHASENOISE_RANGE_AVERAGING_COUNT',
        'type': 'int32'
    },
    1245197: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the smoothing type used to smoothen the measured log plot trace.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_PHASENOISE_SMOOTHING_TYPE_LOGARITHMIC.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetSmoothingType\n Set Function: RFmxSpecAn_PhaseNoiseSetSmoothingType\n'
        },
        'enum': 'PhaseNoiseSmoothingType',
        'name': 'PHASENOISE_SMOOTHING_TYPE',
        'type': 'int32'
    },
    1245198: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of trace points to use in the moving average filter as a percentage of total number of points in the log plot trace.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 2.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetSmoothingPercentage\n Set Function: RFmxSpecAn_PhaseNoiseSetSmoothingPercentage\n'
        },
        'name': 'PHASENOISE_SMOOTHING_PERCENTAGE',
        'type': 'float64'
    },
    1245199: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies an array of offset frequencies at which the phase noise is measured using the smoothed log plot trace.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetSpotNoiseFrequencyList\n Set Function: RFmxSpecAn_PhaseNoiseSetSpotNoiseFrequencyList\n'
        },
        'name': 'PHASENOISE_SPOT_NOISE_FREQUENCY_LIST',
        'type': 'float64[]'
    },
    1245200: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the frequency range for integrated noise measurements.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_PHASENOISE_INTEGRATED_NOISE_RANGE_DEFINITION_MEASUREMENT.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetIntegratedNoiseRangeDefinition\n Set Function: RFmxSpecAn_PhaseNoiseSetIntegratedNoiseRangeDefinition\n'
        },
        'enum': 'PhaseNoiseIntegratedNoiseRangeDefinition',
        'name': 'PHASENOISE_INTEGRATED_NOISE_RANGE_DEFINITION',
        'type': 'int32'
    },
    1245201: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies an array of the start frequencies for integrated noise measurement when you set the RFMXSPECAN_ATTR_PHASENOISE_INTEGRATED_NOISE_RANGE_DEFINITION attribute to RFMXSPECAN_VAL_PHASENOISE_INTEGRATED_NOISE_RANGE_DEFINITION_CUSTOM.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetIntegratedNoiseStartFrequency\n Set Function: RFmxSpecAn_PhaseNoiseSetIntegratedNoiseStartFrequency\n'
        },
        'name': 'PHASENOISE_INTEGRATED_NOISE_START_FREQUENCY',
        'type': 'float64[]'
    },
    1245202: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies an array of the stop frequencies for integrated noise measurement when you set the RFMXSPECAN_ATTR_PHASENOISE_INTEGRATED_NOISE_RANGE_DEFINITION attribute to RFMXSPECAN_VAL_PHASENOISE_INTEGRATED_NOISE_RANGE_DEFINITION_CUSTOM.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetIntegratedNoiseStopFrequency\n Set Function: RFmxSpecAn_PhaseNoiseSetIntegratedNoiseStopFrequency\n'
        },
        'name': 'PHASENOISE_INTEGRATED_NOISE_STOP_FREQUENCY',
        'type': 'float64[]'
    },
    1245203: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the traces to be stored and retrieved after performing the Phase Noise measurement.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_FALSE.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetAllTracesEnabled\n Set Function: RFmxSpecAn_PhaseNoiseSetAllTracesEnabled\n'
        },
        'name': 'PHASENOISE_ALL_TRACES_ENABLED',
        'type': 'int32'
    },
    1245205: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the measured carrier power.\n \nYou do not need to use a selector string to read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetResultsCarrierPower\n'
        },
        'name': 'PHASENOISE_RESULTS_CARRIER_POWER',
        'type': 'float64'
    },
    1245206: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the measured carrier frequency.\n \nYou do not need to use a selector string to read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetResultsCarrierFrequency\n'
        },
        'name': 'PHASENOISE_RESULTS_CARRIER_FREQUENCY',
        'type': 'float64'
    },
    1245207: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the phase noise corresponding to the PhaseNoise Spot Noise Frequency List attribute  by using the smoothed log plot trace.\n \nYou do not need to use a selector string to read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetResultsSpotPhaseNoise\n'
        },
        'name': 'PHASENOISE_RESULTS_SPOT_PHASE_NOISE',
        'type': 'float64[]'
    },
    1245208: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the integrated phase noise.\n \nYou do not need to use a selector string to read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetResultsIntegratedPhaseNoise\n'
        },
        'name': 'PHASENOISE_RESULTS_INTEGRATED_PHASE_NOISE',
        'type': 'float64[]'
    },
    1245209: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the residual PM in radians.\n \nYou do not need to use a selector string to read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetResultsResidualPMInRadian\n'
        },
        'name': 'PHASENOISE_RESULTS_INTEGRATED_NOISE_RESIDUAL_PM_IN_RADIAN',
        'type': 'float64[]'
    },
    1245210: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the residual PM in degrees.\n \nYou do not need to use a selector string to read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetResultsResidualPMInDegree\n'
        },
        'name': 'PHASENOISE_RESULTS_INTEGRATED_NOISE_RESIDUAL_PM_IN_DEGREE',
        'type': 'float64[]'
    },
    1245211: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the residual FM in Hz.\n \nYou do not need to use a selector string to read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetResultsResidualFM\n'
        },
        'name': 'PHASENOISE_RESULTS_INTEGRATED_NOISE_RESIDUAL_FM',
        'type': 'float64[]'
    },
    1245212: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the jitter in seconds.\n \nYou do not need to use a selector string to read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetResultsJitter\n'
        },
        'name': 'PHASENOISE_RESULTS_INTEGRATED_NOISE_JITTER',
        'type': 'float64[]'
    },
    1245213: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to remove spurs from the log plot trace.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_PHASENOISE_SPUR_REMOVAL_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetSpurRemovalEnabled\n Set Function: RFmxSpecAn_PhaseNoiseSetSpurRemovalEnabled\n'
        },
        'enum': 'PhaseNoiseSpurRemovalEnabled',
        'name': 'PHASENOISE_SPUR_REMOVAL_ENABLED',
        'type': 'int32'
    },
    1245214: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the peak excursion to be used when spur detection is performed.      \n\nRefer to the Phase Noise topic for more information on spur removal.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 6.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetSpurRemovalPeakExcursion\n Set Function: RFmxSpecAn_PhaseNoiseSetSpurRemovalPeakExcursion\n'
        },
        'name': 'PHASENOISE_SPUR_REMOVAL_PEAK_EXCURSION',
        'type': 'float64'
    },
    1245215: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable or disable the phase noise cancellation.      \n\nRefer to the Phase Noise topic for more information on phase noise cancellation.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is RFMXSPECAN_VAL_PHASENOISE_CANCELLATION_ENABLED_FALSE.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetCancellationEnabled\n Set Function: RFmxSpecAn_PhaseNoiseSetCancellationEnabled\n'
        },
        'enum': 'PhaseNoiseCancellationEnabled',
        'name': 'PHASENOISE_CANCELLATION_ENABLED',
        'type': 'int32'
    },
    1245216: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the minimum difference between the reference and pre-cancellation traces that must exist before cancellation is performed.\n \nYou do not need to use a selector string to configure or read this attribute for the default signal instance. Refer to the Selector Strings topic for information about the string syntax for named signals.\n \nThe default value is 0.01.\n \nGet Function: RFmxSpecAn_PhaseNoiseGetCancellationThreshold\n Set Function: RFmxSpecAn_PhaseNoiseSetCancellationThreshold\n'
        },
        'name': 'PHASENOISE_CANCELLATION_THRESHOLD',
        'type': 'float64'
    },
    1245217: {
        'access': 'read-write',
        'name': 'PHASENOISE_CANCELLATION_FREQUENCY',
        'type': 'float32[]'
    },
    1245218: {
        'access': 'read-write',
        'name': 'PHASENOISE_CANCELLATION_REFERENCE_PHASE_NOISE',
        'type': 'float32[]'
    }
}
