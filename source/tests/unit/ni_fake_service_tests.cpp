#include <grpcpp/impl/grpc_library.h>
#include <gtest/gtest.h>
#include <nifake_mock_library.h>
#include <nifake_service.h>

#include <thread>

#include "hardware/grpc/internal/session_repository.h"

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

ni::hardware::grpc::Session create_session(ni::hardware::grpc::internal::SessionRepository& session_repo, ViSession sessionToStore)
{
  auto init_lambda = [&] () -> std::tuple<int, uint32_t> {
    return std::make_tuple(0, sessionToStore);
  };
  uint32_t session_id;
  session_repo.add_session("", init_lambda, NULL, session_id);
  ni::hardware::grpc::Session session;
  session.set_id(session_id);
  return session;
}

// Error logic tests using GetABoolean
TEST(NiFakeServiceTests, NiFakeService_FunctionNotFound_DoesNotCallFunction)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  ni::hardware::grpc::Session session = create_session(session_repository, kViSession);
  NiFakeMockLibrary library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  std::string message = "Exception!";
  EXPECT_CALL(library_wrapper, GetABoolean)
      .WillOnce(Throw(ni::hardware::grpc::internal::LibraryLoadException(message)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetABooleanRequest request;
  ni::fake::grpc::GetABooleanResponse response;
  ::grpc::Status status = service.GetABoolean(&context, &request, &response);

  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
  EXPECT_EQ(message, status.error_message());
}

TEST(NiFakeServiceTests, NiFakeService_FunctionCallErrors_ResponseDoesNotIncludeReturnValue)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  ni::hardware::grpc::Session session = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  ViBoolean aBoolean = true;
  EXPECT_CALL(library_wrapper, GetABoolean(kViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(aBoolean), Return(kDriverFailure)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetABooleanRequest request;
  request.set_allocated_vi(&session);
  ni::fake::grpc::GetABooleanResponse response;
  ::grpc::Status status = service.GetABoolean(&context, &request, &response);
  request.release_vi();

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverFailure, response.status());
  EXPECT_NE(aBoolean, response.a_boolean());
}

TEST(NiFakeServiceTests, NiFakeService_GetABoolean_CallsGetABoolean)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  ni::hardware::grpc::Session session = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  ViBoolean aBoolean = true;
  EXPECT_CALL(library_wrapper, GetABoolean(kViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(aBoolean), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetABooleanRequest request;
  request.set_allocated_vi(&session);
  ni::fake::grpc::GetABooleanResponse response;
  ::grpc::Status status = service.GetABoolean(&context, &request, &response);
  request.release_vi();

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(aBoolean, response.a_boolean());
}

// Individual Function Tests for functions without enums or arrays
TEST(NiFakeServiceTests, NiFakeService_Abort_CallsAbort)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  ni::hardware::grpc::Session session = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  EXPECT_CALL(library_wrapper, Abort(kViSession))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  ni::fake::grpc::AbortRequest request;
  request.set_allocated_vi(&session);
  ni::fake::grpc::AbortResponse response;
  ::grpc::Status status = service.Abort(&context, &request, &response);
  request.release_vi();

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_GetANumber_CallsGetANumber)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  ni::hardware::grpc::Session session = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  ViInt16 aNumber = 15;
  EXPECT_CALL(library_wrapper, GetANumber(kViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(aNumber), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetANumberRequest request;
  request.set_allocated_vi(&session);
  ni::fake::grpc::GetANumberResponse response;
  ::grpc::Status status = service.GetANumber(&context, &request, &response);
  request.release_vi();

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(aNumber, response.a_number());
}

TEST(NiFakeServiceTests, NiFakeService_GetArraySizeForPythonCode_CallsGetArraySizeForPythonCode)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  ni::hardware::grpc::Session session = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  ViInt32 arraySize = 1000;
  EXPECT_CALL(library_wrapper, GetArraySizeForPythonCode(kViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(arraySize), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetArraySizeForPythonCodeRequest request;
  request.set_allocated_vi(&session);
  ni::fake::grpc::GetArraySizeForPythonCodeResponse response;
  ::grpc::Status status = service.GetArraySizeForPythonCode(&context, &request, &response);
  request.release_vi();

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(arraySize, response.size_out());
}

TEST(NiFakeServiceTests, NiFakeService_GetAttributeViBoolean_CallsGetAttributeViBoolean)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  ni::hardware::grpc::Session session = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  ni::fake::grpc::NiFakeAttributes attributeId = ni::fake::grpc::NIFAKE_READ_WRITE_BOOL;
  ViBoolean attributeValue = true;
  EXPECT_CALL(library_wrapper, GetAttributeViBoolean(kViSession, Pointee(*kChannelName), attributeId, _))
      .WillOnce(DoAll(SetArgPointee<3>(attributeValue), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetAttributeViBooleanRequest request;
  request.set_allocated_vi(&session);
  request.set_channel_name(kChannelName);
  request.set_attribute_id(attributeId);
  ni::fake::grpc::GetAttributeViBooleanResponse response;
  ::grpc::Status status = service.GetAttributeViBoolean(&context, &request, &response);
  request.release_vi();

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(attributeValue, response.attribute_value());
}

TEST(NiFakeServiceTests, NiFakeService_GetAttributeViInt32_CallsGetAttributeViInt32)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  ni::hardware::grpc::Session session = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  ni::fake::grpc::NiFakeAttributes attributeId = ni::fake::grpc::NIFAKE_READ_WRITE_INTEGER;
  ViInt32 attributeValue = 12345;
  EXPECT_CALL(library_wrapper, GetAttributeViInt32(kViSession, Pointee(*kChannelName), attributeId, _))
      .WillOnce(DoAll(SetArgPointee<3>(attributeValue), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetAttributeViInt32Request request;
  request.set_allocated_vi(&session);
  request.set_channel_name(kChannelName);
  request.set_attribute_id(attributeId);
  ni::fake::grpc::GetAttributeViInt32Response response;
  ::grpc::Status status = service.GetAttributeViInt32(&context, &request, &response);
  request.release_vi();

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(attributeValue, response.attribute_value());
}

TEST(NiFakeServiceTests, NiFakeService_GetAttributeViInt64_CallsGetAttributeViInt64)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  ni::hardware::grpc::Session session = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  ni::fake::grpc::NiFakeAttributes attributeId = ni::fake::grpc::NIFAKE_READ_WRITE_INT64;
  ViInt64 attributeValue = -12345;
  EXPECT_CALL(library_wrapper, GetAttributeViInt64(kViSession, Pointee(*kChannelName), attributeId, _))
      .WillOnce(DoAll(SetArgPointee<3>(attributeValue), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetAttributeViInt64Request request;
  request.set_allocated_vi(&session);
  request.set_channel_name(kChannelName);
  request.set_attribute_id(attributeId);
  ni::fake::grpc::GetAttributeViInt64Response response;
  ::grpc::Status status = service.GetAttributeViInt64(&context, &request, &response);
  request.release_vi();

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(attributeValue, response.attribute_value());
}

TEST(NiFakeServiceTests, NiFakeService_GetAttributeViReal64_CallsGetAttributeViReal64)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  ni::hardware::grpc::Session session = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  ni::fake::grpc::NiFakeAttributes attributeId = ni::fake::grpc::NIFAKE_READ_WRITE_DOUBLE;
  ViReal64 attributeValue = 12.345;
  EXPECT_CALL(library_wrapper, GetAttributeViReal64(kViSession, Pointee(*kChannelName), attributeId, _))
      .WillOnce(DoAll(SetArgPointee<3>(attributeValue), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetAttributeViReal64Request request;
  request.set_allocated_vi(&session);
  request.set_channel_name(kChannelName);
  request.set_attribute_id(attributeId);
  ni::fake::grpc::GetAttributeViReal64Response response;
  ::grpc::Status status = service.GetAttributeViReal64(&context, &request, &response);
  request.release_vi();

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(attributeValue, response.attribute_value());
}

TEST(NiFakeServiceTests, NiFakeService_GetCalDateAndTime_CallsGetCalDateAndTime)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  ni::hardware::grpc::Session session = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  ViInt32 calType = 0;
  ViInt32 month = 1, day = 17, year = 2021, hour = 0, minute = 0;
  EXPECT_CALL(library_wrapper, GetCalDateAndTime(kViSession, calType, _, _, _, _, _))
      .WillOnce(DoAll(
          SetArgPointee<2>(month),
          SetArgPointee<3>(day),
          SetArgPointee<4>(year),
          SetArgPointee<5>(hour),
          SetArgPointee<6>(minute),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetCalDateAndTimeRequest request;
  request.set_allocated_vi(&session);
  request.set_cal_type(calType);
  ni::fake::grpc::GetCalDateAndTimeResponse response;
  ::grpc::Status status = service.GetCalDateAndTime(&context, &request, &response);
  request.release_vi();

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
  ni::hardware::grpc::Session session = create_session(session_repository, kViSession);
  NiceMock<NiFakeMockLibrary> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  ni::fake::grpc::NiFakeAttributes attributeId = ni::fake::grpc::NIFAKE_READ_WRITE_DOUBLE;
  ViInt32 months = 24;
  EXPECT_CALL(library_wrapper, GetCalInterval(kViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(months), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetCalIntervalRequest request;
  request.set_allocated_vi(&session);
  ni::fake::grpc::GetCalIntervalResponse response;
  ::grpc::Status status = service.GetCalInterval(&context, &request, &response);
  request.release_vi();

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(months, response.months());
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
