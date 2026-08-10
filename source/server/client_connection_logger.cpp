#include "client_connection_logger.h"
#include "logging.h"

#include <grpc/grpc_security_constants.h>

namespace nidevice_grpc {

namespace {

std::string describe_authentication(const grpc::AuthContext& auth_context)
{
  if (!auth_context.IsPeerAuthenticated())
    return "Unauthenticated";

  const auto transport_type = auth_context.FindPropertyValues(GRPC_TRANSPORT_SECURITY_TYPE_PROPERTY_NAME);
  const auto common_names = auth_context.FindPropertyValues(GRPC_X509_CN_PROPERTY_NAME);

  std::string description = "Authenticated via ";
  description += transport_type.empty() ? "unknown transport" : std::string(transport_type[0].data(), transport_type[0].size());

  if (!common_names.empty())
    description += ", client cert CN:" + std::string(common_names[0].data(), common_names[0].size());

  return description;
}

}

bool parse_peer(const std::string& peer, std::string& ip, std::string& port)
{
  if (peer.rfind("ipv4:", 0) != 0 && peer.rfind("ipv6:", 0) != 0)
    return false;

  const auto scheme_end = peer.find(':');
  const auto addr_start = scheme_end + 1;
  if (scheme_end == std::string::npos)
    return false;

  // Find the start of the port; IPv6 addresses are enclosed in brackets, so we need to find the closing bracket first.
  size_t port_pos;
  if (peer[addr_start] == '[') {
    const auto bracket_end = peer.find(']', addr_start);
    if (bracket_end == std::string::npos)
      return false;
    port_pos = bracket_end + 1;
    if (port_pos >= peer.size() || peer[port_pos] != ':')
      return false;
  }
  else {
    port_pos = peer.rfind(':');
    if (port_pos <= scheme_end)
      return false;
  }

  ip = peer.substr(addr_start, port_pos - addr_start);
  port = peer.substr(port_pos + 1);

  return !ip.empty() && !port.empty();
}

void ClientConnectionLogger::PreSynchronousRequest(grpc::ServerContext* context)
{
  std::string ip, port;
  const auto peer = context->peer();
  const bool parsed = parse_peer(peer, ip, port);

  // Only log the first connection seen from a given IP.
  {
    const auto& key = parsed ? ip : peer;
    std::lock_guard<std::mutex> lock(seen_ips_mutex_);
    if (!seen_ips_.insert(key).second)
      return;

    // If the client cache is full, evict the oldest entry.
    seen_ips_order_.push_back(key);
    if (seen_ips_order_.size() > kMaxSeenIps) {
      seen_ips_.erase(seen_ips_order_.front());
      seen_ips_order_.pop_front();
    }
  }

  const auto auth_description = describe_authentication(*context->auth_context());

  // Try to parse the IP + Port out of the peer uri so that the log message can be formatted nicely. If it fails, just log the raw string.
  if (parsed)
    nidevice_grpc::logging::log_to_audit_source(nidevice_grpc::logging::Level_Info, "Remote client successfully connected from %s:%s (%s)", ip.c_str(), port.c_str(), auth_description.c_str());
  else 
    nidevice_grpc::logging::log_to_audit_source(nidevice_grpc::logging::Level_Info, "Remote client successfully connected from %s (%s)", peer.c_str(), auth_description.c_str());
}

void ClientConnectionLogger::PostSynchronousRequest(grpc::ServerContext*)
{
}

void register_client_connection_logger()
{
  // gRPC stores this in an owning shared_ptr (see Server::SetGlobalCallbacks inserver_cc.cc) and deletes it at static destruction. Even
  // if that changes to non-owning, intentionally leaking one process-wide object is correct and avoids a static-destruction-order hazard
  // against grpc::Server.
  grpc::Server::SetGlobalCallbacks(new ClientConnectionLogger());
}

}  // namespace nidevice_grpc
