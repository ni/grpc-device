#
# Example communication with niScope over gRPC
#
# Copyright 2020 National Instruments
# Licensed under the MIT license
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
#   > pip install "betterproto[compiler]"
#
# Generate the python API from the gRPC definition (.ptoto) files
#   > python -m grpc_tools.protoc -I. --python_betterproto_out=. --grpc_python_out=. ./niDevice.proto
#   > python -m grpc_tools.protoc -I. --python_betterproto_out=. --grpc_python_out=. ./niScope.proto 
#
# Update the server address and resource name and options in this file
# Run the code to read a waveform from the scope
#

import niScope
import asyncio
from grpclib.client import Channel

# This is the location (ipaddress or machine name):(port) of the niDevice server
serverAddress = "localhost:31763"

# Resource name and options for a simulated 5164 scope
resource = "SimulatedScope7c632f66-e7c2-4fab-85a4-cd15c8be4130"
options = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe; MemorySize:1610612736"

async def perform_acquire():

    # Create the communcation channel for the remote host (in this case we are connecting to a local server)
    # and create a connection to the niScope service
    channel = Channel(host="localhost", port=31763)
    scope = niScope.NiScopeStub(channel)

    # Initialize the scope
    initResult = await scope.init_with_options(
        session_name = "demoSession",
        resource_name = resource,
        id_query = False,
        reset_device=False,
        option_string = options
        )
    vi = initResult.new_vi
    print(vi)

    # Configure horizontal timing
    configResult = await scope.configure_horizontal_timing(
        vi = vi,
        min_sample_rate = 5000000,
        min_num_pts = 100000,
        ref_position = 50,
        num_records = 1,
        enforce_realtime = True
        )

    # Configure vertical timing
    verticalResult = await scope.configure_vertical(
        vi = vi,
        channel_list = "0",
        range = 30.0,
        offset = 0,
        coupling = niScope.ScopeValues.val_dc,
        enabled = True,
        probe_attenuation = 1
        )

    confTriggerEdgeResult = await scope.configure_trigger_edge(
        vi = vi,
        trigger_source = "0",
        level = 0.00,
        trigger_coupling = niScope.ScopeValues.val_dc,
        slope = niScope.ScopeValues.val_positive
        )

    result = await scope.set_attribute_vi_int32(
        vi = vi,
        channel_list = "0",
        attribute_id = niScope.ScopeAttributes.attr_meas_ref_level_units,
        value = niScope.ScopeAttributes.attr_meas_percentage_method
    )

    readResult = await scope.read(
        vi = vi,
        channel_list = "0",
        timeout = 10000,
        num_samples = 100000
        )

    # print the value of the first few samples
    values = readResult.wfm[0:10]

    # Read a waveform from the scope
    readResult = await scope.read(
        vi = vi,
        channel_list = "0",
        timeout = 10000,
        num_samples = 100000
        )

    # print the value of the first few samples
    values = readResult.wfm[0:10]
    print(values)

    await scope.close(vi = vi)
    channel.close()


loop = asyncio.get_event_loop()
asyncio.run(perform_acquire())
