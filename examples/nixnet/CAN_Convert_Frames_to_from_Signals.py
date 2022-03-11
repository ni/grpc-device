# /*
# // This example converts frames to signals, and then converts the signal values
# // back to the frame value using a conversion session.
# // For more information about this type of session, please consult the NI-XNET
# // manual. This example uses hardcoded signals and frames that use the NIXNET_example
# // database. To use your own database, you need to add an alias to your
# // database file using the NI-XNET Database Editor and then modify the database
# // name and signals used here.
# */

# include "../../example_support.h" // Include file for Sleep, _getch
# include <nixnet.h>                // Include file for NI-XNET functions and constants
# include <stdlib.h>                // Include file for various functions
# include <stdio.h>                 // Include file for printf
# include <ctype.h>                 // Include file for tolower


from sqlite3 import Timestamp
from ssl import SSL_ERROR_SSL
from sys import flags
import sys
from urllib import response
from venv import create
import grpc
import nixnet_pb2 as nixnet_types
import nixnet_pb2_grpc as grpc_nixnet

# //=============================================================================
# // Static global variables
# //=============================================================================
# static nxSessionRef_t m_SessionRef = 0;

# //=============================================================================
# // Global functions declarations
# //=============================================================================
# void DisplayErrorAndExit(nxStatus_t Status, char *Source);

# //=============================================================================
# // Main function
# //=============================================================================
# int main(void)
# {
   # // Declare all variables for the function
   # unsigned int i = 0;
l_pSelectedDatabase = "NIXNET_example"
l_pSelectedCluster = "CAN_Cluster"
l_pSelectedSignalList = "CANEventSignal1,CANEventSignal3"
l_NumberOfBytesForFrames = 0
l_NumberOfBytesReturnedConv = 0

NUM_FRAMES = 2
NUM_SIGNALS = 2


   # u8 l_Buffer[NUM_FRAMES * sizeof(nxFrameCAN_t)];
   # u8 l_BufferConv[NUM_FRAMES * sizeof(nxFrameCAN_t)];
   # nxFrameVar_t *l_pFrame = NULL;
   # nxFrameVar_t *l_pFrameConv = NULL;
   # f64 l_ValueBuffer[NUM_SIGNALS];
   # nxTimestamp_t l_TimestampBuffer[NUM_SIGNALS];
   # nxStatus_t l_Status = 0;

   # // Display parameters that will be used for the example.
   # printf("Database: %s\nCluster: %s\nSignal List: %s\n",
   #    l_pSelectedDatabase, l_pSelectedCluster, l_pSelectedSignalList);

   # // Create an XNET session in SignalConversionSinglePoint mode
SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"

channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
client = grpc_nixnet.NiXnetStub(channel)

create_session_response = client.CreateSession(
   nixnet_types.CreateSessionRequest(
      database_name=l_pSelectedDatabase,
      cluster_name=l_pSelectedCluster,
      list=l_pSelectedSignalList,
      interface="",
      mode=nixnet_types.CreateSessionMode.CREATE_SESSION_MODE_MODE_SIGNAL_CONVERSION_SINGLE_POINT
   )
)

session_ref = create_session_response.session_ref

if 0 == create_session_response.status:
   print("Successfully created session.")
else:
   print("Failed to create session.")
   exit(1)

print("\nFrames to Convert\nID\tData\t\n");

   # // Here we set each of the frames parameters.
   # // There are ways to programmatically get these parameters using
   # // the objects properties. The frame IDs correspond to
   # // CANEventFrame1 and CANEventFrame2 from the database.

frame1 = nixnet_types.Frame(
   timestamp=0,
   flags=0,
   identifier=66,
   type=0x00, #nxFrameType_CAN_Data
   payload_length=8,
   payload=bytes([0,1,2,3,4,5,6,7])
)

frame2 = nixnet_types.Frame(
   timestamp=0,
   flags=0,
   identifier=66,
   type=0x00, #nxFrameType_CAN_Data
   payload_length=4,
   payload=bytes([8,9,10,11])
)


# l_pFrame = (nxFrameVar_t *)l_Buffer;
# l_pFrame->Timestamp = 0;
# l_pFrame->Flags = 0;
#    l_pFrame->Identifier = 66;
#    l_pFrame->Type = nxFrameType_CAN_Data;
#    l_pFrame->PayloadLength = 8;
#    for (i = 0; i < l_pFrame->PayloadLength; ++i)
#    {
#       l_pFrame->Payload[i] = (u8)i;
#    }
#    // Print the frame we just created
#    printf("%d\t", l_pFrame->Identifier);
#    for (i = 0; i < l_pFrame->PayloadLength; ++i)
#    {
#       printf("%02X ", l_pFrame->Payload[i]);
#    }
#    printf("\n");

