//---------------------------------------------------------------------
//---------------------------------------------------------------------
#include <thread>
#include <sstream>
#include <fstream>
#include <iostream>
#include <atomic>
#include <grpcpp/grpcpp.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

//---------------------------------------------------------------------
//---------------------------------------------------------------------
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

//---------------------------------------------------------------------
//---------------------------------------------------------------------
using namespace std;

const string localhostAddress = "0.0.0.0:50051";

//---------------------------------------------------------------------
//---------------------------------------------------------------------
void RunServer(int argc, char **argv)
{
	grpc::EnableDefaultHealthCheckService(true);
	grpc::reflection::InitProtoReflectionServerBuilderPlugin();

	ServerBuilder builder;
	
    // Listen on the given address without any authentication mechanism.
	builder.AddListeningPort(localhostAddress, grpc::InsecureServerCredentials());
	
	// Assemble the server.
	std::unique_ptr<Server> server(builder.BuildAndStart());	

	cout << "Server listening on " << localhostAddress << endl;
	
	// This call will block until another thread shuts down the server.
	server->Wait();
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
int main(int argc, char **argv)
{
	RunServer(argc, argv);
	return 0;
}
