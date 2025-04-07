#include <gmock/gmock.h>
#include <google/protobuf/util/time_util.h>
#include <gtest/gtest.h>
#include <nixnet/nixnet_client.h>

#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "device_server.h"
#include "enumerate_devices.h"
#include "nixnet.h"
#include "nixnet_utilities.h"

using namespace nixnet_grpc;
namespace client = nixnet_grpc::experimental::client;
using namespace ::testing;
using namespace ::nixnet_utilities;
using nlohmann::json;

namespace ni {
namespace tests {
namespace system {
namespace {

using u8 = ::google::protobuf::uint8;
using u16 = ::google::protobuf::uint16;
using u32 = ::google::protobuf::uint32;
using u64 = ::google::protobuf::uint64;

class NiXnetEthernetDriverApiTestsWithHardware : public ::testing::Test {
 protected:
  NiXnetEthernetDriverApiTestsWithHardware()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiXnet::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }
  virtual ~NiXnetEthernetDriverApiTestsWithHardware() {}
  void SetUp() override
  {
    const auto discovered_devices = EnumerateDevices();
    const auto required_interfaces = {"ENET1,ENET2,ENET3,ENET4"};

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

void set_enet_frame_data(nixnet_grpc::EnetFrameRequest* frame, nixnet_grpc::EnetFrameType frame_type, u64 device_timestamp, u64 network_timestamp, nixnet_grpc::EnetFlags frame_flags)
{
  u16 payloadSize = 150;
  u32 payloadOffset = kEnetFrameVlanTaggedHeaderSize;
  frame->mutable_frame_data()->resize(payloadSize, 0);
  char* frame_data = const_cast<char*>(frame->mutable_frame_data()->data());
  EncodeEnetFrameHeader((u8*)frame_data, true, kVlanId);
  // The payload is constructed with incrementing values
  for (int i = payloadOffset; i < payloadSize; i++) {
    frame_data[i] = (u8)i;
  }

  frame->set_type(frame_type);
  frame->set_device_timestamp(device_timestamp);
  frame->set_network_timestamp(network_timestamp);
  frame->add_flags_mapped(frame_flags);
}

TEST_F(NiXnetEthernetDriverApiTestsWithHardware, WriteFrameData_ReadFrameData_ValidateFrameData)
{
  constexpr auto NUM_OF_FRAMES = 1;
  constexpr auto MAX_PAYLOAD_PER_FRAME = 150;
  std::vector<nixnet_grpc::FrameBufferRequest> frames_in;
  nixnet_grpc::EnetFlags flags[] = {EnetFlags::ENET_FLAGS_TRANSMIT};
  nixnet_grpc::EnetFrameRequest* frame = new nixnet_grpc::EnetFrameRequest();
  auto write_session = EXPECT_SUCCESS(client::create_session(stub(), "", "", "", "ENET1", CREATE_SESSION_MODE_FRAME_OUT_STREAM)).session();
  auto read_session = EXPECT_SUCCESS(client::create_session(stub(), "", "", "", "ENET2", CREATE_SESSION_MODE_FRAME_IN_STREAM)).session();
  EXPECT_SUCCESS(client::start(stub(), read_session, START_STOP_SCOPE_NORMAL));
  set_enet_frame_data(frame, EnetFrameType::ENET_FRAME_TYPE_DATA, 0, 0, flags[0]);
  frames_in.push_back(nixnet_grpc::FrameBufferRequest());
  frames_in.back().set_allocated_enet(frame);
  auto write_frame_response = EXPECT_SUCCESS(client::write_frame(stub(), write_session, frames_in, TIME_OUT_NONE));

  auto read_frame_response = EXPECT_SUCCESS(client::read_frame(stub(), read_session, NUM_OF_FRAMES, MAX_PAYLOAD_PER_FRAME, PROTOCOL_ENET, TIME_OUT_INFINITE));
  auto frame_out = read_frame_response.buffer()[0];
  // The frame that is read will contain mac address of the source on which the test is being run. For comparison purposes, we will be masking it.
  for (int i = 6; i < 12; i++) {
    const_cast<char*>(frame_out.mutable_enet()->mutable_frame_data()->data())[i] = 0xFFU;
  }

  EXPECT_EQ(frame->type(), frame_out.enet().type());
  EXPECT_EQ(frame->frame_data(), frame_out.enet().frame_data());
  EXPECT_SUCCESS(client::clear(stub(), write_session));
  EXPECT_SUCCESS(client::clear(stub(), read_session));
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni