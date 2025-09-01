attributes = {
    1050002: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to validate attribute values and function  parameters. Range checking parameters is very useful for debugging.  After you validate your program, set this attribute to VI_FALSE to disable  range checking and maximize performance. NI-RFSG can choose to ignore range  checking for particular attributes, regardless of the setting of this attribute.  Use the niRFSG_InitWithOptions function to override the default value. \n \n'
        },
        'name': 'RANGE_CHECK',
        'type': 'ViBoolean'
    },
    1050003: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether NI-RFSG queries the NI-RFSG device status  after each operation. Querying the device status is useful  for debugging. After you validate your program, set this attribute  to VI_FALSE to disable status checking and maximize performance.  NI-RFSG can choose to ignore status checking for particular attributes,  regardless of the setting of this attribute. Use the niRFSG_InitWithOptions  function to override the default value. \n \n'
        },
        'name': 'QUERY_INSTRUMENT_STATUS',
        'type': 'ViBoolean'
    },
    1050004: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to cache the value of attributes. When caching is  enabled, NI-RFSG tracks the current NI-RFSG device settings and avoids  sending redundant commands to the device. \n \n NI-RFSG can always cache or never cache particular attributes, regardless  of the setting of this attribute.\n \n'
        },
        'name': 'CACHE',
        'type': 'ViBoolean'
    },
    1050005: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns whether NI-RFSG simulates I/O operations. This attribute  is useful for debugging applications without using hardware.  After a session is opened, you cannot change the simulation state.  Use the niRFSG_InitWithOptions function to enable simulation.\n \n'
        },
        'name': 'SIMULATE',
        'type': 'ViBoolean'
    },
    1050006: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the IVI engine keeps a list of the value coercions it  makes for integer and real type attributes.\n \n This attribute is currently not supported.\n'
        },
        'name': 'RECORD_COERCIONS',
        'type': 'ViBoolean'
    },
    1050007: {
        'access': 'read-write',
        'name': 'DRIVER_SETUP',
        'type': 'ViString'
    },
    1050021: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to perform interchangeability checking and retrieve  interchangeability warnings.\n \n',
            'note': ' This attribute is currently not supported. \n'
        },
        'name': 'INTERCHANGE_CHECK',
        'type': 'ViBoolean'
    },
    1050022: {
        'access': 'read-write',
        'name': 'SPY',
        'type': 'ViBoolean'
    },
    1050023: {
        'access': 'read-write',
        'name': 'USE_SPECIFIC_SIMULATION',
        'type': 'ViBoolean'
    },
    1050203: {
        'access': 'read-write',
        'name': 'CHANNEL_COUNT',
        'type': 'ViInt32'
    },
    1050302: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns a string that contains the prefix for NI-RFSG. The name of each  user-callable function in NI-RFSG starts with this prefix.  This attribute returns niRFSG.\n     '
        },
        'name': 'SPECIFIC_DRIVER_PREFIX',
        'type': 'ViString'
    },
    1050304: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns a string that contains the resource name NI-RFSG uses to identify the physical device.  If you initialize NI-RFSG with a logical name, this attribute contains the  resource name that corresponds to the entry in the IVI Configuration  Utility. If you initialize NI-RFSG with the resource name, this attribute  contains that value. \n     '
        },
        'name': 'IO_RESOURCE_DESCRIPTOR',
        'type': 'ViString'
    },
    1050305: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns a string that contains the logical name you specified when opening the current IVI session.  You can pass a logical name to the niRFSG_init  function or the niRFSG_InitWithOptions function. The IVI Configuration  Utility must contain an entry for the logical name. The logical name entry  refers to a driver session section in the IVI Configuration file. The  driver session section specifies a physical device and initial user  options.\n     '
        },
        'name': 'LOGICAL_NAME',
        'type': 'ViString'
    },
    1050327: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns a string that contains a model code of the NI-RFSG device.  For drivers that support more than one device,  this attribute contains a comma-separated list of supported devices. \n     '
        },
        'name': 'SUPPORTED_INSTRUMENT_MODELS',
        'type': 'ViString'
    },
    1050401: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns a string that contains a comma-separated list of class-extension  groups that NI-RFSG implements.\n     '
        },
        'name': 'GROUP_CAPABILITIES',
        'type': 'ViString'
    },
    1050402: {
        'access': 'read-write',
        'name': 'FUNCTION_CAPABILITIES',
        'type': 'ViString'
    },
    1050510: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns a string that contains the firmware revision information for the  NI-RFSG device you are currently using.\n     '
        },
        'name': 'INSTRUMENT_FIRMWARE_REVISION',
        'type': 'ViString'
    },
    1050511: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns a string that contains the name of the manufacturer for the  NI-RFSG device you are currently using.\n     '
        },
        'name': 'INSTRUMENT_MANUFACTURER',
        'type': 'ViString'
    },
    1050512: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns a string that contains the model number or name of the NI-RFSG  device that you are currently using. For drivers that support more than  one device, this attribute returns a comma-separated list of  supported devices.\n'
        },
        'name': 'INSTRUMENT_MODEL',
        'type': 'ViString'
    },
    1050513: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns a string that contains the name of the vendor that supplies  NI-RFSG. This attribute returns National Instruments.\n     '
        },
        'name': 'SPECIFIC_DRIVER_VENDOR',
        'type': 'ViString'
    },
    1050514: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns a string that contains a brief description of NI-RFSG.  This attribute returns National Instruments RF Signal Generator Instrument Driver.\n     '
        },
        'name': 'SPECIFIC_DRIVER_DESCRIPTION',
        'type': 'ViString'
    },
    1050515: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the major version number of the class specification with which  NI-RFSG is compliant.\n     '
        },
        'name': 'SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION',
        'type': 'ViInt32'
    },
    1050516: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the minor version number of the class specification with which  NI-RFSG is compliant.\n     '
        },
        'name': 'SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION',
        'type': 'ViInt32'
    },
    1050551: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns a string that contains additional version information about  NI-RFSG. For example, NI-RFSG can return Driver: NI-RFSG 14.5.0,  Compiler: MSVC 9.00, Components: IVI Engine 4.00, VISA-Spec 4.00.\n     '
        },
        'name': 'SPECIFIC_DRIVER_REVISION',
        'type': 'ViString'
    },
    1150001: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the Reference Clock source. To set this attribute, the NI-RFSG  device must be in the Configuration state. Only certain combinations  of this attribute and the NIRFSG_ATTR_PXI_CHASSIS_CLK10_SOURCE  attribute are valid\n \n backplane clock on PXI chassis only using the  NIRFSG_ATTR_PXI_CHASSIS_CLK10_SOURCE attribute. \n \n  ',
            'note': ' PXI-5670/5671 and PXIe-5672 devices also allow you to drive the PXI 10 MHz '
        },
        'enum': 'RefClockSource',
        'name': 'REF_CLOCK_SOURCE',
        'type': 'ViString'
    },
    1150002: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the source terminal for the Start Trigger. This attribute is  used when the NIRFSG_ATTR_START_TRIGGER_TYPE attribute is set to  NIRFSG_VAL_DIGITAL_EDGE. This attribute is not case-sensitive. To set the  NIRFSG_ATTR_DIGITAL_EDGE_START_TRIGGER_SOURCE attribute, the NI-RFSG device  must be in the Configuration state.\n \n'
        },
        'enum': 'StartTriggerSource',
        'name': 'DIGITAL_EDGE_START_TRIGGER_SOURCE',
        'type': 'ViString'
    },
    1150003: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the destination terminal for exporting the Start Trigger.  To set this attribute, the NI-RFSG device must be in the Configuration  state.\n \n'
        },
        'enum': 'AnySignalOutputTerm',
        'name': 'EXPORTED_START_TRIGGER_OUTPUT_TERMINAL',
        'type': 'ViString'
    },
    1150004: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the clock source for driving the PXI 10 MHz backplane Reference  Clock. This attribute is configurable if the PXI-5610 upconverter  module is installed in only Slot 2 of a PXI chassis. To set this attribute, the  NI-RFSG device must be in the Configuration state.\n'
        },
        'enum': 'PXIChassisClk10',
        'name': 'PXI_CHASSIS_CLK10_SOURCE',
        'type': 'ViString'
    },
    1150005: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the driver maintains phase continuity in the  arbitrary waveforms. When this attribute is set to  NIRFSG_VAL_ENABLE, NI-RFSG may increase the waveform size. When  this attribute is set to NIRFSG_VAL_ENABLE, the  NIRFSG_ATTR_FREQUENCY_TOLERANCE attribute specifies the maximum  allowable frequency error that can be introduced when keeping the  signal phase-continuous. To set the NIRFSG_ATTR_PHASE_CONTINUITY_ENABLED  attribute, the NI-RFSG device must be in the Configuration state.  NIRFSG_ATTR_PHASE_CONTINUITY_ENABLED applies only when the  NIRFSG_ATTR_GENERATION_MODE attribute is set to  NIRFSG_VAL_ARB_WAVEFORM or NIRFSG_VAL_SCRIPT. \n \n On the PXI-5671: When using the PXI-5671 with I/Q rates less than or equal  to 8.33 MS/s, an input phase-continuous signal is always phase-continuous  upon output, and this attribute has no effect. \n \n PXIe-5644/5645/5646, PXIe-5672/5673/5673E, PXIe-5820/5830/5831/5840/5841: Phase continuity is always enabled on this device. \n \n'
        },
        'enum': 'PhaseContinuity',
        'name': 'PHASE_CONTINUITY_ENABLED',
        'type': 'ViInt32'
    },
    1150006: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum frequency error allowed during the software  upconversion process. NI-RFSG may introduce a frequency error up to the  specified amount in order to optimize computational speed and onboard  memory usage while upconverting phase-continuous signals. \n \n If the NIRFSG_ATTR_PHASE_CONTINUITY_ENABLED attribute is set to  NIRFSG_VAL_DISABLE, the NIRFSG_ATTR_FREQUENCY_TOLERANCE attribute is  ignored, and the driver does not introduce a frequency error. On devices  that do not use software upconversion, this attribute is ignored. The  PXI-5670 always uses software upconversion, and the PXI-5671 uses software  upconversion for I/Q rates greater than 8.33 MS/s. \n \n To set the  NIRFSG_ATTR_FREQUENCY_TOLERANCE attribute, the NI-RFSG device must be in  the Configuration state.\n \n Units: hertz (Hz) \n \n'
        },
        'name': 'FREQUENCY_TOLERANCE',
        'type': 'ViReal64'
    },
    1150007: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the bandwidth of the arbitrary signal. \n \n This value must be less than or equal to (0.8 * I/Q rate). \n \n NI-RFSG defines signal bandwidth as twice the maximum baseband signal deviation  from 0 Hz. Usually, the baseband signal center frequency is 0 Hz.  In such cases, the signal bandwidth is simply the baseband signal's minimum frequency  subtracted from its maximum frequency. \n \n This attribute applies only when the NIRFSG_ATTR_GENERATION_MODE attribute  is set to NIRFSG_VAL_ARB_WAVEFORM or NIRFSG_VAL_SCRIPT,  except for when using the PXIe-5840/5841, which supports setting this attribute  in all supported generation modes. To set the NIRFSG_ATTR_SIGNAL_BANDWIDTH  attribute, the NI-RFSG device must be in the Configuration state. \n \n PXI-5670/5671, PXIe-5672: Based on your signal bandwidth, NI-RFSG determines whether to  configure the upconverter center frequency in increments of 1 MHz or 5 MHz.  Failure to configure this attribute may result in the signal being placed outside  the upconverter passband. \n \n PXIe-5644/5645/5646, PXIe-5673/5673E: This attribute is used only for  error-checking purposes. Otherwise, this attribute is ignored. \n \n PXIe-5820/5830/5831/5840/5841: Based on your signal bandwidth, NI-RFSG decides the  equalized bandwidth. If this attribute is not set, NI-RFSG uses  the maximum available signal bandwidth. For the PXIe-5840/5841, the maximum allowed signal  bandwidth depends on the upconverter center frequency. Refer to the  specifications document for your device for more information about signal  bandwidth. The device specifications depend on the signal bandwidth. \n Units: hertz (Hz) \n \n"
        },
        'name': 'SIGNAL_BANDWIDTH',
        'type': 'ViReal64'
    },
    1150008: {
        'access': 'read only',
        'documentation': {
            'description': ' Enables or disables automatic thermal correction. When enabled, changes to  settings cause NI-RFSG to check whether the device temperature has changed  and adjustd the settings as needed.When disabled, you must explicitly call  the niRFSG_PerformThermalCorrection function to adjust the device for  temperature changes. \n \n  '
        },
        'name': 'AUTOMATIC_THERMAL_CORRECTION',
        'type': 'ViInt32'
    },
    1150009: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether attenuator hold is enabled. While this attribute is  set to VI_TRUE, changing the power level causes NI-RFSG to scale the  digital data sent to the AWG instead of adjusting the attenuators.  Changing power levels in this manner allows the device to increase or  decrease the power level in more accurate increments, but it may affect  signal-to-noise ratios (noise density).\n \n Setting this attribute to VI_TRUE limits the power levels that can be  attained. With attenuator hold enabled, the power level must satisfy the  following conditions:\n \n - Power level <= the maximum power level set with the  NIRFSG_ATTR_ATTENUATOR_HOLD_MAX_POWER attribute \n - Power level >= (the maximum power level set with  the  NIRFSG_ATTR_ATTENUATOR_HOLD_MAX_POWER attribute -70 dB)\n - Power level >= -145 dBm\n \n To set this attribute, the NI-RFSG device must be in the Configuration  state.\n \n'
        },
        'name': 'ATTENUATOR_HOLD_ENABLED',
        'type': 'ViBoolean'
    },
    1150010: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum power level of the RF output signal whenthe  NIRFSG_ATTR_ATTENUATOR_HOLD_ENABLED attribute is set to VI_TRUE.\n \n To set this attribute, the NI-RFSG device must be in the Configuration  state.\n \n Units: dBm \n'
        },
        'name': 'ATTENUATOR_HOLD_MAX_POWER',
        'type': 'ViReal64'
    },
    1150011: {
        'access': 'read only',
        'documentation': {
            'description': ' Specifies the maximum instantaneous power of the current RF output signal.   \n attribute is set to NIRFSG_VAL_AVERAGE_POWER. \n  \n Units: dBm \n  \n',
            'note': ' This attribute is valid only when the NIRFSG_ATTR_POWER_LEVEL_TYPE '
        },
        'name': 'PEAK_ENVELOPE_POWER',
        'type': 'ViReal64'
    },
    1150012: {
        'access': 'read-write',
        'documentation': {
            'description': ' When this attribute is enabled, NI-RFSG equalizes the waveform  data to correct for variations in the response of the NI-RFSG device.  Enabling digital equalization improves  the modulation error rates (MER) and error vector magnitude (EVM) for  signals with large bandwidths (> 500 kHz). On the PXI-5670/5671, this  equalization is performed in the software so that tuning time is  increased. On the PXIe-5672, this is performed in the hardware so that it  has no performance penalties.\n \n This attribute only applies when the NIRFSG_ATTR_GENERATION_MODE attribute  is set to NIRFSG_VAL_ARB_WAVEFORM or NIRFSG_VAL_SCRIPT. To set this  attribute, the NI-RFSG device must be in the Configuration state.\n \n PXIe-5644/5645/5646, PXIe-5820/5830/5831/5840/5841: NIRFSG_VAL_ENABLE is the only supported value for this device.\n \n'
        },
        'enum': 'EnableValues',
        'name': 'DIGITAL_EQUALIZATION_ENABLED',
        'type': 'ViInt32'
    },
    1150013: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the local oscillator signal is present at the front  panel LO Out connector.\n The local oscillator signal remains at the LO OUT front panel connector  until this attribute is set to VI_FALSE even if the  NIRFSG_ATTR_OUTPUT_ENABLED attribute is set to VI FALSE,  the niRFSG_Abort function is called, or the NI-RFSG sesssion is closed.  To use this attribute for the PXIe-5830/5831, you must use the channelName parameter  of the niRFSG_SetAttributeViBoolean function to specify the name of the channel you are configuring. You can  configure the LO1 and LO2 channels by using lo1 or lo2 as the channel string, or set the channel string to lo1,lo2  to configure both channels. For all other devices, the the only valid value for the channel string is  (empty string). \n \n'
        },
        'name': 'LO_OUT_ENABLED',
        'type': 'ViBoolean'
    },
    1150014: {
        'access': 'read-write',
        'documentation': {
            'description': ' Enables or disables warnings or errors when you set the frequency, power, or bandwidth values beyond the limits  of the NI-RFSG device specifications. When you enable the NIRFSG_ATTR_ALLOW_OUT_OF_SPECIFICATION_USER_SETTINGS attribute,  the driver does not report out-of-specification warnings or errors. \n \n To set this attribute, the NI-RFSG device must be in the Configuration state. \n \n \n',
            'note': ' Accuracy cannot be guaranteed outside of device specifications, and results may vary by unit. \n'
        },
        'name': 'ALLOW_OUT_OF_SPECIFICATION_USER_SETTINGS',
        'type': 'ViInt32'
    },
    1150015: {
        'access': 'read-write',
        'documentation': {
            'description': ' Indicates the carrier frequency generated by the arbitrary waveform  generator (AWG) module. The specified carrier frequency is related  to the RF output as shown in the following equations: \n \n PXI-5610, PXI-5670/5671, PXIe-5672 \n RF Frequency (MHz) = Upconverter Center Frequency + Arb Carrier Frequency - 25 MHz \n \n PXIe-5644/5645/5646, PXIe-5673/5673E, PXIe-5830/5831/5840/5841 \n RF Frequency (MHz) = Upconverter Center Frequency + Arb Carrier Frequency \n \n and the NIRFSG_ATTR_ARB_CARRIER_FREQUENCY attribute cannot be set at the same time.  The only time the carrier frequency is nonzero on the PXIe-5644/5645/5646, PXIe-5673/5673E, PXIe-5840/5841 is when in-band retuning is used.  \n \n Units: Hz \n \n',
            'note': ' This attribute is read-only on the PXI-5670/5671, PXIe-5672. \n'
        },
        'name': 'ARB_CARRIER_FREQUENCY',
        'type': 'ViReal64'
    },
    1150016: {
        'access': 'read only',
        'documentation': {
            'description': ' Indicates the average output power from the PXI-5421, PXI-5441, PXIe-5442, and PXIe-5450  AWG module. If an arbitrary waveform is being generated, this  attribute specifies either the average power or the peak power of the  signal, depending on the NIRFSG_ATTR_POWER_LEVEL_TYPE  attribute setting. \n \n  Units: dBm \n \n'
        },
        'name': 'ARB_POWER',
        'type': 'ViReal64'
    },
    1150017: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the device temperature. If the NI-RFSG session is controlling  multiple devices, this attribute returns the temperature of the primary  NI RF device.  The NI-RFSG session is opened using the primary RF device name. \n \n Serial signals between the sensor and the system control unit could  modulate the signal being generated, thus causing phase spurs. After the device  thoroughly warms up, its temperature varies only slightly (less than 1 degree Celsius)  and slowly, and it is not necessary to constantly poll this temperature sensor.  Refer to the thermal management topic appropriate to your device in the  NI RF Signal Generators Help for more information about device temperature. \n PXIe-5644/5645/5646, PXIe-5820/5840/5841: If you query this attribute during RF  list mode, list steps may take longer to complete during list execution. \n PXIe-5830/5831: To use this attribute, you must first set the channelName parameter of the niRFSG_SetAttributeViReal64 function  to using the appropriate string for your instrument configuration. Refer to the NI-RFSG C Function Reference for more information about  the applicable string to use for your instrument configuration. \n\n Units: desgrees Celsius (°C) \n \n'
        },
        'name': 'DEVICE_TEMPERATURE',
        'type': 'ViReal64'
    },
    1150018: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to generate a continuous wave (CW) signal, the arb  waveform specified by the NIRFSG_ATTR_SELECTED_WAVEFORM attribute, or the  script specified by the NIRFSG_ATTR_SELECTED_SCRIPT attribute, upon  calling the niRFSG_Initiate function. \n  '
        },
        'enum': 'GenerationMode',
        'name': 'GENERATION_MODE',
        'type': 'ViInt32'
    },
    1150019: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the Script Trigger type. Depending upon the value of this  attribute, more attributes may be needed to fully configure the trigger.  To set this attribute, the NI-RFSG device must be in the Configuration  state.\n \n'
        },
        'enum': 'ScriptTriggerType',
        'name': 'SCRIPT_TRIGGER_TYPE',
        'type': 'ViInt32'
    },
    1150020: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the source terminal for the Script Trigger. This attribute is  used when the NIRFSG_ATTR_SCRIPT_TRIGGER_TYPE attribute is set to  NIRFSG_VAL_DIGITAL_EDGE. This attribute is not case-sensitive. To set this  attribute, the NI-RFSG device must be in the Configuration state.\n \n'
        },
        'enum': 'SciptTriggerSource',
        'name': 'DIGITAL_EDGE_SCRIPT_TRIGGER_SOURCE',
        'type': 'ViString'
    },
    1150021: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the active edge for the Script Trigger. This attribute is used  when NIRFSG_ATTR_SCRIPT_TRIGGER_TYPE is set to NIRFSG_VAL_DIGITAL_EDGE. To  set the NIRFSG_ATTR_DIGITAL_EDGE_SCRIPT_TRIGGER_EDGE attribute,  the NI-RFSG device must be in the Configuration state.\n \n'
        },
        'enum': 'DigitalEdgeEdge',
        'name': 'DIGITAL_EDGE_SCRIPT_TRIGGER_EDGE',
        'type': 'ViInt32'
    },
    1150022: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the destination terminal for exporting the Script Trigger. To  set this attribute, the NI-RFSG device must be in the Configuration state.  For trigger delay information, refer to the triggering section in the NI  RF Signal Generators Help. \n \n'
        },
        'enum': 'AnySignalOutputTerm',
        'name': 'EXPORTED_SCRIPT_TRIGGER_OUTPUT_TERMINAL',
        'type': 'ViString'
    },
    1150023: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the script in onboard memory to generate upon calling the  niRFSG_Initiate function when NIRFSG_ATTR_GENERATION_MODE is set to  NIRFSG_VAL_SCRIPT.  \n \n The NIRFSG_ATTR_SELECTED_SCRIPT attribute is ignored  when the NIRFSG_ATTR_GENERATION_MODE attribute is set to  NIRFSG_VAL_ARB_WAVEFORM or NIRFSG_VAL_CW. To set the  NIRFSG_ATTR_SELECTED_SCRIPT attribute, the NI-RFSG device must be in the  Configuration state.\n'
        },
        'name': 'SELECTED_SCRIPT',
        'type': 'ViString'
    },
    1150024: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the phase of the RF output signal. Use this attribute  to align the phase of the RF output with the phase of the RF output of  another device, as long as the two devices are phase-coherent. \n \n Units: degrees (º) \n \n'
        },
        'name': 'PHASE_OFFSET',
        'type': 'ViReal64'
    },
    1150025: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the AWG prefilter gain. The prefilter gain is  applied to the waveform data before any other signal processing.  Reduce this value to prevent overflow in the AWG interpolation filters.  Other gains on the NI-RFSG device are automatically adjusted to  compensate for nonunity AWG prefilter gain. The PXI-5671 and  the PXIe-5672 must be in the Configuration state to use this attribute.  However, the PXIe5644/5645/5646, PXIe-5673/5673E, and PXIe-5820/5830/5831/5840/5841 can be in either the Configuration  or the Generation state to use this attribute. \n \n On the PXI-5671, this attribute applies only when the  NIRFSG_ATTR_IQ_RATE attribute is set to a value  less than or equal to 8.33 MS/s. On the PXIe-5644/5645/5646,  PXIe-5672/5673/5673E, and PXIe-5820/5830/5831/5840/5841, this attribute is always applicable.\n \n Units: dB \n \n'
        },
        'name': 'ARB_PRE_FILTER_GAIN',
        'type': 'ViReal64'
    },
    1150026: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the serial number of the RF module.\n'
        },
        'name': 'SERIAL_NUMBER',
        'type': 'ViString'
    },
    1150027: {
        'access': 'read-write',
        'documentation': {
            'description': ' Configures the loop bandwidth of the tuning PLLs. This attribute is ignored on the  PXI-5610, PXI-5670/5671, PXIe-5672 for signal bandwidths greater than or equal to 10 MHz.  This attribute is ignored on the PXI/PXIe-5650/5651/5652 for RF frequencies less than 50 MHz. \n \n PXIe-5644/5645/5646/5650/5651/5652/5673/5673E allows the frequency to settle  significantly faster at the expense of increased phase noise.  Setting this attribute to NIRFSG_VAL_MEDIUM is not a valid  option on the PXI/PXIe-5650/5651/5652, PXIe-5673/5673E. NIRFSG_VAL_MEDIUM is the only  supported value for the PXIe-5830/5831/5840/5841. \n To use this attribute for the PXIe-5830/5831, you must use the channelName parameter  of the niRFSG_SetAttributeViInt32 function to specify the name of the channel you are configuring. You can  configure the LO1 and LO2 channels by using lo1 or lo2 as the channel string, or set the channel string to lo1,lo2  to configure both channels. For all other devices, the the only valid value for the channel string is  (empty string). \n \n',
            'note': ' Setting this attribute to NIRFSG_VAL_WIDE on the '
        },
        'enum': 'LoopBandwidth',
        'name': 'LOOP_BANDWIDTH',
        'type': 'ViInt32'
    },
    1150029: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the Sample Clock mode on the device.  To set this attribute, the device must be in the Configuration state. \n \n PXIe-5644/5645/5646, PXIe-5820/5830/5831/5840/5841: NIRFSG_VAL_DIVIDE_DOWN is the only supported value for this device. \n \n',
            'note': ' Using the high resolution clock may result in increased phase noise. /n'
        },
        'enum': 'ArbOnboardSampleClockMode',
        'name': 'ARB_ONBOARD_SAMPLE_CLOCK_MODE',
        'type': 'ViInt32'
    },
    1150030: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the Sample Clock source for the device.  To set this attribute, the NI-RFSG device must be in the Configuration state.\n \n PXIe-5644/5645/5646, PXIe-5820/5830/5831/5840/5841: NIRFSG_VAL_ONBOARD_CLK_STR is the only supported value for this device. \n \n'
        },
        'enum': 'ArbSampleClockSource',
        'name': 'ARB_SAMPLE_CLOCK_SOURCE',
        'type': 'ViString'
    },
    1150031: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the rate of the Sample Clock on the device. \n \n Units: hertz (Hz) \n \n'
        },
        'name': 'ARB_SAMPLE_CLOCK_RATE',
        'type': 'ViReal64'
    },
    1150032: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the analog modulation format to use. \n \n'
        },
        'enum': 'AnalogModulationType',
        'name': 'ANALOG_MODULATION_TYPE',
        'type': 'ViInt32'
    },
    1150033: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the type of waveform to use as the message signal for analog  modulation. \n \n'
        },
        'enum': 'AnalogModulationWaveformType',
        'name': 'ANALOG_MODULATION_WAVEFORM_TYPE',
        'type': 'ViInt32'
    },
    1150034: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the frequency of the waveform to use as the message signal in  analog modulation. \n Units: hertz (Hz) \n \n  '
        },
        'name': 'ANALOG_MODULATION_WAVEFORM_FREQUENCY',
        'type': 'ViReal64'
    },
    1150035: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the frequency deviation to use in frequency modulation. \n'
        },
        'name': 'ANALOG_MODULATION_FM_DEVIATION',
        'type': 'ViReal64'
    },
    1150036: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the digital modulation format to use.\n \n'
        },
        'enum': 'DigitalModulationType',
        'name': 'DIGITAL_MODULATION_TYPE',
        'type': 'ViInt32'
    },
    1150037: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the symbol rate of the bit stream for FSK modulation.\n'
        },
        'name': 'DIGITAL_MODULATION_SYMBOL_RATE',
        'type': 'ViReal64'
    },
    1150038: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the type of waveform to use as the message signal in digital  modulation.\n \n'
        },
        'enum': 'DigitalModulationWaveformType',
        'name': 'DIGITAL_MODULATION_WAVEFORM_TYPE',
        'type': 'ViInt32'
    },
    1150039: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the order of the pseudorandom bit sequence (PRBS)  sequence internally generated by hardware  and used as the message signal in digital modulation. \n'
        },
        'name': 'DIGITAL_MODULATION_PRBS_ORDER',
        'type': 'ViInt32'
    },
    1150040: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the seed of the internally generated  pseudorandom bit sequence (PRBS) sequence.\n'
        },
        'name': 'DIGITAL_MODULATION_PRBS_SEED',
        'type': 'ViInt32'
    },
    1150041: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the deviation to use in FSK modulation. \n'
        },
        'name': 'DIGITAL_MODULATION_FSK_DEVIATION',
        'type': 'ViReal64'
    },
    1150042: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the niRFSG_WriteArbWaveform function writes waveforms  immediately to the device or copies the waveform to host memory for  download later. NI-RFSG reads and validates this attribute when an  arbitrary waveform is first allocated.\n \n PXI-5670: Direct download is always disabled. \n \n PXI-5671: To increase performance when using large waveforms,  enable direct download.  To maximize reconfigurability, disable direct  download.\n \n  Perform the following steps to enable direct download:\n -Set the IQ rate to less than or equal to 8.33 MS/s with the  NIRFSG_ATTR_IQ_RATE attribute. \n -Set the NIRFSG_ATTR_POWER_LEVEL_TYPE attribute to NIRFSG_VAL_PEAK_POWER. \n -Disable the NIRFSG_ATTR_IQ_SWAP_ENABLED attribute. \n -Disable the NIRFSG_ATTR_DIGITAL_EQUALIZATION_ENABLED attribute. \n \n PXIe-5644/5645/5646, PXIe-5672/5673/5673E, PXIe-5820/5840/5841: Direct download is always enabled. \n \n  '
        },
        'enum': 'EnableValues',
        'name': 'DIRECT_DOWNLOAD',
        'type': 'ViInt32'
    },
    1150043: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies how NI-RFSG interprets the value of the  NIRFSG_ATTR_POWER_LEVEL attribute.  The NIRFSG_ATTR_POWER_LEVEL_TYPE  attribute also affects how waveforms are scaled.\n \n PXI-5670/5671: While in Script generation mode, if this attribute is set to NIRFSG_VAL_AVERAGE_POWER,  NI-RFSG scales each waveform so that all waveforms have the same average power.  The average power level of each waveform matches the value set with the NIRFSG_ATTR_POWER_LEVEL attribute.  You can disable this scaling operation by setting the NIRFSG_ATTR_POWER_LEVEL_TYPE attribute to NIRFSG_VAL_PEAK_POWER.\n \n PXIe-5644/5645/5646, PXIe-5672/5673/5673E, PXIe-5820/5830/5831/5840/5841: While in Script generation mode, this attribute must be set to NIRFSG_VAL_PEAK_POWER. \n \n'
        },
        'enum': 'PowerLevelType',
        'name': 'POWER_LEVEL_TYPE',
        'type': 'ViInt32'
    },
    1150044: {
        'access': 'read-write',
        'documentation': {
            'description': ' Enables or disables digital pattern on the PXI-5421/5441 AWG module. This  attribute must be set to VI_TRUE to enable signal routing to and from the  Digital Data &amp; Control connector. To set this attribute, the NI-RFSG  device must be in the Configuration state.\n \n'
        },
        'name': 'DIGITAL_PATTERN',
        'type': 'ViBoolean'
    },
    1150045: {
        'access': 'read-write',
        'documentation': {
            'description': ' Enables or disables streaming of waveform data.\n \n'
        },
        'name': 'STREAMING_ENABLED',
        'type': 'ViBoolean'
    },
    1150046: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the name of the waveform used to continuously stream data during  generation.\n \n'
        },
        'name': 'STREAMING_WAVEFORM_NAME',
        'type': 'ViString'
    },
    1150047: {
        'access': 'read only',
        'documentation': {
            'description': ' Indicates the space available, in samples, in the streaming  waveform for writing new data. For optimal performance, write  new data to the waveform in a fixed size that is an integer  divisor of the total size of the streaming waveform.  This waveform size ensures that writes do not have to wrap  around from the end to the beginning of the waveform buffer. \n \n To read this attribute, the NI-RFSG device must be in  the Committed state. \n  \n Units: Samples \n \n  '
        },
        'name': 'STREAMING_SPACE_AVAILABLE_IN_WAVEFORM',
        'type': 'ViInt64'
    },
    1150048: {
        'access': 'read-write',
        'documentation': {
            'description': ' Indicates the number of samples download to onboard memory at one time. This  attribute is useful when the total data to be transferred to onboard  memory is large. \n Units: Samples \n \n'
        },
        'name': 'DATA_TRANSFER_BLOCK_SIZE',
        'type': 'ViInt32'
    },
    1150052: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies how much to scale the data before writing it with the  niRFSG_WriteArbWaveform function. The resulting waveform must be  smaller than 1.0 in complex magnitude. This attribute is supported only  if you set the NIRFSG_ATTR_POWER_LEVEL_TYPE attribute to  NIRFSG_VAL_PEAK_POWER. \n \n'
        },
        'name': 'ARB_WAVEFORM_SOFTWARE_SCALING_FACTOR',
        'type': 'ViReal64'
    },
    1150053: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the destination terminal for exporting the Reference Clock on  the NI RF signal generators. To set this attribute,  the NI-RFSG device must be in the Configuration state. \n'
        },
        'enum': 'RefClockOutputTerm',
        'name': 'EXPORTED_REF_CLOCK_OUTPUT_TERMINAL',
        'type': 'ViString'
    },
    1150054: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the source terminal for the Script Trigger. This attribute is  used when the NIRFSG_ATTR_SCRIPT_TRIGGER_TYPE attribute is set to  NIRFSG_VAL_DIGITAL_LEVEL. This attribute is not case-sensitive. To set  the NIRFSG_ATTR_DIGITAL_LEVEL_SCRIPT_TRIGGER_SOURCE attribute,  the NI-RFSG device must be in the Configuration state.\n \n'
        },
        'enum': 'SciptTriggerSource',
        'name': 'DIGITAL_LEVEL_SCRIPT_TRIGGER_SOURCE',
        'type': 'ViString'
    },
    1150055: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the active level for the Script Trigger. This attribute is used  when the NIRFSG_ATTR_SCRIPT_TRIGGER_TYPE attribute is set to  NIRFSG_VAL_DIGITAL_LEVEL. \n \n'
        },
        'enum': 'DigitalLevelActiveLevel',
        'name': 'DIGITAL_LEVEL_SCRIPT_TRIGGER_ACTIVE_LEVEL',
        'type': 'ViInt32'
    },
    1150056: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the pulse-shaping filter type for the FIR filter. You can use this attribute  only with signal generators that support onboard signal processing (OSP).  NI-RFSG returns an error if you use this attribute with a device that  does not support OSP. \n'
        },
        'enum': 'ArbFilterType',
        'name': 'ARB_FILTER_TYPE',
        'type': 'ViInt32'
    },
    1150057: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the alpha value to use when calculating the pulse-shaping FIR filter coefficients.  You can use this attribute when the NIRFSG_ATTR_ARB_FILTER_TYPE  attribute is set to NIRFSG_VAL_ARB_ROOT_RAISED_COSINE and with signal  generators that support onboard signal processing (OSP).  NI-RFSG returns an error if you use this attribute with a device  that does not support OSP. \n'
        },
        'name': 'ARB_FILTER_ROOT_RAISED_COSINE_ALPHA',
        'type': 'ViReal64'
    },
    1150058: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies which upconverter center frequencies are used. This attribute  can be used to increase the speed of frequency sweeps by reducing the  number of times the upconverter is retuned. \n This attribute is obsolete and should not be used. \n \n  '
        },
        'name': 'UPCONVERTER_CENTER_FREQUENCY_INCREMENT',
        'type': 'ViReal64'
    },
    1150059: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the reference point for the upconverter center frequencies to  use.This attribute can be used to speed up frequency sweeps by reducing  the number of times the upconverter is retuned. \n This attribute is obsolete and should not be used. \n \n  '
        },
        'name': 'UPCONVERTER_CENTER_FREQUENCY_INCREMENT_ANCHOR',
        'type': 'ViReal64'
    },
    1150060: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the alpha value to use when calculating the pulse-shaping filter coefficients.  You can use this attribute when the NIRFSG_ATTR_ARB_FILTER_TYPE  attribute is set to NIRFSG_VAL_ARB_RAISED_COSINE and with signal  generators that support onboard signal processing (OSP).  NI-RFSG returns an error if you use this attribute with a device  that does not support OSP. \n \n'
        },
        'name': 'ARB_FILTER_RAISED_COSINE_ALPHA',
        'type': 'ViReal64'
    },
    1150061: {
        'access': 'read only',
        'documentation': {
            'description': ' The total amount of memory on the signal generator in bytes. \n \n of onboard memory stores scripts that specify how the waveforms are  generated. These scripts typically require less than 1 KB of  onboard memory. \n',
            'note': ' Not all onboard memory can be used for waveform storage. A portion '
        },
        'name': 'MEMORY_SIZE',
        'type': 'ViInt64'
    },
    1150062: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the deviation to use in phase modulation, in degrees. \n'
        },
        'name': 'ANALOG_MODULATION_PM_DEVIATION',
        'type': 'ViReal64'
    },
    1150063: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the destination terminal for exporting the Done event. To set  this attribute, the NI-RFSG device must be in the Configuration state.\n'
        },
        'enum': 'AnySignalOutputTerm',
        'name': 'EXPORTED_DONE_EVENT_OUTPUT_TERMINAL',
        'type': 'ViString'
    },
    1150064: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the destination terminal for exporting the marker event. To set  this attribute, the NI-RFSG device must be in the Configuration state.\n'
        },
        'enum': 'AnySignalOutputTerm',
        'name': 'EXPORTED_MARKER_EVENT_OUTPUT_TERMINAL',
        'type': 'ViString'
    },
    1150065: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the destination terminal for exporting the started event. To set  this attribute, the NI-RFSG device must be in the Configuration state.\n'
        },
        'enum': 'AnySignalOutputTerm',
        'name': 'EXPORTED_STARTED_EVENT_OUTPUT_TERMINAL',
        'type': 'ViString'
    },
    1150066: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the power level of the signal at the LO OUT front panel connector. \n For the PXIe-5644/5645/5646/5673/5673E, this attribute is always read-only. \n To use this attribute for the PXIe-5830/5831, you must use the channelName parameter  of the niRFSG_SetAttributeViReal64 function to specify the name of the channel you are configuring. You can  configure the LO1 and LO2 channels by using lo1 or lo2 as the channel string, or set the channel string to lo1,lo2  to configure both channels. For all other devices, the the only valid value for the channel string is  (empty string). \n \n Units: dBm \n \n'
        },
        'name': 'LO_OUT_POWER',
        'type': 'ViReal64'
    },
    1150067: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the power level of the signal at the front panel LO IN  connector. \n \n Otherwise, this attribute is read-only. \n \n To use this attribute for the PXIe-5830/5831, you must use the channelName parameter  of the niRFSG_SetAttributeViReal64 function to specify the name of the channel you are configuring. You can  configure the LO1 and LO2 channels by using lo1 or lo2 as the channel string, or set the channel string to lo1,lo2  to configure both channels. For all other devices, the the only valid value for the channel string is  (empty string). \n \n Units: dBm \n \n',
            'note': ' For the PXIe-5644/5645/5646, this attribute is always read-only. \n'
        },
        'name': 'LO_IN_POWER',
        'type': 'ViReal64'
    },
    1150068: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the AWG module temperature in degrees Celsius. \n PXIe-5820/5840/5841: If you query this attribute during RF list mode, list steps may  take longer to complete during list execution. \n \n Units: degrees Celsius (°C) \n \n'
        },
        'name': 'ARB_TEMPERATURE',
        'type': 'ViReal64'
    },
    1150069: {
        'access': 'read-write',
        'documentation': {
            'description': ' Enables/disables I/Q impairment.  The NIRFSG_ATTR_IQ_I_OFFSET,  NIRFSG_ATTR_IQ_Q_OFFSET, NIRFSG_ATTR_IQ_GAIN_IMBALANCE, and  NIRFSG_ATTR_IQ_SKEW attributes are ignored when the  NIRFSG_ATTR_IQ_IMPAIRMENT_ENABLED attribute is disabled. \n \n  '
        },
        'name': 'IQ_IMPAIRMENT_ENABLED',
        'type': 'ViBoolean'
    },
    1150070: {
        'access': 'read-write',
        'documentation': {
            'description': ' When using a National Instruments AWG module or vector  signal transceiver (VST), this attribute specifies the  I-signal DC offset. Units are either percent or volts,  depending on the NIRFSG_ATTR_OFFSET_UNITS attribute setting. \n \n PXIe-5673/5673E: Actual AWG signal offset is equal to the I/Q  modulator offset correction plus the value specified by this attribute.  When using an external AWG, this attribute is read-only  and indicates the I/Q modulator I-offset.  Units are volts, as indicated  by the NIRFSG_ATTR_OFFSET_UNITS attribute. \n \n'
        },
        'name': 'IQ_I_OFFSET',
        'type': 'ViReal64'
    },
    1150071: {
        'access': 'read-write',
        'documentation': {
            'description': ' When using a National Instruments AWG or VST device, this attribute  specifies the Q-signal DC offset. Units are either percent or volts,  depending on the NIRFSG_ATTR_OFFSET_UNITS attribute. \n \n PXIe-5673/5673E: Actual AWG signal offset is equal to the  I/Q modulator offset correction plus the value specified by this  attribute. When using an external AWG (non-National Instruments AWG),  this attribute is read-only, and indicates the IQ modulator Q offset.  Units are volts, as indicated by the NIRFSG_ATTR_OFFSET_UNITS attribute. \n \n'
        },
        'name': 'IQ_Q_OFFSET',
        'type': 'ViReal64'
    },
    1150072: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the gain imbalance of the I/Q modulator (I versus Q). \n \n Units: dB \n \n'
        },
        'name': 'IQ_GAIN_IMBALANCE',
        'type': 'ViReal64'
    },
    1150073: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the adjustment of the phase angle between the I and Q vectors.  If this skew is zero, the phase angle is 90 degrees. \n'
        },
        'name': 'IQ_SKEW',
        'type': 'ViReal64'
    },
    1150075: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the LO module temperature in degrees Celsius. \n PXIe-5840/5841: If you query this attribute during RF list mode, list steps may take longer to complete during list execution. \n \n Units: degrees Celsius (°C) \n \n'
        },
        'name': 'LO_TEMPERATURE',
        'type': 'ViReal64'
    },
    1150076: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the recommended interval between each external calibration of the device. \n \n Units: months \n'
        },
        'name': 'EXTERNAL_CALIBRATION_RECOMMENDED_INTERVAL',
        'type': 'ViInt32'
    },
    1150077: {
        'access': 'read only',
        'documentation': {
            'description': ' Indicates in degrees Celsius the temperature of the device at the time of  the last external calibration. \n'
        },
        'name': 'EXTERNAL_CALIBRATION_TEMPERATURE',
        'type': 'ViReal64'
    },
    1150078: {
        'access': 'read only',
        'documentation': {
            'description': ' Specifies a string that contains arbitrary, user-defined information that  is stored with external calibration. \n This attribute is obsolete and should not be used. \n  '
        },
        'name': 'EXTERNAL_CALIBRATION_USER_DEFINED_INFO',
        'type': 'ViString'
    },
    1150079: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the maximum string length for the  NIRFSG_ATTR_EXTERNAL_CALIBRATION_USER_DEFINED_INFO attribute. \n This attribute is obsolete and should not be used. \n  '
        },
        'name': 'EXTERNAL_CALIBRATION_USER_DEFINED_INFO_MAX_SIZE',
        'type': 'ViInt32'
    },
    1150081: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the units of the NIRFSG_ATTR_IQ_I_OFFSET attribute and the  NIRFSG_ATTR_IQ_Q_OFFSET attribute.  Offset units are either percent or  volts.\n \n'
        },
        'enum': 'IqOffsetUnits',
        'name': 'IQ_OFFSET_UNITS',
        'type': 'ViInt32'
    },
    1150082: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the interpretation of the value passed to the  NIRFSG_ATTR_FREQUENCY_SETTLING attribute. \n \n'
        },
        'enum': 'FrequencySettlingUnits',
        'name': 'FREQUENCY_SETTLING_UNITS',
        'type': 'ViInt32'
    },
    1150083: {
        'access': 'read-write',
        'documentation': {
            'description': ' Configures the frequency settling time.  Interpretation of this value  depends on the NIRFSG_ATTR_FREQUENCY_SETTLING_UNITS attribute. \n \n'
        },
        'name': 'FREQUENCY_SETTLING',
        'type': 'ViReal64'
    },
    1150084: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the module revision letter.  If the NI-RFSG session is controlling multiple devices, this returns the module revision letter of the primary RF device.  The NI-RFSG session is  opened using the primary RF device name.\n'
        },
        'name': 'MODULE_REVISION',
        'type': 'ViString'
    },
    1150085: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the external amplification or attenuation, if any, between  the RF signal generator and the device under test.  \n Positive values for this attribute represent amplification, and  negative values for this attribute represent attenuation. \n power to compensate for any amplification or attenuation between  the RF signal generator and the device under test. \n',
            'note': ' For the PXIe-5645, this attribute is ignored if you are using the I/Q ports. \n'
        },
        'name': 'EXTERNAL_GAIN',
        'type': 'ViReal64'
    },
    1150086: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum amount of bus bandwidth to use for data transfers. \n'
        },
        'name': 'DATA_TRANSFER_MAXIMUM_BANDWIDTH',
        'type': 'ViReal64'
    },
    1150087: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the preferred size of the data field in a PCI Express read request packet. \n'
        },
        'name': 'DATA_TRANSFER_PREFERRED_PACKET_SIZE',
        'type': 'ViInt32'
    },
    1150088: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum number of concurrent PCI Express read requests the RF signal generator can issue. \n'
        },
        'name': 'DATA_TRANSFER_MAXIMUM_IN_FLIGHT_READS',
        'type': 'ViInt32'
    },
    1150089: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the oscillator phase digital-to-analog converter (DAC) value  on the arbitrary waveform generator (AWG).  Use this attribute to reduce  the trigger jitter when synchronizing multiple devices with NI-TClk.  This attribute can also help maintain synchronization repeatability  by writing a previous measurement's phase DAC value to the current session.  This attribute is applicable only when using the  NIRFSG_ATTR_ARB_SAMPLE_CLOCK_SOURCE attribute set to NIRFSG_VAL_CLK_IN_STR. /n"
        },
        'name': 'ARB_OSCILLATOR_PHASE_DAC_VALUE',
        'type': 'ViInt32'
    },
    1150096: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the name of the configuration list to make active.  When you get or set  an attribute and it is in the configuration list configuration,  the attribute is set to or read from the active list step of the  active configuration list. \n \n If the NIRFSG_ATTR_ACTIVE_CONFIGURATION_LIST attribute is set  to &quot;&quot; (empty string), no list is active. \n \n the NIRFSG_ATTR_FREQUENCY_SETTLING_UNITS attribute supports only NIRFSG_VAL_TIME_AFTER_IO as a valid value. \n',
            'note': ' For the PXI/PXIe-5650/5651/5652, PXIe-5673E, when this attribute is set to a valid list name, '
        },
        'name': 'ACTIVE_CONFIGURATION_LIST',
        'type': 'ViString'
    },
    1150097: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the step in the configuration list for RF list mode  that you want to make active for configuration or initiation. \n'
        },
        'name': 'ACTIVE_CONFIGURATION_LIST_STEP',
        'type': 'ViInt32'
    },
    1150098: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the type of trigger to use as the Configuration List Step Trigger.  To set this attribute, the NI-RFSG device must be in the  Configuration state. \n'
        },
        'enum': 'ListStepTriggerType',
        'name': 'CONFIGURATION_LIST_STEP_TRIGGER_TYPE',
        'type': 'ViInt32'
    },
    1150099: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the source terminal for the Configuration List Step trigger.  This attribute is valid only when the  NIRFSG_ATTR_CONFIGURATION_LIST_STEP_TRIGGER_TYPE attribute is set to  NIRFSG_VAL_DIGITAL_EDGE. \n'
        },
        'enum': 'ConfigListTrigSource',
        'name': 'DIGITAL_EDGE_CONFIGURATION_LIST_STEP_TRIGGER_SOURCE',
        'type': 'ViString'
    },
    1150100: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the time, in seconds, before the timer emits an event  after the task is started and specifies the time interval  between Timer events after the first event.  If you do not set this attribute, the timer is disabled. \n',
            'note': ' For the PXIe-5820/5840/5841, this attribute must be set for the timer to start. '
        },
        'name': 'TIMER_EVENT_INTERVAL',
        'type': 'ViReal64'
    },
    1150102: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the configuration list runs only once or continuously.\n'
        },
        'enum': 'ConfigurationListRepeat',
        'name': 'CONFIGURATION_LIST_REPEAT',
        'type': 'ViInt32'
    },
    1150103: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the active edge for the Configuration List Step  trigger.  This attribute is valid only when the  NIRFSG_ATTR_CONFIGURATION_LIST_STEP_TRIGGER_TYPE attribute  is set to NIRFSG_VAL_DIGITAL_EDGE. To set this attribute, the NI-RFSG  device must be in the Configuration state. \n'
        },
        'enum': 'ConfigListTriggerDigEdgeEdge',
        'name': 'DIGITAL_EDGE_CONFIGURATION_LIST_STEP_TRIGGER_EDGE',
        'type': 'ViInt32'
    },
    1150104: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the temperature, in degrees Celsius, to use for adjusting the device settings  to correct for temperature changes. If you set this attribute, NI-RFSG uses the value  you specify and therefore no longer uses the actual device temperature as the correction  temperature. If you do not set this attribute, NI-RFSG checks the current device temperature  in the Committed state and automatically sets the value of this attribute.\n \n to be used every time, regardless of the temperature variation. In these cases,  it is good to ensure that the temperature does not vary too much. \n \n PXIe-5820/5830/5831/5840/5841: This attribute is read only. \n \n Units: degrees Celsius (°C) \n \n',
            'note': ' Use this attribute only when your application requires the same settings '
        },
        'name': 'CORRECTION_TEMPERATURE',
        'type': 'ViReal64'
    },
    1150105: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the destination terminal for exporting the Configuration List Step trigger.  To set this attribute, the NI-RFSG device must be in the Configuration state. \n'
        },
        'enum': 'ConfigListTrigOutputTerm',
        'name': 'EXPORTED_CONFIGURATION_LIST_STEP_TRIGGER_OUTPUT_TERMINAL',
        'type': 'ViString'
    },
    1150112: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the name of the fully qualified signal name as a string. \n \n'
        },
        'name': 'STARTED_EVENT_TERMINAL_NAME',
        'type': 'ViString'
    },
    1150113: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the name of the fully qualified signal name as a string. \n'
        },
        'name': 'DONE_EVENT_TERMINAL_NAME',
        'type': 'ViString'
    },
    1150114: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the name of the fully qualified signal name as a string.\n \n'
        },
        'name': 'START_TRIGGER_TERMINAL_NAME',
        'type': 'ViString'
    },
    1150115: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the name of the fully qualified signal name as a string. \n \n'
        },
        'name': 'MARKER_EVENT_TERMINAL_NAME',
        'type': 'ViString'
    },
    1150116: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the name of the fully qualified signal name as a string.\n \n'
        },
        'name': 'SCRIPT_TRIGGER_TERMINAL_NAME',
        'type': 'ViString'
    },
    1150117: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the fully qualified signal name as a string. \n'
        },
        'name': 'CONFIGURATION_LIST_STEP_TRIGGER_TERMINAL_NAME',
        'type': 'ViString'
    },
    1150118: {
        'access': 'read-write',
        'documentation': {
            'description': ' Adjusts the dynamics of the current driving the YIG main coil.\n \n allows the frequency to settle significantly faster for some frequency  transitions at the expense of increased phase noise. \n \n',
            'note': ' Setting this attribute to NIRFSG_VAL_FAST on the PXIe-5653 '
        },
        'enum': 'YigMainCoil',
        'name': 'YIG_MAIN_COIL_DRIVE',
        'type': 'ViInt32'
    },
    1150122: {
        'access': 'read only',
        'documentation': {
            'description': ' Specifies the configuration list step that is currently programmed to the hardware.  The list is zero-indexed. You can query this attribute only when a list is executed. \n'
        },
        'name': 'CONFIGURATION_LIST_STEP_IN_PROGRESS',
        'type': 'ViInt64'
    },
    1150123: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the device reads data from the peer-to-peer  endpoint.  This attribute is endpoint-based. \n  \n'
        },
        'name': 'P2P_ENABLED',
        'type': 'ViBoolean'
    },
    1150124: {
        'access': 'read only',
        'documentation': {
            'description': " Returns the size, in samples, of the device's endpoint.  This attribute is endpoint-based. \n \n"
        },
        'name': 'P2P_ENDPOINT_SIZE',
        'type': 'ViInt64'
    },
    1150125: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the current space available in the endpoint. You can use this  attribute when priming the endpoint with initial data using the  niRFSG_WriteP2PEndpointI16 function to determine how many samples  you can write. You also can use this attribute to characterize the  performance and measure the latency of the peer-to-peer stream as data  moves across the bus. This attribute is endpoint-based. \n \n Units: samples per channel \n \n'
        },
        'name': 'P2P_SPACE_AVAILABLE_IN_ENDPOINT',
        'type': 'ViInt64'
    },
    1150126: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the largest number of samples per channel available in the endpoint since  this attribute was last read. You can use this attribute to determine how much  endpoint space to use as a buffer against bus traffic latencies by reading  the attribute and keeping track of the largest value returned.  This attribute is endpoint-based. \n \n If you want to minimize the latency for data to move through the endpoint  and be generated by the RF signal generator, use the  NIRFSG_ATTR_P2P_DATA_TRANSFER_PERMISSION_INITIAL_CREDITS attribute to grant  fewer initial credits than the default of the entire endpoint size. \n \n Units: samples per channel \n'
        },
        'name': 'P2P_MOST_SPACE_AVAILABLE_IN_ENDPOINT',
        'type': 'ViInt64'
    },
    1150127: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the number of peer-to-peer FIFO endpoints supported by the device. \n  \n'
        },
        'name': 'P2P_ENDPOINT_COUNT',
        'type': 'ViInt32'
    },
    1150128: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of samples needed to be received by the endpoint before  the device starts generation. This attribute applies only when the  NIRFSG_ATTR_START_TRIGGER_TYPE attribute is set to  NIRFSG_VAL_P2P_ENDPOINT_FULLNESS.\n \n Default Value: -1, which allows NI-RFSG to select the appropriate fullness level. \n'
        },
        'name': 'P2P_ENDPOINT_FULLNESS_START_TRIGGER_LEVEL',
        'type': 'ViInt64'
    },
    1150129: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the destination terminal for exporting the Configuration Settled event. To set  this attribute, the NI-RFSG device must be in the Configuration state.\n'
        },
        'enum': 'ConfigSettledEventOutputTerm',
        'name': 'EXPORTED_CONFIGURATION_SETTLED_EVENT_OUTPUT_TERMINAL',
        'type': 'ViString'
    },
    1150132: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the adjustment for the NIRFSG_ATTR_POWER_LEVEL attribute.  The value of the NIRFSG_ATTR_PEAK_POWER_ADJUSTMENT attribute adds  to the NIRFSG_ATTR_POWER_LEVEL attribute. The NIRFSG_ATTR_PEAK_POWER_ADJUSTMENT  attribute typically specifies the peak-to-average power ratio (PAPR) of  a waveform. If the PAPR is specified, the specified power level becomes  the average power level of the waveform, even if the  NIRFSG_ATTR_POWER_LEVEL_TYPE attribute is set to NIRFSG_VAL_PEAK_POWER. \n \n Refer to the Assigning Properties or Attributes to a Waveform topic of the  NI RF Signal Generators Help for more information. \n \n',
            'note': ' For the PXIe-5645, this attribute is ignored if you are using the I/Q ports. \n'
        },
        'name': 'PEAK_POWER_ADJUSTMENT',
        'type': 'ViReal64'
    },
    1150133: {
        'access': 'read-write',
        'documentation': {
            'description': ' Configures the loop bandwidth of the reference PLL.\n \n'
        },
        'enum': 'LoopBandwidth',
        'name': 'REF_PLL_BANDWIDTH',
        'type': 'ViInt32'
    },
    1150134: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the interval at which the RF signal generator issues  credits to allow the writer peer to transfer data over the bus into  the configured endpoint. Refer to the Flow Control topic in the  NI RF Signal Generators Help for more information. This attribute is  coerced up by NI-RFSG to the nearest 128-byte boundary.  This attribute is endpoint-based. \n Units: samples per channel \n \n'
        },
        'name': 'P2P_DATA_TRANSFER_PERMISSION_INTERVAL',
        'type': 'ViInt64'
    },
    1150135: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the initial amount of data that the writer peer  can transfer over the bus into the configured endpoint when the  peer-to-peer data stream is enabled. If this attribute is not  set and the endpoint is empty, credits equal to the full endpoint  size are issued to the writer peer. If data is written to the  endpoint using the niRFSG_WriteP2PEndpointI16 function prior to  enabling the stream, credits equal to the remaining space available  in the endpoint are issued to the writer peer. This attribute is  coerced up by NI-RFSG to 8-byte boundaries.   This attribute is endpoint based \n \n Units: samples per channel \n \n'
        },
        'name': 'P2P_DATA_TRANSFER_PERMISSION_INITIAL_CREDITS',
        'type': 'ViInt64'
    },
    1150136: {
        'access': 'read only',
        'documentation': {
            'description': ' Indicates in degrees Celsius the temperature of the device at the time of  the last self calibration. \n'
        },
        'name': 'SELF_CALIBRATION_TEMPERATURE',
        'type': 'ViReal64'
    },
    1150137: {
        'access': 'read-write',
        'documentation': {
            'description': ' Configures the amplitude settling accuracy in decibels. NI-RFSG waits until the  RF power settles within the specified accuracy level after calling the niRFSG_Initiate function  or niRFSG_WaitUntilSettled function or prior to advancing to next step if using RF list mode. \n \n Any specified amplitude settling value that is above the acceptable minimum value is  coerced down to the closest valid value. \n \n PXI/PXIe-5650/5651/5652: This attribute is for NI internal use only. \n \n Units: dB \n \n'
        },
        'name': 'AMPLITUDE_SETTLING',
        'type': 'ViReal64'
    },
    1150140: {
        'access': 'read-write',
        'documentation': {
            'description': ' Indicates the maximum amount of time allowed to complete a streaming write operation.\n \n'
        },
        'name': 'STREAMING_WRITE_TIMEOUT',
        'type': 'ViReal64'
    },
    1150141: {
        'access': 'read-write',
        'documentation': {
            'description': ' Determines the inheritance behavior of the NIRFSG_ATTR_PEAK_POWER_ADJUSTMENT  attribute when a script inherits values from specified waveforms. \n \n'
        },
        'enum': 'PPAScriptInheritance',
        'name': 'PEAK_POWER_ADJUSTMENT_INHERITANCE',
        'type': 'ViInt32'
    },
    1150142: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the device is the master device when synchronizing the Script Trigger between multiple devices. \n \n The master device distributes the synchronized Script Trigger to all devices in the system through the Script Trigger distribution line. \n \n When synchronizing the Script Trigger, one device must always be designated as the master.  The master device actively drives the Script Trigger distribution line. For slave devices, set the  NIRFSG_ATTR_SCRIPT_TRIGGER_TYPE attribute to NIRFSG_VAL_DIGITAL_EDGE, and set the  NIRFSG_ATTR_DIGITAL_EDGE_SCRIPT_TRIGGER_SOURCE attribute to sync_script. \n \n To set this attribute, the NI-RFSG device must be in the Configuration state. \n \n Refer to the Synchronization Using NI-RFSA and NI-RFSG topic appropriate to your device in the  NI RF Signal Generators Help for more information about device synchronization for vector signal transceivers. \n \n'
        },
        'name': 'SYNC_SCRIPT_TRIGGER_MASTER',
        'type': 'ViBoolean'
    },
    1150143: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies which external trigger line distributes the synchronized Script Trigger signal.  When synchronizing the Script Trigger, configure all devices to use the same Script Trigger distribution line. \n \n To set this attribute, the NI-RFSG device must be in the Configuration state. \n \n Refer to the Synchronization Using NI-RFSA and NI-RFSG topic appropriate to your device in the  NI RF Signal Generators Help for more information about device synchronization for vector signal transceivers. \n \n'
        },
        'name': 'SYNC_SCRIPT_TRIGGER_DIST_LINE',
        'type': 'ViString'
    },
    1150144: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the connector(s) to use to generate the signal. To set this attribute,  the NI-RFSG device must be in the Configuration state. \n \n You must write complex I and Q data for all options. The Q data has no effect if  you set this attribute to I Only and set the NIRFSG_ATTR_IQ_OUT_PORT_CARRIER_FREQUENCY  attribute to 0. If you set the NIRFSG_ATTR_IQ_OUT_PORT_CARRIER_FREQUENCY attribute to a  value other than 0, the onboard signal processing (OSP) frequency shifts I and Q as a complex  value and outputs the real portion of the result on the I connector(s) of the device. \n \n If you set the NIRFSG_ATTR_OUTPUT_PORT attribute to NIRFSG_VAL_I_ONLY or NIRFSG_VAL_IQ_OUT,  the NIRFSG_ATTR_IQ_OUT_PORT_TERMINAL_CONFIGURATION attribute applies. \n \n'
        },
        'enum': 'OutputPort',
        'name': 'OUTPUT_PORT',
        'type': 'ViInt32'
    },
    1150145: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the frequency of the I/Q OUT port signal. The onboard signal processing (OSP)  applies the specified frequency shift to the I/Q data before the data is sent to the  digital-to-analog converter (DAC). To set this attribute, the NI-RFSG device must be in the Configuration state. \n \n Units: hertz (Hz) \n \n',
            'note': ' For the PXIe-5645, this attribute is ignored if you are using the RF ports. \n'
        },
        'name': 'IQ_OUT_PORT_CARRIER_FREQUENCY',
        'type': 'ViReal64'
    },
    1150146: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to use the I/Q OUT port for Differential configuration or Single-Ended configuration.  If you set this attribute to NIRFSG_VAL_SINGLE_ENDED, you must terminate the negative I and Q output  connectors with a 50 Ohm termination. \n \n If you set this attribute to NIRFSG_VAL_SINGLE_ENDED, the positive I and Q connectors generate the resulting waveform.  If you set this attribute to NIRFSG_VAL_DIFFERENTIAL, both the positive and negative I and Q connectors generate the resulting waveform. \n\n To use this attribute, you must use the channelName parameter of the niRFSG_SetAttributeViInt32 function to  specify the name of the channel you are configuring. For the PXIe-5645, you can configure the I and Q channels  by using I or Q as the channel string, or set the channel string to  (empty string) to configure both channels.  For the PXIe-5820, the only valid value for the channel string is  (empty string). \n\n To set this attribute, the NI-RFSG device must be in the Configuration state. \n \n Refer to the Differential and Single-Ended Operation (I/Q Interface) topic of the NI RF Signal Generators Help  for more information about differential and single-ended operation.\n \n',
            'note': ' For the PXIe-5645, this attribute is ignored if you are using the RF ports. \n'
        },
        'enum': 'IqOutPortTermConfig',
        'name': 'IQ_OUT_PORT_TERMINAL_CONFIGURATION',
        'type': 'ViInt32'
    },
    1150147: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the amplitude of the generated signal in volts, peak-to-peak (Vpk-pk). For example,  if you set this attribute to 1.0, the output signal ranges from -0.5 volts to 0.5 volts. \n To use this attribute, you must use the channelName parameter of the niRFSG_SetAttributeViReal64 function to  specify the name of the channel you are configuring. For the PXIe-5645, you can configure the I and Q channels  by using I or Q as the channel string, or set the channel string to  (empty string) to configure both channels.  For the PXIe-5820, the only valid value for the channel string is  (empty string). \n\n To set this attribute, the NI-RFSG device must be in the Configuration state. \n \n Refer to the specifications document for your device for allowable output levels. \n \n Units: Volts, peak-to-peak \n \n',
            'note': ' For the PXIe-5645, this attribute is ignored if you are using the RF ports. \n'
        },
        'name': 'IQ_OUT_PORT_LEVEL',
        'type': 'ViReal64'
    },
    1150148: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the common-mode offset applied to the signals generated at each differential output terminal.  This attribute applies only when you set the NIRFSG_ATTR_IQ_OUT_PORT_TERMINAL_CONFIGURATION attribute to NIRFSG_VAL_DIFFERENTIAL.  Common-mode offset shifts both positive and negative terminals in the same direction. \n To use this attribute, you must use the channelName parameter of the niRFSG_SetAttributeViReal64 function to  specify the name of the channel you are configuring. For the PXIe-5645, you can configure the I and Q channels  by using I or Q as the channel string, or set the channel string to  (empty string) to configure both channels.  For the PXIe-5820, the only valid value for the channel string is  (empty string). \n\n \n To set this attribute, the NI-RFSG device must be in the Configuration state. \n \n Units: Volts \n \n',
            'note': ' For the PXIe-5645, this attribute is ignored if you are using the RF ports. \n'
        },
        'name': 'IQ_OUT_PORT_COMMON_MODE_OFFSET',
        'type': 'ViReal64'
    },
    1150149: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the value, in volts, that the signal generator adds to the I and Q signals.  To set this attribute, the NI-RFSG device must be in the Configuration state. \n To use this attribute, you must use the channelName parameter of the niRFSG_SetAttributeViReal64 function to  specify the name of the channel you are configuring. For the PXIe-5645, you can configure the I and Q channels  by using I or Q as the channel string, or set the channel string to  (empty string) to configure both channels.  For the PXIe-5820, the only valid value for the channel string is  (empty string). \n\n Units: Volts \n \n Supported Devices: PXIe-5645, PXIe-5820 \n PXIe-5645: The waveform may be scaled in DSP prior to adding offset and the device state may be changed in order to accommodate the requested offset.\n PXIe-5820: The waveform is not automatically scaled in DSP prior to adding offset. To prevent DSP overflows, use the NIRFSG_ATTR_ARB_PRE_FILTER_GAIN attribute  to scale the waveform to provide additional headroom for offsets. \n \n',
            'note': ' For the PXIe-5645, this attribute is ignored if you are using the RF ports. \n'
        },
        'name': 'IQ_OUT_PORT_OFFSET',
        'type': 'ViReal64'
    },
    1150150: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to use the internal or external local oscillator (LO) source.  If this attribute is set to  (empty string), NI-RFSG uses the internal LO source.  To set this attribute, the NI-RFSG device must be in the Configuration state. \n To use this attribute for the PXIe-5830/5831, you must use the channelName parameter  of the niRFSG_SetAttributeViString function to specify the name of the channel you are configuring. You can  configure the LO1 and LO2 channels by using lo1 or lo2 as the channel string, or set the channel string to lo1,lo2  to configure both channels. For all other devices, the the only valid value for the channel string is  (empty string). \n \n \n',
            'note': ' For the PXIe-5841 with PXIe-5655, RF list mode is not supported when this attribute is set to NIRFSG_VAL_LO_SOURCE_SG_SA_SHARED_STR. \n'
        },
        'enum': 'LoSource',
        'name': 'LO_SOURCE',
        'type': 'ViString'
    },
    1150151: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the step size, in hertz, for tuning the local oscillator (LO) phase-locked loop (PLL). \n \n When the NIRFSG_ATTR_LO_PLL_FRACTIONAL_MODE_ENABLED attribute is enabled, the specified step size  affects the fractional spur performance of the device. When the NIRFSG_ATTR_LO_PLL_FRACTIONAL_MODE_ENABLED  attribute is disabled, the specified step size affects the phase noise performance of the device. \n \n The valid values for this attribute depend on the NIRFSG_ATTR_LO_PLL_FRACTIONAL_MODE_ENABLED attribute.  PXIe-5644/5645/5646—If you disable the NIRFSG_ATTR_LO_PLL_FRACTIONAL_MODE_ENABLED attribute, the specified value is  coerced to the nearest valid value. \n \n PXIe-5840/5841—If you disable the NIRFSG_ATTR_LO_PLL_FRACTIONAL_MODE_ENABLED attribute, the specified value is  coerced to the nearest valid value that is less than or equal to the desired step size. \n \n'
        },
        'name': 'LO_FREQUENCY_STEP_SIZE',
        'type': 'ViReal64'
    },
    1150152: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to use fractional mode for the local oscillator (LO) phase-locked loop (PLL).  This attribute enables or disables fractional frequency tuning in the LO. Fractional mode  provides a finer frequency step resolution and allows smaller values for the  NIRFSG_ATTR_LO_FREQUENCY_STEP_SIZE attribute. However, fractional mode may introduce non-harmonic spurs. \n \n This attribute applies only if you set the NIRFSG_ATTR_LO_SOURCE attribute to NIRFSG_VAL_LO_SOURCE_ONBOARD_STR. \n \n Refer to the local oscillators topic appropriate to your device in the  NI RF Signal Generators Help for more information about using fractional mode. \n To use this attribute for the PXIe-5830/5831, you must use the channelName parameter  of the niRFSG_SetAttributeViInt32 function to specify the name of the channel you are configuring. You can  configure the LO1 and LO2 channels by using lo1 or lo2 as the channel string, or set the channel string to lo1,lo2  to configure both channels. For all other devices, the the only valid value for the channel string is  (empty string). \n \n \n',
            'note': ' For the PXIe-5841 with PXIe-5655, this attribute is ignored if the PXIe-5655 is used as the LO source. \n'
        },
        'enum': 'EnableValues',
        'name': 'LO_PLL_FRACTIONAL_MODE_ENABLED',
        'type': 'ViInt32'
    },
    1150153: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the delay, in seconds, to apply to the I/Q waveform. To set this attribute,  the NI-RFSG device must be in the Configuration state. \n \n Units: Seconds \n \n'
        },
        'name': 'INTERPOLATION_DELAY',
        'type': 'ViReal64'
    },
    1150154: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the delay, in seconds, applied to the Started event, Done event, and all Marker events with respect to the analog  output of the RF signal generator. To set this attribute, the NI-RFSG device must be in the Configuration or Generation state. \n By default, markers and events are delayed to align with the waveform data generated from the device.  This attribute adds an additional delay to markers and events. Use this attribute to adjust the time delay between  events and the corresponding data. \n \n Units: Seconds \n \n',
            'note': ' If you decrease the event delay during generation, some markers may be dropped. \n\n'
        },
        'name': 'EVENTS_DELAY',
        'type': 'ViReal64'
    },
    1150155: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the device is the master device when synchronizing the Start Trigger between multiple devices. \n \n The master device distributes the synchronized Start Trigger to all devices in the system through the Start Trigger distribution line. \n \n When synchronizing the Start Trigger, one device must always be designated as the master.  The master device actively drives the Start Trigger distribution line. For slave devices, set the NIRFSG_ATTR_START_TRIGGER_TYPE  attribute to NIRFSG_VAL_DIGITAL_EDGE, and set the NIRFSG_ATTR_DIGITAL_EDGE_START_TRIGGER_SOURCE attribute to sync_script. \n \n To set this attribute, the NI-RFSG device must be in the Configuration state. \n \n Refer to the Synchronization Using NI-RFSA and NI-RFSG topic appropriate to your device in the  NI RF Signal Generators Help for more information about device synchronization for vector signal transceivers. \n \n'
        },
        'name': 'SYNC_START_TRIGGER_MASTER',
        'type': 'ViBoolean'
    },
    1150156: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies which external trigger line distributes the synchronized Start Trigger signal. When synchronizing the Start Trigger,  configure all devices to use the same Start Trigger distribution line. \n \n To set this attribute, the NI-RFSG device must be in the Configuration state. \n \n Refer to the Synchronization Using NI-RFSA and NI-RFSG topic appropriate to your device in the  NI RF Signal Generators Help for more information about device synchronization for vector signal transceivers. \n \n'
        },
        'name': 'SYNC_START_TRIGGER_DIST_LINE',
        'type': 'ViString'
    },
    1150157: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the repetition mode of a waveform when you set the NIRFSG_ATTR_GENERATION_MODE attribute to NIRFSG_VAL_ARB_WAVEFORM.  If you set this attribute to VI_TRUE, the number of repetitions is determined by the NIRFSG_ATTR_ARB_WAVEFORM_REPEAT_COUNT attribute.\n To set this attribute, the NI-RFSG device must be in the Configuration state.\n \n'
        },
        'name': 'ARB_WAVEFORM_REPEAT_COUNT_IS_FINITE',
        'type': 'ViBoolean'
    },
    1150158: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the repeat count of a waveform when you set the  NIRFSG_ATTR_ARB_WAVEFORM_REPEAT_COUNT_IS_FINITE attribute to VI_TRUE.  This attribute is valid only when you set the NIRFSG_ATTR_GENERATION_MODE attribute to NIRFSG_VAL_ARB_WAVEFORM. \n To set this attribute, the NI-RFSG device must be in the Configuration state.\n \n'
        },
        'name': 'ARB_WAVEFORM_REPEAT_COUNT',
        'type': 'ViInt32'
    },
    1150160: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute offsets the NIRFSG_ATTR_UPCONVERTER_CENTER_FREQUENCY from the RF frequency.  Use this attribute to keep the local oscillator (LO) leakage at a determined offset from the RF signal. \n \n the NIRFSG_ATTR_ARB_CARRIER_FREQUENCY attribute at the same time as the NIRFSG_ATTR_UPCONVERTER_FREQUENCY_OFFSET attribute. \n \n \n',
            'note': ' Resetting this attribute disables the upcoverter frequency offset. \n'
        },
        'name': 'UPCONVERTER_FREQUENCY_OFFSET',
        'type': 'ViReal64'
    },
    1150161: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the temperature, in degrees Celsius, of the I/Q Out circuitry on the device.  \n \n Units: Degrees Celsius \n \n',
            'note': ' If you query this attribute during RF list mode, list steps may take longer to complete during list execution. \n'
        },
        'name': 'IQ_OUT_PORT_TEMPERATURE',
        'type': 'ViReal64'
    },
    1150162: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the marker event at which RF blanking occurs. RF blanking quickly attenuates the RF OUT signal.  Use marker events to toggle the state of RF blanking. The RF Output always starts in the unblanked state. \n \n To set this attribute, the NI-RFSG device must be in the Configuration state. \n \n You can specify marker events by using scripts to trigger blanking at a certain point in a waveform.  For example, if you set this attribute to NIRFSG_VAL_MARKER0, and marker0 occurs on samples 1,000  and 2,000 of a script, then the RF Output will be blanked (attenuated) between samples 1,000 and 2,000. \n \n \n',
            'note': ' For the PXIe-5840/5841, RF blanking does not occur for frequencies below 120 MHz. \n'
        },
        'name': 'RF_BLANKING_SOURCE',
        'type': 'ViString'
    },
    1150163: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the load impedance connected to the I/Q OUT port. To set this attribute, the NI-RFSG device must be in the Configuration state. \n To use this attribute, you must use the channelName parameter of the niRFSG_SetAttributeViReal64 function to  specify the name of the channel you are configuring. For the PXIe-5645, you can configure the I and Q channels  by using I or Q as the channel string, or set the channel string to  (empty string) to configure both channels.  For the PXIe-5820, the only valid value for the channel string is  (empty string). \n\n Units: Ohms \n \n',
            'note': ' For the PXIe-5645, this attribute is ignored if you are using the RF ports. \n'
        },
        'name': 'IQ_OUT_PORT_LOAD_IMPEDANCE',
        'type': 'ViReal64'
    },
    1150165: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the narrowband frequency modulation (FM) range to apply  by sending the signal through an integrator. \n This attribute is valid only when you set the NIRFSG_ATTR_ANALOG_MODULATION_TYPE  attribute to NIRFSG_VAL_FM and the NIRFSG_ATTR_ANALOG_MODULATION_FM_BAND attribute to NIRFSG_VAL_NARROWBAND. \n'
        },
        'enum': 'AnalogModulationFMNarrowbandIntegrator',
        'name': 'ANALOG_MODULATION_FM_NARROWBAND_INTEGRATOR',
        'type': 'ViInt32'
    },
    1150166: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies an uncalibrated digital-to-analog converter (DAC) value that scales the  input signal before the signal modulates the carrier. A value of 0 completely  attenuates the signal, and a value of 100 passes the full-scale signal to the modulator.\n'
        },
        'name': 'ANALOG_MODULATION_FM_SENSITIVITY',
        'type': 'ViReal64'
    },
    1150167: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies an uncalibrated digital-to-analog converter (DAC) value that scales  the input signal before the signal modulates the carrier. A value of 0 completely  attenuates the signal, and a value of 100 passes the full-scale signal to the modulator.\n \n When using the PXIe-5654 with PXIe-5696, NI-RFSG may coerce AM sensitivity.  Coercing the AM sensitivity prevents overpower conditions at the PXIe-5696 input.  Read this attribute to determine the coerced value. \n'
        },
        'name': 'ANALOG_MODULATION_AM_SENSITIVITY',
        'type': 'ViReal64'
    },
    1150168: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies an uncalibrated digital-to-analog converter (DAC) value that  scales the input signal before the signal modulates the carrier. A value of 0  completely attenuates the signal, and a value of 100 passes the full-scale signal to the modulator.\n'
        },
        'name': 'ANALOG_MODULATION_PM_SENSITIVITY',
        'type': 'ViReal64'
    },
    1150173: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the level of attenuation in the attenuator path.  Setting this attribute overrides the value chosen by NI-RFSG.  Not all power levels are achievable if you set this attribute. \n \n Units: dB \n \n Valid Values: 0 dB to 110 dB in steps of 10 \n',
            'note': ' Resetting this attribute reverts back to the default unset behavior.\n'
        },
        'name': 'ATTENUATOR_SETTING',
        'type': 'ViReal64'
    },
    1150175: {
        'access': 'read-write',
        'name': 'CONFIGURATION_LIST_IS_DONE',
        'type': 'ViBoolean'
    },
    1150180: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the device is the master device when synchronizing the Sample Clock between multiple devices. \n \n The master device distributes the Sample Clock sync signal to all devices in the system through the Sample   Clock sync distribution line. \n \n When synchronizing the Sample Clock, one device must always be designated as the master.  The master device actively drives the Sample Clock sync distribution line. \n \n To set this attribute, the NI-RFSG device must be in the Configuration state.\n \n Refer to the Synchronization Using NI-RFSA and NI-RFSG topic in the NI RF Signal Generators Help  for more information about PXIe-5646 device synchronization.\n \n'
        },
        'name': 'SYNC_SAMPLE_CLOCK_MASTER',
        'type': 'ViBoolean'
    },
    1150181: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies which external trigger line distributes the Sample Clock sync signal.  When synchronizing the Sample Clock, configure all devices to use the same Sample Clock sync distribution line.\n \n To set this attribute, the NI-RFSG device must be in the Configuration state.\n \n Refer to the Synchronization Using NI-RFSA and NI-RFSG topic in the NI RF Signal Generators Help  for more information about PXIe-5646 device synchronization.\n \n'
        },
        'name': 'SYNC_SAMPLE_CLOCK_DIST_LINE',
        'type': 'ViString'
    },
    1150182: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the amplitude extender module temperature in degrees Celsius. \n \n Units: degrees Celsius (°C) \n \n'
        },
        'name': 'AE_TEMPERATURE',
        'type': 'ViReal64'
    },
    1150185: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the amplification path to use. The low harmonic path provides greater  second and third harmonic spurious response, and the high power path provides higher output power. \n \n NI-RFSG automatically sets the value of this attribute based on power and frequency settings.  Setting this attribute overrides the value chosen by NI-RFSG.\n \n  \n',
            'note': ' Resetting this attribute reverts back to the default unset behavior. \n'
        },
        'enum': 'AmpPath',
        'name': 'AMP_PATH',
        'type': 'ViInt32'
    },
    1150186: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns a string containing the path to the location of the current NI-RFSG instrument  driver FPGA extensions bitfile, a .lvbitx file, that is programmed on the device.  You can specify the bitfile location using the Driver Setup string in the optionString parameter  of the niRFSG_InitWithOptions function. \n \n NI-RFSG instrument driver FPGA extensions enable you to use pre-compiled FPGA bitfiles to  customize the behavior of the vector signal transceiver FPGA while maintaining the functionality  of the NI-RFSG instrument driver. \n  \n Refer to the NI-RFSA and NI-RFSG Instrument Driver FPGA Extensions topic in the NI RF Signal  Generators Help for more information about using NI-RFSG instrument driver FPGA extensions for  NI vector signal analyzers. \n \n'
        },
        'name': 'FPGA_BITFILE_PATH',
        'type': 'ViString'
    },
    1150188: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns whether the NI RF signal generator has the fast tuning option available.\n'
        },
        'name': 'FAST_TUNING_OPTION',
        'type': 'ViBoolean'
    },
    1150190: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the pulse modulation mode to use.\n \n'
        },
        'enum': 'PulseModulationMode',
        'name': 'PULSE_MODULATION_MODE',
        'type': 'ViInt32'
    },
    1150191: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the analog modulation frequency modulation (FM) band to use.  Wideband FM allows for modulating signals higher than 100 kHz.  Narrowband FM allows for modulating lower frequency signals. \n'
        },
        'enum': 'AnalogModulationFMBand',
        'name': 'ANALOG_MODULATION_FM_BAND',
        'type': 'ViInt32'
    },
    1150192: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the phase modulation (PM) mode to use. \n'
        },
        'enum': 'AnalogModulationPMMode',
        'name': 'ANALOG_MODULATION_PM_MODE',
        'type': 'ViInt32'
    },
    1150194: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the name of the fully qualified signal name as a string. \n \n'
        },
        'name': 'CONFIGURATION_SETTLED_EVENT_TERMINAL_NAME',
        'type': 'ViString'
    },
    1150195: {
        'access': 'read-write',
        'documentation': {
            'description': ' Enables or disables the automatic leveling control (ALC). \n \n PXIe-5654 with PXIe-5696: If this attribute is enabled, the ALC is closed (closed-loop mode)  and allows for better amplitude accuracy and wider amplitude dynamic range.  If this attribute is disabled, the ALC is open (open-loop mode), which is ideal when using modulation.  Disabling the NIRFSG_ATTR_ALC_CONTROL attribute also allows for NI-RFSG to perform an automatic power search. \n \n PXIe-5654: NIRFSG_VAL_DISABLE is the only supported value for this device.  The PXIe-5654 does not support the ALC when used as a stand-alone device. \n \n'
        },
        'enum': 'EnableValues',
        'name': 'ALC_CONTROL',
        'type': 'ViInt32'
    },
    1150196: {
        'access': 'read-write',
        'documentation': {
            'description': ' Enables or disables automatic power search. When this attribute is enabled,  a power search performs after the device is initiated, after output power is enabled,  or when the frequency or power level changes while the device is generating.  When this attribute is disabled, NI-RFSG does not perform a power search unless you call the niRFSG_PerformPowerSearch function. \n \n This attribute is ignored when the NIRFSG_ATTR_ALC_CONTROL attribute is enabled. \n \n PXIe-5654: NIRFSG_VAL_DISABLE is the only supported value for this device.\n'
        },
        'enum': 'EnableValues',
        'name': 'AUTO_POWER_SEARCH',
        'type': 'ViInt32'
    },
    1150199: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the frequency of the local oscillator (LO). \n \n Otherwise, this attribute is read-only. \n To use this attribute for the PXIe-5830/5831, you must use the channelName parameter  of the niRFSG_SetAttributeViReal64 function to specify the name of the channel you are configuring. You can  configure the LO1 and LO2 channels by using lo1 or lo2 as the channel string, or set the channel string to lo1,lo2  to configure both channels. For all other devices, the the only valid value for the channel string is  (empty string). \n \n Units: Hz \n \n',
            'note': ' This attribute is read/write if you are using an external LO. '
        },
        'name': 'LO_FREQUENCY',
        'type': 'ViReal64'
    },
    1150204: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the digital gain, in decibels. The digital gain is applied to the  waveform data after filtering. Use this attribute to adjust the output power  of the device while keeping the analog path fixed. This may cause clipping,  overflows, or quantization noise if used improperly. \n To set this attribute, the NI-RFSG device must be in the Configuration or  Generation state. \n \n Default Value: 0 dB \n \n'
        },
        'name': 'ARB_DIGITAL_GAIN',
        'type': 'ViReal64'
    },
    1150206: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the output behavior for the Marker Event.  To set this attribute,  the NI-RFSG device must be in the Configuration state. \n'
        },
        'enum': 'MarkerEventOutputBehavior',
        'name': 'MARKER_EVENT_OUTPUT_BEHAVIOR',
        'type': 'ViInt32'
    },
    1150207: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the pulse width value for the Marker Event. Use the  NIRFSG_ATTR_MARKER_EVENT_PULSE_WIDTH_UNITS attribute to set the units for the  pulse width value. This attribute is valid only when the  NIRFSG_ATTR_MARKER_EVENT_OUTPUT_BEHAVIOR attribute is set to NIRFSG_VAL_PULSE. \n \n To set this attribute, the NI-RFSG device must be in the Configuration state. \n \n'
        },
        'name': 'MARKER_EVENT_PULSE_WIDTH',
        'type': 'ViReal64'
    },
    1150208: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the pulse width units for the Marker Event. This attribute is  valid only when the NIRFSG_ATTR_MARKER_EVENT_OUTPUT_BEHAVIOR attribute is set to NIRFSG_VAL_PULSE. \n \n To set this attribute, the NI-RFSG device must be in the Configuration state. \n \n'
        },
        'enum': 'MarkerEventPulseWidthUnits',
        'name': 'MARKER_EVENT_PULSE_WIDTH_UNITS',
        'type': 'ViInt32'
    },
    1150209: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the initial state for the Marker Event when the  NIRFSG_ATTR_MARKER_EVENT_OUTPUT_BEHAVIOR attribute is set to NIRFSG_VAL_TOGGLE.  \n \n To set this attribute, the NI-RFSG device must be in the Configuration state. \n \n'
        },
        'enum': 'MarkerEventToggleInitialState',
        'name': 'MARKER_EVENT_TOGGLE_INITIAL_STATE',
        'type': 'ViInt32'
    },
    1150210: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the total power consumption of the device. \n Units: Watts \n Supported Devices: PXIe-5820/5830/5831/5840/5841 \n \n',
            'note': ' If you query this attribute during RF list mode, list steps may take longer to complete during list execution. \n'
        },
        'name': 'MODULE_POWER_CONSUMPTION',
        'type': 'ViReal64'
    },
    1150211: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the FPGA temperature in degrees Celsius. \n \n Serial signals between the sensor and the system control unit can  potentially modulate the signal being generated, thus causing phase spurs.  After the device thoroughly warms up, its temperature varies only slightly  (less than 1 degree Celsius) and slowly, and it is not necessary to  constantly poll this temperature sensor. \n Units: desgrees Celsius (°C) \n \n',
            'note': ' If you query this attribute during RF list mode, list steps may take longer to complete during list execution. \n'
        },
        'name': 'FPGA_TEMPERATURE',
        'type': 'ViReal64'
    },
    1150212: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the minimum time between temperature sensor readings. \n'
        },
        'name': 'TEMPERATURE_READ_INTERVAL',
        'type': 'ViReal64'
    },
    1150217: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether peer-to-peer should continuously generate data from  the peer-to-peer stream or from only a finite number of samples,  according to the NIRFSG_ATTR_P2P_NUMBER_OF_SAMPLES_TO_GENERATE attribute.  To use this attribute, peer-to-peer must be enabled. This attribute is endpoint-based.  \n \n'
        },
        'name': 'P2P_IS_FINITE_GENERATION',
        'type': 'ViBoolean'
    },
    1150218: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies how many samples are generated from the peer-to-peer subsystem  when it is enabled. To use this attribute, peer-to-peer must be enabled and  set to finite generation. This attribute is endpoint-based. \n \n'
        },
        'name': 'P2P_NUMBER_OF_SAMPLES_TO_GENERATE',
        'type': 'ViInt64'
    },
    1150219: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns how many samples NI-RFSG pulls from the peer-to-peer FIFO per read.  You can use this attribute to determine how many samples to send across the  peer-to-peer bus to ensure that no samples are ignored. If you send a number  of samples that is not a multiple of this value, the remaining samples are not  read from the FIFO during generation. This attribute is endpoint-based. \n \n'
        },
        'name': 'P2P_GENERATION_FIFO_SAMPLE_QUANTUM',
        'type': 'ViInt64'
    },
    1150220: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the delay, in seconds, to apply to the I/Q waveform. \n Relative delay allows for delaying the generated signal from one device relative  to the generated signal of another device after those devices have been synchronized.  You can achieve a negative relative delay by delaying both synchronized devices by the  same value (1 us) before generation begins and then changing the relative delay to a  smaller amount than the initial value on only one of the devices. \n \n that does not support this attribute, use the NITCLK_ATTR_SAMPLE_CLOCK_DELAY attribute. \n \n To set this attribute, the NI-RFSG device must be in the Configuration or Generation state. \n \n of the sample period but not worse than one Sample Clock period. \n \n Units: Seconds \n \n Valid Values: 0 us to 3.2 us \n \n Supported Devices: PXIe-5820/5830/5831/5840/5841 \n',
            'note': ' The resolution of this attribute is a function of the I/Q sample period at 15E(-6) '
        },
        'name': 'RELATIVE_DELAY',
        'type': 'ViReal64'
    },
    1150225: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the sub-Sample Clock delay, in seconds, to apply to the I/Q waveform.  Use this attribute to reduce the trigger jitter when synchronizing multiple devices with NI-TClk.  This attribute can also help maintain synchronization repeatability by writing the absolute delay  value of a previous measurement to the current session. \n To set this attribute, the NI-RFSG device must be in the Configuration state. \n \n \n \n Units: Seconds \n \n Valid Values: Plus or minus half of one Sample Clock period. \n \n Supported Devices: PXIe-5820/5840/5841 \n',
            'note': ' The resolution of this attribute is a function of the I/Q sample period at 15E(-6) times that sample period.  \n'
        },
        'name': 'ABSOLUTE_DELAY',
        'type': 'ViReal64'
    },
    1150226: {
        'access': 'read-write',
        'name': 'DEVICE_INSTANTANEOUS_BANDWIDTH',
        'type': 'ViReal64'
    },
    1150228: {
        'access': 'read-write',
        'documentation': {
            'description': ' Configures error reporting for onboard signal processing (OSP) overflows. Overflows lead to clipping of the waveform. \n\n Default Value: NIRFSG_VAL_ERROR_REPORTING_WARNING \n\n Supported Devices: PXIe-5644/5645/5646, PXIe-5820/5830/5831/5840/5841 \n \n'
        },
        'enum': 'OverflowErrorReporting',
        'name': 'OVERFLOW_ERROR_REPORTING',
        'type': 'ViInt32'
    },
    1150239: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the size of the DMA buffer in computer memory, in bytes. To  set this attribute, the NI-RFSG device must be in the Configuration state.\n\n large fetches to be transferred more efficiently.\n\n Units: bytes\n Default Value: 8 MB\n Supported Devices: PXIe-5820/5830/5831/5840/5841 \n',
            'note': ' A sufficiently large host DMA buffer improves performance by allowing '
        },
        'name': 'HOST_DMA_BUFFER_SIZE',
        'type': 'ViInt64'
    },
    1150241: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the port to configure. \n\n Valid Values: \n PXIe-5644/5645/5646, PXIe-5820/5840/5841:  (empty string) \n PXIe-5830: if0, if1 \n PXIe-5831: if0, if1, rf<0-1>/port<x>, where 0-1 indicates one (0) or two (1) mmRH-5582 connections  and x is the port number on the mmRH-5582 front panel. \n\n Default Value: \n PXIe-5644/5645/5646, PXIe-5820/5840/5841:  (empty string) \n PXIe-5830/5831: if0 \n Supported Devices: PXIe-5820/5830/5831/5840/5841 \n \n'
        },
        'name': 'SELECTED_PORTS',
        'type': 'ViReal64'
    },
    1150242: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to allow NI-RFSA to control the NI-RFSG LO out export. Set this attribute to NIRFSG_VAL_ENABLE to allow NI-RFSA to control the LO out export.  Use the NIRFSA_ATTR_RF_OUT_LO_EXPORT_ENABLED attribute to control the LO out export from NI-RFSA.\n\n Default Value: NIRFSG_VAL_DISABLE \n\n Supported Devices: PXIe-5840/5841 \n'
        },
        'enum': 'EnableValues',
        'name': 'LO_OUT_EXPORT_CONFIGURE_FROM_RFSA',
        'type': 'ViInt32'
    },
    1150243: {
        'access': 'read-write',
        'enum': 'RfInLoExportEnabled',
        'name': 'RF_IN_LO_EXPORT_ENABLED',
        'type': 'ViInt32'
    },
    1150244: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the temperature change, in degrees Celsius, required before NI-RFSG recalculates the thermal correction settings when entering the Generation state. \n\n Units: degrees C \n\n Supported Devices: PXIe-5830/5831/5840/5841 Default Values: PXIe-5830/5831: 0.2 PXIe-5840/5841: 1.0    '
        },
        'name': 'THERMAL_CORRECTION_TEMPERATURE_RESOLUTION',
        'type': 'ViReal64'
    },
    1150248: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to allow NI-RFSG to select the upconverter frequency offset.  You can either set an offset yourself or let NI-RFSG select one for you. \n\n Placing the upconverter center frequency outside the bandwidth of your input signal can help avoid issues such as LO leakage. \n\n To set an offset yourself, set this attribute to NIRFSG_VAL_AUTOMATIC or NIRFSG_VAL_USER_DEFINED,  and set either the NIRFSG_ATTR_UPCONVERTER_CENTER_FREQUENCY or the NIRFSG_ATTR_UPCONVERTER_FREQUENCY_OFFSET attribute. \n To allow NI-RFSG to automatically select the upconverter frequency offset, set this attribute  to NIRFSG_VAL_AUTOMATIC or NIRFSG_VAL_ENABLED and set the NIRFSG_ATTR_SIGNAL_BANDWIDTH to describe your  expected input signal. Do not set the NIRFSG_ATTR_UPCONVERTER_CENTER_FREQUENCY or NIRFSG_ATTR_UPCONVERTER_FREQUENCY_OFFSET  attributes. If all conditions are met, NI-RFSG places the upconverter center frequency outside the signal  bandwidth if there is sufficient room in the device instantaneous bandwidth to do so. \n Set this attribute to NIRFSG_VAL_ENABLED if you want to receive an error any time NIRFSG  is unable to apply automatic offset. \n When you set an offset yourself or do not use an offset, the reference frequency for gain is  near the upconverter center frequency, and offset mode reads back as NIRFSG_VAL_USER_DEFINED. When NI-RFSG  automatically sets an offset, the reference frequency for gain is the carrier frequency, and offset mode reads back as NIRFSG_VAL_ENABLED. \n \n'
        },
        'enum': 'UpconverterFrequencyOffsetMode',
        'name': 'UPCONVERTER_FREQUENCY_OFFSET_MODE',
        'type': 'ViInt32'
    },
    1150249: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns a comma-separated list of the ports available for use based on your instrument configuration. Supported Devices: PXIe-5644/5645/5646, PXIe-5820/5840/5841, PXIe-5830/5831 \n \n'
        },
        'name': 'AVAILABLE_PORTS',
        'type': 'ViReal64'
    },
    1150251: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns a string containing the name of the FPGA target being used. \n This name can be used with the RIO open session to open a reference to the FPGA. \n This attribute is channel dependent if multiple FPGA targets are supported. \n \n Supported Devices: PXIe-5820/5830/5831/5840/5841 \n \n'
        },
        'name': 'FPGA_TARGET_NAME',
        'type': 'ViString'
    },
    1150252: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the type of de-embedding to apply to measurements on the specified port. To use this attribute, you must use the channelName parameter of the niRFSG_SetAttributeViInt32 function to specify the name of the port to configure for de-embedding. \n\n If you set this attribute to NIRFSG_VAL_DEEMBEDDING_TYPE_SCALAR or NIRFSG_VAL_DEEMBEDDING_TYPE_VECTOR, NI-RFSG adjusts the instrument settings and the returned data to remove the effects of the external network between the instrument and the DUT. \n\n Default Value: NIRFSG_VAL_DEEMBEDDING_TYPE_SCALAR \n\n Valid Values for PXIe-5830/5832/5840/5841: NIRFSG_VAL_DEEMBEDDING_TYPE_SCALAR, NIRFSG_VAL_DEEMBEDDING_TYPE_NONE \n\n Valid Values for PXIe-5831: NIRFSG_VAL_DEEMBEDDING_TYPE_VECTOR, NIRFSG_VAL_DEEMBEDDING_TYPE_SCALAR, or NIRFSG_VAL_DEEMBEDDING_TYPE_NONE. NIRFSG_VAL_DEEMBEDDING_TYPE_VECTOR is only supported for TRX Ports in a Semiconductor Test System (STS).\n\n Supported Devices: PXIe-5830/5831/5832/5840/5841     '
        },
        'enum': 'DeembeddingType',
        'name': 'DEEMBEDDING_TYPE',
        'type': 'ViInt32'
    },
    1150253: {
        'access': 'read-write',
        'documentation': {
            'description': ' Selects the de-embedding table to apply to the measurements on the specified port. To use this attribute, you must use the channelName parameter of the niRFSG_SetAttributeViString function to specify the name of the port to configure for de-embedding. \n\n If de-embedding is enabled, NI-RFSG uses the specified table to remove the effects of the external network between the instrument and the DUT. \n\n Use the niRFSG_CreateDeembeddingSparameterTableArray function to create tables. \n\n Supported Devices: PXIe-5830/5831/5840/5841     '
        },
        'name': 'DEEMBEDDING_SELECTED_TABLE',
        'type': 'ViString'
    },
    1150257: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the step size for tuning the internal voltage-controlled oscillator (VCO) used to generate the LO signal. \n\n Default Value: 1 MHz \n Valid Values: 1 Hz to 50 MHz for LO1 and 1 Hz to 100 MHz for LO2 \n\n \n'
        },
        'name': 'LO_VCO_FREQUENCY_STEP_SIZE',
        'type': 'ViReal64'
    },
    1150258: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the expected thermal operating range of the instrument from the self cal temperature in degrees C, as reported by the Device Temperature property. \n\n For example, if the Thermal Correction Headroom Range property is set to 5.0, and the device is self calibrated at 35 degrees C, \n then you can expect to run the device from 30 degC to 40 degC with corrected accuracy and no overflows. \n Setting this value to a smaller value can result in improved dynamic range, but you must ensure thermal stability while the instrument is running. \n Operating the instrument outside of the specified range may cause degraded performance, or DSP overflows. \n\n Units: degrees C \n\n Supported Devices: PXIe-5830/5831/5840/5841 Default Value (PXIe-5830/5831): 5 \n\n Default Value (PXIe-5840/5841): 10 \n\n    '
        },
        'name': 'THERMAL_CORRECTION_HEADROOM_RANGE',
        'type': 'ViReal64'
    },
    1150263: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the I/Q rate of the waveform. To set this attribute, the NI-RFSG device must be in the Configuration state. \n\n Supported Devices: PXIe-5820/5830/5831/5832/5840/5841\n'
        },
        'name': 'WAVEFORM_IQ_RATE',
        'type': 'ViReal64'
    },
    1150264: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the bandwidth of the arbitrary signal. This value must be less than or equal to (0.8 × I/Q rate). \n\n Supported Devices: PXIe-5820/5830/5831/5832/5840/5841\n'
        },
        'name': 'WAVEFORM_SIGNAL_BANDWIDTH',
        'type': 'ViReal64'
    },
    1150265: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the waveform runtime scaling. The waveform runtime scaling is applied to the waveform data before any other signal processing. \n\n Units: dB\n\n Supported Devices: PXIe-5820/5830/5831/5832/5840/5841\n'
        },
        'name': 'WAVEFORM_RUNTIME_SCALING',
        'type': 'ViReal64'
    },
    1150266: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the peak-to-average power ratio (PAPR). \n\n Supported Devices: PXIe-5820/5830/5831/5832/5840/5841\n'
        },
        'name': 'WAVEFORM_PAPR',
        'type': 'ViReal64'
    },
    1150271: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies a comma-separated list of ports for which to fix the group delay. \n\n Valid Values: \n\n PXIe-5831/5832: rf<0-1>/port<x>, where 0-1 indicates one (0) or two (1) mmRH-5582 connections and x is the port number on the mmRH-5582 front panel. \n\n Default Value:  (empty string) \n\n Supported Devices: PXIe-5831/5832 \n'
        },
        'name': 'FIXED_GROUP_DELAY_ACROSS_PORTS',
        'type': 'ViString'
    },
    1150272: {
        'access': 'read-write',
        'name': 'WAVEFORM_FILEPATH',
        'type': 'ViString'
    },
    1150273: {
        'access': 'read-write',
        'documentation': {
            'description': ' Enables the detection of burst start and burst stop locations in the waveform. Set this attribute to NIRFSG_VAL_ENABLED before writing a waveform to NI-RFSG memory for detecting bursts You can read the detected burst start and burst stop locations using niRFSG_Get_Waveform_Burst_Start_Locations and niRFSG_Get_Waveform_Burst_Stop_Locations functions respectively.\n \n NIRFSG_ATTR_WAVEFORM_RF_BLANKING_ENABLED attribute is enabled, you must set the NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION_ENABLED attribute to NIRFSG_VAL_DISABLE. \n\n Default Value: NIRFSG_VAL_DISABLED\n\n Supported Devices:PXIe-5820/5830/5831/5832/5840/5841\n\n',
            'note': ' When you download a waveform using niRFSG_Read_and_Download_Waveform_From_file_(TDMS) function and if'
        },
        'enum': 'EnableValues',
        'name': 'WRITE_WAVEFORM_BURST_DETECTION',
        'type': 'ViInt32'
    },
    1150274: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the algorithm that NI-RFSG uses to detect the burst start and burst stop locations in the waveform when burst detection is enabled using the NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION_ENABLED attribute. When you set NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION_MODE to NIRFSG_VAL_AUTO, NI-RFSG automatically detects the burst start and burst stop locations by analyzing the waveform. To fine-tune the burst detection process parameters yourself, you can set this attribute to NIRFSG_VAL_MANUAL and specify the burst detection parameters using the NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION_MINIMUM_QUIET_TIME, NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION_POWER_THRESHOLD, NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION_MINIMUM_BURST_TIME attributes. \n\n Default Value: NIRFSG_VAL_AUTO\n\n Supported Devices: PXIe-5820/5830/5831/5832/5840/5841\n\n'
        },
        'enum': 'WriteWaveformBurstDetectionMode',
        'name': 'WRITE_WAVEFORM_BURST_DETECTION_MODE',
        'type': 'ViInt32'
    },
    1150275: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies a time duration for which the signal must be quiet before a valid burst start location or after a valid burst stop location. This attribute is ignored when you disable the NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION_ENABLED attribute or when you set the NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION_MODE attribute to NIRFSG_VAL_AUTO. \n\n The default value of this attribute is 0, which means NI-RFSG does not look for a quiet time before or after detected burst start and stop locations. This attribute is useful for detecting burst locations in signals containing multiple bursts. However, each burst must have large changes in signal power within itself. By configuring the NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION_MINIMUM_QUIET_TIME attribute to a value that is less than or equal to the minimum time between two adjacent bursts in the waveform, you can ensure that the burst start and stop locations are detected at the beginning and end of a burst respectively, rather than at the signal power change within a burst. \n\n Units: seconds(s)\n\n Default Value: 0\n\n Supported Devices: PXIe-5820/5830/5831/5832/5840/5841\n\n'
        },
        'name': 'WRITE_WAVEFORM_BURST_DETECTION_MINIMUM_QUIET_TIME',
        'type': 'ViReal64'
    },
    1150276: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the relative power level at which burst start or stop locations are detected. The threshold is relative to the peak power in the waveform. NI-RFSG detects burst start (or burst stop) locations when the signal exceeds (or falls below) the level specified by this attribute. This attribute is ignored when you disable the NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION_ENABLED attribute or when you set the NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION_MODE attribute to NIRFSG_VAL_AUTO. \n\n Units: dB\n\n Default Value: 0\n\n Supported Devices: PXIe-5820/5830/5831/5832/5840/5841\n'
        },
        'name': 'WRITE_WAVEFORM_BURST_DETECTION_POWER_THRESHOLD',
        'type': 'ViReal64'
    },
    1150277: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the minimum duration of the detected bursts. Any detected burst with a duration smaller than the value of this attribute is ignored by NI-RFSG. This attribute is ignored when you disable the NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION_ENABLED attribute or when you set the NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION_MODE attribute to NIRFSG_VAL_AUTO. \n\n Units: seconds(s)\n\n Default Value: 0\n\n Supported Devices: PXIe-5820/5830/5831/5832/5840/5841\n\n'
        },
        'name': 'WRITE_WAVEFORM_BURST_DETECTION_MINIMUM_BURST_TIME',
        'type': 'ViReal64'
    },
    1150278: {
        'access': 'read-write',
        'documentation': {
            'description': ' Enables or disables RF blanking. \n\n Default Value: NIRFSG_VAL_DISABLED\n\n Supported Devices: PXIe-5820/5830/5831/5832/5840/5841\n'
        },
        'enum': 'EnableValues',
        'name': 'WAVEFORM_RF_BLANKING',
        'type': 'ViInt32'
    },
    1150289: {
        'access': 'read-write',
        'name': 'DEEMBEDDING_COMPENSATION_GAIN',
        'type': 'ViReal64'
    },
    1150290: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the configurations to skip while loading from a file. \n\n Default Value: NIRFSG_VAL_LOAD_CONFIGURATIONS_FROM_FILE_LOAD_OPTIONS_SKIP_NONE\n\n Supported Devices: PXIe-5820/5830/5831/5832/5840/5841\n\n'
        },
        'enum': 'LoadOptions',
        'name': 'LOAD_CONFIGURATIONS_FROM_FILE_LOAD_OPTIONS',
        'type': 'ViInt32'
    },
    1150291: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the configurations to skip to reset while loading from a file. \n\n Default Value: NIRFSG_VAL_LOAD_CONFIGURATIONS_FROM_FILE_RESET_OPTIONS_SKIP_NONE\n\n Supported Devices: PXIe-5820/5830/5831/5832/5840/5841\n\n'
        },
        'enum': 'ResetOptions',
        'name': 'LOAD_CONFIGURATIONS_FROM_FILE_RESET_OPTIONS',
        'type': 'ViInt32'
    },
    1150292: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the Reference Clock Rate, in Hz, of the signal sent to the Reference Clock Export Output Terminal.  To set this attribute, the NI-RFSG device must be in the Configuration state.  Units: hertz (Hz) \n Default Value: 10 MHz  Valid Values:   PXIe-5820/5830/5831/5832/5840/5841: 10 MHz  PXIe-5842: 10 MHz, 100 MHz, 1 GHz  PXIe-5860: 10 MHz, 100 MHz  Supported Devices: PXIe-5820/5830/5831/5832/5840/5841/5842/5860  \n  '
        },
        'name': 'EXPORTED_REF_CLOCK_RATE',
        'type': 'ViReal64'
    },
    1150293: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to perform the normalization on a waveform. \n\n \n\n Default Value: NIRFSG_VAL_DISABLE\n\n Supported Devices: PXIe-5820/5830/5831/5832/5840/5841\n\n',
            'note': ' You can not set NIRFSG_ATTR_WRITE_WAVEFORM_NORMALIZATION and NIRFSG_ATTR_POWER_LEVEL_TYPE attributes at the same time.'
        },
        'enum': 'EnableValues',
        'name': 'WRITE_WAVEFORM_NORMALIZATION',
        'type': 'ViInt32'
    },
    1150297: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the size of the waveform specified by active channel. \n\n Supported Devices: PXIe-5820/5830/5831/5832/5840/5841/5842/5860\n'
        },
        'name': 'WAVEFORM_WAVEFORM_SIZE',
        'type': 'ViInt32'
    },
    1150307: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the active level of the pulse modulation signal when pulse modulation is enabled. \n\n Supported Devices: PXIe-5820/5830/5831/5832/5840/5841/5842/5860\n'
        },
        'name': 'PULSE_MODULATION_ACTIVE_LEVEL',
        'type': 'ViInt32'
    },
    1150308: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the source of the pulse modulation signal. \n\n Supported Devices: PXIe-5820/5830/5831/5832/5840/5841/5842/5860\n'
        },
        'name': 'PULSE_MODULATION_SOURCE',
        'type': 'ViString'
    },
    1150309: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the destination terminal for exporting the Pulse Modulation Event. \n\n Supported Devices: PXIe-5820/5830/5831/5832/5840/5841/5842/5860\n'
        },
        'name': 'EXPORTED_PULSE_MODULATION_EVENT_OUTPUT_TERMINAL',
        'type': 'ViString'
    },
    1150310: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the active level of the exported Pulse Modulation Event. \n\n Supported Devices: PXIe-5820/5830/5831/5832/5840/5841/5842/5860\n'
        },
        'name': 'EXPORTED_PULSE_MODULATION_EVENT_ACTIVE_LEVEL',
        'type': 'ViInt32'
    },
    1150311: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the Selected Path. \n\n Supported Devices: PXIe-5820/5830/5831/5832/5840/5841/5842/5860\n'
        },
        'name': 'SELECTED_PATH',
        'type': 'ViString'
    },
    1150312: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns a comma separated list of the configurable paths available for use based on your instrument configuration. \n\n Supported Devices: PXIe-5820/5830/5831/5832/5840/5841/5842/5860\n'
        },
        'name': 'AVAILABLE_PATHS',
        'type': 'ViString'
    },
    1152832: {
        'access': 'read-write',
        'documentation': {
            'description': ' Enables or disables compensation for filter group delay on the AWG module.  This attribute also accounts for the upconverter group delay and aligns  the RF output with the Started Event, Done Event, and Marker Events.\n \n At a low I/Q rate, the group delay can become so large that some devices  may not be able to align the events with the RF output, in which case  you must increase the I/Q rate or disable this attribute. \n'
        },
        'name': 'COMPENSATE_FOR_FILTER_GROUP_DELAY',
        'type': 'ViBoolean'
    },
    1154097: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the gain the upconverter applies to the signal. \n \n read-only on the PXIe-5644/5645/5646, PXI-5670/5671 PXIe-5672/5673/5673E, PXIe-5820/5830/5831/5840/5841. \n \n Units: dB \n \n',
            'note': ' This attribute is read/write on the PXI-5610 and PXIe-5611 and '
        },
        'name': 'UPCONVERTER_GAIN',
        'type': 'ViReal64'
    },
    1154098: {
        'access': 'read-write',
        'documentation': {
            'description': ' Indicates the center frequency of the passband containing the upconverted  RF signal. Writing a value to this attribute while using the   PXIe-5644/5645/5646/5672/5673/5673E/5820/5840/5841 device enables in-band retuning.   In-band retuning increases the speed of  frequency sweeps by reducing the amount of upconverter retunes. \n \n PXIe-5644/5645/5646, PXIe-5673/5673E, PXIe-5820/5830/5831/5840/5841 and read-only on the PXI-5670/5671.  \n \n \n \n  and PXIe-5820/5830/5831/5840/5841 device is generating has no effect until a dynamic attribute is set. \n \n Units: hertz (Hz) \n \n',
            'note': ' Setting this attribute while the PXIe-5644/5645/5646, PXIe-5673/5673E, '
        },
        'name': 'UPCONVERTER_CENTER_FREQUENCY',
        'type': 'ViReal64'
    },
    1250001: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the frequency of the generated RF signal. For arbitrary waveform  generation, this attribute specifies the center frequency of the signal. \n \n The PXI-5670/5671, PXIe-5672, and PXIe-5820 must be in the Configuration state to use this attribute.  However, the PXIe-5644/5645/5646, PXI/PXIe-5650/5651/5652, PXIe-5653/5673/5673E, PXIe-5830/5831/5840/5841 can be in  the Configuration or the Generation state to use this attribute. \n \n Units: hertz (Hz) \n \n',
            'note': ' For the PXIe-5645, this attribute is ignored if you are using the I/Q ports. \n'
        },
        'name': 'FREQUENCY',
        'type': 'ViReal64'
    },
    1250002: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies either the average power level or peak power level of the  generated RF signal, depending on the NIRFSG_ATTR_POWER_LEVEL_TYPE  attribute setting. average power of the signal or the peak power of the  signal. \n \n The PXI-5670/5671 and PXIe-5672 must be in the Configuration state to use this attribute.  However, the PXIe-5644/5645/5646, PXI/PXIe-5650/5651/5652, PXIe-5654/5654 with PXIe-5696, PXIe-5673/5673E, PXIe-5840/5841  can be in the Configuration or the Generation state to use this attribute. \n \n Refer to the specifications document for your device for allowable  power level settings. \n \n Units: dBm \n \n',
            'note': ' For the PXIe-5645, this attribute is ignored if you are using the I/Q ports. \n'
        },
        'name': 'POWER_LEVEL',
        'type': 'ViReal64'
    },
    1250004: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether signal output is enabled. Setting the  NIRFSG_ATTR_OUTPUT_ENABLED attribute to VI_FALSE while in  the Generation state stops signal output, although generation  continues internally. Setting the NIRFSG_ATTR_OUTPUT_ENABLED  attribute while in the Committed state does not transition the  device to the Configuration state, but output changes immediately. \n \n to a valid list name, setting the NIRFSG_ATTR_OUTPUT_ENABLED  attribute transitions the device to the Configuration state. \n \n',
            'note': ' When the NIRFSG_ATTR_ACTIVE_CONFIGURATION_LIST attribute is set '
        },
        'name': 'OUTPUT_ENABLED',
        'type': 'ViBoolean'
    },
    1250051: {
        'access': 'read-write',
        'documentation': {
            'description': ' Enables or disables pulse modulation. \n \n PXIe-5654/5654 with PXIe-5696: If this attribute is enabled and the signal  at the PULSE IN front panel connector is high, the device generates a signal.  If the signal is low, output generation is disabled. \n \n PXIe-5673/5673E: If this attribute is enabled and the signal at the PLS MOD  front panel connector is high, the device generates a signal.  If the signal is low, output generation is disabled. \n \n'
        },
        'name': 'PULSE_MODULATION_ENABLED',
        'type': 'ViBoolean'
    },
    1250322: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the Reference Clock rate, in Hz, of the signal present at the REF IN or CLK IN connector.  This property is only valid when the NIRFSG_ATTR_REF_CLOCK_SOURCE attribute is set to NIRFSG_VAL_CLK_IN_STR,  NIRFSG_VAL_REF_IN_STR, or NIRFSG_VAL_REF_IN_2_STR.. To set this attribute, the NI-RFSG device  must be in the Configuration state. If you are using the PXIe-5654/5654 with PXIe-5696,  the NI-RFSG device must be in the Committed state to read this attribute.  When you read this attribute, it returns the frequency the device is  locked to during the Committed state.\n \n If you set this attribute to NIRFSG_VAL_AUTO, NI-RFSG uses the default Reference Clock  rate for the device or automatically detects the Reference Clock rate if automatic detection is supported by the device.\n \n For all other supported devices, NI-RFSG uses the default Reference Clock rate of 10 MHz.\n \n PXIe-5654/5654 with PXIe-5696: Values between 1 MHz to 20 MHz in 1 MHz steps are supported in  addition to the NIRFSG_VAL_AUTO and NIRFSG_VAL_10MHZ values.\n PXIe-5841 with PXIe-5655: 10 MHz, 100 MHz, 270 MHz, and 3.84 MHz * y, where y is 4, 8, 16, 24, 25, or 32.\n \n  Units: hertz (Hz) \n \n  ',
            'note': ' Automatic detection of the Reference Clock rate is supported on only the PXIe-5654/5654 with PXIe-5696. '
        },
        'enum': 'RefClockRate',
        'name': 'REF_CLOCK_RATE',
        'type': 'ViReal64'
    },
    1250401: {
        'access': 'read-write',
        'documentation': {
            'description': ' Enables or disables I/Q (vector) modulation of the output signal. Enabling this  attribute is required for generating arbitrary signals. To set this attribute, the NI-RFSG device  must be in the Configuration state. \n This attribute is obsolete and should not be used. \n \n  '
        },
        'name': 'IQ_ENABLED',
        'type': 'ViBoolean'
    },
    1250402: {
        'access': 'read-write',
        'name': 'IQ_NOMINAL_VOLTAGE',
        'type': 'ViReal64'
    },
    1250404: {
        'access': 'read-write',
        'documentation': {
            'description': ' Enables or disables the inverse phase rotation of the I/Q signal by  swapping the I and Q inputs. \n To set this attribute, the NI-RFSG device must  be in the Configuration state.\n \n'
        },
        'name': 'IQ_SWAP_ENABLED',
        'type': 'ViBoolean'
    },
    1250451: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the waveform in onboard memory to generate upon calling  the niRFSG_init function when the NIRFSG_ATTR_GENERATION_MODE  attribute is set to NIRFSG_VAL_ARB_WAVEFORM. The  NIRFSG_ATTR_ARB_SELECTED_WAVEFORM attribute is ignored when  the NIRFSG_ATTR_GENERATION_MODE attribute is set to  NIRFSG_VAL_SCRIPT or NIRFSG_VAL_CW. To set the  NIRFSG_ATTR_ARB_SELECTED_WAVEFORM attribute, the NI-RFSG  device must be in the Configuration state. \n \n'
        },
        'name': 'ARB_SELECTED_WAVEFORM',
        'type': 'ViString'
    },
    1250452: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the I/Q rate of the arbitrary waveform.  The I/Q rate is coerced to a value the hardware can achieve.  Read this value back after setting it to see what the actual  I/Q rate is. NI-RFSG internally uses an FIR filter with flat  response up to (0.4 × IQ rate). Given a desired signal with  the maximum frequency content f, sample the signal at  an I/Q rate greater than or equal to (f/0.4). \n \n This attribute applies only when the NIRFSG_ATTR_GENERATION_MODE  attribute is set to NIRFSG_VAL_ARB_WAVEFORM or NIRFSG_VAL_SCRIPT. \n \n Use this attribute to associate an I/Q rate with a waveform.  Refer to the Assigning Properties or Attributes to a Waveform topic of  the NI RF Signal Generators Help for more information about assigning an I/Q rate to a waveform. \n'
        },
        'name': 'IQ_RATE',
        'type': 'ViReal64'
    },
    1250453: {
        'access': 'read-write',
        'name': 'ARB_FILTER_FREQUENCY',
        'type': 'ViReal64'
    },
    1250454: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the maximum number of waveforms the device can hold in memory. \n \n'
        },
        'name': 'ARB_MAX_NUMBER_WAVEFORMS',
        'type': 'ViInt32'
    },
    1250455: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the waveform quantum for the device. The number of samples  in a waveform must be an integer multiple of the waveform quantum.  The other restrictions on the length of the waveform are the minimum and  maximum arbitrary waveform sizes. On the PXI-5671 and PXIe-5672, the value of this  attribute depends on the I/Q rate. Set the NIRFSG_ATTR_IQ_RATE attribute  before reading this attribute. \n'
        },
        'name': 'ARB_WAVEFORM_QUANTUM',
        'type': 'ViInt32'
    },
    1250456: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the smallest allowable waveform size. For the  PXI-5671 and PXIe-5672, the value of this attribute depends on the I/Q rate.  Set the NIRFSG_ATTR_IQ_RATE attribute before reading this attribute.\n \n Units: Samples \n \n'
        },
        'name': 'ARB_WAVEFORM_SIZE_MIN',
        'type': 'ViInt32'
    },
    1250457: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the size of the largest waveform that is allowed. To read  this attribute, the NI-RFSG device must be in the Configuration state.\n \n For the PXI-5671 and PXIe-5672, the value of this attribute depends on the I/Q rate.  Set the I/Q rate before reading this attribute.  For the PXIe-5673/5673E,  the maximum waveform size is reduced to account for the amount of device  memory currently used. \n \n of onboard memory stores scripts that specify how the waveforms are  generated.  These scripts typically require less than 1 KB of onboard  memory. \n \n',
            'note': ' Not all onboard memory is available for waveform storage. A portion '
        },
        'name': 'ARB_WAVEFORM_SIZE_MAX',
        'type': 'ViInt32'
    },
    1250458: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the Start Trigger type. Depending upon the value of this  attribute, more attributes may be needed to fully configure the trigger.  To set this attribute, the NI-RFSG device must be in the Configuration state.\n \n'
        },
        'enum': 'StartTriggerType',
        'name': 'START_TRIGGER_TYPE',
        'type': 'ViInt32'
    },
    1250459: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the active edge for the Start Trigger. This attribute is used  when the NIRFSG_ATTR_START_TRIGGER_TYPE attribute is set to  NIRFSG_VAL_DIGITAL_EDGE. To set the NIRFSG_ATTR_DIGITAL_EDGE_START_TRIGGER_EDGE  attribute, the NI-RFSG device must be in the Configuration state. \n \n'
        },
        'enum': 'DigitalEdgeEdge',
        'name': 'DIGITAL_EDGE_START_TRIGGER_EDGE',
        'type': 'ViInt32'
    }
}
