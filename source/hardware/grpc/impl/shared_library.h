#pragma once
#include <string>

#if defined(WIN32)
#include <Windows.h>
#endif

#ifndef NI_HARDWARE_GRPC_IMPL_SHARED_LIBRARY
#define NI_HARDWARE_GRPC_IMPL_SHARED_LIBRARY

namespace ni
{
namespace hardware
{
namespace grpc
{
namespace impl
{

#ifdef WIN32
   typedef HMODULE LibraryHandle;
#else
   typedef void* LibraryHandle;
#endif

   class SharedLibrary
   {
   public:
      SharedLibrary(const char* library_name);
      SharedLibrary(const SharedLibrary& other);
      virtual ~SharedLibrary();

      void swap(SharedLibrary& other);
      bool is_loaded() const;
      LibraryHandle get_handle() const;
      void load();
      void unload();
      const void* get_function_pointer(const char* name) const;

   private:
      std::string library_name_;
      LibraryHandle handle_;
   };

} // namespace impl
} // namespace grpc
} // namespace hardware
} // namespace ni

#endif // NI_HARDWARE_GRPC_IMPL_SHARED_LIBRARY
