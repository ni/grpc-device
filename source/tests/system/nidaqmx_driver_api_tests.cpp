#include <gtest/gtest.h>

#include "device_server.h"
#include "nidaqmx/nidaqmx_service.h"

using namespace nidaqmx_grpc;

namespace ni {
namespace tests {
namespace system {
class NiDAQmxDriverApiTests : public ::testing::Test {
 protected:
  NiDAQmxDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        nidaqmx_stub_(NiDAQmx::NewStub(device_server_->InProcessChannel()))
  {
  }
  virtual ~NiDAQmxDriverApiTests() {}

  void SetUp() override
  {
    initialize_driver_session();
  }

  void TearDown() override
  {
    close_driver_session();
  }

  void initialize_driver_session()
  {
    ::grpc::ClientContext context;
    CreateTaskResponse response;

    auto status = create_task("", response);
    driver_session_ = std::make_unique<nidevice_grpc::Session>(response.task());

    EXPECT_SUCCESS(status, response);
  }

  void close_driver_session()
  {
    if (!driver_session_) return;

    ::grpc::ClientContext context;
    ClearTaskResponse response;

    auto status = clear_task(driver_session_->name(), driver_session_->id(), response);

    EXPECT_SUCCESS(status, response);
  }

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

  ::grpc::Status create_ai_voltage_chan(CreateAIVoltageChanResponse& response)
  {
    ::grpc::ClientContext context;
    CreateAIVoltageChanRequest request;
    set_id(request);
    request.set_physical_channel("Dev1/ai0");
    request.set_name_to_assign_to_channel("channel1");
    request.set_terminal_config(InputTermCfgWithDefault::INPUT_TERM_CFG_WITH_DEFAULT_Cfg_Default);
    request.set_min_val(-10.0);
    request.set_max_val(10.0);
    request.set_units(VoltageUnits2::VOLTAGE_UNITS2_Volts);
    return stub()->CreateAIVoltageChan(&context, request, &response);
  }

  ::grpc::Status create_di_chan(CreateDIChanResponse& response)
  {
    ::grpc::ClientContext context;
    CreateDIChanRequest request;
    set_id(request);
    request.set_lines("Dev1/port0/line0");
    request.set_name_to_assign_to_lines("di");
    request.set_line_grouping(LineGrouping::LINE_GROUPING_ChanPerLine);
    return stub()->CreateDIChan(&context, request, &response);
  }

  ::grpc::Status create_do_chan(CreateDOChanResponse& response)
  {
    ::grpc::ClientContext context;
    CreateDOChanRequest request;
    set_id(request);
    request.set_lines("Dev1/port1/line0");
    request.set_name_to_assign_to_lines("do");
    request.set_line_grouping(LineGrouping::LINE_GROUPING_ChanPerLine);
    return stub()->CreateDOChan(&context, request, &response);
  }

  ::grpc::Status start_task(StartTaskResponse& response)
  {
    ::grpc::ClientContext context;
    StartTaskRequest request;
    set_id(request);
    return stub()->StartTask(&context, request, &response);
  }

  ::grpc::Status stop_task(StopTaskResponse& response)
  {
    ::grpc::ClientContext context;
    StopTaskRequest request;
    set_id(request);
    return stub()->StopTask(&context, request, &response);
  }

  std::unique_ptr<NiDAQmx::Stub>& stub()
  {
    return nidaqmx_stub_;
  }

  template <typename TRequest>
  void set_id(TRequest& request)
  {
    request.mutable_task()->set_id(driver_session_->id());
  }

  template <typename TResponse>
  void EXPECT_SUCCESS(const ::grpc::Status& status, TResponse& response)
  {
    EXPECT_TRUE(status.ok());
    EXPECT_EQ(DAQmxSuccess, response.status());
  }

  DeviceServerInterface* device_server_;
  std::unique_ptr<::nidevice_grpc::Session> driver_session_;
  std::unique_ptr<NiDAQmx::Stub> nidaqmx_stub_;
};

TEST_F(NiDAQmxDriverApiTests, CreateAIVoltageChannel_Succeeds)
{
  CreateAIVoltageChanResponse response;
  auto status = create_ai_voltage_chan(response);

  EXPECT_SUCCESS(status, response);
}

TEST_F(NiDAQmxDriverApiTests, CreateDIChan_Succeeds)
{
  CreateDIChanResponse response;
  auto status = create_di_chan(response);

  EXPECT_SUCCESS(status, response);
}

TEST_F(NiDAQmxDriverApiTests, CreateDOChan_Succeeds)
{
  CreateDOChanResponse response;
  auto status = create_do_chan(response);

  EXPECT_SUCCESS(status, response);
}

TEST_F(NiDAQmxDriverApiTests, AIVoltageChannel_StartTaskStopTask_Succeeds)
{
  CreateAIVoltageChanResponse create_channel_response;
  create_ai_voltage_chan(create_channel_response);

  StartTaskResponse start_response;
  auto start_status = start_task(start_response);
  StopTaskResponse stop_response;
  auto stop_status = stop_task(stop_response);

  EXPECT_SUCCESS(start_status, start_response);
  EXPECT_SUCCESS(stop_status, stop_response);
}
}  // namespace system
}  // namespace tests
}  // namespace ni