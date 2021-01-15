#pragma once

#ifdef __WIN32__
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#include <core.grpc.pb.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::ServerWriter;
using namespace std;

#ifdef _WIN32
    #define LIBRARY_EXPORT extern "C" __declspec(dllexport)
#else
    #define LIBRARY_EXPORT extern "C"
#endif

class CoreService final : public Core::CoreService::Service
{
public:
   grpc::Status CoreService::GetServerStatus(::grpc::ServerContext* context, const ServerStatus* status);
};
