#include "fake_shared_library.h"

namespace ni {
namespace tests {
namespace unit {
namespace hardware {
namespace grpc {
namespace internal {

FakeSharedLibrary::FakeSharedLibrary(const char* library_name)
    : SharedLibrary(library_name)
{
}

FakeSharedLibrary::~FakeSharedLibrary()
{
  unload();
}

bool FakeSharedLibrary::is_loaded() const
{
  return is_loaded_;
}

void FakeSharedLibrary::load()
{
  if (!mock_function_pointers_.empty()) {
    return;
  }
  create_function_map();
  handle_ = nullptr;
  is_loaded_ = true;
}

void FakeSharedLibrary::unload()
{
  mock_function_pointers_.clear();
  handle_ = nullptr;
  is_loaded_ = false;
}

const void* FakeSharedLibrary::get_function_pointer(const char* name) const
{
  return get_function_from_map(name);
}

void FakeSharedLibrary::register_function(const char* name, void* func_pointer)
{
  mock_function_pointers_[name] = func_pointer;
}

const void* FakeSharedLibrary::get_function_from_map(const char* name) const
{
  return mock_function_pointers_.at(name);
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace unit
}  // namespace tests
}  // namespace ni
