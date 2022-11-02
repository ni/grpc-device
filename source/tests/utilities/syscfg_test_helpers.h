#ifndef SYSCFG_TEST_HELPERS
#define SYSCFG_TEST_HELPERS

#include <nisyscfg.h>

inline static NISysCfgStatus SetSessionHandleToOne(NISysCfgSessionHandle* session_handle)
{
  *session_handle = (NISysCfgSessionHandle)1;
  return NISysCfg_OK;
}

#endif
