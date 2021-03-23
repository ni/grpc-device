# Example communication with NI-SWITCH over gRPC
#
# The gRPC API is built from the C API.  NI-SWITCH documentation is installed with the driver at:
# C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niSwitch\Documentation\English\SWITCH.chm
#
# Getting Started:
#
# For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC Client" wiki page.
# Link: https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client
#
# Run the code to initialize a session with NI-SWITCH. This example demonstrates how to control an individual relay on a module.
#
# Refer to the NI-SWITCH Help to determine topology,relay names and resource names.
#
# Running from command line:
#
# Server machine's IP address, port number, and resource name can be passed as separate command line arguments.
#   > python fetch.py <server_address> <port_number> <resource_name>
# If they are not passed in as command line arguments, then by default the server address will be "localhost:31763", with "SimulatedScope" as the resource name

import grpc
import sys
import time
import niswitch_pb2 as niswitch_types
import niswitch_pb2_grpc as grpc_niswitch

# Server machine's IP address and port number have to be passed as two separate command line arguments.
#   > python controlling-an-individual-relay.py 10.20.30.40 31763
# If not passed as command line arguments, then by default server address would be "localhost:31763"
server_address = "localhost:31763"
if len(sys.argv) == 3 :
    server_address = f"{sys.argv[1]}:{sys.argv[2]}"
session_name = "NI-Switch-Session-1"

# Resource name, topology string and relay name for a simulated 2529 module. Refer to NI-SWITCH help to find valid values for the device being used.
# If you are using real hardware device, use the appropriate resource name and set the simulation parameter to false.
# Set the maximimum time to wait for debounce.
resource = ""
topology_string = "2571/66-SPDT"
relay_name = "k15"
simulation = True
max_time = 1000

# Create the communcation channel for the remote host and create a connection to the NI-SWITCH service
channel = grpc.insecure_channel(server_address)
niswitch_client = grpc_niswitch.NiSwitchStub(channel)
anyError = False

# Checks for errors. If any, throws an exception to stop the execution.
def CheckForError (vi, status) :
    global anyError
    if(status != 0 and not anyError):
        anyError = True
        ThrowOnError (vi, status)

# Converts an error code returned by NI-SWITCH into a user-readable string
def ThrowOnError (vi, errorCode):
    error_message_request = niswitch_types.ErrorMessageRequest(
        vi=vi,
        error_code = errorCode
        )
    error_message_response = niswitch_client.ErrorMessage(error_message_request)
    raise Exception (error_message_response.error_message)
try :
    # Open session to NI-SWITCH and set topology.
    init_with_topology_response = niswitch_client.InitWithTopology(niswitch_types.InitWithTopologyRequest(
        session_name=session_name,
        resource_name=resource,
        topology = topology_string,
        simulate=simulation,
        reset_device=False
        ))
    vi = init_with_topology_response.vi
    CheckForError(vi,init_with_topology_response.status)
    print("Topology set to : ",topology_string)

    # Close the relay. Use values that are valid for the model being used.
    CheckForError(vi, (niswitch_client.RelayControl(niswitch_types.RelayControlRequest(
        vi=vi,
        relay_name = relay_name,
        relay_action = niswitch_types.RelayAction.RELAY_ACTION_NISWITCH_VAL_CLOSE_RELAY
        ))).status)   
    print("Relay closed.")

    #Wait for debounce
    CheckForError(vi, (niswitch_client.WaitForDebounce(niswitch_types.WaitForDebounceRequest(
        vi=vi,
        maximum_time_ms = max_time
        ))).status)
    print("Wait for debounce to complete.")

    # Close NI-SWITCH session.
    CheckForError(vi, (niswitch_client.Close(niswitch_types.CloseRequest(
        vi = vi
        ))).status)

# If NI-SWITCH API throws an exception, print the error message  
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE :
        error_message = f"Failed to connect to server on {server_address}"
    print(f"{error_message}") 