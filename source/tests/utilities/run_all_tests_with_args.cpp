#include <gtest/gtest.h>
#include "tests/utilities/test_environment.h"

std::string g_binary_output_directory;

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  if (argc == 2) {
    g_binary_output_directory = std::string(argv[1]) + kPathDelimitter;
  }
  return RUN_ALL_TESTS();
}
