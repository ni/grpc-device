#include <grpcpp/impl/grpc_library.h>
#include <gtest/gtest.h>
#include <nifake_mock_library_wrapper.h>
#include <nifake_service.h>

#include <thread>

#include "hardware/grpc/internal/session_repository.h"

namespace ni {
namespace tests {
namespace unit {
namespace fake {
namespace grpc {

using ::testing::_;
using ::testing::DoAll;
using ::testing::NiceMock;
using ::testing::Return;
using ::testing::Pointee;
using ::testing::SetArgPointee;

const ViSession kViSession = 12345678;
const ViStatus kDriverSuccess = 0;
const ViStatus kDriverFailure = 1;

// Error logic tests using GetABoolean
TEST(NiFakeServiceTests, NiFakeService_FunctionNotFound_DoesNotCallFunction)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  NiFakeMockLibraryWrapper library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  EXPECT_CALL(library_wrapper, check_function_exists("niFake_GetABoolean"))
      .WillOnce(Return(::grpc::Status(::grpc::NOT_FOUND, "The requested function was not found: niFake_GetABoolean")));
  EXPECT_CALL(library_wrapper, GetABoolean)
      .Times(0);

  ::grpc::ServerContext context;
  ni::fake::grpc::GetABooleanRequest request;
  ni::fake::grpc::GetABooleanResponse response;
  ::grpc::Status status = service.GetABoolean(&context, &request, &response);

  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
}

TEST(NiFakeServiceTests, NiFakeService_FunctionFound_CallsLibraryFunction)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  NiFakeMockLibraryWrapper library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  EXPECT_CALL(library_wrapper, check_function_exists("niFake_GetABoolean"))
      .WillOnce(Return(::grpc::Status::OK));
  EXPECT_CALL(library_wrapper, GetABoolean)
      .Times(1);

  ::grpc::ServerContext context;
  ni::fake::grpc::GetABooleanRequest request;
  ni::fake::grpc::GetABooleanResponse response;
  ::grpc::Status status = service.GetABoolean(&context, &request, &response);

  EXPECT_TRUE(status.ok());
}

TEST(NiFakeServiceTests, NiFakeService_FunctionCallErrors_ResponseDoesNotIncludeReturnValue)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  NiceMock<NiFakeMockLibraryWrapper> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  ViBoolean aBoolean = true;
  EXPECT_CALL(library_wrapper, GetABoolean(kViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(aBoolean), Return(kDriverFailure)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetABooleanRequest request;
  request.set_vi(kViSession);
  ni::fake::grpc::GetABooleanResponse response;
  ::grpc::Status status = service.GetABoolean(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverFailure, response.status());
  EXPECT_NE(aBoolean, response.a_boolean());
}

TEST(NiFakeServiceTests, NiFakeService_FunctionCallSucceeds_ResponseIncludesReturnValue)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  NiceMock<NiFakeMockLibraryWrapper> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  ViBoolean aBoolean = true;
  EXPECT_CALL(library_wrapper, GetABoolean(kViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(aBoolean), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetABooleanRequest request;
  request.set_vi(kViSession);
  ni::fake::grpc::GetABooleanResponse response;
  ::grpc::Status status = service.GetABoolean(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(aBoolean, response.a_boolean());
}

// Individual Function Tests for functions without enums or arrays
TEST(NiFakeServiceTests, NiFakeService_Abort_CallsAbortLibraryFunction)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  NiceMock<NiFakeMockLibraryWrapper> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  EXPECT_CALL(library_wrapper, Abort(kViSession))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  ni::fake::grpc::AbortRequest request;
  request.set_vi(kViSession);
  ni::fake::grpc::AbortResponse response;
  ::grpc::Status status = service.Abort(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_Abort_CallsAbort)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  NiceMock<NiFakeMockLibraryWrapper> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  EXPECT_CALL(library_wrapper, Abort(kViSession))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  ni::fake::grpc::AbortRequest request;
  request.set_vi(kViSession);
  ni::fake::grpc::AbortResponse response;
  ::grpc::Status status = service.Abort(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST(NiFakeServiceTests, NiFakeService_GetANumber_CallsGetANumber)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  NiceMock<NiFakeMockLibraryWrapper> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  ViInt16 aNumber = 15;
  EXPECT_CALL(library_wrapper, GetANumber(kViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(aNumber), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetANumberRequest request;
  request.set_vi(kViSession);
  ni::fake::grpc::GetANumberResponse response;
  ::grpc::Status status = service.GetANumber(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(aNumber, response.a_number());
}

TEST(NiFakeServiceTests, NiFakeService_GetArraySizeForPythonCode_CallsGetArraySizeForPythonCode)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  NiceMock<NiFakeMockLibraryWrapper> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  ViInt32 arraySize = 1000;
  EXPECT_CALL(library_wrapper, GetArraySizeForPythonCode(kViSession, _))
      .WillOnce(DoAll(SetArgPointee<1>(arraySize), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetArraySizeForPythonCodeRequest request;
  request.set_vi(kViSession);
  ni::fake::grpc::GetArraySizeForPythonCodeResponse response;
  ::grpc::Status status = service.GetArraySizeForPythonCode(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(arraySize, response.size_out());
}

TEST(NiFakeServiceTests, NiFakeService_GetAttributeViBoolean_CallsGetAttributeViBoolean)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  NiceMock<NiFakeMockLibraryWrapper> library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  const char* channelName = "channel";
  ni::fake::grpc::NiFakeAttributes attributeId = ni::fake::grpc::NIFAKE_READ_WRITE_BOOL;
  ViBoolean attributeValue = true;
  EXPECT_CALL(library_wrapper, GetAttributeViBoolean(kViSession, Pointee(*channelName), attributeId, _))
      .WillOnce(DoAll(SetArgPointee<3>(attributeValue), Return(kDriverSuccess)));

  ::grpc::ServerContext context;
  ni::fake::grpc::GetAttributeViBooleanRequest request;
  request.set_vi(kViSession);
  request.set_channel_name(channelName);
  request.set_attribute_id(attributeId);
  ni::fake::grpc::GetAttributeViBooleanResponse response;
  ::grpc::Status status = service.GetAttributeViBoolean(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(attributeValue, response.attribute_value());
}

}  // namespace grpc
}  // namespace fake
}  // namespace unit
}  // namespace tests
}  // namespace ni
