/****************************************************************************
 *                              IVI - UPCONVERTER                               
 *---------------------------------------------------------------------------
 *    Copyright (c) 2009-2020 National Instruments.  All Rights Reserved.        
 *---------------------------------------------------------------------------
 *                                                                          
 * Title:       iviupconverter_ni.h                                                    
 * Purpose:     IviUpconverter Class declarations for the Base and Extended  
 *              IviUpconverter Capabilities.                                        
 ****************************************************************************/

#ifndef IVIUPCONVERTER_HEADER
#define IVIUPCONVERTER_HEADER

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

#define IVIUPCONVERTER_MAJOR_VERSION		          (4L)
#define IVIUPCONVERTER_MINOR_VERSION	              (0L)

#define IVIUPCONVERTER_CLASS_SPEC_MAJOR_VERSION	      (2L)
#define IVIUPCONVERTER_CLASS_SPEC_MINOR_VERSION	      (0L)

#define IVIUPCONVERTER_DRIVER_VENDOR	              "National Instruments"
#ifdef	_IVI_mswin64_
#define IVIUPCONVERTER_DRIVER_DESCRIPTION			  "IviUpconverter Class Driver [Compiled for 64-bit.]"
#else
#define IVIUPCONVERTER_DRIVER_DESCRIPTION	          "IviUpconverter Class Driver"
#endif

/****************************************************************************
 *------------------------------ Useful Macros -----------------------------*
 ****************************************************************************/

  
/****************************************************************************
 *---------------- IviUpconverter Class Attribute Defines ------------------*
 ****************************************************************************/

    /*- IVI Inherent Attributes -*/

        /*- User Options -*/
#define IVIUPCONVERTER_ATTR_CACHE	                    IVI_ATTR_CACHE                       /* ViBoolean */
#define IVIUPCONVERTER_ATTR_RANGE_CHECK	                IVI_ATTR_RANGE_CHECK                 /* ViBoolean */
#define IVIUPCONVERTER_ATTR_QUERY_INSTRUMENT_STATUS		IVI_ATTR_QUERY_INSTRUMENT_STATUS     /* ViBoolean */
#define IVIUPCONVERTER_ATTR_RECORD_COERCIONS			IVI_ATTR_RECORD_COERCIONS            /* ViBoolean */
#define IVIUPCONVERTER_ATTR_SIMULATE					IVI_ATTR_SIMULATE                    /* ViBoolean */
#define IVIUPCONVERTER_ATTR_INTERCHANGE_CHECK			IVI_ATTR_INTERCHANGE_CHECK           /* ViBoolean */
#define IVIUPCONVERTER_ATTR_SPY							IVI_ATTR_SPY                         /* ViBoolean */
#define IVIUPCONVERTER_ATTR_USE_SPECIFIC_SIMULATION		IVI_ATTR_USE_SPECIFIC_SIMULATION     /* ViBoolean */

        /*- Instrument Capabilities -*/
#define IVIUPCONVERTER_ATTR_GROUP_CAPABILITIES			IVI_ATTR_GROUP_CAPABILITIES          /* ViString, read-only */
#define IVIUPCONVERTER_ATTR_FUNCTION_CAPABILITIES		IVI_ATTR_FUNCTION_CAPABILITIES       /* ViString, read-only */

        /*- Class Driver Information -*/    
#define IVIUPCONVERTER_ATTR_CLASS_DRIVER_PREFIX						  IVI_ATTR_CLASS_DRIVER_PREFIX         			  /* ViString, read-only */
#define IVIUPCONVERTER_ATTR_CLASS_DRIVER_VENDOR		                  IVI_ATTR_CLASS_DRIVER_VENDOR         			  /* ViString, read-only */
#define IVIUPCONVERTER_ATTR_CLASS_DRIVER_DESCRIPTION	              IVI_ATTR_CLASS_DRIVER_DESCRIPTION    			  /* ViString, read-only */
#define IVIUPCONVERTER_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION	  IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVIUPCONVERTER_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION	  IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION  /* ViInt32,  read-only */

        /*- Specific Driver Information -*/    
#define IVIUPCONVERTER_ATTR_SPECIFIC_DRIVER_PREFIX	                      IVI_ATTR_SPECIFIC_DRIVER_PREFIX      				 /* ViString, read-only */
#define IVIUPCONVERTER_ATTR_SPECIFIC_DRIVER_LOCATOR		                  IVI_ATTR_SPECIFIC_DRIVER_LOCATOR     				 /* ViString, read-only */
#define IVIUPCONVERTER_ATTR_IO_RESOURCE_DESCRIPTOR	                      IVI_ATTR_IO_RESOURCE_DESCRIPTOR      				 /* ViString, read-only */
#define IVIUPCONVERTER_ATTR_LOGICAL_NAME	                              IVI_ATTR_LOGICAL_NAME                				 /* ViString, read-only */
#define IVIUPCONVERTER_ATTR_SPECIFIC_DRIVER_VENDOR	                      IVI_ATTR_SPECIFIC_DRIVER_VENDOR      				 /* ViString, read-only */
#define IVIUPCONVERTER_ATTR_SPECIFIC_DRIVER_DESCRIPTION		              IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION 				 /* ViString, read-only */
#define IVIUPCONVERTER_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION	  IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVIUPCONVERTER_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION	  IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION  /* ViInt32,  read-only */

        /*- Instrument Information -*/    
#define IVIUPCONVERTER_ATTR_INSTRUMENT_FIRMWARE_REVISION	   IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION /* ViString, read-only */
#define IVIUPCONVERTER_ATTR_INSTRUMENT_MANUFACTURER		       IVI_ATTR_INSTRUMENT_MANUFACTURER      /* ViString, read-only */
#define IVIUPCONVERTER_ATTR_INSTRUMENT_MODEL	               IVI_ATTR_INSTRUMENT_MODEL             /* ViString, read-only */
#define IVIUPCONVERTER_ATTR_SUPPORTED_INSTRUMENT_MODELS		   IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS	 /* ViString, read-only */

        /*- Version Information -*/
#define IVIUPCONVERTER_ATTR_CLASS_DRIVER_REVISION		       IVI_ATTR_CLASS_DRIVER_REVISION        /* ViString, read-only */

#define IVIUPCONVERTER_ATTR_SPECIFIC_DRIVER_REVISION	       IVI_ATTR_SPECIFIC_DRIVER_REVISION     /* ViString, read-only */

        /*- Driver Setup Information -*/
#define IVIUPCONVERTER_ATTR_DRIVER_SETUP		         	   IVI_ATTR_DRIVER_SETUP                 /* ViString */

    /*- IviUpconverter Fundamental Attributes -*/
#define IVIUPCONVERTER_ATTR_ACTIVE_IF_INPUT                  			(IVI_CLASS_PUBLIC_ATTR_BASE + 0L)    /* ViString */
#define IVIUPCONVERTER_ATTR_ACTIVE_RF_OUTPUT				            (IVI_CLASS_PUBLIC_ATTR_BASE + 1L)    /* ViString */
#define IVIUPCONVERTER_ATTR_ALC_ENABLED									(IVI_CLASS_PUBLIC_ATTR_BASE + 2L)	 /* ViBoolean*/	
#define IVIUPCONVERTER_ATTR_AUTO_CORRECTIONS_ENABLED				    (IVI_CLASS_PUBLIC_ATTR_BASE + 3L)	 /* ViBoolean*/
#define IVIUPCONVERTER_ATTR_EXTERNAL_LO_ENABLED							(IVI_CLASS_PUBLIC_ATTR_BASE + 4L)	 /* ViBoolean*/
#define IVIUPCONVERTER_ATTR_EXTERNAL_LO_FREQUENCY						(IVI_CLASS_PUBLIC_ATTR_BASE + 5L)	 /* ViReal64 */	
#define IVIUPCONVERTER_ATTR_IF_INPUT_ATTENUATION						(IVI_CLASS_PUBLIC_ATTR_BASE + 6L)	 /* ViReal64 */ 
#define IVIUPCONVERTER_ATTR_IF_INPUT_COUNT								(IVI_CLASS_PUBLIC_ATTR_BASE + 7L)	 /* ViInt32,  read-only */
#define IVIUPCONVERTER_ATTR_IF_INPUT_COUPLING							(IVI_CLASS_PUBLIC_ATTR_BASE + 8L)	 /* ViInt32  */	 
#define IVIUPCONVERTER_ATTR_IF_INPUT_FREQUENCY							(IVI_CLASS_PUBLIC_ATTR_BASE + 9L)	 /* ViReal64, read-only */
#define IVIUPCONVERTER_ATTR_IS_READY									(IVI_CLASS_PUBLIC_ATTR_BASE + 10L)	 /* ViBoolean,read-only */
#define IVIUPCONVERTER_ATTR_RF_OUTPUT_BANDWIDTH							(IVI_CLASS_PUBLIC_ATTR_BASE + 11L)	 /* ViReal64 */
#define IVIUPCONVERTER_ATTR_RF_OUTPUT_COUNT								(IVI_CLASS_PUBLIC_ATTR_BASE + 12L)	 /* ViInt32,  read-only */
#define IVIUPCONVERTER_ATTR_RF_OUTPUT_ENABLED							(IVI_CLASS_PUBLIC_ATTR_BASE + 13L)	 /* ViBoolean*/
#define IVIUPCONVERTER_ATTR_RF_OUTPUT_FREQUENCY							(IVI_CLASS_PUBLIC_ATTR_BASE + 14L)	 /* ViReal64 */

    /*- IviUpconverterOutputGain Attributes -*/
#define IVIUPCONVERTER_ATTR_RF_OUTPUT_GAIN								(IVI_CLASS_PUBLIC_ATTR_BASE + 100L)	 /* ViReal64 */	

    /*- IviUpconverterOutputPowerLevel Attributes -*/
#define IVIUPCONVERTER_ATTR_RF_OUTPUT_LEVEL								(IVI_CLASS_PUBLIC_ATTR_BASE + 110L)	 /* ViReal64 */

	/*- IviUpconverterModulateAM Attributes -*/
#define IVIUPCONVERTER_ATTR_AM_DEPTH									(IVI_CLASS_PUBLIC_ATTR_BASE + 120L)	 /*	ViReal64 */
#define IVIUPCONVERTER_ATTR_AM_ENABLED									(IVI_CLASS_PUBLIC_ATTR_BASE + 121L)	 /* ViBoolean*/
#define IVIUPCONVERTER_ATTR_AM_EXTERNAL_COUPLING						(IVI_CLASS_PUBLIC_ATTR_BASE + 122L)	 /* ViInt32  */
#define IVIUPCONVERTER_ATTR_AM_NOMINAL_VOLTAGE							(IVI_CLASS_PUBLIC_ATTR_BASE + 123L)	 /* ViReal64, read-only */
#define IVIUPCONVERTER_ATTR_AM_SCALING									(IVI_CLASS_PUBLIC_ATTR_BASE + 124L)	 /* ViInt32  */
#define IVIUPCONVERTER_ATTR_AM_SOURCE									(IVI_CLASS_PUBLIC_ATTR_BASE + 125L)	 /* ViString */

    /*- IviUpconverterModulateFM Attributes -*/
#define IVIUPCONVERTER_ATTR_FM_DEVIATION								(IVI_CLASS_PUBLIC_ATTR_BASE + 130L)	 /* ViReal64 */
#define IVIUPCONVERTER_ATTR_FM_ENABLED									(IVI_CLASS_PUBLIC_ATTR_BASE + 131L)	 /* ViBoolean*/
#define IVIUPCONVERTER_ATTR_FM_EXTERNAL_COUPLING						(IVI_CLASS_PUBLIC_ATTR_BASE + 132L)	 /* ViInt32  */
#define IVIUPCONVERTER_ATTR_FM_NOMINAL_VOLTAGE							(IVI_CLASS_PUBLIC_ATTR_BASE + 133L)	 /* ViReal64, read-only */
#define IVIUPCONVERTER_ATTR_FM_SOURCE									(IVI_CLASS_PUBLIC_ATTR_BASE + 134L)	 /* ViString */

	/*- IviUpconverterModulatePM Attributes -*/
#define IVIUPCONVERTER_ATTR_PM_DEVIATION								(IVI_CLASS_PUBLIC_ATTR_BASE + 140L)	 /* ViReal64 */
#define IVIUPCONVERTER_ATTR_PM_ENABLED									(IVI_CLASS_PUBLIC_ATTR_BASE + 141L)	 /* ViBoolean*/
#define IVIUPCONVERTER_ATTR_PM_EXTERNAL_COUPLING						(IVI_CLASS_PUBLIC_ATTR_BASE + 142L)	 /* ViInt32  */
#define IVIUPCONVERTER_ATTR_PM_NOMINAL_VOLTAGE							(IVI_CLASS_PUBLIC_ATTR_BASE + 143L)	 /* ViReal64, read-only */
#define IVIUPCONVERTER_ATTR_PM_SOURCE									(IVI_CLASS_PUBLIC_ATTR_BASE + 144L)	 /* ViString */

    /*- IviUpconverterAnalogModulationSource Attributes -*/
#define IVIUPCONVERTER_ATTR_ANALOG_MODULATION_SOURCE_COUNT		        (IVI_CLASS_PUBLIC_ATTR_BASE + 150L)  /* ViInt32,  read-only */

	/*- IviUpconverterModulatePulse Attributes -*/
#define IVIUPCONVERTER_ATTR_PULSE_MODULATION_ENABLED					(IVI_CLASS_PUBLIC_ATTR_BASE + 160L)	 /* ViBoolean*/	
#define IVIUPCONVERTER_ATTR_PULSE_MODULATION_EXTERNAL_POLARITY			(IVI_CLASS_PUBLIC_ATTR_BASE + 161L)	 /* ViInt32  */

	/*- IviUpconverterBypass Attributes -*/
#define IVIUPCONVERTER_ATTR_BYPASS										(IVI_CLASS_PUBLIC_ATTR_BASE + 170L)	 /* ViBoolean*/

	/*- IviUpconverterOutputReadyTrigger Attributes -*/
#define IVIUPCONVERTER_ATTR_RF_OUTPUT_READY_TRIGGER						(IVI_CLASS_PUBLIC_ATTR_BASE + 180L)	 /* ViString */

	/*- IviUpconverterSweep Attributes -*/
#define IVIUPCONVERTER_ATTR_IS_SWEEPING									(IVI_CLASS_PUBLIC_ATTR_BASE + 200L)	 /* ViBoolean,read-only */
#define IVIUPCONVERTER_ATTR_SWEEP_MODE									(IVI_CLASS_PUBLIC_ATTR_BASE + 201L)	 /* ViInt32  */
#define IVIUPCONVERTER_ATTR_SWEEP_TRIGGER_SOURCE						(IVI_CLASS_PUBLIC_ATTR_BASE + 202L)  /* ViString */

    /*- IviUpconverterFrequencySweep Attributes -*/
#define IVIUPCONVERTER_ATTR_FREQUENCY_SWEEP_START						(IVI_CLASS_PUBLIC_ATTR_BASE + 210L)	 /* ViReal64 */
#define IVIUPCONVERTER_ATTR_FREQUENCY_SWEEP_STOP						(IVI_CLASS_PUBLIC_ATTR_BASE + 211L)	 /* ViReal64 */
#define IVIUPCONVERTER_ATTR_FREQUENCY_SWEEP_TIME						(IVI_CLASS_PUBLIC_ATTR_BASE + 212L)	 /* ViReal64 */

    /*- IviUpconverterPowerSweep Attributes -*/
#define IVIUPCONVERTER_ATTR_POWER_SWEEP_START							(IVI_CLASS_PUBLIC_ATTR_BASE + 220L)	 /* ViReal64 */
#define IVIUPCONVERTER_ATTR_POWER_SWEEP_STOP							(IVI_CLASS_PUBLIC_ATTR_BASE + 221L)  /* ViReal64 */
#define IVIUPCONVERTER_ATTR_POWER_SWEEP_TIME							(IVI_CLASS_PUBLIC_ATTR_BASE + 222L)	 /* ViReal64 */

    /*- IviUpconverterGainSweep Attributes -*/
#define IVIUPCONVERTER_ATTR_GAIN_SWEEP_START							(IVI_CLASS_PUBLIC_ATTR_BASE + 230L)	 /* ViReal64 */
#define IVIUPCONVERTER_ATTR_GAIN_SWEEP_STOP								(IVI_CLASS_PUBLIC_ATTR_BASE + 231L)  /* ViReal64 */
#define IVIUPCONVERTER_ATTR_GAIN_SWEEP_TIME								(IVI_CLASS_PUBLIC_ATTR_BASE + 232L)	 /* ViReal64 */

    /*- IviUpconverterFrequencyStep Attributes -*/
#define IVIUPCONVERTER_ATTR_FREQUENCY_STEP_DWELL						(IVI_CLASS_PUBLIC_ATTR_BASE + 240L)	 /* ViReal64 */
#define IVIUPCONVERTER_ATTR_FREQUENCY_STEP_SCALING						(IVI_CLASS_PUBLIC_ATTR_BASE + 241L)	 /* ViInt32  */
#define IVIUPCONVERTER_ATTR_FREQUENCY_STEP_SINGLE_STEP_ENABLED			(IVI_CLASS_PUBLIC_ATTR_BASE + 242L)	 /* ViBoolean*/
#define IVIUPCONVERTER_ATTR_FREQUENCY_STEP_SIZE							(IVI_CLASS_PUBLIC_ATTR_BASE + 243L)	 /* ViReal64 */
#define IVIUPCONVERTER_ATTR_FREQUENCY_STEP_START						(IVI_CLASS_PUBLIC_ATTR_BASE + 244L)	 /* ViReal64 */
#define IVIUPCONVERTER_ATTR_FREQUENCY_STEP_STOP							(IVI_CLASS_PUBLIC_ATTR_BASE + 245L)	 /* ViReal64 */

    /*- IviUpconverterPowerStep Attributes -*/
#define IVIUPCONVERTER_ATTR_POWER_STEP_DWELL							(IVI_CLASS_PUBLIC_ATTR_BASE + 250L)	 /* ViReal64 */
#define IVIUPCONVERTER_ATTR_POWER_STEP_SINGLE_STEP_ENABLED				(IVI_CLASS_PUBLIC_ATTR_BASE + 251L)	 /* ViBoolean*/
#define IVIUPCONVERTER_ATTR_POWER_STEP_SIZE								(IVI_CLASS_PUBLIC_ATTR_BASE + 252L)	 /* ViReal64 */
#define IVIUPCONVERTER_ATTR_POWER_STEP_START							(IVI_CLASS_PUBLIC_ATTR_BASE + 253L)	 /* ViReal64 */
#define IVIUPCONVERTER_ATTR_POWER_STEP_STOP								(IVI_CLASS_PUBLIC_ATTR_BASE + 254L)	 /* ViReal64 */

    /*- IviUpconverterGainStep Attributes -*/
#define IVIUPCONVERTER_ATTR_GAIN_STEP_DWELL								(IVI_CLASS_PUBLIC_ATTR_BASE + 260L)	 /* ViReal64 */
#define IVIUPCONVERTER_ATTR_GAIN_STEP_SINGLE_STEP_ENABLED				(IVI_CLASS_PUBLIC_ATTR_BASE + 261L)	 /* ViBoolean*/
#define IVIUPCONVERTER_ATTR_GAIN_STEP_SIZE								(IVI_CLASS_PUBLIC_ATTR_BASE + 262L)	 /* ViReal64 */
#define IVIUPCONVERTER_ATTR_GAIN_STEP_START								(IVI_CLASS_PUBLIC_ATTR_BASE + 263L)	 /* ViReal64 */
#define IVIUPCONVERTER_ATTR_GAIN_STEP_STOP								(IVI_CLASS_PUBLIC_ATTR_BASE + 264L)	 /* ViReal64 */

    /*- IviUpconverterList Attributes -*/
#define IVIUPCONVERTER_ATTR_LIST_DWELL									(IVI_CLASS_PUBLIC_ATTR_BASE + 270L)	 /* ViReal64 */
#define IVIUPCONVERTER_ATTR_LIST_SELECTED_NAME							(IVI_CLASS_PUBLIC_ATTR_BASE + 271L)  /* ViString */
#define IVIUPCONVERTER_ATTR_LIST_SINGLE_STEP_ENABLED					(IVI_CLASS_PUBLIC_ATTR_BASE + 272L)	 /* ViBoolean*/

    /*- IviUpconverterALC Attributes -*/
#define IVIUPCONVERTER_ATTR_ALC_BANDWIDTH								(IVI_CLASS_PUBLIC_ATTR_BASE + 300L)	 /* ViReal64 */
#define IVIUPCONVERTER_ATTR_ALC_SOURCE									(IVI_CLASS_PUBLIC_ATTR_BASE + 301L)	 /* ViInt32  */

	/*- IviUpconverterAttenuatorHold Attributes -*/
#define IVIUPCONVERTER_ATTR_ATTENUATOR_HOLD_ENABLED						(IVI_CLASS_PUBLIC_ATTR_BASE + 310L)	 /* ViBoolean*/

    /*- IviUpconverterReferenceOscillator Attributes -*/
#define IVIUPCONVERTER_ATTR_REFERENCE_OSCILLATOR_EXTERNAL_FREQUENCY		(IVI_CLASS_PUBLIC_ATTR_BASE + 320L)  /* ViReal64 */
#define IVIUPCONVERTER_ATTR_REFERENCE_OSCILLATOR_SOURCE		            (IVI_CLASS_PUBLIC_ATTR_BASE + 321L)  /* ViInt32  */
#define IVIUPCONVERTER_ATTR_REFERENCE_OSCILLATOR_OUTPUT_ENABLED			(IVI_CLASS_PUBLIC_ATTR_BASE + 322L)	 /* ViBoolean*/

	/*- IviUpconverterModulateIQ Attributes -*/
#define IVIUPCONVERTER_ATTR_IQ_ENABLED									(IVI_CLASS_PUBLIC_ATTR_BASE + 330L)	 /* ViBoolean*/
#define IVIUPCONVERTER_ATTR_IQ_NOMINAL_VOLTAGE							(IVI_CLASS_PUBLIC_ATTR_BASE + 331L)	 /* ViReal64, read-only */
#define IVIUPCONVERTER_ATTR_IQ_SWAP_ENABLED								(IVI_CLASS_PUBLIC_ATTR_BASE + 332L)	 /* ViBoolean*/

	/*- IviUpconverterIQImpairment Attributes -*/
#define IVIUPCONVERTER_ATTR_IQ_IMPAIRMENT_ENABLED						(IVI_CLASS_PUBLIC_ATTR_BASE + 340L)	 /* ViBoolean*/
#define IVIUPCONVERTER_ATTR_IQ_IMPAIRMENT_I_OFFSET						(IVI_CLASS_PUBLIC_ATTR_BASE + 341L)	 /* ViReal64 */
#define IVIUPCONVERTER_ATTR_IQ_IMPAIRMENT_Q_OFFSET						(IVI_CLASS_PUBLIC_ATTR_BASE + 342L)	 /* ViReal64 */
#define IVIUPCONVERTER_ATTR_IQ_IMPAIRMENT_RATIO							(IVI_CLASS_PUBLIC_ATTR_BASE + 343L)	 /* ViReal64 */
#define IVIUPCONVERTER_ATTR_IQ_IMPAIRMENT_SKEW							(IVI_CLASS_PUBLIC_ATTR_BASE + 344L)	 /* ViReal64 */

/****************************************************************************
 *--------------- IviUpconverter Class Attribute Value Defines -------------*
 ****************************************************************************/

    /*- Defined values for attribute IVIUPCONVERTER_ATTR_ALC_SOURCE -*/
#define IVIUPCONVERTER_VAL_ALC_SOURCE_INTERNAL									(0L)
#define IVIUPCONVERTER_VAL_ALC_SOURCE_EXTERNAL									(1L)

#define IVIUPCONVERTER_VAL_ALC_SOURCE_CLASS_EXT_BASE							(100L)
#define IVIUPCONVERTER_VAL_ALC_SOURCE_SPECIFIC_EXT_BASE							(1000L)

    /*- Defined values for attribute IVIUPCONVERTER_ATTR_AM_EXTERNAL_COUPLING -*/
#define IVIUPCONVERTER_VAL_AM_EXTERNAL_COUPLING_AC								(0L)
#define IVIUPCONVERTER_VAL_AM_EXTERNAL_COUPLING_DC								(1L)

#define IVIUPCONVERTER_VAL_AM_EXTERNAL_COUPLING_CLASS_EXT_BASE					(100L)
#define IVIUPCONVERTER_VAL_AM_EXTERNAL_COUPLING_SPECIFIC_EXT_BASE				(1000L)

    /*- Defined values for attribute IVIUPCONVERTER_ATTR_AM_SCALING -*/
#define IVIUPCONVERTER_VAL_AM_SCALING_LINEAR									(0L)
#define IVIUPCONVERTER_VAL_AM_SCALING_LOGARITHMIC								(1L)

#define IVIUPCONVERTER_VAL_AM_SCALING_CLASS_EXT_BASE							(100L)
#define IVIUPCONVERTER_VAL_AM_SCALING_SPECIFIC_EXT_BASE							(1000L)

    /*- Defined values for attribute IVIUPCONVERTER_ATTR_FM_EXTERNAL_COUPLING -*/
#define IVIUPCONVERTER_VAL_FM_EXTERNAL_COUPLING_AC								(0L)
#define IVIUPCONVERTER_VAL_FM_EXTERNAL_COUPLING_DC								(1L)

#define IVIUPCONVERTER_VAL_FM_EXTERNAL_COUPLING_CLASS_EXT_BASE					(100L)
#define IVIUPCONVERTER_VAL_FM_EXTERNAL_COUPLING_SPECIFIC_EXT_BASE				(1000L)

    /*- Defined values for attribute IVIUPCONVERTER_ATTR_FREQUENCY_STEP_SCALING -*/
#define IVIUPCONVERTER_VAL_FREQUENCY_STEP_SCALING_LINEAR						(0L)
#define IVIUPCONVERTER_VAL_FREQUENCY_STEP_SCALING_LOGARITHMIC					(1L)

#define IVIUPCONVERTER_VAL_FREQUENCY_STEP_SCALING_CLASS_EXT_BASE				(100L)
#define IVIUPCONVERTER_VAL_FREQUENCY_STEP_SCALING_SPECIFIC_EXT_BASE				(1000L)

    /*- Defined values for attribute IVIUPCONVERTER_ATTR_PM_EXTERNAL_COUPLING -*/
#define IVIUPCONVERTER_VAL_PM_EXTERNAL_COUPLING_AC								(0L)
#define IVIUPCONVERTER_VAL_PM_EXTERNAL_COUPLING_DC								(1L)

#define IVIUPCONVERTER_VAL_PM_EXTERNAL_COUPLING_CLASS_EXT_BASE					(100L)
#define IVIUPCONVERTER_VAL_PM_EXTERNAL_COUPLING_SPECIFIC_EXT_BASE				(1000L)

    /*- Defined values for attribute IVIUPCONVERTER_ATTR_PULSE_MODULATION_EXTERNAL_POLARITY -*/
#define IVIUPCONVERTER_VAL_PULSE_MODULATION_EXTERNAL_POLARITY_NORMAL			(0L)
#define IVIUPCONVERTER_VAL_PULSE_MODULATION_EXTERNAL_POLARITY_INVERSE			(1L)

#define IVIUPCONVERTER_VAL_PULSE_MODULATION_EXTERNAL_POLARITY_CLASS_EXT_BASE	(100L)
#define IVIUPCONVERTER_VAL_PULSE_MODULATION_EXTERNAL_POLARITY_SPECIFIC_EXT_BASE	(1000L)

    /*- Defined values for attribute IVIUPCONVERTER_ATTR_REFERENCE_OSCILLATOR_SOURCE -*/
#define IVIUPCONVERTER_VAL_REFERENCE_OSCILLATOR_SOURCE_INTERNAL					(0L)
#define IVIUPCONVERTER_VAL_REFERENCE_OSCILLATOR_SOURCE_EXTERNAL					(1L)

#define IVIUPCONVERTER_VAL_REFERENCE_OSCILLATOR_SOURCE_CLASS_EXT_BASE			(100L)
#define IVIUPCONVERTER_VAL_REFERENCE_OSCILLATOR_SOURCE_SPECIFIC_EXT_BASE		(1000L)

    /*- Defined values for attribute IVIUPCONVERTER_ATTR_SWEEP_MODE -*/
#define IVIUPCONVERTER_VAL_SWEEP_MODE_NONE										(0L)
#define IVIUPCONVERTER_VAL_SWEEP_MODE_FREQUENCY_SWEEP							(1L)
#define IVIUPCONVERTER_VAL_SWEEP_MODE_POWER_SWEEP								(2L)
#define IVIUPCONVERTER_VAL_SWEEP_MODE_GAIN_SWEEP								(3L)
#define IVIUPCONVERTER_VAL_SWEEP_MODE_FREQUENCY_STEP							(4L)
#define IVIUPCONVERTER_VAL_SWEEP_MODE_POWER_STEP								(5L)
#define IVIUPCONVERTER_VAL_SWEEP_MODE_GAIN_STEP									(6L)
#define IVIUPCONVERTER_VAL_SWEEP_MODE_LIST										(7L)

#define IVIUPCONVERTER_VAL_SWEEP_MODE_CLASS_EXT_BASE							(100L)
#define IVIUPCONVERTER_VAL_SWEEP_MODE_SPECIFIC_EXT_BASE							(1000L)

    /*- Defined values for attributes IVIUPCONVERTER_ATTR_RF_OUTPUT_READY_TRIGGER and IVIUPCONVERTER_ATTR_SWEEP_TRIGGER_SOURCE -*/
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_NONE									""
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_IMMEDIATE								"Immediate"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_EXTERNAL								"External"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_INTERNAL								"Internal"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_SOFTWARE								"Software"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_LAN0									"LAN0"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_LAN1									"LAN1"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_LAN2									"LAN2"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_LAN3									"LAN3"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_LAN4									"LAN4"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_LAN5									"LAN5"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_LAN6									"LAN6"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_LAN7									"LAN7"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_LXI0									"LXI0"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_LXI1									"LXI1"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_LXI2									"LXI2"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_LXI3									"LXI3"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_LXI4									"LXI4"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_LXI5									"LXI5"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_LXI6									"LXI6"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_LXI7									"LXI7"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_TTL0									"TTL0"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_TTL1									"TTL1"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_TTL2									"TTL2"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_TTL3									"TTL3"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_TTL4									"TTL4"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_TTL5									"TTL5"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_TTL6									"TTL6"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_TTL7									"TTL7"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_PXI_STAR								"PXI_STAR"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_PXI_TRIG0								"PXI_TRIG0"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_PXI_TRIG1								"PXI_TRIG1"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_PXI_TRIG2								"PXI_TRIG2"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_PXI_TRIG3								"PXI_TRIG3"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_PXI_TRIG4								"PXI_TRIG4"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_PXI_TRIG5								"PXI_TRIG5"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_PXI_TRIG6								"PXI_TRIG6"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_PXI_TRIG7								"PXI_TRIG7"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_PXIE_DSTARA						    "PXIe_DSTARA"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_PXIE_DSTARB						    "PXIe_DSTARB"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_PXIE_DSTARC						    "PXIe_DSTARC"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_RTSI0									"RTSI0"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_RTSI1									"RTSI1"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_RTSI2									"RTSI2"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_RTSI3									"RTSI3"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_RTSI4									"RTSI4"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_RTSI5									"RTSI5"
#define IVIUPCONVERTER_VAL_TRIGGER_SOURCE_RTSI6									"RTSI6"

    /*- Defined values for attribute IVIUPCONVERTER_ATTR_IF_INPUT_COUPLING -*/
#define IVIUPCONVERTER_VAL_IF_INPUT_COUPLING_AC			                       (0L)
#define IVIUPCONVERTER_VAL_IF_INPUT_COUPLING_DC	                       		   (1L)

#define IVIUPCONVERTER_VAL_INPUT_COUPLING_CLASS_EXT_BASE					   (100L)
#define IVIUPCONVERTER_VAL_INPUT_COUPLING_SPECIFIC_EXT_BASE					   (1000L)

#define IVIUPCONVERTER_VAL_CALIBRATION_COMPLETE		   						   (0L)
#define IVIUPCONVERTER_VAL_CALIBRATION_IN_PROGRESS							   (1L)
#define IVIUPCONVERTER_VAL_CALIBRATION_STATUS_UNKNOWN						   (2L)
#define IVIUPCONVERTER_VAL_CALIBRATION_FAILED	         					   (3L)

#define IVIUPCONVERTER_VAL_MAX_TIME_IMMEDIATE								   (IVI_VAL_MAX_TIME_IMMEDIATE)
#define IVIUPCONVERTER_VAL_MAX_TIME_INFINITE								   (IVI_VAL_MAX_TIME_INFINITE)

/****************************************************************************
 *------- IviUpconverter Class Instrument Driver Function Declarations -----*
 ****************************************************************************/
    /*- Required VXIplug&play Functions -*/
ViStatus _VI_FUNC IviUpconverter_init (ViRsrc logicalName, 
                               		   ViBoolean idQuery, 
                               		   ViBoolean resetDevice, 
                               		   ViSession *vi);

ViStatus _VI_FUNC IviUpconverter_close (ViSession vi);

ViStatus _VI_FUNC IviUpconverter_reset (ViSession vi);

ViStatus _VI_FUNC IviUpconverter_self_test (ViSession vi, 
                                    		ViInt16 *selfTestResult, 
                                    		ViChar selfTestMessage[]);

ViStatus _VI_FUNC IviUpconverter_error_query (ViSession vi, 
                                      		  ViInt32 *errorCode, 
                                      		  ViChar errorMessage[]);

ViStatus _VI_FUNC IviUpconverter_error_message (ViSession vi, 
                                        		ViStatus statusCode, 
                                        		ViChar message[]);

ViStatus _VI_FUNC IviUpconverter_revision_query (ViSession vi, 
                                         		 ViChar driverRev[], 
                                         		 ViChar instrRev[]);

    /*- Utility Functions -*/
ViStatus _VI_FUNC IviUpconverter_InvalidateAllAttributes (ViSession vi);

ViStatus _VI_FUNC IviUpconverter_ResetWithDefaults (ViSession vi);

ViStatus _VI_FUNC IviUpconverter_Disable (ViSession vi);

    /*- Required IVI Functions -*/
ViStatus _VI_FUNC IviUpconverter_InitWithOptions (ViRsrc logicalName, 
                                          		  ViBoolean IDQuery,
                                          		  ViBoolean resetDevice, 
                                          		  ViConstString optionString, 
                                          		  ViSession *vi);

    /*- Set, Get, and Check Attribute Functions -*/
ViStatus _VI_FUNC IviUpconverter_GetAttributeViInt32 (ViSession vi, 
                                              		  ViConstString channelName,
                                              		  ViAttr attributeId,
                                              		  ViInt32 *value);

ViStatus _VI_FUNC IviUpconverter_SetAttributeViInt32 (ViSession vi, 
                                              		  ViConstString channelName,
                                              		  ViAttr attributeId,
                                              		  ViInt32 value);

ViStatus _VI_FUNC IviUpconverter_CheckAttributeViInt32 (ViSession vi, 
                                                		ViConstString channelName,
                                                		ViAttr attributeId,
                                                		ViInt32 value);

#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus _VI_FUNC IviUpconverter_GetAttributeViInt64 (ViSession vi, 
                                              		  ViConstString channelName,
                                              		  ViAttr attributeId,
                                              		  ViInt64 *value);

ViStatus _VI_FUNC IviUpconverter_SetAttributeViInt64 (ViSession vi, 
                                              		  ViConstString channelName,
                                              		  ViAttr attributeId,
                                              		  ViInt64 value);

ViStatus _VI_FUNC IviUpconverter_CheckAttributeViInt64 (ViSession vi, 
                                                		ViConstString channelName,
                                                		ViAttr attributeId,
                                                		ViInt64 value);
#endif

ViStatus _VI_FUNC IviUpconverter_GetAttributeViReal64 (ViSession vi, 
                                               		   ViConstString channelName, 
                                               		   ViAttr attributeId, 
                                               		   ViReal64 *value);

ViStatus _VI_FUNC IviUpconverter_SetAttributeViReal64 (ViSession vi, 
                                               		   ViConstString channelName, 
                                               		   ViAttr attributeId, 
                                               		   ViReal64 value);

ViStatus _VI_FUNC IviUpconverter_CheckAttributeViReal64 (ViSession vi, 
                                                 		 ViConstString channelName, 
                                                 		 ViAttr attributeId, 
                                                 		 ViReal64 value);

ViStatus _VI_FUNC IviUpconverter_GetAttributeViString (ViSession vi, 
                                               		   ViConstString channelName, 
                                               		   ViAttr attributeId, 
                                               		   ViInt32 bufferSize, 
                                               		   ViChar value[]);

ViStatus _VI_FUNC IviUpconverter_SetAttributeViString (ViSession vi, 
                                               		   ViConstString channelName, 
                                               		   ViAttr attributeId, 
                                               		   ViConstString value);

ViStatus _VI_FUNC IviUpconverter_CheckAttributeViString (ViSession vi, 
                                                 		 ViConstString channelName, 
                                                 		 ViAttr attributeId, 
                                                 		 ViConstString value); 

ViStatus _VI_FUNC IviUpconverter_GetAttributeViBoolean (ViSession vi, 
                                                		ViConstString channelName, 
                                                		ViAttr attributeId, 
                                                		ViBoolean *value);

ViStatus _VI_FUNC IviUpconverter_SetAttributeViBoolean (ViSession vi, 
                                                		ViConstString channelName, 
                                                		ViAttr attributeId, 
                                                		ViBoolean value);

ViStatus _VI_FUNC IviUpconverter_CheckAttributeViBoolean (ViSession vi, 
                                                  		  ViConstString channelName, 
                                                  		  ViAttr attributeId, 
                                                  		  ViBoolean value);

ViStatus _VI_FUNC IviUpconverter_GetAttributeViSession (ViSession vi, 
                                                		ViConstString channelName, 
                                                		ViAttr attributeId, 
                                                		ViSession *value);

ViStatus _VI_FUNC IviUpconverter_SetAttributeViSession (ViSession vi, 
                                                		ViConstString channelName, 
                                                		ViAttr attributeId, 
                                                		ViSession value);

ViStatus _VI_FUNC IviUpconverter_CheckAttributeViSession (ViSession vi, 
                                                  		  ViConstString channelName, 
                                                  		  ViAttr attributeId, 
                                                  		  ViSession value);

    /*- Lock and Unlock Functions -*/
ViStatus _VI_FUNC IviUpconverter_LockSession (ViSession vi, 
                                      		  ViBoolean *callerHasLock);

ViStatus _VI_FUNC IviUpconverter_UnlockSession (ViSession vi, 
                                        		ViBoolean *callerHasLock);

    /*- Error Information Functions -*/
ViStatus _VI_FUNC IviUpconverter_GetError (ViSession vi, 
                                   		   ViStatus *errorCode, 
                                   		   ViInt32 bufferSize, 
                                   		   ViChar description[]);

ViStatus _VI_FUNC IviUpconverter_ClearError (ViSession vi);

    /*- Interchangeability Checking Functions -*/
