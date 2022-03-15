
import grpc
import nixnet_pb2 as nixnet_types
import nixnet_pb2_grpc as grpc_nixnet
import getch

# Parameters
INTERFACE = "LIN1"
DATABASE = "NIXNET_exampleLDF"
CLUSTER = "Cluster"
SIGNAL_LIST = "MasterSignal1_U16,MasterSignal2_U16"
NUM_SIGNALS = 2
SUCCESS = 0
m_SessionRef = 0
value_Buffer = [0] * NUM_SIGNALS
status_t = 0

# Display Error Function
def displayerror_andexit(Status, Source):
    status_string = [None] * 1024
    # TODO Convert statustostring is pending
    # nixnet_types.StatustoString(Status,status_string.__sizeof__(),Source) 
    print("\n\nERROR at {}!\n{}\n", Source, status_string)
    print("\nExecution stopped.\nPress any key to quit\n")

    client.Clear(nixnet_types.ClearRequest(session_ref = m_SessionRef))
    exit(1)

i = 0
channel = grpc.insecure_channel(f"10.164.75.8:31763")
client = grpc_nixnet.NiXnetStub(channel)

# Change this to set the interface to slave mode
IsMaster = 1

# The schedule is identified by its index. The index is mapped to
# the schedules in the database. Index 0 is the first schedule
# displayed in the Database Editor.
ScheduleIndex = 0

# Display parameters that will be used for the example.
print("Interface: "+ INTERFACE, "Database: " + DATABASE, "Signal List: " + SIGNAL_LIST, sep="\n")

if IsMaster != 0:
    print("Master?: Yes\n")
else:
    print("Master?: No\n")

# Create an XNET session in SignalOutSinglePoint mode
response = client.CreateSession(
    nixnet_types.CreateSessionRequest(
        database_name = DATABASE,
        cluster_name = CLUSTER,
        list = SIGNAL_LIST,
        interface = INTERFACE, 
        mode = nixnet_types.CREATE_SESSION_MODE_MODE_SIGNAL_OUT_SINGLE_POINT
    ))

m_SessionRef = response.session_ref

if response.status != SUCCESS:
    displayerror_andexit(response.status,"CreateSession")
else:
    if IsMaster != 0:
        # Set the schedule - this will also automatically enable master mode
        WriteStateValueObject =  nixnet_types.WriteStateValue(lin_schedule_change = ScheduleIndex)
        response = client.WriteState(
            nixnet_types.WriteStateRequest(
                session_ref = m_SessionRef,
                state_id = nixnet_types.WRITE_STATE_STATE_LIN_SCHEDULE_CHANGE,
                state_value = WriteStateValueObject
            ))

        if response.status != SUCCESS:
            displayerror_andexit(response.status,"WriteState")
    print("Session Created Successfully. \n")

print("\nPress any key to transmit new signal values or q to quit\n")
print("Values are incremented from 0 to 10 in this example.\n")
  
while not (getch.getch()).decode('UTF-8') == 'q':
    value_Buffer[0] = float(i)
    value_Buffer[1] = float(i*10)

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

