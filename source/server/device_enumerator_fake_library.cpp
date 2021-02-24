#include "device_enumerator_fake_library.h"

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

::grpc::Status DeviceEnumeratorFakeLibrary::check_library_exists()
{
  return ::grpc::Status::OK;
}

NISysCfgStatus DeviceEnumeratorFakeLibrary::FindHardware()
{
  resources.clear();
  resources.push_back(Resource("SimulatedScope1"));
  resources.push_back(Resource("SimulatedSwitch1"));
  it = resources.begin();
  return NISysCfg_OK;
}

NISysCfgStatus DeviceEnumeratorFakeLibrary::NextResource(NISysCfgResourceHandle* resourceHandle)
{
  if (resourceHandle && it != resources.end()) {
    *resourceHandle = reinterpret_cast<NISysCfgResourceHandle>(&(*it));
    it++;
    return NISysCfg_OK;
  }
  return NISysCfg_EndOfEnum;
}

NISysCfgStatus DeviceEnumeratorFakeLibrary::GetResourceProperty(NISysCfgEnumResourceHandle resourceEnumHandle, void* value)
{
  r_handle h1 = reinterpret_cast<r_handle>(resourceEnumHandle);
  if (value) {
    strcpy(static_cast<char*>(value), h1->name.c_str());
  }
  return NISysCfg_OK;
}

NISysCfgStatus DeviceEnumeratorFakeLibrary::CloseHandle(void* sysCfgHandle)
{
  return NISysCfg_OK;
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni
