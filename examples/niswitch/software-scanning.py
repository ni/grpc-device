# Example communication with niSwitch over gRPC
#
# Getting Started:
#
# Install the gRPC tools for Python
#     > pip install grpcio-tools
#   if you are using anaconda
#     > conda install grpcio-tools
#
# Generate the python API from the gRPC definition (.proto) files
#   > py -m grpc_tools.protoc -I. --python_out=. --grpc_python_out=. session.proto
#   > py -m grpc_tools.protoc -I. --python_out=. --grpc_python_out=. niswitch.proto 
#
# Run the code to initialize a session with Switch. This example demonstrates how to scan a series of channels on a switch using software scanning.
#
# Refer to the NI Switches Help to determine if your switch supports scanning, the scan list syntax, 
# and the valid channel names and valid resource names for your switch module.

import grpc
import sys
import time
import niswitch_pb2 as switchTypes
import niswitch_pb2_grpc as gRPCSwitch

# Server machine's IP address and port number have to be passed as two separate command line arguments.
#   > python software-scanning.py localhost 31763
# If not passed as command line arguments, then by default server address would be "localhost:31763"
server_address = "localhost:31763"
if len(sys.argv) == 3 :
    server_address = f"{sys.argv[1]}:{sys.argv[2]}"

# Resource name and options for a simulated 2529 switch. Change them according to the switch model.
resource = "Switch1"
channel_name = "0"
options = "Simulate=1, DriverSetup=Model:2529; BoardType:PXI"

# Or you can use real hardware
# resource = "2529"
# channelName="0"
# options = ""

# Create the communcation channel for the remote host (in this case we are connecting to a local server)
# and create a connection to the niSwitch service
channel = grpc.insecure_channel(server_address)
switch = gRPCSwitch.NiSwitchStub(channel)
number_of_triggers = 5
anyError = False

# Checks for errors. If any, throws an exception to stop the execution.
def CheckForError (vi, status) :
    global anyError
    if(status != 0 and not anyError):
        anyError = True
        ThrowOnError (vi, status)

# Converts an error code returned by NI-SWITCH into a user-readable string
def ThrowOnError (vi, errorCode):
    error_message_request = switchTypes.ErrorMessageRequest(
        vi=vi,
        error_code = errorCode
        )
    error_message_response = switch.ErrorMessage(error_message_request)
    raise Exception (error_message_response.error_message)
try :
    # Open session to switch module and set topology. Refer to NI-SWITCH help to find valid values for topology.
    init_with_topology_response = switch.InitWithTopology(switchTypes.InitWithTopologyRequest(
        resource_name=resource,
        topology = "2529/2-Wire Dual 4x16 Matrix",
        simulate=True,
        reset_device=False
        ))
    vi = init_with_topology_response.vi
    CheckForError(vi,init_with_topology_response.status)

    # Specify scan list. Use values that are valid for the switch model being used.
    CheckForError(vi, (switch.ConfigureScanList(switchTypes.ConfigureScanListRequest(
        vi=vi,
        scanlist = "b0r1->b0c1;b0r1->b0c2;b0r2->b0c3",
        scan_mode = switchTypes.ScanMode.SCAN_MODE_NISWITCH_VAL_BREAK_BEFORE_MAKE
        ))).status)

    # Configures the trigger to be software trigger.
    CheckForError(vi, (switch.ConfigureScanTrigger(switchTypes.ConfigureScanTriggerRequest(
        vi=vi,
        trigger_input = switchTypes.TriggerInput.TRIGGER_INPUT_NISWITCH_VAL_SOFTWARE_TRIG,
        scan_advanced_output = switchTypes.ScanAdvancedOutput.SCAN_ADVANCED_OUTPUT_NISWITCH_VAL_NONE
        ))).status)

    # Loop through scan list continuously
    CheckForError(vi, (switch.SetContinuousScan(switchTypes.SetContinuousScanRequest(
        vi=vi,
        continuous_scan = True
        ))).status)

    #Initiate scanning
    CheckForError(vi, (switch.InitiateScan(switchTypes.InitiateScanRequest(
        vi=vi
        ))).status)

    #Send software trigger to switch module in a loop
    for x in range(number_of_triggers):
        #Wait for 500 ms
        time.sleep(0.5)
        CheckForError(vi, (switch.SendSoftwareTrigger(switchTypes.SendSoftwareTriggerRequest(
            vi=vi
            ))).status)
        number_of_triggers = number_of_triggers - 1    

    #Abort Scanning
    CheckForError(vi, (switch.AbortScan(switchTypes.AbortScanRequest(
        vi=vi
        ))).status)

    # Close session to switch module.
    CheckForError(vi, (switch.Close(switchTypes.CloseRequest(
        vi = vi
        ))).status)

# If NiSwitch API throws an exception, print the error message  
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE :
        error_message = f"Failed to connect to server on {server_address}"
    print(f"{error_message}") 