#ifndef ___niRFSG_niRFSGErrors_h___
#define ___niRFSG_niRFSGErrors_h___

/*******************************/
/*********** Errors ************/
/*******************************/

/* hex: 0xBFFA43FF */
/* Session is not usable. If you are using multiple threads, this error may have been caused by attempting to use the session closed in a different thread. */
#define NIRFSG_ERROR_INVALID_SESSION -1074117633

/* hex: 0xBFFA43FE */
/* Unable to initialize because a session for the specified device is already open from another process. Close on the open session by calling niRFSG Close or by exiting the application with the open session. */
#define NIRFSG_ERROR_PREVIOUS_SESSION -1074117634

/* hex: 0xBFFA43FD */
/* Invalid resource name. Note: if the resource name is an IVI Logical name, it must match the entry in the IVI Configuration Store in a case sensitive manner. */
#define NIRFSG_ERROR_INVALID_RESOURCE_NAME -1074117635

/* hex: 0xBFFA43FC */
/* The device specified is not supported by this driver. */
#define NIRFSG_ERROR_DEVICE_NOT_SUPPORTED -1074117636

/* hex: 0xBFFA43FB */
/* Operation failed because the signal generator is not in the Configuration state. Call niRFSG Abort prior to making this call. */
#define NIRFSG_ERROR_NOT_CONFIGURABLE -1074117637

/* hex: 0xBFFA43FA */
/* Operation failed because the signal generator is not in the Generation state. Call niRFSG Initiate prior to making this call. */
#define NIRFSG_ERROR_NOT_GENERATING -1074117638

/* hex: 0xBFFA43F9 */
/* The maximum number of waveforms has been reached. To write more waveforms, clear already written waveforms by using niRFSG Clear All Waveforms. To find out the maximum number of supported waveforms, call niRFSG Query ARB Waveform Capabilities. */
#define NIRFSG_ERROR_EXCEEDED_MAX_WAVEFORMS -1074117639

/* hex: 0xBFFA43F8 */
/* Invalid IQ Rate. */
#define NIRFSG_ERROR_INVALID_IQ_RATE -1074117640

/* hex: 0xBFFA43F7 */
/* Invalid waveform. */
#define NIRFSG_ERROR_INVALID_WAVEFORM -1074117641

/* hex: 0xBFFA43F6 */
/* The combination of the specified Reference Clock Source and PXI Clk Source is not supported. Refer to the documentation for more information. */
#define NIRFSG_ERROR_CLOCK_CONFIGURATION_NOT_SUPPORTED -1074117642

/* hex: 0xBFFA43F5 */
/* The trigger configuration specified is not supported. Refer to the documentation for more information. */
#define NIRFSG_ERROR_INVALID_TRIGGER_CONFIGURATION -1074117643

/* hex: 0xBFFA43F4 */
/* The 'DriverSetup' entry in the Option String is invalid. */
#define NIRFSG_ERROR_DRIVER_SETUP_SYNTAX -1074117644

/* hex: 0xBFFA43F3 */
/* Operation failed because the signal generator is not in the Committed state. Call niRFSG Commit or niRFSG Initiate prior to making this call. */
#define NIRFSG_ERROR_NOT_COMMITTED -1074117645

/* hex: 0xBFFA43F2 */
/* The signal generator's waveform memory is full. */
#define NIRFSG_ERROR_NO_WFMS_AVAILABLE -1074117646

/* hex: 0xBFFA43F1 */
/* The specified digital equalization coefficients are not supported. */
#define NIRFSG_ERROR_INVALID_FILTER -1074117647

/* hex: 0xBFFA43EF */
/* Hardware error has occurred. Frequency PLL did not lock in the expected amount of time. Execute Self Test and Self Cal in MAX, or contact NI technical support at ni.com/support */
#define NIRFSG_ERROR_FREQUENCY_NOT_SETTLED -1074117649

/* hex: 0xBFFA43EE */
/* Hardware error has occurred. Output Gain did not settle in the expected amount of time. Execute Self Test and Self Cal in MAX, or contact NI technical support at ni.com/support */
#define NIRFSG_ERROR_ATTENUATION_NOT_SETTLED -1074117650

/* hex: 0xBFFA43ED */
/* Hardware error has occurred. Debounce Timer for Reverse Power Protection Relay did not expire in the expected amount of time. Execute Self Test in MAX, or contact NI technical support at ni.com/support */
#define NIRFSG_ERROR_REVERSE_POWER_PROTECTION -1074117651

/* hex: 0xBFFA43EC */
/* A session cannot be created because the maximum number of session is already open. To open a new session, close one of the existing sessions by calling niRFSG Close. */
#define NIRFSG_ERROR_MAX_SESSIONS_EXCEEDED -1074117652

/* hex: 0xBFFA43EA */
/* A session cannot be created because the AWG resource name is invalid. Verify the AWG resource name in MAX by selecting the upconverter and specifying the AWG name within the Associated Devices section. If you are specifying the AWG via the Option String, ensure the AWG resource name is valid. */
#define NIRFSG_ERROR_INVALID_AWG_RESOURCE_NAME -1074117654

/* hex: 0xBFFA43E9 */
/* The requested Power Level requires a Peak Envelope Power (PEP) that exceeds the device specifications. */
#define NIRFSG_ERROR_PEP_OUT_OF_RANGE -1074117655

/* hex: 0xBFFA43E8 */
/* Initialization failed because another session with conflicting initialization options is already open for this device. Call niRFSG Close on the opened session, or close and reopen the application. */
#define NIRFSG_ERROR_PREVIOUS_CONFLICTING_SESSION -1074117656

/* hex: 0xBFFA43E7 */
/* The reservedForFutureUse parameter must be 0. */
#define NIRFSG_ERROR_RESERVED_PARAMETER_NOT_ZERO -1074117657

/* hex: 0xBFFA43E6 */
/* Requested Power Level requires an AWG Gain that exceeds device limits. Ensure the requested Power Level is within device specifications. */
#define NIRFSG_ERROR_ARB_GAIN_PAST_LIMIT -1074117658

/* hex: 0xBFFA43E5 */
/* Invalid or unsupported model specified. Note: Valid values for model include 5610, 5611, 5650, 5651,  5652, 5653, 5670, 5671, 5672, 5673 and 5673E. Valid values for AWG include 5421, 5441, 5442, 5450, and 5451. Valid values for LO include 5650, 5651 and 5652. */
#define NIRFSG_ERROR_MODEL_NOT_RECOGNIZED -1074117659

/* hex: 0xBFFA43E4 */
/* Invalid or unsupported product number specified. */
#define NIRFSG_ERROR_PRODUCT_NUMBER_NOT_RECOGNIZED -1074117660

/* hex: 0xBFFA43E3 */
/* The specified generation mode is invalid. */
#define NIRFSG_ERROR_INVALID_GENERATION_MODE -1074117661

/* hex: 0xBFFA43E2 */
/* Invalid waveform size. The waveform size must be a multiple of the waveform quantum. */
#define NIRFSG_ERROR_WFM_QUANTUM_VIOLATION -1074117662

/* hex: 0xBFFA43E1 */
/* Invalid waveform size. */
#define NIRFSG_ERROR_WFM_SIZE_VIOLATION -1074117663

/* hex: 0xBFFA43E0 */
/* The specified waveform has not been completed. The waveform was last written with 'more Data Pending' marked true. */
#define NIRFSG_ERROR_INCOMPLETE_WAVEFORM -1074117664

/* hex: 0xBFFA43DF */
/* You are using script generation mode, but no scripts have been written. */
#define NIRFSG_ERROR_NO_SCRIPTS_WRITTEN -1074117665

/* hex: 0xBFFA43DE */
/* Invalid Power Level Type. */
#define NIRFSG_ERROR_INVALID_POWER_LEVEL_TYPE -1074117666

/* hex: 0xBFFA43DD */
/* This combination of attributes is not supported. */
#define NIRFSG_ERROR_INVALID_CONFIGURATION -1074117667

/* hex: 0xBFFA43DC */
/* The specified signal identifier is invalid for this signal. */
#define NIRFSG_ERROR_INVALID_SIGNAL_IDENTIFIER -1074117668

/* hex: 0xBFFA43DB */
/* Maximum time exceeded before the operation completed. */
#define NIRFSG_ERROR_MAX_TIME_EXCEEDED -1074117669

/* hex: 0xBFFA43DA */
/* Invalid waveform size. Since each I-Q sample consists of two array elements, the total number of array elements needs to be even. */
#define NIRFSG_ERROR_INVALID_NUMBER_OF_IQ_SAMPLES -1074117670

/* hex: 0xBFFA43D9 */
/* A session cannot be created because the LO resource name is invalid. Verify the LO resource name in MAX by selecting the upconverter and specifying the LO name within the Associated Devices section. If you are specifying the LO via the Option String, ensure the LO resource name is valid. */
#define NIRFSG_ERROR_INVALID_LO_RESOURCE_NAME -1074117671

/* hex: 0xBFFA43D8 */
/* Failed to communicate with the RF processing module. Contact NI technical support at ni.com/support */
#define NIRFSG_ERROR_RF_MODULE_COMMUNICATION_FAILURE -1074117672

/* hex: 0xBFFA43D7 */
/* The device is in an invalid state for self test. Call reset before calling self test. */
#define NIRFSG_ERROR_INVALID_STATE_FOR_SELFTEST -1074117673

/* hex: 0xBFFA43D6 */
/* This device does not support the specified driver setup keyword. */
#define NIRFSG_ERROR_DRIVER_SETUP_KEYWORD_NOT_SUPPORTED -1074117674

