#ifndef NIDEVICE_GRPC_SERVER_SECURITY_CONFIGURATION_H
#define NIDEVICE_GRPC_SERVER_SECURITY_CONFIGURATION_H

#include <grpcpp/grpcpp.h>

#include <string>

namespace nidevice_grpc {

class ServerSecurityConfiguration {
 public:
  ServerSecurityConfiguration();
  ServerSecurityConfiguration(const std::string& server_cert, const std::string& server_key, const std::string& root_cert);

  std::shared_ptr<::grpc::ServerCredentials> get_credentials() const;
  const ::grpc::SslServerCredentialsOptions* try_get_options() const;
  bool is_insecure_credentials() const;

 private:
  bool is_insecure_credentials_;
  ::grpc::SslServerCredentialsOptions credentials_options_;
  std::shared_ptr<::grpc::ServerCredentials> server_credentials_;
};

}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_SERVER_SECURITY_CONFIGURATION_H
