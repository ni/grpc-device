r"""Example on how to get the RFSA Handle via RFmx Session.

Steps:
  1. Open only one RFmx Session. No need to open every personality.
  2. Get RFSA Session
  2. Configure Frequency Reference using RFSA Session.
  3. Get Frequency Reference using RFSA Session
  13. Close RFmx Session. RFSA Session is closes by RFmx.

The gRPC API is built from the C API. RFmx NR documentation is installed with the driver at:
  C:\Program Files (x86)\National Instruments\RFmx\NR\Documentation\rfmxnrcvi.chm

Getting Started:

To run this example, install "NI-RFSA Driver" on the server machine:
  https://www.ni.com/en-us/support/downloads/drivers/download.ni-rfsa.html

To run this example, install "RFmx SpecAn" on the server machine:
  https://www.ni.com/en-us/support/downloads/software-products/download.rfmx-specan.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-RFSA gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-RFSA-C-Function-Reference

Refer to the NI-RFmxSpecAn gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-RFmxSpecAn-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and physical channel name can be passed as separate
command line arguments.
  > python rfmx-instr-get-rfsa-handle.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedDevice" as the resource name.
"""

import sys

import grpc
import nirfmxinstr_pb2 as nirfmxinstr_types
import nirfmxinstr_pb2_grpc as grpc_nirfmxinstr
import nirfsa_pb2 as nirfsa_types
import nirfsa_pb2_grpc as grpc_nirfsa

SERVER_ADDRESS = "mercury07"
SERVER_PORT = "31763"
SESSION_NAME = "RFmxSession"

# Resource name and options for a simulated 5663 client.
RESOURCE = "5840_1"
OPTIONS = ""

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
instrclient = grpc_nirfmxinstr.NiRFmxInstrStub(channel)
rfsaclient = grpc_nirfsa.NiRFSAStub(channel)
instr = None


def check_for_warning(response, instrument):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        warning_message = instrclient.GetErrorString(
            nirfmxinstr_types.GetErrorStringRequest(
                instrument=instrument,
                error_code=response.status,
            )
        )
        sys.stderr.write(
            f"{warning_message.error_description}\nWarning status: {response.status}\n"
        )


try:
    initialize_response = instrclient.Initialize(
        nirfmxinstr_types.InitializeRequest(
            session_name=SESSION_NAME,
            resource_name=RESOURCE,
            option_string=OPTIONS,
        )
    )

    instr = initialize_response.instrument

    # Get rfsa session. No need to pass a session name to the request, only the RFmx session
    rfsa_response = instrclient.GetNIRFSASession(
        nirfmxinstr_types.GetNIRFSASessionRequest(instrument=instr)
    )

    nirfsa_session = rfsa_response.nirfsa_session
    # Use this session to get/set RFSA specific parameters. No need to close session
    # Set reference clock
    rfsaclient.ConfigureRefClock(
        nirfsa_types.ConfigureRefClockRequest(
            vi=nirfsa_session,
            clock_source_mapped=nirfsa_types.REF_CLOCK_SOURCE_ONBOARD_CLOCK,
            ref_clock_rate=10e6,
        )
    )
    # Get reference clock
    response = rfsaclient.GetAttributeViString(
        nirfsa_types.GetAttributeViStringRequest(
            vi=nirfsa_session,
            channel_name="",
            attribute_id=nirfsa_types.NIRFSA_ATTRIBUTE_REF_CLOCK_SOURCE,
        )
    )
    reference_clock = response.value

except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    for entry in rpc_error.trailing_metadata() or []:
        if entry.key == "ni-error":
            value = (
                entry.value
                if isinstance(entry.value, str)
                else entry.value.decode("utf-8")
            )
            error_message += f"\nError status: {value}"
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE:
        error_message = f"Failed to connect to server on {SERVER_ADDRESS}:{SERVER_PORT}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = "The operation is not implemented or is not supported/enabled in this service"
    sys.stderr.write(f"{error_message}\n")
finally:
    if instr:
        instrclient.Close(
            # Only RFmx session can be closed
            nirfmxinstr_types.CloseRequest(instrument=instr, force_destroy=False)
        )
