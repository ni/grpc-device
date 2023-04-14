#ifndef NIDEVICE_RESTRICTED_GRPC_CALIBRATION_OPERATIONS_RESTRICTED_SERVICE
#define NIDEVICE_RESTRICTED_GRPC_CALIBRATION_OPERATIONS_RESTRICTED_SERVICE

#include <calibrationoperations_restricted.grpc.pb.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include <string>

#include "feature_toggles.h"
#include "shared_library.h"
#include "syscfg_library_interface.h"
#include "syscfg_resource_accessor.h"

namespace nidevice_restricted_grpc {

static const char* kCalibrationPropertyAccessFailedMessage = "The NI System Configuration API was unable to access the calibration property.";

struct CalibrationOperationsRestrictedFeatureToggles {
  using CodeReadiness = nidevice_grpc::FeatureToggles::CodeReadiness;
  CalibrationOperationsRestrictedFeatureToggles(const nidevice_grpc::FeatureToggles& feature_toggles = {});
  bool is_enabled;
};

class CalibrationOperationsRestrictedService final :
  public CalibrationOperationsRestricted::Service,
  public ::nidevice_restricted_grpc::SysCfgResourceAccessor {
 public:
  CalibrationOperationsRestrictedService(::nidevice_grpc::SysCfgLibraryInterface* library);

  ::grpc::Status GetCalibrationInformation(
    ::grpc::ServerContext* context,
    const GetCalibrationInformationRequest* request,
    GetCalibrationInformationResponse* response) override;

 private:
  ::grpc::Status get_calibration_info(
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
    google::protobuf::Timestamp* recommended_next_calibration_time);
};

}  // namespace nidevice_restricted_grpc

#endif  // NIDEVICE_RESTRICTED_GRPC_CALIBRATION_OPERATIONS_RESTRICTED_SERVICE
