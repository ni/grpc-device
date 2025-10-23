#include <nidaqmx/nidaqmx_service.h>
#include <vector>
#include <memory>
#include <cstdint>
#include "NIDAQmxInternalWaveform.h"

namespace nidaqmx_grpc {

constexpr int64 TICKS_PER_SECOND = 10000000; // 100ns ticks per second
constexpr double TICKS_TO_SECONDS = 1e-7; // Convert 100ns ticks to seconds

// Returns true if it's safe to use outputs of a method with the given status.
inline bool status_ok(int32 status)
{
  return status >= 0;
}

// Callback data structure to pass waveform pointers to the callback
// This can handle both analog and digital waveforms using a variant approach
struct WaveformCallbackData {
  std::vector<::ni::protobuf::types::DoubleAnalogWaveform*> analog_waveforms;
  std::vector<::ni::protobuf::types::DigitalWaveform*> digital_waveforms;
  bool is_digital;
  
  WaveformCallbackData(bool digital = false) : is_digital(digital) {}
};

// Universal callback function for setting waveform attributes (both analog and digital)
int32 CVICALLBACK SetWfmAttrCallback(
    const uInt32 channel_index,
    const char attribute_name[],
    const int32 attribute_type,
    const void* value,
    const uInt32 value_size_in_bytes,
    void* callback_data)
{
  try {
    const auto* data = static_cast<const WaveformCallbackData*>(callback_data);
    if (!data) {
      return -1;
    }

    ::google::protobuf::Map<std::string, ::ni::protobuf::types::WaveformAttributeValue>* attributes = nullptr;
    
    if (data->is_digital) {
      if (channel_index >= data->digital_waveforms.size() || !data->digital_waveforms[channel_index]) {
        return -1;
      }
      attributes = data->digital_waveforms[channel_index]->mutable_attributes();
    } else {
      if (channel_index >= data->analog_waveforms.size() || !data->analog_waveforms[channel_index]) {
        return -1;
      }
      attributes = data->analog_waveforms[channel_index]->mutable_attributes();
    }

    ::ni::protobuf::types::WaveformAttributeValue attr_value;
    
    switch (attribute_type) {
      case DAQmx_Val_WfmAttrType_Bool32:
        if (value_size_in_bytes == sizeof(int32)) {
          const bool bool_val = (*static_cast<const int32*>(value)) != 0;
          attr_value.set_bool_value(bool_val);
        } else {
          return -1;
        }
        break;
        
      case DAQmx_Val_WfmAttrType_Float64:
        if (value_size_in_bytes == sizeof(double)) {
          const double double_val = *static_cast<const double*>(value);
          attr_value.set_double_value(double_val);
        } else {
          return -1;
        }
        break;
        
      case DAQmx_Val_WfmAttrType_Int32:
        if (value_size_in_bytes == sizeof(int32)) {
          const int32 int_val = *static_cast<const int32*>(value);
          attr_value.set_integer_value(int_val);
        } else {
          return -1;
        }
        break;
        
      case DAQmx_Val_WfmAttrType_String:
        if (value_size_in_bytes > 0) {
          const char* str_val = static_cast<const char*>(value);
          const std::string string_val(str_val, value_size_in_bytes - 1);
          attr_value.set_string_value(string_val);
        } else {
          return -1;
        }
        break;
        
      default:
        return -1;
    }
    
    (*attributes)[attribute_name] = attr_value;
    return 0;
  }
  catch (...) {
    return -1;
  }
}

::grpc::Status NiDAQmxService::ConvertApiErrorStatusForTaskHandle(::grpc::ServerContextBase* context, int32_t status, TaskHandle task)
{
  // This implementation assumes this method is always called on the same thread where the error occurred.
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library_->GetExtendedErrorInfo(&description[0], nidevice_grpc::kMaxGrpcErrorDescriptionSize);
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

::grpc::Status NiDAQmxService::ReadAnalogWaveforms(::grpc::ServerContext* context, const ReadAnalogWaveformsRequest* request, ReadAnalogWaveformsResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto task_grpc_session = request->task();
    TaskHandle task = session_repository_->access_session(task_grpc_session.name());

    const auto number_of_samples_per_channel = request->number_of_samples_per_channel();
    const auto timeout = request->timeout();
    
    int32 waveform_attribute_mode;
    switch (request->waveform_attribute_mode_enum_case()) {
      case nidaqmx_grpc::ReadAnalogWaveformsRequest::WaveformAttributeModeEnumCase::kWaveformAttributeMode: {
        waveform_attribute_mode = static_cast<int32>(request->waveform_attribute_mode());
        break;
      }
      case nidaqmx_grpc::ReadAnalogWaveformsRequest::WaveformAttributeModeEnumCase::kWaveformAttributeModeRaw: {
        waveform_attribute_mode = static_cast<int32>(request->waveform_attribute_mode_raw());
        break;
      }
      case nidaqmx_grpc::ReadAnalogWaveformsRequest::WaveformAttributeModeEnumCase::WAVEFORM_ATTRIBUTE_MODE_ENUM_NOT_SET: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for waveform_attribute_mode was not specified or out of range");
        break;
      }
    }

    uInt32 num_channels = 0;
    auto status = library_->GetReadAttributeUInt32(task, ReadUInt32Attribute::READ_ATTRIBUTE_NUM_CHANS, &num_channels);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForTaskHandle(context, status, task);
    }

