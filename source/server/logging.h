#ifndef NIDEVICE_GRPC_LOGGING_H
#define NIDEVICE_GRPC_LOGGING_H

#include <cstdarg>

namespace nidevice_grpc {
namespace logging {

enum Level {
  Level_Info = 0,
  Level_Warning,
  Level_Error,
};

typedef void (*log_fn_impl)(Level level, const char* fmt, va_list args);

// The logger defaults to the terminal (stdout and stderr)
void set_logger(log_fn_impl impl);
void log(Level level, const char* fmt, ...);

}  // namespace logging
}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_LOGGING_H
