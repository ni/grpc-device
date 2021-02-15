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

TEST(NiFakeServiceTests, NiFakeService_FunctionNotFound_DoesNotCallFunction)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  NiFakeMockLibraryWrapper library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  ni::fake::grpc::GetABooleanRequest request;
  EXPECT_CALL(library_wrapper, check_function_exists("niFake_GetABoolean"))
      .WillOnce(testing::Return(::grpc::Status(::grpc::NOT_FOUND, "The requested function was not found: niFake_GetABoolean")));
  EXPECT_CALL(library_wrapper, GetABoolean)
      .Times(0);

  ::grpc::ServerContext context;
  ni::fake::grpc::GetABooleanResponse response;
  ::grpc::Status status = service.GetABoolean(&context, &request, &response);

  // Since the ni fake library shouldn't be present, we expect a NOT_FOUND status in response.
  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
}

TEST(NiFakeServiceTests, NiFakeService_FunctionFound_CallsLibraryFunction)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  NiFakeMockLibraryWrapper library_wrapper;
  ni::fake::grpc::NiFakeService service(&library_wrapper, &session_repository);
  ni::fake::grpc::GetABooleanRequest request;
  EXPECT_CALL(library_wrapper, check_function_exists("niFake_GetABoolean"))
      .WillOnce(testing::Return(::grpc::Status::OK));
  EXPECT_CALL(library_wrapper, GetABoolean)
      .Times(1);

  ::grpc::ServerContext context;
  ni::fake::grpc::GetABooleanResponse response;
  ::grpc::Status status = service.GetABoolean(&context, &request, &response);

  // Since the ni fake library shouldn't be present, we expect a NOT_FOUND status in response.
  EXPECT_TRUE(status.ok());
}

}  // namespace grpc
}  // namespace fake
}  // namespace unit
}  // namespace tests
}  // namespace ni
