//---------------------------------------------------------------------
//---------------------------------------------------------------------
#include "data_moniker_service.h"
#include "moniker_stream_processor.h"

#include <sideband_data.h>
#include <sideband_grpc.h>
#include <sideband_internal.h>

#include <thread>
#include <tuple>
#ifndef _WIN32
  #include <sys/syscall.h>
#endif

#include <fstream>
#include <sstream>

//---------------------------------------------------------------------
//---------------------------------------------------------------------
using google::protobuf::Arena;
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReaderWriter;
using grpc::ServerWriter;
using grpc::Status;
using ni::data_monikers::BeginMonikerSidebandStreamRequest;
using ni::data_monikers::BeginMonikerSidebandStreamResponse;
using ni::data_monikers::DataMoniker;
using ni::data_monikers::MonikerList;
using ni::data_monikers::MonikerReadResponse;
using ni::data_monikers::MonikerWriteRequest;
using ni::data_monikers::SidebandReadResponse;
using ni::data_monikers::SidebandWriteRequest;
using ni::data_monikers::StreamWriteResponse;
using std::string;

static void SysFsWrite(const std::string& fileName, const std::string& value)
{
  std::ofstream fout;
  fout.open(fileName);
  fout << value;
  fout.close();
}

namespace ni::data_monikers {

static MonikerStreamProcessor s_StreamProcessor;

void configure_moniker_stream_processor(const MonikerStreamProcessor& stream_processor)
{
  s_StreamProcessor = stream_processor;
}

bool is_sideband_streaming_enabled(const nidevice_grpc::FeatureToggles& feature_toggles)
{
  return feature_toggles.is_feature_enabled("sideband_streaming", nidevice_grpc::FeatureToggles::CodeReadiness::kNextRelease);
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
DataMonikerService* DataMonikerService::s_Server;

//---------------------------------------------------------------------
//---------------------------------------------------------------------
DataMonikerService::DataMonikerService()
{
  s_Server = this;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
void DataMonikerService::RegisterMonikerEndpoint(string endpointName, MonikerEndpointPtr endpoint)
{
  s_Server->_endpoints.emplace(endpointName, endpoint);
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
void DataMonikerService::RegisterMonikerInstance(string endpointName, void* instanceData, Moniker& moniker)
{
  moniker.set_data_instance(reinterpret_cast<int64_t>(instanceData));
  moniker.set_service_location("local");
  moniker.set_data_source(endpointName);
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
void DataMonikerService::InitiateMonikerList(const MonikerList& monikers, EndpointList* readers, EndpointList* writers)
{
  for (auto readMoniker : monikers.read_monikers()) {
    auto instance = readMoniker.data_instance();
    auto source = readMoniker.data_source();
    auto it = _endpoints.find(source);
    MonikerEndpointPtr ptr = nullptr;
    if (it != _endpoints.end()) {
      ptr = (*it).second;
    }
    readers->push_back(EndpointInstance(ptr, reinterpret_cast<void*>(instance)));
  }
  for (auto writeMoniker : monikers.write_monikers()) {
    auto instance = writeMoniker.data_instance();
    auto source = writeMoniker.data_source();
    auto it = _endpoints.find(source);
    MonikerEndpointPtr ptr = nullptr;
    if (it != _endpoints.end()) {
      ptr = (*it).second;
    }
    writers->push_back(EndpointInstance(ptr, reinterpret_cast<void*>(instance)));
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
#ifndef _WIN32
void set_moniker_stream_processor(int stream_processor)
{
  if (stream_processor >= 0) {
    cpu_set_t cpuSet;
    CPU_ZERO(&cpuSet);
    CPU_SET(stream_processor, &cpuSet);
    sched_setaffinity(0, sizeof(cpu_set_t), &cpuSet);
  }
}
#endif

//---------------------------------------------------------------------
//---------------------------------------------------------------------
void DataMonikerService::RunSidebandReadWriteLoop(string sidebandIdentifier, ::SidebandStrategy strategy, EndpointList* readers, EndpointList* writers)
{
#ifndef _WIN32
  if (strategy == ::SidebandStrategy::RDMA_LOW_LATENCY ||
      strategy == ::SidebandStrategy::SOCKETS_LOW_LATENCY) {
    pid_t threadId = syscall(SYS_gettid);
    ::SysFsWrite("/dev/cgroup/cpuset/LabVIEW_tl_set/tasks", std::to_string(threadId));

    set_moniker_stream_processor(s_StreamProcessor.moniker_sideband_stream_read_write);
  }
#endif

  google::protobuf::Arena arena;
  int64_t sidebandToken;
  GetOwnerSidebandDataToken(sidebandIdentifier.c_str(), &sidebandToken);
  while (true) {
    auto writeRequest = google::protobuf::Arena::CreateMessage<SidebandWriteRequest>(&arena);
    if (!ReadSidebandMessage(sidebandToken, writeRequest)) {
      break;
    }
    if (writeRequest->cancel()) {
      break;
    }
    if (writers->size() > 0) {
      int x = 0;
      if (writers->size() != writeRequest->values().values_size()) {
        break;
      }
      for (auto writer : *writers) {
        std::get<0>(writer)(std::get<1>(writer), arena, const_cast<google::protobuf::Any&>(writeRequest->values().values(x++)));
      }
    }
    auto readResult = Arena::CreateMessage<SidebandReadResponse>(&arena);
    if (readers->size() > 0) {
      int x = 0;
      for (auto reader : *readers) {
        auto readValue = readResult->mutable_values()->add_values();
        std::get<0>(reader)(std::get<1>(reader), arena, *readValue);
      }
    }
    if (!WriteSidebandMessage(sidebandToken, *readResult)) {
      break;
    }
    arena.Reset();
    std::this_thread::sleep_for(std::chrono::microseconds(10));
  }
  delete readers;
  delete writers;
  CloseSidebandData(sidebandToken);
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status DataMonikerService::BeginSidebandStream(ServerContext* context, const BeginMonikerSidebandStreamRequest* request, BeginMonikerSidebandStreamResponse* response)
{
  auto bufferSize = 1024 * 1024;
  auto strategy = static_cast<::SidebandStrategy>(request->strategy());

  char identifier[32] = {};
  InitOwnerSidebandData(strategy, bufferSize, identifier);
  std::string identifierString(identifier);

  response->set_strategy(request->strategy());
  response->set_sideband_identifier(identifier);
  response->set_connection_url(GetConnectionAddress(strategy));
  response->set_buffer_size(bufferSize);
  QueueSidebandConnection(strategy, identifier, true, true, bufferSize);

  auto writers = new EndpointList();
  auto readers = new EndpointList();
  InitiateMonikerList(request->monikers(), readers, writers);

  auto thread = new std::thread(RunSidebandReadWriteLoop, identifierString, strategy, readers, writers);
  thread->detach();

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status DataMonikerService::StreamReadWrite(ServerContext* context, ServerReaderWriter<MonikerReadResponse, MonikerWriteRequest>* stream)
{
#ifndef _WIN32
  set_moniker_stream_processor(s_StreamProcessor.moniker_stream_read_write);
#endif

  EndpointList writers;
  EndpointList readers;
  MonikerWriteRequest writeRequest;
  stream->Read(&writeRequest);
  InitiateMonikerList(writeRequest.monikers(), &readers, &writers);

  google::protobuf::Arena arena;
  while (stream->Read(&writeRequest) && !context->IsCancelled()) {
    int x = 0;
    for (auto writer : writers) {
      std::get<0>(writer)(std::get<1>(writer), arena, const_cast<google::protobuf::Any&>(writeRequest.data().values(x++)));
    }

    MonikerReadResponse readResult;
    for (auto reader : readers) {
      auto readValue = readResult.mutable_data()->add_values();
      std::get<0>(reader)(std::get<1>(reader), arena, *readValue);
    }
    stream->Write(readResult);
    arena.Reset();
  }
  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status DataMonikerService::StreamRead(ServerContext* context, const MonikerList* request, ServerWriter<MonikerReadResponse>* writer)
{
#ifndef _WIN32
  set_moniker_stream_processor(s_StreamProcessor.moniker_stream_read);
#endif

  EndpointList writers;
  EndpointList readers;
  InitiateMonikerList(*request, &readers, &writers);

  google::protobuf::Arena arena;
  while (!context->IsCancelled()) {
    MonikerReadResponse readResult;
    for (auto reader : readers) {
      auto readValue = readResult.mutable_data()->add_values();
      std::get<0>(reader)(std::get<1>(reader), arena, *readValue);
    }
    writer->Write(readResult);
    arena.Reset();
  }
  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status DataMonikerService::StreamWrite(ServerContext* context, ServerReaderWriter<StreamWriteResponse, MonikerWriteRequest>* stream)
{
#ifndef _WIN32
  set_moniker_stream_processor(s_StreamProcessor.moniker_stream_write);
#endif

  EndpointList writers;
  EndpointList readers;
  MonikerWriteRequest writeRequest;
  stream->Read(&writeRequest);
  InitiateMonikerList(writeRequest.monikers(), &readers, &writers);

  int x = 0;
  google::protobuf::Arena arena;
  while (stream->Read(&writeRequest) && !context->IsCancelled()) {
    x = 0;
    for (auto writer : writers) {
      std::get<0>(writer)(std::get<1>(writer), arena, const_cast<google::protobuf::Any&>(writeRequest.data().values(x++)));
    }
    arena.Reset();
  }
  return Status::OK;
}
}  // namespace ni::data_monikers
