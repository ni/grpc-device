#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <server/server_configuration_parser.h>

#include <typeinfo>

namespace ni {
namespace tests {
namespace unit {

using FeatureState = nidevice_grpc::FeatureToggles::FeatureState;

TEST(ServerConfigurationParserTests, CreateConfigurationParserFromDefaultConfigFile_ParseAddress_ReturnsDefaultLocalAddressAndPort)
{
  nidevice_grpc::ServerConfigurationParser server_config_parser;

  auto address = server_config_parser.parse_address();

  EXPECT_EQ(address, nidevice_grpc::kDefaultAddressPrefix + std::string("31763"));
}

TEST(ServerConfigurationParserTests, CreateConfigurationParserFromPathToDefaultConfigFile_ParseAddress_NotEmpty)
{
  std::string config_file_path = nidevice_grpc::ServerConfigurationParser::get_exe_path() + "server_config.json";
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_file_path);

  auto address = server_config_parser.parse_address();

  EXPECT_FALSE(address.empty());
}

TEST(ServerConfigurationParserTests, CreateConfigurationParserFromPathToMutualTlsConfigFile_ParseAllSecurityKeys_NoneEmpty)
{
  std::string config_file_path = nidevice_grpc::ServerConfigurationParser::get_exe_path() + "test_mutual_tls_config.json";
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_file_path);

  auto server_key = server_config_parser.parse_server_key();
  auto server_cert = server_config_parser.parse_server_cert();
  auto root_cert = server_config_parser.parse_root_cert();

  EXPECT_FALSE(server_key.empty());
  EXPECT_FALSE(server_cert.empty());
  EXPECT_FALSE(root_cert.empty());
}

TEST(ServerConfigurationParserTests, CreateConfigurationParserFromMissingConfigFile_ThrowsConfigFileNotFoundException)
{
  std::string missing_file_path = "fake.json";
  try {
    nidevice_grpc::ServerConfigurationParser server_config_parser(missing_file_path);

    FAIL() << "ConfigFileNotFoundException not thrown";
  }
  catch (const nidevice_grpc::ServerConfigurationParser::ConfigFileNotFoundException& ex) {
    EXPECT_EQ(nidevice_grpc::kConfigFileNotFoundMessage + std::string(missing_file_path), ex.what());
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithNegativePortNumber_ParseAddress_ThrowsInvalidPortException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"({ "port": -1 })");
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_address();

    FAIL() << "InvalidPortException not thrown";
  }
  catch (const nidevice_grpc::ServerConfigurationParser::InvalidPortException& ex) {
    EXPECT_EQ(std::string(nidevice_grpc::kInvalidPortMessage), ex.what());
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithPortNumberExceedingMax_ParseAddress_ThrowsInvalidPortException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"({ "port": 65536 })");
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_address();

    FAIL() << "InvalidPortException not thrown";
  }
  catch (const nidevice_grpc::ServerConfigurationParser::InvalidPortException& ex) {
    EXPECT_EQ(std::string(nidevice_grpc::kInvalidPortMessage), ex.what());
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithPortAsString_ParseAddress_ThrowsWrongPortTypeException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"({ "port" : "9090" })");
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_address();

    FAIL() << "WrongPortTypeException not thrown";
  }
  catch (const nidevice_grpc::ServerConfigurationParser::WrongPortTypeException& ex) {
    EXPECT_THAT(ex.what(), testing::HasSubstr(nidevice_grpc::kWrongPortTypeMessage));
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithoutPortKey_ParseAddress_ThrowsUnspecifiedPortException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"({ "foo" : "bar" })");
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_address();
    FAIL() << "UnspecifiedPortException not thrown";
  }
  catch (const nidevice_grpc::ServerConfigurationParser::UnspecifiedPortException& ex) {
    EXPECT_EQ(std::string(nidevice_grpc::kUnspecifiedPortMessage), ex.what());
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
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_json);

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
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_json);

  auto server_key = server_config_parser.parse_server_key();

  EXPECT_FALSE(server_key.empty());
}

