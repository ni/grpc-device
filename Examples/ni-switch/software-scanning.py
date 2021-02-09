# Example communication with niSwitch over gRPC
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
# Generate the python API from the gRPC definition (.proto) files
#   > py -m grpc_tools.protoc -I../../ --python_out=. --grpc_python_out=. niDevice.proto
#   > py -m grpc_tools.protoc -I../../ --python_out=. --grpc_python_out=. niSwitch.proto 
#
# Update the server address and resource name and options in this file
# Run the code to initialize a session with Switch

import grpc
import niSwitch_pb2 as switchTypes
import niSwitch_pb2_grpc as gRPCSwitch

# This is the location (ipaddress or machine name):(port) of the niDevice server
serverAddress = "localhost:50051"

# Resource name and options for a simulated 2571 switch. Change them according to the switch model.
resource = "switch1"
channelName = "0"
options = "Simulate=1, DriverSetup=Model:2571; BoardType:PXI"

# Or you can use real hardware
# resource = "2571"
# channelName="0"
# options = ""

# Create the communcation channel for the remote host (in this case we are connecting to a local server)
# and create a connection to the niSwitch service
channel = grpc.insecure_channel(serverAddress)
switch = gRPCSwitch.niSwitchServiceStub(channel)

# Open session to switch module and set topology
initWithTopologyResult = switch.InitWithTopology(switchTypes.InitWithTopologyParameters(
    resourceName=resource, 
    topology=NISWITCH_TOPOLOGY_CONFIGURED_TOPOLOGY,
    simulate=True,
    resetDevice=False
    ))
vi = initWithTopologyResult.vi
print("Initialize With Topology Status: " + str(initWithTopologyResult.status))

# Specify scan list
configureScanListResult = switch.ConfigureScanList(switchTypes.ConfigureScanListParameters(
    vi=vi,
    scanList = "ch0:4->com0;",
    scanMode = 0
    ))
print("configure scan list Status: " + str(configureScanListResult.status))

# Select software trigger
configureScanTriggerResult = switch.ConfigureScanTrigger(switchTypes.ConfigureScanTriggerParameters(
    vi=vi
    ))
print("Configure Scan Trigger Status: " + str(configureScanTriggerResult.status))


# Loop through scan list continuously
setContinuousScanResult = switch.SetContinuousScan(switchTypes.SetContinuousScanParameters(
    vi=vi
    ))
print("Set Continuous Scan Status: " + str(setContinuousScanResult.status))

#Initiate scanning
initiateScanResult = switch.InitiateScanEnabled(switchTypes.InitiateScanParameters(
    vi=vi
    ))
print("InitiateScan Status: " + str(initiateScanResult.status))


#Send software trigger to switch module in a loop
while (count) :
    sendSoftwareTriggerResult = switch.SendSoftwareTrigger(switchTypes.SendSoftwareTriggerParameters(
    vi=vi
    ))
    print("Send Software Trigger Status: " + str(sendSoftwareTriggerResult.status))
    if (sendSoftwareTriggerResult.status == 0) :
        break
    count = count - 1    

#Set time out
time.sleep(10)

#Abort Generation
abortScanResult = switch.AbortScan(switchTypes.AbortGenerationParameters(
    vi=vi
    ))
print("Abort Scan Status: " + str(abortScanResult.status))

# Close session to switch module.
switch.Close(switchTypes.CloseParameters(
    vi = vi
    ))