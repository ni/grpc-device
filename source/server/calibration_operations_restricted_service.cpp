#include "calibration_operations_restricted_service.h"

#include "converters.h"
#include "nisyscfg.h"

namespace nidevice_restricted_grpc {

CalibrationOperationsRestrictedFeatureToggles::CalibrationOperationsRestrictedFeatureToggles(
  const nidevice_grpc::FeatureToggles& feature_toggles)
  : is_enabled(
      feature_toggles.is_feature_enabled("calibrationoperations_restricted", CodeReadiness::kNextRelease))
{
}

CalibrationOperationsRestrictedService::CalibrationOperationsRestrictedService(::nidevice_grpc::SysCfgLibraryInterface* library)
    : SysCfgResourceAccessor(library) {}

::grpc::Status CalibrationOperationsRestrictedService::GetCalibrationInformation(
  ::grpc::ServerContext* context,
  const GetCalibrationInformationRequest* request,
  GetCalibrationInformationResponse* response)
{
  bool supports_internal_calibration_available = false;
  bool supports_internal_calibration = false;
  bool number_of_internal_calibration_details_available = false;
  uint32_t number_of_internal_calibration_details = 0;
  bool internal_calibration_names_available = false;
  bool internal_calibration_last_temperatures_available = false;
  bool internal_calibration_last_times_available = false;
  bool supports_external_calibration_available = false;
  bool supports_external_calibration = false;
  bool external_calibration_last_temperature_available = false;
  double external_calibration_last_temperature = 0.0;
  bool external_calibration_last_time_available = false;
  bool recommended_next_calibration_time_available = false;

  auto status = get_calibration_info(
    context,
    request->device_id(),
    &supports_internal_calibration_available,
    &supports_internal_calibration,
    &number_of_internal_calibration_details_available,
    &number_of_internal_calibration_details,
    &internal_calibration_names_available,
    response->mutable_internal_calibration_names(),
    &internal_calibration_last_temperatures_available,
    response->mutable_internal_calibration_last_temperatures(),
    &internal_calibration_last_times_available,
    response->mutable_internal_calibration_last_times(),
    &supports_external_calibration_available,
    &supports_external_calibration,
    &external_calibration_last_temperature_available,
    &external_calibration_last_temperature,
    &external_calibration_last_time_available,
    response->mutable_external_calibration_last_time(),
    &recommended_next_calibration_time_available,
    response->mutable_recommended_next_calibration_time());

  response->set_supports_internal_calibration_available(supports_internal_calibration_available);
  response->set_supports_internal_calibration(supports_internal_calibration);
  response->set_number_of_internal_calibration_details_available(number_of_internal_calibration_details_available);
  response->set_number_of_internal_calibration_details(number_of_internal_calibration_details);
  response->set_internal_calibration_names_available(internal_calibration_names_available);
  response->set_internal_calibration_last_temperatures_available(internal_calibration_last_temperatures_available);
  response->set_internal_calibration_last_times_available(internal_calibration_last_times_available);
  response->set_supports_external_calibration_available(supports_external_calibration_available);
  response->set_supports_external_calibration(supports_external_calibration);
  response->set_external_calibration_last_temperature_available(external_calibration_last_temperature_available);
  response->set_external_calibration_last_temperature(external_calibration_last_temperature);
  response->set_external_calibration_last_time_available(external_calibration_last_time_available);
  response->set_recommended_next_calibration_time_available(recommended_next_calibration_time_available);

  return status;
}
::grpc::Status CalibrationOperationsRestrictedService::get_calibration_info(
  ::grpc::ServerContext* context,
  const DeviceId& device_id,
  bool* supports_internal_calibration_available,
  bool* supports_internal_calibration,
  bool* number_of_internal_calibration_details_available,
  uint32_t* number_of_internal_calibration_details,
  bool* internal_calibration_names_available,
  google::protobuf::RepeatedPtrField<std::string>* internal_calibration_names,
  bool* internal_calibration_last_temperatures_available,
  google::protobuf::RepeatedField<double>* internal_calibration_last_temperatures,
  bool* internal_calibration_last_times_available,
  google::protobuf::RepeatedPtrField<google::protobuf::Timestamp>* internal_calibration_last_times,
  bool* supports_external_calibration_available,
  bool* supports_external_calibration,
  bool* external_calibration_last_temperature_available,
  double* external_calibration_last_temperature,
  bool* external_calibration_last_time_available,
  google::protobuf::Timestamp* external_calibration_last_time,
  bool* recommended_next_calibration_time_available,
  google::protobuf::Timestamp* recommended_next_calibration_time)
{
  auto get_calibration_data = [&](nidevice_grpc::SysCfgLibraryInterface* library, NISysCfgResourceHandle resource, bool* save_changes) {
    NISysCfgBool syscfg_bool = NISysCfgBoolFalse;
    NISysCfgTimestampUTC syscfg_time = {{0}};
    char syscfg_name[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
    double syscfg_temp = 0.0;
    int local_calibration_internal_details_count = 0;

    // Supports Internal Calibration
    auto status = library->GetResourceProperty(resource, NISysCfgResourcePropertySupportsInternalCalibration, &syscfg_bool);
    if (NISysCfg_Failed(status)) {
      if (status == NISysCfg_PropDoesNotExist) {
        status = NISysCfg_OK;
      }
      else {
        return status;
      }
    }
    else {
      *supports_internal_calibration = syscfg_bool != NISysCfgBoolFalse;
      *supports_internal_calibration_available = true;
    }

    // Number of Internal Calibration Details
    status = library->GetResourceProperty(resource, NISysCfgResourcePropertyNumberOfInternalCalibrationDetails, &local_calibration_internal_details_count);
    if (NISysCfg_Failed(status)) {
      if (status == NISysCfg_PropDoesNotExist) {
        status = NISysCfg_OK;
      }
      else {
        return status;
      }
    }
    else {
      *number_of_internal_calibration_details = static_cast<uint32_t>(local_calibration_internal_details_count);
      *number_of_internal_calibration_details_available = true;
    }

    // Internal Calibration Names
    for (int i = 0; i < local_calibration_internal_details_count; ++i) {
      char internal_calibration_name[NISYSCFG_SIMPLE_STRING_LENGTH] = {0};
      status = library->GetResourceIndexedProperty(resource, NISysCfgIndexedPropertyInternalCalibrationName, i, internal_calibration_name);
      if (NISysCfg_Failed(status)) {
        if (status == NISysCfg_PropDoesNotExist) {
          status = NISysCfg_OK;
          break;
        }
        else {
          return status;
        }
      }
      else {
        internal_calibration_names->Add(internal_calibration_name);
        *internal_calibration_names_available = true;
      }
    }

    // Internal Calibration Last Temperatures
    for (int i = 0; i < local_calibration_internal_details_count; ++i) {
      status = library->GetResourceIndexedProperty(resource, NISysCfgIndexedPropertyInternalCalibrationLastTemp, i, &syscfg_temp);
      if (NISysCfg_Failed(status)) {
        if (status == NISysCfg_PropDoesNotExist) {
          status = NISysCfg_OK;
          break;
        }
        else {
          return status;
        }
      }
      else {
        internal_calibration_last_temperatures->Add(syscfg_temp);
        *internal_calibration_last_temperatures_available = true;
      }
    }

    // Internal Calibration Last Times
    for (int i = 0; i < local_calibration_internal_details_count; ++i) {
      status = library->GetResourceIndexedProperty(resource, NISysCfgIndexedPropertyInternalCalibrationLastTime, i, &syscfg_time);
      if (NISysCfg_Failed(status)) {
        if (status == NISysCfg_PropDoesNotExist) {
          status = NISysCfg_OK;
          break;
        }
        else {
          return status;
        }
      }
      else {
        CVIAbsoluteTime syscfg_time_convert = *reinterpret_cast<CVIAbsoluteTime*>(&syscfg_time);
        nidevice_grpc::converters::convert_to_grpc(syscfg_time_convert, internal_calibration_last_times->Add());
        *internal_calibration_last_times_available = true;
      }
    }

    // Supports External Calibration
    status = library->GetResourceProperty(resource, NISysCfgResourcePropertySupportsExternalCalibration, &syscfg_bool);
    if (NISysCfg_Failed(status)) {
      if (status == NISysCfg_PropDoesNotExist) {
        status = NISysCfg_OK;
      }
      else {
        return status;
      }
    }
    else {
      *supports_external_calibration = syscfg_bool != NISysCfgBoolFalse;
      *supports_external_calibration_available = true;
    }

    // External Calibration Last Temperature
    status = library->GetResourceProperty(resource, NISysCfgResourcePropertyExternalCalibrationLastTemp, &syscfg_temp);
    if (NISysCfg_Failed(status)) {
      if (status == NISysCfg_PropDoesNotExist) {
        status = NISysCfg_OK;
      }
      else {
        return status;
      }
    }
    else {
      *external_calibration_last_temperature = syscfg_temp;
      *external_calibration_last_temperature_available = true;
    }

    // External Calibration Last Time
    status = library->GetResourceProperty(resource, NISysCfgResourcePropertyExternalCalibrationLastTime, &syscfg_time);
    if (NISysCfg_Failed(status)) {
      if (status == NISysCfg_PropDoesNotExist) {
        status = NISysCfg_OK;
      }
      else {
        return status;
      }
    }
    else {
      CVIAbsoluteTime syscfg_time_convert = *reinterpret_cast<CVIAbsoluteTime*>(&syscfg_time);
      nidevice_grpc::converters::convert_to_grpc(syscfg_time_convert, external_calibration_last_time);
      *external_calibration_last_time_available = true;
    }

    // Recommended Next Calibration Time
    status = library->GetResourceProperty(resource, NISysCfgResourcePropertyRecommendedNextCalibrationTime, &syscfg_time);
    if (NISysCfg_Failed(status)) {
      if (status == NISysCfg_PropDoesNotExist) {
        status = NISysCfg_OK;
      }
      else {
        return status;
      }
    }
    else {
      CVIAbsoluteTime syscfg_time_convert = *reinterpret_cast<CVIAbsoluteTime*>(&syscfg_time);
      nidevice_grpc::converters::convert_to_grpc(syscfg_time_convert, recommended_next_calibration_time);
      *recommended_next_calibration_time_available = true;
    }

    return status;
  };

  return access_syscfg_resource_by_device_id_filter(context, device_id, kCalibrationPropertyAccessFailedMessage, get_calibration_data);
}
}  // namespace nidevice_restricted_grpc
