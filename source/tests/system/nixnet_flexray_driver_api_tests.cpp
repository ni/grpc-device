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

class NiXnetFlexRayDriverApiTests : public ::testing::Test {
 protected:
  NiXnetFlexRayDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiXnet::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }
  virtual ~NiXnetFlexRayDriverApiTests() {}

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

TEST_F(NiXnetFlexRayDriverApiTests, ConvertFramesToFromSignalsFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_SIGNALS = 2;
  constexpr auto PAYLOAD_SIZE_1 = 8;
  constexpr auto PAYLOAD_SIZE_2 = 8;
  nixnet_grpc::Frame* frame = NULL;
  std::vector<nixnet_grpc::FrameBuffer> frames;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "FlexRay_Cluster", "FlexRayCyclicSignal3,FlexRayEventSignal1", "", CREATE_SESSION_MODE_MODE_SIGNAL_CONVERSION_SINGLE_POINT)).session_ref();
  frame = new nixnet_grpc::Frame();
  frame->set_timestamp(0);
  // TODO: set flags
  //frame->set_flags(nxFrameFlags_FlexRay_ChA | nxFrameFlags_FlexRay_ChB);
  frame->set_identifier(4);
  frame->set_type(FRAME_TYPE_FLEX_RAY);
  frame->set_payload("\0\1\2\3\4\5\6\7");
  frames.push_back(nixnet_grpc::FrameBuffer());
  frames.back().set_allocated_flex_ray(frame);
  frame = new nixnet_grpc::Frame();
  frame->set_timestamp(0);
  // TODO: set flags
  //frame->set_flags(nxFrameFlags_FlexRay_ChA | nxFrameFlags_FlexRay_ChB);
  frame->set_identifier(5);
  frame->set_type(FRAME_TYPE_FLEX_RAY);
  frame->set_payload("\0\1\2\3\4\5\6\7");
  frames.push_back(nixnet_grpc::FrameBuffer());
  frames.back().set_allocated_flex_ray(frame);
  auto convert_frames_to_signals_single_point_response = EXPECT_SUCCESS(client::convert_frames_to_signals_single_point(stub(), session, frames, NUM_SIGNALS, NUM_SIGNALS));
  std::vector<f64> value_buffer_copy(convert_frames_to_signals_single_point_response.value_buffer().begin(), convert_frames_to_signals_single_point_response.value_buffer().end());
  auto convert_signals_to_frames_single_point_response = EXPECT_SUCCESS(client::convert_signals_to_frames_single_point(stub(), session, value_buffer_copy, 2, FRAME_TYPE_FLEX_RAY));
  EXPECT_SUCCESS(client::clear(stub(), session));

  EXPECT_EQ(999, convert_frames_to_signals_single_point_response.timestamp_buffer_size());
  EXPECT_EQ(999, convert_frames_to_signals_single_point_response.timestamp_buffer().size());
  EXPECT_EQ(0.0, convert_frames_to_signals_single_point_response.timestamp_buffer(0));
  EXPECT_EQ(999, convert_frames_to_signals_single_point_response.value_buffer_size());
  EXPECT_EQ(999, convert_frames_to_signals_single_point_response.value_buffer().size());
  //EXPECT_EQ(FrameBuffer(), convert_frames_to_signals_single_point_response.value_buffer(0));
  EXPECT_EQ(999, convert_signals_to_frames_single_point_response.buffer_size());
  EXPECT_EQ(999, convert_signals_to_frames_single_point_response.buffer().size());
  //EXPECT_EQ(FrameBuffer(), convert_signals_to_frames_single_point_response.buffer(0));
}

