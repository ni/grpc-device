r"""Generate a waveform from a TDMS file at a specified frequency and power.

The gRPC API is built from the C API. NI-RFSG documentation is installed with the driver at:
  C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niRFSG\documentation\English\RFSG.chm

Getting Started:

To run this example, install "NI-RFSG Driver" on the server machine:
  https://www.ni.com/en-us/support/downloads/drivers/download.ni-rfsg.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-RFSG gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-RFSG-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and physical channel name can be passed as separate
command line arguments.
  > python getting-started-single-tone-generation.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedRFSG" as the physical channel name.
"""  

import sys
import grpc
import nirfsg_pb2 as nirfsg_types
import nirfsg_pb2_grpc as grpc_nirfsg

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "NI-RFSG-Session"

# Resource name, channel name and options for a simulated 5652 client.
RESOURCE = "SimulatedRFSG"
OPTIONS = "Simulate=1,DriverSetup=Model:5652"

# Waveform filepath
FILE_PATH = "C:/Users/Public/Documents/National Instruments/RFIC Test Software/Waveforms/test.tdms"
SCRIPT = "script GenerateWfm " \
         "repeat forever " \
         "generate waveform marker0(0) " \
         "end repeat " \
         "end script"

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    RESOURCE = sys.argv[3]
    OPTIONS = ""

# Create a gRPC channel + client.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
client = grpc_nirfsg.NiRFSGStub(channel)
vi = None


def check_for_warning(response, vi):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        warning_message = client.ErrorMessage(
            nirfsg_types.ErrorMessageRequest(vi=vi, error_code=response.status)
        )
        sys.stderr.write(f"{warning_message.error_message}\nWarning status: {response.status}\n")


# Initialize RFSG
try:
    response = client.InitWithOptions(
        nirfsg_types.InitWithOptionsRequest(
            session_name=SESSION_NAME, resource_name=RESOURCE, option_string=OPTIONS
        )
    )
    vi = response.vi

# Configure RFSG
    client.ConfigureRF(nirfsg_types.ConfigureRFRequest(vi=vi, frequency=3.5e9, power_level=-10))
    client.ConfigureRefClock(
        nirfsg_types.ConfigureRefClockRequest(
            vi=vi,
            ref_clock_source_mapped=nirfsg_types.REF_CLOCK_SOURCE_PXI_CLK,
            ref_clock_rate=10e6
        )
    )

    client.ConfigurePowerLevelType(
        nirfsg_types.ConfigurePowerLevelTypeRequest(
            vi=vi, power_level_type=nirfsg_types.POWER_LEVEL_TYPE_PEAK_POWER
        )
    )

    client.ExportSignal(
        nirfsg_types.ExportSignalRequest(
            vi=vi,
            signal=nirfsg_types.ROUTED_SIGNAL_MARKER_EVENT,
            signal_identifier_mapped=nirfsg_types.SIGNAL_IDENTIFIER_MARKER0,
            output_terminal_mapped=nirfsg_types.OUTPUT_SIGNAL_PXI_TRIG0
        )
    )

    client.ReadAndDownloadWaveformFromFileTDMS(
        nirfsg_types.ReadAndDownloadWaveformFromFileTDMSRequest(
            vi=vi,
            waveform_name="waveform",
            file_path=FILE_PATH,
            waveform_index=0
        )
    )

    client.ConfigureGenerationMode(
        nirfsg_types.ConfigureGenerationModeRequest(
            vi=vi, generation_mode=nirfsg_types.GENERATION_MODE_SCRIPT
        )
    )

    client.WriteScript(
        nirfsg_types.WriteScriptRequest(
            vi=vi, script=SCRIPT
        )
    )

    initiate_response = client.Initiate(nirfsg_types.InitiateRequest(vi=vi))
    check_for_warning(initiate_response, vi)
    print("Generating waveform... "
          "Press Enter to stop generation.")
    input()

except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
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
    if vi:
        client.ConfigureOutputEnabled(
            nirfsg_types.ConfigureOutputEnabledRequest(vi=vi, output_enabled=False)
        )
        client.Close(nirfsg_types.CloseRequest(vi=vi))
