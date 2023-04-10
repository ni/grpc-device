r"""Read a spectrum.

Steps:
  1. Open a new RFmx session
  2. Configure the basic signal properties  (Center Frequency, Reference Level and External
     Attenuation)
  3. Configure Spectrum Span
  4. Configure Spectrum RBW filter
  5. Configure Spectrum Averaging
  6. Read Spectrum Measurement Results
  7. Close the RFmx Session

The gRPC API is built from the C API. RFmx SpecAn documentation is installed with the driver at:
  C:\Program Files (x86)\National Instruments\RFmx\SpecAn\Documentation\rfmxspecancvi.chm

Getting Started:

To run this example, install "RFmx SpecAn" on the server machine:
  # https://www.ni.com/en-us/support/downloads/software-products/download.rfmx-specan.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-RFmxSpecAn gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-RFmxSpecAn-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and physical channel name can be passed as separate
command line arguments.
  > python spectrum-basic.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedRFSA" as the resource name.
"""

import sys
from math import floor

import grpc
import nirfmxspecan_pb2 as nirfmxspecan_types
import nirfmxspecan_pb2_grpc as grpc_nirfmxspecan

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "NI-RFSASession"

# Resource name and options for a simulated 5663 client.
RESOURCE = "SimulatedRFSA"
OPTIONS = "Simulate=1,DriverSetup=Model:5663"

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
client = grpc_nirfmxspecan.NiRFmxSpecAnStub(channel)
instr = None


def _format_frequency(f):
    # adapted from https://stackoverflow.com/a/1094933
    suffix = "Hz"
    for unit in ["", "k", "M", "G"]:
        if abs(f) < 1000.0:
            return f"{f:3.3f} {unit}{suffix}"
        f /= 1000.0
    return f"{f:.3f} G{suffix}"


def check_for_warning(response, instrument):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        warning_message = client.GetErrorString(
            nirfmxspecan_types.GetErrorStringRequest(
                instrument=instrument,
                error_code=response.status,
            )
        )
        sys.stderr.write(
            f"{warning_message.error_description}\nWarning status: {response.status}\n"
        )


try:
    init_response = client.Initialize(
        nirfmxspecan_types.InitializeRequest(
            session_name=SESSION_NAME,
            resource_name=RESOURCE,
            option_string=OPTIONS,
        )
    )
    instr = init_response.instrument

    client.CfgRF(
        nirfmxspecan_types.CfgRFRequest(
            instrument=instr,
            selector_string="",
            center_frequency=1e9,
            reference_level=0,
            external_attenuation=0,
        )
    )

    client.SpectrumCfgSpan(
        nirfmxspecan_types.SpectrumCfgSpanRequest(
            instrument=instr,
            selector_string="",
            span=1e6,
        )
    )

    client.SpectrumCfgRBWFilter(
        nirfmxspecan_types.SpectrumCfgRBWFilterRequest(
            instrument=instr,
            selector_string="",
            rbw_auto=nirfmxspecan_types.SPECTRUM_RBW_AUTO_BANDWIDTH_TRUE,
            rbw=100e3,
            rbw_filter_type=nirfmxspecan_types.SPECTRUM_RBW_FILTER_TYPE_GAUSSIAN,
        )
    )

    client.SpectrumCfgAveraging(
        nirfmxspecan_types.SpectrumCfgAveragingRequest(
            instrument=instr,
            selector_string="",
            averaging_enabled=nirfmxspecan_types.SPECTRUM_AVERAGING_ENABLED_FALSE,
            averaging_count=10,
            averaging_type=nirfmxspecan_types.SPECTRUM_AVERAGING_TYPE_RMS,
        )
    )

    read_response = client.SpectrumRead(
        nirfmxspecan_types.SpectrumReadRequest(
            instrument=instr,
            selector_string="",
            timeout=10.0,
        )
    )
    check_for_warning(read_response, instr)

    print(
        f"min frequency: {_format_frequency(read_response.x0)}: {read_response.spectrum[0]:.1f} dBm"
    )
    midpoint_x = floor(read_response.actual_array_size / 2)
    print(
        f"midpoint frequency: {_format_frequency(read_response.x0 + read_response.dx * midpoint_x)}: {read_response.spectrum[midpoint_x]:.1f} dBm"
    )
    print(
        f"max frequency: {_format_frequency(read_response.x0 + read_response.dx * (read_response.actual_array_size - 1))}: {read_response.spectrum[-1]:.1f} dBm"
    )
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
    sys.stderr.write(f"{error_message}\n")
finally:
    if instr:
        client.Close(nirfmxspecan_types.CloseRequest(instrument=instr, force_destroy=False))