    if (num_channels == 0) {
      return ::grpc::Status(::grpc::INVALID_ARGUMENT, "No channels found in task");
    }

    std::vector<std::vector<float64>> read_arrays(num_channels);
    std::vector<float64*> read_array_ptrs(num_channels);
    
    for (uInt32 i = 0; i < num_channels; ++i) {
      read_arrays[i].resize(number_of_samples_per_channel);
      read_array_ptrs[i] = read_arrays[i].data();
    }

    std::vector<int64> t0_array, dt_array;
    int64* t0_ptr = nullptr;
    int64* dt_ptr = nullptr;
    uInt32 timing_array_size = 0;
    
    if (waveform_attribute_mode & WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_TIMING) {
      t0_array.resize(num_channels, 0);
      dt_array.resize(num_channels, 0);
      t0_ptr = t0_array.data();
      dt_ptr = dt_array.data();
      timing_array_size = num_channels;
    }

    std::unique_ptr<WaveformCallbackData> callback_data;
    DAQmxSetWfmAttrCallbackPtr callback_ptr = nullptr;
    
    for (uInt32 i = 0; i < num_channels; ++i) {
      response->add_waveforms();
    }
    
    if (waveform_attribute_mode & WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_EXTENDED_PROPERTIES) {
      callback_data = std::make_unique<WaveformCallbackData>(false); // false = analog waveforms
      callback_data->analog_waveforms.resize(num_channels);
      callback_ptr = SetWfmAttrCallback;
      
      for (uInt32 i = 0; i < num_channels; ++i) {
        callback_data->analog_waveforms[i] = response->mutable_waveforms(i);
      }
    }

    int32 samples_per_chan_read = 0;
    status = library_->InternalReadAnalogWaveformPerChan(
        task,
        number_of_samples_per_channel,
        timeout,
        t0_ptr,
        dt_ptr,
        timing_array_size,
        callback_ptr,
        callback_data.get(),
        read_array_ptrs.data(),
        num_channels,
        number_of_samples_per_channel,
        &samples_per_chan_read,
        nullptr
    );

    if (!status_ok(status)) {
      return ConvertApiErrorStatusForTaskHandle(context, status, task);
    }

