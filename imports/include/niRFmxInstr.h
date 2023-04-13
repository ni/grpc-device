/******************************************************************************
 *          National Instruments RFmx Instr
 *-----------------------------------------------------------------------------
 *   Copyright (c) National Instruments 2014-2016.  All Rights Reserved.
 *-----------------------------------------------------------------------------
 *
 * Title:    niRFmxInstr.h
 * Purpose:  National Instruments RFmx Instr
 *           Attribute IDs,
 *           Attribute Values,
 *           Functions declarations.
 *
 *****************************************************************************/

#ifndef __NI_RFMX_INSTR_H__
#define __NI_RFMX_INSTR_H__


#ifndef _NI_int8_DEFINED_
#define _NI_int8_DEFINED_
typedef char               int8;
#endif
#ifndef _NI_uInt8_DEFINED_
#define _NI_uInt8_DEFINED_
typedef unsigned char      uInt8;
#endif
#ifndef _NI_int16_DEFINED_
#define _NI_int16_DEFINED_
typedef signed short       int16;
#endif
#ifndef _NI_uInt16_DEFINED_
#define _NI_uInt16_DEFINED_
typedef unsigned short     uInt16;
#endif
#ifndef _NI_int32_DEFINED_
#define _NI_int32_DEFINED_
typedef signed long        int32;
#endif
#ifndef _NI_uInt32_DEFINED_
#define _NI_uInt32_DEFINED_
typedef unsigned long      uInt32;
#endif
#ifndef _NI_float32_DEFINED_
#define _NI_float32_DEFINED_
typedef float              float32;
#endif
#ifndef _NI_float64_DEFINED_
#define _NI_float64_DEFINED_
typedef double             float64;
#endif
#ifndef _NI_int64_DEFINED_
#define _NI_int64_DEFINED_
#ifdef __linux__
typedef long long int      int64;
#else
typedef __int64            int64;
#endif
#endif
#ifndef _NI_uInt64_DEFINED_
#define _NI_uInt64_DEFINED_
#ifdef __linux__
typedef unsigned long long uInt64;
#else
typedef unsigned __int64   uInt64;
#endif
#endif

#ifndef _NI_RFMX_SESSION_DEFINED_
#define _NI_RFMX_SESSION_DEFINED_
typedef void*   niRFmxInstrHandle;
#endif

#if !defined(_NIComplexDoublePrecision)
#define _NIComplexDoublePrecision

#ifndef _WIN64
#pragma pack(push, 1)
#endif

typedef struct NIComplexDouble_struct {
   float64 real;
   float64 imaginary;
} NIComplexDouble;

#ifndef _WIN64
#pragma pack(pop)
#endif

#endif

#if !defined(_NIComplexSinglePrecision)
#define _NIComplexSinglePrecision

#ifndef _WIN64
#pragma pack(push, 1)
#endif

typedef struct NIComplexSingle_struct {
   float32 real;
   float32 imaginary;
} NIComplexSingle;

#ifndef _WIN64
#pragma pack(pop)
#endif

#endif

/*- Time Structures and Helpers ----------------------------------*/

// Please visit ni.com/info and enter the Info Code NI_BTF for more information
#ifndef CVITime_DECLARED
#define CVITime_DECLARED
typedef struct CVITime { unsigned __int64 lsb; __int64 msb; } CVITime;
#endif
#ifndef CVIAbsoluteTime_DECLARED
#define CVIAbsoluteTime_DECLARED
typedef union CVIAbsoluteTime { CVITime cviTime; unsigned int u32Data[4]; } CVIAbsoluteTime;
#endif

/* -- RFmxInstr Attribute IDs --*/

