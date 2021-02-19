#ifndef NI_HARDWARE_GRPC_INTERNAL_SERVERSECURITYCONFIGURATION
#define NI_HARDWARE_GRPC_INTERNAL_SERVERSECURITYCONFIGURATION

#include <string>
#include <grpcpp/grpcpp.h>

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

class ServerSecurityConfiguration {
 public:
  ServerSecurityConfiguration();
  ServerSecurityConfiguration(const std::string& server_cert, const std::string& server_key, const std::string& root_cert);

  std::shared_ptr<::grpc::ServerCredentials> get_credentials();
  bool try_get_options(::grpc::SslServerCredentialsOptions* options);

 private:
  ::grpc::SslServerCredentialsOptions security_configuration_;
  std::shared_ptr<::grpc::ServerCredentials> server_credential_options_;
};

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni

#endif  // NI_HARDWARE_GRPC_INTERNAL_SERVERSECURITYCONFIGURATION
