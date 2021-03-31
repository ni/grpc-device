#ifndef NIDEVICE_GRPC_DEVICE_ENUMERATOR_H
#define NIDEVICE_GRPC_DEVICE_ENUMERATOR_H

#include <grpcpp/grpcpp.h>
#include <nisyscfg.h>
#include <session.grpc.pb.h>
#include <shared_mutex>

#include "shared_library.h"
#include "syscfg_library_interface.h"

namespace nidevice_grpc {

static const char* kDeviceEnumerationFailedMessage = "The NI System Configuration API was unable to enumerate the devices.";
static const char* kLocalHostTargetName = "localhost";
static const char* kNetworkExpertName = "network";
static const int kConnectionTimeoutMilliSec = 10000;

class DeviceEnumerator {
 public:
  DeviceEnumerator(SysCfgLibraryInterface* library);
  virtual ~DeviceEnumerator();

  ::grpc::Status enumerate_devices(google::protobuf::RepeatedPtrField<DeviceProperties>* devices);
  NISysCfgStatus open_or_get_localhost_syscfg_session(NISysCfgSessionHandle* session);
  void clear_syscfg_session();
  bool is_session_open();

 private:
  SysCfgLibraryInterface* library_;
  std::shared_mutex session_mutex_;
  NISysCfgSessionHandle syscfg_session_;
};

}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_DEVICE_ENUMERATOR_H
