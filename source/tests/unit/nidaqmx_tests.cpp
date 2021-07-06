#include <gtest/gtest.h>
#include <nidaqmx/nidaqmx_mock_library.h>
#include <nidaqmx/nidaqmx_service.h>

using ::testing::NiceMock;

namespace ni {
namespace tests {
namespace unit {

namespace daqmx = nidaqmx_grpc;

using ::std::get;
MATCHER(CustomU16Data, "")
{
  uInt16 const* write_data_array = std::get<5>(arg);
  return write_data_array[0] == 0 && write_data_array[1] == UINT16_MAX && write_data_array[2] == 16;
}

TEST(NIDAQMX_TESTS, WriteDigitalU16_U32DataGetsConverted)
{
  using ::testing::_;
  NiceMock<ni::tests::unit::NiDAQmxMockLibrary> mock_library;
  EXPECT_CALL(mock_library, WriteDigitalU16(_, _, _, _, _, _, _, _))
      .With(CustomU16Data())
      .Times(1);
  nidevice_grpc::SessionRepository session_repository;
  nidaqmx_grpc::NiDAQmxService nidaqmx_service(&mock_library, &session_repository);
  ::grpc::ServerContext context;
  daqmx::WriteDigitalU16Request request;
  request.add_write_array(0);
  request.add_write_array(UINT16_MAX);
  request.add_write_array(16);
  daqmx::WriteDigitalU16Response response;

  nidaqmx_service.WriteDigitalU16(&context, &request, &response);

  ASSERT_EQ(0, response.status());
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
