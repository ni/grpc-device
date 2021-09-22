#include <gmock/gmock.h>
#include <gtest/gtest.h>  // For EXPECT matchers.

#include "device_server.h"
#include "ivi.h"  // VI_SUCCESS
#include "niRFSAErrors.h"
#include "nirfsa/nirfsa_client.h"

using namespace ::testing;
using namespace nirfsa_grpc;
namespace client = nirfsa_grpc::experimental::client;

namespace ni {
namespace tests {
namespace system {
class NiRFSADriverApiTests : public Test {
 protected:
  NiRFSADriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiRFSA::NewStub(device_server_->InProcessChannel()))
  {
  }

  const std::unique_ptr<NiRFSA::Stub>& stub() const
  {
    return stub_;
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiRFSA::Stub> stub_;
};

template <typename TResponse>
void EXPECT_SUCCESS(const TResponse& response)
{
  EXPECT_EQ(VI_SUCCESS, response.status());
}

template <typename TResponse>
void EXPECT_SUCCESS(const ::grpc::Status& status, const TResponse& response)
{
  EXPECT_SUCCESS(response);
  EXPECT_EQ(::grpc::Status::OK.error_code(), status.error_code());
}

TEST_F(NiRFSADriverApiTests, Init_Close_Succeeds)
{
  auto init_response = client::init_with_options(stub(), "FakeDevice", false, false, "Simulate=1, DriverSetup=Model:5663E");

  auto close_response = client::close(stub(), init_response.vi());

  EXPECT_SUCCESS(init_response);
  EXPECT_SUCCESS(close_response);
}
}  // namespace system
}  // namespace tests
}  // namespace ni
