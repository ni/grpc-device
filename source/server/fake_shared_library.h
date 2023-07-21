#ifndef NIDEVICE_GRPC_FAKE_SHARED_LIBRARY
#define NIDEVICE_GRPC_FAKE_SHARED_LIBRARY

#include "shared_library.h"

#include <memory>

namespace ni {
namespace tests {
namespace unit {

void FunctionToPointAt() {}

class FakeSharedLibraryAllFunctionsPresent : nidevice_grpc::SharedLibrary {
 public:
  bool is_loaded() const override { return true; }
  void load() override {}
  void unload() override {}
  const void* get_function_pointer(const char* name) const override { return &FunctionToPointAt; }
  bool function_exists(const char* name) const override { return true; }
  void set_library_name(const char* library_name) override {}
  std::string get_library_name() const override { return ""; }
};

class FakeSharedLibraryNoFunctionsPresent : nidevice_grpc::SharedLibrary {
 public:
  bool is_loaded() const override { return true; }
  void load() override {}
  void unload() override {}
  const void* get_function_pointer(const char* name) const override { return nullptr; }
  bool function_exists(const char* name) const override { return false; }
  void set_library_name(const char* library_name) override {}
  std::string get_library_name() const override { return ""; }
};

}  // namespace unit
}  // namespace tests
}  // namespace ni

#endif  // NIDEVICE_GRPC_FAKE_SHARED_LIBRARY
