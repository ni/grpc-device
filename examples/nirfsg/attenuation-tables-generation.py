r"""Download S-parameters from an attenuation per frequency table.

The code shows how to convert attenuation into simple s-parameter table to be used with RFSG.

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
"""  # noqa: W505

import sys

import grpc
import math
import nidevice_pb2 as nidevice_grpc
import nirfsg_pb2 as nirfsg_types
import nirfsg_pb2_grpc as grpc_nirfsg
import numpy as np

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "NI-RFSG-Session"

# Resource name, channel name and options for a simulated 5652 client.
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
client = grpc_nirfsg.NiRFSGStub(channel)
vi = None


def raise_if_error(response):
    """Raise an exception if an error was returned."""
    if response.status != 0:
        response = client.ErrorMessage(
            nirfsg_types.ErrorMessageRequest(error_code=response.status)
        )
        raise Exception(f"Error: {response.error_string}")


def raise_if_initialization_error(response):
    """Raise an exception if an error was returned from Initialize."""
    if response.status < 0:
        raise RuntimeError(f"Error: {response.error_message or response.status}")
    if response.status > 0:
        sys.stderr.write(f"Warning: {response.error_message or response.status}\n")
    return response


try:
    response = client.InitWithOptions(
        nirfsg_types.InitWithOptionsRequest(
            session_name=SESSION_NAME, resource_name=RESOURCE, option_string=OPTIONS
        )
    )
    raise_if_initialization_error(response)
    vi = response.vi

    client.ConfigureRefClock(
        nirfsg_types.ConfigureRefClockRequest(
            vi=vi,
            ref_clock_source_mapped=nirfsg_types.REF_CLOCK_SOURCE_ONBOARD_CLOCK,
            ref_clock_rate=10000000,
        )
    )

    client.SetAttributeViString(
        nirfsg_types.SetAttributeViStringRequest(
            vi=vi,
            channel_name="",
            attribute_id=nirfsg_types.NIRFSG_ATTRIBUTE_REF_CLOCK_SOURCE,
            value_mapped=nirfsg_types.NIRFSG_STRING_REF_CLOCK_SOURCE_ONBOARD_CLOCK,
        )
    )

    raise_if_error(
        client.ConfigureRF(nirfsg_types.ConfigureRFRequest(vi=vi, frequency=1e9, power_level=-10))
    )

    # Having a table of attenuations per frequency, we demo how to convert them to S parameters
    # and download them to RFSG to be automatically set when we change the frequency
    frequency_table_hz = [1e9, 6e9]
    attenuation_table_db = [3, 3]

    # Convert to S parameters: Linear attenuation
    s12 = [math.pow(10, x / 20) for x in attenuation_table_db]
    # We ned a table that it is frequencies x 2 x 2. Easier to fill it as a 3D matrix
    sparam = np.zeros(shape=(len(frequency_table_hz), 2, 2))
    for index in range(len(frequency_table_hz)):
        sparam[index, 0, 1] = s12[index]
        sparam[index, 1, 0] = s12[index]
    # Now flatten into a list
    sparam = sparam.reshape(np.prod(np.shape(sparam)))
    sparam = sparam.tolist()
    # Convert to NI datatype
    sparam_ni = [nidevice_grpc.NIComplexNumber(real=x, imaginary=0) for x in sparam]
    # Send them to the instrument
    client.CreateDeembeddingSparameterTableArray(
        nirfsg_types.CreateDeembeddingSparameterTableArrayRequest(
            vi=vi,
            port="",
            table_name="myTable",
            frequencies=frequency_table_hz,
            sparameter_table=sparam_ni,
            number_of_ports=2,
            sparameter_orientation=nirfsg_types.S_PARAMETER_ORIENTATION_PORT1_TOWARDS_DUT,
        )
    )

    raise_if_error(client.Initiate(nirfsg_types.InitiateRequest(vi=vi)))
    print("Generating tone...")
    # Wait for two seconds and change frequency
    input("Press any key to stop generation")
    raise_if_error(client.Abort(nirfsg_types.AbortRequest(vi=vi)))
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
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
            nirfsg_types.ConfigureOutputEnabledRequest(output_enabled=False)
        )
        client.Close(nirfsg_types.CloseRequest(vi=vi))
