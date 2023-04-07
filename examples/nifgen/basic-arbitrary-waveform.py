r"""Generate a basic arbitrary waveform with Arbitrary Waveform Mode.

The gRPC API is built from the C API. NI-FGEN documentation is installed with the driver at:
  C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niFgen\documentation\English\SigGenHelp.chm

Getting Started:

To run this example, install "NI-FGEN Driver" on the server machine:
  https://www.ni.com/en-us/support/downloads/drivers/download.ni-fgen.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Running from command line:

Server machine's IP address, port number, and resource name can be passed as separate command line
arguments.
  > python basic-arbitrary-waveform.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedFGEN" as the resource name.
"""

import math
import sys

import grpc
import matplotlib.pyplot as plt
import nifgen_pb2 as nifgen_types
import nifgen_pb2_grpc as grpc_nifgen

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "NI-FGEN-Session"

# Resource name and options for a simulated 5441 client. Change them according to the NI-FGEN model.
RESOURCE = "SimulatedFGEN"
OPTIONS = "Simulate=1, DriverSetup=Model:5441; BoardType:PXI"

# parameters
CHANNEL_NAME = "0"
SAMPLE_RATE = 40e6
GAIN = 1.0
DC_OFFSET = 0.0
WAVEFORM_SIZE = 64

# initialize sine waveform data
SINE = [math.sin((i / WAVEFORM_SIZE) * 2 * math.pi) for i in range(WAVEFORM_SIZE)]

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    RESOURCE = sys.argv[3]
    OPTIONS = ""

# Create the communication channel for the remote host and create connections to the NI-FGEN and
# session services.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
nifgen_client = grpc_nifgen.NiFgenStub(channel)


def check_for_warning(response, vi):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        warning_message = nifgen_client.ErrorMessage(
            nifgen_types.ErrorMessageRequest(vi=vi, error_code=response.status)
        )
        sys.stderr.write(f"{warning_message.error_message}\nWarning status: {response.status}\n")


try:
    # Initalize NI-FGEN session
    init_with_options_resp = nifgen_client.InitWithOptions(
        nifgen_types.InitWithOptionsRequest(
            session_name=SESSION_NAME,
            resource_name=RESOURCE,
            option_string=OPTIONS,
        )
    )
    vi = init_with_options_resp.vi

    # Configure channels
    config_channels_resp = nifgen_client.ConfigureChannels(
        nifgen_types.ConfigureChannelsRequest(vi=vi, channels=CHANNEL_NAME)
    )

    # Configure output mode
    config_out_resp = nifgen_client.ConfigureOutputMode(
        nifgen_types.ConfigureOutputModeRequest(
            vi=vi,
            output_mode=nifgen_types.OutputMode.OUTPUT_MODE_NIFGEN_VAL_OUTPUT_ARB,
        )
    )

    # Create waveform
    create_waveform_resp = nifgen_client.CreateWaveformF64(
        nifgen_types.CreateWaveformF64Request(
            vi=vi,
            channel_name=CHANNEL_NAME,
            waveform_data_array=SINE,
        )
    )
    waveform_handle = create_waveform_resp.waveform_handle

    # Configure arbitrary waveform
    config_waveform_resp = nifgen_client.ConfigureArbWaveform(
        nifgen_types.ConfigureArbWaveformRequest(
            vi=vi,
            channel_name=CHANNEL_NAME,
            waveform_handle=waveform_handle,
            gain=GAIN,
            offset=DC_OFFSET,
        )
    )

    # Configure clockmode to VAL_HIGH_RESOLUTION
    config_clckmode_resp = nifgen_client.ConfigureClockMode(
        nifgen_types.ConfigureClockModeRequest(
            vi=vi,
            clock_mode=nifgen_types.ClockMode.CLOCK_MODE_NIFGEN_VAL_HIGH_RESOLUTION,
        )
    )

    # Configure sample rate
    config_sample_rate_resp = nifgen_client.ConfigureSampleRate(
        nifgen_types.ConfigureSampleRateRequest(vi=vi, sample_rate=SAMPLE_RATE)
    )

    # Configure output enabled
    config_outenbl_resp = nifgen_client.ConfigureOutputEnabled(
        nifgen_types.ConfigureOutputEnabledRequest(vi=vi, channel_name=CHANNEL_NAME, enabled=True)
    )

    # Initiate generation
    init_gen_resp = nifgen_client.InitiateGeneration(nifgen_types.InitiateGenerationRequest(vi=vi))
    check_for_warning(init_gen_resp, vi)

    print(f"Generating sine wave at {SAMPLE_RATE} Hz...")
    print("Close the window or press Ctrl+C to stop generation")

    try:
        # Plot the sine wave
        fig = plt.gcf()
        fig.canvas.manager.set_window_title("Sample Waveform")
        plt.plot(SINE)
        plt.suptitle("Close the window to stop generation", fontsize=10)
        plt.xlabel("Samples")
        plt.ylabel("Amplitude")
        plt.show()
    except KeyboardInterrupt:
        pass

# If NI-FGEN API throws an exception, print the error message
except grpc.RpcError as rpc_error:
    error_message = str(rpc_error.details() or "")
    for entry in rpc_error.trailing_metadata() or []:
        if entry.key == "ni-error":
            value = entry.value if isinstance(entry.value, str) else entry.value.decode("utf-8")
            error_message += f"\nError status: {value}"
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE:
        error_message = f"Failed to connect to server on {SERVER_ADDRESS}:{SERVER_PORT}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = (
            "The operation is not implemented or is not supported/enabled in this service"
        )
    print(f"{error_message}")
finally:
    if "vi" in vars() and vi.name != "":
        # Close NI-FGEN session
        nifgen_client.Close(nifgen_types.CloseRequest(vi=vi))
