#ifndef NIDEVICE_GRPC_SHARED_LIBRARY_INTERFACE
#define NIDEVICE_GRPC_SHARED_LIBRARY_INTERFACE

#include <stdexcept>
#include <string>

#include "exceptions.h"

namespace nidevice_grpc {

#ifdef _MSC_VER
typedef HMODULE LibraryHandle;
#else
typedef void* LibraryHandle;
#endif

class SharedLibraryInterface {
 public:
  virtual ~SharedLibraryInterface() = default;

  // not included because we have to templatize the class in order to make this virtual
  // and then can't specify a pointer to SharedLibraryInterface for our Library classes (because we would need a template specifier)
  // virtual void swap(SharedLibraryT& other) = 0;
  virtual bool is_loaded() const = 0;
  virtual LibraryHandle get_handle() const = 0;
  virtual void load() = 0;
  virtual void unload() = 0;
  virtual const void* get_function_pointer(const char* name) const = 0;
  virtual bool function_exists(const char* name) const = 0;
  virtual void set_library_name(const char* library_name) = 0;
  virtual std::string get_library_name() const = 0;

};

}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_SHARED_LIBRARY_INTERFACE