TEST_F(NiXnetFlexRayDriverApiTests, FrameSinglePointInputFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto PAYLOAD_SIZE_1 = 8;
  constexpr auto PAYLOAD_SIZE_2 = 8;
  nixnet_grpc::Frame* frame = NULL;
  u32 num_bytes = 0;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "FlexRay_Cluster", "FlexRayEventFrame1,FlexRayEventFrame2", "FlexRay2", CREATE_SESSION_MODE_MODE_FRAME_IN_SINGLE_POINT)).session_ref();
  EXPECT_SUCCESS(set_property(stub(), session, PROPERTY_SESSION_INTF_FLEX_RAY_KEY_SLOT_ID, (u32)1));
  /* TODO
  std::vector<ReadFrameResponse> read_frame_response_vtr;
  for (int i = 0; i < 20; ++i) {
    read_frame_response_vtr.push_back(EXPECT_SUCCESS(client::read_frame(stub(), session, 2, TIME_OUT_TIMEOUT_NONE, FRAME_TYPE_FLEX_RAY)));
  }
  */
  EXPECT_SUCCESS(client::clear(stub(), session));

  /*
  EXPECT_EQ(999, read_frame_response_vtr[0].buffer_size());
  EXPECT_EQ(999, read_frame_response_vtr[0].buffer().size());
  //EXPECT_EQ(FrameBuffer(), read_frame_response_vtr[0].buffer(0));
  */
}

TEST_F(NiXnetFlexRayDriverApiTests, FrameSinglePointOutputFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto PAYLOAD_SIZE_1 = 8;
  constexpr auto PAYLOAD_SIZE_2 = 8;
  nixnet_grpc::Frame* frame = NULL;
  std::vector<nixnet_grpc::FrameBuffer> frames;
  char payload1[PAYLOAD_SIZE_1 + 1] = {0};
  char payload2[PAYLOAD_SIZE_2 + 1] = {0};
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "FlexRay_Cluster", "FlexRayEventFrame1,FlexRayEventFrame2", "FlexRay1", CREATE_SESSION_MODE_MODE_FRAME_OUT_SINGLE_POINT)).session_ref();
  EXPECT_SUCCESS(set_property(stub(), session, PROPERTY_SESSION_INTF_FLEX_RAY_KEY_SLOT_ID, (u32)2));
  frame = new nixnet_grpc::Frame();
  frame->set_timestamp(0);
  frame->set_flags(0);
  frame->set_identifier(5);
  frame->set_type(FRAME_TYPE_FLEX_RAY);
  frame->set_payload("\0\1\2\3\4\5\6\7");
  frames.push_back(nixnet_grpc::FrameBuffer());
  frames.back().set_allocated_flex_ray(frame);
  frame = new nixnet_grpc::Frame();
  frame->set_timestamp(0);
  frame->set_flags(0);
  frame->set_identifier(6);
  frame->set_type(FRAME_TYPE_FLEX_RAY);
  frame->set_payload("\0\1\2\3\4\5\6\7");
  frames.push_back(nixnet_grpc::FrameBuffer());
  frames.back().set_allocated_flex_ray(frame);
  for (char i = 0; i < 20; ++i) {
    for (char j = 0; j < PAYLOAD_SIZE_1; ++j) {
      payload1[j] = j + i;
    }
    for (char j = 0; j < PAYLOAD_SIZE_2; ++j) {
      payload2[j] = j + i;
    }
    frames[0].mutable_lin()->set_payload(payload1);
    frames[1].mutable_lin()->set_payload(payload2);
    /* TODO
    EXPECT_SUCCESS(client::write_frame(stub(), session, frames, 10.0));
    */
  }
  EXPECT_SUCCESS(client::clear(stub(), session));
}

TEST_F(NiXnetFlexRayDriverApiTests, FrameStreamInputFromExample_FetchData_DataLooksReasonable)
{
  unsigned int j = 0;
  char frame_channel_a = '-';
  char frame_channel_b = '-';
  nixnet_grpc::Frame* frame = NULL;
  std::vector<nixnet_grpc::FrameBuffer> frames;
  u32 num_bytes = 0;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "FlexRay_Cluster", NULL, "FlexRay2", CREATE_SESSION_MODE_MODE_FRAME_IN_STREAM)).session_ref();
  EXPECT_SUCCESS(set_property(stub(), session, PROPERTY_SESSION_INTF_FLEX_RAY_KEY_SLOT_ID, (u32)1));
  /* TODO
  std::vector<ReadFrameResponse> read_frame_response_vtr;
  for (int i = 0; i < 20; ++i) {
    read_frame_response_vtr.push_back(EXPECT_SUCCESS(client::read_frame(stub(), session, 10000, TIME_OUT_TIMEOUT_NONE, FRAME_TYPE_FLEX_RAY)));
  }
  */
  EXPECT_SUCCESS(client::clear(stub(), session));

  /*
  EXPECT_EQ(999, read_frame_response_vtr[0].buffer_size());
  EXPECT_EQ(999, read_frame_response_vtr[0].buffer().size());
  //EXPECT_EQ(FrameBuffer(), read_frame_response_vtr[0].buffer(0));
  */
}

