r"""Initiate an acquisition and continuously fetches waveform samples per channel.

The gRPC API is built from the C API. NI-SCOPE documentation is installed with the driver at:
  C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niScope\Documentation\English\Digitizers.chm

A version of this .chm is available online at:
  https://zone.ni.com/reference/en-XX/help/370592AB-01/

Getting Started:

To run this example, install "NI-SCOPE Driver" on the server machine:
  https://www.ni.com/en-us/support/downloads/drivers/download.ni-scope.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-SCOPE gRPC Wiki to determine the valid channel and resource names for your NI-SCOPE
module:
  https://github.com/ni/grpc-device/wiki/NI-SCOPE-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and resource name can be passed as separate command line
arguments.
  > python fetch-continuous.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedScope" as the resource name.
"""

import sys

import grpc
import niscope_pb2 as niscope_types
import niscope_pb2_grpc as grpc_niscope
import numpy as np

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"

# Resource name and options for a simulated 5164 client. Change them according to the NI-SCOPE
# model.
RESOURCE = "SimulatedScope"
OPTIONS = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe"

CHANNELS = "0,1"
TOTAL_ACQUISITION_TIME_IN_SECONDS = 10
SAMPLE_RATE_IN_HZ = 1000

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    RESOURCE = sys.argv[3]
    OPTIONS = ""

# Create the communication channel for the remote host and create a connection to the NI-SCOPE
# service.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
client = grpc_niscope.NiScopeStub(channel)


def check_for_error(vi, status):
    """Raise an exception if the status indicates an error."""
    if status != 0:
        error_message_response = client.ErrorMessage(
            niscope_types.ErrorMessageRequest(vi=vi, error_code=status)
        )
        raise Exception(error_message_response.error_message)


def check_for_initialization_error(response):
    """Raise an exception if an error was returned from Initialize."""
    if response.status < 0:
        raise RuntimeError(f"Error: {response.error_message or response.status}")
    if response.status > 0:
        sys.stderr.write(f"Warning: {response.error_message or response.status}\n")


try:
    # Open session to NI-SCOPE module with options.
    init_with_options_response = client.InitWithOptions(
        niscope_types.InitWithOptionsRequest(
            resource_name=RESOURCE, id_query=False, option_string=OPTIONS
        )
    )
    vi = init_with_options_response.vi
    check_for_initialization_error(init_with_options_response)

    # Configure vertical.
    voltage = 10.0
    check_for_error(
        vi,
        (
            client.ConfigureVertical(
                niscope_types.ConfigureVerticalRequest(
                    vi=vi,
                    channel_list=CHANNELS,
                    range=voltage,
                    offset=0.0,
                    coupling=niscope_types.VerticalCoupling.VERTICAL_COUPLING_NISCOPE_VAL_DC,
                    probe_attenuation=1.0,
                    enabled=True,
                )
            )
        ).status,
    )

    # Configure horizontal timing.
    check_for_error(
        vi,
        (
            client.ConfigureHorizontalTiming(
                niscope_types.ConfigureHorizontalTimingRequest(
                    vi=vi,
                    min_sample_rate=SAMPLE_RATE_IN_HZ,
                    min_num_pts=1,
                    ref_position=0.0,
                    num_records=1,
                    enforce_realtime=True,
                )
            )
        ).status,
    )

    # Configure software trigger, but never send the trigger.
    # This starts an infinite acquisition, until you call Abort or Close
    check_for_error(
        vi,
        (
            client.ConfigureTriggerSoftware(
                niscope_types.ConfigureTriggerSoftwareRequest(vi=vi, holdoff=0.0, delay=0.0)
            )
        ).status,
    )

    # Initiate acquisition
    check_for_error(
        vi, (client.InitiateAcquisition(niscope_types.InitiateAcquisitionRequest(vi=vi))).status
    )

    # Allocate space for the waveform according to the max number of
    # points to fetch and the number of waveforms.
    channel_list = CHANNELS.split(",")
    total_samples = int(TOTAL_ACQUISITION_TIME_IN_SECONDS * SAMPLE_RATE_IN_HZ)
    waveforms = [np.ndarray(total_samples, dtype=np.float64) for c in channel_list]

    # Set fetch relative to attribute.
    check_for_error(
        vi,
        (
            client.SetAttributeViInt32(
                niscope_types.SetAttributeViInt32Request(
                    vi=vi,
                    channel_list="",
                    attribute_id=niscope_types.NiScopeAttribute.NISCOPE_ATTRIBUTE_FETCH_RELATIVE_TO,
                    value=niscope_types.NiScopeInt32AttributeValues.NISCOPE_INT32_FETCH_RELATIVE_TO_VAL_READ_POINTER,
                )
            )
        ).status,
    )

    # Fetch continuously until all samples are acquired.
    current_pos = 0
    samples_per_fetch = 100

    try:
        while current_pos < total_samples:
            # We fetch each channel at a time so we don't have to de-interleave afterwards.
            # We do not keep the wfm_info returned from fetch.
            for channel_name, waveform in zip(channel_list, waveforms):
                fetch_response = client.Fetch(
                    niscope_types.FetchRequest(
                        vi=vi,
                        channel_list=channel_name,
                        timeout=500000,
                        num_samples=samples_per_fetch,
                    )
                )
                check_for_error(vi, fetch_response.status)
                waveform[current_pos : current_pos + samples_per_fetch] = fetch_response.waveform
                print(
                    f"Fetching channel {channel_name}'s waveform for indices {current_pos} to {current_pos + samples_per_fetch - 1}"
                )
            print()
            current_pos += samples_per_fetch

    except KeyboardInterrupt:
        pass

# If NI-SCOPE API throws an exception, print the error message.
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE:
        error_message = f"Failed to connect to server on {SERVER_ADDRESS}:{SERVER_PORT}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = (
            "The operation is not implemented or is not supported/enabled in this service"
        )
    print(f"{error_message}")

finally:
    if "vi" in vars() and vi.id != 0:
        # close the session.
        check_for_error(vi, (client.Close(niscope_types.CloseRequest(vi=vi))).status)
