/****************************************************************************
 *                              IVI - DOWNCONVERTER                               
 *---------------------------------------------------------------------------
 *    Copyright (c) 2009-2020 National Instruments.  All Rights Reserved.        
 *---------------------------------------------------------------------------
 *                                                                          
 * Title:       ividownconverter_ni.h                                                    
 * Purpose:     IviDownconverter Class declarations for the Base and Extended  
 *              IviDownconverter Capabilities.                                        
 ****************************************************************************/

#ifndef IVIDOWNCONVERTER_HEADER
#define IVIDOWNCONVERTER_HEADER

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

#define IVIDOWNCONVERTER_MAJOR_VERSION                (4L)
#define IVIDOWNCONVERTER_MINOR_VERSION                (0L)

#define IVIDOWNCONVERTER_CLASS_SPEC_MAJOR_VERSION     (2L)
#define IVIDOWNCONVERTER_CLASS_SPEC_MINOR_VERSION     (0L)

#define IVIDOWNCONVERTER_DRIVER_VENDOR                "National Instruments"
#ifdef	_IVI_mswin64_
#define IVIDOWNCONVERTER_DRIVER_DESCRIPTION           "IviDownconverter Class Driver [Compiled for 64-bit.]"
#else
#define IVIDOWNCONVERTER_DRIVER_DESCRIPTION           "IviDownconverter Class Driver"
#endif

/****************************************************************************
 *------------------------------ Useful Macros -----------------------------*
 ****************************************************************************/

  
/****************************************************************************
 *---------------- IviDownconverter Class Attribute Defines ----------------*
 ****************************************************************************/

    /*- IVI Inherent Attributes -*/

        /*- User Options -*/
#define IVIDOWNCONVERTER_ATTR_CACHE                     IVI_ATTR_CACHE                       /* ViBoolean */
#define IVIDOWNCONVERTER_ATTR_RANGE_CHECK               IVI_ATTR_RANGE_CHECK                 /* ViBoolean */
#define IVIDOWNCONVERTER_ATTR_QUERY_INSTRUMENT_STATUS   IVI_ATTR_QUERY_INSTRUMENT_STATUS     /* ViBoolean */
#define IVIDOWNCONVERTER_ATTR_RECORD_COERCIONS          IVI_ATTR_RECORD_COERCIONS            /* ViBoolean */
#define IVIDOWNCONVERTER_ATTR_SIMULATE                  IVI_ATTR_SIMULATE                    /* ViBoolean */
#define IVIDOWNCONVERTER_ATTR_INTERCHANGE_CHECK         IVI_ATTR_INTERCHANGE_CHECK           /* ViBoolean */
#define IVIDOWNCONVERTER_ATTR_SPY                       IVI_ATTR_SPY                         /* ViBoolean */
#define IVIDOWNCONVERTER_ATTR_USE_SPECIFIC_SIMULATION   IVI_ATTR_USE_SPECIFIC_SIMULATION     /* ViBoolean */

        /*- Instrument Capabilities -*/
#define IVIDOWNCONVERTER_ATTR_GROUP_CAPABILITIES        IVI_ATTR_GROUP_CAPABILITIES          /* ViString, read-only */
#define IVIDOWNCONVERTER_ATTR_FUNCTION_CAPABILITIES     IVI_ATTR_FUNCTION_CAPABILITIES       /* ViString, read-only */

        /*- Class Driver Information -*/    
#define IVIDOWNCONVERTER_ATTR_CLASS_DRIVER_PREFIX                     IVI_ATTR_CLASS_DRIVER_PREFIX         			  /* ViString, read-only */
#define IVIDOWNCONVERTER_ATTR_CLASS_DRIVER_VENDOR                     IVI_ATTR_CLASS_DRIVER_VENDOR         			  /* ViString, read-only */
#define IVIDOWNCONVERTER_ATTR_CLASS_DRIVER_DESCRIPTION                IVI_ATTR_CLASS_DRIVER_DESCRIPTION    			  /* ViString, read-only */
#define IVIDOWNCONVERTER_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION   IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVIDOWNCONVERTER_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION   IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION  /* ViInt32,  read-only */

        /*- Specific Driver Information -*/    
