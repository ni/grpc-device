# Demonstrates how to acquire analog data using the grpc asyncio API and RegisterEveryNSamplesEvent.
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
# To run this example without hardware: create a simulated device in NI MAX on the server (Windows only).
#
# Running from command line:
#
# Server machine's IP address, port number, and physical channel name can be passed as separate command line arguments.
#   > python analog-input-every-n-samples.py <server_address> <port_number> <physical_channel_name>
# If they are not passed in as command line arguments, then by default the server address will be "localhost:31763", with "Dev1/ai0" as the physical channel name
import asyncio
import grpc
import sys

import nidaqmx_pb2 as nidaqmx_types
import nidaqmx_pb2_grpc as grpc_nidaqmx

server_address = "localhost"
server_port = "31763"
physical_channel = "Dev1/ai0"

if len(sys.argv) >= 2:
    server_address = sys.argv[1]
if len(sys.argv) >= 3:
    server_port = sys.argv[2]
if len(sys.argv) >= 4:
    physical_channel = sys.argv[3]


async def main():
    client = None
    task = None

    async with grpc.aio.insecure_channel(f"{server_address}:{server_port}") as channel:
        try:
            client = grpc_nidaqmx.NiDAQmxStub(channel)

            async def raise_if_error(response):
                if response.status:
                    response = await client.GetErrorString(
                        nidaqmx_types.GetErrorStringRequest(
                            error_code=response.status, buffer_size=2048))
                    error_string = response.error_string.strip(" \0")
                    raise Exception(f"Error: {error_string}")

            async def raise_if_error_async(awaitable_call):
                response = await awaitable_call
                await raise_if_error(response)
                return response

            create_response: nidaqmx_types.CreateTaskResponse = (
                await raise_if_error_async(
                    client.CreateTask(nidaqmx_types.CreateTaskRequest())))
            task = create_response.task

            await raise_if_error_async(
                client.CreateAIVoltageChan(
                    nidaqmx_types.CreateAIVoltageChanRequest(
                        task=task,
                        physical_channel=physical_channel,
                        min_val=-10.0,
                        max_val=10.0,
                        terminal_config=nidaqmx_types.InputTermCfgWithDefault.INPUT_TERM_CFG_WITH_DEFAULT_CFG_DEFAULT,
                        units=nidaqmx_types.VoltageUnits2.VOLTAGE_UNITS2_VOLTS)))

            await raise_if_error_async(
                client.CfgSampClkTiming(
                    nidaqmx_types.CfgSampClkTimingRequest(
                        task=task,
                        sample_mode=nidaqmx_types.AcquisitionType.ACQUISITION_TYPE_FINITE_SAMPS,
                        samps_per_chan=1000,
                        active_edge=nidaqmx_types.Edge1.EDGE1_RISING,
                        rate=100)))

            every_n_samples_stream = client.RegisterEveryNSamplesEvent(
                nidaqmx_types.RegisterEveryNSamplesEventRequest(
                    task=task,
                    n_samples=100,
                    every_n_samples_event_type=nidaqmx_types.EVERY_N_SAMPLES_EVENT_TYPE_ACQUIRED_INTO_BUFFER))

            done_event_stream = client.RegisterDoneEvent(nidaqmx_types.RegisterDoneEventRequest(task=task))

            await raise_if_error_async(client.StartTask(nidaqmx_types.StartTaskRequest(task=task)))

            async def read_data():
                async for every_n_samples_response in every_n_samples_stream:
                    await raise_if_error(every_n_samples_response)
                    read_response: nidaqmx_types.ReadAnalogF64Response = await raise_if_error_async(
                        client.ReadAnalogF64(
                            nidaqmx_types.ReadAnalogF64Request(
                                task=task,
                                num_samps_per_chan=100,
                                fill_mode=nidaqmx_types.GroupBy.GROUP_BY_GROUP_BY_CHANNEL,
                                array_size_in_samps=100)))

                    print("Read Data:", read_response.read_array[:10])

            async def wait_for_done():
                async for done_response in done_event_stream:
                    every_n_samples_stream.cancel()
                    done_event_stream.cancel()
                    await raise_if_error(done_response)

            await asyncio.gather(read_data(), wait_for_done())

        except grpc.RpcError as rpc_error:
            error_message = rpc_error.details()
            if rpc_error.code() == grpc.StatusCode.UNAVAILABLE:
                error_message = f"Failed to connect to server on {server_address}:{server_port}"
            elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
                error_message = "The operation is not implemented or is not supported/enabled in this service"
            print(f"{error_message}")
        finally:
            if client and task:
                await client.StopTask(nidaqmx_types.StopTaskRequest(task=task))
                await client.ClearTask(nidaqmx_types.ClearTaskRequest(task=task))


## Run main
futures = [main()]
loop = asyncio.get_event_loop()
loop.run_until_complete(asyncio.wait(futures))
