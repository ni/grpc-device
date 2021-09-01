import asyncio
import grpc
import math
import sys

import nidaqmx_pb2 as nidaqmx_types
import nidaqmx_pb2_grpc as grpc_nidaqmx

# False = sample clock, True = reference clock
synchronization_type_is_reference_clock = False
server_address = "localhost"
server_port = "31763"
leader_device = "Dev1"
follower_device = "Dev2"
if len(sys.argv) >= 2:
    server_address = sys.argv[1]
if len(sys.argv) >= 3:
    server_port = sys.argv[2]
if len(sys.argv) >= 4:
    leader_device = sys.argv[3]
if len(sys.argv) >= 5:
    follower_device = sys.argv[4]

leader_input_channel = f"{leader_device}/ai0"
leader_output_channel = f"{leader_device}/ao0"
follower_input_channel = f"{follower_device}/ai0"
follower_output_channel = f"{follower_device}/ao0"

client = None
leader_input_task = None
leader_output_task = None
follower_input_task = None
follower_output_task = None
num_leader_written = 0
num_follower_written = 0


async def main():
    global client, leader_input_task, leader_output_task, follower_input_task, follower_output_task, num_leader_written, num_follower_written
    async with grpc.aio.insecure_channel(f"{server_address}:{server_port}") as channel:
        try:
            client = grpc_nidaqmx.NiDAQmxStub(channel)

            async def get_terminal_name_with_dev_prefix(task, terminal_name):
                num_devices_response = await raise_if_error_async(client.GetTaskAttributeUInt32(nidaqmx_types.GetTaskAttributeUInt32Request(
                    task=task, attribute=nidaqmx_types.TASK_ATTRIBUTE_NUM_DEVICES
                )))
                num_devices = num_devices_response.value
                for i in range(num_devices):
                    # devices are 1-indexed, so use i + 1 here
                    device = (await raise_if_error_async(client.GetNthTaskDevice(nidaqmx_types.GetNthTaskDeviceRequest(
                        task=task, index=i + 1
                    )))).buffer
                    device_category = (await raise_if_error_async(client.GetDeviceAttributeInt32(nidaqmx_types.GetDeviceAttributeInt32Request(
                        device_name=device, attribute=nidaqmx_types.DEVICE_ATTRIBUTE_PRODUCT_CATEGORY
                    )))).value
                    if device_category != nidaqmx_types.DEVICE_INT32_PRODUCT_CATEGORY_C_SERIES_MODULE and device_category != nidaqmx_types.DEVICE_INT32_PRODUCT_CATEGORY_SCXI_MODULE:
                        return "/" + device + "/" + terminal_name
                raise Exception("Unable to get terminal name for timebase!")

            def generate_sinewave(elements, amplitude, frequency, phase):
                sinewave = [
                    amplitude * math.sin(math.pi/180.0 * (phase + 360.0 * frequency * i)) for i in range(elements)]
                new_phase = (phase + frequency * 360.0 * elements) % 360.0
                return (sinewave, new_phase)

            async def raise_if_error(response):
                if response.status:
                    response = await client.GetErrorString(
                        nidaqmx_types.GetErrorStringRequest(
                            error_code=response.status))
                    raise Exception(f"Error: {response.error_string}")

            async def raise_if_error_async(awaitable_call):
                response = await awaitable_call
                await raise_if_error(response)
                return response

            response: nidaqmx_types.CreateTaskResponse = await raise_if_error_async(
                client.CreateTask(nidaqmx_types.CreateTaskRequest(session_name="Leader input task")))
            leader_input_task = response.task
            await raise_if_error_async(client.CreateAIVoltageChan(nidaqmx_types.CreateAIVoltageChanRequest(
                task=leader_input_task, physical_channel=leader_input_channel,
                min_val=-10.0, max_val=10.0, units=nidaqmx_types.VOLTAGE_UNITS2_VOLTS,
                terminal_config=nidaqmx_types.INPUT_TERM_CFG_WITH_DEFAULT_CFG_DEFAULT
            )))
            await raise_if_error_async(client.CfgSampClkTiming(nidaqmx_types.CfgSampClkTimingRequest(
                task=leader_input_task, rate=10000, active_edge=nidaqmx_types.EDGE1_RISING,
                sample_mode=nidaqmx_types.ACQUISITION_TYPE_CONT_SAMPS, samps_per_chan=1000
            )))

            response = await raise_if_error_async(
                client.CreateTask(nidaqmx_types.CreateTaskRequest(session_name="Leader output task")))
            leader_output_task = response.task
            await raise_if_error_async(client.CreateAOVoltageChan(nidaqmx_types.CreateAOVoltageChanRequest(
                task=leader_output_task, physical_channel=leader_output_channel,
                min_val=-10.0, max_val=10.0, units=nidaqmx_types.VOLTAGE_UNITS2_VOLTS,
            )))
            await raise_if_error_async(client.CfgSampClkTiming(nidaqmx_types.CfgSampClkTimingRequest(
                task=leader_output_task, rate=10000, active_edge=nidaqmx_types.EDGE1_RISING,
                sample_mode=nidaqmx_types.ACQUISITION_TYPE_CONT_SAMPS, samps_per_chan=1000
            )))

            response = await raise_if_error_async(
                client.CreateTask(nidaqmx_types.CreateTaskRequest(session_name="Follower input task")))
            follower_input_task = response.task
            await raise_if_error_async(client.CreateAIVoltageChan(nidaqmx_types.CreateAIVoltageChanRequest(
                task=follower_input_task, physical_channel=follower_input_channel,
                min_val=-10.0, max_val=10.0, units=nidaqmx_types.VOLTAGE_UNITS2_VOLTS,
                terminal_config=nidaqmx_types.INPUT_TERM_CFG_WITH_DEFAULT_CFG_DEFAULT
            )))
            await raise_if_error_async(client.CfgSampClkTiming(nidaqmx_types.CfgSampClkTimingRequest(
                task=follower_input_task, rate=10000, active_edge=nidaqmx_types.EDGE1_RISING,
                sample_mode=nidaqmx_types.ACQUISITION_TYPE_CONT_SAMPS, samps_per_chan=1000
            )))

            response = await raise_if_error_async(
                client.CreateTask(nidaqmx_types.CreateTaskRequest(session_name="Follower output task")))
            follower_output_task = response.task
            await raise_if_error_async(client.CreateAOVoltageChan(nidaqmx_types.CreateAOVoltageChanRequest(
                task=follower_output_task, physical_channel=follower_output_channel,
                min_val=-10.0, max_val=10.0, units=nidaqmx_types.VOLTAGE_UNITS2_VOLTS,
            )))
            await raise_if_error_async(client.CfgSampClkTiming(nidaqmx_types.CfgSampClkTimingRequest(
                task=follower_output_task, rate=10000, active_edge=nidaqmx_types.EDGE1_RISING,
                sample_mode=nidaqmx_types.ACQUISITION_TYPE_CONT_SAMPS, samps_per_chan=1000
            )))

            if synchronization_type_is_reference_clock:
                # Note: Not all DSA devices support reference clock synchronization. Refer to
                # your hardware device manual for further information on whether this method
                # of synchronization is supported for your particular device.
                await raise_if_error_async(client.SetTimingAttributeString(nidaqmx_types.SetTimingAttributeStringRequest(
                    task=leader_input_task, attribute=nidaqmx_types.TimingStringAttributes.TIMING_ATTRIBUTE_REF_CLK_SRC,
                    value="PXI_Clk10")))
                await raise_if_error_async(client.SetTimingAttributeString(nidaqmx_types.SetTimingAttributeStringRequest(
                    task=leader_output_task, attribute=nidaqmx_types.TimingStringAttributes.TIMING_ATTRIBUTE_REF_CLK_SRC,
                    value="PXI_Clk10")))
                await raise_if_error_async(client.SetTimingAttributeString(nidaqmx_types.SetTimingAttributeStringRequest(
                    task=follower_input_task, attribute=nidaqmx_types.TimingStringAttributes.TIMING_ATTRIBUTE_REF_CLK_SRC,
                    value="PXI_Clk10")))
                await raise_if_error_async(client.SetTimingAttributeString(nidaqmx_types.SetTimingAttributeStringRequest(
                    task=follower_output_task, attribute=nidaqmx_types.TimingStringAttributes.TIMING_ATTRIBUTE_REF_CLK_SRC,
                    value="PXI_Clk10")))
            else:
                # Sample clock
                # Note: If you are using PXI DSA devices, the leader device must reside in PXI Slot 2.
                timebase_source = await get_terminal_name_with_dev_prefix(task=leader_input_task, terminal_name="SampleClockTimebase")
                await raise_if_error_async(client.SetTimingAttributeString(nidaqmx_types.SetTimingAttributeStringRequest(
                    task=leader_output_task, attribute=nidaqmx_types.TimingStringAttributes.TIMING_ATTRIBUTE_SAMP_CLK_TIMEBASE_SRC,
                    value=timebase_source)))
                await raise_if_error_async(client.SetTimingAttributeString(nidaqmx_types.SetTimingAttributeStringRequest(
                    task=follower_input_task, attribute=nidaqmx_types.TimingStringAttributes.TIMING_ATTRIBUTE_SAMP_CLK_TIMEBASE_SRC,
                    value=timebase_source)))
                await raise_if_error_async(client.SetTimingAttributeString(nidaqmx_types.SetTimingAttributeStringRequest(
                    task=follower_output_task, attribute=nidaqmx_types.TimingStringAttributes.TIMING_ATTRIBUTE_SAMP_CLK_TIMEBASE_SRC,
                    value=timebase_source)))

            sync_pulse_source = await get_terminal_name_with_dev_prefix(task=leader_input_task, terminal_name="SyncPulse")
            await raise_if_error_async(client.SetTimingAttributeString(nidaqmx_types.SetTimingAttributeStringRequest(
                task=leader_output_task, attribute=nidaqmx_types.TimingStringAttributes.TIMING_ATTRIBUTE_SYNC_PULSE_SRC,
                value=sync_pulse_source)))
            await raise_if_error_async(client.SetTimingAttributeString(nidaqmx_types.SetTimingAttributeStringRequest(
                task=follower_input_task, attribute=nidaqmx_types.TimingStringAttributes.TIMING_ATTRIBUTE_SYNC_PULSE_SRC,
                value=sync_pulse_source)))
            await raise_if_error_async(client.SetTimingAttributeString(nidaqmx_types.SetTimingAttributeStringRequest(
                task=follower_output_task, attribute=nidaqmx_types.TimingStringAttributes.TIMING_ATTRIBUTE_SYNC_PULSE_SRC,
                value=sync_pulse_source)))

            start_trigger = await get_terminal_name_with_dev_prefix(task=leader_input_task, terminal_name="ai/StartTrigger")
            await raise_if_error_async(client.CfgDigEdgeStartTrig(nidaqmx_types.CfgDigEdgeStartTrigRequest(
                task=leader_output_task, trigger_source=start_trigger, trigger_edge=nidaqmx_types.EDGE1_RISING
            )))
            await raise_if_error_async(client.CfgDigEdgeStartTrig(nidaqmx_types.CfgDigEdgeStartTrigRequest(
                task=follower_input_task, trigger_source=start_trigger, trigger_edge=nidaqmx_types.EDGE1_RISING
            )))
            await raise_if_error_async(client.CfgDigEdgeStartTrig(nidaqmx_types.CfgDigEdgeStartTrigRequest(
                task=follower_output_task, trigger_source=start_trigger, trigger_edge=nidaqmx_types.EDGE1_RISING
            )))

            (leader_write_data, phase) = generate_sinewave(250, 1.0, 0.02, 0.0)
            (follower_write_data, phase) = generate_sinewave(250, 1.0, 0.02, phase)

            num_leader_written = (await raise_if_error_async(client.WriteAnalogF64(nidaqmx_types.WriteAnalogF64Request(
                task=leader_output_task, num_samps_per_chan=250, auto_start=False, timeout=10.0,
                data_layout=nidaqmx_types.GROUP_BY_GROUP_BY_CHANNEL, write_array=leader_write_data
            )))).samps_per_chan_written
            num_follower_written = (await raise_if_error_async(client.WriteAnalogF64(nidaqmx_types.WriteAnalogF64Request(
                task=follower_output_task, num_samps_per_chan=250, auto_start=False, timeout=10.0,
                data_layout=nidaqmx_types.GROUP_BY_GROUP_BY_CHANNEL, write_array=follower_write_data
            )))).samps_per_chan_written

            every_n_samples_stream = client.RegisterEveryNSamplesEvent(
                nidaqmx_types.RegisterEveryNSamplesEventRequest(
                    task=leader_input_task,
                    n_samples=100,
                    every_n_samples_event_type=nidaqmx_types.EVERY_N_SAMPLES_EVENT_TYPE_ACQUIRED_INTO_BUFFER))

            # Wait for initial_metadata to ensure that the callback is registered before starting the task.
            await every_n_samples_stream.initial_metadata()

            done_event_stream_list = []
            done_event_stream_list.append(client.RegisterDoneEvent(
                nidaqmx_types.RegisterDoneEventRequest(task=leader_input_task)))
            done_event_stream_list.append(client.RegisterDoneEvent(
                nidaqmx_types.RegisterDoneEventRequest(task=leader_output_task)))
            done_event_stream_list.append(client.RegisterDoneEvent(
                nidaqmx_types.RegisterDoneEventRequest(task=follower_input_task)))
            done_event_stream_list.append(client.RegisterDoneEvent(
                nidaqmx_types.RegisterDoneEventRequest(task=follower_output_task)))
            for done_event_stream in done_event_stream_list:
                await done_event_stream.initial_metadata()

            await raise_if_error_async(client.StartTask(nidaqmx_types.StartTaskRequest(task=leader_output_task)))
            await raise_if_error_async(client.StartTask(nidaqmx_types.StartTaskRequest(task=follower_input_task)))
            await raise_if_error_async(client.StartTask(nidaqmx_types.StartTaskRequest(task=follower_output_task)))
            # trigger task must be started last
            await raise_if_error_async(client.StartTask(nidaqmx_types.StartTaskRequest(task=leader_input_task)))

            async def read_data():
                global num_leader_written, num_follower_written
                async for every_n_samples_response in every_n_samples_stream:
                    await raise_if_error(every_n_samples_response)
                    leader_response: nidaqmx_types.ReadAnalogF64Response = await raise_if_error_async(
                        client.ReadAnalogF64(
                            nidaqmx_types.ReadAnalogF64Request(
                                task=leader_input_task,
                                num_samps_per_chan=2000,
                                timeout=10.0,
                                fill_mode=nidaqmx_types.GroupBy.GROUP_BY_GROUP_BY_CHANNEL,
                                array_size_in_samps=2000)))
                    num_leader_written += leader_response.samps_per_chan_read
                    follower_response: nidaqmx_types.ReadAnalogF64Response = await raise_if_error_async(
                        client.ReadAnalogF64(
                            nidaqmx_types.ReadAnalogF64Request(
                                task=follower_input_task,
                                num_samps_per_chan=2000,
                                timeout=10.0,
                                fill_mode=nidaqmx_types.GroupBy.GROUP_BY_GROUP_BY_CHANNEL,
                                array_size_in_samps=2000)))
                    num_follower_written += follower_response.samps_per_chan_read

                    print(
                        f"\t{leader_response.samps_per_chan_read}\t{follower_response.samps_per_chan_read}\t\t{num_leader_written}\t{num_follower_written}")

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
            tasks = [read_data(), wait_for_input()] + [wait_for_done(stream)
                                                       for stream in done_event_stream_list]
            await asyncio.gather(*tasks)

        except grpc.RpcError as rpc_error:
            error_message = rpc_error.details()
            if rpc_error.code() == grpc.StatusCode.UNAVAILABLE:
                error_message = f"Failed to connect to server on {server_address}:{server_port}"
            elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
                error_message = "The operation is not implemented or is not supported/enabled in this service"
            print(f"{error_message}")

        finally:
            await cleanup()


async def cleanup():
    global client, leader_input_task, leader_output_task, follower_input_task, follower_output_task
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
    futures = [main()]
    loop = asyncio.get_event_loop()
    loop.run_until_complete(asyncio.wait(futures))
finally:
    # This handles cleanup if the user presses Ctrl+C
    cleanup_future = [cleanup()]
    loop = asyncio.get_event_loop()
    loop.run_until_complete(asyncio.wait(cleanup_future))
