r"""Read synchronized waveforms from multiple NI-SCOPE devices.

Tested with a 100 kHz tone input to channel 0.

The gRPC API is built from the C API. NI-SCOPE documentation is installed with the driver at:
  C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niScope\Documentation\English\Digitizers.chm

A version of this .chm is available online at:
  https://zone.ni.com/reference/en-XX/help/370592AB-01/

Getting Started:

To run this example, install "NI-SCOPE Driver" on the server machine:
  https://www.ni.com/en-us/support/downloads/drivers/download.ni-scope.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-SCOPE gRPC Wiki to determine the valid channel and resource names for your NI-SCOPE
module:
  https://github.com/ni/grpc-device/wiki/NI-SCOPE-C-Function-Reference

Refer to the NI-TClk gRPC Wiki to determine the valid channel and resource names for your NI-TClk
module:
  https://github.com/ni/grpc-device/wiki/NI-TClk-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and multiple comma separated resource names can be
passed as separate command line arguments.
  > python multi-device-configured-acquisition-tclk.py <server_address> <port_number> <resource_name1,resource_name2>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedScope1" and "SimulatedScope2" as the resource names.
"""  # noqa: W505

import sys
import time

import grpc
import matplotlib.pyplot as plt
import niscope_pb2 as niscope_types
import niscope_pb2_grpc as grpc_scope
import nitclk_pb2 as nitclk_types
import nitclk_pb2_grpc as grpc_tclk
import numpy as np

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"

# Resource name and options for a simulated 5164 client. Change them according to the NI-SCOPE
# model.
OPTIONS = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe;"
RESOURCES = ["SimulatedScope1", "SimulatedScope2"]

# Parameters
CHANNELS = "0"
previous_max_input_frequency = -10.0
previous_min_sample_rate = -10
previous_min_record_length = -10
trigger_type = "-10"
max_input_frequency = 0.0
min_sample_rate = 1000000
num_records = 1

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    RESOURCES = [r.strip() for r in sys.argv[3].split(",")]
    OPTIONS = ""

# Create the communication channel for the remote host (in this case we are connecting to a local
# server) and create a connection to the NI-SCOPE service and NI-TClk service.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
niscope_client = grpc_scope.NiScopeStub(channel)
nitclk_client = grpc_tclk.NiTClkStub(channel)
sessions = []


def check_for_error(client, vi, status):
    """Raise an exception if the status indicates an error."""
    if status != 0:
        if client == niscope_client:
            error_message_request = niscope_types.GetErrorMessageRequest(vi=vi, error_code=status)
            error_message_response = niscope_client.GetErrorMessage(error_message_request)
            raise Exception(error_message_response.error_message)
        else:
            error_message_request = nitclk_types.GetExtendedErrorInfoRequest()
            error_message_response = nitclk_client.GetExtendedErrorInfo(error_message_request)
            raise Exception(error_message_response.error_string)


