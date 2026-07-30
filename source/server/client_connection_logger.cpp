#include "client_connection_logger.h"

#include <absl/log/globals.h>
#include <absl/log/initialize.h>
#include <absl/log/log_entry.h>
#include <absl/log/log_sink.h>
#include <absl/log/log_sink_registry.h>
#include <absl/strings/match.h>

#include "logging.h"

namespace nidevice_grpc {

namespace {

// Gets the IP + Port from a gRPC peer uri.
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

}  // namespace

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

void register_grpc_log_sink()
{
  absl::InitializeLog();

  // By default we will not log anything less severe than a warning.
  absl::SetMinLogLevel(absl::LogSeverityAtLeast::kWarning);

  // Abseil does not take ownership of the sink, so it will be a static object.
  static AuditLogSink sink;
  absl::AddLogSink(&sink);
}

}  // namespace nidevice_grpc
