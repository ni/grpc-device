/****************************************************************************
 *                           I V I - C O U N T E R                               
 *---------------------------------------------------------------------------
 *    Copyright (c) 2009-2020 National Instruments.  All Rights Reserved.        
 *---------------------------------------------------------------------------
 *                                                                          
 * Title:       ivicounter_ni.h                                                    
 * Purpose:     IviCounter Class declarations for the Base and Extended  
 *              IviCounter Capabilities.                                        
 ****************************************************************************/

#ifndef IVICOUNTER_HEADER
#define IVICOUNTER_HEADER

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

#define IVICOUNTER_MAJOR_VERSION              (4L)
#define IVICOUNTER_MINOR_VERSION              (0L)

#define IVICOUNTER_CLASS_SPEC_MAJOR_VERSION   (2L)
#define IVICOUNTER_CLASS_SPEC_MINOR_VERSION   (0L)

#define IVICOUNTER_DRIVER_VENDOR              "National Instruments"
#ifdef	_IVI_mswin64_
#define IVICOUNTER_DRIVER_DESCRIPTION         "IviCounter Class Driver [Compiled for 64-bit.]"
#else
#define IVICOUNTER_DRIVER_DESCRIPTION			"IviCounter Class Driver"
#endif

/****************************************************************************
 *------------------------------ Useful Macros -----------------------------*
 ****************************************************************************/

/****************************************************************************
 *------------------ IviCounter Class Attribute Defines ----------------------*
 ****************************************************************************/

    /*- IVI Inherent Attributes -*/

        /*- User Options -*/
#define IVICOUNTER_ATTR_CACHE                     IVI_ATTR_CACHE                       /* ViBoolean */
#define IVICOUNTER_ATTR_RANGE_CHECK               IVI_ATTR_RANGE_CHECK                 /* ViBoolean */
#define IVICOUNTER_ATTR_QUERY_INSTRUMENT_STATUS   IVI_ATTR_QUERY_INSTRUMENT_STATUS     /* ViBoolean */
#define IVICOUNTER_ATTR_RECORD_COERCIONS          IVI_ATTR_RECORD_COERCIONS            /* ViBoolean */
#define IVICOUNTER_ATTR_SIMULATE                  IVI_ATTR_SIMULATE                    /* ViBoolean */
#define IVICOUNTER_ATTR_INTERCHANGE_CHECK         IVI_ATTR_INTERCHANGE_CHECK           /* ViBoolean */
#define IVICOUNTER_ATTR_SPY                       IVI_ATTR_SPY                         /* ViBoolean */
#define IVICOUNTER_ATTR_USE_SPECIFIC_SIMULATION   IVI_ATTR_USE_SPECIFIC_SIMULATION     /* ViBoolean */

        /*- Instrument Capabilities -*/
#define IVICOUNTER_ATTR_GROUP_CAPABILITIES        IVI_ATTR_GROUP_CAPABILITIES          /* ViString, read-only */
#define IVICOUNTER_ATTR_FUNCTION_CAPABILITIES     IVI_ATTR_FUNCTION_CAPABILITIES       /* ViString, read-only */

        /*- Class Driver Information -*/    
#define IVICOUNTER_ATTR_CLASS_DRIVER_PREFIX                     IVI_ATTR_CLASS_DRIVER_PREFIX         /* ViString, read-only */
#define IVICOUNTER_ATTR_CLASS_DRIVER_VENDOR                     IVI_ATTR_CLASS_DRIVER_VENDOR         /* ViString, read-only */
#define IVICOUNTER_ATTR_CLASS_DRIVER_DESCRIPTION                IVI_ATTR_CLASS_DRIVER_DESCRIPTION    /* ViString, read-only */
#define IVICOUNTER_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION   IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVICOUNTER_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION   IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION  /* ViInt32,  read-only */

        /*- Specific Driver Information -*/    
#define IVICOUNTER_ATTR_SPECIFIC_DRIVER_PREFIX                      IVI_ATTR_SPECIFIC_DRIVER_PREFIX      /* ViString, read-only */
#define IVICOUNTER_ATTR_SPECIFIC_DRIVER_LOCATOR                     IVI_ATTR_SPECIFIC_DRIVER_LOCATOR     /* ViString, read-only */
#define IVICOUNTER_ATTR_IO_RESOURCE_DESCRIPTOR                      IVI_ATTR_IO_RESOURCE_DESCRIPTOR      /* ViString, read-only */
#define IVICOUNTER_ATTR_LOGICAL_NAME                                IVI_ATTR_LOGICAL_NAME                /* ViString, read-only */
#define IVICOUNTER_ATTR_SPECIFIC_DRIVER_VENDOR                      IVI_ATTR_SPECIFIC_DRIVER_VENDOR      /* ViString, read-only */
#define IVICOUNTER_ATTR_SPECIFIC_DRIVER_DESCRIPTION                 IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION /* ViString, read-only */
#define IVICOUNTER_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVICOUNTER_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION  /* ViInt32,  read-only */

        /*- Instrument Information -*/    
