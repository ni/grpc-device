#include <grpcpp/impl/grpc_library.h>
#include <gtest/gtest.h>
#include <nifake/nifake_mock_library.h>
#include <nifake/nifake_service.h>
#include <server/session_repository.h>

#include <thread>

namespace ni {
namespace tests {
namespace unit {

using ::testing::_;
using ::testing::DoAll;
using ::testing::NiceMock;
using ::testing::Pointee;
using ::testing::Return;
using ::testing::SetArgPointee;
using ::testing::Throw;

const ViSession kViSession = 12345678;
const ViStatus kDriverSuccess = 0;
const ViStatus kDriverFailure = 1;
ViConstString kChannelName = "channel";

std::uint32_t create_session(ni::hardware::grpc::internal::SessionRepository& session_repo, ViSession sessionToStore)
{
  auto init_lambda = [&]() -> std::tuple<int, uint32_t> {
    return std::make_tuple(0, sessionToStore);
  };
  uint32_t session_id;
  session_repo.add_session("", init_lambda, NULL, session_id);
  return session_id;
}

// Matcher used for array arguments to ensure each element in the argument matches a set of expected values.
MATCHER_P2(ElementsMatch, expected_values, size, "")
{
  for (int i = 0; i < size; i++) {
    if (expected_values[i] != arg[i])
      return false;
  }
  return true;
}

// Error logic tests using GetABoolean
TEST(NiFakeServiceTests, NiFakeService_FunctionNotFound_DoesNotCallFunction)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t sessionId = create_session(session_repository, kViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  std::string message = "Exception!";
  EXPECT_CALL(library, GetABoolean)
      .WillOnce(Throw(ni::hardware::grpc::internal::LibraryLoadException(message)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetABooleanRequest request;
  request.mutable_vi()->set_id(sessionId);
  ni::fake::grpc::GetABooleanResponse response;
  ::grpc::Status status = service.GetABoolean(&context, &request, &response);

  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
  EXPECT_EQ(message, status.error_message());
}

TEST(NiFakeServiceTests, NiFakeService_FunctionCallErrors_ResponseValuesNotSet)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t sessionId = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  ViBoolean aBoolean = true;
  EXPECT_CALL(library, GetABoolean(kViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(aBoolean), Return(kDriverFailure)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetABooleanRequest request;
  request.mutable_vi()->set_id(sessionId);
  ni::fake::grpc::GetABooleanResponse response;
  ::grpc::Status status = service.GetABoolean(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverFailure, response.status());
  EXPECT_NE(aBoolean, response.a_boolean());
}

TEST(NiFakeServiceTests, NiFakeService_GetABoolean_CallsGetABoolean)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t sessionId = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  ViBoolean aBoolean = true;
  EXPECT_CALL(library, GetABoolean(kViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(aBoolean), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetABooleanRequest request;
  request.mutable_vi()->set_id(sessionId);
  ni::fake::grpc::GetABooleanResponse response;
  ::grpc::Status status = service.GetABoolean(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(aBoolean, response.a_boolean());
}

// Individual Function Tests for functions without enums or arrays
TEST(NiFakeServiceTests, NiFakeService_Abort_CallsAbort)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t sessionId = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  EXPECT_CALL(library, Abort(kViSession))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  ni::fake::grpc::AbortRequest request;
  request.mutable_vi()->set_id(sessionId);
  ni::fake::grpc::AbortResponse response;
  ::grpc::Status status = service.Abort(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_GetANumber_CallsGetANumber)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t sessionId = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  ViInt16 aNumber = 15;
  EXPECT_CALL(library, GetANumber(kViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(aNumber), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetANumberRequest request;
  request.mutable_vi()->set_id(sessionId);
  ni::fake::grpc::GetANumberResponse response;
  ::grpc::Status status = service.GetANumber(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(aNumber, response.a_number());
}

TEST(NiFakeServiceTests, NiFakeService_GetArraySizeForPythonCode_CallsGetArraySizeForPythonCode)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t sessionId = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  ViInt32 arraySize = 1000;
  EXPECT_CALL(library, GetArraySizeForPythonCode(kViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(arraySize), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetArraySizeForPythonCodeRequest request;
  request.mutable_vi()->set_id(sessionId);
  ni::fake::grpc::GetArraySizeForPythonCodeResponse response;
  ::grpc::Status status = service.GetArraySizeForPythonCode(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(arraySize, response.size_out());
}

TEST(NiFakeServiceTests, NiFakeService_GetAttributeViBoolean_CallsGetAttributeViBoolean)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t sessionId = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  ni::fake::grpc::NiFakeAttributes attributeId = ni::fake::grpc::NIFAKE_READ_WRITE_BOOL;
  ViBoolean attributeValue = true;
  EXPECT_CALL(library, GetAttributeViBoolean(kViSession, Pointee(*kChannelName), attributeId, _))
      .WillOnce(DoAll(SetArgPointee<3>(attributeValue), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetAttributeViBooleanRequest request;
  request.mutable_vi()->set_id(sessionId);
  request.set_channel_name(kChannelName);
  request.set_attribute_id(attributeId);
  ni::fake::grpc::GetAttributeViBooleanResponse response;
  ::grpc::Status status = service.GetAttributeViBoolean(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(attributeValue, response.attribute_value());
}

TEST(NiFakeServiceTests, NiFakeService_GetAttributeViInt32_CallsGetAttributeViInt32)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t sessionId = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  ni::fake::grpc::NiFakeAttributes attributeId = ni::fake::grpc::NIFAKE_READ_WRITE_INTEGER;
  ViInt32 attributeValue = 12345;
  EXPECT_CALL(library, GetAttributeViInt32(kViSession, Pointee(*kChannelName), attributeId, _))
      .WillOnce(DoAll(SetArgPointee<3>(attributeValue), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetAttributeViInt32Request request;
  request.mutable_vi()->set_id(sessionId);
  request.set_channel_name(kChannelName);
  request.set_attribute_id(attributeId);
  ni::fake::grpc::GetAttributeViInt32Response response;
  ::grpc::Status status = service.GetAttributeViInt32(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(attributeValue, response.attribute_value());
}

TEST(NiFakeServiceTests, NiFakeService_GetAttributeViInt64_CallsGetAttributeViInt64)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t sessionId = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  ni::fake::grpc::NiFakeAttributes attributeId = ni::fake::grpc::NIFAKE_READ_WRITE_INT64;
  ViInt64 attributeValue = -12345;
  EXPECT_CALL(library, GetAttributeViInt64(kViSession, Pointee(*kChannelName), attributeId, _))
      .WillOnce(DoAll(SetArgPointee<3>(attributeValue), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetAttributeViInt64Request request;
  request.mutable_vi()->set_id(sessionId);
  request.set_channel_name(kChannelName);
  request.set_attribute_id(attributeId);
  ni::fake::grpc::GetAttributeViInt64Response response;
  ::grpc::Status status = service.GetAttributeViInt64(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(attributeValue, response.attribute_value());
}

TEST(NiFakeServiceTests, NiFakeService_GetAttributeViReal64_CallsGetAttributeViReal64)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t sessionId = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  ni::fake::grpc::NiFakeAttributes attributeId = ni::fake::grpc::NIFAKE_READ_WRITE_DOUBLE;
  ViReal64 attributeValue = 12.345;
  EXPECT_CALL(library, GetAttributeViReal64(kViSession, Pointee(*kChannelName), attributeId, _))
      .WillOnce(DoAll(SetArgPointee<3>(attributeValue), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetAttributeViReal64Request request;
  request.mutable_vi()->set_id(sessionId);
  request.set_channel_name(kChannelName);
  request.set_attribute_id(attributeId);
  ni::fake::grpc::GetAttributeViReal64Response response;
  ::grpc::Status status = service.GetAttributeViReal64(&context, &request, &response);
  ;

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(attributeValue, response.attribute_value());
}

TEST(NiFakeServiceTests, NiFakeService_GetCalDateAndTime_CallsGetCalDateAndTime)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t sessionId = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  ViInt32 calType = 0;
  ViInt32 month = 1, day = 17, year = 2021, hour = 0, minute = 0;
  EXPECT_CALL(library, GetCalDateAndTime(kViSession, calType, _, _, _, _, _))
      .WillOnce(DoAll(
          SetArgPointee<2>(month),
          SetArgPointee<3>(day),
          SetArgPointee<4>(year),
          SetArgPointee<5>(hour),
          SetArgPointee<6>(minute),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetCalDateAndTimeRequest request;
  request.mutable_vi()->set_id(sessionId);
  request.set_cal_type(calType);
  ni::fake::grpc::GetCalDateAndTimeResponse response;
  ::grpc::Status status = service.GetCalDateAndTime(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(month, response.month());
  EXPECT_EQ(day, response.day());
  EXPECT_EQ(year, response.year());
  EXPECT_EQ(hour, response.hour());
  EXPECT_EQ(minute, response.minute());
}

TEST(NiFakeServiceTests, NiFakeService_GetCalInterval_CallsGetCalInterval)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t sessionId = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  ni::fake::grpc::NiFakeAttributes attributeId = ni::fake::grpc::NIFAKE_READ_WRITE_DOUBLE;
  ViInt32 months = 24;
  EXPECT_CALL(library, GetCalInterval(kViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(months), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetCalIntervalRequest request;
  request.mutable_vi()->set_id(sessionId);
  ni::fake::grpc::GetCalIntervalResponse response;
  ::grpc::Status status = service.GetCalInterval(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(months, response.months());
}

TEST(NiFakeServiceTests, NiFakeService_AcceptListOfDurationsInSeconds_CallsAcceptListOfDurationsInSeconds)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t sessionId = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  const ViReal64 delays[] = {1, 2, 3, 4, 5};
  ViInt32 expectedSize = 5;
  EXPECT_CALL(library_wrapper, AcceptListOfDurationsInSeconds(kViSession, expectedSize, ElementsMatch(delays, expectedSize)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  ni::fake::grpc::AcceptListOfDurationsInSecondsRequest request;
  request.mutable_vi()->set_id(sessionId);
  for (ViReal64 delay : delays) {
    request.add_delays(delay);
  }
  ni::fake::grpc::AcceptListOfDurationsInSecondsResponse response;
  ::grpc::Status status = service.AcceptListOfDurationsInSeconds(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_DoubleAllTheNums_CallsDoubleAllTheNums)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t sessionId = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  const ViReal64 numbers[] = {1, 2, 3, 4, 5};
  ViInt32 expectedSize = 5;
  EXPECT_CALL(library_wrapper, DoubleAllTheNums(kViSession, expectedSize, ElementsMatch(numbers, expectedSize)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  ni::fake::grpc::DoubleAllTheNumsRequest request;
  request.mutable_vi()->set_id(sessionId);
  for (ViReal64 number : numbers) {
    request.add_numbers(number);
  }
  ni::fake::grpc::DoubleAllTheNumsResponse response;
  ::grpc::Status status = service.DoubleAllTheNums(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_GetAStringOfFixedMaximumSize_CallsGetAStringOfFixedMaximumSize)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t sessionId = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  ViChar output_string[256] = "Hello World!";
  EXPECT_CALL(library_wrapper, GetAStringOfFixedMaximumSize(kViSession, _))
      .WillOnce(DoAll(
          ::testing::SetArrayArgument<1>(output_string, output_string + 256),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetAStringOfFixedMaximumSizeRequest request;
  request.mutable_vi()->set_id(sessionId);
  ni::fake::grpc::GetAStringOfFixedMaximumSizeResponse response;
  ::grpc::Status status = service.GetAStringOfFixedMaximumSize(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_STREQ(output_string, response.a_string().c_str());
}

TEST(NiFakeServiceTests, NiFakeService_ImportAttributeConfigurationBuffer_CallsImportAttributeConfigurationBuffer)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t sessionId = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  const ViInt8 char_array[] = {'a', 'b', 'c'};
  ViInt32 expectedSize = 3;
  EXPECT_CALL(library_wrapper, ImportAttributeConfigurationBuffer(kViSession, expectedSize, ElementsMatch(char_array, 3)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  ni::fake::grpc::ImportAttributeConfigurationBufferRequest request;
  request.mutable_vi()->set_id(sessionId);
  for (ViInt8 character : char_array) {
    request.mutable_configuration()->push_back(character);
  }
  ni::fake::grpc::ImportAttributeConfigurationBufferResponse response;
  ::grpc::Status status = service.ImportAttributeConfigurationBuffer(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_MultipleArraysSameSize_CallsMultipleArraysSameSize)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t sessionId = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  ViReal64 doubles[] = {0.2, -2.3, 4.5};
  ViInt32 expectedSize = 3;
  EXPECT_CALL(
      library_wrapper,
      MultipleArraysSameSize(
          kViSession,
          ElementsMatch(doubles, expectedSize),
          ElementsMatch(doubles, expectedSize),
          ElementsMatch(doubles, expectedSize),
          ElementsMatch(doubles, expectedSize),
          expectedSize))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  ni::fake::grpc::MultipleArraysSameSizeRequest request;
  request.mutable_vi()->set_id(sessionId);
  for (ViReal64 num : doubles) {
    request.add_values1(num);
    request.add_values2(num);
    request.add_values3(num);
    request.add_values4(num);
  }
  ni::fake::grpc::MultipleArraysSameSizeResponse response;
  ::grpc::Status status = service.MultipleArraysSameSize(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_ParametersAreMultipleTypes_CallsParametersAreMultipleTypes)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t sessionId = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  ViBoolean aBoolean = true;
  ViInt32 anInt32 = 35;
  ViInt64 anInt64 = 42;
  ni::fake::grpc::Turtle anIntEnum = ni::fake::grpc::Turtle::TURTLE_MICHELANGELO;
  ViReal64 aFloat = 4.2;
  ni::fake::grpc::FloatEnum aFloatEnum = ni::fake::grpc::FloatEnum::FLOAT_ENUM_SIX_POINT_FIVE;
  float expectedFloatEnumValue = 6.5;
  ViInt32 expectedStringSize = 12;
  ViConstString aString = "Hello There!";
  EXPECT_CALL(
      library_wrapper,
      ParametersAreMultipleTypes(
          kViSession,
          aBoolean,
          anInt32,
          anInt64,
          anIntEnum,
          aFloat,
          expectedFloatEnumValue,
          expectedStringSize,
          ElementsMatch(aString, expectedStringSize)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  ni::fake::grpc::ParametersAreMultipleTypesRequest request;
  request.mutable_vi()->set_id(sessionId);
  request.set_a_boolean(aBoolean);
  request.set_an_int32(anInt32);
  request.set_an_int64(anInt64);
  request.set_an_int_enum(anIntEnum);
  request.set_a_float(aFloat);
  request.set_a_float_enum(aFloatEnum);
  request.set_a_string(aString);
  ni::fake::grpc::ParametersAreMultipleTypesResponse response;
  ::grpc::Status status = service.ParametersAreMultipleTypes(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_ReturnANumberAndAString_CallsReturnANumberAndAString)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t sessionId = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  ViInt16 a_number = 42;
  ViChar a_string[256] = "Hello World!";
  EXPECT_CALL(library_wrapper, ReturnANumberAndAString(kViSession, _, _))
      .WillOnce(DoAll(
          SetArgPointee<1>(a_number),
          ::testing::SetArrayArgument<2>(a_string, a_string + 256),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::ReturnANumberAndAStringRequest request;
  request.mutable_vi()->set_id(sessionId);
  ni::fake::grpc::ReturnANumberAndAStringResponse response;
  ::grpc::Status status = service.ReturnANumberAndAString(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(a_number, response.a_number());
  EXPECT_STREQ(a_string, response.a_string().c_str());
}

TEST(NiFakeServiceTests, NiFakeService_WriteWaveform_CallsWriteWaveform)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t sessionId = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  ViReal64 waveforms[] = {53.4, 42, -120.3};
  ViInt32 expectedNumberOfSamples = 3;
  EXPECT_CALL(library_wrapper, WriteWaveform(kViSession, expectedNumberOfSamples, ElementsMatch(waveforms, expectedNumberOfSamples)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  ni::fake::grpc::WriteWaveformRequest request;
  request.mutable_vi()->set_id(sessionId);
  for (ViReal64 waveform : waveforms) {
    request.add_waveform(waveform);
  }
  ni::fake::grpc::WriteWaveformResponse response;
  ::grpc::Status status = service.WriteWaveform(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
