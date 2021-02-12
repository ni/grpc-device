#include "hardware/grpc/core_service.h"
#include "hardware/grpc/server_configuration.h"

const char* kerrorMessage = "ERROR: ";
const char* kexitingMessage = " Exiting.";

static void RunServer(int argc, char** argv)
{
  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  
  std::string server_address;
  try {
    //TODO: parse config file path from command line argument
    std::string config_file_path;
    ni::hardware::grpc::ServerConfiguration server_configuration(config_file_path);
    server_address = server_configuration.get_address();
  }
  catch(const std::exception& ex) {
    std::cerr << ex.what() << std::endl;
    exit(EXIT_FAILURE);
  }

  // Listen on the given address without any authentication mechanism.
  grpc::ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

  // Register services available on the server.
  ni::hardware::grpc::internal::SessionRepository session_repository;
  ni::hardware::grpc::CoreService core_service(&session_repository);
  builder.RegisterService(&core_service);

  // Assemble the server.
  auto server = builder.BuildAndStart();

  std::cout << "Server listening on " << server_address << std::endl;

  // This call will block until another thread shuts down the server.
  server->Wait();
}

int main(int argc, char** argv)
{
  RunServer(argc, argv);
  return 0;
}
