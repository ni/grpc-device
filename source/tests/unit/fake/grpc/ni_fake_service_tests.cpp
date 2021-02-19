#include <grpcpp/impl/grpc_library.h>
#include <gtest/gtest.h>
#include <nifake_mock_library.h>
#include <nifake_service.h>

#include <thread>

#include "hardware/grpc/internal/session_repository.h"

namespace ni {
namespace tests {
namespace unit {
namespace fake {
namespace grpc {

TEST(NiFakeServiceTests, NiFakeService_FunctionNotFound_DoesNotCallFunction)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  EXPECT_CALL(library, check_function_exists("niFake_GetABoolean"))
      .WillOnce(testing::Return(::grpc::Status(::grpc::NOT_FOUND, "The requested function was not found: niFake_GetABoolean")));
  EXPECT_CALL(library, GetABoolean)
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
  NiFakeMockLibrary library;
  ni::fake::grpc::NiFakeService service(&library, &session_repository);
  EXPECT_CALL(library, check_function_exists("niFake_GetABoolean"))
      .WillOnce(testing::Return(::grpc::Status::OK));
  EXPECT_CALL(library, GetABoolean)
      .Times(1);

  ::grpc::ServerContext context;
  ni::fake::grpc::GetABooleanRequest request;
  ni::fake::grpc::GetABooleanResponse response;
  ::grpc::Status status = service.GetABoolean(&context, &request, &response);

  EXPECT_TRUE(status.ok());
}

}  // namespace grpc
}  // namespace fake
}  // namespace unit
}  // namespace tests
}  // namespace ni
