/****************************************************************************
 *    NI-FGEN Instrument Driver for National Instruments Signal Generators
 *---------------------------------------------------------------------------
 *   Copyright (c) National Instruments 1998-2017.  All Rights Reserved.
 *---------------------------------------------------------------------------
 *
 * Title:    niFgen.h
 * Purpose:  NI-FGEN Instrument Driver for National Instruments Signal Generators
 *           declarations.
 *
 ****************************************************************************/

#ifndef __NIFGEN_HEADER
#define __NIFGEN_HEADER

/* Pragma used in CVI to indicate that functions in this file have
 * user protection associated with them */
#ifdef _CVI_
 #pragma EnableLibraryRuntimeChecking
#endif

#define IVI_DO_NOT_INCLUDE_VISA_HEADERS
#include "IviFgen.h"
#undef IVI_DO_NOT_INCLUDE_VISA_HEADERS

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

/****************************************************************************
 *----------------- Instrument Driver Revision Information -----------------*
 ****************************************************************************/
#define NIFGEN_MAJOR_VERSION       17    /* Instrument driver major version */
#define NIFGEN_MINOR_VERSION       800   /* Instrument driver minor version */

/****************************************************************************
 *---------------------------- Attribute Defines ---------------------------*
 ****************************************************************************/

/*--------------- Output Attributes ----------------------------------------*/

#define NIFGEN_ATTR_OUTPUT_MODE                              IVIFGEN_ATTR_OUTPUT_MODE              /* ViInt32   */
#define NIFGEN_ATTR_OUTPUT_ENABLED                           IVIFGEN_ATTR_OUTPUT_ENABLED           /* ViBoolean, multi-channel */
#define NIFGEN_ATTR_DIGITAL_GAIN                            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 254L) /* ViReal64  */
#define NIFGEN_ATTR_ANALOG_PATH                             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 222L) /* ViInt32   */
#define NIFGEN_ATTR_LOAD_IMPEDANCE                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 220L) /* ViReal64  */
#define NIFGEN_ATTR_OUTPUT_IMPEDANCE                         IVIFGEN_ATTR_OUTPUT_IMPEDANCE         /* ViReal64,  multi-channel, ohms */
#define NIFGEN_ATTR_TERMINAL_CONFIGURATION                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 365L) /* ViInt32   */
#define NIFGEN_ATTR_COMMON_MODE_OFFSET                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 366L) /* ViReal64  */
#define NIFGEN_ATTR_CHANNEL_DELAY                           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 369L) /* ViReal64  */
#define NIFGEN_ATTR_ABSOLUTE_DELAY                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 413L) /* ViReal64 */

/*- Filter -----------------------------------------------------------------*/
#define NIFGEN_ATTR_ANALOG_FILTER_ENABLED                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 103L) /* ViBoolean */
#define NIFGEN_ATTR_DIGITAL_FILTER_ENABLED                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 102L) /* ViBoolean */
#define NIFGEN_ATTR_DIGITAL_FILTER_INTERPOLATION_FACTOR     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 218L) /* ViReal64  */
#define NIFGEN_ATTR_FLATNESS_CORRECTION_ENABLED             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 323L) /* ViBoolean */

/*- Data Mask --------------------------------------------------------------*/
#define NIFGEN_ATTR_ANALOG_DATA_MASK                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 234L) /* ViInt32 */
#define NIFGEN_ATTR_ANALOG_STATIC_VALUE                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 235L) /* ViInt32 */
#define NIFGEN_ATTR_DIGITAL_DATA_MASK                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 236L) /* ViInt32 */
#define NIFGEN_ATTR_DIGITAL_STATIC_VALUE                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 237L) /* ViInt32 */

/*- Advanced Output Attributes ---------------------------------------------*/
#define NIFGEN_ATTR_DIGITAL_PATTERN_ENABLED                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 101L) /* ViBoolean */
#define NIFGEN_ATTR_AUX_POWER_ENABLED                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 411L) /* ViBoolean */
#define NIFGEN_ATTR_IDLE_BEHAVIOR                           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 377L) /* ViInt32 */
#define NIFGEN_ATTR_IDLE_VALUE                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 378L) /* ViInt32 */
#define NIFGEN_ATTR_WAIT_BEHAVIOR                           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 379L) /* ViInt32 */
#define NIFGEN_ATTR_WAIT_VALUE                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 380L) /* ViInt32 */


/*----------------------------- Arbitrary Waveform -------------------------*/

#define NIFGEN_ATTR_ARB_GAIN                                 IVIFGEN_ATTR_ARB_GAIN                 /* ViReal64, multi-channel        */
#define NIFGEN_ATTR_ARB_OFFSET                               IVIFGEN_ATTR_ARB_OFFSET               /* ViReal64, multi-channel, volts */
#define NIFGEN_ATTR_WAVEFORM_QUANTUM                         IVIFGEN_ATTR_WAVEFORM_QUANTUM         /* ViInt32,  read-only, samples   */
#define NIFGEN_ATTR_MAX_NUM_WAVEFORMS                        IVIFGEN_ATTR_MAX_NUM_WAVEFORMS        /* ViInt32,  read-only            */
#define NIFGEN_ATTR_MIN_WAVEFORM_SIZE                        IVIFGEN_ATTR_MIN_WAVEFORM_SIZE        /* ViInt32,  read-only, samples   */
#define NIFGEN_ATTR_MAX_WAVEFORM_SIZE                        IVIFGEN_ATTR_MAX_WAVEFORM_SIZE        /* ViInt32,  read-only, samples   */

/*- Arbitrary Waveform Generation ------------------------------------------*/
#define NIFGEN_ATTR_ARB_WAVEFORM_HANDLE                      IVIFGEN_ATTR_ARB_WAVEFORM_HANDLE  /* ViInt32,  multi-channel        */
#define NIFGEN_ATTR_ARB_MARKER_POSITION                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 327L) /* ViInt32,  readwrite, samples   */
#define NIFGEN_ATTR_ARB_REPEAT_COUNT                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 328L) /* ViInt32,  readwrite            */

/*- Arbitrary Sequence Generation ------------------------------------------*/
#define NIFGEN_ATTR_ARB_SEQUENCE_HANDLE                      IVIFGEN_ATTR_ARB_SEQUENCE_HANDLE /* ViInt32,  multi-channel        */
#define NIFGEN_ATTR_MAX_NUM_SEQUENCES                        IVIFGEN_ATTR_MAX_NUM_SEQUENCES   /* ViInt32,  read-only            */
#define NIFGEN_ATTR_MIN_SEQUENCE_LENGTH                      IVIFGEN_ATTR_MIN_SEQUENCE_LENGTH /* ViInt32,  read-only            */
#define NIFGEN_ATTR_MAX_SEQUENCE_LENGTH                      IVIFGEN_ATTR_MAX_SEQUENCE_LENGTH /* ViInt32,  read-only            */
#define NIFGEN_ATTR_MAX_LOOP_COUNT                           IVIFGEN_ATTR_MAX_LOOP_COUNT      /* ViInt32,  read-only            */

/*- Script Generation ------------------------------------------------------*/
#define NIFGEN_ATTR_SCRIPT_TO_GENERATE                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 270L)  /* ViString */

/*- Data Transfer ----------------------------------------------------------*/
#define NIFGEN_ATTR_FILE_TRANSFER_BLOCK_SIZE                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 240L)  /* ViInt32, samples */
#define NIFGEN_ATTR_DATA_TRANSFER_BLOCK_SIZE                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 241L)  /* ViInt32, samples */
#define NIFGEN_ATTR_DATA_TRANSFER_MAXIMUM_BANDWIDTH         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 373L)  /* ViReal64 */
/*- Direct DMA -------------------------------------------------------------*/
#define NIFGEN_ATTR_DIRECT_DMA_ENABLED                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 244L)  /* ViBoolean */
#define NIFGEN_ATTR_DIRECT_DMA_WINDOW_SIZE                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 245L)  /* ViInt32, bytes */
#define NIFGEN_ATTR_DIRECT_DMA_WINDOW_ADDRESS               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 274L)  /* ViInt32 */
/*- Streaming --------------------------------------------------------------*/
#define NIFGEN_ATTR_STREAMING_WAVEFORM_NAME                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 326L)  /* ViString */
#define NIFGEN_ATTR_STREAMING_WAVEFORM_HANDLE               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 324L)  /* ViInt32  */
#define NIFGEN_ATTR_STREAMING_SPACE_AVAILABLE_IN_WAVEFORM   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 325L)  /* ViInt32  */
#define NIFGEN_ATTR_STREAMING_WRITE_TIMEOUT                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 409L)  /* ViReal64 */
/*- Advanced Data Transfer -------------------------------------------------*/
#define NIFGEN_ATTR_DATA_TRANSFER_PREFERRED_PACKET_SIZE     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 374L)  /* ViInt32  */
#define NIFGEN_ATTR_DATA_TRANSFER_MAXIMUM_IN_FLIGHT_READS   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 375L)  /* ViInt32  */
#define NIFGEN_ATTR_PCI_DMA_OPTIMIZATIONS_ENABLED           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 362L)  /* ViBoolean */

/*- Onboard Signal Processing-------------------------------------------*/
#define NIFGEN_ATTR_OSP_ENABLED                             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 246L) /* ViBoolean */
#define NIFGEN_ATTR_OSP_IQ_RATE                             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 248L) /* ViReal64  */
#define NIFGEN_ATTR_OSP_DATA_PROCESSING_MODE                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 247L) /* ViInt32   */
#define NIFGEN_ATTR_OSP_MODE                                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 370L) /* ViInt32   */
#define NIFGEN_ATTR_OSP_FREQUENCY_SHIFT                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 371L) /* ViReal64  */
#define NIFGEN_ATTR_OSP_CARRIER_ENABLED                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 249L) /* ViBoolean */
#define NIFGEN_ATTR_OSP_CARRIER_FREQUENCY                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 250L) /* ViReal64  */
#define NIFGEN_ATTR_OSP_CARRIER_PHASE_I                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 251L) /* ViReal64  */
#define NIFGEN_ATTR_OSP_CARRIER_PHASE_Q                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 252L) /* ViReal64  */
#define NIFGEN_ATTR_OSP_COMPENSATE_FOR_FILTER_GROUP_DELAY   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 389L) /* ViBoolean  */
#define NIFGEN_ATTR_OSP_FIR_FILTER_TYPE                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 253L) /* ViInt32   */
#define NIFGEN_ATTR_OSP_FIR_FILTER_ENABLED                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 255L) /* ViBoolean */
#define NIFGEN_ATTR_OSP_FIR_FILTER_INTERPOLATION            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 256L) /* ViReal64  */
#define NIFGEN_ATTR_OSP_CIC_FILTER_ENABLED                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 257L) /* ViBoolean */
#define NIFGEN_ATTR_OSP_CIC_FILTER_INTERPOLATION            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 258L) /* ViReal64  */
#define NIFGEN_ATTR_OSP_FIR_FILTER_ROOT_RAISED_COSINE_ALPHA (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 259L) /* ViReal64  */
#define NIFGEN_ATTR_OSP_FIR_FILTER_RAISED_COSINE_ALPHA      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 260L) /* ViReal64  */
#define NIFGEN_ATTR_OSP_FIR_FILTER_FLAT_PASSBAND            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 261L) /* ViReal64  */
#define NIFGEN_ATTR_OSP_FIR_FILTER_GAUSSIAN_BT              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 262L) /* ViReal64  */
#define NIFGEN_ATTR_OSP_CIC_FILTER_GAIN                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 263L) /* ViReal64  */
#define NIFGEN_ATTR_OSP_PRE_FILTER_GAIN_I                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 264L) /* ViReal64  */
#define NIFGEN_ATTR_OSP_PRE_FILTER_GAIN_Q                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 265L) /* ViReal64  */
#define NIFGEN_ATTR_OSP_PRE_FILTER_OFFSET_I                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 266L) /* ViReal64  */
#define NIFGEN_ATTR_OSP_PRE_FILTER_OFFSET_Q                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 267L) /* ViReal64  */
#define NIFGEN_ATTR_OSP_OVERFLOW_ERROR_REPORTING            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 268L) /* ViInt32   */
#define NIFGEN_ATTR_OSP_OVERFLOW_STATUS                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 269L) /* ViInt32   */

/*- Peer-to-Peer (P2P)-------------------------------------------*/
#define NIFGEN_ATTR_P2P_ENABLED                                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 391L) /* ViBoolean  */
#define NIFGEN_ATTR_P2P_DESTINATION_CHANNELS                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 392L) /* ViString */
#define NIFGEN_ATTR_P2P_ENDPOINT_SIZE                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 393L) /* ViInt32 */
#define NIFGEN_ATTR_P2P_SPACE_AVAILABLE_IN_ENDPOINT                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 394L) /* ViInt32 */
#define NIFGEN_ATTR_P2P_MOST_SPACE_AVAILABLE_IN_ENDPOINT           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 395L) /* ViInt32 */
#define NIFGEN_ATTR_P2P_ENDPOINT_COUNT                             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 396L) /* ViInt32 */
#define NIFGEN_ATTR_P2P_DATA_TRANSFER_PERMISSION_INTERVAL          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 400L) /* ViInt32 */
#define NIFGEN_ATTR_P2P_DATA_TRANSFER_PERMISSION_INITIAL_CREDITS   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 408L) /* ViInt32 */


/*- Peer-to-Peer (P2P) ADVANCED -------------------------------------------*/
#define NIFGEN_ATTR_P2P_MANUAL_CONFIGURATION_ENABLED           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 397L) /* ViBoolean */

/*- Peer-to-Peer (P2P) ADVANCED CONFIGURATION-------------------------------------------*/
#define NIFGEN_ATTR_P2P_DATA_TRANSFER_PERMISSION_ADDRESS       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 398L) /* ViInt64 */
#define NIFGEN_ATTR_P2P_DATA_TRANSFER_PERMISSION_ADDRESS_TYPE  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 399L) /* ViInt32 */
#define NIFGEN_ATTR_P2P_ENDPOINT_WINDOW_ADDRESS                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 401L) /* ViInt64 */
#define NIFGEN_ATTR_P2P_ENDPOINT_WINDOW_ADDRESS_TYPE           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 402L) /* ViInt32 */
#define NIFGEN_ATTR_P2P_ENDPOINT_WINDOW_SIZE                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 403L) /* ViInt32 */
#define NIFGEN_ATTR_P2P_ENDPOINT_FULLNESS_START_TRIGGER_LEVEL  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 410L) /* ViInt32 */

/*- Peer-to-Peer (P2P) ADVANCED STATUS NOTIFICATION-------------------------------------------*/
#define NIFGEN_ATTR_P2P_DONE_NOTIFICATION_ADDRESS              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 405L) /* ViInt64 */
#define NIFGEN_ATTR_P2P_DONE_NOTIFICATION_ADDRESS_TYPE         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 406L) /* ViInt32 */
#define NIFGEN_ATTR_P2P_DONE_NOTIFICATION_VALUE                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 407L) /* ViInt32 */


/*---------------------------- Standard Function --------------------------*/

#define NIFGEN_ATTR_FUNC_WAVEFORM                            IVIFGEN_ATTR_FUNC_WAVEFORM            /* ViInt32,  multi-channel        */
#define NIFGEN_ATTR_FUNC_AMPLITUDE                           IVIFGEN_ATTR_FUNC_AMPLITUDE           /* ViReal64, multi-channel, volts */
#define NIFGEN_ATTR_FUNC_DC_OFFSET                           IVIFGEN_ATTR_FUNC_DC_OFFSET           /* ViReal64, multi-channel, volts */
#define NIFGEN_ATTR_FUNC_START_PHASE                         IVIFGEN_ATTR_FUNC_START_PHASE         /* ViReal64, multi-channel, deg   */
#define NIFGEN_ATTR_FUNC_DUTY_CYCLE_HIGH                     IVIFGEN_ATTR_FUNC_DUTY_CYCLE_HIGH     /* ViReal64, multi-channel, pct   */
#define NIFGEN_ATTR_SYNC_DUTY_CYCLE_HIGH                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 105L) /* ViReal64 */
#define NIFGEN_ATTR_SYNC_OUT_OUTPUT_TERMINAL                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 330L) /* ViString */

/*- Standard Waveform Generation -------------------------------------------*/
#define NIFGEN_ATTR_FUNC_FREQUENCY                           IVIFGEN_ATTR_FUNC_FREQUENCY           /* ViReal64, multi-channel, hertz */
#define NIFGEN_ATTR_FUNC_BUFFER_SIZE                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 238L) /* ViInt32,  read-only, samples   */
#define NIFGEN_ATTR_FUNC_MAX_BUFFER_SIZE                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 239L) /* ViInt32,  multi-channel        */

/*- Frequency List Generation ------------------------------------------*/
#define NIFGEN_ATTR_FREQ_LIST_HANDLE                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 208L) /* ViInt32,  multi-channel */
#define NIFGEN_ATTR_MAX_NUM_FREQ_LISTS                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 209L) /* ViInt32,  read-only     */
#define NIFGEN_ATTR_MIN_FREQ_LIST_LENGTH                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 210L) /* ViInt32,  read-only     */
#define NIFGEN_ATTR_MAX_FREQ_LIST_LENGTH                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 211L) /* ViInt32,  read-only     */
#define NIFGEN_ATTR_MIN_FREQ_LIST_DURATION                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 212L) /* ViReal64, read-only     */
#define NIFGEN_ATTR_MAX_FREQ_LIST_DURATION                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 213L) /* ViReal64, read-only     */
#define NIFGEN_ATTR_FREQ_LIST_DURATION_QUANTUM              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 214L) /* ViReal64, read-only     */


/*-------------------------------- Clocks ----------------------------------*/

/*- Reference Clock --------------------------------------------------------*/
#define NIFGEN_ATTR_REFERENCE_CLOCK_SOURCE                           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 113L) /* ViString */
#define NIFGEN_ATTR_REF_CLOCK_FREQUENCY                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 107L) /* ViReal64 */
#define NIFGEN_ATTR_EXPORTED_REFERENCE_CLOCK_OUTPUT_TERMINAL         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 321L) /* ViString */
#define NIFGEN_ATTR_EXPORTED_ONBOARD_REFERENCE_CLOCK_OUTPUT_TERMINAL (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 322L) /* ViString */

/*- Sample Clock -----------------------------------------------------------*/
#define NIFGEN_ATTR_ARB_SAMPLE_RATE                                 IVIFGEN_ATTR_ARB_SAMPLE_RATE          /* ViReal64, samples-per-second */
#define NIFGEN_ATTR_CLOCK_MODE                                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 110L) /* ViInt32 */
#define NIFGEN_ATTR_SAMPLE_CLOCK_SOURCE                            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 112L) /* ViString */
#define NIFGEN_ATTR_EXPORTED_SAMPLE_CLOCK_OUTPUT_TERMINAL          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 320L) /* ViString */
#define NIFGEN_ATTR_EXPORTED_SAMPLE_CLOCK_DIVISOR                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 219L) /* ViInt32  */

/*- Sample Clock Timebase --------------------------------------------------*/
#define NIFGEN_ATTR_SAMPLE_CLOCK_TIMEBASE_SOURCE                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 367L) /* ViString */
#define NIFGEN_ATTR_SAMPLE_CLOCK_TIMEBASE_RATE                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 368L) /* ViReal64 */
#define NIFGEN_ATTR_EXPORTED_SAMPLE_CLOCK_TIMEBASE_OUTPUT_TERMINAL (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 329L) /* ViString */
#define NIFGEN_ATTR_EXPORTED_SAMPLE_CLOCK_TIMEBASE_DIVISOR         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 230L) /* ViInt32  */

/*- Advanced Clock Attributes ----------------------------------------------*/
#define NIFGEN_ATTR_EXTERNAL_SAMPLE_CLOCK_MULTIPLIER           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 376L)   /* ViReal64 */
#define NIFGEN_ATTR_SAMPLE_CLOCK_ABSOLUTE_DELAY                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 231L)   /* ViReal64 */
#define NIFGEN_ATTR_OSCILLATOR_PHASE_DAC_VALUE                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 232L) /* ViInt32  */
#define NIFGEN_ATTR_EXTERNAL_CLOCK_DELAY_BINARY_VALUE          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 233L) /* ViInt32  */


/*--------------------------  Events  --------------------------------------*/

/*- Marker Event -------------------------------------------------------*/
#define NIFGEN_ATTR_MARKER_EVENT_OUTPUT_TERMINAL               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 312L)   /* ViString  */
#define NIFGEN_ATTR_MARKER_EVENT_OUTPUT_BEHAVIOR               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 342L)   /* ViInt32   */
#define NIFGEN_ATTR_MARKER_EVENT_PULSE_POLARITY                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 313L)   /* ViInt32   */
#define NIFGEN_ATTR_MARKER_EVENT_PULSE_WIDTH                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 340L)   /* ViReal64  */
#define NIFGEN_ATTR_MARKER_EVENT_PULSE_WIDTH_UNITS             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 341L)   /* ViInt32   */
#define NIFGEN_ATTR_MARKER_EVENT_TOGGLE_INITIAL_STATE          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 343L)   /* ViInt32   */
#define NIFGEN_ATTR_MARKER_EVENT_DELAY                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 354L)   /* ViReal64  */
#define NIFGEN_ATTR_MARKER_EVENT_DELAY_UNITS                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 355L)   /* ViInt32   */
#define NIFGEN_ATTR_ALL_MARKER_EVENTS_LIVE_STATUS              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 344L)   /* ViInt32   */
#define NIFGEN_ATTR_MARKER_EVENT_LIVE_STATUS                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 345L)   /* ViBoolean */
#define NIFGEN_ATTR_ALL_MARKER_EVENTS_LATCHED_STATUS           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 349L)   /* ViInt32   */
#define NIFGEN_ATTR_MARKER_EVENT_LATCHED_STATUS                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 350L)   /* ViBoolean */

