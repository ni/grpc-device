#include "shared_library.h"

#if defined(__GNUC__)
  #include <dlfcn.h>
#endif

namespace nidevice_grpc {

SharedLibrary::SharedLibrary()
    : handle_(nullptr)
{
}

SharedLibrary::SharedLibrary(const char* library_name)
    : library_name_(library_name), handle_(nullptr)
{
}

SharedLibrary::SharedLibrary(const SharedLibrary& other)
    : library_name_(other.library_name_), handle_(nullptr)
{
  if (other.handle_) {
    load();
  }
}

SharedLibrary::~SharedLibrary()
{
  unload();
}

void SharedLibrary::swap(SharedLibrary& other)
{
  library_name_.swap(other.library_name_);
  std::swap(handle_, other.handle_);
}

bool SharedLibrary::is_loaded() const
{
  return handle_ != nullptr;
}

LibraryHandle SharedLibrary::get_handle() const
{
  return handle_;
}

void SharedLibrary::load()
{
  if (handle_) {
    return;
  }
  if (!library_name_.empty()) {
#if defined(_MSC_VER)
    handle_ = ::LoadLibraryA(library_name_.c_str());
#else
    handle_ = ::dlopen(library_name_.c_str(), RTLD_NOW | RTLD_GLOBAL);
#endif
  }
}

void SharedLibrary::unload()
{
  if (handle_) {
#if defined(_MSC_VER)
    ::FreeLibrary(handle_);
#else
    ::dlclose(handle_);
#endif
    handle_ = nullptr;
  }
}

const void* SharedLibrary::get_function_pointer(const char* name) const
{
  if (!handle_) {
    return nullptr;
  }
#if defined(_MSC_VER)
  return ::GetProcAddress(handle_, name);
#else
  return ::dlsym(handle_, name);
#endif
}

bool SharedLibrary::function_exists(const char* name) const
{
  return get_function_pointer(name) != nullptr;
}

void SharedLibrary::set_library_name(const char* library_name)
{
  if (!is_loaded())
    library_name_ = library_name;
}

std::string SharedLibrary::get_library_name() const
{
  return library_name_;
}

}  // namespace nidevice_grpc
