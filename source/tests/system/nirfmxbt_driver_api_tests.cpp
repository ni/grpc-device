#include <gtest/gtest.h>

#include "device_server.h"
#include "niRFmxBT.h"
#include "nirfmxbt/nirfmxbt_client.h"

using namespace ::testing;
using namespace nirfmxbt_grpc;
namespace client = nirfmxbt_grpc::experimental::client;

namespace ni {
namespace tests {
namespace system {

const auto PXI_5663E = "5663E";

template <typename TResponse>
void EXPECT_SUCCESS(const TResponse& response)
{
  EXPECT_EQ(0, response.status());
}

class NiRFmxBTDriverApiTests : public Test {
 protected:
  NiRFmxBTDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiRFmxBT::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxBTDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  const std::unique_ptr<NiRFmxBT::Stub>& stub() const
  {
    return stub_;
  }

  template <typename TResponse>
  void EXPECT_SUCCESS(const nidevice_grpc::Session& session, const TResponse& response)
  {
    ni::tests::system::EXPECT_SUCCESS(response);
  }

  template <typename TService>
  std::unique_ptr<typename TService::Stub> create_stub()
  {
    return TService::NewStub(device_server_->InProcessChannel());
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiRFmxBT::Stub> stub_;
};

InitializeResponse init(const client::StubPtr& stub, const std::string& model)
{
  auto options = std::string("Simulate=1, DriverSetup=Model:") + model;
  return client::initialize(stub, "FakeDevice", options);
}

TEST_F(NiRFmxBTDriverApiTests, Init_Close_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.handle_out();
  EXPECT_SUCCESS(session, init_response);

  auto close_response = client::close(stub(), session, 0);

  ni::tests::system::EXPECT_SUCCESS(close_response);
}

}  // namespace system
}  // namespace tests
}  // namespace ni