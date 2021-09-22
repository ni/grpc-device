#ifndef ___niRFSA_niRFSAErrors_h___
#define ___niRFSA_niRFSAErrors_h___

/*******************************/
/*********** Errors ************/
/*******************************/

/* hex:0xBFFA4165 */
/* This function is not supported when the device is configured to run as a debug session while using breakpoints in C/C++/.NET applications. */
#define NIRFSA_ERROR_FUNCTION_NOT_SUPPORTED_IN_DEBUG_SESSION -1074118299

/* hex:0xBFFA4164 */
/* Invalid operation due to the acquired data value reference. Call Delete Data Value Reference on all outstanding data value references before calling this operation. */
#define NIRFSA_ERROR_OUTSTANDING_DATA_VALUE_REFERENCE -1074118300

/* hex:0xBFFA4163 */
/* The signal is outside of the downconverter passband. */
#define NIRFSA_ERROR_SIGNAL_OUTSIDE_DOWNCONVERTER_PASSBAND -1074118301

/* hex:0xBFFA4162 */
/* The calibration synthesizer failed to lock. */
#define NIRFSA_ERROR_CAL_SYNTH_FAILED_TO_LOCK -1074118302

/* hex:0xBFFA4161 */
/* A basecard PLL is unlocked. */
#define NIRFSA_ERROR_BASECARD_PLL_UNLOCKED -1074118303

/* hex:0xBFFA4160 */
/* A calibration measurement error occurred. The ADC overflowed while taking a measurement. */
#define NIRFSA_ERROR_CAL_ADC_OVERFLOW -1074118304

/* hex:0xBFFA415F */
/* The device ADC reported a fatal error. */
#define NIRFSA_ERROR_ADC_REPORTED_FATAL_ERROR -1074118305

/* hex:0xBFFA415E */
/* The number of samples to fetch cannot be set to -1 (default) when fetching from records that have been configured with different numbers of samples. */
#define NIRFSA_ERROR_CANNOT_FETCH_NEG_ONE_SAMPLES_IN_DIFFERENT_SIZE_RECORDS -1074118306

/* hex:0xBFFA415D */
/* This device does not support record-based peer-to-peer streaming. When peer-to-peer is enabled, Number of Records must be set to 1 for finite acquisitions, and Reference and Advance Triggers must be set to None. */
#define NIRFSA_ERROR_P2P_RECORDS_NOT_SUPPORTED -1074118307

/* hex:0xBFFA415C */
/* The peer-to-peer endpoint is not available on the FPGA bitfile for your device. This may be caused by renaming or removing of the peer-to-peer FIFO on the bitfile. */
#define NIRFSA_ERROR_ENDPOINT_NOT_AVAILABLE -1074118308

/* hex:0xBFFA415B */
/* The requested action is invalid while onboard memory is disabled and peer-to-peer is enabled. */
#define NIRFSA_ERROR_ONBOARD_MEMORY_DISABLED -1074118309

/* hex:0xBFFA415A */
/* The endpoint name is invalid. The syntax for valid endpoint names is FIFOEndpointN, where N is an integer that represents the endpoint. 0 represents the first endpoint. */
#define NIRFSA_ERROR_INVALID_ENDPOINT_NAME -1074118310

/* hex:0xBFFA4159 */
/* The given configuration results in a computed acquisition size that is too large. Reduce the span, increase the resolution bandwidth, or use another resolution bandwidth type. */
#define NIRFSA_ERROR_MAX_ACQUISITION_SIZE_EXCEEDED -1074118311

/* hex:0xBFFA4158 */
/* You cannot specify multiple channels or repeated capabilities. */
#define NIRSFA_ERROR_MULTIPLE_REPEATED_CAPABILITY_NOT_ALLOWED -1074118312

/* hex:0xBFFA4157 */
/* External Calibration Missing Measurement */
#define NIRFSA_ERROR_EXTERNAL_CALIBRATION_MISSING_MEASUREMENT -1074118313

/* hex:0xBFFA4156 */
/* The given configuration results in a computed value of Spectral Lines that is too large. Reduce the Span, increase the Resolution Bandwidth, or use another Resolution Bandwidth Type. */
#define NIRFSA_ERROR_MAX_NUMBER_OF_SPECTRAL_LINES_EXCEEDED -1074118314

/* hex:0xBFFA4155 */
/* This trigger type is not supported in multispan spectrum acquisition. */
#define NIRFSA_ERROR_TRIGGERING_TYPE_NOT_SUPPORTED_IN_MULTISPAN -1074118315

/* hex:0xBFFA4154 */
/* Self calibration data is missing or invalid. Try performing a self calibration on the device and try again. */
#define NIRFSA_ERROR_SELF_CALIBRATION_DATA_MISSING_OR_INVALID -1074118316

/* hex:0xBFFA4153 */
/* Selected steps to omit are invalid or unsupported for specific session type or device type. */
#define NIRFSA_ERROR_RESET_WITH_OPTION_STEPS_TO_OMIT_INVALID -1074118317

/* hex:0xBFFA4152 */
/* An acquisition data overflow occurred. Not fetching records or not checking the acquisition status fast enough might cause this. */
#define NIRFSA_ERROR_ACQUISITION_DATA_OVERFLOW -1074118318

/* hex:0xBFFA4151 */
/* The currently installed version of NI-RFSA is not compatible with the currently installed version of  NI PXIe-5668R Support. Upgrade your NI-RFSA installation, or downgrade your NI PXIe-5668R Support installation. */
#define NIRFSA_ERROR_INCOMPATIBLE_IFDIG_DRIVER_VERSION -1074118319

/* hex:0xBFFA4150 */
/* This functionality is not available with the current bitfile */
#define NIRFSA_ERROR_FUNCTIONALITY_NOT_SUPPORTED_WITH_CURRENT_BITFILE -1074118320

/* hex:0xBFFA414F */
/* You cannot simulate a connection to Session Access enabled device. */
#define NIRFSA_ERROR_CLIENT_SESSION_NOT_SUPPORTED_IN_SIMULATION -1074118321

/* hex:0xBFFA414E */
/* The initialize failed due to the device being busy with a pending read or calibration operation. */
#define NIRFSA_ERROR_INIT_FAIL_DEVICE_BUSY -1074118322

/* hex:0xBFFA414D */
/* You cannot simulate a connection to a session access enabled device. */
#define NIRFSA_ERROR_CANNOT_SIMULATE_CONNECTION_TO_SESSION_ACCESS_ENABLED_DEVICE -1074118323

/* hex:0xBFFA414C */
/* Device Session access is not available. Suspend the operation on the device before requesting device session access again. */
#define NIRFSA_ERROR_DEVICE_SESSION_ACCESS_NOT_AVAILABLE -1074118324

