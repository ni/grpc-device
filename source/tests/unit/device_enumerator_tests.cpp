#include <gtest/gtest.h>
#include <server/device_enumerator.h>
#include <server/device_enumerator_fake_library.h>

#include "device_enumerator_mock_library.h"

namespace ni {
namespace tests {
namespace unit {

TEST(DeviceEnumeratorTests, CreateDeviceEnumeratorWithMockLibrary_LibraryDoesNotExist_DoesNotCallSysCfgFunction)
{
  DeviceEnumeratorMockLibrary mock_library;
  ni::hardware::grpc::internal::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<ni::hardware::grpc::DeviceProperties> devices;
  mock_library.DelegateToFake();
  std::string message = "The NI System Configuration library was not found";
  EXPECT_CALL(mock_library, check_library_exists())
      .WillOnce(testing::Return(::grpc::Status(::grpc::NOT_FOUND, message)));
  EXPECT_CALL(mock_library, FindHardware)
      .Times(0);

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
  EXPECT_EQ(message, status.error_message());
}

void assert_vectors_are_equal(std::vector<std::string> expected_vector, std::vector<std::string> actual_vector)
{
  ASSERT_EQ(expected_vector.size(), actual_vector.size());

  for (int i = 0; i < expected_vector.size(); ++i) {
    EXPECT_EQ(expected_vector[i], actual_vector[i]);
  }
}

TEST(DeviceEnumeratorTests, CreateDeviceEnumeratorWithMockLibrary_EnumerateDevices_ReturnsExpectedNameOfDevices)
{
  DeviceEnumeratorMockLibrary mock_library;
  ni::hardware::grpc::internal::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<ni::hardware::grpc::DeviceProperties> devices;
  mock_library.DelegateToFake();

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  std::vector<std::string> expected_device_names{"SimulatedScope1", "SimulatedSwitch1"};
  std::vector<std::string> actual_device_names{};
  for (auto it : devices) {
    actual_device_names.push_back(it.name());
  }
  assert_vectors_are_equal(expected_device_names, actual_device_names);
}

TEST(DeviceEnumeratorTests, CreateDeviceEnumeratorWithMockLibrary_EnumerateDevices_CallsFindHardware)
{
  DeviceEnumeratorMockLibrary mock_library;
  ni::hardware::grpc::internal::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<ni::hardware::grpc::DeviceProperties> devices;
  mock_library.DelegateToFake();
  EXPECT_CALL(mock_library, FindHardware)
      .Times(1);

  ::grpc::Status status = device_enumerator.enumerate_devices(&devices);

  EXPECT_TRUE(status.ok());
}

TEST(DeviceEnumeratorTests, ExpectFindHardwareToReturnError_EnumerateDevices_DoesNotCallNextResource)
{
  DeviceEnumeratorMockLibrary mock_library;
  ni::hardware::grpc::internal::DeviceEnumerator device_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<ni::hardware::grpc::DeviceProperties> devices;
  mock_library.DelegateToFake();
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
