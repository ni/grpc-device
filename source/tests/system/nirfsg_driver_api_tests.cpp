#include <gtest/gtest.h>

#include "device_server.h"
#include "nirfsg/nirfsg_client.h"
#include "nirfsg/nirfsg_service.h"

namespace ni {
namespace tests {
namespace system {

namespace rfsg = nirfsg_grpc;
namespace client = nirfsg_grpc::experimental::client;
namespace pb = google::protobuf;
using namespace ::testing;

const auto PXI_5652 = "5652";

const int krfsgDriverApiSuccess = 0;

template <typename TResponse>
void EXPECT_SUCCESS(const TResponse& response)
{
  EXPECT_EQ(krfsgDriverApiSuccess, response.status());
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

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  std::unique_ptr<rfsg::NiRFSG::Stub>& stub()
  {
    return nirfsg_stub_;
  }

  void check_error(const nidevice_grpc::Session& session)
  {
    auto response = client::get_error(stub(), session);
    EXPECT_EQ("", std::string(response.error_description().c_str()));
  }

  template <typename TResponse>
  void EXPECT_SUCCESS(const nidevice_grpc::Session& session, const TResponse& response)
  {
    ni::tests::system::EXPECT_SUCCESS(response);
    check_error(session);
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<rfsg::NiRFSG::Stub> nirfsg_stub_;
};

rfsg::InitWithOptionsResponse init(const client::StubPtr& stub, const std::string& model)
{
  auto options = std::string("Simulate=1, DriverSetup=Model:") + model;
  return client::init_with_options(stub, "FakeDevice", false, false, options);
}

nidevice_grpc::Session init_session(const client::StubPtr& stub, const std::string& model)
{
  auto response = init(stub, model);
  auto session = response.vi();
  EXPECT_SUCCESS(response);
  return session;
}

TEST_F(NiRFSGDriverApiTests, PerformSelfTest_Succeeds)
{
  auto session = init_session(stub(), PXI_5652);
  auto response = client::self_test(stub(), session);
  EXPECT_SUCCESS(session, response);
  EXPECT_EQ(0, response.self_test_result());
  EXPECT_STREQ("Passed", response.self_test_message().c_str());
}

TEST_F(NiRFSGDriverApiTests, PerformReset_Succeeds)
{
  auto session = init_session(stub(), PXI_5652);
  auto response = client::reset(stub(), session);
  EXPECT_SUCCESS(session, response);
  EXPECT_EQ(0, response.status());
}
}  // namespace system
}  // namespace tests
}  // namespace ni