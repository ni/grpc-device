###############################################################
#
# Copyright 2020 National Instruments
#
# Licensed under the MIT license
#
# This is an example of using the niScope driver through gRPC
# Tested with a 100 kHz tone input to channel 0
# The gRPC API is built from the C API.  NI-SCOPE documentation is found:
# C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niScope\Documentation\scopeFunc.chm
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

import grpc
import niScope_pb2 as scopeTypes
import niScope_pb2_grpc as gRPCScope
import matplotlib.pyplot as plt
import time

# This is the location (ipaddress or machine name):(port) of the niDevice server
serverAddress = "localhost:50051"

# Resource name and options for a simulated 5164 scope
# resource = "SimulatedScope7c632f66-e7c2-4fab-85a4-cd15c8be4130"
# options = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe; MemorySize:1610612736"

# Or use real hardware
resource = "Scope"
options = ""

# Create the communication channel for the remote host (in this case we are connecting to a local server)
# and create a connection to the niScope service
channel = grpc.insecure_channel(serverAddress)
scope = gRPCScope.niScopeServiceStub(channel)

# Initialize the scope
initResult = scope.Init(scopeTypes.InitParameters(
    sessionName="0",
    resourceName=resource,
    IDQuery=False,
    resetDevice=False
))
vi = initResult.vi
print("Initialize Status: " + str(initResult.status))

#############################################################################################
# Configure Vertical
verticalResult = scope.ConfigureVertical(scopeTypes.ConfigureVerticalParameters(
    vi=vi,
    channelList="0",
    range=10.0,
    offset=0,
    coupling=scopeTypes.val_dc,
    enabled=True,
    probeAttenuation=1
    ))
print("Configure Vertical Status:" + str(verticalResult.status))

##############################################################################################
# Configure Horizontal Timing
configResult = scope.ConfigureHorizontalTiming(scopeTypes.ConfigureHorizontalTimingParameters(
    vi = vi,
    minSampleRate = 1000000,
    minNumPts = 1000,
    refPosition = 50,
    numRecords = 1,
    enforceRealtime = True
    ))
print("Configure Horizontal Status: " + str(configResult.status))

##############################################################################################
# Setup an Edge Trigger
result = scope.SetAttributeViInt32(scopeTypes.SetAttributeViInt32Parameters(
    vi=vi,
    channelList="0",
    attributeId=scopeTypes.attr_trigger_type,
    value=scopeTypes.val_edge_trigger
    ))

confTriggerEdgeResult = scope.ConfigureTriggerEdge(scopeTypes.ConfigureTriggerEdgeParameters(
    vi=vi,
    triggerSource='0',
    level=0.00,
    slope=scopeTypes.val_positive,
    triggerCoupling=scopeTypes.val_dc,
    holdoff=0.0
))
print("Configure Trigger Edge Status: " + str(confTriggerEdgeResult.status))

result = scope.SetAttributeViInt32(scopeTypes.SetAttributeViInt32Parameters(
    vi = vi,
    channelList = "0",
    attributeId = scopeTypes.attr_meas_ref_level_units,
    value = scopeTypes.attr_meas_percentage_method
))

##############################################################################################
# Set Reference Level Units and Chan. Based Ref
# result = scope.SetAttributeViReal64(scopeTypes.SetAttributeViReal64Parameters(
#     vi=vi,
#     # channelList="0",
#     attributeId=scopeTypes.attr_meas_high_ref,
#     value=90.0
# ))
# print("Set High Ref: " + str(result.status))
#
# result = scope.SetAttributeViReal64(scopeTypes.SetAttributeViReal64Parameters(
#     vi=vi,
#     # channelList="0",
#     attributeId=scopeTypes.attr_meas_mid_ref,
#     value=50
# ))
# print("Set Mid Ref: " + str(result.status))
#
# result = scope.SetAttributeViReal64(scopeTypes.SetAttributeViReal64Parameters(
#     vi=vi,
#     # channelList="0",
#     attributeId=scopeTypes.attr_meas_low_ref,
#     value=10.0
# ))
# print("Set Low Ref: " + str(result.status))

##############################################################################################
# Read the Result

# Setup a plot to draw the captured waveform
fig = plt.gcf()
fig.show()
fig.canvas.draw()

print("\nReading values in loop. CTRL+C to stop.\n")
try:
    while True:
        # Clear the plot and setup the axis
        plt.clf()
        plt.axis([0, 50, -1, 1])
        # Read a waveform from the scope
        readResult = scope.Read(scopeTypes.ReadParameters(
            vi=vi,
            channelList="0",
            timeout=1,
            numSamples=10000
        ))
        values = readResult.wfm[0:10]
        print(values)

        # Update the plot with the new waveform
        plt.plot(readResult.wfm[0:100])
        fig.canvas.draw()
        plt.pause(0.001)

        # Fetch the measured average frequency
        fetchResult = scope.FetchMeasurementStats(scopeTypes.FetchMeasurementStatsParameters(
            vi=vi,
            channelList="0",
            timeout=1,
            scalarMeasFunction=scopeTypes.val_average_frequency
        ))
        # print("Fetch Status: " + str(fetchResult.status))
        print("Average Frequency: " + str("%.2f" % round(fetchResult.result[0], 2)) + " Hz")
        print("")

        time.sleep(3)
except KeyboardInterrupt:
    pass

##############################################################################################
# Close
scope.Close(scopeTypes.CloseParameters(
    vi = vi
    ))
