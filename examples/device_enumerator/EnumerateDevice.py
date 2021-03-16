#
# This example lists out devices connected to the server machine (in this case localhost)
# by estabilishing communication with it over gRPC
#
# Getting Started:
#
# To run this example, install "NI System Configuration API" on the server machine.
# Link : https://www.ni.com/en-in/support/downloads/drivers/download.system-configuration.html
#
# Install the gRPC tools for Python
#     > pip install grpcio-tools
#   if you are using anaconda
#     > conda install grpcio-tools
#
# Generate the python API from the gRPC definition (.proto) files
#   > python -m grpc_tools.protoc -I../../source/protobuf --python_out=. --grpc_python_out=. session.proto
#
import grpc
import session_pb2 as sessionType
import session_pb2_grpc as gRPCSession

# Helper to print the devices 
def print_devices() :
    print("Devices: \n") 
    for device in enumerate_devices_response.devices :
        print(f"{device.name}")
        print(f"    Model: {device.model}")
        print(f"    Vendor: {device.vendor}")
        print(f"    Serial Number: {device.serial_number} \n")

# Create communication with the server using gRPC APIs
server_address = "localhost:31763"
channel = grpc.insecure_channel(server_address)
server = gRPCSession.SessionUtilitiesStub(channel)

try :
    # EnumerateDevices API gives a list of devices (simulated and physical) connected to the server machine.
    enumerate_devices_response = server.EnumerateDevices(sessionType.EnumerateDevicesRequest())

    # Display devices connected to the server machine
    print_devices()     

# If EnumerateDevices API throws an exception, print the error message
except grpc.RpcError as e:
    error_message = e.details()
    print(f"{error_message}")