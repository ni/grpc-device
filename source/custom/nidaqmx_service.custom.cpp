#include <nidaqmx/nidaqmx_service.h>
#include <vector>
#include <memory>

namespace nidaqmx_grpc {

// Returns true if it's safe to use outputs of a method with the given status.
inline bool status_ok(int32 status)
{
  return status >= 0;
}

// Callback data structure to pass waveform pointers to the callback
struct WaveformCallbackData {
  std::vector<::ni::protobuf::types::DoubleAnalogWaveform*> waveforms;
};

// Callback function for setting waveform attributes
int32 CVICALLBACK SetWfmAttrCallback(
    uInt32 channel_index,
    const char attribute_name[],
    int32 attribute_type,
    const void* value,
    uInt32 value_size_in_bytes,
    void* callback_data)
{
  try {
    auto* data = static_cast<WaveformCallbackData*>(callback_data);
    if (!data || channel_index >= data->waveforms.size()) {
      return -1; // Invalid data or index
    }

    auto* waveform = data->waveforms[channel_index];
    if (!waveform) {
      return -1; // Invalid waveform pointer
    }

    // Get the attributes map for this waveform
    auto* attributes = waveform->mutable_attributes();
    
    // Create the attribute value based on type
    ::ni::protobuf::types::WaveformAttributeValue attr_value;
    
    switch (attribute_type) {
      case 1: // DAQmx_Val_WfmAttrType_Bool32
        if (value_size_in_bytes == 4) {
          bool bool_val = (*static_cast<const int32*>(value)) != 0;
          attr_value.set_bool_value(bool_val);
        } else {
          return -1; // Invalid size
        }
        break;
        
      case 2: // DAQmx_Val_WfmAttrType_Float64
        if (value_size_in_bytes == 8) {
          double double_val = *static_cast<const double*>(value);
          attr_value.set_double_value(double_val);
        } else {
          return -1; // Invalid size
        }
        break;
        
      case 3: // DAQmx_Val_WfmAttrType_Int32
        if (value_size_in_bytes == 4) {
          int32 int_val = *static_cast<const int32*>(value);
          attr_value.set_integer_value(int_val);
        } else {
          return -1; // Invalid size
        }
        break;
        
      case 4: // DAQmx_Val_WfmAttrType_String
        if (value_size_in_bytes > 0) {
          // Ensure null-terminated string
          const char* str_val = static_cast<const char*>(value);
          std::string string_val(str_val, value_size_in_bytes - 1); // Exclude null terminator
          attr_value.set_string_value(string_val);
        } else {
          return -1; // Invalid size
        }
        break;
        
      default:
        return -1; // Unsupported attribute type
    }
    
    // Set the attribute in the waveform
    (*attributes)[std::string(attribute_name)] = attr_value;
    
    return 0; // Success
  }
  catch (...) {
    return -1; // Error occurred
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

    auto number_of_samples_per_channel = request->number_of_samples_per_channel();
    auto timeout = request->timeout();
    
    // Get waveform attribute mode
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

    // Get the number of channels
    uInt32 num_channels = 0;
    auto status = library_->GetReadAttributeUInt32(task, 8571 /* READ_ATTRIBUTE_NUM_CHANS */, &num_channels);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForTaskHandle(context, status, task);
    }

    if (num_channels == 0) {
      return ::grpc::Status(::grpc::INVALID_ARGUMENT, "No channels found in task");
    }

    // Prepare arrays for reading data
    std::vector<std::vector<float64>> read_arrays(num_channels);
    std::vector<float64*> read_array_ptrs(num_channels);
    
    // Allocate memory for each channel
    for (uInt32 i = 0; i < num_channels; ++i) {
      read_arrays[i].resize(number_of_samples_per_channel);
      read_array_ptrs[i] = read_arrays[i].data();
    }

    // Prepare timing arrays if timing is requested
    std::vector<int64> t0_array, dt_array;
    int64* t0_ptr = nullptr;
    int64* dt_ptr = nullptr;
    uInt32 timing_array_size = 0;
    
    if (waveform_attribute_mode & 1 /* WAVEFORM_ATTRIBUTE_MODE_TIMING */) {
      t0_array.resize(num_channels, 0);
      dt_array.resize(num_channels, 0);
      t0_ptr = t0_array.data();
      dt_ptr = dt_array.data();
      timing_array_size = num_channels;
    }

    // Prepare callback data for extended properties if requested
    std::unique_ptr<WaveformCallbackData> callback_data;
    DAQmxSetWfmAttrCallbackPtr callback_ptr = nullptr;
    
    if (waveform_attribute_mode & 2 /* WAVEFORM_ATTRIBUTE_MODE_EXTENDED_PROPERTIES */) {
      callback_data = std::make_unique<WaveformCallbackData>();
      callback_data->waveforms.resize(num_channels);
      callback_ptr = SetWfmAttrCallback;
      
      // Pre-populate the waveforms in the response so we can pass pointers to the callback
      for (uInt32 i = 0; i < num_channels; ++i) {
        callback_data->waveforms[i] = response->add_waveforms();
      }
    }

    // Read the waveforms
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
        nullptr   // reserved
    );

    if (!status_ok(status)) {
      return ConvertApiErrorStatusForTaskHandle(context, status, task);
    }

    // Populate the response waveforms
    for (uInt32 i = 0; i < num_channels; ++i) {
      ::ni::protobuf::types::DoubleAnalogWaveform* waveform;
      
      if (waveform_attribute_mode & 2 /* WAVEFORM_ATTRIBUTE_MODE_EXTENDED_PROPERTIES */) {
        // Waveforms were already created for the callback
        waveform = callback_data->waveforms[i];
      } else {
        // Create new waveforms
        waveform = response->add_waveforms();
      }
      
      // Set the actual samples read
      auto* y_data = waveform->mutable_y_data();
      y_data->Reserve(samples_per_chan_read);
      for (int32 j = 0; j < samples_per_chan_read; ++j) {
        y_data->Add(read_arrays[i][j]);
      }

      // Set timing information if requested
      if (waveform_attribute_mode & 1 /* WAVEFORM_ATTRIBUTE_MODE_TIMING */) {
        // Check if DAQmx provided timing information
        if (dt_array[i] == 0) {
          // No timing information available - task likely not configured with sample clock timing
          return ::grpc::Status(::grpc::FAILED_PRECONDITION, 
            "Timing information requested but not available. Task must be configured with sample clock timing (e.g., CfgSampClkTiming) to provide timing information.");
        }

        auto* t0 = waveform->mutable_t0();
        // Convert from 100ns ticks (DAQmx format) to PrecisionTimestamp
        // t0_array[i] contains 100ns ticks since Jan 1, 0001
        // PrecisionTimestamp expects seconds and fractional seconds
        const int64 ticks_per_second = 10000000; // 100ns ticks per second
        int64 seconds = t0_array[i] / ticks_per_second;
        int64 fractional_ticks = t0_array[i] % ticks_per_second;
        double fractional_seconds = static_cast<double>(fractional_ticks) / ticks_per_second;
        
        t0->set_seconds(seconds);
        t0->set_fractional_seconds(fractional_seconds);

        // Set sample interval (dt) - convert 100ns ticks to seconds
        waveform->set_dt(static_cast<double>(dt_array[i]) * 1e-7); // 100ns = 1e-7 seconds
      }
    }

    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

}  // namespace nidaqmx_grpc
