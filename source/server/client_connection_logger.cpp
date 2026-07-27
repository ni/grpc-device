#include "client_connection_logger.h"

#include <mutex>
#include <unordered_set>

#include "logging.h"

namespace nidevice_grpc {

namespace {
std::mutex g_seen_peers_mutex;
std::unordered_set<std::string> g_seen_peers;
}

void ClientConnectionLogger::PreSynchronousRequest(grpc::ServerContext* context)
{
  const auto peer = context->peer();
  bool is_new_connection = false;
  {
    // Use a set to track peers that have already been seen.
    std::lock_guard<std::mutex> guard(g_seen_peers_mutex);
    is_new_connection = g_seen_peers.insert(peer).second;
  }

  // Log only if this is the first time we've seen this peer - this is to reduce noise as this callback
  // fires for every RPC call.
  if (is_new_connection)
    nidevice_grpc::logging::log_to_audit_source(nidevice_grpc::logging::Level_Info, "Client connected from %s", peer.c_str());
}

void ClientConnectionLogger::PostSynchronousRequest(grpc::ServerContext*)
{
}

void register_client_connection_logger()
{
  // gRPC does not take ownership of the callbacks object, so it will be a static object.
  static ClientConnectionLogger logger;
  grpc::Server::SetGlobalCallbacks(&logger);
}

}  // namespace nidevice_grpc
