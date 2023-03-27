
/****************************************************************************************************
*          National Instruments RFmx NR
*----------------------------------------------------------------------------------------------------
*   Copyright(c) National Instruments 2021.  All Rights Reserved.
*----------------------------------------------------------------------------------------------------
*
* Title:    niRFmxNR.h
*
* Purpose:  National Instruments RFmx NR,
*                                Attribute IDs,
*                                Attribute Values,
*                                Functions Declarations.
*
*****************************************************************************************************/

#ifndef __NI_RFMX_NR_H__
#define __NI_RFMX_NR_H__

#include "niRFmxInstr.h"

#define RFMXNR_ATTR_SELECTED_PORTS                                                         0x00900ffd
#define RFMXNR_ATTR_CENTER_FREQUENCY                                                       0x00900001
#define RFMXNR_ATTR_REFERENCE_LEVEL                                                        0x00900002
#define RFMXNR_ATTR_EXTERNAL_ATTENUATION                                                   0x00900003
#define RFMXNR_ATTR_REFERENCE_LEVEL_HEADROOM                                               0x00900ffc
#define RFMXNR_ATTR_TRIGGER_TYPE                                                           0x00900004
#define RFMXNR_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE                                            0x00900005
#define RFMXNR_ATTR_DIGITAL_EDGE_TRIGGER_EDGE                                              0x00900006
#define RFMXNR_ATTR_IQ_POWER_EDGE_TRIGGER_SOURCE                                           0x00900007
#define RFMXNR_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL                                            0x00900008
#define RFMXNR_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE                                       0x00900fff
#define RFMXNR_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE                                            0x00900009
#define RFMXNR_ATTR_TRIGGER_DELAY                                                          0x0090000a
#define RFMXNR_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE                                        0x0090000b
#define RFMXNR_ATTR_TRIGGER_MINIMUM_QUIET_TIME_DURATION                                    0x0090000c
#define RFMXNR_ATTR_LINK_DIRECTION                                                         0x0090000e
#define RFMXNR_ATTR_GNODEB_CATEGORY                                                        0x0090005f
#define RFMXNR_ATTR_GNODEB_TYPE                                                            0x009000a0
#define RFMXNR_ATTR_TRANSMIT_ANTENNA_TO_ANALYZE                                            0x0090009b
#define RFMXNR_ATTR_POWER_CLASS                                                            0x0090009c
#define RFMXNR_ATTR_PIBY2BPSK_POWER_BOOST_ENABLED                                          0x0090009e
#define RFMXNR_ATTR_AUTO_RESOURCE_BLOCK_DETECTION_ENABLED                                  0x0090001f
#define RFMXNR_ATTR_AUTO_CELL_ID_DETECTION_ENABLED                                         0x0090008c
#define RFMXNR_ATTR_DOWNLINK_CHANNEL_CONFIGURATION_MODE                                    0x0090008e
#define RFMXNR_ATTR_AUTO_INCREMENT_CELL_ID_ENABLED                                         0x0090009f
#define RFMXNR_ATTR_DOWNLINK_TEST_MODEL_CELL_ID_MODE                                       0x0090011e
#define RFMXNR_ATTR_NUMBER_OF_SUBBLOCKS                                                    0x00900010
#define RFMXNR_ATTR_SUBBLOCK_FREQUENCY                                                     0x0090011f
#define RFMXNR_ATTR_SUBBLOCK_TRANSMIT_LO_FREQUENCY                                         0x00900060
#define RFMXNR_ATTR_PHASE_COMPENSATION_FREQUENCY                                           0x00900061
#define RFMXNR_ATTR_FREQUENCY_RANGE                                                        0x00900035
#define RFMXNR_ATTR_BAND                                                                   0x00900012
#define RFMXNR_ATTR_SUBBLOCK_ENDC_NOMINAL_SPACING_ADJUSTMENT                               0x00900103
#define RFMXNR_ATTR_CHANNEL_RASTER                                                         0x00900098
#define RFMXNR_ATTR_COMPONENT_CARRIER_SPACING_TYPE                                         0x00900013
#define RFMXNR_ATTR_COMPONENT_CARRIER_AT_CENTER_FREQUENCY                                  0x00900014
#define RFMXNR_ATTR_NUMBER_OF_COMPONENT_CARRIERS                                           0x00900015
#define RFMXNR_ATTR_DOWNLINK_TEST_MODEL                                                    0x00900100
#define RFMXNR_ATTR_DOWNLINK_TEST_MODEL_MODULATION_TYPE                                    0x0090011d
#define RFMXNR_ATTR_DOWNLINK_TEST_MODEL_DUPLEX_SCHEME                                      0x00900101
#define RFMXNR_ATTR_RATED_TRP                                                              0x009000a1
#define RFMXNR_ATTR_RATED_EIRP                                                             0x009000a2
#define RFMXNR_ATTR_COMPONENT_CARRIER_BANDWIDTH                                            0x00900016
#define RFMXNR_ATTR_COMPONENT_CARRIER_FREQUENCY                                            0x00900017
#define RFMXNR_ATTR_COMPONENT_CARRIER_ALLOCATED                                            0x00900118
#define RFMXNR_ATTR_COMPONENT_CARRIER_RADIO_ACCESS_TYPE                                    0x00900102
#define RFMXNR_ATTR_CELL_ID                                                                0x00900019
#define RFMXNR_ATTR_REFERENCE_GRID_SUBCARRIER_SPACING                                      0x00900062
#define RFMXNR_ATTR_REFERENCE_GRID_START                                                   0x00900063
#define RFMXNR_ATTR_REFERENCE_GRID_SIZE                                                    0x00900119
#define RFMXNR_ATTR_SUB_BAND_ALLOCATION                                                    0x0090003c
#define RFMXNR_ATTR_NUMBER_OF_BANDWIDTH_PARTS                                              0x0090003d
#define RFMXNR_ATTR_BANDWIDTH_PART_SUBCARRIER_SPACING                                      0x0090001b
#define RFMXNR_ATTR_BANDWIDTH_PART_CYCLIC_PREFIX_MODE                                      0x0090001a
#define RFMXNR_ATTR_GRID_START                                                             0x00900096
#define RFMXNR_ATTR_GRID_SIZE                                                              0x0090009a
#define RFMXNR_ATTR_BANDWIDTH_PART_RESOURCE_BLOCK_OFFSET                                   0x0090003e
#define RFMXNR_ATTR_BANDWIDTH_PART_NUMBER_OF_RESOURCE_BLOCKS                               0x0090003f
#define RFMXNR_ATTR_NUMBER_OF_USERS                                                        0x00900064
#define RFMXNR_ATTR_RNTI                                                                   0x00900065
#define RFMXNR_ATTR_NUMBER_OF_PUSCH_CONFIGURATIONS                                         0x0090004b
#define RFMXNR_ATTR_PUSCH_TRANSFORM_PRECODING_ENABLED                                      0x0090001e
#define RFMXNR_ATTR_PUSCH_NUMBER_OF_RESOURCE_BLOCK_CLUSTERS                                0x00900027
#define RFMXNR_ATTR_PUSCH_RESOURCE_BLOCK_OFFSET                                            0x00900028
#define RFMXNR_ATTR_PUSCH_NUMBER_OF_RESOURCE_BLOCKS                                        0x00900029
#define RFMXNR_ATTR_PUSCH_MODULATION_TYPE                                                  0x00900026
#define RFMXNR_ATTR_PUSCH_DMRS_RELEASE_VERSION                                             0x00900116
#define RFMXNR_ATTR_PUSCH_DMRS_ANTENNA_PORTS                                               0x00900041
#define RFMXNR_ATTR_PUSCH_DMRS_POWER_MODE                                                  0x00900051
#define RFMXNR_ATTR_PUSCH_DMRS_POWER                                                       0x00900030
#define RFMXNR_ATTR_PUSCH_DMRS_NUMBER_OF_CDM_GROUPS                                        0x00900042
#define RFMXNR_ATTR_PUSCH_DMRS_SCRAMBLING_ID_MODE                                          0x00900044
#define RFMXNR_ATTR_PUSCH_DMRS_SCRAMBLING_ID                                               0x00900045
#define RFMXNR_ATTR_PUSCH_DMRS_NSCID                                                       0x00900046
#define RFMXNR_ATTR_PUSCH_DMRS_GROUP_HOPPING_ENABLED                                       0x00900021
#define RFMXNR_ATTR_PUSCH_DMRS_SEQUENCE_HOPPING_ENABLED                                    0x00900022
#define RFMXNR_ATTR_PUSCH_DMRS_PUSCH_ID_MODE                                               0x00900047
#define RFMXNR_ATTR_PUSCH_DMRS_PUSCH_ID                                                    0x00900048
#define RFMXNR_ATTR_PUSCH_DMRS_CONFIGURATION_TYPE                                          0x00900031
#define RFMXNR_ATTR_PUSCH_MAPPING_TYPE                                                     0x00900034
#define RFMXNR_ATTR_PUSCH_DMRS_TYPE_A_POSITION                                             0x0090004a
#define RFMXNR_ATTR_PUSCH_DMRS_DURATION                                                    0x00900033
#define RFMXNR_ATTR_PUSCH_DMRS_ADDITIONAL_POSITIONS                                        0x00900032
#define RFMXNR_ATTR_PUSCH_PTRS_ENABLED                                                     0x00900055
#define RFMXNR_ATTR_PUSCH_PTRS_ANTENNA_PORTS                                               0x00900056
#define RFMXNR_ATTR_PUSCH_PTRS_POWER_MODE                                                  0x00900057
#define RFMXNR_ATTR_PUSCH_PTRS_POWER                                                       0x00900058
#define RFMXNR_ATTR_NUMBER_OF_PTRS_GROUPS                                                  0x0090005a
#define RFMXNR_ATTR_SAMPLES_PER_PTRS_GROUP                                                 0x0090005b
#define RFMXNR_ATTR_PUSCH_PTRS_TIME_DENSITY                                                0x0090005c
#define RFMXNR_ATTR_PUSCH_PTRS_FREQUENCY_DENSITY                                           0x0090005d
#define RFMXNR_ATTR_PUSCH_PTRS_RE_OFFSET                                                   0x0090005e
#define RFMXNR_ATTR_PUSCH_SLOT_ALLOCATION                                                  0x0090004c
#define RFMXNR_ATTR_PUSCH_SYMBOL_ALLOCATION                                                0x0090004d
#define RFMXNR_ATTR_NUMBER_OF_PDSCH_CONFIGURATIONS                                         0x00900090
#define RFMXNR_ATTR_PDSCH_NUMBER_OF_RESOURCE_BLOCK_CLUSTERS                                0x00900067
#define RFMXNR_ATTR_PDSCH_RESOURCE_BLOCK_OFFSET                                            0x00900068
#define RFMXNR_ATTR_PDSCH_NUMBER_OF_RESOURCE_BLOCKS                                        0x00900069
#define RFMXNR_ATTR_PDSCH_MODULATION_TYPE                                                  0x0090006a
#define RFMXNR_ATTR_PDSCH_DMRS_RELEASE_VERSION                                             0x00900117
#define RFMXNR_ATTR_PDSCH_DMRS_ANTENNA_PORTS                                               0x0090006b
#define RFMXNR_ATTR_PDSCH_DMRS_POWER_MODE                                                  0x0090006c
#define RFMXNR_ATTR_PDSCH_DMRS_POWER                                                       0x0090006d
#define RFMXNR_ATTR_PDSCH_DMRS_NUMBER_OF_CDM_GROUPS                                        0x0090006e
#define RFMXNR_ATTR_PDSCH_DMRS_SCRAMBLING_ID_MODE                                          0x0090006f
#define RFMXNR_ATTR_PDSCH_DMRS_SCRAMBLING_ID                                               0x00900070
#define RFMXNR_ATTR_PDSCH_DMRS_NSCID                                                       0x00900071
#define RFMXNR_ATTR_PDSCH_DMRS_CONFIGURATION_TYPE                                          0x00900074
#define RFMXNR_ATTR_PDSCH_MAPPING_TYPE                                                     0x00900075
#define RFMXNR_ATTR_PDSCH_DMRS_TYPE_A_POSITION                                             0x00900076
#define RFMXNR_ATTR_PDSCH_DMRS_DURATION                                                    0x00900077
#define RFMXNR_ATTR_PDSCH_DMRS_ADDITIONAL_POSITIONS                                        0x00900078
#define RFMXNR_ATTR_PDSCH_PTRS_ENABLED                                                     0x00900079
#define RFMXNR_ATTR_PDSCH_PTRS_ANTENNA_PORTS                                               0x0090007a
#define RFMXNR_ATTR_PDSCH_PTRS_POWER_MODE                                                  0x0090007b
#define RFMXNR_ATTR_EPRE_RATIO_PORT                                                        0x00900092
#define RFMXNR_ATTR_PDSCH_PTRS_POWER                                                       0x0090007c
#define RFMXNR_ATTR_PDSCH_PTRS_TIME_DENSITY                                                0x0090007d
#define RFMXNR_ATTR_PDSCH_PTRS_FREQUENCY_DENSITY                                           0x0090007e
#define RFMXNR_ATTR_PDSCH_PTRS_RE_OFFSET                                                   0x0090007f
#define RFMXNR_ATTR_PDSCH_SLOT_ALLOCATION                                                  0x00900080
#define RFMXNR_ATTR_PDSCH_SYMBOL_ALLOCATION                                                0x00900081
#define RFMXNR_ATTR_NUMBER_OF_CORESETS                                                     0x00900106
#define RFMXNR_ATTR_CORESET_SYMBOL_OFFSET                                                  0x00900107
#define RFMXNR_ATTR_CORESET_NUMBER_OF_SYMBOLS                                              0x00900108
#define RFMXNR_ATTR_CORESET_NUMBER_OF_RESOURCE_BLOCK_CLUSTERS                              0x00900109
#define RFMXNR_ATTR_CORESET_RESOURCE_BLOCK_OFFSET                                          0x0090010a
#define RFMXNR_ATTR_CORESET_NUMBER_OF_RESOURCE_BLOCKS                                      0x0090010b
#define RFMXNR_ATTR_CORESET_PRECODING_GRANULARITY                                          0x0090010c
#define RFMXNR_ATTR_CORESET_CCE_TO_REG_MAPPING_TYPE                                        0x0090010d
#define RFMXNR_ATTR_CORESET_REG_BUNDLE_SIZE                                                0x0090010e
#define RFMXNR_ATTR_CORESET_INTERLEAVER_SIZE                                               0x0090010f
#define RFMXNR_ATTR_CORESET_SHIFT_INDEX                                                    0x00900110
#define RFMXNR_ATTR_NUMBER_OF_PDCCH_CONFIGURATIONS                                         0x00900112
#define RFMXNR_ATTR_PDCCH_CCE_AGGREGATION_LEVEL                                            0x00900113
#define RFMXNR_ATTR_PDCCH_CCE_OFFSET                                                       0x00900114
#define RFMXNR_ATTR_PDCCH_SLOT_ALLOCATION                                                  0x00900115
#define RFMXNR_ATTR_SSB_ENABLED                                                            0x00900082
#define RFMXNR_ATTR_SSB_GRID_START                                                         0x0090011a
#define RFMXNR_ATTR_SSB_GRID_SIZE                                                          0x0090011b
#define RFMXNR_ATTR_SSB_CRB_OFFSET                                                         0x00900083
#define RFMXNR_ATTR_SUBCARRIER_SPACING_COMMON                                              0x00900099
#define RFMXNR_ATTR_SSB_SUBCARRIER_OFFSET                                                  0x00900084
#define RFMXNR_ATTR_SSB_PERIODICITY                                                        0x00900094
#define RFMXNR_ATTR_SSB_PATTERN                                                            0x00900085
#define RFMXNR_ATTR_SSB_ACTIVE_BLOCKS                                                      0x00900095
#define RFMXNR_ATTR_PSS_POWER                                                              0x00900086
#define RFMXNR_ATTR_SSS_POWER                                                              0x00900087
#define RFMXNR_ATTR_PBCH_POWER                                                             0x00900088
#define RFMXNR_ATTR_PBCH_DMRS_POWER                                                        0x00900089
#define RFMXNR_ATTR_SSB_HRF_INDEX                                                          0x00900120
#define RFMXNR_ATTR_NUMBER_OF_STEPS                                                        0x00900ff8
#define RFMXNR_ATTR_LIST_STEP_TIMER_DURATION                                               0x00900ff9
#define RFMXNR_ATTR_LIST_STEP_TIMER_UNIT                                                   0x00900ff6
#define RFMXNR_ATTR_LIST_STEP_TIMER_OFFSET                                                 0x00900ff7
#define RFMXNR_ATTR_MODACC_MEASUREMENT_ENABLED                                             0x00904000
#define RFMXNR_ATTR_MODACC_MULTICARRIER_FILTER_ENABLED                                     0x00904002
#define RFMXNR_ATTR_MODACC_FREQUENCY_ERROR_ESTIMATION                                      0x00904071
#define RFMXNR_ATTR_MODACC_SYMBOL_CLOCK_ERROR_ESTIMATION_ENABLED                           0x00904075
#define RFMXNR_ATTR_MODACC_IQ_IMPAIRMENTS_MODEL                                            0x00904082
#define RFMXNR_ATTR_MODACC_IQ_ORIGIN_OFFSET_ESTIMATION_ENABLED                             0x00904076
#define RFMXNR_ATTR_MODACC_IQ_MISMATCH_ESTIMATION_ENABLED                                  0x00904077
#define RFMXNR_ATTR_MODACC_IQ_GAIN_IMBALANCE_CORRECTION_ENABLED                            0x00904083
#define RFMXNR_ATTR_MODACC_IQ_QUADRATURE_ERROR_CORRECTION_ENABLED                          0x00904084
#define RFMXNR_ATTR_MODACC_IQ_TIMING_SKEW_CORRECTION_ENABLED                               0x00904085
#define RFMXNR_ATTR_MODACC_IQ_IMPAIRMENTS_PER_SUBCARRIER_ENABLED                           0x00904086
#define RFMXNR_ATTR_MODACC_MAGNITUDE_AND_PHASE_ERROR_ENABLED                               0x00904078
#define RFMXNR_ATTR_MODACC_EVM_REFERENCE_DATA_SYMBOLS_MODE                                 0x00904081
#define RFMXNR_ATTR_MODACC_SYNCHRONIZATION_MODE                                            0x00904004
#define RFMXNR_ATTR_MODACC_MEASUREMENT_LENGTH_UNIT                                         0x00904005
#define RFMXNR_ATTR_MODACC_MEASUREMENT_OFFSET                                              0x00904006
#define RFMXNR_ATTR_MODACC_MEASUREMENT_LENGTH                                              0x00904007
#define RFMXNR_ATTR_MODACC_SPECTRUM_INVERTED                                               0x00904008
#define RFMXNR_ATTR_MODACC_CHANNEL_ESTIMATION_TYPE                                         0x00904009
#define RFMXNR_ATTR_MODACC_PHASE_TRACKING_MODE                                             0x00904051
#define RFMXNR_ATTR_MODACC_TIMING_TRACKING_MODE                                            0x00904052
#define RFMXNR_ATTR_MODACC_PRE_FFT_ERROR_ESTIMATION_INTERVAL                               0x009040a0
#define RFMXNR_ATTR_MODACC_EVM_UNIT                                                        0x0090400a
#define RFMXNR_ATTR_MODACC_FFT_WINDOW_TYPE                                                 0x0090400b
#define RFMXNR_ATTR_MODACC_FFT_WINDOW_OFFSET                                               0x0090400c
#define RFMXNR_ATTR_MODACC_FFT_WINDOW_LENGTH                                               0x0090400d
#define RFMXNR_ATTR_MODACC_DC_SUBCARRIER_REMOVAL_ENABLED                                   0x0090002f
#define RFMXNR_ATTR_MODACC_COMMON_CLOCK_SOURCE_ENABLED                                     0x0090400e
#define RFMXNR_ATTR_MODACC_SPECTRAL_FLATNESS_CONDITION                                     0x00904010
#define RFMXNR_ATTR_MODACC_NOISE_COMPENSATION_ENABLED                                      0x00904092
#define RFMXNR_ATTR_MODACC_NOISE_COMPENSATION_INPUT_POWER_CHECK_ENABLED                    0x00904093
#define RFMXNR_ATTR_MODACC_NOISE_COMPENSATION_REFERENCE_LEVEL_COERCION_LIMIT               0x00904094
#define RFMXNR_ATTR_MODACC_MEASUREMENT_MODE                                                0x00904095
#define RFMXNR_ATTR_MODACC_COMPOSITE_RESULTS_INCLUDE_DMRS                                  0x00900038
#define RFMXNR_ATTR_MODACC_COMPOSITE_RESULTS_INCLUDE_PTRS                                  0x00900039
#define RFMXNR_ATTR_MODACC_AVERAGING_ENABLED                                               0x00904011
#define RFMXNR_ATTR_MODACC_AVERAGING_COUNT                                                 0x00904012
#define RFMXNR_ATTR_MODACC_AUTO_LEVEL_ALLOW_OVERFLOW                                       0x00904097
#define RFMXNR_ATTR_MODACC_SHORT_FRAME_ENABLED                                             0x0090409d
#define RFMXNR_ATTR_MODACC_SHORT_FRAME_LENGTH                                              0x0090409e
#define RFMXNR_ATTR_MODACC_SHORT_FRAME_LENGTH_UNIT                                         0x0090409f
#define RFMXNR_ATTR_MODACC_TRANSIENT_PERIOD_EVM_MODE                                       0x009040a3
#define RFMXNR_ATTR_MODACC_TRANSIENT_PERIOD                                                0x009040a4
#define RFMXNR_ATTR_MODACC_TRANSIENT_POWER_CHANGE_THRESHOLD                                0x009040a5
#define RFMXNR_ATTR_MODACC_ALL_TRACES_ENABLED                                              0x00904013
#define RFMXNR_ATTR_MODACC_NUMBER_OF_ANALYSIS_THREADS                                      0x00904014
#define RFMXNR_ATTR_MODACC_RESULTS_DETECTED_CELL_ID                                        0x0090403a
#define RFMXNR_ATTR_MODACC_RESULTS_COMPOSITE_RMS_EVM_MEAN                                  0x00904016
#define RFMXNR_ATTR_MODACC_RESULTS_COMPOSITE_PEAK_EVM_MAXIMUM                              0x00904017
#define RFMXNR_ATTR_MODACC_RESULTS_COMPOSITE_PEAK_EVM_BWP_INDEX                            0x00904054
#define RFMXNR_ATTR_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SLOT_INDEX                           0x0090401c
#define RFMXNR_ATTR_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SYMBOL_INDEX                         0x0090401d
#define RFMXNR_ATTR_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SUBCARRIER_INDEX                     0x0090401e
#define RFMXNR_ATTR_MODACC_RESULTS_COMPOSITE_RMS_MAGNITUDE_ERROR_MEAN                      0x00904018
#define RFMXNR_ATTR_MODACC_RESULTS_COMPOSITE_PEAK_MAGNITUDE_ERROR_MAXIMUM                  0x00904019
#define RFMXNR_ATTR_MODACC_RESULTS_COMPOSITE_RMS_PHASE_ERROR_MEAN                          0x0090401a
#define RFMXNR_ATTR_MODACC_RESULTS_COMPOSITE_PEAK_PHASE_ERROR_MAXIMUM                      0x0090401b
#define RFMXNR_ATTR_MODACC_RESULTS_SCH_SYMBOL_POWER_MEAN                                   0x0090406f
#define RFMXNR_ATTR_MODACC_RESULTS_SCH_DETECTED_MODULATION_TYPE                            0x00904070
#define RFMXNR_ATTR_MODACC_RESULTS_PUSCH_DATA_RMS_EVM_MEAN                                 0x0090401f
#define RFMXNR_ATTR_MODACC_RESULTS_PUSCH_DATA_PEAK_EVM_MAXIMUM                             0x00904020
#define RFMXNR_ATTR_MODACC_RESULTS_PUSCH_DMRS_RMS_EVM_MEAN                                 0x00904023
#define RFMXNR_ATTR_MODACC_RESULTS_PUSCH_DMRS_PEAK_EVM_MAXIMUM                             0x00904024
#define RFMXNR_ATTR_MODACC_RESULTS_PUSCH_PTRS_RMS_EVM_MEAN                                 0x00904048
#define RFMXNR_ATTR_MODACC_RESULTS_PUSCH_PTRS_PEAK_EVM_MAXIMUM                             0x00904049
#define RFMXNR_ATTR_MODACC_RESULTS_PUSCH_DATA_TRANSIENT_RMS_EVM_MEAN                       0x009040a6
#define RFMXNR_ATTR_MODACC_RESULTS_PUSCH_PEAK_PHASE_OFFSET_MAXIMUM                         0x009040a7
#define RFMXNR_ATTR_MODACC_RESULTS_PUSCH_PEAK_PHASE_OFFSET_SLOT_INDEX                      0x009040a8
#define RFMXNR_ATTR_MODACC_RESULTS_PDSCH_QPSK_RMS_EVM_MEAN                                 0x00904055
#define RFMXNR_ATTR_MODACC_RESULTS_PDSCH_16QAM_RMS_EVM_MEAN                                0x00904056
#define RFMXNR_ATTR_MODACC_RESULTS_PDSCH_64QAM_RMS_EVM_MEAN                                0x00904057
#define RFMXNR_ATTR_MODACC_RESULTS_PDSCH_256QAM_RMS_EVM_MEAN                               0x00904058
#define RFMXNR_ATTR_MODACC_RESULTS_PDSCH_1024QAM_RMS_EVM_MEAN                              0x00904073
#define RFMXNR_ATTR_MODACC_RESULTS_PDSCH_8PSK_RMS_EVM_MEAN                                 0x00904091
#define RFMXNR_ATTR_MODACC_RESULTS_PDSCH_DATA_RMS_EVM_MEAN                                 0x00904059
#define RFMXNR_ATTR_MODACC_RESULTS_PDSCH_DATA_PEAK_EVM_MAXIMUM                             0x0090405a
#define RFMXNR_ATTR_MODACC_RESULTS_PDSCH_DMRS_RMS_EVM_MEAN                                 0x0090405b
#define RFMXNR_ATTR_MODACC_RESULTS_PDSCH_DMRS_PEAK_EVM_MAXIMUM                             0x0090405c
#define RFMXNR_ATTR_MODACC_RESULTS_PDSCH_PTRS_RMS_EVM_MEAN                                 0x0090405d
#define RFMXNR_ATTR_MODACC_RESULTS_PDSCH_PTRS_PEAK_EVM_MAXIMUM                             0x0090405e
#define RFMXNR_ATTR_MODACC_RESULTS_PSS_RMS_EVM_MEAN                                        0x00904079
#define RFMXNR_ATTR_MODACC_RESULTS_PSS_PEAK_EVM_MAXIMUM                                    0x0090407a
#define RFMXNR_ATTR_MODACC_RESULTS_SSS_RMS_EVM_MEAN                                        0x0090407b
#define RFMXNR_ATTR_MODACC_RESULTS_SSS_PEAK_EVM_MAXIMUM                                    0x0090407c
#define RFMXNR_ATTR_MODACC_RESULTS_PBCH_DATA_RMS_EVM_MEAN                                  0x0090407d
#define RFMXNR_ATTR_MODACC_RESULTS_PBCH_DATA_PEAK_EVM_MAXIMUM                              0x0090407e
#define RFMXNR_ATTR_MODACC_RESULTS_PBCH_DMRS_RMS_EVM_MEAN                                  0x0090407f
#define RFMXNR_ATTR_MODACC_RESULTS_PBCH_DMRS_PEAK_EVM_MAXIMUM                              0x00904080
#define RFMXNR_ATTR_MODACC_RESULTS_IN_BAND_EMISSION_MARGIN                                 0x00904027
#define RFMXNR_ATTR_MODACC_RESULTS_SUBBLOCK_IN_BAND_EMISSION_MARGIN                        0x0090402c
#define RFMXNR_ATTR_MODACC_RESULTS_SPECTRAL_FLATNESS_MARGIN_SLOT_INDEX                     0x00904088
#define RFMXNR_ATTR_MODACC_RESULTS_SPECTRAL_FLATNESS_RANGE1_MAXIMUM_TO_RANGE1_MINIMUM      0x00904028
#define RFMXNR_ATTR_MODACC_RESULTS_SPECTRAL_FLATNESS_RANGE2_MAXIMUM_TO_RANGE2_MINIMUM      0x00904029
#define RFMXNR_ATTR_MODACC_RESULTS_SPECTRAL_FLATNESS_RANGE1_MAXIMUM_TO_RANGE2_MINIMUM      0x0090402a
#define RFMXNR_ATTR_MODACC_RESULTS_SPECTRAL_FLATNESS_RANGE2_MAXIMUM_TO_RANGE1_MINIMUM      0x0090402b
#define RFMXNR_ATTR_MODACC_RESULTS_SPECTRAL_FLATNESS_RANGE1_MAXIMUM                        0x00904089
#define RFMXNR_ATTR_MODACC_RESULTS_SPECTRAL_FLATNESS_RANGE1_MINIMUM                        0x0090408a
#define RFMXNR_ATTR_MODACC_RESULTS_SPECTRAL_FLATNESS_RANGE2_MAXIMUM                        0x0090408b
#define RFMXNR_ATTR_MODACC_RESULTS_SPECTRAL_FLATNESS_RANGE2_MINIMUM                        0x0090408c
#define RFMXNR_ATTR_MODACC_RESULTS_SPECTRAL_FLATNESS_RANGE1_MAXIMUM_SUBCARRIER_INDEX       0x0090408d
#define RFMXNR_ATTR_MODACC_RESULTS_SPECTRAL_FLATNESS_RANGE1_MINIMUM_SUBCARRIER_INDEX       0x0090408e
#define RFMXNR_ATTR_MODACC_RESULTS_SPECTRAL_FLATNESS_RANGE2_MAXIMUM_SUBCARRIER_INDEX       0x0090408f
#define RFMXNR_ATTR_MODACC_RESULTS_SPECTRAL_FLATNESS_RANGE2_MINIMUM_SUBCARRIER_INDEX       0x00904090
#define RFMXNR_ATTR_MODACC_RESULTS_COMPONENT_CARRIER_TIME_OFFSET_MEAN                      0x00904032
#define RFMXNR_ATTR_MODACC_RESULTS_COMPONENT_CARRIER_FREQUENCY_ERROR_MEAN                  0x0090402d
#define RFMXNR_ATTR_MODACC_RESULTS_COMPONENT_CARRIER_SLOT_FREQUENCY_ERROR_MAXIMUM          0x009040a1
#define RFMXNR_ATTR_MODACC_RESULTS_COMPONENT_CARRIER_SYMBOL_CLOCK_ERROR_MEAN               0x00904033
#define RFMXNR_ATTR_MODACC_RESULTS_COMPONENT_CARRIER_SLOT_IQ_ORIGIN_OFFSET_MAXIMUM         0x009040a2
#define RFMXNR_ATTR_MODACC_RESULTS_COMPONENT_CARRIER_IQ_ORIGIN_OFFSET_MEAN                 0x0090402e
#define RFMXNR_ATTR_MODACC_RESULTS_COMPONENT_CARRIER_IQ_GAIN_IMBALANCE_MEAN                0x0090402f
#define RFMXNR_ATTR_MODACC_RESULTS_COMPONENT_CARRIER_QUADRATURE_ERROR_MEAN                 0x00904030
#define RFMXNR_ATTR_MODACC_RESULTS_COMPONENT_CARRIER_IQ_TIMING_SKEW_MEAN                   0x00904031
#define RFMXNR_ATTR_MODACC_RESULTS_SUBBLOCK_LO_COMPONENT_CARRIER_INDEX                     0x00904062
#define RFMXNR_ATTR_MODACC_RESULTS_SUBBLOCK_LO_SUBCARRIER_INDEX                            0x00904063
#define RFMXNR_ATTR_MODACC_RESULTS_SUBBLOCK_IQ_ORIGIN_OFFSET_MEAN                          0x00904036
#define RFMXNR_ATTR_MODACC_RESULTS_NOISE_COMPENSATION_APPLIED                              0x00904096
#define RFMXNR_ATTR_ACP_MEASUREMENT_ENABLED                                                0x00901000
#define RFMXNR_ATTR_ACP_CHANNEL_CONFIGURATION_TYPE                                         0x0090104d
#define RFMXNR_ATTR_ACP_SUBBLOCK_INTEGRATION_BANDWIDTH                                     0x00901002
#define RFMXNR_ATTR_ACP_SUBBLOCK_OFFSET                                                    0x0090104e
#define RFMXNR_ATTR_ACP_COMPONENT_CARRIER_INTEGRATION_BANDWIDTH                            0x00901006
#define RFMXNR_ATTR_ACP_NUMBER_OF_UTRA_OFFSETS                                             0x00901009
#define RFMXNR_ATTR_ACP_NUMBER_OF_EUTRA_OFFSETS                                            0x0090100a
#define RFMXNR_ATTR_ACP_NUMBER_OF_NR_OFFSETS                                               0x0090100b
#define RFMXNR_ATTR_ACP_NUMBER_OF_ENDC_OFFSETS                                             0x00901043
#define RFMXNR_ATTR_ACP_OFFSET_CHANNEL_SPACING_ADJUSTMENT                                  0x00901045
#define RFMXNR_ATTR_ACP_NUMBER_OF_OFFSETS                                                  0x0090100c
#define RFMXNR_ATTR_ACP_OFFSET_FREQUENCY                                                   0x0090100e
#define RFMXNR_ATTR_ACP_OFFSET_SIDEBAND                                                    0x0090100f
#define RFMXNR_ATTR_ACP_OFFSET_INTEGRATION_BANDWIDTH                                       0x00901012
#define RFMXNR_ATTR_ACP_RBW_FILTER_AUTO_BANDWIDTH                                          0x00901016
#define RFMXNR_ATTR_ACP_RBW_FILTER_BANDWIDTH                                               0x00901017
#define RFMXNR_ATTR_ACP_RBW_FILTER_TYPE                                                    0x00901018
#define RFMXNR_ATTR_ACP_SWEEP_TIME_AUTO                                                    0x00901019
#define RFMXNR_ATTR_ACP_SWEEP_TIME_INTERVAL                                                0x0090101a
#define RFMXNR_ATTR_ACP_POWER_UNITS                                                        0x0090101b
#define RFMXNR_ATTR_ACP_MEASUREMENT_METHOD                                                 0x0090101c
#define RFMXNR_ATTR_ACP_NOISE_CALIBRATION_MODE                                             0x0090104c
#define RFMXNR_ATTR_ACP_NOISE_CALIBRATION_AVERAGING_AUTO                                   0x0090104b
#define RFMXNR_ATTR_ACP_NOISE_CALIBRATION_AVERAGING_COUNT                                  0x0090104a
#define RFMXNR_ATTR_ACP_NOISE_COMPENSATION_ENABLED                                         0x0090101d
#define RFMXNR_ATTR_ACP_NOISE_COMPENSATION_TYPE                                            0x00901049
#define RFMXNR_ATTR_ACP_AVERAGING_ENABLED                                                  0x0090101e
#define RFMXNR_ATTR_ACP_AVERAGING_COUNT                                                    0x0090101f
#define RFMXNR_ATTR_ACP_AVERAGING_TYPE                                                     0x00901021
#define RFMXNR_ATTR_ACP_MEASUREMENT_MODE                                                   0x00901048
#define RFMXNR_ATTR_ACP_FFT_WINDOW                                                         0x00901022
#define RFMXNR_ATTR_ACP_FFT_OVERLAP_MODE                                                   0x00901046
#define RFMXNR_ATTR_ACP_FFT_OVERLAP                                                        0x00901047
#define RFMXNR_ATTR_ACP_IF_OUTPUT_POWER_OFFSET_AUTO                                        0x00901024
#define RFMXNR_ATTR_ACP_NEAR_IF_OUTPUT_POWER_OFFSET                                        0x00901025
#define RFMXNR_ATTR_ACP_FAR_IF_OUTPUT_POWER_OFFSET                                         0x00901026
#define RFMXNR_ATTR_ACP_SEQUENTIAL_FFT_SIZE                                                0x00901027
#define RFMXNR_ATTR_ACP_AMPLITUDE_CORRECTION_TYPE                                          0x00901028
#define RFMXNR_ATTR_ACP_ALL_TRACES_ENABLED                                                 0x00901029
#define RFMXNR_ATTR_ACP_NUMBER_OF_ANALYSIS_THREADS                                         0x0090102a
#define RFMXNR_ATTR_ACP_RESULTS_TOTAL_AGGREGATED_POWER                                     0x0090102c
#define RFMXNR_ATTR_ACP_RESULTS_SUBBLOCK_POWER                                             0x00901030
#define RFMXNR_ATTR_ACP_RESULTS_COMPONENT_CARRIER_ABSOLUTE_POWER                           0x00901033
#define RFMXNR_ATTR_ACP_RESULTS_COMPONENT_CARRIER_RELATIVE_POWER                           0x00901034
#define RFMXNR_ATTR_ACP_RESULTS_LOWER_OFFSET_ABSOLUTE_POWER                                0x0090103a
#define RFMXNR_ATTR_ACP_RESULTS_LOWER_OFFSET_RELATIVE_POWER                                0x0090103b
#define RFMXNR_ATTR_ACP_RESULTS_UPPER_OFFSET_ABSOLUTE_POWER                                0x00901041
#define RFMXNR_ATTR_ACP_RESULTS_UPPER_OFFSET_RELATIVE_POWER                                0x00901042
#define RFMXNR_ATTR_CHP_MEASUREMENT_ENABLED                                                0x00903000
#define RFMXNR_ATTR_CHP_SWEEP_TIME_AUTO                                                    0x00903002
#define RFMXNR_ATTR_CHP_SWEEP_TIME_INTERVAL                                                0x00903003
#define RFMXNR_ATTR_CHP_INTEGRATION_BANDWIDTH_TYPE                                         0x00903004
#define RFMXNR_ATTR_CHP_SUBBLOCK_INTEGRATION_BANDWIDTH                                     0x00903005
#define RFMXNR_ATTR_CHP_COMPONENT_CARRIER_INTEGRATION_BANDWIDTH                            0x00903006
#define RFMXNR_ATTR_CHP_RBW_FILTER_AUTO_BANDWIDTH                                          0x00903009
#define RFMXNR_ATTR_CHP_RBW_FILTER_BANDWIDTH                                               0x0090300a
#define RFMXNR_ATTR_CHP_RBW_FILTER_TYPE                                                    0x0090300b
#define RFMXNR_ATTR_CHP_NOISE_CALIBRATION_MODE                                             0x00903026
#define RFMXNR_ATTR_CHP_NOISE_CALIBRATION_AVERAGING_AUTO                                   0x00903025
#define RFMXNR_ATTR_CHP_NOISE_CALIBRATION_AVERAGING_COUNT                                  0x00903024
#define RFMXNR_ATTR_CHP_NOISE_COMPENSATION_ENABLED                                         0x00903022
#define RFMXNR_ATTR_CHP_NOISE_COMPENSATION_TYPE                                            0x00903023
#define RFMXNR_ATTR_CHP_AVERAGING_ENABLED                                                  0x0090300d
#define RFMXNR_ATTR_CHP_AVERAGING_COUNT                                                    0x0090300e
#define RFMXNR_ATTR_CHP_AVERAGING_TYPE                                                     0x00903010
#define RFMXNR_ATTR_CHP_MEASUREMENT_MODE                                                   0x00903021
#define RFMXNR_ATTR_CHP_FFT_WINDOW                                                         0x00903011
#define RFMXNR_ATTR_CHP_AMPLITUDE_CORRECTION_TYPE                                          0x00903012
#define RFMXNR_ATTR_CHP_ALL_TRACES_ENABLED                                                 0x00903013
#define RFMXNR_ATTR_CHP_NUMBER_OF_ANALYSIS_THREADS                                         0x00903014
#define RFMXNR_ATTR_CHP_RESULTS_TOTAL_AGGREGATED_POWER                                     0x00903016
#define RFMXNR_ATTR_CHP_RESULTS_SUBBLOCK_POWER                                             0x0090301a
#define RFMXNR_ATTR_CHP_RESULTS_COMPONENT_CARRIER_ABSOLUTE_POWER                           0x0090301d
#define RFMXNR_ATTR_CHP_RESULTS_COMPONENT_CARRIER_RELATIVE_POWER                           0x0090301f
#define RFMXNR_ATTR_OBW_MEASUREMENT_ENABLED                                                0x00906000
#define RFMXNR_ATTR_OBW_SPAN_AUTO                                                          0x0090601a
#define RFMXNR_ATTR_OBW_SPAN                                                               0x00906003
#define RFMXNR_ATTR_OBW_RBW_FILTER_AUTO_BANDWIDTH                                          0x00906006
#define RFMXNR_ATTR_OBW_RBW_FILTER_BANDWIDTH                                               0x00906007
#define RFMXNR_ATTR_OBW_RBW_FILTER_TYPE                                                    0x00906008
#define RFMXNR_ATTR_OBW_SWEEP_TIME_AUTO                                                    0x00906009
#define RFMXNR_ATTR_OBW_SWEEP_TIME_INTERVAL                                                0x0090600a
#define RFMXNR_ATTR_OBW_AVERAGING_ENABLED                                                  0x0090600b
#define RFMXNR_ATTR_OBW_AVERAGING_COUNT                                                    0x0090600c
#define RFMXNR_ATTR_OBW_AVERAGING_TYPE                                                     0x0090600e
#define RFMXNR_ATTR_OBW_FFT_WINDOW                                                         0x0090600f
#define RFMXNR_ATTR_OBW_AMPLITUDE_CORRECTION_TYPE                                          0x00906011
#define RFMXNR_ATTR_OBW_ALL_TRACES_ENABLED                                                 0x00906012
#define RFMXNR_ATTR_OBW_NUMBER_OF_ANALYSIS_THREADS                                         0x00906013
#define RFMXNR_ATTR_OBW_RESULTS_OCCUPIED_BANDWIDTH                                         0x00906015
#define RFMXNR_ATTR_OBW_RESULTS_ABSOLUTE_POWER                                             0x00906016
#define RFMXNR_ATTR_OBW_RESULTS_START_FREQUENCY                                            0x00906017
#define RFMXNR_ATTR_OBW_RESULTS_STOP_FREQUENCY                                             0x00906018
#define RFMXNR_ATTR_SEM_MEASUREMENT_ENABLED                                                0x00908000
#define RFMXNR_ATTR_SEM_UPLINK_MASK_TYPE                                                   0x00908002
#define RFMXNR_ATTR_SEM_DOWNLINK_MASK_TYPE                                                 0x00908038
#define RFMXNR_ATTR_SEM_DELTA_F_MAXIMUM                                                    0x00908039
#define RFMXNR_ATTR_SEM_SUBBLOCK_INTEGRATION_BANDWIDTH                                     0x00908003
#define RFMXNR_ATTR_SEM_SUBBLOCK_AGGREGATED_CHANNEL_BANDWIDTH                              0x00908004
#define RFMXNR_ATTR_SEM_COMPONENT_CARRIER_INTEGRATION_BANDWIDTH                            0x00908005
#define RFMXNR_ATTR_SEM_COMPONENT_CARRIER_RATED_OUTPUT_POWER                               0x0090803a
#define RFMXNR_ATTR_SEM_NUMBER_OF_OFFSETS                                                  0x00908006
#define RFMXNR_ATTR_SEM_OFFSET_START_FREQUENCY                                             0x00908007
#define RFMXNR_ATTR_SEM_OFFSET_STOP_FREQUENCY                                              0x00908008
#define RFMXNR_ATTR_SEM_OFFSET_SIDEBAND                                                    0x00908009
#define RFMXNR_ATTR_SEM_OFFSET_RBW_FILTER_BANDWIDTH                                        0x0090800a
#define RFMXNR_ATTR_SEM_OFFSET_RBW_FILTER_TYPE                                             0x0090800b
#define RFMXNR_ATTR_SEM_OFFSET_BANDWIDTH_INTEGRAL                                          0x0090800c
#define RFMXNR_ATTR_SEM_OFFSET_LIMIT_FAIL_MASK                                             0x0090800d
#define RFMXNR_ATTR_SEM_OFFSET_ABSOLUTE_LIMIT_START                                        0x0090800e
#define RFMXNR_ATTR_SEM_OFFSET_FREQUENCY_DEFINITION                                        0x00908042
#define RFMXNR_ATTR_SEM_OFFSET_ABSOLUTE_LIMIT_STOP                                         0x0090800f
#define RFMXNR_ATTR_SEM_OFFSET_RELATIVE_LIMIT_START                                        0x00908010
#define RFMXNR_ATTR_SEM_OFFSET_RELATIVE_LIMIT_STOP                                         0x00908011
#define RFMXNR_ATTR_SEM_SWEEP_TIME_AUTO                                                    0x00908012
#define RFMXNR_ATTR_SEM_SWEEP_TIME_INTERVAL                                                0x00908013
#define RFMXNR_ATTR_SEM_AVERAGING_ENABLED                                                  0x00908014
#define RFMXNR_ATTR_SEM_AVERAGING_COUNT                                                    0x00908015
#define RFMXNR_ATTR_SEM_AVERAGING_TYPE                                                     0x00908016
#define RFMXNR_ATTR_SEM_FFT_WINDOW                                                         0x00908040
#define RFMXNR_ATTR_SEM_AMPLITUDE_CORRECTION_TYPE                                          0x00908017
#define RFMXNR_ATTR_SEM_ALL_TRACES_ENABLED                                                 0x00908018
#define RFMXNR_ATTR_SEM_NUMBER_OF_ANALYSIS_THREADS                                         0x00908019
#define RFMXNR_ATTR_SEM_RESULTS_TOTAL_AGGREGATED_POWER                                     0x0090801b
#define RFMXNR_ATTR_SEM_RESULTS_MEASUREMENT_STATUS                                         0x0090801c
#define RFMXNR_ATTR_SEM_RESULTS_SUBBLOCK_POWER                                             0x0090801f
#define RFMXNR_ATTR_SEM_RESULTS_COMPONENT_CARRIER_ABSOLUTE_INTEGRATED_POWER                0x00908020
#define RFMXNR_ATTR_SEM_RESULTS_COMPONENT_CARRIER_RELATIVE_INTEGRATED_POWER                0x00908021
#define RFMXNR_ATTR_SEM_RESULTS_COMPONENT_CARRIER_ABSOLUTE_PEAK_POWER                      0x00908022
#define RFMXNR_ATTR_SEM_RESULTS_COMPONENT_CARRIER_PEAK_FREQUENCY                           0x00908023
#define RFMXNR_ATTR_SEM_RESULTS_LOWER_OFFSET_MEASUREMENT_STATUS                            0x00908024
#define RFMXNR_ATTR_SEM_RESULTS_LOWER_OFFSET_ABSOLUTE_INTEGRATED_POWER                     0x00908025
#define RFMXNR_ATTR_SEM_RESULTS_LOWER_OFFSET_RELATIVE_INTEGRATED_POWER                     0x00908026
#define RFMXNR_ATTR_SEM_RESULTS_LOWER_OFFSET_ABSOLUTE_PEAK_POWER                           0x00908027
#define RFMXNR_ATTR_SEM_RESULTS_LOWER_OFFSET_RELATIVE_PEAK_POWER                           0x00908028
#define RFMXNR_ATTR_SEM_RESULTS_LOWER_OFFSET_PEAK_FREQUENCY                                0x00908029
#define RFMXNR_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN                                        0x0090802a
#define RFMXNR_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_ABSOLUTE_POWER                         0x0090802b
#define RFMXNR_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_RELATIVE_POWER                         0x0090802c
#define RFMXNR_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_FREQUENCY                              0x0090802d
#define RFMXNR_ATTR_SEM_RESULTS_UPPER_OFFSET_MEASUREMENT_STATUS                            0x0090802e
#define RFMXNR_ATTR_SEM_RESULTS_UPPER_OFFSET_ABSOLUTE_INTEGRATED_POWER                     0x0090802f
#define RFMXNR_ATTR_SEM_RESULTS_UPPER_OFFSET_RELATIVE_INTEGRATED_POWER                     0x00908030
#define RFMXNR_ATTR_SEM_RESULTS_UPPER_OFFSET_ABSOLUTE_PEAK_POWER                           0x00908031
#define RFMXNR_ATTR_SEM_RESULTS_UPPER_OFFSET_RELATIVE_PEAK_POWER                           0x00908032
#define RFMXNR_ATTR_SEM_RESULTS_UPPER_OFFSET_PEAK_FREQUENCY                                0x00908033
#define RFMXNR_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN                                        0x00908034
#define RFMXNR_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_ABSOLUTE_POWER                         0x00908035
#define RFMXNR_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_RELATIVE_POWER                         0x00908036
#define RFMXNR_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_FREQUENCY                              0x00908037
#define RFMXNR_ATTR_TXP_MEASUREMENT_ENABLED                                                0x00907000
#define RFMXNR_ATTR_TXP_MEASUREMENT_OFFSET                                                 0x00907002
#define RFMXNR_ATTR_TXP_MEASUREMENT_INTERVAL                                               0x00907003
#define RFMXNR_ATTR_TXP_AVERAGING_ENABLED                                                  0x00907004
#define RFMXNR_ATTR_TXP_AVERAGING_COUNT                                                    0x00907005
#define RFMXNR_ATTR_TXP_ALL_TRACES_ENABLED                                                 0x00907007
#define RFMXNR_ATTR_TXP_NUMBER_OF_ANALYSIS_THREADS                                         0x00907008
#define RFMXNR_ATTR_TXP_RESULTS_AVERAGE_POWER_MEAN                                         0x0090700a
#define RFMXNR_ATTR_TXP_RESULTS_PEAK_POWER_MAXIMUM                                         0x0090700b
#define RFMXNR_ATTR_PVT_MEASUREMENT_ENABLED                                                0x00909000
#define RFMXNR_ATTR_PVT_MEASUREMENT_INTERVAL_AUTO                                          0x00909014
#define RFMXNR_ATTR_PVT_MEASUREMENT_INTERVAL                                               0x00909015
#define RFMXNR_ATTR_PVT_MEASUREMENT_METHOD                                                 0x00909002
#define RFMXNR_ATTR_PVT_AVERAGING_ENABLED                                                  0x00909003
#define RFMXNR_ATTR_PVT_AVERAGING_COUNT                                                    0x00909004
#define RFMXNR_ATTR_PVT_AVERAGING_TYPE                                                     0x00909005
#define RFMXNR_ATTR_PVT_OFF_POWER_EXCLUSION_BEFORE                                         0x00909007
#define RFMXNR_ATTR_PVT_OFF_POWER_EXCLUSION_AFTER                                          0x00909008
#define RFMXNR_ATTR_PVT_ALL_TRACES_ENABLED                                                 0x00909009
#define RFMXNR_ATTR_PVT_NUMBER_OF_ANALYSIS_THREADS                                         0x0090900b
#define RFMXNR_ATTR_PVT_RESULTS_MEASUREMENT_STATUS                                         0x0090900c
#define RFMXNR_ATTR_PVT_RESULTS_ABSOLUTE_OFF_POWER_BEFORE                                  0x0090900d
#define RFMXNR_ATTR_PVT_RESULTS_ABSOLUTE_OFF_POWER_AFTER                                   0x0090900e
#define RFMXNR_ATTR_PVT_RESULTS_ABSOLUTE_ON_POWER                                          0x0090900f
#define RFMXNR_ATTR_PVT_RESULTS_BURST_WIDTH                                                0x00909010
#define RFMXNR_ATTR_PVT_RESULTS_PEAK_WINDOWED_OFF_POWER                                    0x00909016
#define RFMXNR_ATTR_PVT_RESULTS_PEAK_WINDOWED_OFF_POWER_MARGIN                             0x00909017
#define RFMXNR_ATTR_PVT_RESULTS_PEAK_WINDOWED_OFF_POWER_TIME                               0x00909018
#define RFMXNR_ATTR_ACQUISITION_BANDWIDTH_OPTIMIZATION_ENABLED                             0x0090d001
#define RFMXNR_ATTR_TRANSMITTER_ARCHITECTURE                                               0x0090043b
#define RFMXNR_ATTR_PHASE_COMPENSATION                                                     0x0090043d
#define RFMXNR_ATTR_REFERENCE_GRID_ALIGNMENT_MODE                                          0x00900037
#define RFMXNR_ATTR_GRID_SIZE_MODE                                                         0x0090011c
#define RFMXNR_ATTR_LIMITED_CONFIGURATION_CHANGE                                           0x0090d002
#define RFMXNR_ATTR_RESULT_FETCH_TIMEOUT                                                   0x0090c000

// Values for RFMXNR_ATTR_TRIGGER_TYPE
#define RFMXNR_VAL_TRIGGER_TYPE_NONE                                                              0
#define RFMXNR_VAL_TRIGGER_TYPE_DIGITAL_EDGE                                                      1
#define RFMXNR_VAL_TRIGGER_TYPE_IQ_POWER_EDGE                                                     2
#define RFMXNR_VAL_TRIGGER_TYPE_SOFTWARE                                                          3

// Values for RFMXNR_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE
#define RFMXNR_VAL_PFI0_STR                                                                       "PFI0"
#define RFMXNR_VAL_PFI1_STR                                                                       "PFI1"
#define RFMXNR_VAL_PXI_TRIG0_STR                                                                  "PXI_Trig0"
#define RFMXNR_VAL_PXI_TRIG1_STR                                                                  "PXI_Trig1"
#define RFMXNR_VAL_PXI_TRIG2_STR                                                                  "PXI_Trig2"
#define RFMXNR_VAL_PXI_TRIG3_STR                                                                  "PXI_Trig3"
#define RFMXNR_VAL_PXI_TRIG4_STR                                                                  "PXI_Trig4"
#define RFMXNR_VAL_PXI_TRIG5_STR                                                                  "PXI_Trig5"
#define RFMXNR_VAL_PXI_TRIG6_STR                                                                  "PXI_Trig6"
#define RFMXNR_VAL_PXI_TRIG7_STR                                                                  "PXI_Trig7"
#define RFMXNR_VAL_PXI_STAR_STR                                                                   "PXI_STAR"
#define RFMXNR_VAL_PXIE_DSTARB_STR                                                                "PXIe_DStarB"
#define RFMXNR_VAL_TIMER_EVENT_STR                                                                "TimerEvent"

