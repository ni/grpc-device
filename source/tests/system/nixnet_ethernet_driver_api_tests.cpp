#include <gmock/gmock.h>
#include <google/protobuf/util/time_util.h>
#include <gtest/gtest.h>
#undef interface
#include <nixnet.h>
#include <nixnet/nixnet_client.h>

#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "device_server.h"
#include "enumerate_devices.h"

using namespace nixnet_grpc;
namespace client = nixnet_grpc::experimental::client;
namespace pb = google::protobuf;
using namespace ::testing;
using nlohmann::json;

namespace ni {
namespace tests {
namespace system {
namespace {

typedef pb::uint8 u8;
typedef pb::uint16 u16;
typedef pb::uint32 u32;
typedef pb::uint64 u64;

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

class NiXnetEthernetDriverApiTests : public ::testing::Test {
 protected:
  NiXnetEthernetDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiXnet::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }
  virtual ~NiXnetEthernetDriverApiTests() {}

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

#define EXPECT_SUCCESS(response_)    \
  ([this](auto& response) {          \
    EXPECT_EQ(0, response.status()); \
    return response;                 \
  })(response_)

#define EXPECT_XNET_ERROR(error, response) \
  if (1) {                                 \
    EXPECT_EQ(error, (response).status()); \
  }

TEST_F(NiXnetEthernetDriverApiTests, FrameStreamInputLoggerFromExample_FetchData_DataLooksReasonable)
{
  constexpr u16 VLAN_ID = 2;
  constexpr u32 ENABLE_VID_AND_PRIORITY = 3;
  constexpr u8 PCP = 3;
  char log_path[] = "C:\\Users\\Public\\Documents\\log.pcap";
  nxEptRxFilter_Element_t rx_filter;
  nxMACAddress_t mac = "AA:BB:CC:DD:EE:FF";
  auto session = EXPECT_SUCCESS(client::create_session(stub(), NULL, NULL, NULL, "ENET4", CREATE_SESSION_MODE_MODE_FRAME_IN_STREAM)).session_ref();
  rx_filter.UseFlags = ENABLE_VID_AND_PRIORITY;
  rx_filter.VID = VLAN_ID;
  rx_filter.Priority = PCP;
  memcpy(rx_filter.DestinationMAC, mac, sizeof(nxMACAddress_t));
  //EXPECT_SUCCESS(client::set_property(stub(), session, PROPERTY_SESSION_INTF_ENET_EPT_RECEIVE_FILTER, sizeof(nxEptRxFilter_Element_t), &rx_filter));
  //EXPECT_SUCCESS(client::set_property(stub(), session, PROPERTY_SESSION_ENET_LOG_MODE, sizeof(u32), &nxEnetLogMode_Log));
  //EXPECT_SUCCESS(client::set_property(stub(), session, PROPERTY_SESSION_ENET_LOG_OPERATION, sizeof(u32), &nxEnetLogOperation_CreateOrReplace));
  //EXPECT_SUCCESS(client::set_property(stub(), session, PROPERTY_SESSION_ENET_LOG_FILE, sizeof(log_path), &log_path));
  EXPECT_SUCCESS(client::start(stub(), session, 0));
  //auto get_property_response = EXPECT_SUCCESS(client::get_property(stub(), session, PROPERTY_SESSION_ENET_NUM_FRAMES_RECEIVED, sizeof(u64)));
  EXPECT_SUCCESS(client::clear(stub(), session));

  //EXPECT_EQ(0 /* void[] */, get_property_response.property_value());
}

TEST_F(NiXnetEthernetDriverApiTests, FrameStreamInputReaderFromExample_FetchData_DataLooksReasonable)
{
  constexpr u16 VLAN_ID = 2;
  constexpr u32 ENABLE_VID_AND_PRIORITY = 3;
  constexpr u8 PCP = 3;
  nxEptRxFilter_Element_t rx_filter;
  nxMACAddress_t mac = "AA:BB:CC:DD:EE:FF";
  auto session = EXPECT_SUCCESS(client::create_session(stub(), NULL, NULL, NULL, "ENET4", CREATE_SESSION_MODE_MODE_FRAME_IN_STREAM)).session_ref();
  rx_filter.UseFlags = ENABLE_VID_AND_PRIORITY;
  rx_filter.VID = VLAN_ID;
  rx_filter.Priority = PCP;
  memcpy(rx_filter.DestinationMAC, mac, sizeof(nxMACAddress_t));
  //EXPECT_SUCCESS(client::set_property(stub(), session, PROPERTY_SESSION_INTF_ENET_EPT_RECEIVE_FILTER, sizeof(nxEptRxFilter_Element_t), &rx_filter));
  //auto read_frame_response = EXPECT_SUCCESS(client::read_frame(stub(), session, 250, TIME_OUT_TIMEOUT_NONE));
  EXPECT_SUCCESS(client::clear(stub(), session));

  //EXPECT_EQ(0, read_frame_response.number_of_bytes_returned());
  //EXPECT_EQ(999, read_frame_response.buffer_size());
  //EXPECT_EQ(999, read_frame_response.buffer().size());
  //EXPECT_EQ(FrameBuffer(), read_frame_response.buffer(0));
}

TEST_F(NiXnetEthernetDriverApiTests, FrameStreamOutputFromExample_FetchData_DataLooksReasonable)
{
  constexpr u8 NUM_FRAMES = 2;
  constexpr u16 PAYLOAD_SIZE = 150;
  constexpr u16 VLAN_ID = 2;
  std::vector<FrameBuffer> frames(NUM_FRAMES);
  char payload[PAYLOAD_SIZE + 1] = {0};
  nixnet_grpc::EnetFrame* frame = NULL;
  auto session = EXPECT_SUCCESS(client::create_session(stub(), NULL, NULL, NULL, "ENET1", CREATE_SESSION_MODE_MODE_FRAME_OUT_STREAM)).session_ref();
  for (int i = 0; i < PAYLOAD_SIZE; ++i) {
    payload[i] = (char)i;
  }
  frame = new nixnet_grpc::EnetFrame();
  // TODO: set no vlan
  frame->set_device_timestamp(0);
  frame->set_network_timestamp(0);
  frame->set_flags(0);
  frame->set_type(nxEnetFrameType_Data);
  frame->set_frame_data(payload);
  frames.push_back(nixnet_grpc::FrameBuffer());
  frames.back().set_allocated_enet(frame);
  frame = new nixnet_grpc::EnetFrame();
  // TODO: set VLAN_ID
  frame->set_device_timestamp(0);
  frame->set_network_timestamp(0);
  frame->set_flags(0);
  frame->set_type(nxEnetFrameType_Data);
  frame->set_frame_data(payload);
  frames.push_back(nixnet_grpc::FrameBuffer());
  frames.back().set_allocated_enet(frame);
  //EXPECT_SUCCESS(client::write_frame(stub(), session, frames, 10.0));
  EXPECT_SUCCESS(client::clear(stub(), session));
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
