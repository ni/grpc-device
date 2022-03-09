r"""Fetch ACP data.

Steps:
  1. Open a new RFmx Session.
  2. Configure Frequency Reference.
  3. Configure basic signal properties(Center Frequency, Reference Level and External Attenuation).
  4. Configure Trigger Type and Trigger Parameters.
  5. Configure Packet Type.
  6. Configure Data Rate.
  7. Configure Payload Length.
  8. Select ACP measurement and enable Traces.
  9. Configure ACP Burst Sync Type.
  10. Configure Averaging Parameters for ACP measurement.
  11. Configure Number of Offsets or Channel Number depending on Offset Channel Mode.
  12. Initiate the Measurement.
  13. Fetch ACP Measurements and Trace.
  14. Close RFmx Session.

The gRPC API is built from the C API. RFmx Bluetooth documentation is installed with the driver at:
  C:\Program Files (x86)\National Instruments\RFmx\BT\Documentation\rfmxbtcvi.chm

Getting Started:

To run this example, install "RFmx Bluetooth" on the server machine:
  https://www.ni.com/en-us/support/downloads/software-products/download.rfmx-bluetooth.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-RFmxBluetooth gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-RFmxBluetooth-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and physical channel name can be passed as separate
command line arguments.
  > python acp-basic.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedDevice" as the resource name.
"""

import sys

import grpc
import nirfmxbluetooth_pb2 as nirfmxbluetooth_types
import nirfmxbluetooth_pb2_grpc as grpc_nirfmxbluetooth

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "RFmxBluetoothSession"

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
client = grpc_nirfmxbluetooth.NiRFmxBluetoothStub(channel)
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
            nirfmxbluetooth_types.GetErrorRequest(
                instrument=instr,
            )
        )
        if response.status < 0:
            raise RuntimeError(f"Error: {error_response.error_description or response.status}")
        else:
            sys.stderr.write(f"Warning: {error_response.error_description or response.status}\n")

    return response


try:
    offset_channel_mode = nirfmxbluetooth_types.ACP_OFFSET_CHANNEL_MODE_SYMMETRIC

    initialize_response = raise_if_initialization_error(
        client.Initialize(
            nirfmxbluetooth_types.InitializeRequest(
                session_name=SESSION_NAME, resource_name=RESOURCE, option_string=OPTIONS
            )
        )
    )
    instr = initialize_response.instrument
    raise_if_error(
        client.CfgFrequencyReference(
            nirfmxbluetooth_types.CfgFrequencyReferenceRequest(
                instrument=instr,
                channel_name="",
                frequency_reference_source_mapped=nirfmxbluetooth_types.FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK,
                frequency_reference_frequency=10e6,
            )
        )
    )
    raise_if_error(
        client.CfgRF(
            nirfmxbluetooth_types.CfgRFRequest(
                instrument=instr,
                selector_string="",
                center_frequency=2.402e9,
                reference_level=0.0,
                external_attenuation=0.0,
            )
        )
    )
    raise_if_error(
        client.CfgIQPowerEdgeTrigger(
            nirfmxbluetooth_types.CfgIQPowerEdgeTriggerRequest(
                instrument=instr,
                selector_string="",
                iq_power_edge_source="0",
                iq_power_edge_slope=nirfmxbluetooth_types.IQ_POWER_EDGE_TRIGGER_SLOPE_RISING,
                iq_power_edge_level=-20.0,
                trigger_delay=0.0,
                trigger_min_quiet_time_mode=nirfmxbluetooth_types.TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO,
                trigger_min_quiet_time_duration=100e-6,
                iq_power_edge_level_type=nirfmxbluetooth_types.IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE,
                enable_trigger=False,
            )
        )
    )
    raise_if_error(
        client.CfgPacketType(
            nirfmxbluetooth_types.CfgPacketTypeRequest(
                instrument=instr,
                selector_string="",
                packet_type=nirfmxbluetooth_types.PACKET_TYPE_DH1,
            )
        )
    )
    raise_if_error(
        client.CfgDataRate(
            nirfmxbluetooth_types.CfgDataRateRequest(
                instrument=instr, selector_string="", data_rate=1000000
            )
        )
    )
    raise_if_error(
        client.CfgPayloadLength(
            nirfmxbluetooth_types.CfgPayloadLengthRequest(
                instrument=instr,
                selector_string="",
                payload_length_mode=nirfmxbluetooth_types.PAYLOAD_LENGTH_MODE_AUTO,
                payload_length=10,
            )
        )
    )
    raise_if_error(
        client.SelectMeasurements(
            nirfmxbluetooth_types.SelectMeasurementsRequest(
                instrument=instr,
                selector_string="",
                measurements=nirfmxbluetooth_types.MEASUREMENT_TYPES_ACP,
                enable_all_traces=True,
            )
        )
    )
    raise_if_error(
        client.ACPCfgBurstSynchronizationType(
            nirfmxbluetooth_types.ACPCfgBurstSynchronizationTypeRequest(
                instrument=instr,
                selector_string="",
                burst_synchronization_type=nirfmxbluetooth_types.ACP_BURST_SYNCHRONIZATION_TYPE_PREAMBLE,
            )
        )
    )
    raise_if_error(
        client.ACPCfgAveraging(
            nirfmxbluetooth_types.ACPCfgAveragingRequest(
                instrument=instr,
                selector_string="",
                averaging_enabled=nirfmxbluetooth_types.ACP_AVERAGING_ENABLED_FALSE,
                averaging_count=10,
            )
        )
    )
    raise_if_error(
        client.ACPCfgOffsetChannelMode(
            nirfmxbluetooth_types.ACPCfgOffsetChannelModeRequest(
                instrument=instr,
                selector_string="",
                offset_channel_mode=offset_channel_mode,
            )
        )
    )
    if offset_channel_mode == nirfmxbluetooth_types.ACP_OFFSET_CHANNEL_MODE_SYMMETRIC:
        raise_if_error(
            client.ACPCfgNumberOfOffsets(
                nirfmxbluetooth_types.ACPCfgNumberOfOffsetsRequest(
                    instrument=instr, selector_string="", number_of_offsets=5
                )
            )
        )
    elif offset_channel_mode == nirfmxbluetooth_types.ACP_OFFSET_CHANNEL_MODE_INBAND:
        raise_if_error(
            client.CfgChannelNumber(
                nirfmxbluetooth_types.CfgChannelNumberRequest(
                    instrument=instr, selector_string="", channel_number=0
                )
            )
        )
    raise_if_error(
        client.Initiate(
            nirfmxbluetooth_types.InitiateRequest(
                instrument=instr, selector_string="", result_name=""
            )
        )
    )

    ### Fetch Results ###

    acp_fetch_measurement_status_response = raise_if_error(
        client.ACPFetchMeasurementStatus(
            nirfmxbluetooth_types.ACPFetchMeasurementStatusRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    measurement_status = acp_fetch_measurement_status_response.measurement_status
    if (
        measurement_status
        == nirfmxbluetooth_types.NIRFMXBLUETOOTH_INT32_ACP_RESULTS_MEASUREMENT_STATUS_NOT_APPLICABLE
    ):
        measurement_status_string = "Not Applicable"
    elif (
        measurement_status
        == nirfmxbluetooth_types.NIRFMXBLUETOOTH_INT32_ACP_RESULTS_MEASUREMENT_STATUS_PASS
    ):
        measurement_status_string = "Pass"
    else:
        measurement_status_string = "Fail"

    acp_fetch_reference_channel_power_response = raise_if_error(
        client.ACPFetchReferenceChannelPower(
            nirfmxbluetooth_types.ACPFetchReferenceChannelPowerRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    reference_channel_power = acp_fetch_reference_channel_power_response.reference_channel_power

    acp_fetch_offset_measurement_array_response = raise_if_error(
        client.ACPFetchOffsetMeasurementArray(
            nirfmxbluetooth_types.ACPFetchOffsetMeasurementArrayRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    lower_absolute_power = acp_fetch_offset_measurement_array_response.lower_absolute_power
    upper_absolute_power = acp_fetch_offset_measurement_array_response.upper_absolute_power
    lower_relative_power = acp_fetch_offset_measurement_array_response.lower_relative_power
    upper_relative_power = acp_fetch_offset_measurement_array_response.upper_relative_power
    lower_margin = acp_fetch_offset_measurement_array_response.lower_margin
    upper_margin = acp_fetch_offset_measurement_array_response.upper_margin

    acp_fetch_mask_trace_response = raise_if_error(
        client.ACPFetchMaskTrace(
            nirfmxbluetooth_types.ACPFetchMaskTraceRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    x0 = acp_fetch_mask_trace_response.x0
    dx = acp_fetch_mask_trace_response.dx
    limit_with_exception_mask = acp_fetch_mask_trace_response.limit_with_exception_mask
    limit_without_exception_mask = acp_fetch_mask_trace_response.limit_without_exception_mask

    x0 = 0.0
    dx = 0.0
    acp_fetch_absolute_power_trace_response = raise_if_error(
        client.ACPFetchAbsolutePowerTrace(
            nirfmxbluetooth_types.ACPFetchAbsolutePowerTraceRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    x0 = acp_fetch_absolute_power_trace_response.x0
    dx = acp_fetch_absolute_power_trace_response.dx
    absolute_power = acp_fetch_absolute_power_trace_response.absolute_power

    x0 = 0.0
    dx = 0.0
    acp_fetch_spectrum_response = raise_if_error(
        client.ACPFetchSpectrum(
            nirfmxbluetooth_types.ACPFetchSpectrumRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    x0 = acp_fetch_spectrum_response.x0
    dx = acp_fetch_spectrum_response.dx
    spectrum = acp_fetch_spectrum_response.spectrum

    print("------------------ACP------------------")
    print(f"Measurement Status                   : {measurement_status_string}")
    print(f"Reference Channel Power (dBm)        : {reference_channel_power}\n")
    print("------------------Offset Measurements------------------")
    if len(lower_absolute_power) == 0:
        print("No data")
    for i in range(len(lower_absolute_power)):
        print(f"Offset {i}")
        print(f"Lower Absolute Powers (dBm)          : {lower_absolute_power[i]}")
        print(f"Upper Absolute Powers (dBm)          : {upper_absolute_power[i]}")
        print(f"Lower Relative Powers (dB)           : {lower_relative_power[i]}")
        print(f"Upper Relative Powers (dB)           : {upper_relative_power[i]}")
        # Lower and Upper margin results are not applicable for ACP_OFFSET_CHANNEL_MODE_SYMMETRIC.
        if offset_channel_mode != nirfmxbluetooth_types.ACP_OFFSET_CHANNEL_MODE_SYMMETRIC:
            print(f"Lower Margin (dB)                    : {lower_margin[i]}")
            print(f"Upper Margin (dB)                    : {upper_margin[i]}\n")
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
        client.Close(nirfmxbluetooth_types.CloseRequest(instrument=instr, force_destroy=False))
