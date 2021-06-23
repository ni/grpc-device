# Demonstrates how to configure an NI Arbitrary Waveform Generator to generate a basic arbitrary waveform with Arbitrary Waveform Mode.
# 
# The gRPC API is built from the C API. NI-FGEN documentation is installed with the driver at:
# C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niFgen\documentation\English\SigGenHelp.chm
#
# Getting Started:
#
# To run this example, install "NI-FGEN Driver" on the server machine.
# Link : https://www.ni.com/en-us/support/downloads/drivers/download.ni-fgen.html
#
# For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC Client" wiki page.
# Link: https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client
#
# Running from command line:
#
# Server machine's IP address, port number, and resource name can be passed as separate command line arguments.
#   > python basic-arbitrary-waveform.py <server_address> <port_number> <resource_name>
# If they are not passed in as command line arguments, then by default the server address will be "localhost:31763", with "SimulatedFGEN" as the resource name

import grpc
import sys
import nifgen_pb2 as nifgen_types
import nifgen_pb2_grpc as grpc_nifgen
import session_pb2 as session_types
import session_pb2_grpc as grpc_session
import math
import matplotlib.pyplot as plt

server_address = "localhost"
server_port = "31763"
session_name = "NI-FGEN-Session"

# Resource name and options for a simulated 5441 client. Change them according to the NI-FGEN model.
resource = "SimulatedFGEN"
options = "Simulate=1, DriverSetup=Model:5441; BoardType:PXI"

# parameters
channel_name = "0"
sample_rate = 40e+6
gain = 1.0
dc_offset = 0.0
waveform_size = 64

# initialize sine waveform data
sine = []
for i in range(waveform_size):
    sine.append(math.sin((i/waveform_size)*2*math.pi))

# Read in cmd args
if len(sys.argv) >= 2:
    server_address = sys.argv[1]
if len(sys.argv) >= 3:
    server_port = sys.argv[2]
if len(sys.argv) >= 4:
    resource = sys.argv[3]
    options = ""

# Create the communication channel for the remote host and create connections to the NI-FGEN and session services.
channel = grpc.insecure_channel(f"{server_address}:{server_port}")
nifgen_service = grpc_nifgen.NiFgenStub(channel)

any_error = False
# Checks for errors. If any, throws an exception to stop the execution.
def CheckForError (vi, status) :
    global any_error
    if status != 0 and not any_error:
        any_error = True
        ThrowOnError (vi, status)

# Converts an error code returned by NI-FGEN into a user-readable string.
def ThrowOnError (vi, error_code):
    error_handler_request = nifgen_types.ErrorHandlerRequest(
        vi = vi,
        error_code = error_code
    )
    error_handler_response = nifgen_service.ErrorHandler(error_handler_request)
    raise Exception (error_handler_response.error_message)

try:
    # Initalize NI-FGEN session
    init_with_options_resp = nifgen_service.InitWithOptions(nifgen_types.InitWithOptionsRequest(
        session_name = session_name,
        resource_name = resource,
        option_string = options
    ))
    vi = init_with_options_resp.vi
    CheckForError(vi, init_with_options_resp.status)

    # Configure channels
    config_channels_resp = nifgen_service.ConfigureChannels(nifgen_types.ConfigureChannelsRequest(
        vi = vi,
        channels = channel_name
    ))
    CheckForError(vi, config_channels_resp.status)

    # Configure output mode
    config_out_resp = nifgen_service.ConfigureOutputMode(nifgen_types.ConfigureOutputModeRequest(
        vi = vi,
        output_mode = nifgen_types.OutputMode.OUTPUT_MODE_NIFGEN_VAL_OUTPUT_ARB
    ))
    CheckForError(vi, config_out_resp.status)

    # Create waveform
    create_waveform_resp = nifgen_service.CreateWaveformF64(nifgen_types.CreateWaveformF64Request(
        vi = vi,
        channel_name = channel_name,
        waveform_data_array = sine
    ))
    waveform_handle = create_waveform_resp.waveform_handle
    CheckForError(vi, create_waveform_resp.status)

    # Configure arbitrary waveform
    config_waveform_resp = nifgen_service.ConfigureArbWaveform(nifgen_types.ConfigureArbWaveformRequest(
        vi = vi,
        channel_name = channel_name,
        waveform_handle = waveform_handle,
        gain = gain,
        offset = dc_offset
    ))
    CheckForError(vi, config_waveform_resp.status)

    # Configure clockmode to VAL_HIGH_RESOLUTION
    config_clckmode_resp = nifgen_service.ConfigureClockMode(nifgen_types.ConfigureClockModeRequest(
        vi = vi,
        clock_mode = nifgen_types.ClockMode.CLOCK_MODE_NIFGEN_VAL_HIGH_RESOLUTION
    ))
    CheckForError(vi, config_clckmode_resp.status)

    # Configure sample rate
    config_sample_rate_resp = nifgen_service.ConfigureSampleRate(nifgen_types.ConfigureSampleRateRequest(
        vi = vi,
        sample_rate = sample_rate
    ))
    CheckForError(vi, config_sample_rate_resp.status)

    # Configure output enabled
    config_outenbl_resp = nifgen_service.ConfigureOutputEnabled(nifgen_types.ConfigureOutputEnabledRequest(
        vi = vi,
        channel_name = channel_name,
        enabled = True
    ))
    CheckForError(vi, config_outenbl_resp.status)

    # Initiate generation
    init_gen_resp = nifgen_service.InitiateGeneration(nifgen_types.InitiateGenerationRequest(
        vi = vi
    ))
    CheckForError(vi, init_gen_resp.status)

    print(f"Generating sine wave at {sample_rate} Hz...")
    print('Close the window or press Ctrl+C to stop generation')

    try:
        # Plot the sine wave
        fig = plt.gcf()
        fig.canvas.manager.set_window_title('Sample Waveform')
        plt.plot(sine)
        plt.suptitle("Close the window to stop generation", fontsize = 10)
        plt.xlabel("Samples")
        plt.ylabel("Amplitude")
        plt.show()
    except KeyboardInterrupt:
        pass

# If NI-FGEN API throws an exception, print the error message  
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE :
        error_message = f"Failed to connect to server on {server_address}:{server_port}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = "The operation is not implemented or is not supported/enabled in this service"
    print(f"{error_message}") 
finally:
    if 'vi' in vars() and vi.id != 0:
        # Close NI-FGEN session
        close_session_response = nifgen_service.Close(nifgen_types.CloseRequest(
            vi = vi
        ))
        CheckForError(vi, close_session_response.status)
