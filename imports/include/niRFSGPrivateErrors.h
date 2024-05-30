#ifndef ___niRFSG_niRFSGPrivateErrors_h___
#define ___niRFSG_niRFSGPrivateErrors_h___

/*******************************/
/*********** Errors ************/
/*******************************/

/* hex:0xBFFA4241 */
/* An internal hardware error has occurred.  A PLL lock error occurred.If the Frequency Settling Units property is set to Time After I/O, ensure that the Frequency Settling property is set to a value sufficient for this frequency change.Make sure the device has fully warmed up.  If self calibration is supported, self calibrate the device and attempt the operation again.  If the problem persists, contact National Instruments technical support at ni.com/support. */
#define NIRFSG_ERROR_INTERNAL_PLL_LOCK -1074118079

/* hex:0xBFFA4240 */
/* The calibration data is outside the DAC range.  No data was written to the EEPROM. */
#define NIRFSG_ERROR_CAL_DATA_OUTSIDE_DAC_RANGE -1074118080

/* hex:0xBFFA423F */
/* Harmonic peak lacks sufficient ampliturde or signal is not present. */
#define NIRFSG_ERROR_CAL_HARMONIC_NOT_MEASURABLE -1074118081

/* hex:0xBFFA423E */
/* Fundamental peak lacks sufficient amplitude or no signal is present. */
#define NIRFSG_ERROR_CAL_FUNDAMENTAL_NOT_MEASURABLE -1074118082

/* hex:0xBFFA423D */
/* The board read a bad temperature.  Please contact National Instruments Support. */
#define NIRFSG_ERROR_BAD_TEMPERATURE_READING -1074118083

/* hex:0xBFFA423C */
/* The option string has too many characters. */
#define NIRFSG_ERROR_OPTION_STRING_TOO_LONG -1074118084

/* hex:0xBFFA423A */
/* Simulation is not supported. */
#define NIRFSG_ERROR_SIMULATION_NOT_SUPPORTED -1074118086

/* hex:0xBFFA4239 */
/* The LO reported the following error: */
#define NIRFSG_ERROR_LO_ERROR -1074118087

/* hex:0xBFFA4238 */
/* Internal error (kNITNRErrorInternalEEPROMCommunicationFailure). Contact National Instruments technical support at ni.com/support. */
#define NIRFSG_ERROR_TNR_INTERNAL_EEPROM_COMMUNICATION_FAILURE -1074118088

/* hex:0xBFFA4237 */
/* Internal error (kNITNRErrorInternalMainPLLCommunicationFailure). Contact National Instruments technical support at ni.com/support. */
#define NIRFSG_ERROR_TNR_INTERNAL_MAIN_PLL_COMMUNICATION_FAILURE -1074118089

/* hex:0xBFFA4236 */
/* Internal error (kNITNRErrorInternalDDSCommunicationFailure). Contact National Instruments technical support at ni.com/support. */
#define NIRFSG_ERROR_TNR_INTERNAL_DDS_COMMUNICATION_FAILURE -1074118090

/* hex:0xBFFA4235 */
/* Internal error (kNITNRErrorInternalHardwareError). Contact National Instruments technical support at ni.com/support. */
#define NIRFSG_ERROR_TNR_INTERNAL_HARDWARE_ERROR -1074118091

/* hex:0xBFFA4234 */
/* Internal error (kNITNRErrorInternalCalibrationError). Contact National Instruments technical support at ni.com/support. */
#define NIRFSG_ERROR_TNR_INTERNAL_CALIBRATION_ERROR -1074118092

/* hex:0xBFFA4233 */
/* Internal error (kNITNRErrorInvalidCalibrationParam). Contact National Instruments technical support at ni.com/support. */
#define NIRFSG_ERROR_TNR_INVALID_CALIBRATION_PARAM -1074118093

/* hex:0xBFFA4232 */
/* Internal error (kNITNRErrorInvalidControlCode). Contact National Instruments technical support at ni.com/support. */
#define NIRFSG_ERROR_TNR_INVALID_CONTROL_CODE -1074118094

/* hex:0xBFFA4231 */
/* Internal error (kNITNRErrorInternalSoftwareError). Contact National Instruments technical support at ni.com/support. */
#define NIRFSG_ERROR_TNR_INTERNAL_SOFTWARE_ERROR -1074118095

/* hex:0xBFFA422A */
/* The type of modulation cannot be performed with the loop bandwidth setting requested. */
#define NIRFSG_ERROR_MODULATION_AND_LOOP_BANDWIDTH_INCOMPATIBLE -1074118102

/* hex:0xBFFA4229 */
/* A non-zero phase offset is not supported with modulation enabled. */
#define NIRFSG_ERROR_NONZERO_PHASE_OFFSET_WITH_MODULATION -1074118103

/* hex:0xBFFA4228 */
/* The detected hardware version is unsupported by this version of NI-RFSG.  Please upgrade to the latest NI-RFSG driver version. */
#define NIRFSG_ERROR_HARDWARE_TOO_NEW_FOR_DRIVER -1074118104

/* hex:0xBFFA4227 */
/* Timed out waiting for device power level to settle. */
#define NIRFSG_ERROR_565X_POWER_LEVEL_NOT_SETTLED -1074118105

/* hex:0xBFFA4226 */
/* Timed out waiting for device frequency to settle. */
#define NIRFSG_ERROR_565X_FREQUENCY_NOT_SETTLED -1074118106

/* hex:0xBFFA4225 */
/* Invalid PRBS seed for this PRBS order. At least one of the least-significant n bits of the seed must be non-zero, where 'n' is the PRBS order. */
#define NIRFSG_ERROR_PRBS_SEED_INVALID_FOR_PRBS_ORDER -1074118107

