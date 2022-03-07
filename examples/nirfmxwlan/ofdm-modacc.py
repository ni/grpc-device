r"""Fetch OFDM ModAcc data.

Steps:
  1. Open a new RFmx session.
  2. Configure the Frequency Reference properties (Clock Source and Clock Frequency).
  3. Configure the basic signal properties  (Center Frequency, Reference Level and External
     Attenuation).
  4. Configure IQ Power Edge Trigger properties (Trigger Delay, IQ Power Edge Level, Minimum Quiet
     Time).
  5. Configure Standard and Channel Bandwidth Properties.
  6. Select OFDMModAcc measurement and enable the traces.
  7. Configure the Measurement Interval.
  8. Configure Frequency Error Estimation Method.
  9. Configure Amplitude Tracking Enabled.
  10. Configure Phase Tracking Enabled.
  11. Configure Symbol Clock Error Correction Enabled.
  12. Configure Channel Estimation Type.
  13. Configure Averaging parameters.
  14. Initiate Measurement.
  15. Fetch OFDMModAcc Measurements.
  16. Close the RFmx Session.

The gRPC API is built from the C API. RFmx WLAN documentation is installed with the driver at:
  C:\Program Files (x86)\National Instruments\RFmx\WLAN\Documentation\rfmxwlancvi.chm

Getting Started:

To run this example, install "RFmx WLAN" on the server machine:
  https://www.ni.com/en-us/support/downloads/software-products/download.rfmx-wlan.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-RFmxWLAN gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-RFmxWLAN-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and physical channel name can be passed as separate
command line arguments.
  > python ofdm-modacc.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedDevice" as the resource name.
"""

import sys

import grpc
import nirfmxinstr_pb2 as nirfmxinstr_types
import nirfmxinstr_pb2_grpc as grpc_nirfmxinstr
import nirfmxwlan_pb2 as nirfmxwlan_types
import nirfmxwlan_pb2_grpc as grpc_nirfmxwlan

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "RFmxWLANSession"

# Resource name and options for a simulated 5663 client.
RESOURCE = "SimulatedDevice"
OPTIONS = "Simulate=1,DriverSetup=Model:5663"

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    RESOURCE = sys.argv[3]
    OPTIONS = ""

# Create a gRPC channel + client.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
client = grpc_nirfmxwlan.NiRFmxWLANStub(channel)
instr_client = grpc_nirfmxinstr.NiRFmxInstrStub(channel)
instr = None


def raise_if_initialization_error(response):
    """Raise an exception if an error was returned from Initialize."""
    if response.status < 0:
        raise RuntimeError(f"Error: {response.error_message or response.status}")
    if response.status > 0:
        sys.stderr.write(f"Warning: {response.error_message or response.status}\n")
    return response


def raise_if_error(response):
    """Raise an exception if an error was returned."""
    if response.status != 0:
        error_response = client.GetError(
            nirfmxwlan_types.GetErrorRequest(
                instrument=instr,
            )
        )
        if response.status < 0:
            raise RuntimeError(f"Error: {error_response.error_description or response.status}")
        else:
            sys.stderr.write(f"Warning: {error_response.error_description or response.status}\n")

    return response


try:
    initialize_response = raise_if_initialization_error(
        instr_client.Initialize(
            nirfmxinstr_types.InitializeRequest(
                session_name=SESSION_NAME, resource_name=RESOURCE, option_string=OPTIONS
            )
        )
    )
    instr = initialize_response.instrument
    raise_if_error(
        instr_client.CfgFrequencyReference(
            nirfmxinstr_types.CfgFrequencyReferenceRequest(
                instrument=instr,
                channel_name="",
                frequency_reference_source_mapped=nirfmxinstr_types.FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK,
                frequency_reference_frequency=10e6,
            )
        )
    )
    raise_if_error(
        client.CfgFrequency(
            nirfmxwlan_types.CfgFrequencyRequest(
                instrument=instr, selector_string="", center_frequency=2.412e9
            )
        )
    )
    raise_if_error(
        client.CfgReferenceLevel(
            nirfmxwlan_types.CfgReferenceLevelRequest(
                instrument=instr, selector_string="", reference_level=0.0
            )
        )
    )
    raise_if_error(
        client.CfgExternalAttenuation(
            nirfmxwlan_types.CfgExternalAttenuationRequest(
                instrument=instr, selector_string="", external_attenuation=0.0
            )
        )
    )
    raise_if_error(
        client.CfgIQPowerEdgeTrigger(
            nirfmxwlan_types.CfgIQPowerEdgeTriggerRequest(
                instrument=instr,
                selector_string="",
                iq_power_edge_source="0",
                iq_power_edge_slope=nirfmxwlan_types.IQ_POWER_EDGE_TRIGGER_SLOPE_RISING,
                iq_power_edge_level=-20.0,
                trigger_delay=0.0,
                trigger_min_quiet_time_mode=nirfmxwlan_types.TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO,
                trigger_min_quiet_time_duration=5e-6,
                iq_power_edge_level_type=nirfmxwlan_types.IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE,
                enable_trigger=True,
            )
        )
    )
    raise_if_error(
        client.CfgStandard(
            nirfmxwlan_types.CfgStandardRequest(
                instrument=instr, selector_string="", standard=nirfmxwlan_types.STANDARD_802_11_AG
            )
        )
    )
    raise_if_error(
        client.CfgChannelBandwidth(
            nirfmxwlan_types.CfgChannelBandwidthRequest(
                instrument=instr, selector_string="", channel_bandwidth=20e6
            )
        )
    )
    raise_if_error(
        client.SelectMeasurements(
            nirfmxwlan_types.SelectMeasurementsRequest(
                instrument=instr,
                selector_string="",
                measurements=nirfmxwlan_types.MEASUREMENT_TYPES_OFDMMODACC,
                enable_all_traces=True,
            )
        )
    )
    raise_if_error(
        client.OFDMModAccCfgMeasurementLength(
            nirfmxwlan_types.OFDMModAccCfgMeasurementLengthRequest(
                instrument=instr,
                selector_string="",
                measurement_offset=0,
                maximum_measurement_length=16,
            )
        )
    )
    raise_if_error(
        client.OFDMModAccCfgFrequencyErrorEstimationMethod(
            nirfmxwlan_types.OFDMModAccCfgFrequencyErrorEstimationMethodRequest(
                instrument=instr,
                selector_string="",
                frequency_error_estimation_method=nirfmxwlan_types.OFDMMODACC_FREQUENCY_ERROR_ESTIMATION_METHOD_PREAMBLE_AND_PILOTS,
            )
        )
    )
    raise_if_error(
        client.OFDMModAccCfgAmplitudeTrackingEnabled(
            nirfmxwlan_types.OFDMModAccCfgAmplitudeTrackingEnabledRequest(
                instrument=instr,
                selector_string="",
                amplitude_tracking_enabled=nirfmxwlan_types.OFDMMODACC_AMPLITUDE_TRACKING_ENABLED_FALSE,
            )
        )
    )
    raise_if_error(
        client.OFDMModAccCfgPhaseTrackingEnabled(
            nirfmxwlan_types.OFDMModAccCfgPhaseTrackingEnabledRequest(
                instrument=instr,
                selector_string="",
                phase_tracking_enabled=nirfmxwlan_types.OFDMMODACC_PHASE_TRACKING_ENABLED_TRUE,
            )
        )
    )
    raise_if_error(
        client.OFDMModAccCfgSymbolClockErrorCorrectionEnabled(
            nirfmxwlan_types.OFDMModAccCfgSymbolClockErrorCorrectionEnabledRequest(
                instrument=instr,
                selector_string="",
                symbol_clock_error_correction_enabled=nirfmxwlan_types.OFDMMODACC_SYMBOL_CLOCK_ERROR_CORRECTION_ENABLED_TRUE,
            )
        )
    )
    raise_if_error(
        client.OFDMModAccCfgChannelEstimationType(
            nirfmxwlan_types.OFDMModAccCfgChannelEstimationTypeRequest(
                instrument=instr,
                selector_string="",
                channel_estimation_type=nirfmxwlan_types.OFDMMODACC_CHANNEL_ESTIMATION_TYPE_REFERENCE,
            )
        )
    )
    raise_if_error(
        client.OFDMModAccCfgAveraging(
            nirfmxwlan_types.OFDMModAccCfgAveragingRequest(
                instrument=instr,
                selector_string="",
                averaging_enabled=nirfmxwlan_types.OFDMMODACC_AVERAGING_ENABLED_FALSE,
                averaging_count=10,
            )
        )
    )
    raise_if_error(
        client.Initiate(
            nirfmxwlan_types.InitiateRequest(instrument=instr, selector_string="", result_name="")
        )
    )

    ### Fetch Results ###

    ofdm_mod_acc_fetch_composite_rmsevm_response = raise_if_error(
        client.OFDMModAccFetchCompositeRMSEVM(
            nirfmxwlan_types.OFDMModAccFetchCompositeRMSEVMRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    composite_rmsevm_mean = ofdm_mod_acc_fetch_composite_rmsevm_response.composite_rms_evm_mean
    composite_data_rmsevm_mean = (
        ofdm_mod_acc_fetch_composite_rmsevm_response.composite_data_rms_evm_mean
    )
    composite_pilot_rmsevm_mean = (
        ofdm_mod_acc_fetch_composite_rmsevm_response.composite_pilot_rms_evm_mean
    )
    ofdm_mod_acc_fetch_numberof_symbols_used_response = raise_if_error(
        client.OFDMModAccFetchNumberofSymbolsUsed(
            nirfmxwlan_types.OFDMModAccFetchNumberofSymbolsUsedRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    number_of_symbols_used = (
        ofdm_mod_acc_fetch_numberof_symbols_used_response.number_of_symbols_used
    )
    ofdm_mod_acc_fetch_frequency_error_mean_response = raise_if_error(
        client.OFDMModAccFetchFrequencyErrorMean(
            nirfmxwlan_types.OFDMModAccFetchFrequencyErrorMeanRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    frequency_error_mean = ofdm_mod_acc_fetch_frequency_error_mean_response.frequency_error_mean
    ofdm_mod_acc_fetch_symbol_clock_error_mean_response = raise_if_error(
        client.OFDMModAccFetchSymbolClockErrorMean(
            nirfmxwlan_types.OFDMModAccFetchSymbolClockErrorMeanRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    symbol_clock_error_mean = (
        ofdm_mod_acc_fetch_symbol_clock_error_mean_response.symbol_clock_error_mean
    )
    ofdm_mod_acc_fetch_iq_impairments_response = raise_if_error(
        client.OFDMModAccFetchIQImpairments(
            nirfmxwlan_types.OFDMModAccFetchIQImpairmentsRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    relative_iq_origin_offset_mean = (
        ofdm_mod_acc_fetch_iq_impairments_response.relative_iq_origin_offset_mean
    )
    iq_gain_imbalance_mean = ofdm_mod_acc_fetch_iq_impairments_response.iq_gain_imbalance_mean
    iq_quadrature_error_mean = ofdm_mod_acc_fetch_iq_impairments_response.iq_quadrature_error_mean
    absolute_iq_origin_offset_mean = (
        ofdm_mod_acc_fetch_iq_impairments_response.absolute_iq_origin_offset_mean
    )
    iq_timing_skew_mean = ofdm_mod_acc_fetch_iq_impairments_response.iq_timing_skew_mean
    ofdm_mod_acc_fetch_ppdu_type_response = raise_if_error(
        client.OFDMModAccFetchPPDUType(
            nirfmxwlan_types.OFDMModAccFetchPPDUTypeRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    ppdu_type = ofdm_mod_acc_fetch_ppdu_type_response.ppdu_type
    ofdm_mod_acc_fetch_mcs_index_response = raise_if_error(
        client.OFDMModAccFetchMCSIndex(
            nirfmxwlan_types.OFDMModAccFetchMCSIndexRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    mcs_index = ofdm_mod_acc_fetch_mcs_index_response.mcs_index
    ofdm_mod_acc_fetch_guard_interval_type_response = raise_if_error(
        client.OFDMModAccFetchGuardIntervalType(
            nirfmxwlan_types.OFDMModAccFetchGuardIntervalTypeRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    guard_interval_type = ofdm_mod_acc_fetch_guard_interval_type_response.guard_interval_type
    ofdm_mod_acc_fetch_l_sig_parity_check_status_response = raise_if_error(
        client.OFDMModAccFetchLSIGParityCheckStatus(
            nirfmxwlan_types.OFDMModAccFetchLSIGParityCheckStatusRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    l_sig_parity_check_status = (
        ofdm_mod_acc_fetch_l_sig_parity_check_status_response.l_sig_parity_check_status
    )
    ofdm_mod_acc_fetch_sigcrc_status_response = raise_if_error(
        client.OFDMModAccFetchSIGCRCStatus(
            nirfmxwlan_types.OFDMModAccFetchSIGCRCStatusRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    sig_crc_status = ofdm_mod_acc_fetch_sigcrc_status_response.sig_crc_status
    ofdm_mod_acc_fetch_sigbcrc_status_response = raise_if_error(
        client.OFDMModAccFetchSIGBCRCStatus(
            nirfmxwlan_types.OFDMModAccFetchSIGBCRCStatusRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    sig_b_crc_status = ofdm_mod_acc_fetch_sigbcrc_status_response.sig_b_crc_status

    ofdm_mod_acc_fetch_pilot_constellation_trace_response = raise_if_error(
        client.OFDMModAccFetchPilotConstellationTrace(
            nirfmxwlan_types.OFDMModAccFetchPilotConstellationTraceRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    pilot_constellation = ofdm_mod_acc_fetch_pilot_constellation_trace_response.pilot_constellation

    ofdm_mod_acc_fetch_data_constellation_trace_response = raise_if_error(
        client.OFDMModAccFetchDataConstellationTrace(
            nirfmxwlan_types.OFDMModAccFetchDataConstellationTraceRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    data_constellation = ofdm_mod_acc_fetch_data_constellation_trace_response.data_constellation

    ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace_response = raise_if_error(
        client.OFDMModAccFetchChainRMSEVMPerSubcarrierMeanTrace(
            nirfmxwlan_types.OFDMModAccFetchChainRMSEVMPerSubcarrierMeanTraceRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    x0 = ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace_response.x0
    dx = ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace_response.dx
    chain_rmsevm_per_subcarrier_mean = (
        ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace_response.chain_rms_evm_per_subcarrier_mean
    )

    print("------------------EVM------------------\n")
    print("------------------Composite EVM------------------")
    print(f"RMS EVM Mean (dB)                       : {composite_rmsevm_mean}")
    print(f"Data RMS EVM Mean (dB)                  : {composite_data_rmsevm_mean}")
    print(f"Pilot RMS EVM Mean (dB)                 : {composite_pilot_rmsevm_mean}\n")
    print(f"Number of Symbols Used                  : {number_of_symbols_used}\n")
    print("------------------Impairments & PPDU Info------------------\n")
    print(f"Frequency Error Mean (Hz)               : {frequency_error_mean}")
    print(f"Symbol Clock Error Mean (ppm)           : {symbol_clock_error_mean}\n")
    print("------------------IQ Impairments------------------")
    print(f"Relative I/Q Origin Offset Mean (dB)    : {relative_iq_origin_offset_mean}")
    print(f"Absolute I/Q Origin Offset Mean (dBm)   : {absolute_iq_origin_offset_mean}")
    print(f"I/Q Gain Imbalance Mean (dB)            : {iq_gain_imbalance_mean}")
    print(f"I/Q Quadrature Error Mean (deg)         : {iq_quadrature_error_mean}")
    print(f"I/Q Timing Skew Mean (s)                : {iq_timing_skew_mean}")
    print("\n------------------PPDU Info------------------")
    if ppdu_type == nirfmxwlan_types.OFDM_PPDU_TYPE_NON_HT:
        print("PPDU Type                               : Non-HT")
    elif ppdu_type == nirfmxwlan_types.OFDM_PPDU_TYPE_MIXED:
        print("PPDU Type                               : Mixed")
    elif ppdu_type == nirfmxwlan_types.OFDM_PPDU_TYPE_GREENFIELD:
        print("PPDU Type                               : GreenField")
    elif ppdu_type == nirfmxwlan_types.OFDM_PPDU_TYPE_SU:
        print("PPDU Type                               : SU")
    elif ppdu_type == nirfmxwlan_types.OFDM_PPDU_TYPE_MU:
        print("PPDU Type                               : MU")
    elif ppdu_type == nirfmxwlan_types.OFDM_PPDU_TYPE_EXTENDED_RANGE_SU:
        print("PPDU Type                               : Extended Range SU")
    elif ppdu_type == nirfmxwlan_types.OFDM_PPDU_TYPE_TRIGGER_BASED:
        print("PPDU Type                               : Trigger-Based")
    print(f"MCS Index                               : {mcs_index}")
    if guard_interval_type == nirfmxwlan_types.OFDM_GUARD_INTERVAL_TYPE_1_4:
        print("Guard Interval Type                     : 1/4")
    elif guard_interval_type == nirfmxwlan_types.OFDM_GUARD_INTERVAL_TYPE_1_8:
        print("Guard Interval Type                     : 1/8")
    elif guard_interval_type == nirfmxwlan_types.OFDM_GUARD_INTERVAL_TYPE_1_16:
        print("Guard Interval Type                     : 1/16")
    if (
        l_sig_parity_check_status
        == nirfmxwlan_types.OFDMMODACC_L_SIG_PARITY_CHECK_STATUS_NOT_APPLICABLE
    ):
        print("L-SIG Parity Check Status               : Not Applicable")
    elif l_sig_parity_check_status == nirfmxwlan_types.OFDMMODACC_L_SIG_PARITY_CHECK_STATUS_FAIL:
        print("L-SIG Parity Check Status               : Fail")
    elif l_sig_parity_check_status == nirfmxwlan_types.OFDMMODACC_L_SIG_PARITY_CHECK_STATUS_PASS:
        print("L-SIG Parity Check Status               : Pass")
    if sig_crc_status == nirfmxwlan_types.OFDMMODACC_SIG_CRC_STATUS_NOT_APPLICABLE:
        print("SIG CRC Status                          : Not Applicable")
    elif sig_crc_status == nirfmxwlan_types.OFDMMODACC_SIG_CRC_STATUS_FAIL:
        print("SIG CRC Status                          : Fail")
    elif sig_crc_status == nirfmxwlan_types.OFDMMODACC_SIG_CRC_STATUS_PASS:
        print("SIG CRC Status                          : Pass")
    if sig_b_crc_status == nirfmxwlan_types.OFDMMODACC_SIG_B_CRC_STATUS_NOT_APPLICABLE:
        print("SIG-B CRC Status                        : Not Applicable")
    elif sig_b_crc_status == nirfmxwlan_types.OFDMMODACC_SIG_B_CRC_STATUS_FAIL:
        print("SIG-B CRC Status                        : Fail")
    elif sig_b_crc_status == nirfmxwlan_types.OFDMMODACC_SIG_B_CRC_STATUS_PASS:
        print("SIG-B CRC Status                        : Pass")
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE:
        error_message = f"Failed to connect to server on {SERVER_ADDRESS}:{SERVER_PORT}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = (
            "The operation is not implemented or is not supported/enabled in this service"
        )
    sys.stderr.write(f"{error_message}\n")
finally:
    if instr:
        client.Close(nirfmxwlan_types.CloseRequest(instrument=instr, force_destroy=False))
