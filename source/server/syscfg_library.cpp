#include "syscfg_library.h"

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

#if defined(_MSC_VER)
static const char* kSysCfgApiLibraryName = "nisyscfg.dll";
#else
static const char* kSysCfgApiLibraryName = "libnisyscfg.so";
#endif

SysCfgLibrary::SysCfgLibrary()
    : shared_library_(kSysCfgApiLibraryName)
{
  // Delay loading of nisyscfg dll and initializing function pointers will be implemented in upcoming PRs.
}

SysCfgLibrary::~SysCfgLibrary()
{
}

NISysCfgStatus SysCfgLibrary::InitializeSession()
{
  // In future it will be updated to use function pointers to syscfg APIs. 
  // Now for proving dummy implementation, throwing exception that library is not found.
  if (!shared_library_.is_loaded()) {
    std::string message("Could not load the library: ");
    message += kSysCfgApiLibraryName;
    throw ni::hardware::grpc::internal::LibraryLoadException(message);
  }
  return NISysCfg_OK;
}

std::string SysCfgLibrary::get_library_name() const
{
  return shared_library_.get_library_name();
}

bool SysCfgLibrary::is_library_loaded() const
{
  return shared_library_.is_loaded();
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni
