/****************************************************************************
*                         IVIDIGITIZER                              
*---------------------------------------------------------------------------
*    Copyright (c) 2009-2020 National Instruments.  All Rights Reserved.        
*---------------------------------------------------------------------------
*                                                                          
* Title:       IviDigitizer_ni.h                                                    
* Purpose:     IviDigitizer Class declarations for the Base and Extended  
*              IviDigitizer Capabilities.                                        
****************************************************************************/


#ifndef IVIDIGITIZER_HEADER
#define IVIDIGITIZER_HEADER

#include <ivi.h>

#ifdef _CVI_
#pragma EnableLibraryRuntimeChecking
#endif

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif


/****************************************************************************
 *----------------- Instrument Driver Revision Information -----------------*
 ****************************************************************************/

#define IVIDIGITIZER_MAJOR_VERSION              (4L)
#define IVIDIGITIZER_MINOR_VERSION              (1L)

#define IVIDIGITIZER_CLASS_SPEC_MAJOR_VERSION   (2L)
#define IVIDIGITIZER_CLASS_SPEC_MINOR_VERSION   (3L)

#define IVIDIGITIZER_DRIVER_VENDOR              "National Instruments"
#ifdef	_IVI_mswin64_
#define IVIDIGITIZER_DRIVER_DESCRIPTION         "IviDigitizer Class Driver [Compiled for 64-bit.]"
#else
#define IVIDIGITIZER_DRIVER_DESCRIPTION			"IviDigitizer Class Driver"
#endif

/****************************************************************************
 *------------------------------ Useful Macros -----------------------------*
 ****************************************************************************/


/****************************************************************************
 *------------------ IviDigitizer Class Attribute Defines ------------------*
 ****************************************************************************/

/*- IVI Inherent Attributes -*/

	/*- User Options -*/
#define IVIDIGITIZER_ATTR_CACHE										IVI_ATTR_CACHE										/* ViBoolean */
#define IVIDIGITIZER_ATTR_RANGE_CHECK								IVI_ATTR_RANGE_CHECK								/* ViBoolean */
#define IVIDIGITIZER_ATTR_QUERY_INSTRUMENT_STATUS					IVI_ATTR_QUERY_INSTRUMENT_STATUS					/* ViBoolean */
#define IVIDIGITIZER_ATTR_RECORD_COERCIONS							IVI_ATTR_RECORD_COERCIONS							/* ViBoolean */
#define IVIDIGITIZER_ATTR_SIMULATE									IVI_ATTR_SIMULATE									/* ViBoolean */
#define IVIDIGITIZER_ATTR_INTERCHANGE_CHECK							IVI_ATTR_INTERCHANGE_CHECK							/* ViBoolean */
#define IVIDIGITIZER_ATTR_SPY										IVI_ATTR_SPY										/* ViBoolean */
#define IVIDIGITIZER_ATTR_USE_SPECIFIC_SIMULATION					IVI_ATTR_USE_SPECIFIC_SIMULATION					/* ViBoolean */

	/* Instrument Capabilities */
#define IVIDIGITIZER_ATTR_CHANNEL_COUNT								IVI_ATTR_CHANNEL_COUNT								/* ViInt32,  read-only  */

	/*- Instrument Capabilities -*/
#define IVIDIGITIZER_ATTR_GROUP_CAPABILITIES						IVI_ATTR_GROUP_CAPABILITIES							/* ViString, read-only */
#define IVIDIGITIZER_ATTR_FUNCTION_CAPABILITIES						IVI_ATTR_FUNCTION_CAPABILITIES						/* ViString, read-only */

	/*- Class Driver Information -*/    
#define IVIDIGITIZER_ATTR_CLASS_DRIVER_PREFIX						IVI_ATTR_CLASS_DRIVER_PREFIX						/* ViString, read-only */
#define IVIDIGITIZER_ATTR_CLASS_DRIVER_VENDOR						IVI_ATTR_CLASS_DRIVER_VENDOR						/* ViString, read-only */
#define IVIDIGITIZER_ATTR_CLASS_DRIVER_DESCRIPTION					IVI_ATTR_CLASS_DRIVER_DESCRIPTION					/* ViString, read-only */
#define IVIDIGITIZER_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION		IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION		/* ViInt32,  read-only */
#define IVIDIGITIZER_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION		IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION		/* ViInt32,  read-only */

	/*- Specific Driver Information -*/    
#define IVIDIGITIZER_ATTR_SPECIFIC_DRIVER_PREFIX					IVI_ATTR_SPECIFIC_DRIVER_PREFIX						/* ViString, read-only */
#define IVIDIGITIZER_ATTR_SPECIFIC_DRIVER_LOCATOR					IVI_ATTR_SPECIFIC_DRIVER_LOCATOR					/* ViString, read-only */
#define IVIDIGITIZER_ATTR_IO_RESOURCE_DESCRIPTOR					IVI_ATTR_IO_RESOURCE_DESCRIPTOR						/* ViString, read-only */
#define IVIDIGITIZER_ATTR_LOGICAL_NAME								IVI_ATTR_LOGICAL_NAME								/* ViString, read-only */
#define IVIDIGITIZER_ATTR_SPECIFIC_DRIVER_VENDOR					IVI_ATTR_SPECIFIC_DRIVER_VENDOR						/* ViString, read-only */
#define IVIDIGITIZER_ATTR_SPECIFIC_DRIVER_DESCRIPTION				IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION				/* ViString, read-only */
#define IVIDIGITIZER_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION	IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION	/* ViInt32,  read-only */
#define IVIDIGITIZER_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION	IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION	/* ViInt32,  read-only */

	/*- Instrument Information -*/    
#define IVIDIGITIZER_ATTR_INSTRUMENT_FIRMWARE_REVISION				IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION				/* ViString, read-only */
#define IVIDIGITIZER_ATTR_INSTRUMENT_MANUFACTURER					IVI_ATTR_INSTRUMENT_MANUFACTURER					/* ViString, read-only */
#define IVIDIGITIZER_ATTR_INSTRUMENT_MODEL							IVI_ATTR_INSTRUMENT_MODEL							/* ViString, read-only */
#define IVIDIGITIZER_ATTR_SUPPORTED_INSTRUMENT_MODELS				IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS				/* ViString, read-only */

	/*- Version Information -*/
#define IVIDIGITIZER_ATTR_CLASS_DRIVER_REVISION						IVI_ATTR_CLASS_DRIVER_REVISION						/* ViString, read-only */

#define IVIDIGITIZER_ATTR_SPECIFIC_DRIVER_REVISION					IVI_ATTR_SPECIFIC_DRIVER_REVISION					/* ViString, read-only */

	/*- Driver Setup information -*/
#define IVIDIGITIZER_ATTR_DRIVER_SETUP								IVI_ATTR_DRIVER_SETUP								/* ViString */

/*- IviDigitizer Fundamental Attributes -*/
#define IVIDIGITIZER_ATTR_ACTIVE_TRIGGER_SOURCE						(IVI_CLASS_PUBLIC_ATTR_BASE + 1L)		/* ViString */
#define IVIDIGITIZER_ATTR_CHANNEL_ENABLED							(IVI_CLASS_PUBLIC_ATTR_BASE + 2L)		/* ViBoolean */
#define IVIDIGITIZER_ATTR_INPUT_CONNECTOR_SELECTION					(IVI_CLASS_PUBLIC_ATTR_BASE + 3L)		/* ViInt32 */
#define IVIDIGITIZER_ATTR_INPUT_IMPEDANCE							(IVI_CLASS_PUBLIC_ATTR_BASE + 4L)		/* ViReal64 */
#define IVIDIGITIZER_ATTR_IS_IDLE									(IVI_CLASS_PUBLIC_ATTR_BASE + 5L)		/* ViInt32, read-only */
#define IVIDIGITIZER_ATTR_IS_MEASURING								(IVI_CLASS_PUBLIC_ATTR_BASE + 6L)		/* ViInt32, read-only */
#define IVIDIGITIZER_ATTR_IS_WAITING_FOR_ARM						(IVI_CLASS_PUBLIC_ATTR_BASE + 7L)		/* ViInt32, read-only */
#define IVIDIGITIZER_ATTR_IS_WAITING_FOR_TRIGGER					(IVI_CLASS_PUBLIC_ATTR_BASE + 8L)		/* ViInt32, read-only */
#define IVIDIGITIZER_ATTR_MAX_FIRST_VALID_POINT_VAL					(IVI_CLASS_PUBLIC_ATTR_BASE + 9L)		/* ViInt64, read-only */
#define IVIDIGITIZER_ATTR_MAX_SAMPLES_PER_CHANNEL					(IVI_CLASS_PUBLIC_ATTR_BASE + 10L)		/* ViInt64, read-only */
#define IVIDIGITIZER_ATTR_MIN_RECORD_SIZE							(IVI_CLASS_PUBLIC_ATTR_BASE + 11L)		/* ViInt64, read-only */
#define IVIDIGITIZER_ATTR_NUM_ACQUIRED_RECORDS						(IVI_CLASS_PUBLIC_ATTR_BASE + 12L)		/* ViInt64, read-only */
#define IVIDIGITIZER_ATTR_NUM_RECORDS_TO_ACQUIRE					(IVI_CLASS_PUBLIC_ATTR_BASE + 13L)		/* ViInt64 */
#define IVIDIGITIZER_ATTR_RECORD_SIZE								(IVI_CLASS_PUBLIC_ATTR_BASE + 14L)		/* ViInt64 */
#define IVIDIGITIZER_ATTR_SAMPLE_RATE								(IVI_CLASS_PUBLIC_ATTR_BASE + 15L)		/* ViReal64 */
#define IVIDIGITIZER_ATTR_TRIGGER_COUPLING							(IVI_CLASS_PUBLIC_ATTR_BASE + 16L)		/* ViInt32 */
#define IVIDIGITIZER_ATTR_TRIGGER_DELAY								(IVI_CLASS_PUBLIC_ATTR_BASE + 17L)		/* ViReal64 */
#define IVIDIGITIZER_ATTR_TRIGGER_HYSTERESIS						(IVI_CLASS_PUBLIC_ATTR_BASE + 18L)		/* ViReal64 */
#define IVIDIGITIZER_ATTR_TRIGGER_LEVEL								(IVI_CLASS_PUBLIC_ATTR_BASE + 19L)		/* ViReal64 */
#define IVIDIGITIZER_ATTR_TRIGGER_OUTPUT_ENABLED					(IVI_CLASS_PUBLIC_ATTR_BASE + 20L)		/* ViBoolean */
#define IVIDIGITIZER_ATTR_TRIGGER_SLOPE								(IVI_CLASS_PUBLIC_ATTR_BASE + 21L)		/* ViInt32 */
#define IVIDIGITIZER_ATTR_TRIGGER_SOURCE_COUNT						(IVI_CLASS_PUBLIC_ATTR_BASE + 22L)		/* ViInt32, read-only */
#define IVIDIGITIZER_ATTR_TRIGGER_TYPE								(IVI_CLASS_PUBLIC_ATTR_BASE + 23L)		/* ViInt32 */
#define IVIDIGITIZER_ATTR_VERTICAL_COUPLING							(IVI_CLASS_PUBLIC_ATTR_BASE + 24L)		/* ViInt32 */
#define IVIDIGITIZER_ATTR_VERTICAL_OFFSET							(IVI_CLASS_PUBLIC_ATTR_BASE + 25L)		/* ViReal64 */
#define IVIDIGITIZER_ATTR_VERTICAL_RANGE							(IVI_CLASS_PUBLIC_ATTR_BASE + 26L)		/* ViReal64 */

/*- IviDigitizerBoardTemperature Extension Group -*/
#define IVIDIGITIZER_ATTR_BOARD_TEMPERATURE							(IVI_CLASS_PUBLIC_ATTR_BASE + 100L)		/* ViReal64, read-only */
#define IVIDIGITIZER_ATTR_TEMPERATURE_UNITS							(IVI_CLASS_PUBLIC_ATTR_BASE + 101L)		/* ViInt32 */

/*- IviDigitizerChannelFilter Extension Group -*/
#define IVIDIGITIZER_ATTR_INPUT_FILTER_BYPASS						(IVI_CLASS_PUBLIC_ATTR_BASE + 200L)		/* ViBoolean */
#define IVIDIGITIZER_ATTR_INPUT_FILTER_MAX_FREQUENCY				(IVI_CLASS_PUBLIC_ATTR_BASE + 201L)		/* ViReal64 */
#define IVIDIGITIZER_ATTR_INPUT_FILTER_MIN_FREQUENCY				(IVI_CLASS_PUBLIC_ATTR_BASE + 202L)		/* ViReal64 */

/*- IviDigitizerChannelTemperature Extension Group -*/
#define IVIDIGITIZER_ATTR_CHANNEL_TEMPERATURE						(IVI_CLASS_PUBLIC_ATTR_BASE + 300L)		/* ViReal64, read-only */

/*- IviDigitizerTimeInterleavedChannels Extension Group -*/
#define IVIDIGITIZER_ATTR_TIME_INTERLEAVED_CHANNEL_LIST				(IVI_CLASS_PUBLIC_ATTR_BASE + 400L)		/* ViString */
#define IVIDIGITIZER_ATTR_TIME_INTERLEAVED_CHANNEL_LIST_AUTO		(IVI_CLASS_PUBLIC_ATTR_BASE + 401L)		/* ViBoolean */

/*- IviDigitizerDataInterleavedChannels Extension Group -*/
#define IVIDIGITIZER_ATTR_DATA_INTERLEAVED_CHANNEL_LIST				(IVI_CLASS_PUBLIC_ATTR_BASE + 500L)		/* ViString */

/*- IviDigitizerReferenceOscillator Extension Group -*/
#define IVIDIGITIZER_ATTR_REFERENCE_OSCILLATOR_EXTERNAL_FREQUENCY	(IVI_CLASS_PUBLIC_ATTR_BASE + 600L)		/* ViReal64 */
#define IVIDIGITIZER_ATTR_REFERENCE_OSCILLATOR_OUTPUT_ENABLED		(IVI_CLASS_PUBLIC_ATTR_BASE + 601L)		/* ViBoolean */
#define IVIDIGITIZER_ATTR_REFERENCE_OSCILLATOR_SOURCE				(IVI_CLASS_PUBLIC_ATTR_BASE + 602L)		/* ViInt32 */

/*- IviDigitizerSampleClock Extension Group -*/
#define IVIDIGITIZER_ATTR_SAMPLE_CLOCK_EXTERNAL_DIVIDER				(IVI_CLASS_PUBLIC_ATTR_BASE + 700L)		/* ViReal64 */
#define IVIDIGITIZER_ATTR_SAMPLE_CLOCK_EXTERNAL_FREQUENCY			(IVI_CLASS_PUBLIC_ATTR_BASE + 701L)		/* ViReal64 */
#define IVIDIGITIZER_ATTR_SAMPLE_CLOCK_OUTPUT_ENABLED				(IVI_CLASS_PUBLIC_ATTR_BASE + 702L)		/* ViBoolean */
#define IVIDIGITIZER_ATTR_SAMPLE_CLOCK_SOURCE						(IVI_CLASS_PUBLIC_ATTR_BASE + 703L)		/* ViInt32 */

/*- IviDigitizerSampleMode Extension Group -*/
#define IVIDIGITIZER_ATTR_SAMPLE_MODE								(IVI_CLASS_PUBLIC_ATTR_BASE + 800L)		/* ViInt32 */

/*- IviDigitizerDownconversion Extension Group -*/
#define IVIDIGITIZER_ATTR_DOWNCONVERSION_ENABLED					(IVI_CLASS_PUBLIC_ATTR_BASE + 900L)		/* ViBoolean */
#define IVIDIGITIZER_ATTR_DOWNCONVERSION_CENTER_FREQUENCY			(IVI_CLASS_PUBLIC_ATTR_BASE + 901L)		/* ViReal64 */
#define IVIDIGITIZER_ATTR_DOWNCONVERSION_IQ_INTERLEAVED				(IVI_CLASS_PUBLIC_ATTR_BASE + 902L)		/* ViBoolean */

