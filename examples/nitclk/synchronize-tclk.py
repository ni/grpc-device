r"""Configure multiple NI Arbitrary Waveform Generators to generate synchronized waveforms.

The gRPC API is built from the C API. NI-FGEN documentation is installed with the driver at:
  C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niFgen\documentation\English\SigGenHelp.chm

NI-TClk documentation is installed with the driver at:
  C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niTClk\documentation\English\nitclk.chm

Getting Started:

To run this example, install "NI-FGEN Driver" on the server machine:
  https://www.ni.com/en-us/support/downloads/drivers/download.ni-fgen.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Running from command line:

Server machine's IP address, port number, and multiple comma separated resource names can be
passed as separate command line arguments.
  > python synchronize-tclk.py <server_address> <port_number> <resource_name1,resource_name2>
This example is not supported in simulation mode, hence these arguments are mandatory.
"""

import sys

import grpc
import matplotlib.pyplot as plt
import nifgen_pb2 as nifgen_types
import nifgen_pb2_grpc as grpc_nifgen
import nitclk_pb2 as nitclk_types
import nitclk_pb2_grpc as grpc_nitclk

# parameters
SAMPLE_RATE = 20000000.0
WAVEFORM_SIZE = 16
# Create waveform data
WAVEFORM_DATA = [0.0 if i < WAVEFORM_SIZE // 2 else 1.0 for i in range(WAVEFORM_SIZE)]

# Read in cmd args
if len(sys.argv) < 4:
    msg = "This example is not supported in simulation mode. "
    msg += "Please provide server address, server port and resource name as follows:\n"
    msg += "  python synchronize-tclk.py <server_address> <port_number> <resource_name1,resource_name2>\n"
    sys.stderr.write(msg)
    sys.exit(1)
else:
    SERVER_ADDRESS = sys.argv[1]
    SERVER_PORT = sys.argv[2]
    RESOURCES = [r.strip() for r in sys.argv[3].split(",")]

# Create the communication channel for the remote host and create connections to the NI-FGEN and
# session services.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
nifgen_client = grpc_nifgen.NiFgenStub(channel)
nitclk_client = grpc_nitclk.NiTClkStub(channel)
sessions = []


def check_for_tclk_warning(response):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        warning_message = nitclk_client.GetExtendedErrorInfo(
            nitclk_types.GetExtendedErrorInfoRequest()
        )
        sys.stderr.write(f"{warning_message.error_string}\nWarning status: {response.status}\n")


try:
    for i, resource in enumerate(RESOURCES, start=1):
        # Initalize NI-FGEN session
        init_with_options_resp = nifgen_client.InitWithOptions(
            nifgen_types.InitWithOptionsRequest(
                session_name="session" + str(i), resource_name=resource, option_string=""
            )
        )
        vi = init_with_options_resp.vi
        sessions.append(vi)

        # Configure channels
        nifgen_client.ConfigureChannels(nifgen_types.ConfigureChannelsRequest(vi=vi, channels="0"))

        # Configure output mode
        nifgen_client.ConfigureOutputMode(
            nifgen_types.ConfigureOutputModeRequest(
                vi=vi, output_mode=nifgen_types.OutputMode.OUTPUT_MODE_NIFGEN_VAL_OUTPUT_ARB
            )
        )

        # Configure sample rate
        nifgen_client.ConfigureSampleRate(
            nifgen_types.ConfigureSampleRateRequest(vi=vi, sample_rate=SAMPLE_RATE)
        )

        # Create waveform
        nifgen_client.CreateWaveformF64(
            nifgen_types.CreateWaveformF64Request(
                vi=vi, channel_name="0", waveform_data_array=WAVEFORM_DATA
            )
        )

    nitclk_client.ConfigureForHomogeneousTriggers(
        nitclk_types.ConfigureForHomogeneousTriggersRequest(sessions=sessions)
    )

    # Synchronize and start generation
    nitclk_client.Synchronize(nitclk_types.SynchronizeRequest(sessions=sessions, min_tclk_period=0))
    initiate_response = nitclk_client.Initiate(nitclk_types.InitiateRequest(sessions=sessions))
    check_for_tclk_warning(initiate_response)

    print(f"Generating square wave with sample rate {SAMPLE_RATE} on {RESOURCES}...")
    print("Close the graph or press Ctrl+C to stop generation")

    try:
        # Plot waveform
        fig = plt.gcf()
        fig.canvas.manager.set_window_title("Sample Waveform")
        plt.plot(WAVEFORM_DATA)
        plt.suptitle("Close the window to stop generation", fontsize=10)
        plt.xlabel("Samples")
        plt.ylabel("Amplitude")
        plt.show()
    except KeyboardInterrupt:
        pass

# If NI-FGEN API throws an exception, print the error message.
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
    print(error_message)

finally:
    # Close the NI-FGEN sessions.
    for session in sessions:
        nifgen_client.Close(nifgen_types.CloseRequest(vi=session))
