r"""Configure a total of four tasks on two PXI Dynamic Signal Acquistion (DSA) devices.

Each device runs a task for analog input and another for analog output. This example illustrates
continuous analog input and output operations.

Instructions for Running:
  1. Select which type of Synchronization method you want to use.
  2. Select the physical channel corresponding to the input signal on the DAQ device.
  3. Enter the minimum and maximum expected voltage for the input and output operations on each
     device.
     Note: For optimal accuracy, match the input range to the expected voltage level of the
           measured signal (for input) and generated signal (for output).
  4. Set the number of samples to acquire per channel. This parameter determines how many points
     will be read and generated with each iteration.
  5. Set the rate of the acquisition and generation. The same sampling rate is employed for input
     and output operations on each device.
  Note: The sampling rate should be at least 2.2 times the maximum frequency component of the
        signal being acquired on analog input and the signal being generated on analog output.
        Frequency components beyond about 0.47 times the sampling rate will be eliminated by the
        alias and imaging protection on the DSA device.

Steps:
  1. Create a task.
  2. Create an analog input and output channel for both the leader and follower devices.
  3. Set timing parameters for a continuous acquisition. The sample rate and block size are set to
     the same values for each device.
  4. There are two types of synchronization available on DSA devices. The first method shares the
     Sample Clock Timebase across the PXI_Star bus. It also uses the Sync Pulse which is shared
     across the PXI_Trig / RTSI bus. The second method uses the Sync Pulse in conjunction with the
     PXI Reference clock 10 on the PXI backplane.
  5. Call the Get Terminal Name with Device Prefix utility function. This will take a Task and a
     terminal and create a properly formatted device + terminal name. This signal is then used as an
     output generation trigger on the leader as well as and acquisition start trigger and generation
     start trigger on the follower. The signal is shared along the PXI_Trig / RTSI bus.
  6. Synthesize a standard sine waveform and load this data into the output RAM buffer for each
     device.
  7. Call the Start function to start the acquisition.
  8. Read all of the data continuously. The 'Samples per Channel' control will specify how many
     samples per channel are read each time. If either device reports an error or the user presses
     Enter, the acquisition will stop.
  9. Call the Clear Task function to clear the task.
  10. Display an error if any.

I/O Connections Overview:
  Make sure your signal input and output terminals matches the Physical Channel I/O controls.

  It is important to ensure that your PXI chassis has been properly configured in MAX. If your
  chassis has not been configured in software before running the example, your devices may fail to
  synchronize properly.


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

This example requires physical hardware.

Running from command line:

Server machine's IP address, port number, leader_device, and follower_device can be passed as
separate command line arguments.
  > python dsa-shared-timebase-and-trig-analog-input-and-output.py <server_address> <port_number> <leader_device> <follower_device>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "Dev1" as the leader device and "Dev2" as the follower device.
"""  # noqa: W505

import asyncio
import math
import sys

import grpc
import nidaqmx_pb2 as nidaqmx_types
import nidaqmx_pb2_grpc as grpc_nidaqmx

# False = sample clock, True = reference clock
SYNCHRONIZATION_TYPE_IS_REFERENCE_CLOCK = False
SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
LEADER_DEVICE = "Dev1"
FOLLOWER_DEVICE = "Dev2"
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    LEADER_DEVICE = sys.argv[3]
if len(sys.argv) >= 5:
    FOLLOWER_DEVICE = sys.argv[4]

LEADER_INPUT_CHANNEL = f"{LEADER_DEVICE}/ai0"
LEADER_OUTPUT_CHANNEL = f"{LEADER_DEVICE}/ao0"
FOLLOWER_INPUT_CHANNEL = f"{FOLLOWER_DEVICE}/ai0"
FOLLOWER_OUTPUT_CHANNEL = f"{FOLLOWER_DEVICE}/ao0"

client = None
leader_input_task = None
leader_output_task = None
follower_input_task = None
follower_output_task = None


