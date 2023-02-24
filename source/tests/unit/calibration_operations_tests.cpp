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

static NISysCfgStatus SetDoubleToThree(void* value)
{
  *static_cast<double*>(value) = 1.0;
  return NISysCfg_OK;
}
static NISysCfgStatus SetUintToOne(void* value)
{
  *static_cast<unsigned int*>(value) = 1;
  return NISysCfg_OK;
}
static NISysCfgStatus SetUintToThree(void* value)
{
  *static_cast<unsigned int*>(value) = 3;
  return NISysCfg_OK;
}
static NISysCfgStatus SetBoolToTrue(void* value)
{
  *static_cast<bool*>(value) = true;
  return NISysCfg_OK;
}
const CVIAbsoluteTime TestTime0 = {{55564}};

const CVIAbsoluteTime TestTime1 = {{9569}};

const CVIAbsoluteTime TestTime2 = {{8864}};

static NISysCfgStatus SetTimestampToStatic0(void* value)
{
  *reinterpret_cast<NISysCfgTimestampUTC*>(value) = *reinterpret_cast<const NISysCfgTimestampUTC*>(&TestTime0);
  return NISysCfg_OK;
}
static NISysCfgStatus SetTimestampToStatic1(void* value)
{
  *reinterpret_cast<NISysCfgTimestampUTC*>(value) = *reinterpret_cast<const NISysCfgTimestampUTC*>(&TestTime1);
  return NISysCfg_OK;
}

static NISysCfgStatus SetTimestampToStatic2(void* value)
{
  *reinterpret_cast<NISysCfgTimestampUTC*>(value) = *reinterpret_cast<const NISysCfgTimestampUTC*>(&TestTime2);
  return NISysCfg_OK;
}

const std::string TestString0 = "DAQ";

const std::string TestString1 = "PXI";

const std::string TestString2 = "MyRIO";

static NISysCfgStatus SetString0(void* value)
{
  strcpy(static_cast<char*>(value), TestString0.c_str());
  return NISysCfg_OK;
}
static NISysCfgStatus SetString1(void* value)
{
  strcpy(static_cast<char*>(value), TestString1.c_str());
  return NISysCfg_OK;
}
static NISysCfgStatus SetString2(void* value)
{
  strcpy(static_cast<char*>(value), TestString2.c_str());
  return NISysCfg_OK;
}

const double TestDouble0 = 7.8;

const double TestDouble1 = 8.342;

const double TestDouble2 = 72.3;

static NISysCfgStatus SetDouble0(void* value)
{
  *static_cast<double*>(value) = TestDouble0;
  return NISysCfg_OK;
}

static NISysCfgStatus SetDouble1(void* value)
{
  *static_cast<double*>(value) = TestDouble1;
  return NISysCfg_OK;
}

static NISysCfgStatus SetDouble2(void* value)
{
  *static_cast<double*>(value) = TestDouble2;
  return NISysCfg_OK;
}

TEST(CalibrationOperationsTests, DeviceIsPresent_QueryCalibrationInternalSupported_ResponseIsWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertySupportsInternalCalibration, _))
      .WillOnce(WithArg<2>(SetBoolToTrue));
  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);
  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(response.calibration_internal_support());
  EXPECT_TRUE(response.calibration_internal_support_avaliable());
}

TEST(CalibrationOperationsTests, DeviceIsPresent_QueryCalibrationInternalUnsupported_ResponseIsWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertySupportsInternalCalibration, _))
      .WillOnce(Return(NISysCfg_PropDoesNotExist));
  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);
  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.calibration_internal_support_avaliable());
}

TEST(CalibrationOperationsTests, DeviceIsPresent_QueryCalibrationExternalSupported_ResponseIsWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertySupportsExternalCalibration, _))
      .WillOnce(WithArg<2>(SetBoolToTrue));
  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);
  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(response.calibration_external_support());
  EXPECT_TRUE(response.calibration_external_support_available());
}

TEST(CalibrationOperationsTests, DeviceIsPresent_QueryCalibrationExternalUnsupported_ResponseIsWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertySupportsExternalCalibration, _))
      .WillOnce(Return(NISysCfg_PropDoesNotExist));
  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);
  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.calibration_external_support_available());
}

