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
    RaiseIfError(client.CreateCIFreqChan(nidaqmx_types.CreateCIFreqChanRequest(
        task=task,
        counter="Dev1/ctr0",
        min_val=1.192093,
        max_val=10000000,
        units=nidaqmx_types.FREQUENCY_UNITS3_HZ,
        edge=nidaqmx_types.EDGE1_RISING,
        meas_method=nidaqmx_types.COUNTER_FREQUENCY_METHOD_LOW_FREQ_1_CTR,
        meas_time=0.001,
        divisor=4)))

    RaiseIfError(client.StartTask(nidaqmx_types.StartTaskRequest(task=task)))

    RaiseIfError(client.ReadCounterScalarF64(nidaqmx_types.ReadCounterScalarF64Request(
    )))
finally:
    client.StopTask(nidaqmx_types.StopTaskRequest(task=task))
    client.ClearTask(nidaqmx_types.ClearTaskRequest(task=task))
