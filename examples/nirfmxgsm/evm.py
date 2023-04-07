r"""EVM example.

Steps:
1. Open a new RFmx Session.
2. Configure Frequency Reference.
3. Configure basic signal properties (Center Frequency, Reference Level and External Attenuation).
4. Configure Trigger Parameters for IQ Power Edge Trigger.
5. Configure Number of Timeslots.
6. Configure Auto tsc Detection Enabled.
7. Configure Signal Type.
8. Configure tsc.
9. Select ModAcc measurement and enable Traces.
10. Configure Averaging Parameters for ModAcc measurement.
11. Initiate the Measurement.
12. Fetch ModAcc Measurements and Traces.
13. Close RFmx Session.

The gRPC API is built from the C API. RFmx GSM documentation is installed with the driver at:
C:\Program Files (x86)\National Instruments\RFmx\GSM\Documentation\rfmxgsmcvi.chm

Getting Started:

To run this example, install "RFmx GSM" on the server machine.
Link: https://www.ni.com/en-us/support/downloads/software-products/download.rfmx-gsm-edge-.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page.
Link: https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-RFmx GSM gRPC Wiki for the latest C Function Reference:
Link: https://github.com/ni/grpc-device/wiki/NI-RFmx-GSM-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and physical channel name can be passed as separate
command line arguments.
  > python evm.py <server_address> <port_number> <physical_channel_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedDevice" as the resource name
"""

import sys

import grpc
import nirfmxgsm_pb2 as nirfmxgsm_types
import nirfmxgsm_pb2_grpc as grpc_nirfmxgsm

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "RFmxGSMSession"

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
client = grpc_nirfmxgsm.NiRFmxGSMStub(channel)
instr = None

NUMBER_OF_TIMESLOTS = 1


def check_for_warning(response, instrument):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        warning_message = client.GetErrorString(
            nirfmxgsm_types.GetErrorStringRequest(
                instrument=instrument,
                error_code=response.status,
            )
        )
        sys.stderr.write(
            f"{warning_message.error_description}\nWarning status: {response.status}\n"
        )


try:
    evm = None
    constellation_trace = None
    actual_array_size = 0

    initialize_response = client.Initialize(
        nirfmxgsm_types.InitializeRequest(
            session_name=SESSION_NAME, resource_name=RESOURCE, option_string=OPTIONS
        )
    )
    instr = initialize_response.instrument
    client.CfgFrequencyReference(
        nirfmxgsm_types.CfgFrequencyReferenceRequest(
            instrument=instr,
            channel_name="",
            frequency_reference_source_mapped=nirfmxgsm_types.FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK,
            frequency_reference_frequency=10e6,
        )
    )
    client.CfgRF(
        nirfmxgsm_types.CfgRFRequest(
            instrument=instr,
            selector_string="",
            center_frequency=890.2e6,
            reference_level=0.0,
            external_attenuation=0.0,
        )
    )
    client.CfgIQPowerEdgeTrigger(
        nirfmxgsm_types.CfgIQPowerEdgeTriggerRequest(
            instrument=instr,
            selector_string="",
            iq_power_edge_source="0",
            iq_power_edge_slope=nirfmxgsm_types.IQ_POWER_EDGE_TRIGGER_SLOPE_RISING,
            iq_power_edge_level=-20.00,
            trigger_delay=0.0,
            minimum_quiet_time_mode=nirfmxgsm_types.TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO,
            minimum_quiet_time=582e-6,
            iq_power_edge_level_type=nirfmxgsm_types.IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE,
            enable_trigger=True,
        )
    )
    client.CfgNumberOfTimeslots(
        nirfmxgsm_types.CfgNumberOfTimeslotsRequest(
            instrument=instr, selector_string="", number_of_timeslots=NUMBER_OF_TIMESLOTS
        )
    )
    client.CfgAutoTSCDetectionEnabled(
        nirfmxgsm_types.CfgAutoTSCDetectionEnabledRequest(
            instrument=instr,
            selector_string="",
            auto_tsc_detection_enabled=nirfmxgsm_types.AUTO_TSC_DETECTION_ENABLED_TRUE,
        )
    )
    client.CfgSignalType(
        nirfmxgsm_types.CfgSignalTypeRequest(
            instrument=instr,
            selector_string="slot::all",
            modulation_type=nirfmxgsm_types.MODULATION_TYPE_8PSK,
            burst_type=nirfmxgsm_types.BURST_TYPE_NB,
            hb_filter_width=nirfmxgsm_types.HB_FILTER_WIDTH_NARROW,
        )
    )
    client.CfgTSC(
        nirfmxgsm_types.CfgTSCRequest(
            instrument=instr, selector_string="slot::all", tsc=nirfmxgsm_types.TSC_TSC0
        )
    )
    client.SelectMeasurements(
        nirfmxgsm_types.SelectMeasurementsRequest(
            instrument=instr,
            selector_string="",
            measurements_raw=nirfmxgsm_types.MEASUREMENT_TYPES_MODACC,
            enable_all_traces=True,
        )
    )
    client.ModAccCfgAveraging(
        nirfmxgsm_types.ModAccCfgAveragingRequest(
            instrument=instr,
            selector_string="",
            averaging_enabled=nirfmxgsm_types.MODACC_AVERAGING_ENABLED_FALSE,
            averaging_count=10,
        )
    )

    initiate_response = client.Initiate(
        nirfmxgsm_types.InitiateRequest(instrument=instr, selector_string="", result_name="")
    )
    check_for_warning(initiate_response, instr)

    mod_acc_fetch_evm_response = client.ModAccFetchEVM(
        nirfmxgsm_types.ModAccFetchEVMRequest(instrument=instr, selector_string="", timeout=10.0)
    )
    check_for_warning(mod_acc_fetch_evm_response, instr)
    mean_rmsevm = mod_acc_fetch_evm_response.mean_rms_evm
    maximum_rmsevm = mod_acc_fetch_evm_response.maximum_rms_evm
    mean_peak_evm = mod_acc_fetch_evm_response.mean_peak_evm
    maximum_peak_evm = mod_acc_fetch_evm_response.maximum_peak_evm
    ninety_fifth_percentile_evm = mod_acc_fetch_evm_response.ninety_fifth_percentile_evm
    mean_frequency_error = mod_acc_fetch_evm_response.mean_frequency_error
    peak_evm_symbol = mod_acc_fetch_evm_response.peak_evm_symbol

    mod_acc_fetch_iq_impairments_response = client.ModAccFetchIQImpairments(
        nirfmxgsm_types.ModAccFetchIQImpairmentsRequest(
            instrument=instr, selector_string="", timeout=10.0
        )
    )
    check_for_warning(mod_acc_fetch_iq_impairments_response, instr)
    mean_iq_gain_imbalance = mod_acc_fetch_iq_impairments_response.mean_iq_gain_imbalance
    maximum_iq_gain_imbalance = mod_acc_fetch_iq_impairments_response.maximum_iq_gain_imbalance
    mean_iq_origin_offset = mod_acc_fetch_iq_impairments_response.mean_iq_origin_offset
    maximum_iq_origin_offset = mod_acc_fetch_iq_impairments_response.maximum_iq_origin_offset

    mod_acc_fetch_detected_tsc_array_response = client.ModAccFetchDetectedTSCArray(
        nirfmxgsm_types.ModAccFetchDetectedTSCArrayRequest(
            instrument=instr, selector_string="", timeout=10.0
        )
    )
    check_for_warning(mod_acc_fetch_detected_tsc_array_response, instr)
    detected_tsc = mod_acc_fetch_detected_tsc_array_response.detected_tsc

    mod_acc_fetch_evm_trace_response = client.ModAccFetchEVMTrace(
        nirfmxgsm_types.ModAccFetchEVMTraceRequest(
            instrument=instr, selector_string="", timeout=10.0
        )
    )
    check_for_warning(mod_acc_fetch_evm_trace_response, instr)
    x0 = mod_acc_fetch_evm_trace_response.x0
    dx = mod_acc_fetch_evm_trace_response.dx
    evm = mod_acc_fetch_evm_trace_response.evm

    mod_acc_fetch_constellation_trace_response = client.ModAccFetchConstellationTrace(
        nirfmxgsm_types.ModAccFetchConstellationTraceRequest(
            instrument=instr, selector_string="", timeout=10.0
        )
    )
    check_for_warning(mod_acc_fetch_constellation_trace_response, instr)
    constellation_trace = mod_acc_fetch_constellation_trace_response.constellation_trace

    print("-----------------Measurement-----------------")
    print(f"Mean RMS evm (%%)                : {mean_rmsevm}")
    print(f"Maximum RMS evm (%%)             : {maximum_rmsevm}")
    print(f"Mean Peak evm (%%)               : {mean_peak_evm}")
    print(f"Maximum Peak evm (%%)            : {maximum_peak_evm}")
    print(f"95th Percentile evm (%%)         : {ninety_fifth_percentile_evm}")
    print(f"Mean Frequency Error (Hz)       : {mean_frequency_error}")
    print(f"Peak evm Symbol                 : {peak_evm_symbol}")

    print("\n----------------IQ Impairments-----------------")
    print(f"Mean IQ Origin Offset (dB)      : {mean_iq_origin_offset}")
    print(f"Maximum IQ Origin Offset (dB)   : {maximum_iq_origin_offset}")
    print(f"Mean IQ Gain Imbalance (dB)     : {mean_iq_gain_imbalance}")
    print(f"Maximum IQ Gain Imbalance (dB)  : {maximum_iq_gain_imbalance}")

    print("\n----------------Detected tsc-------------------")
    for i in range(NUMBER_OF_TIMESLOTS):
        if detected_tsc[i] < 0:
            print(f"Slot {i}                             : Unknown")
        else:
            print(f"Slot {i}                          : tsc{detected_tsc[i]}")
except grpc.RpcError as rpc_error:
    error_message = str(rpc_error.details() or "")
    for entry in rpc_error.trailing_metadata() or []:
        if entry.key == "ni-error":
            value = entry.value if isinstance(entry.value, str) else entry.value.decode("utf-8")
            error_message += f"\nError status: {value}"
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE:
        error_message = f"Failed to connect to server on {SERVER_ADDRESS}:{SERVER_PORT}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = (
            "The operation is not implemented or is not supported/enabled in this service"
        )
    sys.stderr.write(f"{error_message}\n")
finally:
    if instr:
        client.Close(nirfmxgsm_types.CloseRequest(instrument=instr, force_destroy=False))
