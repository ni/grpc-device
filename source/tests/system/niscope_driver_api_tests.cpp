#include <gtest/gtest.h>

#include "niscope/niscope_library.h"
#include "niscope/niscope_service.h"

namespace ni {
namespace tests {
namespace system {

namespace scope = grpc::niscope;

const int kScopeDriverApiSuccess = 0;

class NiScopeDriverApiTest : public ::testing::Test {
 protected:
  NiScopeDriverApiTest()
  {
    ::grpc::ServerBuilder builder;
    session_repository_ = std::make_unique<grpc::nidevice::SessionRepository>();
    niscope_library_ = std::make_unique<scope::NiScopeLibrary>();
    niscope_service_ = std::make_unique<scope::NiScopeService>(niscope_library_.get(), session_repository_.get());
    builder.RegisterService(niscope_service_.get());

    server_ = builder.BuildAndStart();
    ResetStub();
  }

  virtual ~NiScopeDriverApiTest() {}

  void SetUp() override
  {
    initialize_driver_session();
  }

  void TearDown() override
  {
    close_driver_session();
  }

  void ResetStub()
  {
    channel_ = server_->InProcessChannel(::grpc::ChannelArguments());
    niscope_stub_ = scope::NiScope::NewStub(channel_);
  }

  std::unique_ptr<scope::NiScope::Stub>& GetStub()
  {
    return niscope_stub_;
  }

  int GetSessionId()
  {
    return driver_session_->id();
  }

  void initialize_driver_session()
  {
    ::grpc::ClientContext context;
    scope::InitWithOptionsRequest request;
    request.set_resource_name("FakeDevice");
    request.set_option_string("Simulate=1, DriverSetup=Model:5164; BoardType:PXIe");
    request.set_session_name("");
    request.set_reset_device(false);
    request.set_id_query(false);
    scope::InitWithOptionsResponse response;

    ::grpc::Status status = GetStub()->InitWithOptions(&context, request, &response);
    driver_session_ = std::make_unique<grpc::nidevice::Session>(response.vi());

    ASSERT_TRUE(status.ok());
    ASSERT_EQ(kScopeDriverApiSuccess, response.status());
  }

  void close_driver_session()
  {
    ::grpc::ClientContext context;
    scope::CloseRequest request;
    request.mutable_vi()->set_id(driver_session_->id());
    scope::CloseResponse response;

    ::grpc::Status status = GetStub()->Close(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kScopeDriverApiSuccess, response.status());
  }

 private:
  std::shared_ptr<::grpc::Channel> channel_;
  std::unique_ptr<::grpc::nidevice::Session> driver_session_;
  std::unique_ptr<scope::NiScope::Stub> niscope_stub_;
  std::unique_ptr<grpc::nidevice::SessionRepository> session_repository_;
  std::unique_ptr<scope::NiScopeLibrary> niscope_library_;
  std::unique_ptr<scope::NiScopeService> niscope_service_;
  std::unique_ptr<::grpc::Server> server_;
};

TEST_F(NiScopeDriverApiTest, NiScopeSelfTest_SendRequest_SelfTestCompletesSuccessfully)
{
  ::grpc::ClientContext context;
  scope::SelfTestRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  scope::SelfTestResponse response;

  ::grpc::Status status = GetStub()->SelfTest(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kScopeDriverApiSuccess, response.status());
  EXPECT_EQ(0, response.self_test_result());
  EXPECT_LT(0, strlen(response.self_test_message().c_str()));
}

TEST_F(NiScopeDriverApiTest, NiScopeReset_SendRequest_ResetCompletesSuccessfully)
{
  ::grpc::ClientContext context;
  scope::ResetRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  scope::ResetResponse response;

  ::grpc::Status status = GetStub()->Reset(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kScopeDriverApiSuccess, response.status());
}

}  // namespace system
}  // namespace tests
}  // namespace ni