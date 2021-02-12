#include <gtest/gtest.h>
#include "hardware/grpc/internal/server_configuration.h"
#include <typeinfo>

namespace ni {
namespace tests {
namespace unit {
namespace hardware {
namespace grpc {
namespace internal {

const char* kdefaultFilename = "server.json";
const char* kreleaseFolder = "Release";

std::string build_asset_path(const std::string& filename, const std::string& sub_directory)
{
  return sub_directory + "/" + filename;
}

TEST(ServerConfigurationTests, CreateConfigurationWithDefaultConfigFile_ReturnsDefaultLocalAddressAndPort)
{
  auto file_path = build_asset_path(kdefaultFilename, kreleaseFolder);
  ni::hardware::grpc::internal::ServerConfiguration server_configuration(file_path);

  auto address = server_configuration.get_address();
  
  EXPECT_EQ(address, "0.0.0.0:50051");
}

TEST(ServerConfigurationTests, CreateConfigurationWithMissingConfigFile_ThrowsConfigFileNotFoundException)
{
  auto file_path = build_asset_path("fake.json", kreleaseFolder);
  ni::hardware::grpc::internal::ServerConfiguration server_configuration(file_path);

  bool exception_thrown = false;
  try {
    auto address = server_configuration.get_address();
  }
  catch(const std::exception& ex)  {
    EXPECT_EQ(typeid(ex), typeid(ni::hardware::grpc::internal::ServerConfiguration::ConfigFileNotFoundException));
    exception_thrown = true;
  }  
  
  EXPECT_TRUE(exception_thrown);
}

TEST(ServerConfigurationTests, CreateConfigurationWithNegativePortNumber_ThrowsInvalidPortException)
{
  auto config_json = R"(
    {
      "port": -1
    }
  )"_json;
  ni::hardware::grpc::internal::ServerConfiguration server_configuration(config_json);

  bool exception_thrown = false;
  try {
    auto address = server_configuration.get_address();
  }
  catch(const std::exception& ex)  {
    EXPECT_EQ(typeid(ex), typeid(ni::hardware::grpc::internal::ServerConfiguration::InvalidPortException));
    exception_thrown = true;
  }
  
  EXPECT_TRUE(exception_thrown);
}

TEST(ServerConfigurationTests, CreateConfigurationWithPortNumberExceedingMax_ThrowsInvalidPortException)
{
  auto config_json = R"(
    {
      "port": 65536
    }
  )"_json;
  ni::hardware::grpc::internal::ServerConfiguration server_configuration(config_json);

  bool exception_thrown = false;
  try {
    auto address = server_configuration.get_address();
  }
  catch(const std::exception& ex)  {
    EXPECT_EQ(typeid(ex), typeid(ni::hardware::grpc::internal::ServerConfiguration::InvalidPortException));
    exception_thrown = true;
  }  

  EXPECT_TRUE(exception_thrown);
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace unit
}  // namespace tests
}  // namespace ni
