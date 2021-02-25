#include <gtest/gtest.h>
#include <server/syscfg_library.h>

namespace ni {
namespace tests {
namespace unit {

#if defined(_MSC_VER)
static const char* kSysCfgApiLibraryName = "nisyscfg.dll";
#else
static const char* kSysCfgApiLibraryName = "libnisyscfg.so";
#endif

TEST(SysCfgLibraryTests, CreateDeviceEnumeratorLibrary_SharedLibraryNameIsSetToSysCfgLibrary)
{
  ni::hardware::grpc::internal::SysCfgLibrary syscfg_library;
  std::string shared_library_name = syscfg_library.get_library_name();

  EXPECT_STREQ(kSysCfgApiLibraryName, shared_library_name.c_str());
}


TEST(SysCfgLibraryTests, CreateDeviceEnumeratorLibrary_SharedLibraryIsNotLoaded)
{
  ni::hardware::grpc::internal::SysCfgLibrary syscfg_library;

  EXPECT_FALSE(syscfg_library.is_library_loaded());
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
