#ifndef NIDEVICE_GRPC_SERVER_RESET_OBSERVER_REGISTRAR_INTERFACE_H
#define NIDEVICE_GRPC_SERVER_RESET_OBSERVER_REGISTRAR_INTERFACE_H

#include "server_reset_observer_interface.h"

namespace nidevice_grpc {

class ServerResetObserverRegistrarInterface {
 public:
  virtual ~ServerResetObserverRegistrarInterface() {}

  virtual void register_observer(ServerResetObserverInterface* observer) = 0;
  virtual void unregister_observer(ServerResetObserverInterface* observer) = 0;
};

}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_SERVER_RESET_OBSERVER_REGISTRAR_INTERFACE_H
