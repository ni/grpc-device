# 
# Copyright 2020 National Instruments
# Licensed under the MIT license
#
# This example initiates an acquisition and continuously fetches waveform samples per channel.
#
# Getting Started:
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
#   > py -m grpc_tools.protoc -I="../../source/protobuf" --python_out=. --grpc_python_out=. session.proto
#   > py -m grpc_tools.protoc -I="../../generated/niscope" -I="../../source/protobuf" --python_out=. --grpc_python_out=. niclient.proto 
#
# Refer to the NI Scope Help to determine the valid channel and resource names for your Scope module.

import grpc
import time
import numpy as np
import niscope_pb2 as scope_types
import niscope_pb2_grpc as grpc_niscope

# Resource name and options for a simulated 5164 client. Change them according to the scope model.
resource = "PXI1Slot2"
channels = "0,1"
options = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe"
total_acquisition_time_in_seconds = 10
sample_rate_in_hz = 1000

# Or you can use real hardware
# resource = "2529"
# channelName="0"
# options = ""

# Create the communcation channel for the remote host (in this case we are connecting to a local server)
# and create a connection to the niScope service
serverAddress = "localhost:31763"
channel = grpc.insecure_channel(serverAddress)
client = grpc_niscope.NiScopeStub(channel)
anyError = False

# Checks for errors. If any, throws an exception to stop the execution.
def CheckForError (vi, status) :
    global anyError
    if(status != 0 and not anyError):
        anyError = True
        ThrowOnError (vi, status)

# Converts an error code returned by NI-Scope into a user-readable string
def ThrowOnError (vi, errorCode):
    errorMessageRequest = scope_types.GetErrorMessageRequest(
        vi = vi,
        error_code = errorCode
        )
    errorMessageResponse = client.GetErrorMessage(errorMessageRequest)
    raise Exception (errorMessageResponse)

# Open session to Scope module with options
initWithOptionsResponse = client.InitWithOptions(scope_types.InitWithOptionsRequest(
    resource_name=resource,
    id_query = False,
    option_string=options
    ))
vi = initWithOptionsResponse.vi
CheckForError(vi, initWithOptionsResponse.status)

# Configure vertical
voltage = 1.0
CheckForError(vi, (client.ConfigureVertical(scope_types.ConfigureVerticalRequest(
    vi = vi,
    channel_list = channels,
    range = voltage,
    offset = 0.0,
    coupling = scope_types.VerticalCoupling.VERTICAL_COUPLING_NISCOPE_VAL_DC,
    probe_attenuation = 1.0,
    enabled = True
    ))).status)

# Configure horizontal timing
CheckForError(vi, (client.ConfigureHorizontalTiming(scope_types.ConfigureHorizontalTimingRequest(
    vi = vi,
    min_sample_rate = sample_rate_in_hz,
    min_num_pts = 1,
    ref_position = 0.0,
    num_records = 1,
    enforce_realtime = True
    ))).status)

# Configure software trigger, but never send the trigger.
# This starts an infinite acquisition, until you call Abort or Close
CheckForError(vi, (client.ConfigureTriggerSoftware(scope_types.ConfigureTriggerSoftwareRequest(
    vi = vi,
    holdoff = 0.0,
    delay = 0.0
    ))).status)

# Initiate acquisition
CheckForError(vi, (client.InitiateAcquisition(scope_types.InitiateAcquisitionRequest(
    vi = vi
    ))).status)

# Allocate space for the waveform according to the max number of
# points to fetch and the number of waveforms
channel_list = channels.split(',')
total_samples = int(total_acquisition_time_in_seconds * sample_rate_in_hz)
waveforms = [np.ndarray(total_samples, dtype=np.float64) for c in channel_list]

totalPointsFetched = 0

# Set fetch relative to attribute
CheckForError(vi, (client.SetAttributeViInt32(scope_types.SetAttributeViInt32Request(
  vi = vi,
  channel_list = "",
  attribute_id = scope_types.NiScopeAttributes.NISCOPE_ATTRIBUTE_FETCH_RELATIVE_TO,
  value = scope_types.FetchRelativeTo.FETCH_RELATIVE_TO_NISCOPE_VAL_READ_POINTER
  ))).status)

# Fetch forever
current_pos = 0
samples_per_fetch = 100
while current_pos < total_samples:

  # We fetch each channel at a time so we don't have to de-interleave afterwards
  # We do not keep the wfm_info returned from fetch
  for channel, waveform in zip(channel_list, waveforms):
    FetchResponse = client.Fetch(scope_types.FetchRequest(
        vi = vi,
        channel_list = channel,
        timeout = 500000,
        num_samples = samples_per_fetch
        ))
    CheckForError(vi, FetchResponse.status)
    waveforms[current_pos:current_pos + samples_per_fetch] = FetchResponse.waveform
    print(f'Filling indexes {current_pos} to {current_pos + samples_per_fetch} of waveform for channel {channel}')
  print()
  current_pos += samples_per_fetch

# Close session to Scope module.
CheckForError(vi, (client.Close(scope_types.CloseRequest(
    vi = vi
    ))).status)