// Values for RFMXNR_ATTR_DIGITAL_EDGE_TRIGGER_EDGE
#define RFMXNR_VAL_DIGITAL_EDGE_RISING_EDGE                                                       0
#define RFMXNR_VAL_DIGITAL_EDGE_FALLING_EDGE                                                      1

// Values for RFMXNR_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE
#define RFMXNR_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE                                      0
#define RFMXNR_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_ABSOLUTE                                      1

// Values for RFMXNR_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE
#define RFMXNR_VAL_IQ_POWER_EDGE_RISING_SLOPE                                                     0
#define RFMXNR_VAL_IQ_POWER_EDGE_FALLING_SLOPE                                                    1

// Values for RFMXNR_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE
#define RFMXNR_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_MANUAL                                         0
#define RFMXNR_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO                                           1

// Values for RFMXNR_ATTR_LINK_DIRECTION
#define RFMXNR_VAL_LINK_DIRECTION_DOWNLINK                                                        0
#define RFMXNR_VAL_LINK_DIRECTION_UPLINK                                                          1

// Values for RFMXNR_ATTR_GNODEB_CATEGORY
#define RFMXNR_VAL_GNODEB_CATEGORY_WIDE_AREA_BASE_STATION_CATEGORY_A                              0
#define RFMXNR_VAL_GNODEB_CATEGORY_WIDE_AREA_BASE_STATION_CATEGORY_B_OPTION1                      1
#define RFMXNR_VAL_GNODEB_CATEGORY_WIDE_AREA_BASE_STATION_CATEGORY_B_OPTION2                      2
#define RFMXNR_VAL_GNODEB_CATEGORY_LOCAL_AREA_BASE_STATION                                        3
#define RFMXNR_VAL_GNODEB_CATEGORY_MEDIUM_RANGE_BASE_STATION                                      5
#define RFMXNR_VAL_GNODEB_CATEGORY_FR2_CATEGORY_A                                                 6
#define RFMXNR_VAL_GNODEB_CATEGORY_FR2_CATEGORY_B                                                 7

// Values for RFMXNR_ATTR_GNODEB_TYPE
#define RFMXNR_VAL_GNODEB_TYPE_1C                                                                 0
#define RFMXNR_VAL_GNODEB_TYPE_1H                                                                 1
#define RFMXNR_VAL_GNODEB_TYPE_1O                                                                 2
#define RFMXNR_VAL_GNODEB_TYPE_2O                                                                 3

// Values for RFMXNR_ATTR_PIBY2BPSK_POWER_BOOST_ENABLED
#define RFMXNR_VAL_PIBY2BPSK_POWER_BOOST_ENABLED_FALSE                                            0
#define RFMXNR_VAL_PIBY2BPSK_POWER_BOOST_ENABLED_TRUE                                             1

// Values for RFMXNR_ATTR_AUTO_RESOURCE_BLOCK_DETECTION_ENABLED
#define RFMXNR_VAL_AUTO_RESOURCE_BLOCK_DETECTION_ENABLED_FALSE                                    0
#define RFMXNR_VAL_AUTO_RESOURCE_BLOCK_DETECTION_ENABLED_TRUE                                     1

// Values for RFMXNR_ATTR_AUTO_CELL_ID_DETECTION_ENABLED
#define RFMXNR_VAL_AUTO_CELL_ID_DETECTION_ENABLED_FALSE                                           0
#define RFMXNR_VAL_AUTO_CELL_ID_DETECTION_ENABLED_TRUE                                            1

// Values for RFMXNR_ATTR_DOWNLINK_CHANNEL_CONFIGURATION_MODE
#define RFMXNR_VAL_DOWNLINK_CHANNEL_CONFIGURATION_MODE_USER_DEFINED                               1
#define RFMXNR_VAL_DOWNLINK_CHANNEL_CONFIGURATION_MODE_TEST_MODEL                                 2

// Values for RFMXNR_ATTR_AUTO_INCREMENT_CELL_ID_ENABLED
#define RFMXNR_VAL_AUTO_INCREMENT_CELL_ID_ENABLED_FALSE                                           0
#define RFMXNR_VAL_AUTO_INCREMENT_CELL_ID_ENABLED_TRUE                                            1

// Values for RFMXNR_ATTR_DOWNLINK_TEST_MODEL_CELL_ID_MODE
#define RFMXNR_VAL_DOWNLINK_TEST_MODEL_CELL_ID_MODE_AUTO                                          0
#define RFMXNR_VAL_DOWNLINK_TEST_MODEL_CELL_ID_MODE_MANUAL                                        1

// Values for RFMXNR_ATTR_FREQUENCY_RANGE
#define RFMXNR_VAL_FREQUENCY_RANGE_RANGE1                                                         0
#define RFMXNR_VAL_FREQUENCY_RANGE_RANGE2                                                         1

// Values for RFMXNR_ATTR_COMPONENT_CARRIER_SPACING_TYPE
#define RFMXNR_VAL_COMPONENT_CARRIER_SPACING_TYPE_NOMINAL                                         0
#define RFMXNR_VAL_COMPONENT_CARRIER_SPACING_TYPE_USER                                            2

// Values for RFMXNR_ATTR_DOWNLINK_TEST_MODEL
#define RFMXNR_VAL_DOWNLINK_TEST_MODEL_TM1_1                                                      0
#define RFMXNR_VAL_DOWNLINK_TEST_MODEL_TM1_2                                                      1
#define RFMXNR_VAL_DOWNLINK_TEST_MODEL_TM2                                                        2
#define RFMXNR_VAL_DOWNLINK_TEST_MODEL_TM2A                                                       3
#define RFMXNR_VAL_DOWNLINK_TEST_MODEL_TM3_1                                                      4
#define RFMXNR_VAL_DOWNLINK_TEST_MODEL_TM3_1A                                                     5
#define RFMXNR_VAL_DOWNLINK_TEST_MODEL_TM3_2                                                      6
#define RFMXNR_VAL_DOWNLINK_TEST_MODEL_TM3_3                                                      7
#define RFMXNR_VAL_DOWNLINK_TEST_MODEL_TM2B                                                       8
#define RFMXNR_VAL_DOWNLINK_TEST_MODEL_TM3_1B                                                     9

// Values for RFMXNR_ATTR_DOWNLINK_TEST_MODEL_MODULATION_TYPE
#define RFMXNR_VAL_DOWNLINK_TEST_MODEL_MODULATION_TYPE_Standard                                   0
#define RFMXNR_VAL_DOWNLINK_TEST_MODEL_MODULATION_TYPE_QPSK                                       1
#define RFMXNR_VAL_DOWNLINK_TEST_MODEL_MODULATION_TYPE_QAM16                                      2
#define RFMXNR_VAL_DOWNLINK_TEST_MODEL_MODULATION_TYPE_QAM64                                      3

// Values for RFMXNR_ATTR_DOWNLINK_TEST_MODEL_DUPLEX_SCHEME
#define RFMXNR_VAL_DOWNLINK_TEST_MODEL_DUPLEX_SCHEME_FDD                                          0
#define RFMXNR_VAL_DOWNLINK_TEST_MODEL_DUPLEX_SCHEME_TDD                                          1

// Values for RFMXNR_ATTR_COMPONENT_CARRIER_ALLOCATED
#define RFMXNR_VAL_COMPONENT_CARRIER_ALLOCATED_FALSE                                              0
#define RFMXNR_VAL_COMPONENT_CARRIER_ALLOCATED_TRUE                                               1

// Values for RFMXNR_ATTR_COMPONENT_CARRIER_RADIO_ACCESS_TYPE
#define RFMXNR_VAL_COMPONENT_CARRIER_RADIO_ACCESS_TYPE_NR                                         0
#define RFMXNR_VAL_COMPONENT_CARRIER_RADIO_ACCESS_TYPE_EUTRA                                      1

// Values for RFMXNR_ATTR_BANDWIDTH_PART_CYCLIC_PREFIX_MODE
#define RFMXNR_VAL_BANDWIDTH_PART_CYCLIC_PREFIX_MODE_NORMAL                                       0
#define RFMXNR_VAL_BANDWIDTH_PART_CYCLIC_PREFIX_MODE_EXTENDED                                     1

// Values for RFMXNR_ATTR_PUSCH_TRANSFORM_PRECODING_ENABLED
#define RFMXNR_VAL_PUSCH_TRANSFORM_PRECODING_ENABLED_FALSE                                        0
#define RFMXNR_VAL_PUSCH_TRANSFORM_PRECODING_ENABLED_TRUE                                         1

// Values for RFMXNR_ATTR_PUSCH_MODULATION_TYPE
#define RFMXNR_VAL_PUSCH_MODULATION_TYPE_PI_BY_2_BPSK                                             0
#define RFMXNR_VAL_PUSCH_MODULATION_TYPE_QPSK                                                     1
#define RFMXNR_VAL_PUSCH_MODULATION_TYPE_QAM16                                                    2
#define RFMXNR_VAL_PUSCH_MODULATION_TYPE_QAM64                                                    3
#define RFMXNR_VAL_PUSCH_MODULATION_TYPE_QAM256                                                   4
#define RFMXNR_VAL_PUSCH_MODULATION_TYPE_QAM1024                                                  5
#define RFMXNR_VAL_PUSCH_MODULATION_TYPE_PSK8                                                     100

// Values for RFMXNR_ATTR_PUSCH_DMRS_RELEASE_VERSION
#define RFMXNR_VAL_PUSCH_DMRS_RELEASE_VERSION_RELEASE15                                           0
#define RFMXNR_VAL_PUSCH_DMRS_RELEASE_VERSION_RELEASE16                                           1

// Values for RFMXNR_ATTR_PUSCH_DMRS_POWER_MODE
#define RFMXNR_VAL_PUSCH_DMRS_POWER_MODE_CDM_GROUPS                                               0
#define RFMXNR_VAL_PUSCH_DMRS_POWER_MODE_USER_DEFINED                                             1

// Values for RFMXNR_ATTR_PUSCH_DMRS_SCRAMBLING_ID_MODE
#define RFMXNR_VAL_PUSCH_DMRS_SCRAMBLING_ID_MODE_CELL_ID                                          0
#define RFMXNR_VAL_PUSCH_DMRS_SCRAMBLING_ID_MODE_USER_DEFINED                                     1

// Values for RFMXNR_ATTR_PUSCH_DMRS_GROUP_HOPPING_ENABLED
#define RFMXNR_VAL_PUSCH_DMRS_GROUP_HOPPING_ENABLED_FALSE                                         0
#define RFMXNR_VAL_PUSCH_DMRS_GROUP_HOPPING_ENABLED_TRUE                                          1

// Values for RFMXNR_ATTR_PUSCH_DMRS_SEQUENCE_HOPPING_ENABLED
#define RFMXNR_VAL_PUSCH_DMRS_SEQUENCE_HOPPING_ENABLED_FALSE                                      0
#define RFMXNR_VAL_PUSCH_DMRS_SEQUENCE_HOPPING_ENABLED_TRUE                                       1

// Values for RFMXNR_ATTR_PUSCH_DMRS_PUSCH_ID_MODE
#define RFMXNR_VAL_PUSCH_DMRS_PUSCH_ID_MODE_CELL_ID                                               0
#define RFMXNR_VAL_PUSCH_DMRS_PUSCH_ID_MODE_USER_DEFINED                                          1

// Values for RFMXNR_ATTR_PUSCH_DMRS_CONFIGURATION_TYPE
#define RFMXNR_VAL_PUSCH_DMRS_CONFIGURATION_TYPE_TYPE1                                            0
#define RFMXNR_VAL_PUSCH_DMRS_CONFIGURATION_TYPE_TYPE2                                            1

// Values for RFMXNR_ATTR_PUSCH_MAPPING_TYPE
#define RFMXNR_VAL_PUSCH_MAPPING_TYPE_TYPE_A                                                      0
#define RFMXNR_VAL_PUSCH_MAPPING_TYPE_TYPE_B                                                      1

// Values for RFMXNR_ATTR_PUSCH_DMRS_DURATION
#define RFMXNR_VAL_PUSCH_DMRS_DURATION_SINGLE_SYMBOL                                              1
#define RFMXNR_VAL_PUSCH_DMRS_DURATION_DOUBLE_SYMBOL                                              2

// Values for RFMXNR_ATTR_PUSCH_PTRS_ENABLED
#define RFMXNR_VAL_PUSCH_PTRS_ENABLED_FALSE                                                       0
#define RFMXNR_VAL_PUSCH_PTRS_ENABLED_TRUE                                                        1

// Values for RFMXNR_ATTR_PUSCH_PTRS_POWER_MODE
#define RFMXNR_VAL_PUSCH_PTRS_POWER_MODE_STANDARD                                                 0
#define RFMXNR_VAL_PUSCH_PTRS_POWER_MODE_USER_DEFINED                                             1

// Values for RFMXNR_ATTR_PDSCH_MODULATION_TYPE
#define RFMXNR_VAL_PDSCH_MODULATION_TYPE_QPSK                                                     1
#define RFMXNR_VAL_PDSCH_MODULATION_TYPE_QAM16                                                    2
#define RFMXNR_VAL_PDSCH_MODULATION_TYPE_QAM64                                                    3
#define RFMXNR_VAL_PDSCH_MODULATION_TYPE_QAM256                                                   4
#define RFMXNR_VAL_PDSCH_MODULATION_TYPE_QAM1024                                                  5
#define RFMXNR_VAL_PDSCH_MODULATION_TYPE_PSK8                                                     100

// Values for RFMXNR_ATTR_PDSCH_DMRS_RELEASE_VERSION
#define RFMXNR_VAL_PDSCH_DMRS_RELEASE_VERSION_RELEASE15                                           0
#define RFMXNR_VAL_PDSCH_DMRS_RELEASE_VERSION_RELEASE16                                           1

// Values for RFMXNR_ATTR_PDSCH_DMRS_POWER_MODE
#define RFMXNR_VAL_PDSCH_DMRS_POWER_MODE_CDM_GROUPS                                               0
#define RFMXNR_VAL_PDSCH_DMRS_POWER_MODE_USER_DEFINED                                             1

// Values for RFMXNR_ATTR_PDSCH_DMRS_SCRAMBLING_ID_MODE
#define RFMXNR_VAL_PDSCH_DMRS_SCRAMBLING_ID_MODE_CELL_ID                                          0
#define RFMXNR_VAL_PDSCH_DMRS_SCRAMBLING_ID_MODE_USER_DEFINED                                     1

// Values for RFMXNR_ATTR_PDSCH_DMRS_CONFIGURATION_TYPE
#define RFMXNR_VAL_PDSCH_DMRS_CONFIGURATION_TYPE_TYPE1                                            0
#define RFMXNR_VAL_PDSCH_DMRS_CONFIGURATION_TYPE_TYPE2                                            1

// Values for RFMXNR_ATTR_PDSCH_MAPPING_TYPE
#define RFMXNR_VAL_PDSCH_MAPPING_TYPE_TYPE_A                                                      0
#define RFMXNR_VAL_PDSCH_MAPPING_TYPE_TYPE_B                                                      1

// Values for RFMXNR_ATTR_PDSCH_DMRS_DURATION
#define RFMXNR_VAL_PDSCH_DMRS_DURATION_SINGLE_SYMBOL                                              1
#define RFMXNR_VAL_PDSCH_DMRS_DURATION_DOUBLE_SYMBOL                                              2

// Values for RFMXNR_ATTR_PDSCH_PTRS_ENABLED
#define RFMXNR_VAL_PDSCH_PTRS_ENABLED_FALSE                                                       0
#define RFMXNR_VAL_PDSCH_PTRS_ENABLED_TRUE                                                        1

// Values for RFMXNR_ATTR_PDSCH_PTRS_POWER_MODE
#define RFMXNR_VAL_PDSCH_PTRS_POWER_MODE_STANDARD                                                 0
#define RFMXNR_VAL_PDSCH_PTRS_POWER_MODE_USER_DEFINED                                             1

// Values for RFMXNR_ATTR_CORESET_PRECODING_GRANULARITY
#define RFMXNR_VAL_CORESET_PRECODING_GRANULARITY_SAME_AS_REG_BUNDLE                               0
#define RFMXNR_VAL_CORESET_PRECODING_GRANULARITY_ALL_CONTIGUOUS_RESOURCE_BLOCKS                   1

// Values for RFMXNR_ATTR_CORESET_CCE_TO_REG_MAPPING_TYPE
#define RFMXNR_VAL_CORESET_CCE_TO_REG_MAPPING_TYPE_NON_INTERLEAVED                                0
#define RFMXNR_VAL_CORESET_CCE_TO_REG_MAPPING_TYPE_INTERLEAVED                                    1

// Values for RFMXNR_ATTR_SSB_ENABLED
#define RFMXNR_VAL_SSB_ENABLED_FALSE                                                              0
#define RFMXNR_VAL_SSB_ENABLED_TRUE                                                               1

// Values for RFMXNR_ATTR_SSB_PATTERN
#define RFMXNR_VAL_SSB_PATTERN_CASE_A_UP_TO_3GHZ                                                  0
#define RFMXNR_VAL_SSB_PATTERN_CASE_A_3GHZ_TO_6GHZ                                                1
#define RFMXNR_VAL_SSB_PATTERN_CASE_B_UP_TO_3GHZ                                                  2
#define RFMXNR_VAL_SSB_PATTERN_CASE_B_3GHZ_TO_6GHZ                                                3
#define RFMXNR_VAL_SSB_PATTERN_CASE_C_UP_TO_3GHZ                                                  4
#define RFMXNR_VAL_SSB_PATTERN_CASE_C_3GHZ_TO_6GHZ                                                5
#define RFMXNR_VAL_SSB_PATTERN_CASE_D                                                             6
#define RFMXNR_VAL_SSB_PATTERN_CASE_E                                                             7

// Values for RFMXNR_ATTR_LIST_STEP_TIMER_UNIT
#define RFMXNR_VAL_LIST_STEP_TIMER_UNIT_SLOT                                                      1
#define RFMXNR_VAL_LIST_STEP_TIMER_UNIT_TIME                                                      6

// Values for RFMXNR_ATTR_MODACC_MULTICARRIER_FILTER_ENABLED
#define RFMXNR_VAL_MODACC_MULTICARRIER_FILTER_ENABLED_FALSE                                       0
#define RFMXNR_VAL_MODACC_MULTICARRIER_FILTER_ENABLED_TRUE                                        1

// Values for ModAccCalibrationDataValid
#define RFMXNR_VAL_MODACC_CALIBRATION_DATA_VALID_FALSE                                            0
#define RFMXNR_VAL_MODACC_CALIBRATION_DATA_VALID_TRUE                                             1

// Values for RFMXNR_ATTR_MODACC_FREQUENCY_ERROR_ESTIMATION
#define RFMXNR_VAL_MODACC_FREQUENCY_ERROR_ESTIMATION_DISABLED                                     0
#define RFMXNR_VAL_MODACC_FREQUENCY_ERROR_ESTIMATION_NORMAL                                       1
#define RFMXNR_VAL_MODACC_FREQUENCY_ERROR_ESTIMATION_WIDE                                         2

// Values for RFMXNR_ATTR_MODACC_SYMBOL_CLOCK_ERROR_ESTIMATION_ENABLED
#define RFMXNR_VAL_MODACC_SYMBOL_CLOCK_ERROR_ESTIMATION_ENABLED_FALSE                             0
#define RFMXNR_VAL_MODACC_SYMBOL_CLOCK_ERROR_ESTIMATION_ENABLED_TRUE                              1

// Values for RFMXNR_ATTR_MODACC_IQ_ORIGIN_OFFSET_ESTIMATION_ENABLED
#define RFMXNR_VAL_MODACC_IQ_ORIGIN_OFFSET_ESTIMATION_ENABLED_FALSE                               0
#define RFMXNR_VAL_MODACC_IQ_ORIGIN_OFFSET_ESTIMATION_ENABLED_TRUE                                1

// Values for RFMXNR_ATTR_MODACC_IQ_MISMATCH_ESTIMATION_ENABLED
#define RFMXNR_VAL_MODACC_IQ_MISMATCH_ESTIMATION_ENABLED_FALSE                                    0
#define RFMXNR_VAL_MODACC_IQ_MISMATCH_ESTIMATION_ENABLED_TRUE                                     1

// Values for RFMXNR_ATTR_MODACC_IQ_IMPAIRMENTS_MODEL
#define RFMXNR_VAL_MODACC_IQ_IMPAIRMENTS_MODEL_TX                                                 0
#define RFMXNR_VAL_MODACC_IQ_IMPAIRMENTS_MODEL_RX                                                 1

// Values for RFMXNR_ATTR_MODACC_IQ_GAIN_IMBALANCE_CORRECTION_ENABLED
#define RFMXNR_VAL_MODACC_IQ_GAIN_IMBALANCE_CORRECTION_ENABLED_FALSE                              0
#define RFMXNR_VAL_MODACC_IQ_GAIN_IMBALANCE_CORRECTION_ENABLED_TRUE                               1

// Values for RFMXNR_ATTR_MODACC_IQ_QUADRATURE_ERROR_CORRECTION_ENABLED
#define RFMXNR_VAL_MODACC_IQ_QUADRATURE_ERROR_CORRECTION_ENABLED_FALSE                            0
#define RFMXNR_VAL_MODACC_IQ_QUADRATURE_ERROR_CORRECTION_ENABLED_TRUE                             1

// Values for RFMXNR_ATTR_MODACC_IQ_TIMING_SKEW_CORRECTION_ENABLED
#define RFMXNR_VAL_MODACC_IQ_TIMING_SKEW_CORRECTION_ENABLED_FALSE                                 0
#define RFMXNR_VAL_MODACC_IQ_TIMING_SKEW_CORRECTION_ENABLED_TRUE                                  1

// Values for RFMXNR_ATTR_MODACC_IQ_IMPAIRMENTS_PER_SUBCARRIER_ENABLED
#define RFMXNR_VAL_MODACC_IQ_IMPAIRMENTS_PER_SUBCARRIER_ENABLED_FALSE                             0
#define RFMXNR_VAL_MODACC_IQ_IMPAIRMENTS_PER_SUBCARRIER_ENABLED_TRUE                              1

// Values for RFMXNR_ATTR_MODACC_MAGNITUDE_AND_PHASE_ERROR_ENABLED
#define RFMXNR_VAL_MODACC_MAGNITUDE_AND_PHASE_ERROR_ENABLED_FALSE                                 0
#define RFMXNR_VAL_MODACC_MAGNITUDE_AND_PHASE_ERROR_ENABLED_TRUE                                  1

// Values for RFMXNR_ATTR_MODACC_EVM_REFERENCE_DATA_SYMBOLS_MODE
#define RFMXNR_VAL_MODACC_EVM_REFERENCE_DATA_SYMBOLS_MODE_ACQUIRED_WAVEFORM                       0
#define RFMXNR_VAL_MODACC_EVM_REFERENCE_DATA_SYMBOLS_MODE_REFERENCE_WAVEFORM                      1

// Values for RFMXNR_ATTR_MODACC_SYNCHRONIZATION_MODE
#define RFMXNR_VAL_MODACC_SYNCHRONIZATION_MODE_SLOT                                               1
#define RFMXNR_VAL_MODACC_SYNCHRONIZATION_MODE_FRAME                                              5
#define RFMXNR_VAL_MODACC_SYNCHRONIZATION_MODE_SSB_START_FRAME                                    7

// Values for RFMXNR_ATTR_MODACC_MEASUREMENT_LENGTH_UNIT
#define RFMXNR_VAL_MODACC_MEASUREMENT_LENGTH_UNIT_SLOT                                            1
#define RFMXNR_VAL_MODACC_MEASUREMENT_LENGTH_UNIT_SUBFRAME                                        3
#define RFMXNR_VAL_MODACC_MEASUREMENT_LENGTH_UNIT_TIME                                            6

// Values for RFMXNR_ATTR_MODACC_SPECTRUM_INVERTED
#define RFMXNR_VAL_MODACC_SPECTRUM_INVERTED_FALSE                                                 0
#define RFMXNR_VAL_MODACC_SPECTRUM_INVERTED_TRUE                                                  1

// Values for RFMXNR_ATTR_MODACC_CHANNEL_ESTIMATION_TYPE
#define RFMXNR_VAL_MODACC_CHANNEL_ESTIMATION_TYPE_REFERENCE                                       0
#define RFMXNR_VAL_MODACC_CHANNEL_ESTIMATION_TYPE_REFERENCE_AND_DATA                              1

// Values for RFMXNR_ATTR_MODACC_PHASE_TRACKING_MODE
#define RFMXNR_VAL_MODACC_PHASE_TRACKING_MODE_DISABLED                                            0
#define RFMXNR_VAL_MODACC_PHASE_TRACKING_MODE_REFERENCE_AND_DATA                                  1
#define RFMXNR_VAL_MODACC_PHASE_TRACKING_MODE_PTRS                                                2

// Values for RFMXNR_ATTR_MODACC_TIMING_TRACKING_MODE
#define RFMXNR_VAL_MODACC_TIMING_TRACKING_MODE_DISABLED                                           0
#define RFMXNR_VAL_MODACC_TIMING_TRACKING_MODE_REFERENCE_AND_DATA                                 1

// Values for RFMXNR_ATTR_MODACC_PRE_FFT_ERROR_ESTIMATION_INTERVAL
#define RFMXNR_VAL_MODACC_PRE_FFT_ERROR_ESTIMATION_INTERVAL_SLOT                                  0
#define RFMXNR_VAL_MODACC_PRE_FFT_ERROR_ESTIMATION_INTERVAL_MEASUREMENT_LENGTH                    1

// Values for RFMXNR_ATTR_MODACC_EVM_UNIT
#define RFMXNR_VAL_MODACC_EVM_UNIT_PERCENTAGE                                                     0
#define RFMXNR_VAL_MODACC_EVM_UNIT_DB                                                             1

// Values for RFMXNR_ATTR_MODACC_FFT_WINDOW_TYPE
#define RFMXNR_VAL_MODACC_FFT_WINDOW_TYPE_3GPP                                                    0
#define RFMXNR_VAL_MODACC_FFT_WINDOW_TYPE_CUSTOM                                                  1

// Values for RFMXNR_ATTR_MODACC_DC_SUBCARRIER_REMOVAL_ENABLED
#define RFMXNR_VAL_MODACC_DC_SUBCARRIER_REMOVAL_ENABLED_FALSE                                     0
#define RFMXNR_VAL_MODACC_DC_SUBCARRIER_REMOVAL_ENABLED_TRUE                                      1

// Values for RFMXNR_ATTR_MODACC_COMMON_CLOCK_SOURCE_ENABLED
#define RFMXNR_VAL_MODACC_COMMON_CLOCK_SOURCE_ENABLED_FALSE                                       0
#define RFMXNR_VAL_MODACC_COMMON_CLOCK_SOURCE_ENABLED_TRUE                                        1

// Values for RFMXNR_ATTR_MODACC_SPECTRAL_FLATNESS_CONDITION
#define RFMXNR_VAL_MODACC_SPECTRAL_FLATNESS_CONDITION_NORMAL                                      0
#define RFMXNR_VAL_MODACC_SPECTRAL_FLATNESS_CONDITION_EXTREME                                     1

// Values for RFMXNR_ATTR_MODACC_NOISE_COMPENSATION_ENABLED
#define RFMXNR_VAL_MODACC_NOISE_COMPENSATION_ENABLED_FALSE                                        0
#define RFMXNR_VAL_MODACC_NOISE_COMPENSATION_ENABLED_TRUE                                         1

// Values for RFMXNR_ATTR_MODACC_NOISE_COMPENSATION_INPUT_POWER_CHECK_ENABLED
#define RFMXNR_VAL_MODACC_NOISE_COMPENSATION_INPUT_POWER_CHECK_ENABLED_FALSE                      0
#define RFMXNR_VAL_MODACC_NOISE_COMPENSATION_INPUT_POWER_CHECK_ENABLED_TRUE                       1

// Values for RFMXNR_ATTR_MODACC_MEASUREMENT_MODE
#define RFMXNR_VAL_MODACC_MEASUREMENT_MODE_MEASURE                                                0
#define RFMXNR_VAL_MODACC_MEASUREMENT_MODE_CALIBRATE_NOISE_FLOOR                                  1

// Values for RFMXNR_ATTR_MODACC_COMPOSITE_RESULTS_INCLUDE_DMRS
#define RFMXNR_VAL_MODACC_COMPOSITE_RESULTS_INCLUDE_DMRS_FALSE                                    0
#define RFMXNR_VAL_MODACC_COMPOSITE_RESULTS_INCLUDE_DMRS_TRUE                                     1

// Values for RFMXNR_ATTR_MODACC_COMPOSITE_RESULTS_INCLUDE_PTRS
#define RFMXNR_VAL_MODACC_COMPOSITE_RESULTS_INCLUDE_PTRS_FALSE                                    0
#define RFMXNR_VAL_MODACC_COMPOSITE_RESULTS_INCLUDE_PTRS_TRUE                                     1

// Values for RFMXNR_ATTR_MODACC_AVERAGING_ENABLED
#define RFMXNR_VAL_MODACC_AVERAGING_ENABLED_FALSE                                                 0
#define RFMXNR_VAL_MODACC_AVERAGING_ENABLED_TRUE                                                  1

// Values for RFMXNR_ATTR_MODACC_AUTO_LEVEL_ALLOW_OVERFLOW
#define RFMXNR_VAL_MODACC_ATUO_LEVEL_ALLOW_OVERFLOW_FALSE                                         0
#define RFMXNR_VAL_MODACC_ATUO_LEVEL_ALLOW_OVERFLOW_TRUE                                          1

// Values for RFMXNR_ATTR_MODACC_RESULTS_NOISE_COMPENSATION_APPLIED
#define RFMXNR_VAL_MODACC_RESULTS_NOISE_COMPENSATION_APPLIED_FALSE                                0
#define RFMXNR_VAL_MODACC_RESULTS_NOISE_COMPENSATION_APPLIED_TRUE                                 1

// Values for RFMXNR_ATTR_ACP_CHANNEL_CONFIGURATION_TYPE
#define RFMXNR_VAL_ACP_CHANNEL_CONFIGURATION_TYPE_STANDARD                                        0
#define RFMXNR_VAL_ACP_CHANNEL_CONFIGURATION_TYPE_CUSTOM                                          1
#define RFMXNR_VAL_ACP_CHANNEL_CONFIGURATION_TYPE_NS_29                                           2

// Values for RFMXNR_ATTR_MODACC_SHORT_FRAME_ENABLED
#define RFMXNR_VAL_MODACC_SHORT_FRAME_ENABLED_FALSE                                               0
#define RFMXNR_VAL_MODACC_SHORT_FRAME_ENABLED_TRUE                                                1

// Values for RFMXNR_ATTR_MODACC_SHORT_FRAME_LENGTH_UNIT
#define RFMXNR_VAL_MODACC_SHORT_FRAME_LENGTH_UNIT_SLOT                                            1
#define RFMXNR_VAL_MODACC_SHORT_FRAME_LENGTH_UNIT_SUBFRAME                                        3
#define RFMXNR_VAL_MODACC_SHORT_FRAME_LENGTH_UNIT_TIME                                            6

// Values for RFMXNR_ATTR_MODACC_TRANSIENT_PERIOD_EVM_MODE
#define RFMXNR_VAL_MODACC_TRANSIENT_PERIOD_EVM_MODE_DISABLED                                      0
#define RFMXNR_VAL_MODACC_TRANSIENT_PERIOD_EVM_MODE_EXCLUDE                                       1
#define RFMXNR_VAL_MODACC_TRANSIENT_PERIOD_EVM_MODE_INCLUDE                                       2

// Values for RFMXNR_ATTR_MODACC_RESULTS_SCH_DETECTED_MODULATION_TYPE
#define RFMXNR_VAL_MODACC_RESULTS_SCH_DETECTED_MODULATION_TYPE_PI_BY_2_BPSK                       0
#define RFMXNR_VAL_MODACC_RESULTS_SCH_DETECTED_MODULATION_TYPE_QPSK                               1
#define RFMXNR_VAL_MODACC_RESULTS_SCH_DETECTED_MODULATION_TYPE_QAM16                              2
#define RFMXNR_VAL_MODACC_RESULTS_SCH_DETECTED_MODULATION_TYPE_QAM64                              3
#define RFMXNR_VAL_MODACC_RESULTS_SCH_DETECTED_MODULATION_TYPE_QAM256                             4
#define RFMXNR_VAL_MODACC_RESULTS_SCH_DETECTED_MODULATION_TYPE_QAM1024                            5
#define RFMXNR_VAL_MODACC_RESULTS_SCH_DETECTED_MODULATION_TYPE_PSK8                               100

// Values for RFMXNR_ATTR_ACP_OFFSET_SIDEBAND
#define RFMXNR_VAL_ACP_OFFSET_SIDEBAND_NEGATIVE                                                   0
#define RFMXNR_VAL_ACP_OFFSET_SIDEBAND_POSITIVE                                                   1
#define RFMXNR_VAL_ACP_OFFSET_SIDEBAND_BOTH                                                       2

// Values for RFMXNR_ATTR_ACP_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXNR_VAL_ACP_RBW_FILTER_AUTO_BANDWIDTH_FALSE                                            0
#define RFMXNR_VAL_ACP_RBW_FILTER_AUTO_BANDWIDTH_TRUE                                             1

// Values for RFMXNR_ATTR_ACP_RBW_FILTER_TYPE
#define RFMXNR_VAL_ACP_RBW_FILTER_TYPE_FFT_BASED                                                  0
#define RFMXNR_VAL_ACP_RBW_FILTER_TYPE_GAUSSIAN                                                   1
#define RFMXNR_VAL_ACP_RBW_FILTER_TYPE_FLAT                                                       2

// Values for RFMXNR_ATTR_ACP_SWEEP_TIME_AUTO
#define RFMXNR_VAL_ACP_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXNR_VAL_ACP_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXNR_ATTR_ACP_POWER_UNITS
#define RFMXNR_VAL_ACP_POWER_UNITS_DBM                                                            0
#define RFMXNR_VAL_ACP_POWER_UNITS_DBM_BY_HZ                                                      1

// Values for RFMXNR_ATTR_ACP_MEASUREMENT_METHOD
#define RFMXNR_VAL_ACP_MEASUREMENT_METHOD_NORMAL                                                  0
#define RFMXNR_VAL_ACP_MEASUREMENT_METHOD_DYNAMIC_RANGE                                           1
#define RFMXNR_VAL_ACP_MEASUREMENT_METHOD_SEQUENTIAL_FFT                                          2

// Values for RFMXNR_ATTR_ACP_NOISE_CALIBRATION_MODE
#define RFMXNR_VAL_ACP_NOISE_CALIBRATION_MODE_MANUAL                                              0
#define RFMXNR_VAL_ACP_NOISE_CALIBRATION_MODE_AUTO                                                1

// Values for RFMXNR_ATTR_ACP_NOISE_CALIBRATION_AVERAGING_AUTO
#define RFMXNR_VAL_ACP_NOISE_CALIBRATION_AVERAGING_AUTO_FALSE                                     0
#define RFMXNR_VAL_ACP_NOISE_CALIBRATION_AVERAGING_AUTO_TRUE                                      1

// Values for RFMXNR_ATTR_ACP_NOISE_COMPENSATION_ENABLED
#define RFMXNR_VAL_ACP_NOISE_COMPENSATION_ENABLED_FALSE                                           0
#define RFMXNR_VAL_ACP_NOISE_COMPENSATION_ENABLED_TRUE                                            1

// Values for RFMXNR_ATTR_ACP_NOISE_COMPENSATION_TYPE
#define RFMXNR_VAL_ACP_NOISE_COMPENSATION_TYPE_ANALYZER_AND_TERMINATION                           0
#define RFMXNR_VAL_ACP_NOISE_COMPENSATION_TYPE_ANALYZER_ONLY                                      1

// Values for RFMXNR_ATTR_ACP_AVERAGING_ENABLED
#define RFMXNR_VAL_ACP_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXNR_VAL_ACP_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXNR_ATTR_ACP_AVERAGING_TYPE
#define RFMXNR_VAL_ACP_AVERAGING_TYPE_RMS                                                         0
#define RFMXNR_VAL_ACP_AVERAGING_TYPE_LOG                                                         1
#define RFMXNR_VAL_ACP_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXNR_VAL_ACP_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXNR_VAL_ACP_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXNR_ATTR_ACP_MEASUREMENT_MODE
#define RFMXNR_VAL_ACP_MEASUREMENT_MODE_MEASURE                                                   0
#define RFMXNR_VAL_ACP_MEASUREMENT_MODE_CALIBRATE_NOISE_FLOOR                                     1

// Values for RFMXNR_ATTR_ACP_FFT_WINDOW
#define RFMXNR_VAL_ACP_FFT_WINDOW_NONE                                                            0
#define RFMXNR_VAL_ACP_FFT_WINDOW_FLAT_TOP                                                        1
#define RFMXNR_VAL_ACP_FFT_WINDOW_HANNING                                                         2
#define RFMXNR_VAL_ACP_FFT_WINDOW_HAMMING                                                         3
#define RFMXNR_VAL_ACP_FFT_WINDOW_GAUSSIAN                                                        4
#define RFMXNR_VAL_ACP_FFT_WINDOW_BLACKMAN                                                        5
#define RFMXNR_VAL_ACP_FFT_WINDOW_BLACKMAN_HARRIS                                                 6
#define RFMXNR_VAL_ACP_FFT_WINDOW_KAISER_BESSEL                                                   7

// Values for RFMXNR_ATTR_ACP_FFT_OVERLAP_MODE
#define RFMXNR_VAL_ACP_FFT_OVERLAP_MODE_DISABLED                                                  0
#define RFMXNR_VAL_ACP_FFT_OVERLAP_MODE_AUTOMATIC                                                 1
#define RFMXNR_VAL_ACP_FFT_OVERLAP_MODE_USER_DEFINED                                              2

// Values for RFMXNR_ATTR_ACP_IF_OUTPUT_POWER_OFFSET_AUTO
#define RFMXNR_VAL_ACP_IF_OUTPUT_POWER_OFFSET_AUTO_FALSE                                          0
#define RFMXNR_VAL_ACP_IF_OUTPUT_POWER_OFFSET_AUTO_TRUE                                           1

// Values for RFMXNR_ATTR_ACP_AMPLITUDE_CORRECTION_TYPE
#define RFMXNR_VAL_ACP_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY                              0
#define RFMXNR_VAL_ACP_AMPLITUDE_CORRECTION_TYPE_SPECTRUM_FREQUENCY_BIN                           1

// Values for RFMXNR_ATTR_CHP_SWEEP_TIME_AUTO
#define RFMXNR_VAL_CHP_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXNR_VAL_CHP_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXNR_ATTR_CHP_INTEGRATION_BANDWIDTH_TYPE
#define RFMXNR_VAL_CHP_INTEGRATION_BANDWIDTH_TYPE_SIGNAL_BANDWIDTH                                0
#define RFMXNR_VAL_CHP_INTEGRATION_BANDWIDTH_TYPE_CHANNEL_BANDWIDTH                               1

// Values for RFMXNR_ATTR_CHP_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXNR_VAL_CHP_RBW_FILTER_AUTO_BANDWIDTH_FALSE                                            0
#define RFMXNR_VAL_CHP_RBW_FILTER_AUTO_BANDWIDTH_TRUE                                             1

// Values for RFMXNR_ATTR_CHP_RBW_FILTER_TYPE
#define RFMXNR_VAL_CHP_RBW_FILTER_TYPE_FFT_BASED                                                  0
#define RFMXNR_VAL_CHP_RBW_FILTER_TYPE_GAUSSIAN                                                   1
#define RFMXNR_VAL_CHP_RBW_FILTER_TYPE_FLAT                                                       2

// Values for RFMXNR_ATTR_CHP_NOISE_CALIBRATION_MODE
#define RFMXNR_VAL_CHP_NOISE_CALIBRATION_MODE_MANUAL                                              0
#define RFMXNR_VAL_CHP_NOISE_CALIBRATION_MODE_AUTO                                                1

// Values for RFMXNR_ATTR_CHP_NOISE_CALIBRATION_AVERAGING_AUTO
#define RFMXNR_VAL_CHP_NOISE_CALIBRATION_AVERAGING_AUTO_FALSE                                     0
#define RFMXNR_VAL_CHP_NOISE_CALIBRATION_AVERAGING_AUTO_TRUE                                      1

// Values for RFMXNR_ATTR_CHP_NOISE_COMPENSATION_ENABLED
#define RFMXNR_VAL_CHP_NOISE_COMPENSATION_ENABLED_FALSE                                           0
#define RFMXNR_VAL_CHP_NOISE_COMPENSATION_ENABLED_TRUE                                            1

// Values for RFMXNR_ATTR_CHP_NOISE_COMPENSATION_TYPE
#define RFMXNR_VAL_CHP_NOISE_COMPENSATION_TYPE_ANALYZER_AND_TERMINATION                           0
#define RFMXNR_VAL_CHP_NOISE_COMPENSATION_TYPE_ANALYZER_ONLY                                      1

// Values for RFMXNR_ATTR_CHP_AVERAGING_ENABLED
#define RFMXNR_VAL_CHP_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXNR_VAL_CHP_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXNR_ATTR_CHP_AVERAGING_TYPE
#define RFMXNR_VAL_CHP_AVERAGING_TYPE_RMS                                                         0
#define RFMXNR_VAL_CHP_AVERAGING_TYPE_LOG                                                         1
#define RFMXNR_VAL_CHP_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXNR_VAL_CHP_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXNR_VAL_CHP_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXNR_ATTR_CHP_MEASUREMENT_MODE
#define RFMXNR_VAL_CHP_MEASUREMENT_MODE_MEASURE                                                   0
#define RFMXNR_VAL_CHP_MEASUREMENT_MODE_CALIBRATE_NOISE_FLOOR                                     1

// Values for RFMXNR_ATTR_CHP_FFT_WINDOW
#define RFMXNR_VAL_CHP_FFT_WINDOW_NONE                                                            0
#define RFMXNR_VAL_CHP_FFT_WINDOW_FLAT_TOP                                                        1
#define RFMXNR_VAL_CHP_FFT_WINDOW_HANNING                                                         2
#define RFMXNR_VAL_CHP_FFT_WINDOW_HAMMING                                                         3
#define RFMXNR_VAL_CHP_FFT_WINDOW_GAUSSIAN                                                        4
#define RFMXNR_VAL_CHP_FFT_WINDOW_BLACKMAN                                                        5
#define RFMXNR_VAL_CHP_FFT_WINDOW_BLACKMAN_HARRIS                                                 6
#define RFMXNR_VAL_CHP_FFT_WINDOW_KAISER_BESSEL                                                   7

// Values for RFMXNR_ATTR_CHP_AMPLITUDE_CORRECTION_TYPE
#define RFMXNR_VAL_CHP_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY                              0
#define RFMXNR_VAL_CHP_AMPLITUDE_CORRECTION_TYPE_SPECTRUM_FREQUENCY_BIN                           1

// Values for RFMXNR_ATTR_OBW_SPAN_AUTO
#define RFMXNR_VAL_OBW_SPAN_AUTO_FALSE                                                            0
#define RFMXNR_VAL_OBW_SPAN_AUTO_TRUE                                                             1

// Values for RFMXNR_ATTR_OBW_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXNR_VAL_OBW_RBW_FILTER_AUTO_BANDWIDTH_FALSE                                            0
#define RFMXNR_VAL_OBW_RBW_FILTER_AUTO_BANDWIDTH_TRUE                                             1

// Values for RFMXNR_ATTR_OBW_RBW_FILTER_TYPE
#define RFMXNR_VAL_OBW_RBW_FILTER_TYPE_FFT_BASED                                                  0
#define RFMXNR_VAL_OBW_RBW_FILTER_TYPE_GAUSSIAN                                                   1
#define RFMXNR_VAL_OBW_RBW_FILTER_TYPE_FLAT                                                       2

// Values for RFMXNR_ATTR_OBW_SWEEP_TIME_AUTO
#define RFMXNR_VAL_OBW_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXNR_VAL_OBW_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXNR_ATTR_OBW_AVERAGING_ENABLED
#define RFMXNR_VAL_OBW_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXNR_VAL_OBW_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXNR_ATTR_OBW_AVERAGING_TYPE
#define RFMXNR_VAL_OBW_AVERAGING_TYPE_RMS                                                         0
#define RFMXNR_VAL_OBW_AVERAGING_TYPE_LOG                                                         1
#define RFMXNR_VAL_OBW_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXNR_VAL_OBW_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXNR_VAL_OBW_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXNR_ATTR_OBW_FFT_WINDOW
#define RFMXNR_VAL_OBW_FFT_WINDOW_NONE                                                            0
#define RFMXNR_VAL_OBW_FFT_WINDOW_FLAT_TOP                                                        1
#define RFMXNR_VAL_OBW_FFT_WINDOW_HANNING                                                         2
#define RFMXNR_VAL_OBW_FFT_WINDOW_HAMMING                                                         3
#define RFMXNR_VAL_OBW_FFT_WINDOW_GAUSSIAN                                                        4
#define RFMXNR_VAL_OBW_FFT_WINDOW_BLACKMAN                                                        5
#define RFMXNR_VAL_OBW_FFT_WINDOW_BLACKMAN_HARRIS                                                 6
#define RFMXNR_VAL_OBW_FFT_WINDOW_KAISER_BESSEL                                                   7

// Values for RFMXNR_ATTR_OBW_AMPLITUDE_CORRECTION_TYPE
#define RFMXNR_VAL_OBW_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY                              0
#define RFMXNR_VAL_OBW_AMPLITUDE_CORRECTION_TYPE_SPECTRUM_FREQUENCY_BIN                           1

// Values for RFMXNR_ATTR_SEM_UPLINK_MASK_TYPE
#define RFMXNR_VAL_SEM_UPLINK_MASK_TYPE_GENERAL                                                   0
#define RFMXNR_VAL_SEM_UPLINK_MASK_TYPE_NS35                                                      1
#define RFMXNR_VAL_SEM_UPLINK_MASK_TYPE_CUSTOM                                                    2
#define RFMXNR_VAL_SEM_UPLINK_MASK_TYPE_NS03                                                      3
#define RFMXNR_VAL_SEM_UPLINK_MASK_TYPE_NS04                                                      4
#define RFMXNR_VAL_SEM_UPLINK_MASK_TYPE_NS06                                                      5
#define RFMXNR_VAL_SEM_UPLINK_MASK_TYPE_NS21                                                      6
#define RFMXNR_VAL_SEM_UPLINK_MASK_TYPE_NS27                                                      7
#define RFMXNR_VAL_SEM_UPLINK_MASK_TYPE_NS07                                                      8

// Values for RFMXNR_ATTR_SEM_DOWNLINK_MASK_TYPE
#define RFMXNR_VAL_SEM_DOWNLINK_MASK_TYPE_STANDARD                                                0
#define RFMXNR_VAL_SEM_DOWNLINK_MASK_TYPE_CUSTOM                                                  2

// Values for RFMXNR_ATTR_SEM_OFFSET_SIDEBAND
#define RFMXNR_VAL_SEM_OFFSET_SIDEBAND_NEGATIVE                                                   0
#define RFMXNR_VAL_SEM_OFFSET_SIDEBAND_POSITIVE                                                   1
#define RFMXNR_VAL_SEM_OFFSET_SIDEBAND_BOTH                                                       2

// Values for RFMXNR_ATTR_SEM_OFFSET_RBW_FILTER_TYPE
#define RFMXNR_VAL_SEM_OFFSET_RBW_FILTER_TYPE_FFT_BASED                                           0
#define RFMXNR_VAL_SEM_OFFSET_RBW_FILTER_TYPE_GAUSSIAN                                            1
#define RFMXNR_VAL_SEM_OFFSET_RBW_FILTER_TYPE_FLAT                                                2

// Values for RFMXNR_ATTR_SEM_OFFSET_LIMIT_FAIL_MASK
#define RFMXNR_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_ABS_AND_REL                                         0
#define RFMXNR_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_ABS_OR_REL                                          1
#define RFMXNR_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_ABSOLUTE                                            2
#define RFMXNR_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_RELATIVE                                            3

// Values for RFMXNR_ATTR_SEM_OFFSET_FREQUENCY_DEFINITION
#define RFMXNR_VAL_SEM_OFFSET_FREQUENCY_DEFINITION_CARRIER_CENTER_TO_MEAS_BW_CENTER               0
#define RFMXNR_VAL_SEM_OFFSET_FREQUENCY_DEFINITION_CARRIER_EDGE_TO_MEAS_BW_CENTER                 2
#define RFMXNR_VAL_SEM_OFFSET_FREQUENCY_DEFINITION_SUBBLOCK_EDGE_TO_MEAS_BW_CENTER                6

// Values for RFMXNR_ATTR_SEM_SWEEP_TIME_AUTO
#define RFMXNR_VAL_SEM_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXNR_VAL_SEM_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXNR_ATTR_SEM_AVERAGING_ENABLED
#define RFMXNR_VAL_SEM_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXNR_VAL_SEM_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXNR_ATTR_SEM_AVERAGING_TYPE
#define RFMXNR_VAL_SEM_AVERAGING_TYPE_RMS                                                         0
#define RFMXNR_VAL_SEM_AVERAGING_TYPE_LOG                                                         1
#define RFMXNR_VAL_SEM_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXNR_VAL_SEM_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXNR_VAL_SEM_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXNR_ATTR_SEM_FFT_WINDOW
#define RFMXNR_VAL_SEM_FFT_WINDOW_NONE                                                            0
#define RFMXNR_VAL_SEM_FFT_WINDOW_FLAT_TOP                                                        1
#define RFMXNR_VAL_SEM_FFT_WINDOW_HANNING                                                         2
#define RFMXNR_VAL_SEM_FFT_WINDOW_HAMMING                                                         3
#define RFMXNR_VAL_SEM_FFT_WINDOW_GAUSSIAN                                                        4
#define RFMXNR_VAL_SEM_FFT_WINDOW_BLACKMAN                                                        5
#define RFMXNR_VAL_SEM_FFT_WINDOW_BLACKMAN_HARRIS                                                 6
#define RFMXNR_VAL_SEM_FFT_WINDOW_KAISER_BESSEL                                                   7

// Values for RFMXNR_ATTR_SEM_AMPLITUDE_CORRECTION_TYPE
#define RFMXNR_VAL_SEM_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY                              0
#define RFMXNR_VAL_SEM_AMPLITUDE_CORRECTION_TYPE_SPECTRUM_FREQUENCY_BIN                           1

// Values for RFMXNR_ATTR_SEM_RESULTS_MEASUREMENT_STATUS
#define RFMXNR_VAL_SEM_MEASUREMENT_STATUS_FAIL                                                    0
#define RFMXNR_VAL_SEM_MEASUREMENT_STATUS_PASS                                                    1

// Values for RFMXNR_ATTR_SEM_RESULTS_LOWER_OFFSET_MEASUREMENT_STATUS
#define RFMXNR_VAL_SEM_LOWER_OFFSET_MEASUREMENT_STATUS_FAIL                                       0
#define RFMXNR_VAL_SEM_LOWER_OFFSET_MEASUREMENT_STATUS_PASS                                       1

// Values for RFMXNR_ATTR_SEM_RESULTS_UPPER_OFFSET_MEASUREMENT_STATUS
#define RFMXNR_VAL_SEM_UPPER_OFFSET_MEASUREMENT_STATUS_FAIL                                       0
#define RFMXNR_VAL_SEM_UPPER_OFFSET_MEASUREMENT_STATUS_PASS                                       1

// Values for RFMXNR_ATTR_TXP_AVERAGING_ENABLED
#define RFMXNR_VAL_TXP_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXNR_VAL_TXP_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXNR_ATTR_PVT_MEASUREMENT_INTERVAL_AUTO
#define RFMXNR_VAL_PVT_MEASUREMENT_INTERVAL_AUTO_FALSE                                            0
#define RFMXNR_VAL_PVT_MEASUREMENT_INTERVAL_AUTO_TRUE                                             1

// Values for RFMXNR_ATTR_PVT_MEASUREMENT_METHOD
#define RFMXNR_VAL_PVT_MEASUREMENT_METHOD_NORMAL                                                  0
#define RFMXNR_VAL_PVT_MEASUREMENT_METHOD_DYNAMIC_RANGE                                           1

// Values for RFMXNR_ATTR_PVT_AVERAGING_ENABLED
#define RFMXNR_VAL_PVT_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXNR_VAL_PVT_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXNR_ATTR_PVT_AVERAGING_TYPE
#define RFMXNR_VAL_PVT_AVERAGING_TYPE_RMS                                                         0
#define RFMXNR_VAL_PVT_AVERAGING_TYPE_LOG                                                         1

// Values for RFMXNR_ATTR_PVT_RESULTS_MEASUREMENT_STATUS
#define RFMXNR_VAL_PVT_MEASUREMENT_STATUS_FAIL                                                    0
#define RFMXNR_VAL_PVT_MEASUREMENT_STATUS_PASS                                                    1

// Values for RFMXNR_ATTR_ACQUISITION_BANDWIDTH_OPTIMIZATION_ENABLED
#define RFMXNR_VAL_ACQUISITION_BANDWIDTH_OPTIMIZATION_ENABLED_FALSE                               0
#define RFMXNR_VAL_ACQUISITION_BANDWIDTH_OPTIMIZATION_ENABLED_TRUE                                1

// Values for RFMXNR_ATTR_TRANSMITTER_ARCHITECTURE
#define RFMXNR_VAL_TRANSMITTER_ARCHITECTURE_LO_PER_COMPONENT_CARRIER                              0
#define RFMXNR_VAL_TRANSMITTER_ARCHITECTURE_LO_PER_SUBBLOCK                                       1

// Values for RFMXNR_ATTR_PHASE_COMPENSATION
#define RFMXNR_VAL_PHASE_COMPENSATION_DISABLED                                                    0
#define RFMXNR_VAL_PHASE_COMPENSATION_AUTO                                                        1
#define RFMXNR_VAL_PHASE_COMPENSATION_USER_DEFINED                                                2

// Values for RFMXNR_ATTR_REFERENCE_GRID_ALIGNMENT_MODE
#define RFMXNR_VAL_REFERENCE_GRID_ALIGNMENT_MODE_MANUAL                                           0
#define RFMXNR_VAL_REFERENCE_GRID_ALIGNMENT_MODE_AUTO                                             1

// Values for RFMXNR_ATTR_GRID_SIZE_MODE
#define RFMXNR_VAL_GRID_SIZE_MODE_MANUAL                                                          0
#define RFMXNR_VAL_GRID_SIZE_MODE_AUTO                                                            1

// Values for RFMXNR_ATTR_LIMITED_CONFIGURATION_CHANGE
#define RFMXNR_VAL_LIMITED_CONFIGURATION_CHANGE_DISABLED                                          0
#define RFMXNR_VAL_LIMITED_CONFIGURATION_CHANGE_NO_CHANGE                                         1
#define RFMXNR_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY                                         2
#define RFMXNR_VAL_LIMITED_CONFIGURATION_CHANGE_REFERENCE_LEVEL                                   3
#define RFMXNR_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY_AND_REFERENCE_LEVEL                     4
#define RFMXNR_VAL_LIMITED_CONFIGURATION_CHANGE_SELECTED_PORTS_FREQUENCY_AND_REFERENCE_LEVEL      5

// Values for MeasurementTypes
#define RFMXNR_VAL_MODACC                                                                         1<<0
#define RFMXNR_VAL_SEM                                                                            1<<1
#define RFMXNR_VAL_ACP                                                                            1<<2
#define RFMXNR_VAL_CHP                                                                            1<<3
#define RFMXNR_VAL_OBW                                                                            1<<4
#define RFMXNR_VAL_PVT                                                                            1<<5
#define RFMXNR_VAL_TXP                                                                            1<<6

// Values for RFAttenuationAuto
#define RFMXNR_VAL_RF_ATTENUATION_AUTO_FALSE                                                      0
#define RFMXNR_VAL_RF_ATTENUATION_AUTO_TRUE                                                       1

// Values for FrequencyReferenceSource
#define RFMXNR_VAL_ONBOARD_CLOCK_STR                                                              "OnboardClock"
#define RFMXNR_VAL_REF_IN_STR                                                                     "RefIn"
#define RFMXNR_VAL_PXI_CLK_STR                                                                    "PXI_Clk"
#define RFMXNR_VAL_CLK_IN_STR                                                                     "ClkIn"
#define RFMXNR_VAL_REF_IN2_STR                                                                    "RefIn2"
#define RFMXNR_VAL_PXI_CLK_MASTER_STR                                                             "PXI_Clk_Master"

// Values for Boolean
#define RFMXNR_VAL_FALSE                                                                          0
#define RFMXNR_VAL_TRUE                                                                           1

// Values for AcpNoiseCalibrationDataValid
#define RFMXNR_VAL_ACP_NOISE_CALIBRATION_DATA_VALID_FALSE                                         0
#define RFMXNR_VAL_ACP_NOISE_CALIBRATION_DATA_VALID_TRUE                                          1

// Values for ChpNoiseCalibrationDataValid
#define RFMXNR_VAL_CHP_NOISE_CALIBRATION_DATA_VALID_FALSE                                         0
#define RFMXNR_VAL_CHP_NOISE_CALIBRATION_DATA_VALID_TRUE                                          1

/* ---------------- RFmxNR APIs ------------------ */


#ifdef __cplusplus
extern "C"
{
#endif


int32 __stdcall RFmxNR_ResetAttribute(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID
);

int32 __stdcall RFmxNR_Initialize(
   char resourceName[],
   char optionString[],
   niRFmxInstrHandle *handleOut,
   int32 *isNewSession
);

int32 __stdcall RFmxNR_InitializeFromNIRFSASession(
   uInt32 NIRFSASession,
   niRFmxInstrHandle *handleOut
);

int32 __stdcall RFmxNR_Close(
   niRFmxInstrHandle instrumentHandle,
   int32 forceDestroy
);

int32 __stdcall RFmxNR_GetErrorString(
   niRFmxInstrHandle instrumentHandle,
   int32 errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxNR_GetError(
   niRFmxInstrHandle instrumentHandle,
   int32* errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxNR_CfgFrequencyReference(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   char frequencyReferenceSource[],
   float64 frequencyReferenceFrequency
);

int32 __stdcall RFmxNR_CfgMechanicalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 mechanicalAttenuationAuto,
   float64 mechanicalAttenuationValue
);

int32 __stdcall RFmxNR_CfgRFAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 RFAttenuationAuto,
   float64 RFAttenuationValue
);

int32 __stdcall RFmxNR_WaitForAcquisitionComplete(
   niRFmxInstrHandle instrumentHandle,
   float64 timeout
);


int32 __stdcall RFmxNR_BuildSignalString(
   char signalName[],
   char resultName[],
   int32 selectorStringLength,
   char selectorString[]
);

int32 __stdcall RFmxNR_BuildListString(
   char listName[],
   char resultName[],
   int32 selectorStringLength,
   char selectorString[]
);

int32 __stdcall RFmxNR_BuildListStepString(
   char listName[],
   char resultName[],
   int32 stepNumber,
   int32 selectorStringLength,
   char selectorString[]
);

int32 __stdcall RFmxNR_BuildSubblockString(
   char selectorString[],
   int32 subblockNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxNR_BuildCarrierString(
   char selectorString[],
   int32 carrierNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxNR_BuildOffsetString(
   char selectorString[],
   int32 offsetNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxNR_BuildBandwidthPartString(
   char selectorString[],
   int32 bandwidthPartNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxNR_BuildUserString(
   char selectorString[],
   int32 userNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxNR_BuildPUSCHString(
   char selectorString[],
   int32 PUSCHNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxNR_BuildPUSCHClusterString(
   char selectorString[],
   int32 PUSCHClusterNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxNR_BuildPDSCHString(
   char selectorString[],
   int32 PDSCHNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxNR_BuildPDSCHClusterString(
   char selectorString[],
   int32 PDSCHClusterNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxNR_BuildCORESETString(
   char selectorString[],
   int32 CORESETNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxNR_BuildCORESETClusterString(
   char selectorString[],
   int32 CORESETClusterNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxNR_BuildPDCCHString(
   char selectorString[],
   int32 PDCCHNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxNR_SetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal
);

int32 __stdcall RFmxNR_GetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8* attrVal
);

int32 __stdcall RFmxNR_SetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxNR_GetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_SetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16 attrVal
);

int32 __stdcall RFmxNR_GetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16* attrVal
);

int32 __stdcall RFmxNR_SetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal
);

int32 __stdcall RFmxNR_GetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32* attrVal
);

int32 __stdcall RFmxNR_SetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxNR_GetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_SetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal
);

int32 __stdcall RFmxNR_GetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64* attrVal
);

int32 __stdcall RFmxNR_SetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxNR_GetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_SetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal
);

int32 __stdcall RFmxNR_GetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8* attrVal
);

int32 __stdcall RFmxNR_SetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxNR_GetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_SetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16 attrVal
);

int32 __stdcall RFmxNR_GetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16* attrVal
);

int32 __stdcall RFmxNR_SetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal
);

int32 __stdcall RFmxNR_GetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32* attrVal
);

int32 __stdcall RFmxNR_SetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxNR_GetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_SetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxNR_GetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_SetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal
);

int32 __stdcall RFmxNR_GetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32* attrVal
);

int32 __stdcall RFmxNR_SetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxNR_GetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_SetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal
);

int32 __stdcall RFmxNR_GetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64* attrVal
);

int32 __stdcall RFmxNR_SetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxNR_GetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_SetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxNR_GetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_SetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxNR_GetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize,
   int32* actualArraySize
);


int32 __stdcall RFmxNR_SetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   char attrVal[]
);

int32 __stdcall RFmxNR_GetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxNR_Initiate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[]
);

int32 __stdcall RFmxNR_WaitForMeasurementComplete(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout
);

int32 __stdcall RFmxNR_Commit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxNR_ClearNamedResult(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxNR_ClearAllNamedResults(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxNR_ResetToDefault(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxNR_CheckMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* isDone
);

int32 __stdcall RFmxNR_AnalyzeIQ1Waveform(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[],
   float64 x0,
   float64 dx,
   NIComplexSingle IQ[],
   int32 arraySize,
   int32 reset,
   int64 reserved
);

int32 __stdcall RFmxNR_AnalyzeIQ1WaveformSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[],
   float64 x0,
   float64 dx,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32 reset,
   int64 reserved
);

int32 __stdcall RFmxNR_AnalyzeSpectrum1Waveform(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[],
   float64 x0,
   float64 dx,
   float32 spectrum[],
   int32 arraySize,
   int32 reset,
   int64 reserved
);

int32 __stdcall RFmxNR_AutoLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 measurementInterval,
   float64* referenceLevel
);

int32 __stdcall RFmxNR_SendSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle
);

int32 __stdcall RFmxNR_CreateSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxNR_CloneSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char oldSignalName[],
   char newSignalName[]
);

int32 __stdcall RFmxNR_DeleteSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxNR_ClearNoiseCalibrationDatabase(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxNR_CreateList(
   niRFmxInstrHandle instrumentHandle,
   char listName[]
);

int32 __stdcall RFmxNR_CreateListStep(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* createdStepIndex
);

int32 __stdcall RFmxNR_DeleteList(
   niRFmxInstrHandle instrumentHandle,
   char listName[]
);

int32 __stdcall RFmxNR_ACPValidateNoiseCalibrationData(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* noiseCalibrationDataValid
);

int32 __stdcall RFmxNR_CHPValidateNoiseCalibrationData(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* noiseCalibrationDataValid
);

int32 __stdcall RFmxNR_ModAccCfgReferenceWaveform(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0,
   float64 dx,
   NIComplexSingle referenceWaveform[],
   int32 arraySize
);

int32 __stdcall RFmxNR_ModAccCfgReferenceWaveformSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0,
   float64 dx,
   float32 I[],
   float32 Q[],
   int32 arraySize
);

int32 __stdcall RFmxNR_ModAccAutoLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout
);

int32 __stdcall RFmxNR_ModAccValidateCalibrationData(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* calibrationDataValid
);

