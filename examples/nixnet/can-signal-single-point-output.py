r""" Write Signal Data.

 This example writes a signal value when a keyboard character is pressed.
 This is used to demonstrate a signal single point output session. 
 This example uses hardcoded signal names that use the NIXNET_example database. 

The gRPC API is built from the C API. NI-XNET documentation is installed with the driver at:
  C:\Users\Public\Documents\National Instruments\NI-XNET\Documentation\NI-XNET Manual.chm
Getting Started:

To run this example, install "NI-XNET Driver" on the server machine:
  https://www.ni.com/en-in/support/downloads/drivers/download.ni-xnet.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI XNET gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-XNET-C-Function-Reference

 Running from command line:

Server machine's IP address and port number can be passed as separate command line
arguments.
  > python can-signal-single-point-output.py <server_address> <port_number>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763"
"""

from logging import raiseExceptions
import sys

import getch
import grpc
import nixnet_pb2 as nixnet_types
import nixnet_pb2_grpc as grpc_nixnet

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]

# Parameters
INTERFACE = "CAN1"
DATABASE = "NIXNET_example"
CLUSTER = "CAN_Cluster"
SIGNAL_LIST = "CANEventSignal1,CANEventSignal2"
NUM_SIGNALS = 2
SUCCESS = 0

# Display Error Function
def check_for_error(status):
    """Raise an exception if the status indicates an error."""
    if status != 0:
        error_message_response = client.StatusToString(
            nixnet_types.StatusToStringRequest(status_id=status)
        )
        raise Exception(error_message_response.status_description)


i = 0
value_buffer = [0] * NUM_SIGNALS

# Create the communication channel for the remote host and create connections to the NI-XNET and
# session services.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
client = grpc_nixnet.NiXnetStub(channel)

# Display parameters that will be used for the example.
print("Interface: " + INTERFACE, "Database: " + DATABASE, "Signal List: " + SIGNAL_LIST, sep="\n")

try:
    # Create an XNET session in SignalOutSinglePoint mode
    create_session_response = client.CreateSession(
        nixnet_types.CreateSessionRequest(
            database_name=DATABASE,
            cluster_name=CLUSTER,
            list=SIGNAL_LIST,
            interface=INTERFACE,
            mode=nixnet_types.CREATE_SESSION_MODE_MODE_SIGNAL_OUT_SINGLE_POINT,
        )
    )
    check_for_error(create_session_response.status)

    session_reference = create_session_response.session_ref

    print("Session Created Successfully.\n")
    print("\nPress any key to transmit new signal values or q to quit\n")

    while not (getch.getch()).decode("UTF-8") == "q":
        value_buffer[0] = float(i)
        value_buffer[1] = float(i * 10)

        # Update the signal data
        write_signal_response = client.WriteSignalSinglePoint(
            nixnet_types.WriteSignalSinglePointRequest(
                session_ref=session_reference, value_buffer=value_buffer
            )
        )
        check_for_error(write_signal_response.status)

        print("Signals sent:")
        print(f"Signal 1: {value_buffer[0]}")
        print(f"Signal 2: {value_buffer[1]}", end="\n\n")
        i = i + 1 if i < 10 else 0

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
    if "session_refernce" in vars() and session_reference.id != 0:
        # clear the XNET session.
        check_for_error(
            client.Clear(nixnet_types.ClearRequest(session_ref=session_reference)).status
        )
        print("Session cleared successfully!\n")
