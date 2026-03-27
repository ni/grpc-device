attributes = {
    0: {
        'access': 'read-write',
        'name': 'CARRIER_FREQUENCY',
        'type': 'float64'
    },
    2: {
        'access': 'read-write',
        'name': 'OVERSAMPLING_FACTOR',
        'type': 'int32'
    },
    3: {
        'access': 'read-write',
        'name': 'IDLE_INTERVAL',
        'type': 'float64'
    },
    4: {
        'access': 'read-write',
        'enum': 'DsssPreambleType',
        'name': 'DSSS_PREAMBLE_TYPE',
        'type': 'int32'
    },
    5: {
        'access': 'read-write',
        'name': 'PAYLOAD_DATA_LENGTH',
        'type': 'int32'
    },
    6: {
        'access': 'read-write',
        'name': 'NUMBER_OF_FRAMES',
        'type': 'int32'
    },
    7: {
        'access': 'read-write',
        'enum': 'PayloadDataType',
        'name': 'PAYLOAD_DATA_TYPE',
        'type': 'int32'
    },
    8: {
        'access': 'read-write',
        'name': 'PAYLOAD_PN_ORDER',
        'type': 'int32'
    },
    9: {
        'access': 'read-write',
        'name': 'PAYLOAD_PN_SEED',
        'type': 'int32'
    },
    10: {
        'access': 'read-write',
        'name': 'PAYLOAD_USER_DEFINED_BITS',
        'type': 'int32[]'
    },
    11: {
        'access': 'read-write',
        'enum': 'MacHeaderEnabled',
        'name': 'MAC_HEADER_ENABLED',
        'type': 'int32'
    },
    12: {
        'access': 'read-write',
        'name': 'SUBCARRIER_MASK',
        'type': 'float64[]'
    },
    13: {
        'access': 'read-write',
        'enum': 'LockedClockBitEnabled',
        'name': 'LOCKED_CLOCK_BIT_ENABLED',
        'type': 'int32'
    },
    14: {
        'access': 'read-write',
        'enum': 'HeaderEncoderEnabled',
        'name': 'HEADER_ENCODER_ENABLED',
        'type': 'int32'
    },
    15: {
        'access': 'read-write',
        'enum': 'HeaderInterleaverEnabled',
        'name': 'HEADER_INTERLEAVER_ENABLED',
        'type': 'int32'
    },
    16: {
        'access': 'read-write',
        'enum': 'PayloadScramblerEnabled',
        'name': 'PAYLOAD_SCRAMBLER_ENABLED',
        'type': 'int32'
    },
    17: {
        'access': 'read-write',
        'name': 'PAYLOAD_SCRAMBLER_SEED',
        'type': 'int32'
    },
    18: {
        'access': 'read-write',
        'enum': 'PayloadEncoderEnabled',
        'name': 'PAYLOAD_ENCODER_ENABLED',
        'type': 'int32'
    },
    19: {
        'access': 'read-write',
        'enum': 'PayloadInterleaverEnabled',
        'name': 'PAYLOAD_INTERLEAVER_ENABLED',
        'type': 'int32'
    },
    20: {
        'access': 'read-write',
        'name': 'CARRIER_FREQUENCY_OFFSET',
        'type': 'float64'
    },
    21: {
        'access': 'read-write',
        'name': 'IQ_GAIN_IMBALANCE',
        'type': 'float64'
    },
    22: {
        'access': 'read-write',
        'name': 'I_DC_OFFSET',
        'type': 'float64'
    },
    23: {
        'access': 'read-write',
        'name': 'Q_DC_OFFSET',
        'type': 'float64'
    },
    24: {
        'access': 'read-write',
        'name': 'QUADRATURE_SKEW',
        'type': 'float64'
    },
    25: {
        'access': 'read-write',
        'name': 'SAMPLE_CLOCK_OFFSET',
        'type': 'float64'
    },
    26: {
        'access': 'read-write',
        'enum': 'PulseShapingFilterType',
        'name': 'PULSE_SHAPING_FILTER_TYPE',
        'type': 'int32'
    },
    27: {
        'access': 'read-write',
        'name': 'PULSE_SHAPING_FILTER_PARAMETER',
        'type': 'float64'
    },
    29: {
        'access': 'read-write',
        'name': 'DSSS_WINDOW_LENGTH',
        'type': 'float64'
    },
    31: {
        'access': 'read-write',
        'enum': 'Standard',
        'name': 'STANDARD',
        'type': 'int32'
    },
    32: {
        'access': 'read-write',
        'enum': 'OfdmDataRate',
        'name': 'OFDM_DATA_RATE',
        'type': 'int32'
    },
    33: {
        'access': 'read-write',
        'enum': 'DsssDataRate',
        'name': 'DSSS_DATA_RATE',
        'type': 'int32'
    },
    35: {
        'access': 'read-write',
        'name': 'IQ_RATE',
        'type': 'float64'
    },
    37: {
        'access': 'read-write',
        'name': 'IQ_WAVEFORM_SIZE',
        'type': 'int32'
    },
    40: {
        'access': 'read-write',
        'name': 'HEADROOM',
        'type': 'float64'
    },
    41: {
        'access': 'read-write',
        'name': 'MCS_INDEX',
        'type': 'int32'
    },
    42: {
        'access': 'read-write',
        'name': 'CHANNEL_BANDWIDTH',
        'type': 'float64'
    },
    43: {
        'access': 'read-write',
        'enum': 'PlcpFrameFormat80211n',
        'name': '80211N_PLCP_FRAME_FORMAT',
        'type': 'int32'
    },
    46: {
        'access': 'read-write',
        'name': 'NUMBER_OF_EXTENSION_SPATIAL_STREAMS',
        'type': 'int32'
    },
    47: {
        'access': 'read-write',
        'name': 'NUMBER_OF_TRANSMIT_CHANNELS',
        'type': 'int32'
    },
    49: {
        'access': 'read-write',
        'name': 'STBC_INDEX',
        'type': 'int32'
    },
    53: {
        'access': 'read-write',
        'enum': 'MacQosControlEnabled',
        'name': 'MAC_QOS_CONTROL_ENABLED',
        'type': 'int32'
    },
    54: {
        'access': 'read-write',
        'enum': 'PulseShapingFilterEnabled',
        'name': 'PULSE_SHAPING_FILTER_ENABLED',
        'type': 'int32'
    },
    55: {
        'access': 'read-write',
        'enum': 'MappingMatrixType',
        'name': 'MAPPING_MATRIX_TYPE',
        'type': 'int32'
    },
    56: {
        'access': 'read-write',
        'enum': 'CompatibilityVersion',
        'name': 'COMPATIBILITY_VERSION',
        'type': 'int32'
    },
    57: {
        'access': 'read-write',
        'name': 'MAC_FRAME_CONTROL',
        'type': 'int32'
    },
    58: {
        'access': 'read-write',
        'name': 'MAC_DURATION_OR_ID',
        'type': 'int32'
    },
    59: {
        'access': 'read-write',
        'enum': 'MacAddress1Enabled',
        'name': 'MAC_ADDRESS1_ENABLED',
        'type': 'int32'
    },
    60: {
        'access': 'read-write',
        'name': 'MAC_ADDRESS1',
        'type': 'int64'
    },
    61: {
        'access': 'read-write',
        'enum': 'MacAddress2Enabled',
        'name': 'MAC_ADDRESS2_ENABLED',
        'type': 'int32'
    },
    62: {
        'access': 'read-write',
        'name': 'MAC_ADDRESS2',
        'type': 'int64'
    },
    63: {
        'access': 'read-write',
        'enum': 'MacAddress3Enabled',
        'name': 'MAC_ADDRESS3_ENABLED',
        'type': 'int32'
    },
    64: {
        'access': 'read-write',
        'name': 'MAC_ADDRESS3',
        'type': 'int64'
    },
    65: {
        'access': 'read-write',
        'enum': 'MacSequenceControlEnabled',
        'name': 'MAC_SEQUENCE_CONTROL_ENABLED',
        'type': 'int32'
    },
    66: {
        'access': 'read-write',
        'name': 'MAC_SEQUENCE_CONTROL',
        'type': 'int32'
    },
    67: {
        'access': 'read-write',
        'enum': 'MacAddress4Enabled',
        'name': 'MAC_ADDRESS4_ENABLED',
        'type': 'int32'
    },
    68: {
        'access': 'read-write',
        'name': 'MAC_ADDRESS4',
        'type': 'int64'
    },
    70: {
        'access': 'read-write',
        'enum': 'FecCodingType',
        'name': 'FEC_CODING_TYPE',
        'type': 'int32'
    },
    71: {
        'access': 'read-write',
        'name': 'MAC_QOS_CONTROL',
        'type': 'int32'
    },
    72: {
        'access': 'read-write',
        'enum': 'MacHTControlEnabled',
        'name': 'MAC_HT_CONTROL_ENABLED',
        'type': 'int32'
    },
    73: {
        'access': 'read-write',
        'name': 'MAC_HT_CONTROL',
        'type': 'int32'
    },
    74: {
        'access': 'read-write',
        'enum': 'WindowingMethod',
        'name': 'WINDOWING_METHOD',
        'type': 'int32'
    },
    75: {
        'access': 'read-write',
        'name': 'NUMBER_OF_SEGMENTS',
        'type': 'int32'
    },
    76: {
        'access': 'read-write',
        'name': 'NUMBER_OF_SPACE_TIME_STREAMS',
        'type': 'int32'
    },
    77: {
        'access': 'read-write',
        'enum': 'StbcAllStreamsEnabled',
        'name': 'STBC_ALL_STREAMS_ENABLED',
        'type': 'int32'
    },
    78: {
        'access': 'read-write',
        'enum': 'SwapIAndQEnabled',
        'name': 'SWAP_I_AND_Q_ENABLED',
        'type': 'int32'
    },
    79: {
        'access': 'read-write',
        'name': 'TIMING_SKEW',
        'type': 'float64'
    },
    80: {
        'access': 'read-write',
        'enum': 'MacSequenceNumberIncrementEnabled',
        'name': 'MAC_SEQUENCE_NUMBER_INCREMENT_ENABLED',
        'type': 'int32'
    },
    81: {
        'access': 'read-write',
        'name': 'MAC_SEQUENCE_NUMBER_INCREMENT_INTERVAL',
        'type': 'int32'
    },
    82: {
        'access': 'read-write',
        'enum': 'MacFragmentNumberIncrementEnabled',
        'name': 'MAC_FRAGMENT_NUMBER_INCREMENT_ENABLED',
        'type': 'int32'
    },
    83: {
        'access': 'read-write',
        'name': 'MPDU_LENGTH',
        'type': 'int32'
    },
    86: {
        'access': 'read-write',
        'name': 'NOT_SOUNDING_BIT',
        'type': 'int32'
    },
    87: {
        'access': 'read-write',
        'enum': 'AutoHeadroomEnabled',
        'name': 'AUTO_HEADROOM_ENABLED',
        'type': 'int32'
    },
    88: {
        'access': 'read-write',
        'name': 'ACTUAL_HEADROOM',
        'type': 'float64'
    },
    89: {
        'access': 'read-write',
        'name': 'ACTUAL_OFDM_DATA_RATE',
        'type': 'float64'
    },
    90: {
        'access': 'read-write',
        'enum': 'RFBlankingEnabled',
        'name': 'RF_BLANKING_ENABLED',
        'type': 'int32'
    },
    91: {
        'access': 'read-write',
        'name': 'RF_BLANKING_MARKER_POSITIONS',
        'type': 'int32[]'
    },
    94: {
        'access': 'read-write',
        'name': 'NUMBER_OF_DATA_SYMBOLS',
        'type': 'int32'
    },
    95: {
        'access': 'read-write',
        'enum': 'PpduType',
        'name': 'PPDU_TYPE',
        'type': 'int32'
    },
    96: {
        'access': 'read-write',
        'enum': 'AllIQImpairmentsEnabled',
        'name': 'ALL_IQ_IMPAIRMENTS_ENABLED',
        'type': 'int32'
    },
    97: {
        'access': 'read-write',
        'enum': 'AwgnEnabled',
        'name': 'AWGN_ENABLED',
        'type': 'int32'
    },
    98: {
        'access': 'read-write',
        'name': 'CARRIER_TO_NOISE_RATIO',
        'type': 'float64'
    },
    100: {
        'access': 'read-write',
        'enum': 'MacFcsEnabled',
        'name': 'MAC_FCS_ENABLED',
        'type': 'int32'
    },
    102: {
        'access': 'read-write',
        'name': 'MAXIMUM_HARDWARE_IQ_RATE',
        'type': 'float64'
    },
    103: {
        'access': 'read-write',
        'enum': 'AmpduEnabled',
        'name': 'AMPDU_ENABLED',
        'type': 'int32'
    },
    104: {
        'access': 'read-write',
        'name': 'PAYLOAD_NUMBER_OF_MPDUS',
        'type': 'int32'
    },
    107: {
        'access': 'read-write',
        'name': 'SAMPLE_CLOCK_RATE_FACTOR',
        'type': 'float64'
    },
    112: {
        'access': 'read-write',
        'name': 'PULSE_SHAPING_FILTER_LENGTH',
        'type': 'int32'
    },
    115: {
        'access': 'read-write',
        'name': 'NUMBER_OF_USERS',
        'type': 'int32'
    },
    118: {
        'access': 'read-write',
        'enum': 'LOSharingEnabled',
        'name': 'LO_SHARING_ENABLED',
        'type': 'int32'
    },
    119: {
        'access': 'read-write',
        'enum': 'PreambleType80211ah',
        'name': '80211AH_PREAMBLE_TYPE',
        'type': 'int32'
    },
    120: {
        'access': 'read-write',
        'enum': 'MacFrameFormat',
        'name': 'MAC_FRAME_FORMAT',
        'type': 'int32'
    },
    121: {
        'access': 'read-write',
        'name': 'MAC_ADDRESS1_LENGTH',
        'type': 'int32'
    },
    122: {
        'access': 'read-write',
        'name': 'MAC_ADDRESS2_LENGTH',
        'type': 'int32'
    },
    123: {
        'access': 'read-write',
        'enum': 'GuardIntervalType',
        'name': 'GUARD_INTERVAL_TYPE',
        'type': 'int32'
    },
    124: {
        'access': 'read-write',
        'enum': 'TransmissionMode',
        'name': 'TRANSMISSION_MODE',
        'type': 'int32'
    },
    125: {
        'access': 'read-write',
        'name': 'OFDM_WINDOW_LENGTH',
        'type': 'int32'
    },
    127: {
        'access': 'read-write',
        'enum': 'NonHTModulationMode',
        'name': 'NON_HT_MODULATION_MODE',
        'type': 'int32'
    },
    132: {
        'access': 'read-write',
        'enum': 'RUSize',
        'name': 'RU_SIZE',
        'type': 'int32'
    },
    133: {
        'access': 'read-write',
        'name': 'RU_OFFSET_MRU_INDEX',
        'type': 'int32'
    },
    134: {
        'access': 'read-write',
        'enum': 'MultiSegmentGenerationMode',
        'name': 'MULTI_SEGMENT_GENERATION_MODE',
        'type': 'int32'
    },
    135: {
        'access': 'read-write',
        'name': 'TIME_DELAY',
        'type': 'float64'
    },
    136: {
        'access': 'read-write',
        'name': 'RELATIVE_POWER',
        'type': 'float64'
    },
    144: {
        'access': 'read-write',
        'enum': 'LtfSize',
        'name': 'LTF_SIZE',
        'type': 'int32'
    },
    154: {
        'access': 'read-write',
        'enum': 'DualCarrierModulationEnabled',
        'name': 'DUAL_CARRIER_MODULATION_ENABLED',
        'type': 'int32'
    },
    159: {
        'access': 'read-write',
        'name': 'PACKET_EXTENSION_DURATION',
        'type': 'float64'
    },
    161: {
        'access': 'read-write',
        'name': 'HE_SIG_B_MCS_INDEX',
        'type': 'int32'
    },
    162: {
        'access': 'read-write',
        'enum': 'HESigBDualCarrierModulationEnabled',
        'name': 'HE_SIG_B_DUAL_CARRIER_MODULATION_ENABLED',
        'type': 'int32'
    },
    163: {
        'access': 'read-write',
        'name': 'STA_ID',
        'type': 'int32'
    },
    164: {
        'access': 'read-write',
        'name': 'POWER_BOOST_FACTOR',
        'type': 'float64'
    },
    165: {
        'access': 'read-write',
        'name': 'NUMBER_OF_LTF_SYMBOLS',
        'type': 'int32'
    },
    168: {
        'access': 'read-write',
        'name': 'FULLSCALE_BACKOFF',
        'type': 'float64'
    },
    170: {
        'access': 'read-write',
        'enum': 'AveragePowerReference',
        'name': 'AVERAGE_POWER_REFERENCE',
        'type': 'int32'
    },
    172: {
        'access': 'read-write',
        'name': 'TRIGGER_FRAME_AP_TX_POWER',
        'type': 'int32'
    },
    173: {
        'access': 'read-write',
        'name': 'TRIGGER_FRAME_TARGET_RSSI',
        'type': 'int32'
    },
    174: {
        'access': 'read-write',
        'name': 'BURST_START_LOCATIONS',
        'type': 'int32[]'
    },
    175: {
        'access': 'read-write',
        'name': 'BURST_STOP_LOCATIONS',
        'type': 'int32[]'
    },
    176: {
        'access': 'read-write',
        'enum': 'LOFrequencyOffsetMode',
        'name': 'LO_FREQUENCY_OFFSET_MODE',
        'type': 'int32'
    },
    177: {
        'access': 'read-write',
        'name': 'LO_FREQUENCY_OFFSET',
        'type': 'float64'
    },
    178: {
        'access': 'read-write',
        'enum': 'PayloadAutoNumberOfMpdus',
        'name': 'PAYLOAD_AUTO_NUMBER_OF_MPDUS',
        'type': 'int32'
    },
    179: {
        'access': 'read-write',
        'enum': 'AutoPayloadDataLengthMode',
        'name': 'AUTO_PAYLOAD_DATA_LENGTH_MODE',
        'type': 'int32'
    },
    180: {
        'access': 'read-write',
        'name': 'L_SIG_LENGTH',
        'type': 'int32'
    },
    181: {
        'access': 'read-write',
        'name': 'PRE_FEC_PADDING_FACTOR',
        'type': 'int32'
    },
    182: {
        'access': 'read-write',
        'name': 'PE_DISAMBIGUITY',
        'type': 'int32'
    },
    183: {
        'access': 'read-write',
        'name': 'LDPC_EXTRA_SYMBOL_SEGMENT',
        'type': 'int32'
    },
    184: {
        'access': 'read-write',
        'name': 'BSS_COLOR',
        'type': 'int32'
    },
    185: {
        'access': 'read-write',
        'enum': 'SpatialMappingMode',
        'name': 'SPATIAL_MAPPING_MODE',
        'type': 'int32'
    },
    186: {
        'access': 'read-write',
        'enum': 'MUMimoLtfModeEnabled',
        'name': 'MU_MIMO_LTF_MODE_ENABLED',
        'type': 'int32'
    },
    187: {
        'access': 'read-write',
        'name': 'SPACE_TIME_STREAM_OFFSET',
        'type': 'int32'
    },
    188: {
        'access': 'read-write',
        'enum': 'PayloadMacFrameType',
        'name': 'PAYLOAD_MAC_FRAME_TYPE',
        'type': 'int32'
    },
    189: {
        'access': 'read-write',
        'enum': 'TriggerFrameMacPaddingDuration',
        'name': 'TRIGGER_FRAME_MAC_PADDING_DURATION',
        'type': 'int32'
    },
    190: {
        'access': 'read-write',
        'name': 'TRIGGER_FRAME_CS_REQUIRED',
        'type': 'int32'
    },
    191: {
        'access': 'read-write',
        'enum': 'PreamblePuncturingEnabled',
        'name': 'PREAMBLE_PUNCTURING_ENABLED',
        'type': 'int32'
    },
    192: {
        'access': 'read-write',
        'name': 'PRIMARY_20MHZ_CHANNEL_INDEX',
        'type': 'int32'
    },
    193: {
        'access': 'read-write',
        'name': 'PREAMBLE_PUNCTURING_MASK',
        'type': 'int32'
    },
    194: {
        'access': 'read-write',
        'name': 'SIGNAL_BANDWIDTH',
        'type': 'float64'
    },
    195: {
        'access': 'read-write',
        'enum': 'NominalPacketPadding',
        'name': 'NOMINAL_PACKET_PADDING',
        'type': 'int32'
    },
    196: {
        'access': 'read-write',
        'name': 'TRIGGER_FRAME_AID12',
        'type': 'int32'
    },
    199: {
        'access': 'read-write',
        'enum': 'IdleIntervalMode',
        'name': 'IDLE_INTERVAL_MODE',
        'type': 'int32'
    },
    201: {
        'access': 'read-write',
        'name': 'RUN_TIME_SCALING',
        'type': 'float64'
    },
    202: {
        'access': 'read-write',
        'enum': 'WaveformFileVersion',
        'name': 'WAVEFORM_FILE_VERSION',
        'type': 'int32'
    },
    204: {
        'access': 'read-write',
        'enum': 'MidamblePeriodicity',
        'name': 'MIDAMBLE_PERIODICITY',
        'type': 'int32'
    },
    205: {
        'access': 'read-write',
        'enum': 'RUAllocationMode',
        'name': 'RU_ALLOCATION_MODE',
        'type': 'int32'
    },
    206: {
        'access': 'read-write',
        'name': 'RU_ALLOCATION',
        'type': 'int32[]'
    },
    207: {
        'access': 'read-write',
        'enum': 'UserEnabled',
        'name': 'USER_ENABLED',
        'type': 'int32'
    },
    209: {
        'access': 'read-write',
        'name': 'FRAME_DURATION',
        'type': 'float64'
    },
    210: {
        'access': 'read-write',
        'enum': 'UnframedDataModulationEnabled',
        'name': 'UNFRAMED_DATA_MODULATION_ENABLED',
        'type': 'int32'
    },
    211: {
        'access': 'read-write',
        'name': 'OVERSAMPLING_RATIO',
        'type': 'float64'
    },
    212: {
        'access': 'read-write',
        'name': 'SIG_MCS_INDEX',
        'type': 'int32'
    },
    213: {
        'access': 'read-write',
        'enum': 'SigCompressionEnabled',
        'name': 'SIG_COMPRESSION_ENABLED',
        'type': 'int32'
    },
    214: {
        'access': 'read-write',
        'enum': 'PhaseRotationCoefficient1',
        'name': 'PHASE_ROTATION_COEFFICIENT_1',
        'type': 'int32'
    },
    215: {
        'access': 'read-write',
        'enum': 'PhaseRotationCoefficient2',
        'name': 'PHASE_ROTATION_COEFFICIENT_2',
        'type': 'int32'
    },
    216: {
        'access': 'read-write',
        'enum': 'PhaseRotationCoefficient3',
        'name': 'PHASE_ROTATION_COEFFICIENT_3',
        'type': 'int32'
    },
    217: {
        'access': 'read-write',
        'name': 'CYCLIC_TIME_SHIFT',
        'type': 'float64'
    },
    222: {
        'access': 'read-write',
        'enum': 'RUType',
        'name': 'RU_TYPE',
        'type': 'int32'
    },
    223: {
        'access': 'read-write',
        'enum': 'HybridLOSharingMode',
        'name': 'HYBRID_LO_SHARING_MODE',
        'type': 'int32'
    },
    224: {
        'access': 'read-write',
        'enum': 'MultiChassisTClkSynchronizationMode',
        'name': 'MULTI_CHASSIS_TCLK_SYNCHRONIZATION_MODE',
        'type': 'int32'
    },
    225: {
        'access': 'read-write',
        'name': 'LO_SPLITTER_LOSS',
        'type': 'float64[]'
    },
    226: {
        'access': 'read-write',
        'name': 'LO_SPLITTER_LOSS_FREQUENCY',
        'type': 'float64[]'
    },
    227: {
        'access': 'read-write',
        'name': 'DISTRIBUTION_BANDWIDTH',
        'type': 'float64'
    },
    228: {
        'access': 'read-write',
        'enum': 'TwoxLdpcEnabled',
        'name': '2XLDPC_ENABLED',
        'type': 'int32'
    },
    229: {
        'access': 'read-write',
        'enum': 'UnequalModulationEnabled',
        'name': 'UNEQUAL_MODULATION_ENABLED',
        'type': 'int32'
    },
    230: {
        'access': 'read-write',
        'name': 'UNEQUAL_MODULATION_PATTERN_INDEX',
        'type': 'int32'
    },
    231: {
        'access': 'read-write',
        'enum': 'Channelization',
        'name': 'CHANNELIZATION',
        'type': 'int32'
    },
    232: {
        'access': 'read-write',
        'enum': 'HESigBCompressionMode',
        'name': 'HE_SIG_B_COMPRESSION_MODE',
        'type': 'int32'
    },
    233: {
        'access': 'read-write',
        'enum': 'InterferenceMitigationPilotsEnabled',
        'name': 'INTERFERENCE_MITIGATION_PILOTS_ENABLED',
        'type': 'int32'
    }
}
