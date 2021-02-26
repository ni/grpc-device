#include <gtest/gtest.h>
#include <stdlib.h>

#include <string>

#if defined(_MSC_VER)
static const char* kPathDelimitter = "\\";
#else
static const char* kPathDelimitter = "/";
#endif

extern const char* g_binary_output_directory;