#include <nirfmxspecan/nirfmxspecan_service.h>
using nidevice_grpc::converters::convert_to_grpc;
using nidevice_grpc::converters::convert_from_grpc;
using nidevice_grpc::converters::calculate_linked_array_size;
using nidevice_grpc::converters::MatchState;

namespace nirfmxspecan_grpc {

  // Returns true if it's safe to use outputs of a method with the given status.
  inline bool status_ok(int32 status)
  {
    return status >= 0;
  }

  ::grpc::Status NiRFmxSpecAnService::ConvertApiErrorStatusForNiRFmxInstrHandle(::grpc::ServerContextBase* context, int32_t status, niRFmxInstrHandle instrumentHandle)
  {
    ViStatus error_code{};
    std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
    // Try first to get the most recent error with a dynamic message.
    library_->GetError(instrumentHandle, &error_code, nidevice_grpc::kMaxGrpcErrorDescriptionSize, &description[0]);
    if (error_code != status) {
      // Since another thread has changed the status, fall back to the static message lookup.
      library_->GetErrorString(instrumentHandle, status, nidevice_grpc::kMaxGrpcErrorDescriptionSize, &description[0]);
    }
    return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiRFmxSpecAnService::DPDCfgApplyDPDUserLookupTableInterleavedIQ(::grpc::ServerContext*context,   const DPDCfgApplyDPDUserLookupTableInterleavedIQRequest* request,  DPDCfgApplyDPDUserLookupTableInterleavedIQResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto instrument_grpc_session = request->instrument();
      niRFmxInstrHandle instrument = session_repository_->access_session(instrument_grpc_session.name());
      auto selector_string_mbcs = convert_from_grpc<std::string>(request->selector_string());
      char* selector_string = (char*)selector_string_mbcs.c_str();
      auto lut_input_powers = const_cast<float32*>(request->lut_input_powers().data());
      auto lut_complex_gains = const_cast<float32*>(request->lut_complex_gains().data());
      auto array_size = 0;
      if (request->lut_input_powers_size()) {
        array_size = request->lut_input_powers_size() * 2;
        if (request->lut_complex_gains_size()) {
          if (request->lut_complex_gains_size() != array_size) {
            return ::grpc::Status(::grpc::INVALID_ARGUMENT, "lut_complex_gains size must be twice the size of lut_input_powers.");
          }
        }
      }
      else if (request->lut_complex_gains_size()) {
        array_size = request->lut_complex_gains_size();
      }
      auto status = library_->DPDCfgApplyDPDUserLookupTableInterleavedIQ(instrument, selector_string,  lut_input_powers, lut_complex_gains, array_size);
      if (!status_ok(status)) {
        return ConvertApiErrorStatusForNiRFmxInstrHandle(context, status, instrument);
      }
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::NonDriverException& ex) {
      return ex.GetStatus();
    }
  }

}  // namespace nirfmxspecan_grpc
