#include <gtest/gtest.h>
// Use NI-SWITCH instead of NI-FAKE because nifake.h is missing a bunch of functions specified in metadata
// and they're difficult to properly add in source.
#include <niswitch/niswitch_library.h>
#include "mock_shared_library.h"
#include "version.h"

namespace ni {
namespace tests {
namespace unit {

using ::testing::_;
using ::testing::Return;

void FunctionToPointAt() {}

TEST(LibrarySetRuntimeEnvironmentTests, Library_SetRuntimeEnvironmentFound_CallsSetRuntimeEnvironment)
{
  auto p_shared_library = std::make_shared<MockSharedLibrary>();
  EXPECT_CALL(*p_shared_library, set_library_name(_));
  EXPECT_CALL(*p_shared_library, load());
  EXPECT_CALL(*p_shared_library, is_loaded())
    .WillOnce(Return(true)); // the constructor will bail out early if false

  const char* func_name = "niSwitch_SetRuntimeEnvironment";

  EXPECT_CALL(*p_shared_library, get_function_pointer(_))
    .WillRepeatedly(Return(nullptr));
  // We must return an address for SetRuntimeEnvironment or we won't call it.
  EXPECT_CALL(*p_shared_library, get_function_pointer(func_name))
    .WillOnce(Return(const_cast<const void*>(reinterpret_cast<void*>(&FunctionToPointAt))));

  auto library = std::make_shared<niswitch_grpc::NiSwitchLibrary>(p_shared_library);
  EXPECT_TRUE(library->is_runtime_environment_set());
}

TEST(LibrarySetRuntimeEnvironmentTests, Library_SetRuntimeEnvironmentNotFound_DoesNotCallSetRuntimeEnvironment)
{
  auto p_shared_library = std::make_shared<MockSharedLibrary>();
  EXPECT_CALL(*p_shared_library, set_library_name(_));
  EXPECT_CALL(*p_shared_library, load());
  EXPECT_CALL(*p_shared_library, is_loaded())
    .WillOnce(Return(true)); // the constructor will bail out early if false
  EXPECT_CALL(*p_shared_library, get_function_pointer(_))
    .WillRepeatedly(Return(nullptr)); // means a function wasn't found

  auto library = std::make_shared<niswitch_grpc::NiSwitchLibrary>(p_shared_library);
  EXPECT_FALSE(library->is_runtime_environment_set());
}

}  // namespace unit
}  // namespace tests
}  // namespace ni