#define IVIDOWNCONVERTER_ATTR_SPECIFIC_DRIVER_PREFIX                      IVI_ATTR_SPECIFIC_DRIVER_PREFIX      				 /* ViString, read-only */
#define IVIDOWNCONVERTER_ATTR_SPECIFIC_DRIVER_LOCATOR                     IVI_ATTR_SPECIFIC_DRIVER_LOCATOR     				 /* ViString, read-only */
#define IVIDOWNCONVERTER_ATTR_IO_RESOURCE_DESCRIPTOR                      IVI_ATTR_IO_RESOURCE_DESCRIPTOR      				 /* ViString, read-only */
#define IVIDOWNCONVERTER_ATTR_LOGICAL_NAME                                IVI_ATTR_LOGICAL_NAME                				 /* ViString, read-only */
#define IVIDOWNCONVERTER_ATTR_SPECIFIC_DRIVER_VENDOR                      IVI_ATTR_SPECIFIC_DRIVER_VENDOR      				 /* ViString, read-only */
#define IVIDOWNCONVERTER_ATTR_SPECIFIC_DRIVER_DESCRIPTION                 IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION 				 /* ViString, read-only */
#define IVIDOWNCONVERTER_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVIDOWNCONVERTER_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION  /* ViInt32,  read-only */

        /*- Instrument Information -*/    
#define IVIDOWNCONVERTER_ATTR_INSTRUMENT_FIRMWARE_REVISION     IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION /* ViString, read-only */
#define IVIDOWNCONVERTER_ATTR_INSTRUMENT_MANUFACTURER          IVI_ATTR_INSTRUMENT_MANUFACTURER      /* ViString, read-only */
#define IVIDOWNCONVERTER_ATTR_INSTRUMENT_MODEL                 IVI_ATTR_INSTRUMENT_MODEL             /* ViString, read-only */
#define IVIDOWNCONVERTER_ATTR_SUPPORTED_INSTRUMENT_MODELS      IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS	 /* ViString, read-only */

        /*- Version Information -*/
#define IVIDOWNCONVERTER_ATTR_CLASS_DRIVER_REVISION            IVI_ATTR_CLASS_DRIVER_REVISION        /* ViString, read-only */

#define IVIDOWNCONVERTER_ATTR_SPECIFIC_DRIVER_REVISION         IVI_ATTR_SPECIFIC_DRIVER_REVISION     /* ViString, read-only */

        /*- Driver Setup Information -*/
#define IVIDOWNCONVERTER_ATTR_DRIVER_SETUP              	   IVI_ATTR_DRIVER_SETUP                 /* ViString */

    /*- IviDownconverter Fundamental Attributes -*/
#define IVIDOWNCONVERTER_ATTR_IF_OUTPUT_COUNT                  			(IVI_CLASS_PUBLIC_ATTR_BASE + 4L)    /* ViInt32,  read-only */
#define IVIDOWNCONVERTER_ATTR_RF_INPUT_FREQUENCY			            (IVI_CLASS_PUBLIC_ATTR_BASE + 12L)   /* ViReal64 */
#define IVIDOWNCONVERTER_ATTR_RF_INPUT_COUPLING							(IVI_CLASS_PUBLIC_ATTR_BASE + 10L)	 /* ViInt32  */	
#define IVIDOWNCONVERTER_ATTR_RF_INPUT_COUNT						    (IVI_CLASS_PUBLIC_ATTR_BASE + 11L)	 /* ViInt32,  read-only */
#define IVIDOWNCONVERTER_ATTR_ACTIVE_RF_INPUT							(IVI_CLASS_PUBLIC_ATTR_BASE + 1L)	 /* ViString */
#define IVIDOWNCONVERTER_ATTR_ACTIVE_IF_OUTPUT							(IVI_CLASS_PUBLIC_ATTR_BASE + 0L)	 /* ViString */	
#define IVIDOWNCONVERTER_ATTR_IF_OUTPUT_FREQUENCY						(IVI_CLASS_PUBLIC_ATTR_BASE + 6L)	 /* ViReal64, read-only */ 
#define IVIDOWNCONVERTER_ATTR_IF_OUTPUT_ENABLED							(IVI_CLASS_PUBLIC_ATTR_BASE + 5L)	 /* ViBoolean*/
#define IVIDOWNCONVERTER_ATTR_IF_OUTPUT_GAIN							(IVI_CLASS_PUBLIC_ATTR_BASE + 7L)	 /* ViReal64 */	 
#define IVIDOWNCONVERTER_ATTR_RF_INPUT_ATTENUATION						(IVI_CLASS_PUBLIC_ATTR_BASE + 9L)	 /* ViReal64 */
#define IVIDOWNCONVERTER_ATTR_RF_INPUT_CORRECTIONS_ENABLED				(IVI_CLASS_PUBLIC_ATTR_BASE + 340L)	 /* ViBoolean*/
#define IVIDOWNCONVERTER_ATTR_IS_SETTLED								(IVI_CLASS_PUBLIC_ATTR_BASE + 8L)	 /* ViBoolean,read-only */
#define IVIDOWNCONVERTER_ATTR_EXTERNAL_LO_ENABLED						(IVI_CLASS_PUBLIC_ATTR_BASE + 2L)	 /* ViBoolean*/
#define IVIDOWNCONVERTER_ATTR_EXTERNAL_LO_FREQUENCY						(IVI_CLASS_PUBLIC_ATTR_BASE + 3L)	 /* ViReal64 */	

    /*- IviDownconverterBypass Attributes -*/
#define IVIDOWNCONVERTER_ATTR_BYPASS									(IVI_CLASS_PUBLIC_ATTR_BASE + 100L)	 /* ViBoolean*/	

    /*- IviDownconverterExternalMixer Attributes -*/
#define IVIDOWNCONVERTER_ATTR_EXTERNAL_MIXER_ENABLED					(IVI_CLASS_PUBLIC_ATTR_BASE + 110L)	 /*	ViBoolean*/
#define IVIDOWNCONVERTER_ATTR_EXTERNAL_MIXER_BIAS_LEVEL					(IVI_CLASS_PUBLIC_ATTR_BASE + 111L)	 /* ViReal64 */
#define IVIDOWNCONVERTER_ATTR_EXTERNAL_MIXER_BIAS_LIMIT					(IVI_CLASS_PUBLIC_ATTR_BASE + 112L)	 /* ViReal64 */
#define IVIDOWNCONVERTER_ATTR_EXTERNAL_MIXER_BIAS_ENABLED				(IVI_CLASS_PUBLIC_ATTR_BASE + 113L)	 /* ViBoolean*/
#define IVIDOWNCONVERTER_ATTR_EXTERNAL_MIXER_HARMONIC					(IVI_CLASS_PUBLIC_ATTR_BASE + 114L)	 /* ViInt32  */
#define IVIDOWNCONVERTER_ATTR_EXTERNAL_MIXER_NUMBER_OF_PORTS			(IVI_CLASS_PUBLIC_ATTR_BASE + 115L)	 /* ViInt32  */

    /*- IviDownconverterFrequencyStep Attributes -*/
#define IVIDOWNCONVERTER_ATTR_FREQUENCY_STEP_START						(IVI_CLASS_PUBLIC_ATTR_BASE + 204L)	 /* ViReal64 */
#define IVIDOWNCONVERTER_ATTR_FREQUENCY_STEP_STOP						(IVI_CLASS_PUBLIC_ATTR_BASE + 205L)	 /* ViReal64 */
#define IVIDOWNCONVERTER_ATTR_FREQUENCY_STEP_SIZE						(IVI_CLASS_PUBLIC_ATTR_BASE + 203L)	 /* ViReal64 */
#define IVIDOWNCONVERTER_ATTR_FREQUENCY_STEP_DWELL						(IVI_CLASS_PUBLIC_ATTR_BASE + 200L)	 /* ViReal64 */
#define IVIDOWNCONVERTER_ATTR_FREQUENCY_STEP_SINGLE_STEP_ENABLED		(IVI_CLASS_PUBLIC_ATTR_BASE + 202L)	 /* ViBoolean*/
#define IVIDOWNCONVERTER_ATTR_FREQUENCY_STEP_SCALING					(IVI_CLASS_PUBLIC_ATTR_BASE + 201L)	 /* ViInt32  */

    /*- IviDownconverterFrequencySweep Attributes -*/
#define IVIDOWNCONVERTER_ATTR_FREQUENCY_SWEEP_START				        (IVI_CLASS_PUBLIC_ATTR_BASE + 211L)  /* ViReal64 */
#define IVIDOWNCONVERTER_ATTR_FREQUENCY_SWEEP_STOP						(IVI_CLASS_PUBLIC_ATTR_BASE + 212L)	 /* ViReal64 */	
#define IVIDOWNCONVERTER_ATTR_FREQUENCY_SWEEP_TIME						(IVI_CLASS_PUBLIC_ATTR_BASE + 213L)	 /* ViReal64 */
#define IVIDOWNCONVERTER_ATTR_FREQUENCY_SWEEP_TRIGGER_SOURCE			(IVI_CLASS_PUBLIC_ATTR_BASE + 214L)	 /* ViString */	
#define IVIDOWNCONVERTER_ATTR_FREQUENCY_SWEEP_MODE						(IVI_CLASS_PUBLIC_ATTR_BASE + 210L)	 /* ViInt32  */
#define IVIDOWNCONVERTER_ATTR_IS_SWEEPING								(IVI_CLASS_PUBLIC_ATTR_BASE + 215L)	 /* ViBoolean,read-only */	

    /*- IviDownconverterFrequencySweepList Attributes -*/
#define IVIDOWNCONVERTER_ATTR_FREQUENCY_SWEEP_LIST_SELECTED_NAME		(IVI_CLASS_PUBLIC_ATTR_BASE + 221L)	 /* ViString */
#define IVIDOWNCONVERTER_ATTR_FREQUENCY_SWEEP_LIST_DWELL				(IVI_CLASS_PUBLIC_ATTR_BASE + 220L)	 /* ViReal64 */
#define IVIDOWNCONVERTER_ATTR_FREQUENCY_SWEEP_LIST_SINGLE_STEP_ENABLED	(IVI_CLASS_PUBLIC_ATTR_BASE + 222L)	 /* ViBoolean*/

    /*- IviDownconverterBandCrossingInformation Attributes -*/
