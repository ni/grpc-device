#ifndef NIDEVICE_GRPC_CLIENT_CONNECTION_LOGGER_H
#define NIDEVICE_GRPC_CLIENT_CONNECTION_LOGGER_H

#include <grpcpp/grpcpp.h>

#include <cstddef>
#include <deque>
#include <mutex>
#include <string>
#include <unordered_set>

namespace nidevice_grpc {

// Parses a gRPC peer URI (e.g. "ipv4:127.0.0.1:12345" or "ipv6:[::1]:12345") into its ip and port components.
// Returns false if the peer string doesn't match a recognized format.
bool parse_peer(const std::string& peer, std::string& ip, std::string& port);

// Implementation of callbacks that the grpc::Server will invoke for individual client RPC calls.
class ClientConnectionLogger : public grpc::Server::GlobalCallbacks {
 public:
  void PreSynchronousRequest(grpc::ServerContext* context) override;
  void PostSynchronousRequest(grpc::ServerContext* context) override;

 private:
  // We cache a set number of seen clients to avoid noise from repeated calls
  static constexpr std::size_t kMaxSeenIps = 3000;

  std::mutex seen_ips_mutex_;
  std::unordered_set<std::string> seen_ips_;
  std::deque<std::string> seen_ips_order_;
};

// Registers a process-wide ClientConnectionLogger with gRPC, must be called before any grpc::Server is built.
void register_client_connection_logger();

}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_CLIENT_CONNECTION_LOGGER_H
