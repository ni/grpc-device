#include "client_connection_logger.h"

#include "logging.h"

namespace nidevice_grpc {

namespace {

bool parse_peer(const std::string& peer, std::string& ip, std::string& port)
{
  if (peer.rfind("ipv4:", 0) != 0 && peer.rfind("ipv6:", 0) != 0)
    return false;

  const auto scheme_end = peer.find(':');
  const auto port_pos = peer.rfind(':');
  if (port_pos <= scheme_end)
    return false;

  ip = peer.substr(scheme_end + 1, port_pos - scheme_end - 1);
  port = peer.substr(port_pos + 1);

  // Strip ipv6 brackets, e.g. "[::1]" -> "::1".
  if (ip.size() >= 2 && ip.front() == '[' && ip.back() == ']')
    ip = ip.substr(1, ip.size() - 2);

  return !ip.empty() && !port.empty();
}

}

void ClientConnectionLogger::PreSynchronousRequest(grpc::ServerContext* context)
{
  const auto peer = context->peer();
  std::string ip, port;

  // Try to parse the IP + Port out of the peer uri so that the log message can be formatted nicely. If it fails, just log the raw string.
  if (parse_peer(peer, ip, port))
    nidevice_grpc::logging::log_to_audit_source(nidevice_grpc::logging::Level_Info, "Remote client successfully connected from %s:%s", ip.c_str(), port.c_str());
  else 
    nidevice_grpc::logging::log_to_audit_source(nidevice_grpc::logging::Level_Info, "Remote client successfully connected from %s", peer.c_str());
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