#define IVIDOWNCONVERTER_ATTR_NUM_BANDS									(IVI_CLASS_PUBLIC_ATTR_BASE + 300L)	 /* ViInt32,  read-only */

    /*- IviDownconverterIFFilter Attributes -*/
#define IVIDOWNCONVERTER_ATTR_IF_OUTPUT_FILTER_BANDWIDTH				(IVI_CLASS_PUBLIC_ATTR_BASE + 310L)	 /* ViReal64 */

    /*- IviDownconverterPreselector Attributes -*/
#define IVIDOWNCONVERTER_ATTR_PRESELECTOR_ENABLED						(IVI_CLASS_PUBLIC_ATTR_BASE + 320L)	 /* ViBoolean*/

    /*- IviDownconverterVideoDetectorBandwidth Attributes -*/
#define IVIDOWNCONVERTER_ATTR_IF_OUTPUT_VIDEO_DETECTOR_BANDWIDTH		(IVI_CLASS_PUBLIC_ATTR_BASE + 330L)	 /* ViReal64 */	

    /*- IviDownconverterReferenceOscillator Attributes -*/
#define IVIDOWNCONVERTER_ATTR_REFERENCE_OSCILLATOR_EXTERNAL_FREQUENCY	(IVI_CLASS_PUBLIC_ATTR_BASE + 341L)  /* ViReal64 */
#define IVIDOWNCONVERTER_ATTR_REFERENCE_OSCILLATOR_SOURCE	            (IVI_CLASS_PUBLIC_ATTR_BASE + 342L)  /* ViInt32  */
#define IVIDOWNCONVERTER_ATTR_REFERENCE_OSCILLATOR_OUTPUT_ENABLED		(IVI_CLASS_PUBLIC_ATTR_BASE + 343L)	 /* ViBoolean*/

/****************************************************************************
 *--------------- IviDownconverter Class Attribute Value Defines -----------*
 ****************************************************************************/

    /*- Defined values for attribute IVIDOWNCONVERTER_ATTR_FREQUENCY_STEP_SCALING -*/
#define IVIDOWNCONVERTER_VAL_FREQUENCY_STEP_SCALING_LINEAR                     (0L)
#define IVIDOWNCONVERTER_VAL_FREQUENCY_STEP_SCALING_LOGARITHMIC                (1L)

#define IVIDOWNCONVERTER_VAL_FREQUENCY_STEP_SCALING_CLASS_EXT_BASE			   (100L)
#define IVIDOWNCONVERTER_VAL_FREQUENCY_STEP_SCALING_SPECIFIC_EXT_BASE		   (1000L)

    /*- Defined values for attribute IVIDOWNCONVERTER_ATTR_FREQUENCY_SWEEP_MODE -*/
#define IVIDOWNCONVERTER_VAL_FREQUENCY_SWEEP_MODE_NONE						   (0L)
#define IVIDOWNCONVERTER_VAL_FREQUENCY_SWEEP_MODE_SWEEP			               (1L)
#define IVIDOWNCONVERTER_VAL_FREQUENCY_SWEEP_MODE_STEP						   (2L)
#define IVIDOWNCONVERTER_VAL_FREQUENCY_SWEEP_MODE_LIST						   (3L)

