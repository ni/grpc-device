import grpc
import nidcpower_pb2 as nidcpower_types
import nidcpower_pb2_grpc as grpc_nidcpower
# import session_pb2 as session_types
# import session_pb2_grpc as grpc_session

server_address = "localhost"
server_port = "31763"
session_name = "NI-DCPower-Session"

resource = "SimulatedDCPower"
options = "Simulate=1,DriverSetup=Model:4110;BoardType:PXI"

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
    raise Exception (error_message_response)

channel = grpc.insecure_channel(f"{server_address}:{server_port}")
client = grpc_nidcpower.NiDCPowerStub(channel)

try :

    # Initialise with channels API
    initialize_with_independent_channels_response = client.InitializeWithIndependentChannels(nidcpower_types.InitializeWithIndependentChannelsRequest(
        session_name = session_name,
        resource_name=resource,
        reset = False,
        option_string=options
    ))
    vi = initialize_with_independent_channels_response.vi
    CheckForError(vi, initialize_with_independent_channels_response.status)
    print("Initialize_with_indepenedent_Channels works fine")

    # close API
    CheckForError(vi, (client.Close(nidcpower_types.CloseRequest(
        vi = vi
        ))).status)
    print("Close API works fine")
    channel.close()

except grpc.RpcError as e:
    error_message = e.details()
    print(error_message)