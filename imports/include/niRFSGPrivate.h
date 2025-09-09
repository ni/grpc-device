#ifndef ___niRFSG_niRFSGPrivate_h___
#define ___niRFSG_niRFSGPrivate_h___

#include "niRFSG.h"
#include "ivi.h"

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

/****************************************************************************
 *----------------- Instrument Driver Revision Information -----------------*
 ****************************************************************************/
#define NIRFSG_DRIVER_VENDOR                "National Instruments"
#if kRFSG_32BitPlatform
   #define NIRFSG_DRIVER_DESCRIPTION           "RF Signal Generator Instrument Driver"
#elif kRFSG_64BitPlatform
   #define NIRFSG_DRIVER_DESCRIPTION           "RF Signal Generator Instrument Driver [Compiled for 64-bit]"
#else
   #error Unknown Platform
#endif


#define MAX_BUFF_SIZE   IVI_MAX_MESSAGE_BUF_SIZE // 256
#define MAX_NUM_DEVS    64L
#define NIRFSG_VAL_NO_OPTION_FLAGS  0
#define NIRFSG_IVI_FP_PRECISION_MAX 0
#define NIRFSG_FGEN_VAL_AUTO_IQ_RATE -1.0

/*
   niRFSG.h defines some Attribute Aliases.  These attribute names are consistent with their equivalent
   IVI-Defined Attribute names.  Our code and documentation will only use the Driver-Specific names.
   Clear the Alias Name to force our code to always use the Driver-Specific name (helps maintainability).
*/
#undef NIRFSG_ATTR_REFERENCE_OSCILLATOR_EXTERNAL_FREQUENCY     // instead use NIRFSG_ATTR_REF_CLOCK_RATE
#undef NIRSFG_ATTR_ARB_CLOCK_FREQUENCY                         // instead use NIRFSG_ATTR_IQ_RATE
#undef NIRFSG_ATTR_ARB_TRIGGER_SOURCE                          // instead use NIRFSG_ATTR_START_TRIGGER_TYPE
#undef NIRFSG_ATTR_ARB_EXTERNAL_TRIGGER_SLOPE                  // instead use NIRFSG_ATTR_DIGITAL_EDGE_START_TRIGGER_EDGE

/*
   Similar to aliased attribute names, clear aliased attribute values.
*/
#undef NIRFSG_VAL_ARB_TRIGGER_SOURCE_IMMEDIATE                 // instead use NIRFSG_VAL_NONE
#undef NIRFSG_VAL_ARB_TRIGGER_SOURCE_EXTERNAL                  // instead use NIRFSG_VAL_DIGITAL_EDGE
#undef NIRFSG_VAL_ARB_TRIGGER_SOURCE_SOFTWARE                  // instead use NIRFSG_VAL_SOFTWARE
#undef NIRFSG_VAL_ARB_EXTERNAL_TRIGGER_SLOPE_POSITIVE          // instead use NIRFSG_VAL_RISING_EDGE
#undef NIRFSG_VAL_ARB_EXTERNAL_TRIGGER_SLOPE_NEGATIVE          // instead use NIRFSG_VAL_FALLING_EDGE

/*
   Starting in 440, IVI remapped IVI_SPECIFIC_PRIVATE_ATTR_BASE from
   (IVI_ATTR_BASE + 100000)
    to
   (IVI_ATTR_BASE + 200000)
   We have decided to continue using the old range in order to avoid
   compatibility issues. (see CAR 530516)
*/
#define RFSG_SPECIFIC_PRIVATE_ATTR_BASE (IVI_ATTR_BASE + 100000)

/*****************************************************************************
 *-----------------------  Hidden Attributes  ---------------*
 *****************************************************************************/
// (numeric gap)
#define NIRFSG_ATTR_ARB_PRODUCT_CODE                                          (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x02)
#define NIRFSG_ATTR_UPCONVERTER_PRODUCT_CODE                                  (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x03)
#define NIRFSG_ATTR_IRFSG_POINTER                           /* ViAddr    */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x04)
// (numeric gap)
#define NIRFSG_ATTR_UPCONVERTER_TASK_ID                     /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x06)
#define NIRFSG_ATTR_INIT_WAITS_UNTIL_SETTLED                /* ViBoolean */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x07)
// (numeric gap)
#define NIRFSG_ATTR_ARB_DIGITAL_FILTER_INTERPOLATION_FACTOR /* ViReal64  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x0a)
#define NIRFSG_ATTR_USE_CALIBRATION                         /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x0d)
#define NIRFSG_ATTR_TEMPERATURE_AVERAGES                    /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x0f)
#define NIRFSG_ATTR_RF_USED_AS_LO                           /* ViBoolean */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x10)
#define NIRFSG_ATTR_ARB_FILTER_FLAT_PASSBAND                /* ViReal64  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x13)
#define NIRFSG_ATTR_ARB_FILTER_GAUSSIAN_BT                  /* ViReal64  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x14)
// Not sure what to name this but probably best to use an enum rather than a boolean
#define NIRFSG_ATTR_ARB_AMPLITUDE_CORRECTION_METHOD         /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x15)
#define NIRFSG_ATTR_5611_LO_FILTER                          /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x16)
#define NIRFSG_ATTR_LO_IN_ATTENUATOR                        /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x17)
#define NIRFSG_ATTR_LO_FILTER_DAC                           /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x18)
#define NIRFSG_ATTR_5611_RF_FILTER                          /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x19)
#define NIRFSG_ATTR_RF_ATTENUATOR                           /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x1a)
#define NIRFSG_ATTR_EXTERNAL_CALIBRATION_LAST_DATE_TIME     /* Timestamp */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x1b)
#define NIRFSG_ATTR_POWER_BOTH_MODULATORS                   /* ViBoolean */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x1c)
#define NIRFSG_ATTR_HAS_REF_OUT2                            /* ViBoolean */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x1d)
#define NIRFSG_ATTR_DIGITAL_MODULATION_USER_DEFINED_WFM     /*    i8[]   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x1e)
#define NIRFSG_ATTR_5653_MASTER_REF_DAC                     /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x1f)
#define NIRFSG_ATTR_5653_YIG_DAC                            /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x20)
#define NIRFSG_ATTR_5653_LO1_ALC_DAC                        /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x21)
#define NIRFSG_ATTR_5653_LO1_OUTPUT_FILTER                  /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x22)
#define NIRFSG_ATTR_5653_LO2_VVA_DAC                        /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x23)
#define NIRFSG_ATTR_5653_LO3_VVA_DAC                        /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x24)
#define NIRFSG_ATTR_5653_100MHz_PLL_LOCKING_ENABLED         /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x25)
#define NIRFSG_ATTR_5653_LO2_PLL_LOCKING_ENABLED            /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x26)
#define NIRFSG_ATTR_CONFIGURATION_LIST_DMA_ENABLED          /* ViBoolean */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x27)
#define NIRFSG_ATTR_YIG_PLL_COARSE_FREQUENCY                /* ViReal64  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0X28)
#define NIRFSG_ATTR_YIG_PLL_FINE_FREQUENCY                  /* ViReal64  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0X29)
#define NIRFSG_ATTR_DEBUGGING_OPTIONS                       /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x2a)
#define NIRFSG_ATTR_SELF_CALIBRATION_VALID                  /* ViBoolean */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x2b)
#define NIRFSG_ATTR_5652_REFERENCE_FREQ_DAC                 /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x2d)
#define NIRFSG_ATTR_5652_ALC_DAC                            /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x2e)
#define NIRFSG_ATTR_5652_ATTENUATION                        /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x2f)
#define NIRFSG_ATTR_5652_BYPASS_MAIN_ATTENUATORS            /* ViBoolean */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x30)
#define NIRFSG_ATTR_EXTRA_LIST_MODE_ATTRIBUTES_ENABLED      /* ViBoolean */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x31)
#define NIRFSG_ATTR_RFSA_PROTOCOL                           /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x32)
#define NIRFSG_ATTR_RFSA_OLDEST_COMPATIBLE_PROTOCOL         /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x33)
#define NIRFSG_ATTR_REF_CLOCK_TOKEN0                        /* ViInt64   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x42)
#define NIRFSG_ATTR_REF_CLOCK_TOKEN1                        /* ViInt64   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x46)
#define NIRFSG_ATTR_REF_CLOCK_TOKEN2                        /* ViInt64   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x47)
#define NIRFSG_ATTR_ALC_ADC_READING                /*ViInt32, read-only  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x34)
#define NIRFSG_ATTR_5696_KNEE                               /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x35)
#define NIRFSG_ATTR_5696_OFFSET                             /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x36)
#define NIRFSG_ATTR_5696_DETECTOR_REF_DAC                   /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x37)
#define NIRFSG_ATTR_5696_ATTN_CELL_10_ON                    /* ViBoolean */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x38)
#define NIRFSG_ATTR_5696_ATTN_CELL_20_ON                    /* ViBoolean */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x39)
#define NIRFSG_ATTR_5696_ATTN_CELL_40A_ON                   /* ViBoolean */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x3A)
#define NIRFSG_ATTR_5696_ATTN_CELL_40B_ON                   /* ViBoolean */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x3B)
#define NIRFSG_ATTR_5654_OCXO_REF_DAC                       /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x3C)
#define NIRFSG_ATTR_5654_OCXO_REF_DAC_FLUSH_TO_HW           /* ViBoolean */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x48)
#define NIRFSG_ATTR_5654_COARSE_AMPLITUDE_DAC               /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x3D)
#define NIRFSG_ATTR_AE_GAIN                                 /* ViReal64  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x3E)
#define NIRFSG_ATTR_5654_POWER_SEARCH_ADC          /* ViInt32, read-only */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x49)
#define NIRFSG_ATTR_LO_CASCADE_ID                           /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x4A)
#define NIRFSG_ATTR_LO_OUT_CASCADE_ID                       /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x52)
#define NIRFSG_ATTR_RF_CASCADE_ID                           /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x4B)
#define NIRFSG_ATTR_IQ_CASCADE_ID                           /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x4C)
#define NIRFSG_ATTR_ONBOARD_REF_CLK_DAC                     /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x4D)
#define NIRFSG_ATTR_VCO_SELF_CAL_ENABLED                    /* ViBoolean */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x4E)
#define NIRFSG_ATTR_VCO_CAL_VOLTAGE                         /* ViReal64  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x4F)
#define NIRFSG_ATTR_VCO_PFD                                 /* ViReal64  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x50)
#define NIRFSG_ATTR_VCO_CHARGE_PUMP                         /* ViReal64  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x51)
#define NIRFSG_ATTR_LO_FILTER                               /* ViReal64  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x53)
#define NIRFSG_ATTR_RF_FILTER                               /* ViReal64  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x54)
#define NIRFSG_ATTR_5840_MODULATOR                          /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x55)
#define NIRFSG_ATTR_CAL_DSP_FREQ_SHIFT                      /* ViReal64  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x56)
#define NIRFSG_ATTR_CAL_DSP_STATIC_I                        /* ViReal64  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x57)
#define NIRFSG_ATTR_CAL_DSP_STATIC_Q                        /* ViReal64  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x58)
#define NIRFSG_ATTR_CAL_DSP_STATIC_IQ_ENABLED               /* ViReal64  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x59)
#define NIRFSG_ATTR_EQ_FILTER_ENABLED                       /* ViBoolean */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x5A)
#define NIRFSG_ATTR_VCO_CAL_RESULT                          /* Internal  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x5B)
#define NIRFSG_ATTR_LO_POWER_METER_ENABLED                  /* ViBoolean */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x5C)
#define NIRFSG_ATTR_LO_POWER_METER_RESULT                   /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x5D)
#define NIRFSG_ATTR_LO_GAIN_STATES                          /* Internal  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x5E)
#define NIRFSG_ATTR_LO_OUT_GAIN_STATES                      /* Internal  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x5F)
#define NIRFSG_ATTR_RF_GAIN_STATES                          /* Internal  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x60)
#define NIRFSG_ATTR_RF_CASCADE_STATE                        /* Internal  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x65)
#define NIRFSG_ATTR_VCO_CAL_FREQUENCY                       /* ViReal64  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x61)
#define NIRFSG_ATTR_WAVEFORM_ANALYSIS_MAP                   /* Internal  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x62)
#define NIRFSG_ATTR_LO_CAL_FREQUENCY                        /* ViReal64  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x63)
#define NIRFSG_ATTR_TCLK_ADJUSTMENT                         /* ViReal64  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x64)
#define NIRFSG_ATTR_USER_COMMON_MODE_DAC_OFFSET             /* ViReal64 */    (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x66)
#define NIRFSG_ATTR_PRIMARY_COMMON_MODE_DAC_OFFSET          /* ViReal64[] */  (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x67)
#define NIRFSG_ATTR_SECONDARY_COMMON_MODE_DAC_OFFSET        /* ViReal64[] */  (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x68)
#define NIRFSG_ATTR_RF_POWER_METER_RESULT                   /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x69)
#define NIRFSG_ATTR_VCO_CAL_CORE                   /* ViInt32, read-only */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x6A)
#define NIRFSG_ATTR_VCO_CAL_OUTPUT_POWER           /* ViInt32, read-only */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x6B)
#define NIRFSG_ATTR_HARDWARE_STATE_OVERRIDE_UIDS            /* ViReal64[] */  (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x6C)
#define NIRFSG_ATTR_HARDWARE_STATE_OVERRIDE_STATES          /* ViReal64[] */  (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x6D)
#define NIRFSG_ATTR_RF_POWER_METER_ENABLED                  /* ViInt32   */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x6E)
#define NIRFSG_ATTR_5653_REFERENCE_CLOCK_ONLY_COMMIT        /* ViBoolean */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x6F)
#define NIRFSG_ATTR_2795_SPARAMETER_DATA                    /* NIComplexNumber[] */  (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x70)
#define NIRFSG_ATTR_2795_SPARAMETER_FREQUENCIES             /* ViReal64[] */         (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x71)
#define NIRFSG_ATTR_DEEMBEDDING_SPARAMETERS                 /* NIComplexNumber[] */  (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x72)
#define NIRFSG_ATTR_DEEMBEDDING_TABLE_NUMBER_OF_PORTS       /* ViInt32 */     (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x73)
#define NIRFSG_ATTR_LO_FREQUENCY_AT_MIXER                   /* ViReal64 */    (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x74)
#define NIRFSG_ATTR_VCO_ID                                  /* ViInt32 */     (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x75)
#define NIRFSG_ATTR_COMPOSITE_IDLE_TRACKER_ID               /* ViInt32*/      (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x76)
#define NIRFSG_ATTR_RF_ACCESSORY_POWER_OFFSET               /* ViReal64*/     (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x77)
#define NIRFSG_ATTR_RF_ACCESSORY_PATH_GAIN                  /* ViReal64*/     (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x78)
#define NIRFSG_ATTR_RF_ACCESSORY_DIGITAL_GAIN               /* ViReal64*/     (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x79)
#define NIRFSG_ATTR_SYSTEM_CONFIGURATION        /* ViString, read-only  */    (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x7a)