/* hex: 0xBFFA43D5 */
/* A session cannot be created because the AWG resource name is invalid. Verify the AWG resource name in MAX by selecting the upconverter and specifying the AWG name within the Associated Devices section.<LF/><LF/>If you are specifying the AWG via the Option String, ensure the AWG resource name is valid and supported by this upconverter. The NI 5610 upconverter supports the NI PXI-5421, NI PXI-5441, and NI PXIe-5442 AWGs. The NI 5611 upconverter supports the NI PXIe-5450 and NI-PXIe-5451 AWGs. */
#define NIRFSG_ERROR_ARB_NOT_SUPPORTED -1074117675

/* hex: 0xBFFA43D4 */
/* You cannot use Streaming in CW mode. Change the generation mode to Arb Waveform or Script to use Streaming. */
#define NIRFSG_ERROR_STREAMING_NOT_SUPPORTED_IN_CW_MODE -1074117676

/* hex: 0xBFFA43D3 */
/* After the session was created, the driver DLL was unloaded and then reloaded at a different base address.  Session is unusable.  Unload all instances of the driver DLL and verify that previous operations do not unload the driver DLL. */
#define NIRFSG_ERROR_DLL_LOADED_AT_DIFFERENT_BASE_ADDRESS -1074117677

/* hex: 0xBFFA43D2 */
/* An IQ Rate of 50 MS/s is only valid when the signal bandwidth is less than 5 MHz. */
#define NIRFSG_ERROR_INVALID_IQ_RATE_AND_BANDWIDTH_CONFIGURATION -1074117678

/* hex: 0xBFFA43D1 */
/* Values must be set in increments of 1MHz. */
#define NIRFSG_ERROR_VALUE_MUST_BE_MULTIPLE_OF_1MHZ -1074117679

/* hex: 0xBFFA43D0 */
/* You cannot change the Power Level Type or Normalization property if you have already allocated one or more waveforms. Either use the previous Power Level Type/normalization property value or clear your waveforms. */
#define NIRFSG_ERROR_POWER_LEVEL_TYPE_CHANGED_DURING_RECONFIGURATION -1074117680

/* hex: 0xBFFA43CF */
/* This function is not supported when the Power Level Type is set to Average Power. Either change the Power Level Type to Peak Power or use a different write function. */
#define NIRFSG_ERROR_AVERAGE_POWER_NOT_SUPPORTED_FOR_BINARY_WRITE -1074117681

/* hex: 0xBFFA43CE */
/* You are trying to query a Streaming property without enabling Streaming. Set Streaming Enabled to True before your query. */
#define NIRFSG_ERROR_STREAMING_NOT_ENABLED -1074117682

/* hex: 0xBFFA43CD */
/* You have not specified which waveform to generate. */
#define NIRFSG_ERROR_WAVEFORM_NOT_SELECTED -1074117683

/* hex: 0xBFFA43CC */
/* You cannot call write multiple times on the same waveform name with the Power Level Type set to Average Power or Normalization set to Enabled. You must set Power Level Type to Peak Power or Normalization property to Disabled to append data to a previously written waveform. */
#define NIRFSG_ERROR_WRITING_IN_CHUNKS_NOT_SUPPORTED_WITH_AVERAGE_POWER -1074117684

/* hex: 0xBFFA43CB */
/* NaN, +Inf, and -Inf are not valid values. */
#define NIRFSG_ERROR_VALUE_CANNOT_BE_INF_OR_NAN -1074117685

/* hex: 0xBFFA43CA */
/* The value must be nonzero. */
#define NIRFSG_ERROR_VALUE_MUST_BE_NONZERO -1074117686

/* hex: 0xBFFA43C9 */
/* You are using Digital Equalization with Direct Download enabled. Either disable Digital Equalization or disable Direct Download. */
#define NIRFSG_ERROR_DIGITAL_EQUALIZATION_NOT_SUPPORTED_WITH_DIRECT_DOWNLOAD -1074117687

/* hex: 0xBFFA43C8 */
/* You are using Direct Download to download a waveform without allocating the waveform.  Call niRFSG Allocate Arb Waveform to allocate the waveform prior to making this call. */
#define NIRFSG_ERROR_ALLOCATE_NOT_CALLED_WITH_DIRECT_DOWNLOAD_ENABLED -1074117688

/* hex: 0xBFFA43C7 */
/* You are using Direct Download with the Average Power as the Power Level Type.  Either change the Power Level Type to Peak Power or disable Direct Download. */
#define NIRFSG_ERROR_DIRECT_DOWNLOAD_INVALID_WITH_AVERAGE_POWER -1074117689

/* hex: 0xBFFA43C6 */
/* You are using IQ Swap Enabled with Direct Download enabled.  Either disable IQ Swap or disable Direct Download. */
#define NIRFSG_ERROR_IQ_SWAP_NOT_SUPPORTED_WITH_DIRECT_DOWNLOAD -1074117690

/* hex: 0xBFFA43C5 */
/* This device does not support resetting attributes. */
#define NIRFSG_ERROR_RESETTING_ATTRIBUTES_NOT_SUPPORTED -1074117691

