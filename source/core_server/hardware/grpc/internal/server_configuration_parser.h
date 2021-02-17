#ifndef NI_HARDWARE_GRPC_INTERNAL_SERVERCONFIGURATION
#define NI_HARDWARE_GRPC_INTERNAL_SERVERCONFIGURATION

#include <fstream>

#include "nlohmann/json.hpp"

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

static const char* kConfigFileNotFoundMessage = "The server configuration file was not found at the provided or default locations.";
static const char* kInvalidPortMessage = "The specified port number must between 0 and 65535.";
static const char* kMalformedJsonMessage = "The JSON in the server configuration file is malformed: \n\n";
static const char* kWrongPortTypeMessage = "The server port must be specified in the server's configuration file as an integer: \n\n";
static const char* kUnspecifiedPortMessage = "The server port must be specified in the server's configuration file.";

class ServerConfigurationParser {
 public:
  ServerConfigurationParser();
  ServerConfigurationParser(const char* config_file_path);
  ServerConfigurationParser(const nlohmann::json& config_file);
  virtual ~ServerConfigurationParser();

  std::string parse_address();

  struct ConfigFileNotFoundException : public std::runtime_error {
    ConfigFileNotFoundException();
  };

  struct InvalidPortException : public std::runtime_error {
    InvalidPortException();
  };

  struct MalformedJsonException : public std::runtime_error {
    MalformedJsonException(const std::string& parse_error_details);
  };

  struct WrongPortTypeException : public std::runtime_error {
    WrongPortTypeException(const std::string& type_error_details);
  };

  struct UnspecifiedPortException : public std::runtime_error {
    UnspecifiedPortException();
  };

 private:
  static std::string get_exe_path();
  static nlohmann::json load(const std::string& config_file_path);

  nlohmann::json config_file_;
  std::string config_file_path_;
};

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni

#endif  // NI_HARDWARE_GRPC_INTERNAL_SERVERCONFIGURATION
