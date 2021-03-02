#ifndef NI_HARDWARE_GRPC_INTERNAL_SERVER_CONFIGURATION_PARSER_H_
#define NI_HARDWARE_GRPC_INTERNAL_SERVER_CONFIGURATION_PARSER_H_

#include <fstream>
#include <nlohmann/json.hpp>

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

static const char* kConfigFileNotFoundMessage = "The server configuration file was not found at: ";
static const char* kInvalidPortMessage = "The specified port number must between 0 and 65535.";
static const char* kMalformedJsonMessage = "The JSON in the server configuration file is malformed: \n\n";
static const char* kWrongPortTypeMessage = "The server port must be specified in the server's configuration file as an integer: \n\n";
static const char* kUnspecifiedPortMessage = "The server port must be specified in the server's configuration file.";
static const char* kValueTypeNotStringMessage = "The following key must be specified in the server's configuration file as a string enclosed with double quotes: ";
static const char* kFileNotFoundMessage = "The following certificate file was not found: ";
static const char* kInvalidExePathMessage = "The server was unable to resolve the current executable path.";
static const char* kDefaultAddressPrefix = "[::]:";

class ServerConfigurationParser {
 public:
  ServerConfigurationParser();
  ServerConfigurationParser(const std::string& config_file_path);
  ServerConfigurationParser(const nlohmann::json& config_file);
  virtual ~ServerConfigurationParser() {}

  static std::string get_exe_path();

  std::string parse_address() const;
  std::string parse_server_cert() const;
  std::string parse_server_key() const;
  std::string parse_root_cert() const;

  struct ConfigFileNotFoundException : public std::runtime_error {
    ConfigFileNotFoundException(const std::string& config_file_path);
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

  struct ValueTypeNotStringException : public std::runtime_error {
    ValueTypeNotStringException(const std::string& key);
  };

  struct FileNotFoundException : public std::runtime_error {
    FileNotFoundException(const std::string& filepath);
  };

  struct InvalidExePathException : public std::runtime_error {
    InvalidExePathException();
  };

 private:
  static nlohmann::json load(const std::string& config_file_path);
  static std::string read_keycert(const std::string& filename);
  static std::string get_certs_directory(const std::string& config_file_path);
  std::string parse_key_from_security_section(const char* key) const;

  nlohmann::json config_file_;
  std::string config_file_path_;
  std::string certs_directory_;
};

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni

#endif  // NI_HARDWARE_GRPC_INTERNAL_SERVER_CONFIGURATION_PARSER_H_