/* hex: 0xBFFA43C4 */
/* Resetting this attribute is not supported. */
#define NIRFSG_ERROR_RESETTING_THIS_ATTRIBUTE_NOT_SUPPORTED -1074117692

/* hex: 0xBFFA43C3 */
/* Scripts are not supported when the Phase Continuity Enabled attribute is enabled. */
#define NIRFSG_ERROR_SCRIPT_MODE_WITH_PHASE_CONTINUITY -1074117693

/* hex: 0xBFFA43C2 */
/* Your waveform data is invalid.  The magnitude of the I-Q signal multiplied by the scaling factor should be less than or equal to 1. */
#define NIRFSG_ERROR_IQ_MAGNITUDE_PAST_LIMIT -1074117694

/* hex: 0xBFFA43C1 */
/* You cannot query Peak Envelope Power with the Power Level Type set to Peak Power. */
#define NIRFSG_ERROR_PEAK_ENVELOPE_POWER_NOT_SUPPORTED_WITH_PEAK_POWER -1074117695

/* hex: 0xBFFA43C0 */
/* Function not supported in Script Mode. */
#define NIRFSG_ERROR_FUNCTION_NOT_SUPPORTED_IN_SCRIPT_MODE -1074117696

/* hex: 0xBFFA43BF */
/* RFDAP reported the following error: */
#define NIRFSG_ERROR_RFDAP_ERROR -1074117697

/* hex: 0xBFFA43BE */
/* Self calibration failed.  Contact NI technical support at ni.com/support. */
#define NIRFSG_ERROR_SELF_CAL_FAILED_CONTACT_SUPPORT -1074117698

/* hex: 0xBFFA43BD */
/* Self calibration failed to converge.  Performing an external calibration may fix the problem. */
#define NIRFSG_ERROR_SELF_CAL_FAILED_TO_CONVERGE -1074117699

/* hex: 0xBFFA43BC */
/* Self calibration failed.  Performing an external calibration may fix the problem. */
#define NIRFSG_ERROR_SELF_CAL_FAILED_TRY_EXT_CAL -1074117700

/* hex: 0xBFFA43BB */
/* A power supply fault has been detected.  Reset the device to clear the fault.  If the fault occurs again contact NI technical support at ni.com/support. */
#define NIRFSG_ERROR_POWER_SUPPLY_FAULT -1074117701

/* hex: 0xBFFA43B9 */
/* You cannot specify multiple channels or repeated capabilities. */
#define NIRSFG_ERROR_MULTIPLE_REPEATED_CAPABILITY_NOT_ALLOWED -1074117703

/* hex: 0xBFFA43B8 */
/* The frequency cannot be changed while attenuator hold is enabled. */
#define NIRFSG_ERROR_CHANGE_FREQUENCY_IN_ATTENUATOR_HOLD -1074117704

/* hex: 0xBFFA43B7 */
/* The Filter Type must be set to None when the Digital Upconverter is disabled. Either change the Filter Type to None or change the IQ Rate to enable the Digital Upconverter. */
#define NIRFSG_ERROR_INVALID_FILTER_TYPE_WITH_DUC_DISABLED -1074117705

/* hex: 0xBFFA43B6 */
/* You are using Direct Download with the Digital Upconverter disabled. Either change the IQ Rate to enable the Digital Upconverter or disable Direct Download. */
#define NIRFSG_ERROR_DIRECT_DOWNLOAD_INVALID_WITH_DUC_DISABLED -1074117706

/* hex: 0xBFFA43B5 */
/* The size of the sine pattern needed to achieve the specified frequency with the specified precision is too large. Either increase the tolerance or modify the center frequency. */
#define NIRFSG_ERROR_SIZE_SINE_PATTERN -1074117707

/* hex: 0xBFFA43B4 */
/* Requested Power Level requires an AWG Gain that exceeds device limits. When Attenuator Hold is enabled, the Power Level must be in the range (Attenuator Hold Max Power - 70, Attenuator Hold Max Power). */
#define NIRFSG_ERROR_ARB_GAIN_PAST_LIMIT_WITH_ATTENUATOR_HOLD -1074117708

/* hex: 0xBFFA43B3 */
/* IQ Rates greater than 25 MS/s and less than 42.5 MS/s and rates greater than 50 MS/s and less than 85 MS/s are only supported when the Arb Sample Clock Source is set to OnboardClock and the Arb Sample Clock Mode is set to Divide Down. */
#define NIRFSG_ERROR_INVALID_IQ_RATE_FOR_NON_DIVIDE_DOWN_MODES -1074117709

/* hex: 0xBFFA43B2 */
/* You have at least one waveform that has not been configured with the same value as the current value of Direct Download. */
#define NIRFSG_ERROR_ALL_WAVEFORMS_NOT_DOWNLOADED_IN_THE_SAME_MODE -1074117710

