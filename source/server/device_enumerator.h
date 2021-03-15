#ifndef GRPC_NIDEVICE_DEVICEENUMERATOR
#define GRPC_NIDEVICE_DEVICEENUMERATOR

#include <grpcpp/grpcpp.h>
#include <nisyscfg.h>
#include <session.grpc.pb.h>

#include "shared_library.h"
#include "syscfg_library_interface.h"
#include <shared_mutex>

namespace grpc {
namespace nidevice {

static const char* kDeviceEnumerationFailedMessage = "The NI System Configuration API was unable to enumerate the devices";
static const char* kSysCfgLibraryLoadFailedMessage = "SysCfg Library load failed";
static const char* kLocalHostTargetName = "localhost";
static const char* kNetworkExpertName = "network";

class DeviceEnumerator {
 public:
  DeviceEnumerator(SysCfgLibraryInterface* library);
  virtual ~DeviceEnumerator();

  ::grpc::Status enumerate_devices(google::protobuf::RepeatedPtrField<DeviceProperties>* devices);

  NISysCfgSessionHandle get_syscfg_session(bool reinitialize = false);
  void clear_sysconfig_session();

 private:
  SysCfgLibraryInterface* library_;

  std::shared_mutex session_mutex;
  NISysCfgSessionHandle cached_syscfg_session;
};

}  // namespace nidevice
}  // namespace grpc

#endif  // GRPC_NIDEVICE_DEVICEENUMERATOR
