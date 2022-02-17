#include <gtest/gtest.h>

#include "device_server.h"
#include "niRFmxLTE.h"
#include "nirfmxlte/nirfmxlte_client.h"
#include "rfmx_expect_macros.h"

using namespace ::testing;
using namespace nirfmxlte_grpc;
namespace client = nirfmxlte_grpc::experimental::client;

namespace ni {
namespace tests {
namespace system {
namespace {

constexpr auto PXI_5663E = "5663E";

class NiRFmxLTEDriverApiTests : public Test {
 protected:
  NiRFmxLTEDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiRFmxLTE::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxLTEDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  const std::unique_ptr<NiRFmxLTE::Stub>& stub() const
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
  std::unique_ptr<NiRFmxLTE::Stub> stub_;
};

InitializeResponse init(const client::StubPtr& stub, const std::string& model)
{
  auto options = std::string("Simulate=1, DriverSetup=Model:") + model;
  return client::initialize(stub, "FakeDevice", options);
}

TEST_F(NiRFmxLTEDriverApiTests, Init_Close_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.instrument();
  // TODO: use EXPECT_SUCCESS here when LTE has get_error and get_error_string
  EXPECT_RESPONSE_SUCCESS(init_response);

  auto close_response = client::close(stub(), session, 0);

  EXPECT_RESPONSE_SUCCESS(close_response);
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
