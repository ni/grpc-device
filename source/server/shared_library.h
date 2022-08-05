#ifndef NIDEVICE_GRPC_SHARED_LIBRARY
#define NIDEVICE_GRPC_SHARED_LIBRARY

#include <stdexcept>
#include <string>

#if defined(_MSC_VER)
  #include <Windows.h>
#endif

namespace nidevice_grpc {

#ifdef _MSC_VER
typedef HMODULE LibraryHandle;
#else
typedef void* LibraryHandle;
#endif

struct LibraryLoadException : std::runtime_error {
  LibraryLoadException(const std::string& message) : std::runtime_error(message) {}
  LibraryLoadException(const char* message) : std::runtime_error(message) {}
  LibraryLoadException(const LibraryLoadException& other) : std::runtime_error(other) {}
};

struct SessionException : std::runtime_error {
  SessionException(const std::string& message) : std::runtime_error(message) {}
  SessionException(const char* message) : std::runtime_error(message) {}
  SessionException(const SessionException& other) : std::runtime_error(other) {}
};

class SharedLibrary {
 public:
  SharedLibrary();
  SharedLibrary(const char* library_name);
  SharedLibrary(const SharedLibrary& other);
  virtual ~SharedLibrary();

  void swap(SharedLibrary& other);
  bool is_loaded() const;
  LibraryHandle get_handle() const;
  void load();
  void unload();
  const void* get_function_pointer(const char* name) const;
  bool function_exists(const char* name) const;
  void set_library_name(const char* library_name);
  std::string get_library_name() const;

 private:
  std::string library_name_;
  LibraryHandle handle_;
};

}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_SHARED_LIBRARY
