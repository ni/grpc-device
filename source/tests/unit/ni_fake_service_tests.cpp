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

std::uint32_t create_session(ni::hardware::grpc::internal::SessionRepository& session_repo, ViSession sessionToStore)
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
  ni::hardware::grpc::internal::SessionRepository session_repository;
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  const char* resource_name = "Dev0";
  const char* option_string = "Simulate = 1";
  bool id_query = false, reset_device = true;
  const char* session_name = "sessionName";
  EXPECT_CALL(library, InitWithOptions(Pointee(*resource_name), id_query, reset_device, Pointee(*option_string), _))
      .WillOnce(DoAll(SetArgPointee<4>(kTestViSession), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::InitWithOptionsRequest request;
  request.set_resource_name(resource_name);
  request.set_id_query(id_query);
  request.set_reset_device(reset_device);
  request.set_option_string(option_string);
  request.set_session_name(session_name);
  ni::fake::grpc::InitWithOptionsResponse response;
  ::grpc::Status status = service.InitWithOptions(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  ni::hardware::grpc::Session session = response.vi();
  EXPECT_EQ(kTestViSession, session_repository.access_session(session.id(), ""));
  EXPECT_EQ(kTestViSession, session_repository.access_session(0, session_name));
}

TEST(NiFakeServiceTests, NiFakeService_InitWithOptionsFails_NoSessionIsStored)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  const char* message = "Exception!";
  EXPECT_CALL(library, InitWithOptions)
      .WillOnce(DoAll(SetArgPointee<4>(kTestViSession), Throw(ni::hardware::grpc::internal::LibraryLoadException(message))));

  ::grpc::ServerContext context;
  ni::fake::grpc::InitWithOptionsRequest request;
  ni::fake::grpc::InitWithOptionsResponse response;
  ::grpc::Status status = service.InitWithOptions(&context, &request, &response);

  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
  EXPECT_EQ(message, status.error_message());
  ni::hardware::grpc::Session session = response.vi();
  EXPECT_NE(kTestViSession, session_repository.access_session(session.id(), ""));
  EXPECT_EQ(0, session_repository.access_session(session.id(), ""));
}

TEST(NiFakeServiceTests, NiFakeService_InitWithOptionsAndResetServer_SessionIsClosed)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  const char* session_name = "sessionName";
  EXPECT_CALL(library, InitWithOptions)
      .WillOnce(DoAll(SetArgPointee<4>(kTestViSession), Return(kDriverSuccess)));
  EXPECT_CALL(library, close(kTestViSession))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  ni::fake::grpc::InitWithOptionsRequest request;
  request.set_session_name(session_name);
  ni::fake::grpc::InitWithOptionsResponse response;
  ::grpc::Status init_status = service.InitWithOptions(&context, &request, &response);
  EXPECT_TRUE(init_status.ok());
  ni::hardware::grpc::Session session = response.vi();
  EXPECT_EQ(kTestViSession, session_repository.access_session(session.id(), ""));
  EXPECT_EQ(kTestViSession, session_repository.access_session(0, session_name));
  bool reset_status = session_repository.reset_server();

  EXPECT_TRUE(reset_status);
  EXPECT_NE(kTestViSession, session_repository.access_session(session.id(), ""));
  EXPECT_EQ(0, session_repository.access_session(session.id(), ""));
}

