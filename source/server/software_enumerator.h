#ifndef NIDEVICE_GRPC_SOFTWARE_ENUMERATOR_H
#define NIDEVICE_GRPC_SOFTWARE_ENUMERATOR_H

#include <grpcpp/grpcpp.h>
#include <nisyscfg.h>
#include <session.grpc.pb.h>

#include <shared_mutex>

#include "converters.h"
#include "syscfg_library_interface.h"
#include "syscfg_session_handler.h"

namespace nidevice_grpc {

static const char* kSoftwareEnumerationFailedMessage = "The NI System Configuration API was unable to enumerate the installed software.";

class SoftwareEnumerator : public SysCfgSessionHandler {
 public:
  SoftwareEnumerator(SysCfgLibraryInterface* library);
  virtual ~SoftwareEnumerator();

  ::grpc::Status enumerate_installed_software(
      ::grpc::ServerContext* context,
      bool includeHiddenPackages,
      google::protobuf::RepeatedPtrField<SoftwareProperties>* software);
};

}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_SOFTWARE_ENUMERATOR_H
