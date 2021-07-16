import grpc
import nidaqmx_pb2 as nidaqmx_types
import nidaqmx_pb2_grpc as grpc_nidaqmx

server_address = "localhost"
server_port = "31763"

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


response = client.CreateTask(
    nidaqmx_types.CreateTaskRequest(session_name="my task"))
RaiseIfError(response)
task = response.task

try:
    RaiseIfError(client.CreateAIVoltageChan(nidaqmx_types.CreateAIVoltageChanRequest(
        task=task,
        physical_channel="Dev1/ai0",
        terminal_config=nidaqmx_types.INPUT_TERM_CFG_WITH_DEFAULT_CFG_DEFAULT,
        min_val=-10.0,
        max_val=10.0,
        units=nidaqmx_types.VOLTAGE_UNITS2_VOLTS
    )))
    # TODO - configure sample timing

    RaiseIfError(client.StartTask(nidaqmx_types.StartTaskRequest(task=task)))

    response = client.ReadAnalogF64(nidaqmx_types.ReadAnalogF64Request(
        task=task,
        num_samps_per_chan=1000,
        array_size_in_samps=1000,
        fill_mode=nidaqmx_types.GROUP_BY_GROUP_BY_CHANNEL,
        timeout=10.0))
    RaiseIfError(response)
    print(f"Acquired {response.samps_per_chan_read} samples")
finally:
    client.StopTask(nidaqmx_types.StopTaskRequest(task=task))
    client.ClearTask(nidaqmx_types.ClearTaskRequest(task=task))
