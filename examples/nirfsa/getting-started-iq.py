r"""Configure I/Q parameters; read and print the I/Q data.

The following parameters of I/Q acquisition are configured:
 * reference clock, reference level, carrier frequency, I/Q rate, number of samples per record,
   and I/Q acquisition type.

The gRPC API is built from the C API. NI-RFSA documentation is installed with the driver at:
  C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niRFSA\documentation\English\nirfsa.chm

Getting Started:

To run this example, install "NI-RFSA Driver" on the server machine:
  https://www.ni.com/en-us/support/downloads/drivers/download.ni-rfsa.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-RFSA gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-RFSA-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and physical channel name can be passed as separate
command line arguments.
  > python getting-started-iq.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedRFSA" as the physical channel name.
"""

import math
import sys

import grpc
import nirfsa_pb2 as nirfsa_types
import nirfsa_pb2_grpc as grpc_nirfsa

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "NI-RFSA-Session"

# Resource name, channel name and options for a simulated 5663 client.
RESOURCE = "SimulatedRFSA"
OPTIONS = "Simulate=1,DriverSetup=Model:5663"

NUMBER_OF_SAMPLES = 1000

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
client = grpc_nirfsa.NiRFSAStub(channel)
vi = None


def check_for_warning(response, vi):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        warning_message = client.ErrorMessage(
            nirfsa_types.ErrorMessageRequest(vi=vi, status_code=response.status)
        )
        sys.stderr.write(f"{warning_message.error_message}\nWarning status: {response.status}\n")


try:
    init_response = client.InitWithOptions(
        nirfsa_types.InitWithOptionsRequest(
            session_name=SESSION_NAME, resource_name=RESOURCE, option_string=OPTIONS
        )
    )
    vi = init_response.vi

    client.ConfigureRefClock(
        nirfsa_types.ConfigureRefClockRequest(
            vi=vi,
            clock_source_mapped=nirfsa_types.RefClockSource.REF_CLOCK_SOURCE_ONBOARD_CLOCK,
            ref_clock_rate=10e6,
        )
    )
    client.ConfigureReferenceLevel(
        nirfsa_types.ConfigureReferenceLevelRequest(vi=vi, reference_level=0)
    )

    client.ConfigureAcquisitionType(
        nirfsa_types.ConfigureAcquisitionTypeRequest(
            vi=vi, acquisition_type=nirfsa_types.AcquisitionType.ACQUISITION_TYPE_IQ
        )
    )
    client.ConfigureIQCarrierFrequency(
        nirfsa_types.ConfigureIQCarrierFrequencyRequest(vi=vi, carrier_frequency=1e9)
    )
    client.ConfigureNumberOfSamples(
        nirfsa_types.ConfigureNumberOfSamplesRequest(
            vi=vi, number_of_samples_is_finite=True, samples_per_record=NUMBER_OF_SAMPLES
        )
    )
    read_response = client.ReadIQSingleRecordComplexF64(
        nirfsa_types.ReadIQSingleRecordComplexF64Request(
            vi=vi, timeout=10.0, data_array_size=NUMBER_OF_SAMPLES
        )
    )
    check_for_warning(read_response, vi)

    accumulator = 0.0
    for sample in read_response.data:
        magnitude_squared = sample.real**2 + sample.imaginary**2
        # We need to handle this because log(0) returns a range error.
        magnitude_squared = magnitude_squared or 1e-8
        accumulator += 10.0 * math.log10((magnitude_squared / (2.0 * 50.0)) * 1000.0)

    average_power = accumulator / NUMBER_OF_SAMPLES
    print(f"Average power = {average_power:.1f} dBm")


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
    if vi:
        client.Close(nirfsa_types.CloseRequest(vi=vi))
