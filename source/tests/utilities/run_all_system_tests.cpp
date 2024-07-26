#include <gtest/gtest.h>
#include <iostream>

int main(int argc, char** argv)
{
  std::cout << "Before setlocale" << std::endl;
  // setlocale(LC_ALL, "");
  std::cout << "After setlocale" << std::endl;
  ::testing::InitGoogleTest(&argc, argv);
  const int run_result = RUN_ALL_TESTS();
  std::cout << "Run_result: " << run_result << std::endl;
  return run_result;
}

TEST(TrivialTest, Add) {
  const int result = 5 * 5;
  EXPECT_EQ(25, result);
}
