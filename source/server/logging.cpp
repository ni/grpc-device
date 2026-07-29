#include "logging.h"

#include <cstdio>
#include <iostream>
#include <memory>
#include <string>

#include <spdlog/spdlog.h>
#if defined(_WIN32)
  #include <spdlog/sinks/win_eventlog_sink.h>
#else
  #include <spdlog/sinks/syslog_sink.h>
#endif

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

namespace {

std::shared_ptr<spdlog::logger> get_audit_logger()
{
  static std::shared_ptr<spdlog::logger> audit_logger = []() {
#if defined(_WIN32)
    auto sink = std::make_shared<spdlog::sinks::win_eventlog_sink_mt>("ni-grpc-device-server");
#else
    auto sink = std::make_shared<spdlog::sinks::syslog_sink_mt>("ni-grpc-device-server", LOG_PID, LOG_USER, /*enable_formatting=*/true);
#endif
    return std::make_shared<spdlog::logger>("audit", sink);
  }();
  return audit_logger;
}

std::string format_message(const char* fmt, va_list args)
{
  va_list args_copy;
  va_copy(args_copy, args);
  const int size = std::vsnprintf(nullptr, 0, fmt, args_copy);
  va_end(args_copy);
  if (size <= 0) {
    return std::string();
  }
  std::string result(static_cast<size_t>(size), '\0');
  std::vsnprintf(&result[0], result.size() + 1, fmt, args);
  return result;
}

}

void log_to_audit_source(Level level, const char* fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  const std::string message = format_message(fmt, args);
  va_end(args);

  auto audit_logger = get_audit_logger();
  switch (level) {
    case Level_Info:
      audit_logger->info("{}", message);
      break;
    case Level_Warning:
      audit_logger->warn("{}", message);
      break;
    case Level_Error:
      audit_logger->error("{}", message);
      break;
  }
}

}  // namespace logging
}  // namespace nidevice_grpc
