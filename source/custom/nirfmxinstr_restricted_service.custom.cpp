#include <nirfmxinstr_restricted/nirfmxinstr_restricted_service.h>

namespace nirfmxinstr_restricted_grpc {
using nidevice_grpc::converters::convert_to_grpc;

// Returns true if it's safe to use outputs of a method with the given status.
inline bool status_ok(int32 status)
{
  return status >= 0;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiRFmxInstrRestrictedService::ConvertApiErrorStatusForNiRFmxInstrHandle(::grpc::ServerContextBase* context, int32_t status, niRFmxInstrHandle instrumentHandle)
{
  int32 error_code{};
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  // Try first to get the most recent error with a dynamic message.
  library_->GetError(instrumentHandle, &error_code, nidevice_grpc::kMaxGrpcErrorDescriptionSize, &description[0]);
  if (error_code != status) {
    // Since another thread has changed the status, fall back to the static message lookup.
    description.assign(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
    library_->GetErrorString(instrumentHandle, status, nidevice_grpc::kMaxGrpcErrorDescriptionSize, &description[0]);
  }
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiRFmxInstrRestrictedService::GetInitiaitedSnapshotStrings(
    ::grpc::ServerContext* context,
    const GetInitiaitedSnapshotStringsRequest* request,
    GetInitiaitedSnapshotStringsResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto instrument_grpc_session = request->instrument();
    niRFmxInstrHandle instrument = session_repository_->access_session(instrument_grpc_session.name());
    uInt64 snapshot_info_cache_index{};
    int32 personality_id_array_actual_size{};
    int32 signal_names_actual_size{};
    int32 result_names_actual_size{};
    int32 snapshot_identifiers_actual_size{};
    int32 snapshot_timestamp_array_actual_size{};
    auto status = library_->GetInitiaitedSnapshotStrings(
        instrument,
        &snapshot_info_cache_index,
        nullptr,  // personalityIDArray
        0,        // personalityIDArraySize
        &personality_id_array_actual_size,
        nullptr,  // signalNames
        0,        // signalNamesSize
        &signal_names_actual_size,
        nullptr,  // resultNames
        0,        // resultNamesSize
        &result_names_actual_size,
        nullptr,  // snapshotIdentifiers
        0,        // snapshotIdentifiersSize
        &snapshot_identifiers_actual_size,
        nullptr,  // snapshotTimestampArray
        0,        // snapshotTimestampArraySize
        &snapshot_timestamp_array_actual_size);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForNiRFmxInstrHandle(context, status, instrument);
    }
    if (snapshot_info_cache_index != 0) {
      response->mutable_personality_id_array()->Resize(personality_id_array_actual_size, 0);
      int32* personality_id_array = reinterpret_cast<int32*>(response->mutable_personality_id_array()->mutable_data());
      std::string signal_names;
      if (signal_names_actual_size > 0) {
        signal_names.resize(signal_names_actual_size - 1);
      }
      std::string result_names;
      if (result_names_actual_size > 0) {
        result_names.resize(result_names_actual_size - 1);
      }
      std::string snapshot_identifiers;
      if (snapshot_identifiers_actual_size > 0) {
        snapshot_identifiers.resize(snapshot_identifiers_actual_size - 1);
      }
      response->mutable_snapshot_timestamp_array()->Resize(snapshot_timestamp_array_actual_size, 0);
      uInt64* snapshot_timestamp_array = reinterpret_cast<uInt64*>(response->mutable_snapshot_timestamp_array()->mutable_data());
      auto personality_id_array_size = personality_id_array_actual_size;
      auto result_names_size = result_names_actual_size;
      auto signal_names_size = signal_names_actual_size;
      auto snapshot_identifiers_size = snapshot_identifiers_actual_size;
      auto snapshot_timestamp_array_size = snapshot_timestamp_array_actual_size;
      status = library_->GetSnapshotInfoFromCache(
          instrument,
          snapshot_info_cache_index,
          personality_id_array,
          personality_id_array_size,
          &personality_id_array_actual_size,
          (char*)signal_names.data(),
          signal_names_size,
          &signal_names_actual_size,
          (char*)result_names.data(),
          result_names_size,
          &result_names_actual_size,
          (char*)snapshot_identifiers.data(),
          snapshot_identifiers_size,
          &snapshot_identifiers_actual_size,
          snapshot_timestamp_array,
          snapshot_timestamp_array_size,
          &snapshot_timestamp_array_actual_size);
      if (!status_ok(status)) {
        return ConvertApiErrorStatusForNiRFmxInstrHandle(context, status, instrument);
      }
      response->mutable_personality_id_array()->Resize(personality_id_array_actual_size, 0);
      std::string signal_names_utf8;
      convert_to_grpc(signal_names, &signal_names_utf8);
      response->set_signal_names(signal_names_utf8);
      nidevice_grpc::converters::trim_trailing_nulls(*(response->mutable_signal_names()));
      signal_names_actual_size = signal_names_utf8.length() + 1;
      std::string result_names_utf8;
      convert_to_grpc(result_names, &result_names_utf8);
      response->set_result_names(result_names_utf8);
      nidevice_grpc::converters::trim_trailing_nulls(*(response->mutable_result_names()));
      result_names_actual_size = result_names_utf8.length() + 1;
      std::string snapshot_identifiers_utf8;
      convert_to_grpc(snapshot_identifiers, &snapshot_identifiers_utf8);
      response->set_snapshot_identifiers(snapshot_identifiers_utf8);
      nidevice_grpc::converters::trim_trailing_nulls(*(response->mutable_snapshot_identifiers()));
      snapshot_identifiers_actual_size = snapshot_identifiers_utf8.length() + 1;
      response->mutable_snapshot_timestamp_array()->Resize(snapshot_timestamp_array_actual_size, 0);
    }
    response->set_status(status);
    response->set_personality_id_array_actual_size(personality_id_array_actual_size);
    response->set_signal_names_actual_size(signal_names_actual_size);
    response->set_result_names_actual_size(result_names_actual_size);
    response->set_snapshot_identifiers_actual_size(snapshot_identifiers_actual_size);
    response->set_snapshot_timestamp_array_actual_size(snapshot_timestamp_array_actual_size);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiRFmxInstrRestrictedService::GetLatestConfigurationSnapshot(
    ::grpc::ServerContext* context,
    const GetLatestConfigurationSnapshotRequest* request,
    GetLatestConfigurationSnapshotResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto instrument_grpc_session = request->instrument();
    niRFmxInstrHandle instrument = session_repository_->access_session(instrument_grpc_session.name());
    uInt64 snapshot_info_cache_index{};
    int32 personality_id{};
    int32 signal_name_actual_size{};
    int32 snapshot_identifier_actual_size{};
    int32 signal_configuration_state{};
    uInt64 signal_timestamp{};
    auto status = library_->GetLatestConfigurationSnapshot(
        instrument,
        &snapshot_info_cache_index,
        &personality_id,
        nullptr,  // signalName
        0,        // signalNameSize
        &signal_name_actual_size,
        nullptr,  // snapshotIdentifier
        0,        // snapshotIdentifierSize
        &snapshot_identifier_actual_size,
        &signal_configuration_state,
        &signal_timestamp);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForNiRFmxInstrHandle(context, status, instrument);
    }
    if (snapshot_info_cache_index != 0) {
      std::string signal_name;
      if (signal_name_actual_size > 0) {
        signal_name.resize(signal_name_actual_size - 1);
      }
      std::string snapshot_identifier;
      if (snapshot_identifier_actual_size > 0) {
        snapshot_identifier.resize(snapshot_identifier_actual_size - 1);
      }
      auto signal_name_size = signal_name_actual_size;
      auto snapshot_identifier_size = snapshot_identifier_actual_size;
      status = library_->GetSnapshotInfoFromCache(
          instrument,
          snapshot_info_cache_index,
          nullptr,  // personalityIDArray
          0,        // personalityIDArraySize
          nullptr,  // personalityIDArrayActualSize
          (char*)signal_name.data(),
          signal_name_size,
          &signal_name_actual_size,
          nullptr,  // resultNames
          0,        // resultNamesSize
          nullptr,  // resultNamesActualSize
          (char*)snapshot_identifier.data(),
          snapshot_identifier_size,
          &snapshot_identifier_actual_size,
          nullptr,   // snapshotTimestampArray
          0,         // snapshotTimestampArraySize
          nullptr);  // snapshotTimestampArrayActualSize
      if (!status_ok(status)) {
        return ConvertApiErrorStatusForNiRFmxInstrHandle(context, status, instrument);
      }
      std::string signal_name_utf8;
      convert_to_grpc(signal_name, &signal_name_utf8);
      response->set_signal_name(signal_name_utf8);
      nidevice_grpc::converters::trim_trailing_nulls(*(response->mutable_signal_name()));
      signal_name_actual_size = signal_name_utf8.length() + 1;
      std::string snapshot_identifier_utf8;
      convert_to_grpc(snapshot_identifier, &snapshot_identifier_utf8);
      response->set_snapshot_identifier(snapshot_identifier_utf8);
      nidevice_grpc::converters::trim_trailing_nulls(*(response->mutable_snapshot_identifier()));
      snapshot_identifier_actual_size = snapshot_identifier_utf8.length() + 1;
    }
    response->set_status(status);
    response->set_personality_id(personality_id);
    response->set_signal_name_actual_size(signal_name_actual_size);
    response->set_snapshot_identifier_actual_size(snapshot_identifier_actual_size);
    response->set_signal_configuration_state(signal_configuration_state);
    response->set_signal_timestamp(signal_timestamp);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}
}  // namespace nirfmxinstr_restricted_grpc
