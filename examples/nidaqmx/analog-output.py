# Demonstrates how to output a single Voltage Update (Sample) to an Analog Output Channel.
#
# The gRPC API is built from the C API. NI-DAQmx documentation is installed with the driver at:
# C:\Program Files (x86)\National Instruments\NI-DAQ\docs\cdaqmx.chm
#
# Getting Started:
#
# To run this example, install "NI-DAQmx Driver" on the server machine.
# Link: https://www.ni.com/en-us/support/downloads/drivers/download.ni-daqmx.html
#
# For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC Client" wiki page.
# Link: https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client
#
# Running from command line:
#
# Server machine's IP address, port number, and physical channel name can be passed as separate command line arguments.
#   > python analog-output.py <server_address> <port_number> <physical_channel_name>
# If they are not passed in as command line arguments, then by default the server address will be "localhost:31763", with "Dev1/ao0" as the physical channel name
import grpc
import sys

import nidaqmx_pb2 as nidaqmx_types
import nidaqmx_pb2_grpc as grpc_nidaqmx

server_address = "localhost"
server_port = "31763"
physical_channel = "Dev1/ao0"

if len(sys.argv) >= 2:
    server_address = sys.argv[1]
if len(sys.argv) >= 3:
    server_port = sys.argv[2]
if len(sys.argv) >= 4:
    physical_channel = sys.argv[3]

# Create a gRPC channel + client.
channel = grpc.insecure_channel(f"{server_address}:{server_port}")
client = grpc_nidaqmx.NiDAQmxStub(channel)
task = None

# Raise an exception if an error was returned
def RaiseIfError(response):
    if response.status != 0:
        response = client.GetErrorString(nidaqmx_types.GetErrorStringRequest(
            error_code=response.status, buffer_size=2048))
        error_string = response.error_string.strip(' \0')
        raise Exception(f"Error: {error_string}")


try:
    response = client.CreateTask(
        nidaqmx_types.CreateTaskRequest(session_name="my task"))
    RaiseIfError(response)
    task = response.task

    RaiseIfError(client.CreateAOVoltageChan(nidaqmx_types.CreateAOVoltageChanRequest(
        task=task,
        physical_channel=physical_channel,
        min_val=-10.0,
        max_val=10.0,
        units=nidaqmx_types.VOLTAGE_UNITS2_VOLTS
    )))

    RaiseIfError(client.StartTask(nidaqmx_types.StartTaskRequest(task=task)))

    RaiseIfError(client.WriteAnalogF64(nidaqmx_types.WriteAnalogF64Request(
        task=task,
        num_samps_per_chan=1,
        data_layout=nidaqmx_types.GROUP_BY_GROUP_BY_CHANNEL,
        write_array=[1.0],
        timeout=10.0)))

    print(f"Output was successfully written to {physical_channel}.")
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE:
        error_message = f"Failed to connect to server on {server_address}:{server_port}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = "The operation is not implemented or is not supported/enabled in this service"
    print(f"{error_message}") 
finally:
    if task:
        client.StopTask(nidaqmx_types.StopTaskRequest(task=task))
        client.ClearTask(nidaqmx_types.ClearTaskRequest(task=task))