#    // Iterate the pointer to the next frame
#    l_pFrame = nxFrameIterate(l_pFrame);
#    l_pFrame->Timestamp = 0;
#    l_pFrame->Flags = 0;
#    l_pFrame->Identifier = 67;
#    l_pFrame->Type = nxFrameType_CAN_Data;
#    l_pFrame->PayloadLength = 2;
#    for (i = 0; i < l_pFrame->PayloadLength; ++i)
#    {
#       l_pFrame->Payload[i] = (u8)(i + 8);
#    }
#    // Print the frame we just created
#    printf("%d\t", l_pFrame->Identifier);
#    for (i = 0; i < l_pFrame->PayloadLength; ++i)
#    {
#       printf("%02X ", l_pFrame->Payload[i]);
#    }
#    printf("\n");

#    // Get the actual size of the buffer used
#    l_pFrame = nxFrameIterate(l_pFrame);
#    l_NumberOfBytesForFrames = (u32)((u8 *)l_pFrame - (u8 *)l_Buffer);

#    // Convert the frames to signal values
convert_frame_response = client.ConvertFramesToSignalsSinglePoint(
   nixnet_types.ConvertFramesToSignalsSinglePointRequest(
      session_ref=session_ref,
      frame_buffer=[frame1, frame2],
      size_of_value_buffer=NUM_SIGNALS * 8,
      size_of_timestamp_buffer=NUM_SIGNALS * 8
   )
)

#       l_NumberOfBytesForFrames, l_ValueBuffer, sizeof(l_ValueBuffer),
#       l_TimestampBuffer, sizeof(l_TimestampBuffer));
if 0 == convert_frame_response.status:
   # // Print the values ignoring the timestamps
   print("\nConverted signal values\n");
   print(f"Signal 1: {convert_frame_response.value_buffer}\n");
   # print(f"Signal 2: {convert_frame_response.value_buffer[1]}\n");
   print(f"Signal 2: {convert_frame_response.timestamp_buffer}\n");
   # print(f"Signal 2: {convert_frame_response.timestamp_buffer[1]}\n");
   # print(f"Signal 2: {convert_frame_response.size_of_buffer}\n");

else:
   print(f"Failed to ConvertFramesToSignalsSinglePoint. Error {convert_frame_response.status}")
   exit(1)


convert_signal_response = client.ConvertSignalsToFramesSinglePoint(
   nixnet_types.ConvertSignalsToFramesSinglePointRequest(
      session_ref=session_ref,
      value_buffer=convert_frame_response.value_buffer,
      size_of_buffer=NUM_FRAMES * 24
   )
)


for f in convert_signal_response.buffer:
   print(f.identifier)
   print(f.payload_length)
   print(f.payload)
   print(len(f.payload))
   # DisplayErrorAndExit(l_Status, "nxConvertFramesToSignalsSinglePoint");

#    // Convert the signal values back to frames
#    l_Status = nxConvertSignalsToFramesSinglePoint(m_SessionRef, l_ValueBuffer,
#       sizeof(l_ValueBuffer), l_BufferConv, sizeof(l_BufferConv),
#       &l_NumberOfBytesReturnedConv);
#    if (nxSuccess == l_Status)
#    {
#       printf("\nFrames converted from signal values\n");
#       printf("ID\tData\n");

#       l_pFrameConv = (nxFrameVar_t *)l_BufferConv;

#       // l_pFrameConv iterates to each frame. When it increments
#       // past the number of bytes returned, we reached the end.
#       while ((u8 *)l_pFrameConv < (u8 *)l_BufferConv + l_NumberOfBytesReturnedConv)
#       {
#          // Print timestamp, ID and payload
#          printf("%d\t", l_pFrameConv->Identifier);

#          for (i = 0; i < l_pFrameConv->PayloadLength; ++i)
#          {
#             printf("%02X ", l_pFrameConv->Payload[i]);
#          }
#          printf("\n");

#          // Go to next variable-payload frame.
#          l_pFrameConv = nxFrameIterate(l_pFrameConv);
#       }
#    }
#    else
#    {
#       DisplayErrorAndExit(l_Status, "nxConvertSignalsToFramesSinglePoint");
#    }

#    // Clear the XNET session
#    l_Status = nxClear(m_SessionRef);
#    if (nxSuccess == l_Status)
#    {
#       printf("\nSession cleared successfully!\n");
#    }
#    else
#    {
#       DisplayErrorAndExit(l_Status, "nxClear");
#    }

#    printf("\nPress any key to quit\n");
#    _getch();

#    return 0;
# }

# //=============================================================================
# // Display Error Function
# //=============================================================================
# void DisplayErrorAndExit(nxStatus_t Status, char *Source)
# {
#    char l_StatusString[1024];
#    nxStatusToString(Status, sizeof(l_StatusString), l_StatusString);

#    printf("\n\nERROR at %s!\n%s\n", Source, l_StatusString);
#    printf("\nExecution stopped.\nPress any key to quit\n");

#    nxClear(m_SessionRef);

#    _getch();
#    exit(1);
# }
