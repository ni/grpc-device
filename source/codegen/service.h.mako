// This file was generated
<%
import codegen_helpers
attributes = data['attributes']
config = data['config']
enums = data['enums']
functions = data['functions']

## TODO: Pull niFake from config metadata.
driver_prefix = "niFake" ## config['driver_name']
driver_namespace = "fake"
define_name = "ni_hardware_grpc_" + driver_prefix + "_service_h"
define_name = define_name.upper()
service_name = "NiFakeService"
%>\
## Define section
#ifndef ${define_name}
#define ${define_name}

## Include section
#include <${driver_prefix}.grpc.pb.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <condition_variable>
#include "core_server/hardware/grpc/internal/shared_library.h"
#include "core_server/hardware/grpc/internal/session_repository.h"

namespace ni
{
namespace ${driver_namespace}
{
namespace grpc
{
  class ${service_name} final : public ${driver_prefix}::Service
  {
  public:
    ${service_name}(SharedLibrary* shared_library, SessionRepository* session_repository);
% for function in functions:
<%
    f = functions[function]
    if not codegen_helpers.should_gen_service_handler(f):
      continue
%>\
    grpc::Status ${function}(grpc::ServerContext* context, const ${driver_prefix}::${function}Request* request, ${driver_prefix}::${function}Response* response) override;
  % endfor
  private:
    internal::SharedLibrary* shared_library_;
    internal::SessionRepository* session_repository_;
  };
} // namespace grpc
} // namespace ${driver_namespace}
} // namespace ni
#endif ${define_name}