/*
TEST_F(NiXnetFlexRayDriverApiTests, InputOutputSamePortFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_SIGNALS_OUT = 2;
  constexpr auto NUM_SIGNALS_IN = 2;
  unsigned int i = 0;
  int typed_char = 0;
  std::vector<f64> output_value_vtr(NUM_SIGNALS_OUT);
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "FlexRay_Cluster", "FlexRayEventSignal1,FlexRayCyclicSignal1", "FlexRay1", CREATE_SESSION_MODE_MODE_SIGNAL_IN_SINGLE_POINT)).session_ref();
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "FlexRay_Cluster", "FlexRayCyclicSignal3,FlexRayCyclicSignal4", "FlexRay1", CREATE_SESSION_MODE_MODE_SIGNAL_OUT_SINGLE_POINT)).session_ref();
  EXPECT_SUCCESS(set_property(stub(), session, PROPERTY_SESSION_INTF_FLEX_RAY_KEY_SLOT_ID, (u32)2));
  std::vector<ReadSignalSinglePointResponse> read_signal_single_point_response_vtr;
  while ('q' != (typed_char = tolower(_getch()))) {
    switch (typed_char) {
      case 'r':
        read_signal_single_point_response_vtr.push_back(EXPECT_SUCCESS(client::read_signal_single_point(stub(), session, NUM_SIGNALS_IN, NUM_SIGNALS_IN)));
        break;
      case 't':
        output_value_vtr[0] = (f64)i;
        output_value_vtr[1] = (f64)(i * 10);
        EXPECT_SUCCESS(client::write_signal_single_point(stub(), session, output_value_vtr));
        if (++i > 10) {
          i = 0;
        }
        break;
      default:
        break;
    }
  }
  EXPECT_SUCCESS(client::clear(stub(), session));
  EXPECT_SUCCESS(client::clear(stub(), session));

  EXPECT_EQ(999, read_signal_single_point_response_vtr[0].timestamp_buffer_size());
  EXPECT_EQ(999, read_signal_single_point_response_vtr[0].timestamp_buffer().size());
*/
//  EXPECT_EQ(0 /* timestamp100ns */, read_signal_single_point_response_vtr[0].timestamp_buffer(0));
/*
  EXPECT_EQ(999, read_signal_single_point_response_vtr[0].value_buffer_size());
  EXPECT_EQ(999, read_signal_single_point_response_vtr[0].value_buffer().size());
  EXPECT_EQ(0.0, read_signal_single_point_response_vtr[0].value_buffer(0));
}
*/

