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

class CalibrationOperationsRestrictedService final : public CalibrationOperationsRestricted::Service,
                                                     public ::nidevice_restricted_grpc::SysCfgResourceAccessor {
 public:
  CalibrationOperationsRestrictedService(::nidevice_grpc::SysCfgLibraryInterface* library);

  ::grpc::Status GetCalibrationInformation(
      ::grpc::ServerContext* context,
      const GetCalibrationInformationRequest* request,
      GetCalibrationInformationResponse* response) override;

 private:
  ::grpc::Status get_calibration_data(
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
      double* calibration_external_last_temperature_c);
};

}  // namespace nidevice_restricted_grpc

#endif  // NIDEVICE_RESTRICTED_GRPC_CALIBRATION_OPERATIONS_RESTRICTED_SERVICE
