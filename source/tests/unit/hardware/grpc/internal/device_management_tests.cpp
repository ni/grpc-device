#include <gtest/gtest.h>

#include "core_server/hardware/grpc/internal/device_management.h"

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

TEST(DeviceManagementTests, CreateDeviceManagement_SharedLibraryNameIsSetToSysCfgLibrary)
{
  ni::hardware::grpc::internal::SharedLibrary shared_library;
  ni::hardware::grpc::internal::DeviceManagement device_management(&shared_library);
  std::string shared_library_name = shared_library.get_library_name();

  EXPECT_STREQ(expected_syscfg_api_library_name, shared_library_name.c_str());
}

TEST(DeviceManagementTests, CreateDeviceManagement_SharedLibraryIsNotLoaded)
{
  ni::hardware::grpc::internal::SharedLibrary shared_library;
  ni::hardware::grpc::internal::DeviceManagement device_management(&shared_library);

  EXPECT_FALSE(shared_library.is_loaded());
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace unit
}  // namespace tests
}  // namespace ni
