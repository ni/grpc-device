#ifndef NIDEVICE_RESTRICTED_GRPC_CALIBRATION_OPERATIONS_RESTRICTED_SERVICE
#define NIDEVICE_RESTRICTED_GRPC_CALIBRATION_OPERATIONS_RESTRICTED_SERVICE

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include <string>

#include "feature_toggles.h"
#include "shared_library.h"
#include "syscfg_library_interface.h"
#include "syscfg_session_handler.h"

namespace nidevice_restricted_grpc {

struct CalibrationOperationsRestrictedFeatureToggles {
  using CodeReadiness = nidevice_grpc::FeatureToggles::CodeReadiness;
  CalibrationOperationsRestrictedFeatureToggles(const nidevice_grpc::FeatureToggles& feature_toggles = {});
  bool is_enabled;
};

class CalibrationOperationsRestrictedService final : public CalibrationOperationsRestricted::Service,
                                                     public ::nidevice_grpc::SysCfgSessionHandler {
 public:
  CalibrationOperationsRestrictedService(::nidevice_grpc::SysCfgLibraryInterface* library);

  ::grpc::Status CalibrationOperationsRestricted::Service::GetCalibrationInformation(
      ::grpc::ServerContext* context,
      const GetCalibrationInformationRequest* request,
      GetCalibrationInformationResponse* response) override;

 private:
  :grpc::Status CalibrationOperationsRestrictedService::get_calibration_data(
    ::grpc::ServerContext* context,
    const DeviceId& device_id,
    bool* calibration_internal_support,
    google.protobuf.Timestamp* calibration_internal_last_reading,
    double* calibration_internal_last_temperature_c,
    google.protobuf.uint32* calibration_internal_details_count,
    std::string* calibration_internal_name,
    bool* calibration_external_support,
    google.protobuf.Timestamp* calibration_external_last_reading,
    google.protobuf.Timestamp* calibration_external_next_reading,
    double* calibration_external_last_temperature_c);
};

}  // namespace nidevice_restricted_grpc

#endif  // NIDEVICE_RESTRICTED_GRPC_CALIBRATION_OPERATIONS_RESTRICTED_SERVICE
