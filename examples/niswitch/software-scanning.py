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
# Run the code to initialize a session with Switch. This example demonstrates how to scan a series of channels on a switch using software scanning.
#
# Refer to the NI Switches Help to determine if your switch supports scanning, the scan list syntax, 
# and the valid channel names and valid resource names for your switch module.

import grpc
import time
import niSwitch_pb2 as switchTypes
import niSwitch_pb2_grpc as gRPCSwitch

# This is the location (ipaddress or machine name):(port) of the niDevice server
serverAddress = "localhost:31763"

# Resource name and options for a simulated 2529 switch. Change them according to the switch model.
resource = "Switch1"
channelName = "0"
options = "Simulate=1, DriverSetup=Model:2529; BoardType:PXI"

# Or you can use real hardware
# resource = "2529"
# channelName="0"
# options = ""

# Create the communcation channel for the remote host (in this case we are connecting to a local server)
# and create a connection to the niSwitch service
channel = grpc.insecure_channel(serverAddress)
switch = gRPCSwitch.niSwitchServiceStub(channel)
numberOfTriggers = 5
anyError = False

# Checks for errors. If any, throws an exception to stop the execution.
def CheckForError (vi, status) :
    global anyError
    if(status != 0 and not anyError):
        anyError = True
        ThrowOnError (vi, status)

# Converts an error code returned by NI-SWITCH into a user-readable string
def ThrowOnError (vi, errorCode):
    errorMessageRequest = switchTypes.ErrorMessageRequest(
        vi=vi,
        errorCode = errorCode
        )
    errorMessageResponse = switch.ErrorMessage(errorMessageRequest)
    raise Exception (errorMessageResponse)

# Open session to switch module and set topology
initWithTopologyResponse = switch.InitWithTopology(switchTypes.InitWithTopologyRequest(
    resourceName=resource,
    topology = switchTypes.SwitchTopology(),
    simulate=True,
    resetDevice=False
    ))
vi = initWithTopologyResponse.newVi
CheckForError(vi,initWithTopologyResponse.status)

# Specify scan list. Use values that are valid for the switch model being used.
CheckForError(vi, (switch.ConfigureScanList(switchTypes.ConfigureScanListRequest(
    vi=vi,
    scanList = "b0r1->b0c1;b0r1->b0c2;b0r2->b0c3;",
    scanMode = 0
    ))).status)

# Configures the trigger to be software trigger.
CheckForError(vi, (switch.ConfigureScanTrigger(switchTypes.ConfigureScanTriggerRequest(
    vi=vi,
    triggerInput = 3
    ))).status)

# Loop through scan list continuously
CheckForError(vi, (switch.SetContinuousScan(switchTypes.SetContinuousScanRequest(
    vi=vi,
    continuousScan = True
    ))).status)

#Initiate scanning
CheckForError(vi, (switch.InitiateScan(switchTypes.InitiateScanRequest(
    vi=vi
    ))).status)

#Send software trigger to switch module in a loop
for x in range(numberOfTriggers):
    #Wait for 500 ms
    time.sleep(0.5)
    CheckForError(vi, (switch.SendSoftwareTrigger(switchTypes.SendSoftwareTriggerRequest(
        vi=vi
        ))).status)
    numberOfTriggers = numberOfTriggers - 1    

#Abort Scanning
CheckForError(vi, (switch.AbortScan(switchTypes.AbortScanRequest(
    vi=vi
    ))).status)

# Close session to switch module.
CheckForError(vi, (switch.Close(switchTypes.CloseRequest(
    vi = vi
    ))).status)