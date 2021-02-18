#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <typeinfo>

#include "hardware/grpc/internal/server_configuration_parser.h"

namespace internal = ni::hardware::grpc::internal;

namespace ni {
namespace tests {
namespace unit {
namespace hardware {
namespace grpc {
namespace internal {

TEST(ServerConfigurationParserTests, CreateConfigurationParserFromDefaultConfigFile_ParseAddress_ReturnsDefaultLocalAddressAndPort)
{
  ::internal::ServerConfigurationParser server_config_parser;

  auto address = server_config_parser.parse_address();

  EXPECT_EQ(address, "0.0.0.0:50051");
}

TEST(ServerConfigurationParserTests, CreateConfigurationParserFromMissingConfigFile_ThrowsConfigFileNotFoundException)
{
  const char* file_path = "fake.json";
  try {
    ::internal::ServerConfigurationParser server_config_parser("fake.json");
    FAIL() << "ConfigFileNotFoundException not thrown";
  }
  catch (const ::internal::ServerConfigurationParser::ConfigFileNotFoundException& ex) {
    EXPECT_EQ(std::string(::internal::kConfigFileNotFoundMessage), ex.what());
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithNegativePortNumber_ParseAddress_ThrowsInvalidPortException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"({ "port": -1 })");
  ::internal::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_address();
    FAIL() << "InvalidPortException not thrown";
  }
  catch (const ::internal::ServerConfigurationParser::InvalidPortException& ex) {
    EXPECT_EQ(std::string(::internal::kInvalidPortMessage), ex.what());
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithPortNumberExceedingMax_ParseAddress_ThrowsInvalidPortException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"({ "port": 65536 })");
  ::internal::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_address();
    FAIL() << "InvalidPortException not thrown";
  }
  catch (const ::internal::ServerConfigurationParser::InvalidPortException& ex) {
    EXPECT_EQ(std::string(::internal::kInvalidPortMessage), ex.what());
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithPortAsString_ParseAddress_ThrowsWrongPortTypeException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"({ "port" : "9090" })");
  ::internal::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_address();
    FAIL() << "WrongPortTypeException not thrown";
  }
  catch (const ::internal::ServerConfigurationParser::WrongPortTypeException& ex) {
    EXPECT_THAT(ex.what(), ::testing::HasSubstr(::internal::kWrongPortTypeMessage));
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithoutPortKey_ParseAddress_ThrowsUnspecifiedPortException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"({ "foo" : "bar" })");
  ::internal::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_address();
    FAIL() << "UnspecifiedPortException not thrown";
  }
  catch (const ::internal::ServerConfigurationParser::UnspecifiedPortException& ex) {
    EXPECT_EQ(std::string(::internal::kUnspecifiedPortMessage), ex.what());
  }
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace unit
}  // namespace tests
}  // namespace ni
