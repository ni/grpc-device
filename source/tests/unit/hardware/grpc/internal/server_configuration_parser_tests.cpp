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
  
#if defined(_MSC_VER)
  const char* kServerSideTlsConfigFile = "config\\server_side_tls.json";
  const char* kMutualTlsConfigFile = "config\\mutual_tls.json";
#else
  const char* kServerSideTlsConfigFile = "config/server_side_tls/server/server_config.json";
  const char* kMutualTlsConfigFile = "config/mutual_tls/server/server_config.json";
#endif

TEST(ServerConfigurationParserTests, CreateConfigurationParserFromDefaultConfigFile_ParseAddress_ReturnsDefaultLocalAddressAndPort)
{
  ::internal::ServerConfigurationParser server_config_parser;

  auto address = server_config_parser.parse_address();

  EXPECT_EQ(address, "[::]:50051");
}

TEST(ServerConfigurationParserTests, CreateConfigurationParserFromMissingConfigFile_ThrowsConfigFileNotFoundException)
{
  try {
    ::internal::ServerConfigurationParser server_config_parser("fake.json", true);
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

TEST(ServerConfigurationParserTests, CreateConfigurationParserFromServerSideTlsConfigFile_ParseServerKey_NotEmpty)
{
  ::internal::ServerConfigurationParser server_config_parser(kServerSideTlsConfigFile, true);

  auto server_key = server_config_parser.parse_server_key();

  EXPECT_FALSE(server_key.empty());
}

TEST(ServerConfigurationParserTests, CreateConfigurationParserFromServerSideTlsConfigFile_ParseServerCert_NotEmpty)
{
  ::internal::ServerConfigurationParser server_config_parser(kServerSideTlsConfigFile, true);

  auto server_cert = server_config_parser.parse_server_cert();

  EXPECT_FALSE(server_cert.empty());
}

TEST(ServerConfigurationParserTests, CreateConfigurationParserFromServerSideTlsConfigFile_ParseRootCert_NotEmpty)
{
  ::internal::ServerConfigurationParser server_config_parser(kServerSideTlsConfigFile, true);

  auto root_cert = server_config_parser.parse_root_cert();

  EXPECT_TRUE(root_cert.empty());
}

TEST(ServerConfigurationParserTests, CreateConfigurationParserFromMutualTlsConfigFile_ParseAllSecurityKeys_NoneEmpty)
{
  ::internal::ServerConfigurationParser server_config_parser(kMutualTlsConfigFile, true);

  auto server_key = server_config_parser.parse_server_key();
  auto server_cert = server_config_parser.parse_server_cert();
  auto root_cert = server_config_parser.parse_root_cert();

  EXPECT_FALSE(server_key.empty());
  EXPECT_FALSE(server_cert.empty());
  EXPECT_FALSE(root_cert.empty());
} 

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace unit
}  // namespace tests
}  // namespace ni
