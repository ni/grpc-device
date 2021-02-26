#include <gtest/gtest.h>

#include <string>
#include <stdlib.h>

#if defined(_MSC_VER)
static const char* kPathDelimitter = "\\";
#else
static const char* kPathDelimitter = "/";
#endif

extern std::string g_binary_output_directory;