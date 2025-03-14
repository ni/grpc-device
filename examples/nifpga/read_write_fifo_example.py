r"""Read and Write to controls and FIFO.

The gRPC API is built from the C API. NI-FPGA documentation is installed with the driver at:
    C:\Program Files (x86)\National Instruments\FPGA Interface C API\capi.chm

Getting Started:

To run this example with your VI, you need to configure the values below.
Additionally, you should have a VI that includes controls and FIFOs, and update the
references for them below. Ensure that the R-Series drivers are installed on the system
where the gRPC-device server is running. You will also need LABVIEW and the LABVIEW FPGA
module to configure the VIs.

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Server machine's IP address, port number, and resource name can be passed as separate command line
arguments.
  > python read_write_example.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "FPGA" as the resource name.

In this example, we specify the number of elements to write to the FIFO and provide
a multiplier as input. We then read elements from another FIFO, which contains the multiplied
values of the elements from the first FIFO.
"""

import random
import sys

import grpc
import nifpga_pb2 as nifpga_types
import nifpga_pb2_grpc as grpc_nifpga

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "NI-FPGA-Session"
RESOURCE = "FPGA"

# Configure these values.
EXAMPLE_BITFILE_PATH = "C:\\DemoExample.lvbitx"
EXAMPLE_SIGNATURE = "11F1FF1D11F1FF1F1F111FF11F11F111"
EXAMPLE_NUMERIC_CONTROL = 0x1000A
EXAMPLE_TARGET_TO_HOST_FIFO = 0
EXAMPLE_HOST_TO_TARGET_FIFO = 1

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
            bitfile=EXAMPLE_BITFILE_PATH,
            signature=EXAMPLE_SIGNATURE,
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

    # Read and Write to FIFO
    # These two FIFOs are configured such that we specify the number of elements
    # to add to the FIFO and the multiplier.
    # The other FIFO will contain the multiplied value of the elements of the firsts FIFO.
    user_input = int(
        input("Enter number of elements you want to add in the FIFO (between 1 and 20): ")
    )
    random_numbers = []
    if 1 <= user_input <= 20:
        for _ in range(user_input):
            random_number = random.randint(1, 100)
            random_numbers.append(random_number)
        print(f"Random numbers: {random_numbers}\n")
    else:
        print("Invalid input. Please enter a number between 1 and 20.")

    multiplier_input = int(
        input("Enter the multiplier you want the FIFO elements to get multplied with: ")
    )

    i16_write_response = client.WriteI16(
        nifpga_types.WriteI16Request(
            session=new_session,
            control=EXAMPLE_NUMERIC_CONTROL,
            value=multiplier_input,
        )
    )
    InfiniteTimeout = 0xFFFFFFFF
    writefifoi16_response = client.WriteFifoI16(
        nifpga_types.WriteFifoI16Request(
            session=new_session,
            fifo=EXAMPLE_HOST_TO_TARGET_FIFO,
            data=random_numbers,
            timeout=InfiniteTimeout,
        )
    )
    check_for_warning(writefifoi16_response)

    readfifoi16_response = client.ReadFifoI16(
        nifpga_types.ReadFifoI16Request(
            session=new_session,
            fifo=EXAMPLE_TARGET_TO_HOST_FIFO,
            number_of_elements=user_input,
            timeout=InfiniteTimeout,
        )
    )
    print(f"Elements in FIFO: {readfifoi16_response.data}\n")
    print(f"Elements remaining to read from FIFO: {readfifoi16_response.elements_remaining}\n")

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