TEST(NiFakeServiceTests, NiFakeService_InitWithOptionsThenClose_SessionIsClosed)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  std::string session_name = "sessionName";
  EXPECT_CALL(library, InitWithOptions)
      .WillOnce(DoAll(SetArgPointee<4>(kTestViSession), Return(kDriverSuccess)));
  EXPECT_CALL(library, close(kTestViSession))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  ni::fake::grpc::InitWithOptionsRequest init_request;
  init_request.set_session_name(session_name);
  ni::fake::grpc::InitWithOptionsResponse init_response;
  ::grpc::Status init_status = service.InitWithOptions(&context, &init_request, &init_response);
  EXPECT_TRUE(init_status.ok());
  ni::hardware::grpc::Session session = init_response.vi();
  EXPECT_EQ(kTestViSession, session_repository.access_session(session.id(), ""));
  EXPECT_EQ(kTestViSession, session_repository.access_session(0, session_name));
  ni::fake::grpc::CloseRequest close_request;
  close_request.mutable_vi()->set_id(session.id());
  ni::fake::grpc::CloseResponse close_response;
  ::grpc::Status close_status = service.Close(&context, &close_request, &close_response);

  EXPECT_TRUE(close_status.ok());
  EXPECT_EQ(kDriverSuccess, close_response.status());
  EXPECT_NE(kTestViSession, session_repository.access_session(session.id(), ""));
  EXPECT_EQ(0, session_repository.access_session(session.id(), ""));
}

