# This example performs continuous measure record.
# 
# The gRPC API is built from the C API. NI-DCPower documentation is installed with the driver at:
# C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niDCPower\Documentation\NIDCPowerCref.chm
#
# Getting Started:
#
# To run this example, install "NI-DCPower Driver" on the server machine.
# Link : https://www.ni.com/en-in/support/downloads/drivers/download.ni-dcpower.html
#
# For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC Client" wiki page.
# Link: https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client
#
# Refer to the NI DCPOWER gRPC Wiki for the latest C Function Reference:
# Link: https://github.com/ni/grpc-device/wiki/NI-DCPOWER-C-Function-Reference
#
# Running from command line:
#
# Server machine's IP address, port number, and resource name can be passed as separate command line arguments.
#   > python measure-record.py <server_address> <port_number> <resource_name>
# If they are not passed in as command line arguments, then by default the server address will be "localhost:31763", with "SimulatedDCPower" as the resource name

import grpc
import sys
import time
import nidcpower_pb2 as nidcpower_types
import nidcpower_pb2_grpc as grpc_nidcpower
import matplotlib.pyplot as plt
import keyword
import numpy as np
import math

server_address = "localhost"
server_port = "31763"
session_name = "NI-DCPower-Session"

# Resource name, channel name and options for a simulated 4147 client. Change them according to NI-DCPower model.
resource = "SimulatedDCPower"
options = "Simulate=1,DriverSetup=Model:4147;BoardType:PXIe"
channels = "0"

# Parameters
record_length = 10
buffer_multiplier = 10
voltage_level = 5.0

# Read in cmd args
if len(sys.argv) >= 2:
    server_address = sys.argv[1]
if len(sys.argv) >= 3:
    server_port = sys.argv[2]
if len(sys.argv) >= 4:
    resource = sys.argv[3]
    options = ""

# Checks for errors. If any, throws an exception to stop the execution.
any_error = False
def CheckForError (vi, status) :
    global any_error
    if(status != 0 and not any_error):
        any_error = True
        ThrowOnError (vi, status)

def ThrowOnError (vi, error_code):
    error_message_request = nidcpower_types.ErrorMessageRequest(
        vi = vi,
        error_code = error_code
        )
    error_message_response = client.ErrorMessage(error_message_request)
    raise Exception (error_message_response.error_message)

# Create the communication channel for the remote host and create connections to the NI-DCPower and session services.
channel = grpc.insecure_channel(f"{server_address}:{server_port}")
client = grpc_nidcpower.NiDCPowerStub(channel)

try :
    # Initialize the session.
    initialize_with_channels_response = client.InitializeWithChannels(nidcpower_types.InitializeWithChannelsRequest(
        session_name = session_name,
        resource_name = resource,
        channels = channels,
        reset = False,
        option_string = options
    ))
    vi = initialize_with_channels_response.vi
    CheckForError(vi, initialize_with_channels_response.status)

    # Specify when the measure unit should acquire measurements.
    configure_measure_when = client.SetAttributeViInt32(nidcpower_types.SetAttributeViInt32Request(
        vi = vi,
        attribute_id = nidcpower_types.NiDCPowerAttributes.NIDCPOWER_ATTRIBUTE_MEASURE_WHEN,
        attribute_value = nidcpower_types.NiDCPowerInt32AttributeValues.NIDCPOWER_INT32_MEASURE_WHEN_VAL_AUTOMATICALLY_AFTER_SOURCE_COMPLETE
    ))
    CheckForError(vi, configure_measure_when.status)

    # set the voltage level.
    configure_voltage_level = client.ConfigureVoltageLevel(nidcpower_types.ConfigureVoltageLevelRequest(
        vi = vi,
        level = voltage_level
    ))
    CheckForError(vi, configure_voltage_level.status)

    # Sspecify how many measurements compose a measure record.
    configure_measure_record_length = client.SetAttributeViInt32(nidcpower_types.SetAttributeViInt32Request(
        vi = vi,
        attribute_id = nidcpower_types.NiDCPowerAttributes.NIDCPOWER_ATTRIBUTE_MEASURE_RECORD_LENGTH,
        attribute_value = record_length
    ))
    CheckForError(vi, configure_measure_record_length.status)

    # Specify whether to take continuous measurements. Set it to False for continuous measurement.
    configure_measure_record_length_is_finite = client.SetAttributeViBoolean(nidcpower_types.SetAttributeViBooleanRequest(
        vi = vi,
        attribute_id = nidcpower_types.NiDCPowerAttributes.NIDCPOWER_ATTRIBUTE_MEASURE_RECORD_LENGTH_IS_FINITE,
        attribute_value = False
    ))
    CheckForError(vi, configure_measure_record_length_is_finite.status)

    # commit the session.
    commit_response = client.Commit(nidcpower_types.CommitRequest(
        vi = vi,
    ))
    CheckForError(vi, commit_response.status)

    # get measure_record_delta_time.
    get_measure_record_delta_time = client.GetAttributeViReal64(nidcpower_types.GetAttributeViReal64Request(
       vi = vi,
       attribute_id =  nidcpower_types.NiDCPowerAttributes.NIDCPOWER_ATTRIBUTE_MEASURE_RECORD_DELTA_TIME
    ))
    CheckForError(vi, get_measure_record_delta_time.status)

    # initiate the session.
    initiate_response = client.Initiate(nidcpower_types.InitiateRequest(
        vi = vi,
    ))
    CheckForError(vi, initiate_response.status)

    # Setup a plot to draw the captured waveform.
    fig = plt.figure("Waveform Graph")
    fig.show()
    fig.canvas.draw()

    # Handle closing of plot window.
    closed = False
    def on_close(event):
        global closed
        closed = True
    fig.canvas.mpl_connect('close_event', on_close)

    print("\nReading values in loop. CTRL+C or Close window to stop.\n")

    # Create a buffer for fetching the values.
    y_axis = [0] * (record_length * buffer_multiplier)
    x_start = 0

    try:
        while not closed:
            # Clear the plot and setup the axis.
            plt.clf()
            plt.axis()
            plt.xlabel("Samples")
            plt.ylabel("Amplitude")

            fetch_multiple_response = client.FetchMultiple(nidcpower_types.FetchMultipleRequest(
                vi = vi,
                timeout = 10,
                count = record_length
            ))
            CheckForError(vi, fetch_multiple_response.status)
            
            # Append the fetched values in the buffer.
            y_axis.extend(fetch_multiple_response.voltage_measurements)
            y_axis = y_axis[record_length:]
            
            # Updating the precision of the fetched values.
            y_axis_new = []
            for value in y_axis:
                if (value < voltage_level):
                    y_axis_new.append(math.floor(value * 100) / 100)
                else:
                    y_axis_new.append(math.ceil(value * 100) / 100)

            # Plotting
            y_axis = y_axis_new
            x_axis = np.arange(start = x_start, stop = x_start + record_length * buffer_multiplier, step = 1)
            x_start = x_start + record_length
            plt.plot(x_axis, y_axis)
            plt.pause(0.001)
            time.sleep(0.1)
            
    except KeyboardInterrupt:
        pass

    print(f"Effective measurement rate : {1 / get_measure_record_delta_time.attribute_value}")

except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE :
        error_message = f"Failed to connect to server on {server_address}:{server_port}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = "The operation is not implemented or is not supported/enabled in this service"
    print(f"{error_message}")

finally:
    if('vi' in vars() and vi.id != 0):
        # close the session.
        CheckForError(vi, (client.Close(nidcpower_types.CloseRequest(
            vi = vi
        ))).status)