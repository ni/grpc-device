#include <gtest/gtest.h>
#include <nidaqmx/nidaqmx_mock_library.h>
#include <nidaqmx/nidaqmx_service.h>

using ::testing::NiceMock;

namespace ni {
namespace tests {
namespace unit {

TEST(NIDAQMX_TESTS, WriteDigitalU16_U32DataGetsConverted)
{
  NiceMock<ni::tests::unit::NiDAQmxMockLibrary> mock_library;
  nidevice_grpc::SessionRepository session_repository;
  nidaqmx_grpc::NiDAQmxService nidaqmx_service(&mock_library, &session_repository);

  EXPECT_CALL(mock_library, WriteDigitalU16);
  //nidevice_grpc::DeviceEnumerator device_enumerator(&mock_library);
  //nidevice_grpc::SysCfgLibrary syscfg_library;
  //std::string shared_library_name = syscfg_library.get_library_name();

  //EXPECT_STREQ(nidevice_grpc::kSysCfgApiLibraryName, shared_library_name.c_str());
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
