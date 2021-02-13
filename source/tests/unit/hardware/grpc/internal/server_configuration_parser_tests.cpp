#include <gtest/gtest.h>
#include "hardware/grpc/internal/server_configuration.h"
#include <typeinfo>

namespace ni {
namespace tests {
namespace unit {
namespace hardware {
namespace grpc {
namespace internal {

TEST(ServerConfigurationTests, CreateConfigurationWithDefaultConfigFile_ReturnsDefaultLocalAddressAndPort)
{
  std::string address;
  try {
    // On Linux the tests run in the Release folder and therefore the default of for "server_config.json" should work
    ni::hardware::grpc::internal::ServerConfigurationParser server_configuration_linux;
    address = server_configuration_linux.parse_address();
  }
  catch (const ni::hardware::grpc::internal::ServerConfigurationParser::ConfigFileNotFoundException& ex) {
    // On Windows the tests run one level above the Release folder and therefore we need to add the relative path "Release"
    const char* file_path = "Release/server_config.json";
    ni::hardware::grpc::internal::ServerConfigurationParser server_configuration_windows(file_path);
    address = server_configuration_windows.parse_address();
  }
  
  EXPECT_EQ(address, "0.0.0.0:50051");
}

TEST(ServerConfigurationTests, CreateConfigurationWithMissingConfigFile_ThrowsConfigFileNotFoundException)
{
  //auto file_path = build_asset_path("fake.json", kreleaseFolder);
  const char* file_path = "fake.json";
  bool exception_thrown = false;
  try {
    ni::hardware::grpc::internal::ServerConfigurationParser server_configuration("fake.json");
  }
  catch(const std::exception& ex)  {
    EXPECT_EQ(typeid(ex), typeid(ni::hardware::grpc::internal::ServerConfigurationParser::ConfigFileNotFoundException));
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
  ni::hardware::grpc::internal::ServerConfigurationParser server_configuration(config_json);

  bool exception_thrown = false;
  try {
    auto address = server_configuration.parse_address();
  }
  catch(const std::exception& ex)  {
    EXPECT_EQ(typeid(ex), typeid(ni::hardware::grpc::internal::ServerConfigurationParser::InvalidPortException));
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
  ni::hardware::grpc::internal::ServerConfigurationParser server_configuration(config_json);

  bool exception_thrown = false;
  try {
    auto address = server_configuration.parse_address();
  }
  catch(const std::exception& ex)  {
    EXPECT_EQ(typeid(ex), typeid(ni::hardware::grpc::internal::ServerConfigurationParser::InvalidPortException));
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
