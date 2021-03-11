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
#   > python -m grpc_tools.protoc -I. --python_betterproto_out=. --grpc_python_out=. ./niDevice.proto
#   > python -m grpc_tools.protoc -I. --python_betterproto_out=. --grpc_python_out=. ./niScope.proto
#
# Update the server address and resource name and options in this file

import niScope
import niDevice
import asyncio
from grpclib.client import Channel
import matplotlib.pyplot as plt

# This is the location (ipaddress or machine name):(port) of the niDevice server
# It contains 2 parts: host [IP] address and port
# resouce is the resource name of the hardware exposed by the server
#serverAddress = "localhost"
serverAddress = "192.168.0.197"
serverPort = 50051
resource = "Scope"
options = ""

showPlot = True #set to false to disable graph and increase speed

# Entry Points ###########################################
async def open_grpc_scope(resource_name: str, host=serverAddress, port=50051):
    print("Entry to open_grpc_scope")
    channel = Channel(host=host, port=50051)
    scope = niScope.NiScopeServiceStub(channel)

    # Initialize the scope without options
    initResult = await scope.init(session_name="0", resource_name=resource_name,
                                  i_d_query=False, reset_device=False)
    vi = initResult.vi
    return scope, channel, vi


async def close_grpc_scope(scope: niScope.NiScopeServiceStub, channel, vi):
    await scope.close(vi=vi)
    channel.close()
    return 0


async def configure_grpc_scope(scope: niScope.NiScopeServiceStub, channel, vi):
    # Configure horizontal timing
    configResult = await scope.configure_horizontal_timing(
        vi=vi,
        min_sample_rate=1000000,
        min_num_pts=1000,
        ref_position=50,
        num_records=1,
        enforce_realtime=True
    )

    # Configure Vertical
    configResult = await scope.configure_vertical(
        vi=vi,
        channel_list="0",
        range=10.0,
        offset=0,
        coupling=niScope.ScopeValues.val_dc,
        enabled=True,
        probe_attenuation=1
    )

    # Setup and Edge Trigger
    await scope.set_attribute_vi_int32(vi=vi, channel_list="0",
                                       attribute_id=niScope.ScopeAttributes.attr_trigger_type,
                                       value=niScope.ScopeValues.val_edge_trigger)

    await scope.configure_trigger_edge(vi=vi, trigger_source="0", level=0.00, holdoff=0.0,
                                       slope=niScope.ScopeValues.val_positive,
                                       trigger_coupling=niScope.ScopeValues.val_dc)


async def measure_grpc_scope(scope: niScope.NiScopeServiceStub, channel, vi):
    if showPlot:
        fig = plt.gcf() # Setup a plot to draw the captured waveform
        fig.show()
        fig.canvas.draw()

    print("\nReading values in loop. CTRL+C to stop.\n")
    try:
        while True:
            if showPlot:
                plt.clf()                   # clear from last iteration
                plt.axis([0, 50, -1, 1])    # setup axis again

            # Read a waveform from the scope
            readResult = await scope.read(vi=vi, channel_list="0", timeout=1, num_samples=10000)
            values = readResult.wfm[0:10]
            print(values)

            if showPlot:    # Update the plot with the new waveform
                plt.plot(readResult.wfm[0:100])
                fig.canvas.draw()
                plt.pause(0.001)

            # Fetch the measured average frequency
            fetchResult = await scope.fetch_measurement(vi=vi, channel_list="0", timeout=1,
                                                        scalar_meas_function=niScope.ScopeValues.val_average_frequency)
            print("Average Frequency: " + str("%.2f" % round(fetchResult.result[0], 2)) + " Hz")
            print("")
    except KeyboardInterrupt:
        pass


async def main():
    grpc_scope = await open_grpc_scope(resource, serverAddress, serverPort)
    await configure_grpc_scope(*grpc_scope)
    await measure_grpc_scope(*grpc_scope)
    await close_grpc_scope(*grpc_scope)

## Run the main
asyncio.run(main())
