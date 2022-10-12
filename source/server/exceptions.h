#ifndef NIDEVICE_GRPC_EXCEPTIONS
#define NIDEVICE_GRPC_EXCEPTIONS

#include <grpcpp/grpcpp.h>

#include <stdexcept>

namespace nidevice_grpc {

class NonDriverException : public std::runtime_error {
 public:
  NonDriverException(::grpc::StatusCode code, const std::string& message) : std::runtime_error(message), code_(code) {}
  NonDriverException(::grpc::StatusCode code, const char* message) : std::runtime_error(message), code_(code) {}
  NonDriverException(const NonDriverException& other) : std::runtime_error(other), code_(other.code_) {}

  ::grpc::Status GetStatus() const { return ::grpc::Status(code_, what()); }

 private:
  ::grpc::StatusCode code_;
};

class ValueOutOfRangeException : public NonDriverException {
 public:
  ValueOutOfRangeException(const char* message) : NonDriverException(::grpc::StatusCode::OUT_OF_RANGE, message) {}
  ValueOutOfRangeException(const std::string& message) : NonDriverException(::grpc::StatusCode::OUT_OF_RANGE, message) {}
  ValueOutOfRangeException(const ValueOutOfRangeException& other) : NonDriverException(other) {}
};

}  // namespace nidevice_grpc

#endif
