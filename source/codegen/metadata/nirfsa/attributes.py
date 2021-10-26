attributes = {
    1050002: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to validate attribute values and function parameters.  If enabled, NI-RFSA validates the parameter values that you  pass to NI-RFSA functions. Range checking parameters is very useful for  debugging. After you validate your program, you can set this attribute to  VI_FALSE to disable range checking and maximize performance.\n\n Default Value: VI_TRUE \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5693/5694/5698, PXIe-5820/5830/5831/5840/5841     ',
            'note': ' Use niRFSA_InitWithOptions function to override this value.\n\n'
        },
        'name': 'RANGE_CHECK',
        'type': 'ViBoolean'
    },
    1050003: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether NI-RFSA queries the NI-RFSA device status after each operation. Querying  the device status is useful for debugging. After you validate your program, you can set  this attribute to VI_FALSE to disable status checking and maximize performance. \n\n NI-RFSA can choose to ignore status checking for  particular attributes, regardless of the setting of this attribute.\n\n Default Value: VI_FALSE  \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5693/5694/5698, PXIe-5820/5830/5831/5840/5841     ',
            'note': ' Use niRFSA_InitWithOptions function to override this value.\n\n'
        },
        'name': 'QUERY_INSTRUMENT_STATUS',
        'type': 'ViBoolean'
    },
    1050004: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to cache the value of attributes. If you set this attribute to VI_TRUE,  NI-RFSA tracks the current NI-RFSA device settings and avoids sending redundant commands  to the device. \n\n NI-RFSA can always cache or never cache  particular attributes, regardless of the setting of this attribute.\n\n Use the niRFSA_InitWithOptions function to override the default value.\n\n Default Value: VI_TRUE  \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5693/5694/5698, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'CACHE',
        'type': 'ViBoolean'
    },
    1050005: {
        'access': 'read only',
        'documentation': {
            'description': ' Specifies whether NI-RFSA simulates I/O operations. This attribute is  useful for debugging applications without using hardware. After a session  is opened, you cannot change the simulation state. Use the niRFSA_InitWithOptions  function to enable simulation.\n\n Default Value: VI_FALSE  \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5693/5694/5698, PXIe-5820/5830/5831/5840/5841     ',
            'note': ' PXI-5600/5661 support setting this attribute to VI_FALSE only. \n\n'
        },
        'name': 'SIMULATE',
        'type': 'ViBoolean'
    },
    1050006: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the IVI engine keeps a list of the value coercions it  makes for integer and real type attributes.\n\n Default Value: VI_FALSE  \n\n Supported Devices: None     ',
            'note': ' This attribute is currently not supported.\n\n'
        },
        'name': 'RECORD_COERCIONS',
        'type': 'ViBoolean'
    },
    1050007: {
        'access': 'read only',
        'documentation': {
            'description': ' The Driver Setup string is used to set the initial values for attributes that  are specific to NI-RFSA. The format of the Driver Setup string is:\n Tag: Value\n Tag is the name of the DriverSetup string attribute. Value is the value set to  the attribute. To set multiple attributes, separate their assignments with a  semicolon.\n\n The DriverSetup string can include the following tags:\n\n PXI-5661, PXIe-5663/5663E/5665/5667-Digitizer-Specifies the resource name of the digitizer to use for  this session. If this Driver Setup tag is not specified, the resource name for the  downconverter associated in MAX is used. An example of a Driver Setup string  is DriverSetup=Digitizer:pxi1slot4. If you want to use the PXI-5600, PXIe-5601/5603 with an  external digitizer, use the following Driver Setup tag:  DriverSetup=Digitizer:<external>.\n\n PXIe-5663/5663E/5665/5667-LO-Specifies the resource name of the LO source to use for this  session. If you want to use the PXIe-5601 with an LO other than the PXI/PXIe-5652 or use the  5603 with an LO other than the 5653, use the following Driver Setup  tag: DriverSetup=LO:<external>.\n\n 5667—RFConditioning—Specifies the resource name of the RF Conditioning source to use for this session. \n\n 5667—IFConditioning—Specifies the resource name of the IF Conditioning source to use for this session. \n\n Refer to the niRFSA_InitWithOptions function for additional information about the  optionString parameter. Refer to the getting started guide for your device for information  about configuring your device in MAX. \n\n Default Value:  (empty string) \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5698, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'DRIVER_SETUP',
        'type': 'ViString'
    },
    1050021: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to perform interchangeability checking and retrieve  interchangeability warnings.\n\n Default Value: VI_FALSE  \n\n Supported Devices: None      ',
            'note': ' Interchangeability check is unsupported.\n\n'
        },
        'name': 'INTERCHANGE_CHECK',
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
            'description': ' Returns a string that contains the prefix for NI-RFSA. The name of each user-callable  function in NI-RFSA starts with this prefix. This attribute returns niRFSA. \n\n Default Value: N/A  \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5693/5694/5698, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'SPECIFIC_DRIVER_PREFIX',
        'type': 'ViString'
    },
    1050304: {
        'access': 'read only',
        'documentation': {
            'description': ' Indicates the resource descriptor NI-RFSA uses to identify the physical device.  If you initialize NI-RFSA with a logical name, this attribute contains the resource  name that corresponds to the entry in the IVI Configuration Utility. \n\n If you initialize NI-RFSA with the resource name, this attribute  contains that value.\n\n Default Value: N/A  \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5693/5694/5698, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'IO_RESOURCE_DESCRIPTOR',
        'type': 'ViString'
    },
    1050305: {
        'access': 'read only',
        'documentation': {
            'description': ' Contains the logical name you specified when opening the current IVI session. You may pass  a logical name to the niRFSA_init function or the niRFSA_InitWithOptions function.  The IVI Configuration Utility must contain an entry for the logical name. The logical name  entry refers to a driver session section in the IVI Configuration file. The driver  session section specifies a physical device and initial user options. \n\n Default Value: N/A \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5693/5694/5698, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'LOGICAL_NAME',
        'type': 'ViString'
    },
    1050327: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns a comma-separated list of supported devices.\n\n Default Value: N/A \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5693/5694/5698, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'SUPPORTED_INSTRUMENT_MODELS',
        'type': 'ViString'
    },
    1050401: {
        'access': 'read-write',
        'name': 'GROUP_CAPABILITIES',
        'type': 'ViString'
    },
    1050510: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns a string that contains the firmware revision information for the  NI-RFSA device you are currently using.\n\n Default Value: N/A \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5693/5694/5698, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'INSTRUMENT_FIRMWARE_REVISION',
        'type': 'ViString'
    },
    1050511: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns a string that contains the name of the manufacturer for the NI-RFSA device you are  currently using.\n\n Default Value: N/A  \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5693/5694/5698, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'INSTRUMENT_MANUFACTURER',
        'type': 'ViString'
    },
    1050512: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns a string that contains the model number or name of the NI-RFSA  device that you are currently using.\n\n Default Value: N/A  \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5693/5694/5698, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'INSTRUMENT_MODEL',
        'type': 'ViString'
    },
    1050513: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns a string that contains the name of the vendor that supplies NI-RFSA.  This attribute returns National Instruments. \n\n Default Value: N/A \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5693/5694/5698, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'SPECIFIC_DRIVER_VENDOR',
        'type': 'ViString'
    },
    1050514: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns a string that contains a brief description of NI-RFSA. This attribute returns  RF Signal Analyzer Instrument Driver. \n\n Default Value: N/A \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5693/5694/5698, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'SPECIFIC_DRIVER_DESCRIPTION',
        'type': 'ViString'
    },
    1050515: {
        'access': 'read-write',
        'name': 'SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION',
        'type': 'ViInt32'
    },
    1050516: {
        'access': 'read-write',
        'name': 'SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION',
        'type': 'ViInt32'
    },
    1050551: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns a string that contains additional version information about NI-RFSA.  For example, NI-RFSA can return Driver: NI-RFSA 2.6, Compiler: MSVC 7.10,  Components: IVI Engine 4.00, VISA-Spec 4.00 as the value of this attribute. \n\n Default Value: N/A  \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5693/5694/5698, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'SPECIFIC_DRIVER_REVISION',
        'type': 'ViString'
    },
    1150001: {
        'access': 'read-write',
        'documentation': {
            'description': ' Configures the session to either acquire I/Q data or to compute a power  spectrum over the specified frequency range.\n\n Default Value: NIRFSA_VAL_IQ \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'enum': 'AcquisitionType',
        'name': 'ACQUISITION_TYPE',
        'type': 'ViInt32'
    },
    1150002: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the center frequency in a spectrum acquisition.  An acquisition consists of a span of data surrounding  the center frequency.  The value is expressed in hertz (Hz).\n\n  Units: hertz (Hz) \n\n Default Values: \n\n PXIe-5694: 193.6 MHz \n\n PXIe-5820: 0 Hz \n\n PXIe-5830/5831: 6.5 GHz \n\n All other devices: 1 GHz \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5644/5645/5646,  PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5693/5694/5698, PXIe-5820/5830/5831/5840/5841     ',
            'note': ' Use this attribute to tune the downconverter when using external digitizer mode. \n\n'
        },
        'name': 'CENTER_FREQUENCY',
        'type': 'ViReal64'
    },
    1150003: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the frequency range of the computed spectrum, in hertz (Hz).  For example, if you specify a center frequency of 1 GHz and a span of 100 MHz,  the spectrum ranges from 950 MHz to 1,050 MHz after zoom processing. This value  may be coerced based on hardware settings and RF downconverter specifications. \n\n NI-RFSA performs multispan acquisitions by dividing the total requested span into equally  sized subspans based on the device instantaneous bandwidth at the range of frequencies you  specify. NI-RFSA combines these subspans to yield a multispan acquisition. You can use the  NIRFSA_ATTR_FFT_WIDTH attribute to improve amplitude accuracy and avoid unwanted effects  such as filter roll-off and spurs across the span you select.\n\n instantaneous bandwidth, NI-RFSA performs multiple acquisitions and combines  them into a spectrum of the size you requested. \n\n At spans wider than 40 MHz,  the dither noise can leak into the lower frequencies and the upper frequencies  of the IF pass band.  The amount of leakage depends on the resolution bandwidth, resolution bandwidth type,  and FFT window  you select. Refer to the NIRFSA_ATTR_DIGITIZER_DITHER_ENABLED attribute for more  information about dithering. \n\n PXIe-5663/5663E-NI-RFSA does not support multispan acquisitions from frequency  ranges that correspond with different instantaneous bandwidths. For example, you cannot configure  a multispan acquisition that acquires one span from 110 MHz to 120 MHz and a  second from 120 MHz to  130 MHz  because the instantaneous bandwidth for frequencies above 120 MHz is different  than instantaneous bandwidth for frequencies less than 120 MHz, which are 20 MHz and 10 MHz respectively.\n\n PXIe-5665 (14 GHz)/5667 (7 GHz)-If you enable the downconverter preselector, the device instantaneous bandwidth is only a  typical specification. \n\n Default Value: 10 MHz  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5840/5841     ',
            'note': ' For the PXIe-5663/5663E/5665/5667/5668, NI-RFSA enables dithering by default. '
        },
        'name': 'SPECTRUM_SPAN',
        'type': 'ViReal64'
    },
    1150004: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the reference level, in dBm. The reference level represents the maximum expected power of an RF input signal. \n\n Refer to the NIRFSA_ATTR_REFERENCE_LEVEL_HEADROOM attribute for information about margin that NI-RFSA adds.  Refer to the NIRFSA_ATTR_EXTERNAL_GAIN attribute for information about how configuring  an external gain and a reference level affect attenuation. \n\n Default Value: 0 \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5644/5645/5646, PXI-5661,  PXIe-5663/5663E/5665/5667/5668, PXIe-5693/5694, PXIe-5830/5831/5840/5841     ',
            'note': ' For the PXIe-5645, this attribute is ignored if you are using the I/Q ports. \n\n'
        },
        'name': 'REFERENCE_LEVEL',
        'type': 'ViReal64'
    },
    1150005: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the nominal attenuation setting, in dB, for all  attenuators before the first mixer in the RF signal chain.  If you do not set this attribute, NI-RFSA automatically chooses  an attenuation setting based on the reference level you configure.  The valid values for this attribute depend on the device configuration. \n\n PXI-5600/5661-You can change the attenuation value to modify the amount of noise and distortion.  Higher attenuation levels increase the noise level while decreasing distortion; lower  attenuation levels  decrease the noise level while increasing distortion.\n\n PXIe-5601/5663/5663E-You can change the attenuation value  to modify the amount of noise and distortion. Higher attenuation  levels increase the noise level while decreasing distortion; lower attenuation levels  decrease the noise  level while increasing distortion.\n\n PXIe-5603/5605/5606/5665/5668-You can set multiple attributes to modify the attenuation values for the device.  Refer to PXIe-5665 RF Attenuation and Signal Levels for more information about  configuring attenuation. \n\n  PXIe-5667-This attribute specifies the nominal attenuation setting for all attenuators before the first  RF mixer in the input signal path. This attribute is read-only when the NIRFSA_ATTR_LOW_FREQUENCY_BYPASS_ENABLED  attribute is set to NIRFSA_VAL_DISABLED. \n\n PXIe-5693—This attribute is read-only and returns the nominal RF attenuation of the PXIe-5693. \n\n Units: dB \n\n Default Value: N/A  \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXI-5661,  PXIe-5663/5663E/5665/5667/5668, PXIe-5693     '
        },
        'name': 'ATTENUATION',
        'type': 'ViReal64'
    },
    1150006: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the mixer level, in dBm. The mixer level represents the attenuation value to apply to  the input RF signal as it reaches the first mixer in the signal chain.  If you do not set this attribute, NI-RFSA automatically selects an optimal mixer level value based  on the reference level. The valid values for this attribute depend on your device configuration. \n If you set the NIRFSA_ATTR_MIXER_LEVEL and NIRFSA_ATTR_MIXER_LEVEL_OFFSET attributes at the same time,  NI-RFSA returns an error. \n\n Default Values: \n PXI-5600/5661: -30 \n PXIe-5601: N/A \n PXIe-5603/5605/5665/5667: -10 \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXI-5661, PXIe-5663/5663E/5665/5667/5668     ',
            'note': ' This attribute is read-only for the PXIe-5667 when the NIRFSA_ATTR_LOW_FREQUENCY_BYPASS_ENABLED attribute is set to NIRFSA_VAL_DISABLED. \n\n'
        },
        'name': 'MIXER_LEVEL',
        'type': 'ViReal64'
    },
    1150007: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the I/Q rate for the acquisition The value is expressed in samples per second (S/s). \n\n Refer to the NIRFSA_ATTR_DEVICE_INSTANTANEOUS_BANDWIDTH attribute for more information about device specific instantaneous  bandwidth limits. You can also refer to the NI PXIe-5665 Specifications for more information about instantaneous bandwidth device specifications.\n\n phase coherency performance and leak into the lower frequencies and the upper frequencies of the IF passband.  Refer to the NIRFSA_ATTR_DIGITIZER_DITHER_ENABLED attribute for more information about dithering. \n For the PXIe-5663/5663E/5665/5667, when you set the NIRFSA_ATTR_DIGITIZER_SAMPLE_CLOCK_TIMEBASE_SOURCE attribute  to NIRFSA_VAL_ONBOARD_CLOCK_STR, the downconverter instantaneous bandwidth is greater than or equal to the  coerced I/Q rate times 0.8. For the PXIe-5665, the actual signal bandwidth is further limited by the combination of the  chosen IF filter and anti-aliasing filter.\n\n PXI-5661-You should not need to configure an I/Q rate higher than 25 megasamples per second (MS/s) because  the PXI-5600 RF downconverter bandwidth is 20 MHz. If you configure a higher I/Q rate, you may see aliasing  effects at negative frequencies because the IF frequency of the PXI-5600 is 15 MHz.\n\n PXIe-5663/5663E-Your maximum allowed instantaneous bandwidth depends on the I/Q carrier frequency you use.  Refer to the PXIe-5601 RF downconverter overview for more information about instantaneous bandwidth. \n\n PXIe-5665-Your maximum allowed instantaneous bandwidth depends on the downconverter center frequency if you have enabled the preselector (YIG-tuned filter). \n\n PXIe-5667—Your maximum allowed instantaneous bandwidth depends on the selected RF preselector filter and whether the preselector on the RF dowconverter is enabled. \n\n PXIe-5668-Your maximum allowed instantaneous bandwidth depends on the downconverter center frequency you use and  whether or not you enable the highpass filter or preselector (YIG-tuned filter). \n\n Units: S/s \n\n Default Value: 1 MHz  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     ',
            'note': ' For the PXIe-5663/5663E/5665/5667/5668, NI-RFSA enables dithering by default. At I/Q rates above 50 MS/s, the dither noise can affect '
        },
        'name': 'IQ_RATE',
        'type': 'ViReal64'
    },
    1150008: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the device acquires a finite number of samples or acquires continuously. Default Value: VI_TRUE  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'NUMBER_OF_SAMPLES_IS_FINITE',
        'type': 'ViBoolean'
    },
    1150009: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of samples to acquire. This attribute is only valid if the  NIRFSA_ATTR_NUM_SAMPLES_IS_FINITE attribute is set to VI_TRUE. \n\n This attribute is supported in RF list mode. You can use this attribute in RF list mode to acquire  variable length records when using the NIRFSA_ATTR_CONTIGUOUS_MULTIRECORD attribute. \n\n Default Value: 1,000  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'NUMBER_OF_SAMPLES',
        'type': 'ViInt64'
    },
    1150010: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the device stops after acquiring the specified number of records or acquires records continuously. \n\n Default Value: VI_TRUE \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'NUMBER_OF_RECORDS_IS_FINITE',
        'type': 'ViBoolean'
    },
    1150011: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of records to acquire if the  NIRFSA_ATTR_NUM_RECORDS_IS_FINITE attribute is set to VI_TRUE. Default Value: 1 \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'NUMBER_OF_RECORDS',
        'type': 'ViInt64'
    },
    1150012: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the units of the power spectrum. \n\n Default Value: NIRFSA_VAL_DBM  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'enum': 'PowerSpectrumUnits',
        'name': 'POWER_SPECTRUM_UNITS',
        'type': 'ViInt32'
    },
    1150013: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the resolution along the x-axis of the spectrum.  NI-RFSA uses the resolution bandwidth value to determine the acquisition size. If the  NIRFSA_ATTR_NUMBER_OF_SPECTRAL_LINES attribute is specified, that value overrides  this value. \n\n Units: hertz (Hz) \n\n Default Value: 100 kHz  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'RESOLUTION_BANDWIDTH',
        'type': 'ViReal64'
    },
    1150014: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies how the NIRFSA_ATTR_RESOLUTION_BANDWIDTH attribute is expressed. \n\n Default Value: NIRFSA_VAL_RBW_3DB \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'enum': 'BandwidthType',
        'name': 'RESOLUTION_BANDWIDTH_TYPE',
        'type': 'ViInt32'
    },
    1150015: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of acquisitions to average.  The averaging process returns the final result after the number  of averages is complete.\n\n Default Value: 10  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'SPECTRUM_NUMBER_OF_AVERAGES',
        'type': 'ViInt32'
    },
    1150016: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the averaging mode for the spectrum acquisition. \n\n Default Value: NIRFSA_VAL_NO_AVERAGING  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'enum': 'AveragingMode',
        'name': 'SPECTRUM_AVERAGING_MODE',
        'type': 'ViInt32'
    },
    1150017: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the time-domain window type. \n\n Default Values: \n\n PXI-5661, PXIe-5663/5663E/5665/5668, PXIe-5644/5645/5646, PXIe-5820/5830/5831/5840/5841: NIRFSA_VAL_7_TERM_BLACKMAN_HARRIS \n\n PXIe-5667: NIRFSA_VAL_4_TERM_BLACKMAN_HARRIS \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'enum': 'FftWindowType',
        'name': 'FFT_WINDOW_TYPE',
        'type': 'ViInt32'
    },
    1150018: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of spectral lines expected with the current power spectrum configuration.  If you do not configure this attribute, NI-RFSA selects an appropriate value based on  the NIRFSA_ATTR_RESOLUTION_BANDWIDTH attribute. If you configure this attribute,  NI-RFSA coerces the NIRFSA_ATTR_RESOLUTION_BANDWIDTH value based on the number of  spectral lines requested and the value of the NIRFSA_ATTR_SPECTRUM_SPAN attribute. \n\n Default Value: N/A  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'NUMBER_OF_SPECTRAL_LINES',
        'type': 'ViInt32'
    },
    1150019: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the Reference clock source. \n\n Default Values: \n\n PXIe-5694: NIRFSA_VAL_REF_IN_STR \n\n PXIe-5840 with PXIe-5653: NIRFSA_VAL_REF_IN_2_STR \n\n All other devices: NIRFSA_VAL_ONBOARD_CLOCK_STR \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5694, PXIe-5820/5830/5831/5840/5841     ',
            'note': ' For the PXIe-5694, if your application requires an external LO source, set this property to NIRFSA_VAL_NONE_STR. \n\n'
        },
        'enum': 'RefClockSource',
        'name': 'REF_CLOCK_SOURCE',
        'type': 'ViString'
    },
    1150020: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the Reference clock rate, in hertz (Hz), of the signal present at the REF IN or CLK IN connector.  This attribute is only valid when the NIRFSA_ATTR_REF_CLOCK_SOURCE attribute is set to  NIRFSA_VAL_CLK_IN_STR, NIRFSA_VAL_REF_IN_STR, or NIRFSA_VAL_REF_IN_2_STR. \n\n Valid Values: \n PXIe-5644/5645/5646, PXIe-5601/5663/5663E, PXIe-5694, PXIe-5820/5830/5831/5840/5841: 10 MHz \n PXIe-5603/5605/5665/5667/5668: 5 MHz to 100 MHz, in increments of 1 MHz \n PXIe-5841 with PXIe-5655: 10 MHz, 100 MHz, 270 MHz, and 3.84 MHz * y, where y is 4, 8, 16, 24, 25, or 32. \n\n Default Value: 10 MHz  \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5644/5645/5646,  PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'REF_CLOCK_RATE',
        'type': 'ViReal64'
    },
    1150021: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the source of the Sample clock timebase, which is the timebase used  to control waveform sampling.\n\n Default Value: NIRFSA_VAL_ONBOARD_CLOCK_STR  \n\n Supported Devices: PXI-5661, PXIe-5663/5663E/5665/5667/5668     '
        },
        'enum': 'DigitizerSampleClockTimebaseSource',
        'name': 'DIGITIZER_SAMPLE_CLOCK_TIMEBASE_SOURCE',
        'type': 'ViString'
    },
    1150022: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the frequency, in hertz (Hz), of the external clock used as the timebase  source if you set the NIRFSA_ATTR_DIGITIZER_SAMPLE_CLOCK_TIMEBASE_SOURCE attribute  to an external source, such as NIRFSA_VAL_CLK_IN_STR or NIRFSA_VAL_LO_REF_CLK_STR. \n\n PXI-5661-If this attribute is set to a value less than 60 MHz, signals at frequencies  just above the 20 MHz passband of the downconverter may be aliased back into the  passband. This aliasing occurs because the IF frequency of the downconverter is 15 MHz,  and the upper end of the passband is 25 MHz. At sampling rates below 60 MHz, the  Nyquist frequency is close to the end of the passband and creates aliases that are  not filtered effectively by the downconverter.\n\n PXIe-5663/5663E/5665/5667-The PXIe-5663/5663E/5665/5667 supports only a 150 MHz external clock. \n\n PXIe-5668-The PXIe-5668 supports only a 2 GHz external clock. \n\n Units: hertz (Hz) \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668     '
        },
        'name': 'DIGITIZER_SAMPLE_CLOCK_TIMEBASE_RATE',
        'type': 'ViReal64'
    },
    1150023: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the signal to drive the 10 MHz Reference clock on the PXI  backplane. This option can be configured only when the PXI-5600 is installed in  Slot 2 of the PXI chassis. \n\n Default Value: N/A \n\n Supported Devices: PXI-5600 (external digitizer mode), PXI-5661     '
        },
        'enum': 'PxiChassisClk10Source',
        'name': 'PXI_CHASSIS_CLK10_SOURCE',
        'type': 'ViString'
    },
    1150024: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether you want the Start trigger to be a digital edge or  software trigger.\n\n attribute to NIRFSA_VAL_SPECTRUM or if you set the acquisitionType parameter to NIRFSA_VAL_SPECTRUM  using the cviniRFSA_ConfigureAcquisitionType function.\n\n Default Value: NIRFSA_VAL_NONE  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     ',
            'note': ' Set this property to NIRFSA_VAL_NONE if you set the NIRFSA_ATTR_ACQUISITION_TYPE '
        },
        'enum': 'GeneralTriggerType',
        'name': 'START_TRIGGER_TYPE',
        'type': 'ViInt32'
    },
    1150025: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the source terminal for the Start trigger. This attribute is used  only when the NIRFSA_ATTR_START_TRIGGER_TYPE attribute is set to  NIRFSA_VAL_DIGITAL_EDGE.\n\n Default Value:  (empty string)  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'enum': 'TriggerSource',
        'name': 'DIGITAL_EDGE_START_TRIGGER_SOURCE',
        'type': 'ViString'
    },
    1150026: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the active edge for the Start trigger. This attribute is used only  when NIRFSA_ATTR_START_TRIGGER_TYPE is set to NIRFSA_VAL_DIGITAL_EDGE. \n\n Default Value: NIRFSA_VAL_RISING_EDGE \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5840/5841     '
        },
        'enum': 'DigitalEdge',
        'name': 'DIGITAL_EDGE_START_TRIGGER_EDGE',
        'type': 'ViInt32'
    },
    1150027: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the destination terminal for the exported Start trigger.\n\n Default Value:  (empty string)  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'enum': 'ExportTerminal',
        'name': 'EXPORTED_START_TRIGGER_OUTPUT_TERMINAL',
        'type': 'ViString'
    },
    1150028: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether you want the Reference trigger to be a digital edge, I/Q  power edge, or software trigger. \n\n attribute to NIRFSA_VAL_SPECTRUM or if you set the acquisitionType parameter to NIRFSA_VAL_SPECTRUM  using the cviniRFSA_ConfigureAcquisitionType function.\n\n Default Value: NIRFSA_VAL_NONE  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5840/5841     ',
            'note': ' Set this property to NIRFSA_VAL_NONE if you set the NIRFSA_ATTR_ACQUISITION_TYPE '
        },
        'enum': 'RefTriggerType',
        'name': 'REF_TRIGGER_TYPE',
        'type': 'ViInt32'
    },
    1150029: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the source terminal for the digital edge Reference trigger. This  attribute is used only when the NIRFSA_ATTR_REF_TRIGGER_TYPE attribute is set  to NIRFSA_VAL_DIGITAL_EDGE. \n\n Default Value:  (empty string)  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'enum': 'TriggerSource',
        'name': 'DIGITAL_EDGE_REF_TRIGGER_SOURCE',
        'type': 'ViString'
    },
    1150030: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the active edge for the Reference trigger. This attribute is used only  when the NIRFSA_ATTR_REF_TRIGGER_TYPE attribute is set to  NIRFSA_VAL_DIGITAL_EDGE. Default Value: NIRFSA_VAL_RISING_EDGE  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'enum': 'DigitalEdge',
        'name': 'DIGITAL_EDGE_REF_TRIGGER_EDGE',
        'type': 'ViInt32'
    },
    1150032: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the destination terminal for the exported Reference trigger. \n\n Default Value:  (empty string) \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'enum': 'ExportTerminal',
        'name': 'EXPORTED_REF_TRIGGER_OUTPUT_TERMINAL',
        'type': 'ViString'
    },
    1150033: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the minimum time, in seconds, that must elapse after the Start trigger is  received before the device recognizes a Reference trigger. \n\n Units: seconds \n\n Default Value: 0 \n\n Supported Devices: PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'START_TO_REF_TRIGGER_HOLDOFF',
        'type': 'ViReal64'
    },
    1150034: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the minimum time, in seconds, that must elapse between Reference triggers of  two records. The device does not recognize the Reference trigger of the next record  before this minimum time elapses. \n\n Units: seconds \n\n Default Value: 0 \n\n Supported Devices: PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'REF_TO_REF_TRIGGER_HOLDOFF',
        'type': 'ViReal64'
    },
    1150035: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of pretrigger samples--the samples acquired before the  Reference trigger is received--to be acquired per record. \n\n Default Value: 0 \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'REF_TRIGGER_PRETRIGGER_SAMPLES',
        'type': 'ViInt64'
    },
    1150036: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether you want the Advance trigger to be a digital edge or  software trigger. \n\n attribute to NIRFSA_VAL_SPECTRUM or if you set the acquisitionType parameter to NIRFSA_VAL_SPECTRUM  using the niRFSA_ConfigureAcquisitionType function.\n\n Default Value: NIRFSA_VAL_NONE  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     ',
            'note': ' Set this property to NIRFSA_VAL_NONE if you set the NIRFSA_ATTR_ACQUISITION_TYPE '
        },
        'enum': 'GeneralTriggerType',
        'name': 'ADVANCE_TRIGGER_TYPE',
        'type': 'ViInt32'
    },
    1150037: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the source terminal for the Advance trigger. This attribute is used  only when the NIRFSA_ATTR_ADVANCE_TRIGGER_TYPE attribute is set to  NIRFSA_VAL_DIGITAL_EDGE. \n\n Default Value:  (empty string)  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'enum': 'TriggerSource',
        'name': 'DIGITAL_EDGE_ADVANCE_TRIGGER_SOURCE',
        'type': 'ViString'
    },
    1150038: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the destination terminal for the exported Advance trigger. \n\n Default Value:  (empty string)  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'enum': 'ExportTerminal',
        'name': 'EXPORTED_ADVANCE_TRIGGER_OUTPUT_TERMINAL',
        'type': 'ViString'
    },
    1150039: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether you want the Arm Reference trigger to be a digital edge or software trigger. \n\n attribute to NIRFSA_VAL_SPECTRUM or if you set the acquisitionType parameter to NIRFSA_VAL_SPECTRUM  using the niRFSA_ConfigureAcquisitionType function.\n\n Default Value: NIRFSA_VAL_NONE  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     ',
            'note': ' Set this property to NIRFSA_VAL_NONE if you set the NIRFSA_ATTR_ACQUISITION_TYPE '
        },
        'enum': 'GeneralTriggerType',
        'name': 'ARM_REF_TRIGGER_TYPE',
        'type': 'ViInt32'
    },
    1150040: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the source terminal for the digital edge Arm Reference trigger. This attribute  is used only when the NIRFSA_ATTR_ARM_REF_TRIGGER_TYPE attribute  is set to NIRFSA_VAL_DIGITAL_EDGE. \n\n Default Value:  (empty string) \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667, PXIe-5820/5830/5831/5840/5841     ',
            'note': ' The PXIe-5644/5645/5646 and PXIe-5820/5830/5831/5840/5841 devices only support  (empty string). \n\n'
        },
        'enum': 'TriggerSource',
        'name': 'DIGITAL_EDGE_ARM_REF_TRIGGER_SOURCE',
        'type': 'ViString'
    },
    1150041: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the destination terminal for the Ready for Start event. \n\n Default Value:  (empty string) \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'enum': 'ExportTerminal',
        'name': 'EXPORTED_READY_FOR_START_EVENT_OUTPUT_TERMINAL',
        'type': 'ViString'
    },
    1150042: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the destination terminal for the Ready for Advance event. \n\n Default Value:  (empty string) \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'enum': 'ExportTerminal',
        'name': 'EXPORTED_READY_FOR_ADVANCE_EVENT_OUTPUT_TERMINAL',
        'type': 'ViString'
    },
    1150043: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the destination terminal for the Ready for Reference event. \n\n Default Value:  (empty string) \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'enum': 'ExportTerminal',
        'name': 'EXPORTED_READY_FOR_REF_EVENT_OUTPUT_TERMINAL',
        'type': 'ViString'
    },
    1150044: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the destination terminal for the End of Record event. \n\n Default Value:  (empty string)  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'enum': 'ExportTerminal',
        'name': 'EXPORTED_END_OF_RECORD_EVENT_OUTPUT_TERMINAL',
        'type': 'ViString'
    },
    1150045: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the reference location within the acquired record from which to  begin fetching. \n\n  Default Value: N/A  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'enum': 'FetchRelativeTo',
        'name': 'FETCH_RELATIVE_TO',
        'type': 'ViInt32'
    },
    1150046: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the offset relative to the position specified by the  NIRFSA_ATTR_FETCH_RELATIVE_TO attribute from which to start fetching data.  Offset can be a positive or negative value. \n\n Default Value: 0 \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'FETCH_OFFSET',
        'type': 'ViInt64'
    },
    1150047: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the number of records the RF vector signal analyzer has acquired. \n\n Default Value: N/A  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'RECORDS_DONE',
        'type': 'ViInt32'
    },
    1150048: {
        'access': 'read-write',
        'documentation': {
            'description': ' Enables use of the digital equalization filter for the RF downconverter.\n PXIe-5820/5830/5831/5840/5841-The only valid value for this attribute is VI_TRUE. \n\n cannot set this attribute  to VI_TRUE if the NIRFSA_ATTR_DIGITIZER_SAMPLE_CLOCK_TIMEBASE_SOURCE attribute  is set to NIRFSA_VAL_LO_REF_CLK_STR.\n\n parameter to NIRFSA_VAL_SPECTRUM using the niRFSA_ConfigureAcquisitionType function.  If you set acquisitionType to NIRFSA_VAL_IQ, digital IF equalization is enabled for  instantaneous bandwidths larger than 300 kHz (PXIe-5665) or 20 MHz (PXIe-5667).  You cannot perform digital IF equalization for instantaneous bandwidths less than or  equal to 300 kHz (PXIe-5665) or 20 MHz (PXIe-5667).\n\n so NI-RFSA does not equalize the preselector distortions.\n\n Default Value: VI_TRUE, if the device configuration is supported. \n\n Supported Devices: PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     ',
            'note': ' For the PXIe-5665 (14 GHz))/5667 (7 GHz)  device, the preselector is not part of the IF filter path, '
        },
        'name': 'DIGITAL_IF_EQUALIZATION_ENABLED',
        'type': 'ViBoolean'
    },
    1150049: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the size of the window used in the fast Fourier transform (FFT), in terms of the number of samples in the window. \n\n Default Value: N/A \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'FFT_WINDOW_SIZE',
        'type': 'ViInt32'
    },
    1150050: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the size of the fast Fourier transform (FFT). \n\n Default Value: N/A  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'FFT_SIZE',
        'type': 'ViInt32'
    },
    1150051: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the current temperature, in degrees Celsius, of the module. \n\n PXIe-5644/5645/5646, PXIe-5820/5840/5841: If you query this attribute during RF list mode, list steps may take longer to complete during list execution. \n PXIe-5830/5831: To use this attribute, you must first set the channelName parameter of the niRFSA_SetAttributeViReal64 function  using the appropriate string for your instrument configuration. Setting the niRFSA_SetAttributeViReal64 attribute is not required for the PXIe-3621/3622.  Refer to the NI-RFSA C Function Reference for more inforamation about the appropriate string to use for your hardware configuration. \n\n Units: degrees C \n\n Default Value: N/A \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5693/5694/5698, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'DEVICE_TEMPERATURE',
        'type': 'ViReal64'
    },
    1150053: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the serial number of the RF downconverter module. \n\n For the PXIe-5830/5831, this attribute returns the serial number of the PXIe-3621/3622. \n\n Default Value: N/A  \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5693/5694/5698, PXIe-5820/5830/5831/5840/5841     ',
            'note': ' For the PXIe-5644/5645/5646 and PXIe-5820/5840/5841, this attribute returns the serial number of the VST module.'
        },
        'name': 'SERIAL_NUMBER',
        'type': 'ViString'
    },
    1150054: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the destination terminal for the Done event. \n\n Default Value:  (empty string)  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'enum': 'ExportTerminal',
        'name': 'EXPORTED_DONE_EVENT_OUTPUT_TERMINAL',
        'type': 'ViString'
    },
    1150055: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the channel from which the device monitors the trigger. NI-RFSA  currently supports only 0  as the value of this attribute. \n\n Default Value:  (empty string) \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'IQ_POWER_EDGE_REF_TRIGGER_SOURCE',
        'type': 'ViString'
    },
    1150056: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the power level, in dBm, at which the device triggers. The device  asserts the trigger when the signal crosses the level specified by the value  of this attribute, taking into consideration the specified slope. If you are  using external gain, refer to the NIRFSA_ATTR_EXTERNAL_GAIN attribute for more information  about how this attribute affects the I/Q power edge trigger level. \n\n Default Value: 0 \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5840/5841     '
        },
        'name': 'IQ_POWER_EDGE_REF_TRIGGER_LEVEL',
        'type': 'ViReal64'
    },
    1150057: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the device asserts the trigger when the signal power is rising or  falling. When you set the NIRFSA_ATTR_REF_TRIGGER_TYPE attribute to  NIRFSA_VAL_IQ_POWER_EDGE, the device asserts the trigger when the signal power exceeds  the specified level with the slope you specify. \n\n Default Value: NIRFSA_VAL_RISING_SLOPE \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'enum': 'AnalogSlope',
        'name': 'IQ_POWER_EDGE_REF_TRIGGER_SLOPE',
        'type': 'ViInt32'
    },
    1150058: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies a time duration, in seconds, for which the signal must be quiet  before the device arms the trigger. The signal is quiet when it is below the  trigger level if the trigger slope, specified by the  NIRFSA_ATTR_IQ_POWER_EDGE_REF_TRIGGER_SLOPE attribute, is set to  NIRFSA_VAL_RISING_SLOPE or above the trigger level if the trigger slope is  set to NIRFSA_VAL_FALLING_SLOPE.\n\n By default this value is set to 0, which means the device does not wait for a  quiet time before arming the trigger. This attribute is useful to trigger the  acquisition on signals containing repeated bursts, but for which each burst  may have large changes in signal power within itself. By configuring the  minimum quiet time to the time between bursts, you can ensure that the trigger  occurs at the beginning of a burst rather than at the  signal power change within  a burst.\n\n Default Value: 0 \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5840/5841     '
        },
        'name': 'REF_TRIGGER_MINIMUM_QUIET_TIME',
        'type': 'ViReal64'
    },
    1150059: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the expected carrier frequency of the incoming signal for demodulation. The  RF vector signal analyzer tunes to this frequency. NI-RFSA may coerce this value  based on hardware settings and the RF downconverter specifications. \n\n Units: hertz (Hz) \n\n Default Values:  \n\n PXIe-5644/5645/5646, PXIe-5840/5841: 1 GHz \n\n PXIe-5820: 0 Hz \n\n PXIe-5830/5831: 6.5 GHz \n\n All other devices: 100 MHz \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     ',
            'note': ' For the PXIe-5645, this attribute is ignored if you are using the I/Q ports. \n\n'
        },
        'name': 'IQ_CARRIER_FREQUENCY',
        'type': 'ViReal64'
    },
    1150060: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the trigger delay time, in seconds. The trigger delay time is the  length of time the IF digitizer waits after it receives the trigger  before it asserts the Reference event. \n\n Units: seconds \n\n Default Value: 0  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'REF_TRIGGER_DELAY',
        'type': 'ViReal64'
    },
    1150061: {
        'access': 'read-write',
        'documentation': {
            'description': ' Indicates the minimum time between temperature sensor readings in seconds. When you  call the niRFSA_ReadPowerSpectrumF64 function, the niRFSA_ReadIQSingleRecordComplexF64 function,  or the niRFSA_Initiate function, NI-RFSA checks whether at least the amount of  time specified by this attribute has elapsed before reading the hardware temperature. \n\n function or the NIRFSA_ATTR_DOWNCONVERTER_GAIN attribute. \n\n Default Value: 30 \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5693/5694/5698, PXIe-5820/5830/5831/5840/5841     ',
            'note': ' NI-RFSA ignores this attribute if you called the niRFSA_PerformThermalCorrection '
        },
        'name': 'TEMPERATURE_READ_INTERVAL',
        'type': 'ViReal64'
    },
    1150065: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the net signal gain for the NI-RFSA device at the current NI-RFSA settings and temperature.  NI-RFSA scales the acquired I/Q and spectrum data from the digitizer using the value of this attribute. \n\n Default Value: N/A  \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5644/5645/5646, PXI-5661,  PXIe-5663/5663E/5665/5667/5668, PXIe-5693/5694/5698, PXIe-5830/5831/5840/5841    '
        },
        'name': 'DOWNCONVERTER_GAIN',
        'type': 'ViReal64'
    },
    1150067: {
        'access': 'read-write',
        'documentation': {
            'description': ' Configures the loop bandwidth of the RF downconverter tuning PLLs. To  set this attribute, the NI-RFSA device must be in the Configuration state.\n\n PXI-5600/5661: For signal bandwidths greater than 10 MHz, NIRFSA_VAL_WIDE is the only  value supported for this attribute.\n\n PXIe-5601/5663/5663E: The PXIe-5601 does not support the NIRFSA_VAL_MEDIUM value.  This attribute is not supported if you are using an external LO. \n\n PXIe-5830/5831/5840/5841: The PXIe-5840/5841 supports only NIRFSA_VAL_MEDIUM for this attribute. This attribute is not supported if you are using an external LO. \n\n To use this attribute for the PXIe-5830/5831, you must use the channelName parameter of the niRFSA_SetAttributeViInt32  function to specify the name of the channel you are configuring. You can configure the LO1 and LO2 channels by using lo1  or lo2 as the channel string, or set the channel string to lo1,lo2 to configure both channels. For all other devices,  the only valid value for the channel string is  (empty string). \n\n Default Values: \n PXI-5600: NIRFSA_VAL_WIDE \n PXIe-5601: NIRFSA_VAL_NARROW \n\n PXIe-5644/5645/5646, PXIe-5830/5831/5840/5841: NIRFSA_VAL_MEDIUM \n\n Supported Devices: PXI-5600, PXIe-5601 (external digitizer mode), PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E, PXIe-5830/5831/5840/5841     '
        },
        'enum': 'LoopBandwidth',
        'name': 'DOWNCONVERTER_LOOP_BANDWIDTH',
        'type': 'ViInt32'
    },
    1150068: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the LO signal frequency for the configured center frequency.\n\n If you are using the NI RF vector signal analyzer with an external LO, use this  attribute to specify  the LO frequency that the external LO source passes into the LO IN or LO IN1 connector, located  on the RF downconverter front panel. If you are using an external LO, reading the value of this  attribute after configuring the rest of the parameters returns the LO frequency needed  by the device. \n\n Set this attribute to the actual LO frequency because NI-RFSA corrects  for any difference between expected and actual LO frequencies. \n\n To use this attribute for the PXIe-5830/5831, you must use the channelName parameter of the niRFSA_SetAttributeViReal64  function to specify the name of the channel you are configuring. You can configure the LO1 and LO2 channels by using lo1  or lo2 as the channel string, or set the channel string to lo1,lo2 to configure both channels. For all other devices,  the only valid value for the channel string is  (empty string). \n\n Default Value: \n\n PXIe-5694: 215 MHz All other devices: 0 \n\n Supported Devices: PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5644/5645/5646, PXIe-5663/5663E/5665/5667/5668, PXIe-5694, PXIe-5830/5831/5840/5841     '
        },
        'name': 'LO_FREQUENCY',
        'type': 'ViReal64'
    },
    1150069: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the LO injection side.\n\n PXIe-5601/5663/5663E-For frequencies below 517.5 MHz or above 6.4125 GHz, the LO  injection side is fixed and NI-RFSA returns an error if you specify the incorrect value.  If you do not configure this attribute, NI-RFSA selects the default LO injection side  based on the downconverter center frequency. Reset this attribute to  return to automatic behavior. \n\n PXIe-5603/5605/5665 (3.6 GHz)/5667 (3.6 GHz)-Setting this attribute to NIRFSA_VAL_LO_INJECTION_LOW_SIDE is not  supported for this device. PXIe-5605/5665 (14 GHz)/5667 (7 GHz)-Setting this attribute to NIRFSA_VAL_LO_INJECTION_LOW_SIDE is supported for this device for frequencies  greater than 4 GHz, but this configuration is not calibrated, and device specifications are not guaranteed. \n\n PXIe-5606/5668-Setting this attribute to NIRFSA_VAL_LO_INJECTION_LOW_SIDE is supported for certain frequencies in  high band, varying by final IF frequency. This configuration is not calibrated and device specifications are not  guaranteed. \n\n'
        },
        'enum': 'LoInjectionSideValues',
        'name': 'LO_INJECTION_SIDE',
        'type': 'ViInt32'
    },
    1150070: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the vertical range of the digitizer. The vertical range is defined as the absolute value  of the input range for a channel. The default vertical range works for all device configurations,  but you can use this attribute to optimize performance if you know that the signal level at the  digitizer input terminal is low. \n\n This value is expressed in volts. For example, to acquire a sine wave that  spans between -0.05 V and +0.05 V, set this attribute to 1.0. \n\n Default Value: 1.0 \n\n Supported Devices: PXI-5661, PXIe-5663/5663E/5665/5667, PXIe-5840/5841     ',
            'note': ' This attribute is read-only for the PXIe-5840/5841. \n\n'
        },
        'name': 'DIGITIZER_VERTICAL_RANGE',
        'type': 'ViReal64'
    },
    1150071: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether fractional resampling is enabled on the digitizer.  Fractional resampling allows the digitizer to achieve very fine resolution on its I/Q rate value.  Setting this attribute to VI_FALSE improves spectral performance. \n\n PXIe-5644/5645/5646, PXIe-5820/5830/5831/5840/5841——The only valid value for this attribute is VI_TRUE. \n\n PXIe-5668—When using a 400 MHz FPGA image, the only valid value for this attribute is VI_TRUE.  When using a 800 MHz FPGA image, the only valid value for this attribute is VI_FALSE.  Refer to the NI-RFSA Instrument Driver FPGA Extension topic for more information on FPGA images. \n\n Default Value: VI_TRUE \n\n Supported Devices: PXIe-5644/5645/5646, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'ENABLE_FRACTIONAL_RESAMPLING',
        'type': 'ViBoolean'
    },
    1150072: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies a comma-separated list of the terminals at which to export the Reference clock. \n\n Default Value:  (empty string) \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5694, PXIe-5820/5830/5831/5840/5841    '
        },
        'enum': 'RefClockOutTerminal',
        'name': 'EXPORTED_REF_CLOCK_OUTPUT_TERMINAL',
        'type': 'ViString'
    },
    1150074: {
        'access': 'read-write',
        'documentation': {
            'description': ' Configures the device attenuation to a value that has the actual calibrated IF attenuation  closest to the desired value. \n\n Valid Values: 0 to 30 \n\n Default Value: N/A \n\n Supported Devices: PXIe-5601/5603/5605 (external digitizer mode), PXIe-5663/5663E/5665/5667, PXIe-5693     '
        },
        'name': 'IF_ATTENUATION',
        'type': 'ViReal64'
    },
    1150075: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the desired IF filter path, regardless of the RF band chosen by NI-RFSA.\n\n Default Value: N/A \n\n Supported Devices: PXIe-5601     '
        },
        'enum': 'IfFilter',
        'name': 'IF_FILTER',
        'type': 'ViInt32'
    },
    1150076: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the value of the RF attenuation from a table of valid configurations.  This attribute is valid only during a calibration session and when you set the  NIRFSA_ATTR_LOW_FREQUENCY_BYPASS_ENABLED attribute to NIRFSA_VAL_DISABLED.\n\n Valid Values: 0 to 64 \n\n Default Value: N/A \n\n Supported Devices: PXIe-5693     '
        },
        'name': 'RF_ATTENUATION_INDEX',
        'type': 'ViInt32'
    },
    1150077: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies which RF attenuator table to use.\n\n Valid Values: 0 to 1 \n\n Default Value: N/A \n\n Supported Devices: PXIe-5601 (external digitizer mode), PXIe-5663/5663E     '
        },
        'name': 'RF_ATTENUATION_TABLE',
        'type': 'ViInt32'
    },
    1150078: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the IF1 attenuation, in dB. The device IF1 attenuator is set to this nominal value.  Use this attribute, along with the NIRFSA_ATTR_IF2_ATTEN_VALUE attribute, when you  set the NIRFSA_ATTR_IF_FILTER attribute to NIRFSA_VAL_BYPASS. \n\n Valid Values: 0 to 15 \n\n Units: dB \n\n Default Value: N/A \n\n Supported Devices: PXIe-5601 (external digitizer mode), PXIe-5663/5663E     '
        },
        'name': 'IF1_ATTEN_VALUE',
        'type': 'ViReal64'
    },
    1150079: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the IF2 attenuation, in dB. The device IF2 attenuator is set to this nominal value.  Use this attribute, along with the NIRFSA_ATTR_IF1_ATTEN_VALUE attribute, when you  set the NIRFSA_ATTR_IF_FILTER attribute to NIRFSA_VAL_BYPASS. \n\n Valid Values: 0 to 15 \n\n Units: dB \n\n Default Value: N/A  \n\n Supported Devices: PXIe-5601 (external digitizer mode), PXIe-5663/5663E     '
        },
        'name': 'IF2_ATTEN_VALUE',
        'type': 'ViReal64'
    },
    1150080: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether dithering is enabled on the digitizer. \n\n Dithering adds band-limited noise in the analog signal path to help reduce  the quantization effects  of the A/D converter and improve spectral performance. On the PXIe-5622,  this out-of-band noise is  added at low frequencies up to approximately 12 MHz.\n\n PXIe-5663/5663E/5665/5667—When you enable dithering, the maximum signal level is reduced by up to 3 dB.  This signal level reduction  is accounted for in the nominal input ranges of the PXIe-5622. Therefore,  you can overrange the input  by up to 3 dB with dither disabled. For example, the +4 dBm input range can handle signal  levels up to +7  dBm with dither disabled. For wider bandwidth acquisitions, such as 40 MHz, disable dithering  to eliminate residual leakage of the dither signal into the  lower frequencies of the IF passband, which starts at 12.5 MHz and ends at 62.5 MHz.  This leakage can slightly raise the noise floor in the lower frequencies, thus  degrading the performance in high-sensitivity applications. When taking spectral  measurements, this leakage can also appear as a wide, low-amplitude signal  near 12.5 MHz and 62.5 MHz. The width and amplitude of the signal depends on your  resolution bandwidth and the type of time-domain window you apply to your FFT. \n\n PXIe-5668—When you enable dithering, the maximum signal level is reduced by up to 2 dB. For the  PXIe-5624, the maximum input power with dither off is 8 dBm and the maximum input power  with dither on is 6 dBm. When acquiring an 800 MHz bandwidth signal, the I/Q data contains  the dither even if the dither signal is not in the displayed spectrum. The dither can affect  actions like power level triggering. \n\n Default Value: NIRFSA_VAL_ENABLED \n\n Supported Devices: PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     ',
            'note': ' For the PXIe-5820/5830/5831/5840/5841, only NIRFSA_VAL_ENABLED is supported. \n\n'
        },
        'enum': 'EnabledAttr',
        'name': 'DIGITIZER_DITHER_ENABLED',
        'type': 'ViInt32'
    },
    1150081: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the mechanical attenuator is enabled. Set this attribute to NIRFSA_VAL_ENABLED to use the mechanical atteuator.\n\n Disabling this attenuator can improve device performance. Refer to the PXIe-5663/5663E  RF Attenuation and Signal Levels for more information about the attenuators. \n\n Default Value: NIRFSA_VAL_ENABLED \n\n Supported Devices: PXIe-5601 (external digitizer mode), PXIe-5663/5663E     '
        },
        'enum': 'EnabledAttr',
        'name': 'MECHANICAL_ATTENUATOR_ENABLED',
        'type': 'ViInt32'
    },
    1150082: {
        'access': 'read-write',
        'documentation': {
            'description': ' Enables in-band retuning and specifies the current frequency, in hertz (Hz),  of the downconverter.   If you set this attribute, any measurements outside the instantaneous bandwidth  of the device are invalid.  To disable in-band retuning, reset the attribute or call the call the niRFSA_ResetDevice function. \n\n After you set this attribute, the downconverter is locked to that frequency  until the value is changed  or the attribute is reset. Locking the downconverter to a fixed value allows  frequencies within the  instantaneous bandwidth of the converter to be measured with minimal  overhead, decreasing tuning time. \n\n Valid Values: Any supported tuning frequency of the device \n PXIe-5820: The only valid value for this attribute is 0 Hz. \n\n Default Value: \n\n PXIe-5694: The default value for the PXIe-5694 is 193.6 MHz unless you set the  NIRFSA_ATTR_SIGNAL_CONDITIONING attribute to NIRFSA_VAL_SIGNAL_CONDITIONING_BYPASSED,  in which case the default value is 187.5 MHz. \n\n All other devices: The carrier frequency or spectrum center frequency.  NI-RFSA sets this attribute to the default value based on the value of  the NIRFSA_ATTR_ACQUISITION_TYPE attribute. \n\n Supported Devices: PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5644/5645/5646,  PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'DOWNCONVERTER_CENTER_FREQUENCY',
        'type': 'ViReal64'
    },
    1150083: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the RF path to use during calibration. This attribute is valid only during a  calibration session. When you set this attribute, NI-RFSA does not select the RF path based  on the downconverter center frequency.\n\n The following RF bands and associated frequency ranges apply to the PXIe-5601:\n RF band 1: 3 GHz to 6.6 GHz \n RF band 2: 330 MHz to 3 GHz \n RF band 3: 120 MHz to 330 MHz  \n RF band 4: 10 MHz to 120 MHz \n\n PXIe-5603—PXIe-5603 only uses RF band 1, which specifies a frequency range of 20 Hz to 3.6 GHz. \n\n PXIe-5605—The PXIe-5605 uses RF band 1 from 20 Hz to 3.6 GHz, the low band signal path, and RF band 2 from 3.6 GHz to 14 GHz, the high band signal path. \n\n PXIe-5606-The PXIe-5606 uses RF band 1 from 20 Hz to 3.6 GHz (20 Hz to 3.41 GHz if using the 320 MHz IF filter)  and RF band 2 from 3.6 GHz to 26.5 GHz (3.41 GHz to 26.5 GHz if using the 320 MHz IF filter). \n\n Default Values: \n PXIe-5603/5605 (low band)/5606—NIRFSA_VAL_EXT_CAL_RF_BAND_1  \n\n PXIe-5601/5605 (high band)—NIRFSA_VAL_EXT_CAL_RF_BAND_2 \n\n Supported Devices: PXIe-5601/5603/5605/5606, PXIe-5698     '
        },
        'enum': 'RfPathSelection',
        'name': 'CAL_RF_PATH_SELECTION',
        'type': 'ViInt32'
    },
    1150085: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the digitizer onboard memory in bytes. \n\n Default Value: N/A \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841    '
        },
        'name': 'MEMORY_SIZE',
        'type': 'ViInt64'
    },
    1150086: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the center frequency of the IF output that corresponds to  the configured RF center frequency.\n\n The downconverter translates RF input frequency to the IF output  frequency by mixing it with the LO signal.  The following values are the nominal values for the IF frequency:\n\n PXI-5600 15 MHz\n PXIe-5601 53 MHz or 187.5 MHz\n PXIe-5603 187.5 MHz or 199 MHz\n PXIe-5605 187.5 MHz, 190 MHz, or 199 MHz \n PXIe-5606 187.5 MHz, 190 MHz, 199 MHz, 507.5 MHz, or 730 MHz \n PXIe-5694 NIRFSA_ATTR_SIGNAL_CONDITIONING_ENABLED set to NIRFSA_VAL_SIGNAL_CONDITIONING_ENABLED and  NIRFSA_ATTR_IF_CONDITIONING_DOWN_CONVERSION_ENABLED set to NIRFSA_VAL_DISABLED: 193.6 MHz \n NIRFSA_ATTR_IF_CONDITIONING_DOWN_CONVERSION_ENABLED set to NIRFSA_VAL_ENABLED: 21.4 MHz \n NIRFSA_ATTR_SIGNAL_CONDITIONING_ENABLED set to NIRFSA_VAL_SIGNAL_CONDITIONING_BYPASSED: 162.5 MHz to 212.5 MHz \n\n However, the coarse nature of the LO settings can cause the  downconverter to be unable to tune to the exact  LO frequency that would produce the nominal IF output. Any coercion  in the actual LO frequency results in the  IF output frequency being slightly off from the nominal value.\n\n Additionally, if you use the NIRFSA_ATTR_DOWNCONVERTER_CENTER_FREQUENCY  and NIRFSA_ATTR_LO_FREQUENCY attributes  to program the downconverter, then the IF output frequency could be very  different from the nominal value.  NI-RFSA adjusts the acquired spectrum or I/Q data for the difference between  nominal and actual IF output  frequency. If you use an external digitizer with the NI RF downconverter,  use this attribute to specify the  actual IF output frequency. \n\n  Default Value: N/A \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5694     '
        },
        'name': 'IF_OUTPUT_FREQUENCY',
        'type': 'ViReal64'
    },
    1150087: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the delay duration units and interpretation for LO settling. Specify  the actual settling value using the NIRFSA_ATTR_FREQUENCY_SETTLING attribute.  This attribute is not supported if you are using an external LO. \n\n Default Value: NIRFSA_VAL_FSU_PPM \n\n Supported Devices: PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5644/5645/5646, PXIe-5663/5663E/5665/5667/5668, PXIe-5830/5831/5840/5841     '
        },
        'enum': 'FrequencySettlingUnits',
        'name': 'FREQUENCY_SETTLING_UNITS',
        'type': 'ViInt32'
    },
    1150088: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the value used for LO frequency settling. The units and interpretation  for this scalar value are specified using the NIRFSA_ATTR_FREQUENCY_SETTLING_UNITS  attribute. This attribute is not supported if you are using an external LO. \n\n The valid values for this attribute depend on the NIRFSA_ATTR_FREQUENCY_SETTLING_UNITS attribute. \n\n Valid Values:\n NIRFSA_VAL_FSU_SECONDS_AFTER_LOCK:\n 2 microseconds* to 80 milliseconds, resolution of approximately 2 microseconds (PXIe-5663/5663E)\n 4 microseconds to 80 milliseconds, resolution of approximately 4 microseconds (PXIe-5665/5667/5668) \n\n 1 microsecond* to 65 milliseconds, resolution of 1 microsecond (PXIe-5645/5646) \n\n 1 microsecond* to 10 seconds, resolution of 1 microsecond (PXIe-5830/5831/5840, PXIe-5840 with PXIe-5653 (using the PXIe-5840 internal LO),  PXIe-5831 with PXIe-5653 (using the PXIe-3622 LO)) \n\n 4 microseconds to 80 milliseconds, resolution of approximately 4 microseconds (PXIe-5840 with PXIe-5653 (using the PXIe-5653 LO),  PXIe-5831 with PXIe-5653 (using the PXIe-5653 LO)) \n\n NIRFSA_VAL_FSU_SECONDS_AFTER_IO:\n 0 microseconds to 80 milliseconds**, resolution of 1 microsecond (PXIe-5663/5663E/5665/5667/5668, PXIe-5840 with PXIe-5653 (using the PXIe-5653 LO), PXIe-5831 with PXIe-5653 (using the PXIe-5653 LO)) \n 1 microsecond to 65 milliseconds, resolution of 1 microsecond (PXIe-5645/5646) \n\n 0 microseconds to 10 seconds, resolution of 1 microsecond (PXIe-5830/5831/5840, PXIe-5840 with PXIe-5653 (using the PXIe-5840 internal LO) PXIe-5831 with PXIe-5653 (using PXIe-3622 LO)) \n\n NIRFSA_VAL_FSU_PPM:\n 1.0, 0.1, 0.01(PXIe-5663/5663E) \n 1.0, 0.1, 0.01, 0.001 (PXIe-5665/5667/5668) \n\n 1.0, 0.1, 0.01 (PXIe-5645/5646) \n\n 1.0 to 0.01 (PXIe-5830/5831/5840/5841, PXIe-5840 with PXIe-5653 (using the PXIe-5840 internal LO), PXIe-5831 with PXIe-5653) \n\n 1.0 to 0.001 (PXIe-5840 with PXIe-5653 (using the PXIe-5653 LO)) \n\n *If the NIRFSA_ATTR_FREQUENCY_SETTLING_UNITS attribute is set to NIRFSA_VAL_FSU_TIME_AFTER_LOCK and the NIRFSA_ATTR_DOWNCONVERTER_LOOP_BANDWIDTH  attribute is set to NIRFSA_VAL_NARROW, NI recommends a minimum settling time of 128 microseconds to ensure that the PLL lock stabilizes.  If the NIRFSA_ATTR_DOWNCONVERTER_LOOP_BANDWIDTH is set to NIRFSA_VAL_WIDE, NI recommends a minimum settling time of 16 microseconds. \n **When in RF list mode, the valid values for NIRFSA_VAL_FSU_TIME_AFTER_IO are 0 microseconds to 50 milliseconds. \n\n Refer to the NIRFSA_ATTR_LO_SOURCE attribute for more information. \n\n Default Value: 0.1 \n\n Supported Devices: PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5645/5646, PXIe-5663/5663E/5665/5667/5668, PXIe-5830/5831/5840/5841     ',
            'note': ' For the PXIe-5840 with PXIe-5653, the valid values depend on the module used as the LO source. '
        },
        'name': 'FREQUENCY_SETTLING',
        'type': 'ViReal64'
    },
    1150089: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the current temperature, in degrees Celsius, of the LO module.  this attribute is not supported if you are using an external LO. \n\n PXIe-5840/5841—If you query this attribute during RF list mode, list steps may take longer to complete during list execution. \n Default Value: N/A \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5840/5841     ',
            'note': ' For the 5601/5603/5605/5606 (external digitizer mode) and PXI-5661, PXIe-5663/5663E/5665/5667/5668, '
        },
        'name': 'LO_TEMPERATURE',
        'type': 'ViReal64'
    },
    1150090: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the current temperature, in degrees Celsius, of the digitizer module. \n\n PXIe-5820/5840/5841—If you query this attribute during RF list mode, list steps may take longer to complete during list execution. \n Default Value: N/A \n\n Supported Devices: PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5840/5841     '
        },
        'name': 'DIGITIZER_TEMPERATURE',
        'type': 'ViReal64'
    },
    1150091: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the revision of the RF downconverter module.\n\n For the PXIe-5830/5831, this attribute returns the revision of the PXIe-3621/3622. \n\n Default Value: N/A \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668,  PXIe-5693/5694/5698, PXIe-5820/5830/5831/5840/5841     ',
            'note': ' For the PXIe-5644/5645/5646 and PXIe-5820/5840/5841, this attribute returns the revision of the VST module. '
        },
        'name': 'MODULE_REVISION',
        'type': 'ViString'
    },
    1150092: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the configuration list for RF list mode to make active  for configuration or initiation. \n\n Activating a list makes all attributes in the list reflect the value of the attributes  that correspond to the set specified by the NIRFSA_ATTR_ACTIVE_CONFIGURATION_LIST and  the NIRFSA_ATTR_ACTIVE_CONFIGURATION_LIST_STEP attributes. Set this attribute to an empty  string to disable RF list mode. \n\n Default Value:  (empty string) for devices that support RF list mode. For all other devices, the default value is N/A. \n\n Supported Devices: PXIe-5644/5645/5646, PXIe-5663E/5665/5667, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'ACTIVE_CONFIGURATION_LIST',
        'type': 'ViString'
    },
    1150093: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the step in the configuration list for RF list mode to make active  for configuration or initiation. \n\n Activating a list makes all attributes in the list reflect the value of the attributes  that correspond to the set specified by the NIRFSA_ATTR_ACTIVE_CONFIGURATION_LIST and  the NIRFSA_ATTR_ACTIVE_CONFIGURATION_LIST_STEP attributes. \n\n Default Value: 0 for devices that support RF list mode. For all other devices, the default value is N/A.\n\n Supported Devices: PXIe-5644/5645/5646, PXIe-5663E/5665/5667, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'ACTIVE_CONFIGURATION_LIST_STEP',
        'type': 'ViInt64'
    },
    1150094: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the gain, in dB, of a switch (or cable) connected before the RF IN connector  of an NI-RFSA system. When you set this attribute and the NIRFSA_ATTR_ATTENUATION and NIRFSA_ATTR_IF_ATTENUATION  values, NI-RFSA calculates appropriate attenuator settings based on the value of this attribute and the  value of the NIRFSA_ATTR_REFERENCE_LEVEL attribute. In this case, NI-RFSA interprets the reference level  as the maximum expected power level of the signal at the input of the external gain device.  For more information about attenuation, refer to the Attenuation and Signal Levels  topic for your device in the NI RF Vector Signal Analyzers Help. \n\n With this attribute set, NI-RFSA reads the NIRFSA_ATTR_IQ_POWER_EDGE_REF_TRIGGER_LEVEL  attribute value as the power level at the input of the external gain device at  which the NI-RFSA device should trigger. \n\n  Negative values indicate attenuation. \n\n the IQ IN connector.  Valid Values: -INF to +INF \n\n Units: dB \n\n Default Value: 0 \n\n Supported Devices: PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5644/5645/5646,  PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841      ',
            'note': ' For the PXIe-5645, this attribute is ignored if you are using the I/Q ports. \n'
        },
        'name': 'EXTERNAL_GAIN',
        'type': 'ViReal64'
    },
    1150095: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute is not for customer use. \n\n     '
        },
        'name': 'CONFIGURATION_LIST_STEP_TRIGGER_SOURCE',
        'type': 'ViString'
    },
    1150096: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the time, in seconds, that the timer waits before sending a Timer event. \n\n After the timer reaches zero, it automatically restarts. \n\n Units: seconds \n\n Default Value: 0.01  \n\n Supported Devices: PXIe-5644/5645/5646, PXIe-5663E/5665/5667, PXIe-5820/5830/5831/5840/5841     ',
            'note': ' For the PXIe-5820/5830/5831/5840/5841, this attribute must be set for the timer to start. If you do not set this attribute, the timer is disabled. \n\n'
        },
        'name': 'TIMER_EVENT_INTERVAL',
        'type': 'ViReal64'
    },
    1150097: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether peer-to-peer streaming is enabled for the active stream endpoint.\n\n This attribute is endpoint based. \n\n Default Value: VI_FALSE \n\n Supported Devices: PXIe-5663/5663E/5665/5667, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'P2P_ENABLED',
        'type': 'ViBoolean'
    },
    1150098: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the number of peer-to-peer streams supported by the device. \n\n Default Value: 0  \n\n Supported Devices: PXIe-5663/5663E/5665/5667, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'P2P_FIFO_ENDPOINT_COUNT',
        'type': 'ViInt64'
    },
    1150099: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the number of complex samples transferred through the peer-to-peer stream endpoint  since the endpoint was last reset. \n\n Default Value: 0 \n\n Supported Devices: PXIe-5663/5663E/5665, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'P2P_SAMPLES_TRANSFERRED',
        'type': 'ViInt64'
    },
    1150100: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the current number of complex samples available in the peer-to-peer endpoint.\n\n Default Value: 0  \n\n Supported Devices: PXIe-5663/5663E/5665/5667, PXIe-5820/5830/5831/5840/5841     ',
            'note': ' The complex samples are composed of two 16-bit words, with the I data as the LSB. \n\n'
        },
        'name': 'P2P_SAMPLES_AVAILABLE_IN_ENDPOINT',
        'type': 'ViInt64'
    },
    1150101: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the largest number of complex samples available in the peer-to-peer endpoint since this  attribute was last read. \n\n Default Value: 0  \n\n Supported Devices: PXIe-5663/5663E/5665/5667, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'P2P_MOST_SAMPLES_AVAILABLE_IN_ENDPOINT',
        'type': 'ViInt64'
    },
    1150102: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the size, in samples, of the peer-to-peer endpoint.\n\n  Default Value: 0 \n\n Supported Devices: PXIe-5663/5663E/5665/5667, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'P2P_ENDPOINT_SIZE',
        'type': 'ViInt64'
    },
    1150103: {
        'access': 'read only',
        'documentation': {
            'description': ' Indicates whether the endpoint has overflowed. An overflow condition occurs when data  is written to the endpoint faster than it can be streamed from it. During an overflow,  data in the endpoint begins to be overwritten. Reset the device or close the session to  reset the overflow condition. \n\n Default Value: VI_FALSE  \n\n Supported Devices: PXIe-5663/5663E/5665/5667, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'P2P_ENDPOINT_OVERFLOW',
        'type': 'ViBoolean'
    },
    1150104: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum bandwidth that the device can consume. \n\n  than the value you specify for this attribute. \n\n Default Value: N/A  \n\n Supported Devices: PXI-5661, PXIe-5663/5663E/5665     ',
            'note': ' The NI device limits itself to transfer fewer bytes per second on the PCI Express bus '
        },
        'name': 'DATA_TRANSFER_MAXIMUM_BANDWIDTH',
        'type': 'ViReal64'
    },
    1150105: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum number of samples to transfer at one time from  the device to host memory. Increasing this number should result in better  fetching performance because the driver does not need to restart the transfers  as often. However, increasing this number may increase the amount of page-locked  memory required from the system. \n\n Default Value: 0x400000 \n\n Supported Devices: PXI-5661, PXIe-5663/5663E/5665/5667/5668     '
        },
        'name': 'DATA_TRANSFER_BLOCK_SIZE',
        'type': 'ViInt32'
    },
    1150106: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the offset to apply to the initial I and Q phases.\n\n Valid Values: -180 to 180 \n Default Value: 0  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'PHASE_OFFSET',
        'type': 'ViReal64'
    },
    1150107: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether a limit is placed on the number of records and the size of the records by  the size of the device onboard memory. When a peer-to-peer stream is enabled and onboard memory  is disabled, any fetch calls result in an error. \n\n Default Value: VI_FALSE  \n\n Supported Devices: PXIe-5663/5663E/5665/5667, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'P2P_ONBOARD_MEMORY_ENABLED',
        'type': 'ViBoolean'
    },
    1150109: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the IF attenuation index from a table of valid settings.  To select a correct attenuation table, set this attribute in conjunction with  the NIRFSA_ATTR_CAL_IF_FILTER_SELECTION attribute. This attribute is valid only  during a calibration session. \n\n Valid Values: 0 to 25 \n\n Default Value: 0 \n\n Supported Devices: PXIe-5694     '
        },
        'name': 'CAL_IF_ATTENUATION_INDEX',
        'type': 'ViInt32'
    },
    1150110: {
        'access': 'read-write',
        'documentation': {
            'description': ' Selects the value of RF electronic attenuation from a table of valid configurations.  This attribute is valid only during a calibration session and when you set  the NIRFSA_ATTR_CAL_RF_PATH_SELECTION attribute to NIRFSA_ATTR_VAL_EXT_CAL_RF_BAND_1. \n\n Default Value: N/A  \n\n Supported Devices: PXIe-5603/5605/5606     '
        },
        'name': 'CAL_RF_ELECTRONIC_ATTENUATION_INDEX',
        'type': 'ViInt32'
    },
    1150111: {
        'access': 'read-write',
        'documentation': {
            'description': ' Selects the value of the RF mechanical attenuation configuration from a table of  valid configurations. This attribute is valid only during a calibration session. \n\n Default Value: N/A \n\n Supported Devices: PXIe-5603/5605/5606     '
        },
        'name': 'CAL_RF_MECHANICAL_ATTENUATION_INDEX',
        'type': 'ViInt32'
    },
    1150112: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the IF filter path during calibration. The attribute is  valid only during a calibration session. \n\n Default Value: NIRFSA_VAL_EXT_CAL_IF_FILTER_PATH_4 \n\n Supported Devices: PXIe-5694     '
        },
        'enum': 'CalIFFilterSelection',
        'name': 'CAL_IF_FILTER_SELECTION',
        'type': 'ViInt32'
    },
    1150113: {
        'access': 'read-write',
        'documentation': {
            'description': ' Selects the LO signal path used during calibration. During noncalibration sessions,  NI-RFSA implicitly derives the LO signal path from the center frequency. During  calibration sessions, you must explicitly specify the LO signal path. This attribute is  valid only during a calibration session. \n\n Default Value: NIRFSA_VAL_EXT_CAL_LO_PATH_1  \n\n Supported Devices: PXIe-5603/5605/5606     '
        },
        'enum': 'LoPathSelection',
        'name': 'CAL_LO_PATH_SELECTION',
        'type': 'ViInt32'
    },
    1150114: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the LO1 attenuation, in dB, during a calibration session. The default value is  31.5 dB. This attribute is valid only during a calibration session. \n\n Valid Values: 0 to 31.5 \n\n Default Value: 31.5  \n\n Supported Devices: PXIe-5603/5605/5606     '
        },
        'name': 'CAL_LO1_ATTENUATION',
        'type': 'ViReal64'
    },
    1150115: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the LO2 attenuation, in dB, during a calibration session. The default value is  15.5 dB. This attribute is valid only during a  calibration session. \n\n Valid Values: 0 to 15.5 \n\n Default Value: 15.5 \n\n Supported Devices: PXIe-5603/5605/5606      '
        },
        'name': 'CAL_LO2_ATTENUATION',
        'type': 'ViReal64'
    },
    1150116: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the LO3 attenuation, in dB, during a calibration session. The default  value is 15.5 dB. This attribute is valid only during a calibration session. \n\n Valid Values: 0 to 15.5 \n\n Default Value: 15.5  \n\n Supported Devices: PXIe-5603/5605/5606      '
        },
        'name': 'CAL_LO3_ATTENUATION',
        'type': 'ViReal64'
    },
    1150117: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the fully qualified signal name as a string. \n\n Default Values:  \n\n PXIe-5820/5840/5841:  /ModuleName/ai/0/ReadyForStartEvent, where ModuleName is the name of your device in MAX. \n\n All other devices: /DigitizerName/ReadyForStartEvent, where DigitizerName is the name associated with your digitizer module in MAX. \n\n PXIe-5830/5831: /BasebandModule/ai/0/ReadyForStartEvent, where BasebandModule is the name of the baseband module of your device in MAX. \n\n Supported Devices: PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841 \t'
        },
        'name': 'READY_FOR_START_EVENT_TERMINAL_NAME',
        'type': 'ViString'
    },
    1150118: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the fully qualified signal name as a string. \n\n Default Values: \n\n PXIe-5820/5840/5841: /ModuleName/ai/0/ReadyForAdvanceEvent, where ModuleName is the name of your device in MAX. \n\n All other devices: /DigitizerName/ReadyForAdvanceEvent, where DigitizerName is the name associated with your digitizer module in MAX. \n\n PXIe-5830/5831: /BasebandModule/ai/0/ReadyForAdvanceEvent, where BasebandModule is the name of the baseband module of your device in MAX. \n\n Supported Devices: PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841 \t'
        },
        'name': 'READY_FOR_ADVANCE_EVENT_TERMINAL_NAME',
        'type': 'ViString'
    },
    1150119: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the fully qualified signal name as a string. \n\n Default Values: \n\n PXIe-5820/5840/5841: /ModuleName/ai/0/ReadyForReferenceEvent, where ModuleName is the name of your device in MAX. \n\n PXIe-5830/5831: /BasebandModule/ai/0/ReadyForReferenceEvent, where BasebandModule is the name of the baseband module of your device in MAX. \n\n All other devices: /DigitizerName/ReadyForReferenceEvent, where DigitizerName is the name associated with your digitizer module in MAX. \n\n Supported Devices: PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841 \t'
        },
        'name': 'READY_FOR_REF_EVENT_TERMINAL_NAME',
        'type': 'ViString'
    },
    1150120: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the fully qualified signal name as a string. \n\n Default Values:  \n\n PXIe-5820/5840/5841: /ModuleName/ai/0/EndOfRecordEvent, where ModuleName is the name of your device in MAX. \n\n All other devices: /DigitizerName/EndOfRecordEvent, where DigitizerName is the name associated with your digitizer module in MAX. \n\n PXIe-5830/5831: /BasebandModule/ai/0/EndOfRecordEvent, where BasebandModule is the name of the baseband module of your device in MAX. \n\n Supported Devices: PXIe-5644/5645/5646, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841 \t'
        },
        'name': 'END_OF_RECORD_EVENT_TERMINAL_NAME',
        'type': 'ViString'
    },
    1150121: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the fully qualified signal name as a string. \n\n Default Values: \n\n PXIe-5820/5840/5841: /ModuleName/ai/0/DoneEvent, where ModuleName is the name of your device in MAX. \n\n PXIe-5830/5831: /BasebandModule/ai/0/DoneEvent, where BasebandModule is the name of the baseband module of your device in MAX. \n\n All other devices: /DigitizerName/DoneEvent, where DigitizerName is the name associated with your digitizer module in MAX. \n\n Supported Devices: PXIe-5644/5645/5646, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'DONE_EVENT_TERMINAL_NAME',
        'type': 'ViString'
    },
    1150122: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the fully qualified signal name as a string. \n\n Default Values: \n\n PXIe-5820/5840/5841: /ModuleName/ai/0/StartTrigger, where ModuleName is the name of your device in MAX. \n\n PXIe-5830/5831: /BasebandModule/ai/0/StartTrigger, where BasebandModule is the name of the baseband module of your device in MAX. \n\n All other devices: /DigitizerName/StartTrigger, where DigitizerName is the name associated with your digitizer module in MAX.  Supported Devices: PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841 \t'
        },
        'name': 'START_TRIGGER_TERMINAL_NAME',
        'type': 'ViString'
    },
    1150123: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the fully qualified signal name as a string. \n\n Default Values: \n\n PXIe-5820/5840/5841: /ModuleName/ai/0/RefTrigger, where ModuleName is the name of your device in MAX. \n\n PXIe-5830/5831: /BasebandModule/ai/0/RefTrigger, where BasebandModule is the name of your baseband module of your device in MAX. \n\n All other devices: /DigitizerName/RefTrigger, where DigitizerName is the name associated with your digitizer module in MAX. \n\n Supported Devices: PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841 \t'
        },
        'name': 'REF_TRIGGER_TERMINAL_NAME',
        'type': 'ViString'
    },
    1150124: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the fully qualified signal name as a string. \n\n Default Values: \n\n PXIe-5820/5840/5841: /ModuleName/ai/0/AdvanceTrigger, where ModuleName is the name of your device in MAX. \n\n All other devices: /DigitizerName/AdvanceTrigger, where DigitizerName is the name associated with your digitizer module in MAX. \n\n PXIe-5830/5831: /BasebandModule/ai/0/AdvanceTrigger, where BasebandModule is the name of the baseband module of your device in MAX. \n\n Supported Devices: PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841  \t'
        },
        'name': 'ADVANCE_TRIGGER_TERMINAL_NAME',
        'type': 'ViString'
    },
    1150125: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the instantaneous bandwidth of the device. The instantaneous bandwidth is  the effective real-time bandwidth of the signal path for your configuration. The value  is expressed in hertz (Hz). \n\n To change the value that NI-RFSA uses for the maximum size of multispan acquisition subspans,  use the NIRFSA_ATTR_FFT_WIDTH attribute.\n\n  bandwidth is constrained to 50 MHz or 25 MHz, depending on the digitizer option you  purchased.\n\n PXI-5661-The PXI-5600 RF downconverter bandwidth is 20 MHz.\n\n PXIe-5663/5663E-Your maximum allowed instantaneous bandwidth depends on the downconverter center  frequency you use. Refer to the PXIe-5601 RF downconverter overview for more information about  instantaneous bandwidth.\n\n correspond with different instantaneous bandwidths. For example, you cannot configure a multispan acquisition that acquires one  span from 110 MHz to 120 MHz and a second from 120 MHz to 130 MHz because the instantaneous  bandwidth for frequencies above 120 MHz is different than the instantaneous bandwidth for  frequencies less than 120 MHz, which are 20 MHz and 10 MHz respectively.\n\n PXIe-5665-Your maximum allowed instantaneous bandwidth is independent of the downconverter center frequency.\n Refer to the NI PXIe-5665 Specifications for more information about instantaneous bandwidth.\n\n PXIe-5665 (14 GHz), PXIe-5668-If you have enabled the preselector for the PXIe-5605, the device instantaneous  bandwidth value is only a typical specification. For multispan acquisitions, NI-RFSA uses this  typical specification as the maximum size for the acquisition subspans.\n\n  PXIe-5605 provide a nominal 80 MHz bandwidth at -6 dB.  At frequencies greater than 3.6 GHz, the PXIe-5605 provides a nominal bandwidth of 47 MHz at -6 dB  with the preselector (YIG-tuned filter) enabled.\n\n PXIe-5693—This attribute is read-only for the PXIe-5693. The value for the device instantaneous bandwidth  depends on the value for the RF preselector filter. \n\n PXIe-5694, PXIe-5667—If your application uses the PXIe-5694 as part of an PXIe-5667 spectrum monitoring receiver  or the PXIe-5694 as a stand-alone device, NI-RFSA determines the appropriate IF filter to use based on the  value that you set for this attribute. \n\n conditioning by setting the NIRFSA_ATTR_SIGNAL_CONDITIONING_ENABLED attribute to  NIRFSA_VAL_SIGNAL_CONDITIONING_BYPASSED. \n\n PXIe-5644/5645/5646-This attribute is read-only for the PXIe-5644/5645/5646. Refer to the specifications  document for your devices for more information about instantaneous bandwidth. \n\n PXIe-5840/5841-Your maximum allowed instantaneous bandwidth depends on the downconverter center frequency you use. Refer to the PXIe-5840 Specifications for more information about instantaneous bandwidth. Set this attribute to select different device instantaneous bandwidths for a given downconverter center frequency. The device instantaneous bandwidth that you select will be greater than or equal to the requested instantaneous  bandwidth. If this attribute is not set, NI-RFSA uses the maximum allowed instantaneous bandwidth. \n\n Default Value: N/A  \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5644/5645/5646,  PXI-5661, PXIe-5663/5663E/5665/5667, PXIe-5693/5694, PXIe-5820/5830/5831/5840/5841     ',
            'note': ' Device instantaneous bandwidths greater than 20 MHz are available only when you bypass all signal '
        },
        'name': 'DEVICE_INSTANTANEOUS_BANDWIDTH',
        'type': 'ViReal64'
    },
    1150126: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the index of the current RF configuration list step that is executing in RF list  mode. The list is zero-indexed. You can query this attribute only when a list is executed. \n\n PXIe-5663E/5665/5667—This attribute can be read only when a configuration list is running. \n PXIe-5644/5645/5646—This attribute always returns 0 when the configuration list is not running.\n PXIe-5820/5830/5831/5840/5841—If a configuration list is not running, this attribute returns the last step of a configuration list that is programmed  to the hardware. If the device was last initiated without an active configuration list, this attribute returns 0. \n\n Default Value: N/A \n\n Supported Devices: PXIe-5644/5645/5646, PXIe-5663E/5665/5667, PXIe-5820/5830/5831/5840/5841 \t'
        },
        'name': 'CONFIGURATION_LIST_STEP_IN_PROGRESS',
        'type': 'ViInt64'
    },
    1150127: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of dB by which to adjust the device mixer level. The default value  is 0, which specifies device settings that are the best compromise between  distortion and noise.  Specifying a positive value for this attribute configures the device for moderate distortion and  low noise, and specifying a negative value results in low distortion and higher noise. \n\n You cannot set the NIRFSA_ATTR_MIXER_LEVEL and NIRFSA_ATTR_MIXER_LEVEL_OFFSET attributes at  the same time. \n\n Units: dB  Default Value: 0 \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXI-5661, PXIe-5663/5663E/5665/5667/5668     ',
            'note': ' This attribute is read-only for the PXIe-5667 when the NIRFSA_ATTR_LOW_FREQUENCY_BYPASS_ENABLED attribute is set to NIRFSA_VAL_DISABLED. \n\n'
        },
        'name': 'MIXER_LEVEL_OFFSET',
        'type': 'ViReal64'
    },
    1150128: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the level of mechanical attenuation for the RF path, in dB.\n\n PXIe-5667—This attribute is read-only when the NIRFSA_ATTR_LOW_FREQUENCY_BYPASS_ENABLED attribute is set to NIRFSA_VAL_DISABLED. \n\n PXIe-5668 with PXIe-5698—This attribute is read-only when the NIRFSA_ATTR_RF_PREAMP_ENABLED attribute is set to NIRFSA_VAL_RF_PREAMP_ENABLED. \n\n Units: dB \n\n Valid Values:\n PXIe-5601/5663/5663E-0, 16 \n PXIe-5603/5665 (3.6 GHz)-0, 10, 20, 30 \n PXIe-5605/5665 (14 GHz), PXIe-5606/5668-0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75 \n PXIe-5667 (3.6 GHz) using the PXIe-5693 RF preselector low frequency bypass path—0, 10, 20, 30 \n PXIe-5667 (3.6 GHz) using the PXIe-5693 RF preselector filter path—0 \n PXIe-5667 (7 GHz) using the PXIe-5693 RF preselector low frequency bypass path—0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75 \n PXIe-5667 (7 GHz) using the PXIe-5693 RF preselector filter path—0 \n PXIe-5668 with PXIe-5698 with the NIRFSA_ATTR_RF_PREAMP_ENABLED attribute set to NIRFSA_VAL_RF_PREAMP_ENABLED—5 \n\n Default Value: N/A \n\n Supported Devices: PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5663/5663E/5665/5667/5668     '
        },
        'name': 'MECHANICAL_ATTENUATION',
        'type': 'ViReal64'
    },
    1150129: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the RF preamplifier is enabled in the system. \n PXIe-5667, PXIe-5830/5831/5840/5841—If you set this attribute to NIRFSA_VAL_RF_PREAMP_AUTOMATIC, NI-RFSA selects the  preamplifier state based on the value of the NIRFSA_ATTR_REFERENCE_LEVEL attribute. \n\n PXIe-5667—The NIRFSA_VAL_RF_PREAMP_AUTOMATIC value is supported only when the NIRFSA_ATTR_LOW_FREQUENCY_BYPASS_ENABLED  attribute is set to NIRFSA_VAL_DISABLED. If the reference level is greater than -25 dBm,  NI-RFSA disables the preamplifier. If the reference level is less than or equal to -25 dBm,  NI-RFSA sets the NIRFSA_ATTR_RF_PREAMP_ENABLED attribute to NIRFSA_VAL_RF_PREAMP_ENABLED_WHEN_IN_SIGNAL_PATH. \n\n PXIe-5668 with PXIe-5698—If you set this attribute to NIRFSA_ATTR_RF_PREAMP_ENABLED, only the  preamplifier on the PXIe-5698 is used, and the preamplifier on the PXIe-5668 remains disabled. \n\n Only devices with an RF preamplifier support setting this attribute  to NIRFSA_VAL_RF_PREAMP_ENABLED_WHEN_IN_SIGNAL_PATH or NIRFSA_VAL_RF_PREAMP_ENABLED. \n\n Default Value:  \n\n PXIe-5830/5831: NIRFSA_VAL_PREAMP_AUTOMATIC \n All other devices: NIRFSA_VAL_RF_PREAMP_DISABLED \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5644/5645/5646,  PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5693/5698, PXIe-5830/5831/5840/5841     ',
            'note': ' All devices support setting this attribute to NIRFSA_VAL_RF_PREAMP_DISABLED. '
        },
        'enum': 'RfPreampEnabled',
        'name': 'RF_PREAMP_ENABLED',
        'type': 'ViInt32'
    },
    1150130: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the level of the IF signal leaving the system, in dBm.  Use this attribute to increase or decrease the nominal IF signal output level to  achieve better measurement results.\n If you set the NIRFSA_ATTR_IF_OUTPUT_POWER_LEVEL and  NIRFSA_ATTR_IF_OUTPUT_POWER_LEVEL_OFFSET attributes at the same time,  NI-RFSA returns an error.\n\n the IF output power level may be higher than the value you request. Read the value of this  attribute to determine the configured IF output power level. \n\n can apply, the NIRFSA_ATTR_REFERENCE_LEVEL attribute, the  NIRFSA_ATTR_DOWNCONVERTER_CENTER_FREQUENCY attribute, and the NIRFSA_ATTR_SPECTRUM_CENTER_FREQUENCY  attribute or NIRFSA_ATTR_IQ_CARRIER_FREQUENCY attribute, depending on your acquisition type. \n\n Units: dBm \n\n Default Value: \n\n PXIe-5667: -2 dBm \n PXIe-5668: -1 dBm \n All other devices: –6 dBm \n\n Supported Devices: PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5663/5663E/5665/5667/5668, PXIe-5693/5694    ',
            'note': ' The value of this attribute is limited by the amount of IF attenuation that the downconverter '
        },
        'name': 'IF_OUTPUT_POWER_LEVEL',
        'type': 'ViReal64'
    },
    1150131: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the number of dB by which to adjust the default IF output power level. This  attribute does  not depend on absolute IF output power levels, so you can use it to adjust  the IF output power level  on all NI-RFSA devices without knowing the exact default value. Use this attribute to increase or  decrease the nominal output level to achieve better measurement results. The  default value for the offset  is 0 dB, which results in an IF OUT output power level of -6 dBm. \n\n You cannot set the  NIRFSA_ATTR_IF_OUTPUT_POWER_LEVEL and NIRFSA_ATTR_IF_OUTPUT_POWER_LEVEL_OFFSET attributes at  the same time. \n\n Units: dB \n\n Default Value: 0 \n\n Supported Devices: PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5663/5663E/5665/5667/5668    '
        },
        'name': 'IF_OUTPUT_POWER_LEVEL_OFFSET',
        'type': 'ViReal64'
    },
    1150132: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the tunable preselector is enabled on the downconverter. \n\n NIRFSA_VAL_PRESELECTOR_ENABLED_WHEN_IN_SIGNAL_PATH.  Only devices with a preselector support setting this attribute to NIRFSA_VAL_PRESLECTOR_ENABLED. \n\n Default Value: NIRFSA_VAL_PRESELECTOR_DISABLED if the device has no preselector. \n NIRFSA_VAL_PRESELECTOR_ENABLED_WHEN_IN_SIGNAL_PATH if the device has a preselector.  \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5830/5831/5840/5841     ',
            'note': ' All devices support setting this attribute to NIRFSA_VAL_PRESELECTOR_DISABLED or '
        },
        'enum': 'DownconverterPreselectorEnabledAttr',
        'name': 'DOWNCONVERTER_PRESELECTOR_ENABLED',
        'type': 'ViInt32'
    },
    1150134: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the LO OUT terminals on the installed devices. \n\n PXIe-5601-The only valid value for this attribute is VI_TRUE. \n\n PXIe-5603/5605/5606—If you want to daisy-chain multiple devices together using the same LO source,  set this attribute to TRUE to export the LO input signals on the LO1 IN, LO2 IN, and LO3 IN  terminals to LO1 OUT, LO2 OUT, and LO3 OUT, respectively. \n\n PXIe-5694-You can enable this attribute only if you set the NIRFSA_ATTR_LO_SOURCE attribute  to NIRFSA_VAL_LO_IN_STR, or if you set the NIRFSA_ATTR_LO_SOURCE attribute to  NIRFSA_VAL_ONBOARD_STR and the NIRFSA_ATTR_IF_CONDITIONING_DOWN_CONVERSION_ENABLED attribute to  NIRFSA_VAL_ENABLED. \n\n PXIe-5830/5831-To use this attribute for the PXIe-5830/5831, you must use the channelName parameter of the niRFSA_SetAttributeViBoolean  function to specify the name of the channel you are configuring. You can configure the LO1 and LO2 channels by using lo1  or lo2 as the channel string, or set the channel string to lo1,lo2 to configure both channels. For all other devices,  the only valid value for the channel string is  (empty string). \n\n Default Values: \n PXIe-5601, PXIe-5663/5663E: VI_TRUE \n PXIe-5603/5605/5606, PXIe-5644/5645/5646, PXIe-5665/5667/5668, PXIe-5694, PXIe-5830/5831/5840/5841: VI_FALSE  \n\n Supported Devices: PXIe-5601/5603/5605 (external digitizer mode), PXIe-5644/5645/5646, PXIe-5663/5663E/5665/5667, PXIe-5694, PXIe-5830/5831/5840/5841     ',
            'note': ' If you are sharing an LO for the PXIe-5830/5831 between and NI-RFSA and NI-RFSG session, ensure both sessions use the same shared setting. \n\n'
        },
        'name': 'LO_EXPORT_ENABLED',
        'type': 'ViBoolean'
    },
    1150135: {
        'access': 'read-write',
        'documentation': {
            'description': ' Adjusts the dynamics of the current driving the YIG main coil.\n\n frequency to settle significantly faster for some frequency transitions at the  expense of increased phase noise. This attribute is not supported if you are  using an external LO. \n\n Default Value: NIRFSA_VAL_LO_YIG_MAIN_COIL_DRIVE_NORMAL  \n\n Supported Devices: PXIe-5603/5605/5606 (external digitizer mode), PXIe-5665/5667/5668     ',
            'note': ' Setting this attribute to NIRFSA_VAL_LO_YIG_MAIN_COIL_DRIVE_FAST allows the '
        },
        'enum': 'LoYIGMainCoilDrive',
        'name': 'LO_YIG_MAIN_COIL_DRIVE',
        'type': 'ViInt32'
    },
    1150136: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns whether a preselector is available on the RF downconverter module. \n\n Default Value: N/A \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5840/5841     '
        },
        'name': 'PRESELECTOR_PRESENT',
        'type': 'ViBoolean'
    },
    1150137: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns whether an RF preamplifier is available on the downconverter module.\n\n  Default Value: N/A \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'RF_PREAMP_PRESENT',
        'type': 'ViBoolean'
    },
    1150139: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the location in a path where a calibration tone is injected or whether  the tone is disabled. \n\n Default Value: NIRFSA_VAL_CAL_TONE_DISABLED  \n\n Supported Devices: PXIe-5603/5605/5606 (external digitizer mode), PXIe-5665/5667/5668      '
        },
        'enum': 'CalToneMode',
        'name': 'DOWNCONVERTER_CAL_TONE_MODE',
        'type': 'ViInt32'
    },
    1150140: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the frequency of the RF downconverter calibration tone, in hertz (Hz).\n\n  Valid Values: 134 MHz to 13.2 GHz \n\n Default Value: 612.5 MHz \n\n Supported Devices: PXIe-5603/5605/5606 (external digitizer mode), NI, 5665/5667/5668      '
        },
        'name': 'DOWNCONVERTER_CAL_TONE_FREQUENCY',
        'type': 'ViReal64'
    },
    1150141: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the IF attenuation table to be used for external calibration. This attribute is  valid only in a calibration session. \n\n Default Value: NIRFSA_VAL_EXT_CAL_IF_ATTENUATION_TABLE_STANDARD  \n\n Supported Devices: PXIe-5603/5605     '
        },
        'enum': 'CalIFAttenTableSelection',
        'name': 'CAL_IF_ATTENUATION_TABLE_SELECTION',
        'type': 'ViInt32'
    },
    1150142: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the minimum adjacent channel power ratio (ACPR), in dB, relative to the main channel reference level.  This attribute configures NI-RFSA to optimize downconverter gain to measure a lower power adjacent channel, adding  gain only after filtering the main channel. The gain NI-RFSA applies is always less than or equal to the ACPR value you specify.  attribute to a value less than 300 kHz. For the PXIe-5665 (14 GHz), this attribute is supported only if you set the NIRFSA_ATTR_DEVICE_INSTANTANEOUS_BANDWIDTH  or NIRFSA_ATTR_SPECTRUM_SPAN attribute to a value less than 300 kHz by using the 300 kHz IF filter, or to a value  between 300 kHz and 5 MHz by using the 5 MHz IF filter. \n\n NI-RFSA coerces this attribute to zero for the PXI-5600, PXIe-5601 and the PXIe-5667. For all other devices, read the coerced value  of this attribute to determine the actual amount of gain applied. \n\n Default Value: 0 \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXI-5661, PXIe-5663/5663E/5665/5667/5668     ',
            'note': ' For the PXIe-5665 (3.6 GHz), this attribute is supported only if you set the NIRFSA_ATTR_DEVICE_INSTANTANEOUS_BANDWIDTH or NIRFSA_ATTR_SPECTRUM_SPAN '
        },
        'name': 'MINIMUM_ACPR',
        'type': 'ViReal64'
    },
    1150144: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the oversampling ratio used by the the digitizer onboard signal processing (OSP)  when you are in spectrum acquisition mode. This attribute allows you to acquire a larger  bandwidth in hardware and reduce that bandwidth in software, decreasing the possibility of hardware data path overflows. \n\n PXIe-5644/5645/5646: The only valid value for this attribute is 1. Default Value: 1.0 \n\n Supported Devices: PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'SPECTRUM_OSP_SAMPLING_RATIO',
        'type': 'ViReal64'
    },
    1150146: {
        'access': 'read-write',
        'documentation': {
            'description': ' Overrides the internal gain self-calibration correction for the IF filter through path  with the value you set for this attribute. \n\n Default Value: 0 \n\n Supported Devices: PXIe-5603/5605      '
        },
        'name': 'CALIBRATION_CORRECTION_THROUGH_FILTER',
        'type': 'ViReal64'
    },
    1150147: {
        'access': 'read-write',
        'documentation': {
            'description': ' Overrides the internal gain self-calibration correction for the 300 kHz IF filter path  with the value you set for this attribute.\n\n Default Value: 0 \n\n Supported Devices: PXIe-5603/5605/5606      '
        },
        'name': 'CALIBRATION_CORRECTION_300_KHZ_FILTER',
        'type': 'ViReal64'
    },
    1150148: {
        'access': 'read-write',
        'documentation': {
            'description': ' Overrides the internal gain self-calibration correction for the 5 MHz IF filter path  with the value you set for this attribute.\n\n Default Value: 0 \n\n Supported Devices: PXIe-5603/5605/5606      '
        },
        'name': 'CALIBRATION_CORRECTION_5_MHZ_FILTER',
        'type': 'ViReal64'
    },
    1150149: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the RF input channel is AC- or DC-coupled on a downconverter. \n\n is present and set to NIRFSA_VAL_DC when the DC block is not present to ensure device  specifications are met and to ensure the use of proper calibration data. For more  information about removing or attaching the DC block on the PXIe-5605, refer to the  PXIe-5665 Theory of Operation topic, the PXIe-5605 RF Downconverter Front Panel topic, or the PXIe-5667 Theory of Operation topic  in this help file. \n\n Default Value: NIRFSA_VAL_AC \n\n Supported Devices: PXIe-5603/5605/5606 (external digitizer mode), PXIe-5665/5667/5668     ',
            'note': ' For the PXIe-5605/5606/5665/5667/5668, this attribute must be set to NIRFSA_VAL_AC when the DC block '
        },
        'enum': 'ChannelCoupling',
        'name': 'CHANNEL_COUPLING',
        'type': 'ViInt32'
    },
    1150151: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the scaling factor applied to the time-domain voltage data in the IF digitizer. Use this attribute to maximize  the dynamic range of the digitizer by increasing the maximum IF power the ADC can measure without creating OSP overflows.  Because of the device amplitude response, some wide-band signals normally attenuated by the signal analyzer go through the  IF digitizer without causing an ADC overflow warning. During IF equalization, these wide-band digitizer input signals may become  mathematically amplified. These amplified input signal values overflow the available numeric range used in the signal processing algorithm.  You can use this attribute when OSP calculations would generate an overflow while applying digital filters to the data.  The OSP module in the digitizer multiplies the time-domain signal amplitude, in volts, by the specified attribute value before  further onboard processing. Set this attribute to a value less than 1 to avoid OSP overflow for near full-scale IF signals and to  use the maximum dynamic range of the digitizer. NI-RFSA compensates for the specified OSP data scaling factor to ensure that the  correct scaled data, in absolute levels, is always returned regardless of the value of this attribute. \n\n Valid Values: 0.25 to 1.0 \n\n Default Values:\n PXI-5661, PXIe-5663/5663E/5665 (3.6 GHz)/5667 (3.6 GHz)/5668, PXIe-5820/5830/5831/5840/5841: 1.0 \n PXIe-5665 (14 GHz))/5667 (7 GHz): 0.8 \n Supported Devices: PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841    '
        },
        'name': 'OSP_DATA_SCALING_FACTOR',
        'type': 'ViReal64'
    },
    1150154: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to allow the device to acquire more records than can fit in the device memory of the PXIe-5622/5624. \n\n NI-RFSA returns an error. If this attribute is set to TRUE, NI-RFSA returns an error only in the event of an acquisition buffer overflow.\n\n Default Value: VI_FALSE  \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     ',
            'note': ' This attribute is always set to VI_TRUE for the PXIe-5644/5645/5646 and the PXIe-5820/5830/5831/5840/5841. \n\n'
        },
        'name': 'ALLOW_MORE_RECORDS_THAN_MEMORY',
        'type': 'ViBoolean'
    },
    1150155: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the step size for the RF attenuation level. The actual RF attenuation is coerced up to the  next highest multiple of this step size.  You can also set this value to change the step size for the device within the supported device precision and configuration. \n\n PXI-5600-The device configuration supports only the following attenuation step size values: 10, 20, 30, 40, and 50. \n PXIe-5601-The attenuation is calculated based on the actual calibrated value closest to the  desired value, so the step size varies as the actual gain values vary between consecutive attenuation settings.\n PXIe-5603-The device configuration supports attenuation changes in 1 dB steps.\n PXIe-5605-The available attenuation step size depends on the specified center frequency. In  the high band signal path (input frequencies greater than 3.6 GHz), the only available attenuation is the step attenuator  that you can change in 5 dB steps. In the low band signal path (input frequencies less than or  equal to 3.6 GHz), an additional 31 dB of solid-state attenuation is available in 1 dB steps.  The 5 dB default value indicates that, even when in the low band signal path, NI-RFSA changes the  attenuation in 5 dB steps using only the mechanical attenuator. You can use this attribute to affect  when the device changes the attenuation settings. To use the solid-state attenuation in the low band  signal path, change the step size to a value other than a multiple of 5 (for example, a step size of 1 dB).  If you use a value other than a multiple of 5 while in the high band of the PXIe-5605, NI-RFSA returns an error.\n\n Valid Values: \n PXI-5600/5661:10, 20, 30, 40, and 50 \n PXIe-5601/5663/5663E:0.0 to 93.0, continuous \n PXIe-5603/5665 (3.6 GHz):1.0 to 74.0, in 1 dB steps \n PXIe-5605/5665 (14 GHz) (low band), PXIe-5606/5668 (low band): 1.0 to 106.0, in 1 dB steps \n PXIe-5605/5665 (14 GHz) (high band), PXIe-5606/5668 (hight band): 5.0 to 75.0, in 5 dB steps \n PXIe-5667 (3.6 GHz) using the PXIe-5693 RF preselector low frequency bypass path—1.0 to 74.0, in 1 dB steps \n PXIe-5667 (3.6 GHz) using the PXIe-5693 RF preselector filter path— 1.0 \n PXIe-5667 (7 GHz) using the PXIe-5693 preselector low frequency bypass path— 1.0 to 106.0 in 1 dB steps \n PXIe-5667 7 GHz) using the PXIe-5693 RF preselector filter path— 1.0 \n\n Default Value: \n PXI-5600/5661: 10.0 \n PXIe-5601/5663/5663E: 0.0 \n PXIe-5603/5665 (3.6 GHz): 1.0 \n PXIe-5605/5665 (14 GHz): 5.0 \n PXIe-5667—1.0 \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXI-5661, PXIe-5663/5663E/5665/5667/5668     '
        },
        'name': 'RF_ATTENUATION_STEP_SIZE',
        'type': 'ViReal64'
    },
    1150157: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable or disable the step gain amplifier. \n\n Default Value: NIRFSA_VAL_STEP_GAIN_DISABLED \n\n Supported Devices: PXIe-5694      '
        },
        'enum': 'StepGainEnabled',
        'name': 'STEP_GAIN_ENABLED',
        'type': 'ViInt32'
    },
    1150158: {
        'access': 'read-write',
        'name': '5665_PRESELECTOR_TUNING_DAC_VALUE',
        'type': 'ViInt32'
    },
    1150159: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the temperature, in degrees Celsius, that NI-RFSA uses to calculate the device configuration settings. \n\n temperature to calculate best attenuation settings. Set this attribute only if you want NI-RFSA to maintain the same device configuration settings from acquisition to acquisition, independent  of device temperature changes.\n\n PXIe-5820/5830/5831/5840/5841- This attribute is read-only. \n\n Units:  degrees C \n\n Default Value: N/A \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5663/5663E/5665/5667/5668, PXIe-5693/5694, PXIe-5820/5830/5831/5840/5841     ',
            'note': ' For most applications, you can choose not to set this attribute, so NI-RFSA uses the device '
        },
        'name': 'DEVICE_CONFIGURATION_TEMPERATURE',
        'type': 'ViReal64'
    },
    1150160: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether all signal conditioning is enabled on the PXIe-5694. \n\n NI-RFSA bypasses all signal conditioning, prevents any signal downconversion,  and fixes the values for NIRFSA_ATTR_DOWNCONVERTER_GAIN attribute, the  NIRFSA_ATTR_DEVICE_INSTANTANEOUS_BANDWIDTH attribute, and the NIRFSA_ATTR_IF_FILTER_BANDWIDTH attribute. \n\n Default Value: NIRFSA_VAL_SIGNAL_CONDITIONING_ENABLED \n\n Supported Devices: PXIe-5694     ',
            'note': ' If you set this attribute to NIRFSA_VAL_SIGNAL_CONDITIONING_BYPASSED, '
        },
        'enum': 'SignalConditioningEnabled',
        'name': 'SIGNAL_CONDITIONING_ENABLED',
        'type': 'ViInt32'
    },
    1150161: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether downconversion to 21.4 MHz is enabled for the IF conditioning module.  The IF output frequency is 21.4 MHz when you enable this attribute, and it is 193.6 MHz  when you disable this attribute. \n\n NIRFSA_VAL_SIGNAL_CONDITIONING_BYPASSED, you cannot set the  NIRFSA_ATTR_IF_CONDITIONING_DOWN_CONVERSION_ENABLED attribute to NIRFSA_VAL_ENABLED. \n\n Default Values: NIRFSA_VAL_DISABLED \n\n Supported Devices: PXIe-5667, PXIe-5694     ',
            'note': ' For the PXI-5661, PXIe-5663/5663E/5665, the only valid value for this attribute is NIRFSA_VAL_DISABLED. \n\n'
        },
        'enum': 'EnabledAttr',
        'name': 'IF_CONDITIONING_DOWN_CONVERSION_ENABLED',
        'type': 'ViInt32'
    },
    1150162: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the source for the LO to be used to downconvert. If this attribute is set to  (empty string),  NI-RFSA uses the internal LO source. \n If no signal down conversion is required, this attribute will be ignored. \n\n To use this attribute for the PXIe-5830/5831, you must use the channelName parameter of the niRFSA_SetAttributeViString  function to specify the name of the channel you are configuring. You can configure the LO1 and LO2 channels by using lo1  or lo2 as the channel string, or set the channel string to lo1,lo2 to configure both channels. For all other devices,  the only valid value for the channel string is  (empty string). \n\n Default Value: NIRFSA_VAL_ONBOARD_STR Supported Devices: PXIe-5644/5645/5646, PXIe-5694, PXIe-5830/5831/5840/5841     ',
            'note': ' For the PXIe-5841 with PXIe-5655, RF list mode is not supported when this attribute is set to NIRFSA_VAL_LO_SOURCE_SG_SA_SHARED_STR. \n\n'
        },
        'enum': 'LoSourceSelection',
        'name': 'LO_SOURCE',
        'type': 'ViString'
    },
    1150163: {
        'access': 'read-write',
        'documentation': {
            'description': ' Configures the amplitude settling accuracy in decibels. \n NI-RFSA waits until the RF path settles within the specified accuracy level after calling the niRFSA_Initiate function. \n Any specified amplitude settling value that is above the acceptable minimum value is coerced down to the closest valid value. \n Units: dB \n\n Default Value: 0.5 \n\n Supported Devices: PXIe-5644/5645/5646, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'AMPLITUDE_SETTLING',
        'type': 'ViReal64'
    },
    1150164: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute is not for customer use. \n\n     '
        },
        'name': 'DDC_REF_TRIGGER_OVERRIDE',
        'type': 'ViBoolean'
    },
    1150165: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute is not for customer use. \n\n Default Value: 0 \n\n     '
        },
        'name': 'MINIMUM_RECONFIG_TIME',
        'type': 'ViReal64'
    },
    1150166: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the RF preselector filter to use. \n\n Default Values: \n PXIe-5667, PXIe-5693: NIRFSA_VAL_RF_PRESELECTOR_FILTER_PATH_9 \n PXIe-5665: NIRFSA_VAL_RF_PRESELECTOR_FILTER_PATH_NONE \n\n Supported Devices: PXIe-5665/5667, PXIe-5693     ',
            'note': ' You can write to this attribute when using only the PXIe-5693 as a stand-alone device. \n\n '
        },
        'enum': 'RfPreselectorFilter',
        'name': 'RF_PRESELECTOR_FILTER',
        'type': 'ViInt32'
    },
    1150167: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the notch filter is enabled on the RF conditioning module. \n\n Default Value: NIRFSA_VAL_NOTCH_FILTER_DISABLED \n\n Supported Devices: PXI-5661, PXIe-5663/5663E/5665/5667, PXIe-5693     '
        },
        'enum': 'NotchFilterEnabled',
        'name': 'NOTCH_FILTER_ENABLED',
        'type': 'ViInt32'
    },
    1150168: {
        'access': 'read-write',
        'name': 'CAL_TONE_STEP_ATTENUATION',
        'type': 'ViReal64'
    },
    1150169: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the FFT width of the device. The FFT width is the effective bandwidth of the signal  path during each signal acquisition.\n\n depending on the digitizer option you purchased.\n\n For more information about in-band retuning, refer to the  NIRFSA_ATTR_DOWNCONVERTER_CENTER_FREQUENCY attribute.\n\n NI-RFSA treats the device instantaneous bandwidth as the effective real-time bandwidth  of the signal path. The span specifies the frequency range of the computed spectrum.  An RF vector signal analyzer can acquire a bandwidth only within the device instantaneous  bandwidth frequency. If the span you choose is greater than the device instantaneous bandwidth,  NI-RFSA obtains multiple acquisitions and combines them into a single spectrum. By specifying  the FFT width, you can control the specific bandwidth obtained in each signal acquisition.  If you read the NIRFSA_ATTR_FFT_WIDTH attribute without setting it, NI-RFSA returns the  value of the NIRFSA_ATTR_DEVICE_INSTANTANEOUS_BANDWIDTH attribute.\n\n Valid Values:\n The lower limit for all FFT width supported devices is 7.325 kHz.\n\n PXIe-5663/5663E—The FFT width upper limit for the PXIe-5663/5663E depends on the  downconverter center frequency and on the module revision of the PXIe-5601 as illustrated  in the NIRFSA_ATTR_FFT_WIDTH attribute topic in the NI RF Vector Signal Analyzers help file. Refer to the  Identifying Module Revision topic for more information about determining which revision of  the PXIe-5601 RF downconverter you have installed. \n\n PXIe-5665/5667/5668—The upper limit of the FFT width is the maximum device instantaneous bandwidth.\n\n NI-RFSA determines the appropriate IF filter to use based on the value that you set  for the FFT width and your specific device. Refer to the NIRFSA_ATTR_FFT_WIDTH  topic in the NI RF Vector Signal Analzyers help for more information about the IF filters NI-RFSA uses with  the NIRSA_ATTR_FFT_WIDTH attribute.\n\n If you set the NIRFSA_ATTR_DEVICE_INSTANTANEOUS_BANDWIDTH attribute, NI-RFSA selects the appropriate  IF filter based on the NIRFSA_ATTR_DEVICE_INSTANTANEOUS_BANDWIDTH attribute and the NIRFSA_ATTR_FFT_WIDTH  attribute determines how much bandwidth of that filter is used during acquisition. Refer to the  NIRFSA_ATTR_DEVICE_INSTANTANEOUS_BANDWIDTH attribute to determine which IF filter corresponds to the  NIRFSA_ATTR_DEVICE_INSTANTANEOUS_BANDWIDTH attribute setting.\n\n 47 MHz at -6 dB with the preselector enabled. The NIRFSA_ATTR_FFT_WIDTH attribute can override  the typical bandwidth of the PXIe-5605 up to 57 MHz using an external digitizer and up to 50 MHz  or 25 MHz depending on the PXIe-5622 digitizer option you purchased. The increase in bandwidth  results in faster signal acquisitions, but amplitude accuracy is decreased for spectrum  acquisitions, and magnitude and phase accuracy is decreased for I/Q acquisitions. National Instruments does not guarantee device specifications if you set the NIRFSA_ATTR_FFT_WIDTH  attribute greater than the warranted instantaneous bandwidth specification.\n\n and above. \n\n Default Value: N/A \n\n Supported Devices: PXIe-5663/5663E/5665/5667/5668     ',
            'note': ' When using the PXIe-5606, the 765 MHz IF filter is only available at center frequencies of 3.6 GHz '
        },
        'name': 'FFT_WIDTH',
        'type': 'ViReal64'
    },
    1150170: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether input isolation is enabled.\n\n Enabling this attribute isolates the input signal at the RF IN connector on the RF downconverter  from the rest of the RF downconverter signal path. Disabling this attribute reintegrates the  input signal into the RF downconverter signal path.\n\n characteristic 50 Ohm impedance. A change in the device impedance may also cause a VSWR value  higher than the device specifications.\n\n For the PXIe-5830/5831, input isolation is supported for all available ports for your hardware configuration. \n\n Default Values: NIRFSA_VAL_DISABLED, if the device configuration is supported. \n Supported Devices: PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5663/5663E/5665/5667/5668, PXIe-5693, PXIe-5820/5830/5831/5840/5841     ',
            'note': ' If you enable input isolation for your device, the device impedance is changed from the '
        },
        'enum': 'EnabledAttr',
        'name': 'INPUT_ISOLATION_ENABLED',
        'type': 'ViInt32'
    },
    1150172: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute is not for customer use. \n\n     '
        },
        'enum': 'EnabledAttr',
        'name': 'CONTIGUOUS_MULTIRECORD',
        'type': 'ViInt32'
    },
    1150173: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute is not for customer use. \n\n     '
        },
        'name': 'TIMER_START_SOURCE',
        'type': 'ViString'
    },
    1150174: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the power of a virtual signal connected to the RF IN connector on the  PXIe-5693 front panel when the calibration tone is enabled. \n You can enable a calibration tone for the PXIe-5693 by setting the  NIRFSA_ATTR_RF_CONDITIONING_CAL_TONE_MODE attribute to  NIRFSA_VAL_CAL_TONE_LOWBAND_RF or NIRFSA_VAL_CAL_TONE_HIGHBAND_RF. \n\n Units: dBm \n\n Default Value: N/A \n\n Supported Devices: PXIe-5693       '
        },
        'name': 'CAL_TONE_POWER_REFERRED_TO_RF_IN',
        'type': 'ViReal64'
    },
    1150175: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute is not for customer use. \n\n     '
        },
        'name': 'START_TRIGGER_DELAY',
        'type': 'ViReal64'
    },
    1150176: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the device is the master for synchronizing the shared  Start Trigger between multiple devices. The master device distributes the  synchronized Start Trigger to all devices in the system through the  Start Trigger distribution line. \n\n When synchronizing the Start Trigger, one device must always be designated  as the master. When the device is configured as a master, it actively drives  the Start Trigger distribution line. When the device is configured as a slave,  set the NIRFSA_ATTR_START_TRIGGER_TYPE attribute to NIRFSA_VAL_DIGITAL_EDGE,  and the NIRFSA_ATTR_DIGITAL_EDGE_START_TRIGGER_SOURCE attribute to NIRFSA_VAL_SYNC_START_TRIGGER_STR. \n\n Refer to the Synchronization Using NI-RFSA and NI-RFSG topic appropriate to your  device in the NI RF Vector Signal Analyzers Help for more information about  device synchronization for vector signal transceivers.\n\n Default Value: VI_FALSE \n\n Supported Devices: PXIe-5644/5645 '
        },
        'name': 'SYNC_START_TRIGGER_MASTER',
        'type': 'ViBoolean'
    },
    1150177: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies which external trigger line distributes the synchronized Start  Trigger signal. When synchronizing the Start Trigger, configure all  devices to use the same Start Trigger distribution line. \n\n Refer to the Synchronization Using NI-RFSA and NI-RFSG topic appropriate to your  device in the NI RF Vector Signal Analyzers Help for more information about  device synchronization for vector signal transceivers.\n\n Valid Values: PXI_Trig0, PXI_Trig1, PXI_Trig2, PXI_Trig3, PXI_Trig4,  PXI_Trig5, PXI_Trig6, PXI_Trig7, PFI0 \n\n Default Value:  (empty string) \n\n Supported Devices: PXIe-5644/5645 '
        },
        'name': 'SYNC_START_TRIGGER_DIST_LINE',
        'type': 'ViString'
    },
    1150178: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the device is the master for synchronizing the shared  Reference Trigger between multiple devices. The master device distributes  the synchronized Reference Trigger to all devices in the system through  the Reference Trigger distribution line. \n\n When synchronizing the Reference Trigger, one device must always be designated  as the master. When the device is configured as a master, it actively drives  the Reference Trigger distribution line. When the device is configured as a  slave, set the NIRFSA_ATTR_REF_TRIGGER_TYPE attribute to NIRFSA_VAL_DIGITAL_EDGE,  and the NIRFSA_ATTR_DIGITAL_EDGE_REF_TRIGGER_SOURCE attribute to NIRFSA_VAL_SYNC_REF_TRIGGER_STR. \n\n Refer to the Synchronization Using NI-RFSA and NI-RFSG topic appropriate to your  device in the NI RF Vector Signal Analyzers Help for more information about  device synchronization for vector signal transceivers.\n\n Default Value: VI_FALSE \n\n Supported Devices: PXIe-5644/5645 '
        },
        'name': 'SYNC_REF_TRIGGER_MASTER',
        'type': 'ViBoolean'
    },
    1150179: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies which external trigger line distributes the synchronized  Reference Trigger signal. When synchronizing the Reference Trigger,  configure all devices to use the same Reference Trigger distribution line. \n\n Refer to the Synchronization Using NI-RFSA and NI-RFSG topic appropriate to your  device in the NI RF Vector Signal Analyzers Help for more information about  device synchronization for vector signal transceivers.\n\n Valid Values: PXI_Trig0, PXI_Trig1, PXI_Trig2, PXI_Trig3, PXI_Trig4,  PXI_Trig5, PXI_Trig6, PXI_Trig7, PFI0 \n\n Default Value:  (empty string) \n\n Supported Devices: PXIe-5644/5645 \n\n '
        },
        'name': 'SYNC_REF_TRIGGER_DIST_LINE',
        'type': 'ViString'
    },
    1150180: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the connector(s) to use to acquire the signal.  To set this attribute, the NI-RFSA device must be in the  Configuration state. \n\n Default Values: \n\n PXIe-5820: NIRFSA_VAL_IQ_IN \n All other devices: NIRFSA_VAL_RF_IN \n Supported Devices: PXIe-5644/5645/5646, PXIe-5820/5830/5831/5840/5841 '
        },
        'enum': 'InputPort',
        'name': 'INPUT_PORT',
        'type': 'ViInt32'
    },
    1150181: {
        'access': 'read-write',
        'documentation': {
            'description': ' Configures the frequency of the signal. The onboard signal  processing (OSP) will frequency shift the signal at this  frequency to baseband prior to acquiring it. \n\n Valid Values:  \n PXIe-5645: -60 MHz to +60 MHz \n PXIe-5820: -500 MHz to +500 MHz \n Default Value: 0 \n\n Supported Devices: PXIe-5645, PXIe-5820 \n\n ',
            'note': ' For the PXIe-5645, this attribute is ignored if you are using the RF ports. \n'
        },
        'name': 'IQ_IN_PORT_CARRIER_FREQUENCY',
        'type': 'ViReal64'
    },
    1150182: {
        'access': 'read-write',
        'documentation': {
            'description': ' Configures the terminal configuration of the I/Q terminals. \n\n To use this attribute, you must use the channelname parameter of the niRFSA_SetAttributeViInt32 function  to specify the name of the channel you are configuring. For the PXIe-5645, you can configure the I and Q  channels by using I or Q as the channel string, or set the channel string to  (empty string) to configure both channels.  For the PXIe-5820, the only valid value for the channel string is  (empty string). \n\n PXIe-5820-The only valid value for this attribute is NIRFSA_VAL_DIFFERENTIAL. \n Default Value: NIRFSA_VAL_DIFFERENTIAL Supported Devices: PXIe-5645, PXIe-5820 ',
            'note': ' For the PXIe-5645, this attribute is ignored if you are using the RF ports. \n\n'
        },
        'enum': 'IqInPortTermConfig',
        'name': 'IQ_IN_PORT_TERMINAL_CONFIGURATION',
        'type': 'ViInt32'
    },
    1150183: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the voltage range for the I/Q terminals. \n\n To use this attribute, you must use the channelname parameter of the niRFSA_SetAttributeViReal64 function  to specify the name of the channel you are configuring. For the PXIe-5645, you can configure the I and Q  channels by using I or Q as the channel string, or set the channel string to  (empty string) to configure both channels.  For the PXIe-5820, the only valid value for the channel string is  (empty string). \n\n The voltage range in differential mode is configurable from 2 Vpk-pk to 0.032 Vpk-pk in  1 dB steps. In single-ended mode, valid ranges are half those for  differential. Values are always coerced up to the next valid range. \n\n Valid Values: \n PXIe-5645: 0 Vpk-pk to 2 Vpk-pk for differential terminal configuration,  0 Vpk-pk to 1 Vpk-pk for single-ended terminal configuration. \n PXIe-5820: 0 Vpk-pk to 4 Vpk-pk for differential terminal configuration. \n Default Value: 2 Vpk-pk \n\n Supported Devices: PXIe-5645, PXIe-5820 \n\n ',
            'note': ' For the PXIe-5645, this attribute is ignored if you are using the RF ports. \n\n'
        },
        'name': 'IQ_IN_PORT_VERTICAL_RANGE',
        'type': 'ViReal64'
    },
    1150184: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the device is the master for synchronizing the  shared Advance Trigger between multiple devices. The master device  distributes the synchronized Advance Trigger to all devices in the  system through the Advance Trigger distribution line. \n\n When synchronizing the Advance Trigger, one device must always be designated  as the master. When the device is configured as a master, it actively drives  the Advance Trigger distribution line. When the device is configured as a slave,  set the NIRFSA_ATTR_ADVANCE_TRIGGER_TYPE attribute to NIRFSA_VAL_DIGITAL_EDGE,  and the NIRFSA_ATTR_DIGITAL_EDGE_ADVANCE_TRIGGER_SOURCE attribute to  NIRFSA_VAL_SYNC_ADVANCE_TRIGGER_STR. \n\n Refer to the Synchronization Using NI-RFSA and NI-RFSG topic appropriate to your  device in the NI RF Vector Signal Analyzers Help for more information about  device synchronization for vector signal transceivers.\n\n Default Value: VI_FALSE \n\n Supported Devices: PXIe-5644/5645 '
        },
        'name': 'SYNC_ADVANCE_TRIGGER_MASTER',
        'type': 'ViBoolean'
    },
    1150185: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies which external trigger line distributes the synchronized Advance  Trigger signal. When synchronizing the Advance Trigger, configure all  devices to use the same Advance Trigger distribution line. \n\n Refer to the Synchronization Using NI-RFSA and NI-RFSG topic appropriate to your  device in the NI RF Vector Signal Analyzers Help for more information about  device synchronization for vector signal transceivers.\n\n Valid Values: PXI_Trig0, PXI_Trig1, PXI_Trig2, PXI_Trig3, PXI_Trig4,  PXI_Trig5, PXI_Trig6, PXI_Trig7, PFI0 \n\n Default Value:  (empty string) \n\n Supported Devices: PXIe-5644/5645 \n\n '
        },
        'name': 'SYNC_ADVANCE_TRIGGER_DIST_LINE',
        'type': 'ViString'
    },
    1150186: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns the power level, in dBm, expected at the LO IN terminal  when the NIRFSA_ATTR_LO_SOURCE attribute is set to NIRFSA_VAL_LO_IN_STR. Supported Devices: PXIe-5644/5645/5646, PXIe-5830/5831/5840/5841 ',
            'note': ' For the PXIe-5644/5645/5646, this attribute is always read-only. \n\n'
        },
        'name': 'LO_IN_POWER',
        'type': 'ViReal64'
    },
    1150187: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to use fractional mode for the LO PLL or not. Fractional mode  gives a finer frequency step resolution, but may result in non-harmonic spurs.  Refer to the PXIe-5644 Specifications or the PXIe-5645 Specifications  for more information about fractional mode and non harmonic spurs. \n\n For the PXIe-5841 with PXIe-5655, this attribute is ignored if the PXIe-5655 is used as the LO source. \n\n applicable when using the internal LO. \n\n To use this attribute for the PXIe-5830/5831, you must use the channelName parameter of the niRFSA_SetAttributeViInt32  function to specify the name of the channel you are configuring. You can configure the LO1 and LO2 channels by using lo1  or lo2 as the channel string, or set the channel string to lo1,lo2 to configure both channels. For all other devices,  the only valid value for the channel string is  (empty string). \n\n Default Value: NIRFSA_VAL_ENABLED \n\n Supported Devices: PXIe-5644/5645/5646, PXIe-5830/5831/5840/5841 \n\n ',
            'note': ' The NIRFSA_ATTR_LO_PLL_FRACTIONAL_MODE_ENABLED attribute is only '
        },
        'enum': 'EnabledAttr',
        'name': 'LO_PLL_FRACTIONAL_MODE_ENABLED',
        'type': 'ViInt32'
    },
    1150188: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the step size for tuning the local oscillator (LO) phase-locked loop (PLL). \n\n The LO frequency can only be tuned by multiples of the NIRFSA_ATTR_LO_FREQUENCY_STEP_SIZE  attribute. The LO frequency can therefore be offset from the requested  center frequency by as much as half of the NIRFSA_ATTR_LO_FREQUENCY_STEP_SIZE  attribute. This offset is corrected by digitally frequency shifting the  NIRFSA_ATTR_LO_FREQUENCY attribute to the value requested in either the  NIRFSA_ATTR_IQ_CARRIER_FREQUENCY attribute or the NIRFSA_ATTR_SPECTRUM_CENTER_FREQUENCY attribute. \n\n When the NIRFSA_ATTR_LO_PLL_FRACTIONAL_MODE_ENABLED attribute is set to  NIRFSA_VAL_ENABLED, the NIRFSA_ATTR_LO_FREQUENCY_STEP_SIZE attribute can  accept any value from 50 kHz to 24 MHz. \n\n When the NIRFSA_ATTR_LO_PLL_FRACTIONAL_MODE_ENABLED attribute is set to  NIRFSA_VAL_DISABLED, the NIRFSA_ATTR_LO_FREQUENCY_STEP_SIZE attribute is  coerced to 4 MHz, 5 MHz, 6 MHz, 12 MHz or 24 MHz. \n\n Refer to the Instrument Configurations topic for more information about available ports for your hardware configuration. \n\n Default Values: \n\n PXIe-5644/5645/5646: 200 kHz \n PXIe-5830: 2 MHz \n PXIe-5831 (RF port): 8 MHz \n PXIe-5831 (IF port): 2 MHz, 4 MHz \n PXIe-5840/5841 (fractional mode): 500 kHz \n PXIe-5840/5841 (integer mode): 10 MHz for frequencies less than or equal to 4 GHz. 20 MHz for frequencies greater than 4 GHz.\n PXIe-5841 with PXIe-5655: 500 kHz \n Supported Devices: PXIe-5644/5645/5646, PXIe-5830/5831/5840/5841 ',
            'note': ' The default value for the PXIe-5831 depends on the frequency range of the selected port for your instrument configuration. '
        },
        'name': 'LO_FREQUENCY_STEP_SIZE',
        'type': 'ViReal64'
    },
    1150189: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the Reference Trigger is delayed with the data. Set this  attribute to NIRFSA_VAL_DISABLED when the NIRFSA_ATTR_REF_TRIGGER_TYPE  attribute is set to NIRFSA_VAL_IQ_POWER_EDGE or NIRFSA_VAL_IQ_ANALOG_EDGE. \n\n Refer to the Synchronization Using NI-RFSA and NI-RFSG topic appropriate to your  device in the NI RF Vector Signal Analyzers Help for more information about  device synchronization for vector signal transceivers.\n\n Default Value: NIRFSA_VAL_DISABLED \n\n Supported Devices: PXIe-5644/5645 \n\n '
        },
        'enum': 'EnabledAttr',
        'name': 'SYNC_REF_TRIGGER_DELAY_ENABLED',
        'type': 'ViInt32'
    },
    1150191: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the sub-sample delay, in seconds, to apply to the  acquired signal. To set this property, the NI-RFSA device  must be in the Configuration state. \n\n Valid Values: -4.16 ns to +4.16 ns \n\n Default Value: 0 \n\n Supported Devices: PXIe-5644/5645 '
        },
        'name': 'DECIMATION_DELAY',
        'type': 'ViReal64'
    },
    1150192: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the channel from which the device monitors the trigger.  Use a value of I to monitor the I channel. Use a value of Q to monitor  the Q channel. Use a value of IQ to monitor both I and Q channels.  This attribute affects the device operation only when the  NIRFSA_ATTR_REF_TRIGGER_TYPE attribute is set to NIRFSA_VAL_IQ_ANALOG_EDGE. \n\n Valid Values: I, Q, IQ, QI \n\n Default Value: I \n\n Supported Devices: PXIe-5644/5645 '
        },
        'name': 'IQ_ANALOG_EDGE_REF_TRIGGER_SOURCE',
        'type': 'ViString'
    },
    1150193: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the device asserts the trigger when the voltage level is  rising or falling. When you set the NIRFSA_ATTR_REF_TRIGGER_TYPE attribute  to NIRFSA_VAL_IQ_ANALOG_EDGE, the device asserts the trigger when the signal  level exceeds the specified level with the slope you specify. This attribute  affects the device operation only when the NIRFSA_ATTR_REF_TRIGGER_TYPE  attribute is set to NIRFSA_VAL_IQ_ANALOG_EDGE. \n\n Default Value: NIRFSA_VAL_RISING_SLOPE \n\n Supported Devices: PXIe-5644/5645 '
        },
        'enum': 'AnalogSlope',
        'name': 'IQ_ANALOG_EDGE_REF_TRIGGER_SLOPE',
        'type': 'ViInt32'
    },
    1150194: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the analog level, in volts, at which the device triggers.  The device asserts the trigger when the signal exceeds the level  specified by the value of this property, taking into consideration  the specified slope. This attribute affects the device operation only  when the NIRFSA_ATTR_REF_TRIGGER_TYPE attribute is set to NIRFSA_VAL_IQ_ANALOG_EDGE. \n\n Default Value: 0 V \n\n Supported Devices: PXIe-5644/5645 '
        },
        'name': 'IQ_ANALOG_EDGE_REF_TRIGGER_LEVEL',
        'type': 'ViReal64'
    },
    1150195: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the size of the hysteresis window on either side of the trigger  level. The device triggers when the signal passes through the threshold  you specify with the NIRFSA_ATTR_IQ_ANALOG_EDGE_REF_TRIGGER_LEVEL attribute,  has the slope you specify with the NIRFSA_ATTR_IQ_ANALOG_EDGE_REF_TRIGGER_SLOPE  attribute, and passes through the hysteresis window that you specify with this  attribute. This attribute affects the device operation only when the  NIRFSA_ATTR_REF_TRIGGER_TYPE attribute is set to NIRFSA_VAL_IQ_ANALOG_EDGE. \n\n Valid Values: 0 to (Voltage Range/2 + Trigger Level) for Rising Slope.  0 to (Voltage Range/2 – Trigger Level) for Falling Slope. These values limit  the hysteresis to the entire voltage range that is below the trigger level for  Rising Slope or that is above the trigger level for Falling Slope.\n\n Default Value: The default is calculated by the driver as (Range x 0.025). \n\n Supported Devices: PXIe-5644/5645 \n\n '
        },
        'name': 'IQ_ANALOG_EDGE_REF_TRIGGER_HYSTERESIS',
        'type': 'ViReal64'
    },
    1150196: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the digitizer OSP block delays Reference triggers, along with the data  samples, moving through the OSP block or if the Reference triggers bypass the OSP block  and are processed immediately.\n\n Enabling this attribute requires the following equipment configurations:\n All digitizers being used must be the same model and hardware revision.\n All digitizers must use the same firmware.\n All digitizers must be configured with the same I/Q rate. \n All devices must use the same signal path. \n\n PXI-5661—The IF filters for the PXI-5661are determined by the incoming frequency.\n\n PXIe-5663/5663E—Read the value of the NIRFSA_ATTR_IF_FILTER attribute to determine the  IF filters used by the PXIe-5663/5663E.\n\n PXIe-5665/5667/5668—Refer to the device-specific information in the NIRFSA_ATTR_DEVICE_INSTANTANEOUS_BANDWIDTH attribute to determine the IF filters used by  the PXIe-5665/5667/5668. If you set the NIRFSA_ATTR_FFT_WIDTH attribute, refer to the device-specific  information for this attribute and the NIRFSA_ATTR_DEVICE_INSTANTANEOUS_BANDWIDTH attribute  to determine the IF filters used. For frequencies less than 3.6 GHz, set the  NIRFSA_ATTR_RF_PREAMP_ENABLED to the same value for all devices.\n\n PXIe-5665 14 GHz—Set the NIRFSA_ATTR_DOWNCONVERTER_PRESELECTOR_ENABLED to the same value for all devices.\n\n If the I/Q rate is set programmatically for I/Q acquisitions, the following attributes  should be identical for the best device synchronization:\n\n NIRFSA_ATTR_DIGITAL_IF_EQUALIZATION_ENABLED \n NIRFSA_ATTR_SPECTRUM_OSP_SAMPLING_RATIO \n\n For spectrum acquisitions, the following attributes should be identical for the  best device synchronization:\n\n NIRFSA_ATTR_SPECTRUM_SPAN \n NIRFSA_ATTR_RESOLUTION_BANDWIDTH_TYPE \n NIRFSA_ATTR_DIGITAL_IF_EQUALIZATION_ENABLED\n NIRFSA_ATTR_SPECTRUM_OSP_SAMPLING_RATIO \n\n For more information about the digitizer OSP block and reference triggers,  refer to the following topics in the NI High-Speed Digitizers Help:\n\n NI-5622 Onboard Signal Processing (OSP) \n NI-5142 Onboard Signal Processing (OSP) \n NI PXIe-5622 Trigger Sources \n NI PXI 5142 Trigger Sources \n NI PXIe-5622 Block Diagram \n NI PXI-5142 Trigger Sources \n Default Value: NIRFSA_VAL_ENABLED \n\n Supported Devices: PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'enum': 'EnabledAttr',
        'name': 'REF_TRIGGER_OSP_DELAY_ENABLED',
        'type': 'ViInt32'
    },
    1150203: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies an offset from the I/Q carrier frequency for the downconverter.  If you set this attribute, any measurements outside the instantaneous bandwidth  of the device are invalid. After you set this attribute, the RF downconverter is  locked to that frequency offset until the value is changed or the attribute is reset. \n\n Valid Values: \n\n PXIe-5646: -100 MHz to +100 MHz PXIe-5830/5831/5840/5841: -625 MHz to +625 MHz \n\n All other devices:  -42 MHz to +42 MHz \n\n Default Values: For spectrum acquisition types the driver automatically calculates  the default to avoid residual LO power. For I/Q acquisition types the default is 0 Hz.  If the center frequency is set to a non-multiple of the  NIRFSA_ATTR_SIGNAL_PATH_LO_FREQUENCY_STEP_SIZE attribute, the  NIRFSA_ATTR_DOWNCONVERTER_FREQUENCY_OFFSET attribute is set to compensate for the difference.\n\n Supported Devices: PXIe-5644/5645/5646, PXIe-5830/5831/5840/5841 '
        },
        'name': 'DOWNCONVERTER_FREQUENCY_OFFSET',
        'type': 'ViReal64'
    },
    1150204: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the temperature of the I/Q IN circuitry on the device. \n\n Units: degrees C \n\n Supported Devices: PXIe-5645, PXIe-5820 '
        },
        'name': 'IQ_IN_PORT_TEMPERATURE',
        'type': 'ViReal64'
    },
    1150205: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the IF filter path bandwidth for your device configuration. \n\n bandwidth includes all IF filters across the component modules of a composite device. \n\n Default Values: For spectrum acquisition types the default is greater than or  equal to the NIRFSA_ATTR_SPECTRUM_SPAN attribute. NI-RFSA chooses the default  value of the NIRFSA_ATTR_IF_FILTER_BANDWIDTH attribute to correspond to the  appropriate IF filter. For I/Q acquisition types NI-RFSA chooses the default  value corresponding to the widest IF filter possible for your equipment setup.\n\n Supported Devices: PXIe-5601/5603/5605/5606, PXIe-5663/5663E/5665/5667/5668, PXIe-5694     ',
            'note': ' For composite devices, such as the PXIe-5663/5663E/5665/5667, the IF filter path '
        },
        'name': 'IF_FILTER_BANDWIDTH',
        'type': 'ViReal64'
    },
    1150206: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the shape factor of the window used in the fast Fourier transform (FFT).  The Window Shape Factor is defined as ratio of the 60 dB to 6 dB bandwidths. \n\n Default Value: N/A \n\n Supported Devices: PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'FFT_WINDOW_SHAPE_FACTOR',
        'type': 'ViReal64'
    },
    1150207: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to use the low-frequency bypass path for the incoming RF signal. \n\n Default Value: NIRFSA_VAL_DISABLED \n\n Supported Devices: PXIe-5693, PXIe-5667     '
        },
        'enum': 'EnabledAttr',
        'name': 'LOW_FREQUENCY_BYPASS_ENABLED',
        'type': 'ViInt32'
    },
    1150208: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the location in a signal path where an RF conditioning calibration  tone is injected or whether the tone is disabled. \n\n Default Value: NIRFSA_VAL_CAL_TONE_DISABLED  \n\n Supported Devices: PXIe-5667, PXIe-5668, PXIe-5693/5698      '
        },
        'enum': 'ConditioningCalToneMode',
        'name': 'RF_CONDITIONING_CAL_TONE_MODE',
        'type': 'ViInt32'
    },
    1150209: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the frequency of the RF conditioning calibration tone, in hertz (Hz). \n\n  Valid Values: 34.5 MHz to 7.5 GHz \n\n Default Value: 612.5 MHz \n\n Supported Devices: PXIe-5667, PXIe-5668, PXIe-5693/5698      '
        },
        'name': 'RF_CONDITIONING_CAL_TONE_FREQUENCY',
        'type': 'ViReal64'
    },
    1150210: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the current temperature, in degrees Celsius, of the IF conditioning module. \n\n Default Value: N/A \n\n Supported Devices: PXIe-5667     '
        },
        'name': 'IF_CONDITIONING_TEMPERATURE',
        'type': 'ViReal64'
    },
    1150211: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the current temperature, in degrees Celsius, of the RF conditioning module. \n\n Default Value: N/A \n\n Supported Devices: PXIe-5667     '
        },
        'name': 'RF_CONDITIONING_TEMPERATURE',
        'type': 'ViReal64'
    },
    1150215: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifics the RF lowband signal conditioning path used during calibration. This attribute is  valid only during a calibration session. \n\n Default Value: NIRFSA_VAL_EXT_CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_1  \n\n Supported Devices: PXIe-5606     '
        },
        'enum': 'RfLBSigCondPathSel',
        'name': 'CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_SELECTION',
        'type': 'ViInt32'
    },
    1150216: {
        'access': 'read-write',
        'documentation': {
            'description': ' Reads the IF attenuation table size based on valid path settings. This attribute is valid only during a calibration session. \n\n Valid Values: N/A \n\n Default Value: N/A \n\n Supported Devices: PXIe-5606     '
        },
        'name': 'CAL_IF_ATTENUATION_TABLE_SIZE',
        'type': 'ViInt32'
    },
    1150217: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the device is the master for synchronizing the sample clock between multiple devices.\n \n The master device distributes the sync signal to all devices in the system through the Sync Sample Clock distribution line. \n \n When synchronizing the Sample Clock, one device must always be designated as the master. When the device is configured as a master, it actively drives the Sync Sample Clock distribution line.\n \n Refer to the Synchronization Using NI-RFSA and NI-RFSG topic appropriate to your device in the NI RF Vector Signal Analyzers Help for more information about device synchronization for vector signal transceivers.\n'
        },
        'name': 'SYNC_SAMPLE_CLOCK_MASTER',
        'type': 'ViBoolean'
    },
    1150218: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies which external trigger line distributes the Sample Clock Sync signal. When synchronizing the Sample Clock, configure all devices to use the same Sync Sample Clock distribution line.\n \n Refer to the Synchronization Using NI-RFSA and NI-RFSG topic appropriate to your device in the NI RF Vector Signal Analyzers Help for more information about device synchronization for vector signal transceivers.\n'
        },
        'name': 'SYNC_SAMPLE_CLOCK_DIST_LINE',
        'type': 'ViString'
    },
    1150219: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies that an optimized IF filtering selection is made at different spectrum frequency ranges during  spectrum acquisition. \n\n Default Value: Disabled \n\n Supported Devices: PXIe-5665/5668     '
        },
        'name': 'SMOOTH_SPECTRUM_ENABLED',
        'type': 'ViInt32'
    },
    1150220: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the maximum corner frequency of the highpass filter in the RF signal path.  The device uses the highest frequency highpass filter option below or equal to the value you  specify and returns a coerced value. Specifying a value of 0 disables highpass filtering. \n\n Valid Values: 0 to 26.5 \n\n Default Value: 0 \n\n Supported Devices: PXIe-5606, PXIe-5668     '
        },
        'name': 'RF_HIGH_PASS_FILTERING',
        'type': 'ViReal64'
    },
    1150221: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns a string containing the path to the location of the current FPGA Extensions bitfile, a .lvbitx file, that is programmed on the device. \n \n An FPGA Extensions bitfile controls the behavior of the FPGA. You can use a custom bitfile with the NI-RFSA instrument driver to override the default FPGA bitfile and change the default behavior of the FPGA. Before reading this property, you must specify the bitfile location using the Driver Setup keyword in the options string parameter of the niRFSA_InitWithOptions function. \n\n Supported Devices: PXIe-5644/5645/5646, PXIe-5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'FPGA_BITFILE_PATH',
        'type': 'ViString'
    },
    1150222: {
        'access': 'read-write',
        'documentation': {
            'description': ' Enables the 28 V DC source on the device front panel. \n\n PXIe-5668 with PXIe-5698—When this attribute is set to NIRFSA_VAL_ENABLED, the PXIe-5698 noise source is used instead of the PXIe-5668 noise source. \n\n Default Value: NIRFSA_VAL_DISABLED \n\n Supported Devices: PXIe-5606, PXIe-5668, PXIe-5698     '
        },
        'name': 'NOISE_SOURCE_POWER_ENABLED',
        'type': 'ViInt32'
    },
    1150223: {
        'access': 'read-write',
        'documentation': {
            'description': ' Overrides the internal gain self-calibration correction for the 100 MHz IF filter path  with the value you set for this attribute.\n\n Default Value: 0 \n\n Supported Devices: PXIe-5606      '
        },
        'name': 'CALIBRATION_CORRECTION_100_MHZ_FILTER',
        'type': 'ViReal64'
    },
    1150224: {
        'access': 'read-write',
        'documentation': {
            'description': ' Overrides the internal gain self-calibration correction for the 320 MHz IF filter path  with the value you set for this attribute.\n\n Default Value: 0 \n\n Supported Devices: PXIe-5606      '
        },
        'name': 'CALIBRATION_CORRECTION_320_MHZ_FILTER',
        'type': 'ViReal64'
    },
    1150225: {
        'access': 'read-write',
        'documentation': {
            'description': ' Overrides the internal gain self-calibration correction for the 765 MHz IF filter path  with the value you set for this attribute.\n\n Default Value: 0 \n\n Supported Devices: PXIe-5606      '
        },
        'name': 'CALIBRATION_CORRECTION_765_MHZ_FILTER',
        'type': 'ViReal64'
    },
    1150226: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the currently associated digitizer ID.\n Allows the use of self calibration data when configured in external digitizer mode.\n\n Default Value:  (empty string) in external digitizer mode\n\n Supported Devices: PXIe-5606 (external digitizer mode), PXIe-5663/5663E/5665/5667/5668     '
        },
        'name': 'CAL_DIGITIZER_ID',
        'type': 'ViString'
    },
    1150228: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the frequency, in hertz (Hz), of the digitizer sample clock. \n\n Units: hertz (Hz) \n\n Supported Devices: PXIe-5668     '
        },
        'name': 'DIGITIZER_SAMPLE_CLOCK_RATE',
        'type': 'ViReal64'
    },
    1150229: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the terminal at which to export the Digitizer Sample Clock. \n\n Default Value:  (empty string) \n\n Supported Devices: PXIe-5668    '
        },
        'enum': 'DigitizerSampleClockOutTerminal',
        'name': 'EXPORTED_DIGITIZER_SAMPLE_CLOCK_OUTPUT_TERMINAL',
        'type': 'ViString'
    },
    1150233: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns a string containing the name of the FPGA target being used. \n\n Supported Devices: PXIe-5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'FPGA_TARGET_NAME',
        'type': 'ViString'
    },
    1150234: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the amount of overlap between consecutive subspans in a multispan spectrum acquisition. Overlapping  subspans can reduce the power level of spurs in acquired data. The value you specify determines the amount of  shift as a percentage of the subspan width. \n\n Valid Values:\n 0 (inclusive) to 100 (exclusive)\n Default Values: \n\n PXIe-5820/5830/5831/5840/5841: 0 \n\n PXIe-5665/5668: 0 to <100 \n\n Supported Devices: PXIe-5665/5668, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'SUBSPAN_OVERLAP',
        'type': 'ViReal64'
    },
    1150235: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the LO2 OUT terminal on the installed devices. \n\n Set this attribute to NIRFSA_VAL_ENABLED to export the 4 GHz LO signal from the device LO2 IN terminal to the LO2 OUT terminal. \n\n You can also export the LO2 signal by setting the NIRFSA_ATTR_LO_EXPORT_ENABLED attribute  and the NIRFSA_ATTR_DIGITIZER_SAMPLE_CLOCK_TIMEBASE_SOURCE attribute. \n\n Default Value: NIRFSA_VAL_DISABLED \n\n Supported Devices: PXIe-5603/5605/5606 (external digitizer mode), PXIe-5665/5668     '
        },
        'enum': 'EnabledAttr',
        'name': 'LO2_EXPORT_ENABLED',
        'type': 'ViInt32'
    },
    1150236: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the maximum instantaneous bandwidth of the device.\n\n Units: Hz \n\n Supported Devices: PXI-5600, PXIe-5601/5603/5605/5606 (external digitizer mode), PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5693/5694, PXIe-5820/5830/5831/5840/5841 '
        },
        'name': 'MAX_DEVICE_INSTANTANEOUS_BANDWIDTH',
        'type': 'ViReal64'
    },
    1150237: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the max I/Q rate of the device.\n\n Units: S/s \n\n Supported Devices: PXIe-5644/5645/5646, PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5820/5830/5831/5840/5841'
        },
        'name': 'MAX_IQ_RATE',
        'type': 'ViReal64'
    },
    1150246: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the power level, in dBm, of the signal at the LO OUT terminal  when the NIRFSA_ATTR_LO_EXPORT_ENABLED attribute is set to VI_TRUE. \n\n To use this attribute for the PXIe-5830/5831, you must use the channelName parameter of the niRFSA_SetAttributeViReal64  function to specify the name of the channel you are configuring. You can configure the LO1 and LO2 channels by using lo1  or lo2 as the channel string, or set the channel string to lo1,lo2 to configure both channels. For all other devices,  the only valid value for the channel string is  (empty string). \n\n Units: dBm \n\n Supported Devices: PXIe-5830/5831/5840/5841 '
        },
        'name': 'LO_OUT_POWER',
        'type': 'ViReal64'
    },
    1150254: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the current temperature, in degrees Celsius, of the FPGA. \n\n Defualt Value: N/A \n\n Supported Devices: PXIe-5820/5830/5831/5840/5841     ',
            'note': ' If you query this attribute during RF list mode, list steps may take longer to complete during list execution. \n'
        },
        'name': 'FPGA_TEMPERATURE',
        'type': 'ViReal64'
    },
    1150255: {
        'access': 'read only',
        'documentation': {
            'description': ' Returns the module power consumption. \n\n Units: Watts \n\n Default Value: N/A \n\n Supported Devices: PXIe-5820/5830/5831/5840/5841 ',
            'note': ' If you query this attribute during RF list mode, list steps may take longer to complete during list execution. \n\n'
        },
        'name': 'MODULE_POWER_CONSUMPTION',
        'type': 'ViReal64'
    },
    1150256: {
        'access': 'read-write',
        'documentation': {
            'description': ' Enables or disables warnings and errors when you set frequency, power, or bandwidth values beyond the limits of the NI-RFSA device  specifications. When you set this attribute to NIRFSA_VAL_ENABLED, the driver does not report out-of-specification warnings and errors. \n\n Default Value: NIRFSA_VAL_DISABLED \n\n Supported Devices: PXIe-5820/5830/5831/5840/5841     '
        },
        'enum': 'EnabledAttr',
        'name': 'ALLOW_OUT_OF_SPECIFICATION_USER_SETTINGS',
        'type': 'ViInt32'
    },
    1150266: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the sub-sample clock delay, in seconds, to apply to the acquired signal.  Use this attribute to reduce the trigger jitter when synchronizing multiple devices with NI-TClk.  This attribute can also help maintain synchronization repeatability by writing the absolute delay value of a previous measurment to the current session. \n\n To set this attribute, your device must be in the Configuration state. \n\n Valid Values: Plus or minus half of one sample clock period \n\n Default Value: 0 \n\n Supported Devices: PXIe-5820/5830/5831/5840/5841 ',
            'note': ' If this value is set, TClk cannot do any sub-sample clock adjustment. \n\n'
        },
        'name': 'ABSOLUTE_DELAY',
        'type': 'ViReal64'
    },
    1150267: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the bandwidth of the input signal around the NIRFSA_ATTR_IQ_CARRIER_FREQUENCY. \n\n This value must be less than or equal to (0.8 x I/Q rate). NI-RFSA defines signal bandwidth as twice the maximum I/Q signal deviation from 0 Hz.  Usually, the baseband signal center frequency is 0 Hz. In such cases, the signal bandwidth  is simply the baseband signal's minimum frequency subtracted from its maximum frequency, or fmax - fmin. \n\n If you do not set this attribute, NI-RFSA uses the maximum available signal bandwidth. Depending on your  device settings, setting this attribute enables certain optimizations. Based on the specified signal  bandwidth, NI-RFSA decides the minimum equalized bandwidth and equalizer gain. \n\n Ensure you set the signal bandwidth wide enough to encompass all significant anticipated input power.  In cases where NI-RFSA optimizes the input gain based on the signal bandwidth, significant input power outside  the signal bandwidth can lead to clipping and associated overflow warnings if you do not have enough margin in your reference level. \n\n Units: hertz (Hz) \n\n Default Value: 0 Hz \n\n Supported Devices: PXIe-5820/5830/5831/5840/5841     ",
            'note': ' You must set this attribute to enable the NIRFSA_ATTR_DOWNCONVERTER_FREQUENCY_OFFSET_MODE attribute. \n\n'
        },
        'name': 'SIGNAL_BANDWIDTH',
        'type': 'ViReal64'
    },
    1150269: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the common-mode level presented at each differential input terminal. Common-mode level shifts both positive and negative terminals in the same direction. This must match the common-mode level of the device under test (DUT). \n\n Units: volts \n\n Default Value: 0 V \n\n Supported Devices: PXIe-5820 \n\n '
        },
        'name': 'COMMON_MODE',
        'type': 'ViReal64'
    },
    1150271: {
        'access': 'read-write',
        'documentation': {
            'description': ' Configures error reporting for ADC and onboard signal processing overflows. Overflows lead to clipping of the waveform. \n\n Default Value: NIRFSA_VAL_ERROR_REPORTING_WARNING \n\n Supported Devices: PXIe-5644/5645/5646, PXIe-5820/5830/5831/5840/5841     '
        },
        'enum': 'OverflowErrorReporting',
        'name': 'OVERFLOW_ERROR_REPORTING',
        'type': 'ViInt32'
    },
    1150285: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the size of the DMA buffer in computer memory, in bytes. To  set this attribute, the NI-RFSA device must be in the Configuration state. \n\n large fetches to be transferred more efficiently.\n\n Default Value: 8 MB \n\n Supported Devices: PXIe-5820/5830/5831/5840/5841     ',
            'note': ' A sufficiently large host DMA buffer improves performance by allowing '
        },
        'name': 'HOST_DMA_BUFFER_SIZE',
        'type': 'ViInt64'
    },
    1150297: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the port to configure. \n\n Valid Values: \n\n PXIe-5644/5645/5646, PXIe-5820/5840/5841:  (empty string) \n PXIe-5830: if0, if1 PXIe-5831: if0, if1, rf<0-1>/port<x>, where 0-1 indicates one (0) or two (1) mmRH-5582 connections and x is the port number on the mmRH-5582 front panel. \n\n Default Value: \n\n PXIe-5830/5831: if1 \n PXIe-5644/5645/5646, PXIe-5820/5840/5841:  (empty string) \n\n Supported Devices: PXIe-5644/5645/5646, PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'SELECTED_PORTS',
        'type': 'ViReal64'
    },
    1150298: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to enable the RF OUT LO OUT terminal on the PXIe-5840/5841.  This attribute cannot be set to NIRFSA_VAL_ENABLED or NIRFSA_VAL_DISABLED unless an NI-RFSG session on the  PXIe-5840 has set the NIRFSG_ATTR_LO_EXPORT_CONFIGURE_FROM_RFSA attribute to NIRFSG_VAL_ENABLE.\n\n When this attribute is enabled, if the NIRFSA_ATTR_LO_SOURCE attribute is set to NIRFSA_VAL_LO_IN_STR and you  do not set the NIRFSA_ATTR_LO_FREQUENCY or NIRFSA_ATTR_DOWNCONVERTER_CENTER_FREQUENCY attributes, NI-RFSA rounds the  LO frequency to approximately an LO step size as if the source was NIRFSA_VAL_ONBOARD_STR. This ensures that when you  configure NI-RFSA and NI-RFSG with compatible settings that result in the same LO frequency, the rounding also is compatible. \n\n Default Value: NIRFSA_VAL_UNSPECIFIED \n\n Supported Devices: PXIe-5840/5841     '
        },
        'enum': 'UnspecifiedAttr',
        'name': 'RF_OUT_LO_EXPORT_ENABLED',
        'type': 'ViInt32'
    },
    1150299: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to allow NI-RFSG to control the NI-RFSA LO out export.  Set this attribute to NIRFSA_VAL_ENABLED to allow NI-RFSG to control the LO out export.  Use the NIRFSG_ATTR_RF_IN_LO_EXPORT_ENABLED attribute to control the NI-RFSA LO out export from NI-RFSG. \n\n Default Value: NIRFSA_VAL_DISABLED \n\n Supported Devices: PXIe-5840/5841     '
        },
        'enum': 'EnabledAttr',
        'name': 'LO_OUT_EXPORT_CONFIGURE_FROM_RFSG',
        'type': 'ViInt32'
    },
    1150300: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the temperature change, in degrees Celsius, required before NI-RFSA recalculates the thermal correction settings when entering the Running state. \n\n Units: degrees Celsius \n\n Supported Devices: PXIe-5820/5830/5831/5840/5841 Default Values: PXIe-5830/5831: 0.2 PXIe-5840/5841: 1.0    '
        },
        'name': 'THERMAL_CORRECTION_TEMPERATURE_RESOLUTION',
        'type': 'ViReal64'
    },
    1150301: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the scaling factor applied to the time-domain voltage data in the digitizer. NI-RFSA does not compensate for the specified digital gain.  You can use this attribute to account for external gain changes without changing the analog signal path.  Units: dB \n\n Default Value: 0 dB \n\n Supported Devices: PXIe-5644/5645/5646, PXIe-5830/5831/5840/5841    ',
            'note': ' The PXIe-5644/5645/5646 applies this gain when the data is scaled. The raw data does not include this scaling on these devices. \n\n'
        },
        'name': 'DIGITAL_GAIN',
        'type': 'ViReal64'
    },
    1150305: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether to allow NI-RFSA to select the downconveter frequency offset. You can either set an offset yourself or let NI-RFSA select one for you. \n\n Placing the downconverter center frequency outside the bandwidth of your input signal can help avoid issues such as LO leakage. \n To set an offset yourself, set this attribute to NIRFSA_VAL_AUTOMATIC or NIRFSA_VAL_USER_DEFINED,  and set either the  NIRFSA_ATTR_DOWNCONVERTER_CENTER_FREQUENCY or the NIRFSA_ATTR_DOWNCONVERTER_FREQUENCY_OFFSET attributes. \n To allow NI-RFSA to automatically select the downconverter frequency offset, set this attribute to NIRFSA_VAL_AUTOMATIC  or NIRFSA_VAL_ENABLED and configure the NIRFSA_ATTR_SIGNAL_BANDWIDTH attribute to describe your expected input signal. \n The signal bandwidth must be no greater than half the specified value of the NIRFSA_ATTR_DEVICE_INSTANTANEOUS_BANDWIDTH attribute,  minus a device-specific guard band. Do not set the NIRFSA_ATTR_DOWNCONVERTER_CENTER_FREQUENCY or NIRFSA_ATTR_DOWNCONVERTER_FREQUENCY_OFFSET  attributes. If all conditions are met, NI-RFSA places the downconverter center frequency outside the signal bandwidth. \n Set this attribute to NIRFSA_VAL_ENABLED if you want to receive an error any time NI-RFSA is unable to apply automatic offset. \n\n When you set an offset yourself or do not use an offset, the reference frequency for gain is near the downconverter center frequency,  and NIRFSA_ATTR_DOWNCONVERTER_FREQUENCY_OFFSET_MODE returns NIRFSA_VAL_USER_DEFINED. When NI-RFSA automatically sets an offset,  the reference frequency for gain is the I/Q carrier frequency, and NIRFSA_ATTR_DOWNCONVERTER_FREQUENCY_OFFSET_MODE returns NIRFSA_VAL_ENABLED.  Refer to the specifications document for your device for more information about gain, flatness, and reference frequencies. \n\n Default Value: NIRFSA_VAL_AUTOMATIC \n\n Supported Devices: PXIe-5830/5831/5841     '
        },
        'enum': 'DownconverterFrequencyOffsetMode',
        'name': 'DOWNCONVERTER_FREQUENCY_OFFSET_MODE',
        'type': 'ViInt32'
    },
    1150306: {
        'access': 'read-write',
        'documentation': {
            'description': ' Returns a comma-separated list of the available ports to use based on your hardware configuration. Supported Devices: PXIe-5644/5645/5646, PXIe-5820/5840/5841, PXIe-5830/5831     '
        },
        'name': 'AVAILABLE_PORTS',
        'type': 'ViReal64'
    },
    1150307: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the type of de-embedding to apply to measurements on the specified port. To use this attribute, you must use the channelName parameter of the niRFSA_SetAttributeViInt32 function to specify the name of the port to configure for de-embedding. \n\n If you set this attribute to NIRFSA_VAL_DEEMBEDDING_TYPE_SCALAR or NIRFSA_VAL_DEEMBEDDING_TYPE_VECTOR, NI-RFSA adjusts the instrument settings and the returned data to remove the effects of the external network between the instrument and the DUT. \n\n Default Value: NIRFSA_VAL_DEEMBEDDING_TYPE_SCALAR \n\n Valid Values for PXIe-5830/5832/5840/5841: NIRFSA_VAL_DEEMBEDDING_TYPE_SCALAR, NIRFSA_VAL_DEEMBEDDING_TYPE_NONE \n\n Valid Values for PXIe-5831: NIRFSA_VAL_DEEMBEDDING_TYPE_VECTOR, NIRFSA_VAL_DEEMBEDDING_TYPE_SCALAR, or NIRFSA_VAL_DEEMBEDDING_TYPE_NONE. NIRFSA_VAL_DEEMBEDDING_TYPE_VECTOR is only supported for TRX Ports in a Semiconductor Test System (STS).\n\n Supported Devices: PXIe-5830/5831/5832/5840/5841     '
        },
        'enum': 'DeembeddingType',
        'name': 'DEEMBEDDING_TYPE',
        'type': 'ViInt32'
    },
    1150308: {
        'access': 'read-write',
        'documentation': {
            'description': ' Selects the de-embedding table to apply to the measurements on the specified port. To use this attribute, you must use the channelName parameter of the niRFSA_SetAttributeViString function to specify the name of the port to configure for de-embedding. \n\n If de-embedding is enabled, NI-RFSA uses the specified table to remove the effects of the external network between the instrument and the DUT. \n\n Use the niRFSA_CreateDeembeddingSparameterTableArray function to create tables. \n\n Supported Devices: PXIe-5830/5831/5840/5841     '
        },
        'name': 'DEEMBEDDING_SELECTED_TABLE',
        'type': 'ViString'
    },
    1150309: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the margin NI-RFSA adds to the NIRFSA_ATTR_REFERENCE_LEVEL attribute.  The margin helps to avoid clipping and overflow warnings if the input signal  exceeds the configured reference level. \n\n NI-RFSA configures the input gain to avoid clipping and associated overflow warnings as long as  the instantaneous power of the input signal remains within the reference level plus the reference level headroom.  If you know the input power of the signal precisely or have already included margin in the  reference level, you may be able to improve the signal-to-noise ratio by reducing  the reference level headroom. \n\n Units: dB \n\n Default Value: \n\n PXIe-5830/5831/5841: 1 dB \n PXIe-5840: 0 dB \n\n Supported Devices: PXIe-5830/5831/5840/5841     '
        },
        'name': 'REFERENCE_LEVEL_HEADROOM',
        'type': 'ViReal64'
    },
    1150312: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the step size for tuning the internal VCO used to generate the LO. \n\n Valid Values: 1 Hz to 50 MHz for LO1 and 1 Hz to 100 MHz for LO2 \n\n Default Value: 1 MHz \n\n Supported Devices: PXIe-5830/5831 ',
            'note': ' Do not set this attribute with the NIRFSA_ATTR_LO_FREQUENCY_STEP_SIZE attribute. \n\n'
        },
        'name': 'LO_VCO_FREQUENCY_STEP_SIZE',
        'type': 'ViReal64'
    },
    1150316: {
        'access': 'read-write',
        'documentation': {
            'description': " Specifies the expected thermal operating range of the instrument from the self-calibration temperature, in degrees Celsius, returned from the NIRFSA_ATTR_DEVICE_TEMPERATURE attribute. \n\n' For example, if this attribute is set to 5.0, and the device is self-calibrated at 35 degrees Celsius, then you can  expect to run the device from 30 degrees Celsius to 40 degrees Celsius with corrected accuracy and no overflows.  Setting this attribute with a smaller value can result in improved dynamic range, but you must ensure thermal stability  while the instrument is running. Operating the instrument outside of the specified range may cause degraded performance and ADC or DSP overflows. \n\n Units: degrees Celsius \n\n Supported Devices: PXIe-5840/5830/5831 Default Value: \n\n PXIe-5830/5831: 5 \n PXIe-5840/5841: 10 \n\n Supported Devices: PXIe-5830/5831/5840/5841    "
        },
        'name': 'THERMAL_CORRECTION_HEADROOM_RANGE',
        'type': 'ViReal64'
    },
    1150321: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the pulse width units for the User Source. When the value is NIRFSA_VAL_PULSE_WIDTH_UNITS_SECONDS, it is assumed that the clock rate of the signal  is the data clock. Use NIRFSA_VAL_PULSE_WIDTH_UNITS_CLOCK_PERIODS if the user source clock rate is anything else \n\n. Valid Values: NIRFSA_VAL_PULSE_WIDTH_UNITS_SECONDS, NIRFSA_VAL_PULSE_WIDTH_UNITS_CLOCK_PERIODS \n\n Default Value: NIRFSA_VAL_PULSE_WIDTH_UNITS_SECONDS \n\n Supported Devices: PXIe-5820/5830/5831/5840/5841     '
        },
        'enum': 'PulseWidthUnitType',
        'name': 'USER_SOURCE_PULSE_WIDTH_UNITS',
        'type': 'ViInt32'
    },
    1150322: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies the pulse width for the User Source. Use the NIRFSA_ATTR_USER_SOURCE_PULSE_WIDTH_UNITS attribute to set the units for the pulse width. \n\n Default Value: 200E(-9) \n\n Supported Devices: PXIe-5820/5830/5831/5840/5841     '
        },
        'name': 'USER_SOURCE_PULSE_WIDTH',
        'type': 'ViReal64'
    },
    1150324: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies a comma-separated list of ports for which to fix the group delay. \n\n Valid Values: \n\n PXIe-5831/5832: rf<0-1>/port<x>, where 0-1 indicates one (0) or two (1) mmRH-5582 connections and x is the port number on the mmRH-5582 front panel. \n\n Default Value:  \n\n PXIe-5831/5832:  (empty string) \n\n Supported Devices: PXIe-5831/5832     '
        },
        'name': 'FIXED_GROUP_DELAY_ACROSS_PORTS',
        'type': 'ViString'
    },
    1150325: {
        'access': 'read-write',
        'name': 'DEEMBEDDING_COMPENSATION_GAIN',
        'type': 'ViReal64'
    }
}
