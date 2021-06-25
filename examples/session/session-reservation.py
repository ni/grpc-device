# 
# This example initiates a session and uses the session API to exercise some common reservation operations on the session.
# This particular example is using NI-SCOPE but the session reservation API should work for any driver session.
#
# The gRPC API is built from the C API.  NI-SCOPE documentation is installed with the driver at:
# C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niScope\Documentation\English\Digitizers.chm
#
# A version of this .chm is available online at:
# Link: https://zone.ni.com/reference/en-XX/help/370592AB-01/
#
# Getting Started:
#
# To run this example, install "NI-SCOPE Driver" on the server machine.
# Link : https://www.ni.com/en-us/support/downloads/drivers/download.ni-scope.html
#
# For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC Client" wiki page.
# Link: https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client
#
# Refer to the NI-SCOPE gRPC Wiki to determine the valid channel and resource names for your NI-SCOPE module.
# Link : https://github.com/ni/grpc-device/wiki/NI-SCOPE-C-Function-Reference
#
#
# Running from command line:
#
# Server machine's IP address, port number, and resource name can be passed as separate command line arguments.
#   > python session-reservation.py <server_address> <port_number> <resource_name>
# If they are not passed in as command line arguments, then by default the server address will be "localhost:31763", with "SimulatedScope" as the resource name

import grpc
import sys
import time
import niscope_pb2 as niscope_types
import niscope_pb2_grpc as grpc_niscope
import session_pb2 as session_types
import session_pb2_grpc as grpc_session

server_address = "localhost"
server_port = "31763"

# Resource name and options for a simulated 5164 client. Change them according to the NI-SCOPE model.
resource = "SimulatedScope"
options = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe"

client_1_id = "Client1"
client_2_id = "Client2"

any_error = False
# Checks for errors. If any, throws an exception to stop the execution.
def CheckForError (vi, status) :
    global any_error
    if(status != 0 and not any_error):
        any_error = True
        ThrowOnError (vi, status)

# Converts an error code returned by NI-SCOPE into a user-readable string.
def ThrowOnError (vi, error_code):
    error_message_request = niscope_types.GetErrorMessageRequest(
        vi = vi,
        error_code = error_code
        )
    error_message_response = niscope_client.GetErrorMessage(error_message_request)
    raise Exception (error_message_response.error_message)

# Read in cmd args
if len(sys.argv) >= 2:
    server_address = sys.argv[1]
if len(sys.argv) >= 3:
    server_port = sys.argv[2]
if len(sys.argv) >= 4:
    resource = sys.argv[3]
    options = ""

# Create the communication channel for the remote host and create connections to the NI-SCOPE and session services.
channel = grpc.insecure_channel(f"{server_address}:{server_port}")
niscope_client = grpc_niscope.NiScopeStub(channel)
session_client = grpc_session.SessionUtilitiesStub(channel)

try :
    # Reset server to start in a fresh state.
    reset_server_response = session_client.ResetServer(session_types.ResetServerRequest())
    assert(reset_server_response.is_server_reset)

    # Open session to NI-SCOPE module with options.
    session_name = "NI-Scope-Session-1"
    print('\nInitializing session...')
    init_with_options_response = niscope_client.InitWithOptions(niscope_types.InitWithOptionsRequest(
        session_name = session_name,
        resource_name = resource,
        id_query = False,
        option_string = options
        ))
    vi = init_with_options_response.vi
    CheckForError(vi, init_with_options_response.status)
    print(f'Session initialized with name {session_name} and id {vi.id}.\n')

    # Check if session is reserved by client 1.
    # Note: The reservation_id is defined by and has meaning only for the client + Session Reservation API.
    print(f'Checking if {session_name} is reserved by {client_1_id}...')
    is_reserved_response = session_client.IsReservedByClient(session_types.IsReservedByClientRequest(
        reservation_id = session_name,
        client_id = client_1_id
        ))
    assert(not is_reserved_response.is_reserved)
    print(f'{session_name} is not reserved by {client_1_id}.\n')

    # Reserve session for client 1.
    print(f'Reserving {session_name} for {client_1_id}...')
    reserve_response = session_client.Reserve(session_types.ReserveRequest(
        reservation_id = session_name,
        client_id = client_1_id
        ))
    is_reserved = reserve_response.is_reserved
    assert(is_reserved)
    is_reserved_by_client1_response = session_client.IsReservedByClient(session_types.IsReservedByClientRequest(
        reservation_id = session_name,
        client_id = client_1_id
        ))
    assert(is_reserved_by_client1_response.is_reserved)
    print(f'{session_name} is reserved by {client_1_id}.\n')

    # Check reservation on client 2.
    print(f'Checking if {session_name} is reserved by {client_2_id}...')
    is_reserved_by_client2_response = session_client.IsReservedByClient(session_types.IsReservedByClientRequest(
        reservation_id = session_name,
        client_id = client_2_id
        ))
    assert(not is_reserved_by_client2_response.is_reserved)
    print(f'{session_name} is not reserved by {client_2_id}.\n')

    # Unreserve on client 1.
    print(f'Unreserving {session_name} reserved by {client_1_id}...')
    is_unreserved_response = session_client.Unreserve(session_types.UnreserveRequest(
        reservation_id = session_name,
        client_id = client_1_id
        ))
    assert(is_unreserved_response.is_unreserved)
    is_reserved_by_client1_response = session_client.IsReservedByClient(session_types.IsReservedByClientRequest(
        reservation_id = session_name,
        client_id = client_1_id
        ))
    assert(not is_reserved_by_client1_response.is_reserved)
    print(f'{session_name} is no longer reserved by {client_1_id}.\n')

    print(f'Reserving {session_name} for {client_2_id}...')
    reserve_response = session_client.Reserve(session_types.ReserveRequest(
        reservation_id = session_name,
        client_id = client_2_id
        ))
    is_reserved = reserve_response.is_reserved
    assert(is_reserved)
    is_reserved_by_client2_response = session_client.IsReservedByClient(session_types.IsReservedByClientRequest(
        reservation_id = session_name,
        client_id = client_2_id
        ))
    assert(is_reserved_by_client2_response.is_reserved)
    print(f'{session_name} is reserved by {client_2_id}.\n')

    # Reset server.
    print(f'Resetting the server...')
    reset_server_response = session_client.ResetServer(session_types.ResetServerRequest())
    assert(reset_server_response.is_server_reset)
    is_reserved_by_client2_response = session_client.IsReservedByClient(session_types.IsReservedByClientRequest(
        reservation_id = session_name,
        client_id = client_2_id
        ))
    assert(not is_reserved_by_client2_response.is_reserved)
    print(f'All sessions have been closed and reservations have been cleared.\n')

# If NI-SCOPE API or Session API throws an exception, print the error message.
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE :
        error_message = f"Failed to connect to server on {server_address}:{server_port}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = "The operation is not implemented or is not supported/enabled in this service"
    print(f"{error_message}")