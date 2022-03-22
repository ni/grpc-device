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
typedef pb::uint16 u16;
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

  void claim_by_address(::nidevice_grpc::Session session, u64 node_name, u32 in_node_addr, u32* out_node_addr);

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiXnet::Stub> stub_;
};

void NiXnetCANDriverApiTests::claim_by_address(::nidevice_grpc::Session session, u64 node_name, u32 in_node_addr, u32* out_node_addr)
{
  EXPECT_SUCCESS(set_property(stub(), session, PROPERTY_SESSION_J1939_NAME, node_name));
  EXPECT_SUCCESS(set_property(stub(), session, PROPERTY_SESSION_J1939_ADDRESS, in_node_addr));

  u16 attempts = 0;
  while (true) {
    Sleep(5);
    auto get_property_response = EXPECT_SUCCESS(get_property(stub(), session, PROPERTY_SESSION_J1939_ADDRESS));
    *out_node_addr = get_property_response.u32_scalar();
    if (*out_node_addr < 254 || ++attempts > 300 || get_property_response.status() != 0) {
      break;
    }
  }

  EXPECT_GE(*out_node_addr, 254U);
}

TEST_F(NiXnetCANDriverApiTests, ConvertFramesToFromSignalsFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_FRAMES = 2;
  constexpr auto NUM_SIGNALS = 2;
  nixnet_grpc::Frame* frame = NULL;
  std::vector<nixnet_grpc::FrameBuffer> frames;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "CAN_Cluster", "CANEventSignal1,CANEventSignal3", "", CREATE_SESSION_MODE_MODE_SIGNAL_CONVERSION_SINGLE_POINT)).session_ref();
  frame = new nixnet_grpc::Frame();
  frame->set_timestamp(0);
  frame->set_flags(0);
  frame->set_identifier(66);
  frame->set_type(FRAME_TYPE_CAN);
  frame->set_payload("\0\1\2\3\4\5\6\7");
  frames.push_back(nixnet_grpc::FrameBuffer());
  frames.back().set_allocated_can(frame);
  frame = new nixnet_grpc::Frame();
  frame->set_timestamp(0);
  frame->set_flags(0);
  frame->set_identifier(67);
  frame->set_type(FRAME_TYPE_CAN);
  frame->set_payload("\0\1");
  frames.push_back(nixnet_grpc::FrameBuffer());
  frames.back().set_allocated_can(frame);
  auto convert_frames_to_signals_single_point_response = EXPECT_SUCCESS(client::convert_frames_to_signals_single_point(stub(), session, frames, NUM_SIGNALS, NUM_SIGNALS));
  std::vector<f64> value_buffer_copy(convert_frames_to_signals_single_point_response.value_buffer().begin(), convert_frames_to_signals_single_point_response.value_buffer().end());
  auto convert_signals_to_frames_single_point_response = EXPECT_SUCCESS(client::convert_signals_to_frames_single_point(stub(), session, value_buffer_copy, NUM_FRAMES, FRAME_TYPE_CAN));
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

TEST_F(NiXnetCANDriverApiTests, FrameSinglePointInputFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_FRAMES = 2;
  nixnet_grpc::Frame* frame = NULL;
  unsigned int num_bytes = 0;
  std::vector<nixnet_grpc::FrameBuffer> frames;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "CAN_Cluster", "CANEventFrame1,CANEventFrame2", "CAN2", CREATE_SESSION_MODE_MODE_FRAME_IN_SINGLE_POINT)).session_ref();
  /* TODO
  std::vector<ReadFrameResponse> read_frame_response_vtr;
  for (int i = 0; i < 20; ++i) {
    read_frame_response_vtr.push_back(EXPECT_SUCCESS(client::read_frame(stub(), session, NUM_FRAMES, TIME_OUT_TIMEOUT_NONE, FRAME_TYPE_CAN)));
  }
  */
  EXPECT_SUCCESS(client::clear(stub(), session));

  /*
  EXPECT_EQ(999, read_frame_response_vtr[0].buffer_size());
  EXPECT_EQ(999, read_frame_response_vtr[0].buffer().size());
  //EXPECT_EQ(FrameBuffer(), read_frame_response_vtr[0].buffer(0));
  */
}

TEST_F(NiXnetCANDriverApiTests, FrameSinglePointOutputFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_FRAMES = 2;
  nixnet_grpc::Frame* frame = NULL;
  std::vector<nixnet_grpc::FrameBuffer> frames;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "CAN_Cluster", "CANEventFrame1,CANEventFrame2", "CAN1", CREATE_SESSION_MODE_MODE_FRAME_OUT_SINGLE_POINT)).session_ref();
  frame = new nixnet_grpc::Frame();
  frame->set_timestamp(0);
  frame->set_flags(0);
  frame->set_identifier(66);
  frame->set_type(FRAME_TYPE_CAN);
  frames.push_back(nixnet_grpc::FrameBuffer());
  frames.back().set_allocated_can(frame);
  frame = new nixnet_grpc::Frame();
  frame->set_timestamp(0);
  frame->set_flags(0);
  frame->set_identifier(67);
  frame->set_type(FRAME_TYPE_CAN);
  frames.push_back(nixnet_grpc::FrameBuffer());
  frames.back().set_allocated_can(frame);
  for (int i = 0; i < 20; ++i) {
    frames[0].mutable_can()->set_payload("\0\1\2\3\4\5\6\7");
    frames[1].mutable_can()->set_payload("\0\1");
    /* TODO
    EXPECT_SUCCESS(client::write_frame(stub(), session, frames, 10.0));
    */
  }
  EXPECT_SUCCESS(client::clear(stub(), session));
}

TEST_F(NiXnetCANDriverApiTests, FrameStreamInputFromExample_FetchData_DataLooksReasonable)
{
  nixnet_grpc::Frame* frame = NULL;
  std::vector<nixnet_grpc::FrameBuffer> frames;
  u32 num_bytes = 0;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), ":memory:", "", "", "CAN2", CREATE_SESSION_MODE_MODE_FRAME_IN_STREAM)).session_ref();
  EXPECT_SUCCESS(set_property(stub(), session, PROPERTY_SESSION_INTF_BAUD_RATE_64, (u64)125000));
  /* TODO
  std::vector<ReadFrameResponse> read_frame_response_vtr;
  for (int i = 0; i < 20; ++i) {
    read_frame_response_vtr.push_back(EXPECT_SUCCESS(client::read_frame(stub(), session, 250, TIME_OUT_TIMEOUT_NONE, FRAME_TYPE_CAN)));
  }
  */
  EXPECT_SUCCESS(client::clear(stub(), session));

  /*
  EXPECT_EQ(999, read_frame_response_vtr[0].buffer_size());
  EXPECT_EQ(999, read_frame_response_vtr[0].buffer().size());
  //EXPECT_EQ(FrameBuffer(), read_frame_response_vtr[0].buffer(0));
  */
}

TEST_F(NiXnetCANDriverApiTests, FrameStreamOutputFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_FRAMES = 2;
  nixnet_grpc::Frame* frame = NULL;
  std::vector<nixnet_grpc::FrameBuffer> frames;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), ":memory:", "", "", "CAN1", CREATE_SESSION_MODE_MODE_FRAME_OUT_STREAM)).session_ref();
  EXPECT_SUCCESS(set_property(stub(), session, PROPERTY_SESSION_INTF_BAUD_RATE_64, (u64)125000));
  frame = new nixnet_grpc::Frame();
  frame->set_timestamp(0);
  frame->set_flags(0);
  frame->set_identifier(4);
  frame->set_type(FRAME_TYPE_CAN);
  frames.push_back(nixnet_grpc::FrameBuffer());
  frames.back().set_allocated_can(frame);
  frame = new nixnet_grpc::Frame();
  frame->set_timestamp(0);
  frame->set_flags(0);
  frame->set_identifier(5);
  frame->set_type(FRAME_TYPE_CAN);
  frames.push_back(nixnet_grpc::FrameBuffer());
  frames.back().set_allocated_can(frame);
  for (int i = 0; i < 20; ++i) {
    frames[0].mutable_can()->set_payload("\0\1\2\3\4\5\6\7");
    frames[1].mutable_can()->set_payload("\0\1");
    /* TODO
    EXPECT_SUCCESS(client::write_frame(stub(), session, frames, 10.0));
    */
  }
  EXPECT_SUCCESS(client::clear(stub(), session));
}

