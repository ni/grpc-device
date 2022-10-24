r"""List out devices connected to the server machine.

Getting Started:

To run this example, install the "NI System Configuration API" on the server machine:
  https://www.ni.com/en-in/support/downloads/drivers/download.system-configuration.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Running from command line:

Server machine's IP address and port number can be passed as separate command line arguments.
  > python enumerate-software.py <server_address> <port_number>
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


def print_software(software):
    """Print software info."""
    if not software:
        print("No software available.")
        return
    print(
        "\n-----------------------------------------------------------------------------------------------------\n"
    )
    print("  List of NI software installed on the server: \n")
    print(
        "-----------------------------------------------------------------------------------------------------\n"
    )
    for package in software:
        print(f"    Product Name: {package.product_name}")
        print(f"    Package Name: {package.package_name}")
        print(f"    Serial Number: {package.version} \n")


try:
    # EnumerateSoftware API gives a list of devices (simulated and physical) connected to the server
    # machine.
    enumerate_software_response = client.EnumerateSoftware(session_types.EnumerateSoftwareRequest())

    # Display devices connected to the server machine.
    print_software(enumerate_software_response.software)

# If EnumerateSoftware API throws an exception, print the error message.
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
    print(f"{error_message}")
