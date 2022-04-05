r"""Route the reference clock source during a simple sine wave generation.

The gRPC API is built from the C API. NI-RFSG documentation is installed with the driver at:
  C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niRFSG\documentation\English\RFSG.chm

Getting Started:

To run this example, install "NI-RFSG Driver" on the server machine:
  https://www.ni.com/en-us/support/downloads/drivers/download.ni-rfsg.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-RFSG gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-RFSG-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and physical channel name can be passed as separate
command line arguments.
  > python reference-clock.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedRFSG" as the physical channel name.
"""

import sys
import time

import grpc
import nirfsg_pb2 as nirfsg_types
import nirfsg_pb2_grpc as grpc_nirfsg

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "NI-RFSG-Session"

# Resource name, channel name and options for a simulated 5652 client.
RESOURCE = "SimulatedRFSG"
OPTIONS = "Simulate=1,DriverSetup=Model:5652"

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
client = grpc_nirfsg.NiRFSGStub(channel)
vi = None


def raise_if_error(response):
    """Raise an exception if an error was returned."""
    if response.status != 0:
        response = client.ErrorMessage(nirfsg_types.ErrorMessageRequest(error_code=response.status))
        raise Exception(f"Error: {response.error_string}")


def raise_if_initialization_error(response):
    """Raise an exception if an error was returned from Initialize."""
    if response.status < 0:
        raise RuntimeError(f"Error: {response.error_message or response.status}")
    if response.status > 0:
        sys.stderr.write(f"Warning: {response.error_message or response.status}\n")
    return response


try:
    response = client.InitWithOptions(
        nirfsg_types.InitWithOptionsRequest(
            session_name=SESSION_NAME, resource_name=RESOURCE, option_string=OPTIONS
        )
    )
    raise_if_initialization_error(response)
    vi = response.vi
    raise_if_error(
        client.ConfigureRF(nirfsg_types.ConfigureRFRequest(vi=vi, frequency=1e9, power_level=-5))
    )
    raise_if_error(
        client.ConfigureGenerationMode(
            nirfsg_types.ConfigureGenerationModeRequest(
                vi=vi, generation_mode=nirfsg_types.GENERATION_MODE_CW
            )
        )
    )
    raise_if_error(
        client.ConfigureRefClock(
            nirfsg_types.ConfigureRefClockRequest(
                vi=vi,
                ref_clock_source_mapped=nirfsg_types.REF_CLOCK_SOURCE_ONBOARD_CLOCK,
                ref_clock_rate=10e6,
            )
        )
    )
    print("Generating...")
    raise_if_error(client.Initiate(nirfsg_types.InitiateRequest(vi=vi)))
    time.sleep(2)
    # Check the generation status
    raise_if_error(client.CheckGenerationStatus(nirfsg_types.CheckGenerationStatusRequest(vi=vi)))
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE:
        error_message = f"Failed to connect to server on {SERVER_ADDRESS}:{SERVER_PORT}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = (
            "The operation is not implemented or is not supported/enabled in this service"
        )
    print(f"{error_message}")
finally:
    if vi:
        client.ConfigureOutputEnabled(
            nirfsg_types.ConfigureOutputEnabledRequest(output_enabled=False)
        )
        client.Close(nirfsg_types.CloseRequest(vi=vi))
