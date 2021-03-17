# 
# Copyright 2020 National Instruments Corp
# Licensed under the MIT license
#
# This example initiates a session and uses the session API to exercise some common reservation operations on the session.
# This particular example is using NI-SCOPE but the session reservation API should work for any driver session.
#
# Getting Started:
#
# To run this example, install "NI-SCOPE Driver" on the server machine.
# Link : https://www.ni.com/en-us/support/downloads/drivers/download.ni-scope.html
#
# Install the gRPC tools for Python
#     > pip install grpcio-tools
#   if you are using anaconda
#     > conda install grpcio-tools
#
# Generate the python API from the gRPC definition (.proto) files
# Note: The snippets below assume you are executing from the examples/session folder in the repo directory. 
# If not, you will need to adjust the -I arguments so the compiler knows where to find the proto files.
#   > py -m grpc_tools.protoc -I="../../source/protobuf" --python_out=. --grpc_python_out=. session.proto
#   > py -m grpc_tools.protoc -I="../../generated/niscope" -I="../../source/protobuf" --python_out=. --grpc_python_out=. niscope.proto 
#
# Refer to the NI Scope Help to determine the valid channel and resource names for your Scope module.

import grpc
import sys
import time
import niscope_pb2 as niscope_types
import niscope_pb2_grpc as grpc_niscope
import session_pb2 as session_types
import session_pb2_grpc as grpc_session

any_error = False
# Checks for errors. If any, throws an exception to stop the execution.
def CheckForError (vi, status) :
    global any_error
    if(status != 0 and not any_error):
        any_error = True
        ThrowOnError (vi, status)

# Converts an error code returned by NI-Scope into a user-readable string
def ThrowOnError (vi, error_code):
    error_message_request = niscope_types.GetErrorMessageRequest(
        vi = vi,
        error_code = error_code
        )
    error_message_response = niscope_client.GetErrorMessage(error_message_request)
    raise Exception (error_message_response)

# Server machine's IP address and port number have to be passed as two separate command line arguments.
#   > python session-reservation.py localhost 31763
# If not passed as command line arguments, then by default server address would be "localhost:31763"
server_address = "localhost:31763"
if len(sys.argv) == 3 :
    server_address = f"{sys.argv[1]}:{sys.argv[2]}"

# Create the communication channel for the remote host (in this case we are connecting to a local server)
# and create connections to the niscope and session services
channel = grpc.insecure_channel(server_address)
niscope_client = grpc_niscope.NiScopeStub(channel)
session_client = grpc_session.SessionUtilitiesStub(channel)

try :
    # Resource name and options for a simulated 5164 client. Change them according to the scope model.
    resource = "PXI1Slot2"
    options = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe"
    client_1_id = "Client1"
    client_2_id = "Client2"

    # Open session to Scope module with options
    session_name = "Ni-Scope-Session-1"
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

    # Check if session is reserved by client 1
    print(f'Checking if {session_name} is reserved by {client_1_id}...')
    is_reserved_response = session_client.IsReservedByClient(session_types.IsReservedByClientRequest(
        reservation_id = session_name,
        client_id = client_1_id
        ))
    assert(not is_reserved_response.is_reserved)
    print(f'{session_name} is not reserved by {client_1_id}.\n')

    # Reserve session for client 1
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

    # Check reservation on client 2
    print(f'Checking if {session_name} is reserved by {client_2_id}...')
    is_reserved_by_client2_response = session_client.IsReservedByClient(session_types.IsReservedByClientRequest(
        reservation_id = session_name,
        client_id = client_2_id
        ))
    assert(not is_reserved_by_client2_response.is_reserved)
    print(f'{session_name} is not reserved by {client_2_id}.\n')

    # Unreserve on client 1
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

    # Reset server
    print(f'Resetting the server...')
    reset_server_response = session_client.ResetServer(session_types.ResetServerRequest())
    is_server_reset = reset_server_response.is_server_reset
    assert(is_server_reset)
    print(f'Server has been reset.\n')    

# If NiScope API or Session API throws an exception, print the error message  
except grpc.RpcError as e:
    error_message = e.details()
    print(error_message)