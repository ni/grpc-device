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

typedef pb::uint32 u32;

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

GetPropertyResponse get_property(const client::StubPtr& stub, const nidevice_grpc::Session& session_ref, const client::simple_variant<nixnet_grpc::Property, pb::uint32>& property_id)
{
  ::grpc::ClientContext context;

  auto request = GetPropertyRequest{};
  request.mutable_session_ref()->CopyFrom(session_ref);
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

DbGetPropertyResponse db_get_property(const client::StubPtr& stub, const nidevice_grpc::Session& dbobject_ref, const client::simple_variant<nixnet_grpc::DBProperty, pb::uint32>& property_id)
{
  ::grpc::ClientContext context;

  auto request = DbGetPropertyRequest{};
  request.mutable_dbobject_ref()->CopyFrom(dbobject_ref);
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

DbGetDatabaseListResponse db_get_database_list(const client::StubPtr& stub, const std::string& ip_address)
{
  ::grpc::ClientContext context;

  auto request = DbGetDatabaseListRequest{};
  request.set_ip_address(ip_address);

  auto response = DbGetDatabaseListResponse{};

  client::raise_if_error(
      stub->DbGetDatabaseList(&context, request, &response));

  return response;
}

class NiXnetCommonDriverApiTests : public ::testing::Test {
 protected:
  NiXnetCommonDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiXnet::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }
  virtual ~NiXnetCommonDriverApiTests() {}

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
  ([](auto& response) {              \
    EXPECT_EQ(0, response.status()); \
    return response;                 \
  })(response_)

#define EXPECT_XNET_ERROR(error, response) \
  if (1) {                                 \
    EXPECT_EQ(error, (response).status()); \
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

TEST_F(NiXnetCommonDriverApiTests, XNETDatabaseBrowserFromExample_FetchData_DataLooksReasonable)
{
  auto session = EXPECT_SUCCESS(client::system_open(stub())).system_ref();
  auto interface_refs = get_property_db_ref_vtr(stub(), session, PROPERTY_SYS_INTF_REFS);
  std::vector<std::string> interface_name_vtr;
  for (auto interface_ref : interface_refs) {
    interface_name_vtr.push_back(EXPECT_SUCCESS(get_property(stub(), interface_ref, PROPERTY_INTF_NAME)).str());
  }
  EXPECT_SUCCESS(client::system_close(stub(), session));
  auto db_get_database_list_response = EXPECT_SUCCESS(db_get_database_list(stub(), ""));
  auto aliases_comma_separated = std::stringstream(db_get_database_list_response.alias_buffer());
  std::vector<std::string> alias_vtr;
  while (aliases_comma_separated.good()) {
    std::string alias;
    std::getline(aliases_comma_separated, alias, ',');
    alias_vtr.push_back(alias);
  }
  std::vector<std::string> file_path_vtr;
  auto file_paths_comma_separated = std::stringstream(db_get_database_list_response.file_path_buffer());
  while (file_paths_comma_separated.good()) {
    std::string file_path;
    std::getline(file_paths_comma_separated, file_path, ',');
    file_path_vtr.push_back(file_path);
  }
  std::vector<std::string> cluster_name_vtr;
  std::vector<std::string> frame_name_vtr;
  std::vector<std::string> signal_name_vtr;
  std::vector<std::string> lin_schedule_name_vtr;
  for (auto alias : alias_vtr) {
    auto database_ref = EXPECT_SUCCESS(client::db_open_database(stub(), alias)).database_ref();
    auto cluster_refs = db_get_property_db_ref_vtr(stub(), database_ref, DB_PROPERTY_DATABASE_CLST_REFS);
    for (auto cluster_ref : cluster_refs) {
      cluster_name_vtr.push_back(EXPECT_SUCCESS(db_get_property(stub(), cluster_ref, DB_PROPERTY_CLST_NAME)).str());
      auto frame_refs = db_get_property_db_ref_vtr(stub(), cluster_ref, DB_PROPERTY_CLST_FRM_REFS);
      for (auto frame_ref : frame_refs) {
        frame_name_vtr.push_back(EXPECT_SUCCESS(db_get_property(stub(), frame_ref, DB_PROPERTY_FRM_NAME)).str());
        auto signal_refs = db_get_property_db_ref_vtr(stub(), frame_ref, DB_PROPERTY_FRM_SIG_REFS);
        for (auto signal_ref : signal_refs) {
          signal_name_vtr.push_back(EXPECT_SUCCESS(db_get_property(stub(), signal_ref, DB_PROPERTY_SIG_NAME)).str());
        }
      }
      auto schedule_refs = db_get_property_db_ref_vtr(stub(), cluster_ref, DB_PROPERTY_CLST_LIN_SCHEDULES);
      for (auto schedule_ref : schedule_refs) {
        // TODO: replace nxPropLINSched_Name
        //lin_schedule_name_vtr.push_back(EXPECT_SUCCESS(db_get_property(stub(), schedule_ref, nxPropLINSched_Name)).str());
      }
    }
    EXPECT_SUCCESS(client::db_close_database(stub(), database_ref, 1));
  }

  EXPECT_EQ(999, interface_name_vtr.size());
  EXPECT_EQ(999, alias_vtr.size());
  EXPECT_EQ(999, file_path_vtr.size());
  EXPECT_EQ(999, cluster_name_vtr.size());
  EXPECT_EQ(999, frame_name_vtr.size());
  EXPECT_EQ(999, signal_name_vtr.size());
  EXPECT_EQ(999, lin_schedule_name_vtr.size());
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
