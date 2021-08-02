# Demonstrates how to read values from a digital input port.
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
# when calling read_digital_u32, we set fill_mode_raw instead of fill_mode to avoid a default raw value
# being used.
#
# Running from command line:
#
# Server machine's IP address, port number, and lines name can be passed as separate command line arguments.
#   > python digital-input-betterproto.py <server_address> <port_number> <lines_name>
# If they are not passed in as command line arguments, then by default the server address will be "localhost:31763", with "Dev1/port0" as the lines name

import asyncio
from nidevice import nidaqmx_grpc
import sys
from grpclib.client import Channel
from grpclib.exceptions import GRPCError

server_address = "localhost"
server_port = "31763"
lines = "Dev1/port0"

if len(sys.argv) >= 2:
    server_address = sys.argv[1]
if len(sys.argv) >= 3:
    server_port = sys.argv[2]
if len(sys.argv) >= 4:
    lines = sys.argv[3]


async def main():
    # Create a gRPC channel + await daq_service.
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
            await daq_service.create_d_i_chan(
                task=task,
                lines=lines,
                line_grouping_raw=nidaqmx_grpc.LineGrouping.LINE_GROUPING_CHAN_FOR_ALL_LINES,
            )
        )

        await raise_if_error(await daq_service.start_task(task=task))

        response = await daq_service.read_digital_u32(
            task=task,
            num_samps_per_chan=1,
            array_size_in_samps=1,
            fill_mode_raw=nidaqmx_grpc.GroupBy.GROUP_BY_GROUP_BY_CHANNEL,
            timeout=10.0,
        )
        await raise_if_error(response)

        print(f"Data acquired: {hex(response.read_array[0])}")
    except GRPCError as e:
        if e.status.name == "UNIMPLEMENTED":
            print("The operation is not implemented or is not supported/enabled in this service")
        else:
            print(f"GRPCError: {str(e)}")
    except Exception as e:
        print(str(e))
    finally:
        if task:
            await daq_service.stop_task(task=task)
            await daq_service.clear_task(task=task)
        channel.close()


## Run main
loop = asyncio.get_event_loop()
future = asyncio.ensure_future(main())
loop.run_until_complete(future)