#define IVICOUNTER_ATTR_INSTRUMENT_FIRMWARE_REVISION     IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION /* ViString, read-only */
#define IVICOUNTER_ATTR_INSTRUMENT_MANUFACTURER          IVI_ATTR_INSTRUMENT_MANUFACTURER      /* ViString, read-only */
#define IVICOUNTER_ATTR_INSTRUMENT_MODEL                 IVI_ATTR_INSTRUMENT_MODEL             /* ViString, read-only */
#define IVICOUNTER_ATTR_SUPPORTED_INSTRUMENT_MODELS      IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS

        /*- Version Information -*/
#define IVICOUNTER_ATTR_CLASS_DRIVER_REVISION            IVI_ATTR_CLASS_DRIVER_REVISION              /* ViString, read-only */

#define IVICOUNTER_ATTR_SPECIFIC_DRIVER_REVISION         IVI_ATTR_SPECIFIC_DRIVER_REVISION             /* ViString, read-only */

        /*- Driver Setup Information -*/
#define IVICOUNTER_ATTR_DRIVER_SETUP              		 IVI_ATTR_DRIVER_SETUP                /* ViString */

    /*- IviCounter Fundamental Attributes -*/
#define IVICOUNTER_ATTR_CHANNEL_COUNT					IVI_ATTR_CHANNEL_COUNT				/* ViInt32,  read-only */	
#define IVICOUNTER_ATTR_MEASUREMENT_FUNCTION		    (IVI_CLASS_PUBLIC_ATTR_BASE + 3L)	/* ViInt32		*/
#define IVICOUNTER_ATTR_IMPEDANCE				        (IVI_CLASS_PUBLIC_ATTR_BASE + 4L)	/* ViInt32		*/
#define IVICOUNTER_ATTR_COUPLING			            (IVI_CLASS_PUBLIC_ATTR_BASE + 5L)	/* ViInt32		*/
#define IVICOUNTER_ATTR_ATTENUATION			            (IVI_CLASS_PUBLIC_ATTR_BASE + 6L)	/* ViReal64		*/        
#define IVICOUNTER_ATTR_CHANNEL_LEVEL				    (IVI_CLASS_PUBLIC_ATTR_BASE + 7L)	/* ViReal64		*/    
#define IVICOUNTER_ATTR_CHANNEL_HYSTERESIS			    (IVI_CLASS_PUBLIC_ATTR_BASE + 8L)	/* ViReal64		*/
#define IVICOUNTER_ATTR_CHANNEL_SLOPE				    (IVI_CLASS_PUBLIC_ATTR_BASE + 9L)	/* ViInt32		*/    
#define IVICOUNTER_ATTR_FILTER_ENABLED				    (IVI_CLASS_PUBLIC_ATTR_BASE + 10L)	/* ViBoolean	*/
#define IVICOUNTER_ATTR_FREQUENCY_CHANNEL		        (IVI_CLASS_PUBLIC_ATTR_BASE + 11L)	/* ViString		*/
#define IVICOUNTER_ATTR_FREQUENCY_ESTIMATE			    (IVI_CLASS_PUBLIC_ATTR_BASE + 12L)	/* ViReal64		*/		 
#define IVICOUNTER_ATTR_FREQUENCY_RESOLUTION		    (IVI_CLASS_PUBLIC_ATTR_BASE + 13L)	/* ViReal64		*/   
#define IVICOUNTER_ATTR_FREQUENCY_APERTURE_TIME		    (IVI_CLASS_PUBLIC_ATTR_BASE + 14L)	/* ViReal64		*/ 	
#define IVICOUNTER_ATTR_FREQUENCY_ESTIMATE_AUTO		    (IVI_CLASS_PUBLIC_ATTR_BASE + 15L)	/* ViBoolean	*/
#define IVICOUNTER_ATTR_FREQUENCY_RESOLUTION_AUTO	    (IVI_CLASS_PUBLIC_ATTR_BASE + 16L)	/* ViBoolean	*/
#define IVICOUNTER_ATTR_PERIOD_CHANNEL	                (IVI_CLASS_PUBLIC_ATTR_BASE + 18L)  /* ViString		*/
#define IVICOUNTER_ATTR_PERIOD_ESTIMATE				    (IVI_CLASS_PUBLIC_ATTR_BASE + 19L)	/* ViReal64		*/
#define IVICOUNTER_ATTR_PERIOD_RESOLUTION			    (IVI_CLASS_PUBLIC_ATTR_BASE + 20L)	/* ViReal64		*/
#define IVICOUNTER_ATTR_PERIOD_APERTURE_TIME			(IVI_CLASS_PUBLIC_ATTR_BASE + 21L)	/* ViReal64		*/
#define IVICOUNTER_ATTR_PULSE_WIDTH_CHANNEL             (IVI_CLASS_PUBLIC_ATTR_BASE + 22L)  /* ViString		*/
#define IVICOUNTER_ATTR_PULSE_WIDTH_ESTIMATE			(IVI_CLASS_PUBLIC_ATTR_BASE + 23L)	/* ViReal64		*/
#define IVICOUNTER_ATTR_PULSE_WIDTH_RESOLUTION		    (IVI_CLASS_PUBLIC_ATTR_BASE + 24L)	/* ViReal64		*/
#define IVICOUNTER_ATTR_DUTY_CYCLE_CHANNEL			    (IVI_CLASS_PUBLIC_ATTR_BASE + 25L)  /* ViString		*/
#define IVICOUNTER_ATTR_DUTY_CYCLE_FREQUENCY_ESTIMATE	(IVI_CLASS_PUBLIC_ATTR_BASE + 26L)	/* ViReal64		*/
#define IVICOUNTER_ATTR_DUTY_CYCLE_RESOLUTION		    (IVI_CLASS_PUBLIC_ATTR_BASE + 27L)	/* ViReal64		*/
#define IVICOUNTER_ATTR_EDGE_TIME_CHANNEL	            (IVI_CLASS_PUBLIC_ATTR_BASE + 28L)  /* ViString		*/
#define IVICOUNTER_ATTR_EDGE_TIME_REFERENCE_TYPE		(IVI_CLASS_PUBLIC_ATTR_BASE + 29L)  /* ViInt32		*/
#define IVICOUNTER_ATTR_EDGE_TIME_ESTIMATE		        (IVI_CLASS_PUBLIC_ATTR_BASE + 30L) 	/* ViReal64		*/
#define IVICOUNTER_ATTR_EDGE_TIME_RESOLUTION			(IVI_CLASS_PUBLIC_ATTR_BASE + 31L) 	/* ViReal64		*/
#define IVICOUNTER_ATTR_EDGE_TIME_HIGH_REFERENCE	    (IVI_CLASS_PUBLIC_ATTR_BASE + 32L)	/* ViReal64		*/
#define IVICOUNTER_ATTR_EDGE_TIME_LOW_REFERENCE		    (IVI_CLASS_PUBLIC_ATTR_BASE + 33L)	/* ViReal64		*/
#define IVICOUNTER_ATTR_FREQUENCY_RATIO_NUMERATOR_CHANNEL	(IVI_CLASS_PUBLIC_ATTR_BASE + 34L)   /*ViString   */
#define IVICOUNTER_ATTR_FREQUENCY_RATIO_DENOMINATOR_CHANNEL			    (IVI_CLASS_PUBLIC_ATTR_BASE + 35L)	/* ViString		*/
#define IVICOUNTER_ATTR_FREQUENCY_RATIO_NUMERATOR_FREQUENCY_ESTIMATE	(IVI_CLASS_PUBLIC_ATTR_BASE + 36L)	/* ViReal64		*/
#define IVICOUNTER_ATTR_FREQUENCY_RATIO_ESTIMATE	    (IVI_CLASS_PUBLIC_ATTR_BASE + 37L)	/* ViReal64		*/
#define IVICOUNTER_ATTR_FREQUENCY_RATIO_RESOLUTION	    (IVI_CLASS_PUBLIC_ATTR_BASE + 38L)	/* ViReal64		*/
#define IVICOUNTER_ATTR_TIME_INTERVAL_START_CHANNEL	    (IVI_CLASS_PUBLIC_ATTR_BASE + 39L)  /* ViString		*/
#define IVICOUNTER_ATTR_TIME_INTERVAL_STOP_CHANNEL	    (IVI_CLASS_PUBLIC_ATTR_BASE + 40L)	/* ViString		*/
#define IVICOUNTER_ATTR_TIME_INTERVAL_ESTIMATE	        (IVI_CLASS_PUBLIC_ATTR_BASE + 41L)	/* ViReal64		*/
#define IVICOUNTER_ATTR_TIME_INTERVAL_RESOLUTION	    (IVI_CLASS_PUBLIC_ATTR_BASE + 42L)	/* ViReal64		*/
#define IVICOUNTER_ATTR_PHASE_INPUT_CHANNEL	            (IVI_CLASS_PUBLIC_ATTR_BASE + 43L)  /* ViString		*/
#define IVICOUNTER_ATTR_PHASE_REFERENCE_CHANNEL	        (IVI_CLASS_PUBLIC_ATTR_BASE + 44L)	/* ViString		*/
#define IVICOUNTER_ATTR_PHASE_FREQUENCY_ESTIMATE	    (IVI_CLASS_PUBLIC_ATTR_BASE + 45L)	/* ViReal64		*/
#define IVICOUNTER_ATTR_PHASE_RESOLUTION		        (IVI_CLASS_PUBLIC_ATTR_BASE + 46L)	/* ViReal64		*/
#define IVICOUNTER_ATTR_CONTINUOUS_TOTALIZE_CHANNEL	    (IVI_CLASS_PUBLIC_ATTR_BASE + 47L)  /* ViString		*/
#define IVICOUNTER_ATTR_GATED_TOTALIZE_CHANNEL	        (IVI_CLASS_PUBLIC_ATTR_BASE + 48L)  /* ViString		*/
#define IVICOUNTER_ATTR_GATED_TOTALIZE_GATE_SOURCE	    (IVI_CLASS_PUBLIC_ATTR_BASE + 49L)	/* ViString		*/
#define IVICOUNTER_ATTR_GATED_TOTALIZE_GATE_SLOPE		(IVI_CLASS_PUBLIC_ATTR_BASE + 50L)	/* ViInt32		*/
#define IVICOUNTER_ATTR_TIMED_TOTALIZE_CHANNEL	        (IVI_CLASS_PUBLIC_ATTR_BASE + 51L)  /* ViString		*/
#define IVICOUNTER_ATTR_TIMED_TOTALIZE_GATE_TIME		(IVI_CLASS_PUBLIC_ATTR_BASE + 52L)	/* ViReal64		*/
#define IVICOUNTER_ATTR_START_ARM_TYPE				    (IVI_CLASS_PUBLIC_ATTR_BASE + 53L) 	/* ViInt32		*/
#define IVICOUNTER_ATTR_EXTERNAL_START_ARM_SOURCE		(IVI_CLASS_PUBLIC_ATTR_BASE + 54L)	/* ViString		*/
#define IVICOUNTER_ATTR_EXTERNAL_START_ARM_LEVEL		(IVI_CLASS_PUBLIC_ATTR_BASE + 55L)	/* ViReal64		*/
#define IVICOUNTER_ATTR_EXTERNAL_START_ARM_SLOPE		(IVI_CLASS_PUBLIC_ATTR_BASE + 56L)	/* ViInt32		*/
#define IVICOUNTER_ATTR_EXTERNAL_START_ARM_DELAY	    (IVI_CLASS_PUBLIC_ATTR_BASE + 57L)	/* ViReal64		*/
#define IVICOUNTER_ATTR_STOP_ARM_TYPE				    (IVI_CLASS_PUBLIC_ATTR_BASE + 58L)	/* ViInt32		*/
#define IVICOUNTER_ATTR_EXTERNAL_STOP_ARM_SOURCE		(IVI_CLASS_PUBLIC_ATTR_BASE + 59L)	/* ViString		*/
#define IVICOUNTER_ATTR_EXTERNAL_STOP_ARM_LEVEL			(IVI_CLASS_PUBLIC_ATTR_BASE + 60L)	/* ViReal64		*/
#define IVICOUNTER_ATTR_EXTERNAL_STOP_ARM_SLOPE			(IVI_CLASS_PUBLIC_ATTR_BASE + 61L)	/* ViInt32		*/
#define IVICOUNTER_ATTR_EXTERNAL_STOP_ARM_DELAY			(IVI_CLASS_PUBLIC_ATTR_BASE + 62L)	/* ViReal64		*/

 /*- IviCounter Filter Group Attributes ---------------*/
