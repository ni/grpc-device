#include "calibration_operations_restricted_service.h"

#include "converters.h"
#include "nisyscfg.h"

namespace nidevice_restricted_grpc {

CalibrationOperationsRestrictedFeatureToggles::CalibrationOperationsRestrictedFeatureToggles(
  const nidevice_grpc::FeatureToggles& feature_toggles)
  : is_enabled(
      feature_toggles.is_feature_enabled("calibrationoperations_restricted", CodeReadiness::kRelease))
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
  bool supports_external_calibration_available = false;
  bool supports_external_calibration = false;
  bool external_calibration_last_temperature_available = false;
  double external_calibration_last_temperature = 0.0;
  bool external_calibration_last_time_available = false;
  google::protobuf::Timestamp external_calibration_last_time;
  bool recommended_next_calibration_time_available = false;
  google::protobuf::Timestamp recommended_next_calibration_time;

  auto status = get_calibration_info(
    context,
    request->device_id(),
    &supports_internal_calibration_available,
    &supports_internal_calibration,
    &number_of_internal_calibration_details_available,
    &number_of_internal_calibration_details,
    response->mutable_internal_calibration_names(),
    response->mutable_internal_calibration_last_temperatures(),
    response->mutable_internal_calibration_last_times(),
    &supports_external_calibration_available,
    &supports_external_calibration,
    &external_calibration_last_temperature_available,
    &external_calibration_last_temperature,
    &external_calibration_last_time_available,
    &external_calibration_last_time,
    &recommended_next_calibration_time_available,
    &recommended_next_calibration_time);

  if (supports_internal_calibration_available) {
    response->set_supports_internal_calibration(supports_internal_calibration);
  }
  if (number_of_internal_calibration_details_available) {
    response->set_number_of_internal_calibration_details(number_of_internal_calibration_details);
  }
  if (supports_external_calibration_available) {
    response->set_supports_external_calibration(supports_external_calibration);
  }
  if (external_calibration_last_temperature_available) {
    response->set_external_calibration_last_temperature(external_calibration_last_temperature);
  }
  if (external_calibration_last_time_available) {
    *response->mutable_external_calibration_last_time() = external_calibration_last_time;
  }
  if (recommended_next_calibration_time_available) {
    *response->mutable_recommended_next_calibration_time() = recommended_next_calibration_time;
  }

  return status;
}

static void AssignIfAvailable(bool* available, std::function<void()> set_value_func, NISysCfgStatus& status)
{
  if (NISysCfg_Failed(status)) {
    *available = false;
    if (status == NISysCfg_PropDoesNotExist) {
      status = NISysCfg_OK;
    }
  }
  else {
    *available = true;
    set_value_func();
  }
}

::grpc::Status CalibrationOperationsRestrictedService::get_calibration_info(
  ::grpc::ServerContext* context,
  const DeviceId& device_id,
  bool* supports_internal_calibration_available,
  bool* supports_internal_calibration,
  bool* number_of_internal_calibration_details_available,
  uint32_t* number_of_internal_calibration_details,
  google::protobuf::RepeatedPtrField<std::string>* internal_calibration_names,
  google::protobuf::RepeatedField<double>* internal_calibration_last_temperatures,
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
    char syscfg_string[NISYSCFG_SIMPLE_STRING_LENGTH] = {0};
    double syscfg_double = 0.0;
    int syscfg_int = 0;
    int local_number_of_internal_calibration_details = 0;

    // Supports Internal Calibration
    auto status = library->GetResourceProperty(resource, NISysCfgResourcePropertySupportsInternalCalibration, &syscfg_bool);
    auto set_supports_internal_calibration_func = [&] () {
      *supports_internal_calibration = syscfg_bool != NISysCfgBoolFalse;
    };
    AssignIfAvailable(supports_internal_calibration_available, set_supports_internal_calibration_func, status);
    if (NISysCfg_Failed(status)) {
      return status;
    }

    // Number of Internal Calibration Details
    status = library->GetResourceProperty(resource, NISysCfgResourcePropertyNumberOfInternalCalibrationDetails, &syscfg_int);
    auto set_number_of_internal_calibration_details_func = [&] () {
      local_number_of_internal_calibration_details = syscfg_int;
      *number_of_internal_calibration_details = static_cast<uint32_t>(syscfg_int);
    };
    AssignIfAvailable(number_of_internal_calibration_details_available, set_number_of_internal_calibration_details_func, status);
    if (NISysCfg_Failed(status)) {
      return status;
    }

    // Internal Calibration Names
    for (int i = 0; i < local_number_of_internal_calibration_details; ++i) {
      status = library->GetResourceIndexedProperty(resource, NISysCfgIndexedPropertyInternalCalibrationName, i, syscfg_string);
      auto set_internal_calibration_names_func = [&] () {
        internal_calibration_names->Add(syscfg_string);
      };
      bool internal_calibration_names_available = false;
      AssignIfAvailable(&internal_calibration_names_available, set_internal_calibration_names_func, status);
      if (NISysCfg_Failed(status)) {
        return status;
      }
      if (!internal_calibration_names_available) {
        break;
      }
    }

    // Internal Calibration Last Temperatures
    for (int i = 0; i < local_number_of_internal_calibration_details; ++i) {
      status = library->GetResourceIndexedProperty(resource, NISysCfgIndexedPropertyInternalCalibrationLastTemp, i, &syscfg_double);
      auto set_internal_calibration_last_temperatures_func = [&] () {
        internal_calibration_last_temperatures->Add(syscfg_double);
      };
      bool internal_calibration_last_temperatures_available = false;
      AssignIfAvailable(&internal_calibration_last_temperatures_available, set_internal_calibration_last_temperatures_func, status);
      if (NISysCfg_Failed(status)) {
        return status;
      }
      if (!internal_calibration_last_temperatures_available) {
        break;
      }
    }

    // Internal Calibration Last Times
    for (int i = 0; i < local_number_of_internal_calibration_details; ++i) {
      status = library->GetResourceIndexedProperty(resource, NISysCfgIndexedPropertyInternalCalibrationLastTime, i, &syscfg_time);
      auto set_internal_calibration_last_times_func = [&] () {
        CVIAbsoluteTime syscfg_time_convert = *reinterpret_cast<CVIAbsoluteTime*>(&syscfg_time);
        nidevice_grpc::converters::convert_to_grpc(syscfg_time_convert, internal_calibration_last_times->Add());
      };
      bool internal_calibration_last_times_available = false;
      AssignIfAvailable(&internal_calibration_last_times_available, set_internal_calibration_last_times_func, status);
      if (NISysCfg_Failed(status)) {
        return status;
      }
      if (!internal_calibration_last_times_available) {
        break;
      }
    }

    // Supports External Calibration
    status = library->GetResourceProperty(resource, NISysCfgResourcePropertySupportsExternalCalibration, &syscfg_bool);
    auto set_supports_external_calibration_func = [&] () {
      *supports_external_calibration = syscfg_bool != NISysCfgBoolFalse;
    };
    AssignIfAvailable(supports_external_calibration_available, set_supports_external_calibration_func, status);
    if (NISysCfg_Failed(status)) {
      return status;
    }

    // External Calibration Last Temperature
    status = library->GetResourceProperty(resource, NISysCfgResourcePropertyExternalCalibrationLastTemp, &syscfg_double);
    auto set_external_calibration_last_temperature_func = [&] () {
      *external_calibration_last_temperature = syscfg_double;
    };
    AssignIfAvailable(external_calibration_last_temperature_available, set_external_calibration_last_temperature_func, status);
    if (NISysCfg_Failed(status)) {
      return status;
    }

    // External Calibration Last Time
    status = library->GetResourceProperty(resource, NISysCfgResourcePropertyExternalCalibrationLastTime, &syscfg_time);
    auto set_external_calibration_last_time_func = [&] () {
      CVIAbsoluteTime syscfg_time_convert = *reinterpret_cast<CVIAbsoluteTime*>(&syscfg_time);
      nidevice_grpc::converters::convert_to_grpc(syscfg_time_convert, external_calibration_last_time);
    };
    AssignIfAvailable(external_calibration_last_time_available, set_external_calibration_last_time_func, status);
    if (NISysCfg_Failed(status)) {
      return status;
    }

    // Recommended Next Calibration Time
    status = library->GetResourceProperty(resource, NISysCfgResourcePropertyRecommendedNextCalibrationTime, &syscfg_time);
    auto set_recommended_next_calibration_time_func = [&] () {
      CVIAbsoluteTime syscfg_time_convert = *reinterpret_cast<CVIAbsoluteTime*>(&syscfg_time);
      nidevice_grpc::converters::convert_to_grpc(syscfg_time_convert, recommended_next_calibration_time);
    };
    AssignIfAvailable(recommended_next_calibration_time_available, set_recommended_next_calibration_time_func, status);

    return status;
  };

  return access_syscfg_resource_by_device_id_filter(context, device_id, kCalibrationPropertyAccessFailedMessage, get_calibration_data);
}

}  // namespace nidevice_restricted_grpc
