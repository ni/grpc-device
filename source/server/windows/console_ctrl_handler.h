#ifndef NIDEVICE_GRPC_WINDOWS_SET_CONSOLE_CTRL_HANDLER_H
#define NIDEVICE_GRPC_WINDOWS_SET_CONSOLE_CTRL_HANDLER_H

namespace nidevice_grpc {

typedef void (*stop_callback)();

void set_console_ctrl_handler(stop_callback stop);

}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_WINDOWS_SET_CONSOLE_CTRL_HANDLER_H

