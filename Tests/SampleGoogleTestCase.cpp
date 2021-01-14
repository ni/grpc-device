#include <gtest/gtest.h>

TEST(SampleTest, Expect_Less_Than)
{
    // Simple google less than test with a custom failure message.
    EXPECT_LT(1, 2) << "1 should be less than 2.";
}

TEST(SampleTest, Expect_Equals)
{
    // Simple google test  with a custom failure message.
    EXPECT_EQ(42, 42) << "42 should equal 42.";
}
