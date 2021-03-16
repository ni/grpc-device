#include <gtest/gtest.h>

#include "niswitch/niswitch_library.h"
#include "niswitch/niswitch_service.h"

namespace ni {
namespace tests {
namespace system {

namespace niswitch = grpc::niswitch;

const int kSwitchDriverApiSuccess = 0;

class NiSwitchDriverApiTest : public ::testing::Test {
 protected:
  NiSwitchDriverApiTest()
  {
    ::grpc::ServerBuilder builder;
    session_repository_ = std::make_unique<grpc::nidevice::SessionRepository>();
    niswitch_library_ = std::make_unique<niswitch::NiSwitchLibrary>();
    niswitch_service_ = std::make_unique<niswitch::NiSwitchService>(niswitch_library_.get(), session_repository_.get());
    builder.RegisterService(niswitch_service_.get());

    server_ = builder.BuildAndStart();
    ResetStub();
  }

  virtual ~NiSwitchDriverApiTest() {}

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
    niswitch_stub_ = niswitch::NiSwitch::NewStub(channel_);
  }

  std::unique_ptr<niswitch::NiSwitch::Stub>& GetStub()
  {
    return niswitch_stub_;
  }

  int GetSessionId()
  {
    return driver_session_->id();
  }

  void expect_api_success(int error_status)
  {
    EXPECT_EQ(kSwitchDriverApiSuccess, error_status) << get_error_message(error_status);
  }

  std::string get_error_message(int error_status)
  {
    ::grpc::ClientContext context;
    niswitch::ErrorMessageRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_error_code(error_status);
    niswitch::ErrorMessageResponse response;

    ::grpc::Status status = GetStub()->ErrorMessage(&context, request, &response);
    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kSwitchDriverApiSuccess, response.status());
    return response.error_message();
  }

void initialize_driver_session()
  {
    ::grpc::ClientContext context;
    niswitch::InitWithTopologyRequest request;
    request.set_resource_name("Switch1");
    request.set_topology("2529/2-Wire Dual 4x16 Matrix");
    request.set_session_name("");
    request.set_reset_device(false);
    request.set_simulate(true);
    niswitch::InitWithTopologyResponse response;

    ::grpc::Status status = GetStub()->InitWithTopology(&context, request, &response);
    driver_session_ = std::make_unique<grpc::nidevice::Session>(response.vi());

    ASSERT_TRUE(status.ok());
    ASSERT_EQ(kSwitchDriverApiSuccess, response.status());
  }

  void close_driver_session()
  {
    ::grpc::ClientContext context;
    niswitch::CloseRequest request;
    request.mutable_vi()->set_id(driver_session_->id());
    niswitch::CloseResponse response;

    ::grpc::Status status = GetStub()->Close(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  private:
  std::shared_ptr<::grpc::Channel> channel_;
  std::unique_ptr<::grpc::nidevice::Session> driver_session_;
  std::unique_ptr<niswitch::NiSwitch::Stub> niswitch_stub_;
  std::unique_ptr<grpc::nidevice::SessionRepository> session_repository_;
  std::unique_ptr<niswitch::NiSwitchLibrary> niswitch_library_;
  std::unique_ptr<niswitch::NiSwitchService> niswitch_service_;
  std::unique_ptr<::grpc::Server> server_;
};

TEST_F(NiSwitchDriverApiTest, NiSwitchSelfTest_SendRequest_SelfTestCompletesSuccessfully)
{
  ::grpc::ClientContext context;
  niswitch::SelfTestRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  niswitch::SelfTestResponse response;

  ::grpc::Status status = GetStub()->SelfTest(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
  EXPECT_EQ(0, response.self_test_result());
  EXPECT_LT(0, strlen(response.self_test_message().c_str()));
}

TEST_F(NiSwitchDriverApiTest, NiSwitchReset_SendRequest_ResetCompletesSuccessfully)
{
  ::grpc::ClientContext context;
  niswitch::ResetRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  niswitch::ResetResponse response;

  ::grpc::Status status = GetStub()->Reset(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
}
}  // namespace system
}  // namespace tests
}  // namespace ni