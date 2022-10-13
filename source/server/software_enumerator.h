#ifndef NIDEVICE_GRPC_SOFTWARE_ENUMERATOR_H
#define NIDEVICE_GRPC_SOFTWARE_ENUMERATOR_H

#include <grpcpp/grpcpp.h>
#include <nisyscfg.h>
#include <session.grpc.pb.h>
#include <shared_mutex>

#include "shared_library.h"
#include "syscfg_library_interface.h"

namespace nidevice_grpc {

static const char* kSoftwareEnumerationFailedMessage = "The NI System Configuration API was unable to enumerate the installed software.";
static const char* kSoftwareEnumerationLocalHostTargetName = "localhost";
static const char* kSoftwareEnumerationNetworkExpertName = "network";
static const int kSoftwareEnumerationConnectionTimeoutMilliSec = 10000;

class SoftwareEnumerator {
 public:
  SoftwareEnumerator(SysCfgLibraryInterface* library);
  virtual ~SoftwareEnumerator();

  ::grpc::Status enumerate_software(google::protobuf::RepeatedPtrField<SoftwareProperties>* software);
  NISysCfgStatus open_or_get_localhost_syscfg_session(NISysCfgSessionHandle* session);
  void clear_syscfg_session();
  bool is_session_open();

 private:
  SysCfgLibraryInterface* library_;
  std::shared_mutex session_mutex_;
  NISysCfgSessionHandle syscfg_session_;
};

}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_SOFTWARE_ENUMERATOR_H