/* hex: 0xBFFA43B1 */
/* The qData may be an empty array to indicate the absence of qData. However, when writing a waveform in segments (moreDataPending = true), you cannot alternate between setting the qData to an empty array and setting it to specific values. */
#define NIRFSG_ERROR_VECTOR_Q_USAGE -1074117711

/* hex: 0xBFFA43B0 */
/* INF (infinite) or NaN (Not a Number) values encountered while making calculations based on waveform data.  Waveform may contain INF or NaN values, or the scale of the waveform data may be too large or too small. */
#define NIRFSG_ERROR_NAN_OR_INF_FROM_IQ_CALCULATION -1074117712

/* hex: 0xBFFA43AF */
/* You must allocate and write your waveform with direct download set to the same value. */
#define NIRFSG_ERROR_WAVEFORM_WRITE_ALLOCATE_DIRECT_DOWNLOAD_MISMATCH -1074117713

/* hex: 0xBFFA43AE */
/* This function is not supported when using an external AWG. */
#define NIRFSG_ERROR_FUNCTION_NOT_SUPPORTED_WITH_EXTERNAL_AWG -1074117714

/* hex: 0xBFFA43AD */
/* The signal is outside of the upconverter passband. */
#define NIRFSG_ERROR_SIGNAL_OUTSIDE_PASSBAND -1074117715

/* hex: 0xBFFA43AC */
/* You cannot set the Power Level Type to Average Power in Script Mode.  Either change the Power Level Type to Peak Power or use the Arb Waveform Mode. */
#define NIRFSG_ERROR_AVERAGE_POWER_INVALID_IN_SCRIPT_MODE -1074117716

/* hex: 0xBFFA43AB */
/* The instrument driver does not support changing the value of the Simulation property after the session is created.  Use the Option String to configure the instrument driver for simulation. */
#define NIRFSG_ERROR_SIMULATION_NOT_WRITABLE -1074117717

/* hex: 0xBFFA43AA */
/* No waveforms were found.  The current configuration requires at least one waveform. */
#define NIRFSG_ERROR_NO_WAVEFORM_EXISTS -1074117718

/* hex: 0xBFFA43A9 */
/* The version of TClk NI-FGEN is using is not compatible with the NI-RFSG version.  Install the version of NI-FGEN that came with NI-RFSG. */
#define NIRFSG_ERROR_INCOMPATIBLE_ARB_TCLK_PROTOCOL -1074117719

/* hex: 0xBFFA43A8 */
/* The requested signal type is not valid. */
#define NIRFSG_ERROR_INVALID_SIGNAL_TYPE -1074117720

/* hex: 0xBFFA43A7 */
/* The Reference Clock is not a valid signal type for this operation. */
#define NIRFSG_ERROR_REF_CLOCK_INVALID_SIGNAL_TYPE -1074117721

/* hex: 0xBFFA43A6 */
/* The specified BoardType is not supported by the specified LO. The NI 5650/5651/5652 LO supported BoardTypes are PXI and PXIe. The NI 5653 LO supported BoardType is PXIe. */
#define NIRFSG_ERROR_BOARDTYPE_NOT_SUPPORTED -1074117722

/* hex: 0xBFFA43A5 */
/* The specified LOBoardType is not supported. The valid LOBoardTypes are PXI and PXIe. */
#define NIRFSG_ERROR_LO_BOARDTYPE_NOT_SUPPORTED -1074117723

/* hex: 0xBFFA43A4 */
/* The specified LO is not supported by the specified upconverter. The NI 5611 upconverter supported LOs include the NI PXI-5650, NI PXI-5651, NI PXI-5652, NI PXIe-5650, NI PXIe-5651, and NI PXIe-5652. */
#define NIRFSG_ERROR_LO_NOT_SUPPORTED -1074117724

/* hex: 0xBFFA43A3 */
/* The model you specified for simulation automatically selects the appropiate AWG. If you want to use a different AWG, specify the corresponding model or use the upconverter model and manually specify the AWG you want to use. */
#define NIRFSG_ERROR_DRIVER_AWG_KEYWORD_NOT_SUPPORTED -1074117725

/* hex: 0xBFFA43A2 */
/* The following attributes cannot be set simultaneously. */
#define NIRFSG_ERROR_CONFLICTING_CONFIGURATION -1074117726

/* hex: 0xBFFA43A1 */
/* Calibration is not supported on simulated devices. */
#define NIRFSG_ERROR_CALIBRATION_SESSION_NOT_SUPPORTED_IN_SIMULATION -1074117727

/* hex: 0xBFFA43A0 */
/* The session was closed, but the calibration data was not updated.  You must use niRFSG Close External Calibration to close your calibration session and save your calibration data. */
#define NIRFSG_ERROR_WRONG_CLOSE_FOR_CAL_SESSION -1074117728

/* hex: 0xBFFA439F */
/* A PLL lock error occurred.<LF/><LF/>If you are using an external reference, make sure it is connected and meets the frequency accuracy and voltage level requirements.  Also make sure the device has fully warmed up. */
#define NIRFSG_ERROR_PLL_LOCK -1074117729

