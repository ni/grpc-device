#include <nidaqmx/nidaqmx_service.h>
#include <vector>
#include <memory>
#include <cstdint>
#include <cstring>
#include <server/converters.h>
#include "NIDAQmxInternalWaveform.h"

namespace nidaqmx_grpc {

using nidevice_grpc::converters::convert_to_grpc;
using nidevice_grpc::converters::convert_dot_net_ticks_to_precision_timestamp;
using nidevice_grpc::converters::DotNetTicksPerSecond;
using google::protobuf::RepeatedPtrField;
using ::ni::protobuf::types::DoubleAnalogWaveform;
using ::ni::protobuf::types::DigitalWaveform;

namespace {
using ::ni::protobuf::types::DigitalWaveform;

namespace {

// Returns true if it's safe to use outputs of a method with the given status.
inline bool status_ok(int32 status)
{
  return status >= 0;
}

// Encapsulates timing arrays and pointers for waveform operations
struct TimingData {
  std::vector<int64> t0_array;
  std::vector<int64> dt_array;
  int64* t0_ptr = nullptr;
  int64* dt_ptr = nullptr;
  uInt32 timing_array_size = 0;

  TimingData(uInt32 num_channels) {
    if (num_channels == 0) {
      return;
    }
    t0_array.resize(num_channels, 0);
    dt_array.resize(num_channels, 0);
    t0_ptr = t0_array.data();
    dt_ptr = dt_array.data();
    timing_array_size = num_channels;
  }
};

// Universal callback function for setting waveform attributes (both analog and digital)
template<typename WaveformCollectionType>
// Encapsulates timing arrays and pointers for waveform operations
struct TimingData {
  std::vector<int64> t0_array;
  std::vector<int64> dt_array;
  int64* t0_ptr = nullptr;
  int64* dt_ptr = nullptr;
  uInt32 timing_array_size = 0;

  TimingData(uInt32 num_channels) {
    if (num_channels == 0) {
      return;
    }
    t0_array.resize(num_channels, 0);
    dt_array.resize(num_channels, 0);
    t0_ptr = t0_array.data();
    dt_ptr = dt_array.data();
    timing_array_size = num_channels;
  }
};

// Universal callback function for setting waveform attributes (both analog and digital)
template<typename WaveformCollectionType>
int32 CVICALLBACK SetWfmAttrCallback(
    const uInt32 channel_index,
    const char attribute_name[],
    const int32 attribute_type,
    const void* value,
    const uInt32 value_size_in_bytes,
    void* callback_data)
{
  try {
    auto* waveforms = static_cast<WaveformCollectionType*>(callback_data);
    auto* waveforms = static_cast<WaveformCollectionType*>(callback_data);
    if (!waveforms || channel_index >= static_cast<uInt32>(waveforms->size())) {
      return -1;
    }

    auto* waveform = waveforms->Mutable(channel_index);
    if (!waveform) {
      return -1;
    }

    auto* attributes = waveform->mutable_attributes();
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
          std::string string_val;
          convert_to_grpc(std::string(str_val), &string_val);
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
  catch (const std::exception&) {
    return -1;
  }
}

template<typename RequestType>
int32 GetWaveformAttributeMode(const RequestType* request)
{
  switch (request->waveform_attribute_mode_enum_case()) {
    case RequestType::WaveformAttributeModeEnumCase::kWaveformAttributeMode: {
      return static_cast<int32>(request->waveform_attribute_mode());
    }
    case RequestType::WaveformAttributeModeEnumCase::kWaveformAttributeModeRaw: {
      return static_cast<int32>(request->waveform_attribute_mode_raw());
    }
    case RequestType::WaveformAttributeModeEnumCase::WAVEFORM_ATTRIBUTE_MODE_ENUM_NOT_SET: {
      return 0;
    }
  }
  return 0;
}

template<typename WaveformType>
void SetWaveformTiming(
    uInt32 channel_index,
    const TimingData& timing_data,
    WaveformType* waveform)
{
  auto* waveform_t0 = waveform->mutable_t0();
  convert_dot_net_ticks_to_precision_timestamp(timing_data.t0_array[channel_index], waveform_t0);
  waveform->set_dt(static_cast<double>(timing_data.dt_array[channel_index]) / DotNetTicksPerSecond);
}

} // anonymous namespace

template<typename RequestType>
int32 GetWaveformAttributeMode(const RequestType* request)
{
  switch (request->waveform_attribute_mode_enum_case()) {
    case RequestType::WaveformAttributeModeEnumCase::kWaveformAttributeMode: {
      return static_cast<int32>(request->waveform_attribute_mode());
    }
    case RequestType::WaveformAttributeModeEnumCase::kWaveformAttributeModeRaw: {
      return static_cast<int32>(request->waveform_attribute_mode_raw());
    }
    case RequestType::WaveformAttributeModeEnumCase::WAVEFORM_ATTRIBUTE_MODE_ENUM_NOT_SET: {
      return 0;
    }
  }
  return 0;
}

template<typename WaveformType>
void SetWaveformTiming(
    uInt32 channel_index,
    const TimingData& timing_data,
    WaveformType* waveform)
{
  auto* waveform_t0 = waveform->mutable_t0();
  convert_dot_net_ticks_to_precision_timestamp(timing_data.t0_array[channel_index], waveform_t0);
  waveform->set_dt(static_cast<double>(timing_data.dt_array[channel_index]) / DotNetTicksPerSecond);
}

} // anonymous namespace

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