TEST_F(NiXnetFlexRayDriverApiTests, LoopbackTestFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_SIGNALS_OUT = 2;
  constexpr auto NUM_SIGNALS_IN = 2;
  std::vector<f64> output_value_vtr(NUM_SIGNALS_OUT);
  auto input_session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "FlexRay_Cluster", "FlexRayEventSignal1,FlexRayEventSignal2", "FlexRay1", CREATE_SESSION_MODE_MODE_SIGNAL_IN_SINGLE_POINT)).session_ref();
  auto output_session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "FlexRay_Cluster", "FlexRayEventSignal1,FlexRayEventSignal2", "FlexRay2", CREATE_SESSION_MODE_MODE_SIGNAL_OUT_SINGLE_POINT)).session_ref();
  EXPECT_SUCCESS(set_property(stub(), input_session, PROPERTY_SESSION_INTF_FLEX_RAY_KEY_SLOT_ID, (u32)2));
  EXPECT_SUCCESS(set_property(stub(), output_session, PROPERTY_SESSION_INTF_FLEX_RAY_KEY_SLOT_ID, (u32)1));
  EXPECT_SUCCESS(client::start(stub(), input_session, START_STOP_SCOPE_START_STOP_NORMAL));
  std::vector<ReadSignalSinglePointResponse> read_signal_single_point_response_vtr;
  for (int i = 0; i < 20; ++i) {
    output_value_vtr[0] = (f64)(i % 10);
    output_value_vtr[1] = (f64)((i % 10) * 10);
    EXPECT_SUCCESS(client::write_signal_single_point(stub(), output_session, output_value_vtr));
    read_signal_single_point_response_vtr.push_back(EXPECT_SUCCESS(client::read_signal_single_point(stub(), input_session, NUM_SIGNALS_IN, NUM_SIGNALS_IN)));
  }
  EXPECT_SUCCESS(client::clear(stub(), output_session));
  EXPECT_SUCCESS(client::clear(stub(), input_session));

  EXPECT_EQ(999, read_signal_single_point_response_vtr[0].timestamp_buffer_size());
  EXPECT_EQ(999, read_signal_single_point_response_vtr[0].timestamp_buffer().size());
  EXPECT_EQ(0 /* timestamp100ns */, read_signal_single_point_response_vtr[0].timestamp_buffer(0));
  EXPECT_EQ(999, read_signal_single_point_response_vtr[0].value_buffer_size());
  EXPECT_EQ(999, read_signal_single_point_response_vtr[0].value_buffer().size());
  EXPECT_EQ(0.0, read_signal_single_point_response_vtr[0].value_buffer(0));
}

TEST_F(NiXnetFlexRayDriverApiTests, PDUSinglePointInputFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto PAYLOAD_SIZE_1 = 4;
  constexpr auto PAYLOAD_SIZE_2 = 2;
  nixnet_grpc::Frame* frame = NULL;
  std::vector<nixnet_grpc::FrameBuffer> frames;
  u32 num_bytes = 0;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "FlexRay_Cluster", "FlexRayCyclicFrame1_pdu,FlexRayCyclicFrame2_pdu", "FlexRay2", CREATE_SESSION_MODE_MODE_FRAME_IN_SINGLE_POINT)).session_ref();
  EXPECT_SUCCESS(set_property(stub(), session, PROPERTY_SESSION_INTF_FLEX_RAY_KEY_SLOT_ID, (u32)1));
  /* TODO
  std::vector<ReadFrameResponse> read_frame_response_vtr;
  for (int i = 0; i < 20; ++i) {
    read_frame_response_vtr.push_back(EXPECT_SUCCESS(client::read_frame(stub(), session, 2, TIME_OUT_TIMEOUT_NONE, FRAME_TYPE_FLEX_RAY)));
  }
  */
  EXPECT_SUCCESS(client::clear(stub(), session));

  /*
  EXPECT_EQ(999, read_frame_response_vtr[0].buffer_size());
  EXPECT_EQ(999, read_frame_response_vtr[0].buffer().size());
  //EXPECT_EQ(FrameBuffer(), read_frame_response_vtr[0].buffer(0));
  */
}

TEST_F(NiXnetFlexRayDriverApiTests, PDUSinglePointOutputFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto PAYLOAD_SIZE_1 = 4;
  constexpr auto PAYLOAD_SIZE_2 = 2;
  nixnet_grpc::Frame* frame = NULL;
  std::vector<nixnet_grpc::FrameBuffer> frames;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "FlexRay_Cluster", "FlexRayCyclicFrame1_pdu,FlexRayCyclicFrame2_pdu", "FlexRay1", CREATE_SESSION_MODE_MODE_FRAME_OUT_SINGLE_POINT)).session_ref();
  EXPECT_SUCCESS(set_property(stub(), session, PROPERTY_SESSION_INTF_FLEX_RAY_KEY_SLOT_ID, (u32)2));
  EXPECT_SUCCESS(client::start(stub(), session, START_STOP_SCOPE_START_STOP_NORMAL));
  auto wait_response = EXPECT_SUCCESS(client::wait(stub(), session, WAIT_CONDITION_CONDITION_INTF_COMMUNICATING, 0, 10.0));
  frame = new nixnet_grpc::Frame();
  frame->set_payload("\0\1\2\3");
  frames.push_back(nixnet_grpc::FrameBuffer());
  frames.back().set_allocated_flex_ray(frame);
  frame = new nixnet_grpc::Frame();
  frame->set_payload("\0\1");
  frames.push_back(nixnet_grpc::FrameBuffer());
  frames.back().set_allocated_flex_ray(frame);
  for (int i = 0; i < 20; ++i) {
    /* TODO
    EXPECT_SUCCESS(client::write_frame(stub(), session, frames, 10.0));
    */
  }
  EXPECT_SUCCESS(client::clear(stub(), session));

  EXPECT_EQ(0, wait_response.param_out());
}

