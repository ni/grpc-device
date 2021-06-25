# This example demonstrates how to use the NI-Digital Pattern Driver API to create an
# instrument session, configure various voltage levels, and then burst a
# pattern. The vol, voh, vih, vil, iol, ioh and vcom values are configurable parameters and the
# user can select from High-Z (h), Active Load (a) and Three-Level Drive (t)
# termination options in termSelect.
#
# The gRPC API is built from the C API. NI-Digital Pattern Driver Pattern documentation is installed with
# the driver at: C:\Users\Public\Documents\National Instruments\NI-Digital-Pattern-Driver\Documentation\Digital Pattern Help.chm
# 
# Copy the .pinmap, .specs, .digitiming & .digipat files that come with this example to a folder on the server machine & copy-paste the path of the folder to the directory_path variable below.
# Use the NI Digital Pattern Editor to create or modify pin or channel map files.
# Link : https://www.ni.com/documentation/en/ni-digital/20.6/digital-pattern-editor/pin-channel-map-editor/
# 
# Getting Started:
#
# To run this example, install "NI-Digital Pattern Driver" on the server machine.
# Link :  https://www.ni.com/en-in/support/downloads/drivers/download.ni-digital-pattern-driver.html#367315
#
# For instructions on how to use protoc to generate gRPC client interfaces, see
# our "Creating a gRPC Client" wiki page.
# Link: https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client
#
# Refer to the NI-Digital Pattern Driver gRPC Wiki for the latest C Function Reference:
# Link: https://github.com/ni/grpc-device/wiki/NI-DIGITAL-PATTERN-DRIVER-C-Function-Reference
#
# Running from command line:
# Server machine's IP address, port number, and resource name can be passed as separate command line arguments.
#   > python configure-voltage-levels-and-termination-voltage.py <server_address> <port_number> <resource>
# If they are not passed in as command line arguments, then by default the server address will be "localhost:31763"
import grpc
import sys
import os
import nidigitalpattern_pb2 as nidigital_types
import nidigitalpattern_pb2_grpc as grpc_nidigital

server_address = "localhost"
server_port = "31763"
session_name = "NI-Digital-Pattern-Driver-Session"

# resource and options for a simulated 6570 client. Change them according to the NI-Digital Pattern Driver model.
resource = "PXI1Slot2"
options = "Simulate=1, DriverSetup=Model:6570"
# Provide the absolute path to the folder on the server machine containing the .pinmap, .specs, .digitiming & .digipat files.
directory_path = r""
if directory_path == "":
    print("\nProvide the absolute path to the folder on the server machine containing the .pinmap, .specs, .digitiming & .digipat files to the dirctory_path variable in the source code.")
    exit(1)
# Fixed parameters
channelList = "PinGroup1"
idQuery = False
resetDevice = False

# Configurable parameters
# The voltage that the instrument will apply to the DUT input pin when driving a logic low (0)
vil = 0
# The voltage that the instrument will apply to the DUT input pin when driving a logic high (1)
vih = 5
# The voltage below which the instrument pin comparator will interpret a logic low (L)
vol = 3
# The voltage above which the instrument pin comparator will interpret a logic high (H)
voh = 2
# The termination voltage the instrument applies during non-drive cycles when the termination mode is set to Vterm
vterm = 5
# The maximum current (A) the DUT sinks while outputting a voltage below VCOM
iol = 0.015
# The maximum current (A) the DUT sources while outputting a voltage above VCOM
ioh = -0.024
# The commutating voltage level at which the active load circuit switches between sourcing current and sinking current
vcom = 2
# Device termination mode [High-Z (h), Active Load (a), Three-Level Drive (t)]
termSelect = 'h'

# Read in cmd args
if len(sys.argv) >= 2:
    server_address = sys.argv[1]
if len(sys.argv) >= 3:
    server_port = sys.argv[2]
if len(sys.argv) >= 4:
    resource = sys.argv[3]
    options = ""

# Create the communication channel for the remote host and create connections to the NI-Digital Pattern Driver and session services.
channel = grpc.insecure_channel(f"{server_address}:{server_port}")
nidigital_client = grpc_nidigital.NiDigitalStub(channel)

any_error = False
# Checks for errors.  If any, throws an exception to stop the execution.
def CheckForError(vi, status) :
    global any_error
    if(status != 0 and not any_error):
        any_error = True
        ThrowOnError(vi, status)

# Converts an error code returned by NI-Digital Pattern Driver into a user-readable string.
def ThrowOnError(vi, error_code):
    error_message_request = nidigital_types.GetErrorRequest(vi = vi
    )
    error_message_response = nidigital_client.GetError(error_message_request)
    raise Exception(error_message_response.error_description)

