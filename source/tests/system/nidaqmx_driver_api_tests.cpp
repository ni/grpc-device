#include <gmock/gmock.h>
#include <google/protobuf/util/time_util.h>
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
  const std::string DEVICE_NAME{"gRPCSystemTestDAQ"};

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
        {DEVICE_NAME, "NI PXIe-6341"}};

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
      if (matched_required_device != required_devices.cend() && matched_required_device->second == device.model()) {
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

  ::grpc::Status clear_task(ClearTaskResponse& response = ThrowawayResponse<ClearTaskResponse>::response())
  {
    ::grpc::ClientContext context;
    ClearTaskRequest request;
    set_request_session_id(request);
    return stub()->ClearTask(&context, request, &response);
  }

  CreateAIVoltageChanRequest create_ai_voltage_request(double min_val, double max_val, const std::string& custom_scale_name = "")
  {
    CreateAIVoltageChanRequest request;
    set_request_session_id(request);
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

  ::grpc::Status create_ao_voltage_chan(double min_val, double max_val, CreateAOVoltageChanResponse& response = ThrowawayResponse<CreateAOVoltageChanResponse>::response())
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

  ::grpc::Status create_di_chan(CreateDIChanResponse& response = ThrowawayResponse<CreateDIChanResponse>::response())
  {
    ::grpc::ClientContext context;
    CreateDIChanRequest request;
    set_request_session_id(request);
    request.set_lines("gRPCSystemTestDAQ/port0/line0");
    request.set_name_to_assign_to_lines("di");
    request.set_line_grouping(LineGrouping::LINE_GROUPING_CHAN_PER_LINE);
    return stub()->CreateDIChan(&context, request, &response);
  }

  ::grpc::Status create_do_chan(CreateDOChanResponse& response = ThrowawayResponse<CreateDOChanResponse>::response())
  {
    ::grpc::ClientContext context;
    CreateDOChanRequest request;
    set_request_session_id(request);
    request.set_lines("gRPCSystemTestDAQ/port1/line0");
    request.set_name_to_assign_to_lines("do");
    request.set_line_grouping(LineGrouping::LINE_GROUPING_CHAN_PER_LINE);
    return stub()->CreateDOChan(&context, request, &response);
  }

  ::grpc::Status create_ci_freq_chan(CreateCIFreqChanResponse& response)
  {
    ::grpc::ClientContext context;
    CreateCIFreqChanRequest request;
    set_request_session_id(request);
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
    request.set_buffer_size(4096);
    request.set_error_code(error_code);
    return stub()->GetErrorString(&context, request, &response);
  }

  ::grpc::Status start_task(const ::nidevice_grpc::Session& session, StartTaskResponse& response)
  {
    ::grpc::ClientContext context;
    StartTaskRequest request;
    set_request_session_id(request, session);
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
    set_request_session_id(request);
    return stub()->StopTask(&context, request, &response);
  }

  ::grpc::Status read_analog_f64(
      int32 samps_per_chan,
      uint32 array_size_in_samps,
      ReadAnalogF64Response& response = ThrowawayResponse<ReadAnalogF64Response>::response())
  {
    ::grpc::ClientContext context;
    ReadAnalogF64Request request;
    set_request_session_id(request);
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
    set_request_session_id(request);
    request.set_num_samps_per_chan(static_cast<int32_t>(data.size()));
    request.set_auto_start(false);
    request.mutable_write_array()->Add(data.cbegin(), data.cend());
    request.set_data_layout(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    return stub()->WriteAnalogF64(&context, request, &response);
  }

  ::grpc::Status write_u32_digital_data(WriteDigitalU32Response& response)
  {
    ::grpc::ClientContext context;
    WriteDigitalU32Request request;
    set_request_session_id(request);
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
    set_request_session_id(request);
    request.set_num_samps_per_chan(4);
    request.set_array_size_in_samps(4);
    request.set_fill_mode(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    return stub()->ReadDigitalU32(&context, request, &response);
  }

  ::grpc::Status write_u16_digital_data(WriteDigitalU16Response& response)
  {
    ::grpc::ClientContext context;
    WriteDigitalU16Request request;
    set_request_session_id(request);
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
    set_request_session_id(request);
    request.set_num_samps_per_chan(4);
    request.set_array_size_in_samps(4);
    request.set_fill_mode(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    return stub()->ReadDigitalU16(&context, request, &response);
  }

  ::grpc::Status write_u8_digital_data(WriteDigitalU8Response& response)
  {
    ::grpc::ClientContext context;
    WriteDigitalU8Request request;
    set_request_session_id(request);
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
    set_request_session_id(request);
    request.set_num_samps_per_chan(4);
    request.set_array_size_in_samps(4);
    request.set_fill_mode(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    return stub()->ReadDigitalU8(&context, request, &response);
  }

  ::grpc::Status read_binary_i32(int32 samples_to_read, ReadBinaryI32Response& response)
  {
    ::grpc::ClientContext context;
    ReadBinaryI32Request request;
    set_request_session_id(request);
    request.set_num_samps_per_chan(samples_to_read);
    request.set_array_size_in_samps(samples_to_read);
    request.set_fill_mode(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    return stub()->ReadBinaryI32(&context, request, &response);
  }

  ::grpc::Status read_binary_i16(int32 samples_to_read, ReadBinaryI16Response& response)
  {
    ::grpc::ClientContext context;
    ReadBinaryI16Request request;
    set_request_session_id(request);
    request.set_num_samps_per_chan(samples_to_read);
    request.set_array_size_in_samps(samples_to_read);
    request.set_fill_mode(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    return stub()->ReadBinaryI16(&context, request, &response);
  }

  ::grpc::Status write_binary_i16(const std::vector<int16>& data, WriteBinaryI16Response& response)
  {
    ::grpc::ClientContext context;
    WriteBinaryI16Request request;
    set_request_session_id(request);
    request.set_num_samps_per_chan(static_cast<uint32>(data.size()));
    request.mutable_write_array()->CopyFrom({data.cbegin(), data.cend()});
    request.set_data_layout(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    return stub()->WriteBinaryI16(&context, request, &response);
  }

  ::grpc::Status get_nth_task_device(uint32_t index, GetNthTaskDeviceResponse& response)
  {
    ::grpc::ClientContext context;
    GetNthTaskDeviceRequest request;
    set_request_session_id(request);
    request.set_index(index);
    request.set_buffer_size(256);

    return stub()->GetNthTaskDevice(&context, request, &response);
  }

  bool is_task_done()
  {
    ::grpc::ClientContext context;
    IsTaskDoneRequest request;
    set_request_session_id(request);
    IsTaskDoneResponse response;
    auto status = stub()->IsTaskDone(&context, request, &response);
    EXPECT_SUCCESS(status, response);
    return response.is_task_done();
  }

  ::grpc::Status task_control(TaskControlAction action, TaskControlResponse& response)
  {
    ::grpc::ClientContext context;
    TaskControlRequest request;
    set_request_session_id(request);
    request.set_action(action);
    return stub()->TaskControl(&context, request, &response);
  }

  auto register_done_event(::grpc::ClientContext& context)
  {
    RegisterDoneEventRequest request;
    set_request_session_id(request);
    return stub()->RegisterDoneEvent(&context, request);
  }
  auto register_every_n_samples_event(::grpc::ClientContext& context, uint32 n_samples)
  {
    RegisterEveryNSamplesEventRequest request;
    set_request_session_id(request);
    request.set_n_samples(n_samples);
    request.set_every_n_samples_event_type(EveryNSamplesEventType::EVERY_N_SAMPLES_EVENT_TYPE_ACQUIRED_INTO_BUFFER);
    return stub()->RegisterEveryNSamplesEvent(&context, request);
  }

  auto register_signal_event(::grpc::ClientContext& context, Signal2 signal_id)
  {
    RegisterSignalEventRequest request;
    set_request_session_id(request);
    request.set_signal_id(Signal2::SIGNAL2_SAMPLE_CLOCK);
    return stub()->RegisterSignalEvent(&context, request);
  }

  CfgSampClkTimingRequest create_cfg_samp_clk_timing_request(double rate, Edge1 active_edge, AcquisitionType sample_mode, uInt64 samples_per_chan)
  {
    CfgSampClkTimingRequest request;
    set_request_session_id(request);
    request.set_rate(rate);
    request.set_active_edge(active_edge);
    request.set_sample_mode(sample_mode);
    request.set_samps_per_chan(samples_per_chan);
    return request;
  }

  ::grpc::Status cfg_samp_clk_timing(CfgSampClkTimingResponse& response)
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
    set_request_session_id(request);
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
    set_request_session_id(request);
    request.set_num_samps_per_chan(1024U);
    return stub()->CfgInputBuffer(&context, request, &response);
  }

  ::grpc::Status cfg_output_buffer(CfgOutputBufferResponse& response)
  {
    ::grpc::ClientContext context;
    CfgOutputBufferRequest request;
    set_request_session_id(request);
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
    request.set_num_forward_coeffs_in(static_cast<int32>(forward_coeffs.size()));

    request.mutable_reverse_coeffs()->CopyFrom({reverse_coeffs.cbegin(), reverse_coeffs.cend()});
    request.set_num_reverse_coeffs_in(static_cast<int32>(reverse_coeffs.size()));

    request.set_pre_scaled_units(UnitsPreScaled::UNITS_PRE_SCALED_VOLTS);
    return stub()->CreatePolynomialScale(&context, request, &response);
  }

  ::grpc::Status create_ai_thrmcpl_chan(double min_val, double max_val, CreateAIThrmcplChanResponse& response)
  {
    ::grpc::ClientContext context;
    CreateAIThrmcplChanRequest request;
    set_request_session_id(request);
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
    request.set_num_forward_coeffs_in(static_cast<uint32>(forward_coeffs.size()));
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
    set_request_session_id(request);
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
    set_request_session_id(request);
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
    set_request_session_id(request);
    request.set_timestamp_event(TimestampEvent::TIMESTAMP_EVENT_FIRST_SAMPLE_TIMESTAMP);
    request.set_timeout(1.000);
    return stub()->WaitForValidTimestamp(&context, request, &response);
  }

  ::grpc::Status cfg_time_start_trig(CfgTimeStartTrigResponse& response)
  {
    ::grpc::ClientContext context;
    CfgTimeStartTrigRequest request;
    set_request_session_id(request);
    auto time = google::protobuf::util::TimeUtil::GetCurrentTime();
    auto duration = google::protobuf::Duration{};
    duration.set_seconds(10);
    time += duration;
    request.mutable_when()->CopyFrom(time);
    request.set_timescale(Timescale2::TIMESCALE2_IO_DEVICE_TIME);
    return stub()->CfgTimeStartTrig(&context, request, &response);
  }

  ::grpc::Status save_task(SaveTaskResponse& response)
  {
    ::grpc::ClientContext context;
    SaveTaskRequest request;
    set_request_session_id(request);
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
      EXPECT_NE(driver_session_->id(), response.task().id());
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
    request.set_device_name_out_buffer_size(1024);
    return stub()->AddNetworkDevice(&context, request, &response);
  }

  ::grpc::Status configure_teds(ConfigureTEDSResponse& response)
  {
    ::grpc::ClientContext context;
    ConfigureTEDSRequest request;
    request.set_physical_channel("gRPCSystemTestDAQ/ai0");
    return stub()->ConfigureTEDS(&context, request, &response);
  }

  template <typename TRequest, typename TAttributes>
  TRequest create_get_scale_attribute_request(const std::string& scale_name, TAttributes attribute)
  {
    TRequest request;
    request.set_scale_name(scale_name);
    request.set_attribute(attribute);
    return request;
  }

  template <typename TRequest, typename TAttributes>
  TRequest create_sized_get_scale_attribute_request(const std::string& scale_name, TAttributes attribute, size_t size)
  {
    auto request = create_get_scale_attribute_request<TRequest>(scale_name, attribute);
    request.set_size(static_cast<int32>(size));
    return request;
  }

  ::grpc::Status get_scale_attribute_double(const GetScaleAttributeDoubleRequest& request, GetScaleAttributeDoubleResponse& response)
  {
    ::grpc::ClientContext context;
    return stub()->GetScaleAttributeDouble(&context, request, &response);
  }

  ::grpc::Status get_scale_attribute_string(const GetScaleAttributeStringRequest& request, GetScaleAttributeStringResponse& response)
  {
    ::grpc::ClientContext context;
    return stub()->GetScaleAttributeString(&context, request, &response);
  }

  ::grpc::Status get_scale_attribute_double_array(const GetScaleAttributeDoubleArrayRequest& request, GetScaleAttributeDoubleArrayResponse& response)
  {
    ::grpc::ClientContext context;
    return stub()->GetScaleAttributeDoubleArray(&context, request, &response);
  }

  ::grpc::Status get_scale_attribute_i32(const GetScaleAttributeInt32Request& request, GetScaleAttributeInt32Response& response)
  {
    ::grpc::ClientContext context;
    return stub()->GetScaleAttributeInt32(&context, request, &response);
  }

  template <typename TRequest, typename T, typename TAttributes>
  TRequest create_set_scale_attribute_raw_request(const std::string& scale_name, TAttributes attribute, T value)
  {
    TRequest request;
    request.set_scale_name(scale_name);
    request.set_attribute(attribute);
    request.set_value_raw(value);
    return request;
  }

  template <typename TRequest, typename T, typename TAttributes>
  TRequest create_set_scale_attribute_request(const std::string& scale_name, TAttributes attribute, T value)
  {
    TRequest request;
    request.set_scale_name(scale_name);
    request.set_attribute(attribute);
    request.set_value(value);
    return request;
  }

  SetScaleAttributeDoubleArrayRequest create_set_scale_attribute_double_array_request(const std::string& scale_name, ScaleDoubleArrayAttributes attribute, const std::vector<double>& value)
  {
    SetScaleAttributeDoubleArrayRequest request;
    request.set_scale_name(scale_name);
    request.set_attribute(attribute);
    request.mutable_value()->CopyFrom({value.begin(), value.end()});
    request.set_size(static_cast<int32>(value.size()));
    return request;
  }

  ::grpc::Status set_scale_attribute_i32(const SetScaleAttributeInt32Request& request, SetScaleAttributeInt32Response& response)
  {
    ::grpc::ClientContext context;
    return stub()->SetScaleAttributeInt32(&context, request, &response);
  }

  ::grpc::Status set_scale_attribute_double(const SetScaleAttributeDoubleRequest& request, SetScaleAttributeDoubleResponse& response)
  {
    ::grpc::ClientContext context;
    return stub()->SetScaleAttributeDouble(&context, request, &response);
  }

  ::grpc::Status set_scale_attribute_double_array(const SetScaleAttributeDoubleArrayRequest& request, SetScaleAttributeDoubleArrayResponse& response)
  {
    ::grpc::ClientContext context;
    return stub()->SetScaleAttributeDoubleArray(&context, request, &response);
  }

  ::grpc::Status set_scale_attribute_string(const SetScaleAttributeStringRequest& request, SetScaleAttributeStringResponse& response)
  {
    ::grpc::ClientContext context;
    return stub()->SetScaleAttributeString(&context, request, &response);
  }

  ::grpc::Status wait_for_next_sample_clock(WaitForNextSampleClockResponse& response)
  {
    ::grpc::ClientContext context;
    WaitForNextSampleClockRequest request;
    set_request_session_id(request);
    request.set_timeout(10.0);
    return stub()->WaitForNextSampleClock(&context, request, &response);
  }

  ::grpc::Status connect_terms(const std::string& source, const std::string& destination, ConnectTermsResponse& response)
  {
    ::grpc::ClientContext context;
    ConnectTermsRequest request;
    request.set_source_terminal(source);
    request.set_destination_terminal(destination);
    request.set_signal_modifiers(InvertPolarity::INVERT_POLARITY_DO_NOT_INVERT_POLARITY);
    return stub()->ConnectTerms(&context, request, &response);
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

    set_request_session_id(request, watchdog_session);
    request.set_channel_names("gRPCSystemTestDAQ/port1/line0:1");
    auto expir_states = std::vector<DigitalLineState>{
        DigitalLineState::DIGITAL_LINE_STATE_HIGH,
        DigitalLineState::DIGITAL_LINE_STATE_HIGH};
    request.mutable_expir_state_array()->CopyFrom({expir_states.cbegin(), expir_states.cend()});
    request.set_array_size(2);
    return stub()->CfgWatchdogDOExpirStates(&context, request, &response);
  }

  ::grpc::Status auto_configure_cdaq_sync_connections(AutoConfigureCDAQSyncConnectionsResponse& response)
  {
    ::grpc::ClientContext context;
    AutoConfigureCDAQSyncConnectionsRequest request;
    request.set_chassis_devices_ports(DEVICE_NAME);
    request.set_timeout(1.0);
    return stub()->AutoConfigureCDAQSyncConnections(&context, request, &response);
  }

  std::unique_ptr<NiDAQmx::Stub>& stub()
  {
    return nidaqmx_stub_;
  }

  template <typename TRequest>
  void set_request_session_id(TRequest& request)
  {
    set_request_session_id(request, *driver_session_);
  }

  template <typename TRequest>
  void set_request_session_id(TRequest& request, const nidevice_grpc::Session& session)
  {
    request.mutable_task()->set_id(session.id());
  }

  template <typename TResponse>
  void EXPECT_SUCCESS(const ::grpc::Status& status, const TResponse& response)
  {
    EXPECT_EQ(DAQmxSuccess, response.status());
    EXPECT_EQ(::grpc::Status::OK.error_code(), status.error_code());
  }

  template <typename TResponse>
  void EXPECT_DAQ_ERROR(int32_t expected_error, const ::grpc::Status& status, const TResponse& response)
  {
    EXPECT_EQ(expected_error, response.status());
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
  CreateDOChanResponse response;
  auto status = create_do_chan(response);

  EXPECT_SUCCESS(status, response);
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

  auto request = create_get_scale_attribute_request<GetScaleAttributeDoubleRequest>(
      SCALE_NAME,
      ScaleDoubleAttributes::SCALE_ATTRIBUTE_LIN_SLOPE);
  GetScaleAttributeDoubleResponse response;
  auto status = get_scale_attribute_double(request, response);

  EXPECT_SUCCESS(status, response);
  EXPECT_NEAR(SLOPE, response.value(), .0001);
}

TEST_F(NiDAQmxDriverApiTests, SetYInterceptAttribute_GetYInterceptAttribute_ReturnsAttribute)
{
  const auto SCALE_NAME = std::string("TestScale");
  const auto Y_INTERCEPT = -3.0;
  auto scale_status = create_lin_scale(SCALE_NAME, 0.5);
  auto set_request = create_set_scale_attribute_request<SetScaleAttributeDoubleRequest>(
      SCALE_NAME,
      ScaleDoubleAttributes::SCALE_ATTRIBUTE_LIN_Y_INTERCEPT,
      Y_INTERCEPT);
  SetScaleAttributeDoubleResponse set_response;
  auto set_status = set_scale_attribute_double(set_request, set_response);
  auto request = create_get_scale_attribute_request<GetScaleAttributeDoubleRequest>(
      SCALE_NAME,
      ScaleDoubleAttributes::SCALE_ATTRIBUTE_LIN_Y_INTERCEPT);
  GetScaleAttributeDoubleResponse response;
  auto status = get_scale_attribute_double(request, response);

  EXPECT_SUCCESS(set_status, set_response);
  EXPECT_SUCCESS(status, response);
  EXPECT_NEAR(Y_INTERCEPT, response.value(), .0001);
}

TEST_F(NiDAQmxDriverApiTests, SetPreScaledUnits_GetPreScaledUnits_ReturnsAttribute)
{
  const auto SCALE_NAME = std::string("TestScale");
  const auto Y_INTERCEPT = -3.0;
  auto scale_status = create_lin_scale(SCALE_NAME, 0.5);
  auto set_request = create_set_scale_attribute_request<SetScaleAttributeInt32Request>(
      SCALE_NAME,
      ScaleInt32Attributes::SCALE_ATTRIBUTE_PRE_SCALED_UNITS,
      ScaleInt32AttributeValues::SCALE_INT32_UNITS_PRE_SCALED_RPM);
  SetScaleAttributeInt32Response set_response;
  auto set_status = set_scale_attribute_i32(set_request, set_response);

  auto request = create_get_scale_attribute_request<GetScaleAttributeInt32Request>(
      SCALE_NAME,
      ScaleInt32Attributes::SCALE_ATTRIBUTE_PRE_SCALED_UNITS);
  GetScaleAttributeInt32Response response;
  auto status = get_scale_attribute_i32(request, response);

  EXPECT_SUCCESS(set_status, set_response);
  EXPECT_SUCCESS(status, response);
  EXPECT_EQ(ScaleInt32AttributeValues::SCALE_INT32_UNITS_PRE_SCALED_RPM, response.value());
}

TEST_F(NiDAQmxDriverApiTests, GetScaledUnitsAsDouble_Fails)
{
  const auto SCALE_NAME = std::string("TestScale");
  const auto UNITS = std::string("Digits");
  auto scale_status = create_lin_scale(SCALE_NAME, 0.5);
  auto set_request = create_set_scale_attribute_request<SetScaleAttributeStringRequest>(
      SCALE_NAME,
      ScaleStringAttributes::SCALE_ATTRIBUTE_SCALED_UNITS,
      UNITS);
  SetScaleAttributeStringResponse set_response;
  auto set_status = set_scale_attribute_string(set_request, set_response);

  auto request = create_get_scale_attribute_request<GetScaleAttributeDoubleRequest>(
      SCALE_NAME,
      (ScaleDoubleAttributes)ScaleStringAttributes::SCALE_ATTRIBUTE_SCALED_UNITS);
  GetScaleAttributeDoubleResponse response;
  auto status = get_scale_attribute_double(request, response);

  EXPECT_NE(DAQmxSuccess, response.status());
  // Getting a scalar from a non-scalar field returns a positive value because that's the convention
  // when you pass in zero for the size (returns the size).
  // The key result here is: don't crash.
  EXPECT_GT(response.status(), 0);
}

TEST_F(NiDAQmxDriverApiTests, SetScaledUnits_GetScaledUnits_ReturnsAttribute)
{
  const auto SCALE_NAME = std::string("TestScale");
  const auto UNITS = std::string("Battalions");
  auto scale_status = create_lin_scale(SCALE_NAME, 0.5);
  auto set_request = create_set_scale_attribute_request<SetScaleAttributeStringRequest>(
      SCALE_NAME,
      ScaleStringAttributes::SCALE_ATTRIBUTE_SCALED_UNITS,
      UNITS);
  SetScaleAttributeStringResponse set_response;
  auto set_status = set_scale_attribute_string(set_request, set_response);

  auto request = create_sized_get_scale_attribute_request<GetScaleAttributeStringRequest>(
      SCALE_NAME,
      ScaleStringAttributes::SCALE_ATTRIBUTE_SCALED_UNITS,
      UNITS.length() + 1);
  GetScaleAttributeStringResponse response;
  auto status = get_scale_attribute_string(request, response);

  EXPECT_SUCCESS(set_status, set_response);
  EXPECT_SUCCESS(status, response);
  EXPECT_EQ(UNITS, response.value());
}

TEST_F(NiDAQmxDriverApiTests, SetPolynomialForwardCoefficients_GetPolynomialForwardCoefficients_ReturnsAttribute)
{
  const auto SCALE_NAME = std::string("TestPolynomialScale");
  const auto INITIAL_COEFFICIENTS = std::vector<double>{1.0, 2.0, 3.0};
  const auto COEFFICIENTS = std::vector<double>{1.0, 3.0, 8.0};
  auto scale_status = create_polynomial_scale(SCALE_NAME, INITIAL_COEFFICIENTS, INITIAL_COEFFICIENTS);
  auto set_request = create_set_scale_attribute_double_array_request(
      SCALE_NAME,
      ScaleDoubleArrayAttributes::SCALE_ATTRIBUTE_POLY_FORWARD_COEFF,
      COEFFICIENTS);
  SetScaleAttributeDoubleArrayResponse set_response;
  auto set_status = set_scale_attribute_double_array(set_request, set_response);

  auto request = create_sized_get_scale_attribute_request<GetScaleAttributeDoubleArrayRequest>(
      SCALE_NAME,
      ScaleDoubleArrayAttributes::SCALE_ATTRIBUTE_POLY_FORWARD_COEFF,
      COEFFICIENTS.size());
  GetScaleAttributeDoubleArrayResponse response;
  auto status = get_scale_attribute_double_array(request, response);

  EXPECT_SUCCESS(set_status, set_response);
  EXPECT_SUCCESS(status, response);
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
  create_ao_voltage_chan(AO_MIN, AO_MAX);

  GetNthTaskDeviceResponse nth_device_response;
  auto status = get_nth_task_device(1, nth_device_response);

  EXPECT_SUCCESS(status, nth_device_response);
  auto trimmed_string = std::string(nth_device_response.buffer().c_str());
  EXPECT_EQ(DEVICE_NAME, trimmed_string);
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
  auto status = get_error_string(DAQmxErrorInvalidAttributeValue, response);

  EXPECT_SUCCESS(status, response);
  EXPECT_THAT(response.error_string(), HasSubstr("Requested value is not a supported value for this property."));
}

TEST_F(NiDAQmxDriverApiTests, ReadBinaryI32_Succeeds)
{
  create_ai_voltage_chan(-5.0, 5.0);
  start_task();

  ReadBinaryI32Response response;
  const auto NUM_SAMPS = 4;
  auto status = read_binary_i32(NUM_SAMPS, response);
  stop_task();

  EXPECT_SUCCESS(status, response);
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
  ReadBinaryI16Response response;
  const auto NUM_SAMPS = 10;
  auto status = read_binary_i16(NUM_SAMPS, response);
  stop_task();

  EXPECT_SUCCESS(status, response);
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
  EXPECT_EQ(DAQmxSuccess, response.status());
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
    EXPECT_EQ(DAQmxSuccess, response.status());
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
  EXPECT_EQ(DAQmxSuccess, response.status());
  second_reader->Read(&response);
  EXPECT_EQ(DAQmxErrorDoneEventAlreadyRegistered, response.status());
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

  auto response = WaitForValidTimestampResponse{};
  auto status = wait_for_valid_timestamp(response);

  EXPECT_DAQ_ERROR(DAQmxErrorWaitForValidTimestampNotSupported, status, response);
}

TEST_F(NiDAQmxDriverApiTests, AIVoltageChannel_CfgTimeStartTrig_ReturnsError)
{
  create_ai_voltage_chan(0.0, 1.0);

  auto response = CfgTimeStartTrigResponse{};
  auto status = cfg_time_start_trig(response);

  EXPECT_DAQ_ERROR(DAQmxErrorInvalidAttributeValue, status, response);
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
  auto response = AddNetworkDeviceResponse{};
  auto status = add_network_device("0.0.0.0", response);

  EXPECT_DAQ_ERROR(DAQmxErrorRetrievingNetworkDeviceProperties, status, response);
}

TEST_F(NiDAQmxDriverApiTests, ConfigureTEDSOnNonTEDSChannel_ErrorTEDSSensorNotDetected)
{
  auto response = ConfigureTEDSResponse{};
  auto status = configure_teds(response);

  EXPECT_DAQ_ERROR(DAQmxErrorTEDSSensorNotDetected, status, response);
}

TEST_F(NiDAQmxDriverApiTests, HardwareTimedTask_WaitForNextSampleClock_Succeeds)
{
  create_ao_voltage_chan(0.0, 10.0);
  create_ai_voltage_chan(0.0, 10.0);
  auto cfg_request = create_cfg_samp_clk_timing_request(
      100.0,
      Edge1::EDGE1_RISING,
      AcquisitionType::ACQUISITION_TYPE_HW_TIMED_SINGLE_POINT,
      1);
  auto cfg_response = CfgSampClkTimingResponse{};
  auto cfg_status = cfg_samp_clk_timing(cfg_request, cfg_response);
  EXPECT_SUCCESS(cfg_status, cfg_response);

  start_task();
  auto response = WaitForNextSampleClockResponse{};
  auto status = wait_for_next_sample_clock(response);

  EXPECT_SUCCESS(status, response);
}

TEST_F(NiDAQmxDriverApiTests, ConnectBogusTerms_FailsWithInvalidRoutingError)
{
  auto response = ConnectTermsResponse{};
  auto status = connect_terms("ABC", "123", response);

  EXPECT_DAQ_ERROR(DAQmxErrorInvalidTerm_Routing, status, response);
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
  auto response = AutoConfigureCDAQSyncConnectionsResponse{};
  auto status = auto_configure_cdaq_sync_connections(response);

  EXPECT_DAQ_ERROR(DAQmxErrorDeviceDoesNotSupportCDAQSyncConnections, status, response);
}
}  // namespace system
}  // namespace tests
}  // namespace ni
