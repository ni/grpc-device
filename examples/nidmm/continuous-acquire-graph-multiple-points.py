# 
# This example performs continuous multipoint acquisition and prints the number of points read and average value of measurements.
# 
# The gRPC API is built from the C API. NI-DMM documentation is installed with the driver at:
# C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niDMM\Documentation\English\DMM.chm
#
# Getting Started:
#
# To run this example, install "NI-DMM Driver" on the server machine.
# Link : https://www.ni.com/en-us/support/downloads/drivers/download.ni-dmm.html
#
# For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC Client" wiki page.
# Link: https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client
#
# Refer to the NI DMM gRPC Wiki for the latest C Function Reference:
# Link: https://github.com/ni/grpc-device/wiki/NI-DMM-C-Function-Reference
#
# Running from command line:
#
# Server machine's IP address, port number, and resource name can be passed as separate command line arguments.
#   > python continuous-acquire-graph-multiple-points.py <server_address> <port_number> <resource_name>
# If they are not passed in as command line arguments, then by default the server address will be "localhost:31763", with "SimulatedDMM" as the resource name

import grpc
import sys
import time
import nidmm_pb2 as nidmm_types
import nidmm_pb2_grpc as grpc_nidmm
import session_pb2 as session_types
import session_pb2_grpc as grpc_session
import matplotlib.pyplot as plt
import numpy as np
import keyword

server_address = "localhost"
server_port = "31763"
session_name = "NI-DMM-Session"

# Resource name and options for a simulated 4080 client. Change them according to the NI-DMM model.
resource = "SimulatedDMM"
options = "Simulate=1, DriverSetup=Model:4080; BoardType:PXIe"

# parameters
MAXPTSTOREAD        = 1000
config_range        = 10.0
resolution          = 5.5
measurementType     = nidmm_types.Function.FUNCTION_NIDMM_VAL_DC_VOLTS
powerlineFreq       = nidmm_types.PowerLineFrequencies.POWER_LINE_FREQUENCIES_NIDMM_VAL_60_HERTZ

# Read in cmd args
if len(sys.argv) >= 2:
    server_address = sys.argv[1]
if len(sys.argv) >= 3:
    server_port = sys.argv[2]
if len(sys.argv) >= 4:
    resource = sys.argv[3]
    options = ""

# Create the communication channel for the remote host and create connections to the NI-DMM and session services.
channel = grpc.insecure_channel(f"{server_address}:{server_port}")
nidmm_client = grpc_nidmm.NiDmmStub(channel)

any_error = False
# Checks for errors. If any, throws an exception to stop the execution.
def CheckForError (vi, status) :
    global any_error
    if(status != 0 and not any_error):
        any_error = True
        ThrowOnError (vi, status)

# Converts an error code returned by NI-DMM into a user-readable string.
def ThrowOnError (vi, error_code):
    error_message_request = nidmm_types.GetErrorMessageRequest(
        vi = vi,
        error_code = error_code
    )
    error_message_response = nidmm_client.GetErrorMessage(error_message_request)
    raise Exception (error_message_response.error_message)

try:
    # Open session to NI-DMM with options
    init_with_options_response = nidmm_client.InitWithOptions(nidmm_types.InitWithOptionsRequest(
        session_name = session_name,
        resource_name = resource,
        id_query = False,
        option_string = options
    ))
    vi = init_with_options_response.vi
    CheckForError(vi, init_with_options_response.status)

    # Configure measurement
    config_measurement_response = nidmm_client.ConfigureMeasurementDigits(nidmm_types.ConfigureMeasurementDigitsRequest(
        vi = vi,
        measurement_function = measurementType,
        range = config_range,
        resolution_digits = resolution
    ))
    CheckForError(vi, config_measurement_response.status)

    # Configure a multipoint acquisition
    config_multipoint_response = nidmm_client.ConfigureMultiPoint(nidmm_types.ConfigureMultiPointRequest(
        vi = vi,
        trigger_count_raw = 1,
        sample_count = nidmm_types.SampleCount.SAMPLE_COUNT_NIDMM_VAL_SAMPLE_COUNT_INFINITE,
        sample_trigger = nidmm_types.SampleTrigger.SAMPLE_TRIGGER_NIDMM_VAL_IMMEDIATE,
        sample_interval_raw = 0.0
    ))
    CheckForError(vi, config_multipoint_response.status)

    # Configure powerline frequency
    config_powlinefreq_response = nidmm_client.ConfigurePowerLineFrequency(nidmm_types.ConfigurePowerLineFrequencyRequest(
        vi = vi,
        power_line_frequency_hz = powerlineFreq
    ))
    CheckForError(vi, config_powlinefreq_response.status)

    # Initiate Acquisition
    initiate_acquisition_response = nidmm_client.Initiate(nidmm_types.InitiateRequest(
        vi = vi
    ))
    CheckForError(vi, initiate_acquisition_response.status)

    # Set while loop control
    stop_measurement = False

    # initialize variables
    num_measurements = 0
    sum_measurements = 0

    # Setup a plot to draw the captured waveform
    fig = plt.gcf()
    fig.show()
    fig.canvas.draw()
    fig.canvas.manager.set_window_title('Measurements')

    # Handle closing of plot window
    closed = False
    def on_close(event):
        global closed
        closed = True
    fig.canvas.mpl_connect('close_event', on_close)

    print("\nReading values in loop. CTRL+C or Close window to stop.\n")

    try:
        while not closed:
            pts_available = 0
            # Check available data
            read_status_response = nidmm_client.ReadStatus(nidmm_types.ReadStatusRequest(
                vi = vi
            ))
            CheckForError(vi, read_status_response.status)
            pts_available = read_status_response.acquisition_backlog

            # if there are more than MAXPTSTOREAD measurements
            # available, set pts_available to MAXPTSTOREAD in order to
            # avoid reallocating the array for measurements
            pts_available = min(pts_available, MAXPTSTOREAD)
            if pts_available > 0:
                # Clear the plot and setup the axis
                plt.clf()
                plt.axis()
                plt.xlabel('Samples')
                plt.ylabel('Amplitude')

                # Fetch data
                fetch_multipoints_response = nidmm_client.FetchMultiPoint(nidmm_types.FetchMultiPointRequest(
                    vi = vi,
                    maximum_time = -1,
                    array_size = pts_available
                ))
                CheckForError(vi, fetch_multipoints_response.status)
                num_pts_read = fetch_multipoints_response.actual_number_of_points
                measurements = np.array(fetch_multipoints_response.reading_array)
                
                # retain data to 2 decimals
                measurements = np.floor(measurements * 100) / 100.0

                # Update the plot with the new measurements
                plt.plot(measurements)
                fig.canvas.draw()
                plt.pause(0.001)

                # Increment number of measurements
                num_measurements += num_pts_read

                # Calculate sum
                for i in range(num_pts_read):
                    sum_measurements += measurements[i]
                
                time.sleep(0.1)
    except KeyboardInterrupt:
        pass

    print(f'Number of measurements = {num_measurements}')
    # Calculate average
    average = sum_measurements/num_measurements
    print(f'Average = {average}')

# If NI-DMM API throws an exception, print the error message  
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE :
        error_message = f"Failed to connect to server on {server_address}:{server_port}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = "The operation is not implemented or is not supported/enabled in this service"
    print(f"{error_message}") 
finally:
    if('vi' in vars() and vi.id != 0):
        # Close NI-DMM session
        close_session_response = nidmm_client.Close(nidmm_types.CloseRequest(
            vi = vi
        ))
        CheckForError(vi, close_session_response.status)
