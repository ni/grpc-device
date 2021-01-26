#include <gtest/gtest.h>
#include "core_server/hardware/grpc/internal/shared_library.h"

namespace ni
{
namespace tests
{
namespace unit
{
namespace hardware
{
namespace grpc
{
namespace internal
{

    using TestSession = void*;
    using TestApiCreateSessionPtr = int (*)(TestSession* session);
    using TestApiCloseSessionPtr = int (*)(TestSession session);
    using TestApiWriteSessionDataPtr = int (*)(TestSession session, int attribute_id, const char* value);
    using TestApiReadSessionDataPtr = int (*)(TestSession session, int attribute_id, size_t* value_length, char* value_buffer);
    using TestApiRemoveSessionDataPtr = int (*)(TestSession session, int attribute_id);

    TEST(SharedLibraryTests, ValidNameForLibrary_Load_IsLoadedReturnsTrue)
    {
        ni::hardware::grpc::internal::SharedLibrary library("TestApi.dll");

        library.load();

        EXPECT_TRUE(library.is_loaded()) << "The library should have loaded.";
    }

    TEST(SharedLibraryTests, ValidNameForLibrary_Load_GetHandleReturnsValue)
    {
        ni::hardware::grpc::internal::SharedLibrary library("TestApi.dll");

        library.load();

        EXPECT_NE(nullptr, library.get_handle()) << "The library should have a handle.";
    }

    TEST(SharedLibraryTests, LibraryLoaded_Unload_UnloadsLibrary)
    {
        ni::hardware::grpc::internal::SharedLibrary library("TestApi.dll");
        library.load();

        library.unload();

        EXPECT_FALSE(library.is_loaded()) << "The library should be unloaded.";
        EXPECT_EQ(nullptr, library.get_handle()) << "The library should not have a handle.";
    }

    TEST(SharedLibraryTests, InvalidNameForLibrary_Load_IsLoadedReturnsFalse)
    {
        ni::hardware::grpc::internal::SharedLibrary library("WrongTestApi.dll");

        library.load();

        EXPECT_FALSE(library.is_loaded()) << "The library should not have loaded.";
    }

    TEST(SharedLibraryTests, InvalidNameForLibrary_Load_GetHandleReturnsNull)
    {
        ni::hardware::grpc::internal::SharedLibrary library("WrongTestApi.dll");

        library.load();

        EXPECT_EQ(nullptr, library.get_handle()) << "The library should not have a handle.";
    }

    TEST(SharedLibraryTests, LibraryNotLoaded_GetFunctionPointerWithExistingFunctionName_ReturnsNull)
    {
        ni::hardware::grpc::internal::SharedLibrary library("TestApi.dll");

        auto createSession = library.get_function_pointer("niTestApiCreateSession");

        EXPECT_EQ(nullptr, createSession) << "The function pointer should have been null when the library was not loaded.";
    }

    TEST(SharedLibraryTests, LibraryLoaded_GetFunctionPointersWithExistingFunctionName_ReturnsValidFunctionPointers)
    {
        ni::hardware::grpc::internal::SharedLibrary library("TestApi.dll");
        library.load();

        auto createSession = reinterpret_cast<TestApiCreateSessionPtr>(library.get_function_pointer("niTestApiCreateSession"));
        auto closeSession = reinterpret_cast<TestApiCloseSessionPtr>(library.get_function_pointer("niTestApiCloseSession"));
        auto writeData = reinterpret_cast<TestApiWriteSessionDataPtr>(library.get_function_pointer("niTestApiWriteSessionData"));
        auto readData = reinterpret_cast<TestApiReadSessionDataPtr>(library.get_function_pointer("niTestApiReadSessionData"));

        EXPECT_NE(nullptr, createSession) << "The function pointer should have been valid.";
        EXPECT_NE(nullptr, closeSession) << "The function pointer should have been valid.";
        EXPECT_NE(nullptr, writeData) << "The function pointer should have been valid.";
        EXPECT_NE(nullptr, readData) << "The function pointer should have been valid.";
    }

    TEST(SharedLibraryTests, LibraryLoaded_GetFunctionPointerWithNonExistentFunctionName_ReturnsNull)
    {
        ni::hardware::grpc::internal::SharedLibrary library("TestApi.dll");

        auto createSession = library.get_function_pointer("niTestApiNonExistentFunctionName");

        EXPECT_EQ(nullptr, createSession) << "The function pointer should have been null when the library was not loaded.";
    }

    TEST(SharedLibraryTests, LibraryLoaded_CallLoadedFunctions_FunctionCallsSucceed)
    {
        ni::hardware::grpc::internal::SharedLibrary library("TestApi.dll");
        library.load();
        auto createSession = reinterpret_cast<TestApiCreateSessionPtr>(library.get_function_pointer("niTestApiCreateSession"));
        auto closeSession = reinterpret_cast<TestApiCloseSessionPtr>(library.get_function_pointer("niTestApiCloseSession"));
        auto writeData = reinterpret_cast<TestApiWriteSessionDataPtr>(library.get_function_pointer("niTestApiWriteSessionData"));
        auto readData = reinterpret_cast<TestApiReadSessionDataPtr>(library.get_function_pointer("niTestApiReadSessionData"));

        const int attribute = 5;
        const char* value = "my data";
        TestSession session = nullptr;
        size_t buffer_length = 0;
        char* buffer = nullptr;
        EXPECT_EQ(0, createSession(&session)) << "The create call should succeed";
        EXPECT_NE(nullptr, session) << "The session should be non-null";
        EXPECT_EQ(0, writeData(session, attribute, "my data")) << "The write call should succeed";
        EXPECT_EQ(0, readData(session, attribute, &buffer_length, nullptr)) << "The first read call should succeed";
        EXPECT_EQ(strlen(value) + 1, buffer_length) << "The first read call should set the value length";
        buffer = new char[buffer_length];
        EXPECT_EQ(0, readData(session, attribute, &buffer_length, buffer)) << "The second read call should succeed";
        EXPECT_STREQ(value, buffer) << "The value read should equal the value written.";
        delete[] buffer;
    }

} // namespace impl
} // namespace grpc
} // namespace hardware
} // namespace unit
} // namespace tests
} // namespace ni
