#ifndef NIDEVICE_GRPC_LINUX_SYSLOG_LOGGING_H
#define NIDEVICE_GRPC_LINUX_SYSLOG_LOGGING_H

#include "../logging.h"

namespace nidevice_grpc {

namespace Logging {

void setup_syslog(bool is_daemon);
void log_syslog(Level level, const char* fmt, va_list args);

} // namespace Logging
} // namespace nidevice_grpc

#endif // NIDEVICE_GRPC_LINUX_SYSLOG_LOGGING_H
