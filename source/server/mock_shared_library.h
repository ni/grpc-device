//---------------------------------------------------------------------
// Mock of SharedLibrary
//---------------------------------------------------------------------
#ifndef NIDEVICE_GRPC_MOCK_SHARED_LIBRARY_H
#define NIDEVICE_GRPC_MOCK_SHARED_LIBRARY_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

#include "shared_library_interface.h"

namespace ni {
namespace tests {
namespace unit {

class MockSharedLibrary : public nidevice_grpc::SharedLibraryInterface {
 public:
  // MOCK_METHOD(void, swap, (nidevice_grpc::SharedLibraryInterface& other), ());
  MOCK_METHOD(bool, is_loaded, (), (const, override));
  MOCK_METHOD(nidevice_grpc::LibraryHandle, get_handle, (), (const, override));
  MOCK_METHOD(void, load, (), (override));
  MOCK_METHOD(void, unload, (), (override));
  MOCK_METHOD(const void*, get_function_pointer, (const char* name), (const, override));
  MOCK_METHOD(bool, function_exists, (const char* name), (const, override));
  MOCK_METHOD(void, set_library_name, (const char* library_name), (override));
  MOCK_METHOD(std::string, get_library_name, (), (const, override));
};

}  // namespace unit
}  // namespace tests
}  // namespace ni
#endif  // NIDEVICE_GRPC_MOCK_SHARED_LIBRARY_H