/*- IviDigitizerArm Extension Group -*/
#define IVIDIGITIZER_ATTR_ACTIVE_ARM_SOURCE							(IVI_CLASS_PUBLIC_ATTR_BASE + 1000L)	/* ViString */
#define IVIDIGITIZER_ATTR_ARM_COUNT									(IVI_CLASS_PUBLIC_ATTR_BASE + 1001L)	/* ViInt32 */
#define IVIDIGITIZER_ATTR_ARM_COUPLING								(IVI_CLASS_PUBLIC_ATTR_BASE + 1002L)	/* ViInt32 */
#define IVIDIGITIZER_ATTR_ARM_DELAY									(IVI_CLASS_PUBLIC_ATTR_BASE + 1003L)	/* ViReal64 */
#define IVIDIGITIZER_ATTR_ARM_HYSTERESIS							(IVI_CLASS_PUBLIC_ATTR_BASE + 1004L)	/* ViReal64 */
#define IVIDIGITIZER_ATTR_ARM_LEVEL									(IVI_CLASS_PUBLIC_ATTR_BASE + 1005L)	/* ViReal64 */
#define IVIDIGITIZER_ATTR_ARM_OUTPUT_ENABLED						(IVI_CLASS_PUBLIC_ATTR_BASE + 1006L)	/* ViReal64 */
#define IVIDIGITIZER_ATTR_ARM_SLOPE									(IVI_CLASS_PUBLIC_ATTR_BASE + 1007L)	/* ViInt32 */
#define IVIDIGITIZER_ATTR_ARM_SOURCE_COUNT							(IVI_CLASS_PUBLIC_ATTR_BASE + 1008L)	/* ViInt32, read-only */
#define IVIDIGITIZER_ATTR_ARM_TYPE									(IVI_CLASS_PUBLIC_ATTR_BASE + 1009L)	/* ViInt32 */

/*- IviDigitizerMultiArm Extension Group -*/
#define IVIDIGITIZER_ATTR_ARM_SOURCE_LIST							(IVI_CLASS_PUBLIC_ATTR_BASE + 1100L)	/* ViString */
#define IVIDIGITIZER_ATTR_ARM_SOURCE_OPERATOR						(IVI_CLASS_PUBLIC_ATTR_BASE + 1101L)	/* ViInt32 */

/*- IviDigitizerGlitchArm Extension Group -*/
#define IVIDIGITIZER_ATTR_GLITCH_ARM_CONDITION						(IVI_CLASS_PUBLIC_ATTR_BASE + 1200L)	/* ViInt32 */
#define IVIDIGITIZER_ATTR_GLITCH_ARM_POLARITY						(IVI_CLASS_PUBLIC_ATTR_BASE + 1201L)	/* ViInt32 */
#define IVIDIGITIZER_ATTR_GLITCH_ARM_WIDTH							(IVI_CLASS_PUBLIC_ATTR_BASE + 1202L)	/* ViReal64 */

/*- IviDigitizerRuntArm Extension Group -*/
#define IVIDIGITIZER_ATTR_RUNT_ARM_HIGH_THRESHOLD					(IVI_CLASS_PUBLIC_ATTR_BASE + 1300L)	/* ViReal64 */
#define IVIDIGITIZER_ATTR_RUNT_ARM_LOW_THRESHOLD					(IVI_CLASS_PUBLIC_ATTR_BASE + 1301L)	/* ViReal64 */
#define IVIDIGITIZER_ATTR_RUNT_ARM_POLARITY							(IVI_CLASS_PUBLIC_ATTR_BASE + 1302L)	/* ViInt32 */

/*- IviDigitizerTVArm Extension -*/
#define IVIDIGITIZER_ATTR_TV_ARM_EVENT								(IVI_CLASS_PUBLIC_ATTR_BASE + 1400L)	/* ViInt32 */
#define IVIDIGITIZER_ATTR_TV_ARM_LINE_NUMBER						(IVI_CLASS_PUBLIC_ATTR_BASE + 1401L)	/* ViInt32 */
#define IVIDIGITIZER_ATTR_TV_ARM_POLARITY							(IVI_CLASS_PUBLIC_ATTR_BASE + 1402L)	/* ViInt32 */
#define IVIDIGITIZER_ATTR_TV_ARM_SIGNAL_FORMAT						(IVI_CLASS_PUBLIC_ATTR_BASE + 1403L)	/* ViInt32 */

/*- IviDigitizerWidthArm Extension Group -*/
#define IVIDIGITIZER_ATTR_WIDTH_ARM_CONDITION						(IVI_CLASS_PUBLIC_ATTR_BASE + 1500L)	/* ViInt32 */
#define IVIDIGITIZER_ATTR_WIDTH_ARM_HIGH_THRESHOLD					(IVI_CLASS_PUBLIC_ATTR_BASE + 1501L)	/* ViReal64 */
#define IVIDIGITIZER_ATTR_WIDTH_ARM_LOW_THRESHOLD					(IVI_CLASS_PUBLIC_ATTR_BASE + 1502L)	/* ViReal64 */
#define IVIDIGITIZER_ATTR_WIDTH_ARM_POLARITY						(IVI_CLASS_PUBLIC_ATTR_BASE + 1503L)	/* ViInt32 */

/*- IviDigitizerWindowArm Extension Group -*/
#define IVIDIGITIZER_ATTR_WINDOW_ARM_CONDITION						(IVI_CLASS_PUBLIC_ATTR_BASE + 1600L)	/* ViInt32 */
#define IVIDIGITIZER_ATTR_WINDOW_ARM_HIGH_THRESHOLD					(IVI_CLASS_PUBLIC_ATTR_BASE + 1601L)	/* ViReal64 */
#define IVIDIGITIZER_ATTR_WINDOW_ARM_LOW_THRESHOLD					(IVI_CLASS_PUBLIC_ATTR_BASE + 1602L)	/* ViReal64 */

/*- IviDigitizerTriggerModifier Extension Group -*/
#define IVIDIGITIZER_ATTR_TRIGGER_MODIFIER							(IVI_CLASS_PUBLIC_ATTR_BASE + 1700L)	/* ViInt32 */

/*- IviDigitizerMultiTrigger Extension Group -*/
#define IVIDIGITIZER_ATTR_TRIGGER_SOURCE_LIST						(IVI_CLASS_PUBLIC_ATTR_BASE + 1800L)	/* ViString */
#define IVIDIGITIZER_ATTR_TRIGGER_SOURCE_OPERATOR					(IVI_CLASS_PUBLIC_ATTR_BASE + 1801L)	/* ViInt32 */

/*- IviDigitizerPretriggerSamples Extension Group -*/
#define IVIDIGITIZER_ATTR_PRETRIGGER_SAMPLES						(IVI_CLASS_PUBLIC_ATTR_BASE + 1900L)	/* ViInt64 */

/*- IviDigitizerTriggerHoldoff Extension Group -*/
#define IVIDIGITIZER_ATTR_TRIGGER_HOLDOFF							(IVI_CLASS_PUBLIC_ATTR_BASE + 2000L)	/* ViReal64 */

/*- IIviDigitizerGlitchTrigger Extension Group -*/
#define IVIDIGITIZER_ATTR_GLITCH_TRIGGER_CONDITION					(IVI_CLASS_PUBLIC_ATTR_BASE + 2100L)	/* ViInt32 */
#define IVIDIGITIZER_ATTR_GLITCH_TRIGGER_POLARITY					(IVI_CLASS_PUBLIC_ATTR_BASE + 2101L)	/* ViInt32 */
#define IVIDIGITIZER_ATTR_GLITCH_TRIGGER_WIDTH						(IVI_CLASS_PUBLIC_ATTR_BASE + 2102L)	/* ViReal64 */

