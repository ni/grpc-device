#include <gtest/gtest.h>

#include "core_server/hardware/grpc/internal/device_management.h"

#if defined(__GNUC__)
  #include <dlfcn.h>
#endif

namespace ni {
namespace tests {
namespace unit {
namespace hardware {
namespace grpc {
namespace internal {

#if defined(_MSC_VER)
static const char* expected_syscfg_api_library_name = "nisyscfg.dll";
#else
static const char* expected_syscfg_api_library_name = "libnisyscfg.so";
#endif

TEST(DeviceManagementTests, DeviceManagementInstance_SharedLibraryNameIsSetToSysCfgLibrary)
{
  ni::hardware::grpc::internal::DeviceManagement device_management;
  std::string library_name = device_management.get_syscfg_library_name();

  EXPECT_STREQ(expected_syscfg_api_library_name, library_name.c_str());
}

TEST(DeviceManagementTests, DeviceManagementInstance_SharedLibraryIsNotLoaded)
{
  ni::hardware::grpc::internal::DeviceManagement device_management;

  EXPECT_FALSE(device_management.is_syscfg_library_loaded());
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace unit
}  // namespace tests
}  // namespace ni
