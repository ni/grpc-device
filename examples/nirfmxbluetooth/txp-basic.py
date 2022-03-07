r"""Fetch TXP data.

Steps:
  1. Open a new RFmx Session.
  2. Configure Frequency Reference.
  3. Configure basic signal properties(Center Frequency and External Attenuation).
  4. Configure Trigger Type and Trigger Parameters.
  5. Configure Packet Type.
  6. Configure Data Rate.
  7. Configure Payload Length.
  8. Configure Direction Finding.
  9. Configure Reference Level.
  10. Select TXP measurement and enable Traces.
  11. Configure TXP Burst Synchronization Type.
  12. Configure Averaging Parameters for TXP measurement.
  13. Initiate the Measurement.
  14. Fetch TXP Measurements and Trace.
  15. Close RFmx Session.

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
  > python txp-basic.py <server_address> <port_number> <resource_name>
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
    resource = sys.argv[3]
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
    auto_level = True
    basic_rate_packets = True

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
        client.CfgFrequency(
            nirfmxbluetooth_types.CfgFrequencyRequest(
                instrument=instr, selector_string="", center_frequency=2.402000e9
            )
        )
    )
    raise_if_error(
        client.CfgExternalAttenuation(
            nirfmxbluetooth_types.CfgExternalAttenuationRequest(
                instrument=instr, selector_string="", external_attenuation=0.0
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
        client.CfgLEDirectionFinding(
            nirfmxbluetooth_types.CfgLEDirectionFindingRequest(
                instrument=instr,
                selector_string="",
                direction_finding_mode=nirfmxbluetooth_types.DIRECTION_FINDING_MODE_DISABLED,
                cte_length=160e-6,
                cte_slot_duration=1e-6,
            )
        )
    )
    if auto_level:
        auto_level_response = raise_if_error(
            client.AutoLevel(
                nirfmxbluetooth_types.AutoLevelRequest(
                    instrument=instr, selector_string="", measurement_interval=10e-3
                )
            )
        )
        reference_level = auto_level_response.reference_level
    else:
        raise_if_error(
            client.CfgReferenceLevel(
                nirfmxbluetooth_types.CfgReferenceLevelRequest(
                    instrument=instr, selector_string="", reference_level=0.0
                )
            )
        )
    raise_if_error(
        client.SelectMeasurements(
            nirfmxbluetooth_types.SelectMeasurementsRequest(
                instrument=instr,
                selector_string="",
                measurements=nirfmxbluetooth_types.MEASUREMENT_TYPES_TXP,
                enable_all_traces=True,
            )
        )
    )
    raise_if_error(
        client.TXPCfgBurstSynchronizationType(
            nirfmxbluetooth_types.TXPCfgBurstSynchronizationTypeRequest(
                instrument=instr,
                selector_string="",
                burst_synchronization_type=nirfmxbluetooth_types.TXP_BURST_SYNCHRONIZATION_TYPE_NONE,
            )
        )
    )
    raise_if_error(
        client.TXPCfgAveraging(
            nirfmxbluetooth_types.TXPCfgAveragingRequest(
                instrument=instr,
                selector_string="",
                averaging_enabled=nirfmxbluetooth_types.TXP_AVERAGING_ENABLED_FALSE,
                averaging_count=10,
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

    txp_fetch_powers_response = raise_if_error(
        client.TXPFetchPowers(
            nirfmxbluetooth_types.TXPFetchPowersRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    average_power_mean = txp_fetch_powers_response.average_power_mean
    average_power_maximum = txp_fetch_powers_response.average_power_maximum
    average_power_minimum = txp_fetch_powers_response.average_power_minimum
    peak_to_average_power_ratio_maximum = (
        txp_fetch_powers_response.peak_to_average_power_ratio_maximum
    )
    txp_fetch_edr_powers_response = raise_if_error(
        client.TXPFetchEDRPowers(
            nirfmxbluetooth_types.TXPFetchEDRPowersRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    edrgfsk_average_power_mean = txp_fetch_edr_powers_response.edr_gfsk_average_power_mean
    edrdpsk_average_power_mean = txp_fetch_edr_powers_response.edr_dpsk_average_power_mean
    edr_dpsk_gfsk_average_power_ratio_mean = (
        txp_fetch_edr_powers_response.edr_dpsk_gfsk_average_power_ratio_mean
    )
    txp_fetch_lecte_reference_period_powers_response = raise_if_error(
        client.TXPFetchLECTEReferencePeriodPowers(
            nirfmxbluetooth_types.TXPFetchLECTEReferencePeriodPowersRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    reference_period_average_power_mean = (
        txp_fetch_lecte_reference_period_powers_response.reference_period_average_power_mean
    )
    reference_period_peak_absolute_power_deviation_maximum = (
        txp_fetch_lecte_reference_period_powers_response.reference_period_peak_absolute_power_deviation_maximum
    )

    txp_fetch_lecte_transmit_slot_powers_array_response = raise_if_error(
        client.TXPFetchLECTETransmitSlotPowersArray(
            nirfmxbluetooth_types.TXPFetchLECTETransmitSlotPowersArrayRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    transmit_slot_average_power_mean = (
        txp_fetch_lecte_transmit_slot_powers_array_response.transmit_slot_average_power_mean
    )
    transmit_slot_peak_absolute_power_deviation_maximum = (
        txp_fetch_lecte_transmit_slot_powers_array_response.transmit_slot_peak_absolute_power_deviation_maximum
    )

    txp_fetch_power_trace_response = raise_if_error(
        client.TXPFetchPowerTrace(
            nirfmxbluetooth_types.TXPFetchPowerTraceRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    x0 = txp_fetch_power_trace_response.x0
    dx = txp_fetch_power_trace_response.dx
    power = txp_fetch_power_trace_response.power

    print("------------------Measurement------------------")
    print(f"Average Power Mean (dBm)                        : {average_power_mean}")
    print(f"Average Power Maximum (dBm)                     : {average_power_maximum}")
    print(f"Average Power Minimum (dBm)                     : {average_power_minimum}")
    print(
        f"Peak to Average Power Ratio Maximum (dB)        : {peak_to_average_power_ratio_maximum}"
    )

    # These results are invalid for basic rate packets.
    if not basic_rate_packets:
        print(f"EDR GFSK Average Power Mean (dBm)               : {edrgfsk_average_power_mean}")
        print(f"EDR DPSK Average Power Mean (dBm)               : {edrdpsk_average_power_mean}")
        print(
            f"EDR DPSK GFSK Average Power Ratio Mean (dB)     : {edr_dpsk_gfsk_average_power_ratio_mean}"
        )

    # These results are invalid for basic rate packets.
    if not basic_rate_packets:
        print("------------------LE CTE Reference Period Measurement------------------")
        print(
            f"Average Power Mean (dBm)                                         : {reference_period_average_power_mean}"
        )
        print(
            f"Peak Absolute Power Deviation Maximum (%)                        : {reference_period_peak_absolute_power_deviation_maximum}\n"
        )

    print("------------------LE CTE Transmit Slot Power Measurement------------------")
    if len(transmit_slot_average_power_mean) == 0:
        print("No data")
    for i in range(len(transmit_slot_average_power_mean)):
        print(
            f"Average Power Mean (dBm)[{i}]                     : {transmit_slot_average_power_mean[i]}\n"
        )
        print(
            f"Peak Absolute Power Deviation Maximum (%)[{i}]    : {transmit_slot_peak_absolute_power_deviation_maximum[i]}\n"
        )
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