TEST_F(NiXnetFlexRayDriverApiTests, SignalSinglePointInputFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_SIGNALS = 2;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "FlexRay_Cluster", "FlexRayEventSignal1,FlexRayEventSignal2", "FlexRay2", CREATE_SESSION_MODE_MODE_SIGNAL_IN_SINGLE_POINT)).session_ref();
  EXPECT_SUCCESS(set_property(stub(), session, PROPERTY_SESSION_INTF_FLEX_RAY_KEY_SLOT_ID, (u32)1));
  std::vector<ReadSignalSinglePointResponse> read_signal_single_point_response_vtr;
  for (int i = 0; i < 20; ++i) {
    read_signal_single_point_response_vtr.push_back(EXPECT_SUCCESS(client::read_signal_single_point(stub(), session, NUM_SIGNALS, NUM_SIGNALS)));
  }
  EXPECT_SUCCESS(client::clear(stub(), session));

  EXPECT_EQ(999, read_signal_single_point_response_vtr[0].timestamp_buffer_size());
  EXPECT_EQ(999, read_signal_single_point_response_vtr[0].timestamp_buffer().size());
  EXPECT_EQ(0 /* timestamp100ns */, read_signal_single_point_response_vtr[0].timestamp_buffer(0));
  EXPECT_EQ(999, read_signal_single_point_response_vtr[0].value_buffer_size());
  EXPECT_EQ(999, read_signal_single_point_response_vtr[0].value_buffer().size());
  EXPECT_EQ(0.0, read_signal_single_point_response_vtr[0].value_buffer(0));
}

TEST_F(NiXnetFlexRayDriverApiTests, SignalWaveformInputFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_SAMP = 100;
  constexpr auto NUM_SIGNALS = 2;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "FlexRay_Cluster", "FlexRayCyclicSignal1,FlexRayCyclicSignal2", "FlexRay2", CREATE_SESSION_MODE_MODE_SIGNAL_IN_WAVEFORM)).session_ref();
  EXPECT_SUCCESS(set_property(stub(), session, PROPERTY_SESSION_INTF_FLEX_RAY_KEY_SLOT_ID, (u32)1));
  std::vector<ReadSignalWaveformResponse> read_signal_waveform_response_vtr;
  for (int i = 0; i < 20; ++i) {
    read_signal_waveform_response_vtr.push_back(EXPECT_SUCCESS(client::read_signal_waveform(stub(), session, 1.0, NUM_SIGNALS * NUM_SAMP)));
  }
  EXPECT_SUCCESS(client::clear(stub(), session));

  EXPECT_EQ(0, read_signal_waveform_response_vtr[0].number_of_values_returned());
  EXPECT_EQ(999, read_signal_waveform_response_vtr[0].value_buffer_size());
  EXPECT_EQ(999, read_signal_waveform_response_vtr[0].value_buffer().size());
  EXPECT_EQ(0.0, read_signal_waveform_response_vtr[0].value_buffer(0));
  EXPECT_EQ(0.0, read_signal_waveform_response_vtr[0].delta_time());
  EXPECT_EQ(0 /* timestamp100ns */, read_signal_waveform_response_vtr[0].start_time());
}