try:
    # Initialize the session
    i = 1
    for resource in RESOURCES:
        init_result = niscope_client.InitWithOptions(
            niscope_types.InitWithOptionsRequest(
                session_name="session" + str(i),
                resource_name=resource,
                id_query=False,
                reset_device=False,
                option_string=OPTIONS,
            )
        )
        i = i + 1
        sessions.append(init_result.vi)
        check_for_error(niscope_client, init_result.vi, init_result.status)

    for session in sessions:
        # Configure Acquisition Type
        acquisition_type_result = niscope_client.ConfigureAcquisition(
            niscope_types.ConfigureAcquisitionRequest(
                vi=session, acquisition_type=0  # NISCOPE_VAL_NORMAL
            )
        )
        check_for_error(niscope_client, session, acquisition_type_result.status)

        # Configure Vertical
        vertical_result = niscope_client.ConfigureVertical(
            niscope_types.ConfigureVerticalRequest(
                vi=session,
                channel_list=CHANNELS,
                range=10.0,
                offset=0.0,
                coupling=niscope_types.VerticalCoupling.VERTICAL_COUPLING_NISCOPE_VAL_DC,
                enabled=True,
                probe_attenuation=1.0,
            )
        )
        check_for_error(niscope_client, session, vertical_result.status)

        # Configure Channel Characteristics
        channel_characteristics_result = niscope_client.ConfigureChanCharacteristics(
            niscope_types.ConfigureChanCharacteristicsRequest(
                vi=session,
                channel_list=CHANNELS,
                input_impedance=1000000.0,
                max_input_frequency=0.0,
            )
        )
        check_for_error(niscope_client, session, channel_characteristics_result.status)

        # Configure Horizontal Timing
        config_result = niscope_client.ConfigureHorizontalTiming(
            niscope_types.ConfigureHorizontalTimingRequest(
                vi=session,
                min_sample_rate=100000000.0,
                min_num_pts=1000,
                ref_position=50,
                num_records=1,
                enforce_realtime=True,
            )
        )
        check_for_error(niscope_client, session, config_result.status)

    vi = sessions[0]
    # Get the trigger type from the user
    print("Type the trigger type\n")
    print("1 - Edge\n")
    print("2 - Hysteresis\n")
    print("3 - Digital\n")
    print("4 - Window\n")
    print("5 - Immediate\n")
    trigger_type = input("Option: ")

    # Assign the default values for the trigger attribute that depends on the trigger type
    if trigger_type == "1":
        trigger_edge_result = niscope_client.ConfigureTriggerEdge(
            niscope_types.ConfigureTriggerEdgeRequest(
                vi=vi,
                trigger_source="0",
                level=0.0,
                slope=niscope_types.TriggerSlope.TRIGGER_SLOPE_NISCOPE_VAL_POSITIVE,
                trigger_coupling=niscope_types.TriggerCoupling.TRIGGER_COUPLING_NISCOPE_VAL_DC,
                holdoff=0.0,
                delay=0.0,
            )
        )
        check_for_error(niscope_client, vi, trigger_edge_result.status)
    elif trigger_type == "2":
        trigger_hysteresis_result = niscope_client.ConfigureTriggerHysteresis(
            niscope_types.ConfigureTriggerHysteresisRequest(
                vi=vi,
                trigger_source="0",
                level=0.0,
                hysteresis=0.1,
                slope=niscope_types.TriggerSlope.TRIGGER_SLOPE_NISCOPE_VAL_POSITIVE,
                trigger_coupling=niscope_types.TriggerCoupling.TRIGGER_COUPLING_NISCOPE_VAL_DC,
                holdoff=0.0,
                delay=0.0,
            )
        )
        check_for_error(niscope_client, vi, trigger_hysteresis_result.status)
    elif trigger_type == "3":
        trigger_digital_result = niscope_client.ConfigureTriggerDigital(
            niscope_types.ConfigureTriggerDigitalRequest(
                vi=vi,
                trigger_source="VAL_PFI_1",
                slope=niscope_types.TriggerSlope.TRIGGER_SLOPE_NISCOPE_VAL_POSITIVE,
                holdoff=0.0,
                delay=0.0,
            )
        )
        check_for_error(niscope_client, vi, trigger_digital_result.status)
    elif trigger_type == "4":
        trigger_window_result = niscope_client.ConfigureTriggerWindow(
            niscope_types.ConfigureTriggerWindowRequest(
                vi=vi,
                trigger_source="0",
                low_level=-0.1,
                high_level=0.1,
                window_mode=niscope_types.TriggerWindowMode.TRIGGER_WINDOW_MODE_NISCOPE_VAL_ENTERING_WINDOW,
                trigger_coupling=niscope_types.TriggerCoupling.TRIGGER_COUPLING_NISCOPE_VAL_DC,
                holdoff=0.0,
                delay=0.0,
            )
        )
        check_for_error(niscope_client, vi, trigger_window_result.status)
    elif trigger_type == "5":
        trigger_immediate_result = niscope_client.ConfigureTriggerImmediate(
            niscope_types.ConfigureTriggerImmediateRequest(vi=vi)
        )
        check_for_error(niscope_client, vi, trigger_immediate_result.status)
    else:
        raise Exception("Enter a Valid Input")

    if (
        previous_min_sample_rate != min_sample_rate
        or previous_max_input_frequency != max_input_frequency
        or previous_min_record_length != num_records
    ):
        # Use NI-TClk to configure appropriate parameters, synchronize digitizers, and initiate
        # operation.
        homogenous_trigger_result = nitclk_client.ConfigureForHomogeneousTriggers(
            nitclk_types.ConfigureForHomogeneousTriggersRequest(sessions=sessions)
        )
        check_for_error(nitclk_client, vi, homogenous_trigger_result.status)

        synchronize_result = nitclk_client.Synchronize(
            nitclk_types.SynchronizeRequest(sessions=sessions, min_tclk_period=0.0)
        )
        check_for_error(nitclk_client, vi, synchronize_result.status)
    previous_min_sample_rate = min_sample_rate
    previous_max_input_frequency = max_input_frequency
    previous_min_record_length = num_records

    initiate_result = nitclk_client.Initiate(nitclk_types.InitiateRequest(sessions=sessions))
    check_for_error(nitclk_client, vi, initiate_result.status)

    # Setup a plot to draw the captured waveform
    fig = plt.figure("Waveform Graph")
    fig.show()
    fig.canvas.draw()

    # Handle closing of plot window.
    closed = False

    def _on_close(event):
        global closed
        closed = True

    fig.canvas.mpl_connect("close_event", _on_close)
    print("\nReading values in loop. CTRL+C to stop.\n")
    try:
        while not closed:
            # Clear the plot and setup the axis
            fig.clf()
            plt.axis([0, 500, -6, 6])
            # Fetch a waveform from the scope
            for i in range(len(sessions)):
                fetch_result = niscope_client.Fetch(
                    niscope_types.FetchRequest(
                        vi=sessions[i], channel_list=CHANNELS, timeout=1, num_samples=500
                    )
                )
                check_for_error(niscope_client, session, fetch_result.status)
                plt.subplot(1, len(sessions), i + 1, label=str(i))
                # Round the array to 2 decimal places and Update the plot with the new waveform
                data = np.array(fetch_result.waveform[0:500])
                # Add labels for axes and legends
                plt.ylabel("Amplitude")
                plt.xlabel("Samples")
                plt.plot(np.round(data, 2))
                plt.title(label="$Scope{i}$".format(i=i))
            plt.subplots_adjust(wspace=0.5)
            plt.pause(0.001)
            time.sleep(0.1)
    except KeyboardInterrupt:
        pass

    for i in range(len(sessions)):
        sample_rate_result = niscope_client.SampleRate(niscope_types.SampleRateRequest(vi=session))
        record_length_result = niscope_client.ActualRecordLength(
            niscope_types.ActualRecordLengthRequest(vi=session)
        )
        print(RESOURCES[i])
        print("Actual Sample Rate = %f" % sample_rate_result.sample_rate)
        print("Actual Record Length = %f\n" % record_length_result.record_length)

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
        # close the sessions.
        for session in sessions:
            close_request_result = niscope_client.Close(niscope_types.CloseRequest(vi=session))
            check_for_error(niscope_client, session, close_request_result.status)