/* hex:0xBFFA414B */
/* The module EEPROM is not formatted correctly. Format the EEPROM. Contact NI Technical Support if you need additional information or the problem persists. */
#define NIRFSA_ERROR_EEPROM_NOT_FORMATTED -1074118325

/* hex:0xBFFA414A */
/* The resolution bandwidth specified is larger than the instantaneous bandwidth of the device for one or more spans or the configured FFT width in the spectrum acquisition. This can result in the loss of information in the overall spectrum. Reduce the resolution bandwidth to acquire more accurate data. */
#define NIRFSA_ERROR_RBW_LARGER_THAN_DEVICE_BW -1074118326

/* hex:0xBFFA4149 */
/* NI-RFSA failed to detect the calibration tone while running self calibration. Ensure that all the modules in the system are properly connected by running the test panel in MAX. Contact NI technical support at ni.com/support if this problem persists. */
#define NIRFSA_ERROR_CAL_TONE_NOT_DETECTED -1074118327

/* hex:0xBFFA4148 */
/* An RF power overload has occurred on the device. The device's signal chain has been disconnected to protect the device. Remove the input signal, reduce the input signal power, or increase the system attenuation. */
#define NIRFSA_ERROR_RF_OVERLOAD -1074118328

/* hex:0xBFFA4147 */
/* An IF power overload has occurred on the device. The device's signal chain has been disconnected to protect the device. Remove the input signal, reduce the input signal power, or increase the system attenuation. */
#define NIRFSA_ERROR_IF_OVERLOAD -1074118329

/* hex:0xBFFA4146 */
/* An RF and IF power overload has occurred on the device. The device's signal chain has been disconnected to protect the device. Remove the input signal, reduce the input signal power, or increase the system attenuation. */
#define NIRFSA_ERROR_IF_AND_RF_OVERLOAD -1074118330

/* hex:0xBFFA4145 */
/* The IF Conditioning device returned the following error: */
#define NIRFSA_ERROR_IF_CONDITIONING_ERROR -1074118331

/* hex:0xBFFA4144 */
/* The RF Conditioning device returned the following error: */
#define NIRFSA_ERROR_RF_CONDITIONING_ERROR -1074118332

/* hex:0xBFFA4143 */
/* Child device missing in the current combined device configuration. */
#define NIRFSA_ERROR_CHILD_DEVICE_MISSING -1074118333

/* hex:0xBFFA4142 */
/* The IF Conditioning device is not supported in the current combined device configuration. */
#define NIRFSA_ERROR_IF_CONDITIONING_DEVICE_NOT_SUPPORTED_FOR_COMBINED_DEVICE -1074118334

/* hex:0xBFFA4141 */
/* RF Preselector not supported in the current combined device configuration. */
#define NIRFSA_ERROR_RF_PRESELECTOR_NOT_SUPPORTED_FOR_COMBINED_DEVICE -1074118335

/* hex:0xBFFA4140 */
/* The specified IF Conditioning device is not supported by NI-RFSA. */
#define NIRFSA_ERROR_IF_CONDITIONING_DEVICE_NOT_SUPPORTED -1074118336

/* hex:0xBFFA413F */
/* The specified RF Preselector is not supported by NI-RFSA. */
#define NIRFSA_ERROR_RF_PRESELECTOR_NOT_SUPPORTED -1074118337

/* hex:0xBFFA413E */
/* IF Conditioning device resource name is invalid. The resource name can be invalid because you either associated an invalid IF Conditioning device resource name in MAX with the downconverter or because you tried to use niRFSA Init With Options with a DriverSetup string that included an invalid IF Conditioning device resource name. */
#define NIRFSA_ERROR_INVALID_IF_CONDITIONING_DEVICE_RESOURCE_NAME -1074118338

/* hex:0xBFFA413D */
/* RF Preselector resource name is invalid. The resource name can be invalid because you either associated an invalid RF Preselector resource name in MAX with the downconverter or because you tried to use niRFSA Init With Options with a DriverSetup string that included an invalid RF Preselector resource name. */
#define NIRFSA_ERROR_INVALID_RF_PRESELECTOR_RESOURCE_NAME -1074118339

/* hex:0xBFFA413C */
/* The number of samples to fetch cannot be set to -1 (default) when contiguous multi record is enabled. */
#define NIRFSA_ERROR_CANNOT_FETCH_NEG_ONE_SAMPLES_IN_CONTIG_MULTIREC -1074118340

/* hex:0xBFFA413B */
/* The requested amplitude settling is not achievable while in list mode. */
#define NIRFSA_ERROR_AMPLITUDE_SETTLING_NOT_ACHIEVABLE_IN_LIST_MODE -1074118341

/* hex:0xBFFA413A */
/* An attribute value conflicts with the value that the current external alignment step needs to configure. */
#define NIRFSA_ERROR_EXT_ALIGNMENT_ATTR_CONFLICT_WITH_USER -1074118342

/* hex:0xBFFA4139 */
/* The preselector alignment coeffcients are invalid. */
#define NIRFSA_ERROR_INVALID_PRESELECTOR_ALIGNMENT_COEFFICIENTS -1074118343

/* hex:0xBFFA4138 */
/* Requested operation cannot be used during an external alignment session. */
#define NIRFSA_ERROR_INVALID_FUNCTION_IN_EXT_ALIGNMENT_SESSION -1074118344

/* hex:0xBFFA4137 */
/* An external alignment function cannot be used on a non external alignment session. */
#define NIRFSA_ERROR_EXT_ALIGNMENT_FUNC_OUTSIDE_ALIGNMENT_SESSION -1074118345

/* hex:0xBFFA4136 */
/* The device temperature varied more than allowed while performing the external alignment operation. */
#define NIRFSA_ERROR_EXT_ALIGNMENT_TEMP_DEVIATION_EXCEEDED -1074118346

/* hex:0xBFFA4135 */
/* An invalid external alignment step has been provided. */
#define NIRFSA_ERROR_INVALID_EXT_ALIGNMENT_STEP -1074118347

/* hex:0xBFFA4134 */
/* This external alignment function is not supported on this device. */
#define NIRFSA_ERROR_EXT_ALIGNMENT_FUNC_NOT_SUPPORTED -1074118348

/* hex:0xBFFA4133 */
/* External Alignment operations cannot be performed on simulated devices. */
#define NIRFSA_ERROR_EXT_ALIGNMENT_SESSION_NOT_SUPPORTED_IN_SIMULATION -1074118349

/* hex:0xBFFA4132 */
/* Self calibration procedure failed. If this is the first time you have seen this error, check your connections and try again. If the problem persists, contact NI for technical support. */
#define NIRFSA_ERROR_SELF_CALIBRATION_FAILED -1074118350

/* hex:0xBFFA4131 */
/* Size of calibration data adjusted exceeds on board memory capacity. */
#define NIRFSA_ERROR_EEPROM_CALIBRATION_DATA_OVERFLOW -1074118351

