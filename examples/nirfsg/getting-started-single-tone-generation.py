# This program demonstrates the use of NI-RFSG to generate a single tone CW at a specified frequency and power.             *
# The niRFSG_Abort function is used to quickly change from one configuration to another.                                      *
#
# The gRPC API is built from the C API. NI-RFSG documentation is installed with the driver at:
# C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niRFSG\documentation\English\RFSG.chm
#
# Getting Started:
#
# To run this example, install "NI-RFSG Driver" on the server machine.
# Link: https://www.ni.com/en-us/support/downloads/drivers/download.ni-rfsg.html
#
# For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC Client" wiki page.
# Link: https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client
#
# Refer to the NI-RFSG gRPC Wiki for the latest C Function Reference:
# Link: https://github.com/ni/grpc-device/wiki/NI-DAQMX-C-Function-Reference
#
# Running from command line:
#
# Server machine's IP address, port number, and physical channel name can be passed as separate command line arguments.
#   > python getting-started-single-tone-generation.py <server_address> <port_number> <physical_channel_name>
# If they are not passed in as command line arguments, then by default the server address will be "localhost:31763", with "SimulatedRFSG" as the physical channel name
import grpc
import sys
import time

import nirfsg_pb2 as nirfsg_types
import nirfsg_pb2_grpc as grpc_nirfsg

server_address = "localhost"
server_port = "31763"
session_name = "NI-RFSG-Session"

# Resource name, channel name and options for a simulated 5652 client.
resource = "SimulatedRFSG"
options = "Simulate=1,DriverSetup=Model:5652"
# TODO - needed?
channels = "0"

# Parameters
# TODO - any of these needed?
record_length = 10
buffer_multiplier = 10
voltage_level = 5.0

# Read in cmd args
if len(sys.argv) >= 2:
    server_address = sys.argv[1]
if len(sys.argv) >= 3:
    server_port = sys.argv[2]
if len(sys.argv) >= 4:
    resource = sys.argv[3]
    options = ""

# Create a gRPC channel + client.
channel = grpc.insecure_channel(f"{server_address}:{server_port}")
client = grpc_nirfsg.NiRFSGStub(channel)
vi = None


# Raise an exception if an error was returned
def RaiseIfError(response):
    if response.status != 0:
        response = client.ErrorMessage(
            nirfsg_types.ErrorMessageRequest(error_code=response.status))
        raise Exception(f"Error: {response.error_string}")


try:
    response = client.InitWithOptions(
        nirfsg_types.InitWithOptionsRequest(
            session_name=session_name, resource_name=resource, option_string=options)
    )
    RaiseIfError(response)
    vi = response.vi
    RaiseIfError(client.ConfigureRF(
        nirfsg_types.ConfigureRFRequest(vi=vi, frequency=1e9, power_level=-5)
    ))
    print("Generating tone...")
    RaiseIfError(client.Initiate(nirfsg_types.InitiateRequest(vi=vi)))
    # Wait for two seconds and change frequency
    time.sleep(2)
    print("Changing frequency")
    RaiseIfError(client.ConfigureRF(
        nirfsg_types.ConfigureRFRequest(vi=vi, frequency=1.5e9, power_level=-5)
    ))
    print("Generating tone...")
    time.sleep(2)
finally:
    if vi:
        client.Close(nirfsg_types.CloseRequest(vi=vi))
