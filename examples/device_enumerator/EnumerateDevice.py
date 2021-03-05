#
# This example lists out devices/chassis in a hierarchical manner 
# by estabilishing communication with the server over gRPC
#
# Copyright 2021 National Instruments
# Licensed under the MIT license
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
#   > python -m grpc_tools.protoc -I../../source --python_out=. --grpc_python_out=. server_utilities.proto
#
import grpc
import server_utilities_pb2 as serverType
import server_utilities_pb2_grpc as gRPCServer

# Helper to print the devices/chassis 
def printDevices() :
    print("Devices: " + "\n") 
    for it in enumerateDeviceResponse.devices :
        print(it.name + ":")
        print("   " + "Model: " + it.model)
        print("   " + "Vendor: " + it.vendor)
        print("   " + "Serial Number: " + it.serial_number +"\n")

# Create communication with the server using gRPC APIs
serverAddress = "localhost:31763"
channel = grpc.insecure_channel(serverAddress)
server = gRPCServer.ServerUtilitiesStub(channel)

# EnumerateDevices API gives a list of devices/chassis connected to the server machine.
enumerateDeviceResponse = server.EnumerateDevices(serverType.EnumerateDevicesRequest())

# Display devices/chassis connected to the server machine
print("Connecting: ")
printDevices()    