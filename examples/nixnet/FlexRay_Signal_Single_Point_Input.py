
import grpc
import nixnet_pb2 as nixnet_types
import nixnet_pb2_grpc as grpc_nixnet
import getch

# Parameters
INTERFACE = "FlexRay2"
DATABASE = "NIXNET_example"
CLUSTER = "FlexRay_Cluster"
SIGNAL_LIST = "FlexRayEventSignal1,FlexRayEventSignal2"
NUM_SIGNALS = 2
SUCCESS = 0

# Display Error Function
def displayerror_andexit(Status, Source):
    status_string = [None] * 1024
    # TODO Convert statustostring is pending
    #nixnet_types.StatustoString(Status,status_string.__sizeof__(),status_string) 
    #print("\n\nERROR at {}!\n{}\n", Source, status_string)
    print("\nExecution stopped.\nPress any key to quit\n")

    client.Clear(nixnet_types.ClearRequest(session_ref = m_SessionRef))
    msvcrt.getwch()
    exit(1)

m_SessionRef = 0
key_SlotId = 1
status_t = 0
value_Buffer = [0] * NUM_SIGNALS
timeStamp_Buffer = [None] * NUM_SIGNALS
channel = grpc.insecure_channel(f"10.164.75.8:31763")
client = grpc_nixnet.NiXnetStub(channel)

# Display parameters that will be used for the example.
print("Interface: "+ INTERFACE, "Database: " + DATABASE, "Signal List: " + SIGNAL_LIST, sep="\n")
print("KeySlotId:",key_SlotId)

# Create an XNET session in SignalOutSinglePoint mode
response = client.CreateSession(
    nixnet_types.CreateSessionRequest(
        database_name = DATABASE,
        cluster_name = CLUSTER,
        list = SIGNAL_LIST,
        interface = INTERFACE, 
        mode = nixnet_types.CREATE_SESSION_MODE_MODE_SIGNAL_IN_SINGLE_POINT
    ))

m_SessionRef = response.session_ref

if response.status == SUCCESS:
    print("Session Created Successfully.\n")
else:
    displayerror_andexit(response.status,"CreateSession")

#Set the Key Slot
response = client.SetProperty(
    nixnet_types.SetPropertyRequest(
        session_ref = m_SessionRef,
        property_id = nixnet_types.PROPERTY_SESSION_INTF_FLEX_RAY_KEY_SLOT_ID,
        u32_scalar = key_SlotId
    ))

if response.status != SUCCESS:
    displayerror_andexit(response.status, "SetProperty")

print("\nPress any key to transmit new signal values or q to quit\n")
  
while not (getch.getch()).decode('UTF-8') == 'q':
    # Update the signal data
    response = client.ReadSignalSinglePoint(
        nixnet_types.ReadSignalSinglePointRequest(
            session_ref = m_SessionRef,
            size_of_value_buffer = value_Buffer.__sizeof__(),
            size_of_timestamp_buffer = timeStamp_Buffer.__sizeof__()
        ))
    
    value_Buffer = response.value_buffer
    timeStamp_Buffer = response.timestamp_buffer
    
    if response.status == SUCCESS: 
        print("Signals received:")
        print("Signal 1: ", value_Buffer[0])
        print("Signal 2: ", value_Buffer[1],end="\n\n")
    else:
        displayerror_andexit(response.status,"ReadSignalSinglePoint")
            
# Clear X-NET Session
response = client.Clear(nixnet_types.ClearRequest(session_ref = m_SessionRef))
if response.status == SUCCESS:
    print("Session cleared successfully!\n")
else:
    displayerror_andexit(response.status,"Clear")

