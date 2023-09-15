#include <niscope/niscope_service.h>
#include <server/converters.h>

#include <stdexcept>

namespace niscope_grpc {
using nidevice_grpc::converters::convert_from_grpc;
using nidevice_grpc::converters::convert_to_grpc;

const auto kErrorReadBufferTooSmall = -200229;

struct DriverWarningOrErrorException : std::runtime_error {
  DriverWarningOrErrorException(int status) : std::runtime_error("") { status_ = status; }
  int status_ = 0;
};

void CheckStatus(int status)
{
  if (status != 0) {
    throw DriverWarningOrErrorException(status);
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiScopeService::Fetch(::grpc::ServerContext* context, const FetchRequest* request, FetchResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  ViSession vi = VI_NULL;
  try {
    auto session = request->vi();
    vi = session_repository_->access_session(session.name());
    auto channel_list_mbcs = convert_from_grpc<std::string>(request->channel_list());
    ViConstString channel_list = channel_list_mbcs.c_str();
    ViReal64 timeout = request->timeout();
    ViInt32 num_samples = request->num_samples();
    if (num_samples < 0) {
      CheckStatus(library_->ActualRecordLength(vi, &num_samples));
    }

    ViInt32 num_waveforms;
    CheckStatus(library_->ActualNumWfms(vi, channel_list, &num_waveforms));

    response->mutable_waveform()->Resize(num_samples * num_waveforms, 0.0);
    ViReal64* waveform = response->mutable_waveform()->mutable_data();
    std::vector<niScope_wfmInfo> waveform_info(num_waveforms, niScope_wfmInfo());
    auto status = library_->Fetch(vi, channel_list, timeout, num_samples, waveform, waveform_info.data());
    if (status < VI_SUCCESS) {
      return ConvertApiErrorStatusForViSession(context, status, vi);
    }
    response->set_status(status);
    convert_to_grpc(waveform_info, response->mutable_wfm_info());
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
  catch (const DriverWarningOrErrorException& ex) {
    if (ex.status_ < VI_SUCCESS) {
      return ConvertApiErrorStatusForViSession(context, ex.status_, vi);
    }
    response->set_status(ex.status_);
    return ::grpc::Status::OK;
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiScopeService::FetchBinary8(::grpc::ServerContext* context, const FetchBinary8Request* request, FetchBinary8Response* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  ViSession vi = VI_NULL;
  try {
    auto session = request->vi();
    vi = session_repository_->access_session(session.name());
    auto channel_list_mbcs = convert_from_grpc<std::string>(request->channel_list());
    ViConstString channel_list = channel_list_mbcs.c_str();
    ViReal64 timeout = request->timeout();
    ViInt32 num_samples = request->num_samples();
    if (num_samples < 0) {
      CheckStatus(library_->ActualRecordLength(vi, &num_samples));
    }

    ViInt32 num_waveforms;
    CheckStatus(library_->ActualNumWfms(vi, channel_list, &num_waveforms));

    response->mutable_waveform()->insert(0, (size_t)(num_samples * num_waveforms), '\0');
    ViInt8* waveform = (ViInt8*)response->mutable_waveform()->data();
    std::vector<niScope_wfmInfo> waveform_info(num_waveforms, niScope_wfmInfo());
    auto status = library_->FetchBinary8(vi, channel_list, timeout, num_samples, waveform, waveform_info.data());
    if (status < VI_SUCCESS) {
      return ConvertApiErrorStatusForViSession(context, status, vi);
    }
    response->set_status(status);
    convert_to_grpc(waveform_info, response->mutable_wfm_info());
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
  catch (const DriverWarningOrErrorException& ex) {
    if (ex.status_ < VI_SUCCESS) {
      return ConvertApiErrorStatusForViSession(context, ex.status_, vi);
    }
    response->set_status(ex.status_);
    return ::grpc::Status::OK;
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiScopeService::FetchBinary16(::grpc::ServerContext* context, const FetchBinary16Request* request, FetchBinary16Response* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  ViSession vi = VI_NULL;
  try {
    auto session = request->vi();
    vi = session_repository_->access_session(session.name());
    auto channel_list_mbcs = convert_from_grpc<std::string>(request->channel_list());
    ViConstString channel_list = channel_list_mbcs.c_str();
    ViReal64 timeout = request->timeout();
    ViInt32 num_samples = request->num_samples();
    if (num_samples < 0) {
      CheckStatus(library_->ActualRecordLength(vi, &num_samples));
    }

    ViInt32 num_waveforms;
    CheckStatus(library_->ActualNumWfms(vi, channel_list, &num_waveforms));

    std::vector<ViInt16> waveform(num_samples * num_waveforms, 0);
    std::vector<niScope_wfmInfo> waveform_info(num_waveforms, niScope_wfmInfo());
    auto status = library_->FetchBinary16(vi, channel_list, timeout, num_samples, waveform.data(), waveform_info.data());
    if (status < VI_SUCCESS) {
      return ConvertApiErrorStatusForViSession(context, status, vi);
    }
    response->set_status(status);
    convert_to_grpc(waveform_info, response->mutable_wfm_info());
    response->mutable_waveform()->Add(waveform.begin(), waveform.end());
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
  catch (const DriverWarningOrErrorException& ex) {
    if (ex.status_ < VI_SUCCESS) {
      return ConvertApiErrorStatusForViSession(context, ex.status_, vi);
    }
    response->set_status(ex.status_);
    return ::grpc::Status::OK;
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiScopeService::FetchBinary32(::grpc::ServerContext* context, const FetchBinary32Request* request, FetchBinary32Response* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  ViSession vi = VI_NULL;
  try {
    auto session = request->vi();
    vi = session_repository_->access_session(session.name());
    auto channel_list_mbcs = convert_from_grpc<std::string>(request->channel_list());
    ViConstString channel_list = channel_list_mbcs.c_str();
    ViReal64 timeout = request->timeout();
    ViInt32 num_samples = request->num_samples();
    if (num_samples < 0) {
      CheckStatus(library_->ActualRecordLength(vi, &num_samples));
    }

    ViInt32 num_waveforms;
    CheckStatus(library_->ActualNumWfms(vi, channel_list, &num_waveforms));

    std::vector<ViInt32> waveform(num_samples * num_waveforms, 0);
    std::vector<niScope_wfmInfo> waveform_info(num_waveforms, niScope_wfmInfo());
    auto status = library_->FetchBinary32(vi, channel_list, timeout, num_samples, waveform.data(), waveform_info.data());
    if (status < VI_SUCCESS) {
      return ConvertApiErrorStatusForViSession(context, status, vi);
    }
    response->set_status(status);
    response->mutable_waveform()->Add(waveform.begin(), waveform.end());
    convert_to_grpc(waveform_info, response->mutable_wfm_info());
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
  catch (const DriverWarningOrErrorException& ex) {
    if (ex.status_ < VI_SUCCESS) {
      return ConvertApiErrorStatusForViSession(context, ex.status_, vi);
    }
    response->set_status(ex.status_);
    return ::grpc::Status::OK;
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiScopeService::FetchArrayMeasurement(::grpc::ServerContext* context, const FetchArrayMeasurementRequest* request, FetchArrayMeasurementResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  ViSession vi = VI_NULL;
  try {
    auto session = request->vi();
    vi = session_repository_->access_session(session.name());
    auto channel_list_mbcs = convert_from_grpc<std::string>(request->channel_list());
    ViConstString channel_list = channel_list_mbcs.c_str();
    ViReal64 timeout = request->timeout();
    ViInt32 array_meas_function;
    switch (request->array_meas_function_enum_case()) {
      case niscope_grpc::FetchArrayMeasurementRequest::ArrayMeasFunctionEnumCase::kArrayMeasFunction:
        array_meas_function = (ViInt32)request->array_meas_function();
        break;
      case niscope_grpc::FetchArrayMeasurementRequest::ArrayMeasFunctionEnumCase::kArrayMeasFunctionRaw:
        array_meas_function = (ViInt32)request->array_meas_function_raw();
        break;
      case niscope_grpc::FetchArrayMeasurementRequest::ArrayMeasFunctionEnumCase::ARRAY_MEAS_FUNCTION_ENUM_NOT_SET:
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for array_meas_function was not specified or out of range");
        break;
    }

    // meas_wfm_size is marked optional in the proto file.
    // If it was set to a non-negative value, use it.
    // If it wasn't set or if it was set to a negative number, use the ActualMeasWfmSize.
    ViInt32 measurement_waveform_size = -1;
    if (request->has_meas_wfm_size()) {
      measurement_waveform_size = request->meas_wfm_size();
    }
    if (measurement_waveform_size < 0) {
      CheckStatus(library_->ActualMeasWfmSize(vi, array_meas_function, &measurement_waveform_size));
    }

    ViInt32 num_waveforms;
    CheckStatus(library_->ActualNumWfms(vi, channel_list, &num_waveforms));

    response->mutable_meas_wfm()->Resize(num_waveforms * measurement_waveform_size, 0);
    ViReal64* meas_wfm = response->mutable_meas_wfm()->mutable_data();
    std::vector<niScope_wfmInfo> waveform_info(num_waveforms, niScope_wfmInfo());
    auto status = library_->FetchArrayMeasurement(vi, channel_list, timeout, array_meas_function, measurement_waveform_size, meas_wfm, waveform_info.data());
    if (status < VI_SUCCESS) {
      return ConvertApiErrorStatusForViSession(context, status, vi);
    }
    response->set_status(status);
    convert_to_grpc(waveform_info, response->mutable_wfm_info());
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
  catch (const DriverWarningOrErrorException& ex) {
    if (ex.status_ < VI_SUCCESS) {
      return ConvertApiErrorStatusForViSession(context, ex.status_, vi);
    }
    response->set_status(ex.status_);
    return ::grpc::Status::OK;
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiScopeService::FetchMeasurementStats(::grpc::ServerContext* context, const FetchMeasurementStatsRequest* request, FetchMeasurementStatsResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  ViSession vi = VI_NULL;
  try {
    auto session = request->vi();
    vi = session_repository_->access_session(session.name());
    auto channel_list_mbcs = convert_from_grpc<std::string>(request->channel_list());
    ViConstString channel_list = channel_list_mbcs.c_str();
    ViReal64 timeout = request->timeout();
    ViInt32 scalar_meas_function;
    switch (request->scalar_meas_function_enum_case()) {
      case niscope_grpc::FetchMeasurementStatsRequest::ScalarMeasFunctionEnumCase::kScalarMeasFunction:
        scalar_meas_function = (ViInt32)request->scalar_meas_function();
        break;
      case niscope_grpc::FetchMeasurementStatsRequest::ScalarMeasFunctionEnumCase::kScalarMeasFunctionRaw:
        scalar_meas_function = (ViInt32)request->scalar_meas_function_raw();
        break;
      case niscope_grpc::FetchMeasurementStatsRequest::ScalarMeasFunctionEnumCase::SCALAR_MEAS_FUNCTION_ENUM_NOT_SET:
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for scalar_meas_function was not specified or out of range");
        break;
    }

    ViInt32 num_waveforms;
    CheckStatus(library_->ActualNumWfms(vi, channel_list, &num_waveforms));

    response->mutable_result()->Resize(num_waveforms, 0.0);
    ViReal64* result = response->mutable_result()->mutable_data();
    response->mutable_mean()->Resize(num_waveforms, 0.0);
    ViReal64* mean = response->mutable_mean()->mutable_data();
    response->mutable_stdev()->Resize(num_waveforms, 0.0);
    ViReal64* stdev = response->mutable_stdev()->mutable_data();
    response->mutable_min()->Resize(num_waveforms, 0.0);
    ViReal64* min = response->mutable_min()->mutable_data();
    response->mutable_max()->Resize(num_waveforms, 0.0);
    ViReal64* max = response->mutable_max()->mutable_data();
    std::vector<ViInt32> num_in_stats(num_waveforms, 0);
    auto status = library_->FetchMeasurementStats(vi, channel_list, timeout, scalar_meas_function, result, mean, stdev, min, max, num_in_stats.data());
    if (status < VI_SUCCESS) {
      return ConvertApiErrorStatusForViSession(context, status, vi);
    }
    response->set_status(status);
    response->mutable_num_in_stats()->Add(num_in_stats.begin(), num_in_stats.end());
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
  catch (const DriverWarningOrErrorException& ex) {
    if (ex.status_ < VI_SUCCESS) {
      return ConvertApiErrorStatusForViSession(context, ex.status_, vi);
    }
    response->set_status(ex.status_);
    return ::grpc::Status::OK;
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiScopeService::Read(::grpc::ServerContext* context, const ReadRequest* request, ReadResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  ViSession vi = VI_NULL;
  try {
    auto session = request->vi();
    vi = session_repository_->access_session(session.name());
    auto channel_list_mbcs = convert_from_grpc<std::string>(request->channel_list());
    ViConstString channel_list = channel_list_mbcs.c_str();
    ViReal64 timeout = request->timeout();
    ViInt32 num_samples = request->num_samples();
    if (num_samples < 0) {
      CheckStatus(library_->ActualRecordLength(vi, &num_samples));
    }

    ViInt32 num_waveforms;
    CheckStatus(library_->ActualNumWfms(vi, channel_list, &num_waveforms));

    response->mutable_waveform()->Resize(num_samples * num_waveforms, 0.0);
    ViReal64* waveform = response->mutable_waveform()->mutable_data();
    std::vector<niScope_wfmInfo> waveform_info(num_waveforms, niScope_wfmInfo());
    auto status = library_->Read(vi, channel_list, timeout, num_samples, waveform, waveform_info.data());
    if (status < VI_SUCCESS) {
      return ConvertApiErrorStatusForViSession(context, status, vi);
    }
    response->set_status(status);
    convert_to_grpc(waveform_info, response->mutable_wfm_info());
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
  catch (const DriverWarningOrErrorException& ex) {
    if (ex.status_ < VI_SUCCESS) {
      return ConvertApiErrorStatusForViSession(context, ex.status_, vi);
    }
    response->set_status(ex.status_);
    return ::grpc::Status::OK;
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiScopeService::FetchComplex(::grpc::ServerContext* context, const FetchComplexRequest* request, FetchComplexResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  ViSession vi = VI_NULL;
  try {
    auto session = request->vi();
    vi = session_repository_->access_session(session.name());
    auto channel_list_mbcs = convert_from_grpc<std::string>(request->channel_list());
    ViConstString channel_list = channel_list_mbcs.c_str();
    ViReal64 timeout = request->timeout();
    ViInt32 num_samples = request->num_samples();
    if (num_samples < 0) {
      CheckStatus(library_->ActualRecordLength(vi, &num_samples));
    }

    ViInt32 num_waveforms;
    CheckStatus(library_->ActualNumWfms(vi, channel_list, &num_waveforms));

    std::vector<NIComplexNumber_struct> waveform(num_samples * num_waveforms, NIComplexNumber_struct());
    std::vector<niScope_wfmInfo> waveform_info(num_waveforms, niScope_wfmInfo());
    auto status = library_->FetchComplex(vi, channel_list, timeout, num_samples, waveform.data(), waveform_info.data());
    if (status < VI_SUCCESS) {
      return ConvertApiErrorStatusForViSession(context, status, vi);
    }
    response->set_status(status);
    convert_to_grpc(waveform, response->mutable_wfm());
    convert_to_grpc(waveform_info, response->mutable_wfm_info());
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
  catch (const DriverWarningOrErrorException& ex) {
    if (ex.status_ < VI_SUCCESS) {
      return ConvertApiErrorStatusForViSession(context, ex.status_, vi);
    }
    response->set_status(ex.status_);
    return ::grpc::Status::OK;
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiScopeService::FetchComplexBinary16(::grpc::ServerContext* context, const FetchComplexBinary16Request* request, FetchComplexBinary16Response* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  ViSession vi = VI_NULL;
  try {
    auto session = request->vi();
    vi = session_repository_->access_session(session.name());
    auto channel_list_mbcs = convert_from_grpc<std::string>(request->channel_list());
    ViConstString channel_list = channel_list_mbcs.c_str();
    ViReal64 timeout = request->timeout();
    ViInt32 num_samples = request->num_samples();
    if (num_samples < 0) {
      CheckStatus(library_->ActualRecordLength(vi, &num_samples));
    }

    ViInt32 num_waveforms;
    CheckStatus(library_->ActualNumWfms(vi, channel_list, &num_waveforms));

    std::vector<NIComplexI16_struct> waveform(num_samples * num_waveforms, NIComplexI16_struct());
    std::vector<niScope_wfmInfo> waveform_info(num_waveforms, niScope_wfmInfo());
    auto status = library_->FetchComplexBinary16(vi, channel_list, timeout, num_samples, waveform.data(), waveform_info.data());
    if (status < VI_SUCCESS) {
      return ConvertApiErrorStatusForViSession(context, status, vi);
    }
    response->set_status(status);
    convert_to_grpc(waveform, response->mutable_wfm());
    convert_to_grpc(waveform_info, response->mutable_wfm_info());
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
  catch (const DriverWarningOrErrorException& ex) {
    if (ex.status_ < VI_SUCCESS) {
      return ConvertApiErrorStatusForViSession(context, ex.status_, vi);
    }
    response->set_status(ex.status_);
    return ::grpc::Status::OK;
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiScopeService::FetchMeasurement(::grpc::ServerContext* context, const FetchMeasurementRequest* request, FetchMeasurementResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  ViSession vi = VI_NULL;
  try {
    auto session = request->vi();
    vi = session_repository_->access_session(session.name());
    auto channel_list_mbcs = convert_from_grpc<std::string>(request->channel_list());
    ViConstString channel_list = channel_list_mbcs.c_str();
    ViReal64 timeout = request->timeout();
    ViInt32 scalar_meas_function;
    switch (request->scalar_meas_function_enum_case()) {
      case niscope_grpc::FetchMeasurementRequest::ScalarMeasFunctionEnumCase::kScalarMeasFunction:
        scalar_meas_function = (ViInt32)request->scalar_meas_function();
        break;
      case niscope_grpc::FetchMeasurementRequest::ScalarMeasFunctionEnumCase::kScalarMeasFunctionRaw:
        scalar_meas_function = (ViInt32)request->scalar_meas_function_raw();
        break;
      case niscope_grpc::FetchMeasurementRequest::ScalarMeasFunctionEnumCase::SCALAR_MEAS_FUNCTION_ENUM_NOT_SET:
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for scalar_meas_function was not specified or out of range");
        break;
    }

    ViInt32 num_waveforms;
    CheckStatus(library_->ActualNumWfms(vi, channel_list, &num_waveforms));

    response->mutable_result()->Resize(num_waveforms, 0.0);
    ViReal64* result = response->mutable_result()->mutable_data();
    auto status = library_->FetchMeasurement(vi, channel_list, timeout, scalar_meas_function, result);
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
    if (ex.status_ < VI_SUCCESS) {
      return ConvertApiErrorStatusForViSession(context, ex.status_, vi);
    }
    response->set_status(ex.status_);
    return ::grpc::Status::OK;
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiScopeService::ReadMeasurement(::grpc::ServerContext* context, const ReadMeasurementRequest* request, ReadMeasurementResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  ViSession vi = VI_NULL;
  try {
    auto session = request->vi();
    vi = session_repository_->access_session(session.name());
    auto channel_list_mbcs = convert_from_grpc<std::string>(request->channel_list());
    ViConstString channel_list = channel_list_mbcs.c_str();
    ViReal64 timeout = request->timeout();
    ViInt32 scalar_meas_function;
    switch (request->scalar_meas_function_enum_case()) {
      case niscope_grpc::ReadMeasurementRequest::ScalarMeasFunctionEnumCase::kScalarMeasFunction:
        scalar_meas_function = (ViInt32)request->scalar_meas_function();
        break;
      case niscope_grpc::ReadMeasurementRequest::ScalarMeasFunctionEnumCase::kScalarMeasFunctionRaw:
        scalar_meas_function = (ViInt32)request->scalar_meas_function_raw();
        break;
      case niscope_grpc::ReadMeasurementRequest::ScalarMeasFunctionEnumCase::SCALAR_MEAS_FUNCTION_ENUM_NOT_SET:
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for scalar_meas_function was not specified or out of range");
        break;
    }

    ViInt32 num_waveforms;
    CheckStatus(library_->ActualNumWfms(vi, channel_list, &num_waveforms));

    response->mutable_result()->Resize(num_waveforms, 0.0);
    ViReal64* result = response->mutable_result()->mutable_data();
    auto status = library_->ReadMeasurement(vi, channel_list, timeout, scalar_meas_function, result);
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
    if (ex.status_ < VI_SUCCESS) {
      return ConvertApiErrorStatusForViSession(context, ex.status_, vi);
    }
    response->set_status(ex.status_);
    return ::grpc::Status::OK;
  }
}

::grpc::Status NiScopeService::ConvertApiErrorStatusForViSession(::grpc::ServerContextBase* context, int32_t status, ViSession vi)
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

}  // namespace niscope_grpc
