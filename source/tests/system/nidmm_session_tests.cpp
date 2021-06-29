#include <gtest/gtest.h>

#include "nidmm/nidmm_library.h"
#include "nidmm/nidmm_service.h"

namespace ni {
namespace tests {
namespace system {

namespace dmm = nidmm_grpc;

const int kViErrorDmmRsrcNFound = -1074118656;
const int kInvalidDmmSession = -1074130544;
const char* kViErrorDmmRsrcNFoundMessage = "Device was not recognized. The device is not supported with this driver or version.";
const char* kInvalidDmmSessionMessage = "IVI: (Hex 0xBFFA1190) The session handle is not valid.";
const char* kResourceName = "FakeDevice";
const char* kDmmOptionsString = "Simulate=1, DriverSetup=Model:4080; BoardType:PXIe";
const char* kSessionName = "SessionName";
const char* kInvalidRsrc = "";

class NiDmmSessionTest : public ::testing::Test {
 protected:
  NiDmmSessionTest()
  {
    ::grpc::ServerBuilder builder;
    session_repository_ = std::make_unique<nidevice_grpc::SessionRepository>();
    using ResourceRepository = nidevice_grpc::SessionResourceRepository<ViSession>;
    auto resource_repository = std::make_shared<ResourceRepository>(session_repository_.get());
    nidmm_library_ = std::make_unique<dmm::NiDmmLibrary>();
    nidmm_service_ = std::make_unique<dmm::NiDmmService>(nidmm_library_.get(), resource_repository);
    builder.RegisterService(nidmm_service_.get());

    server_ = builder.BuildAndStart();
    ResetStubs();
  }

  virtual ~NiDmmSessionTest() {}

  void ResetStubs()
  {
    channel_ = server_->InProcessChannel(::grpc::ChannelArguments());
    nidmm_stub_ = dmm::NiDmm::NewStub(channel_);
  }

  std::unique_ptr<dmm::NiDmm::Stub>& GetStub()
  {
    return nidmm_stub_;
  }

  ::grpc::Status call_init_with_options(const char* resource_name, const char* option_string, const char* session_name, dmm::InitWithOptionsResponse* response)
  {
    ::grpc::ClientContext context;
    dmm::InitWithOptionsRequest request;
    request.set_resource_name(resource_name);
    request.set_option_string(option_string);
    request.set_session_name(session_name);
    request.set_reset_device(false);
    request.set_id_query(false);

    ::grpc::Status status = GetStub()->InitWithOptions(&context, request, response);
    return status;
  }

  std::string get_error_message(int error_status)
  {
    dmm::InitWithOptionsResponse init_response;
    call_init_with_options(kResourceName, kDmmOptionsString, kSessionName, &init_response);
    nidevice_grpc::Session session = init_response.vi();

    ::grpc::ClientContext context;
    dmm::GetErrorMessageRequest error_request;
    error_request.mutable_vi()->set_id(session.id());
    error_request.set_error_code(error_status);
    dmm::GetErrorMessageResponse error_response;

    ::grpc::Status status = GetStub()->GetErrorMessage(&context, error_request, &error_response);
    EXPECT_TRUE(status.ok());
    return error_response.error_message();
  }

 private:
  std::shared_ptr<::grpc::Channel> channel_;
  std::unique_ptr<dmm::NiDmm::Stub> nidmm_stub_;
  std::unique_ptr<nidevice_grpc::SessionRepository> session_repository_;
  std::unique_ptr<dmm::NiDmmLibrary> nidmm_library_;
  std::unique_ptr<dmm::NiDmmService> nidmm_service_;
  std::unique_ptr<::grpc::Server> server_;
};

TEST_F(NiDmmSessionTest, InitializeSessionWithDeviceAndSessionName_CreatesDriverSession)
{
  dmm::InitWithOptionsResponse response;
  ::grpc::Status status = call_init_with_options(kResourceName, kDmmOptionsString, kSessionName, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.vi().id());
}

TEST_F(NiDmmSessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  dmm::InitWithOptionsResponse response;
  ::grpc::Status status = call_init_with_options(kResourceName, kDmmOptionsString, "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.vi().id());
}

TEST_F(NiDmmSessionTest, InitializeSessionWithoutDevice_ReturnsDriverError)
{
  dmm::InitWithOptionsResponse response;
  ::grpc::Status status = call_init_with_options(kInvalidRsrc, "", "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kViErrorDmmRsrcNFound, response.status());
  EXPECT_EQ(0, response.vi().id());
}

TEST_F(NiDmmSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  dmm::InitWithOptionsResponse init_response;
  call_init_with_options(kResourceName, kDmmOptionsString, kSessionName, &init_response);
  nidevice_grpc::Session session = init_response.vi();

  ::grpc::ClientContext context;
  dmm::CloseRequest close_request;
  close_request.mutable_vi()->set_id(session.id());
  dmm::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(NiDmmSessionTest, InvalidSession_CloseSession_ReturnsInvalidSesssionError)
{
  nidevice_grpc::Session session;
  session.set_id(NULL);

  ::grpc::ClientContext context;
  dmm::CloseRequest request;
  request.mutable_vi()->set_id(session.id());
  dmm::CloseResponse response;
  ::grpc::Status status = GetStub()->Close(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kInvalidDmmSession, response.status());
  std::string error_message = get_error_message(response.status());
  EXPECT_STREQ(kInvalidDmmSessionMessage, error_message.c_str());
}

TEST_F(NiDmmSessionTest, ErrorFromDriver_GetErrorMessage_ReturnsUserErrorMessage)
{
  dmm::InitWithOptionsResponse init_response;
  call_init_with_options(kInvalidRsrc, "", "", &init_response);
  EXPECT_EQ(kViErrorDmmRsrcNFound, init_response.status());

  nidevice_grpc::Session session = init_response.vi();
  ::grpc::ClientContext context;
  dmm::GetErrorMessageRequest error_request;
  error_request.mutable_vi()->set_id(session.id());
  error_request.set_error_code(kViErrorDmmRsrcNFound);
  dmm::GetErrorMessageResponse error_response;
  ::grpc::Status status = GetStub()->GetErrorMessage(&context, error_request, &error_response);

  EXPECT_TRUE(status.ok());
  EXPECT_STREQ(kViErrorDmmRsrcNFoundMessage, error_response.error_message().c_str());
}

}  // namespace system
}  // namespace tests
}  // namespace ni