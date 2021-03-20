#
# Example communication with NI-SCOPE over gRPC
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
#   > pip install --pre "betterproto[compiler]"
#
# Generate the python API from the gRPC definition (.ptoto) files
#   > python -m grpc_tools.protoc -I. --python_betterproto_out=. --grpc_python_out=. ./session.proto
#   > python -m grpc_tools.protoc -I. --python_betterproto_out=. --grpc_python_out=. ./niscope.proto 
#
# NOTE: betterproto has a bug generating helpers for gRPC messages with oneofs. 
# Only the last field in the oneof can be properly set without wrapper modification
# For example, when calling configure_vertical, we set coupling_raw instead of coupling to avoid this issue
#
# Update the server address and resource name and options in this file
# Run the code to read a waveform from the scope
#

from grpc import niscope as niscope_types
import asyncio
from grpclib.client import Channel
import sys

# Server machine's IP address and port number have to be passed as two separate command line arguments.
#   > python scope-read-betterpython.py localhost 31763
# If not passed as command line arguments, then by default server address would be "localhost:31763"
host = "localhost"
port = 31763
if len(sys.argv) == 3 :
    host = sys.argv[1]
    port = int(sys.argv[2])

# Resource name and options for a simulated 5164 scope
resource = "SimulatedScope"
options = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe; MemorySize:1610612736"

async def CheckStatus(scope_service, result):
    if (result.status != 0):
        error = await scope_service.get_error()
        print(error.description)

async def PerformAcquire():

    # Create the communcation channel for the remote host (in this case we are connecting to a local server)
    # and create a connection to the niScope service
    channel = Channel(host="localhost", port=31763)
    scope_service = niscope_types.NiScopeStub(channel)

    # Initialize the scope
    init_result = await scope_service.init_with_options(
        session_name = "demoSession",
        resource_name = resource,
        id_query = False,
        reset_device=False,
        option_string = options
    )
    vi = init_result.vi
    print(vi)
    await CheckStatus(scope_service, init_result)

    # Configure horizontal timing
    config_result = await scope_service.configure_horizontal_timing(
        vi = vi,
        min_sample_rate = 5000000,
        min_num_pts = 100000,
        ref_position = 50,
        num_records = 1,
        enforce_realtime = True
    )
    await CheckStatus(scope_service, config_result)

    # Configure vertical timing
    vertical_result = await scope_service.configure_vertical(
        vi = vi,
        channel_list = "0",
        range = 10.0,
        offset = 0,
        coupling_raw = niscope_types.VerticalCoupling.VERTICAL_COUPLING_NISCOPE_VAL_DC,
        enabled = True,
        probe_attenuation = 1
    )
    await CheckStatus(scope_service, vertical_result)

    confTrigger_edge_result = await scope_service.configure_trigger_edge(
        vi = vi,
        trigger_source = "0",
        level = 0.00,
        holdoff = 0.0,
        trigger_coupling_raw = niscope_types.TriggerCoupling.TRIGGER_COUPLING_NISCOPE_VAL_DC,
        slope = niscope_types.TriggerSlope.TRIGGER_SLOPE_NISCOPE_VAL_POSITIVE
    )
    await CheckStatus(scope_service, confTrigger_edge_result)

    set_result = await scope_service.set_attribute_vi_int32(
        vi = vi,
        channel_list = "0",
        attribute_id = niscope_types.NiScopeAttributes.NISCOPE_ATTRIBUTE_MEAS_REF_LEVEL_UNITS,
        value = niscope_types.RefLevelUnits.REF_LEVEL_UNITS_NISCOPE_VAL_PERCENTAGE
    )
    await CheckStatus(scope_service, set_result)

    read_result = await scope_service.read(
        vi = vi,
        channel_list = "0",
        timeout = 10000,
        num_samples = 100000
    )
    await CheckStatus(scope_service, read_result)

    # print the value of the first few samples
    values = read_result.waveform[0:10]
    print(values)

    await scope_service.close(vi = vi)
    channel.close()


loop = asyncio.get_event_loop()
asyncio.run(PerformAcquire())
