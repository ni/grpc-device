#
# This example lists out devices connected to the server machine
# by establishing communication with it over gRPC.
#
# Getting Started:
#
# To run this example, install the "NI System Configuration API" on the server machine.
# Link to the download page: https://www.ni.com/en-in/support/downloads/drivers/download.system-configuration.html
#
# Install the gRPC tools for Python:
#     > pip install grpcio-tools
#   if you are using anaconda
#     > conda install grpcio-tools
#
# Generate the python API from the gRPC definition (.proto) files:
#   > python -m grpc_tools.protoc -I../../source/protobuf --python_out=. --grpc_python_out=. session.proto
#
import grpc
import sys
import session_pb2 as session_types
import session_pb2_grpc as grpc_session

# Helper to print the devices 
def print_devices(devices) :
    if not devices:
        print("No devices are connected.")
        return
    print("\n-----------------------------------------------------------------------------------------------------\n")
    print("  List of devices connected to the server: \n")
    print("-----------------------------------------------------------------------------------------------------\n")
    for device in devices :
        print(f"    {device.name}")
        print(f"        Model: {device.model}")
        print(f"        Vendor: {device.vendor}")
        print(f"        Serial Number: {device.serial_number} \n")

# Server machine's IP address and port number have to be passed as two separate command line arguments.
#   > python enumerate-device.py <server_address> <port_number>
# If not passed as command line arguments, then by default server address would be "localhost:31763".
server_address = "localhost:31763"
if len(sys.argv) == 3 :
    server_address = f"{sys.argv[1]}:{sys.argv[2]}"

# Create communication with the server using gRPC APIs.
channel = grpc.insecure_channel(server_address)
client = grpc_session.SessionUtilitiesStub(channel)

try :
    # EnumerateDevices API gives a list of devices (simulated and physical) connected to the server machine.
    enumerate_devices_response = client.EnumerateDevices(session_types.EnumerateDevicesRequest())

    # Display devices connected to the server machine.
    print_devices(enumerate_devices_response.devices)     

# If EnumerateDevices API throws an exception, print the error message.
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE :
        error_message = f"Failed to connect to the server on {server_address}."
    print(f"{error_message}")