#include <gtest/gtest.h>

#include "device_server.h"
#include "nirfsg/nirfsg_client.h"
#include "nirfsg/nirfsg_service.h"

namespace ni {
namespace tests {
namespace system {

namespace rfsg = nirfsg_grpc;
namespace client = nirfsg_grpc::experimental::client;
using namespace ::testing;

const int krfsgDriverApiSuccess = 0;

class NiRFSGDriverApiTests : public ::testing::Test {
 protected:
  NiRFSGDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        nirfsg_stub_(rfsg::NiRFSG::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }
  virtual ~NiRFSGDriverApiTests() {}

  void SetUp() override
  {
    initialize_driver_session();
  }

  void TearDown() override
  {
    close_driver_session();
  }

  std::unique_ptr<rfsg::NiRFSG::Stub>& GetStub()
  {
    return nirfsg_stub_;
  }

  int GetSessionId()
  {
    return driver_session_->id();
  }

  void initialize_driver_session()
  {
    const auto DEVICE = "FakeDevice";
    const auto OPTIONS = "Simulate=1, DriverSetup=Model:5652; BoardType:PXI";
    auto response = client::init_with_options(
        GetStub(),
        DEVICE,
        false,
        false,
        OPTIONS);

    ASSERT_EQ(krfsgDriverApiSuccess, response.status());
    driver_session_ = std::make_unique<nidevice_grpc::Session>(response.vi());
  }

  void close_driver_session()
  {
    ::grpc::ClientContext context;
    rfsg::CloseRequest request;
    request.mutable_vi()->set_id(driver_session_->id());
    rfsg::CloseResponse response;

    ::grpc::Status status = GetStub()->Close(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(krfsgDriverApiSuccess, response.status());
  }

  ::grpc::Status self_test(rfsg::SelfTestResponse& response)
  {
    ::grpc::ClientContext context;
    rfsg::SelfTestRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    return GetStub()->SelfTest(&context, request, &response);
  }

  ::grpc::Status reset(rfsg::ResetResponse& response)
  {
    ::grpc::ClientContext context;
    rfsg::ResetRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    return GetStub()->Reset(&context, request, &response);
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<::nidevice_grpc::Session> driver_session_;
  std::unique_ptr<rfsg::NiRFSG::Stub> nirfsg_stub_;
};

template <typename TResponse>
void EXPECT_SUCCESS(const TResponse& response)
{
  EXPECT_EQ(krfsgDriverApiSuccess, response.status());
}

template <typename TResponse>
void EXPECT_SUCCESS(const ::grpc::Status& status, const TResponse& response)
{
  EXPECT_SUCCESS(response);
  EXPECT_EQ(::grpc::Status::OK.error_code(), status.error_code());
}

TEST_F(NiRFSGDriverApiTests, PerformSelfTest_Succeeds)
{
  rfsg::SelfTestResponse response;
  auto status = self_test(response);

  EXPECT_SUCCESS(status, response);
  EXPECT_EQ(0, response.self_test_result());
  EXPECT_STREQ("Passed", response.self_test_message().c_str());
}

TEST_F(NiRFSGDriverApiTests, PerformReset_Succeeds)
{
  rfsg::ResetResponse response;
  auto status = reset(response);

  EXPECT_SUCCESS(status, response);
  EXPECT_EQ(0, response.status());
}
}  // namespace system
}  // namespace tests
}  // namespace ni