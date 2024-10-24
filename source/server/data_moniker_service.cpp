//---------------------------------------------------------------------
//---------------------------------------------------------------------
#include <thread>
#include <tuple>
#include <sideband_data.h>
#include <sideband_internal.h>
#include <sideband_grpc.h>
#include "data_moniker_service.h"
#ifndef _WIN32
#include <sys/syscall.h>
#endif

#include <fstream>
#include <sstream>

//---------------------------------------------------------------------
//---------------------------------------------------------------------
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::ServerWriter;
using grpc::ServerReaderWriter;
using std::string;
using ni::data_monikers::DataMoniker;
using ni::data_monikers::MonikerList;
using ni::data_monikers::MonikerWriteRequest;
using ni::data_monikers::MonikerReadResponse;
using ni::data_monikers::StreamWriteResponse;
using ni::data_monikers::SidebandWriteRequest;
using ni::data_monikers::SidebandReadResponse;
using ni::data_monikers::BeginMonikerSidebandStreamRequest;
using ni::data_monikers::BeginMonikerSidebandStreamResponse;
using google::protobuf::Arena;

static void SysFsWrite(const std::string& fileName, const std::string& value)
{
    std::ofstream fout;
    fout.open(fileName);
    fout << value;
    fout.close();
}

namespace ni::data_monikers
{
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
        for (auto readMoniker: monikers.read_monikers())
        {
            auto instance = readMoniker.data_instance();
            auto source = readMoniker.data_source();
            auto it = _endpoints.find(source);
            MonikerEndpointPtr ptr = nullptr;
            if (it != _endpoints.end())
            {
                ptr = (*it).second;
            }
            readers->push_back(EndpointInstance(ptr, reinterpret_cast<void*>(instance)));
        }
        for (auto writeMoniker: monikers.write_monikers())
        {
            auto instance = writeMoniker.data_instance();
            auto source = writeMoniker.data_source();
            auto it = _endpoints.find(source);
            MonikerEndpointPtr ptr = nullptr;
            if (it != _endpoints.end())
            {
                ptr = (*it).second;
            }
            writers->push_back(EndpointInstance(ptr, reinterpret_cast<void*>(instance)));
        }
    }

    //---------------------------------------------------------------------
    //---------------------------------------------------------------------
    void DataMonikerService::RunSidebandReadWriteLoop(string sidebandIdentifier, ::SidebandStrategy strategy, EndpointList* readers, EndpointList* writers)
    {
        std::cout << "Enter RunSidebandReadWriteLoop" << std::endl;

    #ifndef _WIN32
        if (strategy == ::SidebandStrategy::RDMA_LOW_LATENCY ||
            strategy == ::SidebandStrategy::SOCKETS_LOW_LATENCY)
        {
            pid_t threadId = syscall(SYS_gettid);
            ::SysFsWrite("/dev/cgroup/cpuset/LabVIEW_tl_set/tasks", std::to_string(threadId));

            cpu_set_t cpuSet;
            CPU_ZERO(&cpuSet);
            CPU_SET(8, &cpuSet);
            //CPU_SET(8, &cpuSet);
            sched_setaffinity(threadId, sizeof(cpu_set_t), &cpuSet);
        }
    #endif

        google::protobuf::Arena arena;
        int64_t sidebandToken;
        GetOwnerSidebandDataToken(sidebandIdentifier.c_str(), &sidebandToken);
        while (true)
        {
            auto writeRequest = google::protobuf::Arena::CreateMessage<SidebandWriteRequest>(&arena);
            if (!ReadSidebandMessage(sidebandToken, writeRequest))
            {
                break;
            }
            if (writeRequest->cancel())
            {
                std::cout << "Cancelled." << std::endl;
                break;
            }
            if (writers->size() > 0)
            {
                int x = 0;                
                if (writers->size() != writeRequest->values().values_size())
                {
                    std::cout << "ERROR: The number of writers and values read did not match" << std::endl;
                    std::cout << "Expected: " << writers->size() << std::endl;
                    std::cout << "Actual: " << writeRequest->values().values_size() << std::endl;
                    break;
                }
                for (auto writer: *writers)
                {
                    std::get<0>(writer)(std::get<1>(writer), arena, const_cast<google::protobuf::Any&>(writeRequest->values().values(x++)));
                }
            }
            auto readResult = Arena::CreateMessage<SidebandReadResponse>(&arena);
            if (readResult->GetArena() != &arena)
            {
                std::cout << "No Arena 111" << std::endl;
            }
            if (readers->size() > 0)
            {
                 int x = 0;
                 for (auto reader: *readers)
                 {
                     auto readValue = readResult->mutable_values()->add_values();
                     if (readValue->GetArena() != &arena)
                     {
                         std::cout << "No Arena" << std::endl;
                     }
                     std::get<0>(reader)(std::get<1>(reader), arena, *readValue);
                 }
            }
            if (!WriteSidebandMessage(sidebandToken, *readResult))
            {
                std::cout << "Failed to write" << std::endl;
                break;
            }
            arena.Reset();
    		std::this_thread::sleep_for(std::chrono::microseconds(10));
        }
        delete readers;
        delete writers;
        CloseSidebandData(sidebandToken);
        std::cout << "Exit RunSidebandReadWriteLoop" << std::endl;
    }

    //---------------------------------------------------------------------
    //---------------------------------------------------------------------
    Status DataMonikerService::BeginSidebandStream(ServerContext* context, const BeginMonikerSidebandStreamRequest* request, BeginMonikerSidebandStreamResponse* response)
    {
        std::cout << "Enter BeginSidebandStream" << std::endl;
        auto bufferSize = 1024 * 1024;
        auto strategy = static_cast<::SidebandStrategy>(request->strategy());

        char identifier[32] = {};
        InitOwnerSidebandData(strategy, bufferSize, identifier);;
        response->set_strategy(request->strategy());
        response->set_sideband_identifier(identifier);
        response->set_connection_url(GetConnectionAddress(strategy));
        response->set_buffer_size(bufferSize);
        QueueSidebandConnection(strategy, identifier, true, true, bufferSize);

        auto writers = new EndpointList();
        auto readers = new EndpointList();
        InitiateMonikerList(request->monikers(), readers, writers);

        std::cout << "Starting thread with RunSidebandReadWriteLoop()" << std::endl;
        auto thread = new std::thread(RunSidebandReadWriteLoop, identifier, strategy, readers, writers);
        thread->detach();

        std::cout << "Exit BeginSidebandStream" << std::endl;
        return Status::OK;
    }

    //---------------------------------------------------------------------
    //---------------------------------------------------------------------
    Status DataMonikerService::StreamReadWrite(ServerContext* context, ServerReaderWriter<MonikerReadResponse, MonikerWriteRequest>* stream)
    {
        EndpointList writers;
        EndpointList readers;
        MonikerWriteRequest writeRequest;
        stream->Read(&writeRequest);
        InitiateMonikerList(writeRequest.monikers(), &readers, &writers);

        google::protobuf::Arena arena;
        while (stream->Read(&writeRequest) && !context->IsCancelled())
        {
            int x = 0;
            for (auto writer: writers)
            {
                std::get<0>(writer)(std::get<1>(writer), arena, const_cast<google::protobuf::Any&>(writeRequest.data().values(x++)));
            }

            MonikerReadResponse readResult;
            for (auto reader: readers)
            {
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
        EndpointList writers;
        EndpointList readers;
        InitiateMonikerList(*request, &readers, &writers);

        google::protobuf::Arena arena;
        while (!context->IsCancelled())
        {
            MonikerReadResponse readResult;
            for (auto reader: readers)
            {
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
        cpu_set_t cpuSet;
        CPU_ZERO(&cpuSet);
        CPU_SET(1, &cpuSet);
        sched_setaffinity(0, sizeof(cpu_set_t), &cpuSet);
    #endif

        EndpointList writers;
        EndpointList readers;
        MonikerWriteRequest writeRequest;
        stream->Read(&writeRequest);
        InitiateMonikerList(writeRequest.monikers(), &readers, &writers);

        int x = 0;
        google::protobuf::Arena arena;
        while (stream->Read(&writeRequest) && !context->IsCancelled())
        {
            x = 0;
            for (auto writer: writers)
            {
                std::get<0>(writer)(std::get<1>(writer), arena, const_cast<google::protobuf::Any&>(writeRequest.data().values(x++)));
            }
            arena.Reset();
        }
        return Status::OK;
    }
}
