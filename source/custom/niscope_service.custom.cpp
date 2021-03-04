#include <niscope/niscope_service.h>

namespace ni {
namespace scope {
namespace grpc {

namespace internal = ni::hardware::grpc::internal;

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiScopeService::Fetch(::grpc::ServerContext* context, const FetchRequest* request, FetchResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto session = request->vi();
    ViSession vi = session_repository_->access_session(session.id(), session.name());
    ViConstString channel_list = request->channel_list().c_str();
    ViReal64 timeout = request->timeout();
    ViInt32 num_samples = request->num_samples();

    ViInt32 num_waveforms;
    auto status = library_->ActualNumWfms(vi, channel_list, &num_waveforms);
    if (status != 0) {
      response->set_status(status);
      return ::grpc::Status::OK;
    };

    response->mutable_waveform()->Resize(num_samples * num_waveforms, 0);
    ViReal64* waveform = response->mutable_waveform()->mutable_data();
    std::vector<niScope_wfmInfo> waveform_info(num_waveforms, niScope_wfmInfo());
    status = library_->Fetch(vi, channel_list, timeout, num_samples, waveform, waveform_info.data());
    response->set_status(status);
    if (status == 0) {
      Copy(waveform_info, response->mutable_wfm_info());
    }
    return ::grpc::Status::OK;
  }
  catch (internal::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiScopeService::FetchBinary8(::grpc::ServerContext* context, const FetchBinary8Request* request, FetchBinary8Response* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto session = request->vi();
    ViSession vi = session_repository_->access_session(session.id(), session.name());
    ViConstString channel_list = request->channel_list().c_str();
    ViReal64 timeout = request->timeout();
    ViInt32 num_samples = request->num_samples();

    ViInt32 num_waveforms;
    auto status = library_->ActualNumWfms(vi, channel_list, &num_waveforms);
    if (status != 0) {
      response->set_status(status);
      return ::grpc::Status::OK;
    }

    response->mutable_waveform()->insert(0, (size_t)(num_samples * num_waveforms), '\0');
    std::vector<niScope_wfmInfo> waveform_info(num_waveforms, niScope_wfmInfo());
    status = library_->FetchBinary8(vi, channel_list, timeout, num_samples, (ViInt8*)response->mutable_waveform()->data(), waveform_info.data());
    response->set_status(status);
    if (status == 0) {
      Copy(waveform_info, response->mutable_wfm_info());
    }
    return ::grpc::Status::OK;
  }
  catch (internal::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiScopeService::FetchBinary16(::grpc::ServerContext* context, const FetchBinary16Request* request, FetchBinary16Response* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto session = request->vi();
    ViSession vi = session_repository_->access_session(session.id(), session.name());
    ViConstString channel_list = request->channel_list().c_str();
    ViReal64 timeout = request->timeout();
    ViInt32 num_samples = request->num_samples();

    ViInt32 num_waveforms;
    auto status = library_->ActualNumWfms(vi, channel_list, &num_waveforms);
    if (status != 0) {
      response->set_status(status);
      return ::grpc::Status::OK;
    }

    std::vector<ViInt16> waveform(num_samples * num_waveforms, 0);
    std::vector<niScope_wfmInfo> waveform_info(num_waveforms, niScope_wfmInfo());
    status = library_->FetchBinary16(vi, channel_list, timeout, num_samples, waveform.data(), waveform_info.data());
    response->set_status(status);
    if (status == 0) {
      Copy(waveform_info, response->mutable_wfm_info());
      response->mutable_waveform()->Add(waveform.begin(), waveform.end());
    }
    return ::grpc::Status::OK;
  }
  catch (internal::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiScopeService::FetchBinary32(::grpc::ServerContext* context, const FetchBinary32Request* request, FetchBinary32Response* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto session = request->vi();
    ViSession vi = session_repository_->access_session(session.id(), session.name());
    ViConstString channel_list = request->channel_list().c_str();
    ViReal64 timeout = request->timeout();
    ViInt32 num_samples = request->num_samples();

    ViInt32 num_waveforms;
    auto status = library_->ActualNumWfms(vi, channel_list, &num_waveforms);
    if (status != 0) {
      response->set_status(status);
      return ::grpc::Status::OK;
    }

    std::vector<ViInt32> waveform(num_samples * num_waveforms, 0);
    std::vector<niScope_wfmInfo> waveform_info(num_waveforms, niScope_wfmInfo());
    status = library_->FetchBinary32(vi, channel_list, timeout, num_samples, waveform.data(), waveform_info.data());
    response->set_status(status);
    if (status == 0) {
      Copy(waveform_info, response->mutable_wfm_info());
      response->mutable_waveform()->Add(waveform.begin(), waveform.end());
    }
    return ::grpc::Status::OK;
  }
  catch (internal::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiScopeService::FetchArrayMeasurement(::grpc::ServerContext* context, const FetchArrayMeasurementRequest* request, FetchArrayMeasurementResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto session = request->vi();
    ViSession vi = session_repository_->access_session(session.id(), session.name());
    ViConstString channel_list = request->channel_list().c_str();
    ViReal64 timeout = request->timeout();
    ViInt32 array_meas_function = request->array_meas_function();

    ViInt32 measurement_waveform_size;
    auto status = library_->ActualMeasWfmSize(vi, array_meas_function, &measurement_waveform_size);
    if (status != 0) {
      response->set_status(status);
      return ::grpc::Status::OK;
    }

    ViInt32 num_waveforms;
    status = library_->ActualNumWfms(vi, channel_list, &num_waveforms);
    if (status != 0) {
      response->set_status(status);
      return ::grpc::Status::OK;
    }

    response->mutable_meas_wfm()->Resize(num_waveforms * measurement_waveform_size, 0);
    ViReal64* meas_wfm = response->mutable_meas_wfm()->mutable_data();
    std::vector<niScope_wfmInfo> waveform_info(measurement_waveform_size, niScope_wfmInfo());
    status = library_->FetchArrayMeasurement(vi, channel_list, timeout, array_meas_function, measurement_waveform_size, meas_wfm, waveform_info.data());
    response->set_status(status);
    if (status == 0) {
      Copy(waveform_info, response->mutable_wfm_info());
    }
    return ::grpc::Status::OK;
  }
  catch (internal::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiScopeService::FetchMeasurementStats(::grpc::ServerContext* context, const FetchMeasurementStatsRequest* request, FetchMeasurementStatsResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto session = request->vi();
    ViSession vi = session_repository_->access_session(session.id(), session.name());
    ViConstString channel_list = request->channel_list().c_str();
    ViReal64 timeout = request->timeout();
    ViInt32 scalar_meas_function = request->scalar_meas_function();

    ViInt32 num_waveforms;
    auto status = library_->ActualNumWfms(vi, channel_list, &num_waveforms);
    if (status != 0) {
      response->set_status(status);
      return ::grpc::Status::OK;
    }

    std::vector<ViReal64> result(num_waveforms, 0.0);
    std::vector<ViReal64> mean(num_waveforms, 0.0);
    std::vector<ViReal64> stdev(num_waveforms, 0.0);
    std::vector<ViReal64> min(num_waveforms, 0.0);
    std::vector<ViReal64> max(num_waveforms, 0.0);
    std::vector<ViInt32> num_in_stats(num_waveforms, 0);

    status = library_->FetchMeasurementStats(vi, channel_list, timeout, scalar_meas_function, result.data(), mean.data(), stdev.data(), min.data(), max.data(), num_in_stats.data());
    response->set_status(status);
    if (status == 0) {
      response->mutable_result()->Add(result.begin(), result.end());
      response->mutable_mean()->Add(mean.begin(), mean.end());
      response->mutable_stdev()->Add(stdev.begin(), stdev.end());
      response->mutable_min()->Add(min.begin(), min.end());
      response->mutable_max()->Add(max.begin(), max.end());
      response->mutable_num_in_stats()->Add(num_in_stats.begin(), num_in_stats.end());
    }
    return ::grpc::Status::OK;
  }
  catch (internal::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiScopeService::Read(::grpc::ServerContext* context, const ReadRequest* request, ReadResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto session = request->vi();
    ViSession vi = session_repository_->access_session(session.id(), session.name());
    ViConstString channel_list = request->channel_list().c_str();
    ViReal64 timeout = request->timeout();
    ViInt32 num_samples = request->num_samples();

    ViInt32 num_waveforms;
    auto status = library_->ActualNumWfms(vi, channel_list, &num_waveforms);
    if (status != 0) {
      response->set_status(status);
      return ::grpc::Status::OK;
    }

    response->mutable_waveform()->Resize(num_samples * num_waveforms, 0);
    ViReal64* waveform = response->mutable_waveform()->mutable_data();
    std::vector<niScope_wfmInfo> waveform_info(num_waveforms, niScope_wfmInfo());
    status = library_->Read(vi, channel_list, timeout, num_samples, waveform, waveform_info.data());
    response->set_status(status);
    if (status == 0) {
      Copy(waveform_info, response->mutable_wfm_info());
    }
    return ::grpc::Status::OK;
  }
  catch (internal::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

}  // namespace grpc
}  // namespace scope
}  // namespace ni