int32 __stdcall RFmxNR_ModAccClearNoiseCalibrationDatabase(
   niRFmxInstrHandle instrumentHandle
);

int32 __stdcall RFmxNR_SEMCfgUplinkMaskType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 uplinkMaskType
);

int32 __stdcall RFmxNR_SEMCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxNR_SEMCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxNR_SEMCfgNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfOffsets
);

int32 __stdcall RFmxNR_SEMCfgOffsetFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 offsetStartFrequency,
   float64 offsetStopFrequency,
   int32 offsetSideband
);

int32 __stdcall RFmxNR_SEMCfgOffsetRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 offsetRBW,
   int32 offsetRBWFilterType
);

int32 __stdcall RFmxNR_SEMCfgOffsetBandwidthIntegral(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 bandwidthIntegral
);

int32 __stdcall RFmxNR_SEMCfgOffsetAbsoluteLimit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 absoluteLimitStart,
   float64 absoluteLimitStop
);

int32 __stdcall RFmxNR_SEMCfgOffsetLimitFailMask(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 limitFailMask
);

int32 __stdcall RFmxNR_SEMCfgOffsetRelativeLimit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 relativeLimitStart,
   float64 relativeLimitStop
);

int32 __stdcall RFmxNR_SEMCfgComponentCarrierRatedOutputPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 componentCarrierRatedOutputPower
);

int32 __stdcall RFmxNR_SEMCfgOffsetFrequencyArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 offsetStartFrequency[],
   float64 offsetStopFrequency[],
   int32 offsetSideband[],
   int32 numberOfElements
);

int32 __stdcall RFmxNR_SEMCfgOffsetRBWFilterArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 offsetRBW[],
   int32 offsetRBWFilterType[],
   int32 numberOfElements
);

int32 __stdcall RFmxNR_SEMCfgOffsetBandwidthIntegralArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 bandwidthIntegral[],
   int32 numberOfElements
);

int32 __stdcall RFmxNR_SEMCfgOffsetAbsoluteLimitArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 absoluteLimitStart[],
   float64 absoluteLimitStop[],
   int32 numberOfElements
);

int32 __stdcall RFmxNR_SEMCfgOffsetLimitFailMaskArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 limitFailMask[],
   int32 numberOfElements
);

int32 __stdcall RFmxNR_SEMCfgOffsetRelativeLimitArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 relativeLimitStart[],
   float64 relativeLimitStop[],
   int32 numberOfElements
);

int32 __stdcall RFmxNR_SEMCfgComponentCarrierRatedOutputPowerArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 componentCarrierRatedOutputPower[],
   int32 numberOfElements
);

int32 __stdcall RFmxNR_ModAccCfgMeasurementMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementMode
);

int32 __stdcall RFmxNR_ModAccCfgNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 noiseCompensationEnabled
);

int32 __stdcall RFmxNR_CfgRF(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency,
   float64 referenceLevel,
   float64 externalAttenuation
);

int32 __stdcall RFmxNR_CfgFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency
);

int32 __stdcall RFmxNR_CfgReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 referenceLevel
);

int32 __stdcall RFmxNR_CfgExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 externalAttenuation
);

int32 __stdcall RFmxNR_CfggNodeBCategory(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 gNodeBCategory
);

int32 __stdcall RFmxNR_ACPCfgNumberOfUTRAOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfUTRAOffsets
);

int32 __stdcall RFmxNR_ACPCfgNumberOfEUTRAOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfEUTRAOffsets
);

int32 __stdcall RFmxNR_ACPCfgNumberOfNROffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfNROffsets
);

int32 __stdcall RFmxNR_ACPCfgNumberOfENDCOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfENDCOffsets
);

int32 __stdcall RFmxNR_ACPCfgMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementMethod
);

int32 __stdcall RFmxNR_ACPCfgNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 noiseCompensationEnabled
);

int32 __stdcall RFmxNR_ACPCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxNR_ACPCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxNR_ACPCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxNR_ACPCfgPowerUnits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 powerUnits
);

int32 __stdcall RFmxNR_CHPCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxNR_CHPCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxNR_CHPCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxNR_OBWCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxNR_OBWCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxNR_OBWCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxNR_PVTCfgMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementMethod
);

int32 __stdcall RFmxNR_PVTCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxNR_PVTCfgOFFPowerExclusionPeriods(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 OFFPowerExclusionBefore,
   float64 OFFPowerExclusionAfter
);

int32 __stdcall RFmxNR_AbortMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxNR_SelectMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   uInt32 measurements,
   int32 enableAllTraces
);

int32 __stdcall RFmxNR_DisableTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxNR_CfgDigitalEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char digitalEdgeSource[],
   int32 digitalEdge,
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxNR_CfgIQPowerEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char IQPowerEdgeSource[],
   int32 IQPowerEdgeSlope,
   float64 IQPowerEdgeLevel,
   float64 triggerDelay,
   int32 triggerMinQuietTimeMode,
   float64 triggerMinQuietTimeDuration,
   int32 IQPowerEdgeLevelType,
   int32 enableTrigger
);

int32 __stdcall RFmxNR_CfgSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxNR_GetAllNamedResultNames(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultNames[],
   int32 resultNamesBufferSize,
   int32* actualResultNamesSize,
   int32* defaultResultExists
);

int32 __stdcall RFmxNR_ModAccFetchPUSCHDemodulatedBits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int8 bits[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPUSCHDataConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle PUSCHDataConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPUSCHDataConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPUSCHDMRSConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle PUSCHDMRSConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPUSCHDMRSConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPUSCHPTRSConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle PUSCHPTRSConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPUSCHPTRSConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchRMSEVMPerSubcarrierMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 RMSEVMPerSubcarrierMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchRMSEVMPerSlotMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 RMSEVMPerSlotMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchRMSEVMPerSymbolMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 RMSEVMPerSymbolMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPeakEVMPerSubcarrierMaximumTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 peakEVMPerSubcarrierMaximum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPeakEVMPerSlotMaximumTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 peakEVMPerSlotMaximum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPeakEVMPerSymbolMaximumTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 peakEVMPerSymbolMaximum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchRMSEVMHighPerSymbolMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 RMSEVMHighPerSymbolMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchRMSEVMLowPerSymbolMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 RMSEVMLowPerSymbolMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchTransientPeriodLocationsTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 transientPeriodLocations[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchInBandEmissionTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 inBandEmission[],
   float32 inBandEmissionMask[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchSubblockInBandEmissionTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 subblockInBandEmission[],
   float64 subblockInBandEmissionMask[],
   float64 subblockInBandEmissionRBIndices[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchSpectralFlatnessTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectralFlatness[],
   float32 spectralFlatnessLowerMask[],
   float32 spectralFlatnessUpperMask[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPDSCHDemodulatedBits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int8 bits[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPDSCHDMRSConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle PDSCHDMRSConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPDSCHDMRSConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPDSCHPTRSConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle PDSCHPTRSConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPDSCHPTRSConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPDSCHQPSKConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle QPSKConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPDSCHQPSKConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPDSCH16QAMConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle QAM16Constellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPDSCH16QAMConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPDSCH64QAMConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle QAM64Constellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPDSCH64QAMConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPDSCH256QAMConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle QAM256Constellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPDSCH256QAMConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPDSCH1024QAMConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle QAM1024Constellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPDSCH1024QAMConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPDSCH8PSKConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle PSK8Constellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPDSCH8PSKConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPSSConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle PSSConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPSSConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchSSSConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle SSSConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchSSSConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPBCHDataConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle PBCHDataConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPBCHDataConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPBCHDMRSConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle PBCHDMRSConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPBCHDMRSConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPDSCHDataConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle PDSCHDataConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPDSCHDataConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPUSCHPhaseOffsetTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 PUSCHPhaseOffset[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchFrequencyErrorPerSlotMaximumTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 frequencyErrorPerSlotMaximum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPSSRMSEVMPerSubcarrierMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 PSSRMSEVMPerSubcarrierMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPSSRMSEVMPerSymbolMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 PSSRMSEVMPerSymbolMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchSSSRMSEVMPerSubcarrierMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 SSSRMSEVMPerSubcarrierMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchSSSRMSEVMPerSymbolMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 SSSRMSEVMPerSymbolMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPBCHDataRMSEVMPerSubcarrierMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 PBCHDataRMSEVMPerSubcarrierMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPBCHDataRMSEVMPerSymbolMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 PBCHDataRMSEVMPerSymbolMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPBCHDMRSRMSEVMPerSubcarrierMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 PBCHDMRSRMSEVMPerSubcarrierMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchPBCHDMRSRMSEVMPerSymbolMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 PBCHDMRSRMSEVMPerSymbolMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchIQGainImbalancePerSubcarrierMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 IQGainImbalancePerSubcarrierMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchIQQuadratureErrorPerSubcarrierMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 IQQuadratureErrorPerSubcarrierMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ModAccFetchCompositeEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* compositeRMSEVMMean,
   float64* compositePeakEVMMaximum
);

int32 __stdcall RFmxNR_ModAccFetchFrequencyErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* frequencyErrorMean
);

int32 __stdcall RFmxNR_SEMFetchComponentCarrierMeasurementArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 absolutePower[],
   float64 peakAbsolutePower[],
   float64 peakFrequency[],
   float64 relativePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_SEMFetchLowerOffsetMarginArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 measurementStatus[],
   float64 margin[],
   float64 marginFrequency[],
   float64 marginAbsolutePower[],
   float64 marginRelativePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_SEMFetchLowerOffsetPowerArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 totalAbsolutePower[],
   float64 totalRelativePower[],
   float64 peakAbsolutePower[],
   float64 peakFrequency[],
   float64 peakRelativePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_SEMFetchUpperOffsetMarginArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 measurementStatus[],
   float64 margin[],
   float64 marginFrequency[],
   float64 marginAbsolutePower[],
   float64 marginRelativePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_SEMFetchUpperOffsetPowerArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 totalAbsolutePower[],
   float64 totalRelativePower[],
   float64 peakAbsolutePower[],
   float64 peakFrequency[],
   float64 peakRelativePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_SEMFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   float32 compositeMask[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_SEMFetchTotalAggregatedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* totalAggregatedPower
);

int32 __stdcall RFmxNR_SEMFetchMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus
);

int32 __stdcall RFmxNR_SEMFetchSubblockMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* subblockPower,
   float64* integrationBandwidth,
   float64* frequency
);

int32 __stdcall RFmxNR_SEMFetchComponentCarrierMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absolutePower,
   float64* peakAbsolutePower,
   float64* peakFrequency,
   float64* relativePower
);

int32 __stdcall RFmxNR_SEMFetchLowerOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus,
   float64* margin,
   float64* marginFrequency,
   float64* marginAbsolutePower,
   float64* marginRelativePower
);

int32 __stdcall RFmxNR_SEMFetchLowerOffsetPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* totalAbsolutePower,
   float64* totalRelativePower,
   float64* peakAbsolutePower,
   float64* peakFrequency,
   float64* peakRelativePower
);

int32 __stdcall RFmxNR_SEMFetchUpperOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus,
   float64* margin,
   float64* marginFrequency,
   float64* marginAbsolutePower,
   float64* marginRelativePower
);

int32 __stdcall RFmxNR_SEMFetchUpperOffsetPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* totalAbsolutePower,
   float64* totalRelativePower,
   float64* peakAbsolutePower,
   float64* peakFrequency,
   float64* peakRelativePower
);

int32 __stdcall RFmxNR_ACPFetchComponentCarrierMeasurementArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 absolutePower[],
   float64 relativePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ACPFetchOffsetMeasurementArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 lowerRelativePower[],
   float64 upperRelativePower[],
   float64 lowerAbsolutePower[],
   float64 upperAbsolutePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ACPFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ACPFetchAbsolutePowersTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 traceIndex,
   float64* x0,
   float64* dx,
   float32 absolutePowersTrace[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ACPFetchRelativePowersTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 traceIndex,
   float64* x0,
   float64* dx,
   float32 relativePowersTrace[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_ACPFetchTotalAggregatedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* totalAggregatedPower
);

int32 __stdcall RFmxNR_ACPFetchSubblockMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* subblockPower,
   float64* integrationBandwidth,
   float64* frequency
);

int32 __stdcall RFmxNR_ACPFetchComponentCarrierMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absolutePower,
   float64* relativePower
);

int32 __stdcall RFmxNR_ACPFetchOffsetMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* lowerRelativePower,
   float64* upperRelativePower,
   float64* lowerAbsolutePower,
   float64* upperAbsolutePower
);

int32 __stdcall RFmxNR_CHPFetchComponentCarrierMeasurementArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 absolutePower[],
   float64 relativePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_CHPFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_CHPFetchTotalAggregatedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* totalAggregatedPower
);

int32 __stdcall RFmxNR_CHPFetchSubblockPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* subblockPower
);

int32 __stdcall RFmxNR_CHPFetchComponentCarrierMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absolutePower,
   float64* relativePower
);

int32 __stdcall RFmxNR_PVTFetchWindowedSignalPowerTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 windowedSignalPower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_PVTFetchMeasurementArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 measurementStatus[],
   float64 absoluteOFFPowerBefore[],
   float64 absoluteOFFPowerAfter[],
   float64 absoluteONPower[],
   float64 burstWidth[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_PVTFetchSignalPowerTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 signalPower[],
   float32 absoluteLimit[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_PVTFetchMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus,
   float64* absoluteOFFPowerBefore,
   float64* absoluteOFFPowerAfter,
   float64* absoluteONPower,
   float64* burstWidth
);

int32 __stdcall RFmxNR_OBWFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_OBWFetchMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* occupiedBandwidth,
   float64* absolutePower,
   float64* startFrequency,
   float64* stopFrequency
);

int32 __stdcall RFmxNR_TXPFetchPowerTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 power[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxNR_TXPFetchMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* averagePowerMean,
   float64* peakPowerMaximum
);

