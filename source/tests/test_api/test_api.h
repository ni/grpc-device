
#if defined(MAKEDLL)
   #define TEST_API_FUNCTION extern "C" __declspec(dllexport)
#else
   #define TEST_API_FUNCTION extern "C" __declspec(dllimport)
#endif

typedef void* TestSession;

TEST_API_FUNCTION int niTestApiCreateSession(TestSession* session);

TEST_API_FUNCTION int niTestApiCloseSession(TestSession session);

TEST_API_FUNCTION int niTestApiWriteSessionData(TestSession session, int attribute_id, const char* value);

TEST_API_FUNCTION int niTestApiReadSessionData(TestSession session, int attribute_id, size_t* value_length, char* value_buffer);

TEST_API_FUNCTION int niTestApiRemoveSessionData(TestSession session, int attribute_id);