/*- Data Marker Event --------------------------------------------------*/
#define NIFGEN_ATTR_DATA_MARKER_EVENT_DATA_BIT_NUMBER          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 337L)   /* ViInt32  */
#define NIFGEN_ATTR_DATA_MARKER_EVENT_LEVEL_POLARITY           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 338L)   /* ViInt32  */
#define NIFGEN_ATTR_DATA_MARKER_EVENT_OUTPUT_TERMINAL          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 339L)   /* ViString */

/*- Ready For Start Event ----------------------------------------------*/
#define NIFGEN_ATTR_READY_FOR_START_EVENT_OUTPUT_TERMINAL      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 310L)   /* ViString  */
#define NIFGEN_ATTR_READY_FOR_START_EVENT_LEVEL_ACTIVE_LEVEL   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 311L)   /* ViInt32   */
#define NIFGEN_ATTR_READY_FOR_START_EVENT_LIVE_STATUS          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 348L)   /* ViBoolean */

/*- Started Event ------------------------------------------------------*/
#define NIFGEN_ATTR_STARTED_EVENT_OUTPUT_TERMINAL              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 314L) /* ViString */
#define NIFGEN_ATTR_STARTED_EVENT_OUTPUT_BEHAVIOR              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 331L) /* ViInt32  */
#define NIFGEN_ATTR_STARTED_EVENT_LEVEL_ACTIVE_LEVEL           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 316L) /* ViInt32  */
#define NIFGEN_ATTR_STARTED_EVENT_PULSE_POLARITY               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 318L) /* ViInt32  */
#define NIFGEN_ATTR_STARTED_EVENT_PULSE_WIDTH_UNITS            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 333L) /* ViInt32  */
#define NIFGEN_ATTR_STARTED_EVENT_PULSE_WIDTH                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 335L) /* ViReal64 */
#define NIFGEN_ATTR_STARTED_EVENT_DELAY                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 356L) /* ViReal64 */
#define NIFGEN_ATTR_STARTED_EVENT_DELAY_UNITS                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 357L) /* ViInt32  */
#define NIFGEN_ATTR_STARTED_EVENT_LATCHED_STATUS               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 352L) /* ViBoolean */

/*- Done Event ---------------------------------------------------------*/
#define NIFGEN_ATTR_DONE_EVENT_OUTPUT_TERMINAL                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 315L) /* ViString */
#define NIFGEN_ATTR_DONE_EVENT_OUTPUT_BEHAVIOR                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 332L) /* ViInt32  */
#define NIFGEN_ATTR_DONE_EVENT_LEVEL_ACTIVE_LEVEL              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 317L) /* ViInt32  */
#define NIFGEN_ATTR_DONE_EVENT_PULSE_POLARITY                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 319L) /* ViInt32  */
#define NIFGEN_ATTR_DONE_EVENT_PULSE_WIDTH_UNITS               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 334L) /* ViInt32  */
#define NIFGEN_ATTR_DONE_EVENT_PULSE_WIDTH                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 336L) /* ViReal64 */
#define NIFGEN_ATTR_DONE_EVENT_DELAY                           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 358L) /* ViReal64 */
#define NIFGEN_ATTR_DONE_EVENT_DELAY_UNITS                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 359L) /* ViInt32  */
#define NIFGEN_ATTR_DONE_EVENT_LATCHED_STATUS                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 351L) /* ViBoolean */


/*----------------------- Triggers -------------------------------------*/

#define NIFGEN_ATTR_TRIGGER_MODE                               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 108L) /* ViInt32 */
#define NIFGEN_ATTR_BURST_COUNT                                 IVIFGEN_ATTR_BURST_COUNT              /* ViInt32, multi-channel */

/*- Start Trigger ------------------------------------------------------*/
#define NIFGEN_ATTR_START_TRIGGER_TYPE                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 280L) /* ViInt32  */
#define NIFGEN_ATTR_DIGITAL_EDGE_START_TRIGGER_SOURCE          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 281L) /* ViString */
#define NIFGEN_ATTR_DIGITAL_EDGE_START_TRIGGER_EDGE            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 282L) /* ViInt32  */
#define NIFGEN_ATTR_EXPORTED_START_TRIGGER_OUTPUT_TERMINAL     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 283L) /* ViString */

/*- Script Trigger -----------------------------------------------------*/
#define NIFGEN_ATTR_SCRIPT_TRIGGER_TYPE                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 290L) /* ViInt32  */
#define NIFGEN_ATTR_DIGITAL_EDGE_SCRIPT_TRIGGER_SOURCE         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 291L) /* ViString */
#define NIFGEN_ATTR_DIGITAL_EDGE_SCRIPT_TRIGGER_EDGE           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 292L) /* ViInt32  */
#define NIFGEN_ATTR_DIGITAL_LEVEL_SCRIPT_TRIGGER_SOURCE        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 293L) /* ViString */
#define NIFGEN_ATTR_DIGITAL_LEVEL_SCRIPT_TRIGGER_ACTIVE_LEVEL  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 294L) /* ViInt32  */
#define NIFGEN_ATTR_EXPORTED_SCRIPT_TRIGGER_OUTPUT_TERMINAL    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 295L) /* ViString */

/*------------------ Instrument Specific Attributes --------------------*/

#define NIFGEN_ATTR_BUS_TYPE                                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 215L) /* ViInt32,  read-only */
#define NIFGEN_ATTR_MEMORY_SIZE                                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 242L) /* ViInt32,  read-only, bytes */
#define NIFGEN_ATTR_SERIAL_NUMBER                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 243L) /* ViString, read-only */
#define NIFGEN_ATTR_MARKER_EVENTS_COUNT                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 271L) /* ViInt32,  Read-only */
#define NIFGEN_ATTR_DATA_MARKER_EVENTS_COUNT                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 273L) /* ViInt32,  Read-only */
#define NIFGEN_ATTR_SCRIPT_TRIGGERS_COUNT                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 272L) /* ViInt32,  Read-only */
#define NIFGEN_ATTR_VIDEO_WAVEFORM_TYPE                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 216L) /* ViInt32             */
#define NIFGEN_ATTR_FPGA_BITFILE_PATH                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 412L) /* ViString, read-only */

/*- 5401/5411/5431 Attributes -------------------------------------------*/
#define NIFGEN_ATTR_FILTER_CORRECTION_FREQUENCY                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 104L) /* ViReal64                */
#define NIFGEN_ATTR_TRIGGER_SOURCE                              IVIFGEN_ATTR_TRIGGER_SOURCE           /* ViInt32, multi-channel */
#define NIFGEN_ATTR_SYNCHRONIZATION                            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 111L) /* ViInt32,  multi-channel */
#define NIFGEN_ATTR_ID_QUERY_RESPONSE                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1L)   /* ViString, read-only     */

/*-------------------- Calibration --------------------------------------*/
#define NIFGEN_ATTR_GAIN_DAC_VALUE                             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 223L) /* ViInt32  */
#define NIFGEN_ATTR_OFFSET_DAC_VALUE                           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 224L) /* ViInt32  */
#define NIFGEN_ATTR_OSCILLATOR_FREQ_DAC_VALUE                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 225L) /* ViInt32  */
#define NIFGEN_ATTR_CAL_ADC_INPUT                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 227L) /* ViInt32  */
#define NIFGEN_ATTR_PRE_AMPLIFIER_ATTENUATION                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 228L) /* ViReal64 */
#define NIFGEN_ATTR_POST_AMPLIFIER_ATTENUATION                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 229L) /* ViReal64 */

/*-------------- IVI Inherent Attributes -----------------------------------*/
/*- User Options */
#define NIFGEN_ATTR_CACHE                                     IVI_ATTR_CACHE                   /* ViBoolean */
#define NIFGEN_ATTR_RANGE_CHECK                               IVI_ATTR_RANGE_CHECK             /* ViBoolean */
#define NIFGEN_ATTR_QUERY_INSTRUMENT_STATUS                   IVI_ATTR_QUERY_INSTRUMENT_STATUS /* ViBoolean */
#define NIFGEN_ATTR_RECORD_COERCIONS                          IVI_ATTR_RECORD_COERCIONS        /* ViBoolean */
#define NIFGEN_ATTR_SIMULATE                                  IVI_ATTR_SIMULATE                /* ViBoolean */
#define NIFGEN_ATTR_INTERCHANGE_CHECK                         IVI_ATTR_INTERCHANGE_CHECK       /* ViBoolean */
/*- Driver Information, Read-only ------------------------------------------*/
#define NIFGEN_ATTR_SPECIFIC_DRIVER_DESCRIPTION               IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION              /* ViString */
#define NIFGEN_ATTR_SPECIFIC_DRIVER_PREFIX                    IVI_ATTR_SPECIFIC_DRIVER_PREFIX                   /* ViString */
#define NIFGEN_ATTR_SPECIFIC_DRIVER_VENDOR                    IVI_ATTR_SPECIFIC_DRIVER_VENDOR                   /* ViString */
#define NIFGEN_ATTR_SPECIFIC_DRIVER_REVISION                  IVI_ATTR_SPECIFIC_DRIVER_REVISION                 /* ViString */
#define NIFGEN_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION  IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION /* ViInt32  */
#define NIFGEN_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION  IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION /* ViInt32  */
/*- Driver Capabilities, Read-only -----------------------------------------*/
#define NIFGEN_ATTR_SUPPORTED_INSTRUMENT_MODELS              IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS /* ViString */
#define NIFGEN_ATTR_GROUP_CAPABILITIES                       IVI_ATTR_GROUP_CAPABILITIES          /* ViString */
#define NIFGEN_ATTR_CHANNEL_COUNT                            IVI_ATTR_CHANNEL_COUNT               /* ViInt32,  Read-only  */
/*- Instrument Information, Read-only --------------------------------------*/
#define NIFGEN_ATTR_INSTRUMENT_MANUFACTURER                  IVI_ATTR_INSTRUMENT_MANUFACTURER      /* ViString */
#define NIFGEN_ATTR_INSTRUMENT_MODEL                         IVI_ATTR_INSTRUMENT_MODEL             /* ViString */
#define NIFGEN_ATTR_INSTRUMENT_FIRMWARE_REVISION             IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION /* ViString */
#define NIFGEN_ATTR_MODULE_REVISION                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 390L)/* ViString */
/*- Advanced Session Information, read-only --------------------------------*/
#define NIFGEN_ATTR_IO_RESOURCE_DESCRIPTOR                   IVI_ATTR_IO_RESOURCE_DESCRIPTOR /* ViString */
#define NIFGEN_ATTR_LOGICAL_NAME                             IVI_ATTR_LOGICAL_NAME           /* ViString */
#define NIFGEN_ATTR_DRIVER_SETUP                             IVI_ATTR_DRIVER_SETUP           /* ViString */


