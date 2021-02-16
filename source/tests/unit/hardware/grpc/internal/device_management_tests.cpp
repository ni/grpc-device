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
static const char* mock_syscfg_api_library_name = "mocksyscfg.dll";
#else
static const char* expected_syscfg_api_library_name = "libnisyscfg.so";
static const char* mock_syscfg_api_library_name = "mocksyscfg.so";
#endif

TEST(DeviceManagementTests, CreateDeviceManagement_SharedLibraryNameIsSetToSysCfgLibrary)
{
  ni::hardware::grpc::internal::DeviceManagement device_management;
  std::string shared_library_name = device_management.get_syscfg_library_name();

  EXPECT_STREQ(expected_syscfg_api_library_name, shared_library_name.c_str());
}

TEST(DeviceManagementTests, CreateDeviceManagementWithMockLibraryName_SharedLibraryNameIsSetToMockLibrary)
{
  ni::hardware::grpc::internal::DeviceManagement device_management(mock_syscfg_api_library_name);
  std::string shared_library_name = device_management.get_syscfg_library_name();

  EXPECT_STREQ(mock_syscfg_api_library_name, shared_library_name.c_str());
}

TEST(DeviceManagementTests, CreateDeviceManagement_SharedLibraryIsNotLoaded)
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
