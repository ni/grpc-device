r""" Read and Write to indicators, controls, Arrays and FIFO.

The gRPC API is built from the C API. NI-FPGA documentation is installed with the driver at:
    C:\Program Files (x86)\National Instruments\FPGA Interface C API\capi.chm

Getting Started:

To run this example, you need to provide the correct file path and bitfile signature.
Additionally, you should have a VI that includes controls, arrays, and FIFO,
and update the references for them below. Ensure that the R-Series drivers are
installed on which the server would run. You can install FPGA C Interface API as well.

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Run from command line as we need to pass Resource Name:

Server machine's IP address, port number, and resource name can be passed as separate command line
arguments.
  > python read_write_example.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "" as the resource name.

In this example, we are attempting to read and write values to an indicator, to an array,
and take input from the user on the number of elements to write to the FIFO.
Additionally, we are taking the multiplier as input and then reading elements from the other FIFO.
At the end we Abort the VI.
"""

import random
import sys

import grpc
import nifpga_pb2 as nifpga_types
import nifpga_pb2_grpc as grpc_nifpga

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "NI-FPGA-Session"

RESOURCE = ""

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    RESOURCE = sys.argv[3]

channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
client = grpc_nifpga.NiFpgaStub(channel)
print(f"{SERVER_ADDRESS} : {SERVER_PORT} : {RESOURCE}\n")
new_session = None
try:
    NI_FPGA_EXAMPLE_BITFILE_PATH = "C:\\DemoExample.lvbitx"  # Give the correct file path
    NI_FPGA_EXAMPLE_SIGNATURE = (
        "11F1FF1D11F1FF1F1F111FF11F11F111"  # Give the correct bitfile signature
    )
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
    if open_session_response.status == 0:
        print("Session Created Successfully.\n")

    run_response = client.Run(
        nifpga_types.RunRequest(
            session=new_session, attribute=nifpga_types.RunAttribute.RUN_ATTRIBUTE_UNSPECIFIED
        )
    )

    # Read and Write to an indicator
    NumericI16Indicator = 0x10002
    i16_write_response = client.WriteI16(
        nifpga_types.WriteI16Request(session=new_session, control=NumericI16Indicator, value=12)
    )
    if i16_write_response.status == 0:
        print("Write to indicator successful\n")
    i16_read_response = client.ReadI16(
        nifpga_types.ReadI16Request(session=new_session, indicator=NumericI16Indicator)
    )
    print(f"Indicator value: {i16_read_response.value}\n")

    # Read and Write to an Array
    ControlArrayI32 = 0x10004
    ControlArrayI32Size = 4
    updated_array = [1, -221, -1111, -21]
    writei32_array_response = client.WriteArrayI32(
        nifpga_types.WriteArrayI32Request(
            session=new_session, control=ControlArrayI32, array=updated_array
        )
    )
    if writei32_array_response.status == 0:
        print("Write to indicator successful\n")

    readi32_array_response = client.ReadArrayI32(
        nifpga_types.ReadArrayI32Request(
            session=new_session, indicator=ControlArrayI32, size=ControlArrayI32Size
        )
    )
    print(f"Update array value: {readi32_array_response.array}\n")

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

    ControlI16_multiplier = 0x1000A
    i16_write_response = client.WriteI16(
        nifpga_types.WriteI16Request(
            session=new_session, control=ControlI16_multiplier, value=multiplier_input
        )
    )
    InfiniteTimeout = 0xFFFFFFFF
    HostToTargetFifoI16 = 1
    writefifoi16_response = client.WriteFifoI16(
        nifpga_types.WriteFifoI16Request(
            session=new_session,
            fifo=HostToTargetFifoI16,
            data=random_numbers,
            timeout=InfiniteTimeout,
        )
    )
    if writefifoi16_response.status == 0:
        print("FIFO Write successful.\n")

    TargetToHostFifoI16 = 0
    readfifoi16_response = client.ReadFifoI16(
        nifpga_types.ReadFifoI16Request(
            session=new_session,
            fifo=TargetToHostFifoI16,
            number_of_elements=user_input,
            timeout=InfiniteTimeout,
        )
    )
    print(f"Elements in FIFO: {readfifoi16_response.data}\n")
    print(f"Elements remaining to read from FIFO: {readfifoi16_response.elements_remaining}\n")

    abort_response = client.Abort(nifpga_types.AbortRequest(session=new_session))
    if abort_response.status == 0:
        print("VI Aborted Successfully.\n")

    close_response = client.Close(
        nifpga_types.CloseRequest(
            session=new_session,
            attribute=nifpga_types.CloseAttribute.CLOSE_ATTRIBUTE_UNSPECIFIED,
        )
    )
    if close_response.status == 0:
        print("Session closed.\n")

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