/* hex:0xBFFA4130 */
/* Relay count operations are not supported on this device */
#define NIRFSA_ERROR_RELAY_COUNT_NOT_SUPPORTED -1074118352

/* hex:0xBFFA412F */
/* Calibration Tone Frequency was found to exceed maximum deviation. Make sure the PXI chassis backplane clock and the LO Reference Clock are both locked to the same source. */
#define NIRFSA_ERROR_CAL_TONE_FREQUENCY_MAX_DEVIATION_EXCEEDED -1074118353

/* hex:0xBFFA412E */
/* The specified calibration gain adjustment is invalid, verify calibration setup is correct. Contact NI support for further information */
#define NIRFSA_ERROR_EXTCAL_INVALID_GAIN_ADJUSTED -1074118354

/* hex:0xBFFA412D */
/* Adjacent Channel Power Ratio (ACPR) measurements are not supported in the current IF Filter path. Choose a narrower IF Filter by decreasing Span or Device Instantaneous Bandwidth. */
#define NIRFSA_ERROR_ACPR_NOT_SUPPORTED_IN_FILTER_PATH -1074118355

/* hex:0xBFFA412C */
/* Adjacent Channel Power Ratio (ACPR) measurement calibration is not supported with the selected IF filter path, Choose a different table type or a narrower filter. */
#define NIRFSA_ERROR_ACPR_CALIBRATION_NOT_SUPPORTED_IN_FILTER_PATH -1074118356

/* hex:0xBFFA412B */
/* NI-RFSA cannot achieve the specified calibration tone frequency. To solve this issue, try changing the requested resolution. */
#define NIRFSA_ERROR_CALIBRATION_TONE_INVALID -1074118357

/* hex:0xBFFA412A */
/* The number of frequencies and LO attenuation settings being passed to the function are not the same. Ensure the arrays you pass to the function have the same number of elements. */
#define NIRFSA_ERROR_NUMBER_OF_FREQUENCIES_LO_ATTENUATION_MISMATCH -1074118358

/* hex:0xBFFA4129 */
/* NI-RFSA cannot initialize a calibration session because another calibration session for the specified device is already open. Close the open session by calling niRFSA Close Ext Cal or by exiting the application with the open session. */
#define NIRFSA_ERROR_CAL_SESSION_ALREADY_EXISTS -1074118359

/* hex:0xBFFA4128 */
/* Calibration is not supported on simulated devices. */
#define NIRFSA_ERROR_CALIBRATION_SESSION_NOT_SUPPORTED_IN_SIMULATION -1074118360

/* hex:0xBFFA4127 */
/* You have exceeded the EEPROM memory space allocated for Self Cal. Run Self Cal again for all invalid steps, or contact NI technical support. */
#define NIRFSA_ERROR_EEPROM_SPACE_EXCEEDED_FOR_SELF_CAL -1074118361

/* hex:0xBFFA4126 */
/* The gain associated with the specified index is not valid for the specified frequency. */
#define NIRFSA_ERROR_INVALID_IF_GAIN_FOR_FREQUENCY -1074118362

/* hex:0xBFFA4125 */
/* The parameter value specified is not supported when using an external digitizer. */
#define NIRFSA_ERROR_INVALID_PARAMETER_VALUE_FOR_EXTERNAL_DIGITIZER -1074118363

/* hex:0xBFFA4124 */
/* This property or attribute is supported only during a calibration session. */
#define NIRFSA_ERROR_ATTR_NOT_SUPPORTED_IN_NON_CALIBRATION_SESSION -1074118364

/* hex:0xBFFA4123 */
/* LO2 and LO3 calibration adjustment supports adjusting only a single LO frequency (4 GHz  and 800 MHz, respectively). */
#define NIRFSA_ERROR_INVALID_LO_EXPORT_CALIBRATION_NUMBER_OF_FREQUENCIES -1074118365

/* hex:0xBFFA4122 */
/* The device temperature deviation during calibration exceeded the maximum allowed amount. To correct the issue, ensure good ventilation and a stable room temperature, and set the fan speed to its maximum. */
#define NIRFSA_ERROR_CALIBRATION_TEMPERATURE_DEVIATION_EXCEEDED -1074118366

/* hex:0xBFFA4121 */
/* A configuration property or attribute that is required for calibration is missing. Commit these properties and attributes prior to calling calibration adjustment VIs and functions. */
#define NIRFSA_ERROR_REQUIRED_CALIBRATION_PARAMETER_MISSING -1074118367

/* hex:0xBFFA4120 */
/* An invalid LO export number was provided to the niRFSA Cal Adjust LO Export Calibration function. */
#define NIRFSA_ERROR_INVALID_LO_EXPORT_NUMBER -1074118368

/* hex:0xBFFA411F */
/* The LO Export attenuation was adjusted to a value outside the supported range. */
#define NIRFSA_ERROR_LO_EXPORT_ATTENUATION_OUT_OF_RANGE -1074118369

/* hex:0xBFFA411E */
/* The maximum supported mixer level was exceeded. This problem is usually caused by forcing low RF attenuation. To correct the issue, increase the RF attenuation so that the mixer level is equal to the reference level minus the RF attenuation plus RF gain. */
#define NIRFSA_ERROR_MAXIMUM_MIXER_LEVEL_EXCEEDED -1074118370

/* hex:0xBFFA411D */
/* NI-RFSA failed to align the YIG tunable filter (YTF). */
#define NIRFSA_ERROR_YTF_ALIGNMENT_DOES_NOT_COVER_RANGE -1074118371

/* hex:0xBFFA411C */
/* NI-RFSA failed to detect a signal while calibrating the YTF module. Ensure that your LO and digitizer are properly connected by running the test panel in MAX. */
#define NIRFSA_ERROR_YTF_ALIGNMENT_SIGNAL_DETECTION_FAILED -1074118372

/* hex:0xBFFA411B */
/* Creation of the simulated device failed. Connection to the MXS database is taking too long. Restart your system, and if this process does not solve the problem, contact NI technical support. */
#define NIRFSA_ERROR_SIMULATED_DEVICE_CREATION_FAILED -1074118373

/* hex:0xBFFA411A */
/* NI-RFSA does not support the specified LO. */
#define NIRFSA_ERROR_LO_NOT_SUPPORTED -1074118374

/* hex:0xBFFA4119 */
/* The specified keyword is not supported in this session. Real sessions support Digitizer and LO Driver Setup keywords, while simulated sessions support DigitizerModel and LOModel Driver Setup keywords. Refer to the documentation for more information about Driver Setup keywords. */
#define NIRFSA_ERROR_KEYWORD_NOT_SUPPORTED_IN_SESSION -1074118375

