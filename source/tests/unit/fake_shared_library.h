#ifndef NI_HARDWARE_GRPC_INTERNAL_SHARED_LIBRARY_FAKE
#define NI_HARDWARE_GRPC_INTERNAL_SHARED_LIBRARY_FAKE

#include <map>

#include "core_server/hardware/grpc/internal/shared_library.h"

namespace ni {
namespace tests {
namespace unit {
namespace hardware {
namespace grpc {
namespace internal {

class FakeSharedLibrary : public ni::hardware::grpc::internal::SharedLibrary {
 public:
  FakeSharedLibrary(const char* library_name);
  virtual ~FakeSharedLibrary();

  virtual void create_function_map() = 0;
  virtual bool is_loaded() const final;
  virtual void load() final;
  virtual void unload() final;
  virtual const void* get_function_pointer(const char* name) const final;

 protected:
  void register_function(const char* name, void* func_pointer);

 private:
  std::map<std::string, void*> mock_function_pointers_;
  bool is_loaded_;
  const void* get_function_from_map(const char* name) const;
};

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace unit
}  // namespace tests
}  // namespace ni

#endif  // NI_HARDWARE_GRPC_INTERNAL_SHARED_LIBRARY_FAKE