/*
TEST_F(NiXnetCANDriverApiTests, InputOutputSamePortFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_SIGNALS_OUT = 2;
  constexpr auto NUM_SIGNALS_IN = 2;
  unsigned int i = 0;
  int typed_char = 0;
  std::vector<f64> output_value_vtr(NUM_SIGNALS_OUT);
  auto input_session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "CAN_Cluster", "CANEventSignal1,CANEventSignal2", "CAN1", CREATE_SESSION_MODE_MODE_SIGNAL_IN_SINGLE_POINT)).session_ref();
  auto output_session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "CAN_Cluster", "CANEventSignal3,CANEventSignal4", "CAN1", CREATE_SESSION_MODE_MODE_SIGNAL_OUT_SINGLE_POINT)).session_ref();
  std::vector<ReadSignalSinglePointResponse> read_signal_single_point_response_vtr;
  while ('q' != (typed_char = tolower(_getch()))) {
    switch (typed_char) {
      case 'r':
        read_signal_single_point_response_vtr.push_back(EXPECT_SUCCESS(client::read_signal_single_point(stub(), input_session, NUM_SIGNALS_IN, NUM_SIGNALS_IN)));
        break;
      case 't':
        output_value_vtr[0] = (f64)i;
        output_value_vtr[1] = (f64)(i * 10);
        EXPECT_SUCCESS(client::write_signal_single_point(stub(), output_session, output_value_vtr));
        if (++i > 10) {
          i = 0;
        }
        break;
      default:
        break;
    }
  }
  EXPECT_SUCCESS(client::clear(stub(), output_session));
  EXPECT_SUCCESS(client::clear(stub(), input_session));

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

TEST_F(NiXnetCANDriverApiTests, LoopbackTestFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_SIGNALS_OUT = 2;
  constexpr auto NUM_SIGNALS_IN = 2;
  std::vector<f64> output_value_vtr(NUM_SIGNALS_OUT);
  auto input_session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "CAN_Cluster", "CANEventSignal1,CANEventSignal2", "CAN1", CREATE_SESSION_MODE_MODE_SIGNAL_IN_SINGLE_POINT)).session_ref();
  auto output_session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "CAN_Cluster", "CANEventSignal1,CANEventSignal2", "CAN2", CREATE_SESSION_MODE_MODE_SIGNAL_OUT_SINGLE_POINT)).session_ref();
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

TEST_F(NiXnetCANDriverApiTests, SignalSinglePointInputFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_SIGNALS = 2;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "CAN_Cluster", "CANEventSignal1,CANEventSignal2", "CAN2", CREATE_SESSION_MODE_MODE_SIGNAL_IN_SINGLE_POINT)).session_ref();
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

TEST_F(NiXnetCANDriverApiTests, SignalSinglePointOutputFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_SIGNALS = 2;
  std::vector<f64> value_vtr(NUM_SIGNALS);
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "CAN_Cluster", "CANEventSignal1,CANEventSignal2", "CAN1", CREATE_SESSION_MODE_MODE_SIGNAL_OUT_SINGLE_POINT)).session_ref();
  for (int i = 0; i < 20; ++i) {
    value_vtr[0] = (f64)(i % 10);
    value_vtr[1] = (f64)((i % 10) * 10);
    EXPECT_SUCCESS(client::write_signal_single_point(stub(), session, value_vtr));
  }
  EXPECT_SUCCESS(client::clear(stub(), session));
}

TEST_F(NiXnetCANDriverApiTests, SignalWaveformInputFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_SAMP = 100;
  constexpr auto NUM_SIGNALS = 2;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "CAN_Cluster", "CANCyclicSignal3,CANCyclicSignal4", "CAN2", CREATE_SESSION_MODE_MODE_SIGNAL_IN_WAVEFORM)).session_ref();
  ///*
  std::vector<ReadSignalWaveformResponse> read_signal_waveform_response_vtr;
  for (int i = 0; i < 20; ++i) {
    read_signal_waveform_response_vtr.push_back(EXPECT_SUCCESS(client::read_signal_waveform(stub(), session, 1.0, NUM_SIGNALS * NUM_SAMP)));
  }
  //*/
  EXPECT_SUCCESS(client::clear(stub(), session));

  ///*
  EXPECT_EQ(0, read_signal_waveform_response_vtr[0].number_of_values_returned());
  EXPECT_EQ(999, read_signal_waveform_response_vtr[0].value_buffer_size());
  EXPECT_EQ(999, read_signal_waveform_response_vtr[0].value_buffer().size());
  EXPECT_EQ(0.0, read_signal_waveform_response_vtr[0].value_buffer(0));
  EXPECT_EQ(0.0, read_signal_waveform_response_vtr[0].delta_time());
  //*/
  ///*
  EXPECT_EQ(0 /* timestamp100ns */, read_signal_waveform_response_vtr[0].start_time());
  //*/
}

TEST_F(NiXnetCANDriverApiTests, SignalWaveformOutputFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_SAMP = 100;
  constexpr auto NUM_SIGNALS = 2;
  f64 increment_out = 0.0;
  f64 min_out = 0.0;
  f64 max_out = 40.0;
  std::vector<f64> value_vtr(NUM_SIGNALS * NUM_SAMP);
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "CAN_Cluster", "CANCyclicSignal3,CANCyclicSignal4", "CAN1", CREATE_SESSION_MODE_MODE_SIGNAL_OUT_WAVEFORM)).session_ref();
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

TEST_F(NiXnetCANDriverApiTests, SignalXYInputFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_SAMP = 100;
  constexpr auto NUM_SIGNALS = 2;
  unsigned int column = 1;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "CAN_Cluster", "CANCyclicSignal1,CANCyclicSignal2", "CAN2", CREATE_SESSION_MODE_MODE_SIGNAL_IN_XY)).session_ref();
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

TEST_F(NiXnetCANDriverApiTests, SignalXYOutputFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_SAMP = 50;
  constexpr auto NUM_SIGNALS = 1;
  f64 IncrementOut = 0.0;
  std::vector<u32> num_pairs_vtr(NUM_SIGNALS);
  f64 MinOut = 0.0;
  f64 MaxOut = 40.0;
  std::vector<f64> value_vtr(NUM_SAMP);
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "CAN_Cluster", "CANCyclicSignal2", "CAN1", CREATE_SESSION_MODE_MODE_SIGNAL_OUT_XY)).session_ref();
  num_pairs_vtr[0] = NUM_SAMP;
  IncrementOut = (MaxOut - MinOut) / NUM_SAMP;
  for (int i = 0; i < NUM_SAMP; ++i) {
    value_vtr[i] = MinOut + (IncrementOut * ((i + (NUM_SAMP / 2)) % NUM_SAMP));
  }
  for (int i = 0; i < 20; ++i) {
    EXPECT_SUCCESS(client::write_signal_xy(stub(), session, 10.0, value_vtr, std::vector<u64>(), num_pairs_vtr));
  }
  EXPECT_SUCCESS(client::clear(stub(), session));
}

