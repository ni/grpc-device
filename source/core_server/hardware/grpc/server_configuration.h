#include "nlohmann/json.hpp"
#include <fstream>

namespace ni {
namespace hardware {
namespace grpc {

class ServerConfiguration {
 public:
  ServerConfiguration(const std::string& config_file_path);

  std::string get_address();
  
  struct ConfigFileNotFoundException : public std::runtime_error
  {
    ConfigFileNotFoundException();
  };
  
  struct InvalidPortException : public std::runtime_error
  {
    InvalidPortException();
  };

 private:
  static const char* klocalhostAddressPrefix;
  static const char* kconfigurationFile;
  static const char* kportKey;
  static const char* kConfigFileNotFoundMessage;
  static const char* kinvalidPortMessage;
  
  nlohmann::json config_file_;
  std::string config_file_path_;
  
  void parse_config();
};

}  // namespace grpc
}  // namespace hardware
}  // namespace ni
