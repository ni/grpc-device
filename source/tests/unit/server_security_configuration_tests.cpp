#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <typeinfo>

#include "hardware/grpc/internal/server_security_configuration.h"

namespace internal = ni::hardware::grpc::internal;

namespace ni {
namespace tests {
namespace unit {

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
  ::internal::ServerSecurityConfiguration server_security_config;

  auto credentials = server_security_config.get_credentials();

  EXPECT_TRUE(typeid(*get_insecure_credentials_comparison()) == typeid(*credentials));
  EXPECT_TRUE(server_security_config.is_insecure_credentials());
}

TEST(ServerSecurityConfigurationTests, ServerCertEmptyAndServerKeyNotEmpty_GetCredentials_InsecureServerCredentials)
{
  ::internal::ServerSecurityConfiguration server_security_config("", "server key data", "");

  auto credentials = server_security_config.get_credentials();

  EXPECT_TRUE(typeid(*get_insecure_credentials_comparison()) == typeid(*credentials));
  EXPECT_TRUE(server_security_config.is_insecure_credentials());
}

TEST(ServerSecurityConfigurationTests, ServerCertNotEmptyAndServerKeyEmpty_GetCredentials_InsecureServerCredentials)
{
  ::internal::ServerSecurityConfiguration server_security_config("server cert data", "", "");

  auto credentials = server_security_config.get_credentials();

  EXPECT_TRUE(typeid(*get_insecure_credentials_comparison()) == typeid(*credentials));
  EXPECT_TRUE(server_security_config.is_insecure_credentials());
}

TEST(ServerSecurityConfigurationTests, ServerCertAndKeyEmptyAndRootCertNotEmpty_GetCredentials_InsecureServerCredentials)
{
  ::internal::ServerSecurityConfiguration server_security_config("", "", "root cert data");

  auto credentials = server_security_config.get_credentials();

  EXPECT_TRUE(typeid(*get_insecure_credentials_comparison()) == typeid(*credentials));
  EXPECT_TRUE(server_security_config.is_insecure_credentials());
}

TEST(ServerSecurityConfigurationTests, ServerCertAndKeyNotEmpty_GetCredentials_SslServerCredentials)
{
  ::internal::ServerSecurityConfiguration server_security_config("server cert data", "server key data", "");

  auto credentials = server_security_config.get_credentials();

  EXPECT_TRUE(typeid(*get_secure_credentials_comparison()) == typeid(*credentials));
  EXPECT_FALSE(server_security_config.is_insecure_credentials());
}

TEST(ServerSecurityConfigurationTests, ServerCertServerKeyAndRootCertNotEmpty_GetCredentials_SslServerCredentials)
{
  ::internal::ServerSecurityConfiguration server_security_config("server cert data", "server key data", "root cert data");

  auto credentials = server_security_config.get_credentials();

  EXPECT_TRUE(typeid(*get_secure_credentials_comparison()) == typeid(*credentials));
  EXPECT_FALSE(server_security_config.is_insecure_credentials());
}

TEST(ServerSecurityConfigurationTests, ServerCertServerKeyAndRootCertEmpty_TryGetOptions_Unsuccessful)
{
  ::internal::ServerSecurityConfiguration server_security_config("", "", "");
  ::grpc::SslServerCredentialsOptions credentials_options_;

  auto is_successful = server_security_config.try_get_options(&credentials_options_);

  EXPECT_FALSE(is_successful);
}

TEST(ServerSecurityConfigurationTests, ServerCertServerKeyAndRootCertNotEmpty_TryGetOptions_Successful)
{
  ::internal::ServerSecurityConfiguration server_security_config("server cert data", "server key data", "root cert data");
  ::grpc::SslServerCredentialsOptions credentials_options_;

  auto is_successful = server_security_config.try_get_options(&credentials_options_);

  EXPECT_TRUE(is_successful);
}

TEST(ServerSecurityConfigurationTests, ServerCertAndKeyNotEmptyAndRootCertEmpty_TryGetOptions_DoesNotRequestClientCertificate)
{
  ::internal::ServerSecurityConfiguration server_security_config("server cert data", "server key data", "");
  ::grpc::SslServerCredentialsOptions credentials_options_;

  auto is_successful = server_security_config.try_get_options(&credentials_options_);

  EXPECT_TRUE(is_successful);
  EXPECT_EQ(GRPC_SSL_DONT_REQUEST_CLIENT_CERTIFICATE, credentials_options_.client_certificate_request);
}

TEST(ServerSecurityConfigurationTests, ServerCertServerKeyAndRootCertNotEmpty_TryGetOptions_RequestsAndVerifiesClientCertificate)
{
  ::internal::ServerSecurityConfiguration server_security_config("server cert data", "server key data", "root cert data");
  ::grpc::SslServerCredentialsOptions credentials_options_;

  auto is_successful = server_security_config.try_get_options(&credentials_options_);

  EXPECT_TRUE(is_successful);
  EXPECT_EQ(GRPC_SSL_REQUEST_AND_REQUIRE_CLIENT_CERTIFICATE_AND_VERIFY, credentials_options_.client_certificate_request);
}

TEST(ServerSecurityConfigurationTests, ServerCertAndKeyNotEmptyAndRootCertEmpty_TryGetOptions_PemCertPairsNotEmptyAndPemRootCertsEmpty)
{
  ::internal::ServerSecurityConfiguration server_security_config("server cert data", "server key data", "");
  ::grpc::SslServerCredentialsOptions credentials_options_;

  auto is_successful = server_security_config.try_get_options(&credentials_options_);

  EXPECT_TRUE(is_successful);
  EXPECT_FALSE(credentials_options_.pem_key_cert_pairs.empty());
  EXPECT_TRUE(credentials_options_.pem_root_certs.empty());
}

TEST(ServerSecurityConfigurationTests, ServerCertServerKeyAndRootCertNotEmpty_TryGetOptions_PemCertPairsAndPemRootCertsNotEmpty)
{
  ::internal::ServerSecurityConfiguration server_security_config("server cert data", "server key data", "root cert data");
  ::grpc::SslServerCredentialsOptions credentials_options_;

  auto is_successful = server_security_config.try_get_options(&credentials_options_);

  EXPECT_TRUE(is_successful);
  EXPECT_FALSE(credentials_options_.pem_key_cert_pairs.empty());
  EXPECT_FALSE(credentials_options_.pem_root_certs.empty());
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
