# 
# Copyright 2020 National Instruments Corp
# Licensed under the MIT license
#
# This example initiates an acquisition and fetches a waveform for each specified channel.
#
# Getting Started:
#
# Install the gRPC tools for Python
#     > pip install grpcio-tools
#   if you are using anaconda
#     > conda install grpcio-tools
#
# Generate the python API from the gRPC definition (.proto) files
#   > py -m grpc_tools.protoc -I="../../source/protobuf" --python_out=. --grpc_python_out=. session.proto
#   > py -m grpc_tools.protoc -I="../../generated/niscope" -I="../../source/protobuf" --python_out=. --grpc_python_out=. niscope.proto 
#
# Refer to the NI Scope Help to determine the valid channel and resource names for your Scope module.

import grpc
import time
import niscope_pb2 as niscope_types
import niscope_pb2_grpc as grpc_niscope

anyError = False
# Checks for errors. If any, throws an exception to stop the execution.
def CheckForError (vi, status) :
    global anyError
    if(status != 0 and not anyError):
        anyError = True
        ThrowOnError (vi, status)

# Converts an error code returned by NI-Scope into a user-readable string
def ThrowOnError (vi, errorCode):
    errorMessageRequest = niscope_types.GetErrorMessageRequest(
        vi = vi,
        error_code = errorCode
        )
    errorMessageResponse = client.GetErrorMessage(errorMessageRequest)
    raise Exception (errorMessageResponse)

# Create the communcation channel for the remote host (in this case we are connecting to a local server)
# and create a connection to the niScope service
serverAddress = "localhost:31763"
channel = grpc.insecure_channel(serverAddress)
client = grpc_niscope.NiScopeStub(channel)

try :
    # Resource name and options for a simulated 5164 client. Change them according to the scope model.
    resource = "PXI1Slot2"
    channels = "0"
    options = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe"

    # Open session to Scope module with options
    initWithOptionsResponse = client.InitWithOptions(niscope_types.InitWithOptionsRequest(
        resource_name=resource,
        id_query = False,
        option_string=options
        ))
    vi = initWithOptionsResponse.vi
    CheckForError(vi, initWithOptionsResponse.status)

    # Configure vertical
    voltage = 1.0
    CheckForError(vi, (client.ConfigureVertical(niscope_types.ConfigureVerticalRequest(
        vi = vi,
        channel_list = channels,
        range = voltage,
        offset = 0.0,
        coupling = niscope_types.VerticalCoupling.VERTICAL_COUPLING_NISCOPE_VAL_AC,
        probe_attenuation = 1.0,
        enabled = True
        ))).status)

    # Configure horizontal timing
    samples = 1000
    CheckForError(vi, (client.ConfigureHorizontalTiming(niscope_types.ConfigureHorizontalTimingRequest(
        vi = vi,
        min_sample_rate = 50000000,
        min_num_pts = samples,
        ref_position = 50.0,
        num_records = 1,
        enforce_realtime = True
        ))).status)

    # Initiate acquisition
    CheckForError(vi, (client.InitiateAcquisition(niscope_types.InitiateAcquisitionRequest(
        vi = vi
        ))).status)

    # Fetch waveforms
    FetchResponse = client.Fetch(niscope_types.FetchRequest(
        vi = vi,
        channel_list = channels,
        timeout = 10000,
        num_samples = samples
        ))
    CheckForError(vi, FetchResponse.status)
    waveforms = FetchResponse.waveform

    # Print waveform results
    for i in range(len(waveforms)):
        print(f'Waveform {i} information:')
        print(f'{waveforms[i]}\n')

    # Close session to Scope module.
    CheckForError(vi, (client.Close(niscope_types.CloseRequest(
        vi = vi
        ))).status)

# If NiScope API throws an exception, print the error message  
except grpc.RpcError as e:
    error_message = e.details()
    print(f'{error_message}')