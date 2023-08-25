#include <visa/visa_service.h>

namespace visa_grpc {

::grpc::Status VisaService::ConvertApiErrorStatusForViSession(::grpc::ServerContextBase* context, int32_t status, ViSession vi)
{
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library_->GetStatusDescription(vi, &description[0]);
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

::grpc::Status VisaService::ConvertApiErrorStatusForViObject(::grpc::ServerContextBase* context, int32_t status, ViObject vi)
{
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library_->GetStatusDescription(vi, &description[0]);
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

}  // namespace visa_grpc
