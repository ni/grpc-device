#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <thread>
#include <tuple>

#include "device_server.h"
#include "nirfmxinstr/nirfmxinstr_client.h"
#include "nirfmxnr/nirfmxnr_client.h"
#include "nirfmxnr_restricted/nirfmxnr_restricted_client.h"
#include "rfmx_macros.h"
#include "waveform_helpers.h"

using namespace nirfmxnr_grpc;
using namespace nirfmxnr_restricted_grpc;
namespace client = nirfmxnr_grpc::experimental::client;
namespace instr_client = nirfmxinstr_grpc::experimental::client;
namespace restricted_client = nirfmxnr_restricted_grpc::experimental::client;
namespace pb = google::protobuf;
using namespace ::testing;

namespace ni {
namespace tests {
namespace system {
namespace {

constexpr auto PXI_5663E = "5663E";

class NiRFmxNRRestrictedDriverApiTests : public ::testing::Test {
 protected:
  NiRFmxNRRestrictedDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        nirfmxnr_stub_(NiRFmxNR::NewStub(device_server_->InProcessChannel())),
        nirfmxnr_restricted_stub_(NiRFmxNRRestricted::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }
  virtual ~NiRFmxNRRestrictedDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  template <typename TService>
  std::unique_ptr<typename TService::Stub> create_stub()
  {
    return TService::NewStub(device_server_->InProcessChannel());
  }

  std::unique_ptr<NiRFmxNR::Stub>& stub()
  {
    return nirfmxnr_stub_;
  }

  std::unique_ptr<NiRFmxNRRestricted::Stub>& restricted_stub()
  {
    return nirfmxnr_restricted_stub_;
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiRFmxNR::Stub> nirfmxnr_stub_;
  std::unique_ptr<NiRFmxNRRestricted::Stub> nirfmxnr_restricted_stub_;
};

InitializeResponse init(const client::StubPtr& stub, const std::string& model, const std::string& resource_name)
{
  auto options = std::string("Simulate=1, DriverSetup=Model:") + model;
  return client::initialize(stub, resource_name, options);
}

nidevice_grpc::Session init_session(const client::StubPtr& stub, const std::string& model, const std::string& resource_name)
{
  auto response = init(stub, model, resource_name);
  auto session = response.instrument();
  EXPECT_RESPONSE_SUCCESS(response);
  return session;
}

nidevice_grpc::Session init_session(const client::StubPtr& stub, const std::string& model)
{
  return init_session(stub, model, "FakeDevice");
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
