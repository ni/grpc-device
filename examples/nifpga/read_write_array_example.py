r""" Read and Write to Arrays.

The gRPC API is built from the C API. NI-FPGA documentation is installed with the driver at:
    C:\Program Files (x86)\National Instruments\FPGA Interface C API\capi.chm

Getting Started:

To run this example with your VI, you need to configure the values below.
Additionally, ensure you have a VI that includes arrays and update the references for them below.
Make sure the R-Series drivers are installed on the system where the gRPC-device server is running.
You will also need LABVIEW and the LABVIEW FPGA module to configure the VIs.

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Server machine's IP address, port number, and resource name can be passed as separate command line
arguments.
  > python read_write_example.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "FPGA" as the resource name.

This example attempts to read and write values to an array.
"""

import sys

import grpc
import nifpga_pb2 as nifpga_types
import nifpga_pb2_grpc as grpc_nifpga

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "NI-FPGA-Session"
RESOURCE = "FPGA"

# Configure these values.
NI_FPGA_EXAMPLE_BITFILE_PATH = "C:\\DemoExample.lvbitx"
NI_FPGA_EXAMPLE_SIGNATURE = "11F1FF1D11F1FF1F1F111FF11F11F111"
EXAMPLE_ARRAY_CONTROL = 0x10004
EXAMPLE_ARRAY_CONTROL_SIZE = 4

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    RESOURCE = sys.argv[3]

channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
client = grpc_nifpga.NiFpgaStub(channel)


def check_for_warning(response):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        sys.stderr.write(f"Warning status: {response.status}\n")


new_session = None
try:
    open_session_response = client.Open(
        nifpga_types.OpenRequest(
            session_name=SESSION_NAME,
            bitfile=NI_FPGA_EXAMPLE_BITFILE_PATH,
            signature=NI_FPGA_EXAMPLE_SIGNATURE,
            resource=RESOURCE,
            attribute_mapped=nifpga_types.OpenAttribute.OPEN_ATTRIBUTE_NO_RUN,
        )
    )
    new_session = open_session_response.session
    check_for_warning(open_session_response)

    run_response = client.Run(
        nifpga_types.RunRequest(
            session=new_session, attribute=nifpga_types.RunAttribute.RUN_ATTRIBUTE_UNSPECIFIED
        )
    )
    check_for_warning(run_response)

    # Read and Write to an Array
    updated_array = [1, -221, -1111, -21]
    writei32_array_response = client.WriteArrayI32(
        nifpga_types.WriteArrayI32Request(
            session=new_session, control=EXAMPLE_ARRAY_CONTROL, array=updated_array
        )
    )
    check_for_warning(writei32_array_response)

    readi32_array_response = client.ReadArrayI32(
        nifpga_types.ReadArrayI32Request(
            session=new_session,
            indicator=EXAMPLE_ARRAY_CONTROL,
            size=EXAMPLE_ARRAY_CONTROL_SIZE,
        )
    )
    print(f"Updated array value: {readi32_array_response.array}\n")

    abort_response = client.Abort(nifpga_types.AbortRequest(session=new_session))
    check_for_warning(abort_response)

    close_response = client.Close(
        nifpga_types.CloseRequest(
            session=new_session,
            attribute=nifpga_types.CloseAttribute.CLOSE_ATTRIBUTE_UNSPECIFIED,
        )
    )
    check_for_warning(close_response)

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
