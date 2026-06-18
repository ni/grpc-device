//---------------------------------------------------------------------
//---------------------------------------------------------------------
#include "data_moniker_service.h"
#include "exceptions.h"
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

bool is_moniker_streaming_enabled(const nidevice_grpc::FeatureToggles& feature_toggles)
{
  return feature_toggles.is_feature_enabled("moniker_streaming", nidevice_grpc::FeatureToggles::CodeReadiness::kNextRelease);
}

bool is_moniker_streaming_sideband_support_enabled(const nidevice_grpc::FeatureToggles& feature_toggles)
{
  return feature_toggles.is_feature_enabled("moniker_streaming_sideband_support", nidevice_grpc::FeatureToggles::CodeReadiness::kNextRelease);
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
// CWE-822: Register instance data behind an opaque handle instead of
// transmitting raw pointers over gRPC. The handle is a random 64-bit
// value that maps to the actual pointer in s_instance_registry.
// Randomized handles prevent attackers from guessing valid handles.
//---------------------------------------------------------------------
void DataMonikerService::RegisterMonikerInstance(string endpointName, void* instanceData, Moniker& moniker)
{
  int64_t handle;
  {
    std::lock_guard<std::mutex> lock(s_Server->instance_mutex_);
    do {
      handle = static_cast<int64_t>(s_Server->rng_());
    } while (handle == 0 || s_Server->instance_registry_.count(handle));
    s_Server->instance_registry_[handle] = instanceData;
  }
  moniker.set_data_instance(handle);
  moniker.set_service_location("local");
  moniker.set_data_source(endpointName);
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
void* DataMonikerService::LookupInstance(int64_t handle)
{
  std::lock_guard<std::mutex> lock(s_Server->instance_mutex_);
  auto it = s_Server->instance_registry_.find(handle);
  if (it != s_Server->instance_registry_.end()) {
    return it->second;
  }
  return nullptr;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
void DataMonikerService::InitiateMonikerList(const MonikerList& monikers, EndpointList* readers, EndpointList* writers)
{
  for (auto readMoniker : monikers.read_monikers()) {
    auto instance = readMoniker.data_instance();
    auto source = readMoniker.data_source();
    auto it = _endpoints.find(source);
    if (it == _endpoints.end()) {
      throw nidevice_grpc::NonDriverException(grpc::INVALID_ARGUMENT, "Unknown moniker data_source: " + source);
    }
    void* instancePtr = LookupInstance(instance);
    if (!instancePtr) {
      throw nidevice_grpc::NonDriverException(grpc::INVALID_ARGUMENT, "Invalid moniker data_instance handle");
    }
    readers->push_back(EndpointInstance((*it).second, instancePtr));
  }
  for (auto writeMoniker : monikers.write_monikers()) {
    auto instance = writeMoniker.data_instance();
    auto source = writeMoniker.data_source();
    auto it = _endpoints.find(source);
    if (it == _endpoints.end()) {
      throw nidevice_grpc::NonDriverException(grpc::INVALID_ARGUMENT, "Unknown moniker data_source: " + source);
    }
    void* instancePtr = LookupInstance(instance);
    if (!instancePtr) {
      throw nidevice_grpc::NonDriverException(grpc::INVALID_ARGUMENT, "Invalid moniker data_instance handle");
    }
    writers->push_back(EndpointInstance((*it).second, instancePtr));
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
#ifndef _WIN32
void set_cpu_affinity(int cpu)
{
  if (cpu >= 0) {
    cpu_set_t cpuSet;
    CPU_ZERO(&cpuSet);
    CPU_SET(cpu, &cpuSet);
    sched_setaffinity(0, sizeof(cpu_set_t), &cpuSet);
  }
}
#endif

//---------------------------------------------------------------------
//---------------------------------------------------------------------
void DataMonikerService::RunSidebandReadWriteLoop(string sidebandIdentifier, ::SidebandStrategy strategy, EndpointList readers, EndpointList writers)
{
#ifndef _WIN32
  if (strategy == ::SidebandStrategy::RDMA_LOW_LATENCY ||
      strategy == ::SidebandStrategy::SOCKETS_LOW_LATENCY) {
    pid_t threadId = syscall(SYS_gettid);
    ::SysFsWrite("/dev/cgroup/cpuset/LabVIEW_tl_set/tasks", std::to_string(threadId));

    set_cpu_affinity(s_StreamProcessor.moniker_sideband_stream_read_write);
  }
#endif

  google::protobuf::Arena arena;
  int64_t sidebandToken;
  GetOwnerSidebandDataToken(sidebandIdentifier.c_str(), &sidebandToken);
  while (true) {
    auto writeRequest = google::protobuf::Arena::Create<SidebandWriteRequest>(&arena);
    if (!ReadSidebandMessage(sidebandToken, writeRequest)) {
      break;
    }
    if (writeRequest->cancel()) {
      break;
    }
    if (writers.size() > 0) {
      int x = 0;
      if (writers.size() != writeRequest->values().values_size()) {
        break;
      }
      for (auto writer : writers) {
        std::get<0>(writer)(std::get<1>(writer), arena, const_cast<google::protobuf::Any&>(writeRequest->values().values(x++)));
      }
    }
    auto readResult = Arena::Create<SidebandReadResponse>(&arena);
    if (readers.size() > 0) {
      int x = 0;
      for (auto reader : readers) {
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
  CloseSidebandData(sidebandToken);
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status DataMonikerService::BeginSidebandStream(ServerContext* context, const BeginMonikerSidebandStreamRequest* request, BeginMonikerSidebandStreamResponse* response)
{
  try {
    // CWE-20: Validate the strategy enum before casting to the sideband library type.
    // Protobuf accepts any int32 on the wire, so an out-of-range value would be
    // passed through static_cast unchecked, causing undefined behavior.
    auto requested_strategy_enum = request->strategy();
    if (!ni::data_monikers::SidebandStrategy_IsValid(requested_strategy_enum) ||
        requested_strategy_enum == ni::data_monikers::UNKNOWN) {
      return Status(grpc::INVALID_ARGUMENT,
          "Invalid sideband strategy: " + std::to_string(static_cast<int>(requested_strategy_enum)));
    }
    auto sideband_strategy = static_cast<::SidebandStrategy>(requested_strategy_enum);

    auto bufferSize = 1024 * 1024;

    char identifier[32] = {};
    auto sideband_init_result = InitOwnerSidebandData(sideband_strategy, bufferSize, identifier);
    if (sideband_init_result == -1) {
      return Status(grpc::UNKNOWN,
        "Failed to initialize sideband stream for strategy: " + std::to_string(static_cast<int>(requested_strategy_enum)));
    }
    std::string identifierString(identifier);

    response->set_strategy(request->strategy());
    response->set_sideband_identifier(identifier);
    response->set_connection_url(GetConnectionAddress(sideband_strategy));
    response->set_buffer_size(bufferSize);
    QueueSidebandConnection(sideband_strategy, identifier, true, true, bufferSize);

    EndpointList writers;
    EndpointList readers;
    InitiateMonikerList(request->monikers(), &readers, &writers);
    std::thread(RunSidebandReadWriteLoop, identifierString, sideband_strategy, std::move(readers), std::move(writers)).detach();

    return Status::OK;
  } catch (const nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status DataMonikerService::StreamReadWrite(ServerContext* context, ServerReaderWriter<MonikerReadResponse, MonikerWriteRequest>* stream)
{
  try {
#ifndef _WIN32
    set_cpu_affinity(s_StreamProcessor.moniker_stream_read_write);
#endif

    EndpointList writers;
    EndpointList readers;
    MonikerWriteRequest writeRequest;
    stream->Read(&writeRequest);
    InitiateMonikerList(writeRequest.monikers(), &readers, &writers);

    google::protobuf::Arena arena;
    while (stream->Read(&writeRequest) && !context->IsCancelled()) {
      // CWE-125: Validate value count matches writer count before accessing by index.
      if (writers.size() != static_cast<size_t>(writeRequest.data().values_size())) {
        return Status(grpc::INVALID_ARGUMENT, "Value count does not match writer count");
      }
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
  } catch (const nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status DataMonikerService::StreamRead(ServerContext* context, const MonikerList* request, ServerWriter<MonikerReadResponse>* writer)
{
  try {
#ifndef _WIN32
    set_cpu_affinity(s_StreamProcessor.moniker_stream_read);
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
  } catch (const nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status DataMonikerService::StreamWrite(ServerContext* context, ServerReaderWriter<StreamWriteResponse, MonikerWriteRequest>* stream)
{
  try {
#ifndef _WIN32
    set_cpu_affinity(s_StreamProcessor.moniker_stream_write);
#endif

    EndpointList writers;
    EndpointList readers;
    MonikerWriteRequest writeRequest;
    stream->Read(&writeRequest);
    InitiateMonikerList(writeRequest.monikers(), &readers, &writers);

    int x = 0;
    google::protobuf::Arena arena;
    while (stream->Read(&writeRequest) && !context->IsCancelled()) {
      // CWE-125: Validate value count matches writer count before accessing by index.
      if (writers.size() != static_cast<size_t>(writeRequest.data().values_size())) {
        return Status(grpc::INVALID_ARGUMENT, "Value count does not match writer count");
      }

      x = 0;
      for (auto writer : writers) {
        std::get<0>(writer)(std::get<1>(writer), arena, const_cast<google::protobuf::Any&>(writeRequest.data().values(x++)));
      }
      arena.Reset();
    }
    return Status::OK;
  } catch (const nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}
}  // namespace ni::data_monikers
