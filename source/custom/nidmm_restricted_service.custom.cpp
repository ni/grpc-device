#include <nidmm_restricted/nidmm_restricted_service.h>
#include <server/converters.h>
#include "custom/ivi_errors.h"

#include <string>
#include <vector>

namespace nidmm_restricted_grpc {

using nidevice_grpc::converters::convert_from_grpc;
using nidevice_grpc::converters::convert_to_grpc;
using nidevice_grpc::converters::trim_trailing_nulls;

//---------------------------------------------------------------------
// ConvertApiErrorStatusForViSession
//---------------------------------------------------------------------
::grpc::Status NiDmmRestrictedService::ConvertApiErrorStatusForViSession(
    ::grpc::ServerContextBase* context,
    int32_t status,
    ViSession vi)
{
  ViStatus error_code{};
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  // Try first to get the most recent error with a dynamic message.
  library_->GetError(vi, &error_code, nidevice_grpc::kMaxGrpcErrorDescriptionSize, &description[0]);
  if (error_code != status) {
    // Since another thread has changed the status, fall back to the static message lookup.
    description.assign(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
    library_->GetErrorMessage(vi, status, nidevice_grpc::kMaxGrpcErrorDescriptionSize, &description[0]);
  }
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

//---------------------------------------------------------------------
// GetOpenSessionsInformation
//---------------------------------------------------------------------
::grpc::Status NiDmmRestrictedService::GetOpenSessionsInformation(
    ::grpc::ServerContext* context,
    const GetOpenSessionsInformationRequest* request,
    GetOpenSessionsInformationResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }

  try {
    // Convert resource name from gRPC string to native char pointer
    auto resource_name_mbcs = convert_from_grpc<std::string>(request->resource_name());
    ViRsrc resource_name = (ViRsrc)resource_name_mbcs.c_str();
    ViUInt64 buffer_size_needed_in_bytes{};

    // Local constants for NI error/warning codes
    const auto kErrorReadBufferTooSmall = -200229;
    const auto kWarningCAPIStringTruncatedToFitBuffer = 200026;

    while (true) {
      // First call to determine required buffer size with Empty string.
      // Avoid Null pointer since exception will be thrown for PAL devices.
      auto status = library_->GetOpenSessionsInformation(resource_name, (ViChar*)"", 0, &buffer_size_needed_in_bytes);
      if (status < 0) {
        return ConvertApiErrorStatusForViSession(context, status, 0);
      }

      std::string info_json;
      if (buffer_size_needed_in_bytes > 0) {
        info_json.resize(buffer_size_needed_in_bytes - 1);
      }

      auto buffer_size = buffer_size_needed_in_bytes;
      status = library_->GetOpenSessionsInformation(
          resource_name, (ViChar*)info_json.data(), buffer_size, &buffer_size_needed_in_bytes);

      if (status == kErrorReadBufferTooSmall || status == kWarningCAPIStringTruncatedToFitBuffer) {
        // Buffer was too small, try again with new size
        continue;
      }

      if (status < 0) {
        return ConvertApiErrorStatusForViSession(context, status, 0);
      }

      response->set_status(status);
      std::string info_json_utf8;
      convert_to_grpc(info_json, &info_json_utf8);
      response->set_info_json(info_json_utf8);
      trim_trailing_nulls(*(response->mutable_info_json()));
      response->set_buffer_size_needed_in_bytes(buffer_size_needed_in_bytes);
      return ::grpc::Status::OK;
    }
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

}  // namespace nidmm_restricted_grpc
