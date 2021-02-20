#include "server_security_configuration.h"

#include <typeinfo>

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

ServerSecurityConfiguration::ServerSecurityConfiguration()
    : ServerSecurityConfiguration("", "", "")
{
}

ServerSecurityConfiguration::ServerSecurityConfiguration(const std::string& server_cert, const std::string& server_key, const std::string& root_cert)
  : kIsInsecureCredentials(server_cert.empty() || server_key.empty())
{
  if (kIsInsecureCredentials) {
    server_credentials_ = ::grpc::InsecureServerCredentials();
    return;
  }

  ::grpc::SslServerCredentialsOptions::PemKeyCertPair key_cert_pair  = { server_key, server_cert };
  credentials_options_.pem_key_cert_pairs.push_back(key_cert_pair);
  credentials_options_.client_certificate_request = root_cert.empty()
                                                        ? GRPC_SSL_DONT_REQUEST_CLIENT_CERTIFICATE
                                                        : GRPC_SSL_REQUEST_AND_REQUIRE_CLIENT_CERTIFICATE_AND_VERIFY;
  credentials_options_.pem_root_certs = root_cert;
  server_credentials_ = ::grpc::SslServerCredentials(credentials_options_);
}

std::shared_ptr<::grpc::ServerCredentials> ServerSecurityConfiguration::get_credentials()
{
  return server_credentials_;
}

bool ServerSecurityConfiguration::try_get_options(::grpc::SslServerCredentialsOptions* credentials_options)
{
  if (kIsInsecureCredentials) {
    return false;
  }
  *credentials_options = credentials_options_;
  return true;
}

bool ServerSecurityConfiguration::is_insecure_credentials()
{
  return kIsInsecureCredentials;
}
}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni
