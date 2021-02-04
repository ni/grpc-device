#ifndef NI_HARDWARE_GRPC_INTERNAL_DEVICEMANAGEMENT
#define NI_HARDWARE_GRPC_INTERNAL_DEVICEMANAGEMENT

#include "session_repository.h"

namespace ni
{
namespace hardware
{
namespace grpc
{
namespace internal
{
   class DeviceManagement
   {
   public:
      DeviceManagement();

      void enumerate_devices(::grpc::ServerContext* context, const EnumerateDevicesRequest* request, EnumerateDevicesResponse* response);
   };
} // namespace internal
} // namespace grpc
} // namespace hardware
} // namespace ni
#endif // NI_HARDWARE_GRPC_INTERNAL_DEVICEMANAGEMENT