TEST(ServerConfigurationParserTests, JsonConfigWithServerSideTls_ParseRootCert_Empty)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
  {
    "security" : {
        "server_cert": "test_server_self_signed_crt.pem",
        "server_key": "test_server_privatekey.pem",
        "root_cert": ""
    }
  })");
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_json);

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
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_json);

  auto server_key = server_config_parser.parse_server_key();
  auto server_cert = server_config_parser.parse_server_cert();
  auto root_cert = server_config_parser.parse_root_cert();

  EXPECT_FALSE(server_key.empty());
  EXPECT_FALSE(server_cert.empty());
  EXPECT_FALSE(root_cert.empty());
}

TEST(ServerConfigurationParserTests, CreateConfigurationParserFromDefaultConfigFile_ParseAllSecurityKeys_AllEmpty)
{
  nidevice_grpc::ServerConfigurationParser server_config_parser;

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
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_server_cert();

    FAIL() << "ValueTypeNotStringException not thrown";
  }
  catch (const nidevice_grpc::ServerConfigurationParser::ValueTypeNotStringException& ex) {
    EXPECT_THAT(ex.what(), testing::HasSubstr(nidevice_grpc::kValueTypeNotStringMessage));
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
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_server_key();

    FAIL() << "ValueTypeNotStringException not thrown";
  }
  catch (const nidevice_grpc::ServerConfigurationParser::ValueTypeNotStringException& ex) {
    EXPECT_THAT(ex.what(), testing::HasSubstr(nidevice_grpc::kValueTypeNotStringMessage));
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
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_root_cert();

    FAIL() << "ValueTypeNotStringException not thrown";
  }
  catch (const nidevice_grpc::ServerConfigurationParser::ValueTypeNotStringException& ex) {
    EXPECT_THAT(ex.what(), testing::HasSubstr(nidevice_grpc::kValueTypeNotStringMessage));
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithValidPemFilesButWithoutSecurityParentKey_ParseAllSecurityKeys_AllEmpty)
{
  // This JSON configuration is missing the "security" parent key
  nlohmann::json config_json = nlohmann::json::parse(R"(
    {
      "server_cert": "test_server_self_signed_crt.pem",
      "server_key": "test_server_privatekey.pem",
      "root_cert": "test_client_self_signed_crt.pem"
    })");
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_json);

  auto server_key = server_config_parser.parse_server_key();
  auto server_cert = server_config_parser.parse_server_cert();
  auto root_cert = server_config_parser.parse_root_cert();

  EXPECT_TRUE(server_key.empty());
  EXPECT_TRUE(server_cert.empty());
  EXPECT_TRUE(root_cert.empty());
}

TEST(ServerConfigurationParserTests, EmptyJsonConfig_ParseAllSecurityKeys_AllEmpty)
{
  nlohmann::json config_json = nlohmann::json::parse(R"({})");
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_json);

  auto server_key = server_config_parser.parse_server_key();
  auto server_cert = server_config_parser.parse_server_cert();
  auto root_cert = server_config_parser.parse_root_cert();

  EXPECT_TRUE(server_key.empty());
  EXPECT_TRUE(server_cert.empty());
  EXPECT_TRUE(root_cert.empty());
}

TEST(ServerConfigurationParserTests, JsonConfigWithMissingServerCertFile_ParseServerCert_ThrowsFileNotFoundException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
    {
      "security" : {
          "server_cert": "missing_server_cert.pem"
      }
    })");
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_server_cert();

    FAIL() << "FileNotFoundException not thrown";
  }
  catch (const nidevice_grpc::ServerConfigurationParser::FileNotFoundException& ex) {
    EXPECT_THAT(ex.what(), testing::HasSubstr(nidevice_grpc::kFileNotFoundMessage));
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithMissingServerKeyFile_ParseServerKey_ThrowsFileNotFoundException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
    {
      "security" : {
          "server_key": "missing_server_key.pem"
      }
    })");
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_server_key();

    FAIL() << "FileNotFoundException not thrown";
  }
  catch (const nidevice_grpc::ServerConfigurationParser::FileNotFoundException& ex) {
    EXPECT_THAT(ex.what(), testing::HasSubstr(nidevice_grpc::kFileNotFoundMessage));
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithMissingRootCertFile_ParseRootCert_ThrowsFileNotFoundException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
    {
      "security" : {
          "root_cert": "missing_root_cert.pem"
      }
    })");
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_root_cert();

    FAIL() << "FileNotFoundException not thrown";
  }
  catch (const nidevice_grpc::ServerConfigurationParser::FileNotFoundException& ex) {
    EXPECT_THAT(ex.what(), testing::HasSubstr(nidevice_grpc::kFileNotFoundMessage));
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithEnabledFeature_ParseFeatureToggles_FeatureIsEnabled)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
    {
      "feature_toggles" : { 
        "feature": true
      }
    })");
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_json);

  auto features = server_config_parser.parse_feature_toggles();

  EXPECT_EQ(FeatureState::kEnabled, features.get_feature_state("feature"));
}

