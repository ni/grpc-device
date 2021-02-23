#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <server/server_configuration_parser.h>

#include <typeinfo>

namespace internal = ni::hardware::grpc::internal;

namespace ni {
namespace tests {
namespace unit {

TEST(ServerConfigurationParserTests, CreateConfigurationParserFromDefaultConfigFile_ParseAddress_ReturnsDefaultLocalAddressAndPort)
{
  ::internal::ServerConfigurationParser server_config_parser;

  auto address = server_config_parser.parse_address();

  EXPECT_EQ(address, "[::]:50051");
}

TEST(ServerConfigurationParserTests, CreateConfigurationParserFromMissingConfigFile_ThrowsConfigFileNotFoundException)
{
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

TEST(ServerConfigurationParserTests, JsonConfigWithServerSideTls_ParseServerCert_NotEmpty)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
  {
    "security" : {
        "server_cert": "test_server_self_signed_crt.pem",
        "server_key": "test_server_privatekey.pem",
        "root_cert": ""
    }
  })");
  ::internal::ServerConfigurationParser server_config_parser(config_json);

  auto server_cert = server_config_parser.parse_server_cert();

  EXPECT_FALSE(server_cert.empty());
}

TEST(ServerConfigurationParserTests, JsonConfigWithServerSideTls_ParseServerKey_NotEmpty)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
  {
    "security" : {
        "server_cert": "test_server_self_signed_crt.pem",
        "server_key": "test_server_privatekey.pem",
        "root_cert": ""
    }
  })");
  ::internal::ServerConfigurationParser server_config_parser(config_json);

  auto server_key = server_config_parser.parse_server_key();

  EXPECT_FALSE(server_key.empty());
}

TEST(ServerConfigurationParserTests, JsonConfigWithServerSideTls_ParseRootCert_NotEmpty)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
  {
    "security" : {
        "server_cert": "test_server_self_signed_crt.pem",
        "server_key": "test_server_privatekey.pem",
        "root_cert": ""
    }
  })");
  ::internal::ServerConfigurationParser server_config_parser(config_json);

  auto root_cert = server_config_parser.parse_root_cert();

  EXPECT_TRUE(root_cert.empty());
}

TEST(ServerConfigurationParserTests, JsonConfigWithMutualTls_ParseAllSecurityKeys_NoneEmpty)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
    {
      "security" : {
          "server_cert": "test_server_self_signed_crt.pem",
          "server_key": "test_server_privatekey.pem",
          "root_cert": "test_client_self_signed_crt.pem"
      }
    })");
  ::internal::ServerConfigurationParser server_config_parser(config_json);

  auto server_key = server_config_parser.parse_server_key();
  auto server_cert = server_config_parser.parse_server_cert();
  auto root_cert = server_config_parser.parse_root_cert();

  EXPECT_FALSE(server_key.empty());
  EXPECT_FALSE(server_cert.empty());
  EXPECT_FALSE(root_cert.empty());
}

TEST(ServerConfigurationParserTests, CreateConfigurationParserFromDefaultConfigFile_ParseAllSecurityKeys_AllEmpty)
{
  ::internal::ServerConfigurationParser server_config_parser;

  auto server_key = server_config_parser.parse_server_key();
  auto server_cert = server_config_parser.parse_server_cert();
  auto root_cert = server_config_parser.parse_root_cert();

  EXPECT_TRUE(server_key.empty());
  EXPECT_TRUE(server_cert.empty());
  EXPECT_TRUE(root_cert.empty());
}

TEST(ServerConfigurationParserTests, JsonConfigWithServerCertAsInteger_ParseServerCert_ValueTypeNotStringException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
    {
      "security" : {
          "server_cert": 9,
          "server_key": "test_server_privatekey.pem",
          "root_cert": "test_client_self_signed_crt.pem"
      }
    })");
  ::internal::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_server_cert();
    FAIL() << "ValueTypeNotStringException not thrown";
  }
  catch (const ::internal::ServerConfigurationParser::ValueTypeNotStringException& ex) {
    EXPECT_THAT(ex.what(), ::testing::HasSubstr(::internal::kValueTypeNotStringMessage));
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithServerKeyAsNull_ParseServerKey_ValueTypeNotStringException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
    {
      "security" : {
          "server_cert": "test_server_self_signed_crt.pem",
          "server_key": null,
          "root_cert": "test_client_self_signed_crt.pem"
      }
    })");
  ::internal::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_server_key();
    FAIL() << "ValueTypeNotStringException not thrown";
  }
  catch (const ::internal::ServerConfigurationParser::ValueTypeNotStringException& ex) {
    EXPECT_THAT(ex.what(), ::testing::HasSubstr(::internal::kValueTypeNotStringMessage));
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithRootCertAsBoolean_ParseRootCert_ValueTypeNotStringException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
    {
      "security" : {
          "server_cert": "test_server_self_signed_crt.pem",
          "server_key": "test_server_privatekey.pem",
          "root_cert": true
      }
    })");
  ::internal::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_root_cert();
    FAIL() << "ValueTypeNotStringException not thrown";
  }
  catch (const ::internal::ServerConfigurationParser::ValueTypeNotStringException& ex) {
    EXPECT_THAT(ex.what(), ::testing::HasSubstr(::internal::kValueTypeNotStringMessage));
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithValidPemFilesButWithoutSecurityParentKey_ParseAllSecurityKeys_AllEmpty)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
    {
      "server_cert": "test_server_self_signed_crt.pem",
      "server_key": "test_server_privatekey.pem",
      "root_cert": "test_client_self_signed_crt.pem"
    })");
  ::internal::ServerConfigurationParser server_config_parser(config_json);

  auto server_key = server_config_parser.parse_server_key();
  auto server_cert = server_config_parser.parse_server_cert();
  auto root_cert = server_config_parser.parse_root_cert();

  EXPECT_TRUE(server_key.empty());
  EXPECT_TRUE(server_cert.empty());
  EXPECT_TRUE(root_cert.empty());
}

TEST(ServerConfigurationParserTests, JsonConfigForExistingPemFilesUnderSecurityParentKey_ParseAllSecurityKeys_NoneEmpty)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
    {
      "security" : {
          "server_cert": "test_server_self_signed_crt.pem",
          "server_key": "test_server_privatekey.pem",
          "root_cert": "test_client_self_signed_crt.pem"
      }
    })");
  ::internal::ServerConfigurationParser server_config_parser(config_json);

  auto server_key = server_config_parser.parse_server_key();
  auto server_cert = server_config_parser.parse_server_cert();
  auto root_cert = server_config_parser.parse_root_cert();

  EXPECT_FALSE(server_key.empty());
  EXPECT_FALSE(server_cert.empty());
  EXPECT_FALSE(root_cert.empty());
}

TEST(ServerConfigurationParserTests, EmptyJsonConfig_ParseAllSecurityKeys_AllEmpty)
{
  nlohmann::json config_json = nlohmann::json::parse(R"({})");
  ::internal::ServerConfigurationParser server_config_parser(config_json);

  auto server_key = server_config_parser.parse_server_key();
  auto server_cert = server_config_parser.parse_server_cert();
  auto root_cert = server_config_parser.parse_root_cert();

  EXPECT_TRUE(server_key.empty());
  EXPECT_TRUE(server_cert.empty());
  EXPECT_TRUE(root_cert.empty());
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
