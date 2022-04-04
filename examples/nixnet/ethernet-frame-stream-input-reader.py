r""" Reads all the frame on network.

  This example reads all the frames on the network and displays them. 
  This is used to demonstrate a frame input stream session.
  Ensure that you have connected the selected interface to another Ethernet interface that is 
  transmitting data.

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
  > python ethernet-frame-stream-input-reader.py <server_address> <port_number> <interface_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763"
"""

import sys
import time
from datetime import datetime

import grpc
import nixnet_pb2 as nixnet_types
import nixnet_pb2_grpc as grpc_nixnet


CHOOSE_MONITOR_OR_ENDPOINT_TEXT = (
    "\nPress 'm' followed by enter to configure the input stream session to use the monitor path"
    " to monitor all network traffic else press any other key followed by enter to use the"
    " endpoint path which filters traffic based on VLAN ID and priority. :"
)
FRAME_CHECK_SEQUENCE_SIZE = 4
MAX_ENET_FRAME_SIZE = 1518
NUM_OF_FRAMES = 1
MAX_PAYLOAD_PER_FRAME = MAX_ENET_FRAME_SIZE + FRAME_CHECK_SEQUENCE_SIZE

# Parameters
SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
INTERFACE = "ENET1"

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    INTERFACE = sys.argv[3]


def check_for_error(status):
    """Raise an exception if the status indicates an error."""
    if status != 0:
        error_message_response = client.StatusToString(
            nixnet_types.StatusToStringRequest(status_id=status)
        )
        raise Exception(error_message_response.status_description)


def print_timestamp(timestamp):
    """Print a timestamp to console."""
    local_dt = datetime.fromtimestamp(timestamp / 1e9)
    print(local_dt.strftime("%m/%d/%Y %H:%M:%S.%f")[:-3], end=" ")


# Declare all variables for the function
count = 0
session = None

# Receive filter only applies for endpoint mode.
flag = 3
vid = 2
priority = 3
mac = "AA:BB:CC:DD:EE:FF"  # MAC Address filter is not enabled. Use random string.

# Create the communication channel for the remote host and create connections to the NI-XNET and
# session services.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
client = grpc_nixnet.NiXnetStub(channel)

print(CHOOSE_MONITOR_OR_ENDPOINT_TEXT)
if sys.stdin.read(1) == "m":
    INTERFACE += "/monitor"

# Display parameters that will be used for the example.
print(f"Interface: {INTERFACE}", end="\n")

try:
    # Create an XNET session in SignalOutSinglePoint mode
    create_session_response = client.CreateSession(
        nixnet_types.CreateSessionRequest(
            database_name="",
            cluster_name="",
            list="",
            interface_name=INTERFACE,
            mode=nixnet_types.CREATE_SESSION_MODE_FRAME_IN_STREAM,
        )
    )
    check_for_error(create_session_response.status)

    session = create_session_response.session
    print("Session created successfully.\n")

    rxfilter = nixnet_types.EptRxFilter(
        use_flags=flag, vid=vid, priority=priority, destination_mac=mac
    )

    ept_rxfilter_array = nixnet_types.EptRxFilterArray(ept_rx_filter=[rxfilter])

    # Set Receive Filter (Only applies for endpoint mode)
    set_property_response = client.SetProperty(
        nixnet_types.SetPropertyRequest(
            session=session,
            property_id=nixnet_types.PROPERTY_SESSION_INTF_ENET_EPT_RECEIVE_FILTER,
            ept_rx_filter_array=ept_rxfilter_array,
        )
    )
    check_for_error(set_property_response.status)

    print("Reading all received frames.\n")
    print("Local Timestamp", "Network Timestamp", "Data")

    while count < 10:
        # Read the received frames into the buffer
        read_frame_response = client.ReadFrame(
            nixnet_types.ReadFrameRequest(
                session=session,
                number_of_frames=NUM_OF_FRAMES,
                max_payload_per_frame=MAX_PAYLOAD_PER_FRAME,
                protocol=nixnet_types.PROTOCOL_ENET,
                timeout=nixnet_types.TIME_OUT_INFINITE,
            )
        )
        check_for_error(read_frame_response.status)

        frame_buffer = read_frame_response.buffer

        for i in range(0, len(frame_buffer)):
            print_timestamp(frame_buffer[i].enet.device_timestamp)
            print_timestamp(frame_buffer[i].enet.network_timestamp)

            for j in range(0, len(frame_buffer[i].enet.frame_data)):
                # Prints frame data in 2-digit hexadecimal format without '0x'
                print(
                    "{:02x}".format(int(frame_buffer[i].enet.frame_data[j])).upper(),
                    end=" ",
                )
            print("\n\n")

        time.sleep(1)
        count = count + 1

    print("Frame capture stopped.\n")

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