/*- IviDigitizerRuntTrigger Extension Group -*/
#define IVIDIGITIZER_ATTR_RUNT_TRIGGER_HIGH_THRESHOLD				(IVI_CLASS_PUBLIC_ATTR_BASE + 2200L)	/* ViReal64 */
#define IVIDIGITIZER_ATTR_RUNT_TRIGGER_LOW_THRESHOLD				(IVI_CLASS_PUBLIC_ATTR_BASE + 2201L)	/* ViReal64 */
#define IVIDIGITIZER_ATTR_RUNT_TRIGGER_POLARITY						(IVI_CLASS_PUBLIC_ATTR_BASE + 2202L)	/* ViInt32 */

/*- IviDigitizerTVTrigger Extension Group -*/
#define IVIDIGITIZER_ATTR_TV_TRIGGER_EVENT							(IVI_CLASS_PUBLIC_ATTR_BASE + 2300L)	/* ViInt32 */
#define IVIDIGITIZER_ATTR_TV_TRIGGER_LINE_NUMBER					(IVI_CLASS_PUBLIC_ATTR_BASE + 2301L)	/* ViInt32 */
#define IVIDIGITIZER_ATTR_TV_TRIGGER_POLARITY						(IVI_CLASS_PUBLIC_ATTR_BASE + 2302L)	/* ViInt32 */
#define IVIDIGITIZER_ATTR_TV_TRIGGER_SIGNAL_FORMAT					(IVI_CLASS_PUBLIC_ATTR_BASE + 2303L)	/* ViInt32 */

/*- IviDigitizerWidthTrigger Extension Group -*/
#define IVIDIGITIZER_ATTR_WIDTH_TRIGGER_CONDITION					(IVI_CLASS_PUBLIC_ATTR_BASE + 2400L)	/* ViInt32 */
#define IVIDIGITIZER_ATTR_WIDTH_TRIGGER_HIGH_THRESHOLD				(IVI_CLASS_PUBLIC_ATTR_BASE + 2401L)	/* ViReal64 */
#define IVIDIGITIZER_ATTR_WIDTH_TRIGGER_LOW_THRESHOLD				(IVI_CLASS_PUBLIC_ATTR_BASE + 2402L)	/* ViReal64 */
#define IVIDIGITIZER_ATTR_WIDTH_TRIGGER_POLARITY					(IVI_CLASS_PUBLIC_ATTR_BASE + 2403L)	/* ViInt32 */

/*- IviDigitizerWindowTrigger Extension Group -*/
#define IVIDIGITIZER_ATTR_WINDOW_TRIGGER_CONDITION					(IVI_CLASS_PUBLIC_ATTR_BASE + 2500L)	/* ViInt32 */
#define IVIDIGITIZER_ATTR_WINDOW_TRIGGER_HIGH_THRESHOLD				(IVI_CLASS_PUBLIC_ATTR_BASE + 2501L)	/* ViReal64 */
#define IVIDIGITIZER_ATTR_WINDOW_TRIGGER_LOW_THRESHOLD				(IVI_CLASS_PUBLIC_ATTR_BASE + 2502L)	/* ViReal64 */

/****************************************************************************
 *----------------- IviDigitizer Class Attribute Value Defines -------------*
 ****************************************************************************/
/*- Defined values for attribute IVIDIGITIZER_ATTR_IS_IDLE -*/
/*- Defined values for attribute IVIDIGITIZER_ATTR_IS_MEASURING -*/
/*- Defined values for attribute IVIDIGITIZER_ATTR_IS_WAITING_FOR_ARM -*/
/*- Defined values for attribute IVIDIGITIZER_ATTR_IS_WAITING_FOR_TRIGGER -*/
#define IVIDIGITIZER_VAL_ACQUISITION_STATUS_RESULT_TRUE				(1L)
#define IVIDIGITIZER_VAL_ACQUISITION_STATUS_RESULT_FALSE			(2L)
#define IVIDIGITIZER_VAL_ACQUISITION_STATUS_RESULT_UNKNOWN			(3L)

/*- Defined values for attribute IVIDIGITIZER_ATTR_TRIGGER_COUPLING -*/
/*- Defined values for attribute IVIDIGITIZER_ATTR_ARM_COUPLING -*/
#define IVIDIGITIZER_VAL_TRIGGER_COUPLING_AC						(0L)
#define IVIDIGITIZER_VAL_TRIGGER_COUPLING_DC						(1L)
#define IVIDIGITIZER_VAL_TRIGGER_COUPLING_HF_REJECT					(2L)
#define IVIDIGITIZER_VAL_TRIGGER_COUPLING_LF_REJECT					(3L)
#define IVIDIGITIZER_VAL_TRIGGER_COUPLING_NOISE_REJECT				(4L)

/*- Defined values for attribute IVIDIGITIZER_ATTR_TRIGGER_SLOPE -*/
/*- Defined values for attribute IVIDIGITIZER_ATTR_ARM_SLOPE -*/
#define IVIDIGITIZER_VAL_TRIGGER_SLOPE_NEGATIVE						(0L)
#define IVIDIGITIZER_VAL_TRIGGER_SLOPE_POSITIVE						(1L)

/*- Defined values for attribute IVIDIGITIZER_ATTR_TRIGGER_TYPE -*/
#define IVIDIGITIZER_VAL_EDGE_TRIGGER								(1L)
#define IVIDIGITIZER_VAL_WIDTH_TRIGGER								(2L)
#define IVIDIGITIZER_VAL_RUNT_TRIGGER								(3L)
#define IVIDIGITIZER_VAL_GLITCH_TRIGGER								(4L)
#define IVIDIGITIZER_VAL_TV_TRIGGER									(5L)
#define IVIDIGITIZER_VAL_WINDOW_TRIGGER								(6L)

/*- Defined values for attribute IVIDIGITIZER_ATTR_ARM_TYPE -*/
#define IVIDIGITIZER_VAL_EDGE_ARM									(1L)
#define IVIDIGITIZER_VAL_WIDTH_ARM									(2L)
#define IVIDIGITIZER_VAL_RUNT_ARM									(3L)
#define IVIDIGITIZER_VAL_GLITCH_ARM									(4L)
#define IVIDIGITIZER_VAL_TV_ARM										(5L)
#define IVIDIGITIZER_VAL_WINDOW_ARM									(6L)

/*- Defined values for attribute IVIDIGITIZER_ATTR_VERTICAL_COUPLING -*/
#define IVIDIGITIZER_VAL_VERTICAL_COUPLING_AC						(0L)
#define IVIDIGITIZER_VAL_VERTICAL_COUPLING_DC						(1L)
#define IVIDIGITIZER_VAL_VERTICAL_COUPLING_GND						(2L)

/*- Defined values for attribute IVIDIGITIZER_ATTR_TEMPERATURE_UNITS -*/
#define IVIDIGITIZER_VAL_CELSIUS									(0L)
#define IVIDIGITIZER_VAL_FAHRENHEIT									(1L)
#define IVIDIGITIZER_VAL_KELVIN										(2L)

/*- Defined values for attribute IVIDIGITIZER_ATTR_REFERENCE_OSCILLATOR_SOURCE -*/
#define IVIDIGITIZER_VAL_REFERENCE_OSCILLATOR_SOURCE_INTERNAL		(0L)
#define IVIDIGITIZER_VAL_REFERENCE_OSCILLATOR_SOURCE_EXTERNAL		(1L)
#define IVIDIGITIZER_VAL_REFERENCE_OSCILLATOR_SOURCE_PXI_CLK10		(2L)
#define IVIDIGITIZER_VAL_REFERENCE_OSCILLATOR_SOURCE_PXIE_CLK100	(3L)

/*- Defined values for attribute IVIDIGITIZER_ATTR_SAMPLE_CLOCK_SOURCE -*/
#define IVIDIGITIZER_VAL_SAMPLE_CLOCK_SOURCE_INTERNAL				(0L)
#define IVIDIGITIZER_VAL_SAMPLE_CLOCK_SOURCE_EXTERNAL				(1L)

