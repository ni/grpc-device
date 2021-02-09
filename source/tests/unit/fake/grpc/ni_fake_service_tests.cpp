#include <grpcpp/impl/grpc_library.h>
#include <gtest/gtest.h>

#include <thread>

#include "hardware/grpc/internal/session_repository.h"
#include "hardware/grpc/internal/shared_library.h"
#include "nifake/nifake_service.h"

namespace ni {
namespace tests {
namespace unit {
namespace fake {
namespace grpc {

#if defined(_MSC_VER)
static const char* expected_api_library_name = "nifake_64.dll";
#else
static const char* expected_api_library_name = "./nifake.so";
#endif

TEST(NiFakeServiceTests, NiFakeService_CreateService_SharedLibraryIsNotLoaded)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  ni::hardware::grpc::internal::SharedLibrary shared_library;

  ni::fake::grpc::NiFakeService service(&shared_library, &session_repository);

  EXPECT_FALSE(shared_library.is_loaded());
}

TEST(NiFakeServiceTests, NiFakeService_CreateService_SharedLibraryNameIsSet)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  ni::hardware::grpc::internal::SharedLibrary shared_library;

  ni::fake::grpc::NiFakeService service(&shared_library, &session_repository);
  std::string shared_library_name = shared_library.get_library_name();

  EXPECT_STREQ(expected_api_library_name, shared_library_name.c_str());
}

TEST(NiFakeServiceTests, LibraryNotPresent_GetABoolean_ReturnsNotFoundGrpcStatusError)
{
  ni::hardware::grpc::internal::SessionRepository session_repository;
  ni::hardware::grpc::internal::SharedLibrary shared_library;
  ni::fake::grpc::NiFakeService service(&shared_library, &session_repository);
  ni::fake::grpc::GetABooleanRequest request;

  ::grpc::ServerContext context;
  ni::fake::grpc::GetABooleanResponse response;
  ::grpc::Status status = service.GetABoolean(&context, &request, &response);

  // Since the ni fake library shouldn't be present, we expect a NOT_FOUND status in response.
  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
}

}  // namespace grpc
}  // namespace fake
}  // namespace unit
}  // namespace tests
}  // namespace ni
