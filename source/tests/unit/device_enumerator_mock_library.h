#ifndef NI_TESTS_UNIT_DEVICEENUMERATORMOCKLIBRARY_H
#define NI_TESTS_UNIT_DEVICEENUMERATORMOCKLIBRARY_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <server/device_enumerator_fake_library.h>

namespace ni {
namespace tests {
namespace unit {

class DeviceEnumeratorMockLibrary : public ni::hardware::grpc::internal::DeviceEnumeratorLibraryInterface {
 public:
  MOCK_METHOD(::grpc::Status, check_library_exists, (), (override));
  MOCK_METHOD(NISysCfgStatus, FindHardware, (), (override));
  MOCK_METHOD(NISysCfgStatus, NextResource, (NISysCfgResourceHandle * resourceHandle), (override));
  MOCK_METHOD(NISysCfgStatus, GetResourceProperty, (NISysCfgEnumResourceHandle resourceEnumHandle, void* value), (override));
  MOCK_METHOD(NISysCfgStatus, CloseHandle, (void* sysCfgHandle), (override));

  void DelegateToFake()
  {
    ON_CALL(*this, check_library_exists).WillByDefault([this]() {
      return fake_library_.check_library_exists();
    });
    ON_CALL(*this, FindHardware).WillByDefault([this]() {
      return fake_library_.FindHardware();
    });
    ON_CALL(*this, NextResource).WillByDefault([this](NISysCfgResourceHandle* resourceHandle) {
      return fake_library_.NextResource(resourceHandle);
    });
    ON_CALL(*this, GetResourceProperty).WillByDefault([this](NISysCfgEnumResourceHandle resourceEnumHandle, void* value) {
      return fake_library_.GetResourceProperty(resourceEnumHandle, value);
    });
    ON_CALL(*this, CloseHandle).WillByDefault([this](void* sysCfgHandle) {
      return fake_library_.CloseHandle(sysCfgHandle);
    });
  }

 private:
  ni::hardware::grpc::internal::DeviceEnumeratorFakeLibrary fake_library_;
};

}  // namespace unit
}  // namespace tests
}  // namespace ni

#endif  // NI_TESTS_UNIT_DEVICEENUMERATORMOCKLIBRARY_H
