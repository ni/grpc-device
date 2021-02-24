#include <grpcpp/impl/grpc_library.h>
#include <gtest/gtest.h>

// fixes seg faults caused by https://github.com/grpc/grpc/issues/14633
static grpc::internal::GrpcLibraryInitializer g_gli_initializer;

namespace ni {
namespace tests {
namespace unit {

TEST(SystemTests, StubTest)
{
  EXPECT_TRUE(true);
}

}  // namespace unit
}  // namespace tests
}  // namespace ni