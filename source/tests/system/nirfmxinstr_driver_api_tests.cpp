#include <gmock/gmock.h>
#include <gtest/gtest.h>  // For EXPECT matchers.

#include "device_server.h"
#include "niRFmxInstr.h"
#include "nirfmxinstr/nirfmxinstr_client.h"
#include "nirfsa/nirfsa_client.h"

using namespace ::testing;
using namespace nirfmxinstr_grpc;
namespace client = nirfmxinstr_grpc::experimental::client;
namespace nirfsa_client = nirfsa_grpc::experimental::client;
namespace pb = google::protobuf;

namespace ni {
namespace tests {
namespace system {
namespace {

const auto PXI_5663E = "5663E";

template <typename TResponse>
void EXPECT_SUCCESS(const TResponse& response)
{
  EXPECT_EQ(0, response.status());
}

class NiRFmxInstrDriverApiTests : public Test {
 protected:
  NiRFmxInstrDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiRFmxInstr::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxInstrDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  const std::unique_ptr<NiRFmxInstr::Stub>& stub() const
  {
    return stub_;
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

  template <typename TService>
  std::unique_ptr<typename TService::Stub> create_stub()
  {
    return TService::NewStub(device_server_->InProcessChannel());
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiRFmxInstr::Stub> stub_;
};

InitializeResponse init(const client::StubPtr& stub, const std::string& model)
{
  auto options = std::string("Simulate=1, DriverSetup=Model:") + model;
  return client::initialize(stub, "FakeDevice", options);
}

TEST_F(NiRFmxInstrDriverApiTests, Init_Close_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  auto close_response = client::close(stub(), session, 0);

  // Don't check_error because this can report stale errors from previous tests.
  ni::tests::system::EXPECT_SUCCESS(close_response);
}

TEST_F(NiRFmxInstrDriverApiTests, GetNIRFSASession_SelfTest_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  const auto rfsa_response = client::get_nirfsa_session(stub(), session);
  EXPECT_SUCCESS(session, rfsa_response);

  auto rfsa_stub = create_stub<nirfsa_grpc::NiRFSA>();
  ni::tests::system::EXPECT_SUCCESS(nirfsa_client::self_test(rfsa_stub, rfsa_response.ni_rfsa_session()));
}

TEST_F(NiRFmxInstrDriverApiTests, InitializeFromNIRFSA_SelfCalibrate_Succeeds)
{
  auto rfsa_stub = create_stub<nirfsa_grpc::NiRFSA>();
  auto init_rfsa_response = nirfsa_client::init_with_options(rfsa_stub, "Sim", false, false, "Simulate=1, DriverSetup=Model:5663E");
  ni::tests::system::EXPECT_SUCCESS(init_rfsa_response);
  auto init_response = client::initialize_from_nirfsa_session(stub(), init_rfsa_response.vi());
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  client::self_calibrate(stub(), session, "", 0);
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni