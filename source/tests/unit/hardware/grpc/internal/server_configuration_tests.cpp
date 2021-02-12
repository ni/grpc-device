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

TEST(ServerConfigurationTests, CreateConfigurationWithDefault_ReturnsDefaultLocalAddressAndPort)
{
  auto file_path = build_asset_path(kdefaultFilename, kreleaseFolder);
  ni::hardware::grpc::internal::ServerConfiguration server_configuration(file_path);

  auto address = server_configuration.get_address();
  
  EXPECT_EQ(address, "0.0.0.0:50051");
}

TEST(ServerConfigurationTests, CreateConfigurationWithMissingConfigFile_ThrowsConfigFileNotFoundException)
{
  auto file_path = build_asset_path("fake.json", "");
  ni::hardware::grpc::internal::ServerConfiguration server_configuration(file_path);

  try {
    auto address = server_configuration.get_address();
  }
  catch(const std::exception& ex)  {
    EXPECT_EQ(typeid(ex), typeid(ni::hardware::grpc::internal::ServerConfiguration::ConfigFileNotFoundException));
  }  
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace unit
}  // namespace tests
}  // namespace ni
