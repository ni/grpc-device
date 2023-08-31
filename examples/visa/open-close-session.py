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
SESSION_NAME = "visa_session"

INSTRUMENT_DESCRIPTOR = "TCPIP::www.ni.com::80::SOCKET"
TIME_OUT = 0
INITIALIZATION_BEHAVIOR = 0

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    INSTRUMENT_DESCRIPTOR = sys.argv[3]


# Create the communication channel for the remote host and a connection to the NI-VISA service.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
client = grpc_visa.VisaStub(channel)

try:
    # Open IO Session
    open_resp = client.Open(
        visa_types.OpenRequest(
            session_name=SESSION_NAME,
            instrument_descriptor=INSTRUMENT_DESCRIPTOR,
            open_timeout=TIME_OUT,
            initialization_behavior=INITIALIZATION_BEHAVIOR,
        )
    )
    vi = open_resp.vi
    session = visa_types.SessionOrEventData(vi=vi)

    # Get some information about the connection
    get_resp = client.GetAttribute(
        visa_types.GetAttributeRequest(
            object_handle=session, attribute_name=visa_types.VisaAttribute.VISA_ATTRIBUTE_TCPIP_ADDR
        )
    )
    print(f"Network address: {get_resp.attribute_value}")

    get_resp = client.GetAttribute(
        visa_types.GetAttributeRequest(
            object_handle=session,
            attribute_name=visa_types.VisaAttribute.VISA_ATTRIBUTE_TCPIP_HOSTNAME,
        )
    )
    print(f"Network hostname: {get_resp.attribute_value}")

    # Change the timeout
    get_resp = client.GetAttribute(
        visa_types.GetAttributeRequest(
            object_handle=session, attribute_name=visa_types.VisaAttribute.VISA_ATTRIBUTE_TMO_VALUE
        )
    )
    print(f"Original timeout in milliseconds: {get_resp.attribute_value}")

    set_resp = client.SetAttribute(
        visa_types.SetAttributeRequest(
            object_handle=session,
            attribute_name=visa_types.VisaAttribute.VISA_ATTRIBUTE_TMO_VALUE,
            attribute_value=visa_types.AttributeValueData(value_u32=7500),
        )
    )

    get_resp = client.GetAttribute(
        visa_types.GetAttributeRequest(
            object_handle=session, attribute_name=visa_types.VisaAttribute.VISA_ATTRIBUTE_TMO_VALUE
        )
    )
    print(f"Original timeout in milliseconds: {get_resp.attribute_value}")

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
    if "session" in vars():
        # Close VISA session
        client.Close(visa_types.CloseRequest(object_handle=session))
