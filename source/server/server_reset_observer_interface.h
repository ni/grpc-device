#ifndef NIDEVICE_GRPC_SERVER_RESET_OBSERVER_INTERFACE_H
#define NIDEVICE_GRPC_SERVER_RESET_OBSERVER_INTERFACE_H

namespace nidevice_grpc {

class ServerResetObserverInterface {
 public:
  virtual ~ServerResetObserverInterface() {}

  virtual void on_server_reset() = 0;
};

}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_SERVER_RESET_OBSERVER_INTERFACE_H
