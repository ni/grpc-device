/****************************************************************************
 *                                NI-Sync
 *---------------------------------------------------------------------------
 *   Copyright (c) National Instruments 2003-2018.  All Rights Reserved.
 *---------------------------------------------------------------------------
 *
 * Title:    niSync.h
 * Purpose:  NI-Sync
 *           Instrument Driver Declarations.
 *
 ****************************************************************************/

#ifndef __NISYNC_HEADER
#define __NISYNC_HEADER

#ifndef NIVISA_PXI
#define NIVISA_PXI
#endif

#include <visa.h>

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

/****************************************************************************
 *----------------- Instrument Driver Revision Information -----------------*
 ****************************************************************************/
#define NISYNC_MAJOR_VERSION                 21 /* Inst. driver major version */
#define NISYNC_MINOR_VERSION                 0 /* Inst. driver minor version */

/****************************************************************************
 *---------------------------- Attribute Defines ---------------------------*
 ****************************************************************************/
#define NISYNC_ATTR_BASE                     1150000 /* IVI_SPECIFIC_PUBLIC_ATTR_BASE */

/* Interface attributes */
#define NISYNC_ATTR_INTF_NUM                 (NISYNC_ATTR_BASE + 0L)    /* ViInt32 */
#define NISYNC_ATTR_SERIAL_NUM               (NISYNC_ATTR_BASE + 1L)    /* ViInt32 */

/* Calibration Attributes */
#define NISYNC_ATTR_PFI0_THRESHOLD           (NISYNC_ATTR_BASE + 100L)  /* ViReal64 */
#define NISYNC_ATTR_PFI1_THRESHOLD           (NISYNC_ATTR_BASE + 101L)  /* ViReal64 */
#define NISYNC_ATTR_PFI2_THRESHOLD           (NISYNC_ATTR_BASE + 102L)  /* ViReal64 */
#define NISYNC_ATTR_PFI3_THRESHOLD           (NISYNC_ATTR_BASE + 103L)  /* ViReal64 */
#define NISYNC_ATTR_PFI4_THRESHOLD           (NISYNC_ATTR_BASE + 104L)  /* ViReal64 */
#define NISYNC_ATTR_PFI5_THRESHOLD           (NISYNC_ATTR_BASE + 105L)  /* ViReal64 */
#define NISYNC_ATTR_OSCILLATOR_VOLTAGE       (NISYNC_ATTR_BASE + 106L)  /* ViReal64 */
#define NISYNC_ATTR_CLK10_PHASE_ADJUST       (NISYNC_ATTR_BASE + 107L)  /* ViReal64 */
#define NISYNC_ATTR_DDS_VCXO_VOLTAGE         (NISYNC_ATTR_BASE + 108L)  /* ViReal64 */
#define NISYNC_ATTR_DDS_PHASE_ADJUST         (NISYNC_ATTR_BASE + 109L)  /* ViReal64 */
#define NISYNC_ATTR_PFI0_1KOHM_ENABLE        (NISYNC_ATTR_BASE + 110L)  /* ViBoolean */
#define NISYNC_ATTR_PFI1_1KOHM_ENABLE        (NISYNC_ATTR_BASE + 111L)  /* ViBoolean */
#define NISYNC_ATTR_PFI2_1KOHM_ENABLE        (NISYNC_ATTR_BASE + 112L)  /* ViBoolean */
#define NISYNC_ATTR_PFI3_1KOHM_ENABLE        (NISYNC_ATTR_BASE + 113L)  /* ViBoolean */
#define NISYNC_ATTR_PFI4_1KOHM_ENABLE        (NISYNC_ATTR_BASE + 114L)  /* ViBoolean */
#define NISYNC_ATTR_PFI5_1KOHM_ENABLE        (NISYNC_ATTR_BASE + 115L)  /* ViBoolean */
#define NISYNC_ATTR_PFI0_10KOHM_ENABLE       (NISYNC_ATTR_BASE + 116L)  /* ViBoolean */
#define NISYNC_ATTR_PFI1_10KOHM_ENABLE       (NISYNC_ATTR_BASE + 117L)  /* ViBoolean */
#define NISYNC_ATTR_PFI2_10KOHM_ENABLE       (NISYNC_ATTR_BASE + 118L)  /* ViBoolean */
#define NISYNC_ATTR_PFI3_10KOHM_ENABLE       (NISYNC_ATTR_BASE + 119L)  /* ViBoolean */
#define NISYNC_ATTR_PFI4_10KOHM_ENABLE       (NISYNC_ATTR_BASE + 120L)  /* ViBoolean */
#define NISYNC_ATTR_PFI5_10KOHM_ENABLE       (NISYNC_ATTR_BASE + 121L)  /* ViBoolean */

/* Synchronization Clock Attributes */
#define NISYNC_ATTR_FRONT_SYNC_CLK_SRC       (NISYNC_ATTR_BASE + 200L)  /* ViString */
#define NISYNC_ATTR_REAR_SYNC_CLK_SRC        (NISYNC_ATTR_BASE + 201L)  /* ViString */
#define NISYNC_ATTR_SYNC_CLK_DIV1            (NISYNC_ATTR_BASE + 202L)  /* ViInt32 */
#define NISYNC_ATTR_SYNC_CLK_DIV2            (NISYNC_ATTR_BASE + 203L)  /* ViInt32 */
#define NISYNC_ATTR_SYNC_CLK_RST_PXITRIG_NUM (NISYNC_ATTR_BASE + 204L)  /* ViString */
#define NISYNC_ATTR_SYNC_CLK_PFI0_FREQ       (NISYNC_ATTR_BASE + 205L)  /* ViReal64 */
#define NISYNC_ATTR_SYNC_CLK_RST_DDS_CNTR_ON_PXITRIG  (NISYNC_ATTR_BASE + 206L)     /* ViBoolean */
#define NISYNC_ATTR_SYNC_CLK_RST_PFI0_CNTR_ON_PXITRIG (NISYNC_ATTR_BASE + 207L)     /* ViBoolean */
#define NISYNC_ATTR_SYNC_CLK_RST_CLK10_CNTR_ON_PXITRIG   (NISYNC_ATTR_BASE + 208L)  /* ViBoolean */

/* Trigger State Attributes */
#define NISYNC_ATTR_TERMINAL_STATE_PXISTAR               (NISYNC_ATTR_BASE + 300L)  /* ViInt32 */
#define NISYNC_ATTR_TERMINAL_STATE_PXITRIG               (NISYNC_ATTR_BASE + 301L)  /* ViInt32 */
#define NISYNC_ATTR_TERMINAL_STATE_PFI                   (NISYNC_ATTR_BASE + 302L)  /* ViInt32 */
#define NISYNC_ATTR_TERMINAL_STATE_PXIEDSTARC            (NISYNC_ATTR_BASE + 303L)  /* ViInt32 */
#define NISYNC_ATTR_TERMINAL_STATE_PFILVDS               (NISYNC_ATTR_BASE + 304L)  /* ViInt32 */
#define NISYNC_ATTR_TERMINAL_STATE_PXIEDSTARCPERIPHERAL  (NISYNC_ATTR_BASE + 305L)  /* ViBoolean */
#define NISYNC_ATTR_TERMINAL_STATE_PXIEDSTARBPERIPHERAL  (NISYNC_ATTR_BASE + 306L)  /* ViBoolean */
#define NISYNC_ATTR_TERMINAL_STATE_PXISTARPERIPHERAL     (NISYNC_ATTR_BASE + 307L)  /* ViBoolean */

/* DDS Attributes */
#define NISYNC_ATTR_DDS_FREQ                 (NISYNC_ATTR_BASE + 400L)  /* ViReal64 */
#define NISYNC_ATTR_DDS_UPDATE_SOURCE        (NISYNC_ATTR_BASE + 401L)  /* ViString */
#define NISYNC_ATTR_DDS_INITIAL_DELAY        (NISYNC_ATTR_BASE + 402L)  /* ViReal64 */

/* Clk Attributes */
#define NISYNC_ATTR_CLKIN_PLL_FREQ            (NISYNC_ATTR_BASE + 500L)  /* ViReal64 */
#define NISYNC_ATTR_CLKIN_USE_PLL             (NISYNC_ATTR_BASE + 501L)  /* ViBoolean */
#define NISYNC_ATTR_CLKIN_PLL_LOCKED          (NISYNC_ATTR_BASE + 502L)  /* ViBoolean */
#define NISYNC_ATTR_CLKOUT_GAIN_ENABLE        (NISYNC_ATTR_BASE + 503L)  /* ViBoolean */
#define NISYNC_ATTR_PXICLK10_PRESENT          (NISYNC_ATTR_BASE + 504L)  /* ViBoolean */
#define NISYNC_ATTR_CLKIN_ATTENUATION_DISABLE (NISYNC_ATTR_BASE + 505L)  /* ViBoolean */

/* User LED Attributes */
#define NISYNC_ATTR_USER_LED_STATE           (NISYNC_ATTR_BASE + 600L)  /* ViBoolean */