/* hex:0xBFFA4118 */
/* An internal software error has occurred. Contact NI technical support at ni.com/support, with the following information: There are too many endpoints for streaming initialization. */
#define NIRFSA_ERROR_TOO_MANY_STREAMING_ENDPOINTS -1074118376

/* hex:0xBFFA4117 */
/* An internal software error has occurred. Contact NI technical support at ni.com/support, with the following information: The file size is too large for parameter block. */
#define NIRFSA_ERROR_FILESIZE_OVERFLOW -1074118377

/* hex:0xBFFA4116 */
/* The Reference clock is not a valid value for this operation. */
#define NIRFSA_ERROR_REF_CLOCK_INVALID_SIGNAL_TYPE -1074118378

/* hex:0xBFFA4115 */
/* An internal software error has occurred. Contact NI technical support at ni.com/support, with the following information: The attenuation table has too many entries. */
#define NIRFSA_ERROR_TOO_MANY_ELEMENTS_IN_ATTENUATION_TABLE -1074118379

/* hex:0xBFFA4114 */
/* An internal software error has occurred. Contact NI technical support at ni.com/support, with the following information: The band has too many frequencies for calibration. */
#define NIRFSA_ERROR_TOO_MANY_FREQUENCIES_IN_BAND -1074118380

/* hex:0xBFFA4113 */
/* An internal software error has occurred. Contact NI technical support at ni.com/support, with the following information: There are too many elements for the EEPROM size. */
#define NIRFSA_ERROR_EEPROM_ELEMENT_OVERFLOW -1074118381

/* hex:0xBFFA4112 */
/* An internal software error has occurred. Contact NI technical support at ni.com/support, with the following information: The size of the LabVIEW array is too large. */
#define NIRFSA_ERROR_LABVIEW_ARRAY_TOO_LARGE -1074118382

/* hex:0xBFFA4111 */
/* You have exceeded the maximum number of configuration list steps supported for your device. */
#define NIRFSA_ERROR_MAX_STEP_COUNT_EXCEEDED -1074118383

/* hex:0xBFFA4110 */
/* NI-RFSA cannot get the frequency response. Calibration data is not available for this device configuration. */
#define NIRFA_ERROR_CANNOT_GET_FREQUENCY_RESPONSE -1074118384

/* hex:0xBFFA410F */
/* The currently installed version of NI-RFSA is not compatible with the currently installed version of NI-RFSG. Downgrade your NI-RFSA installation, or upgrade your NI-RFSG installation. */
#define NIRFSA_ERROR_NIRFSG_DRIVER_VERSION_TOO_OLD -1074118385

/* hex:0xBFFA410E */
/* The currently installed version of NI-RFSA is not compatible with the currently installed version of NI-RFSG. Upgrade your NI-RFSA installation, or downgrade your NI-RFSG installation. */
#define NIRFSA_ERROR_NIRFSG_DRIVER_VERSION_TOO_NEW -1074118386

/* hex:0xBFFA410D */
/* The number of measurements taken for reference level calibration is insufficient. Please refer to the calibration procedure document to see the list of required measurement configurations. */
#define NIRFSA_ERROR_INVALID_ALT_REF_CAL_MEASUREMENTS -1074118387

/* hex:0xBFFA410C */
/* The option string has too many characters. */
#define NIRFSA_ERROR_OPTION_STRING_TOO_LONG -1074118388

/* hex:0xBFFA410B */
/* The LVDLL returned the following error: */
#define NIRFSA_ERROR_LVDLL_ERROR -1074118389

/* hex:0xBFFA410A */
/* The combination of the number of records, number of samples per record, and the size of sample in bytes exceeds maximum allowed allocation size. */
#define NIRFSA_ERROR_REQUESTED_ALLOCATION_TOO_LARGE -1074118390

/* hex:0xBFFA4109 */
/* There are insufficient number of IF Attenuation measurements. The required number of measurements is 256. */
#define NIRFSA_ERROR_INVALID_CAL_NUM_OF_IF_ATTEN_MEASUREMENTS -1074118391

/* hex:0xBFFA4108 */
/* The specified operation cannot be performed while the device is being reset. */
#define NIRFSA_ERROR_OPERATION_NOT_SUPPORTED_DURING_RESET -1074118392

/* hex:0xBFFA4107 */
/* Password is longer than maximum length. */
#define NIRFSA_ERROR_CAL_PASSWORD_LENGTH_VIOLATION -1074118393

/* hex:0xBFFA4106 */
/* The number of frequencies is different than the number of DAC values. They should be the same. */
#define NIRFSA_ERROR_FREQUENCY_DAC_VALUE_ARRAY_SIZE_VIOLATION -1074118394

/* hex:0xBFFA4105 */
/* The calibration close action specified is not supported by this instrument driver. The valid values for calibration action are Commit or Abort. */
#define NIRFSA_ERROR_INVALID_CLOSE_ACTION -1074118395

/* hex:0xBFFA4104 */
/* Requested operation cannot be used during an external calibration session. */
#define NIRFSA_ERROR_INVALID_FUNCTION_IN_CAL_SESSION -1074118396

/* hex:0xBFFA4103 */
/* The calibration number of measurements specified is not supported by this instrument driver. The number of measurements should be greater than 0. */
#define NIRFSA_ERROR_INVALID_CAL_NUM_OF_MEASUREMENTS -1074118397

/* hex:0xBFFA4102 */
/* The calibration number of attenuators specified is not supported by this instrument driver. The number of attenuators should be 2. */
#define NIRFSA_ERROR_INVALID_CAL_NUM_OF_ATTENUATORS -1074118398

/* hex:0xBFFA4101 */
/* The calibration number of frequencies specified is not supported by this instrument driver. The number of frequencies should be greater than 0. */
#define NIRFSA_ERROR_INVALID_CAL_NUM_OF_FREQUENCIES -1074118399

/* hex:0xBFFA4100 */
/* The calibration reference level calibration data type specified is not supported by this instrument driver. The valid values are default or mechanical attenuator disabled. */
#define NIRFSA_ERROR_INVALID_CAL_REF_LEVEL_CAL_DATA_TYPE -1074118400

/* hex:0xBFFA40FF */
/* The calibration attenuator table number parameter specified is not supported by this instrument driver. The valid values for attenuator table numbers are 0 to 2. */
#define NIRFSA_ERROR_INVALID_CAL_ATTENUATOR_TABLE_NUMBER -1074118401

/* hex:0xBFFA40FE */
/* The calibration bandwidth parameter specified is not supported by this instrument driver. The bandwidth specified should be greater than 0. */
#define NIRFSA_ERROR_INVALID_CAL_BANDWIDTH -1074118402

/* hex:0xBFFA40FD */
/* The calibration IF filter parameter specified is not supported by this instrument driver. The valid values for the IF filter are 187.5 MHz Wide, 187.5 MHz Narrow, 53 MHz, and Bypass. */
#define NIRFSA_ERROR_INVALID_CAL_IF_FILTER -1074118403

