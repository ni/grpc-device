# Demonstrates how to acquire a finite amount of data using the DAQ device's internal clock.
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
# This example uses the "betterproto" protocol buffers / gRPC library
#   betterproto produces a more idiomatic version of the gRPC API
#   for more information see: https://github.com/danielgtaylor/python-betterproto
#
# NOTE: The betterproto code generator has a bug generating helpers for gRPC messages with oneof fields.
# If any parameter accepts either an enum value or a raw value, only the raw value is used. For example,
# when calling cfg_samp_clk_timing, we set active_edge_raw instead of active_edge to avoid a default raw value
# being used.
#
# Running from command line:
#
# Server machine's IP address, port number, and physical channel name can be passed as separate command line arguments.
#   > python analog-input-betterproto.py <server_address> <port_number> <physical_channel_name>
# If they are not passed in as command line arguments, then by default the server address will be "localhost:31763", with "Dev1/ai0" as the physical channel name

import asyncio
from nidevice import nidaqmx_grpc
import sys
from grpclib.client import Channel


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
    # Create a gRPC channel + client.
    channel = Channel(host=server_address, port=server_port)
    daq_service = nidaqmx_grpc.NiDAQmxStub(channel)
    task = None

    # Raise an exception if an error was returned
    async def raise_if_error(response):
        if response.status != 0:
            response = await daq_service.get_error_string(
                error_code=response.status, buffer_size=2048
            )
            error_string = response.error_string.strip(" \0")
            raise Exception(f"Error: {error_string}")

    try:
        response = await daq_service.create_task()
        await raise_if_error(response)
        task = response.task

        await raise_if_error(
            await daq_service.create_a_i_voltage_chan(
                task=task,
                physical_channel=physical_channel,
                terminal_config_raw=nidaqmx_grpc.InputTermCfgWithDefault.INPUT_TERM_CFG_WITH_DEFAULT_CFG_DEFAULT,
                min_val=-10.0,
                max_val=10.0,
                units_raw=nidaqmx_grpc.VoltageUnits2.VOLTAGE_UNITS2_VOLTS,
            )
        )

        await raise_if_error(
            await daq_service.cfg_samp_clk_timing(
                task=task,
                rate=10000.0,
                active_edge_raw=nidaqmx_grpc.Edge1.EDGE1_RISING,
                sample_mode_raw=nidaqmx_grpc.AcquisitionType.ACQUISITION_TYPE_FINITE_SAMPS,
                samps_per_chan=1000,
            )
        )

        await raise_if_error(await daq_service.start_task(task=task))

        response = await daq_service.read_analog_f64(
            task=task,
            num_samps_per_chan=100,
            array_size_in_samps=100,
            fill_mode_raw=nidaqmx_grpc.GroupBy.GROUP_BY_GROUP_BY_CHANNEL,
            timeout=10.0,
        )
        await raise_if_error(response)

        print(f"Acquired {response.samps_per_chan_read} samples.")
        print(f"First 5 samples: {response.read_array[:5]}")
    finally:
        if task:
            await daq_service.stop_task(task=task)
            await daq_service.clear_task(task=task)
        channel.close()


## Run main
loop = asyncio.get_event_loop()
future = asyncio.ensure_future(main())
loop.run_until_complete(future)
