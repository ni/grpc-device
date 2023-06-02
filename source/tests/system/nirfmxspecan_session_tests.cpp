#include <gmock/gmock.h>

#include "device_server.h"
#include "nirfmxspecan/nirfmxspecan_client.h"
#include "tests/utilities/test_helpers.h"

namespace ni {
namespace tests {
namespace system {

namespace rfmxspecan = nirfmxspecan_grpc;
using ::testing::IsEmpty;

const int kInvalidRsrc = -200220;
const int kInvalidRFmxSpecAnSession = -380598;
const char* kRFmxSpecAnErrorResourceNotFoundMessage = "-200220: Device identifier is invalid.";
const char* kRFmxSpecAnTestRsrc = "FakeDevice";
const char* kRFmxSpecAnOptionsString = "Simulate=1, DriverSetup=Model:5663E";
const char* kRFmxSpecAnTestSession = "SessionName";
const char* kRFmxSpecAnTestInvalidRsrc = "";

class NiRFmxSpecAnSessionTest : public ::testing::Test {
 protected:
  NiRFmxSpecAnSessionTest()
      : device_server_(DeviceServerInterface::Singleton()),
        nirfmxspecan_stub_(rfmxspecan::NiRFmxSpecAn::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxSpecAnSessionTest() {}

  std::unique_ptr<rfmxspecan::NiRFmxSpecAn::Stub>& GetStub()
  {
    return nirfmxspecan_stub_;
  }

  ::grpc::Status call_initialize(const char* resource_name, const char* option_string, const char* session_name, rfmxspecan::InitializeResponse* response)
  {
    ::grpc::ClientContext context;
    rfmxspecan::InitializeRequest request;
    request.set_resource_name(resource_name);
    request.set_option_string(option_string);
    request.set_session_name(session_name);

    ::grpc::Status status = GetStub()->Initialize(&context, request, response);
    nidevice_grpc::experimental::client::raise_if_error(status, context);
    return status;
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<rfmxspecan::NiRFmxSpecAn::Stub> nirfmxspecan_stub_;
};

TEST_F(NiRFmxSpecAnSessionTest, InitializeSessionWithDeviceAndSessionName_CreatesDriverSession)
{
  rfmxspecan::InitializeResponse response;
  ::grpc::Status status = call_initialize(kRFmxSpecAnTestRsrc, kRFmxSpecAnOptionsString, kRFmxSpecAnTestSession, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE("", response.instrument().name());
}

TEST_F(NiRFmxSpecAnSessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  rfmxspecan::InitializeResponse response;
  ::grpc::Status status = call_initialize(kRFmxSpecAnTestRsrc, kRFmxSpecAnOptionsString, "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE("", response.instrument().name());
}

TEST_F(NiRFmxSpecAnSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  rfmxspecan::InitializeResponse init_response;
  call_initialize(kRFmxSpecAnTestRsrc, kRFmxSpecAnOptionsString, kRFmxSpecAnTestSession, &init_response);

  nidevice_grpc::Session session = init_response.instrument();
  ::grpc::ClientContext context;
  rfmxspecan::CloseRequest close_request;
  close_request.mutable_instrument()->set_name(session.name());
  close_request.set_force_destroy(false);
  rfmxspecan::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
  EXPECT_THAT(init_response.error_message(), IsEmpty());
}

// Note: the error_message is included in the Init response because querying for errors
// afterwards will fail to get the error_message if the request is handled on a different thread.
TEST_F(NiRFmxSpecAnSessionTest, InitWithErrorFromDriver_ReturnsDriverErrorWithUserErrorMessage)
{
  EXPECT_THROW_DRIVER_ERROR_WITH_SUBSTR({
    rfmxspecan::InitializeResponse init_response;
    call_initialize(kRFmxSpecAnTestInvalidRsrc, "", "", &init_response);
  }, kInvalidRsrc, kRFmxSpecAnErrorResourceNotFoundMessage);
}

TEST_F(NiRFmxSpecAnSessionTest, InitWithErrorFromDriver_ReinitSuccessfully_ErrorMessageIsEmpty)
{
  EXPECT_THROW({
    try {
      rfmxspecan::InitializeResponse failed_init_response;
      call_initialize(kRFmxSpecAnTestInvalidRsrc, "", "", &failed_init_response);
    }
    catch (const nidevice_grpc::experimental::client::grpc_driver_error& ex) {
      EXPECT_EQ(::grpc::StatusCode::UNKNOWN, ex.StatusCode());
      EXPECT_STREQ(kRFmxSpecAnErrorResourceNotFoundMessage, ex.what());
      throw;
    }
  }, nidevice_grpc::experimental::client::grpc_driver_error);

  rfmxspecan::InitializeResponse successful_init_response;
  auto status_two = call_initialize(kRFmxSpecAnTestRsrc, kRFmxSpecAnOptionsString, kRFmxSpecAnTestSession, &successful_init_response);

  EXPECT_EQ(::grpc::StatusCode::OK, status_two.error_code());
  EXPECT_THAT(status_two.error_message(), IsEmpty());
  EXPECT_THAT(successful_init_response.error_message(), IsEmpty());
}

TEST_F(NiRFmxSpecAnSessionTest, InvalidSession_CloseSession_ReturnsInvalidSessionError)
{
  nidevice_grpc::Session session;
  session.set_name("");

  EXPECT_THROW_DRIVER_ERROR({
    ::grpc::ClientContext context;
    rfmxspecan::CloseRequest request;
    request.mutable_instrument()->set_name(session.name());
    request.set_force_destroy(false);
    rfmxspecan::CloseResponse response;
    ::grpc::Status status = GetStub()->Close(&context, request, &response);
    nidevice_grpc::experimental::client::raise_if_error(status, context);
  }, kInvalidRFmxSpecAnSession);
}

}  // namespace system
}  // namespace tests
}  // namespace ni
