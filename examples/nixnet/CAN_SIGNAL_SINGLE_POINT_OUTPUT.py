r""" Write Signal Data 

 This example writes a signal value when a keyboard character is pressed.
 This is used to demonstrate a signal single point output session. 
 This example uses hardcoded signal names that use the NIXNET_example database. 

The gRPC API is built from the C API. NI-XNET documentation is installed with the driver at:
  C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niXNET\Documentation\NIXNETCref.chm
Getting Started:

To run this example, install "NI-XNET Driver" on the server machine:
  https://www.ni.com/en-in/support/downloads/drivers/download.ni-xnet.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI XNET gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-XNET-C-Function-Reference

 Running from command line:

Server machine's IP address, port number, and resource name can be passed as separate command line
arguments.
  > python CAN_SIGNAL_SINGLE_POINT_OUTPUT.py <server_address> <port_number>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763"
"""

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
def display_error_andexit(status, source):
    """Display error message and exit."""
    response = client.StatusToString(
        nixnet_types.StatusToStringRequest(
            status_id = status
        ))
    print("\n\nERROR at {}!\n{}\n", source, response.status_description)
    print("\nExecution stopped.\nPress any key to quit\n")
    client.Clear(nixnet_types.ClearRequest(session_ref = session_reference))
    exit(1)

i = 0
session_reference = 0
value_buffer = [0] * NUM_SIGNALS

# Create the communication channel for the remote host and create connections to the NI-DCPower and
# session services.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
client = grpc_nixnet.NiXnetStub(channel)

# Display parameters that will be used for the example.
print("Interface: "+ INTERFACE, "Database: " + DATABASE, "Signal List: " + SIGNAL_LIST, sep="\n")

# Create an XNET session in SignalOutSinglePoint mode
CreateSession_Response = client.CreateSession(
    nixnet_types.CreateSessionRequest(
        database_name = DATABASE,
        cluster_name = CLUSTER,
        list = SIGNAL_LIST,
        interface = INTERFACE, 
        mode = nixnet_types.CREATE_SESSION_MODE_MODE_SIGNAL_OUT_SINGLE_POINT
    ))

session_reference = CreateSession_Response.session_ref

if CreateSession_Response.status == SUCCESS:
    print("Session Created Successfully.\n")
else:
    display_error_andexit(CreateSession_Response.status,"CreateSession")
    
print("\nPress any key to transmit new signal values or q to quit\n")

while not (getch.getch()).decode('UTF-8') == 'q':
    value_buffer[0] = float(i)
    value_buffer[1] = float(i*10)
    
    # Update the signal data
    response = client.WriteSignalSinglePoint(
        nixnet_types.WriteSignalSinglePointRequest(
            session_ref = session_reference,
            value_buffer = value_buffer
        ))
    
    if response.status == SUCCESS: 
        print("Signals sent:")
        print(f"Signal 1: {value_buffer[0]}")
        print(f"Signal 2: {value_buffer[1]}", end="\n\n")
        i = i+1 if i<10 else 0
    else:
        display_error_andexit(response.status,"WriteSignalSinglePoint")
            
# Clears the X-NET Session
response = client.Clear(nixnet_types.ClearRequest(session_ref = session_reference))
if response.status == SUCCESS:
    print("Session cleared successfully!\n")
else:
    display_error_andexit(response.status,"Clear")