/****************************************************************************
 *------------------------ Attribute Value Defines -------------------------*
 ****************************************************************************/

#define NIFGEN_VAL_TRIG_SRC_RANGE               (200L)
#define NIFGEN_VAL_CLK_SRC_BASE                 (IVIFGEN_VAL_CLK_SRC_SPECIFIC_EXT_BASE + NIFGEN_VAL_TRIG_SRC_RANGE)

/*- Defined value for NIFGEN_ATTR_OPERATION_MODE -----------------------*/
#define NIFGEN_VAL_OPERATE_CONTINUOUS           IVIFGEN_VAL_OPERATE_CONTINUOUS

/*- Defined values for attribute NIFGEN_ATTR_OUTPUT_MODE ---------------*/
#define NIFGEN_VAL_OUTPUT_FUNC                  IVIFGEN_VAL_OUTPUT_FUNC
#define NIFGEN_VAL_OUTPUT_ARB                   IVIFGEN_VAL_OUTPUT_ARB
#define NIFGEN_VAL_OUTPUT_SEQ                   IVIFGEN_VAL_OUTPUT_SEQ
#define NIFGEN_VAL_OUTPUT_FREQ_LIST             (101L)
#define NIFGEN_VAL_OUTPUT_SCRIPT                (102L)

/*- Defined values for attribute NIFGEN_ATTR_OUTPUT_IMPEDANCE ----------*/
#define NIFGEN_VAL_50_OHMS                      50.0
#define NIFGEN_VAL_75_OHMS                      75.0

/*- Defined values for attribute NIFGEN_ATTR_LOAD_IMPEDANCE ----------*/
#define NIFGEN_VAL_MATCHED_LOAD_IMPEDANCE       -1.0

/*- Defined values for attribute NIFGEN_ATTR_FUNC_WAVEFORM -------------*/
#define NIFGEN_VAL_WFM_SINE                     IVIFGEN_VAL_WFM_SINE
#define NIFGEN_VAL_WFM_SQUARE                   IVIFGEN_VAL_WFM_SQUARE
#define NIFGEN_VAL_WFM_TRIANGLE                 IVIFGEN_VAL_WFM_TRIANGLE
#define NIFGEN_VAL_WFM_RAMP_UP                  IVIFGEN_VAL_WFM_RAMP_UP
#define NIFGEN_VAL_WFM_RAMP_DOWN                IVIFGEN_VAL_WFM_RAMP_DOWN
#define NIFGEN_VAL_WFM_DC                       IVIFGEN_VAL_WFM_DC
#define NIFGEN_VAL_WFM_NOISE                    (101L)
#define NIFGEN_VAL_WFM_USER                     (102L)

/*- Defined values for attribute NIFGEN_ATTR_ARB_WAVEFORM_HANDLE ---------*/
#define NIFGEN_VAL_FIRST_WAVEFORM_HANDLE        (10000L)
#define NIFGEN_VAL_LAST_WAVEFORM_HANDLE         (NIFGEN_VAL_FIRST_WAVEFORM_HANDLE + 999L)
#define NIFGEN_VAL_NO_WAVEFORM                  (-1L)

/*- Defined values for attribute NIFGEN_ATTR_ARB_SEQUENCE_HANDLE --------*/
#define NIFGEN_VAL_FIRST_SEQUENCE_HANDLE        (100000L)
#define NIFGEN_VAL_LAST_SEQUENCE_HANDLE         (NIFGEN_VAL_FIRST_SEQUENCE_HANDLE + 9999L)
#define NIFGEN_VAL_NO_SEQUENCE                  (-1L)

/*- Defined values for attribute NIFGEN_ATTR_FREQ_LIST_HANDLE --------*/
#define NIFGEN_VAL_FIRST_FREQ_LIST_HANDLE       (200000L)
#define NIFGEN_VAL_LAST_FREQ_LIST_HANDLE        (NIFGEN_VAL_FIRST_FREQ_LIST_HANDLE + 9999L)
#define NIFGEN_VAL_NO_FREQ_LIST                 (-1L)

/*- Defined values for Arbitrary Waveform Handles ----------------------*/
#define NIFGEN_VAL_ALL_WAVEFORMS                IVIFGEN_VAL_ALL_WAVEFORMS
#define NIFGEN_VAL_ALL_SEQUENCES                IVIFGEN_VAL_ALL_SEQUENCES
#define NIFGEN_VAL_ALL_FLISTS                   (-1L)

/*- Defined values for atttribute NIFGEN_ATTR_BURST_COUNT ---------------*/
#define NIFGEN_VAL_GENERATE_CONTINUOUS          (-1L)

/*- Defined values for attribute NIFGEN_ATTR_TERMINAL_CONFIGURATION -----*/
#define NIFGEN_VAL_SINGLE_ENDED                 (300L)
#define NIFGEN_VAL_DIFFERENTIAL                 (301L)

/*- Defined values for Signal Values ---------------------------------*/
#define NIFGEN_VAL_MARKER_EVENT                                (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 1L)  /* ViInt32 */
#define NIFGEN_VAL_SYNC_OUT                                    (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 2L)  /* ViInt32 */
#define NIFGEN_VAL_ONBOARD_REFERENCE_CLOCK                     (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 19L) /* ViInt32 */
#define NIFGEN_VAL_START_TRIGGER                               (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 4L)  /* ViInt32 */
#define NIFGEN_VAL_SAMPLE_CLOCK_TIMEBASE                       (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 6L)
#define NIFGEN_VAL_SYNCHRONIZATION                             (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 7L)  /* ViInt32 */
#define NIFGEN_VAL_SAMPLE_CLOCK                                (101L)
#define NIFGEN_VAL_REFERENCE_CLOCK                             (102L)
#define NIFGEN_VAL_SCRIPT_TRIGGER                              (103L)
#define NIFGEN_VAL_READY_FOR_START_EVENT                       (105L)
#define NIFGEN_VAL_STARTED_EVENT                               (106L)
#define NIFGEN_VAL_DONE_EVENT                                  (107L)
#define NIFGEN_VAL_DATA_MARKER_EVENT                           (108L)

/*- Additional defined values for 5404 signal routing ----------------*/
#define NIFGEN_VAL_NONE                         (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 0L)
#define NIFGEN_VAL_MARKER                       (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 1L)
#define NIFGEN_VAL_OUT_START_TRIGGER            (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 4L)
#define NIFGEN_VAL_BOARD_CLOCK                  (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 6L)
#define NIFGEN_VAL_REF_OUT                      (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 8L)
#define NIFGEN_VAL_CLOCK_OUT                    (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 9L)
#define NIFGEN_VAL_RTSI_7                       (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 10L)
#define NIFGEN_VAL_PFI_0                        (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 11L)

/*- Defined values for Digital Edge ----------------------------------*/
#define NIFGEN_VAL_RISING_EDGE                                 (101L)
#define NIFGEN_VAL_FALLING_EDGE                                (102L)

/*- Defined values for Toggle ----------------------------------------*/
#define NIFGEN_VAL_HIGH                                        (101L)
#define NIFGEN_VAL_LOW                                         (102L)

/*- Defined values for Event polarity --------------------------------*/
#define NIFGEN_VAL_ACTIVE_HIGH                                 (101L)
#define NIFGEN_VAL_ACTIVE_LOW                                  (102L)

/*- Defined values for Output Behavior -------------------------------*/
#define NIFGEN_VAL_PULSE                                       (101L)
#define NIFGEN_VAL_LEVEL                                       (102L)
#define NIFGEN_VAL_TOGGLE                                      (103L)

/*- Defined values for Pulse Width & Delay ---------------------------*/
#define NIFGEN_VAL_SAMPLE_CLOCK_PERIODS                        (101L)
#define NIFGEN_VAL_SECONDS                                     (102L)

/*- Defined values for Triggers types --------------------------------*/
#define NIFGEN_VAL_TRIG_NONE                                   (101L)                                   /* ViInt32 */
#define NIFGEN_VAL_DIGITAL_EDGE                                (102L)                                   /* ViInt32 */
#define NIFGEN_VAL_DIGITAL_LEVEL                               (103L)                                   /* ViInt32 */
#define NIFGEN_VAL_SOFTWARE_EDGE                               (104L)                                   /* ViInt32 */
#define NIFGEN_VAL_SOFTWARE_LEVEL                              (105L)                                   /* ViInt32 */
#define NIFGEN_VAL_P2P_ENDPOINT_FULLNESS                       (106L)                                   /* ViInt32 */

/*- Defined values for attribute NIFGEN_ATTR_TRIGGER_MODE ------------*/
#define NIFGEN_VAL_SINGLE                       1L
#define NIFGEN_VAL_CONTINUOUS                   2L
#define NIFGEN_VAL_STEPPED                      3L
#define NIFGEN_VAL_BURST                        4L

/*- Defined values for attribute NIFGEN_ATTR_ARB_SAMPLE_RATE ---------*/
#define NIFGEN_VAL_EXTERNAL_SAMPLE_RATE         -1.0

/*- Defined values for attribute NIFGEN_ATTR_CLOCK_MODE --------------*/
#define NIFGEN_VAL_HIGH_RESOLUTION               0L
#define NIFGEN_VAL_DIVIDE_DOWN                   1L
#define NIFGEN_VAL_AUTOMATIC                     2L

/*- Defined values for attribute NIFGEN_ATTR_IDLE_BEHAVIOR and NIFGEN_ATTR_WAIT_BEHAVIOR ---*/
#define NIFGEN_VAL_HOLD_LAST_VALUE               400L
#define NIFGEN_VAL_JUMP_TO_VALUE                 401L

/*- Defined values for Arbitrary Sequence Creation -------------------*/
#define NIFGEN_VAL_INFINITE_LOOP                 0L
#define NIFGEN_VAL_WHOLE_BUFFER                  0L
#define NIFGEN_VAL_NO_MARKER                    -1L
#define NIFGEN_VAL_MARKER_QUANTUM                8L

/*- Defined Values for Bus Type --------------------------------------*/
#define NIFGEN_VAL_BUS_INVALID                   0L
#define NIFGEN_VAL_BUS_AT                        1L
#define NIFGEN_VAL_BUS_PCI                       2L
#define NIFGEN_VAL_BUS_PXI                       3L
#define NIFGEN_VAL_BUS_VXI                       4L
#define NIFGEN_VAL_BUS_PCMCIA                    5L
#define NIFGEN_VAL_BUS_PXIE                      6L

/*- Defined Values for Video Waveform Type ---------------------------*/
#define NIFGEN_VAL_PAL_B                         0L
#define NIFGEN_VAL_PAL_D                         1L
#define NIFGEN_VAL_PAL_G                         2L
#define NIFGEN_VAL_PAL_H                         3L
#define NIFGEN_VAL_PAL_I                         4L
#define NIFGEN_VAL_PAL_M                         5L
#define NIFGEN_VAL_PAL_N                         6L
#define NIFGEN_VAL_NTSC_M                        7L

