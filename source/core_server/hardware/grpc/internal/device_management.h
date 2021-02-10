#ifndef NI_HARDWARE_GRPC_INTERNAL_DEVICEMANAGEMENT
#define NI_HARDWARE_GRPC_INTERNAL_DEVICEMANAGEMENT

#include "session_repository.h"
#include "shared_library.h"
#include "nisyscfg.h"

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

      NISysCfgStatus enumerate_devices(SharedLibrary* shared_library, google::protobuf::RepeatedPtrField<NiDeviceProperties>* devices);
   };
} // namespace internal
} // namespace grpc
} // namespace hardware
} // namespace ni
#endif // NI_HARDWARE_GRPC_INTERNAL_DEVICEMANAGEMENT
