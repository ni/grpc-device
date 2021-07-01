#include <gtest/gtest.h>

#include "device_server.h"
#include "nidaqmx/nidaqmx_service.h"

using namespace nidaqmx_grpc;

namespace ni {
namespace tests {
namespace system {
class NiDAQmxSessionTests : public ::testing::Test {
 protected:
  NiDAQmxSessionTests()
      : device_server_(DeviceServerInterface::Singleton()),
        nidaqmx_stub_(NiDAQmx::NewStub(device_server_->InProcessChannel()))
  {
  }
  virtual ~NiDAQmxSessionTests() {}

  ::grpc::Status create_task(const std::string& name, CreateTaskResponse& response)
  {
    ::grpc::ClientContext context;
    CreateTaskRequest request;
    request.set_session_name(name);
    return stub()->CreateTask(&context, request, &response);
  }

  ::grpc::Status clear_task(const std::string& name, uint32_t session_id, ClearTaskResponse& response)
  {
    ::grpc::ClientContext context;
    ClearTaskRequest request;
    if (!name.empty()) {
      request.mutable_task()->set_name(name);
    }
    if (session_id) {
      request.mutable_task()->set_id(session_id);
    }
    return stub()->ClearTask(&context, request, &response);
  }

  std::unique_ptr<NiDAQmx::Stub>& stub()
  {
    return nidaqmx_stub_;
  }
  DeviceServerInterface* device_server_;
  std::unique_ptr<::nidevice_grpc::Session> driver_session_;
  std::unique_ptr<NiDAQmx::Stub> nidaqmx_stub_;
};

TEST_F(NiDAQmxSessionTests, CreateTask_ClearTask_Succeeds)
{
  CreateTaskResponse create_response;
  auto create_status = create_task("", create_response);

  ClearTaskResponse clear_response;
  auto clear_status = clear_task("", create_response.task().id(), clear_response);

  EXPECT_TRUE(create_status.ok());
  EXPECT_TRUE(clear_status.ok());
  EXPECT_EQ(0, create_response.status());
  EXPECT_EQ(0, clear_response.status());
  EXPECT_NE(0, create_response.task().id());
}
}  // namespace system
}  // namespace tests
}  // namespace ni
