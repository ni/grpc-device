#include <server/session_repository.h>
#include "visa/visa_mock_library.h"
#include "visa/visa_service.h"

using namespace testing;
using namespace visa_grpc;

namespace ni {
namespace tests {
namespace integration {

static const char* test_descriptor = "fake::descriptor";

OpenResponse call_open(VisaService& service, const char* session_name)
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
    return response;
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

ViStatus SetNumberEventsToOne(void* attributeValue)
{
  *(ViUInt16*)attributeValue = 1;
  return VI_SUCCESS;
}

ViStatus SetEventTypeToTrigger(void* attributeValue)
{
  *(ViEventType*)attributeValue = VI_EVENT_TRIG;
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
  EXPECT_CALL(*library, GetAttribute(_, 0x3FFF019CUL, _))
    .WillOnce(WithArg<2>(Invoke(SetNumberEventsToOne)));
  EXPECT_CALL(*library, GetAttribute(_, 0x3FFF019DUL, _))
    .WillOnce(WithArg<2>(Invoke(SetEventTypeToTrigger)));

  call_parse(service);
  auto response = call_open(service, "name2");
  EXPECT_EQ(1, response.supported_events_size());
  EXPECT_EQ(VI_EVENT_TRIG, response.supported_events(0));

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
  EXPECT_CALL(*library, GetAttribute)
    .Times(2)
    .WillRepeatedly(Return(VI_ERROR_NSUP_ATTR));

  auto response = call_open(service, "name1");
  EXPECT_EQ(0, response.supported_events_size());
  response = call_open(service, "name2");
  EXPECT_EQ(0, response.supported_events_size());

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
  EXPECT_CALL(*library, GetAttribute)
    .Times(2)
    .WillRepeatedly(Return(VI_ERROR_NSUP_ATTR));
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
