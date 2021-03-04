#include <gtest/gtest.h>
#include <server/session_utilities_service.h>

#include "niscope/niscope_library.h"
#include "niscope/niscope_service.h"

namespace ni {
namespace tests {
namespace system {

namespace scope = ni::scope::grpc;

const int kViErrorRsrcNFound = -1073807343;
const char* kViErrorRsrcNFoundMessage = "VISA:  (Hex 0xBFFF0011) Insufficient location information or the device or resource is not present in the system.";
const char* kTestResourceName = "FakeDevice";
const char* kSimulatedOptionsString = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe";
const char* kTestSessionName = "SessionName";
const char* kInvalidResourceName = "";

class NiScopeSessionTest : public ::testing::Test {
 public:
  virtual ~NiScopeSessionTest() {}

  void SetUp() override
  {
    ResetStubs();
    ::grpc::ClientContext context;
    ni::hardware::grpc::ResetServerRequest request;
    ni::hardware::grpc::ResetServerResponse response;
    session_utilities_stub_->ResetServer(&context, request, &response);
  }

  void ResetStubs()
  {
    channel_ = server_->InProcessChannel(::grpc::ChannelArguments());
    niscope_stub_ = scope::NiScope::NewStub(channel_);
    session_utilities_stub_ = ni::hardware::grpc::SessionUtilities::NewStub(channel_);
  }

  std::unique_ptr<scope::NiScope::Stub>& GetStub()
  {
    return niscope_stub_;
  }

  ::grpc::Status call_init_with_options(const char* resource_name, const char* option_string, const char* session_name, scope::InitWithOptionsResponse* response)
  {
    ::grpc::ClientContext context;
    scope::InitWithOptionsRequest request;
    request.set_resource_name(resource_name);
    request.set_option_string(option_string);
    request.set_session_name(session_name);
    request.set_reset_device(false);
    request.set_id_query(false);

    ::grpc::Status status = GetStub()->InitWithOptions(&context, request, response);
    return status;
  }

 protected:
  NiScopeSessionTest()
  {
    ::grpc::ServerBuilder builder;
    session_repository_ = std::make_unique<ni::hardware::grpc::internal::SessionRepository>();
    device_enumerator_ = std::make_unique<ni::hardware::grpc::internal::DeviceEnumerator>();
    session_utilities_service_ = std::make_unique<ni::hardware::grpc::SessionUtilitiesService>(session_repository_.get(), device_enumerator_.get());
    niscope_library_ = std::make_unique<scope::NiScopeLibrary>();
    niscope_service_ = std::make_unique<scope::NiScopeService>(niscope_library_.get(), session_repository_.get());
    builder.RegisterService(session_utilities_service_.get());
    builder.RegisterService(niscope_service_.get());

    server_ = builder.BuildAndStart();
  }

 private:
  std::shared_ptr<::grpc::Channel> channel_;
  std::unique_ptr<scope::NiScope::Stub> niscope_stub_;
  std::unique_ptr<ni::hardware::grpc::SessionUtilities::Stub> session_utilities_stub_;
  std::unique_ptr<::ni::hardware::grpc::internal::SessionRepository> session_repository_;
  std::unique_ptr<::ni::hardware::grpc::internal::DeviceEnumerator> device_enumerator_;
  std::unique_ptr<::ni::hardware::grpc::SessionUtilitiesService> session_utilities_service_;
  std::unique_ptr<scope::NiScopeLibrary> niscope_library_;
  std::unique_ptr<scope::NiScopeService> niscope_service_;
  std::unique_ptr<::grpc::Server> server_;
};

TEST_F(NiScopeSessionTest, NiScopeClient_InitializeSessionWithDevice_CreatesDriverSession)
{
  ::grpc::ClientContext context;
  scope::InitWithOptionsResponse response;
  ::grpc::Status status = call_init_with_options(kTestResourceName, kSimulatedOptionsString, kTestSessionName, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.vi().id());
}

TEST_F(NiScopeSessionTest, NiScopeClient_InitializeSessionWithoutDevice_ReturnsDriverError)
{
  scope::InitWithOptionsResponse response;
  ::grpc::Status status = call_init_with_options(kInvalidResourceName, "", "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kViErrorRsrcNFound, response.status());
  EXPECT_EQ(0, response.vi().id());
}

TEST_F(NiScopeSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  scope::InitWithOptionsResponse init_response;
  call_init_with_options(kTestResourceName, kSimulatedOptionsString, kTestSessionName, &init_response);
  ni::hardware::grpc::Session session = init_response.vi();

  ::grpc::ClientContext context;
  scope::CloseRequest close_request;
  close_request.mutable_vi()->set_id(session.id());
  scope::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(NiScopeSessionTest, InvalidSession_CloseSession_NoErrorReported)
{
  ni::hardware::grpc::Session session;
  session.set_id(NULL);

  ::grpc::ClientContext context;
  scope::CloseRequest request;
  request.mutable_vi()->set_id(session.id());
  scope::CloseResponse response;
  ::grpc::Status status = GetStub()->Close(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
}

TEST_F(NiScopeSessionTest, ErrorFromDriver_GetErrorMessage_ReturnsUserErrorMessage)
{
  scope::InitWithOptionsResponse init_response;
  call_init_with_options(kInvalidResourceName, "", "", &init_response);
  EXPECT_EQ(kViErrorRsrcNFound, init_response.status());

  ni::hardware::grpc::Session session = init_response.vi();
  ::grpc::ClientContext context;
  scope::ErrorMessageRequest error_request;
  error_request.mutable_vi()->set_id(session.id());
  error_request.set_error_code(kViErrorRsrcNFound);
  scope::ErrorMessageResponse error_response;
  ::grpc::Status status = GetStub()->ErrorMessage(&context, error_request, &error_response);

  EXPECT_TRUE(status.ok());
  EXPECT_STREQ(kViErrorRsrcNFoundMessage, error_response.error_message().c_str());
}

}  // namespace system
}  // namespace tests
}  // namespace ni