r"""Perform continuous measure record.

The gRPC API is built from the C API. NI-DCPower documentation is installed with the driver at:
  C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niDCPower\Documentation\NIDCPowerCref.chm

Getting Started:

To run this example, install "NI-DCPower Driver" on the server machine:
  https://www.ni.com/en-in/support/downloads/drivers/download.ni-dcpower.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI DCPOWER gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-DCPOWER-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and resource name can be passed as separate command line
arguments.
  > python measure-record.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedDCPower" as the resource name.
"""

import math
import sys
import time

import grpc
import matplotlib.pyplot as plt
import nidcpower_pb2 as nidcpower_types
import nidcpower_pb2_grpc as grpc_nidcpower
import numpy as np

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "NI-DCPower-Session"

# Resource name, channel name and options for a simulated 4147 client. Change them according to
# NI-DCPower model.
RESOURCE = "SimulatedDCPower"
OPTIONS = "Simulate=1,DriverSetup=Model:4147;BoardType:PXIe"
CHANNELS = "0"

# Parameters
RECORD_LENGTH = 10
BUFFER_MULTIPLIER = 10
VOLTAGE_LEVEL = 5.0

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    RESOURCE = sys.argv[3]
    OPTIONS = ""


def check_for_error(vi, status):
    """Raise an exception if the status indicates an error."""
    if status != 0:
        error_message_response = client.ErrorMessage(
            nidcpower_types.ErrorMessageRequest(vi=vi, error_code=status)
        )
        raise Exception(error_message_response.error_message)


def check_for_initialization_error(response):
    """Raise an exception if an error was returned from Initialize."""
    if response.status < 0:
        raise RuntimeError(f"Error: {response.error_message or response.status}")
    if response.status > 0:
        sys.stderr.write(f"Warning: {response.error_message or response.status}\n")


# Create the communication channel for the remote host and create connections to the NI-DCPower and
# session services.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
client = grpc_nidcpower.NiDCPowerStub(channel)

try:
    # Initialize the session.
    initialize_with_channels_response = client.InitializeWithChannels(
        nidcpower_types.InitializeWithChannelsRequest(
            session_name=SESSION_NAME,
            resource_name=RESOURCE,
            channels=CHANNELS,
            reset=False,
            option_string=OPTIONS,
        )
    )
    vi = initialize_with_channels_response.vi
    check_for_initialization_error(initialize_with_channels_response)

    # Specify when the measure unit should acquire measurements.
    configure_measure_when = client.SetAttributeViInt32(
        nidcpower_types.SetAttributeViInt32Request(
            vi=vi,
            attribute_id=nidcpower_types.NiDCPowerAttribute.NIDCPOWER_ATTRIBUTE_MEASURE_WHEN,
            attribute_value=nidcpower_types.NiDCPowerInt32AttributeValues.NIDCPOWER_INT32_MEASURE_WHEN_VAL_AUTOMATICALLY_AFTER_SOURCE_COMPLETE,
        )
    )
    check_for_error(vi, configure_measure_when.status)

    # set the voltage level.
    configure_voltage_level = client.ConfigureVoltageLevel(
        nidcpower_types.ConfigureVoltageLevelRequest(vi=vi, level=VOLTAGE_LEVEL)
    )
    check_for_error(vi, configure_voltage_level.status)

    # Sspecify how many measurements compose a measure record.
    configure_measure_record_length = client.SetAttributeViInt32(
        nidcpower_types.SetAttributeViInt32Request(
            vi=vi,
            attribute_id=nidcpower_types.NiDCPowerAttribute.NIDCPOWER_ATTRIBUTE_MEASURE_RECORD_LENGTH,
            attribute_value=RECORD_LENGTH,
        )
    )
    check_for_error(vi, configure_measure_record_length.status)

    # Specify whether to take continuous measurements. Set it to False for continuous measurement.
    configure_measure_record_length_is_finite = client.SetAttributeViBoolean(
        nidcpower_types.SetAttributeViBooleanRequest(
            vi=vi,
            attribute_id=nidcpower_types.NiDCPowerAttribute.NIDCPOWER_ATTRIBUTE_MEASURE_RECORD_LENGTH_IS_FINITE,
            attribute_value=False,
        )
    )
    check_for_error(vi, configure_measure_record_length_is_finite.status)

    # commit the session.
    commit_response = client.Commit(
        nidcpower_types.CommitRequest(
            vi=vi,
        )
    )
    check_for_error(vi, commit_response.status)

    # get measure_record_delta_time.
    get_measure_record_delta_time = client.GetAttributeViReal64(
        nidcpower_types.GetAttributeViReal64Request(
            vi=vi,
            attribute_id=nidcpower_types.NiDCPowerAttribute.NIDCPOWER_ATTRIBUTE_MEASURE_RECORD_DELTA_TIME,
        )
    )
    check_for_error(vi, get_measure_record_delta_time.status)

    # initiate the session.
    initiate_response = client.Initiate(
        nidcpower_types.InitiateRequest(
            vi=vi,
        )
    )
    check_for_error(vi, initiate_response.status)

    # Setup a plot to draw the captured waveform.
    fig = plt.figure("Waveform Graph")
    fig.show()
    fig.canvas.draw()

    # Handle closing of plot window.
    closed = False

    def _on_close(event):
        global closed
        closed = True

    fig.canvas.mpl_connect("close_event", _on_close)

    print("\nReading values in loop. CTRL+C or Close window to stop.\n")

    # Create a buffer for fetching the values.
    y_axis = [0.0] * (RECORD_LENGTH * BUFFER_MULTIPLIER)
    x_start = 0

    try:
        while not closed:
            # Clear the plot and setup the axis.
            plt.clf()
            plt.axis()
            plt.xlabel("Samples")
            plt.ylabel("Amplitude")

            fetch_multiple_response = client.FetchMultiple(
                nidcpower_types.FetchMultipleRequest(vi=vi, timeout=10, count=RECORD_LENGTH)
            )
            check_for_error(vi, fetch_multiple_response.status)

            # Append the fetched values in the buffer.
            y_axis.extend(fetch_multiple_response.voltage_measurements)
            y_axis = y_axis[RECORD_LENGTH:]

            # Updating the precision of the fetched values.
            y_axis_new = []
            for value in y_axis:
                if value < VOLTAGE_LEVEL:
                    y_axis_new.append(math.floor(value * 100) / 100)
                else:
                    y_axis_new.append(math.ceil(value * 100) / 100)

            # Plotting
            y_axis = y_axis_new
            x_axis = np.arange(
                start=x_start, stop=x_start + RECORD_LENGTH * BUFFER_MULTIPLIER, step=1
            )
            x_start = x_start + RECORD_LENGTH
            plt.plot(x_axis, y_axis)
            plt.pause(0.001)
            time.sleep(0.1)

    except KeyboardInterrupt:
        pass

    print(f"Effective measurement rate : {1 / get_measure_record_delta_time.attribute_value}")

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
    if "vi" in vars() and vi.id != 0:
        # close the session.
        check_for_error(vi, (client.Close(nidcpower_types.CloseRequest(vi=vi))).status)
