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
  ([this](auto& response) {          \
    EXPECT_EQ(0, response.status()); \
    return response;                 \
  })(response_)

#define EXPECT_XNET_ERROR(error, response) \
  if (1) {                                 \
    EXPECT_EQ(error, (response).status()); \
  }

TEST_F(NiXnetCommonDriverApiTests, XNETDatabaseBrowserFromExample_FetchData_DataLooksReasonable)
{
  char** interface_name_array = NULL;
  char** db_filepath_array = NULL;
  char** db_alias_array = NULL;
  char** cluster_name_array = NULL;
  char** frame_name_array = NULL;
  char** signal_name_array = NULL;
  char** lin_schedule_name_array = NULL;
  u32 number_of_interfaces = 0;
  u32 number_of_db_filepaths = 0;
  u32 number_of_db_aliases = 0;
  u32 number_of_clusters = 0;
  u32 number_of_frames = 0;
  u32 number_of_signals = 0;
  u32 number_of_lin_schedules = 0;
  nxStatus_t status = 0;
  u32 array_pos = 0;
  u32 property_size = 0;
  unsigned int local_NumberOfInterfaces = 0;
  char** interface_names = NULL;
  nxSessionRef_t system_ref = 0;
  u32 alias_list_size = 0;
  u32 filepath_list_size = 0;
  u32 num_databases = 0;
  char* alias_list = NULL;
  char* filepath_list = NULL;
  char* temp_ptr = NULL;
  char** alias_array = NULL;
  size_t tempLen = 0;
  char** filepath_array = NULL;
  unsigned int local_NumberOfClusters = 0;
  char** cluster_names = NULL;
  nxDatabaseRef_t database_ref = 0;
  nxDatabaseRef_t* cluster_refs = NULL;
  unsigned int filtering = 0;
  unsigned int correct_protocol = 0;
  u32 protocol = 0;
  unsigned int local_NumberOfFrames = 0;
  char** frame_names = NULL;
  nxDatabaseRef_t cluster_ref = 0;
  nxDatabaseRef_t* frame_refs = NULL;
  unsigned int local_NumberOfSignals = 0;
  char** signal_names = NULL;
  nxDatabaseRef_t frame_ref = 0;
  nxDatabaseRef_t* signal_refs = NULL;
  unsigned int total_number_of_schedules = 0;
  char** schedule_names = NULL;
  nxDatabaseRef_t* schedule_refs = NULL;
  {
    array_pos = 0;
    property_size = 0;
    local_NumberOfInterfaces = 0;
    interface_names = NULL;
    system_ref = 0;
    auto session = EXPECT_SUCCESS(client::system_open(stub())).system_ref();
    auto get_property_size_response = EXPECT_SUCCESS(client::get_property_size(stub(), session, PROPERTY_SYS_INTF_REFS));
    local_NumberOfInterfaces = (unsigned int)(property_size / sizeof(u32));
    if (0 < local_NumberOfInterfaces) {
      auto get_property_response = EXPECT_SUCCESS(get_property(stub(), session, PROPERTY_SYS_INTF_REFS));
      interface_names = (char**)malloc(local_NumberOfInterfaces * sizeof(char*));
      for (int i = 0; i < local_NumberOfInterfaces; ++i) {
        auto get_property_size_response = EXPECT_SUCCESS(client::get_property_size(stub(), session, PROPERTY_INTF_NAME));
        interface_names[array_pos] = (char*)malloc(property_size);
        auto get_property_response = EXPECT_SUCCESS(get_property(stub(), session, PROPERTY_INTF_NAME));
        ++array_pos;
      }
    }
    if (0 != system_ref) {
      EXPECT_SUCCESS(client::system_close(stub(), session));
    }
    number_of_interfaces = array_pos;
    interface_name_array = interface_names;
  }
  {
    alias_list_size = 0;
    filepath_list_size = 0;
    num_databases = 0;
    alias_list = NULL;
    filepath_list = NULL;
    temp_ptr = NULL;
    alias_array = NULL;
    tempLen = 0;
    auto db_get_database_list_sizes_response = EXPECT_SUCCESS(client::db_get_database_list_sizes(stub(), ""));
    if (alias_list_size > 0 && filepath_list_size > 0) {
      alias_list = (char*)malloc(alias_list_size);
      filepath_list = (char*)malloc(filepath_list_size);
      //auto db_get_database_list_response = EXPECT_SUCCESS(client::db_get_database_list(stub(), "", alias_list_size, filepath_list_size));
      if (num_databases > 0) {
        alias_array = (char**)malloc(num_databases * sizeof(char*));
        temp_ptr = alias_list;
        for (int i = 0; i < num_databases; ++i) {
          tempLen = strcspn(temp_ptr, ",");
          alias_array[i] = (char*)malloc(tempLen + 1);
          strncpy(alias_array[i], temp_ptr, tempLen);
          alias_array[i][tempLen] = (char)'\0';
          temp_ptr += tempLen + 1;
        }
      }
      else {
        num_databases = 0;
      }
    }
    number_of_db_aliases = num_databases;
    db_alias_array = alias_array;
  }
  {
    alias_list_size = 0;
    filepath_list_size = 0;
    num_databases = 0;
    alias_list = NULL;
    filepath_list = NULL;
    temp_ptr = NULL;
    filepath_array = NULL;
    tempLen = 0;
    auto db_get_database_list_sizes_response = EXPECT_SUCCESS(client::db_get_database_list_sizes(stub(), ""));
    if (alias_list_size > 0 && filepath_list_size > 0) {
      alias_list = (char*)malloc(alias_list_size);
      filepath_list = (char*)malloc(filepath_list_size);
      //auto db_get_database_list_response = EXPECT_SUCCESS(client::db_get_database_list(stub(), "", alias_list_size, filepath_list_size));
      if (num_databases > 0) {
        filepath_array = (char**)malloc(num_databases * sizeof(char*));
        temp_ptr = filepath_list;
        for (int i = 0; i < num_databases; ++i) {
          tempLen = strcspn(temp_ptr, ",");
          filepath_array[i] = (char*)malloc(tempLen + 1);
          strncpy(filepath_array[i], temp_ptr, tempLen);
          filepath_array[i][tempLen] = (char)'\0';
          temp_ptr += tempLen + 1;
        }
      }
      else {
        num_databases = 0;
      }
    }
    number_of_db_filepaths = num_databases;
    db_filepath_array = filepath_array;
  }
  for (int i = 0; i < number_of_db_aliases; ++i) {
    {
      array_pos = 0;
      local_NumberOfClusters = 0;
      property_size = 0;
      cluster_names = NULL;
      database_ref = 0;
      cluster_refs = NULL;
      filtering = 0;
      correct_protocol = 0;
      protocol = 0;
      EXPECT_SUCCESS(client::db_open_database(stub(), db_alias_array[i]));
      //auto db_get_property_size_response = EXPECT_SUCCESS(client::db_get_property_size(stub(), database_ref, DB_PROPERTY_DATABASE_CLST_REFS));
      local_NumberOfClusters = (unsigned int)(property_size / sizeof(nxDatabaseRef_t));
      if (0 < local_NumberOfClusters) {
        cluster_refs = (nxDatabaseRef_t*)malloc(property_size);
        //auto db_get_property_response = EXPECT_SUCCESS(client::db_get_property(stub(), database_ref, DB_PROPERTY_DATABASE_CLST_REFS, property_size));
        cluster_names = (char**)malloc(local_NumberOfClusters * sizeof(char*));
        for (int j = 0; j < local_NumberOfClusters; ++j) {
          if (filtering == 0) {
            correct_protocol = 1;
          }
          else {
            //auto db_get_property_response = EXPECT_SUCCESS(client::db_get_property(stub(), cluster_refs[j], DB_PROPERTY_CLST_PROTOCOL, (u32)sizeof(protocol)));
            if (protocol == nxProtocol_Unknown) {
              correct_protocol = 1;
            }
            else {
              correct_protocol = 0;
            }
          }
          if (correct_protocol != 0) {
            //auto db_get_property_size_response = EXPECT_SUCCESS(client::db_get_property_size(stub(), cluster_refs[j], DB_PROPERTY_CLST_NAME));
            if (property_size > 0) {
              cluster_names[array_pos] = (char*)malloc(property_size);
              //auto db_get_property_response = EXPECT_SUCCESS(client::db_get_property(stub(), cluster_refs[j], DB_PROPERTY_CLST_NAME, property_size));
              ++array_pos;
            }
          }
        }
      }
      if (0 != database_ref) {
        //EXPECT_SUCCESS(client::db_close_database(stub(), database_ref, 1));
      }
      number_of_clusters = array_pos;
      cluster_name_array = cluster_names;
    }
    for (int j = 0; j < number_of_clusters; ++j) {
      {
        array_pos = 0;
        property_size = 0;
        local_NumberOfFrames = 0;
        frame_names = NULL;
        database_ref = 0;
        cluster_ref = 0;
        frame_refs = NULL;
        EXPECT_SUCCESS(client::db_open_database(stub(), db_alias_array[i]));
        //EXPECT_SUCCESS(client::db_find_object(stub(), database_ref, nxClass_Cluster, cluster_name_array[j]));
        //auto db_get_property_size_response = EXPECT_SUCCESS(client::db_get_property_size(stub(), cluster_ref, DB_PROPERTY_CLST_FRM_REFS));
        local_NumberOfFrames = (unsigned int)(property_size / sizeof(nxDatabaseRef_t));
        if (0 < local_NumberOfFrames) {
          frame_refs = (nxDatabaseRef_t*)malloc(property_size);
          //auto db_get_property_response = EXPECT_SUCCESS(client::db_get_property(stub(), cluster_ref, DB_PROPERTY_CLST_FRM_REFS, property_size));
          frame_names = (char**)malloc(local_NumberOfFrames * sizeof(char*));
          for (int k = 0; k < local_NumberOfFrames; ++k) {
            //auto db_get_property_size_response = EXPECT_SUCCESS(client::db_get_property_size(stub(), frame_refs[k], DB_PROPERTY_FRM_NAME));
            if (property_size > 0) {
              frame_names[array_pos] = (char*)malloc(property_size);
              //auto db_get_property_response = EXPECT_SUCCESS(client::db_get_property(stub(), frame_refs[k], DB_PROPERTY_FRM_NAME, property_size));
              ++array_pos;
            }
          }
        }
        if (0 != database_ref) {
          //EXPECT_SUCCESS(client::db_close_database(stub(), database_ref, 1));
        }
        number_of_frames = array_pos;
        frame_name_array = frame_names;
      }
      for (int k = 0; k < number_of_frames; ++k) {
        {
          array_pos = 0;
          property_size = 0;
          local_NumberOfSignals = 0;
          signal_names = NULL;
          database_ref = 0;
          cluster_ref = 0;
          frame_ref = 0;
          signal_refs = NULL;
          EXPECT_SUCCESS(client::db_open_database(stub(), db_alias_array[i]));
          //EXPECT_SUCCESS(client::db_find_object(stub(), database_ref, nxClass_Cluster, cluster_name_array[j]));
          //EXPECT_SUCCESS(client::db_find_object(stub(), cluster_ref, nxClass_Frame, frame_name_array[k]));
          //auto db_get_property_size_response = EXPECT_SUCCESS(client::db_get_property_size(stub(), frame_ref, DB_PROPERTY_FRM_SIG_REFS));
          local_NumberOfSignals = (unsigned int)(property_size / sizeof(nxDatabaseRef_t));
          if (0 < local_NumberOfSignals) {
            signal_refs = (nxDatabaseRef_t*)malloc(property_size);
            //auto db_get_property_response = EXPECT_SUCCESS(client::db_get_property(stub(), frame_ref, DB_PROPERTY_FRM_SIG_REFS, property_size));
            signal_names = (char**)malloc(local_NumberOfSignals * sizeof(char*));
            for (int m = 0; m < local_NumberOfSignals; ++m) {
              //auto db_get_property_size_response = EXPECT_SUCCESS(client::db_get_property_size(stub(), signal_refs[m], DB_PROPERTY_SIG_NAME));
              if (property_size > 0) {
                signal_names[array_pos] = (char*)malloc(property_size);
                //auto db_get_property_response = EXPECT_SUCCESS(client::db_get_property(stub(), signal_refs[m], DB_PROPERTY_SIG_NAME, property_size));
                ++array_pos;
              }
            }
          }
          if (0 != database_ref) {
            //EXPECT_SUCCESS(client::db_close_database(stub(), database_ref, 1));
          }
          number_of_signals = array_pos;
          signal_name_array = signal_names;
        }
      }
      {
        array_pos = 0;
        total_number_of_schedules = 0;
        property_size = 0;
        schedule_names = NULL;
        cluster_ref = 0;
        database_ref = 0;
        schedule_refs = NULL;
        EXPECT_SUCCESS(client::db_open_database(stub(), db_alias_array[i]));
        //EXPECT_SUCCESS(client::db_find_object(stub(), database_ref, nxClass_Cluster, cluster_name_array[j]));
        //auto db_get_property_size_response = EXPECT_SUCCESS(client::db_get_property_size(stub(), cluster_ref, DB_PROPERTY_CLST_LIN_SCHEDULES));
        total_number_of_schedules = (unsigned int)(property_size / sizeof(nxDatabaseRef_t));
        if (0 < total_number_of_schedules) {
          schedule_refs = (nxDatabaseRef_t*)malloc(property_size);
          //auto db_get_property_response = EXPECT_SUCCESS(client::db_get_property(stub(), cluster_ref, DB_PROPERTY_CLST_LIN_SCHEDULES, property_size));
          schedule_names = (char**)malloc(total_number_of_schedules * sizeof(char*));
          for (int k = 0; k < total_number_of_schedules; ++k) {
            //auto db_get_property_size_response = EXPECT_SUCCESS(client::db_get_property_size(stub(), schedule_refs[k], nxPropLINSched_Name));
            if (property_size > 0) {
              schedule_names[array_pos] = (char*)malloc(property_size);
              //auto db_get_property_response = EXPECT_SUCCESS(client::db_get_property(stub(), schedule_refs[k], nxPropLINSched_Name, property_size));
              ++array_pos;
            }
          }
        }
        if (0 != database_ref) {
          //EXPECT_SUCCESS(client::db_close_database(stub(), database_ref, 1));
        }
        number_of_lin_schedules = array_pos;
        lin_schedule_name_array = schedule_names;
      }
    }
  }

  //EXPECT_EQ(0, get_property_size_response.property_size());
  //EXPECT_EQ(999, get_property_response.property_value_size());
  //EXPECT_EQ(999, get_property_response.property_value().size());
  //EXPECT_EQ(0 /* void[] */, get_property_response.property_value(0));
  //EXPECT_EQ(0, db_get_database_list_sizes_response.sizeof_filepath_buffer());
  //EXPECT_EQ(0, db_get_database_list_sizes_response.sizeof_alias_buffer());
  /*
  EXPECT_EQ(0, db_get_database_list_response.number_of_databases());
  EXPECT_EQ(999, db_get_database_list_response.filepath_buffer_size());
  EXPECT_EQ(999, db_get_database_list_response.filepath_buffer().size());
  EXPECT_EQ('\0', db_get_database_list_response.filepath_buffer(0));
  EXPECT_EQ(999, db_get_database_list_response.alias_buffer_size());
  EXPECT_EQ(999, db_get_database_list_response.alias_buffer().size());
  EXPECT_EQ('\0', db_get_database_list_response.alias_buffer(0));
  */
  //EXPECT_EQ(0, db_get_database_list_sizes_response.sizeof_filepath_buffer());
  //EXPECT_EQ(0, db_get_database_list_sizes_response.sizeof_alias_buffer());
  /*
  EXPECT_EQ(0, db_get_database_list_response.number_of_databases());
  EXPECT_EQ(999, db_get_database_list_response.filepath_buffer_size());
  EXPECT_EQ(999, db_get_database_list_response.filepath_buffer().size());
  EXPECT_EQ('\0', db_get_database_list_response.filepath_buffer(0));
  EXPECT_EQ(999, db_get_database_list_response.alias_buffer_size());
  EXPECT_EQ(999, db_get_database_list_response.alias_buffer().size());
  EXPECT_EQ('\0', db_get_database_list_response.alias_buffer(0));
  */
  //EXPECT_EQ(0, db_get_property_size_response.property_size());
  //EXPECT_EQ(999, db_get_property_response.property_value_size());
  //EXPECT_EQ(999, db_get_property_response.property_value().size());
  //EXPECT_EQ(0 /* void[] */, db_get_property_response.property_value(0));
  //EXPECT_EQ(999, db_get_property_response.property_value_size());
  //EXPECT_EQ(999, db_get_property_response.property_value().size());
  //EXPECT_EQ(0 /* void[] */, db_get_property_response.property_value(0));
  //EXPECT_EQ(0, db_get_property_size_response.property_size());
  //EXPECT_EQ(999, db_get_property_response.property_value_size());
  //EXPECT_EQ(999, db_get_property_response.property_value().size());
  //EXPECT_EQ(0 /* void[] */, db_get_property_response.property_value(0));
  //EXPECT_EQ(0, db_get_property_size_response.property_size());
  //EXPECT_EQ(999, db_get_property_response.property_value_size());
  //EXPECT_EQ(999, db_get_property_response.property_value().size());
  //EXPECT_EQ(0 /* void[] */, db_get_property_response.property_value(0));
  //EXPECT_EQ(0, db_get_property_size_response.property_size());
  //EXPECT_EQ(999, db_get_property_response.property_value_size());
  //EXPECT_EQ(999, db_get_property_response.property_value().size());
  //EXPECT_EQ(0 /* void[] */, db_get_property_response.property_value(0));
  //EXPECT_EQ(0, db_get_property_size_response.property_size());
  //EXPECT_EQ(999, db_get_property_response.property_value_size());
  //EXPECT_EQ(999, db_get_property_response.property_value().size());
  //EXPECT_EQ(0 /* void[] */, db_get_property_response.property_value(0));
  //EXPECT_EQ(0, db_get_property_size_response.property_size());
  //EXPECT_EQ(999, db_get_property_response.property_value_size());
  //EXPECT_EQ(999, db_get_property_response.property_value().size());
  //EXPECT_EQ(0 /* void[] */, db_get_property_response.property_value(0));
  //EXPECT_EQ(0, db_get_property_size_response.property_size());
  //EXPECT_EQ(999, db_get_property_response.property_value_size());
  //EXPECT_EQ(999, db_get_property_response.property_value().size());
  //EXPECT_EQ(0 /* void[] */, db_get_property_response.property_value(0));
  //EXPECT_EQ(0, db_get_property_size_response.property_size());
  //EXPECT_EQ(999, db_get_property_response.property_value_size());
  //EXPECT_EQ(999, db_get_property_response.property_value().size());
  //EXPECT_EQ(0 /* void[] */, db_get_property_response.property_value(0));
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
