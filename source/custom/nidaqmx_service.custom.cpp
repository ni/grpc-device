#include <nidaqmx.grpc.pb.h>
#include <nidaqmx/nidaqmx_service.h>
#include <nidaqmx/nidaqmx_library_interface.h>
#include <server/data_moniker_service.h>

namespace nidaqmx_grpc {

::grpc::Status NiDAQmxService::ConvertApiErrorStatusForTaskHandle(::grpc::ServerContextBase* context, int32_t status, TaskHandle task)
{
  // This implementation assumes this method is always called on the same thread where the error occurred.
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library_->GetExtendedErrorInfo(&description[0], nidevice_grpc::kMaxGrpcErrorDescriptionSize);
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
struct MonikerWriteDAQmxData {
 public:
  TaskHandle task;
  int32 numsamples;
  int32 num_samps_per_chan;
  bool auto_start;
  double timeout;
  int32 data_layout;
  NiDAQmxService::LibrarySharedPtr library;
  int32 index;
};

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status MonikerWriteAnalogF64(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
  //std::cout << "Begin MonikerWriteAnalogF64" << std::endl;
  MonikerWriteDAQmxData* writeData = (MonikerWriteDAQmxData*)data;

  int32 samps_per_chan_written;

  auto channelData = google::protobuf::Arena::CreateMessage<nidaqmx_grpc::ChannelData>(&arena);
  packedData.UnpackTo(channelData);  

  const double* values = channelData->data().data();
  auto status = writeData->library->WriteAnalogF64(writeData->task, writeData->num_samps_per_chan, writeData->auto_start, writeData->timeout, writeData->data_layout, values, &samps_per_chan_written, nullptr);
  if (status < 0) {
    std ::cout << "DAQmxWriteAnalogF64 error: " << status << std::endl;
    std ::cout << "TaskName " << writeData->task << std::endl;
    std ::cout << "Values " << values[0] << " " << channelData->data_size() << std::endl;
    std ::cout << "Index " << writeData->index << std::endl;
  }
  writeData->index += 1;

  //std::cout << "End MonikerWriteAnalogF64" << std::endl;
  return ::grpc::Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
struct MonikerReadDAQmxData {
 public:
  TaskHandle task;
  int32 numSamples;
  int32 num_samps_per_chan;
  double timeout;
  uInt32 array_size_in_samps;
  nidaqmx_grpc::ChannelData channelData;
  int32 fill_mode;
  NiDAQmxService::LibrarySharedPtr library;
  int index;
};

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status MonikerReadAnalogF64(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
  //std::cout << "Begin MonikerReadAnalogF64" << std::endl;
  MonikerReadDAQmxData* readData = (MonikerReadDAQmxData*)data;
  // calling into driver and setting response

  int32 numRead;
  auto status = readData->library->ReadAnalogF64(readData->task, readData->num_samps_per_chan, readData->timeout, readData->fill_mode, readData->channelData.mutable_data()->mutable_data(), readData->array_size_in_samps, &numRead, nullptr);
  if (status < 0) {
    std::cout << "DAQmxReadAnalogF64 error: " << status << std::endl;
    std::cout << "TaskName " << readData->task << std::endl;
    std::cout << "Values " << readData->channelData.data()[0] << " " << readData->channelData.data_size() << std::endl;
    std::cout << "Index " << readData->index << std::endl;
  }
  readData->index += 1;

  packedData.PackFrom(readData->channelData);
  //std::cout << "End MonikerReadAnalogF64" << std::endl;
  return ::grpc::Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
struct MonikerWaitForNextSampleClockData {
 public:
  TaskHandle task;
  double timeout;
  bool32 is_late; //?
  nidaqmx_grpc::ChannelData channelData;
  NiDAQmxService::LibrarySharedPtr library;
};

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status MonikerWaitForNextSampleClock(void* data, google::protobuf::Arena& arena, google::protobuf::Any& packedData)
{
  MonikerWaitForNextSampleClockData* waitData = (MonikerWaitForNextSampleClockData*)data;
  // calling into driver and setting response

  bool32 is_late{};
  auto status = waitData->library->WaitForNextSampleClock(waitData->task, waitData->timeout, &is_late);
  if (status < 0) {
    std::cout << "WaitForNextSampleClock error: " << status << std::endl;
  }
  nidaqmx_grpc::SampleClockData message;
  message.set_is_late(is_late);
  packedData.PackFrom(message);
  return ::grpc::Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiDAQmxService::BeginWriteAnalogF64(::grpc::ServerContext* context, const BeginWriteAnalogF64Request* request, BeginWriteAnalogF64Response* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    MonikerWriteDAQmxData* writeData = new MonikerWriteDAQmxData();
    auto task_grpc_session = request->task();
    writeData->task = session_repository_->access_session(task_grpc_session.name());
    writeData->num_samps_per_chan = request->num_samps_per_chan();
    writeData->auto_start = request->auto_start();
    writeData->timeout = request->timeout();
    writeData->index = 0;

    switch (request->data_layout_enum_case()) {
      case nidaqmx_grpc::BeginWriteAnalogF64Request::DataLayoutEnumCase::kDataLayout: {
        writeData->data_layout = static_cast<int32>(request->data_layout());
        break;
      }
      case nidaqmx_grpc::BeginWriteAnalogF64Request::DataLayoutEnumCase::kDataLayoutRaw: {
        writeData->data_layout = static_cast<int32>(request->data_layout_raw());
        break;
      }
      case nidaqmx_grpc::BeginWriteAnalogF64Request::DataLayoutEnumCase::DATA_LAYOUT_ENUM_NOT_SET: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for data_layout was not specified or out of range");
        break;
      }
    }
    writeData->library = library_;

    ni::data_monikers::Moniker* writeMoniker = new ni::data_monikers::Moniker();
    ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWriteAnalogF64", writeData, *writeMoniker);
    response->set_allocated_moniker(writeMoniker);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}


//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
::grpc::Status NiDAQmxService::BeginReadAnalogF64(::grpc::ServerContext* context, const BeginReadAnalogF64Request* request, BeginReadAnalogF64Response* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    MonikerReadDAQmxData* readData = new MonikerReadDAQmxData();
    auto task_grpc_session = request->task();
    readData->task = session_repository_->access_session(task_grpc_session.name());
    readData->array_size_in_samps = request->array_size_in_samps();
    readData->num_samps_per_chan = request->num_samps_per_chan();
    readData->timeout = request->timeout();
    readData->channelData.mutable_data()->Reserve(readData->array_size_in_samps);
    readData->channelData.mutable_data()->Resize(readData->array_size_in_samps, 0.0);
    readData->fill_mode;
    readData->index = 0;
    switch (request->fill_mode_enum_case()) {
      case nidaqmx_grpc::BeginReadAnalogF64Request::FillModeEnumCase::kFillMode: {
        readData->fill_mode = static_cast<int32>(request->fill_mode());
        break;
      }
      case nidaqmx_grpc::BeginReadAnalogF64Request::FillModeEnumCase::kFillModeRaw: {
        readData->fill_mode = static_cast<int32>(request->fill_mode_raw());
        break;
      }
      case nidaqmx_grpc::BeginReadAnalogF64Request::FillModeEnumCase::FILL_MODE_ENUM_NOT_SET: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for fill_mode was not specified or out of range");
        break;
      }
    }
    readData->library = library_;

    ni::data_monikers::Moniker* readMoniker = new ni::data_monikers::Moniker();
    ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerReadAnalogF64", readData, *readMoniker);
    response->set_allocated_moniker(readMoniker);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiDAQmxService::BeginWaitForNextSampleClock(::grpc::ServerContext* context, const BeginWaitForNextSampleClockRequest* request, BeginWaitForNextSampleClockResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    MonikerWaitForNextSampleClockData* waitData = new MonikerWaitForNextSampleClockData();
    auto task_grpc_session = request->task();
    waitData->task = session_repository_->access_session(task_grpc_session.name());
    waitData->timeout = request->timeout();
    waitData->library = library_;

    ni::data_monikers::Moniker* waitMoniker = new ni::data_monikers::Moniker();
    ni::data_monikers::DataMonikerService::RegisterMonikerInstance("MonikerWaitForNextSampleClock", waitData, *waitMoniker);
    response->set_allocated_moniker(waitMoniker);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

void RegisterMonikers()
{
    ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerReadAnalogF64", MonikerReadAnalogF64);
    ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWaitForNextSampleClock", MonikerWaitForNextSampleClock);
    ni::data_monikers::DataMonikerService::RegisterMonikerEndpoint("MonikerWriteAnalogF64", MonikerWriteAnalogF64);
}

}  // namespace nidaqmx_grpc
