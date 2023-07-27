#ifndef NIDEVICE_GRPC_SHARED_LIBRARY
#define NIDEVICE_GRPC_SHARED_LIBRARY

#include "shared_library_interface.h"
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

class LibraryLoadException : public NonDriverException {
 public:
  LibraryLoadException(const std::string& message) : NonDriverException(::grpc::StatusCode::NOT_FOUND, message) {}
  LibraryLoadException(const char* message) : NonDriverException(::grpc::StatusCode::NOT_FOUND, message) {}
  LibraryLoadException(const LibraryLoadException& other) : NonDriverException(other) {}
};

class SessionException : public NonDriverException {
 public:
  SessionException(const std::string& message) : NonDriverException(::grpc::StatusCode::INVALID_ARGUMENT, message) {}
  SessionException(const char* message) : NonDriverException(::grpc::StatusCode::INVALID_ARGUMENT, message) {}
  SessionException(const SessionException& other) : NonDriverException(other) {}
};

class SharedLibrary : public SharedLibraryInterface {
 public:
  SharedLibrary();
  SharedLibrary(const char* library_name);
  SharedLibrary(const SharedLibrary& other);
  virtual ~SharedLibrary() override;

  void swap(SharedLibrary& other);
  bool is_loaded() const override;
  LibraryHandle get_handle() const override;
  void load() override;
  void unload() override;
  const void* get_function_pointer(const char* name) const override;
  bool function_exists(const char* name) const override;
  void set_library_name(const char* library_name) override;
  std::string get_library_name() const override;

 private:
  std::string library_name_;
  LibraryHandle handle_;
};

}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_SHARED_LIBRARY
