r"""Read waveforms from an NI-SCOPE device using betterproto.

The gRPC API is built from the C API. NI-SCOPE documentation is installed with the driver at:
  C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niScope\Documentation\English\Digitizers.chm

A version of this .chm is available online at:
  https://zone.ni.com/reference/en-XX/help/370592AB-01/

Getting Started:

To run this example, install "NI-SCOPE Driver" on the server machine:
  https://www.ni.com/en-us/support/downloads/drivers/download.ni-scope.html

Refer to the NI-SCOPE gRPC Wiki to determine the valid channel and resource names for your
NI-SCOPE module:
  https://github.com/ni/grpc-device/wiki/NI-SCOPE-C-Function-Reference

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

This example uses the "betterproto" protocol buffers / gRPC library.
 * betterproto produces a more idiomatic version of the gRPC API
 * for more information see: https://github.com/danielgtaylor/python-betterproto

NOTE: The betterproto code generator has a bug generating helpers for gRPC messages with oneof
fields. If any parameter accepts either an enum value or a raw value, only the raw value is used.
For example, when calling configure_vertical, we set coupling_raw instead of coupling to avoid a
default raw value being used.

Running from command line:

Server machine's IP address, port number, and resource name can be passed as separate command line
arguments.
  > python graph-measurement-betterproto.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedScope" as the resource name.
"""

import asyncio
import sys
import time

import matplotlib.pyplot as plt
from grpclib.client import Channel
from grpclib.exceptions import GRPCError
from nidevice import niscope_grpc

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"

# Resource name and options for a simulated 5164 client. Change them according to the NI-SCOPE
# model.
RESOURCE = "SimulatedScope"
OPTIONS = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe; MemorySize:1610612736"

CHANNELS = "0"

# set to false to disable graph and increase speed
SHOW_PLOT = True

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) == 4:
    RESOURCE = sys.argv[3]
    OPTIONS = ""

# Handle closing of plot window.
closed = False


def _on_close(event):
    global closed
    closed = True


async def check_for_error(scope_service, vi, result):
    """Raise an exception if the status indicates an error."""
    if result.status != 0:
        error_result = await scope_service.get_error_message(vi=vi, error_code=result.status)
        raise Exception(error_result.error_message)


async def open_grpc_scope(resource_name: str, server_address: str, server_port):
    """Initialize the scope."""
    channel = Channel(host=server_address, port=server_port)
    scope_service = niscope_grpc.NiScopeStub(channel)

    init_result = await scope_service.init_with_options(
        session_name="demoSession",
        resource_name=RESOURCE,
        id_query=False,
        reset_device=False,
        option_string=OPTIONS,
    )
    vi = init_result.vi
    await check_for_error(scope_service, vi, init_result)
    return scope_service, channel, vi


async def configure_grpc_scope(scope_service: niscope_grpc.NiScopeStub, channel, vi):
    """Configure timing and trigger."""
    # Configure horizontal timing
    config_horizontal_result = await scope_service.configure_horizontal_timing(
        vi=vi,
        min_sample_rate=1000000,
        min_num_pts=1000,
        ref_position=50,
        num_records=1,
        enforce_realtime=True,
    )
    await check_for_error(scope_service, vi, config_horizontal_result)

    # Configure Vertical
    config_vertical_result = await scope_service.configure_vertical(
        vi=vi,
        channel_list=CHANNELS,
        range=10.0,
        offset=0,
        coupling_raw=niscope_grpc.VerticalCoupling.VERTICAL_COUPLING_NISCOPE_VAL_DC,
        enabled=True,
        probe_attenuation=1,
    )
    await check_for_error(scope_service, vi, config_vertical_result)

    # Setup and Edge Trigger
    set_trigger_result = await scope_service.set_attribute_vi_int32(
        vi=vi,
        attribute_id=niscope_grpc.NiScopeAttribute.NISCOPE_ATTRIBUTE_TRIGGER_TYPE,
        value_raw=niscope_grpc.NiScopeInt32AttributeValues.NISCOPE_INT32_TRIGGER_TYPE_VAL_EDGE_TRIGGER,
    )
    await check_for_error(scope_service, vi, set_trigger_result)

    configure_trigger_result = await scope_service.configure_trigger_edge(
        vi=vi,
        trigger_source=CHANNELS,
        level=0.00,
        slope_raw=niscope_grpc.TriggerSlope.TRIGGER_SLOPE_NISCOPE_VAL_POSITIVE,
        trigger_coupling_raw=niscope_grpc.TriggerCoupling.TRIGGER_COUPLING_NISCOPE_VAL_DC,
        holdoff=0.0,
    )
    await check_for_error(scope_service, vi, configure_trigger_result)

    set_units_result = await scope_service.set_attribute_vi_int32(
        vi=vi,
        channel_list=CHANNELS,
        attribute_id=niscope_grpc.NiScopeAttribute.NISCOPE_ATTRIBUTE_MEAS_REF_LEVEL_UNITS,
        value_raw=niscope_grpc.NiScopeInt32AttributeValues.NISCOPE_INT32_REF_LEVEL_UNITS_VAL_PERCENTAGE,
    )
    await check_for_error(scope_service, vi, set_units_result)


async def measure_grpc_scope(scope_service: niscope_grpc.NiScopeStub, channel, vi):
    """Acquire data."""
    if SHOW_PLOT:
        fig = plt.gcf()  # Setup a plot to draw the captured waveform
        fig.show()
        fig.canvas.draw()
        fig.canvas.mpl_connect("close_event", _on_close)

    print("\nReading values in loop. CTRL+C to stop.\n")
    try:
        while not closed:
            if SHOW_PLOT:
                plt.clf()  # clear from last iteration
                plt.axis([0, 100, -6, 6])  # setup axis again

            # Read a waveform from the scope
            read_result = await scope_service.read(
                vi=vi, channel_list="0", timeout=1, num_samples=10000
            )
            await check_for_error(scope_service, vi, read_result)
            values = read_result.waveform[0:10]
            print(values)

            # Update the plot with the new waveform
            if SHOW_PLOT:
                plt.plot(read_result.waveform[0:100])
                fig.canvas.draw()
                plt.pause(0.001)

            # Fetch the measured average frequency
            fetch_result = await scope_service.fetch_measurement_stats(
                vi=vi,
                channel_list=CHANNELS,
                timeout=1,
                scalar_meas_function_raw=niscope_grpc.ScalarMeasurement.SCALAR_MEASUREMENT_NISCOPE_VAL_AVERAGE_FREQUENCY,
            )
            await check_for_error(scope_service, vi, fetch_result)
            print("Average Frequency: " + str("%.2f" % round(fetch_result.result[0], 2)) + " Hz")
            print("")
            time.sleep(0.1)

    except KeyboardInterrupt:
        pass


async def _main():
    channel = None
    try:
        scope_service, channel, vi = await open_grpc_scope(RESOURCE, SERVER_ADDRESS, SERVER_PORT)
        await configure_grpc_scope(scope_service, channel, vi)
        await measure_grpc_scope(scope_service, channel, vi)
    except GRPCError as e:
        if e.status.name == "UNIMPLEMENTED":
            print("The operation is not implemented or is not supported/enabled in this service")
        else:
            print(f"GRPCError: {str(e)}")
    except Exception as e:
        print(str(e))
    finally:
        if channel:
            await open_grpc_scope(scope_service, channel, vi)
            channel.close()


# Run the main
loop = asyncio.get_event_loop()
future = asyncio.ensure_future(_main())
loop.run_until_complete(future)
