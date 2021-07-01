#include <grpcpp/impl/grpc_library.h>
#include <gtest/gtest.h>
#include <nifake_non_ivi/nifake_non_ivi_mock_library.h>
#include <nifake_non_ivi/nifake_non_ivi_service.h>
#include <server/session_resource_repository.h>

#include <iostream>
#include <string>

using namespace nifake_non_ivi_grpc;

using ::testing::_;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgPointee;
using ::testing::StrEq;

const int32 kDriverSuccess = 0;
const int32 kDriverFailure = 1;

namespace ni {
namespace tests {
namespace unit {

class NiFakeNonIviServiceTests : public ::testing::Test {
 protected:
  using FakeResourceRepository = nidevice_grpc::SessionResourceRepository<FakeHandle>;
  nidevice_grpc::SessionRepository session_repository_;
  std::shared_ptr<FakeResourceRepository> resource_repository_;
  NiFakeNonIviMockLibrary library_;
  NiFakeNonIviService service_;

  NiFakeNonIviServiceTests()
      : session_repository_(),
        resource_repository_(std::make_shared<FakeResourceRepository>(&session_repository_)),
        library_(),
        service_(&library_, resource_repository_)
  {
  }

  virtual ~NiFakeNonIviServiceTests() {}

  uint32_t init(const std::string& session_name, FakeHandle handle)
  {
    EXPECT_CALL(library_, Init(StrEq(session_name.c_str()), _))
        .WillOnce(DoAll(SetArgPointee<1>(handle), Return(kDriverSuccess)));

    ::grpc::ServerContext context;
    InitRequest request;
    request.set_session_name(session_name.c_str());
    InitResponse response;

    service_.Init(&context, &request, &response);

    return response.handle().id();
  }

  uint32_t init_with_handle_name_as_session_name(const std::string& handle_name, FakeHandle handle)
  {
    EXPECT_CALL(library_, InitWithHandleNameAsSessionName(StrEq(handle_name.c_str()), _))
        .WillOnce(DoAll(SetArgPointee<1>(handle), Return(kDriverSuccess)));

    ::grpc::ServerContext context;
    InitWithHandleNameAsSessionNameRequest request;
    request.set_handle_name(handle_name.c_str());
    InitWithHandleNameAsSessionNameResponse response;

    service_.InitWithHandleNameAsSessionName(&context, &request, &response);

    return response.handle().id();
  }

  int32 close_with_expected_handle(uint32_t session_id, FakeHandle expected_closed_handle)
  {
    EXPECT_CALL(library_, Close(expected_closed_handle))
        .WillOnce(Return(kDriverSuccess));
    ::grpc::ServerContext context;
    CloseRequest request;
    request.mutable_handle()->set_id(session_id);
    CloseResponse response;
    service_.Close(&context, &request, &response);

    return response.status();
  }
};

TEST_F(NiFakeNonIviServiceTests, InitSession_CloseSession_ClosesHandleAndSucceeds)
{
  const FakeHandle kHandle = 1234UL;
  auto session = init("test", kHandle);
  EXPECT_NE(0, session);

  auto status = close_with_expected_handle(session, kHandle);

  EXPECT_EQ(kDriverSuccess, status);
}

TEST_F(NiFakeNonIviServiceTests, InitWithHandleNameAsSessionName_CloseSession_ClosesHandleAndSucceeds)
{
  const FakeHandle kHandle = 99999UL;
  auto session = init_with_handle_name_as_session_name("test", kHandle);
  EXPECT_NE(0, session);

  auto status = close_with_expected_handle(session, kHandle);

  EXPECT_EQ(kDriverSuccess, status);
}
}  // namespace unit
}  // namespace tests
}  // namespace ni
