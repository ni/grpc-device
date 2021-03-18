# Example communication with NI-SWITCH over gRPC
#
# Getting Started:
#
# Install the gRPC tools for Python
#     > pip install grpcio-tools
#   if you are using anaconda
#     > conda install grpcio-tools
#
# Generate the python API from the gRPC definition (.proto) files
# Note: The snippets below assume you are executing from the examples/session folder in the repo directory.
#   > python -m grpc_tools.protoc -I../../source/protobuf --python_out=. --grpc_python_out=. session.proto
#   > python -m grpc_tools.protoc -I../../generated/niswitch --python_out=. --grpc_python_out=. niswitch.proto 
#
# Run the code to initialize a session with NI-SWITCH. This example demonstrates how to scan a series of channels on a module using software scanning.
#
# Refer to the NI-SWITCH Help to determine if your module supports scanning, the scan list syntax, valid channel names and valid resource names  

import grpc
import sys
import time
import niswitch_pb2 as niswitch_types
import niswitch_pb2_grpc as grpc_niswitch

# Server machine's IP address and port number have to be passed as two separate command line arguments.
#   > python software-scanning.py 10.20.30.40 31763
# If not passed as command line arguments, then by default server address would be "localhost:31763"
server_address = "localhost:31763"
if len(sys.argv) == 3 :
    server_address = f"{sys.argv[1]}:{sys.argv[2]}"

# Resource name and topology string for a simulated 2529 module. Refer to NI-SWITCH help to find valid values for the device being used currently.
resource = "Switch1"
topology_string = "2529/2-Wire Dual 4x16 Matrix"

# Create the communcation channel for the remote host and create a connection to the NI-SWITCH service
channel = grpc.insecure_channel(server_address)
niswitch_client = grpc_niswitch.NiSwitchStub(channel)
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
    error_message_request = niswitch_types.ErrorMessageRequest(
        vi=vi,
        error_code = errorCode
        )
    error_message_response = niswitch_client.ErrorMessage(error_message_request)
    raise Exception (error_message_response.error_message)
try :
    # Open session to NI-SWITCH and set topology. Set simulate parameter to false if real hardware device is being used.
    init_with_topology_response = niswitch_client.InitWithTopology(niswitch_types.InitWithTopologyRequest(
        resource_name=resource,
        topology = topology_string,
        simulate=True,
        reset_device=False
        ))
    vi = init_with_topology_response.vi
    CheckForError(vi,init_with_topology_response.status)

    # Specify scan list. Use values that are valid for the model being used.
    CheckForError(vi, (niswitch_client.ConfigureScanList(niswitch_types.ConfigureScanListRequest(
        vi=vi,
        scanlist = "b0r1->b0c1;b0r1->b0c2;b0r2->b0c3",
        scan_mode = niswitch_types.ScanMode.SCAN_MODE_NISWITCH_VAL_BREAK_BEFORE_MAKE
        ))).status)

    # Configures the trigger to be software trigger.
    CheckForError(vi, (niswitch_client.ConfigureScanTrigger(niswitch_types.ConfigureScanTriggerRequest(
        vi=vi,
        trigger_input = niswitch_types.TriggerInput.TRIGGER_INPUT_NISWITCH_VAL_SOFTWARE_TRIG,
        scan_advanced_output = niswitch_types.ScanAdvancedOutput.SCAN_ADVANCED_OUTPUT_NISWITCH_VAL_NONE
        ))).status)

    # Loop through scan list continuously
    CheckForError(vi, (niswitch_client.SetContinuousScan(niswitch_types.SetContinuousScanRequest(
        vi=vi,
        continuous_scan = True
        ))).status)

    #Initiate scanning
    CheckForError(vi, (niswitch_client.InitiateScan(niswitch_types.InitiateScanRequest(
        vi=vi
        ))).status)

    #Send software trigger to module in a loop
    for x in range(number_of_triggers):
        #Wait for 500 ms
        time.sleep(0.5)
        CheckForError(vi, (niswitch_client.SendSoftwareTrigger(niswitch_types.SendSoftwareTriggerRequest(
            vi=vi
            ))).status)
        number_of_triggers = number_of_triggers - 1    

    #Abort Scanning
    CheckForError(vi, (niswitch_client.AbortScan(niswitch_types.AbortScanRequest(
        vi=vi
        ))).status)

    # Close NI-SWITCH session.
    CheckForError(vi, (niswitch_client.Close(niswitch_types.CloseRequest(
        vi = vi
        ))).status)

# If NI-SWITCH API throws an exception, print the error message  
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE :
        error_message = f"Failed to connect to server on {server_address}"
    print(f"{error_message}") 