TEST(CalibrationOperationsTests, DeviceIsPresent_QueryNumberOfInternalCalibrationDetailsSupported_ResponseIsWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertyNumberOfInternalCalibrationDetails, _))
      .WillOnce(WithArg<2>(SetUintToOne));
  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);
  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(response.calibration_internal_details_count());
  EXPECT_TRUE(response.calibration_internal_details_count_available());
}

TEST(CalibrationOperationsTests, DeviceIsPresent_QueryNumberOfInternalCalibrationDetailsUnsupported_ResponseIsWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertyNumberOfInternalCalibrationDetails, _))
      .WillOnce(Return(NISysCfg_PropDoesNotExist));
  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);
  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.calibration_internal_details_count_available());
}

TEST(CalibrationOperationsTests, DeviceIsPresent_QueryExternalCalibrationLastTimeSupported_ResponseIsWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertyExternalCalibrationLastTime, _))
      .WillOnce(WithArg<2>(SetTimestampToStatic0));

  google::protobuf::Timestamp ExpectedTime3;
  nidevice_grpc::converters::convert_to_grpc(SetTimestampToStatic0, &ExpectedTime3);
  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(ExpectedTime3, response.calibration_external_last_reading());
  EXPECT_TRUE(response.calibration_external_last_reading_available());
}

TEST(CalibrationOperationsTests, DeviceIsPresent_QueryExternalCalibrationLastTimeUnsupported_ResponseIsWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertyExternalCalibrationLastTime, _))
      .WillOnce(Return(NISysCfg_PropDoesNotExist));
  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);
  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.calibration_external_last_reading_available());
}

TEST(CalibrationOperationsTests, DeviceIsPresent_QueryExternalCalibrationLastTempSupported_ResponseIsWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertyExternalCalibrationLastTemp, _))
      .WillOnce(WithArg<2>(SetDoubleToOne));
  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);
  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(response.calibration_external_last_temperature_c());
  EXPECT_TRUE(response.calibration_external_last_temperature_c_available());
}

TEST(CalibrationOperationsTests, DeviceIsPresent_QueryExternalCalibrationLastTempUnsupported_ResponseIsWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertyExternalCalibrationLastTemp, _))
      .WillOnce(Return(NISysCfg_PropDoesNotExist));
  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);
  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.calibration_external_last_temperature_c_available());
}

TEST(CalibrationOperationsTests, DeviceIsPresent_QueryCalibrationNextRecommendedTimeSupported_ResponseIsWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertyRecommendedNextCalibrationTime, _))
      .WillOnce(WithArg<2>(SetTimestampToStatic0));
  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  google::protobuf::Timestamp ExpectedTime4;
  nidevice_grpc::converters::convert_to_grpc(SetTimestampToStatic0, &ExpectedTime4);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(ExpectedTime4, response.calibration_external_next_reading());
  EXPECT_TRUE(response.calibration_external_next_reading_available());
}

TEST(CalibrationOperationsTests, DeviceIsPresent_QueryCalibrationNextRecommendedTimeUnsupported_ResponseIsWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertyRecommendedNextCalibrationTime, _))
      .WillOnce(Return(NISysCfg_PropDoesNotExist));
  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);
  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.calibration_external_next_reading_available());
}

TEST(CalibrationOperationsTests, DeviceIsPresent_QueryInternalCalibrationNameSupported_ResponseIsWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertyNumberOfInternalCalibrationDetails, _))
      .WillOnce(WithArg<2>(SetUintToThree));
  EXPECT_CALL(mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationName, 0, _))
      .WillOnce(WithArg<2>(SetString0));
  EXPECT_CALL(mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationName, 1, _))
      .WillOnce(WithArg<2>(SetString1));
  EXPECT_CALL(mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationName, 2, _))
      .WillOnce(WithArg<2>(SetString2));
  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);
  EXPECT_TRUE(status.ok());
  EXPECT_EQ(TestString0, response.calibration_internal_name().at(0));
  EXPECT_EQ(TestString1, response.calibration_internal_name().at(1));
  EXPECT_EQ(TestString2, response.calibration_internal_name().at(2));

  EXPECT_TRUE(response.calibration_internal_name_available());
}

TEST(CalibrationOperationsTests, DeviceIsPresent_QueryInternalCalibrationNameUnsupported_ResponseIsWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertyNumberOfInternalCalibrationDetails, _))
      .WillOnce(WithArg<2>(SetUintToThree));
  EXPECT_CALL(mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationName, 0, _))
      .WillOnce(Return(NISysCfg_PropDoesNotExist));
  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);
  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.calibration_internal_last_reading_available());
}

TEST(CalibrationOperationsTests, DeviceIsPresent_QueryInternalCalibrationLastTimeSupported_ResponseIsWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertyNumberOfInternalCalibrationDetails, _))
      .WillOnce(WithArg<2>(SetUintToThree));
  EXPECT_CALL(mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTime, 0, _))
      .WillOnce(WithArg<2>(SetTimestampToStatic0));
  EXPECT_CALL(mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTime, 1, _))
      .WillOnce(WithArg<2>(SetTimestampToStatic1));
  EXPECT_CALL(mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTime, 2, _))
      .WillOnce(WithArg<2>(SetTimestampToStatic2));
  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);
  EXPECT_TRUE(status.ok());
  google::protobuf::Timestamp ExpectedTime0;
  google::protobuf::Timestamp ExpectedTime1;
  google::protobuf::Timestamp ExpectedTime2;

  nidevice_grpc::converters::convert_to_grpc(TestTime0, &ExpectedTime0);
  nidevice_grpc::converters::convert_to_grpc(TestTime1, &ExpectedTime1);
  nidevice_grpc::converters::convert_to_grpc(TestTime2, &ExpectedTime2);

  EXPECT_EQ(ExpectedTime0, response.calibration_internal_last_reading().at(0));
  EXPECT_EQ(ExpectedTime1, response.calibration_internal_last_reading().at(1));
  EXPECT_EQ(ExpectedTime2, response.calibration_internal_last_reading().at(2));
  EXPECT_TRUE(response.calibration_internal_last_reading_available());
}

TEST(CalibrationOperationsTests, DeviceIsPresent_QueryInternalCalibrationLastTimeUnsupported_ResponseIsWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertyNumberOfInternalCalibrationDetails, _))
      .WillOnce(WithArg<2>(SetUintToThree));
  EXPECT_CALL(mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTime, 0, _))
      .WillOnce(Return(NISysCfg_PropDoesNotExist));
  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);
  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.calibration_internal_last_reading_available());
}

TEST(CalibrationOperationsTests, DeviceIsPresent_QueryInternalCalibrationLastTempSupported_ResponseIsWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertyNumberOfInternalCalibrationDetails, _))
      .WillOnce(WithArg<2>(SetUintToThree));
  EXPECT_CALL(mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTemp, 0, _))
      .WillOnce(WithArg<2>(SetDouble0));
  EXPECT_CALL(mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTemp, 1, _))
      .WillOnce(WithArg<2>(SetDouble1));
  EXPECT_CALL(mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTemp, 2, _))
      .WillOnce(WithArg<2>(SetDouble2));
  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);
  EXPECT_TRUE(status.ok());
  EXPECT_EQ(TestDouble0, response.calibration_internal_last_temperature_c().at(0));
  EXPECT_EQ(TestDouble1, response.calibration_internal_last_temperature_c().at(1));
  EXPECT_EQ(TestDouble2, response.calibration_internal_last_temperature_c().at(2));

  EXPECT_TRUE(response.calibration_internal_last_temperature_c_available());
}

TEST(CalibrationOperationsTests, DeviceIsPresent_QueryInternalCalibrationLastTempUnsupported_ResponseIsWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertyNumberOfInternalCalibrationDetails, _))
      .WillOnce(WithArg<2>(SetUintToThree));
  EXPECT_CALL(mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTemp, 0, _))
      .WillOnce(Return(NISysCfg_PropDoesNotExist));
  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);
  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.calibration_internal_last_temperature_c_available());
}

}  // namespace unit

}  // namespace tests

}  // namespace ni
