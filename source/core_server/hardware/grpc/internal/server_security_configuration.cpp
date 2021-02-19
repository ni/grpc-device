#include "server_security_configuration.h"

#include <typeinfo>

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

  ServerSecurityConfiguration::ServerSecurityConfiguration()
  {
  }

  ServerSecurityConfiguration::ServerSecurityConfiguration(const std::string& server_cert, const std::string& server_key, const std::string& root_cert)
  {
    if (server_cert.empty()) {
      server_credential_options_ = ::grpc::InsecureServerCredentials();
    }
    
    ::grpc::SslServerCredentialsOptions::PemKeyCertPair key_cert_pair;
    key_cert_pair.private_key = server_key;
    key_cert_pair.cert_chain = server_cert;
    security_configuration_.pem_key_cert_pairs.push_back(key_cert_pair);

    security_configuration_.client_certificate_request = root_cert.empty()
      ? GRPC_SSL_DONT_REQUEST_CLIENT_CERTIFICATE 
      : GRPC_SSL_REQUEST_AND_REQUIRE_CLIENT_CERTIFICATE_AND_VERIFY;

    security_configuration_.pem_root_certs = root_cert;

    server_credential_options_ = ::grpc::SslServerCredentials(security_configuration_);
  }

  std::shared_ptr<::grpc::ServerCredentials> ServerSecurityConfiguration::get_credentials()
  {
    return server_credential_options_;
  }

  bool ServerSecurityConfiguration::try_get_options(::grpc::SslServerCredentialsOptions* options)
  {
    if (typeid(server_credential_options_) == typeid(::grpc::InsecureServerCredentials)) {
      return false;
    }
    *options = security_configuration_;
    return true;
  }
}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni
