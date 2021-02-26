#include <gtest/gtest.h>
#include "tests/utilities/test_environment.h"

const char* g_binary_output_directory;

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  if (argc != 2) {
    std::cerr << "\nUsage: " << argv[0] << " <default-config-folder-path>\nExample: " << argv[0] << " .\\Release\n";
    exit(EXIT_FAILURE);
  }
  g_binary_output_directory = strcat(argv[1], kPathDelimitter);
  return RUN_ALL_TESTS();
}
