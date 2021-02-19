
#include <cstddef>

#if defined(_MSC_VER)
  #define EXPORT __declspec(dllexport)
  #define IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
  #define EXPORT __attribute__((visibility("default")))
  #define IMPORT
#endif

#if defined(TEST_API_BUILDING)
  #define TEST_API_FUNCTION extern "C" EXPORT
#else
  #define TEST_API_FUNCTION extern "C" IMPORT
#endif

typedef void* TestSession;

TEST_API_FUNCTION int niTestApiCreateSession(TestSession* session);

TEST_API_FUNCTION int niTestApiCloseSession(TestSession session);

TEST_API_FUNCTION int niTestApiWriteSessionData(TestSession session, int attribute_id, const char* value);

TEST_API_FUNCTION int niTestApiReadSessionData(TestSession session, int attribute_id, size_t* value_length, char* value_buffer);

TEST_API_FUNCTION int niTestApiRemoveSessionData(TestSession session, int attribute_id);