/*
TEST_F(NiXnetCANDriverApiTests, SynchronizeWithDAQmxFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_SAMP = 100;
  constexpr auto NUM_SIGNAL = 2;
  f64 daq_value_buffer[NUM_SIGNAL][NUM_SAMP];
  char* daq_channel_string = "Dev1/ai0";
  u32 sample_rate = 1000;
  DAQmxErrChk(DAQmxCreateTask("DAQ Task", &m_DaqTask));
  DAQmxErrChk(DAQmxCreateAIVoltageChan(m_DaqTask, daq_channel_string, "", DAQmx_Val_Cfg_Default, -10.0, 10.0, DAQmx_Val_Volts, ""));
  DAQmxErrChk(DAQmxCfgSampClkTiming(m_DaqTask, "OnboardClock", sample_rate, DAQmx_Val_Rising, DAQmx_Val_ContSamps, NUM_SAMP));
  DAQmxErrChk(DAQmxExportSignal(m_DaqTask, DAQmx_Val_10MHzRefClock, "/Dev1/RTSI1"));
  DAQmxErrChk(DAQmxExportSignal(m_DaqTask, DAQmx_Val_StartTrigger, "/Dev1/RTSI0"));
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "CAN_Cluster", "CANCyclicSignal3,CANCyclicSignal4", "CAN2", CREATE_SESSION_MODE_MODE_SIGNAL_IN_WAVEFORM)).session_ref();
  EXPECT_SUCCESS(client::connect_terminals(stub(), session, "PXI_Trig0", "MasterTimebase"));
  EXPECT_SUCCESS(client::connect_terminals(stub(), session, "PXI_Trig1", "StartTrigger"));
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

TEST_F(NiXnetCANDriverApiTests, J1939FrameInputQueuedFromExample_FetchData_DataLooksReasonable)
{
  unsigned int j = 0;
  unsigned int num_of_frames_received = 0;
  u32 num_bytes_per_frame = 0;
  nixnet_grpc::Frame* frame = NULL;
  u16 payload_length = 0;
  u32 num_bytes = 0;
  std::vector<nixnet_grpc::FrameBuffer> frames;
  u64 node_name = 1;
  u32 in_address = 1;
  u32 out_address = 0;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "J1939_Over_CAN", "J1939_Transport_BAM", "CAN2", CREATE_SESSION_MODE_MODE_FRAME_IN_QUEUED)).session_ref();
  claim_by_address(session, node_name, in_address, &out_address);
  /* TODO
  std::vector<ReadFrameResponse> read_frame_response_vtr;
  for (int i = 0; i < 20; ++i) {
    read_frame_response_vtr.push_back(EXPECT_SUCCESS(client::read_frame(stub(), session, 10000, TIME_OUT_TIMEOUT_NONE, FRAME_TYPE_J1939)));
  }
  */
  EXPECT_SUCCESS(client::clear(stub(), session));

  /*
  EXPECT_EQ(999, read_frame_response_vtr[0].buffer_size());
  EXPECT_EQ(999, read_frame_response_vtr[0].buffer().size());
  //EXPECT_EQ(FrameBuffer(), read_frame_response_vtr[0].buffer(0));
  */
}

TEST_F(NiXnetCANDriverApiTests, J1939FrameOutputQueuedFromExample_FetchData_DataLooksReasonable)
{
  nixnet_grpc::Frame* frame = NULL;
  std::vector<nixnet_grpc::FrameBuffer> frames;
  u64 node_name = 2;
  u32 in_address = 2;
  u32 out_address = 0;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "J1939_Over_CAN", "J1939_Transport_BAM", "CAN1", CREATE_SESSION_MODE_MODE_FRAME_OUT_QUEUED)).session_ref();
  claim_by_address(session, node_name, in_address, &out_address);
  frame = new nixnet_grpc::Frame();
  frame->set_type(FRAME_TYPE_J1939);
  frame->set_payload("\0\1\2\3\4\5\6\7\x8\x9\xA\xB\xD\xD\xE\xF");
  frames.push_back(nixnet_grpc::FrameBuffer());
  frames.back().set_allocated_j1939(frame);
  for (int i = 0; i < 20; ++i) {
    /* TODO
    EXPECT_SUCCESS(client::write_frame(stub(), session, frames, 10.0));
    */
  }
  EXPECT_SUCCESS(client::clear(stub(), session));
}

