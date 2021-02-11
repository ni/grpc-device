#include "test_api.h"

#include <string.h>

#include <map>
#include <string>

using DataMap = std::map<int, std::string>;

static DataMap& GetDataMapFromSession(TestSession session)
{
  DataMap* map = reinterpret_cast<DataMap*>(session);
  return *map;
}

int niTestApiCreateSession(TestSession* session)
{
  if (!session) {
    return 1;
  }
  *session = nullptr;
  try {
    DataMap* map = new DataMap();
    *session = reinterpret_cast<TestSession>(map);
    return 0;
  }
  catch (const std::bad_alloc&) {
    return 1;
  }
}

int niTestApiCloseSession(TestSession session)
{
  if (!session) {
    return 1;
  }
  DataMap& map = GetDataMapFromSession(session);
  delete &map;
  return 0;
}

int niTestApiWriteSessionData(TestSession session, int attribute_id, const char* value)
{
  if (!session || !value) {
    return 1;
  }
  DataMap& map = GetDataMapFromSession(session);
  map[attribute_id] = value;
  return 0;
}

int niTestApiReadSessionData(TestSession session, int attribute_id, size_t* value_length, char* value_buffer)
{
  if (!session || !value_length) {
    return 1;
  }
  DataMap& map = GetDataMapFromSession(session);
  DataMap::const_iterator it = map.find(attribute_id);
  if (it == map.end()) {
    return 1;
  }
  const std::string& value = it->second;
  if (*value_length) {
    if (!value_buffer || *value_length < value.length() + 1) {
      return 1;
    }
    strncpy(value_buffer, value.c_str(), *value_length);
  }
  else {
    if (value_buffer) {
      return 1;
    }
    *value_length = value.length() + 1;
  }
  return 0;
}

int niTestApiRemoveSessionData(TestSession session, int attribute_id)
{
  if (!session) {
    return 1;
  }
  DataMap& map = GetDataMapFromSession(session);
  size_t elements_removed = map.erase(attribute_id);
  return elements_removed > 0 ? 0 : 1;
}
