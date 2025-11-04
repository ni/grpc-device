#include <gmock/gmock.h>
#include <google/protobuf/util/time_util.h>

#include <algorithm>
#include <chrono>
#include <cstring>
#include <nlohmann/json.hpp>
#include <random>
#include <stdexcept>
#include <vector>

#include "device_server.h"
#include "enumerate_devices.h"
#include "nidaqmx/nidaqmx_client.h"
#include "server/converters.h"
#include "tests/utilities/async_helpers.h"
#include "tests/utilities/scope_exit.h"
#include "tests/utilities/test_helpers.h"

using namespace ::testing;
using namespace nidaqmx_grpc;
using google::protobuf::uint32;
using nidevice_grpc::converters::SecondsFromCVI1904EpochTo1970Epoch;
namespace client = nidaqmx_grpc::experimental::client;

namespace ni {
namespace tests {
namespace system {
namespace {

typedef ::google::protobuf::int16 int16;
typedef ::google::protobuf::int32 int32;
typedef ::google::protobuf::int64 int64;
typedef ::google::protobuf::uint64 uInt64;
typedef double float64;

constexpr auto DAQMX_SUCCESS = 0;
constexpr auto SAMPLES_NOT_YET_AVAILABLE_ERROR = -200284;
constexpr auto SPECIFIED_ATTRIBUTE_NOT_VALID_ERROR = -200233;
constexpr auto INVALID_AO_DATA_WRITE_ERROR = -200561;
constexpr auto DONE_EVENT_ALREADY_REGISTERED_ERROR = -200950;
constexpr auto WAIT_FOR_VALID_TIMESTAMP_NOT_SUPPORTED_ERROR = -209833;
constexpr auto INVALID_ATTRIBUTE_VALUE_ERROR = -200077;
constexpr auto RETRIEVING_NETWORK_DEVICE_PROPERTIES_ERROR = -201401;
constexpr auto TEDS_SENSOR_NOT_DETECTED_ERROR = -200709;
constexpr auto INVALID_TERM_ROUTING_ERROR = -89129;
constexpr auto DEVICE_DOES_NOT_SUPPORT_CDAQ_SYNC_CONNECTIONS_ERROR = -201450;
constexpr auto EVERY_N_SAMPLES_EVENT_NOT_SUPPORTED_FOR_NON_BUFFERED_TASKS = -200848;
constexpr auto EVERY_N_SAMPS_TRANSFERRED_FROM_BUFFER_EVENT_NOT_SUPPORTED_BY_DEVICE_ERROR = -200980;
constexpr auto CANNOT_UNREGISTER_DAQMX_SOFTWARE_EVENT_WHILE_TASK_IS_RUNNING_ERROR = -200986;
constexpr auto STRAIN_SHUNT_CAL_NOT_SUPPORTED_ERROR = -201203;
constexpr auto BRIDGE_SHUNT_CAL_NOT_SUPPORTED_ERROR = -201204;
constexpr auto THRMCPL_LEAD_OFFSET_NULLING_CAL_NOT_SUPPORTED_ERROR = -201375;
constexpr auto BRIDGE_OFFSET_NULLING_CAL_NOT_SUPPORTED_ERROR = -200696;

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
  const std::string AI_CHANNEL_1{"gRPCSystemTestDAQ/ai1"};
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
    auto status = stub()->CreateTask(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ClearTaskResponse clear_task(const nidevice_grpc::Session& task)
  {
    return client::clear_task(stub(), task);
  }

  ClearTaskResponse clear_task()
  {
    return clear_task(task());
  }

  CreateAIVoltageChanRequest create_ai_voltage_request(double min_val, double max_val, const std::string& custom_scale_name = "", const std::string& physical_channel = "gRPCSystemTestDAQ/ai0", const std::string& channel_name = "ai0")
  {
    CreateAIVoltageChanRequest request;
    set_request_session_name(request);
    request.set_physical_channel(physical_channel);
    request.set_name_to_assign_to_channel(channel_name);
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
    auto status = stub()->CreateAIVoltageChan(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status create_ai_voltage_chan(double min_val, double max_val, CreateAIVoltageChanResponse& response = ThrowawayResponse<CreateAIVoltageChanResponse>::response())
  {
    auto request = create_ai_voltage_request(min_val, max_val);
    return create_ai_voltage_chan(request, response);
  }

  ::grpc::Status create_ai_voltage_chan(const std::string& physical_channel, const std::string& channel_name, double min_val, double max_val, CreateAIVoltageChanResponse& response = ThrowawayResponse<CreateAIVoltageChanResponse>::response())
  {
    auto request = create_ai_voltage_request(min_val, max_val, "", physical_channel, channel_name);
    return create_ai_voltage_chan(request, response);
  }

  CreateAIBridgeChanRequest create_ai_bridge_request(double min_val, double max_val, const std::string& custom_scale_name = "")
  {
    CreateAIBridgeChanRequest request;
    set_request_session_name(request);
    request.set_physical_channel("gRPCSystemTestDAQ/ai0");
    request.set_name_to_assign_to_channel("ai0");
    request.set_min_val(min_val);
    request.set_max_val(max_val);
    if (custom_scale_name.empty()) {
      request.set_units(BridgeUnits::BRIDGE_UNITS_VOLTS_PER_VOLT);
    }
    else {
      request.set_custom_scale_name(custom_scale_name);
      request.set_units(BridgeUnits::BRIDGE_UNITS_FROM_CUSTOM_SCALE);
    }
    request.set_bridge_config(BridgeConfiguration1::BRIDGE_CONFIGURATION1_FULL_BRIDGE);
    request.set_voltage_excit_source(ExcitationSource::EXCITATION_SOURCE_INTERNAL);
    request.set_voltage_excit_val(2.50);
    request.set_nominal_bridge_resistance(350.00);
    return request;
  }

  ::grpc::Status create_ai_bridge_chan(const CreateAIBridgeChanRequest& request, CreateAIBridgeChanResponse& response = ThrowawayResponse<CreateAIBridgeChanResponse>::response())
  {
    ::grpc::ClientContext context;
    auto status = stub()->CreateAIBridgeChan(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status create_ai_bridge_chan(double min_val, double max_val, CreateAIBridgeChanResponse& response = ThrowawayResponse<CreateAIBridgeChanResponse>::response())
  {
    auto request = create_ai_bridge_request(min_val, max_val);
    return create_ai_bridge_chan(request, response);
  }

  CreateAIStrainGageChanRequest create_ai_strain_gage_request(double min_val, double max_val, const std::string& custom_scale_name = "")
  {
    CreateAIStrainGageChanRequest request;
    set_request_session_name(request);
    request.set_physical_channel("gRPCSystemTestDAQ/ai0");
    request.set_name_to_assign_to_channel("ai0");
    request.set_min_val(min_val);
    request.set_max_val(max_val);
    if (custom_scale_name.empty()) {
      request.set_units(StrainUnits1::STRAIN_UNITS1_STRAIN);
    }
    else {
      request.set_custom_scale_name(custom_scale_name);
      request.set_units(StrainUnits1::STRAIN_UNITS1_FROM_CUSTOM_SCALE);
    }
    request.set_strain_config(StrainGageBridgeType1::STRAIN_GAGE_BRIDGE_TYPE1_FULL_BRIDGE_I);
    request.set_initial_bridge_voltage(0.00);
    request.set_lead_wire_resistance(0.00);
    request.set_voltage_excit_source(ExcitationSource::EXCITATION_SOURCE_EXTERNAL);
    request.set_voltage_excit_val(2.50);
    request.set_gage_factor(2.00);
    request.set_poisson_ratio(0.30);
    request.set_nominal_gage_resistance(350.00);
    return request;
  }

  ::grpc::Status create_ai_strain_gage_chan(const CreateAIStrainGageChanRequest& request, CreateAIStrainGageChanResponse& response = ThrowawayResponse<CreateAIStrainGageChanResponse>::response())
  {
    ::grpc::ClientContext context;
    auto status = stub()->CreateAIStrainGageChan(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status create_ai_strain_gage_chan(double min_val, double max_val, CreateAIStrainGageChanResponse& response = ThrowawayResponse<CreateAIStrainGageChanResponse>::response())
  {
    auto request = create_ai_strain_gage_request(min_val, max_val);
    return create_ai_strain_gage_chan(request, response);
  }

  CreateAIThrmcplChanRequest create_ai_thrmcpl_request(double min_val, double max_val, const std::string& custom_scale_name = "")
  {
    CreateAIThrmcplChanRequest request;
    set_request_session_name(request);
    request.set_physical_channel("gRPCSystemTestDAQ/ai0");
    request.set_name_to_assign_to_channel("ai0");
    request.set_min_val(min_val);
    request.set_max_val(max_val);
    request.set_units(TemperatureUnits::TEMPERATURE_UNITS_DEG_C);
    request.set_thermocouple_type(ThermocoupleType1::THERMOCOUPLE_TYPE1_J_TYPE_TC);
    request.set_cjc_val(25.0);
    request.set_cjc_channel("");
    request.set_cjc_source(CJCSource1::CJC_SOURCE1_CONST_VAL);
    return request;
  }

  ::grpc::Status create_ai_thrmcpl_chan(const CreateAIThrmcplChanRequest& request, CreateAIThrmcplChanResponse& response = ThrowawayResponse<CreateAIThrmcplChanResponse>::response())
  {
    ::grpc::ClientContext context;
    auto status = stub()->CreateAIThrmcplChan(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status create_ai_thrmcpl_chan(double min_val, double max_val, CreateAIThrmcplChanResponse& response = ThrowawayResponse<CreateAIThrmcplChanResponse>::response())
  {
    auto request = create_ai_thrmcpl_request(min_val, max_val);
    return create_ai_thrmcpl_chan(request, response);
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
    auto status = stub()->CreateAOVoltageChan(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status create_ao_voltage_chan(double min_val, double max_val, CreateAOVoltageChanResponse& response = ThrowawayResponse<CreateAOVoltageChanResponse>::response())
  {
    auto request = create_ao_voltage_chan_request(min_val, max_val);
    return create_ao_voltage_chan(request, response);
  }

  ::grpc::Status create_ao_voltage_chan(const std::string& physical_channel, const std::string& channel_name, double min_val, double max_val, CreateAOVoltageChanResponse& response = ThrowawayResponse<CreateAOVoltageChanResponse>::response())
  {
    CreateAOVoltageChanRequest request;
    set_request_session_name(request);
    request.set_physical_channel(physical_channel);
    request.set_name_to_assign_to_channel(channel_name);
    request.set_min_val(min_val);
    request.set_max_val(max_val);
    request.set_units(VoltageUnits2::VOLTAGE_UNITS2_VOLTS);
    return create_ao_voltage_chan(request, response);
  }

  ::grpc::Status create_di_chan(
    CreateDIChanResponse& response = ThrowawayResponse<CreateDIChanResponse>::response(),
    const std::string& lines = "gRPCSystemTestDAQ/port0/line0",
    const std::string& name = "di",
    LineGrouping line_grouping = LineGrouping::LINE_GROUPING_CHAN_PER_LINE)
  {
    ::grpc::ClientContext context;
    CreateDIChanRequest request;
    set_request_session_name(request);
    request.set_lines(lines);
    request.set_name_to_assign_to_lines(name);
    request.set_line_grouping(line_grouping);
    auto status = stub()->CreateDIChan(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  CreateDOChanResponse create_do_chan(CreateDOChanResponse& response = ThrowawayResponse<CreateDOChanResponse>::response())
  {
    return client::create_do_chan(stub(), task(), "gRPCSystemTestDAQ/port1/line0", "do", LineGrouping::LINE_GROUPING_CHAN_PER_LINE);
  }

  ::grpc::Status create_do_chan(
      CreateDOChanResponse& response,
      const std::string& lines,
      const std::string& name_to_assign_to_channel,
      LineGrouping line_grouping)
  {
    response = client::create_do_chan(stub(), task(), lines, name_to_assign_to_channel, line_grouping);
    return ::grpc::Status::OK;
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
    auto status = stub()->CreateCIFreqChan(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status get_error_string(int32 error_code, GetErrorStringResponse& response)
  {
    ::grpc::ClientContext context;
    GetErrorStringRequest request;
    request.set_error_code(error_code);
    auto status = stub()->GetErrorString(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status start_task(const ::nidevice_grpc::Session& session, StartTaskResponse& response)
  {
    ::grpc::ClientContext context;
    StartTaskRequest request;
    set_request_session_name(request, session);
    auto status = stub()->StartTask(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
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
    auto status = stub()->StopTask(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status read_analog_f64(
      int32 samps_per_chan,
      uint32 array_size_in_samps,
      double timeout = 10.0,
      ReadAnalogF64Response& response = ThrowawayResponse<ReadAnalogF64Response>::response())
  {
    ::grpc::ClientContext context;
    ReadAnalogF64Request request;
    set_request_session_name(request);
    request.set_num_samps_per_chan(samps_per_chan);
    request.set_array_size_in_samps(array_size_in_samps);
    request.set_fill_mode(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    request.set_timeout(timeout);
    auto status = stub()->ReadAnalogF64(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  auto async_read_analog_f64(
    ::grpc::ClientContext& context,
    ::grpc::CompletionQueue& completion_queue,
    void* tag,
    int32 samps_per_chan,
    uint32 array_size_in_samps,
    ReadAnalogF64Response& response,
    ::grpc::Status& status)
  {
    ReadAnalogF64Request request;
    set_request_session_name(request);
    request.set_num_samps_per_chan(samps_per_chan);
    request.set_array_size_in_samps(array_size_in_samps);
    request.set_fill_mode(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    request.set_timeout(10.0);
    auto reader = stub()->AsyncReadAnalogF64(&context, request, &completion_queue);
    reader->Finish(&response, &status, tag);
    return reader;
  }

  ::grpc::Status read_analog_waveforms(
      int32 num_samps_per_chan,
      double timeout = 10.0,
      WaveformAttributeMode waveform_attribute_mode = WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_NONE,
      ReadAnalogWaveformsResponse& response = ThrowawayResponse<ReadAnalogWaveformsResponse>::response())
  {
    ::grpc::ClientContext context;
    ReadAnalogWaveformsRequest request;
    set_request_session_name(request);
    request.set_num_samps_per_chan(num_samps_per_chan);
    request.set_timeout(timeout);
    request.set_waveform_attribute_mode(waveform_attribute_mode);
    auto status = stub()->ReadAnalogWaveforms(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status read_digital_waveforms(
      int32 number_of_samples_per_channel,
      double timeout = 10.0,
      WaveformAttributeMode waveform_attribute_mode = WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_NONE,
      ReadDigitalWaveformsResponse& response = ThrowawayResponse<ReadDigitalWaveformsResponse>::response())
  {
    ::grpc::ClientContext context;
    ReadDigitalWaveformsRequest request;
    set_request_session_name(request);
    request.set_num_samps_per_chan(number_of_samples_per_channel);
    request.set_timeout(timeout);
    request.set_waveform_attribute_mode(waveform_attribute_mode);
    auto status = stub()->ReadDigitalWaveforms(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status write_analog_waveforms(
      const std::vector<std::vector<double>>& waveform_data,
      bool auto_start = false,
      double timeout = 10.0,
      WriteAnalogWaveformsResponse& response = ThrowawayResponse<WriteAnalogWaveformsResponse>::response())
  {
    ::grpc::ClientContext context;
    WriteAnalogWaveformsRequest request;
    set_request_session_name(request);
    
    if (waveform_data.empty()) {
      return ::grpc::Status(::grpc::INVALID_ARGUMENT, "No waveform data provided");
    }
    
    request.set_auto_start(auto_start);
    request.set_timeout(timeout);
    
    for (const auto& channel_data : waveform_data) {
      auto* waveform = request.add_waveforms();
      auto* y_data = waveform->mutable_y_data();
      y_data->Add(channel_data.begin(), channel_data.end());
    }
    
    auto status = stub()->WriteAnalogWaveforms(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status write_digital_waveforms(
      int32 number_of_samples_per_channel,
      const std::vector<ni::protobuf::types::DigitalWaveform>& waveforms,
      bool auto_start = false,
      double timeout = 10.0,
      WriteDigitalWaveformsResponse& response = ThrowawayResponse<WriteDigitalWaveformsResponse>::response())
  {
    ::grpc::ClientContext context;
    WriteDigitalWaveformsRequest request;
    set_request_session_name(request);
    request.set_auto_start(auto_start);
    request.set_timeout(timeout);
    for (const auto& waveform : waveforms) {
      *request.add_waveforms() = waveform;
    }
    auto status = stub()->WriteDigitalWaveforms(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
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
    client::raise_if_error(status, context);
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
    auto status = stub()->WriteDigitalU32(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status read_u32_digital_data(ReadDigitalU32Response& response)
  {
    ::grpc::ClientContext context;
    ReadDigitalU32Request request;
    set_request_session_name(request);
    request.set_num_samps_per_chan(4);
    request.set_array_size_in_samps(4);
    request.set_fill_mode(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    auto status = stub()->ReadDigitalU32(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
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
    auto status = stub()->WriteDigitalU16(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status read_u16_digital_data(ReadDigitalU16Response& response)
  {
    ::grpc::ClientContext context;
    ReadDigitalU16Request request;
    set_request_session_name(request);
    request.set_num_samps_per_chan(4);
    request.set_array_size_in_samps(4);
    request.set_fill_mode(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    auto status = stub()->ReadDigitalU16(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
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
    auto status = stub()->WriteDigitalU8(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status read_u8_digital_data(ReadDigitalU8Response& response)
  {
    ::grpc::ClientContext context;
    ReadDigitalU8Request request;
    set_request_session_name(request);
    request.set_num_samps_per_chan(4);
    request.set_array_size_in_samps(4);
    request.set_fill_mode(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    auto status = stub()->ReadDigitalU8(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status write_binary_i16(const std::vector<int16>& data, WriteBinaryI16Response& response)
  {
    ::grpc::ClientContext context;
    WriteBinaryI16Request request;
    set_request_session_name(request);
    request.set_num_samps_per_chan(static_cast<uint32>(data.size()));
    request.mutable_write_array()->CopyFrom({data.cbegin(), data.cend()});
    request.set_data_layout(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    auto status = stub()->WriteBinaryI16(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status get_nth_task_device(uint32_t index, GetNthTaskDeviceResponse& response)
  {
    ::grpc::ClientContext context;
    GetNthTaskDeviceRequest request;
    set_request_session_name(request);
    request.set_index(index);

    auto status = stub()->GetNthTaskDevice(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  bool is_task_done()
  {
    ::grpc::ClientContext context;
    IsTaskDoneRequest request;
    set_request_session_name(request);
    IsTaskDoneResponse response;
    auto status = stub()->IsTaskDone(&context, request, &response);
    client::raise_if_error(status, context);
    return response.is_task_done();
  }

  ::grpc::Status task_control(TaskControlAction action, TaskControlResponse& response)
  {
    ::grpc::ClientContext context;
    TaskControlRequest request;
    set_request_session_name(request);
    request.set_action(action);
    auto status = stub()->TaskControl(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  auto register_done_event(::grpc::ClientContext& context)
  {
    RegisterDoneEventRequest request;
    set_request_session_name(request);
    return stub()->RegisterDoneEvent(&context, request);
  }

  auto async_register_done_event(::grpc::ClientContext& context, ::grpc::CompletionQueue& completion_queue, void* tag)
  {
    RegisterDoneEventRequest request;
    set_request_session_name(request);
    return stub()->AsyncRegisterDoneEvent(&context, request, &completion_queue, tag);
  }

  auto register_every_n_samples_event(
    ::grpc::ClientContext& context,
    uint32 n_samples,
    EveryNSamplesEventType every_n_samples_event_type = EveryNSamplesEventType::EVERY_N_SAMPLES_EVENT_TYPE_ACQUIRED_INTO_BUFFER)
  {
    RegisterEveryNSamplesEventRequest request;
    set_request_session_name(request);
    request.set_n_samples(n_samples);
    request.set_every_n_samples_event_type(every_n_samples_event_type);
    return stub()->RegisterEveryNSamplesEvent(&context, request);
  }

  auto async_register_every_n_samples_event(
    ::grpc::ClientContext& context,
    ::grpc::CompletionQueue& completion_queue,
    void* tag,
    uint32 n_samples,
    EveryNSamplesEventType every_n_samples_event_type = EveryNSamplesEventType::EVERY_N_SAMPLES_EVENT_TYPE_ACQUIRED_INTO_BUFFER)
  {
    RegisterEveryNSamplesEventRequest request;
    set_request_session_name(request);
    request.set_n_samples(n_samples);
    request.set_every_n_samples_event_type(every_n_samples_event_type);
    return stub()->AsyncRegisterEveryNSamplesEvent(&context, request, &completion_queue, tag);
  }

  auto register_signal_event(::grpc::ClientContext& context, Signal2 signal_id)
  {
    RegisterSignalEventRequest request;
    set_request_session_name(request);
    request.set_signal_id(signal_id);
    return stub()->RegisterSignalEvent(&context, request);
  }

  auto async_register_signal_event(
    ::grpc::ClientContext& context,
    ::grpc::CompletionQueue& completion_queue,
    void* tag,
    Signal2 signal_id)
  {
    RegisterSignalEventRequest request;
    set_request_session_name(request);
    request.set_signal_id(signal_id);
    return stub()->AsyncRegisterSignalEvent(&context, request, &completion_queue, tag);
  }

  template <typename TResponse>
  void read_stream(
    ::grpc::ClientContext& context,
    ::grpc::ClientReader<TResponse>& reader,
    TResponse& response)
  {
    if (!reader.Read(&response)) {
      auto status = reader.Finish();
      client::raise_if_error(status, context);
      throw std::runtime_error("Stream unexpectedly closed");
    }
  }

  template <typename TResponse>
  void read_stream(
    ::grpc::ClientContext& context,
    ::grpc::ClientReader<TResponse>& reader,
    size_t count,
    std::vector<TResponse>& responses)
  {
    TResponse response;
    for (size_t i = 0; i < count; ++i) {
      read_stream(context, reader, response);
      responses.push_back(response);
    }
  }

  template <typename TResponse>
  void async_wait_for_initial_metadata(
    ::grpc::ClientContext& context,
    ::grpc::ClientAsyncReader<TResponse>& reader,
    ::grpc::CompletionQueue& completion_queue,
    void* start_call_tag,
    void* read_initial_metadata_tag)
  {
    // Assume start_call_tag was initiated by async_register_x_event().
    reader.ReadInitialMetadata(read_initial_metadata_tag);
    ASSERT_EQ(Completion(start_call_tag, true), get_next_completion(completion_queue));
    ASSERT_EQ(Completion(read_initial_metadata_tag, true), get_next_completion(completion_queue));
  }

  // Wait for the stream to finish and throw an exception if it has an error. If the stream is not
  // closed/canceled, this function waits forever.
  template <typename TResponse>
  void async_finish_stream(
    ::grpc::ClientContext& context,
    ::grpc::ClientAsyncReader<TResponse>& reader,
    ::grpc::CompletionQueue& completion_queue,
    void* finish_tag)
  {
    ::grpc::Status status;
    reader.Finish(&status, finish_tag);

    while (true) {
      auto completion = get_next_completion(completion_queue);
      if (get_completion_tag(completion) == finish_tag) {
        ASSERT_TRUE(is_completion_ok(completion));
        client::raise_if_error(status, context);
        break;
      }
      // Discard other completions.
    }
  }

  // Cancel the stream and wait for it to finish with ::grpc::CANCELLED.
  template <typename TResponse>
  void async_cancel_stream(
    ::grpc::ClientContext& context,
    ::grpc::ClientAsyncReader<TResponse>& reader,
    ::grpc::CompletionQueue& completion_queue,
    void* finish_tag)
  {
    context.TryCancel();
    EXPECT_THROW_GRPC_CANCELLED(async_finish_stream(context, reader, completion_queue, finish_tag));
  }

  // Begin an async read. If the read immediately completes with an error, finish the stream and
  // throw an exception. This function assumes there are no other pending tags.
  template <typename TResponse>
  void async_begin_read_stream(
    ::grpc::ClientContext& context,
    ::grpc::ClientAsyncReader<TResponse>& reader,
    ::grpc::CompletionQueue& completion_queue,
    void* read_tag,
    void* finish_tag,
    TResponse& response)
  {
    reader.Read(&response, read_tag);

    Completion completion;
    bool completed = try_get_next_completion_without_blocking(completion_queue, completion);

    if (completed) {
      ASSERT_EQ(read_tag, get_completion_tag(completion)) << "There should be no other pending tags";
      if (!is_completion_ok(completion)) {
        async_finish_stream(context, reader, completion_queue, finish_tag);
        throw std::runtime_error("Stream unexpectedly closed");
      }
    }
  }

  ::grpc::Status unregister_done_event(UnregisterDoneEventResponse& response = ThrowawayResponse<UnregisterDoneEventResponse>::response())
  {
    ::grpc::ClientContext context;
    UnregisterDoneEventRequest request;
    set_request_session_name(request);
    auto status = stub()->UnregisterDoneEvent(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status unregister_every_n_samples_event(
    EveryNSamplesEventType every_n_samples_event_type = EveryNSamplesEventType::EVERY_N_SAMPLES_EVENT_TYPE_ACQUIRED_INTO_BUFFER,
    UnregisterEveryNSamplesEventResponse& response = ThrowawayResponse<UnregisterEveryNSamplesEventResponse>::response())
  {
    ::grpc::ClientContext context;
    UnregisterEveryNSamplesEventRequest request;
    set_request_session_name(request);
    request.set_every_n_samples_event_type(every_n_samples_event_type);
    auto status = stub()->UnregisterEveryNSamplesEvent(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status unregister_signal_event(
    Signal2 signal_id,
    UnregisterSignalEventResponse& response = ThrowawayResponse<UnregisterSignalEventResponse>::response())
  {
    ::grpc::ClientContext context;
    UnregisterSignalEventRequest request;
    set_request_session_name(request);
    request.set_signal_id(signal_id);
    auto status = stub()->UnregisterSignalEvent(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
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
    auto status = stub()->CfgSampClkTiming(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
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
    auto status = stub()->CfgChangeDetectionTiming(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status cfg_input_buffer(CfgInputBufferResponse& response)
  {
    ::grpc::ClientContext context;
    CfgInputBufferRequest request;
    set_request_session_name(request);
    request.set_num_samps_per_chan(1024U);
    auto status = stub()->CfgInputBuffer(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status cfg_output_buffer(CfgOutputBufferResponse& response)
  {
    ::grpc::ClientContext context;
    CfgOutputBufferRequest request;
    set_request_session_name(request);
    request.set_num_samps_per_chan(1024U);
    auto status = stub()->CfgOutputBuffer(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status self_test_device(SelfTestDeviceResponse& response)
  {
    ::grpc::ClientContext context;
    SelfTestDeviceRequest request;
    request.set_device_name(DEVICE_NAME);
    auto status = stub()->SelfTestDevice(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status create_lin_scale(const std::string& name, double slope, CreateLinScaleResponse& response = ThrowawayResponse<CreateLinScaleResponse>::response())
  {
    ::grpc::ClientContext context;
    CreateLinScaleRequest request;
    request.set_name(name);
    request.set_slope(slope);
    request.set_pre_scaled_units(UnitsPreScaled::UNITS_PRE_SCALED_VOLTS);
    auto status = stub()->CreateLinScale(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status create_polynomial_scale(const std::string& name, const std::vector<double>& forward_coeffs, const std::vector<double>& reverse_coeffs, CreatePolynomialScaleResponse& response = ThrowawayResponse<CreatePolynomialScaleResponse>::response())
  {
    ::grpc::ClientContext context;
    CreatePolynomialScaleRequest request;
    request.set_name(name);

    request.mutable_forward_coeffs()->CopyFrom({forward_coeffs.cbegin(), forward_coeffs.cend()});

    request.mutable_reverse_coeffs()->CopyFrom({reverse_coeffs.cbegin(), reverse_coeffs.cend()});

    request.set_pre_scaled_units(UnitsPreScaled::UNITS_PRE_SCALED_VOLTS);
    auto status = stub()->CreatePolynomialScale(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
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
    auto status = stub()->CalculateReversePolyCoeff(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  template <typename TRaw>
  ::grpc::Status read_raw(int32 samples_to_read, ReadRawResponse& response)
  {
    ::grpc::ClientContext context;
    ReadRawRequest request;
    set_request_session_name(request);
    request.set_num_samps_per_chan(samples_to_read);
    request.set_array_size_in_bytes(samples_to_read * sizeof(TRaw));
    request.set_timeout(10.0);
    auto status = stub()->ReadRaw(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
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
    request.set_timeout(10.0);
    auto status = stub()->WriteRaw(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status wait_for_valid_timestamp(WaitForValidTimestampResponse& response)
  {
    ::grpc::ClientContext context;
    WaitForValidTimestampRequest request;
    set_request_session_name(request);
    request.set_timestamp_event(TimestampEvent::TIMESTAMP_EVENT_FIRST_SAMPLE_TIMESTAMP);
    request.set_timeout(1.000);
    auto status = stub()->WaitForValidTimestamp(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status cfg_time_start_trig(CfgTimeStartTrigResponse& response)
  {
    ::grpc::ClientContext context;
    CfgTimeStartTrigRequest request;
    set_request_session_name(request);

    // Ensure GetCurrentTime macro in WinBase.h does not interfere with the GetCurrentTime function from protobuf.
#ifdef _WIN32
     #pragma push_macro("GetCurrentTime")
     #undef GetCurrentTime
#endif
    auto time = google::protobuf::util::TimeUtil::GetCurrentTime();
#ifdef _WIN32
     #pragma pop_macro("GetCurrentTime")
#endif


    auto duration = google::protobuf::Duration{};
    duration.set_seconds(10);
    time += duration;
    request.mutable_when()->CopyFrom(time);
    request.set_timescale(Timescale2::TIMESCALE2_IO_DEVICE_TIME);
    auto status = stub()->CfgTimeStartTrig(&context, request, &response);
    client::raise_if_error(status, context);
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
    auto status = stub()->SaveTask(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
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
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status perform_bridge_offset_nulling_cal_ex(std::string channel, bool skipUnsupportedChannels, PerformBridgeOffsetNullingCalExResponse& response)
  {
    ::grpc::ClientContext context;
    PerformBridgeOffsetNullingCalExRequest request;
    set_request_session_name(request);
    request.set_channel(channel);
    request.set_skip_unsupported_channels(skipUnsupportedChannels);
    auto status = stub()->PerformBridgeOffsetNullingCalEx(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status perform_bridge_shunt_cal_ex(PerformBridgeShuntCalExResponse & response)
  {
    ::grpc::ClientContext context;
    PerformBridgeShuntCalExRequest request;
    set_request_session_name(request);
    request.set_channel("");
    request.set_shunt_resistor_value(100000);
    request.set_shunt_resistor_location(ShuntElementLocation::SHUNT_ELEMENT_LOCATION_R3);
    request.set_shunt_resistor_select(ShuntCalSelect::SHUNT_CAL_SELECT_A);
    request.set_shunt_resistor_source(ShuntCalSource::SHUNT_CAL_SOURCE_DEFAULT);
    request.set_bridge_resistance(120);
    request.set_skip_unsupported_channels(false);
    auto status = stub()->PerformBridgeShuntCalEx(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status perform_strain_shunt_cal_ex(PerformStrainShuntCalExResponse& response)
  {
    ::grpc::ClientContext context;
    PerformStrainShuntCalExRequest request;
    set_request_session_name(request);
    request.set_channel("");
    request.set_shunt_resistor_value(100000);
    request.set_shunt_resistor_location(ShuntElementLocation::SHUNT_ELEMENT_LOCATION_R3);
    request.set_shunt_resistor_select(ShuntCalSelect::SHUNT_CAL_SELECT_A);
    request.set_shunt_resistor_source(ShuntCalSource::SHUNT_CAL_SOURCE_DEFAULT);
    request.set_skip_unsupported_channels(false);
    auto status = stub()->PerformStrainShuntCalEx(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status perform_thrmcpl_lead_offset_nulling_cal(std::string channel, bool skipUnsupportedChannels, PerformThrmcplLeadOffsetNullingCalResponse& response)
  {
    ::grpc::ClientContext context;
    PerformThrmcplLeadOffsetNullingCalRequest request;
    set_request_session_name(request);
    request.set_channel(channel);
    request.set_skip_unsupported_channels(skipUnsupportedChannels);
    auto status = stub()->PerformThrmcplLeadOffsetNullingCal(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status self_cal(SelfCalResponse& response)
  {
    ::grpc::ClientContext context;
    SelfCalRequest request;
    request.set_device_name(DEVICE_NAME);
    auto status = stub()->SelfCal(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status add_network_device(const std::string& ip_address, AddNetworkDeviceResponse& response)
  {
    ::grpc::ClientContext context;
    AddNetworkDeviceRequest request;
    request.set_ip_address(ip_address);
    auto status = stub()->AddNetworkDevice(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status wait_for_next_sample_clock(WaitForNextSampleClockResponse& response)
  {
    ::grpc::ClientContext context;
    WaitForNextSampleClockRequest request;
    set_request_session_name(request);
    request.set_timeout(10.0);
    auto status = stub()->WaitForNextSampleClock(&context, request, &response);
    client::raise_if_error(status, context);
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
    client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status create_watchdog_timer_task_ex(double timeout, CreateWatchdogTimerTaskExResponse& response)
  {
    ::grpc::ClientContext context;
    CreateWatchdogTimerTaskExRequest request;

    request.set_device_name(DEVICE_NAME);
    request.set_timeout(timeout);
    auto status = stub()->CreateWatchdogTimerTaskEx(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
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
    auto status = stub()->CfgWatchdogDOExpirStates(&context, request, &response);
    client::raise_if_error(status, context);
    return status;
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

  // Get number of seconds since 1904 epoch (CVI/BTF epoch) for comparison with waveform timestamps
  int64_t get_seconds_since_1904() const
  {    
    auto now = std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now().time_since_epoch()).count();    
    return now + SecondsFromCVI1904EpochTo1970Epoch;
  }

  std::vector<uint8_t> get_expected_data_for_line(int32 num_samples, int32 line_number) const
  {
    std::vector<uint8_t> data;
    // Simulated digital signals "count" from 0 in binary within each group of 8 lines.
    // Each line represents a bit in the binary representation of the sample number.
    // - line 0 represents bit 0 (LSB) - alternates every sample: 0,1,0,1,0,1,0,1...
    // - line 1 represents bit 1 - alternates every 2 samples:    0,0,1,1,0,0,1,1...
    // - line 2 represents bit 2 - alternates every 4 samples:    0,0,0,0,1,1,1,1...
    line_number %= 8;
    for (int32 sample_num = 0; sample_num < num_samples; ++sample_num) {
      uint8_t bit_value = (sample_num >> line_number) & 1;
      data.push_back(bit_value);
    }
    return data;
  }

  void verify_digital_waveform_data(
      const std::string& y_data,
      int32 num_samples,
      int32 signals_per_sample,
      int32 line_offset) const
  {
    for (int32 sample = 0; sample < num_samples; ++sample) {
      for (int32 line = 0; line < signals_per_sample; ++line) {
        int32 line_number = line + line_offset;
        auto expected_data = get_expected_data_for_line(num_samples, line_number);
        uint8_t actual_value = static_cast<uint8_t>(y_data[sample * signals_per_sample + line]);
        uint8_t expected_value = expected_data[sample];
        EXPECT_EQ(actual_value, expected_value) 
          << "Mismatch at sample " << sample << ", line " << line_number
          << ": expected " << static_cast<int>(expected_value) 
          << ", got " << static_cast<int>(actual_value);
      }
    }
  }

  ni::protobuf::types::DigitalWaveform create_test_digital_waveform(
      int32 num_samples,
      int32 signal_count,
      int32 line_offset = 0) const
  {
    ni::protobuf::types::DigitalWaveform waveform;
    waveform.set_signal_count(signal_count);
    
    auto* y_data = waveform.mutable_y_data();
    y_data->reserve(num_samples * signal_count);
    
    for (int32 sample = 0; sample < num_samples; ++sample) {
      for (int32 line = 0; line < signal_count; ++line) {
        int32 line_number = line + line_offset;
        auto expected_data = get_expected_data_for_line(num_samples, line_number);
        y_data->push_back(expected_data[sample]);
      }
    }
    
    return waveform;
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

TEST_F(NiDAQmxDriverApiTests, WriteDigitalWaveforms_Succeeds)
{
  const auto NUM_SAMPLES = 50;
  const auto TIMEOUT = 10.0;
  CreateDOChanResponse create_channel_response;
  auto create_channel_status = create_do_chan(create_channel_response, "gRPCSystemTestDAQ/port1/line0:2", "do_port1", LineGrouping::LINE_GROUPING_CHAN_FOR_ALL_LINES);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);
  create_channel_status = create_do_chan(create_channel_response, "gRPCSystemTestDAQ/port1/line4:5", "do_port1_lines45", LineGrouping::LINE_GROUPING_CHAN_FOR_ALL_LINES);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);

  std::vector<ni::protobuf::types::DigitalWaveform> waveforms;
  waveforms.push_back(create_test_digital_waveform(NUM_SAMPLES, 3, 0)); // 3 lines starting at line 0
  waveforms.push_back(create_test_digital_waveform(NUM_SAMPLES, 2, 4)); // 2 lines starting at line 4

  start_task();
  WriteDigitalWaveformsResponse write_response;
  auto write_status = write_digital_waveforms(NUM_SAMPLES, waveforms, false, TIMEOUT, write_response);
  stop_task();

  EXPECT_SUCCESS(write_status, write_response);
  EXPECT_EQ(write_response.status(), DAQMX_SUCCESS);
  EXPECT_EQ(write_response.samps_per_chan_written(), NUM_SAMPLES);
}

TEST_F(NiDAQmxDriverApiTests, WriteDigitalWaveforms_WithAutoStart_Succeeds)
{
  const auto NUM_SAMPLES = 25;
  const auto TIMEOUT = 10.0;
  CreateDOChanResponse create_channel_response;
  auto create_channel_status = create_do_chan(create_channel_response, "gRPCSystemTestDAQ/port1/line0", "do_line0", LineGrouping::LINE_GROUPING_CHAN_PER_LINE);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);

  std::vector<ni::protobuf::types::DigitalWaveform> waveforms;
  waveforms.push_back(create_test_digital_waveform(NUM_SAMPLES, 1, 0)); // 1 line starting at line 0

  WriteDigitalWaveformsResponse write_response;
  auto write_status = write_digital_waveforms(NUM_SAMPLES, waveforms, true, TIMEOUT, write_response);

  EXPECT_SUCCESS(write_status, write_response);
  EXPECT_EQ(write_response.status(), DAQMX_SUCCESS);
  EXPECT_EQ(write_response.samps_per_chan_written(), NUM_SAMPLES);
}

TEST_F(NiDAQmxDriverApiTests, WriteDigitalWaveforms_EmptyWaveforms_Fails)
{
  const auto NUM_SAMPLES = 10;
  CreateDOChanResponse create_channel_response;
  auto create_channel_status = create_do_chan(create_channel_response, "gRPCSystemTestDAQ/port1/line0", "do_line0", LineGrouping::LINE_GROUPING_CHAN_PER_LINE);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);

  std::vector<ni::protobuf::types::DigitalWaveform> waveforms; // Empty waveforms

  // Use direct stub call without raise_if_error to check for gRPC errors
  ::grpc::ClientContext context;
  WriteDigitalWaveformsRequest request;
  WriteDigitalWaveformsResponse response;
  set_request_session_name(request);
  request.set_auto_start(false);
  request.set_timeout(10.0);
  auto write_status = stub()->WriteDigitalWaveforms(&context, request, &response);

  EXPECT_FALSE(write_status.ok());
  EXPECT_EQ(write_status.error_code(), ::grpc::StatusCode::INVALID_ARGUMENT);
  EXPECT_THAT(write_status.error_message(), HasSubstr("No waveforms provided"));
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
  const auto TIMEOUT = 10.0;
  create_ai_voltage_chan(AI_MIN, AI_MAX);

  StartTaskResponse start_response;
  auto start_status = start_task(start_response);
  ReadAnalogF64Response read_response;
  auto read_status = read_analog_f64(NUM_SAMPS, NUM_SAMPS, TIMEOUT, read_response);
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
  const auto TIMEOUT = 10.0;
  CreateAIThrmcplChanResponse create_response;
  auto create_status = create_ai_thrmcpl_chan(MIN_TEMPERATURE, MAX_TEMPERATURE, create_response);
  EXPECT_SUCCESS(create_status, create_response);

  start_task();
  ReadAnalogF64Response read_response;
  auto read_status = read_analog_f64(NUM_SAMPS, NUM_SAMPS, TIMEOUT, read_response);
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
  const auto TIMEOUT = 10.0;
  CreateLinScaleResponse scale_response;
  auto scale_status = create_lin_scale(SCALE_NAME, 0.5, scale_response);
  EXPECT_SUCCESS(scale_status, scale_response);
  auto request = create_ai_voltage_request(AI_MIN, AI_MAX, SCALE_NAME);
  CreateAIVoltageChanResponse create_channel_response;
  auto create_channel_status = create_ai_voltage_chan(request, create_channel_response);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);

  start_task();
  ReadAnalogF64Response read_response;
  auto read_status = read_analog_f64(NUM_SAMPS, NUM_SAMPS, TIMEOUT, read_response);
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

  EXPECT_THROW_DRIVER_ERROR({
    client::get_scale_attribute_double(
      stub(),
      SCALE_NAME,
      (ScaleDoubleAttribute)ScaleStringAttribute::SCALE_ATTRIBUTE_SCALED_UNITS);
  }, SPECIFIED_ATTRIBUTE_NOT_VALID_ERROR);
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

TEST_F(NiDAQmxDriverApiTests, ReadAnalogWaveforms_WithNoAttributeMode_ReturnsWaveformData)
{
  const auto NUM_SAMPLES = 1000;
  const auto TIMEOUT = 10.0;
  CreateAIVoltageChanResponse create_channel_response;
  auto create_channel_status = create_ai_voltage_chan("gRPCSystemTestDAQ/ai0", "ai0", -1.0, 1.0, create_channel_response);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);
  create_channel_status = create_ai_voltage_chan("gRPCSystemTestDAQ/ai1", "ai1", -1.0, 1.0, create_channel_response);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);

  start_task();
  ReadAnalogWaveformsResponse read_response;
  auto read_status = read_analog_waveforms(NUM_SAMPLES, TIMEOUT, WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_NONE, read_response);
  stop_task();

  EXPECT_SUCCESS(read_status, read_response);
  EXPECT_EQ(read_response.status(), DAQMX_SUCCESS);
  EXPECT_EQ(read_response.waveforms_size(), 2);
  EXPECT_EQ(read_response.samps_per_chan_read(), NUM_SAMPLES);
  
  for (int i = 0; i < read_response.waveforms_size(); ++i) {
    const auto& waveform = read_response.waveforms(i);
    EXPECT_EQ(waveform.y_data_size(), NUM_SAMPLES);    
    EXPECT_FALSE(waveform.has_t0());
    EXPECT_EQ(waveform.dt(), 0.0);    
    EXPECT_EQ(waveform.attributes_size(), 0);
    
    for (const auto& sample : waveform.y_data()) {
      EXPECT_GE(sample, -1.0);
      EXPECT_LE(sample, 1.0);
    }
  }
}

TEST_F(NiDAQmxDriverApiTests, ReadAnalogWaveforms_WithTimingMode_ReturnsWaveformDataWithTimingInfo)
{
  const auto NUM_SAMPLES = 100;
  const auto TIMEOUT = 10.0;
  CreateAIVoltageChanResponse create_channel_response;
  auto create_channel_status = create_ai_voltage_chan("gRPCSystemTestDAQ/ai0", "ai0", -5.0, 5.0, create_channel_response);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);
  create_channel_status = create_ai_voltage_chan("gRPCSystemTestDAQ/ai1", "ai1", -5.0, 5.0, create_channel_response);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);

  auto timing_request = create_cfg_samp_clk_timing_request(1000.0, Edge1::EDGE1_RISING, AcquisitionType::ACQUISITION_TYPE_FINITE_SAMPS, NUM_SAMPLES);
  CfgSampClkTimingResponse timing_response;
  auto timing_status = cfg_samp_clk_timing(timing_request, timing_response);
  EXPECT_SUCCESS(timing_status, timing_response);

  start_task();
  ReadAnalogWaveformsResponse read_response;
  auto read_status = read_analog_waveforms(NUM_SAMPLES, TIMEOUT, WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_TIMING, read_response);
  stop_task();

  EXPECT_SUCCESS(read_status, read_response);
  EXPECT_EQ(read_response.status(), DAQMX_SUCCESS);
  EXPECT_EQ(read_response.waveforms_size(), 2);
  EXPECT_EQ(read_response.samps_per_chan_read(), NUM_SAMPLES);
  
  for (int i = 0; i < read_response.waveforms_size(); ++i) {
    const auto& waveform = read_response.waveforms(i);
    EXPECT_EQ(waveform.y_data_size(), NUM_SAMPLES);
    EXPECT_TRUE(waveform.has_t0());
    EXPECT_NEAR(waveform.t0().seconds(), get_seconds_since_1904(), 1);    
    EXPECT_GT(waveform.dt(), 0.0);
    
    for (const auto& sample : waveform.y_data()) {
      EXPECT_GE(sample, -5.0);
      EXPECT_LE(sample, 5.0);
    }
  }
}

TEST_F(NiDAQmxDriverApiTests, ReadAnalogWaveforms_WithExtendedPropertiesMode_ReturnsWaveformDataWithAttributes)
{
  const auto NUM_SAMPLES = 50;
  const auto TIMEOUT = 10.0;
  CreateAIVoltageChanResponse create_channel_response;
  auto create_channel_status = create_ai_voltage_chan("gRPCSystemTestDAQ/ai0", "ai0", -2.0, 2.0, create_channel_response);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);
  create_channel_status = create_ai_voltage_chan("gRPCSystemTestDAQ/ai1", "ai1", -2.0, 2.0, create_channel_response);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);

  start_task();
  ReadAnalogWaveformsResponse read_response;
  auto read_status = read_analog_waveforms(NUM_SAMPLES, TIMEOUT, WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_EXTENDED_PROPERTIES, read_response);
  stop_task();

  EXPECT_SUCCESS(read_status, read_response);
  EXPECT_EQ(read_response.status(), DAQMX_SUCCESS);
  EXPECT_EQ(read_response.waveforms_size(), 2);
  EXPECT_EQ(read_response.samps_per_chan_read(), NUM_SAMPLES);
  
  for (int i = 0; i < read_response.waveforms_size(); ++i) {
    const auto& waveform = read_response.waveforms(i);
    EXPECT_EQ(waveform.y_data_size(), NUM_SAMPLES);
    EXPECT_GT(waveform.attributes_size(), 0);
    
    bool has_channel_name = false;
    bool has_units = false;
    std::string expected_channel_name = (i == 0) ? "ai0" : "ai1";
    
    for (const auto& attr_pair : waveform.attributes()) {
      const auto& attr_name = attr_pair.first;
      const auto& attr_value = attr_pair.second;
      
      if (attr_name == "NI_ChannelName" && attr_value.has_string_value()) {
        if (attr_value.string_value() == expected_channel_name) {
          has_channel_name = true;
        }
      }
      if (attr_name == "NI_UnitDescription" && attr_value.has_string_value()) {
        if (attr_value.string_value() == "Volts") {
          has_units = true;
        }
      }
    }
    EXPECT_TRUE(has_channel_name);
    EXPECT_TRUE(has_units);
    
    for (const auto& sample : waveform.y_data()) {
      EXPECT_GE(sample, -2.0);
      EXPECT_LE(sample, 2.0);
    }
  }
}

TEST_F(NiDAQmxDriverApiTests, ReadAnalogWaveforms_WithTimingAndExtendedPropertiesMode_ReturnsWaveformDataWithTimingAndAttributes)
{
  const auto NUM_SAMPLES = 75;
  const auto TIMEOUT = 10.0;
  CreateAIVoltageChanResponse create_channel_response;
  auto create_channel_status = create_ai_voltage_chan("gRPCSystemTestDAQ/ai0", "ai0", -3.0, 3.0, create_channel_response);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);
  create_channel_status = create_ai_voltage_chan("gRPCSystemTestDAQ/ai1", "ai1", -3.0, 3.0, create_channel_response);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);

  auto timing_request = create_cfg_samp_clk_timing_request(2000.0, Edge1::EDGE1_RISING, AcquisitionType::ACQUISITION_TYPE_FINITE_SAMPS, NUM_SAMPLES);
  CfgSampClkTimingResponse timing_response;
  auto timing_status = cfg_samp_clk_timing(timing_request, timing_response);
  EXPECT_SUCCESS(timing_status, timing_response);

  start_task();
  ReadAnalogWaveformsResponse read_response;
  const auto combined_mode = static_cast<WaveformAttributeMode>(
    static_cast<int32>(WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_TIMING) | 
    static_cast<int32>(WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_EXTENDED_PROPERTIES)
  );
  auto read_status = read_analog_waveforms(NUM_SAMPLES, TIMEOUT, combined_mode, read_response);
  stop_task();

  EXPECT_SUCCESS(read_status, read_response);
  EXPECT_EQ(read_response.status(), DAQMX_SUCCESS);
  EXPECT_EQ(read_response.waveforms_size(), 2);
  EXPECT_EQ(read_response.samps_per_chan_read(), NUM_SAMPLES);
  
  for (int i = 0; i < read_response.waveforms_size(); ++i) {
    const auto& waveform = read_response.waveforms(i);
    EXPECT_EQ(waveform.y_data_size(), NUM_SAMPLES);
    EXPECT_TRUE(waveform.has_t0());
    EXPECT_NEAR(waveform.t0().seconds(), get_seconds_since_1904(), 1);
    EXPECT_GT(waveform.dt(), 0.0);
    EXPECT_GT(waveform.attributes_size(), 0);
    
    bool has_channel_name = false;
    bool has_units = false;
    std::string expected_channel_name = (i == 0) ? "ai0" : "ai1";
    
    for (const auto& attr_pair : waveform.attributes()) {
      const auto& attr_name = attr_pair.first;
      const auto& attr_value = attr_pair.second;
      
      if (attr_name == "NI_ChannelName" && attr_value.has_string_value()) {
        if (attr_value.string_value() == expected_channel_name) {
          has_channel_name = true;
        }
      }
      if (attr_name == "NI_UnitDescription" && attr_value.has_string_value()) {
        if (attr_value.string_value() == "Volts") {
          has_units = true;
        }
      }
    }
    EXPECT_TRUE(has_channel_name);
    EXPECT_TRUE(has_units);
    
    for (const auto& sample : waveform.y_data()) {
      EXPECT_GE(sample, -3.0);
      EXPECT_LE(sample, 3.0);
    }
  }
}

TEST_F(NiDAQmxDriverApiTests, ReadDigitalWaveforms_WithNoAttributeMode_ReturnsWaveformData)
{
  const auto NUM_SAMPLES = 100;
  const auto TIMEOUT = 10.0;
  CreateDIChanResponse create_channel_response;
  auto create_channel_status = create_di_chan(create_channel_response, "gRPCSystemTestDAQ/port0/line0:2", "di_port0", LineGrouping::LINE_GROUPING_CHAN_FOR_ALL_LINES);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);
  create_channel_status = create_di_chan(create_channel_response, "gRPCSystemTestDAQ/port0/line4:5", "di_port0_lines45", LineGrouping::LINE_GROUPING_CHAN_FOR_ALL_LINES);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);

  start_task();
  ReadDigitalWaveformsResponse read_response;
  auto read_status = read_digital_waveforms(NUM_SAMPLES, TIMEOUT, WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_NONE, read_response);
  stop_task();

  EXPECT_SUCCESS(read_status, read_response);
  EXPECT_EQ(read_response.status(), DAQMX_SUCCESS);
  EXPECT_EQ(read_response.waveforms_size(), 2); // Two channels: di_port0 and di_port0_lines45
  EXPECT_EQ(read_response.samps_per_chan_read(), NUM_SAMPLES);
  
  const auto& waveform0 = read_response.waveforms(0);
  EXPECT_EQ(waveform0.signal_count(), 3); // 3 lines in port0 (line0:2 means 0,1,2)
  EXPECT_EQ(static_cast<int32>(waveform0.y_data().size()), NUM_SAMPLES * 3); // 3 bytes per sample
  verify_digital_waveform_data(waveform0.y_data(), NUM_SAMPLES, 3, 0);
  
  const auto& waveform1 = read_response.waveforms(1);
  EXPECT_EQ(waveform1.signal_count(), 2); // 2 lines in port0 (line4:5 means 4,5)
  EXPECT_EQ(static_cast<int32>(waveform1.y_data().size()), NUM_SAMPLES * 2); // 2 bytes per sample
  verify_digital_waveform_data(waveform1.y_data(), NUM_SAMPLES, 2, 4);
}

TEST_F(NiDAQmxDriverApiTests, ReadDigitalWaveforms_WithTimingMode_ReturnsWaveformDataWithTimingInfo)
{
  const auto NUM_SAMPLES = 50;
  const auto TIMEOUT = 10.0;
  CreateDIChanResponse create_channel_response;
  auto create_channel_status = create_di_chan(create_channel_response, "gRPCSystemTestDAQ/port0/line0:2", "di_port0", LineGrouping::LINE_GROUPING_CHAN_FOR_ALL_LINES);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);
  create_channel_status = create_di_chan(create_channel_response, "gRPCSystemTestDAQ/port0/line4:5", "di_port0_lines45", LineGrouping::LINE_GROUPING_CHAN_FOR_ALL_LINES);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);

  auto timing_request = create_cfg_samp_clk_timing_request(1000.0, Edge1::EDGE1_RISING, AcquisitionType::ACQUISITION_TYPE_FINITE_SAMPS, NUM_SAMPLES);
  CfgSampClkTimingResponse timing_response;
  auto timing_status = cfg_samp_clk_timing(timing_request, timing_response);
  EXPECT_SUCCESS(timing_status, timing_response);

  start_task();
  ReadDigitalWaveformsResponse read_response;
  auto read_status = read_digital_waveforms(NUM_SAMPLES, TIMEOUT, WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_TIMING, read_response);
  stop_task();

  EXPECT_SUCCESS(read_status, read_response);
  EXPECT_EQ(read_response.status(), DAQMX_SUCCESS);
  EXPECT_EQ(read_response.waveforms_size(), 2); // Two channels: di_port0 and di_port0_lines45
  EXPECT_EQ(read_response.samps_per_chan_read(), NUM_SAMPLES);
    
  for (int i = 0; i < read_response.waveforms_size(); ++i) {
    const auto& waveform = read_response.waveforms(i);
    
    int expected_signal_count = (i == 0) ? 3 : 2; // port0 lines 0:2 has 3 lines, lines 4:5 has 2 lines
    EXPECT_EQ(waveform.signal_count(), expected_signal_count);
    EXPECT_EQ(static_cast<int32>(waveform.y_data().size()), NUM_SAMPLES * expected_signal_count);
    
    EXPECT_TRUE(waveform.has_t0());
    const auto& timestamp = waveform.t0();
    EXPECT_NEAR(timestamp.seconds(), get_seconds_since_1904(), 1);
    EXPECT_GT(waveform.dt(), 0.0);
  }
}

TEST_F(NiDAQmxDriverApiTests, ReadDigitalWaveforms_WithExtendedPropertiesMode_ReturnsWaveformDataWithAttributes)
{
  const auto NUM_SAMPLES = 50;
  const auto TIMEOUT = 10.0;
  CreateDIChanResponse create_channel_response;
  auto create_channel_status = create_di_chan(create_channel_response, "gRPCSystemTestDAQ/port0/line0:2", "di_port0", LineGrouping::LINE_GROUPING_CHAN_FOR_ALL_LINES);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);
  create_channel_status = create_di_chan(create_channel_response, "gRPCSystemTestDAQ/port0/line4:5", "di_port0_lines45", LineGrouping::LINE_GROUPING_CHAN_FOR_ALL_LINES);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);

  start_task();
  ReadDigitalWaveformsResponse read_response;
  auto read_status = read_digital_waveforms(NUM_SAMPLES, TIMEOUT, WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_EXTENDED_PROPERTIES, read_response);
  stop_task();

  EXPECT_SUCCESS(read_status, read_response);
  EXPECT_EQ(read_response.status(), DAQMX_SUCCESS);
  EXPECT_EQ(read_response.waveforms_size(), 2); // Two channels: di_port0 and di_port0_lines45
  EXPECT_EQ(read_response.samps_per_chan_read(), NUM_SAMPLES);
  
  for (int i = 0; i < read_response.waveforms_size(); ++i) {
    const auto& waveform = read_response.waveforms(i);
    
    int expected_signal_count = (i == 0) ? 3 : 2; // port0 lines 0:2 has 3 lines, lines 4:5 has 2 lines
    EXPECT_EQ(waveform.signal_count(), expected_signal_count);
    EXPECT_EQ(static_cast<int32>(waveform.y_data().size()), NUM_SAMPLES * expected_signal_count);
    EXPECT_GT(waveform.attributes_size(), 0);
    
    std::string expected_channel_name = (i == 0) ? "di_port0" : "di_port0_lines45";
    bool has_channel_name = false;
    for (const auto& attr_pair : waveform.attributes()) {
      const auto& attr_name = attr_pair.first;
      const auto& attr_value = attr_pair.second;
      
      if (attr_name == "NI_ChannelName" && attr_value.has_string_value()) {
        if (attr_value.string_value() == expected_channel_name) {
          has_channel_name = true;
        }
      }
    }
    EXPECT_TRUE(has_channel_name);
  }
}

TEST_F(NiDAQmxDriverApiTests, ReadDigitalWaveforms_WithTimingAndExtendedPropertiesMode_ReturnsWaveformDataWithTimingAndAttributes)
{
  const auto NUM_SAMPLES = 50;
  const auto TIMEOUT = 10.0;
  CreateDIChanResponse create_channel_response;
  auto create_channel_status = create_di_chan(create_channel_response, "gRPCSystemTestDAQ/port0/line0:2", "di_port0", LineGrouping::LINE_GROUPING_CHAN_FOR_ALL_LINES);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);
  create_channel_status = create_di_chan(create_channel_response, "gRPCSystemTestDAQ/port0/line4:5", "di_port0_lines45", LineGrouping::LINE_GROUPING_CHAN_FOR_ALL_LINES);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);

  auto timing_request = create_cfg_samp_clk_timing_request(1000.0, Edge1::EDGE1_RISING, AcquisitionType::ACQUISITION_TYPE_FINITE_SAMPS, NUM_SAMPLES);
  CfgSampClkTimingResponse timing_response;
  auto timing_status = cfg_samp_clk_timing(timing_request, timing_response);
  EXPECT_SUCCESS(timing_status, timing_response);

  const auto combined_mode = static_cast<WaveformAttributeMode>(
    WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_TIMING | 
    WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_EXTENDED_PROPERTIES);

  start_task();
  ReadDigitalWaveformsResponse read_response;
  auto read_status = read_digital_waveforms(NUM_SAMPLES, TIMEOUT, combined_mode, read_response);
  stop_task();

  EXPECT_SUCCESS(read_status, read_response);
  EXPECT_EQ(read_response.status(), DAQMX_SUCCESS);
  EXPECT_EQ(read_response.waveforms_size(), 2); // Two channels: di_port0 and di_port0_lines45
  EXPECT_EQ(read_response.samps_per_chan_read(), NUM_SAMPLES);
  
  for (int i = 0; i < read_response.waveforms_size(); ++i) {
    const auto& waveform = read_response.waveforms(i);
    
    int expected_signal_count = (i == 0) ? 3 : 2; // port0 lines 0:2 has 3 lines, lines 4:5 has 2 lines
    EXPECT_EQ(waveform.signal_count(), expected_signal_count);
    EXPECT_EQ(static_cast<int32>(waveform.y_data().size()), NUM_SAMPLES * expected_signal_count);
    
    EXPECT_TRUE(waveform.has_t0());
    EXPECT_GT(waveform.dt(), 0.0);
    
    EXPECT_GT(waveform.attributes_size(), 0);
    
    std::string expected_channel_name = (i == 0) ? "di_port0" : "di_port0_lines45";
    bool has_channel_name = false;
    for (const auto& attr_pair : waveform.attributes()) {
      const auto& attr_name = attr_pair.first;
      const auto& attr_value = attr_pair.second;
      
      if (attr_name == "NI_ChannelName" && attr_value.has_string_value()) {
        if (attr_value.string_value() == expected_channel_name) {
          has_channel_name = true;
        }
      }
    }
    EXPECT_TRUE(has_channel_name);
  }
}

TEST_F(NiDAQmxDriverApiTests, WriteAnalogWaveforms_SingleChannel_Succeeds)
{
  const double AO_MIN = -5.0;
  const double AO_MAX = 5.0;
  const auto NUM_SAMPLES = 1000;
  const auto TIMEOUT = 10.0;
  
  CreateAOVoltageChanResponse create_channel_response;
  auto create_channel_status = create_ao_voltage_chan(AO_MIN, AO_MAX, create_channel_response);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);

  start_task();
  
  std::vector<std::vector<double>> waveform_data(1);
  waveform_data[0] = generate_random_data(AO_MIN, AO_MAX, NUM_SAMPLES);
  
  WriteAnalogWaveformsResponse write_response;
  auto write_status = write_analog_waveforms(waveform_data, false, TIMEOUT, write_response);
  stop_task();

  EXPECT_SUCCESS(write_status, write_response);
  EXPECT_EQ(write_response.status(), DAQMX_SUCCESS);
  EXPECT_EQ(write_response.samps_per_chan_written(), NUM_SAMPLES);
  EXPECT_GT(write_response.samps_per_chan_written(), 0);
}

TEST_F(NiDAQmxDriverApiTests, WriteAnalogWaveforms_MultipleChannels_Succeeds)
{
  const double AO_MIN = -3.0;
  const double AO_MAX = 3.0;
  const auto NUM_SAMPLES = 500;
  const auto TIMEOUT = 10.0;
  
  CreateAOVoltageChanResponse create_channel_response;
  auto create_channel_status = create_ao_voltage_chan("gRPCSystemTestDAQ/ao0", "ao0", AO_MIN, AO_MAX, create_channel_response);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);
  create_channel_status = create_ao_voltage_chan("gRPCSystemTestDAQ/ao1", "ao1", AO_MIN, AO_MAX, create_channel_response);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);

  start_task();
  
  std::vector<std::vector<double>> waveform_data(2);
  waveform_data[0] = generate_random_data(AO_MIN, AO_MAX, NUM_SAMPLES);
  waveform_data[1] = generate_random_data(AO_MIN, AO_MAX, NUM_SAMPLES);
  
  WriteAnalogWaveformsResponse write_response;
  auto write_status = write_analog_waveforms(waveform_data, false, TIMEOUT, write_response);
  stop_task();

  EXPECT_SUCCESS(write_status, write_response);
  EXPECT_EQ(write_response.status(), DAQMX_SUCCESS);
  EXPECT_EQ(write_response.samps_per_chan_written(), NUM_SAMPLES);
  EXPECT_GT(write_response.samps_per_chan_written(), 0);
}

TEST_F(NiDAQmxDriverApiTests, WriteAnalogWaveforms_WithAutoStart_Succeeds)
{
  const double AO_MIN = -2.0;
  const double AO_MAX = 2.0;
  const auto NUM_SAMPLES = 100;
  const auto TIMEOUT = 10.0;
  
  CreateAOVoltageChanResponse create_channel_response;
  auto create_channel_status = create_ao_voltage_chan(AO_MIN, AO_MAX, create_channel_response);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);

  // Don't start task manually since we're using auto_start
  std::vector<std::vector<double>> waveform_data(1);
  waveform_data[0] = generate_random_data(AO_MIN, AO_MAX, NUM_SAMPLES);
  
  WriteAnalogWaveformsResponse write_response;
  auto write_status = write_analog_waveforms(waveform_data, true, TIMEOUT, write_response);
  stop_task();

  EXPECT_SUCCESS(write_status, write_response);
  EXPECT_EQ(write_response.status(), DAQMX_SUCCESS);
  EXPECT_EQ(write_response.samps_per_chan_written(), NUM_SAMPLES);
  EXPECT_GT(write_response.samps_per_chan_written(), 0);
}

TEST_F(NiDAQmxDriverApiTests, WriteAnalogWaveforms_WithOutOfRangeValue_ReturnsInvalidAODataError)
{
  const double AO_MIN = 0.0;
  const double AO_MAX = 5.0;
  const auto NUM_SAMPLES = 100;
  
  CreateAOVoltageChanResponse create_channel_response;
  auto create_channel_status = create_ao_voltage_chan(AO_MIN, AO_MAX, create_channel_response);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);

  start_task();
  
  EXPECT_THROW_DRIVER_ERROR({
    std::vector<std::vector<double>> waveform_data(1);
    waveform_data[0] = generate_random_data(AO_MIN, AO_MAX, NUM_SAMPLES);
    waveform_data[0][50] = AO_MAX + 10.0;  // Out of range value
    
    WriteAnalogWaveformsResponse write_response;
    write_analog_waveforms(waveform_data, false, 10.0, write_response);
  }, INVALID_AO_DATA_WRITE_ERROR);
  
  stop_task();
}

TEST_F(NiDAQmxDriverApiTests, WriteAnalogWaveforms_MismatchedNumberOfWaveforms_ReturnsError)
{
  const double AO_MIN = -1.0;
  const double AO_MAX = 1.0;
  const auto NUM_SAMPLES = 100;
  
  CreateAOVoltageChanResponse create_channel_response;
  auto create_channel_status = create_ao_voltage_chan(AO_MIN, AO_MAX, create_channel_response);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);

  start_task();
  
  // Provide waveforms for 2 channels but task only has 1 channel
  std::vector<std::vector<double>> waveform_data(2);
  waveform_data[0] = generate_random_data(AO_MIN, AO_MAX, NUM_SAMPLES);
  waveform_data[1] = generate_random_data(AO_MIN, AO_MAX, NUM_SAMPLES);
  
  EXPECT_THROW({
    try {
      WriteAnalogWaveformsResponse write_response;
      write_analog_waveforms(waveform_data, false, 10.0, write_response);
    }
    catch (const nidevice_grpc::experimental::client::grpc_driver_error& ex) {
      EXPECT_EQ(::grpc::StatusCode::UNKNOWN, ex.StatusCode());
      throw;
    }
  }, nidevice_grpc::experimental::client::grpc_driver_error);
  
  stop_task();
}

TEST_F(NiDAQmxDriverApiTests, WriteAnalogWaveforms_MismatchedSampleCounts_ReturnsError)
{
  const double AO_MIN = -1.0;
  const double AO_MAX = 1.0;
  const auto NUM_SAMPLES = 100;
  
  CreateAOVoltageChanResponse create_channel_response;
  auto create_channel_status = create_ao_voltage_chan("gRPCSystemTestDAQ/ao0", "ao0", AO_MIN, AO_MAX, create_channel_response);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);
  create_channel_status = create_ao_voltage_chan("gRPCSystemTestDAQ/ao1", "ao1", AO_MIN, AO_MAX, create_channel_response);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);

  start_task();
  
  // Provide waveforms with different sample counts
  std::vector<std::vector<double>> waveform_data(2);
  waveform_data[0] = generate_random_data(AO_MIN, AO_MAX, NUM_SAMPLES);
  waveform_data[1] = generate_random_data(AO_MIN, AO_MAX, NUM_SAMPLES / 2);  // Different count
  
  EXPECT_THROW_GRPC_INVALID_ARGUMENT({
    WriteAnalogWaveformsResponse write_response;
    write_analog_waveforms(waveform_data, false, 10.0, write_response);
  });
  
  stop_task();
}

TEST_F(NiDAQmxDriverApiTests, WriteAnalogWaveforms_ZeroSamples_Succeeds)
{
  const double AO_MIN = -1.0;
  const double AO_MAX = 1.0;
  
  CreateAOVoltageChanResponse create_channel_response;
  auto create_channel_status = create_ao_voltage_chan("gRPCSystemTestDAQ/ao0", "ao0", AO_MIN, AO_MAX, create_channel_response);
  EXPECT_SUCCESS(create_channel_status, create_channel_response);

  start_task();
  
  // Provide waveforms with zero samples
  std::vector<std::vector<double>> waveform_data(1);
  waveform_data[0] = {};  // Empty waveform
  
  WriteAnalogWaveformsResponse write_response;
  auto write_status = write_analog_waveforms(waveform_data, false, 10.0, write_response);
  
  EXPECT_SUCCESS(write_status, write_response);
  EXPECT_EQ(write_response.samps_per_chan_written(), 0);
  
  stop_task();
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
  EXPECT_THROW_DRIVER_ERROR({
    auto write_data = generate_random_data(AO_MIN, AO_MAX, 100);
    write_data[80] += AO_MAX;
    WriteAnalogF64Response write_response;
    write_analog_f64(write_data, write_response);
  }, INVALID_AO_DATA_WRITE_ERROR);
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
  const auto TIMEOUT = 10.0;

  CfgSampClkTimingResponse response;
  auto config_status = cfg_samp_clk_timing(response);
  start_task();
  ReadAnalogF64Response read_response;
  const auto NUM_SAMPS = 10;
  auto read_status = read_analog_f64(NUM_SAMPS, NUM_SAMPS, TIMEOUT, read_response);
  stop_task();

  EXPECT_SUCCESS(config_status, response);
  EXPECT_SUCCESS(read_status, read_response);
  EXPECT_EQ(NUM_SAMPS, read_response.samps_per_chan_read());
}

TEST_F(NiDAQmxDriverApiTests, AIFiniteAcquisition_ReadWithTimeoutTooSmall_SamplesNotYetAvailableStatusReturned)
{
  create_ai_voltage_chan(0.0, 1.0);
  const auto TIMEOUT = 100e-3;
  const auto SAMPLE_RATE = 1000.0;
  const auto SAMPLES_PER_CHAN = 60000UL;
  const auto NUM_SAMPS = 60000;
  cfg_samp_clk_timing(
      create_cfg_samp_clk_timing_request(SAMPLE_RATE, Edge1::EDGE1_RISING, AcquisitionType::ACQUISITION_TYPE_FINITE_SAMPS , SAMPLES_PER_CHAN));
  
  start_task();
  ReadAnalogF64Response read_response;
  read_analog_f64(NUM_SAMPS, NUM_SAMPS, TIMEOUT, read_response);

  EXPECT_EQ(SAMPLES_NOT_YET_AVAILABLE_ERROR, read_response.status());
}

TEST_F(NiDAQmxDriverApiTests, ChannelWithDoneEventRegistered_RunCompleteFiniteAcquisition_DoneEventResponseIsReceived)
{
  const auto FINITE_SAMPLE_COUNT = 10UL;
  create_ai_voltage_chan(0.0, 1.0);
  cfg_samp_clk_timing(
    create_cfg_samp_clk_timing_request(1000.0, Edge1::EDGE1_RISING, AcquisitionType::ACQUISITION_TYPE_FINITE_SAMPS, FINITE_SAMPLE_COUNT));
  ::grpc::ClientContext reader_context;
  auto reader = register_done_event(reader_context);
  reader->WaitForInitialMetadata();

  start_task();
  read_analog_f64(FINITE_SAMPLE_COUNT, FINITE_SAMPLE_COUNT);
  RegisterDoneEventResponse response;
  read_stream(reader_context, *reader, response);

  EXPECT_EQ(DAQMX_SUCCESS, response.status());
}

TEST_F(NiDAQmxDriverApiTests, ChannelWithDoneEventRegistered_RunMultipleFiniteAcquisitions_DoneEventResponsesAreReceived)
{
  const auto ACQUISITION_COUNT = 3UL;
  const auto FINITE_SAMPLE_COUNT = 10UL;
  create_ai_voltage_chan(0.0, 1.0);
  cfg_samp_clk_timing(
    create_cfg_samp_clk_timing_request(1000.0, Edge1::EDGE1_RISING, AcquisitionType::ACQUISITION_TYPE_FINITE_SAMPS, FINITE_SAMPLE_COUNT));
  ::grpc::ClientContext reader_context;
  auto reader = register_done_event(reader_context);
  reader->WaitForInitialMetadata();

  std::vector<RegisterDoneEventResponse> responses;
  for (auto acquisition = 0UL; acquisition < ACQUISITION_COUNT; ++acquisition) {
    start_task();
    read_analog_f64(FINITE_SAMPLE_COUNT, FINITE_SAMPLE_COUNT);
    read_stream(reader_context, *reader, 1, responses);
    stop_task();
  }

  EXPECT_THAT(responses, SizeIs(ACQUISITION_COUNT));
  EXPECT_THAT(responses, Each(Property(&RegisterDoneEventResponse::status, Eq(DAQMX_SUCCESS))));
}

TEST_F(NiDAQmxDriverApiTests, ChannelWithEveryNSamplesEventRegistered_WaitForSamplesMultipleTimes_EveryNSamplesEventResponsesAreReceived)
{
  const auto FINITE_SAMPLE_COUNT = 100UL;
  const auto N_SAMPLES = 10UL;
  const auto N_READS = 10UL;
  create_ai_voltage_chan(0.0, 1.0);
  cfg_samp_clk_timing(
      create_cfg_samp_clk_timing_request(1000.0, Edge1::EDGE1_RISING, AcquisitionType::ACQUISITION_TYPE_FINITE_SAMPS, FINITE_SAMPLE_COUNT));
  ::grpc::ClientContext reader_context;
  auto reader = register_every_n_samples_event(reader_context, N_SAMPLES);
  reader->WaitForInitialMetadata();

  start_task();
  std::vector<RegisterEveryNSamplesEventResponse> responses;
  for (auto i = 0UL; i < N_READS; ++i) {
    read_stream(reader_context, *reader, 1, responses);
    read_analog_f64(N_SAMPLES, N_SAMPLES);
  }

  EXPECT_THAT(responses, SizeIs(N_READS));
  EXPECT_THAT(responses, Each(Property(&RegisterEveryNSamplesEventResponse::n_samples, Eq(N_SAMPLES))));
  EXPECT_THAT(responses, Each(Property(&RegisterEveryNSamplesEventResponse::status, Eq(DAQMX_SUCCESS))));
}

TEST_F(NiDAQmxDriverApiTests, ChannelWithEveryNSamplesEventRegistered_RunMultipleFiniteAcquisitions_EveryNSamplesEventResponsesAreReceived)
{
  const auto ACQUISITION_COUNT = 3UL;
  const auto FINITE_SAMPLE_COUNT = 100UL;
  const auto N_SAMPLES = 10UL;
  const auto N_READS = 10UL;
  create_ai_voltage_chan(0.0, 1.0);
  cfg_samp_clk_timing(
      create_cfg_samp_clk_timing_request(1000.0, Edge1::EDGE1_RISING, AcquisitionType::ACQUISITION_TYPE_FINITE_SAMPS, FINITE_SAMPLE_COUNT));
  ::grpc::ClientContext reader_context;
  auto reader = register_every_n_samples_event(reader_context, N_SAMPLES);
  reader->WaitForInitialMetadata();

  std::vector<RegisterEveryNSamplesEventResponse> responses;
  for (auto acquisition = 0UL; acquisition < ACQUISITION_COUNT; ++acquisition) {
    start_task();
    for (auto i = 0UL; i < N_READS; ++i) {
      read_stream(reader_context, *reader, 1, responses);
      read_analog_f64(N_SAMPLES, N_SAMPLES);
    }
    stop_task();
  }

  EXPECT_THAT(responses, SizeIs(ACQUISITION_COUNT * N_READS));
  EXPECT_THAT(responses, Each(Property(&RegisterEveryNSamplesEventResponse::n_samples, Eq(N_SAMPLES))));
  EXPECT_THAT(responses, Each(Property(&RegisterEveryNSamplesEventResponse::status, Eq(DAQMX_SUCCESS))));
}

TEST_F(NiDAQmxDriverApiTests, Channel_RunMultipleFiniteAcquisitionsWithVaryingEveryNSamplesEventInterval_EveryNSamplesEventResponsesAreReceived)
{
  const auto ACQUISITION_COUNT = 3UL;
  const auto FINITE_SAMPLE_COUNT = 100UL;
  const uint32_t N_SAMPLES[ACQUISITION_COUNT] = {10, 20, 25};
  const size_t N_READS[ACQUISITION_COUNT] = {10, 5, 4};
  create_ai_voltage_chan(0.0, 1.0);
  cfg_samp_clk_timing(
    create_cfg_samp_clk_timing_request(1000.0, Edge1::EDGE1_RISING, AcquisitionType::ACQUISITION_TYPE_FINITE_SAMPS, FINITE_SAMPLE_COUNT));

  std::vector<RegisterEveryNSamplesEventResponse> responses[ACQUISITION_COUNT];
  for (auto acquisition = 0UL; acquisition < ACQUISITION_COUNT; ++acquisition) {
    ASSERT_EQ(FINITE_SAMPLE_COUNT, N_SAMPLES[acquisition] * N_READS[acquisition]);
    ::grpc::ClientContext reader_context;
    auto reader = register_every_n_samples_event(reader_context, N_SAMPLES[acquisition]);
    reader->WaitForInitialMetadata();
    start_task();
    for (auto i = 0UL; i < N_READS[acquisition]; ++i) {
      read_stream(reader_context, *reader, 1, responses[acquisition]);
      read_analog_f64(N_SAMPLES[acquisition], N_SAMPLES[acquisition]);
    }
    stop_task();
    unregister_every_n_samples_event();
  }

  for (auto acquisition = 0UL; acquisition < ACQUISITION_COUNT; ++acquisition) {
    SCOPED_TRACE(Message() << "acquisition=" << acquisition);
    EXPECT_THAT(responses[acquisition], SizeIs(N_READS[acquisition]));
    EXPECT_THAT(responses[acquisition], Each(Property(&RegisterEveryNSamplesEventResponse::n_samples, Eq(N_SAMPLES[acquisition]))));
    EXPECT_THAT(responses[acquisition], Each(Property(&RegisterEveryNSamplesEventResponse::status, Eq(DAQMX_SUCCESS))));
  }
}

TEST_F(NiDAQmxDriverApiTests, ChannelWithDoneEventRegisteredTwice_RunCompleteFiniteAcquisition_DoneEventResponseAndAlreadyRegisteredErrorReceived)
{
  const auto FINITE_SAMPLE_COUNT = 10UL;
  create_ai_voltage_chan(0.0, 1.0);
  cfg_samp_clk_timing(
      create_cfg_samp_clk_timing_request(1000.0, Edge1::EDGE1_RISING, AcquisitionType::ACQUISITION_TYPE_FINITE_SAMPS, FINITE_SAMPLE_COUNT));
  ::grpc::ClientContext reader_context1, reader_context2;
  auto reader1 = register_done_event(reader_context1);
  reader1->WaitForInitialMetadata();
  auto reader2 = register_done_event(reader_context2);
  reader2->WaitForInitialMetadata();

  start_task();
  read_analog_f64(FINITE_SAMPLE_COUNT, FINITE_SAMPLE_COUNT);
  RegisterDoneEventResponse response1, response2;
  read_stream(reader_context1, *reader1, response1);

  EXPECT_EQ(DAQMX_SUCCESS, response1.status());
  EXPECT_THROW_DRIVER_ERROR({
    read_stream(reader_context2, *reader2, response2);
  }, DONE_EVENT_ALREADY_REGISTERED_ERROR);
}

TEST_F(NiDAQmxDriverApiTests, EveryNSamplesEventRegisteredWithNonBufferedTask_StartTask_NotSupportedForNonBufferedTaskErrorReceived)
{
  const auto N_SAMPLES = 10UL;
  create_ai_voltage_chan(0.0, 1.0);
  ::grpc::ClientContext reader_context;
  auto reader = register_every_n_samples_event(reader_context, N_SAMPLES);
  reader->WaitForInitialMetadata();

  EXPECT_THROW_DRIVER_ERROR({
    start_task();
  }, EVERY_N_SAMPLES_EVENT_NOT_SUPPORTED_FOR_NON_BUFFERED_TASKS);
}

TEST_F(NiDAQmxDriverApiTests, EveryNSamplesEventRegisteredWithWrongEventType_ReadStream_NotSupportedByDeviceErrorReceived)
{
  const auto N_SAMPLES = 10UL;
  create_ai_voltage_chan(0.0, 1.0);
  cfg_samp_clk_timing(); // Every N Samples requires a buffered task (validated in start_task)
  ::grpc::ClientContext reader_context;
  auto reader = register_every_n_samples_event(reader_context, N_SAMPLES, EveryNSamplesEventType::EVERY_N_SAMPLES_EVENT_TYPE_TRANSFERRED_FROM_BUFFER);
  reader->WaitForInitialMetadata();

  RegisterEveryNSamplesEventResponse response;
  EXPECT_THROW_DRIVER_ERROR({
    read_stream(reader_context, *reader, response);
  }, EVERY_N_SAMPS_TRANSFERRED_FROM_BUFFER_EVENT_NOT_SUPPORTED_BY_DEVICE_ERROR);
}

TEST_F(NiDAQmxDriverApiTests, EveryNSamplesEventRegisteredWithWrongEventType_Finish_NotSupportedByDeviceErrorReceived)
{
  const auto N_SAMPLES = 10UL;
  create_ai_voltage_chan(0.0, 1.0);
  cfg_samp_clk_timing(); // Every N Samples requires a buffered task (validated in start_task)
  ::grpc::ClientContext reader_context;
  auto reader = register_every_n_samples_event(reader_context, N_SAMPLES, EveryNSamplesEventType::EVERY_N_SAMPLES_EVENT_TYPE_TRANSFERRED_FROM_BUFFER);
  reader->WaitForInitialMetadata();

  EXPECT_THROW_DRIVER_ERROR({
    auto status = reader->Finish();
    client::raise_if_error(status, reader_context);
  }, EVERY_N_SAMPS_TRANSFERRED_FROM_BUFFER_EVENT_NOT_SUPPORTED_BY_DEVICE_ERROR);
}

TEST_F(NiDAQmxDriverApiTests, EveryNSamplesEventRegisteredWithWrongEventType_Cancel_NoErrors)
{
  const auto N_SAMPLES = 10UL;
  create_ai_voltage_chan(0.0, 1.0);
  ::grpc::ClientContext reader_context;
  auto reader = register_every_n_samples_event(reader_context, N_SAMPLES, EveryNSamplesEventType::EVERY_N_SAMPLES_EVENT_TYPE_TRANSFERRED_FROM_BUFFER);
  reader->WaitForInitialMetadata();

  reader_context.TryCancel();
}

TEST_F(NiDAQmxDriverApiTests, AsyncEveryNSamplesEventRegistered_OnEventReadAnalogF64_EventAndReadResponsesAreReceived)
{
  const auto FINITE_SAMPLE_COUNT = 100UL;
  const auto N_SAMPLES = 10UL;
  const auto N_READS = 10UL;
  const auto EVENT_START_CALL_TAG = (void*)1;
  const auto EVENT_READ_INITIAL_METADATA_TAG = (void*)2;
  const auto EVENT_READ_TAG = (void*)3;
  const auto READ_ANALOG_F64_TAG = (void*)4;
  create_ai_voltage_chan(0.0, 1.0);
  cfg_samp_clk_timing(
      create_cfg_samp_clk_timing_request(1000.0, Edge1::EDGE1_RISING, AcquisitionType::ACQUISITION_TYPE_FINITE_SAMPS, FINITE_SAMPLE_COUNT));
  ::grpc::ClientContext event_context;
  ::grpc::CompletionQueue completion_queue;
  auto shut_down_on_exit = make_scope_exit([&]{ shut_down_completion_queue(completion_queue); });
  auto event_reader = async_register_every_n_samples_event(event_context, completion_queue, EVENT_START_CALL_TAG, N_SAMPLES);
  async_wait_for_initial_metadata(event_context, *event_reader, completion_queue, EVENT_START_CALL_TAG, EVENT_READ_INITIAL_METADATA_TAG);

  start_task();
  RegisterEveryNSamplesEventResponse event_response;
  event_reader->Read(&event_response, EVENT_READ_TAG);
  std::vector<RegisterEveryNSamplesEventResponse> event_responses;
  std::vector<ReadAnalogF64Response> read_responses;
  std::unique_ptr<::grpc::ClientContext> read_context;
  std::unique_ptr<::grpc::ClientAsyncResponseReader<ReadAnalogF64Response>> read_reader;
  ReadAnalogF64Response read_response;
  ::grpc::Status read_status;
  while (read_responses.size() < N_READS) {
    auto completion = get_next_completion(completion_queue);
    if (get_completion_tag(completion) == EVENT_READ_TAG) {
      ASSERT_TRUE(is_completion_ok(completion));
      event_responses.push_back(event_response);
      if (event_responses.size() < N_READS) {
        event_reader->Read(&event_response, EVENT_READ_TAG);
      }
      // Start a new read, unless the previous read hasn't completed yet.
      if (read_responses.size() < N_READS && !read_context) {
        read_context = std::make_unique<::grpc::ClientContext>();
        read_reader = async_read_analog_f64(
          *read_context, completion_queue, READ_ANALOG_F64_TAG, N_SAMPLES, N_SAMPLES,
          read_response, read_status);
      }
    }
    else if (get_completion_tag(completion) == READ_ANALOG_F64_TAG) {
      ASSERT_TRUE(is_completion_ok(completion));
      client::raise_if_error(read_status, *read_context);
      read_responses.push_back(read_response);
      read_reader.reset();
      read_context.reset();
      // If reads can't keep up with events, do back-to-back reads.
      if (read_responses.size() < N_READS && read_responses.size() < event_responses.size()) {
        read_context = std::make_unique<::grpc::ClientContext>();
        read_reader = async_read_analog_f64(
          *read_context, completion_queue, READ_ANALOG_F64_TAG, N_SAMPLES, N_SAMPLES,
          read_response, read_status);
      }
    }
    else {
      FAIL() << "Unexpected completion: " << PrintToString(completion);
    }
  }

  EXPECT_THAT(event_responses, SizeIs(N_READS));
  EXPECT_THAT(event_responses, Each(Property(&RegisterEveryNSamplesEventResponse::n_samples, Eq(N_SAMPLES))));
  EXPECT_THAT(event_responses, Each(Property(&RegisterEveryNSamplesEventResponse::status, Eq(DAQMX_SUCCESS))));
  EXPECT_THAT(read_responses, SizeIs(N_READS));
  EXPECT_THAT(read_responses, Each(Property(&ReadAnalogF64Response::read_array, SizeIs(N_SAMPLES))));
  EXPECT_THAT(read_responses, Each(Property(&ReadAnalogF64Response::samps_per_chan_read, Eq(N_SAMPLES))));
  EXPECT_THAT(read_responses, Each(Property(&ReadAnalogF64Response::status, Eq(DAQMX_SUCCESS))));
}

// This test uses the async API in order to check whether the event stream is closed without blocking.
TEST_F(NiDAQmxDriverApiTests, AsyncEveryNSamplesEventRegisteredWithWrongEventTypeAndWaitForMetadata_ReadStreamWithoutBlocking_ReadCompletesImmediatelyWithError)
{
  const auto N_SAMPLES = 10UL;
  const auto START_CALL_TAG = (void*)1;
  const auto READ_INITIAL_METADATA_TAG = (void*)2;
  const auto READ_TAG = (void*)3;
  const auto FINISH_TAG = (void*)4;
  create_ai_voltage_chan(0.0, 1.0);
  cfg_samp_clk_timing(); // Every N Samples requires a buffered task (validated in start_task)
  ::grpc::ClientContext reader_context;
  ::grpc::CompletionQueue completion_queue;
  auto shut_down_on_exit = make_scope_exit([&]{ shut_down_completion_queue(completion_queue); });
  auto reader = async_register_every_n_samples_event(
    reader_context, completion_queue, START_CALL_TAG, N_SAMPLES,
    EveryNSamplesEventType::EVERY_N_SAMPLES_EVENT_TYPE_TRANSFERRED_FROM_BUFFER);
  async_wait_for_initial_metadata(reader_context, *reader, completion_queue, START_CALL_TAG, READ_INITIAL_METADATA_TAG);

  RegisterEveryNSamplesEventResponse response;
  reader->Read(&response, READ_TAG);
  Completion read_completion;
  bool read_completed = try_get_next_completion_without_blocking(completion_queue, read_completion);

  EXPECT_TRUE(read_completed);
  EXPECT_EQ(Completion(READ_TAG, false), read_completion);  // read_completion should NOT be OK
  ::grpc::Status status;
  reader->Finish(&status, FINISH_TAG);
  Completion finish_completion;
  bool finish_completed = try_get_next_completion_without_blocking(completion_queue, finish_completion);
  EXPECT_TRUE(finish_completed);
  ASSERT_EQ(Completion(FINISH_TAG, true), finish_completion);
  EXPECT_THROW_DRIVER_ERROR({
    client::raise_if_error(status, reader_context);
  }, EVERY_N_SAMPS_TRANSFERRED_FROM_BUFFER_EVENT_NOT_SUPPORTED_BY_DEVICE_ERROR);
}

TEST_F(NiDAQmxDriverApiTests, Channel_AsyncRegisterUnregisterDoneEventMultipleTimes_NoErrors)
{
  const auto N_ITERATIONS = 10UL;
  const auto START_CALL_TAG = (void*)1;
  const auto READ_INITIAL_METADATA_TAG = (void*)2;
  const auto READ_TAG = (void*)3;
  const auto FINISH_TAG = (void*)4;
  create_ai_voltage_chan(0.0, 1.0);
  ::grpc::CompletionQueue completion_queue;
  auto shut_down_on_exit = make_scope_exit([&]{ shut_down_completion_queue(completion_queue); });

  for (auto i = 0UL; i < N_ITERATIONS; ++i) {
    ::grpc::ClientContext reader_context;
    auto reader = async_register_done_event(reader_context, completion_queue, START_CALL_TAG);
    auto cancel_on_exit = make_scope_exit([&]{ async_cancel_stream(reader_context, *reader, completion_queue, FINISH_TAG); });
    async_wait_for_initial_metadata(reader_context, *reader, completion_queue, START_CALL_TAG, READ_INITIAL_METADATA_TAG);
    RegisterDoneEventResponse response;
    async_begin_read_stream(reader_context, *reader, completion_queue, READ_TAG, FINISH_TAG, response); // check for errors
    unregister_done_event(); // does not close/cancel stream
  }
}

TEST_F(NiDAQmxDriverApiTests, Channel_AsyncRegisterUnregisterEveryNSamplesEventMultipleTimes_NoErrors)
{
  const auto N_ITERATIONS = 10UL;
  const auto N_SAMPLES = 10UL;
  const auto START_CALL_TAG = (void*)1;
  const auto READ_INITIAL_METADATA_TAG = (void*)2;
  const auto READ_TAG = (void*)3;
  const auto FINISH_TAG = (void*)4;
  create_ai_voltage_chan(0.0, 1.0);
  cfg_samp_clk_timing(); // Every N Samples requires a buffered task (validated in start_task)
  ::grpc::CompletionQueue completion_queue;
  auto shut_down_on_exit = make_scope_exit([&]{ shut_down_completion_queue(completion_queue); });

  for (auto i = 0UL; i < N_ITERATIONS; ++i) {
    ::grpc::ClientContext reader_context;
    auto reader = async_register_every_n_samples_event(reader_context, completion_queue, START_CALL_TAG, N_SAMPLES);
    auto cancel_on_exit = make_scope_exit([&]{ async_cancel_stream(reader_context, *reader, completion_queue, FINISH_TAG); });
    async_wait_for_initial_metadata(reader_context, *reader, completion_queue, START_CALL_TAG, READ_INITIAL_METADATA_TAG);
    RegisterEveryNSamplesEventResponse response;
    async_begin_read_stream(reader_context, *reader, completion_queue, READ_TAG, FINISH_TAG, response); // check for errors
    unregister_every_n_samples_event(); // does not close/cancel stream
  }
}

TEST_F(NiDAQmxDriverApiTests, Channel_AsyncRegisterUnregisterSignalEventMultipleTimes_NoErrors)
{
  const auto N_ITERATIONS = 10UL;
  const auto START_CALL_TAG = (void*)1;
  const auto READ_INITIAL_METADATA_TAG = (void*)2;
  const auto READ_TAG = (void*)3;
  const auto FINISH_TAG = (void*)4;
  create_ai_voltage_chan(0.0, 1.0);
  ::grpc::CompletionQueue completion_queue;
  auto shut_down_on_exit = make_scope_exit([&]{ shut_down_completion_queue(completion_queue); });

  for (auto i = 0UL; i < N_ITERATIONS; ++i) {
    ::grpc::ClientContext reader_context;
    auto reader = async_register_signal_event(reader_context, completion_queue, START_CALL_TAG, Signal2::SIGNAL2_SAMPLE_COMPLETE_EVENT);
    auto cancel_on_exit = make_scope_exit([&]{ async_cancel_stream(reader_context, *reader, completion_queue, FINISH_TAG); });
    async_wait_for_initial_metadata(reader_context, *reader, completion_queue, START_CALL_TAG, READ_INITIAL_METADATA_TAG);
    RegisterSignalEventResponse response;
    async_begin_read_stream(reader_context, *reader, completion_queue, READ_TAG, FINISH_TAG, response); // check for errors
    unregister_signal_event(Signal2::SIGNAL2_SAMPLE_COMPLETE_EVENT); // does not close/cancel stream
  }
}

TEST_F(NiDAQmxDriverApiTests, DoneEventRegisteredAndTaskRunning_UnregisterDoneEvent_CannotUnregisterErrorReceived)
{
  create_ai_voltage_chan(0.0, 1.0);
  ::grpc::ClientContext reader_context;
  auto reader = register_done_event(reader_context);
  reader->WaitForInitialMetadata();
  start_task();

  EXPECT_THROW_DRIVER_ERROR({
    unregister_done_event();
  }, CANNOT_UNREGISTER_DAQMX_SOFTWARE_EVENT_WHILE_TASK_IS_RUNNING_ERROR);
}

TEST_F(NiDAQmxDriverApiTests, EveryNSamplesEventRegisteredAndTaskRunning_UnregisterEveryNSamplesEvent_CannotUnregisterErrorReceived)
{
  auto N_SAMPLES = 10UL;
  create_ai_voltage_chan(0.0, 1.0);
  cfg_samp_clk_timing(); // Every N Samples requires a buffered task (validated in start_task)
  ::grpc::ClientContext reader_context;
  auto reader = register_every_n_samples_event(reader_context, N_SAMPLES);
  reader->WaitForInitialMetadata();
  start_task();

  EXPECT_THROW_DRIVER_ERROR({
    unregister_every_n_samples_event();
  }, CANNOT_UNREGISTER_DAQMX_SOFTWARE_EVENT_WHILE_TASK_IS_RUNNING_ERROR);
}

TEST_F(NiDAQmxDriverApiTests, SignalEventRegisteredAndTaskRunning_UnregisterSignalEvent_CannotUnregisterErrorReceived)
{
  create_ai_voltage_chan(0.0, 1.0);
  ::grpc::ClientContext reader_context;
  auto reader = register_signal_event(reader_context, Signal2::SIGNAL2_SAMPLE_COMPLETE_EVENT);
  reader->WaitForInitialMetadata();
  start_task();

  EXPECT_THROW_DRIVER_ERROR({
    unregister_signal_event(Signal2::SIGNAL2_SAMPLE_COMPLETE_EVENT);
  }, CANNOT_UNREGISTER_DAQMX_SOFTWARE_EVENT_WHILE_TASK_IS_RUNNING_ERROR);
}

TEST_F(NiDAQmxDriverApiTests, DoneEventNotRegistered_UnregisterDoneEvent_NoError)
{
  create_ai_voltage_chan(0.0, 1.0);

  unregister_done_event();
}

TEST_F(NiDAQmxDriverApiTests, EveryNSamplesEventNotRegistered_UnregisterEveryNSamplesEvent_NoError)
{
  create_ai_voltage_chan(0.0, 1.0);
  cfg_samp_clk_timing(); // Every N Samples requires a buffered task (validated in start_task)

  unregister_every_n_samples_event();
}

TEST_F(NiDAQmxDriverApiTests, SignalEventNotRegistered_UnregisterSignalEvent_NoError)
{
  create_ai_voltage_chan(0.0, 1.0);

  unregister_signal_event(Signal2::SIGNAL2_SAMPLE_COMPLETE_EVENT);
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

  EXPECT_THROW_DRIVER_ERROR({
    auto response = WaitForValidTimestampResponse{};
    auto status = wait_for_valid_timestamp(response);
  }, WAIT_FOR_VALID_TIMESTAMP_NOT_SUPPORTED_ERROR);
}

TEST_F(NiDAQmxDriverApiTests, AIVoltageChannel_CfgTimeStartTrig_ReturnsError)
{
  create_ai_voltage_chan(0.0, 1.0);

  EXPECT_THROW_DRIVER_ERROR({
    auto response = CfgTimeStartTrigResponse{};
    cfg_time_start_trig(response);
  }, INVALID_ATTRIBUTE_VALUE_ERROR);
}

TEST_F(NiDAQmxDriverApiTests, LoadedVoltageTask_ReadAIData_ReturnsDataInExpectedRange)
{
  const auto AI_MIN = 0.0;
  const auto AI_MAX = 1.0;
  const auto NUM_SAMPS = 10;
  const auto TIMEOUT = 10.0;
  create_ai_voltage_chan(AI_MIN, AI_MAX);
  auto save_response = SaveTaskResponse{};
  auto status = save_task(save_response);
  EXPECT_SUCCESS(status, save_response);
  clear_task();
  auto load_response = LoadTaskResponse{};
  status = load_task(load_response); // cleaned up by test fixture
  EXPECT_SUCCESS(status, load_response);

  auto read_response = ReadAnalogF64Response{};
  status = read_analog_f64(NUM_SAMPS, NUM_SAMPS, TIMEOUT, read_response);

  EXPECT_SUCCESS(status, read_response);
  EXPECT_DATA_IN_RANGE(read_response.read_array(), AI_MIN, AI_MAX);
}

TEST_F(NiDAQmxDriverApiTests, UnsupportedChannelType_BridgeOffsetNullingCal_ReturnsError)
{
  const auto AI_MIN = 0.0;
  const auto AI_MAX = 1.0;
  create_ai_voltage_chan(AI_MIN, AI_MAX);

  std::string channel = "";
  bool skip_unsupported_channels = false;
  EXPECT_THROW_DRIVER_ERROR({
    auto response = PerformBridgeOffsetNullingCalExResponse{};
    auto status = perform_bridge_offset_nulling_cal_ex(channel, skip_unsupported_channels, response);
  }, BRIDGE_OFFSET_NULLING_CAL_NOT_SUPPORTED_ERROR);
}

// AI Voltage Channel doesn't support Bridge Shunt Calibration
TEST_F(NiDAQmxDriverApiTests, UnsupportedChannelType_PerformBridgeShuntCalEx_ReturnsError)
{
  const auto AI_MIN = -5;
  const auto AI_MAX = 5;
  create_ai_voltage_chan(AI_MIN, AI_MAX);

  EXPECT_THROW_DRIVER_ERROR({
    auto response = PerformBridgeShuntCalExResponse{};
    auto status = perform_bridge_shunt_cal_ex(response);
  }, BRIDGE_SHUNT_CAL_NOT_SUPPORTED_ERROR);
}

// X Series doesn't support Strain Shunt Calibration
TEST_F(NiDAQmxDriverApiTests, UnsupportedDevice_PerformStrainShuntCalEx_ReturnsError)
{
  const auto AI_MIN = -0.001;
  const auto AI_MAX = 0.001;
  create_ai_strain_gage_chan(AI_MIN, AI_MAX);

  EXPECT_THROW_DRIVER_ERROR({
    auto response = PerformStrainShuntCalExResponse{};
    auto status = perform_strain_shunt_cal_ex(response);
  }, STRAIN_SHUNT_CAL_NOT_SUPPORTED_ERROR);
}

// X Series doesn't support thermocouple offset nulling
TEST_F(NiDAQmxDriverApiTests, UnsupportedDevice_ThrmcplLeadOffsetNullingCal_ReturnsError)
{
  const auto AI_MIN = 0.0;
  const auto AI_MAX = 100.0;
  create_ai_thrmcpl_chan(AI_MIN, AI_MAX);

  std::string channel = "";
  bool skip_unsupported_channels = false;
  EXPECT_THROW_DRIVER_ERROR({
    auto response = PerformThrmcplLeadOffsetNullingCalResponse{};
    auto status = perform_thrmcpl_lead_offset_nulling_cal(channel, skip_unsupported_channels, response);
  }, THRMCPL_LEAD_OFFSET_NULLING_CAL_NOT_SUPPORTED_ERROR);
}

TEST_F(NiDAQmxDriverApiTests, SelfCal_Succeeds)
{
  auto response = SelfCalResponse{};
  auto status = self_cal(response);

  EXPECT_SUCCESS(status, response);
}

TEST_F(NiDAQmxDriverApiTests, AddNetworkDeviceWithInvalidIP_ErrorRetrievingNetworkDeviceProperties)
{
  EXPECT_THROW_DRIVER_ERROR({
    auto response = AddNetworkDeviceResponse{};
    add_network_device("0.0.0.0", response);
  }, RETRIEVING_NETWORK_DEVICE_PROPERTIES_ERROR);
}

TEST_F(NiDAQmxDriverApiTests, ConfigureTEDSOnNonTEDSChannel_ErrorTEDSSensorNotDetected)
{
  EXPECT_THROW_DRIVER_ERROR({
    client::configure_teds(stub(), AI_CHANNEL, "");
  }, TEDS_SENSOR_NOT_DETECTED_ERROR);
}

TEST_F(NiDAQmxDriverApiTests, HardwareTimedTask_WaitForNextSampleClock_Succeeds)
{
  create_ao_voltage_chan(0.0, 10.0);
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
  EXPECT_THROW_DRIVER_ERROR({
    auto response = ConnectTermsResponse{};
    connect_terms("ABC", "123", response);
  }, INVALID_TERM_ROUTING_ERROR);
}

TEST_F(NiDAQmxDriverApiTests, DOWatchdogTask_StartTaskAndWatchdogTask_Succeeds)
{
  // Note: the DO chan will be the default task in this test.
  // The watchdog task is a separate task passed around through create_watchdog_response.
  create_do_chan();
  auto create_watchdog_response = CreateWatchdogTimerTaskExResponse{};
  auto create_status = create_watchdog_timer_task_ex(.001, create_watchdog_response);
  auto watchdog_task = create_watchdog_response.task();
  auto clear_watchdog_task_on_exit = make_scope_exit([&]{ clear_task(watchdog_task); });
  auto cfg_watchdog_response = CfgWatchdogDOExpirStatesResponse{};
  auto cfg_status = cfg_watchdog_do_expir_states(
      watchdog_task,
      cfg_watchdog_response);
  EXPECT_SUCCESS(create_status, create_watchdog_response);
  EXPECT_SUCCESS(cfg_status, cfg_watchdog_response);

  start_task();
  auto start_watchdog_response = StartTaskResponse{};
  auto start_watchdog_status = start_task(
      watchdog_task,
      start_watchdog_response);

  EXPECT_SUCCESS(start_watchdog_status, start_watchdog_response);
}

TEST_F(NiDAQmxDriverApiTests, AutoConfigureCDAQSyncConnections_ReturnsNotSupportedError)
{
  EXPECT_THROW_DRIVER_ERROR({
    client::auto_configure_cdaq_sync_connections(stub(), DEVICE_NAME, 1.0);
  }, DEVICE_DOES_NOT_SUPPORT_CDAQ_SYNC_CONNECTIONS_ERROR);
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
  EXPECT_THROW_DRIVER_ERROR({
    client::get_device_attribute_bool(stub(), DEVICE_NAME, ScaleDoubleAttribute::SCALE_ATTRIBUTE_LIN_SLOPE);
  }, SPECIFIED_ATTRIBUTE_NOT_VALID_ERROR);
}

TEST_F(NiDAQmxDriverApiTests, SetWrongDataTypeAttribute_ReturnsNotValidError)
{
  EXPECT_THROW_DRIVER_ERROR({
    client::get_device_attribute_bool(stub(), DEVICE_NAME, DeviceStringAttribute::DEVICE_ATTRIBUTE_AO_PHYSICAL_CHANS);
  }, SPECIFIED_ATTRIBUTE_NOT_VALID_ERROR);
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
