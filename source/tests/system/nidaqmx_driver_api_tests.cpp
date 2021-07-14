#include <gmock/gmock.h>
#include <gtest/gtest.h>  // For EXPECT matchers.

#include <algorithm>
#include <random>

#include "device_server.h"
#include "enumerate_devices.h"

#include "nidaqmx/nidaqmx_service.h"

using namespace ::testing;
using namespace nidaqmx_grpc;
using google::protobuf::uint32;

namespace ni {
namespace tests {
namespace system {

// Creates a static TResponse instance that can be used as a default/in-line value (because it's not a temporary).
template <typename TResponse>
struct ThrowawayResponse {
  static TResponse& response()
  {
    static TResponse response_instance;
    return response_instance;
  }
};

class NiDAQmxDriverApiTests : public Test {
 protected:
  const std::string DEVICE_NAME{"Dev1"};

  NiDAQmxDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        nidaqmx_stub_(NiDAQmx::NewStub(device_server_->InProcessChannel()))
  {
  }
  virtual ~NiDAQmxDriverApiTests() {}

  void SetUp() override
  {
    // In MAX, this can be set up by importing grpc-device-daq-tests.nce.
    std::unordered_map<std::string, std::string> required_devices{
        {"gRPCSystemTestDAQ", "NI PXIe-6341"}};

    if (!are_all_devices_present(required_devices)) {
      GTEST_SKIP() << "Required Device(s) not found";
    }

    initialize_driver_session();
  }

  void TearDown() override
  {
    close_driver_session();
  }

  bool are_all_devices_present(std::unordered_map<std::string, std::string> required_devices) 
  {
    for(const auto& device : EnumerateDevices()) {
      auto matched_required_device = required_devices.find(device.name());
      if (matched_required_device != required_devices.cend()
        && matched_required_device->second == device.model()) {
          required_devices.erase(matched_required_device);
      }
    }

    return required_devices.empty();
  }

  void initialize_driver_session()
  {
    ::grpc::ClientContext context;
    CreateTaskResponse response;
    auto status = create_task(response);
    driver_session_ = std::make_unique<nidevice_grpc::Session>(response.task());

    EXPECT_SUCCESS(status, response);
  }

  void close_driver_session()
  {
    if (!driver_session_) return;

    ::grpc::ClientContext context;
    ClearTaskResponse response;
    auto status = clear_task(response);

    EXPECT_SUCCESS(status, response);
  }

  ::grpc::Status create_task(CreateTaskResponse& response)
  {
    ::grpc::ClientContext context;
    CreateTaskRequest request;
    return stub()->CreateTask(&context, request, &response);
  }

  ::grpc::Status clear_task(ClearTaskResponse& response)
  {
    ::grpc::ClientContext context;
    ClearTaskRequest request;
    set_request_session_id(request);
    return stub()->ClearTask(&context, request, &response);
  }

  ::grpc::Status create_ai_voltage_chan(double min_val, double max_val, CreateAIVoltageChanResponse& response)
  {
    ::grpc::ClientContext context;
    CreateAIVoltageChanRequest request;
    set_request_session_id(request);
    request.set_physical_channel("gRPCSystemTestDAQ/ai0");
    request.set_name_to_assign_to_channel("ai0");
    request.set_terminal_config(InputTermCfgWithDefault::INPUT_TERM_CFG_WITH_DEFAULT_CFG_DEFAULT);
    request.set_min_val(min_val);
    request.set_max_val(max_val);
    request.set_units(VoltageUnits2::VOLTAGE_UNITS2_VOLTS);
    return stub()->CreateAIVoltageChan(&context, request, &response);
  }

  ::grpc::Status create_ao_voltage_chan(double min_val, double max_val, CreateAOVoltageChanResponse& response)
  {
    ::grpc::ClientContext context;
    CreateAOVoltageChanRequest request;
    set_request_session_id(request);
    request.set_physical_channel("gRPCSystemTestDAQ/ao0");
    request.set_name_to_assign_to_channel("ao0");
    request.set_min_val(min_val);
    request.set_max_val(max_val);
    request.set_units(VoltageUnits2::VOLTAGE_UNITS2_VOLTS);
    return stub()->CreateAOVoltageChan(&context, request, &response);
  }

  ::grpc::Status create_di_chan(CreateDIChanResponse& response)
  {
    ::grpc::ClientContext context;
    CreateDIChanRequest request;
    set_request_session_id(request);
    request.set_lines("gRPCSystemTestDAQ/port0/line0");
    request.set_name_to_assign_to_lines("di");
    request.set_line_grouping(LineGrouping::LINE_GROUPING_CHAN_PER_LINE);
    return stub()->CreateDIChan(&context, request, &response);
  }

