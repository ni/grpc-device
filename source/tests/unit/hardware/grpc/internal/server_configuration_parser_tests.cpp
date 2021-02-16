#include <gtest/gtest.h>
#include <gmock/gmock.h>
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
  ni::hardware::grpc::internal::ServerConfigurationParser server_config_parser;
    
  auto address = server_config_parser.parse_address();
  
  EXPECT_EQ(address, "0.0.0.0:50051");
}

TEST(ServerConfigurationParserTests, CreateConfigurationParserFromMissingConfigFile_ThrowsConfigFileNotFoundException)
{
  const char* file_path = "fake.json";
  try {
    ni::hardware::grpc::internal::ServerConfigurationParser server_config_parser("fake.json");
    FAIL() << "ConfigFileNotFoundException not thrown";
  }
  catch(const ni::hardware::grpc::internal::ServerConfigurationParser::ConfigFileNotFoundException& ex)  {
    EXPECT_EQ(std::string(ex.what()), ni::hardware::grpc::internal::kConfigFileNotFoundMessage);
  }  
}

TEST(ServerConfigurationParserTests, JsonConfigWithNegativePortNumber_ParseAddress_ThrowsInvalidPortException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"({ "port": -1 })");
  ni::hardware::grpc::internal::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_address();
    FAIL() << "InvalidPortException not thrown";
  }
  catch(const ni::hardware::grpc::internal::ServerConfigurationParser::InvalidPortException& ex)  {
    EXPECT_EQ(std::string(ex.what()), ni::hardware::grpc::internal::kInvalidPortMessage);
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithPortNumberExceedingMax_ParseAddress_ThrowsInvalidPortException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"({ "port": 65536 })");
  ni::hardware::grpc::internal::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_address();
    FAIL() << "InvalidPortException not thrown";
  }
  catch(const ni::hardware::grpc::internal::ServerConfigurationParser::InvalidPortException& ex)  {
    EXPECT_EQ(std::string(ex.what()), ni::hardware::grpc::internal::kInvalidPortMessage);
  }  
}

TEST(ServerConfigurationParserTests, JsonConfigWithPortAsString_ParseAddress_ThrowsWrongPortTypeException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"({ "port" : "9090" })");
  ni::hardware::grpc::internal::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_address();
    FAIL() << "WrongPortTypeException not thrown";
  }
  catch(const ni::hardware::grpc::internal::ServerConfigurationParser::WrongPortTypeException& ex)  {
    EXPECT_THAT(ex.what(), ::testing::HasSubstr( ni::hardware::grpc::internal::kWrongPortTypeMessage));
  }  
}

TEST(ServerConfigurationParserTests, JsonConfigWithoutPortKey_ParseAddress_ThrowsUnspecifiedPortException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"({ "foo" : "bar" })");
  ni::hardware::grpc::internal::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_address();
    FAIL() << "UnspecifiedPortException not thrown";
  }
  catch(const ni::hardware::grpc::internal::ServerConfigurationParser::UnspecifiedPortException& ex)  {
    EXPECT_EQ(std::string(ex.what()), ni::hardware::grpc::internal::kUnspecifiedPortMessage);
  }  
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace unit
}  // namespace tests
}  // namespace ni
