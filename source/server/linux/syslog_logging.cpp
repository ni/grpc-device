#include "syslog_logging.h"

#include <syslog.h>

namespace nidevice_grpc {
namespace logging {

void setup_syslog(bool is_daemon, const std::string& identity)
{
  int syslog_options = LOG_PID;
  int syslog_facility = 0;
  if (is_daemon) {
    syslog_facility = LOG_DAEMON;
  }
  else {
    // It's OK to fall back to the console if we're not a daemon.
    syslog_options |= LOG_CONS;
    syslog_facility |= LOG_USER;
  }
  openlog(identity.c_str(), syslog_options, syslog_facility);
}

void log_syslog(Level level, const char* fmt, va_list args)
{
  int priority;
  switch (level) {
    case Level_Info:
      priority = LOG_INFO;
      break;
    case Level_Warning:
      priority = LOG_WARNING;
      break;
    case Level_Error:
      priority = LOG_ERR;
      break;
  }
  vsyslog(priority, fmt, args);
}

}  // namespace logging
}  // namespace nidevice_grpc
