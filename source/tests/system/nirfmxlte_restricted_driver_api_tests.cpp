#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <thread>
#include <tuple>

#include "device_server.h"
#include "nirfmxinstr/nirfmxinstr_client.h"
#include "nirfmxlte/nirfmxlte_client.h"
#include "nirfmxlte_restricted/nirfmxlte_restricted_client.h"
#include "rfmx_macros.h"
#include "waveform_helpers.h"

using namespace nirfmxlte_grpc;
using namespace nirfmxlte_restricted_grpc;
namespace client = nirfmxlte_grpc::experimental::client;
namespace instr_client = nirfmxinstr_grpc::experimental::client;
namespace restricted_client = nirfmxlte_restricted_grpc::experimental::client;
namespace pb = google::protobuf;
using namespace ::testing;

namespace ni {
namespace tests {
namespace system {
namespace {

constexpr auto PXI_5841 = "5841";

class NiRFmxLTERestrictedDriverApiTests : public ::testing::Test {
 protected:
  NiRFmxLTERestrictedDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        nirfmxlte_stub_(NiRFmxLTE::NewStub(device_server_->InProcessChannel())),
        nirfmxlte_restricted_stub_(NiRFmxLTERestricted::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }
  virtual ~NiRFmxLTERestrictedDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  template <typename TService>
  std::unique_ptr<typename TService::Stub> create_stub()
  {
    return TService::NewStub(device_server_->InProcessChannel());
  }

  std::unique_ptr<NiRFmxLTE::Stub>& stub()
  {
    return nirfmxlte_stub_;
  }

  std::unique_ptr<NiRFmxLTERestricted::Stub>& restricted_stub()
  {
    return nirfmxlte_restricted_stub_;
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiRFmxLTE::Stub> nirfmxlte_stub_;
  std::unique_ptr<NiRFmxLTERestricted::Stub> nirfmxlte_restricted_stub_;
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
