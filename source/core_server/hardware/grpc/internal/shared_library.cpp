#include "shared_library.h"

#if !defined(WIN32)

#include <dlfcn.h>
#include "PosixError.h"

#endif

namespace ni
{
namespace hardware
{
namespace grpc
{
namespace internal
{

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
      if (!library_name_.empty()) {
#if defined(WIN32)
         handle_ = ::LoadLibraryA(library_name_.c_str());
#else
         handle_ = ::dlopen(library_name_.c_str(), RTLD_NOW | RTLD_GLOBAL);
#endif
      }
   }

   void SharedLibrary::unload()
   {
      if (handle_) {
#if defined (WIN32)
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
#if defined (WIN32)
      return ::GetProcAddress(handle_, name);
#else
      return ::dlsym(handle_, name);
#endif
   }

} // namespace impl
} // namespace grpc
} // namespace hardware
} // namespace ni