/*- Defined Values for Next Waveform Write Position ------------------*/
#define NIFGEN_VAL_WAVEFORM_POSITION_START       0L
#define NIFGEN_VAL_WAVEFORM_POSITION_CURRENT     1L

/*- Defined values for attribute NIFGEN_ATTR_ANALOG_PATH -------------*/
#define NIFGEN_VAL_MAIN_ANALOG_PATH              0L
#define NIFGEN_VAL_DIRECT_ANALOG_PATH            1L
#define NIFGEN_VAL_FIXED_LOW_GAIN_ANALOG_PATH    2L
#define NIFGEN_VAL_FIXED_HIGH_GAIN_ANALOG_PATH   3L

/*- Defined values for attribute NIFGEN_ATTR_CAL_ADC_INPUT -----------*/
#define NIFGEN_VAL_ANALOG_OUTPUT                 0L
#define NIFGEN_VAL_INTERNAL_VOLTAGE_REFERENCE    1L
#define NIFGEN_VAL_GROUND                        2L
#define NIFGEN_VAL_ANALOG_OUTPUT_DIFFERENTIAL    3L
#define NIFGEN_VAL_ANALOG_OUTPUT_PLUS            4L
#define NIFGEN_VAL_ANALOG_OUTPUT_MINUS           5L

/*- Defined values for action in niFgen_CloseExtCal()  ---------------*/
#define NIFGEN_VAL_EXT_CAL_ABORT                 0L
#define NIFGEN_VAL_EXT_CAL_COMMIT                1L

/*- Defined values for state in niFgen_GetHardwareState ()  ----------*/
#define NIFGEN_VAL_IDLE                          0L
#define NIFGEN_VAL_WAITING_FOR_START_TRIGGER     100L
#define NIFGEN_VAL_RUNNING                       200L
#define NIFGEN_VAL_DONE                          600L
#define NIFGEN_VAL_HARDWARE_ERROR                1000L

/*- Defined values for byte order in From File functions -------------*/
#define NIFGEN_VAL_LITTLE_ENDIAN                 0L
#define NIFGEN_VAL_BIG_ENDIAN                    1L

/*- Defined values for configuration in niFgen_CalAdjustMainPathPreAmpOffset ()
    and niFgen_CalAdjustMainPathPreAmpGain ()  -*/
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_FILTER_OFF_0DB         0L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_FILTER_OFF_3DB         1L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_FILTER_OFF_6DB         2L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_FILTER_OFF_9DB         3L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_FILTER_OFF_12DB        4L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_FILTER_ON_0DB          5L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_FILTER_ON_3DB          6L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_FILTER_ON_6DB          7L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_FILTER_ON_9DB          8L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_FILTER_ON_12DB         9L

/*- Defined values for configuration in niFgen_CalAdjustMainPathPostAmpGainAndOffset ()  -*/
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_LOW_GAIN_0DB           0L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_LOW_GAIN_12DB          1L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_LOW_GAIN_24DB          2L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_LOW_GAIN_36DB          3L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_HIGH_GAIN_0DB          4L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_HIGH_GAIN_12DB         5L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_HIGH_GAIN_24DB         6L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_HIGH_GAIN_36DB         7L

/*- Defined values for configuration in niFgen_CalAdjustMainPathOutputImpedance ()  -*/
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_LOW_GAIN_0DB_50OHMS    0L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_LOW_GAIN_0DB_75OHMS    1L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_LOW_GAIN_12DB_50OHMS   2L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_LOW_GAIN_12DB_75OHMS   3L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_LOW_GAIN_24DB_50OHMS   4L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_LOW_GAIN_24DB_75OHMS   5L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_LOW_GAIN_36DB_50OHMS   6L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_LOW_GAIN_36DB_75OHMS   7L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_HIGH_GAIN_0DB_50OHMS   8L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_HIGH_GAIN_0DB_75OHMS   9L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_HIGH_GAIN_12DB_50OHMS  10L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_HIGH_GAIN_12DB_75OHMS  11L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_HIGH_GAIN_24DB_50OHMS  12L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_HIGH_GAIN_24DB_75OHMS  13L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_HIGH_GAIN_36DB_50OHMS  14L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_HIGH_GAIN_36DB_75OHMS  15L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_DIFFERENTIAL           16L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_RSE                    17L

/*- Defined values for configuration in niFgen_CalAdjustDirectPathOutputImpedance ()  -*/
#define NIFGEN_VAL_CAL_CONFIG_DIRECT_PATH_50OHMS               0L
#define NIFGEN_VAL_CAL_CONFIG_DIRECT_PATH_75OHMS               1L
#define NIFGEN_VAL_CAL_CONFIG_DIRECT_PATH_DIFFERENTIAL         2L


/*- Defined values for configuration in niFgen_CalAdjustFlatness and niFgen_CalAdjustCalADC ()  -*/
#define NIFGEN_VAL_CAL_CONFIG_GLOBAL                          -1L
#define NIFGEN_VAL_CAL_CONFIG_LOW_GAIN_PATH_PRE_AMP_0DB        0L
#define NIFGEN_VAL_CAL_CONFIG_LOW_GAIN_PATH_PRE_AMP_3DB        1L
#define NIFGEN_VAL_CAL_CONFIG_LOW_GAIN_PATH_PRE_AMP_6DB        2L
#define NIFGEN_VAL_CAL_CONFIG_LOW_GAIN_PATH_PRE_AMP_9DB        3L
#define NIFGEN_VAL_CAL_CONFIG_LOW_GAIN_PATH_PRE_AMP_12DB       4L
#define NIFGEN_VAL_CAL_CONFIG_HIGH_GAIN_PATH_PRE_AMP_0DB       5L
#define NIFGEN_VAL_CAL_CONFIG_HIGH_GAIN_PATH_PRE_AMP_3DB       6L
#define NIFGEN_VAL_CAL_CONFIG_HIGH_GAIN_PATH_PRE_AMP_6DB       7L
#define NIFGEN_VAL_CAL_CONFIG_HIGH_GAIN_PATH_PRE_AMP_9DB       8L
#define NIFGEN_VAL_CAL_CONFIG_HIGH_GAIN_PATH_PRE_AMP_12DB      9L
#define NIFGEN_VAL_CAL_CONFIG_DIRECT_PATH                     10L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH                       11L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_0DB                   12L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_9DB                   13L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_33DB                  14L

/*- Defined values for NIFGEN_ATTR_OSP_DATA_PROCESSING_MODE -*/
#define NIFGEN_VAL_OSP_REAL                                    0L
#define NIFGEN_VAL_OSP_COMPLEX                                 1L

/*- Defined values for NIFGEN_ATTR_OSP_MODE -*/
#define NIFGEN_VAL_OSP_IF                                      0L
#define NIFGEN_VAL_OSP_BASEBAND                                1L

/*- Defined values for NIFGEN_ATTR_OSP_FIR_FILTER_TYPE -*/
#define NIFGEN_VAL_OSP_FLAT                                    0L
#define NIFGEN_VAL_OSP_RAISED_COSINE                           1L
#define NIFGEN_VAL_OSP_ROOT_RAISED_COSINE                      2L
#define NIFGEN_VAL_OSP_GAUSSIAN                                3L
#define NIFGEN_VAL_OSP_CUSTOM                                  4L

/*- Defined bit mask values for NIFGEN_ATTR_OSP_OVERFLOW_ERROR_REPORTING -*/
#define NIFGEN_VAL_ERROR_REPORTING_ERROR                       0L
#define NIFGEN_VAL_ERROR_REPORTING_DISABLED                    2L

/*- Defined bit mask values for NIFGEN_ATTR_OSP_OVERFLOW_STATUS -*/
#define NIFGEN_VAL_OSP_OVERFLOW_NONE                           0L
#define NIFGEN_VAL_OSP_OVERFLOW_PRE_FILTER_GAIN_I              1L
#define NIFGEN_VAL_OSP_OVERFLOW_PRE_FILTER_GAIN_Q              2L
#define NIFGEN_VAL_OSP_OVERFLOW_PRE_FILTER_OFFSET_I            4L
#define NIFGEN_VAL_OSP_OVERFLOW_PRE_FILTER_OFFSET_Q            8L
#define NIFGEN_VAL_OSP_OVERFLOW_FIR_FILTER_I                   16L
#define NIFGEN_VAL_OSP_OVERFLOW_PFIR_FILTER_I                  16L
#define NIFGEN_VAL_OSP_OVERFLOW_FIR_FILTER_Q                   32L
#define NIFGEN_VAL_OSP_OVERFLOW_PFIR_FILTER_Q                  32L
#define NIFGEN_VAL_OSP_OVERFLOW_CIC_FILTER_I                   64L
#define NIFGEN_VAL_OSP_OVERFLOW_CIC_FILTER_Q                   128L
#define NIFGEN_VAL_OSP_OVERFLOW_COMPLEX_DATA                   256L
#define NIFGEN_VAL_OSP_OVERFLOW_CFIR_FILTER_I                  512L
#define NIFGEN_VAL_OSP_OVERFLOW_CFIR_FILTER_Q                  1024L
#define NIFGEN_VAL_OSP_OVERFLOW_EQUALIZER                      2048L

/*- Defined values for P2P Address Type Attributes -*/
#define NIFGEN_VAL_ADDR_PHYSICAL                               0L
#define NIFGEN_VAL_ADDR_VIRTUAL                                1L



/****************************************************************************
 *---------------- Instrument Driver struct definititions  -----------------*
 ****************************************************************************/

/*- Use with:
      niFgen_CreateWaveformComplexF64
      niFgen_WriteWaveformComplexF64
      niFgen_WriteNamedWaveformComplexF64
*/
#if !defined(_NIComplexNumber)
typedef struct NIComplexNumber_struct {
   ViReal64 real;
   ViReal64 imaginary;
} NIComplexNumber;
#define _NIComplexNumber
#endif

/*- Use with:
      niFgen_WriteComplexBinary16Waveform
      niFgen_WriteNamedWaveformComplexI16
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

/*- Init and Close Functions -------------------------------------------*/

ViStatus _VI_FUNC  niFgen_init(
   ViRsrc resourceName,
   ViBoolean IDQuery,
   ViBoolean resetDevice,
   ViSession *vi);

ViStatus _VI_FUNC  niFgen_InitWithOptions(
   ViRsrc resourceName,
   ViBoolean IDQuery,
   ViBoolean resetDevice,
   ViConstString optionString,
   ViSession *newVi);

ViStatus _VI_FUNC niFgen_InitializeWithChannels(
   ViRsrc resourceName,
   ViConstString channelName,
   ViBoolean resetDevice,
   ViConstString optionString,
   ViSession *newVi);

ViStatus _VI_FUNC  niFgen_close(
   ViSession vi);

/*- Required VXIplug&play Functions -------------------------------------*/

ViStatus _VI_FUNC niFgen_reset(
   ViSession vi);

