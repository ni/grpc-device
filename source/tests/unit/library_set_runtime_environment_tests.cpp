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
using ::testing::AtLeast;
using ::testing::StrEq;
using ::testing::Return;

void FunctionToPointAt() {}

TEST(LibrarySetRuntimeEnvironmentTests, Library_SetRuntimeEnvironmentFound_CallsSetRuntimeEnvironment)
{
  auto p_shared_library = std::make_shared<MockSharedLibrary>();
  EXPECT_CALL(*p_shared_library, set_library_name(_))
    .Times(1);
  EXPECT_CALL(*p_shared_library, load())
    .Times(1);
  EXPECT_CALL(*p_shared_library, is_loaded())
    .WillOnce(Return(true)); // the constructor will bail out early if false

  const char* func_name = "niSwitch_SetRuntimeEnvironment";

  ON_CALL(*p_shared_library, get_function_pointer(_))
    .WillByDefault(Return(nullptr));
  // We must return an address for SetRuntimeEnvironment or we won't call it.
  ON_CALL(*p_shared_library, get_function_pointer(func_name))
    .WillByDefault(Return(&FunctionToPointAt));
  EXPECT_CALL(*p_shared_library, get_function_pointer(_))
    .Times(AtLeast(1));
  EXPECT_CALL(*p_shared_library, get_function_pointer(func_name))
    .Times(1);

  auto library = std::make_shared<niswitch_grpc::NiSwitchLibrary>(p_shared_library);
  EXPECT_TRUE(library->is_runtime_environment_set());
}

TEST(LibrarySetRuntimeEnvironmentTests, Library_SetRuntimeEnvironmentNotFound_DoesNotCallSetRuntimeEnvironment)
{
  auto p_shared_library = std::make_shared<MockSharedLibrary>();
  EXPECT_CALL(*p_shared_library, set_library_name(_))
    .Times(1);
  EXPECT_CALL(*p_shared_library, load())
    .Times(1);
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