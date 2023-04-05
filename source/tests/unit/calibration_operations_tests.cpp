#include <grpcpp/test/server_context_test_spouse.h>
#include <gtest/gtest.h>
#include <server/calibration_operations_restricted_service.h>
#include <server/converters.h>
#include <server/syscfg_library.h>
#include <tests/utilities/syscfg_mock_library.h>

namespace ni {
namespace tests {
namespace unit {

using ::ni::tests::utilities::CastAndSetArgPointee;
using ::testing::_;
using ::testing::Action;
using ::testing::DoAll;
using ::testing::Invoke;
using ::testing::NiceMock;
using ::testing::Return;
using ::testing::Throw;
using ::testing::WithArg;

const std::string kIntCalName0 = "Gain Reference";
const std::string kIntCalName1 = "Amplitude Accuracy";
const std::string kIntCalName2 = "Residual LO Power";
const std::string kIntCalName3 = "Image Suppression";

const double kIntCalLastTemp0 = 51.2;
const double kIntCalLastTemp1 = 52.3;
const double kIntCalLastTemp2 = 53.4;
const double kIntCalLastTemp3 = 54.5;

const NISysCfgTimestampUTC kIntCalLastTime0 = {{1}};
const NISysCfgTimestampUTC kIntCalLastTime1 = {{2}};
const NISysCfgTimestampUTC kIntCalLastTime2 = {{3}};
const NISysCfgTimestampUTC kIntCalLastTime3 = {{4}};

static google::protobuf::Timestamp convert_syscfg_timestamp_to_protobuf_timestamp(const NISysCfgTimestampUTC& syscfg_timestamp)
{
  google::protobuf::Timestamp protobuf_timestamp;
  nidevice_grpc::converters::convert_to_grpc(*reinterpret_cast<const CVIAbsoluteTime*>(&syscfg_timestamp), &protobuf_timestamp);
  return protobuf_timestamp;
}

const google::protobuf::Timestamp kIntCalLastTimeProtobufTimestamp0 = convert_syscfg_timestamp_to_protobuf_timestamp(kIntCalLastTime0);
const google::protobuf::Timestamp kIntCalLastTimeProtobufTimestamp1 = convert_syscfg_timestamp_to_protobuf_timestamp(kIntCalLastTime1);
const google::protobuf::Timestamp kIntCalLastTimeProtobufTimestamp2 = convert_syscfg_timestamp_to_protobuf_timestamp(kIntCalLastTime2);
const google::protobuf::Timestamp kIntCalLastTimeProtobufTimestamp3 = convert_syscfg_timestamp_to_protobuf_timestamp(kIntCalLastTime3);

const double kExtCalLastTemp0 = 45.6;
const double kExtCalLastTemp1 = 56.7;

const NISysCfgTimestampUTC kExtCalLastTime0 = {{5}};
const NISysCfgTimestampUTC kExtCalLastTime1 = {{6}};

const google::protobuf::Timestamp kExtCalLastTimeProtobufTimestamp0 = convert_syscfg_timestamp_to_protobuf_timestamp(kExtCalLastTime0);
const google::protobuf::Timestamp kExtCalLastTimeProtobufTimestamp1 = convert_syscfg_timestamp_to_protobuf_timestamp(kExtCalLastTime1);

const NISysCfgTimestampUTC kNextCalTime0 = {{7}};
const NISysCfgTimestampUTC kNextCalTime1 = {{8}};

const google::protobuf::Timestamp kNextCalTimeProtobufTimestamp0 = convert_syscfg_timestamp_to_protobuf_timestamp(kNextCalTime0);
const google::protobuf::Timestamp kNextCalTimeProtobufTimestamp1 = convert_syscfg_timestamp_to_protobuf_timestamp(kNextCalTime1);

ACTION_P(CopyStringToArg3, value)
{
  strcpy(static_cast<char*>(arg3), value);
}

static void configure_mock_library_calibration_properties_do_not_exist(NiceMock<ni::tests::utilities::SysCfgMockLibrary>* mock_library)
{ 
  EXPECT_CALL(*mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertySupportsInternalCalibration, _))
      .WillOnce(Return(NISysCfg_PropDoesNotExist));
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertyNumberOfInternalCalibrationDetails, _))
      .WillOnce(Return(NISysCfg_PropDoesNotExist));
  EXPECT_CALL(*mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationName, _, _))
      .Times(0);
  EXPECT_CALL(*mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTemp, _, _))
      .Times(0);
  EXPECT_CALL(*mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTime, _, _))
      .Times(0);
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertySupportsExternalCalibration, _))
      .WillOnce(Return(NISysCfg_PropDoesNotExist));
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertyExternalCalibrationLastTemp, _))
      .WillOnce(Return(NISysCfg_PropDoesNotExist));
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertyExternalCalibrationLastTime, _))
      .WillOnce(Return(NISysCfg_PropDoesNotExist));
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertyRecommendedNextCalibrationTime, _))
      .WillOnce(Return(NISysCfg_PropDoesNotExist));
}

static void configure_mock_library_no_calibration_support(NiceMock<ni::tests::utilities::SysCfgMockLibrary>* mock_library)
{ 
  unsigned int number_of_internal_calibration_regions = 0;

  EXPECT_CALL(*mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertySupportsInternalCalibration, _))
      .WillOnce(DoAll(CastAndSetArgPointee<2>(NISysCfgBoolFalse), Return(NISysCfg_OK)));
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertyNumberOfInternalCalibrationDetails, _))
      .WillOnce(DoAll(CastAndSetArgPointee<2>(number_of_internal_calibration_regions), Return(NISysCfg_OK)));
  EXPECT_CALL(*mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationName, _, _))
      .Times(0);
  EXPECT_CALL(*mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTemp, _, _))
      .Times(0);
  EXPECT_CALL(*mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTime, _, _))
      .Times(0);
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertySupportsExternalCalibration, _))
      .WillOnce(DoAll(CastAndSetArgPointee<2>(false), Return(NISysCfg_OK)));
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertyExternalCalibrationLastTemp, _))
      .WillOnce(Return(NISysCfg_PropDoesNotExist));
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertyExternalCalibrationLastTime, _))
      .WillOnce(Return(NISysCfg_PropDoesNotExist));
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertyRecommendedNextCalibrationTime, _))
      .WillOnce(Return(NISysCfg_PropDoesNotExist));
}

static void configure_mock_library_no_indexed_properties(
  NiceMock<ni::tests::utilities::SysCfgMockLibrary>* mock_library,
  NISysCfgBool internal_calibration_supported,
  unsigned int number_of_internal_calibration_regions,
  NISysCfgBool external_calibration_supported,
  double external_calibration_last_temperature,
  NISysCfgTimestampUTC external_calibration_last_time,
  NISysCfgTimestampUTC next_calibration_time)
{ 
  EXPECT_CALL(*mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertySupportsInternalCalibration, _))
      .WillOnce(DoAll(CastAndSetArgPointee<2>(internal_calibration_supported), Return(NISysCfg_OK)));
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertyNumberOfInternalCalibrationDetails, _))
      .WillOnce(DoAll(CastAndSetArgPointee<2>(number_of_internal_calibration_regions), Return(NISysCfg_OK)));
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertySupportsExternalCalibration, _))
      .WillOnce(DoAll(CastAndSetArgPointee<2>(external_calibration_supported), Return(NISysCfg_OK)));
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertyExternalCalibrationLastTemp, _))
      .WillOnce(DoAll(CastAndSetArgPointee<2>(external_calibration_last_temperature), Return(NISysCfg_OK)));
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertyExternalCalibrationLastTime, _))
      .WillOnce(DoAll(CastAndSetArgPointee<2>(external_calibration_last_time), Return(NISysCfg_OK)));
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertyRecommendedNextCalibrationTime, _))
      .WillOnce(DoAll(CastAndSetArgPointee<2>(next_calibration_time), Return(NISysCfg_OK)));
}

