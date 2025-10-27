#include <nidaqmx/nidaqmx_service.h>
#include <vector>
#include <memory>
#include <cstdint>
#include <server/converters.h>
#include "NIDAQmxInternalWaveform.h"

namespace nidaqmx_grpc {

using nidevice_grpc::converters::convert_to_grpc;
using nidevice_grpc::converters::convert_dot_net_daqmx_ticks_to_btf_precision_timestamp;
using nidevice_grpc::converters::SecondsPerDotNetTick;
using google::protobuf::RepeatedPtrField;
using ::ni::protobuf::types::DoubleAnalogWaveform;

// Returns true if it's safe to use outputs of a method with the given status.
inline bool status_ok(int32 status)
{
  return status >= 0;
}

// Callback function for setting waveform attributes
int32 CVICALLBACK SetWfmAttrCallback(
    const uInt32 channel_index,
    const char attribute_name[],
    const int32 attribute_type,
    const void* value,
    const uInt32 value_size_in_bytes,
    void* callback_data)
{
  try {
    auto* waveforms = static_cast<RepeatedPtrField<DoubleAnalogWaveform>*>(callback_data);
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
    
    if (waveform_attribute_mode & WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_TIMING) {
      t0_array.resize(num_channels, 0);
      dt_array.resize(num_channels, 0);
      t0_ptr = t0_array.data();
      dt_ptr = dt_array.data();
      timing_array_size = num_channels;
    }

    DAQmxSetWfmAttrCallbackPtr callback_ptr = nullptr;

    response->mutable_waveforms()->Reserve(num_channels);
    for (uInt32 i = 0; i < num_channels; ++i) {
      response->add_waveforms();
    }
    
    if (waveform_attribute_mode & WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_EXTENDED_PROPERTIES) {
      callback_ptr = SetWfmAttrCallback;
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
      y_data->Reserve(samples_per_chan_read);
      y_data->Add(read_arrays[i].data(), read_arrays[i].data() + samples_per_chan_read);

      if (waveform_attribute_mode & WaveformAttributeMode::WAVEFORM_ATTRIBUTE_MODE_TIMING) {
        auto* waveform_t0 = waveform->mutable_t0();
        convert_dot_net_daqmx_ticks_to_btf_precision_timestamp(t0_array[i], waveform_t0);
        waveform->set_dt(static_cast<double>(dt_array[i]) * SecondsPerDotNetTick);
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