  ::grpc::Status create_do_chan(CreateDOChanResponse& response)
  {
    ::grpc::ClientContext context;
    CreateDOChanRequest request;
    set_request_session_id(request);
    request.set_lines("gRPCSystemTestDAQ/port1/line0");
    request.set_name_to_assign_to_lines("do");
    request.set_line_grouping(LineGrouping::LINE_GROUPING_CHAN_PER_LINE);
    return stub()->CreateDOChan(&context, request, &response);
  }

  ::grpc::Status start_task(StartTaskResponse& response = ThrowawayResponse<StartTaskResponse>::response())
  {
    ::grpc::ClientContext context;
    StartTaskRequest request;
    set_request_session_id(request);
    return stub()->StartTask(&context, request, &response);
  }

  ::grpc::Status stop_task(StopTaskResponse& response = ThrowawayResponse<StopTaskResponse>::response())
  {
    ::grpc::ClientContext context;
    StopTaskRequest request;
    set_request_session_id(request);
    return stub()->StopTask(&context, request, &response);
  }

  ::grpc::Status read_analog_f64(
      int32 samps_per_chan,
      uint32 array_size_in_samps,
      ReadAnalogF64Response& response)
  {
    ::grpc::ClientContext context;
    ReadAnalogF64Request request;
    set_request_session_id(request);
    request.set_num_samps_per_chan(samps_per_chan);
    request.set_array_size_in_samps(array_size_in_samps);
    request.set_fill_mode(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    return stub()->ReadAnalogF64(&context, request, &response);
  }

  ::grpc::Status write_analog_f64(
      const std::vector<double>& data,
      WriteAnalogF64Response& response)
  {
    ::grpc::ClientContext context;
    WriteAnalogF64Request request;
    set_request_session_id(request);
    request.set_num_samps_per_chan(static_cast<int32_t>(data.size()));
    request.set_auto_start(false);
    request.mutable_write_array()->Add(data.cbegin(), data.cend());
    request.set_data_layout(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    return stub()->WriteAnalogF64(&context, request, &response);
  }

  ::grpc::Status write_u16_digital_data(WriteDigitalU16Response& response)
  {
    ::grpc::ClientContext context;
    WriteDigitalU16Request request;
    set_request_session_id(request);
    request.set_num_samps_per_chan(4);
    request.add_write_array(100);
    request.add_write_array(10);
    request.add_write_array(1);
    request.add_write_array(0);
    return stub()->WriteDigitalU16(&context, request, &response);
  }

  ::grpc::Status read_u16_digital_data(ReadDigitalU16Response& response)
  {
    ::grpc::ClientContext context;
    ReadDigitalU16Request request;
    set_request_session_id(request);
    request.set_num_samps_per_chan(4);
    request.set_array_size_in_samps(4);
    request.set_fill_mode(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    return stub()->ReadDigitalU16(&context, request, &response);
  ::grpc::Status get_nth_task_device(uint32_t index, GetNthTaskDeviceResponse& response)
  {
    ::grpc::ClientContext context;
    GetNthTaskDeviceRequest request;
    set_request_session_id(request);
    request.set_index(index);
    request.set_buffer_size(256);
    
    return stub()->GetNthTaskDevice(&context, request, &response);
  }

  std::unique_ptr<NiDAQmx::Stub>& stub()
  {
    return nidaqmx_stub_;
  }

  template <typename TRequest>
  void set_request_session_id(TRequest& request)
  {
    request.mutable_task()->set_id(driver_session_->id());
  }

  template <typename TResponse>
  void EXPECT_SUCCESS(const ::grpc::Status& status, const TResponse& response)
  {
    EXPECT_TRUE(status.ok());
    EXPECT_EQ(DAQmxSuccess, response.status());
  }

  DeviceServerInterface* device_server_;
  std::unique_ptr<::nidevice_grpc::Session> driver_session_;
  std::unique_ptr<NiDAQmx::Stub> nidaqmx_stub_;
};

template <typename T>
std::function<T()> random_generator(T begin, T end)
{
  std::random_device device;
  std::default_random_engine engine(device());
  std::uniform_real_distribution<T> distribution(begin, end);
  return [=]() mutable { return distribution(engine); };
}

template <typename T>
std::vector<T> generate_random_data(T min, T max, size_t size)
{
  std::vector<T> data(size);
  auto generate_value_in_range = random_generator<T>(min, max);
  std::generate(data.begin(), data.end(), generate_value_in_range);
  return data;
}

TEST_F(NiDAQmxDriverApiTests, CreateAIVoltageChannel_Succeeds)
{
  CreateAIVoltageChanResponse response;
  auto status = create_ai_voltage_chan(-1.0, 1.0, response);

  EXPECT_SUCCESS(status, response);
}

TEST_F(NiDAQmxDriverApiTests, CreateDIChannel_Succeeds)
{
  CreateDIChanResponse response;
  auto status = create_di_chan(response);

  EXPECT_SUCCESS(status, response);
}

TEST_F(NiDAQmxDriverApiTests, CreateDOChannel_Succeeds)
{
  CreateDOChanResponse response;
  auto status = create_do_chan(response);

  EXPECT_SUCCESS(status, response);
}

TEST_F(NiDAQmxDriverApiTests, WriteU16DigitalData_Succeeds)
{
  CreateDOChanResponse create_channel_response;
  create_do_chan(create_channel_response);
  StartTaskResponse start_response;
  start_task(start_response);

  WriteDigitalU16Response response;
  auto status = write_u16_digital_data(response);

  StopTaskResponse stop_response;
  stop_task(stop_response);

  EXPECT_SUCCESS(status, response);
  EXPECT_EQ(4, response.samps_per_chan_written());
}

TEST_F(NiDAQmxDriverApiTests, ReadU16DigitalData_Succeeds)
{
  CreateDIChanResponse create_channel_response;
  create_di_chan(create_channel_response);
  StartTaskResponse start_response;
  start_task(start_response);

  ReadDigitalU16Response response;
  auto status = read_u16_digital_data(response);

  StopTaskResponse stop_response;
  stop_task(stop_response);

  EXPECT_EQ(0, status.error_code());
  EXPECT_SUCCESS(status, response);
  EXPECT_EQ(4, response.samps_per_chan());
}

TEST_F(NiDAQmxDriverApiTests, AIVoltageChannel_ReadAIData_ReturnsDataInExpectedRange)
{
  const double AI_MIN = 1.0;
  const double AI_MAX = 10.0;
  CreateAIVoltageChanResponse create_channel_response;
  create_ai_voltage_chan(AI_MIN, AI_MAX, create_channel_response);

  StartTaskResponse start_response;
  auto start_status = start_task(start_response);
  ReadAnalogF64Response read_response;
  auto read_status = read_analog_f64(100, 100, read_response);
  StopTaskResponse stop_response;
  auto stop_status = stop_task(stop_response);

  EXPECT_EQ(read_response.read_array_size(), 100);
  EXPECT_THAT(read_response.read_array(), Each(Not(Lt(AI_MIN))));
  EXPECT_THAT(read_response.read_array(), Each(Not(Gt(AI_MAX))));
  EXPECT_SUCCESS(start_status, start_response);
  EXPECT_SUCCESS(read_status, read_response);
  EXPECT_SUCCESS(stop_status, stop_response);
}

TEST_F(NiDAQmxDriverApiTests, AOVoltageChannel_WriteAOData_Succeeds)
{
  const double AO_MIN = 1.0;
  const double AO_MAX = 10.0;
  CreateAOVoltageChanResponse create_channel_response;
  create_ao_voltage_chan(AO_MIN, AO_MAX, create_channel_response);

  start_task();
  auto write_data = generate_random_data(AO_MIN, AO_MAX, 100);
  WriteAnalogF64Response write_response;
  auto write_status = write_analog_f64(write_data, write_response);
  stop_task();

  EXPECT_SUCCESS(write_status, write_response);
}

TEST_F(NiDAQmxDriverApiTests, AOVoltageChannel_WriteAODataWithOutOfRangeValue_ReturnsInvalidAODataError)
{
  const double AO_MIN = 1.0;
  const double AO_MAX = 10.0;
  CreateAOVoltageChanResponse create_channel_response;
  create_ao_voltage_chan(AO_MIN, AO_MAX, create_channel_response);

  start_task();
  auto write_data = generate_random_data(AO_MIN, AO_MAX, 100);
  write_data[80] += AO_MAX;
  WriteAnalogF64Response write_response;
  write_analog_f64(write_data, write_response);
  stop_task();

  EXPECT_EQ(DAQmxErrorInvalidAODataWrite, write_response.status());
}

TEST_F(NiDAQmxDriverApiTests, TaskWithAOChannel_GetNthTaskDevice_ReturnsDeviceForChannel)
{
  const double AO_MIN = 1.0;
  const double AO_MAX = 10.0;
  CreateAOVoltageChanResponse create_channel_response;
  create_ao_voltage_chan(AO_MIN, AO_MAX, create_channel_response);

  GetNthTaskDeviceResponse nth_device_response;
  auto status = get_nth_task_device(1, nth_device_response);

  EXPECT_SUCCESS(status, nth_device_response);
  auto trimmed_string = std::string(nth_device_response.buffer().c_str());
  EXPECT_EQ(DEVICE_NAME, trimmed_string);
}
}  // namespace system
}  // namespace tests
}  // namespace ni
