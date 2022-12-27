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
  google::protobuf::Timestamp calibration_internal_last_reading;
  double calibration_internal_last_temperature_c;
  google::protobuf::uint32 calibration_internal_details_count;
  bool calibration_external_support;
  google::protobuf::Timestamp calibration_external_last_reading;
  google::protobuf::Timestamp calibration_external_next_reading;
  double calibration_external_last_temperature_c;

  auto status = get_calibration_data(context, request->device_id(), &calibration_internal_support, &calibration_internal_last_reading, &calibration_internal_last_temperature_c, &calibration_internal_details_count, response->mutable_calibration_internal_name(), &calibration_external_support, &calibration_external_last_reading, &calibration_external_next_reading, &calibration_external_last_temperature_c);

  response->set_calibration_internal_support(calibration_internal_support);
  response->set_allocated_calibration_internal_last_reading(&calibration_internal_last_reading);
  response->set_calibration_internal_last_temperature_c(calibration_internal_last_temperature_c);
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
    bool* calibration_internal_support,
    google::protobuf::Timestamp* calibration_internal_last_reading,
    double* calibration_internal_last_temperature_c,
    google::protobuf::uint32* calibration_internal_details_count,
    std::string* calibration_internal_name,
    bool* calibration_external_support,
    google::protobuf::Timestamp* calibration_external_last_reading,
    google::protobuf::Timestamp* calibration_external_next_reading,
    double* calibration_external_last_temperature_c)
{
  auto get_calibration_data = [&](nidevice_grpc::SysCfgLibraryInterface* library, NISysCfgResourceHandle resource, bool* save_changes) {
    NISysCfgBool syscfg_bool = NISysCfgBoolFalse;
    NISysCfgTimestampUTC syscfg_time = {{0}};
    char syscfg_name[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
    double syscfg_temp = 0.0;
    int syscfg_details = 0;
    auto status = library->GetResourceProperty(resource, NISysCfgResourcePropertySupportsInternalCalibration, &syscfg_bool);
    if (NISysCfg_Failed(status)) {
      return status;
    }
    *calibration_internal_support = syscfg_bool != NISysCfgBoolFalse;

    status = library->GetResourceProperty(resource, NISysCfgResourcePropertySupportsExternalCalibration, &syscfg_bool);
    if (NISysCfg_Failed(status)) {
      return status;
    }
    *calibration_external_support = syscfg_bool != NISysCfgBoolFalse;

    /* status = library->GetResourceProperty(resource, NISysCfgIndexedPropertyInternalCalibrationName, syscfg_name);
     if (NISysCfg_Failed(status)) {
       return status;
     }
     *calibration_internal_name = std::string(syscfg_name);
     */
    /*status = library->GetResourceProperty(resource, NISysCfgResourcePropertyNumberOfInternalCalibrationDetails, &syscfg_details);
    if (NISysCfg_Failed(status)) {
      return status;
    }
    *calibration_internal_details_count = static_cast<google::protobuf::uint32>(syscfg_details);
    */
    /*status = library->GetResourceProperty(resource, NISysCfgIndexedPropertyInternalCalibrationLastTemp, &syscfg_temp);
    if (NISysCfg_Failed(status)) {
      return status;
    }
    *calibration_internal_last_temperature_c = syscfg_temp;
    */
    status = library->GetResourceProperty(resource, NISysCfgResourcePropertyExternalCalibrationLastTemp, &syscfg_temp);
    if (NISysCfg_Failed(status)) {
      return status;
    }
    *calibration_external_last_temperature_c = syscfg_temp;

    /* status = library->GetResourceProperty(resource, NISysCfgIndexedPropertyInternalCalibrationLastTime, &syscfg_time);
     if (NISysCfg_Failed(status)) {
       return status;
     }
     *calibration_internal_last_reading = *reinterpret_cast<CVIAbsoluteTime*>(&syscfg_time);
 */
    status = library->GetResourceProperty(resource, NISysCfgResourcePropertyExternalCalibrationLastTime, &syscfg_time);
    if (NISysCfg_Failed(status)) {
      return status;
    }
    // convert_to_grpc(CVIAbsoluteTime*(&syscfg_time),*calibration_external_last_reading)
    CVIAbsoluteTime syscfg_time_convert = *reinterpret_cast<CVIAbsoluteTime*>(&syscfg_time);
    nidevice_grpc::converters::convert_to_grpc(syscfg_time_convert, calibration_external_last_reading);
    //*reinterpret_cast<CVIAbsoluteTime*>(&syscfg_time);

    status = library->GetResourceProperty(resource, NISysCfgResourcePropertyRecommendedNextCalibrationTime, &syscfg_time);
    if (NISysCfg_Failed(status)) {
      return status;
    }
    nidevice_grpc::converters::convert_to_grpc(syscfg_time_convert, calibration_external_next_reading);

    return status;
  };
  return access_syscfg_resource_by_device_id_filter(context, device_id, kCalibrationPropertyAccessFailedMessage, get_calibration_data);
}

}  // namespace nidevice_restricted_grpc
