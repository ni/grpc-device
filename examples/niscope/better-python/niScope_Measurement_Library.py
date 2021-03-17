#########################################################################################
#
# Copyright 2020 National Instruments
# Licensed under the MIT license
#
# This is an example of using the niScope driver through gRPC
# Tested with a 100 kHz tone input to channel 0
# The gRPC API is built from the C API.  NI-SCOPE documentation is found:
# C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niScope\Documentation\scopeFunc.chm
#
# This example uses the "betterproto" protocol buffers / gRPC library
#   betterproto produces a more idiomatic version of the gRPC API
#   for more information see: https://github.com/danielgtaylor/python-betterproto
#
# Getting Started:
#
# Install the gRPC tools for Python
#     > pip install grpcio-tools
#   if you are using anaconda
#     > conda install grpcio-tools
#
# Install the betterproto tools
#   Install both the library and compiler
#       pip install "betterproto[compiler]"
#   Install just the library (to use the generated code output)
#       pip install betterproto
#
# Generate the python API from the gRPC definition (.ptoto) files
#   > python -m grpc_tools.protoc -I. --python_betterproto_out=. --grpc_python_out=. ./session.proto
#   > python -m grpc_tools.protoc -I. --python_betterproto_out=. --grpc_python_out=. ./niscope.proto
#
# NOTE: betterproto has a bug generating helpers for gRPC messages with oneofs. 
# Only the last field in the oneof can be properly set without wrapper modification
#
# Update the server address and resource name and options in this file

from grpc import niscope as scope_types
import asyncio
from grpclib.client import Channel
import matplotlib.pyplot as plt
import time

# This is the location (ipaddress or machine name):(port) of the niDevice server
# It contains 2 parts: host [IP] address and port
# resouce is the resource name of the hardware exposed by the server
server_address = "localhost"
server_port = 31763
resource = "Scope"
options = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe; MemorySize:1610612736"

show_plot = True #set to false to disable graph and increase speed

# Error Reporting ########################################
async def check_status(scope_service, result):
    if (result.status != 0):
        error = await scope_service.get_error()
        print(error.description)

# Entry Points ###########################################
async def open_grpc_scope(resource_name: str, host: str, port: int):
    print("Entry to open_grpc_scope")
    channel = Channel(host=host, port=port)
    scope_service = scope_types.NiScopeStub(channel)

    # Initialize the scope
    init_result = await scope_service.init_with_options(
        session_name = "demoSession",
        resource_name = resource,
        id_query = False,
        reset_device=False,
        option_string = options
    )
    await check_status(scope_service, init_result)
    vi = init_result.vi
    return scope_service, channel, vi


async def close_grpc_scope(scope_service: scope_types.NiScopeStub, channel, vi):
    await scope_service.close(vi=vi)
    channel.close()
    return 0


async def configure_grpc_scope(scope_service: scope_types.NiScopeStub, channel, vi):
    # Configure horizontal timing
    config_horizontal_result = await scope_service.configure_horizontal_timing(
        vi=vi,
        min_sample_rate = 1000000,
        min_num_pts = 1000,
        ref_position = 50,
        num_records = 1,
        enforce_realtime = True
    )
    await check_status(scope_service, config_horizontal_result)

    # Configure Vertical
    config_vertical_result = await scope_service.configure_vertical(
        vi = vi,
        channel_list = "0",
        range = 10.0,
        offset = 0,
        coupling_raw = 1, #scope_types.VerticalCoupling.VERTICAL_COUPLING_NISCOPE_VAL_DC,
        enabled = True,
        probe_attenuation = 1
    )
    await check_status(scope_service, config_vertical_result)

    # Setup and Edge Trigger
    set_trigger_result = await scope_service.set_attribute_vi_int32(
        vi = vi,
        attribute_id = scope_types.NiScopeAttributes.NISCOPE_ATTRIBUTE_TRIGGER_TYPE,
        value = scope_types.TriggerType.TRIGGER_TYPE_NISCOPE_VAL_EDGE_TRIGGER
    )
    await check_status(scope_service, set_trigger_result)

    configure_trigger_result = await scope_service.configure_trigger_edge(
        vi = vi,
        trigger_source = "0",
        level = 0.00,
        slope_raw = scope_types.TriggerSlope.TRIGGER_SLOPE_NISCOPE_VAL_POSITIVE,
        trigger_coupling_raw = scope_types.TriggerCoupling.TRIGGER_COUPLING_NISCOPE_VAL_DC,
        holdoff = 0.0,
    )
    await check_status(scope_service, configure_trigger_result)

    set_units_result = await scope_service.set_attribute_vi_int32(
        vi = vi,
        channel_list = "0",
        attribute_id = scope_types.NiScopeAttributes.NISCOPE_ATTRIBUTE_MEAS_REF_LEVEL_UNITS,
        value = scope_types.RefLevelUnits.REF_LEVEL_UNITS_NISCOPE_VAL_PERCENTAGE
    )
    await check_status(scope_service, set_units_result)

async def measure_grpc_scope(scope_service: scope_types.NiScopeStub, channel, vi):
    if show_plot:
        fig = plt.gcf() # Setup a plot to draw the captured waveform
        fig.show()
        fig.canvas.draw()

    print("\nReading values in loop. CTRL+C to stop.\n")
    try:
        while True:
            if show_plot:
                plt.clf()                   # clear from last iteration
                plt.axis([0, 100, -6, 6])    # setup axis again

            # Read a waveform from the scope
            read_result = await scope_service.read(vi = vi, channel_list = "0", timeout = 1, num_samples = 10000)
            await check_status(scope_service, read_result)
            values = read_result.waveform[0:10]
            print(values)

            if show_plot:    # Update the plot with the new waveform
                plt.plot(read_result.waveform[0:100])
                fig.canvas.draw()
                plt.pause(0.001)

            # Fetch the measured average frequency
            fetch_result = await scope_service.fetch_measurement(
                vi = vi,
                channel_list = "0",
                timeout = 1,
                scalar_meas_function_raw = scope_types.ScalarMeasurement.SCALAR_MEASUREMENT_NISCOPE_VAL_AVERAGE_FREQUENCY
            )
            await check_status(scope_service, fetch_result)
            print("Average Frequency: " + str("%.2f" % round(fetch_result.result[0], 2)) + " mHz")
            print("")
            time.sleep(0.1)
            
    except KeyboardInterrupt:
        pass


async def main():
    grpc_scope = await open_grpc_scope(resource, server_address, server_port)
    await configure_grpc_scope(*grpc_scope)
    await measure_grpc_scope(*grpc_scope)
    await close_grpc_scope(*grpc_scope)

## Run the main
asyncio.run(main())
