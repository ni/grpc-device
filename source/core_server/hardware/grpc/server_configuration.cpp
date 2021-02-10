#include "server_configuration.h"

namespace ni {
namespace hardware {
namespace grpc {

const char* klocalhostAddressPrefix = "0.0.0.0:";
const int kdefaultPort = 50051;
const char* kconfigurationFile = "server.json";
const char* kportKey = "port";

ServerConfiguration::ServerConfiguration()
{
}

void ServerConfiguration::parse_config()
{
   if(config_file_ == nullptr){
      std::ifstream input_stream(kconfigurationFile);
      if (input_stream) {
         input_stream >> config_file_;
      }
   }
}

std::string ServerConfiguration::get_address()
{
   int parsed_port = 0;
   parse_config();
   if (config_file_ != nullptr){
      parsed_port = config_file_[kportKey].get<int>();
   }
   
   int port = kdefaultPort;
   if (parsed_port > 0) {
      port = parsed_port;
   }
   return klocalhostAddressPrefix + std::to_string(port);
}

}  // namespace grpc
}  // namespace hardware
}  // namespace ni
