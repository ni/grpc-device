r""" Write Signal Data.

 This example writes a signal value for 10 times.
 This is used to demonstrate a signal single point output session. 
 This example uses hardcoded signal names that use the NIXNET_example database.
 To use your own database, you need to add an alias to your database file using the NI-XNET 
 Database Editor and then modify the database name and signals used here.
 Also ensure that the transceivers are externally powered when using C Series modules.

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
Server machine's IP address, port number, and interface name can be passed as separate command line
arguments.
  > python can-signal-single-point-output.py <server_address> <port_number> <interface_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763"
"""

import sys

import grpc
import nixnet_pb2 as nixnet_types
import nixnet_pb2_grpc as grpc_nixnet

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
INTERFACE = "CAN1"

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    INTERFACE = sys.argv[3]

# Parameters
DATABASE = "NIXNET_example"
CLUSTER = "CAN_Cluster"
SIGNAL_LIST = "CANEventSignal1,CANEventSignal2"
NUM_SIGNALS = 2


i = 0
value_buffer = [0.0] * NUM_SIGNALS
session = None

# Create the communication channel for the remote host and create connections to the NI-XNET and
# session services.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
client = grpc_nixnet.NiXnetStub(channel)


def check_for_warning(response):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        warning_message = client.StatusToString(
            nixnet_types.StatusToStringRequest(status_id=response.status)
        )
        sys.stderr.write(
            f"{warning_message.status_description}\nWarning status: {response.status}\n"
        )


# Display parameters that will be used for the example.
print("Interface: " + INTERFACE, "Database: " + DATABASE, "Signal List: " + SIGNAL_LIST, sep="\n")

try:
    # Create an XNET session in SignalOutSinglePoint mode
    create_session_response = client.CreateSession(
        nixnet_types.CreateSessionRequest(
            database_name=DATABASE,
            cluster_name=CLUSTER,
            list=SIGNAL_LIST,
            interface_name=INTERFACE,
            mode=nixnet_types.CREATE_SESSION_MODE_SIGNAL_OUT_SINGLE_POINT,
        )
    )
    session = create_session_response.session
    print("Session Created Successfully.\n")

    print("Writing 10 values to CAN Interface.\n")

    while i < 10:
        value_buffer[0] = float(i)
        value_buffer[1] = float(i * 10)

        # Update the signal data
        write_signal_response = client.WriteSignalSinglePoint(
            nixnet_types.WriteSignalSinglePointRequest(session=session, value_buffer=value_buffer)
        )
        check_for_warning(write_signal_response)

        print("Signals sent:")
        print(f"Signal 1: {value_buffer[0]}")
        print(f"Signal 2: {value_buffer[1]}", end="\n\n")
        i = i + 1

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
    # Clear the XNET session.
    if session:
        client.Clear(nixnet_types.ClearRequest(session=session))
