#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <server/server_security_configuration.h>

#include <typeinfo>

namespace ni {
namespace tests {
namespace unit {

static const char* kEmptyServerCertData = "";
static const char* kEmptyServerKeyData = "";
static const char* kEmptyRootCertData = "";

std::shared_ptr<::grpc::ServerCredentials> get_secure_credentials_comparison()
{
  return ::grpc::SslServerCredentials(::grpc::SslServerCredentialsOptions());
}

std::shared_ptr<::grpc::ServerCredentials> get_insecure_credentials_comparison()
{
  return ::grpc::InsecureServerCredentials();
}

TEST(ServerSecurityConfigurationTests, DefaultServerSecurityConfiguration_GetCredentials_InsecureServerCredentials)
{
  nidevice_grpc::ServerSecurityConfiguration server_security_config;

  auto credentials = server_security_config.get_credentials();

  EXPECT_TRUE(typeid(*get_insecure_credentials_comparison()) == typeid(*credentials));
  EXPECT_TRUE(server_security_config.is_insecure_credentials());
}

TEST(ServerSecurityConfigurationTests, ServerCertEmptyAndServerKeyNotEmpty_GetCredentials_InsecureServerCredentials)
{
  nidevice_grpc::ServerSecurityConfiguration server_security_config(kEmptyServerCertData, "server key data", kEmptyRootCertData);

  auto credentials = server_security_config.get_credentials();

  EXPECT_TRUE(typeid(*get_insecure_credentials_comparison()) == typeid(*credentials));
  EXPECT_TRUE(server_security_config.is_insecure_credentials());
}

TEST(ServerSecurityConfigurationTests, ServerCertNotEmptyAndServerKeyEmpty_GetCredentials_InsecureServerCredentials)
{
  nidevice_grpc::ServerSecurityConfiguration server_security_config("server cert data", kEmptyServerKeyData, kEmptyRootCertData);

  auto credentials = server_security_config.get_credentials();

  EXPECT_TRUE(typeid(*get_insecure_credentials_comparison()) == typeid(*credentials));
  EXPECT_TRUE(server_security_config.is_insecure_credentials());
}

TEST(ServerSecurityConfigurationTests, ServerCertAndKeyEmptyAndRootCertNotEmpty_GetCredentials_InsecureServerCredentials)
{
  nidevice_grpc::ServerSecurityConfiguration server_security_config(kEmptyServerCertData, kEmptyServerKeyData, "root cert data");

  auto credentials = server_security_config.get_credentials();

  EXPECT_TRUE(typeid(*get_insecure_credentials_comparison()) == typeid(*credentials));
  EXPECT_TRUE(server_security_config.is_insecure_credentials());
}

TEST(ServerSecurityConfigurationTests, ServerCertAndKeyNotEmpty_GetCredentials_SslServerCredentials)
{
  nidevice_grpc::ServerSecurityConfiguration server_security_config("server cert data", "server key data", kEmptyRootCertData);

  auto credentials = server_security_config.get_credentials();

  EXPECT_TRUE(typeid(*get_secure_credentials_comparison()) == typeid(*credentials));
  EXPECT_FALSE(server_security_config.is_insecure_credentials());
}

TEST(ServerSecurityConfigurationTests, ServerCertServerKeyAndRootCertNotEmpty_GetCredentials_SslServerCredentials)
{
  nidevice_grpc::ServerSecurityConfiguration server_security_config("server cert data", "server key data", "root cert data");

  auto credentials = server_security_config.get_credentials();

  EXPECT_TRUE(typeid(*get_secure_credentials_comparison()) == typeid(*credentials));
  EXPECT_FALSE(server_security_config.is_insecure_credentials());
}

TEST(ServerSecurityConfigurationTests, ServerCertServerKeyAndRootCertEmpty_TryGetOptions_Unsuccessful)
{
  nidevice_grpc::ServerSecurityConfiguration server_security_config(kEmptyServerCertData, kEmptyServerKeyData, kEmptyRootCertData);

  auto credentials_options = server_security_config.try_get_options();

  EXPECT_EQ(nullptr, credentials_options);
}

TEST(ServerSecurityConfigurationTests, ServerCertServerKeyAndRootCertNotEmpty_TryGetOptions_RequestsAndVerifiesClientCertificate)
{
  nidevice_grpc::ServerSecurityConfiguration server_security_config("server cert data", "server key data", "root cert data");

  auto credentials_options = server_security_config.try_get_options();

  EXPECT_NE(nullptr, credentials_options);
  EXPECT_EQ(GRPC_SSL_REQUEST_AND_REQUIRE_CLIENT_CERTIFICATE_AND_VERIFY, credentials_options->client_certificate_request);
  EXPECT_FALSE(credentials_options->pem_key_cert_pairs.empty());
  EXPECT_FALSE(credentials_options->pem_root_certs.empty());
}

TEST(ServerSecurityConfigurationTests, ServerCertAndKeyNotEmptyAndRootCertEmpty_TryGetOptions_DoesNotRequestClientCertificate)
{
  nidevice_grpc::ServerSecurityConfiguration server_security_config("server cert data", "server key data", kEmptyRootCertData);

  auto credentials_options = server_security_config.try_get_options();

  EXPECT_NE(nullptr, credentials_options);
  EXPECT_EQ(GRPC_SSL_DONT_REQUEST_CLIENT_CERTIFICATE, credentials_options->client_certificate_request);
  EXPECT_FALSE(credentials_options->pem_key_cert_pairs.empty());
  EXPECT_TRUE(credentials_options->pem_root_certs.empty());
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
