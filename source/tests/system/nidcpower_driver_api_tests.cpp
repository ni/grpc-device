#include <gtest/gtest.h>

#include "nidcpower/nidcpower_library.h"
#include "nidcpower/nidcpower_service.h"

namespace ni {
namespace tests {
namespace system {

namespace dcpower = nidcpower_grpc;

const int kdcpowerDriverApiSuccess = 0;

class NiDCPowerDriverApiTest : public ::testing::Test {
 protected:
  NiDCPowerDriverApiTest()
  {
    ::grpc::ServerBuilder builder;
    session_repository_ = std::make_unique<nidevice_grpc::SessionRepository>();
    nidcpower_library_ = std::make_unique<dcpower::NiDCPowerLibrary>();
    nidcpower_service_ = std::make_unique<dcpower::NiDCPowerService>(nidcpower_library_.get(), session_repository_.get());
    builder.RegisterService(nidcpower_service_.get());

    server_ = builder.BuildAndStart();
    ResetStub();
  }

  virtual ~NiDCPowerDriverApiTest() {}

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
    nidcpower_stub_ = dcpower::NiDCPower::NewStub(channel_);
  }

  std::unique_ptr<dcpower::NiDCPower::Stub>& GetStub()
  {
    return nidcpower_stub_;
  }

  int GetSessionId()
  {
    return driver_session_->id();
  }

  void initialize_driver_session()
  {
    ::grpc::ClientContext context;
    dcpower::InitializeWithIndependentChannelsRequest request;
    request.set_resource_name("FakeDevice");
    request.set_option_string("Simulate=1, DriverSetup=Model:4147; BoardType:PXIe");
    request.set_session_name("");
    request.set_reset(false);
    dcpower::InitializeWithIndependentChannelsResponse response;

    ::grpc::Status status = GetStub()->InitializeWithIndependentChannels(&context, request, &response);
    driver_session_ = std::make_unique<nidevice_grpc::Session>(response.vi());

    ASSERT_TRUE(status.ok());
    ASSERT_EQ(kdcpowerDriverApiSuccess, response.status());
  }

  void close_driver_session()
  {
    ::grpc::ClientContext context;
    dcpower::CloseRequest request;
    request.mutable_vi()->set_id(driver_session_->id());
    dcpower::CloseResponse response;

    ::grpc::Status status = GetStub()->Close(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
  }

 private:
  std::shared_ptr<::grpc::Channel> channel_;
  std::unique_ptr<::nidevice_grpc::Session> driver_session_;
  std::unique_ptr<dcpower::NiDCPower::Stub> nidcpower_stub_;
  std::unique_ptr<nidevice_grpc::SessionRepository> session_repository_;
  std::unique_ptr<dcpower::NiDCPowerLibrary> nidcpower_library_;
  std::unique_ptr<dcpower::NiDCPowerService> nidcpower_service_;
  std::unique_ptr<::grpc::Server> server_;
};

TEST_F(NiDCPowerDriverApiTest, PerformSelfTest_CompletesSuccessfuly)
{
  ::grpc::ClientContext context;
  dcpower::SelfTestRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  dcpower::SelfTestResponse response;
  ::grpc::Status status = GetStub()->SelfTest(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
  EXPECT_EQ(0, response.self_test_result());
  EXPECT_LT(0, response.self_test_message().size());
}

TEST_F(NiDCPowerDriverApiTest, PerformReset_CompletesSuccessfuly)
{
  ::grpc::ClientContext context;
  dcpower::ResetRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  dcpower::ResetResponse response;
  ::grpc::Status status = GetStub()->Reset(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
}

}  // namespace system
}  // namespace tests
}  // namespace ni