/* hex:0xBFFA40FC */
/* The calibration RF band specified is not supported by this instrument driver. The valid values for the RF band are RF bands 1 to 4 inclusive. */
#define NIRFSA_ERROR_INVALID_CAL_RF_BAND -1074118404

/* hex:0xBFFA40FB */
/* The calibration frequency specified is not supported by this instrument driver. */
#define NIRFSA_ERROR_INVALID_CAL_FREQUENCY -1074118405

/* hex:0xBFFA40FA */
/* The calibration function specified is not supported in this calibration step. Call the appropriate calibration function or initialize the appropriate calibration step prior to calling this calibration function. */
#define NIRFSA_ERROR_CAL_FUNCTION_CALLED_IN_INCORRECT_CAL_STEP -1074118406

/* hex:0xBFFA40F9 */
/* The previous calibration step is not closed. Close the previous calibration step before calling this function. */
#define NIRFSA_ERROR_CAL_STEP_NOT_CLOSED -1074118407

/* hex:0xBFFA40F8 */
/* The calibration step specified is not supported without first performing an LO ALC DAC alignment. */
#define NIRFSA_ERROR_CAL_STEP_NOT_VALID_WITHOUT_LO_ALC_DAC_ALIGNMENT -1074118408

/* hex:0xBFFA40F7 */
/* The calibration step specified is not supported by this instrument driver. */
#define NIRFSA_ERROR_INVALID_CALIBRATION_STEP -1074118409

/* hex:0xBFFA40F6 */
/* The calibration action specified is not supported by this instrument driver. The valid values for calibration action are Create and Append. */
#define NIRFSA_ERROR_INVALID_CAL_ACTION -1074118410

/* hex:0xBFFA40F5 */
/* The requested device configuration requires you to directly specify an additional property. */
#define NIRFSA_ERROR_REQUIRED_ATTRIBUTE_NOT_SPECIFIED -1074118411

/* hex:0xBFFA40F4 */
/* Cannot compute downconverter gain because no calibration data exists for this device configuration. */
#define NIRFSA_ERROR_CANNOT_FETCH_DC_GAIN_FOR_NON_CALIBRATED_DATA -1074118412

/* hex:0xBFFA40F3 */
/* Multispan spectrum acquisition is not supported while in-band retuning is enabled. Reduce the spectrum span for the acquisition or do not set the Downconverter Center Frequency property or the NIRFSA_ATTR_DOWNCONVERTER_CENTER_FREQUENCY attribute. Consult the device documentation for information about supported RF bands and their corresponding real-time bandwidths. */
#define NIRFSA_ERROR_MULTISPAN_NOT_SUPPORTED_WITH_INBAND_RETUNING -1074118413

/* hex:0xBFFA40F2 */
/* The spectrum frequencies specified span two or more frequency bands which have different real-time bandwidths. Reduce the spectrum span or break up the spectrum acquisition into multiple segments. Consult the device documentation for information on its RF bands and their corresponding real-time bandwidths. */
#define NIRFSA_ERROR_SPECTRUM_SPANS_BANDS_OF_DIFFERENT_BANDWIDTH -1074118414

/* hex:0xBFFA40F1 */
/* The IQ Rate specified is larger than the maximum supported IQ Rate for the current settings. Consider lowering your IQ Rate or disabling fractional resampling. */
#define NIRFSA_ERROR_IQ_RATE_TOO_HIGH_FOR_FRACTIONAL_RESAMPLING_MODE -1074118415

/* hex:0xBFFA40F0 */
/* You cannot configure the LO Frequency attribute when NI-RFSA is controlling the LO device. You can only use this attribute to read the coerced LO frequency in this session. */
#define NIRFSA_ERROR_CANNOT_SET_LO_FREQUENCY_WITH_INTERNAL_LO -1074118416

/* hex:0xBFFA40EF */
/* The DriverSetup tags are specified with conflicting settings. Refer to the user documentation for information about the DriverSetup syntax. */
#define NIRFSA_ERROR_CONFLICTING_DRIVER_SETUP_TAGS_SPECIFIED -1074118417

/* hex:0xBFFA40EE */
/* The spectrum span specified is larger than the bandwidth of the device at the given frequency. This is not supported when the LO is external to the RFSA session. */
#define NIRFSA_ERROR_MULTISPAN_NOT_SUPPORTED_WITH_EXTERNAL_LO -1074118418

/* hex:0xBFFA40ED */
/* Only the high downconverter loop bandwidth is configurable for spans greater than 10 MHz. */
#define NIRFSA_ERROR_SPAN_AND_LOOP_BANDWIDTH -1074118419

/* hex:0xBFFA40EC */
/* This function is only supported when using NI-RFSA in external digitizer mode. Specify the digitizer resource name as <external> in MAX or in the Option String. */
#define NIRFSA_ERROR_FUNCTION_NOT_SUPPORTED_IN_DOWNCONVERTER_DIGITIZER_MODE -1074118420

/* hex:0xBFFA40EB */
/* This attribute is only supported when using NI-RFSA in external digitizer mode. Specify the digitizer resource name as <external> in MAX or in the Option String. */
#define NIRFSA_ERROR_ATTR_NOT_SUPPORTED_IN_DOWNCONVERTER_DIGITIZER_MODE -1074118421

/* hex:0xBFFA40E6 */
/* Fetch position and fetch offset cannot be configured in a spectrum acquisition. Reset the attributes in order to read the spectrum. */
#define NIRFSA_ERROR_FETCH_POSITION_AND_OFFSET_IN_SPECTRUM_ACQUISITION -1074118426

/* hex:0xBFFA40E5 */
/* You have configured multiple records to be acquired in a continuous acquisition. You can only configure multiple records when the number of samples is finite parameter is set to TRUE. */
#define NIRFSA_ERROR_MULTIPLE_RECORDS_IN_CONT_ACQ -1074118427

/* hex:0xBFFA40E4 */
/* Driver has stopped operating because a sensor on the device detected a temperature in excess of the maximum recommended operating temperature. Possible causes incude excessive current on the device channels and inadequate chassis cooling.To use the device again, reduce the current and/or improve the chassis cooling. Ensure that the device has cooled before operating it. */
#define NIRFSA_ERROR_TEMPERATURE_EXCEEDS_OPERATING_LIMIT -1074118428

/* hex:0xBFFA40E3 */
/* You cannot call Read IQ when you are acquiring more than one record. Use Initiate and Fetch IQ instead. */
#define NIRFSA_ERROR_READ_IN_MULTIRECORD_ACQUISITION -1074118429

/* hex:0xBFFA40E2 */
/* You cannot call Read IQ when the number of samples is not finite. Use Initiate and Fetch IQ instead. */
#define NIRFSA_ERROR_READ_IN_CONTINUOUS_ACQUISITION -1074118430

/* hex:0xBFFA40E1 */
/* The frequency range specified by the combination of center frequency and span values contains data outside the frequency range allowed for this device. */
#define NIRFSA_ERROR_FREQUENCY_CONTENT_OUTSIDE_SPECIFICATION -1074118431

/* hex:0xBFFA40E0 */
/* The number of records to fetch cannot be set to -1 (default) when the number of records to acquire is not a finite quantity. */
#define NIRFSA_ERROR_CANNOT_FETCH_NEG_ONE_RECORDS_IN_CONT_ACQ -1074118432

/* hex:0xBFFA40DF */
/* The number of samples to fetch cannot be set to -1 (default) when the number of samples to acquire is not a finite quantity. */
#define NIRFSA_ERROR_CANNOT_FETCH_NEG_ONE_SAMPLES_IN_CONT_ACQ -1074118433

/* hex:0xBFFA40DE */
/* Firmware is corrupted or is not working correctly. Reboot your system. Contact NI Technical Support if you need additional information or the problem persists. */
#define NIRFSA_ERROR_FIRMWARE -1074118434

/* hex:0xBFFA40DD */
/* The specified value is not a recognized Boolean value. Refer to the user documentation for information about the DriverSetup syntax. */
#define NIRFSA_ERROR_INVALID_BOOLEAN_IN_DRIVER_SETUP -1074118435

/* hex:0xBFFA40DC */
/* Trigger source must be specified for the given trigger type. */
#define NIRFSA_ERROR_TRIGGER_SOURCE_NOT_SPECIFIED -1074118436

/* hex:0xBFFA40DB */
/* This attribute is not supported in a spectrum acquisition. */
#define NIRFSA_ERROR_ATTR_NOT_SUPPORTED_IN_SPECTRUM_ACQUISITION -1074118437

/* hex:0xBFFA40DA */
/* The temperature sensor on the device returned a bad reading. The sensor may be failing and need replacement. Contact NI Technical Support if you need additional information or the problem persists. */
#define NIRFSA_ERROR_BAD_TEMPERATURE_READING -1074118438

/* hex:0xBFFA40D9 */
/* The Sample clock timebase rate is unspecified. You must specify a Sample clock timebase rate when a spectrum acquisition is configured and a Sample clock timebase source is configured. */
#define NIRFSA_ERROR_SPECIFY_SOURCE_AND_RATE_IN_SPECTRUM_ACQUISITION -1074118439

/* hex:0xBFFA40D8 */
/* Exporting this event is not supported when the acquisition type is set to Spectrum. */
#define NIRFSA_ERROR_EVENT_NOT_SUPPORTED_IN_SPECTRUM_ACQUISITION -1074118440

/* hex:0xBFFA40D7 */
/* This trigger type is not supported when the acquisition type is set to Spectrum. */
#define NIRFSA_ERROR_TRIG_NOT_SUPPORTED_IN_SPECTRUM_ACQUISITION -1074118441

/* hex:0xBFFA40D6 */
/* You cannot configure the Arm Reference trigger without configuring the device to use the Reference trigger. */
#define NIRFSA_ERROR_ARM_REF_TRIGGER_NOT_ALLOWED_WITHOUT_REF_TRIGGER -1074118442

/* hex:0xBFFA40D5 */
/* The value of reference level minus the value of attenuation must be smaller or equal to 0. */
#define NIRFSA_ERROR_ATTENUATION_TOO_SMALL_FOR_REF_LEVEL -1074118443

/* hex:0xBFFA40D4 */
/* You have attempted to configure a Reference trigger for an acquisition containing an unbounded number of samples. You can only use the Reference trigger if the number of samples per record is finite. */
#define NIRFSA_ERROR_REF_TRIG_IN_CONTINUOUS_ACQUISITION -1074118444

/* hex:0xBFFA40D3 */
/* You have attempted to configure an unbounded number of samples and an unbounded number of records in the same acquisition. At least one of the two quantities must be configured as finite. */
#define NIRFSA_ERROR_BOTH_SAMPLES_AND_RECORDS_ARE_UNBOUNDED -1074118445

/* hex:0xBFFA40D1 */
/* The value of mixer level must be no more than 50 dBm smaller than the value of reference level. */
#define NIRFSA_ERROR_MIXER_LEVEL_TOO_SMALL_FOR_REF_LEVEL -1074118447

/* hex:0xBFFA40D0 */
/* Mixer level must be less than or equal to reference level. */
#define NIRFSA_ERROR_MIXER_LEVEL_GREATER_THAN_REF_LEVEL -1074118448

/* hex:0xBFFA40CF */
/* Driver was unloaded and then reloaded at a different base address after the session was created. Session is unusable. Close and reopen the session. */
#define NIRFSA_ERROR_SESSION_CORRUPTED_BY_DLL_RELOAD -1074118449

/* hex:0xBFFA40CE */
/* You must specify exactly one channel or repeated capability from which to retrieve an attribute. */
#define NIRFSA_ERROR_ONLY_ONE_IDENTIFIER_ALLOWED -1074118450

/* hex:0xBFFA40CD */
/* No value was found for the tag. Valid DriverSetup strings have the form "tag:value; tag:value; ... tag:value". Refer to the user documentation for information about the DriverSetup syntax. */
#define NIRFSA_ERROR_VALUE_NOT_SPECIFIED_FOR_DRIVER_SETUP_TAG -1074118451

/* hex:0xBFFA40CC */
/* The tag is specified more than once. Refer to the user documentation for information about the DriverSetup syntax. */
#define NIRFSA_ERROR_DRIVER_SETUP_TAG_SPECIFIED_MORE_THAN_ONCE -1074118452

/* hex:0xBFFA40CB */
/* The specified tag is not supported. Refer to the user documentation for information about the DriverSetup syntax. */
#define NIRFSA_ERROR_UNSUPPORTED_DRIVER_SETUP_TAG -1074118453

/* hex:0xBFFA40CA */
/* You must specify the reference level, attenuation, and mixer level attributes such that attenuation = reference level - mixer level. If you do not set either mixer level or attenuation, the driver selects the appropriate value for the attribute. */
#define NIRFSA_ERROR_ATTENUATION_RELATIONSHIP_INVALID -1074118454

/* hex:0xBFFA40C9 */
/* Specified PXI Chassis CLK10 Source is invalid given the Reference clock source.  When PXI Chassis CLK10 Source is anything other than None the Reference clock source must be the same as the PXI Chassis CLK10 Source. */
#define NIRFSA_ERROR_INVALID_PXI_CLK10_SRC_GIVEN_REF_CLK_SRC -1074118455

/* hex:0xBFFA40C8 */
/* The IVI engine was unable to create the session. Repair or reinstall the NI-RFSA instrument driver. Contact NI Technical Support if you need additional information or the problem persists. */
#define NIRFSA_ERROR_SESSION_FAILED_TO_INITIALIZE -1074118456