/* 1588 Attributes */
#define NISYNC_ATTR_1588_IP_ADDRESS                  (NISYNC_ATTR_BASE + 700L)  /* ViString */
#define NISYNC_ATTR_1588_CLOCK_STATE                 (NISYNC_ATTR_BASE + 712L)  /* ViInt32 */
#define NISYNC_ATTR_1588_CLOCK_ID                    (NISYNC_ATTR_BASE + 729L)  /* ViString */
#define NISYNC_ATTR_1588_CLOCK_CLASS                 (NISYNC_ATTR_BASE + 730L)  /* ViInt32 */
#define NISYNC_ATTR_1588_CLOCK_ACCURACY              (NISYNC_ATTR_BASE + 731L)  /* ViInt32 */
#define NISYNC_ATTR_1588_PRIORITY1                   (NISYNC_ATTR_BASE + 732L)  /* ViInt32 */
#define NISYNC_ATTR_1588_PRIORITY2                   (NISYNC_ATTR_BASE + 733L)  /* ViInt32 */
#define NISYNC_ATTR_1588_GRANDMASTER_CLOCK_ID        (NISYNC_ATTR_BASE + 734L)  /* ViString */
#define NISYNC_ATTR_1588_GRANDMASTER_CLOCK_CLASS     (NISYNC_ATTR_BASE + 735L)  /* ViInt32 */
#define NISYNC_ATTR_1588_GRANDMASTER_CLOCK_ACCURACY  (NISYNC_ATTR_BASE + 736L)  /* ViInt32 */
#define NISYNC_ATTR_1588_GRANDMASTER_PRIORITY1       (NISYNC_ATTR_BASE + 737L)  /* ViInt32 */
#define NISYNC_ATTR_1588_GRANDMASTER_PRIORITY2       (NISYNC_ATTR_BASE + 738L)  /* ViInt32 */
#define NISYNC_ATTR_1588_STEPS_TO_GRANDMASTER        (NISYNC_ATTR_BASE + 716L)  /* ViInt32 */
#define NISYNC_ATTR_1588_LOG_SYNC_INTERVAL           (NISYNC_ATTR_BASE + 739L)  /* ViInt32 */
#define NISYNC_ATTR_1588_MEAN_PATH_DELAY             (NISYNC_ATTR_BASE + 740L)  /* ViReal64 */
#define NISYNC_ATTR_1588_GRANDMASTER_IP_ADDRESS      (NISYNC_ATTR_BASE + 741L)  /* ViString */
#define NISYNC_ATTR_1588_BMCA_MODE                   (NISYNC_ATTR_BASE + 742L)  /* ViInt32 */
#define NISYNC_ATTR_1588_INTERFACE_NAME              (NISYNC_ATTR_BASE + 743L)  /* ViString */

#define NISYNC_ATTR_1588_TIMESTAMP_BUF_SIZE          (NISYNC_ATTR_BASE + 718L)  /* ViInt32 */
#define NISYNC_ATTR_1588_AVAIL_TIMESTAMPS            (NISYNC_ATTR_BASE + 719L)  /* ViInt32 */
#define NISYNC_ATTR_1588_CLK_RESOLUTION              (NISYNC_ATTR_BASE + 720L)  /* ViInt32 */
/* (NISYNC_ATTR_BASE + 770) */

/* Time Reference Attributes */
#define NISYNC_ATTR_TIMEREF_PRESENT               (NISYNC_ATTR_BASE + 800L)  /* ViBoolean */
#define NISYNC_ATTR_TIMEREF_CURRENT               (NISYNC_ATTR_BASE + 801L)  /* ViInt32 */
#define NISYNC_ATTR_TIMEREF_OFFSET                (NISYNC_ATTR_BASE + 802L)  /* ViReal64 */
#define NISYNC_ATTR_TIMEREF_OFFSET_NS             (NISYNC_ATTR_BASE + 808L)  /* ViReal64 */
#define NISYNC_ATTR_TIMEREF_CORRECTION            (NISYNC_ATTR_BASE + 804L)  /* ViReal64 */
#define NISYNC_ATTR_TIMEREF_UTC_OFFSET            (NISYNC_ATTR_BASE + 805L)  /* ViInt32 */
#define NISYNC_ATTR_TIMEREF_UTC_OFFSET_VALID      (NISYNC_ATTR_BASE + 806L)  /* ViBoolean */
#define NISYNC_ATTR_TIMEREF_LAST_SYNC_ID          (NISYNC_ATTR_BASE + 807L)  /* ViInt32 */
#define NISYNC_ATTR_TIMEREF_SELECTED_TYPE         (NISYNC_ATTR_BASE + 809L)  /* ViString */
#define NISYNC_ATTR_TIMEREF_TYPE                  (NISYNC_ATTR_BASE + 810L)  /* ViString */
#define NISYNC_ATTR_TIMEREF_SELECTED_NAME         (NISYNC_ATTR_BASE + 811L)  /* ViString */
#define NISYNC_ATTR_TIMEREF_ENABLED               (NISYNC_ATTR_BASE + 812L)  /* ViBoolean */
#define NISYNC_ATTR_TIMEREF_IS_SELECTED           (NISYNC_ATTR_BASE + 813L)  /* ViBoolean */

/* GPS Attributes */
#define NISYNC_ATTR_GPS_ANTENNA_CONNECTED    (NISYNC_ATTR_BASE + 900L)  /* ViBoolean */
#define NISYNC_ATTR_GPS_RECALCULATE_POSITION (NISYNC_ATTR_BASE + 901L)  /* ViBoolean */
#define NISYNC_ATTR_GPS_SATELLITES_AVAILABLE (NISYNC_ATTR_BASE + 902L)  /* ViInt32 */
#define NISYNC_ATTR_GPS_SELF_SURVEY          (NISYNC_ATTR_BASE + 903L)  /* ViInt32 */
#define NISYNC_ATTR_GPS_MOBILE_MODE          (NISYNC_ATTR_BASE + 904L)  /* ViBoolean */
#define NISYNC_ATTR_GPS_STATUS               (NISYNC_ATTR_BASE + 905L)  /* ViInt32 */

/* Deprecated Attributes - Do not use */
#define NISYNC_ATTR_TIMEREF_CLK_ADJ_OFFSET   (NISYNC_ATTR_BASE + 803L)
#define NISYNC_ATTR_GPS_UTC_OFFSET           (NISYNC_ATTR_BASE + 906L)
#define NISYNC_ATTR_IRIG_TAI_OFFSET          (NISYNC_ATTR_BASE + 1000L)

/* 8021as Attributes */
#define NISYNC_ATTR_8021AS_PORT_STATE                  (NISYNC_ATTR_BASE + 1100L)  /* ViInt32 */
#define NISYNC_ATTR_8021AS_CLOCK_ID                    (NISYNC_ATTR_BASE + 1101L)  /* ViString */
#define NISYNC_ATTR_8021AS_CLOCK_CLASS                 (NISYNC_ATTR_BASE + 1102L)  /* ViInt32 */
#define NISYNC_ATTR_8021AS_CLOCK_ACCURACY              (NISYNC_ATTR_BASE + 1103L)  /* ViInt32 */
#define NISYNC_ATTR_8021AS_PRIORITY1                   (NISYNC_ATTR_BASE + 1104L)  /* ViInt32 */
#define NISYNC_ATTR_8021AS_PRIORITY2                   (NISYNC_ATTR_BASE + 1105L)  /* ViInt32 */
#define NISYNC_ATTR_8021AS_GRANDMASTER_CLOCK_ID        (NISYNC_ATTR_BASE + 1106L)  /* ViString */
#define NISYNC_ATTR_8021AS_GRANDMASTER_CLOCK_CLASS     (NISYNC_ATTR_BASE + 1107L)  /* ViInt32 */
#define NISYNC_ATTR_8021AS_GRANDMASTER_CLOCK_ACCURACY  (NISYNC_ATTR_BASE + 1108L)  /* ViInt32 */
#define NISYNC_ATTR_8021AS_GRANDMASTER_PRIORITY1       (NISYNC_ATTR_BASE + 1109L)  /* ViInt32 */
#define NISYNC_ATTR_8021AS_GRANDMASTER_PRIORITY2       (NISYNC_ATTR_BASE + 1110L)  /* ViInt32 */
#define NISYNC_ATTR_8021AS_LOG_SYNC_INTERVAL           (NISYNC_ATTR_BASE + 1111L)  /* ViInt32 */
#define NISYNC_ATTR_8021AS_LOG_ANNOUNCE_INTERVAL       (NISYNC_ATTR_BASE + 1112L)  /* ViInt32 */
#define NISYNC_ATTR_8021AS_INTERFACE_NAME              (NISYNC_ATTR_BASE + 1113L)  /* ViString */
#define NISYNC_ATTR_8021AS_NEIGHBOR_PROP_DELAY_THRESH  (NISYNC_ATTR_BASE + 1114L)  /* ViInt32 */
#define NISYNC_ATTR_8021AS_AS_CAPABLE                  (NISYNC_ATTR_BASE + 1115L)  /* ViBoolean */

/* NISYNC_ATTR_BASE + 1300L to NISYNC_ATTR_BASE + 1399L is reserved for internal use */

/****************************************************************************
 *------------------------ Attribute Value Defines -------------------------*
 ****************************************************************************/

/* Trigger Terminals Selectors */
#define NISYNC_VAL_PXITRIG0               "PXI_Trig0"
#define NISYNC_VAL_PXITRIG1               "PXI_Trig1"
#define NISYNC_VAL_PXITRIG2               "PXI_Trig2"
#define NISYNC_VAL_PXITRIG3               "PXI_Trig3"
#define NISYNC_VAL_PXITRIG4               "PXI_Trig4"
#define NISYNC_VAL_PXITRIG5               "PXI_Trig5"
#define NISYNC_VAL_PXITRIG6               "PXI_Trig6"
#define NISYNC_VAL_PXITRIG7               "PXI_Trig7"
#define NISYNC_VAL_PXISTAR0               "PXI_Star0"
#define NISYNC_VAL_PXISTAR1               "PXI_Star1"
#define NISYNC_VAL_PXISTAR2               "PXI_Star2"
#define NISYNC_VAL_PXISTAR3               "PXI_Star3"
#define NISYNC_VAL_PXISTAR4               "PXI_Star4"
#define NISYNC_VAL_PXISTAR5               "PXI_Star5"
#define NISYNC_VAL_PXISTAR6               "PXI_Star6"
#define NISYNC_VAL_PXISTAR7               "PXI_Star7"
#define NISYNC_VAL_PXISTAR8               "PXI_Star8"
#define NISYNC_VAL_PXISTAR9               "PXI_Star9"
#define NISYNC_VAL_PXISTAR10              "PXI_Star10"
#define NISYNC_VAL_PXISTAR11              "PXI_Star11"
#define NISYNC_VAL_PXISTAR12              "PXI_Star12"

#define NISYNC_VAL_PXISTAR13              "PXI_Star13"
#define NISYNC_VAL_PXISTAR14              "PXI_Star14"
#define NISYNC_VAL_PXISTAR15              "PXI_Star15"
#define NISYNC_VAL_PXISTAR16              "PXI_Star16"
#define NISYNC_VAL_PXISTAR                "PXI_Star"

#define NISYNC_VAL_PXIEDSTARA0            "PXIe_DStarA0"
#define NISYNC_VAL_PXIEDSTARA1            "PXIe_DStarA1"
#define NISYNC_VAL_PXIEDSTARA2            "PXIe_DStarA2"
#define NISYNC_VAL_PXIEDSTARA3            "PXIe_DStarA3"
#define NISYNC_VAL_PXIEDSTARA4            "PXIe_DStarA4"
#define NISYNC_VAL_PXIEDSTARA5            "PXIe_DStarA5"
#define NISYNC_VAL_PXIEDSTARA6            "PXIe_DStarA6"
#define NISYNC_VAL_PXIEDSTARA7            "PXIe_DStarA7"
#define NISYNC_VAL_PXIEDSTARA8            "PXIe_DStarA8"
#define NISYNC_VAL_PXIEDSTARA9            "PXIe_DStarA9"
#define NISYNC_VAL_PXIEDSTARA10           "PXIe_DStarA10"
#define NISYNC_VAL_PXIEDSTARA11           "PXIe_DStarA11"
#define NISYNC_VAL_PXIEDSTARA12           "PXIe_DStarA12"
#define NISYNC_VAL_PXIEDSTARA13           "PXIe_DStarA13"
#define NISYNC_VAL_PXIEDSTARA14           "PXIe_DStarA14"
#define NISYNC_VAL_PXIEDSTARA15           "PXIe_DStarA15"
#define NISYNC_VAL_PXIEDSTARA16           "PXIe_DStarA16"
#define NISYNC_VAL_PXIEDSTARA             "PXIe_DStarA"

#define NISYNC_VAL_PXIEDSTARB0            "PXIe_DStarB0"
#define NISYNC_VAL_PXIEDSTARB1            "PXIe_DStarB1"
#define NISYNC_VAL_PXIEDSTARB2            "PXIe_DStarB2"
#define NISYNC_VAL_PXIEDSTARB3            "PXIe_DStarB3"
#define NISYNC_VAL_PXIEDSTARB4            "PXIe_DStarB4"
#define NISYNC_VAL_PXIEDSTARB5            "PXIe_DStarB5"
#define NISYNC_VAL_PXIEDSTARB6            "PXIe_DStarB6"
#define NISYNC_VAL_PXIEDSTARB7            "PXIe_DStarB7"
#define NISYNC_VAL_PXIEDSTARB8            "PXIe_DStarB8"
#define NISYNC_VAL_PXIEDSTARB9            "PXIe_DStarB9"
#define NISYNC_VAL_PXIEDSTARB10           "PXIe_DStarB10"
#define NISYNC_VAL_PXIEDSTARB11           "PXIe_DStarB11"
#define NISYNC_VAL_PXIEDSTARB12           "PXIe_DStarB12"
#define NISYNC_VAL_PXIEDSTARB13           "PXIe_DStarB13"
#define NISYNC_VAL_PXIEDSTARB14           "PXIe_DStarB14"
#define NISYNC_VAL_PXIEDSTARB15           "PXIe_DStarB15"
#define NISYNC_VAL_PXIEDSTARB16           "PXIe_DStarB16"
#define NISYNC_VAL_PXIEDSTARB             "PXIe_DStarB"

#define NISYNC_VAL_PXIEDSTARC0            "PXIe_DStarC0"
#define NISYNC_VAL_PXIEDSTARC1            "PXIe_DStarC1"
#define NISYNC_VAL_PXIEDSTARC2            "PXIe_DStarC2"
#define NISYNC_VAL_PXIEDSTARC3            "PXIe_DStarC3"
#define NISYNC_VAL_PXIEDSTARC4            "PXIe_DStarC4"
#define NISYNC_VAL_PXIEDSTARC5            "PXIe_DStarC5"
#define NISYNC_VAL_PXIEDSTARC6            "PXIe_DStarC6"
#define NISYNC_VAL_PXIEDSTARC7            "PXIe_DStarC7"
#define NISYNC_VAL_PXIEDSTARC8            "PXIe_DStarC8"
#define NISYNC_VAL_PXIEDSTARC9            "PXIe_DStarC9"
#define NISYNC_VAL_PXIEDSTARC10           "PXIe_DStarC10"
#define NISYNC_VAL_PXIEDSTARC11           "PXIe_DStarC11"
#define NISYNC_VAL_PXIEDSTARC12           "PXIe_DStarC12"
#define NISYNC_VAL_PXIEDSTARC13           "PXIe_DStarC13"
#define NISYNC_VAL_PXIEDSTARC14           "PXIe_DStarC14"
#define NISYNC_VAL_PXIEDSTARC15           "PXIe_DStarC15"
#define NISYNC_VAL_PXIEDSTARC16           "PXIe_DStarC16"
#define NISYNC_VAL_PXIEDSTARC             "PXIe_DStarC"

#define NISYNC_VAL_PFILVDS0               "PFI_LVDS0"
#define NISYNC_VAL_PFILVDS1               "PFI_LVDS1"
#define NISYNC_VAL_PFILVDS2               "PFI_LVDS2"

#define NISYNC_VAL_PFI0                   "PFI0"
#define NISYNC_VAL_PFI1                   "PFI1"
#define NISYNC_VAL_PFI2                   "PFI2"
#define NISYNC_VAL_PFI3                   "PFI3"
#define NISYNC_VAL_PFI4                   "PFI4"
#define NISYNC_VAL_PFI5                   "PFI5"
#define NISYNC_VAL_GND                    "Ground"
#define NISYNC_VAL_SYNC_CLK_FULLSPEED     "SyncClkFullSpeed"
#define NISYNC_VAL_SYNC_CLK_DIV1          "SyncClkDivided1"
#define NISYNC_VAL_SYNC_CLK_DIV2          "SyncClkDivided2"
/* Trigger Terminal Synchronization Clock Selectors */
#define NISYNC_VAL_SYNC_CLK_ASYNC         "SyncClkAsync"
/* #define NISYNC_VAL_SYNC_CLK_FULLSPEED  DEFINED ABOVE */
/* #define NISYNC_VAL_SYNC_CLK_DIV1       DEFINED ABOVE */
/* #define NISYNC_VAL_SYNC_CLK_DIV2       DEFINED ABOVE */

/* Software Trigger Terminal Selectors */
#define NISYNC_VAL_SWTRIG_GLOBAL          "GlobalSoftwareTrigger"

/* Clock Terminal Selectors */
#define NISYNC_VAL_CLK10                  "PXI_Clk10"
#define NISYNC_VAL_CLK10_IN               "PXI_Clk10_In"
#define NISYNC_VAL_CLKIN                  "ClkIn"
#define NISYNC_VAL_CLKOUT                 "ClkOut"
#define NISYNC_VAL_OSCILLATOR             "Oscillator"
#define NISYNC_VAL_DDS                    "DDS"
#define NISYNC_VAL_CLK100                 "PXIe_Clk100"

/* "All Connected" Terminal Selector */
#define NISYNC_VAL_ALL_CONNECTED          "AllConnected"

/* Synchronization Clock Source Selectors */
/* #define NISYNC_VAL_PFI0                DEFINED ABOVE */
/* #define NISYNC_VAL_CLK10               DEFINED ABOVE */
/* #define NISYNC_VAL_DDS                 DEFINED ABOVE */

/* Trigger Terminal Connection Mode Definitions (invert, updateEdge, etc.) */
#define NISYNC_VAL_DONT_INVERT            (0)
#define NISYNC_VAL_INVERT                 (1)
#define NISYNC_VAL_UPDATE_EDGE_RISING     (0)
#define NISYNC_VAL_UPDATE_EDGE_FALLING    (1)

/* DDS Update Signal Source Selectors */
#define NISYNC_VAL_DDS_UPDATE_IMMEDIATE   "DDS_UpdateImmediate"
/* #define NISYNC_VAL_PXITRIG0            DEFINED ABOVE */
/* #define NISYNC_VAL_PXITRIG1            DEFINED ABOVE */
/* #define NISYNC_VAL_PXITRIG2            DEFINED ABOVE */
/* #define NISYNC_VAL_PXITRIG3            DEFINED ABOVE */
/* #define NISYNC_VAL_PXITRIG4            DEFINED ABOVE */
/* #define NISYNC_VAL_PXITRIG5            DEFINED ABOVE */
/* #define NISYNC_VAL_PXITRIG6            DEFINED ABOVE */
/* #define NISYNC_VAL_PXITRIG7            DEFINED ABOVE */
/* #define NISYNC_VAL_PXISTAR0            DEFINED ABOVE */
/* #define NISYNC_VAL_PXISTAR1            DEFINED ABOVE */
/* #define NISYNC_VAL_PXISTAR2            DEFINED ABOVE */
/* #define NISYNC_VAL_PXISTAR3            DEFINED ABOVE */
/* #define NISYNC_VAL_PXISTAR4            DEFINED ABOVE */
/* #define NISYNC_VAL_PXISTAR5            DEFINED ABOVE */
/* #define NISYNC_VAL_PXISTAR6            DEFINED ABOVE */
/* #define NISYNC_VAL_PXISTAR7            DEFINED ABOVE */
/* #define NISYNC_VAL_PXISTAR8            DEFINED ABOVE */
/* #define NISYNC_VAL_PXISTAR9            DEFINED ABOVE */
/* #define NISYNC_VAL_PXISTAR10           DEFINED ABOVE */
/* #define NISYNC_VAL_PXISTAR11           DEFINED ABOVE */
/* #define NISYNC_VAL_PXISTAR12           DEFINED ABOVE */
/* #define NISYNC_VAL_PFI0                DEFINED ABOVE */
/* #define NISYNC_VAL_PFI1                DEFINED ABOVE */
/* #define NISYNC_VAL_PFI2                DEFINED ABOVE */
/* #define NISYNC_VAL_PFI3                DEFINED ABOVE */
/* #define NISYNC_VAL_PFI4                DEFINED ABOVE */
/* #define NISYNC_VAL_PFI5                DEFINED ABOVE */

/* PCI-1588 Terminal Selectors */
/* #define NISYNC_VAL_PFI0                DEFINED ABOVE */
/* #define NISYNC_VAL_PFI1                DEFINED ABOVE */
/* #define NISYNC_VAL_PFI2                DEFINED ABOVE */
#define NISYNC_VAL_RTSI0                  "RTSI0"
#define NISYNC_VAL_RTSI1                  "RTSI1"
#define NISYNC_VAL_RTSI2                  "RTSI2"
#define NISYNC_VAL_RTSI3                  "RTSI3"
#define NISYNC_VAL_RTSI4                  "RTSI4"
#define NISYNC_VAL_RTSI5                  "RTSI5"
#define NISYNC_VAL_RTSI6                  "RTSI6"
#define NISYNC_VAL_RTSI7                  "RTSI7"
#define NISYNC_VAL_BOARD_CLK              "BoardClk"

/* Initial Time Source Definitions */
#define NISYNC_VAL_INIT_TIME_SRC_SYSTEM_CLK  (0)
#define NISYNC_VAL_INIT_TIME_SRC_MANUAL      (1)

/* Level Definitions (output level) */
#define NISYNC_VAL_LEVEL_LOW             (0)
#define NISYNC_VAL_LEVEL_HIGH            (1)

/* Edge Definitions (activeEdge, detectedEdge ) */
#define NISYNC_VAL_EDGE_RISING              (0)
#define NISYNC_VAL_EDGE_FALLING             (1)
#define NISYNC_VAL_EDGE_ANY                 (2)

/* 1588 Clock State Definitions */
#define NISYNC_VAL_1588_CLK_STATE_NOT_DEFINED   (-1)
#define NISYNC_VAL_1588_CLK_STATE_INIT          (0)
#define NISYNC_VAL_1588_CLK_STATE_FAULT         (1)
#define NISYNC_VAL_1588_CLK_STATE_DISABLE       (2)
#define NISYNC_VAL_1588_CLK_STATE_LISTENING     (3)
#define NISYNC_VAL_1588_CLK_STATE_PREMASTER     (4)
#define NISYNC_VAL_1588_CLK_STATE_MASTER        (5)
#define NISYNC_VAL_1588_CLK_STATE_PASSIVE       (6)
#define NISYNC_VAL_1588_CLK_STATE_UNCALIBRATED  (7)
#define NISYNC_VAL_1588_CLK_STATE_SLAVE         (8)
#define NISYNC_VAL_1588_CLK_STATE_STOPPED       (9)

/* Sync Interval Definitions */
#define NISYNC_VAL_SYNC_INTERVAL_125_MSEC (-3)
#define NISYNC_VAL_SYNC_INTERVAL_250_MSEC (-2)
#define NISYNC_VAL_SYNC_INTERVAL_HALF_SEC (-1)
#define NISYNC_VAL_SYNC_INTERVAL_ONE_SEC  (0)
#define NISYNC_VAL_SYNC_INTERVAL_TWO_SEC  (1)

/* 1588 Clock Accuracy Definitions */
#define NISYNC_VAL_1588_CLK_ACCURACY_UNKNOWN              (0)
#define NISYNC_VAL_1588_CLK_ACCURACY_WITHIN_25_NSEC       (1)
#define NISYNC_VAL_1588_CLK_ACCURACY_WITHIN_100_NSEC      (2)
#define NISYNC_VAL_1588_CLK_ACCURACY_WITHIN_250_NSEC      (3)
#define NISYNC_VAL_1588_CLK_ACCURACY_WITHIN_1_USEC        (4)
#define NISYNC_VAL_1588_CLK_ACCURACY_WITHIN_2500_NSEC     (5)
#define NISYNC_VAL_1588_CLK_ACCURACY_WITHIN_10_USEC       (6)
#define NISYNC_VAL_1588_CLK_ACCURACY_WITHIN_25_USEC       (7)
#define NISYNC_VAL_1588_CLK_ACCURACY_WITHIN_100_USEC      (8)
#define NISYNC_VAL_1588_CLK_ACCURACY_WITHIN_250_USEC      (9)
#define NISYNC_VAL_1588_CLK_ACCURACY_WITHIN_1_MSEC       (10)
#define NISYNC_VAL_1588_CLK_ACCURACY_WITHIN_2500_USEC    (11)
#define NISYNC_VAL_1588_CLK_ACCURACY_WITHIN_10_MSEC      (12)
#define NISYNC_VAL_1588_CLK_ACCURACY_WITHIN_25_MSEC      (13)
#define NISYNC_VAL_1588_CLK_ACCURACY_WITHIN_100_MSEC     (14)
#define NISYNC_VAL_1588_CLK_ACCURACY_WITHIN_250_MSEC     (15)
#define NISYNC_VAL_1588_CLK_ACCURACY_WITHIN_1_SEC        (16)
#define NISYNC_VAL_1588_CLK_ACCURACY_WITHIN_10_SEC       (17)
#define NISYNC_VAL_1588_CLK_ACCURACY_GREATER_THAN_10_SEC (18)

/* 8021AS Clock Accuracy Definitions */
#define NISYNC_VAL_8021AS_CLK_ACCURACY_UNKNOWN              (254)
#define NISYNC_VAL_8021AS_CLK_ACCURACY_WITHIN_25_NSEC       (32)
#define NISYNC_VAL_8021AS_CLK_ACCURACY_WITHIN_100_NSEC      (33)
#define NISYNC_VAL_8021AS_CLK_ACCURACY_WITHIN_250_NSEC      (34)
#define NISYNC_VAL_8021AS_CLK_ACCURACY_WITHIN_1_USEC        (35)
#define NISYNC_VAL_8021AS_CLK_ACCURACY_WITHIN_2500_NSEC     (36)
#define NISYNC_VAL_8021AS_CLK_ACCURACY_WITHIN_10_USEC       (37)
#define NISYNC_VAL_8021AS_CLK_ACCURACY_WITHIN_25_USEC       (38)
#define NISYNC_VAL_8021AS_CLK_ACCURACY_WITHIN_100_USEC      (39)
#define NISYNC_VAL_8021AS_CLK_ACCURACY_WITHIN_250_USEC      (40)
#define NISYNC_VAL_8021AS_CLK_ACCURACY_WITHIN_1_MSEC        (41)
#define NISYNC_VAL_8021AS_CLK_ACCURACY_WITHIN_2500_USEC     (42)
#define NISYNC_VAL_8021AS_CLK_ACCURACY_WITHIN_10_MSEC       (43)
#define NISYNC_VAL_8021AS_CLK_ACCURACY_WITHIN_25_MSEC       (44)
#define NISYNC_VAL_8021AS_CLK_ACCURACY_WITHIN_100_MSEC      (45)
#define NISYNC_VAL_8021AS_CLK_ACCURACY_WITHIN_250_MSEC      (46)
#define NISYNC_VAL_8021AS_CLK_ACCURACY_WITHIN_1_SEC         (47)
#define NISYNC_VAL_8021AS_CLK_ACCURACY_WITHIN_10_SEC        (48)
#define NISYNC_VAL_8021AS_CLK_ACCURACY_GREATER_THAN_10_SEC  (49)

/* IRIG Type Definitions */
#define NISYNC_VAL_IRIG_TYPE_IRIGB_DC   (0)
#define NISYNC_VAL_IRIG_TYPE_IRIGB_AM   (1)

/* GPS Status Definitions */
#define NISYNC_VAL_GPS_UNINITIALIZED            (0)
#define NISYNC_VAL_GPS_ANTENNA_ERROR            (1)
#define NISYNC_VAL_GPS_NO_USEABLE_SATELLITE     (2)
#define NISYNC_VAL_GPS_ONE_USEABLE_SATELLITE    (3)
#define NISYNC_VAL_GPS_TWO_USEABLE_SATELLITES   (4)
#define NISYNC_VAL_GPS_THREE_USEABLE_SATELLITES (5)
#define NISYNC_VAL_GPS_NO_GPS_TIME              (6)
#define NISYNC_VAL_GPS_PDOP_TOO_HIGH            (7)
#define NISYNC_VAL_GPS_UNUSABLE_SATELLITE       (8)
#define NISYNC_VAL_GPS_FIX_REJECTED             (9)
#define NISYNC_VAL_GPS_SELF_SURVEY_COMPLETE     (10)
#define NISYNC_VAL_GPS_SELF_SURVEY_NOT_COMPLETE (11)

/* Time Reference Definitions */
#define NISYNC_VAL_TIMEREF_GPS                 (0)
#define NISYNC_VAL_TIMEREF_IRIG                (1)
#define NISYNC_VAL_TIMEREF_PPS                 (2)
#define NISYNC_VAL_TIMEREF_1588_ORDINARY_CLOCK (3)
#define NISYNC_VAL_TIMEREF_FREERUNNING         (4)
#define NISYNC_VAL_TIMEREF_8021AS              (5)

/* BMCA Mode Definitions */
#define NISYNC_VAL_BMCA_MODE_SLAVE_ONLY        (0)
#define NISYNC_VAL_BMCA_MODE_MASTER_SLAVE      (1)
/* (2) is reserved for internal use */

/* Port State Definitions */
#define NISYNC_VAL_8021AS_PORT_STATE_DISABLED  (3)
#define NISYNC_VAL_8021AS_PORT_STATE_MASTER    (6)
#define NISYNC_VAL_8021AS_PORT_STATE_PASSIVE   (7)
#define NISYNC_VAL_8021AS_PORT_STATE_SLAVE     (9)

/*- Defined values for action in niSync_CloseExtCal()  --------*/
#define NISYNC_VAL_EXT_CAL_ABORT          0L
#define NISYNC_VAL_EXT_CAL_COMMIT         1L

/*- Deprecated value definitions ---------------------------*/
#define NISYNC_VAL_GPS_UNUSEABLE_SATELLITE (8)

/****************************************************************************
 *---------------- Instrument Driver Function Declarations -----------------*
 ****************************************************************************/

/*- Init and Close Functions -------------------------------------------*/
ViStatus _VI_FUNC niSync_init(ViRsrc resourceName,
                              ViBoolean IDQuery,
                              ViBoolean resetDevice,
                              ViSession *vi);
ViStatus _VI_FUNC niSync_close(ViSession vi);

/*- Time Reference Functions -------------------------------------------*/
ViStatus _VI_FUNC niSync_GetTimeReferenceNames(ViSession vi,
                                               ViUInt32 bufferSize,
                                               ViChar timeReferenceNames[]);

/*- Error Functions ----------------------------------------------------*/
ViStatus _VI_FUNC niSync_error_message(ViSession vi,
                                       ViStatus errorCode,
                                       ViChar errorMessage[]);

/*- Utility Functions --------------------------------------------------*/
ViStatus _VI_FUNC niSync_reset(ViSession vi);
ViStatus _VI_FUNC niSync_PersistConfig(ViSession vi);
ViStatus _VI_FUNC niSync_self_test(ViSession vi,
                                   ViInt16* selfTestResult,
                                   ViChar selfTestMessage[]);
ViStatus _VI_FUNC niSync_revision_query(ViSession vi,
                                        ViChar instrumentDriverRevision[],
                                        ViChar firmwareRevision[]);

/*- FPGA Management Functions ------------------------------------------*/
ViStatus _VI_FUNC niSync_ConfigureFPGA(ViSession vi,
                                       ViConstString fpgaProgramPath);

/*- Trigger Terminal Connection Functions -------------------------------*/
ViStatus _VI_FUNC niSync_ConnectTrigTerminals(ViSession vi,
                                              ViConstString srcTerminal,
                                              ViConstString destTerminal,
                                              ViConstString syncClock,
                                              ViInt32 invert,
                                              ViInt32 updateEdge);
ViStatus _VI_FUNC niSync_DisconnectTrigTerminals(ViSession vi,
                                                 ViConstString srcTerminal,
                                                 ViConstString destTerminal);
ViStatus _VI_FUNC niSync_GetTrigTerminalConnectionInfo(ViSession vi,
                                                       ViConstString destTerminal,
                                                       ViChar srcTerminal[256],
                                                       ViChar syncClock[256],
                                                       ViInt32* invert,
                                                       ViInt32* updateEdge);

/*- Software Trigger Connection Functions --------------------------------*/
ViStatus _VI_FUNC niSync_ConnectSWTrigToTerminal(ViSession vi,
                                                 ViConstString srcTerminal,
                                                 ViConstString destTerminal,
                                                 ViConstString syncClock,
                                                 ViInt32 invert,
                                                 ViInt32 updateEdge,
                                                 ViReal64 delay);
ViStatus _VI_FUNC niSync_DisconnectSWTrigFromTerminal(ViSession vi,
                                                      ViConstString srcTerminal,
                                                      ViConstString destTerminal);
ViStatus _VI_FUNC niSync_GetSWTrigConnectionInfo(ViSession vi,
                                                 ViConstString destTerminal,
                                                 ViChar srcTerminal[256],
                                                 ViChar syncClk[256],
                                                 ViInt32* invert,
                                                 ViInt32* updateEdge,
                                                 ViReal64* delay);
ViStatus _VI_FUNC niSync_SendSoftwareTrigger(ViSession vi,
                                             ViConstString srcTerminal);

/*- Clk Terminal Functions -----------------------------------------------*/
ViStatus _VI_FUNC niSync_ConnectClkTerminals(ViSession vi,
                                             ViConstString srcTerminal,
                                             ViConstString destTerminal);
ViStatus _VI_FUNC niSync_DisconnectClkTerminals(ViSession vi,
                                                ViConstString srcTerminal,
                                                ViConstString destTerminal);
ViStatus _VI_FUNC niSync_GetClkTerminalConnectionInfo(ViSession vi,
                                                      ViConstString destTerminal,
                                                      ViChar srcTerminal[256]);

/*- Frequency Counting Functions ---------------------------------------*/
ViStatus _VI_FUNC niSync_MeasureFrequency(ViSession vi,
                                          ViConstString srcTerminal,
                                          ViReal64 duration,
                                          ViReal64* actualDuration,
                                          ViReal64* frequency,
                                          ViReal64* frequencyError);

ViStatus _VI_FUNC niSync_MeasureFrequencyEx(ViSession vi,
                                            ViConstString srcTerminal,
                                            ViReal64 duration,
                                            ViUInt32 decimationCount,
                                            ViReal64* actualDuration,
                                            ViReal64* frequency,
                                            ViReal64* frequencyError);
/*- 1588 Functions -----------------------------------------------------*/

/*- 1588 PTP and Time Functions ----------------------------------------*/
ViStatus _VI_FUNC niSync_Start1588(ViSession vi);
ViStatus _VI_FUNC niSync_Stop1588(ViSession vi);
ViStatus _VI_FUNC niSync_SetTime(ViSession vi,
                                 ViInt32 timeSource,
                                 ViUInt32 timeSeconds,
                                 ViUInt32 timeNanoseconds,
                                 ViUInt16 timeFractionalNanoseconds
                                 );
ViStatus _VI_FUNC niSync_GetTime(ViSession vi,
                                 ViUInt32* timeSeconds,
                                 ViUInt32* timeNanoseconds,
                                 ViUInt16* timeFractionalNanoseconds);

ViStatus _VI_FUNC niSync_ResetFrequency(ViSession vi);

/*- 1588 Future Time Events Functions ---------------------------------*/
ViStatus _VI_FUNC niSync_CreateFutureTimeEvent(ViSession vi,
                                               ViConstString terminal,
                                               ViInt32 outputLevel,
                                               ViUInt32 timeSeconds,
                                               ViUInt32 timeNanoseconds,
                                               ViUInt16 timeFractionalNanoseconds);
ViStatus _VI_FUNC niSync_ClearFutureTimeEvents(ViSession vi,
                                               ViConstString terminal);

/*- 1588 Time Stamping Triggers Functions ------------------------------*/
ViStatus _VI_FUNC niSync_EnableTimeStampTrigger(ViSession     vi,
                                                ViConstString terminal,
                                                ViInt32       activeEdge);
ViStatus _VI_FUNC niSync_EnableTimeStampTriggerWithDecimation(ViSession     vi,
                                                              ViConstString terminal,
                                                              ViInt32       activeEdge,
                                                              ViUInt32      decimationCount);
ViStatus _VI_FUNC niSync_ReadTriggerTimeStamp(ViSession vi,
                                              ViConstString terminal,
                                              ViReal64 timeout,
                                              ViUInt32* timeSeconds,
                                              ViUInt32* timeNanoseconds,
                                              ViUInt16* timeFractionalNanoseconds,
                                              ViInt32* detectedEdge);
ViStatus _VI_FUNC niSync_ReadMultipleTriggerTimeStamp(ViSession       vi,
                                                      ViConstString   terminal,
                                                      ViUInt32        timestampsToRead,
                                                      ViReal64        timeout,
                                                      ViUInt32      * timeSecondsBuffer,
                                                      ViUInt32      * timeNanosecondsBuffer,
                                                      ViUInt16      * timeFractionalNanosecondsBuffer,
                                                      ViInt32       * detectedEdgeBuffer,
                                                      ViUInt32      * timestampsRead);
ViStatus _VI_FUNC niSync_DisableTimeStampTrigger(ViSession vi,
                                                 ViConstString terminal);

/*- 1588 Clock Functions ----------------------------------*/
ViStatus _VI_FUNC niSync_CreateClock(ViSession vi,
                                     ViConstString terminal,
                                     ViUInt32 highTicks,
                                     ViUInt32 lowTicks,
                                     ViUInt32 startTimeSeconds,
                                     ViUInt32 startTimeNanoseconds,
                                     ViUInt16 startTimeFractionalNanoseconds,
                                     ViUInt32 stopTimeSeconds,
                                     ViUInt32 stopTimeNanoseconds,
                                     ViUInt16 stopTimeFractionalNanoseconds);
ViStatus _VI_FUNC niSync_ClearClock(ViSession vi,
                                      ViConstString terminal);

ViStatus _VI_FUNC niSync_Start8021AS(ViSession vi);
ViStatus _VI_FUNC niSync_Stop8021AS(ViSession vi);

/*- External Synchronization Functions ---------------------------------*/
ViStatus _VI_FUNC niSync_SetTimeReferenceFreeRunning(ViSession vi);
ViStatus _VI_FUNC niSync_SetTimeReferenceGPS(ViSession vi);
ViStatus _VI_FUNC niSync_SetTimeReferenceIRIG(ViSession vi,
                                              ViInt32 irigType,
                                              ViConstString terminalName
                                              );
ViStatus _VI_FUNC niSync_SetTimeReferencePPS(ViSession vi,
                                             ViConstString terminalName,
                                             ViBoolean useManualTime,
                                             ViUInt32 initialTimeSeconds,
                                             ViUInt32 initialTimeNanoseconds,
                                             ViUInt16 initialTimeFractionalNanoseconds
                                             );
ViStatus _VI_FUNC niSync_SetTimeReference1588OrdinaryClock(ViSession vi);
ViStatus _VI_FUNC niSync_SetTimeReference8021AS(ViSession vi);


/*- External Synchronization Timestamping Functions---------------------*/
ViStatus _VI_FUNC niSync_EnableGPSTimestamping(ViSession vi);
ViStatus _VI_FUNC niSync_EnableIRIGTimestamping(ViSession vi,
                                                ViInt32 irigType,
                                                ViConstString terminalName
                                                );

ViStatus _VI_FUNC niSync_ReadLastGPSTimestamp(ViSession vi,
                                              ViUInt32* timestampSeconds,
                                              ViUInt32* timestampNanoseconds,
                                              ViUInt16* timestampFractionalNanoseconds,
                                              ViUInt32* gpsSeconds,
                                              ViUInt32* gpsNanoseconds,
                                              ViUInt16* gpsFractionalNanoseconds
                                              );

ViStatus _VI_FUNC niSync_ReadLastIRIGTimestamp(ViSession vi,
                                               ViConstString terminal,
                                               ViUInt32* timestampSeconds,
                                               ViUInt32* timestampNanoseconds,
                                               ViUInt16* timestampFractionalNanoseconds,
                                               ViUInt32* irigbSeconds,
                                               ViUInt32* irigbNanoseconds,
                                               ViUInt16* irigbFractionalNanoseconds
                                               );

ViStatus _VI_FUNC niSync_DisableGPSTimestamping(ViSession vi);

ViStatus _VI_FUNC niSync_DisableIRIGTimestamping(ViSession vi,
                                                 ViConstString terminalName
                                                 );

ViStatus _VI_FUNC niSync_GetVelocity(ViSession vi,
                                     ViReal64* eastVelocity,
                                     ViReal64* northVelocity,
                                     ViReal64* upVelocity
                                     );

ViStatus _VI_FUNC niSync_GetLocation(ViSession vi,
                                     ViReal64* latitude,
                                     ViReal64* longitude,
                                     ViReal64* altitude
                                     );

/*- Attribute Functions ------------------------------------------------*/
ViStatus _VI_FUNC niSync_GetAttributeViInt32(ViSession vi,
                                             ViConstString activeItem,
                                             ViAttr attribute,
                                             ViInt32* value);
ViStatus _VI_FUNC niSync_GetAttributeViReal64(ViSession vi,
                                              ViConstString activeItem,
                                              ViAttr attribute,
                                              ViReal64* value);
ViStatus _VI_FUNC niSync_GetAttributeViBoolean(ViSession vi,
                                               ViConstString activeItem,
                                               ViAttr attribute,
                                               ViBoolean* value);
ViStatus _VI_FUNC niSync_GetAttributeViString(ViSession vi,
                                              ViConstString activeItem,
                                              ViAttr attribute,
                                              ViInt32 bufferSize,
                                              ViChar value[]);

ViStatus _VI_FUNC niSync_SetAttributeViInt32(ViSession vi,
                                             ViConstString activeItem,
                                             ViAttr attribute,
                                             ViInt32 value);
ViStatus _VI_FUNC niSync_SetAttributeViReal64(ViSession vi,
                                              ViConstString activeItem,
                                              ViAttr attribute,
                                              ViReal64 value);
ViStatus _VI_FUNC niSync_SetAttributeViBoolean(ViSession vi,
                                               ViConstString activeItem,
                                               ViAttr attribute,
                                               ViBoolean value);
ViStatus _VI_FUNC niSync_SetAttributeViString(ViSession vi,
                                              ViConstString activeItem,
                                              ViAttr attribute,
                                              ViConstString value);

/*- Calibration Functions ------------------------------------------*/

/*- Calibration Utility Functions ----------------------------------*/
ViStatus _VI_FUNC niSync_GetExtCalLastDateAndTime(ViSession vi,
                                                  ViInt32* year,
                                                  ViInt32* month,
                                                  ViInt32* day,
                                                  ViInt32* hour,
                                                  ViInt32* minute);

ViStatus _VI_FUNC niSync_GetExtCalLastTemp(ViSession vi,
                                           ViReal64* temp);

ViStatus _VI_FUNC niSync_GetExtCalRecommendedInterval(ViSession vi,
                                                      ViInt32* months);

ViStatus _VI_FUNC niSync_ChangeExtCalPassword(ViSession vi,
                                              ViConstString oldPassword,
                                              ViConstString newPassword);

ViStatus _VI_FUNC niSync_ReadCurrentTemperature(ViSession vi,
                                                ViReal64* temperature);

/*- Calibration Data Retrieval Functions-----------------------------*/
ViStatus _VI_FUNC niSync_CalGetOscillatorVoltage(ViSession vi,
                                                 ViReal64* voltage);

ViStatus _VI_FUNC niSync_CalGetClk10PhaseVoltage(ViSession vi,
                                                 ViReal64* voltage);

ViStatus _VI_FUNC niSync_CalGetDDSStartPulsePhaseVoltage(ViSession vi,
                                                         ViReal64* voltage);

ViStatus _VI_FUNC niSync_CalGetDDSInitialPhase(ViSession vi,
                                               ViReal64* phase);

/*- Calibration Session Management Functions (password required)-----*/
ViStatus _VI_FUNC niSync_InitExtCal(ViRsrc resourceName,
                                    ViConstString password,
                                    ViSession* extCalVi);

ViStatus _VI_FUNC niSync_CloseExtCal(ViSession extCalVi,
                                     ViInt32 action);

/*- Calibration Adjustment Functions (password required)--------------*/
ViStatus _VI_FUNC niSync_CalAdjustOscillatorVoltage(ViSession extCalVi,
                                                    ViReal64 measuredVoltage,
                                                    ViReal64* oldVoltage);

ViStatus _VI_FUNC niSync_CalAdjustClk10PhaseVoltage(ViSession extCalVi,
                                                    ViReal64 measuredVoltage,
                                                    ViReal64* oldVoltage);

ViStatus _VI_FUNC niSync_CalAdjustDDSStartPulsePhaseVoltage(ViSession extCalVi,
                                                            ViReal64 measuredVoltage,
                                                            ViReal64* oldVoltage);

ViStatus _VI_FUNC niSync_CalAdjustDDSInitialPhase(ViSession extCalVi,
                                                  ViReal64 measuredPhase,
                                                  ViReal64* oldPhase);

/*- Deprecated Functions----------------------------------------------*/
ViStatus _VI_FUNC niSync_StartPTP(ViSession vi,
                                  ViInt32 initialTimeSource,
                                  ViUInt32 initialTimeSeconds,
                                  ViUInt32 initialTimeNanoseconds,
                                  ViUInt16 initialTimeFractionalNanoseconds);

ViStatus _VI_FUNC niSync_StopPTP(ViSession vi);
ViStatus _VI_FUNC niSync_Get1588Time(ViSession vi,
                                     ViUInt32* timeSeconds,
                                     ViUInt32* timeNanoseconds,
                                     ViUInt16* timeFractionalNanoseconds);

/****************************************************************************
 *------------------------ Error And Completion Codes ----------------------*
 ****************************************************************************/
#define NISYNC_WARN_BASE                        (ViStatus)(0x3FFA4000)
#define NISYNC_ERROR_BASE                       (ViStatus)(0xBFFA4000) /* IVI_SPECIFIC_PUBLIC_ATTR_BASE */

// NISYNC_WARN_BASE + 6x is reserved for calibration warnings.
#define NISYNC_WARN_CAL_UNCALIBRATED            (NISYNC_WARN_BASE + 60)
#define NISYNC_WARN_NETWORK_CLIENT_IN_PROGRESS  (NISYNC_WARN_BASE + 100)
#define NISYNC_WARN_UNKNOWN_STATUS              VI_WARN_UNKNOWN_STATUS

#define NISYNC_WARNMSG_CAL_UNCALIBRATED              "This device is not properly calibrated."
#define NISYNC_WARNMSG_NETWORK_CLIENT_IN_PROGRESS    "The request has been accepted by the remote device but processing has not been completed. Wait and attempt to query the property again."
#define NISYNC_WARNMSG_UNKNOWN_STATUS                "The status code passed to the operation could not be interpreted."

#define NISYNC_ERROR_INV_PARAMETER              VI_ERROR_INV_PARAMETER
#define NISYNC_ERROR_NSUP_ATTR                  VI_ERROR_NSUP_ATTR
#define NISYNC_ERROR_NSUP_ATTR_STATE            VI_ERROR_NSUP_ATTR_STATE
#define NISYNC_ERROR_ATTR_READONLY              VI_ERROR_ATTR_READONLY
#define NISYNC_ERROR_ALLOCATION_FAILED          VI_ERROR_ALLOC
#define NISYNC_ERROR_SYSTEM_ERROR               VI_ERROR_SYSTEM_ERROR
#define NISYNC_ERROR_INV_OBJECT                 VI_ERROR_INV_OBJECT
#define NISYNC_ERROR_RSRC_NFOUND                VI_ERROR_RSRC_NFOUND
#define NISYNC_ERROR_NIMPL_OPER                 VI_ERROR_NIMPL_OPER

#define NISYNC_ERROR_INVALID_DESCRIPTOR         (NISYNC_ERROR_BASE + 1)
#define NISYNC_ERROR_INVALID_MODE               (NISYNC_ERROR_BASE + 2)
#define NISYNC_ERROR_FEATURE_NOT_SUPPORTED      (NISYNC_ERROR_BASE + 3)
#define NISYNC_ERROR_VERSION_MISMATCH           (NISYNC_ERROR_BASE + 4)
#define NISYNC_ERROR_INTERNAL_SOFTWARE          (NISYNC_ERROR_BASE + 5)
#define NISYNC_ERROR_FILE_IO                    (NISYNC_ERROR_BASE + 6)
#define NISYNC_ERROR_RESET_NOT_SUPPORTED        (NISYNC_ERROR_BASE + 7)
#define NISYNC_ERROR_INVALID_TYPE               (NISYNC_ERROR_BASE + 8)
#define NISYNC_ERROR_API_SUPPORT_INCOMPATIBLE_WITH_RUNTIME (NISYNC_ERROR_BASE + 9)

#define NISYNC_ERROR_DRIVER_INITIALIZATION      (NISYNC_ERROR_BASE + 10)
#define NISYNC_ERROR_DRIVER_TIMEOUT             (NISYNC_ERROR_BASE + 11)

#define NISYNC_ERROR_READ_FAILURE               (NISYNC_ERROR_BASE + 20)
#define NISYNC_ERROR_WRITE_FAILURE              (NISYNC_ERROR_BASE + 21)
#define NISYNC_ERROR_DEVICE_NOT_FOUND           (NISYNC_ERROR_BASE + 22)
#define NISYNC_ERROR_DEVICE_NOT_READY           (NISYNC_ERROR_BASE + 23)
#define NISYNC_ERROR_INTERNAL_HARDWARE          (NISYNC_ERROR_BASE + 24)
#define NISYNC_ERROR_OVERFLOW                   (NISYNC_ERROR_BASE + 25)
#define NISYNC_ERROR_REMOTE_DEVICE              (NISYNC_ERROR_BASE + 26)

#define NISYNC_ERROR_FIRMWARE_LOAD              (NISYNC_ERROR_BASE + 30)
#define NISYNC_ERROR_DEVICE_NOT_INITIALIZED     (NISYNC_ERROR_BASE + 31)
#define NISYNC_ERROR_CLK10_NOT_PRESENT          (NISYNC_ERROR_BASE + 32)

#define NISYNC_ERROR_PLL_NOT_PRESENT            (NISYNC_ERROR_BASE + 40)
#define NISYNC_ERROR_DDS_NOT_PRESENT            (NISYNC_ERROR_BASE + 41)
#define NISYNC_ERROR_DDS_ALREADY_STARTED        (NISYNC_ERROR_BASE + 42)
#define NISYNC_ERROR_DDS_SYNC_CLK_COMBO_INVALID (NISYNC_ERROR_BASE + 43)

#define NISYNC_ERROR_DEST_TERMINAL_IN_USE                              VI_ERROR_LINE_IN_USE
#define NISYNC_ERROR_SRC_TERMINAL_INVALID                              (NISYNC_ERROR_BASE + 50)
#define NISYNC_ERROR_DEST_TERMINAL_INVALID                             (NISYNC_ERROR_BASE + 51)
#define NISYNC_ERROR_TERMINAL_NOT_CONNECTED                            (NISYNC_ERROR_BASE + 52)
#define NISYNC_ERROR_SYNC_CLK_INVALID                                  (NISYNC_ERROR_BASE + 53)
#define NISYNC_ERROR_TERMINAL_INVALID                                  (NISYNC_ERROR_BASE + 54)
#define NISYNC_ERROR_SRC_TERMINAL_PXI_CHASSIS_NOT_IDENTIFIED           (NISYNC_ERROR_BASE + 55)
#define NISYNC_ERROR_DEST_TERMINAL_PXI_CHASSIS_NOT_IDENTIFIED          (NISYNC_ERROR_BASE + 56)
#define NISYNC_ERROR_SRC_TERMINAL_PXI_STARX_NOT_IN_SYS_TIMING_SLOT     (NISYNC_ERROR_BASE + 57)
#define NISYNC_ERROR_DEST_TERMINAL_PXI_STARX_NOT_IN_SYS_TIMING_SLOT    (NISYNC_ERROR_BASE + 58)
#define NISYNC_ERROR_DEST_TERMINAL_PXI_CLK10_IN_NOT_IN_SYS_TIMING_SLOT (NISYNC_ERROR_BASE + 59)

#define NISYNC_ERROR_CAL_INCORRECT_PASSWORD  (NISYNC_ERROR_BASE + 60)
#define NISYNC_ERROR_CAL_PASSWORD_TOO_LARGE  (NISYNC_ERROR_BASE + 61)
#define NISYNC_ERROR_CAL_NOT_PERMITTED       (NISYNC_ERROR_BASE + 62)

#define NISYNC_ERROR_RSRC_UNAVAILABLE        (NISYNC_ERROR_BASE + 70)
#define NISYNC_ERROR_RSRC_RESERVED           (NISYNC_ERROR_BASE + 71)
#define NISYNC_ERROR_RSRC_NOT_RESERVED       (NISYNC_ERROR_BASE + 72)
#define NISYNC_ERROR_HW_BUFFER_FULL          (NISYNC_ERROR_BASE + 73)
#define NISYNC_ERROR_SW_BUFFER_FULL          (NISYNC_ERROR_BASE + 74)
#define NISYNC_ERROR_SOCKET_FAILURE          (NISYNC_ERROR_BASE + 75)
#define NISYNC_ERROR_SESSION_ABORTED         (NISYNC_ERROR_BASE + 76)
#define NISYNC_ERROR_SESSION_ABORTING        (NISYNC_ERROR_BASE + 77)
#define NISYNC_ERROR_TERMINAL_NOT_SPECIFIED  (NISYNC_ERROR_BASE + 78)

#define NISYNC_ERROR_TIME_OVERFLOW           (NISYNC_ERROR_BASE + 80)
#define NISYNC_ERROR_TIME_TOO_EARLY          (NISYNC_ERROR_BASE + 81)
#define NISYNC_ERROR_TIME_TOO_LATE           (NISYNC_ERROR_BASE + 82)
#define NISYNC_ERROR_PTP_ALREADY_STARTED     (NISYNC_ERROR_BASE + 83)
#define NISYNC_ERROR_PTP_NOT_STARTED         (NISYNC_ERROR_BASE + 84)
#define NISYNC_ERROR_INVALID_CLOCK_STATE     (NISYNC_ERROR_BASE + 85)
#define NISYNC_ERROR_IP_ADDRESS              (NISYNC_ERROR_BASE + 86)
#define NISYNC_ERROR_FUTURE_TIME_EVENT_TOO_SOON (NISYNC_ERROR_BASE + 87)
#define NISYNC_ERROR_CLOCK_PERIOD_TOO_SHORT  (NISYNC_ERROR_BASE + 88)
#define NISYNC_ERROR_DUP_FUTURE_TIME_EVENT   (NISYNC_ERROR_BASE + 89)
#define NISYNC_ERROR_SYNC_INTERVAL_MISMACH   (NISYNC_ERROR_BASE + 90)
#define NISYNC_ERROR_INVALID_INITIAL_TIME    (NISYNC_ERROR_BASE + 91)
#define NISYNC_ERROR_CLK_ADJ_TOO_LARGE       (NISYNC_ERROR_BASE + 92)
#define NISYNC_ERROR_CLOCK_PERIOD_TOO_LARGE  (NISYNC_ERROR_BASE + 93)
#define NISYNC_ERROR_NETWORK_ADAPTER_NOT_FOUND (NISYNC_ERROR_BASE + 94)

#define NISYNC_ERROR_NO_COMMON_TRIG_LINE_FOR_ROUTE (NISYNC_ERROR_BASE + 95)

#define NISYNC_ERROR_TIMESTAMP_DECIMATION_NOT_SUPPORTED   (NISYNC_ERROR_BASE + 96)
#define NISYNC_ERROR_TIMESTAMP_DECIMATION_COUNT_TOO_SMALL (NISYNC_ERROR_BASE + 97)
#define NISYNC_ERROR_TIMESTAMP_DECIMATION_COUNT_TOO_LARGE (NISYNC_ERROR_BASE + 98)

#define NISYNC_ERROR_FUTURE_TIME_EVENT_REARM_TIME_VIOLATION (NISYNC_ERROR_BASE + 99)

#define NISYNC_ERROR_TIME_SNAPPED (NISYNC_ERROR_BASE + 100)

#define NISYNC_ERROR_TR_TYPE_MISMATCH                            (NISYNC_ERROR_BASE + 101)
#define NISYNC_ERROR_TR_INSTANCE_NOT_FOUND                       (NISYNC_ERROR_BASE + 102)
#define NISYNC_ERROR_REMOTE_DEVICE_READ_FAILURE                  (NISYNC_ERROR_BASE + 103)
#define NISYNC_ERROR_REMOTE_DEVICE_COMMUNICATION_FAILURE         (NISYNC_ERROR_BASE + 104)
#define NISYNC_ERROR_LIB_LOAD_FAILURE                            (NISYNC_ERROR_BASE + 105)
#define NISYNC_ERROR_INVALID_RESOURCE_NAME_FORMAT                (NISYNC_ERROR_BASE + 106)
#define NISYNC_ERROR_TR_INSTANCE_ALREADY_EXISTS                  (NISYNC_ERROR_BASE + 107)
#define NISYNC_ERROR_REMOTE_DEVICE_RESOURCE_NOT_FOUND            (NISYNC_ERROR_BASE + 108)
#define NISYNC_ERROR_CONFLICTING_TR_INSTANCES                    (NISYNC_ERROR_BASE + 109)
#define NISYNC_ERROR_TR_ATTR_NOT_FOUND                           (NISYNC_ERROR_BASE + 110)
#define NISYNC_ERROR_COMMUNICATIONS_FAULT                        (NISYNC_ERROR_BASE + 111)


#define NISYNC_ERRMSG_INV_PARAMETER              "A parameter for this operation is invalid."
#define NISYNC_ERRMSG_NSUP_ATTR                  "The specified attribute is not supported."
#define NISYNC_ERRMSG_NSUP_ATTR_STATE            "The specified attribute state is not supported."
#define NISYNC_ERRMSG_ATTR_READONLY              "The specified attribute is read-only."
#define NISYNC_ERRMSG_ALLOCATION_FAILED          "Insufficient system resources to perform necessary memory allocation."
#define NISYNC_ERRMSG_SYSTEM_ERROR               "Unknown system error (miscellaneous error)."
#define NISYNC_ERRMSG_INV_OBJECT                 "The given session or object reference is invalid."
#define NISYNC_ERRMSG_RSRC_NFOUND                "Insufficient location information or the device or resource is not present in the system."
#define NISYNC_ERRMSG_NIMPL_OPER                 "The given operation is not implemented."
#define NISYNC_ERRMSG_INVALID_DESCRIPTOR         "The specified instrument descriptor is invalid."
#define NISYNC_ERRMSG_INVALID_MODE               "The mode for this operation is invalid."
#define NISYNC_ERRMSG_FEATURE_NOT_SUPPORTED      "This operation requires a feature that is not supported."
#define NISYNC_ERRMSG_VERSION_MISMATCH           "There is a version mismatch."
#define NISYNC_ERRMSG_INTERNAL_SOFTWARE          "An internal software error occurred."
#define NISYNC_ERRMSG_FILE_IO                    "An error occurred while reading or writing a file."
#define NISYNC_ERRMSG_RESET_NOT_SUPPORTED        "This device does not support Reset."
#define NISYNC_ERRMSG_INVALID_TYPE               "A parameter for this operation is of an invalid type."
#define NISYNC_ERRMSG_API_SUPPORT_INCOMPATIBLE_WITH_RUNTIME "The NI-Sync API Support is unable to communicate with the NI-Sync Runtime. To resolve this issue, install NI-Sync 18.0 or later."

#define NISYNC_ERRMSG_DRIVER_INITIALIZATION      "An error occurred while initializing the driver."
#define NISYNC_ERRMSG_DRIVER_TIMEOUT             "The driver timed out while performing an operation."

#define NISYNC_ERRMSG_READ_FAILURE               "A failure occurred while reading from the device."
#define NISYNC_ERRMSG_WRITE_FAILURE              "A failure occurred while writing to the device."
#define NISYNC_ERRMSG_DEVICE_NOT_FOUND           "The specified device was not found."
#define NISYNC_ERRMSG_DEVICE_NOT_READY           "The specified device is not ready."
#define NISYNC_ERRMSG_INTERNAL_HARDWARE          "An internal hardware error occurred."
#define NISYNC_ERRMSG_OVERFLOW                   "An overflow condition occurred."
#define NISYNC_ERRMSG_REMOTE_DEVICE              "The specified device is a remote device.  Remote devices are not allowed."

#define NISYNC_ERRMSG_FIRMWARE_LOAD              "The firmware failed to load."
#define NISYNC_ERRMSG_DEVICE_NOT_INITIALIZED     "The device is not initialized."
#define NISYNC_ERRMSG_CLK10_NOT_PRESENT          "PXI_Clk10 is not present."

#define NISYNC_ERRMSG_PLL_NOT_PRESENT            "This device does not support a PLL."
#define NISYNC_ERRMSG_DDS_NOT_PRESENT            "The device does not support a DDS."
#define NISYNC_ERRMSG_DDS_ALREADY_STARTED        "The specified attribute cannot be set because the DDS is already running."
#define NISYNC_ERRMSG_DDS_SYNC_CLK_COMBO_INVALID "The current DDS frequency is incompatible as a synchronization clock, either the DDS is off or running too fast."

#define NISYNC_ERRMSG_DEST_TERMINAL_IN_USE                              "The specified destination terminal is in use."
#define NISYNC_ERRMSG_SRC_TERMINAL_INVALID                              "The specified source terminal is invalid for this operation."
#define NISYNC_ERRMSG_DEST_TERMINAL_INVALID                             "The specified destination terminal is invalid for this operation."
#define NISYNC_ERRMSG_TERMINAL_NOT_CONNECTED                            "The specified terminal is not connected."
#define NISYNC_ERRMSG_SYNC_CLK_INVALID                                  "The specified synchronization clock is invalid for this operation."
#define NISYNC_ERRMSG_TERMINAL_INVALID                                  "Terminal for the device is invalid."
#define NISYNC_ERRMSG_SRC_TERMINAL_PXI_CHASSIS_NOT_IDENTIFIED           "Route failed because the PXI chassis is not identified. The existence of the source terminal depends on the chassis being identified. Use the Measurements & Automation Explorer (MAX) to identify your chassis."
#define NISYNC_ERRMSG_DEST_TERMINAL_PXI_CHASSIS_NOT_IDENTIFIED          "Route failed because the PXI chassis is not identified. The existence of the destination terminal depends on the chassis being identified. Use the Measurements & Automation Explorer (MAX) to identify your chassis."
#define NISYNC_ERRMSG_SRC_TERMINAL_PXI_STARX_NOT_IN_SYS_TIMING_SLOT     "PXI_Star<n> is available as a source terminal only for devices in a system timing slot. To use PXI_Star<n>, move your device to a system timing slot."
#define NISYNC_ERRMSG_DEST_TERMINAL_PXI_STARX_NOT_IN_SYS_TIMING_SLOT    "PXI_Star<n> is available as a destination terminal only for devices in a system timing slot. To use PXI_Star<n>, move your device to a system timing slot."
#define NISYNC_ERRMSG_DEST_TERMINAL_PXI_CLK10_IN_NOT_IN_SYS_TIMING_SLOT "PXI_Clk10_In is available as a destination terminal only for devices in a system timing slot. Move your device to a system timing slot."

#define NISYNC_ERRMSG_CAL_INCORRECT_PASSWORD "The supplied external calibration password is incorrect."
#define NISYNC_ERRMSG_CAL_PASSWORD_TOO_LARGE "The external calibration password contains too many characters."
#define NISYNC_ERRMSG_CAL_NOT_PERMITTED      "The specified calibration operation is not permitted on this session type."

#define NISYNC_ERRMSG_RSRC_UNAVAILABLE       "A resource necessary to complete the specified operation is not available; therefore, the operation cannot be completed."
#define NISYNC_ERRMSG_RSRC_RESERVED          "A resource necessary to complete the specified operation is already reserved by a previous operation and cannot be shared; therefore, the operation cannot be completed."
#define NISYNC_ERRMSG_RSRC_NOT_RESERVED      "A resource necessary to complete the specified operation is not reserved and should have already been; therefore, the operation cannot be completed"
#define NISYNC_ERRMSG_HW_BUFFER_FULL         "A hardware buffer necessary to complete the specified operation is unexpectedly full; therefore, the operation cannot be completed."
#define NISYNC_ERRMSG_SW_BUFFER_FULL         "A software buffer necessary to complete the specified operation is unexpectedly full; therefore, the operation cannot be completed."
#define NISYNC_ERRMSG_SOCKET_FAILURE         "A network socket necessary to complete the specified operation has generated a failure; therefore, the operation cannot be completed."
#define NISYNC_ERRMSG_SESSION_ABORTED        "The specified operation cannot be performed because a session has been aborted or a device has been removed from the system. Handle this situation as required by the application and then, if appropriate, attempt to perform the operation again."
#define NISYNC_ERRMSG_SESSION_ABORTING       "The specified operation cannot be performed because a session is in the process of being aborted or a device is in the process of being removed from the system. Wait until the abort operation is complete, and attempt to perform the operation again."
#define NISYNC_ERRMSG_TERMINAL_NOT_SPECIFIED "The specified operation cannot be performed since the Active Item was not specified."

#define NISYNC_ERRMSG_TIME_OVERFLOW          "A 1588 time value has overflowed.  The resulting value is not accurate."
#define NISYNC_ERRMSG_TIME_TOO_EARLY         "The specified time value is too early to be represented as a 1588 time value."
#define NISYNC_ERRMSG_TIME_TOO_LATE          "The specified time value is too late to be represetned as a 1588 time value."
#define NISYNC_ERRMSG_PTP_ALREADY_STARTED    "The Precision Time Protocol (PTP) has already been started on this device; therefore, it cannot be started again."
#define NISYNC_ERRMSG_PTP_NOT_STARTED        "The Precision Time Protocol (PTP) has not been started on this device; therefore, it cannot be stopped."
#define NISYNC_ERRMSG_INVALID_CLOCK_STATE    "The specified attribute cannot be set when the Precision Time Protocol (PTP) is in its current state."
#define NISYNC_ERRMSG_IP_ADDRESS             "The IP address for the specified device cannot be determined; therefore, the specified operation cannot be completed."
#define NISYNC_ERRMSG_FUTURE_TIME_EVENT_TOO_SOON "The time for the specified future time event is too soon, or may be in the past, and cannot be programmed in the device before it would occur."
#define NISYNC_ERRMSG_CLOCK_PERIOD_TOO_SHORT "A clock with the specified period is too short to be generated by the device."
#define NISYNC_ERRMSG_DUP_FUTURE_TIME_EVENT  "A future time event with the same time and same terminal as the specified future time event has already been created.  Multiple future time events on the same terminal at the same time cannot be created."
#define NISYNC_ERRMSG_SYNC_INTERVAL_MISMACH  "The specified sync interval for this 1588 clock is different than the sync interval specified for other 1588 clocks participating in the PTP.  Adjust the sync interval on this 1588 clock or the other 1588 clocks participating in the PTP to the same value."
#define NISYNC_ERRMSG_INVALID_INITIAL_TIME   "The specified initial time is invalid.  Initial times must be after 0 hours 1 January 2000 and before 0 hours 1 January 2100."
#define NISYNC_ERRMSG_CLK_ADJ_TOO_LARGE      "The specified 1588 clock adjustment offset is too large.  The clock adjustment cannot be more than +1 seconds or less than -1 seconds."
#define NISYNC_ERRMSG_CLOCK_PERIOD_TOO_LARGE "A clock with the specified period is too large to be generated by the device."
#define NISYNC_ERRMSG_NETWORK_ADAPTER_NOT_FOUND "The network interface associated with the device was not found.  Ensure that the associated NIC (network interface controller) is installed and enabled."

#define NISYNC_ERRMSG_NO_COMMON_TRIG_LINE_FOR_ROUTE "There are no shared trigger lines between the two devices which are acceptable to both devices. Consider routing the signal through the I/O connectors of the two devices, if applicable."

#define NISYNC_ERRMSG_TIMESTAMP_DECIMATION_NOT_SUPPORTED   "This device does not support timestamp decimation."
#define NISYNC_ERRMSG_TIMESTAMP_DECIMATION_COUNT_TOO_SMALL "The timestamp decimation count must be greater than 0 for this device."
#define NISYNC_ERRMSG_TIMESTAMP_DECIMATION_COUNT_TOO_LARGE "The specified timestamp decimation count is too great for this device."

#define NISYNC_ERRMSG_FUTURE_TIME_EVENT_REARM_TIME_VIOLATION "The specified future time event violates the rearm time of the future time event engine."

#define NISYNC_ERRMSG_TIME_SNAPPED "Board time was snapped back during measurement."

#define NISYNC_ERRMSG_TR_TYPE_MISMATCH "The requested property is not supported by the time reference specified on the Active Terminal."
#define NISYNC_ERRMSG_TR_INSTANCE_NOT_FOUND "The requested time reference instance was not found."
#define NISYNC_ERRMSG_REMOTE_DEVICE_READ_FAILURE "The data received from the remote device could not be interpreted. Try to perform the operation again."
#define NISYNC_ERRMSG_REMOTE_DEVICE_COMMUNICATION_FAILURE "A failure occured while communicating with the remote device. Ensure the remote device is accessible."
#define NISYNC_ERRMSG_LIB_LOAD_FAILURE "Unable to load an internal library. If the error persists contact National Instruments support."
#define NISYNC_ERRMSG_INVALID_RESOURCE_NAME_FORMAT "The resource name format is invalid."
#define NISYNC_ERRMSG_TR_INSTANCE_ALREADY_EXISTS "The specified time reference already exists."
#define NISYNC_ERRMSG_REMOTE_DEVICE_RESOURCE_NOT_FOUND "Requested resource not found on a remote device. This may be because the device was not reachable or has experienced an internal error. It may also mean you need to update software or firmware on the remote device."
#define NISYNC_ERRMSG_CONFLICTING_TR_INSTANCES "The time reference you are trying to enable conflicts with a time reference already running on the same interface. Disable the conflicting time reference and retry the operation."
#define NISYNC_ERRMSG_TR_ATTR_NOT_FOUND "The requested attribute is not currently available. This may be because the time reference is disabled, not ready, or has encountered an error."
#define NISYNC_ERRMSG_COMMUNICATIONS_FAULT "A failure occured while communicating with a required software service running on the device. Restart the device. If the error persists, contact National Instruments support."

/****************************************************************************
 *---------------------------- End Include File ----------------------------*
 ****************************************************************************/
#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif
#endif /* __NISYNC_HEADER */
