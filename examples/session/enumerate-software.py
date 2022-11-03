r"""List out NI software installed on the server machine.

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

import argparse

import grpc
import session_pb2 as session_types
import session_pb2_grpc as grpc_session

# Parser for command-line options
parser = argparse.ArgumentParser(
    description="Lists out NI software installed on the server machine."
)
parser.add_argument(
    "server_address",
    help="The IP address or machine name of the server. The default is localhost.",
    nargs="?",
    default="localhost",
)
parser.add_argument(
    "port_number",
    help="The port number of the server. The default is 31763.",
    nargs="?",
    default="31763",
)
parser.add_argument(
    "--show-hidden",
    help="Include hidden packages in the list of software.",
    action="store_true",
    default=False,
)
args = parser.parse_args()

# Read in cmd args
SERVER_ADDRESS = args.server_address
SERVER_PORT = args.port_number
SHOW_HIDDEN_PACKAGES = args.show_hidden

# Open communication with the server using gRPC APIs.
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
        print(f"    Package ID: {package.package_id}")
        print(f"    Product Name: {package.product_name}")
        print(f"    Version: {package.package_version} \n")


try:
    # The EnumerateInstalledSoftware API gives a list of NI packages installed on the server machine.
    if SHOW_HIDDEN_PACKAGES:
        enumerate_software_response = client.EnumerateInstalledSoftwareIncludeHiddenPackages(
            session_types.EnumerateInstalledSoftwareIncludeHiddenPackagesRequest()
        )
    else:
        enumerate_software_response = client.EnumerateInstalledSoftware(
            session_types.EnumerateInstalledSoftwareRequest()
        )

    # Display software installed on the server machine.
    print_software(enumerate_software_response.software)

# If the EnumerateInstalledSoftware API throws an exception, print the error message.
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