TEST_F(NiXnetFlexRayDriverApiTests, SignalWaveformOutputFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_SAMP = 300;
  constexpr auto NUM_SIGNALS = 2;
  f64 increment_out = 0.0;
  f64 min_out = 0.0;
  f64 max_out = 10.0;
  std::vector<f64> value_vtr(NUM_SIGNALS * NUM_SAMP);
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "FlexRay_Cluster", "FlexRayCyclicSignal1,FlexRayCyclicSignal2", "FlexRay1", CREATE_SESSION_MODE_MODE_SIGNAL_OUT_WAVEFORM)).session_ref();
  EXPECT_SUCCESS(set_property(stub(), session, PROPERTY_SESSION_INTF_FLEX_RAY_KEY_SLOT_ID, (u32)2));
  increment_out = (max_out - min_out) / NUM_SAMP;
  for (int i = 0; i < NUM_SAMP; ++i) {
    value_vtr[i] = min_out + (increment_out * i);
    value_vtr[i + NUM_SAMP] = min_out + (increment_out * ((i + (NUM_SAMP / 2)) % NUM_SAMP));
  }
  for (int i = 0; i < 20; ++i) {
    EXPECT_SUCCESS(client::write_signal_waveform(stub(), session, 10.0, value_vtr));
  }
  EXPECT_SUCCESS(client::clear(stub(), session));
}

TEST_F(NiXnetFlexRayDriverApiTests, SignalXYInputFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_SAMP = 1000;
  constexpr auto NUM_SIGNALS = 1;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "FlexRay_Cluster", "FlexRayCyclicSignal1", "FlexRay2", CREATE_SESSION_MODE_MODE_SIGNAL_IN_XY)).session_ref();
  EXPECT_SUCCESS(set_property(stub(), session, PROPERTY_SESSION_INTF_FLEX_RAY_KEY_SLOT_ID, (u32)1));
  /*
  std::vector<ReadSignalXYResponse> read_signal_xy_response_vtr;
  for (int i = 0; i < 20; ++i) {
    read_signal_xy_response_vtr.push_back(EXPECT_SUCCESS(client::read_signal_xy(stub(), session, NULL, NUM_SIGNALS * NUM_SAMP, NUM_SIGNALS * NUM_SAMP, NUM_SIGNALS)));
  }
  */
  EXPECT_SUCCESS(client::clear(stub(), session));

  /*
  EXPECT_EQ(999, read_signal_xy_response_vtr[0].num_pairs_buffer_size());
  EXPECT_EQ(999, read_signal_xy_response_vtr[0].num_pairs_buffer().size());
  EXPECT_EQ(0, read_signal_xy_response_vtr[0].num_pairs_buffer(0));
  EXPECT_EQ(999, read_signal_xy_response_vtr[0].timestamp_buffer_size());
  EXPECT_EQ(999, read_signal_xy_response_vtr[0].timestamp_buffer().size());
  */
  //EXPECT_EQ(0 /* timestamp100ns */, read_signal_xy_response_vtr[0].timestamp_buffer(0));
  /*
  EXPECT_EQ(999, read_signal_xy_response_vtr[0].value_buffer_size());
  EXPECT_EQ(999, read_signal_xy_response_vtr[0].value_buffer().size());
  EXPECT_EQ(0.0, read_signal_xy_response_vtr[0].value_buffer(0));
  */
}

TEST_F(NiXnetFlexRayDriverApiTests, SignalXYOutputFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_SAMP = 50;
  constexpr auto NUM_SIGNALS = 1;
  f64 increment_out = 0.0;
  std::vector<u32> num_pairs_vtr(NUM_SIGNALS);
  f64 min_out = 0.0;
  f64 max_out = 40.0;
  std::vector<f64> value_vtr(NUM_SAMP);
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "FlexRay_Cluster", "FlexRayCyclicSignal1", "FlexRay1", CREATE_SESSION_MODE_MODE_SIGNAL_OUT_XY)).session_ref();
  EXPECT_SUCCESS(set_property(stub(), session, PROPERTY_SESSION_INTF_FLEX_RAY_KEY_SLOT_ID, (u32)2));
  num_pairs_vtr[0] = NUM_SAMP;
  increment_out = (max_out - min_out) / NUM_SAMP;
  for (int i = 0; i < NUM_SAMP; ++i) {
    value_vtr[i] = min_out + (increment_out * ((i + (NUM_SAMP / 2)) % NUM_SAMP));
  }
  for (int i = 0; i < 20; ++i) {
    EXPECT_SUCCESS(client::write_signal_xy(stub(), session, 10.0, value_vtr, std::vector<u64>(), num_pairs_vtr));
  }
  EXPECT_SUCCESS(client::clear(stub(), session));
}

