r"""Initiate an acquisition and fetch a waveform for each specified channel.

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
  > python fetch.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedScope" as the resource name.
"""

import sys

import grpc
import niscope_pb2 as niscope_types
import niscope_pb2_grpc as grpc_niscope

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"

# Resource name and options for a simulated 5164 client. Change them according to the NI-SCOPE
# model.
RESOURCE = "SimulatedScope"
OPTIONS = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe"

CHANNELS = "0"

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    RESOURCE = sys.argv[3]
    OPTIONS = ""

# Create the communication channel for the remote host and create a connection to the NI-SCOPE
# service.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
niscope_client = grpc_niscope.NiScopeStub(channel)


def check_for_warning(response, vi):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        warning_message = niscope_client.GetErrorMessage(
            niscope_types.GetErrorMessageRequest(vi=vi, error_code=response.status)
        )
        sys.stderr.write(f"{warning_message.error_message}\nWarning status: {response.status}\n")


try:
    # Open session to NI-SCOPE module with options.
    init_with_options_response = niscope_client.InitWithOptions(
        niscope_types.InitWithOptionsRequest(
            resource_name=RESOURCE,
            id_query=False,
            option_string=OPTIONS,
        )
    )
    vi = init_with_options_response.vi

    # Configure vertical.
    voltage = 10.0
    niscope_client.ConfigureVertical(
        niscope_types.ConfigureVerticalRequest(
            vi=vi,
            channel_list=CHANNELS,
            range=voltage,
            offset=0.0,
            coupling=niscope_types.VerticalCoupling.VERTICAL_COUPLING_NISCOPE_VAL_AC,
            probe_attenuation=1.0,
            enabled=True,
        )
    )

    # Configure horizontal timing.
    samples = 1000
    niscope_client.ConfigureHorizontalTiming(
        niscope_types.ConfigureHorizontalTimingRequest(
            vi=vi,
            min_sample_rate=50000000,
            min_num_pts=samples,
            ref_position=50.0,
            num_records=1,
            enforce_realtime=True,
        )
    )

    # Initiate acquisition.
    initiate_response = niscope_client.InitiateAcquisition(
        niscope_types.InitiateAcquisitionRequest(vi=vi)
    )
    check_for_warning(initiate_response, vi)

    # Fetch waveforms.
    fetch_response = niscope_client.Fetch(
        niscope_types.FetchRequest(vi=vi, channel_list=CHANNELS, timeout=10000, num_samples=samples)
    )
    check_for_warning(fetch_response, vi)
    waveforms = fetch_response.waveform

    # Print waveform results.
    for i in range(len(waveforms)):
        print(f"Waveform {i} information:")
        print(f"{waveforms[i]}\n")

# If NI-SCOPE API throws an exception, print the error message.
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
