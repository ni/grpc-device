#include <nifpga.pb.h>
#include <nifpga/nifpga_service.h>

namespace nifpga_grpc {
::grpc::Status NiFpgaService::ConvertApiErrorStatusForNiFpga_Session(::grpc::ServerContextBase* context, int32_t status, NiFpga_Session session)
{
  // There is no function in FPGA C API to get error descriptions.
  std::string description("Error");
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

struct MonikerI32Data
{
    NiFpga_Session session;
    uint32_t item;
    nifpga_grpc::I32Data data;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

struct MonikerU32Data
{
    NiFpga_Session session;
    uint32_t item;
    nifpga_grpc::U32Data data;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

struct MonikerI64Data
{
    NiFpga_Session session;
    uint32_t item;
    nifpga_grpc::I64Data data;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};

struct MonikerU64Data
{
    NiFpga_Session session;
    uint32_t item;
    nifpga_grpc::U64Data data;
    std::shared_ptr<NiFpgaLibraryInterface> library;
};
}  // namespace nifpga_grpc