#include <niscope/niscope_service.h>

namespace grpc {
namespace niscope {

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
    // TODO: Re-evaluate this when we get ActualRecordLength method in metadata. At that point
    // num_samples can come from a call to library_->ActualRecordLength and be removed from proto fields on request.
    ViInt32 num_samples = request->num_samples();

    ViInt32 num_waveforms;
    auto status = library_->ActualNumWfms(vi, channel_list, &num_waveforms);
    if (status != 0) {
      response->set_status(status);
      return ::grpc::Status::OK;
    };

    response->mutable_waveform()->Resize(num_samples * num_waveforms, 0.0);
    ViReal64* waveform = response->mutable_waveform()->mutable_data();
    std::vector<niScope_wfmInfo> waveform_info(num_waveforms, niScope_wfmInfo());
    status = library_->Fetch(vi, channel_list, timeout, num_samples, waveform, waveform_info.data());
    response->set_status(status);
    if (status == 0) {
      Copy(waveform_info, response->mutable_wfm_info());
    }
    return ::grpc::Status::OK;
  }
  catch (grpc::nidevice::LibraryLoadException& ex) {
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
    ViInt8* waveform = (ViInt8*)response->mutable_waveform()->data();
    std::vector<niScope_wfmInfo> waveform_info(num_waveforms, niScope_wfmInfo());
    status = library_->FetchBinary8(vi, channel_list, timeout, num_samples, waveform, waveform_info.data());
    response->set_status(status);
    if (status == 0) {
      Copy(waveform_info, response->mutable_wfm_info());
    }
    return ::grpc::Status::OK;
  }
  catch (grpc::nidevice::LibraryLoadException& ex) {
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
  catch (grpc::nidevice::LibraryLoadException& ex) {
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
      response->mutable_waveform()->Add(waveform.begin(), waveform.end());
      Copy(waveform_info, response->mutable_wfm_info());
    }
    return ::grpc::Status::OK;
  }
  catch (grpc::nidevice::LibraryLoadException& ex) {
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
    ViInt32 measurement_waveform_size = request->measurement_waveform_size();

    ViInt32 num_waveforms;
    auto status = library_->ActualNumWfms(vi, channel_list, &num_waveforms);
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
  catch (grpc::nidevice::LibraryLoadException& ex) {
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
    std::vector<ViInt32> num_in_stats(num_waveforms, 0.0);
    status = library_->FetchMeasurementStats(vi, channel_list, timeout, scalar_meas_function, result, mean, stdev, min, max, num_in_stats.data());
    response->set_status(status);
    if (status == 0) {
      response->mutable_num_in_stats()->Add(num_in_stats.begin(), num_in_stats.end());
    }
    return ::grpc::Status::OK;
  }
  catch (grpc::nidevice::LibraryLoadException& ex) {
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

    response->mutable_waveform()->Resize(num_samples * num_waveforms, 0.0);
    ViReal64* waveform = response->mutable_waveform()->mutable_data();
    std::vector<niScope_wfmInfo> waveform_info(num_waveforms, niScope_wfmInfo());
    status = library_->Read(vi, channel_list, timeout, num_samples, waveform, waveform_info.data());
    response->set_status(status);
    if (status == 0) {
      Copy(waveform_info, response->mutable_wfm_info());
    }
    return ::grpc::Status::OK;
  }
  catch (grpc::nidevice::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

}  // namespace niscope
}  // namespace grpc
