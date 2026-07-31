#include "logging.h"

#include <cstdio>
#include <iostream>
#include <string>

#if defined(_WIN32)
  #include <memory>

  #include <spdlog/sinks/win_eventlog_sink.h>
  #include <spdlog/spdlog.h>
#else
  #include "linux/syslog_logging.h"
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

#if defined(_WIN32)
namespace {

std::shared_ptr<spdlog::logger> get_event_log_logger()
{
  static std::shared_ptr<spdlog::logger> audit_logger = []() {
    auto sink = std::make_shared<spdlog::sinks::win_eventlog_sink_mt>("ni-grpc-device-server");
    auto logger = std::make_shared<spdlog::logger>("Server", sink);
    logger->set_pattern("[ni-grpc-device-server][%n] %v");
    return logger;
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

}  // namespace
#endif

void log_to_audit_source(Level level, const char* fmt, ...)
{
#if defined(_WIN32)
  va_list args;
  va_start(args, fmt);
  const std::string message = format_message(fmt, args);
  va_end(args);

  auto audit_logger = get_event_log_logger();
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
#else
  // We're manually prefixing audit logs in the Windows spdlog path, so manually add it here on the Linux path before sending it over to syslog.
  const std::string message = "[ni-grpc-device-server][Server] " + std::string(fmt);

  va_list args;
  va_start(args, fmt);
  log_syslog(level, message.c_str(), args);
  va_end(args);
#endif
}

}  // namespace logging
}  // namespace nidevice_grpc
