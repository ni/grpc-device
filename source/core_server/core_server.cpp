#include "hardware/grpc/core_service.h"

const char* klocalhostAddress = "0.0.0.0:50051";

static void RunServer(int argc, char **argv)
{
   grpc::EnableDefaultHealthCheckService(true);
   grpc::reflection::InitProtoReflectionServerBuilderPlugin();

   grpc::ServerBuilder builder;

   // Listen on the given address without any authentication mechanism.
   builder.AddListeningPort(klocalhostAddress, grpc::InsecureServerCredentials());

   // Register services available on the server.
   ni::hardware::grpc::CoreService coreService;
   builder.RegisterService(&coreService);

   // Assemble the server.
   auto server = builder.BuildAndStart();

   std::cout << "Server listening on " << klocalhostAddress << std::endl;

   // This call will block until another thread shuts down the server.
   server->Wait();
}

int main(int argc, char **argv)
{
   RunServer(argc, argv);
   return 0;
}