// Error logic tests using GetABoolean
TEST(NiFakeServiceTests, NiFakeService_FunctionNotFound_DoesNotCallFunction)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  const char* message = "Exception!";
  EXPECT_CALL(library, GetABoolean)
      .WillOnce(Throw(ni::hardware::grpc::internal::LibraryLoadException(message)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetABooleanRequest request;
  request.mutable_vi()->set_id(session_id);
  ni::fake::grpc::GetABooleanResponse response;
  ::grpc::Status status = service.GetABoolean(&context, &request, &response);

  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
  EXPECT_EQ(message, status.error_message());
}

TEST(NiFakeServiceTests, NiFakeService_FunctionCallErrors_ResponseValuesNotSet)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  bool a_boolean = true;
  EXPECT_CALL(library, GetABoolean(kTestViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(a_boolean), Return(kDriverFailure)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetABooleanRequest request;
  request.mutable_vi()->set_id(session_id);
  ni::fake::grpc::GetABooleanResponse response;
  ::grpc::Status status = service.GetABoolean(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverFailure, response.status());
  EXPECT_NE(a_boolean, response.a_boolean());
}

TEST(NiFakeServiceTests, NiFakeService_GetABoolean_CallsGetABoolean)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  bool a_boolean = true;
  EXPECT_CALL(library, GetABoolean(kTestViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(a_boolean), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetABooleanRequest request;
  request.mutable_vi()->set_id(session_id);
  ni::fake::grpc::GetABooleanResponse response;
  ::grpc::Status status = service.GetABoolean(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(a_boolean, response.a_boolean());
}

// Simple Input and Output Type Function Tests
TEST(NiFakeServiceTests, NiFakeService_Abort_CallsAbort)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  EXPECT_CALL(library, Abort(kTestViSession))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  ni::fake::grpc::AbortRequest request;
  request.mutable_vi()->set_id(session_id);
  ni::fake::grpc::AbortResponse response;
  ::grpc::Status status = service.Abort(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_GetANumber_CallsGetANumber)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  std::int16_t a_number = 15;
  EXPECT_CALL(library, GetANumber(kTestViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(a_number), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetANumberRequest request;
  request.mutable_vi()->set_id(session_id);
  ni::fake::grpc::GetANumberResponse response;
  ::grpc::Status status = service.GetANumber(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(a_number, response.a_number());
}

TEST(NiFakeServiceTests, NiFakeService_GetArraySizeForPythonCode_CallsGetArraySizeForPythonCode)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  std::int32_t array_size = 1000;
  EXPECT_CALL(library, GetArraySizeForPythonCode(kTestViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(array_size), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetArraySizeForPythonCodeRequest request;
  request.mutable_vi()->set_id(session_id);
  ni::fake::grpc::GetArraySizeForPythonCodeResponse response;
  ::grpc::Status status = service.GetArraySizeForPythonCode(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(array_size, response.size_out());
}

TEST(NiFakeServiceTests, NiFakeService_GetAttributeViBoolean_CallsGetAttributeViBoolean)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  ni::fake::grpc::NiFakeAttributes attribute_id = ni::fake::grpc::NIFAKE_READ_WRITE_BOOL;
  bool attribute_value = true;
  EXPECT_CALL(library, GetAttributeViBoolean(kTestViSession, Pointee(*kTestChannelName), attribute_id, _))
      .WillOnce(DoAll(SetArgPointee<3>(attribute_value), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetAttributeViBooleanRequest request;
  request.mutable_vi()->set_id(session_id);
  request.set_channel_name(kTestChannelName);
  request.set_attribute_id(attribute_id);
  ni::fake::grpc::GetAttributeViBooleanResponse response;
  ::grpc::Status status = service.GetAttributeViBoolean(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(attribute_value, response.attribute_value());
}

TEST(NiFakeServiceTests, NiFakeService_GetAttributeViInt32_CallsGetAttributeViInt32)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  ni::fake::grpc::NiFakeAttributes attribute_id = ni::fake::grpc::NIFAKE_READ_WRITE_INTEGER;
  std::int32_t attribute_value = 12345;
  EXPECT_CALL(library, GetAttributeViInt32(kTestViSession, Pointee(*kTestChannelName), attribute_id, _))
      .WillOnce(DoAll(SetArgPointee<3>(attribute_value), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetAttributeViInt32Request request;
  request.mutable_vi()->set_id(session_id);
  request.set_channel_name(kTestChannelName);
  request.set_attribute_id(attribute_id);
  ni::fake::grpc::GetAttributeViInt32Response response;
  ::grpc::Status status = service.GetAttributeViInt32(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(attribute_value, response.attribute_value());
}

TEST(NiFakeServiceTests, NiFakeService_GetAttributeViInt64_CallsGetAttributeViInt64)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  ni::fake::grpc::NiFakeAttributes attribute_id = ni::fake::grpc::NIFAKE_READ_WRITE_INT64;
  std::int64_t attribute_value = -12345;
  EXPECT_CALL(library, GetAttributeViInt64(kTestViSession, Pointee(*kTestChannelName), attribute_id, _))
      .WillOnce(DoAll(SetArgPointee<3>(attribute_value), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetAttributeViInt64Request request;
  request.mutable_vi()->set_id(session_id);
  request.set_channel_name(kTestChannelName);
  request.set_attribute_id(attribute_id);
  ni::fake::grpc::GetAttributeViInt64Response response;
  ::grpc::Status status = service.GetAttributeViInt64(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(attribute_value, response.attribute_value());
}

TEST(NiFakeServiceTests, NiFakeService_GetAttributeViReal64_CallsGetAttributeViReal64)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  ni::fake::grpc::NiFakeAttributes attribute_id = ni::fake::grpc::NIFAKE_READ_WRITE_DOUBLE;
  double attribute_value = 12.345;
  EXPECT_CALL(library, GetAttributeViReal64(kTestViSession, Pointee(*kTestChannelName), attribute_id, _))
      .WillOnce(DoAll(SetArgPointee<3>(attribute_value), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetAttributeViReal64Request request;
  request.mutable_vi()->set_id(session_id);
  request.set_channel_name(kTestChannelName);
  request.set_attribute_id(attribute_id);
  ni::fake::grpc::GetAttributeViReal64Response response;
  ::grpc::Status status = service.GetAttributeViReal64(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(attribute_value, response.attribute_value());
}

TEST(NiFakeServiceTests, NiFakeService_GetCalDateAndTime_CallsGetCalDateAndTime)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
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
  ni::fake::grpc::GetCalDateAndTimeRequest request;
  request.mutable_vi()->set_id(session_id);
  request.set_cal_type(cal_type);
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
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  ni::fake::grpc::NiFakeAttributes attribute_id = ni::fake::grpc::NIFAKE_READ_WRITE_DOUBLE;
  std::int32_t months = 24;
  EXPECT_CALL(library, GetCalInterval(kTestViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(months), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetCalIntervalRequest request;
  request.mutable_vi()->set_id(session_id);
  ni::fake::grpc::GetCalIntervalResponse response;
  ::grpc::Status status = service.GetCalInterval(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(months, response.months());
}

TEST(NiFakeServiceTests, NiFakeService_GetEnumValue_CallsGetEnumValue)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  std::int32_t a_quantity = 123;
  std::int16_t a_turtle = NIFAKE_VAL_LEONARDO;
  EXPECT_CALL(library, GetEnumValue(kTestViSession, _, _))
    .WillOnce(DoAll(SetArgPointee<1>(a_quantity), SetArgPointee<2>(a_turtle), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetEnumValueRequest request;
  request.mutable_vi()->set_id(session_id);
  ni::fake::grpc::GetEnumValueResponse response;
  ::grpc::Status status = service.GetEnumValue(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(a_quantity, response.a_quantity());
  EXPECT_EQ(a_turtle, response.a_turtle());
}

// Array input and output tests
TEST(NiFakeServiceTests, NiFakeService_AcceptListOfDurationsInSeconds_CallsAcceptListOfDurationsInSeconds)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  const double delays[] = {1, 2, 3, 4, 5};
  std::int32_t expected_size = 5;
  EXPECT_CALL(library, AcceptListOfDurationsInSeconds(kTestViSession, expected_size, _))
      .With(Args<2, 1>(ElementsAreArray(delays)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  ni::fake::grpc::AcceptListOfDurationsInSecondsRequest request;
  request.mutable_vi()->set_id(session_id);
  for (double delay : delays) {
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
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  const double numbers[] = {1, 2, 3, 4, 5};
  std::int32_t expected_size = 5;
  EXPECT_CALL(library, DoubleAllTheNums(kTestViSession, expected_size, _))
      .With(Args<2, 1>(ElementsAreArray(numbers)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  ni::fake::grpc::DoubleAllTheNumsRequest request;
  request.mutable_vi()->set_id(session_id);
  for (double number : numbers) {
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
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  char output_string[256] = "Hello World!";
  EXPECT_CALL(library, GetAStringOfFixedMaximumSize(kTestViSession, _))
      .WillOnce(DoAll(
          SetArrayArgument<1>(output_string, output_string + 256),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;   
  ni::fake::grpc::GetAStringOfFixedMaximumSizeRequest request;
  request.mutable_vi()->set_id(session_id);
  ni::fake::grpc::GetAStringOfFixedMaximumSizeResponse response;
  ::grpc::Status status = service.GetAStringOfFixedMaximumSize(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_STREQ(output_string, response.a_string().c_str());
}

TEST(NiFakeServiceTests, NiFakeService_GetCustomTypeArray_CallsGetCustomTypeArray)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  ViInt32 number_of_elements = 3;
  std::vector<CustomStruct> cs(number_of_elements);

  EXPECT_CALL(library, GetCustomTypeArray(kTestViSession, number_of_elements, _))
    .WillOnce(DoAll(SetArgPointee<2>(*(cs.data())), Return(kDriverSuccess)));

  ::grpc::ServerContext context;   
  ni::fake::grpc::GetCustomTypeArrayRequest request;
  request.mutable_vi()->set_id(session_id);
  request.set_number_of_elements(3);
  ni::fake::grpc::GetCustomTypeArrayResponse response;
  ::grpc::Status status = service.GetCustomTypeArray(&context, &request, &response);
  
  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());

}

TEST(NiFakeServiceTests, NiFakeService_ImportAttributeConfigurationBuffer_CallsImportAttributeConfigurationBuffer)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  const std::int8_t char_array[] = {'a', 'b', 'c'};
  std::int32_t expected_size = 3;
  EXPECT_CALL(library, ImportAttributeConfigurationBuffer(kTestViSession, expected_size, _))
      .With(Args<2, 1>(ElementsAreArray(char_array)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  ni::fake::grpc::ImportAttributeConfigurationBufferRequest request;
  request.mutable_vi()->set_id(session_id);
  for (std::int8_t character : char_array) {
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
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
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
  ni::fake::grpc::MultipleArraysSameSizeRequest request;
  request.mutable_vi()->set_id(session_id);
  for (double num : doubles) {
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
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  bool a_boolean = true;
  std::int32_t an_int_32 = 35;
  std::int64_t an_int_64 = 42;
  ni::fake::grpc::Turtle an_int_enum = ni::fake::grpc::Turtle::TURTLE_MICHELANGELO;
  double a_float = 4.2;
  ni::fake::grpc::FloatEnum a_float_enum = ni::fake::grpc::FloatEnum::FLOAT_ENUM_SIX_POINT_FIVE;
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
  ni::fake::grpc::ParametersAreMultipleTypesRequest request;
  request.mutable_vi()->set_id(session_id);
  request.set_a_boolean(a_boolean);
  request.set_an_int32(an_int_32);
  request.set_an_int64(an_int_64);
  request.set_an_int_enum(an_int_enum);
  request.set_a_float(a_float);
  request.set_a_float_enum(a_float_enum);
  request.set_a_string(a_string);
  ni::fake::grpc::ParametersAreMultipleTypesResponse response;
  ::grpc::Status status = service.ParametersAreMultipleTypes(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_ReturnANumberAndAString_CallsReturnANumberAndAString)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  std::int16_t a_number = 42;
  char a_string[256] = "Hello World!";
  EXPECT_CALL(library, ReturnANumberAndAString(kTestViSession, _, _))
      .WillOnce(DoAll(
          SetArgPointee<1>(a_number),
          SetArrayArgument<2>(a_string, a_string + 256),
          Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::ReturnANumberAndAStringRequest request;
  request.mutable_vi()->set_id(session_id);
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
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  double waveforms[] = {53.4, 42, -120.3};
  std::int32_t expected_number_of_samples = 3;
  EXPECT_CALL(library, WriteWaveform(kTestViSession, expected_number_of_samples, _))
      .With(Args<2, 1>(ElementsAreArray(waveforms)))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  ni::fake::grpc::WriteWaveformRequest request;
  request.mutable_vi()->set_id(session_id);
  for (double waveform : waveforms) {
    request.add_waveform(waveform);
  }
  ni::fake::grpc::WriteWaveformResponse response;
  ::grpc::Status status = service.WriteWaveform(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

// Non-int enum Tests
TEST(NiFakeServiceTests, NiFakeService_StringValuedEnumInputFunctionWithDefaultsWithInvalidEnumInput_ReturnsInvalidArgument)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  ni::fake::grpc::MobileOSNames a_mobile_o_s_name = ni::fake::grpc::MOBILE_O_S_NAMES_UNSPECIFIED;
  EXPECT_CALL(library, StringValuedEnumInputFunctionWithDefaults)
    .Times(0);

  ::grpc::ServerContext context;
  ni::fake::grpc::StringValuedEnumInputFunctionWithDefaultsRequest request;
  request.mutable_vi()->set_id(session_id);
  request.set_a_mobile_o_s_name(a_mobile_o_s_name);
  ni::fake::grpc::StringValuedEnumInputFunctionWithDefaultsResponse response;
  ::grpc::Status status = service.StringValuedEnumInputFunctionWithDefaults(&context, &request, &response);

  EXPECT_EQ(::grpc::INVALID_ARGUMENT, status.error_code());
  EXPECT_EQ(NULL, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_StringValuedEnumInputFunctionWithDefaultsWithValidEnumInput_CallsStringValuedEnumInputFunctionWithDefaults)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  std::uint32_t session_id = create_session(session_repository, kTestViSession);
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  ni::fake::grpc::MobileOSNames a_mobile_o_s_name = ni::fake::grpc::MOBILE_O_S_NAMES_ANDROID;
  const char* expected_enum_value = NIFAKE_VAL_ANDROID;
  EXPECT_CALL(library, StringValuedEnumInputFunctionWithDefaults(kTestViSession, Pointee(*expected_enum_value)))
    .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  ni::fake::grpc::StringValuedEnumInputFunctionWithDefaultsRequest request;
  request.mutable_vi()->set_id(session_id);
  request.set_a_mobile_o_s_name(a_mobile_o_s_name);
  ni::fake::grpc::StringValuedEnumInputFunctionWithDefaultsResponse response;
  ::grpc::Status status = service.StringValuedEnumInputFunctionWithDefaults(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
