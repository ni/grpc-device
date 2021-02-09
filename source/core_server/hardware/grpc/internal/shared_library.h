#ifndef NI_HARDWARE_GRPC_INTERNAL_SHARED_LIBRARY
#define NI_HARDWARE_GRPC_INTERNAL_SHARED_LIBRARY

#include <string>

#if defined(_MSC_VER)
  #include <Windows.h>
#endif

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

#ifdef _MSC_VER
typedef HMODULE LibraryHandle;
#else
typedef void* LibraryHandle;
#endif

class SharedLibrary {
 public:
  SharedLibrary(const char* library_name);
  SharedLibrary(const SharedLibrary& other);
  virtual ~SharedLibrary();

  virtual void swap(SharedLibrary& other);
  virtual bool is_loaded() const;
  virtual LibraryHandle get_handle() const;
  virtual void load();
  virtual void unload();
  virtual const void* get_function_pointer(const char* name) const;
  virtual void set_library_name(const char* library_name);
  virtual std::string get_library_name() const;

 protected:
  std::string library_name_;
  LibraryHandle handle_;
};

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni

#endif  // NI_HARDWARE_GRPC_INTERNAL_SHARED_LIBRARY