#define NIRFSG_ATTR_ASSOC_AUX_SWITCH_GAIN_UID   /* ViInt32, read-only */      (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x88)

// This attribute is only used by VST now and should not be used for newer devices.
#define NIRFSG_ATTR_SELF_CALIBRATION_DATE_TIME              /* Timestamp */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x2C)

/*
   NIRFSG_ATTR_SELF_CALIBRATION_MODULE is not used as an Attribute, only declared as such so that enums
   used for the self calibration "module" parameter (i32) can return enum values as strings via tEnglishAttributeStringTable.
*/
#define NIRFSG_ATTR_SELF_CALIBRATION_MODULE                 /* ViInt32 */     (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x40)
#define NIRFSG_ATTR_5696_AMP_BAND                           /* ViInt32 */     (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x41)
#define NIRFSG_ATTR_5696_LOWHARMONIC_LEVEL_DAC              /* ViInt32 */     (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x43)
#define NIRFSG_ATTR_5696_TEMP_COMP_DAC                      /* ViInt32 */     (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x44)

// Per-Waveform Internal Attributes
#define NIRFSG_ATTR_IQ_RATE_INTERNAL                        /* ViReal64 */    (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x7b)
#define NIRFSG_ATTR_SIGNAL_BANDWIDTH_INTERNAL               /* ViReal64 */    (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x7c)
#define NIRFSG_ATTR_RUNTIME_SCALING_INTERNAL                /* ViReal64 */    (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x7d)
#define NIRFSG_ATTR_PAPR_INTERNAL                           /* ViReal64 */    (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x7e)
#define NIRFSG_ATTR_WAVEFORM_INDEX_FROM_FILE_INTERNAL       /* ViUInt32 */    (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x80)

#define NIRFSG_ATTR_SENSOR_TEMPERATURE                      /* ViReal64 */    (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x81)

#define NIRFSG_ATTR_ASSOC_LO_GAIN_STATES                    /* Internal  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x82)
#define NIRFSG_ATTR_ASSOC_LO_FILTER                         /* ViUInt32  */   (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x83)

// NIRFSG_ATTR_OOP_SESSION_MANAGER_PTR attribute stores OutOfProcessSessionManager pointer. This attribute is used in Remote component.
#define NIRFSG_ATTR_OOP_SESSION_MANAGER_PTR                 /* ViAddr */      (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x7f)
#define NIRFSG_ATTR_OOP_SESSION_PIPE_ID                     /* ViInt64 */     (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x86) 

// This attribute stores the channel number specified at initialize (first used in MCVST)
#define NIRFSG_ATTR_CREATED_SESSION_CHANNEL                 /* ViInt32 */     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x139)

