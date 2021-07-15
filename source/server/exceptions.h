#ifndef NIDEVICE_GRPC_EXCEPTIONS
#define NIDEVICE_GRPC_EXCEPTIONS

#include <stdexcept>

namespace nidevice_grpc {

struct ValueOutOfRangeException : std::runtime_error {
  ValueOutOfRangeException(const char* message) : std::runtime_error(message) {}
  ValueOutOfRangeException(const std::string& message) : std::runtime_error(message) {}
  ValueOutOfRangeException(const ValueOutOfRangeException& other) : std::runtime_error(other) {}
};

}  // namespace nidevice_grpc

#endif