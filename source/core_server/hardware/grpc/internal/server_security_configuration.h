#ifndef NI_HARDWARE_GRPC_INTERNAL_SERVER_SECURITY_CONFIGURATION_H_
#define NI_HARDWARE_GRPC_INTERNAL_SERVER_SECURITY_CONFIGURATION_H_

#include <grpcpp/grpcpp.h>

#include <string>

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

class ServerSecurityConfiguration {
 public:
  ServerSecurityConfiguration();
  ServerSecurityConfiguration(const std::string& server_cert, const std::string& server_key, const std::string& root_cert);

  std::shared_ptr<::grpc::ServerCredentials> get_credentials() const;
  const ::grpc::SslServerCredentialsOptions* ServerSecurityConfiguration::try_get_options() const;
  bool is_insecure_credentials() const;

 private:
  bool is_insecure_credentials_;
  ::grpc::SslServerCredentialsOptions credentials_options_;
  std::shared_ptr<::grpc::ServerCredentials> server_credentials_;
};

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni

#endif  // NI_HARDWARE_GRPC_INTERNAL_SERVER_SECURITY_CONFIGURATION_H_
