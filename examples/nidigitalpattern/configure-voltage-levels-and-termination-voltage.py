r"""Create an instrument session, configure various voltage levels, and then burst a pattern.

The VOL, VOH, VIH, VIL, VTERM, IOL, IOH, and VCOM values are configurable parameters and the user
can select from High-Z (h), Active Load (a) and Three-Level Drive (t) termination options in
TERM_SELECT.

The gRPC API is built from the C API. NI-Digital Pattern Driver Pattern documentation is installed
with the driver at:
  C:\Users\Public\Documents\National Instruments\NI-Digital-Pattern-Driver\Documentation\Digital Pattern Help.chm

Copy the .pinmap, .specs, .digitiming & .digipat files that come with this example to a folder on
the server machine & copy-paste the path of the folder to the DIRECTORY_PATH variable below.

Use the NI Digital Pattern Editor to create or modify pin or channel map files:
  https://www.ni.com/documentation/en/ni-digital/20.6/digital-pattern-editor/pin-channel-map-editor/

Getting Started:

To run this example, install "NI-Digital Pattern Driver" on the server machine:
  https://www.ni.com/en-in/support/downloads/drivers/download.ni-digital-pattern-driver.html#367315

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-Digital Pattern Driver gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-DIGITAL-PATTERN-DRIVER-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and resource name can be passed as separate command line
arguments.
  > python configure-voltage-levels-and-termination-voltage.py <server_address> <port_number> <resource>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "PXI1Slot2" as the resource name.
"""  # noqa: W505

import json
import os
import sys

import grpc
import nidigitalpattern_pb2 as nidigital_types
import nidigitalpattern_pb2_grpc as grpc_nidigital

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "NI-Digital-Pattern-Driver-Session"

# Resource and options for a simulated 6570 client. Change them according to the NI-Digital Pattern
# Driver model.
RESOURCE = "PXI1Slot2"
OPTIONS = "Simulate=1, DriverSetup=Model:6570"
# Provide the absolute path to the folder on the server machine containing the .pinmap, .specs,
# .digitiming & .digipat files.
DIRECTORY_PATH = r""
if DIRECTORY_PATH == "":
    print(
        "\nProvide the absolute path to the folder on the server machine containing the .pinmap, .specs, .digitiming & .digipat files to the dirctory_path variable in the source code."
    )
    exit(1)
# Fixed parameters
CHANNEL_LIST = "PinGroup1"

# Configurable parameters
# The voltage that the instrument will apply to the DUT input pin when driving a logic low (0)
VIL = 0
# The voltage that the instrument will apply to the DUT input pin when driving a logic high (1)
VIH = 5
# The voltage below which the instrument pin comparator will interpret a logic low (L)
VOL = 3
# The voltage above which the instrument pin comparator will interpret a logic high (H)
VOH = 2
# The termination voltage the instrument applies during non-drive cycles when the termination mode
# is set to Vterm
VTERM = 5
# The maximum current (A) the DUT sinks while outputting a voltage below VCOM
IOL = 0.015
# The maximum current (A) the DUT sources while outputting a voltage above VCOM
IOH = -0.024
# The commutating voltage level at which the active load circuit switches between sourcing current
# and sinking current
VCOM = 2
# Device termination mode [High-Z (h), Active Load (a), Three-Level Drive (t)]
TERM_SELECT = "h"

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    RESOURCE = sys.argv[3]
    OPTIONS = ""

# Create the communication channel for the remote host and create connections to the NI-Digital
# Pattern Driver and session services.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
nidigital_client = grpc_nidigital.NiDigitalStub(channel)


def check_for_warning(response, vi):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        warning_message = nidigital_client.ErrorMessage(
            nidigital_types.ErrorMessageRequest(vi=vi, error_code=response.status)
        )
        sys.stderr.write(f"{warning_message.error_message}\nWarning status: {response.status}\n")


try:
    # Open session to NI-Digital Pattern Driver with options
    init_with_options_response = nidigital_client.InitWithOptions(
        nidigital_types.InitWithOptionsRequest(
            session_name=SESSION_NAME,
            resource_name=RESOURCE,
            id_query=True,
            reset_device=True,
            option_string=OPTIONS,
        )
    )
    vi = init_with_options_response.vi

    load_pin_map_response = nidigital_client.LoadPinMap(
        nidigital_types.LoadPinMapRequest(
            vi=vi,
            file_path=os.path.join(DIRECTORY_PATH, "PinMap.pinmap"),
        )
    )

    load_specification_response = nidigital_client.LoadSpecifications(
        nidigital_types.LoadSpecificationsRequest(
            vi=vi,
            file_path=os.path.join(DIRECTORY_PATH, "Specifications.specs"),
        )
    )

    load_timing_response = nidigital_client.LoadTiming(
        nidigital_types.LoadTimingRequest(
            vi=vi,
            file_path=os.path.join(DIRECTORY_PATH, "Timing.digitiming"),
        )
    )

    load_apply_levels_and_timing_response = nidigital_client.ApplyLevelsAndTiming(
        nidigital_types.ApplyLevelsAndTimingRequest(
            vi=vi,
            site_list="",
            levels_sheet="",
            timing_sheet=os.path.join(DIRECTORY_PATH, "Timing.digitiming"),
            initial_state_high_pins="",
            initial_state_low_pins="",
            initial_state_tristate_pins="",
        )
    )

    load_pattern_response = nidigital_client.LoadPattern(
        nidigital_types.LoadPatternRequest(
            vi=vi,
            file_path=os.path.join(DIRECTORY_PATH, "Pattern.digipat"),
        )
    )

    configure_voltage_response = nidigital_client.ConfigureVoltageLevels(
        nidigital_types.ConfigureVoltageLevelsRequest(
            vi=vi,
            channel_list=CHANNEL_LIST,
            vil=VIL,
            vih=VIH,
            vol=VOL,
            voh=VOH,
            vterm=VTERM,
        )
    )

    if TERM_SELECT == "h":
        configure_termination_mode_response = nidigital_client.ConfigureTerminationMode(
            nidigital_types.ConfigureTerminationModeRequest(
                vi=vi,
                channel_list=CHANNEL_LIST,
                mode=nidigital_types.TerminationMode.TERMINATION_MODE_NIDIGITAL_VAL_HIGH_Z,
            )
        )

    if TERM_SELECT == "a":
        configure_termination_mode_response = nidigital_client.ConfigureTerminationMode(
            nidigital_types.ConfigureTerminationModeRequest(
                vi=vi,
                channel_list=CHANNEL_LIST,
                mode=nidigital_types.TerminationMode.TERMINATION_MODE_NIDIGITAL_VAL_ACTIVE_LOAD,
            )
        )

        configure_active_load_levels_response = nidigital_client.ConfigureActiveLoadLevels(
            nidigital_types.ConfigureActiveLoadLevelsRequest(
                vi=vi,
                channel_list=CHANNEL_LIST,
                iol=IOL,
                ioh=IOH,
                vcom=VCOM,
            )
        )

    if TERM_SELECT == "t":
        configure_termination_mode_response = nidigital_client.ConfigureTerminationMode(
            nidigital_types.ConfigureTerminationModeRequest(
                vi=vi,
                channel_list=CHANNEL_LIST,
                mode=nidigital_types.TerminationMode.TERMINATION_MODE_NIDIGITAL_VAL_VTERM,
            )
        )

    if TERM_SELECT != "h" and TERM_SELECT != "a" and TERM_SELECT != "t":
        print(
            "The value of TERM_SELECT is invalid. Please set it to one of 'h', 'a', or 't' values."
        )
        exit(0)

    burst_pattern_response = nidigital_client.BurstPattern(
        nidigital_types.BurstPatternRequest(
            vi=vi,
            site_list="",
            start_label="new_pattern",
            select_digital_function=True,
            wait_until_done=True,
            timeout=10,
        )
    )
    check_for_warning(burst_pattern_response, vi)

    select_function_response = nidigital_client.SelectFunction(
        nidigital_types.SelectFunctionRequest(
            vi=vi,
            channel_list=CHANNEL_LIST,
            function_raw=nidigital_types.SelectedFunction.SELECTED_FUNCTION_NIDIGITAL_VAL_DISCONNECT,
        )
    )
    check_for_warning(select_function_response, vi)

    print("The NI-Digital Pattern device was configured successfully.\n")

# If NI-Digital Pattern Driver API throws an exception, print the error message
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE:
        error_message = f"Failed to connect to server on {SERVER_ADDRESS}:{SERVER_PORT}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = (
            "The operation is not implemented or is not supported/enabled in this service"
        )
    elif rpc_error.code() == grpc.StatusCode.UNKNOWN:
        try:
            error_details = json.loads(error_message)
            error_message = f"{error_details['message']}\nError status: {error_details['code']}"
        except (json.JSONDecodeError, KeyError):
            pass
    print(f"{error_message}")
finally:
    if "vi" in vars() and vi.id != 0:
        # Close NI-Digital Pattern Driver session
        nidigital_client.Close(nidigital_types.CloseRequest(vi=vi))
