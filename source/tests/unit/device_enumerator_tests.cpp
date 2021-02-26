#include <gtest/gtest.h>
#include <server/device_enumerator.h>
#include <tests/utilities/syscfg_mock_library.h>

namespace ni {
namespace tests {
namespace unit {

using ::testing::_;
using ::testing::Return;
using ::testing::Throw;

TEST(DeviceEnumeratorTests, ExpectFindHardwareToThrowException_EnumerateDevices_ReturnsNotFoundGrpcStatus)
{
  ni::tests::utilities::SysCfgMockLibrary mock_library;
  ni::hardware::grpc::internal::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<ni::hardware::grpc::DeviceProperties> devices;
  std::string message = "The NI System Configuration library was not found";
  EXPECT_CALL(mock_library, FindHardware)
      .WillOnce(Throw(ni::hardware::grpc::internal::LibraryLoadException(message)));

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
  EXPECT_EQ(message, status.error_message());
}

TEST(DeviceEnumeratorTests, ExpectNextResourceToSetResourceHandle_EnumerateDevices_ResouceHandleValueIsPassedToGetResourceProperty)
{
  ni::tests::utilities::SysCfgMockLibrary mock_library;
  ni::hardware::grpc::internal::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<ni::hardware::grpc::DeviceProperties> devices;
  EXPECT_CALL(mock_library, FindHardware)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce([](NISysCfgResourceHandle* resourcesHandle) {
        *resourcesHandle = (NISysCfgResourceHandle)1;
        return NISysCfg_OK;
      })
      .WillOnce([](NISysCfgResourceHandle* resourcesHandle) {
        *resourcesHandle = (NISysCfgResourceHandle)2;
        return NISysCfg_OK;
      })
      .WillOnce(Return(NISysCfg_EndOfEnum));
  EXPECT_CALL(mock_library, GetResourceProperty((NISysCfgEnumResourceHandle)1, _, _))
      .WillRepeatedly(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty((NISysCfgEnumResourceHandle)2, _, _))
      .WillRepeatedly(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, CloseHandle)
      .WillRepeatedly(Return(NISysCfg_OK));

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_EQ(::grpc::StatusCode::OK, status.error_code());
}

TEST(DeviceEnumeratorTests, ExpectGetResourcePropertyToSetModelName_EnumerateDevices_ReturnsExpectedModelNameOfDevices)
{
  ni::tests::utilities::SysCfgMockLibrary mock_library;
  ni::hardware::grpc::internal::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<ni::hardware::grpc::DeviceProperties> devices;
  EXPECT_CALL(mock_library, FindHardware)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK))
      .WillOnce(Return(NISysCfg_OK))
      .WillOnce(Return(NISysCfg_EndOfEnum));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertyProductName, _))
      .WillOnce([](NISysCfgEnumResourceHandle resourceEnumHandle, NISysCfgResourceProperty propertyID, void* value) {
        strcpy(static_cast<char*>(value), "NI PXIe-5122");
        return NISysCfg_OK;
      })
      .WillOnce([](NISysCfgEnumResourceHandle resourceEnumHandle, NISysCfgResourceProperty propertyID, void* value) {
        strcpy(static_cast<char*>(value), "NI PXIe-5441");
        return NISysCfg_OK;
      });
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertyVendorName, _))
      .WillRepeatedly(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, CloseHandle)
      .WillRepeatedly(Return(NISysCfg_OK));

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  std::vector<std::string> expected_model_names{"NI PXIe-5122", "NI PXIe-5441"};
  ASSERT_EQ(expected_model_names.size(), devices.size());
  for (int i = 0; i < expected_model_names.size(); i++) {
    EXPECT_EQ(expected_model_names[i], devices.Get(i).model());
  }
}

TEST(DeviceEnumeratorTests, ExpectFindHardwareToReturnError_EnumerateDevices_DoesNotCallNextResource)
{
  ni::tests::utilities::SysCfgMockLibrary mock_library;
  ni::hardware::grpc::internal::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<ni::hardware::grpc::DeviceProperties> devices;
  EXPECT_CALL(mock_library, FindHardware)
      .WillOnce(testing::Return(NISysCfg_InvalidArg));
  EXPECT_CALL(mock_library, NextResource)
      .Times(0);

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_EQ(::grpc::StatusCode::INTERNAL, status.error_code());
  EXPECT_EQ("The NI System Configuration API was unable to enumerate the devices.", status.error_message());
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
