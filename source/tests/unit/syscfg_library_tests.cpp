#include <gtest/gtest.h>
#include <server/syscfg_library.h>

namespace internal = ni::hardware::grpc::internal;

namespace ni {
namespace tests {
namespace unit {

#if defined(_MSC_VER)
static const char* kSysCfgApiLibraryName = "nisyscfg.dll";
#else
static const char* kSysCfgApiLibraryName = "libnisyscfg.so";
#endif

TEST(SysCfgLibraryTests, SysCfgLibrary_SharedLibraryNameIsSetToSysCfgLibrary)
{
  internal::SysCfgLibrary syscfg_library;
  std::string shared_library_name = syscfg_library.get_library_name();

  EXPECT_STREQ(kSysCfgApiLibraryName, shared_library_name.c_str());
}


TEST(SysCfgLibraryTests, SysCfgLibrary_SharedLibraryIsNotLoaded)
{
  internal::SysCfgLibrary syscfg_library;

  EXPECT_FALSE(syscfg_library.is_library_loaded());
}

TEST(SysCfgLibraryTests, SysCfgApiNotInstalled_CallInitializeSession_ThrowsLibraryLoadException)
{
  internal::SysCfgLibrary syscfg_library;

  try {
    NISysCfgSessionHandle session = NULL;
    auto status = syscfg_library.InitializeSession("localhost", NULL, NULL, NISysCfgLocaleDefault, NISysCfgBoolTrue, 10000, NULL, &session);

    FAIL() << "LibraryLoadException not thrown";
  }
  catch (internal::LibraryLoadException& ex) {
    EXPECT_STREQ("The NI System Configuration API is not installed on the server.", ex.what());
  }
}

TEST(SysCfgLibraryTests, SysCfgApiNotInstalled_CallCloseHandle_ThrowsLibraryLoadException)
{
  internal::SysCfgLibrary syscfg_library;

  try {
    auto status = syscfg_library.CloseHandle(NULL);

    FAIL() << "LibraryLoadException not thrown";
  }
  catch (internal::LibraryLoadException& ex) {
    EXPECT_STREQ("The NI System Configuration API is not installed on the server.", ex.what());
  }
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