#define RFMXINSTR_ATTR_FREQUENCY_REFERENCE_SOURCE                          0x00000002
#define RFMXINSTR_ATTR_FREQUENCY_REFERENCE_FREQUENCY                       0x00000003
#define RFMXINSTR_ATTR_RF_ATTENUATION_AUTO                                 0x00000004
#define RFMXINSTR_ATTR_RF_ATTENUATION_VALUE                                0x00000005
#define RFMXINSTR_ATTR_MECHANICAL_ATTENUATION_AUTO                         0x00000006
#define RFMXINSTR_ATTR_MECHANICAL_ATTENUATION_VALUE                        0x00000007
#define RFMXINSTR_ATTR_LO_EXPORT_ENABLED                                   0x00000021
#define RFMXINSTR_ATTR_FREQUENCY_REFERENCE_EXPORTED_TERMINAL               0x00000022
#define RFMXINSTR_ATTR_LO2_EXPORT_ENABLED                                  0x0000003A
#define RFMXINSTR_ATTR_TRIGGER_EXPORT_OUTPUT_TERMINAL                      0x00000023
#define RFMXINSTR_ATTR_TRIGGER_TERMINAL_NAME                               0x00000024
#define RFMXINSTR_ATTR_DEVICE_TEMPERATURE                                  0x00000018
#define RFMXINSTR_ATTR_DIGITIZER_TEMPERATURE                               0x00000019
#define RFMXINSTR_ATTR_LO_TEMPERATURE                                      0x0000001a
#define RFMXINSTR_ATTR_SERIAL_NUMBER                                       0x0000001e
#define RFMXINSTR_ATTR_INSTRUMENT_MODEL                                    0x0000001c
#define RFMXINSTR_ATTR_MODULE_REVISION                                     0x0000001d
#define RFMXINSTR_ATTR_INSTRUMENT_FIRMWARE_REVISION                        0x0000001b
#define RFMXINSTR_ATTR_PRESELECTOR_PRESENT                                 0x0000001f
#define RFMXINSTR_ATTR_RF_PREAMP_PRESENT                                   0x00000020
#define RFMXINSTR_ATTR_PREAMP_ENABLED                                      0x0000000e
#define RFMXINSTR_ATTR_CHANNEL_COUPLING                                    0x0000000b
#define RFMXINSTR_ATTR_TUNING_SPEED                                        0x00000008
#define RFMXINSTR_ATTR_DOWNCONVERTER_PRESELECTOR_ENABLED                   0x0000000c
#define RFMXINSTR_ATTR_MIXER_LEVEL                                         0x00000010
#define RFMXINSTR_ATTR_MIXER_LEVEL_OFFSET                                  0x0000000f
#define RFMXINSTR_ATTR_DOWNCONVERTER_CENTER_FREQUENCY                      0x0000000d
#define RFMXINSTR_ATTR_LO_SOURCE                                           0x0000003B
#define RFMXINSTR_ATTR_LO_FREQUENCY                                        0x0000003C
#define RFMXINSTR_ATTR_OSP_DELAY_ENABLED                                   0x00000017
#define RFMXINSTR_ATTR_PHASE_OFFSET                                        0x00000013
#define RFMXINSTR_ATTR_FFT_WIDTH                                           0x00000016
#define RFMXINSTR_ATTR_CLEANER_SPECTRUM                                    0x00000025
#define RFMXINSTR_ATTR_IF_OUTPUT_POWER_LEVEL_OFFSET                        0x00000011
#define RFMXINSTR_ATTR_DIGITIZER_DITHER_ENABLED                            0x00000015
#define RFMXINSTR_ATTR_IF_FILTER_BANDWIDTH                                 0x00000030
#define RFMXINSTR_ATTR_LO_INJECTION_SIDE                                   0x00000012
#define RFMXINSTR_ATTR_FREQUENCY_SETTLING_UNITS                            0x00000009
#define RFMXINSTR_ATTR_FREQUENCY_SETTLING                                  0x0000000a
#define RFMXINSTR_ATTR_SUBSPAN_OVERLAP                                     0x00000032
#define RFMXINSTR_ATTR_DOWNCONVERTER_GAIN                                  0x00000034
#define RFMXINSTR_ATTR_RECOMMENDED_ACQUISITION_TYPE                        0x00000027
#define RFMXINSTR_ATTR_RECOMMENDED_NUMBER_OF_RECORDS                       0x00000028
#define RFMXINSTR_ATTR_RECOMMENDED_TRIGGER_MINIMUM_QUIET_TIME              0x00000029
#define RFMXINSTR_ATTR_RECOMMENDED_IQ_ACQUISITION_TIME                     0x0000002a
#define RFMXINSTR_ATTR_RECOMMENDED_IQ_MINIMUM_SAMPLE_RATE                  0x0000002b
#define RFMXINSTR_ATTR_RECOMMENDED_IQ_PRE_TRIGGER_TIME                     0x0000002c
#define RFMXINSTR_ATTR_RECOMMENDED_SPECTRAL_ACQUISITION_SPAN               0x0000002d
#define RFMXINSTR_ATTR_RECOMMENDED_SPECTRAL_FFT_WINDOW                     0x0000002e
#define RFMXINSTR_ATTR_RECOMMENDED_SPECTRAL_RESOLUTION_BANDWIDTH           0x0000002f
#define RFMXINSTR_ATTR_RECOMMENDED_CENTER_FREQUENCY                        0x00000039
#define RFMXINSTR_ATTR_COMMON_MODE_LEVEL                                   0x00000046
#define RFMXINSTR_ATTR_SMU_RESOURCE_NAME                                   0x00000047
#define RFMXINSTR_ATTR_SMU_CHANNEL                                         0x00000048
#define RFMXINSTR_ATTR_DOWNCONVERTER_FREQUENCY_OFFSET                      0x00000035
#define RFMXINSTR_ATTR_RF_ATTENUATION_STEP_SIZE                            0x00000036
#define RFMXINSTR_ATTR_LO_LEAKAGE_AVOIDANCE_ENABLED                        0x00000037
#define RFMXINSTR_ATTR_AMPLITUDE_SETTLING                                  0x00000038
#define RFMXINSTR_ATTR_OVERFLOW_ERROR_REPORTING                            0x0000004d
#define RFMXINSTR_ATTR_LO_IN_POWER                                         0x0000004e
#define RFMXINSTR_ATTR_LO_OUT_POWER                                        0x0000004f
#define RFMXINSTR_ATTR_LO_PLL_FRACTIONAL_MODE                              0x0000005a
#define RFMXINSTR_ATTR_OPTIMIZE_PATH_FOR_SIGNAL_BANDWIDTH                  0x0000005b
#define RFMXINSTR_ATTR_INPUT_ISOLATION_ENABLED                             0x0000005c
#define RFMXINSTR_ATTR_LO_VCO_FREQUENCY_STEP_SIZE                          0x00000050
#define RFMXINSTR_ATTR_THERMAL_CORRECTION_HEADROOM_RANGE                   0x0000005e
#define RFMXINSTR_ATTR_LO_FREQUENCY_STEP_SIZE                              0x0000005f
#define RFMXINSTR_ATTR_RF_HIGHPASS_FILTER_FREQUENCY                        0x00000031
#define RFMXINSTR_ATTR_SELF_CALIBRATION_VALIDITY_CHECK                     0x00000075
#define RFMXINSTR_ATTR_SELF_CALIBRATION_VALIDITY_CHECK_TIME_INTERVAL       0x00000076
#define RFMXINSTR_ATTR_START_TRIGGER_TYPE                                  0x00000062
#define RFMXINSTR_ATTR_START_TRIGGER_DIGITAL_EDGE_SOURCE                   0x00000063
#define RFMXINSTR_ATTR_START_TRIGGER_DIGITAL_EDGE                          0x00000064
#define RFMXINSTR_ATTR_START_TRIGGER_EXPORT_OUTPUT_TERMINAL                0x00000065
#define RFMXINSTR_ATTR_START_TRIGGER_TERMINAL_NAME                         0x00000066
#define RFMXINSTR_ATTR_ADVANCE_TRIGGER_TYPE                                0x00000067
#define RFMXINSTR_ATTR_ADVANCE_TRIGGER_DIGITAL_EDGE_SOURCE                 0x00000068
#define RFMXINSTR_ATTR_ADVANCE_TRIGGER_EXPORT_OUTPUT_TERMINAL              0x00000069
#define RFMXINSTR_ATTR_ADVANCE_TRIGGER_TERMINAL_NAME                       0x0000006a
#define RFMXINSTR_ATTR_READY_FOR_START_EVENT_OUTPUT_TERMINAL               0x0000006b
#define RFMXINSTR_ATTR_READY_FOR_START_EVENT_TERMINAL_NAME                 0x0000006c
#define RFMXINSTR_ATTR_READY_FOR_ADVANCE_EVENT_OUTPUT_TERMINAL             0x0000006d
#define RFMXINSTR_ATTR_READY_FOR_ADVANCE_EVENT_TERMINAL_NAME               0x0000006e
#define RFMXINSTR_ATTR_READY_FOR_REFERENCE_EVENT_OUTPUT_TERMINAL           0x0000006f
#define RFMXINSTR_ATTR_READY_FOR_REFERENCE_EVENT_TERMINAL_NAME             0x00000070
#define RFMXINSTR_ATTR_END_OF_RECORD_EVENT_OUTPUT_TERMINAL                 0x00000071
#define RFMXINSTR_ATTR_END_OF_RECORD_EVENT_TERMINAL_NAME                   0x00000072
#define RFMXINSTR_ATTR_DONE_EVENT_OUTPUT_TERMINAL                          0x00000073
#define RFMXINSTR_ATTR_DONE_EVENT_TERMINAL_NAME                            0x00000074
#define RFMXINSTR_ATTR_TEMPERATURE_READ_INTERVAL                           0x00000077
#define RFMXINSTR_ATTR_THERMAL_CORRECTION_TEMPERATURE_RESOLUTION           0x00000078
#define RFMXINSTR_ATTR_LO_SHARING_MODE                                     0x00000044
#define RFMXINSTR_ATTR_NUMBER_OF_LO_SHARING_GROUPS                         0x00000061


/* -- Values for binary attributes -- */
#define RFMXINSTR_VAL_FALSE                                                0
#define RFMXINSTR_VAL_TRUE                                                 1

/* -- Values for RF Attenuation Auto -- */

#define RFMXINSTR_VAL_RF_ATTENUATION_AUTO_FALSE                            0
#define RFMXINSTR_VAL_RF_ATTENUATION_AUTO_TRUE                             1

/* -- Values for RF Mechanical Attenuation Auto -- */

#define RFMXINSTR_VAL_MECHANICAL_ATTENUATION_AUTO_FALSE                    0
#define RFMXINSTR_VAL_MECHANICAL_ATTENUATION_AUTO_TRUE                     1

/* -- Values for LO2 Export Enabled -- */
#define RFMXINSTR_VAL_LO2_EXPORT_DISABLED                                  0
#define RFMXINSTR_VAL_LO2_EXPORT_ENABLED                                   1

/* -- Values for LO Source  -- */

#define RFMXINSTR_VAL_LO_SOURCE_NONE                                        "None"
#define RFMXINSTR_VAL_LO_SOURCE_ONBOARD                                     "Onboard"
#define RFMXINSTR_VAL_LO_SOURCE_LO_IN                                       "LO_In"
#define RFMXINSTR_VAL_LO_SOURCE_SECONDARY                                   "Secondary"
#define RFMXINSTR_VAL_LO_SOURCE_SG_SA_SHARED                                "SG_SA_Shared"
#define RFMXINSTR_VAL_LO_SOURCE_AUTOMATIC_SG_SA_SHARED                      "Automatic_SG_SA_Shared"

/* -- Values for Tuning Speed -- */

#define RFMXINSTR_VAL_TUNING_SPEED_NORMAL                                  0
#define RFMXINSTR_VAL_TUNING_SPEED_MEDIUM                                  1
#define RFMXINSTR_VAL_TUNING_SPEED_FAST                                    2

/* -- Values for Frequency Settling Units -- */

#define RFMXINSTR_VAL_FREQUENCY_SETTLING_UNITS_PPM                         0
#define RFMXINSTR_VAL_FREQUENCY_SETTLING_UNITS_SECONDS_AFTER_LOCK          1
#define RFMXINSTR_VAL_FREQUENCY_SETTLING_UNITS_SECONDS_AFTER_IO            2

/* -- Values for Cleaner Spectrum -- */

#define RFMXINSTR_VAL_CLEANER_SPECTRUM_DISABLED                            0
#define RFMXINSTR_VAL_CLEANER_SPECTRUM_ENABLED                             1

/* -- Values for Channel Coupling -- */

#define RFMXINSTR_VAL_CHANNEL_COUPLING_AC_COUPLED                          0
#define RFMXINSTR_VAL_CHANNEL_COUPLING_DC_COUPLED                          1

/* -- Values for Downconverter Preselector Enabled -- */

#define RFMXINSTR_VAL_DOWNCONVERTER_PRESELECTOR_DISABLED                   0
#define RFMXINSTR_VAL_DOWNCONVERTER_PRESELECTOR_ENABLED                    1

/* -- Values for Preamp Enabled -- */

#define RFMXINSTR_VAL_PREAMP_DISABLED                                      0
#define RFMXINSTR_VAL_PREAMP_ENABLED                                       1
#define RFMXINSTR_VAL_PREAMP_AUTOMATIC                                     3

/* -- Values for LO Injection Side -- */

#define RFMXINSTR_VAL_LO_INJECTION_HIGH_SIDE                               0
#define RFMXINSTR_VAL_LO_INJECTION_LOW_SIDE                                1

/* -- Values for Digitizer Dither Enabled -- */

#define RFMXINSTR_VAL_DIGITIZER_DITHER_DISABLED                            0
#define RFMXINSTR_VAL_DIGITIZER_DITHER_ENABLED                             1

/* -- Values for OSP Delay Enabled -- */

#define RFMXINSTR_VAL_OSP_DELAY_DISABLED                                   0
#define RFMXINSTR_VAL_OSP_DELAY_ENABLED                                    1

/* -- Values for Export Signal Source -- */

#define RFMXINSTR_VAL_START_TRIGGER                                        0
#define RFMXINSTR_VAL_REFERENCE_TRIGGER                                    1
#define RFMXINSTR_VAL_ADVANCE_TRIGGER                                      2
#define RFMXINSTR_VAL_READY_FOR_START_EVENT                                3
#define RFMXINSTR_VAL_READY_FOR_REFERENCE_EVENT                            4
#define RFMXINSTR_VAL_READY_FOR_ADVANCE_EVENT                              5
#define RFMXINSTR_VAL_END_OF_RECORD_EVENT                                  6
#define RFMXINSTR_VAL_DONE_EVENT                                           7
#define RFMXINSTR_VAL_REFERENCE_CLOCK                                      8

/* -- Values for LO Export Enabled -- */

#define RFMXINSTR_VAL_LO_EXPORT_DISABLED                                   0
#define RFMXINSTR_VAL_LO_EXPORT_ENABLED                                    1

/* -- Values for Acquisition Type -- */

#define RFMXINSTR_VAL_RECOMMENDED_ACQUISITION_TYPE_IQ                      0
#define RFMXINSTR_VAL_RECOMMENDED_ACQUISITION_TYPE_SPECTRAL                1
#define RFMXINSTR_VAL_RECOMMENDED_ACQUISITION_TYPE_IQ_OR_SPECTRAL          2

/* -- Values for FFT Window -- */

#define RFMXINSTR_VAL_RECOMMENDED_SPECTRAL_FFT_WINDOW_NONE                 0
#define RFMXINSTR_VAL_RECOMMENDED_SPECTRAL_FFT_WINDOW_FLAT_TOP             1
#define RFMXINSTR_VAL_RECOMMENDED_SPECTRAL_FFT_WINDOW_HANNING              2
#define RFMXINSTR_VAL_RECOMMENDED_SPECTRAL_FFT_WINDOW_HAMMING              3
#define RFMXINSTR_VAL_RECOMMENDED_SPECTRAL_FFT_WINDOW_GAUSSIAN             4
#define RFMXINSTR_VAL_RECOMMENDED_SPECTRAL_FFT_WINDOW_BLACKMAN             5
#define RFMXINSTR_VAL_RECOMMENDED_SPECTRAL_FFT_WINDOW_BLACKMAN_HARRIS      6
#define RFMXINSTR_VAL_RECOMMENDED_SPECTRAL_FFT_WINDOW_KAISER_BESSEL        7

/* -- Values for Steps to Omit -- */
#define RFMXINSTR_VAL_SELF_CAL_STEP_NONE                                   0
#define RFMXINSTR_VAL_SELF_CAL_STEP_PRESELECTOR_ALIGNMENT                  1 << 0
#define RFMXINSTR_VAL_SELF_CAL_STEP_GAIN_REFERENCE                         1 << 1
#define RFMXINSTR_VAL_SELF_CAL_STEP_IF_FLATNESS                            1 << 2
#define RFMXINSTR_VAL_SELF_CAL_STEP_DIGITIZER_SELF_CAL                     1 << 3
#define RFMXINSTR_VAL_SELF_CAL_STEP_LO_SELF_CAL                            1 << 4
#define RFMXINSTR_VAL_SELF_CAL_STEP_AMPLITUDE_ACCURACY                     1 << 5
#define RFMXINSTR_VAL_SELF_CAL_STEP_RESIDUAL_LO_POWER                      1 << 6
#define RFMXINSTR_VAL_SELF_CAL_STEP_IMAGE_SUPPRESSION                      1 << 7
#define RFMXINSTR_VAL_SELF_CAL_STEP_SYNTHESIZER_ALIGNMENT                  1 << 8
#define RFMXINSTR_VAL_SELF_CAL_STEP_DC_OFFSET                              1 << 9
/* -- Values for Frequency Reference Source -- */

#define RFMXINSTR_VAL_ONBOARD_CLOCK_STR                                    "OnboardClock"
#define RFMXINSTR_VAL_REF_IN_STR                                           "RefIn"
#define RFMXINSTR_VAL_PXI_CLK_STR                                          "PXI_Clk"
#define RFMXINSTR_VAL_CLK_IN_STR                                           "ClkIn"
#define RFMXINSTR_VAL_REF_IN2_STR                                          "RefIn2"
#define RFMXINSTR_VAL_PXI_CLK_MASTER_STR                                   "PXI_ClkMaster"

/* -- Values for Frequency Reference Exported Terminal -- */

#define RFMXINSTR_VAL_NONE_STR                                             ""
#define RFMXINSTR_VAL_REF_OUT_STR                                          "RefOut"
#define RFMXINSTR_VAL_REF_OUT2_STR                                         "RefOut2"
#define RFMXINSTR_VAL_CLK_OUT_STR                                          "ClkOut"

