# Demonstrates how to generate a single digital pulse from a Counter Output Channel.
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
# Server machine's IP address, port number, and counter name can be passed as separate command line arguments.
#   > python counter-output.py <server_address> <port_number> <counter_name>
# If they are not passed in as command line arguments, then by default the server address will be "localhost:31763", with "Dev1/ctr0" as the counter name
import grpc
import sys

import nidaqmx_pb2 as nidaqmx_types
import nidaqmx_pb2_grpc as grpc_nidaqmx

server_address = "localhost"
server_port = "31763"
counter_name = "Dev1/ctr0"

# Create a gRPC channel + client.
channel = grpc.insecure_channel(f"{server_address}:{server_port}")
client = grpc_nidaqmx.NiDAQmxStub(channel)

# Raise an exception if an error was returned
def RaiseIfError(response):
    if response.status != 0:
        response = client.GetErrorString(nidaqmx_types.GetErrorStringRequest(
            error_code=response.status, buffer_size=2048))
        error_string = response.error_string.strip(' \0')
        raise Exception(f"Error: {error_string}")


if len(sys.argv) >= 2:
    server_address = sys.argv[1]
if len(sys.argv) >= 3:
    server_port = sys.argv[2]
if len(sys.argv) >= 4:
    counter_name = sys.argv[3]


response = client.CreateTask(
    nidaqmx_types.CreateTaskRequest(session_name="my task"))
RaiseIfError(response)
task = response.task

try:
    RaiseIfError(client.CreateCOPulseChanTime(nidaqmx_types.CreateCOPulseChanTimeRequest(
        task=task,
        counter=counter_name,
        units=nidaqmx_types.DIGITAL_WIDTH_UNITS3_SECONDS,
        idle_state=nidaqmx_types.LEVEL1_LOW,
        initial_delay=1.0,
        low_time=0.5,
        high_time=1.0)))

    RaiseIfError(client.StartTask(nidaqmx_types.StartTaskRequest(task=task)))

    RaiseIfError(client.WaitUntilTaskDone(nidaqmx_types.WaitUntilTaskDoneRequest(
        task=task,
        time_to_wait=10.0)))
finally:
    client.StopTask(nidaqmx_types.StopTaskRequest(task=task))
    client.ClearTask(nidaqmx_types.ClearTaskRequest(task=task))
