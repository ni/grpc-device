#include <gtest/gtest.h>

#include "device_server.h"
#include "enumerate_devices.h"
#include "nisync/nisync_client.h"

namespace ni {
namespace tests {
namespace system {

namespace nisync = nisync_grpc;

static const int kSyncDeviceNotFound = -1074118634;
static const char* kTestSessionName = "TestSession";
static const char* kEmptySessionName = "";
static const char* kInvalidRsrcName = "InvalidName";

class NiSyncSessionTest : public ::testing::Test {
 protected:
  std::string test_resource_name;

  NiSyncSessionTest()
      : device_server_(DeviceServerInterface::Singleton()),
        nisync_stub_(nisync::NiSync::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  void SetUp() override
  {
    for (const auto& device : EnumerateDevices()) {
      if ((device.model() == "NI PXI-6683H") || (device.model() == "NI PXIe-6674T")) {
        test_resource_name = device.name();
        break;
      }
    }

    if (test_resource_name.empty()) {
      GTEST_SKIP() << "No device found";
    }
  }

  virtual ~NiSyncSessionTest() {}

  std::unique_ptr<nisync::NiSync::Stub>& GetStub()
  {
    return nisync_stub_;
  }

  ::grpc::Status call_init(const char* resource_name, const char* session_name, nisync::InitResponse* response)
  {
    ::grpc::ClientContext context;
    nisync::InitRequest request;
    request.set_resource_name(resource_name);
    request.set_session_name(session_name);
    request.set_reset_device(false);

    ::grpc::Status status = GetStub()->Init(&context, request, response);
    return status;
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<nisync::NiSync::Stub> nisync_stub_;
};

TEST_F(NiSyncSessionTest, InitializeSessionWithDeviceAndSessionName_CreatesDriverSession)
{
  nisync::InitResponse response;
  ::grpc::Status status = call_init(test_resource_name.c_str(), kTestSessionName, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE("", response.vi().name());
}

TEST_F(NiSyncSessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  nisync::InitResponse response;
  ::grpc::Status status = call_init(test_resource_name.c_str(), kEmptySessionName, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE("", response.vi().name());
}

TEST_F(NiSyncSessionTest, InitializeSessionWithoutDevice_ReturnsDriverError)
{
  nisync::InitResponse response;
  ::grpc::Status status = call_init(kInvalidRsrcName, kEmptySessionName, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kSyncDeviceNotFound, response.status());
  EXPECT_EQ("", response.vi().name());
}

TEST_F(NiSyncSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  nisync::InitResponse init_response;
  call_init(test_resource_name.c_str(), kEmptySessionName, &init_response);
  nidevice_grpc::Session session = init_response.vi();
  EXPECT_EQ(0, init_response.status());

  ::grpc::ClientContext context;
  nisync::CloseRequest close_request;
  close_request.mutable_vi()->set_name(session.name());
  nisync::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(NiSyncSessionTest, InvalidSession_CloseSession_NoErrorReported)
{
  nidevice_grpc::Session session;
  session.set_name("");

  ::grpc::ClientContext context;
  nisync::CloseRequest request;
  request.mutable_vi()->set_name(session.name());
  nisync::CloseResponse response;
  ::grpc::Status status = GetStub()->Close(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
}

}  // namespace system
}  // namespace tests
}  // namespace ni
