#include <gtest/gtest.h>
#include "core_server/hardware/grpc/internal/shared_library.h"

namespace ni
{
namespace tests
{
namespace unit
{
namespace hardware
{
namespace grpc
{
namespace internal
{

    TEST(SharedLibraryTests, Expect_Less_Than)
    {
        // Simple google less than test with a custom failure message.
        EXPECT_LT(1, 2) << "1 should be less than 2.";
    }

    TEST(SharedLibraryTests, Expect_Equals)
    {
        // Simple google test  with a custom failure message.
        EXPECT_EQ(42, 42) << "42 should equal 42.";
    }

} // namespace impl
} // namespace grpc
} // namespace hardware
} // namespace unit
} // namespace tests
} // namespace ni
