# 
# Copyright 2020 National Instruments Corp
# Licensed under the MIT license
#
# This example initiates an acquisition and continuously fetches waveform samples per channel.
#
# Getting Started:
#
# To run this example, install "NI-SCOPE Driver" on the server machine.
# Link : https://www.ni.com/en-us/support/downloads/drivers/download.ni-scope.html
#
# Install the gRPC tools for Python
#     > pip install grpcio-tools
#   if you are using anaconda
#     > conda install grpcio-tools
#
# Install numpy for arrays
#     > pip install numpy
#   if you are using anaconda
#     > conda install numpy
#
# Generate the python API from the gRPC definition (.proto) files
# Note: The snippets below assume you are executing from the examples/session folder in the repo directory. 
# If not, you will need to adjust the -I arguments so the compiler knows where to find the proto files.
#   > py -m grpc_tools.protoc -I="../../source/protobuf" --python_out=. --grpc_python_out=. session.proto
#   > py -m grpc_tools.protoc -I="../../generated/niscope" -I="../../source/protobuf" --python_out=. --grpc_python_out=. niscope.proto 
#
# Refer to the NI-SCOPE Help to determine the valid channel and resource names for your NI-SCOPE module.

import grpc
import sys
import time
import numpy as np
import niscope_pb2 as niscope_types
import niscope_pb2_grpc as grpc_niscope

any_error = False
# Checks for errors. If any, throws an exception to stop the execution.
def CheckForError (vi, status) :
    global any_error
    if(status != 0 and not any_error):
        any_error = True
        ThrowOnError (vi, status)

# Converts an error code returned by NI-SCOPE into a user-readable string
def ThrowOnError (vi, error_code):
    error_message_request = niscope_types.GetErrorMessageRequest(
        vi = vi,
        error_code = error_code
        )
    error_message_response = client.GetErrorMessage(error_message_request)
    raise Exception (error_message_response)

# Server machine's IP address and port number have to be passed as two separate command line arguments.
#   > python fetch-forever.py localhost 31763
# If not passed as command line arguments, then by default server address would be "localhost:31763"
server_address = "localhost:31763"
if len(sys.argv) == 3 :
    server_address = f"{sys.argv[1]}:{sys.argv[2]}"

# Create the communication channel for the remote host (in this case we are connecting to a local server)
# and create a connection to the NI-SCOPE service
channel = grpc.insecure_channel(server_address)
client = grpc_niscope.NiScopeStub(channel)

try :
    # Resource name and options for a simulated 5164 client. Change them according to the NI-SCOPE model.
    resource = "PXI1Slot2"
    channels = "0,1"
    options = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe"
    total_acquisition_time_in_seconds = 10
    sample_rate_in_hz = 1000

    # Open session to NI-SCOPE module with options
    init_with_options_response = client.InitWithOptions(niscope_types.InitWithOptionsRequest(
        resource_name=resource,
        id_query = False,
        option_string=options
        ))
    vi = init_with_options_response.vi
    CheckForError(vi, init_with_options_response.status)

    # Configure vertical
    voltage = 1.0
    CheckForError(vi, (client.ConfigureVertical(niscope_types.ConfigureVerticalRequest(
        vi = vi,
        channel_list = channels,
        range = voltage,
        offset = 0.0,
        coupling = niscope_types.VerticalCoupling.VERTICAL_COUPLING_NISCOPE_VAL_DC,
        probe_attenuation = 1.0,
        enabled = True
        ))).status)

    # Configure horizontal timing
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
    # points to fetch and the number of waveforms
    channel_list = channels.split(',')
    total_samples = int(total_acquisition_time_in_seconds * sample_rate_in_hz)
    waveforms = [np.ndarray(total_samples, dtype=np.float64) for c in channel_list]

    # Set fetch relative to attribute
    CheckForError(vi, (client.SetAttributeViInt32(niscope_types.SetAttributeViInt32Request(
        vi = vi,
        channel_list = "",
        attribute_id = niscope_types.NiScopeAttributes.NISCOPE_ATTRIBUTE_FETCH_RELATIVE_TO,
        value = niscope_types.FetchRelativeTo.FETCH_RELATIVE_TO_NISCOPE_VAL_READ_POINTER
        ))).status)

    # Fetch forever
    current_pos = 0
    samples_per_fetch = 100
    while current_pos < total_samples:

        # We fetch each channel at a time so we don't have to de-interleave afterwards
        # We do not keep the wfm_info returned from fetch
        for channel, waveform in zip(channel_list, waveforms):
            fetch_response = client.Fetch(niscope_types.FetchRequest(
                vi = vi,
                channel_list = channel,
                timeout = 500000,
                num_samples = samples_per_fetch
                ))
            CheckForError(vi, fetch_response.status)
            waveform[current_pos : current_pos + samples_per_fetch] = fetch_response.waveform
            print(f'Fetching channel {channel}\'s waveform for indices {current_pos} to {current_pos + samples_per_fetch - 1}')
        print()
        current_pos += samples_per_fetch

    # Close session to NI-SCOPE module.
    CheckForError(vi, (client.Close(niscope_types.CloseRequest(
        vi = vi
        ))).status)

# If NI-SCOPE API throws an exception, print the error message  
except grpc.RpcError as e:
    error_message = e.details()
    print(error_message)