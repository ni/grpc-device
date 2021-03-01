#include <gtest/gtest.h>
#include <server/syscfg_library.h>

namespace internal = ni::hardware::grpc::internal;

namespace ni {
namespace tests {
namespace unit {

TEST(SysCfgLibraryTests, CreateSysCfgLibrary_SharedLibraryNameIsSetToSysCfgLibrary)
{
  internal::SysCfgLibrary syscfg_library;
  std::string shared_library_name = syscfg_library.get_library_name();

  EXPECT_STREQ(internal::kSysCfgApiLibraryName, shared_library_name.c_str());
}


TEST(SysCfgLibraryTests, CreateSysCfgLibrary_SharedLibraryIsNotLoaded)
{
  internal::SysCfgLibrary syscfg_library;

  EXPECT_FALSE(syscfg_library.is_library_loaded());
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
