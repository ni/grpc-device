r"""Fetch TXP data.

Steps:
  1. Open a new RFmx session.
  2. Configure the frequency reference properties (Clock Source and Clock Frequency).
  3. Configure the basic signal properties (Center Frequency and External Attenuation).
  4. Configure IQ Power Edge Trigger properties (Trigger Delay, IQ Power Edge Level, Minimum Quiet
     Time).
  5. Configure Standard and Channel Bandwidth Properties.
  6. Configure Reference Level.
  7. Select TXP measurement and enable the traces.
  8. Configure the Measurement Interval.
  9. Configure Averaging parameters.
  10. Initiate Measurement.
  11. Fetch TXP Traces and Measurements.
  12. Close the RFmx Session.

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
  > python txp-basic.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedDevice" as the resource name.
"""

import sys

import grpc
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
    auto_level = True

    initialize_response = raise_if_initialization_error(
        client.Initialize(
            nirfmxwlan_types.InitializeRequest(
                session_name=SESSION_NAME, resource_name=RESOURCE, option_string=OPTIONS
            )
        )
    )
    instr = initialize_response.instrument
    raise_if_error(
        client.CfgFrequencyReference(
            nirfmxwlan_types.CfgFrequencyReferenceRequest(
                instrument=instr,
                channel_name="",
                frequency_reference_source_mapped=nirfmxwlan_types.FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK,
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
                trigger_min_quiet_time_duration=5.0e-6,
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
    if auto_level:
        raise_if_error(
            client.AutoLevel(
                nirfmxwlan_types.AutoLevelRequest(
                    instrument=instr, selector_string="", measurement_interval=10e-3
                )
            )
        )
    else:
        raise_if_error(
            client.CfgReferenceLevel(
                nirfmxwlan_types.CfgReferenceLevelRequest(
                    instrument=instr, selector_string="", reference_level=0.0
                )
            )
        )
    raise_if_error(
        client.SelectMeasurements(
            nirfmxwlan_types.SelectMeasurementsRequest(
                instrument=instr,
                selector_string="",
                measurements=nirfmxwlan_types.MEASUREMENT_TYPES_TXP,
                enable_all_traces=True,
            )
        )
    )
    raise_if_error(
        client.TXPCfgMaximumMeasurementInterval(
            nirfmxwlan_types.TXPCfgMaximumMeasurementIntervalRequest(
                instrument=instr, selector_string="", maximum_measurement_interval=1e-3
            )
        )
    )
    raise_if_error(
        client.TXPCfgAveraging(
            nirfmxwlan_types.TXPCfgAveragingRequest(
                instrument=instr,
                selector_string="",
                averaging_enabled=nirfmxwlan_types.TXP_AVERAGING_ENABLED_FALSE,
                averaging_count=10,
            )
        )
    )
    raise_if_error(
        client.Initiate(
            nirfmxwlan_types.InitiateRequest(instrument=instr, selector_string="", result_name="")
        )
    )

    ### Fetch results ###

    txp_fetch_power_trace_response = raise_if_error(
        client.TXPFetchPowerTrace(
            nirfmxwlan_types.TXPFetchPowerTraceRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    x0 = txp_fetch_power_trace_response.x0
    dx = txp_fetch_power_trace_response.dx
    power = txp_fetch_power_trace_response.power
    txp_fetch_measurement_response = raise_if_error(
        client.TXPFetchMeasurement(
            nirfmxwlan_types.TXPFetchMeasurementRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    average_power_mean = txp_fetch_measurement_response.average_power_mean
    peak_power_maximum = txp_fetch_measurement_response.peak_power_maximum

    print("\n----------Measurement----------\n")
    print(f"Average Power Mean (dBm)          : {average_power_mean}")
    print(f"Peak Power Maximum (dBm)          : {peak_power_maximum}")
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
