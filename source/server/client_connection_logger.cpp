#include "client_connection_logger.h"
#include "logging.h"

#include <absl/log/globals.h>
#include <absl/log/initialize.h>
#include <absl/log/log_entry.h>
#include <absl/log/log_sink.h>
#include <absl/log/log_sink_registry.h>
#include <absl/strings/match.h>

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
    description += ", client cert CN: " + std::string(common_names[0].data(), common_names[0].size());

  return description;
}

} // namespace

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
    if (bracket_end == std::string::npos || bracket_end == addr_start + 1)
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

namespace {

// Converts absl's severity levels to our own.
logging::Level to_logging_level(absl::LogSeverity severity)
{
  switch (severity) {
    case absl::LogSeverity::kWarning:
      return logging::Level_Warning;
    case absl::LogSeverity::kError:
    case absl::LogSeverity::kFatal:
      return logging::Level_Error;
    case absl::LogSeverity::kInfo:
    default:
      return logging::Level_Info;
  }
}

// This sink captures gRPC's own internal logs and calls Send for each of them. We only use it to log handshake failures.
class AuditLogSinkWrapper {
  public:
    AuditLogSinkWrapper() {
      absl::InitializeLog();
      absl::AddLogSink(&sink_);
    }
    ~AuditLogSinkWrapper() {
      absl::RemoveLogSink(&sink_);
    }

    // Disable copy/move constructors and assignment operators.
    AuditLogSinkWrapper(const AuditLogSinkWrapper&) = delete;
    AuditLogSinkWrapper& operator=(const AuditLogSinkWrapper&) = delete;
    AuditLogSinkWrapper(AuditLogSinkWrapper&&) = delete;
    AuditLogSinkWrapper& operator=(AuditLogSinkWrapper&&) = delete;

  private:
    class AuditLogSink : public absl::LogSink {
    public:
      void Send(const absl::LogEntry& entry) override
      {
        if (!absl::StrContainsIgnoreCase(entry.text_message(), "handshake"))
          return;

        const auto message = std::string(entry.text_message());
        logging::log_to_audit_source(to_logging_level(entry.log_severity()), "%s", message.c_str());
      }
    };

    AuditLogSink sink_;
};

} // namespace

void register_grpc_log_sink()
{
  // The wrapper handles adding and removing the log sink from absl.
  static AuditLogSinkWrapper sink;
}

}  // namespace nidevice_grpc
