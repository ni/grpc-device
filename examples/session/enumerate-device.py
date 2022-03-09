r"""List out devices connected to the server machine.

Getting Started:

To run this example, install the "NI System Configuration API" on the server machine:
  https://www.ni.com/en-in/support/downloads/drivers/download.system-configuration.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Running from command line:

Server machine's IP address and port number can be passed as separate command line arguments.
  > python enumerate-device.py <server_address> <port_number>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763".
"""

import sys

import grpc
import session_pb2 as session_types
import session_pb2_grpc as grpc_session

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]

# Create communication with the server using gRPC APIs.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
client = grpc_session.SessionUtilitiesStub(channel)


def print_devices(devices):
    """Print device info."""
    if not devices:
        print("No devices are connected.")
        return
    print(
        "\n-----------------------------------------------------------------------------------------------------\n"
    )
    print("  List of devices connected to the server: \n")
    print(
        "-----------------------------------------------------------------------------------------------------\n"
    )
    for device in devices:
        print(f"    {device.name}")
        print(f"        Model: {device.model}")
        print(f"        Vendor: {device.vendor}")
        print(f"        Serial Number: {device.serial_number} \n")


try:
    # EnumerateDevices API gives a list of devices (simulated and physical) connected to the server
    # machine.
    enumerate_devices_response = client.EnumerateDevices(session_types.EnumerateDevicesRequest())

    # Display devices connected to the server machine.
    print_devices(enumerate_devices_response.devices)

# If EnumerateDevices API throws an exception, print the error message.
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE:
        error_message = f"Failed to connect to server on {SERVER_ADDRESS}:{SERVER_PORT}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = (
            "The operation is not implemented or is not supported/enabled in this service"
        )
    print(f"{error_message}")
