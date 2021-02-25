/****************************************************************************
 *                       NI Switch
 *---------------------------------------------------------------------------
 *   Copyright (c) National Instruments 1998-2015.  All Rights Reserved.
 *---------------------------------------------------------------------------
 *
 * Title:    niSwitch.h
 * Purpose:  NI Switch
 *           instrument driver declarations.
 *
 ****************************************************************************/

#ifndef ___niswitch_h___
#define ___niswitch_h___

#define IVI_DO_NOT_INCLUDE_VISA_HEADERS
#include <ivi.h>
#include <IviSwtch.h>
#undef IVI_DO_NOT_INCLUDE_VISA_HEADERS
#include "niswitchTopologies.h"

#ifdef _CVI_
 #pragma EnableLibraryRuntimeChecking
#endif

#ifdef __cplusplus
 extern "C" {
#endif

/****************************************************************************
 *----------------- Instrument Driver Revision Information -----------------*
 ****************************************************************************/
#define NISWITCH_MAJOR_VERSION                  15     /* Instrument driver major version */
#define NISWITCH_MINOR_VERSION                  9      /* Instrument driver minor version */

#define NISWITCH_CLASS_SPEC_MAJOR_VERSION       4      /* Class specification major version */
#define NISWITCH_CLASS_SPEC_MINOR_VERSION       0      /* Class specification minor version */

#define NISWITCH_SUPPORTED_INSTRUMENT_MODELS    "SCXI-1127,"\
                                                "SCXI-1128,"\
                                                "SCXI-1129,"\
                                                "SCXI-1130,"\
                                                "SCXI-1160,"\
                                                "SCXI-1161,"\
                                                "SCXI-1163R,"\
                                                "SCXI-1166,"\
                                                "SCXI-1167,"\
                                                "SCXI-1169,"\
                                                "SCXI-1175,"\
                                                "SCXI-1190,"\
                                                "SCXI-1191,"\
                                                "SCXI-1192,"\
                                                "SCXI-1193,"\
                                                "SCXI-1194,"\
                                                "SCXI-1195,"\
                                                "PXI-2501,"\
                                                "PXI-2503,"\
                                                "PXI-2510,"\
                                                "PXI-2512,"\
                                                "PXI-2514,"\
                                                "PXI-2515,"\
                                                "PXI-2520,"\
                                                "PXI-2521,"\
                                                "PXI-2522,"\
                                                "PXI-2523,"\
                                                "PXI-2527,"\
                                                "PXI-2529,"\
                                                "PXI-2530,"\
                                                "PXI-2531,"\
                                                "PXI-2532,"\
                                                "PXI-2533,"\
                                                "PXI-2534,"\
                                                "PXI-2535,"\
                                                "PXI-2536,"\
                                                "PXI-2540,"\
                                                "PXI-2541,"\
                                                "PXI-2542,"\
                                                "PXI-2543,"\
                                                "PXI-2544,"\
                                                "PXI-2545,"\
                                                "PXI-2546,"\
                                                "PXI-2547,"\
                                                "PXI-2548,"\
                                                "PXI-2549,"\
                                                "PXI-2554,"\
                                                "PXI-2555,"\
                                                "PXI-2556,"\
                                                "PXI-2557,"\
                                                "PXI-2558,"\
                                                "PXI-2559,"\
                                                "PXI-2564,"\
                                                "PXI-2565,"\
                                                "PXI-2566,"\
                                                "PXI-2567,"\
                                                "PXI-2568,"\
                                                "PXI-2569,"\
                                                "PXI-2570,"\
                                                "PXI-2571,"\
                                                "PXI-2575,"\
                                                "PXI-2576,"\
                                                "PXI-2584,"\
                                                "PXI-2585,"\
                                                "PXI-2586,"\
                                                "PXI-2590,"\
                                                "PXI-2591,"\
                                                "PXI-2593,"\
                                                "PXI-2594,"\
                                                "PXI-2595,"\
                                                "PXI-2596,"\
                                                "PXI-2597,"\
                                                "PXI-2598,"\
                                                "PXI-2599,"\
                                                "PXI-2720,"\
                                                "PXI-2722,"\
                                                "PXI-2796,"\
                                                "PXI-2797,"\
                                                "PXI-2798,"\
                                                "PXI-2799,"\
                                                "NI 2810,"\
                                                "NI 2811,"\
                                                "NI 2812,"\
                                                "NI 2813,"\
                                                "NI 2814,"\
                                                "NI 2815,"\
                                                "NI 2816,"\
                                                "NI 2817,"\
                                                "NI 2833,"\
                                                "NI 2834,"\
                                                "NI 2865,"\
                                                "PXIe-2512,"\
                                                "PXIe-2514,"\
                                                "PXIe-2515,"\
                                                "PXIe-2524,"\
                                                "PXIe-2525,"\
                                                "PXIe-2526,"\
                                                "PXIe-2527,"\
                                                "PXIe-2529,"\
                                                "PXIe-2531,"\
                                                "PXIe-2532,"\
                                                "PXIe-2540,"\
                                                "PXIe-2541,"\
                                                "PXIe-2542,"\
                                                "PXIe-2543,"\
                                                "PXIe-2544,"\
                                                "PXIe-2569,"\
                                                "PXIe-2575,"\
                                                "PXIe-2593,"\
                                                "PXIe-2725,"\
                                                "PXIe-2727,"\
                                                "PXIe-2737,"\
                                                "PXIe-2738,"\
                                                "PXIe-2739,"\
                                                "PXIe-2746,"\
                                                "PXIe-2747,"\
                                                "PXIe-2748,"\
                                                "PXIe-2790"

#define NISWITCH_DRIVER_VENDOR                  "National Instruments"
#define NISWITCH_DRIVER_DESCRIPTION             "NI-SWITCH Driver"

/****************************************************************************
 *---------------------------- Attribute Defines ---------------------------*
 ****************************************************************************/

    /*- IVI Inherent Instrument Attributes ---------------------------------*/

    /*- User Options -------------------------------------------------------*/
#define NISWITCH_ATTR_RANGE_CHECK                   IVI_ATTR_RANGE_CHECK                    /* ViBoolean */
#define NISWITCH_ATTR_QUERY_INSTRUMENT_STATUS       IVI_ATTR_QUERY_INSTR_STATUS             /* ViBoolean */
#define NISWITCH_ATTR_CACHE                         IVI_ATTR_CACHE                          /* ViBoolean */
#define NISWITCH_ATTR_SIMULATE                      IVI_ATTR_SIMULATE                       /* ViBoolean */
#define NISWITCH_ATTR_RECORD_COERCIONS              IVI_ATTR_RECORD_COERCIONS               /* ViBoolean */
#define NISWITCH_ATTR_INTERCHANGE_CHECK             IVI_ATTR_INTERCHANGE_CHECK              /* ViBoolean */

    /*- Instrument Capabilities --------------------------------------------*/
#define NISWITCH_ATTR_CHANNEL_COUNT                 IVI_ATTR_NUM_CHANNELS                   /* ViInt32,  read-only  */
#define NISWITCH_ATTR_GROUP_CAPABILITIES            IVI_ATTR_GROUP_CAPABILITIES             /* ViString, read-only */

    /*- Driver Information  ------------------------------------------------*/
#define NISWITCH_ATTR_SPECIFIC_DRIVER_PREFIX        IVI_ATTR_SPECIFIC_DRIVER_PREFIX         /* ViString, read-only  */
#define NISWITCH_ATTR_SUPPORTED_INSTRUMENT_MODELS   IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS    /* ViString, read-only  */
#define NISWITCH_ATTR_INSTRUMENT_MANUFACTURER       IVI_ATTR_INSTRUMENT_MANUFACTURER        /* ViString, read-only  */
#define NISWITCH_ATTR_INSTRUMENT_MODEL              IVI_ATTR_INSTRUMENT_MODEL               /* ViString, read-only  */
#define NISWITCH_ATTR_INSTRUMENT_FIRMWARE_REVISION  IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION   /* ViString, read-only  */
#define NISWITCH_ATTR_SPECIFIC_DRIVER_REVISION      IVI_ATTR_SPECIFIC_DRIVER_REVISION       /* ViString, read-only  */
#define NISWITCH_ATTR_SPECIFIC_DRIVER_VENDOR        IVI_ATTR_SPECIFIC_DRIVER_VENDOR         /* ViString, read-only  */
#define NISWITCH_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION /* ViInt32, read-only */
#define NISWITCH_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION /* ViInt32, read-only */
#define NISWITCH_ATTR_SPECIFIC_DRIVER_DESCRIPTION   IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION    /* ViString, read-only  */
#define NISWITCH_ATTR_DRIVER_SETUP                  IVI_ATTR_DRIVER_SETUP                   /* ViString, read-only  */

    /*- Advanced Session Information ---------------------------------------*/
#define NISWITCH_ATTR_LOGICAL_NAME                  IVI_ATTR_LOGICAL_NAME                   /* ViString, read-only  */
#define NISWITCH_ATTR_IO_RESOURCE_DESCRIPTOR        IVI_ATTR_RESOURCE_DESCRIPTOR            /* ViString, read-only  */

    /*- Configuration Attributes -------------------------------------------*/
#define NISWITCH_ATTR_IS_SOURCE_CHANNEL             IVISWTCH_ATTR_IS_SOURCE_CHANNEL         /* ViBoolean, channel-based */
#define NISWITCH_ATTR_IS_CONFIGURATION_CHANNEL      IVISWTCH_ATTR_IS_CONFIGURATION_CHANNEL  /* ViBoolean, channel-based */

    /*- Status Attributes --------------------------------------------------*/
#define NISWITCH_ATTR_IS_DEBOUNCED                  IVISWTCH_ATTR_IS_DEBOUNCED              /* ViBoolean, read-only */

    /*- Device Information Attributes --------------------------------------*/
#define NISWITCH_ATTR_SETTLING_TIME                 IVISWTCH_ATTR_SETTLING_TIME             /* ViReal64, channel-based */
#define NISWITCH_ATTR_BANDWIDTH                     IVISWTCH_ATTR_BANDWIDTH                 /* ViReal64, channel-based, read-only */
#define NISWITCH_ATTR_MAX_DC_VOLTAGE                IVISWTCH_ATTR_MAX_DC_VOLTAGE            /* ViReal64, channel-based, read-only */
#define NISWITCH_ATTR_MAX_AC_VOLTAGE                IVISWTCH_ATTR_MAX_AC_VOLTAGE            /* ViReal64, channel-based, read-only */
#define NISWITCH_ATTR_MAX_SWITCHING_AC_CURRENT      IVISWTCH_ATTR_MAX_SWITCHING_AC_CURRENT  /* ViReal64, channel-based, read-only */
#define NISWITCH_ATTR_MAX_SWITCHING_DC_CURRENT      IVISWTCH_ATTR_MAX_SWITCHING_DC_CURRENT  /* ViReal64, channel-based, read-only */
#define NISWITCH_ATTR_MAX_CARRY_AC_CURRENT          IVISWTCH_ATTR_MAX_CARRY_AC_CURRENT      /* ViReal64, channel-based, read-only */
#define NISWITCH_ATTR_MAX_CARRY_DC_CURRENT          IVISWTCH_ATTR_MAX_CARRY_DC_CURRENT      /* ViReal64, channel-based, read-only */
#define NISWITCH_ATTR_MAX_SWITCHING_AC_POWER        IVISWTCH_ATTR_MAX_SWITCHING_AC_POWER    /* ViReal64, channel-based, read-only */
#define NISWITCH_ATTR_MAX_SWITCHING_DC_POWER        IVISWTCH_ATTR_MAX_SWITCHING_DC_POWER    /* ViReal64, channel-based, read-only */
#define NISWITCH_ATTR_MAX_CARRY_AC_POWER            IVISWTCH_ATTR_MAX_CARRY_AC_POWER        /* ViReal64, channel-based, read-only */
#define NISWITCH_ATTR_MAX_CARRY_DC_POWER            IVISWTCH_ATTR_MAX_CARRY_DC_POWER        /* ViReal64, channel-based, read-only */
#define NISWITCH_ATTR_CHARACTERISTIC_IMPEDANCE      IVISWTCH_ATTR_CHARACTERISTIC_IMPEDANCE  /* ViReal64, channel-based, read-only */
#define NISWITCH_ATTR_WIRE_MODE                     IVISWTCH_ATTR_WIRE_MODE                 /* ViInt32,  channel-based, read-only */
#define NISWITCH_ATTR_NUM_OF_ROWS                   IVISWTCH_ATTR_NUM_OF_ROWS               /* ViInt32,  read-only */
#define NISWITCH_ATTR_NUM_OF_COLUMNS                IVISWTCH_ATTR_NUM_OF_COLUMNS            /* ViInt32,  read-only */

    /*- Scanning Attributes ------------------------------------------------*/
#define NISWITCH_ATTR_SCAN_LIST                     IVISWTCH_ATTR_SCAN_LIST                 /* ViString */
#define NISWITCH_ATTR_SCAN_MODE                     IVISWTCH_ATTR_SCAN_MODE                 /* ViInt32  */
#define NISWITCH_ATTR_TRIGGER_INPUT                 IVISWTCH_ATTR_TRIGGER_INPUT             /* ViInt32  */
#define NISWITCH_ATTR_SCAN_ADVANCED_OUTPUT          IVISWTCH_ATTR_SCAN_ADVANCED_OUTPUT      /* ViInt32  */
#define NISWITCH_ATTR_SCAN_DELAY                    IVISWTCH_ATTR_SCAN_DELAY                /* ViReal64 */
#define NISWITCH_ATTR_CONTINUOUS_SCAN               IVISWTCH_ATTR_CONTINUOUS_SCAN           /* ViBoolean */
#define NISWITCH_ATTR_IS_SCANNING                   IVISWTCH_ATTR_IS_SCANNING               /* ViBoolean, read-only */

    /*- niSwitch specific driver attributes --------------------------------*/
#define NISWITCH_ATTR_IS_WAITING_FOR_TRIG             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4L)    /* ViBoolean, read-only */
#define NISWITCH_ATTR_TRIGGER_MODE                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 5L)    /* ViInt32  */
#define NISWITCH_ATTR_MASTER_SLAVE_TRIGGER_BUS        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 6L)    /* ViInt32  */
#define NISWITCH_ATTR_MASTER_SLAVE_SCAN_ADVANCED_BUS  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 7L)    /* ViInt32  */
#define NISWITCH_ATTR_CABLED_MODULE_TRIGGER_BUS       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 8L)    /* ViInt32  */
#define NISWITCH_ATTR_CABLED_MODULE_SCAN_ADVANCED_BUS (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 9L)    /* ViInt32  */
#define NISWITCH_ATTR_TRIGGER_INPUT_POLARITY          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 10L)   /* ViInt32  */
#define NISWITCH_ATTR_SCAN_ADVANCED_POLARITY          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 11L)   /* ViInt32  */
#define NISWITCH_ATTR_PARSED_SCAN_LIST                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 12L)   /* ViString, read-only */
#define NISWITCH_ATTR_HANDSHAKING_INITIATION          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 13L)   /* ViInt32  */
#define NISWITCH_ATTR_NUMBER_OF_RELAYS                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 14L)   /* ViInt32  */
#define NISWITCH_ATTR_SERIAL_NUMBER                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 15L)   /* ViString, read-only */
#define NISWITCH_ATTR_DIGITAL_FILTER_ENABLE           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 16L)   /* ViBoolean */
#define NISWITCH_ATTR_POWER_DOWN_LATCHING_RELAYS_AFTER_DEBOUNCE  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 17L)   /* ViBoolean */
#define NISWITCH_ATTR_ANALOG_BUS_SHARING_ENABLE       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 18L)   /* ViBoolean, channel-based */
#define NISWITCH_ATTR_TEMPERATURE                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 19L)   /* ViReal64  */


/****************************************************************************
 *------------------------ Attribute Value Defines -------------------------*
 ****************************************************************************/
    /* Defined values for NISWITCH_ATTR_SCAN_MODE */
#define NISWITCH_VAL_NONE                           IVISWTCH_VAL_NONE
#define NISWITCH_VAL_BREAK_BEFORE_MAKE              IVISWTCH_VAL_BREAK_BEFORE_MAKE
#define NISWITCH_VAL_BREAK_AFTER_MAKE               IVISWTCH_VAL_BREAK_AFTER_MAKE

    /* Defined values for NISWITCH_ATTR_TRIGGER_INPUT */
#define NISWITCH_VAL_REARCONNECTOR_MODULE_BASE      (IVISWTCH_VAL_TRIGGER_INPUT_SPECIFIC_EXT_BASE + 20)
#define NISWITCH_VAL_FRONTCONNECTOR_MODULE_BASE     (IVISWTCH_VAL_TRIGGER_INPUT_SPECIFIC_EXT_BASE + 40)

#define NISWITCH_VAL_IMMEDIATE                      IVISWTCH_VAL_IMMEDIATE
#define NISWITCH_VAL_EXTERNAL                       IVISWTCH_VAL_EXTERNAL
#define NISWITCH_VAL_SOFTWARE_TRIG                  IVISWTCH_VAL_SOFTWARE_TRIG
#define NISWITCH_VAL_TTL0                           IVISWTCH_VAL_TTL0
#define NISWITCH_VAL_TTL1                           IVISWTCH_VAL_TTL1
#define NISWITCH_VAL_TTL2                           IVISWTCH_VAL_TTL2
#define NISWITCH_VAL_TTL3                           IVISWTCH_VAL_TTL3
#define NISWITCH_VAL_TTL4                           IVISWTCH_VAL_TTL4
#define NISWITCH_VAL_TTL5                           IVISWTCH_VAL_TTL5
#define NISWITCH_VAL_TTL6                           IVISWTCH_VAL_TTL6
#define NISWITCH_VAL_TTL7                           IVISWTCH_VAL_TTL7
#define NISWITCH_VAL_PXI_STAR                       IVISWTCH_VAL_PXI_STAR
#define NISWITCH_VAL_REARCONNECTOR                  (IVISWTCH_VAL_TRIGGER_INPUT_SPECIFIC_EXT_BASE + 0)
#define NISWITCH_VAL_FRONTCONNECTOR                 (IVISWTCH_VAL_TRIGGER_INPUT_SPECIFIC_EXT_BASE + 1)
#define NISWITCH_VAL_REARCONNECTOR_MODULE1          (NISWITCH_VAL_REARCONNECTOR_MODULE_BASE + 1)
#define NISWITCH_VAL_REARCONNECTOR_MODULE2          (NISWITCH_VAL_REARCONNECTOR_MODULE_BASE + 2)
#define NISWITCH_VAL_REARCONNECTOR_MODULE3          (NISWITCH_VAL_REARCONNECTOR_MODULE_BASE + 3)
#define NISWITCH_VAL_REARCONNECTOR_MODULE4          (NISWITCH_VAL_REARCONNECTOR_MODULE_BASE + 4)
#define NISWITCH_VAL_REARCONNECTOR_MODULE5          (NISWITCH_VAL_REARCONNECTOR_MODULE_BASE + 5)
#define NISWITCH_VAL_REARCONNECTOR_MODULE6          (NISWITCH_VAL_REARCONNECTOR_MODULE_BASE + 6)
#define NISWITCH_VAL_REARCONNECTOR_MODULE7          (NISWITCH_VAL_REARCONNECTOR_MODULE_BASE + 7)
#define NISWITCH_VAL_REARCONNECTOR_MODULE8          (NISWITCH_VAL_REARCONNECTOR_MODULE_BASE + 8)
#define NISWITCH_VAL_REARCONNECTOR_MODULE9          (NISWITCH_VAL_REARCONNECTOR_MODULE_BASE + 9)
#define NISWITCH_VAL_REARCONNECTOR_MODULE10         (NISWITCH_VAL_REARCONNECTOR_MODULE_BASE + 10)
#define NISWITCH_VAL_REARCONNECTOR_MODULE11         (NISWITCH_VAL_REARCONNECTOR_MODULE_BASE + 11)
#define NISWITCH_VAL_REARCONNECTOR_MODULE12         (NISWITCH_VAL_REARCONNECTOR_MODULE_BASE + 12)
#define NISWITCH_VAL_FRONTCONNECTOR_MODULE1         (NISWITCH_VAL_FRONTCONNECTOR_MODULE_BASE + 1)
#define NISWITCH_VAL_FRONTCONNECTOR_MODULE2         (NISWITCH_VAL_FRONTCONNECTOR_MODULE_BASE + 2)
#define NISWITCH_VAL_FRONTCONNECTOR_MODULE3         (NISWITCH_VAL_FRONTCONNECTOR_MODULE_BASE + 3)
#define NISWITCH_VAL_FRONTCONNECTOR_MODULE4         (NISWITCH_VAL_FRONTCONNECTOR_MODULE_BASE + 4)
#define NISWITCH_VAL_FRONTCONNECTOR_MODULE5         (NISWITCH_VAL_FRONTCONNECTOR_MODULE_BASE + 5)
#define NISWITCH_VAL_FRONTCONNECTOR_MODULE6         (NISWITCH_VAL_FRONTCONNECTOR_MODULE_BASE + 6)
#define NISWITCH_VAL_FRONTCONNECTOR_MODULE7         (NISWITCH_VAL_FRONTCONNECTOR_MODULE_BASE + 7)
#define NISWITCH_VAL_FRONTCONNECTOR_MODULE8         (NISWITCH_VAL_FRONTCONNECTOR_MODULE_BASE + 8)
#define NISWITCH_VAL_FRONTCONNECTOR_MODULE9         (NISWITCH_VAL_FRONTCONNECTOR_MODULE_BASE + 9)
#define NISWITCH_VAL_FRONTCONNECTOR_MODULE10        (NISWITCH_VAL_FRONTCONNECTOR_MODULE_BASE + 10)
#define NISWITCH_VAL_FRONTCONNECTOR_MODULE11        (NISWITCH_VAL_FRONTCONNECTOR_MODULE_BASE + 11)
#define NISWITCH_VAL_FRONTCONNECTOR_MODULE12        (NISWITCH_VAL_FRONTCONNECTOR_MODULE_BASE + 12)


/* Defined values for NISWITCH_ATTR_SCAN_ADVANCED_OUTPUT */
/* #define NISWITCH_VAL_NONE                        DEFINED ABOVE */
/* #define NISWITCH_VAL_EXTERNAL                    DEFINED ABOVE */
/* #define NISWITCH_VAL_TTL0                        DEFINED ABOVE */
/* #define NISWITCH_VAL_TTL1                        DEFINED ABOVE */
/* #define NISWITCH_VAL_TTL2                        DEFINED ABOVE */
/* #define NISWITCH_VAL_TTL3                        DEFINED ABOVE */
/* #define NISWITCH_VAL_TTL4                        DEFINED ABOVE */
/* #define NISWITCH_VAL_TTL5                        DEFINED ABOVE */
/* #define NISWITCH_VAL_TTL6                        DEFINED ABOVE */
/* #define NISWITCH_VAL_TTL7                        DEFINED ABOVE */
/* #define NISWITCH_VAL_PXI_STAR                    DEFINED ABOVE */
/* #define NISWITCH_VAL_FRONTCONNECTOR              DEFINED ABOVE */
/* #define NISWITCH_VAL_FRONTCONNECTOR_MODULE1      DEFINED ABOVE */
/* #define NISWITCH_VAL_FRONTCONNECTOR_MODULE2      DEFINED ABOVE */
/* #define NISWITCH_VAL_FRONTCONNECTOR_MODULE3      DEFINED ABOVE */
/* #define NISWITCH_VAL_FRONTCONNECTOR_MODULE4      DEFINED ABOVE */
/* #define NISWITCH_VAL_FRONTCONNECTOR_MODULE5      DEFINED ABOVE */
/* #define NISWITCH_VAL_FRONTCONNECTOR_MODULE6      DEFINED ABOVE */
/* #define NISWITCH_VAL_FRONTCONNECTOR_MODULE7      DEFINED ABOVE */
/* #define NISWITCH_VAL_FRONTCONNECTOR_MODULE8      DEFINED ABOVE */
/* #define NISWITCH_VAL_FRONTCONNECTOR_MODULE9      DEFINED ABOVE */
/* #define NISWITCH_VAL_FRONTCONNECTOR_MODULE10     DEFINED ABOVE */
/* #define NISWITCH_VAL_FRONTCONNECTOR_MODULE11     DEFINED ABOVE */
/* #define NISWITCH_VAL_FRONTCONNECTOR_MODULE12     DEFINED ABOVE */

    /* Defined values for NISWITCH_ATTR_WIRE_MODE */
#define NISWITCH_VAL_1_WIRE                         1
#define NISWITCH_VAL_2_WIRE                         2
#define NISWITCH_VAL_4_WIRE                         4

    /* Defined values for niSwitch_CanConnect path capability parameter */
#define NISWITCH_VAL_PATH_AVAILABLE                 IVISWTCH_VAL_PATH_AVAILABLE
#define NISWITCH_VAL_PATH_EXISTS                    IVISWTCH_VAL_PATH_EXISTS
#define NISWITCH_VAL_PATH_UNSUPPORTED               IVISWTCH_VAL_PATH_UNSUPPORTED
#define NISWITCH_VAL_RSRC_IN_USE                    IVISWTCH_VAL_RSRC_IN_USE
#define NISWITCH_VAL_SOURCE_CONFLICT                IVISWTCH_VAL_SOURCE_CONFLICT
#define NISWITCH_VAL_CHANNEL_NOT_AVAILABLE          IVISWTCH_VAL_CHANNEL_NOT_AVAILABLE

   /* Defined values for NISWITCH_ATTR_SCAN_ADVANCED_POLARITY and NISWITCH_TRIGGER_INPUT_POLARITY */
#define NISWITCH_VAL_RISING_EDGE                    0
#define NISWITCH_VAL_FALLING_EDGE                   1

    /* Defined values for the NISWITCH_ATTR_TRIGGER_MODE attribute */
#define NISWITCH_VAL_SINGLE                         0
#define NISWITCH_VAL_MASTER                         1
#define NISWITCH_VAL_SLAVE                          2

    /* Defined values for the Scan function */
#define NISWITCH_VAL_MEASUREMENT_DEVICE_INITIATED   0
#define NISWITCH_VAL_DMM_INITIATED                  NISWITCH_VAL_MEASUREMENT_DEVICE_INITIATED
#define NISWITCH_VAL_SWITCH_INITIATED               1

    /* Defined values for the niSwitch_GetRelayPosition's position parameter */
#define NISWITCH_VAL_OPEN                           10
#define NISWITCH_VAL_CLOSED                         11

    /* Defined values for the niSwitch_RelayControl function */
#define NISWITCH_VAL_OPEN_RELAY                     20
#define NISWITCH_VAL_CLOSE_RELAY                    21

/****************************************************************************
 *---------------- Instrument Driver Function Declarations -----------------*
 ****************************************************************************/

    /*- Session Management Functions ---------------------------------------*/
ViStatus _VI_FUNC  niSwitch_init(ViRsrc resourceName,
                                 ViBoolean idQuery,
                                 ViBoolean resetDevice,
                                 ViSession *newVi);
ViStatus _VI_FUNC  niSwitch_InitWithOptions(ViRsrc resourceName,
                                            ViBoolean idQuery,
                                            ViBoolean resetDevice,
                                            ViConstString optionString,
                                            ViSession *newVi);
ViStatus _VI_FUNC  niSwitch_InitWithTopology(ViRsrc resourceName,
                                             ViConstString topology,
                                             ViBoolean simulate,
                                             ViBoolean resetDevice,
                                             ViSession *newVi);

ViStatus _VI_FUNC  niSwitch_close(ViSession vi);

    /*- Locking Functions --------------------------------------------------*/
ViStatus _VI_FUNC  niSwitch_LockSession(ViSession vi,
                                        ViBoolean *callerHasLock);
ViStatus _VI_FUNC  niSwitch_UnlockSession(ViSession vi,
                                          ViBoolean *callerHasLock);

    /*- Switch Routing Functions -------------------------------------------*/
ViStatus _VI_FUNC niSwitch_Connect(ViSession vi,
                                   ViConstString channel1,
                                   ViConstString channel2);
ViStatus _VI_FUNC niSwitch_ConnectMultiple(ViSession vi,
                                           ViConstString connectionList);
ViStatus _VI_FUNC niSwitch_Disconnect(ViSession vi,
                                      ViConstString channel1,
                                      ViConstString channel2);
ViStatus _VI_FUNC niSwitch_DisconnectMultiple(ViSession vi,
                                              ViConstString disconnectionList);
ViStatus _VI_FUNC niSwitch_DisconnectAll(ViSession vi);
ViStatus _VI_FUNC niSwitch_GetPath(ViSession vi,
                                   ViConstString channel1,
                                   ViConstString channel2,
                                   ViInt32 bufferSize,
                                   ViChar pathList[]);
ViStatus _VI_FUNC niSwitch_SetPath(ViSession vi,
                                   ViConstString pathList);
ViStatus _VI_FUNC niSwitch_CanConnect(ViSession vi,
                                      ViConstString channel1,
                                      ViConstString channel2,
                                      ViInt32 *pathCapability);
ViStatus _VI_FUNC niSwitch_IsDebounced(ViSession vi,
                                       ViBoolean* isDebounced);
ViStatus _VI_FUNC niSwitch_WaitForDebounce(ViSession vi,
                                           ViInt32 maxTime);

    /*- Scanning Functions -------------------------------------------------*/
ViStatus _VI_FUNC  niSwitch_Scan(ViSession vi,
                                 ViConstString scanList,
                                 ViInt16 initiation);
ViStatus _VI_FUNC  niSwitch_InitiateScan(ViSession vi);
ViStatus _VI_FUNC  niSwitch_AbortScan(ViSession vi);
ViStatus _VI_FUNC  niSwitch_IsScanning(ViSession vi,
                                       ViBoolean* isScanning);
ViStatus _VI_FUNC  niSwitch_WaitForScanComplete(ViSession vi,
                                                ViInt32 maxTime);
ViStatus _VI_FUNC  niSwitch_SendSoftwareTrigger(ViSession vi);
ViStatus _VI_FUNC  niSwitch_ConfigureScanList(ViSession vi,
                                              ViConstString scanList,
                                              ViInt32 scanMode);
ViStatus _VI_FUNC  niSwitch_ConfigureScanTrigger(ViSession vi,
                                                 ViReal64 scanDelay,
                                                 ViInt32 triggerInput,
                                                 ViInt32 scanAdvancedOutput);
ViStatus _VI_FUNC  niSwitch_SetContinuousScan(ViSession vi,
                                              ViBoolean continuousScan);
ViStatus _VI_FUNC  niSwitch_RouteTriggerInput(ViSession vi,
                                              ViInt32 triggerInputConnector,
                                              ViInt32 triggerInputBusLine,
                                              ViBoolean invert);
ViStatus _VI_FUNC  niSwitch_RouteScanAdvancedOutput(ViSession vi,
                                                    ViInt32 scanAdvancedOutputConnector,
                                                    ViInt32 scanAdvancedOutputBusLine,
                                                    ViBoolean invert);


    /*- Error Functions ----------------------------------------------------*/
ViStatus _VI_FUNC  niSwitch_error_query(ViSession vi,
                                        ViInt32 *errorCode,
                                        ViChar errorMessage[]);
ViStatus _VI_FUNC  niSwitch_GetError(ViSession vi,
                                     ViStatus *errorCode,
                                     ViInt32 bufferSize,
                                     ViChar description[]);
ViStatus _VI_FUNC  niSwitch_ClearError(ViSession vi);
ViStatus _VI_FUNC  niSwitch_error_message(ViSession vi,
                                          ViStatus errorCode,
                                          ViChar errorMessage[256]);

   /*- Channel Info Functions ---------------------------------------------*/
ViStatus _VI_FUNC  niSwitch_GetChannelName(ViSession vi,
                                           ViInt32 index,
                                           ViInt32 bufferSize,
                                           ViChar name[]);

   /*- Relay Operation Functions -------------------------------------------*/
ViStatus _VI_FUNC  niSwitch_GetRelayName(ViSession vi,
                                         ViInt32 index,
                                         ViInt32 bufferSize,
                                         ViChar name[]);
ViStatus _VI_FUNC  niSwitch_GetRelayCount(ViSession vi,
                                          ViConstString relayName,
                                          ViInt32* count);
ViStatus _VI_FUNC  niSwitch_GetRelayPosition(ViSession vi,
                                             ViConstString relayName,
                                             ViInt32* position);
ViStatus _VI_FUNC  niSwitch_RelayControl(ViSession vi,
                                         ViConstString relayNames,
                                         ViInt32 relayAction);

    /*- Interchangeability Checking Functions ------------------------------*/
ViStatus _VI_FUNC  niSwitch_GetNextInterchangeWarning(ViSession vi,
                                                      ViInt32 bufferSize,
                                                      ViChar warnString[]);
ViStatus _VI_FUNC  niSwitch_ResetInterchangeCheck(ViSession vi);
ViStatus _VI_FUNC  niSwitch_ClearInterchangeWarnings(ViSession vi);

    /*- Coercion Functions -------------------------------------------------*/
ViStatus _VI_FUNC  niSwitch_GetNextCoercionRecord(ViSession vi,
                                                  ViInt32 bufferSize,
                                                  ViChar record[]);

    /*- Utility Functions --------------------------------------------------*/
ViStatus _VI_FUNC  niSwitch_Commit(ViSession vi);
ViStatus _VI_FUNC  niSwitch_InvalidateAllAttributes(ViSession vi);
ViStatus _VI_FUNC  niSwitch_ResetWithDefaults(ViSession vi);
ViStatus _VI_FUNC  niSwitch_Disable(ViSession vi);
ViStatus _VI_FUNC  niSwitch_reset(ViSession vi);
ViStatus _VI_FUNC  niSwitch_self_test(ViSession vi,
                                      ViInt16 *selfTestResult,
                                      ViChar selfTestMessage[]);
ViStatus _VI_FUNC  niSwitch_revision_query(ViSession vi,
                                           ViChar instrumentDriverRevision[],
                                           ViChar firmwareRevision[]);

    /*- Set, Get, and Check Attribute Functions ----------------------------*/
ViStatus _VI_FUNC  niSwitch_GetAttributeViInt32(ViSession vi, ViConstString channelName, ViAttr attribute, ViInt32 *value);
ViStatus _VI_FUNC  niSwitch_GetAttributeViReal64(ViSession vi, ViConstString channelName, ViAttr attribute, ViReal64 *value);
ViStatus _VI_FUNC  niSwitch_GetAttributeViString(ViSession vi, ViConstString channelName, ViAttr attribute, ViInt32 bufferSize, ViChar value[]);
ViStatus _VI_FUNC  niSwitch_GetAttributeViSession(ViSession vi, ViConstString channelName, ViAttr attribute, ViSession *value);
ViStatus _VI_FUNC  niSwitch_GetAttributeViBoolean(ViSession vi, ViConstString channelName, ViAttr attribute, ViBoolean *value);

ViStatus _VI_FUNC  niSwitch_SetAttributeViInt32(ViSession vi, ViConstString channelName, ViAttr attribute, ViInt32 value);
ViStatus _VI_FUNC  niSwitch_SetAttributeViReal64(ViSession vi, ViConstString channelName, ViAttr attribute, ViReal64 value);
ViStatus _VI_FUNC  niSwitch_SetAttributeViString(ViSession vi, ViConstString channelName, ViAttr attribute, ViConstString value);
ViStatus _VI_FUNC  niSwitch_SetAttributeViSession(ViSession vi, ViConstString channelName, ViAttr attribute, ViSession value);
ViStatus _VI_FUNC  niSwitch_SetAttributeViBoolean(ViSession vi, ViConstString channelName, ViAttr attribute, ViBoolean value);

ViStatus _VI_FUNC  niSwitch_CheckAttributeViInt32(ViSession vi, ViConstString channelName, ViAttr attribute, ViInt32 value);
ViStatus _VI_FUNC  niSwitch_CheckAttributeViReal64(ViSession vi, ViConstString channelName, ViAttr attribute, ViReal64 value);
ViStatus _VI_FUNC  niSwitch_CheckAttributeViString(ViSession vi, ViConstString channelName, ViAttr attribute, ViConstString value);
ViStatus _VI_FUNC  niSwitch_CheckAttributeViSession(ViSession vi, ViConstString channelName, ViAttr attribute, ViSession value);
ViStatus _VI_FUNC  niSwitch_CheckAttributeViBoolean(ViSession vi, ViConstString channelName, ViAttr attribute, ViBoolean value);

/****************************************************************************
 *------------------------ Error And Completion Codes ----------------------*
 ****************************************************************************/

#define NISWITCH_ERROR_SESSION_ALREADY_OPEN                          (IVI_SPECIFIC_ERROR_BASE + 1)
#define NISWITCH_ERROR_INVALID_RESOURCE_DESCRIPTOR                   (IVI_SPECIFIC_ERROR_BASE + 2)
#define NISWITCH_ERROR_SCANNING_NOT_SUPPORTED                        (IVI_SPECIFIC_ERROR_BASE + 3)
#define NISWITCH_ERROR_MUST_SPECIFY_MODULE                           (IVI_SPECIFIC_ERROR_BASE + 4)
#define NISWITCH_ERROR_MODULE_FIFO_LENGTH_EXCEEDED                   (IVI_SPECIFIC_ERROR_BASE + 5)
#define NISWITCH_ERROR_HW_COMMUNICATE_TMO                            (IVI_SPECIFIC_ERROR_BASE + 6)
#define NISWITCH_ERROR_TTL_BUS_REQUIRED                              (IVI_SPECIFIC_ERROR_BASE + 7)
#define NISWITCH_ERROR_MODULE_IS_BBM_ONLY                            (IVI_SPECIFIC_ERROR_BASE + 8)
#define NISWITCH_ERROR_1127_TTL1_CONFLICT                            (IVI_SPECIFIC_ERROR_BASE + 9)
#define NISWITCH_ERROR_INVALID_DRIVER_SETUP_STRING                   (IVI_SPECIFIC_ERROR_BASE + 11)
#define NISWITCH_ERROR_TOPOLOGY_NOT_SUPPORTED                        (IVI_SPECIFIC_ERROR_BASE + 12)
#define NISWITCH_ERROR_INVALID_TOPOLOGY                              (IVI_SPECIFIC_ERROR_BASE + 13)
#define NISWITCH_ERROR_HARDWARE_UNEXPECTEDLY_RESET                   (IVI_SPECIFIC_ERROR_BASE + 14)
#define NISWITCH_ERROR_HANDSHAKING_INITIATION_CONFLICT               (IVI_SPECIFIC_ERROR_BASE + 15)
#define NISWITCH_ERROR_LEGACY_DESCRIPTOR_DAQMX_RSC_TYPE              (IVI_SPECIFIC_ERROR_BASE + 16)
#define NISWITCH_ERROR_DAQMX_DESCRIPTOR_LEGACY_RSC_TYPE              (IVI_SPECIFIC_ERROR_BASE + 17)
#define NISWITCH_ERROR_AMBIGUOUS_MODEL_CODE                          (IVI_SPECIFIC_ERROR_BASE + 18)
#define NISWITCH_ERROR_TRIGGER_INPUT_NOT_SUPPORTED                   (IVI_SPECIFIC_ERROR_BASE + 19)
#define NISWITCH_ERROR_INVALID_TERMINALBLOCK_FOR_TOPOLOGY            (IVI_SPECIFIC_ERROR_BASE + 20)
#define NISWITCH_ERROR_CANT_INVERT_WHEN_SOURCE_EQUALS_DEST           (IVI_SPECIFIC_ERROR_BASE + 21)
#define NISWITCH_ERROR_CONFLICTING_TRIGGER_ROUTE_EXISTS              (IVI_SPECIFIC_ERROR_BASE + 22)
#define NISWITCH_ERROR_INVALID_VALUE_FOR_DEVICE                      (IVI_SPECIFIC_ERROR_BASE + 23)
#define NISWITCH_ERROR_TRIGGER_POLARITY_CONFLICT                     (IVI_SPECIFIC_ERROR_BASE + 24)
#define NISWITCH_ERROR_INTERNAL_ERROR                                (IVI_SPECIFIC_ERROR_BASE + 25)
#define NISWITCH_ERROR_RESET_NEEDED_TO_CHANGE_TOPOLOGY               (IVI_SPECIFIC_ERROR_BASE + 26)
#define NISWITCH_ERROR_RESERVATION_ERROR                             (IVI_SPECIFIC_ERROR_BASE + 27)
#define NISWITCH_ERROR_ANALOG_BUS_INVALID                            (IVI_SPECIFIC_ERROR_BASE + 28)
#define NISWITCH_ERROR_POWER_LIMIT_EXCEEDED                          (IVI_SPECIFIC_ERROR_BASE + 29)
#define NISWITCH_ERROR_DEVICE_SELF_TEST_FAILED                       (IVI_SPECIFIC_ERROR_BASE + 30)
#define NISWITCH_ERROR_CARD_DETECTED_DOES_NOT_MATCH_EXPECTED_CARD    (IVI_SPECIFIC_ERROR_BASE + 31)
#define NISWITCH_ERROR_ANALOG_BUS_STATE_INCONSISTENT                 (IVI_SPECIFIC_ERROR_BASE + 32)
#define NISWITCH_ERROR_FIVE_VOLT_DETECT_FAILED                       (IVI_SPECIFIC_ERROR_BASE + 33)
#define NISWITCH_ERROR_SLOT_POWER_LIMIT_EXCEEDED                     (IVI_SPECIFIC_ERROR_BASE + 34)
#define NISWITCH_ERROR_CANNOT_EXCEED_RELAY_DRIVE_LIMIT               (IVI_SPECIFIC_ERROR_BASE + 35)
#define NISWITCH_ERROR_INVALID_CONNECTION_LIST                       (IVI_SPECIFIC_ERROR_BASE + 36)
#define NISWITCH_ERROR_DISCONNECTION_PATH_NOT_SAME_AS_EXISTING_PATH  (IVI_SPECIFIC_ERROR_BASE + 37)
#define NISWITCH_ERROR_INVALID_RELAY_NAME                            (IVI_SPECIFIC_ERROR_BASE + 38)
#define NISWITCH_ERROR_ANALOG_BUS_SHARING_DIFFERENT_WIRE_MODES       (IVI_SPECIFIC_ERROR_BASE + 39)
#define NISWITCH_ERROR_DEVICE_NO_LONGER_SUPPORTED                    (IVI_SPECIFIC_ERROR_BASE + 40)

#define NISWITCH_WARN_PATH_REMAINS                       IVISWTCH_WARN_PATH_REMAINS
#define NISWITCH_WARN_IMPLICIT_CONNECTION_EXISTS         IVISWTCH_WARN_IMPLICIT_CONNECTION_EXISTS

#define NISWITCH_ERROR_INVALID_SWITCH_PATH               IVISWTCH_ERROR_INVALID_SWITCH_PATH
#define NISWITCH_ERROR_INVALID_SCAN_LIST                 IVISWTCH_ERROR_INVALID_SCAN_LIST
#define NISWITCH_ERROR_RSRC_IN_USE                       IVISWTCH_ERROR_RSRC_IN_USE
#define NISWITCH_ERROR_EMPTY_SCAN_LIST                   IVISWTCH_ERROR_EMPTY_SCAN_LIST
#define NISWITCH_ERROR_EMPTY_SWITCH_PATH                 IVISWTCH_ERROR_EMPTY_SWITCH_PATH
#define NISWITCH_ERROR_SCAN_IN_PROGRESS                  IVISWTCH_ERROR_SCAN_IN_PROGRESS
#define NISWITCH_ERROR_NO_SCAN_IN_PROGRESS               IVISWTCH_ERROR_NO_SCAN_IN_PROGRESS
#define NISWITCH_ERROR_NO_SUCH_PATH                      IVISWTCH_ERROR_NO_SUCH_PATH
#define NISWITCH_ERROR_IS_CONFIGURATION_CHANNEL          IVISWTCH_ERROR_IS_CONFIGURATION_CHANNEL
#define NISWITCH_ERROR_NOT_A_CONFIGURATION_CHANNEL       IVISWTCH_ERROR_NOT_A_CONFIGURATION_CHANNEL
#define NISWITCH_ERROR_ATTEMPT_TO_CONNECT_SOURCES        IVISWTCH_ERROR_ATTEMPT_TO_CONNECT_SOURCES
#define NISWITCH_ERROR_EXPLICIT_CONNECTION_EXISTS        IVISWTCH_ERROR_EXPLICIT_CONNECTION_EXISTS
#define NISWITCH_ERROR_LEG_MISSING_FIRST_CHANNEL         IVISWTCH_ERROR_LEG_MISSING_FIRST_CHANNEL
#define NISWITCH_ERROR_LEG_MISSING_SECOND_CHANNEL        IVISWTCH_ERROR_LEG_MISSING_SECOND_CHANNEL
#define NISWITCH_ERROR_CHANNEL_DUPLICATED_IN_LEG         IVISWTCH_ERROR_CHANNEL_DUPLICATED_IN_LEG
#define NISWITCH_ERROR_CHANNEL_DUPLICATED_IN_PATH        IVISWTCH_ERROR_CHANNEL_DUPLICATED_IN_PATH
#define NISWITCH_ERROR_PATH_NOT_FOUND                    IVISWTCH_ERROR_PATH_NOT_FOUND
#define NISWITCH_ERROR_DISCONTINUOUS_PATH                IVISWTCH_ERROR_DISCONTINUOUS_PATH
#define NISWITCH_ERROR_CANNOT_CONNECT_DIRECTLY           IVISWTCH_ERROR_CANNOT_CONNECT_DIRECTLY
#define NISWITCH_ERROR_CHANNELS_ALREADY_CONNECTED        IVISWTCH_ERROR_CHANNELS_ALREADY_CONNECTED
#define NISWITCH_ERROR_CANNOT_CONNECT_TO_ITSELF          IVISWTCH_ERROR_CANNOT_CONNECT_TO_ITSELF

#ifdef IVISWTCH_ERROR_MAX_TIME_EXCEEDED
 #define NISWITCH_ERROR_MAX_TIME_EXCEEDED          IVISWTCH_ERROR_MAX_TIME_EXCEEDED
#else
 #define NISWITCH_ERROR_MAX_TIME_EXCEEDED          (IVI_CLASS_ERROR_BASE + 22L)
#endif

#define NISWITCH_ERROR_TRIGGER_NOT_SOFTWARE        IVISWTCH_ERROR_TRIGGER_NOT_SOFTWARE

    /*- Obsolete Instrument Driver Values, Attributes and functions -*/
    /*- These attributes and functions have been deprecated and may not
        be supported in future versions of this driver.
    -*/
#define niSwitch_SwitchSwitch                       niSwitch_SingleSwitchControl
#define NISWITCH_ATTR_QUERY_INSTR_STATUS            NISWITCH_ATTR_QUERY_INSTRUMENT_STATUS
    /*- Driver Information -*/
#define NISWITCH_ATTR_SPECIFIC_PREFIX               IVI_ATTR_SPECIFIC_PREFIX
#define NISWITCH_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION IVI_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION
#define NISWITCH_ATTR_SPECIFIC_DRIVER_MINOR_VERSION IVI_ATTR_SPECIFIC_DRIVER_MINOR_VERSION
    /*- IVI Engine Information -*/
#define NISWITCH_ATTR_ENGINE_MAJOR_VERSION          IVI_ATTR_ENGINE_MAJOR_VERSION
#define NISWITCH_ATTR_ENGINE_MINOR_VERSION          IVI_ATTR_ENGINE_MINOR_VERSION
#define NISWITCH_ATTR_ENGINE_REVISION               IVI_ATTR_ENGINE_REVISION
    /*- Error Info -*/
#define NISWITCH_ATTR_PRIMARY_ERROR                 IVI_ATTR_PRIMARY_ERROR
#define NISWITCH_ATTR_SECONDARY_ERROR               IVI_ATTR_SECONDARY_ERROR
#define NISWITCH_ATTR_ERROR_ELABORATION             IVI_ATTR_ERROR_ELABORATION
    /*- Advanced Session Information -*/
#define NISWITCH_ATTR_IO_SESSION_TYPE               IVI_ATTR_IO_SESSION_TYPE
#define NISWITCH_ATTR_IO_SESSION                    IVI_ATTR_IO_SESSION
    /*- Deprecated Attribute Identifiers for Renamed Attributes -*/
#define NISWITCH_ATTR_NUM_CHANNELS                  NISWITCH_ATTR_CHANNEL_COUNT
#define NISWITCH_ATTR_QUERY_INSTR_STATUS            NISWITCH_ATTR_QUERY_INSTRUMENT_STATUS
#define NISWITCH_ATTR_RESOURCE_DESCRIPTOR           NISWITCH_ATTR_IO_RESOURCE_DESCRIPTOR
    /* Version Info */
#define NISWITCH_ATTR_DRIVER_MAJOR_VERSION          IVI_ATTR_DRIVER_MAJOR_VERSION
#define NISWITCH_ATTR_DRIVER_MINOR_VERSION          IVI_ATTR_DRIVER_MINOR_VERSION
#define NISWITCH_ATTR_DRIVER_REVISION               IVI_ATTR_DRIVER_REVISION
    /* Serial number - ViInt32 version */
#define NISWITCH_ATTR_SERIAL_NUMBER_I32             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1L)
    /* Software Trigger */
#define NISWITCH_VAL_SW_TRIG_FUNC                   IVISWTCH_VAL_SOFTWARE_TRIG
    /* Other deprecated values */
#define NISWITCH_VAL_ECL0                           IVISWTCH_VAL_ECL0
#define NISWITCH_VAL_ECL1                           IVISWTCH_VAL_ECL1

#define NISWITCH_ERROR_SCANLIST_NOT_SPECIFIED       (IVI_SPECIFIC_ERROR_BASE + 10)

    /*- Deprecated Send Software Trigger function -*/
ViStatus _VI_FUNC  niSwitch_SendSWTrigger(ViSession vi);

    /*- Deprecated Error Information functions -*/
ViStatus _VI_FUNC  niSwitch_GetErrorInfo(ViSession vi, ViStatus *primaryError, ViStatus *secondaryError, ViChar errorElaboration[256]);
ViStatus _VI_FUNC  niSwitch_ClearErrorInfo(ViSession vi);

    /*- Deprecated Single Switch Control Functions ------------------------------------*/
ViStatus _VI_FUNC  niSwitch_SingleSwitchControl(ViSession vi, ViConstString switchName, ViInt16 switchAction);
ViStatus _VI_FUNC  niSwitch_SingleSwitchQuery(ViSession vi, ViConstString switchName, ViInt16 *switchState);

    /*- Deprecated Calibration Functions ----------------------------------------------*/
ViStatus _VI_FUNC  niSwitch_CalibrationDataWrite(ViSession vi,
                                                 ViConstString channel,
                                                 ViInt32 field,
                                                 ViReal64 calData);
ViStatus _VI_FUNC  niSwitch_CalibrationDataRead(ViSession vi,
                                                ViConstString channel,
                                                ViInt32 field,
                                                ViReal64 *calData,
                                                ViInt32 *year,
                                                ViInt32 *month,
                                                ViInt32 *day);


    /* Deprecated defined values for the niSwitch_SingleSwitchControl and */
    /* niSwitch_SingleSwitchQuery operations */
#define NISWITCH_VAL_SWITCH_OPEN                    0
#define NISWITCH_VAL_SWITCH_CLOSE                   1
#define NISWITCH_VAL_SWITCH_CLOSED                  NISWITCH_VAL_SWITCH_CLOSE

    /* Deprecated defined values for the calibration values */
#define NISWITCH_VAL_CALIBRATION_CJS_AMP            0x00000001
#define NISWITCH_VAL_CALIBRATION_CHANNEL_AMP        0x08000001

/****************************************************************************
 *---------------------------- End Include File ----------------------------*
 ****************************************************************************/
#ifdef __cplusplus
    }
#endif

#endif // ___niswitch_h___

