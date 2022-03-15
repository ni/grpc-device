#ifndef NIDEVICE_GRPC_DEVICE_NIRFMX_ERRORS_H
#define NIDEVICE_GRPC_DEVICE_NIRFMX_ERRORS_H
#include <nirfmxinstr/nirfmxinstr_library_interface.h>  // For niRFmxInstrHandle, int32

#include <vector>

template <typename TLibraryPtr>
std::string get_last_error_message(TLibraryPtr& library)
{
  std::vector<char> error_message;
  int32 error_code;
  // Calling with no instr handle gives us thread-local errors instead of handle
  // scoped errors. This method should only be used in cases where that is correct.
  constexpr auto NO_INSTR_HANDLE = static_cast<niRFmxInstrHandle>(nullptr);
  const auto buffer_size = library->GetError(NO_INSTR_HANDLE, &error_code, 0, nullptr);
  error_message.resize(buffer_size);
  library->GetError(NO_INSTR_HANDLE, &error_code, buffer_size, error_message.data());

  return std::string(error_message.data());
}

#endif  // NIDEVICE_GRPC_DEVICE_NIRFMX_ERRORS_H
