//---------------------------------------------------------------------
// Implementation of NI Data Moniker Service
//---------------------------------------------------------------------
#pragma once

//---------------------------------------------------------------------
//---------------------------------------------------------------------
#include <grpcpp/grpcpp.h>
#include <data_moniker.grpc.pb.h>
#include <type_traits>
#include <map>
#include <sideband_data.h>

//---------------------------------------------------------------------
//---------------------------------------------------------------------
namespace ni::data_monikers
{
    //---------------------------------------------------------------------
    //---------------------------------------------------------------------
    using MonikerEndpointPtr = std::add_pointer<::grpc::Status(void*, google::protobuf::Arena& arena, google::protobuf::Any&)>::type;
    using EndpointInstance = std::tuple<MonikerEndpointPtr, void*>;
    using EndpointList = std::vector<EndpointInstance>;

    //---------------------------------------------------------------------
    //---------------------------------------------------------------------
    class DataMonikerService final : public DataMoniker::Service
    {
    public:
        DataMonikerService();
        ::grpc::Status BeginSidebandStream(grpc::ServerContext* context, const ni::data_monikers::BeginMonikerSidebandStreamRequest* request, ni::data_monikers::BeginMonikerSidebandStreamResponse* response) override;
        ::grpc::Status StreamReadWrite(::grpc::ServerContext* context, ::grpc::ServerReaderWriter<MonikerReadResponse, MonikerWriteRequest>* stream) override;
        ::grpc::Status StreamRead(::grpc::ServerContext* context, const MonikerList* request, ::grpc::ServerWriter<MonikerReadResponse>* writer);
        ::grpc::Status StreamWrite(::grpc::ServerContext* context, ::grpc::ServerReaderWriter<StreamWriteResponse, MonikerWriteRequest>* stream);

    public:
        static void RegisterMonikerEndpoint(std::string endpointName, MonikerEndpointPtr endpoint);
        static void RegisterMonikerInstance(std::string endpointName, void* instanceData, Moniker& moniker);
    
    private:
        static DataMonikerService* s_Server;
        std::map<std::string, MonikerEndpointPtr> _endpoints;

    private:
        void InitiateMonikerList(const MonikerList& monikers, EndpointList* readers, EndpointList* writers);
        static void RunSidebandReadWriteLoop(std::string sidebandIdentifier, ::SidebandStrategy strategy, EndpointList* readers, EndpointList* writers);
    };
}