/*- Defined values for attribute IVIDIGITIZER_ATTR_SAMPLE_MODE -*/
#define IVIDIGITIZER_VAL_SAMPLE_MODE_REAL_TIME						(0L)
#define IVIDIGITIZER_VAL_SAMPLE_MODE_EQUIVALENT_TIME				(1L)

/*- Defined values for attribute IVIDIGITIZER_ATTR_ARM_SOURCE_OPERATOR -*/
#define IVIDIGITIZER_VAL_ARM_SOURCE_OPERATOR_AND					(0L)
#define IVIDIGITIZER_VAL_ARM_SOURCE_OPERATOR_OR						(1L)
#define IVIDIGITIZER_VAL_ARM_SOURCE_OPERATOR_NONE					(2L)

/*- Defined values for attribute IVIDIGITIZER_ATTR_GLITCH_ARM_CONDITION -*/
/*- Defined values for attribute IVIDIGITIZER_ATTR_GLITCH_TRIGGER_CONDITION -*/
#define IVIDIGITIZER_VAL_GLITCH_LESS_THAN							(1L)
#define IVIDIGITIZER_VAL_GLITCH_GREATER_THAN						(2L)

/*- Defined values for attribute IVIDIGITIZER_ATTR_GLITCH_ARM_POLARITY -*/
/*- Defined values for attribute IVIDIGITIZER_ATTR_GLITCH_TRIGGER_POLARITY -*/
#define IVIDIGITIZER_VAL_GLITCH_POSITIVE							(1L)
#define IVIDIGITIZER_VAL_GLITCH_NEGATIVE							(2L)
#define IVIDIGITIZER_VAL_GLITCH_EITHER								(3L)

/*- Defined values for attribute IVIDIGITIZER_ATTR_RUNT_ARM_POLARITY -*/
/*- Defined values for attribute IVIDIGITIZER_ATTR_RUNT_TRIGGER_POLARITY -*/
#define IVIDIGITIZER_VAL_RUNT_POSITIVE								(1L)
#define IVIDIGITIZER_VAL_RUNT_NEGATIVE								(2L)
#define IVIDIGITIZER_VAL_RUNT_EITHER								(3L)

/*- Defined values for attribute IVIDIGITIZER_ATTR_TV_ARM_EVENT -*/
/*- Defined values for attribute IVIDIGITIZER_ATTR_TV_TRIGGER_EVENT -*/
#define IVIDIGITIZER_VAL_TV_EVENT_FIELD1							(1L)
#define IVIDIGITIZER_VAL_TV_EVENT_FIELD2							(2L)
#define IVIDIGITIZER_VAL_TV_EVENT_ANY_FIELD							(3L)
#define IVIDIGITIZER_VAL_TV_EVENT_ANY_LINE							(4L)
#define IVIDIGITIZER_VAL_TV_EVENT_LINE_NUMBER						(5L)

/*- Defined values for attribute IVIDIGITIZER_ATTR_TV_ARM_POLARITY -*/
/*- Defined values for attribute IVIDIGITIZER_ATTR_TV_TRIGGER_POLARITY -*/
#define IVIDIGITIZER_VAL_TV_POSITIVE								(1L)
#define IVIDIGITIZER_VAL_TV_NEGATIVE								(2L)

/*- Defined values for attribute IVIDIGITIZER_ATTR_TV_ARM_SIGNAL_FORMAT -*/
/*- Defined values for attribute IVIDIGITIZER_ATTR_TV_TRIGGER_SIGNAL_FORMAT -*/
#define IVIDIGITIZER_VAL_NTSC										(1L)
#define IVIDIGITIZER_VAL_PAL										(2L)
#define IVIDIGITIZER_VAL_SECAM										(3L)

/*- Defined values for attribute IVIDIGITIZER_ATTR_WIDTH_ARM_CONDITION -*/
/*- Defined values for attribute IVIDIGITIZER_ATTR_WIDTH_TRIGGER_CONDITION -*/
#define IVIDIGITIZER_VAL_WIDTH_WITHIN								(1L)
#define IVIDIGITIZER_VAL_WIDTH_OUTSIDE								(2L)

/*- Defined values for attribute IVIDIGITIZER_ATTR_WIDTH_ARM_POLARITY -*/
/*- Defined values for attribute IVIDIGITIZER_ATTR_WIDTH_TRIGGER_POLARITY -*/
#define IVIDIGITIZER_VAL_WIDTH_POSITIVE								(1L)
#define IVIDIGITIZER_VAL_WIDTH_NEGATIVE								(2L)
#define IVIDIGITIZER_VAL_WIDTH_EITHER								(3L)

/*- Defined values for attribute IVIDIGITIZER_ATTR_WINDOW_ARM_CONDITION -*/
/*- Defined values for attribute IVIDIGITIZER_ATTR_WINDOW_TRIGGER_CONDITION -*/
#define IVIDIGITIZER_VAL_WINDOW_CONDITION_ENTERING					(1L)
#define IVIDIGITIZER_VAL_WINDOW_CONDITION_LEAVING					(2L)

/*- Defined values for attribute IVIDIGITIZER_ATTR_TRIGGER_MODIFIER -*/
#define IVIDIGITIZER_VAL_TRIGGER_MODIFIER_NONE						(1L)
#define IVIDIGITIZER_VAL_TRIGGER_MODIFIER_AUTO						(2L)
#define IVIDIGITIZER_VAL_TRIGGER_MODIFIER_AUTO_LEVEL				(3L)

#define IVIDIGITIZER_VAL_TRIGGER_MOD_CLASS_EXT_BASE					(100L)
#define IVIDIGITIZER_VAL_TRIGGER_MOD_SPECIFIC_EXT_BASE				(1000L)

/*- Defined values for attribute IVIDIGITIZER_ATTR_TRIGGER_SOURCE_OPERATOR -*/
#define IVIDIGITIZER_VAL_TRIGGER_SOURCE_OPERATOR_AND				(0L)
#define IVIDIGITIZER_VAL_TRIGGER_SOURCE_OPERATOR_OR					(1L)
#define IVIDIGITIZER_VAL_TRIGGER_SOURCE_OPERATOR_NONE				(2L)

/****************************************************************************
*----------------- IviDigitizer Function Parameter Value Defines -------------*
****************************************************************************/
/*- Defined values for Read Waveform Int16, Read Waveform Int32, Read Waveform Int8, Read Waveform Real64 -*/
#define IVIDIGITIZER_VAL_TIMEOUT_IMMEDIATE                           (0L)
#define IVIDIGITIZER_VAL_TIMEOUT_INFINITE                            (-1L)

/****************************************************************************
 *--------- IviDigitizer Class Instrument Driver Function Declarations -----*
 ****************************************************************************/
/*- Required VXIplug&play Functions -*/
 ViStatus _VI_FUNC IviDigitizer_init (ViRsrc logicalName, 
									ViBoolean idQuery, 
									ViBoolean resetDevice, 
									ViSession *vi);

ViStatus _VI_FUNC IviDigitizer_close (ViSession vi);

ViStatus _VI_FUNC IviDigitizer_reset (ViSession vi);

ViStatus _VI_FUNC IviDigitizer_self_test (ViSession vi, 
									   ViInt16 *selfTestResult, 
									   ViChar selfTestMessage[]);

ViStatus _VI_FUNC IviDigitizer_error_query (ViSession vi, 
										 ViInt32 *errorCode, 
										 ViChar errorMessage[]);

ViStatus _VI_FUNC IviDigitizer_error_message (ViSession vi, 
										   ViStatus statusCode, 
										   ViChar message[]);

ViStatus _VI_FUNC IviDigitizer_revision_query (ViSession vi, 
											ViChar driverRev[], 
											ViChar instrRev[]);

/*- Utility Functions -*/
ViStatus _VI_FUNC IviDigitizer_InvalidateAllAttributes (ViSession vi);

ViStatus _VI_FUNC IviDigitizer_ResetWithDefaults (ViSession vi);

ViStatus _VI_FUNC IviDigitizer_Disable (ViSession vi);

