#include <grpcpp/impl/grpc_library.h>
#include <gtest/gtest.h>
#include <nifake/nifake_mock_library.h>
#include <nifake/nifake_service.h>
#include <server/session_repository.h>

#include <iostream>

// fixes seg faults caused by https://github.com/grpc/grpc/issues/14633
static grpc::internal::GrpcLibraryInitializer g_gli_initializer;

namespace ni {
namespace tests {
namespace unit {

using ::testing::_;
using ::testing::AllOf;
using ::testing::Args;
using ::testing::DoAll;
using ::testing::ElementsAreArray;
using ::testing::Pointee;
using ::testing::Return;
using ::testing::SetArgPointee;
using ::testing::SetArrayArgument;
using ::testing::Throw;

const std::uint32_t kTestViSession = 12345678;
const std::uint32_t kDriverSuccess = 0;
const std::uint32_t kDriverFailure = 1;
const char* kTestChannelName = "channel";

std::uint32_t create_session(nidevice_grpc::SessionRepository& session_repo, ViSession sessionToStore)
{
  auto init_lambda = [&]() -> std::tuple<int, uint32_t> {
    return std::make_tuple(0, sessionToStore);
  };
  uint32_t session_id;
  session_repo.add_session("", init_lambda, NULL, session_id);
  return session_id;
}

// Init and Close function tests
TEST(NiFakeServiceTests, NiFakeService_InitWithOptionsSucceeds_CreatesAndStoresSession)
{
  nidevice_grpc::SessionRepository session_repository;
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  const char* resource_name = "Dev0";
  const char* option_string = "Simulate = 1";
  bool id_query = false, reset_device = true;
  const char* session_name = "sessionName";
  EXPECT_CALL(library, InitWithOptions(Pointee(*resource_name), id_query, reset_device, Pointee(*option_string), _))
      .WillOnce(DoAll(SetArgPointee<4>(kTestViSession), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::InitWithOptionsRequest request;
  request.set_resource_name(resource_name);
  request.set_id_query(id_query);
  request.set_reset_device(reset_device);
  request.set_option_string(option_string);
  request.set_session_name(session_name);
  nifake_grpc::InitWithOptionsResponse response;
  ::grpc::Status status = service.InitWithOptions(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  nidevice_grpc::Session session = response.vi();
  EXPECT_EQ(kTestViSession, session_repository.access_session(session.id(), ""));
  EXPECT_EQ(kTestViSession, session_repository.access_session(0, session_name));
}

TEST(NiFakeServiceTests, NiFakeService_InitWithOptionsFails_NoSessionIsStored)
{
  nidevice_grpc::SessionRepository session_repository;
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  const char* message = "Exception!";
  EXPECT_CALL(library, InitWithOptions)
      .WillOnce(DoAll(SetArgPointee<4>(kTestViSession), Throw(nidevice_grpc::LibraryLoadException(message))));

  ::grpc::ServerContext context;
  nifake_grpc::InitWithOptionsRequest request;
  nifake_grpc::InitWithOptionsResponse response;
  ::grpc::Status status = service.InitWithOptions(&context, &request, &response);

  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
  EXPECT_EQ(message, status.error_message());
  nidevice_grpc::Session session = response.vi();
  EXPECT_NE(kTestViSession, session_repository.access_session(session.id(), ""));
  EXPECT_EQ(0, session_repository.access_session(session.id(), ""));
}

TEST(NiFakeServiceTests, NiFakeService_InitWithOptionsAndResetServer_SessionIsClosed)
{
  nidevice_grpc::SessionRepository session_repository;
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  const char* session_name = "sessionName";
  EXPECT_CALL(library, InitWithOptions)
      .WillOnce(DoAll(SetArgPointee<4>(kTestViSession), Return(kDriverSuccess)));
  EXPECT_CALL(library, close(kTestViSession))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::InitWithOptionsRequest request;
  request.set_session_name(session_name);
  nifake_grpc::InitWithOptionsResponse response;
  ::grpc::Status init_status = service.InitWithOptions(&context, &request, &response);
  EXPECT_TRUE(init_status.ok());
  nidevice_grpc::Session session = response.vi();
  EXPECT_EQ(kTestViSession, session_repository.access_session(session.id(), ""));
  EXPECT_EQ(kTestViSession, session_repository.access_session(0, session_name));
  bool reset_status = session_repository.reset_server();

  EXPECT_TRUE(reset_status);
  EXPECT_NE(kTestViSession, session_repository.access_session(session.id(), ""));
  EXPECT_EQ(0, session_repository.access_session(session.id(), ""));
}

TEST(NiFakeServiceTests, NiFakeService_InitExtCalAndResetServer_SessionIsClosed)
{
  nidevice_grpc::SessionRepository session_repository;
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  const char* session_name = "sessionName";
  EXPECT_CALL(library, InitExtCal)
      .WillOnce(DoAll(SetArgPointee<2>(kTestViSession), Return(kDriverSuccess)));
  EXPECT_CALL(library, CloseExtCal(kTestViSession, 0))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::InitExtCalRequest request;
  request.set_session_name(session_name);
  nifake_grpc::InitExtCalResponse response;
  ::grpc::Status init_status = service.InitExtCal(&context, &request, &response);
  EXPECT_TRUE(init_status.ok());
  nidevice_grpc::Session session = response.vi();
  EXPECT_EQ(kTestViSession, session_repository.access_session(session.id(), ""));
  EXPECT_EQ(kTestViSession, session_repository.access_session(0, session_name));
  bool reset_status = session_repository.reset_server();

  EXPECT_TRUE(reset_status);
  EXPECT_EQ(0, session_repository.access_session(session.id(), ""));
  EXPECT_EQ(0, session_repository.access_session(0, session_name));
}

TEST(NiFakeServiceTests, NiFakeService_InitWithOptionsThenClose_SessionIsClosed)
{
  nidevice_grpc::SessionRepository session_repository;
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  std::string session_name = "sessionName";
  EXPECT_CALL(library, InitWithOptions)
      .WillOnce(DoAll(SetArgPointee<4>(kTestViSession), Return(kDriverSuccess)));
  EXPECT_CALL(library, close(kTestViSession))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::InitWithOptionsRequest init_request;
  init_request.set_session_name(session_name);
  nifake_grpc::InitWithOptionsResponse init_response;
  ::grpc::Status init_status = service.InitWithOptions(&context, &init_request, &init_response);
  EXPECT_TRUE(init_status.ok());
  nidevice_grpc::Session session = init_response.vi();
  EXPECT_EQ(kTestViSession, session_repository.access_session(session.id(), ""));
  EXPECT_EQ(kTestViSession, session_repository.access_session(0, session_name));
  nifake_grpc::CloseRequest close_request;
  close_request.mutable_vi()->set_id(session.id());
  nifake_grpc::CloseResponse close_response;
  ::grpc::Status close_status = service.Close(&context, &close_request, &close_response);

  EXPECT_TRUE(close_status.ok());
  EXPECT_EQ(kDriverSuccess, close_response.status());
  EXPECT_NE(kTestViSession, session_repository.access_session(session.id(), ""));
  EXPECT_EQ(0, session_repository.access_session(session.id(), ""));
}

TEST(NiFakeServiceTests, NiFakeService_InitExtCalThenCloseExtCal_SessionIsClosed)
{
  nidevice_grpc::SessionRepository session_repository;
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  std::string session_name = "sessionName";
  ViInt32 action = 1;
  EXPECT_CALL(library, InitExtCal)
      .WillOnce(DoAll(SetArgPointee<2>(kTestViSession), Return(kDriverSuccess)));
  EXPECT_CALL(library, CloseExtCal(kTestViSession, action))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::InitExtCalRequest init_request;
  init_request.set_session_name(session_name);
  nifake_grpc::InitExtCalResponse init_response;
  ::grpc::Status init_status = service.InitExtCal(&context, &init_request, &init_response);
  EXPECT_TRUE(init_status.ok());
  nidevice_grpc::Session session = init_response.vi();
  EXPECT_EQ(kTestViSession, session_repository.access_session(session.id(), ""));
  EXPECT_EQ(kTestViSession, session_repository.access_session(0, session_name));
  nifake_grpc::CloseExtCalRequest close_request;
  close_request.mutable_vi()->set_id(session.id());
  close_request.set_action(action);
  nifake_grpc::CloseExtCalResponse close_response;
  ::grpc::Status close_status = service.CloseExtCal(&context, &close_request, &close_response);

  EXPECT_TRUE(close_status.ok());
  EXPECT_EQ(kDriverSuccess, close_response.status());
  EXPECT_EQ(0, session_repository.access_session(session.id(), ""));
  EXPECT_EQ(0, session_repository.access_session(0, session_name));
}

// Error logic tests using GetABoolean
TEST(NiFakeServiceTests, NiFakeService_FunctionNotFound_DoesNotCallFunction)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  const char* message = "Exception!";
  EXPECT_CALL(library, GetABoolean)
      .WillOnce(Throw(nidevice_grpc::LibraryLoadException(message)));

  ::grpc::ServerContext context;
  nifake_grpc::GetABooleanRequest request;
  request.mutable_vi()->set_id(session_id);
  nifake_grpc::GetABooleanResponse response;
  ::grpc::Status status = service.GetABoolean(&context, &request, &response);

  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
  EXPECT_EQ(message, status.error_message());
}

TEST(NiFakeServiceTests, NiFakeService_FunctionCallErrors_ResponseValuesNotSet)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  bool a_boolean = true;
  EXPECT_CALL(library, GetABoolean(kTestViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(a_boolean), Return(kDriverFailure)));

  ::grpc::ServerContext context;
  nifake_grpc::GetABooleanRequest request;
  request.mutable_vi()->set_id(session_id);
  nifake_grpc::GetABooleanResponse response;
  ::grpc::Status status = service.GetABoolean(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverFailure, response.status());
  EXPECT_NE(a_boolean, response.a_boolean());
}

TEST(NiFakeServiceTests, NiFakeService_GetABoolean_CallsGetABoolean)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  bool a_boolean = true;
  EXPECT_CALL(library, GetABoolean(kTestViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(a_boolean), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetABooleanRequest request;
  request.mutable_vi()->set_id(session_id);
  nifake_grpc::GetABooleanResponse response;
  ::grpc::Status status = service.GetABoolean(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(a_boolean, response.a_boolean());
}

// Simple Input and Output Type Function Tests
TEST(NiFakeServiceTests, NiFakeService_Abort_CallsAbort)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  EXPECT_CALL(library, Abort(kTestViSession))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::AbortRequest request;
  request.mutable_vi()->set_id(session_id);
  nifake_grpc::AbortResponse response;
  ::grpc::Status status = service.Abort(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_GetANumber_CallsGetANumber)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  std::int16_t a_number = 15;
  EXPECT_CALL(library, GetANumber(kTestViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(a_number), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetANumberRequest request;
  request.mutable_vi()->set_id(session_id);
  nifake_grpc::GetANumberResponse response;
  ::grpc::Status status = service.GetANumber(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(a_number, response.a_number());
}

TEST(NiFakeServiceTests, NiFakeService_GetArraySizeForCustomCode_CallsGetArraySizeForCustomCode)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  std::int32_t array_size = 1000;
  EXPECT_CALL(library, GetArraySizeForCustomCode(kTestViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(array_size), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetArraySizeForCustomCodeRequest request;
  request.mutable_vi()->set_id(session_id);
  nifake_grpc::GetArraySizeForCustomCodeResponse response;
  ::grpc::Status status = service.GetArraySizeForCustomCode(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(array_size, response.size_out());
}

TEST(NiFakeServiceTests, NiFakeService_GetAttributeViBoolean_CallsGetAttributeViBoolean)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  nifake_grpc::NiFakeAttributes attribute_id = nifake_grpc::NIFAKE_ATTRIBUTE_READ_WRITE_BOOL;
  bool attribute_value = true;
  EXPECT_CALL(library, GetAttributeViBoolean(kTestViSession, Pointee(*kTestChannelName), attribute_id, _))
      .WillOnce(DoAll(SetArgPointee<3>(attribute_value), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAttributeViBooleanRequest request;
  request.mutable_vi()->set_id(session_id);
  request.set_channel_name(kTestChannelName);
  request.set_attribute_id(attribute_id);
  nifake_grpc::GetAttributeViBooleanResponse response;
  ::grpc::Status status = service.GetAttributeViBoolean(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(attribute_value, response.attribute_value());
}

TEST(NiFakeServiceTests, NiFakeService_GetAttributeViInt32_CallsGetAttributeViInt32)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  nifake_grpc::NiFakeAttributes attribute_id = nifake_grpc::NIFAKE_ATTRIBUTE_READ_WRITE_INTEGER;
  std::int32_t attribute_value = 12345;
  EXPECT_CALL(library, GetAttributeViInt32(kTestViSession, Pointee(*kTestChannelName), attribute_id, _))
      .WillOnce(DoAll(SetArgPointee<3>(attribute_value), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAttributeViInt32Request request;
  request.mutable_vi()->set_id(session_id);
  request.set_channel_name(kTestChannelName);
  request.set_attribute_id(attribute_id);
  nifake_grpc::GetAttributeViInt32Response response;
  ::grpc::Status status = service.GetAttributeViInt32(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(attribute_value, response.attribute_value());
}

TEST(NiFakeServiceTests, NiFakeService_GetAttributeViInt64_CallsGetAttributeViInt64)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  nifake_grpc::NiFakeAttributes attribute_id = nifake_grpc::NIFAKE_ATTRIBUTE_READ_WRITE_INT64;
  std::int64_t attribute_value = -12345;
  EXPECT_CALL(library, GetAttributeViInt64(kTestViSession, Pointee(*kTestChannelName), attribute_id, _))
      .WillOnce(DoAll(SetArgPointee<3>(attribute_value), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAttributeViInt64Request request;
  request.mutable_vi()->set_id(session_id);
  request.set_channel_name(kTestChannelName);
  request.set_attribute_id(attribute_id);
  nifake_grpc::GetAttributeViInt64Response response;
  ::grpc::Status status = service.GetAttributeViInt64(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(attribute_value, response.attribute_value());
}

TEST(NiFakeServiceTests, NiFakeService_GetAttributeViReal64_CallsGetAttributeViReal64)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  nifake_grpc::NiFakeAttributes attribute_id = nifake_grpc::NIFAKE_ATTRIBUTE_READ_WRITE_DOUBLE;
  double attribute_value = 12.345;
  EXPECT_CALL(library, GetAttributeViReal64(kTestViSession, Pointee(*kTestChannelName), attribute_id, _))
      .WillOnce(DoAll(SetArgPointee<3>(attribute_value), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAttributeViReal64Request request;
  request.mutable_vi()->set_id(session_id);
  request.set_channel_name(kTestChannelName);
  request.set_attribute_id(attribute_id);
  nifake_grpc::GetAttributeViReal64Response response;
  ::grpc::Status status = service.GetAttributeViReal64(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(attribute_value, response.attribute_value());
}

TEST(NiFakeServiceTests, NiFakeService_GetCalDateAndTime_CallsGetCalDateAndTime)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  std::int32_t cal_type = 0;
  std::int32_t month = 1, day = 17, year = 2021, hour = 0, minute = 0;
  EXPECT_CALL(library, GetCalDateAndTime(kTestViSession, cal_type, _, _, _, _, _))
      .WillOnce(DoAll(
          SetArgPointee<2>(month),
          SetArgPointee<3>(day),
          SetArgPointee<4>(year),
          SetArgPointee<5>(hour),
          SetArgPointee<6>(minute),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetCalDateAndTimeRequest request;
  request.mutable_vi()->set_id(session_id);
  request.set_cal_type(cal_type);
  nifake_grpc::GetCalDateAndTimeResponse response;
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
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  nifake_grpc::NiFakeAttributes attribute_id = nifake_grpc::NIFAKE_ATTRIBUTE_READ_WRITE_DOUBLE;
  std::int32_t months = 24;
  EXPECT_CALL(library, GetCalInterval(kTestViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(months), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetCalIntervalRequest request;
  request.mutable_vi()->set_id(session_id);
  nifake_grpc::GetCalIntervalResponse response;
  ::grpc::Status status = service.GetCalInterval(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(months, response.months());
}

TEST(NiFakeServiceTests, NiFakeService_GetEnumValue_CallsGetEnumValue)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  std::int32_t a_quantity = 123;
  std::int16_t a_turtle = NIFAKE_VAL_LEONARDO;
  EXPECT_CALL(library, GetEnumValue(kTestViSession, _, _))
      .WillOnce(DoAll(SetArgPointee<1>(a_quantity), SetArgPointee<2>(a_turtle), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetEnumValueRequest request;
  request.mutable_vi()->set_id(session_id);
  nifake_grpc::GetEnumValueResponse response;
  ::grpc::Status status = service.GetEnumValue(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(a_quantity, response.a_quantity());
  EXPECT_EQ(a_turtle, response.a_turtle());
  EXPECT_EQ(a_turtle, response.a_turtle_raw());
}

TEST(NiFakeServiceTests, NiFakeService_GetEnumValueNotInEnum_CallsGetEnumValue)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  std::int32_t a_quantity = 123;
  std::int16_t a_turtle = 5;
  EXPECT_CALL(library, GetEnumValue(kTestViSession, _, _))
      .WillOnce(DoAll(SetArgPointee<1>(a_quantity), SetArgPointee<2>(a_turtle), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetEnumValueRequest request;
  request.mutable_vi()->set_id(session_id);
  nifake_grpc::GetEnumValueResponse response;
  ::grpc::Status status = service.GetEnumValue(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(a_quantity, response.a_quantity());
  EXPECT_EQ(a_turtle, response.a_turtle());
  EXPECT_EQ(a_turtle, response.a_turtle_raw());
}

// Array input and output tests
TEST(NiFakeServiceTests, NiFakeService_AcceptListOfDurationsInSeconds_CallsAcceptListOfDurationsInSeconds)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  const double delays[] = {1, 2, 3, 4, 5};
  std::int32_t expected_size = 5;
  EXPECT_CALL(library, AcceptListOfDurationsInSeconds(kTestViSession, expected_size, _))
      .With(Args<2, 1>(ElementsAreArray(delays)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::AcceptListOfDurationsInSecondsRequest request;
  request.mutable_vi()->set_id(session_id);
  for (double delay : delays) {
    request.add_delays(delay);
  }
  nifake_grpc::AcceptListOfDurationsInSecondsResponse response;
  ::grpc::Status status = service.AcceptListOfDurationsInSeconds(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_BoolArrayOutputFunction_CallsBoolArrayOutputFunction)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  ViInt32 number_of_elements = 3;
  ViBoolean an_array[] = {VI_FALSE, VI_TRUE, VI_TRUE};
  EXPECT_CALL(library, BoolArrayOutputFunction(kTestViSession, number_of_elements, _))
      .WillOnce(DoAll(
          SetArrayArgument<2>(an_array, an_array + number_of_elements),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::BoolArrayOutputFunctionRequest request;
  request.mutable_vi()->set_id(session_id);
  request.set_number_of_elements(number_of_elements);
  nifake_grpc::BoolArrayOutputFunctionResponse response;
  ::grpc::Status status = service.BoolArrayOutputFunction(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  bool expected_response_booleans[] = {false, true, true};
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(response.an_array_size(), number_of_elements);
  EXPECT_THAT(response.an_array(), ElementsAreArray(expected_response_booleans, number_of_elements));
}

TEST(NiFakeServiceTests, NiFakeService_BoolArrayInputFunction_CallsBoolArrayInputFunction)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  ViInt32 number_of_elements = 3;
  ViBoolean expected_array[] = { VI_FALSE, VI_TRUE, VI_TRUE };
  EXPECT_CALL(library, BoolArrayInputFunction(kTestViSession, number_of_elements, _))
    .With(Args<2, 1>(ElementsAreArray(expected_array)))
    .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::BoolArrayInputFunctionRequest request;
  request.mutable_vi()->set_id(session_id);
  request.set_number_of_elements(number_of_elements);
  request.add_an_array(false);
  request.add_an_array(true);
  request.add_an_array(true);
  nifake_grpc::BoolArrayInputFunctionResponse response;
  ::grpc::Status status = service.BoolArrayInputFunction(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_DoubleAllTheNums_CallsDoubleAllTheNums)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  const double numbers[] = {1, 2, 3, 4, 5};
  std::int32_t expected_size = 5;
  EXPECT_CALL(library, DoubleAllTheNums(kTestViSession, expected_size, _))
      .With(Args<2, 1>(ElementsAreArray(numbers)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::DoubleAllTheNumsRequest request;
  request.mutable_vi()->set_id(session_id);
  for (double number : numbers) {
    request.add_numbers(number);
  }
  nifake_grpc::DoubleAllTheNumsResponse response;
  ::grpc::Status status = service.DoubleAllTheNums(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_GetAStringOfFixedMaximumSize_CallsGetAStringOfFixedMaximumSize)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  char output_string[256] = "Hello World!";
  EXPECT_CALL(library, GetAStringOfFixedMaximumSize(kTestViSession, _))
      .WillOnce(DoAll(
          SetArrayArgument<1>(output_string, output_string + 256),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAStringOfFixedMaximumSizeRequest request;
  request.mutable_vi()->set_id(session_id);
  nifake_grpc::GetAStringOfFixedMaximumSizeResponse response;
  ::grpc::Status status = service.GetAStringOfFixedMaximumSize(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_STREQ(output_string, response.a_string().c_str());
}

TEST(NiFakeServiceTests, NiFakeService_GetCustomTypeArray_CallsGetCustomTypeArray)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  ViInt32 number_of_elements = 3;
  std::vector<CustomStruct> cs(number_of_elements);
  EXPECT_CALL(library, GetCustomTypeArray(kTestViSession, number_of_elements, _))
      .WillOnce(DoAll(SetArgPointee<2>(*(cs.data())), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetCustomTypeArrayRequest request;
  request.mutable_vi()->set_id(session_id);
  request.set_number_of_elements(3);
  nifake_grpc::GetCustomTypeArrayResponse response;
  ::grpc::Status status = service.GetCustomTypeArray(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(response.cs_size(), cs.size());
}

TEST(NiFakeServiceTests, NiFakeService_ImportAttributeConfigurationBuffer_CallsImportAttributeConfigurationBuffer)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  const std::int8_t char_array[] = {'a', 'b', 'c'};
  std::int32_t expected_size = 3;
  EXPECT_CALL(library, ImportAttributeConfigurationBuffer(kTestViSession, expected_size, _))
      .With(Args<2, 1>(ElementsAreArray(char_array)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::ImportAttributeConfigurationBufferRequest request;
  request.mutable_vi()->set_id(session_id);
  for (std::int8_t character : char_array) {
    request.mutable_configuration()->push_back(character);
  }
  nifake_grpc::ImportAttributeConfigurationBufferResponse response;
  ::grpc::Status status = service.ImportAttributeConfigurationBuffer(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_MultipleArraysSameSize_CallsMultipleArraysSameSize)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  const double doubles[] = {0.2, -2.3, 4.5};
  std::int32_t expected_size = 3;
  EXPECT_CALL(library, MultipleArraysSameSize(kTestViSession, _, _, _, _, expected_size))
      .With(AllOf(
          Args<1, 5>(ElementsAreArray(doubles, expected_size)),
          Args<2, 5>(ElementsAreArray(doubles, expected_size)),
          Args<3, 5>(ElementsAreArray(doubles, expected_size)),
          Args<4, 5>(ElementsAreArray(doubles, expected_size))))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::MultipleArraysSameSizeRequest request;
  request.mutable_vi()->set_id(session_id);
  for (double num : doubles) {
    request.add_values1(num);
    request.add_values2(num);
    request.add_values3(num);
    request.add_values4(num);
  }
  nifake_grpc::MultipleArraysSameSizeResponse response;
  ::grpc::Status status = service.MultipleArraysSameSize(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_ParametersAreMultipleTypes_CallsParametersAreMultipleTypes)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  bool a_boolean = true;
  std::int32_t an_int_32 = 35;
  std::int64_t an_int_64 = 42;
  nifake_grpc::Turtle an_int_enum = nifake_grpc::Turtle::TURTLE_MICHELANGELO;
  double a_float = 4.2;
  nifake_grpc::FloatEnum a_float_enum = nifake_grpc::FloatEnum::FLOAT_ENUM_SIX_POINT_FIVE;
  float expected_float_enum_value = 6.5;
  std::int32_t expected_string_size = 12;
  char a_string[] = "Hello There!";
  EXPECT_CALL(
      library,
      ParametersAreMultipleTypes(
          kTestViSession,
          a_boolean,
          an_int_32,
          an_int_64,
          an_int_enum,
          a_float,
          expected_float_enum_value,
          expected_string_size,
          _))
      .With(Args<8, 7>(ElementsAreArray(a_string, expected_string_size)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::ParametersAreMultipleTypesRequest request;
  request.mutable_vi()->set_id(session_id);
  request.set_a_boolean(a_boolean);
  request.set_an_int32(an_int_32);
  request.set_an_int64(an_int_64);
  request.set_an_int_enum(an_int_enum);
  request.set_a_float(a_float);
  request.set_a_float_enum(a_float_enum);
  request.set_a_string(a_string);
  nifake_grpc::ParametersAreMultipleTypesResponse response;
  ::grpc::Status status = service.ParametersAreMultipleTypes(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_ParametersAreMultipleTypesWithRawValues_CallsParametersAreMultipleTypes)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  bool a_boolean = true;
  std::int32_t an_int_32 = 35;
  std::int64_t an_int_64 = 42;
  nifake_grpc::Turtle an_int_enum = nifake_grpc::Turtle::TURTLE_MICHELANGELO;
  double a_float = 4.2;
  float expected_float_enum_value = 6.5;
  std::int32_t expected_string_size = 12;
  char a_string[] = "Hello There!";
  EXPECT_CALL(
      library,
      ParametersAreMultipleTypes(
          kTestViSession,
          a_boolean,
          an_int_32,
          an_int_64,
          an_int_enum,
          a_float,
          expected_float_enum_value,
          expected_string_size,
          _))
      .With(Args<8, 7>(ElementsAreArray(a_string, expected_string_size)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::ParametersAreMultipleTypesRequest request;
  request.mutable_vi()->set_id(session_id);
  request.set_a_boolean(a_boolean);
  request.set_an_int32(an_int_32);
  request.set_an_int64(an_int_64);
  request.set_an_int_enum_raw(an_int_enum);
  request.set_a_float(a_float);
  request.set_a_float_enum_raw(expected_float_enum_value);
  request.set_a_string(a_string);
  nifake_grpc::ParametersAreMultipleTypesResponse response;
  ::grpc::Status status = service.ParametersAreMultipleTypes(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_ParametersAreMultipleTypesWithRawValuesNotInEnum_CallsParametersAreMultipleTypes)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  bool a_boolean = true;
  std::int32_t an_int_32 = 35;
  std::int64_t an_int_64 = 42;
  std::int32_t expected_int_enum_value = 5;  // value not in enum
  double a_float = 4.2;
  float expected_float_enum_value = 8.5;  // value not in enum
  std::int32_t expected_string_size = 12;
  char a_string[] = "Hello There!";
  EXPECT_CALL(
      library,
      ParametersAreMultipleTypes(
          kTestViSession,
          a_boolean,
          an_int_32,
          an_int_64,
          expected_int_enum_value,
          a_float,
          expected_float_enum_value,
          expected_string_size,
          _))
      .With(Args<8, 7>(ElementsAreArray(a_string, expected_string_size)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::ParametersAreMultipleTypesRequest request;
  request.mutable_vi()->set_id(session_id);
  request.set_a_boolean(a_boolean);
  request.set_an_int32(an_int_32);
  request.set_an_int64(an_int_64);
  request.set_an_int_enum_raw(expected_int_enum_value);
  request.set_a_float(a_float);
  request.set_a_float_enum_raw(expected_float_enum_value);
  request.set_a_string(a_string);
  nifake_grpc::ParametersAreMultipleTypesResponse response;
  ::grpc::Status status = service.ParametersAreMultipleTypes(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_ReturnANumberAndAString_CallsReturnANumberAndAString)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  std::int16_t a_number = 42;
  char a_string[256] = "Hello World!";
  EXPECT_CALL(library, ReturnANumberAndAString(kTestViSession, _, _))
      .WillOnce(DoAll(
          SetArgPointee<1>(a_number),
          SetArrayArgument<2>(a_string, a_string + 256),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::ReturnANumberAndAStringRequest request;
  request.mutable_vi()->set_id(session_id);
  nifake_grpc::ReturnANumberAndAStringResponse response;
  ::grpc::Status status = service.ReturnANumberAndAString(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(a_number, response.a_number());
  EXPECT_STREQ(a_string, response.a_string().c_str());
}

TEST(NiFakeServiceTests, NiFakeService_ReturnListOfDurationsInSeconds_CallsReturnListOfDurationsInSeconds)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  ViInt32 number_of_elements = 3;
  ViReal64 timedeltas[] = {1.0, 2, -3.0};
  EXPECT_CALL(library, ReturnListOfDurationsInSeconds(kTestViSession, number_of_elements, _))
      .WillOnce(DoAll(
          SetArrayArgument<2>(timedeltas, timedeltas + number_of_elements),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::ReturnListOfDurationsInSecondsRequest request;
  request.mutable_vi()->set_id(session_id);
  request.set_number_of_elements(3);
  nifake_grpc::ReturnListOfDurationsInSecondsResponse response;
  ::grpc::Status status = service.ReturnListOfDurationsInSeconds(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  double expected_response_doubles[] = {1.0, 2, -3.0};
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(response.timedeltas_size(), number_of_elements);
  EXPECT_THAT(response.timedeltas(), ElementsAreArray(expected_response_doubles, number_of_elements));
}

TEST(NiFakeServiceTests, NiFakeService_ReturnMultipleTypes_CallsReturnMultipleTypes)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  ViInt32 array_size = 3;
  ViBoolean a_boolean = false;
  ViInt32 an_int32 = 4;
  ViInt64 an_int64 = 5;
  ViInt16 an_int_enum = nifake_grpc::Turtle::TURTLE_MICHELANGELO;
  ViReal64 a_float = 7.2;
  ViReal64 a_float_enum = 6.5f;
  ViReal64 an_array[] = {1.0, 2, -3.0};
  char a_string[] = "Hello!";
  ViInt32 string_size = sizeof(a_string);
  // ivi-dance call
  EXPECT_CALL(library, ReturnMultipleTypes(kTestViSession, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, nullptr, 0, nullptr))
      .WillOnce(Return(string_size));
  EXPECT_CALL(library, ReturnMultipleTypes(kTestViSession, _, _, _, _, _, _, array_size, _, string_size, _))
      .WillOnce(DoAll(
          SetArgPointee<1>(a_boolean),
          SetArgPointee<2>(an_int32),
          SetArgPointee<3>(an_int64),
          SetArgPointee<4>(an_int_enum),
          SetArgPointee<5>(a_float),
          SetArgPointee<6>(a_float_enum),
          SetArrayArgument<8>(an_array, an_array + array_size),
          SetArrayArgument<10>(a_string, a_string + string_size),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::ReturnMultipleTypesRequest request;
  request.mutable_vi()->set_id(session_id);
  request.set_array_size(3);
  nifake_grpc::ReturnMultipleTypesResponse response;
  ::grpc::Status status = service.ReturnMultipleTypes(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(a_boolean, response.a_boolean());
  EXPECT_EQ(an_int32, response.an_int32());
  EXPECT_EQ(an_int64, response.an_int64());
  EXPECT_EQ(an_int_enum, response.an_int_enum());
  EXPECT_EQ(an_int_enum, response.an_int_enum_raw());
  EXPECT_EQ(a_float, response.a_float());
  EXPECT_EQ(nifake_grpc::FloatEnum::FLOAT_ENUM_SIX_POINT_FIVE, response.a_float_enum());
  EXPECT_EQ(a_float_enum, response.a_float_enum_raw());
  EXPECT_THAT(response.an_array(), ElementsAreArray(an_array, array_size));
  EXPECT_STREQ(response.a_string().c_str(), a_string);
  EXPECT_EQ(response.a_string().length(), string_size - 1);
}

TEST(NiFakeServiceTests, NiFakeService_WriteWaveform_CallsWriteWaveform)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  ViReal64 waveforms[] = {53.4, 42, -120.3};
  std::int32_t expected_number_of_samples = 3;
  EXPECT_CALL(library, WriteWaveform(kTestViSession, expected_number_of_samples, _))
      .With(Args<2, 1>(ElementsAreArray(waveforms)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::WriteWaveformRequest request;
  request.mutable_vi()->set_id(session_id);
  for (double waveform : waveforms) {
    request.add_waveform(waveform);
  }
  nifake_grpc::WriteWaveformResponse response;
  ::grpc::Status status = service.WriteWaveform(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_FetchWaveform_CallsFetchWaveform)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  ViInt32 request_number_of_samples = 4;
  ViReal64 actual_doubles[] = {53.4, 42, -120.3};
  ViInt32 actual_number_of_samples = 3;
  EXPECT_CALL(library, FetchWaveform(kTestViSession, request_number_of_samples, _, _))
      .WillOnce(DoAll(
          SetArrayArgument<2>(actual_doubles, actual_doubles + actual_number_of_samples),
          SetArgPointee<3>(actual_number_of_samples),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::FetchWaveformRequest request;
  request.mutable_vi()->set_id(session_id);
  request.set_number_of_samples(request_number_of_samples);
  nifake_grpc::FetchWaveformResponse response;
  ::grpc::Status status = service.FetchWaveform(&context, &request, &response);

  double expected_response_doubles[] = {actual_doubles[0], actual_doubles[1], actual_doubles[2], 0.0};
  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(response.actual_number_of_samples(), actual_number_of_samples);
  EXPECT_EQ(response.waveform_data_size(), request_number_of_samples);
  EXPECT_THAT(response.waveform_data(), ElementsAreArray(expected_response_doubles, request_number_of_samples));
}

// Non-int enum Tests
TEST(NiFakeServiceTests, NiFakeService_StringValuedEnumInputFunctionWithDefaultsWithInvalidEnumInput_ReturnsInvalidArgument)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  nifake_grpc::MobileOSNames a_mobile_o_s_name = nifake_grpc::MOBILE_O_S_NAMES_UNSPECIFIED;
  EXPECT_CALL(library, StringValuedEnumInputFunctionWithDefaults)
      .Times(0);

  ::grpc::ServerContext context;
  nifake_grpc::StringValuedEnumInputFunctionWithDefaultsRequest request;
  request.mutable_vi()->set_id(session_id);
  request.set_a_mobile_o_s_name(a_mobile_o_s_name);
  nifake_grpc::StringValuedEnumInputFunctionWithDefaultsResponse response;
  ::grpc::Status status = service.StringValuedEnumInputFunctionWithDefaults(&context, &request, &response);

  EXPECT_EQ(::grpc::INVALID_ARGUMENT, status.error_code());
  EXPECT_EQ(NULL, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_StringValuedEnumInputFunctionWithDefaultsWithValidEnumInput_CallsStringValuedEnumInputFunctionWithDefaults)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  nifake_grpc::MobileOSNames a_mobile_o_s_name = nifake_grpc::MOBILE_O_S_NAMES_ANDROID;
  const char* expected_enum_value = NIFAKE_VAL_ANDROID;
  EXPECT_CALL(library, StringValuedEnumInputFunctionWithDefaults(kTestViSession, Pointee(*expected_enum_value)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::StringValuedEnumInputFunctionWithDefaultsRequest request;
  request.mutable_vi()->set_id(session_id);
  request.set_a_mobile_o_s_name(a_mobile_o_s_name);
  nifake_grpc::StringValuedEnumInputFunctionWithDefaultsResponse response;
  ::grpc::Status status = service.StringValuedEnumInputFunctionWithDefaults(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

// Array methods using ivi-dance mechanism
TEST(NiFakeServiceTests, NiFakeService_ExportAttributeConfigurationBuffer_CallsExportAttributeConfigurationBuffer)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  ViInt8 config_buffer[] = {'A', 'B', 'C'};
  ViInt32 expected_size = 3;
  // ivi-dance call
  EXPECT_CALL(library, ExportAttributeConfigurationBuffer(kTestViSession, 0, nullptr))
      .WillOnce(Return(expected_size));
  // follow up call with size returned from ivi-dance setup.
  EXPECT_CALL(library, ExportAttributeConfigurationBuffer(kTestViSession, expected_size, _))
      .WillOnce(DoAll(
          SetArrayArgument<2>(config_buffer, config_buffer + expected_size),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::ExportAttributeConfigurationBufferRequest request;
  request.mutable_vi()->set_id(session_id);
  nifake_grpc::ExportAttributeConfigurationBufferResponse response;
  ::grpc::Status status = service.ExportAttributeConfigurationBuffer(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_THAT(response.configuration(), ElementsAreArray(config_buffer, expected_size));
}

TEST(NiFakeServiceTests, NiFakeService_GetAnIviDanceString_CallsGetAnIviDanceString)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  ViChar char_array[] = {'H', 'E', 'L', 'L', 'O', '\0'};
  ViInt32 expected_size = sizeof(char_array);
  // ivi-dance call
  EXPECT_CALL(library, GetAnIviDanceString(kTestViSession, 0, nullptr))
      .WillOnce(Return(expected_size));
  // follow up call with size returned from ivi-dance setup.
  EXPECT_CALL(library, GetAnIviDanceString(kTestViSession, expected_size, _))
      .WillOnce(DoAll(
          SetArrayArgument<2>(char_array, char_array + expected_size),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAnIviDanceStringRequest request;
  request.mutable_vi()->set_id(session_id);
  nifake_grpc::GetAnIviDanceStringResponse response;
  ::grpc::Status status = service.GetAnIviDanceString(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_STREQ(response.a_string().c_str(), char_array);
  EXPECT_EQ(response.a_string().length(), expected_size - 1);
}

TEST(NiFakeServiceTests, NiFakeService_GetArrayUsingIviDance_CallsGetArrayUsingIviDance)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  ViReal64 doubles[] = {53.4, 42, -120.3};
  ViInt32 expected_size = 3;
  // ivi-dance call
  EXPECT_CALL(library, GetArrayUsingIviDance(kTestViSession, 0, nullptr))
      .WillOnce(Return(expected_size));
  // follow up call with size returned from ivi-dance setup.
  EXPECT_CALL(library, GetArrayUsingIviDance(kTestViSession, expected_size, _))
      .WillOnce(DoAll(
          SetArrayArgument<2>(doubles, doubles + expected_size),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetArrayUsingIviDanceRequest request;
  request.mutable_vi()->set_id(session_id);
  nifake_grpc::GetArrayUsingIviDanceResponse response;
  ::grpc::Status status = service.GetArrayUsingIviDance(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_THAT(response.array_out(), ElementsAreArray(doubles, expected_size));
}

TEST(NiFakeServiceTests, NiFakeService_GetAttributeViString_CallsGetAttributeViString)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  nifake_grpc::NiFakeAttributes attributeId = nifake_grpc::NIFAKE_ATTRIBUTE_READ_WRITE_DOUBLE;
  ViChar attribute_char_array[] = {'H', 'E', 'L', 'L', 'O', '\0'};
  ViInt32 expected_size = sizeof(attribute_char_array);
  // ivi-dance call
  EXPECT_CALL(library, GetAttributeViString(kTestViSession, Pointee(*kTestChannelName), attributeId, 0, nullptr))
      .WillOnce(Return(expected_size));
  // follow up call with size returned from ivi-dance setup.
  EXPECT_CALL(library, GetAttributeViString(kTestViSession, Pointee(*kTestChannelName), attributeId, expected_size, _))
      .WillOnce(DoAll(
          SetArrayArgument<4>(attribute_char_array, attribute_char_array + expected_size),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  nifake_grpc::GetAttributeViStringRequest request;
  request.mutable_vi()->set_id(session_id);
  request.set_channel_name(kTestChannelName);
  request.set_attribute_id(attributeId);
  nifake_grpc::GetAttributeViStringResponse response;
  ::grpc::Status status = service.GetAttributeViString(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_STREQ(response.attribute_value().c_str(), attribute_char_array);
  EXPECT_EQ(response.attribute_value().length(), expected_size - 1);
}

TEST(NiFakeServiceTests, NiFakeService_AcceptViUInt32Array_CallsAcceptViUInt32Array)
{
  nidevice_grpc::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  nifake_grpc::NiFakeService service(&library, &session_repository);
  std::uint32_t uint32_array[] = {0, 1, 0xFFFFFFFD, 0xFFFFFFFE, 0xFFFFFFFF};
  std::int32_t array_len = 5;
  EXPECT_CALL(library, AcceptViUInt32Array(kTestViSession, array_len, _))
      .With(Args<2, 1>(ElementsAreArray(uint32_array)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  nifake_grpc::AcceptViUInt32ArrayRequest request;
  request.mutable_vi()->set_id(session_id);
  request.mutable_u_int32_array()->CopyFrom(google::protobuf::RepeatedField<google::protobuf::uint32>(uint32_array, uint32_array+5));
  nifake_grpc::AcceptViUInt32ArrayResponse response;
  ::grpc::Status status = service.AcceptViUInt32Array(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
