#include <gmock/gmock.h>
#include <google/protobuf/util/time_util.h>
#include <gtest/gtest.h>
#undef interface
#include <nixnet/nixnet_client.h>

#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "device_server.h"
#include "enumerate_devices.h"
#include "nixnet_utilities.h"

using namespace nixnet_grpc;
namespace client = nixnet_grpc::experimental::client;
namespace pb = google::protobuf;
using namespace ::testing;
using namespace ::nixnet_utilities;
using nlohmann::json;

namespace ni {
namespace tests {
namespace system {
namespace {

using u8 = pb::uint8;
using u32 = pb::uint32;
using u64 = pb::uint64;
using f64 = double;

class NiXnetLINDriverApiTests : public ::testing::Test {
 protected:
  NiXnetLINDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiXnet::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }
  virtual ~NiXnetLINDriverApiTests() {}

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

  void assert_lin_frames_are_equal(nixnet_grpc::FrameRequest* frame1, nixnet_grpc::FrameResponse* frame2)
  {
    int frame1_flags = calculate_bitwise_or_of_flags(frame1->flags());
    int frame2_flags = calculate_bitwise_or_of_flags(frame2->flags());
    EXPECT_EQ(frame1_flags, frame2_flags);

    EXPECT_EQ(frame1->type(), frame2->type());
    EXPECT_EQ(frame1->identifier(), frame2->identifier());
    EXPECT_EQ(frame1->payload(), frame2->payload());
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiXnet::Stub> stub_;
};

TEST_F(NiXnetLINDriverApiTests, ConvertFramesToFromSignalsFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_FRAMES = 2;
  constexpr auto NUM_SIGNALS = 2;
  std::vector<nixnet_grpc::FrameBufferRequest> frames;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_exampleLDF", "Cluster", "SlaveSignal1_U16,MasterSignal1_U16", "", CREATE_SESSION_MODE_SIGNAL_CONVERSION_SINGLE_POINT)).session();
  nixnet_grpc::FrameRequest* frame1 = new nixnet_grpc::FrameRequest();
  frame1->set_timestamp(0);
  frame1->add_flags(FrameFlags::FRAME_FLAGS_UNSPECIFIED);
  frame1->set_identifier(4);
  frame1->set_type(FrameType::FRAME_TYPE_LIN_DATA);
  frame1->set_payload("\2\1\2\3\4\5\6\7");
  frames.push_back(nixnet_grpc::FrameBufferRequest());
  frames.back().set_allocated_lin(frame1);
  nixnet_grpc::FrameRequest* frame2 = new nixnet_grpc::FrameRequest();
  frame2->set_timestamp(0);
  frame2->add_flags(FrameFlags::FRAME_FLAGS_UNSPECIFIED);
  frame2->set_identifier(2);
  frame2->set_type(FrameType::FRAME_TYPE_LIN_DATA);
  frame2->set_payload("\4\1");
  frames.push_back(nixnet_grpc::FrameBufferRequest());
  frames.back().set_allocated_lin(frame2);

  auto convert_frames_to_signals_single_point_response = EXPECT_SUCCESS(client::convert_frames_to_signals_single_point(stub(), session, NUM_SIGNALS, frames));
  std::vector<f64> value_buffer_copy(convert_frames_to_signals_single_point_response.value_buffer().begin(), convert_frames_to_signals_single_point_response.value_buffer().end());
  auto convert_signals_to_frames_single_point_response = EXPECT_SUCCESS(client::convert_signals_to_frames_single_point(stub(), session, value_buffer_copy, NUM_FRAMES, 8, Protocol::PROTOCOL_LIN));
  auto frame_out_1 = convert_signals_to_frames_single_point_response.buffer()[0];
  auto frame_out_2 = convert_signals_to_frames_single_point_response.buffer()[1];
  auto lin_1 = frame_out_1.lin();
  auto lin_2 = frame_out_2.lin();

  EXPECT_EQ(2, convert_frames_to_signals_single_point_response.timestamp_buffer().size());
  EXPECT_EQ(2, convert_frames_to_signals_single_point_response.value_buffer().size());
  EXPECT_EQ(2, convert_signals_to_frames_single_point_response.buffer().size());
  assert_lin_frames_are_equal(frame1, &lin_1);
  assert_lin_frames_are_equal(frame2, &lin_2);
  EXPECT_SUCCESS(client::clear(stub(), session));
  frames.clear();
}

TEST_F(NiXnetLINDriverApiTests, FrameStreamInputFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_FRAMES = 2;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_exampleLDF", "Cluster", "", "LIN2", CREATE_SESSION_MODE_FRAME_IN_STREAM)).session();
  EXPECT_SUCCESS(set_property(stub(), session, PROPERTY_SESSION_INTF_LIN_NO_RESPONSE_TO_IN_STRM, true));

  auto read_frame_response = EXPECT_SUCCESS(client::read_frame(stub(), session, NUM_FRAMES, 8, Protocol::PROTOCOL_LIN, TimeOut::TIME_OUT_NONE));
  EXPECT_SUCCESS(client::clear(stub(), session));
}

TEST_F(NiXnetLINDriverApiTests, LoopbackTestFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_SIGNALS_OUT = 2;
  constexpr auto NUM_SIGNALS_IN = 2;
  std::vector<f64> output_value_vtr(NUM_SIGNALS_OUT);
  auto input_session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_exampleLDF", "Cluster", "MasterSignal1_U16,MasterSignal2_U16", "LIN1", CREATE_SESSION_MODE_SIGNAL_IN_SINGLE_POINT)).session();
  auto output_session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_exampleLDF", "Cluster", "MasterSignal1_U16,MasterSignal2_U16", "LIN2", CREATE_SESSION_MODE_SIGNAL_OUT_SINGLE_POINT)).session();
  WriteStateValue state_value;
  state_value.set_lin_schedule_change(0);
  EXPECT_SUCCESS(client::write_state(stub(), output_session, WRITE_STATE_LIN_SCHEDULE_CHANGE, state_value));
  EXPECT_SUCCESS(client::start(stub(), input_session, START_STOP_SCOPE_NORMAL));
  output_value_vtr[0] = (f64)(5 % 10);
  output_value_vtr[1] = (f64)((5 % 10) * 10);
  auto write_signal_single_point_response = EXPECT_SUCCESS(client::write_signal_single_point(stub(), output_session, output_value_vtr));

  auto read_signal_single_point_response = EXPECT_SUCCESS(client::read_signal_single_point(stub(), input_session, NUM_SIGNALS_IN));
  EXPECT_SUCCESS(client::clear(stub(), output_session));
  EXPECT_SUCCESS(client::clear(stub(), input_session));

  EXPECT_EQ(output_value_vtr[0], read_signal_single_point_response.value_buffer()[0]) << "LIN1 and LIN2 must be connected together.";
  EXPECT_EQ(output_value_vtr[1], read_signal_single_point_response.value_buffer()[1]) << "LIN1 and LIN2 must be connected together.";
}

TEST_F(NiXnetLINDriverApiTests, WriteSignalXYFromExample_ReadSignalXYFromExample_SignalMatches)
{
  constexpr auto NUM_SAMP = 3;
  constexpr auto NUM_SIGNALS = 2;
  f64 increment_out = 0.0;
  f64 min_out = 0.0;
  f64 max_out = 40.0;
  std::vector<u32> num_pairs_buffer(NUM_SIGNALS);
  std::vector<f64> value_buffer(NUM_SAMP * NUM_SIGNALS);
  auto session_for_writing = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_exampleLDF", "Cluster", "MasterSignal1_U16", "LIN1", CREATE_SESSION_MODE_SIGNAL_OUT_XY)).session();
  WriteStateValue state_value;
  state_value.set_lin_schedule_change(0);
  EXPECT_SUCCESS(client::write_state(stub(), session_for_writing, WRITE_STATE_LIN_SCHEDULE_CHANGE, state_value));
  EXPECT_SUCCESS(client::start(stub(), session_for_writing, START_STOP_SCOPE_NORMAL));
  increment_out = (max_out - min_out) / NUM_SAMP;
  for (int i = 0; i < NUM_SAMP; ++i) {
    value_buffer[i] = min_out + (increment_out * i);
    value_buffer[i + NUM_SAMP] = min_out + (increment_out * ((i + (NUM_SAMP / 2)) % NUM_SAMP));
  }
  auto write_signal_xy_response = EXPECT_SUCCESS(client::write_signal_xy(stub(), session_for_writing, 1.0, value_buffer, std::vector<u64>(), num_pairs_buffer));

  auto session_for_reading = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_exampleLDF", "Cluster", "MasterSignal1_U16", "LIN2", CREATE_SESSION_MODE_SIGNAL_IN_XY)).session();
  auto read_signal_xy_response = EXPECT_SUCCESS(client::read_signal_xy(stub(), session_for_reading, 1.0, NUM_SAMP, NUM_SIGNALS));
  EXPECT_SUCCESS(client::clear(stub(), session_for_reading));
  EXPECT_SUCCESS(client::clear(stub(), session_for_writing));

  for (int i = 0; i < NUM_SAMP; ++i) {
    EXPECT_EQ(value_buffer[i], read_signal_xy_response.value_buffer()[i]) << "LIN1 and LIN2 must be connected together.";
    EXPECT_EQ(value_buffer[i + NUM_SAMP], read_signal_xy_response.value_buffer()[i + NUM_SAMP]) << "LIN1 and LIN2 must be connected together.";
  }
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni