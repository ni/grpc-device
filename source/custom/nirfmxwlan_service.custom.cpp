#include "nirfmxwlan/nirfmxwlan_service.h"

#include <server/converters.h>

#include <atomic>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>

namespace nirfmxwlan_grpc {

using nidevice_grpc::converters::calculate_linked_array_size;
using nidevice_grpc::converters::convert_from_grpc;
using nidevice_grpc::converters::convert_to_grpc;
using nidevice_grpc::converters::MatchState;

::grpc::Status NiRFmxWLANService::AnalyzeNWaveformsIQ(::grpc::ServerContext* context, const AnalyzeNWaveformsIQRequest* request, AnalyzeNWaveformsIQResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto instrument_grpc_session = request->instrument();
    niRFmxInstrHandle instrument = session_repository_->access_session(instrument_grpc_session.id(), instrument_grpc_session.name());
    char* selector_string = (char*)request->selector_string().c_str();
    char* result_name = (char*)request->result_name().c_str();
    auto x0 = const_cast<float64*>(request->x0().data());
    auto dx = const_cast<float64*>(request->dx().data());
    auto iq = convert_from_grpc<NIComplexSingle>(request->iq());
    auto iq_lenghts = const_cast<int32*>(reinterpret_cast<const int32*>(request->iq_lengths().data()));
    auto array_size_determine_from_sizes = std::array<int, 3>{
        request->x0_size(),
        request->dx_size(),
        request->iq_lengths_size()};
    const auto array_size_size_calculation = calculate_linked_array_size(array_size_determine_from_sizes, false);

    if (array_size_size_calculation.match_state == MatchState::MISMATCH) {
      return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The sizes of linked repeated fields [x0, dx, iqLenghts] do not match");
    }
    auto array_size = array_size_size_calculation.size;

    auto total_length = std::accumulate(request->iq_lengths().cbegin(), request->iq_lengths().cend(), 0);

    if (total_length != request->iq_size()) {
      return ::grpc::Status(::grpc::INVALID_ARGUMENT, "Bad Size");
    }

    int32 reset = request->reset();
    auto status = library_->AnalyzeNWaveformsIQ(instrument, selector_string, result_name, x0, dx, iq.data(), iq_lenghts, array_size, reset);
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}
}  // namespace nirfmxwlan_grpc
