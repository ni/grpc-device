r"""Acquire a finite amount of data using the DAQ device's internal clock.

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

This example uses the "betterproto" protocol buffers / gRPC library.
 * betterproto produces a more idiomatic version of the gRPC API
 * for more information see: https://github.com/danielgtaylor/python-betterproto

NOTE: The betterproto code generator has a bug generating helpers for gRPC messages with oneof
fields.
If any parameter accepts either an enum value or a raw value, only the raw value is used. For
example, when calling cfg_samp_clk_timing, we set active_edge_raw instead of active_edge to avoid a
default raw value being used.

To run this example without hardware: create a simulated device in NI MAX on the server (Windows
only).

Running from command line:

Server machine's IP address, port number, and physical channel name can be passed as separate
command line arguments.
  > python analog-input-betterproto.py <server_address> <port_number> <physical_channel_name>
To acquire data from multiple channels, pass in a list or range of channels (i.e., Dev1/ai0:3).
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "Dev1/ai0" as the physical channel name.
"""

import asyncio
import sys

from grpclib.client import Channel
from grpclib.exceptions import GRPCError
from nidevice import nidaqmx_grpc

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
    # Create a gRPC channel + client.
    channel = Channel(host=SERVER_ADDRESS, port=SERVER_PORT)
    daq_service = nidaqmx_grpc.NiDAQmxStub(channel)
    task = None

    async def raise_if_error(response):
        """Raise an exception if an error was returned."""
        if response.status != 0:
            response = await daq_service.get_error_string(error_code=response.status)
            raise Exception(f"Error: {response.error_string}")

    try:
        response = await daq_service.create_task()
        await raise_if_error(response)
        task = response.task

        await raise_if_error(
            await daq_service.create_a_i_voltage_chan(
                task=task,
                physical_channel=PHYSICAL_CHANNEL,
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

        response = await daq_service.get_task_attribute_u_int32(
            task=task, attribute_raw=nidaqmx_grpc.TaskUInt32Attribute.TASK_ATTRIBUTE_NUM_CHANS
        )
        await raise_if_error(response)
        number_of_channels = response.value

        response = await daq_service.read_analog_f64(
            task=task,
            num_samps_per_chan=100,
            array_size_in_samps=number_of_channels * 100,
            fill_mode_raw=nidaqmx_grpc.GroupBy.GROUP_BY_GROUP_BY_CHANNEL,
            timeout=10.0,
        )
        await raise_if_error(response)

        print(
            f"Acquired {len(response.read_array)} samples.",
            f"({response.samps_per_chan_read} samples per channel)",
        )
        print(f"First 5 samples: {response.read_array[:5]}")
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
future = asyncio.ensure_future(_main())
loop.run_until_complete(future)