int32 __stdcall RFmxNR_GetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxNR_SetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxNR_GetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxNR_SetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxNR_GetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxNR_SetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxNR_GetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetLinkDirection(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetLinkDirection(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetgNodeBCategory(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetgNodeBCategory(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetgNodeBType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetgNodeBType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetTransmitAntennaToAnalyze(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetTransmitAntennaToAnalyze(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPowerClass(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPowerClass(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPiBy2BPSKPowerBoostEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPiBy2BPSKPowerBoostEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetAutoResourceBlockDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetAutoResourceBlockDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetAutoCellIDDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetAutoCellIDDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetDownlinkChannelConfigurationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetDownlinkChannelConfigurationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetAutoIncrementCellIDEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetAutoIncrementCellIDEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetDownlinkTestModelCellIDMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetDownlinkTestModelCellIDMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetNumberOfSubblocks(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetNumberOfSubblocks(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetSubblockFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetSubblockFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetSubblockTransmitLOFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetSubblockTransmitLOFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetPhaseCompensationFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetPhaseCompensationFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetFrequencyRange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetFrequencyRange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetBand(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetBand(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetSubblockENDCNominalSpacingAdjustment(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetSubblockENDCNominalSpacingAdjustment(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetChannelRaster(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetChannelRaster(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetComponentCarrierSpacingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetComponentCarrierSpacingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetComponentCarrierAtCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetComponentCarrierAtCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetNumberOfComponentCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetNumberOfComponentCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetDownlinkTestModel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetDownlinkTestModel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetDownlinkTestModelModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetDownlinkTestModelModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetDownlinkTestModelDuplexScheme(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetDownlinkTestModelDuplexScheme(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetRatedTRP(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetRatedTRP(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetRatedEIRP(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetRatedEIRP(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetComponentCarrierBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetComponentCarrierBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetComponentCarrierFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetComponentCarrierFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetComponentCarrierAllocated(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetComponentCarrierAllocated(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetComponentCarrierRadioAccessType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetComponentCarrierRadioAccessType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetCellID(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetCellID(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetReferenceGridSubcarrierSpacing(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetReferenceGridSubcarrierSpacing(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetReferenceGridStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetReferenceGridStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetReferenceGridSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetReferenceGridSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetSubBandAllocation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxNR_SetSubBandAllocation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxNR_GetNumberOfBandwidthParts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetNumberOfBandwidthParts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetBandwidthPartSubcarrierSpacing(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetBandwidthPartSubcarrierSpacing(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetBandwidthPartCyclicPrefixMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetBandwidthPartCyclicPrefixMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetGridStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetGridStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetGridSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetGridSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetBandwidthPartResourceBlockOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetBandwidthPartResourceBlockOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetBandwidthPartNumberOfResourceBlocks(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetBandwidthPartNumberOfResourceBlocks(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetNumberOfUsers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetNumberOfUsers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetRNTI(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetRNTI(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetNumberOfPUSCHConfigurations(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetNumberOfPUSCHConfigurations(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHTransformPrecodingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHTransformPrecodingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHNumberOfResourceBlockClusters(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHNumberOfResourceBlockClusters(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHResourceBlockOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHResourceBlockOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHNumberOfResourceBlocks(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHNumberOfResourceBlocks(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHDMRSReleaseVersion(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHDMRSReleaseVersion(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHDMRSAntennaPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxNR_SetPUSCHDMRSAntennaPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxNR_GetPUSCHDMRSPowerMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHDMRSPowerMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHDMRSPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHDMRSPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHDMRSNumberOfCDMGroups(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHDMRSNumberOfCDMGroups(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHDMRSScramblingIDMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHDMRSScramblingIDMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHDMRSScramblingID(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHDMRSScramblingID(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHDMRSNSCID(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHDMRSNSCID(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHDMRSGroupHoppingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHDMRSGroupHoppingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHDMRSSequenceHoppingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHDMRSSequenceHoppingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHDMRSPUSCHIDMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHDMRSPUSCHIDMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHDMRSPUSCHID(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHDMRSPUSCHID(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHDMRSConfigurationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHDMRSConfigurationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHMappingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHMappingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHDMRSTypeAPosition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHDMRSTypeAPosition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHDMRSDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHDMRSDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHDMRSAdditionalPositions(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHDMRSAdditionalPositions(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHPTRSEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHPTRSEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHPTRSAntennaPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxNR_SetPUSCHPTRSAntennaPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxNR_GetPUSCHPTRSPowerMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHPTRSPowerMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHPTRSPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHPTRSPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetNumberOfPTRSGroups(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetNumberOfPTRSGroups(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetSamplesPerPTRSGroup(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetSamplesPerPTRSGroup(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHPTRSTimeDensity(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHPTRSTimeDensity(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHPTRSFrequencyDensity(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHPTRSFrequencyDensity(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHPTRSREOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPUSCHPTRSREOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPUSCHSlotAllocation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxNR_SetPUSCHSlotAllocation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxNR_GetPUSCHSymbolAllocation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxNR_SetPUSCHSymbolAllocation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxNR_GetNumberOfPDSCHConfigurations(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetNumberOfPDSCHConfigurations(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPDSCHNumberOfResourceBlockClusters(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPDSCHNumberOfResourceBlockClusters(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPDSCHResourceBlockOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPDSCHResourceBlockOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPDSCHNumberOfResourceBlocks(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPDSCHNumberOfResourceBlocks(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPDSCHModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPDSCHModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPDSCHDMRSReleaseVersion(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPDSCHDMRSReleaseVersion(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPDSCHDMRSAntennaPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxNR_SetPDSCHDMRSAntennaPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxNR_GetPDSCHDMRSPowerMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPDSCHDMRSPowerMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPDSCHDMRSPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetPDSCHDMRSPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetPDSCHDMRSNumberOfCDMGroups(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPDSCHDMRSNumberOfCDMGroups(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPDSCHDMRSScramblingIDMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPDSCHDMRSScramblingIDMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPDSCHDMRSScramblingID(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPDSCHDMRSScramblingID(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPDSCHDMRSnSCID(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPDSCHDMRSnSCID(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPDSCHDMRSConfigurationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPDSCHDMRSConfigurationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPDSCHMappingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPDSCHMappingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPDSCHDMRSTypeAPosition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPDSCHDMRSTypeAPosition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPDSCHDMRSDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPDSCHDMRSDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPDSCHDMRSAdditionalPositions(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPDSCHDMRSAdditionalPositions(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPDSCHPTRSEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPDSCHPTRSEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPDSCHPTRSAntennaPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxNR_SetPDSCHPTRSAntennaPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxNR_GetPDSCHPTRSPowerMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPDSCHPTRSPowerMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetEPRERatioPort(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetEPRERatioPort(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPDSCHPTRSPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetPDSCHPTRSPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetPDSCHPTRSTimeDensity(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPDSCHPTRSTimeDensity(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPDSCHPTRSFrequencyDensity(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPDSCHPTRSFrequencyDensity(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPDSCHPTRSREOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPDSCHPTRSREOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPDSCHSlotAllocation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxNR_SetPDSCHSlotAllocation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxNR_GetPDSCHSymbolAllocation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxNR_SetPDSCHSymbolAllocation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxNR_GetNumberOfCORESETs(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetNumberOfCORESETs(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetCORESETSymbolOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetCORESETSymbolOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetCORESETNumberOfSymbols(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetCORESETNumberOfSymbols(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetCORESETNumberOfResourceBlockClusters(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetCORESETNumberOfResourceBlockClusters(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetCORESETResourceBlockOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetCORESETResourceBlockOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetCORESETNumberOfResourceBlocks(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetCORESETNumberOfResourceBlocks(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetCORESETPrecodingGranularity(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetCORESETPrecodingGranularity(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetCORESETCCEToREGMappingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetCORESETCCEToREGMappingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetCORESETREGBundleSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetCORESETREGBundleSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetCORESETInterleaverSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetCORESETInterleaverSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetCORESETShiftIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetCORESETShiftIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetNumberOfPDCCHConfigurations(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetNumberOfPDCCHConfigurations(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPDCCHCCEAggregationLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPDCCHCCEAggregationLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPDCCHCCEOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPDCCHCCEOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPDCCHSlotAllocation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxNR_SetPDCCHSlotAllocation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxNR_GetSSBEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetSSBEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetSSBGridStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetSSBGridStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetSSBGridSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetSSBGridSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetSSBCRBOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetSSBCRBOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetSubcarrierSpacingCommon(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetSubcarrierSpacingCommon(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetSSBSubcarrierOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetSSBSubcarrierOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetSSBPeriodicity(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetSSBPeriodicity(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetSSBPattern(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetSSBPattern(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetSSBActiveBlocks(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxNR_SetSSBActiveBlocks(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxNR_GetPSSPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetPSSPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetSSSPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetSSSPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetPBCHPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetPBCHPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetPBCHDMRSPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetPBCHDMRSPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetSSBHRFIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetSSBHRFIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetNumberOfSteps(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetNumberOfSteps(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetListStepTimerDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetListStepTimerDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetListStepTimerUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetListStepTimerUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetListStepTimerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetListStepTimerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_GetAcquisitionBandwidthOptimizationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetAcquisitionBandwidthOptimizationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetTransmitterArchitecture(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetTransmitterArchitecture(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetPhaseCompensation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPhaseCompensation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetReferenceGridAlignmentMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetReferenceGridAlignmentMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetGridSizeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetGridSizeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_ModAccGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetMulticarrierFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetMulticarrierFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetFrequencyErrorEstimation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetFrequencyErrorEstimation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetSymbolClockErrorEstimationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetSymbolClockErrorEstimationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetIQImpairmentsModel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetIQImpairmentsModel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetIQOriginOffsetEstimationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetIQOriginOffsetEstimationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetIQMismatchEstimationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetIQMismatchEstimationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetIQGainImbalanceCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetIQGainImbalanceCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetIQQuadratureErrorCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetIQQuadratureErrorCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetIQTimingSkewCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetIQTimingSkewCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetIQImpairmentsPerSubcarrierEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetIQImpairmentsPerSubcarrierEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetMagnitudeAndPhaseErrorEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetMagnitudeAndPhaseErrorEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetEVMReferenceDataSymbolsMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetEVMReferenceDataSymbolsMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetMeasurementLengthUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetMeasurementLengthUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_ModAccGetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_ModAccGetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetChannelEstimationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetChannelEstimationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetPhaseTrackingMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetPhaseTrackingMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetTimingTrackingMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetTimingTrackingMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetPreFFTErrorEstimationInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetPreFFTErrorEstimationInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetEVMUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetEVMUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetFFTWindowType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetFFTWindowType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetFFTWindowOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetFFTWindowOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_ModAccGetFFTWindowLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetFFTWindowLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_ModAccGetDCSubcarrierRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetDCSubcarrierRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetCommonClockSourceEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetCommonClockSourceEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetSpectralFlatnessCondition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetSpectralFlatnessCondition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetNoiseCompensationInputPowerCheckEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetNoiseCompensationInputPowerCheckEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetNoiseCompensationReferenceLevelCoercionLimit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetNoiseCompensationReferenceLevelCoercionLimit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_ModAccGetMeasurementMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetMeasurementMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetCompositeResultsIncludeDMRS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetCompositeResultsIncludeDMRS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetCompositeResultsIncludePTRS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetCompositeResultsIncludePTRS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetAutoLevelAllowOverflow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetAutoLevelAllowOverflow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetShortFrameEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetShortFrameEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetShortFrameLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetShortFrameLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_ModAccGetShortFrameLengthUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetShortFrameLengthUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetTransientPeriodEVMMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetTransientPeriodEVMMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetTransientPeriod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetTransientPeriod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_ModAccGetTransientPowerChangeThreshold(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetTransientPowerChangeThreshold(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_ModAccGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsDetectedCellID(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsCompositeRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsCompositePeakEVMMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsCompositePeakEVMBWPIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsCompositePeakEVMSlotIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsCompositePeakEVMSymbolIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsCompositePeakEVMSubcarrierIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsCompositeRMSMagnitudeErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsCompositePeakMagnitudeErrorMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsCompositeRMSPhaseErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsCompositePeakPhaseErrorMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsSCHSymbolPowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsSCHDetectedModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPUSCHDataRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPUSCHDataPeakEVMMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPUSCHDMRSRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPUSCHDMRSPeakEVMMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPUSCHPTRSRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPUSCHPTRSPeakEVMMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPUSCHDataTransientRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPUSCHPeakPhaseOffsetMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPUSCHPeakPhaseOffsetSlotIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPDSCHQPSKRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPDSCH16QAMRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPDSCH64QAMRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPDSCH256QAMRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPDSCH1024QAMRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPDSCH8PSKRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPDSCHDataRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPDSCHDataPeakEVMMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPDSCHDMRSRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPDSCHDMRSPeakEVMMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPDSCHPTRSRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPDSCHPTRSPeakEVMMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPSSRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPSSPeakEVMMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsSSSRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsSSSPeakEVMMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPBCHDataRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPBCHDataPeakEVMMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPBCHDMRSRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsPBCHDMRSPeakEVMMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsInBandEmissionMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsSubblockInBandEmissionMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsSpectralFlatnessMarginSlotIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsSpectralFlatnessRange1MaximumToRange1Minimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsSpectralFlatnessRange2MaximumToRange2Minimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsSpectralFlatnessRange1MaximumToRange2Minimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsSpectralFlatnessRange2MaximumToRange1Minimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsSpectralFlatnessRange1Maximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsSpectralFlatnessRange1Minimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsSpectralFlatnessRange2Maximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsSpectralFlatnessRange2Minimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsSpectralFlatnessRange1MaximumSubcarrierIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsSpectralFlatnessRange1MinimumSubcarrierIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsSpectralFlatnessRange2MaximumSubcarrierIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsSpectralFlatnessRange2MinimumSubcarrierIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsComponentCarrierTimeOffsetMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsComponentCarrierFrequencyErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsComponentCarrierSlotFrequencyErrorMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsComponentCarrierSymbolClockErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsComponentCarrierSlotIQOriginOffsetMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsComponentCarrierIQOriginOffsetMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsComponentCarrierIQGainImbalanceMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsComponentCarrierQuadratureErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsComponentCarrierIQTimingSkewMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsSubblockLOComponentCarrierIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsSubblockLOSubcarrierIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsSubblockIQOriginOffsetMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ModAccGetResultsNoiseCompensationApplied(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetChannelConfigurationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetChannelConfigurationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetSubblockIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ACPSetSubblockIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_ACPGetSubblockOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ACPSetSubblockOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_ACPGetComponentCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ACPSetComponentCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_ACPGetNumberOfUTRAOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetNumberOfUTRAOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetNumberOfEUTRAOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetNumberOfEUTRAOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetNumberOfNROffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetNumberOfNROffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetNumberOfENDCOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetNumberOfENDCOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetOffsetChannelSpacingAdjustment(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ACPSetOffsetChannelSpacingAdjustment(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_ACPGetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetOffsetFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ACPSetOffsetFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_ACPGetOffsetSideband(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetOffsetSideband(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetOffsetIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ACPSetOffsetIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_ACPGetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ACPSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_ACPGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ACPSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_ACPGetPowerUnits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetPowerUnits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetNoiseCalibrationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetNoiseCalibrationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetNoiseCalibrationAveragingAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetNoiseCalibrationAveragingAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetNoiseCalibrationAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetNoiseCalibrationAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetNoiseCompensationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetNoiseCompensationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetMeasurementMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetMeasurementMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetFFTWindow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetFFTWindow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetFFTOverlapMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetFFTOverlapMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetFFTOverlap(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ACPSetFFTOverlap(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_ACPGetIFOutputPowerOffsetAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetIFOutputPowerOffsetAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetNearIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ACPSetNearIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_ACPGetFarIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ACPSetFarIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_ACPGetSequentialFFTSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetSequentialFFTSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ACPSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPGetResultsTotalAggregatedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ACPGetResultsSubblockPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ACPGetResultsComponentCarrierAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ACPGetResultsComponentCarrierRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ACPGetResultsLowerOffsetAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ACPGetResultsLowerOffsetRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ACPGetResultsUpperOffsetAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_ACPGetResultsUpperOffsetRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_CHPGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_CHPSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_CHPGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_CHPSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_CHPGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_CHPSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_CHPGetIntegrationBandwidthType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_CHPSetIntegrationBandwidthType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_CHPGetSubblockIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_CHPGetComponentCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_CHPGetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_CHPSetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_CHPGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_CHPSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_CHPGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_CHPSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_CHPGetNoiseCalibrationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_CHPSetNoiseCalibrationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_CHPGetNoiseCalibrationAveragingAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_CHPSetNoiseCalibrationAveragingAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_CHPGetNoiseCalibrationAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_CHPSetNoiseCalibrationAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_CHPGetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_CHPSetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_CHPGetNoiseCompensationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_CHPSetNoiseCompensationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_CHPGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_CHPSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_CHPGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_CHPSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_CHPGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_CHPSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_CHPGetMeasurementMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_CHPSetMeasurementMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_CHPGetFFTWindow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_CHPSetFFTWindow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_CHPGetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_CHPSetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_CHPGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_CHPSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_CHPGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_CHPSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_CHPGetResultsTotalAggregatedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_CHPGetResultsSubblockPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_CHPGetResultsComponentCarrierAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_CHPGetResultsComponentCarrierRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_OBWGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_OBWSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_OBWGetSpanAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_OBWSetSpanAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_OBWGetSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_OBWSetSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_OBWGetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_OBWSetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_OBWGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_OBWSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_OBWGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_OBWSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_OBWGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_OBWSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_OBWGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_OBWSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_OBWGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_OBWSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_OBWGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_OBWSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_OBWGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_OBWSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_OBWGetFFTWindow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_OBWSetFFTWindow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_OBWGetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_OBWSetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_OBWGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_OBWSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_OBWGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_OBWSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_OBWGetResultsOccupiedBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_OBWGetResultsAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_OBWGetResultsStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_OBWGetResultsStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SEMSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_SEMGetUplinkMaskType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SEMSetUplinkMaskType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_SEMGetDownlinkMaskType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SEMSetDownlinkMaskType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_SEMGetDeltaFMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMSetDeltaFMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_SEMGetSubblockIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetSubblockAggregatedChannelBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetComponentCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetComponentCarrierRatedOutputPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMSetComponentCarrierRatedOutputPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_SEMGetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SEMSetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_SEMGetOffsetStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMSetOffsetStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_SEMGetOffsetStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMSetOffsetStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_SEMGetOffsetSideband(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SEMSetOffsetSideband(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_SEMGetOffsetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMSetOffsetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_SEMGetOffsetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SEMSetOffsetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_SEMGetOffsetBandwidthIntegral(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SEMSetOffsetBandwidthIntegral(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_SEMGetOffsetLimitFailMask(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SEMSetOffsetLimitFailMask(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_SEMGetOffsetAbsoluteLimitStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMSetOffsetAbsoluteLimitStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_SEMGetOffsetFrequencyDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SEMSetOffsetFrequencyDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_SEMGetOffsetAbsoluteLimitStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMSetOffsetAbsoluteLimitStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_SEMGetOffsetRelativeLimitStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMSetOffsetRelativeLimitStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_SEMGetOffsetRelativeLimitStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMSetOffsetRelativeLimitStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_SEMGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SEMSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_SEMGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_SEMGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SEMSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_SEMGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SEMSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_SEMGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SEMSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_SEMGetFFTWindow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SEMSetFFTWindow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_SEMGetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SEMSetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_SEMGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SEMSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_SEMGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SEMSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsTotalAggregatedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsSubblockPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsComponentCarrierAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsComponentCarrierRelativeIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsComponentCarrierAbsolutePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsComponentCarrierPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsLowerOffsetMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsLowerOffsetAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsLowerOffsetRelativeIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsLowerOffsetAbsolutePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsLowerOffsetRelativePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsLowerOffsetPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsLowerOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsLowerOffsetMarginAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsLowerOffsetMarginRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsLowerOffsetMarginFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsUpperOffsetMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsUpperOffsetAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsUpperOffsetRelativeIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsUpperOffsetAbsolutePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsUpperOffsetRelativePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsUpperOffsetPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsUpperOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsUpperOffsetMarginAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsUpperOffsetMarginRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_SEMGetResultsUpperOffsetMarginFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_TXPGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_TXPSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_TXPGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_TXPSetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_TXPGetMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_TXPSetMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_TXPGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_TXPSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_TXPGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_TXPSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_TXPGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_TXPSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_TXPGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_TXPSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_TXPGetResultsAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_TXPGetResultsPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_PVTGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_PVTSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_PVTGetMeasurementIntervalAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_PVTSetMeasurementIntervalAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_PVTGetMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_PVTSetMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_PVTGetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_PVTSetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_PVTGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_PVTSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_PVTGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_PVTSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_PVTGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_PVTSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_PVTGetOFFPowerExclusionBefore(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_PVTSetOFFPowerExclusionBefore(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_PVTGetOFFPowerExclusionAfter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_PVTSetOFFPowerExclusionAfter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxNR_PVTGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_PVTSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_PVTGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_PVTSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_PVTGetResultsMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_PVTGetResultsAbsoluteOFFPowerBefore(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_PVTGetResultsAbsoluteOFFPowerAfter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_PVTGetResultsAbsoluteONPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_PVTGetResultsBurstWidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_PVTGetResultsPeakWindowedOFFPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_PVTGetResultsPeakWindowedOFFPowerMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxNR_PVTGetResultsPeakWindowedOFFPowerTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

#ifdef __cplusplus
}
#endif

/* ---------------- Obsolete Section ------------------ */

#define RFMXNR_ATTR_MODACC_EVM_WITH_EXCLUSION_PERIOD_ENABLED                               0x0090400f
#define RFMXNR_ATTR_MODACC_IQ_IMPAIRMENTS_ESTIMATION_ENABLED                               0x00904077
#define RFMXNR_ATTR_PDSCH_PRESENT_IN_SSB_RESOURCE_BLOCK                                    0x00900097
#define RFMXNR_ATTR_SUBBLOCK_FREQUENCY_DEFINITION                                          0x00900011
#define RFMXNR_ATTR_MODACC_PHASE_TRACKING_ENABLED                                          0x00904051
#define RFMXNR_ATTR_MODACC_TIMING_TRACKING_ENABLED                                         0x00904052

// Values for RFMXNR_ATTR_MODACC_EVM_WITH_EXCLUSION_PERIOD_ENABLED
#define RFMXNR_VAL_MODACC_EVM_WITH_EXCLUSION_PERIOD_ENABLED_FALSE                                 0
#define RFMXNR_VAL_MODACC_EVM_WITH_EXCLUSION_PERIOD_ENABLED_TRUE                                  1

// Values for RFMXNR_ATTR_MODACC_IQ_IMPAIRMENTS_ESTIMATION_ENABLED
#define RFMXNR_VAL_MODACC_IQ_IMPAIRMENTS_ESTIMATION_ENABLED_FALSE                                 0
#define RFMXNR_VAL_MODACC_IQ_IMPAIRMENTS_ESTIMATION_ENABLED_TRUE                                  1

// Values for RFMXNR_ATTR_PDSCH_PRESENT_IN_SSB_RESOURCE_BLOCK
#define RFMXNR_VAL_PDSCH_PRESENT_IN_SSB_RESOURCE_BLOCK_FALSE                                      0
#define RFMXNR_VAL_PDSCH_PRESENT_IN_SSB_RESOURCE_BLOCK_TRUE                                       1

// Values for RFMXNR_ATTR_SUBBLOCK_FREQUENCY_DEFINITION
#define RFMXNR_VAL_SUBBLOCK_FREQUENCY_DEFINITION_RELATIVE                                         0
#define RFMXNR_VAL_SUBBLOCK_FREQUENCY_DEFINITION_ABSOLUTE                                         1

// Values for RFMXNR_ATTR_MODACC_PHASE_TRACKING_ENABLED
#define RFMXNR_VAL_MODACC_PHASE_TRACKING_ENABLED_FALSE                                            0
#define RFMXNR_VAL_MODACC_PHASE_TRACKING_ENABLED_TRUE                                             1

// Values for RFMXNR_ATTR_MODACC_TIMING_TRACKING_ENABLED
#define RFMXNR_VAL_MODACC_TIMING_TRACKING_ENABLED_FALSE                                           0
#define RFMXNR_VAL_MODACC_TIMING_TRACKING_ENABLED_TRUE                                            1

#ifdef __cplusplus
extern "C"
{
#endif

int32 __stdcall RFmxNR_AnalyzeIQ(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[],
   float64 x0,
   float64 dx,
   NIComplexSingle IQ[],
   int32 arraySize,
   int32 reset,
   int32* averagingDone
);

int32 __stdcall RFmxNR_AnalyzeIQSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[],
   float64 x0,
   float64 dx,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32 reset,
   int32* averagingDone
);

int32 __stdcall RFmxNR_AnalyzeSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[],
   float64 x0,
   float64 dx,
   float32 spectrum[],
   int32 arraySize,
   int32 reset,
   int32* averagingDone
);

int32 __stdcall RFmxNR_ModAccGetEVMWithExclusionPeriodEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetEVMWithExclusionPeriodEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetIQImpairmentsEstimationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetIQImpairmentsEstimationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ACPFetchSubblockPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* subblockPower
);

int32 __stdcall RFmxNR_SEMFetchSubblockPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* subblockPower
);

int32 __stdcall RFmxNR_GetPDSCHPresentInSSBResourceBlock(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetPDSCHPresentInSSBResourceBlock(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_GetSubblockFrequencyDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_SetSubblockFrequencyDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetPhaseTrackingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetPhaseTrackingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxNR_ModAccGetTimingTrackingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxNR_ModAccSetTimingTrackingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

#ifdef __cplusplus
}
#endif


#endif

