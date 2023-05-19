#include <nidcpower/nidcpower_service.h>

#include <stdexcept>

namespace nidcpower_grpc {
using nidevice_grpc::converters::convert_from_grpc;
using nidevice_grpc::converters::convert_to_grpc;

class DriverWarningOrErrorException : public std::runtime_error {
 private:
  int status_ = 0;

 public:
  DriverWarningOrErrorException(int status) : std::runtime_error(""), status_(status) {}
  int status() const
  {
    return status_;
  }
};

static void CheckStatus(int status)
{
  if (status != 0) {
    throw DriverWarningOrErrorException(status);
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiDCPowerService::MeasureMultiple(::grpc::ServerContext* context, const MeasureMultipleRequest* request, MeasureMultipleResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  ViSession vi = VI_NULL;
  try {
    auto vi_grpc_session = request->vi();
    vi = session_repository_->access_session(vi_grpc_session.name());
    auto channel_name_mbcs = convert_from_grpc<std::string>(request->channel_name());
    ViConstString channel_name = channel_name_mbcs.c_str();

    ViUInt32 number_of_channels;
    CheckStatus(library_->ParseChannelCount(vi, channel_name, &number_of_channels));
    response->mutable_voltage_measurements()->Resize(number_of_channels, 0.0);
    ViReal64* voltage_measurements = response->mutable_voltage_measurements()->mutable_data();
    response->mutable_current_measurements()->Resize(number_of_channels, 0.0);
    ViReal64* current_measurements = response->mutable_current_measurements()->mutable_data();

    auto status = library_->MeasureMultiple(vi, channel_name, voltage_measurements, current_measurements);
    if (status < VI_SUCCESS) {
      return ConvertApiErrorStatusForViSession(context, status, vi);
    }
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
  catch (const DriverWarningOrErrorException& ex) {
    if (ex.status() < VI_SUCCESS) {
      return ConvertApiErrorStatusForViSession(context, ex.status(), vi);
    }
    response->set_status(ex.status());
    return ::grpc::Status::OK;
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiDCPowerService::MeasureMultipleLCR(::grpc::ServerContext* context, const MeasureMultipleLCRRequest* request, MeasureMultipleLCRResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  ViSession vi = VI_NULL;
  try {
    auto vi_grpc_session = request->vi();
    vi = session_repository_->access_session(vi_grpc_session.name());
    auto channel_name_mbcs = convert_from_grpc<std::string>(request->channel_name());
    ViConstString channel_name = channel_name_mbcs.c_str();

    ViUInt32 number_of_channels;
    CheckStatus(library_->ParseChannelCount(vi, channel_name, &number_of_channels));
    std::vector<NILCRMeasurement_struct> measurements(number_of_channels, NILCRMeasurement_struct());

    auto status = library_->MeasureMultipleLCR(vi, channel_name, measurements.data());
    if (status < VI_SUCCESS) {
      return ConvertApiErrorStatusForViSession(context, status, vi);
    }
    response->set_status(status);
    convert_to_grpc(measurements, response->mutable_measurements());
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
  catch (const DriverWarningOrErrorException& ex) {
    if (ex.status() < VI_SUCCESS) {
      return ConvertApiErrorStatusForViSession(context, ex.status(), vi);
    }
    response->set_status(ex.status());
    return ::grpc::Status::OK;
  }
}

::grpc::Status NiDCPowerService::ConvertApiErrorStatusForViSession(::grpc::ServerContextBase* context, int32_t status, ViSession vi)
{
  static_assert(nidevice_grpc::kMaxGrpcErrorDescriptionSize >= 256, "ErrorMessage expects a minimum buffer size.");
  ViStatus error_code{};
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  // Try first to get the most recent error with a dynamic message.
  library_->GetError(vi, &error_code, nidevice_grpc::kMaxGrpcErrorDescriptionSize, &description[0]);
  if (error_code != status) {
    // Since another thread has changed the status, fall back to the static message lookup.
    description.assign(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
    library_->ErrorMessage(vi, status, &description[0]);
  }
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

}  // namespace nidcpower_grpc
