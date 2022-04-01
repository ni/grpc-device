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

typedef pb::uint8 u8;
typedef pb::uint32 u32;
typedef pb::uint64 u64;
typedef double f64;

constexpr auto SCHEMA = "file:///NIXNET_Documentation/xnetIpStackSchema-03.json";
const auto SIMPLE_INTERFACE_CONFIG = R"(
        {
          "address": "inherit",
          "VLANs": [
            {
              "IPv4": {
                "mode": "static",
                "staticAddresses": [
                  {
                    "address": "192.22.33.44",
                    "subnetMask": "255.0.0.0"
                  }
                ]
              }
            }
          ]
        }
)"_json;

std::string create_simple_config(const std::string& interface_name)
{
  auto interface_config = json{};
  interface_config["name"] = interface_name;
  interface_config["MACs"] = std::vector<json>{SIMPLE_INTERFACE_CONFIG};

  auto config = json{};
  config["schema"] = SCHEMA;
  config["xnetInterfaces"] = std::vector<json>{interface_config};

  return config.dump();
}

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
  // frame = new nixnet_grpc::Framerequest();
  nixnet_grpc::FrameRequest* frame = new nixnet_grpc::FrameRequest();
  frame->set_timestamp(0);
  frame->add_flags(FrameFlags::FRAME_FLAGS_UNSPECIFIED);
  frame->set_identifier(4);
  frame->set_type(FrameType::FRAME_TYPE_LIN_DATA);
  frame->set_payload("\0\1\2\3\4\5\6\7");
  frames.push_back(nixnet_grpc::FrameBufferRequest());
  frames.back().set_allocated_lin(frame);
  // frame = new nixnet_grpc::Frame();
  nixnet_grpc::FrameRequest* frame2 = new nixnet_grpc::FrameRequest();
  frame2->set_timestamp(0);
  frame2->add_flags(FrameFlags::FRAME_FLAGS_UNSPECIFIED);
  frame2->set_identifier(2);
  frame2->set_type(FrameType::FRAME_TYPE_LIN_DATA);
  frame2->set_payload("\0\1\2\3\4\5\6\7");
  frames.push_back(nixnet_grpc::FrameBufferRequest());
  frames.back().set_allocated_lin(frame2);

  auto convert_frames_to_signals_single_point_response = EXPECT_SUCCESS(client::convert_frames_to_signals_single_point(stub(), session, NUM_SIGNALS, frames));
  std::vector<f64> value_buffer_copy(convert_frames_to_signals_single_point_response.value_buffer().begin(), convert_frames_to_signals_single_point_response.value_buffer().end());
  auto convert_signals_to_frames_single_point_response = EXPECT_SUCCESS(client::convert_signals_to_frames_single_point(stub(), session, value_buffer_copy, NUM_FRAMES, 8, Protocol::PROTOCOL_LIN));
  EXPECT_SUCCESS(client::clear(stub(), session));

  EXPECT_EQ(2, convert_frames_to_signals_single_point_response.timestamp_buffer_size());
  EXPECT_EQ(2, convert_frames_to_signals_single_point_response.timestamp_buffer().size());
  // EXPECT_EQ(0.0, convert_frames_to_signals_single_point_response.timestamp_buffer(0));
  EXPECT_EQ(2, convert_frames_to_signals_single_point_response.value_buffer_size());
  EXPECT_EQ(2, convert_frames_to_signals_single_point_response.value_buffer().size());
  //EXPECT_EQ(FrameBuffer(), convert_frames_to_signals_single_point_response.value_buffer(0));
  EXPECT_EQ(2, convert_signals_to_frames_single_point_response.buffer_size());
  EXPECT_EQ(2, convert_signals_to_frames_single_point_response.buffer().size());
  //EXPECT_EQ(FrameBuffer(), convert_signals_to_frames_single_point_response.buffer(0));
  frames.clear();
}

// TEST_F(NiXnetLINDriverApiTests, FrameSinglePointInputFromExample_FetchData_DataLooksReasonable)
// {
//   constexpr auto NUM_FRAMES = 2;
//   nixnet_grpc::FrameRequest frame;
//   unsigned int num_bytes = 0;
//   std::vector<nixnet_grpc::FrameBufferRequest> frames;
//   auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_exampleLDF", "Cluster", "MasterFrame1,MasterFrame2", "LIN2", CREATE_SESSION_MODE_FRAME_IN_SINGLE_POINT)).session();
//   /* TODO
//   std::vector<ReadFrameResponse> read_frame_response_vtr;
//   for (int i = 0; i < 20; ++i) {
//     read_frame_response_vtr.push_back(EXPECT_SUCCESS(client::read_frame(stub(), session, NUM_FRAMES, TIME_OUT_TIMEOUT_NONE, FRAME_TYPE_LIN)));
//   }
//   */
//   EXPECT_SUCCESS(client::clear(stub(), session));

//   /*
//   EXPECT_EQ(999, read_frame_response_vtr[0].buffer_size());
//   EXPECT_EQ(999, read_frame_response_vtr[0].buffer().size());
//   //EXPECT_EQ(FrameBuffer(), read_frame_response_vtr[0].buffer(0));
//   */
// }

// TEST_F(NiXnetLINDriverApiTests, FrameSinglePointOutputFromExample_FetchData_DataLooksReasonable)
// {
//   constexpr auto PAYLOAD_SIZE_1 = 8;
//   constexpr auto PAYLOAD_SIZE_2 = 8;
//   constexpr auto NUM_FRAMES = 2;
//   nixnet_grpc::Frame* frame = NULL;
//   std::vector<nixnet_grpc::FrameBuffer> frames;
//   char payload1[PAYLOAD_SIZE_1 + 1] = {0};
//   char payload2[PAYLOAD_SIZE_2 + 1] = {0};
//   auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_exampleLDF", "Cluster", "MasterFrame1,MasterFrame2", "LIN1", CREATE_SESSION_MODE_MODE_FRAME_OUT_SINGLE_POINT)).session_ref();
//   WriteStateValue state_value;
//   state_value.set_lin_schedule_change(0);
//   EXPECT_SUCCESS(client::write_state(stub(), session, WRITE_STATE_STATE_LIN_SCHEDULE_CHANGE, state_value));
//   frame = new nixnet_grpc::Frame();
//   frame->set_timestamp(0);
//   frame->set_flags(0);
//   frame->set_identifier(66);
//   frame->set_type(FRAME_TYPE_LIN);
//   frames.push_back(nixnet_grpc::FrameBuffer());
//   frames.back().set_allocated_lin(frame);
//   frame = new nixnet_grpc::Frame();
//   frame->set_timestamp(0);
//   frame->set_flags(0);
//   frame->set_identifier(67);
//   frame->set_type(FRAME_TYPE_LIN);
//   frames.push_back(nixnet_grpc::FrameBuffer());
//   frames.back().set_allocated_lin(frame);
//   for (char i = 0; i < 20; ++i) {
//     for (char j = 0; j < PAYLOAD_SIZE_1; ++j) {
//       payload1[j] = j + i;
//     }
//     for (char j = 0; j < PAYLOAD_SIZE_2; ++j) {
//       payload2[j] = j + i;
//     }
//     frames[0].mutable_lin()->set_payload(payload1);
//     frames[1].mutable_lin()->set_payload(payload2);
//     /* TODO
//     EXPECT_SUCCESS(client::write_frame(stub(), session, frames, 10.0));
//     */
//   }
//   EXPECT_SUCCESS(client::clear(stub(), session));
// }

TEST_F(NiXnetLINDriverApiTests, FrameStreamInputFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_FRAMES = 2;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_exampleLDF", "Cluster", "", "LIN2", CREATE_SESSION_MODE_FRAME_IN_STREAM)).session();
  EXPECT_SUCCESS(set_property(stub(), session, PROPERTY_SESSION_INTF_LIN_NO_RESPONSE_TO_IN_STRM, true));

  auto read_frame_response = EXPECT_SUCCESS(client::read_frame(stub(), session, NUM_FRAMES, 8, Protocol::PROTOCOL_LIN, TimeOut::TIME_OUT_NONE));
  EXPECT_SUCCESS(client::clear(stub(), session));

  EXPECT_EQ(2, read_frame_response.buffer_size());
  EXPECT_EQ(2, read_frame_response.buffer().size());
  //EXPECT_EQ(FrameBuffer(), read_frame_response_vtr.buffer(0));
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
  std::vector<ReadSignalSinglePointResponse> read_signal_single_point_response_vtr;
  for (int i = 0; i < 20; ++i) {
    output_value_vtr[0] = (f64)(i % 10);
    output_value_vtr[1] = (f64)((i % 10) * 10);
    EXPECT_SUCCESS(client::write_signal_single_point(stub(), output_session, output_value_vtr));
    read_signal_single_point_response_vtr.push_back(EXPECT_SUCCESS(client::read_signal_single_point(stub(), input_session, NUM_SIGNALS_IN)));
  }
  EXPECT_SUCCESS(client::clear(stub(), output_session));
  EXPECT_SUCCESS(client::clear(stub(), input_session));

  EXPECT_EQ(2, read_signal_single_point_response_vtr[0].timestamp_buffer_size());
  EXPECT_EQ(2, read_signal_single_point_response_vtr[0].timestamp_buffer().size());
  // EXPECT_EQ(0 /* timestamp100ns */, read_signal_single_point_response_vtr[0].timestamp_buffer(0));
  EXPECT_EQ(2, read_signal_single_point_response_vtr[0].value_buffer_size());
  EXPECT_EQ(2, read_signal_single_point_response_vtr[0].value_buffer().size());
  EXPECT_EQ(0.0, read_signal_single_point_response_vtr[0].value_buffer(0));
}

// TEST_F(NiXnetLINDriverApiTests, WriteSignalWaveformFromExample_ReadSignalWaveformFromExample_WaveformMatches)
// {
//   constexpr auto NUM_SAMP = 100;
//   constexpr auto NUM_SIGNALS = 2;
//   f64 increment_out = 0.0;
//   f64 min_out = 0.0;
//   f64 max_out = 40.0;
//   std::vector<f64> value_buffer(NUM_SIGNALS * NUM_SAMP);
//   auto session_for_writing = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_exampleLDF", "Cluster", "MasterSignal1_U16,MasterSignal2_U16", "LIN1", CREATE_SESSION_MODE_SIGNAL_OUT_WAVEFORM)).session();
//   WriteStateValue state_value;
//   state_value.set_lin_schedule_change(0);
//   EXPECT_SUCCESS(client::write_state(stub(), session_for_writing, WRITE_STATE_LIN_SCHEDULE_CHANGE, state_value));
//   increment_out = (max_out - min_out) / NUM_SAMP;
//   for (int i = 0; i < NUM_SAMP; ++i) {
//     value_buffer[i] = min_out + (increment_out * i);
//     value_buffer[i + NUM_SAMP] = min_out + (increment_out * ((i + (NUM_SAMP / 2)) % NUM_SAMP));
//   }
//   auto write_signal_waveform_response = EXPECT_SUCCESS(client::write_signal_waveform(stub(), session_for_writing, 1.0, value_buffer));
//   EXPECT_SUCCESS(client::clear(stub(), session_for_writing));

//   auto session_for_reading = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_exampleLDF", "Cluster", "MasterSignal1_U16,MasterSignal2_U16", "LIN2", CREATE_SESSION_MODE_SIGNAL_IN_WAVEFORM)).session();
//   auto read_signal_waveform_response = EXPECT_SUCCESS(client::read_signal_waveform(stub(), session_for_reading, 1.0, NUM_SIGNALS, NUM_SAMP));
//   EXPECT_SUCCESS(client::clear(stub(), session_for_reading));

//   EXPECT_EQ((u32)value_buffer.size(), (u32)read_signal_waveform_response.value_buffer().size());
//   for(int i=0; i < NUM_SAMP; ++i) {
//     EXPECT_EQ(value_buffer[i], read_signal_waveform_response.value_buffer()[i]);
//     EXPECT_EQ(value_buffer[i + NUM_SAMP], read_signal_waveform_response.value_buffer()[i + NUM_SAMP]);
//   }
// }

TEST_F(NiXnetLINDriverApiTests, WriteSignalXYFromExample_ReadSignalXYFromExample_SignalMatches)
{
  constexpr auto NUM_SAMP = 3;
  constexpr auto NUM_SIGNALS = 2;
  f64 increment_out = 0.0;
  f64 min_out = 0.0;
  f64 max_out = 40.0;
  std::vector<u32> num_pairs_buffer(NUM_SIGNALS);
  std::vector<f64> value_buffer(NUM_SAMP * NUM_SIGNALS);
  // std::vector<u64> timestamp_buffer();
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

  EXPECT_EQ((u32)value_buffer.size(), (u32)read_signal_xy_response.value_buffer().size());
  // EXPECT_EQ((u32)timestamp_buffer.size(), (u32)read_signal_xy_response.timestamp_buffer().size());
  for (int i = 0; i < NUM_SAMP; ++i) {
    EXPECT_EQ(value_buffer[i], read_signal_xy_response.value_buffer()[i]);
    EXPECT_EQ(value_buffer[i + NUM_SAMP], read_signal_xy_response.value_buffer()[i + NUM_SAMP]);
  }
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni