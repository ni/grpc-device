r""" Read Signal Data.
 
 This example reads a signal value for 10 times.
 This is used to demonstrate a signal single point input session. 
 This example uses hardcoded signal names that use the NIXNET_example database. 
 To use your own database, you need to add an alias to your database file using the NI-XNET
 Database Editor and then modify the database name and signals used here.
 Also ensure that the bus is properly terminated as this example does not enable the on-board
 termination.

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
  > python flexray-signal-single-point-input.py <server_address> <port_number> <interface_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763"
"""

import sys

import grpc
import nixnet_pb2 as nixnet_types
import nixnet_pb2_grpc as grpc_nixnet

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
INTERFACE = "FlexRay2"

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    INTERFACE = sys.argv[3]

# Parameters
DATABASE = "NIXNET_example"
CLUSTER = "FlexRay_Cluster"
SIGNAL_LIST = "FlexRayEventSignal1,FlexRayEventSignal2"
NUM_SIGNALS = 2


def check_for_error(status):
    """Raise an exception if the status indicates an error."""
    if status != 0:
        error_message_response = client.StatusToString(
            nixnet_types.StatusToStringRequest(status_id=status)
        )
        raise Exception(error_message_response.status_description)


i = 0
keyslot_id = 1
session = None

# Create the communication channel for the remote host and create connections to the NI-XNET and
# session services.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
client = grpc_nixnet.NiXnetStub(channel)

# Display parameters that will be used for the example.
print("Interface: " + INTERFACE, "Database: " + DATABASE, "Signal List: " + SIGNAL_LIST, sep="\n")
print("KeySlotId:", keyslot_id)

try:
    # Create an XNET session in SignalOutSinglePoint mode
    create_session_response = client.CreateSession(
        nixnet_types.CreateSessionRequest(
            database_name=DATABASE,
            cluster_name=CLUSTER,
            list=SIGNAL_LIST,
            interface_name=INTERFACE,
            mode=nixnet_types.CREATE_SESSION_MODE_SIGNAL_IN_SINGLE_POINT,
        )
    )
    check_for_error(create_session_response.status)

    session = create_session_response.session
    print("Session Created Successfully.\n")

    # Set the Key Slot
    set_property_response = client.SetProperty(
        nixnet_types.SetPropertyRequest(
            session=session,
            property_id=nixnet_types.PROPERTY_SESSION_INTF_FLEX_RAY_KEY_SLOT_ID,
            u32_scalar=keyslot_id,
        )
    )
    check_for_error(set_property_response.status)

    # If no values are being written on the FlexRay port, the signals read would contain the
    # default value of 0.0
    while i < 10:
        # Update the signal data
        read_signal_response = client.ReadSignalSinglePoint(
            nixnet_types.ReadSignalSinglePointRequest(
                session=session,
                number_of_signals=NUM_SIGNALS,
            )
        )
        check_for_error(read_signal_response.status)

        value_buffer = read_signal_response.value_buffer

        print("Signals received:")
        print(f"Signal 1: {value_buffer[0]}")
        print(f"Signal 2: {value_buffer[1]}", end="\n\n")
        i = i + 1

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
    if session:
        # clear the XNET session.
        check_for_error(client.Clear(nixnet_types.ClearRequest(session=session)).status)
        print("Session cleared successfully!\n")
