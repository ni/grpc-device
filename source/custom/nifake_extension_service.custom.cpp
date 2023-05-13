#include <nifake_extension/nifake_extension_service.h>

namespace nifake_extension_grpc {

::grpc::Status NiFakeExtensionService::ConvertApiErrorStatusForViSession(::grpc::ServerContextBase* context, int32_t status, ViSession vi)
{
  std::string description = "In a real service, you'd look up the error message here.";
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

}  // namespace nifake_extension_grpc
