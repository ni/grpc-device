#include <nidaqmx/nidaqmx_service.h>
#include <vector>
#include <memory>
#include <cstdint>
#include <server/converters.h>
#include "NIDAQmxInternalWaveform.h"
#include "ni/protobuf/types/waveform.pb.h"

namespace nidaqmx_grpc {

using nidevice_grpc::converters::convert_to_grpc;
using nidevice_grpc::converters::convert_dot_net_daqmx_ticks_to_btf_precision_timestamp;
using nidevice_grpc::converters::DotNetTicksPerSecond;
using google::protobuf::RepeatedPtrField;
using ::ni::protobuf::types::DoubleAnalogWaveform;

// Returns true if it's safe to use outputs of a method with the given status.
inline bool status_ok(int32 status)
{
  return status >= 0;
}

// Universal callback function for setting waveform attributes (both analog and digital)
template<typename WaveformCollectionType>
int32 CVICALLBACK SetWfmAttrCallbackTemplated(
    const uInt32 channel_index,
    const char attribute_name[],
    const int32 attribute_type,
    const void* value,
    const uInt32 value_size_in_bytes,
    void* callback_data)
{
  try {
    auto* waveforms = static_cast<WaveformCollectionType*>(callback_data);
    if (!waveforms || channel_index >= static_cast<uInt32>(waveforms->size())) {
      return -1;
    }

    auto* waveform = waveforms->Mutable(channel_index);
    if (!waveform) {
      return -1;
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
    
    // Insert the attribute into the waveform's attributes map
    auto* attributes_map = waveform->mutable_attributes();
    (*attributes_map)[attribute_name] = std::move(attr_value);
    
    return 0;
  }
  catch (const std::exception&) {
    return -1;
  }
}

// Wrapper functions for each waveform type
int32 CVICALLBACK SetAnalogWfmAttrCallback(
    const uInt32 channel_index,
    const char attribute_name[],
    const int32 attribute_type,
    const void* value,
    const uInt32 value_size_in_bytes,
    void* callback_data)
{
  return SetWfmAttrCallbackTemplated<RepeatedPtrField<DoubleAnalogWaveform>>(
    channel_index, attribute_name, attribute_type, value, value_size_in_bytes, callback_data);
}

int32 CVICALLBACK SetDigitalWfmAttrCallback(
    const uInt32 channel_index,
    const char attribute_name[],
    const int32 attribute_type,
    const void* value,
    const uInt32 value_size_in_bytes,
    void* callback_data)
{
  return SetWfmAttrCallbackTemplated<RepeatedPtrField<::ni::protobuf::types::DigitalWaveform>>(
    channel_index, attribute_name, attribute_type, value, value_size_in_bytes, callback_data);
}

template<typename RequestType>
::grpc::Status ParseWaveformAttributeMode(const RequestType* request, int32& waveform_attribute_mode)
{
  switch (request->waveform_attribute_mode_enum_case()) {
    case RequestType::WaveformAttributeModeEnumCase::kWaveformAttributeMode: {
      waveform_attribute_mode = static_cast<int32>(request->waveform_attribute_mode());
      break;
    }
    case RequestType::WaveformAttributeModeEnumCase::kWaveformAttributeModeRaw: {
      waveform_attribute_mode = static_cast<int32>(request->waveform_attribute_mode_raw());
      break;
    }
    case RequestType::WaveformAttributeModeEnumCase::WAVEFORM_ATTRIBUTE_MODE_ENUM_NOT_SET: {
      return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for waveform_attribute_mode was not specified or out of range");
    }
  }
  return ::grpc::Status::OK;
}

void SetupTimingArrays(int32 waveform_attribute_mode, uInt32 num_channels,
                      std::vector<int64>& t0_array, std::vector<int64>& dt_array,
                      int64*& t0_ptr, int64*& dt_ptr, uInt32& timing_array_size)
{
  if (waveform_attribute_mode & WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_TIMING) {
    t0_array.resize(num_channels, 0);
    dt_array.resize(num_channels, 0);
    t0_ptr = t0_array.data();
    dt_ptr = dt_array.data();
    timing_array_size = num_channels;
  }
}

// void SetupAnalogCallbackData(int32 waveform_attribute_mode, uInt32 num_channels,
//                             std::unique_ptr<WaveformCallbackData>& callback_data,
//                             DAQmxSetWfmAttrCallbackPtr& callback_ptr,
//                             ReadAnalogWaveformsResponse* response)
// {
//   if (waveform_attribute_mode & WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_EXTENDED_PROPERTIES) {
//     callback_data = std::make_unique<WaveformCallbackData>(false);
//     callback_data->analog_waveforms.resize(num_channels);
//     callback_ptr = SetWfmAttrCallback;
    
//     for (uInt32 i = 0; i < num_channels; ++i) {
//       callback_data->analog_waveforms[i] = response->mutable_waveforms(i);
//     }
//   }
// }

// void SetupDigitalCallbackData(int32 waveform_attribute_mode, uInt32 num_channels,
//                              std::unique_ptr<WaveformCallbackData>& callback_data,
//                              DAQmxSetWfmAttrCallbackPtr& callback_ptr,
//                              ReadDigitalWaveformsResponse* response)
// {
//   if (waveform_attribute_mode & WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_EXTENDED_PROPERTIES) {
//     callback_data = std::make_unique<WaveformCallbackData>(true);
//     callback_data->digital_waveforms.resize(num_channels);
//     callback_ptr = SetWfmAttrCallback;
    
//     for (uInt32 i = 0; i < num_channels; ++i) {
//       callback_data->digital_waveforms[i] = response->mutable_waveforms(i);
//     }
//   }
// }

template<typename WaveformType>
::grpc::Status ProcessWaveformTiming(int32 waveform_attribute_mode, uInt32 channel_index,
                                    const std::vector<int64>& t0_array, const std::vector<int64>& dt_array,
                                    WaveformType* waveform)
{
  if (waveform_attribute_mode & WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_TIMING) {
    auto* waveform_t0 = waveform->mutable_t0();
    convert_ticks_to_btf_precision_timestamp(t0_array[channel_index], waveform_t0);
    waveform->set_dt(static_cast<double>(dt_array[channel_index]) * SecondsPerTick);
  }
  return ::grpc::Status::OK;
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

    const auto number_of_samples_per_channel = request->num_samps_per_chan();
    const auto timeout = request->timeout();
    
    int32 waveform_attribute_mode;
    auto parse_status = ParseWaveformAttributeMode(request, waveform_attribute_mode);
    if (!parse_status.ok()) {
      return parse_status;
    }

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

    std::vector<int64> t0_array, dt_array;
    int64* t0_ptr = nullptr;
    int64* dt_ptr = nullptr;
    uInt32 timing_array_size = 0;
    
    SetupTimingArrays(waveform_attribute_mode, num_channels, t0_array, dt_array, t0_ptr, dt_ptr, timing_array_size);

    DAQmxSetWfmAttrCallbackPtr callback_ptr = nullptr;

    response->mutable_waveforms()->Reserve(num_channels);
    for (uInt32 i = 0; i < num_channels; ++i) {
      response->add_waveforms();
    }
    
    if (waveform_attribute_mode & WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_EXTENDED_PROPERTIES) {
      callback_ptr = SetAnalogWfmAttrCallback;
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

    for (uInt32 i = 0; i < num_channels; ++i) {
      auto* waveform = response->mutable_waveforms(i);
      
      auto* y_data = waveform->mutable_y_data();
      y_data->Add(read_arrays[i].data(), read_arrays[i].data() + samples_per_chan_read);

      if (waveform_attribute_mode & WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_TIMING) {
        auto* waveform_t0 = waveform->mutable_t0();
        convert_dot_net_daqmx_ticks_to_btf_precision_timestamp(t0_array[i], waveform_t0);
        waveform->set_dt(static_cast<double>(dt_array[i]) / DotNetTicksPerSecond);
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
    
    int32 waveform_attribute_mode;
    auto parse_status = ParseWaveformAttributeMode(request, waveform_attribute_mode);
    if (!parse_status.ok()) {
      return parse_status;
    }

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
      return ::grpc::Status(::grpc::INVALID_ARGUMENT, "Digital lines bytes per channel is 0");
    }

    // Calculate total array size needed (samples * channels * max_bytes_per_chan)
    const uInt32 array_size = number_of_samples_per_channel * num_channels * max_bytes_per_chan;
    std::vector<uInt8> read_array(array_size);

    std::vector<int64> t0_array, dt_array;
    int64* t0_ptr = nullptr;
    int64* dt_ptr = nullptr;
    uInt32 timing_array_size = 0;
    
    SetupTimingArrays(waveform_attribute_mode, num_channels, t0_array, dt_array, t0_ptr, dt_ptr, timing_array_size);

    DAQmxSetWfmAttrCallbackPtr callback_ptr = nullptr;
    
    response->mutable_waveforms()->Reserve(num_channels);
    for (uInt32 i = 0; i < num_channels; ++i) {
      response->add_waveforms();
    }
    
    if (waveform_attribute_mode & WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_EXTENDED_PROPERTIES) {
      callback_ptr = SetDigitalWfmAttrCallback;
    }

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

    for (uInt32 i = 0; i < num_channels; ++i) {
      auto* waveform = response->mutable_waveforms(i);
      
      const uInt32 bytes_per_chan = bytes_per_chan_array[i];
      waveform->set_signal_count(static_cast<int32>(bytes_per_chan));

      // Data layout: all samples for each channel are grouped together
      // Channel 0: all its samples, Channel 1: all its samples, etc.
      // Within each channel, samples are sequential: Sample0, Sample1, Sample2, ...
      // Within each sample, signals are sequential: Signal0, Signal1, Signal2, ...
      std::string y_data;
      y_data.reserve(samples_per_chan_read * bytes_per_chan);
      
      // Calculate offset to start of this channel's data
      const uInt32 channel_start = i * samples_per_chan_read * max_bytes_per_chan;
      
      for (int32 sample = 0; sample < samples_per_chan_read; ++sample) {
        // Within this channel, find the start of this sample
        const uInt32 sample_start = channel_start + sample * max_bytes_per_chan;
        
        // Copy all signals for this sample (up to bytes_per_chan)
        for (uInt32 signal = 0; signal < bytes_per_chan; ++signal) {
          const uInt32 offset = sample_start + signal;
          y_data.append(reinterpret_cast<const char*>(&read_array[offset]), 1);
        }
      }
      
      waveform->set_y_data(std::move(y_data));

      auto timing_status = ProcessWaveformTiming(waveform_attribute_mode, i, t0_array, dt_array, waveform);
      if (!timing_status.ok()) {
        return timing_status;
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