ViStatus _VI_FUNC niFgen_self_test(
   ViSession vi,
   ViInt16 *testResult,/*Output*/
   ViChar testMessage[]);

ViStatus _VI_FUNC niFgen_error_query(
   ViSession vi,
   ViInt32 *errorCode,
   ViChar selfTestMessage[]);

ViStatus _VI_FUNC niFgen_error_message(
   ViSession vi,
   ViStatus statusCode,
   ViChar message[]);

ViStatus _VI_FUNC niFgen_revision_query(
   ViSession vi,
   ViChar driverRev[],
   ViChar instrRev[]);

/*- Error Functions --------------------------------------------------------*/
ViStatus _VI_FUNC niFgen_GetError(
   ViSession vi,
   ViStatus *errorCode,
   ViInt32 errorDescriptionBufferSize,
   ViChar errorDescription[]);

ViStatus _VI_FUNC niFgen_ClearError(
   ViSession vi);

ViStatus _VI_FUNC niFgen_ErrorHandler(
   ViSession vi,
   ViStatus statusCode,
   ViChar errorMessage[256]);

/*- Required IVI Functions ---------------------------------------------*/
ViStatus _VI_FUNC niFgen_LockSession(
   ViSession vi,
   ViBoolean *callerHasLock);

ViStatus _VI_FUNC niFgen_UnlockSession(
   ViSession vi,
   ViBoolean *callerHasLock);

/*- Channel Info Functions ---------------------------------------------*/
ViStatus _VI_FUNC niFgen_GetChannelName(
   ViSession vi,
   ViInt32 index,
   ViInt32 bufferSize,
   ViChar name[]);

/*- Interchangeability Checking Functions ------------------------------*/
ViStatus _VI_FUNC niFgen_GetNextInterchangeWarning(
   ViSession vi,
   ViInt32 bufferSize,
   ViChar warnString[]);

ViStatus _VI_FUNC niFgen_ResetInterchangeCheck(
   ViSession vi);

ViStatus _VI_FUNC niFgen_ClearInterchangeWarnings(
   ViSession vi);

ViStatus _VI_FUNC niFgen_GetNextCoercionRecord(
   ViSession vi,
   ViInt32 bufferSize,
   ViChar record[]);

/*- Utility Functions --------------------------------------------------*/
ViStatus _VI_FUNC niFgen_InvalidateAllAttributes(
   ViSession vi);

ViStatus _VI_FUNC niFgen_ResetWithDefaults(
   ViSession vi);

ViStatus _VI_FUNC niFgen_Disable(
   ViSession vi);

ViStatus _VI_FUNC niFgen_Commit(
   ViSession vi);

ViStatus _VI_FUNC niFgen_GetHardwareState(
   ViSession vi,
   ViInt32* state);

ViStatus _VI_FUNC niFgen_WaitUntilDone(
   ViSession vi,
   ViInt32  maxTime);

ViStatus _VI_FUNC niFgen_IsDone(
   ViSession vi,
   ViBoolean* done);

ViStatus _VI_FUNC niFgen_ResetDevice(
   ViSession vi);

/*- Basic Instrument Operation -----------------------------------------*/
ViStatus _VI_FUNC niFgen_ConfigureOperationMode(
   ViSession vi,
   ViConstString channelName,
   ViInt32 mode);

ViStatus _VI_FUNC niFgen_ConfigureOutputMode(
   ViSession vi,
   ViInt32 outputMode);

ViStatus _VI_FUNC niFgen_ConfigureReferenceClock(
   ViSession vi,
   ViConstString referenceClockSource,
   ViReal64 referenceClockFrequency);

ViStatus _VI_FUNC niFgen_ConfigureOutputImpedance(
   ViSession vi,
   ViConstString channelName,
   ViReal64 outputImpedance);

ViStatus _VI_FUNC niFgen_ConfigureOutputEnabled(
   ViSession vi,
   ViConstString channelName,
   ViBoolean enabled);

ViStatus _VI_FUNC niFgen_ConfigureChannels(
   ViSession vi,
   ViConstString channelName);

ViStatus _VI_FUNC niFgen_InitiateGeneration(
   ViSession vi);

ViStatus _VI_FUNC niFgen_AbortGeneration(
   ViSession vi);

/*- Standard Function Output -------------------------------------------*/
ViStatus _VI_FUNC niFgen_ConfigureStandardWaveform(
   ViSession vi,
   ViConstString channelName,
   ViInt32 waveform,
   ViReal64 amplitude,
   ViReal64 dcOffset,
   ViReal64 frequency,
   ViReal64 startPhase);

ViStatus _VI_FUNC niFgen_DefineUserStandardWaveform(
   ViSession vi,
   ViConstString channelName,
   ViInt32 numberOfSamples,
   ViReal64 data[]);

ViStatus _VI_FUNC niFgen_ClearUserStandardWaveform(
   ViSession vi,
   ViConstString channelName);

ViStatus _VI_FUNC niFgen_ConfigureFrequency(
   ViSession vi,
   ViConstString channelName,
   ViReal64 Frequency);

ViStatus _VI_FUNC niFgen_ConfigureAmplitude(
   ViSession vi,
   ViConstString channelName,
   ViReal64 Amplitude);

/*- Arbitrary Waveform Output ------------------------------------------*/
ViStatus _VI_FUNC niFgen_QueryArbWfmCapabilities(
   ViSession vi,
   ViInt32 *maxNumWfms,
   ViInt32 *wfmQuantum,
   ViInt32 *minNumberOfSamples,
   ViInt32 *maxNumberOfSamples);

ViStatus _VI_FUNC  niFgen_CreateWaveformF64(
   ViSession vi,
   ViConstString channelName,
   ViInt32 numberOfSamples,
   ViReal64 wfmData[],
   ViInt32 *wfmHandle);

ViStatus _VI_FUNC  niFgen_CreateWaveformI16(
   ViSession vi,
   ViConstString channelName,
   ViInt32 numberOfSamples,
   ViInt16 wfmData[],
   ViInt32 *wfmHandle);

ViStatus _VI_FUNC  niFgen_CreateWaveformComplexF64(
   ViSession vi,
   ViConstString channelName,
   ViInt32 numberOfSamples,
   NIComplexNumber wfmData[],
   ViInt32 *wfmHandle);

ViStatus _VI_FUNC  niFgen_CreateWaveformFromFileI16(
   ViSession vi,
   ViConstString channelName,
   ViConstString fileName,
   ViInt32 byteOrder,
   ViInt32 *wfmHandle);

ViStatus _VI_FUNC  niFgen_CreateWaveformFromFileF64(
   ViSession vi,
   ViConstString channelName,
   ViConstString fileName,
   ViInt32 byteOrder,
   ViInt32 *wfmHandle);

ViStatus _VI_FUNC  niFgen_CreateWaveformFromFileHWS(
   ViSession vi,
   ViConstString channelName,
   ViConstString fileName,
   ViBoolean useRateFromWaveform,
   ViBoolean useGainAndOffsetFromWaveform,
   ViInt32 *wfmHandle);

ViStatus _VI_FUNC  niFgen_ConfigureSampleRate(
   ViSession vi,
   ViReal64 sampleRate);

ViStatus _VI_FUNC  niFgen_ConfigureArbWaveform(
   ViSession vi,
   ViConstString channelName,
   ViInt32 wfmHandle,
   ViReal64 arbGain,
   ViReal64 arbOffset);

ViStatus _VI_FUNC  niFgen_ClearArbWaveform (
   ViSession vi,
   ViInt32 wfmHandle);

ViStatus _VI_FUNC niFgen_AllocateNamedWaveform(
   ViSession vi,
   ViConstString channelName,
   ViConstString wfmName,
   ViInt32 numberOfSamples);

ViStatus _VI_FUNC niFgen_SetNamedWaveformNextWritePosition(
   ViSession vi,
   ViConstString channelName,
   ViConstString wfmName,
   ViInt32 relativeTo,
   ViInt32 offset);

ViStatus _VI_FUNC niFgen_WriteNamedWaveformF64(
   ViSession vi,
   ViConstString channelName,
   ViConstString wfmName,
   ViInt32 numberOfSamples,
   ViReal64 wfmData[]);

ViStatus _VI_FUNC niFgen_WriteNamedWaveformI16(
   ViSession vi,
   ViConstString channelName,
   ViConstString wfmName,
   ViInt32 numberOfSamples,
   ViInt16 wfmData[]);

ViStatus _VI_FUNC niFgen_WriteNamedWaveformComplexF64(
   ViSession vi,
   ViConstString channelName,
   ViConstString wfmName,
   ViInt32 numberOfSamples,
   NIComplexNumber wfmData[]);

ViStatus _VI_FUNC niFgen_WriteNamedWaveformComplexI16(
   ViSession vi,
   ViConstString channelName,
   ViConstString wfmName,
   ViInt32 numberOfSamples,
   NIComplexI16 wfmData[]);

ViStatus _VI_FUNC niFgen_DeleteNamedWaveform(
   ViSession vi,
   ViConstString channelName,
   ViConstString wfmName);

/*- Arbitrary Sequence Output ------------------------------------------*/
ViStatus _VI_FUNC niFgen_QueryArbSeqCapabilities(
   ViSession vi,
   ViInt32 *maxNumSeqs,
   ViInt32 *minSeqLength,
   ViInt32 *maxSeqLength,
   ViInt32 *maxLoopCount);

ViStatus _VI_FUNC niFgen_CreateArbSequence(
   ViSession vi,
   ViInt32 seqLength,
   ViInt32 wfmHandle[],
   ViInt32 wfmLoopCount[],
   ViInt32 *seqHandle);

ViStatus _VI_FUNC  niFgen_CreateAdvancedArbSequence(
   ViSession vi,
   ViInt32 seqLength,
   ViInt32 wfmHandles[],
   ViInt32 loopCounts[],
   ViInt32 sampleCounts[],
   ViInt32 markers[],
   ViInt32 coercedMarkers[],
   ViInt32 *seqHandle);

ViStatus _VI_FUNC niFgen_ConfigureArbSequence(
   ViSession vi,
   ViConstString channelName,
   ViInt32 seqHandle,
   ViReal64 arbGain,
   ViReal64 arbOffset);

ViStatus _VI_FUNC niFgen_ClearArbSequence(
   ViSession vi,
   ViInt32 seqHandle);

ViStatus _VI_FUNC niFgen_ClearArbMemory(
   ViSession vi);

/*- Frequency List Output ----------------------------------------------*/
ViStatus _VI_FUNC niFgen_QueryFreqListCapabilities(
   ViSession vi,
   ViInt32 *maximumNumberOfFreqLists,
   ViInt32 *minimumFrequencyListLength,
   ViInt32 *maximumFrequencyListLength,
   ViReal64 *minimumFrequencyListDuration,
   ViReal64 *maximumFrequencyListDuration,
   ViReal64 *frequencyListDurationQuantum);

