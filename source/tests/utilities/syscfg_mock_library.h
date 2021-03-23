#ifndef NI_TESTS_UTILITIES_SYSCFGMOCKLIBRARY_H
#define NI_TESTS_UTILITIES_SYSCFGMOCKLIBRARY_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <nisyscfg.h>

namespace ni {
namespace tests {
namespace utilities {

using ::testing::Return;

class SysCfgMockLibrary : public nidevice_grpc::SysCfgLibraryInterface {
 public:
  SysCfgMockLibrary()
  {
    ON_CALL(*this, NextResource)
        .WillByDefault(Return(NISysCfg_EndOfEnum));
  }
  MOCK_METHOD(NISysCfgStatus, InitializeSession, (const char* target_name, const char* username, const char* password, NISysCfgLocale language, NISysCfgBool force_property_refresh, unsigned int connect_timeout_msec, NISysCfgEnumExpertHandle* expert_enum_handle, NISysCfgSessionHandle* session_handle), (override));
  MOCK_METHOD(NISysCfgStatus, CloseHandle, (void* syscfg_handle), (override));
  MOCK_METHOD(NISysCfgStatus, CreateFilter, (NISysCfgSessionHandle session_handle, NISysCfgFilterHandle* filter_handle), (override));
  NISysCfgStatus SetFilterProperty(
      NISysCfgFilterHandle filter_handle,
      NISysCfgFilterProperty property_ID,
      ...)
  {
    return NISysCfg_OK;
  }
  MOCK_METHOD(NISysCfgStatus, FindHardware, (NISysCfgSessionHandle session_handle, NISysCfgFilterMode filter_mode, NISysCfgFilterHandle filter_handle, const char* expert_names, NISysCfgEnumResourceHandle* resource_enum_handle), (override));
  MOCK_METHOD(NISysCfgStatus, NextResource, (NISysCfgSessionHandle session_handle, NISysCfgEnumResourceHandle resource_enum_handle, NISysCfgResourceHandle* resource_handle), (override));
  MOCK_METHOD(NISysCfgStatus, GetResourceIndexedProperty, (NISysCfgResourceHandle resource_handle, NISysCfgIndexedProperty property_ID, unsigned int index, void* value), (override));
  MOCK_METHOD(NISysCfgStatus, GetResourceProperty, (NISysCfgResourceHandle resource_handle, NISysCfgResourceProperty property_ID, void* value), (override));
};

}  // namespace utilities
}  // namespace tests
}  // namespace ni

#endif  // NI_TESTS_UTILITIES_SYSCFGMOCKLIBRARY_H
