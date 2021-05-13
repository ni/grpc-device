#ifndef NIDEVICE_GRPC_TESTS_DEVICE_SERVER
#define NIDEVICE_GRPC_TESTS_DEVICE_SERVER

#include <memory>

namespace grpc {
class Channel;
}

namespace ni {
namespace tests {
namespace system {

class DeviceServerInterface {
 public:
  virtual ~DeviceServerInterface() = 0;
  virtual void ResetServer() = 0;
  virtual std::shared_ptr<::grpc::Channel> InProcessChannel() = 0;

  static DeviceServerInterface* Singleton();
};

}  // namespace system
}  // namespace tests
}  // namespace ni

#endif  // NIDEVICE_GRPC_TESTS_DEVICE_SERVER
