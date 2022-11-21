#ifndef NIDEVICE_GRPC_DEVICE_ENUMERATOR_H
#define NIDEVICE_GRPC_DEVICE_ENUMERATOR_H

#include <grpcpp/grpcpp.h>
#include <nisyscfg.h>
#include <session.grpc.pb.h>
#include <session_utilities.grpc.pb.h>
#include <shared_mutex>

#include "syscfg_library_interface.h"
#include "syscfg_session_handler.h"

namespace nidevice_grpc {

static const char* kDeviceEnumerationFailedMessage = "The NI System Configuration API was unable to enumerate the devices.";

class DeviceEnumerator : public SysCfgSessionHandler {
 public:
  DeviceEnumerator(SysCfgLibraryInterface* library);
  virtual ~DeviceEnumerator();

  ::grpc::Status enumerate_devices(google::protobuf::RepeatedPtrField<DeviceProperties>* devices);
};

}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_DEVICE_ENUMERATOR_H