    const auto number_of_samples_per_channel = request->num_samps_per_chan();
    const auto timeout = request->timeout();
    
    
    uInt32 num_channels = 0;
    auto status = library_->GetReadAttributeUInt32(task, ReadUInt32Attribute::READ_ATTRIBUTE_NUM_CHANS, &num_channels);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForTaskHandle(context, status, task);
    }

    if (num_channels == 0) {
      return ::grpc::Status(::grpc::INVALID_ARGUMENT, "No channels to read");
    }

    std::vector<std::vector<float64>> read_arrays(num_channels);
    std::vector<float64*> read_array_ptrs(num_channels);
    
    for (uInt32 i = 0; i < num_channels; ++i) {
      read_arrays[i].resize(number_of_samples_per_channel);
      read_array_ptrs[i] = read_arrays[i].data();
    }

    response->mutable_waveforms()->Reserve(num_channels);
    for (uInt32 i = 0; i < num_channels; ++i) {
      response->add_waveforms();
    }
    
    int32 waveform_attribute_mode = GetWaveformAttributeMode(request);
    const bool timing_enabled = (waveform_attribute_mode & WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_TIMING) != 0;
    const bool extended_properties_enabled = (waveform_attribute_mode & WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_EXTENDED_PROPERTIES) != 0;

    TimingData timing_data(timing_enabled ? num_channels : 0);

    DAQmxSetWfmAttrCallbackPtr callback_ptr = nullptr;
    if (extended_properties_enabled) {
      callback_ptr = &SetWfmAttrCallback<RepeatedPtrField<DoubleAnalogWaveform>>;
    int32 waveform_attribute_mode = GetWaveformAttributeMode(request);
    const bool timing_enabled = (waveform_attribute_mode & WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_TIMING) != 0;
    const bool extended_properties_enabled = (waveform_attribute_mode & WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_EXTENDED_PROPERTIES) != 0;

    TimingData timing_data(timing_enabled ? num_channels : 0);

    DAQmxSetWfmAttrCallbackPtr callback_ptr = nullptr;
    if (extended_properties_enabled) {
      callback_ptr = &SetWfmAttrCallback<RepeatedPtrField<DoubleAnalogWaveform>>;
    }

    int32 samples_per_chan_read = 0;
    status = library_->InternalReadAnalogWaveformPerChan(
        task,
        number_of_samples_per_channel,
        timeout,
        timing_data.t0_array.data(),
        timing_data.dt_array.data(),
        timing_data.timing_array_size,
        timing_data.t0_array.data(),
        timing_data.dt_array.data(),
        timing_data.timing_array_size,
        callback_ptr,
        response->mutable_waveforms(),
        read_array_ptrs.data(),
        num_channels,
        number_of_samples_per_channel,
        &samples_per_chan_read,
        nullptr
    );

    if (!status_ok(status)) {
      return ConvertApiErrorStatusForTaskHandle(context, status, task);
    }

    for (uInt32 channel = 0; channel < num_channels; ++channel) {
      auto* waveform = response->mutable_waveforms(channel);

      auto* y_data = waveform->mutable_y_data();
      y_data->Add(read_arrays[channel].data(), read_arrays[channel].data() + samples_per_chan_read);

      if (timing_enabled) {
        SetWaveformTiming(channel, timing_data, waveform);
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

    const auto number_of_samples_per_channel = request->num_samps_per_chan();
    const auto timeout = request->timeout();
    
    uInt32 num_channels = 0;
    auto status = library_->GetReadAttributeUInt32(task, ReadUInt32Attribute::READ_ATTRIBUTE_NUM_CHANS, &num_channels);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForTaskHandle(context, status, task);
    }

    if (num_channels == 0) {
      return ::grpc::Status(::grpc::INVALID_ARGUMENT, "No channels to read");
    }

    // Get the maximum number of lines per channel to calculate array size
    uInt32 max_bytes_per_chan = 0;
    status = library_->GetReadAttributeUInt32(task, ReadUInt32Attribute::READ_ATTRIBUTE_DIGITAL_LINES_BYTES_PER_CHAN, &max_bytes_per_chan);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForTaskHandle(context, status, task);
    }

    if (max_bytes_per_chan == 0) {
      return ::grpc::Status(::grpc::UNKNOWN, "Digital lines bytes per channel is 0");
    }

    // Calculate total array size needed (samples * channels * max_bytes_per_chan)
    const uInt32 array_size = number_of_samples_per_channel * num_channels * max_bytes_per_chan;
    std::vector<uInt8> read_array(array_size);

    response->mutable_waveforms()->Reserve(num_channels);
    for (uInt32 channel = 0; channel < num_channels; ++channel) {
      auto* waveform = response->mutable_waveforms(channel);

      auto* y_data = waveform->mutable_y_data();
      y_data->Add(read_arrays[channel].data(), read_arrays[channel].data() + samples_per_chan_read);

      if (timing_enabled) {
        SetWaveformTiming(channel, timing_data, waveform);
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

    const auto number_of_samples_per_channel = request->num_samps_per_chan();
    const auto timeout = request->timeout();
    
    uInt32 num_channels = 0;
    auto status = library_->GetReadAttributeUInt32(task, ReadUInt32Attribute::READ_ATTRIBUTE_NUM_CHANS, &num_channels);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForTaskHandle(context, status, task);
    }

    if (num_channels == 0) {
      return ::grpc::Status(::grpc::INVALID_ARGUMENT, "No channels to read");
    }

    // Get the maximum number of lines per channel to calculate array size
    uInt32 max_bytes_per_chan = 0;
    status = library_->GetReadAttributeUInt32(task, ReadUInt32Attribute::READ_ATTRIBUTE_DIGITAL_LINES_BYTES_PER_CHAN, &max_bytes_per_chan);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForTaskHandle(context, status, task);
    }

    if (max_bytes_per_chan == 0) {
      return ::grpc::Status(::grpc::UNKNOWN, "Digital lines bytes per channel is 0");
    }

    // Calculate total array size needed (samples * channels * max_bytes_per_chan)
    const uInt32 array_size = number_of_samples_per_channel * num_channels * max_bytes_per_chan;
    std::vector<uInt8> read_array(array_size);

    response->mutable_waveforms()->Reserve(num_channels);
    for (uInt32 i = 0; i < num_channels; ++i) {
      response->add_waveforms();
    }
    
    int32 waveform_attribute_mode = GetWaveformAttributeMode(request);
    const bool timing_enabled = (waveform_attribute_mode & WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_TIMING) != 0;
    const bool extended_properties_enabled = (waveform_attribute_mode & WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_EXTENDED_PROPERTIES) != 0;

    TimingData timing_data(timing_enabled ? num_channels : 0);

    DAQmxSetWfmAttrCallbackPtr callback_ptr = nullptr;
    if (extended_properties_enabled) {
      callback_ptr = &SetWfmAttrCallback<RepeatedPtrField<DigitalWaveform>>;
    }

    std::vector<uInt32> bytes_per_chan_array(num_channels);
    
    int32 samples_per_chan_read = 0;
    int32 num_bytes_per_samp = 0;
    status = library_->InternalReadDigitalWaveform(
        task,
        number_of_samples_per_channel,
        timeout,
        GROUP_BY_GROUP_BY_SCAN_NUMBER,
        timing_data.t0_array.data(),
        timing_data.dt_array.data(),
        timing_data.timing_array_size,
        callback_ptr,
        response->mutable_waveforms(),
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

    for (uInt32 channel = 0; channel < num_channels; ++channel) {
      auto* waveform = response->mutable_waveforms(channel);

      const uInt32 bytes_per_chan = bytes_per_chan_array[channel];
      waveform->set_signal_count(static_cast<int32>(bytes_per_chan));

      response->add_waveforms();
    }
    
    int32 waveform_attribute_mode = GetWaveformAttributeMode(request);
    const bool timing_enabled = (waveform_attribute_mode & WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_TIMING) != 0;
    const bool extended_properties_enabled = (waveform_attribute_mode & WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_EXTENDED_PROPERTIES) != 0;

    TimingData timing_data(timing_enabled ? num_channels : 0);

    DAQmxSetWfmAttrCallbackPtr callback_ptr = nullptr;
    if (extended_properties_enabled) {
      callback_ptr = &SetWfmAttrCallback<RepeatedPtrField<DigitalWaveform>>;
    }

    std::vector<uInt32> bytes_per_chan_array(num_channels);
    
    int32 samples_per_chan_read = 0;
    int32 num_bytes_per_samp = 0;
    status = library_->InternalReadDigitalWaveform(
        task,
        number_of_samples_per_channel,
        timeout,
        GROUP_BY_GROUP_BY_SCAN_NUMBER,
        timing_data.t0_array.data(),
        timing_data.dt_array.data(),
        timing_data.timing_array_size,
        callback_ptr,
        response->mutable_waveforms(),
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

    for (uInt32 channel = 0; channel < num_channels; ++channel) {
      auto* waveform = response->mutable_waveforms(channel);

      const uInt32 bytes_per_chan = bytes_per_chan_array[channel];
      waveform->set_signal_count(static_cast<int32>(bytes_per_chan));

      auto* y_data = waveform->mutable_y_data();
      y_data->reserve(samples_per_chan_read * bytes_per_chan);
      
      // Data layout: grouped by scan number (interleaved)
      // Sample 0: Channel 0 signals, Channel 1 signals, Channel 2 signals, ...
      // Sample 1: Channel 0 signals, Channel 1 signals, Channel 2 signals, ...
      // Within each channel's data in a sample, signals are sequential: Signal0, Signal1, Signal2, ...
      for (int32 sample = 0; sample < samples_per_chan_read; ++sample) {
        const uInt32 sample_start = sample * num_channels * max_bytes_per_chan;
        const uInt32 channel_offset = sample_start + channel * max_bytes_per_chan;
        y_data->append(reinterpret_cast<const char*>(&read_array[channel_offset]), bytes_per_chan);
      }

      if (timing_enabled) {
        SetWaveformTiming(channel, timing_data, waveform);
      y_data->reserve(samples_per_chan_read * bytes_per_chan);
      
      // Data layout: grouped by scan number (interleaved)
      // Sample 0: Channel 0 signals, Channel 1 signals, Channel 2 signals, ...
      // Sample 1: Channel 0 signals, Channel 1 signals, Channel 2 signals, ...
      // Within each channel's data in a sample, signals are sequential: Signal0, Signal1, Signal2, ...
      for (int32 sample = 0; sample < samples_per_chan_read; ++sample) {
        const uInt32 sample_start = sample * num_channels * max_bytes_per_chan;
        const uInt32 channel_offset = sample_start + channel * max_bytes_per_chan;
        y_data->append(reinterpret_cast<const char*>(&read_array[channel_offset]), bytes_per_chan);
      }

      if (timing_enabled) {
        SetWaveformTiming(channel, timing_data, waveform);
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

::grpc::Status NiDAQmxService::WriteDigitalWaveforms(::grpc::ServerContext* context, const WriteDigitalWaveformsRequest* request, WriteDigitalWaveformsResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto task_grpc_session = request->task();
    TaskHandle task = session_repository_->access_session(task_grpc_session.name());

    const auto number_of_samples_per_channel = request->num_samps_per_chan();
    const auto auto_start = request->auto_start();
    const auto timeout = request->timeout();
    const auto& waveforms = request->waveforms();
    
    uInt32 num_channels = 0;
    auto status = library_->GetWriteAttributeUInt32(task, WriteUInt32Attribute::WRITE_ATTRIBUTE_NUM_CHANS, &num_channels);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForTaskHandle(context, status, task);
    }

    if (num_channels == 0) {
      return ::grpc::Status(::grpc::INVALID_ARGUMENT, "No channels to write");
    }

    if (static_cast<uInt32>(waveforms.size()) != num_channels) {
      return ::grpc::Status(::grpc::INVALID_ARGUMENT, "Write cannot be performed, because the number of channels in the task does not match the number of waveforms provided");
    }

    uInt32 max_bytes_per_chan = 0;
    status = library_->GetWriteAttributeUInt32(task, WriteUInt32Attribute::WRITE_ATTRIBUTE_DIGITAL_LINES_BYTES_PER_CHAN, &max_bytes_per_chan);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForTaskHandle(context, status, task);
    }

    if (max_bytes_per_chan == 0) {
      return ::grpc::Status(::grpc::UNKNOWN, "Digital lines per channel is 0");
    }

    std::vector<uInt32> bytes_per_chan_array(num_channels);
    for (uInt32 channel = 0; channel < num_channels; ++channel) {
      const auto& waveform = waveforms[channel];
      const auto signal_count = waveform.signal_count();
      
      if (signal_count <= 0) {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "Signal count must be positive");
      }
      
      if (static_cast<uInt32>(signal_count) > max_bytes_per_chan) {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "Specified read or write operation failed, because the number of lines in the data does not match the number of lines in the channel");
      }
      
      const auto& y_data = waveform.y_data();
      const auto expected_data_size = number_of_samples_per_channel * signal_count;
      
      if (y_data.size() != expected_data_size) {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "Waveform data size does not match expected size");
      }
      
      bytes_per_chan_array[channel] = static_cast<uInt32>(signal_count);
    }

    const uInt32 array_size = number_of_samples_per_channel * num_channels * max_bytes_per_chan;
    std::vector<uInt8> write_array(array_size, 0);

    for (uInt32 channel = 0; channel < num_channels; ++channel) {
      const auto& waveform = waveforms[channel];
      const auto signal_count = waveform.signal_count();
      const auto& y_data = waveform.y_data();

      // Data layout: grouped by scan number (interleaved)
      // Sample 0: Channel 0 signals, Channel 1 signals, Channel 2 signals, ...
      // Sample 1: Channel 0 signals, Channel 1 signals, Channel 2 signals, ...
      // Within each channel's data in a sample, signals are sequential: Signal0, Signal1, Signal2, ...
      for (int32 sample = 0; sample < number_of_samples_per_channel; ++sample) {
        const uInt32 dest_index = sample * num_channels * max_bytes_per_chan + channel * max_bytes_per_chan;
        const uInt32 src_index = sample * signal_count;
        std::memcpy(&write_array[dest_index], &y_data[src_index], signal_count);
      }
    }

    int32 samples_per_chan_written = 0;
    status = library_->InternalWriteDigitalWaveform(
        task,
        number_of_samples_per_channel,
        auto_start,
        timeout,
        GROUP_BY_GROUP_BY_SCAN_NUMBER,
        write_array.data(),
        bytes_per_chan_array.data(),
        num_channels,
        &samples_per_chan_written,
        nullptr
    );

    if (!status_ok(status)) {
      return ConvertApiErrorStatusForTaskHandle(context, status, task);
    }

    response->set_samps_per_chan_written(samples_per_chan_written);
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

}  // namespace nidaqmx_grpc