/* -- Values for Trigger Export Output Terminal -- */

#define RFMXINSTR_VAL_DO_NOT_EXPORT_STR                                    ""
#define RFMXINSTR_VAL_PFI0_STR                                             "PFI0"
#define RFMXINSTR_VAL_PFI1_STR                                             "PFI1"
#define RFMXINSTR_VAL_PXI_TRIG0_STR                                        "PXI_Trig0"
#define RFMXINSTR_VAL_PXI_TRIG1_STR                                        "PXI_Trig1"
#define RFMXINSTR_VAL_PXI_TRIG2_STR                                        "PXI_Trig2"
#define RFMXINSTR_VAL_PXI_TRIG3_STR                                        "PXI_Trig3"
#define RFMXINSTR_VAL_PXI_TRIG4_STR                                        "PXI_Trig4"
#define RFMXINSTR_VAL_PXI_TRIG5_STR                                        "PXI_Trig5"
#define RFMXINSTR_VAL_PXI_TRIG6_STR                                        "PXI_Trig6"
#define RFMXINSTR_VAL_PXI_TRIG7_STR                                        "PXI_Trig7"
#define RFMXINSTR_VAL_PXI_STAR_STR                                         "PXI_STAR"
#define RFMXINSTR_VAL_PXIE_DSTARC_STR                                      "PXIe_DStarC"
#define RFMXINSTR_VAL_PXIE_DSTARB_STR                                      "PXIe_DStarB"
#define RFMXINSTR_VAL_TIMER_EVENT_STR                                      "TimerEvent"

/* -- Values for LO Leakage Avoidance Enabled -- */
#define RFMXINSTR_VAL_LO_LEAKAGE_AVOIDANCE_ENABLED_FALSE                   0
#define RFMXINSTR_VAL_LO_LEAKAGE_AVOIDANCE_ENABLED_TRUE                    1

//Enum PersonalityID
#define RFMXINSTR_VAL_PERSONALITY_NONE                                      0
#define RFMXINSTR_VAL_PERSONALITY_SPECAN                                   (1 << 0)
#define RFMXINSTR_VAL_PERSONALITY_DEMOD                                    (1 << 1)
#define RFMXINSTR_VAL_PERSONALITY_LTE                                      (1 << 2)
#define RFMXINSTR_VAL_PERSONALITY_GSM                                      (1 << 3)
#define RFMXINSTR_VAL_PERSONALITY_WCDMA                                    (1 << 4)
#define RFMXINSTR_VAL_PERSONALITY_CDMA2K                                   (1 << 5)
#define RFMXINSTR_VAL_PERSONALITY_TDSCDMA                                  (1 << 6)
#define RFMXINSTR_VAL_PERSONALITY_EVDO                                     (1 << 7)
#define RFMXINSTR_VAL_PERSONALITY_NR                                       (1 << 8)
#define RFMXINSTR_VAL_PERSONALITY_BT                                       (1 << 10)
#define RFMXINSTR_VAL_PERSONALITY_WLAN                                     (1 << 9)
#define RFMXINSTR_VAL_PERSONALITY_VNA                                      (1 << 12)
#define RFMXINSTR_VAL_PERSONALITY_PULSE                                    (1 << 11)
#define RFMXINSTR_VAL_PERSONALITY_ALL                                      0x7FFFFFFF

/* -- Values for Overflow Error Reporting -- */
#define RFMXINSTR_VAL_OVERFLOW_ERROR_REPORTING_WARNING                     0
#define RFMXINSTR_VAL_OVERFLOW_ERROR_REPORTING_DISABLED                    1

/*- Values for S-parameters orientation passed to Create De-embedding S-parameter Table functions -*/
#define RFMXINSTR_VAL_PORT1_TOWARDS_DUT                                    0
#define RFMXINSTR_VAL_PORT2_TOWARDS_DUT                                    1

/*- Values for Linear Interpolation passed to Configure External Attenuation Interpolation Linear function -*/
#define RFMXINSTR_VAL_LINEAR_INTERPOLATION_FORMAT_REAL_AND_IMAGINARY       0
#define RFMXINSTR_VAL_LINEAR_INTERPOLATION_FORMAT_MAGNITUDE_AND_PHASE      1
#define RFMXINSTR_VAL_LINEAR_INTERPOLATION_FORMAT_MAGNITUDE_DB_AND_PHASE   2

/*  Values for LO PLL Fractional Mode */
#define RFMXINSTR_VAL_LO_PLL_FRACTIONAL_MODE_DISABLED                      0
#define RFMXINSTR_VAL_LO_PLL_FRACTIONAL_MODE_ENABLED                       1

/* Values for Optimize Path For Signal Bandwidth */
#define RFMXINSTR_VAL_OPTIMIZE_PATH_FOR_SIGNAL_BANDWIDTH_DISABLED          0
#define RFMXINSTR_VAL_OPTIMIZE_PATH_FOR_SIGNAL_BANDWIDTH_ENABLED           1
#define RFMXINSTR_VAL_OPTIMIZE_PATH_FOR_SIGNAL_BANDWIDTH_AUTOMATIC         2

/*  Values for Input Isolation Enabled */
#define RFMXINSTR_VAL_INPUT_ISOLATION_DISABLED                             0
#define RFMXINSTR_VAL_INPUT_ISOLATION_ENABLED                              1

/* Values for S-Parameter Type */
#define RFMXINSTR_VAL_SPARAMETER_TYPE_SCALAR                               1
#define RFMXINSTR_VAL_SPARAMETER_TYPE_VECTOR                               2

/* Values for Self Calibration Validity Check */
#define RFMXINSTR_VAL_SELF_CALIBRATION_VALIDITY_CHECK_OFF                  0
#define RFMXINSTR_VAL_SELF_CALIBRATION_VALIDITY_CHECK_ENABLED              1

/* Values for Start Trigger Type */
#define RFMXINSTR_VAL_START_TRIGGER_TYPE_NONE                              0
#define RFMXINSTR_VAL_START_TRIGGER_TYPE_DIGITAL_EDGE                      1
#define RFMXINSTR_VAL_START_TRIGGER_TYPE_SOFTWARE                          3

/* Values for Start Trigger Digital Edge */
#define RFMXINSTR_VAL_START_TRIGGER_DIGITAL_EDGE_RISING_EDGE               0
#define RFMXINSTR_VAL_START_TRIGGER_DIGITAL_EDGE_FALLING_EDGE              1

/* Values for Advance Trigger Type */
#define RFMXINSTR_VAL_ADVANCE_TRIGGER_TYPE_NONE                            0
#define RFMXINSTR_VAL_ADVANCE_TRIGGER_TYPE_DIGITAL_EDGE                    1
#define RFMXINSTR_VAL_ADVANCE_TRIGGER_TYPE_SOFTWARE                        3

/* Values for LO Sharing Mode */
#define RFMXINSTR_VAL_LO_SHARING_MODE_DISABLED                             0
#define RFMXINSTR_VAL_LO_SHARING_MODE_EXTERNAL_STAR                        3
#define RFMXINSTR_VAL_LO_SHARING_MODE_EXTERNAL_DAISY_CHAIN                 4

/*****************************************************************************/
/*= Macros for checking for errors.                                 ======== */
/*= The RFmxcheckWarn macro preserve warnings.                      ======== */
/*****************************************************************************/
#ifndef RFmxCheckWarn
#define RFmxCheckWarn(fCall)     if (1) {int32 _code_; if (_code_ = (fCall), _code_ < 0)    \
                                    {error = _code_;goto Error;}        \
                                    else error = (error==0)?_code_:error;} else error = error
