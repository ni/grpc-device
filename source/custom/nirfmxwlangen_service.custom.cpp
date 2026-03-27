#include <nirfmxwlangen/nirfmxwlangen_service.h>
#include <nirfsg/nirfsg_library.h>

namespace nirfmxwlangen_grpc {
using nidevice_grpc::converters::convert_to_grpc;
using nidevice_grpc::converters::convert_from_grpc;
const auto kErrorReadBufferTooSmall = -200229;
const auto kWarningCAPIStringTruncatedToFitBuffer = 200026;

// Returns true if it's safe to use outputs of a method with the given status.
inline bool status_ok(int32 status)
{
  return status >= 0;
}

::grpc::Status NiRFmxWLANGenService::ConvertApiErrorStatusForNiWLANGenerationSession(::grpc::ServerContextBase* context, int32_t status, niWLANGenerationSession session)
{
  ViStatus error_code{};
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  description.assign(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library_->GetErrorString(session, status, &description[0], nidevice_grpc::kMaxGrpcErrorDescriptionSize);
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

::grpc::Status NiRFmxWLANGenService::ConvertApiErrorStatusForViSession(::grpc::ServerContextBase* context, int32_t status, ViSession RFSGHandle)
{
  auto library = std::make_shared<nirfsg_grpc::NiRFSGLibrary>();

  ViStatus error_code{};
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library->GetError(RFSGHandle, &error_code, nidevice_grpc::kMaxGrpcErrorDescriptionSize, &description[0]);
  if (error_code != status) {
    description.assign(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
    library->ErrorMessage(RFSGHandle, status, &description[0]);
  }
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiRFmxWLANGenService::CreateMIMOWaveformsComplexF64(::grpc::ServerContext* context, const CreateMIMOWaveformsComplexF64Request* request, CreateMIMOWaveformsComplexF64Response* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto session_grpc_session = request->session();
    niWLANGenerationSession session = session_repository_->access_session(session_grpc_session.name());
    int32 reset = request->reset();

    int32 number_of_transmit_channels, iq_waveform_size, number_of_segments;

    auto status = library_->GetScalarAttributeI32(session, "", 47, &number_of_transmit_channels);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForNiWLANGenerationSession(context, status, session);
    }

    status = library_->GetScalarAttributeI32(session, "", 37, &iq_waveform_size);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForNiWLANGenerationSession(context, status, session);
    }

    status = library_->GetScalarAttributeI32(session, "", 75, &number_of_segments);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForNiWLANGenerationSession(context, status, session);
    }

    int32 number_of_tx_chains = number_of_transmit_channels * number_of_segments;

    response->mutable_t0()->Resize(number_of_tx_chains, 0);
    float64* t0 = response->mutable_t0()->mutable_data();
    response->mutable_dt()->Resize(number_of_tx_chains, 0);
    float64* dt = response->mutable_dt()->mutable_data();
    std::vector<NIComplexNumber_struct> waveforms(iq_waveform_size * number_of_tx_chains, NIComplexNumber_struct());

    int32 done{};
    status = library_->CreateMIMOWaveformsComplexF64(session, reset, t0, dt, waveforms.data(), number_of_tx_chains, iq_waveform_size, nullptr, &done);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForNiWLANGenerationSession(context, status, session);
    }
    response->set_status(status);
    convert_to_grpc(waveforms, response->mutable_waveforms());
    response->set_actual_num_samples_in_each_wfm(iq_waveform_size);
    response->set_done(done);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiRFmxWLANGenService::CreateMIMOWaveformsComplexF64InterleavedIQ(::grpc::ServerContext* context, const CreateMIMOWaveformsComplexF64InterleavedIQRequest* request, CreateMIMOWaveformsComplexF64InterleavedIQResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto session_grpc_session = request->session();
    niWLANGenerationSession session = session_repository_->access_session(session_grpc_session.name());
    int32 reset = request->reset();

    int32 number_of_transmit_channels, iq_waveform_size, number_of_segments;

    auto status = library_->GetScalarAttributeI32(session, "", 47, &number_of_transmit_channels);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForNiWLANGenerationSession(context, status, session);
    }

    status = library_->GetScalarAttributeI32(session, "", 37, &iq_waveform_size);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForNiWLANGenerationSession(context, status, session);
    }

    status = library_->GetScalarAttributeI32(session, "", 75, &number_of_segments);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForNiWLANGenerationSession(context, status, session);
    }

    int32 number_of_tx_chains = number_of_transmit_channels * number_of_segments;

    response->mutable_waveforms()->Resize(number_of_tx_chains * iq_waveform_size * 2, 0);
    float64* waveforms = response->mutable_waveforms()->mutable_data();
    response->mutable_t0()->Resize(number_of_tx_chains, 0);
    float64* t0 = response->mutable_t0()->mutable_data();
    response->mutable_dt()->Resize(number_of_tx_chains, 0);
    float64* dt = response->mutable_dt()->mutable_data();
    int32 done{};
    status = library_->CreateMIMOWaveformsComplexF64InterleavedIQ(session, reset, t0, dt, waveforms, number_of_tx_chains, iq_waveform_size, nullptr, &done);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForNiWLANGenerationSession(context, status, session);
    }
    response->set_status(status);
    response->set_actual_num_samples_in_each_wfm(iq_waveform_size);
    response->set_done(done);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiRFmxWLANGenService::GetMappingMatrix(::grpc::ServerContext* context, const GetMappingMatrixRequest* request, GetMappingMatrixResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto session_grpc_session = request->session();
    niWLANGenerationSession session = session_repository_->access_session(session_grpc_session.name());
    auto channel_string_mbcs = convert_from_grpc<std::string>(request->channel_string());
    char* channel_string = (char*)channel_string_mbcs.c_str();

    while (true) {

      std::vector<NIComplexNumber_struct> mapping_matrix(request->num_mapping_matrix_rows() * request->num_mapping_matrix_columns(), NIComplexNumber_struct());
      int32 status = library_->GetMappingMatrix(session, channel_string, mapping_matrix.data(), request->num_mapping_matrix_rows(), request->num_mapping_matrix_columns());
      if (status == kErrorReadBufferTooSmall || status == kWarningCAPIStringTruncatedToFitBuffer) {
        // buffer is now too small, try again
        continue;
      }
      if (!status_ok(status)) {
        return ConvertApiErrorStatusForNiWLANGenerationSession(context, status, session);
      }
      response->set_status(status);
      convert_to_grpc(mapping_matrix, response->mutable_mapping_matrix());
      return ::grpc::Status::OK;
    }
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiRFmxWLANGenService::SetMappingMatrix(::grpc::ServerContext* context, const SetMappingMatrixRequest* request, SetMappingMatrixResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto session_grpc_session = request->session();
    niWLANGenerationSession session = session_repository_->access_session(session_grpc_session.name());
    auto channel_string_mbcs = convert_from_grpc<std::string>(request->channel_string());
    char* channel_string = (char*)channel_string_mbcs.c_str();
    auto mapping_matrix = convert_from_grpc<NIComplexNumber_struct>(request->mapping_matrix());
    int32 num_mapping_matrix_rows = request->num_mapping_matrix_rows();
    int32 num_mapping_matrix_columns = request->num_mapping_matrix_columns();
    auto status = library_->SetMappingMatrix(session, channel_string, mapping_matrix.data(), num_mapping_matrix_rows, num_mapping_matrix_columns);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForNiWLANGenerationSession(context, status, session);
    }
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiRFmxWLANGenService::GetMappingMatrixInterleavedIQ(::grpc::ServerContext* context, const GetMappingMatrixInterleavedIQRequest* request, GetMappingMatrixInterleavedIQResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto session_grpc_session = request->session();
    niWLANGenerationSession session = session_repository_->access_session(session_grpc_session.name());
    auto channel_string_mbcs = convert_from_grpc<std::string>(request->channel_string());
    char* channel_string = (char*)channel_string_mbcs.c_str();

    while (true) {

      response->mutable_mapping_matrix()->Resize(request->num_mapping_matrix_rows() * request->num_mapping_matrix_columns() * 2, 0);
      float64* mapping_matrix = response->mutable_mapping_matrix()->mutable_data();
      int32 status = library_->GetMappingMatrixInterleavedIQ(session, channel_string, mapping_matrix, request->num_mapping_matrix_rows(), request->num_mapping_matrix_columns());
      if (status == kErrorReadBufferTooSmall || status == kWarningCAPIStringTruncatedToFitBuffer) {
        // buffer is now too small, try again
        continue;
      }
      if (!status_ok(status)) {
        return ConvertApiErrorStatusForNiWLANGenerationSession(context, status, session);
      }
      response->set_status(status);
      return ::grpc::Status::OK;
    }
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiRFmxWLANGenService::SetMappingMatrixInterleavedIQ(::grpc::ServerContext* context, const SetMappingMatrixInterleavedIQRequest* request, SetMappingMatrixInterleavedIQResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto session_grpc_session = request->session();
    niWLANGenerationSession session = session_repository_->access_session(session_grpc_session.name());
    auto channel_string_mbcs = convert_from_grpc<std::string>(request->channel_string());
    char* channel_string = (char*)channel_string_mbcs.c_str();

    auto mapping_matrix = const_cast<float64*>(request->mapping_matrix().data());
    int32 num_mapping_matrix_rows = request->num_mapping_matrix_rows();
    int32 num_mapping_matrix_columns = request->num_mapping_matrix_columns();
    
    auto status = library_->SetMappingMatrixInterleavedIQ(session, channel_string, mapping_matrix, num_mapping_matrix_rows, num_mapping_matrix_columns);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForNiWLANGenerationSession(context, status, session);
    }
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

}  // namespace nirfmxwlangen_grpc