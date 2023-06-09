#include "console_ctrl_handler.h"

#include "../logging.h"

#include <string>
#include <Windows.h>

namespace nidevice_grpc {

static stop_callback signal_stop = nullptr;

static BOOL WINAPI console_ctrl_handler(DWORD dwCtrlType)
{
  const char* signal_description = "?";
  switch (dwCtrlType)
  {
  case CTRL_C_EVENT:
    signal_description = "ctrl-c";
    break;
  case CTRL_BREAK_EVENT:
    signal_description = "ctrl-break";
    break;
  case CTRL_CLOSE_EVENT:
    signal_description = "close";
    break;
  case CTRL_LOGOFF_EVENT:
    signal_description = "logoff";
    break;
  case CTRL_SHUTDOWN_EVENT:
    signal_description = "shutdown";
    break;
  default:
    break;
  }

  logging::log(logging::Level_Info, "Received %s signal, stopping server.", signal_description);
  if (signal_stop) {
    signal_stop();

    // Wait up to 10 seconds for the server to stop. When either main() or this handler returns,
    // the process will exit.
    Sleep(10000);
  }
  return TRUE;
}

static std::string get_error_message(DWORD error)
{
  char buffer[1024] = "";
  if (!FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, nullptr, error, 0, buffer, sizeof(buffer), nullptr)) {
    return "unknown Win32 error " + std::to_string(error);
  }
  return buffer;
}

void set_console_ctrl_handler(stop_callback signal_stop_)
{
  signal_stop = signal_stop_;
  if (!SetConsoleCtrlHandler(&console_ctrl_handler, TRUE /*Add*/)) {
    DWORD error = GetLastError();
    logging::log(logging::Level_Error, "Failed to register console control handler: %s",
      get_error_message(error).c_str());
  }
}

}  // namespace nidevice_grpc
