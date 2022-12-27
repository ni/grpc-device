#include <grpcpp/test/server_context_test_spouse.h>
#include <gtest/gtest.h>
#include <server/calibration_operations_restricted_service.h>
#include <server/converters.h>
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

static NISysCfgStatus SetDoubleToOne(void* value)
{
  *static_cast<double*>(value) = 1.0;
  return NISysCfg_OK;
}
static NISysCfgStatus SetUintToOne(void* value)
{
  *static_cast<unsigned int*>(value) = 1;
  return NISysCfg_OK;
}
static NISysCfgStatus SetBoolToTrue(void* value)
{
  *static_cast<bool*>(value) = true;
  return NISysCfg_OK;
}
// static NISysCfgStatus SetStringToEmpty(void* value)
//{
//  *static_cast<char*>(value) = 'h';
// return NISysCfg_OK;
//}

// static NISysCfgStatus SetTimestampToStatic0(void* value)
//{
//   static_cast<google::protobuf::Timestamp*>(value) = {{55564}};
//  return NISysCfg_OK;
//}
static NISysCfgStatus SetTimestampToStatic1(void* value)
{
  *reinterpret_cast<NISysCfgTimestampUTC*>(value) = {{55564}};
  return NISysCfg_OK;
}
// static NISysCfgStatus SetTimestampToStatic2(void* value)
//{
//  static_cast<google::protobuf::Timestamp*>(value) = {8864};
//  return NISysCfg_OK;
//}
TEST(CalibrationOperationsTests, DeviceIsPresent_QueryCalibrationInformation_DeviceStatus)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  EXPECT_CALL(mock_library, SaveResourceChanges)
      .Times(0);
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertySupportsInternalCalibration, _))
      .WillOnce(WithArg<2>(SetBoolToTrue));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertySupportsExternalCalibration, _))
      .WillOnce(WithArg<2>(SetBoolToTrue));
  // EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgIndexedPropertyInternalCalibrationName, _))
  //    .WillOnce(WithArg<2>(SetStringToEmpty));
  // EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertyNumberOfInternalCalibrationDetails, _))
  //   .WillOnce(WithArg<2>(SetUintToOne));
  // EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTemp, _))
  //   .WillOnce(WithArg<2>(SetDoubleToOne));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertyExternalCalibrationLastTemp, _))
      .WillOnce(WithArg<2>(SetDoubleToOne));
  // EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTime, _))
  //    .WillOnce(WithArg<2>(SetTimestampToStatic0));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertyExternalCalibrationLastTime, _))
      .WillOnce(WithArg<2>(SetTimestampToStatic1));
  // EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertyRecommendedNextCalibrationTime, _))
  //    .WillOnce(WithArg<2>(SetTimestampToStatic2));

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);
  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(response.calibration_internal_support());
  EXPECT_TRUE(response.calibration_external_support());
  // EXPECT_EQ('NI_Cal0', response->calibration_internal_name());
  // EXPECT_EQ(1, response.calibration_internal_details_count());
  // EXPECT_NEAR(1.0, response->calibration_internal_last_temperature_c(), 1e-9);
  EXPECT_NEAR(1.0, response.calibration_external_last_temperature_c(), 1e-9);
  // EXPECT_EQ({{8864}}, response->calibration_internal_last_reading());
  CVIAbsoluteTime expected_cvi_absolute_time = {{55564}};
  google::protobuf::Timestamp expected_calibration_external_last_reading;
  nidevice_grpc::converters::convert_to_grpc(expected_cvi_absolute_time, &expected_calibration_external_last_reading);
  // CVIAbsoluteTime actual_calibration_external_last_reading_converted = nidevice_grpc::converters::convert_from_grpc<CVIAbsoluteTime>(actual_calibration_external_last_reading);
  EXPECT_EQ(expected_calibration_external_last_reading, response.calibration_external_last_reading());
  // EXPECT_EQ({{5564}}, response.calibration_external_next_reading());
}

}  // namespace unit

}  // namespace tests

}  // namespace ni
