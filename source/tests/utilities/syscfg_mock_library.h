#ifndef NI_TESTS_UTILITIES_SYSCFGMOCKLIBRARY_H
#define NI_TESTS_UTILITIES_SYSCFGMOCKLIBRARY_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace ni {
namespace tests {
namespace utilities {

class SysCfgMockLibrary : public ni::hardware::grpc::internal::SysCfgLibraryInterface {
 public:
  MOCK_METHOD(NISysCfgStatus, InitializeSession, (
    const char*                          target_name,
    const char*                          username,
    const char*                          password,
    NISysCfgLocale                       language,
    NISysCfgBool                         force_property_refresh,
    unsigned int                         connect_timeout_msec,
    NISysCfgEnumExpertHandle*            expert_enum_handle,
    NISysCfgSessionHandle*               session_handle
    ), (override));
  MOCK_METHOD(NISysCfgStatus, CloseHandle, (
    void*                                syscfg_handle
    ), (override));
};

}  // namespace utilities
}  // namespace tests
}  // namespace ni

#endif  // NI_TESTS_UTILITIES_SYSCFGMOCKLIBRARY_H
