#ifndef NI_HARDWARE_GRPC_INTERNAL_SERVERCONFIGURATION
#define NI_HARDWARE_GRPC_INTERNAL_SERVERCONFIGURATION

#include "nlohmann/json.hpp"
#include <fstream>

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

class ServerConfigurationParser {

 public:
  ServerConfigurationParser();
  ServerConfigurationParser(const char* config_file_path);
  ServerConfigurationParser(const nlohmann::json& config_file);

  std::string parse_address();
  
  struct ConfigFileNotFoundException : public std::runtime_error
  {
    ConfigFileNotFoundException();
  };
  
  struct InvalidPortException : public std::runtime_error
  {
    InvalidPortException();
  };

 private:
  static const char* kLocalhostAddressPrefix;
  static const char* kDefaultFilename;
  static const char* kPortKey;
  static const char* kConfigFileNotFoundMessage;
  static const char* kInvalidPortMessage;
  
  nlohmann::json config_file_;
  std::string config_file_path_;

  static nlohmann::json load(const char* config_file_path);
};

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni

#endif  // NI_HARDWARE_GRPC_INTERNAL_SERVERCONFIGURATION
