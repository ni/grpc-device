#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <nixnet/nixnet_client.h>

#include <iostream>
#include <string>
#include <vector>

#include "device_server.h"
#include "nixnet_utilities.h"

using namespace nixnet_grpc;
namespace client = nixnet_grpc::experimental::client;
using namespace ::testing;
using namespace ::nixnet_utilities;

namespace ni {
namespace tests {
namespace system {
namespace {

using u8 = ::google::protobuf::uint8;
using u32 = ::google::protobuf::uint32;
using u64 = ::google::protobuf::uint64;
using f64 = double;

class NiXnetCANDriverApiTests : public ::testing::Test {
 protected:
  NiXnetCANDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiXnet::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }
  virtual ~NiXnetCANDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  template <typename TService>
  std::unique_ptr<typename TService::Stub> create_stub()
  {
    return TService::NewStub(device_server_->InProcessChannel());
  }

  std::unique_ptr<NiXnet::Stub>& stub()
  {
    return stub_;
  }

  void assert_can_frames_are_equal(nixnet_grpc::FrameRequest* frame1, nixnet_grpc::FrameResponse* frame2)
  {
    int frame1_flags = calculate_bitwise_or_of_flags(frame1->flags());
    int frame2_flags = calculate_bitwise_or_of_flags(frame2->flags());
    EXPECT_EQ(frame1_flags, frame2_flags);

    EXPECT_EQ(frame1->type(), frame2->type());
    EXPECT_EQ(frame1->identifier(), frame2->identifier());
    EXPECT_EQ(frame1->payload(), frame2->payload());
  }

  void set_frame_data(nixnet_grpc::FrameRequest* frame, u64 timestamp, nixnet_grpc::FrameFlags frame_flag, u32 identifier, nixnet_grpc::FrameType frame_type, const char* payload)
  {
    frame->set_timestamp(timestamp);
    frame->add_flags(frame_flag);
    frame->set_identifier(identifier);
    frame->set_type(frame_type);
    frame->set_payload(payload);
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiXnet::Stub> stub_;
};

TEST_F(NiXnetCANDriverApiTests, TwoFrameExample_ConvertFramesToSignalAndBackToFramesSinglePoint_InputAndOutputFramesAreEquivalent)
{
  constexpr auto NUM_FRAMES = 2;
  constexpr auto NUM_SIGNALS = 2;
  std::vector<nixnet_grpc::FrameBufferRequest> frames;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "CAN_Cluster", "CANEventSignal1,CANEventSignal3", "", CREATE_SESSION_MODE_SIGNAL_CONVERSION_SINGLE_POINT)).session();
  nixnet_grpc::FrameRequest* frame_in_1 = new nixnet_grpc::FrameRequest();
  nixnet_grpc::FrameRequest* frame_in_2 = new nixnet_grpc::FrameRequest();
  set_frame_data(frame_in_1, 0, FrameFlags::FRAME_FLAGS_UNSPECIFIED, 66, FrameType::FRAME_TYPE_CAN_DATA, "\2\1\2\3\4\5\6\7");
  set_frame_data(frame_in_2, 0, FrameFlags::FRAME_FLAGS_UNSPECIFIED, 67, FrameType::FRAME_TYPE_CAN_DATA, "\4\1");
  frames.push_back(nixnet_grpc::FrameBufferRequest());
  frames.back().set_allocated_can(frame_in_1);
  frames.push_back(nixnet_grpc::FrameBufferRequest());
  frames.back().set_allocated_can(frame_in_2);

  auto convert_frames_to_signals_single_point_response = EXPECT_SUCCESS(client::convert_frames_to_signals_single_point(stub(), session, NUM_SIGNALS, frames));
  std::vector<f64> value_buffer_copy(convert_frames_to_signals_single_point_response.value_buffer().begin(), convert_frames_to_signals_single_point_response.value_buffer().end());
  auto convert_signals_to_frames_single_point_response = EXPECT_SUCCESS(client::convert_signals_to_frames_single_point(stub(), session, value_buffer_copy, NUM_FRAMES, 8, Protocol::PROTOCOL_CAN));

  EXPECT_EQ(2, convert_frames_to_signals_single_point_response.value_buffer_size());
  EXPECT_EQ(2, convert_frames_to_signals_single_point_response.value_buffer().size());
  EXPECT_EQ(2, convert_signals_to_frames_single_point_response.buffer_size());
  EXPECT_EQ(2, convert_signals_to_frames_single_point_response.buffer().size());
  auto frame_out_1 = convert_signals_to_frames_single_point_response.buffer()[0];
  auto frame_out_2 = convert_signals_to_frames_single_point_response.buffer()[1];
  auto can_1 = frame_out_1.can();
  auto can_2 = frame_out_2.can();
  assert_can_frames_are_equal(frame_in_1, &can_1);
  assert_can_frames_are_equal(frame_in_2, &can_2);
  EXPECT_SUCCESS(client::clear(stub(), session));
}

TEST_F(NiXnetCANDriverApiTests, TwoFrameExample_ConvertFramesToSignalAndBackToFramesSinglePoint_SecondFramePayloadDoesNotContainDataFromFirstFramePayload)
{
  constexpr auto NUM_FRAMES = 2;
  constexpr auto NUM_SIGNALS = 2;
  std::vector<nixnet_grpc::FrameBufferRequest> frames;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "CAN_Cluster", "CANEventSignal1,CANEventSignal3", "", CREATE_SESSION_MODE_SIGNAL_CONVERSION_SINGLE_POINT)).session();
  nixnet_grpc::FrameRequest* frame_in_1 = new nixnet_grpc::FrameRequest();
  nixnet_grpc::FrameRequest* frame_in_2 = new nixnet_grpc::FrameRequest();
  set_frame_data(frame_in_1, 0, FrameFlags::FRAME_FLAGS_UNSPECIFIED, 66, FrameType::FRAME_TYPE_CAN_DATA, "\2\1\2\3\4\5\6\7");
  set_frame_data(frame_in_2, 0, FrameFlags::FRAME_FLAGS_UNSPECIFIED, 67, FrameType::FRAME_TYPE_CAN_DATA, "\4");
  frames.push_back(nixnet_grpc::FrameBufferRequest());
  frames.back().set_allocated_can(frame_in_1);
  frames.push_back(nixnet_grpc::FrameBufferRequest());
  frames.back().set_allocated_can(frame_in_2);

  auto convert_frames_to_signals_single_point_response = EXPECT_SUCCESS(client::convert_frames_to_signals_single_point(stub(), session, NUM_SIGNALS, frames));
  std::vector<f64> value_buffer_copy(convert_frames_to_signals_single_point_response.value_buffer().begin(), convert_frames_to_signals_single_point_response.value_buffer().end());
  auto convert_signals_to_frames_single_point_response = EXPECT_SUCCESS(client::convert_signals_to_frames_single_point(stub(), session, value_buffer_copy, NUM_FRAMES, 8, Protocol::PROTOCOL_CAN));

  // This assertion is specifically for a bug where payload data from previous frame was being copied over to the next frame.
  auto frame_out_2 = convert_signals_to_frames_single_point_response.buffer()[1];
  auto payload_2 = frame_out_2.can().payload();
  EXPECT_EQ(2, payload_2.length());
  EXPECT_EQ('\4', payload_2[0]);
  EXPECT_NE('\1', payload_2[1]);
  EXPECT_SUCCESS(client::clear(stub(), session));
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni