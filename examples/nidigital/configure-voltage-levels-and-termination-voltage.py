# This example demonstrates how to use the NI-Digital Pattern Driver API to create an
# instrument session, configure various voltage levels, and then burst a
# pattern. The vol, voh, vih, vil, iol, ioh and vcom values are configurable parameters and the
# user can select from High-Z (h), Active Load (a) and Three-Level Drive (t)
# termination options in termSelect.
#
# The gRPC API is built from the C API.  NI-Digital documentation is installed with
# the driver at:
# C:\Users\Public\Documents\National Instruments\NI-Digital\Documentation\Digital Pattern Help.chm
#
# Getting Started:
#
# To run this example, install "NI-Digital Driver" on the server machine.
# Link :
# https://www.ni.com/en-in/support/downloads/drivers/download.ni-digital-pattern-driver.html#367315
#
# For instructions on how to use protoc to generate gRPC client interfaces, see
# our "Creating a gRPC Client" wiki page.
# Link: https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client
#
# Refer to the NI Digital gRPC Wiki for the latest C Function Reference:
# Link: https://github.com/doshirohan/grpc-device/wiki/NI-DIGITAL-C-Function-Reference
#
# Running from command line:
#
# Server machine's IP address, port number, and resource name can be passed as
# separate command line arguments.
#   > python configure-voltage-levels-and-termination-voltage.py <server_address>
#   <port_number>
# If they are not passed in as command line arguments, then by default the
# server address will be "localhost:31763"
import grpc
import sys
import os
import time
import nidigital_pb2 as nidigital_types
import nidigital_pb2_grpc as grpc_nidigital
import session_pb2 as session_types
import session_pb2_grpc as grpc_session
import keyword

server_address = "localhost"
server_port = "31763"
session_name = "NI-Digital-Session"

# deviceID and options for a simulated 6570 client. Change them according
# to the NI-Digital model.
deviceID = "PXI1Slot2,PXI1Slot3"
options = "Simulate=1, DriverSetup=Model:6570"

# Fixed parameters
channelList = "PinGroup1"
idQuery = False
resetDevice = False

# Configurable parameters
vil = 0
vih = 5
vol = 3
voh = 2
vterm = 5
iol = 0.015
ioh = -0.024
vcom = 2
termSelect = 'h'

# Read in cmd args
if len(sys.argv) >= 2:
    server_address = sys.argv[1]
if len(sys.argv) >= 3:
    server_port = sys.argv[2]
if len(sys.argv) >= 4:
    resource = sys.argv[3]
    options = ""

# Create the communication channel for the remote host and create connections
# to the NI-DMM and session services.
channel = grpc.insecure_channel(f"{server_address}:{server_port}")
nidigital_client = grpc_nidigital.NiDigitalStub(channel)

any_error = False
# Checks for errors.  If any, throws an exception to stop the execution.
def CheckForError(vi, status) :
    global any_error
    if(status != 0 and not any_error):
        any_error = True
        ThrowOnError(vi, status)

# Converts an error code returned by NI-Digital into a user-readable string.
def ThrowOnError(vi, error_code):
    error_message_request = nidigital_types.GetErrorRequest(vi = vi
    )
    error_message_response = nidigital_client.GetError(error_message_request)
    raise Exception(error_message_response.error_description)

try:
    # Open session to NI-Digital with options
     init_with_options_response = nidigital_client.InitWithOptions(nidigital_types.InitWithOptionsRequest(session_name = session_name, 
         resource_name = deviceID, 
         id_query = True,
         reset_device = True,
         option_string = options))
     vi = init_with_options_response.vi
     CheckForError(vi, init_with_options_response.status)

     dir = os.path.dirname(__file__)

     load_pin_map_response = nidigital_client.LoadPinMap(nidigital_types.LoadPinMapRequest(vi = vi,
         file_path = os.path.join(dir, 'PinMap.pinmap')))
     CheckForError(vi, load_pin_map_response.status)

     load_specification_response = nidigital_client.LoadSpecifications(nidigital_types.LoadSpecificationsRequest(vi = vi,
         file_path = os.path.join(dir, "Specifications.specs")))
     CheckForError(vi, load_specification_response.status)

     load_timing_response = nidigital_client.LoadTiming(nidigital_types.LoadTimingRequest(vi = vi,
         file_path = os.path.join(dir, "Timing.digitiming")))
     CheckForError(vi, load_timing_response.status)

     load_apply_levels_and_timing_response = nidigital_client.ApplyLevelsAndTiming(nidigital_types.ApplyLevelsAndTimingRequest(vi = vi,
         site_list ="",
         levels_sheet ="",
         timing_sheet = os.path.join(dir, "Timing.digitiming"),
         initial_state_high_pins ="",
         initial_state_low_pins ="",
         initial_state_tristate_pins =""))
     CheckForError(vi, load_apply_levels_and_timing_response.status)

     load_pattern_response = nidigital_client.LoadPattern(nidigital_types.LoadPatternRequest(vi = vi,
         file_path = os.path.join(dir, "Pattern.digipat")))
     CheckForError(vi, load_pattern_response.status)

     configure_voltage_response = nidigital_client.ConfigureVoltageLevels(nidigital_types.ConfigureVoltageLevelsRequest(vi = vi,
         channel_list = channelList,
         vil = vil,
         vih = vih,
         vol = vol,
         voh = voh,
         vterm = vterm))
     CheckForError(vi, configure_voltage_response.status)
     
     while True:
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

        if(termSelect == 'h' or termSelect == 'a' or termSelect == 't'):
            break

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

     print('Done without error.\n')

# If NI-Digital API throws an exception, print the error message  
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE :
        error_message = f"Failed to connect to server on {server_address}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = "The operation is not implemented or is not supported/enabled in this service"
    print(f"{error_message}") 
finally:
    if('vi' in vars() and vi.id != 0):      
        # Close NI-Digital session
        close_session_response = nidigital_client.Close(nidigital_types.CloseRequest(
            vi = vi
        ))
        CheckForError(vi, close_session_response.status)