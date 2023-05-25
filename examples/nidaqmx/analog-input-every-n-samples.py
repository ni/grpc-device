r"""Acquire analog data using futures and RegisterEveryNSamplesEvent.

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

import sys
from concurrent.futures import ThreadPoolExecutor

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


def _main():
    with grpc.insecure_channel(
        f"{SERVER_ADDRESS}:{SERVER_PORT}"
    ) as channel, ThreadPoolExecutor() as executor:
        client = grpc_nidaqmx.NiDAQmxStub(channel)
        task = None

        def check_for_warning(response):
            """Print to console if the status indicates a warning."""
            if response.status > 0:
                warning_message = client.GetErrorString(
                    nidaqmx_types.GetErrorStringRequest(error_code=response.status)
                )
                sys.stderr.write(
                    f"{warning_message.error_string}\nWarning status: {response.status}\n"
                )

        def check_for_stream_error(stream):
            """Raise an exception if the stream was closed with an error."""
            if stream.done() and stream.exception() is not None:
                raise stream.exception()

        try:
            create_task_response = client.CreateTask(nidaqmx_types.CreateTaskRequest())
            task = create_task_response.task

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

            total_samples_per_channel = 1000
            samples_per_channel_per_read = 100
            client.CfgSampClkTiming(
                nidaqmx_types.CfgSampClkTimingRequest(
                    task=task,
                    sample_mode=nidaqmx_types.AcquisitionType.ACQUISITION_TYPE_FINITE_SAMPS,
                    samps_per_chan=total_samples_per_channel,
                    active_edge=nidaqmx_types.Edge1.EDGE1_RISING,
                    rate=100,
                )
            )

            every_n_samples_stream = client.RegisterEveryNSamplesEvent(
                nidaqmx_types.RegisterEveryNSamplesEventRequest(
                    task=task,
                    n_samples=samples_per_channel_per_read,
                    every_n_samples_event_type=nidaqmx_types.EVERY_N_SAMPLES_EVENT_TYPE_ACQUIRED_INTO_BUFFER,
                )
            )

            # Wait for initial_metadata and check for stream errors to ensure that the callback is
            # registered successfully before starting the task.
            every_n_samples_stream.initial_metadata()
            check_for_stream_error(every_n_samples_stream)

            done_event_stream = client.RegisterDoneEvent(
                nidaqmx_types.RegisterDoneEventRequest(task=task)
            )

            done_event_stream.initial_metadata()
            check_for_stream_error(done_event_stream)

            start_task_response = client.StartTask(nidaqmx_types.StartTaskRequest(task=task))
            check_for_warning(start_task_response)

            get_num_chans_response = client.GetTaskAttributeUInt32(
                nidaqmx_types.GetTaskAttributeUInt32Request(
                    task=task, attribute=nidaqmx_types.TASK_ATTRIBUTE_NUM_CHANS
                )
            )

            number_of_channels = get_num_chans_response.value

            def read_data():
                samps_per_chan_read = 0

                try:
                    for every_n_samples_response in every_n_samples_stream:
                        read_response = client.ReadAnalogF64(
                            nidaqmx_types.ReadAnalogF64Request(
                                task=task,
                                num_samps_per_chan=samples_per_channel_per_read,
                                fill_mode=nidaqmx_types.GroupBy.GROUP_BY_GROUP_BY_CHANNEL,
                                array_size_in_samps=number_of_channels
                                * samples_per_channel_per_read,
                            )
                        )
                        check_for_warning(read_response)

                        print(
                            f"Acquired {len(read_response.read_array)} samples",
                            f"({read_response.samps_per_chan_read} samples per channel)",
                        )
                        print("Read Data:", read_response.read_array[:10])

                        # Unregister the event stream when all samples are read.
                        samps_per_chan_read += read_response.samps_per_chan_read
                        if samps_per_chan_read >= total_samples_per_channel:
                            every_n_samples_stream.cancel()
                except grpc.RpcError as rpc_error:
                    if rpc_error.code() == grpc.StatusCode.CANCELLED:
                        return
                    raise

            def wait_for_done():
                try:
                    for done_response in done_event_stream:
                        done_event_stream.cancel()
                        # Cancel the acquisition if there's an error, otherwise let it continue
                        # until all samples are read.
                        if done_response.status:
                            every_n_samples_stream.cancel()
                except grpc.RpcError as rpc_error:
                    if rpc_error.code() == grpc.StatusCode.CANCELLED:
                        return
                    raise

            read_data_future = executor.submit(read_data)
            wait_for_done_future = executor.submit(wait_for_done)

            read_data_future.result()
            wait_for_done_future.result()

            stop_task_response = client.StopTask(nidaqmx_types.StopTaskRequest(task=task))
            check_for_warning(stop_task_response)

        except grpc.RpcError as rpc_error:
            error_message = str(rpc_error.details() or "")
            for entry in rpc_error.trailing_metadata() or []:
                if entry.key == "ni-error":
                    value = (
                        entry.value if isinstance(entry.value, str) else entry.value.decode("utf-8")
                    )
                    error_message += f"\nError status: {value}"
            if rpc_error.code() == grpc.StatusCode.UNAVAILABLE:
                error_message = f"Failed to connect to server on {SERVER_ADDRESS}:{SERVER_PORT}"
            elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
                error_message = (
                    "The operation is not implemented or is not supported/enabled in this service"
                )
            print(f"{error_message}")
        finally:
            if client and task:
                client.ClearTask(nidaqmx_types.ClearTaskRequest(task=task))


if __name__ == "__main__":
    _main()
