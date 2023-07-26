//---------------------------------------------------------------------
// Mock of SharedLibrary
//---------------------------------------------------------------------
#ifndef NIDEVICE_GRPC_MOCK_SHARED_LIBRARY_H
#define NIDEVICE_GRPC_MOCK_SHARED_LIBRARY_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

#include "shared_library.h"

namespace ni {
namespace tests {
namespace unit {

class MockSharedLibrary : public nidevice_grpc::SharedLibrary {
 public:
  MOCK_METHOD(void, swap, (nidevice_grpc::SharedLibrary& other), ());
  MOCK_METHOD(bool, is_loaded, (), (const));
  MOCK_METHOD(nidevice_grpc::LibraryHandle, get_handle, (), (const));
  MOCK_METHOD(void, load, (), ());
  MOCK_METHOD(void, unload, (), ());
  MOCK_METHOD(const void*, get_function_pointer, (const char* name), (const));
  MOCK_METHOD(bool, function_exists, (const char* name), (const));
  MOCK_METHOD(void, set_library_name, (const char* library_name), ());
  MOCK_METHOD(std::string, get_library_name, (), (const));
};

}  // namespace unit
}  // namespace tests
}  // namespace ni
#endif  // NIDEVICE_GRPC_MOCK_SHARED_LIBRARY_H
