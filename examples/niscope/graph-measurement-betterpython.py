# This is an example of plotting waveforms read from an NI-SCOPE device through gRPC
#
# The gRPC API is built from the C API.  NI-SCOPE documentation is installed with the driver at:
# C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niScope\Documentation\English\Digitizers.chm
#
# Getting Started:
#
# To run this example, install "NI-SCOPE Driver" on the server machine.
# Link : https://www.ni.com/en-us/support/downloads/drivers/download.ni-scope.html
#
# Refer to the NI-SCOPE gRPC Wiki to determine the valid channel and resource names for your NI-SCOPE module.
# Link : https://github.com/ni/grpc-device/wiki/niScope_header
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
# when calling configure_vertical, we set coupling_raw instead of coupling to avoid a default raw value
# being used.
#
# Running from command line:
#
# Server machine's IP address, port number, and resource name can be passed as separate command line arguments.
#   > python fetch.py <server_address> <port_number> <resource_name>
# If they are not passed in as command line arguments, then by default the server address will be "localhost:31763", with "SimulatedScope" as the resource name

from grpc import niscope as niscope_types
import asyncio
import matplotlib.pyplot as plt
import time
import sys
import grpc

default_server_ip = "localhost"
default_server_port = "31763"

# Resource name and options for a simulated 5164 client. Change them according to the NI-SCOPE model.
channels = "0"
resource_name = "SimulatedScope"
options = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe; MemorySize:1610612736"

# Read in cmd args
server_address = f"{default_server_ip}:{default_server_port}"
if len(sys.argv) == 2:
    server_address = f"{sys.argv[1]}:{default_server_port}"
elif len(sys.argv) >= 3:
    server_address = f"{sys.argv[1]}:{sys.argv[2]}"
    if len(sys.argv) == 4:
        resource = sys.argv[3]
        options = ""

#set to false to disable graph and increase speed
show_plot = True 

# Error Reporting
async def CheckStatus(scope_service, result):
    if (result.status != 0):
        error = await scope_service.get_error()
        print(error.description)

# Entry Points
async def OpenGrpcScope(resource_name: str, server_address: str):
    print("Entry to open_grpc_scope")
    channel = grpc.insecure_channel(server_address)
    scope_service = niscope_types.NiScopeStub(channel)

    # Initialize the scope
    init_result = await scope_service.init_with_options(
        session_name = "demoSession",
        resource_name = resource,
        id_query = False,
        reset_device=False,
        option_string = options
    )
    await CheckStatus(scope_service, init_result)
    vi = init_result.vi
    return scope_service, channel, vi


async def CloseGrpcScope(scope_service: niscope_types.NiScopeStub, channel, vi):
    await scope_service.close(vi=vi)
    channel.close()
    return 0


async def ConfigureGrpcScope(scope_service: niscope_types.NiScopeStub, channel, vi):
    # Configure horizontal timing
    config_horizontal_result = await scope_service.configure_horizontal_timing(
        vi=vi,
        min_sample_rate = 1000000,
        min_num_pts = 1000,
        ref_position = 50,
        num_records = 1,
        enforce_realtime = True
    )
    await CheckStatus(scope_service, config_horizontal_result)

    # Configure Vertical
    config_vertical_result = await scope_service.configure_vertical(
        vi = vi,
        channel_list = channels,
        range = 10.0,
        offset = 0,
        coupling_raw = niscope_types.VerticalCoupling.VERTICAL_COUPLING_NISCOPE_VAL_DC,
        enabled = True,
        probe_attenuation = 1
    )
    await CheckStatus(scope_service, config_vertical_result)

    # Setup and Edge Trigger
    set_trigger_result = await scope_service.set_attribute_vi_int32(
        vi = vi,
        attribute_id = niscope_types.NiScopeAttributes.NISCOPE_ATTRIBUTE_TRIGGER_TYPE,
        value = niscope_types.TriggerType.TRIGGER_TYPE_NISCOPE_VAL_EDGE_TRIGGER
    )
    await CheckStatus(scope_service, set_trigger_result)

    configure_trigger_result = await scope_service.configure_trigger_edge(
        vi = vi,
        trigger_source = channels,
        level = 0.00,
        slope_raw = niscope_types.TriggerSlope.TRIGGER_SLOPE_NISCOPE_VAL_POSITIVE,
        trigger_coupling_raw = niscope_types.TriggerCoupling.TRIGGER_COUPLING_NISCOPE_VAL_DC,
        holdoff = 0.0,
    )
    await CheckStatus(scope_service, configure_trigger_result)

    set_units_result = await scope_service.set_attribute_vi_int32(
        vi = vi,
        channel_list = channels,
        attribute_id = niscope_types.NiScopeAttributes.NISCOPE_ATTRIBUTE_MEAS_REF_LEVEL_UNITS,
        value = niscope_types.RefLevelUnits.REF_LEVEL_UNITS_NISCOPE_VAL_PERCENTAGE
    )
    await CheckStatus(scope_service, set_units_result)

async def MeasureGrpcScope(scope_service: niscope_types.NiScopeStub, channel, vi):
    if show_plot:
        fig = plt.gcf() # Setup a plot to draw the captured waveform
        fig.show()
        fig.canvas.draw()

    print("\nReading values in loop. CTRL+C to stop.\n")
    try:
        while True:
            if show_plot:
                plt.clf()                    # clear from last iteration
                plt.axis([0, 100, -6, 6])    # setup axis again

            # Read a waveform from the scope
            read_result = await scope_service.read(vi = vi, channel_list = "0", timeout = 1, num_samples = 10000)
            await CheckStatus(scope_service, read_result)
            values = read_result.waveform[0:10]
            print(values)

            # Update the plot with the new waveform
            if show_plot:    
                plt.plot(read_result.waveform[0:100])
                fig.canvas.draw()
                plt.pause(0.001)

            # Fetch the measured average frequency
            fetch_result = await scope_service.fetch_measurement_stats(
                vi = vi,
                channel_list = channels,
                timeout = 1,
                scalar_meas_function_raw = niscope_types.ScalarMeasurement.SCALAR_MEASUREMENT_NISCOPE_VAL_AVERAGE_FREQUENCY
            )
            await CheckStatus(scope_service, fetch_result)
            print("Average Frequency: " + str("%.2f" % round(fetch_result.result[0], 2)) + " Hz")
            print("")
            time.sleep(0.1)
            
    except KeyboardInterrupt:
        pass


async def main():
    grpc_scope = await OpenGrpcScope(resource, server_address)
    await ConfigureGrpcScope(*grpc_scope)
    await MeasureGrpcScope(*grpc_scope)
    await CloseGrpcScope(*grpc_scope)

## Run the main
asyncio.run(main())