/*- Required IVI Functions -*/
ViStatus _VI_FUNC IviDigitizer_InitWithOptions (ViRsrc logicalName, 
											 ViBoolean IDQuery,
											 ViBoolean resetDevice, 
											 ViConstString optionString, 
											 ViSession *vi);

/*- Set, Get, and Check Attribute Functions -*/

ViStatus _VI_FUNC IviDigitizer_GetAttributeViInt32 (ViSession vi, 
												 ViConstString repeatedCapName,
												 ViAttr attributeId,
												 ViInt32 *value);

ViStatus _VI_FUNC IviDigitizer_SetAttributeViInt32 (ViSession vi, 
												 ViConstString repeatedCapName,
												 ViAttr attributeId,
												 ViInt32 value);

ViStatus _VI_FUNC IviDigitizer_CheckAttributeViInt32 (ViSession vi, 
												   ViConstString repeatedCapName,
												   ViAttr attributeId,
												   ViInt32 value);

ViStatus _VI_FUNC IviDigitizer_GetAttributeViInt64 (ViSession vi, 
													ViConstString repeatedCapName,
													ViAttr attributeId,
													ViInt64 *value);

ViStatus _VI_FUNC IviDigitizer_SetAttributeViInt64 (ViSession vi, 
													ViConstString repeatedCapName,
													ViAttr attributeId,
													ViInt64 value);

ViStatus _VI_FUNC IviDigitizer_CheckAttributeViInt64 (ViSession vi, 
													  ViConstString repeatedCapName,
													  ViAttr attributeId,
													  ViInt64 value);

ViStatus _VI_FUNC IviDigitizer_GetAttributeViReal64 (ViSession vi, 
												  ViConstString repeatedCapName, 
												  ViAttr attributeId, 
												  ViReal64 *value);

ViStatus _VI_FUNC IviDigitizer_SetAttributeViReal64 (ViSession vi, 
												  ViConstString repeatedCapName, 
												  ViAttr attributeId, 
												  ViReal64 value);

ViStatus _VI_FUNC IviDigitizer_CheckAttributeViReal64 (ViSession vi, 
													ViConstString repeatedCapName, 
													ViAttr attributeId, 
													ViReal64 value);

ViStatus _VI_FUNC IviDigitizer_GetAttributeViString (ViSession vi, 
												  ViConstString repeatedCapName, 
												  ViAttr attributeId, 
												  ViInt32 bufferSize, 
												  ViChar value[]);

ViStatus _VI_FUNC IviDigitizer_SetAttributeViString (ViSession vi, 
												  ViConstString repeatedCapName, 
												  ViAttr attributeId, 
												  ViConstString value);

ViStatus _VI_FUNC IviDigitizer_CheckAttributeViString (ViSession vi, 
													ViConstString repeatedCapName, 
													ViAttr attributeId, 
													ViConstString value); 

ViStatus _VI_FUNC IviDigitizer_GetAttributeViBoolean (ViSession vi, 
												   ViConstString repeatedCapName, 
												   ViAttr attributeId, 
												   ViBoolean *value);

ViStatus _VI_FUNC IviDigitizer_SetAttributeViBoolean (ViSession vi, 
												   ViConstString repeatedCapName, 
												   ViAttr attributeId, 
												   ViBoolean value);

ViStatus _VI_FUNC IviDigitizer_CheckAttributeViBoolean (ViSession vi, 
													 ViConstString repeatedCapName, 
													 ViAttr attributeId, 
													 ViBoolean value);

ViStatus _VI_FUNC IviDigitizer_GetAttributeViSession (ViSession vi, 
												   ViConstString repeatedCapName, 
												   ViAttr attributeId, 
												   ViSession *value);

ViStatus _VI_FUNC IviDigitizer_SetAttributeViSession (ViSession vi, 
												   ViConstString repeatedCapName, 
												   ViAttr attributeId, 
												   ViSession value);

ViStatus _VI_FUNC IviDigitizer_CheckAttributeViSession (ViSession vi, 
													 ViConstString repeatedCapName, 
													 ViAttr attributeId, 
													 ViSession value);

/*- Lock and Unlock Functions -*/
ViStatus _VI_FUNC IviDigitizer_LockSession (ViSession vi, 
										 ViBoolean *callerHasLock);

ViStatus _VI_FUNC IviDigitizer_UnlockSession (ViSession vi, 
										   ViBoolean *callerHasLock);

/*- Error Information Functions -*/
ViStatus _VI_FUNC IviDigitizer_GetError (ViSession vi, 
									  ViStatus *errorCode, 
									  ViInt32 bufferSize, 
									  ViChar description[]);

ViStatus _VI_FUNC IviDigitizer_ClearError (ViSession vi);

/*- Interchangeability Checking Functions -*/
ViStatus _VI_FUNC IviDigitizer_GetNextInterchangeWarning (ViSession vi, 
													   ViInt32 bufferSize,
													   ViChar warning[]);

ViStatus _VI_FUNC IviDigitizer_ClearInterchangeWarnings (ViSession vi);
ViStatus _VI_FUNC IviDigitizer_ResetInterchangeCheck (ViSession vi);

ViStatus _VI_FUNC IviDigitizer_GetNextCoercionRecord (ViSession vi,
												   ViInt32 bufferSize, 
												   ViChar record[]);

ViStatus _VI_FUNC IviDigitizer_GetSpecificDriverCHandle (ViSession vi,
													  ViSession* specificDriverCHandle);

/*- IviDigitizer Fundamental Capabilities -*/
ViStatus _VI_FUNC IviDigitizer_Abort (ViSession vi);

ViStatus _VI_FUNC IviDigitizer_ConfigureAcquisition (ViSession vi,
												  ViInt64 NumRecords,
												  ViInt64 RecordSize,
												  ViReal64 SampleRate);

ViStatus _VI_FUNC IviDigitizer_ConfigureActiveTriggerSource (ViSession vi,
												  ViString TriggerSource);


ViStatus _VI_FUNC IviDigitizer_ConfigureChannel (ViSession vi,
											  ViConstString ChannelName,
											  ViReal64 Range,
											  ViReal64 Offset,
											  ViInt32 Coupling,
											  ViBoolean Enabled);

ViStatus _VI_FUNC IviDigitizer_ConfigureEdgeTriggerSource (ViSession vi,
														ViConstString Source,
														ViReal64 Level,
														ViInt32 Slope);

ViStatus _VI_FUNC IviDigitizer_FetchWaveformInt8 (ViSession vi,
												ViConstString ChannelName,
												ViInt64 WaveformArraySize,
												ViInt8 WaveformArray[],
												ViInt64* ActualPoints,
												ViInt64* FirstValidPoint,
												ViReal64* InitialXOffset,
												ViReal64* InitialXTimeSeconds,
												ViReal64* InitialXTimeFraction,
												ViReal64* XIncrement,
												ViReal64* ScaleFactor,
												ViReal64* ScaleOffset);

ViStatus _VI_FUNC IviDigitizer_FetchWaveformInt16 (ViSession vi,
												ViConstString ChannelName,
												ViInt64 WaveformArraySize,
												ViInt16 WaveformArray[],
												ViInt64* ActualPoints,
												ViInt64* FirstValidPoint,
												ViReal64* InitialXOffset,
												ViReal64* InitialXTimeSeconds,
												ViReal64* InitialXTimeFraction,
												ViReal64* XIncrement,
												ViReal64* ScaleFactor,
												ViReal64* ScaleOffset);

ViStatus _VI_FUNC IviDigitizer_FetchWaveformInt32 (ViSession vi,
												ViConstString ChannelName,
												ViInt64 WaveformArraySize,
												ViInt32 WaveformArray[],
												ViInt64* ActualPoints,
												ViInt64* FirstValidPoint,
												ViReal64* InitialXOffset,
												ViReal64* InitialXTimeSeconds,
												ViReal64* InitialXTimeFraction,
												ViReal64* XIncrement,
												ViReal64* ScaleFactor,
												ViReal64* ScaleOffset);

