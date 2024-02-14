#define NOMINMAX

#include <custom/nixnet_converters.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <nixnet/nixnet_mock_library.h>
#include <tests/system/nixnet_utilities.h>

#include <algorithm>
#include <numeric>
#include <string>

using namespace nixnet_grpc;
using namespace nixnet_grpc::converters;
using namespace nixnet_utilities;
using namespace ::testing;
namespace pb = ::google::protobuf;
using namespace std::string_literals;
using ni::tests::unit::NiXnetMockLibrary;

namespace ni {
namespace tests {
namespace unit {
namespace {

void assert_enet_frames_are_equal(nxFrameEnet_t* frame1, nixnet_grpc::EnetFrameResponse frame2)
{
  EXPECT_EQ(nixnet_grpc::EnetFrameType::ENET_FRAME_TYPE_DATA, frame2.type());
  EXPECT_EQ(frame1->Type, frame2.type_raw());
  EXPECT_EQ(frame1->DeviceTimestamp, frame2.device_timestamp());
  EXPECT_EQ(frame1->NetworkTimestamp, frame2.network_timestamp());
  EXPECT_EQ(nixnet_grpc::EnetFlags::ENET_FLAGS_TRANSMIT, frame2.flags_mapped()[0]);
  EXPECT_EQ(frame1->Flags, frame2.flags_raw());
  EXPECT_EQ(frame1->Length - nixnet_grpc::ENET_FRAME_HEADER_LENGTH - nixnet_grpc::ENET_FRAME_FCS_SIZE, frame2.frame_data().size());
  ASSERT_THAT(std::vector<u8>(frame1->FrameData, frame1->FrameData + frame1->Length - nixnet_grpc::ENET_FRAME_HEADER_LENGTH - nixnet_grpc::ENET_FRAME_FCS_SIZE), ::testing::ElementsAreArray(frame2.frame_data()));
}

void assert_frames_are_equal(nxFrameVar_t* frame1, nixnet_grpc::FrameResponse frame2)
{
  EXPECT_EQ(frame1->Timestamp, frame2.timestamp());
  EXPECT_EQ(frame1->Identifier, frame2.identifier());
  EXPECT_EQ(nixnet_grpc::FrameType::FRAME_TYPE_LIN_DATA, frame2.type());
  EXPECT_EQ(frame1->Type, frame2.type_raw());
  EXPECT_EQ(1, frame2.flags().size());
  EXPECT_EQ(nixnet_grpc::FrameFlags::FRAME_FLAGS_LIN_EVENT_SLOT, frame2.flags()[0]);
  EXPECT_EQ(frame1->Flags, frame2.flags_raw());
  EXPECT_EQ(frame1->Info, frame2.info());
  EXPECT_EQ(frame1->PayloadLength, frame2.payload().size());
  ASSERT_THAT(std::vector<u8>(frame1->Payload, frame1->Payload + frame1->PayloadLength), ::testing::ElementsAreArray(frame2.payload()));
}

TEST(XnetConvertersTests, CANCommStateValue_SetCANCommResponse_ExtractBitfields)
{
  u32 canCommunicationState = 0;
  u32 transcieverError = 0;
  u32 sleep = 0;
  u32 lastError = 3;
  u32 transmitErrorCounter = 3;
  u32 receiveErrorCounter = 3;
  // This value is obtained by combining above bit fields.
  u32 canCommStateValue = 0x03030300;

  nixnet_grpc::CanCommResponse output;
  SetCanCommResponse(canCommStateValue, &output);

  EXPECT_EQ(nixnet_grpc::CanCommState::CAN_COMM_STATE_ERROR_ACTIVE, output.comm_state());
  EXPECT_EQ(canCommunicationState, output.comm_state_raw());
  EXPECT_EQ(transcieverError, output.transceiver_error());
  EXPECT_EQ(sleep, output.sleep());
  EXPECT_EQ(nixnet_grpc::CanLastErr::CAN_LAST_ERR_ACK, output.last_error());
  EXPECT_EQ(lastError, output.last_error_raw());
  EXPECT_EQ(transmitErrorCounter, output.transmit_error_counter());
  EXPECT_EQ(receiveErrorCounter, output.receive_error_counter());
}

TEST(XnetConvertersTests, FlexRayCommStateValue_SetFlexRayCommResponse_ExtractBitFields)
{
  u32 pocState = 2;
  u32 clockCorrectionFailed = 5;
  u32 passiveToActiveCount = 15;
  u32 channelASleep = 0;
  u32 channelBSleep = 0;
  // This value is obtained by combining above bit fields.
  u32 flexRayCommStateValue = 0x00000F52;

  nixnet_grpc::FlexRayCommResponse output;
  SetFlexRayCommResponse(flexRayCommStateValue, &output);

  EXPECT_EQ(nixnet_grpc::FlexRayPocState::FLEX_RAY_POC_STATE_NORMAL_ACTIVE, output.poc_state());
  EXPECT_EQ(pocState, output.poc_state_raw());
  EXPECT_EQ(clockCorrectionFailed, output.clock_correction_failed());
  EXPECT_EQ(passiveToActiveCount, output.passive_to_active_count());
  EXPECT_EQ(channelASleep, output.channel_a_sleep());
  EXPECT_EQ(channelBSleep, output.channel_b_sleep());
}

TEST(XnetConvertersTests, LINCommStateValue_SetLINCommResponse_ExtractBitFields)
{
  u32 reserved = 0;
  u32 sleep = 1;
  u32 linCommunicationState = 1;
  u32 lastError = 3;
  u32 lastErrorReceived = 0;
  u32 lastErrorExpected = 3;
  u32 lastErrorID = 1;
  u32 transcieverReady = 1;
  // This value is obtained by combining above bit fields.
  u32 communicationState = 0x81030036;
  u32 scheduleIndex = 3;
  u32 linCommState[] = {communicationState, scheduleIndex};

  nixnet_grpc::LinCommResponse output;
  SetLinCommResponse(linCommState, &output);

  EXPECT_EQ(sleep, output.sleep());
  EXPECT_EQ(nixnet_grpc::LinCommState::LIN_COMM_STATE_ACTIVE, output.comm_state());
  EXPECT_EQ(linCommunicationState, output.comm_state_raw());
  EXPECT_EQ(lastError, output.last_error());
  EXPECT_EQ(lastErrorReceived, output.last_error_received());
  EXPECT_EQ(lastErrorExpected, output.last_error_expected());
  EXPECT_EQ(lastErrorID, output.last_error_id());
  EXPECT_EQ(transcieverReady, output.transceiver_ready());
  EXPECT_EQ(scheduleIndex, output.schedule_index());
}

TEST(XnetConvertersTests, SessionInfoStateValue_SetSessionInfoResponse_ExtractSessionInfoState)
{
  u32 sessionInfoState = 1;

  nixnet_grpc::SessionInfoResponse output;
  SetSessionInfoResponse(sessionInfoState, &output);

  EXPECT_EQ(nixnet_grpc::SessionInfoState::SESSION_INFO_STATE_STARTED, output.info());
  EXPECT_EQ(sessionInfoState, output.info_raw());
}

TEST(XnetConvertersTests, FrameBufferArray_ConvertToGrpc_FrameBufferResponse)
{
  std::vector<u8> buffer(48);
  nxFrameVar_t* pFrame = (nxFrameVar_t*)buffer.data();
  pFrame->Timestamp = 0;
  pFrame->Flags = nxFrameFlags_LIN_EventSlot;
  pFrame->Info = 0;
  pFrame->Identifier = 66;
  pFrame->Type = nxFrameType_LIN_Data;
  pFrame->PayloadLength = 8;
  for (u16 j = 0; j < pFrame->PayloadLength; ++j) {
    pFrame->Payload[j] = (u8)(j + 1);
  }

  pFrame = nxFrameIterate(pFrame);
  pFrame->Timestamp = 0;
  pFrame->Flags = nxFrameFlags_LIN_EventSlot;
  pFrame->Info = 0;
  pFrame->Identifier = 67;
  pFrame->Type = nxFrameType_LIN_Data;
  pFrame->PayloadLength = 2;
  for (u16 j = 0; j < pFrame->PayloadLength; ++j) {
    pFrame->Payload[j] = (u8)(j + 1);
  }

  pb::RepeatedPtrField<nixnet_grpc::FrameBufferResponse> output;
  nixnet_grpc::convert_to_grpc(buffer, &output, static_cast<u32>(buffer.size()), nixnet_grpc::Protocol::PROTOCOL_LIN, std::map<int32_t, int32_t>());

  pFrame = (nxFrameVar_t*)buffer.data();
  assert_frames_are_equal(pFrame, output[0].lin());
  pFrame = nxFrameIterate(pFrame);
  assert_frames_are_equal(pFrame, output[1].lin());
}

TEST(XnetConvertersTests, EnetFrameBuffer_ConvertToGrpc_EnetFrameResponse)
{
  std::vector<u8> buffer(3092);
  nxFrameEnet_t* pFrame = (nxFrameEnet_t*)buffer.data();
  EncodeEnetFrame(pFrame, 150, false, 0);
  u16 buffer_length = pFrame->Length;
  pFrame = nxFrameIterateEthernetRead(pFrame);
  EncodeEnetFrame(pFrame, 150, true, 2);
  buffer_length += pFrame->Length;
  std::map<int32_t, int32_t> enet_flags_map = {{nxEnetFlags_Transmit, nixnet_grpc::EnetFlags::ENET_FLAGS_TRANSMIT}};

  pb::RepeatedPtrField<nixnet_grpc::FrameBufferResponse> output;
  nixnet_grpc::convert_to_grpc(buffer, &output, buffer_length, nixnet_grpc::Protocol::PROTOCOL_ENET, enet_flags_map);

  pFrame = (nxFrameEnet_t*)buffer.data();
  assert_enet_frames_are_equal(pFrame, output[0].enet());
  pFrame = nxFrameIterateEthernetRead(pFrame);
  assert_enet_frames_are_equal(pFrame, output[1].enet());
}
}  // namespace
}  // namespace unit
}  // namespace tests
}  // namespace ni