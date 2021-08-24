#include <nidaqmx/nidaqmx_service.h>

namespace nidaqmx_grpc {
//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiDAQmxService::ReadAnalogF64(::grpc::ServerContext* context, const ReadAnalogF64Request* request, ReadAnalogF64Response* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto task_grpc_session = request->task();
    TaskHandle task = session_repository_->access_session(task_grpc_session.id(), task_grpc_session.name());
    int32 num_samps_per_chan = request->num_samps_per_chan();
    float64 timeout = request->timeout();
    int32 fill_mode;
    switch (request->fill_mode_enum_case()) {
      case nidaqmx_grpc::ReadAnalogF64Request::FillModeEnumCase::kFillMode: {
        fill_mode = static_cast<int32>(request->fill_mode());
        break;
      }
      case nidaqmx_grpc::ReadAnalogF64Request::FillModeEnumCase::kFillModeRaw: {
        fill_mode = static_cast<int32>(request->fill_mode_raw());
        break;
      }
      case nidaqmx_grpc::ReadAnalogF64Request::FillModeEnumCase::FILL_MODE_ENUM_NOT_SET: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for fill_mode was not specified or out of range");
        break;
      }
    }

    uInt32 array_size_in_samps = request->array_size_in_samps();
    if (array_size_in_samps == 0) {
      // get number of channels
      uInt32 number_of_channels;
      auto read_status = library_->GetReadAttributeUInt32(task, READ_ATTRIBUTE_NUM_CHANS, &number_of_channels, 0);
      if (read_status != 0) {
        response->set_status(read_status);
        return ::grpc::Status::OK;
      }
      // get number of samples
      if (num_samps_per_chan == 0) {
        // TODO - the Python API uses a sentinel value to indicate acquire only one sample
        // and return a 1D array instead of a 2D array. Since that doesn't make a difference here,
        // we could use 0 (i.e. unset) to mean something different...
        num_samps_per_chan = 1;
      }
      else if (num_samps_per_chan == -1) {
        // READ_ALL_AVAILABLE
        int32 acquisition_type;
        auto acquisition_type_status = library_->GetTimingAttributeInt32(task, TIMING_ATTRIBUTE_SAMP_QUANT_SAMP_MODE, &acquisition_type, 0);
        if (acquisition_type_status != 0) {
          response->set_status(acquisition_type_status);
          return ::grpc::Status::OK;
        }
        bool is_finite_read_all_available_samples = false;
        if (acquisition_type == DAQmx_Val_FiniteSamps) {
          // check read_all_avail_samp
          bool32 read_all_available_samples;
          auto available_status = library_->GetReadAttributeBool(task, READ_ATTRIBUTE_READ_ALL_AVAIL_SAMP, &read_all_available_samples, 0);
          if (acquisition_type_status != 0) {
            response->set_status(acquisition_type_status);
            return ::grpc::Status::OK;
          }
          is_finite_read_all_available_samples = read_all_available_samples != 0;
        }
        if (is_finite_read_all_available_samples) {
          uInt64 read_samples_per_channel;
          // TODO - this is actually a timing attribute, but the attribute metadata is wrong so there's
          // no way to read a Timing UInt64 property.
          // See GitHub issue #324
          auto samples_per_channel_status = library_->GetReadAttributeUInt64(task, TIMING_ATTRIBUTE_SAMP_QUANT_SAMP_PER_CHAN, &read_samples_per_channel, 0);
          if (samples_per_channel_status != 0) {
            response->set_status(samples_per_channel_status);
            return ::grpc::Status::OK;
          }
          num_samps_per_chan = static_cast<int32>(read_samples_per_channel);
        }
        else {
          uInt32 samples_per_channel;
          auto samples_per_channel_status = library_->GetReadAttributeUInt32(task, READ_ATTRIBUTE_AVAIL_SAMP_PER_CHAN, &samples_per_channel, 0);
          if (samples_per_channel_status != 0) {
            response->set_status(samples_per_channel_status);
            return ::grpc::Status::OK;
          }
          num_samps_per_chan = static_cast<int32>(samples_per_channel);
        }
      }
      array_size_in_samps = number_of_channels * num_samps_per_chan;
    }
    auto reserved = nullptr;
    response->mutable_read_array()->Resize(array_size_in_samps, 0);
    float64* read_array = response->mutable_read_array()->mutable_data();
    int32 samps_per_chan_read{};
    auto status = library_->ReadAnalogF64(task, num_samps_per_chan, timeout, fill_mode, read_array, array_size_in_samps, &samps_per_chan_read, reserved);
    response->set_status(status);
    if (status == 0) {
      response->set_samps_per_chan_read(samps_per_chan_read);
    }
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}
}  // namespace nidaqmx_grpc
