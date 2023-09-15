#include <server/session_repository.h>
#include "visa/visa_mock_library.h"
#include "visa/visa_service.h"

using namespace testing;
using namespace visa_grpc;

namespace ni {
namespace tests {
namespace integration {

static const char* test_descriptor = "fake::descriptor";

void call_open(VisaService& service, const char* session_name)
{
    ::grpc::ServerContext context;
    OpenRequest request;
    OpenResponse response;
    request.set_instrument_descriptor(test_descriptor);
    request.set_access_mode(visa_grpc::LOCK_STATE_NO_LOCK);
    request.set_session_name(session_name);
    request.set_open_timeout(0);

    auto status = service.Open(&context, &request, &response);
    EXPECT_TRUE(status.ok());
    EXPECT_EQ(0, response.status());
}

void call_parse(VisaService& service)
{
    ::grpc::ServerContext context;
    ParseRsrcRequest request;
    ParseRsrcResponse response;
    request.set_resource_name(test_descriptor);

    auto status = service.ParseRsrc(&context, &request, &response);
    EXPECT_TRUE(status.ok());
    EXPECT_EQ(0, response.status());
}

ViStatus SetSessionToOne(ViSession* session)
{
  *session = (ViSession)1;
  return VI_SUCCESS;
}

TEST(VisaResourceManagerTest, ParsePlusOpen_OpensResourceManagerOnce)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<ni::tests::unit::VisaMockLibrary>();
  auto resource_repository = std::make_shared<nidevice_grpc::SessionResourceRepository<ViSession>>(session_repository);
  auto object_repository = std::shared_ptr<nidevice_grpc::SessionResourceRepository<ViObject>>();
  VisaService service(library, resource_repository, object_repository);

  EXPECT_CALL(*library, OpenDefaultRM)
    .WillOnce(WithArg<0>(Invoke(SetSessionToOne)));
  EXPECT_CALL(*library, ParseRsrc)
    .Times(1);
  EXPECT_CALL(*library, Open)
    .Times(1);

  call_parse(service);
  call_open(service, "name2");

  EXPECT_CALL(*library, Close)
    .Times(2);
  session_repository->reset_server();
}

TEST(VisaResourceManagerTest, OpenTwoSessions_OpensResourceManagerOnce)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<ni::tests::unit::VisaMockLibrary>();
  auto resource_repository = std::make_shared<nidevice_grpc::SessionResourceRepository<ViSession>>(session_repository);
  auto object_repository = std::shared_ptr<nidevice_grpc::SessionResourceRepository<ViObject>>();
  VisaService service(library, resource_repository, object_repository);

  EXPECT_CALL(*library, OpenDefaultRM)
    .WillOnce(WithArg<0>(Invoke(SetSessionToOne)));
  EXPECT_CALL(*library, Open)
    .Times(2);

  call_open(service, "name1");
  call_open(service, "name2");

  EXPECT_CALL(*library, Close)
    .Times(3);
  session_repository->reset_server();
}

TEST(VisaResourceManagerTest, ResetServerWithOpenSession_OpenNewSession_OpensResourceManagerAgain)
{
  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto library = std::make_shared<ni::tests::unit::VisaMockLibrary>();
  auto resource_repository = std::make_shared<nidevice_grpc::SessionResourceRepository<ViSession>>(session_repository);
  auto object_repository = std::shared_ptr<nidevice_grpc::SessionResourceRepository<ViObject>>();
  VisaService service(library, resource_repository, object_repository);

  EXPECT_CALL(*library, OpenDefaultRM)
    .Times(2)
    .WillRepeatedly(WithArg<0>(Invoke(SetSessionToOne)));
  EXPECT_CALL(*library, Open)
    .Times(2);
  EXPECT_CALL(*library, Close)
    .Times(4);

  call_open(service, "name1");
  session_repository->reset_server();

  call_open(service, "name2");
  session_repository->reset_server();
}

}  // namespace integration
}  // namespace tests
}  // namespace ni
