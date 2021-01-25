
typedef void* TestSession;

extern "C" int niTestApiCreateSession(TestSession* session);

extern "C" int niTestApiCloseSession(TestSession* session);

extern "C" int niTestApiWriteSessionData(TestSession session, int attribute_id, const char* value);

extern "C" int niTestApiReadSessionData(TestSession session, int attribute_id, size_t* value_length, const char** value_buffer);

extern "C" int niTestApiRemoveSessionData(TestSession session, int attribute_id);