ViStatus _VI_FUNC niFgen_CreateFreqList(
   ViSession vi,
   ViInt32 waveform,
   ViInt32 frequencyListLength,
   ViReal64 frequencyArray[],
   ViReal64 durationArray[],
   ViInt32 *frequencyListHandle);

ViStatus _VI_FUNC niFgen_ConfigureFreqList(
   ViSession vi,
   ViConstString channelName,
   ViInt32 frequencyListHandle,
   ViReal64 amplitude,
   ViReal64 dcOffset,
   ViReal64 startPhase);

ViStatus _VI_FUNC niFgen_ClearFreqList(
   ViSession vi,
   ViInt32 frequencyListHandle);

/*- Script Output ----------------------------------------------------*/
ViStatus _VI_FUNC niFgen_WriteScript(
   ViSession vi,
   ViConstString channelName,
   ViConstString script);

ViStatus _VI_FUNC niFgen_DeleteScript(
   ViSession vi,
   ViConstString channelName,
   ViConstString scriptName);

/*- Routing ------------------------------------------------------------*/
ViStatus _VI_FUNC niFgen_ExportSignal(
   ViSession vi,
   ViInt32 signal,
   ViConstString signalIdentifier,
   ViConstString outputTerminal);

/*- 5404 Routing -------------------------------------------------------*/
ViStatus _VI_FUNC  niFgen_RouteSignalOut(
   ViSession vi,
   ViConstString channelName,
   ViInt32 from,
   ViInt32 to);

/*- Triggering ---------------------------------------------------------*/
ViStatus _VI_FUNC niFgen_SendSoftwareEdgeTrigger(
   ViSession vi,
   ViInt32 triggerName,
   ViConstString triggerIdentifier);


/* Start Trigger */

ViStatus _VI_FUNC niFgen_ConfigureDigitalEdgeStartTrigger(
   ViSession vi,
   ViConstString source,
   ViInt32 edge);

ViStatus _VI_FUNC niFgen_ConfigureSoftwareEdgeStartTrigger(
   ViSession vi);

ViStatus _VI_FUNC niFgen_DisableStartTrigger(
   ViSession vi);

ViStatus _VI_FUNC niFgen_ConfigureP2PEndpointFullnessStartTrigger(
   ViSession vi,
   ViInt32 p2pEndpointFullnessLevel);


/* Script Trigger */

ViStatus _VI_FUNC niFgen_ConfigureDigitalEdgeScriptTrigger(
   ViSession vi,
   ViConstString triggerID,
   ViConstString source,
   ViInt32 edge);

ViStatus _VI_FUNC niFgen_ConfigureDigitalLevelScriptTrigger(
   ViSession vi,
   ViConstString triggerID,
   ViConstString source,
   ViInt32 level);

ViStatus _VI_FUNC niFgen_ConfigureSoftwareEdgeScriptTrigger(
   ViSession vi,
   ViConstString triggerID);

ViStatus _VI_FUNC niFgen_DisableScriptTrigger(
   ViSession vi,
   ViConstString triggerID);

/*- Sampling Control -----------------------------------------------------*/
ViStatus _VI_FUNC niFgen_ConfigureClockMode(
   ViSession vi,
   ViInt32 clockMode);

ViStatus _VI_FUNC niFgen_AdjustSampleClockRelativeDelay(
   ViSession vi,
   ViReal64 time);

/*- Incremental Write -----------------------------------------------------*/
ViStatus _VI_FUNC niFgen_AllocateWaveform(
   ViSession vi,
   ViConstString channelName,
   ViInt32 numberOfSamples,
   ViInt32* waveformHandle);

ViStatus _VI_FUNC niFgen_SetWaveformNextWritePosition(
   ViSession vi,
   ViConstString channelName,
   ViInt32 waveformHandle,
   ViInt32 relativeTo,
   ViInt32 offset);

ViStatus _VI_FUNC niFgen_WriteWaveform(
   ViSession vi,
   ViConstString channelName,
   ViInt32 waveformHandle,
   ViInt32 numberOfSamples,
   ViReal64 wfmData[]);

ViStatus _VI_FUNC niFgen_WriteBinary16Waveform(
   ViSession vi,
   ViConstString channelName,
   ViInt32 waveformHandle,
   ViInt32 numberOfSamples,
   ViInt16 wfmData[]);

ViStatus _VI_FUNC  niFgen_WriteWaveformComplexF64(
   ViSession vi,
   ViConstString channelName,
   ViInt32 numberOfSamples,
   NIComplexNumber wfmData[],
   ViInt32 wfmHandle);

ViStatus _VI_FUNC  niFgen_WriteComplexBinary16Waveform(
   ViSession vi,
   ViConstString channelName,
   ViInt32 waveformHandle,
   ViInt32 numberOfSamples,
   NIComplexI16 wfmData[]);

/*- Calibration --------------------------------------------*/
ViStatus _VI_FUNC niFgen_InitExtCal(
   ViRsrc resourceName,
   ViConstString password,
   ViSession* vi);

ViStatus _VI_FUNC niFgen_InitializeOscillatorFrequencyCalibration(
   ViSession vi);

ViStatus _VI_FUNC niFgen_InitializeAnalogOutputCalibration(
   ViSession vi);

ViStatus _VI_FUNC niFgen_InitializeCalADCCalibration(
   ViSession vi);

ViStatus _VI_FUNC niFgen_InitializeFlatnessCalibration(
   ViSession vi);

ViStatus _VI_FUNC niFgen_CloseExtCal(
   ViSession vi,
   ViInt32 action);

ViStatus _VI_FUNC niFgen_SelfCal(
   ViSession vi);

ViStatus _VI_FUNC niFgen_RestoreLastExtCalConstants(
   ViSession vi);

ViStatus _VI_FUNC niFgen_GetSelfCalSupported(
   ViSession vi,
   ViBoolean* selfCalSupported);

ViStatus _VI_FUNC niFgen_GetSelfCalLastDateAndTime(
   ViSession vi,
   ViInt32* year,
   ViInt32* month,
   ViInt32* day,
   ViInt32* hour,
   ViInt32* minute);

ViStatus _VI_FUNC niFgen_GetExtCalLastDateAndTime(
   ViSession vi,
   ViInt32* year,
   ViInt32* month,
   ViInt32* day,
   ViInt32* hour,
   ViInt32* minute);

ViStatus _VI_FUNC niFgen_GetSelfCalLastTemp(
   ViSession vi,
   ViReal64* temp);

ViStatus _VI_FUNC niFgen_GetExtCalLastTemp(
   ViSession vi,
   ViReal64* temp);

ViStatus _VI_FUNC niFgen_GetExtCalRecommendedInterval(
   ViSession vi,
   ViInt32* months);

ViStatus _VI_FUNC niFgen_ChangeExtCalPassword(
   ViSession vi,
   ViConstString oldPassword,
   ViConstString newPassword);

ViStatus _VI_FUNC niFgen_SetCalUserDefinedInfo(
   ViSession vi,
   ViConstString info);

ViStatus _VI_FUNC niFgen_GetCalUserDefinedInfo(
   ViSession vi,
   ViString info);

ViStatus _VI_FUNC niFgen_GetCalUserDefinedInfoMaxSize(
   ViSession vi,
   ViInt32* infoSize);

ViStatus _VI_FUNC niFgen_ReadCurrentTemperature(
   ViSession vi,
   ViReal64* temperature);

ViStatus _VI_FUNC niFgen_ReadCalADC(
   ViSession vi,
   ViInt32 numberOfReadsToAverage,
   ViBoolean returnCalibratedValue,
   ViReal64* calADCValue);

ViStatus _VI_FUNC niFgen_WriteBinary16AnalogStaticValue(
   ViSession vi,
   ViConstString channelName,
   ViInt16 value);


/*- Calibration Adjust Functions-------------------------------------*/

ViStatus _VI_FUNC niFgen_CalAdjustMainPathPreAmpOffset(
   ViSession vi,
   ViConstString channelName,
   ViInt32  configuration,
   ViInt32* gainDACValues,
   ViInt32* offsetDACValues,
   ViReal64* measuredOutputs);

ViStatus _VI_FUNC niFgen_CalAdjustMainPathPreAmpGain(
   ViSession vi,
   ViConstString channelName,
   ViInt32  configuration,
   ViInt32* mainDACValues,
   ViInt32* gainDACValues,
   ViInt32* offsetDACValues,
   ViReal64* measuredOutputs);

ViStatus _VI_FUNC niFgen_CalAdjustMainPathPostAmpGainAndOffset(
   ViSession vi,
   ViConstString channelName,
   ViInt32  configuration,
   ViInt32* mainDACValues,
   ViInt32* gainDACValues,
   ViInt32* offsetDACValues,
   ViReal64* measuredOutputs);

ViStatus _VI_FUNC niFgen_CalAdjustDirectPathGain(
   ViSession vi,
   ViConstString channelName,
   ViInt32* mainDACValues,
   ViInt32* gainDACValues,
   ViReal64* measuredOutputs);

ViStatus _VI_FUNC niFgen_CalAdjustMainPathOutputImpedance(
   ViSession vi,
   ViConstString channelName,
   ViInt32 configuration,
   ViReal64 loadImpedance,
   ViReal64 measuredSourceVoltage,
   ViReal64 measuredVoltageAcrossLoad);

ViStatus _VI_FUNC niFgen_CalAdjustDirectPathOutputImpedance(
   ViSession vi,
   ViConstString channelName,
   ViInt32 configuration,
   ViReal64 loadImpedance,
   ViReal64 measuredSourceVoltage,
   ViReal64 measuredVoltageAcrossLoad);

ViStatus _VI_FUNC niFgen_CalAdjustOscillatorFrequency(
   ViSession vi,
   ViReal64 desiredFrequencyInHz,
   ViReal64 measuredFrequencyInHz);

ViStatus _VI_FUNC niFgen_CalAdjustADC(
   ViSession vi,
   ViConstString channelName,
   ViInt32 configuration,
   ViReal64* voltagesMeasuredExternally,
   ViReal64* voltagesMeasuredWithCalADC);

ViStatus _VI_FUNC niFgen_CalAdjustFlatness(
   ViSession vi,
   ViConstString channelName,
   ViInt32 configuration,
   ViReal64 requestedAmplitude,
   ViReal64* frequencies,
   ViReal64* measuredAmplitudes,
   ViInt32 numberOfMeasurements);


/*- Onboard Signal Processing Functions --------------------------------*/
ViStatus _VI_FUNC niFgen_ConfigureCustomFIRFilterCoefficients(
   ViSession vi,
   ViConstString channelName,
   ViInt32 numberOfCoefficients,
   ViReal64* coefficients);

ViStatus _VI_FUNC niFgen_GetFIRFilterCoefficients(
   ViSession vi,
   ViConstString channelName,
   ViInt32 arraySize,
   ViReal64* coefficients,
   ViInt32* numberOfCoefficientsRead);