/* hex: 0xBFFA439E */
/* Streaming does not work in Average Power mode. Change the power level type to Peak Power to use streaming. */
#define NIRFSG_ERROR_AVERAGE_POWER_INVALID_WITH_STREAMING -1074117730

/* hex: 0xBFFA439D */
/* Performing sets or gets on the non-active context while the device is running is not allowed. */
#define NIRFSG_ERROR_NON_ACTIVE_CONTEXT_WHILE_RUNNING -1074117731

/* hex: 0xBFFA439C */
/* The values the script is trying to inherit from the waveforms are incompatible with each other. */
#define NIRFSG_ERROR_INCOMPATIBLE_SCRIPT_INHERITANCE -1074117732

/* hex: 0xBFFA439B */
/* Changing the value to or from the special value while the device is running is not allowed. */
#define NIRFSG_ERROR_SPECIAL_VALUE_WHILE_RUNNING -1074117733

/* hex: 0xBFFA439A */
/* Resetting an attribute with a context is not allowed. */
#define NIRFSG_ERROR_WAVEFORM_ATTRIBUTE_AND_RESET_ATTRIBUTE -1074117734

/* hex: 0xBFFA4399 */
/* The peer-to-peer endpoint is not available on the FPGA bitfile for your device. This may be caused by renaming or removing the peer-to-peer FIFO on the bitfile. */
#define NIRFSG_ERROR_ENDPOINT_NOT_AVAILABLE -1074117735

/* hex: 0xBFFA4398 */
/* A session cannot be created because the AE resource name is invalid. Verify the AE resource name in MAX by selecting the NI 5654 in the configuration tree and specifying the AE name within the Associated Devices section. If you specify the AE using the Option String, ensure the AE resource name is valid. */
#define NIRFSG_ERROR_INVALID_AE_RESOURCE_NAME -1074117736

/* hex: 0xBFFA4397 */
/* This function is not supported when an AE is not associated. */
#define NIRFSG_ERROR_FUNCTION_NOT_SUPPORTED_IF_AE_IS_NOT_ASSOCIATED -1074117737

/* hex: 0xBFFA4396 */
/* The niRFSG Perform Power Search function is not supported when the output is disabled. */
#define NIRFSG_ERROR_PWR_SEARCH_NOT_SUPPORTED_IF_OUTPUT_IS_DISABLED -1074117738

/* hex: 0xBFFA4395 */
/* The niRFSG Perform Power Search function is not supported when the ALC Control property is enabled. */
#define NIRFSG_ERROR_PWR_SEARCH_NOT_SUPPORTED_IF_ALC_IS_ENABLED -1074117739

/* hex: 0xBFFA4394 */
/* Modulation is not supported when the ALC Control property is enabled. */
#define NIRFSG_ERROR_MODULATION_NOT_SUPPORTED_IF_ALC_IS_ENABLED -1074117740

/* hex: 0xBFFA4393 */
/* The configured Reference Clock rate does not match the actual Reference Clock rate detected by the device. */
#define NIRFSG_ERROR_CONFIGURED_REF_CLOCK_RATE_NOT_MATCHING_ACTUAL_REF_CLOCK_RATE -1074117741

/* hex: 0xBFFA4392 */
/* The number of attributes specified does not match the number of values provided. */
#define NIRFSG_ERROR_LIST_MODE_NUMBER_OF_ATTRIBUTES_NOT_MATCHING_NUMBER_OF_VALUES -1074117742

/* hex: 0xBFFA4391 */
/* The configuration list data provided cannot be null or empty. */
#define NIRFSG_ERROR_LIST_MODE_CONFIGURATION_LIST_DATA_CANNOT_BE_NULL_OR_EMPTY -1074117743

/* hex: 0xBFFA4390 */
/* A trigger source must be specified for the given trigger type. */
#define NIRFSG_ERROR_TRIGGER_SOURCE_NOT_SPECIFIED -1074117744

/* hex: 0xBFFA438F */
/* Attempted to initiate a generation session with multiple scripts without selecting a script to generate.  Use the Selected Script property to specify a script for the device to execute. */
#define NIRFSG_ERROR_ACTIVE_SCRIPT_NOT_SPECIFIED -1074117745

/* hex: 0xBFFA438E */
/* The endpoint name is invalid. The syntax for valid endpoint names is FIFOEndpointN, where N is an integer that represents the endpoint. 0 represents the first endpoint. */
#define NIRFSG_ERROR_INVALID_ENDPOINT_NAME -1074117746

/* hex: 0xBFFA438D */
/* An underflow occurred during the peer-to-peer stream. Ensure the writer endpoint is writing data at a high enough rate to keep up with generation. */
#define NIRFSG_ERROR_P2P_UNDERFLOW -1074117747

