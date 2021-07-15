import grpc
import sys
import os
import nidaqmx_pb2 as nidaqmx_types
import nidaqmx_pb2_grpc as grpc_nidaqmx

server_address = "localhost"
server_port = "31763"

# Create a gRPC channel + client.
channel = grpc.insecure_channel(f"{server_address}:{server_port}")
client = grpc_nidaqmx.NiDAQmxStub(channel)

# TODO: check for error
response = client.CreateTask(
    nidaqmx_types.CreateTaskRequest(session_name="my task"))
print(response.status)
task = response.task

try:
    response = client.CreateAIVoltageChan(nidaqmx_types.CreateAIVoltageChanRequest(
        task=task,
        physical_channel="Dev1/ai0",
        name_to_assign_to_channel="ai0",
        terminal_config=nidaqmx_types.INPUT_TERM_CFG_WITH_DEFAULT_RSE,
        min_val=-10.0,
        max_val=10.0,
        units=nidaqmx_types.VOLTAGE_UNITS2_VOLTS
    ))
    print(response.status)

    # TODO: check for error
    response = client.StartTask(nidaqmx_types.StartTaskRequest(task=task))
    print(response.status)

    response = client.ReadAnalogF64(nidaqmx_types.ReadAnalogF64Request(
        task=task,
        num_samps_per_chan=1,
        array_size_in_samps=1,
        fill_mode=nidaqmx_types.GROUP_BY_GROUP_BY_CHANNEL,
        timeout=10.0))
    print(response.status)
    print(f"Data: {response.read_array[0]}")
finally:
    response = client.ClearTask(nidaqmx_types.ClearTaskRequest(task=task))
    print(response.status)
