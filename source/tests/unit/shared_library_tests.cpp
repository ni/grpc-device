#include <gtest/gtest.h>
#include <server/shared_library.h>

#if defined(__GNUC__)
  #include <dlfcn.h>
#endif

namespace ni {
namespace tests {
namespace unit {

using TestSession = void*;
using TestApiCreateSessionPtr = int (*)(TestSession* session);
using TestApiCloseSessionPtr = int (*)(TestSession session);
using TestApiWriteSessionDataPtr = int (*)(TestSession session, int attribute_id, const char* value);
using TestApiReadSessionDataPtr = int (*)(TestSession session, int attribute_id, size_t* value_length, char* value_buffer);
using TestApiRemoveSessionDataPtr = int (*)(TestSession session, int attribute_id);

#if defined(_MSC_VER)
static const char* test_library_name = "TestApi.dll";
static const char* wrong_library_name = "WrongTestApi.dll";
#else
static const char* test_library_name = "./libTestApi.so";
static const char* wrong_library_name = "./libWrongTestApi.so";
#endif

TEST(SharedLibraryTests, ValidNameForLibrary_Load_IsLoadedReturnsTrue)
{
  nidevice_grpc::SharedLibrary library(test_library_name);

  library.load();

  EXPECT_TRUE(library.is_loaded()) << "The library should have loaded.";
}

TEST(SharedLibraryTests, ValidNameForLibrary_Load_GetHandleReturnsValue)
{
  nidevice_grpc::SharedLibrary library(test_library_name);

  library.load();

  EXPECT_NE(nullptr, library.get_handle());
}

TEST(SharedLibraryTests, LibraryLoaded_Unload_UnloadsLibrary)
{
  nidevice_grpc::SharedLibrary library(test_library_name);
  library.load();

  library.unload();

  EXPECT_FALSE(library.is_loaded());
  EXPECT_EQ(nullptr, library.get_handle());
}

TEST(SharedLibraryTests, InvalidNameForLibrary_Load_IsLoadedReturnsFalse)
{
  nidevice_grpc::SharedLibrary library(wrong_library_name);

  library.load();

  EXPECT_FALSE(library.is_loaded());
}

TEST(SharedLibraryTests, InvalidNameForLibrary_Load_GetHandleReturnsNull)
{
  nidevice_grpc::SharedLibrary library(wrong_library_name);

  library.load();

  EXPECT_EQ(nullptr, library.get_handle());
}

TEST(SharedLibraryTests, LibraryNotLoaded_GetFunctionPointerWithExistingFunctionName_ReturnsNull)
{
  nidevice_grpc::SharedLibrary library(test_library_name);

  auto createSession = library.get_function_pointer("niTestApiCreateSession");

  EXPECT_EQ(nullptr, createSession);
}

TEST(SharedLibraryTests, LibraryLoaded_GetFunctionPointersWithExistingFunctionName_ReturnsValidFunctionPointers)
{
  nidevice_grpc::SharedLibrary library(test_library_name);
  library.load();

  auto createSession = reinterpret_cast<TestApiCreateSessionPtr>(library.get_function_pointer("niTestApiCreateSession"));
  auto closeSession = reinterpret_cast<TestApiCloseSessionPtr>(library.get_function_pointer("niTestApiCloseSession"));
  auto writeData = reinterpret_cast<TestApiWriteSessionDataPtr>(library.get_function_pointer("niTestApiWriteSessionData"));
  auto readData = reinterpret_cast<TestApiReadSessionDataPtr>(library.get_function_pointer("niTestApiReadSessionData"));

  EXPECT_NE(nullptr, createSession);
  EXPECT_NE(nullptr, closeSession);
  EXPECT_NE(nullptr, writeData);
  EXPECT_NE(nullptr, readData);
}

TEST(SharedLibraryTests, LibraryLoaded_GetFunctionPointerWithNonExistentFunctionName_ReturnsNull)
{
  nidevice_grpc::SharedLibrary library(test_library_name);

  auto createSession = library.get_function_pointer("niTestApiNonExistentFunctionName");

  EXPECT_EQ(nullptr, createSession);
}

TEST(SharedLibraryTests, LibraryAndFunctionsLoaded_FunctionCallsSucceed)
{
  nidevice_grpc::SharedLibrary library(test_library_name);
  library.load();
  ASSERT_TRUE(library.is_loaded());
  auto createSession = reinterpret_cast<TestApiCreateSessionPtr>(library.get_function_pointer("niTestApiCreateSession"));
  auto closeSession = reinterpret_cast<TestApiCloseSessionPtr>(library.get_function_pointer("niTestApiCloseSession"));
  auto writeData = reinterpret_cast<TestApiWriteSessionDataPtr>(library.get_function_pointer("niTestApiWriteSessionData"));
  auto readData = reinterpret_cast<TestApiReadSessionDataPtr>(library.get_function_pointer("niTestApiReadSessionData"));

  const int attribute = 5;
  const char* value = "my data";
  TestSession session = nullptr;
  size_t buffer_length = 0;
  char* buffer = nullptr;
  EXPECT_EQ(0, createSession(&session));
  EXPECT_NE(nullptr, session);
  EXPECT_EQ(0, writeData(session, attribute, "my data"));
  EXPECT_EQ(0, readData(session, attribute, &buffer_length, nullptr));
  EXPECT_EQ(strlen(value) + 1, buffer_length);
  buffer = new char[buffer_length];
  EXPECT_EQ(0, readData(session, attribute, &buffer_length, buffer));
  EXPECT_STREQ(value, buffer);
  delete[] buffer;
}

TEST(SharedLibraryTests, LoadedLibrary_SetLibraryName_DoesNotUpdateLibraryName)
{
  nidevice_grpc::SharedLibrary library(test_library_name);
  library.load();
  std::string initial_library_name = library.get_library_name();
  ASSERT_STREQ(test_library_name, initial_library_name.c_str());

  ASSERT_TRUE(library.is_loaded());
  const char* new_library_name = "hello";
  library.set_library_name(new_library_name);

  std::string name_after_attempted_rename = library.get_library_name();
  EXPECT_STREQ(initial_library_name.c_str(), name_after_attempted_rename.c_str());
}

TEST(SharedLibraryTests, UnloadedLibrary_SetLibraryName_UpdatesLibraryName)
{
  nidevice_grpc::SharedLibrary library(test_library_name);

  ASSERT_FALSE(library.is_loaded());
  const char* new_library_name = "hello";
  library.set_library_name(new_library_name);

  std::string name_after_attempted_rename = library.get_library_name();
  EXPECT_STREQ(new_library_name, name_after_attempted_rename.c_str());
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