// Leaving these attributes in the public attribute space but in the private header file
#define NIRFSG_ATTR_CONFIGURATION_TRIGGER_DELAY                /* ViReal64  */               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x65)
#define NIRFSG_ATTR_LO2_OUT_ENABLED                            /* ViBoolean */               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x77)
#define NIRFSG_ATTR_LO3_OUT_ENABLED                            /* ViBoolean */               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x78)
#define NIRFSG_ATTR_MIN_PLL_LOCK_TIME                          /* ViReal64  */               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x82)
#define NIRFSG_ATTR_PLL_CHECK_ENABLED                          /* ViBoolean */               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x83)
#define NIRFSG_ATTR_INCLUDE_SETTLING_FOR_FREQUENCY_DIVIDER_AND_MULTIPLIER_CHANGE /* ViBoolean */      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x8B)
#define NIRFSG_ATTR_TIMER_START_SOURCE                         /* ViString */                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xC1) /* VST only right now */
#define NIRFSG_ATTR_ATTENUATION                                /* ViReal64, read-only */     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xAE)
#define NIRFSG_ATTR_AMP_GAIN                                   /* ViReal64, read-only */     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xAC)
#define NIRFSG_ATTR_LOW_PHASE_NOISE_OPTION                     /* ViBoolean, read-only */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xBD)
#define NIRFSG_ATTR_POWER_CALIBRATION_TEMPERATURE              /* ViReal64, read-write */    (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x3F)
#define NIRFSG_ATTR_EQUALIZER_COEFFICIENTS                     /* ViReal64[], read-write */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xC8)
#define NIRFSG_ATTR_EQUALIZER_COEFFICIENTS_GROUP_DELAY         /* ViReal64, read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xC9)
#define NIRFSG_ATTR_EQUALIZER_COEFFICIENTS_GAIN                /* ViReal64, read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xDD)
#define NIRFSG_ATTR_EQUALIZER_COEFFICIENTS_PHASE_OFFSET        /* ViReal64, read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xDE)
#define NIRFSG_ATTR_EQUALIZER_COEFFICIENTS_BANDWIDTH           /* ViReal64, read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xDF)
#define NIRFSG_ATTR_DC_OFFSET_CORRECTION_I_OFFSET              /* ViReal64, read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xCA)
#define NIRFSG_ATTR_DC_OFFSET_CORRECTION_Q_OFFSET              /* ViReal64, read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xCB)
#define NIRFSG_ATTR_LO_OUT_SOURCE                              /* ViString, read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xCD)
#define NIRFSG_ATTR_MIN_FREQUENCY                              /* ViReal64, read-only */     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xD5)
#define NIRFSG_ATTR_MAX_FREQUENCY                              /* ViReal64, read-only */     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xD6)
#define NIRFSG_ATTR_MIN_UPCONVERTER_CENTER_FREQUENCY           /* ViReal64, read-only */     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xD7)
#define NIRFSG_ATTR_MAX_UPCONVERTER_CENTER_FREQUENCY           /* ViReal64, read-only */     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xD8)
#define NIRFSG_ATTR_RF_POWER_PROTECTION_ENABLED                /* ViInt32,  read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xE0)
#define NIRFSG_ATTR_MAX_DEVICE_INSTANTANEOUS_BANDWIDTH         /* ViReal64  */               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xe7)
#define NIRFSG_ATTR_MAX_IQ_RATE                                /* ViReal64, read-only */     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x9F)
#define NIRFSG_ATTR_MIN_IQ_RATE                                /* ViReal64, read-only */     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xE3)
#define NIRFSG_ATTR_DMM_ACQUISITION_LENGTH                     /* ViInt32,  read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xE8)
#define NIRFSG_ATTR_DMM_READ                                   /* ViReal64, read-only */     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xE9)
#define NIRFSG_ATTR_DMM_READ_Q                                 /* ViReal64, read-only */     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xEA)
#define NIRFSG_ATTR_DMM_CORRECTION_FREQUENCY                   /* ViReal64, read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xEB)
#define NIRFSG_ATTR_FINE_TUNE_ADJUSTMENT                       /* ViReal64, read-only */     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xED)
#define NIRFSG_ATTR_CONFIGURATION_LIST_STATUS_CHECKS_DISABLED  /* ViInt64,  read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xEE)
#define NIRFSG_ATTR_P2P_ENDPOINT_HANDLE                        /* ViUInt32  read-only */     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xF5)
#define NIRFSG_ATTR_FREQUENCY_RESPONSE_FILTER_ENABLED          /* ViInt32,  read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xF6)
#define NIRFSG_ATTR_IMPAIRMENTS_FILTER_ENABLED                 /* ViInt32,  read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xF7)
#define NIRFSG_ATTR_GAIN_STATE_FROM_SELF_CAL                   /* ViInt32,  read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xFE)
#define NIRFSG_ATTR_TRIGGER_MIN_IMPORT_PULSE_WIDTH             /* ViReal64, read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xFF)
#define NIRFSG_ATTR_INTERNAL_CALIBRATION_ELEMENT_TERMINATION   /* ViString, read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x100)
#define NIRFSG_ATTR_WAVEFORM_SOURCE                            /* ViInt32,  read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x104)
#define NIRFSG_ATTR_ASSOC_AUX_SWITCH_GAIN                      /* ViReal64, read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x106)
#define NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION             /* ViInt32, read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x111)
#define NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION_MODE        /* ViInt32, read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x112)
#define NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION_MINIMUM_QUIET_TIME     /* ViReal64, read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x113)
#define NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION_POWER_THRESHOLD        /* ViReal64, read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x114)
#define NIRFSG_ATTR_WRITE_WAVEFORM_BURST_DETECTION_MINIMUM_BURST_TIME     /* ViReal64, read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x115)

#define NIRFSG_ATTR_FREQUENCY_RESPONSE_EQUALIZER_COEFFICIENTS              /* ViReal64[] */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x117)
#define NIRFSG_ATTR_FREQUENCY_RESPONSE_EQUALIZER_COEFFICIENTS_GAIN         /* ViReal64 */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x118)
#define NIRFSG_ATTR_FREQUENCY_RESPONSE_EQUALIZER_COEFFICIENTS_BANDWIDTH    /* ViReal64 */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x119)
#define NIRFSG_ATTR_FREQUENCY_RESPONSE_EQUALIZER_COEFFICIENTS_PHASE_OFFSET /* ViReal64 */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x11A)
#define NIRFSG_ATTR_FREQUENCY_RESPONSE_EQUALIZER_COEFFICIENTS_GROUP_DELAY  /* ViReal64 */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x11B)
#define NIRFSG_ATTR_IMPAIRMENTS_EQUALIZER_COEFFICIENTS                     /* ViReal64[] */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x11C)
#define NIRFSG_ATTR_IMPAIRMENTS_EQUALIZER_COEFFICIENTS_GAIN                /* ViReal64 */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x11D)
#define NIRFSG_ATTR_IMPAIRMENTS_EQUALIZER_COEFFICIENTS_BANDWIDTH           /* ViReal64 */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x11E)
#define NIRFSG_ATTR_IMPAIRMENTS_EQUALIZER_COEFFICIENTS_PHASE_OFFSET        /* ViReal64 */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x11F)
#define NIRFSG_ATTR_IMPAIRMENTS_EQUALIZER_COEFFICIENTS_GROUP_DELAY         /* ViReal64 */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x120)

#define NIRFSG_ATTR_LOAD_CONFIGURATIONS_FROM_FILE_LOAD_OPTIONS             /*ViInt32*/          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x122)
#define NIRFSG_ATTR_LOAD_CONFIGURATIONS_FROM_FILE_RESET_OPTIONS            /*ViInt32*/          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x123)

#define NIRFSG_ATTR_ASSOC_AUX_POWER_CUTOFF_LEVEL               /* ViReal64, read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x128)

#define NIRFSG_ATTR_DAC_DECODER_MODE                          /* ViInt32,  read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x130)

#define NIRFSG_ATTR_OPTIMIZE_PATH_FOR_SIGNAL_BANDWIDTH        /* ViInt64,  read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x132)

/* System Correction attributes ---------------------------------------------------*/
#define NIRFSG_ATTR_CHANNEL_GAIN_IMBALANCE                     /* ViReal64 */                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xEC)

#define NIRFSG_ATTR_HOST_DMA_BUFFER_MIRROR_SIZE                /* ViInt64  */                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xF0)

#define NIRFSG_ATTR_AVAILABLE_INTERNAL_PORTS                   /* ViString */                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x103)
#define NIRFSG_ATTR_INTERNAL_PORT_MAP                          /* ViString */                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x105)
#define NIRFSG_ATTR_STS_5532_SIGNAL_PATH                       /* ViInt32  */                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0xFA)

#define NIRFSG_ATTR_WAVEFORM_BURST_START_LOCATIONS             /* ViReal64[] */              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x10B)
#define NIRFSG_ATTR_WAVEFORM_BURST_STOP_LOCATIONS              /* ViReal64[] */              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x10C)
#define NIRFSG_ATTR_WAVEFORM_MARKER_EVENT_LOCATIONS            /* ViReal64[] */              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x10D)

#define NIRFSG_ATTR_MISMATCH_CORRECTION_ENABLED                /* ViInt32 */                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x126)

#define NIRFSG_ATTR_FREQUENCY_SHIFT                            /* ViReal64  */               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x127)

#define NIRFSG_ATTR_ACCESSORY_INTERNAL_CONNECTION              /* ViString, read-write */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x131)

#define NIRFSG_ATTR_CONVERTER_DELAY_BASELINE                   /* ViReal64 */                (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x84)

#define NIRFSG_ATTR_MTS_DELAY_BASELINE                         /* ViInt32 */                 (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x85)

#define NIRFSG_ATTR_COERCE_POWER_LEVEL_TO_MAX_POWER            /* ViInt32 */                 (RFSG_SPECIFIC_PRIVATE_ATTR_BASE + 0x87)

/*****************************************************************************
 *-----------------------  Hidden Constants  ---------------*
 *****************************************************************************/

// Unique values allows better error checking (detect using wrong value for this attribute).
// In general, split up the ranges like this to make it easier to ensure unique values:
//    0    to ~50k:  Public values
//   ~50k  to  99k:  Private values
//    101k to 200k:  Values synchronized with RFSA (ie, Willy LO filter is same on generator and analyzer)

/*------------------- Private Values (99k downto ~50k) -----------------------*/

// Values for attribute NIRFSG_ATTR_ARB_FILTER_TYPE
#define NIRFSG_VAL_ARB_FILTER_TYPE_GAUSSIAN                 99001
#define NIRFSG_VAL_ARB_FILTER_TYPE_CUSTOM                   99002

// Values for attribute NIRFSG_ATTR_ARB_AMPLITUDE_CORRECTION_METHOD
#define NIRFSG_VAL_ANALOG_GAIN                  98000
#define NIRFSG_VAL_DIGITAL_GAIN                 98001

// Values for NIRFSG_ATTR_5696_AMP_BAND
#define NIRFSG_VAL_5696_AMPBAND_HIGHPOWER_250K_TO_250M            96000
#define NIRFSG_VAL_5696_AMPBAND_LOWHARMONICS_250M_TO_1G           96001
#define NIRFSG_VAL_5696_AMPBAND_1G_TO_2_4G                        96002
#define NIRFSG_VAL_5696_AMPBAND_2_4G_TO_3_86G                     96003
#define NIRFSG_VAL_5696_AMPBAND_3_86G_TO_5_37G                    96004
#define NIRFSG_VAL_5696_AMPBAND_5_37G_TO_7_45G                    96005
#define NIRFSG_VAL_5696_AMPBAND_7_45G_TO_10_4G                    96006
#define NIRFSG_VAL_5696_AMPBAND_10_4G_TO_14_4G                    96007
#define NIRFSG_VAL_5696_AMPBAND_14_4G_TO_20_0G                    96008
#define NIRFSG_VAL_5696_AMPBAND_LOWGROUPDELAY_14_4G_TO_17G        96009
#define NIRFSG_VAL_5696_AMPBAND_LOWGROUPDELAY_17G_TO_20G          96010

// For 565x, this is an alias for "RefIn" or "RefOut" (depending on context).  Use of "RefIn" or "RefOut" is preferred.
#define NIRFSG_VAL_REF_INOUT_STR                "RefIn/Out"

// Values for repository selection on the GetFPGAExtensionsBitfileDir function
#define NIRFSG_VAL_FPGA_BITFILE_REPOSITORY_USER 0

// Additional Values for attribute NIRFSG_ATTR_AMP_PATH
#define NIRFSG_VAL_OFF                          16002 // Uses the public range since it is a public attribute. Make sure it is unique across other values for this enum in niRFSG.h
#define NIRFSG_VAL_LOW_GROUP_DELAY              16003

// Values for niRFSG_ResetWithOption
// These are now obsolete and the public versions should be now used.
#define NIRFSG_VAL_RESET_WITH_OPTION_RESET                       NIRFSG_VAL_RESET_WITH_OPTIONS_NONE
#define NIRFSG_VAL_RESET_WITH_OPTION_PRESERVE_WAVEFORM           NIRFSG_VAL_RESET_WITH_OPTIONS_WAVEFORMS
#define NIRFSG_VAL_RESET_WITH_OPTION_PRESERVE_SCRIPT             NIRFSG_VAL_RESET_WITH_OPTIONS_SCRIPTS
#define NIRFSG_VAL_RESET_WITH_OPTION_PRESERVE_ROUTES             NIRFSG_VAL_RESET_WITH_OPTIONS_ROUTES
#define NIRFSG_VAL_RESET_WITH_OPTION_PRESERVE_DEEMBEDDING_TABLES NIRFSG_VAL_RESET_WITH_OPTIONS_DEEMBEDDING_TABLES

// Values for NIRFSG_ATTR_5840_MODULATOR
#define NIRFSG_VAL_5840_MODULATOR_BYPASS     95000
#define NIRFSG_VAL_5840_MODULATOR_ENABLED    95001   // Module uses a single modulator for now.  Layout allows for 1 to be added.

// For NIRFSG_ATTR_LO_OUT_SOURCE attribute
// Internal_LO means match the LO_SOURCE attribute
#define NIRFSG_VAL_LO_OUT_SOURCE_INTERNAL_LO_STR            "Internal_LO"
// Onboard means export the lo synth signal regardless of the LO_SOURCE attribute
#define NIRFSG_VAL_LO_OUT_SOURCE_ONBOARD_STR                NIRFSG_VAL_LO_SOURCE_ONBOARD_STR

// Values used internally to match RFSA amp modes
// note these continue the NIRFSG_ATTR_AMP_PATH values that are public, using the 16xxx range.
#define NIRFSG_VAL_RF_AMP_DISABLED                             16002
#define NIRFSG_VAL_RF_AMP_ENABLED_WHEN_IN_SIGNAL_PATH          16003
#define NIRFSG_VAL_RF_AMP_ENABLED                              16004
#define NIRFSG_VAL_RF_AMP_AUTOMATIC                            16005

// Values for NIRFSG_ATTR_OUTPUT_PORT
// note there are other enum values that are not private in niRFSG.h
#define NIRFSG_VAL_IQ_IN                      14100 // Output to IQ In Port
#define NIRFSG_VAL_IMPORT_SIGNAL              14101 // Measure via IQ Out Port
#define NIRFSG_VAL_IF_POWER_METER             14102 // Route to internal power meter

// Values for NIRFSG_ATTR_CONFIGURATION_LIST_STATUS_CHECKS_DISABLED
#define NIRFSG_VAL_STATUS_CHECK_NONE                0x0000000000000000
#define NIRFSG_VAL_STATUS_CHECK_POWER_PROTECTION    0x0000000000000001
#define NIRFSG_VAL_STATUS_CHECK_DSP                 0x0000000000000002
#define NIRFSG_VAL_STATUS_CHECK_LO_PLL              0x0000000000000004
#define NIRFSG_VAL_STATUS_CHECK_ALL                 0xFFFFFFFFFFFFFFFF

// Values for NIRFSG_ATTR_UPCONVERTER_FREQUENCY_OFFSET_MODE
#define NIRFSG_VAL_IF_MODE_COMPATIBILITY                       26000

// Values for NIRFSG_ATTR_WAVEFORM_SOURCE
// note using values that are public; expect attribute to be public in future release.
#define NIRFSG_VAL_WAVEFORM_SOURCE_NONE                        NIRFSG_VAL_NONE
#define NIRFSG_VAL_WAVEFORM_SOURCE_WGEN                        27000
#define NIRFSG_VAL_WAVEFORM_SOURCE_P2P                         27001
#define NIRFSG_VAL_WAVEFORM_SOURCE_USER                        27002

// Enum values for getting attribute authorship
#define NIRFSG_VAL_ATTR_AUTHOR_DEFAULT          0
#define NIRFSG_VAL_ATTR_AUTHOR_USER             1
#define NIRFSG_VAL_ATTR_AUTHOR_DRIVER           2

// Private marker used for RF Blanking
#define NIRFSG_VAL_RF_BLANKING_MARKER                       "marker7"

// "PulseIn" is an alias for the following two signal names.  We want customers to use
// the public alias, which allows the driver to choose the appropriate signal for the
// configured use case.
#define NIRFSG_VAL_PULSE_IN_HIGH_RESOLUTION_STR             "PulseInHighResolution"
#define NIRFSG_VAL_PULSE_IN_LOW_LATENCY_STR                 "PulseInLowLatency"

//Enum values for DAC decoder modes

#define NIRFSG_VAL_DAC_DECODER_MAX_SNR          28001
#define NIRFSG_VAL_DAC_DECODER_MAX_LINEARITY    28002

/*****************************************************************************
 *-------------------  Global Variables (driver internal use) ---------------*
 *****************************************************************************/

/*****************************************************************************
 *------------------  Hidden Functions (but exported from dll)  -------------*
 *****************************************************************************/
