# 
# This example initiates an acquisition and fetches a waveform for each specified channel.
#
# The gRPC API is built from the C API.  NI-SCOPE documentation is installed with the driver at:
# C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niScope\Documentation\English\Digitizers.chm
#
# A version of this .chm is available online at:
# Link: https://zone.ni.com/reference/en-XX/help/370592AB-01/
#
# Getting Started:
#
# To run this example, install "NI-SCOPE Driver" on the server machine.
# Link : https://www.ni.com/en-us/support/downloads/drivers/download.ni-scope.html
#
# For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC Client" wiki page.
# Link: https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client
#
# Refer to the NI-SCOPE gRPC Wiki to determine the valid channel and resource names for your NI-SCOPE module.
# Link : https://github.com/ni/grpc-device/wiki/NI-SCOPE-C-Function-Reference
#
# Running from command line:
#
# Server machine's IP address, port number, and resource name can be passed as separate command line arguments.
#   > python fetch.py <server_address> <port_number> <resource_name>
# If they are not passed in as command line arguments, then by default the server address will be "localhost:31763", with "SimulatedScope" as the resource name

import grpc
import sys
import time
import niscope_pb2 as niscope_types
import niscope_pb2_grpc as grpc_niscope

server_address = "localhost"
server_port = "31763"

# Resource name and options for a simulated 5164 client. Change them according to the NI-SCOPE model.
resource = "SimulatedScope"
options = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe"

channels = "0"

any_error = False
# Checks for errors. If any, throws an exception to stop the execution.
def CheckForError (vi, status) :
    global any_error
    if(status != 0 and not any_error):
        any_error = True
        ThrowOnError (vi, status)

# Converts an error code returned by NI-SCOPE into a user-readable string.
def ThrowOnError (vi, error_code):
    error_message_request = niscope_types.GetErrorMessageRequest(
        vi = vi,
        error_code = error_code
        )
    error_message_response = client.GetErrorMessage(error_message_request)
    raise Exception (error_message_response.error_message)

# Read in cmd args
if len(sys.argv) >= 2:
    server_address = sys.argv[1]
if len(sys.argv) >= 3:
    server_port = sys.argv[2]
if len(sys.argv) >= 4:
    resource = sys.argv[3]
    options = ""

# Create the communication channel for the remote host and create a connection to the NI-SCOPE service.
channel = grpc.insecure_channel(f"{server_address}:{server_port}")
client = grpc_niscope.NiScopeStub(channel)

try :
    # Open session to NI-SCOPE module with options.
    init_with_options_response = client.InitWithOptions(niscope_types.InitWithOptionsRequest(
        resource_name=resource,
        id_query = False,
        option_string=options
        ))
    vi = init_with_options_response.vi
    CheckForError(vi, init_with_options_response.status)

    # Configure vertical.
    voltage = 10.0
    CheckForError(vi, (client.ConfigureVertical(niscope_types.ConfigureVerticalRequest(
        vi = vi,
        channel_list = channels,
        range = voltage,
        offset = 0.0,
        coupling = niscope_types.VerticalCoupling.VERTICAL_COUPLING_NISCOPE_VAL_AC,
        probe_attenuation = 1.0,
        enabled = True
        ))).status)

    # Configure horizontal timing.
    samples = 1000
    CheckForError(vi, (client.ConfigureHorizontalTiming(niscope_types.ConfigureHorizontalTimingRequest(
        vi = vi,
        min_sample_rate = 50000000,
        min_num_pts = samples,
        ref_position = 50.0,
        num_records = 1,
        enforce_realtime = True
        ))).status)

    # Initiate acquisition.
    CheckForError(vi, (client.InitiateAcquisition(niscope_types.InitiateAcquisitionRequest(
        vi = vi
        ))).status)

    # Fetch waveforms.
    fetch_response = client.Fetch(niscope_types.FetchRequest(
        vi = vi,
        channel_list = channels,
        timeout = 10000,
        num_samples = samples
        ))
    CheckForError(vi, fetch_response.status)
    waveforms = fetch_response.waveform

    # Print waveform results.
    for i in range(len(waveforms)):
        print(f'Waveform {i} information:')
        print(f'{waveforms[i]}\n')

# If NI-SCOPE API throws an exception, print the error message.
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE :
        error_message = f"Failed to connect to server on {server_address}:{server_port}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = "The operation is not implemented or is not supported/enabled in this service"
    print(f"{error_message}")

finally:
    if('vi' in vars() and vi.id != 0):
        # close the session.
        CheckForError(vi, (client.Close(niscope_types.CloseRequest(
            vi = vi
        ))).status)