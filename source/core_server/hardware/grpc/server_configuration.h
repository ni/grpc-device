#include "nlohmann/json.hpp"
#include <fstream>

namespace ni {
namespace hardware {
namespace grpc {

class ServerConfiguration {
 public:
  ServerConfiguration();

  std::string get_address();

 private:
  nlohmann::json config_file_;
  
  void parse_config();
};

}  // namespace grpc
}  // namespace hardware
}  // namespace ni
