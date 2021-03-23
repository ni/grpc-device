#include "server_security_configuration.h"

#include <typeinfo>

namespace nidevice_grpc {

ServerSecurityConfiguration::ServerSecurityConfiguration()
    : ServerSecurityConfiguration("", "", "")
{
}

ServerSecurityConfiguration::ServerSecurityConfiguration(const std::string& server_cert, const std::string& server_key, const std::string& root_cert)
    : is_insecure_credentials_(server_cert.empty() || server_key.empty())
{
  if (is_insecure_credentials_) {
    server_credentials_ = ::grpc::InsecureServerCredentials();
    return;
  }

  ::grpc::SslServerCredentialsOptions::PemKeyCertPair key_cert_pair = {server_key, server_cert};
  credentials_options_.pem_key_cert_pairs.push_back(key_cert_pair);
  credentials_options_.client_certificate_request = root_cert.empty()
      ? GRPC_SSL_DONT_REQUEST_CLIENT_CERTIFICATE
      : GRPC_SSL_REQUEST_AND_REQUIRE_CLIENT_CERTIFICATE_AND_VERIFY;
  credentials_options_.pem_root_certs = root_cert;
  server_credentials_ = ::grpc::SslServerCredentials(credentials_options_);
}

std::shared_ptr<::grpc::ServerCredentials> ServerSecurityConfiguration::get_credentials() const
{
  return server_credentials_;
}

const ::grpc::SslServerCredentialsOptions* ServerSecurityConfiguration::try_get_options() const
{
  if (is_insecure_credentials_) {
    return nullptr;
  }
  return &credentials_options_;
}

bool ServerSecurityConfiguration::is_insecure_credentials() const
{
  return is_insecure_credentials_;
}

}  // namespace nidevice_grpc
