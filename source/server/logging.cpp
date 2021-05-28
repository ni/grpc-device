#include "logging.h"

#include <cstdio>
#include <iostream>

namespace nidevice_grpc {
namespace logging {

void log_terminal(Level level, const char* fmt, va_list args)
{
  switch (level) {
    case Level_Info:
    // explicit fall-through
    case Level_Warning:
      vfprintf(stdout, fmt, args);
      std::cout << std::endl;
      break;
    case Level_Error:
      vfprintf(stderr, fmt, args);
      std::cerr << std::endl;
      break;
  }
}

static log_fn_impl logger = &log_terminal;

void set_logger(log_fn_impl impl)
{
  logger = impl;
}

void log(Level level, const char* fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  logger(level, fmt, args);
  va_end(args);
}

}  // namespace logging
}  // namespace nidevice_grpc
