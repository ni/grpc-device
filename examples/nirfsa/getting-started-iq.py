# Use this example to learn the basics of I/Q acquisition using the RF vector signal analyzer.
# The example shows how to configure the following parameters of I/Q acquisition:
# reference clock, reference level, carrier frequency, I/Q rate, number of samples per record,
# and I/Q acquisition type. This example also reads and prints the I/Q data.
#
# The gRPC API is built from the C API. NI-RFSA documentation is installed with the driver at:
# C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niRFSA\documentation\English\nirfsa.chm
#
# Getting Started:
#
# To run this example, install "NI-RFSA Driver" on the server machine.
# Link: https://www.ni.com/en-us/support/downloads/drivers/download.ni-rfsa.html
#
# For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC Client" wiki page.
# Link: https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client
#
# Refer to the NI-RFSA gRPC Wiki for the latest C Function Reference:
# Link: https://github.com/ni/grpc-device/wiki/NI-RFSA-C-Function-Reference
#
# Running from command line:
#
# Server machine's IP address, port number, and physical channel name can be passed as separate command line arguments.
#   > python getting-started-iq.py <server_address> <port_number> <physical_channel_name>
# If they are not passed in as command line arguments, then by default the server address will be "localhost:31763",
# with "SimulatedRFSA" as the physical channel name
import grpc
import math
import sys

import nirfsa_pb2 as nirfsa_types
import nirfsa_pb2_grpc as grpc_nirfsa

server_address = "localhost"
server_port = "31763"
session_name = "NI-RFSA-Session"

# Resource name, channel name and options for a simulated 5663 client.
resource = "SimulatedRFSA"
options = "Simulate=1,DriverSetup=Model:5663"

NUMBER_OF_SAMPLES = 1000

# Read in cmd args
if len(sys.argv) >= 2:
    server_address = sys.argv[1]
if len(sys.argv) >= 3:
    server_port = sys.argv[2]
if len(sys.argv) >= 4:
    resource = sys.argv[3]
    options = ""

# Create a gRPC channel + client.
channel = grpc.insecure_channel(f"{server_address}:{server_port}")
client = grpc_nirfsa.NiRFSAStub(channel)
vi = None

# Raise an exception if an error was returned
def raise_if_error(response):
    if response.status != 0:
        error_response = client.ErrorMessage(
            nirfsa_types.ErrorMessageRequest(status_code=response.status)
        )
        raise Exception(f"Error: {error_response.error_message}")

    return response


try:
    init_response = raise_if_error(
        client.InitWithOptions(
            nirfsa_types.InitWithOptionsRequest(
                session_name=session_name, resource_name=resource, option_string=options
            )
        )
    )
    vi = init_response.vi

    raise_if_error(
        client.ConfigureRefClock(
            nirfsa_types.ConfigureRefClockRequest(
                vi=vi,
                clock_source_mapped=nirfsa_types.RefClockSource.REF_CLOCK_SOURCE_ONBOARD_CLOCK,
                ref_clock_rate=10e6,
            )
        )
    )
    raise_if_error(
        client.ConfigureReferenceLevel(
            nirfsa_types.ConfigureReferenceLevelRequest(vi=vi, reference_level=0)
        )
    )
    raise_if_error(
        client.ConfigureAcquisitionType(
            nirfsa_types.ConfigureAcquisitionTypeRequest(
                vi=vi, acquisition_type=nirfsa_types.AcquisitionType.ACQUISITION_TYPE_IQ
            )
        )
    )
    raise_if_error(
        client.ConfigureIQCarrierFrequency(
            nirfsa_types.ConfigureIQCarrierFrequencyRequest(vi=vi, carrier_frequency=1e9)
        )
    )
    raise_if_error(
        client.ConfigureNumberOfSamples(
            nirfsa_types.ConfigureNumberOfSamplesRequest(
                vi=vi, number_of_samples_is_finite=True, samples_per_record=NUMBER_OF_SAMPLES
            )
        )
    )
    raise_if_error(client.ConfigureIQRate(nirfsa_types.ConfigureIQRateRequest(vi=vi, iq_rate=1e6)))

    read_response = raise_if_error(
        client.ReadIQSingleRecordComplexF64(
            nirfsa_types.ReadIQSingleRecordComplexF64Request(
                vi=vi, timeout=10.0, data_array_size=NUMBER_OF_SAMPLES
            )
        )
    )

    accumulator = 0.0
    for sample in read_response.data:
        magnitude_squared = sample.real**2 + sample.imaginary**2
        # We need to handle this because log(0) returns a range error.
        magnitude_squared = magnitude_squared or 1e-8
        accumulator += 10.0 * math.log10((magnitude_squared / (2.0 * 50.0)) * 1000.0)

    average_power = accumulator / NUMBER_OF_SAMPLES
    print(f"Average power = {average_power:.1f} dBm")


except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE:
        error_message = f"Failed to connect to server on {server_address}:{server_port}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = (
            "The operation is not implemented or is not supported/enabled in this service"
        )
    print(f"{error_message}")
finally:
    if vi:
        client.Close(nirfsa_types.CloseRequest(vi=vi))
