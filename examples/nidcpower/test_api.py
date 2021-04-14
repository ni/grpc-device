import grpc
import nidcpower_pb2 as nidcpower_types
import nidcpower_pb2_grpc as grpc_nidcpower
# import matplotlib.pyplot as plt
# import keyword
# import session_pb2 as session_types
# import session_pb2_grpc as grpc_session

server_address = "localhost"
server_port = "31763"
session_name = "NI-DCPower-Session"

resource = "SimulatedDCPower"
options = "Simulate=1,DriverSetup=Model:4147;BoardType:PXIe"
channels = "0"

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
        resource_name = resource,
        reset = False,
        option_string = options
    ))
    vi = initialize_with_independent_channels_response.vi
    CheckForError(vi, initialize_with_independent_channels_response.status)
    print("Initialize_with_independent_channels works fine")

    # configure measure_when
    configure_measure_when = client.SetAttributeViInt32(nidcpower_types.SetAttributeViInt32Request(
        vi = vi,
        channel_name = channels,
        attribute_id = nidcpower_types.NiDCPowerAttributes.NIDCPOWER_ATTRIBUTE_MEASURE_WHEN,
        attribute_value = nidcpower_types.MeasureWhen.MEASURE_WHEN_NIDCPOWER_VAL_AUTOMATICALLY_AFTER_SOURCE_COMPLETE
    ))
    CheckForError(vi, configure_measure_when.status)
    print("Configured measure_when attribute")

    # configure measure_record_length
    configure_measure_record_length = client.SetAttributeViInt32(nidcpower_types.SetAttributeViInt32Request(
        vi = vi,
        channel_name = channels,
        attribute_id = nidcpower_types.NiDCPowerAttributes.NIDCPOWER_ATTRIBUTE_MEASURE_RECORD_LENGTH,
        attribute_value = 20
    ))
    CheckForError(vi, configure_measure_record_length.status)
    print("configured measure_record_length attribute")

    # value of measure_record_length
    get_value_measure_record_length = client.GetAttributeViInt32(nidcpower_types.GetAttributeViInt32Request(
        vi = vi,
        channel_name = channels,
        attribute_id = nidcpower_types.NiDCPowerAttributes.NIDCPOWER_ATTRIBUTE_MEASURE_RECORD_LENGTH
    ))
    CheckForError(vi, get_value_measure_record_length.status)
    print(get_value_measure_record_length.attribute_value)

    # configure measure_record_length_is_finite
    configure_measure_record_length_is_finite = client.SetAttributeViBoolean(nidcpower_types.SetAttributeViBooleanRequest(
        vi = vi,
        channel_name = channels,
        attribute_id = nidcpower_types.NiDCPowerAttributes.NIDCPOWER_ATTRIBUTE_MEASURE_RECORD_LENGTH_IS_FINITE,
        attribute_value = True
    ))
    CheckForError(vi, configure_measure_record_length_is_finite.status)
    print("configured measure_record_length_is_finite attribute")

    # value of measure_record_length_is_finite
    get_value_measure_record_length_is_finite = client.GetAttributeViBoolean(nidcpower_types.GetAttributeViBooleanRequest(
        vi = vi,
        channel_name = channels,
        attribute_id = nidcpower_types.NiDCPowerAttributes.NIDCPOWER_ATTRIBUTE_MEASURE_RECORD_LENGTH_IS_FINITE
    ))
    CheckForError(vi, get_value_measure_record_length_is_finite.status)
    print(get_value_measure_record_length_is_finite.attribute_value)

    # configure voltage level
    configure_voltage_level = client.ConfigureVoltageLevel(nidcpower_types.ConfigureVoltageLevelRequest(
        vi = vi,
        channel_name = channels,
        level = 5.0
    ))
    CheckForError(vi, configure_voltage_level.status)
    print("Configured voltage level")

    # commit the session
    commit_with_channels = client.CommitWithChannels(nidcpower_types.CommitWithChannelsRequest(
        vi = vi,
        channel_name = channels
    ))
    CheckForError(vi, commit_with_channels.status)
    print("Commit_with_channels works fine!")

    # get measure_record_delta_time
    get_measure_record_delta_time = client.GetAttributeViReal64(nidcpower_types.GetAttributeViReal64Request(
       vi = vi,
       channel_name = channels,
       attribute_id =  nidcpower_types.NiDCPowerAttributes.NIDCPOWER_ATTRIBUTE_MEASURE_RECORD_DELTA_TIME
    ))
    CheckForError(vi, get_measure_record_delta_time.status)
    print(f"Effective measurement rate : {get_measure_record_delta_time.attribute_value}")

    # initiate the session
    initiate = client.Initiate(nidcpower_types.InitiateRequest(
        vi = vi
    ))
    CheckForError(vi, initiate.status)
    print("Session initiated")

    samples_aquired = 0
    while (samples_aquired < 20):

        fetch_multiple_response = client.FetchMultiple(nidcpower_types.FetchMultipleRequest(
            vi = vi,
            channel_name = channels,
            timeout = 5,
            count = 20
        ))
        CheckForError(vi, fetch_multiple_response.status)

        samples_aquired += fetch_multiple_response.actual_count
        


    # close API
    CheckForError(vi, (client.Close(nidcpower_types.CloseRequest(
        vi = vi
        ))).status)
    print("Close API works fine")
    # channel.close()

except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE :
        error_message = f"Failed to connect to server on {server_address}"
    print(f"{error_message}") 