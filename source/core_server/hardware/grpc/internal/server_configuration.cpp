#include "server_configuration.h"

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {
  
const char* ServerConfiguration::klocalhostAddressPrefix = "0.0.0.0:";
const char* ServerConfiguration::kdefaultFilename = "server.json";
const char* ServerConfiguration::kportKey = "port";
const char* ServerConfiguration::kConfigFileNotFoundMessage = "The server configuration file was not found.";
const char* ServerConfiguration::kinvalidPortMessage = "The specified port number must between 0 and 65535.";

ServerConfiguration::ServerConfiguration(const std::string& config_file_path)
  : config_file_path_(config_file_path)
{
}

void ServerConfiguration::parse_config()
{
  if(config_file_ == nullptr){
    // TODO: Prefer a passed in configuration file path and then search next to
    // the binary and finally at platform specific default config file locations.
    std::string file_path;
    if (config_file_path_.empty()){
      file_path = kdefaultFilename;
    }
    else {
      file_path = config_file_path_;
    }
    
    std::ifstream input_stream(file_path);
    if (!input_stream) {
      throw ConfigFileNotFoundException();
    }
    input_stream >> config_file_;
  }
}

std::string ServerConfiguration::get_address()
{
   int parsed_port = 0;
   parse_config();
   if (config_file_ != nullptr){
      std::string key(kportKey);
      auto it = config_file_.find(key);
      if (it != config_file_.end()) {
         parsed_port = config_file_[key].get<int>();
      }
   }
   
   if (parsed_port < 0 || parsed_port > 65535) {
      throw InvalidPortException();
   }
   return klocalhostAddressPrefix + std::to_string(parsed_port);
}

ServerConfiguration::ConfigFileNotFoundException::ConfigFileNotFoundException()
  : std::runtime_error(std::string(kConfigFileNotFoundMessage))
{
}

ServerConfiguration::InvalidPortException::InvalidPortException()
  : std::runtime_error(std::string(kinvalidPortMessage))
{
}
}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni
