#include <gtest/gtest.h>

#include "device_server.h"
#include "nirfmxdemod/nirfmxdemod_client.h"
#include "rfmx_macros.h"

using namespace ::testing;
using namespace nirfmxdemod_grpc;
namespace client = nirfmxdemod_grpc::experimental::client;

namespace ni {
namespace tests {
namespace system {
namespace {

const auto PXI_5663E = "5663E";

class NiRFmxDemodDriverApiTests : public Test {
 protected:
  NiRFmxDemodDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiRFmxDemod::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxDemodDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  const std::unique_ptr<NiRFmxDemod::Stub>& stub() const
  {
    return stub_;
  }

  template <typename TService>
  std::unique_ptr<typename TService::Stub> create_stub()
  {
    return TService::NewStub(device_server_->InProcessChannel());
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiRFmxDemod::Stub> stub_;
};

InitializeResponse init(const client::StubPtr& stub, const std::string& model)
{
  auto options = std::string("Simulate=1, DriverSetup=Model:") + model;
  return client::initialize(stub, "FakeDevice", options);
}

nidevice_grpc::Session init_session(const client::StubPtr& stub, const std::string& model)
{
  auto response = init(stub, model);
  auto session = response.instrument();
  EXPECT_RESPONSE_SUCCESS(response);
  return session;
}

TEST_F(NiRFmxDemodDriverApiTests, Init_Close_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  auto close_response = client::close(stub(), session, 0);

  EXPECT_RESPONSE_SUCCESS(close_response);
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
