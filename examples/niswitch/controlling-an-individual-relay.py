r"""Control an individual relay on a module.

The gRPC API is built from the C API. NI-SWITCH documentation is installed with the driver at:
  C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niSwitch\Documentation\English\SWITCH.chm

A version of this .chm is available online at:
  https://zone.ni.com/reference/en-XX/help/375472H-01/

Getting Started:

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-SWITCH Help to determine topology, relay names, and resource names.

Refer to the NI-SWITCH gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-SWITCH-C-Function-Reference

Running from command line:

Server machine's IP address and port number can be passed as separate command line arguments.
  > python controlling-an-individual-relay.py <server_address> <port_number>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763".
To successfully run this example, the resource name, topology, and relay name must be hard coded
in this file.
"""

import sys

import grpc
import niswitch_pb2 as niswitch_types
import niswitch_pb2_grpc as grpc_niswitch

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"

# Resource name, topology string and relay name for a simulated 2529 module. Refer to NI-SWITCH help
# to find valid values for the device being used.
# If you are using real hardware device, use the appropriate resource name and set the SIMULATION
# variable to False.
RESOURCE = ""
TOPOLOGY_STRING = "2571/66-SPDT"
RELAY_NAME = "k15"
SIMULATION = True

# Set the maximimum time to wait for debounce.
MAX_DEBOUNCE_TIME = 1000
SESSION_NAME = "NI-Switch-Session-1"

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]

# Create the communcation channel for the remote host and create a connection to the NI-SWITCH
# service.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
niswitch_client = grpc_niswitch.NiSwitchStub(channel)


def check_for_error(vi, status):
    """Raise an exception if the status indicates an error."""
    if status != 0:
        error_message_response = niswitch_client.ErrorMessage(
            niswitch_types.ErrorMessageRequest(vi=vi, error_code=status)
        )
        raise Exception(error_message_response.error_message)


def check_for_initialization_error(response):
    """Raise an exception if an error was returned from Initialize."""
    if response.status < 0:
        raise RuntimeError(f"Error: {response.error_message or response.status}")
    if response.status > 0:
        sys.stderr.write(f"Warning: {response.error_message or response.status}\n")


try:
    # Open session to NI-SWITCH and set topology.
    init_with_topology_response = niswitch_client.InitWithTopology(
        niswitch_types.InitWithTopologyRequest(
            session_name=SESSION_NAME,
            resource_name=RESOURCE,
            topology=TOPOLOGY_STRING,
            simulate=SIMULATION,
            reset_device=False,
        )
    )
    vi = init_with_topology_response.vi
    check_for_initialization_error(init_with_topology_response)
    print("Topology set to : ", TOPOLOGY_STRING)

    # Close the relay. Use values that are valid for the model being used.
    check_for_error(
        vi,
        (
            niswitch_client.RelayControl(
                niswitch_types.RelayControlRequest(
                    vi=vi,
                    relay_name=RELAY_NAME,
                    relay_action=niswitch_types.RelayAction.RELAY_ACTION_NISWITCH_VAL_CLOSE_RELAY,
                )
            )
        ).status,
    )
    print("Relay closed.")

    # Wait for debounce
    check_for_error(
        vi,
        (
            niswitch_client.WaitForDebounce(
                niswitch_types.WaitForDebounceRequest(vi=vi, maximum_time_ms=MAX_DEBOUNCE_TIME)
            )
        ).status,
    )
    print("Wait for debounce to complete.")

# If NI-SWITCH API throws an exception, print the error message
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
    if "vi" in vars() and vi.id != 0:
        # close the session.
        check_for_error(vi, (niswitch_client.Close(niswitch_types.CloseRequest(vi=vi))).status)
