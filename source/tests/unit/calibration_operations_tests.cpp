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
static NISysCfgStatus SetTimestampToStatic0(void* value)
{
  *reinterpret_cast<NISysCfgTimestampUTC*>(value) = {{55564}};
  return NISysCfg_OK;
}
static NISysCfgStatus SetTimestampToStatic1(void* value)
{
  *reinterpret_cast<NISysCfgTimestampUTC*>(value) = {{9569}};
  return NISysCfg_OK;
}

static NISysCfgStatus SetTimestampToStatic2(void* value)
{
  *reinterpret_cast<NISysCfgTimestampUTC*>(value) = {{8864}};
  return NISysCfg_OK;
}

const std::string TestString1 = "DAQ";

const std::string TestString2 = "PXI";

const std::string TestString3 = "MyRIO";

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
static NISysCfgStatus SetString3(void* value)
{
  strcpy(static_cast<char*>(value), TestString3.c_str());
  return NISysCfg_OK;
}

static NISysCfgStatus SetDouble1(void* value)
{
  *static_cast<double*>(value) = 7.8;
  return NISysCfg_OK;
}

static NISysCfgStatus SetDouble2(void* value)
{
  *static_cast<double*>(value) = 8.342;
  return NISysCfg_OK;
}

static NISysCfgStatus SetDouble3(void* value)
{
  *static_cast<double*>(value) = 72.3;
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
  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);
  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(response.calibration_external_last_reading());
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
  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(response.calibration_external_next_reading());
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
      .WillOnce(WithArg<2>(SetString1));
  EXPECT_CALL(mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationName, 1, _))
      .WillOnce(WithArg<2>(SetString2));
  EXPECT_CALL(mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationName, 2, _))
      .WillOnce(WithArg<2>(SetString3));
  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);
  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(response.calibration_internal_name());
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
  EXPECT_TRUE(response.calibration_internal_last_reading());
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
      .WillOnce(WithArg<2>(SetDouble1));
  EXPECT_CALL(mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTemp, 1, _))
      .WillOnce(WithArg<2>(SetDouble2));
  EXPECT_CALL(mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTemp, 2, _))
      .WillOnce(WithArg<2>(SetDouble3));
  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);
  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(response.calibration_internal_last_temperature_c());
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