/* hex:0xBFFA401E */
/* The configured trigger level value is too high. The maximum value for the trigger level is determined by the configured reference level. */
#define NIRFSA_ERROR_TRIGGER_LEVEL_HIGHER_THAN_REF_LEVEL -1074118626

/* hex:0xBFFA401D */
/* Additional calibration information is necessary to enable this feature. */
#define NIRFSA_ERROR_ADDITIONAL_CALIBRATION_NEEDED_FOR_THIS_FEATURE -1074118627

/* hex:0xBFFA401C */
/* This function is not supported when using NI-RFSA with an external LO module. */
#define NIRFSA_ERROR_FUNCTION_NOT_SUPPORTED_IN_EXTERNAL_LO_MODE -1074118628

/* hex:0xBFFA401B */
/* This attribute is not supported when using NI-RFSA with the external LO module. */
#define NIRFSA_ERROR_ATTR_NOT_SUPPORTED_IN_EXTERNAL_LO_MODE -1074118629

/* hex:0xBFFA401A */
/* The LO returned the following error: */
#define NIRFSA_ERROR_NIRFSG_ERROR -1074118630

/* hex:0xBFFA4019 */
/* LO resource name is invalid. The resource name can be invalid because you either associated an invalid LO resource name in MAX with the downconverter or because you tried to use niRFSA Init With Options with a DriverSetup string that included an invalid LO resource name. */
#define NIRFSA_ERROR_INVALID_LO_RESOURCE_NAME -1074118631

/* hex:0xBFFA4018 */
/* Session could not be opened because the LO resource name was not specified. Specify the LO resource name in MAX or in the Option String. */
#define NIRFSA_ERROR_LO_RESOURCE_NAME_NOT_FOUND -1074118632

/* hex:0xBFFA4017 */
/* The currently installed version of NI-RFSA is not compatible with the currently installed version of NI-SCOPE. Upgrade your NI-RFSA installation, or downgrade your NI-SCOPE installation. */
#define NIRFSA_ERROR_INCOMPATIBLE_NISCOPE_DRIVER_VERSION -1074118633

/* hex:0xBFFA4016 */
/* The attenuator relays are not settled. Repair or reinstall the NI-RFSA instrument driver. Contact NI Technical Support if you need additional information or the problem persists. */
#define NIRFSA_ERROR_ATTENUATORS_NOT_SETTLED -1074118634

/* hex:0xBFFA4015 */
/* The frequency tuning PLL is not locked. */
#define NIRFSA_ERROR_FREQUENCY_TUNING_PLL_NOT_LOCKED -1074118635

/* hex:0xBFFA4014 */
/* The Reference clock PLL is not locked. */
#define NIRFSA_ERROR_REF_CLK_PLL_NOT_LOCKED -1074118636

/* hex:0xBFFA4013 */
/* This attribute is not supported when using NI-RFSA with an external digitizer module. */
#define NIRFSA_ERROR_ATTR_NOT_SUPPORTED_IN_DOWNCONVERTER_ONLY_MODE -1074118637

/* hex:0xBFFA4012 */
/* This function is not supported when using NI-RFSA with an external digitizer module. */
#define NIRFSA_ERROR_FUNCTION_NOT_SUPPORTED_IN_EXTERNAL_DIGITIZER_MODE -1074118638

/* hex:0xBFFA4011 */
/* This function is not supported when the acquisition type is set to IQ. */
#define NIRFSA_ERROR_FUNCTION_NOT_SUPPORTED_IN_IQ_ACQUISITION -1074118639

/* hex:0xBFFA4010 */
/* This function is not supported when the acquisition type is set to Spectrum. */
#define NIRFSA_ERROR_FUNCTION_NOT_SUPPORTED_IN_SPECTRUM_ACQUISITION -1074118640

/* hex:0xBFFA400F */
/* You can only get the specified property while the session is committed or while the session is running.Commit or initiate the session prior to getting the property. */
#define NIRFSA_ERROR_GET_WHEN_SESSION_NOT_RUNNING -1074118641

/* hex:0xBFFA400E */
/* Unable to initialize because a session for the specified device is already open from another process. Close the open session by calling niRFSA Close or by exiting the application with the open session.  If you are using NI-RFSA SFP, refer to "Debugging your Application Using SFP Session Access" in the documentation on how to share the device in this process and NI-RFSA SFP. */
#define NIRFSA_ERROR_INSTRUMENT_ALREADY_IN_USE -1074118642

/* hex:0xBFFA400D */
/* Device not available in NI-RFSA. The device may be being used by NI-Tuner or NI-5660, or the device is being reset. After using a device in NI-Tuner, you must reset the device using the Traditional DAQ Device Reset before using it in NI-RFSA. */
#define NIRFSA_ERROR_DEVICE_ABSENT_OR_UNAVAILABLE -1074118643

/* hex:0xBFFA400C */
/* The device's calibration revision is unsupported by this version of the driver. Upgrade the driver. Contact NI Technical Support if you need additional information or the problem persists. */
#define NIRFSA_ERROR_UNSUPPORTED_CALIBRATION_REVISION -1074118644

/* hex:0xBFFA400B */
/* The specified operation cannot be performed because a session has been aborted or a device has been removed from the system. */
#define NIRFSA_ERROR_RUNTIME_ABORTED -1074118645

/* hex:0xBFFA400A */
/* Specified property cannot be set while the session is running.Set the property prior to initiating the session, or abort the session prior to setting the property. */
#define NIRFSA_ERROR_SET_WHEN_SESSION_RUNNING -1074118646

/* hex:0xBFFA4009 */
/* Specified operation is only supported while the session is running.Initiate the session before requesting the operation and ensure that the session has not been aborted. */
#define NIRFSA_ERROR_SESSION_NOT_IN_RUNNING_STATE -1074118647

/* hex:0xBFFA4008 */
/* You cannot perform this action while the session is running. */
#define NIRFSA_ERROR_SESSION_IN_RUNNING_STATE -1074118648

/* hex:0xBFFA4007 */
/* Session could not be opened because the digitizer resource name was not specified. Click on the system device in MAX and select the appropriate digitizer resource name in the Associated Devices. */
#define NIRFSA_ERROR_DIGITIZER_RESOURCE_NAME_NOT_FOUND_IN_INIT -1074118649

/* hex:0xBFFA4006 */
/* Session could not be opened because the digitizer resource name was not specified. Click on the system device in MAX and select the appropriate digitizer resource name in the Associated Devices. If you are specifying the digitizer via the Option String, ensure the digitizer Resource Name is valid. */
#define NIRFSA_ERROR_DIGITIZER_RESOURCE_NAME_NOT_FOUND -1074118650

/* hex:0xBFFA4005 */
/* Digitizer resource name is invalid. The resource name can be invalid because you either associated an invalid digitizer resource name in MAX with the downconverter or because you tried to use niRFSA Init With Options with a DriverSetup string that included an invalid digitizer resource name. */
#define NIRFSA_ERROR_INVALID_DIGITIZER_RESOURCE_NAME -1074118651

/* hex:0xBFFA4004 */
/* The specified digitizer is not supported by NI-RFSA. */
#define NIRFSA_ERROR_DIGITIZER_NOT_SUPPORTED -1074118652

/* hex:0xBFFA4003 */
/* The device specified is not supported by this driver. */
#define NIRFSA_ERROR_DEVICE_NOT_SUPPORTED -1074118653

/* hex:0xBFFA4002 */
/* Maximum time exceeded before the operation completed. */
#define NIRFSA_ERROR_MAX_TIME_EXCEEDED -1074118654

/* hex:0xBFFA4001 */
/* The digitizer returned the following error: */
#define NIRFSA_ERROR_NISCOPE_ERROR -1074118655

/* hex:0xBFFA4000 */
/* The IF Digitizer Host DLL Returned the following Error: */
#define NIRFSA_ERROR_IFDIG_LVDLL_ERROR -1074118656

/*********************************/
/*********** Warnings ************/
/*********************************/

/* hex:0x3FFA4001 */
/* The digitizer returned the following warning: */
#define NIRFSA_WARN_NISCOPE_WARN 1073364993

/* hex:0x3FFA4002 */
/* The reference clock PLL is not locked. */
#define NIRFSA_WARN_REF_CLK_PLL_NOT_LOCKED 1073364994

/* hex:0x3FFA4003 */
/* The LO returned the following warning: */
#define NIRFSA_WARN_NIRFSG_WARN 1073364995

/* hex:0x3FFA4004 */
/* The digitizer returned the following PLL warning: */
#define NIRFSA_WARN_NISCOPE_PLL_WARN 1073364996

/* hex:0x3FFA4005 */
/* The current channel coupling configuration is not calibrated, accuracy levels are not guaranteed */
#define NIRFSA_WARN_DCBLOCK_NOT_CALIBRATED 1073364997

/* hex:0x3FFA4006 */
/* The Speficied IF state is not present in the calibration data, try a different IF filter path, IF Attenuation table type, or IF Index. */
#define NIRFSA_WARN_IF_INDEX_NOT_CALIBRATED 1073364998

/* hex:0x3FFA4007 */
/* The specified Attenuation constraints are not calibrated, Reference level accuracy not guaranteed. */
#define NIRFSA_WARN_ATTENUATION_CONSTRAINT_NOT_CALIBRATED 1073364999

/* hex:0x3FFA4008 */
/* Calibration data not present or invalid, Reference level accuracy not guaranteed */
#define NIRFSA_WARN_CALIBRATION_DATA_NOT_PRESENT 1073365000

/* hex:0x3FFA4009 */
/* The current RF configuration is not calibrated. Try changing the Channel Coupling attribute, Preamp Enabled attribute, or RF attenuation configuration with either Mixer Level or RF Attenuation Attributes */
#define NIRFSA_WARN_RF_CONFIGURATION_NOT_CALIBRATED 1073365001

/* hex:0x3FFA400A */
/* Unable to correct for temperature deviation, reference level accuracy not guaranteed, re-commit settings inorder to regain accuracy. */
#define NIRFSA_WARN_TEMPERATURE_DEVIATION_LIMIT_EXCEEDED 1073365002

/* hex:0x3FFA400B */
/* External Calibration IF Equalization Self Calibration IF Equalization Data is not present. Contact NI for further assistance. */
#define NIRFSA_WARN_EXTERNAL_CAL_IF_EQUALIZATION_DATA_NOT_PRESENT 1073365003

/* hex:0x3FFA400C */
/* The RF Conditioning device returned the following warning: */
#define NIRFSA_WARN_RF_CONDITIONING_WARN 1073365004

/* hex:0x3FFA400D */
/* The IF Conditioning device returned the following warning: */
#define NIRFSA_WARN_IF_CONDITIONING_WARN 1073365005

/* hex:0x3FFA400E */
/* The self calibration offset measured by NI-RFSA was out of bounds. Ensure that all the modules in the system are externally calibrated before running self calibration. */
#define NIRFSA_WARN_SELF_CAL_OFFSET_OUT_OF_BOUNDS 1073365006

/* hex:0x3FFA400F */
/* The cache is not sufficient to store the acquired waveform within the driver. The driver will truncate the waveform and store the truncated data in the cache. */
#define NIRFSA_WARN_WAVEFORM_SIZE_EXCEEDS_MAX_CACHE_SIZE_LIMIT 1073365007

/* hex:0x3FFA4010 */
/* Hardware external calibration data format is older than the earliest revision supported by the currently installed driver.<LF/>Perform an external calibration (this will modify the calibration data).  For more information, contact NI technical support. */
#define NIRFSA_WARN_EXT_CALIBRATION_DATA_TOO_OLD_FOR_SOFTWARE 1073365008

/* hex:0x3FFA40C8 */
/* The frequency range for the spectrum contains data outside the frequency range from the device specifications. Data in this frequency range may be inaccurate. */
#define NIRFSA_WARN_FREQUENCY_CONTENT_OUTSIDE_SPECIFICATION 1073365192

/* hex:0x3FFA40C9 */
/* The device is operating at a frequency outside the frequency range from the device specifications. Data in this frequency range may be inaccurate. */
#define NIRFSA_WARN_CENTER_FREQUENCY_OUTSIDE_SPECIFICATION 1073365193

/* hex:0x3FFA40CA */
/* Hardware external calibration data format is newer than the latest revision supported by the currently installed driver.  Either externally calibrate your device (this may modify the calibration data) or upgrade your driver to the version supplied with the device. Driver updates can also be downloaded from ni.com. If uncertain, contact NI technical support. */
#define NIRFSA_WARN_EXT_CALIBRATION_DATA_TOO_NEW_FOR_SOFTWARE 1073365194

/* hex:0x3FFA40CB */
/* External calibration constants are invalid. Perform an external calibration. Contact NI Technical Support if you need additional information. */
#define NIRFSA_WARN_EXT_CALIBRATION_CONSTS_INVALID 1073365195

/* hex:0x3FFA40CC */
/* A DSP overflow was detected. Reduce the input power level or configure the reference level to a higher value to eliminate overflow. */
#define NIRFSA_WARN_DSP_OVERFLOW 1073365196

/* hex:0x3FFA40CD */
/* One or more peer-to-peer endpoints has overflowed. */
#define NIRFSA_WARN_P2P_OVERFLOW 1073365197


#endif /* ___niRFSA_niRFSAErrors_h___ */
