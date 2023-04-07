r"""Continuously read and plot waveform data from an NI-SCOPE device.

The gRPC API is built from the C API. NI-SCOPE documentation is installed with the driver at:
  C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niScope\Documentation\English\Digitizers.chm

A version of this .chm is available online at:
  https://zone.ni.com/reference/en-XX/help/370592AB-01/

Getting Started:

To run this example, install "NI-SCOPE Driver" on the server machine:
  https://www.ni.com/en-us/support/downloads/drivers/download.ni-scope.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-SCOPE gRPC Wiki to determine the valid channel and resource names for your NI-SCOPE
module:
  https://github.com/ni/grpc-device/wiki/NI-SCOPE-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and resource name can be passed as separate command line
arguments.
  > python plot-read-waveform.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedScope" as the resource name.
"""

import sys

import grpc
import niscope_pb2 as niscope_types
import niscope_pb2_grpc as grpc_scope

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"

# Resource name and options for a simulated 5164 client. Change them according to the NI-SCOPE
# model.
RESOURCE = "SimulatedScope"
OPTIONS = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe; MemorySize:1610612736"

CHANNELS = "0"

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    RESOURCE = sys.argv[3]
    OPTIONS = ""


def check_for_warning(response, vi):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        warning_message = niscope_client.GetErrorMessage(
            niscope_types.GetErrorMessageRequest(vi=vi, error_code=response.status)
        )
        sys.stderr.write(f"{warning_message.error_message}\nWarning status: {response.status}\n")


# Create the communcation channel for the remote host (in this case we are connecting to a local
# server) and create a connection to the niScope service
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
niscope_client = grpc_scope.NiScopeStub(channel)

try:
    # Initialize the scope
    init_result = niscope_client.InitWithOptions(
        niscope_types.InitWithOptionsRequest(
            session_name="demo",
            resource_name=RESOURCE,
            id_query=False,
            option_string=OPTIONS,
        )
    )
    vi = init_result.vi

    # Configure horizontal timing
    config_result = niscope_client.ConfigureHorizontalTiming(
        niscope_types.ConfigureHorizontalTimingRequest(
            vi=vi,
            min_sample_rate=1000000,
            min_num_pts=100000,
            ref_position=50,
            num_records=1,
            enforce_realtime=True,
        )
    )

    # Configure vertical timing
    vertical_result = niscope_client.ConfigureVertical(
        niscope_types.ConfigureVerticalRequest(
            vi=vi,
            channel_list=CHANNELS,
            range=10.0,
            offset=0,
            coupling=niscope_types.VerticalCoupling.VERTICAL_COUPLING_NISCOPE_VAL_DC,
            enabled=True,
            probe_attenuation=1,
        )
    )

    conf_trigger_edge_result = niscope_client.ConfigureTriggerEdge(
        niscope_types.ConfigureTriggerEdgeRequest(
            vi=vi,
            trigger_source=CHANNELS,
            level=0.00,
            trigger_coupling=niscope_types.TriggerCoupling.TRIGGER_COUPLING_NISCOPE_VAL_DC,
            slope=niscope_types.TriggerSlope.TRIGGER_SLOPE_NISCOPE_VAL_POSITIVE,
        )
    )

    result = niscope_client.SetAttributeViInt32(
        niscope_types.SetAttributeViInt32Request(
            vi=vi,
            channel_list=CHANNELS,
            attribute_id=niscope_types.NiScopeAttribute.NISCOPE_ATTRIBUTE_MEAS_REF_LEVEL_UNITS,
            value=niscope_types.NiScopeInt32AttributeValues.NISCOPE_INT32_MEAS_REF_LEVEL_UNITS_VAL_MEAS_VOLTAGE,
        )
    )

    # Read a waveform from the scope
    read_result = niscope_client.Read(
        niscope_types.ReadRequest(vi=vi, channel_list=CHANNELS, timeout=10000, num_samples=100000)
    )
    check_for_warning(read_result, vi)
    values = read_result.waveform[0:10]
    print(values)

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
    print(f"{error_message}")

finally:
    if "vi" in vars() and vi.name != "":
        # close the session.
        niscope_client.Close(niscope_types.CloseRequest(vi=vi))