/* hex:0xBFFA4224 */
/* Power level is too low to be used with OOK modulation enabled. Increase the power level or disable OOK modulation. */
#define NIRFSG_ERROR_POWER_LEVEL_TOO_LOW_FOR_OOK -1074118108

/* hex:0xBFFA4210 */
/* The waveform input cluster contains no values. */
#define NIRFSG_ERROR_INTERNAL_FRACTIONAL_RESAMPLING_21837 -1074118128

/* hex:0xBFFA420F */
/* The values of the dt element of the waveform cluster must be greater than 0. */
#define NIRFSG_ERROR_INTERNAL_FRACTIONAL_RESAMPLING_21836 -1074118129

/* hex:0xBFFA420E */
/* The ratio of the old and new sample rates must be in the range of 1E-4 to 1E+4. */
#define NIRFSG_ERROR_INTERNAL_FRACTIONAL_RESAMPLING_21863 -1074118130

/* hex:0xBFFA420D */
/* Resampling error: internal error. */
#define NIRFSG_ERROR_INTERNAL_FRACTIONAL_RESAMPLING_21852 -1074118131

/* hex:0xBFFA420C */
/* Sample phase offset must be greater or equal to 0. */
#define NIRFSG_ERROR_INTERNAL_FRACTIONAL_RESAMPLING_21851 -1074118132

/* hex:0xBFFA420B */
/* Sample rates must be greater than 0. */
#define NIRFSG_ERROR_INTERNAL_FRACTIONAL_RESAMPLING_21850 -1074118133

/* hex:0xBFFA420A */
/* Internal Driver Error: Function has not been implemented yet. */
#define NIRFSG_ERROR_FUNCTION_NOT_IMPLEMENTED_YET -1074118134

/* hex:0xBFFA4209 */
/* The upconverter reported the following error: */
#define NIRFSG_ERROR_UNMAPPED_5610_ERROR -1074118135

/* hex:0xBFFA4208 */
/* The AWG reported the following error: */
#define NIRFSG_ERROR_UNMAPPED_FGEN_ERROR -1074118136

/* hex:0xBFFA4207 */
/* An internal software error has occurred. Contact National Instruments technical support at ni.com/support. */
#define NIRFSG_ERROR_INTERNAL_FGEN -1074118137

/* hex:0xBFFA4205 */
/* An internal software error has occurred. Contact National Instruments technical support at ni.com/support. */
#define NIRFSG_ERROR_INTERNAL_INVALID_NUMBER_OF_CYCLES -1074118139

/* hex:0xBFFA4204 */
/* An internal software error has occurred. Contact National Instruments technical support at ni.com/support. */
#define NIRFSG_ERROR_INTERNAL_PARSING_OPTIONS_STRING -1074118140

/* hex:0xBFFA4203 */
/* An internal software error has occurred. Contact National Instruments technical support at ni.com/support. */
#define NIRFSG_ERROR_INTERNAL_VALUE_OUT_OF_RANGE -1074118141

/* hex:0xBFFA4202 */
/* An internal software error has occurred. Contact National Instruments technical support at ni.com/support. */
#define NIRFSG_ERROR_INTERNAL_WAVEFORM_NOT_FOUND -1074118142

/* hex:0xBFFA4201 */
/* An internal software error has occurred. Contact National Instruments technical support at ni.com/support. */
#define NIRFSG_ERROR_INTERNAL_INVALID_PARAMETER -1074118143

/* hex:0xBFFA4200 */
/* An internal error has occurred. Contact National Instruments technical support at ni.com/support. */
#define NIRFSG_ERROR_INTERNAL_ERROR -1074118144

/*********************************/
/*********** Warnings ************/
/*********************************/

/* hex:0x3FFA4200 */
/* An internal warning was generated. Contact National Instruments technical support at ni.com/support. */
#define NIRFSG_WARN_INTERNAL_WARNING 1073365504

/* hex:0x3FFA4201 */
/* The AWG reported the following warning: */
#define NIRFSG_WARN_UNMAPPED_FGEN_WARNING 1073365505

/* hex:0x3FFA4202 */
/* The upconverter reported the following warning: */
#define NIRFSG_WARN_UNMAPPED_5610_WARNING 1073365506

/* hex:0x3FFA4203 */
/* FIR Calibration constants are invalid. Perform an external calibration.Contact National Instruments Technical Support if you need additional information. */
#define NIRFSG_WARN_INTERNAL_FAKE_IF_CALIBRATION 1073365507

/* hex:0x3FFA4204 */
/* An internal device setting is out of range.  This could be due to calibration problems or compensation for extreme temperatures.  The device setting was coerced to the maximum or minimum supported value.  Device performance is not guaranteed. */
#define NIRFSG_WARN_INTERNAL_SETTING_OUT_OF_RANGE 1073365508

/* hex:0x3FFA4210 */
/* Requested attribute value exceeds device specification limits. Device performance is not guaranteed. */
#define NIRFSG_WARN_DEVICE_SPECIFICATIONS_EXCEEDED 1073365520

/* hex:0x3FFA4211 */
/* While averaging temperature sensor readings, found more variation in the readings than expected.  Temperature reading may not be accurate. */
#define NIRFSG_WARN_INCONSISTENT_TEMPERATURE_READING 1073365521

/* hex:0x3FFA4212 */
/* The LO reported the following warning: */
#define NIRFSG_WARN_LO_WARNING 1073365522

#endif /* ___niRFSG_niRFSGPrivateErrors_h___ */
