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
    const char*                            targetName,
    const char*                            username,
    const char*                            password,
    NISysCfgLocale                         language,
    NISysCfgBool                           forcePropertyRefresh,
    unsigned int                           connectTimeoutMsec,
    NISysCfgEnumExpertHandle*              expertEnumHandle,
    NISysCfgSessionHandle*                 sessionHandle
    ), (override));
  MOCK_METHOD(NISysCfgStatus, CloseHandle, (void* sysCfgHandle), (override));
};

}  // namespace utilities
}  // namespace tests
}  // namespace ni

#endif  // NI_TESTS_UTILITIES_SYSCFGMOCKLIBRARY_H