    for (uInt32 i = 0; i < num_channels; ++i) {
      auto* waveform = response->mutable_waveforms(i);
      
      auto* y_data = waveform->mutable_y_data();
      y_data->Reserve(samples_per_chan_read);
      for (int32 j = 0; j < samples_per_chan_read; ++j) {
        y_data->Add(read_arrays[i][j]);
      }

      if (waveform_attribute_mode & WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_TIMING) {
        if (dt_array[i] == 0) {
          return ::grpc::Status(::grpc::FAILED_PRECONDITION, 
            "Timing information requested but not available. Task must be configured with sample clock timing (e.g., CfgSampClkTiming) to provide timing information.");
        }

        auto* t0 = waveform->mutable_t0();
        // Convert from 100ns ticks (DAQmx format) to PrecisionTimestamp
        // t0_array[i] contains 100ns ticks since Jan 1, 0001 (.NET DateTime epoch)
        const int64_t seconds = t0_array[i] / TICKS_PER_SECOND;
        const int64_t fractional_ticks = t0_array[i] % TICKS_PER_SECOND;
        
        t0->set_seconds(seconds);
        t0->set_fractional_seconds(fractional_ticks);

        // Set sample interval (dt) - convert 100ns ticks to seconds
        waveform->set_dt(static_cast<double>(dt_array[i]) * TICKS_TO_SECONDS);
      }
    }

    response->set_samps_per_chan_read(samples_per_chan_read);
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

::grpc::Status NiDAQmxService::ReadDigitalWaveforms(::grpc::ServerContext* context, const ReadDigitalWaveformsRequest* request, ReadDigitalWaveformsResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto task_grpc_session = request->task();
    TaskHandle task = session_repository_->access_session(task_grpc_session.name());

    const auto number_of_samples_per_channel = request->number_of_samples_per_channel();
    const auto timeout = request->timeout();
    
    int32 waveform_attribute_mode;
    switch (request->waveform_attribute_mode_enum_case()) {
      case nidaqmx_grpc::ReadDigitalWaveformsRequest::WaveformAttributeModeEnumCase::kWaveformAttributeMode: {
        waveform_attribute_mode = static_cast<int32>(request->waveform_attribute_mode());
        break;
      }
      case nidaqmx_grpc::ReadDigitalWaveformsRequest::WaveformAttributeModeEnumCase::kWaveformAttributeModeRaw: {
        waveform_attribute_mode = static_cast<int32>(request->waveform_attribute_mode_raw());
        break;
      }
      case nidaqmx_grpc::ReadDigitalWaveformsRequest::WaveformAttributeModeEnumCase::WAVEFORM_ATTRIBUTE_MODE_ENUM_NOT_SET: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for waveform_attribute_mode was not specified or out of range");
        break;
      }
    }

    uInt32 num_channels = 0;
    auto status = library_->GetReadAttributeUInt32(task, ReadUInt32Attribute::READ_ATTRIBUTE_NUM_CHANS, &num_channels);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForTaskHandle(context, status, task);
    }

    if (num_channels == 0) {
      return ::grpc::Status(::grpc::INVALID_ARGUMENT, "No channels found in task");
    }

    // Get the maximum number of lines per channel to calculate array size
    uInt32 max_bytes_per_chan = 0;
    status = library_->GetReadAttributeUInt32(task, ReadUInt32Attribute::READ_ATTRIBUTE_DIGITAL_LINES_BYTES_PER_CHAN, &max_bytes_per_chan);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForTaskHandle(context, status, task);
    }

    if (max_bytes_per_chan == 0) {
      return ::grpc::Status(::grpc::INVALID_ARGUMENT, "Digital lines bytes per channel is 0");
    }

    // Calculate total array size needed (samples * channels * max_bytes_per_chan)
    const uInt32 array_size = number_of_samples_per_channel * num_channels * max_bytes_per_chan;
    std::vector<uInt8> read_array(array_size);

    std::vector<int64> t0_array, dt_array;
    int64* t0_ptr = nullptr;
    int64* dt_ptr = nullptr;
    uInt32 timing_array_size = 0;
    
    if (waveform_attribute_mode & WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_TIMING) {
      t0_array.resize(num_channels, 0);
      dt_array.resize(num_channels, 0);
      t0_ptr = t0_array.data();
      dt_ptr = dt_array.data();
      timing_array_size = num_channels;
    }

    std::unique_ptr<WaveformCallbackData> callback_data;
    DAQmxSetWfmAttrCallbackPtr callback_ptr = nullptr;
    
    for (uInt32 i = 0; i < num_channels; ++i) {
      response->add_waveforms();
    }
    
    if (waveform_attribute_mode & WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_EXTENDED_PROPERTIES) {
      callback_data = std::make_unique<WaveformCallbackData>(true); // true = digital waveforms
      callback_data->digital_waveforms.resize(num_channels);
      callback_ptr = SetWfmAttrCallback;
      
      for (uInt32 i = 0; i < num_channels; ++i) {
        callback_data->digital_waveforms[i] = response->mutable_waveforms(i);
      }
    }

    // Array to get actual bytes per channel
    std::vector<uInt32> bytes_per_chan_array(num_channels);
    
    int32 samples_per_chan_read = 0;
    int32 num_bytes_per_samp = 0;
    status = library_->InternalReadDigitalWaveform(
        task,
        number_of_samples_per_channel,
        timeout,
        false, // fillMode: false = GROUP_BY_SCAN_NUMBER (interleaved)
        t0_ptr,
        dt_ptr,
        timing_array_size,
        callback_ptr,
        callback_data.get(),
        read_array.data(),
        array_size,
        &samples_per_chan_read,
        &num_bytes_per_samp,
        bytes_per_chan_array.data(),
        num_channels,
        nullptr
    );

    if (!status_ok(status)) {
      return ConvertApiErrorStatusForTaskHandle(context, status, task);
    }

    // Extract data for each channel
    for (uInt32 i = 0; i < num_channels; ++i) {
      auto* waveform = response->mutable_waveforms(i);
      
      const uInt32 bytes_per_chan = bytes_per_chan_array[i];
      waveform->set_signal_count(static_cast<int32>(bytes_per_chan));

      // Extract data for this channel
      // Data layout: samples_per_chan_read x num_channels x max_bytes_per_chan
      std::string y_data;
      y_data.reserve(samples_per_chan_read * bytes_per_chan);
      
      for (int32 sample = 0; sample < samples_per_chan_read; ++sample) {
        const uInt32 sample_offset = sample * num_channels * max_bytes_per_chan + i * max_bytes_per_chan;
        y_data.append(reinterpret_cast<const char*>(&read_array[sample_offset]), bytes_per_chan);
      }
      
      waveform->set_y_data(std::move(y_data));

      if (waveform_attribute_mode & WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_TIMING) {
        if (dt_array[i] == 0) {
          return ::grpc::Status(::grpc::FAILED_PRECONDITION, 
            "Timing information requested but not available. Task must be configured with sample clock timing (e.g., CfgSampClkTiming) to provide timing information.");
        }

        auto* t0 = waveform->mutable_t0();
        // Convert from 100ns ticks (DAQmx format) to PrecisionTimestamp
        // t0_array[i] contains 100ns ticks since Jan 1, 0001 (.NET DateTime epoch)
        const int64_t seconds = t0_array[i] / TICKS_PER_SECOND;
        const int64_t fractional_ticks = t0_array[i] % TICKS_PER_SECOND;
        
        t0->set_seconds(seconds);
        t0->set_fractional_seconds(fractional_ticks);

        // Set sample interval (dt) - convert 100ns ticks to seconds
        waveform->set_dt(static_cast<double>(dt_array[i]) * TICKS_TO_SECONDS);
      }
    }

    response->set_samps_per_chan_read(samples_per_chan_read);
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

}  // namespace nidaqmx_grpc