async def _main():
    global client, leader_input_task, leader_output_task, follower_input_task, follower_output_task
    num_leader_samples_written = 0
    num_follower_samples_written = 0
    async with grpc.aio.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}") as channel:
        try:
            client = grpc_nidaqmx.NiDAQmxStub(channel)

            async def get_terminal_name_with_dev_prefix(task, terminal_name):
                num_devices_response = await raise_if_error_async(
                    client.GetTaskAttributeUInt32(
                        nidaqmx_types.GetTaskAttributeUInt32Request(
                            task=task, attribute=nidaqmx_types.TASK_ATTRIBUTE_NUM_DEVICES
                        )
                    )
                )
                num_devices = num_devices_response.value
                for i in range(num_devices):
                    # devices are 1-indexed, so use i + 1 here
                    device = (
                        await raise_if_error_async(
                            client.GetNthTaskDevice(
                                nidaqmx_types.GetNthTaskDeviceRequest(task=task, index=i + 1)
                            )
                        )
                    ).buffer
                    device_category = (
                        await raise_if_error_async(
                            client.GetDeviceAttributeInt32(
                                nidaqmx_types.GetDeviceAttributeInt32Request(
                                    device_name=device,
                                    attribute=nidaqmx_types.DEVICE_ATTRIBUTE_PRODUCT_CATEGORY,
                                )
                            )
                        )
                    ).value
                    if (
                        device_category
                        != nidaqmx_types.DEVICE_INT32_PRODUCT_CATEGORY_C_SERIES_MODULE
                        and device_category
                        != nidaqmx_types.DEVICE_INT32_PRODUCT_CATEGORY_SCXI_MODULE
                    ):
                        return "/" + device + "/" + terminal_name
                raise Exception("Unable to get terminal name for timebase!")

            def generate_sinewave(elements, amplitude, frequency, phase):
                sinewave = [
                    amplitude * math.sin(math.pi / 180.0 * (phase + 360.0 * frequency * i))
                    for i in range(elements)
                ]
                new_phase = (phase + frequency * 360.0 * elements) % 360.0
                return (sinewave, new_phase)

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

            # DAQmx Configure Tasks code
            response: nidaqmx_types.CreateTaskResponse = await raise_if_error_async(
                client.CreateTask(nidaqmx_types.CreateTaskRequest(session_name="Leader input task"))
            )
            leader_input_task = response.task
            await raise_if_error_async(
                client.CreateAIVoltageChan(
                    nidaqmx_types.CreateAIVoltageChanRequest(
                        task=leader_input_task,
                        physical_channel=LEADER_INPUT_CHANNEL,
                        min_val=-10.0,
                        max_val=10.0,
                        units=nidaqmx_types.VOLTAGE_UNITS2_VOLTS,
                        terminal_config=nidaqmx_types.INPUT_TERM_CFG_WITH_DEFAULT_CFG_DEFAULT,
                    )
                )
            )
            await raise_if_error_async(
                client.CfgSampClkTiming(
                    nidaqmx_types.CfgSampClkTimingRequest(
                        task=leader_input_task,
                        rate=10000,
                        active_edge=nidaqmx_types.EDGE1_RISING,
                        sample_mode=nidaqmx_types.ACQUISITION_TYPE_CONT_SAMPS,
                        samps_per_chan=1000,
                    )
                )
            )

            response = await raise_if_error_async(
                client.CreateTask(
                    nidaqmx_types.CreateTaskRequest(session_name="Leader output task")
                )
            )
            leader_output_task = response.task
            await raise_if_error_async(
                client.CreateAOVoltageChan(
                    nidaqmx_types.CreateAOVoltageChanRequest(
                        task=leader_output_task,
                        physical_channel=LEADER_OUTPUT_CHANNEL,
                        min_val=-10.0,
                        max_val=10.0,
                        units=nidaqmx_types.VOLTAGE_UNITS2_VOLTS,
                    )
                )
            )
            await raise_if_error_async(
                client.CfgSampClkTiming(
                    nidaqmx_types.CfgSampClkTimingRequest(
                        task=leader_output_task,
                        rate=10000,
                        active_edge=nidaqmx_types.EDGE1_RISING,
                        sample_mode=nidaqmx_types.ACQUISITION_TYPE_CONT_SAMPS,
                        samps_per_chan=1000,
                    )
                )
            )

            response = await raise_if_error_async(
                client.CreateTask(
                    nidaqmx_types.CreateTaskRequest(session_name="Follower input task")
                )
            )
            follower_input_task = response.task
            await raise_if_error_async(
                client.CreateAIVoltageChan(
                    nidaqmx_types.CreateAIVoltageChanRequest(
                        task=follower_input_task,
                        physical_channel=FOLLOWER_INPUT_CHANNEL,
                        min_val=-10.0,
                        max_val=10.0,
                        units=nidaqmx_types.VOLTAGE_UNITS2_VOLTS,
                        terminal_config=nidaqmx_types.INPUT_TERM_CFG_WITH_DEFAULT_CFG_DEFAULT,
                    )
                )
            )
            await raise_if_error_async(
                client.CfgSampClkTiming(
                    nidaqmx_types.CfgSampClkTimingRequest(
                        task=follower_input_task,
                        rate=10000,
                        active_edge=nidaqmx_types.EDGE1_RISING,
                        sample_mode=nidaqmx_types.ACQUISITION_TYPE_CONT_SAMPS,
                        samps_per_chan=1000,
                    )
                )
            )

            response = await raise_if_error_async(
                client.CreateTask(
                    nidaqmx_types.CreateTaskRequest(session_name="Follower output task")
                )
            )
            follower_output_task = response.task
            await raise_if_error_async(
                client.CreateAOVoltageChan(
                    nidaqmx_types.CreateAOVoltageChanRequest(
                        task=follower_output_task,
                        physical_channel=FOLLOWER_OUTPUT_CHANNEL,
                        min_val=-10.0,
                        max_val=10.0,
                        units=nidaqmx_types.VOLTAGE_UNITS2_VOLTS,
                    )
                )
            )
            await raise_if_error_async(
                client.CfgSampClkTiming(
                    nidaqmx_types.CfgSampClkTimingRequest(
                        task=follower_output_task,
                        rate=10000,
                        active_edge=nidaqmx_types.EDGE1_RISING,
                        sample_mode=nidaqmx_types.ACQUISITION_TYPE_CONT_SAMPS,
                        samps_per_chan=1000,
                    )
                )
            )

            # DAQmx Clock Synchronization code
            if SYNCHRONIZATION_TYPE_IS_REFERENCE_CLOCK:
                # Note: Not all DSA devices support reference clock synchronization. Refer to
                # your hardware device manual for further information on whether this method
                # of synchronization is supported for your particular device.
                await raise_if_error_async(
                    client.SetTimingAttributeString(
                        nidaqmx_types.SetTimingAttributeStringRequest(
                            task=leader_input_task,
                            attribute=nidaqmx_types.TimingStringAttribute.TIMING_ATTRIBUTE_REF_CLK_SRC,
                            value="PXI_Clk10",
                        )
                    )
                )
                await raise_if_error_async(
                    client.SetTimingAttributeString(
                        nidaqmx_types.SetTimingAttributeStringRequest(
                            task=leader_output_task,
                            attribute=nidaqmx_types.TimingStringAttribute.TIMING_ATTRIBUTE_REF_CLK_SRC,
                            value="PXI_Clk10",
                        )
                    )
                )
                await raise_if_error_async(
                    client.SetTimingAttributeString(
                        nidaqmx_types.SetTimingAttributeStringRequest(
                            task=follower_input_task,
                            attribute=nidaqmx_types.TimingStringAttribute.TIMING_ATTRIBUTE_REF_CLK_SRC,
                            value="PXI_Clk10",
                        )
                    )
                )
                await raise_if_error_async(
                    client.SetTimingAttributeString(
                        nidaqmx_types.SetTimingAttributeStringRequest(
                            task=follower_output_task,
                            attribute=nidaqmx_types.TimingStringAttribute.TIMING_ATTRIBUTE_REF_CLK_SRC,
                            value="PXI_Clk10",
                        )
                    )
                )
            else:
                # Sample clock
                # Note: If you are using PXI DSA devices, the leader device must be in PXI Slot 2.
                timebase_source = await get_terminal_name_with_dev_prefix(
                    task=leader_input_task, terminal_name="SampleClockTimebase"
                )
                await raise_if_error_async(
                    client.SetTimingAttributeString(
                        nidaqmx_types.SetTimingAttributeStringRequest(
                            task=leader_output_task,
                            attribute=nidaqmx_types.TimingStringAttribute.TIMING_ATTRIBUTE_SAMP_CLK_TIMEBASE_SRC,
                            value=timebase_source,
                        )
                    )
                )
                await raise_if_error_async(
                    client.SetTimingAttributeString(
                        nidaqmx_types.SetTimingAttributeStringRequest(
                            task=follower_input_task,
                            attribute=nidaqmx_types.TimingStringAttribute.TIMING_ATTRIBUTE_SAMP_CLK_TIMEBASE_SRC,
                            value=timebase_source,
                        )
                    )
                )
                await raise_if_error_async(
                    client.SetTimingAttributeString(
                        nidaqmx_types.SetTimingAttributeStringRequest(
                            task=follower_output_task,
                            attribute=nidaqmx_types.TimingStringAttribute.TIMING_ATTRIBUTE_SAMP_CLK_TIMEBASE_SRC,
                            value=timebase_source,
                        )
                    )
                )

            sync_pulse_source = await get_terminal_name_with_dev_prefix(
                task=leader_input_task, terminal_name="SyncPulse"
            )
            await raise_if_error_async(
                client.SetTimingAttributeString(
                    nidaqmx_types.SetTimingAttributeStringRequest(
                        task=leader_output_task,
                        attribute=nidaqmx_types.TimingStringAttribute.TIMING_ATTRIBUTE_SYNC_PULSE_SRC,
                        value=sync_pulse_source,
                    )
                )
            )
            await raise_if_error_async(
                client.SetTimingAttributeString(
                    nidaqmx_types.SetTimingAttributeStringRequest(
                        task=follower_input_task,
                        attribute=nidaqmx_types.TimingStringAttribute.TIMING_ATTRIBUTE_SYNC_PULSE_SRC,
                        value=sync_pulse_source,
                    )
                )
            )
            await raise_if_error_async(
                client.SetTimingAttributeString(
                    nidaqmx_types.SetTimingAttributeStringRequest(
                        task=follower_output_task,
                        attribute=nidaqmx_types.TimingStringAttribute.TIMING_ATTRIBUTE_SYNC_PULSE_SRC,
                        value=sync_pulse_source,
                    )
                )
            )

            # DAQmx Configure Start Trigger code
            start_trigger = await get_terminal_name_with_dev_prefix(
                task=leader_input_task, terminal_name="ai/StartTrigger"
            )
            await raise_if_error_async(
                client.CfgDigEdgeStartTrig(
                    nidaqmx_types.CfgDigEdgeStartTrigRequest(
                        task=leader_output_task,
                        trigger_source=start_trigger,
                        trigger_edge=nidaqmx_types.EDGE1_RISING,
                    )
                )
            )
            await raise_if_error_async(
                client.CfgDigEdgeStartTrig(
                    nidaqmx_types.CfgDigEdgeStartTrigRequest(
                        task=follower_input_task,
                        trigger_source=start_trigger,
                        trigger_edge=nidaqmx_types.EDGE1_RISING,
                    )
                )
            )
            await raise_if_error_async(
                client.CfgDigEdgeStartTrig(
                    nidaqmx_types.CfgDigEdgeStartTrigRequest(
                        task=follower_output_task,
                        trigger_source=start_trigger,
                        trigger_edge=nidaqmx_types.EDGE1_RISING,
                    )
                )
            )

            (leader_write_data, phase) = generate_sinewave(250, 1.0, 0.02, 0.0)
            (follower_write_data, phase) = generate_sinewave(250, 1.0, 0.02, phase)

            # DAQmx Write code
            num_leader_samples_written = (
                await raise_if_error_async(
                    client.WriteAnalogF64(
                        nidaqmx_types.WriteAnalogF64Request(
                            task=leader_output_task,
                            num_samps_per_chan=250,
                            auto_start=False,
                            timeout=10.0,
                            data_layout=nidaqmx_types.GROUP_BY_GROUP_BY_CHANNEL,
                            write_array=leader_write_data,
                        )
                    )
                )
            ).samps_per_chan_written
            num_follower_samples_written = (
                await raise_if_error_async(
                    client.WriteAnalogF64(
                        nidaqmx_types.WriteAnalogF64Request(
                            task=follower_output_task,
                            num_samps_per_chan=250,
                            auto_start=False,
                            timeout=10.0,
                            data_layout=nidaqmx_types.GROUP_BY_GROUP_BY_CHANNEL,
                            write_array=follower_write_data,
                        )
                    )
                )
            ).samps_per_chan_written

            every_n_samples_stream = client.RegisterEveryNSamplesEvent(
                nidaqmx_types.RegisterEveryNSamplesEventRequest(
                    task=leader_input_task,
                    n_samples=100,
                    every_n_samples_event_type=nidaqmx_types.EVERY_N_SAMPLES_EVENT_TYPE_ACQUIRED_INTO_BUFFER,
                )
            )

            # Wait for initial_metadata to ensure that the callback is registered before starting
            # the task.
            await every_n_samples_stream.initial_metadata()

            done_event_stream_list = []
            done_event_stream_list.append(
                client.RegisterDoneEvent(
                    nidaqmx_types.RegisterDoneEventRequest(task=leader_input_task)
                )
            )
            done_event_stream_list.append(
                client.RegisterDoneEvent(
                    nidaqmx_types.RegisterDoneEventRequest(task=leader_output_task)
                )
            )
            done_event_stream_list.append(
                client.RegisterDoneEvent(
                    nidaqmx_types.RegisterDoneEventRequest(task=follower_input_task)
                )
            )
            done_event_stream_list.append(
                client.RegisterDoneEvent(
                    nidaqmx_types.RegisterDoneEventRequest(task=follower_output_task)
                )
            )
            for done_event_stream in done_event_stream_list:
                await done_event_stream.initial_metadata()

            # DAQmx Start code
            await raise_if_error_async(
                client.StartTask(nidaqmx_types.StartTaskRequest(task=leader_output_task))
            )
            await raise_if_error_async(
                client.StartTask(nidaqmx_types.StartTaskRequest(task=follower_input_task))
            )
            await raise_if_error_async(
                client.StartTask(nidaqmx_types.StartTaskRequest(task=follower_output_task))
            )
            # trigger task must be started last
            await raise_if_error_async(
                client.StartTask(nidaqmx_types.StartTaskRequest(task=leader_input_task))
            )

            async def read_data():
                nonlocal num_leader_samples_written, num_follower_samples_written
                async for every_n_samples_response in every_n_samples_stream:
                    await raise_if_error(every_n_samples_response)
                    leader_response: nidaqmx_types.ReadAnalogF64Response = (
                        await raise_if_error_async(
                            client.ReadAnalogF64(
                                nidaqmx_types.ReadAnalogF64Request(
                                    task=leader_input_task,
                                    num_samps_per_chan=2000,
                                    timeout=10.0,
                                    fill_mode=nidaqmx_types.GroupBy.GROUP_BY_GROUP_BY_CHANNEL,
                                    array_size_in_samps=2000,
                                )
                            )
                        )
                    )
                    num_leader_samples_written += leader_response.samps_per_chan_read
                    follower_response: nidaqmx_types.ReadAnalogF64Response = (
                        await raise_if_error_async(
                            client.ReadAnalogF64(
                                nidaqmx_types.ReadAnalogF64Request(
                                    task=follower_input_task,
                                    num_samps_per_chan=2000,
                                    timeout=10.0,
                                    fill_mode=nidaqmx_types.GroupBy.GROUP_BY_GROUP_BY_CHANNEL,
                                    array_size_in_samps=2000,
                                )
                            )
                        )
                    )
                    num_follower_samples_written += follower_response.samps_per_chan_read

                    print(
                        f"\t{leader_response.samps_per_chan_read}\t{follower_response.samps_per_chan_read}\t\t{num_leader_samples_written}\t{num_follower_samples_written}"
                    )

            async def wait_for_done(done_event_stream):
                async for done_response in done_event_stream:
                    every_n_samples_stream.cancel()
                    for stream in done_event_stream_list:
                        stream.cancel()
                    await raise_if_error(done_response)

            async def wait_for_input():
                loop = asyncio.get_event_loop()
                await loop.run_in_executor(None, sys.stdin.readline)
                raise Exception("Enter pressed, quitting")

            print("Acquiring samples continuously. Press Enter to interrupt")
            print("\nRead:\tLeader\tFollower\tTotal:\tLeader\tFollower")
            tasks = [read_data(), wait_for_input()] + [
                wait_for_done(stream) for stream in done_event_stream_list
            ]
            await asyncio.gather(*tasks)

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
            await _cleanup()


async def _cleanup():
    global leader_input_task, leader_output_task, follower_input_task, follower_output_task
    if client:
        if leader_input_task:
            await client.StopTask(nidaqmx_types.StopTaskRequest(task=leader_input_task))
            await client.ClearTask(nidaqmx_types.ClearTaskRequest(task=leader_input_task))
            leader_input_task = None
        if leader_output_task:
            await client.StopTask(nidaqmx_types.StopTaskRequest(task=leader_output_task))
            await client.ClearTask(nidaqmx_types.ClearTaskRequest(task=leader_output_task))
            leader_output_task = None
        if follower_input_task:
            await client.StopTask(nidaqmx_types.StopTaskRequest(task=follower_input_task))
            await client.ClearTask(nidaqmx_types.ClearTaskRequest(task=follower_input_task))
            follower_input_task = None
        if follower_output_task:
            await client.StopTask(nidaqmx_types.StopTaskRequest(task=follower_output_task))
            await client.ClearTask(nidaqmx_types.ClearTaskRequest(task=follower_output_task))
            follower_output_task = None


# Run main
try:
    futures = [_main()]
    loop = asyncio.get_event_loop()
    loop.run_until_complete(asyncio.wait(futures))
finally:
    # This handles cleanup if the user presses Ctrl+C
    cleanup_future = [_cleanup()]
    loop = asyncio.get_event_loop()
    loop.run_until_complete(asyncio.wait(cleanup_future))
