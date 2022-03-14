
import grpc
import nixnet_pb2 as nixnet_types
import nixnet_pb2_grpc as grpc_nixnet
import msvcrt


# Parameters
INTERFACE = "CAN1"
DATABASE = "NIXNET_example"
CLUSTER = "CAN_Cluster"
SIGNAL_LIST = "CANEventSignal1,CANEventSignal2"
NUM_SIGNALS = 2
SUCCESS = 0

# Display Error Function
def displayerror_andexit(Status, Source):
    status_string = [None] * 1024
    # TO-DO Convert statustostring is pending
    #nixnet_types.StatustoString(Status,status_string.__sizeof__(),Source) 
    #print("\n\nERROR at {}!\n{}\n", Source, status_string)
    print(Status)
    print("\nExecution stopped.\nPress any key to quit\n")

    client.Clear(nixnet_types.ClearRequest(session_ref = m_SessionRef))
    msvcrt.getch()
    exit(1)

i = 0
m_SessionRef = 0
value_Buffer = [0] * NUM_SIGNALS
channel = grpc.insecure_channel('10.164.75.8:31764')
client = grpc_nixnet.NiXnetStub(channel)

# Display parameters that will be used for the example.
print("Interface: "+ INTERFACE, "Database: " + DATABASE, "Signal List: " + SIGNAL_LIST, sep="\n")

# Create an XNET session in SignalOutSinglePoint mode
CreateSession_Response = client.CreateSession(
    nixnet_types.CreateSessionRequest(
        database_name = DATABASE,
        cluster_name = CLUSTER,
        list = SIGNAL_LIST,
        interface = INTERFACE, 
        mode = nixnet_types.CREATE_SESSION_MODE_MODE_SIGNAL_OUT_SINGLE_POINT
    ))

m_SessionRef = CreateSession_Response.session_ref

if CreateSession_Response.status == SUCCESS:
    print("Session Created Successfully.\n")
else:
    displayerror_andexit(CreateSession_Response.status,"CreateSession")
    
print("\nPress any key to transmit new signal values or q to quit\n")

while msvcrt.getwch() != 'q':
    value_Buffer[0] = float(i)
    value_Buffer[1] = float(i*10)
    #value_Buffer = [1,2]

    # Update the signal data
    response = client.WriteSignalSinglePoint(
        nixnet_types.WriteSignalSinglePointRequest(
            session_ref = m_SessionRef,
            value_buffer = value_Buffer
        ))
    
    if response.status == SUCCESS: 
        print("Signals sent:")
        print("Signal 1: ", value_Buffer[0])
        print("Signal 2: ", value_Buffer[1],end="\n\n")
        i += 1
        if i > 10 :
            i = 0
    else:
        displayerror_andexit(response.status,"WriteSignalSinglePoint")
            
response = client.Clear(nixnet_types.ClearRequest(session_ref = m_SessionRef))
if response.status == SUCCESS:
    print("Session cleared successfully!\n")
else:
    displayerror_andexit(response.status,"Clear")

