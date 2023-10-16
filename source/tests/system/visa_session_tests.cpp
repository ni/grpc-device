#include "device_server.h"
#include "tests/utilities/test_helpers.h"
#include "visa/visa_client.h"

namespace ni {
namespace tests {
namespace system {

namespace visa = visa_grpc;

const int kInvalidRsrc = -1073807343;
const int kInvalidVisaSessionWarning = 1073676418;
const char* kVisaErrorInstrumentDescriptorNotFoundMessage = "Insufficient location information or the device or resource is not present in the system.";
const char* kInstrumentDescriptor = "TCPIP::www.ni.com::80::SOCKET";
const char* kVisaTestSession = "SessionName";
const char* kVisaTestInvalidInstrumentDescriptor = "FOO::BAR";

class VisaSessionTest : public ::testing::Test {
 protected:
  VisaSessionTest()
      : device_server_(DeviceServerInterface::Singleton()),
        visa_stub_(visa::Visa::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~VisaSessionTest() {}

  std::unique_ptr<visa::Visa::Stub>& GetStub()
  {
    return visa_stub_;
  }

  ::grpc::Status call_open(const char* instrument_descriptor, visa::LockState access_mode, const char* session_name, uint32_t open_timeout, visa::OpenResponse* response)
  {
    ::grpc::ClientContext context;
    visa::OpenRequest request;
    request.set_instrument_descriptor(instrument_descriptor);
    request.set_access_mode(access_mode);
    request.set_session_name(session_name);
    request.set_open_timeout(open_timeout);

    ::grpc::Status status = GetStub()->Open(&context, request, response);
    nidevice_grpc::experimental::client::raise_if_error(status, context);
    return status;
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<visa::Visa::Stub> visa_stub_;
};

TEST_F(VisaSessionTest, OpenSessionWithInstrumentDescriptor_CreatesDriverSession)
{
  visa::OpenResponse response;
  ::grpc::Status status = call_open(kInstrumentDescriptor, visa::LOCK_STATE_NO_LOCK, kVisaTestSession, 0, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_EQ(kVisaTestSession, response.vi().name());
}

TEST_F(VisaSessionTest, OpenSessionWithInstrumentDescriptorAndNoSessionName_CreatesDriverSession)
{
  visa::OpenResponse response;
  ::grpc::Status status = call_open(kInstrumentDescriptor, visa::LOCK_STATE_NO_LOCK, "", 0, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE("", response.vi().name());
}

TEST_F(VisaSessionTest, OpenSession_CloseSession_ClosesDriverSession)
{
  visa::OpenResponse open_response;
  call_open(kInstrumentDescriptor, visa::LOCK_STATE_NO_LOCK, kVisaTestSession, 0, &open_response);

  nidevice_grpc::Session session = open_response.vi();
  ::grpc::ClientContext context;
  visa::CloseRequest close_request;
  close_request.mutable_vi()->set_name(session.name());
  visa::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(VisaSessionTest, OpenWithErrorFromDriver_ReturnsDriverErrorWithUserErrorMessage)
{
  EXPECT_THROW_DRIVER_ERROR_WITH_SUBSTR(
    {
      visa::OpenResponse init_response;
      call_open(kVisaTestInvalidInstrumentDescriptor, visa::LOCK_STATE_NO_LOCK, "", 0, &init_response);
    },
    kInvalidRsrc,
    kVisaErrorInstrumentDescriptorNotFoundMessage);
}

TEST_F(VisaSessionTest, OpenWithErrorFromDriver_ReturnsDriverErrorWithResourceDescriptor)
{
  EXPECT_THROW_DRIVER_ERROR_WITH_SUBSTR(
    {
      visa::OpenResponse init_response;
      call_open(kVisaTestInvalidInstrumentDescriptor, visa::LOCK_STATE_NO_LOCK, "", 0, &init_response);
    },
    kInvalidRsrc,
    kVisaTestInvalidInstrumentDescriptor);
}

TEST_F(VisaSessionTest, InvalidSession_CloseSession_ReturnsWarning)
{
  nidevice_grpc::Session session;
  session.set_name("");

  ::grpc::ClientContext context;
  visa::CloseRequest request;
  request.mutable_vi()->set_name(session.name());
  visa::CloseResponse response;
  auto status = GetStub()->Close(&context, request, &response);
  EXPECT_EQ(kInvalidVisaSessionWarning, response.status());
}

}  // namespace system
}  // namespace tests
}  // namespace ni
