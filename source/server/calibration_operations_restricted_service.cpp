#include "calibration_operations_restricted_service.h"

#include "converters.h"
#include "nisyscfg.h"

namespace nidevice_restricted_grpc {

CalibrationOperationsRestrictedFeatureToggles::CalibrationOperationsRestrictedFeatureToggles(
    const nidevice_grpc::FeatureToggles& feature_toggles)
    : is_enabled(
          feature_toggles.is_feature_enabled("calibrationoperations_restricted", CodeReadiness::kRestrictedNextRelease))
{
}

CalibrationOperationsRestrictedService::CalibrationOperationsRestrictedService(::nidevice_grpc::SysCfgLibraryInterface* library)
    : SysCfgResourceAccessor(library) {}

::grpc::Status CalibrationOperationsRestrictedService::GetCalibrationInformation(
    ::grpc::ServerContext* context,
    const GetCalibrationInformationRequest* request,
    GetCalibrationInformationResponse* response)
{
  bool calibration_internal_support;
  bool calibration_internal_last_reading_available;
  bool calibration_internal_last_temperature_c_available;
  bool calibration_internal_name_available;
  bool calibration_internal_support_avaliable;
  bool calibration_internal_details_count_available;
  bool calibration_external_support_available;
  bool calibration_external_last_reading_available;
  bool calibration_external_next_reading_available;
  bool calibration_external_last_temperature_c_available;

  google::protobuf::RepeatedPtrField<google::protobuf::Timestamp*> calibration_internal_last_reading;
  double calibration_internal_last_temperature_c;
  google::protobuf::uint32 calibration_internal_details_count;
  bool calibration_external_support;
  google::protobuf::Timestamp calibration_external_last_reading;
  google::protobuf::Timestamp calibration_external_next_reading;
  double calibration_external_last_temperature_c;

  auto status = get_calibration_data(
      context,
      request->device_id(),
      &calibration_internal_last_reading_available,
      response->mutable_calibration_internal_last_reading(),
      &calibration_internal_last_temperature_c_available,
      response->mutable_calibration_internal_last_temperature_c(),
      &calibration_internal_name_available,
      response->mutable_calibration_internal_name(),
      &calibration_internal_support_avaliable,
      &calibration_internal_support,
      &calibration_internal_details_count_available,
      &calibration_internal_details_count,
      &calibration_external_support_available,
      &calibration_external_support,
      &calibration_external_last_reading_available,
      &calibration_external_last_reading,
      &calibration_external_next_reading_available,
      &calibration_external_next_reading,
      &calibration_external_last_temperature_c_available,
      &calibration_external_last_temperature_c);

  response->set_calibration_internal_support(calibration_internal_support);
  response->set_calibration_internal_details_count(calibration_internal_details_count);
  response->set_calibration_external_support(calibration_external_support);
  response->set_allocated_calibration_external_last_reading(&calibration_external_last_reading);
  response->set_allocated_calibration_external_next_reading(&calibration_external_next_reading);
  response->set_calibration_external_last_temperature_c(calibration_external_last_temperature_c);
  return status;
}
::grpc::Status CalibrationOperationsRestrictedService::get_calibration_data(
    ::grpc::ServerContext* context,
    const DeviceId& device_id,
    bool* calibration_internal_last_reading_available,
    google::protobuf::RepeatedPtrField<google::protobuf::Timestamp>* calibration_internal_last_reading,
    bool* calibration_internal_last_temperature_c_available,
    google::protobuf::RepeatedField<double>* calibration_internal_last_temperature_c,
    bool* calibration_internal_name_available,
    google::protobuf::RepeatedPtrField<google::protobuf::string>* calibration_internal_name,
    bool* calibration_internal_support_available,
    bool* calibration_internal_support,
    bool* calibration_internal_details_count_available,
    google::protobuf::uint32* calibration_internal_details_count,
    bool* calibration_external_support_available,
    bool* calibration_external_support,
    bool* calibration_external_last_reading_available,
    google::protobuf::Timestamp* calibration_external_last_reading,
    bool* calibration_external_next_reading_available,
    google::protobuf::Timestamp* calibration_external_next_reading,
    bool* calibration_external_last_temperature_c_available,
    double* calibration_external_last_temperature_c)
{
  auto get_calibration_data = [&](nidevice_grpc::SysCfgLibraryInterface* library, NISysCfgResourceHandle resource, bool* save_changes) {
    NISysCfgBool syscfg_bool = NISysCfgBoolFalse;
    NISysCfgTimestampUTC syscfg_time = {{0}};
    char syscfg_name[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
    double syscfg_temp = 0.0;
    int syscfg_details = 0;
    int internal_calibration_details_count = 0;

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
      *calibration_internal_support = syscfg_bool != NISysCfgBoolFalse;
      *calibration_internal_support_available = true;
    }

    status = library->GetResourceProperty(resource, NISysCfgResourcePropertyNumberOfInternalCalibrationDetails, &syscfg_details);
    if (NISysCfg_Failed(status)) {
      if (status == NISysCfg_PropDoesNotExist) {
        status = NISysCfg_OK;
      }
      else {
        return status;
      }
    }
    else {
      *calibration_internal_details_count = static_cast<google::protobuf::uint32>(syscfg_details);
      *calibration_internal_details_count_available = true;
    }

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
      *calibration_external_support = syscfg_bool != NISysCfgBoolFalse;
      *calibration_external_support_available = true;
    }

    for (int i = 0; i < syscfg_details; ++i) {
      char internal_calibration_name[NISYSCFG_SIMPLE_STRING_LENGTH] = {0};
      status = library->GetResourceIndexedProperty(resource, NISysCfgIndexedPropertyInternalCalibrationName, i, internal_calibration_name);
      if (NISysCfg_Failed(status)) {
        if (status == NISysCfg_PropDoesNotExist) {
          status = NISysCfg_OK;
        }
        else {
          return status;
        }
      }
      else {
        calibration_internal_name->Add(internal_calibration_name);
        *calibration_internal_name_available = true;
      }

      status = library->GetResourceIndexedProperty(resource, NISysCfgIndexedPropertyInternalCalibrationLastTemp, i, &syscfg_temp);
      if (NISysCfg_Failed(status)) {
        if (status == NISysCfg_PropDoesNotExist) {
          status = NISysCfg_OK;
        }
        else {
          return status;
        }
      }
      else {
        calibration_internal_last_temperature_c->Add(syscfg_temp);
        *calibration_internal_last_temperature_c_available = true;
      }

      status = library->GetResourceIndexedProperty(resource, NISysCfgIndexedPropertyInternalCalibrationLastTime, i, &syscfg_time);
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
        nidevice_grpc::converters::convert_to_grpc(syscfg_time_convert, calibration_internal_last_reading->Add());
        *calibration_internal_last_reading_available = true;
      }
    }

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
      nidevice_grpc::converters::convert_to_grpc(syscfg_time_convert, calibration_external_last_reading);
      *calibration_external_last_reading_available = true;
    }

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
      *calibration_external_last_temperature_c = syscfg_temp;
      *calibration_external_last_temperature_c_available = true;
    }

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
      nidevice_grpc::converters::convert_to_grpc(syscfg_time_convert, calibration_external_next_reading);
      *calibration_external_next_reading_available = true;
    }
    return status;
  };
  return access_syscfg_resource_by_device_id_filter(context, device_id, kCalibrationPropertyAccessFailedMessage, get_calibration_data);
}
}  // namespace nidevice_restricted_grpc
