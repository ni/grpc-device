#include "syscfg_library.h"

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

SysCfgLibrary::SysCfgLibrary()
    : shared_library_(kSysCfgApiLibraryName)
{
  // Delay loading of nisyscfg dll and initializing function pointers will be implemented in upcoming PRs.
}

SysCfgLibrary::~SysCfgLibrary()
{
}

std::string SysCfgLibrary::get_library_name() const
{
  return shared_library_.get_library_name();
}

bool SysCfgLibrary::is_library_loaded() const
{
  return shared_library_.is_loaded();
}

NISysCfgStatus SysCfgLibrary::InitializeSession()
{
  // In future it will be updated to use function pointers to syscfg APIs.
  // Now for proving dummy implementation, throwing exception that library is not found.
  if (!shared_library_.is_loaded()) {
    throw LibraryLoadException(kSysCfgApiNotInstalledMessage);
  }
  return NISysCfg_OK;
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni
