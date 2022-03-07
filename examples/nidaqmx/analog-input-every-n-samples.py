r"""Acquire analog data using the grpc asyncio API and RegisterEveryNSamplesEvent.

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

Server machine's IP address, port number, and physical channel name can be passed as separate
command line arguments.
  > python analog-input-every-n-samples.py <server_address> <port_number> <physical_channel_name>
To acquire data from multiple channels, pass in a list or range of channels (i.e., Dev1/ai0:3).
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "Dev1/ai0" as the physical channel name.
"""

import asyncio
import sys

import grpc
import nidaqmx_pb2 as nidaqmx_types
import nidaqmx_pb2_grpc as grpc_nidaqmx

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
PHYSICAL_CHANNEL = "Dev1/ai0"

if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    PHYSICAL_CHANNEL = sys.argv[3]


async def _main():
    client = None
    task = None

    async with grpc.aio.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}") as channel:
        try:
            client = grpc_nidaqmx.NiDAQmxStub(channel)

            async def raise_if_error(response):
                """Raise an exception if an error was returned."""
                if response.status:
                    response = await client.GetErrorString(
                        nidaqmx_types.GetErrorStringRequest(error_code=response.status)
                    )
                    raise Exception(f"Error: {response.error_string}")

            async def raise_if_error_async(awaitable_call):
                """Await response, then raise an exception if an error was returned."""
                response = await awaitable_call
                await raise_if_error(response)
                return response

            create_response: nidaqmx_types.CreateTaskResponse = await raise_if_error_async(
                client.CreateTask(nidaqmx_types.CreateTaskRequest())
            )
            task = create_response.task

            await raise_if_error_async(
                client.CreateAIVoltageChan(
                    nidaqmx_types.CreateAIVoltageChanRequest(
                        task=task,
                        physical_channel=PHYSICAL_CHANNEL,
                        min_val=-10.0,
                        max_val=10.0,
                        terminal_config=nidaqmx_types.InputTermCfgWithDefault.INPUT_TERM_CFG_WITH_DEFAULT_CFG_DEFAULT,
                        units=nidaqmx_types.VoltageUnits2.VOLTAGE_UNITS2_VOLTS,
                    )
                )
            )

            total_samples_per_channel = 1000
            samples_per_channel_per_read = 100
            await raise_if_error_async(
                client.CfgSampClkTiming(
                    nidaqmx_types.CfgSampClkTimingRequest(
                        task=task,
                        sample_mode=nidaqmx_types.AcquisitionType.ACQUISITION_TYPE_FINITE_SAMPS,
                        samps_per_chan=total_samples_per_channel,
                        active_edge=nidaqmx_types.Edge1.EDGE1_RISING,
                        rate=100,
                    )
                )
            )

            every_n_samples_stream = client.RegisterEveryNSamplesEvent(
                nidaqmx_types.RegisterEveryNSamplesEventRequest(
                    task=task,
                    n_samples=samples_per_channel_per_read,
                    every_n_samples_event_type=nidaqmx_types.EVERY_N_SAMPLES_EVENT_TYPE_ACQUIRED_INTO_BUFFER,
                )
            )

            # Wait for initial_metadata to ensure that the callback is registered before starting
            # the task.
            await every_n_samples_stream.initial_metadata()

            done_event_stream = client.RegisterDoneEvent(
                nidaqmx_types.RegisterDoneEventRequest(task=task)
            )

            await done_event_stream.initial_metadata()

            await raise_if_error_async(client.StartTask(nidaqmx_types.StartTaskRequest(task=task)))

            response = await raise_if_error_async(
                client.GetTaskAttributeUInt32(
                    nidaqmx_types.GetTaskAttributeUInt32Request(
                        task=task, attribute=nidaqmx_types.TASK_ATTRIBUTE_NUM_CHANS
                    )
                )
            )

            number_of_channels = response.value

            async def read_data():
                samps_per_chan_read = 0

                try:
                    async for every_n_samples_response in every_n_samples_stream:
                        await raise_if_error(every_n_samples_response)
                        read_response: nidaqmx_types.ReadAnalogF64Response = (
                            await raise_if_error_async(
                                client.ReadAnalogF64(
                                    nidaqmx_types.ReadAnalogF64Request(
                                        task=task,
                                        num_samps_per_chan=samples_per_channel_per_read,
                                        fill_mode=nidaqmx_types.GroupBy.GROUP_BY_GROUP_BY_CHANNEL,
                                        array_size_in_samps=number_of_channels
                                        * samples_per_channel_per_read,
                                    )
                                )
                            )
                        )

                        print(
                            f"Acquired {len(read_response.read_array)} samples",
                            f"({read_response.samps_per_chan_read} samples per channel)",
                        )
                        print("Read Data:", read_response.read_array[:10])

                        # Unregister the event stream when all samples are read.
                        samps_per_chan_read += read_response.samps_per_chan_read
                        if samps_per_chan_read >= total_samples_per_channel:
                            every_n_samples_stream.cancel()
                except asyncio.CancelledError:
                    pass

            async def wait_for_done():
                try:
                    async for done_response in done_event_stream:
                        done_event_stream.cancel()
                        # Cancel the acquisition if there's an error, otherwise let it continue
                        # until all samples are read.
                        if done_response.status:
                            every_n_samples_stream.cancel()
                        await raise_if_error(done_response)
                except asyncio.CancelledError:
                    pass

            await asyncio.gather(read_data(), wait_for_done())

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
            if client and task:
                await client.StopTask(nidaqmx_types.StopTaskRequest(task=task))
                await client.ClearTask(nidaqmx_types.ClearTaskRequest(task=task))


## Run main
futures = [_main()]
loop = asyncio.get_event_loop()
loop.run_until_complete(asyncio.wait(futures))
