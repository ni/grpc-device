r"""Perform continuous multipoint acquisition; print the number of points read and average value.

The gRPC API is built from the C API. NI-DMM documentation is installed with the driver at:
  C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niDMM\Documentation\English\DMM.chm

Getting Started:

To run this example, install "NI-DMM Driver" on the server machine:
  https://www.ni.com/en-us/support/downloads/drivers/download.ni-dmm.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI DMM gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-DMM-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and resource name can be passed as separate command line
arguments.
  > python continuous-acquire-graph-multiple-points.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedDMM" as the resource name.
"""  # noqa: W505

import sys
import time

import grpc
import matplotlib.pyplot as plt
import nidmm_pb2 as nidmm_types
import nidmm_pb2_grpc as grpc_nidmm
import numpy as np

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "NI-DMM-Session"

# Resource name and options for a simulated 4080 client. Change them according to the NI-DMM model.
RESOURCE = "SimulatedDMM"
OPTIONS = "Simulate=1, DriverSetup=Model:4080; BoardType:PXIe"

# parameters
MAX_PTS_TO_READ = 1000
CONFIG_RANGE = 10.0
RESOLUTION = 5.5
MEASUREMENT_TYPE = nidmm_types.Function.FUNCTION_NIDMM_VAL_DC_VOLTS
POWERLINE_FREQ = nidmm_types.PowerLineFrequencies.POWER_LINE_FREQUENCIES_NIDMM_VAL_60_HERTZ

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    RESOURCE = sys.argv[3]
    OPTIONS = ""

# Create the communication channel for the remote host and create connections to the NI-DMM and
# session services.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
nidmm_client = grpc_nidmm.NiDmmStub(channel)


def check_for_error(vi, status):
    """Raise an exception if the status indicates an error."""
    if status != 0:
        error_message_response = nidmm_client.ErrorMessage(
            nidmm_types.ErrorMessageRequest(vi=vi, error_code=status)
        )
        raise Exception(error_message_response.error_message)


def check_for_initialization_error(response):
    """Raise an exception if an error was returned from Initialize."""
    if response.status < 0:
        raise RuntimeError(f"Error: {response.error_message or response.status}")
    if response.status > 0:
        sys.stderr.write(f"Warning: {response.error_message or response.status}\n")


try:
    # Open session to NI-DMM with options
    init_with_options_response = nidmm_client.InitWithOptions(
        nidmm_types.InitWithOptionsRequest(
            session_name=SESSION_NAME, resource_name=RESOURCE, id_query=False, option_string=OPTIONS
        )
    )
    vi = init_with_options_response.vi
    check_for_initialization_error(init_with_options_response)

    # Configure measurement
    config_measurement_response = nidmm_client.ConfigureMeasurementDigits(
        nidmm_types.ConfigureMeasurementDigitsRequest(
            vi=vi,
            measurement_function=MEASUREMENT_TYPE,
            range=CONFIG_RANGE,
            resolution_digits=RESOLUTION,
        )
    )
    check_for_error(vi, config_measurement_response.status)

    # Configure a multipoint acquisition
    config_multipoint_response = nidmm_client.ConfigureMultiPoint(
        nidmm_types.ConfigureMultiPointRequest(
            vi=vi,
            trigger_count_raw=1,
            sample_count=nidmm_types.SampleCount.SAMPLE_COUNT_NIDMM_VAL_SAMPLE_COUNT_INFINITE,
            sample_trigger=nidmm_types.SampleTrigger.SAMPLE_TRIGGER_NIDMM_VAL_IMMEDIATE,
            sample_interval_raw=0.0,
        )
    )
    check_for_error(vi, config_multipoint_response.status)

    # Configure powerline frequency
    config_powlinefreq_response = nidmm_client.ConfigurePowerLineFrequency(
        nidmm_types.ConfigurePowerLineFrequencyRequest(
            vi=vi, power_line_frequency_hz=POWERLINE_FREQ
        )
    )
    check_for_error(vi, config_powlinefreq_response.status)

    # Initiate Acquisition
    initiate_acquisition_response = nidmm_client.Initiate(nidmm_types.InitiateRequest(vi=vi))
    check_for_error(vi, initiate_acquisition_response.status)

    # Set while loop control
    stop_measurement = False

    # initialize variables
    num_measurements = 0
    sum_measurements = 0

    # Setup a plot to draw the captured waveform
    fig = plt.gcf()
    fig.show()
    fig.canvas.draw()
    fig.canvas.manager.set_window_title("Measurements")

    # Handle closing of plot window
    closed = False

    def _on_close(event):
        global closed
        closed = True

    fig.canvas.mpl_connect("close_event", _on_close)

    print("\nReading values in loop. CTRL+C or Close window to stop.\n")

    try:
        while not closed:
            pts_available = 0
            # Check available data
            read_status_response = nidmm_client.ReadStatus(nidmm_types.ReadStatusRequest(vi=vi))
            check_for_error(vi, read_status_response.status)
            pts_available = read_status_response.acquisition_backlog

            # if there are more than MAX_PTS_TO_READ measurements available, set pts_available to
            # MAX_PTS_TO_READ in order to avoid reallocating the array for measurements
            pts_available = min(pts_available, MAX_PTS_TO_READ)
            if pts_available > 0:
                # Clear the plot and setup the axis
                plt.clf()
                plt.axis()
                plt.xlabel("Samples")
                plt.ylabel("Amplitude")

                # Fetch data
                fetch_multipoints_response = nidmm_client.FetchMultiPoint(
                    nidmm_types.FetchMultiPointRequest(
                        vi=vi, maximum_time=-1, array_size=pts_available
                    )
                )
                check_for_error(vi, fetch_multipoints_response.status)
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

    print(f"Number of measurements = {num_measurements}")
    # Calculate average
    average = sum_measurements / num_measurements
    print(f"Average = {average}")

# If NI-DMM API throws an exception, print the error message
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
        # Close NI-DMM session
        close_session_response = nidmm_client.Close(nidmm_types.CloseRequest(vi=vi))
        check_for_error(vi, close_session_response.status)
