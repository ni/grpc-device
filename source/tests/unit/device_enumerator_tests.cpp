#include <gtest/gtest.h>
#include <server/device_enumerator.h>
#include <server/syscfg_library.h>
#include <tests/utilities/syscfg_mock_library.h>

namespace internal = ni::hardware::grpc::internal;

namespace ni {
namespace tests {
namespace unit {

using ::testing::_;
using ::testing::Invoke;
using ::testing::Return;
using ::testing::Throw;
using ::testing::WithArg;

TEST(DeviceEnumeratorTests, SysCfgApiNotInstalled_EnumerateDevices_ReturnsNotFoundGrpcStatusCode)
{
  ni::tests::utilities::SysCfgMockLibrary mock_library;
  internal::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<ni::hardware::grpc::DeviceProperties> devices;
  EXPECT_CALL(mock_library, InitializeSession)
      .WillOnce(Throw(internal::LibraryLoadException(internal::kSysCfgApiNotInstalledMessage)));
  EXPECT_CALL(mock_library, CloseHandle)
      .Times(0);

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
  EXPECT_EQ(internal::kSysCfgApiNotInstalledMessage, status.error_message());
}

TEST(DeviceEnumeratorTests, SysCfgApiNotInstalled_EnumerateDevices_ListOfDevicesIsEmpty)
{
  ni::tests::utilities::SysCfgMockLibrary mock_library;
  internal::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<ni::hardware::grpc::DeviceProperties> devices;
  EXPECT_CALL(mock_library, InitializeSession)
      .WillOnce(Throw(internal::LibraryLoadException(internal::kSysCfgApiNotInstalledMessage)));

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_EQ(0, devices.size());
}

TEST(DeviceEnumeratorTests, InitializeSessionReturnsError_EnumerateDevices_ReturnsInternalGrpcStatusCode)
{
  ni::tests::utilities::SysCfgMockLibrary mock_library;
  internal::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<ni::hardware::grpc::DeviceProperties> devices;
  EXPECT_CALL(mock_library, InitializeSession)
      .WillOnce(Return(NISysCfg_InvalidLoginCredentials));
  EXPECT_CALL(mock_library, CloseHandle)
      .Times(0);

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_EQ(::grpc::StatusCode::INTERNAL, status.error_code());
  EXPECT_EQ(internal::kDeviceEnumerationFailedMessage, status.error_message());
}

TEST(DeviceEnumeratorTests, InitializeSessionReturnsError_EnumerateDevices_ListOfDevicesIsEmpty)
{
  ni::tests::utilities::SysCfgMockLibrary mock_library;
  internal::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<ni::hardware::grpc::DeviceProperties> devices;
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
  ni::tests::utilities::SysCfgMockLibrary mock_library;
  internal::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<ni::hardware::grpc::DeviceProperties> devices;
  EXPECT_CALL(mock_library, InitializeSession)
      .WillOnce(WithArg<7>(Invoke(SetSessionHandleToOne)));
  EXPECT_CALL(mock_library, CloseHandle((void*)1))
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_EQ(::grpc::StatusCode::OK, status.error_code());
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
