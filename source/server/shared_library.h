#ifndef NIDEVICE_GRPC_SHARED_LIBRARY
#define NIDEVICE_GRPC_SHARED_LIBRARY

#include <stdexcept>
#include <string>

#include "exceptions.h"

#if defined(_MSC_VER)
  #include <Windows.h>
#endif

namespace nidevice_grpc {

#ifdef _MSC_VER
typedef HMODULE LibraryHandle;
#else
typedef void* LibraryHandle;
#endif

class LibraryLoadException : NonDriverException {
 public:
  LibraryLoadException(const std::string& message) : NonDriverException(::grpc::StatusCode::NOT_FOUND, message) {}
  LibraryLoadException(const char* message) : NonDriverException(::grpc::StatusCode::NOT_FOUND, message) {}
  LibraryLoadException(const LibraryLoadException& other) : NonDriverException(other) {}
};

class SessionException : NonDriverException {
 public:
  SessionException(const std::string& message) : NonDriverException(::grpc::StatusCode::INVALID_ARGUMENT, message) {}
  SessionException(const char* message) : NonDriverException(::grpc::StatusCode::INVALID_ARGUMENT, message) {}
  SessionException(const SessionException& other) : NonDriverException(other) {}
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
