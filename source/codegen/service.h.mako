// This file was generated
<%
attributes = data['attributes']
config = data['config']
enums = data['enums']
functions = data['functions']

## TODO: Pull niFake from config metadata.
driver_prefix = "niFake" ## config['driver_name']
%>\
## Include section
#include <${driver_prefix}.grpc.pb.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <condition_variable>
## TODO: Do we need more includes? Session manager, core_service, and/or SharedLibrary?

## Usings TODO: Do we want to use usings or no?
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::ServerWriter;
using namespace std;

namespace ni
{
namespace hardware
{
namespace grpc
{
  class ${driver_prefix}Service final : public ${driver_prefix}::Service
  {
  public:
  % for function in functions:
  <% 
    method_name = function
  %>\
  ## TODO: Possibly filter which functions to generate.
    Status ${method_name}(ServerContext* context, const ${driver_prefix}::${method_name}Request* request, ${driver_prefix}::${method_name}Response* response) override;
  % endfor
  };
} // namespace grpc
} // namespace hardware
} // namespace ni