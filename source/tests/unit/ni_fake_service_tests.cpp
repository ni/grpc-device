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
  auto init_lambda = [&] () -> std::tuple<int, uint32_t> {
    return std::make_tuple(0, sessionToStore);
  };
  uint32_t session_id;
  session_repo.add_session("", init_lambda, NULL, session_id);
  return session_id;
}

// Init and Close function tests
TEST(NiFakeServiceTests, NiFakeService_InitWithOptionsSucceeds_CreatesAndRegistersSession)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  ViConstString resourceName = "Dev0", optionString = "Simulate = 1";
  ViBoolean idQuery, resetDevice = true;
  std::string sessionName = "sessionName";
  ViSession vi = kViSession;
  EXPECT_CALL(library, InitWithOptions(Pointee(*resourceName), idQuery, resetDevice, Pointee(*optionString), _))
    .WillOnce(DoAll(SetArgPointee<4>(vi), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::InitWithOptionsRequest request;
  request.set_resource_name(resourceName);
  request.set_id_query(idQuery);
  request.set_reset_device(resetDevice);
  request.set_option_string(optionString);
  request.set_session_name(sessionName);
  ni::fake::grpc::InitWithOptionsResponse response;
  ::grpc::Status status = service.InitWithOptions(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  ni::hardware::grpc::Session session = response.vi();
  EXPECT_EQ(vi, session_repository.access_session(session.id(), ""));
  EXPECT_EQ(vi, session_repository.access_session(0, sessionName));
}

TEST(NiFakeServiceTests, NiFakeService_InitWithOptionsFails_SessionIsNotRegistered)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  std::string message = "Exception!";
  ViSession vi = kViSession;
  EXPECT_CALL(library, InitWithOptions)
    .WillOnce(DoAll(SetArgPointee<4>(vi), Throw(ni::hardware::grpc::internal::LibraryLoadException(message))));

  ::grpc::ServerContext context;
  ni::fake::grpc::InitWithOptionsRequest request;
  ni::fake::grpc::InitWithOptionsResponse response;
  ::grpc::Status status = service.InitWithOptions(&context, &request, &response);

  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
  EXPECT_EQ(message, status.error_message());
  ni::hardware::grpc::Session session = response.vi();
  EXPECT_NE(vi, session_repository.access_session(session.id(), ""));
  EXPECT_EQ(0, session_repository.access_session(session.id(), ""));
}

TEST(NiFakeServiceTests, NiFakeService_InitWithOptionsAndResetServer_SessionIsClosed)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  std::string sessionName = "sessionName";
  ViSession vi = kViSession;
  EXPECT_CALL(library, InitWithOptions)
    .WillOnce(DoAll(SetArgPointee<4>(vi), Return(kDriverSuccess)));
  EXPECT_CALL(library, close(vi))
    .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  ni::fake::grpc::InitWithOptionsRequest request;
  request.set_session_name(sessionName);
  ni::fake::grpc::InitWithOptionsResponse response;
  ::grpc::Status initStatus = service.InitWithOptions(&context, &request, &response);
  EXPECT_TRUE(initStatus.ok());
  ni::hardware::grpc::Session session = response.vi();
  EXPECT_EQ(vi, session_repository.access_session(session.id(), ""));
  EXPECT_EQ(vi, session_repository.access_session(0, sessionName));

  bool resetStatus = session_repository.reset_server();

  EXPECT_TRUE(resetStatus);
  EXPECT_NE(vi, session_repository.access_session(session.id(), ""));
  EXPECT_EQ(0, session_repository.access_session(session.id(), ""));
}

TEST(NiFakeServiceTests, NiFakeService_InitWithOptionsThenClose_SessionIsClosed)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  std::string sessionName = "sessionName";
  ViSession vi = kViSession;
  EXPECT_CALL(library, InitWithOptions)
    .WillOnce(DoAll(SetArgPointee<4>(vi), Return(kDriverSuccess)));
  EXPECT_CALL(library, close(vi))
    .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  ni::fake::grpc::InitWithOptionsRequest initRequest;
  initRequest.set_session_name(sessionName);
  ni::fake::grpc::InitWithOptionsResponse initResponse;
  ::grpc::Status initStatus = service.InitWithOptions(&context, &initRequest, &initResponse);
  EXPECT_TRUE(initStatus.ok());
  ni::hardware::grpc::Session session = initResponse.vi();
  EXPECT_EQ(vi, session_repository.access_session(session.id(), ""));
  EXPECT_EQ(vi, session_repository.access_session(0, sessionName));

  ni::fake::grpc::CloseRequest closeRequest;
  closeRequest.mutable_vi()->set_id(session.id());
  ni::fake::grpc::CloseResponse closeResponse;
  ::grpc::Status closeStatus = service.Close(&context, &closeRequest, &closeResponse);

  EXPECT_TRUE(closeStatus.ok());
  EXPECT_EQ(kDriverSuccess, closeResponse.status());
  EXPECT_NE(kViSession, session_repository.access_session(session.id(), ""));
  EXPECT_EQ(0, session_repository.access_session(session.id(), ""));
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
  ::grpc::Status status = service.GetAttributeViReal64(&context, &request, &response);;

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

}  // namespace unit
}  // namespace tests
}  // namespace ni
