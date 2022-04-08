#define NOMINMAX

#include <custom/nixnet_converters.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <nixnet/nixnet_mock_library.h>

#include <algorithm>
#include <numeric>
#include <string>

using namespace nixnet_grpc;
using namespace nixnet_grpc::converters;
using namespace ::testing;
namespace pb = ::google::protobuf;
using namespace std::string_literals;
using ni::tests::unit::NiXnetMockLibrary;

namespace ni {
namespace tests {
namespace unit {
namespace {
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
}  // namespace
}  // namespace unit
}  // namespace tests
}  // namespace ni