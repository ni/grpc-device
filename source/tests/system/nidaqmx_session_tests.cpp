#include <gtest/gtest.h>

#include "device_server.h"
#include "nidaqmx/nidaqmx_client.h"

using namespace nidaqmx_grpc;

namespace ni {
namespace tests {
namespace system {

constexpr auto DAQMX_SUCCESS = 0;

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

  ::grpc::Status clear_task(const std::string& name, ClearTaskResponse& response)
  {
    ::grpc::ClientContext context;
    ClearTaskRequest request;
    if (!name.empty()) {
      request.mutable_task()->set_name(name);
    }
    return stub()->ClearTask(&context, request, &response);
  }

  std::unique_ptr<NiDAQmx::Stub>& stub()
  {
    return nidaqmx_stub_;
  }
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiDAQmx::Stub> nidaqmx_stub_;
};

TEST_F(NiDAQmxSessionTests, CreateTask_ClearTask_Succeeds)
{
  CreateTaskResponse create_response;
  auto create_status = create_task("", create_response);
  auto task_name = create_response.task().name();

  ClearTaskResponse clear_response;
  auto clear_status = clear_task(task_name, clear_response);

  EXPECT_TRUE(create_status.ok());
  EXPECT_TRUE(clear_status.ok());
  EXPECT_EQ(DAQMX_SUCCESS, create_response.status());
  EXPECT_EQ(DAQMX_SUCCESS, clear_response.status());
  EXPECT_NE("", create_response.task().name());
}
}  // namespace system
}  // namespace tests
}  // namespace ni
