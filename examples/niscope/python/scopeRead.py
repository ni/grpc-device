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
#   > python -m grpc_tools.protoc -I. --python_out=. --grpc_python_out=. ./niDevice.proto
#   > python -m grpc_tools.protoc -I. --python_out=. --grpc_python_out=. ./niScope.proto 
#
# Update the server address and resource name and options in this file
# Run the code to read a waveform from the scope
#

import grpc
import niScope_pb2 as scopeTypes
import niScope_pb2_grpc as gRPCScope

# This is the location (ipaddress or machine name):(port) of the niDevice server
serverAddress = "localhost:50051"

# Resource name and options for a simulated 5164 scope
resource = "SimulatedScope7c632f66-e7c2-4fab-85a4-cd15c8be4130"
options = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe; MemorySize:1610612736"

# Create the communcation channel for the remote host (in this case we are connecting to a local server)
# and create a connection to the niScope service
channel = grpc.insecure_channel(serverAddress)
scope = gRPCScope.niScopeServiceStub(channel)

# Initialize the scope
initResult = scope.InitWithOptions(scopeTypes.InitWithOptionsParameters(
    resourceName=resource, 
    IDQuery=False, 
    optionString=options
    ))
vi = initResult.newVi

# Configure horizontal timing
configResult = scope.ConfigureHorizontalTiming(scopeTypes.ConfigureHorizontalTimingParameters(
    vi = vi,
    minSampleRate = 1000000,
    minNumPts = 100000,
    refPosition = 50,
    numRecords = 1,
    enforceRealtime = True
    ))

# Configure vertical timing
verticalResult = scope.ConfigureVertical(scopeTypes.ConfigureVerticalParameters(
    vi = vi,
    channelList = "0",
    range = 30.0,
    offset = 0,
    coupling = scopeTypes.val_dc,
    enabled = True,
    probeAttenuation = 1
    ))

confTriggerEdgeResult = scope.ConfigureTriggerEdge(scopeTypes.ConfigureTriggerEdgeParameters(
    vi = vi,
    triggerSource = "0",
    level = 0.00,
    triggerCoupling = scopeTypes.val_dc,
    slope = scopeTypes.val_positive
))

result = scope.SetAttributeViInt32(scopeTypes.SetAttributeViInt32Parameters(
    vi = vi,
    channelList = "0",
    attributeId = scopeTypes.attr_meas_ref_level_units,
    value = scopeTypes.attr_meas_percentage_method
))

# Read a waveform from the scope
readResult = scope.Read(scopeTypes.ReadParameters(
    vi = vi,
    channelList = "0",
    timeout = 10000,
    numSamples = 100000
    ))
values = readResult.wfm[0:10]
print(values)

scope.Close(scopeTypes.CloseParameters(
    vi = vi
    ))
