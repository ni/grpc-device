#include <nifpga.pb.h>
#include <nifpga/nifpga_service.h>

namespace nifpga_grpc {
::grpc::Status NiFpgaService::ConvertApiErrorStatusForNiFpga_Session(::grpc::ServerContextBase* context, int32_t status, NiFpga_Session session)
{
  // There is no function in FPGA C API to get error descriptions.
  std::string description("Error");
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}
}  // namespace nifpga_grpc