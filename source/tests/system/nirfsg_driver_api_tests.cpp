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
    auto response = client::close(stub(), session());
    EXPECT_SUCCESS(response);
  }

  std::unique_ptr<rfsg::NiRFSG::Stub>& stub()
  {
    return nirfsg_stub_;
  }

  const nidevice_grpc::Session& session()
  {
    return *driver_session_;
  }

  void initialize_driver_session()
  {
    const auto DEVICE = "FakeDevice";
    const auto OPTIONS = "Simulate=1, DriverSetup=Model:5652; BoardType:PXI";
    auto response = client::init_with_options(
        stub(),
        DEVICE,
        false,
        false,
        OPTIONS);

    ASSERT_EQ(krfsgDriverApiSuccess, response.status());
    driver_session_ = std::make_unique<nidevice_grpc::Session>(response.vi());
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<::nidevice_grpc::Session> driver_session_;
  std::unique_ptr<rfsg::NiRFSG::Stub> nirfsg_stub_;
};

TEST_F(NiRFSGDriverApiTests, PerformSelfTest_Succeeds)
{
  auto response = client::self_test(stub(), session());
  EXPECT_SUCCESS(response);
  EXPECT_EQ(0, response.self_test_result());
  EXPECT_STREQ("Passed", response.self_test_message().c_str());
}

TEST_F(NiRFSGDriverApiTests, PerformReset_Succeeds)
{
  auto response = client::reset(stub(), session());
  EXPECT_SUCCESS(response);
  EXPECT_EQ(0, response.status());
}
}  // namespace system
}  // namespace tests
}  // namespace ni