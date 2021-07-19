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
    RaiseIfError(client.CreateCOPulseChanTime(nidaqmx_types.CreateCOPulseChanTimeRequest(
        task=task,
        counter="Dev1/ctr0",
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
