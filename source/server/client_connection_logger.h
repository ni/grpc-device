#ifndef NIDEVICE_GRPC_CLIENT_CONNECTION_LOGGER_H
#define NIDEVICE_GRPC_CLIENT_CONNECTION_LOGGER_H

#include <grpcpp/grpcpp.h>

#include <string>

namespace nidevice_grpc {

// Implementation of callbacks that the grpc::Server will invoke for individual client RPC calls.
class ClientConnectionLogger : public grpc::Server::GlobalCallbacks {
 public:
  void PreSynchronousRequest(grpc::ServerContext* context) override;
  void PostSynchronousRequest(grpc::ServerContext* context) override;
};

// Registers a process-wide ClientConnectionLogger with gRPC, must be called before any grpc::Server is built.
void register_client_connection_logger();

// Registers an absl::LogSink that captures all of gRPC's internal log messages; used for logging connection failures
void register_grpc_log_sink();

}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_CLIENT_CONNECTION_LOGGER_H