ViStatus _VI_FUNC niRFSG_SetDigitalIFEqualizationCoefficients
(
   ViSession   vi,
   ViInt32     numberOfCoefficients,
   ViReal32*   coefficients
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_GetDigitalIFEqualizationCoefficients
(
   ViSession   vi,
   ViInt32*    numberOfCoefficients,
   ViReal32*   coefficients
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_IsCalibrationSession
(
   ViSession   vi,
   ViBoolean*  isCalibrationSessionPtr
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_readCalibrationBytestream
(
   ViSession   vi,
   ViUInt8*    bytestream,
   ViUInt32*   numberOfBytes
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_writeCalibrationBytestream
(
   ViSession      vi,
   const ViUInt8* bytestream,
   ViUInt32       numberOfBytes
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_SetExternalCalibrationLastDateAndTime
(
   ViSession      vi,
   ViInt32        year,
   ViInt32        month,
   ViInt32        day,
   ViInt32        hour,
   ViInt32        minute,
   ViInt32        second
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_UpdateExternalCalibrationDateAndTime
(
   ViSession vi
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_UpdateExternalCalibrationTemperature
(
   ViSession vi
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_InitExternalCalibration
(
   ViRsrc        resourceName,
   ViConstString password,
   ViConstString optionString,
   ViSession*    newVi
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_CloseExternalCalibration
(
   ViSession vi,
   ViBoolean writeCalibrationInformationToHardware
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_GetErrorMessage
(
   ViSession   vi,
   ViStatus    errorCode,
   ViInt32     errorDescriptionBufferSize,
   ViChar      errorDescription[]
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_SetRalInstructions
(
   ViSession   vi,
   ViInt32     instructionsBufferSize,
   ViInt32*    instructionsBuffer
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_GetRalInstructions
(
   ViSession   vi,
   ViInt32     instructionsBufferSize,
   ViInt32*    instructionsBuffer,
   ViInt32*    actualInstructionsBufferSize
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_5653_GetYigPllCoarseAndFineFrequencyOptions
(
   ViSession vi,
   ViReal64 desiredLO1Frequency,
   ViBoolean allowUntestedCoarseFrequencies,
   ViInt32 optionsArrayCapacity,
   ViReal64 coarseFrequencies[],
   ViReal64 fineFrequencies[],
   ViUInt32 spurBitfield[],
   ViInt32* optionsArraySize
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_GetRefClockPLLStickyBit
(
   ViSession vi,
   ViBoolean* refClockPLLStickyBitPtr
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_GetRefClockToken
(
   ViSession vi,
   ViUInt32 tokenNumber,
   ViInt64* refClockTokenPtr
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_5654_WriteCalTable
(
   ViSession       vi,
   ViInt32         table,                 /* CalTableEnum defined in ni5654 */
   ViInt32         powersSize,
   const ViInt16   powers_centi_dBm[],
   ViInt32         frequenciesSize,
   const ViUInt64  frequencies_mHz[],
   const ViUInt16  values[]          /* size = powersSize * frequenciesSize */
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_5654_ReadCalTable
(
   ViSession       vi,
   ViInt32         table,                 /* CalTableEnum defined in ni5654 */
   ViInt32         powersSize,
   const ViInt16   powers_centi_dBm[],
   ViInt32         frequenciesSize,
   const ViUInt64  frequencies_mHz[],
   ViUInt16        values[]          /* size = powersSize * frequenciesSize */
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_5654_OCXOCal
(
   ViSession       vi
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_GetDesiredAttributeViInt32
(
   ViSession       vi,
   ViConstString   channelName,
   ViAttr          attribute,
   ViInt32*        value
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_GetDesiredAttributeViInt64
(
   ViSession       vi,
   ViConstString   channelName,
   ViAttr          attribute,
   ViInt64*        value
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_GetDesiredAttributeViReal64
(
   ViSession       vi,
   ViConstString   channelName,
   ViAttr          attribute,
   ViReal64*       value
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
// ViStatus is returning the length of the string when positive
ViStatus _VI_FUNC niRFSG_GetDesiredAttributeViString
(
   ViSession       vi,
   ViConstString   channelName,
   ViAttr          attribute,
   ViInt32         bufSize,
   ViChar          value[]
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_GetDesiredAttributeViBoolean
(
   ViSession       vi,
   ViConstString   channelName,
   ViAttr          attribute,
   ViBoolean*      value
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
// ViStatus is returning the size of the array when positive
ViStatus _VI_FUNC niRFSG_GetDesiredAttributeViReal64Array
(
   ViSession       vi,
   ViConstString   channelName,
   ViAttr          attributeId,
   ViInt32         valueLengthInElements,
   ViReal64        value[]
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
// ViStatus is returning the size of the array when positive
ViStatus _VI_FUNC niRFSG_GetDesiredAttributeNIComplexNumberArray
(
   ViSession       vi,
   ViConstString   channelName,
   ViAttr          attributeId,
   ViInt32         valueLengthInElements,
   NIComplexNumber value[]
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

// This is the original private ResetWithOption, but is now obsolete.  The public version
// is ResetWithOptions to match the already RFSA public version.  This entrypoint is kept
// to keep backwards compatibility.
ViStatus _VI_FUNC niRFSG_ResetWithOption
(
   ViSession vi,
   ViUInt64 resetOption
);


/*****************************************************************************
 *-----------------------  Included for IVI-compiance only ------------------*
 *  None of these will be useful to customers using the niRFSG API directly. *
 *  These are for IVI class driver customers only, and were removed from the *
 *  public header file to eliminate clutter (show only what niRFSG supports. *
 *****************************************************************************/
#define NIRFSG_ATTR_IQ_SOURCE                               /* ViInt32   */   IVIRFSIGGEN_ATTR_IQ_SOURCE
#define NIRFSG_VAL_IQ_SOURCE_ARB_GENERATOR                                    IVIRFSIGGEN_VAL_IQ_SOURCE_ARB_GENERATOR

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ConfigureArb
(
   ViSession   vi,
   ViReal64    clockFrequency,
   ViReal64    filterFrequency
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_SendSoftwareTrigger
(
   ViSession vi
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_IsSettled
(
   ViSession   vi,
   ViBoolean*  isSettledPtr
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_ConfigureALCEnabled
(
   ViSession vi,
   ViBoolean ALCEnabled
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_CalibrateIQ
(
   ViSession   vi
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_GetCfgTime
(
   ViSession   vi,
   ViInt64     step,
   ViBoolean   includeSettling,
   ViReal64*   configurationTime
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_PerformThermalCorrectionIfNeeded
(
   ViSession vi,
   ViBoolean* thermalCorrectionPerformedPtr
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_GetFPGAExtensionsBitfileDir
(
   ViRsrc resourceName,
   ViConstString deviceContext,
   ViUInt32 repositorySelect,
   ViUInt32 bitfileDirBufferSize,
   ViChar* bitfileDir,
   ViUInt32* requiredBitfileDirBufferSize
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_SetAttributeViReal64Array
(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32 valueLengthInElements,
   const ViReal64 value[]
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
// ViStatus is returning the size of the array when positive
ViStatus _VI_FUNC niRFSG_GetAttributeViReal64Array
(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32 valueLengthInElements,
   ViReal64 value[]
);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_SetAttributeNIComplexNumberArray(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32 valueLengthInElements,
   NIComplexNumber value[]);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
// ViStatus is returning the size of the array when positive
ViStatus _VI_FUNC niRFSG_GetAttributeNIComplexNumberArray(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32 valueLengthInElements,
   NIComplexNumber value[]);

ViStatus _VI_FUNC niRFSG_GetSensorTemperature(
   ViSession vi,
   ViConstString sensorString,
   ViReal64* temperature);

ViStatus _VI_FUNC niRFSG_MfgOverride(
   ViSession vi,
   ViConstString value);

// The difference between the Unix timestamp epoch (1970) and the Mac timestamp epoch (1904) is 2082844800 seconds.
const ViUInt64 kRfsgTimeDiff_Epoch_1904_1970 = 2082844800ull;

// This was excluded from the public API, but is currently used by RFPM.
// See https://nitalk.jiveon.com/docs/DOC-462757#comment-334603
// begin private GetSelfCalibrateRangeState

/*- Time Structures and Helpers ----------------------------------*/

// Please visit ni.com/info and enter the Info Code NI_BTF for more information
#ifndef CVITime_DECLARED
#define CVITime_DECLARED
     typedef struct CVITime { ViUInt64 lsb; ViInt64 msb; } CVITime;
#endif
#ifndef CVIAbsoluteTime_DECLARED
#define CVIAbsoluteTime_DECLARED
     typedef union CVIAbsoluteTime { CVITime cviTime; ViUInt32 u32Data[4]; } CVIAbsoluteTime;
#endif

/*
 * Converts a timestamp to seconds and fractional seconds.
 */
ViStatus _VI_FUNC niRFSG_ValuesFromTimestamp(
   CVIAbsoluteTime timestamp,
   ViInt64* secondsSince1970,
   ViReal64* fractionalSeconds);
/*
 * Converts seconds and fractional seconds to a timestamp.
 */
ViStatus _VI_FUNC niRFSG_TimestampFromValues(
   ViInt64 secondsSince1970,
   ViReal64 fractionalSeconds,
   CVIAbsoluteTime* timestamp);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
ViStatus _VI_FUNC niRFSG_GetSelfCalibrateRangeState
(
   ViSession vi,
   ViInt32 bufferSize,
   ViInt64 step[],
   CVIAbsoluteTime timestamp[],
   ViReal64 temperature[],
   ViReal64 minFrequency[],
   ViReal64 maxFrequency[],
   ViReal64 minReferenceLevel[],
   ViReal64 maxReferenceLevel[],
   ViInt32* actualDataSize
);

// end private GetSelfCalibrateRangeState

// Returns the number of ports in the currently selected de-embedding table.
// Used to resize the 2D array in LabVIEW for calls to niRFSA_GetDeembeddingSparameters
ViStatus _VI_FUNC niRFSG_GetDeembeddingTableNumberOfPorts(
   ViSession vi,
   ViInt32 *numberOfPorts);

// Calls to support creation of de-embedding S-parameter tables in RFmx SCPI API

ViStatus _VI_FUNC niRFSG_CreateDeembeddingSparameterTable(
   ViSession vi,
   ViConstString port,
   ViConstString tableName,
   ViInt32 numberOfFrequencies,
   ViInt32 numberOfPorts);

ViStatus _VI_FUNC niRFSG_ConfigureSparameterTableFrequencies(
   ViSession vi,
   ViConstString port,
   ViConstString tableName,
   const ViReal64 frequencies[], ViInt32 frequenciesSize);

ViStatus _VI_FUNC niRFSG_ConfigureSparameterTableSparameters(
   ViSession vi,
   ViConstString port,
   ViConstString tableName,
   const NIComplexNumber sparameterTable[], ViInt32 sparameterTableSize,
   ViInt32 sparameterOrientation);

ViStatus _VI_FUNC niRFSG_GetViSessionByName(
   ViRsrc resourceName,
   ViSession* existingVi);

ViStatus _VI_FUNC niRFSG_GetAssociatedDevicesForName
(
   ViConstString deviceName,
   ViUInt32 stringBufferSize,
   ViChar* associatedArb,
   ViChar* associatedLO,
   ViChar* associatedDevX,
   ViChar* associatedDevY,
   ViChar* associatedDevZ
);

ViStatus _VI_FUNC niRFSG_GetErrorUP
(
   ViSession   vi,
   ViStatus*   errorCodePtr,
   ViInt32     errorDescriptionBufferSize,
   ViChar      errorDescription[]
);

ViStatus _VI_FUNC niRFSG_GetTickCount
(
   ViSession vi,
   ViUInt64 *tickCountPtr,
   ViReal64 *secondsPerTickPtr
);

ViStatus _VI_FUNC niRFSG_GetAssociatedDevicesForGUID
(
   ViUInt32 configHandle,
   ViConstString deviceGUIDString,
   ViUInt32 stringBufferSize,
   ViChar* associatedArb,
   ViChar* associatedLO,
   ViChar* associatedDevX,
   ViChar* associatedDevY,
   ViChar* associatedDevZ
);

ViStatus _VI_FUNC niRFSG_SetAssociatedDevicesForGUID
(
   ViUInt32 configHandle,
   ViConstString deviceGUIDString,
   const ViChar* associatedArb,
   const ViChar* associatedLO,
   const ViChar* associatedDevX,
   const ViChar* associatedDevY,
   const ViChar* associatedDevZ
);

ViStatus _VI_FUNC niRFSG_GetWaveformNames
(
   ViSession vi,
   ViChar waveformNames[],
   ViInt32 bufferSize,
   ViInt32* actualBufferSize,
   ViInt32* numberOfWaveforms
);

// Remote entrypoints.
ViStatus _VI_FUNC InitializeSessionForServer
(
   ViRsrc resourceName,
   ViBoolean idQuery,
   ViBoolean resetDevice,
   ViConstString options,
   ViConstString additionalOpts,
   ViSession* newVi
);

ViStatus _VI_FUNC ReleaseSessionForServer
(
   ViSession vi
);

ViStatus _VI_FUNC niRFSG_StartDebugServer
(
   ViSession vi,
   ViRsrc resourceName
);

ViStatus _VI_FUNC niRFSG_RequestPrivilege
(
   ViSession vi,
   ViInt32 privilegeLevel
);

ViStatus _VI_FUNC niRFSG_GetOpenSessionsInformation
(
   ViRsrc resourceName,
   ViString infoJSON,
   ViUInt64 bufferSize,
   ViUInt64* bufferSizeNeededInBytes
);

ViStatus _VI_FUNC niRFSG_GetAttributeAuthor
(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32* value
);

ViStatus _VI_FUNC niRFSG_GetAttributeContexts
(
   ViSession vi,
   ViAttr attributeId,
   ViInt32 bufSize,
   ViString contexts,
   ViInt32* requiredBufSize
);

ViStatus _VI_FUNC niRFSG_GetPrivilegeLevel
(
   ViSession vi,
   ViInt32* privilegeLevel
);

ViStatus _VI_FUNC niRFSG_GetSparameterTableS2pFilePathAndOrientation
(
    ViSession vi,
    ViConstString port,
    ViConstString tableName,
    ViInt32 filePathBufferSize,
    ViChar* s2pFilePath,
    ViInt32* requiredFilePathBufferSize,
    ViInt32* s2pOrientation
);

ViStatus _VI_FUNC niRFSG_GetDeembeddingTableNames
(
   ViSession vi,
   ViConstString port,
   ViChar tableNames[],
   ViInt32 bufferSize,
   ViInt32* actualBufferSize
);

ViStatus _VI_FUNC niRFSG_ExportConfigurationBuffer
(
   ViSession vi,
   ViConstString channelName,
   ViInt32 size,
   ViChar* configuration,
   ViInt32* requiredSize
);

ViStatus _VI_FUNC niRFSG_ImportConfigurationBuffer
(
   ViSession vi,
   ViConstString channelName,
   ViInt32 size,
   ViChar* configuration
);

/*****************************************************************************
 *---------------------------- Internal Error Codes -------------------------*
 *****************************************************************************/
 // This document describes the IVI error ranges:
 //   P:\Measurements\Infrastructure\InstrDriverComponents\secm\export\100\100f1\documentation\ErrorsForNIInstrumentDrivers.doc

 // Sqeeze these between niFGEN and niRFSG public Errors/Warnings.           //IVI_SPECIFIC_ERROR_BASE + 0x200 == 0xbffa4200
#define NIRFSG_INTERNAL_ERROR_BASE                                            (IVI_SPECIFIC_ERROR_BASE + 0x200)
#define NIRFSG_INTERNAL_WARN_BASE                                             (IVI_SPECIFIC_WARN_BASE + 0x200)

#include "niRFSGPrivateErrors.h"

#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif
#endif //___niRFSG_niRFSGPrivate_h___
