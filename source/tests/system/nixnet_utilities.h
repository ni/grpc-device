#ifndef NIXNET_UTILITIES_H
#define NIXNET_UTILITIES_H

#include <gtest/gtest.h>
#undef interface
#include <custom/nixnet_converters.h>
#include <nixnet.h>
#include <nixnet/nixnet_client.h>

#include <string>
#include <vector>

#define EXPECT_SUCCESS(response_)    \
  ([](const auto& response) {        \
    EXPECT_EQ(0, response.status()); \
    return response;                 \
  })(response_)

#define EXPECT_XNET_ERROR(error, response) \
  if (1) {                                 \
    EXPECT_EQ(error, (response).status()); \
  }

#define FCS_SIZE 4

using namespace nixnet_grpc;
namespace client = nixnet_grpc::experimental::client;

static const u8 kEnetFrameOffsetEtherType = 12;
static const u8 kEnetFrameOffsetVlanEtherType = 16;
static const u8 kEnetFrameOffsetVlanTag = 12;
static const u8 kEnetFrameOffsetDstMacAddr = 0;
static const u8 kEnetFrameOffsetSrcMacAddr = 6;
static const u8 kPcp = 3;
static const u32 kEnetFrameHeaderSize = 14;
static const u32 kEnetFrameVlanTaggedHeaderSize = 18;
static const u32 kEnetMacAddrSize = 6;
static const u32 kFcsSize = FCS_SIZE;
static const u16 kVlanId = 2;

using u8 = ::google::protobuf::uint8;
using u16 = ::google::protobuf::uint16;
using u32 = ::google::protobuf::uint32;

namespace nixnet_utilities {

inline GetPropertyResponse get_property(const client::StubPtr& stub, const nidevice_grpc::Session& session_ref, const client::simple_variant<nixnet_grpc::Property, ::google::protobuf::uint32>& property_id)
{
  ::grpc::ClientContext context;

  auto request = GetPropertyRequest{};
  request.mutable_session()->CopyFrom(session_ref);
  const auto property_id_ptr = property_id.get_if<nixnet_grpc::Property>();
  const auto property_id_raw_ptr = property_id.get_if<::google::protobuf::uint32>();
  if (property_id_ptr) {
    request.set_property_id(*property_id_ptr);
  }
  else if (property_id_raw_ptr) {
    request.set_property_id_raw(*property_id_raw_ptr);
  }

  auto response = GetPropertyResponse{};

  client::raise_if_error(
      stub->GetProperty(&context, request, &response),
      context);

  return response;
}

inline void _set_property_value(SetPropertyRequest& request, const ::google::protobuf::uint32& value)
{
  request.set_u32_scalar(value);
}

inline void _set_property_value(SetPropertyRequest& request, const bool& value)
{
  request.set_bool_scalar(value);
}

inline void _set_property_value(SetPropertyRequest& request, const std::string& value)
{
  request.set_str(value);
}

inline void _set_property_value(SetPropertyRequest& request, const ::google::protobuf::uint64& value)
{
  request.set_u64_scalar(value);
}

inline void _set_property_value(SetPropertyRequest& request, const ::google::protobuf::int32& value)
{
  request.set_i32_scalar(value);
}

inline void _set_property_value(SetPropertyRequest& request, const double& value)
{
  request.set_f64_scalar(value);
}

inline void _set_property_value(SetPropertyRequest& request, const std::vector<::google::protobuf::uint32>& value)
{
  request.mutable_u32_array()->clear_u32_array();
  request.mutable_u32_array()->mutable_u32_array()->Add(value.begin(), value.end());
}

inline void _set_property_value(SetPropertyRequest& request, const nidevice_grpc::Session& value)
{
  request.mutable_db_ref()->CopyFrom(value);
}

inline void _set_property_value(SetPropertyRequest& request, const std::vector<nidevice_grpc::Session>& value)
{
  request.mutable_db_ref_array()->clear_db_ref();
  request.mutable_db_ref_array()->mutable_db_ref()->Reserve(static_cast<int>(value.size()));
  for (int i = 0; i < value.size(); ++i) {
    request.mutable_db_ref_array()->mutable_db_ref()->at(i) = value[i];
  }
}

inline void _set_property_value(SetPropertyRequest& request, const std::vector<EptRxFilter>& value)
{
  request.mutable_ept_rx_filter_array()->clear_ept_rx_filter();
  request.mutable_ept_rx_filter_array()->mutable_ept_rx_filter()->Reserve(static_cast<int>(value.size()));
  for (int i = 0; i < value.size(); ++i) {
    request.mutable_ept_rx_filter_array()->mutable_ept_rx_filter()->at(i) = value[i];
  }
}

template <typename T>
inline SetPropertyResponse set_property(
    const client::StubPtr& stub,
    const nidevice_grpc::Session& session,
    const client::simple_variant<nixnet_grpc::Property, ::google::protobuf::uint32>& property_id,
    const T& value)
{
  ::grpc::ClientContext context;

  auto request = SetPropertyRequest{};
  request.mutable_session()->CopyFrom(session);
  const auto property_id_ptr = property_id.get_if<nixnet_grpc::Property>();
  const auto property_id_raw_ptr = property_id.get_if<::google::protobuf::uint32>();
  if (property_id_ptr) {
    request.set_property_id(*property_id_ptr);
  }
  else if (property_id_raw_ptr) {
    request.set_property_id_raw(*property_id_raw_ptr);
  }
  _set_property_value(request, value);

  auto response = SetPropertyResponse{};

  client::raise_if_error(
      stub->SetProperty(&context, request, &response),
      context);

  return response;
}

inline DbGetPropertyResponse db_get_property(const client::StubPtr& stub, const nidevice_grpc::Session& dbobject_ref, const client::simple_variant<nixnet_grpc::DBProperty, ::google::protobuf::uint32>& property_id)
{
  ::grpc::ClientContext context;

  auto request = DbGetPropertyRequest{};
  request.mutable_dbobject()->CopyFrom(dbobject_ref);
  const auto property_id_ptr = property_id.get_if<nixnet_grpc::DBProperty>();
  const auto property_id_raw_ptr = property_id.get_if<::google::protobuf::uint32>();
  if (property_id_ptr) {
    request.set_property_id(*property_id_ptr);
  }
  else if (property_id_raw_ptr) {
    request.set_property_id_raw(*property_id_raw_ptr);
  }

  auto response = DbGetPropertyResponse{};

  client::raise_if_error(
      stub->DbGetProperty(&context, request, &response),
      context);

  return response;
}

inline std::vector<u32> get_property_u32_vtr(const client::StubPtr& stub, const nidevice_grpc::Session& session_ref, const client::simple_variant<nixnet_grpc::Property, ::google::protobuf::uint32>& property_id)
{
  auto array = EXPECT_SUCCESS(get_property(stub, session_ref, property_id)).u32_array().u32_array();
  return std::vector<u32>(array.begin(), array.end());
}

inline std::vector<nidevice_grpc::Session> get_property_db_ref_vtr(const client::StubPtr& stub, const nidevice_grpc::Session& session_ref, const client::simple_variant<nixnet_grpc::Property, ::google::protobuf::uint32>& property_id)
{
  auto array = EXPECT_SUCCESS(get_property(stub, session_ref, property_id)).db_ref_array().db_ref();
  return std::vector<nidevice_grpc::Session>(array.begin(), array.end());
}

inline std::vector<u32> db_get_property_u32_vtr(const client::StubPtr& stub, const nidevice_grpc::Session& database_ref, const client::simple_variant<nixnet_grpc::DBProperty, ::google::protobuf::uint32>& property_id)
{
  auto array = EXPECT_SUCCESS(db_get_property(stub, database_ref, property_id)).u32_array().u32_array();
  return std::vector<u32>(array.begin(), array.end());
}

inline std::vector<nidevice_grpc::Session> db_get_property_db_ref_vtr(const client::StubPtr& stub, const nidevice_grpc::Session& database_ref, const client::simple_variant<nixnet_grpc::DBProperty, ::google::protobuf::uint32>& property_id)
{
  auto array = EXPECT_SUCCESS(db_get_property(stub, database_ref, property_id)).db_ref_array().db_ref();
  return std::vector<nidevice_grpc::Session>(array.begin(), array.end());
}

inline int calculate_bitwise_or_of_flags(::google::protobuf::RepeatedField<::google::protobuf::int32> flags)
{
  int bitwise_or_of_flags = 0;
  for (int i = 0; i < flags.size(); i++) {
    bitwise_or_of_flags = bitwise_or_of_flags | flags[i];
  }
  return bitwise_or_of_flags;
}

struct EthernetHeader {
  u8 DestinationMacAddress[6];
  u8 SourceMacAddress[6];
  u16 EtherType;
};

inline u16 ChangeByteOrderU16(u16 value)
{
  return BigToHostOrder16(value);
}

inline u32 ChangeByteOrderU32(u32 value)
{
  return (value & 0x000000FF) << 24 |
      (value & 0x0000FF00) << 8 |
      (value & 0x00FF0000) >> 8 |
      (value & 0xFF000000) >> 24;
}

inline void AssignVlanId(u32* pVlan, u16 vlanId)
{
  u16 vidMask = 0x0FFF;
  *pVlan = ((*pVlan) & ~(vidMask));
  *pVlan = ((*pVlan) | (vlanId & vidMask));
}

inline void AssignPriorityCodePoint(u32* pVlan, u8 pcp)
{
  u16 pcpMask = 0xE000;
  u8 pcpLsb = 13;
  *pVlan = ((*pVlan) & ~(pcpMask));
  *pVlan = ((*pVlan) | (((u16)pcp << pcpLsb) & pcpMask));
}

inline u32 GenerateVlanTag(u16 vlanId)
{
  u32 vlanTag = 0x81000000;
  AssignVlanId(&vlanTag, vlanId);
  AssignPriorityCodePoint(&vlanTag, kPcp);
  return vlanTag;
}

inline void EncodeEnetFrameHeader(u8* FrameData, bool hasVlan, u16 vlanId)
{
  struct EthernetHeader EnetHead =
      {
          {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
          {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
          0x88B5 /* Local Experimental Ethertype */
      };

  u16 ethertypeBigEndian = ChangeByteOrderU16(EnetHead.EtherType);
  u32 vlanTagBigEndian = ChangeByteOrderU32(GenerateVlanTag(vlanId));

  memcpy(FrameData + kEnetFrameOffsetDstMacAddr, &EnetHead.DestinationMacAddress, kEnetMacAddrSize);
  memcpy(FrameData + kEnetFrameOffsetSrcMacAddr, &EnetHead.SourceMacAddress, kEnetMacAddrSize);

  if (hasVlan) {
    memcpy(FrameData + kEnetFrameOffsetVlanTag, &vlanTagBigEndian, sizeof(vlanTagBigEndian));
    memcpy(FrameData + kEnetFrameOffsetVlanEtherType, &ethertypeBigEndian, sizeof(EnetHead.EtherType));
  }
  else {
    memcpy(FrameData + kEnetFrameOffsetEtherType, &ethertypeBigEndian, sizeof(EnetHead.EtherType));
  }
}

inline void EncodeEnetFrame(nxFrameEnet_t* pFrame, u16 payloadSize, bool hasVlan, u16 vlanId)
{
  u16 frameSize = 0;
  u32 payloadOffset = 0;

  EncodeEnetFrameHeader(pFrame->FrameData, hasVlan, vlanId);
  pFrame->DeviceTimestamp = 0;
  pFrame->NetworkTimestamp = 0;
  pFrame->Flags = nxEnetFlags_Transmit;
  pFrame->Type = nxEnetFrameType_Data;

  if (hasVlan) {
    payloadOffset = kEnetFrameVlanTaggedHeaderSize;
  }
  else {
    payloadOffset = kEnetFrameHeaderSize;
  }

  frameSize = (u16)(nixnet_grpc::ENET_FRAME_HEADER_LENGTH + payloadOffset + payloadSize + kFcsSize);
  pFrame->Length = frameSize;

  for (u16 i = 0; i < payloadSize; i++) {
    pFrame->FrameData[payloadOffset + i] = (u8)i;
  }
}

}  // namespace nixnet_utilities

#endif  // NIXNET_UTILITIES_H