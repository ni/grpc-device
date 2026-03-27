#include <nirfmxwlangen/nirfmxwlangen_service.h>
#include <nirfsg/nirfsg_library.h>

namespace nirfmxwlangen_grpc {
using nidevice_grpc::converters::convert_to_grpc;
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

}  // namespace nirfmxwlangen_grpc