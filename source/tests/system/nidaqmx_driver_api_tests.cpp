#include <gmock/gmock.h>
#include <google/protobuf/util/time_util.h>

#include <algorithm>
#include <cstring>
#include <nlohmann/json.hpp>
#include <random>
#include <stdexcept>
#include <vector>

#include "device_server.h"
#include "enumerate_devices.h"
#include "nidaqmx/nidaqmx_client.h"
#include "tests/utilities/test_helpers.h"

using namespace ::testing;
using namespace nidaqmx_grpc;
using google::protobuf::uint32;
namespace client = nidaqmx_grpc::experimental::client;
namespace pb = ::google::protobuf;

namespace ni {
namespace tests {
namespace system {
namespace {

typedef pb::int16 int16;
typedef pb::int32 int32;
typedef pb::int64 int64;
typedef pb::uint64 uInt64;
typedef double float64;

constexpr auto DAQMX_SUCCESS = 0;
constexpr auto SPECIFIED_ATTRIBUTE_NOT_VALID_ERROR = -200233;
constexpr auto INVALID_AO_DATA_WRITE_ERROR = -200561;
constexpr auto DONE_EVENT_ALREADY_REGISTERED_ERROR = -200950;
constexpr auto WAIT_FOR_VALID_TIMESTAMP_NOT_SUPPORTED_ERROR = -209833;
constexpr auto INVALID_ATTRIBUTE_VALUE_ERROR = -200077;
constexpr auto RETRIEVING_NETWORK_DEVICE_PROPERTIES_ERROR = -201401;
constexpr auto TEDS_SENSOR_NOT_DETECTED_ERROR = -200709;
constexpr auto INVALID_TERM_ROUTING_ERROR = -89129;
constexpr auto DEVICE_DOES_NOT_SUPPORT_CDAQ_SYNC_CONNECTIONS_ERROR = -201450;

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
  const std::string DEVICE_NAME{"gRPCSystemTestDAQ"};
  const std::string ANY_DEVICE_MODEL{"[[ANY_DEVICE_MODEL]]"};
  const std::string AI_CHANNEL{"gRPCSystemTestDAQ/ai0"};
  const std::string AO_CHANNEL{"gRPCSystemTestDAQ/ao0"};

  NiDAQmxDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        nidaqmx_stub_(NiDAQmx::NewStub(device_server_->InProcessChannel()))
  {
  }
  virtual ~NiDAQmxDriverApiTests() {}

  void SetUp() override
  {
    // In MAX, this can be set up by importing grpc-device-daq-tests.nce.
    // Allow ANY_DEVICE_MODEL so we can run on any hardware with DEVICE_NAME configured.
    // Tests are written for a simulated "NI PXIe-6341".
    std::unordered_map<std::string, std::string> required_devices{
        {DEVICE_NAME, ANY_DEVICE_MODEL}};

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
    for (const auto& device : EnumerateDevices()) {
      auto matched_required_device = required_devices.find(device.name());
      if (matched_required_device != required_devices.cend()) {
        if (matched_required_device->second == device.model() || matched_required_device->second == ANY_DEVICE_MODEL)
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

    auto response = clear_task();

    EXPECT_SUCCESS(response);
  }

  ::grpc::Status create_task(CreateTaskResponse& response)
  {
    ::grpc::ClientContext context;
    CreateTaskRequest request;
    return stub()->CreateTask(&context, request, &response);
  }

  ClearTaskResponse clear_task()
  {
    return client::clear_task(stub(), task());
  }

  CreateAIVoltageChanRequest create_ai_voltage_request(double min_val, double max_val, const std::string& custom_scale_name = "")
  {
    CreateAIVoltageChanRequest request;
    set_request_session_name(request);
    request.set_physical_channel("gRPCSystemTestDAQ/ai0");
    request.set_name_to_assign_to_channel("ai0");
    request.set_terminal_config(InputTermCfgWithDefault::INPUT_TERM_CFG_WITH_DEFAULT_CFG_DEFAULT);
    request.set_min_val(min_val);
    request.set_max_val(max_val);
    if (custom_scale_name.empty()) {
      request.set_units(VoltageUnits2::VOLTAGE_UNITS2_VOLTS);
    }
    else {
      request.set_custom_scale_name(custom_scale_name);
      request.set_units(VoltageUnits2::VOLTAGE_UNITS2_FROM_CUSTOM_SCALE);
    }
    return request;
  }

  ::grpc::Status create_ai_voltage_chan(const CreateAIVoltageChanRequest& request, CreateAIVoltageChanResponse& response = ThrowawayResponse<CreateAIVoltageChanResponse>::response())
  {
    ::grpc::ClientContext context;
    return stub()->CreateAIVoltageChan(&context, request, &response);
  }

  ::grpc::Status create_ai_voltage_chan(double min_val, double max_val, CreateAIVoltageChanResponse& response = ThrowawayResponse<CreateAIVoltageChanResponse>::response())
  {
    auto request = create_ai_voltage_request(min_val, max_val);
    return create_ai_voltage_chan(request, response);
  }

  CreateAOVoltageChanRequest create_ao_voltage_chan_request(double min_val, double max_val, const std::string& name = "ao0")
  {
    CreateAOVoltageChanRequest request;
    set_request_session_name(request);

    request.set_physical_channel("gRPCSystemTestDAQ/ao0");
    request.set_name_to_assign_to_channel(name);

    request.set_min_val(min_val);
    request.set_max_val(max_val);
    request.set_units(VoltageUnits2::VOLTAGE_UNITS2_VOLTS);
    return request;
  }

  ::grpc::Status create_ao_voltage_chan(const CreateAOVoltageChanRequest& request, CreateAOVoltageChanResponse& response = ThrowawayResponse<CreateAOVoltageChanResponse>::response())
  {
    ::grpc::ClientContext context;
    return stub()->CreateAOVoltageChan(&context, request, &response);
  }

  ::grpc::Status create_ao_voltage_chan(double min_val, double max_val, CreateAOVoltageChanResponse& response = ThrowawayResponse<CreateAOVoltageChanResponse>::response())
  {
    auto request = create_ao_voltage_chan_request(min_val, max_val);
    return create_ao_voltage_chan(request, response);
  }

  ::grpc::Status create_di_chan(CreateDIChanResponse& response = ThrowawayResponse<CreateDIChanResponse>::response())
  {
    ::grpc::ClientContext context;
    CreateDIChanRequest request;
    set_request_session_name(request);
    request.set_lines("gRPCSystemTestDAQ/port0/line0");
    request.set_name_to_assign_to_lines("di");
    request.set_line_grouping(LineGrouping::LINE_GROUPING_CHAN_PER_LINE);
    return stub()->CreateDIChan(&context, request, &response);
  }

  CreateDOChanResponse create_do_chan(CreateDOChanResponse& response = ThrowawayResponse<CreateDOChanResponse>::response())
  {
    return client::create_do_chan(stub(), task(), "gRPCSystemTestDAQ/port1/line0", "do", LineGrouping::LINE_GROUPING_CHAN_PER_LINE);
  }

  ::grpc::Status create_ci_freq_chan(CreateCIFreqChanResponse& response)
  {
    ::grpc::ClientContext context;
    CreateCIFreqChanRequest request;
    set_request_session_name(request);
    request.set_counter("gRPCSystemTestDAQ/ctr0");
    request.set_name_to_assign_to_channel("ctr");
    request.set_min_val(1.19209);
    request.set_max_val(1e+2);
    request.set_units(FrequencyUnits3::FREQUENCY_UNITS3_HZ);
    request.set_edge(Edge1::EDGE1_RISING);
    request.set_meas_method(CounterFrequencyMethod::COUNTER_FREQUENCY_METHOD_LOW_FREQ_1_CTR);
    request.set_meas_time(0.001);
    request.set_divisor(4);
    return stub()->CreateCIFreqChan(&context, request, &response);
  }

  ::grpc::Status get_error_string(int32 error_code, GetErrorStringResponse& response)
  {
    ::grpc::ClientContext context;
    GetErrorStringRequest request;
    request.set_error_code(error_code);
    return stub()->GetErrorString(&context, request, &response);
  }

  ::grpc::Status start_task(const ::nidevice_grpc::Session& session, StartTaskResponse& response)
  {
    ::grpc::ClientContext context;
    StartTaskRequest request;
    set_request_session_name(request, session);
    return stub()->StartTask(&context, request, &response);
  }

  ::grpc::Status start_task(StartTaskResponse& response = ThrowawayResponse<StartTaskResponse>::response())
  {
    return start_task(*driver_session_, response);
  }

  ::grpc::Status stop_task(StopTaskResponse& response = ThrowawayResponse<StopTaskResponse>::response())
  {
    ::grpc::ClientContext context;
    StopTaskRequest request;
    set_request_session_name(request);
    return stub()->StopTask(&context, request, &response);
  }

  ::grpc::Status read_analog_f64(
      int32 samps_per_chan,
      uint32 array_size_in_samps,
      ReadAnalogF64Response& response = ThrowawayResponse<ReadAnalogF64Response>::response())
  {
    ::grpc::ClientContext context;
    ReadAnalogF64Request request;
    set_request_session_name(request);
    request.set_num_samps_per_chan(samps_per_chan);
    request.set_array_size_in_samps(array_size_in_samps);
    request.set_fill_mode(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    request.set_timeout(1000.0);
    return stub()->ReadAnalogF64(&context, request, &response);
  }

  ::grpc::Status write_analog_f64(
      const std::vector<double>& data,
      WriteAnalogF64Response& response)
  {
    ::grpc::ClientContext context;
    WriteAnalogF64Request request;
    set_request_session_name(request);
    request.set_num_samps_per_chan(static_cast<int32_t>(data.size()));
    request.set_auto_start(false);
    request.mutable_write_array()->Add(data.cbegin(), data.cend());
    request.set_data_layout(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    auto status = stub()->WriteAnalogF64(&context, request, &response);
    nidevice_grpc::experimental::client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status write_u32_digital_data(WriteDigitalU32Response& response)
  {
    ::grpc::ClientContext context;
    WriteDigitalU32Request request;
    set_request_session_name(request);
    request.set_data_layout(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    request.set_num_samps_per_chan(4);
    request.add_write_array(1000000);
    request.add_write_array(10000);
    request.add_write_array(1);
    request.add_write_array(0);
    return stub()->WriteDigitalU32(&context, request, &response);
  }

  ::grpc::Status read_u32_digital_data(ReadDigitalU32Response& response)
  {
    ::grpc::ClientContext context;
    ReadDigitalU32Request request;
    set_request_session_name(request);
    request.set_num_samps_per_chan(4);
    request.set_array_size_in_samps(4);
    request.set_fill_mode(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    return stub()->ReadDigitalU32(&context, request, &response);
  }

  ::grpc::Status write_u16_digital_data(WriteDigitalU16Response& response)
  {
    ::grpc::ClientContext context;
    WriteDigitalU16Request request;
    set_request_session_name(request);
    request.set_data_layout(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    request.set_num_samps_per_chan(4);
    request.add_write_array(65535);
    request.add_write_array(10);
    request.add_write_array(1);
    request.add_write_array(0);
    return stub()->WriteDigitalU16(&context, request, &response);
  }

  ::grpc::Status read_u16_digital_data(ReadDigitalU16Response& response)
  {
    ::grpc::ClientContext context;
    ReadDigitalU16Request request;
    set_request_session_name(request);
    request.set_num_samps_per_chan(4);
    request.set_array_size_in_samps(4);
    request.set_fill_mode(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    return stub()->ReadDigitalU16(&context, request, &response);
  }

  ::grpc::Status write_u8_digital_data(WriteDigitalU8Response& response)
  {
    ::grpc::ClientContext context;
    WriteDigitalU8Request request;
    set_request_session_name(request);
    request.set_data_layout(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    request.set_num_samps_per_chan(4);
    uint8_t data[4] = {255, 10, 1, 0};
    request.set_write_array(data, sizeof(data));
    return stub()->WriteDigitalU8(&context, request, &response);
  }

  ::grpc::Status read_u8_digital_data(ReadDigitalU8Response& response)
  {
    ::grpc::ClientContext context;
    ReadDigitalU8Request request;
    set_request_session_name(request);
    request.set_num_samps_per_chan(4);
    request.set_array_size_in_samps(4);
    request.set_fill_mode(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    return stub()->ReadDigitalU8(&context, request, &response);
  }

  ::grpc::Status write_binary_i16(const std::vector<int16>& data, WriteBinaryI16Response& response)
  {
    ::grpc::ClientContext context;
    WriteBinaryI16Request request;
    set_request_session_name(request);
    request.set_num_samps_per_chan(static_cast<uint32>(data.size()));
    request.mutable_write_array()->CopyFrom({data.cbegin(), data.cend()});
    request.set_data_layout(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    return stub()->WriteBinaryI16(&context, request, &response);
  }

  ::grpc::Status get_nth_task_device(uint32_t index, GetNthTaskDeviceResponse& response)
  {
    ::grpc::ClientContext context;
    GetNthTaskDeviceRequest request;
    set_request_session_name(request);
    request.set_index(index);

    return stub()->GetNthTaskDevice(&context, request, &response);
  }

  bool is_task_done()
  {
    ::grpc::ClientContext context;
    IsTaskDoneRequest request;
    set_request_session_name(request);
    IsTaskDoneResponse response;
    auto status = stub()->IsTaskDone(&context, request, &response);
    EXPECT_SUCCESS(status, response);
    return response.is_task_done();
  }

  ::grpc::Status task_control(TaskControlAction action, TaskControlResponse& response)
  {
    ::grpc::ClientContext context;
    TaskControlRequest request;
    set_request_session_name(request);
    request.set_action(action);
    return stub()->TaskControl(&context, request, &response);
  }

  auto register_done_event(::grpc::ClientContext& context)
  {
    RegisterDoneEventRequest request;
    set_request_session_name(request);
    return stub()->RegisterDoneEvent(&context, request);
  }

  auto register_every_n_samples_event(::grpc::ClientContext& context, uint32 n_samples)
  {
    RegisterEveryNSamplesEventRequest request;
    set_request_session_name(request);
    request.set_n_samples(n_samples);
    request.set_every_n_samples_event_type(EveryNSamplesEventType::EVERY_N_SAMPLES_EVENT_TYPE_ACQUIRED_INTO_BUFFER);
    return stub()->RegisterEveryNSamplesEvent(&context, request);
  }

  auto register_signal_event(::grpc::ClientContext& context, Signal2 signal_id)
  {
    RegisterSignalEventRequest request;
    set_request_session_name(request);
    request.set_signal_id(Signal2::SIGNAL2_SAMPLE_CLOCK);
    return stub()->RegisterSignalEvent(&context, request);
  }

  CfgSampClkTimingRequest create_cfg_samp_clk_timing_request(double rate, Edge1 active_edge, AcquisitionType sample_mode, uInt64 samples_per_chan)
  {
    CfgSampClkTimingRequest request;
    set_request_session_name(request);
    request.set_rate(rate);
    request.set_active_edge(active_edge);
    request.set_sample_mode(sample_mode);
    request.set_samps_per_chan(samples_per_chan);
    return request;
  }

  ::grpc::Status cfg_samp_clk_timing(CfgSampClkTimingResponse& response = ThrowawayResponse<CfgSampClkTimingResponse>::response())
  {
    auto request = create_cfg_samp_clk_timing_request(100.0, Edge1::EDGE1_RISING, AcquisitionType::ACQUISITION_TYPE_CONT_SAMPS, 1000UL);
    return cfg_samp_clk_timing(request, response);
  }

  ::grpc::Status cfg_samp_clk_timing(const CfgSampClkTimingRequest& request, CfgSampClkTimingResponse& response = ThrowawayResponse<CfgSampClkTimingResponse>::response())
  {
    ::grpc::ClientContext context;
    return stub()->CfgSampClkTiming(&context, request, &response);
  }

  CfgChangeDetectionTimingRequest create_cfg_change_detection_timing(const std::string& channel)
  {
    CfgChangeDetectionTimingRequest request;
    set_request_session_name(request);
    request.set_falling_edge_chan(channel);
    request.set_rising_edge_chan(channel);
    request.set_sample_mode(AcquisitionType::ACQUISITION_TYPE_HW_TIMED_SINGLE_POINT);
    return request;
  }

  ::grpc::Status cfg_change_detection_timing(const CfgChangeDetectionTimingRequest& request, CfgChangeDetectionTimingResponse& response = ThrowawayResponse<CfgChangeDetectionTimingResponse>::response())
  {
    ::grpc::ClientContext context;
    return stub()->CfgChangeDetectionTiming(&context, request, &response);
  }

  ::grpc::Status cfg_input_buffer(CfgInputBufferResponse& response)
  {
    ::grpc::ClientContext context;
    CfgInputBufferRequest request;
    set_request_session_name(request);
    request.set_num_samps_per_chan(1024U);
    return stub()->CfgInputBuffer(&context, request, &response);
  }

  ::grpc::Status cfg_output_buffer(CfgOutputBufferResponse& response)
  {
    ::grpc::ClientContext context;
    CfgOutputBufferRequest request;
    set_request_session_name(request);
    request.set_num_samps_per_chan(1024U);
    return stub()->CfgOutputBuffer(&context, request, &response);
  }

  ::grpc::Status self_test_device(SelfTestDeviceResponse& response)
  {
    ::grpc::ClientContext context;
    SelfTestDeviceRequest request;
    request.set_device_name(DEVICE_NAME);
    return stub()->SelfTestDevice(&context, request, &response);
  }

  ::grpc::Status create_lin_scale(const std::string& name, double slope, CreateLinScaleResponse& response = ThrowawayResponse<CreateLinScaleResponse>::response())
  {
    ::grpc::ClientContext context;
    CreateLinScaleRequest request;
    request.set_name(name);
    request.set_slope(slope);
    request.set_pre_scaled_units(UnitsPreScaled::UNITS_PRE_SCALED_VOLTS);
    return stub()->CreateLinScale(&context, request, &response);
  }

  ::grpc::Status create_polynomial_scale(const std::string& name, const std::vector<double>& forward_coeffs, const std::vector<double>& reverse_coeffs, CreatePolynomialScaleResponse& response = ThrowawayResponse<CreatePolynomialScaleResponse>::response())
  {
    ::grpc::ClientContext context;
    CreatePolynomialScaleRequest request;
    request.set_name(name);

    request.mutable_forward_coeffs()->CopyFrom({forward_coeffs.cbegin(), forward_coeffs.cend()});

    request.mutable_reverse_coeffs()->CopyFrom({reverse_coeffs.cbegin(), reverse_coeffs.cend()});

    request.set_pre_scaled_units(UnitsPreScaled::UNITS_PRE_SCALED_VOLTS);
    return stub()->CreatePolynomialScale(&context, request, &response);
  }

  ::grpc::Status create_ai_thrmcpl_chan(double min_val, double max_val, CreateAIThrmcplChanResponse& response)
  {
    ::grpc::ClientContext context;
    CreateAIThrmcplChanRequest request;
    set_request_session_name(request);
    request.set_physical_channel("gRPCSystemTestDAQ/ai0");
    request.set_units(TemperatureUnits::TEMPERATURE_UNITS_DEG_C);
    request.set_min_val(min_val);
    request.set_max_val(max_val);
    request.set_thermocouple_type(ThermocoupleType1::THERMOCOUPLE_TYPE1_J_TYPE_TC);
    request.set_cjc_source(CJCSource1::CJC_SOURCE1_CONST_VAL);
    request.set_cjc_val(25.0);
    return stub()->CreateAIThrmcplChan(&context, request, &response);
  }

  CalculateReversePolyCoeffRequest create_calculate_reverse_poly_coeff_request(
      const std::vector<double> forward_coeffs,
      double min_val_x,
      double max_val_x,
      int32_t num_points_to_compute,
      int32_t reverse_poly_order)
  {
    CalculateReversePolyCoeffRequest request;
    request.mutable_forward_coeffs()->CopyFrom({forward_coeffs.cbegin(), forward_coeffs.cend()});
    request.set_min_val_x(min_val_x);
    request.set_max_val_x(max_val_x);
    request.set_num_points_to_compute(num_points_to_compute);
    request.set_reverse_poly_order(reverse_poly_order);
    return request;
  }

  ::grpc::Status calculate_reverse_poly_coeff(const CalculateReversePolyCoeffRequest& request, CalculateReversePolyCoeffResponse& response)
  {
    ::grpc::ClientContext context;
    return stub()->CalculateReversePolyCoeff(&context, request, &response);
  }

  template <typename TRaw>
  ::grpc::Status read_raw(int32 samples_to_read, ReadRawResponse& response)
  {
    ::grpc::ClientContext context;
    ReadRawRequest request;
    set_request_session_name(request);
    request.set_num_samps_per_chan(samples_to_read);
    request.set_array_size_in_bytes(samples_to_read * sizeof(TRaw));
    request.set_timeout(1000.0);
    return stub()->ReadRaw(&context, request, &response);
  }

  template <typename TRaw>
  ::grpc::Status write_raw(const std::vector<TRaw>& data, WriteRawResponse& response)
  {
    ::grpc::ClientContext context;
    WriteRawRequest request;
    set_request_session_name(request);
    auto byte_data = reinterpret_cast<const char*>(data.data());
    auto write_data = request.mutable_write_array();
    write_data->insert(write_data->cbegin(), byte_data, byte_data + data.size() * sizeof(TRaw));
    request.set_num_samps(static_cast<uint32>(data.size()));
    request.set_timeout(1000.0);
    return stub()->WriteRaw(&context, request, &response);
  }

  ::grpc::Status wait_for_valid_timestamp(WaitForValidTimestampResponse& response)
  {
    ::grpc::ClientContext context;
    WaitForValidTimestampRequest request;
    set_request_session_name(request);
    request.set_timestamp_event(TimestampEvent::TIMESTAMP_EVENT_FIRST_SAMPLE_TIMESTAMP);
    request.set_timeout(1.000);
    auto status = stub()->WaitForValidTimestamp(&context, request, &response);
    nidevice_grpc::experimental::client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status cfg_time_start_trig(CfgTimeStartTrigResponse& response)
  {
    ::grpc::ClientContext context;
    CfgTimeStartTrigRequest request;
    set_request_session_name(request);
    auto time = google::protobuf::util::TimeUtil::GetCurrentTime();
    auto duration = google::protobuf::Duration{};
    duration.set_seconds(10);
    time += duration;
    request.mutable_when()->CopyFrom(time);
    request.set_timescale(Timescale2::TIMESCALE2_IO_DEVICE_TIME);
    auto status = stub()->CfgTimeStartTrig(&context, request, &response);
    nidevice_grpc::experimental::client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status save_task(SaveTaskResponse& response)
  {
    ::grpc::ClientContext context;
    SaveTaskRequest request;
    set_request_session_name(request);
    request.set_author("grpc.tester@ni.com");
    request.set_options_raw(SaveOptions::SAVE_OPTIONS_OVERWRITE | SaveOptions::SAVE_OPTIONS_ALLOW_INTERACTIVE_DELETION);
    request.set_save_as("saved_task");
    return stub()->SaveTask(&context, request, &response);
  }

  ::grpc::Status load_task(LoadTaskResponse& response)
  {
    ::grpc::ClientContext context;
    LoadTaskRequest request;
    request.set_session_name("saved_task");
    auto status = stub()->LoadTask(&context, request, &response);
    if (status.ok()) {
      EXPECT_NE(driver_session_->name(), response.task().name());
      driver_session_ = std::make_unique<nidevice_grpc::Session>(response.task());
    }
    return status;
  }

  ::grpc::Status self_cal(SelfCalResponse& response)
  {
    ::grpc::ClientContext context;
    SelfCalRequest request;
    request.set_device_name(DEVICE_NAME);
    return stub()->SelfCal(&context, request, &response);
  }

  ::grpc::Status add_network_device(const std::string& ip_address, AddNetworkDeviceResponse& response)
  {
    ::grpc::ClientContext context;
    AddNetworkDeviceRequest request;
    request.set_ip_address(ip_address);
    auto status = stub()->AddNetworkDevice(&context, request, &response);
    nidevice_grpc::experimental::client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status wait_for_next_sample_clock(WaitForNextSampleClockResponse& response)
  {
    ::grpc::ClientContext context;
    WaitForNextSampleClockRequest request;
    set_request_session_name(request);
    request.set_timeout(10.0);
    auto status = stub()->WaitForNextSampleClock(&context, request, &response);
    nidevice_grpc::experimental::client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status connect_terms(const std::string& source, const std::string& destination, ConnectTermsResponse& response)
  {
    ::grpc::ClientContext context;
    ConnectTermsRequest request;
    request.set_source_terminal(source);
    request.set_destination_terminal(destination);
    request.set_signal_modifiers(InvertPolarity::INVERT_POLARITY_DO_NOT_INVERT_POLARITY);
    auto status = stub()->ConnectTerms(&context, request, &response);
    nidevice_grpc::experimental::client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status create_watchdog_timer_task_ex(double timeout, CreateWatchdogTimerTaskExResponse& response)
  {
    ::grpc::ClientContext context;
    CreateWatchdogTimerTaskExRequest request;

    request.set_device_name(DEVICE_NAME);
    request.set_timeout(timeout);
    return stub()->CreateWatchdogTimerTaskEx(&context, request, &response);
  }

  ::grpc::Status cfg_watchdog_do_expir_states(const nidevice_grpc::Session& watchdog_session, CfgWatchdogDOExpirStatesResponse& response)
  {
    ::grpc::ClientContext context;
    CfgWatchdogDOExpirStatesRequest request;

    set_request_session_name(request, watchdog_session);
    request.set_channel_names("gRPCSystemTestDAQ/port1/line0:1");
    auto expir_states = std::vector<DigitalLineState>{
        DigitalLineState::DIGITAL_LINE_STATE_HIGH,
        DigitalLineState::DIGITAL_LINE_STATE_HIGH};
    request.mutable_expir_state_array()->CopyFrom({expir_states.cbegin(), expir_states.cend()});
    return stub()->CfgWatchdogDOExpirStates(&context, request, &response);
  }

  std::unique_ptr<NiDAQmx::Stub>& stub()
  {
    return nidaqmx_stub_;
  }

  const nidevice_grpc::Session& task()
  {
    return *driver_session_;
  }

  template <typename TRequest>
  void set_request_session_name(TRequest& request)
  {
    set_request_session_name(request, *driver_session_);
  }

  template <typename TRequest>
  void set_request_session_name(TRequest& request, const nidevice_grpc::Session& session)
  {
    request.mutable_task()->set_name(session.name());
  }

  template <typename TResponse>
  void EXPECT_SUCCESS(const TResponse& response)
  {
    EXPECT_EQ(DAQMX_SUCCESS, response.status());
    if (response.status() != DAQMX_SUCCESS) {
      auto error_response = client::get_error_string(stub(), response.status());
      EXPECT_EQ("", error_response.error_string());
    }
  }

  template <typename TResponse>
  void EXPECT_SUCCESS(const ::grpc::Status& status, const TResponse& response)
  {
    EXPECT_SUCCESS(response);
    EXPECT_EQ(::grpc::Status::OK.error_code(), status.error_code());
  }

  template <typename T>
  void EXPECT_DATA_IN_RANGE(const ::google::protobuf::RepeatedField<T>& data, T min_val, T max_val)
  {
    EXPECT_THAT(data, Each(Not(Lt(min_val))));
    EXPECT_THAT(data, Each(Not(Gt(max_val))));
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
  auto response = create_do_chan();

  EXPECT_SUCCESS(response);
}

TEST_F(NiDAQmxDriverApiTests, WriteU32DigitalData_Succeeds)
{
  create_do_chan();
  start_task();

  WriteDigitalU32Response response;
  auto status = write_u32_digital_data(response);
  stop_task();

  EXPECT_SUCCESS(status, response);
  EXPECT_EQ(4, response.samps_per_chan_written());
}

TEST_F(NiDAQmxDriverApiTests, ReadU32DigitalData_Succeeds)
{
  create_di_chan();
  start_task();

  ReadDigitalU32Response response;
  auto status = read_u32_digital_data(response);
  stop_task();

  EXPECT_SUCCESS(status, response);
  EXPECT_EQ(4, response.samps_per_chan_read());
}

TEST_F(NiDAQmxDriverApiTests, WriteU16DigitalData_Succeeds)
{
  create_do_chan();
  start_task();

  WriteDigitalU16Response response;
  auto status = write_u16_digital_data(response);
  stop_task();

  EXPECT_SUCCESS(status, response);
  EXPECT_EQ(4, response.samps_per_chan_written());
}

TEST_F(NiDAQmxDriverApiTests, ReadU16DigitalData_Succeeds)
{
  create_di_chan();
  start_task();

  ReadDigitalU16Response response;
  auto status = read_u16_digital_data(response);
  stop_task();

  EXPECT_EQ(0, status.error_code());
  EXPECT_SUCCESS(status, response);
  EXPECT_EQ(4, response.samps_per_chan_read());
}

TEST_F(NiDAQmxDriverApiTests, WriteU8DigitalData_Succeeds)
{
  create_do_chan();
  start_task();

  WriteDigitalU8Response response;
  auto status = write_u8_digital_data(response);
  stop_task();

  EXPECT_SUCCESS(status, response);
  EXPECT_EQ(4, response.samps_per_chan_written());
}

TEST_F(NiDAQmxDriverApiTests, ReadU8DigitalData_Succeeds)
{
  create_di_chan();
  start_task();

  ReadDigitalU8Response response;
  auto status = read_u8_digital_data(response);
  stop_task();

  EXPECT_EQ(0, status.error_code());
  EXPECT_SUCCESS(status, response);
  EXPECT_EQ(4, response.samps_per_chan_read());
}

TEST_F(NiDAQmxDriverApiTests, AIVoltageChannel_ReadAIData_ReturnsDataInExpectedRange)
{
  const auto AI_MIN = 1.0;
  const auto AI_MAX = 10.0;
  const auto NUM_SAMPS = 100;
  create_ai_voltage_chan(AI_MIN, AI_MAX);

  StartTaskResponse start_response;
  auto start_status = start_task(start_response);
  ReadAnalogF64Response read_response;
  auto read_status = read_analog_f64(NUM_SAMPS, NUM_SAMPS, read_response);
  StopTaskResponse stop_response;
  auto stop_status = stop_task(stop_response);

  EXPECT_EQ(read_response.read_array_size(), NUM_SAMPS);
  EXPECT_DATA_IN_RANGE(read_response.read_array(), AI_MIN, AI_MAX);
  EXPECT_SUCCESS(start_status, start_response);
  EXPECT_SUCCESS(read_status, read_response);
  EXPECT_SUCCESS(stop_status, stop_response);
}

TEST_F(NiDAQmxDriverApiTests, AIDeviceTempChan_ReadAIData_ReturnsData)
{
  const auto NUM_SAMPS = 100;
  const auto MIN_TEMPERATURE = 0.0;
  const auto MAX_TEMPERATURE = 100.0;
  CreateAIThrmcplChanResponse create_response;
  auto create_status = create_ai_thrmcpl_chan(MIN_TEMPERATURE, MAX_TEMPERATURE, create_response);
  EXPECT_SUCCESS(create_status, create_response);

  start_task();
  ReadAnalogF64Response read_response;
  auto read_status = read_analog_f64(NUM_SAMPS, NUM_SAMPS, read_response);
  stop_task();

  EXPECT_SUCCESS(read_status, read_response);
  EXPECT_EQ(read_response.read_array_size(), NUM_SAMPS);
  EXPECT_DATA_IN_RANGE(read_response.read_array(), MIN_TEMPERATURE, MAX_TEMPERATURE);
}

TEST_F(NiDAQmxDriverApiTests, AIVoltageChannelWithLinearScale_ReadAIData_ReturnsDataInExpectedRange)
{
  const auto SCALE_NAME = std::string("TestScale");
  const auto AI_MIN = 1.0;
  const auto AI_MAX = 2.0;
  const auto NUM_SAMPS = 1000;
  CreateLinScaleResponse scale_response;
  auto scale_status = create_lin_scale(SCALE_NAME, 0.5, scale_response);
  EXPECT_SUCCESS(scale_status, scale_response);
  auto request = create_ai_voltage_request(AI_MIN, AI_MAX, SCALE_NAME);
  CreateAIVoltageChanResponse create_channel_response;
  auto create_channel_status = create_ai_voltage_chan(request, create_channel_response);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);

  start_task();
  ReadAnalogF64Response read_response;
  auto read_status = read_analog_f64(NUM_SAMPS, NUM_SAMPS, read_response);
  stop_task();

  EXPECT_SUCCESS(read_status, read_response);
  EXPECT_EQ(read_response.read_array_size(), NUM_SAMPS);
  // NOTE: linear scaling on simulated channels isn't really observable.
  // Either way you get a sine wave filling the min/max range.
  EXPECT_DATA_IN_RANGE(read_response.read_array(), AI_MIN, AI_MAX);
}

TEST_F(NiDAQmxDriverApiTests, LinearScale_GetSlopeAttribute_ReturnsInitialSlopeValue)
{
  const auto SCALE_NAME = std::string("TestScale");
  const auto SLOPE = 0.5;
  auto scale_status = create_lin_scale(SCALE_NAME, SLOPE);

  auto response = client::get_scale_attribute_double(
      stub(),
      SCALE_NAME,
      ScaleDoubleAttribute::SCALE_ATTRIBUTE_LIN_SLOPE);

  EXPECT_SUCCESS(response);
  EXPECT_NEAR(SLOPE, response.value(), .0001);
}

TEST_F(NiDAQmxDriverApiTests, SetYInterceptAttribute_GetYInterceptAttribute_ReturnsAttribute)
{
  const auto SCALE_NAME = std::string("TestScale");
  const auto Y_INTERCEPT = -3.0;
  auto scale_status = create_lin_scale(SCALE_NAME, 0.5);
  auto set_response = client::set_scale_attribute_double(
      stub(),
      SCALE_NAME,
      ScaleDoubleAttribute::SCALE_ATTRIBUTE_LIN_Y_INTERCEPT,
      Y_INTERCEPT);

  auto response = client::get_scale_attribute_double(
      stub(),
      SCALE_NAME,
      ScaleDoubleAttribute::SCALE_ATTRIBUTE_LIN_Y_INTERCEPT);

  EXPECT_SUCCESS(set_response);
  EXPECT_SUCCESS(response);
  EXPECT_NEAR(Y_INTERCEPT, response.value(), .0001);
}

TEST_F(NiDAQmxDriverApiTests, SetPreScaledUnits_GetPreScaledUnits_ReturnsAttribute)
{
  const auto SCALE_NAME = std::string("TestScale");
  const auto Y_INTERCEPT = -3.0;
  auto scale_status = create_lin_scale(SCALE_NAME, 0.5);
  auto set_response = client::set_scale_attribute_int32(
      stub(),
      SCALE_NAME,
      ScaleInt32Attribute::SCALE_ATTRIBUTE_PRE_SCALED_UNITS,
      ScaleInt32AttributeValues::SCALE_INT32_UNITS_PRE_SCALED_RPM);

  auto response = client::get_scale_attribute_int32(
      stub(),
      SCALE_NAME,
      ScaleInt32Attribute::SCALE_ATTRIBUTE_PRE_SCALED_UNITS);

  EXPECT_SUCCESS(set_response);
  EXPECT_SUCCESS(response);
  EXPECT_EQ(ScaleInt32AttributeValues::SCALE_INT32_UNITS_PRE_SCALED_RPM, response.value());
  EXPECT_EQ(ScaleInt32AttributeValues::SCALE_INT32_UNITS_PRE_SCALED_RPM, response.value_raw());
}

TEST_F(NiDAQmxDriverApiTests, GetScaledUnitsAsDouble_Fails)
{
  const auto SCALE_NAME = std::string("TestScale");
  const auto UNITS = std::string("Digits");
  auto scale_status = create_lin_scale(SCALE_NAME, 0.5);
  auto set_response = client::set_scale_attribute_string(
      stub(),
      SCALE_NAME,
      ScaleStringAttribute::SCALE_ATTRIBUTE_SCALED_UNITS,
      UNITS);

  try {
    client::get_scale_attribute_double(
        stub(),
        SCALE_NAME,
        (ScaleDoubleAttribute)ScaleStringAttribute::SCALE_ATTRIBUTE_SCALED_UNITS);
    FAIL() << "We shouldn't get here.";
  }
  catch (const nidevice_grpc::experimental::client::grpc_driver_error& ex) {
    expect_driver_error(ex, SPECIFIED_ATTRIBUTE_NOT_VALID_ERROR);
  }
}

TEST_F(NiDAQmxDriverApiTests, SetScaledUnits_GetScaledUnits_ReturnsAttribute)
{
  const auto SCALE_NAME = std::string("TestScale");
  const auto UNITS = std::string("Battalions");
  auto scale_status = create_lin_scale(SCALE_NAME, 0.5);
  auto set_response = client::set_scale_attribute_string(
      stub(),
      SCALE_NAME,
      ScaleStringAttribute::SCALE_ATTRIBUTE_SCALED_UNITS,
      UNITS);

  auto response = client::get_scale_attribute_string(
      stub(),
      SCALE_NAME,
      ScaleStringAttribute::SCALE_ATTRIBUTE_SCALED_UNITS);

  EXPECT_SUCCESS(set_response);
  EXPECT_SUCCESS(response);
  EXPECT_EQ(UNITS, response.value());
}

TEST_F(NiDAQmxDriverApiTests, SetPolynomialForwardCoefficients_GetPolynomialForwardCoefficients_ReturnsAttribute)
{
  const auto SCALE_NAME = std::string("TestPolynomialScale");
  const auto INITIAL_COEFFICIENTS = std::vector<double>{1.0, 2.0, 3.0};
  const auto COEFFICIENTS = std::vector<double>{1.0, 3.0, 8.0};
  auto scale_status = create_polynomial_scale(SCALE_NAME, INITIAL_COEFFICIENTS, INITIAL_COEFFICIENTS);
  auto set_response = client::set_scale_attribute_double_array(
      stub(),
      SCALE_NAME,
      ScaleDoubleArrayAttribute::SCALE_ATTRIBUTE_POLY_FORWARD_COEFF,
      COEFFICIENTS);

  auto response = client::get_scale_attribute_double_array(
      stub(),
      SCALE_NAME,
      ScaleDoubleArrayAttribute::SCALE_ATTRIBUTE_POLY_FORWARD_COEFF);

  EXPECT_SUCCESS(set_response);
  EXPECT_SUCCESS(response);
  auto actual = std::vector<double>{response.value().cbegin(), response.value().cend()};
  EXPECT_THAT(actual, ContainerEq(COEFFICIENTS));
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
  create_ao_voltage_chan(AO_MIN, AO_MAX);

  start_task();
  try {
    auto write_data = generate_random_data(AO_MIN, AO_MAX, 100);
    write_data[80] += AO_MAX;
    WriteAnalogF64Response write_response;
    write_analog_f64(write_data, write_response);
    FAIL() << "We shouldn't get here.";
  }
  catch (const nidevice_grpc::experimental::client::grpc_driver_error& ex) {
    expect_driver_error(ex, INVALID_AO_DATA_WRITE_ERROR);
  }
  stop_task();
}

TEST_F(NiDAQmxDriverApiTests, TaskWithAOChannel_GetNthTaskDevice_ReturnsDeviceForChannel)
{
  const double AO_MIN = 1.0;
  const double AO_MAX = 10.0;
  create_ao_voltage_chan(AO_MIN, AO_MAX);

  GetNthTaskDeviceResponse nth_device_response;
  auto status = get_nth_task_device(1, nth_device_response);

  EXPECT_SUCCESS(status, nth_device_response);
  EXPECT_EQ(DEVICE_NAME, nth_device_response.buffer());
}

TEST_F(NiDAQmxDriverApiTests, RunningTask_StopWithTaskControl_TaskIsDone)
{
  create_ao_voltage_chan(0.0, 1.0);
  start_task();
  EXPECT_FALSE(is_task_done());

  TaskControlResponse response;
  auto status = task_control(TaskControlAction::TASK_CONTROL_ACTION_TASK_STOP, response);

  EXPECT_SUCCESS(status, response);
  EXPECT_TRUE(is_task_done());
}

TEST_F(NiDAQmxDriverApiTests, CreateCIFreqChannel_Succeeds)
{
  CreateCIFreqChanResponse response;
  auto status = create_ci_freq_chan(response);

  EXPECT_SUCCESS(status, response);
}

TEST_F(NiDAQmxDriverApiTests, GetErrorString_ReturnsErrorMessage)
{
  GetErrorStringResponse response;
  auto status = get_error_string(INVALID_ATTRIBUTE_VALUE_ERROR, response);

  EXPECT_SUCCESS(status, response);
  const auto& error_string = response.error_string();
  EXPECT_THAT(
      error_string,
      StrEq("Requested value is not a supported value for this property. The property value may be invalid because it conflicts with another property."));
  // If we don't get the correct ivi-dance size we can get a string padded out with extra nulls.
  // Comparing to the length of the null-terminated c_str will catch this.
  EXPECT_EQ(error_string.length(), std::strlen(error_string.c_str()));
}

TEST_F(NiDAQmxDriverApiTests, ReadBinaryI32_Succeeds)
{
  create_ai_voltage_chan(-5.0, 5.0);
  start_task();

  const auto NUM_SAMPS = 4;
  auto response = client::read_binary_i32(
      stub(),
      task(),
      NUM_SAMPS,
      10.0,
      GroupBy::GROUP_BY_GROUP_BY_CHANNEL,
      NUM_SAMPS);
  stop_task();

  EXPECT_EQ(NUM_SAMPS, response.samps_per_chan_read());
}

TEST_F(NiDAQmxDriverApiTests, AOVoltageChannel_WriteBinaryI16_Succeeds)
{
  create_ao_voltage_chan(-5.0, 5.0);

  start_task();
  WriteBinaryI16Response response;
  auto status = write_binary_i16({12, -13, 32767, 15, -32768}, response);
  stop_task();

  EXPECT_SUCCESS(status, response);
}

TEST_F(NiDAQmxDriverApiTests, AIVoltageChannel_ReadBinaryI16_Succeeds)
{
  create_ai_voltage_chan(-5.0, 5.0);

  start_task();
  const auto NUM_SAMPS = 10;
  auto response = client::read_binary_i16(
      stub(),
      task(),
      NUM_SAMPS,
      10.0,
      GroupBy::GROUP_BY_GROUP_BY_CHANNEL,
      NUM_SAMPS);
  stop_task();

  EXPECT_EQ(NUM_SAMPS, response.samps_per_chan_read());
}

TEST_F(NiDAQmxDriverApiTests, AIVoltageChannel_ReadRaw_Succeeds)
{
  using TRaw = uint16_t;
  create_ai_voltage_chan(-5.0, 5.0);

  start_task();
  ReadRawResponse response;
  const auto NUM_SAMPS = 10;
  auto status = read_raw<TRaw>(NUM_SAMPS, response);
  stop_task();

  EXPECT_SUCCESS(status, response);
  EXPECT_EQ(NUM_SAMPS, response.samps_read());
  EXPECT_EQ(NUM_SAMPS * sizeof(TRaw), response.read_array().size());
  auto data_ptr = reinterpret_cast<const TRaw*>(response.read_array().data());
  auto data_vector = std::vector<TRaw>(data_ptr, data_ptr + NUM_SAMPS);
  EXPECT_THAT(data_vector, Each(Not(Eq(0))));
}

TEST_F(NiDAQmxDriverApiTests, AOVoltageChannel_WriteRaw_Succeeds)
{
  using TRaw = uint16_t;
  const auto RAW_DATA = std::vector<TRaw>{65046, 262, 97, 902, 882, 978, 1050, 1786, 1914, 2038};
  create_ao_voltage_chan(-5.0, 5.0);

  start_task();
  WriteRawResponse response;
  const auto NUM_SAMPS = 10;
  auto status = write_raw<TRaw>(RAW_DATA, response);
  stop_task();

  EXPECT_SUCCESS(status, response);
  EXPECT_EQ(NUM_SAMPS, response.samps_per_chan_written());
}

TEST_F(NiDAQmxDriverApiTests, AIVoltageChannel_CfgSampClkTimingAndAcquireData_Succeeds)
{
  create_ai_voltage_chan(0.0, 1.0);

  CfgSampClkTimingResponse response;
  auto config_status = cfg_samp_clk_timing(response);
  start_task();
  ReadAnalogF64Response read_response;
  const auto NUM_SAMPS = 10;
  auto read_status = read_analog_f64(NUM_SAMPS, NUM_SAMPS, read_response);
  stop_task();

  EXPECT_SUCCESS(config_status, response);
  EXPECT_SUCCESS(read_status, read_response);
  EXPECT_EQ(NUM_SAMPS, read_response.samps_per_chan_read());
}

TEST_F(NiDAQmxDriverApiTests, ChannelWithDoneEventRegistered_RunCompleteFiniteAcquisition_DoneEventResponseIsReceived)
{
  create_ai_voltage_chan(0.0, 1.0);
  ::grpc::ClientContext reader_context;
  auto reader = register_done_event(reader_context);
  reader->WaitForInitialMetadata();

  const auto FINITE_SAMPLE_COUNT = 10UL;
  cfg_samp_clk_timing(
      create_cfg_samp_clk_timing_request(1000.0, Edge1::EDGE1_UNSPECIFIED, AcquisitionType::ACQUISITION_TYPE_FINITE_SAMPS, FINITE_SAMPLE_COUNT));
  start_task();
  ReadAnalogF64Response read_response;
  auto read_status = read_analog_f64(FINITE_SAMPLE_COUNT, FINITE_SAMPLE_COUNT, read_response);
  EXPECT_SUCCESS(read_status, read_response);

  RegisterDoneEventResponse response;
  reader->Read(&response);
  EXPECT_EQ(DAQMX_SUCCESS, response.status());
}

TEST_F(NiDAQmxDriverApiTests, ChannelWithEveryNSamplesEventRegistered_WaitForSamplesMultipleTimes_Succeeds)
{
  const auto N_SAMPLES = 10UL;
  const auto N_READS = 10;
  create_ai_voltage_chan(0.0, 1.0);
  ::grpc::ClientContext reader_context;
  auto reader = register_every_n_samples_event(reader_context, N_SAMPLES);
  reader->WaitForInitialMetadata();
  cfg_samp_clk_timing(
      create_cfg_samp_clk_timing_request(1000.0, Edge1::EDGE1_UNSPECIFIED, AcquisitionType::ACQUISITION_TYPE_CONT_SAMPS, 0UL));

  start_task();
  RegisterEveryNSamplesEventResponse response;
  for (auto i = 0; i < N_READS; ++i) {
    reader->Read(&response);
    read_analog_f64(N_SAMPLES, N_SAMPLES);

    EXPECT_EQ(N_SAMPLES, response.n_samples());
    EXPECT_EQ(DAQMX_SUCCESS, response.status());
  }
}

TEST_F(NiDAQmxDriverApiTests, ChannelWithDoneEventRegisteredTwice_RunCompleteFiniteAcquisition_DoneEventResponseIsReceived)
{
  create_ai_voltage_chan(0.0, 1.0);
  ::grpc::ClientContext reader_context;
  auto reader = register_done_event(reader_context);
  reader->WaitForInitialMetadata();
  ::grpc::ClientContext second_reader_context;
  auto second_reader = register_done_event(second_reader_context);
  second_reader->WaitForInitialMetadata();

  const auto FINITE_SAMPLE_COUNT = 10UL;
  cfg_samp_clk_timing(
      create_cfg_samp_clk_timing_request(1000.0, Edge1::EDGE1_UNSPECIFIED, AcquisitionType::ACQUISITION_TYPE_FINITE_SAMPS, FINITE_SAMPLE_COUNT));
  start_task();
  ReadAnalogF64Response read_response;
  auto read_status = read_analog_f64(FINITE_SAMPLE_COUNT, FINITE_SAMPLE_COUNT, read_response);
  EXPECT_SUCCESS(read_status, read_response);

  RegisterDoneEventResponse response;
  reader->Read(&response);
  EXPECT_EQ(DAQMX_SUCCESS, response.status());
  second_reader->Read(&response);
  EXPECT_EQ(DONE_EVENT_ALREADY_REGISTERED_ERROR, response.status());
}

TEST_F(NiDAQmxDriverApiTests, AIVoltageChannel_ConfigureInputBuffer_Succeeds)
{
  create_ai_voltage_chan(0.0, 1.0);

  CfgInputBufferResponse response;
  auto status = cfg_input_buffer(response);

  EXPECT_SUCCESS(status, response);
}

TEST_F(NiDAQmxDriverApiTests, AOVoltageChannel_ConfigureOutputBuffer_Succeeds)
{
  create_ao_voltage_chan(0.0, 1.0);

  CfgOutputBufferResponse response;
  auto status = cfg_output_buffer(response);

  EXPECT_SUCCESS(status, response);
}

TEST_F(NiDAQmxDriverApiTests, SelfTestDevice_Succeeds)
{
  SelfTestDeviceResponse response;
  auto status = self_test_device(response);

  EXPECT_SUCCESS(status, response);
}

TEST_F(NiDAQmxDriverApiTests, CalculateReversePolyCoefficientsWithNegativeOneReverseOrder_ReturnsCoefficientsSizedToForwardCoefficients)
{
  auto const FORWARD_COEFFICIENTS = std::vector<double>{1.0, 3.0, 8.0};
  auto const REVERSE_ORDER = -1;
  auto request = create_calculate_reverse_poly_coeff_request(
      FORWARD_COEFFICIENTS,
      0.0,
      10.0,
      100,
      REVERSE_ORDER);
  auto response = CalculateReversePolyCoeffResponse{};
  auto status = calculate_reverse_poly_coeff(request, response);

  EXPECT_SUCCESS(status, response);
  EXPECT_EQ(FORWARD_COEFFICIENTS.size(), response.reverse_coeffs().size());
}

TEST_F(NiDAQmxDriverApiTests, CalculateReversePolyCoefficientsWithPositiveReverseOrder_ReturnsCoefficientsSizedToReverseOrderPlusOne)
{
  auto const REVERSE_ORDER = 10;
  auto request = create_calculate_reverse_poly_coeff_request(
      {1.0, 3.0, 8.0},
      0.0,
      10.0,
      100,
      REVERSE_ORDER);
  auto response = CalculateReversePolyCoeffResponse{};
  auto status = calculate_reverse_poly_coeff(request, response);

  EXPECT_SUCCESS(status, response);
  EXPECT_EQ(REVERSE_ORDER + 1, response.reverse_coeffs().size());
}

TEST_F(NiDAQmxDriverApiTests, AIVoltageChannel_WaitForValidTimestamp_ReturnsError)
{
  create_ai_voltage_chan(0.0, 1.0);

  try {
    auto response = WaitForValidTimestampResponse{};
    auto status = wait_for_valid_timestamp(response);
    FAIL() << "We shouldn't get here.";
  }
  catch (const nidevice_grpc::experimental::client::grpc_driver_error& ex) {
    expect_driver_error(ex, WAIT_FOR_VALID_TIMESTAMP_NOT_SUPPORTED_ERROR);
  }
}

TEST_F(NiDAQmxDriverApiTests, AIVoltageChannel_CfgTimeStartTrig_ReturnsError)
{
  create_ai_voltage_chan(0.0, 1.0);

  try {
    auto response = CfgTimeStartTrigResponse{};
    cfg_time_start_trig(response);
    FAIL() << "We shouldn't get here.";
  }
  catch (const nidevice_grpc::experimental::client::grpc_driver_error& ex) {
    expect_driver_error(ex, INVALID_ATTRIBUTE_VALUE_ERROR);
  }
}

TEST_F(NiDAQmxDriverApiTests, LoadedVoltageTask_ReadAIData_ReturnsDataInExpectedRange)
{
  const auto AI_MIN = 0.0;
  const auto AI_MAX = 1.0;
  const auto NUM_SAMPS = 10;
  create_ai_voltage_chan(AI_MIN, AI_MAX);
  auto save_response = SaveTaskResponse{};
  auto status = save_task(save_response);
  EXPECT_SUCCESS(status, save_response);
  clear_task();
  auto load_response = LoadTaskResponse{};
  status = load_task(load_response);
  EXPECT_SUCCESS(status, load_response);

  auto read_response = ReadAnalogF64Response{};
  status = read_analog_f64(NUM_SAMPS, NUM_SAMPS, read_response);

  EXPECT_SUCCESS(status, read_response);
  EXPECT_DATA_IN_RANGE(read_response.read_array(), AI_MIN, AI_MAX);
}

TEST_F(NiDAQmxDriverApiTests, SelfCal_Succeeds)
{
  auto response = SelfCalResponse{};
  auto status = self_cal(response);

  EXPECT_SUCCESS(status, response);
}

TEST_F(NiDAQmxDriverApiTests, AddNetworkDeviceWithInvalidIP_ErrorRetrievingNetworkDeviceProperties)
{
  try {
    auto response = AddNetworkDeviceResponse{};
    add_network_device("0.0.0.0", response);
    FAIL() << "We shouldn't get here.";
  }
  catch (const nidevice_grpc::experimental::client::grpc_driver_error& ex) {
    expect_driver_error(ex, RETRIEVING_NETWORK_DEVICE_PROPERTIES_ERROR);
  }
}

TEST_F(NiDAQmxDriverApiTests, ConfigureTEDSOnNonTEDSChannel_ErrorTEDSSensorNotDetected)
{
  try {
    client::configure_teds(stub(), AI_CHANNEL, "");
    FAIL() << "We shouldn't get here.";
  }
  catch (const nidevice_grpc::experimental::client::grpc_driver_error& ex) {
    expect_driver_error(ex, TEDS_SENSOR_NOT_DETECTED_ERROR);
  }
}

TEST_F(NiDAQmxDriverApiTests, HardwareTimedTask_WaitForNextSampleClock_Succeeds)
{
  create_ao_voltage_chan(0.0, 10.0);
  create_ai_voltage_chan(0.0, 10.0);
  auto cfg_response = client::cfg_samp_clk_timing(
      stub(),
      task(),
      "",
      100.0,
      Edge1::EDGE1_RISING,
      AcquisitionType::ACQUISITION_TYPE_HW_TIMED_SINGLE_POINT,
      1);
  EXPECT_SUCCESS(cfg_response);

  start_task();
  auto response = WaitForNextSampleClockResponse{};
  auto status = wait_for_next_sample_clock(response);

  EXPECT_SUCCESS(status, response);
}

TEST_F(NiDAQmxDriverApiTests, ConnectBogusTerms_FailsWithInvalidRoutingError)
{
  try {
    auto response = ConnectTermsResponse{};
    connect_terms("ABC", "123", response);
    FAIL() << "We shouldn't get here.";
  }
  catch (const nidevice_grpc::experimental::client::grpc_driver_error& ex) {
    expect_driver_error(ex, INVALID_TERM_ROUTING_ERROR);
  }
}

TEST_F(NiDAQmxDriverApiTests, DOWatchdogTask_StartTaskAndWatchdogTask_Succeeds)
{
  // Note: the DO chan will be the default task in this test.
  // The watchdog task is a separate task passed around through create_watchdog_response.
  create_do_chan();
  auto create_watchdog_response = CreateWatchdogTimerTaskExResponse{};
  auto create_status = create_watchdog_timer_task_ex(.001, create_watchdog_response);
  auto cfg_watchdog_response = CfgWatchdogDOExpirStatesResponse{};
  auto cfg_status = cfg_watchdog_do_expir_states(
      create_watchdog_response.task(),
      cfg_watchdog_response);
  EXPECT_SUCCESS(create_status, create_watchdog_response);
  EXPECT_SUCCESS(cfg_status, cfg_watchdog_response);

  start_task();
  auto start_watchdog_response = StartTaskResponse{};
  auto start_watchdog_status = start_task(
      create_watchdog_response.task(),
      start_watchdog_response);

  EXPECT_SUCCESS(start_watchdog_status, start_watchdog_response);
}

TEST_F(NiDAQmxDriverApiTests, AutoConfigureCDAQSyncConnections_ReturnsNotSupportedError)
{
  try {
    client::auto_configure_cdaq_sync_connections(stub(), DEVICE_NAME, 1.0);
    FAIL() << "We shouldn't get here.";
  }
  catch (const nidevice_grpc::experimental::client::grpc_driver_error& ex) {
    expect_driver_error(ex, DEVICE_DOES_NOT_SUPPORT_CDAQ_SYNC_CONNECTIONS_ERROR);
  }
}

TEST_F(NiDAQmxDriverApiTests, DIChannel_GetSetResetInputBufferSize_UpdatesBufferSize)
{
  create_di_chan();
  auto ATTRIBUTE = BufferUInt32Attribute::BUFFER_ATTRIBUTE_INPUT_BUF_SIZE;

  auto get_response = client::get_buffer_attribute_uint32(
      stub(),
      task(),
      ATTRIBUTE);
  auto initial_value = get_response.value();
  auto set_response = client::set_buffer_attribute_uint32(
      stub(),
      task(),
      ATTRIBUTE,
      initial_value * 2);
  auto readback_response = client::get_buffer_attribute_uint32(
      stub(),
      task(),
      ATTRIBUTE);
  auto reset_response = client::reset_buffer_attribute(
      stub(),
      task(),
      BufferResetAttribute::BUFFER_RESET_ATTRIBUTE_INPUT_BUF_SIZE);
  auto read_after_reset_response = client::get_buffer_attribute_uint32(
      stub(),
      task(),
      ATTRIBUTE);

  EXPECT_SUCCESS(get_response);
  EXPECT_SUCCESS(set_response);
  EXPECT_SUCCESS(readback_response);
  EXPECT_SUCCESS(reset_response);
  EXPECT_SUCCESS(read_after_reset_response);
  EXPECT_EQ(initial_value, read_after_reset_response.value());
  EXPECT_EQ(initial_value * 2, readback_response.value());
}

TEST_F(NiDAQmxDriverApiTests, GetAISupportMeasurementTypes_ResultIncludesCurrentAndVoltage)
{
  const auto ATTRIBUTE = DeviceInt32ArrayAttribute::DEVICE_ATTRIBUTE_AI_SUPPORTED_MEAS_TYPES;
  auto response = client::get_device_attribute_int32_array(stub(), DEVICE_NAME, ATTRIBUTE);

  EXPECT_SUCCESS(response);
  EXPECT_THAT(response.value(), Contains(DeviceInt32AttributeValues::DEVICE_INT32_AI_MEASUREMENT_TYPE_CURRENT));
  EXPECT_THAT(response.value(), Contains(DeviceInt32AttributeValues::DEVICE_INT32_AI_MEASUREMENT_TYPE_VOLTAGE));
  EXPECT_THAT(response.value_raw(), Contains(DeviceInt32AttributeValues::DEVICE_INT32_AI_MEASUREMENT_TYPE_CURRENT));
  EXPECT_THAT(response.value_raw(), Contains(DeviceInt32AttributeValues::DEVICE_INT32_AI_MEASUREMENT_TYPE_VOLTAGE));
}

TEST_F(NiDAQmxDriverApiTests, AOChannel_GetAOMax_ReturnsAOMax)
{
  const auto A0_MIN = -10.0;
  const auto AO_MAX = 10.0;
  const auto CHANNEL_NAME = "AO Channel";
  create_ao_voltage_chan(
      create_ao_voltage_chan_request(A0_MIN, AO_MAX, CHANNEL_NAME));

  auto response = client::get_chan_attribute_double(
      stub(),
      task(),
      CHANNEL_NAME,
      ChannelDoubleAttribute::CHANNEL_ATTRIBUTE_AO_MAX);

  EXPECT_SUCCESS(response);
  EXPECT_NEAR(AO_MAX, response.value(), 0.0001);
}

TEST_F(NiDAQmxDriverApiTests, AOChannel_SetAndGetAllowConnToGround_SucceedsAndReturnsSetValue)
{
  const auto CHANNEL_NAME = "AO Channel";
  create_ao_voltage_chan(
      create_ao_voltage_chan_request(-1.0, 1.0, CHANNEL_NAME));

  auto initial_get_response = client::get_chan_attribute_bool(
      stub(),
      task(),
      CHANNEL_NAME,
      ChannelBoolAttribute::CHANNEL_ATTRIBUTE_AO_DAC_REF_ALLOW_CONN_TO_GND);
  auto set_response = client::set_chan_attribute_bool(
      stub(),
      task(),
      CHANNEL_NAME,
      ChannelBoolAttribute::CHANNEL_ATTRIBUTE_AO_DAC_REF_ALLOW_CONN_TO_GND,
      true);
  auto get_response = client::get_chan_attribute_bool(
      stub(),
      task(),
      CHANNEL_NAME,
      ChannelBoolAttribute::CHANNEL_ATTRIBUTE_AO_DAC_REF_ALLOW_CONN_TO_GND);

  EXPECT_SUCCESS(set_response);
  EXPECT_SUCCESS(set_response);
  EXPECT_SUCCESS(get_response);
  EXPECT_FALSE(initial_get_response.value());
  EXPECT_TRUE(get_response.value());
}

TEST_F(NiDAQmxDriverApiTests, AOChannel_GetAOOutputType_SucceedsAndReturnsVoltage)
{
  const auto CHANNEL_NAME = "AO Channel";
  create_ao_voltage_chan(
      create_ao_voltage_chan_request(-1.0, 1.0, CHANNEL_NAME));

  auto response = client::get_chan_attribute_int32(
      stub(),
      task(),
      CHANNEL_NAME,
      ChannelInt32Attribute::CHANNEL_ATTRIBUTE_AO_OUTPUT_TYPE);

  EXPECT_SUCCESS(response);
  EXPECT_EQ(
      ChannelInt32AttributeValues::CHANNEL_INT32_AO_OUTPUT_CHANNEL_TYPE_VOLTAGE,
      response.value());
}

TEST_F(NiDAQmxDriverApiTests, TaskWithChannel_GetTaskAttributes_ReturnsCorrectResults)
{
  const auto CHANNEL_NAME = "AO Channel";
  create_ao_voltage_chan(
      create_ao_voltage_chan_request(-1.0, 1.0, CHANNEL_NAME));
  start_task();

  auto num_chans_response = client::get_task_attribute_uint32(stub(), task(), TaskUInt32Attribute::TASK_ATTRIBUTE_NUM_CHANS);
  auto channels_response = client::get_task_attribute_string(stub(), task(), TaskStringAttribute::TASK_ATTRIBUTE_CHANNELS);
  auto complete_response = client::get_task_attribute_bool(stub(), task(), TaskBoolAttribute::TASK_ATTRIBUTE_COMPLETE);

  EXPECT_SUCCESS(num_chans_response);
  EXPECT_SUCCESS(channels_response);
  EXPECT_SUCCESS(complete_response);
  EXPECT_EQ(1, num_chans_response.value());
  EXPECT_EQ(CHANNEL_NAME, channels_response.value());
  EXPECT_FALSE(complete_response.value());
}

TEST_F(NiDAQmxDriverApiTests, AIChannelWithSampleClock_ReconfigureRate_UpdatesRateSuccessfully)
{
  const auto INITIAL_RATE = 100.0;
  const auto RECONFIGURED_RATE = 200.0;
  create_ai_voltage_chan(0.0, 10.0);
  auto cfg_request = create_cfg_samp_clk_timing_request(INITIAL_RATE, Edge1::EDGE1_RISING, AcquisitionType::ACQUISITION_TYPE_CONT_SAMPS, 1U);
  cfg_samp_clk_timing(cfg_request);

  auto initial_response = client::get_timing_attribute_double(stub(), task(), TimingDoubleAttribute::TIMING_ATTRIBUTE_SAMP_CLK_RATE);
  auto set_response = client::set_timing_attribute_double(stub(), task(), TimingDoubleAttribute::TIMING_ATTRIBUTE_SAMP_CLK_RATE, RECONFIGURED_RATE);
  auto get_response = client::get_timing_attribute_double(stub(), task(), TimingDoubleAttribute::TIMING_ATTRIBUTE_SAMP_CLK_RATE);

  EXPECT_SUCCESS(initial_response);
  EXPECT_SUCCESS(set_response);
  EXPECT_SUCCESS(get_response);
  EXPECT_NEAR(INITIAL_RATE, initial_response.value(), .0001);
  EXPECT_NEAR(RECONFIGURED_RATE, get_response.value(), .0001);
}

TEST_F(NiDAQmxDriverApiTests, AIChannel_ReconfigureOverwrite_UpdatesOverwriteSuccessfully)
{
  const auto NEW_VALUE = ReadInt32AttributeValues::READ_INT32_OVERWRITE_MODE1_OVERWRITE_UNREAD_SAMPS;
  create_ai_voltage_chan(-5.0, 5.0);

  auto initial_response = client::get_read_attribute_int32(stub(), task(), ReadInt32Attribute::READ_ATTRIBUTE_OVERWRITE);
  auto set_response = client::set_read_attribute_int32(stub(), task(), ReadInt32Attribute::READ_ATTRIBUTE_OVERWRITE, NEW_VALUE);
  auto get_response = client::get_read_attribute_int32(stub(), task(), ReadInt32Attribute::READ_ATTRIBUTE_OVERWRITE);

  EXPECT_SUCCESS(initial_response);
  EXPECT_SUCCESS(set_response);
  EXPECT_SUCCESS(get_response);
  EXPECT_EQ(NEW_VALUE, get_response.value());
  EXPECT_NE(get_response.value(), initial_response.value());
}

TEST_F(NiDAQmxDriverApiTests, AOChannel_ReconfigureSleepTime_UpdatesSleepTimeSuccessfully)
{
  const auto NEW_VALUE = 100.0;
  create_ao_voltage_chan(-10.0, 10.0);

  auto initial_response = client::get_write_attribute_double(stub(), task(), WriteDoubleAttribute::WRITE_ATTRIBUTE_SLEEP_TIME);
  auto set_response = client::set_write_attribute_double(stub(), task(), WriteDoubleAttribute::WRITE_ATTRIBUTE_SLEEP_TIME, NEW_VALUE);
  auto get_response = client::get_write_attribute_double(stub(), task(), WriteDoubleAttribute::WRITE_ATTRIBUTE_SLEEP_TIME);

  EXPECT_SUCCESS(initial_response);
  EXPECT_SUCCESS(set_response);
  EXPECT_SUCCESS(get_response);
  EXPECT_NEAR(NEW_VALUE, get_response.value(), .0001);
  EXPECT_NE(get_response.value(), initial_response.value());
}

TEST_F(NiDAQmxDriverApiTests, AIChannel_ReconfigureSampQuantSampsPerChan_UpdatesSampQuantSampsPerChanSuccessfully)
{
  const auto SAMPS_PER_CHAN_ATTRIBUTE = TimingUInt64Attribute::TIMING_ATTRIBUTE_SAMP_QUANT_SAMP_PER_CHAN;
  const auto RECONFIGURED_SAMPS_PER_CHAN = 2000ULL;
  create_ai_voltage_chan(-10.0, 10.0);

  auto initial_response = client::get_timing_attribute_uint64(
      stub(),
      task(),
      SAMPS_PER_CHAN_ATTRIBUTE);
  auto set_response = client::set_timing_attribute_uint64(
      stub(),
      task(),
      SAMPS_PER_CHAN_ATTRIBUTE,
      RECONFIGURED_SAMPS_PER_CHAN);
  auto get_response = client::get_timing_attribute_uint64(
      stub(),
      task(),
      SAMPS_PER_CHAN_ATTRIBUTE);

  EXPECT_SUCCESS(initial_response);
  EXPECT_SUCCESS(set_response);
  EXPECT_SUCCESS(get_response);
  EXPECT_EQ(1000ULL, initial_response.value());
  EXPECT_EQ(RECONFIGURED_SAMPS_PER_CHAN, get_response.value());
}

TEST_F(NiDAQmxDriverApiTests, SetWrongCategoryAttribute_ReturnsNotValidError)
{
  try {
    client::get_device_attribute_bool(stub(), DEVICE_NAME, ScaleDoubleAttribute::SCALE_ATTRIBUTE_LIN_SLOPE);
    FAIL() << "We shouldn't get here.";
  }
  catch (const nidevice_grpc::experimental::client::grpc_driver_error& ex) {
    expect_driver_error(ex, SPECIFIED_ATTRIBUTE_NOT_VALID_ERROR);
  }
}

TEST_F(NiDAQmxDriverApiTests, SetWrongDataTypeAttribute_ReturnsNotValidError)
{
  try {
    client::get_device_attribute_bool(stub(), DEVICE_NAME, DeviceStringAttribute::DEVICE_ATTRIBUTE_AO_PHYSICAL_CHANS);
    FAIL() << "We shouldn't get here.";
  }
  catch (const nidevice_grpc::experimental::client::grpc_driver_error& ex) {
    expect_driver_error(ex, SPECIFIED_ATTRIBUTE_NOT_VALID_ERROR);
  }
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
