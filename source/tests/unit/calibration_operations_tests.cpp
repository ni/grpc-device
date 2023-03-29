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

static google::protobuf::Timestamp convertSysCfgTimestampToProtobufTimestamp(const NISysCfgTimestampUTC& sysCfgTimestamp)
{
  google::protobuf::Timestamp protobufTimestamp;
  nidevice_grpc::converters::convert_to_grpc(*reinterpret_cast<const CVIAbsoluteTime*>(&sysCfgTimestamp), &protobufTimestamp);
  return protobufTimestamp;
}

const google::protobuf::Timestamp kIntCalLastTimeProtobufTimestamp0 = convertSysCfgTimestampToProtobufTimestamp(kIntCalLastTime0);
const google::protobuf::Timestamp kIntCalLastTimeProtobufTimestamp1 = convertSysCfgTimestampToProtobufTimestamp(kIntCalLastTime1);
const google::protobuf::Timestamp kIntCalLastTimeProtobufTimestamp2 = convertSysCfgTimestampToProtobufTimestamp(kIntCalLastTime2);
const google::protobuf::Timestamp kIntCalLastTimeProtobufTimestamp3 = convertSysCfgTimestampToProtobufTimestamp(kIntCalLastTime3);

const double kExtCalLastTemp0 = 45.6;
const double kExtCalLastTemp1 = 56.7;

const NISysCfgTimestampUTC kExtCalLastTime0 = {{5}};
const NISysCfgTimestampUTC kExtCalLastTime1 = {{6}};

const google::protobuf::Timestamp kExtCalLastTimeProtobufTimestamp0 = convertSysCfgTimestampToProtobufTimestamp(kExtCalLastTime0);
const google::protobuf::Timestamp kExtCalLastTimeProtobufTimestamp1 = convertSysCfgTimestampToProtobufTimestamp(kExtCalLastTime1);

const NISysCfgTimestampUTC kNextCalTime0 = {{7}};
const NISysCfgTimestampUTC kNextCalTime1 = {{8}};

const google::protobuf::Timestamp kNextCalTimeProtobufTimestamp0 = convertSysCfgTimestampToProtobufTimestamp(kNextCalTime0);
const google::protobuf::Timestamp kNextCalTimeProtobufTimestamp1 = convertSysCfgTimestampToProtobufTimestamp(kNextCalTime1);

ACTION_P(CopyStringToArg3, value)
{
  strcpy_s(static_cast<char*>(arg3), NISYSCFG_SIMPLE_STRING_LENGTH, value);
}

void ConfigMockLibraryCalPropsDoNotExist(NiceMock<ni::tests::utilities::SysCfgMockLibrary>* mock_library)
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

void ConfigMockLibraryNoCalSupport(NiceMock<ni::tests::utilities::SysCfgMockLibrary>* mock_library)
{ 
  EXPECT_CALL(*mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertySupportsInternalCalibration, _))
      .WillOnce(DoAll(CastAndSetArgPointee<2>(false), Return(NISysCfg_OK)));
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertyNumberOfInternalCalibrationDetails, _))
      .WillOnce(DoAll(CastAndSetArgPointee<2>(unsigned int(0)), Return(NISysCfg_OK)));
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

void ConfigMockLibraryNoIndexedProps(
  NiceMock<ni::tests::utilities::SysCfgMockLibrary>* mock_library,
  bool intCalSupported,
  unsigned int numberOfIntCalRegions,
  bool extCalSupported,
  double extCalLastTemp,
  NISysCfgTimestampUTC extCalLastTime,
  NISysCfgTimestampUTC nextCalTime)
{ 
  EXPECT_CALL(*mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertySupportsInternalCalibration, _))
      .WillOnce(DoAll(CastAndSetArgPointee<2>(intCalSupported), Return(NISysCfg_OK)));
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertyNumberOfInternalCalibrationDetails, _))
      .WillOnce(DoAll(CastAndSetArgPointee<2>(numberOfIntCalRegions), Return(NISysCfg_OK)));
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertySupportsExternalCalibration, _))
      .WillOnce(DoAll(CastAndSetArgPointee<2>(extCalSupported), Return(NISysCfg_OK)));
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertyExternalCalibrationLastTemp, _))
      .WillOnce(DoAll(CastAndSetArgPointee<2>(extCalLastTemp), Return(NISysCfg_OK)));
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertyExternalCalibrationLastTime, _))
      .WillOnce(DoAll(CastAndSetArgPointee<2>(extCalLastTime), Return(NISysCfg_OK)));
  EXPECT_CALL(*mock_library, GetResourceProperty(_, NISysCfgResourcePropertyRecommendedNextCalibrationTime, _))
      .WillOnce(DoAll(CastAndSetArgPointee<2>(nextCalTime), Return(NISysCfg_OK)));
}

