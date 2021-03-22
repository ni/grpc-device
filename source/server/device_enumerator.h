#ifndef GRPC_NIDEVICE_DEVICEENUMERATOR
#define GRPC_NIDEVICE_DEVICEENUMERATOR

#include <grpcpp/grpcpp.h>
#include <nisyscfg.h>
#include <session.grpc.pb.h>
#include <shared_mutex>
#include "shared_library.h"
#include "syscfg_library_interface.h"

namespace grpc {
namespace nidevice {

static const char* kDeviceEnumerationFailedMessage = "The NI System Configuration API was unable to enumerate the devices";
static const char* kLocalHostTargetName = "localhost";
static const char* kNetworkExpertName = "network";
static const int kConstantNamingConvention = 10000;

class DeviceEnumerator {
 public:
  DeviceEnumerator(SysCfgLibraryInterface* library);
  virtual ~DeviceEnumerator();

  ::grpc::Status enumerate_devices(google::protobuf::RepeatedPtrField<DeviceProperties>* devices);

  NISysCfgStatus open_or_get_localhost_syscfg_session(NISysCfgSessionHandle* session);
  void clear_syscfg_session();

 private:
  SysCfgLibraryInterface* library_;
  std::shared_mutex session_mutex_;
  NISysCfgSessionHandle syscfg_session_;
};

}  // namespace nidevice
}  // namespace grpc

#endif  // GRPC_NIDEVICE_DEVICEENUMERATOR
