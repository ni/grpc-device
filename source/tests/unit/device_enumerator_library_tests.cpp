#include <gtest/gtest.h>
#include <server/device_enumerator_library.h>

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

TEST(DeviceEnumeratorLibraryTests, CreateDeviceEnumeratorLibrary_SharedLibraryNameIsSetToSysCfgLibrary)
{
  ni::hardware::grpc::internal::DeviceEnumeratorLibrary device_enumerator_library;
  std::string shared_library_name = device_enumerator_library.get_library_name();

  EXPECT_STREQ(kSysCfgApiLibraryName, shared_library_name.c_str());
}


TEST(DeviceEnumeratorLibraryTests, CreateDeviceEnumeratorLibrary_SharedLibraryIsNotLoaded)
{
  ni::hardware::grpc::internal::DeviceEnumeratorLibrary device_enumerator_library;

  EXPECT_FALSE(device_enumerator_library.is_library_loaded());
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
