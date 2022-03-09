r"""Initiate a session and exercise some common reservation operations on the session.

This particular example is using NI-SCOPE but the session reservation API should work for any driver
session.

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
  > python session-reservation.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedScope" as the resource name.
"""

import sys

import grpc
import niscope_pb2 as niscope_types
import niscope_pb2_grpc as grpc_niscope
import session_pb2 as session_types
import session_pb2_grpc as grpc_session

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"

# Resource name and options for a simulated 5164 client. Change them according to the NI-SCOPE
# model.
RESOURCE = "SimulatedScope"
OPTIONS = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe"

CLIENT_1_ID = "Client1"
CLIENT_2_ID = "Client2"

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    RESOURCE = sys.argv[3]
    OPTIONS = ""

# Create the communication channel for the remote host and create connections to the NI-SCOPE and
# session services.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
niscope_client = grpc_niscope.NiScopeStub(channel)
session_client = grpc_session.SessionUtilitiesStub(channel)


def check_for_error(vi, status):
    """Raise an exception if the status indicates an error."""
    if status != 0:
        error_message_response = niscope_client.ErrorMessage(
            niscope_types.ErrorMessageRequest(vi=vi, error_code=status)
        )
        raise Exception(error_message_response.error_message)


try:
    # Reset server to start in a fresh state.
    reset_server_response = session_client.ResetServer(session_types.ResetServerRequest())
    assert reset_server_response.is_server_reset

    # Open session to NI-SCOPE module with options.
    session_name = "NI-Scope-Session-1"
    print("\nInitializing session...")
    init_with_options_response = niscope_client.InitWithOptions(
        niscope_types.InitWithOptionsRequest(
            session_name=session_name, resource_name=RESOURCE, id_query=False, option_string=OPTIONS
        )
    )
    vi = init_with_options_response.vi
    check_for_error(vi, init_with_options_response.status)
    print(f"Session initialized with name {session_name} and id {vi.id}.\n")

    # Check if session is reserved by client 1.
    # Note: The reservation_id is defined by and has meaning only for the client + Session
    # Reservation API.
    print(f"Checking if {session_name} is reserved by {CLIENT_1_ID}...")
    is_reserved_response = session_client.IsReservedByClient(
        session_types.IsReservedByClientRequest(reservation_id=session_name, client_id=CLIENT_1_ID)
    )
    assert not is_reserved_response.is_reserved
    print(f"{session_name} is not reserved by {CLIENT_1_ID}.\n")

    # Reserve session for client 1.
    print(f"Reserving {session_name} for {CLIENT_1_ID}...")
    reserve_response = session_client.Reserve(
        session_types.ReserveRequest(reservation_id=session_name, client_id=CLIENT_1_ID)
    )
    is_reserved = reserve_response.is_reserved
    assert is_reserved
    is_reserved_by_client1_response = session_client.IsReservedByClient(
        session_types.IsReservedByClientRequest(reservation_id=session_name, client_id=CLIENT_1_ID)
    )
    assert is_reserved_by_client1_response.is_reserved
    print(f"{session_name} is reserved by {CLIENT_1_ID}.\n")

    # Check reservation on client 2.
    print(f"Checking if {session_name} is reserved by {CLIENT_2_ID}...")
    is_reserved_by_client2_response = session_client.IsReservedByClient(
        session_types.IsReservedByClientRequest(reservation_id=session_name, client_id=CLIENT_2_ID)
    )
    assert not is_reserved_by_client2_response.is_reserved
    print(f"{session_name} is not reserved by {CLIENT_2_ID}.\n")

    # Unreserve on client 1.
    print(f"Unreserving {session_name} reserved by {CLIENT_1_ID}...")
    is_unreserved_response = session_client.Unreserve(
        session_types.UnreserveRequest(reservation_id=session_name, client_id=CLIENT_1_ID)
    )
    assert is_unreserved_response.is_unreserved
    is_reserved_by_client1_response = session_client.IsReservedByClient(
        session_types.IsReservedByClientRequest(reservation_id=session_name, client_id=CLIENT_1_ID)
    )
    assert not is_reserved_by_client1_response.is_reserved
    print(f"{session_name} is no longer reserved by {CLIENT_1_ID}.\n")

    print(f"Reserving {session_name} for {CLIENT_2_ID}...")
    reserve_response = session_client.Reserve(
        session_types.ReserveRequest(reservation_id=session_name, client_id=CLIENT_2_ID)
    )
    is_reserved = reserve_response.is_reserved
    assert is_reserved
    is_reserved_by_client2_response = session_client.IsReservedByClient(
        session_types.IsReservedByClientRequest(reservation_id=session_name, client_id=CLIENT_2_ID)
    )
    assert is_reserved_by_client2_response.is_reserved
    print(f"{session_name} is reserved by {CLIENT_2_ID}.\n")

    # Reset server.
    print(f"Resetting the server...")
    reset_server_response = session_client.ResetServer(session_types.ResetServerRequest())
    assert reset_server_response.is_server_reset
    is_reserved_by_client2_response = session_client.IsReservedByClient(
        session_types.IsReservedByClientRequest(reservation_id=session_name, client_id=CLIENT_2_ID)
    )
    assert not is_reserved_by_client2_response.is_reserved
    print(f"All sessions have been closed and reservations have been cleared.\n")

# If NI-SCOPE API or Session API throws an exception, print the error message.
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE:
        error_message = f"Failed to connect to server on {SERVER_ADDRESS}:{SERVER_PORT}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = (
            "The operation is not implemented or is not supported/enabled in this service"
        )
    print(f"{error_message}")
