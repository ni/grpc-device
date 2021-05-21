#include "syslog_logging.h"

#include <syslog.h>

namespace nidevice_grpc {
namespace Logging {

static const char* syslog_identity = "ni_grpc_server";

void setup_syslog(bool is_daemon)
{
  int syslog_options = LOG_PID;
  int syslog_facility = 0;
  if (is_daemon) {
    syslog_facility = LOG_DAEMON;
  } else {
    // It's OK to fall back to the console if we're not a daemon.
    syslog_options |= LOG_CONS;
    syslog_facility |= LOG_USER;
  }
  openlog(syslog_identity, syslog_options, syslog_facility);
}

void log_syslog(Level level, const char* fmt, va_list args)
{
  int priority;
  switch (level)
  {
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

} // Logging
} // nidevice_grpc

