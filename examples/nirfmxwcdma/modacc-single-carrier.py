r"""Fetch ModAcc data.

Steps:
1. Open a new RFmx Session.
2. Configure Frequency Reference.
3. Configure basic signal properties (Center Frequency, Reference Level and External Attenuation).
4. Configure Trigger Type and Trigger Parameters.
5. Configure Uplink Scrambling.
6. Select ModAcc measurement and enable Traces.
7. Configure Synchronization Mode and Measurement Interval.
8. Initiate the Measurement.
9. Fetch ModAcc Measurements and Traces.
10. Close RFmx Session.


The gRPC API is built from the C API. RFmx WCDMA documentation is installed with the driver at:
C:\Program Files (x86)\National Instruments\RFmx\WCDMA\Documentation\wcdmacvi.chm

Getting Started:

To run this example, install "RFmx WCDMA" on the server machine.
Link: https://www.ni.com/en-us/support/downloads/software-products/download.rfmx-wcdma.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a
gRPC Client" wiki page.
Link: https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-RFmxWCDMA gRPC Wiki for the latest C Function Reference:
Link: https://github.com/ni/grpc-device/wiki/NI-RFmxWCDMA-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and physical channel name can be passed as separate
command line arguments.
  > python RFmxWcdmaModAccSingleCarrier.c <server_address> <port_number> <physical_channel_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedDevice" as the resource name
"""

import sys

import grpc
import nirfmxwcdma_pb2 as nirfmxwcdma_types
import nirfmxwcdma_pb2_grpc as grpc_nirfmxwcdma

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "RFmxWCDMASession"

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
client = grpc_nirfmxwcdma.NiRFmxWCDMAStub(channel)
instr = None


def check_for_warning(response, instrument):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        warning_message = client.GetErrorString(
            nirfmxwcdma_types.GetErrorStringRequest(
                instrument=instrument,
                error_code=response.status,
            )
        )
        sys.stderr.write(
            f"{warning_message.error_description}\nWarning status: {response.status}\n"
        )


try:
    actual_array_size = 0

    evm = None  # (%)
    constellation = None

    # Initialize a session
    initialize_response = client.Initialize(
        nirfmxwcdma_types.InitializeRequest(
            session_name=SESSION_NAME,
            resource_name=RESOURCE,
            option_string=OPTIONS,
        )
    )
    instr = initialize_response.instrument
    check_for_warning(initialize_response, instr)

    client.CfgFrequencyReference(
        nirfmxwcdma_types.CfgFrequencyReferenceRequest(
            instrument=instr,
            channel_name="",
            frequency_reference_source_mapped=nirfmxwcdma_types.FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK,
            frequency_reference_frequency=10e6,
        )
    )

    client.CfgRF(
        nirfmxwcdma_types.CfgRFRequest(
            instrument=instr,
            selector_string="",
            center_frequency=1.95e9,
            reference_level=0.000000,
            external_attenuation=0.000000,
        )
    )

    client.CfgDigitalEdgeTrigger(
        nirfmxwcdma_types.CfgDigitalEdgeTriggerRequest(
            instrument=instr,
            selector_string="",
            digital_edge_source_mapped=nirfmxwcdma_types.DIGITAL_EDGE_TRIGGER_SOURCE_PFI0,
            digital_edge=nirfmxwcdma_types.DIGITAL_EDGE_TRIGGER_EDGE_RISING,
            trigger_delay=0.000000,
            enable_trigger=False,
        )
    )

    client.CfgUplinkScrambling(
        nirfmxwcdma_types.CfgUplinkScramblingRequest(
            instrument=instr,
            selector_string="",
            uplink_scrambling_code=0x0,
            uplink_scrambling_type=nirfmxwcdma_types.UPLINK_SCRAMBLING_TYPE_LONG,
        )
    )

    client.SelectMeasurements(
        nirfmxwcdma_types.SelectMeasurementsRequest(
            instrument=instr,
            selector_string="",
            measurements_array=[nirfmxwcdma_types.MEASUREMENT_TYPES_MODACC],
            enable_all_traces=True,
        )
    )

    client.ModAccCfgSynchronizationModeAndInterval(
        nirfmxwcdma_types.ModAccCfgSynchronizationModeAndIntervalRequest(
            instrument=instr,
            selector_string="",
            synchronization_mode=nirfmxwcdma_types.MODACC_SYNCHRONIZATION_MODE_SLOT,
            measurement_offset=0,
            measurement_length=1,
        )
    )

    client.Initiate(
        nirfmxwcdma_types.InitiateRequest(
            instrument=instr,
            selector_string="",
            result_name="",
        )
    )

    mod_acc_fetch_evm_response = client.ModAccFetchEVM(
        nirfmxwcdma_types.ModAccFetchEVMRequest(
            instrument=instr,
            selector_string="",
            timeout=10.000000,
        )
    )
    check_for_warning(mod_acc_fetch_evm_response, instr)

    rms_evm = mod_acc_fetch_evm_response.rms_evm
    peak_evm = mod_acc_fetch_evm_response.peak_evm
    rho = mod_acc_fetch_evm_response.rho
    frequency_error = mod_acc_fetch_evm_response.frequency_error
    chip_rate_error = mod_acc_fetch_evm_response.chip_rate_error
    rms_magnitude_error = mod_acc_fetch_evm_response.rms_magnitude_error
    rms_phase_error = mod_acc_fetch_evm_response.rms_phase_error

    mod_acc_fetch_iq_impairments_response = client.ModAccFetchIQImpairments(
        nirfmxwcdma_types.ModAccFetchIQImpairmentsRequest(
            instrument=instr,
            selector_string="",
            timeout=10.000000,
        )
    )
    check_for_warning(mod_acc_fetch_iq_impairments_response, instr)

    iq_origin_offset = mod_acc_fetch_iq_impairments_response.iq_origin_offset
    iq_gain_imbalance = mod_acc_fetch_iq_impairments_response.iq_gain_imbalance
    iq_quadrature_error = mod_acc_fetch_iq_impairments_response.iq_quadrature_error

    mod_acc_fetch_peak_cde_response = client.ModAccFetchPeakCDE(
        nirfmxwcdma_types.ModAccFetchPeakCDERequest(
            instrument=instr,
            selector_string="",
            timeout=10.000000,
        )
    )
    check_for_warning(mod_acc_fetch_peak_cde_response, instr)

    peak_cde = mod_acc_fetch_peak_cde_response.peak_cde
    peak_cde_code = mod_acc_fetch_peak_cde_response.peak_cde_code
    peak_cde_branch = mod_acc_fetch_peak_cde_response.peak_cde_branch

    mod_acc_fetch_peak_active_cde_response = client.ModAccFetchPeakActiveCDE(
        nirfmxwcdma_types.ModAccFetchPeakActiveCDERequest(
            instrument=instr,
            selector_string="",
            timeout=10.000000,
        )
    )
    check_for_warning(mod_acc_fetch_peak_active_cde_response, instr)

    peak_active_cde = mod_acc_fetch_peak_active_cde_response.peak_active_cde
    peak_active_cde_spreading_factor = (
        mod_acc_fetch_peak_active_cde_response.peak_active_cde_spreading_factor
    )
    peak_active_cde_code = mod_acc_fetch_peak_active_cde_response.peak_active_cde_code
    peak_active_cde_branch = mod_acc_fetch_peak_active_cde_response.peak_active_cde_branch

    mod_acc_fetch_rcde_response = client.ModAccFetchRCDE(
        nirfmxwcdma_types.ModAccFetchRCDERequest(
            instrument=instr,
            selector_string="",
            timeout=10.000000,
        )
    )
    check_for_warning(mod_acc_fetch_rcde_response, instr)

    peak_rcde = mod_acc_fetch_rcde_response.peak_rcde
    peak_rcde_spreading_factor = mod_acc_fetch_rcde_response.peak_rcde_spreading_factor
    peak_rcde_code = mod_acc_fetch_rcde_response.peak_rcde_code
    peak_rcde_branch = mod_acc_fetch_rcde_response.peak_rcde_branch

    mod_acc_fetch_evm_trace_response = client.ModAccFetchEVMTrace(
        nirfmxwcdma_types.ModAccFetchEVMTraceRequest(
            instrument=instr,
            selector_string="",
            timeout=10.000000,
        )
    )
    check_for_warning(mod_acc_fetch_evm_trace_response, instr)

    x0 = mod_acc_fetch_evm_trace_response.x0
    dx = mod_acc_fetch_evm_trace_response.dx
    evm = mod_acc_fetch_evm_trace_response.evm

    mod_acc_fetch_constellation_trace_response = client.ModAccFetchConstellationTrace(
        nirfmxwcdma_types.ModAccFetchConstellationTraceRequest(
            instrument=instr,
            selector_string="",
            timeout=10.000000,
        )
    )
    check_for_warning(mod_acc_fetch_constellation_trace_response, instr)

    constellation = mod_acc_fetch_constellation_trace_response.constellation

    print("----------------------------EVM---------------------------")
    print(f"RMS EVM (%%)                            : {rms_evm}")
    print(f"Peak EVM (%%)                           : {peak_evm}")
    print(f"Rho                                     : {rho}")
    print(f"Frequency Error (Hz)                    : {frequency_error}")
    print(f"Chip Rate Error (ppm)                   : {chip_rate_error}")
    print(f"RMS Magnitude Error (%%)                : {rms_magnitude_error}")
    print(f"RMS Phase Error (deg)                   : {rms_phase_error}")

    print("\n----------------------IQ Impairments----------------------")
    print(f"I/Q Origin Offset (dB)                  : {iq_origin_offset}")
    print(f"I/Q Gain Imbalance (dB)                 : {iq_gain_imbalance}")
    print(f"I/Q Quadrature Error (deg)              : {iq_quadrature_error}")

    print("\n---------------------Code Domain Error--------------------")
    print(f"Peak CDE (dB)                           : {peak_cde}")
    print(f"Peak CDE Code                           : {peak_cde_code}")
    print(f"Peak CDE Branch                         : {'Q' if peak_cde_branch else 'I'}")
    print(f"Peak Active CDE (dB)                    : {peak_active_cde}")
    print(f"Peak Active CDE Code                    : {peak_active_cde_code}")
    print(f"Peak Active CDE Spreading Factor        : {peak_active_cde_spreading_factor}")
    print(f"Peak Active CDE Branch                  : {'Q' if peak_active_cde_branch else 'I'}")
    print(f"Peak RCDE (dB)                          : {peak_rcde}")
    print(f"Peak RCDE Code                          : {peak_rcde_code}")
    print(f"Peak RCDE Spreading Factor              : {peak_rcde_spreading_factor}")
    print(f"Peak RCDE Branch                        : {'Q' if peak_rcde_branch else 'I'}")
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
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
        client.Close(nirfmxwcdma_types.CloseRequest(instrument=instr, force_destroy=False))