TEST(ServerConfigurationParserTests, JsonConfigWithEnabledFeature_ParseFeatureToggles_SomeOtherFeatureIsUnspecified)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
    {
      "feature_toggles" : { 
        "feature": true
      }
    })");
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_json);

  auto features = server_config_parser.parse_feature_toggles();

  EXPECT_EQ(FeatureState::kUnspecified, features.get_feature_state("someOtherFeature"));
}

TEST(ServerConfigurationParserTests, JsonConfigWithDisabledFeature_ParseFeatureToggles_FeatureIsDisabled)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
    {
      "feature_toggles" : { 
        "feature": false
      }
    })");
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_json);

  auto features = server_config_parser.parse_feature_toggles();

  EXPECT_EQ(FeatureState::kDisabled, features.get_feature_state("feature"));
}

TEST(ServerConfigurationParserTests, JsonConfigWithMultipleFeaturesWithDifferentEnabledState_ParseFeatureToggles_FeaturesAreEnabledAndDisabled)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
    {
      "feature_toggles" : { 
        "feature1": false,
        "feature2": true,
        "feature3": false,
        "feature4": true
      }
    })");
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_json);

  auto features = server_config_parser.parse_feature_toggles();

  EXPECT_EQ(FeatureState::kDisabled, features.get_feature_state("feature1"));
  EXPECT_EQ(FeatureState::kEnabled, features.get_feature_state("feature2"));
  EXPECT_EQ(FeatureState::kDisabled, features.get_feature_state("feature3"));
  EXPECT_EQ(FeatureState::kEnabled, features.get_feature_state("feature4"));
  EXPECT_EQ(FeatureState::kUnspecified, features.get_feature_state("someOtherFeature"));
}

TEST(ServerConfigurationParserTests, JsonConfigWithInvalidFeatureToggleValue_ParseFeatureToggles_ThrowsInvalidFeatureToggleException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
    {
      "feature_toggles" : { 
        "feature": 12345
      }
    })");
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_json);

  EXPECT_THROW(
      {
        auto features = server_config_parser.parse_feature_toggles();
      },
      nidevice_grpc::ServerConfigurationParser::InvalidFeatureToggleException);
}

TEST(ServerConfigurationParserTests, JsonConfigWithFeatureTogglesAsArray_ParseFeatureToggles_ThrowsInvalidFeatureToggleException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
    {
      "feature_toggles" : [ { "feature": true } ]
    })");
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_json);

  EXPECT_THROW(
      {
        auto features = server_config_parser.parse_feature_toggles();
      },
      nidevice_grpc::ServerConfigurationParser::InvalidFeatureToggleException);
}

TEST(ServerConfigurationParserTests, JsonConfigWithNoFeatureToggles_ParseFeatureToggles_ReturnsValidFeatureToggles)
{
  nlohmann::json config_json = nlohmann::json::parse(R"({})");
  nidevice_grpc::ServerConfigurationParser server_config_parser(config_json);

  auto features = server_config_parser.parse_feature_toggles();

  EXPECT_EQ(FeatureState::kUnspecified, features.get_feature_state("dummy_feature"));
}
}  // namespace unit
}  // namespace tests
}  // namespace ni
