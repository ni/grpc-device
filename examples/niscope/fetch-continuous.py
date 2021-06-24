# 
# This example initiates an acquisition and continuously fetches waveform samples per channel.
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
#   > python fetch-continuous.py <server_address> <port_number> <resource_name>
# If they are not passed in as command line arguments, then by default the server address will be "localhost:31763", with "SimulatedScope" as the resource name

import grpc
import sys
import time
import numpy as np
import niscope_pb2 as niscope_types
import niscope_pb2_grpc as grpc_niscope

server_address = "localhost"
server_port = "31763"

# Resource name and options for a simulated 5164 client. Change them according to the NI-SCOPE model.
resource = "SimulatedScope"
options = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe"

channels = "0,1"
total_acquisition_time_in_seconds = 10
sample_rate_in_hz = 1000

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
        coupling = niscope_types.VerticalCoupling.VERTICAL_COUPLING_NISCOPE_VAL_DC,
        probe_attenuation = 1.0,
        enabled = True
        ))).status)

    # Configure horizontal timing.
    CheckForError(vi, (client.ConfigureHorizontalTiming(niscope_types.ConfigureHorizontalTimingRequest(
        vi = vi,
        min_sample_rate = sample_rate_in_hz,
        min_num_pts = 1,
        ref_position = 0.0,
        num_records = 1,
        enforce_realtime = True
        ))).status)

    # Configure software trigger, but never send the trigger.
    # This starts an infinite acquisition, until you call Abort or Close
    CheckForError(vi, (client.ConfigureTriggerSoftware(niscope_types.ConfigureTriggerSoftwareRequest(
        vi = vi,
        holdoff = 0.0,
        delay = 0.0
        ))).status)

    # Initiate acquisition
    CheckForError(vi, (client.InitiateAcquisition(niscope_types.InitiateAcquisitionRequest(
        vi = vi
        ))).status)

    # Allocate space for the waveform according to the max number of
    # points to fetch and the number of waveforms.
    channel_list = channels.split(',')
    total_samples = int(total_acquisition_time_in_seconds * sample_rate_in_hz)
    waveforms = [np.ndarray(total_samples, dtype=np.float64) for c in channel_list]

    # Set fetch relative to attribute.
    CheckForError(vi, (client.SetAttributeViInt32(niscope_types.SetAttributeViInt32Request(
        vi = vi,
        channel_list = "",
        attribute_id = niscope_types.NiScopeAttributes.NISCOPE_ATTRIBUTE_FETCH_RELATIVE_TO,
        value = niscope_types.NiScopeInt32AttributeValues.NISCOPE_INT32_FETCH_RELATIVE_TO_VAL_READ_POINTER
        ))).status)
 
    # Fetch continuously until all samples are acquired.
    current_pos = 0
    samples_per_fetch = 100

    try:
        while current_pos < total_samples:
            # We fetch each channel at a time so we don't have to de-interleave afterwards.
            # We do not keep the wfm_info returned from fetch.
            for channel_name, waveform in zip(channel_list, waveforms):
                fetch_response = client.Fetch(niscope_types.FetchRequest(
                    vi = vi,
                    channel_list = channel_name,
                    timeout = 500000,
                    num_samples = samples_per_fetch
                    ))
                CheckForError(vi, fetch_response.status)
                waveform[current_pos : current_pos + samples_per_fetch] = fetch_response.waveform
                print(f'Fetching channel {channel_name}\'s waveform for indices {current_pos} to {current_pos + samples_per_fetch - 1}')
            print()
            current_pos += samples_per_fetch
            
    except KeyboardInterrupt:
        pass

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