/*
TEST_F(NiXnetFlexRayDriverApiTests, SynchronizeWithDAQmxFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_SAMP = 100;
  constexpr auto NUM_SIGNALS = 2;
  f64 daq_value_buffer[NUM_SIGNALS][NUM_SAMP];
  char* daq_channel_string = "Dev1/ai0";
  u32 sample_rate = 1000;
  DAQmxErrChk(DAQmxCreateTask("DAQ Task", &m_DaqTask));
  DAQmxErrChk(DAQmxCreateAIVoltageChan(m_DaqTask, daq_channel_string, "", DAQmx_Val_Cfg_Default, -10.0, 10.0, DAQmx_Val_Volts, ""));
  DAQmxErrChk(DAQmxCfgSampClkTiming(m_DaqTask, "OnboardClock", sample_rate, DAQmx_Val_Rising, DAQmx_Val_ContSamps, NUM_SAMP));
  DAQmxErrChk(DAQmxExportSignal(m_DaqTask, DAQmx_Val_10MHzRefClock, "/Dev1/RTSI1"));
  DAQmxErrChk(DAQmxExportSignal(m_DaqTask, DAQmx_Val_StartTrigger, "/Dev1/RTSI0"));
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "FlexRay_Cluster", "FlexRayCyclicSignal3,FlexRayCyclicSignal4", "FlexRay2", CREATE_SESSION_MODE_MODE_SIGNAL_IN_WAVEFORM)).session_ref();
  EXPECT_SUCCESS(client::connect_terminals(stub(), session, "PXI_Trig0", "MasterTimebase"));
  EXPECT_SUCCESS(client::connect_terminals(stub(), session, "PXI_Trig1", "StartTrigger"));
  EXPECT_SUCCESS(set_property(stub(), session, PROPERTY_SESSION_INTF_FLEX_RAY_KEY_SLOT_ID, (u32)1));
  EXPECT_SUCCESS(client::start(stub(), session, START_STOP_SCOPE_START_STOP_NORMAL));
  DAQmxErrChk(DAQmxStartTask(m_DaqTask));
  std::vector<ReadSignalWaveformResponse> read_signal_waveform_response_vtr;
  for (int i = 0; i < 20; ++i) {
    read_signal_waveform_response_vtr.push_back(EXPECT_SUCCESS(client::read_signal_waveform(stub(), session, 1.0, NUM_SIGNALS * NUM_SAMP)));
    DAQmxErrChk(DAQmxReadAnalogF64(m_DaqTask, NUM_SAMP, 10, DAQmx_Val_GroupByChannel, (f64*)daq_value_buffer, NUM_SAMP, NULL, NULL));
  }
  EXPECT_SUCCESS(client::clear(stub(), session));
  DAQmxErrChk(DAQmxStopTask(m_DaqTask));
  DAQmxErrChk(DAQmxClearTask(m_DaqTask));

  EXPECT_EQ(0, read_signal_waveform_response_vtr[0].number_of_values_returned());
  EXPECT_EQ(999, read_signal_waveform_response_vtr[0].value_buffer_size());
  EXPECT_EQ(999, read_signal_waveform_response_vtr[0].value_buffer().size());
  EXPECT_EQ(0.0, read_signal_waveform_response_vtr[0].value_buffer(0));
  EXPECT_EQ(0.0, read_signal_waveform_response_vtr[0].delta_time());
*/
//  EXPECT_EQ(0 /* timestamp100ns */, read_signal_waveform_response_vtr[0].start_time());
//}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