#define IVICOUNTER_ATTR_FILTER_MINIMUM_FREQUENCY		(IVI_CLASS_PUBLIC_ATTR_BASE + 501L)	/* ViReal64		*/
#define IVICOUNTER_ATTR_FILTER_MAXIMUM_FREQUENCY		(IVI_CLASS_PUBLIC_ATTR_BASE + 502L)	/* ViReal64		*/

 /*- IviCounter Time Interval Delay Group Attributes ---------------*/
#define IVICOUNTER_ATTR_TIME_INTERVAL_STOP_HOLDOFF		(IVI_CLASS_PUBLIC_ATTR_BASE + 601L)/* ViReal64		*/

 /*- IviCounter Voltage Measurement Group Attributes ---------------*/
#define IVICOUNTER_ATTR_VOLTAGE_CHANNEL	                (IVI_CLASS_PUBLIC_ATTR_BASE + 701L) /* ViString		*/
#define IVICOUNTER_ATTR_VOLTAGE_ESTIMATE			    (IVI_CLASS_PUBLIC_ATTR_BASE + 702L)	/* ViReal64		*/
#define IVICOUNTER_ATTR_VOLTAGE_RESOLUTION			    (IVI_CLASS_PUBLIC_ATTR_BASE + 703L)	/* ViReal64		*/

/****************************************************************************
 *----------------- IviCounter Class Attribute Value Defines -----------------*
 ****************************************************************************/

    /*- Defined values for attribute IVICOUNTER_ATTR_COUPLING -*/
#define IVICOUNTER_VAL_AC	 						      (1L)   
#define IVICOUNTER_VAL_DC							      (2L)   

#define IVICOUNTER_VAL_COUPLING_CLASS_EXT_BASE            (500L)
#define IVICOUNTER_VAL_COUPLING_SPECIFIC_EXT_BASE         (1000L) 
 
    /*- Defined values for attribute IVICOUNTER_ATTR_CHANNEL_SLOPE -*/
    /*- Defined values for attribute IVICOUNTER_ATTR_GATED_TOTALIZE_GATE_SLOPE -*/
    /*- Defined values for attribute IVICOUNTER_ATTR_EXTERNAL_START_ARM_SLOPE -*/
    /*- Defined values for attribute IVICOUNTER_ATTR_EXTERNAL_STOP_ARM_SLOPE -*/	
#define IVICOUNTER_VAL_NEGATIVE                           (0L)
#define IVICOUNTER_VAL_POSITIVE                           (1L)
	
#define IVICOUNTER_VAL_SLOPE_CLASS_EXT_BASE            	  (500L)
#define IVICOUNTER_VAL_SLOPE_SPECIFIC_EXT_BASE            (1000L)
	
    /*- Defined values for attribute IVICOUNTER_ATTR_MEASUREMENT_FUNCTION -*/
#define IVICOUNTER_VAL_FREQUENCY			              (1L)
#define IVICOUNTER_VAL_FREQUENCY_WITH_APERTURE			  (2L)
#define IVICOUNTER_VAL_PERIOD							  (3L)
#define IVICOUNTER_VAL_PERIOD_WITH_APERTURE				  (4L)
#define IVICOUNTER_VAL_PULSE_WIDTH						  (5L)
#define IVICOUNTER_VAL_DUTY_CYCLE						  (6L)
#define IVICOUNTER_VAL_EDGE_TIME						  (7L)
#define IVICOUNTER_VAL_FREQUENCY_RATIO					  (8L)
#define IVICOUNTER_VAL_TIME_INTERVAL					  (9L)
#define IVICOUNTER_VAL_PHASE							  (10L)
#define IVICOUNTER_VAL_CONTINUOUS_TOTALIZE				  (11L)
#define IVICOUNTER_VAL_GATED_TOTALIZE					  (12L)
#define IVICOUNTER_VAL_TIMED_TOTALIZE					  (13L)
#define IVICOUNTER_VAL_DC_VOLTAGE						  (14L)
#define IVICOUNTER_VAL_MAXIMUM_VOLTAGE					  (15L)
#define IVICOUNTER_VAL_MINIMUM_VOLTAGE					  (16L)
#define IVICOUNTER_VAL_RMS_VOLTAGE						  (17L)
#define IVICOUNTER_VAL_PEAK_TO_PEAK_VOLTAGE				  (18L)

#define IVICOUNTER_VAL_MEASUREMENT_FUNCTION_CLASS_EXT_BASE (500L)
#define IVICOUNTER_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE (1000L)
	
    /*- Defined values for attribute IVICOUNTER_ATTR_START_ARM_TYPE -*/
    /*- Defined values for attribute IVICOUNTER_ATTR_STOP_ARM_TYPE -*/
#define IVICOUNTER_VAL_IMMEDIATE_ARM_TYPE                 (1L)
#define IVICOUNTER_VAL_EXTERNAL_ARM_TYPE			      (2L)

#define IVICOUNTER_VAL_ARM_TYPE_CLASS_EXT_BASE            (500L)
#define IVICOUNTER_VAL_ARM_TYPE_SPECIFIC_EXT_BASE         (1000L)
	
    /*- Defined values for attribute IVICOUNTER_ATTR_EDGE_TIME_REFERENCE_TYPE -*/	
#define IVICOUNTER_VAL_VOLTAGE_REFERENCE_TYPE			  (1L)
#define IVICOUNTER_VAL_PERCENT_REFERENCE_TYPE			  (2L)

#define IVICOUNTER_VAL_REFERENCE_TYPE_CLASS_EXT_BASE	  (500L)
#define IVICOUNTER_VAL_REFERENCE_TYPE_SPECIFIC_EXT_BASE   (1000L)

    /*- Defined values for Function Parameters  -*/
#define IVICOUNTER_VAL_MAX_TIME_IMMEDIATE				  (0L)
#define IVICOUNTER_VAL_MAX_TIME_INFINITE				  (-1L)

#define IVICOUNTER_VAL_MEASUREMENT_COMPLETE        (1L)   
#define IVICOUNTER_VAL_MEASUREMENT_IN_PROGRESS     (0L)   
#define IVICOUNTER_VAL_MEASUREMENT_STATUS_UNKNOWN         (-1L) 

/****************************************************************************
 *--------- IviCounter Class Instrument Driver Function Declarations -----------*
 ****************************************************************************/
    /*- Required VXIplug&play Functions -*/
ViStatus _VI_FUNC IviCounter_init (ViRsrc logicalName, 
                               ViBoolean idQuery, 
                               ViBoolean resetDevice, 
                               ViSession *vi);

ViStatus _VI_FUNC IviCounter_close (ViSession vi);

ViStatus _VI_FUNC IviCounter_reset (ViSession vi);

ViStatus _VI_FUNC IviCounter_self_test (ViSession vi, 
                                    ViInt16 *selfTestResult, 
                                    ViChar selfTestMessage[]);

ViStatus _VI_FUNC IviCounter_error_query (ViSession vi, 
                                      ViInt32 *errorCode, 
                                      ViChar errorMessage[]);

ViStatus _VI_FUNC IviCounter_error_message (ViSession vi, 
                                        ViStatus statusCode, 
                                        ViChar message[]);

ViStatus _VI_FUNC IviCounter_revision_query (ViSession vi, 
                                         ViChar driverRev[], 
                                         ViChar instrRev[]);

    /*- Utility Functions -*/
ViStatus _VI_FUNC IviCounter_InvalidateAllAttributes (ViSession vi);

ViStatus _VI_FUNC IviCounter_ResetWithDefaults (ViSession vi);

ViStatus _VI_FUNC IviCounter_Disable (ViSession vi);

    /*- Required IVI Functions -*/
ViStatus _VI_FUNC IviCounter_InitWithOptions (ViRsrc logicalName, 
                                          ViBoolean IDQuery,
                                          ViBoolean resetDevice, 
                                          ViConstString optionString, 
                                          ViSession *vi);

    /*- Set, Get, and Check Attribute Functions -*/
ViStatus _VI_FUNC IviCounter_GetAttributeViInt32 (ViSession vi, 
                                              ViConstString channelName,
                                              ViAttr attributeId,
                                              ViInt32 *value);

ViStatus _VI_FUNC IviCounter_SetAttributeViInt32 (ViSession vi, 
                                              ViConstString channelName,
                                              ViAttr attributeId,
                                              ViInt32 value);

ViStatus _VI_FUNC IviCounter_CheckAttributeViInt32 (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId,
                                                ViInt32 value);

#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus _VI_FUNC IviCounter_GetAttributeViInt64 (ViSession vi, 
                                              ViConstString channelName,
                                              ViAttr attributeId,
                                              ViInt64 *value);

ViStatus _VI_FUNC IviCounter_SetAttributeViInt64 (ViSession vi, 
                                              ViConstString channelName,
                                              ViAttr attributeId,
                                              ViInt64 value);

ViStatus _VI_FUNC IviCounter_CheckAttributeViInt64 (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId,
                                                ViInt64 value);
#endif
												
ViStatus _VI_FUNC IviCounter_GetAttributeViReal64 (ViSession vi, 
                                               ViConstString channelName, 
                                               ViAttr attributeId, 
                                               ViReal64 *value);

ViStatus _VI_FUNC IviCounter_SetAttributeViReal64 (ViSession vi, 
                                               ViConstString channelName, 
                                               ViAttr attributeId, 
                                               ViReal64 value);

ViStatus _VI_FUNC IviCounter_CheckAttributeViReal64 (ViSession vi, 
                                                 ViConstString channelName, 
                                                 ViAttr attributeId, 
                                                 ViReal64 value);

ViStatus _VI_FUNC IviCounter_GetAttributeViString (ViSession vi, 
                                               ViConstString channelName, 
                                               ViAttr attributeId, 
                                               ViInt32 bufferSize, 
                                               ViChar value[]);

ViStatus _VI_FUNC IviCounter_SetAttributeViString (ViSession vi, 
                                               ViConstString channelName, 
                                               ViAttr attributeId, 
                                               ViConstString value);

ViStatus _VI_FUNC IviCounter_CheckAttributeViString (ViSession vi, 
                                                 ViConstString channelName, 
                                                 ViAttr attributeId, 
                                                 ViConstString value); 

ViStatus _VI_FUNC IviCounter_GetAttributeViBoolean (ViSession vi, 
                                                ViConstString channelName, 
                                                ViAttr attributeId, 
                                                ViBoolean *value);

ViStatus _VI_FUNC IviCounter_SetAttributeViBoolean (ViSession vi, 
                                                ViConstString channelName, 
                                                ViAttr attributeId, 
                                                ViBoolean value);

ViStatus _VI_FUNC IviCounter_CheckAttributeViBoolean (ViSession vi, 
                                                  ViConstString channelName, 
                                                  ViAttr attributeId, 
                                                  ViBoolean value);

ViStatus _VI_FUNC IviCounter_GetAttributeViSession (ViSession vi, 
                                                ViConstString channelName, 
                                                ViAttr attributeId, 
                                                ViSession *value);

ViStatus _VI_FUNC IviCounter_SetAttributeViSession (ViSession vi, 
                                                ViConstString channelName, 
                                                ViAttr attributeId, 
                                                ViSession value);

ViStatus _VI_FUNC IviCounter_CheckAttributeViSession (ViSession vi, 
                                                  ViConstString channelName, 
                                                  ViAttr attributeId, 
                                                  ViSession value);

    /*- Lock and Unlock Functions -*/
ViStatus _VI_FUNC IviCounter_LockSession (ViSession vi, 
                                      ViBoolean *callerHasLock);

ViStatus _VI_FUNC IviCounter_UnlockSession (ViSession vi, 
                                        ViBoolean *callerHasLock);

    /*- Error Information Functions -*/
ViStatus _VI_FUNC IviCounter_GetError (ViSession vi, 
                                   ViStatus *errorCode, 
                                   ViInt32 bufferSize, 
                                   ViChar description[]);

ViStatus _VI_FUNC IviCounter_ClearError (ViSession vi);

    /*- Interchangeability Checking Functions -*/
ViStatus _VI_FUNC IviCounter_GetNextInterchangeWarning (ViSession vi, 
                                                    ViInt32 bufferSize,
                                                    ViChar warning[]);

ViStatus _VI_FUNC IviCounter_ClearInterchangeWarnings (ViSession vi);
ViStatus _VI_FUNC IviCounter_ResetInterchangeCheck (ViSession vi);

ViStatus _VI_FUNC IviCounter_GetNextCoercionRecord (ViSession vi,
                                                ViInt32 bufferSize, 
                                                ViChar record[]);

ViStatus _VI_FUNC IviCounter_GetSpecificDriverCHandle (ViSession vi,
                                                   ViSession* specificDriverCHandle);

ViStatus _VI_FUNC IviCounter_GetSpecificDriverIUnknownPtr (ViSession vi,
                                                       void* specificDriverIUnknownPtr);
    /*- IviCounterBase Functions -*/
ViStatus _VI_FUNC IviCounter_GetChannelName (ViSession vi, 
                                      ViInt32 ChannelIndex,
                                      ViInt32 ChannelNameBufferSize,
                                      ViChar ChannelName[]);
	
ViStatus _VI_FUNC IviCounter_ConfigureChannel (ViSession vi, 
													  ViConstString Channel, 
													  ViReal64 Impedance, 
													  ViInt32 Coupling,
													  ViReal64 Attenuation);

ViStatus _VI_FUNC IviCounter_ConfigureChannelLevel (ViSession vi, 
														   ViConstString Channel, 
														   ViReal64 TriggerLevel, 
														   ViReal64 Hysteresis);													  
								
ViStatus _VI_FUNC IviCounter_ConfigureChannelSlope (ViSession vi, 
														   ViConstString Channel, 
														   ViInt32 Slope);
								
ViStatus _VI_FUNC IviCounter_ConfigureChannelFilterEnabled (ViSession vi, 
																   ViConstString Channel, 
																   ViBoolean FilterEnabled);

ViStatus _VI_FUNC IviCounter_ConfigureFrequency (ViSession vi, 
													    ViConstString Channel);

ViStatus _VI_FUNC IviCounter_ConfigureFrequencyManual (ViSession vi, 
															  ViConstString Channel, 
															  ViReal64 Estimate, 
															  ViReal64 Resolution);
													
ViStatus _VI_FUNC IviCounter_ConfigureFrequencyWithApertureTime (ViSession vi, 
																		ViConstString Channel, 
																		ViReal64 ApertureTime);	
													
ViStatus _VI_FUNC IviCounter_ConfigurePeriod (ViSession vi, 
													 ViConstString Channel, 
													 ViReal64 Estimate, 
													 ViReal64 Resolution);

ViStatus _VI_FUNC IviCounter_ConfigurePeriodWithApertureTime (ViSession vi, 
																	 ViConstString Channel, 
																	 ViReal64 ApertureTime);
											
ViStatus _VI_FUNC IviCounter_ConfigurePulseWidth (ViSession vi, 
														 ViConstString Channel, 
														 ViReal64 Estimate, 
														 ViReal64 Resolution);
				
ViStatus _VI_FUNC IviCounter_ConfigureDutyCycle (ViSession vi, 
														ViConstString Channel, 
														ViReal64 FrequencyEstimate, 
														ViReal64 Resolution);

ViStatus _VI_FUNC IviCounter_ConfigureEdgeTime (ViSession vi, 
													   ViConstString Channel, 
													   ViReal64 Estimate, 
													   ViReal64 Resolution);												 
	
ViStatus _VI_FUNC IviCounter_ConfigureEdgeTimeReferenceLevels (ViSession vi,
                                                      ViConstString Channel,
                                                      ViInt32 ReferenceType,
                                                      ViReal64 Estimate,
                                                      ViReal64 Resolution,
                                                      ViReal64 HighReference,
                                                      ViReal64 LowReference);
		
ViStatus _VI_FUNC IviCounter_ConfigureFrequencyRatio (ViSession vi, 
															 ViConstString NumeratorChannel,
															 ViConstString DenominatorChannel, 
															 ViReal64 NumeratorFrequencyEstimate,
															 ViReal64 Estimate,
															 ViReal64 Resolution);	
	
ViStatus _VI_FUNC IviCounter_ConfigureTimeInterval (ViSession vi, 
														   ViConstString StartChannel,
														   ViConstString StopChannel, 
														   ViReal64 Estimate, 
														   ViReal64 Resolution);	
	
ViStatus _VI_FUNC IviCounter_ConfigurePhase (ViSession vi, 
													ViConstString MeasurementChannel, 
													ViConstString ReferenceChannel, 
													ViReal64 FrequencyEstimate,
													ViReal64 Resolution);	
													
ViStatus _VI_FUNC IviCounter_ConfigureContinuousTotalize (ViSession vi, 
															     ViConstString Channel);	
	
ViStatus _VI_FUNC IviCounter_ConfigureGatedTotalize (ViSession vi, 
															ViConstString Channel,
															ViConstString GateSource, 
															ViInt32 GateSlope);
		
ViStatus _VI_FUNC IviCounter_ConfigureTimedTotalize (ViSession vi, 
															ViConstString Channel, 
															ViReal64 GateTime);		
		
ViStatus _VI_FUNC IviCounter_ConfigureStartArm (ViSession vi, 
													   ViInt32 Type);		
		
ViStatus _VI_FUNC IviCounter_ConfigureExternalStartArm (ViSession vi, 
															   ViConstString Source,
															   ViReal64 Level, 
															   ViInt32 Slope,
															   ViReal64 Delay);	

ViStatus _VI_FUNC IviCounter_ConfigureStopArm (ViSession vi, 
													  ViInt32 Type);															   
															   
ViStatus _VI_FUNC IviCounter_ConfigureExternalStopArm (ViSession vi, 
															  ViConstString Source,
															  ViReal64 Level, 
															  ViInt32 Slope,
															  ViReal64 Delay);

ViStatus _VI_FUNC IviCounter_ConfigureFilter (ViSession vi, 
													 ViConstString Channel, 
													 ViReal64 MinimumFrequency, 
													 ViReal64 MaximumFrequency);	

ViStatus _VI_FUNC IviCounter_ConfigureTimeIntervalStopHoldoff (ViSession vi, 
																ViReal64 Time);	

ViStatus _VI_FUNC IviCounter_ConfigureVoltage (ViSession vi, 
													  ViConstString Channel, 
													  ViInt32 Function, 
													  ViReal64 Estimate,
													  ViReal64 Resolution);																  
															  
ViStatus _VI_FUNC IviCounter_StartContinuousTotalize (ViSession vi);	

ViStatus _VI_FUNC IviCounter_StopContinuousTotalize (ViSession vi);																  
															  
ViStatus _VI_FUNC IviCounter_FetchContinuousTotalizeCount (ViSession vi, ViInt32* Measurement);
										
ViStatus _VI_FUNC IviCounter_Read (ViSession vi, 
                                 ViInt32 MaximumTime, 
                                 ViReal64 *Measurement);

ViStatus _VI_FUNC IviCounter_Initiate (ViSession vi);								 
								 
ViStatus _VI_FUNC IviCounter_Abort (ViSession vi);

ViStatus _VI_FUNC IviCounter_Fetch (ViSession vi, 
                                  ViReal64 *Measurement);
										
ViStatus _VI_FUNC IviCounter_IsMeasurementComplete (ViSession vi, ViInt32* MeasurementStatus);		
													  
/****************************************************************************
 *--------------- IviCounter Class Error And Completion Codes ----------------*
 ****************************************************************************/
#define IVICOUNTER_WARN_MEASURE_UNCALIBRATED    (IVI_CLASS_WARN_BASE + 0x0001L)

#define IVICOUNTER_ERRMSG_MEASURE_UNCALIBRATED  "The instrument was in an uncalibrated state when the measurement was taken."
	
#define IVICOUNTER_WARN_OVER_RANGE              (IVI_CLASS_WARN_BASE + 0x0002L)

#define IVICOUNTER_ERRMSG_OVER_RANGE            "The measurement taken was over the instrument's range."
	
#define IVICOUNTER_ERROR_MAX_TIME_EXCEEDED      (IVI_CLASS_ERROR_BASE + 0x0003L)

#define IVICOUNTER_ERRMSG_MAX_TIME_EXCEEDED     "The maximum waiting time for this operation was exceeded."	

#define IVICOUNTER_ERROR_CODES_AND_MSGS \
        {IVICOUNTER_WARN_MEASURE_UNCALIBRATED, IVICOUNTER_ERRMSG_MEASURE_UNCALIBRATED}, \
	   {IVICOUNTER_WARN_OVER_RANGE, IVICOUNTER_ERRMSG_OVER_RANGE}, \
	   {IVICOUNTER_ERROR_MAX_TIME_EXCEEDED, IVICOUNTER_ERRMSG_MAX_TIME_EXCEEDED}
	
/****************************************************************************
 *---------------------------- End Include File ----------------------------*
 ****************************************************************************/
#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif /* IVICOUNTER_HEADER */