/*- Peer-to-Peer (P2P) Functions --------------------------------*/
ViStatus _VI_FUNC niFgen_GetStreamEndpointHandle(
   ViSession vi,
   ViConstString streamEndpoint,
   ViUInt32* readerHandle);

ViStatus _VI_FUNC niFgen_ManualEnableP2PStream(
   ViSession vi,
   ViConstString streamEndpoint);

ViStatus _VI_FUNC niFgen_WriteP2PEndpointI16(
   ViSession vi,
   ViConstString fifoEndpointName,
   ViInt32 numberOfSamples,
   ViInt16 endpointData[]);


/*- Miscellaneous Functions --------------------------------------------*/
ViStatus _VI_FUNC  niFgen_ConfigureSynchronization(
   ViSession vi,
   ViConstString channelName,
   ViInt32 Synchronization);

ViStatus _VI_FUNC niFgen_EnableDigitalPatterning(
   ViSession vi,
   ViConstString channelName);

ViStatus _VI_FUNC niFgen_DisableDigitalPatterning(
   ViSession vi,
   ViConstString channelName);

ViStatus _VI_FUNC niFgen_EnableDigitalFilter(
   ViSession vi,
   ViConstString channelName);

ViStatus _VI_FUNC niFgen_DisableDigitalFilter(
   ViSession vi,
   ViConstString channelName);

ViStatus _VI_FUNC niFgen_EnableAnalogFilter(
   ViSession vi,
   ViConstString channelName,
   ViReal64 filterCorrectionFreq);

ViStatus _VI_FUNC niFgen_DisableAnalogFilter(
   ViSession vi,
   ViConstString channelName);

ViStatus _VI_FUNC niFgen_ConfigureSampleClockSource(
   ViSession vi,
   ViConstString sampleClockSource);

ViStatus _VI_FUNC niFgen_ConfigureTriggerMode(
   ViSession vi,
   ViConstString channelName,
   ViInt32 mode);

/*- Import and Export Attribute Configuration Functions -----------------*/
ViStatus _VI_FUNC niFgen_ImportAttributeConfigurationFile(
   ViSession vi,
   ViConstString filePath);

ViStatus _VI_FUNC niFgen_ExportAttributeConfigurationFile(
   ViSession vi,
   ViConstString filePath);

ViStatus _VI_FUNC niFgen_ImportAttributeConfigurationBuffer(
   ViSession vi,
   ViInt32 size,
   ViAddr configuration);

ViStatus _VI_FUNC niFgen_ExportAttributeConfigurationBuffer(
   ViSession vi,
   ViInt32 size,
   ViAddr configuration);

/*- Attributes ---------------------------------------------------------*/
#ifdef _VI_INT64_UINT64_DEFINED
ViStatus _VI_FUNC niFgen_SetAttributeViInt64    (ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt64 value) ;
ViStatus _VI_FUNC niFgen_CheckAttributeViInt64  (ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt64 value) ;
ViStatus _VI_FUNC niFgen_GetAttributeViInt64    (ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt64 *value) ;
#endif

ViStatus _VI_FUNC niFgen_SetAttributeViInt32    (ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 value) ;
ViStatus _VI_FUNC niFgen_SetAttributeViReal64   (ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64 value) ;
ViStatus _VI_FUNC niFgen_SetAttributeViString   (ViSession vi, ViConstString channelName, ViAttr attributeId, ViConstString value) ;
ViStatus _VI_FUNC niFgen_SetAttributeViBoolean  (ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean value) ;
ViStatus _VI_FUNC niFgen_SetAttributeViSession  (ViSession vi, ViConstString channelName, ViAttr attributeId, ViSession value) ;

ViStatus _VI_FUNC niFgen_CheckAttributeViInt32  (ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 value) ;
ViStatus _VI_FUNC niFgen_CheckAttributeViReal64 (ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64 value) ;
ViStatus _VI_FUNC niFgen_CheckAttributeViString (ViSession vi, ViConstString channelName, ViAttr attributeId, ViConstString value) ;
ViStatus _VI_FUNC niFgen_CheckAttributeViBoolean(ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean value) ;
ViStatus _VI_FUNC niFgen_CheckAttributeViSession(ViSession vi, ViConstString channelName, ViAttr attributeId, ViSession value) ;

ViStatus _VI_FUNC niFgen_GetAttributeViInt32    (ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 *value) ;
ViStatus _VI_FUNC niFgen_GetAttributeViReal64   (ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64 *value) ;
ViStatus _VI_FUNC niFgen_GetAttributeViString   (ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 bufSize, ViChar value[]) ;
ViStatus _VI_FUNC niFgen_GetAttributeViBoolean  (ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean *value) ;
ViStatus _VI_FUNC niFgen_GetAttributeViSession  (ViSession vi, ViConstString channelName, ViAttr attributeId, ViSession *value) ;

ViStatus _VI_FUNC niFgen_ResetAttribute         (ViSession vi, ViConstString channelName, ViAttr attributeId);

/****************************************************************************
 *------------------------------- Error Codes ------------------------------*
 ****************************************************************************/
#define NIFGEN_ERROR_TRIGGER_NOT_SOFTWARE      IVIFGEN_ERROR_TRIGGER_NOT_SOFTWARE
#define NIFGEN_ERROR_NOT_CONFIGURABLE          0xBFFA2001
#define NIFGEN_ERROR_NOT_GENERATING            0xBFFA2002
#define NIFGEN_ERROR_INVALID_MODE              0xBFFA2003
#define NIFGEN_ERROR_NO_WFMS_AVAILABLE         IVIFGEN_ERROR_NO_WFMS_AVAILABLE
#define NIFGEN_ERROR_INVALID_WFM_LENGTH        0xBFFA2005
#define NIFGEN_ERROR_INVALID_WFM_ELEMENT       0xBFFA2006
#define NIFGEN_ERROR_INVALID_WAVEFORM          0xBFFA2007
#define NIFGEN_ERROR_WFM_IN_USE                IVIFGEN_ERROR_WFM_IN_USE
#define NIFGEN_ERROR_NO_SEQS_AVAILABLE         IVIFGEN_ERROR_NO_SEQS_AVAILABLE
#define NIFGEN_ERROR_INVALID_SEQ_LENGTH        0xBFFA200A
#define NIFGEN_ERROR_INVALID_LOOP_COUNT        0xBFFA200B
#define NIFGEN_ERROR_INVALID_SEQUENCE          0xBFFA200C
#define NIFGEN_ERROR_SEQ_IN_USE                IVIFGEN_ERROR_SEQ_IN_USE
#define NIFGEN_ERROR_INVALID_SESSION           0xBFFA1190

#define NIFGEN_ERROR_DAQ_PARAMETER_CHANGE      (IVI_SPECIFIC_ERROR_BASE + 1L)
#define NIFGEN_ERROR_DAQ_GROUP_CONTROL         (IVI_SPECIFIC_ERROR_BASE + 2L)
#define NIFGEN_ERROR_DAQ_SELECT_SIGNAL         (IVI_SPECIFIC_ERROR_BASE + 3L)
#define NIFGEN_ERROR_DAQ_GROUP_SETUP           (IVI_SPECIFIC_ERROR_BASE + 4L)
#define NIFGEN_ERROR_DAQ_CONFIGURE             (IVI_SPECIFIC_ERROR_BASE + 5L)
#define NIFGEN_ERROR_DAQ_INIT_BOARD            (IVI_SPECIFIC_ERROR_BASE + 6L)
#define NIFGEN_ERROR_DAQ_WFM_LOAD              (IVI_SPECIFIC_ERROR_BASE + 7L)
#define NIFGEN_ERROR_DAQ_GET_ATTRIBUTE         (IVI_SPECIFIC_ERROR_BASE + 8L)
#define NIFGEN_ERROR_INVALID_FREQ_LIST         (IVI_SPECIFIC_ERROR_BASE + 9L)
#define NIFGEN_ERROR_NO_FREQ_LISTS_AVAILABLE   (IVI_SPECIFIC_ERROR_BASE + 10L)
#define NIFGEN_ERROR_INVALID_FREQ_LIST_LENGTH  (IVI_SPECIFIC_ERROR_BASE + 11L)
#define NIFGEN_ERROR_DAQ_CLOCK_RATE            (IVI_SPECIFIC_ERROR_BASE + 12L)
#define NIFGEN_ERROR_INVALID_SAMPLE_COUNT      (IVI_SPECIFIC_ERROR_BASE + 13L)
#define NIFGEN_ERROR_INVALID_MARKER            (IVI_SPECIFIC_ERROR_BASE + 14L)
#define NIFGEN_ERROR_INVALID_FREQUENCY         (IVI_SPECIFIC_ERROR_BASE + 15L)
#define NIFGEN_ERROR_INVALID_DURATION          (IVI_SPECIFIC_ERROR_BASE + 16L)
#define NIFGEN_ERROR_DAQ_SET_CLOCK             (IVI_SPECIFIC_ERROR_BASE + 17L)
#define NIFGEN_ERROR_DAQ_DEVICE_INFO           (IVI_SPECIFIC_ERROR_BASE + 18L)
#define NIFGEN_ERROR_MAX_TIME_EXCEEDED         (IVI_SPECIFIC_ERROR_BASE + 19L)
#define NIFGEN_ERROR_NO_WFMS_EXIST             (IVI_SPECIFIC_ERROR_BASE + 20L)
#define NIFGEN_ERROR_NO_SEQS_EXIST             (IVI_SPECIFIC_ERROR_BASE + 21L)
#define NIFGEN_ERROR_NO_WFM_SPECIFIED          (IVI_SPECIFIC_ERROR_BASE + 22L)
#define NIFGEN_ERROR_NO_SEQ_SPECIFIED          (IVI_SPECIFIC_ERROR_BASE + 23L)
#define NIFGEN_ERROR_INVALID_DURING_SIMULATION (IVI_SPECIFIC_ERROR_BASE + 24L)
#define NIFGEN_ERROR_CAL_ADC_OVER_RANGE        (IVI_SPECIFIC_ERROR_BASE + 25L)
#define NIFGEN_ERROR_CAL_ADC_UNDER_RANGE       (IVI_SPECIFIC_ERROR_BASE + 26L)
#define NIFGEN_ERROR_HWS_ERROR                 (IVI_SPECIFIC_ERROR_BASE + 27L)
#define NIFGEN_ERROR_INSTRUMENT_ALREADY_IN_USE (IVI_SPECIFIC_ERROR_BASE + 28L)
#define NIFGEN_ERROR_SAMPLE_RATE_INVALID_FOR_INTERPOLATION (IVI_SPECIFIC_ERROR_BASE + 29L)
#define NIFGEN_ERROR_CODE_LAST                 (IVI_SPECIFIC_ERROR_BASE + 100L)

/* Warning codes */
#define NIFGEN_WARN_CODE_BASE                  (IVI_SPECIFIC_WARN_BASE + 0L)

/****************************************************************************
 *---------------------------- End Include File ----------------------------*
 ****************************************************************************/

#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#include "niFgenObsolete.h"

#endif /* __NIFGEN_HEADER */



