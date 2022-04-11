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
namespace pb = google::protobuf;
using namespace ::testing;
using namespace ::nixnet_utilities;
using nlohmann::json;

namespace ni {
namespace tests {
namespace system {
namespace {

using u8 = pb::uint8;
using u16 = pb::uint16;
using u32 = pb::uint32;
using u64 = pb::uint64;

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
    const auto required_interfaces = {"ENET1,ENET2"};

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

static const u8 kEnetFrameOffsetVlanEtherType = 16;
static const u8 kEnetFrameOffsetVlanTag = 12;
static const u8 kEnetFrameOffsetDstMacAddr = 0;
static const u8 kEnetFrameOffsetSrcMacAddr = 6;
static const u8 kPcp = 3;
static const u16 kVlanId = 2;
static const u32 kEnetFrameHeaderSize = 14;
static const u32 kEnetFrameVlanTaggedHeaderSize = 18;
static const u32 kEnetMacAddrSize = 6;
static const u32 kMaxEnetFrameSize = 1518;

struct EthernetHeader {
  u8 DestinationMacAddress[6];
  u8 SourceMacAddress[6];
  u16 EtherType;
} EthernetHeader;

// Performs endianness swapping on u16
u16 ChangeByteOrderU16(u16 value)
{
  return BigToHostOrder16(value);
}

// Performs endianness swapping on u32
u32 ChangeByteOrderU32(u32 value)
{
  return (value & 0x000000FF) << 24 |
      (value & 0x0000FF00) << 8 |
      (value & 0x00FF0000) >> 8 |
      (value & 0xFF000000) >> 24;
}

void AssignVlanId(u32* pVlan, u16 vlanId)
{
  u16 vidMask = 0x0FFF;
  *pVlan = ((*pVlan) & ~(vidMask));
  *pVlan = ((*pVlan) | (vlanId & vidMask));
}

void AssignPriorityCodePoint(u32* pVlan, u8 pcp)
{
  u16 pcpMask = 0xE000;
  u8 pcpLsb = 13;
  *pVlan = ((*pVlan) & ~(pcpMask));
  *pVlan = ((*pVlan) | (((u16)pcp << pcpLsb) & pcpMask));
}

u32 GenerateVlanTag(u16 vlanId)
{
  // Initialize vlan tag with the TPID
  u32 vlanTag = 0x81000000;
  AssignVlanId(&vlanTag, vlanId);
  AssignPriorityCodePoint(&vlanTag, kPcp);
  return vlanTag;
}
void EncodeEnetFrameHeader(char* frame_data, u16 vlanId)
{
  struct EthernetHeader EnetHead =
      {
          {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
          {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
          0x88B5 /* Local Experimental Ethertype */
      };
  // The FrameData field is big-endian, so fields that are wider than
  // a byte (i.e. EtherType and VLAN tag) must be converted.
  u16 ethertypeBigEndian = ChangeByteOrderU16(EnetHead.EtherType);
  u32 vlanTagBigEndian = ChangeByteOrderU32(GenerateVlanTag(vlanId));

  memcpy(frame_data + kEnetFrameOffsetDstMacAddr, &EnetHead.DestinationMacAddress, kEnetMacAddrSize);
  memcpy(frame_data + kEnetFrameOffsetSrcMacAddr, &EnetHead.SourceMacAddress, kEnetMacAddrSize);
  memcpy(frame_data + kEnetFrameOffsetVlanTag, &vlanTagBigEndian, sizeof(vlanTagBigEndian));
  memcpy(frame_data + kEnetFrameOffsetVlanEtherType, &ethertypeBigEndian, sizeof(EthernetHeader.EtherType));
}

void set_enet_frame_data(nixnet_grpc::EnetFrameRequest* frame, nixnet_grpc::EnetFrameType frame_type, u64 device_timestamp, u64 network_timestamp, nixnet_grpc::EnetFlags frame_flags)
{
  u16 payloadSize = 150;
  u32 payloadOffset = kEnetFrameVlanTaggedHeaderSize;
  frame->mutable_frame_data()->resize(payloadSize, 0);
  char* frame_data = const_cast<char*>(frame->mutable_frame_data()->data());
  EncodeEnetFrameHeader(frame_data, kVlanId);
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
  constexpr auto FRAME_CHECK_SEQUENCE_SIZE = 4;
  constexpr auto NUM_OF_FRAMES = 1;
  constexpr auto MAX_PAYLOAD_PER_FRAME = kMaxEnetFrameSize + FRAME_CHECK_SEQUENCE_SIZE;
  std::vector<nixnet_grpc::FrameBufferRequest> frames_in;
  nixnet_grpc::EnetFlags flags[] = {EnetFlags::ENET_FLAGS_TRANSMIT};
  nixnet_grpc::EnetFrameRequest* frame = new nixnet_grpc::EnetFrameRequest();

  auto write_session = EXPECT_SUCCESS(client::create_session(stub(), "", "", "", "ENET1", CREATE_SESSION_MODE_FRAME_OUT_STREAM)).session();
  auto read_session = EXPECT_SUCCESS(client::create_session(stub(), "", "", "", "ENET2", CREATE_SESSION_MODE_FRAME_IN_STREAM)).session();
  set_enet_frame_data(frame, EnetFrameType::ENET_FRAME_TYPE_DATA, 0, 0, flags[0]);
  frames_in.push_back(nixnet_grpc::FrameBufferRequest());
  frames_in.back().set_allocated_enet(frame);

  auto write_frame_response = EXPECT_SUCCESS(client::write_frame(stub(), write_session, frames_in, TIME_OUT_NONE));
  auto read_frame_response = EXPECT_SUCCESS(client::read_frame(stub(), read_session, NUM_OF_FRAMES, MAX_PAYLOAD_PER_FRAME, PROTOCOL_ENET, TIME_OUT_INFINITE));
  auto frame_out = read_frame_response.buffer()[0];
  // The frame that is read will contain mac address of the source on which the test is being run. For comparison purposes, we will be masking it.
  const_cast<char*>(frame_out.mutable_enet()->mutable_frame_data()->data())[5] = 0xFFFFFF;

  EXPECT_EQ(frame->type(), frame_out.enet().type());
  EXPECT_EQ(frame->frame_data(), frame_out.enet().frame_data());
  EXPECT_SUCCESS(client::clear(stub(), write_session));
  EXPECT_SUCCESS(client::clear(stub(), read_session));
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni