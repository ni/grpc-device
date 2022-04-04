#include <gtest/gtest.h>
#undef interface
#include <nixnet/nixnet_client.h>

#include <string>
#include <vector>

#define EXPECT_SUCCESS(response_)    \
  ([](const auto& response) {              \
    EXPECT_EQ(0, response.status()); \
    return response;                 \
  })(response_)

#define EXPECT_XNET_ERROR(error, response) \
  if (1) {                                 \
    EXPECT_EQ(error, (response).status()); \
  }

namespace nixnet_utilities {
  
namespace client = nixnet_grpc::experimental::client;
namespace pb = google::protobuf;
using namespace nixnet_grpc;

typedef pb::uint32 u32;

GetPropertyResponse get_property(const client::StubPtr& stub, const nidevice_grpc::Session& session_ref, const client::simple_variant<nixnet_grpc::Property, pb::uint32>& property_id)
{
  ::grpc::ClientContext context;

  auto request = GetPropertyRequest{};
  request.mutable_session()->CopyFrom(session_ref);
  const auto property_id_ptr = property_id.get_if<nixnet_grpc::Property>();
  const auto property_id_raw_ptr = property_id.get_if<pb::uint32>();
  if (property_id_ptr) {
    request.set_property_id(*property_id_ptr);
  }
  else if (property_id_raw_ptr) {
    request.set_property_id_raw(*property_id_raw_ptr);
  }

  auto response = GetPropertyResponse{};

  client::raise_if_error(
      stub->GetProperty(&context, request, &response));

  return response;
}

inline void _set_property_value(SetPropertyRequest& request, const pb::uint32& value)
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

inline void _set_property_value(SetPropertyRequest& request, const pb::uint64& value)
{
  request.set_u64_scalar(value);
}

inline void _set_property_value(SetPropertyRequest& request, const pb::int32& value)
{
  request.set_i32_scalar(value);
}

inline void _set_property_value(SetPropertyRequest& request, const double& value)
{
  request.set_f64_scalar(value);
}

inline void _set_property_value(SetPropertyRequest& request, const std::vector<std::string>& value)
{
  // TODO: set_string_array expects a single string?!?
  request.set_string_array(value[0]);
}

inline void _set_property_value(SetPropertyRequest& request, const std::vector<pb::uint32>& value)
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
SetPropertyResponse set_property(
    const client::StubPtr& stub,
    const nidevice_grpc::Session& session,
    const client::simple_variant<nixnet_grpc::Property, pb::uint32>& property_id,
    const T& value)
{
  ::grpc::ClientContext context;

  auto request = SetPropertyRequest{};
  request.mutable_session()->CopyFrom(session);
  const auto property_id_ptr = property_id.get_if<nixnet_grpc::Property>();
  const auto property_id_raw_ptr = property_id.get_if<pb::uint32>();
  if (property_id_ptr) {
    request.set_property_id(*property_id_ptr);
  }
  else if (property_id_raw_ptr) {
    request.set_property_id_raw(*property_id_raw_ptr);
  }
  _set_property_value(request, value);

  auto response = SetPropertyResponse{};

  client::raise_if_error(
      stub->SetProperty(&context, request, &response));

  return response;
}

DbGetPropertyResponse db_get_property(const client::StubPtr& stub, const nidevice_grpc::Session& dbobject_ref, const client::simple_variant<nixnet_grpc::DBProperty, pb::uint32>& property_id)
{
  ::grpc::ClientContext context;

  auto request = DbGetPropertyRequest{};
  request.mutable_dbobject()->CopyFrom(dbobject_ref);
  const auto property_id_ptr = property_id.get_if<nixnet_grpc::DBProperty>();
  const auto property_id_raw_ptr = property_id.get_if<pb::uint32>();
  if (property_id_ptr) {
    request.set_property_id(*property_id_ptr);
  }
  else if (property_id_raw_ptr) {
    request.set_property_id_raw(*property_id_raw_ptr);
  }

  auto response = DbGetPropertyResponse{};

  client::raise_if_error(
      stub->DbGetProperty(&context, request, &response));

  return response;
}

std::vector<u32> get_property_u32_vtr(const client::StubPtr& stub, const nidevice_grpc::Session& session_ref, const client::simple_variant<nixnet_grpc::Property, pb::uint32>& property_id)
{
  auto array = EXPECT_SUCCESS(get_property(stub, session_ref, property_id)).u32_array().u32_array();
  return std::vector<u32>(array.begin(), array.end());
}

std::vector<nidevice_grpc::Session> get_property_db_ref_vtr(const client::StubPtr& stub, const nidevice_grpc::Session& session_ref, const client::simple_variant<nixnet_grpc::Property, pb::uint32>& property_id)
{
  auto array = EXPECT_SUCCESS(get_property(stub, session_ref, property_id)).db_ref_array().db_ref();
  return std::vector<nidevice_grpc::Session>(array.begin(), array.end());
}

std::vector<u32> db_get_property_u32_vtr(const client::StubPtr& stub, const nidevice_grpc::Session& database_ref, const client::simple_variant<nixnet_grpc::DBProperty, pb::uint32>& property_id)
{
  auto array = EXPECT_SUCCESS(db_get_property(stub, database_ref, property_id)).u32_array().u32_array();
  return std::vector<u32>(array.begin(), array.end());
}

std::vector<nidevice_grpc::Session> db_get_property_db_ref_vtr(const client::StubPtr& stub, const nidevice_grpc::Session& database_ref, const client::simple_variant<nixnet_grpc::DBProperty, pb::uint32>& property_id)
{
  auto array = EXPECT_SUCCESS(db_get_property(stub, database_ref, property_id)).db_ref_array().db_ref();
  return std::vector<nidevice_grpc::Session>(array.begin(), array.end());
}

int calculate_bitwise_or_of_flags(google::protobuf::RepeatedField<google::protobuf::int32> flags)
{
  int bitwise_or_of_flags = 0;
  for(int i = 0; i < flags.size(); i++)
  {
    bitwise_or_of_flags = bitwise_or_of_flags | flags[i];
  }
  return bitwise_or_of_flags;
}

}  // namespace nixnet_utilities