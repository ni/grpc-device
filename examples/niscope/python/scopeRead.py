#
# Example communication with niScope over gRPC
#
# Copyright 2020 National Instruments
# Licensed under the MIT license
#
# Getting Started:
#
# Install the gRPC tools for Python
#     > pip install grpcio-tools
#   if you are using anaconda
#     > conda install grpcio-tools
#
# Generate the python API from the gRPC definition (.ptoto) files
#   > python -m grpc_tools.protoc -I. --python_out=. --grpc_python_out=. ./session.proto
#   > python -m grpc_tools.protoc -I. --python_out=. --grpc_python_out=. ./niscope.proto 
#
# Update the server address and resource name and options in this file
# Run the code to read a waveform from the scope
#

import grpc
import niScope_pb2 as scope_types
import niScope_pb2_grpc as gRPC_scope

def check_status(scope_service, result):
    if (result.status != 0):
        error = scope_service.GetError(scope_types.GetErrorRequest())
        print(error.description)

# This is the location (ipaddress or machine name):(port) of the niDevice server
server_address = "localhost:31763"

# Resource name and options for a simulated 5164 scope
resource = "SimulatedScope7c632f66-e7c2-4fab-85a4-cd15c8be4130"
options = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe; MemorySize:1610612736"

# Create the communcation channel for the remote host (in this case we are connecting to a local server)
# and create a connection to the niScope service
channel = grpc.insecure_channel(server_address)
scope_service = gRPC_scope.NiScopeStub(channel)

# Initialize the scope
init_result = scope_service.InitWithOptions(scope_types.InitWithOptionsRequest(
    session_name = "demo",
    resource_name = resource, 
    id_query = False, 
    option_string = options
    ))
vi = init_result.vi
check_status(scope_service, init_result)

# Configure horizontal timing
config_result = scope_service.ConfigureHorizontalTiming(scope_types.ConfigureHorizontalTimingRequest(
    vi = vi,
    min_sample_rate = 1000000,
    min_num_pts = 100000,
    ref_position = 50,
    num_records = 1,
    enforce_realtime = True
))
check_status(scope_service, config_result)

# Configure vertical timing
vertical_result = scope_service.ConfigureVertical(scope_types.ConfigureVerticalRequest(
    vi = vi,
    channel_list = "0",
    range = 30.0,
    offset = 0,
    coupling = scope_types.VerticalCoupling.VERTICAL_COUPLING_NISCOPE_VAL_DC,
    enabled = True,
    probe_attenuation = 1
))
check_status(scope_service, vertical_result)

confTrigger_edge_result = scope_service.ConfigureTriggerEdge(scope_types.ConfigureTriggerEdgeRequest(
    vi = vi,
    trigger_source = "0",
    level = 0.00,
    trigger_coupling = scope_types.TriggerCoupling.TRIGGER_COUPLING_NISCOPE_VAL_DC,
    slope = scope_types.TriggerSlope.TRIGGER_SLOPE_NISCOPE_VAL_POSITIVE
))
check_status(scope_service, confTrigger_edge_result)

result = scope_service.SetAttributeViInt32(scope_types.SetAttributeViInt32Request(
    vi = vi,
    channel_list = "0",
    attribute_id = scope_types.NiScopeAttributes.NISCOPE_ATTRIBUTE_MEAS_REF_LEVEL_UNITS,
    value = scope_types.RefLevelUnits.REF_LEVEL_UNITS_NISCOPE_VAL_VOLTS
))
check_status(scope_service, result)

# Read a waveform from the scope
read_result = scope_service.Read(scope_types.ReadRequest(
    vi = vi,
    channel_list = "0",
    timeout = 10000,
    num_samples = 100000
))
check_status(scope_service, read_result)
values = read_result.waveform[0:10]
print(values)

scope_service.Close(scope_types.CloseRequest(
    vi = vi
))
