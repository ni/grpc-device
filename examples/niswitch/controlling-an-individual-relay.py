# This example demonstrates how to control an individual relay on a module.
#
# The gRPC API is built from the C API.  NI-SWITCH documentation is installed with the driver at:
# C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niSwitch\Documentation\English\SWITCH.chm
#
# A version of this .chm is available online at:
# Link: https://zone.ni.com/reference/en-XX/help/375472H-01/
#
# Getting Started:
#
# For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC Client" wiki page.
# Link: https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client
#
# Refer to the NI-SWITCH Help to determine topology, relay names, and resource names.
#
# Refer to the NI-SWITCH gRPC Wiki for the latest C Function Reference:
# Link: https://github.com/ni/grpc-device/wiki/NI-SWITCH-C-Function-Reference
#
# Running from command line:
#
# Server machine's IP address and port number can be passed as separate command line arguments.
#   > python controlling-an-individual-relay.py <server_address> <port_number>
# If they are not passed in as command line arguments, then by default the server address will be "localhost:31763", with
# To successfully run this example, the resource name, topology, and relay name must be hard coded in this file

import grpc
import sys
import time
import niswitch_pb2 as niswitch_types
import niswitch_pb2_grpc as grpc_niswitch

server_address = "localhost"
server_port = "31763"

# Resource name, topology string and relay name for a simulated 2529 module. Refer to NI-SWITCH help to find valid values for the device being used.
# If you are using real hardware device, use the appropriate resource name and set the simulation parameter to false.
resource = ""
topology_string = "2571/66-SPDT"
relay_name = "k15"
simulation = True

# Set the maximimum time to wait for debounce.
max_time = 1000
session_name = "NI-Switch-Session-1"

# Read in cmd args
if len(sys.argv) >= 2:
    server_address = sys.argv[1]
if len(sys.argv) >= 3:
    server_port = sys.argv[2]

# Create the communcation channel for the remote host and create a connection to the NI-SWITCH service
channel = grpc.insecure_channel(f"{server_address}:{server_port}")
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

# If NI-SWITCH API throws an exception, print the error message  
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE :
        error_message = f"Failed to connect to server on {server_address}:{server_port}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = "The operation is not implemented or is not supported/enabled in this service"
    print(f"{error_message}")

finally:
    if('vi' in vars() and vi.id != 0):
        # close the session.
        CheckForError(vi, (niswitch_client.Close(niswitch_types.CloseRequest(
            vi = vi
        ))).status)