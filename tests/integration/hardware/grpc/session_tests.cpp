#include <gtest/gtest.h>

TEST(SessionTest, Run_Server)
{
    ni::hardware::grpc::CoreService service = new ni::hardware::grpc::CoreService();
    // Simple google less than test with a custom failure message.
    EXPECT_LT(4, 2) << "1 should be less than 2.";
}