/* hex: 0xBFFA438C */
/* The LO alignment procedure failed because the power at the LO IN terminal is too high. */
#define NIRFSG_ERROR_LO_ALIGNMENT_LO_IN_POWER_TOO_HIGH -1074117748

/* hex: 0xBFFA438B */
/* The LO alignment procedure failed because the power at the LO IN terminal is too low. */
#define NIRFSG_ERROR_LO_ALIGNMENT_LO_IN_POWER_TOO_LOW -1074117749

/* hex: 0xBFFA438A */
/* LO alignment is not supported for configurations where the RF input LO OUT is connected to the RF output LO IN on the same module. */
#define NIRFSG_ERROR_LO_ALIGNMENT_SA_EXPORT_TO_SG_ON_SAME_MODULE -1074117750

/* hex: 0xBFFA4389 */
/* Set the following waveform attribute to continue. */
#define NIRFSG_ERROR_WAVEFORM_ATTRIBUTE_NOT_SET -1074117751

/* hex: 0xBFFA4388 */
/* An interaction with TDMS has caused the following error */
#define NIRFSG_ERROR_TDMS_INTERACTION_FAILED -1074117752

/* hex: 0xBFFA4387 */
/* Waveform file version is not supported. Minimum supported version is 2.0.0. */
#define NIRFSG_ERROR_WAVEFORM_FILE_VERSION_NOT_SUPPORTED -1074117753

/* hex: 0xBFFA4386 */
/* Waveform data must be interleaved I and Q samples. */
#define NIRFSG_ERROR_WAVEFORM_DATA_NOT_INTERLEAVED_I_Q -1074117754

/* hex: 0xBFFA4385 */
/* Waveform data type not supported. */
#define NIRFSG_ERROR_WAVEFORM_DATA_TYPE_NOT_SUPPORTED -1074117755

/* hex: 0xBFFA4384 */
/* One or more required waveform properties are missing in the waveform file. */
#define NIRFSG_ERROR_WAVEFORM_PROPERTY_MISSING_FROM_FILE -1074117756

/* hex: 0xBFFA4383 */
/* Number of RF blanking marker positions present in the waveform file is invalid. RF blanking marker positions should always be in pairs. */
#define NIRFSG_ERROR_INVALID_RF_BLANKING_POSITIONS -1074117757

/* hex: 0xBFFA4382 */
/* Marker event locations must be whole numbers. */
#define NIRFSG_ERROR_INVALID_MARKER_EVENT_LOCATIONS -1074117758

/* hex: 0xBFFA4381 */
/* Burst Start Locations and Burst Stop Locations must be in ascending order. */
#define NIRFSG_ERROR_BURST_LOCATIONS_NOT_IN_ASCENDING_ORDER -1074117759

/* hex: 0xBFFA4380 */
/* Burst Start Locations and Burst Stop Locations must be whole numbers. */
#define NIRFSG_ERROR_BURST_LOCATIONS_NOT_WHOLE_NUMBERS -1074117760

/* hex: 0xBFFA437F */
/* Burst Start Locations and Burst Stop Locations must be less than waveform size. */
#define NIRFSG_ERROR_BURST_LOCATIONS_OUTSIDE_WAVEFORM -1074117761

/* hex: 0xBFFA437E */
/* Burst Start Locations count must be equal to or greater than Burst Stop Locations count by 1. */
#define NIRFSG_ERROR_INVALID_BURST_LOCATIONS -1074117762

/* hex: 0xBFFA437D */
/* Burst Start and Stop Locations should be configured to perform blanking. */
#define NIRFSG_ERROR_BURST_LOCATIONS_NOT_CONFIGURED -1074117763

/* hex: 0xBFFA437C */
/* Burst Start Locations must be less than the corresponding Burst Stop Locations. */
#define NIRFSG_ERROR_BURST_START_LOCATION_GREATER_THAN_BURST_STOP_LOCATION -1074117764

/* hex: 0xBFFA437B */
/* The driver version saved in the file is higher than the current installed driver. */
#define NIRFSG_ERROR_INCOMPATIBLE_DRIVER_VERSION -1074117765

/* hex: 0xBFFA437A */
/* Loading configuration is not allowed while session is running. */
#define NIRFSG_ERROR_LOAD_WHILE_SESSION_IS_RUNNING -1074117766

/*********************************/
/*********** Warnings ************/
/*********************************/

/* hex: 0x3FFA43ED */
/* Waveform could not be downloaded. */
#define NIRFSG_WARN_READ_AND_DOWNLOAD_UNSUCCESSFUL 1073365997

/* hex: 0x3FFA43EE */
/* Waveform filepath is invalid. */
#define NIRFSG_WARN_INVALID_WAVEFORM_FILEPATH 1073365998

/* hex: 0x3FFA43EF */
/* Calibration constants stored in the EEPROM are missing or invalid. The device will continue to function, but the accuracy of the measurements may be compromised. This may be due to an incorrect calibration or corrupted calibration data in the EEPROM. Perform either an external calibration, self-calibration, or contact NI technical support. */
#define NIRFSG_WARN_CALIBRATION_DATA_NOT_PRESENT 1073365999

/* hex: 0x3FFA43F0 */
/* Unable to correct for temperature deviation. The power level accuracy is not guaranteed. Re-commit the settings to regain accuracy. */
#define NIRFSG_WARN_TEMPERATURE_DEVIATION_LIMIT_EXCEEDED 1073366000

/* hex: 0x3FFA43F1 */
/* Overflow detected in the Arb's Digital Gain circuit. Output waveform was clipped. Reduce the Arb Pre Filter Gain to eliminate overflow. */
#define NIRFSG_WARN_ARB_OVERFLOW_DIGITAL_GAIN 1073366001

/* hex: 0x3FFA43F3 */
/* Attenuator Hold is enabled, but the held attenuator combination is not calibrated at the new frequency. The nearest calibrated attenuator combination was selected. This is expected for some frequency changes. The ideal attenuation distribution between amplifiers varies across frequency bands, and only the ideal attenuation combination is calibrated. */
#define NIRFSG_WARN_ATTENUATOR_HOLD_OVERRIDDEN_INVALID_ATTENUATOR 1073366003

/* hex: 0x3FFA43F4 */
/* Requested attribute value exceeds device specification limits. Device performance is not guaranteed. */
#define NIRFSG_WARN_OUT_OF_SPECIFICATION_USER_SETTING 1073366004

/* hex: 0x3FFA43F5 */
/* Attenuator Hold is enabled, and the requested Power Level is out of range for the selected attenuator. Note that once the attenuator is selected, the max power for that attenuator varies with configuration changes, including changes to frequency, IQ impairments, and prefilter gain. */
#define NIRFSG_WARN_POWER_OUT_OF_RANGE_FOR_ATTENUATOR_HOLD 1073366005

/* hex: 0x3FFA43F6 */
/* The signal is outside of the upconverter passband. */
#define NIRFSG_WARN_SIGNAL_OUTSIDE_PASSBAND 1073366006

/* hex: 0x3FFA43F7 */
/* Thermal Correction has reached its limit. Note: The amount of correction that can be applied is limited because Attenuator Hold is currently enabled. */
#define NIRFSG_WARN_COMPENSATION_LIMITED_BY_ATTENUATOR_HOLD 1073366007

/* hex: 0x3FFA43F8 */
/* IQ Rate was coerced, but coerced IQ Rate was never read. To eliminate this warning, read the IQ Rate before committing or initiating the generation, and account for the coerced IQ Rate as appropriate in your application. */
#define NIRFSG_WARN_COERCED_IQ_RATE_NEVER_READ 1073366008

/* hex: 0x3FFA43F9 */
/* Signal Bandwidth exceeds FIR Filter Passband Bandwidth. Ensure the specified Signal Bandwidth is correct, or increase the IQ Rate. The Arb FIR Filter Passband is -0.4*IQ Rate to +0.4*IQ Rate. */
#define NIRFSG_WARN_ARB_FILTER_BANDWIDTH_EXCEEDED 1073366009

/* hex: 0x3FFA43FA */
/* The Arb's OSP circuit detected an overflow due to an IQ pair with an absolute value greater than 1.0 (after the FIR and CIC filters). Output waveform was clipped. Reduce the Arb Pre Filter Gain to eliminate overflow. */
#define NIRFSG_WARN_ARB_OVERFLOW_IQ_SUM 1073366010

/* hex: 0x3FFA43FB */
/* Overflow detected in the Arb's CIC Filter. Output waveform was clipped. Reduce the Arb Pre Filter Gain to eliminate overflow. */
#define NIRFSG_WARN_ARB_OVERFLOW_CIC_FILTER 1073366011

/* hex: 0x3FFA43FC */
/* Overflow detected in the Arb's FIR Filter. Output waveform was clipped. Reduce the Arb Pre Filter Gain to eliminate overflow. */
#define NIRFSG_WARN_ARB_OVERFLOW_FIR_FILTER 1073366012

/* hex: 0x3FFA43FD */
/* Output signal may not be phase continuous. Remove this notification by setting the Phase Continuity Mode attribute to Disable. Refer to the documentation for more information. */
#define NIRFSG_WARN_SIGNAL_NOT_PHASE_CONTINUOUS 1073366013

/* hex: 0x3FFA43FE */
/* Output generation had been aborted by the reverse power protection circuitry of the device. Either the output signal exceeded the output power limit, or power was driven back into the output of the device by an external source. Error state is cleared. */
#define NIRFSG_WARN_REVERSE_POWER_PROTECTION 1073366014

/* hex: 0x3FFA43FF */
/* The specified value is outside the valid range. Device performance is not guaranteed. */
#define NIRFSG_WARN_OUT_OF_RANGE 1073366015


#endif /* ___niRFSG_niRFSGErrors_h___ */
