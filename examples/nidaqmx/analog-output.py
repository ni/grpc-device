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
    RaiseIfError(client.CreateAOVoltageChan(nidaqmx_types.CreateAOVoltageChanRequest(
        task=task,
        physical_channel="Dev1/ao0",
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
finally:
    client.StopTask(nidaqmx_types.StopTaskRequest(task=task))
    client.ClearTask(nidaqmx_types.ClearTaskRequest(task=task))
