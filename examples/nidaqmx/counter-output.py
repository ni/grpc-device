r"""Generate a single digital pulse from a Counter Output Channel.

The gRPC API is built from the C API. NI-DAQmx documentation is installed with the driver at:
  C:\Program Files (x86)\National Instruments\NI-DAQ\docs\cdaqmx.chm

Getting Started:

To run this example, install "NI-DAQmx Driver" on the server machine:
  https://www.ni.com/en-us/support/downloads/drivers/download.ni-daqmx.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI DAQmx gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-DAQMX-C-Function-Reference

To run this example without hardware: create a simulated device in NI MAX on the server (Windows
only).

Running from command line:

Server machine's IP address, port number, and counter name can be passed as separate command line
arguments.
  > python counter-output.py <server_address> <port_number> <counter_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "Dev1/ctr0" as the counter name.
"""

import sys

import grpc
import nidaqmx_pb2 as nidaqmx_types
import nidaqmx_pb2_grpc as grpc_nidaqmx

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
COUNTER_NAME = "Dev1/ctr0"

if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    COUNTER_NAME = sys.argv[3]

# Create a gRPC channel + client.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
client = grpc_nidaqmx.NiDAQmxStub(channel)
task = None


def raise_if_error(response):
    """Raise an exception if an error was returned."""
    if response.status != 0:
        response = client.GetErrorString(
            nidaqmx_types.GetErrorStringRequest(error_code=response.status)
        )
        raise Exception(f"Error: {response.error_string}")


try:
    response = client.CreateTask(nidaqmx_types.CreateTaskRequest(session_name="my task"))
    raise_if_error(response)
    task = response.task

    raise_if_error(
        client.CreateCOPulseChanTime(
            nidaqmx_types.CreateCOPulseChanTimeRequest(
                task=task,
                counter=COUNTER_NAME,
                units=nidaqmx_types.DIGITAL_WIDTH_UNITS3_SECONDS,
                idle_state=nidaqmx_types.LEVEL1_LOW,
                initial_delay=1.0,
                low_time=0.5,
                high_time=1.0,
            )
        )
    )

    raise_if_error(client.StartTask(nidaqmx_types.StartTaskRequest(task=task)))

    raise_if_error(
        client.WaitUntilTaskDone(
            nidaqmx_types.WaitUntilTaskDoneRequest(task=task, time_to_wait=10.0)
        )
    )

    print(f"Output was successfully written to {COUNTER_NAME}.")
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
    if task:
        client.StopTask(nidaqmx_types.StopTaskRequest(task=task))
        client.ClearTask(nidaqmx_types.ClearTaskRequest(task=task))
