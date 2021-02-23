#include <gtest/gtest.h>

#include "core_server/hardware/grpc/internal/device_enumerator.h"

namespace ni {
namespace tests {
namespace unit {

#if defined(_MSC_VER)
static const char* kSysCfgApiLibraryName = "nisyscfg.dll";
static const char* kFakeSysCfgApiLibraryName = "FakeSysCfgApi.dll";
#else
static const char* kSysCfgApiLibraryName = "libnisyscfg.so";
static const char* kFakeSysCfgApiLibraryName = "FakeSysCfgApi.so";
#endif

TEST(DeviceEnumeratorTests, CreateDeviceEnumerator_SharedLibraryNameIsSetToSysCfgLibrary)
{
  ni::hardware::grpc::internal::DeviceEnumerator device_management;
  std::string shared_library_name = device_management.get_syscfg_library_name();

  EXPECT_STREQ(kSysCfgApiLibraryName, shared_library_name.c_str());
}

TEST(DeviceEnumeratorTests, CreateDeviceEnumeratorWithFakeLibraryName_SharedLibraryNameIsSetToFakeLibrary)
{
  ni::hardware::grpc::internal::DeviceEnumerator device_management(kFakeSysCfgApiLibraryName);
  std::string shared_library_name = device_management.get_syscfg_library_name();

  EXPECT_STREQ(kFakeSysCfgApiLibraryName, shared_library_name.c_str());
}

TEST(DeviceEnumeratorTests, CreateDeviceEnumerator_SharedLibraryIsNotLoaded)
{
  ni::hardware::grpc::internal::DeviceEnumerator device_management;

  EXPECT_FALSE(device_management.is_syscfg_library_loaded());
}

<<<<<<< HEAD:source/tests/unit/hardware/grpc/internal/device_enumerator_tests.cpp
TEST(DeviceEnumeratorTests, DeviceEnumerator_SysCfgSessionWithReinitializeTrueReturnsValidSession)
{
  ni::hardware::grpc::internal::DeviceEnumerator device_management;

  EXPECT_NE(nullptr, device_management.get_syscfg_session());
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
=======
>>>>>>> main:source/tests/unit/device_enumerator_tests.cpp
}  // namespace unit
}  // namespace tests
}  // namespace ni