void ConfigMockLibraryOneIntCalRegion(NiceMock<ni::tests::utilities::SysCfgMockLibrary>* mock_library)
{
  ConfigMockLibraryNoIndexedProps(
    mock_library,
    true, //intCalSupported
    1, //numberOfIntCalRegions
    true, //extCalSupported
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

void ConfigMockLibraryThreeIntCalRegions(NiceMock<ni::tests::utilities::SysCfgMockLibrary>* mock_library)
{
  ConfigMockLibraryNoIndexedProps(
    mock_library,
    true, //intCalSupported
    3, //numberOfIntCalRegions
    true, //extCalSupported
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

void ConfigMockLibraryThreeIntCalRegionsIndexedPropsDoNotExist(NiceMock<ni::tests::utilities::SysCfgMockLibrary>* mock_library)
{
  ConfigMockLibraryNoIndexedProps(
    mock_library,
    true, //intCalSupported
    3, //numberOfIntCalRegions
    true, //extCalSupported
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
  ConfigMockLibraryOneIntCalRegion(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(response.supports_internal_calibration());
  EXPECT_TRUE(response.supports_internal_calibration_available());
}

TEST(CalibrationOperationsTests, DoesNotSupportIntCal_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  ConfigMockLibraryNoCalSupport(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.supports_internal_calibration());
  EXPECT_TRUE(response.supports_internal_calibration_available());
}

TEST(CalibrationOperationsTests, SupportsIntCalPropDoesNotExist_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  ConfigMockLibraryCalPropsDoNotExist(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.supports_internal_calibration_available());
}

TEST(CalibrationOperationsTests, NoIntCalRegions_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  ConfigMockLibraryNoCalSupport(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(response.number_of_internal_calibration_details(), 0);
  EXPECT_TRUE(response.number_of_internal_calibration_details_available());
}

TEST(CalibrationOperationsTests, OneIntCalRegion_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  ConfigMockLibraryOneIntCalRegion(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(response.number_of_internal_calibration_details(), 1);
  EXPECT_TRUE(response.number_of_internal_calibration_details_available());
}

TEST(CalibrationOperationsTests, ThreeIntCalRegions_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  ConfigMockLibraryThreeIntCalRegions(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(response.number_of_internal_calibration_details(), 3);
  EXPECT_TRUE(response.number_of_internal_calibration_details_available());
}

TEST(CalibrationOperationsTests, NumberOfIntCalDetailsPropDoesNotExist_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  ConfigMockLibraryCalPropsDoNotExist(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.number_of_internal_calibration_details_available());
}

TEST(CalibrationOperationsTests, OneIntCalName_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  ConfigMockLibraryOneIntCalRegion(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(response.internal_calibration_names().size(), 1);
  if (response.internal_calibration_names().size() == 1)
  {
    EXPECT_EQ(response.internal_calibration_names()[0], kIntCalName0);
  }
  EXPECT_TRUE(response.internal_calibration_names_available());
}

TEST(CalibrationOperationsTests, ThreeIntCalNames_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  ConfigMockLibraryThreeIntCalRegions(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(response.internal_calibration_names().size(), 3);
  if (response.internal_calibration_names().size() == 3)
  {
    EXPECT_EQ(response.internal_calibration_names()[0], kIntCalName1);
    EXPECT_EQ(response.internal_calibration_names()[1], kIntCalName2);
    EXPECT_EQ(response.internal_calibration_names()[2], kIntCalName3);
  }
  EXPECT_TRUE(response.internal_calibration_names_available());
}

TEST(CalibrationOperationsTests, IntCalNamePropDoesNotExist_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  ConfigMockLibraryThreeIntCalRegionsIndexedPropsDoNotExist(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.internal_calibration_names_available());
}

TEST(CalibrationOperationsTests, OneIntCalLastTemp_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  ConfigMockLibraryOneIntCalRegion(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(response.internal_calibration_last_temperatures().size(), 1);
  if (response.internal_calibration_last_temperatures().size() == 1)
  {
    EXPECT_EQ(response.internal_calibration_last_temperatures()[0], kIntCalLastTemp0);
  }
  EXPECT_TRUE(response.internal_calibration_last_temperatures_available());
}

TEST(CalibrationOperationsTests, ThreeIntCalLastTemps_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  ConfigMockLibraryThreeIntCalRegions(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(response.internal_calibration_last_temperatures().size(), 3);
  if (response.internal_calibration_last_temperatures().size() == 3)
  {
    EXPECT_EQ(response.internal_calibration_last_temperatures()[0], kIntCalLastTemp1);
    EXPECT_EQ(response.internal_calibration_last_temperatures()[1], kIntCalLastTemp2);
    EXPECT_EQ(response.internal_calibration_last_temperatures()[2], kIntCalLastTemp3);
  }
  EXPECT_TRUE(response.internal_calibration_last_temperatures_available());
}

TEST(CalibrationOperationsTests, IntCalLastTempPropDoesNotExist_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  ConfigMockLibraryThreeIntCalRegionsIndexedPropsDoNotExist(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.internal_calibration_last_temperatures_available());
}

TEST(CalibrationOperationsTests, OneIntCalLastTime_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  ConfigMockLibraryOneIntCalRegion(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(response.internal_calibration_last_times().size(), 1);
  if (response.internal_calibration_last_times().size() == 1)
  {
    EXPECT_EQ(response.internal_calibration_last_times()[0], kIntCalLastTimeProtobufTimestamp0);
  }
  EXPECT_TRUE(response.internal_calibration_last_times_available());
}

TEST(CalibrationOperationsTests, ThreeIntCalLastTimes_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  ConfigMockLibraryThreeIntCalRegions(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(response.internal_calibration_last_times().size(), 3);
  if (response.internal_calibration_last_times().size() == 3)
  {
    EXPECT_EQ(response.internal_calibration_last_times()[0], kIntCalLastTimeProtobufTimestamp1);
    EXPECT_EQ(response.internal_calibration_last_times()[1], kIntCalLastTimeProtobufTimestamp2);
    EXPECT_EQ(response.internal_calibration_last_times()[2], kIntCalLastTimeProtobufTimestamp3);
  }
  EXPECT_TRUE(response.internal_calibration_last_times_available());
}

TEST(CalibrationOperationsTests, IntCalLastTimePropDoesNotExist_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  ConfigMockLibraryThreeIntCalRegionsIndexedPropsDoNotExist(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.internal_calibration_last_times_available());
}

TEST(CalibrationOperationsTests, SupportsExtCal_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  ConfigMockLibraryOneIntCalRegion(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(response.supports_external_calibration());
  EXPECT_TRUE(response.supports_external_calibration_available());
}

TEST(CalibrationOperationsTests, DoesNotSupportExtCal_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  ConfigMockLibraryNoCalSupport(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.supports_external_calibration());
  EXPECT_TRUE(response.supports_external_calibration_available());
}

TEST(CalibrationOperationsTests, SupportsExtCalPropDoesNotExist_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  ConfigMockLibraryCalPropsDoNotExist(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.supports_external_calibration_available());
}

TEST(CalibrationOperationsTests, ExtCalLastTempPropExists_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  ConfigMockLibraryOneIntCalRegion(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(response.external_calibration_last_temperature(), kExtCalLastTemp0);
  EXPECT_TRUE(response.external_calibration_last_temperature_available());
}

TEST(CalibrationOperationsTests, ExtCalLastTempPropDoesNotExist_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  ConfigMockLibraryCalPropsDoNotExist(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.external_calibration_last_temperature_available());
}

TEST(CalibrationOperationsTests, ExtCalLastTimePropExists_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  ConfigMockLibraryOneIntCalRegion(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(response.external_calibration_last_time(), kExtCalLastTimeProtobufTimestamp0);
  EXPECT_TRUE(response.external_calibration_last_time_available());
}

TEST(CalibrationOperationsTests, ExtCalLastTimePropDoesNotExist_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  ConfigMockLibraryCalPropsDoNotExist(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.external_calibration_last_time_available());
}

TEST(CalibrationOperationsTests, NextCalTimePropExists_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  ConfigMockLibraryOneIntCalRegion(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(response.recommended_next_calibration_time(), kNextCalTimeProtobufTimestamp0);
  EXPECT_TRUE(response.recommended_next_calibration_time_available());
}

TEST(CalibrationOperationsTests, NextCalTimePropDoesNotExist_GetCalibrationInformation_ResponseWritten)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::CalibrationOperationsRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::GetCalibrationInformationRequest request;
  nidevice_restricted_grpc::GetCalibrationInformationResponse response;
  ConfigMockLibraryCalPropsDoNotExist(&mock_library);

  ::grpc::Status status = service.GetCalibrationInformation(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_FALSE(response.recommended_next_calibration_time_available());
}

}  // namespace unit

}  // namespace tests

}  // namespace ni