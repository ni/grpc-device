#include <gtest/gtest.h>
#include <server/device_enumerator.h>
#include <tests/utilities/syscfg_mock_library.h>

namespace ni {
namespace tests {
namespace unit {

using ::testing::_;
using ::testing::Return;
using ::testing::Throw;

TEST(DeviceEnumeratorTests, SysCfgApiNotInstalled_EnumerateDevices_ReturnsNotFoundGrpcStatusCode)
{
  ni::tests::utilities::SysCfgMockLibrary mock_library;
  ni::hardware::grpc::internal::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<ni::hardware::grpc::DeviceProperties> devices;
  std::string message = "The NI System Configuration API is not installed on the server.";
  EXPECT_CALL(mock_library, InitializeSession)
      .WillOnce(Throw(ni::hardware::grpc::internal::LibraryLoadException(message)));
  EXPECT_CALL(mock_library, CloseHandle)
      .Times(0);

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
  EXPECT_EQ(message, status.error_message());
}

TEST(DeviceEnumeratorTests, InitializeSessionReturnsError_EnumerateDevices_ReturnsInternalGrpcStatusCode)
{
  ni::tests::utilities::SysCfgMockLibrary mock_library;
  ni::hardware::grpc::internal::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<ni::hardware::grpc::DeviceProperties> devices;
  EXPECT_CALL(mock_library, InitializeSession)
      .WillOnce(Return(NISysCfg_InvalidLoginCredentials));
  EXPECT_CALL(mock_library, CloseHandle)
      .Times(1)
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_EQ(::grpc::StatusCode::INTERNAL, status.error_code());
}

TEST(DeviceEnumeratorTests, ExpectInitializeSessionToSetSessionHandle_EnumerateDevices_SessionHandleIsPassedToCloseHandle)
{
  ni::tests::utilities::SysCfgMockLibrary mock_library;
  ni::hardware::grpc::internal::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<ni::hardware::grpc::DeviceProperties> devices;
  EXPECT_CALL(mock_library, InitializeSession)
      .WillOnce([](
          const char* targetName,
          const char* username,
          const char* password,
          NISysCfgLocale language,
          NISysCfgBool forcePropertyRefresh,
          unsigned int connectTimeoutMsec,
          NISysCfgEnumExpertHandle* expertEnumHandle,
          NISysCfgSessionHandle* sessionHandle
          ) {
              *sessionHandle = (NISysCfgSessionHandle)1;
              return NISysCfg_OK;
          }
      );
  EXPECT_CALL(mock_library, CloseHandle((void*)1))
      .Times(1)
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_EQ(::grpc::StatusCode::OK, status.error_code());
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
