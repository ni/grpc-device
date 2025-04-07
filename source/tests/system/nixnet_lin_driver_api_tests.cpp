#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <nixnet/nixnet_client.h>

#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

#include "device_server.h"
#include "enumerate_devices.h"
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

class NiXnetLINDriverApiTestsWithHardware : public NiXnetLINDriverApiTests {
 protected:
  void SetUp() override
  {
    const auto discovered_devices = EnumerateDevices();
    const auto required_interfaces = {"LIN1,LIN2"};

    for (const auto& required_name : required_interfaces) {
      auto found = std::find_if(
          discovered_devices.cbegin(),
          discovered_devices.cend(),
          [&required_name](const nidevice_grpc::DeviceProperties& properties) {
            return properties.name() == required_name;
          });

      if (found == discovered_devices.cend()) {
        GTEST_SKIP() << "Interface not found: " << required_name;
      }
    }
  }
};

TEST_F(NiXnetLINDriverApiTests, ConvertFramesToFromSignalsFromExample_CompareFrames_ValuesMatch)
{
  constexpr auto NUM_FRAMES = 2;
  constexpr auto NUM_SIGNALS = 2;
  std::vector<nixnet_grpc::FrameBufferRequest> frames;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_exampleLDF", "Cluster", "SlaveSignal1_U16,MasterSignal3_U8", "", CREATE_SESSION_MODE_SIGNAL_CONVERSION_SINGLE_POINT)).session();
  nixnet_grpc::FrameRequest* frame1 = new nixnet_grpc::FrameRequest();
  nixnet_grpc::FrameRequest* frame2 = new nixnet_grpc::FrameRequest();
  set_frame_data(frame1, 0, FrameFlags::FRAME_FLAGS_UNSPECIFIED, 4, FrameType::FRAME_TYPE_LIN_DATA, "\2\1\2\3\4\5\6\7");
  set_frame_data(frame2, 0, FrameFlags::FRAME_FLAGS_UNSPECIFIED, 3, FrameType::FRAME_TYPE_LIN_DATA, "\4\1");
  frames.push_back(nixnet_grpc::FrameBufferRequest());
  frames.back().set_allocated_lin(frame1);
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

TEST_F(NiXnetLINDriverApiTestsWithHardware, FrameStreamInputFromExample_ReadFrame_Succeeds)
{
  constexpr auto NUM_FRAMES = 2;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_exampleLDF", "Cluster", "", "LIN2", CREATE_SESSION_MODE_FRAME_IN_STREAM)).session();
  EXPECT_SUCCESS(set_property(stub(), session, PROPERTY_SESSION_INTF_LIN_NO_RESPONSE_TO_IN_STRM, true));

  auto read_frame_response = EXPECT_SUCCESS(client::read_frame(stub(), session, NUM_FRAMES, 8, Protocol::PROTOCOL_LIN, TimeOut::TIME_OUT_NONE));
  EXPECT_SUCCESS(client::clear(stub(), session));
}

TEST_F(NiXnetLINDriverApiTestsWithHardware, LoopbackSignalSinglePointTestFromExample_WriteAndReadSignal_SignalMatches)
{
  constexpr auto NUM_SIGNALS_OUT = 2;
  constexpr auto NUM_SIGNALS_IN = 2;
  constexpr auto MAX_READ_ATTEMPTS = 100;
  std::vector<f64> output_value_vtr(NUM_SIGNALS_OUT);
  auto input_session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_exampleLDF", "Cluster", "MasterSignal1_U16,MasterSignal2_U16", "LIN1", CREATE_SESSION_MODE_SIGNAL_IN_SINGLE_POINT)).session();
  auto output_session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_exampleLDF", "Cluster", "MasterSignal1_U16,MasterSignal2_U16", "LIN2", CREATE_SESSION_MODE_SIGNAL_OUT_SINGLE_POINT)).session();
  WriteStateValue state_value;
  state_value.set_lin_schedule_change(0);
  EXPECT_SUCCESS(client::write_state(stub(), output_session, WRITE_STATE_LIN_SCHEDULE_CHANGE, state_value));
  EXPECT_SUCCESS(client::start(stub(), input_session, START_STOP_SCOPE_NORMAL));
  output_value_vtr[0] = 5;
  output_value_vtr[1] = 50;

  auto write_signal_single_point_response = EXPECT_SUCCESS(client::write_signal_single_point(stub(), output_session, output_value_vtr));
  int i = 0;
  ReadSignalSinglePointResponse read_signal_single_point_response;
  while (true) {
    read_signal_single_point_response = EXPECT_SUCCESS(client::read_signal_single_point(stub(), input_session, NUM_SIGNALS_IN));
    if (output_value_vtr[0] == read_signal_single_point_response.value_buffer()[0] || i >= MAX_READ_ATTEMPTS) {
      break;
    }
    i++;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }

  EXPECT_SUCCESS(client::clear(stub(), output_session));
  EXPECT_SUCCESS(client::clear(stub(), input_session));
  EXPECT_EQ(output_value_vtr[0], read_signal_single_point_response.value_buffer()[0]) << "LIN1 and LIN2 must be connected together. Couldn't read valid signals after " << MAX_READ_ATTEMPTS << " attempts.";
  EXPECT_EQ(output_value_vtr[1], read_signal_single_point_response.value_buffer()[1]) << "LIN1 and LIN2 must be connected together. Couldn't read valid signals after " << MAX_READ_ATTEMPTS << " attempts.";
}

TEST_F(NiXnetLINDriverApiTestsWithHardware, LoopbackSignalXYTestFromExample_WriteAndReadSignalXY_SignalMatches)
{
  constexpr auto NUM_SAMPLES = 2;
  constexpr auto NUM_SIGNALS = 2;
  std::vector<u32> num_pairs_buffer(NUM_SIGNALS);
  std::vector<f64> value_buffer(NUM_SAMPLES * NUM_SIGNALS);
  auto session_for_writing = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_exampleLDF", "Cluster", "MasterSignal1_U16,MasterSignal2_U16", "LIN1", CREATE_SESSION_MODE_SIGNAL_OUT_XY)).session();
  auto session_for_reading = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_exampleLDF", "Cluster", "MasterSignal1_U16,MasterSignal2_U16,", "LIN2", CREATE_SESSION_MODE_SIGNAL_IN_XY)).session();
  WriteStateValue state_value;
  state_value.set_lin_schedule_change(0);
  EXPECT_SUCCESS(client::write_state(stub(), session_for_writing, WRITE_STATE_LIN_SCHEDULE_CHANGE, state_value));
  EXPECT_SUCCESS(client::start(stub(), session_for_reading, START_STOP_SCOPE_NORMAL));
  for (int i = 0; i < NUM_SIGNALS; ++i) {
    for (int j = 0; j < NUM_SAMPLES; ++j) {
      value_buffer[i * NUM_SAMPLES + j] = i * NUM_SAMPLES + j + 1;
    }
  }
  num_pairs_buffer[0] = NUM_SAMPLES;
  num_pairs_buffer[1] = NUM_SAMPLES;

  auto write_signal_xy_response = EXPECT_SUCCESS(client::write_signal_xy(stub(), session_for_writing, 10, value_buffer, std::vector<u64>(), num_pairs_buffer));
  auto read_signal_xy_response = EXPECT_SUCCESS(client::read_signal_xy(stub(), session_for_reading, -1, NUM_SAMPLES, NUM_SIGNALS));

  EXPECT_SUCCESS(client::clear(stub(), session_for_reading));
  EXPECT_SUCCESS(client::clear(stub(), session_for_writing));
  for (int i = 0; i < NUM_SAMPLES * NUM_SIGNALS; ++i) {
    EXPECT_EQ(value_buffer[i], read_signal_xy_response.value_buffer()[i]) << "LIN1 and LIN2 must be connected together.";
  }
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni