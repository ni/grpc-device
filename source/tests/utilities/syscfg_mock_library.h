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
  NISysCfgStatus SetResourceProperty(
      NISysCfgResourceHandle resource_handle,
      NISysCfgResourceProperty property_ID,
      ...)
  {
    return NISysCfg_OK;
  }
  MOCK_METHOD(NISysCfgStatus, SaveResourceChanges, (NISysCfgResourceHandle resource_handle, NISysCfgBool* changes_require_restart, char** detailed_result), (override));
  MOCK_METHOD(NISysCfgStatus, FreeDetailedString, (char str[]), (override));
  MOCK_METHOD(NISysCfgStatus, GetInstalledSoftwareComponents, (NISysCfgSessionHandle session_handle, NISysCfgIncludeComponentTypes item_types, NISysCfgBool cached, NISysCfgEnumSoftwareComponentHandle* component_enum_handle), (override));
  MOCK_METHOD(NISysCfgStatus, ResetEnumeratorGetCount, (void* enumHandle, unsigned int* count), (override));
  MOCK_METHOD(NISysCfgStatus, NextComponentInfo, (NISysCfgEnumSoftwareComponentHandle component_enum_handle, char* id, char* version, char* title, NISysCfgComponentType* itemType, char** detailedDescription), (override));
};

// SysCfg GetResourceProperty and GetResourceIndexedProperty require assigning to a void* parameter.
// The standard gmock action SetArgPointee fails due to mismatched types.  The following action
// casts the void* to a pointer of the type of the value passed in prior to assignment.
template <size_t N, typename A, typename = void>
struct CastAndSetArgumentPointeeAction {
  A value;

  template <typename... Args>
  void operator()(const Args&... args) const
  {
    *static_cast<A*>(::std::get<N>(std::tie(args...))) = value;
  }
};

template <size_t N, typename T>
CastAndSetArgumentPointeeAction<N, T> CastAndSetArgPointee(T value)
{
  return {std::move(value)};
}

}  // namespace utilities
}  // namespace tests
}  // namespace ni

#endif  // NI_TESTS_UTILITIES_SYSCFGMOCKLIBRARY_H