static void configure_mock_library_one_internal_calibration_region(NiceMock<ni::tests::utilities::SysCfgMockLibrary>* mock_library)
{
  configure_mock_library_no_indexed_properties(
    mock_library,
    NISysCfgBoolTrue, //internal_calibration_supported
    1, //number_of_internal_calibration_regions
    NISysCfgBoolTrue, //external_calibration_supported
    kExtCalLastTemp0,
    kExtCalLastTime0,
    kNextCalTime0);

  EXPECT_CALL(*mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationName, 0, _))
      .WillOnce(DoAll(CopyStringToArg3(kIntCalName0.c_str()), Return(NISysCfg_OK)));
  EXPECT_CALL(*mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTemp, 0, _))
      .WillOnce(DoAll(CastAndSetArgPointee<3>(kIntCalLastTemp0), Return(NISysCfg_OK)));
  EXPECT_CALL(*mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTime, 0, _))
      .WillOnce(DoAll(CastAndSetArgPointee<3>(kIntCalLastTime0), Return(NISysCfg_OK)));
}

static void configure_mock_library_three_internal_calibration_regions(NiceMock<ni::tests::utilities::SysCfgMockLibrary>* mock_library)
{
  configure_mock_library_no_indexed_properties(
    mock_library,
    NISysCfgBoolTrue, //internal_calibration_supported
    3, //number_of_internal_calibration_regions
    NISysCfgBoolTrue, //external_calibration_supported
    kExtCalLastTemp1,
    kExtCalLastTime1,
    kNextCalTime1);

  EXPECT_CALL(*mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationName, 0, _))
      .WillOnce(DoAll(CopyStringToArg3(kIntCalName1.c_str()), Return(NISysCfg_OK)));
  EXPECT_CALL(*mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationName, 1, _))
      .WillOnce(DoAll(CopyStringToArg3(kIntCalName2.c_str()), Return(NISysCfg_OK)));
  EXPECT_CALL(*mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationName, 2, _))
      .WillOnce(DoAll(CopyStringToArg3(kIntCalName3.c_str()), Return(NISysCfg_OK)));
  EXPECT_CALL(*mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTemp, 0, _))
      .WillOnce(DoAll(CastAndSetArgPointee<3>(kIntCalLastTemp1), Return(NISysCfg_OK)));
  EXPECT_CALL(*mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTemp, 1, _))
      .WillOnce(DoAll(CastAndSetArgPointee<3>(kIntCalLastTemp2), Return(NISysCfg_OK)));
  EXPECT_CALL(*mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTemp, 2, _))
      .WillOnce(DoAll(CastAndSetArgPointee<3>(kIntCalLastTemp3), Return(NISysCfg_OK)));
  EXPECT_CALL(*mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTime, 0, _))
      .WillOnce(DoAll(CastAndSetArgPointee<3>(kIntCalLastTime1), Return(NISysCfg_OK)));
  EXPECT_CALL(*mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTime, 1, _))
      .WillOnce(DoAll(CastAndSetArgPointee<3>(kIntCalLastTime2), Return(NISysCfg_OK)));
  EXPECT_CALL(*mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTime, 2, _))
      .WillOnce(DoAll(CastAndSetArgPointee<3>(kIntCalLastTime3), Return(NISysCfg_OK)));
}

static void configure_mock_library_three_internal_calibration_regions_indexed_properties_do_not_exist(NiceMock<ni::tests::utilities::SysCfgMockLibrary>* mock_library)
{
  configure_mock_library_no_indexed_properties(
    mock_library,
    NISysCfgBoolTrue, //internal_calibration_supported
    3, //number_of_internal_calibration_regions
    NISysCfgBoolTrue, //external_calibration_supported
    kExtCalLastTemp1,
    kExtCalLastTime1,
    kNextCalTime1);

  EXPECT_CALL(*mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationName, _, _))
      .WillOnce(Return(NISysCfg_PropDoesNotExist));
  EXPECT_CALL(*mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTemp, _, _))
      .WillOnce(Return(NISysCfg_PropDoesNotExist));
  EXPECT_CALL(*mock_library, GetResourceIndexedProperty(_, NISysCfgIndexedPropertyInternalCalibrationLastTime, _, _))
      .WillOnce(Return(NISysCfg_PropDoesNotExist));
}

TEST(CalibrationOperationsTests, SupportsIntCal_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_one_internal_calibration_region(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(response.has_supports_internal_calibration());
  EXPECT_TRUE(response.supports_internal_calibration());
}

TEST(CalibrationOperationsTests, DoesNotSupportIntCal_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_no_calibration_support(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(response.has_supports_internal_calibration());
  EXPECT_FALSE(response.supports_internal_calibration());
}

TEST(CalibrationOperationsTests, SupportsIntCalPropDoesNotExist_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_calibration_properties_do_not_exist(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.has_supports_internal_calibration());
  EXPECT_FALSE(response.supports_internal_calibration());
}

TEST(CalibrationOperationsTests, NoIntCalRegions_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_no_calibration_support(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(response.has_number_of_internal_calibration_details());
  EXPECT_EQ(0, response.number_of_internal_calibration_details());
}

TEST(CalibrationOperationsTests, OneIntCalRegion_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_one_internal_calibration_region(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(response.has_number_of_internal_calibration_details());
  EXPECT_EQ(1, response.number_of_internal_calibration_details());
}

TEST(CalibrationOperationsTests, ThreeIntCalRegions_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_three_internal_calibration_regions(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(response.has_number_of_internal_calibration_details());
  EXPECT_EQ(3, response.number_of_internal_calibration_details());
}

TEST(CalibrationOperationsTests, NumberOfIntCalDetailsPropDoesNotExist_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_calibration_properties_do_not_exist(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.has_number_of_internal_calibration_details());
  EXPECT_EQ(0, response.number_of_internal_calibration_details());
}

TEST(CalibrationOperationsTests, OneIntCalName_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_one_internal_calibration_region(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(1, response.internal_calibration_names().size());
  if (response.internal_calibration_names().size() == 1)
  {
    EXPECT_EQ(kIntCalName0, response.internal_calibration_names()[0]);
  }
}

TEST(CalibrationOperationsTests, ThreeIntCalNames_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_three_internal_calibration_regions(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(3, response.internal_calibration_names().size());
  if (response.internal_calibration_names().size() == 3)
  {
    EXPECT_EQ(kIntCalName1, response.internal_calibration_names()[0]);
    EXPECT_EQ(kIntCalName2, response.internal_calibration_names()[1]);
    EXPECT_EQ(kIntCalName3, response.internal_calibration_names()[2]);
  }
}

TEST(CalibrationOperationsTests, IntCalNamePropDoesNotExist_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_three_internal_calibration_regions_indexed_properties_do_not_exist(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.internal_calibration_names().size());
}

TEST(CalibrationOperationsTests, OneIntCalLastTemp_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_one_internal_calibration_region(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(1, response.internal_calibration_last_temperatures().size());
  if (response.internal_calibration_last_temperatures().size() == 1)
  {
    EXPECT_EQ(kIntCalLastTemp0, response.internal_calibration_last_temperatures()[0]);
  }
}

TEST(CalibrationOperationsTests, ThreeIntCalLastTemps_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_three_internal_calibration_regions(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(3, response.internal_calibration_last_temperatures().size());
  if (response.internal_calibration_last_temperatures().size() == 3)
  {
    EXPECT_EQ(kIntCalLastTemp1, response.internal_calibration_last_temperatures()[0]);
    EXPECT_EQ(kIntCalLastTemp2, response.internal_calibration_last_temperatures()[1]);
    EXPECT_EQ(kIntCalLastTemp3, response.internal_calibration_last_temperatures()[2]);
  }
}

TEST(CalibrationOperationsTests, IntCalLastTempPropDoesNotExist_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_three_internal_calibration_regions_indexed_properties_do_not_exist(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.internal_calibration_last_temperatures().size());
}

TEST(CalibrationOperationsTests, OneIntCalLastTime_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_one_internal_calibration_region(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(1, response.internal_calibration_last_times().size());
  if (response.internal_calibration_last_times().size() == 1)
  {
    EXPECT_EQ(kIntCalLastTimeProtobufTimestamp0, response.internal_calibration_last_times()[0]);
  }
}

TEST(CalibrationOperationsTests, ThreeIntCalLastTimes_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_three_internal_calibration_regions(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(3, response.internal_calibration_last_times().size());
  if (response.internal_calibration_last_times().size() == 3)
  {
    EXPECT_EQ(kIntCalLastTimeProtobufTimestamp1, response.internal_calibration_last_times()[0]);
    EXPECT_EQ(kIntCalLastTimeProtobufTimestamp2, response.internal_calibration_last_times()[1]);
    EXPECT_EQ(kIntCalLastTimeProtobufTimestamp3, response.internal_calibration_last_times()[2]);
  }
}

TEST(CalibrationOperationsTests, IntCalLastTimePropDoesNotExist_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_three_internal_calibration_regions_indexed_properties_do_not_exist(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.internal_calibration_last_times().size());
}

TEST(CalibrationOperationsTests, SupportsExtCal_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_one_internal_calibration_region(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(response.has_supports_external_calibration());
  EXPECT_TRUE(response.supports_external_calibration());
}

TEST(CalibrationOperationsTests, DoesNotSupportExtCal_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_no_calibration_support(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(response.has_supports_external_calibration());
  EXPECT_FALSE(response.supports_external_calibration());
}

TEST(CalibrationOperationsTests, SupportsExtCalPropDoesNotExist_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_calibration_properties_do_not_exist(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.has_supports_external_calibration());
  EXPECT_FALSE(response.supports_external_calibration());
}

TEST(CalibrationOperationsTests, ExtCalLastTempPropExists_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_one_internal_calibration_region(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(response.has_external_calibration_last_temperature());
  EXPECT_EQ(kExtCalLastTemp0, response.external_calibration_last_temperature());
}

TEST(CalibrationOperationsTests, ExtCalLastTempPropDoesNotExist_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_calibration_properties_do_not_exist(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.has_external_calibration_last_temperature());
  EXPECT_EQ(0.0, response.external_calibration_last_temperature());
}

TEST(CalibrationOperationsTests, ExtCalLastTimePropExists_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_one_internal_calibration_region(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(response.has_external_calibration_last_time());
  EXPECT_EQ(kExtCalLastTimeProtobufTimestamp0, response.external_calibration_last_time());
}

TEST(CalibrationOperationsTests, ExtCalLastTimePropDoesNotExist_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_calibration_properties_do_not_exist(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.has_external_calibration_last_time());
  EXPECT_EQ(::google::protobuf::Timestamp::default_instance(), response.external_calibration_last_time());
}

TEST(CalibrationOperationsTests, NextCalTimePropExists_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_one_internal_calibration_region(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(response.has_recommended_next_calibration_time());
  EXPECT_EQ(kNextCalTimeProtobufTimestamp0, response.recommended_next_calibration_time());
}

TEST(CalibrationOperationsTests, NextCalTimePropDoesNotExist_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  configure_mock_library_calibration_properties_do_not_exist(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.has_recommended_next_calibration_time());
  EXPECT_EQ(::google::protobuf::Timestamp::default_instance(), response.recommended_next_calibration_time());
}

}  // namespace unit

}  // namespace tests

}  // namespace ni