ViStatus _VI_FUNC IviUpconverter_GetNextInterchangeWarning (ViSession vi, 
                                                    		ViInt32 bufferSize,
                                                    		ViChar warning[]);

ViStatus _VI_FUNC IviUpconverter_ClearInterchangeWarnings (ViSession vi);
ViStatus _VI_FUNC IviUpconverter_ResetInterchangeCheck (ViSession vi);

ViStatus _VI_FUNC IviUpconverter_GetNextCoercionRecord (ViSession vi,
                                                		ViInt32 bufferSize, 
                                                		ViChar record[]);

ViStatus _VI_FUNC IviUpconverter_GetSpecificDriverCHandle (ViSession vi,
                                                   		   ViSession* specificDriverCHandle);

    /*- IviUpconverterBase Functions -*/
ViStatus _VI_FUNC   IviUpconverter_ConfigureIFInputAttenuation (ViSession vi, 
                                                 			    ViReal64 attenuation);

ViStatus _VI_FUNC   IviUpconverter_ConfigureRFOutputEnabled (ViSession vi, 
															 ViBoolean enabled);

ViStatus _VI_FUNC   IviUpconverter_ConfigureRFOutputFrequency (ViSession vi, 
															   ViReal64 frequency);

ViStatus _VI_FUNC   IviUpconverter_GetIFInputName (ViSession vi, 
												   ViInt32 index,
												   ViInt32 nameBufferSize,
												   ViChar name[]);

ViStatus _VI_FUNC   IviUpconverter_GetRFOutputName (ViSession vi, 
													ViInt32 index,
													ViInt32 nameBufferSize,
													ViChar name[]);

ViStatus _VI_FUNC   IviUpconverter_SetActiveIFInput (ViSession vi, 
													 ViConstString name);

ViStatus _VI_FUNC	IviUpconverter_SetActiveRFOutput (ViSession vi, 
													  ViConstString name);

ViStatus _VI_FUNC	IviUpconverter_WaitUntilReady (ViSession vi,
												   ViInt32 maxTimeMilliseconds);

    /*- IviUpconverterOutputGain Functions -*/
ViStatus _VI_FUNC   IviUpconverter_ConfigureRFOutputGain (ViSession vi, 
														  ViReal64 gain);
    
    /*- IviUpconverterOutputPowerLevel Functions -*/
ViStatus _VI_FUNC   IviUpconverter_ConfigureRFOutputLevel (ViSession vi, 
														   ViReal64 level);

    /*- IviUpconverterModulateAM Functions -*/
ViStatus _VI_FUNC   IviUpconverter_ConfigureAM (ViSession vi, 
												ViConstString source,
												ViInt32 scaling,
												ViReal64 depth);

ViStatus _VI_FUNC	IviUpconverter_ConfigureAMEnabled (ViSession vi,
													   ViBoolean enabled);

ViStatus _VI_FUNC	IviUpconverter_ConfigureAMExternalCoupling (ViSession vi,
																ViInt32 coupling);

    /*- IviUpconverterModulateFM Functions -*/
ViStatus _VI_FUNC   IviUpconverter_ConfigureFM (ViSession vi, 
												ViConstString source,
												ViReal64 deviation);

ViStatus _VI_FUNC   IviUpconverter_ConfigureFMEnabled (ViSession vi, 
													   ViBoolean enabled);

ViStatus _VI_FUNC	IviUpconverter_ConfigureFMExternalCoupling (ViSession vi,
																ViInt32 coupling);

	/*- IviUpconverterModulatePM Functions -*/
ViStatus _VI_FUNC	IviUpconverter_ConfigurePM (ViSession vi,
												ViConstString source,
												ViReal64 deviation);

ViStatus _VI_FUNC   IviUpconverter_ConfigurePMEnabled (ViSession vi, 
													   ViBoolean enabled);

ViStatus _VI_FUNC	IviUpconverter_ConfigurePMExternalCoupling (ViSession vi,
																ViInt32 coupling);

    /*- IviUpconverterAnalogModulationSource Functions -*/
ViStatus _VI_FUNC   IviUpconverter_GetAnalogModulationSourceName (ViSession vi,
																  ViInt32 index,
																  ViInt32 nameBufferSize,
																  ViChar name[]);

	/*- IviUpconverterModulatePulse Functions -*/
ViStatus _VI_FUNC	IviUpconverter_ConfigurePulseModulationEnabled (ViSession vi,
																	ViBoolean enabled);

ViStatus _VI_FUNC	IviUpconverter_ConfigurePulseModulationExternalPolarity (ViSession vi,
																			 ViInt32 polarity);

	/*- IviUpconverterBypass Functions -*/
ViStatus _VI_FUNC	IviUpconverter_ConfigureBypass (ViSession vi,
													ViBoolean bypass);

    /*- IviUpconverterOutputReadyTrigger Functions -*/
ViStatus _VI_FUNC   IviUpconverter_ConfigureRFOutputReadyTrigger (ViSession vi, 
																  ViConstString outputTrigger);

    /*- IviUpconverterSweep Functions -*/
ViStatus _VI_FUNC   IviUpconverter_ConfigureSweep (ViSession vi,
												   ViInt32 mode,
												   ViConstString triggerSource);

    /*- IviUpconverterFrequencySweep Functions -*/
ViStatus _VI_FUNC   IviUpconverter_ConfigureFrequencySweepCenterSpan (ViSession vi, 
																	  ViReal64 center,
																	  ViReal64 span);

ViStatus _VI_FUNC   IviUpconverter_ConfigureFrequencySweepStartStop (ViSession vi, 
																	 ViReal64 start,
																	 ViReal64 stop);

ViStatus _VI_FUNC   IviUpconverter_ConfigureFrequencySweepTime (ViSession vi, 
																ViReal64 sweepTime);

    /*- IviUpconverterPowerSweep Functions -*/
ViStatus _VI_FUNC   IviUpconverter_ConfigurePowerSweepStartStop (ViSession vi, 
																 ViReal64 start,
																 ViReal64 stop);

ViStatus _VI_FUNC   IviUpconverter_ConfigurePowerSweepTime (ViSession vi, 
															ViReal64 sweepTime);

    /*- IviUpconverterGainSweep Functions -*/
ViStatus _VI_FUNC   IviUpconverter_ConfigureGainSweepStartStop (ViSession vi, 
																ViReal64 start,
																ViReal64 stop);

ViStatus _VI_FUNC   IviUpconverter_ConfigureGainSweepTime (ViSession vi, 
														   ViReal64 sweepTime);

	/*- IviUpconverterFrequencyStep Functions -*/
ViStatus _VI_FUNC   IviUpconverter_ConfigureFrequencyStepDwell (ViSession vi, 
																ViBoolean singleStepEnabled, 
																ViReal64 dwell);

ViStatus _VI_FUNC   IviUpconverter_ConfigureFrequencyStepStartStop (ViSession vi, 
																	ViReal64 start,
																	ViReal64 stop,
																	ViInt32 scaling,
																	ViReal64 stepSize);

ViStatus _VI_FUNC   IviUpconverter_ResetFrequencyStep (ViSession vi);

	/*- IviUpconverterPowerStep Functions -*/
ViStatus _VI_FUNC   IviUpconverter_ConfigurePowerStepDwell (ViSession vi, 
															ViBoolean singleStepEnabled, 
															ViReal64 dwell);

ViStatus _VI_FUNC   IviUpconverter_ConfigurePowerStepStartStop (ViSession vi, 
																ViReal64 start,
																ViReal64 stop,
																ViReal64 stepSize);

ViStatus _VI_FUNC   IviUpconverter_ResetPowerStep (ViSession vi);

	/*- IviUpconverterGainStep Functions -*/
ViStatus _VI_FUNC   IviUpconverter_ConfigureGainStepDwell (ViSession vi, 
														   ViBoolean singleStepEnabled, 
														   ViReal64 dwell);

ViStatus _VI_FUNC   IviUpconverter_ConfigureGainStepStartStop (ViSession vi, 
															   ViReal64 start,
															   ViReal64 stop,
															   ViReal64 stepSize);

ViStatus _VI_FUNC   IviUpconverter_ResetGainStep (ViSession vi);

	/*- IviUpconverterList Functions -*/
ViStatus _VI_FUNC   IviUpconverter_ClearAllLists (ViSession vi);

ViStatus _VI_FUNC   IviUpconverter_ConfigureListDwell (ViSession vi,
													   ViBoolean singleStepEnabled,
													   ViReal64 dwell);

ViStatus _VI_FUNC   IviUpconverter_CreateFrequencyList (ViSession vi,
													    ViConstString name,
														ViInt32 frequencyBufferSize,
														ViReal64 frequency[]);

ViStatus _VI_FUNC   IviUpconverter_CreateFrequencyPowerList (ViSession vi,
															 ViConstString name,
															 ViInt32 bufferSize,
															 ViReal64 frequency[],
															 ViReal64 power[]);

ViStatus _VI_FUNC   IviUpconverter_CreateFrequencyGainList (ViSession vi,
															ViConstString name,
															ViInt32 bufferSize,
															ViReal64 frequency[],
															ViReal64 gain[]);

ViStatus _VI_FUNC   IviUpconverter_CreatePowerList (ViSession vi,
													ViConstString name,
													ViInt32 powerBufferSize,
													ViReal64 power[]);

ViStatus _VI_FUNC   IviUpconverter_CreateGainList (ViSession vi,
												   ViConstString name,
												   ViInt32 gainBufferSize,
												   ViReal64 gain[]);

ViStatus _VI_FUNC   IviUpconverter_ResetList (ViSession vi);

	/*- IviUpconverterALC Functions -*/
ViStatus _VI_FUNC   IviUpconverter_ConfigureALC (ViSession vi,
												 ViInt32 source,
												 ViReal64 bandwidth);

    /*- IviUpconverterCalibration Functions -*/
ViStatus _VI_FUNC   IviUpconverter_Calibrate (ViSession vi);

ViStatus _VI_FUNC	IviUpconverter_IsCalibrationComplete (ViSession vi,
														  ViInt32* status);

	/*- IviUpconverterAttenuatorHold Functions -*/
ViStatus _VI_FUNC	IviUpconverter_ConfigureAttenuatorHoldEnabled (ViSession vi,
																   ViBoolean enabled);

	/*- IviUpconverterReferenceOscillator Functions -*/
ViStatus _VI_FUNC   IviUpconverter_ConfigureReferenceOscillator (ViSession vi, 
																 ViInt32 source,
																 ViReal64 frequency);

ViStatus _VI_FUNC	IviUpconverter_ConfigureReferenceOscillatorOutputEnabled (ViSession vi,
																			  ViBoolean enabled);

	/*- IviUpconverterSoftwareTrigger Functions -*/
ViStatus _VI_FUNC	IviUpconverter_SendSoftwareTrigger (ViSession vi);

	/*- IviUpconverterModulateIQ Functions -*/
ViStatus _VI_FUNC	IviUpconverter_CalibrateIQ (ViSession vi);

ViStatus _VI_FUNC	IviUpconverter_ConfigureIQEnabled (ViSession vi,
													   ViBoolean enabled);

	/*- IviUpconverterIQImpairment Functions -*/
ViStatus _VI_FUNC	IviUpconverter_ConfigureIQImpairment (ViSession vi,
														  ViReal64 IOffset,
														  ViReal64 QOffset,
														  ViReal64 ratio,
														  ViReal64 skew);

ViStatus _VI_FUNC	IviUpconverter_ConfigureIQImpairmentEnabled (ViSession vi,
																 ViBoolean enabled);
                                                
/****************************************************************************
 *------------- IviUpconverter Class Error And Completion Codes ------------*
 ****************************************************************************/
#define IVIUPCONVERTER_ERROR_LIST_UNKNOWN				(IVI_CLASS_ERROR_BASE + 2L) 
#define IVIUPCONVERTER_ERROR_MAX_TIME_EXCEEDED	      	(IVI_CLASS_ERROR_BASE + 1L)
#define IVIUPCONVERTER_ERROR_TRIGGER_NOT_SOFTWARE   	(IVI_CROSS_CLASS_ERROR_BASE + 1L)

#define IVIUPCONVERTER_ERRMSG_LIST_UNKNOWN				"The selected list is not defined."
#define IVIUPCONVERTER_ERRMSG_MAX_TIME_EXCEEDED     	"Maximum time exceeded before the operation completed."	
#define IVIUPCONVERTER_ERRMSG_TRIGGER_NOT_SOFTWARE  	"Trigger source is not set to software trigger."

#define IVIUPCONVERTER_ERROR_CODES_AND_MSGS \
        {IVIUPCONVERTER_ERROR_LIST_UNKNOWN,				IVIUPCONVERTER_ERRMSG_LIST_UNKNOWN}, \
        {IVIUPCONVERTER_ERROR_MAX_TIME_EXCEEDED,    	IVIUPCONVERTER_ERRMSG_MAX_TIME_EXCEEDED	  }, \
        {IVIUPCONVERTER_ERROR_TRIGGER_NOT_SOFTWARE, 	IVIUPCONVERTER_ERRMSG_TRIGGER_NOT_SOFTWARE  } 

/****************************************************************************
 *---------------------------- End Include File ----------------------------*
 ****************************************************************************/
#if defined(__cplusplus) || defined(__cplusplus__)
}                                                    
#endif

#endif /* IVIUPCONVERTER_HEADER */

