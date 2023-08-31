r"""Perform continuous measure record.

The gRPC API is built from the C API. NI-VISA documentation is installed with the driver at:
  C:\Program Files (x86)\IVI Foundation\VISA\WinNT\NIvisa\ni-visa.chm

Getting Started:

To run this example, install "NI-VISA" on the server machine:
  https://www.ni.com/en/support/downloads/drivers/download.ni-visa.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Running from command line:

Server machine's IP address, port number, and resource name can be passed as separate command line
arguments.
  > python find-resources.py <server_address> <port_number>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763".
"""

import sys

import grpc
import visa_pb2 as visa_types
import visa_pb2_grpc as grpc_visa

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]


# Create the communication channel for the remote host and a connection to the NI-VISA service.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
client = grpc_visa.VisaStub(channel)

try:
    # Query for resources.
    find_resources_resp = client.FindRsrc(visa_types.FindRsrcRequest(expression="?*"))

    # Get information about each resource.
    for resource in find_resources_resp.instrument_descriptor:
        parse_resp = client.ParseRsrc(visa_types.ParseRsrcRequest(resource_name=resource))
        print(
            f"Resource: {parse_resp.expanded_unaliased_name}, Class: {parse_resp.resource_class}, Alias: {parse_resp.alias_if_exists}"
        )

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