ViStatus _VI_FUNC IviDigitizer_FetchWaveformReal64 (ViSession vi,
												ViConstString ChannelName,
												ViInt64 WaveformArraySize,
												ViReal64 WaveformArray[],
												ViInt64* ActualPoints,
												ViInt64* FirstValidPoint,												 
												ViReal64* InitialXOffset,
												ViReal64* InitialXTimeSeconds,
												ViReal64* InitialXTimeFraction,
												ViReal64* XIncrement);

ViStatus _VI_FUNC IviDigitizer_GetChannelName (ViSession vi,
											ViInt32 ChannelIndex, 
											ViInt32 ChannelNameBufferSize,
											ViChar ChannelName[]);
									  
ViStatus _VI_FUNC IviDigitizer_GetTriggerSourceName (ViSession vi,
												  ViInt32 SourceIndex, 
												  ViInt32 SourceNameBufferSize,
												  ViChar SourceName[]);

ViStatus _VI_FUNC IviDigitizer_InitiateAcquisition (ViSession vi);

ViStatus _VI_FUNC IviDigitizer_IsIdle (ViSession vi,
											ViInt32* Status);

ViStatus _VI_FUNC IviDigitizer_IsMeasuring (ViSession vi,
										 ViInt32* Status);

ViStatus _VI_FUNC IviDigitizer_IsWaitingForArm (ViSession vi,
											 ViInt32* Status);

ViStatus _VI_FUNC IviDigitizer_IsWaitingForTrigger (ViSession vi,
												 ViInt32* Status);

ViStatus _VI_FUNC IviDigitizer_QueryMinWaveformMemory (ViSession vi,
													ViInt32 DataWidth, 
													ViInt64 NumRecords, 
													ViInt64 OffsetWithinRecord, 
													ViInt64 NumPointsPerRecord,
													ViInt64* NumSamples);												 
												 
ViStatus _VI_FUNC IviDigitizer_ReadWaveformInt8 (ViSession vi,
											ViConstString ChannelName,
											ViInt32 MaxTimeMilliseconds,
											ViInt64 WaveformArraySize,
											ViInt8 WaveformArray[],
											ViInt64* ActualPoints,
											ViInt64* FirstValidPoint,
											ViReal64* InitialXOffset,
											ViReal64* InitialXTimeSeconds,
											ViReal64* InitialXTimeFraction,
											ViReal64* XIncrement,
											ViReal64* ScaleFactor,
											ViReal64* ScaleOffset);

ViStatus _VI_FUNC IviDigitizer_ReadWaveformInt16 (ViSession vi,
											ViConstString ChannelName,
											ViInt32 MaxTimeMilliseconds,
											ViInt64 WaveformArraySize,
											ViInt16 WaveformArray[],
											ViInt64* ActualPoints,
											ViInt64* FirstValidPoint,
											ViReal64* InitialXOffset,
											ViReal64* InitialXTimeSeconds,
											ViReal64* InitialXTimeFraction,
											ViReal64* XIncrement,
											ViReal64* ScaleFactor,
											ViReal64* ScaleOffset);

ViStatus _VI_FUNC IviDigitizer_ReadWaveformInt32 (ViSession vi,
											ViConstString ChannelName,
											ViInt32 MaxTimeMilliseconds,
											ViInt64 WaveformArraySize,
											ViInt32 WaveformArray[],
											ViInt64* ActualPoints,
											ViInt64* FirstValidPoint,
											ViReal64* InitialXOffset,
											ViReal64* InitialXTimeSeconds,
											ViReal64* InitialXTimeFraction,
											ViReal64* XIncrement,
											ViReal64* ScaleFactor,
											ViReal64* ScaleOffset);

ViStatus _VI_FUNC IviDigitizer_ReadWaveformReal64 (ViSession vi,
											ViConstString ChannelName,
											ViInt32 MaxTimeMilliseconds,
											ViInt64 WaveformArraySize,
											ViReal64 WaveformArray[],
											ViInt64* ActualPoints,
											ViInt64* FirstValidPoint,
											ViReal64* InitialXOffset,
											ViReal64* InitialXTimeSeconds,
											ViReal64* InitialXTimeFraction,
											ViReal64* XIncrement);

ViStatus _VI_FUNC IviDigitizer_WaitForAcquisitionComplete (ViSession vi,
														ViInt32 MaxTimeMilliseconds);

/*- IviDigitizerMultiRecordAcquisition Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_FetchMultiRecordWaveformInt8 (ViSession vi,
														ViConstString ChannelName,
														ViInt64 FirstRecord,
														ViInt64 NumRecords,
														ViInt64 OffsetWithinRecord,
														ViInt64 NumPointsPerRecord,
														ViInt64 WaveformArraySize,
														ViInt8 WaveformArray[],
														ViInt64* ActualRecords,
														ViInt64 ActualPoints[],
														ViInt64 FirstValidPoint[],
														ViReal64 InitialXOffset[],
														ViReal64 InitialXTimeSeconds[],
														ViReal64 InitialXTimeFraction[],
														ViReal64* XIncrement,
														ViReal64* ScaleFactor,
														ViReal64* ScaleOffset);

ViStatus _VI_FUNC IviDigitizer_FetchMultiRecordWaveformInt16 (ViSession vi,
														ViConstString ChannelName,
														ViInt64 FirstRecord,
														ViInt64 NumRecords,
														ViInt64 OffsetWithinRecord,
														ViInt64 NumPointsPerRecord,
														ViInt64 WaveformArraySize,
														ViInt16 WaveformArray[],
														ViInt64* ActualRecords,
														ViInt64 ActualPoints[],
														ViInt64 FirstValidPoint[],
														ViReal64 InitialXOffset[],
														ViReal64 InitialXTimeSeconds[],
														ViReal64 InitialXTimeFraction[],
														ViReal64* XIncrement,
														ViReal64* ScaleFactor,
														ViReal64* ScaleOffset);
														
ViStatus _VI_FUNC IviDigitizer_FetchMultiRecordWaveformInt32 (ViSession vi,
														ViConstString ChannelName,
														ViInt64 FirstRecord,
														ViInt64 NumRecords,
														ViInt64 OffsetWithinRecord,
														ViInt64 NumPointsPerRecord,
														ViInt64 WaveformArraySize,
														ViInt32 WaveformArray[],
														ViInt64* ActualRecords,
														ViInt64 ActualPoints[],
														ViInt64 FirstValidPoint[],
														ViReal64 InitialXOffset[],
														ViReal64 InitialXTimeSeconds[],
														ViReal64 InitialXTimeFraction[],
														ViReal64* XIncrement,
														ViReal64* ScaleFactor,
														ViReal64* ScaleOffset);

ViStatus _VI_FUNC IviDigitizer_FetchMultiRecordWaveformReal64 (ViSession vi,
														ViConstString ChannelName,
														ViInt64 FirstRecord,
														ViInt64 NumRecords,
														ViInt64 OffsetWithinRecord,
														ViInt64 NumPointsPerRecord,
														ViInt64 WaveformArraySize,
														ViReal64 WaveformArray[],
														ViInt64* ActualRecords,
														ViInt64 ActualPoints[],
														ViInt64 FirstValidPoint[],
														ViReal64 InitialXOffset[],
														ViReal64 InitialXTimeSeconds[],
														ViReal64 InitialXTimeFraction[],
														ViReal64* XIncrement);
														
/*- IviDigitizerBoardTemperature Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_ConfigureTemperatureUnits (ViSession vi,
													   ViInt32 Units);

ViStatus _VI_FUNC IviDigitizer_QueryBoardTemperature (ViSession vi,
												   ViReal64* Temperature);

/*- IviDigitizerChannelFilter Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_ConfigureInputFilter (ViSession vi,
												  ViConstString ChannelName,
												  ViReal64 MinFrequency,
												  ViReal64 MaxFrequency);

/*- IviDigitizerChannelTemperature Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_QueryChannelTemperature (ViSession vi,
													 ViConstString ChannelName,
													 ViReal64* Temperature);

/*- IviDigitizerTimeInterleavedChannels Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_ConfigureTimeInterleavedChannelList (ViSession vi,
																 ViConstString ChannelName,
																 ViConstString ChannelList);

/*- IviDigitizerDataInterleavedChannels Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_ConfigureDataInterleavedChannelList (ViSession vi,
																 ViConstString ChannelName,
																 ViConstString ChannelList);

/*- IviDigitizerReferenceOscillator Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_ConfigureReferenceOscillator (ViSession vi,
														  ViInt32 Source,
														  ViReal64 Frequency);

ViStatus _VI_FUNC IviDigitizer_ConfigureReferenceOscillatorOutputEnabled (ViSession vi,
																	   ViBoolean Enabled);

/*- IviDigitizerSampleClock Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_ConfigureSampleClock (ViSession vi,
												  ViInt32 Source,
												  ViReal64 Frequency,
												  ViReal64 Divider);

ViStatus _VI_FUNC IviDigitizer_ConfigureSampleClockOutputEnabled (ViSession vi,
															   ViBoolean Enabled);

/*- IviDigitizerSampleMode Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_ConfigureSampleMode (ViSession vi,
												 ViInt32 SampleMode);

/*- IviDigitizerSelfCalibration Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_SelfCalibrate (ViSession vi);

/*- IviDigitizerDownconversion Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_ConfigureDownconversion (ViSession vi,
													 ViConstString ChannelName,
													 ViBoolean Enabled,
													 ViReal64 CenterFrequency);

/*- IviDigitizerArm Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_ConfigureEdgeArmSource (ViSession vi,
													ViConstString Source,
													ViReal64 Level,
													ViInt32 Slope);

ViStatus _VI_FUNC IviDigitizer_GetArmSourceName (ViSession vi,
											  ViInt32 SourceIndex, 
											  ViInt32 SourceNameBufferSize,
											  ViChar SourceName[]);

/*- IviDigitizerMultiArm Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_ConfigureMultiArm (ViSession vi,
											   ViConstString SourceList,
											   ViInt32 Operator);

/*- IviDigitizerGlitchArm Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_ConfigureGlitchArmSource (ViSession vi,
													  ViConstString Source,
													  ViReal64 Level,
													  ViReal64 Width,
													  ViInt32 Polarity,
													  ViInt32 Condition);

/*- IviDigitizerRuntArm Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_ConfigureRuntArmSource (ViSession vi,
													ViConstString Source,
													ViReal64 ThresholdLow,
													ViReal64 ThresholdHigh,
													ViInt32 Polarity);
													
/*- IviDigitizerSoftwareArm Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_SendSoftwareArm (ViSession vi);

/*- IviDigitizerTVArm Extension -*/
ViStatus _VI_FUNC IviDigitizer_ConfigureTVArmSource (ViSession vi,
												  ViConstString Source,
												  ViInt32 SignalFormat,
												  ViInt32 Event,
												  ViInt32 Polarity);

/*- IviDigitizerWidthArm Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_ConfigureWidthArmSource (ViSession vi,
													 ViConstString Source,
													 ViReal64 Level,
													 ViReal64 ThresholdLow,
													 ViReal64 ThresholdHigh,
													 ViInt32 Polarity,
													 ViInt32 Condition);

/*- IviDigitizerWindowArm Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_ConfigureWindowArmSource (ViSession vi,
													  ViConstString Source,
													  ViReal64 ThresholdLow,
													  ViReal64 ThresholdHigh,
													  ViInt32 Condition);

/*- IviDigitizerTriggerModifier Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_ConfigureTriggerModifier (ViSession vi, 
													  ViInt32 TriggerModifier);

/*- IviDigitizerMultiTrigger Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_ConfigureMultiTrigger (ViSession vi,
												   ViConstString SourceList,
												   ViInt32 Operator);

/*- IviDigitizerPretriggerSamples Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_ConfigurePretriggerSamples (ViSession vi,
														ViInt64 PretriggerSamples);

/*- IviDigitizerTriggerHoldoff Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_ConfigureTriggerHoldoff (ViSession vi,
													 ViReal64 TriggerHoldoff);

/*- IIviDigitizerGlitchTrigger Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_ConfigureGlitchTriggerSource (ViSession vi,
														  ViConstString Source,
														  ViReal64 Level,
														  ViReal64 Width,
														  ViInt32 Polarity,
														  ViInt32 Condition);

/*- IviDigitizerRuntTrigger Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_ConfigureRuntTriggerSource (ViSession vi,
														ViConstString Source,
														ViReal64 ThresholdLow,
														ViReal64 ThresholdHigh,
														ViInt32 Polarity);

/*- IviDigitizerSoftwareTrigger Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_SendSoftwareTrigger (ViSession vi);

/*- IviDigitizerTVTrigger Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_ConfigureTVTriggerSource (ViSession vi,
													  ViConstString Source,
													  ViInt32 SignalFormat,
													  ViInt32 Event,
													  ViInt32 Polarity);

/*- IviDigitizerWidthTrigger Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_ConfigureWidthTriggerSource (ViSession vi,
														 ViConstString Source,
														 ViReal64 Level,
														 ViReal64 ThresholdLow,
														 ViReal64 ThresholdHigh,
														 ViInt32 Polarity,
														 ViInt32 Condition);

/*- IviDigitizerWindowTrigger Extension Group -*/
ViStatus _VI_FUNC IviDigitizer_ConfigureWindowTriggerSource (ViSession vi,
														  ViConstString Source,
														  ViReal64 ThresholdLow,
														  ViReal64 ThresholdHigh,
														  ViInt32 Condition);

/****************************************************************************
*--------------- IviDigitizer Class Error And Completion Codes -------------*
****************************************************************************/
#define IVIDIGITIZER_ERROR_TRIGGER_NOT_SOFTWARE						(IVI_CROSS_CLASS_ERROR_BASE + 1L)
#define IVIDIGITIZER_ERROR_CHANNEL_NOT_ENABLED						(IVI_CLASS_ERROR_BASE + 1L)
#define IVIDIGITIZER_ERROR_MAX_TIME_EXCEEDED						(IVI_CLASS_ERROR_BASE + 2L)
#define IVIDIGITIZER_ERROR_ARM_NOT_SOFTWARE							(IVI_CLASS_ERROR_BASE + 3L)
#define IVIDIGITIZER_ERROR_INCOMPATIBLE_FETCH						(IVI_CLASS_ERROR_BASE + 4L)

#define IVIDIGITIZER_ERRMSG_TRIGGER_NOT_SOFTWARE					"Trigger source is not set to software trigger."
#define IVIDIGITIZER_ERRMSG_CHANNEL_NOT_ENABLED						"The specified channel is not enabled."
#define IVIDIGITIZER_ERRMSG_MAX_TIME_EXCEEDED						"Maximum time exceeded before the operation completed."
#define IVIDIGITIZER_ERRMSG_ARM_NOT_SOFTWARE						"Arm source is not set to software arm."
#define IVIDIGITIZER_ERRMSG_INCOMPATIBLE_FETCH						"The multi-record acquisition fetch functions must be used if the number of records to acquire is greater than 1."

#define IVIDIGITIZER_ERROR_CODES_AND_MSGS \
{IVIDIGITIZER_ERROR_TRIGGER_NOT_SOFTWARE,	IVIDIGITIZER_ERRMSG_TRIGGER_NOT_SOFTWARE},\
{IVIDIGITIZER_ERROR_CHANNEL_NOT_ENABLED,	IVIDIGITIZER_ERRMSG_CHANNEL_NOT_ENABLED},\
{IVIDIGITIZER_ERROR_MAX_TIME_EXCEEDED,		IVIDIGITIZER_ERRMSG_MAX_TIME_EXCEEDED},\
{IVIDIGITIZER_ERROR_ARM_NOT_SOFTWARE,		IVIDIGITIZER_ERRMSG_ARM_NOT_SOFTWARE},\
{IVIDIGITIZER_ERROR_INCOMPATIBLE_FETCH,		IVIDIGITIZER_ERRMSG_INCOMPATIBLE_FETCH}

/****************************************************************************
*---------------------------- End Include File ----------------------------*
****************************************************************************/
#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif /* IVIDIGITIZER_HEADER */