TEST_F(NiXnetCANDriverApiTests, J1939FrameStreamInputFromExample_FetchData_DataLooksReasonable)
{
  unsigned int j = 0;
  u32 num_bytes_per_frame = 0;
  nixnet_grpc::Frame* frame = NULL;
  u16 payload_length = 0;
  u32 num_bytes = 0;
  std::vector<nixnet_grpc::FrameBuffer> frames;
  u64 node_name = 3;
  u32 in_address = 3;
  u32 out_address = 0;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), ":can_j1939:", "", "", "CAN2", CREATE_SESSION_MODE_MODE_FRAME_IN_STREAM)).session_ref();
  EXPECT_SUCCESS(set_property(stub(), session, PROPERTY_SESSION_INTF_BAUD_RATE_64, (u64)250000));
  claim_by_address(session, node_name, in_address, &out_address);
  /* TODO
  std::vector<ReadFrameResponse> read_frame_response_vtr;
  for (int i = 0; i < 20; ++i) {
    read_frame_response_vtr.push_back(EXPECT_SUCCESS(client::read_frame(stub(), session, 10000, TIME_OUT_TIMEOUT_NONE, FRAME_TYPE_J1939)));
  }
  */
  EXPECT_SUCCESS(client::clear(stub(), session));

  /*
  EXPECT_EQ(999, read_frame_response_vtr[0].buffer_size());
  EXPECT_EQ(999, read_frame_response_vtr[0].buffer().size());
  //EXPECT_EQ(FrameBuffer(), read_frame_response_vtr[0].buffer(0));
  */
}

TEST_F(NiXnetCANDriverApiTests, J1939FrameStreamOutputFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto PAYLOAD_SIZE_1 = 256;
  nixnet_grpc::Frame* frame = NULL;
  std::vector<nixnet_grpc::FrameBuffer> frames;
  u64 node_name = 4;
  u32 in_address = 4;
  u32 out_address = 0;
  char payload[PAYLOAD_SIZE_1 + 1];
  auto session = EXPECT_SUCCESS(client::create_session(stub(), ":can_j1939:", "", "", "CAN1", CREATE_SESSION_MODE_MODE_FRAME_OUT_STREAM)).session_ref();
  EXPECT_SUCCESS(set_property(stub(), session, PROPERTY_SESSION_INTF_BAUD_RATE_64, (u64)250000));
  claim_by_address(session, node_name, in_address, &out_address);
  frame = new nixnet_grpc::Frame();
  frame->set_timestamp(0);
  frame->set_flags(0);
  frame->set_type(FRAME_TYPE_J1939);
  frame->set_identifier(0x18FAFF00);
  for (int i = 0; i < PAYLOAD_SIZE_1; ++i) {
    payload[i] = (u8)i;
  }
  payload[PAYLOAD_SIZE_1] = '\0';
  frame->set_payload(payload);
  frames.push_back(nixnet_grpc::FrameBuffer());
  frames.back().set_allocated_j1939(frame);
  for (int i = 0; i < 20; ++i) {
    /* TODO
    EXPECT_SUCCESS(client::write_frame(stub(), session, frames, 10.0));
    */
    Sleep(3000);
  }
  EXPECT_SUCCESS(client::clear(stub(), session));
}

TEST_F(NiXnetCANDriverApiTests, J1939SignalSinglePointInputFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_SIGNALS = 2;
  u64 node_name = 5;
  u32 in_address = 5;
  u32 out_address = 0;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "J1939_Over_CAN", "J1939_LargeSignal1,J1939_LargeSignal2", "CAN2", CREATE_SESSION_MODE_MODE_SIGNAL_IN_SINGLE_POINT)).session_ref();
  claim_by_address(session, node_name, in_address, &out_address);
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

TEST_F(NiXnetCANDriverApiTests, J1939SignalSinglePointOutputFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUM_SIGNALS = 2;
  std::vector<f64> value_vtr(NUM_SIGNALS);
  u64 node_name = 6;
  u32 in_address = 6;
  u32 out_address = 0;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), "NIXNET_example", "J1939_Over_CAN", "J1939_LargeSignal1,J1939_LargeSignal2", "CAN1", CREATE_SESSION_MODE_MODE_SIGNAL_OUT_SINGLE_POINT)).session_ref();
  claim_by_address(session, node_name, in_address, &out_address);
  for (int i = 0; i < 20; ++i) {
    value_vtr[0] = (f64)(i % 10);
    value_vtr[1] = (f64)((i % 10) * 10);
    EXPECT_SUCCESS(client::write_signal_single_point(stub(), session, value_vtr));
  }
  EXPECT_SUCCESS(client::clear(stub(), session));
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