#define IVIDOWNCONVERTER_VAL_FREQUENCY_SWEEP_MODE_CLASS_EXT_BASE			   (100L)
#define IVIDOWNCONVERTER_VAL_FREQUENCY_SWEEP_MODE_SPECIFIC_EXT_BASE			   (1000L)

    /*- Defined values for attribute IVIDOWNCONVERTER_ATTR_FREQUENCY_SWEEP_TRIGGER_SOURCE -*/
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_NONE							   ""
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_IMMEDIATE						   "Immediate"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_EXTERNAL						   "External"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_INTERNAL						   "Internal"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_SOFTWARE						   "Software"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_LAN0							   "LAN0"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_LAN1							   "LAN1"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_LAN2							   "LAN2"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_LAN3							   "LAN3"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_LAN4							   "LAN4"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_LAN5							   "LAN5"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_LAN6							   "LAN6"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_LAN7							   "LAN7"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_LXI0							   "LXI0"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_LXI1							   "LXI1"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_LXI2							   "LXI2"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_LXI3							   "LXI3"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_LXI4							   "LXI4"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_LXI5							   "LXI5"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_LXI6							   "LXI6"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_LXI7							   "LXI7"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_TTL0							   "TTL0"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_TTL1							   "TTL1"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_TTL2							   "TTL2"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_TTL3							   "TTL3"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_TTL4							   "TTL4"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_TTL5							   "TTL5"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_TTL6							   "TTL6"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_TTL7							   "TTL7"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_PXI_STAR						   "PXI_STAR"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_PXI_TRIG0						   "PXI_TRIG0"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_PXI_TRIG1						   "PXI_TRIG1"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_PXI_TRIG2						   "PXI_TRIG2"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_PXI_TRIG3						   "PXI_TRIG3"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_PXI_TRIG4						   "PXI_TRIG4"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_PXI_TRIG5						   "PXI_TRIG5"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_PXI_TRIG6						   "PXI_TRIG6"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_PXI_TRIG7						   "PXI_TRIG7"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_PXIE_DSTARA						   "PXIe_DSTARA"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_PXIE_DSTARB						   "PXIe_DSTARB"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_PXIE_DSTARC						   "PXIe_DSTARC"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_RTSI0							   "RTSI0"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_RTSI1							   "RTSI1"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_RTSI2							   "RTSI2"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_RTSI3							   "RTSI3"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_RTSI4							   "RTSI4"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_RTSI5							   "RTSI5"
#define IVIDOWNCONVERTER_VAL_TRIGGER_SOURCE_RTSI6							   "RTSI6"

    /*- Defined values for attribute IVIDOWNCONVERTER_ATTR_REFERENCE_OSCILLATOR_SOURCE -*/
#define IVIDOWNCONVERTER_VAL_REFERENCE_OSCILLATOR_SOURCE_INTERNAL              (0L)
#define IVIDOWNCONVERTER_VAL_REFERENCE_OSCILLATOR_SOURCE_EXTERNAL              (1L)

#define IVIDOWNCONVERTER_VAL_REFERENCE_OSCILLATOR_SOURCE_CLASS_EXT_BASE		   (100L)
#define IVIDOWNCONVERTER_VAL_REFERENCE_OSCILLATOR_SOURCE_SPECIFIC_EXT_BASE	   (1000L)

    /*- Defined values for attribute IVIDOWNCONVERTER_ATTR_RF_INPUT_COUPLING -*/
#define IVIDOWNCONVERTER_VAL_INPUT_COUPLING_AC			                       (0L)
#define IVIDOWNCONVERTER_VAL_INPUT_COUPLING_DC                       		   (1L)

#define IVIDOWNCONVERTER_VAL_RF_INPUT_COUPLING_CLASS_EXT_BASE				   (100L)
#define IVIDOWNCONVERTER_VAL_RF_INPUT_COUPLING_SPECIFIC_EXT_BASE			   (1000L)

#define IVIDOWNCONVERTER_VAL_CALIBRATION_COMPLETE   						   (0L)
#define IVIDOWNCONVERTER_VAL_CALIBRATION_IN_PROGRESS						   (1L)
#define IVIDOWNCONVERTER_VAL_CALIBRATION_STATUS_UNKNOWN						   (2L)
#define IVIDOWNCONVERTER_VAL_CALIBRATION_FAILED         					   (3L)

#define IVIDOWNCONVERTER_VAL_CALIBRATED										   (0L)
#define IVIDOWNCONVERTER_VAL_UNCALIBRATED									   (1L)
#define IVIDOWNCONVERTER_VAL_CALIBRATED_STATUS_UNKNOWN						   (2L)

#define IVIDOWNCONVERTER_VAL_MAX_TIME_IMMEDIATE								   (IVI_VAL_MAX_TIME_IMMEDIATE)
#define IVIDOWNCONVERTER_VAL_MAX_TIME_INFINITE								   (IVI_VAL_MAX_TIME_INFINITE)

/****************************************************************************
 *------- IviDownconverter Class Instrument Driver Function Declarations ---*
 ****************************************************************************/
    /*- Required VXIplug&play Functions -*/
ViStatus _VI_FUNC IviDownconverter_init (ViRsrc logicalName, 
                               			 ViBoolean idQuery, 
                               			 ViBoolean resetDevice, 
                               			 ViSession *vi);

ViStatus _VI_FUNC IviDownconverter_close (ViSession vi);

ViStatus _VI_FUNC IviDownconverter_reset (ViSession vi);

ViStatus _VI_FUNC IviDownconverter_self_test (ViSession vi, 
                                    		  ViInt16 *selfTestResult, 
                                    		  ViChar selfTestMessage[]);

ViStatus _VI_FUNC IviDownconverter_error_query (ViSession vi, 
                                      			ViInt32 *errorCode, 
                                      			ViChar errorMessage[]);

ViStatus _VI_FUNC IviDownconverter_error_message (ViSession vi, 
                                        		  ViStatus statusCode, 
                                        		  ViChar message[]);

ViStatus _VI_FUNC IviDownconverter_revision_query (ViSession vi, 
                                         		   ViChar driverRev[], 
                                         		   ViChar instrRev[]);

    /*- Utility Functions -*/
ViStatus _VI_FUNC IviDownconverter_InvalidateAllAttributes (ViSession vi);

ViStatus _VI_FUNC IviDownconverter_ResetWithDefaults (ViSession vi);

ViStatus _VI_FUNC IviDownconverter_Disable (ViSession vi);

    /*- Required IVI Functions -*/
ViStatus _VI_FUNC IviDownconverter_InitWithOptions (ViRsrc logicalName, 
                                          			ViBoolean IDQuery,
                                          			ViBoolean resetDevice, 
                                          			ViConstString optionString, 
                                          			ViSession *vi);

    /*- Set, Get, and Check Attribute Functions -*/
ViStatus _VI_FUNC IviDownconverter_GetAttributeViInt32 (ViSession vi, 
                                              			ViConstString channelName,
                                              			ViAttr attributeId,
                                              			ViInt32 *value);

ViStatus _VI_FUNC IviDownconverter_SetAttributeViInt32 (ViSession vi, 
                                              			ViConstString channelName,
                                              			ViAttr attributeId,
                                              			ViInt32 value);

ViStatus _VI_FUNC IviDownconverter_CheckAttributeViInt32 (ViSession vi, 
                                                		  ViConstString channelName,
                                                		  ViAttr attributeId,
                                                		  ViInt32 value);

#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus _VI_FUNC IviDownconverter_GetAttributeViInt64 (ViSession vi, 
                                              			ViConstString channelName,
                                              			ViAttr attributeId,
                                              			ViInt64 *value);

ViStatus _VI_FUNC IviDownconverter_SetAttributeViInt64 (ViSession vi, 
                                              			ViConstString channelName,
                                              			ViAttr attributeId,
                                              			ViInt64 value);

ViStatus _VI_FUNC IviDownconverter_CheckAttributeViInt64 (ViSession vi, 
                                                		  ViConstString channelName,
                                                		  ViAttr attributeId,
                                                		  ViInt64 value);
#endif

ViStatus _VI_FUNC IviDownconverter_GetAttributeViReal64 (ViSession vi, 
                                               			 ViConstString channelName, 
                                               			 ViAttr attributeId, 
                                               			 ViReal64 *value);

ViStatus _VI_FUNC IviDownconverter_SetAttributeViReal64 (ViSession vi, 
                                               			 ViConstString channelName, 
                                               			 ViAttr attributeId, 
                                               			 ViReal64 value);

ViStatus _VI_FUNC IviDownconverter_CheckAttributeViReal64 (ViSession vi, 
                                                 		   ViConstString channelName, 
                                                 		   ViAttr attributeId, 
                                                 		   ViReal64 value);

ViStatus _VI_FUNC IviDownconverter_GetAttributeViString (ViSession vi, 
                                               			 ViConstString channelName, 
                                               			 ViAttr attributeId, 
                                               			 ViInt32 bufferSize, 
                                               			 ViChar value[]);

ViStatus _VI_FUNC IviDownconverter_SetAttributeViString (ViSession vi, 
                                               			 ViConstString channelName, 
                                               			 ViAttr attributeId, 
                                               			 ViConstString value);

ViStatus _VI_FUNC IviDownconverter_CheckAttributeViString (ViSession vi, 
                                                 		   ViConstString channelName, 
                                                 		   ViAttr attributeId, 
                                                 		   ViConstString value); 

ViStatus _VI_FUNC IviDownconverter_GetAttributeViBoolean (ViSession vi, 
                                                		  ViConstString channelName, 
                                                		  ViAttr attributeId, 
                                                		  ViBoolean *value);

ViStatus _VI_FUNC IviDownconverter_SetAttributeViBoolean (ViSession vi, 
                                                		  ViConstString channelName, 
                                                		  ViAttr attributeId, 
                                                		  ViBoolean value);

ViStatus _VI_FUNC IviDownconverter_CheckAttributeViBoolean (ViSession vi, 
                                                  			ViConstString channelName, 
                                                  			ViAttr attributeId, 
                                                  			ViBoolean value);

ViStatus _VI_FUNC IviDownconverter_GetAttributeViSession (ViSession vi, 
                                                		  ViConstString channelName, 
                                                		  ViAttr attributeId, 
                                                		  ViSession *value);

ViStatus _VI_FUNC IviDownconverter_SetAttributeViSession (ViSession vi, 
                                                		  ViConstString channelName, 
                                                		  ViAttr attributeId, 
                                                		  ViSession value);

ViStatus _VI_FUNC IviDownconverter_CheckAttributeViSession (ViSession vi, 
                                                  			ViConstString channelName, 
                                                  			ViAttr attributeId, 
                                                  			ViSession value);

    /*- Lock and Unlock Functions -*/
ViStatus _VI_FUNC IviDownconverter_LockSession (ViSession vi, 
                                      			ViBoolean *callerHasLock);

ViStatus _VI_FUNC IviDownconverter_UnlockSession (ViSession vi, 
                                        		  ViBoolean *callerHasLock);

    /*- Error Information Functions -*/
ViStatus _VI_FUNC IviDownconverter_GetError (ViSession vi, 
                                   			 ViStatus *errorCode, 
                                   			 ViInt32 bufferSize, 
                                   			 ViChar description[]);

ViStatus _VI_FUNC IviDownconverter_ClearError (ViSession vi);

    /*- Interchangeability Checking Functions -*/
ViStatus _VI_FUNC IviDownconverter_GetNextInterchangeWarning (ViSession vi, 
                                                    		  ViInt32 bufferSize,
                                                    		  ViChar warning[]);

ViStatus _VI_FUNC IviDownconverter_ClearInterchangeWarnings (ViSession vi);
ViStatus _VI_FUNC IviDownconverter_ResetInterchangeCheck (ViSession vi);

ViStatus _VI_FUNC IviDownconverter_GetNextCoercionRecord (ViSession vi,
                                                		  ViInt32 bufferSize, 
                                                		  ViChar record[]);

ViStatus _VI_FUNC IviDownconverter_GetSpecificDriverCHandle (ViSession vi,
                                                   			 ViSession* specificDriverCHandle);	

    /*- IviDownconverterBase Functions -*/
ViStatus _VI_FUNC   IviDownconverter_ConfigureIFOutputEnabled (ViSession vi, 
                                                 			   ViBoolean enabled);

ViStatus _VI_FUNC   IviDownconverter_ConfigureIFOutputGain (ViSession vi, 
															ViReal64 gain);

ViStatus _VI_FUNC   IviDownconverter_GetIFOutputName (ViSession vi, 
													  ViInt32 index,
													  ViInt32 nameBufferSize,
													  ViChar name[]);

ViStatus _VI_FUNC   IviDownconverter_SetActiveIFOutput (ViSession vi, 
														ViConstString name);

ViStatus _VI_FUNC   IviDownconverter_ConfigureRFInputAttenuation (ViSession vi, 
																  ViReal64 attenuation);

ViStatus _VI_FUNC   IviDownconverter_ConfigureRFInputFrequency (ViSession vi, 
																ViReal64 frequency);

ViStatus _VI_FUNC	IviDownconverter_GetRFInputName (ViSession vi, 
													 ViInt32 index,
												     ViInt32 nameBufferSize,
												     ViChar name[]);

ViStatus _VI_FUNC	IviDownconverter_SetActiveRFInput (ViSession vi,
													   ViConstString name);

ViStatus _VI_FUNC	IviDownconverter_WaitUntilSettled (ViSession vi,
													   ViInt32 maxTimeMilliseconds);

    /*- IviDownconverterBypass Functions -*/
ViStatus _VI_FUNC   IviDownconverter_ConfigureBypass (ViSession vi, 
													  ViBoolean bypass);
    
    /*- IviDownconverterExternalMixer Functions -*/
ViStatus _VI_FUNC   IviDownconverter_ConfigureExternalMixerBias (ViSession vi, 
																 ViReal64 bias, 
															     ViReal64 biasLimit);

    /*- IviDownconverterFrequencyStep Functions -*/
ViStatus _VI_FUNC   IviDownconverter_ConfigureFrequencyStepDwell (ViSession vi, 
																  ViBoolean singleStepEnabled, 
																  ViReal64 dwell);

ViStatus _VI_FUNC	IviDownconverter_ConfigureFrequencyStepStartStop (ViSession vi,
																	  ViReal64 start,
																	  ViReal64 stop,
																	  ViInt32 scaling,
																	  ViReal64 stepSize);

ViStatus _VI_FUNC	IviDownconverter_ResetFrequencyStep (ViSession vi);

    /*- IviDownconverterFrequencySweep Functions -*/
ViStatus _VI_FUNC   IviDownconverter_ConfigureFrequencySweep (ViSession vi, 
															  ViInt32 mode,
															  ViConstString triggerSource);

ViStatus _VI_FUNC   IviDownconverter_ConfigureFrequencySweepStartStop (ViSession vi, 
																	   ViReal64 start,
																	   ViReal64 stop);

ViStatus _VI_FUNC	IviDownconverter_ConfigureFrequencySweepTime (ViSession vi,
																  ViReal64 sweepTime);

ViStatus _VI_FUNC	IviDownconverter_WaitUntilFrequencySweepComplete (ViSession vi,
																	  ViInt32 maxTimeMilliseconds);

    /*- IviDownconverterFrequencySweepList Functions -*/
ViStatus _VI_FUNC   IviDownconverter_ClearAllFrequencySweepLists (ViSession vi);

ViStatus _VI_FUNC	IviDownconverter_ConfigureFrequencySweepListDwell (ViSession vi,
																	   ViBoolean singleStepEnabled,
																	   ViReal64 dwell);

ViStatus _VI_FUNC	IviDownconverter_CreateFrequencySweepList (ViSession vi,
															   ViConstString name,
															   ViInt32 frequencyListBufferSize,
															   ViReal64 frequencyList[]);

ViStatus _VI_FUNC	IviDownconverter_ResetFrequencySweepList (ViSession vi);

    /*- IviDownconverterBandCrossingInformation Functions -*/
ViStatus _VI_FUNC   IviDownconverter_GetBandCrossingInfo (ViSession vi, 
														  ViInt32 bufferSize,
														  ViReal64 startFrequencies[],
														  ViReal64 stopFrequencies[],
														  ViInt32* actualNumFrequencies);

    /*- IviDownconverterSoftwareTrigger Functions -*/
ViStatus _VI_FUNC   IviDownconverter_SendSoftwareTrigger (ViSession vi);

    /*- IviDownconverterIFFilter Functions -*/
ViStatus _VI_FUNC   IviDownconverter_ConfigureIFOutputFilterBandwidth (ViSession vi, 
																	   ViReal64 bandwidth);

    /*- IviDownconverterPreselector Functions -*/
ViStatus _VI_FUNC   IviDownconverter_ConfigurePreselectorEnabled (ViSession vi, 
																  ViBoolean enabled);

    /*- IviDownconverterVideoDetectorBandwidth Functions -*/
ViStatus _VI_FUNC   IviDownconverter_ConfigureIFOutputVideoDetectorBandwidth (ViSession vi, 
																			  ViReal64 bandwidth);

    /*- IviDownconverterCalibration Functions -*/
ViStatus _VI_FUNC   IviDownconverter_Calibrate (ViSession vi);

ViStatus _VI_FUNC	IviDownconverter_IsCalibrationComplete (ViSession vi,
															ViInt32* status);

ViStatus _VI_FUNC	IviDownconverter_IsCalibrated (ViSession vi,
												   ViInt32* status);

	/*- IviDownconverterReferenceOscillator Functions -*/
ViStatus _VI_FUNC   IviDownconverter_ConfigureReferenceOscillator (ViSession vi, 
																   ViInt32 source,
																   ViReal64 frequency);

ViStatus _VI_FUNC	IviDownconverter_ConfigureReferenceOscillatorOutputEnabled (ViSession vi,
																				ViBoolean enabled);
                                                
/****************************************************************************
 *------------- IviDownconverter Class Error And Completion Codes ----------*
 ****************************************************************************/
#define IVIDOWNCONVERTER_ERROR_FREQUENCY_LIST_UNKNOWN	(IVI_CLASS_ERROR_BASE + 1L) 
#define IVIDOWNCONVERTER_ERROR_MAX_TIME_EXCEEDED      	(IVI_CLASS_ERROR_BASE + 2L)
#define IVIDOWNCONVERTER_ERROR_TRIGGER_NOT_SOFTWARE   	(IVI_CROSS_CLASS_ERROR_BASE + 1L)

#define IVIDOWNCONVERTER_ERRMSG_FREQUENCY_LIST_UNKNOWN	"The selected frequency list is not defined."
#define IVIDOWNCONVERTER_ERRMSG_MAX_TIME_EXCEEDED     	"Maximum time exceeded before operation completed."	
#define IVIDOWNCONVERTER_ERRMSG_TRIGGER_NOT_SOFTWARE  	"The trigger source is not set to software trigger."

#define IVIDOWNCONVERTER_ERROR_CODES_AND_MSGS \
        {IVIDOWNCONVERTER_ERROR_FREQUENCY_LIST_UNKNOWN, IVIDOWNCONVERTER_ERRMSG_FREQUENCY_LIST_UNKNOWN}, \
        {IVIDOWNCONVERTER_ERROR_MAX_TIME_EXCEEDED,    	IVIDOWNCONVERTER_ERRMSG_MAX_TIME_EXCEEDED	  }, \
        {IVIDOWNCONVERTER_ERROR_TRIGGER_NOT_SOFTWARE, 	IVIDOWNCONVERTER_ERRMSG_TRIGGER_NOT_SOFTWARE  } 

/****************************************************************************
 *---------------------------- End Include File ----------------------------*
 ****************************************************************************/
#if defined(__cplusplus) || defined(__cplusplus__)
}                                                    
#endif

#endif /* IVIDOWNCONVERTER_HEADER */

