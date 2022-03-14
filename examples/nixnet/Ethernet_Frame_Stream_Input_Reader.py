from asyncio.windows_events import NULL
from pickle import NONE
from selectors import SelectSelector
from sre_constants import SUCCESS
import grpc
import nixnet_pb2 as nixnet_types
import nixnet_pb2_grpc as grpc_nixnet
import msvcrt

CHOOSE_MONITOR_OR_ENDPOINT_TEXT = "\nPress \'m\' followed by enter to configure the input stream session to use the monitor path"\
                                        " to monitor all network traffic else just the enter key to use the endpoint path which filters"\
                                        " traffic based on VLAN ID and priority.\n"
FCS_SIZE = 4
MAX_ENET_FRAME_SIZE = 1518

# Display Error Function
def displayerror_andexit(Status, Source):
    status_string = [None] * 1024
    # TODO Convert statustostring is pending
    nixnet_types.StatustoString(Status,status_string.__sizeof__(),Source) 
    print("\n\nERROR at {}!\n{}\n", Source, status_string)
    print("\nExecution stopped.\nPress any key to quit\n")

    client.Clear(nixnet_types.ClearRequest(session_ref = m_SessionRef))
    msvcrt.getch()
    exit(1)

# Prints a timestamp to stdout
def printTimeStamp1(Time):
    # Converts nxTimestamp1ns_t (elapsed since 1 January 1970 00:00:00
    # International Atomic Time (TAI)) to nxTimestamp100ns_t (elapsed since 1
    # January 1601 00:00:00 Coordinated Universal Time (UTC)).
    response = client.ConvertTimestamp1nsTo100ns(
        nixnet_types.ConvertTimestamp1nsTo100nsRequest(
            Time
        ))
    if response.status != SUCCESS:
        displayerror_andexit(response.status,"ConvertTimeStamp1nsTo100ns")
    
    return printTimeStamp1(response.to) + print(" ")


# Declare all variables for the function
i = 0
typedChar = 0
channel = grpc.insecure_channel(f"localhost:31763")
client = grpc_nixnet.NiXnetStub(channel)

# An interface with the "/monitor" suffix would configure the input stream session to passively monitor all network traffic.
# An interface without this suffix would configure the session as an endpoint.
SelectedInterface = "ENET4"
# Allocate buffer to accommodate 250 frames of maximum size
buffer = [None] * (250 * nixnet_types.FRAME + MAX_ENET_FRAME_SIZE + FCS_SIZE)
pFrame = NULL
numBytes = 0
status = 0

# Receive filter only applies for endpoint mode.
rxFilter = None
flag = 3
vid = 2
priority = 3
mac = "AA:BB:CC:DD:EE:FF"; # MAC Address filter is not enabled. Use random string.

print(CHOOSE_MONITOR_OR_ENDPOINT_TEXT)
if 'm' == msvcrt.getch().lower():
    SelectedInterface = "ENET4/monitor"

# Display parameters that will be used for the example.
print("Interface: %s\n", SelectedInterface)

#Create an XNET session in FrameInStream mode
CreateSession_Response = client.CreateSession(
    nixnet_types.CreateSessionRequest(
        database_name = None,
        cluster_name = None,
        list = None,
        interface = SelectedInterface, 
        mode_enum = nixnet_types.CREATE_SESSION_MODE_MODE_FRAME_IN_STREAM
    ))

m_SessionRef = CreateSession_Response.session_ref

if CreateSession_Response.status == SUCCESS:
    print("Session Created Successfully.\n")
else:
    displayerror_andexit(CreateSession_Response.status,"CreateSession")


response = client.SetProperty(
    nixnet_types.SetPropertyRequest(
        m_SessionRef,
        nixnet_types.PROPERTIES_SESSION_INTF_ENET_EPT_RECEIVE_FILTER
    ))
# Set Receive Filter (Only applies for endpoint mode)
rxFilter = flag
rxFilter.VID = vid
rxFilter.Priority = priority
memcpy(rxFilter.DestinationMAC, mac, sizeof(nxMACAddress_t))


 status = nxSetProperty(m_SessionRef, nxPropSession_IntfEnetEptReceiveFilter,
      sizeof(nxEptRxFilter_Element_t), &rxFilter);
   if (nxSuccess != status)
   {
      DisplayErrorAndExit(status, "nxSetProperty");
   }

print("\nFrame capture stopped.\n")

response = client.Clear(nixnet_types.ClearRequest(session_ref = m_SessionRef))
if response.status == SUCCESS:
    print("Session cleared successfully!\n")
else:
    displayerror_andexit(response.status,"Clear")