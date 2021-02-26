#include <gtest/gtest.h>
#include "tests/utilities/test_environment.h"

const char* kBinaryOutputDirectory;

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  if (argc != 2) {
    std::cerr << "\nUsage: " << argv[0] << " <test-config-folder-path>\n\nExamples:\n\n" << argv[0] << " .\\Release\n\n" << "<exe_filename> .\n\n" ;
    exit(EXIT_FAILURE);
  }
  kBinaryOutputDirectory = strcat(argv[1], kPathDelimitter);
  return RUN_ALL_TESTS();
}
