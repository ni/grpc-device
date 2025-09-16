/****************************************************************************
 *                          NI RF Signal Generator
 *---------------------------------------------------------------------------
 *   Copyright (c) National Instruments 2003-2020.  All Rights Reserved.
 *---------------------------------------------------------------------------
 *
 * Title:    niRFSG.h
 * Purpose:  NI RF Signal Generator
 *           Instrument Driver declarations.
 *
 ****************************************************************************/

#ifndef ___niRFSG_niRFSG_h___
#define ___niRFSG_niRFSG_h___

#include <ivi.h>

#include <IviRFSigGen.h>

#ifdef _CVI_
   #pragma EnableLibraryRuntimeChecking
#endif


#if defined(__cplusplus) || defined(__cplusplus__)
   extern "C" {
#endif

// Bitness check for Supported Platforms
#if ((defined(_WIN32) || defined(WIN32)) && !defined(_WIN64))
   #define kRFSG_32BitPlatform 1
#elif defined(_WIN64) || (defined(__linux__) && defined(__x86_64__))
   #define kRFSG_64BitPlatform 1
#else
   #error "Unknown platform"
#endif

/****************************************************************************
 *---------------------------- Attribute Defines ---------------------------*
 ****************************************************************************/

/*- IVI Inherent Attributes ---------------------------------------------*/
   /*- User Options -*/
#define NIRFSG_ATTR_CACHE                                   /* ViBoolean */   IVIRFSIGGEN_ATTR_CACHE
#define NIRFSG_ATTR_RANGE_CHECK                             /* ViBoolean */   IVIRFSIGGEN_ATTR_RANGE_CHECK
#define NIRFSG_ATTR_QUERY_INSTRUMENT_STATUS                 /* ViBoolean */   IVIRFSIGGEN_ATTR_QUERY_INSTRUMENT_STATUS
#define NIRFSG_ATTR_RECORD_COERCIONS                        /* ViBoolean */   IVIRFSIGGEN_ATTR_RECORD_COERCIONS
#define NIRFSG_ATTR_SIMULATE                                /* ViBoolean */   IVIRFSIGGEN_ATTR_SIMULATE
#define NIRFSG_ATTR_INTERCHANGE_CHECK                       /* ViBoolean */   IVIRFSIGGEN_ATTR_INTERCHANGE_CHECK
#define NIRFSG_ATTR_SPY                                     /* ViBoolean */   IVIRFSIGGEN_ATTR_SPY
#define NIRFSG_ATTR_USE_SPECIFIC_SIMULATION                 /* ViBoolean */   IVIRFSIGGEN_ATTR_USE_SPECIFIC_SIMULATION

   /*- Instrument Capabilities, Read-only -*/
#define NIRFSG_ATTR_CHANNEL_COUNT                 /* ViInt32,  read-only */   IVIRFSIGGEN_ATTR_CHANNEL_COUNT
#define NIRFSG_ATTR_GROUP_CAPABILITIES            /* ViString, read-only */   IVIRFSIGGEN_ATTR_GROUP_CAPABILITIES
#define NIRFSG_ATTR_FUNCTION_CAPABILITIES         /* ViString, read-only */   IVIRFSIGGEN_ATTR_FUNCTION_CAPABILITIES

   /*- Specific Driver Information, Read-only -*/
#define NIRFSG_ATTR_SPECIFIC_DRIVER_PREFIX                   /* ViString */   IVIRFSIGGEN_ATTR_SPECIFIC_DRIVER_PREFIX
#define NIRFSG_ATTR_IO_RESOURCE_DESCRIPTOR                   /* ViString */   IVIRFSIGGEN_ATTR_IO_RESOURCE_DESCRIPTOR
#define NIRFSG_ATTR_LOGICAL_NAME                             /* ViString */   IVIRFSIGGEN_ATTR_LOGICAL_NAME
#define NIRFSG_ATTR_SPECIFIC_DRIVER_VENDOR                   /* ViString */   IVIRFSIGGEN_ATTR_SPECIFIC_DRIVER_VENDOR
#define NIRFSG_ATTR_SPECIFIC_DRIVER_DESCRIPTION              /* ViString */   IVIRFSIGGEN_ATTR_SPECIFIC_DRIVER_DESCRIPTION
#define NIRFSG_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION /* ViInt32  */   IVIRFSIGGEN_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION
#define NIRFSG_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION /* ViInt32  */   IVIRFSIGGEN_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION

   /*- Instrument Information -*/
#define NIRFSG_ATTR_INSTRUMENT_FIRMWARE_REVISION  /* ViString, read-only */   IVIRFSIGGEN_ATTR_INSTRUMENT_FIRMWARE_REVISION
#define NIRFSG_ATTR_INSTRUMENT_MANUFACTURER       /* ViString, read-only */   IVIRFSIGGEN_ATTR_INSTRUMENT_MANUFACTURER
#define NIRFSG_ATTR_INSTRUMENT_MODEL              /* ViString, read-only */   IVIRFSIGGEN_ATTR_INSTRUMENT_MODEL
#define NIRFSG_ATTR_SUPPORTED_INSTRUMENT_MODELS   /* ViString, read-only */   IVIRFSIGGEN_ATTR_SUPPORTED_INSTRUMENT_MODELS

   /*- Version Information -*/
#define NIRFSG_ATTR_SPECIFIC_DRIVER_REVISION      /* ViString, read-only */   IVIRFSIGGEN_ATTR_SPECIFIC_DRIVER_REVISION

   /*- Driver Setup information -*/
#define NIRFSG_ATTR_DRIVER_SETUP                             /* ViString */   IVIRFSIGGEN_ATTR_DRIVER_SETUP

/*- IVI Class-Specific Attributes ---------------------------------------*/

   /*- IviRFSigGen Fundamental Attributes -*/
#define NIRFSG_ATTR_FREQUENCY                               /* ViReal64  */   IVIRFSIGGEN_ATTR_FREQUENCY
#define NIRFSG_ATTR_POWER_LEVEL                             /* ViReal64  */   IVIRFSIGGEN_ATTR_POWER_LEVEL
#define NIRFSG_ATTR_OUTPUT_ENABLED                          /* ViBoolean */   IVIRFSIGGEN_ATTR_OUTPUT_ENABLED

   /*- IviRFSigGenReferenceOscillator Extension Group -*/
#define NIRFSG_ATTR_REF_CLOCK_RATE                          /* ViReal64  */   IVIRFSIGGEN_ATTR_REFERENCE_OSCILLATOR_EXTERNAL_FREQUENCY

   /*- IviRFSigGenModulateIQ Extension Group -*/
#define NIRFSG_ATTR_IQ_NOMINAL_VOLTAGE                      /* ViReal64  */   IVIRFSIGGEN_ATTR_IQ_NOMINAL_VOLTAGE
#define NIRFSG_ATTR_IQ_SWAP_ENABLED                         /* ViBoolean */   IVIRFSIGGEN_ATTR_IQ_SWAP_ENABLED

   /*- IviRFSigGenArbGenerator Extension Group -*/
#define NIRFSG_ATTR_ARB_SELECTED_WAVEFORM                   /* ViString  */   IVIRFSIGGEN_ATTR_ARB_SELECTED_WAVEFORM
#define NIRFSG_ATTR_IQ_RATE                                 /* ViReal64  */   IVIRFSIGGEN_ATTR_ARB_CLOCK_FREQUENCY
#define NIRFSG_ATTR_ARB_FILTER_FREQUENCY                    /* ViReal64  */   IVIRFSIGGEN_ATTR_ARB_FILTER_FREQUENCY
#define NIRFSG_ATTR_ARB_MAX_NUMBER_WAVEFORMS       /* ViInt32,  read-only */  IVIRFSIGGEN_ATTR_ARB_MAX_NUMBER_WAVEFORMS
#define NIRFSG_ATTR_ARB_WAVEFORM_QUANTUM           /* ViInt32,  read-only */  IVIRFSIGGEN_ATTR_ARB_WAVEFORM_QUANTUM
#define NIRFSG_ATTR_ARB_WAVEFORM_SIZE_MIN          /* ViInt32,  read-only */  IVIRFSIGGEN_ATTR_ARB_WAVEFORM_SIZE_MIN
#define NIRFSG_ATTR_ARB_WAVEFORM_SIZE_MAX          /* ViInt32,  read-only */  IVIRFSIGGEN_ATTR_ARB_WAVEFORM_SIZE_MAX
#define NIRFSG_ATTR_START_TRIGGER_TYPE                      /* ViInt32   */   IVIRFSIGGEN_ATTR_ARB_TRIGGER_SOURCE
#define NIRFSG_ATTR_DIGITAL_EDGE_START_TRIGGER_EDGE         /* ViInt32   */   IVIRFSIGGEN_ATTR_ARB_EXTERNAL_TRIGGER_SLOPE

   /*- Pulse Modulation -*/
#define NIRFSG_ATTR_PULSE_MODULATION_ENABLED                         /* ViBoolean */   IVIRFSIGGEN_ATTR_PULSE_MODULATION_ENABLED
#define NIRFSG_ATTR_PULSE_MODULATION_MODE                            /* ViInt32, read-write */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xbe)
#define NIRFSG_ATTR_PULSE_MODULATION_ACTIVE_LEVEL                    /* ViInt32, read-write */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x133)
#define NIRFSG_ATTR_PULSE_MODULATION_SOURCE                          /* ViString, read-write */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x134)
#define NIRFSG_ATTR_EXPORTED_PULSE_MODULATION_EVENT_OUTPUT_TERMINAL  /* ViString, read-write */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x135)
#define NIRFSG_ATTR_EXPORTED_PULSE_MODULATION_EVENT_ACTIVE_LEVEL     /* ViInt32,  read-write */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x136)

/*- niRFSG Driver-Specific Attributes -----------------------------------*/

   /*- Fundamental Attributes (see IviRFSigGen Fundamental Attributes above) -*/
#define NIRFSG_ATTR_GENERATION_MODE                         /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x12)
#define NIRFSG_ATTR_POWER_LEVEL_TYPE                        /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x2b)
#define NIRFSG_ATTR_PEAK_ENVELOPE_POWER           /* ViReal64, read-only */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x0b)

   /*- Arb Waveform (see IviRFSigGenArbGenerator Attributes above) -*/
#define NIRFSG_ATTR_SIGNAL_BANDWIDTH                        /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x07)
#define NIRFSG_ATTR_DEVICE_INSTANTANEOUS_BANDWIDTH          /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xe2)
#define NIRFSG_ATTR_DIRECT_DOWNLOAD                         /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x2a)
#define NIRFSG_ATTR_ARB_WAVEFORM_SOFTWARE_SCALING_FACTOR    /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x34)
#define NIRFSG_ATTR_FREQUENCY_TOLERANCE                     /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x06)
#define NIRFSG_ATTR_PHASE_CONTINUITY_ENABLED                /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x05)
#define NIRFSG_ATTR_DIGITAL_EQUALIZATION_ENABLED            /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x0c)
#define NIRFSG_ATTR_ARB_WAVEFORM_REPEAT_COUNT_IS_FINITE     /* ViBoolean */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x9d)
#define NIRFSG_ATTR_ARB_WAVEFORM_REPEAT_COUNT               /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x9e)

   /*- Waveform Normalization -*/
#define NIRFSG_ATTR_WRITE_WAVEFORM_NORMALIZATION            /* ViInt32 */     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x125)

   /*- Burst Detection -*/
#define NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION                        /* ViInt32 */     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x111)
#define NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION_MODE                   /* ViInt32 */     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x112)
#define NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION_MINIMUM_QUIET_TIME     /* ViReal64 */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x113)
#define NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION_POWER_THRESHOLD        /* ViReal64 */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x114)
#define NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION_MINIMUM_BURST_TIME     /* ViReal64 */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x115)

   /*- Instrument Information -*/
#define NIRFSG_ATTR_MEMORY_SIZE                  /* ViInt64, read-only   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x3d)

   /*- Scripting -*/
#define NIRFSG_ATTR_SELECTED_SCRIPT                         /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x17)

   /*- Clocking -*/
#define NIRFSG_ATTR_REF_CLOCK_SOURCE                        /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x01)
#define NIRFSG_ATTR_EXPORTED_REF_CLOCK_OUTPUT_TERMINAL      /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x35)
#define NIRFSG_ATTR_EXPORTED_REF_CLOCK_RATE                 /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x124)
#define NIRFSG_ATTR_LO_OUT_ENABLED                          /* ViBoolean */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x0d)
#define NIRFSG_ATTR_LO_OUT_POWER                            /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x42)
#define NIRFSG_ATTR_LO_IN_POWER                             /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x43)
#define NIRFSG_ATTR_PXI_CHASSIS_CLK10_SOURCE                /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x04)
#define NIRFSG_ATTR_ARB_ONBOARD_SAMPLE_CLOCK_MODE           /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x1d)
#define NIRFSG_ATTR_ARB_SAMPLE_CLOCK_SOURCE                 /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x1e)
#define NIRFSG_ATTR_ARB_SAMPLE_CLOCK_RATE         /* ViReal64, read-only */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x1f)
#define NIRFSG_ATTR_ARB_OSCILLATOR_PHASE_DAC_VALUE          /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x59)
#define NIRFSG_ATTR_REF_PLL_BANDWIDTH                       /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x85)
#define NIRFSG_ATTR_LO_OUT_EXPORT_CONFIGURE_FROM_RFSA       /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xF2)
#define NIRFSG_ATTR_RF_IN_LO_EXPORT_ENABLED                 /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xF3)

   /*- Analog Modulation -*/
#define NIRFSG_ATTR_ANALOG_MODULATION_TYPE                      /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x20)
#define NIRFSG_ATTR_ANALOG_MODULATION_WAVEFORM_TYPE             /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x21)
#define NIRFSG_ATTR_ANALOG_MODULATION_WAVEFORM_FREQUENCY        /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x22)
#define NIRFSG_ATTR_ANALOG_MODULATION_FM_DEVIATION              /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x23)
#define NIRFSG_ATTR_ANALOG_MODULATION_PM_DEVIATION              /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x3e)
#define NIRFSG_ATTR_ANALOG_MODULATION_FM_BAND                   /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xbf)
#define NIRFSG_ATTR_ANALOG_MODULATION_FM_NARROWBAND_INTEGRATOR  /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xa5)
#define NIRFSG_ATTR_ANALOG_MODULATION_FM_SENSITIVITY            /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xa6)
#define NIRFSG_ATTR_ANALOG_MODULATION_AM_SENSITIVITY            /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xa7)
#define NIRFSG_ATTR_ANALOG_MODULATION_PM_SENSITIVITY            /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xa8)
#define NIRFSG_ATTR_ANALOG_MODULATION_PM_MODE                   /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xc0)

   /*- Digital Modulation -*/
#define NIRFSG_ATTR_DIGITAL_MODULATION_TYPE                 /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x24)
#define NIRFSG_ATTR_DIGITAL_MODULATION_SYMBOL_RATE          /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x25)
#define NIRFSG_ATTR_DIGITAL_MODULATION_WAVEFORM_TYPE        /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x26)
#define NIRFSG_ATTR_DIGITAL_MODULATION_PRBS_ORDER           /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x27)
#define NIRFSG_ATTR_DIGITAL_MODULATION_PRBS_SEED            /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x28)
#define NIRFSG_ATTR_DIGITAL_MODULATION_FSK_DEVIATION        /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x29)

   /*- Arb Signal Processing -*/
#define NIRFSG_ATTR_ARB_PRE_FILTER_GAIN                     /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x19)
#define NIRFSG_ATTR_ARB_FILTER_TYPE                         /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x38)
#define NIRFSG_ATTR_ARB_FILTER_ROOT_RAISED_COSINE_ALPHA     /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x39)
#define NIRFSG_ATTR_ARB_FILTER_RAISED_COSINE_ALPHA          /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x3c)

   /*- Attenuator Hold -*/
#define NIRFSG_ATTR_ATTENUATOR_HOLD_ENABLED                 /* ViBoolean */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x09)
#define NIRFSG_ATTR_ATTENUATOR_HOLD_MAX_POWER               /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x0a)

   /*- Script Trigger -*/
#define NIRFSG_ATTR_SCRIPT_TRIGGER_TYPE                                 /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x13)
#define NIRFSG_ATTR_DIGITAL_EDGE_SCRIPT_TRIGGER_SOURCE                  /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x14)
#define NIRFSG_ATTR_DIGITAL_EDGE_SCRIPT_TRIGGER_EDGE                    /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x15)
#define NIRFSG_ATTR_DIGITAL_LEVEL_SCRIPT_TRIGGER_SOURCE                 /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x36)
#define NIRFSG_ATTR_DIGITAL_LEVEL_SCRIPT_TRIGGER_ACTIVE_LEVEL           /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x37)
#define NIRFSG_ATTR_EXPORTED_SCRIPT_TRIGGER_OUTPUT_TERMINAL             /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x16)
#define NIRFSG_ATTR_SCRIPT_TRIGGER_TERMINAL_NAME              /* ViString, read-only */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x74)

   /*- Start Trigger (see IviRFSigGenArbGenerator Attributes above) -*/
#define NIRFSG_ATTR_DIGITAL_EDGE_START_TRIGGER_SOURCE          /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x02)
#define NIRFSG_ATTR_EXPORTED_START_TRIGGER_OUTPUT_TERMINAL     /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x03)
#define NIRFSG_ATTR_START_TRIGGER_TERMINAL_NAME                /* ViString, read-only */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x72)
#define NIRFSG_ATTR_P2P_ENDPOINT_FULLNESS_START_TRIGGER_LEVEL  /* ViInt64   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x80)

   /*- Done Event -*/
#define NIRFSG_ATTR_EXPORTED_DONE_EVENT_OUTPUT_TERMINAL                 /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x3f)
#define NIRFSG_ATTR_DONE_EVENT_TERMINAL_NAME                  /* ViString, read-only */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x71)

   /*- Marker Event -*/
#define NIRFSG_ATTR_EXPORTED_MARKER_EVENT_OUTPUT_TERMINAL               /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x40)
#define NIRFSG_ATTR_MARKER_EVENT_TERMINAL_NAME                          /* ViString, read-only */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x73)
#define NIRFSG_ATTR_MARKER_EVENT_OUTPUT_BEHAVIOR                        /* ViInt32 */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xce)
#define NIRFSG_ATTR_MARKER_EVENT_PULSE_WIDTH                            /* ViReal64 */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xcf)
#define NIRFSG_ATTR_MARKER_EVENT_PULSE_WIDTH_UNITS                      /* ViInt32 */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xd0)
#define NIRFSG_ATTR_MARKER_EVENT_TOGGLE_INITIAL_STATE                   /* ViInt32 */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xd1)

   /*- Started Event -*/
#define NIRFSG_ATTR_EXPORTED_STARTED_EVENT_OUTPUT_TERMINAL              /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x41)
#define NIRFSG_ATTR_STARTED_EVENT_TERMINAL_NAME               /* ViString, read-only */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x70)

   /*- Configuration Settled Event -*/
#define NIRFSG_ATTR_EXPORTED_CONFIGURATION_SETTLED_EVENT_OUTPUT_TERMINAL   /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x81)
#define NIRFSG_ATTR_CONFIGURATION_SETTLED_EVENT_TERMINAL_NAME              /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xC2)

   /*- Data Transfer -*/
#define NIRFSG_ATTR_DATA_TRANSFER_BLOCK_SIZE                /* ViInt32   */        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x30)
#define NIRFSG_ATTR_DATA_TRANSFER_MAXIMUM_BANDWIDTH         /* ViReal64  */        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x56)
#define NIRFSG_ATTR_DATA_TRANSFER_PREFERRED_PACKET_SIZE     /* ViInt32   */        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x57)
#define NIRFSG_ATTR_DATA_TRANSFER_MAXIMUM_IN_FLIGHT_READS   /* ViInt32   */        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x58)

   /*- Streaming -*/
#define NIRFSG_ATTR_STREAMING_ENABLED                       /* ViBoolean */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x2d)
#define NIRFSG_ATTR_STREAMING_WAVEFORM_NAME                 /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x2e)
#define NIRFSG_ATTR_STREAMING_SPACE_AVAILABLE_IN_WAVEFORM   /* ViInt64   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x2f)
#define NIRFSG_ATTR_STREAMING_WRITE_TIMEOUT                 /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x8c)

   /*- Upconverter -*/
#define NIRFSG_ATTR_UPCONVERTER_GAIN                        /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x1001)
#define NIRFSG_ATTR_UPCONVERTER_CENTER_FREQUENCY            /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x1002)

   /*- Advanced -*/
#define NIRFSG_ATTR_ALLOW_OUT_OF_SPECIFICATION_USER_SETTINGS/* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x0e)
#define NIRFSG_ATTR_ARB_CARRIER_FREQUENCY                   /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x0f)
#define NIRFSG_ATTR_ARB_DIGITAL_GAIN                        /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xcc)
#define NIRFSG_ATTR_ARB_POWER                     /* ViReal64, read-only */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x10)
#define NIRFSG_ATTR_DEVICE_TEMPERATURE            /* ViReal64, read-only */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x11)
#define NIRFSG_ATTR_ARB_TEMPERATURE               /* ViReal64, read-only */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x44)
#define NIRFSG_ATTR_LO_TEMPERATURE                /* ViReal64, read-only */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x4b)
#define NIRFSG_ATTR_AE_TEMPERATURE                /* ViReal64, read-only */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xb6)
#define NIRFSG_ATTR_FPGA_TEMPERATURE              /* ViReal64, read-only */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xd3)
#define NIRFSG_ATTR_TEMPERATURE_READ_INTERVAL               /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xd4)
#define NIRFSG_ATTR_AUTOMATIC_THERMAL_CORRECTION            /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x08)
#define NIRFSG_ATTR_LOOP_BANDWIDTH                          /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x1b)
#define NIRFSG_ATTR_FGEN_SESSION                 /* ViSession, read-only */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x1c)
#define NIRFSG_ATTR_LO_SESSION                   /* ViSession, read-only */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x4a)
#define NIRFSG_ATTR_AE_SESSION                   /* ViSession, read-only */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xb7)
#define NIRFSG_ATTR_DIGITAL_PATTERN                         /* ViBoolean */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x2c)
#define NIRFSG_ATTR_PHASE_OFFSET                            /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x18)
#define NIRFSG_ATTR_FREQUENCY_SETTLING_UNITS                /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x52)
#define NIRFSG_ATTR_FREQUENCY_SETTLING                      /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x53)
#define NIRFSG_ATTR_AMPLITUDE_SETTLING                      /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x89)
#define NIRFSG_ATTR_EXTERNAL_GAIN                           /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x55)
#define NIRFSG_ATTR_YIG_MAIN_COIL_DRIVE                     /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x76)
#define NIRFSG_ATTR_PEAK_POWER_ADJUSTMENT                   /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x84)
#define NIRFSG_ATTR_PEAK_POWER_ADJUSTMENT_INHERITANCE       /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x8d)
#define NIRFSG_ATTR_COMPENSATE_FOR_FILTER_GROUP_DELAY       /* ViBoolean */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xb10)
#define NIRFSG_ATTR_CORRECTION_TEMPERATURE                  /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x68)
#define NIRFSG_ATTR_ALC_CONTROL                             /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xc3)
#define NIRFSG_ATTR_AUTO_POWER_SEARCH                       /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xc4)
#define NIRFSG_ATTR_AMP_PATH                                /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xb9)
#define NIRFSG_ATTR_ATTENUATOR_SETTING                      /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xad)
#define NIRFSG_ATTR_OVERFLOW_ERROR_REPORTING                /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xe4)
#define NIRFSG_ATTR_THERMAL_CORRECTION_TEMPERATURE_RESOLUTION  /* ViReal64 */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xF4)
#define NIRFSG_ATTR_THERMAL_CORRECTION_HEADROOM_RANGE          /* ViReal64 */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x102)
#define NIRFSG_ATTR_FIXED_GROUP_DELAY_ACROSS_PORTS          /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x10F)
#define NIRFSG_ATTR_SELECTED_PORTS                          /* ViString */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xF1)
#define NIRFSG_ATTR_AVAILABLE_PORTS                         /* ViString */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xF9)
#define NIRFSG_ATTR_SELECTED_PATH                           /* ViString */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x137)
#define NIRFSG_ATTR_AVAILABLE_PATHS                         /* ViString */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x138)

   /*- IQ Impairments -*/
#define NIRFSG_ATTR_IQ_IMPAIRMENT_ENABLED                   /* ViBoolean */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x45)
#define NIRFSG_ATTR_IQ_OFFSET_UNITS                         /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x51)
#define NIRFSG_ATTR_IQ_I_OFFSET                             /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x46)
#define NIRFSG_ATTR_IQ_Q_OFFSET                             /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x47)
#define NIRFSG_ATTR_IQ_GAIN_IMBALANCE                       /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x48)
#define NIRFSG_ATTR_IQ_SKEW                                 /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x49)

   /*- Device Attributes -*/
#define NIRFSG_ATTR_SERIAL_NUMBER                /* ViString, read-only  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x1a)
#define NIRFSG_ATTR_MODULE_REVISION              /* ViString, read-only  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x54)
#define NIRFSG_ATTR_MODULE_POWER_CONSUMPTION     /* ViReal64, read-only  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xd2)

#define NIRFSG_ATTR_FAST_TUNING_OPTION          /* ViBoolean, read-only  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xbc)

   /*- Calibration Attributes -*/
#define NIRFSG_ATTR_EXTERNAL_CALIBRATION_RECOMMENDED_INTERVAL       /* ViInt32  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x4c)
#define NIRFSG_ATTR_EXTERNAL_CALIBRATION_TEMPERATURE                /* ViReal64 */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x4d)
#define NIRFSG_ATTR_SELF_CALIBRATION_TEMPERATURE                    /* ViReal64 */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x88)

   /*- Configuration List -*/
#define NIRFSG_ATTR_ACTIVE_CONFIGURATION_LIST                                         /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x60)
#define NIRFSG_ATTR_ACTIVE_CONFIGURATION_LIST_STEP                                    /* ViInt64   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x61)
#define NIRFSG_ATTR_CONFIGURATION_LIST_STEP_IN_PROGRESS                      /* ViInt64, read-only */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x7a)
#define NIRFSG_ATTR_CONFIGURATION_LIST_STEP_TRIGGER_TYPE                              /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x62)
#define NIRFSG_ATTR_DIGITAL_EDGE_CONFIGURATION_LIST_STEP_TRIGGER_SOURCE               /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x63)
#define NIRFSG_ATTR_DIGITAL_EDGE_CONFIGURATION_LIST_STEP_TRIGGER_EDGE                 /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x67)
#define NIRFSG_ATTR_EXPORTED_CONFIGURATION_LIST_STEP_TRIGGER_OUTPUT_TERMINAL          /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x69)
#define NIRFSG_ATTR_CONFIGURATION_LIST_STEP_TRIGGER_TERMINAL_NAME           /* ViString, read-only */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x75)
#define NIRFSG_ATTR_CONFIGURATION_LIST_REPEAT                                         /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x66)
#define NIRFSG_ATTR_CONFIGURATION_LIST_IS_DONE                             /* ViBoolean, read-only */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xAF)

   /*- Timer -*/
#define NIRFSG_ATTR_TIMER_EVENT_INTERVAL     /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x64)

   /*- Peer-to-Peer (P2P) -*/
#define NIRFSG_ATTR_P2P_ENABLED                                      /* ViBoolean  */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x7b)
#define NIRFSG_ATTR_P2P_ENDPOINT_SIZE                        /* ViInt64, read-only */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x7c)
#define NIRFSG_ATTR_P2P_SPACE_AVAILABLE_IN_ENDPOINT          /* ViInt64, read-only */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x7d)
#define NIRFSG_ATTR_P2P_MOST_SPACE_AVAILABLE_IN_ENDPOINT     /* ViInt64, read-only */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x7e)
#define NIRFSG_ATTR_P2P_ENDPOINT_COUNT                       /* ViInt32, read-only */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x7f)
#define NIRFSG_ATTR_P2P_DATA_TRANSFER_PERMISSION_INTERVAL               /* ViInt64 */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x86)
#define NIRFSG_ATTR_P2P_DATA_TRANSFER_PERMISSION_INITIAL_CREDITS        /* ViInt64 */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x87)
#define NIRFSG_ATTR_P2P_IS_FINITE_GENERATION                          /* ViBoolean */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xd9)
#define NIRFSG_ATTR_P2P_NUMBER_OF_SAMPLES_TO_GENERATE                   /* ViInt64 */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xda)
#define NIRFSG_ATTR_P2P_GENERATION_FIFO_SAMPLE_QUANTUM                  /* ViInt64 */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xdb)

/*- niRFSG Attribute Aliases --------------------------------------------*/

/* Attribute Aliases. The attribute names on the right (native names) are consistent
   with the names of their related Driver-Specific attributes.  The attribute names on
   the left (attribute aliases) are consistent with the IVI-defined attribute names.
   Either name can be used.  niRFSG (Driver-Specific) documentation and examples will
   use the names on the right (native names).
*/
#define NIRFSG_ATTR_REFERENCE_OSCILLATOR_EXTERNAL_FREQUENCY                   NIRFSG_ATTR_REF_CLOCK_RATE
#define NIRFSG_ATTR_ARB_CLOCK_FREQUENCY                                       NIRFSG_ATTR_IQ_RATE
#define NIRFSG_ATTR_ARB_TRIGGER_SOURCE                                        NIRFSG_ATTR_START_TRIGGER_TYPE
#define NIRFSG_ATTR_ARB_EXTERNAL_TRIGGER_SLOPE                                NIRFSG_ATTR_DIGITAL_EDGE_START_TRIGGER_EDGE


/****************************************************************************
 *--------- Device-Specific Attribute Defines (5644R/5645R/5646R) ----------*
 ****************************************************************************/

/*- Trigger Synchronization Attributes ---------------------------------------------*/
#define NIRFSG_ATTR_SYNC_START_TRIGGER_MASTER                          /* ViBoolean */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x9B)
#define NIRFSG_ATTR_SYNC_START_TRIGGER_DIST_LINE                       /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x9C)
#define NIRFSG_ATTR_SYNC_SCRIPT_TRIGGER_MASTER                         /* ViBoolean */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x8E)
#define NIRFSG_ATTR_SYNC_SCRIPT_TRIGGER_DIST_LINE                      /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x8F)
#define NIRFSG_ATTR_SYNC_SAMPLE_CLOCK_MASTER                           /* ViBoolean */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xB4)
#define NIRFSG_ATTR_SYNC_SAMPLE_CLOCK_DIST_LINE                        /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xB5)

/*- Events Attributes -------------------------------------------------------------*/
#define NIRFSG_ATTR_EVENTS_DELAY                                       /* ViReal64 */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x9A)

/*- Signal Path Attributes ---------------------------------------------------------*/
#define NIRFSG_ATTR_INTERPOLATION_DELAY                                /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x99)
#define NIRFSG_ATTR_RELATIVE_DELAY                                     /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xDC)
#define NIRFSG_ATTR_ABSOLUTE_DELAY                                     /* ViReal64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xE1)

/*- Output Port -------------------------------------------------------------------*/
#define NIRFSG_ATTR_OUTPUT_PORT                                        /* ViInt32  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x90)

/*- LO control attributes ---------------------------------------------------------*/
#define NIRFSG_ATTR_LO_SOURCE                                          /* ViString */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x96)
#define NIRFSG_ATTR_LO_FREQUENCY                                       /* ViReal64 */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xC7)
#define NIRFSG_ATTR_LO_FREQUENCY_STEP_SIZE                             /* ViReal64 */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x97)
#define NIRFSG_ATTR_LO_PLL_FRACTIONAL_MODE_ENABLED                     /* ViInt32  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x98)
#define NIRFSG_ATTR_LO_VCO_FREQUENCY_STEP_SIZE                         /* ViReal64 */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x101)

/*- IQ Out Port attributes --------------------------------------------------------*/
#define NIRFSG_ATTR_IQ_OUT_PORT_CARRIER_FREQUENCY                      /* ViReal64 */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x91)
#define NIRFSG_ATTR_IQ_OUT_PORT_TERMINAL_CONFIGURATION                 /* ViInt32  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x92)
#define NIRFSG_ATTR_IQ_OUT_PORT_LEVEL                                  /* ViReal64 */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x93)
#define NIRFSG_ATTR_IQ_OUT_PORT_COMMON_MODE_OFFSET                     /* ViReal64 */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x94)
#define NIRFSG_ATTR_IQ_OUT_PORT_OFFSET                                 /* ViReal64 */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x95)
#define NIRFSG_ATTR_IQ_OUT_PORT_TEMPERATURE                            /* ViReal64 */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xA1)
#define NIRFSG_ATTR_IQ_OUT_PORT_LOAD_IMPEDANCE                         /* ViReal64 */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xA3)

/*- RF Blanking Attributes --------------------------------------------------------*/
#define NIRFSG_ATTR_RF_BLANKING_SOURCE                                 /* ViString  */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xA2)

/*- RF Upconverter attributes -----------------------------------------------------*/
#define NIRFSG_ATTR_UPCONVERTER_FREQUENCY_OFFSET_MODE                  /* ViInt32  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xF8)
#define NIRFSG_ATTR_UPCONVERTER_FREQUENCY_OFFSET                       /* ViReal64 */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xA0)

/*- FPGA Extensions attributes ----------------------------------------------------*/
#define NIRFSG_ATTR_FPGA_BITFILE_PATH                                  /* ViString */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xBA)
#define NIRFSG_ATTR_FPGA_TARGET_NAME                                   /* ViString */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xFB)

/*- Host DMA Buffer Attributes ----------------------------------------------------*/
#define NIRFSG_ATTR_HOST_DMA_BUFFER_SIZE                               /* ViInt64  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xEF)

/*- De-embedding Attributes -------------------------------------------------------*/
#define NIRFSG_ATTR_DEEMBEDDING_TYPE                                   /* ViInt32  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xFC)
#define NIRFSG_ATTR_DEEMBEDDING_SELECTED_TABLE                         /* ViString */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xFD)
#define NIRFSG_ATTR_DEEMBEDDING_COMPENSATION_GAIN                      /* ViReal64 */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x121)


/*- Per-Waveform Attributes. -------------------------------------------------------*/
#define NIRFSG_ATTR_WAVEFORM_IQ_RATE                           /* ViReal64 */                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x107)
#define NIRFSG_ATTR_WAVEFORM_SIGNAL_BANDWIDTH                  /* ViReal64 */                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x108)
#define NIRFSG_ATTR_WAVEFORM_RUNTIME_SCALING                   /* ViReal64 */                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x109)
#define NIRFSG_ATTR_WAVEFORM_PAPR                              /* ViReal64 */                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x10A)
#define NIRFSG_ATTR_WAVEFORM_FILEPATH                          /* ViString, read only */     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x110)
#define NIRFSG_ATTR_WAVEFORM_RF_BLANKING                       /* ViInt32 */                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x116)
#define NIRFSG_ATTR_WAVEFORM_WAVEFORM_SIZE                     /* ViInt32 */                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x129)

/****************************************************************************
 *------ Device-Specific Attribute Value Defines (5644R/5645R/5646R) -------*
 ****************************************************************************/

/*- Values for NIRFSG_ATTR_OUTPUT_PORT */
#define NIRFSG_VAL_RF_OUT              14000
#define NIRFSG_VAL_IQ_OUT              14001
#define NIRFSG_VAL_CAL_OUT             14002
#define NIRFSG_VAL_I_ONLY              14003

/*- Values for niRFSG 5840 Lo Align Daisy Chain.vi in the niRFSG RF Port Type.ctl -*/
#define NIRFSG_VAL_PORT_RF_IN          14500
#define NIRFSG_VAL_PORT_RF_OUT         14501

/*- Values for NIRFSG_ATTR_IQ_OUT_PORT_TERMINAL_CONFIGURATION */
#define NIRFSG_VAL_DIFFERENTIAL        15000
#define NIRFSG_VAL_SINGLE_ENDED        15001

/*- Trigger Synchronization attribute values -*/
#define NIRFSG_VAL_SYNC_START_TRIGGER_STR               "Sync_Start"
#define NIRFSG_VAL_SYNC_SCRIPT_TRIGGER_STR              "Sync_Script"

/*- LO Source attribute values -*/
#define NIRFSG_VAL_LO_SOURCE_ONBOARD_STR                    "Onboard"
#define NIRFSG_VAL_LO_SOURCE_LO_IN_STR                      "LO_In"
#define NIRFSG_VAL_LO_SOURCE_SECONDARY_STR                  "Secondary"
#define NIRFSG_VAL_LO_SOURCE_SG_SA_SHARED_STR               "SG_SA_Shared"
#define NIRFSG_VAL_LO_SOURCE_AUTOMATIC_SG_SA_SHARED_STR     "Automatic_SG_SA_Shared"

/****************************************************************************
 *------------------------ Attribute Value Defines -------------------------*
 ****************************************************************************/

/*- Values for function WaitUntilSetttled -*/
#define NIRFSG_VAL_MAX_TIME_IMMEDIATE                                  IVIRFSIGGEN_VAL_MAX_TIME_IMMEDIATE
#define NIRFSG_VAL_MAX_TIME_INFINITE                                   IVIRFSIGGEN_VAL_MAX_TIME_INFINITE

/*- Values for attributes NIRFSG_ATTR_START_TRIGGER_TYPE and NIRFSG_ATTR_SCRIPT_TRIGGER_TYPE -*/
#define NIRFSG_VAL_ARB_TRIGGER_SOURCE_IMMEDIATE                        NIRFSG_VAL_NONE
#define NIRFSG_VAL_ARB_TRIGGER_SOURCE_EXTERNAL                         NIRFSG_VAL_DIGITAL_EDGE
#define NIRFSG_VAL_ARB_TRIGGER_SOURCE_SOFTWARE                         NIRFSG_VAL_SOFTWARE

/*- Alias Values for attributes NIRFSG_ATTR_DIGITAL_EDGE_START_TRIGGER_EDGE and NIRFSG_ATTR_DIGITAL_EDGE_SCRIPT_TRIGGER_EDGE -*/
#define NIRFSG_VAL_ARB_EXTERNAL_TRIGGER_SLOPE_POSITIVE                 NIRFSG_VAL_RISING_EDGE
#define NIRFSG_VAL_ARB_EXTERNAL_TRIGGER_SLOPE_NEGATIVE                 NIRFSG_VAL_FALLING_EDGE

/*- Values for boolean (enabled/disabled) attributes -*/
#define NIRFSG_VAL_ENABLE                       VI_TRUE
#define NIRFSG_VAL_DISABLE                      VI_FALSE

/*- Additional value for NIRFSG_ATTR_PHASE_CONTINUITY and NIRFSG_ATTR_UPCONVERTER_FREQUENCY_OFFSET_MODE */
#define NIRFSG_VAL_AUTO                         -1

/*-Enum value for attribute NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION_MODE. */
#define NIRFSG_VAL_MANUAL                       0

/*- Additional value for NIRFSG_ATTR_RF_IN_LO_EXPORT_ENABLED */
#define NIRFSG_VAL_UNSPECIFIED                  -2

/*- Values for NIRFSG_ATTR_START_TRIGGER_TYPE, NIRFSG_ATTR_SCRIPT_TRIGGER_TYPE
    and NIRFSG_ATTR_CONFIGURATION_LIST_STEP_TRIGGER_TYPE-*/
#define NIRFSG_VAL_NONE                         IVIRFSIGGEN_VAL_ARB_TRIGGER_SOURCE_IMMEDIATE
#define NIRFSG_VAL_DIGITAL_EDGE                 IVIRFSIGGEN_VAL_ARB_TRIGGER_SOURCE_EXTERNAL
#define NIRFSG_VAL_SOFTWARE                     IVIRFSIGGEN_VAL_ARB_TRIGGER_SOURCE_SOFTWARE

/*- Additional value for NIRFSG_ATTR_START_TRIGGER_TYPE */
#define NIRFSG_VAL_P2P_ENDPOINT_FULLNESS        3

/*- Additional value for NIRFSG_ATTR_SCRIPT_TRIGGER_TYPE */
#define NIRFSG_VAL_DIGITAL_LEVEL                8000

/*- Values for NIRFSG_ATTR_DIGITAL_EDGE_START_TRIGGER_EDGE & NIRFSG_ATTR_DIGITAL_EDGE_SCRIPT_TRIGGER_EDGE -*/
#define NIRFSG_VAL_RISING_EDGE                  IVIRFSIGGEN_VAL_ARB_EXTERNAL_TRIGGER_SLOPE_POSITIVE
#define NIRFSG_VAL_FALLING_EDGE                 IVIRFSIGGEN_VAL_ARB_EXTERNAL_TRIGGER_SLOPE_NEGATIVE

/*- Values for NIRFSG_ATTR_DIGITAL_EDGE_CONFIGURATION_LIST_STEP_TRIGGER_EDGE */
/* #define NIRFSG_VAL_RISING_EDGE                  IVIRFSIGGEN_VAL_ARB_EXTERNAL_TRIGGER_SLOPE_POSITIVE (Defined Elsewhere)*/

/*- Values for NIRFSG_ATTR_DIGITAL_LEVEL_SCRIPT_TRIGGER_ACTIVE_LEVEL */
#define NIRFSG_VAL_ACTIVE_HIGH                  9000
#define NIRFSG_VAL_ACTIVE_LOW                   9001

/*- Values for Signals -*/
#define NIRFSG_VAL_START_TRIGGER                      0
#define NIRFSG_VAL_SCRIPT_TRIGGER                     1
#define NIRFSG_VAL_MARKER_EVENT                       2
#define NIRFSG_VAL_REF_CLOCK                          3
#define NIRFSG_VAL_STARTED_EVENT                      4
#define NIRFSG_VAL_DONE_EVENT                         5
#define NIRFSG_VAL_CONFIGURATION_LIST_STEP_TRIGGER    6
#define NIRFSG_VAL_CONFIGURATION_SETTLED_EVENT        7

/*- Values for attributes NIRFSG_ATTR_DIGITAL_EDGE_START_TRIGGER_SOURCE,
    NIRFSG_ATTR_DIGITAL_EDGE_SCRIPT_TRIGGER_SOURCE,
    NIRFSG_ATTR_DIGITAL_EDGE_CONFIGURATION_LIST_STEP_TRIGGER_SOURCE,
    NIRFSG_ATTR_EXPORTED_START_TRIGGER_OUTPUT_TERMINAL,
    and NIRFSG_ATTR_EXPORTED_SCRIPT_TRIGGER_OUTPUT_TERMINAL -*/
#define NIRFSG_VAL_DO_NOT_EXPORT_STR            ""
#define NIRFSG_VAL_TRIG_IN_STR                  "TrigIn"
#define NIRFSG_VAL_TRIG_OUT_STR                 "TrigOut"
#define NIRFSG_VAL_PFI0_STR                     "PFI0"
#define NIRFSG_VAL_PFI1_STR                     "PFI1"
#define NIRFSG_VAL_PFI2_STR                     "PFI2"
#define NIRFSG_VAL_PFI3_STR                     "PFI3"
#define NIRFSG_VAL_PFI4_STR                     "PFI4"
#define NIRFSG_VAL_PFI5_STR                     "PFI5"
#define NIRFSG_VAL_PXI_TRIG0_STR                "PXI_Trig0"
#define NIRFSG_VAL_PXI_TRIG1_STR                "PXI_Trig1"
#define NIRFSG_VAL_PXI_TRIG2_STR                "PXI_Trig2"
#define NIRFSG_VAL_PXI_TRIG3_STR                "PXI_Trig3"
#define NIRFSG_VAL_PXI_TRIG4_STR                "PXI_Trig4"
#define NIRFSG_VAL_PXI_TRIG5_STR                "PXI_Trig5"
#define NIRFSG_VAL_PXI_TRIG6_STR                "PXI_Trig6"
#define NIRFSG_VAL_PXI_TRIG7_STR                "PXI_Trig7"
#define NIRFSG_VAL_PXI_STAR_STR                 "PXI_STAR"
#define NIRFSG_VAL_PXIE_DSTARB_STR              "PXIe_DStarB"
#define NIRFSG_VAL_PXIE_DSTARC_STR              "PXIe_DStarC"
#define NIRFSG_VAL_RTSI0_STR                    "RTSI0"
#define NIRFSG_VAL_RTSI1_STR                    "RTSI1"
#define NIRFSG_VAL_RTSI2_STR                    "RTSI2"
#define NIRFSG_VAL_RTSI3_STR                    "RTSI3"
#define NIRFSG_VAL_RTSI4_STR                    "RTSI4"
#define NIRFSG_VAL_RTSI5_STR                    "RTSI5"
#define NIRFSG_VAL_RTSI6_STR                    "RTSI6"
#define NIRFSG_VAL_RTSI7_STR                    "RTSI7"
#define NIRFSG_VAL_DIO0_STR                     "DIO/PFI0"
#define NIRFSG_VAL_DIO1_STR                     "DIO/PFI1"
#define NIRFSG_VAL_DIO2_STR                     "DIO/PFI2"
#define NIRFSG_VAL_DIO3_STR                     "DIO/PFI3"
#define NIRFSG_VAL_DIO4_STR                     "DIO/PFI4"
#define NIRFSG_VAL_DIO5_STR                     "DIO/PFI5"
#define NIRFSG_VAL_DIO6_STR                     "DIO/PFI6"
#define NIRFSG_VAL_DIO7_STR                     "DIO/PFI7"

/*- Values for NIRFSG_ATTR_REF_CLOCK_RATE -*/
#define NIRFSG_VAL_10MHz                        10000000
/* #define NIRFSG_VAL_AUTO                         -1     (Defined Elsewhere) */
/* NIRFSG_ATTR_REF_CLOCK_RATE can also accept any value that the underlying hardware supports */

/*- Additional values for NIRFSG_ATTR_DIGITAL_EDGE_CONFIGURATION_LIST_STEP_TRIGGER_SOURCE -*/
#define NIRFSG_VAL_TIMER_EVENT_STR              "TimerEvent"
#define NIRFSG_VAL_MARKER0_EVENT_STR            "Marker0Event"
#define NIRFSG_VAL_MARKER1_EVENT_STR            "Marker1Event"
#define NIRFSG_VAL_MARKER2_EVENT_STR            "Marker2Event"
#define NIRFSG_VAL_MARKER3_EVENT_STR            "Marker3Event"

/*- Values for attribute NIRFSG_ATTR_CONFIGURATION_LIST_REPEAT -*/
#define NIRFSG_VAL_CONFIGURATION_LIST_REPEAT_CONTINUOUS          0
#define NIRFSG_VAL_CONFIGURATION_LIST_REPEAT_SINGLE              1

/*- Values for attributes NIRFSG_ATTR_REF_CLOCK_SOURCE and NIRFSG_ATTR_PXI_CHASSIS_CLK10_SOURCE -*/
#define NIRFSG_VAL_ONBOARD_CLOCK_STR            "OnboardClock"
#define NIRFSG_VAL_REF_IN_STR                   "RefIn"
#define NIRFSG_VAL_PXI_CLK_STR                  "PXI_CLK"
#define NIRFSG_VAL_NONE_STR                     "None"
#define NIRFSG_VAL_REF_IN_2_STR                 "RefIn2"
#define NIRFSG_VAL_PXI_CLK_MASTER_STR           "PXI_ClkMaster"
/* #define NIRFSG_VAL_CLK_IN_STR                "ClkIn" (Defined Elsewhere)*/

/*- Values for NIRFSG_ATTR_EXPORTED_REF_CLOCK_OUTPUT_TERMINAL -*/
#define NIRFSG_VAL_REF_OUT_STR                  "RefOut"
#define NIRFSG_VAL_REF_OUT2_STR                 "RefOut2"
#define NIRFSG_VAL_CLK_OUT_STR                  "ClkOut"
/* #define NIRFSG_VAL_DO_NOT_EXPORT_STR         ""        (Defined Elsewhere)*/

/* Values for signal names */
#define NIRFSG_VAL_SCRIPT_TRIGGER0              "scriptTrigger0"
#define NIRFSG_VAL_SCRIPT_TRIGGER1              "scriptTrigger1"
#define NIRFSG_VAL_SCRIPT_TRIGGER2              "scriptTrigger2"
#define NIRFSG_VAL_SCRIPT_TRIGGER3              "scriptTrigger3"
#define NIRFSG_VAL_MARKER0                      "marker0"
#define NIRFSG_VAL_MARKER1                      "marker1"
#define NIRFSG_VAL_MARKER2                      "marker2"
#define NIRFSG_VAL_MARKER3                      "marker3"

/* Values for endpoint names */
#define NIRFSG_VAL_P2P_ENDPOINT0                "FIFOEndpoint0"

/*- Values for attribute NIRFSG_ATTR_GENERATION_MODE -*/
#define NIRFSG_VAL_CW                           1000
#define NIRFSG_VAL_ARB_WAVEFORM                 1001
#define NIRFSG_VAL_SCRIPT                       1002

/*- Values for attribute NIRFSG_ATTR_LOOP_BANDWIDTH, NIRFSG_ATTR_REF_PLL_BANDWIDTH,
    and NIRFSG_ATTR_ANALOG_MODULATION_PM_LOOP_BANDWIDTH  -*/
#define NIRFSG_VAL_NARROW                       0
#define NIRFSG_VAL_MEDIUM                       1
#define NIRFSG_VAL_WIDE                         2

/*- Values for attribute NIRFSG_ATTR_YIG_MAIN_COIL_DRIVE -*/
#define NIRFSG_VAL_SLOW                         0
#define NIRFSG_VAL_FAST                         1

/*- Values for attribute NIRFSG_ATTR_ARB_SAMPLE_CLOCK_SOURCE -*/
/* #define NIRFSG_VAL_ONBOARD_CLOCK_STR         "OnboardClock" (Defined Elsewhere)*/
#define NIRFSG_VAL_CLK_IN_STR                   "ClkIn"

/*- Values for attribute NIRFSG_ATTR_ANALOG_MODULATION_TYPE -*/
/* #define NIRFSG_VAL_NONE                      0     (Defined Elsewhere)*/
#define NIRFSG_VAL_FM                           2000
#define NIRFSG_VAL_PM                           2001
#define NIRFSG_VAL_AM                           2002

/*- Values for attribute NIRFSG_ATTR_ANALOG_MODULATION_WAVEFORM_TYPE -*/
#define NIRFSG_VAL_SINE                         3000
#define NIRFSG_VAL_SQUARE                       3001
#define NIRFSG_VAL_TRIANGLE                     3002

/*- Values for attribute NIRFSG_ATTR_DIGITAL_MODULATION_TYPE -*/
/* #define NIRFSG_VAL_NONE                         0     (Defined Elsewhere)*/
#define NIRFSG_VAL_FSK                          4000
#define NIRFSG_VAL_OOK                          4001
#define NIRFSG_VAL_PSK                          4002

/*- Values for attribute NIRFSG_ATTR_DIGITAL_MODULATION_WAVEFORM_TYPE;
    NIRFSG_VAL_USER_DEFINED is also for NIRFSG_ATTR_UPCONVERTER_FREQUENCY_OFFSET_MODE -*/
#define NIRFSG_VAL_PRBS                         5000
#define NIRFSG_VAL_USER_DEFINED                 5001

/*- Values for attribute NIRFSG_ATTR_ARB_ONBOARD_SAMPLE_CLOCK_MODE -*/
#define NIRFSG_VAL_HIGH_RESOLUTION              6000
#define NIRFSG_VAL_DIVIDE_DOWN                  6001

/*- Values for attribute NIRFSG_ATTR_POWER_LEVEL_TYPE -*/
#define NIRFSG_VAL_AVERAGE_POWER                7000
#define NIRFSG_VAL_PEAK_POWER                   7001

/*- Values for niRFSG_SetArbWaveformNextWritePosition relativeTo -*/
#define NIRFSG_VAL_START_OF_WAVEFORM            8000
#define NIRFSG_VAL_CURRENT_POSITION             8001

/*- Values for attribute NIRFSG_ATTR_ARB_FILTER_TYPE -*/
#define NIRFSG_VAL_ARB_FILTER_TYPE_NONE                10000
#define NIRFSG_VAL_ARB_FILTER_TYPE_ROOT_RAISED_COSINE  10001
#define NIRFSG_VAL_ARB_FILTER_TYPE_RAISED_COSINE       10002

/*- Values for attribute NIRFSG_ATTR_IQ_OFFSET_UNITS -*/
#define NIRFSG_VAL_PERCENT                      11000
#define NIRFSG_VAL_VOLTS                        11001

/*- Values for attribute NIRFSG_ATTR_FREQUENCY_SETTLING_UNITS -*/
#define NIRFSG_VAL_TIME_AFTER_LOCK              12000
#define NIRFSG_VAL_TIME_AFTER_IO                12001
#define NIRFSG_VAL_PPM                          12002

/*- Values for Modules -*/
#define NIRFSG_VAL_PRIMARY_MODULE               13000
#define NIRFSG_VAL_AWG                          13001
#define NIRFSG_VAL_LO                           13002

/*- Values for attribute NIRFSG_ATTR_PEAK_POWER_ADJUSTMENT_INHERITANCE -*/
#define NIRFSG_VAL_EXACT_MATCH                  0
#define NIRFSG_VAL_MINIMUM                      1
#define NIRFSG_VAL_MAXIMUM                      2

/*- Values for attribute NIRFSG_ATTR_AMP_PATH -*/
#define NIRFSG_VAL_HIGH_POWER                   16000
#define NIRFSG_VAL_LOW_HARMONIC                 16001

/*- Values for attribute NIRFSG_ATTR_ANALOG_MODULATION_FM_BAND -*/
#define NIRFSG_VAL_NARROWBAND                   17000
#define NIRFSG_VAL_WIDEBAND                     17001

/*- Values for attribute NIRFSG_ATTR_ANALOG_MODULATION_FM_NARROWBAND_INTEGRATOR -*/
#define NIRFSG_VAL_100HZ_TO_1KHZ                18000
#define NIRFSG_VAL_1KHZ_TO_10KHZ                18001
#define NIRFSG_VAL_10KHZ_TO_100KHZ              18002

/*- Values for attribute NIRFSG_ATTR_ANALOG_MODULATION_PM_MODE -*/
#define NIRFSG_VAL_HIGH_DEVIATION               19000
#define NIRFSG_VAL_LOW_PHASE_NOISE              19001

/*- Values for attribute NIRFSG_ATTR_PULSE_MODULATION_MODE -*/
#define NIRFSG_VAL_OPTIMAL_MATCH                20000
#define NIRFSG_VAL_HIGH_ISOLATION               20001
#define NIRFSG_VAL_PULSE_MODULATION_ANALOG      20002
#define NIRFSG_VAL_PULSE_MODULATION_DIGITAL     20003
#define NIRFSG_VAL_PULSE_MODULATION_ANALOG_HIGH_ISOLATION   NIRFSG_VAL_HIGH_ISOLATION

/*- Values for attribute NIRFSG_ATTR_PULSE_MODULATION_SOURCE -*/
#define NIRFSG_VAL_PULSE_IN_STR                 "PulseIn"

/*- Values for attribute NIRFSG_ATTR_PULSE_MODULATION_EVENT_OUTPUT_TERMINAL -*/
#define NIRFSG_VAL_PULSE_OUT_STR                "PulseOut"

/*- Values for attribute NIRFSG_ATTR_MARKER_EVENT_TOGGLE_INITIAL_STATE -*/
#define NIRFSG_VAL_DIGITAL_LOW                  21000
#define NIRFSG_VAL_DIGITAL_HIGH                 21001

/*- Values for attribute NIRFSG_ATTR_MARKER_EVENT_PULSE_WIDTH_UNITS -*/
#define NIRFSG_VAL_SECONDS                      22000
#define NIRFSG_VAL_SAMPLE_CLOCK_PERIODS         22001

/*- Values for attribute NIRFSG_ATTR_MARKER_EVENT_OUTPUT_BEHAVIOR -*/
#define NIRFSG_VAL_PULSE                        23000
#define NIRFSG_VAL_TOGGLE                       23001

/*- Values for S-parameters orientation passed to Create De-embedding S-parameter Table functions -*/
#define NIRFSG_VAL_PORT1_TOWARDS_DUT            24000
#define NIRFSG_VAL_PORT2_TOWARDS_DUT            24001

/*- Values for NIRFSG_ATTR_DEEMBEDDING_TYPE attribute -*/
#define NIRFSG_VAL_DEEMBEDDING_TYPE_NONE        25000
#define NIRFSG_VAL_DEEMBEDDING_TYPE_SCALAR      25001
#define NIRFSG_VAL_DEEMBEDDING_TYPE_VECTOR      25002

/*- Values for niRFSG_ConfigureDeembeddingTableInterpolationLinear -*/
#define NIRFSG_VAL_LINEAR_INTERPOLATION_FORMAT_REAL_AND_IMAGINARY      26000
#define NIRFSG_VAL_LINEAR_INTERPOLATION_FORMAT_MAGNITUDE_AND_PHASE     26001
#define NIRFSG_VAL_LINEAR_INTERPOLATION_FORMAT_MAGNITUDE_DB_AND_PHASE  26002

// Values for NIRFSG_ATTR_UPCONVERTER_FREQUENCY_OFFSET_MODE
/* #define NIRFSG_VAL_AUTO                         -1      (Defined Elsewhere) */
/* #define NIRFSG_VAL_USER_DEFINED                 5001    (Defined Elsewhere) */
/* #define NIRFSG_VAL_ENABLE                       VI_TRUE (Defined Elsewhere) */

/*- Values for attribute NIRFSG_ATTR_OVERFLOW_ERROR_REPORTING -*/
#define NIRFSG_VAL_ERROR_REPORTING_WARNING      1301
#define NIRFSG_VAL_ERROR_REPORTING_DISABLED     1302

/*- Values for niRFSG_SelfCalibrateRange stepsToOmit -*/
#define NIRFSG_VAL_SELF_CAL_OMIT_NONE               0x0000000000000000
#define NIRFSG_VAL_SELF_CAL_LO_SELF_CAL             0x0000000000000001
#define NIRFSG_VAL_SELF_CAL_POWER_LEVEL_ACCURACY    0x0000000000000002
#define NIRFSG_VAL_SELF_CAL_RESIDUAL_LO_POWER       0x0000000000000004
#define NIRFSG_VAL_SELF_CAL_IMAGE_SUPPRESSION       0x0000000000000008
#define NIRFSG_VAL_SELF_CAL_SYNTHESIZER_ALIGNMENT   0x0000000000000010

/*- Values for niRFSG_ResetWithOptions stepsToOmit -*/
#define NIRFSG_VAL_RESET_WITH_OPTIONS_NONE               0x0ULL // reset everything
#define NIRFSG_VAL_RESET_WITH_OPTIONS_WAVEFORMS          0x1ULL
#define NIRFSG_VAL_RESET_WITH_OPTIONS_SCRIPTS            0x2ULL
#define NIRFSG_VAL_RESET_WITH_OPTIONS_ROUTES             0x4ULL
#define NIRFSG_VAL_RESET_WITH_OPTIONS_DEEMBEDDING_TABLES 0x8ULL

#define NIRFSG_MAX_ERROR_MESSAGE_SIZE           1024

/*- Enum values for Load Configuration Load Skip Options -*/
#define RFSG_VAL_LOAD_CONFIGURATIONS_FROM_FILE_LOAD_OPTIONS_SKIP_NONE       0
#define RFSG_VAL_LOAD_CONFIGURATIONS_FROM_FILE_LOAD_OPTIONS_SKIP_WAVEFORMS  1

/*- Enum values for Load Configuration Reset Skip Options. Keeping the values same as the enum values for niRFSG_ResetWithOptions -*/
#define RFSG_VAL_LOAD_CONFIGURATIONS_FROM_FILE_RESET_OPTIONS_SKIP_NONE                0x0ULL
#define RFSG_VAL_LOAD_CONFIGURATIONS_FROM_FILE_RESET_OPTIONS_SKIP_WAVEFORMS           0x1ULL
#define RFSG_VAL_LOAD_CONFIGURATIONS_FROM_FILE_RESET_OPTIONS_SKIP_SCRIPTS             0x2ULL
#define RFSG_VAL_LOAD_CONFIGURATIONS_FROM_FILE_RESET_OPTIONS_SKIP_DEEMBEDDING_TABLES  0x8ULL

/*-Enum value for attribute NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION_MODE. */
/* #define NIRFSG_VAL_AUTO                        -1      (Defined Elsewhere) */
/* #define NIRFSG_VAL_MANUAL                       0      (Defined Elsewhere) */

/****************************************************************************
 *---------------- Instrument Driver struct definititions  -----------------*
 ****************************************************************************/

/*- Use with:
      niRFSG_WriteArbWaveformComplexF64
*/
#if !defined(_NIComplexNumber)
typedef struct NIComplexNumber_struct {
   ViReal64 real;
   ViReal64 imaginary;
} NIComplexNumber;
#define _NIComplexNumber
#endif

/*- Use with:
      niRFSG_WriteArbWaveformComplexF32
*/
#if !defined(_NIComplexNumberF32)
#define _NIComplexNumberF32

#if kRFSG_32BitPlatform
   #pragma pack(push, 1)
#elif kRFSG_64BitPlatform
   // Nothing needed for 64 bit platforms
#else
   #error Unknown Platform
#endif

typedef struct NIComplexNumberF32_struct {
   ViReal32 real;
   ViReal32 imaginary;
} NIComplexNumberF32;

#if kRFSG_32BitPlatform
   #pragma pack(pop)
#elif kRFSG_64BitPlatform
   // Nothing needed for 64 bit platforms
#else
   #error Unknown Platform
#endif

#endif
/*- Use with:
      niRFSG_WriteArbWaveformComplexI16
*/
#if !defined(_NIComplexI16)
typedef struct NIComplexI16_struct {
   ViInt16 real;
   ViInt16 imaginary;
} NIComplexI16;
#define _NIComplexI16
#endif

/****************************************************************************
 *---------------- Instrument Driver Function Declarations -----------------*
 ****************************************************************************/

/*- Init and Close Functions -----------------------------------------------*/
ViStatus _VI_FUNC niRFSG_init
(
   ViRsrc      resourceName,
   ViBoolean   IDQuery,
   ViBoolean   resetDevice,
   ViSession*  newVi
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_InitWithOptions
(
   ViRsrc        resourceName,
   ViBoolean     IDQuery,
   ViBoolean     resetDevice,
   ViConstString optionString,
   ViSession*    newVi
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_close
(
   ViSession vi
);
/*- RFSigGenBase Functions -------------------------------------------------*/
ViStatus _VI_FUNC niRFSG_ConfigureRF
(
   ViSession   vi,
   ViReal64    frequency,
   ViReal64    powerLevel
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ConfigurePowerLevelType
(
   ViSession vi,
   ViInt32 powerLevelType
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_DisableAllModulation
(
   ViSession vi
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_WaitUntilSettled
(
   ViSession   vi,
   ViInt32     maxTimeMilliseconds
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ConfigureOutputEnabled
(
   ViSession vi,
   ViBoolean outputEnabled
);

/*- Control Functions ------------------------------------------------------*/
ViStatus _VI_FUNC niRFSG_Commit
(
   ViSession vi
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_Initiate
(
   ViSession vi
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_Abort
(
   ViSession vi
);

/*- Arb Generator Functions ------------------------------------------------*/
ViStatus _VI_FUNC niRFSG_AllocateArbWaveform
(
   ViSession      vi,
   ViConstString  waveformName,
   ViInt32        sizeInSamples
);

ViStatus _VI_FUNC niRFSG_WriteArbWaveform
(
   ViSession      vi,
   ViConstString  waveformName,
   ViInt32        numberOfSamples,
   const ViReal64 iData[],
   const ViReal64 qData[],
   ViBoolean      moreDataPending
);

ViStatus _VI_FUNC niRFSG_WriteArbWaveformF32
(
   ViSession      vi,
   ViConstString  waveformName,
   ViInt32        numberOfSamples,
   const ViReal32 iData[],
   const ViReal32 qData[],
   ViBoolean      moreDataPending
);

ViStatus _VI_FUNC niRFSG_WriteArbWaveformComplexF64
(
   ViSession               vi,
   ViConstString           waveformName,
   ViInt32                 numberOfSamples,
   const NIComplexNumber   wfmData[],
   ViBoolean               moreDataPending
);

ViStatus _VI_FUNC niRFSG_WriteArbWaveformComplexF32
(
   ViSession                vi,
   ViConstString            waveformName,
   ViInt32                  numberOfSamples,
   const NIComplexNumberF32 wfmData[],
   ViBoolean                moreDataPending
);

ViStatus _VI_FUNC niRFSG_WriteArbWaveformComplexI16
(
   ViSession            vi,
   ViConstString        waveformName,
   ViInt32              numberOfSamples,
   const NIComplexI16   wfmData[]
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ReadAndDownloadWaveformFromFileTDMS
(
   ViSession vi,
   ViConstString waveformName,
   ViConstString filePath,
   ViUInt32 waveformIndex
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_SetArbWaveformNextWritePosition
(
   ViSession vi,
   ViConstString waveformName,
   ViInt32 relativeTo,
   ViInt32 offset
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ClearArbWaveform
(
   ViSession      vi,
   ViConstString  name
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_SelectArbWaveform
(
   ViSession      vi,
   ViConstString  name
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ClearAllArbWaveforms
(
   ViSession vi
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_QueryArbWaveformCapabilities
(
   ViSession   vi,
   ViInt32*    maxNumberWaveforms,
   ViInt32*    waveformQuantum,
   ViInt32*    minWaveformSize,
   ViInt32*    maxWaveformSize
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ConfigureSignalBandwidth
(
   ViSession vi,
   ViReal64 signalBandwidth
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_CheckIfWaveformExists
(
   ViSession vi,
   ViConstString waveformName,
   ViBoolean* waveformExists
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_CheckIfScriptExists
(
   ViSession vi,
   ViConstString scriptName,
   ViBoolean* scriptExists
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_SetWaveformBurstStartLocations
(
   ViSession vi,
   ViConstString channelName,
   ViInt32 numberOfLocations,
   ViReal64* locations
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_GetWaveformBurstStartLocations
(
   ViSession vi,
   ViConstString channelName,
   ViInt32 numberOfLocations,
   ViReal64* locations,
   ViInt32* requiredSize
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_SetWaveformBurstStopLocations
(
   ViSession vi,
   ViConstString channelName,
   ViInt32 numberOfLocations,
   ViReal64* locations
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_GetWaveformBurstStopLocations
(
   ViSession vi,
   ViConstString channelName,
   ViInt32 numberOfLocations,
   ViReal64* locations,
   ViInt32* requiredSize
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_SetWaveformMarkerEventLocations
(
   ViSession vi,
   ViConstString channelName,
   ViInt32 numberOfLocations,
   ViReal64* locations
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_GetWaveformMarkerEventLocations
(
   ViSession vi,
   ViConstString channelName,
   ViInt32 numberOfLocations,
   ViReal64* locations,
   ViInt32* requiredSize
);
/*- Configuration List Functions ------------------------------------------------------*/
ViStatus _VI_FUNC niRFSG_CreateConfigurationList
(
   ViSession      vi,
   ViConstString  listName,
   ViInt32        numberOfAttributes,
   const ViAttr   configurationListAttributes[],
   ViBoolean      setAsActiveList
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_CreateConfigurationListStep
(
   ViSession      vi,
   ViBoolean      setAsActiveStep
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_DeleteConfigurationList
(
   ViSession      vi,
   ViConstString  listName
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_CheckIfConfigurationListExists
(
   ViSession vi,
   ViConstString listName,
   ViBoolean* listExists
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

/*- Trigger Functions ------------------------------------------------------*/
ViStatus _VI_FUNC niRFSG_SendSoftwareEdgeTrigger
(
   ViSession      vi,
   ViInt32        trigger,
   ViConstString  triggerIdentifier
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ConfigureDigitalEdgeStartTrigger
(
   ViSession      vi,
   ViConstString  source,
   ViInt32        edge
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ConfigureP2PEndpointFullnessStartTrigger
(
   ViSession vi,
   ViInt64 p2pEndpointFullnessLevel
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_DisableStartTrigger
(
   ViSession vi
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ConfigureSoftwareStartTrigger
(
   ViSession vi
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ConfigureDigitalEdgeConfigurationListStepTrigger
(
   ViSession      vi,
   ViConstString  source,
   ViInt32        edge
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_DisableConfigurationListStepTrigger
(
   ViSession vi
);

/*- Clocking Functions -----------------------------------------------------*/
ViStatus _VI_FUNC niRFSG_ConfigureRefClock
(
   ViSession      vi,
   ViConstString  refClockSource,
   ViReal64       refClockRate
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ConfigurePXIChassisClk10
(
   ViSession      vi,
   ViConstString  pxiClk10Source
);

/*- Scripting Functions ----------------------------------------------------*/
ViStatus _VI_FUNC niRFSG_ConfigureGenerationMode
(
   ViSession   vi,
   ViInt32     generationMode
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_WriteScript
(
   ViSession      vi,
   ViConstString  script
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_DeleteScript
(
   ViSession vi,
   ViConstString scriptName
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ConfigureDigitalEdgeScriptTrigger
(
   ViSession      vi,
   ViConstString  triggerID,
   ViConstString  source,
   ViInt32        edge
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ConfigureDigitalLevelScriptTrigger
(
   ViSession      vi,
   ViConstString  triggerID,
   ViConstString  source,
   ViInt32        level
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_DisableScriptTrigger
(
   ViSession      vi,
   ViConstString  triggerID
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ConfigureSoftwareScriptTrigger
(
   ViSession      vi,
   ViConstString  triggerID
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ExportSignal
(
   ViSession      vi,
   ViInt32        signal,
   ViConstString  signalIdentifier,
   ViConstString  outputTerminal
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_GetTerminalName
(
   ViSession      vi,
   ViInt32        signal,
   ViConstString  signalIdentifier,
   ViInt32        bufferSize,
   ViChar         terminalName[]
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_GetAllScriptNames
(
   ViSession  vi,
   ViChar     scriptNames[],
   ViInt32    bufferSize,
   ViInt32*   actualBufferSize
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_GetScript
(
    ViSession vi,
    ViConstString scriptName,
    ViChar script[],
    ViInt32 bufferSize,
    ViInt32* actualBufferSize
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_GetAllNamedWaveformNames
(
   ViSession  vi,
   ViChar     waveformNames[],
   ViInt32    bufferSize,
   ViInt32*   actualBufferSize
);

/*- Peer-to-Peer (P2P) Functions -------------------------------------------*/
ViStatus _VI_FUNC niRFSG_GetStreamEndpointHandle
(
   ViSession      vi,
   ViConstString  streamEndpoint,
   ViUInt32*      readerHandle
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_WriteP2PEndpointI16
(
   ViSession vi,
   ViConstString streamEndpoint,
   ViInt32 numberOfSamples,
   ViInt16 endpointData[]
);
/*- Instrument Specific Functions ------------------------------------------*/
ViStatus _VI_FUNC niRFSG_CheckGenerationStatus
(
   ViSession  vi,
   ViBoolean* isDone
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ConfigureUpconverterPLLSettlingTime
(
   ViSession   vi,
   ViReal64    pllSettlingTime,
   ViBoolean   ensurePLLLocked,
   ViInt32     reservedForFutureUse    /* pass 0 */
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ConfigureDigitalModulationUserDefinedWaveform
(
   ViSession vi,
   ViInt32 numberOfSamples,
   const ViInt8 userDefinedWaveform[]
);

/*- Channel Info Functions ------------------------------------------------------*/
ViStatus _VI_FUNC niRFSG_GetChannelName
(
   ViSession vi,
   ViInt32 index,
   ViInt32 bufferSize,
   ViChar name[]
);

/*- Utility Functions ------------------------------------------------------*/
ViStatus _VI_FUNC niRFSG_reset
(
   ViSession vi
);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ResetAttribute
(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId
);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ResetDevice
(
   ViSession vi
);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ResetWithDefaults
(
   ViSession vi
);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ResetWithOptions
(
   ViSession vi,
   ViUInt64 stepsToOmit
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_SaveConfigurationsToFile
(
   ViSession vi,
   ViConstString channelName,
   ViConstString filePath
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_LoadConfigurationsFromFile
(
   ViSession vi,
   ViConstString channelName,
   ViConstString filePath
);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_InvalidateAllAttributes
(
   ViSession vi
);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_SetUserData
(
   ViSession vi,
   ViConstString identifier,
   ViInt32 bufferSize,
   ViInt8 data[]
);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_GetUserData
(
   ViSession vi,
   ViConstString identifier,
   ViInt32 bufferSize,
   ViInt8 data[],
   ViInt32* actualDataSize
);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_self_test
(
   ViSession   vi,
   ViInt16*    selfTestResult,
   ViChar      selfTestMessage[]
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ChangeExternalCalibrationPassword
(
   ViSession      vi,
   ViConstString  oldPassword,
   ViConstString  newPassword
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_GetExternalCalibrationLastDateAndTime
(
   ViSession      vi,
   ViInt32*       year,
   ViInt32*       month,
   ViInt32*       day,
   ViInt32*       hour,
   ViInt32*       minute,
   ViInt32*       second
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_GetSelfCalibrationDateAndTime
(
   ViSession      vi,
   ViInt32        module,
   ViInt32*       year,
   ViInt32*       month,
   ViInt32*       day,
   ViInt32*       hour,
   ViInt32*       minute,
   ViInt32*       second
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_GetSelfCalibrationTemperature
(
   ViSession      vi,
   ViInt32        module,
   ViReal64*      temperature
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ClearSelfCalibrateRange
(
   ViSession vi
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_revision_query
(
   ViSession   vi,
   ViChar      instrumentDriverRevision[],
   ViChar      firmwareRevision[]
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_Disable
(
   ViSession vi
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_PerformThermalCorrection
(
   ViSession vi
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_PerformPowerSearch
(
   ViSession vi
);
/*- Error Functions --------------------------------------------------------*/
ViStatus _VI_FUNC niRFSG_error_query
(
   ViSession   vi,
   ViInt32*    errorCode,
   ViChar      errorMessage[]
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ClearError
(
   ViSession vi
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_error_message
(
   ViSession   vi,
   ViStatus    errorCode,
   ViChar      errorMessage[]
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_GetError
(
   ViSession   vi,
   ViStatus*   errorCode,
   ViInt32     errorDescriptionBufferSize,
   ViChar      errorDescription[]
);

/*- Calibration Functions --------------------------------------------------*/
ViStatus _VI_FUNC niRFSG_SelfCal
(
   ViSession   vi
);

ViStatus _VI_FUNC niRFSG_SelfCalibrateRange
(
   ViSession vi,
   ViInt64   stepsToOmit,
   ViReal64  minFrequency,
   ViReal64  maxFrequency,
   ViReal64  minPowerLevel,
   ViReal64  maxPowerLevel
);

ViStatus _VI_FUNC niRFSG_5840_AlignLODaisyChain
(
   ViBoolean      useExternalLo,
   ViRsrc         externalLo,
   ViConstString  resourceNames, // comma separated
   ViInt32        portTypesLen,
   ViInt32        *portTypes,
   ViReal64       startFrequency,
   ViReal64       stopFrequency
);

/*- Locking Functions ------------------------------------------------------*/
ViStatus _VI_FUNC niRFSG_LockSession
(
   ViSession   vi,
   ViBoolean*  callerHasLock
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_UnlockSession
(
   ViSession   vi,
   ViBoolean*  callerHasLock
);

/*- Set, Get, and Check Attribute Functions --------------------------------*/
ViStatus _VI_FUNC niRFSG_GetAttributeViInt32 (ViSession vi, ViConstString channelName, ViAttr attribute, ViInt32 *value);
ViStatus _VI_FUNC niRFSG_GetAttributeViInt64 (ViSession vi, ViConstString channelName, ViAttr attribute, ViInt64 *value);
ViStatus _VI_FUNC niRFSG_GetAttributeViReal64 (ViSession vi, ViConstString channelName, ViAttr attribute, ViReal64 *value);
ViStatus _VI_FUNC niRFSG_GetAttributeViString (ViSession vi, ViConstString channelName, ViAttr attribute, ViInt32 bufSize, ViChar value[]);
ViStatus _VI_FUNC niRFSG_GetAttributeViSession (ViSession vi, ViConstString channelName, ViAttr attribute, ViSession *value);
ViStatus _VI_FUNC niRFSG_GetAttributeViBoolean (ViSession vi, ViConstString channelName, ViAttr attribute, ViBoolean *value);

ViStatus _VI_FUNC niRFSG_SetAttributeViInt32 (ViSession vi, ViConstString channelName, ViAttr attribute, ViInt32 value);
ViStatus _VI_FUNC niRFSG_SetAttributeViInt64 (ViSession vi, ViConstString channelName, ViAttr attribute, ViInt64 value);
ViStatus _VI_FUNC niRFSG_SetAttributeViReal64 (ViSession vi, ViConstString channelName, ViAttr attribute, ViReal64 value);
ViStatus _VI_FUNC niRFSG_SetAttributeViString (ViSession vi, ViConstString channelName, ViAttr attribute, ViConstString value);
ViStatus _VI_FUNC niRFSG_SetAttributeViSession (ViSession vi, ViConstString channelName, ViAttr attribute, ViSession value);
ViStatus _VI_FUNC niRFSG_SetAttributeViBoolean (ViSession vi, ViConstString channelName, ViAttr attribute, ViBoolean value);

ViStatus _VI_FUNC niRFSG_CheckAttributeViInt32 (ViSession vi, ViConstString channelName, ViAttr attribute, ViInt32 value);
ViStatus _VI_FUNC niRFSG_CheckAttributeViInt64 (ViSession vi, ViConstString channelName, ViAttr attribute, ViInt64 value);
ViStatus _VI_FUNC niRFSG_CheckAttributeViReal64 (ViSession vi, ViConstString channelName, ViAttr attribute, ViReal64 value);
ViStatus _VI_FUNC niRFSG_CheckAttributeViString (ViSession vi, ViConstString channelName, ViAttr attribute, ViConstString value);
ViStatus _VI_FUNC niRFSG_CheckAttributeViSession (ViSession vi, ViConstString channelName, ViAttr attribute, ViSession value);
ViStatus _VI_FUNC niRFSG_CheckAttributeViBoolean (ViSession vi, ViConstString channelName, ViAttr attribute, ViBoolean value);

ViStatus _VI_FUNC niRFSG_GetMaxSettablePower (ViSession vi, ViReal64 *value);

/*- Sparameter de-embedding API --------------------------------------------*/
ViStatus _VI_FUNC niRFSG_CreateDeembeddingSparameterTableS2PFile(
   ViSession vi,
   ViConstString port,
   ViConstString tableName,
   ViConstString s2pFilePath,
   ViInt32 sparameterOrientation);

ViStatus _VI_FUNC niRFSG_CreateDeembeddingSparameterTableArray(
   ViSession vi,
   ViConstString port,
   ViConstString tableName,
   const ViReal64 frequencies[], ViInt32 frequenciesSize,
   const NIComplexNumber sparameterTable[], ViInt32 sparameterTableSize,
   ViInt32 numberOfPorts,
   ViInt32 sparameterOrientation);

ViStatus _VI_FUNC niRFSG_DeleteDeembeddingTable(
   ViSession vi,
   ViConstString port,
   ViConstString tableName);

ViStatus _VI_FUNC niRFSG_DeleteAllDeembeddingTables(
   ViSession vi);

ViStatus _VI_FUNC niRFSG_ConfigureDeembeddingTableInterpolationNearest
(
   ViSession vi,
   ViConstString port,
   ViConstString tableName
);

ViStatus _VI_FUNC niRFSG_ConfigureDeembeddingTableInterpolationLinear
(
   ViSession vi,
   ViConstString port,
   ViConstString tableName,
   ViInt32 format
);

ViStatus _VI_FUNC niRFSG_ConfigureDeembeddingTableInterpolationSpline
(
   ViSession vi,
   ViConstString port,
   ViConstString tableName
);

ViStatus _VI_FUNC niRFSG_GetDeembeddingSparameters
(
   ViSession vi,
   NIComplexNumber *sparameters, ViInt32 sparametersArraySize,
   ViInt32 *numberOfSparameters,
   ViInt32 *numberOfPorts
);

/****************************************************************************
 *------------------------ Error And Completion Codes ----------------------*
 ****************************************************************************/
#include "niRFSGErrors.h"

// IVI_SPECIFIC_ERROR_BASE == 0xbffa4000
#define NIRFSG_ERROR_BASE (IVI_SPECIFIC_ERROR_BASE + 0x3ff)

// IVI_SPECIFIC_WARN_BASE == 0x3ffa4000
#define NIRFSG_WARN_BASE (IVI_SPECIFIC_WARN_BASE + 0x3ff)

/****************************************************************************
 *---------------------------- End Include File ----------------------------*
 ****************************************************************************/
#include "niRFSGObsolete.h"

#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif
#endif /* ___niRFSG_niRFSG_h___ */





