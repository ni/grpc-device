#ifndef NIDEVICE_GRPC_CLIENT_CONNECTION_LOGGER_H
#define NIDEVICE_GRPC_CLIENT_CONNECTION_LOGGER_H

#include <grpcpp/grpcpp.h>

#include <mutex>
#include <string>
#include <unordered_set>

namespace nidevice_grpc {

// Implementation of callbacks that the grpc::Server will invoke for individual client RPC calls.
class ClientConnectionLogger : public grpc::Server::GlobalCallbacks {
 public:
  void PreSynchronousRequest(grpc::ServerContext* context) override;
  void PostSynchronousRequest(grpc::ServerContext* context) override;

 private:
  std::mutex seen_ips_mutex_;
  std::unordered_set<std::string> seen_ips_;
};

// Registers a process-wide ClientConnectionLogger with gRPC, must be called before any grpc::Server is built.
void register_client_connection_logger();

}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_CLIENT_CONNECTION_LOGGER_H
