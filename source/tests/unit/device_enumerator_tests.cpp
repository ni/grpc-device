#include <gtest/gtest.h>
#include <server/device_enumerator.h>
#include <server/syscfg_library.h>
#include <tests/utilities/syscfg_mock_library.h>

namespace ni {
namespace tests {
namespace unit {

using ::testing::_;
using ::testing::Invoke;
using ::testing::NiceMock;
using ::testing::Return;
using ::testing::Throw;
using ::testing::WithArg;

static const char* kScopeName = "MyScope";
static const char* kModel = "NI PXIe-5122";
static const char* kVendor = "NI";
static const char* kSerialNumber = "37ED39FC0D17";

TEST(DeviceEnumeratorTests, SysCfgApiNotInstalled_EnumerateDevices_ReturnsNotFoundGrpcStatusCode)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  grpc::nidevice::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<grpc::nidevice::DeviceProperties> devices;
  EXPECT_CALL(mock_library, InitializeSession)
      .WillOnce(Throw(grpc::nidevice::LibraryLoadException(grpc::nidevice::kSysCfgApiNotInstalledMessage)));
  EXPECT_CALL(mock_library, CloseHandle)
      .Times(0);

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
  EXPECT_EQ(grpc::nidevice::kSysCfgApiNotInstalledMessage, status.error_message());
}

TEST(DeviceEnumeratorTests, SysCfgApiNotInstalled_EnumerateDevices_ListOfDevicesIsEmpty)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  grpc::nidevice::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<grpc::nidevice::DeviceProperties> devices;
  EXPECT_CALL(mock_library, InitializeSession)
      .WillOnce(Throw(grpc::nidevice::LibraryLoadException(grpc::nidevice::kSysCfgApiNotInstalledMessage)));

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_EQ(0, devices.size());
}

TEST(DeviceEnumeratorTests, InitializeSessionReturnsError_EnumerateDevices_ReturnsInternalGrpcStatusCode)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  grpc::nidevice::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<grpc::nidevice::DeviceProperties> devices;
  EXPECT_CALL(mock_library, InitializeSession)
      .WillOnce(Return(NISysCfg_InvalidLoginCredentials));
  EXPECT_CALL(mock_library, CloseHandle)
      .Times(0);

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_EQ(::grpc::StatusCode::INTERNAL, status.error_code());
  EXPECT_EQ(grpc::nidevice::kDeviceEnumerationFailedMessage, status.error_message());
}

TEST(DeviceEnumeratorTests, InitializeSessionReturnsError_EnumerateDevices_ListOfDevicesIsEmpty)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  grpc::nidevice::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<grpc::nidevice::DeviceProperties> devices;
  EXPECT_CALL(mock_library, InitializeSession)
      .WillOnce(Return(NISysCfg_InvalidLoginCredentials));

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_EQ(0, devices.size());
}

NISysCfgStatus SetSessionHandleToOne(NISysCfgSessionHandle* session_handle)
{
  *session_handle = (NISysCfgSessionHandle)1;
  return NISysCfg_OK;
}

TEST(DeviceEnumeratorTests, InitializeSessionSetsSessionHandle_EnumerateDevices_SessionHandleIsPassedToCloseHandle)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  grpc::nidevice::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<grpc::nidevice::DeviceProperties> devices;
  EXPECT_CALL(mock_library, InitializeSession)
      .WillOnce(WithArg<7>(Invoke(SetSessionHandleToOne)));
  EXPECT_CALL(mock_library, CloseHandle(_))
      .WillRepeatedly(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, CloseHandle((void*)1))
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_EQ(::grpc::StatusCode::OK, status.error_code());
}

TEST(DeviceEnumerationTests, SysCfgApiInstalledAndNoDevicesPresent_EnumerateDevices_ListOfDevicesIsEmpty)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  grpc::nidevice::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<grpc::nidevice::DeviceProperties> devices;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_EndOfEnum));

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_EQ(::grpc::StatusCode::OK, status.error_code());
  EXPECT_EQ(0, devices.size());
}

NISysCfgStatus SetExpertNameToNetwork(void* value)
{
  char* expert_name = (char*)value;
  strcpy(expert_name, grpc::nidevice::kNetworkExpertName);
  return NISysCfg_OK;
}

TEST(DeviceEnumerationTests, LocalHostContainsNetworkDevice_EnumerateDevices_ListOfDevicesReturnedDoesNotContainNetworkDevices)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  grpc::nidevice::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<grpc::nidevice::DeviceProperties> devices;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK))
      .WillOnce(Return(NISysCfg_EndOfEnum));
  EXPECT_CALL(mock_library, GetResourceIndexedProperty)
      .WillOnce(WithArg<3>(Invoke(SetExpertNameToNetwork)));
  EXPECT_CALL(mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyExpertUserAlias, _, _))
      .Times(0);

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_EQ(::grpc::StatusCode::OK, status.error_code());
  EXPECT_EQ(0, devices.size());
}

TEST(DeviceEnumerationTests, GetResourcePropertyApisReturnError_EnumerateDevices_DevicePropertiesAreSetToEmptyString)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  grpc::nidevice::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<grpc::nidevice::DeviceProperties> devices;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK))
      .WillOnce(Return(NISysCfg_EndOfEnum));
  EXPECT_CALL(mock_library, GetResourceIndexedProperty)
      .WillRepeatedly(Return(NISysCfg_PropDoesNotExist));
  EXPECT_CALL(mock_library, GetResourceProperty)
      .WillRepeatedly(Return(NISysCfg_PropDoesNotExist));

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_EQ(::grpc::StatusCode::OK, status.error_code());
  EXPECT_EQ(1, devices.size());
  EXPECT_EQ("", devices.Get(0).name());
  EXPECT_EQ("", devices.Get(0).model());
  EXPECT_EQ("", devices.Get(0).vendor());
  EXPECT_EQ("", devices.Get(0).serial_number());
}

NISysCfgStatus SetNameToMyScope(void* value)
{
  char* name = (char*)value;
  strcpy(name, kScopeName);
  return NISysCfg_OK;
}

TEST(DeviceEnumerationTests, GetResourceIndexedPropertySetsName_EnumerateDevices_ResponseContainsThatName)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  grpc::nidevice::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<grpc::nidevice::DeviceProperties> devices;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK))
      .WillOnce(Return(NISysCfg_EndOfEnum));
  EXPECT_CALL(mock_library, GetResourceIndexedProperty)
      .WillRepeatedly(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyExpertUserAlias, _, _))
      .WillOnce(WithArg<3>(Invoke(SetNameToMyScope)));

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(1, devices.size());
  EXPECT_EQ(kScopeName, devices.Get(0).name());
}

NISysCfgStatus SetModelName(void* value)
{
  char* model = (char*)value;
  strcpy(model, kModel);
  return NISysCfg_OK;
}

TEST(DeviceEnumerationTests, GetResourceIndexedPropertySetsModelName_EnumerateDevices_ResponseContainsThatModelName)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  grpc::nidevice::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<grpc::nidevice::DeviceProperties> devices;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK))
      .WillOnce(Return(NISysCfg_EndOfEnum));
  EXPECT_CALL(mock_library, GetResourceProperty)
      .WillRepeatedly(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertyProductName, _))
      .WillOnce(WithArg<2>(Invoke(SetModelName)));

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(1, devices.size());
  EXPECT_EQ(kModel, devices.Get(0).model());
}

NISysCfgStatus SetVendorName(void* value)
{
  char* vendor = (char*)value;
  strcpy(vendor, kVendor);
  return NISysCfg_OK;
}

TEST(DeviceEnumerationTests, GetResourceIndexedPropertySetsModelName_EnumerateDevices_ResponseContainsThatModelName)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  grpc::nidevice::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<grpc::nidevice::DeviceProperties> devices;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK))
      .WillOnce(Return(NISysCfg_EndOfEnum));
  EXPECT_CALL(mock_library, GetResourceProperty)
      .WillRepeatedly(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertyVendorName, _))
      .WillOnce(WithArg<2>(Invoke(SetVendorName)));

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(1, devices.size());
  EXPECT_EQ(kVendor, devices.Get(0).vendor());
}

NISysCfgStatus SetSerialNumber(void* value)
{
  char* serial_number = (char*)value;
  strcpy(serial_number, kSerialNumber);
  return NISysCfg_OK;
}

TEST(DeviceEnumerationTests, GetResourceIndexedPropertySetsSerialNumber_EnumerateDevices_ResponseContainsThatSerialNumber)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  grpc::nidevice::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<grpc::nidevice::DeviceProperties> devices;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK))
      .WillOnce(Return(NISysCfg_EndOfEnum));
  EXPECT_CALL(mock_library, GetResourceProperty)
      .WillRepeatedly(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertySerialNumber, _))
      .WillOnce(WithArg<2>(Invoke(SetSerialNumber)));

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(1, devices.size());
  EXPECT_EQ(kSerialNumber, devices.Get(0).serial_number());
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