#endif

#ifndef RFmxCheckAlloc
#define RFmxCheckAlloc(fCall)    if ((fCall) == 0) \
                                 {error = -1; goto Error;}  else error = error
#endif


#ifdef __cplusplus
extern "C"
{
#endif

   /******************************************************************************
    *------------------- NI RFmxInstr Function Declarations ---------------------*
    *****************************************************************************/

   // Initializiation methods
   int32 __stdcall RFmxInstr_Initialize(
      char resourceName[],
      char optionString[],
      niRFmxInstrHandle *handleOut,
      int32 *isNewSession);

   int32 __stdcall RFmxInstr_InitializeFromNIRFSASession(
      uInt32 NIRFSASession,
      niRFmxInstrHandle *handleOut);

   int32 __stdcall RFmxInstr_InitializeFromNIRFSASessionArray(
       uInt32 NIRFSASessions[],
       int32 numberOfNIRFSASessions,
       niRFmxInstrHandle* handleOut
       );

   // Close method
   int32 __stdcall RFmxInstr_Close(
      niRFmxInstrHandle instrumentHandle,
      int32 forceDestroy);

   // Error methods
   int32 __stdcall RFmxInstr_GetError(
      niRFmxInstrHandle instrumentHandle,
      int32* errorCode,
      int32 errorDescriptionBufferSize,
      char errorDescription[]);

   int32 __stdcall RFmxInstr_GetErrorString(
      niRFmxInstrHandle instrumentHandle,
      int32 errorCode,
      int32 errorDescriptionBufferSize,
      char errorDescription[]);

   // Configuation methods
   int32 __stdcall RFmxInstr_CfgFrequencyReference(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      char frequencyReferenceSource[],
      float64 frequencyReferenceFrequency);

   int32 __stdcall RFmxInstr_CfgMechanicalAttenuation(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 mechanicalAttenuationAuto,
      float64 mechanicalAttenuationValue);

   int32 __stdcall RFmxInstr_CfgRFAttenuation(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 RFAttenuationAuto,
      float64 RFAttenuationValue);

   int32 __stdcall RFmxInstr_CfgExternalAttenuationTable(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      char tableName[],
      float64 frequency[],
      float64 externalAttenuation[],
      int32 arraySize
   );

   int32 __stdcall RFmxInstr_CfgSParameterExternalAttenuationType(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 sParameterType
   );

   int32 __stdcall RFmxInstr_CfgSParameterExternalAttenuationTable(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      char tableName[],
      float64 frequency[],
      int32 frequencyArraySize,
      NIComplexDouble sParameters[],
      int32 sParameterTableSize,
      int32 numberOfPorts,
      int32 sParameterOrientation
   );

   int32 __stdcall RFmxInstr_CfgExternalAttenuationInterpolationNearest
   (
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      char tableName[]
   );

   int32 __stdcall RFmxInstr_CfgExternalAttenuationInterpolationLinear
   (
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      char tableName[],
      int32 format
   );

   int32 __stdcall RFmxInstr_CfgExternalAttenuationInterpolationSpline
   (
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      char tableName[]
   );

   int32 __stdcall RFmxInstr_DeleteExternalAttenuationTable(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      char tableName[]
   );

   int32 __stdcall RFmxInstr_DeleteAllExternalAttenuationTables(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[]
   );

   int32 __stdcall RFmxInstr_EnableCalibrationPlane(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[]
   );

   int32 __stdcall RFmxInstr_DisableCalibrationPlane(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[]
   );

   // Utility methods
   int32 __stdcall RFmxInstr_WaitForAcquisitionComplete(
      niRFmxInstrHandle instrumentHandle,
      float64 timeout);

   int32 __stdcall RFmxInstr_CheckAcquisitionStatus(
      niRFmxInstrHandle instrumentHandle,
      int32* acquisitionDone
   );

   int32 __stdcall RFmxInstr_ResetToDefault(
      niRFmxInstrHandle instrumentHandle);

   int32 __stdcall RFmxInstr_ResetDriver(
      niRFmxInstrHandle instrumentHandle);

   int32 __stdcall RFmxInstr_GetNIRFSASession(
      niRFmxInstrHandle instrumentHandle,
      uInt32 *niRfsaSession);

   int32 __stdcall RFmxInstr_GetNIRFSASessionArray(
       niRFmxInstrHandle instrumentHandle,
       uInt32 NIRFSASessions[],
       int32 arraySize,
       int32* actualArraySize
       );

   int32 __stdcall RFmxInstr_CheckIfSignalConfigurationExists(
      niRFmxInstrHandle instrumentHandle,
      char signalName[],
      int32* signalConfigurationExists,
      int32* personality
   );

   int32 __stdcall RFmxInstr_CheckIfListExists(
      niRFmxInstrHandle instrumentHandle,
      char listName[],
      int32* listExists,
      int32* personality
   );

   int32 __stdcall RFmxInstr_SaveAllConfigurations(
      niRFmxInstrHandle instrumentHandle,
      char filePath[]);

   int32 __stdcall RFmxInstr_LoadAllConfigurations(
      niRFmxInstrHandle instrumentHandle,
      char filePath[],
      int32 loadRFInstrConfiguration);

   int32 __stdcall RFmxInstr_ResetEntireSession(
      niRFmxInstrHandle instrumentHandle);

   int32 __stdcall RFmxInstr_ResetAttribute(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID);

   int32 __stdcall RFmxInstr_GetSignalConfigurationNames(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 personalityFilter,
      char signalNames[],
      int32 signalNamesSize,
      int32* actualSignalNamesSize,
      int32 personality[],
      int32 personalityArraySize,
      int32* actualPersonalityArraySize
   );

   int32 __stdcall RFmxInstr_GetListNames(
       niRFmxInstrHandle instrumentHandle,
       char selectorString[],
       int32 personalityFilter,
       char listNames[],
       int32 listNamesSize,
       int32* actualListNamesSize,
       int32 personality[],
       int32 personalityArraySize,
       int32* actualPersonalityArraySize
   );


   int32 __stdcall RFmxInstr_GetAvailablePorts(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 arraySize,
      char availablePorts[]
   );

   int32 __stdcall RFmxInstr_ExportSignal(
      niRFmxInstrHandle instrumentHandle,
      int32 exportSignalSource,
      char exportSignalOutputTerminal[]);

   int32 __stdcall RFmxInstr_LoadSParameterExternalAttenuationTableFromS2PFile(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      char tableName[],
      char S2PFilePath[],
      int32 sParameterOrientation
   );

   int32 __stdcall RFmxInstr_SelectActiveExternalAttenuationTable(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      char tableName[]
   );

   int32 __stdcall RFmxInstr_GetExternalAttenuationTableActualValue(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      float64* externalAttenuation
   );

   int32 __stdcall RFmxInstr_SelfCalibrate(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 stepsToOmit
   );

   int32 __stdcall RFmxInstr_SelfCalibrateRange(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 stepsToOmit,
      float64 minimumFrequency,
      float64 maximumFrequency,
      float64 minimumReferenceLevel,
      float64 maximumReferenceLevel
   );

   int32 __stdcall RFmxInstr_IsSelfCalibrateValid(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32* selfCalibrateValid,
      int32* validSteps
   );

   int32 __stdcall RFmxInstr_GetSelfCalibrateLastDateAndTime(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int64 selfCalibrateStep,
      CVIAbsoluteTime* timestamp
   );

   int32 __stdcall RFmxInstr_GetSelfCalibrateLastTemperature(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int64 selfCalibrateStep,
      float64* temperature
   );

   int32 __stdcall RFmxInstr_ValuesFromTimestamp(
      CVIAbsoluteTime timestamp,
      int64* secondsSince1970,
      float64* fractionalSeconds);

   int32 __stdcall RFmxInstr_TimestampFromValues(
      int64 secondsSince1970,
      float64 fractionalSeconds,
      CVIAbsoluteTime* timestamp);

   int32 __stdcall RFmxInstr_SendSoftwareEdgeStartTrigger(
      niRFmxInstrHandle instrumentHandle
   );

   int32 __stdcall RFmxInstr_SendSoftwareEdgeAdvanceTrigger(
      niRFmxInstrHandle instrumentHandle
   );

   int32 __stdcall RFmxInstr_RegisterExternalRFSubsystemCallbacks(
      niRFmxInstrHandle instrumentHandle,
      void *externalRFSubsystemContext,
      void *callbacks[],
      int32 arraySize,
      int32 callbackVersion);

   int32 __stdcall RFmxInstr_UnregisterExternalRFSubsystemCallbacks(niRFmxInstrHandle instrumentHandle);

   // Build string methods
   int32 __stdcall RFmxInstr_BuildPortString2(
      char selectorString[],
      char portName[],
      char deviceName[],
      int32 channelNumber,
      int32 selectorStringOutLength,
      char selectorStringOut[]
   );

   int32 __stdcall RFmxInstr_BuildCalibrationPlaneString(
      char calibrationPlaneName[],
      int32 selectorStringLength,
      char selectorString[]
   );

   int32 __stdcall RFmxInstr_BuildLOString(
      char selectorString[],
      int32 LOIndex,
      int32 selectorStringOutLength,
      char selectorStringOut[]
   );

   int32 __stdcall RFmxInstr_BuildModuleString(
      char selectorString[],
      char moduleName[],
      int32 selectorStringOutLength,
      char selectorStringOut[]
   );

   int32 __stdcall RFmxInstr_BuildInstrumentString(
      char selectorString[],
      int32 instrumentNumber,
      int32 selectorStringOutLength,
      char selectorStringOut[]
   );

   // Generic Get/Set Methods
   int32 __stdcall RFmxInstr_SetAttributeString(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      char attrVal[]
   );
   int32 __stdcall RFmxInstr_GetAttributeString(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      int32 arraySize,
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_SetAttributeI8(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      int8 attrVal
   );
   int32 __stdcall RFmxInstr_GetAttributeI8(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      int8 *attrVal
   );

   int32 __stdcall RFmxInstr_SetAttributeU8(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      uInt8 attrVal
   );
   int32 __stdcall RFmxInstr_GetAttributeU8(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      uInt8 *attrVal
   );

   int32 __stdcall RFmxInstr_SetAttributeI16(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      int16 attrVal
   );
   int32 __stdcall RFmxInstr_GetAttributeI16(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      int16 *attrVal
   );

   int32 __stdcall RFmxInstr_SetAttributeU16(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      uInt16 attrVal
   );
   int32 __stdcall RFmxInstr_GetAttributeU16(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      uInt16 *attrVal
   );

   int32 __stdcall RFmxInstr_SetAttributeI32(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      int32 attrVal
   );
   int32 __stdcall RFmxInstr_GetAttributeI32(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      int32 *attrVal
   );

   int32 __stdcall RFmxInstr_SetAttributeU32(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      uInt32 attrVal
   );
   int32 __stdcall RFmxInstr_GetAttributeU32(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      uInt32 *attrVal
   );

   int32 __stdcall RFmxInstr_SetAttributeI64(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      int64 attrVal
   );
   int32 __stdcall RFmxInstr_GetAttributeI64(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      int64 *attrVal
   );

   int32 __stdcall RFmxInstr_SetAttributeF64(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      float64 attrVal
   );
   int32 __stdcall RFmxInstr_GetAttributeF64(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      float64 *attrVal
   );

   int32 __stdcall RFmxInstr_SetAttributeF32(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      float32 attrVal
   );
   int32 __stdcall RFmxInstr_GetAttributeF32(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      float32 *attrVal
   );

   int32 __stdcall RFmxInstr_SetAttributeI8Array(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      int8 attrVal[],
      int32 arraySize
   );
   int32 __stdcall RFmxInstr_GetAttributeI8Array(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      int8 attrVal[],
      int32 arraySize,
      int32 *actualArraySize
   );

   int32 __stdcall RFmxInstr_SetAttributeI32Array(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      int32 attrVal[],
      int32 arraySize
   );
   int32 __stdcall RFmxInstr_GetAttributeI32Array(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      int32 attrVal[],
      int32 arraySize,
      int32 *actualArraySize
   );

   int32 __stdcall RFmxInstr_SetAttributeI64Array(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      int64 attrVal[],
      int32 arraySize
   );
   int32 __stdcall RFmxInstr_GetAttributeI64Array(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      int64 attrVal[],
      int32 arraySize,
      int32 *actualArraySize
   );

   int32 __stdcall RFmxInstr_SetAttributeU64Array(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      uInt64 attrVal[],
      int32 arraySize
   );
   int32 __stdcall RFmxInstr_GetAttributeU64Array(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      uInt64 attrVal[],
      int32 arraySize,
      int32 *actualArraySize
   );

   int32 __stdcall RFmxInstr_SetAttributeU8Array(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      uInt8 attrVal[],
      int32 arraySize
   );
   int32 __stdcall RFmxInstr_GetAttributeU8Array(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      uInt8 attrVal[],
      int32 arraySize,
      int32 *actualArraySize
   );

   int32 __stdcall RFmxInstr_SetAttributeU32Array(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      uInt32 attrVal[],
      int32 arraySize
   );
   int32 __stdcall RFmxInstr_GetAttributeU32Array(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      uInt32 attrVal[],
      int32 arraySize,
      int32 *actualArraySize
   );

   int32 __stdcall RFmxInstr_SetAttributeF32Array(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      float32 attrVal[],
      int32 arraySize
   );
   int32 __stdcall RFmxInstr_GetAttributeF32Array(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      float32 attrVal[],
      int32 arraySize,
      int32 *actualArraySize
   );

   int32 __stdcall RFmxInstr_SetAttributeF64Array(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      float64 attrVal[],
      int32 arraySize
   );
   int32 __stdcall RFmxInstr_GetAttributeF64Array(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      float64 attrVal[],
      int32 arraySize,
      int32 *actualArraySize
   );

   int32 __stdcall RFmxInstr_SetAttributeNIComplexSingleArray(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      NIComplexSingle attrVal[],
      int32 arraySize
   );
   int32 __stdcall RFmxInstr_GetAttributeNIComplexSingleArray(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      NIComplexSingle attrVal[],
      int32 arraySize,
      int32 *actualArraySize
   );

   int32 __stdcall RFmxInstr_SetAttributeNIComplexDoubleArray(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      NIComplexDouble attrVal[],
      int32 arraySize
   );

   int32 __stdcall RFmxInstr_GetAttributeNIComplexDoubleArray(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attributeID,
      NIComplexDouble attrVal[],
      int32 arraySize,
      int32 *actualArraySize
   );

   // Get/Set attribute methods
   int32 __stdcall RFmxInstr_SetFrequencyReferenceSource(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      char attrVal[]);

   int32 __stdcall RFmxInstr_GetFrequencyReferenceSource(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 arraySize,
      char attrVal[]);

   int32 __stdcall RFmxInstr_SetFrequencyReferenceFrequency(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 attrVal);

   int32 __stdcall RFmxInstr_GetFrequencyReferenceFrequency(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_SetRFAttenuationAuto(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attrVal);

   int32 __stdcall RFmxInstr_GetRFAttenuationAuto(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 *attrVal);

   int32 __stdcall RFmxInstr_SetRFAttenuationValue(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 attrVal);

   int32 __stdcall RFmxInstr_GetRFAttenuationValue(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_SetMechanicalAttenuationAuto(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attrVal);

   int32 __stdcall RFmxInstr_GetMechanicalAttenuationAuto(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 *attrVal);

   int32 __stdcall RFmxInstr_SetMechanicalAttenuationValue(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 attrVal);

   int32 __stdcall RFmxInstr_GetMechanicalAttenuationValue(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_SetTuningSpeed(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attrVal);

   int32 __stdcall RFmxInstr_GetTuningSpeed(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 *attrVal);

   int32 __stdcall RFmxInstr_SetFrequencySettlingUnits(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attrVal);

   int32 __stdcall RFmxInstr_GetFrequencySettlingUnits(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 *attrVal);

   int32 __stdcall RFmxInstr_SetFrequencySettling(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 attrVal);

   int32 __stdcall RFmxInstr_GetFrequencySettling(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_SetChannelCoupling(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attrVal);

   int32 __stdcall RFmxInstr_GetChannelCoupling(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 *attrVal);

   int32 __stdcall RFmxInstr_SetDownconverterPreselectorEnabled(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attrVal);

   int32 __stdcall RFmxInstr_GetDownconverterPreselectorEnabled(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 *attrVal);

   int32 __stdcall RFmxInstr_SetDownconverterCenterFrequency(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 attrVal);

   int32 __stdcall RFmxInstr_GetDownconverterCenterFrequency(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_SetLOSource(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      char attrVal[]);

   int32 __stdcall RFmxInstr_GetLOSource(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 arraySize,
      char attrVal[]);

   int32 __stdcall RFmxInstr_SetLOFrequency(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 attrVal);

   int32 __stdcall RFmxInstr_GetLOFrequency(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_SetPreampEnabled(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attrVal);

   int32 __stdcall RFmxInstr_GetPreampEnabled(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 *attrVal);

   int32 __stdcall RFmxInstr_SetMixerLevelOffset(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 attrVal);

   int32 __stdcall RFmxInstr_GetMixerLevelOffset(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_SetMixerLevel(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 attrVal);

   int32 __stdcall RFmxInstr_GetMixerLevel(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_SetIFOutputPowerLevelOffset(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 attrVal);

   int32 __stdcall RFmxInstr_GetIFOutputPowerLevelOffset(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_SetLOInjectionSide(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attrVal);

   int32 __stdcall RFmxInstr_GetLOInjectionSide(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 *attrVal);

   int32 __stdcall RFmxInstr_SetPhaseOffset(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 attrVal);

   int32 __stdcall RFmxInstr_GetPhaseOffset(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_SetDigitizerDitherEnabled(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attrVal);

   int32 __stdcall RFmxInstr_GetDigitizerDitherEnabled(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 *attrVal);

   int32 __stdcall RFmxInstr_SetFFTWidth(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 attrVal);

   int32 __stdcall RFmxInstr_GetFFTWidth(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_SetOSPDelayEnabled(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attrVal);

   int32 __stdcall RFmxInstr_GetOSPDelayEnabled(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 *attrVal);

   int32 __stdcall RFmxInstr_GetDeviceTemperature(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_GetDigitizerTemperature(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_GetLOTemperature(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_GetInstrumentFirmwareRevision(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 arraySize,
      char attrVal[]);

   int32 __stdcall RFmxInstr_GetInstrumentModel(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 arraySize,
      char attrVal[]);

   int32 __stdcall RFmxInstr_GetModuleRevision(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 arraySize,
      char attrVal[]);

   int32 __stdcall RFmxInstr_GetSerialNumber(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 arraySize,
      char attrVal[]);

   int32 __stdcall RFmxInstr_GetPreselectorPresent(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 *attrVal);

   int32 __stdcall RFmxInstr_GetRFPreampPresent(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 *attrVal);

   int32 __stdcall RFmxInstr_SetLOExportEnabled(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attrVal);

   int32 __stdcall RFmxInstr_GetLOExportEnabled(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 *attrVal);

   int32 __stdcall RFmxInstr_SetLO2ExportEnabled(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attrVal);

   int32 __stdcall RFmxInstr_GetLO2ExportEnabled(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 *attrVal);

   int32 __stdcall RFmxInstr_SetFrequencyReferenceExportedTerminal(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      char attrVal[]);

   int32 __stdcall RFmxInstr_GetFrequencyReferenceExportedTerminal(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 arraySize,
      char attrVal[]);

   int32 __stdcall RFmxInstr_SetTriggerExportOutputTerminal(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      char attrVal[]);

   int32 __stdcall RFmxInstr_GetTriggerExportOutputTerminal(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 arraySize,
      char attrVal[]);

   int32 __stdcall RFmxInstr_GetTriggerTerminalName(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 arraySize,
      char attrVal[]);

   int32 __stdcall RFmxInstr_SetCleanerSpectrum(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attrVal);

   int32 __stdcall RFmxInstr_GetCleanerSpectrum(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 *attrVal);

   int32 __stdcall RFmxInstr_GetRecommendedAcquisitionType(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 *attrVal);

   int32 __stdcall RFmxInstr_GetRecommendedNumberOfRecords(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 *attrVal);

   int32 __stdcall RFmxInstr_GetRecommendedTriggerMinimumQuietTime(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_GetRecommendedIQAcquisitionTime(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_GetRecommendedIQMinimumSampleRate(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_GetRecommendedIQPreTriggerTime(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_GetRecommendedSpectralAcquisitionSpan(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_GetRecommendedSpectralFFTWindow(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 *attrVal);

   int32 __stdcall RFmxInstr_GetRecommendedSpectralResolutionBandwidth(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_GetRecommendedCenterFrequency(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_SetIFFilterBandwidth(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 attrVal);

   int32 __stdcall RFmxInstr_GetIFFilterBandwidth(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_SetSubSpanOverlap(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 attrVal);

   int32 __stdcall RFmxInstr_GetSubSpanOverlap(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_GetDownconverterGain(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_SetDownconverterFrequencyOffset(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 attrVal
   );

   int32 __stdcall RFmxInstr_GetDownconverterFrequencyOffset(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal
   );

   int32 __stdcall RFmxInstr_SetRFAttenuationStepSize(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 attrVal
   );

   int32 __stdcall RFmxInstr_GetRFAttenuationStepSize(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal
   );

   int32 __stdcall RFmxInstr_SetAmplitudeSettling(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 attrVal
   );

   int32 __stdcall RFmxInstr_GetAmplitudeSettling(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal
   );

   int32 __stdcall RFmxInstr_SetLOLeakageAvoidanceEnabled(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attrVal
   );

   int32 __stdcall RFmxInstr_GetLOLeakageAvoidanceEnabled(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 *attrVal
   );

   int32 __stdcall RFmxInstr_SetCommonModeLevel(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 attrVal
   );

   int32 __stdcall RFmxInstr_GetCommonModeLevel(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal
   );

   int32 __stdcall RFmxInstr_SetSMUResourceName(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_GetSMUResourceName(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 arraySize,
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_SetSMUChannel(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_GetSMUChannel(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 arraySize,
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_GetSelfCalibrationValidityCheck(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 *attrVal
   );

   int32 __stdcall RFmxInstr_SetSelfCalibrationValidityCheck(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 attrVal
   );

   int32 __stdcall RFmxInstr_GetSelfCalibrationValidityCheckTimeInterval(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      float64 *attrVal
   );

   int32 __stdcall RFmxInstr_SetSelfCalibrationValidityCheckTimeInterval(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      float64 attrVal
   );

   int32 __stdcall RFmxInstr_SetOverflowErrorReporting(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attrVal
   );

   int32 __stdcall RFmxInstr_GetOverflowErrorReporting(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 *attrVal
   );

   int32 __stdcall RFmxInstr_SetLOInPower(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 attrVal);

   int32 __stdcall RFmxInstr_GetLOInPower(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_SetLOOutPower(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 attrVal);

   int32 __stdcall RFmxInstr_GetLOOutPower(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal);

   int32 __stdcall RFmxInstr_SetLOPLLFractionalMode(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attrVal
   );

   int32 __stdcall RFmxInstr_GetLOPLLFractionalMode(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 *attrVal
   );

   int32 __stdcall RFmxInstr_SetOptimizePathForSignalBandwidth(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attrVal);

   int32 __stdcall RFmxInstr_GetOptimizePathForSignalBandwidth(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 *attrVal);

   int32 __stdcall RFmxInstr_SetInputIsolationEnabled(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 attrVal);

   int32 __stdcall RFmxInstr_GetInputIsolationEnabled(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      int32 *attrVal);

   int32 __stdcall RFmxInstr_GetLOVCOFrequencyStepSize(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      float64 *attrVal
   );

   int32 __stdcall RFmxInstr_SetLOVCOFrequencyStepSize(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      float64 attrVal
   );

   int32 __stdcall RFmxInstr_GetThermalCorrectionHeadroomRange(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      float64 *attrVal
   );

   int32 __stdcall RFmxInstr_SetThermalCorrectionHeadroomRange(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      float64 attrVal
   );

   int32 __stdcall RFmxInstr_GetLOFrequencyStepSize(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      float64 *attrVal
   );

   int32 __stdcall RFmxInstr_SetLOFrequencyStepSize(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      float64 attrVal
   );
   int32 __stdcall RFmxInstr_GetRFHighpassFilterFrequency(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      float64 *attrVal
   );

   int32 __stdcall RFmxInstr_SetRFHighpassFilterFrequency(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      float64 attrVal
   );

   int32 __stdcall RFmxInstr_GetStartTriggerType(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 *attrVal
   );

   int32 __stdcall RFmxInstr_SetStartTriggerType(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 attrVal
   );

   int32 __stdcall RFmxInstr_GetStartTriggerDigitalEdgeSource(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 arraySize,
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_SetStartTriggerDigitalEdgeSource(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_GetStartTriggerDigitalEdge(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 *attrVal
   );

   int32 __stdcall RFmxInstr_SetStartTriggerDigitalEdge(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 attrVal
   );

   int32 __stdcall RFmxInstr_GetStartTriggerExportOutputTerminal(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 arraySize,
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_SetStartTriggerExportOutputTerminal(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_GetStartTriggerTerminalName(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 arraySize,
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_GetAdvanceTriggerType(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 *attrVal
   );

   int32 __stdcall RFmxInstr_SetAdvanceTriggerType(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 attrVal
   );

   int32 __stdcall RFmxInstr_GetAdvanceTriggerDigitalEdgeSource(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 arraySize,
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_SetAdvanceTriggerDigitalEdgeSource(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_GetAdvanceTriggerExportOutputTerminal(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 arraySize,
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_SetAdvanceTriggerExportOutputTerminal(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_GetAdvanceTriggerTerminalName(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 arraySize,
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_GetReadyForStartEventOutputTerminal(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 arraySize,
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_SetReadyForStartEventOutputTerminal(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_GetReadyForStartEventTerminalName(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 arraySize,
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_GetReadyForAdvanceEventOutputTerminal(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 arraySize,
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_SetReadyForAdvanceEventOutputTerminal(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_GetReadyForAdvanceEventTerminalName(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 arraySize,
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_GetReadyForReferenceEventOutputTerminal(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 arraySize,
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_SetReadyForReferenceEventOutputTerminal(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_GetReadyForReferenceEventTerminalName(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 arraySize,
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_GetEndOfRecordEventOutputTerminal(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 arraySize,
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_SetEndOfRecordEventOutputTerminal(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_GetEndOfRecordEventTerminalName(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 arraySize,
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_GetDoneEventOutputTerminal(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 arraySize,
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_SetDoneEventOutputTerminal(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_GetDoneEventTerminalName(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 arraySize,
      char attrVal[]
   );

   int32 __stdcall RFmxInstr_GetTemperatureReadInterval(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      float64 *attrVal
   );

   int32 __stdcall RFmxInstr_SetTemperatureReadInterval(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      float64 attrVal
   );

   int32 __stdcall RFmxInstr_GetThermalCorrectionTemperatureResolution(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      float64 *attrVal
   );

   int32 __stdcall RFmxInstr_SetThermalCorrectionTemperatureResolution(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      float64 attrVal
   );

   int32 __stdcall RFmxInstr_GetSParameterExternalAttenuationType(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32* sParameterType
   );

   int32 __stdcall RFmxInstr_GetLOSharingMode(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 *attrVal
   );

   int32 __stdcall RFmxInstr_SetLOSharingMode(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 attrVal
   );

   int32 __stdcall RFmxInstr_GetNumberOfLOSharingGroups(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 *attrVal
   );

   int32 __stdcall RFmxInstr_SetNumberOfLOSharingGroups(
      niRFmxInstrHandle instrumentHandle,
      char selectorString[],
      int32 attrVal
   );

#ifdef __cplusplus
}
#endif

/* ---------------- Obsolete Section ------------------ */

#define RFMXINSTR_ATTR_RECOMMENDED_IQ_MEASUREMENT_BANDWIDTH                0x00000033
#define RFMXINSTR_ATTR_AUTOMATIC_SG_SA_SHARED_LO                           0x0000004a

/* -- Values for Automatic SG SA Shared LO -- */

#define RFMXINSTR_VAL_AUTOMATIC_SG_SA_SHARED_LO_DISABLED                   0
#define RFMXINSTR_VAL_AUTOMATIC_SG_SA_SHARED_LO_ENABLED                    1

#ifdef __cplusplus
extern "C"
{
#endif

   int32 __stdcall RFmxInstr_GetRecommendedIQMeasurementBandwidth(
      niRFmxInstrHandle instrumentHandle,
      char channelName[],
      float64 *attrVal
   );

   int32 __stdcall RFmxInstr_BuildPortString(
      char selectorString[],
      char portName[],
      int32 selectorStringOutLength,
      char selectorStringOut[]
   );

   int32 __stdcall RFmxInstr_CfgAutomaticSGSASharedLO(
       niRFmxInstrHandle instrumentHandle,
       char selectorString[],
       int32 automaticSGSASharedLO
   );

   int32 __stdcall RFmxInstr_GetAutomaticSGSASharedLO(
       niRFmxInstrHandle instrumentHandle,
       char channelName[],
       int32* attrVal
   );

   int32 __stdcall RFmxInstr_SetAutomaticSGSASharedLO(
       niRFmxInstrHandle instrumentHandle,
       char channelName[],
       int32 attrVal
   );

#ifdef __cplusplus
}
#endif

#endif   /*__NI_RFMX_INSTR_H__*/
