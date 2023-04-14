r"""ModAcc example.

Steps:
1. Open a new RFmx session.
2. Configure Frequency Reference.
3. Configure basic signal properties (Center Frequency, Reference Level and External Attenuation).
4. Configure Trigger Type and Trigger Parameters..
5. Select ModAcc measurement and enable traces.
6. Configure Uplink Scrambling Code.
7. Configure Synchronization Mode and Measurement Interval.
8. Configure Midamble Parameters.
9. Initiate the Measurement.
10. Fetch ModAcc Measurements and Traces.
11. Close the RFmx session.

The gRPC API is built from the C API. RFmx TDSCDMA documentation is installed with the driver at:
C:\Program Files (x86)\National Instruments\RFmx\TDSCDMA\Documentation\tdscdmacvi.chm

Getting Started:

To run this example, install "RFmx TDSCDMA" on the server machine.
Link: https://www.ni.com/en-us/support/downloads/software-products/download.rfmx-tdscdma.html

For instructions on how to use protoc to generate gRPC client interfaces, see our
"Creating a gRPC Client" wiki page.
Link: https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-RFmxTDSCDMA gRPC Wiki for the latest C Function Reference:
Link: https://github.com/ni/grpc-device/wiki/NI-RFmxTDSCDMA-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and physical channel name can be passed as separate
command line arguments.
  > python modacc.py <server_address> <port_number> <physical_channel_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedDevice" as the resource name
"""


import sys

import grpc
import nirfmxtdscdma_pb2 as nirfmxtdscdma_types
import nirfmxtdscdma_pb2_grpc as grpc_nirfmxtdscdma

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "RFmxTDSCDMASession"

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
client = grpc_nirfmxtdscdma.NiRFmxTDSCDMAStub(channel)
instr = None


def check_for_warning(response, instrument):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        warning_message = client.GetErrorString(
            nirfmxtdscdma_types.GetErrorStringRequest(
                instrument=instrument,
                error_code=response.status,
            )
        )
        sys.stderr.write(
            f"{warning_message.error_description}\nWarning status: {response.status}\n"
        )


try:
    # Initialize a session
    initialize_response = client.Initialize(
        nirfmxtdscdma_types.InitializeRequest(
            session_name=SESSION_NAME, resource_name=RESOURCE, option_string=OPTIONS
        )
    )
    instr = initialize_response.instrument
    client.CfgFrequencyReference(
        nirfmxtdscdma_types.CfgFrequencyReferenceRequest(
            instrument=instr,
            channel_name="",
            frequency_reference_source_mapped=nirfmxtdscdma_types.FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK,
            frequency_reference_frequency=10e6,
        )
    )
    client.CfgRF(
        nirfmxtdscdma_types.CfgRFRequest(
            instrument=instr,
            selector_string="",
            center_frequency=1.91e9,
            reference_level=0.00,
            external_attenuation=0.00,
        )
    )
    client.CfgIQPowerEdgeTrigger(
        nirfmxtdscdma_types.CfgIQPowerEdgeTriggerRequest(
            instrument=instr,
            selector_string="",
            iq_power_edge_source="0",
            iq_power_edge_slope=nirfmxtdscdma_types.IQ_POWER_EDGE_TRIGGER_SLOPE_RISING,
            iq_power_edge_level=-20.00,
            trigger_delay=0.00,
            minimum_quiet_time_mode=nirfmxtdscdma_types.TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO,
            minimum_quiet_time=80e-6,
            iq_power_edge_level_type=nirfmxtdscdma_types.IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE,
            enable_trigger=True,
        )
    )
    client.SelectMeasurements(
        nirfmxtdscdma_types.SelectMeasurementsRequest(
            instrument=instr,
            selector_string="",
            measurements_raw=nirfmxtdscdma_types.MEASUREMENT_TYPES_MODACC,
            enable_all_traces=True,
        )
    )
    client.ModAccCfgAveraging(
        nirfmxtdscdma_types.ModAccCfgAveragingRequest(
            instrument=instr,
            selector_string="",
            averaging_enabled=nirfmxtdscdma_types.MODACC_AVERAGING_ENABLED_FALSE,
            averaging_count=10,
        )
    )
    client.CfgUplinkScramblingCode(
        nirfmxtdscdma_types.CfgUplinkScramblingCodeRequest(
            instrument=instr, selector_string="", uplink_scrambling_code=0
        )
    )
    client.ModAccCfgSynchronizationModeAndInterval(
        nirfmxtdscdma_types.ModAccCfgSynchronizationModeAndIntervalRequest(
            instrument=instr,
            selector_string="",
            synchronization_mode=nirfmxtdscdma_types.MODACC_SYNCHRONIZATION_MODE_SLOT,
            measurement_offset=0,
            measurement_length=1,
        )
    )
    client.CfgMidambleShift(
        nirfmxtdscdma_types.CfgMidambleShiftRequest(
            instrument=instr,
            selector_string="",
            midamble_auto_detection_mode=nirfmxtdscdma_types.MIDAMBLE_AUTO_DETECTION_MODE_MIDAMBLE_SHIFT,
            maximum_number_of_users=16,
            midamble_shift=8,
        )
    )

    initiate_response = client.Initiate(
        nirfmxtdscdma_types.InitiateRequest(instrument=instr, selector_string="", result_name="")
    )
    check_for_warning(initiate_response, instr)

    mod_acc_fetch_composite_evm_response = client.ModAccFetchCompositeEVM(
        nirfmxtdscdma_types.ModAccFetchCompositeEVMRequest(
            instrument=instr, selector_string="", timeout=10.00
        )
    )
    check_for_warning(mod_acc_fetch_composite_evm_response, instr)
    rms_composite_evm = mod_acc_fetch_composite_evm_response.rms_composite_evm
    peak_composite_evm = mod_acc_fetch_composite_evm_response.peak_composite_evm
    composite_rho = mod_acc_fetch_composite_evm_response.composite_rho
    frequency_error = mod_acc_fetch_composite_evm_response.frequency_error
    chip_rate_error = mod_acc_fetch_composite_evm_response.chip_rate_error
    rms_composite_magnitude_error = (
        mod_acc_fetch_composite_evm_response.rms_composite_magnitude_error
    )
    rms_composite_phase_error = mod_acc_fetch_composite_evm_response.rms_composite_phase_error

    mod_acc_fetch_data_evm_response = client.ModAccFetchDataEVM(
        nirfmxtdscdma_types.ModAccFetchDataEVMRequest(
            instrument=instr, selector_string="", timeout=10.00
        )
    )
    check_for_warning(mod_acc_fetch_data_evm_response, instr)
    rms_data_evm = mod_acc_fetch_data_evm_response.rms_data_evm
    peak_data_evm = mod_acc_fetch_data_evm_response.peak_data_evm
    data_rho = mod_acc_fetch_data_evm_response.data_rho
    rms_data_magnitude_error = mod_acc_fetch_data_evm_response.rms_data_magnitude_error
    rms_data_phase_error = mod_acc_fetch_data_evm_response.rms_data_phase_error

    mod_acc_fetch_iq_impairments_response = client.ModAccFetchIQImpairments(
        nirfmxtdscdma_types.ModAccFetchIQImpairmentsRequest(
            instrument=instr, selector_string="", timeout=10.00
        )
    )
    check_for_warning(mod_acc_fetch_iq_impairments_response, instr)
    iq_origin_offset = mod_acc_fetch_iq_impairments_response.iq_origin_offset
    iq_gain_imbalance = mod_acc_fetch_iq_impairments_response.iq_gain_imbalance
    iq_quadrature_error = mod_acc_fetch_iq_impairments_response.iq_quadrature_error

    mod_acc_fetch_constellation_trace_response = client.ModAccFetchConstellationTrace(
        nirfmxtdscdma_types.ModAccFetchConstellationTraceRequest(
            instrument=instr, selector_string="", timeout=10.00
        )
    )
    check_for_warning(mod_acc_fetch_constellation_trace_response, instr)
    constellation = mod_acc_fetch_constellation_trace_response.constellation

    mod_acc_fetch_midamble_evm_response = client.ModAccFetchMidambleEVM(
        nirfmxtdscdma_types.ModAccFetchMidambleEVMRequest(
            instrument=instr, selector_string="", timeout=10.00
        )
    )
    check_for_warning(mod_acc_fetch_midamble_evm_response, instr)
    rms_midamble_evm = mod_acc_fetch_midamble_evm_response.rms_midamble_evm
    peak_midamble_evm = mod_acc_fetch_midamble_evm_response.peak_midamble_evm
    midamble_rho = mod_acc_fetch_midamble_evm_response.midamble_rho
    rms_midamble_magnitude_error = mod_acc_fetch_midamble_evm_response.rms_midamble_magnitude_error
    rms_midamble_phase_error = mod_acc_fetch_midamble_evm_response.rms_midamble_phase_error

    mod_acc_fetch_midamble_and_data_power_response = client.ModAccFetchMidambleAndDataPower(
        nirfmxtdscdma_types.ModAccFetchMidambleAndDataPowerRequest(
            instrument=instr, selector_string="", timeout=10.00
        )
    )
    check_for_warning(mod_acc_fetch_midamble_and_data_power_response, instr)
    midamble_power = mod_acc_fetch_midamble_and_data_power_response.midamble_power
    data_field1_power = mod_acc_fetch_midamble_and_data_power_response.data_field1_power
    data_field2_power = mod_acc_fetch_midamble_and_data_power_response.data_field2_power

    mod_acc_fetch_evm_trace_response = client.ModAccFetchEVMTrace(
        nirfmxtdscdma_types.ModAccFetchEVMTraceRequest(
            instrument=instr, selector_string="", timeout=10.00
        )
    )
    check_for_warning(mod_acc_fetch_evm_trace_response, instr)
    x0 = mod_acc_fetch_evm_trace_response.x0
    dx = mod_acc_fetch_evm_trace_response.dx
    evm = mod_acc_fetch_evm_trace_response.evm

    print("Composite evm Results")
    print(f"RMS Composite evm  (%%)             : {rms_composite_evm}")
    print(f"Peak Composite evm  (%%)            : {peak_composite_evm}")
    print(f"Composite Rho                       : {composite_rho}")
    print(f"Frequency Error  (Hz)               : {frequency_error}")
    print(f"Chip Rate Error  (ppm)              : {chip_rate_error}")
    print(f"RMS Composite Phase Error  (deg)    : {rms_composite_phase_error}")
    print(f"RMS Composite Magnitude Error  (%%) : {rms_composite_magnitude_error}")

    print("\nData evm Results")
    print(f"RMS Data evm  (%%)                  : {rms_data_evm}")
    print(f"Peak Data evm  (%%)                 : {peak_data_evm}")
    print(f"Data Rho                            : {data_rho}")
    print(f"RMS Data Phase Error  (deg)         : {rms_data_phase_error}")
    print(f"RMS Data Magnitude Error  (%%)      : {rms_data_magnitude_error}")
    print(f"Data Field1 Power  (dBm)            : {data_field1_power}")
    print(f"Data Field2 Power  (dBm)            : {data_field2_power}")

    print("\nIQ Impairments")
    print(f"I/Q Origin Offset (dB)              : {iq_origin_offset}")
    print(f"I/Q Gain Imbalance (dB)             : {iq_gain_imbalance}")
    print(f"I/Q Quadrature Error (deg)          : {iq_quadrature_error}")

    print("\nMidamble evm")
    print(f"RMS Midamble evm  (%%)              : {rms_midamble_evm}")
    print(f"Peak Midamble evm  (%%)             : {peak_midamble_evm}")
    print(f"Midamble Rho                        : {midamble_rho}")
    print(f"RMS Midamble Phase Error  (deg)     : {rms_midamble_phase_error}")
    print(f"RMS Midamble Magnitude Error  (%%)  : {rms_midamble_magnitude_error}")
    print(f"Midamble Power  (dBm)               : {midamble_power}")
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
        client.Close(nirfmxtdscdma_types.CloseRequest(instrument=instr, force_destroy=False))