try:
    # Open session to NI-Digital Pattern Driver with options
     init_with_options_response = nidigital_client.InitWithOptions(nidigital_types.InitWithOptionsRequest(session_name = session_name, 
         resource_name = resource, 
         id_query = True,
         reset_device = True,
         option_string = options))
     vi = init_with_options_response.vi
     CheckForError(vi, init_with_options_response.status)

     load_pin_map_response = nidigital_client.LoadPinMap(nidigital_types.LoadPinMapRequest(vi = vi,
         file_path = os.path.join(directory_path, 'PinMap.pinmap')))
     CheckForError(vi, load_pin_map_response.status)

     load_specification_response = nidigital_client.LoadSpecifications(nidigital_types.LoadSpecificationsRequest(vi = vi,
         file_path = os.path.join(directory_path, "Specifications.specs")))
     CheckForError(vi, load_specification_response.status)

     load_timing_response = nidigital_client.LoadTiming(nidigital_types.LoadTimingRequest(vi = vi,
         file_path = os.path.join(directory_path, "Timing.digitiming")))
     CheckForError(vi, load_timing_response.status)

     load_apply_levels_and_timing_response = nidigital_client.ApplyLevelsAndTiming(nidigital_types.ApplyLevelsAndTimingRequest(vi = vi,
         site_list = "",
         levels_sheet = "",
         timing_sheet = os.path.join(directory_path, "Timing.digitiming"),
         initial_state_high_pins = "",
         initial_state_low_pins = "",
         initial_state_tristate_pins = ""))
     CheckForError(vi, load_apply_levels_and_timing_response.status)

     load_pattern_response = nidigital_client.LoadPattern(nidigital_types.LoadPatternRequest(vi = vi,
         file_path = os.path.join(directory_path, "Pattern.digipat")))
     CheckForError(vi, load_pattern_response.status)

     configure_voltage_response = nidigital_client.ConfigureVoltageLevels(nidigital_types.ConfigureVoltageLevelsRequest(vi = vi,
         channel_list = channelList,
         vil = vil,
         vih = vih,
         vol = vol,
         voh = voh,
         vterm = vterm))
     CheckForError(vi, configure_voltage_response.status)
     
     if termSelect == 'h':
        configure_termination_Mode_response = nidigital_client.ConfigureTerminationMode(nidigital_types.ConfigureTerminationModeRequest(vi = vi,
            channel_list = channelList,
            mode = nidigital_types.TerminationMode.TERMINATION_MODE_NIDIGITAL_VAL_HIGH_Z))
        CheckForError(vi, configure_termination_Mode_response.status)

     if termSelect == 'a':
        configure_termination_Mode_response = nidigital_client.ConfigureTerminationMode(nidigital_types.ConfigureTerminationModeRequest(vi = vi,
            channel_list = channelList,
            mode = nidigital_types.TerminationMode.TERMINATION_MODE_NIDIGITAL_VAL_ACTIVE_LOAD))
        CheckForError(vi, configure_termination_Mode_response.status)

        
        configure_active_load_levels_response = nidigital_client.ConfigureActiveLoadLevels(nidigital_types.ConfigureActiveLoadLevelsRequest(vi = vi,
            channel_list = channelList,
            iol = iol,
            ioh = ioh,
            vcom = vcom))
        CheckForError(vi, configure_active_load_levels_response.status)

     if termSelect == 't':
        configure_termination_mode_response = nidigital_client.ConfigureTerminationMode(nidigital_types.ConfigureTerminationModeRequest(vi = vi,
            channel_list = channelList,
            mode = nidigital_types.TerminationMode.TERMINATION_MODE_NIDIGITAL_VAL_VTERM))
        CheckForError(vi, configure_termination_mode_response.status)

     if(termSelect != 'h' and termSelect != 'a' and termSelect != 't'):
        print('The value of termSelect is invalid. Please set it to one of \'h\', \'a\', or \'t\' values.')
        exit(0)
     
     burst_pattern_response = nidigital_client.BurstPattern(nidigital_types.BurstPatternRequest(vi = vi,
        site_list = "",
        start_label = "new_pattern",
        select_digital_function = True,
        wait_until_done = True,
        timeout = 10))
     CheckForError(vi, burst_pattern_response.status)

     select_function_response = nidigital_client.SelectFunction(nidigital_types.SelectFunctionRequest(vi = vi,
        channel_list = channelList,
        function_raw = nidigital_types.SelectedFunction.SELECTED_FUNCTION_NIDIGITAL_VAL_DISCONNECT))
     CheckForError(vi, select_function_response.status)

     print('The NI-Digital Pattern device was configured successfully.\n')

# If NI-Digital Pattern Driver API throws an exception, print the error message  
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE :
        error_message = f"Failed to connect to server on {server_address}:{server_port}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = "The operation is not implemented or is not supported/enabled in this service"
    print(f"{error_message}") 
finally:
    if('vi' in vars() and vi.id != 0):      
        # Close NI-Digital Pattern Driver session
        close_session_response = nidigital_client.Close(nidigital_types.CloseRequest(
            vi = vi
        ))
        CheckForError(vi, close_session_response.status)