#ifndef NIDEVICE_GRPC_LINUX_SYSLOG_LOGGING_H
#define NIDEVICE_GRPC_LINUX_SYSLOG_LOGGING_H

#include <string>

#include "../logging.h"

namespace nidevice_grpc {
namespace logging {

void setup_syslog(bool is_daemon, const std::string& identity);
void log_syslog(Level level, const char* fmt, va_list args);

}  // namespace logging
}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_LINUX_SYSLOG_LOGGING_H
